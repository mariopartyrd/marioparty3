#include "overlays/ovl_37.h"
#include "overlays/minigame.h"
#include "gcc/memory.h"
#include "game/audio.h"
#include "game/camera.h"
#include "game/gamemes.h"
#include "game/gamework_data.h"
#include "game/hmflight.h"
#include "game/hmfman.h"
#include "game/pause.h"
#include "game/util.h"
#include "game/wipe.h"
#include "mallocblock.h"
#include "include_asm.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

#define FPS 30.0f

#define PLAYERS_TOTAL 2
#define SIGNS_TOTAL 2
#define SCREWS_TOTAL 6
#define NUTS_TOTAL 6

#define GOAL_POS_X 200.0f
#define JUMP_RANGE_X 25.0f

// C1F0
void func_8000B5F0_C1F0(u8 arg0);
s32 func_8000B710_C310(s32 arg0);

// 14EA0
void func_800142A0_14EA0(s32);
s16 func_80017790_18390(s16 model, s32 arg1, s32 arg2, s32 arg3);
s32 func_80017BB8_187B8(s32, s32);

// 20A20
void Hu3DAnimInit(s32);

// 8FB20
f32 HuMathSin(f32);

// pad
extern u16 D_800CDA7C_CE67C[];
extern u16 D_800D5558_D6158[];

// printfunc
s32 print8(u16 x, u16 y, char* src);

// unknown
extern s32 D_800A178C[][6];
extern char D_800D5218_D5E18[];
extern u16 D_800D530C_D5F0C;

// LOCAL

enum {
    FGRP_CAMERA,
    FGRP_MINIGAME,
    FGRP_NUTS_1,
    FGRP_NUTS_2,
    FGRP_PLAYER_1,
    FGRP_PLAYER_2
};

enum {
    MDL_ARROW = 9,
    MDL_BALLOON_B,
    MDL_BALLOON_A
};

enum {
    CUE_ARROW,
    CUE_BALLOON_B,
    CUE_BALLOON_A
};

typedef struct {
    /* 0x00 */ s16 modelId;
    /* 0x04 */ f32 startPosX;
} NutData; // Size 8

typedef struct {
    /* 0x00 */ s16 wallCount;
    /* 0x02 */ s16 screwCount;
    /* 0x04 */ NutData* nuts;
    /* 0x08 */ char unk08[4];
} PlayerWorld; // Size 0xC

typedef struct {
    /* 0x00 */ PlayerWorld* worlds;
    /* 0x04 */ s8 unk04;
    /* 0x08 */ f32 timer; // counted in frames
    /* 0x0C */ Work work;
} MinigameData; // Size 0x3C

#define PLAYER_STATE_ON_PLATFORM 0
#define PLAYER_STATE_1 1
#define PLAYER_STATE_ROTATE 2
#define PLAYER_STATE_TRANSITION 3
#define PLAYER_STATE_JUMP 4
#define PLAYER_STATE_FINISHED 5
#define PLAYER_STATE_WON 6
#define PLAYER_STATE_7 7
#define PLAYER_STATE_WAIT_CAM 8

#define PLAYER_ANIM_IDLE 0
#define PLAYER_ANIM_WALK 1
#define PLAYER_ANIM_RUN 2
#define PLAYER_ANIM_JUMP 6
#define PLAYER_ANIM_WON 13
#define PLAYER_ANIM_LOST 14
#define PLAYER_ANIM_32 32

enum {
    PLAYER_DIR_RIGHT,
    PLAYER_DIR_LEFT
};

typedef struct {
    /* 0x00 */ omObjData* object;
    /* 0x04 */ s16 padId;
    /* 0x08 */ f32 startPosX;
    /* 0x0C */ s16 state;
    /* 0x0E */ s16 direction;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 inputIdleTimer;
    /* 0x12 */ s8 inputEnabled;
    /* 0x13 */ s8 cuesEnabled;
    /* 0x14 */ s8 finished;
    /* 0x15 */ s8 lost;
    /* 0x18 */ f32 speed;
    /* 0x1C */ s8 currNutId;
    /* 0x20 */ f32 accelY;
    /* 0x24 */ s16 nutSeNo;
    /* 0x26 */ s8 nutSeActive;
    /* 0x28 */ Work work;
} PlayerData; // Size 0x58

void m255_InitEnvironment(void);
void m255_CreateMinigame(void);
void m255_CheckExitRequest(omObjData* object);
void m255_WaitExitWipeOut(omObjData* object);
void m255_ExitOverlay(omObjData* object);
void m255_InitMinigame(omObjData* object);
void m255_UpdateSystem(omObjData* object);
void m255_CreateWall(omObjData* object);
void m255_UpdateWall(omObjData* object);
void m255_CreateSigns(omObjData* object);
void m255_UpdateSigns(omObjData* object);
void m255_CreateScrews(omObjData* object);
void m255_UpdateScrews(omObjData* object);
void m255_CreateNuts(omObjData* object);
void m255_UpdateNuts(omObjData* object);
void m255_InitPlayer(omObjData* object);
void m255_UpdatePlayer(omObjData* object);
void m255_InitCamera(FuncContext* ctx);
void m255_FollowPlayerWithCamera(FuncContext* ctx);
void m255_ExecMinigameIntro(FuncContext* ctx);
void m255_ExecPlayersDraw(FuncContext* ctx);
void m255_CheckMinigameEnd(FuncContext* ctx);
void m255_ChooseNutsPositions(void);
void m255_SetWall(s16 modelId, s16 worldId);
void m255_SetScrew(s16 modelId, s16 worldId);
void m255_UpdateNutSpinning(FuncContext* ctx);
void m255_UpdatePlayerCue(FuncContext* ctx);
void m255_ExecPlayerWins(FuncContext* ctx);
void m255_UpdatePlayerSpeed(FuncContext* ctx);
void m255_UpdatePlayerAnimation(FuncContext* ctx);
void m255_LerpPlayerRotation(FuncContext* ctx);
void m255_ExecPlayerJump(FuncContext* ctx);
void m255_UpdateComInput(FuncContext* ctx);
f32 func_8010B18C_2B4A3C_silly_screws(PlayerData* player);

const s16 D_8010BE50_2B5700_silly_screws[] = {
    0x8272, 0x8273, 0x8260, 0x8271, 0x8273, 0x0000
};

const s16 D_8010BE5C_2B570C_silly_screws[] = {
    0x8265, 0x8268, 0x826D, 0x8268, 0x8272, 0x8267, 0x0000, 0x0000
};

const s16 D_8010BE6C_2B571C_silly_screws[] = {
    0x8263, 0x8271, 0x8260, 0x8276, 0x0000, 0x0000
};

MinigameData* BSS m255_minigame;
PlayerData* BSS m255_players;
s16 BSS m255_playerId[PLAYERS_TOTAL];

s16 D_8010BE20_2B56D0_silly_screws = -1;
s16 D_8010BE22_2B56D2_silly_screws = 0;
s16 D_8010BE24_2B56D4_silly_screws = 0;
s16 D_8010BE26_2B56D6_silly_screws = 0;
s16 D_8010BE28_2B56D8_silly_screws = 0;

s32 D_8010BE2C_2B56DC_silly_screws[] = {
    0x000200A5, 0x000300A5, 0x000700A5, 0x000400A5, 0x000500A5, 0x000600A5, 0x000800A5, 0x0009001C
};

s16 D_8010BE4C_2B56FC_silly_screws = 0;
s16 D_8010BE4E_2B56FE_silly_screws = 0;

void m255_OverlayMain(void) {
    m255_InitEnvironment();
}

