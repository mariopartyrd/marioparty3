#include "common.h"
#include "gcc/string.h"

typedef struct HvqFileHeader {
    char signature[20];
    u16 width;
    u16 height;
    u8 horizontalSampling;
    u8 verticalSampling;
    u8 shifts;
    u8 componentOrder;
    u32 treeOffsets[4];
} HvqFileHeader;

typedef struct HvqBitStream {
    u32 mask;
    u32 word;
    u32 *nextWord;
} HvqBitStream;

typedef struct HvqHuffmanTree {
    s16 root;
    /* Nodes below 256 are leaves; left holds their decoded values. */
    s16 left[512];
    s16 right[512];
} HvqHuffmanTree;

typedef struct HvqBlockState {
    u8 *aboveMode;
    u8 *aboveMean;
    u8 *currentMode;
    u8 *currentMean;
    u8 *belowMode;
    u8 *belowMean;
    u8 rightMode;
    u8 rightMean;
    u8 mode;
    u8 mean;
    u8 leftMean;
} HvqBlockState;

static const char sHvqSignature[] = "HVQ-MPS 1.1";
/* Preserve the original string storage, including its trailing zero padding. */
static const char sHvqInvalidSignatureError[52] = "Error : This file is not HVQ-MPS 1.1";

/* BSS declarations follow the original allocation order. */
static u8 sHvqColorClampTable[768];
static u8 sHvqColorAlphaClampTable[768];
static s32 sHvqHasSecondLumaRow;
static void (*sHvqConvertToRgba)(u16 *, s16 *, s16 *, s16 *);
static s32 sHvqNextTreeNode;
static HvqHuffmanTree sHvqMeanTree;
static HvqHuffmanTree sHvqModeTree;
static HvqHuffmanTree sHvqAmplitudeTree;
static HvqHuffmanTree sHvqPatternTableTree;
static s16 sHvqMeanDeltaMax;
static s16 sHvqMeanDeltaMin;
static HvqBitStream sHvqTreeStream;
static HvqBitStream sHvqModeStreams[2];
static HvqBitStream sHvqAmplitudeStreams[3];
static HvqBitStream sHvqMeanStreams[3];
static u8 *sHvqRawStreams[3];
static u8 sHvqPatternTableBuffer[2660];
static u8 *sHvqPatternTable;
static s32 sHvqPatternTableWidth;
static s32 sHvqPatternTableHeight;
static s32 sHvqPatternTableDoubleStride;
static s32 sHvqPatternTableTransposed;
static HvqBlockState sHvqLumaBlockState;
static HvqBlockState sHvqSecondLumaRowBlockState;
static HvqBlockState sHvqCbBlockState;
static HvqBlockState sHvqCrBlockState;
static s32 sHvqReciprocalTable[512];
static u8 *sHvqBlockModes[3];
static u8 *sHvqBlockMeans[3];
static u16 sHvqImageWidth;
static u16 sHvqImageHeight;
static s32 sHvqOutputStride;
static u16 sHvqLumaBlockColumns;
static u16 sHvqLumaBlockRows;
static u16 sHvqLumaBlockCount;
static u16 sHvqChromaBlockColumns;
static u16 sHvqChromaBlockRows;
static u16 sHvqChromaBlockCount;
static u8 sHvqHorizontalSampling;
static u8 sHvqVerticalSampling;
static s32 sHvqOutputGroupColumnStep;
static s32 sHvqOutputGroupRowStep;
static s16 sHvqLumaSamples[64];
static s16 sHvqCbSamples[16];
static s16 sHvqCrSamples[16];
static s32 sHvqSampleFractionBits;
static s32 sHvqSampleRoundingBias;

void func_800677B8_683B8(u16 *, s16 *, s16 *, s16 *);
void func_80067D50_68950(u16 *, s16 *, s16 *, s16 *);

static inline u32 HvqReadBit(HvqBitStream *stream) {
    u32 bit;

    /* Consume each input word from most significant bit to least significant bit. */
    if (stream->mask == 0) {
        stream->word = *stream->nextWord++;
        stream->mask = 0x80000000;
    }
    bit = stream->word & stream->mask;
    stream->mask >>= 1;
    return bit;
}

static inline s16 HvqReadSymbol(HvqBitStream *stream, HvqHuffmanTree *tree) {
    s16 node = tree->root;

    while (node >= 256) {
        if (HvqReadBit(stream)) {
            node = tree->right[node];
        } else {
            node = tree->left[node];
        }
    }
    return tree->left[node];
}

s16 func_800665E0_671E0(HvqBitStream *stream, HvqHuffmanTree *tree) {
    s32 node;
    u32 bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0;

    /* A set bit introduces a branch, followed by its left and right subtrees. */
    if (HvqReadBit(stream)) {
        node = sHvqNextTreeNode++;
        tree->left[node] = func_800665E0_671E0(stream, tree);
        tree->right[node] = func_800665E0_671E0(stream, tree);
        return node;
    }

    /* A leaf contains an eight-bit symbol, most significant bit first. */
    bit7 = HvqReadBit(stream) != 0;
    bit6 = HvqReadBit(stream) != 0;
    bit5 = HvqReadBit(stream) != 0;
    bit4 = HvqReadBit(stream) != 0;
    bit3 = HvqReadBit(stream) != 0;
    bit2 = HvqReadBit(stream) != 0;
    bit1 = HvqReadBit(stream) != 0;
    bit0 = HvqReadBit(stream) != 0;
    return (bit7 << 7) | (bit6 << 6) | (bit5 << 5) | (bit4 << 4) | (bit3 << 3) | (bit2 << 2) | (bit1 << 1) | bit0;
}

