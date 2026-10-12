#ifndef _ovl_80_10C230
#define _ovl_80_10C230

#include "common.h"
#include "game/board.h"

void MBOvlCall(s32 id, s16 event, u16 stat);
void MBOvlCallInit(void);
void MBOvlCallExec(void);
void func_800F884C_shared_board(void);
s16 func_800F8858_shared_board(void);
void MBObjectSetup(s32 arg0, s16 arg1, s32 arg2, s32 unused);
void MBExit(void);
void MBHatenaFuncSet(void (*arg0)(void));
void func_800F8D54_shared_board(void (*arg0)(void));
void MBKinokoEffKillHookSet(void (*arg0)());
void func_800F8D6C_shared_board(s32 arg0);
void MBCameraFocusModeSet(s16 arg0);
s16 MBCameraFocusModeGet(void);
void MBCameraFocusStaticPosSet(Vec *arg0);
void MBCameraFocusVecSet(Vec *arg0);
void MBPlayerPosFixSet(s32 playerNo, s32 arg1);
void MBKettouResultExec(void);
void MBKettouComResultSet(void);
s32 MBKettouPlayerBitGet(s32 arg0);
s32 func_800F9A68_shared_board(s32 arg0);
// s32 MBKettouExec(GW_PLAYER *arg0, s32 arg1); //this has to be implicit as it gets called with the wrong number of args in F5E80.c
s32 BoardGetTurnTier(s32 turn);
void func_800FC7C8_shared_board(void);
void func_800FC8A4_shared_board(void);
void func_800FC938_shared_board(void);
void func_800FC968_shared_board(void);
void func_800FC998_shared_board(void);
void func_800FC9E0_shared_board(void);
void func_800FCA14_shared_board(void);
void func_800FCA4C_shared_board(void);
void MBStart(u32 arg0);
void func_800FF794_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800FF7C4_shared_board(s32 arg0, s16 arg1, s16 arg2);
void func_800FF7F0_shared_board(s32 arg0);
void func_800FF800_shared_board(s16 arg0, s16 arg1); //unused
s16 func_800FF834_shared_board(void);
void func_800FF840_shared_board(Vec *arg0);

#endif //_ovl_80_10C230