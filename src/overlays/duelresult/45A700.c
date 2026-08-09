#include "common.h"

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010ABE0_45A700_duelresult);

// Work area allocated by func_8010ABE0 and stored at the process's user_data
// (see Process.user_data). Total size is 0x4C; fields are added as functions
// are decompiled.
typedef struct DuelResultWork {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0x40];
} DuelResultWork; // sizeof 0x4C

void func_8010AC6C_45A78C_duelresult(DuelResultWork *arg0, u32 arg1) {
    arg0->unk_00 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010AC74_45A794_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010AC84_45A7A4_duelresult);

void func_8010AC94_45A7B4_duelresult(DuelResultWork *arg0, s16 arg1) {
    arg0->unk_0A = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010AC9C_45A7BC_duelresult);

s16 func_8010ACB4_45A7D4_duelresult(DuelResultWork *arg0) {
    return arg0->unk_04;
}

void func_8010ACBC_45A7DC_duelresult(DuelResultWork *arg0, s16 arg1) {
    arg0->unk_06 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010ACC4_45A7E4_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010BDA4_45B8C4_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010C13C_45BC5C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010C21C_45BD3C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010C72C_45C24C_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010C880_45C3A0_duelresult);

INCLUDE_ASM("asm/nonmatchings/overlays/duelresult/45A700", func_8010C8E0_45C400_duelresult);
