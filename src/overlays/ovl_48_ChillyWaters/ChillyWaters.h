#include "common.h"
#include "mallocblock.h"

typedef struct RGB2 {
    s32 r;
    s32 g;
    s32 b;
} RGB2;

void MBHelpWinKill(Unk3*);
void* func_800E210C_F5D2C_shared_board(s32, s32, s32);
void MBMapScrollExec(s32);
s32 MBCameraStopCheck(void);
void MBMoveMasuSet(s32, s32, s32);
void MB1Ev_StarShuffle(void);
f32 MBVecAngleGet(Vec*);
void MBComItemDecideHookSet(void*);
void MBItemHookSet(s32, void*);
void MBMasuArrowAngleAdd(f32);
void MBMasuStarSet(s32, s16);
void func_800EBCFC_FF91C_shared_board(void*);
void MBMasuBlockTblSet(void*);
void func_800EBDAC_FF9CC_shared_board(void);
void MBObjectSetup(s32 arg0, s16 arg1, s32 arg2, s32 unused);
void MB1Ev_StarNextPos(void);
void MB1Ev_StarMasuInit(void);
void MB1_StarGuideCreateAll(void);
void MB1_TeresaGuideCreateAll(void);
void MB1_BankCoinCreateAll(void);
void func_801088B4_31E424_ChillyWaters(void);
void func_80108B24_31E694_ChillyWaters(void);
void func_80108BA4_31E714_ChillyWaters(void);
void func_80116AA0_32C610_ChillyWaters(void);
void MB1Ev_SnowmanObjMain(void);
void MB1Ev_Teresa(void);
void MB1Ev_ItemMajinLamp(void);
void MB1Ev_ItemMajinLampStar(void);
void MB1Ev_ItemWarpBlock(void);
void MB1Ev_ItemKinoko(void);
void MB1Ev_ItemShake(void);
void MB1Ev_ItemPhoneMove(void);
void MB1Ev_KSuitStart(void);
void MB1Ev_KSuitEnd(void);
void MB1Ev_ItemShopPhone(void);
void MB1Ev_ItemKoopaPhone(void);
void MB1Ev_ItemStarYoke(void);
void MB1Ev_ItemKeyManUse(void);
void MB1Ev_ItemNullUse(void);
void MB1Ev_ItemExchangeBox(void);
void MB1Ev_ItemGambleCoin(void);
void MB1Ev_ItemAfter5(void);
void MB1Ev_ItemKoopaNKinoko(void);
void MB1Ev_ItemNKinoko(void);
void MB1Ev_ItemKoopaRKinoko(void);
void MB1Ev_ItemRKinoko(void);
void MB1Ev_ItemRobBox(void);
void MB1_ComItemDecide(void);
void MBMasuEventTblAdd(void*);
void MBHatenaFuncSet(void*);
void func_800F8D6C_10C98C_shared_board(s32);
void MBStart(s32);
void MB1_ObjectSetup(void);
void MB1Ev_SnowmanStart(void);
void MB1_BankCoinHide(void);
void MB1_BankCoinCreate(s16);
void MB1Ev_BranchMain(void*, void*, void*);
void MBMoveNextMasuSet(s32, s32, s32);
void MB1Ev_After5LineShow(omObjData*);
void MB1Ev_After5NumFade(omObjData*);
void MB1Ev_After5Effect(omObjData*);
void MB1Ev_After5ItemMove(s32, s32, f32*);

extern RGB D_8011E4B8_334028_ChillyWaters[2];
extern s32 mb1_After5GrpId[4];
extern void* D_8011FB90_335700_ChillyWaters;
extern s16 D_8011FB8E_3356FE_ChillyWaters;

//size based on MB1_ObjectSetup (calls to MBItemHookSet)
//not really sure what to call this, it includes the boo event at index 0 for instance
extern void (*MBItemSubFunctions[22])(void);


extern char mb1ev_Branch3RevComTree[];
extern char mb1ev_Branch3RevMasu[];
extern char mb1ev_Branch3RevLink[];
extern char mb1ev_Branch2ComTree[]; //ai
extern char mb1ev_Branch2Masu[]; //spaces
extern char mb1ev_Branch2Link[]; //chain
extern s32 mb1_BankCoinBaseMdl;
extern s32 mb1_BankCoinMdl[10];
extern s16 D_800CE194_CED94[];
extern char mb1_CommonEventTbl[]; //unknown type
extern char mb1_TeresaEventTbl[]; //unknown type
extern char mb1_TurnStatusEventTbl[]; //unknown type
extern char mb1_SpecialEventTbl[]; //unknown type
extern s16 mb1ev_StarGuideMasu[8];
extern s32 D_8011D31C_332E8C_ChillyWaters; //unknown type
extern s32 D_8011D320_332E90_ChillyWaters; //unknown type
extern s16 mb1ev_StarFlag[8];
extern s16 mb1ev_StarMasu[8];
extern Unk3* mb1_BranchStickHelp;           // used with direction arrows
extern Unk3* mb1_BranchBtnHelp;           // used with direction arrows
extern Unk3* mb1_BranchMapScrollHelp;           // used with direction arrows
extern Unk3* mb1_BranchMapOverheadHelp;           // used with direction arrows
extern Unk3* mb1_BranchItemHelp;           // used with direction arrows