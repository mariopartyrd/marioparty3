#include "overlays/ovl_39.h"
#include "mallocblock.h"

#define PLAYERS_TOTAL 2
#define JUMPS_MAX 99

#define HAND_PLATFORM 0
#define HAND_OBSTACLE 1

#define MDL_PLATFORM 0
#define MDL_OBSTACLE 1
#define MDL_DISK_SMALL 2
#define MDL_DISK_LARGE 3

// C1F0
s32 func_8000B638_C238(void);

// 14EA0
s32 func_80017BB8_187B8(s32, s32);

// pause
void func_80045F1C_46B1C(s32, s32, s32);

// 4B120 (audio?)
void func_8004ABE8_4B7E8(s32, s32);
void func_8004AC10_4B810(s32, s32);
void func_8004AC98_4B898(s32, s16);
void func_8004AD50_4B950(s32);
void func_8004B25C_4BE5C(s16, s32, s32, s32);

// pad
extern s8 D_800CBB6E_CC76E[];
extern u16 D_800CDA7C_CE67C[];
extern s8 D_800D20A1_D2CA1[];

// ovl_82
void func_800E18D8_B4458_name_82(void);
void func_800E19F0_B4570_name_82(s32);
void func_800E1BA8_B4728_name_82(omObjData*, s32, s32, u16, s32, s32);
void func_800E4E30_B79B0_name_82(omObjData*);
void func_800E5690_B8210_name_82(omObjData*, u16);
void func_800E5A00_B8580_name_82(omObjData*, s32, s32, s32, s32);
extern s16 D_800EBE28_BE9A8_name_82;
extern s16 D_800EC1B8_BED38_name_82;
extern omObjData* D_800EC1C0_BED40_name_82;
extern u16 D_800EC280_BEE00_name_82;
extern omObjData* D_800EC598_BF118_name_82[];

// unknown
extern s32 D_800A178C[][6];

// LOCAL

typedef struct {
    /* 0x00 */ f32 clockHandRot[2];
    /* 0x08 */ f32 clockBaseSpeed[2];
    /* 0x10 */ s16 clockHandModel[2];
    /* 0x14 */ s16 tensSpriteId;
    /* 0x16 */ s16 unitsSpriteId;
    /* 0x18 */ s16 obstacleColliderId;
    /* 0x1A */ s16 obstacleProximityColliderId;
    /* 0x1C */ s16 jumpCount;
    /* 0x1E */ s16 jumpsSinceSpeedChange;
    /* 0x20 */ s16 jumpsForSpeedChange;
    /* 0x24 */ f32 clockSpeedMultiplier;
    /* 0x28 */ s8 finished;
    /* 0x29 */ char unk29[0x33];
} MinigameData; // Size 0x5C

#define PLAYER_STAT_01 1
#define PLAYER_STAT_JUMPING 2
#define PLAYER_STAT_LOST 8
#define PLAYER_STAT_WON 0x10
#define PLAYER_STAT_FROZEN 0x20
#define PLAYER_STAT_FINISHED (PLAYER_STAT_LOST | PLAYER_STAT_WON)

#define PLAYER_STATE_IDLE 0
#define PLAYER_STATE_WALK 2
#define PLAYER_STATE_JUMP 6
#define PLAYER_STATE_WON 13
#define PLAYER_STATE_KNOCKED 14
#define PLAYER_STATE_LAND 21
#define PLAYER_STATE_LOST 38

typedef struct {
    /* 0x00 */ s16 padId;
    /* 0x02 */ s16 chr;
    /* 0x04 */ s32 stat;
    /* 0x08 */ s8 updateAnimation;
    /* 0x0A */ s16 state;
    /* 0x0C */ s16 nextState;
    /* 0x0E */ char unk0E[0x12];
    /* 0x20 */ s16 resetInputGroupId;
    /* 0x22 */ s16 resetInputId;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ char unk26[0x1A];
    /* 0x40 */ ModelTracker* obstacleCollisionTracker;
    /* 0x44 */ ModelTracker* obstacleProximityTracker;
    /* 0x48 */ f32 accelY;
    /* 0x4C */ s16 comReactionDelay;
    /* 0x4E */ s16 comShortJumpBias;
    /* 0x50 */ s16 comFreezeThreshold;
    /* 0x52 */ s16 dustBillId;
    /* 0x54 */ char unk54[8];
} PlayerData; // Size 0x5C

void o39_InitEnvironment(void);
void o39_CreateMinigame(void);
void o39_CheckExitRequest(omObjData* object);
void o39_ExitOverlay(omObjData* object);
void o39_WaitExitWipeOut(omObjData* object);
void o39_InitMinigame(omObjData* object);
void o39_UpdateSystem(omObjData* object);
void o39_InitClock(omObjData* object);
void o39_UpdateClockHands(omObjData* object);
void o39_InitPlayer(omObjData* object);
void o39_UpdatePlayer(omObjData* object);
void o39_InitCamera(FuncGroupData* groupData, FuncWork* work);
void o39_CheckMinigameEnd(FuncGroupData* groupData, FuncWork* work);
void o39_ExecPlayersDraw(FuncGroupData* groupData, FuncWork* work);
void o39_ExecClockIntro(FuncGroupData* groupData, FuncWork* work);
void o39_UpdateClockSpeed(FuncGroupData* groupData, FuncWork* work);
void o39_UpdateClockObstacleRotation(FuncGroupData* groupData, FuncWork* work);
void o39_UpdateClockPlatformRotation(FuncGroupData* groupData, FuncWork* work);
f32 o39_GetRandInRange(s16 min, s16 max);
void o39_CheckPlayerJumpStart(FuncGroupData* groupData, FuncWork* work);
void o39_UpdatePlayerPosition(FuncGroupData* groupData, FuncWork* work);
void o39_UpdatePlayerRotation(FuncGroupData* groupData, FuncWork* work);
void o39_UpdatePlayerJump(FuncGroupData* groupData, FuncWork* work);
void o39_CheckPlayerCollision(FuncGroupData* groupData, FuncWork* work);
void o39_ExecPlayerIntro(FuncGroupData* groupData, FuncWork* work);
void o39_ExecPlayerWins(FuncGroupData* groupData, FuncWork* work);
void o39_ExecPlayerKnockedOut(FuncGroupData* groupData, FuncWork* work);
void o39_UpdatePlayerAnimation(FuncGroupData* groupData, FuncWork* work);
void o39_SetPlayerState(PlayerData* player, s32 state, s32 updateAnimation);
void o39_SetPlayerNextState(PlayerData* player, s32 state);
void o39_InitCom(FuncGroupData* groupData, FuncWork* work);
void o39_ResetPlayerInput(FuncGroupData* groupData, FuncWork* work);
void o39_UpdateComInput(FuncGroupData* groupData, FuncWork* work);

MinigameData* BSS o39_minigame;
PlayerData* BSS o39_players;
s16 BSS o39_playerId[PLAYERS_TOTAL];
s16 BSS o39_playerOrder[PLAYERS_TOTAL];

