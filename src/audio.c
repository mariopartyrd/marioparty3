#include "game/audio.h"
#include "game/vibrator.h"
#include "common.h" // TODO: remove.

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ char unk0C[0x1D];
} UnkAudStruct; // Size unknown (min: 0x29, max: 0x30)

void func_8000086C_main(str800D5298 *);
s16 func_80003310_main(s16);
s32 func_80007064_main(s32);
s32 func_80007080_main(s16, UnkAudStruct *);
void func_80007BD4_main(s16, s16);
void func_80007C80_main(s16, s16);
void func_80007DD8_main(s16);

extern u8 D_800D09A8_main;
extern str800D5298 D_800D5298_main;
extern s32 D_800D52C0_main;

u16 D_800A1900_main = 1;
u16 D_800A1902_main = 1;
s16 D_800A1904_main = -1; // active musId
u16 D_800A1906_main = 1;  // stat/attr
s16 D_800A1908_main = 0;
s16 D_800A190A_main = 0;
s16 D_800A190C_main = 1;
s16 D_800A190E_main = 1;
s16 D_800A1910_main[8] = { 0x0040 }; // single s16 + padding?

s16 HuAudSeqPlay(s16 musId) {
    if (D_800A1900_main == 0) {
        return 0;
    }
    if (D_800A1904_main == musId) {
        return 0;
    }
    if (musId == 0) {
        return -1;
    }
    func_800035E8_main(D_800CDBC8_main);
    D_800A1904_main = musId;
    D_800A1906_main |= 2;
    D_800A1906_main &= ~(1 | 8);
    D_800CDBC8_main = func_80003310_main(musId);
    return D_800CDBC8_main;
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A5C4_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A650_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A670_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A72C_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A7C4_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A880_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A918_main);

// HuAudSeqStop?
void func_8004A950_main(void) {
    D_800A1904_main = -1;
    func_800035E8_main(D_800CDBC8_main);
    D_800A1906_main &= ~(2 | 8);
    D_800A1906_main |= 1;
}

void HuAudSeqFadeOut(s16 speed) {
    D_800A1904_main = -1;
    func_800039A4_main(D_800CDBC8_main, speed);
    D_800A1906_main |= 8;
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004A9DC_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA04_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA38_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AA60_main);

s16 HuAudFXPlay(s16 seId) {
    if (D_800A1902_main == 0) {
        return 0;
    }
    if (seId == 0) {
        return 0;
    }
    return func_80007064_main(seId);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AAD0_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AB0C_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AB7C_main);

void HuAudFXPitchSet(s32 seNo, s32 pitch) {
    func_80007BD4_main(seNo, pitch);
}

s16 CharFXPlay(s16 seId, u8 charNo) {
    if (D_800A1902_main == 0) {
        return 0;
    }
    if (seId == 0) {
        return 0;
    }
    return func_80007064_main(seId + charNo + 1);
}

s32 func_8004AC5C_main(s16 arg0, s16 arg1) {
    UnkAudStruct sp10;

    sp10.unk00 = 0x200;
    sp10.unk08 = arg1 + 1;
    return func_80007080_main(arg0, &sp10);
}

s16 func_8004AC98_main(s16 arg0, s16 arg1) {
    if (D_800A1902_main == 0) {
        return 0;
    }
    if (arg0 == 0) {
        return 0;
    }
    return func_8004AC5C_main(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004ACE0_main);

void HuAudFXStop(s32 seNo) {
    func_80007DD8_main(seNo);
}

void func_8004AD70_main() {
    func_80007DD8_main(-1);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AD8C_main);

void func_8004ADDC_main(s16 arg0) {
    func_80007C80_main(-1, arg0);
}

void func_8004AE00_main(s16 arg0, s16 arg1) {
    func_80007C80_main(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AE28_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AEF0_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004AFBC_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004B0D4_main);

INCLUDE_ASM("asm/nonmatchings/audio", func_8004B1AC_main);

// Doesn't seem to be audio related? Maybe part of the next file.
void omVibrate(s16 player, s16 duration, s16 off, s16 on) {
    if (!(GwPlayer[player].stat & PLAYER_IS_CPU)) {
        RepeatVibrator(GwPlayer[player].pad, duration, off, on);
    }
}

s32 func_8004B2C0_main() {
    return 0;
}

void func_8004B2C8_main(void) {
    str800D5298 *temp;

    func_80000EA8_main(&D_800D5298_main);
    temp = &D_800D5298_main;
    temp->unk28 = 1; //?
    D_800D5298_main.unk8 = audio_mbf0_ROM_START;
    D_800D5298_main.unkC = audio_sbf0_ROM_START;
    func_8000086C_main(&D_800D5298_main);
    if (!(D_800D09A8_main & 1)) {
        func_80000F30_main(0);
    } else {
        func_80000F30_main(1);
    }
}
