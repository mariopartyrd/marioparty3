#ifndef _ovl_80_FA250
#define _ovl_80_FA250

#include "common.h"
#include "game/board.h"

void func_800E6630_shared_board(u32 arg0);
void func_800E66D4_shared_board(void);
void MBBackClose(void);
void MBBackCreate(s32 arg0, s32 arg1);
void MBBackLoad(s32 arg0);
void MBBackKill(void);
void func_800E6FBC_shared_board(void);
void func_800E6FCC_shared_board(void);
void func_800E7254_shared_board(void);
void func_800E728C_shared_board(void);
f32 MBBackMdlScaleGet(void);
f32 MBCameraZoomGet(void);
void MBCameraZoomSet(f32 zoom);
Process* MBCameraZoomMotStart(f32 arg0);
Process* func_800E9044_shared_board(f32 arg0);
void func_800E92D4_shared_board(void);
void func_800E9344_shared_board(f32 arg0, f32 arg1);
void func_800E9730_shared_board(f32 arg0);
f32 func_800E973C_shared_board(void);
u16 MBCameraPos3DSet(Vec *arg0);
u16 MBCameraPos2DSet(Vec2f* arg0);
void MBCameraPos3DGet(Vec2f* arg0);
void MBCameraPos2DGet(Vec2f *arg0);
void MBCamera3Dto2D(Vec* arg0, f32* arg1);
void MBBackTPLvlSet(u8 arg0);
void MBCameraSpeedSet(f32 arg0);
f32 MBCameraSpeedGet(void);
s32 MBCameraStopCheck(void);
void func_800E9AF0_shared_board(Vec* arg0, s32 arg1);
void func_800E9EF4_shared_board(void);
void func_800EA284_shared_board(void);
void func_800EA348_shared_board(void);
void func_800EA358_shared_board(void);
void func_800EA60C_shared_board(void);
void MBMasuArrowAngleAdd(f32 arg0);
void func_800EA694_shared_board(void);
void func_800EA6B0_shared_board(s16 arg0);
void MBMasuStarSet(s32 arg0, s16 arg1);
s32 MBMasuCreate(s32 arg0, s32 arg1);
void func_800EB09C_shared_board(void);

//file split?
SpaceData *MBMasuGet(s16 arg0);
s16 MBMasuLinkMasuIdGet(u16 linkIdx, u16 spaceIdx);
s16 MBMasuLinkNumGet(u16 arg0);
void func_800EB24C_shared_board(s16 arg0, s8 *chainOut, s8 *linkOut);
void MBMasuTypeSet(s16 spaceIdx, s32 newSpaceType);
void func_800EB820_shared_board(u16 linkNo, u16 curSpaceType, u8 newSpaceType);
void func_800EB97C_shared_board(s16 arg0);
void MBMasuEventTblAdd(event_table_entry *arg0);
s32 MBMasuEventCall(s16 arg0, s16 arg1);
void MBMasuCurSet(s16 arg0);
s16 MBMasuCurGet(void);
s16 MBMasuKakusiBlockGet(u8 arg0);
void MBMasuBlockTblExtSet(s16 *arg0);
void MBMasuBlockTblSet(s16 *arg0);
void func_800EBDAC_shared_board(void);
u8 func_800EBEAC_shared_board(s32 arg0, s32 arg1);
void MBMasuDispOn(void);
void MBMasuDispOff(void);

#endif //_ovl_80_FA250