s32 func_80066894_67494(HvqBitStream *stream) {
    s16 value;
    s16 symbol;

    symbol = HvqReadSymbol(stream, &sHvqMeanTree);
    value = symbol;
    /* Endpoint symbols extend the value with one or more additional symbols. */
    if (symbol == sHvqMeanDeltaMin || symbol == sHvqMeanDeltaMax) {
        do {
            symbol = HvqReadSymbol(stream, &sHvqMeanTree);
            value += symbol;
        } while (symbol <= sHvqMeanDeltaMin || symbol >= sHvqMeanDeltaMax);
    }
    return value;
}

static inline s32 HvqReadMean(s32 component) {
    return func_80066894_67494(&sHvqMeanStreams[component]);
}

static inline s32 HvqPatternScale(s32 *amplitude, u16 code, s16 maximum, s32 component) {
    s32 value;

    /* Huffman deltas supply the coarse amplitude; the code adds two low
     * bits and a sign. Normalize by the pattern's largest deviation. */
    *amplitude += HvqReadSymbol(&sHvqAmplitudeStreams[component], &sHvqAmplitudeTree);
    value = *amplitude + ((code >> 13) & 3);
    return ((code & 0x8000) ? -sHvqReciprocalTable[maximum] : sHvqReciprocalTable[maximum]) * value;
}

static inline s32 HvqAbsSample(s16 value) {
    return value < 0 ? -value : value;
}

static inline s32 HvqDecodePattern(s16 *sample, u16 code, s32 *amplitude, s32 component) {
    u8 *row, *entry;
    s32 xStep, yStep;
    s32 sum;
    s16 maximum, magnitude;

    if (sHvqPatternTableTransposed == 0) {
        row = sHvqPatternTable + ((code & 0x3F) + ((code >> 6) & 0x1F) * sHvqPatternTableWidth);
        xStep = ((code >> 11) & 1) + 1;
        yStep = ((code >> 12) & 1) == 0 ? sHvqPatternTableWidth : sHvqPatternTableDoubleStride;
    } else {
        row = sHvqPatternTable + (((code >> 6) & 0x1F) + (code & 0x3F) * sHvqPatternTableWidth);
        xStep = ((code >> 12) & 1) + 1;
        yStep = ((code >> 11) & 1) == 0 ? sHvqPatternTableWidth : sHvqPatternTableDoubleStride;
    }
    /* Sample a 4x4 pattern and remove its mean before scaling. */
    sum = 0;
    entry = row;
    sum += sample[0] = *entry;
    entry += xStep;
    sum += sample[1] = *entry;
    entry += xStep;
    sum += sample[2] = *entry;
    entry += xStep;
    sum += sample[3] = *entry;
    row += yStep;
    entry = row;
    sum += sample[4] = *entry;
    entry += xStep;
    sum += sample[5] = *entry;
    entry += xStep;
    sum += sample[6] = *entry;
    entry += xStep;
    sum += sample[7] = *entry;
    row += yStep;
    entry = row;
    sum += sample[8] = *entry;
    entry += xStep;
    sum += sample[9] = *entry;
    entry += xStep;
    sum += sample[10] = *entry;
    entry += xStep;
    sum += sample[11] = *entry;
    row += yStep;
    entry = row;
    sum += sample[12] = *entry;
    entry += xStep;
    sum += sample[13] = *entry;
    entry += xStep;
    sum += sample[14] = *entry;
    entry += xStep;
    sum += sample[15] = *entry;
    sum >>= 4;
    *sample -= sum;
    maximum = HvqAbsSample(*sample++);
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    *sample -= sum;
    magnitude = HvqAbsSample(*sample++);
    if (magnitude > maximum) {
        maximum = magnitude;
    }
    return HvqPatternScale(amplitude, code, maximum, component);
}