void m255_InitEnvironment(void) {
    omObjData* temp_v0;

    Hu3DAnimInit(50);
    func_800142A0_14EA0(0x20);
    omInitObjMan(50, 0);
    func_8004A208_4AE08();
    temp_v0 = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    temp_v0->work[0] = 2;
    omSetStatBit(temp_v0, 0xA0);
    HmfLightColorSet(0, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightDirSet(1, -56.0f, 50.0f, 56.0f);
    func_8000B5F0_C1F0(2);
    func_8000B710_C310(2);
    ScissorSet(0, 0.0f, 0.0f, 159.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 60.0f, 80.0f, 4000.0f);
    ScissorSet(1, 161.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 60.0f, 80.0f, 4000.0f);
    D_800EC1B8_BED38_minigame = 0;
    D_800EC280_BEE00_minigame = 0;
    D_800EBE28_BE9A8_minigame = 0;
    m255_CreateSystem();
    m255_CreateMinigame();
    m255_SetFunc(FGRP_CAMERA, 0, -1, 0, m255_InitCamera, FALSE, FALSE);
    omAddObj(100, 0, 0, -1, m255_InitMinigame);
    omAddObj(1000, 0, 0, -1, m255_CheckExitRequest);
    func_80045010_45C10(D_8010BE50_2B5700_silly_screws, 1);
    func_80045010_45C10(D_8010BE5C_2B570C_silly_screws, 1);
    func_80045010_45C10(D_8010BE6C_2B571C_silly_screws, 1);
}

void m255_CreateMinigame(void) {
    s16 i;

    m255_minigame = HuMemAllocTag(sizeof(MinigameData), 31000);
    memset(m255_minigame, 0, sizeof(MinigameData));
    m255_minigame->worlds = HuMemAllocTag(PLAYERS_TOTAL * sizeof(PlayerWorld), 31000);
    memset(m255_minigame->worlds, 0, PLAYERS_TOTAL * sizeof(PlayerWorld));
    for (i = 0; i < PLAYERS_TOTAL; i++) {
        m255_minigame->worlds[i].nuts = HuMemAllocTag(NUTS_TOTAL * sizeof(NutData), 31000);
        memset(m255_minigame->worlds[i].nuts, 0, NUTS_TOTAL * sizeof(NutData));
    }
    m255_players = HuMemAllocTag(PLAYERS_TOTAL * sizeof(PlayerData), 31000);
    memset(m255_players, 0, PLAYERS_TOTAL * sizeof(PlayerData));
    m255_ChooseNutsPositions();
}

void m255_CheckExitRequest(omObjData* object) {
    if (D_800D530C_D5F0C == 1) {
        WipeCreateOut(0, 20);
        object->func = m255_WaitExitWipeOut;
    }
}

void m255_WaitExitWipeOut(omObjData* object) {
    if (WipeStatGet() == 0) {
        object->func = m255_ExitOverlay;
    }
}

void m255_ExitOverlay(omObjData* object) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void m255_UpdateCameras(void) {
    s16 i;

    for (i = 0; i < PLAYERS_TOTAL; i++) {
        if (CRotM[i].x > 360.0f) {
            CRotM[i].x -= 360.0f;
        } else if (CRotM[i].x < 0.0f) {
            CRotM[i].x += 360.0f;
        }
        if (CRotM[i].y > 360.0f) {
            CRotM[i].y -= 360.0f;
        } else if (CRotM[i].y < 0.0f) {
            CRotM[i].y += 360.0f;
        }
    }
    m255_UpdateFuncGroup(FGRP_CAMERA);
}

void m255_InitMinigame(omObjData* object) {
    s16 player1Set = FALSE;
    s16 player2Set = FALSE;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            if (!player1Set) {
                m255_playerId[0] = i;
                player1Set = TRUE;
            }
        } else if (GwPlayer[i].group == 1) {
            if (!player2Set) {
                m255_playerId[1] = i;
                player2Set = TRUE;
            }
        }
    }
    func_800E18D8_B4458_minigame();
    func_800E19F0_B4570_minigame(1);
    for (i = 0; i < PLAYERS_TOTAL; i++) {
        omAddObj(10, 8, 0, -1, m255_CreateWall);
        omAddObj(10, 2, 0, -1, m255_CreateSigns);
        omAddObj(10, 7, 0, -1, m255_CreateScrews);
        omAddObj(10, 6, 0, -1, m255_CreateNuts);
        D_800EC598_BF118_minigame[i] = omAddObj(300, 12, 38, -1, m255_InitPlayer);
    }
    m255_SetSpriteDispOn(m255_SetSprite(0x58, 0xF, 0, 0), 160, 120);
    m255_SetFunc(FGRP_MINIGAME, 1, -1, 0, m255_ExecMinigameIntro, TRUE, FALSE);
    WipeCreateIn(0xFF, 0x10);
    object->func = m255_UpdateSystem;
}

void m255_UpdateSystem(omObjData* object) {
    m255_UpdateFuncGroup(FGRP_MINIGAME);
    m255_UpdateCameras();
    m255_UpdateSprites();
}

void m255_CreateWall(omObjData* object) {
    s16 var_a1;
    s16 i;

    object->work[0] = m255_minigame->work.s8[0];
    object->model[0] = func_8000B108_BD08(0x580000, 0x9D); // checkered flat wall segment
    for (i = 1; i < 5; i++) {
        if (i == 4) {
            object->model[i] = func_8000B108_BD08(0x580001, 0x9D); // ending platform + wall
        } else {
            object->model[i] = Hu3DModelLink(object->model[0]);
        }
    }
    for (i = 5; i < 8; i++) {
        if (i == 5) {
            object->model[i] = func_8000B108_BD08(0x580009, 0x9D); // wall pipes
        } else {
            object->model[i] = Hu3DModelLink(object->model[5]);
        }
        Hu3DModelPosSet(object->model[i], 0.0f, 0.0f, -(200.0f + (i - 5) * 900.0f));
    }
    for (i = 0; i < 4; i++) {
        m255_SetWall(object->model[i], object->work[0]);
    }
    Hu3DModelPosSet(object->model[4], 0.0f, 0.0f, -2050.0f);
    m255_SyncWithModel(object);
    var_a1 = (object->work[0] == 0) ? 1 : 2;
    for (i = 0; i < 8; i++) {
        func_8001C8A8_1D4A8(object->model[i], var_a1);
    }
    m255_minigame->work.s8[0]++;
    object->func = m255_UpdateWall;
}

void m255_UpdateWall(omObjData* object) {
    s16 i;

    if (m255_minigame->unk04 != 0) {
        for (i = 0; i < 8; i++) {
            func_8001C258_1CE58(object->model[i], 4, 4);
        }
    }
    for (i = 0; i < 8; i++) {
        HmfModel* model = &HmfModelData[object->model[i]];

        if (i < 5) {
            if (CenterM[object->work[0]].z - 1050.0f < model->pos.z) {
                func_8001C258_1CE58(object->model[i], 4, 0);
            }
            if (CenterM[object->work[0]].z + 1600.0f < model->pos.z) {
                func_8001C258_1CE58(object->model[i], 4, 4);
                if (i != 4) {
                    m255_SetWall(object->model[i], object->work[0]);
                }
            }
        } else {
            if (CenterM[object->work[0]].z - 1500.0f < model->pos.z) {
                func_8001C258_1CE58(object->model[i], 4, 0);
            }
            if (CenterM[object->work[0]].z + 1700.0f < model->pos.z) {
                func_8001C258_1CE58(object->model[i], 4, 4);
            }
        }
    }
    m255_SyncWithModel(object);
}

void m255_CreateSigns(omObjData* object) {
    s16 var_a1;
    s16 i;

    object->work[0] = m255_minigame->work.s8[3];
    object->model[0] = func_8000B108_BD08(0x58000C, 0x9D);
    for (i = 1; i < SIGNS_TOTAL; i++) {
        object->model[i] = Hu3DModelLink(object->model[0]);
    }
    for (i = 0; i < SIGNS_TOTAL; i++) {
        Hu3DModelPosSet(object->model[i], 0.0f, 1300.0f, -(675.0f + i * 900.0f));
    }
    m255_SyncWithModel(object);
    var_a1 = (object->work[0] == 0) ? 1 : 2;
    for (i = 0; i < SIGNS_TOTAL; i++) {
        func_8001C8A8_1D4A8(object->model[i], var_a1);
    }
    m255_minigame->work.s8[3]++;
    object->func = m255_UpdateSigns;
}

void m255_UpdateSigns(omObjData* object) {
    s16 i;

    for (i = 0; i < SIGNS_TOTAL; i++) {
        HmfModel* model = &HmfModelData[object->model[i]];

        if (CenterM[object->work[0]].z - 1050.0f < model->pos.z) {
            func_8001C258_1CE58(object->model[i], 4, 0);
        }
        if (CenterM[object->work[0]].z + 1600.0f < model->pos.z) {
            func_8001C258_1CE58(object->model[i], 4, 4);
            if (i != 4) {
                m255_SetWall(object->model[i], object->work[0]);
            }
        }
    }
    m255_SyncWithModel(object);
}

