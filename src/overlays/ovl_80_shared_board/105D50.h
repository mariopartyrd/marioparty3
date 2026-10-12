#ifndef _ovl_80_105D50
#define _ovl_80_105D50

#include "common.h"
#include "game/board.h"

extern u32 *D_80101734_shared_board[];

s16 MBPlayerTurnGet(void);
GW_PLAYER *MBPlayerGet(s32 playerNo);
s32 MBPlayerCurrentCheck(s16 playerNo);
s32 MBPlayerComCheck(s16 playerNo);
void MBPlayerCoinAdd(s32 playerNo, s32 amount);
s32 MBPlayerCoinCheck(s32 playerNo, s32 requiredCoins);
void MBPlayerSpeedSet(s32 playerNo, f32 arg1);
void MBPlayerMotionWait(s32 playerNo);
void MBPlayerMotionSet(s32 playerNo, s16 arg1, u16 arg2) ;
void func_800F2388_shared_board(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4) ;
void func_800F244C_shared_board(s32 playerNo, u8 arg1);
void func_800F2484_shared_board(s32 arg0);
void MBPlayerModelCreate(s16 playerNo, u32 *arg1, s32 arg2);
void func_800F25B4_shared_board(s16 arg0, u32 *arg1); //unused
void func_800F25D8_shared_board(s16 playerNo);
void func_800F2624_shared_board(s16 playerNo); //unused
void func_800F2690_shared_board(s16 playerNo); //unused
void func_800F26E8_shared_board(void);
void func_800F27C4_shared_board(void);

#endif //_ovl_80_105D50
