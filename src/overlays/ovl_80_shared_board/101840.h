#ifndef _ovl_80_101840
#define _ovl_80_101840

#include "common.h"
#include "game/board.h"

void func_800EDC20_101840_shared_board(s32 arg0);
s32 func_800EDC40_101860_shared_board(void);
void func_800EDC58_101878_shared_board(s32 arg0, s32 arg1);
void func_800EDC74_101894_shared_board(s32 arg0, s32 arg1);
void func_800EDF90_101BB0_shared_board(s32 arg0, s32 arg1, s32 arg2); //unused
void func_800EDFAC_101BCC_shared_board(s32 arg0, s32 arg1, s32 arg2); //unused
void func_800EE2A4_101EC4_shared_board(s32 arg0);
void func_800EE2C0_101EE0_shared_board(s32 arg0);
void func_800EE2DC_101EFC_shared_board(s32 arg0, s32 arg1);
void func_800EE688_1022A8_shared_board(Object* arg0, f32 arg1, f32 arg2);
u32 func_800EE884_1024A4_shared_board(Object* arg0, s16 arg1, s16 arg2);
void func_800EE94C_10256C_shared_board(Object *arg0, s16 arg1, s32 arg2); //unused
void MBModelMotionWait(Object *arg0);
s32 BoardPlayerRankCalc(s32 player);
s32 MBPlayerStealRankGet(s32 arg0);
s32 MBPlayerScoreGet(s32 arg0);
s32 func_800EECF0_102910_shared_board(s32 arg0); //unused
s32 MBRand(f32 arg0);
void MBGuideFaceCreate(Object *arg0, s16 arg1, s16 arg2, s32 arg3);
void MBGuideFaceSet(Object* arg0, s32 arg1);
s32 func_800EF0D8_102CF8_shared_board(s32 arg0);
s32 MBPauseMesNumGet(s32 arg0);
void MBPauseCreate(s32 arg0);

#endif //_ovl_80_101840