#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "common.h"
#include "game/object.h"

void SprAttrSet(s16, s16, u16);
void SprAttrReset(s16, s16, u16);
s16 HuAudFXPlay(s32);
void func_800E52F8_CD0C8_name_81(void);
void func_800E5000_CCDD0_name_81(void);
void func_800F64FC_DE2CC_name_81(void);
void func_8001C814_1D414(s16, s32, s16);
void Hu3DModelScaleSet(s16, f32, f32, f32);
void func_8000B460_C060(omObjData*, u16, s32);
void func_8001C5B4_1D1B4(s16, s16);
void func_80106850_4F10A0_name_73(omObjData*, s32);
void Hu3DModelPosSet(s16, f32, f32, f32);
u16 func_8000B108_BD08(s32 arg0, s32 arg1);
void ovlEventCall(OvlEntrypoint*, s16);
f32 HuMathCos(f32);
s16 func_8000B13C_BD3C(s32);
s16 Hu3DModelCreate(void*, s32);
void* HuReadFileTag(s32 dirAndFile, s32 tag);
void CameraScissorSet(s16 camIndex, RectF* arg1);
void* ReadMainFS(s32);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void HuMemMemoryFreePerm(void *ptr);
void* ReadMainFS(s32 dirAndFile);
s32 func_8001443C_1503C(void*, s32, u8);
s32 func_800323CC_32FCC(s32, void*, s32, s32);
void func_80054904_55504(s16, s16, s16, s16);
void func_80055024_55C24(s16, s16, s16, s32);
void func_800552DC_55EDC(s16, s16, f32);
void func_80055140_55D40(s32, s16, u16, s32);
void func_800550B4_55CB4(s32, s16, f32);
void func_800550F4_55CF4(s16, s16, s32);
void SprScale(s16, s16, f32, f32);
void SprPriSet(s16, s16, u16);
void func_80055420_56020(s16, s16, u8, u8, u8);
void func_80055458_56058(s16, s16, u16);
void func_8001C258_1CE58(s16, s32, s32);
void func_8001C448_1D048(s16);
void func_8001C8E4_1D4E4(s16, s32);
void HuFreeFilePerm(void*);
s16 func_80055810_56410(void*);
s16 func_8005279C_5339C(u16, u16);
void pfClsScr(void);
u8 rand8(void);
s32 GWBoardFlagCheck(s32);
GW_PLAYER* GetPlayerStruct(s32 playerIndex);
s16 func_80017790_18390(s16 model, s32 arg1, s32 arg2, s32 arg3);
void AdjustPlayerCoins(s32 arg0, s32 arg1);
s32 func_800EEF80_102BA0_shared_board(f32);
void func_8004ACE0_4B8E0(s32, s16);
void FixUpPlayerItemSlots(s32 arg0);
void Hu3DCamSetPerspective(s16 camIndex, f32 fov, f32 near, f32 far);
void ScissorSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void ViewportSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_8004B4D4_4C0D4(omObjData*);
void Hu3DCamInit(u32 arg0);
void WipeCreateIn(s32, s32);
void func_8004A208_4AE08(void);
void HmfLightColorSet(s32, s32, s32, s32);
void HmfLightMaxSet(s32);
void HmfLightDirSet(s32, f32, f32, f32);
void func_800007FC_13FC(str800D5298* arg0);
void func_80000EA8_1AA8(str800D5298* arg0);
void func_80000F30_1B30(u32 arg0);
void func_8000BA30_C630(void); // esprite.h
void func_800143F0_14FF0(void);
void func_80014A3C_1563C(u32 arg0);
void func_8001A070_1AC70(void *arg0, void *arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5); // hmfman.h
void func_8001B0B4_1BCB4(void **arg0, u32 arg1); // hmfman.h
void func_8001BF90_1CB90(u32 arg0, u32 arg1); // hmfman.h
void func_800224BC_230BC(void);
void GWInit(void); // save.h
void GWMgRecordSet(s16 arg0, s16 arg1); // save.h
void func_80036380_36F80(Addr arg0);
void pfInit(void);
void func_8004F290_4FE90(void);
s32  func_8004FDC0_509C0(void);
void func_80050800_51400(void);
void SLCurBoxNoSet(u32 arg0);
void WipeInit(void);
void* memset(void *dest, int ch, unsigned int n);
void func_80050974_51574(void);
s32 print8(u16 x, u16 y, char* src);
void func_8005035C_50F5C(s32);
void func_80050ABC_516BC(void);
void GWBoardFlagClear(s32 flag);
void GWBoardFlagSet(s32 flag);
void SetSpaceType(s16, s32);
SpaceData* GetSpaceData(s16 arg0);
void omDelPrcObj(s32);
void func_80055670_56270(s16);
void func_800698E8_6A4E8(u8**, u8*, s32, s32);
void func_80069E68_6AA68(s32);
void func_8006A370_6AF70(s32);
void func_8000B690_C290(s32);
void func_800142A0_14EA0(s32);
void func_80037258_37E58(void);
void func_8004B340_4BF40(omObjData*);
f32 HuMathCos(f32);
f32 HuMathSin(f32);
void* HuMemMemoryAlloc(HeapNode* heap, s32 size);
void func_8005A6B0_5B2B0(void);
void func_8004CF30_4DB30(void);
void func_8001FDE8_209E8(s16);
s32 WipeCreateOut(s32, s32);
s32 WipeStatGet(void);
void func_8004A994_4B594(s32);
void func_8004AB0C_4B70C(s32);
s16 HuAudFXPlay(s32);
void HuFreeFileTemp(void*);
void* HuReadFileTemp(s32);
void func_80036414_37014(Addr);
void func_8005DDDC_5E9DC(void);
void func_8001ACDC_1B8DC(s16);
void func_80033354_33F54(s16);
void func_800525C8_531C8(s16);
void func_8005F364_5FF64(s16);
void WipeColorSet(u8, u8, u8);
void func_8005B43C_5C03C(s16, s32, s32, s32);
void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2);
void func_8005E1A8_5EDA8(s16, s16);
void func_8006022C_60E2C(s32, s32);
void func_80060394_60F94(s32, s16*, s32);
void func_80061388_61F88(s16);
void func_8001F304_1FF04(s16, s16);
void HuVecSubtract(Vec * dest, Vec * a, Vec * b);
void func_8001C92C_1D52C(s16, f32);
void HuVecAdd(Vec* out, Vec* a, Vec* b);
void func_8001C92C_1D52C(s16, f32);
s16 InitEspriteSlot(s16, s32, s32);
u16 func_8000B838_C438(s32);
void func_8000BB54_C754(s32);
void func_8000BBD4_C7D4(u16, s32, s32);
void func_8000BCC8_C8C8(u16, s32);
void func_8000C184_CD84(u16);
s32 CheckControllerRead(s16 padNum);
s32 GWContErrorGet(void);
void func_8005F524_60124(void);
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat);
void GWContErrorSet(void);
void Hu3DAnimInit(s32);
void HuAudSeqPlay(s32);

#endif