void m255_CreateScrews(omObjData* object) {
    s16 var_a1;
    s16 i;

    object->work[0] = m255_minigame->work.s8[2];
    object->model[0] = func_8000B108_BD08(0x580002, 0x9D);
    for (i = 1; i < SCREWS_TOTAL + 1; i++) {
        if (i == 6) {
            object->model[i] = func_8000B108_BD08(0x58000A, 0x9D);
        } else {
            object->model[i] = Hu3DModelLink(object->model[0]);
        }
    }
    for (i = 0; i < SCREWS_TOTAL; i++) {
        m255_SetScrew(object->model[i], object->work[0]);
    }
    Hu3DModelPosSet(object->model[6], 0.0f, 1800.0f, -2650.0f);
    m255_SyncWithModel(object);
    var_a1 = (object->work[0] == 0) ? 1 : 2;
    for (i = 0; i < SCREWS_TOTAL + 1; i++) {
        func_8001C8A8_1D4A8(object->model[i], var_a1);
    }
    m255_minigame->work.s8[2]++;
    object->func = m255_UpdateScrews;
}

void m255_UpdateScrews(omObjData* object) {
    s16 i;

    for (i = 0; i < SCREWS_TOTAL; i++) {
        HmfModel* model = &HmfModelData[object->model[i]];

        if (CenterM[object->work[0]].z - 800.0f < model->pos.z) {
            func_8001C258_1CE58(object->model[i], 4, 0);
        }
        if (CenterM[object->work[0]].z + 800.0f < model->pos.z) {
            func_8001C258_1CE58(object->model[i], 4, 4);
            if (i != 6) {
                m255_SetScrew(object->model[i], object->work[0]);
            }
        }
    }
    m255_SyncWithModel(object);
}

void m255_CreateNuts(omObjData* object) {
    PlayerWorld* world = &m255_minigame->worlds[m255_minigame->work.s8[1]];
    s32 file[] = { 3, 4, 5, 6, 7, 8 };
    s16 var_s4;
    s16 i;

    object->work[0] = m255_minigame->work.s8[1];
    var_s4 = (object->work[0] == 0) ? 1 : 2;
    for (i = 0; i < NUTS_TOTAL; i++) {
        object->model[i] = world->nuts[i].modelId = func_8000B108_BD08(0x580000 | file[i], 0x9D);
        Hu3DModelPosSet(object->model[i], m255_minigame->worlds[object->work[0]].nuts[i].startPosX, 1800.0f, 0.0f - i * 450.0f);
        func_8001C8A8_1D4A8(object->model[i], var_s4);
    }
    m255_SyncWithModel(object);
    m255_minigame->work.s8[1]++;
    m255_SetFunc(FGRP_NUTS_1 + object->work[0], 0, object->work[0], &m255_minigame->worlds[object->work[0]], m255_UpdateNutSpinning, FALSE, FALSE);
    object->func = m255_UpdateNuts;
}

void m255_UpdateNuts(omObjData* object) {
    s16 i;

    if (m255_minigame->unk04 != 0) {
        for (i = 0; i < NUTS_TOTAL; i++) {
            func_8001C258_1CE58(object->model[i], 4, 4);
        }
    }
    m255_UpdateFuncGroup(FGRP_NUTS_1 + object->work[0]);
    m255_SyncWithModel(object);
}

void m255_InitPlayer(omObjData* object) {
    s8* unkData;
    s32 temp_v0_2;
    s32 temp_a1;
    s16 var_a1;
    s16 chr;
    s16 i;

    object->work[0] = D_800EC280_BEE00_minigame;
    object->work[1] = m255_playerId[object->work[0]];
    chr = GwPlayer[object->work[1]].chr;
    temp_a1 = D_800A178C[GwPlayer[object->work[1]].chr][0];
    temp_v0_2 = D_800A178C[GwPlayer[object->work[1]].chr][2];
    func_800E1BA8_B4728_minigame(object, temp_a1, temp_v0_2, object->work[1], 0x2A9, 0x2B9);
    object->model[MDL_ARROW] = func_8000B108_BD08(0x58000B, 0x2B9);
    object->model[MDL_BALLOON_B] = func_8000B108_BD08(0x58000D, 0x2B9);
    object->model[MDL_BALLOON_A] = func_8000B108_BD08(0x58000E, 0x2B9);
    Hu3DModelScaleSet(object->model[MDL_ARROW], 1.25f, 1.25f, 1.25f);
    Hu3DModelScaleSet(object->model[MDL_BALLOON_B], 1.25f, 1.25f, 1.25f);
    Hu3DModelScaleSet(object->model[MDL_BALLOON_A], 1.25f, 1.25f, 1.25f);
    func_8001C258_1CE58(object->model[MDL_ARROW], 4, 4);
    func_8001C258_1CE58(object->model[MDL_BALLOON_B], 4, 4);
    func_8001C258_1CE58(object->model[MDL_BALLOON_A], 4, 4);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_IDLE, func_80017BB8_187B8(chr, 0), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_WALK, func_80017BB8_187B8(chr, 1), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_RUN, func_80017BB8_187B8(chr, 2), 1, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_JUMP, func_80017BB8_187B8(chr, 4), 1, 19);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_32, func_80017BB8_187B8(chr, 0x22), 0, 0);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_LOST, func_80017BB8_187B8(chr, 0x36), 1, 999);
    func_800E5A00_B8580_minigame(object, PLAYER_ANIM_WON, func_80017BB8_187B8(chr, 0x2F), 1, 999);
    object->trans.x = m255_players[object->work[0]].startPosX;
    object->trans.y = 2000.0f;
    object->trans.z = 0.0f;
    object->rot.y = 180.0f;
    func_800E5690_B8210_minigame(object, PLAYER_ANIM_IDLE);
    Hu3DModelPosSet(object->model[1], object->trans.x, object->trans.y, object->trans.z);
    func_8001C258_1CE58(object->model[1], 4, 0);
    D_800EC280_BEE00_minigame++;
    unkData = object->data;
    m255_players[object->work[0]].padId = unkData[0x57]; // TODO: figure out type.
    m255_players[object->work[0]].object = object;
    m255_players[object->work[0]].direction = PLAYER_DIR_RIGHT;
    m255_players[object->work[0]].currNutId = 0;
    m255_players[object->work[0]].inputEnabled = TRUE;
    m255_players[object->work[0]].cuesEnabled = TRUE;
    m255_players[object->work[0]].nutSeActive = FALSE;
    var_a1 = (object->work[0] == 0) ? 1 : 2;
    for (i = 0; i < 12; i++) {
        func_8001C8A8_1D4A8(object->model[i], var_a1);
    }
    m255_SetFunc(FGRP_PLAYER_1 + object->work[0], 9, -1, &m255_players[object->work[0]], m255_UpdatePlayerAnimation, FALSE, FALSE);
    object->func = m255_UpdatePlayer;
}

void m255_UpdatePlayer(omObjData* object) {
    m255_UpdateFuncGroup(FGRP_PLAYER_1 + object->work[0]);
    func_800E4E30_B79B0_minigame(object);
}

void m255_InitCamera(FuncContext* ctx) {
    s16 i;

    switch (ctx->state) {
        case 0:
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                CenterM[i].x = 372.0f;
                CenterM[i].y = 2019.0f;
                if (i == 0) {
                    CenterM[i].z = -2890.0f;
                } else {
                    CenterM[i].z = -2970.0f;
                }
                CRotM[i].x = 323.0f;
                CRotM[i].y = 77.0f;
                CRotM[i].z = 0.0f;
                CZoomM[i] = 1240.0f;
            }
            m255_ResetFunc(FGRP_CAMERA, ctx);
            break;
    }
}

// TODO: only works with -Wa,--vr4300mul-off.
#ifdef NON_MATCHING
void m255_ExecCameraIntro(FuncContext* ctx) {
    s16 camId = ctx->unk06;
    f32 temp_f22;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 0;
            ctx->state = 1;
            break;
        case 1:
            temp_f22 = ctx->work.s8[0] * 0.008333334f;
            temp_f22 = HuMathSin(temp_f22 * 90.0f) * HuMathSin(temp_f22 * 90.0f);
            CZoomM[camId] = temp_f22 * 0.0f + 1240.0f;
            CenterM[camId].x = temp_f22 * 0.0f + 372.0f;
            CenterM[camId].y = temp_f22 * 0.0f + 2019.0f;
            if (camId == 0) {
                CenterM[camId].z = temp_f22 * 2693.0f + -2890.0f;
            } else {
                CenterM[camId].z = temp_f22 * 2693.0f + -2970.0f;
            }
            CRotM[camId].x = temp_f22 * 0.0f + 323.0f;
            CRotM[camId].y = temp_f22 * 0.0f + 77.0f;
            ctx->work.s8[0]++;
            if (ctx->work.s8[0] > 120.0f) {
                CZoomM[camId] = 1240.0f;
                CenterM[camId].x = 372.0f;
                CenterM[camId].y = 2019.0f;
                if (camId == 0) {
                    CenterM[camId].z = -197.0f;
                } else {
                    CenterM[camId].z = -277.0f;
                }
                CRotM[camId].x = 323.0f;
                CRotM[camId].y = 77.0f;
                m255_ResetFunc(FGRP_CAMERA, ctx);
                m255_minigame->unk04 = 1;
                m255_SetFunc(FGRP_CAMERA, 0, camId, &m255_minigame->unk00[camId], m255_FollowPlayerWithCamera, FALSE, FALSE);
            }
            break;
    }
}
#else
void m255_ExecCameraIntro(FuncContext* ctx);
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_37_silly_screws/main", m255_ExecCameraIntro);
#endif

