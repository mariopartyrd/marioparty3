#include "common.h"

extern u16 omdispinfo;
extern s16 D_800A1786_main;
extern u8 D_800CD280_main;
extern u16 D_800D530C_main;
extern u16 D_80106500_meschk;

extern void func_800142A0_main(s32);
extern void func_8004DEC8_main(s16);
extern void func_80105B50_meschk(void);
extern void func_80105B8C_meschk(void);
extern void func_80106334_meschk(omObjData *data);
extern void func_80106390_meschk(omObjData *data);
extern void func_801063BC_meschk(void);

void func_801059A0_meschk() {
    omObjData *temp_v0;

    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_main(0x19);
    omInitObjMan(0x33, 10);
    func_8005A6B0_main();
    temp_v0 = omAddObj(0x7FDA, 0, 0, -1, omOutView);
    Center.y = 100.0f;
    CZoom = 600.0f;
    CRot.x = -30.0f;
    omSetStatBit(temp_v0, 0xA0);
    if (omdispinfo != 0) {
        omdispinfo = 0;
        func_8004DEC8_main(D_800A1786_main);
        D_800A1786_main = -1;
    }
    omAddObj(0x2710, 0, 0, -1, func_80106334_meschk);
    HmfLightMaxSet(3);
    HmfLightColorSet(0, 0x78, 0x78, 0x78);
    HmfLightColorSet(1, 0x40, 0x40, 0x60);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    HmfLightColorSet(2, 0, 0, 0);
    HmfLightColorSet(3, 0, 0, 0);
    omAddPrcObj(func_80105B50_meschk, 0x3F00, 0x800, 0);
    omAddPrcObj(func_801063BC_meschk, 0x3F00, 0x800, 0);
    WipeCreateIn(0, 0);
    D_800CD280_main = 1;
    func_8001F38C_main(0xFF, 0xFF, 0xFF);
}

void func_80105B50_meschk() {
    func_80105B8C_meschk();
    D_80106500_meschk = 1;
    func_8005F524_main();
    while (1) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/meschk/4F69F0", func_80105B8C_meschk);

void func_80106334_meschk(omObjData *arg0) {
    if ((D_80106500_meschk != 0) || (D_800D530C_main != 0)) {
        WipeCreateOut(0, 8);
        arg0->func = &func_80106390_meschk;
        HuAudSeqFadeOut(0x3C);
    }
}

void func_80106390_meschk(omObjData *arg0) {
    if (WipeStatGet() == 0) {
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/meschk/4F69F0", func_801063BC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069E0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069E4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069F0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069FC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A04_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A10_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A20_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A34_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A40_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A48_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A50_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A58_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A60_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A6C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A7C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A94_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AA0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AAC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AB8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AC0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AD0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106ADC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AF4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AFC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B04_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B14_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B24_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B34_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B44_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B64_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B6C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B78_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B80_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B94_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BA0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BB0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BBC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BC8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BD0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BE0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BF8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C04_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C10_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C20_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C38_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C40_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C48_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C5C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C64_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C6C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C74_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C80_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C94_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C9C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CAC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CB4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CC4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CD4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CDC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CF4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CFC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D08_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D14_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D20_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D38_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D40_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D4C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D5C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D68_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D74_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D80_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D94_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D9C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DA8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DB8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DC0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DCC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DD8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DE0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DF4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E04_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E0C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E1C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E34_meschk);
