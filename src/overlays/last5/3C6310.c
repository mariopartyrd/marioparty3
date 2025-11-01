#include "common.h"
#include "../ovl_80_shared_board/ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801059A0_3C6310_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105A68_3C63D8_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105AAC_3C641C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105B04_3C6474_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105C9C_3C660C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105CD4_3C6644_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105DEC_3C675C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80105F9C_3C690C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801060A4_3C6A14_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80106100_3C6A70_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801066E0_3C7050_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80106768_3C70D8_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107178_3C7AE8_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801072B0_3C7C20_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_801072FC_3C7C6C_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107358_3C7CC8_last5);

INCLUDE_ASM("asm/nonmatchings/overlays/last5/3C6310", func_80107384_3C7CF4_last5);

INCLUDE_RODATA("asm/nonmatchings/overlays/last5/3C6310", D_80107510_3C7E80_last5);

INCLUDE_RODATA("asm/nonmatchings/overlays/last5/3C6310", D_80107520_3C7E90_last5);

s32 func_801073B0_3C7D20_last5(void) {
    s32 sp10[] = {4, 7, 0xA, 0xD, 0x10, 0x13};

    Hu3DCamInit(1);
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    MBBackKill(sp10[GwSystem.current_board_index]);
    return func_800E9344_FCF64_shared_board(1000.0f, 10000.0f);
}

void func_80107450_3C7DC0_last5(void) {
    func_800E69D8_FA5F8_shared_board();
    MBBackClose();
}
