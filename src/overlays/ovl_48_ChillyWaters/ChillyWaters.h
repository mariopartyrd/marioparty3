#include "common.h"
#include "mallocblock.h"
#include "game/board.h"

typedef struct RGB2 {
    s32 r;
    s32 g;
    s32 b;
} RGB2;

// void MBHelpWinKill(Unk3*);
// Unk3* func_800E210C_F5D2C_shared_board(s16 arg0, s16 arg1, u8 arg2);
// void MBMapScrollExec(s32);
// s32 MBCameraStopCheck(void);
// void MBMoveMasuSet(s32, s32, s32);
// void MBStatusItemAttrSet(s32, s32, s32);
// f32 MBVecAngleGet(Vec*);
// void MBComItemDecideHookSet(void*);
// void MBItemHookSet(s32, void*);
// void MBMasuArrowAngleAdd(f32);
// void MBMasuStarSet(s32, s16);
// void MBMasuBlockTblExtSet(s16*);
// void MBMasuBlockTblSet(s16*);
// void func_800EBDAC_FF9CC_shared_board(void);
// void MBObjectSetup(s32 arg0, s16 arg1, s32 arg2, s32 unused);
// void MBMasuEventTblAdd(event_table_entry*);
// void MBHatenaFuncSet(void*);
// void func_800F8D6C_10C98C_shared_board(s32);
// void MBStart(s32);
// void MBMoveNextMasuSet(s16 playerNo, s16 arg1, s16 arg2);

void MB1Ev_StarShuffle(void);
void MB1Ev_StarNextPos(void);
void MB1Ev_StarMasuInit(void);
void MB1Ev_StarMapView(void);
void MB1_StarGuideCreateAll(void);
void MB1_TeresaGuideCreateAll(void);
void MB1_BankCoinCreateAll(void);
void func_801088B4_31E424_ChillyWaters(void);
void func_80108B24_31E694_ChillyWaters(void);
void func_80108BA4_31E714_ChillyWaters(void);
void MB1Ev_BranchMerge(s32 masuAbsIndex, s16 arg1, s16 arg2);
void func_80116AA0_32C610_ChillyWaters(void);
void MB1Ev_TuruturuMain(void);
void MB1Ev_SnowmanObjMain(void);
s32 MB1Ev_SnowmanPathGet(s32);
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
void MB1_ObjectSetup(void);
void MB1Ev_SnowmanStart(void);
void MB1_BankCoinHide(void);
void MB1_BankCoinCreate(s16);
void MB1Ev_BranchMain(void*, void*, void*);
void MB1Ev_After5LineShow(omObjData*);
void MB1Ev_After5NumFade(omObjData*);
void MB1Ev_After5Effect(omObjData*);
void MB1Ev_After5ItemMove(s32, s32, f32*);
s32 func_8011CE94_332A04_ChillyWaters(void);
s32 func_8011D1F8_332D68_ChillyWaters(void);
s32 MB1Ev_YesNoChoiceGet(DecisionTreeNonLeafNode *arg0, s32 arg1);

extern s32 mbWalkNum;
extern RGB D_8011E4B8_334028_ChillyWaters[2];
extern s32 mb1_After5GrpId[4];
extern void* D_8011FB90_335700_ChillyWaters;
extern s16 D_8011FB8E_3356FE_ChillyWaters;
extern Object *D_8011D314_332E84_ChillyWaters;
extern Object *D_8011D318_332E88_ChillyWaters;

extern char mb1ev_Branch3RevComTree[];
extern char mb1ev_Branch3RevMasu[];
extern char mb1ev_Branch3RevLink[];
extern char mb1ev_Branch2ComTree[]; //ai
extern char mb1ev_Branch2Masu[]; //spaces
extern char mb1ev_Branch2Link[]; //chain

extern char D_8011DACC_33363C_ChillyWaters[]; //spaces
extern char D_8011DAE0_333650_ChillyWaters[]; //chain
extern char D_8011D5F0_333160_ChillyWaters[]; //ai

extern Object* mb1_BankCoinBaseMdl;
extern Object* mb1_BankCoinMdl[10];
extern omObjData *D_800CE194_CED94;
extern char D_8011E010_333B80_ChillyWaters[]; // spaces
extern char D_8011E024_333B94_ChillyWaters[]; // chain
extern char D_8011DA58_3335C8_ChillyWaters[]; // ai
extern event_table_entry mb1_CommonEventTbl[]; //unknown type
extern event_table_entry mb1_TeresaEventTbl[]; //unknown type
extern event_table_entry mb1_TurnStatusEventTbl[]; //unknown type
extern event_table_entry mb1_SpecialEventTbl[]; //unknown type
extern RectF D_8011E8B8_334428_ChillyWaters;
extern s16 mb1ev_StarGuideMasu[8];
extern s16 D_8011D31C_332E8C_ChillyWaters; //unknown type
extern s16 D_8011D320_332E90_ChillyWaters[]; //unknown type

extern s16 mb1ev_StarFlag[STAR_POSITIONS_TOTAL];
extern s16 mb1ev_StarMasu[STAR_POSITIONS_TOTAL];
extern s16 D_8011D280_332DF0_ChillyWaters[STAR_POSITIONS_TOTAL];
extern s16 D_8011D290_332E00_ChillyWaters[STAR_POSITIONS_TOTAL];
extern Unk3* mb1_BranchStickHelp;
extern Unk3* mb1_BranchBtnHelp;
extern Unk3* mb1_BranchMapScrollHelp;
extern Unk3* mb1_BranchMapOverheadHelp;
extern Unk3* mb1_BranchItemHelp;
extern Object *D_8011FAEC_33565C_ChillyWaters;
