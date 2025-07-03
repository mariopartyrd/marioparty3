#include "common.h"
#include "../ovl_81_name/ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801059A0_460790_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105B3C_46092C_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105CBC_460AAC_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105E20_460C10_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80105FE8_460DD8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106070_460E60_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801061C4_460FB4_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106294_461084_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106350_461140_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801066B8_4614A8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106CB4_461AA4_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_801094F0_4642E0_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80106D18_461B08_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80108FDC_463DCC_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_80109050_463E40_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801090AC_463E9C_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801090F8_463EE8_opduel);

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_8010911C_463F0C_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109508_4642F8_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109528_464318_opduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/opduel/460790", D_80109548_464338_opduel);

void func_80109158_463F48_opduel(void) {
    s32 sp10[] = {0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D};

    Hu3DCamInit(1);
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    func_800E52DC_CD0AC_name_81(sp10[GwSystem.current_board_index]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/opduel/460790", func_801091DC_463FCC_opduel);
