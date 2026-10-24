#include "common.h"
#include "mtxpack.h"

// Concatenate a fixed-point Z-axis rotation with a matrix.
void func_8008C5E0_main(Mtx *src, f32 angle, Mtx *dst) {
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
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 0, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 0, 1);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 1, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 1, 1);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 2, 0);
    HU_MTX_PACK_PAIR(output, dst, packed1, packed2, 2, 1);
}
