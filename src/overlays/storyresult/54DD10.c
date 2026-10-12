#include "common.h"
#include "../ovl_81_name/ovl_81.h"

void func_801060D0_storyresult(Vec *);
void func_8010818C_storyresult(s16 *, s32);
extern s16 D_8010A910_storyresult;
extern s16 D_8010A912_storyresult;
extern s16 D_8010A914_storyresult;
extern Vec D_8010AB9C_storyresult[];
extern s16 D_8010AC28_storyresult;
extern s16 D_8010AC2A_storyresult;

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801059A0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105C30_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105CF8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105DEC_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105EA0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105F7C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106050_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106078_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801060D0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106190_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106754_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106780_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106C84_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106E48_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106FF0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107030_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801070D8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107140_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107204_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107920_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010818C_storyresult);

void func_8010822C_storyresult(void) {
    s16 sp10;

    D_800CD280_main = 0;
    func_801060D0_storyresult(&D_8010AB9C_storyresult[0]);
    D_8010A912_storyresult = 1;
    func_800E4F50_name_81(hvq_data_ROM_START);
    MBDBackLoad(0x20);
    func_800E8180_name_81(1000.0f, 10000.0f);
    D_8010AC2A_storyresult = 0xB;
    WipeCreateIn(0xB, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    func_8010818C_storyresult(&sp10, -1);
    while (sp10 >= -1) {
        HuPrcVSleep();
    }
    D_8010AC2A_storyresult = 0xB;
    D_8010AC28_storyresult = 0x36;
    D_8010A914_storyresult = 2;
    D_8010A910_storyresult = 1;

    while (1) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010832C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801083A4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801085E8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801086E4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108884_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108AC0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108CB8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108D04_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108D34_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108F0C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A370_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A4A4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A558_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A5C4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A738_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A7B0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A7EC_storyresult);