static inline void HvqExpandBlock(s16 *output, s32 mode, u8 mean, s32 component) {
    s16 pattern[16];
    s32 pixels[16];
    s32 amplitude;
    s32 count;
    u16 code;
    s32 scale;

    /* Mode 8 stores raw pixels; modes 1 through 7 add that many patterns.
     * The fixed 16-sample operations are unrolled in the original code. */
    if (mode == 8) {
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
        *output++ = *sHvqRawStreams[component]++;
    } else {
        amplitude = 0;
        pixels[0] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[1] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[2] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[3] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[4] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[5] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[6] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[7] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[8] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[9] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[10] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[11] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[12] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[13] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[14] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        pixels[15] = (mean << sHvqSampleFractionBits) + sHvqSampleRoundingBias;
        for (count = mode; count > 0; count--) {
            code = *sHvqRawStreams[component]++ << 8;
            code |= *sHvqRawStreams[component]++;
            scale = HvqDecodePattern(pattern, code, &amplitude, component);
            pixels[0] += scale * pattern[0];
            pixels[1] += scale * pattern[1];
            pixels[2] += scale * pattern[2];
            pixels[3] += scale * pattern[3];
            pixels[4] += scale * pattern[4];
            pixels[5] += scale * pattern[5];
            pixels[6] += scale * pattern[6];
            pixels[7] += scale * pattern[7];
            pixels[8] += scale * pattern[8];
            pixels[9] += scale * pattern[9];
            pixels[10] += scale * pattern[10];
            pixels[11] += scale * pattern[11];
            pixels[12] += scale * pattern[12];
            pixels[13] += scale * pattern[13];
            pixels[14] += scale * pattern[14];
            pixels[15] += scale * pattern[15];
        }
        output[0] = pixels[0] >> sHvqSampleFractionBits;
        output[1] = pixels[1] >> sHvqSampleFractionBits;
        output[2] = pixels[2] >> sHvqSampleFractionBits;
        output[3] = pixels[3] >> sHvqSampleFractionBits;
        output[4] = pixels[4] >> sHvqSampleFractionBits;
        output[5] = pixels[5] >> sHvqSampleFractionBits;
        output[6] = pixels[6] >> sHvqSampleFractionBits;
        output[7] = pixels[7] >> sHvqSampleFractionBits;
        output[8] = pixels[8] >> sHvqSampleFractionBits;
        output[9] = pixels[9] >> sHvqSampleFractionBits;
        output[10] = pixels[10] >> sHvqSampleFractionBits;
        output[11] = pixels[11] >> sHvqSampleFractionBits;
        output[12] = pixels[12] >> sHvqSampleFractionBits;
        output[13] = pixels[13] >> sHvqSampleFractionBits;
        output[14] = pixels[14] >> sHvqSampleFractionBits;
        output[15] = pixels[15] >> sHvqSampleFractionBits;
    }
}

void func_80066A44_67644(s16 *output, HvqBlockState *state, s32 component) {
    s32 mode = state->mode;
    u8 mean = state->mean;

    /* Interpolate the block mean with the four neighboring block means.
     * Non-interpolated neighbors use the current mean at that boundary. */
    if (mode == 0) {
        s16 *pixel = output;
        u8 right, above, below, left;
        s32 base, twiceMean;
        s32 belowValue, rightValue;
        s32 aboveBelow, leftRight, diagonalSum, diagonalDifference;
        s32 aboveRight, belowRight, aboveLeft, belowLeft;
        s32 aboveRightSum, belowRightSum, aboveLeftSum, belowLeftSum;
        s16 p0, p1, p2, p3;
        s16 p4, p5, p6, p7;
        s16 p8, p9, p10, p11;
        s16 p12, p13, p14;

        right = mean;
        if (state->rightMode == 0) {
            right = state->rightMean;
        }
        above = *state->aboveMode == 0 ? *state->aboveMean : mean;
        below = *state->belowMode == 0 ? *state->belowMean : mean;
        left = state->leftMean;
        belowValue = below;
        rightValue = right;
        twiceMean = mean << 1;
        base = (mean << 3) + 4;
        belowRightSum = belowValue + rightValue - twiceMean;
        aboveBelow = above - below;
        leftRight = left - right;
        diagonalSum = aboveBelow + leftRight;
        diagonalDifference = aboveBelow - leftRight;
        aboveRight = above - right;
        belowRight = below - right;
        aboveLeft = above - left;
        belowLeft = below - left;
        aboveRightSum = above + right - twiceMean;
        aboveLeftSum = above + left - twiceMean;
        belowLeftSum = left + below - twiceMean;

        p0 = (base + diagonalSum + aboveLeftSum) >> 3;
        p1 = (base + diagonalSum + aboveLeft) >> 3;
        p2 = (base + diagonalDifference + aboveRight) >> 3;
        p3 = (base + diagonalDifference + aboveRightSum) >> 3;
        p4 = (base + diagonalSum - aboveLeft) >> 3;
        p5 = (base - belowRightSum) >> 3;
        p6 = (base - belowLeftSum) >> 3;
        p7 = (base + diagonalDifference - aboveRight) >> 3;
        p8 = (base - diagonalDifference - belowLeft) >> 3;
        p9 = (base - aboveRightSum) >> 3;
        p10 = (base - aboveLeftSum) >> 3;
        p11 = (base - diagonalSum - belowRight) >> 3;
        p12 = (base - diagonalDifference + belowLeftSum) >> 3;
        p13 = (base - diagonalDifference + belowLeft) >> 3;
        p14 = (base - diagonalSum + belowRight) >> 3;
        pixel[0] = p0;
        pixel[1] = p1;
        pixel[2] = p2;
        pixel[3] = p3;
        pixel[4] = p4;
        pixel[5] = p5;
        pixel[6] = p6;
        pixel[7] = p7;
        pixel[8] = p8;
        pixel[9] = p9;
        pixel[10] = p10;
        pixel[11] = p11;
        pixel[12] = p12;
        pixel[13] = p13;
        pixel[14] = p14;
        pixel[15] = (base - diagonalSum + belowRightSum) >> 3;
        state->leftMean = mean;
    } else {
        HvqExpandBlock(output, mode, mean, component);
        state->leftMean = state->rightMean;
    }
    state->aboveMode++;
    state->aboveMean++;
    state->belowMode++;
    state->belowMean++;
}