s16 o39_jumpEnabled = TRUE;
s16 D_8010E4A2_2C5912_tick_tock_hop = FALSE;
s16 o39_bgmStartTimer = 0;
s16 o39_bothPlayersWinState = 0;
s16 o39_playersDrawState = 0;
s16 o39_playerWinsState = 0;

const s16 D_8010E5F0_2C5A60_tick_tock_hop[] = {
    0x8272, 0x8273, 0x8260, 0x8271, 0x8273, 0x0000
};

const s16 D_8010E5FC_2C5A6C_tick_tock_hop[] = {
    0x8265, 0x8268, 0x826D, 0x8268, 0x8272, 0x8267, 0x0000, 0x0000
};

const s16 D_8010E60C_2C5A7C_tick_tock_hop[] = {
    0x8263, 0x8271, 0x8260, 0x8276, 0x0000, 0x0000
};

void o39_OverlayMain(void) {
    o39_InitEnvironment();
}

void o39_InitEnvironment(void) {
    s32 camIndex;

    Hu3DAnimInit(50);
    func_800142A0_14EA0(0x30);
    omInitObjMan(50, 0);
    func_8004A208_4AE08();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    HmfLightColorSet(0, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightDirSet(1, -56.0f, 50.0f, 56.0f);
    func_8000B5F0_C1F0(1);
    camIndex = func_8000B638_C238();
    ScissorSet(camIndex, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(camIndex, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 60.0f, 80.0f, 4000.0f);
    D_800EC1B8_BED38_name_82 = 0;
    D_800EC280_BEE00_name_82 = 0;
    D_800EBE28_BE9A8_name_82 = 0;
    o39_CreateSystem();
    o39_CreateMinigame();
    omAddObj(1000, 0, 0, -1, o39_InitMinigame);
    omAddObj(2000, 0, 0, -1, o39_CheckExitRequest);
    func_80045010_45C10(D_8010E5F0_2C5A60_tick_tock_hop, 1); // gamemes
    func_80045010_45C10(D_8010E5FC_2C5A6C_tick_tock_hop, 1);
    func_80045010_45C10(D_8010E60C_2C5A7C_tick_tock_hop, 1);
}

void o39_CreateMinigame(void) {
    s16 player1Set = FALSE;
    s16 player2Set = FALSE;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            if (!player1Set) {
                o39_playerId[0] = i;
                player1Set = TRUE;
            }
        } else if (GwPlayer[i].group == 1) {
            if (!player2Set) {
                o39_playerId[1] = i;
                player2Set = TRUE;
            }
        }
    }
    o39_minigame = HuMemAllocTag(sizeof(*o39_minigame), 31000);
    memset(o39_minigame, 0, sizeof(*o39_minigame));
    o39_players = HuMemAllocTag(PLAYERS_TOTAL * sizeof(*o39_players), 31000);
    memset(o39_players, 0, PLAYERS_TOTAL * sizeof(*o39_players));
}

void o39_CheckExitRequest(omObjData* object) {
    if (D_800D530C_D5F0C == 1) { // omSysExitReq?
        WipeCreateOut(0, 20);
        object->func = o39_WaitExitWipeOut;
    }
}

void o39_WaitExitWipeOut(omObjData* object) {
    if (WipeStatGet() == 0) {
        object->func = o39_ExitOverlay;
    }
}

void o39_ExitOverlay(omObjData* object) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void o39_UpdateCamera(void) {
    if (CRot.x > 360.0f) {
        CRot.x -= 360.0f;
    } else if (CRot.x < 0.0f) {
        CRot.x += 360.0f;
    }
    if (CRot.y > 360.0f) {
        CRot.y -= 360.0f;
    } else if (CRot.y < 0.0f) {
        CRot.y += 360.0f;
    }
    o39_UpdateFuncGroup(0);
}

void o39_InitMinigame(omObjData* object) {
    FuncWork* createCollidersWork;
    s16 createCollidersId;
    s16 i;

    func_800E18D8_B4458_name_82();
    func_800E19F0_B4570_name_82(1);
    o39_CreateFuncGroup(NULL, 0, 0, 4);
    o39_SetFunc(0, 0, NULL, o39_InitCamera, 0);
    object->work[1] = 1;
    o39_CreateFuncGroup(object, object->work[1], 0, 4);
    createCollidersId = o39_SetFunc(object->work[1], 0xFFFF, NULL, o39_CreateColliders, object->work[1]);
    createCollidersWork = &o39_funcGroups[object->work[1]].funcWork[createCollidersId];
    createCollidersWork->func(NULL, createCollidersWork);
    o39_MakeRandPermutation(o39_playerOrder, PLAYERS_TOTAL);
    for (i = 0; i < PLAYERS_TOTAL; i++) {
        D_800EC598_BF118_name_82[i] = omAddObj(300, 9, 39, -1, o39_InitPlayer);
    }
    D_800EC1C0_BED40_name_82 = omAddObj(10, 5, 0, -1, o39_InitClock);
    WipeCreateIn(0xFF, 16);
    object->func = o39_UpdateSystem;
}

void o39_UpdateSystem(omObjData* object) {
    o39_UpdateFuncGroup(1);
    o39_UpdateCamera();
    o39_UpdateSprites();
    o39_UpdateAnimModels();
    o39_UpdateBills();
}

