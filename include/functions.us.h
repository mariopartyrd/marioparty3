#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "common.h"

void MBDBackKill(void);
void MBDBackClose(void);
void func_800F64FC_DE2CC_name_81(void);
void func_80106850_4F10A0_mgresultduel(omObjData*, s32);
void ovlEventCall(OvlEntrypoint*, s16);
void HuMemMemoryFreePerm(void *ptr);
s32 HmfSprModelCreate(void*, s32, u8);
s32 HmfAnimCreate(s32, void*, s32, s32);
void pfClsScr(void);
s32 GWBoardFlagCheck(s32);
GW_PLAYER* GetPlayerStruct(s32 playerIndex);
s16 func_80017790_18390(s16 model, s32 arg1, s16 arg2, s32 arg3);
void AdjustPlayerCoins(s32 arg0, s32 arg1);
s32 func_800EEF80_102BA0_shared_board(f32);
void FixUpPlayerItemSlots(s32 arg0);
void func_800007FC_13FC(str800D5298* arg0);
void func_80000EA8_1AA8(str800D5298* arg0);
void func_80000F30_1B30(u32 arg0);
void func_800143F0_14FF0(void);
void func_80014A3C_1563C(u32 arg0);
void func_800224BC_230BC(void);
void GWInit(void); // save.h
void GWMgRecordSet(s16 arg0, s16 arg1); // save.h
void func_80036380_36F80(Addr arg0);
void pfInit(void);
void func_8004F290_4FE90(void);
s32  func_8004FDC0_509C0(void);
void func_80050800_51400(void);
void SLCurBoxNoSet(u32 arg0);
void* memset(void *dest, int ch, unsigned int n);
void func_80050974_51574(void);
s32 print8(u16 x, u16 y, char* src);
void func_8005035C_50F5C(s32);
void func_80050ABC_516BC(void);
void GWBoardFlagClear(s32 flag);
void GWBoardFlagSet(s32 flag);
void SetSpaceType(s16, s32);
SpaceData* MBMasuGet(s16 arg0);
void func_800698E8_6A4E8(u8**, u8*, s32, s32);
void func_80069E68_6AA68(s32);
void func_8006A370_6AF70(s32);
void func_8000B690_C290(s32);
void func_800142A0_14EA0(s32);
f32 HuMathCos(f32);
f32 HuMathSin(f32);
void* HuMemMemoryAlloc(HeapNode* heap, s32 size);
void func_8004CF30_4DB30(void);
void func_80036414_37014(Addr);
void func_80033354_33F54(s16);
void HuVecSubtract(Vec * dest, Vec * a, Vec * b);
void HuVecAdd(Vec* out, Vec* a, Vec* b);
s32 CheckControllerRead(s16 padNum);
s32 GWContErrorGet(void);
void GWContErrorSet(void);
void Hu3DAnimInit(s32);
s16 GWMgUnlockCheck(s16 arg0);
s32 _CheckFlag(s32);
void GWMgUnlockSet(s16 bitPos);
void _ClearFlag(s32 flag);
void func_8000B5F0_C1F0(u8 arg0);
void _SetFlag(s32 flag);
void func_8008A430_8B030(f32(*)[], f32);
void func_8005B63C_5C23C(s16, s32, s32);
s32 func_8005E1D8_5EDD8(s16, s16, s32);
void func_8005F698_60298(s16, s16, s16, s16, u8);
void func_8005F744_60344(s16, s16, s16, s16);
void func_8005FE54_60A54(s16, u8);
void func_8006010C_60D0C(s16, s16);
void Hu3DCam3DToScreen(s16 camIndex, Vec * worldPos, Vec * outPos);
s32 func_80017BB8_187B8(s16, s16);

#endif
