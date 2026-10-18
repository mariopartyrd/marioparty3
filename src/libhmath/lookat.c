#include "common.h"
#include "math.h"

// Build a view matrix from camera[0..2] (eye, target, up), returning its basis vectors.
void func_8008D450_main(HuMtx4F mtx, Vec *camera, Vec *basis) {
    HuVecSubtract(&basis[2], &camera[0], &camera[1]);
    HuVecNormalize3F(&basis[2]);
    HuVecCross(&basis[0], &camera[2], &basis[2]);
    HuVecNormalize3F(&basis[0]);
    HuVecCross(&basis[1], &basis[2], &basis[0]);
    HuVecNormalize3F(&basis[1]);

    {
        const Vec *input = basis;
        const f32 x = camera[0].x;
        const f32 y = camera[0].y;
        const f32 z = camera[0].z;

        mtx[0][0] = basis[0].x;
        mtx[1][0] = basis[0].y;
        mtx[2][0] = basis[0].z;
        mtx[3][0] = -(x * input[0].x + y * input[0].y + z * input[0].z);
        mtx[0][1] = basis[1].x;
        mtx[1][1] = basis[1].y;
        mtx[2][1] = basis[1].z;
        mtx[3][1] = -(x * input[1].x + y * input[1].y + z * input[1].z);
        mtx[0][2] = basis[2].x;
        mtx[1][2] = basis[2].y;
        mtx[2][2] = basis[2].z;
        mtx[3][2] = -(x * input[2].x + y * input[2].y + z * input[2].z);
        mtx[0][3] = mtx[1][3] = mtx[2][3] = 0.0f;
        mtx[3][3] = 1.0f;
    }
}