void o39_InitClock(omObjData* object) {
    FuncGroupData* groupData;
    s32 var_s4 = 0xB9;
    s32 spriteAttr = 0x4000;
    Quad obstacleQuad = { {
        {  30.000002f, 0.0f, 100.0f },
        { -30.000002f, 0.0f, 100.0f },
        { -30.000002f, 0.0f, 400.0f },
        {  30.000002f, 0.0f, 400.0f }
    } };
    Quad obstacleProximityQuad = { {
        {  90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 400.0f },
        {  90.0f, 0.0f, 400.0f }
    } };
    f32 starAngle[] = { 35.0f, 60.0f, 120.0f, 145.0f, 215.0f, 240.0f, 300.0f, 325.0f };
    s16 id;
    s16 i;

    groupData = o39_CreateFuncGroup(object, 2, 5, 16)->data;
    groupData->modelIds[MDL_PLATFORM] = o39_minigame->clockHandModel[HAND_PLATFORM] = func_8000B108_BD08(0x5A0000, var_s4);
    groupData->modelIds[MDL_OBSTACLE] = o39_minigame->clockHandModel[HAND_OBSTACLE] = func_8000B108_BD08(0x5A0001, var_s4);
    groupData->modelIds[MDL_DISK_SMALL] = func_8000B108_BD08(0x5A0002, var_s4);
    groupData->modelIds[MDL_DISK_LARGE] = func_8000B108_BD08(0x5A0003, var_s4);
    o39_SetSpriteDispOn(o39_SetSprite(0xFFFF, 0x5A, 6, 0, spriteAttr), 160, 120);
    for (i = 0; i < 8; i++) {
        f32 starPosX = HuMathSin(starAngle[i]) * 600.0f;
        f32 starPosZ = HuMathCos(starAngle[i]) * 600.0f;

        if (i % 2 != 0) {
            // Yellow star.
            id = o39_SetAnimModel(0x5A, 5, 0.25f, ANIMMDL_ATTR_DISPON, var_s4);
        } else {
            // Red star.
            id = o39_SetAnimModel(0x5A, 4, 0.25f, ANIMMDL_ATTR_DISPON, var_s4);
        }
        o39_SetAnimModelDispOn(id, starPosX, -25.0f, starPosZ, 0.0f, 0.0f, 0.0f, 0.4f, rand16() % 31);
        func_8001C258_1CE58(o39_animModels[id].modelId, 4, 0);
    }
    o39_minigame->tensSpriteId = o39_SetSprite(0xF, 0, 0x2D, 0, 0);
    o39_minigame->unitsSpriteId = id = o39_SetSprite(0xF, 0, 0x2D, 0, 0);
    o39_SetSpriteDispOn(id, 280, 32);
    o39_minigame->clockHandRot[HAND_PLATFORM] = 270.0f;
    o39_minigame->clockHandRot[HAND_OBSTACLE] = 0.0f;
    Hu3DModelRotSet(groupData->modelIds[MDL_PLATFORM], 0.0f, o39_minigame->clockHandRot[HAND_PLATFORM], 0.0f);
    Hu3DModelRotSet(groupData->modelIds[MDL_OBSTACLE], 0.0f, o39_minigame->clockHandRot[HAND_OBSTACLE], 0.0f);
    Hu3DModelPosSet(groupData->modelIds[MDL_PLATFORM], 0.0f, 25.0f, 0.0f);
    Hu3DModelPosSet(groupData->modelIds[MDL_OBSTACLE], 0.0f, 0.0f, 0.0f);
    Hu3DModelPosSet(groupData->modelIds[MDL_DISK_SMALL], 0.0f, 30.0f, 0.0f);
    Hu3DModelPosSet(groupData->modelIds[MDL_DISK_LARGE], 0.0f, -40.0f, 0.0f);
    o39_SetFunc(2, 0xF, NULL, o39_UpdateClockPlatformRotation, 0);
    o39_SetFunc(2, 0xF, NULL, o39_UpdateClockObstacleRotation, 0);
    o39_minigame->obstacleColliderId = o39_SetCollider(groupData->modelIds[MDL_PLATFORM], &obstacleQuad, 25.0f, PLAYERS_TOTAL, COLLIDER_ATTR_DISABLED);
    o39_minigame->obstacleProximityColliderId = o39_SetCollider(groupData->modelIds[MDL_PLATFORM], &obstacleProximityQuad, 0.0f, PLAYERS_TOTAL, COLLIDER_ATTR_HEIGHT_DISABLED);
    o39_minigame->clockBaseSpeed[HAND_PLATFORM] = 0.0f;
    o39_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
    o39_minigame->finished = FALSE;
    object->model[0] = groupData->modelIds[MDL_PLATFORM];
    o39_SyncWithModel(object);
    o39_SetFunc(2, 0, NULL, o39_ExecClockIntro, 0);
    object->func = o39_UpdateClockHands;
}

void o39_UpdateClockHands(omObjData* object) {
    o39_UpdateFuncGroup(2);
    o39_SyncWithModel(object);
}

void o39_InitPlayer(omObjData* object) {
    PlayerData* player;
    s32 var_a0 = 0x2B9;
    s32 temp_a1;
    s32 temp_a2;

    object->work[0] = D_800EC280_BEE00_name_82;
    player = &o39_players[object->work[0]];
    player->chr = GwPlayer[o39_playerId[object->work[0]]].chr;
    temp_a1 = D_800A178C[player->chr][0];
    temp_a2 = D_800A178C[player->chr][1];
    func_800E1BA8_B4728_name_82(object, temp_a1, temp_a2, o39_playerId[object->work[0]], var_a0, var_a0);
    object->model[7] = func_8000B108_BD08(8, var_a0);
    func_8001C258_1CE58(object->model[7], 4, 4);
    player->dustBillId = o39_SetBill(0x57, 0x10, BILL_ATTR_01 | BILL_ATTR_ANIM | BILL_ATTR_DISPOFF);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_IDLE, func_80017BB8_187B8(player->chr, 0), 1, 0);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_WALK, func_80017BB8_187B8(player->chr, 2), 1, 0);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_JUMP, func_80017BB8_187B8(player->chr, 4), 1, 19);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_LAND, func_80017BB8_187B8(player->chr, 0x1F), 1, 999);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_WON, func_80017BB8_187B8(player->chr, 0x30), 1, 999);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_KNOCKED, func_80017BB8_187B8(player->chr, 0x1A), 1, 0);
    func_800E5A00_B8580_name_82(object, PLAYER_STATE_LOST, func_80017BB8_187B8(player->chr, 0x36), 1, 999);
    o39_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
    player->nextState = -1;
    player->padId = ((s8*) object->data)[0x57]; // TODO: figure out type.
    player->stat = PLAYER_STAT_01;
    object->rot.x = object->rot.y = object->rot.z = 0.0f;
    object->scale.x = object->scale.y = object->scale.z = 1.0f;
    D_800EC280_BEE00_name_82++;
    player->obstacleCollisionTracker = o39_SetModelTracker(o39_minigame->obstacleColliderId, object->model[0]);
    player->obstacleProximityTracker = o39_SetModelTracker(o39_minigame->obstacleProximityColliderId, object->model[0]);
    object->work[1] = 3 + object->work[0];
    o39_CreateFuncGroup(object, object->work[1], 0, 10);
    player->resetInputGroupId = object->work[1];
    player->resetInputId = o39_SetFunc(object->work[1], 0, player, o39_ResetPlayerInput, 0);
    o39_SetFunc(object->work[1], 0xF, player, o39_CheckPlayerJumpStart, 0);
    o39_SetFunc(object->work[1], 0x1F, player, o39_UpdatePlayerPosition, 0);
    o39_SetFunc(object->work[1], 0x1F, player, o39_UpdatePlayerRotation, 0);
    o39_SetFunc(object->work[1], 0xEFFF, player, o39_CheckPlayerCollision, 0);
    o39_SetFunc(object->work[1], 0xFFFF, player, o39_UpdatePlayerAnimation, 0);
    object->func = o39_UpdatePlayer;
}

void o39_UpdatePlayer(omObjData* object) {
    o39_UpdateFuncGroup(object->work[1]);
    func_800E4E30_B79B0_name_82(object);
}

void o39_InitCamera(FuncGroupData* groupData, FuncWork* work) {
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = -137.0f;
    CRot.x = 298.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    CZoom = 990.0f;
    o39_ResetFunc(0, work);
}

