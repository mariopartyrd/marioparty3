#include "ChillyWaters.h"
#include "../ovl_80_shared_board/ovl_80.h"

// Get toad space index for current start space index.
s16 MB1Ev_StarGuideMasuGet(void) {
    return mb1ev_StarGuideMasu[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarShuffle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarNextPos);

void MB1Ev_StarMasuInit(void) {
    GW_SYSTEM* system = &GwSystem;
    s32 i;
    for (i = 0; i < ARRAY_COUNT(mb1ev_StarFlag); i++) {
        GWBoardFlagSet(mb1ev_StarFlag[i]);
    }

    MBMasuTypeSet(mb1ev_StarMasu[system->star_spawn_indices[system->current_star_spawn]], 0xE);
    GWBoardFlagClear(mb1ev_StarFlag[system->star_spawn_indices[system->current_star_spawn]]);
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarGuideIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80106544_31C0B4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarMapView);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarGet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80106EEC_31CA5C_ChillyWaters);

// View board map
void MB1_MapScroll(void) {
    mbCameraBtnF = 1;
    mbItemBtnF = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    MBMapScrollExec(GwPlayer[GwSystem.current_player_index].pad);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    mbCameraBtnF = 0;
    mbItemBtnF = 1;
}

// Exit the board map?
void MB1_MapScrollCancel(void) {
    mbItemBtnF = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    MBMapScrollExec(GwPlayer[GwSystem.current_player_index].pad);
    mbItemBtnF = 1;
}

// setup arrows used during player direction decisions.
void MB1_BranchHelpStart(void) {
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    mb1_BranchStickHelp = func_800E210C_F5D2C_shared_board(0, 0x92, 1);
    mb1_BranchBtnHelp = func_800E210C_F5D2C_shared_board(1, 0xA0, 1);
    mb1_BranchItemHelp = func_800E210C_F5D2C_shared_board(0xD, 0xAE, 1);
    mb1_BranchMapScrollHelp = func_800E210C_F5D2C_shared_board(3, 0xBC, 1);
    mb1_BranchMapOverheadHelp = func_800E210C_F5D2C_shared_board(0xB, 0xCA, 1);
    HuPrcSleep(3);
    mbCameraBtnF = 1;
    D_800D51F8_D5DF8 = 1;
}

// teardown arrows
void MB1_BranchHelpEnd(void) {
    mbCameraBtnF = 0;
    D_800D51F8_D5DF8 = 0;
    MBHelpWinKill(mb1_BranchStickHelp);
    MBHelpWinKill(mb1_BranchBtnHelp);
    MBHelpWinKill(mb1_BranchItemHelp);
    MBHelpWinKill(mb1_BranchMapScrollHelp);
    MBHelpWinKill(mb1_BranchMapOverheadHelp);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComShopItemChoice);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComShopEnterChoice);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107620_31D190_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107750_31D2C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComTeresaChoice);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComTeresaTypeChoice);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComTeresaPlayerChoice);

//entrypoint 0
void MB1_BoardInit(void) {
    GwSystem.current_board_index = 0;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x47, 0, 0x192);
}

//entrypoint 1
void MB1_SaveInit(void) {
    omInitObjMan(0xA, 0);
    MBMoveMasuSet(0, 0, 0);
    MBMoveMasuSet(1, 0, 0);
    MBMoveMasuSet(2, 0, 0);
    MBMoveMasuSet(3, 0, 0);
    GWBoardFlagSet(3);
    MB1Ev_StarShuffle();
    GWBoardFlagClear(0x12);
    GwSystem.bank_coins = 0;
    GwSystem.slow_dice_flags = 0;
    GwSystem.forceShopHost = 0;
    GwSystem.boardData.halfWordBytes[1] = 0;
    omOvlReturnEx(1);
}

