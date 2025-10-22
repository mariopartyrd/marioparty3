#include "common.h"

void HuVecNormalize3F(Vec*);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8790_EC3B0_shared_board);

void HuVecNormalizeSafe3F(Vec* vec) {
    if ((vec->x == 0.0f) && (vec->y == 0.0f) && (vec->z == 0.0f)) {
        vec->z = 1.0f;
    }
    
    HuVecNormalize3F(vec);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8958_EC578_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D89F4_EC614_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8A90_EC6B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8B2C_EC74C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EC3B0", func_800D8DAC_EC9CC_shared_board);