void o39_UpdateJumpCounterSprites(FuncGroupData* groupData, FuncWork* work) {
    s16 units = o39_minigame->jumpCount % 10;
    s16 tens = o39_minigame->jumpCount * 0.1f;

    if (tens != 0) {
        o39_SetSpriteDispOn(o39_minigame->tensSpriteId, 264, 32);
    } else {
        o39_SetSpriteDispOff(o39_minigame->tensSpriteId);
    }
    func_80054FF8_55BF8(o39_sprites[o39_minigame->tensSpriteId].groupId, 0, tens);
    func_80054FF8_55BF8(o39_sprites[o39_minigame->unitsSpriteId].groupId, 0, units);
}

void o39_ExecMinigameStart(FuncGroupData* groupData, FuncWork* work) {
    s16 i;

    if (work->state == 0) {
        work->work16[0] = 0;
        work->state = 1;
    }
    work->work16[0]++;
    switch (work->work16[0]) {
        case 5:
            func_80036C4C_3784C(6);
            HuAudFXPlay(0xE); // plays whistle fx
            o39_bgmStartTimer = 1;
            break;
        case 30:
            D_8010E4A2_2C5912_tick_tock_hop = TRUE;
            break;
        default:
            if (D_8010E4A2_2C5912_tick_tock_hop && func_80037030_37C30() == 2) {
                o39_jumpEnabled = TRUE;
                o39_minigame->clockBaseSpeed[HAND_PLATFORM] = 0.0f;
                o39_minigame->clockBaseSpeed[HAND_OBSTACLE] = 3.0f;
                for (i = 0; i < PLAYERS_TOTAL; i++) {
                    if (GwPlayer[o39_playerId[i]].stat & PLAYER_IS_CPU) {
                        o39_SetFunc(3 + i, 0, &o39_players[i], o39_InitCom, 0);
                    } else {
                        o39_ResetFunc(o39_players[i].resetInputGroupId, &o39_funcGroups[o39_players[i].resetInputGroupId].funcWork[o39_players[i].resetInputId]);
                    }
                }
                o39_SetFunc(1, 0, NULL, o39_UpdateJumpCounterSprites, 0);
                work->func = o39_CheckMinigameEnd;
            }
            break;
    }
    if (o39_bgmStartTimer != 0 && func_80037030_37C30() != 0) {
        o39_bgmStartTimer++;
        if (o39_bgmStartTimer >= 45) {
            HuAudSeqPlay(0x2F);
            o39_bgmStartTimer = 0;
        }
    }
}

void o39_ExitOverlayOnWipeOut(FuncGroupData* groupData, FuncWork* work) {
    switch (work->state) {
        case 0:
            WipeCreateOut(0, 20);
            work->state = 1;
            break;
        case 1:
            if (WipeStatGet() == 0) {
                omOvlReturnEx(1);
            }
            break;
    }
}

void o39_CheckMinigameEnd(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = o39_players;
    s16 losers[2] = { -1, -1 };
    s16 loserCount;
    f32 clockObstacleRot;
    f32 clockPlatformRot;
    s16 i;

    if (o39_minigame->jumpCount == JUMPS_MAX) {
        if (!o39_minigame->finished) {
            o39_minigame->finished = TRUE;
        }
        clockObstacleRot = HmfModelData[o39_minigame->clockHandModel[HAND_OBSTACLE]].rot.y;
        clockPlatformRot = HmfModelData[o39_minigame->clockHandModel[HAND_PLATFORM]].rot.y;
        o39_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
        if (ABS(clockObstacleRot - clockPlatformRot) > 90.0f) {
            o39_minigame->clockBaseSpeed[HAND_PLATFORM] = o39_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
            func_8004A994_4B594(0x78); // audio related
            func_80036C4C_3784C(0x11); // FINISH gamemes
            o39_SetFunc(1, 0, NULL, o39_ExecPlayersDraw, 0);
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                o39_players[i].stat |= PLAYER_STAT_LOST;
            }
            o39_ResetFunc(1, work);
        }
    } else {
        loserCount = 0;
        for (i = 0; i < PLAYERS_TOTAL; i++, player++) {
            if (player->stat & PLAYER_STAT_LOST) {
                losers[loserCount] = i;
                loserCount++;
            }
        }
        if (loserCount == 0) {
            return;
        }
        if (!o39_minigame->finished) {
            o39_minigame->finished = TRUE;
        }
        clockObstacleRot = HmfModelData[o39_minigame->clockHandModel[HAND_OBSTACLE]].rot.y;
        clockPlatformRot = HmfModelData[o39_minigame->clockHandModel[HAND_PLATFORM]].rot.y;
        o39_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
        if (ABS(clockObstacleRot - clockPlatformRot) > 90.0f) {
            o39_minigame->clockBaseSpeed[HAND_PLATFORM] = o39_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
            func_8004A994_4B594(0x78);
            func_80036C4C_3784C(0x11);
            if (loserCount == PLAYERS_TOTAL) {
                o39_ResetFunc(1, work);
                o39_SetFunc(1, 0, NULL, o39_ExecPlayersDraw, 0);
            } else {
                s16 winner = !losers[0];

                o39_players[winner].stat |= PLAYER_STAT_WON;
                o39_SetFunc(3 + winner, 0xFF, &o39_players[winner], o39_ExecPlayerWins, 0);
                o39_ResetFunc(1, work);
            }
        }
    }
}

void o39_ExecBothPlayersWin(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player1 = &o39_players[0];
    PlayerData* player2 = &o39_players[1];

    if (work->state == 0) {
        work->work16[0] = 0;
        work->state = 1;
    }
    if (o39_bothPlayersWinState == 0) {
        if (func_80037030_37C30() == 0) {
            o39_bothPlayersWinState = 1;
        }
    } else if (o39_bothPlayersWinState >= 2) {
        if (func_80037030_37C30() == 0) {
            o39_bothPlayersWinState = 3;
        }
        if (o39_bothPlayersWinState == 3) {
            work->work16[0]++;
            if (work->work16[0] >= 15) {
                o39_ResetFunc(1, work);
                o39_SetFunc(1, 0, NULL, o39_ExitOverlayOnWipeOut, 0);
            }
        }
    } else {
        work->work16[0]++;
        if (work->work16[0] == 15) {
            HuAudSeqPlay(0x67);
            o39_SetPlayerState(player1, PLAYER_STATE_WON, TRUE);
            o39_SetPlayerState(player2, PLAYER_STATE_WON, TRUE);
            func_8004AC98_4B898(0x290 + GwPlayer[o39_playerId[0]].chr, o39_playerId[0]);
            func_8004AC98_4B898(0x290 + GwPlayer[o39_playerId[1]].chr, o39_playerId[1]);
            func_80036C4C_3784C(0x1E, player1->chr, player2->chr); // gamemes.
            GwPlayer[o39_playerId[D_800EC598_BF118_name_82[0]->work[0]]].bonusCoin += 10;
            GwPlayer[o39_playerId[D_800EC598_BF118_name_82[1]->work[0]]].bonusCoin += 10;
        }
        if (func_80037030_37C30() != 0) {
            work->work16[0] = 0;
            o39_bothPlayersWinState = 2;
        }
    }
}

