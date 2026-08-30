#ifndef _ovl_80_1006F0
#define _ovl_80_1006F0

#include "common.h"

void MBPlayerPosMasuSet(s16 playerNo, s16 spaceIdx);
void MBVecDirGet(Vec *arg0, Vec *arg1, Vec *arg2);
void func_800ECB90_1007B0_shared_board(s16 playerIdx, Vec* arg1);
void func_800ECBD0_1007F0_shared_board(Object* arg0, s16 arg1);
void MBVecForwardSet(Vec* out);
void MBPlayerForwardSet(s16 playerNo);
void func_800ECC54_100874_shared_board(Object* obj);
void MBPlayerMasuSwap(s16 playerNoOne, s16 playerNoTwo);
void MBPlayerMasuColorSet(s16 playerNo, s16 spaceType);
s16 MBTotalStarGet(void);
s16 MBRandCheck100(s8 arg0);
s16 MBTurnRemain(void);
s32 func_800ECF18_100B38_shared_board(s16 arg0, f32 arg1);
void func_800ECF9C_100BBC_shared_board(s16 arg0);
Process* func_800ED128_100D48_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
Process* func_800ED1E4_100E04_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
void func_800ED20C_100E2C_shared_board(s16 playerNo, s32 arg1, s16 masuAbsIndex);
Process *MBPlayerPosMoveCreate(Vec *arg0, Vec *arg1, Vec *outVec, s32 interpolationTime);
void MBPlayerPosMoveSet(s16 playerNo, s32 interpolationFrameTotal);
void MBMoveMasuSet(s16 playerNo, s16 link, s16 idx);
void MBMoveNextMasuSet(s16 playerNo, s16 arg1, s16 arg2);
void MBMoveBackMasuSet(s16 playerNo, s16 arg1, s16 arg2);
s32 func_800EDA58_101678_shared_board(void);
Process* func_800EDB98_1017B8_shared_board(Object* arg0, f32 arg1, f32 arg2);

#endif //_ovl_80_1006F0