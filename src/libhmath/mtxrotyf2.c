#include "common.h"
#include "mtxpack.h"

// Concatenate a fixed-point X-axis rotation with a matrix.
void func_8008B840_main(Mtx *src, f32 angle, Mtx *dst) {
    HuMtx4F input, output;
    f32 sincos[2];
    s32 e[2];
    s32 packed1, packed2;
    u16 (*fraction)[4] = (u16 (*)[4])&src->m[2];

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
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 0, 0);
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 0, 1);
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 1, 0);
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 1, 1);
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 2, 0);
    HU_MTX_UNPACK_PAIR(src, fraction, input, e, 2, 1);
    output[1][0] = input[1][0] * sincos[1] + input[2][0] * sincos[0];
    output[1][1] = input[1][1] * sincos[1] + input[2][1] * sincos[0];
    output[1][2] = input[1][2] * sincos[1] + input[2][2] * sincos[0];
    output[1][3] = input[1][3] * sincos[1] + input[2][3] * sincos[0];
    output[2][0] = input[2][0] * sincos[1] - input[1][0] * sincos[0];
    output[2][1] = input[2][1] * sincos[1] - input[1][1] * sincos[0];
    output[2][2] = input[2][2] * sincos[1] - input[1][2] * sincos[0];
    output[2][3] = input[2][3] * sincos[1] - input[1][3] * sincos[0];
    output[0][0] = input[0][0];
    output[0][1] = input[0][1];
    output[0][2] = input[0][2];
    output[0][3] = input[0][3];
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 0, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 0, 1);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 1, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 1, 1);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 2, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 2, 1);
}

// Concatenate a float Y-axis rotation with a matrix.
void func_8008BD90_main(const HuMtx4F src, f32 angle, HuMtx4F dst) {
    f32 sine, cosine;

    sincosdf(angle, &sine, &cosine);
    dst[0][0] = src[0][0] * cosine - src[2][0] * sine;
    dst[0][1] = src[0][1] * cosine - src[2][1] * sine;
    dst[0][2] = src[0][2] * cosine - src[2][2] * sine;
    dst[0][3] = src[0][3] * cosine - src[2][3] * sine;
    dst[2][0] = src[0][0] * sine + src[2][0] * cosine;
    dst[2][1] = src[0][1] * sine + src[2][1] * cosine;
    dst[2][2] = src[0][2] * sine + src[2][2] * cosine;
    dst[2][3] = src[0][3] * sine + src[2][3] * cosine;
    dst[1][0] = src[1][0];
    dst[1][1] = src[1][1];
    dst[1][2] = src[1][2];
    dst[1][3] = src[1][3];
    dst[3][0] = src[3][0];
    dst[3][1] = src[3][1];
    dst[3][2] = src[3][2];
    dst[3][3] = src[3][3];
}
