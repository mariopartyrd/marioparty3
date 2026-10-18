#include "common.h"

// Likely equivalent to guMtxF2L.
void func_800898F0_main(HuMtx4F mf, Mtx *m) {
    s32 i, j;
    s32 ival1, ival2;
    s16 *intPart = (s16 *)m;
    u16 *fracPart = (u16 *)m + 16;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            ival1 = mf[i][j * 2] * 65536.0f;
            ival2 = mf[i][j * 2 + 1] * 65536.0f;
            intPart[0] = ival1 >> 16;
            intPart[1] = ival2 >> 16;
            fracPart[0] = ival1;
            fracPart[1] = ival2;
            intPart += 2;
            fracPart += 2;
        }
    }
}