static inline u16 HvqPackPixel(s16 y, s16 red, s16 green, s16 blue) {
    return (sHvqColorClampTable[(y + red) >> 6] << 10) | (sHvqColorClampTable[(y + green) >> 6] << 5) | sHvqColorAlphaClampTable[(y + blue) >> 6];
}

void func_800677B8_683B8(u16 *output, s16 *luma, s16 *cb, s16 *cr) {
    s16 *left = luma;
    s16 *right = left + 16;
    u16 *pixel;
    s32 row;
    s16 y, u, v;
    s16 red, green, blue;

    /* Each chroma sample colors two adjacent pixels in the two 4x4 luma blocks.
     * Six fractional bits retain precision; 0x4020 adds the clamp-table bias
     * of 256 and rounds to the nearest integer before packing RGBA5551. */
    for (row = 4; row > 0; row--) {
        pixel = output;
        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red = 90 * v + 0x4020;
        u -= 128;
        green = (-22 * u) + (-46 * v) + 0x4020;
        blue = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red, green, blue);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red, green, blue);

        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red = 90 * v + 0x4020;
        u -= 128;
        green = (-22 * u) + (-46 * v) + 0x4020;
        blue = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red, green, blue);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red, green, blue);

        v = *cr++;
        y = *right++ << 6;
        u = *cb++;
        v -= 128;
        red = 90 * v + 0x4020;
        u -= 128;
        green = (-22 * u) + (-46 * v) + 0x4020;
        blue = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red, green, blue);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red, green, blue);

        v = *cr++;
        y = *right++ << 6;
        u = *cb++;
        v -= 128;
        red = 90 * v + 0x4020;
        u -= 128;
        green = (-22 * u) + (-46 * v) + 0x4020;
        blue = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red, green, blue);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red, green, blue);

        output += sHvqOutputStride;
    }
}

void func_80067D50_68950(u16 *output, s16 *luma, s16 *cb, s16 *cr) {
    s16 *left = luma;
    s16 *right = (luma += 16);
    u16 *pixel;
    s32 row;
    s16 y, u, v;
    s16 red0, green0, blue0;
    s16 red1, green1, blue1;
    s16 red2, green2, blue2;
    s16 red3, green3, blue3;

    /* Four 4x4 luma blocks form an 8x8 tile. Each chroma sample is
     * shared by two columns and two rows; retain its color offsets
     * while writing the second row. */
    for (row = 4; row > 0; row -= 2) {
        pixel = output;
        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red0 = 90 * v + 0x4020;
        u -= 128;
        green0 = (-22 * u) + (-46 * v) + 0x4020;
        blue0 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);

        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red1 = 90 * v + 0x4020;
        u -= 128;
        green1 = (-22 * u) + (-46 * v) + 0x4020;
        blue1 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);

        v = *cr++;
        y = *right++ << 6;
        u = *cb++;
        v -= 128;
        red2 = 90 * v + 0x4020;
        u -= 128;
        green2 = (-22 * u) + (-46 * v) + 0x4020;
        blue2 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);

        v = *cr;
        y = *right++ << 6;
        u = *cb;
        v -= 128;
        red3 = 90 * v + 0x4020;
        u -= 128;
        green3 = (-22 * u) + (-46 * v) + 0x4020;
        blue3 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);

        output += sHvqOutputStride;
        pixel = output;
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        output += sHvqOutputStride;
        cr++;
        cb++;
    }

    left = (luma += 16);
    right = left + 16;
    for (row = 4; row > 0; row -= 2) {
        pixel = output;
        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red0 = 90 * v + 0x4020;
        u -= 128;
        green0 = (-22 * u) + (-46 * v) + 0x4020;
        blue0 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);

        v = *cr++;
        y = *left++ << 6;
        u = *cb++;
        v -= 128;
        red1 = 90 * v + 0x4020;
        u -= 128;
        green1 = (-22 * u) + (-46 * v) + 0x4020;
        blue1 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);

        v = *cr++;
        y = *right++ << 6;
        u = *cb++;
        v -= 128;
        red2 = 90 * v + 0x4020;
        u -= 128;
        green2 = (-22 * u) + (-46 * v) + 0x4020;
        blue2 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);

        v = *cr;
        y = *right++ << 6;
        u = *cb;
        v -= 128;
        red3 = 90 * v + 0x4020;
        u -= 128;
        green3 = (-22 * u) + (-46 * v) + 0x4020;
        blue3 = 113 * u + 0x4020;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);

        output += sHvqOutputStride;
        pixel = output;
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red0, green0, blue0);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *left++ << 6;
        *pixel++ = HvqPackPixel(y, red1, green1, blue1);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red2, green2, blue2);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        y = *right++ << 6;
        *pixel++ = HvqPackPixel(y, red3, green3, blue3);
        output += sHvqOutputStride;
        cr++;
        cb++;
    }
}

