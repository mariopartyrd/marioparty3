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

static const char D_800A7F50_A8B50[] = "HVQ-MPS 1.1";
/* Preserve the original string storage, including its trailing zero padding. */
static const char D_800A7F5C_A8B5C[52] = "Error : This file is not HVQ-MPS 1.1";

/* BSS declarations follow the original allocation order. */
static u8 D_800BDA90_BE690[768];
static u8 D_800BDD90_BE990[768];
static s32 D_800BE090_BEC90;
static void (*D_800BE094_BEC94)(u16 *, s16 *, s16 *, s16 *);
static s32 D_800BE098_BEC98;
static HvqHuffmanTree D_800BE0A0_BECA0;
static HvqHuffmanTree D_800BE8B0_BF4B0;
static HvqHuffmanTree D_800BF0C0_BFCC0;
static HvqHuffmanTree D_800BF8D0_C04D0;
static s16 D_800C00D2_C0CD2;
static s16 D_800C00D4_C0CD4;
static HvqBitStream sHvqTreeStream;
static HvqBitStream sHvqModeStreams[2];
static HvqBitStream sHvqAmplitudeStreams[3];
static HvqBitStream sHvqMeanStreams[3];
static u8 *D_800C014C_C0D4C[3];
static u8 D_800C0160_C0D60[2660];
static u8 *D_800C0BC4_C17C4;
static s32 D_800C0BC8_C17C8;
static s32 D_800C0BCC_C17CC;
static s32 D_800C0BD0_C17D0;
static s32 D_800C0BD4_C17D4;
static HvqBlockState D_800C0BD8_C17D8;
static HvqBlockState D_800C0BF8_C17F8;
static HvqBlockState D_800C0C18_C1818;
static HvqBlockState D_800C0C38_C1838;
static s32 D_800C0C60_C1860[512];
static u8 *D_800C1460_C2060[3];
static u8 *D_800C146C_C206C[3];
static u16 D_800C1478_C2078;
static u16 D_800C147A_C207A;
static s32 D_800C147C_C207C;
static u16 D_800C1480_C2080;
static u16 D_800C1482_C2082;
static u16 D_800C1484_C2084;
static u16 D_800C1486_C2086;
static u16 D_800C1488_C2088;
static u16 D_800C148A_C208A;
static u8 D_800C148C_C208C;
static u8 D_800C148D_C208D;
static s32 D_800C1490_C2090;
static s32 D_800C1494_C2094;
static s16 D_800C1498_C2098[64];
static s16 D_800C1518_C2118[16];
static s16 D_800C1538_C2138[16];
static s32 D_800C1558_C2158;
static s32 D_800C155C_C215C;

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
        node = D_800BE098_BEC98++;
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

    symbol = HvqReadSymbol(stream, &D_800BE0A0_BECA0);
    value = symbol;
    /* Endpoint symbols extend the value with one or more additional symbols. */
    if (symbol == D_800C00D4_C0CD4 || symbol == D_800C00D2_C0CD2) {
        do {
            symbol = HvqReadSymbol(stream, &D_800BE0A0_BECA0);
            value += symbol;
        } while (symbol <= D_800C00D4_C0CD4 || symbol >= D_800C00D2_C0CD2);
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
    *amplitude += HvqReadSymbol(&sHvqAmplitudeStreams[component], &D_800BF0C0_BFCC0);
    value = *amplitude + ((code >> 13) & 3);
    return ((code & 0x8000) ? -D_800C0C60_C1860[maximum] : D_800C0C60_C1860[maximum]) * value;
}

static inline s32 HvqAbsSample(s16 value) {
    return value < 0 ? -value : value;
}

