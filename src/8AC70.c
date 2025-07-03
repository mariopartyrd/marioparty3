#include "ultra64.h"

#define M_ID(m, i, j) ((m)[(i) * 4 + (j)])

void func_8008A070_8AC70(f32* mtx) {
    f32 one = 1.0f;

    M_ID(mtx, 0, 1) = M_ID(mtx, 0, 2) = M_ID(mtx, 0, 3) =
    M_ID(mtx, 1, 0) = M_ID(mtx, 1, 2) = M_ID(mtx, 1, 3) =
    M_ID(mtx, 2, 0) = M_ID(mtx, 2, 1) = M_ID(mtx, 2, 3) =
    M_ID(mtx, 3, 0) = M_ID(mtx, 3, 1) = M_ID(mtx, 3, 2) = 0.0f;
    M_ID(mtx, 0, 0) = M_ID(mtx, 1, 1) = M_ID(mtx, 2, 2) = M_ID(mtx, 3, 3) = one;
}