void m255_CenterCameraOnWinner(FuncContext* ctx) {
    PlayerData* player = ctx->data;
    s16 camId = player->object->work[0];
    f32 temp_f0;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 0;
            ctx->work.f32[0] = CenterM[camId].z;
            ctx->work.f32[1] = player->object->trans.z - 70.0f;
            player->state = PLAYER_STATE_WAIT_CAM;
            ctx->state = 1;
            break;
        case 1:
            temp_f0 = ctx->work.s8[0] * 0.02f;
            temp_f0 = HuMathSin(temp_f0 * 90.0f);
            CZoomM[camId] = temp_f0 * -1010.0f + 1240.0f;
            CenterM[camId].x = temp_f0 * -113.0f + 372.0f;
            CenterM[camId].y = temp_f0 * 5.0f + 2019.0f;
            if (camId == 0) {
                CenterM[camId].z = (ctx->work.f32[1] - ctx->work.f32[0]) * temp_f0 + ctx->work.f32[0];
            } else {
                CenterM[camId].z = (ctx->work.f32[1] - ctx->work.f32[0]) * temp_f0 + ctx->work.f32[0];
            }
            CRotM[camId].x = temp_f0 * 26.0f + 323.0f;
            CRotM[camId].y = temp_f0 * 50.0f + 77.0f;
            player->object->rot.y = temp_f0 * -53.0f + 180.0f;
            ctx->work.s8[0]++;
            if (ctx->work.s8[0] > 50.0f) {
                CZoomM[camId] = 230.0f;
                CenterM[camId].x = 259.0f;
                CenterM[camId].y = 2024.0f;
                if (camId == 0) {
                    CenterM[camId].z = ctx->work.f32[1];
                } else {
                    CenterM[camId].z = ctx->work.f32[1];
                }
                CRotM[camId].x = 349.0f;
                CRotM[camId].y = 127.0f;
                m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 3, -1, player, m255_ExecPlayerWins, FALSE, FALSE);
                m255_ResetFunc(FGRP_CAMERA, ctx);
            }
            break;
    }
}

void m255_FollowPlayerWithCamera(FuncContext* ctx) {
    PlayerData* player;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = ctx->param;
            ctx->state = 1;
            break;
        case 1:
            m255_minigame->unk04 = 0;
            player = &m255_players[ctx->work.s8[0]];
            if (player->state == PLAYER_STATE_FINISHED || player->state == PLAYER_STATE_7 || player->state == PLAYER_STATE_WAIT_CAM) {
                m255_ResetFunc(FGRP_CAMERA, ctx);
                break;
            }
            if (player->object->trans.z < CenterM[ctx->work.s8[0]].z + 197.0f) {
                CenterM[ctx->work.s8[0]].z = player->object->trans.z - 197.0f;
            }
            break;
    }
}

void m255_UpdateDebugCamera(FuncContext* ctx) {
    s16 camId = ctx->work.s8[3];
    u16 temp_a0;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 1;
            ctx->work.s8[1] = 0;
            ctx->work.s8[2] = 0;
            ctx->work.s8[3] = 0;
            ctx->state = 1;
            break;
        case 1:
            if (ctx->work.s8[1] != 0) {
                if (ctx->work.s8[1] == 1) {
                    sprintf(D_800D5218_D5E18, "C: TRANSLATE ADD: %d", ctx->work.s8[0]);
                } else {
                    sprintf(D_800D5218_D5E18, "C: ROTATE");
                }
                print8(16, 56, D_800D5218_D5E18);
                sprintf(D_800D5218_D5E18, "CZOOMM %.2f", CZoomM[camId]);
                print8(16, 64, D_800D5218_D5E18);
                sprintf(D_800D5218_D5E18, "CCENTER_X %.2f Y %.2f Z %.2f", CenterM[camId].x, CenterM[camId].y, CenterM[camId].z);
                print8(16, 72, D_800D5218_D5E18);
                sprintf(D_800D5218_D5E18, "CROTATE_X %.2f Y %.2f Z %.2f", CRotM[camId].x, CRotM[camId].y, CRotM[camId].z);
                print8(16, 80, D_800D5218_D5E18);
            }
            temp_a0 = D_800CDA7C_CE67C[0];
            if (D_800D5558_D6158[0] & Z_TRIG) {
                ctx->work.s8[1]++;
            }
            if (ctx->work.s8[1] >= 3) {
                ctx->work.s8[1] = 0;
            }
            if (D_800D5558_D6158[0] & R_TRIG) {
                ctx->work.s8[3]++;
            }
            if (ctx->work.s8[3] >= 2) {
                ctx->work.s8[3] = 0;
            }
            if (ctx->work.s8[1] == 1) {
                if (temp_a0 & D_JPAD) {
                    CenterM[camId].z += ctx->work.s8[0];
                }
                if (temp_a0 & L_JPAD) {
                    CenterM[camId].x += ctx->work.s8[0];
                }
                if (temp_a0 & U_JPAD) {
                    CenterM[camId].z -= ctx->work.s8[0];
                }
                if (temp_a0 & R_JPAD) {
                    CenterM[camId].x -= ctx->work.s8[0];
                }
                if (temp_a0 & U_CBUTTONS) {
                    CenterM[camId].y += ctx->work.s8[0];
                }
                if (temp_a0 & D_CBUTTONS) {
                    CenterM[camId].y -= ctx->work.s8[0];
                }
                if (ctx->work.s8[2] == 15) {
                    ctx->work.s8[2] = 0;
                    if (temp_a0 & A_BUTTON) {
                        ctx->work.s8[0]++;
                    }
                    if (temp_a0 & B_BUTTON) {
                        ctx->work.s8[0]--;
                    }
                    if (ctx->work.s8[0] >= 125) {
                        ctx->work.s8[0] = 0;
                    }
                } else {
                    ctx->work.s8[2]++;
                }
            } else if (ctx->work.s8[1] == 2) {
                if (temp_a0 & D_JPAD) {
                    CRotM[camId].x += 1.0f;
                }
                if (temp_a0 & U_JPAD) {
                    CRotM[camId].x -= 1.0f;
                }
                if (temp_a0 & L_JPAD) {
                    CRotM[camId].y -= 1.0f;
                }
                if (temp_a0 & R_JPAD) {
                    CRotM[camId].y += 1.0f;
                }
                if (temp_a0 & U_CBUTTONS) {
                    CZoomM[camId] += 10.0f;
                }
                if (temp_a0 & D_CBUTTONS) {
                    CZoomM[camId] -= 10.0f;
                }
            }
            break;
    }
}

void m255_UpdateTimer(FuncContext* ctx) {
    s16 i;

    if (D_8010BE24_2B56D4_silly_screws != 0) {
        return;
    }
    switch (ctx->state) {
        case 0:
            ctx->state = 1;
            break;
        case 1:
            m255_minigame->timer -= 1.0f;
            if (m255_minigame->timer < 30.0f * FPS) {
                ctx->state = 3;
            }
            break;
        case 3:
            m255_minigame->timer -= 1.0f;
            GMesCreate(GMES_MES_TIMER, m255_minigame->timer / FPS, 160, 28);
            func_8003F578_40178((m255_minigame->timer + (FPS - 1.0f)) / FPS);
            ctx->state = 4;
            break;
        case 4:
            m255_minigame->timer -= 1.0f;
            func_8003F578_40178((m255_minigame->timer + (FPS - 1.0f)) / FPS);
            if (m255_minigame->timer < 0.0f) {
                D_8010BE22_2B56D2_silly_screws = 1;
                func_8003F5C0_401C0();
                m255_ResetFunc(FGRP_MINIGAME, ctx);
                m255_SetFunc(FGRP_MINIGAME, 0, -1, NULL, m255_ExecPlayersDraw, FALSE, FALSE);
                for (i = 0; i < PLAYERS_TOTAL; i++) {
                    m255_players[i].lost = TRUE;
                }
            }
            break;
    }
}

