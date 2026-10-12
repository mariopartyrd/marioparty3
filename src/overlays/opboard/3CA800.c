#include "common.h"
#include "../ovl_80_shared_board/FA250.h"

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801059A0_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80105AE0_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80105C60_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80105DC4_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80105F8C_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80106014_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801060A8_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801061FC_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801062CC_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80106388_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801066F0_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80106CFC_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_801071F4_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_8010727C_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80107580_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80107E28_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80107E58_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80108B3C_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80108BB0_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80108C0C_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80108C58_opboard);

INCLUDE_ASM("asm/nonmatchings/overlays/opboard/3CA800", func_80108C8C_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108F80_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108F98_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108FB0_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108FC0_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108FD8_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80108FF0_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80109008_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80109020_opboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboard/3CA800", D_80109038_opboard);

void func_80108CC0_opboard(void) {
    s32 sp10[] = { 3, 6, 9, 0xC, 0xF, 0x12 };

    Hu3DCamInit(1);
    func_800E6630_shared_board((u32)hvq_data_ROM_START);
    MBBackLoad(sp10[GwSystem.current_board_index]);
}

void func_80108D44_opboard() {
    MBBackKill();
    MBBackClose();
}
