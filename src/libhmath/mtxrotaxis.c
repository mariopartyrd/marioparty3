#include "common.h"

// Builds a fixed-point matrix that aligns the negative Z axis to a direction.
void func_8008B300_main(Mtx *m, f32 angle, const f32 *axis) {
    f32 sine, cosine;
    f32 len;
    f32 inv;
    f32 xz;
    f32 x, y, z;
    f32 xn, yn, zn;
    // Upper-left 3x3 matrix in row order, converted to 16.16.
    s32 fixed[9];

    x = axis[0];
    y = axis[1];
    z = axis[2];

    len = HuSqrtf(x * x + y * y + z * z);
    if (len == 0.0f) {
        return;
    }
    len = 1.0f / len;
    xn = x * len;
    zn = z * len;
    yn = y * len;
    xz = HuSqrtf(xn * xn + zn * zn);
    sincosdf(angle, &sine, &cosine);
    if (xz != 0.0f) {
        inv = 1.0f / xz;
        fixed[0] = ((-zn * cosine - sine * yn * xn) * inv) * 65536.0f;
        fixed[1] = sine * xz * 65536.0f;
        fixed[2] = ((cosine * xn - sine * yn * zn) * inv) * 65536.0f;
        fixed[3] = ((zn * sine - cosine * yn * xn) * inv) * 65536.0f;
        fixed[4] = cosine * xz * 65536.0f;
        fixed[5] = ((-sine * xn - cosine * yn * zn) * inv) * 65536.0f;
        fixed[6] = -xn * 65536.0f;
        fixed[7] = -yn * 65536.0f;
        fixed[8] = -zn * 65536.0f;
    } else {
        fixed[0] = cosine * 65536.0f;
        fixed[1] = 0;
        fixed[2] = sine * yn * 65536.0f;
        fixed[3] = -sine * 65536.0f;
        fixed[4] = 0;
        fixed[5] = cosine * yn * 65536.0f;
        fixed[6] = 0;
        fixed[7] = -yn * 65536.0f;
        fixed[8] = 0;
    }
    m->m[0][0] = (fixed[0] & 0xFFFF0000) | ((fixed[1] >> 16) & 0xFFFF);
    m->m[0][1] = fixed[2] & 0xFFFF0000;
    m->m[0][2] = (fixed[3] & 0xFFFF0000) | ((fixed[4] >> 16) & 0xFFFF);
    m->m[0][3] = fixed[5] & 0xFFFF0000;
    m->m[1][0] = (fixed[6] & 0xFFFF0000) | ((fixed[7] >> 16) & 0xFFFF);
    m->m[1][1] = fixed[8] & 0xFFFF0000;
    m->m[1][2] = 0;
    m->m[1][3] = 1;
    m->m[2][0] = ((fixed[0] << 16) & 0xFFFF0000) | (fixed[1] & 0xFFFF);
    m->m[2][1] = (fixed[2] << 16) & 0xFFFF0000;
    m->m[2][2] = ((fixed[3] << 16) & 0xFFFF0000) | (fixed[4] & 0xFFFF);
    m->m[2][3] = (fixed[5] << 16) & 0xFFFF0000;
    m->m[3][0] = ((fixed[6] << 16) & 0xFFFF0000) | (fixed[7] & 0xFFFF);
    m->m[3][1] = (fixed[8] << 16) & 0xFFFF0000;
    m->m[3][2] = 0;
    m->m[3][3] = 0;
}
