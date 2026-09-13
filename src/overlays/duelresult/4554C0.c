#include "common.h"
#include "../ovl_81_name/ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_801059A0_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80105B60_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80105BD0_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80106800_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010690C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_801069DC_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80106A24_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80106C4C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80106D48_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80106EF8_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010709C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010753C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107644_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107A58_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107AF4_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107BC0_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107E7C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80107F3C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80108138_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_80108174_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_801082C0_duelresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/duelresult/4554C0", D_8010D7F0_duelresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/duelresult/4554C0", D_8010D810_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010856C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010A938_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010A978_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/4554C0", func_8010AA9C_duelresult);

void func_8010AAE8_duelresult() {
    func_800D7EB8_name_81();
    func_800F3F4C_name_81();
    func_800EF840_name_81();
    func_800F4300_name_81();
}

void func_8010AB1C_duelresult() {
    func_800F4314_name_81();
    func_800EF880_name_81();
    func_800F4030_name_81();
    func_800D7F0C_name_81();
}

void func_8010AB50_duelresult(void) {
    Hu3DCamInit(1);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    func_800E4F50_name_81(hvq_data_ROM_START);
    MBDBackLoad(0);
    func_800E8180_name_81(1000.0f, 10000.0f);
}

void func_8010ABB0_duelresult() {
    MBDBackKill();
    MBDBackClose();
}

INCLUDE_RODATA("asm/nonmatchings/overlays/duelresult/4554C0", D_8010D83C_duelresult);
