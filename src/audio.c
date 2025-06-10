#include "game/audio.h"
#include "common.h" // TODO: remove.

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ char unk0C[0x1D];
} UnkAudStruct; // Size unknown (min: 0x29, max: 0x30)

void func_8000086C_146C(str800D5298*);
s16 func_80003310_3F10(s16);
void func_800035E8_41E8(s16);
void func_800039A4_45A4(s16, s16);
s32 func_80007064_7C64(s32);
s32 func_80007080_7C80(s16, UnkAudStruct*);
void func_80007BD4_87D4(s16, s16);
void func_80007DD8_89D8(s16);
void func_8005A674_5B274(s32, s16, s16, s16); // window

extern u8 D_800D09A8_D15A8;
extern str800D5298 D_800D5298_D5E98;
extern s32 D_800D52C0_D5EC0;

u16 D_800A1900_A2500 = 1;
u16 D_800A1902_A2502 = 1;
s16 D_800A1904_A2504 = -1; // active musId
u16 D_800A1906_A2506 = 1; // stat/attr
s16 D_800A1908_A2508 = 0;
s16 D_800A190A_A250A = 0;
s16 D_800A190C_A250C = 1;
s16 D_800A190E_A250E = 1;
s16 D_800A1910_A2510[8] = { 0x0040 }; // single s16 + padding?

// TODO: this only matches if D_800CDBC8_CE7C8 is declared as an s16. D_800CDBC8 BSS?
/*
s16 HuAudSeqPlay(s16 musId) {
    if (D_800A1900_A2500 == 0) {
        return 0;
    }
    if (D_800A1904_A2504 == musId) {
        return 0;
    }
    if (musId == 0) {
        return -1;
    }
    func_800035E8_41E8(D_800CDBC8_CE7C8[0].unk_00);
    D_800A1904_A2504 = musId;
    D_800A1906_A2506 |= 2;
    D_800A1906_A2506 &= ~(1 | 8);
    D_800CDBC8_CE7C8[0].unk_00 = func_80003310_3F10(musId);
    return D_800CDBC8_CE7C8[0].unk_00;
}
*/
INCLUDE_ASM("asm/nonmatchings/audio", HuAudSeqPlay);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A5C4_4B1C4);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A650_4B250);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A670_4B270);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A72C_4B32C);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A7C4_4B3C4);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A880_4B480);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A918_4B518);

// HuAudSeqStop?
void func_8004A950_4B550(void) {
    D_800A1904_A2504 = -1;
    func_800035E8_41E8(D_800CDBC8_CE7C8[0].unk_00);
    D_800A1906_A2506 &= ~(2 | 8);
    D_800A1906_A2506 |= 1;
}

void HuAudSeqFadeOut(s16 speed) {
    D_800A1904_A2504 = -1;
    func_800039A4_45A4(D_800CDBC8_CE7C8[0].unk_00, speed);
    D_800A1906_A2506 |= 8;
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A9DC_4B5DC);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA04_4B604);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA38_4B638);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA60_4B660);

s16 HuAudFXPlay(s16 seId) {
    if (D_800A1902_A2502 == 0) {
        return 0;
    }
    if (seId == 0) {
        return 0;
    }
    return func_80007064_7C64(seId);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AAD0_4B6D0);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AB0C_4B70C);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AB7C_4B77C);

void HuAudFXPitchSet(s32 seNo, s32 pitch) {
    func_80007BD4_87D4(seNo, pitch);
}

s16 CharFXPlay(s16 seId, u8 charNo) {
    if (D_800A1902_A2502 == 0) {
        return 0;
    }
    if (seId == 0) {
        return 0;
    }
    return func_80007064_7C64(seId + charNo + 1);
}

s32 func_8004AC5C_4B85C(s16 arg0, s16 arg1) {
    UnkAudStruct sp10;

    sp10.unk00 = 0x200;
    sp10.unk08 = arg1 + 1;
    return func_80007080_7C80(arg0, &sp10);
}

s16 func_8004AC98_4B898(s16 arg0, s16 arg1) {
    if (D_800A1902_A2502 == 0) {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }
    return func_8004AC5C_4B85C(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004ACE0_4B8E0);

void HuAudFXStop(s32 seNo) {
    func_80007DD8_89D8(seNo);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AD70_4B970);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AD8C_4B98C);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004ADDC_4B9DC);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AE00_4BA00);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AE28_4BA28);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AEF0_4BAF0);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AFBC_4BBBC);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004B0D4_4BCD4);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004B1AC_4BDAC);

// Doesn't seem to be audio related? Maybe part of the next file.
void func_8004B25C_4BE5C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (!(GwPlayer[arg0].stat & PLAYER_IS_CPU)) {
        func_8005A674_5B274(GwPlayer[arg0].pad, arg1, arg2, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004B2C0_4BEC0);

void func_8004B2C8_4BEC8(void) {
    str800D5298* temp;

    func_80000EA8_1AA8(&D_800D5298_D5E98);
    temp = &D_800D5298_D5E98;
    temp->unk28 = 1; //?
    D_800D5298_D5E98.unk8 = audio_mbf0_ROM_START;
    D_800D5298_D5E98.unkC = audio_sbf0_ROM_START;
    func_8000086C_146C(&D_800D5298_D5E98);
    if (!(D_800D09A8_D15A8 & 1)) {
        func_80000F30_1B30(0);
    } else {
        func_80000F30_1B30(1);
    }
}
