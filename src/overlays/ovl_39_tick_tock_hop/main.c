#include "overlays/ovl_39.h"
#include "overlays/minigame.h"
#include "gcc/memory.h"
#include "game/audio.h"
#include "game/camera.h"
#include "game/gamemes.h"
#include "game/gamework_data.h"
#include "game/hmflight.h"
#include "game/pause.h"
#include "game/sprite.h"
#include "game/wipe.h"
#include "mallocblock.h"

#define PLAYERS_TOTAL 2
#define JUMPS_MAX 99

// C1F0
void func_8000B5F0_C1F0(u8 arg0);
s32 func_8000B638_C238(void);

// 14EA0
void func_800142A0_14EA0(s32);
s32 func_80017BB8_187B8(s32, s32);

// 20A20
void Hu3DAnimInit(s32);

// 8EFF0
f32 HuMathCos(f32);

// 8FB20
f32 HuMathSin(f32);

// pad
extern s8 D_800CBB6E_CC76E[];
extern u16 D_800CDA7C_CE67C[];
extern s8 D_800D20A1_D2CA1[];

// unknown
extern s32 D_800A178C[][6];
extern u16 D_800D530C_D5F0C;

// LOCAL

enum {
    FGRP_CAMERA,
    FGRP_MINIGAME,
    FGRP_CLOCK,
    FGRP_PLAYER_1,
    FGRP_PLAYER_2
};

enum {
    MDL_PLATFORM,
    MDL_OBSTACLE,
    MDL_DISK_SMALL,
    MDL_DISK_LARGE
};

enum {
    HAND_PLATFORM,
    HAND_OBSTACLE
};

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
    /* 0x2C */ Work work;
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

