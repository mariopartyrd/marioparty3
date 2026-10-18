#include "common.h"

// Likely equivalent to guMtxL2F.
void func_80089980_main(HuMtx4F mf, Mtx *m) {
    s32 i, j;
    s32 e1, e2;
    u16 *intPart = (u16 *)m;
    u16 *fracPart = (u16 *)m + 16;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            e1 = (s32)(((u32)intPart[0] << 16) | fracPart[0]);
            mf[i][j * 2] = e1 * (1.0f / 65536.0f);
            e2 = (s32)(((u32)intPart[1] << 16) | fracPart[1]);
            mf[i][j * 2 + 1] = e2 * (1.0f / 65536.0f);
            intPart += 2;
            fracPart += 2;
        }
    }
}
