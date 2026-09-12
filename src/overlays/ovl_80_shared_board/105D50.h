#ifndef _ovl_80_105D50
#define _ovl_80_105D50

#include "common.h"
#include "game/board.h"

extern u32 *D_80101734_115354_shared_board[];

s16 MBPlayerTurnGet(void);
GW_PLAYER *MBPlayerGet(s32 playerNo);
s32 MBPlayerCurrentCheck(s16 playerNo);
s32 MBPlayerComCheck(s16 playerNo);
void MBPlayerCoinAdd(s32 playerNo, s32 amount);
s32 MBPlayerCoinCheck(s32 playerNo, s32 requiredCoins);
void MBPlayerSpeedSet(s32 playerNo, f32 arg1);
void MBPlayerMotionWait(s32 playerNo);
void MBPlayerMotionSet(s32 playerNo, s16 arg1, u16 arg2) ;
void func_800F2388_105FA8_shared_board(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4) ;
void func_800F244C_10606C_shared_board(s32 playerNo, u8 arg1);
void func_800F2484_1060A4_shared_board(s32 arg0);
void MBPlayerModelCreate(s16 playerNo, u32 *arg1, s32 arg2);
void func_800F25B4_1061D4_shared_board(s16 arg0, u32 *arg1); //unused
void func_800F25D8_1061F8_shared_board(s16 playerNo);
void func_800F2624_106244_shared_board(s16 playerNo); //unused
void func_800F2690_1062B0_shared_board(s16 playerNo); //unused
void func_800F26E8_106308_shared_board(void);
void func_800F27C4_1063E4_shared_board(void);

#endif //_ovl_80_105D50
