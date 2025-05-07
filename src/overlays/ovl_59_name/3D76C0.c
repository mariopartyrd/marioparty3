#include "common.h"

void func_80105B64_3D7884_name_59(omObjData*);      /* extern */
void func_80106254_3D7F74_name_59(omObjData*);      /* extern */
void func_80106850_3D8570_name_59(void);                   /* extern */
void func_801068D4_3D85F4_name_59(omObjData*);      /* extern */
extern Vec D_80106C10_3D8930_name_59;
extern f32 D_80106C1C_3D893C_name_59;
extern Vec D_80106C2C_3D894C_name_59;

void func_801059A0_3D76C0_name_59(void) {
    Hu3DCamInit(1);
    Hu3DAnimInit(1);
    func_800142A0_14EA0(0x2D);
    omInitObjMan(0x33, 0xA);
    func_8004A208_4AE08();
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, func_8004B340_4BF40), 0xA0U);
    omAddObj(0x2710, 0U, 0U, -1, func_801068D4_3D85F4_name_59);
    HmfLightMaxSet(4);
    HmfLightColorSet(0, 0x78, 0x78, 0x78);
    HmfLightColorSet(1, 0x40, 0x40, 0x60);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    HmfLightColorSet(2, 0, 0, 0);
    HmfLightColorSet(3, 0, 0, 0);
    D_80106C10_3D8930_name_59.x = D_80106C10_3D8930_name_59.y = D_80106C10_3D8930_name_59.z = 0.0f;
    D_80106C1C_3D893C_name_59 = 400.0f;
    D_80106C2C_3D894C_name_59.x = D_80106C2C_3D894C_name_59.z = 0.0f;
    D_80106C2C_3D894C_name_59.y = 150.0f;
    gCameraList->fov = 45.0f;
    func_80106850_3D8570_name_59();
    omAddObj(0x7D0, 0xAU, 0xAU, -1, func_80105B64_3D7884_name_59);
    omAddObj(0x7D0, 0U, 0U, -1, func_80106254_3D7F74_name_59);
    WipeCreateIn(0, 0x10);
    D_800CD280_CDE80 = 1;
    func_80050ABC_516BC();
    HuAudSeqPlay(8);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106990_3D86B0_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_8010699C_3D86BC_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069A8_3D86C8_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069B4_3D86D4_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069C0_3D86E0_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069CC_3D86EC_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069D8_3D86F8_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069E4_3D8704_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069F0_3D8710_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_801069FC_3D871C_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A08_3D8728_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A14_3D8734_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A20_3D8740_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A2C_3D874C_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A60_3D8780_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A74_3D8794_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A88_3D87A8_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106A9C_3D87BC_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106AB0_3D87D0_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106AC4_3D87E4_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106AD8_3D87F8_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106AF0_3D8810_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106B04_3D8824_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106B18_3D8838_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106B2C_3D884C_name_59);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_59_name/3D76C0", D_80106B44_3D8864_name_59);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_80105B64_3D7884_name_59);

void func_80106124_3D7E44_name_59(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_8010612C_3D7E4C_name_59);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_80106254_3D7F74_name_59);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_80106850_3D8570_name_59);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_801068D4_3D85F4_name_59);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_name/3D76C0", func_80106930_3D8650_name_59);
