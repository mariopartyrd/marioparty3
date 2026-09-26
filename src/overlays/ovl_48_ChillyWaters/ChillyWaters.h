#include "common.h"
#include "mallocblock.h"
#include "game/board.h"


void MB1Ev_StarShuffle(void);
void MB1Ev_StarNextPos(void);
void MB1Ev_StarMasuInit(void);
void MB1Ev_StarMapView(void);
void MB1_StarGuideCreateAll(void);
void MB1_TeresaGuideCreateAll(void);
void MB1_BankCoinCreateAll(void);
void func_801088B4_ChillyWaters(void);
void func_80108B24_ChillyWaters(void);
void func_80108BA4_ChillyWaters(void);
void MB1Ev_BranchMerge(s32 masuAbsIndex, s16 arg1, s16 arg2);
void func_80116AA0_ChillyWaters(void);
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
s32 MB1_ComItemDecide(void);
void MB1_ObjectSetup(void);
void MB1Ev_SnowmanStart(void);
void MB1_BankCoinHide(void);
void MB1_BankCoinCreate(s16);

typedef struct BranchLink {
    /* 0x00 */ s16 link;
    /* 0x02 */ s16 idx;
    /* 0x04 */ s16 rev;
} BranchLink; /* size 6 */

s16 MBComTreeExec(DecisionTreeNonLeafNode *arg0);
void MB1_BranchHelpEnd(void);
void MB1Ev_BranchMain(s16 (*masu)[3], BranchLink (*links)[2], DecisionTreeNonLeafNode **trees);

void MB1Ev_After5LineShow(omObjData*);
void MB1Ev_After5NumFade(omObjData*);
void MB1Ev_After5Effect(void);
void MB1Ev_After5ItemMove(s32, s32, f32*);
s32 func_8011CE94_ChillyWaters(void);
s32 func_8011D1F8_ChillyWaters(void);
s32 MB1Ev_YesNoChoiceGet(DecisionTreeNonLeafNode *arg0, s32 arg1);

extern s32 mbWalkNum;
extern RGB D_8011E4B8_ChillyWaters[2];
extern s32 mb1_After5GrpId[4];
extern void* D_8011FB90_ChillyWaters;
extern s16 D_8011FB8E_ChillyWaters;
extern Object *D_8011D314_ChillyWaters;
extern Object *D_8011D318_ChillyWaters;

extern Object* mb1_BankCoinBaseMdl;
extern Object* mb1_BankCoinMdl[10];
extern omObjData *D_800CE194_main;
extern event_table_entry mb1_CommonEventTbl[]; //unknown type
extern event_table_entry mb1_TeresaEventTbl[]; //unknown type
extern event_table_entry mb1_TurnStatusEventTbl[]; //unknown type
extern event_table_entry mb1_SpecialEventTbl[]; //unknown type
extern RectF D_8011E8B8_ChillyWaters;
extern s16 mb1ev_StarGuideMasu[8];
extern s16 D_8011D31C_ChillyWaters; //unknown type
extern s16 D_8011D320_ChillyWaters[]; //unknown type

extern s16 mb1ev_StarFlag[STAR_POSITIONS_TOTAL];
extern s16 mb1ev_StarMasu[STAR_POSITIONS_TOTAL];
extern s16 D_8011D280_ChillyWaters[STAR_POSITIONS_TOTAL];
extern s16 D_8011D290_ChillyWaters[STAR_POSITIONS_TOTAL];
extern Unk3* mb1_BranchStickHelp;
extern Unk3* mb1_BranchBtnHelp;
extern Unk3* mb1_BranchMapScrollHelp;
extern Unk3* mb1_BranchMapOverheadHelp;
extern Unk3* mb1_BranchItemHelp;
extern Object *D_8011FAEC_ChillyWaters;



extern DecisionTreeNonLeafNode *mb1ev_Branch3RevComTree[];  // ai
extern s16 mb1ev_Branch3RevMasu[][3];                       // spaces
extern BranchLink mb1ev_Branch3RevLink[][2];                // chain
extern DecisionTreeNonLeafNode *mb1ev_Branch2ComTree[];     // ai
extern s16 mb1ev_Branch2Masu[][3];                          // spaces
extern BranchLink mb1ev_Branch2Link[][2];                   // chain

extern s16 D_8011DACC_ChillyWaters[][3];             // spaces
extern BranchLink D_8011DAE0_ChillyWaters[][2];      // chain
extern DecisionTreeNonLeafNode *D_8011D5F0_ChillyWaters[];  // ai

extern s16 D_8011E010_ChillyWaters[][3];             // spaces
extern BranchLink D_8011E024_ChillyWaters[][2];      // chain
extern DecisionTreeNonLeafNode *D_8011DA58_ChillyWaters[];  // ai

extern DecisionTreeNonLeafNode *D_8011D668_ChillyWaters[];  // ai
extern s16 D_8011DB14_ChillyWaters[][3];                    // spaces
extern BranchLink D_8011DB28_ChillyWaters[][2];             // links
extern DecisionTreeNonLeafNode *D_8011D974_ChillyWaters[];
extern s16 D_8011DDF8_ChillyWaters[][3];
extern BranchLink D_8011DE0C_ChillyWaters[][2];
