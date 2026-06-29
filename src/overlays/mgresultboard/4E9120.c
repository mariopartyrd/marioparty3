#include "common.h"

typedef struct UnkTemp { // is this just a copy of PlayerResult ?
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
} UnkTemp; // sizeof 0xC

extern UnkTemp D_8010AFB0_4EC3D0_mgresultboard[];

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80107D00_4E9120_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801080C4_4E94E4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108150_4E9570_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801081CC_4E95EC_mgresultboard);

void func_801081E8_4E9608_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801081F0_4E9610_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108250_4E9670_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108330_4E9750_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108700_4E9B20_mgresultboard);

void func_80108BBC_4E9FDC_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108BC4_4E9FE4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108C60_4EA080_mgresultboard);

void func_8010913C_4EA55C_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109144_4EA564_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801092E0_4EA700_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109498_4EA8B8_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109650_4EAA70_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801096E0_4EAB00_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109744_4EAB64_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109878_4EAC98_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109A90_4EAEB0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109CB0_4EB0D0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109D44_4EB164_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109DAC_4EB1CC_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109F30_4EB350_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E9120", D_8010AD58_4EC178_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A000_4EB420_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A334_4EB754_mgresultboard);

void func_8010A350_4EB770_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A358_4EB778_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A3E4_4EB804_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A454_4EB874_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A4A0_4EB8C0_mgresultboard);

s32 func_8010A864_4EBC84_mgresultboard(omObjData *arg0, s8 arg1, s8 arg2) {
    if (D_8010AFB0_4EC3D0_mgresultboard[arg1].unk_04 >= 0) {
        return 0;
    }

    D_8010AFB0_4EC3D0_mgresultboard[arg1].unk_04 = arg2;

    if (D_8010AFB0_4EC3D0_mgresultboard[arg1].unk_08 >= 0) {
        func_8001C258_1CE58(arg0->model[D_8010AFB0_4EC3D0_mgresultboard[arg1].unk_08 + 1], 4, 0);
    }

    D_8010AFB0_4EC3D0_mgresultboard[arg1].unk_00 = 1;
    return 1;
}
