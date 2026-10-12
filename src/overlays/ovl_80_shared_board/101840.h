#ifndef _ovl_80_101840
#define _ovl_80_101840

#include "common.h"
#include "game/board.h"

void func_800EE6C0_shared_board(Object*);
void func_800EDC20_shared_board(s32 arg0);
s32 func_800EDC40_shared_board(void);
void func_800EDC58_shared_board(s32 arg0, s32 arg1);
void func_800EDC74_shared_board(s32 arg0, s32 arg1);
void func_800EDF90_shared_board(s32 arg0, s32 arg1, s32 arg2); //unused
void func_800EDFAC_shared_board(s32 arg0, s32 arg1, s32 arg2); //unused
void func_800EE2A4_shared_board(s32 arg0);
void func_800EE2C0_shared_board(s32 arg0);
void func_800EE688_shared_board(Object* arg0, f32 arg1, f32 arg2);
s32 func_800EE694_shared_board(Object* arg0);
u32 func_800EE884_shared_board(Object* arg0, s16 arg1, s16 arg2);
void func_800EE94C_shared_board(Object *arg0, s16 arg1, s32 arg2); //unused
void MBModelMotionWait(Object *arg0);
s32 BoardPlayerRankCalc(s32 player);
s32 MBPlayerStealRankGet(s32 arg0);
s32 MBPlayerScoreGet(s32 arg0);
s32 func_800EECF0_shared_board(s32 arg0); //unused
s32 MBRand(f32 arg0);
void MBGuideFaceCreate(Object *arg0, s16 arg1, s16 arg2, s32 arg3);
void MBGuideFaceSet(Object* arg0, s32 arg1);
s32 func_800EF0D8_shared_board(s32 arg0);
s32 MBPauseMesNumGet(s32 arg0);
void MBPauseCreate(s32 arg0);

#endif //_ovl_80_101840