#include "common.h"

// Build a fixed-point rotation matrix around the Z axis.
void func_8008A4C0_main(Mtx *mtx, f32 angle) {
    f32 sincos[2];
    u32 fixedCosine, fixedSine;
    u16 (*integer)[4] = (u16 (*)[4])mtx->m;

    sincosdf(angle, &sincos[0], &sincos[1]);
    fixedCosine = (s32)(sincos[1] * 65536.0f);
    fixedSine = (s32)(sincos[0] * 65536.0f);
    mtx->m[1][1] = fixedCosine;
    mtx->m[1][3] = fixedSine;
    mtx->m[0][2] = (-mtx->m[1][3] & 0xFFFF0000) | integer[2][2];
    mtx->m[2][2] = (-mtx->m[1][3] << 16 & 0xFFFF0000) | integer[2][3];
    mtx->m[0][0] = (mtx->m[1][1] & 0xFFFF0000) | integer[3][2];
    mtx->m[2][0] = (mtx->m[1][1] << 16 & 0xFFFF0000) | integer[3][3];
    mtx->m[0][1] = mtx->m[0][3] = mtx->m[1][0] = mtx->m[1][2] = mtx->m[2][1] =
        mtx->m[2][3] = mtx->m[3][0] = mtx->m[3][1] = mtx->m[3][2] = mtx->m[3][3] = 0;
    mtx->m[1][1] = 0x10000;
    mtx->m[1][3] = 1;
}
