#include "common.h"

// Build a fixed-point Euler rotation matrix with scale and translation.
void func_8008AD60_main(Mtx *m, const f32 *rot, const f32 *scale, const f32 *translation) {
    f32 sinR, cosR, sinP, cosP, sinH, cosH;
    // Four rows of three 16.16 elements: rotation/scale followed by translation.
    s32 fixed[12];

    sincosdf(rot[0], &sinR, &cosR);
    sincosdf(rot[1], &sinP, &cosP);
    sincosdf(rot[2], &sinH, &cosH);

    fixed[0] = scale[0] * (cosP * cosH) * 65536.0f;
    fixed[1] = scale[1] * (cosP * sinH) * 65536.0f;
    fixed[2] = scale[2] * (-sinP) * 65536.0f;
    fixed[3] = scale[0] * (sinR * sinP * cosH - cosR * sinH) * 65536.0f;
    fixed[4] = scale[1] * (sinR * sinP * sinH + cosR * cosH) * 65536.0f;
    fixed[5] = scale[2] * (sinR * cosP) * 65536.0f;
    fixed[6] = scale[0] * (cosR * sinP * cosH + sinR * sinH) * 65536.0f;
    fixed[7] = scale[1] * (cosR * sinP * sinH - sinR * cosH) * 65536.0f;
    fixed[8] = scale[2] * (cosR * cosP) * 65536.0f;
    fixed[9] = translation[0] * 65536.0f;
    fixed[10] = translation[1] * 65536.0f;
    fixed[11] = translation[2] * 65536.0f;

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

// Build a floating-point matrix that aligns the negative Z axis to a direction.
void func_8008B0E0_main(HuMtx4F mtx, f32 angle, const f32 *axis) {
    f32 sine, cosine;
    f32 len;
    f32 xz;
    f32 x, y, z;
    f32 xn, yn, zn;
    f32 inv;

    x = axis[0];
    y = axis[1];
    z = axis[2];
    len = HuSqrtf(x * x + y * y + z * z);
    if (len == 0.0f) {
        return;
    }
    len = 1.0f / len;
    xn = x * len;
    yn = y * len;
    zn = z * len;
    xz = HuSqrtf(xn * xn + zn * zn);
    sincosdf(angle, &sine, &cosine);
    if (xz != 0.0f) {
        inv = 1.0f / xz;
        mtx[0][0] = (-zn * cosine - sine * yn * xn) * inv;
        mtx[1][0] = (zn * sine - cosine * yn * xn) * inv;
        mtx[2][0] = -xn;
        mtx[0][1] = sine * xz;
        mtx[1][1] = cosine * xz;
        mtx[2][1] = -yn;
        mtx[0][2] = (cosine * xn - sine * yn * zn) * inv;
        mtx[1][2] = (-sine * xn - cosine * yn * zn) * inv;
        mtx[2][2] = -zn;
    } else {
        mtx[0][0] = cosine;
        mtx[1][0] = -sine;
        mtx[2][0] = 0.0f;
        mtx[0][1] = 0.0f;
        mtx[1][1] = 0.0f;
        mtx[2][1] = -yn;
        mtx[0][2] = sine * yn;
        mtx[1][2] = cosine * yn;
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
