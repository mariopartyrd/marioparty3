#include "common.h"

// Apply translation to a fixed-point matrix.
void func_8008CC60_main(Mtx *src, f32 *translation, Mtx *dst) {
    HuMtx4F temp;

    func_80089980_main(temp, src);
    func_8008CBF0_main(temp, translation, temp);
    func_800898F0_main(temp, dst);
}