void m255_ExecMinigameIntro(FuncContext* ctx) {
    PlayerData* player = m255_players;
    s16 i;

    switch (ctx->state) {
        case 0:
            ctx->state = 1;
            break;
        case 1:
            switch (ctx->work.s16[0]++) {
                case 5:
                    for (i = 0; i < PLAYERS_TOTAL; i++) {
                        m255_SetFunc(FGRP_CAMERA, 0, i, NULL, m255_ExecCameraIntro, FALSE, FALSE);
                    }
                    break;
                case 125:
                    GMesCreate(GMES_MES_MG_START);
                    HuAudFXPlay(0xE);
                    D_8010BE28_2B56D8_silly_screws = 1;
                    break;
                case 140:
                    D_8010BE26_2B56D6_silly_screws = 1;
                    break;
                default:
                    if (D_8010BE26_2B56D6_silly_screws != 0 && GMesStatGet() == 2) {
                        for (i = 0; i < PLAYERS_TOTAL; i++, player++) {
                            if (GwPlayer[m255_playerId[i]].stat & PLAYER_IS_CPU) {
                                m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 1, -1, player, m255_UpdateComInput, FALSE, FALSE);
                                m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 2, -1, player, m255_UpdatePlayerSpeed, FALSE, FALSE);
                            } else {
                                m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 2, -1, player, m255_UpdatePlayerSpeed, FALSE, FALSE);
                            }
                            m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 0, -1, player, m255_UpdatePlayerCue, FALSE, FALSE);
                        }
                        m255_SetFunc(FGRP_MINIGAME, 0, -1, NULL, m255_UpdateTimer, FALSE, FALSE);
                        m255_SetFunc(FGRP_MINIGAME, 1, -1, NULL, m255_CheckMinigameEnd, FALSE, FALSE);
                        m255_ResetFunc(FGRP_MINIGAME, ctx);
                    }
                    break;
            }
    }
    if (D_8010BE28_2B56D8_silly_screws != 0 && GMesStatGet() != GMES_STAT_NONE) {
        D_8010BE28_2B56D8_silly_screws++;
        if (D_8010BE28_2B56D8_silly_screws >= 45) {
            HuAudSeqPlay(0x38);
            D_8010BE28_2B56D8_silly_screws = 0;
        }
    }
}

void m255_ExecMinigameFinish(FuncContext* ctx) {
    s16 temp_v1;

    switch (ctx->state) {
        case 0:
            ctx->state = 1;
            break;
        case 1:
            temp_v1 = ctx->work.s16[0]++;
            if (temp_v1 == 3) {
                HuAudSeqFadeOut(120);
                GMesCreate(GMES_MES_MG_FINISH);
                ctx->work.s16[0] = 0;
                ctx->state = 10;
            }
            break;
        case 2:
            if (WipeStatGet() == 0) {
                omOvlReturnEx(1);
            }
            break;
        case 10:
            if (D_8010BE20_2B56D0_silly_screws == 0) {
                if (GMesStatGet() == GMES_STAT_NONE) {
                    ctx->work.s16[0] = 0;
                    D_8010BE20_2B56D0_silly_screws = 1;
                }
            } else if (D_8010BE20_2B56D0_silly_screws == 1) {
                ctx->work.s16[0]++;
                if (ctx->work.s16[0] >= 15) {
                    WipeCreateOut(0, 20);
                    ctx->state = 2;
                }
            }
            break;
    }
}

void m255_ExecPlayersDraw(FuncContext* ctx) {
    s16 i;

    switch (ctx->state) {
        case 0:
            for (i = 0; i < PLAYERS_TOTAL; i++) {
                m255_players[i].cuesEnabled = FALSE;
                func_8001C258_1CE58(m255_players[i].object->model[MDL_ARROW], 4, 4);
                func_8001C258_1CE58(m255_players[i].object->model[MDL_BALLOON_B], 4, 4);
                func_8001C258_1CE58(m255_players[i].object->model[MDL_BALLOON_A], 4, 4);
            }
            ctx->work.s16[0] = 0;
            ctx->state = 1;
            break;
        case 1:
            switch (ctx->work.s16[0]++) {
                case 0:
                    HuAudSeqFadeOut(120);
                    GMesCreate(GMES_MES_MG_FINISH);
                    ctx->state = 3;
                    break;
                case 15:
                    GMesCreate(GMES_MES_MG_DRAW);
                    HuAudSeqPlay(0x6C);
                    ctx->state = 3;
                    break;
                case 30:
                    WipeCreateOut(0, 20);
                    ctx->state = 2;
                    break;
            }
            break;
        case 2:
            if (WipeStatGet() == 0) {
                omOvlReturnEx(1);
            }
            break;
        case 3:
            if (GMesStatGet() == GMES_STAT_NONE) {
                ctx->state = 1;
            }
            break;
    }
}

void m255_CheckMinigameEnd(FuncContext* ctx) {
    PlayerData* player = m255_players;
    s16 winnerCount = 0;
    s16 winners[] = { -1, -1 };
    u8 unused_stack[8];
    s16 i;

    if (D_8010BE22_2B56D2_silly_screws != 0) {
        return;
    }
    switch (ctx->state) {
        case 0:
            ctx->state = 1;
            break;
        case 1:
            for (i = 0; i < PLAYERS_TOTAL; i++, player++) {
                if (player->finished) {
                    winners[winnerCount] = i;
                    winnerCount++;
                }
            }
            if (winnerCount == 0) {
                break;
            }
            D_8010BE24_2B56D4_silly_screws = 1;
            i = (winnerCount == PLAYERS_TOTAL) ? (rand16() & 1) : winners[0];
            if (i == 0) {
                m255_players[1].lost = TRUE;
                m255_players[1].cuesEnabled = FALSE;
                func_8001C258_1CE58(m255_players[1].object->model[MDL_ARROW], 4, 4);
                func_8001C258_1CE58(m255_players[1].object->model[MDL_BALLOON_B], 4, 4);
                func_8001C258_1CE58(m255_players[1].object->model[MDL_BALLOON_A], 4, 4);
            } else {
                m255_players[0].lost = TRUE;
                m255_players[0].cuesEnabled = FALSE;
                func_8001C258_1CE58(m255_players[0].object->model[MDL_ARROW], 4, 4);
                func_8001C258_1CE58(m255_players[0].object->model[MDL_BALLOON_B], 4, 4);
                func_8001C258_1CE58(m255_players[0].object->model[MDL_BALLOON_A], 4, 4);
            }
            func_8003F5C0_401C0();
            m255_SetFunc(FGRP_MINIGAME, 1, i, &m255_players[i], m255_ExecMinigameFinish, FALSE, FALSE);
            m255_ResetFunc(FGRP_MINIGAME, ctx);
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void m255_ChooseNutsPositions(void) {
    PlayerWorld* world = m255_minigame->worlds;
    f32 nutBasePosX[][6] = {
        { 4.5f, 6.5f, 2.5f, 4.5f, 2.5f, 5.0f, },
        { 4.5f, 2.5f, 6.5f, 2.5f, 4.5f, 6.5f  }
    };
    s16 rand = rand16() & 1;
    s16 i, j;

    for (i = 0; i < PLAYERS_TOTAL; i++, world++) {
        for (j = 0; j < NUTS_TOTAL; j++) {
            world->nuts[j].startPosX = nutBasePosX[rand][j] * 20.0f * 5.0f;
        }
    }
    m255_players[0].startPosX = m255_players[1].startPosX = m255_minigame->worlds->nuts[0].startPosX;
    m255_minigame->timer = 180.0f * FPS;
}

void m255_SetWall(s16 modelId, s16 worldId) {
    if (m255_minigame->worlds[worldId].wallCount < 4) {
        Hu3DModelPosSet(modelId, 0.0f, 0.0f, 1150.0f - m255_minigame->worlds[worldId].wallCount * 800.0f);
        m255_minigame->worlds[worldId].wallCount++;
    }
}

void m255_SetScrew(s16 modelId, s16 worldId) {
    if (m255_minigame->worlds[worldId].screwCount < SCREWS_TOTAL) {
        Hu3DModelPosSet(modelId, 50.0f, 1800.0f, 0.0f - m255_minigame->worlds[worldId].screwCount * 450.0f);
        m255_minigame->worlds[worldId].screwCount++;
    }
}

static inline void m255_SpinNutModel(HmfModel* model, PlayerData* player) {
    model->rot.x -= player->speed;
    if (model->rot.x > 360.0f) {
        model->rot.x -= 360.0f;
    } else if (model->rot.x < 0.0f) {
        model->rot.x += 360.0f;
    }
    model->pos.x -= player->speed * 0.22222222f;
    if (model->pos.x < 150.0f) {
        model->pos.x = 150.0f;
    } else if (model->pos.x > 700.0f) {
        model->pos.x = 700.0f;
    }
}

void m255_UpdateNutSpinning(FuncContext* ctx) {
    PlayerWorld* world = ctx->data;
    NutData* nut = world->nuts;
    s16 i;

    switch (ctx->state) {
        case 0:
            ctx->work.s16[0] = ctx->param;
            ctx->state = 1;
            break;
        case 1:
            for (i = 0; i < NUTS_TOTAL; i++, nut++) {
                HmfModel* nutModel = &HmfModelData[nut->modelId];
                PlayerData* player = &m255_players[ctx->work.s16[0]];

                if (CenterM[ctx->work.s16[0]].z - 800.0f < nutModel->pos.z) {
                    func_8001C258_1CE58(nut->modelId, 4, 0);
                }
                if (CenterM[ctx->work.s16[0]].z + 900.0f < nutModel->pos.z) {
                    func_8001C258_1CE58(nut->modelId, 4, 4);
                }
                if (player->inputEnabled && player->currNutId == i) {
                    m255_SpinNutModel(nutModel, player);
                    player->object->trans.x = nutModel->pos.x;
                    HmfModelData[player->object->model[1]].pos.x = nutModel->pos.x;
                    HmfModelData[player->object->model[1]].pos.y = player->object->trans.y;
                    if (player->speed != 0.0f) {
                        continue;
                    }
                    if (i == NUTS_TOTAL - 1) {
                        s32 jumpGapX = nutModel->pos.x - GOAL_POS_X;

                        if (ABS(jumpGapX) < JUMP_RANGE_X) {
                            player->inputEnabled = FALSE;
                            player->currNutId++;
                            HuAudFXStop(player->nutSeNo);
                            player->nutSeActive = FALSE;
                            m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 3, -1, player, m255_ExecPlayerJump, FALSE, FALSE);
                        }
                    } else {
                        s32 jumpGapX = nutModel->pos.x - nut[1].startPosX;

                        if (ABS(jumpGapX) < JUMP_RANGE_X) {
                            player->inputEnabled = FALSE;
                            player->currNutId++;
                            HuAudFXStop(player->nutSeNo);
                            player->nutSeActive = FALSE;
                            m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 3, -1, player, m255_ExecPlayerJump, FALSE, FALSE);
                        }
                    }
                }
            }
            break;
    }
}

