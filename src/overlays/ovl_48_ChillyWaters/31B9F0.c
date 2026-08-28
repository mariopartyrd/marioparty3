#include "ChillyWaters.h"
#include "../ovl_80_shared_board/ovl_80.h"

#define GET_STAR_MODEL() D_8011FA78_3355E8_ChillyWaters[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]

typedef struct UnkStar {
/* 0x00 */ char unk_00[8];
/* 0x08 */ Vec pos;
} UnkStar; //sizeof?

typedef struct UnkStarWork {
    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ Vec unk_0C;
} UnkStarWork; /* size >= 0x18 */

typedef struct DecisionTreeNonLeafNode {
    u8 type;
    union {
        s32 (*func) ();
        u32 data;
        s32 signed_data;
        u16 data_u16[2];
        u8 data_u8[4];
        s8 data_s8[4];
    } node_data1;
    union {
        u32 data;
        struct DecisionTreeNonLeafNode *node_data;
        u8 data_u8[4];
    } node_data2;
} DecisionTreeNonLeafNode;
void MBMoveBackMasuSet(s16 playerNo, s16 arg1, s16 arg2);
void func_8004A918_4B518(s32);
void func_800461B4_46DB4(s16 arg0);
void MB1Ev_StarGuideIn(void);
s32 MBCameraStopCheck(void);
void MBGuideFaceSet(Object*, s32);
void func_800E6FCC_FABEC_shared_board(void);
void func_800FFF44_113B64_shared_board(void);
void func_80100130_113D50_shared_board(void);
void func_80106544_31C0B4_ChillyWaters(UnkMBGuideData*);
void func_8004A880_4B480(s32);
s32 MBPlayerStealRankGet(s32);
void func_80107620_31D190_ChillyWaters(void);
s32 func_800EF0D8_102CF8_shared_board(s32 arg0);
s16 MBComTreeExec(DecisionTreeNonLeafNode *arg0);
Object* MBModelLinkCreate(Object*); //unsure if correct signature
void MB1_StarGuideCreate(s16);
void MBKinokoEffKillHookSet(void*);
void MB1_StarGuideKill(void);
void func_800D771C_EB33C_shared_board(s32, Object*, s16, s16);
void func_800D7790_EB3B0_shared_board(s8 arg0, Vec* arg1, s16 arg2, s16 arg3);

extern s16 D_8011D364_332ED4_ChillyWaters[][2];
extern s16 D_8011D508_333078_ChillyWaters[];
extern s16 D_8011D35C_332ECC_ChillyWaters[][2];
extern s16 D_8011D504_333074_ChillyWaters[];
extern s32 D_8011D498_333008_ChillyWaters[];
extern s32 D_8011D4BC_33302C_ChillyWaters[];
extern s32 D_8011D474_332FE4_ChillyWaters[];
extern s32 D_8011D4E0_333050_ChillyWaters[];
extern s16 D_8011D36C_332EDC_ChillyWaters[][2];
extern s16 D_8011D374_332EE4_ChillyWaters[][2];
extern s16 D_8011D41C_332F8C_ChillyWaters[];
extern u8 D_8011D420_332F90_ChillyWaters[][2];
extern u32 *D_8011D45C_332FCC_ChillyWaters[];
extern Object *D_8011FB40_3356B0_ChillyWaters;
extern Object *D_8011FB44_3356B4_ChillyWaters[];
extern Process* D_8011FA98_335608_ChillyWaters[8];
extern Object* D_8011FA70_3355E0_ChillyWaters;
extern s16 D_8011D38C_332EFC_ChillyWaters[8];
extern s16 D_8011D334_332EA4_ChillyWaters[][2];
extern s16 D_8011D37C_332EEC_ChillyWaters[];
extern Object* D_8011FB58_3356C8_ChillyWaters;
extern s32 D_8011FAD4_335644_ChillyWaters;
extern s32 D_8011FAD8_335648_ChillyWaters;
extern s32 D_8011D2D0_332E40_ChillyWaters[];
extern s32 D_8011D2EC_332E5C_ChillyWaters[];
extern Object* D_8011FA78_3355E8_ChillyWaters[];
extern Process* D_8011FAB8_335628_ChillyWaters;
extern Object* D_8011FABC_33562C_ChillyWaters;
extern s16 mb1ev_StarGuideMasu[];
extern s32 D_8011D308_332E78_ChillyWaters;
extern s16 mbDlgWinId;
extern Object* D_8011FB0C_33567C_ChillyWaters[];
extern Object* D_8011FB08_335678_ChillyWaters;
extern s16 D_8011D39C_332F0C_ChillyWaters[];
extern s16 D_8011D354_332EC4_ChillyWaters[][2];
extern s16 D_8011D3A0_332F10_ChillyWaters[];
extern Vec D_8011D3A4_332F14_ChillyWaters[5];
extern Vec D_8011D3E0_332F50_ChillyWaters[];
extern char D_8011D7F4_333364_ChillyWaters[];
extern char D_8011DC00_333770_ChillyWaters[];
extern char D_8011DC14_333784_ChillyWaters[];
extern char D_8011D854_3333C4_ChillyWaters[];
extern char D_8011DC48_3337B8_ChillyWaters[];
extern char D_8011DC5C_3337CC_ChillyWaters[];
extern char D_8011D884_3333F4_ChillyWaters[];
extern char D_8011DC90_333800_ChillyWaters[];
extern char D_8011DCA4_333814_ChillyWaters[];
extern char D_8011D8B4_333424_ChillyWaters[];
extern char D_8011DCD8_333848_ChillyWaters[];
extern char D_8011DCEC_33385C_ChillyWaters[];
extern char D_8011D8E4_333454_ChillyWaters[];
extern char D_8011DD20_333890_ChillyWaters[];
extern char D_8011DD34_3338A4_ChillyWaters[];
extern char D_8011D914_333484_ChillyWaters[];
extern char D_8011DD68_3338D8_ChillyWaters[];
extern char D_8011DD7C_3338EC_ChillyWaters[];
extern char D_8011D944_3334B4_ChillyWaters[];
extern char D_8011DDB0_333920_ChillyWaters[];
extern char D_8011DDC4_333934_ChillyWaters[];

// Get toad space index for current start space index.
s16 MB1Ev_StarGuideMasuGet(void) {
    return mb1ev_StarGuideMasu[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]];
}