void func_80068ECC_69ACC(u16 *output) {
    s32 count;

    sHvqCbBlockState.rightMode = *sHvqCbBlockState.currentMode;
    sHvqCbBlockState.rightMean = sHvqCbBlockState.leftMean = *sHvqCbBlockState.currentMean;
    sHvqCrBlockState.rightMode = *sHvqCrBlockState.currentMode;
    sHvqCrBlockState.rightMean = sHvqCrBlockState.leftMean = *sHvqCrBlockState.currentMean;
    sHvqLumaBlockState.rightMode = *sHvqLumaBlockState.currentMode;
    sHvqLumaBlockState.rightMean = sHvqLumaBlockState.leftMean = *sHvqLumaBlockState.currentMean;
    if (sHvqHasSecondLumaRow) {
        sHvqSecondLumaRowBlockState.rightMode = *sHvqSecondLumaRowBlockState.currentMode;
        sHvqSecondLumaRowBlockState.rightMean = sHvqSecondLumaRowBlockState.leftMean = *sHvqSecondLumaRowBlockState.currentMean;
    }

    for (count = sHvqChromaBlockColumns - 1; count > 0; count--) {
        sHvqLumaBlockState.mode = sHvqLumaBlockState.rightMode;
        sHvqLumaBlockState.rightMode = *++sHvqLumaBlockState.currentMode;
        sHvqLumaBlockState.mean = sHvqLumaBlockState.rightMean;
        sHvqLumaBlockState.rightMean = *++sHvqLumaBlockState.currentMean;
        func_80066A44_67644(sHvqLumaSamples, &sHvqLumaBlockState, 0);
        sHvqLumaBlockState.mode = sHvqLumaBlockState.rightMode;
        sHvqLumaBlockState.rightMode = *++sHvqLumaBlockState.currentMode;
        sHvqLumaBlockState.mean = sHvqLumaBlockState.rightMean;
        sHvqLumaBlockState.rightMean = *++sHvqLumaBlockState.currentMean;
        func_80066A44_67644(sHvqLumaSamples + 16, &sHvqLumaBlockState, 0);
        if (sHvqHasSecondLumaRow) {
            sHvqSecondLumaRowBlockState.mode = sHvqSecondLumaRowBlockState.rightMode;
            sHvqSecondLumaRowBlockState.rightMode = *++sHvqSecondLumaRowBlockState.currentMode;
            sHvqSecondLumaRowBlockState.mean = sHvqSecondLumaRowBlockState.rightMean;
            sHvqSecondLumaRowBlockState.rightMean = *++sHvqSecondLumaRowBlockState.currentMean;
            func_80066A44_67644(sHvqLumaSamples + 32, &sHvqSecondLumaRowBlockState, 0);
            sHvqSecondLumaRowBlockState.mode = sHvqSecondLumaRowBlockState.rightMode;
            sHvqSecondLumaRowBlockState.rightMode = *++sHvqSecondLumaRowBlockState.currentMode;
            sHvqSecondLumaRowBlockState.mean = sHvqSecondLumaRowBlockState.rightMean;
            sHvqSecondLumaRowBlockState.rightMean = *++sHvqSecondLumaRowBlockState.currentMean;
            func_80066A44_67644(sHvqLumaSamples + 48, &sHvqSecondLumaRowBlockState, 0);
        }
        sHvqCbBlockState.mode = sHvqCbBlockState.rightMode;
        sHvqCbBlockState.rightMode = *++sHvqCbBlockState.currentMode;
        sHvqCbBlockState.mean = sHvqCbBlockState.rightMean;
        sHvqCbBlockState.rightMean = *++sHvqCbBlockState.currentMean;
        func_80066A44_67644(sHvqCbSamples, &sHvqCbBlockState, 1);
        sHvqCrBlockState.mode = sHvqCrBlockState.rightMode;
        sHvqCrBlockState.rightMode = *++sHvqCrBlockState.currentMode;
        sHvqCrBlockState.mean = sHvqCrBlockState.rightMean;
        sHvqCrBlockState.rightMean = *++sHvqCrBlockState.currentMean;
        func_80066A44_67644(sHvqCrSamples, &sHvqCrBlockState, 2);
        sHvqConvertToRgba(output, sHvqLumaSamples, sHvqCbSamples, sHvqCrSamples);
        output += sHvqOutputGroupColumnStep;
    }

    /* Repeat the rightmost mode and mean at the image boundary. */
    sHvqLumaBlockState.mode = sHvqLumaBlockState.rightMode;
    sHvqLumaBlockState.rightMode = *++sHvqLumaBlockState.currentMode;
    sHvqLumaBlockState.mean = sHvqLumaBlockState.rightMean;
    sHvqLumaBlockState.rightMean = *++sHvqLumaBlockState.currentMean;
    func_80066A44_67644(sHvqLumaSamples, &sHvqLumaBlockState, 0);
    sHvqLumaBlockState.mode = sHvqLumaBlockState.rightMode;
    sHvqLumaBlockState.currentMode++;
    sHvqLumaBlockState.mean = sHvqLumaBlockState.rightMean;
    sHvqLumaBlockState.currentMean++;
    func_80066A44_67644(sHvqLumaSamples + 16, &sHvqLumaBlockState, 0);
    if (sHvqHasSecondLumaRow) {
        sHvqSecondLumaRowBlockState.mode = sHvqSecondLumaRowBlockState.rightMode;
        sHvqSecondLumaRowBlockState.rightMode = *++sHvqSecondLumaRowBlockState.currentMode;
        sHvqSecondLumaRowBlockState.mean = sHvqSecondLumaRowBlockState.rightMean;
        sHvqSecondLumaRowBlockState.rightMean = *++sHvqSecondLumaRowBlockState.currentMean;
        func_80066A44_67644(sHvqLumaSamples + 32, &sHvqSecondLumaRowBlockState, 0);
        sHvqSecondLumaRowBlockState.mode = sHvqSecondLumaRowBlockState.rightMode;
        sHvqSecondLumaRowBlockState.currentMode++;
        sHvqSecondLumaRowBlockState.mean = sHvqSecondLumaRowBlockState.rightMean;
        sHvqSecondLumaRowBlockState.currentMean++;
        func_80066A44_67644(sHvqLumaSamples + 48, &sHvqSecondLumaRowBlockState, 0);
    }
    sHvqCbBlockState.mode = sHvqCbBlockState.rightMode;
    sHvqCbBlockState.currentMode++;
    sHvqCbBlockState.mean = sHvqCbBlockState.rightMean;
    sHvqCbBlockState.currentMean++;
    func_80066A44_67644(sHvqCbSamples, &sHvqCbBlockState, 1);
    sHvqCrBlockState.mode = sHvqCrBlockState.rightMode;
    sHvqCrBlockState.currentMode++;
    sHvqCrBlockState.mean = sHvqCrBlockState.rightMean;
    sHvqCrBlockState.currentMean++;
    func_80066A44_67644(sHvqCrSamples, &sHvqCrBlockState, 2);
    sHvqConvertToRgba(output, sHvqLumaSamples, sHvqCbSamples, sHvqCrSamples);
}

