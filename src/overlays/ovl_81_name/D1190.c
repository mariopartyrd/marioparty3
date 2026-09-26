#include "common.h"
#include "ovl_81.h"

extern SpaceData* D_801050A4_name_81;
extern LinkData* D_801050A8_name_81;

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E93C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9468_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E94D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9524_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9530_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9564_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9580_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E95B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E95C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9B00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9B10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9D9C_name_81);

SpaceData* MBDMasuGet(s16 spaceIdx) {
    return &D_801050A4_name_81[spaceIdx];
}

s16 MBDMasuLinkMasuIdGet(u16 linkIdx, u16 spaceIdx) {
    return D_801050A8_name_81[linkIdx].spaces[spaceIdx];
}

s16 MBDMasuLinkNumGet(u16 linkIdx) {
    return D_801050A8_name_81[linkIdx].chainIndicies;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9ECC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800E9F4C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA010_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA0C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA1FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA22C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA2C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA388_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA3CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA46C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA4D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA68C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA698_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA6A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA6B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA708_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA760_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA788_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA7D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA848_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA898_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA8DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA940_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EA97C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EAA7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D1190", func_800EAAF8_name_81);
