#include "common.h"

// Build a fixed-point perspective matrix.
void func_8008A030_main(Mtx *mtx, u16 *perspNorm, PerspectiveParams *params) {
    HuMtx4F temp;

    func_8008D5D0_main(temp, perspNorm, params);
    func_800898F0_main(temp, mtx);
}
