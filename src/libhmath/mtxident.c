#include "ultra64.h"

void func_8008A0D0_main(Mtx *mtx) {
    mtx->m[0][1] = mtx->m[0][3] = mtx->m[1][0] = mtx->m[1][2] =
        mtx->m[2][0] = mtx->m[2][1] = mtx->m[2][2] = mtx->m[2][3] =
        mtx->m[3][0] = mtx->m[3][1] = mtx->m[3][2] = mtx->m[3][3] = 0;
    mtx->m[0][0] = mtx->m[1][1] = 0x10000;
    mtx->m[0][2] = mtx->m[1][3] = 1;
}
