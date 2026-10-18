#include "common.h"

// Builds a floating-point Euler rotation matrix.
void func_80088910_main(HuMtx4F mtx, f32 r, f32 p, f32 h) {
    f32 sin_x, cos_x, sin_y, cos_y, sin_z, cos_z;

    sincosdf(r, &sin_x, &cos_x);
    sincosdf(p, &sin_y, &cos_y);
    sincosdf(h, &sin_z, &cos_z);

    mtx[0][0] = cos_y * cos_z;
    mtx[0][1] = cos_y * sin_z;
    mtx[0][2] = -sin_y;
    mtx[1][0] = sin_x * sin_y * cos_z - cos_x * sin_z;
    mtx[1][1] = sin_x * sin_y * sin_z + cos_x * cos_z;
    mtx[1][2] = sin_x * cos_y;
    mtx[2][0] = cos_x * sin_y * cos_z + sin_x * sin_z;
    mtx[2][1] = cos_x * sin_y * sin_z - sin_x * cos_z;
    mtx[2][2] = cos_x * cos_y;
    mtx[0][3] = mtx[1][3] = mtx[2][3] = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
    mtx[3][3] = 1.0f;
}

// Builds a fixed-point Euler rotation matrix.
void func_80088A70_main(HuMtxFixed *mtx, f32 r, f32 p, f32 h) {
    f32 sin_x, cos_x, sin_y, cos_y, sin_z, cos_z;
    s32 value, value2;
    f32 row01, row02, row10, row11, row12, row20, row21, row22;
    s16(*integer)[4] = mtx->parts.integer;
    u16(*fraction)[4] = mtx->parts.fraction;

    sincosdf(r, &sin_x, &cos_x);
    sincosdf(p, &sin_y, &cos_y);
    sincosdf(h, &sin_z, &cos_z);

    integer[0][3] = 0;
    fraction[0][3] = 0;
    integer[1][3] = 0;
    fraction[1][3] = 0;
    integer[2][3] = 0;
    fraction[2][3] = 0;

    value = (cos_y * cos_z) * 65536.0f;
    row01 = (cos_y * sin_z) * 65536.0f;
    integer[0][0] = value >> 16;
    row02 = (-sin_y) * 65536.0f;
    row10 = (sin_x * sin_y * cos_z - cos_x * sin_z) * 65536.0f;
    row11 = (sin_x * sin_y * sin_z + cos_x * cos_z) * 65536.0f;
    row12 = (sin_x * cos_y) * 65536.0f;
    row20 = (cos_x * sin_y * cos_z + sin_x * sin_z) * 65536.0f;
    row21 = (cos_x * sin_y * sin_z - sin_x * cos_z) * 65536.0f;
    row22 = (cos_x * cos_y) * 65536.0f;
    fraction[0][0] = value;
    value2 = row01;
    integer[0][1] = value2 >> 16;
    fraction[0][1] = value2;
    value = row02;
    integer[0][2] = value >> 16;
    fraction[0][2] = value;
    value = row10;
    integer[1][0] = value >> 16;
    fraction[1][0] = value;
    value2 = row11;
    integer[1][1] = value2 >> 16;
    fraction[1][1] = value2;
    value = row12;
    integer[1][2] = value >> 16;
    fraction[1][2] = value;
    value = row20;
    integer[2][0] = value >> 16;
    fraction[2][0] = value;
    value2 = row21;
    integer[2][1] = value2 >> 16;
    fraction[2][1] = value2;
    value = row22;
    integer[2][2] = value >> 16;
    fraction[2][2] = value;
    integer[3][0] = 0;
    integer[3][1] = 0;
    fraction[3][0] = 0;
    fraction[3][1] = 0;
    integer[3][2] = 0;
    integer[3][3] = 1;
    fraction[3][2] = 0;
    fraction[3][3] = 0;
}