void m255_UpdatePlayerCue(FuncContext* ctx) {
    PlayerData* player = ctx->data;
    HmfModel* cueModel = NULL;
    PlayerWorld* world = &m255_minigame->worlds[player->object->work[0]];
    f32 cuePosY = 0.0f;
    f32 cuePosZ = 0.0f;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[1] = CUE_ARROW;
            ctx->work.f32[0] = 0.0f;
            ctx->state = 1;
            break;
        case 1:
            if (!player->cuesEnabled) {
                break;
            }
            if (player->inputEnabled) {
                NutData* nut = &world->nuts[player->currNutId];
                f32 currNutPosX;
                f32 nextNutPosX;

                if (player->currNutId < NUTS_TOTAL - 1) {
                    currNutPosX = HmfModelData[nut->modelId].pos.x;
                    nextNutPosX = nut[1].startPosX;
                } else {
                    currNutPosX = HmfModelData[nut->modelId].pos.x;
                    nextNutPosX = GOAL_POS_X;
                }
                func_8001C258_1CE58(player->object->model[MDL_ARROW], 4, 4);
                func_8001C258_1CE58(player->object->model[MDL_BALLOON_B], 4, 4);
                func_8001C258_1CE58(player->object->model[MDL_BALLOON_A], 4, 4);
                if (ABS((s32) (currNutPosX - nextNutPosX)) < JUMP_RANGE_X) {
                    ctx->work.s8[1] = ctx->work.s8[0];
                    ctx->work.s8[0] = CUE_ARROW;
                } else if (currNutPosX - nextNutPosX < 0.0f) {
                    ctx->work.s8[1] = ctx->work.s8[0];
                    ctx->work.s8[0] = CUE_BALLOON_A;
                } else if (currNutPosX - nextNutPosX > 0.0f) {
                    ctx->work.s8[1] = ctx->work.s8[0];
                    ctx->work.s8[0] = CUE_BALLOON_B;
                }
            } else {
                ctx->work.s8[1] = ctx->work.s8[0];
                ctx->work.s8[0] = CUE_ARROW;
            }
            if (ctx->work.s8[0] != ctx->work.s8[1]) {
                ctx->work.f32[0] = 0.0f;
            }
            switch (ctx->work.s8[0]) {
                case CUE_ARROW:
                    player->unk10 = 2;
                    ctx->work.f32[0] += 0.1f;
                    if (ctx->work.f32[0] > 1.0f) {
                        ctx->work.f32[0] = 0.0f;
                    }
                    cuePosY = player->object->trans.y + 100.0f;
                    cuePosZ = player->object->trans.z - 125.0f - HuMathSin(ctx->work.f32[0] * 90.0f) * 20.0f * 5.0f * 0.5f;
                    cueModel = &HmfModelData[player->object->model[MDL_ARROW]];
                    func_8001C258_1CE58(player->object->model[MDL_ARROW], 4, 0);
                    break;
                case CUE_BALLOON_B:
                    player->unk10 = 1;
                    ctx->work.f32[0] += 0.05f;
                    if (ctx->work.f32[0] > 1.0f) {
                        ctx->work.f32[0] = 0.0f;
                    }
                    cuePosY = player->object->trans.y + 300.0f - HuMathSin(ctx->work.f32[0] * 90.0f) * 20.0f * 5.0f * 0.25f;
                    cuePosZ = player->object->trans.z;
                    cueModel = &HmfModelData[player->object->model[MDL_BALLOON_B]];
                    func_8001C258_1CE58(player->object->model[MDL_BALLOON_B], 4, 0);
                    break;
                case CUE_BALLOON_A:
                    player->unk10 = 0;
                    ctx->work.f32[0] += 0.05f;
                    if (ctx->work.f32[0] > 1.0f) {
                        ctx->work.f32[0] = 0.0f;
                    }
                    cuePosY = player->object->trans.y + 300.0f - HuMathSin(ctx->work.f32[0] * 90.0f) * 20.0f * 5.0f * 0.25f;
                    cuePosZ = player->object->trans.z;
                    cueModel = &HmfModelData[player->object->model[MDL_BALLOON_A]];
                    func_8001C258_1CE58(player->object->model[MDL_BALLOON_A], 4, 0);
                    break;
            }
            cueModel->pos.x = player->object->trans.x;
            cueModel->pos.y = cuePosY;
            cueModel->pos.z = cuePosZ;
            cueModel->rot.y = 90.0f;
            break;
    }
}