void func_800694D0_6A0D0(u16 *output) {
    s32 count;

    /* Repeat the first row above the image. */
    sHvqCbBlockState.aboveMode = sHvqCbBlockState.currentMode = sHvqBlockModes[1];
    sHvqCbBlockState.aboveMean = sHvqCbBlockState.currentMean = sHvqBlockMeans[1];
    sHvqCbBlockState.belowMode = sHvqCbBlockState.currentMode + sHvqChromaBlockColumns;
    sHvqCbBlockState.belowMean = sHvqCbBlockState.currentMean + sHvqChromaBlockColumns;
    sHvqCrBlockState.aboveMode = sHvqCrBlockState.currentMode = sHvqBlockModes[2];
    sHvqCrBlockState.aboveMean = sHvqCrBlockState.currentMean = sHvqBlockMeans[2];
    sHvqCrBlockState.belowMode = sHvqCrBlockState.currentMode + sHvqChromaBlockColumns;
    sHvqCrBlockState.belowMean = sHvqCrBlockState.currentMean + sHvqChromaBlockColumns;
    sHvqLumaBlockState.aboveMode = sHvqLumaBlockState.currentMode = sHvqBlockModes[0];
    sHvqLumaBlockState.aboveMean = sHvqLumaBlockState.currentMean = sHvqBlockMeans[0];
    sHvqLumaBlockState.belowMode = sHvqLumaBlockState.currentMode + sHvqLumaBlockColumns;
    sHvqLumaBlockState.belowMean = sHvqLumaBlockState.currentMean + sHvqLumaBlockColumns;
    if (sHvqHasSecondLumaRow) {
        sHvqSecondLumaRowBlockState.aboveMode = sHvqLumaBlockState.currentMode;
        sHvqSecondLumaRowBlockState.aboveMean = sHvqLumaBlockState.currentMean;
        sHvqSecondLumaRowBlockState.currentMode = sHvqLumaBlockState.belowMode;
        sHvqSecondLumaRowBlockState.currentMean = sHvqLumaBlockState.belowMean;
        sHvqSecondLumaRowBlockState.belowMode = sHvqSecondLumaRowBlockState.currentMode + sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.belowMean = sHvqSecondLumaRowBlockState.currentMean + sHvqLumaBlockColumns;
    }

    func_80068ECC_69ACC(output);
    output += sHvqOutputGroupRowStep;
    sHvqCbBlockState.aboveMode = sHvqBlockModes[1];
    sHvqCbBlockState.aboveMean = sHvqBlockMeans[1];
    sHvqCrBlockState.aboveMode = sHvqBlockModes[2];
    sHvqCrBlockState.aboveMean = sHvqBlockMeans[2];
    if (sHvqHasSecondLumaRow) {
        sHvqLumaBlockState.currentMode += sHvqLumaBlockColumns;
        sHvqLumaBlockState.currentMean += sHvqLumaBlockColumns;
        sHvqLumaBlockState.belowMode += sHvqLumaBlockColumns;
        sHvqLumaBlockState.belowMean += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.aboveMode += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.aboveMean += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.currentMode += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.currentMean += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.belowMode += sHvqLumaBlockColumns;
        sHvqSecondLumaRowBlockState.belowMean += sHvqLumaBlockColumns;
    } else {
        sHvqLumaBlockState.aboveMode = sHvqBlockModes[0];
        sHvqLumaBlockState.aboveMean = sHvqBlockMeans[0];
    }

    for (count = sHvqChromaBlockRows - 2; count > 0; count--) {
        func_80068ECC_69ACC(output);
        output += sHvqOutputGroupRowStep;
        if (sHvqHasSecondLumaRow) {
            sHvqLumaBlockState.aboveMode += sHvqLumaBlockColumns;
            sHvqLumaBlockState.aboveMean += sHvqLumaBlockColumns;
            sHvqLumaBlockState.currentMode += sHvqLumaBlockColumns;
            sHvqLumaBlockState.currentMean += sHvqLumaBlockColumns;
            sHvqLumaBlockState.belowMode += sHvqLumaBlockColumns;
            sHvqLumaBlockState.belowMean += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.aboveMode += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.aboveMean += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.currentMode += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.currentMean += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.belowMode += sHvqLumaBlockColumns;
            sHvqSecondLumaRowBlockState.belowMean += sHvqLumaBlockColumns;
        }
    }

    /* Repeat the last row below the image. */
    sHvqCbBlockState.belowMode = sHvqCbBlockState.currentMode;
    sHvqCbBlockState.belowMean = sHvqCbBlockState.currentMean;
    sHvqCrBlockState.belowMode = sHvqCrBlockState.currentMode;
    sHvqCrBlockState.belowMean = sHvqCrBlockState.currentMean;
    if (sHvqHasSecondLumaRow) {
        sHvqSecondLumaRowBlockState.belowMode = sHvqSecondLumaRowBlockState.currentMode;
        sHvqSecondLumaRowBlockState.belowMean = sHvqSecondLumaRowBlockState.currentMean;
    } else {
        sHvqLumaBlockState.belowMode = sHvqLumaBlockState.currentMode;
        sHvqLumaBlockState.belowMean = sHvqLumaBlockState.currentMean;
    }
    func_80068ECC_69ACC(output);
}