void MB1_ObjectSetup(void) {
    Vec sp10;
    SpaceData* space;
    s32 i;

    omInitObjMan(0xA0, 0x28);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(2, 0xC8, 0xC8, 0xC8);
    MBObjectSetup(3, 0x23A, 5, 0);
    func_800EBCFC_FF91C_shared_board(&D_8011D31C_332E8C_ChillyWaters);
    MBMasuBlockTblSet(&D_8011D320_332E90_ChillyWaters);
    space = MBMasuGet(0x77);
    MBVecDirGet(&space->coords, &MBMasuGet(0x73)->coords, &sp10);
    MBMasuArrowAngleAdd(MBVecAngleGet(&sp10) + 180.0f);
    space = MBMasuGet(0x7C);
    MBVecDirGet(&space->coords, &MBMasuGet(0x6E)->coords, &sp10);
    MBMasuArrowAngleAdd(MBVecAngleGet(&sp10) + 180.0f);
    space = MBMasuGet(0x8F);
    MBVecDirGet(&space->coords, &MBMasuGet(0x80)->coords, &sp10);
    MBMasuArrowAngleAdd(MBVecAngleGet(&sp10) + 180.0f);
    MBItemHookSet(0, &MB1Ev_Teresa); //boo event
    MBItemHookSet(1, &MB1Ev_ItemMajinLamp); //magic lamp
    MBItemHookSet(9, &MB1Ev_ItemMajinLampStar);
    MBItemHookSet(2, &MB1Ev_ItemWarpBlock); //warp block
    MBItemHookSet(3, &MB1Ev_ItemRobBox); //plunder chest
    MBItemHookSet(4, &MB1Ev_KSuitStart); //activate bowser suit
    MBItemHookSet(5, &MB1Ev_KSuitEnd); //when landing on a space as bowser suit
    MBItemHookSet(6, &MB1Ev_ItemKinoko); //mushroom/golden mushroom/bowser suit
    MBItemHookSet(7, &MB1Ev_ItemShake); //dueling glove/boo bell (?)
    MBItemHookSet(8, &MB1Ev_ItemPhoneMove);
    MBItemHookSet(0xA, &MB1Ev_ItemNKinoko); //poison mushroom
    MBItemHookSet(0xB, &MB1Ev_ItemRKinoko); //reverse mushroom
    MBItemHookSet(0xE, &MB1Ev_ItemShopPhone);
    MBItemHookSet(0xF, &MB1Ev_ItemKoopaPhone); //bowser phone
    MBItemHookSet(0x10, &MB1Ev_ItemStarYoke); //lucky lamp
    MBItemHookSet(0x11, &MB1Ev_ItemKeyManUse); //skeleton key throw away event
    MBItemHookSet(0x12, &MB1Ev_ItemNullUse); //boo repellant/koopa kard thrown away
    MBItemHookSet(0x13, &MB1Ev_ItemExchangeBox); //barter box
    MBItemHookSet(0x14, &MB1Ev_ItemGambleCoin); //game guy coin
    MBItemHookSet(0x15, &MB1Ev_ItemAfter5); //wacky watch
    MBItemHookSet(0xC, &MB1Ev_ItemKoopaNKinoko);
    MBItemHookSet(0xD, &MB1Ev_ItemKoopaRKinoko);
    MBComItemDecideHookSet(&MB1_ComItemDecide);

    for (i = 0; i < ARRAY_COUNT(mb1ev_StarGuideMasu); i++) {
        MBMasuStarSet(i, mb1ev_StarGuideMasu[i]);
    }

    if (GWBoardFlagCheck(0xE) != 0) {
        GWBoardFlagClear(0xE);
        MB1Ev_StarNextPos();
    }

    MB1Ev_StarMasuInit();
    MB1_StarGuideCreateAll();
    MB1_TeresaGuideCreateAll();
    MB1_BankCoinCreateAll();
    func_801088B4_31E424_ChillyWaters();
    func_80108B24_31E694_ChillyWaters();
    func_80108BA4_31E714_ChillyWaters();
    func_80116AA0_32C610_ChillyWaters();
    func_800EBDAC_FF9CC_shared_board();
    omAddPrcObj(MB1Ev_SnowmanObjMain, 0x4800, 0, 0);
}

