#include "common.h"
#include "../ovl_80_shared_board/FA250.h"

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801059A0_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105A68_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105AAC_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105B04_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105C9C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105CD4_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105DEC_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105F9C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801060A4_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80106100_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801066E0_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80106768_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107178_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801072B0_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801072FC_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107358_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107384_last5);

INCLUDE_RODATA("asm/nonmatchings/overlays/last5/3C6310", D_80107510_last5);

INCLUDE_RODATA("asm/nonmatchings/overlays/last5/3C6310", D_80107520_last5);

void func_801073B0_last5(void) {
    s32 sp10[] = { 4, 7, 0xA, 0xD, 0x10, 0x13 };

    Hu3DCamInit(1);
    func_800E6630_shared_board((u32)hvq_data_ROM_START);
    MBBackLoad(sp10[GwSystem.current_board_index]);
    func_800E9344_shared_board(1000.0f, 10000.0f);
}

void func_80107450_last5(void) {
    MBBackKill();
    MBBackClose();
}
