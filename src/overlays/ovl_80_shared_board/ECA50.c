#include "common.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E30_ECA50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E60_ECA80_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E88_ECAA8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8ED4_ECAF4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8F30_ECB50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8F80_ECBA0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8FC4_ECBE4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9004_ECC24_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D90C8_ECCE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D912C_ECD4C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D93C0_ECFE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D95C4_ED1E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D95D0_ED1F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9714_ED334_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D975C_ED37C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9A40_ED660_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9A50_ED670_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9AA4_ED6C4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9AD0_ED6F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9B24_ED744_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9B54_ED774_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9CB0_ED8D0_shared_board);

void func_800D9CE8_ED908_shared_board(Object* arg0, s16 arg1, s32 arg2) {
    u16 var_v1;

    if (arg1 == -1) {
        var_v1 = arg0->unk44;
        arg0->unk46 = arg1;
    } else {
        var_v1 = arg0->unk3C->motion[arg1];
        arg0->unk46 = arg1;
    }
    func_8001F304_1FF04(arg0->unk3C->model[0], var_v1);
    func_8001C814_1D414(arg0->unk3C->model[0], -1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9D84_ED9A4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9E0C_EDA2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9E80_EDAA0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9ED0_EDAF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9F5C_EDB7C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800DA09C_EDCBC_shared_board);