void MB1Ev_StarShuffle(void) {
    s32 temp;
    s32 a;
    s32 b;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = rand8() & (STAR_POSITIONS_TOTAL-1);
        b = rand8() & (STAR_POSITIONS_TOTAL-1);
        if (a != b) {
            if (a >= D_8011D290_332E00_ChillyWaters[b]) {
                if (b >= D_8011D290_332E00_ChillyWaters[a]) {
                    temp = D_8011D280_332DF0_ChillyWaters[a];
                    D_8011D280_332DF0_ChillyWaters[a] = D_8011D280_332DF0_ChillyWaters[b];
                    D_8011D280_332DF0_ChillyWaters[b] = temp;

                    temp = D_8011D290_332E00_ChillyWaters[a];
                    D_8011D290_332E00_ChillyWaters[a] = D_8011D290_332E00_ChillyWaters[b];
                    D_8011D290_332E00_ChillyWaters[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < STAR_POSITIONS_TOTAL; i++) {
        system->star_spawn_indices[i] = D_8011D280_332DF0_ChillyWaters[i];
    }
}

void MB1Ev_StarNextPos(void) {
    s32 temp_s0;
    s32 temp_v1;
    GW_SYSTEM* system = &GwSystem;

    if (++system->current_star_spawn >= STAR_POSITIONS_TOTAL) {
        temp_s0 = system->star_spawn_indices[STAR_POSITIONS_TOTAL-1];
        system->current_star_spawn = 0;
        GWBoardFlagSet(4);
        MB1Ev_StarShuffle();
        if (temp_s0 == system->star_spawn_indices[0]) {
            temp_s0 = system->star_spawn_indices[0];
            system->star_spawn_indices[0] = system->star_spawn_indices[STAR_POSITIONS_TOTAL-1];
            system->star_spawn_indices[STAR_POSITIONS_TOTAL-1] = temp_s0;
        }
    }
}

void MB1Ev_StarMasuInit(void) {
    GW_SYSTEM *system = &GwSystem;
    s32 i;
    for (i = 0; i < STAR_POSITIONS_TOTAL; i++) {
        GWBoardFlagSet(mb1ev_StarFlag[i]);
    }

    MBMasuTypeSet(mb1ev_StarMasu[system->star_spawn_indices[system->current_star_spawn]], 0xE);
    GWBoardFlagClear(mb1ev_StarFlag[system->star_spawn_indices[system->current_star_spawn]]);
}

s32 MB1Ev_StarCheck(s16 arg0) {
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    for (i = 0; i < STAR_POSITIONS_TOTAL; i++) {
        if (arg0 == mb1ev_StarMasu[i]) {
            if (i == system->star_spawn_indices[system->current_star_spawn]) {
                system->unk_0E = mb1ev_StarFlag[i];
                return 1;
            }
            break;
        }
    }
    return 0;
}

void MB1Ev_StarGuideIn(void) {
    UnkStar *unkStar;
    Object *star;
    s32 light;
    f32 scale;
    f32 angle;
    f32 speed;
    s32 i;

    unkStar = HuPrcCurrentGet()->user_data;

    HuAudFXPlay(0x11B);
    star = D_8011FABC_33562C_ChillyWaters = MBModelCreate(0x3A, NULL);
    func_800461B4_46DB4(star->omObj1->model[0]);
    star->flags |= 4;
    func_800ECC54_100874_shared_board(star);
    HuVecCopy3F(&star->coords, &unkStar->pos);
    star->velocity.x = 50.0f;

    light = func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(light, 2.0f, 20.0f, 1.0f);
    func_8000D018_DC18(light, 30.0f);
    func_8000CFA4_DBA4(light, star->coords.x, star->coords.y + star->velocity.x, star->coords.z);
    func_8001C8A8_1D4A8(light, 1);

    scale = 0.0f;

    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        func_8000D018_DC18(light, scale * 30.0f);
        HuPrcVSleep();
    }

    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        func_8000D018_DC18(light, scale * 30.0f);
        HuPrcVSleep();
    }

    func_8000D018_DC18(light, scale * 30.0f);

    HuPrcSleep(30);
    HuAudFXPlay(0x132);

    angle = 0.0f;
    while (1) {
        func_8008A2A0_8AEA0(HmfModelData[star->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        if (scale > 0.6f) {
            scale -= 0.04f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);

        if (star->velocity.x > 10.0f) {
            star->velocity.x -= 1.2f;
        }

        func_8000D018_DC18(light, scale * 30.0f);
        func_8000CFA4_DBA4(light, star->coords.x, star->coords.y + star->velocity.x, star->coords.z);

        if ((star->velocity.x <= 10.0f) && (scale <= 0.6f) && (angle == 0.0f)) {
            break;
        }
        HuPrcVSleep();
    }

    func_8008A2A0_8AEA0(HmfModelData[star->omObj1->model[0]].mtx, 0.0f);
    func_8000D044_DC44(light);
    D_8011FAB8_335628_ChillyWaters = 0;
    omDelPrcObj(NULL);
}

void func_80106544_31C0B4_ChillyWaters(UnkMBGuideData* arg0) {
    Object* obj;

    obj = arg0->obj;
    obj->velocity.y = 4.0f;
    obj->velocity.z = -0.6f;
    
    HuPrcSleep(3);
    while (obj->velocity.z != 0.0f) {
        HuPrcVSleep();
    }
}

void MB1Ev_StarMapView(void) {
    UnkMBGuideData *guide;
    Process *proc;
    SpaceData *space;
    s32 face;
    s32 mesNum;
    GW_SYSTEM* system = &GwSystem;

    D_800A12D4_A1ED4 = 0;
    guide = MBGuideCreate(0, 0);
    HuAudSeqPlay(0x12);
    MBGuideFaceCreate(guide->obj, 2, 0xF, D_8011D2D0_332E40_ChillyWaters[0]);
    func_800FFF44_113B64_shared_board();
    MBModelDispOff(GET_STAR_MODEL());
    WipeCreateIn(2, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    func_800E6FCC_FABEC_shared_board();
    func_800E9730_FD350_shared_board(3.0f);
    func_80106544_31C0B4_ChillyWaters(guide);

    if ((system->current_star_spawn == 0) && (GWBoardFlagCheck(4) == 0)) {
        if (system->current_board_index == 2) {
            mesNum = 0x5E09;
        } else {
            mesNum = 0x5E00;
        }
    } else {
        if (system->current_board_index == 2) {
            mesNum = 0x5E09;
        } else {
            mesNum = 0x5E01;
        }
    }
    func_8005B43C_5C03C(guide->amount, mesNum, -1, -1);
    func_80060C14_61814(guide->amount, 1);
    HuAudFXPlay(0x2A7);
    func_800EE2C0_101EE0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(guide->amount, 1);
    func_8001FDE8_209E8(guide->obj->omObj1->model[0]);

    if ((system->current_board_index != SPINY_DESERT) || (rand8() & 1)) {
        space = MBMasuGet(mb1ev_StarGuideMasu[system->star_spawn_indices[system->current_star_spawn]]);
    }

    //@bug: this can be unintialized (except not because SPINY_DESERT has different code for this)
    MBCameraPos3DSet(&space->coords);
    MBCameraSpeedSet(5.0f);
    HuPrcSleep(5);
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);

    face = MBRand(7.0f);
    MBGuideFaceSet(guide->obj, D_8011D2D0_332E40_ChillyWaters[face]);
    MBMotionSet(guide->obj, -1, 2);

    if (system->current_board_index != 2) {
        proc = omAddPrcObj(MB1Ev_StarGuideIn, 0x4800, 0, 0);
        D_8011FAB8_335628_ChillyWaters = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_8011FAB8_335628_ChillyWaters = NULL;
    }

    func_8005B43C_5C03C(guide->amount, D_8011D2EC_332E5C_ChillyWaters[face], -1, -1);
    func_80060C14_61814(guide->amount, 1);
    func_800EE2C0_101EE0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(guide->amount, 1);

    HuAudSeqFadeOut(0x5A);
    HuPrcSleep(30);
    WipeCreateOut(2, 0x10);
    HuPrcSleep(0x11);
    D_800A12D4_A1ED4 = 1;
    func_80100130_113D50_shared_board();
    func_80046558_47158(D_8011FABC_33562C_ChillyWaters->omObj1->model[0]);
    MBModelKill(D_8011FABC_33562C_ChillyWaters);
    MBModelDispOn(GET_STAR_MODEL());
    MBGuideKill(guide);
    MBExit();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void MB1Ev_StarGet(void) {
    Vec sp10;
    GW_PLAYER *player;
    Object *star;
    Object *playerObj;
    Vec *coords;
    UnkStarWork *work;
    s32 light;
    f32 scale;
    f32 angle;
    s32 i;

    work = HuPrcCurrentGet()->user_data;
    player = MBPlayerGet(CUR_PLAYER);

    HuAudFXPlay(0x11B);
    star = MBModelCreate(0x1A, NULL);
    star->flags |= 4;
    func_800ECC54_100874_shared_board(star);

    if (MBMasuLinkMasuIdGet(MBPlayerGet(CUR_PLAYER)->clink, MBPlayerGet(CUR_PLAYER)->cidx) == 0x92) {
        HuVecCopyXYZ(&star->coords, work->unk_0C.x, work->unk_0C.y + 10.0f, work->unk_0C.z);
        HuVecCopyXYZ(&sp10, gCameraList->pos.x, gCameraList->pos.y, gCameraList->pos.z);
        star->velocity.x = 15.0f;
    } else {
        HuVecCopyXYZ(&star->coords, work->unk_0C.x, work->unk_0C.y + 10.0f, work->unk_0C.z + 30.0f);
        HuVecCopyXYZ(&sp10, gCameraList->pos.x, gCameraList->pos.y, gCameraList->pos.z);
        star->velocity.x = 35.0f;
    }

    light = func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(light, 1.0f, 20.0f, 1.0f);
    func_8000D018_DC18(light, 15.0f);
    func_8001C8A8_1D4A8(light, 1);
    func_8000CFA4_DBA4(light, star->coords.x, star->coords.y + star->velocity.x, star->coords.z);

    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        func_8000D018_DC18(light, scale * 15.0f);
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        func_8000D018_DC18(light, scale * 15.0f);
        HuPrcVSleep();
    }
    func_8000D018_DC18(light, scale * 15.0f);

    HuPrcSleep(20);
    HuAudFXPlay(0x132);

    angle = 0.0f;
    playerObj = player->player_obj;
    HuVecCopyXYZ(&sp10, playerObj->coords.x, playerObj->coords.y - 10.0f, playerObj->coords.z);
    coords = &star->coords;
    MBPlayerPosMoveCreate(coords, &sp10, coords, 40);

    for (i = 0; i < 40; i++) {
        func_8008A2A0_8AEA0(HmfModelData[star->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        func_8000D018_DC18(light, scale * 15.0f);
        func_8000CFA4_DBA4(light, star->coords.x, star->coords.y + star->velocity.x, star->coords.z);
        HuPrcVSleep();
    }

    MBModelKill(star);
    func_8000D044_DC44(light);
    MBVecForwardSet(&player->player_obj->rot);
    MBPlayerVibrate(-1, 5);

    if (D_8011D308_332E78_ChillyWaters != 0) {
        func_8004A670_4B270(0xE);
    } else {
        HuAudSeqPlay(0x6F);
    }

    GwPlayer[GwSystem.current_player_index].star++;
    if (GwPlayer[GwSystem.current_player_index].star >= 100) {
        GwPlayer[GwSystem.current_player_index].star = 99;
    }

    MBPlayerMotionSet(-1, 6, 0);
    func_8004ACE0_4B8E0(0x262, GwSystem.current_player_index);

    if (D_8011D308_332E78_ChillyWaters != 0) {
        HuPrcSleep(0x10);
        func_80003A70_4670(D_800CDBC8_CE7C8);
        func_8004A918_4B518(0x6F);
        func_8004A880_4B480(0);
        HuPrcSleep(0x6E);
        func_80003B70_4770(D_800CDBC8_CE7C8, 0);
        func_8004A72C_4B32C(0xF);
    } else {
        HuPrcSleep(60);
    }
    omDelPrcObj(NULL);
}

void func_80106EEC_31CA5C_ChillyWaters(s32 arg0) {
    Process* temp_v0;

    mbItemBtnF = 0;
    temp_v0 = omAddPrcObj(MB1Ev_StarGet, 0x4800U, 0, 0);
    temp_v0->user_data = (void*)arg0;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0);
    HuPrcChildWait();
    mbItemBtnF = 1;
}

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

s32 func_8011CE94_332A04_ChillyWaters(void);
s32 func_8011D1F8_332D68_ChillyWaters(void);

s32 MB1_ComShopItemChoice(u8 *arg0) {
    s32 count = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    s32 i;
    s32 j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                count = func_8011CE94_332A04_ChillyWaters();
                sp18[GwPlayer[GwSystem.current_player_index].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (count != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 9; i++) {
        if (arg0[i] == 0) {
            func_8006010C_60D0C(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8005E1D8_5EDD8(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
        if (arg0[i] != 0) {
            return i;
        }        
    }
}

void MB1_ComShopEnterChoice(void) {
    s32 count = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    s32 i;
    s32 j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                count = func_8011D1F8_332D68_ChillyWaters();
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (count != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    func_8005E1D8_5EDD8(mbDlgWinId, 0, 1);
}


extern s32 D_8011FAD4_335644_ChillyWaters;

void func_80107620_31D190_ChillyWaters(void) {
    s32 current;
    s32 i;
    s32 j;

    current = GwSystem.current_player_index;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((i != current) && (GwPlayer[i].star != 0)) {
            break;
        }
    }

    if (i != MB_MAX_PLAYERS) {
        if (GwPlayer[current].coin >= 50) {
            if (MBRand(100.0f) < (GwPlayer[current].coin + 10)) {
                D_8011FAD4_335644_ChillyWaters = 1;
                if (GwPlayer[current].star < 99) {
                    return;
                }
            }
        }
    }

    for (j = 0; j < MB_MAX_PLAYERS; j++) {
        if ((j != current) && (GwPlayer[j].coin >= 5)) {
            break;
        }
    }

    if (j != MB_MAX_PLAYERS) {
        D_8011FAD4_335644_ChillyWaters = 0;
        return;
    }
    D_8011FAD4_335644_ChillyWaters = 2;
}

void func_80107750_31D2C0_ChillyWaters(void) {
    s32 sp10[MB_MAX_PLAYERS];
    s32 current;
    s32 target;
    s32 rank;
    s32 i;

    current = GwSystem.current_player_index;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        sp10[i] = -1;
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        rank = MBPlayerStealRankGet(i);
        while (1) {
            if (sp10[rank] == -1) {
                break;
            }
            rank++;
        }
        sp10[rank] = i;
    }

    func_80107620_31D190_ChillyWaters();

    if (D_8011FAD4_335644_ChillyWaters == 1) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            target = sp10[i];
            if ((target != current) && (GwPlayer[target].star != 0)) {
                D_8011FAD8_335648_ChillyWaters = target;
                break;
            }
        }
    } else if (D_8011FAD4_335644_ChillyWaters == 0) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            target = sp10[i];
            if ((target != current) && (GwPlayer[target].coin >= 5)) {
                D_8011FAD8_335648_ChillyWaters = target;
                break;
            }
        }
    }

    if (i == MB_MAX_PLAYERS) {
        D_8011FAD4_335644_ChillyWaters = 2;
    }
}

s32 MB1_ComTeresaChoice(u8 *arg0, s32 arg1, s32 arg2) {
    s32 pct;
    s32 ret;
    s16 sel;
    s32 i;
    s32 j;
    s32 count = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                if (arg1 == 0) {
                    func_80107750_31D2C0_ChillyWaters();
                    count = D_8011FAD4_335644_ChillyWaters + 1;
                } else {
                    count = D_8011FAD8_335648_ChillyWaters + 1;
                }
                sp18[GwPlayer[GwSystem.current_player_index].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (count != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0[i] == 0) {
            func_8006010C_60D0C(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8005E1D8_5EDD8(mbDlgWinId, i, arg2);
        if (arg2 == 0) {
            if (i == -1) {
                return -1;
            }
        }

        if (arg0[i] != 0) {
            return i;
        }        
    }
}

s32 MB1_ComTeresaTypeChoice(u8* arg0) {
    return MB1_ComTeresaChoice(arg0, 0, 1);
}

s32 MB1_ComTeresaPlayerChoice(u8* arg0) {
    return MB1_ComTeresaChoice(arg0, 1, 0);
}

// entrypoint 0
void MB1_BoardInit(void) {
    GwSystem.current_board_index = 0;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x47, 0, 0x192);
}

// entrypoint 1
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
    SpaceData *space;
    s32 i;

    omInitObjMan(0xA0, 0x28);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(2, 0xC8, 0xC8, 0xC8);
    MBObjectSetup(3, 0x23A, 5, 0);
    MBMasuBlockTblExtSet(&D_8011D31C_332E8C_ChillyWaters);
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
    MBItemHookSet(0, &MB1Ev_Teresa); // boo event
    MBItemHookSet(1, &MB1Ev_ItemMajinLamp); // magic lamp
    MBItemHookSet(9, &MB1Ev_ItemMajinLampStar);
    MBItemHookSet(2, &MB1Ev_ItemWarpBlock); // warp block
    MBItemHookSet(3, &MB1Ev_ItemRobBox); // plunder chest
    MBItemHookSet(4, &MB1Ev_KSuitStart); // activate bowser suit
    MBItemHookSet(5, &MB1Ev_KSuitEnd); // when landing on a space as bowser suit
    MBItemHookSet(6, &MB1Ev_ItemKinoko); // mushroom/golden mushroom/bowser suit
    MBItemHookSet(7, &MB1Ev_ItemShake); // dueling glove/boo bell (?)
    MBItemHookSet(8, &MB1Ev_ItemPhoneMove);
    MBItemHookSet(0xA, &MB1Ev_ItemNKinoko); // poison mushroom
    MBItemHookSet(0xB, &MB1Ev_ItemRKinoko); // reverse mushroom
    MBItemHookSet(0xE, &MB1Ev_ItemShopPhone);
    MBItemHookSet(0xF, &MB1Ev_ItemKoopaPhone);  // bowser phone
    MBItemHookSet(0x10, &MB1Ev_ItemStarYoke); // lucky lamp
    MBItemHookSet(0x11, &MB1Ev_ItemKeyManUse); // skeleton key throw away event
    MBItemHookSet(0x12, &MB1Ev_ItemNullUse); // boo repellant/koopa kard thrown away
    MBItemHookSet(0x13, &MB1Ev_ItemExchangeBox); // barter box
    MBItemHookSet(0x14, &MB1Ev_ItemGambleCoin); // game guy coin
    MBItemHookSet(0x15, &MB1Ev_ItemAfter5);                 // wacky watch
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

// entrypoint 2
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

// entrypoint 3
void MB1_BoardReload(void) {
    Hu3DCamInit(1);
    MB1_ObjectSetup();
    MBStart(1);
}

void MB1_StarGuideCreate(s16 arg0) {
    Object* temp_v0;
    s32 temp_s1;

    if (D_8011FA78_3355E8_ChillyWaters[arg0] == 0) {
        
        temp_v0 = MBModelCreate(0x3A, NULL);
        func_800461B4_46DB4(temp_v0->omObj1->model[0]);
        if (D_8011FA70_3355E0_ChillyWaters == NULL) {
            D_8011FA70_3355E0_ChillyWaters = temp_v0;
        }
        
        D_8011FA78_3355E8_ChillyWaters[arg0] = temp_v0;
        temp_v0->flags |= 2;
        HuVecCopyXYZ(&temp_v0->scale, 0.6f, 0.6f, 0.6f);
        temp_v0->velocity.x = 10.0f;
        D_8011FA98_335608_ChillyWaters[arg0] = func_800EDB98_1017B8_shared_board(temp_v0, 6.0f, 2.0f);
        HuVecCopy3F(&temp_v0->coords, &MBMasuGet(D_8011D37C_332EEC_ChillyWaters[arg0])->coords);
        func_800D771C_EB33C_shared_board(0xB, temp_v0, D_8011D334_332EA4_ChillyWaters[arg0][0], D_8011D334_332EA4_ChillyWaters[arg0][1]);
    }
}

void MB1_StarGuideKill(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8011FA98_335608_ChillyWaters); i++) {
        if (D_8011FA98_335608_ChillyWaters[i] != NULL) {
            omDelPrcObj(D_8011FA98_335608_ChillyWaters[i]);
            D_8011FA98_335608_ChillyWaters[i] = NULL;            
        }
    }
}

void MB1_StarGuideCreateAll(void) {
    s32 i;

    D_8011FA70_3355E0_ChillyWaters = NULL;

    for (i = 0; i < ARRAY_COUNT(D_8011D38C_332EFC_ChillyWaters); i++) {
        D_8011FA78_3355E8_ChillyWaters[i] = 0;
        D_8011FA98_335608_ChillyWaters[i] = 0;
        MBKinokoEffKillHookSet(&MB1_StarGuideKill);
        if (GWBoardFlagCheck(D_8011D38C_332EFC_ChillyWaters[i]) == 0) {
            MB1_StarGuideCreate(i);
        }
    }
}

void MB1_TeresaGuideCreate(s16 arg0) {
    Object *teresa;

    if (D_8011FB0C_33567C_ChillyWaters[arg0] == NULL) {
        if (D_8011FB08_335678_ChillyWaters == NULL) {
            teresa = MBModelCreate(0xA, NULL);
            func_8001FA68_20668(teresa->omObj1->model[0]);
            func_8001FA68_20668(teresa->omObj2->model[0]);
            D_8011FB08_335678_ChillyWaters = teresa;
        } else {
            teresa = MBModelLinkCreate(D_8011FB08_335678_ChillyWaters);
        }
        MBModelDispOff(teresa);
        D_8011FB0C_33567C_ChillyWaters[arg0] = teresa;
        teresa->flags |= 2;
        teresa->velocity.x = 15.0f;
        HuVecCopy3F(&teresa->coords, &MBMasuGet(D_8011D39C_332F0C_ChillyWaters[arg0])->coords);
        func_800D771C_EB33C_shared_board(0xA, teresa,
                                         D_8011D354_332EC4_ChillyWaters[arg0][0],
                                         D_8011D354_332EC4_ChillyWaters[arg0][1]);
    }
}

void MB1_TeresaGuideCreateAll(void) {
    s32 i;

    D_8011FB08_335678_ChillyWaters = 0;
    for (i = 0; i < 1; i++) {
        D_8011FB0C_33567C_ChillyWaters[i] = 0;
        MB1_TeresaGuideCreate(i);
    }
}

void MB1_BankCoinHide(void) {
    s32 count;
    s32 i;
    s32 bank;

    for (bank = 0; bank < 2; bank++) {
        count = (GwSystem.bank_coins + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (i = 0; i < count; i++) {
            MBModelDispOn(mb1_BankCoinMdl[(bank * 5) + i]);
        }
        for (; i < 5; i++) {
            MBModelDispOff(mb1_BankCoinMdl[(bank * 5) + i]);
        }
    }
}

void MB1_BankCoinCreate(s16 arg0) {
    Object *coin;
    Vec *pos;
    s32 bank;
    s16 slot;

    if (mb1_BankCoinMdl[arg0] == NULL) {
        if (mb1_BankCoinBaseMdl == NULL) {
            coin = MBModelCreate(0x1E, NULL);
            MBModelTempAllocFree(coin);
            mb1_BankCoinBaseMdl = coin;
        } else {
            coin = MBModelLinkCreate(mb1_BankCoinBaseMdl);
        }
        mb1_BankCoinMdl[arg0] = coin;
        coin->flags |= 2;

        bank = arg0 / 5;
        pos = &coin->coords;
        HuVecCopy3F(pos, &MBMasuGet(D_8011D3A0_332F10_ChillyWaters[bank])->coords);

        slot = arg0 % ARRAY_COUNT(D_8011D3A4_332F14_ChillyWaters);
        HuVecAdd(pos, &D_8011D3A4_332F14_ChillyWaters[slot], pos);
        coin->omObj1->rot.x = D_8011D3E0_332F50_ChillyWaters[slot].x;
        coin->omObj1->rot.z = D_8011D3E0_332F50_ChillyWaters[slot].z;
        MBModelDispOff(coin);
    }
}

void MB1_BankCoinCreateAll(void) {
    s32 i;

    mb1_BankCoinBaseMdl = NULL;
    for (i = 0; i < ARRAY_COUNT(mb1_BankCoinMdl); i++) {
        mb1_BankCoinMdl[i] = 0;
        MB1_BankCoinCreate(i);
    }
    MB1_BankCoinHide();
}

void func_80108748_31E2B8_ChillyWaters(s16 arg0) {
    Object *obj;
    SpaceData *space;
    char pad[4];

    if (D_8011FB44_3356B4_ChillyWaters[arg0] == NULL) {
        if (D_8011FB40_3356B0_ChillyWaters == NULL) {
            obj = MBModelCreate(D_8011D420_332F90_ChillyWaters[GwSystem.current_board_index][1],
                                D_8011D45C_332FCC_ChillyWaters[GwSystem.current_board_index]);
            MBModelTempAllocFree(obj);
            D_8011FB40_3356B0_ChillyWaters = obj;
        } else {
            obj = MBModelLinkCreate(D_8011FB40_3356B0_ChillyWaters);
        }
        D_8011FB44_3356B4_ChillyWaters[arg0] = obj;
        obj->flags |= 2;
        func_8001C814_1D414(obj->omObj1->model[0], 2, 1);
        HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011D41C_332F8C_ChillyWaters[arg0])->coords);

        space = MBMasuGet(D_8011D374_332EE4_ChillyWaters[arg0][0]);
        MBVecDirGet(&MBMasuGet(D_8011D374_332EE4_ChillyWaters[arg0][1])->coords,
                    &space->coords, &obj->rot);
        func_800D771C_EB33C_shared_board(0xC, obj,
                                         D_8011D36C_332EDC_ChillyWaters[arg0][0],
                                         D_8011D36C_332EDC_ChillyWaters[arg0][1]);
    }
}

void func_801088B4_31E424_ChillyWaters(void) {
    s32 i;

    D_8011FB40_3356B0_ChillyWaters = NULL;
    for (i = 0; i < 2; i++) {
        D_8011FB44_3356B4_ChillyWaters[i] = 0;
        func_80108748_31E2B8_ChillyWaters(i);
    }
}

void func_80108914_31E484_ChillyWaters(void) {
    HuPrcSleep(D_8011D4BC_33302C_ChillyWaters[GwSystem.current_board_index]);
    HuAudFXPlay(D_8011D498_333008_ChillyWaters[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_80108970_31E4E0_ChillyWaters(s32 arg0, s32 arg1) {
    MBMotionSet(D_8011FB44_3356B4_ChillyWaters[arg0], (arg1 - 1), 0);
    func_8001C814_1D414(D_8011FB44_3356B4_ChillyWaters[arg0]->omObj1->model[0], 5, 0);
    
    if (D_8011D474_332FE4_ChillyWaters[GwSystem.current_board_index] != -1) {
        HuAudFXPlay(D_8011D474_332FE4_ChillyWaters[GwSystem.current_board_index]);
    }
    
    if (D_8011D498_333008_ChillyWaters[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80108914_31E484_ChillyWaters, 0x1000U, 0, 0);
    }
}

void func_80108A38_31E5A8_ChillyWaters(void) {
    GW_SYSTEM* system = &GwSystem;
    s32 temp_s0 = (s32)HuPrcCurrentGet()->user_data;
    s32 sleepTime;

    switch (system->walk_speed) {
    case 0:
        HuPrcSleep(5);
        break;
    case 1:
        HuPrcSleep(10);
        break;
    default:
        HuPrcSleep(15);
        break;
    }
    
    func_8001C814_1D414(D_8011FB44_3356B4_ChillyWaters[temp_s0]->omObj1->model[0], 1, 4);
    
    if (D_8011D4E0_333050_ChillyWaters[GwSystem.current_board_index] != -1) {
        HuAudFXPlay(D_8011D4E0_333050_ChillyWaters[GwSystem.current_board_index]);
    }
    
    omDelPrcObj(NULL);
}

void func_80108AE8_31E658_ChillyWaters(s32 arg0) {
    omAddPrcObj(func_80108A38_31E5A8_ChillyWaters, 0x1000, 0, 0)->user_data = (void*)arg0;
}

void func_80108B24_31E694_ChillyWaters(void) {
    s32 i;

    D_8011FB40_3356B0_ChillyWaters = NULL;
    for (i = 0; i < 2; i++) {
        func_800D7790_EB3B0_shared_board(8, &MBMasuGet(D_8011D504_333074_ChillyWaters[i])->coords, D_8011D35C_332ECC_ChillyWaters[i][0], D_8011D35C_332ECC_ChillyWaters[i][1]);
    }
}

void func_80108BA4_31E714_ChillyWaters(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_800D7790_EB3B0_shared_board(9, &MBMasuGet(D_8011D508_333078_ChillyWaters[i])->coords, D_8011D364_332ED4_ChillyWaters[i][0], D_8011D364_332ED4_ChillyWaters[i][1]);
    }
}

void MB1Ev_BranchMerge(s32 masuAbsIndex, s16 arg1, s16 arg2) {
    GW_PLAYER* player = MBPlayerGet(CUR_PLAYER);

    if (MBMasuLinkMasuIdGet(player->blink, player->bidx) == masuAbsIndex) {
        MBMoveNextMasuSet(-1, arg1, arg2);
    }
}

void MB1Ev_Branch1(void) {
    MBMoveNextMasuSet(-1, 1, 6);
}

void MB1Ev_Branch1Rev(void) {
    GW_PLAYER* temp_v0 = MBPlayerGet(CUR_PLAYER);

    if (MBMasuLinkMasuIdGet(temp_v0->blink, temp_v0->bidx) == 0x6B) {
        MBMoveBackMasuSet(-1, 1, 6);
    }
}


void MB1Ev_Branch2(void) {
    MB1Ev_BranchMain(&mb1ev_Branch2Masu, &mb1ev_Branch2Link, &mb1ev_Branch2ComTree);
    omDelPrcObj(0);
}

void MB1Ev_Branch2Rev(void) {
    MB1Ev_BranchMain(D_8011DACC_33363C_ChillyWaters, D_8011DAE0_333650_ChillyWaters, D_8011D5F0_333160_ChillyWaters);
    omDelPrcObj(NULL);
}

extern char D_8011D668_3331D8_ChillyWaters[]; //ai
extern char D_8011DB14_333684_ChillyWaters[]; //spaces
extern char D_8011DB28_333698_ChillyWaters[]; //links

void MB1Ev_Branch3(void) {
    MB1Ev_BranchMain(D_8011DB14_333684_ChillyWaters, D_8011DB28_333698_ChillyWaters, D_8011D668_3331D8_ChillyWaters);
    omDelPrcObj(NULL);
}


void MB1Ev_Branch3Rev(void) {
    GW_PLAYER *player;

    player = MBPlayerGet(CUR_PLAYER);
    if ((MBMasuLinkMasuIdGet(player->blink, player->bidx) == 0x4B) && !(player->rev & FLAG_UNK_80)) {
        MBMoveNextMasuSet(-1, 0xA, 0);
        player->rev &= ~FLAG_REV;
    } else {
        MB1Ev_BranchMain(mb1ev_Branch3RevMasu, mb1ev_Branch3RevLink, mb1ev_Branch3RevComTree);
    }
    omDelPrcObj(0);
}

void func_800D6CA0_EA8C0_shared_board(UnkEA790Struct* arg0);
s32 func_800D7250_EAE70_shared_board(UnkEA790Struct*, s32);
s32 func_800D742C_EB04C_shared_board(UnkEA790Struct* arg0, s16 playerNo, s32 arg2);
s32 func_800D7518_EB138_shared_board(UnkEA790Struct* arg0);
UnkEA790Struct* func_800D76A0_EB2C0_shared_board(s16 arg0, s16* arg1);
extern DecisionTreeNonLeafNode D_8011D788_3332F8_ChillyWaters;
extern s16 D_8011DBA4_333714_ChillyWaters[];
extern s16 D_8011DBAC_33371C_ChillyWaters[];
extern s16 D_8011DBB4_333724_ChillyWaters[];
extern s16 D_8011DBC0_333730_ChillyWaters[];
extern s16 D_8011DBCC_33373C_ChillyWaters[];
extern s16 D_8011DBD8_333748_ChillyWaters[];
extern s16 D_8011DBE4_333754_ChillyWaters[];

void MB1Ev_Branch4(void) {
    GW_PLAYER *player;
    DecisionTreeNonLeafNode *tree;
    UnkEA790Struct* win;
    s32 sel;
    s32 sel2;
    s32 i;

    player = MBPlayerGet(CUR_PLAYER);
    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    MB1_BranchHelpStart();

    if (!(player->rev & 0x80)) {
        if (MBMasuLinkMasuIdGet(player->blink, player->bidx) == 0x3D) {
            player->rev &= ~1;
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBAC_33371C_ChillyWaters);
        } else {
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBA4_333714_ChillyWaters);
        }
    } else {
        switch (MBMasuLinkMasuIdGet(player->blink, player->bidx)) {
        case 0x3C:
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBB4_333724_ChillyWaters);
            break;
        case 0x57:
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBC0_333730_ChillyWaters);
            break;
        case 0x46:
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBCC_33373C_ChillyWaters);
            break;
        case 0x3D:
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBD8_333748_ChillyWaters);
            break;
        default:
            win = func_800D76A0_EB2C0_shared_board(GwSystem.current_player_index, D_8011DBE4_333754_ChillyWaters);
            break;
        }
    }

    func_800D742C_EB04C_shared_board(win, GwSystem.current_player_index, 0);

    if (MBPlayerComCheck(-1) != 0) {
        sel = MBComTreeExec(&D_8011D788_3332F8_ChillyWaters);
        for (i = 0; i < sel; i++) {
            func_800D7250_EAE70_shared_board(win, -2);
        }
        func_800D7250_EAE70_shared_board(win, -4);
    }

    sel2 = func_800D7518_EB138_shared_board(win);
    func_800D6CA0_EA8C0_shared_board(win);
    MB1_BranchHelpEnd();

    if (!(player->rev & 0x80)) {
        if (MBMasuLinkMasuIdGet(player->blink, player->bidx) == 0x3D) {
            if (sel2 == 0) {
                MBMoveNextMasuSet(-1, 7, 0);
            } else {
                MBMoveNextMasuSet(-1, 8, 0);
            }
        } else {
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 7, 0);
                break;
            case 1:
                MBMoveNextMasuSet(-1, 8, 0);
                break;
            default:
                MBMoveNextMasuSet(-1, 9, 0);
                break;
            }
        }
    } else {
        switch (MBMasuLinkMasuIdGet(player->blink, player->bidx)) {
        case 0x3C:
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 7, 0);
                break;
            case 1:
                MBMoveNextMasuSet(-1, 8, 0);
                break;
            case 2:
                MBMoveNextMasuSet(-1, 9, 0);
                break;
            default:
                MBMoveNextMasuSet(-1, 0xB, 7);
                player->rev |= 1;
                break;
            }
            break;
        case 0x57:
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 2, 6);
                break;
            case 1:
                MBMoveNextMasuSet(-1, 8, 0);
                player->rev &= ~1;
                break;
            case 2:
                MBMoveNextMasuSet(-1, 9, 0);
                player->rev &= ~1;
                break;
            default:
                MBMoveNextMasuSet(-1, 0xB, 7);
                break;
            }
            break;
        case 0x46:
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 2, 6);
                break;
            case 1:
                MBMoveNextMasuSet(-1, 7, 0);
                player->rev &= ~1;
                break;
            case 2:
                MBMoveNextMasuSet(-1, 9, 0);
                player->rev &= ~1;
                break;
            default:
                MBMoveNextMasuSet(-1, 0xB, 7);
                break;
            }
            break;
        case 0x3D:
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 2, 6);
                break;
            case 1:
                MBMoveNextMasuSet(-1, 7, 0);
                player->rev &= ~1;
                break;
            case 2:
                MBMoveNextMasuSet(-1, 8, 0);
                player->rev &= ~1;
                break;
            default:
                MBMoveNextMasuSet(-1, 0xB, 7);
                break;
            }
            break;
        default:
            switch (sel2) {
            case 0:
                MBMoveNextMasuSet(-1, 2, 6);
                player->rev |= 1;
                break;
            case 1:
                MBMoveNextMasuSet(-1, 7, 0);
                break;
            case 2:
                MBMoveNextMasuSet(-1, 8, 0);
                break;
            default:
                MBMoveNextMasuSet(-1, 9, 0);
                break;
            }
            break;
        }
    }
    omDelPrcObj(NULL);
}