void o39_ExecPlayersDraw(FuncGroupData* groupData, FuncWork* work) {
    if (work->state == 0) {
        work->work16[0] = 0;
        work->state = 1;
    }
    if (o39_playersDrawState == 0) {
        if (func_80037030_37C30() == 0) { // seems to check gamemes state.
            o39_playersDrawState = 1;
        }
    } else if (o39_playersDrawState >= 2) {
        if (func_80037030_37C30() == 0) {
            o39_playersDrawState = 3;
        }
        if (o39_playersDrawState == 3) {
            work->work16[0]++;
            if (work->work16[0] >= 15) {
                o39_ResetFunc(1, work);
                o39_SetFunc(1, 0, NULL, o39_ExitOverlayOnWipeOut, 0);
            }
        }
    } else {
        work->work16[0]++;
        if (work->work16[0] == 15) {
            o39_SetPlayerState(&o39_players[0], PLAYER_STATE_LOST, TRUE);
            o39_SetPlayerState(&o39_players[1], PLAYER_STATE_LOST, TRUE);
            func_80036C4C_3784C(0x20);
            HuAudSeqPlay(0x6C);
        }
        if (func_80037030_37C30() != 0) {
            work->work16[0] = 0;
            o39_playersDrawState = 2;
        }
    }
}

void o39_ExecClockIntro(FuncGroupData* groupData, FuncWork* work) {
    s16 i;

    switch (work->state) {
        case 0:
            work->work8[0] = 0;
            work->work16[3] = 0;
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                work->work16[i] = o39_SetFunc(3 + i, 0xF, &o39_players[i], o39_ExecPlayerIntro, 0);
            }
            work->state = 1;
            break;
        case 1:
            work->work16[3]++;
            if (work->work16[3] < 30.0f) {
                return;
            }
            work->state = 2;
            HuAudFXPlay(0x4BB);
            work->work16[4] = HuAudFXPlay(0x4BC);
            func_8004ABE8_4B7E8(work->work16[4], 0);
            break;
    }
    if (work->work8[0] == 0) {
        o39_minigame->clockHandRot[HAND_OBSTACLE] -= 4.0f;
        if (o39_minigame->clockHandRot[HAND_OBSTACLE] < 0.0f) {
            o39_minigame->clockHandRot[HAND_OBSTACLE] += 360.0f;
        }
        if (o39_minigame->clockHandRot[HAND_OBSTACLE] < 180.0f) {
            func_8004AD50_4B950(work->work16[4]);
            work->work8[4] = 0;
            work->work8[0] = 1;
        }
    } else if (++work->work8[0] >= 11) {
        if (work->work8[1] == 0) {
            work->work16[4] = HuAudFXPlay(0x4BC);
            func_8004ABE8_4B7E8(work->work16[4], 0);
            HuAudFXPlay(0x4BB);
            work->work8[1] = 1;
        }
        work->work8[0] = 10;
        o39_minigame->clockHandRot[HAND_OBSTACLE] += 4.0f;
        if (o39_minigame->clockHandRot[HAND_OBSTACLE] > 360.0f) {
            o39_SetFunc(1, 0, NULL, o39_ExecMinigameStart, 0);
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                o39_ResetFunc(3 + i, &o39_funcGroups[3 + i].funcWork[work->work16[i]]);
            }
            o39_jumpEnabled = FALSE;
            o39_colliders[o39_minigame->obstacleColliderId].attr &= ~COLLIDER_ATTR_DISABLED;
            o39_colliders[o39_minigame->obstacleColliderId].attr |= COLLIDER_ATTR_ENABLED;
            func_8004AD50_4B950(work->work16[4]);
            work->work8[1] = 0;
            work->func = o39_UpdateClockSpeed;
            work->state = 0;
        }
    }
}

