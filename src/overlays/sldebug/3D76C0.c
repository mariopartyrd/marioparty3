#include "common.h"

void func_80105B64_sldebug(omObjData *); /* extern */
void func_80106254_sldebug(omObjData *); /* extern */
void func_80106850_sldebug(void);        /* extern */
void func_801068D4_sldebug(omObjData *); /* extern */
extern Vec D_80106C10_sldebug;
extern f32 D_80106C1C_sldebug;
extern Vec D_80106C2C_sldebug;

void func_801059A0_sldebug(void) {
    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_main(0x2D);
    omInitObjMan(0x33, 0xA);
    func_8004A208_main();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0U);
    omAddObj(0x2710, 0, 0, -1, func_801068D4_sldebug);
    HmfLightMaxSet(4);
    HmfLightColorSet(0, 0x78, 0x78, 0x78);
    HmfLightColorSet(1, 0x40, 0x40, 0x60);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    HmfLightColorSet(2, 0, 0, 0);
    HmfLightColorSet(3, 0, 0, 0);
    D_80106C10_sldebug.x = D_80106C10_sldebug.y = D_80106C10_sldebug.z = 0.0f;
    D_80106C1C_sldebug = 400.0f;
    D_80106C2C_sldebug.x = D_80106C2C_sldebug.z = 0.0f;
    D_80106C2C_sldebug.y = 150.0f;
    gCameraList->fov[0] = 45.0f;
    func_80106850_sldebug();
    omAddObj(0x7D0, 0xA, 0xA, -1, func_80105B64_sldebug);
    omAddObj(0x7D0, 0, 0, -1, func_80106254_sldebug);
    WipeCreateIn(0, 0x10);
    D_800CD280_main = 1;
    func_80050ABC_main();
    HuAudSeqPlay(8);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106990_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_8010699C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069A8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069B4_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069C0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069CC_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069D8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069E4_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069F0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_801069FC_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A08_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A14_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A20_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A2C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A60_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A74_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A88_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106A9C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AB0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AC4_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AD8_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106AF0_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B04_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B18_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B2C_sldebug);

INCLUDE_RODATA("asm/nonmatchings/overlays/sldebug/3D76C0", D_80106B44_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80105B64_sldebug);

void func_80106124_sldebug(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_8010612C_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106254_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106850_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_801068D4_sldebug);

INCLUDE_ASM("asm/nonmatchings/overlays/sldebug/3D76C0", func_80106930_sldebug);