void func_80109390_31EF00_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DC00_333770_ChillyWaters, D_8011DC14_333784_ChillyWaters, D_8011D7F4_333364_ChillyWaters);
    omDelPrcObj(NULL);
}

void func_801093C8_31EF38_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DC48_3337B8_ChillyWaters, D_8011DC5C_3337CC_ChillyWaters, D_8011D854_3333C4_ChillyWaters);
    omDelPrcObj(NULL);
}

void func_80109400_31EF70_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DC90_333800_ChillyWaters, D_8011DCA4_333814_ChillyWaters, D_8011D884_3333F4_ChillyWaters);
}

void func_80109430_31EFA0_ChillyWaters(void) {
    if ((MBPlayerGet(CUR_PLAYER)->rev & FLAG_UNK_80) && (mbWalkNum != 0)) {
        func_80109400_31EF70_ChillyWaters();
    }
}

void func_80109474_31EFE4_ChillyWaters(void) {
    MB1Ev_BranchMain(&D_8011DCD8_333848_ChillyWaters, &D_8011DCEC_33385C_ChillyWaters, &D_8011D8B4_333424_ChillyWaters);
}

void func_801094A4_31F014_ChillyWaters(void) {
    if ((MBPlayerGet(CUR_PLAYER)->rev & FLAG_UNK_80) && (mbWalkNum != 0)) {
        func_80109474_31EFE4_ChillyWaters();
    }
}

