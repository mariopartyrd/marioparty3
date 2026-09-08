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

static const char D_800A7F50_main[] = "HVQ-MPS 1.1";
/* Preserve the original string storage, including its trailing zero padding. */
static const char D_800A7F5C_main[52] = "Error : This file is not HVQ-MPS 1.1";

extern s32 D_800BE098_main;
extern HvqHuffmanTree D_800BE0A0_main;
extern s16 D_800C00D2_main;
extern s16 D_800C00D4_main;
extern s32 D_800C0C60_main[512];
extern u8 D_800BDA90_main[768];
extern u8 D_800BDD90_main[768];

extern HvqHuffmanTree D_800BE8B0_main;
extern HvqHuffmanTree D_800BF0C0_main;
extern HvqHuffmanTree D_800BF8D0_main;
extern u16 D_800C1478_main;
extern u16 D_800C147A_main;
extern s32 D_800C147C_main;
extern u16 D_800C1480_main;
extern u16 D_800C1482_main;
extern u16 D_800C1484_main;
extern u16 D_800C1486_main;
extern u16 D_800C1488_main;
extern u16 D_800C148A_main;
extern u8 D_800C148C_main;
extern u8 D_800C148D_main;
extern s32 D_800BE090_main;
extern s32 D_800C0BD4_main;
extern s32 D_800C0BC8_main;
extern s32 D_800C0BCC_main;
extern s32 D_800C0BD0_main;
extern s32 D_800C1558_main;
extern s32 D_800C155C_main;
extern HvqBitStream D_800C00D8_main;
extern HvqBitStream D_800C00E8_main;
extern HvqBitStream D_800C00F4_main;
extern HvqBitStream D_800C0128_main[3];
extern HvqBitStream D_800C0134_main;
extern HvqBitStream D_800C0140_main;
extern HvqBitStream D_800C0100_main[3];
extern u8 *D_800C014C_main[3];
extern u8 D_800C0160_main[2660];
extern u8 *D_800C0BC4_main;
extern HvqBlockState D_800C0BD8_main;
extern HvqBlockState D_800C0BF8_main;
extern HvqBlockState D_800C0C18_main;
extern HvqBlockState D_800C0C38_main;
extern u8 *D_800C1460_main[3];
extern u8 *D_800C146C_main[3];
extern s32 D_800C1494_main;
extern s32 D_800C1490_main;
extern s16 D_800C1498_main[64];
extern s16 D_800C1518_main[16];
extern s16 D_800C1538_main[16];
extern void (*D_800BE094_main)(u16 *, s16 *, s16 *, s16 *);

void func_800677B8_main(u16 *, s16 *, s16 *, s16 *);
void func_80067D50_main(u16 *, s16 *, s16 *, s16 *);

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

