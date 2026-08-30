#ifndef _ovl_80_ECA50
#define _ovl_80_ECA50

#include "common.h"
#include "game/board.h"

s16 func_800D8E88_ECAA8_shared_board(s32 arg0);
void MBMotionKill(s16 arg0);
void MBModelInit(void);
void MBModelClose(void);
Object* MBModelCreate(u8 arg0, u32* arg1);
Object *MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32 *arg4);
void func_800D95C4_ED1E4_shared_board(f32 arg0);
void MBModelTempAllocFree(Object* arg0);
Object *MBModelLinkCreate(Object *src);
void func_800D9A40_ED660_shared_board(Object* arg0);
void MBModelAttrSetDispOn(Object* arg0);
void MBModelDispOn(Object* arg0);
void MBModelAttrSetDispOff(Object* arg0);
void MBModelDispOff(Object* arg0);
void MBModelKill(Object* arg0);
s32 func_800D9CB0_ED8D0_shared_board(Object* arg0);
void MBMotionSet(Object *arg0, s16 arg1, u16 arg2);
void MBMotionShiftSet(Object* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
u16 MBMotionCheck(Object* arg0);
u16 func_800D9E80_EDAA0_shared_board(Object* arg0);
void MBPlayerMotionLoad(s32 arg0, s32 arg1, s32 arg2);

#endif //_ovl_80_ECA50