void func_801094E8_31F058_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DD20_333890_ChillyWaters, D_8011DD34_3338A4_ChillyWaters, D_8011D8E4_333454_ChillyWaters);
}

void func_80109518_31F088_ChillyWaters(void) {
    if ((MBPlayerGet(CUR_PLAYER)->rev & FLAG_UNK_80) && (mbWalkNum != 0)) {
        func_801094E8_31F058_ChillyWaters();
    }
}

void func_8010955C_31F0CC_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DD68_3338D8_ChillyWaters, D_8011DD7C_3338EC_ChillyWaters, D_8011D914_333484_ChillyWaters);
}

void func_8010958C_31F0FC_ChillyWaters(void) {
    if ((MBPlayerGet(CUR_PLAYER)->rev & FLAG_UNK_80) && (mbWalkNum != 0)) {
        func_8010955C_31F0CC_ChillyWaters();
    }
}

void func_801095D0_31F140_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DDB0_333920_ChillyWaters, D_8011DDC4_333934_ChillyWaters, D_8011D944_3334B4_ChillyWaters);
}

void func_80109600_31F170_ChillyWaters(void) {
    if ((MBPlayerGet(CUR_PLAYER)->rev & FLAG_UNK_80) && (mbWalkNum != 0)) {
        func_801095D0_31F140_ChillyWaters();
    }
}
extern char D_8011D974_3334E4_ChillyWaters[];
extern char D_8011DDF8_333968_ChillyWaters[];
extern char D_8011DE0C_33397C_ChillyWaters[];

