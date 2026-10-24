#include "common.h"

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
    // Four rows of three 16.16 elements: rotation/scale followed by translation.
    s32 fixed[12];

    sincosdf(r, &sinR, &cosR);
    sincosdf(p, &sinP, &cosP);
    sincosdf(h, &sinH, &cosH);

    fixed[0] = s * (cosP * cosH) * 65536.0f;
    fixed[1] = s * (cosP * sinH) * 65536.0f;
    fixed[2] = s * (-sinP) * 65536.0f;
    fixed[3] = s * (sinR * sinP * cosH - cosR * sinH) * 65536.0f;
    fixed[4] = s * (sinR * sinP * sinH + cosR * cosH) * 65536.0f;
    fixed[5] = s * (sinR * cosP) * 65536.0f;
    fixed[6] = s * (cosR * sinP * cosH + sinR * sinH) * 65536.0f;
    fixed[7] = s * (cosR * sinP * sinH - sinR * cosH) * 65536.0f;
    fixed[8] = s * (cosR * cosP) * 65536.0f;
    fixed[9] = x * 65536.0f;
    fixed[10] = y * 65536.0f;
    fixed[11] = z * 65536.0f;

    m->m[0][0] = (fixed[0] & 0xFFFF0000) | ((fixed[1] >> 16) & 0xFFFF);
    m->m[0][1] = fixed[2] & 0xFFFF0000;
    m->m[0][2] = (fixed[3] & 0xFFFF0000) | ((fixed[4] >> 16) & 0xFFFF);
    m->m[0][3] = fixed[5] & 0xFFFF0000;
    m->m[1][0] = (fixed[6] & 0xFFFF0000) | ((fixed[7] >> 16) & 0xFFFF);
    m->m[1][1] = fixed[8] & 0xFFFF0000;
    m->m[1][2] = (fixed[9] & 0xFFFF0000) | ((fixed[10] >> 16) & 0xFFFF);
    m->m[1][3] = (fixed[11] & 0xFFFF0000) | 1;
    m->m[2][0] = ((fixed[0] << 16) & 0xFFFF0000) | (fixed[1] & 0xFFFF);
    m->m[2][1] = (fixed[2] << 16) & 0xFFFF0000;
    m->m[2][2] = ((fixed[3] << 16) & 0xFFFF0000) | (fixed[4] & 0xFFFF);
    m->m[2][3] = (fixed[5] << 16) & 0xFFFF0000;
    m->m[3][0] = ((fixed[6] << 16) & 0xFFFF0000) | (fixed[7] & 0xFFFF);
    m->m[3][1] = (fixed[8] << 16) & 0xFFFF0000;
    m->m[3][2] = ((fixed[9] << 16) & 0xFFFF0000) | (fixed[10] & 0xFFFF);
    m->m[3][3] = (fixed[11] << 16) & 0xFFFF0000;
}

// Builds a floating-point matrix that aligns the negative Z axis to a direction.
void func_80089190_main(HuMtx4F mtx, f32 angle, f32 x, f32 y, f32 z) {
    f32 sine, cosine;
    f32 len;
    f32 inv;
    f32 xz;

    len = HuSqrtf(x * x + y * y + z * z);
    if (len == 0.0f) {
        return;
    }
    len = 1.0f / len;
    x *= len;
    z *= len;
    y *= len;
    xz = HuSqrtf(x * x + z * z);
    sincosdf(angle, &sine, &cosine);
    if (xz != 0.0f) {
        inv = 1.0f / xz;
        mtx[0][0] = (-z * cosine - sine * y * x) * inv;
        mtx[1][0] = (z * sine - cosine * y * x) * inv;
        mtx[2][0] = -x;
        mtx[0][1] = sine * xz;
        mtx[1][1] = cosine * xz;
        mtx[2][1] = -y;
        mtx[0][2] = (cosine * x - sine * y * z) * inv;
        mtx[1][2] = (-sine * x - cosine * y * z) * inv;
        mtx[2][2] = -z;
    } else {
        mtx[0][0] = cosine;
        mtx[1][0] = -sine;
        mtx[2][0] = 0.0f;
        mtx[0][1] = 0.0f;
        mtx[1][1] = 0.0f;
        mtx[2][1] = -y;
        mtx[0][2] = sine * y;
        mtx[1][2] = cosine * y;
        mtx[2][2] = 0.0f;
    }
    mtx[3][0] = 0.0f;
    mtx[3][1] = 0.0f;
    mtx[3][2] = 0.0f;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    mtx[3][3] = 1.0f;
}
