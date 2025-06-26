#include "common.h"
#include "../ovl_81_name/ovl_81.h"

void func_801060D0_54E440_storyresult(Vec*);
void func_8010818C_5504FC_storyresult(s16*, s32);
extern s16 D_8010A910_552C80_storyresult;
extern s16 D_8010A912_552C82_storyresult;
extern s16 D_8010A914_552C84_storyresult;
extern Vec D_8010AB9C_552F0C_storyresult[];
extern s16 D_8010AC28_552F98_storyresult;
extern s16 D_8010AC2A_552F9A_storyresult;

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801059A0_54DD10_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105C30_54DFA0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105CF8_54E068_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105DEC_54E15C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105EA0_54E210_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80105F7C_54E2EC_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106050_54E3C0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106078_54E3E8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801060D0_54E440_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106190_54E500_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106754_54EAC4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106780_54EAF0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106C84_54EFF4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106E48_54F1B8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80106FF0_54F360_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107030_54F3A0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801070D8_54F448_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107140_54F4B0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107204_54F574_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80107920_54FC90_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010818C_5504FC_storyresult);

void func_8010822C_55059C_storyresult(void) {
    s16 sp10;

    D_800CD280_CDE80 = 0;
    func_801060D0_54E440_storyresult(&D_8010AB9C_552F0C_storyresult[0]);
    D_8010A912_552C82_storyresult = 1;
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    func_800E52DC_CD0AC_name_81(0x20);
    func_800E8180_CFF50_name_81(1000.0f, 10000.0f);
    D_8010AC2A_552F9A_storyresult = 0xB;
    WipeCreateIn(0xB, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    func_8010818C_5504FC_storyresult(&sp10, -1);
    while (sp10 >= -1) {
        HuPrcVSleep();
    }
    D_8010AC2A_552F9A_storyresult = 0xB;
    D_8010AC28_552F98_storyresult = 0x36;
    D_8010A914_552C84_storyresult = 2;
    D_8010A910_552C80_storyresult = 1;

    while (1) {
        HuPrcVSleep();    
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010832C_55069C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801083A4_550714_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801085E8_550958_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_801086E4_550A54_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108884_550BF4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108AC0_550E30_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108CB8_551028_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108D04_551074_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108D34_5510A4_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_80108F0C_55127C_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A370_5526E0_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A4A4_552814_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A558_5528C8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A5C4_552934_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A738_552AA8_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A7B0_552B20_storyresult);

INCLUDE_ASM("asm/nonmatchings/overlays/storyresult/54DD10", func_8010A7EC_552B5C_storyresult);
