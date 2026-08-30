#ifndef _ovl_80_F5E80
#define _ovl_80_F5E80

#include "common.h"
#include "game/board.h"

void func_800E2260_F5E80_shared_board(s32 arg0, char *arg1);
void MBItemWarpBlockSwapInit(void);
s32 MBItemWarpBlockSwapPlayerSet(s16 arg0);
void MBItemWarpBlockSwapCreate(void);
void MBItemHookSet(s32 idx, void (*func)());
void MBItemSelExec(s32 playerNo, s32 arg1);
void MBItemViewExec(s32 playerNo);
void MBItemDescExec(s32 arg0);
void MBItemKSuitWalkExec(void);
void MBItemMajinLampStarExec(void);
s32 MBItemFind(s32 playerNo, s32 item);
s32 MBItemFindEmpty(s32 arg0);
void MBItemRemoveEmpty(s32 arg0);
s32 MBItemSelNoGet(void);
void MBTelopInit(void);
void MBTelopClose(void);
void MBTelopMgTypeCreate(s32 arg0, u32 arg1);
s32 MBTelopMgTypeStatGet(void);
void MBTelopMgTypeKill(void);
Process* MBTelopCreate(s32 playerNo);
void MBGuideCameraCreate(void);
UnkMBGuideData* MBGuideCreate(u32* arg0, s32 arg1);
void MBGuideKill(UnkMBGuideData* arg0);
void MBGuidePosSet(UnkMBGuideData* arg0, s16 arg1, s16 arg2);

#endif //_ovl_80_F5E80