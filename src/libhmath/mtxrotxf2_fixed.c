#include "common.h"

#define UNPACK_PAIR(row, pair)                                                                                              \
    e[0] = (src->m[(row) / 2][((row) % 2) * 2 + (pair)] & 0xFFFF0000) | fixed->parts.fraction[row][(pair) * 2];             \
    e[1] = ((src->m[(row) / 2][((row) % 2) * 2 + (pair)] << 16) & 0xFFFF0000) | fixed->parts.fraction[row][(pair) * 2 + 1]; \
    input[row][(pair) * 2] = e[0] * (1.0f / 65536.0f);                                                                      \
    input[row][(pair) * 2 + 1] = e[1] * (1.0f / 65536.0f)

#define PACK_PAIR(row, pair)                                                                     \
    packed1 = output[row][(pair) * 2] * 65536.0f;                                                \
    packed2 = output[row][(pair) * 2 + 1] * 65536.0f;                                            \
    dst->m[(row) / 2][((row) % 2) * 2 + (pair)] = (packed1 & 0xFFFF0000) | ((u32)packed2 >> 16); \
    dst->m[2 + (row) / 2][((row) % 2) * 2 + (pair)] = ((packed1 << 16) & 0xFFFF0000) | (packed2 & 0xFFFF)

// Concatenate a fixed-point Z-axis rotation with a matrix.
void func_8008C5E0_main(Mtx *src, f32 angle, Mtx *dst) {
    HuMtx4F input, output;
    f32 sincos[2];
    s32 e[2];
    s32 packed1, packed2;
    HuMtxFixed *fixed = (HuMtxFixed *)src;

    sincosdf(angle, &sincos[0], &sincos[1]);
    {
        s32 a = src->m[1][2];
        s32 b = src->m[1][3];
        s32 c = src->m[3][2];
        s32 d = src->m[3][3];
        dst->m[1][2] = a;
        dst->m[1][3] = b;
        dst->m[3][2] = c;
        dst->m[3][3] = d;
    }
    UNPACK_PAIR(0, 0);
    UNPACK_PAIR(0, 1);
    UNPACK_PAIR(1, 0);
    UNPACK_PAIR(1, 1);
    UNPACK_PAIR(2, 0);
    UNPACK_PAIR(2, 1);
    output[0][0] = input[0][0] * sincos[1] + input[1][0] * sincos[0];
    output[0][1] = input[0][1] * sincos[1] + input[1][1] * sincos[0];
    output[0][2] = input[0][2] * sincos[1] + input[1][2] * sincos[0];
    output[0][3] = input[0][3] * sincos[1] + input[1][3] * sincos[0];
    output[1][0] = input[1][0] * sincos[1] - input[0][0] * sincos[0];
    output[1][1] = input[1][1] * sincos[1] - input[0][1] * sincos[0];
    output[1][2] = input[1][2] * sincos[1] - input[0][2] * sincos[0];
    output[1][3] = input[1][3] * sincos[1] - input[0][3] * sincos[0];
    output[2][0] = input[2][0];
    output[2][1] = input[2][1];
    output[2][2] = input[2][2];
    output[2][3] = input[2][3];
    PACK_PAIR(0, 0);
    PACK_PAIR(0, 1);
    PACK_PAIR(1, 0);
    PACK_PAIR(1, 1);
    PACK_PAIR(2, 0);
    PACK_PAIR(2, 1);
}

#undef UNPACK_PAIR
#undef PACK_PAIR
