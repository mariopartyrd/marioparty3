#include "common.h"

f32 HuSqrtf(f32 x);

// Build a fixed-point Euler rotation matrix with scale and translation.
void func_8008AD60_main(Mtx *m, const f32 *rot, const f32 *scale, const f32 *translation) {
    f32 sinR, cosR, sinP, cosP, sinH, cosH;
    s32 tmp[12];

    sincosdf(rot[0], &sinR, &cosR);
    sincosdf(rot[1], &sinP, &cosP);
    sincosdf(rot[2], &sinH, &cosH);

    tmp[0] = scale[0] * (cosP * cosH) * 65536.0f;
    tmp[1] = scale[1] * (cosP * sinH) * 65536.0f;
    tmp[2] = scale[2] * (-sinP) * 65536.0f;
    tmp[3] = scale[0] * (sinR * sinP * cosH - cosR * sinH) * 65536.0f;
    tmp[4] = scale[1] * (sinR * sinP * sinH + cosR * cosH) * 65536.0f;
    tmp[5] = scale[2] * (sinR * cosP) * 65536.0f;
    tmp[6] = scale[0] * (cosR * sinP * cosH + sinR * sinH) * 65536.0f;
    tmp[7] = scale[1] * (cosR * sinP * sinH - sinR * cosH) * 65536.0f;
    tmp[8] = scale[2] * (cosR * cosP) * 65536.0f;
    tmp[9] = translation[0] * 65536.0f;
    tmp[10] = translation[1] * 65536.0f;
    tmp[11] = translation[2] * 65536.0f;

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

// Build a float rotation matrix around an arbitrary axis.
INCLUDE_ASM("asm/nonmatchings/libhmath/mtxeulersrt2", func_8008B0E0_main);