void m257_InitEnvironment(void);
void m257_CreateMinigame(void);
void m257_CheckExitRequest(omObjData* object);
void m257_ExitOverlay(omObjData* object);
void m257_WaitExitWipeOut(omObjData* object);
void m257_InitMinigame(omObjData* object);
void m257_UpdateSystem(omObjData* object);
void m257_InitClock(omObjData* object);
void m257_UpdateClockHands(omObjData* object);
void m257_InitPlayer(omObjData* object);
void m257_UpdatePlayer(omObjData* object);
void m257_InitCamera(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_CheckMinigameEnd(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecPlayersDraw(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecClockIntro(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdateClockSpeed(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdateClockObstacleRotation(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdateClockPlatformRotation(FuncGroupContext* groupCtx, FuncContext* ctx);
f32 m257_GetRandInRange(s16 min, s16 max);
void m257_CheckPlayerJumpStart(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdatePlayerPosition(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdatePlayerRotation(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecPlayerJump(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_CheckPlayerCollision(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecPlayerIntro(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecPlayerWins(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ExecPlayerKnockedOut(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdatePlayerAnimation(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_SetPlayerState(PlayerData* player, s32 state, s32 updateAnimation);
void m257_SetPlayerNextState(PlayerData* player, s32 state);
void m257_InitCom(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_ResetPlayerInput(FuncGroupContext* groupCtx, FuncContext* ctx);
void m257_UpdateComInput(FuncGroupContext* groupCtx, FuncContext* ctx);

const s16 D_8010E5F0_2C5A60_tick_tock_hop[] = {
    0x8272, 0x8273, 0x8260, 0x8271, 0x8273, 0x0000
};

const s16 D_8010E5FC_2C5A6C_tick_tock_hop[] = {
    0x8265, 0x8268, 0x826D, 0x8268, 0x8272, 0x8267, 0x0000, 0x0000
};

const s16 D_8010E60C_2C5A7C_tick_tock_hop[] = {
    0x8263, 0x8271, 0x8260, 0x8276, 0x0000, 0x0000
};

MinigameData* BSS m257_minigame;
PlayerData* BSS m257_players;
s16 BSS m257_playerId[PLAYERS_TOTAL];
s16 BSS m257_playerOrder[PLAYERS_TOTAL];

s16 m257_jumpEnabled = TRUE;
s16 D_8010E4A2_2C5912_tick_tock_hop = FALSE;
s16 m257_bgmStartTimer = 0;
s16 m257_bothPlayersWinState = 0;
s16 m257_playersDrawState = 0;
s16 m257_playerWinsState = 0;

void m257_OverlayMain(void) {
    m257_InitEnvironment();
}

void m257_InitEnvironment(void) {
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
    D_800EC1B8_BED38_minigame = 0;
    D_800EC280_BEE00_minigame = 0;
    D_800EBE28_BE9A8_minigame = 0;
    m257_CreateSystem();
    m257_CreateMinigame();
    omAddObj(1000, 0, 0, -1, m257_InitMinigame);
    omAddObj(2000, 0, 0, -1, m257_CheckExitRequest);
    func_80045010_45C10(D_8010E5F0_2C5A60_tick_tock_hop, 1); // gamemes
    func_80045010_45C10(D_8010E5FC_2C5A6C_tick_tock_hop, 1);
    func_80045010_45C10(D_8010E60C_2C5A7C_tick_tock_hop, 1);
}

void m257_CreateMinigame(void) {
    s16 player1Set = FALSE;
    s16 player2Set = FALSE;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            if (!player1Set) {
                m257_playerId[0] = i;
                player1Set = TRUE;
            }
        } else if (GwPlayer[i].group == 1) {
            if (!player2Set) {
                m257_playerId[1] = i;
                player2Set = TRUE;
            }
        }
    }
    m257_minigame = HuMemAllocTag(sizeof(MinigameData), 31000);
    memset(m257_minigame, 0, sizeof(MinigameData));
    m257_players = HuMemAllocTag(PLAYERS_TOTAL * sizeof(PlayerData), 31000);
    memset(m257_players, 0, PLAYERS_TOTAL * sizeof(PlayerData));
}

void m257_CheckExitRequest(omObjData* object) {
    if (D_800D530C_D5F0C == 1) { // omSysExitReq?
        WipeCreateOut(0, 20);
        object->func = m257_WaitExitWipeOut;
    }
}

void m257_WaitExitWipeOut(omObjData* object) {
    if (WipeStatGet() == 0) {
        object->func = m257_ExitOverlay;
    }
}

void m257_ExitOverlay(omObjData* object) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void m257_UpdateCamera(void) {
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
    m257_UpdateFuncGroup(FGRP_CAMERA);
}

void m257_InitMinigame(omObjData* object) {
    FuncContext* createCollidersCtx;
    s16 createCollidersId;
    s16 i;

    func_800E18D8_B4458_minigame();
    func_800E19F0_B4570_minigame(1);
    m257_CreateFuncGroup(NULL, FGRP_CAMERA, 0, 4);
    m257_SetFunc(FGRP_CAMERA, 0, NULL, m257_InitCamera, 0);
    object->work[1] = FGRP_MINIGAME;
    m257_CreateFuncGroup(object, object->work[1], 0, 4);
    createCollidersId = m257_SetFunc(object->work[1], 0xFFFF, NULL, m257_CreateColliders, object->work[1]);
    createCollidersCtx = &m257_funcGroups[object->work[1]].funcCtx[createCollidersId];
    createCollidersCtx->func(NULL, createCollidersCtx);
    m257_MakeRandPermutation(m257_playerOrder, PLAYERS_TOTAL);
    for (i = 0; i < PLAYERS_TOTAL; i++) {
        D_800EC598_BF118_minigame[i] = omAddObj(300, 9, 39, -1, m257_InitPlayer);
    }
    D_800EC1C0_BED40_minigame[0] = omAddObj(10, 5, 0, -1, m257_InitClock);
    WipeCreateIn(0xFF, 16);
    object->func = m257_UpdateSystem;
}

void m257_UpdateSystem(omObjData* object) {
    m257_UpdateFuncGroup(FGRP_MINIGAME);
    m257_UpdateCamera();
    m257_UpdateSprites();
    m257_UpdateAnimModels();
    m257_UpdateBills();
}

void m257_InitClock(omObjData* object) {
    FuncGroupContext* groupCtx;
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

    groupCtx = m257_CreateFuncGroup(object, FGRP_CLOCK, 5, 16)->groupCtx;
    groupCtx->modelIds[MDL_PLATFORM] = m257_minigame->clockHandModel[HAND_PLATFORM] = func_8000B108_BD08(0x5A0000, var_s4);
    groupCtx->modelIds[MDL_OBSTACLE] = m257_minigame->clockHandModel[HAND_OBSTACLE] = func_8000B108_BD08(0x5A0001, var_s4);
    groupCtx->modelIds[MDL_DISK_SMALL] = func_8000B108_BD08(0x5A0002, var_s4);
    groupCtx->modelIds[MDL_DISK_LARGE] = func_8000B108_BD08(0x5A0003, var_s4);
    m257_SetSpriteDispOn(m257_SetSprite(0xFFFF, 0x5A, 6, 0, spriteAttr), 160, 120);
    for (i = 0; i < 8; i++) {
        f32 starPosX = HuMathSin(starAngle[i]) * 600.0f;
        f32 starPosZ = HuMathCos(starAngle[i]) * 600.0f;

        if (i % 2 != 0) {
            // Yellow star.
            id = m257_SetAnimModel(0x5A, 5, 0.25f, ANIMMDL_ATTR_DISPON, var_s4);
        } else {
            // Red star.
            id = m257_SetAnimModel(0x5A, 4, 0.25f, ANIMMDL_ATTR_DISPON, var_s4);
        }
        m257_SetAnimModelDispOn(id, starPosX, -25.0f, starPosZ, 0.0f, 0.0f, 0.0f, 0.4f, rand16() % 31);
        func_8001C258_1CE58(m257_animModels[id].modelId, 4, 0);
    }
    m257_minigame->tensSpriteId = m257_SetSprite(0xF, 0, 0x2D, 0, 0);
    m257_minigame->unitsSpriteId = id = m257_SetSprite(0xF, 0, 0x2D, 0, 0);
    m257_SetSpriteDispOn(id, 280, 32);
    m257_minigame->clockHandRot[HAND_PLATFORM] = 270.0f;
    m257_minigame->clockHandRot[HAND_OBSTACLE] = 0.0f;
    Hu3DModelRotSet(groupCtx->modelIds[MDL_PLATFORM], 0.0f, m257_minigame->clockHandRot[HAND_PLATFORM], 0.0f);
    Hu3DModelRotSet(groupCtx->modelIds[MDL_OBSTACLE], 0.0f, m257_minigame->clockHandRot[HAND_OBSTACLE], 0.0f);
    Hu3DModelPosSet(groupCtx->modelIds[MDL_PLATFORM], 0.0f, 25.0f, 0.0f);
    Hu3DModelPosSet(groupCtx->modelIds[MDL_OBSTACLE], 0.0f, 0.0f, 0.0f);
    Hu3DModelPosSet(groupCtx->modelIds[MDL_DISK_SMALL], 0.0f, 30.0f, 0.0f);
    Hu3DModelPosSet(groupCtx->modelIds[MDL_DISK_LARGE], 0.0f, -40.0f, 0.0f);
    m257_SetFunc(FGRP_CLOCK, 0xF, NULL, m257_UpdateClockPlatformRotation, 0);
    m257_SetFunc(FGRP_CLOCK, 0xF, NULL, m257_UpdateClockObstacleRotation, 0);
    m257_minigame->obstacleColliderId = m257_SetCollider(groupCtx->modelIds[MDL_PLATFORM], &obstacleQuad, 25.0f, PLAYERS_TOTAL, COLLIDER_ATTR_DISABLED);
    m257_minigame->obstacleProximityColliderId = m257_SetCollider(groupCtx->modelIds[MDL_PLATFORM], &obstacleProximityQuad, 0.0f, PLAYERS_TOTAL, COLLIDER_ATTR_HEIGHT_DISABLED);
    m257_minigame->clockBaseSpeed[HAND_PLATFORM] = 0.0f;
    m257_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
    m257_minigame->finished = FALSE;
    object->model[0] = groupCtx->modelIds[MDL_PLATFORM];
    m257_SyncWithModel(object);
    m257_SetFunc(FGRP_CLOCK, 0, NULL, m257_ExecClockIntro, 0);
    object->func = m257_UpdateClockHands;
}

void m257_UpdateClockHands(omObjData* object) {
    m257_UpdateFuncGroup(FGRP_CLOCK);
    m257_SyncWithModel(object);
}

void m257_InitPlayer(omObjData* object) {
    PlayerData* player;
    s32 var_a0 = 0x2B9;
    s32 temp_a1;
    s32 temp_a2;

    object->work[0] = D_800EC280_BEE00_minigame;
    player = &m257_players[object->work[0]];
    player->chr = GwPlayer[m257_playerId[object->work[0]]].chr;
    temp_a1 = D_800A178C[player->chr][0];
    temp_a2 = D_800A178C[player->chr][1];
    func_800E1BA8_B4728_minigame(object, temp_a1, temp_a2, m257_playerId[object->work[0]], var_a0, var_a0);
    object->model[7] = func_8000B108_BD08(8, var_a0);
    func_8001C258_1CE58(object->model[7], 4, 4);
    player->dustBillId = m257_SetBill(0x57, 0x10, BILL_ATTR_01 | BILL_ATTR_ANIM | BILL_ATTR_DISPOFF);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_IDLE, func_80017BB8_187B8(player->chr, 0), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_WALK, func_80017BB8_187B8(player->chr, 2), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_JUMP, func_80017BB8_187B8(player->chr, 4), 1, 19);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_LAND, func_80017BB8_187B8(player->chr, 0x1F), 1, 999);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_WON, func_80017BB8_187B8(player->chr, 0x30), 1, 999);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_KNOCKED, func_80017BB8_187B8(player->chr, 0x1A), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_STATE_LOST, func_80017BB8_187B8(player->chr, 0x36), 1, 999);
    m257_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
    player->nextState = -1;
    player->padId = ((s8*) object->data)[0x57]; // TODO: figure out type.
    player->stat = PLAYER_STAT_01;
    object->rot.x = object->rot.y = object->rot.z = 0.0f;
    object->scale.x = object->scale.y = object->scale.z = 1.0f;
    D_800EC280_BEE00_minigame++;
    player->obstacleCollisionTracker = m257_SetModelTracker(m257_minigame->obstacleColliderId, object->model[0]);
    player->obstacleProximityTracker = m257_SetModelTracker(m257_minigame->obstacleProximityColliderId, object->model[0]);
    object->work[1] = FGRP_PLAYER_1 + object->work[0];
    m257_CreateFuncGroup(object, object->work[1], 0, 10);
    player->resetInputGroupId = object->work[1];
    player->resetInputId = m257_SetFunc(object->work[1], 0, player, m257_ResetPlayerInput, 0);
    m257_SetFunc(object->work[1], 0xF, player, m257_CheckPlayerJumpStart, 0);
    m257_SetFunc(object->work[1], 0x1F, player, m257_UpdatePlayerPosition, 0);
    m257_SetFunc(object->work[1], 0x1F, player, m257_UpdatePlayerRotation, 0);
    m257_SetFunc(object->work[1], 0xEFFF, player, m257_CheckPlayerCollision, 0);
    m257_SetFunc(object->work[1], 0xFFFF, player, m257_UpdatePlayerAnimation, 0);
    object->func = m257_UpdatePlayer;
}

void m257_UpdatePlayer(omObjData* object) {
    m257_UpdateFuncGroup(object->work[1]);
    func_800E4E30_B79B0_minigame(object);
}

void m257_InitCamera(FuncGroupContext* groupCtx, FuncContext* ctx) {
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = -137.0f;
    CRot.x = 298.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    CZoom = 990.0f;
    m257_ResetFunc(FGRP_CAMERA, ctx);
}

void m257_UpdateJumpCounterSprites(FuncGroupContext* groupCtx, FuncContext* ctx) {
    s16 units = m257_minigame->jumpCount % 10;
    s16 tens = m257_minigame->jumpCount * 0.1f;

    if (tens != 0) {
        m257_SetSpriteDispOn(m257_minigame->tensSpriteId, 264, 32);
    } else {
        m257_SetSpriteDispOff(m257_minigame->tensSpriteId);
    }
    func_80054FF8_55BF8(m257_sprites[m257_minigame->tensSpriteId].groupId, 0, tens);
    func_80054FF8_55BF8(m257_sprites[m257_minigame->unitsSpriteId].groupId, 0, units);
}

void m257_ExecMinigameStart(FuncGroupContext* groupCtx, FuncContext* ctx) {
    s16 i;

    if (ctx->state == 0) {
        ctx->work.s16[0] = 0;
        ctx->state = 1;
    }
    ctx->work.s16[0]++;
    switch (ctx->work.s16[0]) {
        case 5:
            GMesCreate(GMES_MES_MG_START);
            HuAudFXPlay(0xE); // plays whistle fx
            m257_bgmStartTimer = 1;
            break;
        case 30:
            D_8010E4A2_2C5912_tick_tock_hop = TRUE;
            break;
        default:
            if (D_8010E4A2_2C5912_tick_tock_hop && GMesStatGet() == 2) { // GMES_STAT_TIMEEND?
                m257_jumpEnabled = TRUE;
                m257_minigame->clockBaseSpeed[HAND_PLATFORM] = 0.0f;
                m257_minigame->clockBaseSpeed[HAND_OBSTACLE] = 3.0f;
                for (i = 0; i < PLAYERS_TOTAL; i++) {
                    if (GwPlayer[m257_playerId[i]].stat & PLAYER_IS_CPU) {
                        m257_SetFunc(FGRP_PLAYER_1 + i, 0, &m257_players[i], m257_InitCom, 0);
                    } else {
                        m257_ResetFunc(m257_players[i].resetInputGroupId, &m257_funcGroups[m257_players[i].resetInputGroupId].funcCtx[m257_players[i].resetInputId]);
                    }
                }
                m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_UpdateJumpCounterSprites, 0);
                ctx->func = m257_CheckMinigameEnd;
            }
            break;
    }
    if (m257_bgmStartTimer != 0 && GMesStatGet() != GMES_STAT_NONE) {
        m257_bgmStartTimer++;
        if (m257_bgmStartTimer >= 45) {
            HuAudSeqPlay(0x2F);
            m257_bgmStartTimer = 0;
        }
    }
}

void m257_ExitOverlayOnWipeOut(FuncGroupContext* groupCtx, FuncContext* ctx) {
    switch (ctx->state) {
        case 0:
            WipeCreateOut(0, 20);
            ctx->state = 1;
            break;
        case 1:
            if (WipeStatGet() == 0) {
                omOvlReturnEx(1);
            }
            break;
    }
}

void m257_CheckMinigameEnd(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = m257_players;
    s16 losers[2] = { -1, -1 };
    s16 loserCount;
    f32 clockObstacleRot;
    f32 clockPlatformRot;
    s16 i;

    if (m257_minigame->jumpCount == JUMPS_MAX) {
        if (!m257_minigame->finished) {
            m257_minigame->finished = TRUE;
        }
        clockObstacleRot = HmfModelData[m257_minigame->clockHandModel[HAND_OBSTACLE]].rot.y;
        clockPlatformRot = HmfModelData[m257_minigame->clockHandModel[HAND_PLATFORM]].rot.y;
        m257_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
        if (ABS(clockObstacleRot - clockPlatformRot) > 90.0f) {
            m257_minigame->clockBaseSpeed[HAND_PLATFORM] = m257_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
            HuAudSeqFadeOut(120);
            GMesCreate(GMES_MES_MG_FINISH);
            m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExecPlayersDraw, 0);
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                m257_players[i].stat |= PLAYER_STAT_LOST;
            }
            m257_ResetFunc(FGRP_MINIGAME, ctx);
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
        if (!m257_minigame->finished) {
            m257_minigame->finished = TRUE;
        }
        clockObstacleRot = HmfModelData[m257_minigame->clockHandModel[HAND_OBSTACLE]].rot.y;
        clockPlatformRot = HmfModelData[m257_minigame->clockHandModel[HAND_PLATFORM]].rot.y;
        m257_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
        if (ABS(clockObstacleRot - clockPlatformRot) > 90.0f) {
            m257_minigame->clockBaseSpeed[HAND_PLATFORM] = m257_minigame->clockBaseSpeed[HAND_OBSTACLE] = 0.0f;
            HuAudSeqFadeOut(120);
            GMesCreate(GMES_MES_MG_FINISH);
            if (loserCount == PLAYERS_TOTAL) {
                m257_ResetFunc(FGRP_MINIGAME, ctx);
                m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExecPlayersDraw, 0);
            } else {
                s16 winner = !losers[0];

                m257_players[winner].stat |= PLAYER_STAT_WON;
                m257_SetFunc(FGRP_PLAYER_1 + winner, 0xFF, &m257_players[winner], m257_ExecPlayerWins, 0);
                m257_ResetFunc(FGRP_MINIGAME, ctx);
            }
        }
    }
}

void m257_ExecBothPlayersWin(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player1 = &m257_players[0];
    PlayerData* player2 = &m257_players[1];

    if (ctx->state == 0) {
        ctx->work.s16[0] = 0;
        ctx->state = 1;
    }
    if (m257_bothPlayersWinState == 0) {
        if (GMesStatGet() == GMES_STAT_NONE) {
            m257_bothPlayersWinState = 1;
        }
    } else if (m257_bothPlayersWinState >= 2) {
        if (GMesStatGet() == GMES_STAT_NONE) {
            m257_bothPlayersWinState = 3;
        }
        if (m257_bothPlayersWinState == 3) {
            ctx->work.s16[0]++;
            if (ctx->work.s16[0] >= 15) {
                m257_ResetFunc(FGRP_MINIGAME, ctx);
                m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExitOverlayOnWipeOut, 0);
            }
        }
    } else {
        ctx->work.s16[0]++;
        if (ctx->work.s16[0] == 15) {
            HuAudSeqPlay(0x67);
            m257_SetPlayerState(player1, PLAYER_STATE_WON, TRUE);
            m257_SetPlayerState(player2, PLAYER_STATE_WON, TRUE);
            func_8004AC98_4B898(0x290 + GwPlayer[m257_playerId[0]].chr, m257_playerId[0]);
            func_8004AC98_4B898(0x290 + GwPlayer[m257_playerId[1]].chr, m257_playerId[1]);
            GMesCreate(GMES_MES_MG_WINNERS_2, player1->chr, player2->chr);
            GwPlayer[m257_playerId[D_800EC598_BF118_minigame[0]->work[0]]].bonusCoin += 10;
            GwPlayer[m257_playerId[D_800EC598_BF118_minigame[1]->work[0]]].bonusCoin += 10;
        }
        if (GMesStatGet() != GMES_STAT_NONE) {
            ctx->work.s16[0] = 0;
            m257_bothPlayersWinState = 2;
        }
    }
}

void m257_ExecPlayersDraw(FuncGroupContext* groupCtx, FuncContext* ctx) {
    if (ctx->state == 0) {
        ctx->work.s16[0] = 0;
        ctx->state = 1;
    }
    if (m257_playersDrawState == 0) {
        if (GMesStatGet() == GMES_STAT_NONE) {
            m257_playersDrawState = 1;
        }
    } else if (m257_playersDrawState >= 2) {
        if (GMesStatGet() == GMES_STAT_NONE) {
            m257_playersDrawState = 3;
        }
        if (m257_playersDrawState == 3) {
            ctx->work.s16[0]++;
            if (ctx->work.s16[0] >= 15) {
                m257_ResetFunc(FGRP_MINIGAME, ctx);
                m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExitOverlayOnWipeOut, 0);
            }
        }
    } else {
        ctx->work.s16[0]++;
        if (ctx->work.s16[0] == 15) {
            m257_SetPlayerState(&m257_players[0], PLAYER_STATE_LOST, TRUE);
            m257_SetPlayerState(&m257_players[1], PLAYER_STATE_LOST, TRUE);
            GMesCreate(GMES_MES_MG_DRAW);
            HuAudSeqPlay(0x6C);
        }
        if (GMesStatGet() != GMES_STAT_NONE) {
            ctx->work.s16[0] = 0;
            m257_playersDrawState = 2;
        }
    }
}

void m257_ExecClockIntro(FuncGroupContext* groupCtx, FuncContext* ctx) {
    s16 i;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 0;
            ctx->work.s16[3] = 0;
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                ctx->work.s16[i] = m257_SetFunc(FGRP_PLAYER_1 + i, 0xF, &m257_players[i], m257_ExecPlayerIntro, 0);
            }
            ctx->state = 1;
            break;
        case 1:
            ctx->work.s16[3]++;
            if (ctx->work.s16[3] < 30.0f) {
                return;
            }
            ctx->state = 2;
            HuAudFXPlay(0x4BB);
            ctx->work.s16[4] = HuAudFXPlay(0x4BC);
            HuAudFXPitchSet(ctx->work.s16[4], 0);
            break;
    }
    if (ctx->work.s8[0] == 0) {
        m257_minigame->clockHandRot[HAND_OBSTACLE] -= 4.0f;
        if (m257_minigame->clockHandRot[HAND_OBSTACLE] < 0.0f) {
            m257_minigame->clockHandRot[HAND_OBSTACLE] += 360.0f;
        }
        if (m257_minigame->clockHandRot[HAND_OBSTACLE] < 180.0f) {
            HuAudFXStop(ctx->work.s16[4]);
            ctx->work.s8[4] = 0;
            ctx->work.s8[0] = 1;
        }
    } else if (++ctx->work.s8[0] >= 11) {
        if (ctx->work.s8[1] == 0) {
            ctx->work.s16[4] = HuAudFXPlay(0x4BC);
            HuAudFXPitchSet(ctx->work.s16[4], 0);
            HuAudFXPlay(0x4BB);
            ctx->work.s8[1] = 1;
        }
        ctx->work.s8[0] = 10;
        m257_minigame->clockHandRot[HAND_OBSTACLE] += 4.0f;
        if (m257_minigame->clockHandRot[HAND_OBSTACLE] > 360.0f) {
            m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExecMinigameStart, 0);
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                m257_ResetFunc(FGRP_PLAYER_1 + i, &m257_funcGroups[FGRP_PLAYER_1 + i].funcCtx[ctx->work.s16[i]]);
            }
            m257_jumpEnabled = FALSE;
            m257_colliders[m257_minigame->obstacleColliderId].attr &= ~COLLIDER_ATTR_DISABLED;
            m257_colliders[m257_minigame->obstacleColliderId].attr |= COLLIDER_ATTR_ENABLED;
            HuAudFXStop(ctx->work.s16[4]);
            ctx->work.s8[1] = 0;
            ctx->func = m257_UpdateClockSpeed;
            ctx->state = 0;
        }
    }
}

void m257_UpdateClockSpeed(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player1 = &m257_players[0];
    f32 clockObstacleRot;
    f32 clockPlatformRot;
    s16 fxPlayed;

    if (m257_minigame->finished) {
        return;
    }
    if (ctx->state == 0) {
        ctx->work.s8[0] = FALSE;
        m257_minigame->clockSpeedMultiplier = 1.0f;
        m257_minigame->jumpCount = 0;
        m257_minigame->jumpsSinceSpeedChange = 0;
        m257_minigame->jumpsForSpeedChange = rand16() % 3 + 1;
        ctx->state = 1;
    }
    if (player1->obstacleProximityTracker->colliding) {
        if (!ctx->work.s8[0]) {
            ctx->work.s8[0] = TRUE;
        }
    } else {
        if (ctx->work.s8[0]) {
            m257_minigame->jumpsSinceSpeedChange++;
            m257_minigame->jumpCount++;
            m257_minigame->clockSpeedMultiplier = 1.0f + m257_minigame->jumpCount * 0.03f;
        }
        ctx->work.s8[0] = FALSE;
    }
    if (m257_minigame->jumpsSinceSpeedChange > m257_minigame->jumpsForSpeedChange) {
        if (!ctx->work.s8[1]) {
            fxPlayed = FALSE;
            ctx->work.s8[1] = TRUE;
            ctx->work.f32[3] = 120 + rand16() % 60;
            switch (rand16() % 3) {
                case 0:
                    if (rand16() & 1) {
                        ctx->work.f32[0] = 0.0f;
                        ctx->work.f32[1] = m257_GetRandInRange(3, 4);
                    } else {
                        ctx->work.f32[0] = m257_GetRandInRange(3, 4);
                        ctx->work.f32[1] = 0.0f;
                    }
                    break;
                case 1:
                    if (rand16() & 1) {
                        if (rand16() & 1) {
                            ctx->work.f32[0] = 3.0f;
                            ctx->work.f32[1] = 1.0f;
                        } else {
                            ctx->work.f32[0] = 1.0f;
                            ctx->work.f32[1] = 3.0f;
                        }
                    } else {
                        if (rand16() & 1) {
                            ctx->work.f32[0] = -3.0f;
                            ctx->work.f32[1] = -1.0f;
                        } else {
                            ctx->work.f32[0] = -1.0f;
                            ctx->work.f32[1] = -3.0f;
                        }
                    }
                    break;
                case 2:
                    ctx->work.f32[0] = m257_GetRandInRange(2, 3);
                    if (ctx->work.f32[0] > 0.0f) {
                        ctx->work.f32[1] = -(f32) (2 + (rand16() & 1));
                    } else {
                        ctx->work.f32[1] = (f32) (2 + (rand16() & 1));
                    }
                    break;
            }
        } else {
            fxPlayed = FALSE;
            clockObstacleRot = HmfModelData[groupCtx->modelIds[MDL_OBSTACLE]].rot.y;
            clockPlatformRot = HmfModelData[groupCtx->modelIds[MDL_PLATFORM]].rot.y;
            m257_MinimizeAngleDiff(&clockObstacleRot, &clockPlatformRot);
            if (ABS(clockObstacleRot - clockPlatformRot) > ctx->work.f32[3]) {
                if (m257_minigame->clockBaseSpeed[HAND_OBSTACLE] > 0.0f) {
                    if (ctx->work.f32[0] < 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                } else if (m257_minigame->clockBaseSpeed[HAND_OBSTACLE] < 0.0f) {
                    if (ctx->work.f32[0] > 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                } else {
                    if (ctx->work.f32[0] != 0.0f) {
                        HuAudFXPlay(0x4BB);
                        fxPlayed = TRUE;
                    }
                }
                if (!fxPlayed) {
                    if (m257_minigame->clockBaseSpeed[HAND_PLATFORM] > 0.0f) {
                        if (ctx->work.f32[1] < 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else if (m257_minigame->clockBaseSpeed[HAND_PLATFORM] < 0.0f) {
                        if (ctx->work.f32[1] > 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else {
                        if (ctx->work.f32[1] != 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    }
                }
                m257_minigame->clockBaseSpeed[HAND_OBSTACLE] = ctx->work.f32[0];
                m257_minigame->clockBaseSpeed[HAND_PLATFORM] = ctx->work.f32[1];
                ctx->work.s8[1] = FALSE;
                m257_minigame->jumpsSinceSpeedChange = 0;
                m257_minigame->jumpsForSpeedChange = 2 + (rand16() & 1);
            }
        }
    }
}

void m257_UpdateClockObstacleRotation(FuncGroupContext* groupCtx, FuncContext* ctx) {
    s32 seNo;
    s16 currSeNo;
    s16 pitch;
    s16 basePitch;

    currSeNo = ctx->work.s16[0];
    m257_minigame->clockHandRot[HAND_OBSTACLE] += m257_minigame->clockBaseSpeed[HAND_OBSTACLE] * m257_minigame->clockSpeedMultiplier;
    if (m257_minigame->clockHandRot[HAND_OBSTACLE] < 0.0f) {
        m257_minigame->clockHandRot[HAND_OBSTACLE] += 360.0f;
    } else if (m257_minigame->clockHandRot[HAND_OBSTACLE] > 360.0f) {
        m257_minigame->clockHandRot[HAND_OBSTACLE] -= 360.0f;
    }
    Hu3DModelRotSet(groupCtx->modelIds[MDL_PLATFORM], 0.0f, m257_minigame->clockHandRot[HAND_OBSTACLE], 0.0f);
    if (m257_minigame->clockBaseSpeed[HAND_OBSTACLE] != 0.0f) {
        if (ctx->work.s8[0] == 0) {
            currSeNo = ctx->work.s16[0] = HuAudFXPlay(0x4BC);
            ctx->work.s8[0] = 1;
        }
        basePitch = m257_minigame->clockSpeedMultiplier * 150.0f;
        switch ((s16) ABS(m257_minigame->clockBaseSpeed[HAND_OBSTACLE])) {
            case 1:
                seNo = currSeNo;
                pitch = basePitch;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 2:
                seNo = currSeNo;
                pitch = basePitch + 150;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 3:
                seNo = currSeNo;
                pitch = basePitch + 300;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 4:
                seNo = currSeNo;
                pitch = basePitch + 450;
                HuAudFXPitchSet(seNo, pitch);
                break;
        }
    } else {
        if (ctx->work.s8[0] != 0) {
            HuAudFXStop(currSeNo);
            ctx->work.s8[0] = 0;
        }
    }
}

void m257_UpdateClockPlatformRotation(FuncGroupContext* groupCtx, FuncContext* ctx) {
    s32 seNo;
    s16 currSeNo;
    s16 pitch;
    s16 basePitch;

    currSeNo = ctx->work.s16[0];
    m257_minigame->clockHandRot[HAND_PLATFORM] += m257_minigame->clockBaseSpeed[HAND_PLATFORM] * m257_minigame->clockSpeedMultiplier;
    if (m257_minigame->clockHandRot[HAND_PLATFORM] < 0.0f) {
        m257_minigame->clockHandRot[HAND_PLATFORM] += 360.0f;
    } else if (m257_minigame->clockHandRot[HAND_PLATFORM] > 360.0f) {
        m257_minigame->clockHandRot[HAND_PLATFORM] -= 360.0f;
    }
    Hu3DModelRotSet(groupCtx->modelIds[MDL_OBSTACLE], 0.0f, m257_minigame->clockHandRot[HAND_PLATFORM], 0.0f);
    if (m257_minigame->clockBaseSpeed[HAND_PLATFORM] != 0.0f) {
        if (ctx->work.s8[0] == 0) {
            currSeNo = ctx->work.s16[0] = HuAudFXPlay(0x4BD);
            ctx->work.s8[0] = 1;
        }
        basePitch = m257_minigame->clockSpeedMultiplier * 150.0f;
        switch ((s16) ABS(m257_minigame->clockBaseSpeed[HAND_PLATFORM])) {
            case 1:
                seNo = currSeNo;
                pitch = basePitch;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 2:
                seNo = currSeNo;
                pitch = basePitch + 150;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 3:
                seNo = currSeNo;
                pitch = basePitch + 300;
                HuAudFXPitchSet(seNo, pitch);
                break;
            case 4:
                seNo = currSeNo;
                pitch = basePitch + 450;
                HuAudFXPitchSet(seNo, pitch);
                break;
        }
    } else {
        if (ctx->work.s8[0] != 0) {
            HuAudFXStop(currSeNo);
            ctx->work.s8[0] = 0;
        }
    }
}

f32 m257_GetRandInRange(s16 min, s16 max) {
    f32 rand;

    rand = rand16() % (max - min + 1) + min;
    if (rand16() & 1) {
        rand = -rand;
    }
    return rand;
}

void m257_CheckPlayerJumpStart(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    FuncContext* playerJumpCtx;
    s16 playerJumpId;

    if (!m257_jumpEnabled) {
        return;
    }
    if (player->stat & PLAYER_STAT_FINISHED) {
        m257_ResetFunc(object->work[1], ctx);
        return;
    }
    if (D_800CDA7C_CE67C[player->padId] & A_BUTTON) {
        if (ctx->work.s8[0] == 0 && !(player->stat & PLAYER_STAT_JUMPING) && player->state != PLAYER_STATE_LAND) {
            ctx->work.s8[0] = 1;
            player->stat |= PLAYER_STAT_JUMPING;
            playerJumpId = m257_SetFunc(object->work[1], 0xEFFF, player, m257_ExecPlayerJump, 0);
            playerJumpCtx = &m257_funcGroups[object->work[1]].funcCtx[playerJumpId];
            playerJumpCtx->func(groupCtx, playerJumpCtx);
        }
    } else {
        ctx->work.s8[0] = 0;
    }
}

void m257_UpdatePlayerPosition(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    f32 clockPlatformRot = m257_minigame->clockHandRot[HAND_PLATFORM];

    if (player->stat & PLAYER_STAT_LOST) {
        return;
    }
    if (ctx->state == 0) {
        if (m257_playerOrder[object->work[0]] == 0) {
            ctx->work.f32[0] = 185.0f;
            ctx->work.f32[1] = 185.0f;
        } else {
            ctx->work.f32[0] = 315.0f;
            ctx->work.f32[1] = 315.0f;
        }
        ctx->state = 1;
    }
    object->trans.x = HuMathSin(clockPlatformRot) * ctx->work.f32[0];
    object->trans.z = HuMathCos(clockPlatformRot) * ctx->work.f32[1];
    HmfModelData[object->model[1]].pos.x = object->trans.x;
    HmfModelData[object->model[1]].pos.z = object->trans.z;
    if (ABS(m257_minigame->clockHandRot[HAND_PLATFORM] - m257_minigame->clockHandRot[HAND_OBSTACLE]) < 10.0f) {
        HmfModelData[object->model[1]].pos.y = 30.0f;
    } else {
        HmfModelData[object->model[1]].pos.y = 5.0f;
    }
}

void m257_UpdatePlayerRotation(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    Vec direction;
    Vec origin;
    f32 rotAngles[3];

    if (player->stat & PLAYER_STAT_FINISHED) {
        m257_ResetFunc(object->work[1], ctx);
        return;
    }
    if (player->state == PLAYER_STATE_LAND || player->state == PLAYER_STATE_JUMP) {
        return;
    }
    if (D_800CBB6E_CC76E[player->padId] == 0 && D_800D20A1_D2CA1[player->padId] == 0) {
        m257_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
    } else {
        m257_SetPlayerState(player, PLAYER_STATE_WALK, TRUE);
        direction.x = -D_800CBB6E_CC76E[player->padId];
        direction.y = 0.0f;
        direction.z = D_800D20A1_D2CA1[player->padId];
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        m257_CalcPitchAndYaw(origin, direction, rotAngles);
        object->rot.y = rotAngles[1];
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void m257_ExecPlayerJump(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    f32 var_f2;
    f32 accelY;
    f32 scale;

    if (object->trans.y == 0.0f && (player->stat & PLAYER_STAT_LOST)) {
        m257_ResetFunc(object->work[1], ctx);
        return;
    }
    if (ctx->state == 0) {
        player->accelY = -1.47f;
        m257_SetBillDispOnRef(player->dustBillId, &object->trans.x, NULL, &object->trans.z);
        m257_SetPlayerState(player, PLAYER_STATE_JUMP, TRUE);
        CharFXPlay(0x3A, GwPlayer[m257_playerId[object->work[0]]].chr);
        ctx->state = 1;
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
        m257_SetBillDispOnRef(player->dustBillId, &object->trans.x, NULL, &object->trans.z);
        CharFXPlay(0x31, GwPlayer[m257_playerId[object->work[0]]].chr);
        m257_SetPlayerState(player, PLAYER_STATE_LAND, TRUE);
        m257_SetPlayerNextState(player, PLAYER_STATE_IDLE);
        m257_ResetFunc(object->work[1], ctx);
    }
}

void m257_CheckPlayerCollision(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;

    if ((player->stat & PLAYER_STAT_FINISHED) || m257_minigame->jumpCount == JUMPS_MAX) {
        return;
    }
    if (player->obstacleCollisionTracker->colliding) {
        func_8001C258_1CE58(object->model[7], 4, 0);
        Hu3DModelPosSet(object->model[7], object->trans.x, 10.0f, object->trans.z);
        m257_SetPlayerState(player, PLAYER_STATE_KNOCKED, TRUE);
        m257_SetFunc(object->work[1], 0xFF, player, m257_ExecPlayerKnockedOut, 0);
        player->stat |= PLAYER_STAT_LOST;
        if (!(GwPlayer[m257_playerId[object->work[0]]].stat & PLAYER_IS_CPU)) {
            omVibrate(object->work[0], 2, 2, 0x14);
        }
    }
}

void m257_ExecPlayerIntro(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;

    D_800CDA7C_CE67C[player->padId] = 0;
    D_800CBB6E_CC76E[player->padId] = 0;
    D_800D20A1_D2CA1[player->padId] = 0;
    if (player->obstacleProximityTracker->colliding) {
        ctx->work.s8[1] = 1;
        ctx->work.s8[0]++;
        if (ctx->work.s8[0] < 5) {
            D_800CDA7C_CE67C[player->padId] = A_BUTTON;
        }
    } else {
        ctx->work.s8[0] = 0;
        if (ctx->work.s8[1] != 0 && ctx->work.s8[2] == 0) {
            D_800CBB6E_CC76E[player->padId] = HuMathSin(ctx->work.f32[0]) * 70.0f;
            D_800D20A1_D2CA1[player->padId] = HuMathCos(ctx->work.f32[0]) * 70.0f;
            ctx->work.f32[0] += 10.0f;
            if (ctx->work.f32[0] > 180.0f) {
                ctx->work.f32[0] = 180.0f;
                ctx->work.s8[2] = 1;
            }
        }
    }
}

void m257_ExecPlayerWins(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    f32 lerpT;

    ctx->work.s16[3]++;
    if (ctx->work.s16[3] < 40) {
        return;
    }
    switch (ctx->state) {
        case 0:
            if (player->state == PLAYER_STATE_IDLE || player->state == PLAYER_STATE_WALK) {
                ctx->work.s16[0] = 0;
                ctx->work.f32[0] = object->rot.y;
                if (object->rot.y != 180.0f) {
                    m257_SetPlayerState(player, PLAYER_STATE_WALK, TRUE);
                    ctx->state = 1;
                } else {
                    m257_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
                    ctx->state = 2;
                }
            }
            break;
        case 1: // Face the camera.
            lerpT = ctx->work.s16[0] / 10.0f;
            if (lerpT > 1.0f) {
                lerpT = 1.0f;
            }
            object->rot.y = (180.0f - ctx->work.f32[0]) * lerpT + ctx->work.f32[0];
            ctx->work.s16[0]++;
            if (ctx->work.s16[0] >= 11) {
                ctx->work.s16[0] = 0;
                object->rot.y = 180.0f;
                m257_SetPlayerState(player, PLAYER_STATE_IDLE, TRUE);
                ctx->state = 2;
            }
            break;
        default:
            if (m257_minigame->jumpCount == JUMPS_MAX) { // Always false?
                m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExecBothPlayersWin, 0);
                m257_ResetFunc(object->work[1], ctx);
                break;
            }
            if (m257_playerWinsState == 0) {
                if (GMesStatGet() == GMES_STAT_NONE) {
                    m257_playerWinsState = 1;
                }
            } else if (m257_playerWinsState >= 2) {
                if (GMesStatGet() == GMES_STAT_NONE) {
                    m257_playerWinsState = 3;
                }
                if (m257_playerWinsState == 3) {
                    ctx->work.s16[0]++;
                    if (ctx->work.s16[0] >= 15) {
                        m257_ResetFunc(FGRP_MINIGAME, ctx);
                        m257_SetFunc(FGRP_MINIGAME, 0, NULL, m257_ExitOverlayOnWipeOut, 0);
                    }
                }
            } else {
                ctx->work.s16[0]++;
                if (ctx->work.s16[0] == 15) {
                    HuAudSeqPlay(0x67);
                    m257_SetPlayerState(player, PLAYER_STATE_WON, TRUE);
                    GMesCreate(GMES_MES_MG_WINNER, player->chr);
                    GwPlayer[m257_playerId[object->work[0]]].bonusCoin += 10;
                }
                if (GMesStatGet() != GMES_STAT_NONE) {
                    ctx->work.s16[0] = 0;
                    m257_playerWinsState = 2;
                }
            }
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void m257_ExecPlayerKnockedOut(FuncGroupContext* groupCtx, FuncContext* ctx) {
    omObjData* object = groupCtx->object;
    f32 rotDirection;
    f32 scale;
    f32 transY;

    if (ctx->state == 0) {
        if (m257_minigame->clockBaseSpeed[HAND_OBSTACLE] == 0.0f) {
            if (m257_minigame->clockBaseSpeed[HAND_PLATFORM] < 0.0f) {
                rotDirection = 1.0f;
            } else {
                rotDirection = -1.0f;
            }
        } else {
            if (m257_minigame->clockBaseSpeed[HAND_OBSTACLE] < 0.0f) {
                rotDirection = -1.0f;
            } else {
                rotDirection = 1.0f;
            }
        }
        ctx->work.f32[0] = m257_minigame->clockHandRot[HAND_PLATFORM] + rotDirection * 90.0f;
        while (ctx->work.f32[0] < 0.0f) {
            ctx->work.f32[0] += 360.0f;
        }
        while (ctx->work.f32[0] > 360.0f) {
            ctx->work.f32[0] -= 360.0f;
        }
        ctx->work.f32[1] = ctx->work.f32[2] = HuMathSin(45.0f) * 60.000004f;
        ctx->work.s16[0] = 0;
        func_8004AC98_4B898(0x287 + GwPlayer[m257_playerId[object->work[0]]].chr, m257_playerId[object->work[0]]);
        func_8004AC98_4B898(0x4BE, object->work[0]);
        ctx->state = 1;
    }
    object->trans.y += ctx->work.f32[1];
    ctx->work.f32[1] = ctx->work.f32[2] - ctx->work.s16[0] * 2.45f;
    ctx->work.s16[0]++;
    object->trans.x += HuMathSin(ctx->work.f32[0]) * 20.0f * 5.0f * 0.25f;
    object->trans.z += HuMathCos(ctx->work.f32[0]) * 20.0f * 5.0f * 0.25f;
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
        ctx->work.s16[0] = 0;
        object->trans.y = 10.0f;
        func_8001C258_1CE58(object->model[0], 4, 4);
        func_8001C258_1CE58(object->model[1], 4, 4);
        m257_ResetFunc(object->work[1], ctx);
    }
}

void m257_UpdatePlayerAnimation(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    HmfModel* model = &HmfModelData[object->model[0]];

    if (D_800CCF58_CDB58[model->unk02].unk02 - 1 <= model->unk40) {
        player->updateAnimation = TRUE;
    }
    if (player->updateAnimation) {
        func_800E5690_B8210_minigame(object, player->state);
        if (player->state == PLAYER_STATE_WON) {
            func_80045F1C_46B1C(D_800A178C[GwPlayer[m257_playerId[object->work[0]]].chr][0] | 0x30, -1, m257_playerId[object->work[0]]);
        }
        player->updateAnimation = FALSE;
        if (player->nextState != -1) {
            player->state = player->nextState;
            player->nextState = -1;
        }
    }
}

void m257_SetPlayerState(PlayerData* player, s32 state, s32 updateAnimation) {
    player->updateAnimation = updateAnimation;
    player->state = state;
}

void m257_SetPlayerNextState(PlayerData* player, s32 state) {
    player->nextState = state;
}

void m257_InitCom(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;
    omObjData* object = groupCtx->object;
    Quad obstacleProximityQuad = { {
        {  90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 400.0f },
        {  90.0f, 0.0f, 400.0f }
    } };

    switch (GwPlayer[m257_playerId[object->work[0]]].cpu_difficulty) {
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
    m257_SetColliderBaseQuad(m257_minigame->obstacleProximityColliderId, &obstacleProximityQuad, 0.0f);
    ctx->func = m257_UpdateComInput;
}

void m257_ResetPlayerInput(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;

    if (player->unk24 != 99) {
        D_800CDA7C_CE67C[player->padId] = 0;
        D_800CBB6E_CC76E[player->padId] = 0;
        D_800D20A1_D2CA1[player->padId] = 0;
    }
}

void m257_UpdateComInput(FuncGroupContext* groupCtx, FuncContext* ctx) {
    PlayerData* player = ctx->data;

    player->unk24 = 99;
    D_800CDA7C_CE67C[player->padId] = 0;
    D_800CBB6E_CC76E[player->padId] = 0;
    D_800D20A1_D2CA1[player->padId] = 0;
    if (player->stat & PLAYER_STAT_FROZEN) {
        return;
    }
    if (ctx->work.s8[0] == 0) {
        if (player->obstacleProximityTracker->colliding) {
            if (m257_minigame->jumpCount > player->comFreezeThreshold && rand16() % 6 == 0) {
                player->stat |= PLAYER_STAT_FROZEN;
            }
            if (ctx->work.s8[1] == 0) {
                ctx->work.s8[0] = 1;
                ctx->work.s8[1] = 1;
            }
        } else {
            ctx->work.s8[1] = 0;
        }
    }
    if (ctx->work.s8[0] == 1) {
        ctx->work.s16[0]++;
        if (ctx->work.s16[0] > rand16() % (player->comReactionDelay + 1)) {
            ctx->work.s16[0] = 0;
            ctx->work.s8[0] = 2;
            if (rand16() % (player->comShortJumpBias + 1) != 0
                && ABS(m257_minigame->clockBaseSpeed[HAND_PLATFORM] - m257_minigame->clockBaseSpeed[HAND_OBSTACLE]) > 2.0f)
            {
                ctx->work.s16[1] = 1;
            } else {
                ctx->work.s16[1] = 6;
            }
        }
    }
    if (ctx->work.s8[0] == 2) {
        ctx->work.s16[0]++;
        if (ctx->work.s16[0] <= ctx->work.s16[1]) {
            D_800CDA7C_CE67C[player->padId] = A_BUTTON;
        } else {
            ctx->work.s16[0] = 0;
            ctx->work.s8[0] = 0;
        }
    }
}
