#ifndef _OVL_MINIGAME_H
#define _OVL_MINIGAME_H

#include "ultra64.h"
#include "game/object.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x08 */ s32 unk08;
} func_800E1BA8_B4728_UnkE8_ObjData; // Size 0xC

typedef struct {
    /* 0x000 */ char unk00[0x34];
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03C */ char unk3C[8];
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04C */ f32 unk4C;
    /* 0x050 */ char unk50[2];
    /* 0x052 */ s8 unk52;
    /* 0x053 */ char unk53[4];
    /* 0x057 */ s8 unk57;
    /* 0x058 */ char unk58[1];
    /* 0x059 */ s8 unk59;
    /* 0x05A */ char unk5A[6];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ char unk74[0x18];
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ char unk90[0xC];
    /* 0x09C */ f32 unk9C;
    /* 0x0A0 */ f32 unkA0;
    /* 0x0A4 */ f32 unkA4;
    /* 0x0A8 */ char unkA8[4];
    /* 0x0AC */ f32 unkAC;
    /* 0x0B0 */ f32 unkB0;
    /* 0x0B4 */ f32 unkB4;
    /* 0x0B8 */ char unkB8[0xB];
    /* 0x0C3 */ s8 unkC3;
    /* 0x0C4 */ s8 unkC4;
    /* 0x0C5 */ char unkC5[7];
    /* 0x0CC */ f32 unkCC;
    /* 0x0D0 */ u16 unkD0;
    /* 0x0D2 */ char unkD2[0x16];
    /* 0x0E8 */ func_800E1BA8_B4728_UnkE8_ObjData* unkE8;
    /* 0x0EC */ char unkEC[0x18];
    /* 0x104 */ s32 unk104[21];
    /* 0x158 */ char unk158[4];
} func_800E1BA8_B4728_ObjData; // Size 0x15C

typedef struct {
    /* 0x00 */ char unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ char unk07[0x11];
    /* 0x18 */ s8 unk18;
    /* 0x19 */ char unk19[3];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
} D_80111B50_282620_Struct; // Size unknown (>= 0x26 and <= 0x28)

void func_800E18D8_B4458_minigame(void);
void func_800E19F0_B4570_minigame(s8);
void func_800E1BA8_B4728_minigame(omObjData*, u32, s32, u16, s32, s32);
void func_800E4E30_B79B0_minigame(omObjData*);
void func_800E5690_B8210_minigame(omObjData*, u16);
void func_800E5A00_B8580_minigame(omObjData*, u16, s32, s32, u16);
void func_800E5EA0_B8A20_minigame(D_80111B50_282620_Struct*);
u8 func_800E6E8C_B9A0C_minigame(void);
void func_800E6F1C_B9A9C_minigame(void);
void func_800E6F34_B9AB4_minigame(s32);
void func_800E6F40_B9AC0_minigame(void);

extern s16 D_800EBE28_BE9A8_minigame;
extern s16 D_800EC1B8_BED38_minigame;
extern omObjData* D_800EC1C0_BED40_minigame;
extern u16 D_800EC280_BEE00_minigame;
extern omObjData* D_800EC598_BF118_minigame[];

#endif
