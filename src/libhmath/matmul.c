#include "common.h"

void func_80089980_main(HuMtx4F, Mtx *);

void func_8008CCC0_main(const HuMtx4F a, const HuMtx4F b, HuMtx4F result) {
    HuMtx4F temp;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

void func_8008CD90_main(Mtx *a, Mtx *b, Mtx *result) {
    HuMtx4F tempA, tempB;

    func_80089980_main(tempA, a);
    func_80089980_main(tempB, b);
    func_8008CCC0_main(tempA, tempB, tempA);
    func_800898F0_main(tempA, result);
}

// Multiply by an affine matrix, preserving the fourth column.
void func_8008CE00_main(const HuMtx4F a, const HuMtx4F b, HuMtx4F result) {
    HuMtx4F temp;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            temp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = temp[i][j];
        }
        result[i][3] = a[i][3];
    }
}

void func_8008CEE0_main(Mtx *a, const HuMtxFixed *b, Mtx *result) {
    HuMtx4F tempA, tempB;
    s32 i, j;
    const u16 *row;

    func_80089980_main(tempA, a);
    row = b->packed;
    for (i = 0; i < 4; row += 4, i++) {
        for (j = 0; j < 3; j++) {
            tempB[i][j] = (s32)(((u32)row[j] << 16) | row[j + 16]) * (1.0f / 65536.0f);
        }
    }
    func_8008CE00_main(tempA, tempB, tempA);
    func_800898F0_main(tempA, result);
}

// Multiply by the upper-left 3x3 matrix, preserving the fourth column.
void func_8008CFA0_main(const HuMtx4F a, const HuMtx4F b, HuMtx4F result) {
    HuMtx4F temp;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            temp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = temp[i][j];
        }
        result[i][3] = a[i][3];
    }
}

void func_8008D070_main(Mtx *a, const HuMtxFixed *b, Mtx *result) {
    HuMtx4F tempA, tempB;
    s32 i, j;
    const u16 *row;

    func_80089980_main(tempA, a);
    row = b->packed;
    for (i = 0; i < 3; row += 4, i++) {
        for (j = 0; j < 3; j++) {
            tempB[i][j] = (s32)(((u32)row[j] << 16) | row[j + 16]) * (1.0f / 65536.0f);
        }
    }
    func_8008CFA0_main(tempA, tempB, tempA);
    func_800898F0_main(tempA, result);
}

// Multiply by a translation-only matrix.
void func_8008D130_main(const HuMtx4F a, const HuMtx4F b, HuMtx4F result) {
    HuMtx4F temp;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            temp[i][j] = a[i][j] + a[i][3] * b[3][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = temp[i][j];
        }
        result[i][3] = a[i][3];
    }
}

void func_8008D1F0_main(Mtx *a, HuMtxFixed *b, Mtx *result) {
    HuMtx4F tempA, tempB;

    func_80089980_main(tempA, a);
    tempB[3][0] = (s32)(((u32)(u16)b->parts.integer[3][0] << 16) | b->parts.fraction[3][0]) * (1.0f / 65536.0f);
    tempB[3][1] = (s32)(((u32)(u16)b->parts.integer[3][1] << 16) | b->parts.fraction[3][1]) * (1.0f / 65536.0f);
    tempB[3][2] = (s32)(((u32)(u16)b->parts.integer[3][2] << 16) | b->parts.fraction[3][2]) * (1.0f / 65536.0f);
    func_8008D130_main(tempA, tempB, tempA);
    func_800898F0_main(tempA, result);
}
