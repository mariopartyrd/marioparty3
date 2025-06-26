#include "common.h"

void func_80105B64_3D7884_sldebug(omObjData*);      /* extern */
void func_80106254_3D7F74_sldebug(omObjData*);      /* extern */
void func_80106850_3D8570_sldebug(void);                   /* extern */
void func_801068D4_3D85F4_sldebug(omObjData*);      /* extern */
extern Vec D_80106C10_3D8930_sldebug;
extern f32 D_80106C1C_3D893C_sldebug;
extern Vec D_80106C2C_3D894C_sldebug;

void func_801059A0_3D76C0_sldebug(void) {
    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_14EA0(0x2D);
    omInitObjMan(0x33, 0xA);
    func_8004A208_4AE08();
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, omOutView), 0xA0U);
    omAddObj(0x2710, 0U, 0U, -1, func_801068D4_3D85F4_sldebug);
    HmfLightMaxSet(4);
    HmfLightColorSet(0, 0x78, 0x78, 0x78);
    HmfLightColorSet(1, 0x40, 0x40, 0x60);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    HmfLightColorSet(2, 0, 0, 0);
    HmfLightColorSet(3, 0, 0, 0);
    D_80106C10_3D8930_sldebug.x = D_80106C10_3D8930_sldebug.y = D_80106C10_3D8930_sldebug.z = 0.0f;
    D_80106C1C_3D893C_sldebug = 400.0f;
    D_80106C2C_3D894C_sldebug.x = D_80106C2C_3D894C_sldebug.z = 0.0f;
    D_80106C2C_3D894C_sldebug.y = 150.0f;
    gCameraList->fov[0] = 45.0f;
    func_80106850_3D8570_sldebug();
    omAddObj(0x7D0, 0xAU, 0xAU, -1, func_80105B64_3D7884_sldebug);
    omAddObj(0x7D0, 0U, 0U, -1, func_80106254_3D7F74_sldebug);
    WipeCreateIn(0, 0x10);
    D_800CD280_CDE80 = 1;
    func_80050ABC_516BC();
    HuAudSeqPlay(8);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106990_3D86B0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_8010699C_3D86BC_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069A8_3D86C8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069B4_3D86D4_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069C0_3D86E0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069CC_3D86EC_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069D8_3D86F8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069E4_3D8704_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069F0_3D8710_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069FC_3D871C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A08_3D8728_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A14_3D8734_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A20_3D8740_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A2C_3D874C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A60_3D8780_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A74_3D8794_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A88_3D87A8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A9C_3D87BC_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AB0_3D87D0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AC4_3D87E4_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AD8_3D87F8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AF0_3D8810_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B04_3D8824_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B18_3D8838_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B2C_3D884C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B44_3D8864_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80105B64_3D7884_sldebug);

void func_80106124_3D7E44_sldebug(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_8010612C_3D7E4C_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106254_3D7F74_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106850_3D8570_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_801068D4_3D85F4_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106930_3D8650_sldebug);
