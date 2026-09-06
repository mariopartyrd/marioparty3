#ifndef _ovl_80_F5E80
#define _ovl_80_F5E80

#include "common.h"
#include "game/board.h"

extern u8 D_80100F94_114BB4_shared_board[];
extern s32 D_80100FA8_114BC8_shared_board[];
extern s32 D_80100FF4_114C14_shared_board[];
extern s32 D_80101040_114C60_shared_board[];

void func_800E2260_F5E80_shared_board(s32 arg0, char *arg1);
void MBItemWarpBlockSwapInit(void);
s32 MBItemWarpBlockSwapPlayerSet(s16 arg0);
void MBItemWarpBlockSwapCreate(void);
void MBItemHookSet(s32 idx, void (*func)());
void MBItemSelExec(s32 playerNo, s32 arg1);
void MBItemViewExec(s32 playerNo);
void MBItemDescExec(s32 arg0);
void MBItemKSuitWalkExec(void);
void MBItemKSuitEnd(void);
void MBItemMajinLampStarExec(void);
s32 MBItemFind(s32 playerNo, s32 item);
s32 MBItemFindEmpty(s32 arg0);
void MBItemRemoveEmpty(s32 arg0);
s32 MBItemSelNoGet(void);
void MBItemSelNoSet(s32 arg0);
void MBItemSelNoClear(void);
void MBTelopInit(void);
void MBTelopClose(void);
void MBTelopMgTypeCreate(s32 arg0, u32 arg1);
s32 MBTelopMgTypeStatGet(void);
void MBTelopMgTypeKill(void);
Process* MBTelopCreate(s32 playerNo);
UnkMBGuideData* MBGuideCreate(u32* arg0, s32 arg1);
void MBGuideKill(UnkMBGuideData* arg0);
void MBGuidePosSet(UnkMBGuideData* arg0, s16 arg1, s16 arg2);
void MBItemKoopaNKinokoExec(void);
void MBItemKoopaRKinokoExec(void);

#endif //_ovl_80_F5E80