static inline void HvqInitStream(u32 *data, HvqBitStream *stream) {
    if (*data != 0) {
        stream->nextWord = data + 1;
        stream->mask = 0;
    } else {
        stream->nextWord = NULL;
        stream->mask = 0;
    }
}

static inline void HvqReadModes(void) {
    s32 i;
    u8 *first, *second;
    u8 mode;

    /* Each chroma symbol packs one mode for each color component. */
    first = sHvqBlockModes[0];
    for (i = sHvqLumaBlockCount; i > 0; i--) {
        *first++ = HvqReadSymbol(&sHvqModeStreams[0], &sHvqModeTree);
    }
    first = sHvqBlockModes[1];
    second = sHvqBlockModes[2];
    for (i = sHvqChromaBlockCount; i > 0; i--) {
        mode = HvqReadSymbol(&sHvqModeStreams[1], &sHvqModeTree);
        *first++ = mode & 15;
        *second++ = mode >> 4;
    }
}

void func_800698E8_6A4E8(HvqImageHeader *image, u16 *output, s32 stride, u8 *workBuffer) {
    HvqImageHeader *header = image;
    u8 *data = (u8 *)image;
    u8 *work = workBuffer;
    s32 i, rows;
    u8 *first, *second, *aboveFirst, *aboveSecond;
    u32 firstMean, secondMean;

    HvqInitStream((u32 *)(data + header->modeOffsets[0]), &sHvqModeStreams[0]);
    HvqInitStream((u32 *)(data + header->modeOffsets[1]), &sHvqModeStreams[1]);
    {
        s32 i;

        for (i = 0; i < 3; i++) {
            HvqInitStream((u32 *)(data + header->meanOffsets[i]), &sHvqMeanStreams[i]);
            HvqInitStream((u32 *)(data + header->amplitudeOffsets[i]), &sHvqAmplitudeStreams[i]);
            sHvqRawStreams[i] = data + header->rawOffsets[i] + 4;
        }
    }

    sHvqBlockModes[0] = work;
    sHvqBlockMeans[0] = sHvqBlockModes[0] + sHvqLumaBlockCount;
    sHvqBlockModes[1] = sHvqBlockMeans[0] + sHvqLumaBlockCount;
    sHvqBlockMeans[1] = sHvqBlockModes[1] + sHvqChromaBlockCount;
    sHvqBlockModes[2] = sHvqBlockMeans[1] + sHvqChromaBlockCount;
    sHvqBlockMeans[2] = sHvqBlockModes[2] + sHvqChromaBlockCount;
    sHvqOutputStride = stride;
    sHvqOutputGroupColumnStep = sHvqHorizontalSampling * 4;
    sHvqOutputGroupRowStep = stride * (sHvqVerticalSampling << 2);

    HvqReadModes();

    {
        u32 firstMean;
        u8 *aboveFirst;

        /* The first row uses horizontal deltas. Later rows predict from the
         * previous sample and the sample above the next column. */

        firstMean = 0;
        first = aboveFirst = sHvqBlockMeans[0];
        for (i = sHvqLumaBlockColumns; i > 0; i--) {
            firstMean += HvqReadMean(0);
            *first++ = firstMean;
        }
        for (rows = sHvqLumaBlockRows; rows > 1; rows--) {
            firstMean = *aboveFirst;
            for (i = sHvqLumaBlockColumns; i > 0; i--) {
                firstMean = ((u32) * ++aboveFirst + (*first++ = firstMean + HvqReadMean(0))) >> 1;
            }
        }
    }

    firstMean = secondMean = 0;
    first = aboveFirst = sHvqBlockMeans[1];
    second = aboveSecond = sHvqBlockMeans[2];
    for (i = sHvqChromaBlockColumns; i > 0; i--) {
        firstMean += HvqReadMean(1);
        *first++ = firstMean;
        secondMean += HvqReadMean(2);
        *second++ = secondMean;
    }
    for (rows = sHvqChromaBlockRows; rows > 1; rows--) {
        firstMean = *aboveFirst;
        secondMean = *aboveSecond;
        for (i = sHvqChromaBlockColumns; i > 0; i--) {
            firstMean = ((u32) * ++aboveFirst + (*first++ = firstMean + HvqReadMean(1))) >> 1;
            secondMean = ((u32) * ++aboveSecond + (*second++ = secondMean + HvqReadMean(2))) >> 1;
        }
    }
    func_800694D0_6A0D0(output);
}

