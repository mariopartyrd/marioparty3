#include "common.h"

extern u16 omdispinfo;
extern s16 D_800A1786_A2386;
extern u8 D_800CD280_CDE80;
extern u16 D_800D530C_D5F0C;
extern u16 D_80106500_4F7550_meschk;

extern void func_800142A0_14EA0(s32);
extern void func_8004DEC8_4EAC8(s16);
extern void func_80105B50_4F6BA0_meschk(void);
extern void func_80105B8C_4F6BDC_meschk(void);
extern void func_80106334_4F7384_meschk(omObjData *data);
extern void func_80106390_4F73E0_meschk(omObjData *data);
extern void func_801063BC_4F740C_meschk(void);

void func_801059A0_4F69F0_meschk() {
    omObjData *temp_v0;

    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_14EA0(0x19);
    omInitObjMan(0x33, 10);
    func_8005A6B0_5B2B0();
    temp_v0 = omAddObj(0x7FDA, 0, 0, -1, omOutView);
    Center.y = 100.0f;
    CZoom = 600.0f;
    CRot.x = -30.0f;
    omSetStatBit(temp_v0, 0xA0);
    if (omdispinfo != 0) {
        omdispinfo = 0;
        func_8004DEC8_4EAC8(D_800A1786_A2386);
        D_800A1786_A2386 = -1;
    }
    omAddObj(0x2710, 0, 0, -1, func_80106334_4F7384_meschk);
    HmfLightMaxSet(3);
    HmfLightColorSet(0, 0x78, 0x78, 0x78);
    HmfLightColorSet(1, 0x40, 0x40, 0x60);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    HmfLightColorSet(2, 0, 0, 0);
    HmfLightColorSet(3, 0, 0, 0);
    omAddPrcObj(func_80105B50_4F6BA0_meschk, 0x3F00, 0x800, 0);
    omAddPrcObj(func_801063BC_4F740C_meschk, 0x3F00, 0x800, 0);
    WipeCreateIn(0, 0);
    D_800CD280_CDE80 = 1;
    func_8001F38C_1FF8C(0xFF, 0xFF, 0xFF);
}

void func_80105B50_4F6BA0_meschk() {
    func_80105B8C_4F6BDC_meschk();
    D_80106500_4F7550_meschk = 1;
    func_8005F524_60124();
    while (1) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/meschk/4F69F0", func_80105B8C_4F6BDC_meschk);

void func_80106334_4F7384_meschk(omObjData *arg0) {
    if ((D_80106500_4F7550_meschk != 0) || (D_800D530C_D5F0C != 0)) {
        WipeCreateOut(0, 8);
        arg0->func = &func_80106390_4F73E0_meschk;
        HuAudSeqFadeOut(0x3C);
    }
}

void func_80106390_4F73E0_meschk(omObjData *arg0) {
    if (WipeStatGet() == 0) {
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/meschk/4F69F0", func_801063BC_4F740C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069E0_4F7A30_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069E4_4F7A34_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069F0_4F7A40_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_801069FC_4F7A4C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A04_4F7A54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A10_4F7A60_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A20_4F7A70_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A2C_4F7A7C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A34_4F7A84_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A40_4F7A90_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A48_4F7A98_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A50_4F7AA0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A58_4F7AA8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A60_4F7AB0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A6C_4F7ABC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A7C_4F7ACC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A88_4F7AD8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106A94_4F7AE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AA0_4F7AF0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AAC_4F7AFC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AB8_4F7B08_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AC0_4F7B10_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AD0_4F7B20_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106ADC_4F7B2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AE4_4F7B34_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AEC_4F7B3C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AF4_4F7B44_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106AFC_4F7B4C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B04_4F7B54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B14_4F7B64_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B24_4F7B74_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B34_4F7B84_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B44_4F7B94_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B54_4F7BA4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B64_4F7BB4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B6C_4F7BBC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B78_4F7BC8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B80_4F7BD0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B88_4F7BD8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106B94_4F7BE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BA0_4F7BF0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BB0_4F7C00_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BBC_4F7C0C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BC8_4F7C18_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BD0_4F7C20_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BE0_4F7C30_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BEC_4F7C3C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106BF8_4F7C48_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C04_4F7C54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C10_4F7C60_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C20_4F7C70_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C2C_4F7C7C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C38_4F7C88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C40_4F7C90_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C48_4F7C98_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C54_4F7CA4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C5C_4F7CAC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C64_4F7CB4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C6C_4F7CBC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C74_4F7CC4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C80_4F7CD0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C88_4F7CD8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C94_4F7CE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106C9C_4F7CEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CAC_4F7CFC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CB4_4F7D04_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CC4_4F7D14_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CD4_4F7D24_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CDC_4F7D2C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CE4_4F7D34_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CEC_4F7D3C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CF4_4F7D44_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106CFC_4F7D4C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D08_4F7D58_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D14_4F7D64_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D20_4F7D70_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D2C_4F7D7C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D38_4F7D88_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D40_4F7D90_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D4C_4F7D9C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D54_4F7DA4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D5C_4F7DAC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D68_4F7DB8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D74_4F7DC4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D80_4F7DD0_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D88_4F7DD8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D94_4F7DE4_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106D9C_4F7DEC_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DA8_4F7DF8_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DB8_4F7E08_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DC0_4F7E10_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DCC_4F7E1C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DD8_4F7E28_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DE0_4F7E30_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DEC_4F7E3C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106DF4_4F7E44_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E04_4F7E54_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E0C_4F7E5C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E1C_4F7E6C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E2C_4F7E7C_meschk);

INCLUDE_RODATA("asm/nonmatchings/overlays/meschk/4F69F0", D_80106E34_4F7E84_meschk);
