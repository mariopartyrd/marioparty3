#include "common.h"

// Apply scale to a float matrix.
void func_8008CB30_main(HuMtx4F src, f32 *scale, HuMtx4F dst) {
    // Initialize before loading the vector to preserve instruction order.
    s32 i = 0;
    f32 x, y, z;
    f32 sx, sy, sz;

    sx = scale[0];
    sy = scale[1];
    sz = scale[2];
    for (; i < 4; i++) {
        x = src[i][0] * sx;
        y = src[i][1] * sy;
        z = src[i][2] * sz;
        dst[i][3] = src[i][3];
        dst[i][0] = x;
        dst[i][1] = y;
        dst[i][2] = z;
    }
}