static inline void HvqReadTree(u32 *data, HvqBitStream *stream, HvqHuffmanTree *tree) {
    if (*data != 0) {
        stream->nextWord = data + 1;
        stream->mask = 0;
        if (tree != NULL) {
            sHvqNextTreeNode = 256;
            tree->root = func_800665E0_671E0(stream, tree);
        }
    } else {
        stream->nextWord = NULL;
        stream->mask = 0;
    }
}

static inline void HvqReadTable(HvqBitStream *stream) {
    /* Table entries are stored as Huffman-coded deltas. */
    s32 value = 0;
    u8 *output = sHvqPatternTable;
    s32 i;

    for (i = 2660; i > 0; i--) {
        value += HvqReadSymbol(stream, &sHvqPatternTableTree);
        *output++ = value;
    }
}

void func_80069E68_6AA68(void *data) {
    HvqFileHeader *header = data;
    u8 *file = data;
    s32 i;
    s8 symbol;
    s32 shift;
    s32 tableShift;

    if (strcmp(header->signature, sHvqSignature) != 0) {
        osSyncPrintf(sHvqInvalidSignatureError);
        return;
    }

    sHvqImageWidth = header->width;
    sHvqImageHeight = header->height;
    sHvqHorizontalSampling = header->horizontalSampling;
    sHvqVerticalSampling = header->verticalSampling;
    sHvqLumaBlockColumns = sHvqImageWidth / 4;
    sHvqLumaBlockRows = sHvqImageHeight / 4;
    sHvqLumaBlockCount = sHvqLumaBlockColumns * sHvqLumaBlockRows;
    sHvqChromaBlockColumns = sHvqLumaBlockColumns / sHvqHorizontalSampling;
    sHvqChromaBlockRows = sHvqLumaBlockRows / sHvqVerticalSampling;
    sHvqChromaBlockCount = sHvqChromaBlockColumns * sHvqChromaBlockRows;
    if (sHvqVerticalSampling == 1) {
        sHvqHasSecondLumaRow = 0;
        sHvqConvertToRgba = func_800677B8_683B8;
    } else {
        sHvqHasSecondLumaRow = 1;
        sHvqConvertToRgba = func_80067D50_68950;
    }
    sHvqPatternTableTransposed = header->componentOrder;
    if (sHvqPatternTableTransposed == 0) {
        sHvqPatternTableWidth = 70;
        sHvqPatternTableHeight = 38;
    } else {
        sHvqPatternTableWidth = 38;
        sHvqPatternTableHeight = 70;
    }
    sHvqPatternTableDoubleStride = sHvqPatternTableWidth * 2;

    HvqReadTree((u32 *)(file + header->treeOffsets[0]), &sHvqTreeStream, &sHvqModeTree);
    HvqReadTree((u32 *)(file + header->treeOffsets[1]), &sHvqTreeStream, &sHvqMeanTree);
    HvqReadTree((u32 *)(file + header->treeOffsets[2]), &sHvqTreeStream, &sHvqAmplitudeTree);
    HvqReadTree((u32 *)(file + header->treeOffsets[3]), &sHvqTreeStream, &sHvqPatternTableTree);

    /* Translate leaf symbols to the signed, scaled values used by each tree. */
    shift = header->shifts >> 4;
    tableShift = header->shifts & 15;
    for (i = 0, symbol = 0; i < 256; i++, symbol++) {
        sHvqAmplitudeTree.left[i] = symbol << 2;
        sHvqMeanTree.left[i] = symbol << shift;
        sHvqPatternTableTree.left[i] = symbol << 4;
        sHvqModeTree.left[i] = i;
    }
    sHvqMeanDeltaMax = 127 << shift;
    sHvqMeanDeltaMin = -128 << shift;
    sHvqSampleFractionBits = 12 - tableShift;
    sHvqSampleRoundingBias = 1 << (sHvqSampleFractionBits - 1);

    sHvqPatternTable = sHvqPatternTableBuffer;
    HvqReadTable(&sHvqTreeStream);
}

void func_8006A370_6AF70(u8 alpha) {
    s32 index;
    s32 i;
    s32 minColorAlpha;

    sHvqReciprocalTable[0] = 0;
    for (index = 1; index < 512; index++) {
        sHvqReciprocalTable[index] = 4096 / index;
    }

    alpha >>= 7;
    minColorAlpha = alpha;
    /* Clamp the extended color range and pack five color bits plus alpha. */
    for (i = -256, index = 0; index < 768; index++, i++) {
        if (i < 0) {
            sHvqColorClampTable[index] = 0;
            sHvqColorAlphaClampTable[index] = minColorAlpha;
        } else if (i >= 256) {
            sHvqColorClampTable[index] = 0x3E;
            sHvqColorAlphaClampTable[index] = 0x3E | minColorAlpha;
        } else {
            sHvqColorClampTable[index] = (i >> 2) & 0x3E;
            sHvqColorAlphaClampTable[index] = sHvqColorClampTable[index] | alpha;
        }
    }
}
