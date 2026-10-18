#include "common.h"

// Builds a fixed-point perspective matrix from field-of-view and clip parameters.
void func_80088520_main(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    HuMtx4F temp;

    func_8008D2C0_main(temp, perspNorm, fovy, aspect, near, far, scale);
    func_800898F0_main(temp, m);
}