//entrypoint 2
void MB1_Create(void) {
    HuAudSeqPlay(0x18);
    D_800CE194_CED94[2] = 0x18;
    func_800F8D6C_10C98C_shared_board(0x18);
    Hu3DCamInit(2);
    MB1_ObjectSetup();
    MBMasuEventTblAdd(&mb1_CommonEventTbl);
    MBMasuEventTblAdd(&mb1_SpecialEventTbl);
    MBHatenaFuncSet(&MB1Ev_SnowmanStart);
    MBMasuEventTblAdd(&mb1_TeresaEventTbl);
    MBMasuEventTblAdd(&mb1_TurnStatusEventTbl);
    MBStart(0);
}

//entrypoint 3
void MB1_BoardReload(void) {
    Hu3DCamInit(1);
    MB1_ObjectSetup();
    MBStart(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_StarGuideCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_StarGuideKill);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_StarGuideCreateAll);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_TeresaGuideCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_TeresaGuideCreateAll);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_BankCoinHide);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_BankCoinCreate);

void MB1_BankCoinCreateAll(void) {
    s32 i;

    mb1_BankCoinBaseMdl = 0;
    for (i = 0; i < ARRAY_COUNT(mb1_BankCoinMdl); i++) {
        mb1_BankCoinMdl[i] = 0;
        MB1_BankCoinCreate(i);
    }
    MB1_BankCoinHide();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108748_31E2B8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801088B4_31E424_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108914_31E484_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108970_31E4E0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108A38_31E5A8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108AE8_31E658_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108B24_31E694_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108BA4_31E714_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_BranchMerge);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Branch1);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Branch1Rev);

void MB1Ev_Branch2(void) {
    MB1Ev_BranchMain(&mb1ev_Branch2Masu, &mb1ev_Branch2Link, &mb1ev_Branch2ComTree);
    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Branch2Rev);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Branch3);

void MB1Ev_Branch3Rev(void) {
    GW_PLAYER* player;

    player = MBPlayerGet(CUR_PLAYER);
    if ((MBMasuLinkMasuIdGet(player->blink, player->bidx) == 0x4B) && !(player->rev & FLAG_UNK_80)) {
        MBMoveNextMasuSet(-1, 0xA, 0);
        player->rev &= ~FLAG_REV;
    } else {
        MB1Ev_BranchMain(mb1ev_Branch3RevMasu, mb1ev_Branch3RevLink, mb1ev_Branch3RevComTree);
    }
    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Branch4);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109390_31EF00_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801093C8_31EF38_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109400_31EF70_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109430_31EFA0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109474_31EFE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801094A4_31F014_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801094E8_31F058_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109518_31F088_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010955C_31F0CC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010958C_31F0FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801095D0_31F140_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109600_31F170_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109644_31F1B4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109674_31F1E4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801096B8_31F228_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109718_31F288_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010973C_31F2AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109760_31F2D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109784_31F2F4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801097E4_31F354_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109808_31F378_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010982C_31F39C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109850_31F3C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109874_31F3E4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801098D4_31F444_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801098F8_31F468_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010991C_31F48C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109940_31F4B0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109964_31F4D4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109988_31F4F8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099AC_31F51C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099D0_31F540_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099F4_31F564_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A28_31F598_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A6C_31F5DC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A90_31F600_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109AB4_31F624_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_KeyManMasu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109E84_31F9F4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EB4_31FA24_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EF8_31FA68_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109F54_31FAC4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A068_31FBD8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A098_31FC08_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_YesNoChoiceGet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A3B8_31FF28_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A474_31FFE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_StarMasu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_BankMasu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B394_320F04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B41C_320F8C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B484_320FF4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ShopMasu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010C914_322484_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010C9B4_322524_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010CA54_3225C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010CE9C_322A0C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_TeresaSteal);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_TeresaCoin);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_TeresaCoinCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Teresa);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F050_324BC0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F06C_324BDC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F088_324BF8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F1E4_324D54_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemMajinLamp);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemMajinLampStar);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemWarpBlock);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemMove);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemMoveCreate);

extern f32 D_8011E354_333EC4_ChillyWaters[4][2];