void func_80109644_31F1B4_ChillyWaters(void) {
    MB1Ev_BranchMain(D_8011DDF8_333968_ChillyWaters, D_8011DE0C_33397C_ChillyWaters, D_8011D974_3334E4_ChillyWaters);
}

void func_80109674_31F1E4_ChillyWaters(void) {
    if ((MBPlayerGet(-1)->rev & 0x80) && (mbWalkNum != 0)) {
        func_80109644_31F1B4_ChillyWaters();
    }
}

void func_801096B8_31F228_ChillyWaters(void) {
    GW_PLAYER* player = MBPlayerGet(-1);

    if (MBMasuLinkMasuIdGet(player->blink, player->bidx) == 0x36) {
        MBMoveNextMasuSet(-1, 1, 0xD);
    }
}

void func_80109718_31F288_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x2E, 0xF, 0xA);
}

void func_8010973C_31F2AC_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x34, 3, 6);
}

void func_80109760_31F2D0_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x33, 15, 2);
}

void func_80109784_31F2F4_ChillyWaters(void) {
    GW_PLAYER* player = MBPlayerGet(-1);

    if (MBMasuLinkMasuIdGet(player->blink, player->bidx) != 0x8D) {
        MBMoveNextMasuSet(-1, 5, 0xB);
    }
}

