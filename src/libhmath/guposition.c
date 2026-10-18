#include "common.h"

f32 HuSqrtf(f32 x);

// Builds a floating-point position matrix from Euler rotation, scale, and translation.
void func_80088CB0_main(HuMtx4F mtx, f32 r, f32 p, f32 h, f32 s, f32 x, f32 y, f32 z) {
    f32 sinR, cosR, sinP, cosP, sinH, cosH;

    sincosdf(r, &sinR, &cosR);
    sincosdf(p, &sinP, &cosP);
    sincosdf(h, &sinH, &cosH);

    mtx[0][0] = s * (cosP * cosH);
    mtx[0][1] = s * (cosP * sinH);
    mtx[0][2] = s * (-sinP);
    mtx[0][3] = 0.0f;
    mtx[1][0] = s * (sinR * sinP * cosH - cosR * sinH);
    mtx[1][1] = s * (sinR * sinP * sinH + cosR * cosH);
    mtx[1][2] = s * (sinR * cosP);
    mtx[1][3] = 0.0f;
    mtx[2][0] = s * (cosR * sinP * cosH + sinR * sinH);
    mtx[2][1] = s * (cosR * sinP * sinH - sinR * cosH);
    mtx[2][2] = s * (cosR * cosP);
    mtx[2][3] = 0.0f;
    mtx[3][0] = x;
    mtx[3][1] = y;
    mtx[3][2] = z;
    mtx[3][3] = 1.0f;
}

// Builds a fixed-point position matrix from Euler rotation, scale, and translation.
void func_80088E50_main(Mtx *m, f32 r, f32 p, f32 h, f32 s, f32 x, f32 y, f32 z) {
    f32 sinR, cosR, sinP, cosP, sinH, cosH;
    s32 tmp[12];

    sincosdf(r, &sinR, &cosR);
    sincosdf(p, &sinP, &cosP);
    sincosdf(h, &sinH, &cosH);

    tmp[0] = s * (cosP * cosH) * 65536.0f;
    tmp[1] = s * (cosP * sinH) * 65536.0f;
    tmp[2] = s * (-sinP) * 65536.0f;
    tmp[3] = s * (sinR * sinP * cosH - cosR * sinH) * 65536.0f;
    tmp[4] = s * (sinR * sinP * sinH + cosR * cosH) * 65536.0f;
    tmp[5] = s * (sinR * cosP) * 65536.0f;
    tmp[6] = s * (cosR * sinP * cosH + sinR * sinH) * 65536.0f;
    tmp[7] = s * (cosR * sinP * sinH - sinR * cosH) * 65536.0f;
    tmp[8] = s * (cosR * cosP) * 65536.0f;
    tmp[9] = x * 65536.0f;
    tmp[10] = y * 65536.0f;
    tmp[11] = z * 65536.0f;

    m->m[0][0] = (tmp[0] & 0xFFFF0000) | ((tmp[1] >> 16) & 0xFFFF);
    m->m[0][1] = tmp[2] & 0xFFFF0000;
    m->m[0][2] = (tmp[3] & 0xFFFF0000) | ((tmp[4] >> 16) & 0xFFFF);
    m->m[0][3] = tmp[5] & 0xFFFF0000;
    m->m[1][0] = (tmp[6] & 0xFFFF0000) | ((tmp[7] >> 16) & 0xFFFF);
    m->m[1][1] = tmp[8] & 0xFFFF0000;
    m->m[1][2] = (tmp[9] & 0xFFFF0000) | ((tmp[10] >> 16) & 0xFFFF);
    m->m[1][3] = (tmp[11] & 0xFFFF0000) | 1;
    m->m[2][0] = ((tmp[0] << 16) & 0xFFFF0000) | (tmp[1] & 0xFFFF);
    m->m[2][1] = (tmp[2] << 16) & 0xFFFF0000;
    m->m[2][2] = ((tmp[3] << 16) & 0xFFFF0000) | (tmp[4] & 0xFFFF);
    m->m[2][3] = (tmp[5] << 16) & 0xFFFF0000;
    m->m[3][0] = ((tmp[6] << 16) & 0xFFFF0000) | (tmp[7] & 0xFFFF);
    m->m[3][1] = (tmp[8] << 16) & 0xFFFF0000;
    m->m[3][2] = ((tmp[9] << 16) & 0xFFFF0000) | (tmp[10] & 0xFFFF);
    m->m[3][3] = (tmp[11] << 16) & 0xFFFF0000;
}

// Builds a floating-point matrix that aligns the negative Z axis to a direction.
INCLUDE_ASM("asm/nonmatchings/libhmath/guposition", func_80089190_main);
