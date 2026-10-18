#include "common.h"

// Build a float scale matrix.
void func_8008A5C0_main(HuMtx4F mtx, f32 *scale) {
    f32 x = scale[0];
    f32 y = scale[1];
    f32 z = scale[2];

    mtx[0][1] = mtx[0][2] = mtx[0][3] = mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[2][3] = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
    mtx[0][0] = x;
    mtx[1][1] = y;
    mtx[2][2] = z;
    mtx[3][3] = 1.0f;
}

// Build a fixed-point scale matrix.
void func_8008A620_main(Mtx *mtx, f32 *scale) {
    u32 x = (s32)(scale[0] * 65536.0f);
    u32 y = (s32)(scale[1] * 65536.0f);
    u32 z = (s32)(scale[2] * 65536.0f);

    mtx->m[0][0] = x & 0xFFFF0000;
    mtx->m[0][1] = 0;
    mtx->m[0][2] = y >> 16;
    mtx->m[0][3] = 0;
    mtx->m[1][0] = 0;
    mtx->m[1][1] = z & 0xFFFF0000;
    mtx->m[1][2] = 0;
    mtx->m[1][3] = 1;
    mtx->m[2][0] = (x << 16) & 0xFFFF0000;
    mtx->m[2][1] = 0;
    mtx->m[2][2] = y & 0xFFFF;
    mtx->m[2][3] = 0;
    mtx->m[3][0] = 0;
    mtx->m[3][1] = (z << 16) & 0xFFFF0000;
    mtx->m[3][2] = 0;
    mtx->m[3][3] = 0;
}

// Build a float translation matrix.
void func_8008A6D0_main(HuMtx4F mtx, f32 *translation) {
    f32 x = translation[0];
    f32 y = translation[1];
    f32 z = translation[2];

    mtx[0][1] = mtx[0][2] = mtx[0][3] = mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[2][3] = 0.0f;
    mtx[3][0] = x;
    mtx[3][1] = y;
    mtx[3][2] = z;
    mtx[0][0] = mtx[1][1] = mtx[2][2] = mtx[3][3] = 1.0f;
}

// Build a fixed-point translation matrix.
void func_8008A730_main(Mtx *mtx, const f32 *translation) {
    u32 x = (s32)(translation[0] * 65536.0f);
    u32 y = (s32)(translation[1] * 65536.0f);
    u32 z = (s32)(translation[2] * 65536.0f);

    mtx->m[0][0] = 0x10000;
    mtx->m[0][1] = 0;
    mtx->m[0][2] = 1;
    mtx->m[0][3] = 0;
    mtx->m[1][0] = 0;
    mtx->m[1][1] = 0x10000;
    mtx->m[1][2] = (x & 0xFFFF0000) | (y >> 16);
    mtx->m[1][3] = (z & 0xFFFF0000) | 1;
    mtx->m[2][0] = 0;
    mtx->m[2][1] = 0;
    mtx->m[2][2] = 0;
    mtx->m[2][3] = 0;
    mtx->m[3][0] = 0;
    mtx->m[3][1] = 0;
    mtx->m[3][2] = ((x << 16) & 0xFFFF0000) | (y & 0xFFFF);
    mtx->m[3][3] = (z << 16) & 0xFFFF0000;
}
