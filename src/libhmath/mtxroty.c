#include "common.h"

// Build a fixed-point rotation matrix around the Y axis.
void func_8008A330_main(Mtx *mtx, f32 angle) {
    f32 sincos[4];
    u32 fixedCosine, fixedSine;
    u32 integerCosine, integerNegativeSine, fractionCosine;

    sincosdf(angle, &sincos[0], &sincos[1]);
    fixedCosine = (s32)(sincos[1] * 65536.0f);
    fixedSine = (s32)(sincos[0] * 65536.0f);

    mtx->m[0][0] = fixedCosine;
    mtx->m[0][1] = -fixedSine;
    mtx->m[0][2] = mtx->m[1][3] = 1;
    mtx->m[1][0] = fixedSine;
    mtx->m[2][0] = (u32)mtx->m[0][0] << 16;
    integerCosine = mtx->m[0][0];
    integerNegativeSine = mtx->m[0][1];
    mtx->m[0][3] = mtx->m[2][2] = mtx->m[2][3] = mtx->m[1][2] = mtx->m[3][2] = mtx->m[3][3] = 0;
    mtx->m[2][1] = (u32)mtx->m[0][1] << 16;
    mtx->m[1][1] = mtx->m[0][0] & 0xFFFF0000;
    fractionCosine = mtx->m[0][0];
    mtx->m[3][0] = ((u32)mtx->m[1][0] << 16) & 0xFFFF0000;
    mtx->m[3][1] = (fractionCosine << 16) & 0xFFFF0000;
    mtx->m[1][0] &= 0xFFFF0000;
    mtx->m[0][0] = integerCosine & 0xFFFF0000;
    mtx->m[0][1] = integerNegativeSine & 0xFFFF0000;
}