void func_801097E4_31F354_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x4C, 7, 6);
}

void func_80109808_31F378_ChillyWaters() {
    MB1Ev_BranchMerge(0x59, 2, 7);
}

void func_8010982C_31F39C_ChillyWaters() {
    MB1Ev_BranchMerge(0x47, 2, 7);
}

void func_80109850_31F3C0_ChillyWaters() {
    MB1Ev_BranchMerge(0x7C, 10, 2);
}

void func_80109874_31F3E4_ChillyWaters(void) {
    GW_PLAYER* player = MBPlayerGet(-1);

    if (MBMasuLinkMasuIdGet(player->blink, player->bidx) != 0x7D) {
        MBMoveNextMasuSet(-1, 2, 7);
    }
}

void func_801098D4_31F444_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x3F, 0xE, 3);
}

void func_801098F8_31F468_ChillyWaters() {
    MB1Ev_BranchMerge(0x15, 5, 11);
}

void func_8010991C_31F48C_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x50, 0xA, 0xB);
}

void func_80109940_31F4B0_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x55, 2, 7);
}

void func_80109964_31F4D4_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x60, 0xC, 4);
}

void func_80109988_31F4F8_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x60, 0xB, 4);
}

void func_801099AC_31F51C_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x24, 0xC, 4);
}

