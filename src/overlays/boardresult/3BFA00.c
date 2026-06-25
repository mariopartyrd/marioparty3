#include "common.h"

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BD30_3BFA00_boardresult);

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

void func_8010BDBC_3BFA8C_boardresult(BoardResultWork *arg0, s32 arg1) {
    arg0->unk_00 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDC4_3BFA94_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDD4_3BFAA4_boardresult);

void func_8010BDE4_3BFAB4_boardresult(BoardResultWork *arg0, s16 arg1) {
    arg0->unk_0A = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BDEC_3BFABC_boardresult);

s16 func_8010BE04_3BFAD4_boardresult(BoardResultWork *arg0) {
    return arg0->unk_04;
}

void func_8010BE0C_3BFADC_boardresult(BoardResultWork *arg0, s16 arg1) {
    arg0->unk_06 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010BE14_3BFAE4_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010CEF4_3C0BC4_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D28C_3C0F5C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D36C_3C103C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D87C_3C154C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010D9D0_3C16A0_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3BFA00", func_8010DA30_3C1700_boardresult);