static inline s32 HvqDecodePattern(s16 *sample, u16 code, s32 *amplitude, s32 component) {
    u8 *row, *entry;
    s32 xStep, yStep;
    s32 sum;
    s16 maximum, magnitude;

    if (D_800C0BD4_C17D4 == 0) {
        row = D_800C0BC4_C17C4 + ((code & 0x3F) + ((code >> 6) & 0x1F) * D_800C0BC8_C17C8);
        xStep = ((code >> 11) & 1) + 1;
        yStep = ((code >> 12) & 1) == 0 ? D_800C0BC8_C17C8 : D_800C0BD0_C17D0;
    } else {
        row = D_800C0BC4_C17C4 + (((code >> 6) & 0x1F) + (code & 0x3F) * D_800C0BC8_C17C8);
        xStep = ((code >> 12) & 1) + 1;
        yStep = ((code >> 11) & 1) == 0 ? D_800C0BC8_C17C8 : D_800C0BD0_C17D0;
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
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
        *output++ = *D_800C014C_C0D4C[component]++;
    } else {
        amplitude = 0;
        pixels[0] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[1] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[2] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[3] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[4] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[5] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[6] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[7] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[8] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[9] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[10] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[11] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[12] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[13] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[14] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        pixels[15] = (mean << D_800C1558_C2158) + D_800C155C_C215C;
        for (count = mode; count > 0; count--) {
            code = *D_800C014C_C0D4C[component]++ << 8;
            code |= *D_800C014C_C0D4C[component]++;
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
        output[0] = pixels[0] >> D_800C1558_C2158;
        output[1] = pixels[1] >> D_800C1558_C2158;
        output[2] = pixels[2] >> D_800C1558_C2158;
        output[3] = pixels[3] >> D_800C1558_C2158;
        output[4] = pixels[4] >> D_800C1558_C2158;
        output[5] = pixels[5] >> D_800C1558_C2158;
        output[6] = pixels[6] >> D_800C1558_C2158;
        output[7] = pixels[7] >> D_800C1558_C2158;
        output[8] = pixels[8] >> D_800C1558_C2158;
        output[9] = pixels[9] >> D_800C1558_C2158;
        output[10] = pixels[10] >> D_800C1558_C2158;
        output[11] = pixels[11] >> D_800C1558_C2158;
        output[12] = pixels[12] >> D_800C1558_C2158;
        output[13] = pixels[13] >> D_800C1558_C2158;
        output[14] = pixels[14] >> D_800C1558_C2158;
        output[15] = pixels[15] >> D_800C1558_C2158;
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
    return (D_800BDA90_BE690[(y + red) >> 6] << 10) | (D_800BDA90_BE690[(y + green) >> 6] << 5) | D_800BDD90_BE990[(y + blue) >> 6];
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

        output += D_800C147C_C207C;
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

        output += D_800C147C_C207C;
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
        output += D_800C147C_C207C;
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

        output += D_800C147C_C207C;
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
        output += D_800C147C_C207C;
        cr++;
        cb++;
    }
}

void func_80068ECC_69ACC(u16 *output) {
    s32 count;

    D_800C0C18_C1818.rightMode = *D_800C0C18_C1818.currentMode;
    D_800C0C18_C1818.rightMean = D_800C0C18_C1818.leftMean = *D_800C0C18_C1818.currentMean;
    D_800C0C38_C1838.rightMode = *D_800C0C38_C1838.currentMode;
    D_800C0C38_C1838.rightMean = D_800C0C38_C1838.leftMean = *D_800C0C38_C1838.currentMean;
    D_800C0BD8_C17D8.rightMode = *D_800C0BD8_C17D8.currentMode;
    D_800C0BD8_C17D8.rightMean = D_800C0BD8_C17D8.leftMean = *D_800C0BD8_C17D8.currentMean;
    if (D_800BE090_BEC90) {
        D_800C0BF8_C17F8.rightMode = *D_800C0BF8_C17F8.currentMode;
        D_800C0BF8_C17F8.rightMean = D_800C0BF8_C17F8.leftMean = *D_800C0BF8_C17F8.currentMean;
    }

    for (count = D_800C1486_C2086 - 1; count > 0; count--) {
        D_800C0BD8_C17D8.mode = D_800C0BD8_C17D8.rightMode;
        D_800C0BD8_C17D8.rightMode = *++D_800C0BD8_C17D8.currentMode;
        D_800C0BD8_C17D8.mean = D_800C0BD8_C17D8.rightMean;
        D_800C0BD8_C17D8.rightMean = *++D_800C0BD8_C17D8.currentMean;
        func_80066A44_67644(D_800C1498_C2098, &D_800C0BD8_C17D8, 0);
        D_800C0BD8_C17D8.mode = D_800C0BD8_C17D8.rightMode;
        D_800C0BD8_C17D8.rightMode = *++D_800C0BD8_C17D8.currentMode;
        D_800C0BD8_C17D8.mean = D_800C0BD8_C17D8.rightMean;
        D_800C0BD8_C17D8.rightMean = *++D_800C0BD8_C17D8.currentMean;
        func_80066A44_67644(D_800C1498_C2098 + 16, &D_800C0BD8_C17D8, 0);
        if (D_800BE090_BEC90) {
            D_800C0BF8_C17F8.mode = D_800C0BF8_C17F8.rightMode;
            D_800C0BF8_C17F8.rightMode = *++D_800C0BF8_C17F8.currentMode;
            D_800C0BF8_C17F8.mean = D_800C0BF8_C17F8.rightMean;
            D_800C0BF8_C17F8.rightMean = *++D_800C0BF8_C17F8.currentMean;
            func_80066A44_67644(D_800C1498_C2098 + 32, &D_800C0BF8_C17F8, 0);
            D_800C0BF8_C17F8.mode = D_800C0BF8_C17F8.rightMode;
            D_800C0BF8_C17F8.rightMode = *++D_800C0BF8_C17F8.currentMode;
            D_800C0BF8_C17F8.mean = D_800C0BF8_C17F8.rightMean;
            D_800C0BF8_C17F8.rightMean = *++D_800C0BF8_C17F8.currentMean;
            func_80066A44_67644(D_800C1498_C2098 + 48, &D_800C0BF8_C17F8, 0);
        }
        D_800C0C18_C1818.mode = D_800C0C18_C1818.rightMode;
        D_800C0C18_C1818.rightMode = *++D_800C0C18_C1818.currentMode;
        D_800C0C18_C1818.mean = D_800C0C18_C1818.rightMean;
        D_800C0C18_C1818.rightMean = *++D_800C0C18_C1818.currentMean;
        func_80066A44_67644(D_800C1518_C2118, &D_800C0C18_C1818, 1);
        D_800C0C38_C1838.mode = D_800C0C38_C1838.rightMode;
        D_800C0C38_C1838.rightMode = *++D_800C0C38_C1838.currentMode;
        D_800C0C38_C1838.mean = D_800C0C38_C1838.rightMean;
        D_800C0C38_C1838.rightMean = *++D_800C0C38_C1838.currentMean;
        func_80066A44_67644(D_800C1538_C2138, &D_800C0C38_C1838, 2);
        D_800BE094_BEC94(output, D_800C1498_C2098, D_800C1518_C2118, D_800C1538_C2138);
        output += D_800C1490_C2090;
    }

    /* Repeat the rightmost mode and mean at the image boundary. */
    D_800C0BD8_C17D8.mode = D_800C0BD8_C17D8.rightMode;
    D_800C0BD8_C17D8.rightMode = *++D_800C0BD8_C17D8.currentMode;
    D_800C0BD8_C17D8.mean = D_800C0BD8_C17D8.rightMean;
    D_800C0BD8_C17D8.rightMean = *++D_800C0BD8_C17D8.currentMean;
    func_80066A44_67644(D_800C1498_C2098, &D_800C0BD8_C17D8, 0);
    D_800C0BD8_C17D8.mode = D_800C0BD8_C17D8.rightMode;
    D_800C0BD8_C17D8.currentMode++;
    D_800C0BD8_C17D8.mean = D_800C0BD8_C17D8.rightMean;
    D_800C0BD8_C17D8.currentMean++;
    func_80066A44_67644(D_800C1498_C2098 + 16, &D_800C0BD8_C17D8, 0);
    if (D_800BE090_BEC90) {
        D_800C0BF8_C17F8.mode = D_800C0BF8_C17F8.rightMode;
        D_800C0BF8_C17F8.rightMode = *++D_800C0BF8_C17F8.currentMode;
        D_800C0BF8_C17F8.mean = D_800C0BF8_C17F8.rightMean;
        D_800C0BF8_C17F8.rightMean = *++D_800C0BF8_C17F8.currentMean;
        func_80066A44_67644(D_800C1498_C2098 + 32, &D_800C0BF8_C17F8, 0);
        D_800C0BF8_C17F8.mode = D_800C0BF8_C17F8.rightMode;
        D_800C0BF8_C17F8.currentMode++;
        D_800C0BF8_C17F8.mean = D_800C0BF8_C17F8.rightMean;
        D_800C0BF8_C17F8.currentMean++;
        func_80066A44_67644(D_800C1498_C2098 + 48, &D_800C0BF8_C17F8, 0);
    }
    D_800C0C18_C1818.mode = D_800C0C18_C1818.rightMode;
    D_800C0C18_C1818.currentMode++;
    D_800C0C18_C1818.mean = D_800C0C18_C1818.rightMean;
    D_800C0C18_C1818.currentMean++;
    func_80066A44_67644(D_800C1518_C2118, &D_800C0C18_C1818, 1);
    D_800C0C38_C1838.mode = D_800C0C38_C1838.rightMode;
    D_800C0C38_C1838.currentMode++;
    D_800C0C38_C1838.mean = D_800C0C38_C1838.rightMean;
    D_800C0C38_C1838.currentMean++;
    func_80066A44_67644(D_800C1538_C2138, &D_800C0C38_C1838, 2);
    D_800BE094_BEC94(output, D_800C1498_C2098, D_800C1518_C2118, D_800C1538_C2138);
}

void func_800694D0_6A0D0(u16 *output) {
    s32 count;

    /* Repeat the first row above the image. */
    D_800C0C18_C1818.aboveMode = D_800C0C18_C1818.currentMode = D_800C1460_C2060[1];
    D_800C0C18_C1818.aboveMean = D_800C0C18_C1818.currentMean = D_800C146C_C206C[1];
    D_800C0C18_C1818.belowMode = D_800C0C18_C1818.currentMode + D_800C1486_C2086;
    D_800C0C18_C1818.belowMean = D_800C0C18_C1818.currentMean + D_800C1486_C2086;
    D_800C0C38_C1838.aboveMode = D_800C0C38_C1838.currentMode = D_800C1460_C2060[2];
    D_800C0C38_C1838.aboveMean = D_800C0C38_C1838.currentMean = D_800C146C_C206C[2];
    D_800C0C38_C1838.belowMode = D_800C0C38_C1838.currentMode + D_800C1486_C2086;
    D_800C0C38_C1838.belowMean = D_800C0C38_C1838.currentMean + D_800C1486_C2086;
    D_800C0BD8_C17D8.aboveMode = D_800C0BD8_C17D8.currentMode = D_800C1460_C2060[0];
    D_800C0BD8_C17D8.aboveMean = D_800C0BD8_C17D8.currentMean = D_800C146C_C206C[0];
    D_800C0BD8_C17D8.belowMode = D_800C0BD8_C17D8.currentMode + D_800C1480_C2080;
    D_800C0BD8_C17D8.belowMean = D_800C0BD8_C17D8.currentMean + D_800C1480_C2080;
    if (D_800BE090_BEC90) {
        D_800C0BF8_C17F8.aboveMode = D_800C0BD8_C17D8.currentMode;
        D_800C0BF8_C17F8.aboveMean = D_800C0BD8_C17D8.currentMean;
        D_800C0BF8_C17F8.currentMode = D_800C0BD8_C17D8.belowMode;
        D_800C0BF8_C17F8.currentMean = D_800C0BD8_C17D8.belowMean;
        D_800C0BF8_C17F8.belowMode = D_800C0BF8_C17F8.currentMode + D_800C1480_C2080;
        D_800C0BF8_C17F8.belowMean = D_800C0BF8_C17F8.currentMean + D_800C1480_C2080;
    }

    func_80068ECC_69ACC(output);
    output += D_800C1494_C2094;
    D_800C0C18_C1818.aboveMode = D_800C1460_C2060[1];
    D_800C0C18_C1818.aboveMean = D_800C146C_C206C[1];
    D_800C0C38_C1838.aboveMode = D_800C1460_C2060[2];
    D_800C0C38_C1838.aboveMean = D_800C146C_C206C[2];
    if (D_800BE090_BEC90) {
        D_800C0BD8_C17D8.currentMode += D_800C1480_C2080;
        D_800C0BD8_C17D8.currentMean += D_800C1480_C2080;
        D_800C0BD8_C17D8.belowMode += D_800C1480_C2080;
        D_800C0BD8_C17D8.belowMean += D_800C1480_C2080;
        D_800C0BF8_C17F8.aboveMode += D_800C1480_C2080;
        D_800C0BF8_C17F8.aboveMean += D_800C1480_C2080;
        D_800C0BF8_C17F8.currentMode += D_800C1480_C2080;
        D_800C0BF8_C17F8.currentMean += D_800C1480_C2080;
        D_800C0BF8_C17F8.belowMode += D_800C1480_C2080;
        D_800C0BF8_C17F8.belowMean += D_800C1480_C2080;
    } else {
        D_800C0BD8_C17D8.aboveMode = D_800C1460_C2060[0];
        D_800C0BD8_C17D8.aboveMean = D_800C146C_C206C[0];
    }

    for (count = D_800C1488_C2088 - 2; count > 0; count--) {
        func_80068ECC_69ACC(output);
        output += D_800C1494_C2094;
        if (D_800BE090_BEC90) {
            D_800C0BD8_C17D8.aboveMode += D_800C1480_C2080;
            D_800C0BD8_C17D8.aboveMean += D_800C1480_C2080;
            D_800C0BD8_C17D8.currentMode += D_800C1480_C2080;
            D_800C0BD8_C17D8.currentMean += D_800C1480_C2080;
            D_800C0BD8_C17D8.belowMode += D_800C1480_C2080;
            D_800C0BD8_C17D8.belowMean += D_800C1480_C2080;
            D_800C0BF8_C17F8.aboveMode += D_800C1480_C2080;
            D_800C0BF8_C17F8.aboveMean += D_800C1480_C2080;
            D_800C0BF8_C17F8.currentMode += D_800C1480_C2080;
            D_800C0BF8_C17F8.currentMean += D_800C1480_C2080;
            D_800C0BF8_C17F8.belowMode += D_800C1480_C2080;
            D_800C0BF8_C17F8.belowMean += D_800C1480_C2080;
        }
    }

    /* Repeat the last row below the image. */
    D_800C0C18_C1818.belowMode = D_800C0C18_C1818.currentMode;
    D_800C0C18_C1818.belowMean = D_800C0C18_C1818.currentMean;
    D_800C0C38_C1838.belowMode = D_800C0C38_C1838.currentMode;
    D_800C0C38_C1838.belowMean = D_800C0C38_C1838.currentMean;
    if (D_800BE090_BEC90) {
        D_800C0BF8_C17F8.belowMode = D_800C0BF8_C17F8.currentMode;
        D_800C0BF8_C17F8.belowMean = D_800C0BF8_C17F8.currentMean;
    } else {
        D_800C0BD8_C17D8.belowMode = D_800C0BD8_C17D8.currentMode;
        D_800C0BD8_C17D8.belowMean = D_800C0BD8_C17D8.currentMean;
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
    first = D_800C1460_C2060[0];
    for (i = D_800C1484_C2084; i > 0; i--) {
        *first++ = HvqReadSymbol(&sHvqModeStreams[0], &D_800BE8B0_BF4B0);
    }
    first = D_800C1460_C2060[1];
    second = D_800C1460_C2060[2];
    for (i = D_800C148A_C208A; i > 0; i--) {
        mode = HvqReadSymbol(&sHvqModeStreams[1], &D_800BE8B0_BF4B0);
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
            D_800C014C_C0D4C[i] = data + header->rawOffsets[i] + 4;
        }
    }

    D_800C1460_C2060[0] = work;
    D_800C146C_C206C[0] = D_800C1460_C2060[0] + D_800C1484_C2084;
    D_800C1460_C2060[1] = D_800C146C_C206C[0] + D_800C1484_C2084;
    D_800C146C_C206C[1] = D_800C1460_C2060[1] + D_800C148A_C208A;
    D_800C1460_C2060[2] = D_800C146C_C206C[1] + D_800C148A_C208A;
    D_800C146C_C206C[2] = D_800C1460_C2060[2] + D_800C148A_C208A;
    D_800C147C_C207C = stride;
    D_800C1490_C2090 = D_800C148C_C208C * 4;
    D_800C1494_C2094 = stride * (D_800C148D_C208D << 2);

    HvqReadModes();

    {
        u32 firstMean;
        u8 *aboveFirst;

        /* The first row uses horizontal deltas. Later rows predict from the
         * previous sample and the sample above the next column. */

        firstMean = 0;
        first = aboveFirst = D_800C146C_C206C[0];
        for (i = D_800C1480_C2080; i > 0; i--) {
            firstMean += HvqReadMean(0);
            *first++ = firstMean;
        }
        for (rows = D_800C1482_C2082; rows > 1; rows--) {
            firstMean = *aboveFirst;
            for (i = D_800C1480_C2080; i > 0; i--) {
                firstMean = ((u32) * ++aboveFirst + (*first++ = firstMean + HvqReadMean(0))) >> 1;
            }
        }
    }

    firstMean = secondMean = 0;
    first = aboveFirst = D_800C146C_C206C[1];
    second = aboveSecond = D_800C146C_C206C[2];
    for (i = D_800C1486_C2086; i > 0; i--) {
        firstMean += HvqReadMean(1);
        *first++ = firstMean;
        secondMean += HvqReadMean(2);
        *second++ = secondMean;
    }
    for (rows = D_800C1488_C2088; rows > 1; rows--) {
        firstMean = *aboveFirst;
        secondMean = *aboveSecond;
        for (i = D_800C1486_C2086; i > 0; i--) {
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
            D_800BE098_BEC98 = 256;
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
    u8 *output = D_800C0BC4_C17C4;
    s32 i;

    for (i = 2660; i > 0; i--) {
        value += HvqReadSymbol(stream, &D_800BF8D0_C04D0);
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

    if (strcmp(header->signature, D_800A7F50_A8B50) != 0) {
        osSyncPrintf(D_800A7F5C_A8B5C);
        return;
    }

    D_800C1478_C2078 = header->width;
    D_800C147A_C207A = header->height;
    D_800C148C_C208C = header->horizontalSampling;
    D_800C148D_C208D = header->verticalSampling;
    D_800C1480_C2080 = D_800C1478_C2078 / 4;
    D_800C1482_C2082 = D_800C147A_C207A / 4;
    D_800C1484_C2084 = D_800C1480_C2080 * D_800C1482_C2082;
    D_800C1486_C2086 = D_800C1480_C2080 / D_800C148C_C208C;
    D_800C1488_C2088 = D_800C1482_C2082 / D_800C148D_C208D;
    D_800C148A_C208A = D_800C1486_C2086 * D_800C1488_C2088;
    if (D_800C148D_C208D == 1) {
        D_800BE090_BEC90 = 0;
        D_800BE094_BEC94 = func_800677B8_683B8;
    } else {
        D_800BE090_BEC90 = 1;
        D_800BE094_BEC94 = func_80067D50_68950;
    }
    D_800C0BD4_C17D4 = header->componentOrder;
    if (D_800C0BD4_C17D4 == 0) {
        D_800C0BC8_C17C8 = 70;
        D_800C0BCC_C17CC = 38;
    } else {
        D_800C0BC8_C17C8 = 38;
        D_800C0BCC_C17CC = 70;
    }
    D_800C0BD0_C17D0 = D_800C0BC8_C17C8 * 2;

    HvqReadTree((u32 *)(file + header->treeOffsets[0]), &sHvqTreeStream, &D_800BE8B0_BF4B0);
    HvqReadTree((u32 *)(file + header->treeOffsets[1]), &sHvqTreeStream, &D_800BE0A0_BECA0);
    HvqReadTree((u32 *)(file + header->treeOffsets[2]), &sHvqTreeStream, &D_800BF0C0_BFCC0);
    HvqReadTree((u32 *)(file + header->treeOffsets[3]), &sHvqTreeStream, &D_800BF8D0_C04D0);

    /* Translate leaf symbols to the signed, scaled values used by each tree. */
    shift = header->shifts >> 4;
    tableShift = header->shifts & 15;
    for (i = 0, symbol = 0; i < 256; i++, symbol++) {
        D_800BF0C0_BFCC0.left[i] = symbol << 2;
        D_800BE0A0_BECA0.left[i] = symbol << shift;
        D_800BF8D0_C04D0.left[i] = symbol << 4;
        D_800BE8B0_BF4B0.left[i] = i;
    }
    D_800C00D2_C0CD2 = 127 << shift;
    D_800C00D4_C0CD4 = -128 << shift;
    D_800C1558_C2158 = 12 - tableShift;
    D_800C155C_C215C = 1 << (D_800C1558_C2158 - 1);

    D_800C0BC4_C17C4 = D_800C0160_C0D60;
    HvqReadTable(&sHvqTreeStream);
}

void func_8006A370_6AF70(u8 alpha) {
    s32 index;
    s32 i;
    s32 minColorAlpha;

    D_800C0C60_C1860[0] = 0;
    for (index = 1; index < 512; index++) {
        D_800C0C60_C1860[index] = 4096 / index;
    }

    alpha >>= 7;
    minColorAlpha = alpha;
    /* Clamp the extended color range and pack five color bits plus alpha. */
    for (i = -256, index = 0; index < 768; index++, i++) {
        if (i < 0) {
            D_800BDA90_BE690[index] = 0;
            D_800BDD90_BE990[index] = minColorAlpha;
        } else if (i >= 256) {
            D_800BDA90_BE690[index] = 0x3E;
            D_800BDD90_BE990[index] = 0x3E | minColorAlpha;
        } else {
            D_800BDA90_BE690[index] = (i >> 2) & 0x3E;
            D_800BDD90_BE990[index] = D_800BDA90_BE690[index] | alpha;
        }
    }
}
