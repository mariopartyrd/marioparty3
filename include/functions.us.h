#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "common.h"

void func_800E52F8_CD0C8_name_81(void);
void func_800E5000_CCDD0_name_81(void);
void func_800F64FC_DE2CC_name_81(void);
void func_8001C5B4_1D1B4(s16, s16);
void func_80106850_4F10A0_name_73(omObjData*, s32);
void ovlEventCall(OvlEntrypoint*, s16);
void HuMemMemoryFreePerm(void *ptr);
s32 HmfSprModelCreate(void*, s32, u8);
s32 HmfAnimCreate(s32, void*, s32, s32);
void pfClsScr(void);
s32 GWBoardFlagCheck(s32);
GW_PLAYER* GetPlayerStruct(s32 playerIndex);
s16 func_80017790_18390(s16 model, s32 arg1, s32 arg2, s32 arg3);
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
SpaceData* GetSpaceData(s16 arg0);
void func_800698E8_6A4E8(u8**, u8*, s32, s32);
void func_80069E68_6AA68(s32);
void func_8006A370_6AF70(s32);
void func_8000B690_C290(s32);
void func_800142A0_14EA0(s32);
f32 HuMathCos(f32);
f32 HuMathSin(f32);
void* HuMemMemoryAlloc(HeapNode* heap, s32 size);
void func_8005A6B0_5B2B0(void);
void func_8004CF30_4DB30(void);
void func_80036414_37014(Addr);
void func_8005DDDC_5E9DC(void);
void func_80033354_33F54(s16);
void func_8005F364_5FF64(s16);
void func_8005B43C_5C03C(s16, s32, s32, s32);
void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2);
void func_8005E1A8_5EDA8(s16, s16);
void func_8006022C_60E2C(s32, s32);
void func_80060394_60F94(s32, s16*, s32);
void func_80061388_61F88(s16);
void HuVecSubtract(Vec * dest, Vec * a, Vec * b);
void HuVecAdd(Vec* out, Vec* a, Vec* b);
void func_8000BBD4_C7D4(u16, s32, s32);
void func_8000BCC8_C8C8(u16, s32);
s32 CheckControllerRead(s16 padNum);
s32 GWContErrorGet(void);
void func_8005F524_60124(void);
void GWContErrorSet(void);
void Hu3DAnimInit(s32);
s16 GWMgUnlockCheck(s16 arg0);
s32 _CheckFlag(s32);
void GWMgUnlockSet(s16 bitPos);
void _ClearFlag(s32 flag);
void func_8000B5F0_C1F0(u8 arg0);
void _SetFlag(s32 flag);

#endif
