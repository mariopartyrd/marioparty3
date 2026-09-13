#include "common.h"

typedef struct UnkTemp { // is this just a copy of PlayerResult ?
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
} UnkTemp; // sizeof 0xC

extern UnkTemp D_8010AFB0_mgresultboard[];

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80107D00_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801080C4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108150_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801081CC_mgresultboard);

void func_801081E8_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801081F0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108250_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108330_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108700_mgresultboard);

void func_80108BBC_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108BC4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80108C60_mgresultboard);

void func_8010913C_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109144_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801092E0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109498_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109650_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_801096E0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109744_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109878_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109A90_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109CB0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109D44_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109DAC_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_80109F30_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E9120", D_8010AD58_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A000_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A334_mgresultboard);

void func_8010A350_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A358_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A3E4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A454_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E9120", func_8010A4A0_mgresultboard);

s32 func_8010A864_mgresultboard(omObjData *arg0, s8 arg1, s8 arg2) {
    if (D_8010AFB0_mgresultboard[arg1].unk_04 >= 0) {
        return 0;
    }

    D_8010AFB0_mgresultboard[arg1].unk_04 = arg2;

    if (D_8010AFB0_mgresultboard[arg1].unk_08 >= 0) {
        func_8001C258_main(arg0->model[D_8010AFB0_mgresultboard[arg1].unk_08 + 1], 4, 0);
    }

    D_8010AFB0_mgresultboard[arg1].unk_00 = 1;
    return 1;
}