void o39_UpdateClockSpeed(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player1 = &o39_players[0];
    f32 clockObstacleRot;
    f32 clockPlatformRot;
    s16 fxPlayed;

    if (o39_minigame->finished) {
        return;
    }
    if (work->state == 0) {
        work->work8[0] = FALSE;
        o39_minigame->clockSpeedMultiplier = 1.0f;
        o39_minigame->jumpCount = 0;
        o39_minigame->jumpsSinceSpeedChange = 0;
        o39_minigame->jumpsForSpeedChange = rand16() % 3 + 1;
        work->state = 1;
    }
    if (player1->obstacleProximityTracker->colliding) {
        if (!work->work8[0]) {
            work->work8[0] = TRUE;
        }
    } else {
        if (work->work8[0]) {
            o39_minigame->jumpsSinceSpeedChange++;
            o39_minigame->jumpCount++;
            o39_minigame->clockSpeedMultiplier = 1.0f + o39_minigame->jumpCount * 0.03f;
        }
        work->work8[0] = FALSE;
    }
    if (o39_minigame->jumpsSinceSpeedChange > o39_minigame->jumpsForSpeedChange) {
        if (!work->work8[1]) {
            fxPlayed = FALSE;
            work->work8[1] = TRUE;
            work->workF[3] = 120 + rand16() % 60;
            switch (rand16() % 3) {
                case 0:
                    if (rand16() & 1) {
                        work->workF[0] = 0.0f;
                        work->workF[1] = o39_GetRandInRange(3, 4);
                    } else {
                        work->workF[0] = o39_GetRandInRange(3, 4);
                        work->workF[1] = 0.0f;
                    }
                    break;
                case 1:
                    if (rand16() & 1) {
                        if (rand16() & 1) {
                            work->workF[0] = 3.0f;
                            work->workF[1] = 1.0f;
                        } else {
                            work->workF[0] = 1.0f;
                            work->workF[1] = 3.0f;
                        }
                    } else {
                        if (rand16() & 1) {
                            work->workF[0] = -3.0f;
                            work->workF[1] = -1.0f;
                        } else {
                            work->workF[0] = -1.0f;
                            work->workF[1] = -3.0f;
                        }
                    }
                    break;
                case 2:
                    work->workF[0] = o39_GetRandInRange(2, 3);
                    if (work->workF[0] > 0.0f) {
                        work->workF[1] = -(f32) (2 + (rand16() & 1));
                    } else {
                        work->workF[1] = (f32) (2 + (rand16() & 1));
                    }
                    break;
            }
        } else {
            fxPlayed = FALSE;
            clockObstacleRot = HmfModelData[groupData->modelIds[MDL_OBSTACLE]].rot.y;
            clockPlatformRot = HmfModelData[groupData->modelIds[MDL_PLATFORM]].rot.y;
            o39_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
            if (ABS(clockObstacleRot - clockPlatformRot) > work->workF[3]) {
                if (o39_minigame->clockBaseSpeed[HAND_OBSTACLE] > 0.0f) {
                    if (work->workF[0] < 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                } else if (o39_minigame->clockBaseSpeed[HAND_OBSTACLE] < 0.0f) {
                    if (work->workF[0] > 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                } else {
                    if (work->workF[0] != 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                }
                if (!fxPlayed) {
                    if (o39_minigame->clockBaseSpeed[HAND_PLATFORM] > 0.0f) {
                        if (work->workF[1] < 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else if (o39_minigame->clockBaseSpeed[HAND_PLATFORM] < 0.0f) {
                        if (work->workF[1] > 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else {
                        if (work->workF[1] != 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    }
                }
                o39_minigame->clockBaseSpeed[HAND_OBSTACLE] = work->workF[0];
                o39_minigame->clockBaseSpeed[HAND_PLATFORM] = work->workF[1];
                work->work8[1] = FALSE;
                o39_minigame->jumpsSinceSpeedChange = 0;
                o39_minigame->jumpsForSpeedChange = 2 + (rand16() & 1);
            }
        }
    }
}

void o39_UpdateClockObstacleRotation(FuncGroupData* groupData, FuncWork* work) {
    s32 var_a0;
    s16 var_s1;
    s16 var_a1;
    s16 var_a1_0;

    var_s1 = work->work16[0];
    o39_minigame->clockHandRot[HAND_OBSTACLE] += o39_minigame->clockBaseSpeed[HAND_OBSTACLE] * o39_minigame->clockSpeedMultiplier;
    if (o39_minigame->clockHandRot[HAND_OBSTACLE] < 0.0f) {
        o39_minigame->clockHandRot[HAND_OBSTACLE] += 360.0f;
    } else if (o39_minigame->clockHandRot[HAND_OBSTACLE] > 360.0f) {
        o39_minigame->clockHandRot[HAND_OBSTACLE] -= 360.0f;
    }
    Hu3DModelRotSet(groupData->modelIds[MDL_PLATFORM], 0.0f, o39_minigame->clockHandRot[HAND_OBSTACLE], 0.0f);
    if (o39_minigame->clockBaseSpeed[HAND_OBSTACLE] != 0.0f) {
        if (work->work8[0] == 0) {
            var_s1 = work->work16[0] = HuAudFXPlay(0x4BC);
            work->work8[0] = 1;
        }
        var_a1_0 = o39_minigame->clockSpeedMultiplier * 150.0f;
        switch ((s16) ABS(o39_minigame->clockBaseSpeed[HAND_OBSTACLE])) {
            case 1:
                var_a0 = var_s1;
                var_a1 = var_a1_0;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 2:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 150;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 3:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 300;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 4:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 450;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
        }
    } else if (work->work8[0] != 0) {
        func_8004AD50_4B950(var_s1);
        work->work8[0] = 0;
    }
}

void o39_UpdateClockPlatformRotation(FuncGroupData* groupData, FuncWork* work) {
    s32 var_a0;
    s16 var_s1;
    s16 var_a1;
    s16 var_a1_0;

    var_s1 = work->work16[0];
    o39_minigame->clockHandRot[HAND_PLATFORM] += o39_minigame->clockBaseSpeed[HAND_PLATFORM] * o39_minigame->clockSpeedMultiplier;
    if (o39_minigame->clockHandRot[HAND_PLATFORM] < 0.0f) {
        o39_minigame->clockHandRot[HAND_PLATFORM] += 360.0f;
    } else if (o39_minigame->clockHandRot[HAND_PLATFORM] > 360.0f) {
        o39_minigame->clockHandRot[HAND_PLATFORM] -= 360.0f;
    }
    Hu3DModelRotSet(groupData->modelIds[MDL_OBSTACLE], 0.0f, o39_minigame->clockHandRot[HAND_PLATFORM], 0.0f);
    if (o39_minigame->clockBaseSpeed[HAND_PLATFORM] != 0.0f) {
        if (work->work8[0] == 0) {
            var_s1 = work->work16[0] = HuAudFXPlay(0x4BD);
            work->work8[0] = 1;
        }
        var_a1_0 = o39_minigame->clockSpeedMultiplier * 150.0f;
        switch ((s16) ABS(o39_minigame->clockBaseSpeed[HAND_PLATFORM])) {
            case 1:
                var_a0 = var_s1;
                var_a1 = var_a1_0;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 2:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 150;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 3:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 300;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 4:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 450;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
        }
    } else if (work->work8[0] != 0) {
        func_8004AD50_4B950(var_s1);
        work->work8[0] = 0;
    }
}

f32 o39_GetRandInRange(s16 min, s16 max) {
    f32 rand;

    rand = rand16() % (max - min + 1) + min;
    if (rand16() & 1) {
        rand = -rand;
    }
    return rand;
}

void o39_CheckPlayerJumpStart(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    FuncWork* playerJumpWork;
    s16 playerJumpId;

    if (!o39_jumpEnabled) {
        return;
    }
    if (player->stat & PLAYER_STAT_FINISHED) {
        o39_ResetFunc(object->work[1], work);
        return;
    }
    if (D_800CDA7C_CE67C[player->padId] & A_BUTTON) {
        if (work->work8[0] == 0 && !(player->stat & PLAYER_STAT_JUMPING) && player->state != PLAYER_STATE_LAND) {
            work->work8[0] = 1;
            player->stat |= PLAYER_STAT_JUMPING;
            playerJumpId = o39_SetFunc(object->work[1], 0xEFFF, player, o39_UpdatePlayerJump, 0);
            playerJumpWork = &o39_funcGroups[object->work[1]].funcWork[playerJumpId];
            playerJumpWork->func(groupData, playerJumpWork);
        }
    } else {
        work->work8[0] = 0;
    }
}

void o39_UpdatePlayerPosition(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    f32 clockPlatformRot = o39_minigame->clockHandRot[HAND_PLATFORM];

    if (player->stat & PLAYER_STAT_LOST) {
        return;
    }
    if (work->state == 0) {
        if (o39_playerOrder[object->work[0]] == 0) {
            work->workF[0] = 185.0f;
            work->workF[1] = 185.0f;
        } else {
            work->workF[0] = 315.0f;
            work->workF[1] = 315.0f;
        }
        work->state = 1;
    }
    object->trans.x = HuMathSin(clockPlatformRot) * work->workF[0];
    object->trans.z = HuMathCos(clockPlatformRot) * work->workF[1];
    HmfModelData[object->model[1]].pos.x = object->trans.x;
    HmfModelData[object->model[1]].pos.z = object->trans.z;
    if (ABS(o39_minigame->clockHandRot[HAND_PLATFORM] - o39_minigame->clockHandRot[HAND_OBSTACLE]) < 10.0f) {
        HmfModelData[object->model[1]].pos.y = 30.0f;
    } else {
        HmfModelData[object->model[1]].pos.y = 5.0f;
    }
}

void o39_UpdatePlayerRotation(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    Vec direction;
    Vec origin;
    f32 rotAngles[3];

    if (player->stat & PLAYER_STAT_FINISHED) {
        o39_ResetFunc(object->work[1], work);
        return;
    }
    if (player->state == PLAYER_STATE_LAND || player->state == PLAYER_STATE_JUMP) {
        return;
    }
    if (D_800CBB6E_CC76E[player->padId] == 0 && D_800D20A1_D2CA1[player->padId] == 0) {
        o39_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
    } else {
        o39_SetPlayerState(player, PLAYER_STATE_WALK, TRUE);
        direction.x = -D_800CBB6E_CC76E[player->padId];
        direction.y = 0.0f;
        direction.z = D_800D20A1_D2CA1[player->padId];
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        o39_CalcPitchAndYaw(origin, direction, rotAngles);
        object->rot.y = rotAngles[1];
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void o39_UpdatePlayerJump(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    f32 var_f2;
    f32 accelY;
    f32 scale;

    if (object->trans.y == 0.0f && (player->stat & PLAYER_STAT_LOST)) {
        o39_ResetFunc(object->work[1], work);
        return;
    }
    if (work->state == 0) {
        player->accelY = -1.47f;
        o39_SetBillDispOnRef(player->dustBillId, &object->trans.x, NULL, &object->trans.z);
        o39_SetPlayerState(player, PLAYER_STATE_JUMP, TRUE);
        func_8004AC10_4B810(0x3A, GwPlayer[o39_playerId[object->work[0]]].chr);
        work->state = 1;
    }
    var_f2 = func_8001C7D0_1D3D0(object->model[0]);
    if (var_f2 == -1.0f) {
        var_f2 = HmfModelData[object->model[0]].unk40;
    }
    if (var_f2 > 5.0f && var_f2 < 7.0f && !(D_800CDA7C_CE67C[player->padId] & A_BUTTON)) {
        player->accelY = -0.294f;
    }
    accelY = player->accelY;
    if (accelY > 1.7f) {
        accelY = 1.7f;
    }
    object->trans.y += accelY * accelY * (accelY >= 0.0f ? -35.0f : 35.0f);
    player->accelY += 0.15f;
    scale = 1.0f - object->trans.y / 300.0f;
    if (scale > 1.0f) {
        scale = 1.0f;
    } else if (scale < 0.5f) {
        scale = 0.5f;
    }
    Hu3DModelScaleSet(object->model[1], scale, scale, scale);
    if (object->trans.y < 0.0f) {
        object->trans.y = 0.0f;
        player->stat &= ~PLAYER_STAT_JUMPING;
        player->stat |= PLAYER_STAT_01;
        o39_SetBillDispOnRef(player->dustBillId, &object->trans.x, NULL, &object->trans.z);
        func_8004AC10_4B810(0x31, GwPlayer[o39_playerId[object->work[0]]].chr);
        o39_SetPlayerState(player, PLAYER_STATE_LAND, TRUE);
        o39_SetPlayerNextState(player, PLAYER_STATE_IDLE);
        o39_ResetFunc(object->work[1], work);
    }
}

void o39_CheckPlayerCollision(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;

    if ((player->stat & PLAYER_STAT_FINISHED) || o39_minigame->jumpCount == JUMPS_MAX) {
        return;
    }
    if (player->obstacleCollisionTracker->colliding) {
        func_8001C258_1CE58(object->model[7], 4, 0);
        Hu3DModelPosSet(object->model[7], object->trans.x, 10.0f, object->trans.z);
        o39_SetPlayerState(player, PLAYER_STATE_KNOCKED, TRUE);
        o39_SetFunc(object->work[1], 0xFF, player, o39_ExecPlayerKnockedOut, 0);
        player->stat |= PLAYER_STAT_LOST;
        if (!(GwPlayer[o39_playerId[object->work[0]]].stat & PLAYER_IS_CPU)) {
            func_8004B25C_4BE5C(object->work[0], 2, 2, 0x14);
        }
    }
}

void o39_ExecPlayerIntro(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;

    D_800CDA7C_CE67C[player->padId] = 0;
    D_800CBB6E_CC76E[player->padId] = 0;
    D_800D20A1_D2CA1[player->padId] = 0;
    if (player->obstacleProximityTracker->colliding) {
        work->work8[1] = 1;
        work->work8[0]++;
        if (work->work8[0] < 5) {
            D_800CDA7C_CE67C[player->padId] = A_BUTTON;
        }
    } else {
        work->work8[0] = 0;
        if (work->work8[1] != 0 && work->work8[2] == 0) {
            D_800CBB6E_CC76E[player->padId] = HuMathSin(work->workF[0]) * 70.0f;
            D_800D20A1_D2CA1[player->padId] = HuMathCos(work->workF[0]) * 70.0f;
            work->workF[0] += 10.0f;
            if (work->workF[0] > 180.0f) {
                work->workF[0] = 180.0f;
                work->work8[2] = 1;
            }
        }
    }
}

void o39_ExecPlayerWins(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    f32 lerpT;

    work->work16[3]++;
    if (work->work16[3] < 40) {
        return;
    }
    switch (work->state) {
        case 0:
            if (player->state == PLAYER_STATE_IDLE || player->state == PLAYER_STATE_WALK) {
                work->work16[0] = 0;
                work->workF[0] = object->rot.y;
                if (object->rot.y != 180.0f) {
                    o39_SetPlayerState(player, PLAYER_STATE_WALK, TRUE);
                    work->state = 1;
                } else {
                    o39_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
                    work->state = 2;
                }
            }
            break;
        case 1: // Face the camera.
            lerpT = work->work16[0] / 10.0f;
            if (lerpT > 1.0f) {
                lerpT = 1.0f;
            }
            object->rot.y = (180.0f - work->workF[0]) * lerpT + work->workF[0];
            work->work16[0]++;
            if (work->work16[0] >= 11) {
                work->work16[0] = 0;
                object->rot.y = 180.0f;
                o39_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
                work->state = 2;
            }
            break;
        default:
            if (o39_minigame->jumpCount == JUMPS_MAX) { // Always false?
                o39_SetFunc(1, 0, NULL, o39_ExecBothPlayersWin, 0);
                o39_ResetFunc(object->work[1], work);
                break;
            }
            if (o39_playerWinsState == 0) {
                if (func_80037030_37C30() == 0) {
                    o39_playerWinsState = 1;
                }
            } else if (o39_playerWinsState >= 2) {
                if (func_80037030_37C30() == 0) {
                    o39_playerWinsState = 3;
                }
                if (o39_playerWinsState == 3) {
                    work->work16[0]++;
                    if (work->work16[0] >= 15) {
                        o39_ResetFunc(1, work);
                        o39_SetFunc(1, 0, NULL, o39_ExitOverlayOnWipeOut, 0);
                    }
                }
            } else {
                work->work16[0]++;
                if (work->work16[0] == 15) {
                    HuAudSeqPlay(0x67);
                    o39_SetPlayerState(player, PLAYER_STATE_WON, TRUE);
                    func_80036C4C_3784C(0x16, player->chr);
                    GwPlayer[o39_playerId[object->work[0]]].bonusCoin += 10;
                }
                if (func_80037030_37C30() != 0) {
                    work->work16[0] = 0;
                    o39_playerWinsState = 2;
                }
            }
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void o39_ExecPlayerKnockedOut(FuncGroupData* groupData, FuncWork* work) {
    omObjData* object = groupData->object;
    f32 rotDirection;
    f32 scale;
    f32 transY;

    if (work->state == 0) {
        if (o39_minigame->clockBaseSpeed[HAND_OBSTACLE] == 0.0f) {
            if (o39_minigame->clockBaseSpeed[HAND_PLATFORM] < 0.0f) {
                rotDirection = 1.0f;
            } else {
                rotDirection = -1.0f;
            }
        } else {
            if (o39_minigame->clockBaseSpeed[HAND_OBSTACLE] < 0.0f) {
                rotDirection = -1.0f;
            } else {
                rotDirection = 1.0f;
            }
        }
        work->workF[0] = o39_minigame->clockHandRot[HAND_PLATFORM] + rotDirection * 90.0f;
        while (work->workF[0] < 0.0f) {
            work->workF[0] += 360.0f;
        }
        while (work->workF[0] > 360.0f) {
            work->workF[0] -= 360.0f;
        }
        work->workF[1] = work->workF[2] = HuMathSin(45.0f) * 60.000004f;
        work->work16[0] = 0;
        func_8004AC98_4B898(0x287 + GwPlayer[o39_playerId[object->work[0]]].chr, o39_playerId[object->work[0]]);
        func_8004AC98_4B898(0x4BE, object->work[0]);
        work->state = 1;
    }
    object->trans.y += work->workF[1];
    work->workF[1] = work->workF[2] - work->work16[0] * 2.45f;
    work->work16[0]++;
    object->trans.x += HuMathSin(work->workF[0]) * 20.0f * 5.0f * 0.25f;
    object->trans.z += HuMathCos(work->workF[0]) * 20.0f * 5.0f * 0.25f;
    transY = object->trans.y;
    scale = 300.0f;
    scale = 1.0f - transY / scale;
    if (scale > 1.0f) {
        scale = 1.0f;
    } else if (scale < 0.5f) {
        scale = 0.5f;
    }
    Hu3DModelScaleSet(object->model[1], scale, scale, scale);
    HmfModelData[object->model[1]].pos.x = object->trans.x;
    HmfModelData[object->model[1]].pos.z = object->trans.z;
    if (object->trans.y < 10.0f) {
        work->work16[0] = 0;
        object->trans.y = 10.0f;
        func_8001C258_1CE58(object->model[0], 4, 4);
        func_8001C258_1CE58(object->model[1], 4, 4);
        o39_ResetFunc(object->work[1], work);
    }
}

void o39_UpdatePlayerAnimation(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    HmfModel* model = &HmfModelData[object->model[0]];

    if (D_800CCF58_CDB58[model->unk02].unk02 - 1 <= model->unk40) {
        player->updateAnimation = TRUE;
    }
    if (player->updateAnimation) {
        func_800E5690_B8210_name_82(object, player->state);
        if (player->state == PLAYER_STATE_WON) {
            func_80045F1C_46B1C(D_800A178C[GwPlayer[o39_playerId[object->work[0]]].chr][0] | 0x30, -1, o39_playerId[object->work[0]]);
        }
        player->updateAnimation = FALSE;
        if (player->nextState != -1) {
            player->state = player->nextState;
            player->nextState = -1;
        }
    }
}

void o39_SetPlayerState(PlayerData* player, s32 state, s32 updateAnimation) {
    player->updateAnimation = updateAnimation;
    player->state = state;
}

void o39_SetPlayerNextState(PlayerData* player, s32 state) {
    player->nextState = state;
}

void o39_InitCom(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;
    omObjData* object = groupData->object;
    Quad obstacleProximityQuad = { {
        {  90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 400.0f },
        {  90.0f, 0.0f, 400.0f }
    } };

    switch (GwPlayer[o39_playerId[object->work[0]]].cpu_difficulty) {
        case 0:
            player->comReactionDelay = 4;
            player->comShortJumpBias = 0;
            player->comFreezeThreshold = 10;
            break;
        case 1:
            player->comReactionDelay = 3;
            player->comShortJumpBias = 2;
            player->comFreezeThreshold = 20;
            break;
        case 2:
            player->comReactionDelay = 1;
            player->comShortJumpBias = 10;
            player->comFreezeThreshold = 30;
            break;
        case 3:
            player->comReactionDelay = 0;
            player->comShortJumpBias = 99;
            player->comFreezeThreshold = 40;
            break;
    }
    o39_SetColliderBaseQuad(o39_minigame->obstacleProximityColliderId, &obstacleProximityQuad, 0.0f);
    work->func = o39_UpdateComInput;
}

void o39_ResetPlayerInput(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;

    if (player->unk24 != 99) {
        D_800CDA7C_CE67C[player->padId] = 0;
        D_800CBB6E_CC76E[player->padId] = 0;
        D_800D20A1_D2CA1[player->padId] = 0;
    }
}

void o39_UpdateComInput(FuncGroupData* groupData, FuncWork* work) {
    PlayerData* player = work->data;

    player->unk24 = 99;
    D_800CDA7C_CE67C[player->padId] = 0;
    D_800CBB6E_CC76E[player->padId] = 0;
    D_800D20A1_D2CA1[player->padId] = 0;
    if (player->stat & PLAYER_STAT_FROZEN) {
        return;
    }
    if (work->work8[0] == 0) {
        if (player->obstacleProximityTracker->colliding) {
            if (o39_minigame->jumpCount > player->comFreezeThreshold && rand16() % 6 == 0) {
                player->stat |= PLAYER_STAT_FROZEN;
            }
            if (work->work8[1] == 0) {
                work->work8[0] = 1;
                work->work8[1] = 1;
            }
        } else {
            work->work8[1] = 0;
        }
    }
    if (work->work8[0] == 1) {
        work->work16[0]++;
        if (work->work16[0] > rand16() % (player->comReactionDelay + 1)) {
            work->work16[0] = 0;
            work->work8[0] = 2;
            if (rand16() % (player->comShortJumpBias + 1) != 0
                && ABS(o39_minigame->clockBaseSpeed[HAND_PLATFORM] - o39_minigame->clockBaseSpeed[HAND_OBSTACLE]) > 2.0f)
            {
                work->work16[1] = 1;
            } else {
                work->work16[1] = 6;
            }
        }
    }
    if (work->work8[0] == 2) {
        work->work16[0]++;
        if (work->work16[0] <= work->work16[1]) {
            D_800CDA7C_CE67C[player->padId] = A_BUTTON;
        } else {
            work->work16[0] = 0;
            work->work8[0] = 0;
        }
    }
}
