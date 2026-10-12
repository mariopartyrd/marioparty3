#ifndef _ovl_80_F2910
#define _ovl_80_F2910

#include "common.h"

void MBMgCallHisInit(void);
void func_800DF854_shared_board(void);
void MBMgCallClose(void);
void MBMgCallListCreate(s32 arg0);
void func_800E00EC_shared_board(void);
void MBArrayShuffle(u8 *output, s32 count);
Process *MBMgCallCreate(void);
Process *MBMgCallBattleCreate(void);
Process *func_800E0F84_shared_board(void);
Process *func_800E11C0_shared_board(s32 arg0, s32 arg1);
Process *MBMgCallTutorialCreate(void);

#endif //_ovl_80_F2910