#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "common.h"
#include "common_structs.h"

extern s16 omovlevtno;
extern UnkDiceRelated D_800CDBC8_CE7C8[4];
extern GW_PLAYER GwPlayer[4];
extern GW_COMMON GwCommon;
extern GW_STORY GwStory;
extern GW_SYSTEM GwSystem;
ESprite* D_800CDD70_CE970[256]__attribute__((aligned(16)));
extern s32 D_800A12D4;
extern s32 D_800A12D8;

extern s16 D_800CDD58_CE958;
extern s16 D_800D037C_D0F7C;
extern s16 D_800D51F8_D5DF8;
extern UnkOvl81 D_800D1360_D1F60;
extern s8 D_800CD280_CDE80;

extern HuCamera* gCameraList;

#endif //_VARIABLES_H_