//ItemFunctions[IFUNC_MUSHROOM]
void MB1Ev_ItemKinoko(void) {
    f32 sp18[2];
    Process* process;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &sp18[0], &sp18[1]);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, MB1Ev_ItemMoveCreate(mbItemCursorGrpId, sp18[0], sp18[1], D_8011E354_333EC4_ChillyWaters[system->current_player_index][0], D_8011E354_333EC4_ChillyWaters[GwSystem.current_player_index][1], -1));
    HuPrcChildWait();
    HuPrcSleep(0xA);
    func_80055140_55D40(mbItemCursorGrpId, 0, 0, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);

    for (i = 1; i < 10; i++) {
        MBStatusItemTPLvlSet(system->current_player_index, MBItemSelNoGet(), (255 - (i * 25)));
        MBStatusItemOfsApply(system->current_player_index, MBItemSelNoGet(), 0, 2.0f);
        HuPrcVSleep();        
    }

    MBStatusItemTPLvlSet(system->current_player_index, MBItemSelNoGet(), 0);
    MBPlayerMotionSet(-1, 5, 0);
    func_8004ACE0_4B8E0(0x274, system->current_player_index);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010FE54_3259C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110024_325B94_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemShake);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemPhoneMove);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801106A4_326214_ChillyWaters);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", D_8011F940_3354B0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_KSuitStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_KSuitEnd);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110E08_326978_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemShopPhone);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemKoopaPhone);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemStarYoke);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemKeyManUse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801125BC_32812C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801127D8_328348_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemNullUse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112C88_3287F8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112DDC_32894C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112E18_328988_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112FA8_328B18_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80113364_328ED4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801135FC_32916C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80113708_329278_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemExchangeBox);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114590_32A100_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114650_32A1C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemGambleCoin);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_After5ItemMove);

void MB1Ev_After5LineShow(omObjData* obj) {
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 i;

    temp_s1 = (s32)HuPrcCurrentGet()->user_data;
    var_s3 = 10;

    switch (temp_s1) {
    case 0:
        func_80054904_55504(mb1_After5GrpId[temp_s1], 0, 0xB1, 0x2C);
        break;
    case 1:
        func_80054904_55504(mb1_After5GrpId[temp_s1], 0, 0x7A, 0x39);
        break;
    default:
        func_80054904_55504(mb1_After5GrpId[temp_s1], 0, 0xA0, 0x98);
        var_s3 = 30;
        break;
    }

    HuSprAttrReset(mb1_After5GrpId[temp_s1], 0, 0x8000U);
    for (i = 0; i < 255; i += 255 / var_s3) {
        func_80055458_56058(mb1_After5GrpId[temp_s1], 0, i & 0xFFFF);
        HuPrcVSleep();
    }

    func_80055458_56058(mb1_After5GrpId[temp_s1], 0, 0xFF);
    omDelPrcObj(0);
}

void MB1Ev_After5NumFade(omObjData* obj) {
    RGB2 sp18;
    RGB2 sp28;
    s32 i, j;

    for (i = 0; i <= 0; i++) {
        sp18.r = D_8011E4B8_334028_ChillyWaters[i].r;
        sp18.g = D_8011E4B8_334028_ChillyWaters[i].g;
        sp18.b = D_8011E4B8_334028_ChillyWaters[i].b;

        sp28.r = (D_8011E4B8_334028_ChillyWaters[i+1].r - sp18.r) / 30;
        sp28.g = (D_8011E4B8_334028_ChillyWaters[i+1].g - sp18.g) / 30;
        sp28.b = (D_8011E4B8_334028_ChillyWaters[i+1].b - sp18.b) / 30;

        for (j = 0; j < 30; j++) {
            func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, sp18.r, sp18.g, sp18.b);
            sp18.r += sp28.r;
            sp18.g += sp28.g;
            sp18.b += sp28.b;
            HuPrcVSleep();            
        }
        func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, D_8011E4B8_334028_ChillyWaters[i+1].r, D_8011E4B8_334028_ChillyWaters[i+1].g, D_8011E4B8_334028_ChillyWaters[i+1].b);
        HuPrcSleep(0xA);        
    }

    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_After5Effect);

