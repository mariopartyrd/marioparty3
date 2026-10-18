#include "common.h"

// Build a fixed-point look-at matrix.
void func_80089FF0_main(Mtx *mtx, Vec *camera) {
    HuMtx4F temp;
    Vec basis[3];

    func_8008D450_main(temp, camera, basis);
    func_800898F0_main(temp, mtx);
}
