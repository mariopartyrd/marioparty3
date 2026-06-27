#ifndef _GAME_SPRITE_H
#define _GAME_SPRITE_H

#include "ultra64.h"

#define HUSPR_GRP_MAX 256

#define HUSPR_NONE -1

typedef struct {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
} HuSprite_Unk84_Unk00_Struct; // Size 0xC

typedef struct {
    /* 0x00 */ HuSprite_Unk84_Unk00_Struct* unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ void* unk08;
    /* 0x0C */ void* unk0C; // pal data?
    /* 0x10 */ u16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
} HuSprite_Unk84_Struct; // Size 0x1C

// Cel-animation playback state. Embedded in HuSprite at offset 0x68 (unk_68);
// the animation functions receive a pointer to this region.
typedef struct HuSprAnm {
    /* 0x00 */ HuSprite_Unk84_Struct* unk00; // texture descriptor
    /* 0x04 */ u8 unk04;                     // flags
    /* 0x06 */ s16 unk06;                    // playback mode
    /* 0x08 */ s16 unk08;                    // cel index
    /* 0x0A */ s16 unk0A;                    // frame counter
    /* 0x0C */ f32 unk0C;                    // time accumulator
    /* 0x10 */ f32 unk10;                    // frame step
    /* 0x14 */ s16 unk14;                    // current cel output
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
} HuSprAnm; // Size 0x1C

typedef struct HuSprite {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 prio;
    /* 0x18 */ char unk_18[0xC];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk_28[4];
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ char unk_30[0x18];
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ HuSprAnm unk_68;
    /* 0x84 */ HuSprite_Unk84_Struct* unk_84;
    /* 0x88 */ s8 unk_88;
    /* 0x8A */ s16 unk_8A;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ s16 unk_90;
    /* 0x92 */ s8 unk_92;
} HuSprite; // Size 0x210 (or a divisor of 0x210)

typedef struct HuSprGrp {
    struct HuSprGrp* next;
    struct HuSprGrp* prev;
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    HuSprite* members[4]; //unknown size
} HuSprGrp; //unknown size

extern HuSprGrp* HuSprGrpData[HUSPR_GRP_MAX];

void func_80052330_52F30(void);
void HuSprGrpKill(s16);
s16 HuSprGrpCreate(u16 arg0, u16 arg1);
void func_80054904_55504(s16 group, s16 member, s16 arg2, s16 arg3);
void func_80054FF8_55BF8(s16 group, s16 member, s32 arg2);
void func_80055024_55C24(s16 group, s16 member, s16 arg2, s32 arg3);
void func_800550B4_55CB4(s16 group, s16 member, f32 arg2);
void func_800550F4_55CF4(s16, s16, s32);
void func_80055140_55D40(s32, s16, u16, s32);
u8 func_800551AC_55DAC(s16 group, s16 member);
HuSprite_Unk84_Struct* func_80055194_55D94(s16 arg0);
void HuSprScaleSet(s16 group, s16 member, f32 x, f32 y);
void HuSprPriSet(s16 group, s16 member, u16 prio);
void func_800552DC_55EDC(s16, s16, f32);
void HuSprAttrReset(s16 group, s16 member, s32 attr);
void HuSprAttrSet(s16 group, s16 member, s32 attr);
void func_80055420_56020(s16, s16, u8, u8, u8);
void func_80055458_56058(s16, s16, u16);
void func_800554C4_560C4(s16 group, s16 member, u16 arg2);
HuSprite* HuSprGet(s16 group, s16 member);
void HuSprKill(s16);
s16 func_80055810_56410(void*);
void func_80056BAC_577AC(void);

#endif
