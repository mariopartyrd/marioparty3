#include "common.h"

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BD30_boardresult);

// Work area allocated by func_8010BD30 (HuMemAllocTag 0x4C bytes) and stored at
// the process object's user_data (offset 0x8C). Total size is 0x4C; fields are
// added as functions are decompiled.
typedef struct BoardResultWork {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0x40];
} BoardResultWork; // sizeof 0x4C

void func_8010BDBC_boardresult(BoardResultWork *arg0, s32 arg1) {
    arg0->unk_00 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDC4_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDD4_boardresult);

void func_8010BDE4_boardresult(BoardResultWork *arg0, s16 arg1) {
    arg0->unk_0A = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDEC_boardresult);

s16 func_8010BE04_boardresult(BoardResultWork *arg0) {
    return arg0->unk_04;
}

void func_8010BE0C_boardresult(BoardResultWork *arg0, s16 arg1) {
    arg0->unk_06 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BE14_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010CEF4_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D28C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D36C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D87C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D9D0_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010DA30_boardresult);
