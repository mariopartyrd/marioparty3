#include "common.h"

// Concatenate a float X-axis rotation with a matrix.
void func_8008B6B0_main(const HuMtx4F src, f32 angle, HuMtx4F dst) {
    f32 sine, cosine;

    sincosdf(angle, &sine, &cosine);
    dst[1][0] = src[1][0] * cosine + src[2][0] * sine;
    dst[1][1] = src[1][1] * cosine + src[2][1] * sine;
    dst[1][2] = src[1][2] * cosine + src[2][2] * sine;
    dst[1][3] = src[1][3] * cosine + src[2][3] * sine;
    dst[2][0] = src[2][0] * cosine - src[1][0] * sine;
    dst[2][1] = src[2][1] * cosine - src[1][1] * sine;
    dst[2][2] = src[2][2] * cosine - src[1][2] * sine;
    dst[2][3] = src[2][3] * cosine - src[1][3] * sine;
    dst[0][0] = src[0][0];
    dst[0][1] = src[0][1];
    dst[0][2] = src[0][2];
    dst[0][3] = src[0][3];
    dst[3][0] = src[3][0];
    dst[3][1] = src[3][1];
    dst[3][2] = src[3][2];
    dst[3][3] = src[3][3];
}
