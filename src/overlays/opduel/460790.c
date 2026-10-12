#include "common.h"
#include "../ovl_81_name/ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801059A0_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105B3C_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105CBC_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105E20_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105FE8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106070_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801061C4_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106294_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106350_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801066B8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106CB4_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_801094F0_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106D18_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80108FDC_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80109050_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801090AC_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801090F8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_8010911C_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109508_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109528_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109548_opduel);

void func_80109158_opduel(void) {
    s32 sp10[] = { 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };

    Hu3DCamInit(1);
    func_800E4F50_name_81(hvq_data_ROM_START);
    MBDBackLoad(sp10[GwSystem.current_board_index]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801091DC_opduel);