void m255_ExecPlayerWins(FuncContext* ctx) {
    PlayerData* player = ctx->data;

    if (GMesStatGet() == GMES_STAT_NONE) {
        D_8010BE4C_2B56FC_silly_screws = 1;
    }
    if (D_8010BE4C_2B56FC_silly_screws != 0) {
        s16 temp_15;

        switch (ctx->state) {
            case 0:
                ctx->state = 1;
                break;
            case 1:
                temp_15 = 15;
                if (ctx->work.s16[0]++ == temp_15) {
                    s16 chr = GwPlayer[m255_playerId[player->object->work[0]]].chr;
                    s32 temp_a2 = D_8010BE2C_2B56DC_silly_screws[GwPlayer[m255_playerId[player->object->work[0]]].chr];

                    func_80017790_18390(player->object->model[0], 2, chr, temp_a2);
                    player->state = PLAYER_STATE_WON;
                    HuAudSeqPlay(0x67);
                    GMesCreate(GMES_MES_MG_WINNER, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                    GwPlayer[m255_playerId[player->object->work[0]]].bonusCoin += 10;
                    D_8010BE20_2B56D0_silly_screws = 0;
                }
                break;
        }
    }
}

void m255_UpdatePlayerSpeed(FuncContext* ctx) {
    PlayerData* player = ctx->data;
    f32 newSpeed;
    s16 absSpeed;
    s16 pitch;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 0;
            ctx->work.s8[1] = 0;
            ctx->work.s8[2] = 0;
            ctx->work.s16[3] = 999;
            ctx->state = 1;
            break;
        case 1:
            if (!player->inputEnabled) {
                break;
            }
            if (player->lost) {
                player->state = PLAYER_STATE_ON_PLATFORM;
                m255_ResetFunc(FGRP_PLAYER_1 + player->object->work[0], ctx);
                break;
            }
            if (player->state != PLAYER_STATE_ROTATE) {
                player->state = PLAYER_STATE_ON_PLATFORM;
            }
            if (D_800CDA7C_CE67C[player->padId] & B_BUTTON) {
                if (ctx->work.s8[0] == 0 && player->state != PLAYER_STATE_ROTATE) {
                    player->inputIdleTimer = 0;
                    if (player->direction == PLAYER_DIR_RIGHT) {
                        player->work.f32[0] = 180.0f;
                        player->work.f32[1] = 0.0f;
                        m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 5, -1, player, m255_LerpPlayerRotation, FALSE, TRUE);
                    }
                    player->state = PLAYER_STATE_TRANSITION;
                    player->direction = PLAYER_DIR_LEFT;
                    ctx->work.s8[0] = 1;
                    if (player->speed + 1.0f > 15.0f) {
                        newSpeed = 15.0f;
                    } else {
                        newSpeed = player->speed + 1.0f;
                    }
                    player->speed = newSpeed;
                    if (!player->nutSeActive) {
                        player->nutSeNo = func_8004AC5C_4B85C(0x4B3, m255_playerId[player->object->work[0]]);
                        player->nutSeActive = TRUE;
                    }
                    if (ABS(player->speed) < 5.0f) {
                        pitch = -50;
                    } else if (ABS(player->speed) < 10.0f) {
                        pitch = 0;
                    } else {
                        pitch = 50;
                    }
                    HuAudFXPitchSet(player->nutSeNo, pitch);
                    absSpeed = ABS(player->speed);
                    func_8004AAD0_4B6D0(player->nutSeNo, 100 + (s32) ((absSpeed / 15.0f) * 27.0f));
                }
            } else if (D_800CDA7C_CE67C[player->padId] & A_BUTTON) {
                if (ctx->work.s8[1] == 0 && player->state != PLAYER_STATE_ROTATE) {
                    player->inputIdleTimer = 0;
                    if (player->direction == PLAYER_DIR_LEFT) {
                        player->work.f32[0] = 0.0f;
                        player->work.f32[1] = 180.0f;
                        m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 5, -1, player, m255_LerpPlayerRotation, FALSE, TRUE);
                    }
                    player->state = PLAYER_STATE_TRANSITION;
                    player->direction = PLAYER_DIR_RIGHT;
                    ctx->work.s8[1] = 1;
                    if (player->speed - 1.0f < -15.0f) {
                        newSpeed = -15.0f;
                    } else {
                        newSpeed = player->speed - 1.0f;
                    }
                    player->speed = newSpeed;
                    if (!player->nutSeActive) {
                        player->nutSeNo = func_8004AC5C_4B85C(0x4B3, m255_playerId[player->object->work[0]]);
                        player->nutSeActive = TRUE;
                    }
                    if (ABS(player->speed) < 5.0f) {
                        pitch = -50;
                    } else if (ABS(player->speed) < 10.0f) {
                        pitch = 0;
                    } else {
                        pitch = 50;
                    }
                    HuAudFXPitchSet(player->nutSeNo, pitch);
                    absSpeed = ABS(player->speed);
                    func_8004AAD0_4B6D0(player->nutSeNo, 100 + (s32) ((absSpeed / 15.0f) * 27.0f));
                }
            }
            if (!(D_800CDA7C_CE67C[player->padId] & B_BUTTON)) {
                ctx->work.s8[0] = 0;
            }
            if (!(D_800CDA7C_CE67C[player->padId] & A_BUTTON)) {
                ctx->work.s8[1] = 0;
            }
            break;
    }
}

void m255_UpdatePlayerAnimation(FuncContext* ctx) {
    PlayerData* player = ctx->data;

    switch (ctx->state) {
        case 0:
            player->state = PLAYER_STATE_ON_PLATFORM;
            player->inputIdleTimer = 0;
            ctx->state = 1;
            ctx->work.s8[0] = 0;
            ctx->work.s8[1] = 0;
            break;
        case 1:
            switch (player->state) {
                case PLAYER_STATE_ON_PLATFORM:
                    ctx->work.s8[0] = 0;
                    if (player->speed == 0.0f) {
                        if (!player->lost) {
                            func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_IDLE);
                        } else {
                            func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_LOST);
                        }
                        if (player->nutSeActive) {
                            HuAudFXStop(player->nutSeNo);
                            player->nutSeActive = FALSE;
                        }
                    } else if (player->speed > 0.0f) {
                        player->inputIdleTimer++;
                        if (player->inputIdleTimer >= 6) {
                            player->speed -= 0.5f;
                        }
                        func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_RUN);
                        if (HmfModelData[player->object->model[0]].unk40 == 0.0f) {
                            CharFXPlay(0x28, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                        }
                    } else {
                        player->inputIdleTimer++;
                        if (player->inputIdleTimer >= 6) {
                            player->speed += 0.5f;
                        }
                        func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_RUN);
                        if (HmfModelData[player->object->model[0]].unk40 == 0.0f) {
                            CharFXPlay(0x28, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                        }
                    }
                    break;
                case PLAYER_STATE_WAIT_CAM:
                    func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_IDLE);
                    break;
                case PLAYER_STATE_1:
                    if (HmfModelData[player->object->model[0]].unk40 == 0.0f) {
                        CharFXPlay(0x1F, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                    }
                    func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_WALK);
                    break;
                case PLAYER_STATE_FINISHED:
                    if (HmfModelData[player->object->model[0]].unk40 == 0.0f) {
                        CharFXPlay(0x28, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                    }
                    func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_WALK);
                    break;
                case PLAYER_STATE_JUMP:
                    func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_JUMP);
                    if (ctx->work.s8[0] == 0) {
                        ctx->work.s8[0] = 1;
                        CharFXPlay(0x3A, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                    }
                    break;
                case PLAYER_STATE_WON:
                    if (D_8010BE4E_2B56FE_silly_screws == 0) {
                        func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_WON);
                        func_80045F1C_46B1C(D_800A178C[GwPlayer[m255_playerId[player->object->work[0]]].chr][0] | 0x2F, -1, m255_playerId[player->object->work[0]]);
                        D_8010BE4E_2B56FE_silly_screws = 1;
                    }
                    break;
                default:
                    if (HmfModelData[player->object->model[0]].unk40 == 0.0f) {
                        CharFXPlay(0x28, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                    }
                    func_800E5690_B8210_minigame(player->object, PLAYER_ANIM_RUN);
                    break;
            }
            break;
    }
}