void func_801099D0_31F540_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x44, 1, 8);
}

void func_801099F4_31F564_ChillyWaters(void) {
    GW_PLAYER* player = MBPlayerGet(-1);
    if (player->rev & 1) {
        player->rev &= ~1;
    }
}

void func_80109A28_31F598_ChillyWaters(void) {
    GW_PLAYER* player = MBPlayerGet(-1);

    MBMoveNextMasuSet(-1, 0x10, 1);
    player->rev &= ~1;
}

void func_80109A6C_31F5DC_ChillyWaters(void) {
    MB1Ev_BranchMerge(9, 0xF, 0xA);
}

void func_80109A90_31F600_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x27, 0xE, 3);
}

void func_80109AB4_31F624_ChillyWaters(void) {
    MB1Ev_BranchMerge(0x20, 0xA, 0xB);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_KeyManMasu);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109E84_31F9F4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EB4_31FA24_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EF8_31FA68_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109F54_31FAC4_ChillyWaters);

void func_8010A068_31FBD8_ChillyWaters() {
    MB1Ev_BranchMain(&D_8011E010_333B80_ChillyWaters, &D_8011E024_333B94_ChillyWaters, &D_8011DA58_3335C8_ChillyWaters);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A098_31FC08_ChillyWaters);

s32 MB1Ev_YesNoChoiceGet(DecisionTreeNonLeafNode *arg0, s32 arg1) {
    s32 count = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    s32 pct;
    s32 i;
    s32 j;

    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                switch ((s32)arg0) {
                case 0:
                    count = func_800EF0D8_102CF8_shared_board(0) + 1;
                    break;
                case 1:
                    count = func_800EF0D8_102CF8_shared_board(1) + 1;
                    break;
                case 2:
                    count = arg1 + 1;
                    break;
                default:
                    count = MBComTreeExec(arg0) + 1;
                    break;
                }
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (count != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    return func_8005E1D8_5EDD8(mbDlgWinId, 0, 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A3B8_31FF28_ChillyWaters);

void func_8010A474_31FFE4_ChillyWaters() {
    while (TRUE) {
        MBStatusItemAttrSet(GwSystem.current_player_index, MBItemSelNoGet(), 0x8000);
        HuPrcVSleep();
    }
}

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

const char D_8011F8D4_335444_ChillyWaters[] = "%d";

void MB1Ev_TeresaCoin(void) {
    Object *coin;
    Object *src;
    f32 angle;
    f32 y;

    src = HuPrcCurrentGet()->user_data;

    coin = MBModelLinkCreate(D_8011FB58_3356C8_ChillyWaters);
    HuVecCopy3F(&coin->coords, &src->coords);
    HuVecCopyXYZ(&coin->scale, 2.0f, 2.0f, 2.0f);
    coin->velocity.x = src->velocity.x + 10.0f;
    MBModelDispOn(coin);

    angle = MBRand(360.0f);
    while (1) {
        HuPrcVSleep();
        coin->velocity.x += 1.5;
        if ((src->velocity.x + 35.0f) <= coin->velocity.x) {
            break;
        }
        angle += 40.0f;
        func_8008A2A0_8AEA0(HmfModelData[coin->omObj1->model[0]].mtx, angle);
    }
    MBModelKill(coin);
    omDelPrcObj(NULL);
}

const f32 D_8011F8E0_335450_ChillyWaters[] = {
    1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.0f, 2.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 1.0f, -1.0f, 2.0f, 1.0f, 1.0f, -1.0f, 1.0f
};

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

// ItemFunctions[IFUNC_MUSHROOM]
void MB1Ev_ItemKinoko(void) {
    f32 sp18[2];
    Process *process;
    s32 i;
    GW_SYSTEM *system = &GwSystem;

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

void MB1Ev_ItemNullUse() {
    s32 i;

    HuPrcSleep(10);
    for (i = 1; i < 64; i++) {
        MBStatusItemTPLvlSet(GwSystem.current_player_index, MBItemSelNoGet(), 255.0f - (i * 3.984f));
        HuPrcVSleep();
    }

    MBStatusItemTPLvlSet(GwSystem.current_player_index, MBItemSelNoGet(), 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112C88_3287F8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112DDC_32894C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112E18_328988_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112FA8_328B18_ChillyWaters);

extern s32 D_8011FB70_3356E0_ChillyWaters;
extern s32 D_8011FB74_3356E4_ChillyWaters;

s32 func_80113364_328ED4_ChillyWaters(u8 *arg0, s32 arg1) {
    s32 count = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    s32 i;
    s32 j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                if (arg1 != 0) {
                    count = D_8011FB70_3356E0_ChillyWaters + 1;
                } else {
                    count = D_8011FB74_3356E4_ChillyWaters + 1;
                }
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (count != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0[i] == 0) {
            func_8006010C_60D0C(mbDlgWinId, i);
        }
    }

    i = 0;
    do {
        i = func_8005E1D8_5EDD8(mbDlgWinId, i, 1);
    } while (arg0[i] == 0);
    return i;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801135FC_32916C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80113708_329278_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemExchangeBox);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114590_32A100_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114650_32A1C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemGambleCoin);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_After5ItemMove);

void MB1Ev_After5LineShow(omObjData *obj) {
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

void MB1Ev_After5NumFade(omObjData *obj) {
    RGB2 sp18;
    RGB2 sp28;
    s32 i, j;

    for (i = 0; i <= 0; i++) {
        sp18.r = D_8011E4B8_334028_ChillyWaters[i].r;
        sp18.g = D_8011E4B8_334028_ChillyWaters[i].g;
        sp18.b = D_8011E4B8_334028_ChillyWaters[i].b;

        sp28.r = (D_8011E4B8_334028_ChillyWaters[i + 1].r - sp18.r) / 30;
        sp28.g = (D_8011E4B8_334028_ChillyWaters[i + 1].g - sp18.g) / 30;
        sp28.b = (D_8011E4B8_334028_ChillyWaters[i + 1].b - sp18.b) / 30;

        for (j = 0; j < 30; j++) {
            func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, sp18.r, sp18.g, sp18.b);
            sp18.r += sp28.r;
            sp18.g += sp28.g;
            sp18.b += sp28.b;
            HuPrcVSleep();
        }
        func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, D_8011E4B8_334028_ChillyWaters[i + 1].r, D_8011E4B8_334028_ChillyWaters[i + 1].g, D_8011E4B8_334028_ChillyWaters[i + 1].b);
        HuPrcSleep(0xA);
    }

    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_After5Effect);

