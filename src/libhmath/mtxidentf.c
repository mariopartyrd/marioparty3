#include "ultra64.h"
#include "types.h"

void func_8008A070_main(HuMtx4F mtx) {
    f32 one = 1.0f;

    mtx[0][1] = mtx[0][2] = mtx[0][3] =
        mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[2][3] =
        mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
    mtx[0][0] = mtx[1][1] = mtx[2][2] = mtx[3][3] = one;
}
