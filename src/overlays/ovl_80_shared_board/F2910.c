#include "common.h"

extern u32 D_800D2094_D2C94;
extern u32 D_80100EE8_114B08_shared_board;

void func_800DECF0_F2910_shared_board(void) {
    if (D_800D2094_D2C94 >= (D_80100EE8_114B08_shared_board + 4)) {
        HuAudFXPlay(0x104);
        D_80100EE8_114B08_shared_board = D_800D2094_D2C94;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DED3C_F295C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF7F4_F3414_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF854_F3474_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF8B4_F34D4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF9EC_F360C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DFAD4_F36F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DFBA8_F37C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E00EC_F3D0C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E00FC_F3D1C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E01DC_F3DFC_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", D_801020B0_115CD0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", D_801020C8_115CE8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", D_801020E0_115D00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0534_F4154_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0A14_F4634_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0A64_F4684_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0C3C_F485C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0C94_F48B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0F84_F4BA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0FE0_F4C00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E11C0_F4DE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E1230_F4E50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E13F0_F5010_shared_board);
