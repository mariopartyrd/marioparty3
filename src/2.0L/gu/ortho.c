#include "common.h"

inline void guOrthoF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale) {
    int i, j;

    guMtxIdentF(mf);

    mf[0][0] = 2 / (r - l);
    mf[1][1] = 2 / (t - b);
    mf[2][2] = -2 / (f - n);
    mf[3][0] = -(r + l) / (r - l);
    mf[3][1] = -(t + b) / (t - b);
    mf[3][2] = -(f + n) / (f - n);
    mf[3][3] = 1;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mf[i][j] *= scale;
}

void guOrtho(Mtx *m, float l, float r, float b, float t, float n, float f, float scale) {
    float mf[4][4];

    // Inlined guOrthoF
    guOrthoF(mf, l, r, b, t, n, f, scale);

    guMtxF2L(mf, m);
}

INCLUDE_RODATA("asm/nonmatchings/2.0L/gu/ortho", D_800A85D8_A91D8);

INCLUDE_RODATA("asm/nonmatchings/2.0L/gu/ortho", D_800A85DC_A91DC);