void m255_LerpPlayerRotation(FuncContext* ctx) {
    PlayerData* player = ctx->data;

    switch (ctx->state) {
        case 0:
            ctx->work.s8[0] = 0;
            player->state = PLAYER_STATE_ROTATE;
            ctx->state = 1;
            break;
        case 1:
            if (m255_CalcLerp(&player->object->rot.y, (u8*) &ctx->work.s8[0], player->work.f32[0], player->work.f32[1], 5.0f)) {
                m255_ResetFunc(FGRP_PLAYER_1 + player->object->work[0], ctx);
                player->state = PLAYER_STATE_ON_PLATFORM;
            }
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void m255_ExecPlayerJump(FuncContext* ctx) {
    PlayerData* player = ctx->data;
    Work* ctxWork = &ctx->work;
    f32 accelY;
    f32 scale;

    switch (ctx->state) {
        case 0:
            if (player->direction != PLAYER_DIR_RIGHT) {
                player->work.f32[0] = 0.0f;
                player->work.f32[1] = 180.0f;
                m255_SetFunc(FGRP_PLAYER_1 + player->object->work[0], 5, -1, player, m255_LerpPlayerRotation, FALSE, TRUE);
                player->direction = PLAYER_DIR_RIGHT;
            }
            ctxWork->s8[0] = 0;
            ctxWork->s8[1] = 0;
            ctxWork->s8[2] = 0;
            ctxWork->f32[0] = player->object->trans.z;
            ctx->state = 1;
            break;
        case 1:
            if (player->state == PLAYER_STATE_ROTATE) {
                break;
            }
            switch (ctxWork->s8[1]) {
                case 0:
                    player->state = PLAYER_STATE_TRANSITION; // moving forward before jumping
                    if (m255_CalcLerp(&player->object->trans.z, (u8*) &ctxWork->s8[0], ctxWork->f32[0], ctxWork->f32[0] - 80.0f, 10.0f)) {
                        ctxWork->s8[1] = 1;
                        ctxWork->f32[0] = player->object->trans.z;
                        if (player->currNutId < NUTS_TOTAL) {
                            ctxWork->f32[1] = 2000.0f;
                            ctxWork->f32[2] = 0.0f - player->currNutId * 450.0f;
                            ctxWork->f32[3] = 28.0f;
                            player->accelY = -1.22f;
                        } else {
                            if (player->work.s8[0] == 0) {
                                ctxWork->f32[1] = 1900.0f;
                                ctxWork->f32[2] = -2650.0f;
                                ctxWork->f32[3] = 25.0f;
                                player->accelY = -1.0f;
                                player->work.s8[0] = 1;
                                player->cuesEnabled = FALSE;
                                func_8001C258_1CE58(player->object->model[MDL_ARROW], 4, 4);
                                func_8001C258_1CE58(player->object->model[MDL_BALLOON_B], 4, 4);
                                func_8001C258_1CE58(player->object->model[MDL_BALLOON_A], 4, 4);
                            } else {
                                ctxWork->f32[1] = 1800.0f;
                                ctxWork->f32[2] = -3300.0f;
                                ctxWork->f32[3] = 45.0f;
                                player->accelY = -1.0f;
                                player->work.s8[0] = 2;
                                player->cuesEnabled = FALSE;
                                func_8001C258_1CE58(player->object->model[MDL_ARROW], 4, 4);
                            }
                        }
                    }
                    Hu3DModelPosSet(player->object->model[1], player->object->trans.x, player->object->trans.y, player->object->trans.z);
                    break;
                case 1:
                    player->state = PLAYER_STATE_JUMP;
                    accelY = player->accelY;
                    if (accelY > 1.7f) {
                        accelY = 1.7f;
                    }
                    player->object->trans.y += accelY * accelY * (accelY >= 0.0f ? -35.0f : 35.0f);
                    player->accelY += 0.11f;
                    if (player->object->trans.y < ctxWork->f32[1]) {
                        if (ctxWork->s8[2] == 0) {
                            ctxWork->s8[2] = 1;
                            CharFXPlay(0x31, GwPlayer[m255_playerId[player->object->work[0]]].chr);
                        }
                        if (player->work.s8[0] == 1) {
                            player->object->trans.y = ctxWork->f32[1];
                            player->finished = TRUE;
                        } else {
                            player->object->trans.y = ctxWork->f32[1];
                        }
                        player->state = PLAYER_STATE_TRANSITION;
                    }
                    scale = 1.0f - (player->object->trans.y - ctxWork->f32[1]) * 0.01f;
                    if (scale < 0.0f) {
                        scale = 0.0f;
                    }
                    if (scale > 1.0f) {
                        scale = 1.0f;
                    }
                    Hu3DModelScaleSet(player->object->model[1], scale, 1.0f, scale);
                    Hu3DModelPosSet(player->object->model[1], player->object->trans.x, ctxWork->f32[1] + 1.0f, player->object->trans.z);
                    if (m255_CalcLerp(&player->object->trans.z, (u8*) &ctxWork->s8[0], ctxWork->f32[0], ctxWork->f32[2], ctxWork->f32[3])) {
                        m255_ResetFunc(FGRP_PLAYER_1 + player->object->work[0], ctx);
                        Hu3DModelScaleSet(player->object->model[1], 1.0f, 1.0f, 1.0f);
                        if (player->lost) {
                            player->state = PLAYER_STATE_ON_PLATFORM;
                        } else if (player->currNutId < NUTS_TOTAL) {
                            player->inputEnabled = TRUE;
                            player->state = PLAYER_STATE_ON_PLATFORM;
                        } else {
                            player->state = PLAYER_STATE_FINISHED;
                            m255_SetFunc(FGRP_CAMERA, 0, 0, player, m255_CenterCameraOnWinner, FALSE, FALSE);
                        }
                    }
                    break;
            }
            break;
    }
}

void m255_UpdateComInput(FuncContext* ctx) {
    PlayerData* player = ctx->data;
    u8 unused_stack[0x18];

    switch (ctx->state) {
        case 0:
            switch (GwPlayer[m255_playerId[player->object->work[0]]].cpu_difficulty) {
                case 0:
                    ctx->work.s8[2] = 9; // controls the delay between button presses
                    ctx->work.s8[3] = 12; // controls precision when deciding when to stop running
                    break;
                case 1:
                    ctx->work.s8[2] = 7;
                    ctx->work.s8[3] = 10;
                    break;
                case 2:
                    ctx->work.s8[2] = 6;
                    ctx->work.s8[3] = 8;
                    break;
                case 3:
                    ctx->work.s8[2] = 4;
                    ctx->work.s8[3] = 6;
                    break;
            }
            ctx->work.f32[0] = (rand16() % (ctx->work.s8[3] + 1)) * 0.1f * 20.0f * 5.0f;
            ctx->work.f32[0] = (rand16() & 1) ? -ctx->work.f32[0] : ctx->work.f32[0];
            ctx->state = 1;
            break;
        case 1:
            if (player->finished) {
                break;
            }
            if (player->lost) {
                break;
            }
            if (player->currNutId != NUTS_TOTAL) {
                f32 temp_f6 = func_8010B18C_2B4A3C_silly_screws(player);
                NutData* nut = &m255_minigame->worlds[player->object->work[0]].nuts[player->currNutId];
                HmfModel* nutModel = &HmfModelData[nut->modelId];
                f32 nextNutPosX;
                s8 temp_v1_3;

                if (player->currNutId == NUTS_TOTAL - 1) {
                    nextNutPosX = GOAL_POS_X;
                } else {
                    nextNutPosX = nut[1].startPosX;
                }
                if (player->state == PLAYER_STATE_JUMP) {
                    ctx->work.s8[4] = 0;
                }
                if (ABS((s32) (nutModel->pos.x + temp_f6 - (nextNutPosX + ctx->work.f32[0]))) < JUMP_RANGE_X) {
                    ctx->work.s8[4] = ctx->work.s8[4] - 1 - (rand16() & 1);
                    temp_v1_3 = rand16() % (ctx->work.s8[3] + 1) + ctx->work.s8[4];
                    ctx->work.f32[0] = (temp_v1_3 >= 0 ? temp_v1_3 : 0) * 0.1f * 20.0f * 5.0f;
                    ctx->work.f32[0] = (rand16() & 1) ? -ctx->work.f32[0] : ctx->work.f32[0];
                    D_800CDA7C_CE67C[player->padId] = 0;
                } else if (nutModel->pos.x + temp_f6 - (nextNutPosX + ctx->work.f32[0]) < 0.0f) {
                    ctx->work.s8[0]--;
                    if (ctx->work.s8[0] < 0) {
                        ctx->work.s8[0] = rand16() % ctx->work.s8[2] + 1;
                        D_800CDA7C_CE67C[player->padId] = A_BUTTON;
                    } else {
                        D_800CDA7C_CE67C[player->padId] = 0;
                    }
                } else if (nutModel->pos.x + temp_f6 - (nextNutPosX + ctx->work.f32[0]) > 0.0f) {
                    ctx->work.s8[1]--;
                    if (ctx->work.s8[1] < 0) {
                        ctx->work.s8[1] = rand16() % ctx->work.s8[2] + 1;
                        D_800CDA7C_CE67C[player->padId] = B_BUTTON;
                    } else {
                        D_800CDA7C_CE67C[player->padId] = 0;
                    }
                }
            }
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
f32 func_8010B18C_2B4A3C_silly_screws(PlayerData* player) {
    f32 var_f4 = 0.0f;
    f32 absSpeed;
    f32 var_f2;

    absSpeed = ABS((s32) player->speed);
    for (var_f2 = 0.0f; var_f2 <= absSpeed; var_f2 += 0.5f) {
        var_f4 += var_f2 * 0.22222222f;
    }
    for (var_f2 = 0.0f; var_f2 < 6.0f; var_f2 += 1.0f) {
        var_f4 += absSpeed * 0.22222222f;
    }
    return (player->speed < 0.0f) ? var_f4 : -var_f4;
}
