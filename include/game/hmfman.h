#ifndef _GAME_HMFMAN_H
#define _GAME_HMFMAN_H

#include "common.h"

typedef struct {
    /* 0x00 */ Gfx* unk00;
    /* 0x04 */ Gfx* unk04[3]; // unknown length
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
} HmfModelData_Unk64_Unk3C_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[0x50];
    /* 0x50 */ s32 unk50;
} HmfModelData_Unk64_Unk60_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[8];
    /* 0x08 */ s32 unk08;
} HmfModelData_Unk64_Unk98_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[0xE];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ char unk10[0x2C];
    /* 0x3C */ HmfModelData_Unk64_Unk3C_Struct* unk3C;
    /* 0x40 */ char unk40[4];
    /* 0x44 */ Vtx* unk44[1]; // unknown length
    /* 0x48 */ char unk48[0x18];
    /* 0x60 */ HmfModelData_Unk64_Unk60_Struct* unk60;
    /* 0x64 */ char unk64[0x34];
    /* 0x98 */ HmfModelData_Unk64_Unk98_Struct* unk98;
} HmfModelData_Unk64_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ u8 unk02;
    /* 0x03 */ char unk03[1];
    /* 0x04 */ u8 unk04;
    /* 0x05 */ char unk05[0x13];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec rot;
    /* 0x34 */ Vec scale;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ char unk48[4];
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ char unk50[0x14];
    /* 0x64 */ HmfModelData_Unk64_Struct* unk64;
    /* 0x68 */ char unk68[0xC];
    /* 0x74 */ f32 unk74[16];
    /* 0x78 */ char unkB4[0xC];
} HmfModel; // Size 0xC0

void func_8001A070_1AC70(void* arg0, void* arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5);
s32 func_8001A894_1B494(s32, void*, s32); // unsure about second arg. Gfx*?
void func_8001ACDC_1B8DC(s16);
void func_8001B0B4_1BCB4(void** arg0, u32 arg1);
void func_8001BF90_1CB90(u32 arg0, u32 arg1);
void Hu3DModelPosSet(s16 arg0, f32 x, f32 y, f32 z);
void Hu3DModelRotSet(s16 arg0, f32 x, f32 y, f32 z);
void Hu3DModelScaleSet(s16 arg0, f32 x, f32 y, f32 z);
void func_8001C258_1CE58(s16 arg0, s32 arg1, s32 arg2);
void func_8001C448_1D048(s16);
f32 func_8001C7D0_1D3D0(s16 arg0);
void func_8001C8E4_1D4E4(s16, s32);
void func_8001C92C_1D52C(s16, f32);
void func_8001F304_1FF04(s16, s16);
void func_8001FDE8_209E8(s16);

extern HmfModel* HmfModelData;

#endif