//main function for using a wacky watch?
void MB1Ev_ItemAfter5(void) {
    s32 sp18[4];
    f32 sp28[2];
    s32 sp30;
    s32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    Process* temp_v0_4;
    f32 temp_f20;
    f32 var_f20;
    s32 temp_s0_3;
    s32 temp_s4;
    s32 temp_s7;
    s32 temp_s1_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;
    s32* temp_s0;
    void* temp_v0;
    Object* temp_v0_3;
    s32 i;
    s32 j;
    GW_SYSTEM* system = &GwSystem;
    s32 temp;
    
    temp_s4 = HuSprGrpCreate(1, 0);
    temp_v0 = DataRead(D_8010197C_11559C_shared_board[18]);
    temp_s7 = func_80055810_56410(temp_v0);
    DataClose(temp_v0);
    func_80055024_55C24(temp_s4, 0, temp_s7, 0);
    HuSprPriSet(temp_s4, 0, 0x4776U);
    HuSprAttrSet(temp_s4, 0, 0x1000U);
    for (i = 0; i < 4; i++) {
        mb1_After5GrpId[i] = HuSprGrpCreate(1, 0);
        temp_v0 = DataRead((i + 0x1BB) | 0x130000);
        sp18[i] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        func_80055024_55C24(mb1_After5GrpId[i], 0, sp18[i], 0);
        HuSprPriSet(mb1_After5GrpId[i], 0, 0x4780U);
        HuSprAttrSet(mb1_After5GrpId[i], 0, 0x980CU);
        func_80055458_56058(mb1_After5GrpId[i], 0, 0U);
        func_80055420_56020(mb1_After5GrpId[i], 0, 0xFF, 0xFF, 0);
    }
    temp_v0_3 = MBModelCreate(0x46, 0);
    D_8011FB90_335700_ChillyWaters = temp_v0_3;
    func_8001C258_1CE58(temp_v0_3->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(temp_v0_3->omObj1->model[0], 0x1800);
    func_8001C448_1D048(temp_v0_3->omObj1->model[0]);
    Hu3DModelScaleSet(temp_v0_3->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&temp_v0_3->coords, &MBPlayerGet(CUR_PLAYER)->player_obj->coords);
    MBModelTempAllocFree(temp_v0_3);
    MBModelDispOff(temp_v0_3);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000U);
    MBStatusItemTPLvlSet(system->current_player_index, MBItemSelNoGet(), 0);
    MBStatusItemPosGet(system->current_player_index, MBItemSelNoGet(), &sp30, &sp34);
    func_80054904_55504(temp_s4, 0, sp30, sp34);
    sp28[0] = 160.0f;
    sp28[1] = 76.0f;
    HuAudFXPlay(0x145);
    MB1Ev_After5ItemMove(temp_s4, 0x1E, sp28);
    GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] = -1;
    MBItemRemoveEmpty(system->current_player_index);
    MBStatusShrink(CUR_PLAYER);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(CUR_PLAYER);
    HuPrcSleep(0x1E);
    sp28[0] = 203.0f;
    sp28[1] = 44.0f;
    MB1Ev_After5ItemMove(temp_s4, 0xA, sp28);
    temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002U, 0, 0);
    temp_v0_4->user_data = NULL;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[0] -= 76.0f;
    HuAudFXPlay(0x14D);
    MB1Ev_After5ItemMove(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002U, 0, 0);
    temp_v0_4->user_data = (void* )1;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[1] += 64.0f;
    HuAudFXPlay(0x14D);
    MB1Ev_After5ItemMove(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    HuAudFXPlay(0x14E);
    MBStatusSprPosGet(temp_s4, 0, &sp38, &sp3C);
    for (var_f20 = 0.0f, var_s1 = 0; var_f20 < 90.0f; var_f20 += 3.6f) {
        func_80054904_55504(temp_s4, 0, ((HuMathCos((2.0f * var_f20) + 270.0f) * 80.0f) + sp38), (((1.0f - HuMathCos(var_f20)) * 90.0f) + sp3C));
        if (!(var_f20 > 54.0f)) {
            var_v1 = 0;
        } else {
            var_v1 = 1;
        }
        temp = var_v1 != 0;
        if (temp && var_s1 == 0) {
            var_s1 = 1;
            temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002U, 0, 0);
            temp_v0_4->user_data = (void* )2;
            HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
        }
        HuPrcVSleep();        
    }

    temp_s0_3 = (s16) (s32) ((HuMathCos(450.0f) * 80.0f) + sp38);
    func_80054904_55504(temp_s4, 0, temp_s0_3, (((1.0f - HuMathCos(90.0f)) * 90.0f) + sp3C));
    
    for (j = 255; j > 0; j -= 0x19, HuPrcVSleep()) {
        func_80055458_56058(temp_s4, 0, j);
    }

    HuSprGrpKill(temp_s4);
    HuSprKill(temp_s7);
    HuPrcChildWait();
    
    for (i = 0; i < 3; i++) {
        HuSprAttrSet(mb1_After5GrpId[i], 0, 0x8000);
    }

    HuSprAttrReset(D_8011FB8E_3356FE_ChillyWaters, 0, 0x8000U);
    func_80055458_56058(D_8011FB8E_3356FE_ChillyWaters, 0, 0xFFU);
    func_80054904_55504(D_8011FB8E_3356FE_ChillyWaters, 0, 0xA0, 0x78);
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(MB1Ev_After5NumFade, 0x4002U, 0, 0));
    sp40 = 0;
    omAddPrcObj(MB1Ev_After5Effect, 0x4002U, 0, 0)->user_data = &sp40;
    HuPrcChildWait();
    HuAudFXPlay(0x14F);
    temp_s1_2 = MBPlayerVibrateObjCreate(-1, 4, 5);
    
    for (i = 0; i <= 2880; i += 50) {
        temp_f20 = (HuMathSin(i) / 2.0f) + 1.0f;
        HuSprScaleSet(D_8011FB8E_3356FE_ChillyWaters, 0, temp_f20, (HuMathSin(i) / 3.0f) + 1.0f);
        if (i >= (2880 / 2 + 1)) {
            sp40 = 1;
        }
        HuPrcVSleep();        
    }
    
    HuAudFXPlay(0x129);
    WipeColorSet(0xFF, 0xFF, 0xFF);
    WipeCreateOut(0xB, 0x32);
    MBPlayerVibrateObjKill(temp_s1_2);
    
    for (var_f20 = 0.0f; WipeStatGet() != 0; var_f20 += 0.1f) {
        HuSprScaleSet(D_8011FB8E_3356FE_ChillyWaters, 0, var_f20, var_f20);
        HuPrcVSleep();
    }
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    sp40 = 2;
    for (i = 0; i < 4; i++) {
        HuSprGrpKill(mb1_After5GrpId[i]);
        HuSprKill(sp18[i]);
    }
    
    WipeCreateIn(0xB, 0x5A);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    MBDlgResultWinExec(0x3A23);
    GwSystem.unk_52 = 2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_BranchMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011667C_32C1EC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801166F4_32C264_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116758_32C2C8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116904_32C474_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116A04_32C574_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116AA0_32C610_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_NKinokoTurnStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemKoopaNKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116F0C_32CA7C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemNKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_RKinokoTurnStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemKoopaRKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemRKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemRobBox);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_TuruturuMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Turuturu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118AE8_32E658_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanObjMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118D6C_32E8DC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118E2C_32E99C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanRoll);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanPathGet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119A20_32F590_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119A60_32F5D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119B3C_32F6AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119C54_32F7C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ActionTimeSpr);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A764_3302D4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A794_330304_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A838_3303A8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A8B8_330428_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Snowman);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BBA4_331714_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD48_3318B8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD8C_3318FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BF3C_331AAC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Lake);

//entrypoint 4
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_OpStarMapView);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C5E0_332150_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C68C_3321FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C750_3322C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C7A4_332314_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComItemDecide);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011CE94_332A04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011D1F8_332D68_ChillyWaters);