// main function for using a wacky watch?
void MB1Ev_ItemAfter5(void) {
    s32 sp18[4];
    f32 sp28[2];
    s32 sp30;
    s32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    Process *temp_v0_4;
    f32 temp_f20;
    f32 var_f20;
    s32 temp_s0_3;
    s32 temp_s4;
    s32 temp_s7;
    void *temp_s1_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;
    s32 *temp_s0;
    void *temp_v0;
    Object *temp_v0_3;
    s32 i;
    s32 j;
    GW_SYSTEM *system = &GwSystem;
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
    temp_v0_3 = MBModelCreate(0x46, NULL);
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
    temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002, 0, 0);
    temp_v0_4->user_data = NULL;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[0] -= 76.0f;
    HuAudFXPlay(0x14D);
    MB1Ev_After5ItemMove(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002, 0, 0);
    temp_v0_4->user_data = (void *)1;
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
            temp_v0_4 = omAddPrcObj(MB1Ev_After5LineShow, 0x4002, 0, 0);
            temp_v0_4->user_data = (void *)2;
            HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
        }
        HuPrcVSleep();
    }

    temp_s0_3 = (s16)(s32)((HuMathCos(450.0f) * 80.0f) + sp38);
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
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(MB1Ev_After5NumFade, 0x4002, 0, 0));
    sp40 = 0;
    omAddPrcObj(MB1Ev_After5Effect, 0x4002, 0, 0)->user_data = &sp40;
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
    GwSystem.wackyWatchUsedState = WATCH_USED;
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

void func_80116F0C_32CA7C_ChillyWaters() {
    void *data;
    s32 i;

    i = 0x3C;
    data = HuPrcCurrentGet()->user_data;

    while (i != 0) {
        HuPrcVSleep();
        i--;
    }

    MBPlayerVibrateObjKill(data);
    omDelPrcObj(NULL);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemNKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_RKinokoTurnStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemKoopaRKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemRKinoko);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ItemRobBox);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_TuruturuMain);

void MB1Ev_Turuturu() {
    GW_PLAYER *player;

    player = MBPlayerGet(CUR_PLAYER);
    if (mbWalkNum != 0) {
        if ((player->rev & 1) == 0) {
            HuPrcSleep(0xA);
            MB1Ev_TuruturuMain();
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118AE8_32E658_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanObjMain);

void func_80118D6C_32E8DC_ChillyWaters() {
    Object *temp_a0;
    Object *temp_ret;
    Object *temp_v0;
    Object *temp_v0_2;

    temp_v0 = D_8011D318_332E88_ChillyWaters;
    if (temp_v0 == NULL) {
        temp_v0_2 = MBModelCreate(0x2E, 0);
        D_8011D318_332E88_ChillyWaters = temp_v0_2;
        MBModelTempAllocFree(temp_v0_2);
        HuVecCopy3F(&(D_8011D318_332E88_ChillyWaters->coords), &(MBMasuGet(0x81)->coords));
        temp_a0 = D_8011D318_332E88_ChillyWaters;
        temp_a0->coords.x = temp_a0->coords.x + 1.0f;
        temp_a0->coords.z = temp_a0->coords.z - 20.0f;
        temp_a0->scale.x = 1.2f;
        temp_a0->scale.z = 1.2f;
        MBModelDispOn(temp_a0);
        MBModelKill(D_8011D314_332E84_ChillyWaters);
        D_8011D314_332E84_ChillyWaters = NULL;
    }
}

void func_80118E2C_32E99C_ChillyWaters() {
    Object *temp_a0;
    Object *temp_ret;
    Object *temp_v0;
    Object *temp_v0_2;

    temp_v0 = D_8011D314_332E84_ChillyWaters;
    if (temp_v0 == NULL) {
        temp_v0_2 = MBModelCreate(0x2D, 0);
        D_8011D314_332E84_ChillyWaters = temp_v0_2;
        MBModelTempAllocFree(temp_v0_2);
        HuVecCopy3F(&(D_8011D314_332E84_ChillyWaters->coords), &(MBMasuGet(0x81)->coords));
        temp_a0 = D_8011D314_332E84_ChillyWaters;
        temp_a0->coords.x = temp_a0->coords.x + 1.0f;
        temp_a0->coords.z = temp_a0->coords.z - 20.0f;
        temp_a0->scale.x = 1.2f;
        temp_a0->scale.z = 1.2f;
        MBModelDispOn(temp_a0);
        MBModelKill(D_8011D318_332E88_ChillyWaters);
        D_8011D318_332E88_ChillyWaters = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanRoll);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanPathGet);

s32 func_80119A20_32F590_ChillyWaters(s32 arg0) {
    s32 temp_s1;

    temp_s1 = MB1Ev_SnowmanPathGet(arg0++);
    return temp_s1 + MB1Ev_SnowmanPathGet(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119A60_32F5D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119B3C_32F6AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119C54_32F7C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_ActionTimeSpr);

void func_8011A764_3302D4_ChillyWaters() {
    Object *temp_v0;

    temp_v0 = MBModelCreate(0x36, 0);
    D_8011FAEC_33565C_ChillyWaters = temp_v0;
    MBModelDispOff(temp_v0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A794_330304_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A838_3303A8_ChillyWaters);

void func_8011A8B8_330428_ChillyWaters() {
    MBModelKill(D_8011FAEC_33565C_ChillyWaters);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_SnowmanStart);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Snowman);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BBA4_331714_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD48_3318B8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD8C_3318FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BF3C_331AAC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1Ev_Lake);

// entrypoint 4
void MB1Ev_OpStarMapView() {
    Hu3DCamInit(2);
    CameraScissorSet(1, &D_8011E8B8_334428_ChillyWaters);
    MB1_ObjectSetup();
    MBStart(2);
    omAddPrcObj(MB1Ev_StarMapView, 0x1005, 0x1000, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C5E0_332150_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C68C_3321FC_ChillyWaters);

s32 func_8011C750_3322C0_ChillyWaters() {
    s32 temp_s0;
    s32 phi_v1;
    GW_SYSTEM *loc;
    loc = &GwSystem;

    temp_s0 = loc->total_turns - loc->current_turn + 1;

    phi_v1 = MBItemFindEmpty(-1);
    if (phi_v1 == -1) {
        phi_v1 = 3;
    }

    return (phi_v1 < temp_s0) ? 0 : 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C7A4_332314_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", MB1_ComItemDecide);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011CE94_332A04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011D1F8_332D68_ChillyWaters);