s16 func_800665E0_main(HvqBitStream *stream, HvqHuffmanTree *tree) {
    s32 node;
    u32 bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0;

    /* A set bit introduces a branch, followed by its left and right subtrees. */
    if (HvqReadBit(stream)) {
        node = D_800BE098_main++;
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

s32 func_80066894_main(HvqBitStream *stream) {
    s16 value;
    s16 symbol;

    symbol = HvqReadSymbol(stream, &D_800BE0A0_main);
    value = symbol;
    /* Endpoint symbols extend the value with one or more additional symbols. */
    if (symbol == D_800C00D4_main || symbol == D_800C00D2_main) {
        do {
            symbol = HvqReadSymbol(stream, &D_800BE0A0_main);
            value += symbol;
        } while (symbol <= D_800C00D4_main || symbol >= D_800C00D2_main);
    }
    return value;
}

static inline s32 HvqPatternScale(s32 *amplitude, u16 code, s16 maximum, s32 component) {
    s32 value;

    /* Huffman deltas supply the coarse amplitude; the code adds two low
     * bits and a sign. Normalize by the pattern's largest deviation. */
    *amplitude += HvqReadSymbol(&D_800C0100_main[component], &D_800BF0C0_main);
    value = *amplitude + ((code >> 13) & 3);
    return ((code & 0x8000) ? -D_800C0C60_main[maximum] : D_800C0C60_main[maximum]) * value;
}

static inline s32 HvqAbsSample(s16 value) {
    return value < 0 ? -value : value;
}

static inline s32 HvqDecodePattern(s16 *sample, u16 code, s32 *amplitude, s32 component) {
    u8 *row, *entry;
    s32 xStep, yStep;
    s32 sum;
    s16 maximum, magnitude;

    if (D_800C0BD4_main == 0) {
        row = D_800C0BC4_main + ((code & 0x3F) + ((code >> 6) & 0x1F) * D_800C0BC8_main);
        xStep = ((code >> 11) & 1) + 1;
        yStep = ((code >> 12) & 1) == 0 ? D_800C0BC8_main : D_800C0BD0_main;
    } else {
        row = D_800C0BC4_main + (((code >> 6) & 0x1F) + (code & 0x3F) * D_800C0BC8_main);
        xStep = ((code >> 12) & 1) + 1;
        yStep = ((code >> 11) & 1) == 0 ? D_800C0BC8_main : D_800C0BD0_main;
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
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
        *output++ = *D_800C014C_main[component]++;
    } else {
        amplitude = 0;
        pixels[0] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[1] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[2] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[3] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[4] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[5] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[6] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[7] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[8] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[9] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[10] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[11] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[12] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[13] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[14] = (mean << D_800C1558_main) + D_800C155C_main;
        pixels[15] = (mean << D_800C1558_main) + D_800C155C_main;
        for (count = mode; count > 0; count--) {
            code = *D_800C014C_main[component]++ << 8;
            code |= *D_800C014C_main[component]++;
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
        output[0] = pixels[0] >> D_800C1558_main;
        output[1] = pixels[1] >> D_800C1558_main;
        output[2] = pixels[2] >> D_800C1558_main;
        output[3] = pixels[3] >> D_800C1558_main;
        output[4] = pixels[4] >> D_800C1558_main;
        output[5] = pixels[5] >> D_800C1558_main;
        output[6] = pixels[6] >> D_800C1558_main;
        output[7] = pixels[7] >> D_800C1558_main;
        output[8] = pixels[8] >> D_800C1558_main;
        output[9] = pixels[9] >> D_800C1558_main;
        output[10] = pixels[10] >> D_800C1558_main;
        output[11] = pixels[11] >> D_800C1558_main;
        output[12] = pixels[12] >> D_800C1558_main;
        output[13] = pixels[13] >> D_800C1558_main;
        output[14] = pixels[14] >> D_800C1558_main;
        output[15] = pixels[15] >> D_800C1558_main;
    }
}

void func_80066A44_main(s16 *output, HvqBlockState *state, s32 component) {
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
    return (D_800BDA90_main[(y + red) >> 6] << 10) | (D_800BDA90_main[(y + green) >> 6] << 5) | D_800BDD90_main[(y + blue) >> 6];
}

void func_800677B8_main(u16 *output, s16 *luma, s16 *cb, s16 *cr) {
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

        output += D_800C147C_main;
    }
}

void func_80067D50_main(u16 *output, s16 *luma, s16 *cb, s16 *cr) {
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

        output += D_800C147C_main;
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
        output += D_800C147C_main;
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

        output += D_800C147C_main;
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
        output += D_800C147C_main;
        cr++;
        cb++;
    }
}

void func_80068ECC_main(u16 *output) {
    s32 count;

    D_800C0C18_main.rightMode = *D_800C0C18_main.currentMode;
    D_800C0C18_main.rightMean = D_800C0C18_main.leftMean = *D_800C0C18_main.currentMean;
    D_800C0C38_main.rightMode = *D_800C0C38_main.currentMode;
    D_800C0C38_main.rightMean = D_800C0C38_main.leftMean = *D_800C0C38_main.currentMean;
    D_800C0BD8_main.rightMode = *D_800C0BD8_main.currentMode;
    D_800C0BD8_main.rightMean = D_800C0BD8_main.leftMean = *D_800C0BD8_main.currentMean;
    if (D_800BE090_main) {
        D_800C0BF8_main.rightMode = *D_800C0BF8_main.currentMode;
        D_800C0BF8_main.rightMean = D_800C0BF8_main.leftMean = *D_800C0BF8_main.currentMean;
    }

    for (count = D_800C1486_main - 1; count > 0; count--) {
        D_800C0BD8_main.mode = D_800C0BD8_main.rightMode;
        D_800C0BD8_main.rightMode = *++D_800C0BD8_main.currentMode;
        D_800C0BD8_main.mean = D_800C0BD8_main.rightMean;
        D_800C0BD8_main.rightMean = *++D_800C0BD8_main.currentMean;
        func_80066A44_main(D_800C1498_main, &D_800C0BD8_main, 0);
        D_800C0BD8_main.mode = D_800C0BD8_main.rightMode;
        D_800C0BD8_main.rightMode = *++D_800C0BD8_main.currentMode;
        D_800C0BD8_main.mean = D_800C0BD8_main.rightMean;
        D_800C0BD8_main.rightMean = *++D_800C0BD8_main.currentMean;
        func_80066A44_main(D_800C1498_main + 16, &D_800C0BD8_main, 0);
        if (D_800BE090_main) {
            D_800C0BF8_main.mode = D_800C0BF8_main.rightMode;
            D_800C0BF8_main.rightMode = *++D_800C0BF8_main.currentMode;
            D_800C0BF8_main.mean = D_800C0BF8_main.rightMean;
            D_800C0BF8_main.rightMean = *++D_800C0BF8_main.currentMean;
            func_80066A44_main(D_800C1498_main + 32, &D_800C0BF8_main, 0);
            D_800C0BF8_main.mode = D_800C0BF8_main.rightMode;
            D_800C0BF8_main.rightMode = *++D_800C0BF8_main.currentMode;
            D_800C0BF8_main.mean = D_800C0BF8_main.rightMean;
            D_800C0BF8_main.rightMean = *++D_800C0BF8_main.currentMean;
            func_80066A44_main(D_800C1498_main + 48, &D_800C0BF8_main, 0);
        }
        D_800C0C18_main.mode = D_800C0C18_main.rightMode;
        D_800C0C18_main.rightMode = *++D_800C0C18_main.currentMode;
        D_800C0C18_main.mean = D_800C0C18_main.rightMean;
        D_800C0C18_main.rightMean = *++D_800C0C18_main.currentMean;
        func_80066A44_main(D_800C1518_main, &D_800C0C18_main, 1);
        D_800C0C38_main.mode = D_800C0C38_main.rightMode;
        D_800C0C38_main.rightMode = *++D_800C0C38_main.currentMode;
        D_800C0C38_main.mean = D_800C0C38_main.rightMean;
        D_800C0C38_main.rightMean = *++D_800C0C38_main.currentMean;
        func_80066A44_main(D_800C1538_main, &D_800C0C38_main, 2);
        D_800BE094_BEC94(output, D_800C1498_main, D_800C1518_main, D_800C1538_main);
        output += D_800C1490_main;
    }

    /* Repeat the rightmost mode and mean at the image boundary. */
    D_800C0BD8_main.mode = D_800C0BD8_main.rightMode;
    D_800C0BD8_main.rightMode = *++D_800C0BD8_main.currentMode;
    D_800C0BD8_main.mean = D_800C0BD8_main.rightMean;
    D_800C0BD8_main.rightMean = *++D_800C0BD8_main.currentMean;
    func_80066A44_main(D_800C1498_main, &D_800C0BD8_main, 0);
    D_800C0BD8_main.mode = D_800C0BD8_main.rightMode;
    D_800C0BD8_main.currentMode++;
    D_800C0BD8_main.mean = D_800C0BD8_main.rightMean;
    D_800C0BD8_main.currentMean++;
    func_80066A44_main(D_800C1498_main + 16, &D_800C0BD8_main, 0);
    if (D_800BE090_main) {
        D_800C0BF8_main.mode = D_800C0BF8_main.rightMode;
        D_800C0BF8_main.rightMode = *++D_800C0BF8_main.currentMode;
        D_800C0BF8_main.mean = D_800C0BF8_main.rightMean;
        D_800C0BF8_main.rightMean = *++D_800C0BF8_main.currentMean;
        func_80066A44_main(D_800C1498_main + 32, &D_800C0BF8_main, 0);
        D_800C0BF8_main.mode = D_800C0BF8_main.rightMode;
        D_800C0BF8_main.currentMode++;
        D_800C0BF8_main.mean = D_800C0BF8_main.rightMean;
        D_800C0BF8_main.currentMean++;
        func_80066A44_main(D_800C1498_main + 48, &D_800C0BF8_main, 0);
    }
    D_800C0C18_main.mode = D_800C0C18_main.rightMode;
    D_800C0C18_main.currentMode++;
    D_800C0C18_main.mean = D_800C0C18_main.rightMean;
    D_800C0C18_main.currentMean++;
    func_80066A44_main(D_800C1518_main, &D_800C0C18_main, 1);
    D_800C0C38_main.mode = D_800C0C38_main.rightMode;
    D_800C0C38_main.currentMode++;
    D_800C0C38_main.mean = D_800C0C38_main.rightMean;
    D_800C0C38_main.currentMean++;
    func_80066A44_main(D_800C1538_main, &D_800C0C38_main, 2);
    D_800BE094_main(output, D_800C1498_main, D_800C1518_main, D_800C1538_main);
}

void func_800694D0_main(u16 *output) {
    s32 count;

    /* Repeat the first row above the image. */
    D_800C0C18_main.aboveMode = D_800C0C18_main.currentMode = D_800C1460_main[1];
    D_800C0C18_main.aboveMean = D_800C0C18_main.currentMean = D_800C146C_main[1];
    D_800C0C18_main.belowMode = D_800C0C18_main.currentMode + D_800C1486_main;
    D_800C0C18_main.belowMean = D_800C0C18_main.currentMean + D_800C1486_main;
    D_800C0C38_main.aboveMode = D_800C0C38_main.currentMode = D_800C1460_main[2];
    D_800C0C38_main.aboveMean = D_800C0C38_main.currentMean = D_800C146C_main[2];
    D_800C0C38_main.belowMode = D_800C0C38_main.currentMode + D_800C1486_main;
    D_800C0C38_main.belowMean = D_800C0C38_main.currentMean + D_800C1486_main;
    D_800C0BD8_main.aboveMode = D_800C0BD8_main.currentMode = D_800C1460_main[0];
    D_800C0BD8_main.aboveMean = D_800C0BD8_main.currentMean = D_800C146C_main[0];
    D_800C0BD8_main.belowMode = D_800C0BD8_main.currentMode + D_800C1480_main;
    D_800C0BD8_main.belowMean = D_800C0BD8_main.currentMean + D_800C1480_main;
    if (D_800BE090_main) {
        D_800C0BF8_main.aboveMode = D_800C0BD8_main.currentMode;
        D_800C0BF8_main.aboveMean = D_800C0BD8_main.currentMean;
        D_800C0BF8_main.currentMode = D_800C0BD8_main.belowMode;
        D_800C0BF8_main.currentMean = D_800C0BD8_main.belowMean;
        D_800C0BF8_main.belowMode = D_800C0BF8_main.currentMode + D_800C1480_main;
        D_800C0BF8_main.belowMean = D_800C0BF8_main.currentMean + D_800C1480_main;
    }

    func_80068ECC_main(output);
    output += D_800C1494_main;
    D_800C0C18_main.aboveMode = D_800C1460_main[1];
    D_800C0C18_main.aboveMean = D_800C146C_main[1];
    D_800C0C38_main.aboveMode = D_800C1460_main[2];
    D_800C0C38_main.aboveMean = D_800C146C_main[2];
    if (D_800BE090_main) {
        D_800C0BD8_main.currentMode += D_800C1480_main;
        D_800C0BD8_main.currentMean += D_800C1480_main;
        D_800C0BD8_main.belowMode += D_800C1480_main;
        D_800C0BD8_main.belowMean += D_800C1480_main;
        D_800C0BF8_main.aboveMode += D_800C1480_main;
        D_800C0BF8_main.aboveMean += D_800C1480_main;
        D_800C0BF8_main.currentMode += D_800C1480_main;
        D_800C0BF8_main.currentMean += D_800C1480_main;
        D_800C0BF8_main.belowMode += D_800C1480_main;
        D_800C0BF8_main.belowMean += D_800C1480_main;
    } else {
        D_800C0BD8_main.aboveMode = D_800C1460_main[0];
        D_800C0BD8_main.aboveMean = D_800C146C_main[0];
    }

    for (count = D_800C1488_main - 2; count > 0; count--) {
        func_80068ECC_main(output);
        output += D_800C1494_main;
        if (D_800BE090_main) {
            D_800C0BD8_main.aboveMode += D_800C1480_main;
            D_800C0BD8_main.aboveMean += D_800C1480_main;
            D_800C0BD8_main.currentMode += D_800C1480_main;
            D_800C0BD8_main.currentMean += D_800C1480_main;
            D_800C0BD8_main.belowMode += D_800C1480_main;
            D_800C0BD8_main.belowMean += D_800C1480_main;
            D_800C0BF8_main.aboveMode += D_800C1480_main;
            D_800C0BF8_main.aboveMean += D_800C1480_main;
            D_800C0BF8_main.currentMode += D_800C1480_main;
            D_800C0BF8_main.currentMean += D_800C1480_main;
            D_800C0BF8_main.belowMode += D_800C1480_main;
            D_800C0BF8_main.belowMean += D_800C1480_main;
        }
    }

    /* Repeat the last row below the image. */
    D_800C0C18_main.belowMode = D_800C0C18_main.currentMode;
    D_800C0C18_main.belowMean = D_800C0C18_main.currentMean;
    D_800C0C38_main.belowMode = D_800C0C38_main.currentMode;
    D_800C0C38_main.belowMean = D_800C0C38_main.currentMean;
    if (D_800BE090_main) {
        D_800C0BF8_main.belowMode = D_800C0BF8_main.currentMode;
        D_800C0BF8_main.belowMean = D_800C0BF8_main.currentMean;
    } else {
        D_800C0BD8_main.belowMode = D_800C0BD8_main.currentMode;
        D_800C0BD8_main.belowMean = D_800C0BD8_main.currentMean;
    }
    func_80068ECC_main(output);
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
    first = D_800C1460_main[0];
    for (i = D_800C1484_main; i > 0; i--) {
        *first++ = HvqReadSymbol(&D_800C00E8_main, &D_800BE8B0_main);
    }
    first = D_800C1460_main[1];
    second = D_800C1460_main[2];
    for (i = D_800C148A_main; i > 0; i--) {
        mode = HvqReadSymbol(&D_800C00F4_main, &D_800BE8B0_main);
        *first++ = mode & 15;
        *second++ = mode >> 4;
    }
}

void func_800698E8_main(HvqImageHeader *image, u16 *output, s32 stride, u8 *workBuffer) {
    HvqImageHeader *header = image;
    u8 *data = (u8 *)image;
    u8 *work = workBuffer;
    s32 i, rows;
    u8 *first, *second, *aboveFirst, *aboveSecond;
    u32 firstMean, secondMean;

    HvqInitStream((u32 *)(data + header->modeOffsets[0]), &D_800C00E8_main);
    HvqInitStream((u32 *)(data + header->modeOffsets[1]), &D_800C00F4_main);
    {
        s32 i;

        for (i = 0; i < 3; i++) {
            HvqInitStream((u32 *)(data + header->meanOffsets[i]), &D_800C0128_main[i]);
            HvqInitStream((u32 *)(data + header->amplitudeOffsets[i]), &D_800C0100_main[i]);
            D_800C014C_main[i] = data + header->rawOffsets[i] + 4;
        }
    }

    D_800C1460_main[0] = work;
    D_800C146C_main[0] = D_800C1460_main[0] + D_800C1484_main;
    D_800C1460_main[1] = D_800C146C_main[0] + D_800C1484_main;
    D_800C146C_main[1] = D_800C1460_main[1] + D_800C148A_main;
    D_800C1460_main[2] = D_800C146C_main[1] + D_800C148A_main;
    D_800C146C_main[2] = D_800C1460_main[2] + D_800C148A_main;
    D_800C147C_main = stride;
    D_800C1490_main = D_800C148C_main * 4;
    D_800C1494_main = stride * (D_800C148D_main << 2);

    HvqReadModes();

    {
        u32 firstMean;
        u8 *aboveFirst;

        /* The first row uses horizontal deltas. Later rows predict from the
         * previous sample and the sample above the next column. */

        firstMean = 0;
        first = aboveFirst = D_800C146C_main[0];
        for (i = D_800C1480_main; i > 0; i--) {
            firstMean += func_80066894_67494(&D_800C0128_main[0]);
            *first++ = firstMean;
        }
        for (rows = D_800C1482_main; rows > 1; rows--) {
            firstMean = *aboveFirst;
            for (i = D_800C1480_main; i > 0; i--) {
                firstMean = ((u32) * ++aboveFirst + (*first++ = firstMean + func_80066894_67494(&D_800C0128_main[0]))) >> 1;
            }
        }
    }

    firstMean = secondMean = 0;
    first = aboveFirst = D_800C146C_main[1];
    second = aboveSecond = D_800C146C_main[2];
    for (i = D_800C1486_main; i > 0; i--) {
        firstMean += func_80066894_67494(&D_800C0134_main);
        *first++ = firstMean;
        secondMean += func_80066894_67494(&D_800C0140_main);
        *second++ = secondMean;
    }
    for (rows = D_800C1488_main; rows > 1; rows--) {
        firstMean = *aboveFirst;
        secondMean = *aboveSecond;
        for (i = D_800C1486_main; i > 0; i--) {
            firstMean = ((u32) * ++aboveFirst + (*first++ = firstMean + func_80066894_67494(&D_800C0134_main))) >> 1;
            secondMean = ((u32) * ++aboveSecond + (*second++ = secondMean + func_80066894_67494(&D_800C0140_main))) >> 1;
        }
    }
    func_800694D0_main(output);
}

static inline void HvqReadTree(u32 *data, HvqBitStream *stream, HvqHuffmanTree *tree) {
    if (*data != 0) {
        stream->nextWord = data + 1;
        stream->mask = 0;
        if (tree != NULL) {
            D_800BE098_main = 256;
            tree->root = func_800665E0_main(stream, tree);
        }
    } else {
        stream->nextWord = NULL;
        stream->mask = 0;
    }
}

static inline void HvqReadTable(HvqBitStream *stream) {
    /* Table entries are stored as Huffman-coded deltas. */
    s32 value = 0;
    u8 *output = D_800C0BC4_main;
    s32 i;

    for (i = 2660; i > 0; i--) {
        value += HvqReadSymbol(stream, &D_800BF8D0_main);
        *output++ = value;
    }
}

void func_80069E68_main(void *data) {
    HvqFileHeader *header = data;
    u8 *file = data;
    s32 i;
    s8 symbol;
    s32 shift;
    s32 tableShift;

    if (strcmp(header->signature, D_800A7F50_main) != 0) {
        osSyncPrintf(D_800A7F5C_main);
        return;
    }

    D_800C1478_main = header->width;
    D_800C147A_main = header->height;
    D_800C148C_main = header->horizontalSampling;
    D_800C148D_main = header->verticalSampling;
    D_800C1480_main = D_800C1478_main / 4;
    D_800C1482_main = D_800C147A_main / 4;
    D_800C1484_main = D_800C1480_main * D_800C1482_main;
    D_800C1486_main = D_800C1480_main / D_800C148C_main;
    D_800C1488_main = D_800C1482_main / D_800C148D_main;
    D_800C148A_main = D_800C1486_main * D_800C1488_main;
    if (D_800C148D_main == 1) {
        D_800BE090_main = 0;
        D_800BE094_main = func_800677B8_main;
    } else {
        D_800BE090_main = 1;
        D_800BE094_main = func_80067D50_main;
    }
    D_800C0BD4_main = header->componentOrder;
    if (D_800C0BD4_main == 0) {
        D_800C0BC8_main = 70;
        D_800C0BCC_main = 38;
    } else {
        D_800C0BC8_main = 38;
        D_800C0BCC_main = 70;
    }
    D_800C0BD0_main = D_800C0BC8_main * 2;

    HvqReadTree((u32 *)(file + header->treeOffsets[0]), &D_800C00D8_main, &D_800BE8B0_main);
    HvqReadTree((u32 *)(file + header->treeOffsets[1]), &D_800C00D8_main, &D_800BE0A0_main);
    HvqReadTree((u32 *)(file + header->treeOffsets[2]), &D_800C00D8_main, &D_800BF0C0_main);
    HvqReadTree((u32 *)(file + header->treeOffsets[3]), &D_800C00D8_main, &D_800BF8D0_main);

    /* Translate leaf symbols to the signed, scaled values used by each tree. */
    shift = header->shifts >> 4;
    tableShift = header->shifts & 15;
    for (i = 0, symbol = 0; i < 256; i++, symbol++) {
        D_800BF0C0_main.left[i] = symbol << 2;
        D_800BE0A0_main.left[i] = symbol << shift;
        D_800BF8D0_main.left[i] = symbol << 4;
        D_800BE8B0_main.left[i] = i;
    }
    D_800C00D2_main = 127 << shift;
    D_800C00D4_main = -128 << shift;
    D_800C1558_main = 12 - tableShift;
    D_800C155C_main = 1 << (D_800C1558_main - 1);

    D_800C0BC4_main = D_800C0160_main;
    HvqReadTable(&D_800C00D8_main);
}

void func_8006A370_main(u8 alpha) {
    s32 index;
    s32 i;
    s32 minColorAlpha;

    D_800C0C60_main[0] = 0;
    for (index = 1; index < 512; index++) {
        D_800C0C60_main[index] = 4096 / index;
    }

    alpha >>= 7;
    minColorAlpha = alpha;
    /* Clamp the extended color range and pack five color bits plus alpha. */
    for (i = -256, index = 0; index < 768; index++, i++) {
        if (i < 0) {
            D_800BDA90_main[index] = 0;
            D_800BDD90_main[index] = minColorAlpha;
        } else if (i >= 256) {
            D_800BDA90_main[index] = 0x3E;
            D_800BDD90_main[index] = 0x3E | minColorAlpha;
        } else {
            D_800BDA90_main[index] = (i >> 2) & 0x3E;
            D_800BDD90_main[index] = D_800BDA90_main[index] | alpha;
        }
    }
}
