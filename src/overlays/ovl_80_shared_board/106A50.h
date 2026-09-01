#ifndef _ovl_80_106A50
#define _ovl_80_106A50

#include "common.h"
#include "game/board.h"

void func_800F453C_10815C_shared_board(void); //start MBStatusMain process
void func_800F4730_108350_shared_board(void);
void MBStatusColorSet(u32 playerNo, s32 turnStatus);
s32 func_800F482C_10844C_shared_board(s32 playerNo);
void func_800F4850_108470_shared_board(s32 playerNo, s32 arg1);
void MBStatusPosSet(s32 playerIndex, s16 arg1, s16 arg2);
void MBStatusDispSideSet(s32 playerNo, s32 arg1);
void MBStatusSideSet(s32 playerNo, s32 arg1);
s32 MBStatusDispMoveSet(s32 arg0);
s32 MBStatusItemDispGet(s32 playerNo);
s32 func_800F5278_108E98_shared_board(void);
s32 func_800F52C4_108EE4_shared_board(void);
void MBVsSprCreate(void);
void MBVsSprCreateY(f32 arg0, f32 arg1);
void MBVsSprKill(void);
void MBCoinTakeCreateSound(s32 playerIndex, s32 coinAmount, s32 arg2);
void MBCoinTakeCreate(s32 playerNo, s32 arg1);
s32 MBCoinTakeCheck(s32 playerNo);
s32 MBStatusHideCheck(void);
void MBStatusHideAll(void);
void MBStatusShowAll(void);
void func_800F5E24_109A44_shared_board(s32 arg0);
void MBStatusItemIconSprReinit(s32 arg0);
void MBStatusItemSprKill(s32 playerIndex);
void MBStatusItemDispSet(s32 playerNo, s32 arg1);
void MBStatusItemDispSetAll(s32 arg0);
void MBStatusSprPosGet(s16 arg0, s16 arg1, f32 *arg2, f32 *arg3);
void MBStatusItemOfsApply(s32 playerNo, s32 arg1, f32 arg2, f32 arg3);
void func_800F6848_10A468_shared_board(s32 playerNo, s32 arg1, f32 *arg2, f32 *arg3);
void MBStatusItemPosSet(s32 playerNo, s32 arg1, s16 arg2, s16 arg3);
void MBStatusItemTPLvlSet(s32 playerNo, s32 arg1, s16 arg2);
void MBStatusItemRotSet(s32 playerNo, s32 arg1, f32 arg2);
void MBStatusItemScaleSet(s32 playerNo, s32 arg1, f32 arg2, f32 arg3);
void MBStatusItemPriSet(s32 playerNo, s32 arg1, u16 arg2);
void MBStatusItemAttrSet(s32 playerNo, s32 arg1, u16 arg2);
void MBStatusItemAttrReset(s32 playerNo, s32 arg1, u16 arg2);
void func_800F6A88_10A6A8_shared_board(s16 arg0, u16 arg1);
void MBStatusSprBmpClear(s16 arg0, s16 arg1);
void MBStatusScaleSet(s32 arg0, f32 xScale, f32 yScale);
void MBStatusShrink(s32 playerNo);
void MBStatusItemPosGet(s32 playerIndex, s32 itemIndex, s32 *xPos, s32 *yPos);
void MBStatusGrow(s32 playerNo);
void func_800F70F8_10AD18_shared_board(void);
void func_800F7108_10AD28_shared_board(void);
void func_800F7114_10AD34_shared_board(s32 arg0, s32 arg1);

#endif //_ovl_80_106A50