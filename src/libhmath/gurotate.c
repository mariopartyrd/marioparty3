#include "common.h"

// Builds a floating-point axis-angle rotation matrix.
void func_80088570_main(HuMtx4F mtx, f32 angle, f32 x, f32 y, f32 z) {
    f32 sine, cosine;
    f32 xx, yy, zz;
    f32 xy, yz, zx;
    f32 xs, ys, zs;
    f32 t;
    f32 zero = 0.0f;
    t = 1.0f / HuSqrtf(x * x + y * y + z * z);
    x *= t;
    y *= t;
    z *= t;
    xx = x * x;
    zz = z * z;
    sincosdf(angle, &sine, &cosine);
    xy = x * y;
    zx = z * x;
    yy = y * y;
    xs = x * sine;
    yz = y * z;
    ys = y * sine;
    zs = z * sine;
    t = 1.0f - cosine;
    mtx[0][0] = xx + cosine * (1.0f - xx);
    mtx[2][1] = yz * t - xs;
    mtx[1][2] = yz * t + xs;
    mtx[1][1] = yy + cosine * (1.0f - yy);
    mtx[2][0] = zx * t + ys;
    mtx[2][2] = zz + cosine * (1.0f - zz);
    mtx[0][2] = zx * t - ys;
    mtx[0][1] = xy * t + zs;
    mtx[1][0] = xy * t - zs;
    mtx[3][2] = zero;
    mtx[3][1] = zero;
    mtx[2][3] = zero;
    mtx[1][3] = zero;
    mtx[0][3] = zero;
    mtx[3][0] = zero;
    // The original leaves mtx[3][3] unchanged.
}

// Builds a floating-point scaling matrix.
void func_80088700_main(HuMtx4F mtx, f32 x, f32 y, f32 z) {
    mtx[0][1] = mtx[0][2] = mtx[0][3] = mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[2][3] = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
    mtx[0][0] = x;
    mtx[1][1] = y;
    mtx[2][2] = z;
    mtx[3][3] = 1.0f;
}

// Builds a fixed-point scaling matrix.
void func_80088750_main(Mtx *mtx, f32 x, f32 y, f32 z) {
    f32 scaledX = x * 65536.0f;
    f32 scaledY = y * 65536.0f;
    f32 scaledZ = z * 65536.0f;
    s32 fixedX = scaledX;
    s32 fixedY = scaledY;
    s32 fixedZ = scaledZ;

    mtx->m[1][3] = 1;
    mtx->m[0][1] = 0;
    mtx->m[0][3] = 0;
    mtx->m[1][0] = 0;
    mtx->m[1][2] = 0;
    mtx->m[2][1] = 0;
    mtx->m[2][3] = 0;
    mtx->m[3][0] = 0;
    mtx->m[3][2] = 0;
    mtx->m[3][3] = 0;
    mtx->m[0][0] = fixedX & 0xFFFF0000;
    mtx->m[0][2] = (u32)fixedY >> 16;
    mtx->m[1][1] = fixedZ & 0xFFFF0000;
    mtx->m[2][0] = (fixedX << 16) & 0xFFFF0000;
    mtx->m[2][2] = fixedY & 0xFFFF;
    mtx->m[3][1] = (fixedZ << 16) & 0xFFFF0000;
}

// Builds a floating-point translation matrix.
void func_80088800_main(HuMtx4F mtx, f32 x, f32 y, f32 z) {
    mtx[3][0] = x;
    mtx[3][1] = y;
    mtx[3][2] = z;
    mtx[0][1] = mtx[0][2] = mtx[0][3] = mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[2][3] = 0.0f;
    mtx[0][0] = mtx[1][1] = mtx[2][2] = mtx[3][3] = 1.0f;
}

// Builds a fixed-point translation matrix.
void func_80088850_main(Mtx *mtx, const f32 x, const f32 y, const f32 z) {
    const f32 scaledX = x * 65536.0f;
    const f32 scaledY = y * 65536.0f;
    const f32 scaledZ = z * 65536.0f;
    const s32 fixedX = scaledX;
    const s32 fixedY = scaledY;
    const s32 fixedZ = scaledZ;

    mtx->m[0][0] = 0x10000;
    mtx->m[0][1] = 0;
    mtx->m[0][2] = 1;
    mtx->m[0][3] = 0;
    mtx->m[1][0] = 0;
    mtx->m[1][1] = 0x10000;
    mtx->m[1][2] = (fixedX & 0xFFFF0000) | ((u32)fixedY >> 16);
    mtx->m[1][3] = (fixedZ & 0xFFFF0000) | 1;
    mtx->m[2][0] = 0;
    mtx->m[2][1] = 0;
    mtx->m[2][2] = 0;
    mtx->m[2][3] = 0;
    mtx->m[3][0] = 0;
    mtx->m[3][1] = 0;
    mtx->m[3][2] = ((fixedX << 16) & 0xFFFF0000) | (fixedY & 0xFFFF);
    mtx->m[3][3] = (fixedZ << 16) & 0xFFFF0000;
}
