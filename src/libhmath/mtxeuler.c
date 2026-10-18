#include "common.h"

// Build a float rotation matrix from Euler angles.
void func_8008A7F0_main(HuMtx4F mtx, const f32 *rot) {
    f32 sin_x, cos_x, sin_y, cos_y, sin_z, cos_z;

    sincosdf(rot[0], &sin_x, &cos_x);
    sincosdf(rot[1], &sin_y, &cos_y);
    sincosdf(rot[2], &sin_z, &cos_z);

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
