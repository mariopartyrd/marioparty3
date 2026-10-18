#include "common.h"

// Apply scale to a fixed-point matrix.
void func_8008CB90_main(Mtx *src, f32 *scale, Mtx *dst) {
    HuMtx4F temp;

    func_80089980_main(temp, src);
    func_8008CB30_main(temp, scale, temp);
    func_800898F0_main(temp, dst);
}
