#include "common.h"

// Apply translation to a float matrix.
void func_8008CBF0_main(const HuMtx4F src, f32 *translation, HuMtx4F dst) {
    // Initialize before loading the vector to preserve instruction order.
    s32 i = 0;
    f32 x, y, z, w;
    f32 tx, ty, tz;

    tx = translation[0];
    ty = translation[1];
    tz = translation[2];
    for (; i < 4; i++) {
        w = src[i][3];
        x = src[i][0] + w * tx;
        y = src[i][1] + w * ty;
        z = src[i][2] + w * tz;
        dst[i][3] = w;
        dst[i][0] = x;
        dst[i][1] = y;
        dst[i][2] = z;
    }
}
