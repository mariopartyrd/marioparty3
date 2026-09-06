#include "WaluigisIsland.h"
#include "gcc/memory.h"
#include "mallocblock.h"
#include "../ovl_80_shared_board/1006F0.h"
#include "../ovl_80_shared_board/101840.h"
#include "../ovl_80_shared_board/105D50.h"
#include "../ovl_80_shared_board/106A50.h"
#include "../ovl_80_shared_board/106A50.h"
#include "../ovl_80_shared_board/10C230.h"
#include "../ovl_80_shared_board/113520.h"
#include "../ovl_80_shared_board/113750.h"
#include "../ovl_80_shared_board/EA790.h"
#include "../ovl_80_shared_board/EAB00.h"
#include "../ovl_80_shared_board/EB2F0.h"
#include "../ovl_80_shared_board/EC3B0.h"
#include "../ovl_80_shared_board/ECA50.h"
#include "../ovl_80_shared_board/EDDB0.h"
#include "../ovl_80_shared_board/EE660.h"
#include "../ovl_80_shared_board/F5070.h"
#include "../ovl_80_shared_board/F5B90.h"
#include "../ovl_80_shared_board/F5E80.h"
#include "../ovl_80_shared_board/F9DE0.h"
#include "../ovl_80_shared_board/F9DE0.h"
#include "../ovl_80_shared_board/FA250.h"
#include "../ovl_80_shared_board/FFB10.h"

void func_8001ED54_1F954(s16 arg0);
void func_800D9F5C_C1D2C_name_81(Object *arg0, Vec *arg1, s32 arg2);
void func_8011A2A0_3AF620_w06(void);
void func_80108A10_39DD90_w06(void);

#define GW_SYSTEM_FROM_CURRENT_PLAYER(ptr) \
    ((GW_SYSTEM *)((u8 *)(ptr) - (u32) & ((GW_SYSTEM *)0)->current_player_index))

typedef struct {
    /* 0x00 */ Object *obj1;
    /* 0x04 */ Object *obj2;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 motion;
    /* 0x0C */ s32 flag;
} ModelAnimWork;

typedef struct {
    /* 0x00 */ Vec unk00;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ Object *model;
    /* 0x1C */ u16 unk1C;
} ModelFadeWork;

typedef struct {
    u8 unk[4];
} Unk4Bytes;

typedef struct StarChaseWork {
    /* 0x00 */ Vec dir;
    /* 0x0C */ char pad0C[4];
    /* 0x10 */ Vec pos;
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ ChanceTable chaseChanceA;
    /* 0x30 */ ChanceTable chaseChanceB;
    /* 0x40 */ ChanceTable eventTableA;
    /* 0x50 */ ChanceTable eventTableB;
} StarChaseWork; // size 0x60

typedef struct WarpBlockSwapWork {
    /* 0x00 */ s16 startX;
    /* 0x02 */ s16 startY;
    /* 0x04 */ s16 endX;
    /* 0x06 */ s16 endY;
    /* 0x08 */ s16 duration;
    /* 0x0A */ s16 spriteGroup;
} WarpBlockSwapWork;

// Keep these field reads independent of the cached system pointer in board events.
static inline s8 W06CurrentPlayerIndexGet(void) {
    return GwSystem.current_player_index;
}

static inline s8 W06CurrentTurnGet(void) {
    return GwSystem.current_turn;
}

static inline s8 W06TotalTurnsGet(void) {
    return GwSystem.total_turns;
}

s16 func_801059D0_39AD50_w06(void) {
    return D_8011B5C0_3B0940_w06[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]];
}

void func_801059F8_39AD78_w06(void) {
    s32 i;
    s32 idx1;
    s32 idx2;
    GW_SYSTEM *loc = &GwSystem;

    for (i = 0; i < 0x3C; i++) {
        idx1 = rand8() & 7;
        idx2 = rand8() & 7;

        if (idx1 != idx2) {
            if (idx1 < D_8011B590_3B0910_w06[idx2]) {
                continue;
            }
            if (idx2 < D_8011B590_3B0910_w06[idx1]) {
                continue;
            }
            {
                s32 temp = D_8011B580_3B0900_w06[idx1];
                D_8011B580_3B0900_w06[idx1] = D_8011B580_3B0900_w06[idx2];
                D_8011B580_3B0900_w06[idx2] = temp;
                temp = D_8011B590_3B0910_w06[idx1];
                D_8011B590_3B0910_w06[idx1] = D_8011B590_3B0910_w06[idx2];
                D_8011B590_3B0910_w06[idx2] = temp;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        loc->star_spawn_indices[i] = D_8011B580_3B0900_w06[i];
    }
}

void func_80105B00_39AE80_w06(void) {
    GW_SYSTEM *loc;
    s32 sp7;
    s32 sp0;

    loc = &GwSystem;
    loc->current_star_spawn++;
    if (loc->current_star_spawn >= 8) {
        sp7 = loc->star_spawn_indices[7];
        loc->current_star_spawn = 0;
        GWBoardFlagSet(4);
        func_801059F8_39AD78_w06();
        sp0 = loc->star_spawn_indices[0];
        if ((sp7 ^ sp0) == 0) {
            loc->star_spawn_indices[0] = loc->star_spawn_indices[7];
            loc->star_spawn_indices[7] = sp0;
        }
    }
}

void func_80105B8C_39AF0C_w06(void) {
    s32 i;
    GW_SYSTEM *loc = &GwSystem;

    for (i = 0; i < 8; i++) {
        GWBoardFlagSet(D_8011B5A0_3B0920_w06[i]);
    }
    MBMasuTypeSet(D_8011B5B0_3B0930_w06[loc->star_spawn_indices[loc->current_star_spawn]], 0xE);
    GWBoardFlagClear(D_8011B5A0_3B0920_w06[loc->star_spawn_indices[loc->current_star_spawn]]);
}

s32 func_80105C30_39AFB0_w06(s16 arg0) {
    s32 i;
    GW_SYSTEM *loc = &GwSystem;

    for (i = 0; i < 8; i++) {
        if (arg0 == D_8011B5B0_3B0930_w06[i]) {
            if (i == loc->star_spawn_indices[loc->current_star_spawn]) {
                loc->unk_0E = D_8011B5A0_3B0920_w06[i];
                return 1;
            }
            break;
        }
    }
    return 0;
}

void func_80105CA4_39B024_w06(void) {
    SpaceData *space = HuPrcCurrentGet()->user_data;
    Object *model;
    s32 obj;
    f32 scale;
    f32 angle;
    s32 i;

    HuAudFXPlay(0x11B);
    D_8011E2BC_3B363C_w06 = MBModelCreate(0x3A, NULL);
    model = D_8011E2BC_3B363C_w06;
    func_800461B4_46DB4(model->omObj1->model[0]);
    model->flags |= 4;
    func_800ECC54_100874_shared_board(model);
    HuVecCopy3F(&model->coords, &space->coords);
    model->velocity.x = 50.0f;
    obj = func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(obj, 2.0f, 20.0f, 1.0f);
    func_8000D018_DC18(obj, 30.0f);
    func_8000CFA4_DBA4(obj, model->coords.x, model->coords.y + model->velocity.x, model->coords.z);
    func_8001C8A8_1D4A8(obj, 1);

    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        scale += 0.5f;
        func_8000D018_DC18(obj, scale * 30.0f);
        HuPrcVSleep();
    }

    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        scale -= 0.4f;
        func_8000D018_DC18(obj, scale * 30.0f);
        HuPrcVSleep();
    }

    func_8000D018_DC18(obj, scale * 30.0f);
    HuPrcSleep(30);
    HuAudFXPlay(0x132);

    angle = 0.0f;
    while (1) {
        func_8008A2A0_8AEA0(HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        if (scale > 0.6f) {
            scale -= 0.04f;
        }
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        if (model->velocity.x > 10.0f) {
            model->velocity.x -= 1.2f;
        }
        func_8000D018_DC18(obj, scale * 30.0f);
        func_8000CFA4_DBA4(obj, model->coords.x, model->coords.y + model->velocity.x, model->coords.z);
        if ((model->velocity.x <= 10.0f) & (scale <= 0.6f)) {
            if (angle == 0.0f) {
                break;
            }
        }
        HuPrcVSleep();
    }

    func_8008A2A0_8AEA0(HmfModelData[model->omObj1->model[0]].mtx, 0.0f);
    func_8000D044_DC44(obj);
    D_8011E2B8_3B3638_w06 = 0;
    omDelPrcObj(NULL);
}

void func_80106094_39B414_w06(omObjData **arg) {
    omObjData *s0 = *arg;

    s0->scale.y = 4.0f;
    s0->scale.z = -0.6f;
    HuPrcSleep(3);
    while (s0->scale.z != 0.0f) {
        HuPrcVSleep();
    }
}

void func_80106120_39B4A0_w06(void) {
    struct UnkMBGuideData *data;
    GW_SYSTEM *loc = &GwSystem;
    SpaceData *space;
    s32 idx;

    D_800A12D4_A1ED4 = 0;
    data = MBGuideCreate(0, 0);
    HuAudSeqPlay(0x12);
    MBGuideFaceCreate(data->obj, 2, 0xF, D_8011B5D0_3B0950_w06[0]);
    func_800FFF44_113B64_shared_board();
    MBModelDispOff(D_8011E278_3B35F8_w06[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]);
    WipeCreateIn(2, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    func_800E6FCC_FABEC_shared_board();
    func_800E9730_FD350_shared_board(3.0f);
    func_80106094_39B414_w06((omObjData **)data);
    func_8005B43C_5C03C(
        data->amount,
        (loc->current_star_spawn == 0 && GWBoardFlagCheck(4) == 0)
            ? (((loc->current_board_index == 2) ? 0x5E09 : 0) | 0x5E00)
            : (((loc->current_board_index == 2) ? 0x5E09 : 0) | 0x5E01),
        -1, -1);
    func_80060C14_61814(data->amount, 1);
    HuAudFXPlay(0x2A7);
    func_800EE2C0_101EE0_shared_board(data->amount);
    MBMotionShiftSet(data->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(data->amount, 1);
    func_8001FDE8_209E8(data->obj->omObj1->model[0]);
    if (loc->current_board_index != 2 || (rand8() & 1)) {
        space = MBMasuGet(D_8011B5C0_3B0940_w06[loc->star_spawn_indices[loc->current_star_spawn]]);
    }
    MBCameraPos3DSet(&space->coords);
    MBCameraSpeedSet(5.0f);
    HuPrcSleep(5);
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    idx = MBRand(7.0f);
    MBGuideFaceSet(data->obj, D_8011B5D0_3B0950_w06[idx]);
    MBMotionSet(data->obj, -1, 2);
    if (loc->current_board_index != 2) {
        Process *prc = omAddPrcObj(func_80105CA4_39B024_w06, 0x4800, 0, 0);
        D_8011E2B8_3B3638_w06 = (s32)prc;
        prc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_8011E2B8_3B3638_w06 = 0;
    }
    func_8005B43C_5C03C(data->amount, D_8011B5EC_3B096C_w06[idx], -1, -1);
    func_80060C14_61814(data->amount, 1);
    func_800EE2C0_101EE0_shared_board(data->amount);
    MBMotionShiftSet(data->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(data->amount, 1);
    HuAudSeqFadeOut(0x5A);
    HuPrcSleep(30);
    WipeCreateOut(2, 0x10);
    HuPrcSleep(0x11);
    D_800A12D4_A1ED4 = 1;
    func_80100130_113D50_shared_board();
    func_80046558_47158(D_8011E2BC_3B363C_w06->omObj1->model[0]);
    MBModelKill(D_8011E2BC_3B363C_w06);
    MBModelDispOn(D_8011E278_3B35F8_w06[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]);
    MBGuideKill(data);
    MBExit();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_801064DC_39B85C_w06(void) {
    Object *playerModel = HuPrcCurrentGet()->user_data;
    GW_PLAYER *player = MBPlayerGet(-1);
    Object *model;
    Vec camPos;
    f32 scale;
    f32 angle;
    s32 obj;
    s32 i;

    HuAudFXPlay(0x11B);
    model = MBModelCreate(0x1A, NULL);
    model->flags |= 4;
    func_800ECC54_100874_shared_board(model);
    if (MBMasuLinkMasuIdGet(MBPlayerGet(-1)->clink, MBPlayerGet(-1)->cidx) == 0x7F) {
        HuVecCopyXYZ(&model->coords, playerModel->coords.x, playerModel->coords.y + 10.0f, playerModel->coords.z);
        HuVecCopyXYZ(&camPos, gCameraList->pos.x, gCameraList->pos.y, gCameraList->pos.z);
        model->velocity.x = 15.0f;
    } else {
        HuVecCopyXYZ(&model->coords, playerModel->coords.x, playerModel->coords.y + 10.0f, playerModel->coords.z + 30.0f);
        HuVecCopyXYZ(&camPos, gCameraList->pos.x, gCameraList->pos.y, gCameraList->pos.z);
        model->velocity.x = 35.0f;
    }

    obj = func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(obj, 1.0f, 20.0f, 1.0f);
    func_8000D018_DC18(obj, 15.0f);
    func_8001C8A8_1D4A8(obj, 1);
    func_8000CFA4_DBA4(obj, model->coords.x, model->coords.y + model->velocity.x, model->coords.z);

    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        scale += 0.5f;
        func_8000D018_DC18(obj, scale * 15.0f);
        HuPrcVSleep();
    }

    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        scale -= 0.4f;
        func_8000D018_DC18(obj, scale * 15.0f);
        HuPrcVSleep();
    }

    func_8000D018_DC18(obj, scale * 15.0f);
    HuPrcSleep(20);
    HuAudFXPlay(0x132);

    angle = 0.0f;
    HuVecCopyXYZ(&camPos, player->player_obj->coords.x, player->player_obj->coords.y - 10.0f, player->player_obj->coords.z);
    MBPlayerPosMoveCreate(&model->coords, &camPos, &model->coords, 40);

    for (i = 0; i < 40; i++) {
        func_8008A2A0_8AEA0(HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8000D018_DC18(obj, scale * 15.0f);
        func_8000CFA4_DBA4(obj, model->coords.x, model->coords.y + model->velocity.x, model->coords.z);
        HuPrcVSleep();
    }

    MBModelKill(model);
    func_8000D044_DC44(obj);
    MBVecForwardSet(&player->player_obj->rot);
    MBPlayerVibrate(-1, 5);
    if (D_8011B608_3B0988_w06 != 0) {
        func_8004A670_4B270(0xE);
    } else {
        HuAudSeqPlay(0x6F);
    }

    GwPlayer[GwSystem.current_player_index].star += 1;
    if (GwPlayer[GwSystem.current_player_index].star >= 100) {
        GwPlayer[GwSystem.current_player_index].star = 99;
    }

    MBPlayerMotionSet(-1, 6, 0);
    func_8004ACE0_4B8E0(0x262, GwSystem.current_player_index);
    if (D_8011B608_3B0988_w06 != 0) {
        HuPrcSleep(16);
        func_80003A70_4670(D_800CDBC8_CE7C8);
        func_8004A918_4B518(0x6F);
        func_8004A880_4B480(0);
        HuPrcSleep(110);
        func_80003B70_4770(D_800CDBC8_CE7C8, 0);
        func_8004A72C_4B32C(0xF);
    } else {
        HuPrcSleep(60);
    }
    omDelPrcObj(NULL);
}

void func_80106A3C_39BDBC_w06(Object *arg) {
    Process *prc;

    mbItemBtnF = 0;
    prc = omAddPrcObj(func_801064DC_39B85C_w06, 0x4800, 0, 0);
    prc->user_data = arg;
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWait();
    mbItemBtnF = 1;
}

void func_80106AB0_39BE30_w06(void) {
    mbCameraBtnF = 1;
    mbItemBtnF = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    MBMapScrollExec(GwPlayer[GwSystem.current_player_index].pad);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    mbCameraBtnF = 0;
    mbItemBtnF = 1;
}

void func_80106B38_39BEB8_w06(void) {
    mbItemBtnF = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    MBMapScrollExec(GwPlayer[GwSystem.current_player_index].pad);
    mbItemBtnF = 1;
}

void func_80106B94_39BF14_w06(void) {
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_8011E2C0_3B3640_w06 = func_800E210C_F5D2C_shared_board(0, 0x92, 1);
    D_8011E2C4_3B3644_w06 = func_800E210C_F5D2C_shared_board(1, 0xA0, 1);
    D_8011E2D0_3B3650_w06 = func_800E210C_F5D2C_shared_board(0xD, 0xAE, 1);
    D_8011E2C8_3B3648_w06 = func_800E210C_F5D2C_shared_board(3, 0xBC, 1);
    D_8011E2CC_3B364C_w06 = func_800E210C_F5D2C_shared_board(0xB, 0xCA, 1);
    HuPrcSleep(3);
    mbCameraBtnF = 1;
    D_800D51F8_D5DF8 = 1;
}

void func_80106C64_39BFE4_w06(void) {
    mbCameraBtnF = 0;
    D_800D51F8_D5DF8 = 0;
    MBHelpWinKill(D_8011E2C0_3B3640_w06);
    MBHelpWinKill(D_8011E2C4_3B3644_w06);
    MBHelpWinKill(D_8011E2D0_3B3650_w06);
    MBHelpWinKill(D_8011E2C8_3B3648_w06);
    MBHelpWinKill(D_8011E2CC_3B364C_w06);
}

s32 func_80106CC4_39C044_w06(u8 *arg0) {
    s32 var_s2 = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS];
    s32 i;
    s32 j;

    *(Unk4Bytes *)sp20 = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                var_s2 = func_8011B188_3B0508_w06();
                sp18[GwPlayer[GwSystem.current_player_index].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            if (--var_s2 == 0) {
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

    i = 0;
    do {
        i = func_8005E1D8_5EDD8(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
    } while (arg0[i] == 0);
    return i;
}

s32 func_80106F58_39C2D8_w06(void) {
    s32 var_s2 = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS];
    s32 i;
    s32 j;

    *(Unk4Bytes *)sp20 = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                var_s2 = 1; // dead store; matches func_800FA104_10DD24_shared_board
                var_s2 = func_8011B4EC_3B086C_w06();
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            if (--var_s2 == 0) {
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

void func_80107170_39C4F0_w06(void) {
    s32 i;
    s32 cur = GwSystem.current_player_index;

    for (i = 0; i < 4; i++) {
        if (i != cur && GwPlayer[i].star != 0) {
            break;
        }
    }
    if (i != 4) {
        if (GwPlayer[cur].coin >= 50) {
            if (MBRand(100.0f) < GwPlayer[cur].coin + 10) {
                D_8011E2D4_3B3654_w06 = 1;
                if (GwPlayer[cur].star < 99) {
                    return;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (i != cur && GwPlayer[i].coin >= 5) {
            break;
        }
    }
    if (i != 4) {
        D_8011E2D4_3B3654_w06 = 0;
    } else {
        D_8011E2D4_3B3654_w06 = 2;
    }
}

void func_801072A0_39C620_w06(void) {
    s32 order[4];
    s32 i;
    s32 j;
    s32 cur = GwSystem.current_player_index;

    for (i = 0; i < 4; i++) {
        order[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        j = MBPlayerStealRankGet(i);
        while (1) {
            if (order[j] == -1) {
                break;
            }
            j++;
        }
        order[j] = i;
    }
    func_80107170_39C4F0_w06();
    if (D_8011E2D4_3B3654_w06 == 1) {
        for (i = 0; i < 4; i++) {
            if (order[i] != cur && GwPlayer[order[i]].star != 0) {
                D_8011E2D8_3B3658_w06 = order[i];
                break;
            }
        }
    } else if (D_8011E2D4_3B3654_w06 == 0) {
        for (i = 0; i < 4; i++) {
            if (order[i] != cur && GwPlayer[order[i]].coin >= 5) {
                D_8011E2D8_3B3658_w06 = order[i];
                break;
            }
        }
    }
    if (i == 4) {
        D_8011E2D4_3B3654_w06 = 2;
    }
}

s32 func_80107438_39C7B8_w06(u8 *arg0, s32 arg1, s32 arg2) {
    s32 var_s2 = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS];
    s32 i;
    s32 j;

    *(Unk4Bytes *)sp20 = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                if (arg1 == 0) {
                    func_801072A0_39C620_w06();
                    var_s2 = D_8011E2D4_3B3654_w06 + 1;
                } else {
                    var_s2 = D_8011E2D8_3B3658_w06 + 1;
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

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            if (--var_s2 == 0) {
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
    while (1) {
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

s32 func_80107704_39CA84_w06(u8 *arg0) {
    return func_80107438_39C7B8_w06(arg0, 0, 1);
}

s32 func_80107724_39CAA4_w06(u8 *arg0) {
    return func_80107438_39C7B8_w06(arg0, 1, 0);
}

void func_80107744_39CAC4_w06(void) {
    GwSystem.current_board_index = 5;
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x47, 0, 0x192);
}

void func_80107780_39CB00_w06(void) {
    omInitObjMan(0xA, 0);
    MBMoveMasuSet(0, 0, 0);
    MBMoveMasuSet(1, 0, 0);
    MBMoveMasuSet(2, 0, 0);
    MBMoveMasuSet(3, 0, 0);
    GWBoardFlagSet(3);
    func_801059F8_39AD78_w06();
    GwSystem.bank_coins = 0;
    GwSystem.slow_dice_flags = 0;
    GwSystem.forceShopHost = 0;
    GwSystem.wackyWatchUsedState = 0;
    GwSystem.boardData.halfWordBytes[0] = 0;
    GwSystem.boardData.halfWordBytes[1] = 5;
    GwSystem.boardData.halfWordBytes[2] = -1;
    func_8011A2A0_3AF620_w06();
    omOvlReturnEx(1);
}

void func_80107828_39CBA8_w06(void) {
    Vec sp10;
    SpaceData *space;
    s32 i;

    omInitObjMan(0xA0, 0x28);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(2, 0xC8, 0xC8, 0xC8);
    MBObjectSetup(0x12, 0x23F, 0x14, 0);
    MBMasuBlockTblExtSet(&D_8011B60C_3B098C_w06);
    MBMasuBlockTblSet(D_8011B610_3B0990_w06);
    space = MBMasuGet(0x6C);
    MBVecDirGet(&space->coords, &MBMasuGet(0x90)->coords, &sp10);
    MBMasuArrowAngleAdd(MBVecAngleGet(&sp10) + 180.0f);
    space = MBMasuGet(0x79);
    MBVecDirGet(&space->coords, &MBMasuGet(0x8C)->coords, &sp10);
    MBMasuArrowAngleAdd(MBVecAngleGet(&sp10) + 180.0f);
    MBItemHookSet(0, &func_8010F20C_3A458C_w06); // boo event
    MBItemHookSet(1, &func_8011068C_3A5A0C_w06); // magic lamp
    MBItemHookSet(9, &func_80110A54_3A5DD4_w06);
    MBItemHookSet(2, &func_80110AC0_3A5E40_w06); // warp block
    MBItemHookSet(3, &func_80118FF0_3AE370_w06); // plunder chest
    MBItemHookSet(4, &func_80111CCC_3A704C_w06); // activate bowser suit
    MBItemHookSet(5, &func_80111F58_3A72D8_w06); // when landing on a space as bowser suit
    MBItemHookSet(6, &func_80110FB4_3A6334_w06); // mushroom/golden mushroom/bowser suit
    MBItemHookSet(7, &func_80111524_3A68A4_w06); // dueling glove/boo bell (?)
    MBItemHookSet(8, &func_80111870_3A6BF0_w06);
    MBItemHookSet(0xA, &func_801182EC_3AD66C_w06); // poison mushroom
    MBItemHookSet(0xB, &func_80118B6C_3ADEEC_w06); // reverse mushroom
    MBItemHookSet(0xE, &func_801123A8_3A7728_w06);
    MBItemHookSet(0xF, &func_80112668_3A79E8_w06);  // bowser phone
    MBItemHookSet(0x10, &func_80112A08_3A7D88_w06); // lucky lamp
    MBItemHookSet(0x11, &func_80113404_3A8784_w06); // skeleton key throw away event
    MBItemHookSet(0x12, &func_80113F5C_3A92DC_w06); // boo repellant/koopa kard thrown away
    MBItemHookSet(0x13, &func_80114C74_3A9FF4_w06); // barter box
    MBItemHookSet(0x14, &func_80115F10_3AB290_w06); // game guy coin
    MBItemHookSet(0x15, &func_80116F10_3AC290_w06); // wacky watch
    MBItemHookSet(0xC, &func_8011813C_3AD4BC_w06);
    MBItemHookSet(0xD, &func_80118A34_3ADDB4_w06);
    MBComItemDecideHookSet(func_8011AB80_3AFF00_w06);

    for (i = 0; i < ARRAY_COUNT(D_8011B5C0_3B0940_w06); i++) {
        MBMasuStarSet(i, D_8011B5C0_3B0940_w06[i]);
    }

    if (GWBoardFlagCheck(0xE) != 0) {
        GWBoardFlagClear(0xE);
        func_80105B00_39AE80_w06();
    }

    func_80105B8C_39AF0C_w06();
    func_80107D98_39D118_w06();
    func_80107F64_39D2E4_w06();
    func_80108228_39D5A8_w06();
    func_801083FC_39D77C_w06();
    func_8010866C_39D9EC_w06();
    func_801086EC_39DA6C_w06();
    func_80108764_39DAE4_w06();
    func_801087DC_39DB5C_w06();
    func_80108950_39DCD0_w06();
    func_80108A2C_39DDAC_w06();
    func_8011A1E8_3AF568_w06();
    func_80117E30_3AD1B0_w06();
    func_800EBDAC_FF9CC_shared_board();
}

void func_80107B54_39CED4_w06(void) {
    HuAudSeqPlay(0x1D);
    D_800CE198_CED98 = 0x1D;
    func_800F8D6C_10C98C_shared_board(0x1D);
    Hu3DCamInit(2);
    func_80107828_39CBA8_w06();
    MBMasuEventTblAdd((event_table_entry *)D_8011C9BC_3B1D3C_w06);
    MBMasuEventTblAdd((event_table_entry *)D_8011CC58_3B1FD8_w06);
    MBHatenaFuncSet(&func_8011A110_3AF490_w06);
    MBMasuEventTblAdd((event_table_entry *)D_8011CA34_3B1DB4_w06);
    MBMasuEventTblAdd((event_table_entry *)D_8011CBC8_3B1F48_w06);
    MBStart(0);
}

void func_80107BD8_39CF58_w06(void) {
    Hu3DCamInit(1);
    func_80107828_39CBA8_w06();
    MBStart(1);
}

void func_80107C04_39CF84_w06(s16 arg0) {
    Object *obj;

    if (D_8011E278_3B35F8_w06[arg0] != NULL) {
        return;
    }
    obj = MBModelCreate(0x3A, NULL);
    func_800461B4_46DB4(obj->omObj1->model[0]);
    if (D_8011E270_3B35F0_w06 == NULL) {
        D_8011E270_3B35F0_w06 = obj;
    }
    D_8011E278_3B35F8_w06[arg0] = obj;
    obj->flags |= 2;
    HuVecCopyXYZ(&obj->scale, 0.6f, 0.6f, 0.6f);
    obj->velocity.x = 10.0f;
    D_8011E298_3B3618_w06[arg0] = func_800EDB98_1017B8_shared_board(obj, 6.0f, 2.0f);
    HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011B688_3B0A08_w06[arg0])->coords);
    func_800D771C_EB33C_shared_board(0xB, obj, D_8011B640_3B09C0_w06[arg0][0], D_8011B640_3B09C0_w06[arg0][1]);
}

void func_80107D2C_39D0AC_w06(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        Process *prc = D_8011E298_3B3618_w06[i];

        if (prc != NULL) {
            omDelPrcObj(prc);
            D_8011E298_3B3618_w06[i] = NULL;
        }
    }
    func_80108A10_39DD90_w06();
}

void func_80107D98_39D118_w06(void) {
    s32 i;

    D_8011E270_3B35F0_w06 = 0;
    for (i = 0; i < 8; i++) {
        D_8011E278_3B35F8_w06[i] = 0;
        D_8011E298_3B3618_w06[i] = NULL;
        MBKinokoEffKillHookSet(func_80107D2C_39D0AC_w06);
        if (!GWBoardFlagCheck(D_8011B698_3B0A18_w06[i])) {
            func_80107C04_39CF84_w06((s16)i);
        }
    }
}

void func_80107E44_39D1C4_w06(s16 arg0) {
    Object *obj;

    if (D_8011E2E0_3B3660_w06[arg0] != NULL) {
        return;
    }
    if (D_8011E2DC_3B365C_w06 == NULL) {
        obj = MBModelCreate(0xA, NULL);
        func_8001FA68_20668(obj->omObj1->model[0]);
        func_8001FA68_20668(obj->omObj2->model[0]);
        D_8011E2DC_3B365C_w06 = obj;
    } else {
        obj = MBModelLinkCreate(D_8011E2DC_3B365C_w06);
    }
    MBModelDispOff(obj);
    D_8011E2E0_3B3660_w06[arg0] = obj;
    obj->flags |= 2;
    obj->velocity.x = 15.0f;
    HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011B6A8_3B0A28_w06[arg0])->coords);
    func_800D771C_EB33C_shared_board(0xA, obj, D_8011B660_3B09E0_w06[arg0][0], D_8011B660_3B09E0_w06[arg0][1]);
}

void func_80107F64_39D2E4_w06(void) {
    s32 i;

    D_8011E2DC_3B365C_w06 = 0;
    for (i = 0; i <= 0; i++) {
        D_8011E2E0_3B3660_w06[i] = NULL;
        func_80107E44_39D1C4_w06(i);
    }
}

void func_80107FC0_39D340_w06(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 2; i++) {
        count = ((s16)GwSystem.bank_coins + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_8011E2E8_3B3668_w06[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_8011E2E8_3B3668_w06[i * 5 + j]);
        }
    }
}

void func_801080BC_39D43C_w06(s16 arg0) {
    Object *obj;

    if (D_8011E2E8_3B3668_w06[arg0] != NULL) {
        return;
    }
    if (D_8011E2E4_3B3664_w06 == NULL) {
        obj = MBModelCreate(0x1E, NULL);
        MBModelTempAllocFree(obj);
        D_8011E2E4_3B3664_w06 = obj;
    } else {
        obj = MBModelLinkCreate(D_8011E2E4_3B3664_w06);
    }
    D_8011E2E8_3B3668_w06[arg0] = obj;
    obj->flags |= 2;
    HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011B6AC_3B0A2C_w06[arg0 / 5])->coords);
    HuVecAdd(&obj->coords, &D_8011B6B0_3B0A30_w06[arg0 % 5], &obj->coords);
    obj->omObj1->rot.x = D_8011B6EC_3B0A6C_w06[arg0 % 5].x;
    obj->omObj1->rot.z = D_8011B6EC_3B0A6C_w06[arg0 % 5].z;
    MBModelDispOff(obj);
}

void func_80108228_39D5A8_w06(void) {
    s32 i;

    D_8011E2E4_3B3664_w06 = 0;
    for (i = 0; i < 0xA; i++) {
        D_8011E2E8_3B3668_w06[i] = NULL;
        func_801080BC_39D43C_w06(i);
    }
    func_80107FC0_39D340_w06();
}

void func_80108290_39D610_w06(s16 arg0) {
    Object *obj;
    s32 unk[2]; // unreferenced; preserves an 8-byte stack slot

    if (D_8011E314_3B3694_w06[arg0] != NULL) {
        return;
    }
    if (D_8011E310_3B3690_w06 == NULL) {
        s32 board = GwSystem.current_board_index;

        obj = MBModelCreate(D_8011B72D_3B0AAD_w06[board][0], D_8011B768_3B0AE8_w06[board]);
        MBModelTempAllocFree(obj);
        D_8011E310_3B3690_w06 = obj;
    } else {
        obj = MBModelLinkCreate(D_8011E310_3B3690_w06);
    }
    D_8011E314_3B3694_w06[arg0] = obj;
    obj->flags |= 2;
    func_8001C814_1D414(obj->omObj1->model[0], 2, 1);
    HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011B728_3B0AA8_w06[arg0])->coords);
    {
        SpaceData *masuA = MBMasuGet(D_8011B680_3B0A00_w06[arg0][0]);
        SpaceData *masuB = MBMasuGet(D_8011B680_3B0A00_w06[arg0][1]);

        MBVecDirGet(&masuB->coords, &masuA->coords, &obj->rot);
    }
    func_800D771C_EB33C_shared_board(0xC, obj, D_8011B678_3B09F8_w06[arg0][0], D_8011B678_3B09F8_w06[arg0][1]);
}

void func_801083FC_39D77C_w06(void) {
    s32 i;

    D_8011E310_3B3690_w06 = 0;
    for (i = 0; i < 2; i++) {
        D_8011E314_3B3694_w06[i] = NULL;
        func_80108290_39D610_w06((s16)i);
    }
}

void func_8010845C_39D7DC_w06(void) {
    HuPrcSleep(D_8011B7C8_3B0B48_w06[GwSystem.current_board_index]);
    HuAudFXPlay(D_8011B7A6_3B0B26_w06[GwSystem.current_board_index][0]);
    omDelPrcObj(NULL);
}

void func_801084B8_39D838_w06(s32 arg0, s32 arg1) {
    s32 *sndEntry;
    s32 *base;
    s32 board;

    MBMotionSet(D_8011E314_3B3694_w06[arg0], arg1 - 1, 0);
    func_8001C814_1D414(D_8011E314_3B3694_w06[arg0]->omObj1->model[0], 5, 0);

    board = GwSystem.current_board_index;
    base = D_8011B780_3B0B00_w06;
    sndEntry = base + board;
    if (*sndEntry != -1) {
        HuAudFXPlay(((s16 *)sndEntry)[1]);
    }

    if (D_8011B7A4_3B0B24_w06[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_8010845C_39D7DC_w06, 0x1000, 0, 0);
    }
}

void func_80108580_39D900_w06(void) {
    s32 index;
    s32 sleep;
    s32 *sndEntry;
    s32 *base;
    s32 board;

    index = (s32)HuPrcCurrentGet()->user_data;

    switch (GwSystem.walk_speed) {
        case 0:
            sleep = 5;
            break;
        case 1:
            sleep = 10;
            break;
        default:
            sleep = 15;
            break;
    }

    HuPrcSleep(sleep);
    func_8001C814_1D414(D_8011E314_3B3694_w06[index]->omObj1->model[0], 1, 4);

    board = GwSystem.current_board_index;
    base = D_8011B7EC_3B0B6C_w06;
    sndEntry = base + board;
    if (*sndEntry != -1) {
        HuAudFXPlay(((s16 *)sndEntry)[1]);
    }

    omDelPrcObj(NULL);
}

void func_80108630_39D9B0_w06(s32 arg) {
    Process *temp = omAddPrcObj(func_80108580_39D900_w06, 0x1000, 0, 0);

    temp->user_data = (void *)arg;
}

void func_8010866C_39D9EC_w06(void) {
    s32 i;

    D_8011E310_3B3690_w06 = 0;
    for (i = 0; i < 2; i++) {
        func_800D7790_EB3B0_shared_board(8, &MBMasuGet(D_8011B810_3B0B90_w06[i])->coords,
                                         D_8011B668_3B09E8_w06[i][0], D_8011B668_3B09E8_w06[i][1]);
    }
}

void func_801086EC_39DA6C_w06(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_800D7790_EB3B0_shared_board(9, &MBMasuGet(D_8011B814_3B0B94_w06[i])->coords,
                                         D_8011B670_3B09F0_w06[i][0], D_8011B670_3B09F0_w06[i][1]);
    }
}

void func_80108764_39DAE4_w06(void) {
    SpaceData *masu = MBMasuGet(0x8B);
    Object *obj = MBModelFileCreate(0x130186, -1, 1.0f, 0, 0);

    MBModelTempAllocFree(obj);
    D_8011B818_3B0B98_w06 = obj;
    obj->flags |= 2;
    HuVecCopy3F(&obj->coords, &masu->coords);
}

void func_801087DC_39DB5C_w06(void) {
    s32 i;
    Object *obj;

    for (i = 0; i < 3; i++) {
        if (i == 0) {
            obj = MBModelFileCreate(0x130185, -1, 1.0f, 0, 0);
            MBModelTempAllocFree(obj);
            D_8011B824_3B0BA4_w06 = obj;
        } else {
            obj = MBModelLinkCreate(D_8011B824_3B0BA4_w06);
        }
        D_8011E31C_3B369C_w06[i] = obj;
        obj->flags |= 2;
        HuVecCopy3F(&obj->coords, &MBMasuGet(D_8011B81C_3B0B9C_w06[i])->coords);
    }
}

void func_801088B4_39DC34_w06(void) {
    func_80032FF8_33BF8(D_8011B82C_3B0BAC_w06, (u8)GwSystem.boardData.bytes[3]);
    func_8001C448_1D048(D_8011E328_3B36A8_w06->omObj1->model[0]);
}

void func_801088F4_39DC74_w06(void) {
    if (D_8011B828_3B0BA8_w06 != NULL) {
        DataClose(D_8011B828_3B0BA8_w06);
        D_8011B828_3B0BA8_w06 = NULL;
    }
    if (D_8011B82C_3B0BAC_w06 != -1) {
        func_80033430_34030(D_8011B82C_3B0BAC_w06);
        D_8011B82C_3B0BAC_w06 = -1;
    }
}

// Keep rodata definitions interleaved with functions to preserve the original constant order.
const u8 D_8011E0E0_3B3460_w06[4] = { 1, 2, 4, 8 };

void func_80108950_39DCD0_w06(void) {
    Object *obj = MBModelFileCreate(0x130189, -1, 1.0f, 0, 0);
    void *data;

    D_8011E328_3B36A8_w06 = obj;
    obj->flags |= 2;
    HuVecCopy3F(&obj->coords, &MBMasuGet(0x94)->coords);
    data = DataRead(0x13018A);
    D_8011B828_3B0BA8_w06 = data;
    D_8011B82C_3B0BAC_w06 = HmfAnimCreate(HmfModelData[obj->omObj1->model[0]].hmf, data, 0, "count_1_DEF");
    func_801088B4_39DC34_w06();
}

void func_80108A10_39DD90_w06(void) {
    func_801088F4_39DC74_w06();
}

void func_80108A2C_39DDAC_w06(void) {
    s32 i;
    Object *obj;
    SpaceData *masuA;

    for (i = 0; i < 2; i++) {
        Object **objArr = D_8011E32C_3B36AC_w06;
        s16 *coordsArr = D_8011B830_3B0BB0_w06;
        s16(*masuAArr)[2] = D_8011B834_3B0BB4_w06;
        s16(*masuBArr)[2] = D_8011B836_3B0BB6_w06;

        if (i == 0) {
            obj = MBModelFileCreate(0x130187, -1, 1.0f, 0, 0);
            MBModelTempAllocFree(obj);
            D_8011B83C_3B0BBC_w06 = obj;
        } else {
            obj = MBModelLinkCreate(D_8011B83C_3B0BBC_w06);
        }
        objArr[i] = obj;
        obj->flags |= 2;
        masuA = MBMasuGet(coordsArr[i]);
        HuVecCopy3F(&obj->coords, &masuA->coords);
        masuA = MBMasuGet(masuAArr[i][0]);
        MBVecDirGet(&masuA->coords, &MBMasuGet(masuBArr[i][0])->coords, &obj->rot);
        if (GwSystem.boardData.halfWordBytes[0] == i) {
            func_8001C6A8_1D2A8(obj->omObj1->model[0], 1000.0f);
        }
        func_8001C814_1D414(obj->omObj1->model[0], 6, 1);
    }
}

void func_80108B9C_39DF1C_w06(void) {
    MBMoveNextMasuSet(-1, 1, 0xA);
    MBMoveBackMasuSet(-1, 1, 0xA);
}

void func_80108BD0_39DF50_w06(void) {
    void *data;
    s32 spriteId;
    s32 grp;
    s32 count;
    s32 wrapped;
    s32 fading;
    s32 mask;
    s32 clampedAlpha;
    s32 alpha;
    f32 angle;
    f32 speed;

    data = DataRead(0x1300F7);
    spriteId = func_80055810_56410(data);
    DataClose(data);
    grp = HuSprGrpCreate(1, 5);
    func_80055024_55C24(grp, 0, spriteId, 0);
    HuSprAttrReset(grp, 0, 0xFFFF);
    HuSprAttrSet(grp, 0, 0x1008);
    HuSprPriSet(grp, 0, 0x1000);
    func_80054904_55504(grp, 0, 0xA0, 0x5A);

    angle = 0.0f;
    speed = 30.0f;
    count = 0;
    wrapped = 0;

    while (1) {
        if (angle >= 90.0f && wrapped == 0) {
            wrapped = 1;
            count++;
        }
        if (angle >= 360.0f) {
            wrapped = 0;
            angle -= 360.0f;
        }
        if (angle >= 180.0f && angle <= 360.0f) {
            HuSprAttrSet(grp, 0, 2);
        } else {
            HuSprAttrReset(grp, 0, 2);
        }
        HuSprScaleSet(grp, 0, 1.0f, HuMathSin(angle >= 180.0f ? angle - 180.0f : angle));
        if (count >= 2) {
            break;
        }
        HuPrcVSleep();
        angle += speed;
    }

    HuSprAttrReset(grp, 0, 2);
    HuSprScaleSet(grp, 0, 1.0f, 1.0f);
    HuPrcSleep(20);

    angle = 90.0f;
    count = 0;
    fading = 0;
    wrapped = 0;
    alpha = 255;

    while (1) {
        if (angle >= 360.0f && wrapped == 0) {
            wrapped = 1;
            count++;
        }
        if (angle >= 360.0f) {
            wrapped = 0;
            angle -= 360.0f;
        }
        if (fading == 0 && count != 0) {
            if (angle >= 90.0f && angle < 180.0f) {
                fading = 1;
            }
        }
        if (fading != 0) {
            alpha -= 21;
            mask = -(alpha > 0);
            clampedAlpha = mask & alpha;
            alpha = clampedAlpha;
        }
        func_80055458_56058(grp, 0, alpha);
        if (count >= 2) {
            break;
        }
        HuPrcVSleep();
        angle += speed;
    }

    HuSprScaleSet(grp, 0, 1.0f, 0.0f);
    HuSprGrpKill(grp);
    HuSprKill(spriteId);
    omDelPrcObj(NULL);
}

Process *func_80108F68_39E2E8_w06(void) {
    return omAddPrcObj(func_80108BD0_39DF50_w06, 0x1000, 0, 0);
}

void func_80108F94_39E314_w06(void) {
    StarMasuTable masuTable = D_8011E0F0_3B3470_w06;
    StarDelayTable delayTable = D_8011E100_3B3480_w06;
    Process *prc = HuPrcCurrentGet();
    Object *model;
    SpaceData *space;
    StarMasuSlot *slot;
    s32 idx;
    s32 playedSfx = 0;
    s32 delay;

    model = MBModelFileCreate(0x130188, -1, 1.1f, 0, 0);
    MBModelTempAllocFree(model);
    delay = delayTable.times[MBRand(10.0f)];
    idx = MBRand(4.0f);

    while (prc->user_data == NULL) {
        idx++;
        idx &= 3;
        D_8011E338_3B36B8_w06 = idx;
        slot = (StarMasuSlot *)((idx << 2) + (s32)masuTable.entries); // manual index math; GCC orders the addu operands differently with plain array indexing
        space = MBMasuGet(slot->masuId);
        HuVecCopy3F(&model->coords, &space->coords);
        model->coords.z -= 1.0f;
        model->rot.x = HuMathSin(180 - (idx * 90));
        model->rot.z = HuMathCos(180 - (idx * 90));
        HuAudFXPlay(0x1B6);
        HuPrcSleep(delay - 1);
    }

    D_8011E334_3B36B4_w06 = idx;
    HuPrcSleep(10);
    idx = 0;

    if ((s32)prc->user_data != 2) {
        while ((s32)prc->user_data != 2) {
            if (playedSfx == 0) {
                HuAudFXPlay(0x1B7);
                playedSfx = 1;
            }
            idx++;
            if (idx & 2) {
                MBModelDispOff(model);
            } else {
                MBModelDispOn(model);
            }
            HuPrcVSleep();
        }
    }

    MBModelKill(model);
    prc->user_data = NULL;
    omDelPrcObj(NULL);
}

void func_801091EC_39E56C_w06(void) {
    StarChaseWork work;
    Unk3 *helpWin;
    s16 msgWin;
    SpaceData *starMasu = MBMasuGet(0x99);
    GW_PLAYER *player = MBPlayerGet(-1);
    Process *starPrc;
    s16 comResult;
    s32 playerIdx;
    s32 i;

    playerIdx = GwSystem.current_player_index;

    work.chaseChanceA = D_8011E10C_3B348C_w06;
    work.chaseChanceB = D_8011E11C_3B349C_w06;
    comResult = 0;
    MBStatusHideAll();
    func_800DBEC0_EFAE0_shared_board(playerIdx);
    MBVecDirGet(&player->player_obj->coords, &starMasu->coords, &work.dir);
    HuPrcChildLink(HuPrcCurrentGet(), func_800ED128_100D48_shared_board(&player->player_obj->rot, &work.dir, &player->player_obj->rot, 5));
    HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.0f));
    HuPrcChildWait();
    HuVecCopy3F(&work.pos, &player->player_obj->coords);
    MBCameraFocusModeSet(4);
    MBCameraFocusVecSet(&work.pos);
    HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(&work.pos, &starMasu->coords, &work.pos, 30));
    HuPrcChildWait();
    starPrc = omAddPrcObj(func_80108F94_39E314_w06, 0x1000, 0, 0);
    HuPrcChildLink(HuPrcCurrentGet(), func_80108F68_39E2E8_w06());
    HuPrcSleep(30);
    msgWin = func_8005A968_5B568(0x6E, 0xB2, 0x64, 0x18, 0, 0);
    func_8005BEE0_5CAE0(msgWin, 0x100);
    func_8005FBF8_607F8(msgWin, 0x8C, 0xC8, 0x3C);
    helpWin = func_800E210C_F5D2C_shared_board(0x14, 0xB4, 1);
    HuPrcChildWait();

    if (MBPlayerComCheck(-1) != 0) {
        if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011C054_3B13D4_w06) != 0) {
            comResult = 1;
            if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011C078_3B13F8_w06) != 0) {
                comResult |= 2;
            } else {
                comResult = 1;
            }
        } else {
            comResult = 0;
        }
    }
    i = 0;

    while (1) {
        if (MBPlayerComCheck(-1) != 0) {
            if ((D_8011E338_3B36B8_w06 == comResult && MBRand(100.0f) < work.chaseChanceA.entries[player->cpu_difficulty])) {
                goto move;
            }
            if (MBRand(100.0f) < work.chaseChanceB.entries[player->cpu_difficulty]) {
                goto move;
            }
            goto sleep;
        }
        if (!(D_800C9520_CA120[GwPlayer[playerIdx].pad] & 0x8000)) {
            goto sleep;
        }

    move:
        func_8004ACE0_4B8E0(0x3A, playerIdx);
        MBPlayerMotionSet(-1, 2, 0);
        func_800EE688_1022A8_shared_board(player->player_obj, 16.0f, -0.95f);
        HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(
                                              &player->player_obj->coords, &starMasu->coords, &player->player_obj->coords, 31));
        break;

    sleep:
        HuPrcVSleep();
        i++;
        if (i >= 150) {
            break;
        }
    }

    MBHelpWinKill(helpWin);
    func_8005F364_5FF64(msgWin);

    if (i == 150) {
        starPrc->user_data = (void *)2;
        MBDlgResultWinExec(0x1000);
    } else {

        HuPrcChildWait();
        MBPlayerVibrate(-1, 2);
        MBPlayerMotionSet(-1, -1, 2);
        func_8004ACE0_4B8E0(0x31, playerIdx);
        starPrc->user_data = (void *)1;
        HuPrcSleep(40);
        starPrc->user_data = (void *)2;

        if (D_8011E334_3B36B4_w06 != 2) {
            s16 eventId;
            s16 eventArg;

            MBMoveMasuSet(-1, 0x15, 0);
            work.eventTableA = D_8011E12C_3B34AC_w06;
            work.eventTableB = D_8011E13C_3B34BC_w06;
            eventId = ((s16 *)work.eventTableA.entries)[D_8011E334_3B36B4_w06 * 2 + 1];
            eventArg = ((s16 *)work.eventTableB.entries)[D_8011E334_3B36B4_w06 * 2 + 1];
            MBMoveNextMasuSet(-1, eventId, eventArg);
            goto restoreCamera;
        } else {
            starMasu = MBMasuGet(0x77);
            MBVecDirGet(&player->player_obj->coords, &starMasu->coords, &player->player_obj->rot);
            func_8004ACE0_4B8E0(0x3A, playerIdx);
            MBPlayerMotionSet(-1, 2, 0);
            func_800EE688_1022A8_shared_board(player->player_obj, 15.0f, -2.0f);
            HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(
                                                  &player->player_obj->coords, &starMasu->coords, &player->player_obj->coords, 14));
            HuPrcChildWait();
            MBPlayerMotionSet(-1, -1, 2);
            func_8004ACE0_4B8E0(0x31, playerIdx);
        }
    }

    MBMoveNextMasuSet(-1, 2, 0);
    HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(&work.pos, &player->player_obj->coords, &work.pos, 20));
    HuPrcChildWait();

restoreCamera:
    MBCameraFocusModeSet(1);
    MBStatusShowAll();
    func_800DB884_EF4A4_shared_board(playerIdx);
    HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.3f));
    HuPrcChildWait();
}

void func_8010980C_39EB8C_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    func_80117814_3ACB94_w06(D_8011C090_3B1410_w06, D_8011C0A4_3B1424_w06, D_8011B870_3B0BF0_w06);
    if (player->nlink == 0x15) {
        func_801091EC_39E56C_w06();
    }
    omDelPrcObj(NULL);
}

void func_80109870_39EBF0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x5C && !(player->rev & 0x80)) {
        MBMoveNextMasuSet(-1, 3, 4);
        player->rev &= ~1;
    } else {
        func_80117814_3ACB94_w06(D_8011C0D8_3B1458_w06, D_8011C0EC_3B146C_w06, D_8011B924_3B0CA4_w06);
    }
}

void func_80109918_39EC98_w06(void) {
    func_80117814_3ACB94_w06(D_8011C120_3B14A0_w06, D_8011C134_3B14B4_w06, D_8011B99C_3B0D1C_w06);
    omDelPrcObj(NULL);
}

void func_80109950_39ECD0_w06(void) {
    func_80117814_3ACB94_w06(D_8011C168_3B14E8_w06, D_8011C17C_3B14FC_w06, D_8011BA2C_3B0DAC_w06);
    omDelPrcObj(NULL);
}

void func_80109988_39ED08_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if (GwSystem.boardData.halfWordBytes[0] == 0) {
        func_80117814_3ACB94_w06(D_8011C1B0_3B1530_w06, D_8011C1C4_3B1544_w06, D_8011BA8C_3B0E0C_w06);
    } else {
        s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

        if (masu == 0x38) {
            MBMoveNextMasuSet(-1, 0xE, 0);
        } else {
            MBMoveNextMasuSet(-1, 0xD, 3);
            player->rev |= 1;
        }
    }
    omDelPrcObj(NULL);
}

void func_80109A50_39EDD0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if (GwSystem.boardData.halfWordBytes[0] == 1) {
        func_80117814_3ACB94_w06(D_8011C1F8_3B1578_w06, D_8011C20C_3B158C_w06, D_8011BB04_3B0E84_w06);
    } else {
        s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

        if (masu == 0x1C) {
            MBMoveNextMasuSet(-1, 6, 0);
        } else {
            MBMoveNextMasuSet(-1, 5, 4);
            player->rev |= 1;
        }
    }
    omDelPrcObj(NULL);
}

void func_80109B1C_39EE9C_w06(void) {
    func_80117814_3ACB94_w06(D_8011C240_3B15C0_w06, D_8011C254_3B15D4_w06, D_8011BB4C_3B0ECC_w06);
    omDelPrcObj(NULL);
}

void func_80109B54_39EED4_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x96 && !(player->rev & 0x80)) {
        MBMoveNextMasuSet(-1, 7, 0);
        player->rev &= ~1;
    } else {
        func_80117814_3ACB94_w06(D_8011C288_3B1608_w06, D_8011C29C_3B161C_w06, D_8011BBA0_3B0F20_w06);
    }
    omDelPrcObj(NULL);
}

void func_80109C04_39EF84_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu != 0x3F) {
        MBMoveNextMasuSet(-1, 0x11, 0);
        player->rev |= 1;
    } else {
        MBDlgResultWinExec(0xE01);
        func_80117814_3ACB94_w06(D_8011C2D0_3B1650_w06, D_8011C2E4_3B1664_w06, D_8011BBB8_3B0F38_w06);
    }
}

void func_80109CA4_39F024_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu != 0x40) {
        MBMoveNextMasuSet(-1, 0x12, 1);
        player->rev &= ~1;
    } else {
        MBDlgResultWinExec(0xE01);
        func_80117814_3ACB94_w06(D_8011C318_3B1698_w06, D_8011C32C_3B16AC_w06, D_8011BBD0_3B0F50_w06);
    }
}

void func_80109D44_39F0C4_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu;

    if (GwSystem.boardData.halfWordBytes[0] == 0 && (player->rev & 0x80)) {
        func_80117814_3ACB94_w06(D_8011C360_3B16E0_w06, D_8011C374_3B16F4_w06, D_8011BC78_3B0FF8_w06);
    } else {
        masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);
        if (masu == 0x2D) {
            goto boost;
        }
        if (masu != 0x75) {
            goto normal;
        }
    boost:
        MBMoveNextMasuSet(-1, 0xB, 5);
        goto done;
    normal:
        MBMoveNextMasuSet(-1, 0xB, 3);
        player->rev |= 1;
    done:;
    }
    omDelPrcObj(0);
}

void func_80109E28_39F1A8_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu;

    if (GwSystem.boardData.halfWordBytes[0] == 1 && (player->rev & 0x80)) {
        func_80117814_3ACB94_w06(D_8011C3A8_3B1728_w06, D_8011C3BC_3B173C_w06, D_8011BD38_3B10B8_w06);
    } else {
        masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);
        if (masu == 0x32) {
            goto boost;
        }
        if (masu != 0x70) {
            goto normal;
        }
    boost:
        MBMoveNextMasuSet(-1, 0xB, 0xC);
        goto done;
    normal:
        MBMoveNextMasuSet(-1, 0xB, 0xA);
        player->rev |= 1;
    done:;
    }
    omDelPrcObj(0);
}

void func_80109F10_39F290_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C3F0_3B1770_w06, D_8011C404_3B1784_w06, D_8011BD98_3B1118_w06);
    }
}

void func_80109F68_39F2E8_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C438_3B17B8_w06, D_8011C44C_3B17CC_w06, D_8011BE04_3B1184_w06);
    }
}

void func_80109FC0_39F340_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C480_3B1800_w06, D_8011C494_3B1814_w06, D_8011BE64_3B11E4_w06);
    }
}

void func_8010A018_39F398_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C4C8_3B1848_w06, D_8011C4DC_3B185C_w06, D_8011BEC4_3B1244_w06);
    }
}

void func_8010A070_39F3F0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C510_3B1890_w06, D_8011C524_3B18A4_w06, D_8011BEE8_3B1268_w06);
    }
}

void func_8010A0C8_39F448_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C548_3B18C8_w06, D_8011C55C_3B18DC_w06, D_8011BF9C_3B131C_w06);
    }
}

void func_8010A120_39F4A0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);

    if ((player->rev & 0x80) && mbWalkNum != 0) {
        func_80117814_3ACB94_w06(D_8011C590_3B1910_w06, D_8011C5A4_3B1924_w06, D_8011C014_3B1394_w06);
    }
}

void func_8010A178_39F4F8_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x5D) {
        MBMoveNextMasuSet(-1, 3, 3);
    }
}

void func_8010A1D8_39F558_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x21) {
        MBMoveNextMasuSet(-1, 2, 8);
    }
}

void func_8010A238_39F5B8_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x04) {
        MBMoveNextMasuSet(-1, 2, 0xD);
    }
}

void func_8010A298_39F618_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x5A) {
        MBMoveNextMasuSet(-1, 0x15, 0);
    }
}

void func_8010A2F8_39F678_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x62) {
        MBMoveNextMasuSet(-1, 0x15, 0);
    }
}

void func_8010A358_39F6D8_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x1F) {
        MBMoveNextMasuSet(-1, 0x15, 0);
    }
}

void func_8010A3B8_39F738_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x1A) {
        MBMoveNextMasuSet(-1, 5, 5);
    }
}

void func_8010A418_39F798_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 7) {
        MBMoveNextMasuSet(-1, 6, 0xE);
    } else {
        MBMoveNextMasuSet(-1, 2, 4);
    }
}

void func_8010A488_39F808_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x97) {
        MBMoveNextMasuSet(-1, 0xB, 0xB);
    } else {
        MBMoveNextMasuSet(-1, 5, 5);
    }
}

void func_8010A4F8_39F878_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x74) {
        MBMoveNextMasuSet(-1, 0xB, 4);
    } else {
        MBMoveNextMasuSet(-1, 0xD, 4);
    }
}

void func_8010A560_39F8E0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x2A) {
        MBMoveNextMasuSet(-1, 0xB, 0x14);
    }
}

void func_8010A5C0_39F940_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x3A) {
        MBMoveNextMasuSet(-1, 4, 3);
    }
}

void func_8010A620_39F9A0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x35) {
        MBMoveNextMasuSet(-1, 0xD, 4);
    }
}

void func_8010A680_39FA00_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x3D) {
        MBMoveNextMasuSet(-1, 4, 3);
    }
}

void func_8010A6E0_39FA60_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x4F) {
        MBMoveNextMasuSet(-1, 0xF, 4);
    }
}

void func_8010A740_39FAC0_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x47) {
        MBMoveNextMasuSet(-1, 3, 8);
    }
}

void func_8010A7A0_39FB20_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x7B) {
        MBMoveNextMasuSet(-1, 0xF, 4);
    }
}

void func_8010A800_39FB80_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x45) {
        MBMoveNextMasuSet(-1, 0x10, 8);
    }
}

void func_8010A860_39FBE0_w06(void) {
    Vec sp18;
    GW_PLAYER *player;
    Object *model1;
    Object *model2;
    SpaceData *masu;
    f32 scale;
    s32 playerIdx = GwSystem.current_player_index;

    player = MBPlayerGet(-1);
    MBPlayerMotionSet(-1, -1, 2);
    MBVecForwardSet(&sp18);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_800ED128_100D48_shared_board(&player->player_obj->rot, &sp18, &player->player_obj->rot, 5));
    HuPrcSleep(0x1E);
    if (MBRand(2.0f) == 0) {
        func_800DBEC0_EFAE0_shared_board(playerIdx);
        model1 = MBModelFileCreate(0x13018B, -1, 1.0f, 0, 0);
        func_8001C258_1CE58(model1->omObj1->model[0], 0x180, 0);
        func_8001C8E4_1D4E4(model1->omObj1->model[0], 0);
        func_8001C448_1D048(model1->omObj1->model[0]);
        MBModelTempAllocFree(model1);
        HuVecCopy3F(&model1->coords, &player->player_obj->coords);
        model2 = MBModelFileCreate(0x13018C, -1, 1.0f, 0, 0);
        func_8001C8E4_1D4E4(model2->omObj1->model[0], 0);
        func_8001C258_1CE58(model2->omObj1->model[0], 0x80000, 0x80000);
        func_8001C448_1D048(model2->omObj1->model[0]);
        MBModelTempAllocFree(model2);
        HuVecCopy3F(&model2->coords, &player->player_obj->coords);
        HuAudFXPlay(0x1BD);
        func_8004ACE0_4B8E0(0x286, playerIdx);
        MBPlayerVibrate(-1, 4);
        scale = 1.0f;
        player->stat |= 4;
        while (player->player_obj->velocity.x >= -25.0f) {
            player->player_obj->velocity.x -= 3.0f;
            HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
            scale -= 0.1f;
            if (scale < 0.0f) {
                scale = 0.0f;
            }
            HuPrcVSleep();
        }
        scale = 0.0f;
        HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
        HuPrcChildWait();
        WipeCreateOut(0, 0x10);
        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        MBModelKill(model2);
        MBModelKill(model1);
        HuVecCopy3F(&player->player_obj->coords, &MBMasuGet(0x8B)->coords);
        player->player_obj->velocity.x = -4.0f;
        MBVecForwardSet(&player->player_obj->rot);
        HuPrcSleep(2);
        WipeCreateIn(0, 0x10);
        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        HuAudFXPlay(0x1BC);
        while (player->player_obj->velocity.x <= 15.0f) {
            player->player_obj->velocity.x += 1.5f;
            HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
            scale += 0.08f;
            if (scale > 1.0f) {
                scale = 1.0f;
            }
            HuPrcVSleep();
        }
        HuVecCopyXYZ(&player->player_obj->scale, 1.0f, 1.0f, 1.0f);
        player->stat &= ~4;
        masu = MBMasuGet(0x8A);
        MBVecDirGet(&player->player_obj->coords, &masu->coords, &player->player_obj->rot);
        MBPlayerMotionSet(-1, 2, 0);
        func_800EE688_1022A8_shared_board(player->player_obj, 10.0f, -1.5f);
        HuPrcChildLink(HuPrcCurrentGet(),
                       MBPlayerPosMoveCreate(&player->player_obj->coords, &masu->coords, &player->player_obj->coords, 0xE));
        HuPrcChildWait();
        MBPlayerMotionSet(-1, -1, 2);
        MBVecForwardSet(&sp18);
        HuPrcChildLink(HuPrcCurrentGet(),
                       func_800ED128_100D48_shared_board(&player->player_obj->rot, &sp18, &player->player_obj->rot, 5));
        HuPrcChildWait();
        MBDlgResultWinExec(0xE00);
        MBMoveMasuSet(-1, 1, 7);
        MBMoveBackMasuSet(-1, 1, 0);
        func_800DB884_EF4A4_shared_board(playerIdx);
        HuPrcSleep(0xA);
        func_8010A070_39F3F0_w06();
    } else {
        s16 masuId = MBMasuLinkMasuIdGet(player->blink, player->bidx);

        if (masuId == 0x7B) {
            MBMoveNextMasuSet(-1, 0x12, 0);
        } else {
            MBMoveNextMasuSet(-1, 0x11, 1);
        }
    }
}

void func_8010AE18_3A0198_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);

    if (masu == 0x6B) {
        MBMoveBackMasuSet(-1, 1, 9);
    }
}

s32 func_8010AE78_3A01F8_w06(s32 arg0) {
    s32 var_s2 = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS];
    s32 i;
    s32 j;
    s16 *inputs;
    s32 cpu_buttons;
    u8 *choices;

    *(Unk4Bytes *)sp20 = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    i = 0;
    inputs = sp18;
    cpu_buttons = 0x400;
    choices = sp20;
    // Keep the per-player sentinel assignment inside the loop for matching.
next_player:
    if (i == GwSystem.current_player_index) {
        if (GwPlayer[i].stat & 1) {
            var_s2 = 1;
            inputs[GwPlayer[i].pad] = cpu_buttons;
        } else {
            func_8005FE54_60A54(mbDlgWinId, choices[GwPlayer[i].pad]);
            inputs[GwPlayer[i].pad] = -1;
        }
    } else {
        inputs[GwPlayer[i].pad] = 0;
    }

    if (++i < MB_MAX_PLAYERS) {
        goto next_player;
    }

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            if (--var_s2 == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 0x10);
            }
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    func_8005E1D8_5EDD8(mbDlgWinId, 0, 1);
}

void func_8010B088_3A0408_w06(void) {
    GW_SYSTEM *loc;
    GW_PLAYER *player;
    s32 flag;
    s32 choice;
    void *prc;
    s16 sp18;
    s16 masuId;

    loc = &GwSystem;
    player = MBPlayerGet(GwSystem.current_player_index);
    flag = 1;

    if (MBMasuLinkMasuIdGet(player->blink, player->bidx) != 0x88) {
        if (MBMasuLinkMasuIdGet(player->blink, player->bidx) != 0x8D) {
            if (MBItemFind(GwSystem.current_player_index, 1) != -1) {
                func_800DBEC0_EFAE0_shared_board(GwSystem.current_player_index);
                MBPlayerMotionSet(-1, -1, 2);
                sp18 = MBMasuLinkMasuIdGet(player->clink, player->cidx);
                switch (sp18) {
                    case 0x83:
                    case 0x89:
                        func_800ED20C_100E2C_shared_board(-1, 8, 0x88);
                        break;
                    default:
                        func_800ED20C_100E2C_shared_board(-1, 8, 0x8D);
                        break;
                }
                HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.6f));
                HuPrcChildWait();
                MBPlayerVibrate(-1, 1);

                while (1) {
                    MBDlgWinCreate(0x38, 0x4103);
                    choice = func_8010AE78_3A01F8_w06(0);
                    MBDlgWinClose();
                    MBDlgWinKill();

                    switch (choice) {
                        case 0:
                            MBDlgWinExec(0x38, 0x4104);
                            GwPlayer[loc->current_player_index].itemNo[MBItemFind(loc->current_player_index, 1)] = -1;
                            MBItemRemoveEmpty(GwSystem.current_player_index);
                            MBStatusItemIconSprReinit(-1);
                            sp18 = MBMasuLinkMasuIdGet(player->clink, player->cidx);
                            switch (sp18) {
                                case 0x83:
                                    func_801084B8_39D838_w06(0, 0);
                                    break;
                                case 0x89:
                                    func_801084B8_39D838_w06(0, 1);
                                    break;
                                case 0x96:
                                    func_801084B8_39D838_w06(1, 0);
                                    break;
                                default:
                                    func_801084B8_39D838_w06(1, 1);
                                    break;
                            }
                            flag = 0;
                            prc = MBPlayerVibrateObjCreate(-1, 2, 5);
                            HuPrcSleep(0x14);
                            MBPlayerVibrateObjKill(prc);
                            break;
                        case 1:
                            MBDlgWinExec(0x38, 0x4105);
                            break;
                        case 2:
                            func_80106AB0_39BE30_w06();
                            continue;
                        default:
                            break;
                    }
                    break;
                }

                func_800DB884_EF4A4_shared_board(loc->current_player_index);
                HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.3f));
                HuPrcChildWait();
            } else {
                MBDlgWinExec(-1, 0x4106);
            }
        }
    }

    if (flag != 0) {
        masuId = MBMasuLinkMasuIdGet(player->clink, player->cidx);
        switch (masuId) {
            case 0x83:
                MBMoveNextMasuSet(-1, 1, 1);
                player->rev |= 1;
                break;
            case 0x89:
                MBMoveNextMasuSet(-1, 1, 5);
                player->rev &= ~1;
                break;
            case 0x96:
                MBMoveNextMasuSet(-1, 6, 0xE);
                player->rev |= 1;
                break;
            default:
                MBMoveNextMasuSet(-1, 6, 5);
                player->rev &= ~1;
                break;
        }
    }

    omDelPrcObj(NULL);
}

void func_8010B4AC_3A082C_w06(void) {
}

void func_8010B4B4_3A0834_w06(void) {
}

void func_8010B4BC_3A083C_w06(void) {
}

s32 func_8010B4C4_3A0844_w06(s32 arg0, s32 arg1) {
    s32 var_s2 = 0;
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS];
    s32 i;
    s32 j;

    *(Unk4Bytes *)sp20 = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                switch (arg0) {
                    case 0:
                        var_s2 = func_800EF0D8_102CF8_shared_board(0) + 1;
                        break;
                    case 1:
                        var_s2 = func_800EF0D8_102CF8_shared_board(1) + 1;
                        break;
                    case 2:
                        var_s2 = arg1 + 1;
                        break;
                    default:
                        var_s2 = (s16)MBComTreeExec((void *)arg0) + 1;
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

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            if (--var_s2 == 0) {
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

void func_8010B748_3A0AC8_w06(s16 arg0, s32 arg1, s16 arg2, s32 arg3) {
    s16 sp10[2];
    s16 winId;

    func_80060394_60F94(1, sp10, arg1);
    winId = MBWinCreate(arg0, sp10, arg2);
    mbDlgWinId = winId;
    func_8005B43C_5C03C(winId, arg1, -1, -1);
    func_80061388_61F88(winId);
    func_800EBF98_FFBB8_shared_board(winId, arg3);
    func_80061A5C_6265C(winId, 0);
    func_8005F364_5FF64(winId);
}

void func_8010B804_3A0B84_w06(void) {
    while (1) {
        MBStatusItemAttrSet(GwSystem.current_player_index, MBItemSelNoGet(), 0x8000);
        HuPrcVSleep();
    }
}

void func_8010B844_3A0BC4_w06(void) {
    GW_SYSTEM *loc;
    s16 spaceIdx;
    s16 choice;

    spaceIdx = MBMasuCurGet();
    loc = &GwSystem;
    spaceIdx = func_80105C30_39AFB0_w06(spaceIdx);
    if (spaceIdx == 1) {
        func_800DBEC0_EFAE0_shared_board(loc->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_800ED20C_100E2C_shared_board(-1, 8, func_801059D0_39AD50_w06());
        HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.6f));
        HuPrcChildWait();
        HuAudFXPlay(0x159);

        if (GwPlayer[loc->current_player_index].itemTurn != 0) {
            MBDlgWinInsertCreate(0x16, 0x4805, GwPlayer[loc->current_player_index].chr + 0x1C00, 0, 0, 0, 0);
            func_800EC9DC_1005FC_shared_board();
            MBDlgWinClose();
            MBDlgWinKill();
        }

        if (GwPlayer[loc->current_player_index].star >= 99) {
            MBDlgWinExec(0x16, 0x4804);
        } else {
            if (GwPlayer[loc->current_player_index].coin >= 20) {
            purchaseMenu:
                MBDlgWinInsertCreate(0x16, 0x4800, GwPlayer[loc->current_player_index].chr + 0x1C00, 0, 0, 0, 0);
                choice = func_8010B4C4_3A0844_w06(2, 0);
                MBDlgWinClose();
                MBDlgWinKill();

                switch (choice) {
                    case 0:
                        MBCoinChangeCreate(loc->current_player_index, -20);
                        MBCoinTakeCreate(loc->current_player_index, -20);
                        HuPrcSleep(30);
                        MBDlgWinExec(0x16, 0x4802);
                        if (D_800A12D0_A1ED0 != 0) {
                            func_8004A950_4B550();
                            func_800039A4_45A4(D_800C9930_CA530, 60);
                            D_800C9930_CA530 = -1;
                        } else {
                            HuAudSeqFadeOut(0x5A);
                        }
                        func_80106A3C_39BDBC_w06(D_8011E270_3B35F0_w06);
                        HuPrcSleep(30);
                        func_800EDA58_101678_shared_board();
                        func_800FF7F0_113410_shared_board(2);
                        goto exit;
                    case 1:
                        if (D_800A12D0_A1ED0 != 0) {
                            func_800039A4_45A4(D_800C9930_CA530, 60);
                            func_80003310_3F10(D_800CE198_CED98);
                            func_8004A670_4B270(0);
                            func_8004A72C_4B32C(0x5A);
                            D_800C9930_CA530 = -1;
                        }
                        MBDlgWinExec(0x16, 0x4803);
                        goto cameraRestore;
                    case 2:
                        func_80106AB0_39BE30_w06();
                        goto purchaseMenu;
                    default:
                        goto exit;
                }
            } else {
                MBDlgWinExec(0x16, 0x4801);
            }
        }

        if (D_800A12D0_A1ED0 != 0) {
            func_800039A4_45A4(D_800C9930_CA530, 60);
            func_80003310_3F10(D_800CE198_CED98);
            func_8004A670_4B270(0);
            func_8004A72C_4B32C(0x5A);
            D_800C9930_CA530 = -1;
        }

    cameraRestore:
        func_800DB884_EF4A4_shared_board(loc->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.3f));
        HuPrcChildWait();
    }

exit:
    func_8010B4B4_3A0834_w06();
}

void func_8010BBF0_3A0F70_w06(void) {
    Object *model;
    Object *effectModel;
    SpaceData *spaceA;
    SpaceData *spaceB;
    GW_SYSTEM *sys;
    Vec *vec;
    s16 mgId;
    s32 choice;
    s32 flag;
    f32 angle;
    f32 speed;
    f32 scaleK;
    f32 scaleBase;
    f32 scaleStep;
    f32 scaleLimit;
    f32 sp38;
    char sp20[0x10];
    char sp30[0x10];
    Vec sp40;

    flag = 0;
    mgId = MBMasuCurGet();
    sys = &GwSystem;
    spaceA = NULL;
    spaceB = NULL;
    if (func_800DCD9C_F09BC_shared_board(sys->current_player_index) <= 0) {
        MBPlayerVibrate(-1, 3);
    }
    MBPlayerMotionSet(-1, -1, 2);

    switch (mgId) {
        case 0x59:
            func_800ED20C_100E2C_shared_board(-1, 8, 0x8F);
            spaceA = MBMasuGet(0x8F);
            spaceB = MBMasuGet(0x59);
            break;
        case 0x22:
            func_800ED20C_100E2C_shared_board(-1, 8, 0x8E);
            spaceA = MBMasuGet(0x8E);
            spaceB = MBMasuGet(0x22);
            break;
    }

    HuPrcSleep(8);
    if (func_800DCD9C_F09BC_shared_board(sys->current_player_index) > 0) {
        func_800DBEC0_EFAE0_shared_board(sys->current_player_index);
    }
    HuAudFXPlay(0x114);

    model = MBModelCreate(0x32, NULL);
    MBModelTempAllocFree(model);
    vec = &sp40;
    HuVecSubtract(vec, &spaceB->coords, &spaceA->coords);
    MBVecNormalize(vec);
    HuVecCopy3F(&model->rot, vec);
    model->scale.y = 0.0f;
    HuVecCopy3F(&model->coords, &spaceA->coords);
    MBMotionSet(model, -1, 1);
    func_800D9A40_ED660_shared_board(model);

    effectModel = MBModelCreate(0x35, D_8011C760_3B1AE0_w06);
    MBModelTempAllocFree(effectModel);
    HuVecCopy3F(&effectModel->rot, vec);
    HuVecCopy3F(&effectModel->coords, &spaceA->coords);
    effectModel->scale.y = effectModel->scale.x = effectModel->scale.z = 1.2f;
    MBModelDispOff(effectModel);

    speed = 1.0f / HuMathSin(50.0f);
    angle = 0.0f;
    scaleK = 0.2f;
    scaleBase = 0.8f;
    scaleStep = 11.25f;
    scaleLimit = 90.0f;
    for (; angle < scaleLimit; angle += scaleStep) {
        model->scale.y = HuMathSin(angle) * speed;
        sp38 = HuMathSin(angle) * speed;
        model->scale.x = sp38 * scaleK + scaleBase;
        sp38 = HuMathSin(angle) * speed;
        model->scale.z = sp38 * scaleK + scaleBase;
        HuPrcVSleep();
    }

    if (50.0f < angle) {
        scaleK = 0.2f;
        scaleBase = 0.8f;
        scaleStep = 11.25f;
        do {
            model->scale.y = HuMathSin(angle) * speed;
            sp38 = HuMathSin(angle) * speed;
            model->scale.x = sp38 * scaleK + scaleBase;
            sp38 = HuMathSin(angle) * speed;
            model->scale.z = sp38 * scaleK + scaleBase;
            HuPrcVSleep();
            angle -= scaleStep;
        } while (50.0f < angle);
    }

    model->scale.z = model->scale.x = model->scale.y = 1.0f;
    func_800D9A40_ED660_shared_board(effectModel);

    if (MBItemFind(-1, 0xF) != -1) {
    dialogLoop:
        MBDlgWinInsertCreate(-1, 0x3A1D, 0, 0, 0, 0, 0);
        choice = func_8010B4C4_3A0844_w06((s32)D_8011C748_3B1AC8_w06, 0);
        MBDlgWinClose();
        MBDlgWinKill();
        switch (choice) {
            case 0:
                flag = 1;
                break;
            case 2:
                func_80106AB0_39BE30_w06();
                goto dialogLoop;
        }
    }

    MBMotionSet(model, -1, 0);
    func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
    while ((u16)MBMotionCheck(model) == 0) {
        HuPrcVSleep();
    }
    HuAudFXPlay(0x259);
    MBMotionSet(effectModel, 0, 0);
    while ((u16)MBMotionCheck(effectModel) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(effectModel, -1, 2);

    if (flag != 0) {
        sprintf(sp20, D_8011E14C_3B34CC_w06, GwSystem.bank_coins);
        if (GwSystem.bank_coins != 0) {
            MBDlgWinInsertCreate(2, 0x3A1E, (s32)sp20, 0, 0, 0, 0);
        } else {
            MBDlgWinInsertCreate(2, 0x3A1F, 0, 0, 0, 0, 0);
        }
        func_800EC9DC_1005FC_shared_board();
        MBDlgWinClose();
        MBDlgWinKill();

        if (GwSystem.bank_coins != 0) {
            mbItemBtnF = 0;
            func_80114338_3A96B8_w06();
            mbItemBtnF = 1;
        } else {
            MBDlgWinInsertCreate(2, 0x3A21, 0, 0, 0, 0, 0);
            func_800EC9DC_1005FC_shared_board();
            MBDlgWinClose();
            MBDlgWinKill();
            GwPlayer[sys->current_player_index].itemNo[MBItemFind(-1, 0xF)] = -1;
            MBItemRemoveEmpty(sys->current_player_index);
            MBStatusItemIconSprReinit(sys->current_player_index);
        }

        if (func_800DCD9C_F09BC_shared_board(sys->current_player_index) > 0) {
            func_800DB884_EF4A4_shared_board(sys->current_player_index);
        }
    } else {
        if (func_800DCD9C_F09BC_shared_board(sys->current_player_index) > 0) {
            if ((GwPlayer[sys->current_player_index].coin != 0) && (GwPlayer[sys->current_player_index].coin < 5)) {
                sprintf(sp20, D_8011E14C_3B34CC_w06, GwPlayer[sys->current_player_index].coin);
                sprintf(sp30, D_8011E14C_3B34CC_w06, GwSystem.bank_coins + GwPlayer[sys->current_player_index].coin);
                MBDlgWinInsertCreate(2, 0x1201, (s32)sp20, (s32)sp30, 0, 0, 0);
                MBDlgWinClose();
                GwSystem.bank_coins += GwPlayer[sys->current_player_index].coin;
                func_80107FC0_39D340_w06();
                MBCoinChangeCreate(sys->current_player_index, -GwPlayer[sys->current_player_index].coin);
                MBCoinTakeCreate(sys->current_player_index, -GwPlayer[sys->current_player_index].coin);
                HuPrcSleep(30);
                func_800EC6A8_1002C8_shared_board();
            } else if (GwPlayer[sys->current_player_index].coin == 0) {
                sprintf(sp20, D_8011E14C_3B34CC_w06, GwSystem.bank_coins);
                MBDlgWinInsertCreate(2, 0x1202, (s32)sp20, 0, 0, 0, 0);
            } else {
                sprintf(sp20, D_8011E14C_3B34CC_w06, GwSystem.bank_coins + 5);
                MBDlgWinInsertCreate(2, 0x1200, (s32)sp20, 0, 0, 0, 0);
                MBDlgWinClose();
                GwSystem.bank_coins += 5;
                func_80107FC0_39D340_w06();
                MBCoinChangeCreate(sys->current_player_index, -5);
                MBCoinTakeCreate(sys->current_player_index, -5);
                HuPrcSleep(30);
                func_800EC6A8_1002C8_shared_board();
            }
            func_800EC9DC_1005FC_shared_board();
            MBDlgWinClose();
            MBDlgWinKill();
            func_800DB884_EF4A4_shared_board(sys->current_player_index);
            HuPrcSleep(10);
        } else {
            if (GwSystem.bank_coins != 0) {
                sprintf(sp20, D_8011E14C_3B34CC_w06, GwSystem.bank_coins);
                MBDlgWinInsertCreate(2, 0x1203, (s32)sp20, 0, 0, 0, 0);
                func_800EC9DC_1005FC_shared_board();
                MBDlgWinClose();
                MBCoinChangeCreate(sys->current_player_index, GwSystem.bank_coins);
                MBCoinTakeCreate(sys->current_player_index, GwSystem.bank_coins);
                GwSystem.bank_coins = 0;
                func_80107FC0_39D340_w06();
                MBVecForwardSet(&MBPlayerGet(-1)->player_obj->rot);
                MBPlayerMotionSet(-1, 5, 0);
                func_8004ACE0_4B8E0(0x274, sys->current_player_index);
                HuPrcSleep(30);
                MBPlayerMotionSet(-1, -1, 2);
                func_800EC6A8_1002C8_shared_board();
                func_800EC9DC_1005FC_shared_board();
                MBDlgWinClose();
                MBDlgWinKill();
            } else {
                MBDlgWinExec(2, 0x1204);
            }
        }
    }

    HuAudFXPlay(0x115);
    MBMotionSet(model, -1, 4);
    func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
    func_8001C6A8_1D2A8(
        model->omObj1->model[0], D_800CCF58_CDB58[HmfModelData[model->omObj1->model[0]].unk02].unk02);
    while ((u16)func_800D9E80_EDAA0_shared_board(model) == 0) {
        HuPrcVSleep();
    }
    MBModelDispOff(effectModel);

    speed = 1.0f / HuMathSin(50.0f);
    angle = 50.0f;
    scaleK = 0.2f;
    scaleBase = 0.8f;
    scaleStep = 11.25f;
    scaleLimit = 90.0f;
    for (; angle < scaleLimit; angle += scaleStep) {
        model->scale.y = HuMathSin(angle) * speed;
        sp38 = HuMathSin(angle) * speed;
        model->scale.x = sp38 * scaleK + scaleBase;
        sp38 = HuMathSin(angle) * speed;
        model->scale.z = sp38 * scaleK + scaleBase;
        HuPrcVSleep();
    }

    angle = 90.0f;
    scaleK = 0.2f;
    scaleBase = 0.8f;
    scaleStep = 11.25f;
    scaleLimit = 0.0f;
    for (; scaleLimit < angle; angle -= scaleStep) {
        model->scale.y = HuMathSin(angle) * speed;
        sp38 = HuMathSin(angle) * speed;
        model->scale.x = sp38 * scaleK + scaleBase;
        sp38 = HuMathSin(angle) * speed;
        model->scale.z = sp38 * scaleK + scaleBase;
        HuPrcVSleep();
    }

    model->scale.y = 0;
    model->scale.x = 0;
    model->scale.z = 0;
    MBModelKill(model);
    MBModelKill(effectModel);
    func_8010B4AC_3A082C_w06();
}

s32 func_8010C724_3A1AA4_w06(s32 arg0) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (D_8011E344_3B36C4_w06[i] != 0) {
            if (D_8011C790_3B1B10_w06[D_8011E33C_3B36BC_w06][D_8011E340_3B36C0_w06][i] == arg0) {
                return i;
            }
        }
    }
    return -1;
}

s32 func_8010C7AC_3A1B2C_w06(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (D_8011C790_3B1B10_w06[D_8011E33C_3B36BC_w06][D_8011E340_3B36C0_w06][i] == -1) {
            break;
        }
    }
    return i;
}

void func_8010C814_3A1B94_w06(void) {
    s32 grp = (s32)HuPrcCurrentGet()->user_data;
    f32 angle;
    f32 scaleX;

    MBPlayerGet(GwSystem.current_player_index);
    MBPlayerVibrate(-1, 2);
    HuAudFXPlay(0x15A);

    for (angle = 0.0f; angle < 180.0f; angle += 20.0f) {
        scaleX = HuMathSin(angle) * 1.5f + 1.0f;
        HuSprScaleSet(grp, 0, scaleX, 1.0f - HuMathSin(angle) * 0.5f);
        HuPrcVSleep();
    }

    for (; angle < 360.0f; angle += 20.0f) {
        scaleX = HuMathSin(angle) * 0.5f + 1.0f;
        HuSprScaleSet(grp, 0, scaleX, 1.0f - HuMathSin(angle) * 0.25f);
        HuPrcVSleep();
    }

    HuSprScaleSet(grp, 0, 1.0f, 1.0f);
    omDelPrcObj(NULL);
}

void func_8010C9EC_3A1D6C_w06(void) {
    s8 *currentPlayerField = &GwSystem.current_player_index;
    SpaceData *spaceA;
    SpaceData *spaceB;
    Object *model;
    Object *playerObj;
    Unk3 *helpWin;
    void *data;
    Process *prc;
    u8 enabled[9];
    u8 itemFlags[6][4];
    Vec sp48;
    s32 dlgWin;
    s16 shopIdx;
    s32 flag2;
    s32 id;
    s32 slot;
    s32 row;
    s32 row2;
    s32 sel;
    s32 choice;
    s32 count;
    s32 item;
    s8 *itemPtr;
    s8(*shopTable)[35];
    s8 *shopItems;
    s32 timer;
    s32 randVal;
    s32 i;
    s32 j;
    s32 grp;
    s32 grp2;
    s16 spriteId;
    s32 spriteId2;
    s16 sprY;
    s16 masuId;
    s16 camMasu;
    GW_PLAYER *player;
    Object *effectModel;
    f32 angle;
    f32 speed;
    f32 scaleK;
    f32 scaleBase;
    f32 scaleStep;
    f32 scaleLimit;
    f32 sp38;
    f32 scale;
    player = MBPlayerGet(-1);
    spaceA = NULL;
    spaceB = NULL;
    model = NULL;
    effectModel = NULL;
    MBPlayerMotionSet(-1, -1, 2);

    masuId = MBMasuLinkMasuIdGet(player->clink, player->cidx);
    switch (masuId) {
        case 0x6C:
            camMasu = 0x90;
            spaceA = MBMasuGet(0x90);
            spaceB = MBMasuGet(0x6C);
            D_8011C8C8_3B1C48_w06 = 0;
            break;
        case 0x79:
            camMasu = 0x8C;
            spaceA = MBMasuGet(0x8C);
            spaceB = MBMasuGet(0x79);
            D_8011C8C8_3B1C48_w06 = 1;
            break;
        default:
            camMasu = -1;
            break;
    }

    if (camMasu != -1) {
        func_800ED20C_100E2C_shared_board(-1, 8, camMasu);
        HuPrcSleep(8);
    }
    func_800DBEC0_EFAE0_shared_board(*currentPlayerField);

    switch (GwSystem.forceShopHost) {
        case 0:
            shopIdx = !MBRandCheck100(0x42);
            break;
        case 1:
            shopIdx = 0;
            break;
        default:
            shopIdx = 1;
            break;
    }

    dlgWin = 3;
    if (shopIdx != 0) {
        dlgWin = 5;
    }

    if (camMasu != -1) {
        flag2 = (shopIdx << 1) >> 1;
        id = (-shopIdx & 0x31) | 0x30;
        HuAudFXPlay(0x114);
        model = MBModelCreate(id, NULL);
        MBModelTempAllocFree(model);
        HuVecSubtract(&sp48, &spaceB->coords, &spaceA->coords);
        MBVecNormalize(&sp48);
        HuVecCopy3F(&model->rot, &sp48);
        model->scale.y = 0.0f;
        MBMotionSet(model, -1, 1);
        func_800D9A40_ED660_shared_board(model);
        HuVecCopy3F(&model->coords, &spaceA->coords);

        if (flag2 != 0) {
            effectModel = MBModelCreate(0x39, D_8011C8C0_3B1C40_w06);
        } else {
            effectModel = MBModelCreate(0x1B, D_8011C8B8_3B1C38_w06);
        }
        MBModelTempAllocFree(effectModel);
        HuVecCopy3F(&effectModel->rot, &sp48);
        HuVecCopy3F(&effectModel->coords, &spaceA->coords);
        effectModel->scale.y = effectModel->scale.x = effectModel->scale.z = 1.2f;
        MBModelDispOff(effectModel);

        speed = 1.0f / HuMathSin(50.0f);
        angle = 0.0f;
        scaleK = 0.2f;
        scaleBase = 0.8f;
        scaleStep = 11.25f;
        scaleLimit = 90.0f;
        for (; angle < scaleLimit; angle += scaleStep) {
            model->scale.y = HuMathSin(angle) * speed;
            sp38 = HuMathSin(angle) * speed;
            model->scale.x = sp38 * scaleK + scaleBase;
            sp38 = HuMathSin(angle) * speed;
            model->scale.z = sp38 * scaleK + scaleBase;
            HuPrcVSleep();
        }

        if (50.0f < angle) {
            scaleK = 0.2f;
            scaleBase = 0.8f;
            scaleStep = 11.25f;
            do {
                model->scale.y = HuMathSin(angle) * speed;
                sp38 = HuMathSin(angle) * speed;
                model->scale.x = sp38 * scaleK + scaleBase;
                sp38 = HuMathSin(angle) * speed;
                model->scale.z = sp38 * scaleK + scaleBase;
                HuPrcVSleep();
                angle -= scaleStep;
            } while (50.0f < angle);
        }

        model->scale.y = model->scale.x = model->scale.z = 1.0f;
        func_800D9A40_ED660_shared_board(effectModel);
        MBMotionSet(model, -1, 0);
        func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
        while ((u16)MBMotionCheck(model) == 0) {
            HuPrcVSleep();
        }
        MBMotionSet(effectModel, 0, 0);

        if (shopIdx != 0) {
            HuAudFXPlay(0x2A0);
        } else {
            if (GwPlayer[*currentPlayerField].coin < 5 || MBItemFindEmpty(*currentPlayerField) == -1) {
                HuAudFXPlay(0x29A);
            } else if (W06CurrentTurnGet() != W06TotalTurnsGet()) {
                HuAudFXPlay(0x298);
            } else {
                HuAudFXPlay(0x29A);
            }
        }

        while ((u16)MBMotionCheck(effectModel) == 0) {
            HuPrcVSleep();
        }
        MBMotionSet(effectModel, -1, 2);
    }

    if (W06CurrentTurnGet() == W06TotalTurnsGet()) {
        MBDlgWinExec(dlgWin, D_8011C8A8_3B1C28_w06[shopIdx]);
        goto end;
    }
    if (MBItemFindEmpty(*currentPlayerField) == -1) {
        MBDlgWinExec(dlgWin, D_8011C8A0_3B1C20_w06[shopIdx]);
        goto end;
    }
    if (GwPlayer[*currentPlayerField].coin < 5) {
        MBDlgWinExec(dlgWin, D_8011C898_3B1C18_w06[shopIdx]);
        goto end;
    }

itemSelect:
    MBDlgWinCreate(dlgWin, D_8011C890_3B1C10_w06[shopIdx]);
    choice = func_80106F58_39C2D8_w06();
    MBDlgWinClose();
    MBDlgWinKill();

    switch (choice) {
        case 0:

        restart:
            i = BoardGetTurnTier(-1);
            row = D_8011C778_3B1AF8_w06[shopIdx][i][BoardPlayerRankCalc(*currentPlayerField)];
            count = 0;
            for (j = 0; j < 7; j++) {
                if (D_8011C790_3B1B10_w06[shopIdx][row][j] == -1) {
                    continue;
                }
                if (D_8011C790_3B1B10_w06[shopIdx][row][j] >= 6) {
                    break;
                }
                enabled[j] = 1;
                count++;
            }
            i = 0;
            for (; j < 7; j++, i++) {
                enabled[j] = 1;
                itemFlags[i][0] = 0;
                if (D_8011C790_3B1B10_w06[shopIdx][row][j] == -1) {
                    continue;
                }
                if (D_80100F94_114BB4_shared_board[D_8011C790_3B1B10_w06[shopIdx][row][j]] >
                    GwPlayer[*currentPlayerField].coin) {
                    enabled[j] = 0;
                    itemFlags[i][0] = 1;
                }
                itemFlags[i][1] = 0;
                count++;
            }
            if (j < 9) {
                for (; j < 9; j++) {
                    enabled[j] = 1;
                }
            }

            MBDlgWinInsertCreate(dlgWin, D_8011C868_3B1BE8_w06[row][slot = shopIdx], (s32)itemFlags[0],
                                 (s32)itemFlags[1], (s32)itemFlags[2], (s32)itemFlags[3], (s32)itemFlags[4]);
            func_800ECAA8_1006C8_shared_board(0);
            D_8011E33C_3B36BC_w06 = slot;
            D_8011E340_3B36C0_w06 = row;
            D_8011E344_3B36C4_w06 = enabled;
            sel = func_80106CC4_39C044_w06(enabled);
            MBDlgWinClose();
            MBDlgWinKill();

            if (sel == count) {
                mbItemBtnF = 0;
                MBItemSelNoClear();
                MBItemDescExec(*currentPlayerField);
                mbItemBtnF = 1;
                goto restart;
            }
            if (sel == count + 1 || sel == -1) {
                goto itemSelect;
            }

            playerObj = player->player_obj;
            i = shopIdx;
            shopTable = (s8(*)[35])D_8011C790_3B1B10_w06;
            shopItems = shopTable[i];
            itemPtr = (s8 *)(row * 7);
            itemPtr += (s32)shopItems;
            itemPtr += sel;
            MBCoinChangeCreate(*currentPlayerField, -D_80100F94_114BB4_shared_board[*itemPtr]);
            MBCoinTakeCreate(*currentPlayerField, -D_80100F94_114BB4_shared_board[*itemPtr]);
            HuPrcSleep(30);

            if (*itemPtr == 0x13) {
                item = i + 0x13;
            } else {
                GwPlayer[*currentPlayerField].itemNo[MBItemFindEmpty(*currentPlayerField)] =
                    D_8011C790_3B1B10_w06[shopIdx][row][sel];
                item = D_8011C790_3B1B10_w06[shopIdx][row][sel];
            }

            grp = HuSprGrpCreate(1, 5);
            i = 0;
            data = DataRead(D_8010197C_11559C_shared_board[item]);
            spriteId = func_80055810_56410(data);
            DataClose(data);
            func_80055024_55C24(grp, 0, spriteId, 0);
            HuSprPriSet(grp, 0, 0xA);
            func_800550F4_55CF4(grp, 0, 0);
            HuSprAttrSet(grp, 0, 0x180C);
            func_80054904_55504(grp, 0, 0xA0, 0x5A);
            func_80055458_56058(grp, 0, 0);
            MBVecForwardSet(&sp48);
            func_800ED128_100D48_shared_board(&player->player_obj->rot, &sp48, &player->player_obj->rot, 0xA);
            HuAudFXPlay(0x19);
            for (; i < 10; i++) {
                func_80055458_56058(grp, 0, i * 25);
                HuPrcVSleep();
            }
            func_80055458_56058(grp, 0, 0x100);

            if (D_8011C790_3B1B10_w06[shopIdx][row][sel] == 0x13) {
                while (MBItemFindEmpty(*currentPlayerField) != -1) {
                    row2 = D_8011C7D8_3B1B58_w06[shopIdx][BoardGetTurnTier(-1)]
                                                [BoardPlayerRankCalc(*currentPlayerField)];
                    randVal = MBRand(100.0f);
                    for (i = 0; i < 10; i++) {
                        if (randVal < D_8011C7F0_3B1B70_w06[shopIdx][row2][i]) {
                            break;
                        }
                    }
                    item = D_8011C854_3B1BD4_w06[shopIdx][i];

                    if (camMasu != -1) {
                        helpWin = func_800E210C_F5D2C_shared_board(0x15, 0xA0, 1);
                    } else {
                        playerObj->flags |= 0x10;
                        helpWin = func_800E210C_F5D2C_shared_board(0x15, 0xA0, 0);
                    }
                    timer = 30;

                    if ((*(u16 *)((u8 *)D_800C9520_CA120 + (GwPlayer[*currentPlayerField].pad << 1)) & 0x8000) == 0) {
                        row = (s32)D_800C9520_CA120;
                        while (1) {
                            if (MBPlayerComCheck(-1) != 0) {
                                timer--;
                                if (timer == -1) {
                                    break;
                                }
                            }
                            HuPrcVSleep();
                            if (((u16 *)row)[GwPlayer[*currentPlayerField].pad] & 0x8000) {
                                break;
                            }
                        }
                    }
                    MBHelpWinKill(helpWin);

                    MBPlayerMotionSet(*currentPlayerField, 2, 0);
                    func_800EE688_1022A8_shared_board(playerObj, 2.0f, -0.3f);
                    HuPrcSleep(5);
                    prc = omAddPrcObj(func_8010C814_3A1B94_w06, 0x4002, 0, 0);
                    prc->user_data = (void *)grp;
                    func_800EE6C0_1022E0_shared_board(playerObj);
                    MBPlayerMotionSet(-1, -1, 2);

                    grp2 = HuSprGrpCreate(1, 5);
                    i = 0;
                    data = DataRead(D_8010197C_11559C_shared_board[item]);
                    spriteId2 = func_80055810_56410(data);
                    DataClose(data);
                    func_80055024_55C24(grp2, 0, spriteId2, 0);
                    HuSprPriSet(grp2, 0, 0xB);
                    func_800550F4_55CF4(grp2, 0, 0);
                    HuSprAttrSet(grp2, 0, 0x1000);
                    func_80054904_55504(grp2, 0, 0xA0, 0x5A);
                    func_80055458_56058(grp2, 0, 0);
                    MBVecForwardSet(&sp48);
                    func_800ED128_100D48_shared_board(&player->player_obj->rot, &sp48, &player->player_obj->rot, 0xA);

                    sprY = 0x5A;
                    scale = 0.0f;
                    do {
                        func_80054904_55504(grp2, 0, 0xA0, sprY);
                        func_80055458_56058(grp2, 0, i * 25);
                        HuSprScaleSet(grp2, 0, scale, scale);
                        i++;
                        HuPrcVSleep();
                        sprY -= 3;
                        scale += 0.1f;
                    } while (i < 10);
                    HuSprScaleSet(grp2, 0, 1.0f, 1.0f);
                    func_80055458_56058(grp2, 0, 0x100);
                    HuPrcSleep(10);
                    GwPlayer[*currentPlayerField].itemNo[MBItemFindEmpty(*currentPlayerField)] = item;
                    HuSprGrpKill(grp2);
                    HuSprKill(spriteId2);
                }
                if (camMasu == -1) {
                    playerObj->flags &= ~0x10;
                }
            }

            HuPrcSleep(5);
            MBPlayerMotionSet(-1, 5, 0);
            HuPrcSleep(5);
            func_8004ACE0_4B8E0(0x274, *currentPlayerField);
            HuPrcSleep(20);
            HuPrcVSleep();
            func_800F2388_105FA8_shared_board(-1, -1, 0, 5, 2);
            HuPrcSleep(10);
            HuSprGrpKill(grp);
            HuSprKill(spriteId);
            break;
        case 1:
            MBDlgWinExec(dlgWin, D_8011C8B0_3B1C30_w06[shopIdx]);
            break;
        case 2:
            if (camMasu == -1) {
                func_80106B38_39BEB8_w06();
                D_800CB99C_CC59C = 1;
                func_80049FB8_4ABB8();
            } else {
                func_80106AB0_39BE30_w06();
            }
            goto itemSelect;
    }

end:
    if (camMasu != -1) {
        HuAudFXPlay(0x115);
        MBMotionSet(model, -1, 4);
        func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
        func_8001C6A8_1D2A8(
            model->omObj1->model[0], D_800CCF58_CDB58[HmfModelData[model->omObj1->model[0]].unk02].unk02);
        while ((u16)func_800D9E80_EDAA0_shared_board(model) == 0) {
            HuPrcVSleep();
        }
        MBModelDispOff(effectModel);

        speed = 1.0f / HuMathSin(50.0f);
        angle = 50.0f;
        scaleK = 0.2f;
        scaleBase = 0.8f;
        scaleStep = 11.25f;
        scaleLimit = 90.0f;
        for (; angle < scaleLimit; angle += scaleStep) {
            model->scale.y = HuMathSin(angle) * speed;
            sp38 = HuMathSin(angle) * speed;
            model->scale.x = sp38 * scaleK + scaleBase;
            sp38 = HuMathSin(angle) * speed;
            model->scale.z = sp38 * scaleK + scaleBase;
            HuPrcVSleep();
        }

        angle = 90.0f;
        scaleK = 0.2f;
        scaleBase = 0.8f;
        scaleStep = 11.25f;
        scaleLimit = 0.0f;
        for (; scaleLimit < angle; angle -= scaleStep) {
            model->scale.y = HuMathSin(angle) * speed;
            sp38 = HuMathSin(angle) * speed;
            model->scale.x = sp38 * scaleK + scaleBase;
            sp38 = HuMathSin(angle) * speed;
            model->scale.z = sp38 * scaleK + scaleBase;
            HuPrcVSleep();
        }

        model->scale.y = 0;
        model->scale.x = 0;
        model->scale.z = 0;
        MBModelKill(model);
        MBModelKill(effectModel);
    }
    func_800DB884_EF4A4_shared_board(*currentPlayerField);
    HuPrcSleep(10);
}

void func_8010DCA4_3A3024_w06(Object *obj) {
    s32 i;

    MBModelDispOn(obj);
    for (i = 0; i < 0x100; i += 0xC) {
        func_8001F9E4_205E4(obj->omObj1->model[0], i);
        func_8001F9E4_205E4(obj->omObj2->model[0], i);
        HuPrcVSleep();
    }
    func_8001F9E4_205E4(obj->omObj1->model[0], 0xFF);
    func_8001F9E4_205E4(obj->omObj2->model[0], 0xFF);
}

void func_8010DD44_3A30C4_w06(Object *obj) {
    s32 i;

    for (i = 0xFF; i >= 0; i -= 0xC) {
        func_8001F9E4_205E4(obj->omObj1->model[0], i);
        func_8001F9E4_205E4(obj->omObj2->model[0], i);
        HuPrcVSleep();
    }
    func_8001F9E4_205E4(obj->omObj1->model[0], 0);
    func_8001F9E4_205E4(obj->omObj2->model[0], 0);
    MBModelDispOff(obj);
}

s32 func_8010DDE4_3A3164_w06(s32 playerIndex) {
    s32 hasRareItem = 0;
    s16 grp;
    void *data;
    s16 spriteId;
    s32 i;
    s32 duration;
    Process *process;

    grp = HuSprGrpCreate(1, 5);
    data = DataRead(0x13020E);
    spriteId = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(grp, 0, spriteId, 0);
    HuSprPriSet(grp, 0, 0xA);
    func_800550F4_55CF4(grp, 0, 0);
    HuSprAttrSet(grp, 0, 0x1000);
    func_80054904_55504(grp, 0, D_8011C8DC_3B1C5C_w06[playerIndex].x,
                        D_8011C8DC_3B1C5C_w06[playerIndex].y);
    func_80055458_56058(grp, 0, 0);
    HuAudFXPlay(0x134);

    for (i = 0; i < 0x11; i++) {
        func_80054904_55504(grp, 0,
                            (i * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].x,
                            (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].y);
        func_80055458_56058(grp, 0, i << 4);
        HuPrcVSleep();
    }
    func_80055458_56058(grp, 0, 0xFF);

    if (MBItemFind(playerIndex, 0xC) != -1) {
        hasRareItem = 1;
        process = omAddPrcObj(func_80113B68_3A8EE8_w06, 0x4002, 0, 0);
        process->user_data = (void *)playerIndex;
    }

    if (!hasRareItem) {
        GwPlayer[playerIndex].star--;
    }
    MBPlayerVibrate(playerIndex, 5);
    HuAudFXPlay(0x257);

    duration = hasRareItem ? 0x78 : 0x1E;
    for (i = 0; i < duration; i++) {
        func_80054904_55504(grp, 0,
                            (D_8011C8FC_3B1C7C_w06[playerIndex].x * 16.0f) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].x,
                            (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].y +
                                (HuMathSin(i * 90) * 4.0f));
        HuPrcVSleep();
    }

    for (i = 0x10; i >= 0; i--) {
        func_80054904_55504(grp, 0,
                            (i * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].x,
                            (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].y);
        func_80055458_56058(grp, 0, i << 4);
        HuPrcVSleep();
    }
    HuSprGrpKill(grp);
    HuSprKill(spriteId);
    return !hasRareItem;
}

void func_8010E22C_3A35AC_w06(void) {
    func_800EC3E4_100004_shared_board();
    omDelPrcObj(NULL);
}

s32 func_8010E250_3A35D0_w06(s32 playerIndex) {
    s32 hasRareItem;
    s16 grp;
    void *data;
    s16 spriteId;
    s16 playerGrp;
    s16 playerSpriteId;
    s32 i;
    s32 state;
    s32 playerSpriteVisible;
    s16 delay;
    s32 angle;
    s32 attempts;
    void *dialog;
    Process *process;

    hasRareItem = 0;
    grp = HuSprGrpCreate(1, 5);
    data = DataRead(0x13020E);
    spriteId = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(grp, 0, spriteId, 0);
    HuSprPriSet(grp, 0, 0xA);
    func_800550F4_55CF4(grp, 0, 0);
    HuSprAttrSet(grp, 0, 0x1000);
    func_80054904_55504(grp, 0, D_8011C8DC_3B1C5C_w06[playerIndex].x,
                        D_8011C8DC_3B1C5C_w06[playerIndex].y);
    func_80055458_56058(grp, 0, 0);

    {
        playerGrp = HuSprGrpCreate(1, 5);
        playerSpriteVisible = 0;
        data = DataRead(D_80101040_114C60_shared_board[GwPlayer[playerIndex].chr]);
        playerSpriteId = func_80055810_56410(data);
        DataClose(data);
        func_80055024_55C24(playerGrp, 0, playerSpriteId, 0);
        HuSprPriSet(playerGrp, 0, 0xA);
        func_800550F4_55CF4(playerGrp, 0, 1);
        if (playerIndex & 1) {
            HuSprAttrSet(playerGrp, 0, 0x1001);
        } else {
            HuSprAttrSet(playerGrp, 0, 0x1000);
        }
        if (MBItemFind(playerIndex, 0xC) != -1) {
            HuSprAttrSet(playerGrp, 0, 0x8000);
        }
        func_80054904_55504(playerGrp, 0,
                            D_8011C8DC_3B1C5C_w06[playerIndex].x -
                                (D_8011C8FC_3B1C7C_w06[playerIndex].x * 16.0f) - 8.0f,
                            D_8011C8DC_3B1C5C_w06[playerIndex].y +
                                (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f));
        func_80055458_56058(playerGrp, 0, 0);
        HuAudFXPlay(0x133);

        for (i = 0; i < 0x11; i++) {
            func_80054904_55504(grp, 0,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].x,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].y);
            func_80055458_56058(grp, 0, i << 4);
            func_80055458_56058(playerGrp, 0, i << 4);
            HuPrcVSleep();
        }
        func_80055458_56058(grp, 0, 0xFF);
        func_80055458_56058(playerGrp, 0, 0xFF);

        MBWinInsertOpen(MBItemFind(playerIndex, 0xC) == -1 ? 0x620E : 0x620F,
                        (char *)mbCharNameMesTbl[GwPlayer[playerIndex].chr], 0, 0, 0, 0);
        MBPlayerVibrate(playerIndex, 2);
        func_800EC3C0_FFFE0_shared_board(playerIndex);
        if (MBItemFind(playerIndex, 0xC) != -1) {
            omAddPrcObj(func_8010E22C_3A35AC_w06, 0x1000, 0, 0);
            HuPrcSleep(0x14);
        }

        attempts = 0;
        state = 0;
        if (MBItemFind(playerIndex, 0xC) != -1) {
            attempts = 1;
            hasRareItem = 1;
            process = omAddPrcObj(func_80113B68_3A8EE8_w06, 0x4002, 0, 0);
            process->user_data = (void *)playerIndex;
        }
        HuAudFXPlay(0x133);
        dialog = MBPlayerVibrateObjCreate((s16)playerIndex, 3, 5);
        delay = MBRand(10.0f) + 1;
        i = 0;
        angle = 0;

        for (; i < 0x78; i++, delay--) {
            if (delay == 0) {
                HuAudFXPlay(0x257);
                delay = MBRand(15.0f) + 0x1E;
            }
            state -= !(state < 2);
            if (state == 0) {
                func_80054904_55504(
                    grp, 0,
                    (D_8011C8FC_3B1C7C_w06[playerIndex].x * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].x,
                    (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].y + (HuMathSin(i * 90) * 2.0f));
            } else if (state == 9) {
                func_80054904_55504(
                    grp, 0,
                    (D_8011C8FC_3B1C7C_w06[playerIndex].x * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].x + (HuMathSin(angle * 90) * 2.0f),
                    (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].y);
                func_80054904_55504(
                    playerGrp, 0,
                    D_8011C8DC_3B1C5C_w06[playerIndex].x - 8.0f +
                        (HuMathSin(angle * 90) * 2.0f),
                    (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].y);
                angle++;
            }

            if (GwPlayer[playerIndex].stat & 1) {
                if (state == 0) {
                    goto tryInput;
                } else {
                    if (GwPlayer[playerIndex].cpu_difficulty == 0) {
                        if ((6 - MBRand(3.0f)) >= state) {
                            goto tryInput;
                        }
                    } else if (GwPlayer[playerIndex].cpu_difficulty == 1) {
                        if ((7 - MBRand(3.0f)) >= state) {
                            goto tryInput;
                        }
                    } else if (GwPlayer[playerIndex].cpu_difficulty == 2) {
                        if ((8 - MBRand(3.0f)) >= state) {
                            goto tryInput;
                        }
                    } else if ((9 - MBRand(2.0f)) >= state) {
                        goto tryInput;
                    }
                }
            } else if (D_800C9520_CA120[GwPlayer[playerIndex].pad] & 0x8000) {
            tryInput:
                if (!hasRareItem) {
                    attempts++;
                    state = 10;
                    if (!playerSpriteVisible) {
                        func_80055140_55D40(playerGrp, 0, 1, 0);
                        func_800550F4_55CF4(playerGrp, 0, 1);
                        playerSpriteVisible = 1;
                        func_80054904_55504(
                            playerGrp, 0, D_8011C8DC_3B1C5C_w06[playerIndex].x - 8.0f,
                            (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                                D_8011C8DC_3B1C5C_w06[playerIndex].y);
                    }
                }
            }
            if ((state == 0) && (playerSpriteVisible == 1)) {
                func_80055140_55D40(playerGrp, 0, 0, 0);
                func_800550F4_55CF4(playerGrp, 0, 1);
                playerSpriteVisible = 0;
                func_80054904_55504(
                    playerGrp, 0,
                    D_8011C8DC_3B1C5C_w06[playerIndex].x -
                        (D_8011C8FC_3B1C7C_w06[playerIndex].x * 16.0f) - 8.0f,
                    (D_8011C8FC_3B1C7C_w06[playerIndex].y * 16.0f) +
                        D_8011C8DC_3B1C5C_w06[playerIndex].y);
            }
            HuPrcVSleep();
        }
    }

    MBPlayerVibrateObjKill(dialog);
    if (!hasRareItem) {
        omAddPrcObj(func_8010E22C_3A35AC_w06, 0x1000, 0, 0);
    }

    if (attempts == 0) {
        for (i = 0x10; i >= 0; i -= 2) {
            func_80054904_55504(grp, 0,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].x,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].y);
            func_80055458_56058(grp, 0, i << 4);
            func_80055458_56058(playerGrp, 0, i << 4);
            HuPrcVSleep();
        }
    } else {
        for (i = 0x10; i >= -0x10; i -= 2) {
            func_80054904_55504(grp, 0,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].x,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].y);
            func_80054904_55504(playerGrp, 0,
                                ((i - 0x10) * D_8011C8FC_3B1C7C_w06[playerIndex].x) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].x - 8.0f,
                                (i * D_8011C8FC_3B1C7C_w06[playerIndex].y) +
                                    D_8011C8DC_3B1C5C_w06[playerIndex].y);
            if (hasRareItem) {
                i -= 2;
            }
            HuPrcVSleep();
        }
        func_80055140_55D40(playerGrp, 0, 0, 0);
        func_800550F4_55CF4(playerGrp, 0, 1);
        for (i = 0x10; i >= 0; i -= 2) {
            func_80055458_56058(grp, 0, i << 4);
            HuPrcVSleep();
        }
    }

    HuSprGrpKill(grp);
    HuSprKill(spriteId);
    HuSprGrpKill(playerGrp);
    HuSprKill(playerSpriteId);

    playerSpriteVisible = -2;
    if (!hasRareItem) {
        for (i = 0; (u32)i < 6; i++) {
            if ((GwSystem.current_turn >= D_8011C91C_3B1C9C_w06[i][0]) &&
                (GwSystem.current_turn <= D_8011C91C_3B1C9C_w06[i][1])) {
                break;
            }
        }
        playerSpriteVisible = D_8011C91C_3B1C9C_w06[i][2];
        for (i = 0; (u32)i < 14; i++) {
            if ((attempts >= D_8011C930_3B1CB0_w06[i][0]) &&
                (attempts <= D_8011C930_3B1CB0_w06[i][1])) {
                break;
            }
        }
        playerSpriteVisible -= D_8011C930_3B1CB0_w06[i][2];
        if (playerSpriteVisible >= GwPlayer[playerIndex].coin) {
            playerSpriteVisible = -1;
        }
    }
    return playerSpriteVisible;
}

const StarMasuTable D_8011E0F0_3B3470_w06 = { { { 0, 0x6E }, { 0, 0x6F }, { 0, 0x98 }, { 0, 0x6D } } };

const StarDelayTable D_8011E100_3B3480_w06 = { { 2, 4, 4, 4, 8, 8, 8, 8, 8, 8 } };

const ChanceTable D_8011E10C_3B348C_w06 = { { 50, 70, 90, 100 } };

const ChanceTable D_8011E11C_3B349C_w06 = { { 10, 7, 3, 0 } };

const ChanceTable D_8011E12C_3B34AC_w06 = { { 4, 3, 2, 5 } };

const ChanceTable D_8011E13C_3B34BC_w06 = { { 0, 0, 13, 0 } };

const char D_8011E14C_3B34CC_w06[] = "%d";

void func_8010F07C_3A43FC_w06(void) {
    Object *src = HuPrcCurrentGet()->user_data;
    Object *obj = MBModelLinkCreate(D_8011E348_3B36C8_w06);
    f32 angle;

    HuVecCopy3F(&obj->coords, &src->coords);
    HuVecCopyXYZ(&obj->scale, 2.0f, 2.0f, 2.0f);
    obj->velocity.x = src->velocity.x + 10.0f;
    MBModelDispOn(obj);
    angle = MBRand(360.0f);
    while (1) {
        HuPrcVSleep();
        obj->velocity.x += 1.5;
        if (src->velocity.x + 35.0f <= obj->velocity.x) {
            break;
        }
        angle += 40.0f;
        func_8008A2A0_8AEA0(HmfModelData[obj->omObj1->model[0]].mtx, angle);
    }
    MBModelKill(obj);
    omDelPrcObj(NULL);
}

void func_8010F1D0_3A4550_w06(s32 arg) {
    Process *temp = omAddPrcObj(func_8010F07C_3A43FC_w06, 0x1000, 0, 0);

    temp->user_data = (void *)arg;
}

void func_8010F20C_3A458C_w06(void) {
    char inserts[4][16];
    u8 choices[8];
    Vec direction;
    s32 rankedPlayers[3];
    Object *model = NULL;
    SpaceData *space;
    Vec *spaceCoords;
    GW_PLAYER *player;
    GW_SYSTEM *sys;
    Process *process;
    void *coinEffect;
    s32 resultAmount;
    s32 selectedByCpu;
    s16 target;
    s32 menuResult;
    s32 playerChoice;
    s32 rank;
    s32 count;
    s32 i;
    s32 j;
    s32 amountDifference;
    s16 spaceId;
    f32 angle;
    f32 scale;
    f32 rate;
    f32 booVelocity;
    Object *boo;
    s32 modelIsLinked;
    s32 estimatedAmount;
    s16 camMasu;
    s16 menu;
    s32 cameraSet;

    resultAmount = 0;
    estimatedAmount = resultAmount;
    MBMasuCurGet();
    sys = &GwSystem;
    player = MBPlayerGet(-1);
    cameraSet = func_800DBEC0_EFAE0_shared_board(W06CurrentPlayerIndexGet());
    MBPlayerMotionSet(-1, -1, 2);
    menu = 0;
    spaceId = MBMasuLinkMasuIdGet((s8)player->clink, (s8)player->cidx);
    if (spaceId != 0x7F) {
        modelIsLinked = -1;
        camMasu = -1;
        boo = MBModelLinkCreate(D_8011E2DC_3B365C_w06);
        MBModelDispOff(boo);
        booVelocity = 30.0f;
        boo->velocity.x = booVelocity;
        space = MBMasuGet(spaceId);
        HuVecCopyXYZ(&boo->coords, space->coords.x, space->coords.y + 10.0f, space->coords.z);
    } else {
        modelIsLinked = 0;
        camMasu = 0x80;
        space = MBMasuGet(0x80);
        boo = D_8011E2E0_3B3660_w06[0];
        HuAudFXPlay(0x125);
        model = MBModelCreate(0x33, NULL);
        if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
            func_8001ED54_1F954(model->omObj1->model[0]);
        }
        func_8001C448_1D048(model->omObj1->model[0]);
        MBModelTempAllocFree(model);
        spaceCoords = &space->coords;
        HuVecSubtract(&direction, &MBMasuGet(spaceId)->coords, spaceCoords);
        MBVecNormalize(&direction);
        HuVecCopy3F(&model->rot, &direction);
        model->scale.y = 0.0f;
        HuVecCopy3F(&model->coords, spaceCoords);
        MBMotionSet(model, -1, 1);
        MBModelDispOn(model);
        scale = 1.0f / HuMathSin(50.0f);
        for (angle = 0.0f; angle < 90.0f; angle += 11.25f) {
            model->scale.y = HuMathSin(angle) * scale;
            model->scale.x = HuMathSin(angle) * scale * 0.99f + 0.01f;
            model->scale.z = HuMathSin(angle) * scale * 0.99f + 0.01f;
            if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
                model->scale.x = -model->scale.x;
            }
            HuPrcVSleep();
        }
        for (; angle > 50.0f; angle -= 11.25f) {
            model->scale.y = HuMathSin(angle) * scale;
            model->scale.x = HuMathSin(angle) * scale * 0.99f + 0.01f;
            model->scale.z = HuMathSin(angle) * scale * 0.99f + 0.01f;
            if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
                model->scale.x = -model->scale.x;
            }
            HuPrcVSleep();
        }
        model->scale.y = 1.0f;
        model->scale.x = 1.0f;
        model->scale.z = 1.0f;
        if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
            model->scale.x = -1.0f;
        }
        MBMotionSet(model, -1, 0);
        func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
        while ((u16)MBMotionCheck(model) == 0) {
            HuPrcVSleep();
        }
    }
    HuAudFXPlay(0x257);
    func_8010DCA4_3A3024_w06(boo);
    space = MBMasuGet(spaceId);
    spaceId = (s16)camMasu;
    if (spaceId != -1) {
        func_800D9F5C_C1D2C_name_81(boo, &space->coords, 5);
        func_800ED20C_100E2C_shared_board(-1, 5, spaceId);
        HuPrcSleep(5);
        process = HuPrcCurrentGet();
        HuPrcChildLink(process, MBCameraZoomMotStart(1.6f));
        HuPrcChildWait();
    }

    if (GwPlayer[sys->current_player_index].coin < 5) {
        MBDlgWinExec(7, 0x6201);
        goto finishMenu;
    }

restartMenu:
    for (i = 0; i < 4; i++) {
        if (i != sys->current_player_index &&
            (GwPlayer[i].coin != 0 || GwPlayer[i].star != 0)) {
            break;
        }
    }
    if (i >= 4) {
        MBDlgWinExec(7, 0x6202);
        goto finishMenu;
    }
    for (i = 0; i < 4; i++) {
        if (i != sys->current_player_index && GwPlayer[i].coin != 0) {
            break;
        }
    }
    if (i == 4) {
        inserts[0][0] = 1;
        choices[0] = 0;
    } else {
        inserts[0][0] = 8;
        choices[0] = 1;
    }
    inserts[0][1] = 0;
    for (i = 0; i < 4; i++) {
        if (i != sys->current_player_index && GwPlayer[i].star != 0) {
            break;
        }
    }
    if (i == 4) {
        goto starChoiceUnavailable;
    }
    if (GwPlayer[sys->current_player_index].coin < 50) {
        goto starChoiceUnavailable;
    }
    if (GwPlayer[sys->current_player_index].star < 99) {
        goto starChoiceAvailable;
    }

starChoiceUnavailable: {
    inserts[1][0] = 1;
    choices[1] = 0;
    goto starChoiceDone;
}

starChoiceAvailable: {
    inserts[1][0] = 8;
    choices[1] = 1;
}

starChoiceDone:
    inserts[1][1] = 0;
    choices[3] = 1;
    choices[2] = 1;
    MBDlgWinInsertCreate(7, 0x6200, (s32)inserts[0], (s32)inserts[1], 0, 0, 0);
    menuResult = func_80107704_39CA84_w06(choices);
    menu = menuResult;
    MBDlgWinClose();
    MBDlgWinKill();
    switch ((s16)menuResult) {
        case 0:
        case 1:
            goto selectPlayer;
        case 2:
            goto menuResultTwo;
        case 3:
            goto menuResultThree;
        default:
            goto finishMenu;
    }

selectPlayer:
    i = 0;
    j = 0;
    while (i < 4) {
        if (i == sys->current_player_index) {
            choices[j] = 0;
            inserts[j][0] = 1;
        } else if (menu == 0) {
            if (GwPlayer[i].coin == 0) {
                choices[j] = 0;
                inserts[j][0] = 1;
            } else {
                choices[j] = 1;
                inserts[j][0] = 8;
            }
        } else {
            if (GwPlayer[i].star == 0) {
                choices[j] = 0;
                inserts[j][0] = 1;
            } else {
                choices[j] = 1;
                inserts[j][0] = 8;
            }
        }
        func_800E2260_F5E80_shared_board(i, &inserts[j][1]);
        i++;
        j++;
    }
    choices[4] = 1;
    choices[5] = 1;
    MBDlgWinInsertCreate(7, 0x5C02, (s32)inserts[0], (s32)inserts[1], (s32)inserts[2], (s32)inserts[3], 0);
    playerChoice = func_80107724_39CAA4_w06(choices);
    target = playerChoice;
    MBDlgWinClose();
    selectedByCpu = 0;
    MBDlgWinKill();
    switch ((s16)playerChoice) {
        case -1:
            goto restartMenu;
        case 4:
            goto selectCpuPlayer;
        case 5:
            if (modelIsLinked == -1) {
                func_80106B38_39BEB8_w06();
                D_800CB99C_CC59C = 1;
                func_80049FB8_4ABB8();
            } else {
                func_80106AB0_39BE30_w06();
            }
            goto selectPlayer;
        default:
            goto playerSelected;
    }

selectCpuPlayer: {
    i = 0;
    count = 0;
    while (i < 4) {
        for (j = 0; j < 4; j++) {
            if (i == BoardPlayerRankCalc(j) && sys->current_player_index != j) {
                rankedPlayers[count++] = j;
            }
        }
        i++;
    }
    rank = MBRand(100.0f);
    for (i = 0; i < 3; i++) {
        if (rank < D_8011C964_3B1CE4_w06[i]) {
            break;
        }
    }
    if (menu != 0) {
        while (GwPlayer[rankedPlayers[i]].star == 0 || rankedPlayers[i] == sys->current_player_index) {
            i--;
        }
    } else {
        while (i >= 0 &&
               (GwPlayer[rankedPlayers[i]].coin == 0 || rankedPlayers[i] == sys->current_player_index)) {
            i--;
        }
        i = 2;
        while (i >= 0 &&
               (GwPlayer[rankedPlayers[i]].coin == 0 || rankedPlayers[i] == sys->current_player_index)) {
            i--;
        }
    }
    target = rankedPlayers[i];
    selectedByCpu = 1;
}

playerSelected:
    if (menu == 0) {
        MBCoinChangeCreate(sys->current_player_index, -5);
        MBCoinTakeCreate(sys->current_player_index, -5);
    } else {
        MBCoinChangeCreate(sys->current_player_index, -50);
        MBCoinTakeCreate(sys->current_player_index, -50);
    }
    HuPrcSleep(30);
    if ((s16)menu == 1) {
        if (selectedByCpu != 0) {
            MBDlgWinExec(7, 0x6206);
        }
    } else {
        for (i = 0; (u32)i < 6; i++) {
            if (GwSystem.current_turn >= D_8011C91C_3B1C9C_w06[i][0] &&
                GwSystem.current_turn <= D_8011C91C_3B1C9C_w06[i][1]) {
                break;
            }
        }
        estimatedAmount = D_8011C91C_3B1C9C_w06[i][2];
        if (selectedByCpu == 0) {
            MBDlgWinExec(7, MBRand(6.0f) + 0x6207);
        } else {
            MBDlgWinExec(7, 0x620D);
        }
    }
    func_8010DD44_3A30C4_w06(boo);
    if (menu == 0) {
        resultAmount = func_8010E250_3A35D0_w06(target);
        func_8010DCA4_3A3024_w06(boo);
        if (resultAmount != -2) {
            if (resultAmount == -1) {
                resultAmount = GwPlayer[target].coin;
                sprintf(inserts[0], D_8011E14C_3B34CC_w06, resultAmount);
                MBDlgWinInsertCreate(7, 0x6214, (s32)inserts[0], 0, 0, 0, 0);
            } else {
                sprintf(inserts[0], D_8011E14C_3B34CC_w06, resultAmount);
                amountDifference = estimatedAmount - resultAmount;
                for (i = 0; i < 4; i++) {
                    if (amountDifference >= D_8011C95C_3B1CDC_w06[i]) {
                        break;
                    }
                }
                MBDlgWinInsertCreate(7, i + 0x6210, (s32)inserts[0], 0, 0, 0, 0);
            }
            MBDlgWinClose();
            MBDlgWinKill();
        }
        if (resultAmount != -2) {
            mbItemBtnF = 0;
            rate = (f32)resultAmount / 90.0f;
            angle = 0.0f;
            D_8011E348_3B36C8_w06 = MBModelCreate(0x19, NULL);
            MBModelTempAllocFree(D_8011E348_3B36C8_w06);
            MBModelDispOff(D_8011E348_3B36C8_w06);
            coinEffect = MBPlayerVibrateObjCreate(target, 3, 5);
            while (resultAmount != 0) {
                angle += rate;
                if (angle >= 1.0f) {
                    angle -= 1.0f;
                    func_8010F1D0_3A4550_w06((s32)boo);
                    MBCoinTakeCreate(sys->current_player_index, 1);
                    MBCoinTakeCreateSound(target, -1, 0);
                    resultAmount--;
                }
                HuPrcVSleep();
            }
            MBPlayerVibrateObjKill(coinEffect);
            HuPrcSleep(20);
            MBModelKill(D_8011E348_3B36C8_w06);
            MBVecForwardSet(&MBPlayerGet(-1)->player_obj->rot);
            MBPlayerMotionSet(-1, 5, 0);
            HuPrcSleep(5);
            func_8004ACE0_4B8E0(0x274, sys->current_player_index);
            HuPrcSleep(45);
            mbItemBtnF = 1;
            goto outcomeDone;
        }
    } else {
        i = func_8010DDE4_3A3164_w06(target);
        func_8010DCA4_3A3024_w06(boo);
        if (i != 0) {
            MBDlgWinExec(7, 0x6205);
            D_8011B608_3B0988_w06 = 1;
            func_80106A3C_39BDBC_w06(boo);
            D_8011B608_3B0988_w06 = 0;
            goto outcomeDone;
        } else {
            resultAmount = -2;
        }
    }

outcomeDone:
    if (modelIsLinked == -1) {
        HuPrcSleep(20);
        MBPlayerMotionSet(-1, -1, 2);
    }
    if (resultAmount == -2) {
        HuPrcSleep(30);
        MBDlgWinExec(7, 0x6215);
    }
    goto finishMenu;

menuResultTwo:
    func_8010DD44_3A30C4_w06(boo);
    MBDlgWinExec(7, 0x6203);
    goto finishMenu;

menuResultThree:
    if (modelIsLinked == -1) {
        func_80106B38_39BEB8_w06();
        D_800CB99C_CC59C = 1;
        func_80049FB8_4ABB8();
    } else {
        func_80106AB0_39BE30_w06();
    }
    goto restartMenu;

finishMenu:
    if ((s16)menu != 2) {
        func_8010DD44_3A30C4_w06(boo);
    }
    MBVecForwardSet(&boo->rot);
    if (modelIsLinked == -1) {
        MBModelKill(boo);
    }
    if ((s16)camMasu != -1) {
        HuAudFXPlay(0x126);
        MBMotionSet(model, -1, 4);
        func_8001C92C_1D52C(model->omObj1->model[0], 1.2f);
        func_8001C6A8_1D2A8(
            model->omObj1->model[0], D_800CCF58_CDB58[HmfModelData[model->omObj1->model[0]].unk02].unk02);
        while ((u16)func_800D9E80_EDAA0_shared_board(model) == 0) {
            HuPrcVSleep();
        }
        scale = 1.0f / HuMathSin(50.0f);
        for (angle = 50.0f; angle < 90.0f; angle += 11.25f) {
            model->scale.y = HuMathSin(angle) * scale;
            model->scale.x = HuMathSin(angle) * scale * 0.2f + 0.8f;
            model->scale.z = HuMathSin(angle) * scale * 0.2f + 0.8f;
            if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
                model->scale.x = -model->scale.x;
            }
            HuPrcVSleep();
        }
        for (angle = 90.0f; angle > 0.0f; angle -= 11.25f) {
            model->scale.y = HuMathSin(angle) * scale;
            model->scale.x = HuMathSin(angle) * scale * 0.2f + 0.8f;
            model->scale.z = HuMathSin(angle) * scale * 0.2f + 0.8f;
            if (D_8011C970_3B1CF0_w06[sys->current_board_index] != 0) {
                model->scale.x = -model->scale.x;
            }
            HuPrcVSleep();
        }
        model->scale.y = 0.0f;
        model->scale.x = 0.0f;
        model->scale.z = 0.0f;
        MBModelKill(model);
    }
    if (cameraSet != 0) {
        func_800DB884_EF4A4_shared_board(sys->current_player_index);
    }
    if (modelIsLinked != -1) {
        process = HuPrcCurrentGet();
        HuPrcChildLink(process, MBCameraZoomMotStart(1.3f));
        HuPrcChildWait();
    }
    func_8010B4BC_3A083C_w06();
}

void func_801103E0_3A5760_w06(void) {
    func_80108630_39D9B0_w06(0);
}

void func_801103FC_3A577C_w06(void) {
    func_80108630_39D9B0_w06(1);
}

omObjData *func_80110418_3A5798_w06(Vec *arg0, f32 arg1, f32 arg2, s16 arg3, Vec *arg4, s32 arg5) {
    omObjData *obj;
    ModelFadeWork *data;
    Object *model;

    obj = omAddObj(0x1F4, 0, 0, -1, func_80110574_3A58F4_w06);
    data = obj->data = HuMemAllocTag(0x20, 0x7918);
    data->unk0C = 255.0f;
    data->unk10 = arg1;
    data->unk14 = arg2;
    HuVecCopy3F(&data->unk00, arg4);
    if (arg5 != 0) {
        model = MBModelFileCreate(0x1301F8, 0, 1.0f, 0, 0);
    } else {
        model = MBModelFileCreate(0x1301F7, 0, 1.0f, 0, 0);
    }
    Hu3DModelScaleSet(model->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    model->coords.x = arg0->x;
    model->coords.y = arg0->y;
    model->coords.z = arg0->z;
    func_8001FA68_20668(model->omObj1->model[0]);
    func_8001F9E4_205E4(model->omObj1->model[0], 0xFF);
    data->model = model;
    data->unk1C = arg3;
    return obj;
}

void func_80110574_3A58F4_w06(omObjData *arg0) {
    ModelFadeWork *data = arg0->data;
    Object *model = data->model;
    f32 scale;
    f32 alpha;

    HuVecAdd(&model->coords, &model->coords, &data->unk00);
    scale = model->scale.z + data->unk10;
    model->scale.z = scale;
    model->scale.y = scale;
    model->scale.x = scale;
    alpha = data->unk0C - data->unk14;
    data->unk0C = alpha;
    if (alpha < 0.0f) {
        data->unk0C = 0.0f;
        if (data->unk1C != 0) {
            MBModelKill(data->model);
            omDelObj(arg0);
            return;
        }
        omSetStatBit(arg0, 8);
    }
    func_8001F9E4_205E4(model->omObj1->model[0], (u8)data->unk0C);
}

const Vec D_8011E158_3B34D8_w06[8] = {
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 2.0f, 1.0f },
    { 0.0f, 2.0f, 1.0f },
    { -1.0f, 1.0f, 1.0f },
    { -1.0f, -1.0f, 1.0f },
    { 0.0f, -1.0f, 1.0f },
    { -1.0f, 2.0f, 1.0f },
    { 1.0f, -1.0f, 1.0f },
};

void func_8011068C_3A5A0C_w06(void) {
    GW_PLAYER *player;
    GW_SYSTEM *system = &GwSystem;
    Object *lamp;
    void *dialog;
    Vec pos;
    s8 link;
    s8 index;
    s32 angle;
    s32 i;

    player = MBPlayerGet(-1);
    func_801111E4_3A6564_w06();
    lamp = MBModelCreate(0x24, 0);
    Hu3DModelScaleSet(lamp->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&lamp->coords, &player->player_obj->coords);
    lamp->coords.y = 100.0f;
    while (lamp->coords.y > 30.0f) {
        lamp->coords.y -= 1.0f;
        HuPrcVSleep();
    }

    HuAudFXPlay(0x127);
    func_8004A7C4_4B3C4(180);
    dialog = MBPlayerVibrateObjCreate(-1, 4, 5);

    for (angle = 180, i = 0; angle < 1080; angle += 20, i++) {
        Vec velocities[8];

        memcpy(velocities, D_8011E158_3B34D8_w06, sizeof(velocities));
        lamp->coords.y = HuMathSin(angle) * 2.0f + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->coords.x, lamp->coords.y, lamp->coords.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_80110418_3A5798_w06(&pos, 0.1f, 2.0f, 1, &velocities[(i / 2) & 7], 0);
        }
        HuPrcVSleep();
    }

    MBPlayerVibrateObjKill(dialog);
    WipeColorSet(0xFF, 0xFF, 0xFF);
    func_800EB24C_FEE6C_shared_board(
        D_8011B5B0_3B0930_w06[system->star_spawn_indices[system->current_star_spawn]], &link, &index);
    player->clink = link;
    player->cidx = index;
    player->nlink = link;
    player->nidx = index + 1;
    player->blink = link;
    player->bidx = index - 1;
    player->rev &= ~1;
    func_800FC9E0_110600_shared_board();
    HuAudFXPlay(0x128);
    func_8004A0E0_4ACE0();

    while (1) {
        Vec velocities[8];

        memcpy(velocities, D_8011E158_3B34D8_w06, sizeof(velocities));
        lamp->coords.y = HuMathSin(angle) * 2.0f + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->coords.x, lamp->coords.y, lamp->coords.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_80110418_3A5798_w06(&pos, 0.1f, 2.0f, 1, &velocities[(i / 2) & 7], 0);
        }
        HuPrcVSleep();
        i++;
        angle += 20;
        if (angle == 1280) {
            func_80003A70_4670(0);
        }
    }
}

void func_80110A54_3A5DD4_w06(void) {
    s16 ret;

    D_800A12D0_A1ED0 = 1;
    MBMasuEventCall(D_8011B5B0_3B0930_w06[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]], 1);
    D_800A12D0_A1ED0 = 0;
    ret = func_800FF834_113454_shared_board();
    if (ret >= 0) {
        HuPrcSleep(-1);
    }
}

void func_80110AC0_3A5E40_w06(void) {
    s32 currentPlayerIndex;
    GW_PLAYER *player;
    s16 playerIndex;
    s16 spaceIndex;
    s16 fxId;
    s16 ret;

    currentPlayerIndex = GwSystem.current_player_index;
    player = MBPlayerGet(CUR_PLAYER);
    func_801111E4_3A6564_w06();
    func_800DCA64_F0684_shared_board(currentPlayerIndex);
    MBPlayerVibrate(CUR_PLAYER, 3);
    GWBoardFlagSet(0x11);
    func_800DC128_EFD48_shared_board(currentPlayerIndex);
    playerIndex = func_800EF0D8_102CF8_shared_board(1);
    func_8004A0E0_4ACE0();
    func_800FC8A4_1104C4_shared_board();
    HuPrcSleep(5);
    HuPrcSleep(25);
    MBPlayerMotionSet(currentPlayerIndex, 2, 0);
    func_800EE688_1022A8_shared_board(GwPlayer[currentPlayerIndex].player_obj, 2.0f, -0.3f);
    HuPrcSleep(5);
    func_800DCBCC_F07EC_shared_board(currentPlayerIndex);
    func_800F2388_105FA8_shared_board(currentPlayerIndex, CUR_PLAYER, 0, 10, 2);
    HuPrcSleep(20);
    MBItemWarpBlockSwapInit();
    MBItemWarpBlockSwapPlayerSet(playerIndex);
    MBItemWarpBlockSwapCreate();
    GWBoardFlagClear(0x11);
    fxId = func_800DC128_EFD48_shared_board(currentPlayerIndex);
    HuAudFXStop(fxId);
    func_800DC06C_EFC8C_shared_board(currentPlayerIndex);
    MBStatusShrink(CUR_PLAYER);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(CUR_PLAYER);
    func_800DCD2C_F094C_shared_board(currentPlayerIndex, CUR_PLAYER);
    spaceIndex = MBMasuLinkMasuIdGet(player->clink, player->cidx);
    MBMasuCurSet(spaceIndex);
    MBMasuEventCall(spaceIndex, 1);
    ret = func_800FF834_113454_shared_board();
    if (ret >= 0) {
        HuPrcSleep(CUR_PLAYER);
    }
    func_800DAA40_EE660_shared_board(currentPlayerIndex);
}

void func_80110C80_3A6000_w06(void) {
    Process *process = HuPrcCurrentGet();
    WarpBlockSwapWork *work = process->user_data;
    f32 deltaX;
    f32 deltaY;
    f32 spriteX;
    f32 spriteY;
    s32 i;

    deltaX = (f32)(work->endX - work->startX) / (f32)work->duration;
    deltaY = (f32)(work->endY - work->startY) / (f32)work->duration;
    func_800F6848_10A468_shared_board(GwSystem.current_player_index, MBItemSelNoGet(), &spriteX, &spriteY);

    for (i = 1; i <= work->duration; i++) {
        if (work->spriteGroup != -1) {
            func_80054904_55504(work->spriteGroup, 0,
                                work->startX + (deltaX * i), work->startY + (deltaY * i));
        }

        MBStatusItemPosSet(GwSystem.current_player_index, MBItemSelNoGet(),
                           spriteX + (deltaX * i), spriteY + (deltaY * i));
        HuPrcVSleep();
    }

    if (work->spriteGroup != -1) {
        func_80054904_55504(work->spriteGroup, 0, work->endX, work->endY);
    }

    MBStatusItemPosSet(GwSystem.current_player_index, MBItemSelNoGet(),
                       work->endX + spriteX - work->startX,
                       work->endY + spriteY - work->startY);
    omDelPrcObj(NULL);
}

Process *func_80110EE4_3A6264_w06(s32 spriteGroup, s16 startX, s16 startY, s16 endX, s16 endY,
                                  s16 duration) {
    Process *process;
    WarpBlockSwapWork *work;

    process = omAddPrcObj(func_80110C80_3A6000_w06, 0x4002, 0, 0x40);
    work = HuMemMemoryAlloc(process->heap, 0x10);
    process->user_data = work;
    work->startX = startX;
    work->startY = startY;
    work->endX = endX;
    work->endY = endY;
    if (duration == -1) {
        duration = 25;
    }
    work->duration = duration;
    work->spriteGroup = spriteGroup;
    return process;
}

void func_80110FB4_3A6334_w06(void) {
    GW_SYSTEM *system = &GwSystem;
    Process *process;
    f32 position[2];
    s32 i;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &position[0], &position[1]);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_80110EE4_3A6264_w06(
                                mbItemCursorGrpId, position[0], position[1],
                                D_8011CA44_3B1DC4_w06[system->current_player_index].x,
                                D_8011CA44_3B1DC4_w06[system->current_player_index].y, -1));
    HuPrcChildWait();
    HuPrcSleep(10);
    func_80055140_55D40(mbItemCursorGrpId, 0, 0, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);

    for (i = 1; i < 10; i++) {
        MBStatusItemTPLvlSet(system->current_player_index,
                             MBItemSelNoGet(), 255 - (i * 25));
        MBStatusItemOfsApply(system->current_player_index,
                             MBItemSelNoGet(), 0, 2.0f);
        HuPrcVSleep();
    }

    MBStatusItemTPLvlSet(system->current_player_index,
                         MBItemSelNoGet(), 0);
    MBPlayerMotionSet(-1, 5, 0);
    func_8004ACE0_4B8E0(0x274, system->current_player_index);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

void func_801111E4_3A6564_w06(void) {
    GW_SYSTEM *system = &GwSystem;
    f32 position[2];
    s32 i;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &position[0], &position[1]);
    func_80110EE4_3A6264_w06(
        mbItemCursorGrpId, (s16)position[0], (s16)position[1],
        (s16)D_8011CA64_3B1DE4_w06[system->current_player_index].x,
        (s16)D_8011CA64_3B1DE4_w06[system->current_player_index].y, -1);
    HuPrcSleep(20);

    for (i = 1; i < 10; i++) {
        MBStatusItemTPLvlSet(system->current_player_index,
                             MBItemSelNoGet(), 255 - (i * 25));
        func_80055458_56058(mbItemCursorGrpId, 0, 255 - (i * 25));
        HuPrcVSleep();
    }

    MBStatusItemTPLvlSet(system->current_player_index,
                         MBItemSelNoGet(), 0);
    func_80055458_56058(mbItemCursorGrpId, 0, 0);
    HuPrcSleep(2);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

void func_801113B4_3A6734_w06(void) {
    f32 position[2];
    s32 targetX;
    s32 targetY;
    Process *process;
    s32 i;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    func_800F6848_10A468_shared_board(GwSystem.current_player_index,
                                      MBItemSelNoGet(), &position[0], &position[1]);
    MBStatusItemPosGet(-1, MBItemSelNoGet(), &targetX, &targetY);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_80110EE4_3A6264_w06(mbItemCursorGrpId, (s16)position[0], (s16)position[1],
                                            (s16)targetX, (s16)targetY, -1));
    HuPrcChildWait();

    for (i = 1; i < 10; i++) {
        func_80055458_56058(mbItemCursorGrpId, 0, 255 - (i * 25));
        HuPrcVSleep();
    }

    func_80055458_56058(mbItemCursorGrpId, 0, 0);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

void func_80111524_3A68A4_w06(void) {
    GW_SYSTEM *system = &GwSystem;
    f32 position[2];
    Process *process;
    s32 i;
    s32 j;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &position[0], &position[1]);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_80110EE4_3A6264_w06(mbItemCursorGrpId, (s16)position[0], (s16)position[1],
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].x,
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].y, -1));
    HuPrcChildWait();
    HuPrcSleep(10);
    func_80055140_55D40(mbItemCursorGrpId, 0, 0, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);

    for (i = 1; i < 10; i++) {
        func_80055458_56058(mbItemCursorGrpId, 0, 255 - (i * 25));
        HuPrcVSleep();
    }

    func_80055458_56058(mbItemCursorGrpId, 0, 0);
    if ((GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] == 0xB) ||
        (GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] == 8)) {
        HuAudFXPlay(0x141);
    }

    for (i = 0; i <= 1080; i += 30) {
        MBStatusItemRotSet(system->current_player_index,
                           MBItemSelNoGet(), HuMathSin(i) * 30.0f);
        HuPrcVSleep();
    }

    for (j = 1; j < 10; j++) {
        MBStatusItemTPLvlSet(system->current_player_index,
                             MBItemSelNoGet(), 255 - (j * 25));
        MBStatusItemRotSet(system->current_player_index,
                           MBItemSelNoGet(), HuMathSin(i) * 30.0f);
        HuPrcVSleep();
        i += 30;
    }

    MBStatusItemTPLvlSet(system->current_player_index,
                         MBItemSelNoGet(), 0);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

void func_80111870_3A6BF0_w06(void) {
    GW_SYSTEM *system = &GwSystem;
    f32 position[2];
    Process *process;
    s32 i;

    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &position[0], &position[1]);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_80110EE4_3A6264_w06(mbItemCursorGrpId, (s16)position[0], (s16)position[1],
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].x,
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].y, -1));
    HuPrcChildWait();
    HuPrcSleep(10);
    func_80055140_55D40(mbItemCursorGrpId, 0, 0, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);

    for (i = 1; i < 10; i++) {
        func_80055458_56058(mbItemCursorGrpId, 0, 255 - (i * 25));
        HuPrcVSleep();
    }

    func_80055458_56058(mbItemCursorGrpId, 0, 0);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
}

void func_80111A34_3A6DB4_w06(s32 arg0, s32 arg1, s32 duration, f32 *target, s32 mode) {
    f32 position[2];
    f32 stepX;
    f32 stepY;
    f32 scale;
    s32 i;

    if (mode == 2) {
        HuAudFXPlay(0x145);
    }

    func_800F6848_10A468_shared_board(arg0, arg1, &position[0], &position[1]);
    stepX = (target[0] - position[0]) / duration;
    stepY = (target[1] - position[1]) / duration;

    for (i = 2; duration != 0; duration--, i++) {
        position[0] += stepX;
        position[1] += stepY;
        MBStatusItemPosSet(arg0, arg1, (s16)position[0], (s16)position[1]);

        if ((mode == 1) && (i < 11)) {
            MBStatusItemTPLvlSet(arg0, arg1, i * 25);
            scale = i * 0.07f;
            MBStatusItemScaleSet(arg0, arg1, scale + 0.3f,
                                 (f32)((f64)scale + D_8011E1B8_3B3538_w06));
        }
        HuPrcVSleep();
    }

    MBStatusItemPosSet(arg0, arg1, (s16)target[0], (s16)target[1]);

    if (mode == 0) {
        for (i = 1; i < 10; i++) {
            MBStatusItemTPLvlSet(arg0, arg1, 255 - (i * 25));
            MBStatusItemScaleSet(arg0, arg1, 1.0f - (i * 0.1f), 1.0f - (i * 0.1f));
            HuPrcVSleep();
        }
        MBStatusItemTPLvlSet(arg0, arg1, 0);
    }
}

const f64 D_8011E1B8_3B3538_w06 = 0.3;

void func_80111CCC_3A704C_w06(void) {
    GW_PLAYER *player;
    Object *model;
    f32 scale;
    f32 angle;

    player = MBPlayerGet(-1);
    MBKSuitCreate();
    MBModelDispOff(D_801011FC_114E1C_shared_board);
    D_801011FC_114E1C_shared_board->omObj1->scale.x = 0.0f;
    D_801011FC_114E1C_shared_board->omObj1->scale.y = 0.0f;
    D_801011FC_114E1C_shared_board->omObj1->scale.z = 0.0f;
    MBPlayerVibrate(-1, 3);
    HuAudFXPlay(0x143);

    model = MBModelCreate(0x22, NULL);
    func_8001C258_1CE58(model->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(model->omObj1->model[0], 0x1800);
    func_8001C448_1D048(model->omObj1->model[0]);
    HuVecCopy3F(&model->coords, &player->player_obj->coords);

    angle = 0.0f;
    for (scale = 1.0f; scale < 10.0f; scale = (f32)((f64)scale + 0.5)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    MBModelDispOff(player->player_obj);
    MBModelDispOn(D_801011FC_114E1C_shared_board);

    for (; scale >= 1.0f; scale = (f32)((f64)scale - 0.5)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    MBModelKill(model);
    HuPrcSleep(20);
    func_8004ACE0_4B8E0(0x274, GwSystem.current_player_index);
    MBKSuitMotionSet(5, 2);
    HuPrcSleep(40);
    MBKSuitMotionSet(-1, 2);
    MBDlgResultWinExec(0x3A14);
}

void func_80111F58_3A72D8_w06(void) {
    Vec direction;
    GW_PLAYER *player;
    Object *model;
    f32 scale;
    f32 angle;

    player = MBPlayerGet(-1);
    MBKSuitMotionSet(-1, 2);
    MBVecForwardSet(&direction);
    func_800ED128_100D48_shared_board(&player->player_obj->rot, &direction, &player->player_obj->rot, 8);
    HuPrcSleep(8);
    HuAudFXPlay(0x143);

    model = MBModelCreate(0x22, NULL);
    func_8001C258_1CE58(model->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(model->omObj1->model[0], 0x1800);
    func_8001C448_1D048(model->omObj1->model[0]);
    HuVecCopy3F(&model->coords, &player->player_obj->coords);

    angle = 0.0f;
    for (scale = 1.0f; scale < 10.0f; scale = (f32)((f64)scale + 0.5)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    MBModelDispOn(player->player_obj);
    MBKSuitKill();

    for (; scale >= 1.0f; scale = (f32)((f64)scale - 0.5)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    MBModelKill(model);
}

void func_80112198_3A7518_w06(void) {
    s32 index;
    s32 group;
    s32 alpha;
    void *dialog;
    f32 x;
    f32 y;
    f32 angle;

    index = (s32)HuPrcCurrentGet()->user_data;
    dialog = MBPlayerVibrateObjCreate(-1, 1, 5);
    group = HuSprGrpCreate(1, 0);
    func_80055024_55C24(group, 0, D_8011E34E_3B36CE_w06, 0);
    HuSprPriSet(group, 0, 0x4780);
    HuSprAttrSet(group, 0, 0x1000);
    func_800F6848_10A468_shared_board(GwSystem.current_player_index, MBItemSelNoGet(), &x, &y);
    x += 20.0f;
    y -= 20.0f;
    func_80054904_55504(group, 0, (s16)x, (s16)y);
    func_80055420_56020(group, 0, 0xFF, 0xFF, 0);

    alpha = 0xFF;
    angle = (f32)D_8011CB30_3B1EB0_w06[index];
    for (; alpha >= 0; alpha -= 0x14) {
        x += HuMathCos(angle) * 5.0f;
        y -= HuMathSin(angle) * 5.0f;
        func_80054904_55504(group, 0, (s16)x, (s16)y);
        func_80055458_56058(group, 0, alpha);
        HuPrcVSleep();
    }

    func_80055458_56058(group, 0, 0);
    MBPlayerVibrateObjKill(dialog);
    HuSprGrpKill(group);
    omDelPrcObj(0);
}

void func_801123A8_3A7728_w06(void) {
    GW_SYSTEM *loc;
    void *data;
    s32 choice;
    Process *process;
    s32 one;

    loc = &GwSystem;
    data = DataRead(0x001301B8);
    D_8011E34C_3B36CC_w06 = func_80055810_56410(data);
    DataClose(data);
    func_80111870_3A6BF0_w06();

    while (1) {
        MBDlgWinInsertCreate(-1, 0x3A01, 0, 0, 0, 0, 0);
        choice = func_8010B4C4_3A0844_w06((s32)D_8011CAC4_3B1E44_w06, 0);
        MBDlgWinClose();
        MBDlgWinKill();

        if (choice < 2) {
            if (choice < 0) {
                process = omAddPrcObj(func_8010B804_3A0B84_w06, 0, 0, 0);
                omPrcSetStatBit(process, 0x80);
                func_80106B38_39BEB8_w06();
                one = 1;
                D_800CB99C_CC59C = one;
                func_80049FB8_4ABB8();
                omDelPrcObj(process);
                func_800FC8A4_1104C4_shared_board();
                continue;
            }
            GwSystem.forceShopHost = choice + 1;
            break;
        }

        process = omAddPrcObj(func_8010B804_3A0B84_w06, 0, 0, 0);
        omPrcSetStatBit(process, 0x80);
        func_80106B38_39BEB8_w06();
        one = 1;
        D_800CB99C_CC59C = one;
        func_80049FB8_4ABB8();
        omDelPrcObj(process);
        func_800FC8A4_1104C4_shared_board();
        continue;
    }

    {
        s32 i;

        HuPrcSleep(30);
        HuAudFXPlay(0x147);
        for (i = 0; i < 5; i++) {
            process = omAddPrcObj(func_80112198_3A7518_w06, 0x4002, 0, 0);
            process->user_data = (void *)i;
            HuPrcChildLink(HuPrcCurrentGet(), process);
            HuPrcSleep(3);
        }
        HuPrcChildWait();
        HuPrcSleep(20);

        for (i = 0; i < 5; i++) {
            process = omAddPrcObj(func_80112198_3A7518_w06, 0x4002, 0, 0);
            process->user_data = (void *)i;
            HuPrcChildLink(HuPrcCurrentGet(), process);
            HuPrcSleep(3);
        }
        HuPrcChildWait();
        HuPrcSleep(20);
    }

    GwPlayer[loc->current_player_index].itemNo[MBItemSelNoGet()] = -1;
    MBItemRemoveEmpty(loc->current_player_index);
    MBStatusItemTPLvlSet(loc->current_player_index,
                         MBItemSelNoGet(), 0);
    HuSprKill(D_8011E34E_3B36CE_w06);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);

    if (choice != 0) {
        HuAudFXPlay(0x2A0);
        goto sound_done;
    }
    if (GwPlayer[loc->current_player_index].coin < 5)
        goto sound_29a;
    if (loc->current_turn != loc->total_turns)
        goto sound_298;
sound_29a:
    HuAudFXPlay(0x29A);
    goto sound_done;
sound_298:
    HuAudFXPlay(0x298);
    goto sound_done;
sound_done:
    func_8010C9EC_3A1D6C_w06();
    GwSystem.forceShopHost = 0;
}

void func_80112668_3A79E8_w06(void) {
    GW_SYSTEM *loc;
    void *data;
    s32 choice;
    Process *process;
    s32 one;

    loc = &GwSystem;
    data = DataRead(0x001301B8);
    D_8011E34C_3B36CC_w06 = func_80055810_56410(data);
    DataClose(data);
    func_80111870_3A6BF0_w06();

    {
        s32 i;

        HuPrcSleep(30);
        HuAudFXPlay(0x147);
        for (i = 0; i < 5; i++) {
            process = omAddPrcObj(func_80112198_3A7518_w06, 0x4002, 0, 0);
            process->user_data = (void *)i;
            HuPrcChildLink(HuPrcCurrentGet(), process);
            HuPrcSleep(3);
        }
        HuPrcChildWait();
        HuPrcSleep(20);

        for (i = 0; i < 5; i++) {
            process = omAddPrcObj(func_80112198_3A7518_w06, 0x4002, 0, 0);
            process->user_data = (void *)i;
            HuPrcChildLink(HuPrcCurrentGet(), process);
            HuPrcSleep(3);
        }
        HuPrcChildWait();
        HuPrcSleep(20);
    }

    HuAudFXPlay(0x29F);
retry:
    MBDlgWinInsertCreate(4, 0x3A0A,
                         mbCharNameMesTbl[GwPlayer[0].chr],
                         mbCharNameMesTbl[GwPlayer[1].chr],
                         mbCharNameMesTbl[GwPlayer[2].chr],
                         mbCharNameMesTbl[GwPlayer[3].chr], 0);
    if (GwPlayer[loc->current_player_index].coin != 0) {
        choice = func_8010B4C4_3A0844_w06(1, 0);
    } else {
        choice = func_8010B4C4_3A0844_w06(2, loc->current_player_index);
    }
    MBDlgWinClose();
    MBDlgWinKill();

    switch (choice) {
        case 4:
            choice = func_800EF0D8_102CF8_shared_board(0);
            MBDlgWinInsertCreate(4, 0x3A0C, 0, 0, 0, 0, 0);
            break;
        case 5:
            process = omAddPrcObj(func_8010B804_3A0B84_w06, 0, 0, 0);
            omPrcSetStatBit(process, 0x80);
            func_80106B38_39BEB8_w06();
            one = 1;
            D_800CB99C_CC59C = one;
            func_80049FB8_4ABB8();
            omDelPrcObj(process);
            func_800FC8A4_1104C4_shared_board();
            goto retry;
        default:
            MBDlgWinInsertCreate(4, 0x3A0B,
                                 (s32)((char **)0x801014A0)[GwPlayer[choice].chr],
                                 0, 0, 0, 0);
            break;
    }
    MBDlgWinClose();
    MBDlgWinKill();

    HuAudFXPlay(0x29C);
    GwPlayer[loc->current_player_index].itemNo[MBItemSelNoGet()] = -1;
    MBItemRemoveEmpty(loc->current_player_index);
    MBStatusItemTPLvlSet(loc->current_player_index,
                         MBItemSelNoGet(), 0);
    HuSprKill(D_8011E34E_3B36CE_w06);

    if (func_800DEB2C_F274C_shared_board(loc->current_player_index) == 3) {
        GWBoardFlagSet(0x17);
    } else {
        GWBoardFlagClear(0x17);
    }
    GwSystem.playerIndexVisitingBowser = choice;
    func_800FCA4C_11066C_shared_board();
    func_800FF794_1133B4_shared_board(0x50, 0, 3, 1);
    func_800FC8A4_1104C4_shared_board();
    func_800FF7F0_113410_shared_board(2);
    func_8004A0E0_4ACE0();
    HuPrcSleep(-1);
}

void func_80112A08_3A7D88_w06(void) {
    s32 i;
    s32 j;
    s32 wipeStarted;
    GW_SYSTEM *system = &GwSystem;
    Object *lamp;
    Object *starModel;
    Object *targetStar;
    Process *process;
    Process *dialogProcess;
    Vec direction;
    Vec pos;
    Vec destination;
    Vec velocities[8];
    Vec velocities2[8];
    s32 angle;
    s32 alpha;
    f32 speed;
    f32 rotation;
    void *dialog;

    {
        GW_PLAYER *player;

        player = MBPlayerGet(-1);
        lamp = MBModelCreate(0x3C, NULL);
        MBMotionSet(lamp, -1, 1);
        Hu3DModelScaleSet(lamp->omObj1->model[0], 0.0f, 0.0f, 0.0f);
        HuVecCopy3F(&lamp->coords, &player->player_obj->coords);
        lamp->velocity.x = 30.0f;
        lamp->flags |= 1;
        HuVecCopyXYZ(&lamp->scale, 0.0f, 0.0f, 0.0f);
        MBModelDispOff(lamp);
        func_801111E4_3A6564_w06();

        {
            s32 itemSlot = MBItemFind(-1, 9);

            GwPlayer[W06CurrentPlayerIndexGet()].itemNo[itemSlot] = -1;
        }
        MBItemRemoveEmpty(W06CurrentPlayerIndexGet());

        starModel = MBModelCreate(0x3D, NULL);
        func_8001FA68_20668(starModel->omObj1->model[0]);
        func_8001F9E4_205E4(starModel->omObj1->model[0], 0xFF);
        Hu3DModelScaleSet(starModel->omObj1->model[0], 0.0f, 0.0f, 0.0f);
        HuVecCopy3F(&starModel->coords, &player->player_obj->coords);
        starModel->coords.y = 100.0f;
        while (starModel->coords.y > 30.0f) {
            starModel->coords.y -= 1.0f;
            HuPrcVSleep();
        }
    }

    HuAudFXPlay(0x127);
    func_800039A4_45A4(D_800CDBC8_CE7C8, 0xB4);
    dialog = MBPlayerVibrateObjCreate(-1, 3, 5);

    for (angle = 180, i = 0; angle < 1080; angle += 20, i++) {
        memcpy(velocities, D_8011E158_3B34D8_w06, sizeof(velocities));
        starModel->coords.y = HuMathSin((f32)angle) * 2.0f + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, starModel->coords.x, starModel->coords.y, starModel->coords.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_80110418_3A5798_w06(&pos, 0.1f, 2.0f, 1,
                                     &velocities[(i / 2) & 7], 1);
        }
        HuPrcVSleep();
    }

    alpha = 0xFF;
    speed = 0.0f;
    while (1) {
        memcpy(velocities2, D_8011E158_3B34D8_w06, sizeof(velocities2));
        starModel->coords.y = HuMathSin((f32)angle) * 2.0f + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, starModel->coords.x, starModel->coords.y, starModel->coords.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_80110418_3A5798_w06(&pos, 0.1f, 2.0f, 1,
                                     &velocities2[(i / 2) & 7], 1);
        }

        if (alpha > 0) {
            func_8001F9E4_205E4(starModel->omObj1->model[0], alpha & 0xFF);
            alpha -= 12;
        } else {
            MBModelDispOff(starModel);
            func_800D9A40_ED660_shared_board(lamp);
            speed += 0.1f;
            lamp->scale.z = speed;
            lamp->scale.y = speed;
            lamp->scale.x = speed;
            if (speed > 1.0f) {
                HuAudSeqPlay(0x3D);
                break;
            }
        }
        i++;
        HuPrcVSleep();
    }

    lamp->scale.x = lamp->scale.y = lamp->scale.z = 1.0f;
    dialogProcess = func_800EDB98_1017B8_shared_board(lamp, 3.0f, 2.0f);
    MBPlayerVibrateObjKill(dialog);
    HuPrcSleep(30);
    MBDlgWinExec(0x3C, 0x3A2F);
    omDelPrcObj(dialogProcess);

    i = 1;
    lamp->coords.y -= lamp->velocity.x;
    HuVecSubtract(&direction, &gCameraList->pos, &lamp->coords);
    MBVecNormalize(&direction);
    lamp->coords.y += lamp->velocity.x;

    while (lamp->velocity.x < 1800.0f) {
        lamp->coords.x += direction.x * 40.2f;
        lamp->velocity.x += direction.y * 40.0f;
        lamp->coords.z += direction.z * 40.2f;
        if ((lamp->velocity.x > 300.0f) && (i != 0)) {
            i = 0;
            WipeColorSet(0xFF, 0xFF, 0xFF);
            WipeCreateOut(0xB, 0x32);
            HuAudFXPlay(0x128);
        }
        HuPrcVSleep();
    }

    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    {
        SpaceData *space;
        SpaceData *nextSpace;

        space = MBMasuGet(D_8011B5B0_3B0930_w06[system->star_spawn_indices[system->current_star_spawn]]);
        nextSpace = MBMasuGet(D_8011B5C0_3B0940_w06[system->star_spawn_indices[system->current_star_spawn]]);
        HuVecCopy3F(&destination, &space->coords);
        MBCameraPos3DSet(&destination);
        MBCameraFocusModeSet(4);
        MBCameraFocusVecSet(&destination);
        lamp->flags &= ~1;
        HuVecCopy3F(&lamp->coords, &space->coords);
        HuVecSubtract(&direction, &nextSpace->coords, &space->coords);
        MBVecNormalize(&direction);
        lamp->coords.x -= direction.x * 20.0f;
        lamp->coords.z -= direction.z * 20.0f;
    }

    HuAudFXPlay(0x129);
    WipeCreateIn(0xB, 0x32);
    lamp->velocity.x = 100.0f;
    while (lamp->velocity.x > 30.0f) {
        HuPrcVSleep();
        lamp->velocity.x -= 3.0f;
    }

    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_800ED128_100D48_shared_board(&lamp->rot,
                                                     &direction,
                                                     &lamp->rot, 0x10));
    i = 0;
    HuPrcChildWait();
    dialogProcess = func_800EDB98_1017B8_shared_board(lamp, 3.0f, 2.0f);
    MBDlgWinExec(0x3C, 0x3A30);
    HuAudFXPlay(0x12C);
    MBMotionSet(lamp, -1, 0);
    HuPrcSleep(20);

    wipeStarted = 1;
    for (j = 0; j < 8; j++) {
        if (D_8011E298_3B3618_w06[j] != NULL) {
            omDelPrcObj(D_8011E298_3B3618_w06[j]);
            D_8011E298_3B3618_w06[j] = NULL;
        }
    }

    targetStar = D_8011E278_3B35F8_w06[system->star_spawn_indices[system->current_star_spawn]];
    HuAudSeqFadeOut(0x5A);
    rotation = 0.0f;
    while (targetStar->velocity.x < 400.0f) {
        targetStar->velocity.x += 3.0f;
        targetStar->coords.x += direction.x * 3.0f;
        targetStar->coords.z += direction.z * 3.0f;
        targetStar->rot.x = -HuMathSin(rotation);
        targetStar->rot.z = HuMathCos(rotation);
        rotation += 45.0f;
        if (rotation > 360.0f) {
            rotation -= 360.0f;
        }
        if ((targetStar->velocity.x > 50.0f) && (wipeStarted != 0)) {
            if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
                GWBoardFlagSet(0x17);
            } else {
                GWBoardFlagClear(0x17);
            }
            wipeStarted = 0;
            WipeColorSet(0, 0, 0);
            omDelPrcObj(dialogProcess);
            func_800EDA58_101678_shared_board();
            func_800FC8A4_1104C4_shared_board();
            func_800FF7F0_113410_shared_board(2);
            func_800FCA14_110634_shared_board();
            func_8004A0E0_4ACE0();
        }
        HuPrcVSleep();
    }
    HuPrcSleep(-1);
}

void func_80113404_3A8784_w06(void) {
    GW_SYSTEM *system = &GwSystem;
    s32 player;
    Process *process;
    s32 group;
    void *sprite;
    s32 spriteCount;
    s32 i;
    f32 position[2];
    s32 result;

    player = GwSystem.current_player_index;
    group = (s16)HuSprGrpCreate(1, 0);
    sprite = DataRead(D_8010197C_11559C_shared_board[1]);
    spriteCount = (s16)func_80055810_56410(sprite);
    DataClose(sprite);
    func_80055024_55C24(group, 0, spriteCount, 0);
    HuSprPriSet(group, 0, 0x4780);
    HuSprAttrSet(group, 0, 0x9000);
    func_80055140_55D40(mbItemCursorGrpId, 0, 1, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuPrcSleep(20);
    HuAudFXPlay(0x145);
    MBStatusSprPosGet(mbItemCursorGrpId, 0, &position[0], &position[1]);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_80110EE4_3A6264_w06(mbItemCursorGrpId, (s16)position[0], (s16)position[1],
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].x,
                                            (s16)D_8011CA44_3B1DC4_w06[system->current_player_index].y, -1));
    HuPrcChildWait();
    HuPrcSleep(10);
    func_80055140_55D40(mbItemCursorGrpId, 0, 0, 0);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    for (i = 1; i < 10; i++) {
        func_80055458_56058(mbItemCursorGrpId, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80055458_56058(mbItemCursorGrpId, 0, 0);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
    GwPlayer[player].itemNo[MBItemSelNoGet()] = -1;
    MBStatusItemTPLvlSet(player, MBItemSelNoGet(), 0);
    func_800F6848_10A468_shared_board(player, MBItemSelNoGet(), &position[0], &position[1]);
    func_80054904_55504(group, 0, (s16)position[0], (s16)position[1]);
    HuSprAttrReset(group, 0, 0x8000);
    MBItemRemoveEmpty(player);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);
retry:
    MBDlgWinInsertCreate(0x38, 0x4100, 0, 0, 0, 0, 0);
    result = func_8010B4C4_3A0844_w06((s32)&D_8011CB44_3B1EC4_w06, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    switch (result) {
        case 0:
            MBDlgWinInsertCreate(0x38, 0x4101, 0, 0, 0, 0, 0);
            break;
        case 1:
            MBDlgWinInsertCreate(0x38, 0x4102, 0, 0, 0, 0, 0);
            HuSprAttrSet(group, 0, 0x8000);
            GwPlayer[player].itemNo[MBItemFindEmpty(player)] = 1;
            MBItemRemoveEmpty(player);
            GwSystem.cur_player_used_item &= ~1;
            break;
        default:
            HuSprAttrSet(group, 0, 0x8000);
            func_80106B38_39BEB8_w06();
            D_800CB99C_CC59C = 1;
            func_80049FB8_4ABB8();
            HuSprAttrReset(group, 0, 0x8000);
            goto retry;
    }
    MBDlgWinClose();
    MBDlgWinKill();
    if (result == 0) {
        HuPrcSleep(10);
        for (i = 1; i < 0x40; i++) {
            func_80055458_56058(group, 0, (u16)(255.0f - (f32)i * 3.984f));
            HuPrcVSleep();
        }
        func_80055458_56058(group, 0, 0);
    }
    HuSprGrpKill(group);
    HuSprKill(spriteCount);
}

void func_8011394C_3A8CCC_w06(void) {
    s32 playerIndex;
    s32 group;
    s16 setupGroup;
    s32 xPos;
    s16 fadeGroup;
    s32 yPos;
    f32 scale;
    s32 alpha;

    playerIndex = (s32)HuPrcCurrentGet()->user_data;
    group = (s16)HuSprGrpCreate(1, 0);
    setupGroup = group;
    func_80055024_55C24(setupGroup, 0, D_8011E356_3B36D6_w06, 0);
    HuSprPriSet(setupGroup, 0, 9);
    HuSprAttrSet(setupGroup, 0, 0x1000);
    MBStatusItemPosGet(D_8011E350_3B36D0_w06, 0, &xPos, &yPos);

    xPos = (s32)((D_8011C8FC_3B1C7C_w06[D_8011E350_3B36D0_w06].x * 16.0f) +
                 D_8011C8DC_3B1C5C_w06[D_8011E350_3B36D0_w06].x);
    yPos = (s32)((D_8011C900_3B1C80_w06[D_8011E350_3B36D0_w06].x * 16.0f) +
                 D_8011C8E0_3B1C60_w06[D_8011E350_3B36D0_w06].x);
    func_80054904_55504(
        setupGroup, 0, (s16)((f32)xPos + D_8011CB50_3B1ED0_w06[playerIndex].x),
        (s16)((f32)yPos + D_8011CB54_3B1ED4_w06[playerIndex].x));
    func_80055420_56020(group, 0, 0xFF, 0xFF, 0xFF);
    func_80055458_56058(group, 0, 0xFF);

    scale = 0.0f;
    alpha = 0xFF;
    while (alpha >= 0) {
        HuSprScaleSet(group, 0, scale, scale);
        func_80055458_56058(group, 0, alpha);
        HuPrcVSleep();
        alpha -= 10;
        scale += 0.1f;
    }

    func_80055458_56058(group, 0, 0);
    HuSprGrpKill(group);
    omDelPrcObj(NULL);
}

void func_80113B68_3A8EE8_w06(void) {
    s32 playerIndex;
    void *data;
    s32 itemSpriteId;
    s32 auraSpriteId;
    s32 group;
    s16 setupGroup;
    s32 xPos;
    s16 fadeGroup;
    s32 yPos;
    s32 i;
    s32 j;
    Process *childProcess;
    s32 fxId;

    playerIndex = (s32)HuPrcCurrentGet()->user_data;
    data = DataRead(0x21002C);
    itemSpriteId = func_80055810_56410(data);
    DataClose(data);
    data = DataRead(0x1301BA);
    auraSpriteId = func_80055810_56410(data);
    DataClose(data);
    data = DataRead(0x1301B9);
    D_8011E354_3B36D4_w06 = func_80055810_56410(data);
    DataClose(data);

    group = (s16)HuSprGrpCreate(2, 2);
    setupGroup = group;
    func_800550F4_55CF4(setupGroup, 0, 1);
    func_80055024_55C24(setupGroup, 0, itemSpriteId, 0xC);
    HuSprPriSet(setupGroup, 0, 9);
    HuSprAttrSet(setupGroup, 0, 0x1000);
    func_800554C4_560C4(setupGroup, 0, -1);
    func_80055024_55C24(setupGroup, 1, auraSpriteId, 0);
    HuSprPriSet(setupGroup, 1, 9);
    HuSprAttrSet(setupGroup, 1, 0x9000);
    func_80055420_56020(setupGroup, 1, 0xFF, 0xFF, 0xFF);
    func_80055458_56058(setupGroup, 1, 0xFF);
    HuSprScaleSet(setupGroup, 1, 2.0f, 2.0f);
    func_800554C4_560C4(setupGroup, 1, 0);

    yPos = 0xC8;
    if (playerIndex & 1) {
        HuSprAttrSet(setupGroup, 0, 1);
        HuSprAttrSet(setupGroup, 1, 1);
        func_80054904_55504(setupGroup, 1, 0x14, -5);
    } else {
        yPos = 0x78;
        func_80054904_55504(group, 1, -0x14, -5);
    }

    xPos = (playerIndex < 2) ? -0x20 : 0x110;
    HuPrcSleep(0x14);
    GwPlayer[playerIndex].itemNo[MBItemFind(playerIndex, 0xC)] = -1;
    MBItemRemoveEmpty(playerIndex);
    MBStatusItemIconSprReinit(playerIndex);

    do {
        if (playerIndex < 2) {
            xPos += 5;
            if (xPos >= 0x33) {
                break;
            }
        } else {
            xPos -= 5;
            if (xPos < 0xD2) {
                break;
            }
        }
        func_80054904_55504(group, 0, yPos, xPos);
        HuPrcVSleep();
    } while (1);

    HuPrcSleep(0xA);
    HuSprAttrReset(group, 1, 0x8000);
    fxId = HuAudFXPlay(0x14C);
    D_8011E350_3B36D0_w06 = playerIndex;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 6; i++) {
            childProcess = omAddPrcObj(func_8011394C_3A8CCC_w06, 0x4002, 0, 0);
            childProcess->user_data = (void *)i;
            HuPrcSleep(2);
        }
        HuPrcSleep(5);
    }

    HuPrcChildLink(HuPrcCurrentGet(), childProcess);
    HuPrcChildWait();
    HuAudFXStop(fxId);
    func_80055458_56058(group, 1, 0);

    for (i = 0xFF; i >= 0; i -= 0x1E) {
        func_80055458_56058(group, 0, i);
        HuPrcVSleep();
    }

    func_80055458_56058(group, 0, 0);
    HuSprGrpKill(group);
    HuSprKill(D_8011E356_3B36D6_w06);
    HuSprKill(auraSpriteId);
    HuSprKill(itemSpriteId);
    omDelPrcObj(NULL);
}

void func_80113F5C_3A92DC_w06(void) {
    s32 i;

    HuPrcSleep(10);
    for (i = 1; i < 64; i++) {
        MBStatusItemTPLvlSet(GwSystem.current_player_index, MBItemSelNoGet(), 255.0f - (i * 3.984f));
        HuPrcVSleep();
    }
    MBStatusItemTPLvlSet(GwSystem.current_player_index, MBItemSelNoGet(), 0);
}

void func_80114018_3A9398_w06(void) {
    Object *src = HuPrcCurrentGet()->user_data;
    Object *obj = MBModelLinkCreate(D_8011E358_3B36D8_w06);
    f32 angle;

    HuVecCopy3F(&obj->coords, &src->coords);
    HuVecCopyXYZ(&obj->scale, 2.0f, 2.0f, 2.0f);
    obj->velocity.x = src->velocity.x + 10.0f;
    MBModelDispOn(obj);
    angle = MBRand(360.0f);
    while (1) {
        HuPrcVSleep();
        obj->velocity.x += 1.5;
        if (src->velocity.x + 35.0f <= obj->velocity.x) {
            break;
        }
        angle += 40.0f;
        func_8008A2A0_8AEA0(HmfModelData[obj->omObj1->model[0]].mtx, angle);
    }
    MBModelKill(obj);
    omDelPrcObj(NULL);
}

void func_8011416C_3A94EC_w06(Object *arg) {
    Process *temp = omAddPrcObj(func_80114018_3A9398_w06, 0x1000, 0, 0);

    temp->user_data = arg;
}

void func_801141A8_3A9528_w06(void) {
    s32 *flag = HuPrcCurrentGet()->user_data;
    f32 angle = 0.0f;
    f32 scale = 1.0f;
    GW_SYSTEM *loc = &GwSystem;

    while (1) {
        D_8011E35C_3B36DC_w06->rot.x = -HuMathSin(angle);
        D_8011E35C_3B36DC_w06->rot.z = HuMathCos(angle);
        angle += 30.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        if (*flag != 0) {
            D_8011E35C_3B36DC_w06->scale.z = scale;
            D_8011E35C_3B36DC_w06->scale.y = scale;
            D_8011E35C_3B36DC_w06->scale.x = scale;
            scale -= 0.1f;
            if (scale <= 0.0f) {
                break;
            }
        }
        HuPrcVSleep();
    }
    D_8011E35C_3B36DC_w06->scale.x = D_8011E35C_3B36DC_w06->scale.y = D_8011E35C_3B36DC_w06->scale.z = 0.0f;
    GwPlayer[loc->current_player_index].itemNo[MBItemFind(-1, 0xF)] = -1;
    MBItemRemoveEmpty(loc->current_player_index);
    MBStatusItemIconSprReinit(loc->current_player_index);
    MBModelKill(D_8011E35C_3B36DC_w06);
    omDelPrcObj(0);
}

void func_80114338_3A96B8_w06(void) {
    s32 flag = 0;
    GW_SYSTEM *system = &GwSystem;
    void *data;
    UnkVibrateProcess *process;
    s32 positionX;
    s32 positionY;
    s32 bankCoins;
    s32 coinCount;
    s32 spriteId;
    f32 coinStep;
    f32 coinProgress;

    mbItemCursorGrpId = HuSprGrpCreate(1, 5);
    data = DataRead(D_80101040_114C60_shared_board[GwPlayer[W06CurrentPlayerIndexGet()].chr]);
    spriteId = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(mbItemCursorGrpId, 0, spriteId, 0);
    HuSprPriSet(mbItemCursorGrpId, 0, 10);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);
    HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
    MBStatusItemPosGet(-1, 0, &positionX, &positionY);
    func_80054904_55504(mbItemCursorGrpId, 0, (s16)positionX, (s16)positionY);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(1);
    MBStatusGrow(-1);
    MBItemSelNoSet(MBItemFind(-1, 0xF));
    func_801111E4_3A6564_w06();

    D_8011E35C_3B36DC_w06 = MBModelCreate(0x44, NULL);
    HuVecCopy3F(&D_8011E35C_3B36DC_w06->coords, &MBPlayerGet(-1)->player_obj->coords);
    D_8011E35C_3B36DC_w06->velocity.x = 100.0f;
    while (30.0f < D_8011E35C_3B36DC_w06->velocity.x) {
        D_8011E35C_3B36DC_w06->velocity.x -= 1.0f;
        HuPrcVSleep();
    }
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);
    omAddPrcObj(func_801141A8_3A9528_w06, 0x4002, 0, 0)->user_data = &flag;
    process = MBPlayerVibrateObjCreate(-1, 4, 5);

    bankCoins = GwSystem.bank_coins;
    coinStep = (f32)bankCoins / 30.0f;
    coinProgress = 0.0f;
    D_8011E358_3B36D8_w06 = MBModelCreate(0x19, NULL);
    MBModelTempAllocFree(D_8011E358_3B36D8_w06);
    MBModelDispOff(D_8011E358_3B36D8_w06);
    if (bankCoins != 0) {
        while (bankCoins != 0) {
            coinProgress += coinStep;
            coinCount = 0;
            while (coinProgress >= 1.0f) {
                coinProgress -= 1.0f;
                coinCount++;
            }
            if (coinCount != 0) {
                func_8011416C_3A94EC_w06(D_8011E35C_3B36DC_w06);
                if (bankCoins - coinCount < 0) {
                    coinCount = bankCoins;
                }
                bankCoins -= coinCount;
                MBPlayerCoinAdd(system->current_player_index, coinCount);
                HuAudFXPlay(0x106);
                GwSystem.bank_coins -= coinCount;
                func_80107FC0_39D340_w06();
                HuPrcSleep(5);
            }
        }
    }

    MBPlayerVibrateObjKill(process);
    flag = 1;
    HuPrcSleep(20);
    MBModelKill(D_8011E358_3B36D8_w06);
    MBVecForwardSet(&MBPlayerGet(-1)->player_obj->rot);
    MBPlayerMotionSet(-1, 5, 0);
    HuPrcSleep(5);
    func_8004ACE0_4B8E0(0x274, system->current_player_index);
    HuPrcSleep(0x2D);
    MBPlayerMotionSet(-1, -1, 2);
}

s32 func_801146F4_3A9A74_w06(u8 *arg0, s32 arg1) {
    s32 delay = 0;
    s16 inputs[MB_MAX_PLAYERS];
    u8 buttons[MB_MAX_PLAYERS];
    s32 i;
    s32 j;

    *(Unk4Bytes *)buttons = *(Unk4Bytes *)D_8011E0E0_3B3460_w06;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                delay = 1; // Required for matching register allocation.
                if (arg1 != 0) {
                    delay = D_8011E360_3B36E0_w06 + 1;
                } else {
                    delay = D_8011E364_3B36E4_w06 + 1;
                }
                inputs[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(mbDlgWinId, buttons[GwPlayer[i].pad]);
                inputs[GwPlayer[i].pad] = -1;
            }
        } else {
            inputs[GwPlayer[i].pad] = 0;
        }
    }

    if (delay != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
        for (j = 0; delay != 0; j++) {
            if (--delay == 0) {
                inputs[GwPlayer[GwSystem.current_player_index].pad] = 0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(inputs[0], inputs[1], inputs[2], inputs[3],
                                    func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(inputs[0], inputs[1], inputs[2], inputs[3], 5);
            }
        }
    } else {
        func_8005F744_60344(inputs[0], inputs[1], inputs[2], inputs[3]);
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

void func_8011498C_3A9D0C_w06(void) {
    Process *prc = HuPrcCurrentGet();
    s32 playerIdx = (s32)prc->user_data;
    s32 j;
    s32 val;
    s32 unk[2]; // unreferenced; preserves an 8-byte stack slot

    MBPlayerVibrate(((s16 *)&prc->user_data)[1], 4);

    for (val = 0x80; val > 0; val -= 0xA) {
        for (j = 0; j < 3; j++) {
            if (GwPlayer[playerIdx].itemNo[j] != -1) {
                MBStatusItemTPLvlSet(playerIdx, j, val);
            }
        }
        HuPrcVSleep();
    }

    for (j = 0; j < 3; j++) {
        if (GwPlayer[playerIdx].itemNo[j] != -1) {
            MBStatusItemTPLvlSet(playerIdx, j, 0);
        }
    }
    omDelPrcObj(NULL);
}

void func_80114A98_3A9E18_w06(void) {
    Process *process = HuPrcCurrentGet();
    s32 playerIndex = (s32)process->user_data;
    GW_SYSTEM *system = &GwSystem;
    s32 i;
    s32 alpha;
    s32 itemIndex;
    s32 xPos;
    s16 fadeGroup;
    s32 yPos;

    for (i = 0, itemIndex = 0; i < 3; i++) {
        if (GwPlayer[system->current_player_index].itemNo[i] != -1) {
            MBStatusItemScaleSet(system->current_player_index, i, 1.0f, 1.0f);
            MBStatusItemPosGet(playerIndex, itemIndex, &xPos, &yPos);
            MBStatusItemPosSet(system->current_player_index, i, xPos, yPos);
            itemIndex += (i != MBItemSelNoGet());
        }
    }

    for (alpha = 0; alpha < 0x80; alpha += 0x14) {
        for (i = 0; i < 3; i++) {
            if (GwPlayer[system->current_player_index].itemNo[i] != -1) {
                if (i != MBItemSelNoGet()) {
                    MBStatusItemTPLvlSet(system->current_player_index, i, alpha);
                }
            }
        }
        HuPrcVSleep();
    }

    for (i = 0; i < 3; i++) {
        if (GwPlayer[system->current_player_index].itemNo[i] != -1) {
            if (i != MBItemSelNoGet()) {
                MBStatusItemTPLvlSet(system->current_player_index, i, 0x80);
            }
        }
    }
    omDelPrcObj(NULL);
}

void func_80114C74_3A9FF4_w06(void) {
    char playerNames[4][16];
    u8 choices[16];
    Vec2f position;
    Vec2f target;
    s32 xPos;
    s16 fadeGroup;
    s32 yPos;
    u16 spriteId;
    Object *box;
    Process *process;
    GW_SYSTEM *system = &GwSystem;
    s32 targetPlayer;
    s32 noAnimation = 0;
    s32 itemCount;
    s32 itemSlot;
    s32 sleepTime;
    s32 i;
    s32 j;
    s32 item;
    f32 angle;
    f32 angleStep;
    f32 spinStep;
    f32 scale;
    f32 scaleY;
    f32 itemAngle;
    f32 scaleZ;
    f32 finalScale;

    func_801111E4_3A6564_w06();
    box = MBModelCreate(0x20, NULL);
    func_8001C2FC_1CEFC(box->omObj1->model[0], 0x20000, 0x20000);
    func_8001C448_1D048(box->omObj1->model[0]);
    func_8001C954_1D554(box->omObj1->model[0]);
    func_8001C514_1D114(box->omObj1->model[0]);
    Hu3DModelScaleSet(box->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&box->coords, &MBPlayerGet(-1)->player_obj->coords);
    func_8001C814_1D414(box->omObj1->model[0], 2, 1);
    box->velocity.x = 100.0f;
    HuAudFXPlay(0x142);
    while (box->velocity.x > 30.0f) {
        box->velocity.x -= 1.0f;
        HuPrcVSleep();
    }

    for (itemSlot = 0; itemSlot < 4; itemSlot++) {
        if (GwSystem.current_player_index == itemSlot) {
            playerNames[itemSlot][0] = 1;
            choices[itemSlot] = 0;
        } else {
            playerNames[itemSlot][0] = 8;
            choices[itemSlot] = 1;
        }
        func_800E2260_F5E80_shared_board(itemSlot, &playerNames[itemSlot][1]);
    }
    choices[4] = 1;
    choices[5] = 1;
    MBDlgWinInsertCreate(-1, 0x5C01, (s32)playerNames[0], (s32)playerNames[1], (s32)playerNames[2],
                         (s32)playerNames[3], 0);
    targetPlayer = func_801146F4_3A9A74_w06(choices, 1);
    MBDlgWinClose();
    MBDlgWinKill();
    if (targetPlayer == 4) {
        targetPlayer = func_800EF0D8_102CF8_shared_board(1);
    }

    itemSlot = MBItemSelNoGet();
    if (GwPlayer[GwSystem.current_player_index].itemNo[itemSlot] == 0x10 &&
        MBItemFindEmpty(GwSystem.current_player_index) == 1 && MBItemFindEmpty(targetPlayer) == 0) {
        noAnimation = 1;
    }

    if (!noAnimation) {
        HuAudFXPlay(0x149);
        func_8001C814_1D414(box->omObj1->model[0], 1, 0);
        HuPrcSleep(20);
        position.x = 160.0f;
        position.y = 84.0f;
        for (itemSlot = 0; itemSlot < 3; itemSlot++) {
            for (j = 0; j < 3; j++) {
                spriteId = 0x4790;
                if (j == itemSlot) {
                    spriteId = 0x4786;
                }
                MBStatusItemPriSet(system->current_player_index, j, spriteId);
            }
            if (GwPlayer[system->current_player_index].itemNo[itemSlot] != -1) {
                if (itemSlot != MBItemSelNoGet()) {
                    func_80111A34_3A6DB4_w06(system->current_player_index, itemSlot, 10, &position.x, 0);
                    HuPrcSleep(2);
                }
            }
        }
        func_8001C814_1D414(box->omObj1->model[0], 4, 4);
        while (HmfModelData[box->omObj1->model[0]].unk40 != 0.0f) {
            HuPrcVSleep();
        }
        HuAudFXPlay(0x150);
        HuPrcSleep(20);
        process = omAddPrcObj(func_8011498C_3A9D0C_w06, 0x4800, 0, 0);
        process->user_data = (void *)targetPlayer;
        HuAudFXPlay(0x151);

        angle = 0.0f;
        spinStep = 5.0f;
        i = 0;
        while (1) {
            box->rot.x = -HuMathSin(angle);
            box->rot.z = HuMathCos(angle);
            angle += spinStep;
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
            spinStep += 2.0f;
            if (spinStep > 45.0f) {
                spinStep = 45.0f;
                if (i++ >= 31) {
                    break;
                }
            }
            HuPrcVSleep();
        }

        i = 0;
        while (1) {
            box->rot.x = -HuMathSin(angle);
            box->rot.z = HuMathCos(angle);
            angle += spinStep;
            if (angle > 360.0f) {
                angle -= 360.0f;
                if (++i >= 2) {
                    break;
                }
            }
            spinStep -= 2.0f;
            if (spinStep < 5.0f) {
                spinStep = 5.0f;
            }
            HuPrcVSleep();
        }
        box->rot.x = 0.0f;
        box->rot.z = 1.0f;
        HuAudFXPlay(0x152);
        for (itemSlot = 0; itemSlot < 1441; itemSlot += 40) {
            scale = itemSlot;
            angleStep = HuMathSin(scale) / 1.5f + 1.0f;
            scaleY = HuMathSin(scale) / 1.5f + 1.0f;
            scaleZ = HuMathSin(scale) / 1.5f + 1.0f;
            HuVecCopyXYZ(&box->scale, angleStep, scaleY, scaleZ);
            HuPrcVSleep();
        }

        HuAudFXPlay(0x149);
        func_8001C814_1D414(box->omObj1->model[0], 4, 0);
        HuPrcSleep(20);
        process = omAddPrcObj(func_80114A98_3A9E18_w06, 0x4800, 0, 0);
        process->user_data = (void *)targetPlayer;
        itemCount = MBItemFindEmpty(targetPlayer);
        target.y = 70.0f;

        switch (itemCount) {
            case 0:
                break;
            case 1:
                target.x = 160.0f;
                MBStatusItemPosSet(targetPlayer, 0, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 10, &target.x, 1);
                HuPrcSleep(20);
                MBStatusItemPosGet(system->current_player_index, 0, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 0, 0x4790);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 7, &target.x, 2);
                break;
            case 2:
                target.x = 130.0f;
                MBStatusItemPosSet(targetPlayer, 0, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 10, &target.x, 1);
                target.x = 190.0f;
                MBStatusItemPosSet(targetPlayer, 1, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 1, 10, &target.x, 1);
                HuPrcSleep(20);
                MBStatusItemPosGet(system->current_player_index, 0, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 0, 0x4790);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 7, &target.x, 2);
                MBStatusItemPosGet(system->current_player_index, 1, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 1, 0x478F);
                func_80111A34_3A6DB4_w06(targetPlayer, 1, 7, &target.x, 2);
                break;
            default:
                target.x = 110.0f;
                MBStatusItemPosSet(targetPlayer, 0, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 10, &target.x, 1);
                target.x = 210.0f;
                MBStatusItemPosSet(targetPlayer, 1, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 1, 10, &target.x, 1);
                target.x = 160.0f;
                MBStatusItemPosSet(targetPlayer, 2, 160, 84);
                func_80111A34_3A6DB4_w06(targetPlayer, 2, 10, &target.x, 1);
                HuPrcSleep(20);
                MBStatusItemPosGet(system->current_player_index, 0, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 0, 0x4790);
                func_80111A34_3A6DB4_w06(targetPlayer, 0, 7, &target.x, 2);
                MBStatusItemPosGet(system->current_player_index, 1, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 1, 0x478F);
                func_80111A34_3A6DB4_w06(targetPlayer, 1, 7, &target.x, 2);
                MBStatusItemPosGet(system->current_player_index, 2, &xPos, &yPos);
                target.x = xPos;
                target.y = yPos;
                MBStatusItemPriSet(targetPlayer, 2, 0x478E);
                func_80111A34_3A6DB4_w06(targetPlayer, 2, 7, &target.x, 2);
                break;
        }
        HuPrcSleep(2);
    }

    itemSlot = MBItemSelNoGet();
    GwPlayer[system->current_player_index].itemNo[itemSlot] = -1;
    MBItemRemoveEmpty(system->current_player_index);
    for (itemSlot = 0; itemSlot < 3; itemSlot++) {
        item = (s8)GwPlayer[targetPlayer].itemNo[itemSlot];
        GwPlayer[targetPlayer].itemNo[itemSlot] = GwPlayer[system->current_player_index].itemNo[itemSlot];
        GwPlayer[system->current_player_index].itemNo[itemSlot] = item;
    }
    if (!noAnimation) {
        MBStatusItemSprKill(-1);
        MBStatusItemSprKill(targetPlayer);
        sleepTime = 10;
    } else {
        sleepTime = 20;
    }
    HuPrcSleep(sleepTime);
    HuAudFXPlay(0x15B);
    finalScale = 0.1f;
    for (i = 0; i < 20; i++) {
        finalScale += 0.044999998f;
        func_8001D558_1E158(box->omObj1->model[0], finalScale, finalScale * 10.0f, 1);
        HuPrcVSleep();
    }
    MBModelKill(box);

    if (noAnimation) {
        func_8004ACE0_4B8E0(0x286, system->current_player_index);
        MBPlayerMotionSet(-1, 3, 0);
        HuPrcSleep(70);
    } else {
        func_8004ACE0_4B8E0(0x274, system->current_player_index);
        MBPlayerMotionSet(-1, 5, 0);
        HuPrcSleep(50);
    }
    func_800F2388_105FA8_shared_board(-1, -1, 0, 10, 2);
    MBDlgWinInsertCreate(-1, noAnimation ? 0x3A2E : 0x3A2D,
                         mbCharNameMesTbl[GwPlayer[system->current_player_index].chr],
                         mbCharNameMesTbl[GwPlayer[targetPlayer].chr], 0, 0, 0);
    MBDlgWinClose();
    MBDlgWinKill();
}

void func_80115920_3AACA0_w06(void) {
    ModelAnimWork *data = HuPrcCurrentGet()->user_data;
    Object *obj1 = data->obj1;
    Object *obj2 = data->obj2;

    MBMotionSet(obj1, -1, data->motion);
    HuVecCopy3F(&obj1->coords, &obj2->coords);
    obj1->coords.y += obj2->velocity.x - 10.0f;
    func_800D9A40_ED660_shared_board(obj1);
    while ((u16)MBMotionCheck(obj1) == 0 && data->flag == 0) {
        HuPrcVSleep();
    }
    MBModelKill(obj1);
    omDelPrcObj(0);
}

void func_801159E0_3AAD60_w06(void) {
    s32 *processFlag = HuPrcCurrentGet()->user_data;
    Object *gameGuyModel = D_8011E368_3B36E8_w06;
    Object *model;
    Process *process;
    ModelAnimWork *work;
    s32 effect;
    f32 angle;
    f32 angleStep;
    f32 fallSpeed;
    f32 scale;
    s32 i;

    model = MBModelCreate(0x45, NULL);
    MBModelDispOff(model);
    effect = (s16)func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(effect, 1.0f, 20.0f, 1.0f);
    func_8000D018_DC18(effect, 10.0f);
    func_8001C8A8_1D4A8(effect, 1);
    HuAudFXPlay(0x24C);

    angle = 0.0f;
    angleStep = 2.0f;
    while (angleStep < 80.0f) {
        gameGuyModel->rot.x = -HuMathSin(angle);
        gameGuyModel->rot.z = HuMathCos(angle);
        angle += angleStep;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        angleStep += 1.0f;
        if (angleStep > 80.0f) {
            angleStep = 80.0f;
        }
        func_8000CFA4_DBA4(effect, gameGuyModel->coords.x,
                           gameGuyModel->coords.y + gameGuyModel->velocity.x, gameGuyModel->coords.z);
        HuPrcVSleep();
    }

    HuAudFXPlay(0x14A);
    while (gameGuyModel->velocity.x < 110.0f) {
        gameGuyModel->velocity.x += 7.0f;
        gameGuyModel->rot.x = -HuMathSin(angle);
        gameGuyModel->rot.z = HuMathCos(angle);
        angle += angleStep;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        func_8000CFA4_DBA4(effect, gameGuyModel->coords.x,
                           gameGuyModel->coords.y + gameGuyModel->velocity.x, gameGuyModel->coords.z);
        HuPrcVSleep();
    }

    *processFlag = 0;
    while (*processFlag == 0) {
        if (D_8011CB80_3B1F00_w06 != -1) {
            HuVecCopy3F(&gameGuyModel->coords,
                        &MBPlayerGet(D_8011CB80_3B1F00_w06)->player_obj->coords);
            func_8000CFA4_DBA4(effect, gameGuyModel->coords.x,
                               gameGuyModel->coords.y + gameGuyModel->velocity.x, gameGuyModel->coords.z);
        }
        HuPrcVSleep();
    }

    HuAudFXPlay(0x14B);
    fallSpeed = 3.0f;
    while (gameGuyModel->velocity.x > 30.0f) {
        gameGuyModel->velocity.x -= fallSpeed;
        if (fallSpeed > 1.0f) {
            fallSpeed -= 0.2f;
        }
        gameGuyModel->rot.x = -HuMathSin(angle);
        gameGuyModel->rot.z = HuMathCos(angle);
        angle += angleStep;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        func_8000CFA4_DBA4(effect, gameGuyModel->coords.x,
                           gameGuyModel->coords.y + gameGuyModel->velocity.x, gameGuyModel->coords.z);
        HuPrcVSleep();
    }

    while (1) {
        gameGuyModel->rot.x = -HuMathSin(angle);
        gameGuyModel->rot.z = HuMathCos(angle);
        angle += angleStep;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        if (angleStep > 15.0f) {
            angleStep -= 3.0f;
        } else {
            angleStep -= 0.5f;
        }
        if (angleStep < 1.0f) {
            break;
        }
        func_8000CFA4_DBA4(effect, gameGuyModel->coords.x,
                           gameGuyModel->coords.y + gameGuyModel->velocity.x, gameGuyModel->coords.z);
        HuPrcVSleep();
    }

    func_8000D044_DC44(effect);
    process = omAddPrcObj(func_80115920_3AACA0_w06, 0x4800, 0, 0x40);
    work = HuMemMemoryAlloc(process->heap, 0x20);
    process->user_data = work;
    work->obj1 = model;
    work->obj2 = gameGuyModel;
    *(s32 *)&work->unk_08 = 0;
    work->flag = 0;
    HuPrcSleep(3);
    *processFlag = 0;
    HuAudFXPlay(0x24D);

    i = 0;
    scale = 0.1f;
    for (; i < 20; i++) {
        scale += 0.044999998f;
        func_8001D558_1E158(gameGuyModel->omObj1->model[0], scale, scale * 10.0f, 1);
        HuPrcVSleep();
    }
    MBModelKill(gameGuyModel);
    omDelPrcObj(NULL);
}

void func_80115F10_3AB290_w06(void) {
    Object *coinModel;
    Object *gameGuyModel;
    Object *playerObj;
    Process *process;
    GW_SYSTEM *system;
    s32 choice;
    s32 itemSlot;
    s32 rewardIndex;
    s32 randomValue;
    s32 rewardAmount;
    s32 i;
    struct {
        s32 processFlag;
        s32 pad;
        char rewardText[0x10];
    } locals;

    system = &GwSystem;
    func_801111E4_3A6564_w06();
    itemSlot = MBItemFind(-1, 0x11);
    GwPlayer[W06CurrentPlayerIndexGet()].itemNo[itemSlot] = -1;
    MBItemRemoveEmpty(W06CurrentPlayerIndexGet());
    MBStatusItemIconSprReinit(W06CurrentPlayerIndexGet());
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);

    coinModel = MBModelCreate(0x3E, 0);
    Hu3DModelScaleSet(coinModel->omObj1->model[0], 0, 0, 0);
    MBModelTempAllocFree(coinModel);
    coinModel->velocity.x = 30.0f;
    MBModelDispOff(coinModel);

    gameGuyModel = MBModelCreate(0x43, 0);
    D_8011E368_3B36E8_w06 = gameGuyModel;
    func_8001C2FC_1CEFC(gameGuyModel->omObj1->model[0], 0x20000, 0x20000);
    func_8001C448_1D048(gameGuyModel->omObj1->model[0]);
    func_8001C954_1D554(gameGuyModel->omObj1->model[0]);
    func_8001C514_1D114(gameGuyModel->omObj1->model[0]);
    HuVecCopy3F(&gameGuyModel->coords, &MBPlayerGet(-1)->player_obj->coords);
    func_8001C814_1D414(gameGuyModel->omObj1->model[0], 2, 1);
    gameGuyModel->velocity.x = 100.0f;
    HuAudFXPlay(0x14B);
    while (gameGuyModel->velocity.x > 30.0f) {
        gameGuyModel->velocity.x -= 1.0f;
        HuPrcVSleep();
    }

selectPlayer:
    MBDlgWinInsertCreate(-1, 0x5C00, GwPlayer[0].chr + 0x1C00, GwPlayer[1].chr + 0x1C00,
                         GwPlayer[2].chr + 0x1C00, GwPlayer[3].chr + 0x1C00, 0);
    choice = func_8010B4C4_3A0844_w06(0, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    if (choice < 0) {
        goto invalidChoice;
    }
    if (choice < 4) {
        goto validChoice;
    }
    if (choice == 4) {
        choice = func_800EF0D8_102CF8_shared_board(0);
    } else {
    invalidChoice:
        func_80106B38_39BEB8_w06();
        D_800CB99C_CC59C = 1;
        func_80049FB8_4ABB8();
        goto selectPlayer;
    }

validChoice:
    locals.processFlag = 1;
    process = omAddPrcObj(func_801159E0_3AAD60_w06, 0x4002, 0, 0);
    process->user_data = &locals.processFlag;
    while (locals.processFlag != 0) {
        HuPrcVSleep();
    }

    if (choice != system->current_player_index) {
        WipeCreateOut(0, 0x10);
        HuPrcSleep(0x10);
        D_8011CB80_3B1F00_w06 = choice;
        MBCameraFocusModeSet(2);
        MBCameraFocusStaticPosSet(&MBPlayerGet(choice)->player_obj->coords);
        MBCameraPos3DSet(&MBPlayerGet(choice)->player_obj->coords);
        HuPrcVSleep();
        HuPrcSleep(10);
        WipeCreateIn(0, 0x10);
        HuPrcSleep(0x10);
    } else {
        HuPrcSleep(30);
        D_8011CB80_3B1F00_w06 = choice;
    }

    locals.processFlag = 1;
    while (locals.processFlag != 0) {
        HuPrcVSleep();
    }

    playerObj = MBPlayerGet(choice)->player_obj;
    process = func_800EDB98_1017B8_shared_board(coinModel, 5.0f, 2.0f);
    HuVecCopy3F(&coinModel->coords, &playerObj->coords);
    func_800D9A40_ED660_shared_board(coinModel);
    coinModel->scale.x = coinModel->scale.y = coinModel->scale.z = 0.0f;
    while (coinModel->scale.x < 1.0f) {
        coinModel->scale.x = coinModel->scale.y = coinModel->scale.z += 0.2f;
        HuPrcVSleep();
    }

    MBPlayerVibrate(choice, 4);
    HuAudFXPlay(0x2A1);
    if (GwPlayer[choice].coin != 0) {
        func_8010B748_3A0AC8_w06(10, 0x2F00, -1, choice);
        GwPlayer[choice].gameCoin = GwPlayer[choice].coin;
        MBCoinChangeCreate(choice, -GwPlayer[choice].coin);
        MBCoinTakeCreate(choice, -GwPlayer[choice].coin);
        HuPrcSleep(30);
        func_8010B748_3A0AC8_w06(10, 0x2F02, -1, choice);
        omDelPrcObj(process);
        while (coinModel->velocity.x >= 10.0f) {
            coinModel->velocity.x -= 2.0f;
            HuPrcVSleep();
        }
        HuPrcSleep(30);
        while (coinModel->velocity.x < 100.0f) {
            coinModel->velocity.x += 4.0f;
            playerObj->velocity.x += 4.0f;
            HuPrcVSleep();
        }
    } else {
        func_8010B748_3A0AC8_w06(10, 0x2F01, -1, choice);
        omDelPrcObj(process);
        while (coinModel->velocity.x <= 100.0f) {
            coinModel->velocity.x += 4.0f;
            HuPrcVSleep();
        }
        MBModelKill(coinModel);
        WipeCreateOut(9, 0x10);
        HuPrcSleep(0x11);
        MBCameraFocusModeSet(1);
        MBCameraPos3DSet(&MBPlayerGet(-1)->player_obj->coords);
        HuPrcSleep(5);
        WipeCreateIn(9, 0x10);
        HuPrcSleep(0x11);
        return;
    }

    if (MBPlayerComCheck((s16)choice) != 0 && system->show_com_minigames != 0) {
        WipeCreateOut(9, 0x10);
        HuPrcSleep(0x11);
        MBModelKill(coinModel);
        func_800EE688_1022A8_shared_board(playerObj, 0, 0);
        playerObj->velocity.x = 0.0f;
        HuPrcSleep(5);
        WipeCreateIn(9, 0x10);
        HuPrcSleep(0x11);
        randomValue = MBRand(100.0f) + 1;
        for (rewardIndex = 0; rewardIndex < 7; rewardIndex++) {
            if (randomValue <= D_8011CB8C_3B1F0C_w06[rewardIndex].threshold) {
                break;
            }
        }
        if (D_8011CB8C_3B1F0C_w06[rewardIndex].multiplier != 0) {
            rewardAmount = GwPlayer[choice].gameCoin * D_8011CB8C_3B1F0C_w06[rewardIndex].multiplier;
            if (rewardAmount >= 1000) {
                rewardAmount = 999;
            }
            sprintf(locals.rewardText, D_8011E14C_3B34CC_w06, rewardAmount);
            MBDlgWinInsertCreate(-1, 0x2F03, (s32)locals.rewardText, 0, 0, 0, 0);
            MBDlgWinClose();
            MBDlgWinKill();
            MBCoinChangeCreate(choice, rewardAmount);
            MBCoinTakeCreate(choice, rewardAmount);
            HuPrcSleep(20);
        } else {
            MBDlgWinExec(-1, 0x2F04);
        }
        HuPrcSleep(10);
        WipeCreateOut(9, 0x10);
        HuPrcSleep(0x11);
        MBCameraFocusModeSet(1);
        MBCameraPos3DSet(&MBPlayerGet(-1)->player_obj->coords);
        HuPrcSleep(5);
        WipeCreateIn(9, 0x10);
        HuPrcSleep(0x11);
        return;
    }

    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
        GWBoardFlagSet(0x17);
    } else {
        GWBoardFlagClear(0x17);
    }
    for (i = 0; i < 4; i++) {
        GwPlayer[i].group = 1;
    }
    MBPlayerGet(choice)->group = 0;
    randomValue = MBRand(100.0f);
    for (rewardIndex = 0; (u32)rewardIndex < 3; rewardIndex++) {
        if (randomValue < D_8011CB88_3B1F08_w06[rewardIndex]) {
            break;
        }
    }
    if (rewardIndex == 3) {
        rewardIndex = 2;
    }
    system->minigame_index = D_8011CB84_3B1F04_w06[rewardIndex];
    GwSystem.playerIndexVisitingBowser = choice;
    func_800FC998_1105B8_shared_board();
    func_8004A0E0_4ACE0();
    func_800FF7F0_113410_shared_board(2);
    HuPrcSleep(-1);
}

void func_8011681C_3ABB9C_w06(s32 arg0, s32 arg1, f32 *arg2) {
    f32 curX;
    f32 curY;
    f32 stepX;
    f32 stepY;

    MBStatusSprPosGet((s16)arg0, 0, &curX, &curY);
    stepX = (arg2[0] - curX) / arg1;
    stepY = (arg2[1] - curY) / arg1;
    while (arg1 != 0) {
        curX += stepX;
        curY += stepY;
        func_80054904_55504(arg0, 0, curX, curY);
        HuPrcVSleep();
        arg1--;
    }
    func_80054904_55504(arg0, 0, arg2[0], arg2[1]);
}

void func_80116954_3ABCD4_w06(void) {
    s32 idx;
    s32 divisor;
    s32 i;

    idx = (s32)HuPrcCurrentGet()->user_data;
    divisor = 10;

    switch (idx) {
        case 0:
            func_80054904_55504(D_8011E370_3B36F0_w06[idx], 0, 0xB1, 0x2C);
            break;
        case 1:
            func_80054904_55504(D_8011E370_3B36F0_w06[idx], 0, 0x7A, 0x39);
            break;
        default:
            func_80054904_55504(D_8011E370_3B36F0_w06[idx], 0, 0xA0, 0x98);
            divisor = 30;
            break;
    }

    HuSprAttrReset(D_8011E370_3B36F0_w06[idx], 0, 0x8000U);
    for (i = 0; i < 255; i += 255 / divisor) {
        func_80055458_56058(D_8011E370_3B36F0_w06[idx], 0, i & 0xFFFF);
        HuPrcVSleep();
    }

    func_80055458_56058(D_8011E370_3B36F0_w06[idx], 0, 0xFF);
    omDelPrcObj(0);
}

void func_80116AC4_3ABE44_w06(omObjData *obj) {
    RGB2 sp18;
    RGB2 sp28;
    s32 i;
    s32 j;

    for (i = 0; i <= 0; i++) {
        sp18.r = D_8011CBA8_3B1F28_w06[i].r;
        sp18.g = D_8011CBA8_3B1F28_w06[i].g;
        sp18.b = D_8011CBA8_3B1F28_w06[i].b;

        sp28.r = (D_8011CBA8_3B1F28_w06[i + 1].r - sp18.r) / 30;
        sp28.g = (D_8011CBA8_3B1F28_w06[i + 1].g - sp18.g) / 30;
        sp28.b = (D_8011CBA8_3B1F28_w06[i + 1].b - sp18.b) / 30;

        for (j = 0; j < 30; j++) {
            func_80055420_56020(D_8011E37E_3B36FE_w06, 0, sp18.r, sp18.g, sp18.b);
            sp18.r += sp28.r;
            sp18.g += sp28.g;
            sp18.b += sp28.b;
            HuPrcVSleep();
        }
        func_80055420_56020(D_8011E37E_3B36FE_w06, 0, D_8011CBA8_3B1F28_w06[i + 1].r, D_8011CBA8_3B1F28_w06[i + 1].g, D_8011CBA8_3B1F28_w06[i + 1].b);
        HuPrcSleep(0xA);
    }

    omDelPrcObj(0);
}

void func_80116C8C_3AC00C_w06(void) {
    s32 *state = HuPrcCurrentGet()->user_data;
    Object *model;
    f32 scale;
    f32 angle;
    f32 wait_angle_step;

    HuAudFXPlay(0x143);
    model = D_8011E380_3B3700_w06;
    func_800D9A40_ED660_shared_board(model);

    angle = 0.0f;
    for (scale = 1.0f; scale < 18.0f; scale = (f32)((f64)scale + 0.8)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    if (*state != 1) {
        wait_angle_step = 20.0f;
        while (*state != 1) {
            func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
            angle += wait_angle_step;
            HuPrcVSleep();
        }
    }

    for (; scale < 40.0f; scale = (f32)((f64)scale + 0.8)) {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
        angle += 20.0f;
        HuPrcVSleep();
    }

    if (*state != 2) {
        scale = 20.0f;
        while (*state != 2) {
            func_8008A430_8B030(&HmfModelData[model->omObj1->model[0]].mtx, angle);
            angle += scale;
            HuPrcVSleep();
        }
    }

    MBModelKill(model);
    omDelPrcObj(0);
}

void func_80116F10_3AC290_w06(void) {
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
        D_8011E370_3B36F0_w06[i] = HuSprGrpCreate(1, 0);
        temp_v0 = DataRead((i + 0x1BB) | 0x130000);
        sp18[i] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        func_80055024_55C24(D_8011E370_3B36F0_w06[i], 0, sp18[i], 0);
        HuSprPriSet(D_8011E370_3B36F0_w06[i], 0, 0x4780U);
        HuSprAttrSet(D_8011E370_3B36F0_w06[i], 0, 0x980CU);
        func_80055458_56058(D_8011E370_3B36F0_w06[i], 0, 0U);
        func_80055420_56020(D_8011E370_3B36F0_w06[i], 0, 0xFF, 0xFF, 0);
    }
    temp_v0_3 = MBModelCreate(0x46, NULL);
    D_8011E380_3B3700_w06 = temp_v0_3;
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
    func_8011681C_3ABB9C_w06(temp_s4, 0x1E, sp28);
    GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] = -1;
    MBItemRemoveEmpty(system->current_player_index);
    MBStatusShrink(CUR_PLAYER);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(CUR_PLAYER);
    HuPrcSleep(0x1E);
    sp28[0] = 203.0f;
    sp28[1] = 44.0f;
    func_8011681C_3ABB9C_w06(temp_s4, 0xA, sp28);
    temp_v0_4 = omAddPrcObj(func_80116954_3ABCD4_w06, 0x4002U, 0, 0);
    temp_v0_4->user_data = NULL;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[0] -= 76.0f;
    HuAudFXPlay(0x14D);
    func_8011681C_3ABB9C_w06(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    temp_v0_4 = omAddPrcObj(func_80116954_3ABCD4_w06, 0x4002U, 0, 0);
    temp_v0_4->user_data = (void *)1;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[1] += 64.0f;
    HuAudFXPlay(0x14D);
    func_8011681C_3ABB9C_w06(temp_s4, 0xA, sp28);
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
            temp_v0_4 = omAddPrcObj(func_80116954_3ABCD4_w06, 0x4002U, 0, 0);
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
        HuSprAttrSet(D_8011E370_3B36F0_w06[i], 0, 0x8000);
    }

    HuSprAttrReset(D_8011E37E_3B36FE_w06, 0, 0x8000U);
    func_80055458_56058(D_8011E37E_3B36FE_w06, 0, 0xFFU);
    func_80054904_55504(D_8011E37E_3B36FE_w06, 0, 0xA0, 0x78);
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_80116AC4_3ABE44_w06, 0x4002U, 0, 0));
    sp40 = 0;
    omAddPrcObj(func_80116C8C_3AC00C_w06, 0x4002U, 0, 0)->user_data = &sp40;
    HuPrcChildWait();
    HuAudFXPlay(0x14F);
    temp_s1_2 = MBPlayerVibrateObjCreate(-1, 4, 5);

    for (i = 0; i <= 2880; i += 50) {
        temp_f20 = (HuMathSin(i) / 2.0f) + 1.0f;
        HuSprScaleSet(D_8011E37E_3B36FE_w06, 0, temp_f20, (HuMathSin(i) / 3.0f) + 1.0f);
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
        HuSprScaleSet(D_8011E37E_3B36FE_w06, 0, var_f20, var_f20);
        HuPrcVSleep();
    }

    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    sp40 = 2;
    for (i = 0; i < 4; i++) {
        HuSprGrpKill(D_8011E370_3B36F0_w06[i]);
        HuSprKill(sp18[i]);
    }

    WipeCreateIn(0xB, 0x5A);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    MBDlgResultWinExec(0x3A23);
    GwSystem.wackyWatchUsedState = 2;
}

void func_80117814_3ACB94_w06(s16 *arg0, s32 *arg1, s32 *arg2) {
    s32 i;
    s32 unused[2];
    GW_PLAYER *player;
    s16 masu;
    s8 *currentPlayerIndex;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    i = 0;
    func_80106B94_39BF14_w06();
    player = MBPlayerGet(GwSystem.current_player_index);
    masu = MBMasuLinkMasuIdGet(player->blink, player->bidx);
    {
        s32 j;
        s16 *row;

        for (; i < 3; i++) {
            j = 0;
            row = arg0;
            row = (s16 *)((i * 6) + (s32)arg0);

            while (j < 2 && row[j] != masu) {
                j++;
            }
            if (j == 2) {
                break;
            }
        }
    }

    {
        s16 *nameData = arg0 + i * 3;

        arg1 += i * 3;
        currentPlayerIndex = &GwSystem.current_player_index;
        arg0 = (s16 *)func_800D76A0_EB2C0_shared_board(*currentPlayerIndex, nameData);
    }
    func_800D742C_EB04C_shared_board((UnkEA790Struct *)arg0, *currentPlayerIndex, 0);
    {
        s32 j;

        if (MBPlayerComCheck(-1) != 0) {
            j = 0;
            i = (s16)MBComTreeExec((void *)arg2[i]);
            if (i > 0) {
                do {
                    func_800D7250_EAE70_shared_board((UnkEA790Struct *)arg0, -2);
                    j++;
                } while (j < i);
            }
            func_800D7250_EAE70_shared_board((UnkEA790Struct *)arg0, -4);
        }
        j = func_800D7518_EB138_shared_board((UnkEA790Struct *)arg0);
        func_800D6CA0_EA8C0_shared_board((UnkEA790Struct *)arg0);
        func_80106C64_39BFE4_w06();
        if (j != 0) {
            arg1 = (s32 *)((s16 *)arg1 + 3);
        }
    }

    MBMoveNextMasuSet(-1, ((s16 *)arg1)[0], ((s16 *)arg1)[1]);
    switch (((s16 *)arg1)[2]) {
        case 0:
            player->rev &= ~1;
            break;
        case 1:
            player->rev |= 1;
            break;
    }
}

void func_80117A0C_3ACD8C_w06(s32 arg0) {
    if (D_8011E398_3B3718_w06[arg0] != NULL) {
        omDelObj(D_8011E398_3B3718_w06[arg0]);
        D_8011E398_3B3718_w06[arg0] = NULL;
    }
    if (D_8011E388_3B3708_w06[arg0] != NULL) {
        MBModelKill(D_8011E388_3B3708_w06[arg0]);
        D_8011E388_3B3708_w06[arg0] = NULL;
    }
}

void func_80117A84_3ACE04_w06(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        omObjData *obj = D_8011E398_3B3718_w06[i];

        if (obj != NULL) {
            omDelObj(obj);
            D_8011E398_3B3718_w06[i] = NULL;
        }
    }
}

void func_80117AE8_3ACE68_w06(omObjData *obj) {
    s32 playerIdx = obj->work[0];

    if (GwSystem.current_player_index == 4) {
        if (obj->work[2] == 0) {
            if (obj->work[1] != 0) {
                obj->work[1] -= 1;
                if (obj->work[1] != 0) {
                    return;
                }
                obj->work[2] = 1;
            } else {
                obj->work[1] = 40;
                return;
            }
        }
    }

    {
        GW_PLAYER *player = MBPlayerGet(playerIdx);
        Object *effectObj = D_8011E388_3B3708_w06[playerIdx];

        HuVecCopy3F(&effectObj->coords, &player->player_obj->coords);
        effectObj->velocity.x = player->player_obj->velocity.x + 20.0f;
        HuVecCopy3F(&effectObj->rot, &player->player_obj->rot);
        effectObj->coords.x += HuMathSin(obj->rot.x) * obj->trans.x;
        effectObj->coords.z += HuMathCos(obj->rot.x) * obj->trans.x;
        obj->rot.x += 5.0f;
        if (obj->rot.x >= 360.0f) {
            obj->rot.x -= 360.0f;
        }
        if (obj->trans.x <= 5.0f) {
            obj->trans.x += 0.25f;
        }
        if (player->player_obj->flags & 8) {
            func_800D9A40_ED660_shared_board(effectObj);
        } else {
            MBModelDispOff(effectObj);
        }
    }
}

void func_80117C94_3AD014_w06(s32 arg0, s32 arg1) {
    GW_PLAYER *player = MBPlayerGet(arg0);
    Object *obj;
    u8 modelId;

    if (D_8011E388_3B3708_w06[arg0] == NULL) {
        switch (arg1) {
            case 0:
                modelId = 0x3F;
                break;
            case 1:
                modelId = 0x40;
                break;
            case 2:
                modelId = 0x41;
                break;
            default:
                modelId = 0x42;
                break;
        }

        obj = MBModelCreate(modelId, NULL);
        MBModelTempAllocFree(obj);
        D_8011E388_3B3708_w06[arg0] = obj;
        obj->flags |= 2;
        HuVecCopy3F(&obj->coords, &player->player_obj->coords);
        obj->velocity.x = 20.0f;
        MBVecForwardSet(&obj->rot);
    } else {
        func_800D9A40_ED660_shared_board(D_8011E388_3B3708_w06[arg0]);
    }
}

void func_80117D94_3AD114_w06(s32 arg) {
    D_8011E398_3B3718_w06[arg] = omAddObj(0x3FFF, 0, 0, -1, func_80117AE8_3ACE68_w06);
    D_8011E398_3B3718_w06[arg]->work[0] = arg;
    D_8011E398_3B3718_w06[arg]->work[1] = 0;
    D_8011E398_3B3718_w06[arg]->work[2] = 0;
    D_8011E398_3B3718_w06[arg]->rot.x = (f32)MBRand(360.0f);
    D_8011E398_3B3718_w06[arg]->trans.x = 0;
}

void func_80117E30_3AD1B0_w06(void) {
    s32 i;
    s32 idx;

    for (i = 0; i < 4; i++) {
        D_8011E398_3B3718_w06[i] = NULL;
        D_8011E388_3B3708_w06[i] = NULL;
        idx = -!(MBPlayerGet(i)->rev & 0x2);
        if (MBPlayerGet(i)->rev & 0x4) {
            idx = 1;
        }
        if (MBPlayerGet(i)->rev & 0x20) {
            idx = 2;
        }
        if (MBPlayerGet(i)->rev & 0x40) {
            idx = 3;
        }
        if (idx != -1) {
            func_80117C94_3AD014_w06(i, idx);
            func_80117D94_3AD114_w06(i);
        }
    }
    func_800F8D54_10C974_shared_board(func_80117A84_3ACE04_w06);
}

void func_80117F30_3AD2B0_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 *slowDiceFlags = &loc->slow_dice_flags;
    f32 scale;

    if ((((*slowDiceFlags >> loc->current_player_index) & 1))) {
        GWBoardFlagSet(0x10);
        *slowDiceFlags &= ~(1 << loc->current_player_index);
        if ((player->rev & 0x20) || ((*(u32 *)&player->nnidx & 0xA) == 8)) {
            MBDlgWinExec(-1, 0x4219);
        } else {
            MBDlgWinExec(-1, 0x3A07);
        }

        if (player->rev & 2) {
            if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
                for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                    HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                    HuPrcVSleep();
                }
            }
            func_80117A0C_3ACD8C_w06(loc->current_player_index);
        }
        if (player->rev & 8) {
            if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
                for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                    HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                    HuPrcVSleep();
                }
            }
            func_80117A0C_3ACD8C_w06(loc->current_player_index);
        }
        player->rev &= 0xD5;
    }
}

void func_8011813C_3AD4BC_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    s16 *slowDiceFlags = &loc->slow_dice_flags;
    GW_PLAYER *player = MBPlayerGet(-1);
    f32 scale;

    if (player->rev & 8) {
        func_800DCA64_F0684_shared_board(loc->current_player_index);
        GWBoardFlagSet(0x10);
        *slowDiceFlags &= ~(1 << loc->current_player_index);
        MBDlgWinExec(-1, 0x4219);
        if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
            for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                HuPrcVSleep();
            }
        }
        func_80117A0C_3ACD8C_w06(loc->current_player_index);
        player->rev &= 0xD7;
        MBPlayerVibrate(-1, 2);
        func_800DC128_EFD48_shared_board(loc->current_player_index);
        HuPrcSleep(0xF);
    }
}

void func_8011829C_3AD61C_w06(void) {
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

void func_801182EC_3AD66C_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player;
    s32 choice;
    s16 targetPlayer;
    s32 previousPlayer;
    s8 *currentPlayerIndex;
    f32 scale;
    f32 hudScale;

    MBDlgWinInsertCreate(-1, 0x5C01, GwPlayer[0].chr + 0x1C00, GwPlayer[1].chr + 0x1C00,
                         GwPlayer[2].chr + 0x1C00, GwPlayer[3].chr + 0x1C00, 0);
    choice = func_8010B4C4_3A0844_w06(2, D_8011E3AC_3B372C_w06);
    MBDlgWinClose();
    MBDlgWinKill();
    if (choice < 4) {
        if (choice >= 0) {
            targetPlayer = choice;
        } else {
            targetPlayer = func_800EF0D8_102CF8_shared_board(0);
        }
    } else {
        targetPlayer = func_800EF0D8_102CF8_shared_board(0);
    }

    GwSystem.slow_dice_flags |= 1 << targetPlayer;
    player = MBPlayerGet((s16)targetPlayer);
    scale = 1.0f;
    hudScale = 1.0f;
    while (scale > 0.0f) {
        scale -= 0.1f;
        hudScale += 0.07f;
        MBStatusItemScaleSet(loc->current_player_index, MBItemSelNoGet(), scale,
                             hudScale);
        HuPrcVSleep();
    }
    MBStatusItemTPLvlSet(loc->current_player_index, MBItemSelNoGet(), 0);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);

    if ((s16)targetPlayer != loc->current_player_index) {
        WipeCreateOut(0, 0x10);
        HuPrcSleep(0x10);
        MBCameraFocusModeSet(2);
        MBCameraFocusStaticPosSet(&player->player_obj->coords);
        MBCameraPos3DSet(&player->player_obj->coords);
        HuPrcVSleep();
        WipeCreateIn(0, 0x10);
        D_800A12D8_A1ED8 = 1;
        HuPrcSleep(0x10);
    }

    func_80117A0C_3ACD8C_w06((s16)targetPlayer);
    player->rev = (player->rev & 0x99) | 2;
    func_80117C94_3AD014_w06((s16)targetPlayer, 0);
    for (scale = 0.0f; scale <= 1.0f; scale += 0.08f) {
        HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, 1.0f, 1.0f, 1.0f);

    if ((s16)targetPlayer == loc->current_player_index) {
        MBPlayerMotionSet((s16)targetPlayer, 4, 2);
    } else {
        MBMotionSet(MBPlayerGet((s16)targetPlayer)->player_obj, 4, 2);
    }
    CharFXPlay(0x286, GwPlayer[(s16)targetPlayer].chr);
    func_80117D94_3AD114_w06((s16)targetPlayer);
    {
        void *data = MBPlayerVibrateObjCreate((s16)targetPlayer, 1, 5);
        Process *process = omAddPrcObj(func_8011829C_3AD61C_w06, 0x4002, 0, 0);

        process->user_data = data;
    }
    HuPrcSleep(0x14);

    previousPlayer = (s8) * (volatile u8 *)&loc->current_player_index;
    loc->current_player_index = targetPlayer;
    if (player->rev & 0x80) {
        MBDlgWinExec(-1, 0x3A09);
    }
    MBDlgWinExec(-1, 0x3A06);
    asm volatile("" : "=r"(previousPlayer) : "0"(previousPlayer));
    loc->current_player_index = previousPlayer;
    if ((s16)targetPlayer == (s8)previousPlayer) {
        MBPlayerMotionSet(-1, -1, 2);
    } else {
        MBMotionSet(MBPlayerGet((s16)targetPlayer)->player_obj, -1, 2);
        D_800A12D8_A1ED8 = 0;
    }

    if ((s16)targetPlayer != loc->current_player_index) {
        WipeCreateOut(0, 0x10);
        HuPrcSleep(0x10);
        MBCameraFocusModeSet(1);
        MBCameraPos3DSet(&MBPlayerGet(-1)->player_obj->coords);
        HuPrcVSleep();
        WipeCreateIn(0, 0x10);
        HuPrcSleep(0x10);
    }

    if ((s16)targetPlayer == loc->current_player_index) {
        GWBoardFlagSet(0x10);
        MBDlgWinExec(-1, 0x3A07);
        for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
            HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, scale, scale, scale);
            HuPrcVSleep();
        }
        HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, 0.0f, 0.0f, 0.0f);
        func_80117A0C_3ACD8C_w06(loc->current_player_index);
        currentPlayerIndex = &GwSystem.current_player_index;
        func_800DCA64_F0684_shared_board(*currentPlayerIndex);
        MBPlayerVibrate(-1, 2);
        func_800DC128_EFD48_shared_board(*currentPlayerIndex);
        HuPrcSleep(0xF);
        loc = GW_SYSTEM_FROM_CURRENT_PLAYER(currentPlayerIndex);
        loc->slow_dice_flags &= ~(1 << *currentPlayerIndex);
        player->rev &= ~2;
    }
}

void func_80118864_3ADBE4_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player = MBPlayerGet(-1);
    f32 scale;

    if (player->rev & 0x80) {
        if ((player->rev & 0x40) || ((*(int *)&player->nnidx & 0x14) == 0x10)) {
            MBDlgWinExec(-1, 0x421C);
        } else {
            MBDlgWinExec(-1, 0x3A03);
        }
        if (player->rev & 4) {
            if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
                for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                    HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                    HuPrcVSleep();
                }
            }
            func_80117A0C_3ACD8C_w06(loc->current_player_index);
        }
        if (player->rev & 0x10) {
            if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
                for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                    HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                    HuPrcVSleep();
                }
            }
            func_80117A0C_3ACD8C_w06(loc->current_player_index);
        }
        player->rev &= 0xAB;
    }
}

void func_80118A34_3ADDB4_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player = MBPlayerGet(-1);
    f32 scale;

    if (player->rev & 0x10) {
        func_800DCA64_F0684_shared_board(loc->current_player_index);
        MBDlgWinExec(-1, 0x421C);
        if (D_8011E388_3B3708_w06[loc->current_player_index] != NULL) {
            for (scale = 1.0f; scale >= 0.0f; scale -= 0.08f) {
                HuVecCopyXYZ(&D_8011E388_3B3708_w06[loc->current_player_index]->scale, scale, scale, scale);
                HuPrcVSleep();
            }
        }
        func_80117A0C_3ACD8C_w06(loc->current_player_index);
        player->rev &= 0xAF;
        MBPlayerVibrate(-1, 2);
        func_800DC128_EFD48_shared_board(loc->current_player_index);
        HuPrcSleep(0xF);
    }
}

void func_80118B6C_3ADEEC_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player;
    s32 choice;
    s16 targetPlayer;
    s16 previousPlayer;
    f32 scale;
    f32 hudScale;
    void *data;

    MBDlgWinInsertCreate(-1, 0x5C01, GwPlayer[0].chr + 0x1C00, GwPlayer[1].chr + 0x1C00,
                         GwPlayer[2].chr + 0x1C00, GwPlayer[3].chr + 0x1C00, 0);
    choice = func_8010B4C4_3A0844_w06(2, D_8011E3A8_3B3728_w06);
    MBDlgWinClose();
    MBDlgWinKill();
    if (choice < 4) {
        if (choice >= 0) {
            targetPlayer = choice;
        } else {
            targetPlayer = func_800EF0D8_102CF8_shared_board(0);
        }
    } else {
        targetPlayer = func_800EF0D8_102CF8_shared_board(0);
    }

    player = MBPlayerGet((s16)targetPlayer);
    player->rev |= 0x80;
    scale = 1.0f;
    hudScale = 1.0f;
    while (scale > 0.0f) {
        scale -= 0.1f;
        hudScale += 0.07f;
        MBStatusItemScaleSet(loc->current_player_index, MBItemSelNoGet(), scale,
                             hudScale);
        HuPrcVSleep();
    }
    MBStatusItemTPLvlSet(loc->current_player_index, MBItemSelNoGet(), 0);

    if ((s16)targetPlayer != loc->current_player_index) {
        WipeCreateOut(0, 0x10);
        HuPrcSleep(0x10);
        MBCameraFocusModeSet(2);
        MBCameraFocusStaticPosSet(&player->player_obj->coords);
        MBCameraPos3DSet(&player->player_obj->coords);
        HuPrcVSleep();
        WipeCreateIn(0, 0x10);
        D_800A12D8_A1ED8 = 1;
        HuPrcSleep(0x10);
    }

    func_80117A0C_3ACD8C_w06((s16)targetPlayer);
    player->rev = (player->rev & 0x99) | 4;
    MBPlayerVibrate((s16)targetPlayer, 3);
    func_80117C94_3AD014_w06((s16)targetPlayer, 1);
    for (scale = 0.0f; scale <= 1.0f; scale += 0.08f) {
        HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&D_8011E388_3B3708_w06[(s16)targetPlayer]->scale, 1.0f, 1.0f, 1.0f);

    if ((s16)targetPlayer == loc->current_player_index) {
        MBPlayerMotionSet((s16)targetPlayer, 4, 2);
    } else {
        MBMotionSet(MBPlayerGet((s16)targetPlayer)->player_obj, 4, 2);
    }
    CharFXPlay(0x286, GwPlayer[(s16)targetPlayer].chr);
    data = MBPlayerVibrateObjCreate((s16)targetPlayer, 1, 5);
    func_80117D94_3AD114_w06((s16)targetPlayer);
    {
        Process *process = omAddPrcObj(func_8011829C_3AD61C_w06, 0x4002, 0, 0);

        process->user_data = data;
    }
    HuPrcSleep(0x14);

    previousPlayer = (s8) * (volatile u8 *)&loc->current_player_index;
    loc->current_player_index = targetPlayer;
    if (previousPlayer == targetPlayer && 3 == func_800DEB2C_F274C_shared_board(previousPlayer)) {
        MBDlgWinExec(-1, 0x3A05);
    } else if (GwSystem.slow_dice_flags & (1 << targetPlayer)) {
        MBDlgWinExec(-1, 0x3A05);
    }
    MBDlgWinExec(-1, 0x3A02);
    loc->current_player_index = previousPlayer;
    if ((s16)targetPlayer == (s8)previousPlayer) {
        MBPlayerMotionSet(-1, -1, 2);
    } else {
        MBMotionSet(MBPlayerGet((s16)targetPlayer)->player_obj, -1, 2);
        D_800A12D8_A1ED8 = 0;
    }

    if ((s16)targetPlayer != loc->current_player_index) {
        WipeCreateOut(0, 0x10);
        HuPrcSleep(0x10);
        MBCameraFocusModeSet(1);
        MBCameraPos3DSet(&MBPlayerGet(-1)->player_obj->coords);
        HuPrcVSleep();
        WipeCreateIn(0, 0x10);
        HuPrcSleep(0x10);
    }

    if ((s16)targetPlayer == loc->current_player_index) {
        func_80118864_3ADBE4_w06();
    }
}

void func_80118FF0_3AE370_w06(void) {
    char playerNames[4][16];
    u8 choices[16];
    Object *chest;
    Process *process;
    GW_SYSTEM *system = &GwSystem;
    s32 targetPlayer = 0;
    s32 itemSlot;
    s32 i;
    f32 angle;
    u32 *motion;

    func_801111E4_3A6564_w06();
    chest = MBModelCreate(0x21, NULL);
    Hu3DModelScaleSet(chest->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&chest->coords, &MBPlayerGet(-1)->player_obj->coords);
    func_8001C814_1D414(chest->omObj1->model[0], 2, 1);
    chest->velocity.x = 100.0f;
    HuAudFXPlay(0x142);
    while (chest->velocity.x > 30.0f) {
        chest->velocity.x -= 1.0f;
        HuPrcVSleep();
    }

    if (targetPlayer != 0) {
        for (i = 0; i < 1081; i += 30) {
            angle = HuMathSin((f32)i) / 2.0f + 1.0f;
            HuVecCopyXYZ(&chest->scale, angle, HuMathSin((f32)i) / 2.0f + 1.0f,
                         HuMathSin((f32)i) / 2.0f + 1.0f);
            HuPrcVSleep();
        }
    }

    HuAudFXPlay(0x149);
    func_8001C814_1D414(chest->omObj1->model[0], 1, 0);
    HuPrcSleep(20);

    for (i = 0; i < 4; i++) {
        if (GwSystem.current_player_index == i) {
            playerNames[i][0] = 1;
            choices[i] = 0;
        } else {
            playerNames[i][0] = 8;
            choices[i] = 1;
        }
        func_800E2260_F5E80_shared_board(i, &playerNames[i][1]);
    }
    choices[4] = 1;
    choices[5] = 1;
    MBDlgWinInsertCreate(-1, 0x5C01, (s32)playerNames[0], (s32)playerNames[1], (s32)playerNames[2],
                         (s32)playerNames[3], 0);
    targetPlayer = func_801146F4_3A9A74_w06(choices, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    if (targetPlayer == 4) {
        targetPlayer = func_800EF0D8_102CF8_shared_board(1);
    }

    if (GwPlayer[targetPlayer].itemNo[0] == -1) {
        MBPlayerMotionSet(-1, 3, 0);
        func_8004ACE0_4B8E0(0x286, system->current_player_index);
        HuPrcSleep(60);
        func_800E2260_F5E80_shared_board(targetPlayer, playerNames[0]);
        MBWinInsertOpen(0x3A0F, playerNames[0], 0, 0, 0, 0);
        func_800EC3C0_FFFE0_shared_board(system->current_player_index);
        func_800EC3E4_100004_shared_board();
        func_800F2388_105FA8_shared_board(-1, -1, 0, 10, 2);
        MBModelKill(chest);
        GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] = -1;
        MBItemRemoveEmpty(system->current_player_index);
        return;
    }

    itemSlot = MBItemFindEmpty(targetPlayer);
    if (itemSlot == -1) {
        itemSlot = 3;
    }
    itemSlot = MBRand((f32)itemSlot);
    GwPlayer[system->current_player_index].itemNo[MBItemSelNoGet()] =
        GwPlayer[targetPlayer].itemNo[itemSlot];
    GwPlayer[targetPlayer].itemNo[itemSlot] = -1;
    MBItemRemoveEmpty(targetPlayer);
    MBPlayerVibrate((s16)targetPlayer, 3);
    if (MBItemSelNoGet() == itemSlot) {
        MBStatusItemTPLvlSet(targetPlayer, MBItemSelNoGet(), 0);
    }
    MBStatusItemSprKill(-1);
    MBStatusItemPosSet(system->current_player_index, MBItemSelNoGet(),
                       (s16)D_8011CAA4_3B1E24_w06[system->current_player_index].x,
                       (s16)D_8011CAA4_3B1E24_w06[system->current_player_index].y);
    MBStatusItemTPLvlSet(system->current_player_index, MBItemSelNoGet(), 0x100);
    MBStatusItemTPLvlSet(targetPlayer, itemSlot, 0);
    MBStatusItemPriSet(system->current_player_index, MBItemSelNoGet(), 0x4786);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process,
                   func_80110EE4_3A6264_w06(-1,
                                            (s16)D_8011CAA4_3B1E24_w06[system->current_player_index].x,
                                            (s16)D_8011CAA4_3B1E24_w06[system->current_player_index].y,
                                            (s16)D_8011CA84_3B1E04_w06[system->current_player_index].x,
                                            (s16)D_8011CA84_3B1E04_w06[system->current_player_index].y, 5));
    HuPrcChildWait();
    func_8004ACE0_4B8E0(0x274, system->current_player_index);
    MBPlayerMotionLoad(system->current_player_index, 5, 0x31);
    MBPlayerMotionSet(-1, 5, 0);
    HuPrcSleep(50);
    func_800F2388_105FA8_shared_board(system->current_player_index, -1, 0, 10, 2);
    HuPrcSleep(11);
    motion = D_80101734_115354_shared_board[0];
    for (i = 6; i != 0; i--) {
        motion++;
    }
    MBPlayerMotionLoad(system->current_player_index, 5, ((u16 *)motion)[1]);
    MBModelKill(chest);
    MBDlgWinInsertCreate(-1, 0x3A0D, GwPlayer[targetPlayer].chr + 0x1C00,
                         GwPlayer[system->current_player_index].chr + 0x1C00, 0, 0, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    func_801113B4_3A6734_w06();
}

void func_80119698_3AEA18_w06(void) {
    Object *obj = *(Object **)HuPrcCurrentGet()->user_data;

    func_8001C814_1D414(obj->omObj1->model[0], 3, 0);
    MBModelMotionWait(obj);
    MBModelKill(obj);
    omDelPrcObj(NULL);
}

void func_801196F0_3AEA70_w06(Object *arg) {
    Process *temp = omAddPrcObj(func_80119698_3AEA18_w06, 0, 0, 0x40);
    s32 *data = HuMemMemoryAlloc(temp->heap, 0x10);

    temp->user_data = data;
    *data = (s32)arg;
}

void func_80119748_3AEAC8_w06(void) {
    Vec camPos;
    Vec targetPos;
    Object *models[3];
    ModelIdTable animIds;
    void *data[4];
    s8 link;
    s8 index;
    s32 i;
    s32 j;
    s32 mask;
    s32 maxCoins;
    f32 scale;
    SpaceData *masu;
    GW_PLAYER *player;

    masu = MBMasuGet(0x94);
    player = MBPlayerGet(-1);
    animIds = D_8011E1F8_3B3578_w06;
    func_800E6FCC_FABEC_shared_board();
    if (GwSystem.boardData.halfWordBytes[1] == 1) {
        HuAudFXPlay(0x1BA);
    }
    HuVecCopy3F(&camPos, &player->player_obj->coords);
    MBCameraFocusModeSet(4);
    MBCameraFocusVecSet(&camPos);
    HuVecCopy3F(&targetPos, &masu->coords);
    targetPos.z += 10.0f;
    HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(&camPos, &targetPos, &camPos, 0x1E));
    HuPrcChildWait();
    HuPrcSleep(5);

    GwSystem.boardData.halfWordBytes[1]--;
    func_801088B4_39DC34_w06();
    if (GwSystem.boardData.halfWordBytes[1] != 0) {
        HuAudFXPlay(0x1B8);
        for (i = 0; i < 4; i++) {
            player = MBPlayerGet(i);

            for (j = 0; D_8011CBD8_3B1F58_w06[j] != -1; j++) {
                func_800EB24C_FEE6C_shared_board(D_8011CBD8_3B1F58_w06[j], &link, &index);
                if (player->clink == link && player->cidx == index) {
                    MBPlayerVibrate(i, 3);
                    break;
                }
            }
        }
    } else {
        HuAudFXPlay(0x1B9);
        HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.0f));
        HuPrcChildWait();
    }
    HuPrcSleep(0x14);

    if (GwSystem.boardData.halfWordBytes[1] == 0) {
        mask = 0;
        MBStatusHideAll();
        D_800A12D8_A1ED8 = 1;
        for (i = 0; i < 4; i++) {
            player = MBPlayerGet(i);

            for (j = 0; D_8011CBD8_3B1F58_w06[j] != -1; j++) {
                func_800EB24C_FEE6C_shared_board(D_8011CBD8_3B1F58_w06[j], &link, &index);
                if (player->clink == link && player->cidx == index) {
                    s32 bit = 1 << i;

                    mask |= bit;
                    data[i] = MBPlayerVibrateObjCreate(i, 4, 5);
                    break;
                }
            }
            if (D_8011CBD8_3B1F58_w06[j] == -1) {
                data[i] = MBPlayerVibrateObjCreate(i, 2, 5);
            }
        }
        HuAudFXPlay(0x1BB);
        for (i = 0; i < 3; i++) {
            scale = 25.0f;
            models[i] = MBModelFileCreate(animIds.entries[i], -1, 1.0f, 0, 0);
            func_8001C258_1CE58(models[i]->omObj1->model[0], 0x180, 0);
            func_8001C8E4_1D4E4(models[i]->omObj1->model[0], 0x1800);
            func_8001C448_1D048(models[i]->omObj1->model[0]);
            func_801196F0_3AEA70_w06(models[i]);
            MBModelTempAllocFree(models[i]);
            HuVecCopy3F(&models[i]->coords, &masu->coords);
            HuVecCopyXYZ(&models[i]->scale, scale, scale, scale);
            HuPrcSleep(0xC);
        }
        for (i = 0; i < 4; i++) {
            if ((mask & (1 << i)) != 0) {
                MBMotionSet(MBPlayerGet(i)->player_obj, 4, 2);
                func_8004ACE0_4B8E0(0x286, i);
            }
        }
        HuPrcSleep(0x28);
        MBStatusShowAll();
        maxCoins = -1;
        D_800A12D8_A1ED8 = 0;
        j = -1;
        for (i = 0; i < 4; i++) {
            MBPlayerVibrateObjKill(data[i]);
            if ((mask & (1 << i)) != 0 && maxCoins < GwPlayer[i].coin) {
                maxCoins = GwPlayer[i].coin;
                j = i;
            }
        }
        for (i = 0; i < 4; i++) {
            if ((mask & (1 << i)) != 0) {
                MBCoinChangeStatusCreate(i, -GwPlayer[i].coin);
                if (i == j) {
                    MBCoinTakeCreateSound(i, -GwPlayer[i].coin, 1);
                } else {
                    MBCoinTakeCreateSound(i, -GwPlayer[i].coin, 0);
                }
            }
        }
        HuPrcSleep(0x1E);
        GwSystem.boardData.halfWordBytes[1] = 5;
        func_801088B4_39DC34_w06();
    } else {
        MessageTable msgs;

        msgs = D_8011E204_3B3584_w06;
        MBWinInsertOpen(0xF00, (char *)msgs.entries[GwSystem.boardData.halfWordBytes[1] - 1], 0, 0, 0, 0);
        func_800EC39C_FFFBC_shared_board(GwSystem.current_player_index);
        func_800EC3E4_100004_shared_board();
    }

    if (MBKettouPlayerBitGet(0) == 0) {
        MBCameraFocusModeSet(3);
    } else {
        player = MBPlayerGet(-1);
        HuPrcChildLink(HuPrcCurrentGet(),
                       MBPlayerPosMoveCreate(&camPos, &player->player_obj->coords, &camPos, 0x14));
        HuPrcChildWait();
        MBCameraFocusModeSet(1);
    }
    func_800E6FBC_FABDC_shared_board();
}

void func_80119E00_3AF180_w06(s32 arg0) {
    Vec cameraPos;
    s32 masuIds[2];
    s32 index;
    SpaceData *masu;
    GW_PLAYER *player;
    Process *process;
    Object *model;

    player = MBPlayerGet(-1);
    masuIds[0] = 0x75;
    masuIds[1] = 0x70;
    switch (arg0) {
        case 0x34:
        case 0x38:
            index = 0;
            break;
        default:
            index = 1;
            break;
    }

    masu = MBMasuGet(masuIds[index]);
    HuVecCopy3F(&cameraPos, &player->player_obj->coords);
    MBCameraFocusModeSet(4);
    MBCameraFocusVecSet(&cameraPos);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, MBPlayerPosMoveCreate(&cameraPos, &masu->coords, &cameraPos, 0x1E));
    HuPrcChildWait();

    model = D_8011E32C_3B36AC_w06[index];
    if (GwSystem.boardData.halfWordBytes[0] == index) {
        HuAudFXPlay(0x1BE);
        func_8001C814_1D414(model->omObj1->model[0], 3, 4);
        while ((u16)func_800D9E80_EDAA0_shared_board(model) == 0) {
            HuPrcVSleep();
        }
    } else {
        HuAudFXPlay(0x1BF);
        func_8001C814_1D414(model->omObj1->model[0], 7, 0);
        MBModelMotionWait(model);
    }

    WipeCreateOut(4, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    index ^= 1;
    masu = MBMasuGet(masuIds[index]);
    HuVecCopy3F(&cameraPos, &masu->coords);
    HuPrcSleep(2);
    WipeCreateIn(4, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    model = D_8011E32C_3B36AC_w06[index];
    if (GwSystem.boardData.halfWordBytes[0] == index) {
        HuAudFXPlay(0x1BE);
        func_8001C814_1D414(model->omObj1->model[0], 3, 4);
        while ((u16)func_800D9E80_EDAA0_shared_board(model) == 0) {
            HuPrcVSleep();
        }
    } else {
        HuAudFXPlay(0x1BF);
        func_8001C814_1D414(model->omObj1->model[0], 7, 0);
        MBModelMotionWait(model);
    }

    MBDlgResultWinExec(0x1100);
    GwSystem.boardData.halfWordBytes[0] ^= 1;
    if (MBKettouPlayerBitGet(0) == 0) {
        MBCameraFocusModeSet(3);
    } else {
        WipeCreateOut(4, 0x10);
        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        MBCameraFocusModeSet(1);
        HuPrcSleep(2);
        WipeCreateIn(4, 0x10);
        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
    }
}

void func_8011A110_3AF490_w06(void) {
    GW_PLAYER *player = MBPlayerGet(-1);
    s16 masu = MBMasuLinkMasuIdGet(player->clink, player->cidx);

    HuPrcSleep(8);
    switch (masu) {
        case 1:
        case 4:
        case 6:
        case 8:
        case 0x37:
        case 0x4D:
            func_80119748_3AEAC8_w06();
            break;
        default:
            func_80119E00_3AF180_w06(masu);
            break;
    }
    omDelPrcObj(0);
}

void func_8011A1E8_3AF568_w06(void) {
    s32 i;

    for (i = 0; D_8011CBF8_3B1F78_w06[i] != -1; i++) {
        if (MBMasuGet(D_8011CBF8_3B1F78_w06[i])->space_type != 0xE) {
            MBMasuTypeSet(D_8011CBF8_3B1F78_w06[i], D_8011CC1C_3B1F9C_w06[GwSystem.boardData.halfWordBytes[2]]);
        }
    }
    func_800EBDAC_FF9CC_shared_board();
}

void func_8011A2A0_3AF620_w06(void) {
    s32 next;
    s32 prev;

    do {
        next = MBRand(10.0f);
        prev = GwSystem.boardData.halfWordBytes[2];
    } while (prev != -1 && D_8011CC1C_3B1F9C_w06[prev] == D_8011CC1C_3B1F9C_w06[next]);
    GwSystem.boardData.halfWordBytes[2] = next;
}

void func_8011A30C_3AF68C_w06(void) {
    MasuIdTable masuIds;
    Vec rotation;
    GW_PLAYER *player;
    SpaceData *masu;
    void *dialog;
    f32 scale;
    s32 playerIdx;
    s32 index;

    player = MBPlayerGet(-1);
    playerIdx = GwSystem.current_player_index;
    masuIds = D_8011E214_3B3594_w06;
    func_800DBEC0_EFAE0_shared_board(playerIdx);
    switch (MBMasuLinkMasuIdGet(player->clink, player->cidx)) {
        case 0x84:
            index = 0;
            break;
        case 0x76:
            index = 1;
            break;
        case 0x85:
        default:
            index = 2;
            break;
    }
    masu = MBMasuGet(masuIds.entries[index].masuId);
    MBVecDirGet(&player->player_obj->coords, &masu->coords, &player->player_obj->rot);
    MBPlayerMotionSet(-1, 2, 0);
    func_800EE688_1022A8_shared_board(player->player_obj, 10.0f, -1.4f);
    HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(&player->player_obj->coords,
                                                            &masu->coords,
                                                            &player->player_obj->coords, 10));
    HuPrcChildWait();
    player->player_obj->velocity.y = player->player_obj->velocity.z = 0.0f;
    MBPlayerMotionSet(-1, -1, 2);
    MBVecForwardSet(&rotation);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_800ED128_100D48_shared_board(&player->player_obj->rot, &rotation,
                                                     &player->player_obj->rot, 10));
    HuAudFXPlay(0x1BC);
    dialog = MBPlayerVibrateObjCreate(-1, 2, 5);
    scale = 1.0f;
    player->stat |= 4;
    while (player->player_obj->velocity.x >= -3.0f) {
        player->player_obj->velocity.x -= 1.0f;
        HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
        scale -= 0.1f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuPrcVSleep();
    }
    scale = 0.0f;
    HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
    HuPrcChildWait();
    MBPlayerVibrateObjKill(dialog);
    WipeCreateOut(0, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    HuVecCopy3F(&player->player_obj->coords, &MBMasuGet(0x8B)->coords);
    HuPrcSleep(2);
    WipeCreateIn(0, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    HuAudFXPlay(0x1BC);
    while (player->player_obj->velocity.x <= 15.0f) {
        player->player_obj->velocity.x += 1.5f;
        HuVecCopyXYZ(&player->player_obj->scale, scale, scale, scale);
        scale += 0.08f;
        if (scale > 1.0f) {
            scale = 1.0f;
        }
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&player->player_obj->scale, 1.0f, 1.0f, 1.0f);
    player->stat &= ~4;
    masu = MBMasuGet(0x8A);
    MBVecDirGet(&player->player_obj->coords, &masu->coords, &player->player_obj->rot);
    MBPlayerMotionSet(-1, 2, 0);
    func_800EE688_1022A8_shared_board(player->player_obj, 10.0f, -1.5f);
    HuPrcChildLink(HuPrcCurrentGet(), MBPlayerPosMoveCreate(&player->player_obj->coords,
                                                            &masu->coords,
                                                            &player->player_obj->coords, 14));
    HuPrcChildWait();
    MBPlayerMotionSet(-1, -1, 2);
    MBVecForwardSet(&rotation);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_800ED128_100D48_shared_board(&player->player_obj->rot, &rotation,
                                                     &player->player_obj->rot, 5));
    HuPrcChildWait();
    MBMoveMasuSet(-1, 1, 7);
    MBMoveBackMasuSet(-1, 1, 0);
    func_800DB884_EF4A4_shared_board(playerIdx);
    HuPrcSleep(10);
    func_8010A070_39F3F0_w06();
}

void func_8011A848_3AFBC8_w06(void) {
    Hu3DCamInit(2);
    CameraScissorSet(1, &D_8011CDE8_3B2168_w06);
    func_80107828_39CBA8_w06();
    MBStart(2);
    omAddPrcObj(func_80106120_39B4A0_w06, 0x1005, 0x1000, 0);
}

s32 func_8011A89C_3AFC1C_w06(void) {
    s32 i;
    s32 data;
    GW_SYSTEM *loc = &GwSystem;

    data = D_8011D788_3B2B08_w06[loc->star_spawn_indices[loc->current_star_spawn]];
    func_800DA778_EE398_shared_board(loc->current_player_index);
    if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D650_3B29D0_w06) == 0) {
        return loc->current_player_index;
    }
    for (i = 0; i < 4; i++) {
        if (i != loc->current_player_index) {
            func_800DA778_EE398_shared_board(i);
            if ((s16)MBComTreeExec((void *)data) == 0) {
                return i;
            }
        }
    }
    MBRand(4.0f);
}

s32 func_8011A96C_3AFCEC_w06(void) {
    s32 i;
    s32 data1;
    s32 data2;
    GW_SYSTEM *loc = &GwSystem;

    data1 = D_8011DD9C_3B311C_w06[loc->star_spawn_indices[loc->current_star_spawn]];
    data2 = D_8011DDBC_3B313C_w06[loc->star_spawn_indices[loc->current_star_spawn]];
    func_800DA778_EE398_shared_board(loc->current_player_index);
    if ((s16)MBComTreeExec((void *)data1) == 0) {
        return loc->current_player_index;
    }
    for (i = 0; i < 4; i++) {
        if (i != loc->current_player_index) {
            func_800DA778_EE398_shared_board(i);
            if ((s16)MBComTreeExec((void *)data2) == 0) {
                return i;
            }
        }
    }
    MBRand(4.0f);
}

s32 func_8011AA44_3AFDC4_w06(void) {
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

s32 func_8011AA98_3AFE18_w06(s32 arg0, s32 arg1) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 j;

        if (i == GwSystem.current_player_index) {
            continue;
        }
        for (j = 0; j < 3; j++) {
            if (GwPlayer[i].itemNo[j] == ITEM_PLUNDER_CHEST || GwPlayer[i].itemNo[j] == ITEM_BARTER_BOX) {
                break;
            }
        }
        if (j < 3) {
            break;
        }
    }
    if (i < 4) {
        result &= -!MBRandCheck100((s8)(arg0 + arg1 * GwPlayer[i].cpu_difficulty));
    }
    return result;
}

const ModelIdTable D_8011E1F8_3B3578_w06 = { { 0x000B0010, 0x000B0011, 0x000B001B } };

const MessageTable D_8011E204_3B3584_w06 = { { 0xF04, 0xF03, 0xF02, 0xF01 } };

const MasuIdTable D_8011E214_3B3594_w06 = { { { 0, 0x85 }, { 0, 0x78 }, { 0, 0x87 } } };

s32 func_8011AB80_3AFF00_w06(void) {
    s32 curPlayer = (s16)MBPlayerTurnGet();
    GW_SYSTEM *loc = &GwSystem;
    s32 results[3];
    s32 item;
    s32 i;
    s32 j;
    s32 count;
    s32 best;
    s32 slot;

    if (GwSystem.cur_player_used_item & 1) {
        return -1;
    }
    for (slot = 0; slot < 3; slot++) {
        results[slot] = -1;
        item = GwPlayer[curPlayer].itemNo[slot];
        switch (item) {
            case ITEM_NONE:
                continue;
            case ITEM_SKELETON_KEY:
            case ITEM_BOO_REPELLENT:
            case ITEM_KOOPA_KARD:
                for (i = 0, count = 0; i < 3; i++) {
                    if (GwPlayer[curPlayer].itemNo[i] == item) {
                        count++;
                    }
                }
                if (count < 2) {
                    continue;
                }
                break;
            case ITEM_WACKY_WATCH:
                if (loc->total_turns == loc->current_turn) {
                    if (MBPlayerStealRankGet(loc->current_player_index) != 0) {
                        break;
                    }
                }
                if (loc->total_turns - loc->current_turn < 6) {
                    continue;
                }
                if (MBPlayerStealRankGet(loc->current_player_index) == 0) {
                    break;
                }
                continue;
            case ITEM_MUSHROOM:
            case ITEM_LUCKY_CHARM:
                if (func_8011AA44_3AFDC4_w06() != 0) {
                    break;
                }
                if (MBRandCheck100(80) == 0) {
                    continue;
                }
                break;
            case ITEM_BOWSER_PHONE:
                if (GwPlayer[curPlayer].coin == 0) {
                    break;
                }
                for (i = 0; i < 4; i++) {
                    if (i != curPlayer && GwPlayer[i].coin == 0) {
                        break;
                    }
                }
                if (i >= 4) {
                    break;
                }
                if (MBRandCheck100(70) != 0 && func_8011AA44_3AFDC4_w06() == 0) {
                    continue;
                }
                break;
            case ITEM_GOLDEN_MUSHROOM:
                if (func_8011AA44_3AFDC4_w06() != 0) {
                    break;
                }
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D0E0_3B2460_w06) != 0) {
                    continue;
                }
                break;
            case ITEM_BOWSER_SUIT:
                if (func_8011AA44_3AFDC4_w06() != 0) {
                    break;
                }
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D14C_3B24CC_w06) != 0) {
                    continue;
                }
                break;
            case ITEM_WARP_BLOCK:
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D2F0_3B2670_w06) != 0) {
                    continue;
                }
                break;
            case ITEM_POISON_MUSHROOM:
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D5C0_3B2940_w06) == 0) {
                    s32 target = func_8011A89C_3AFC1C_w06();

                    D_8011E3AC_3B372C_w06 = target;
                    if ((GwSystem.slow_dice_flags >> target) & 1) {
                        continue;
                    }
                    break;
                }
                continue;
            case ITEM_REVERSE_MUSHROOM:
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011DA3C_3B2DBC_w06) == 0) {
                    s32 target = func_8011A96C_3AFCEC_w06();

                    D_8011E3A8_3B3728_w06 = target;
                    if (GwPlayer[target].rev & 0x80) {
                        continue;
                    }
                    break;
                }
                continue;
            case ITEM_PLUNDER_CHEST:
                for (i = 0, best = 0, D_8011E364_3B36E4_w06 = -1; i < 4; i++) {
                    if (i != curPlayer) {
                        for (j = 0; j < 3; j++) {
                            s8 it = GwPlayer[i].itemNo[j];

                            if (it != -1) {
                                if (best < D_80100FA8_114BC8_shared_board[it]) {
                                    best = D_80100FA8_114BC8_shared_board[it];
                                    D_8011E364_3B36E4_w06 = i;
                                }
                            }
                        }
                    }
                }
                if (D_8011E364_3B36E4_w06 == -1) {
                    continue;
                }
                if (best >= 4) {
                    break;
                }
                if (MBRandCheck100(5) == 0) {
                    continue;
                }
                break;
            case ITEM_BARTER_BOX:
                for (i = 0, best = 0; i < 3; i++) {
                    if (i != slot) {
                        s8 it = GwPlayer[loc->current_player_index].itemNo[i];

                        if (it != -1) {
                            best += D_80100FA8_114BC8_shared_board[it];
                        }
                    }
                }
                for (i = 0, D_8011E360_3B36E0_w06 = -1; i < 4; i++) {
                    if (i != curPlayer) {
                        count = 0;
                        for (j = 0; j < 3; j++) {
                            s8 it = GwPlayer[i].itemNo[j];

                            if (it != -1) {
                                count += D_80100FA8_114BC8_shared_board[it];
                            }
                        }
                        if (best < count) {
                            D_8011E360_3B36E0_w06 = i;
                            best = count;
                        }
                    }
                }
                if (D_8011E360_3B36E0_w06 == -1) {
                    continue;
                }
                break;
            case ITEM_BOO_BELL:
                if (func_8011AA98_3AFE18_w06(0x32, 0xA) == 0) {
                    break;
                }
                if (GwPlayer[curPlayer].coin < 5) {
                    continue;
                }
                break;
            case ITEM_CELLULAR_SHOPPER:
                if (loc->total_turns == loc->current_turn) {
                    continue;
                }
                if (GwPlayer[curPlayer].coin < 5) {
                    continue;
                }
                break;
            case ITEM_MAGIC_LAMP:
                if (func_8011AA98_3AFE18_w06(0x3C, 0xA) == 0) {
                    break;
                }
                if (GwPlayer[curPlayer].coin < 20) {
                    continue;
                }
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011D44C_3B27CC_w06) != 0) {
                    continue;
                }
                break;
            case ITEM_DUEL_GLOVE:
                if (GwPlayer[curPlayer].coin < 10 && func_8011AA44_3AFDC4_w06() == 0) {
                    continue;
                }
                break;
            case ITEM_LUCKY_LAMP:
                if ((s16)MBComTreeExec((DecisionTreeNonLeafNode *)D_8011DDDC_3B315C_w06) != 0) {
                    continue;
                }
                break;
        }
        results[slot] = GwPlayer[curPlayer].itemNo[slot];
    }
    slot = 0;
    i = 0;
    for (j = 0; j < 3; j++) {
        item = results[j];
        if (item == -1) {
            continue;
        }
        if (loc->total_turns == loc->current_turn) {
            if (item == ITEM_WACKY_WATCH) {
                return j;
            }
        }
        if (slot < D_80100FF4_114C14_shared_board[results[j]]) {
            i = j;
            slot = D_80100FF4_114C14_shared_board[results[j]];
        }
    }
    if (slot == 0) {
        return -1;
    }
    return i;
}

s32 func_8011B188_3B0508_w06(void) {
    GW_SYSTEM *loc = &GwSystem;
    GW_PLAYER *player = MBPlayerGet(-1);
    s32 found;
    s32 i;
    u32 flag = 1;

    for (i = 0; i < 16; i++) {
        u8 val = D_8011E004_3B3384_w06[player->chr][i];

        found = func_8010C724_3A1AA4_w06(val);
        if (found == -1) {
            continue;
        }
        if (D_80100F94_114BB4_shared_board[val] + 20 > GwPlayer[loc->current_player_index].coin) {
            continue;
        }
        if (MBRandCheck100(D_8011E0A4_3B3424_w06[player->chr][i]) != 0) {
            break;
        }
    }
    if (i == 16) {
        found = -1;
    }

    if (found != -1) {
        if (func_8010C724_3A1AA4_w06(0xE) == found) {
            return found + 1;
        }
        if (func_8010C724_3A1AA4_w06(0xB) == found && D_80100F94_114BB4_shared_board[0xB] + 50 <= GwPlayer[loc->current_player_index].coin) {
            return found + 1;
        }
        if (func_8010C724_3A1AA4_w06(0x4) == found && MBItemFind(loc->current_player_index, 0x4) != -1) {
            found = -1;
            flag = 0;
        }
    }

    if ((s16)MBComTreeExec(D_8011E0C4_3B3444_w06[D_8011C8C8_3B1C48_w06]) == 0 && GwPlayer[loc->current_player_index].coin >= D_80100F94_114BB4_shared_board[1]) {
        s32 route = func_8010C724_3A1AA4_w06(1);

        if (route != -1) {
            return route + 1;
        }
    }
    if (found != -1) {
        return found + 1;
    }

    i = (s16)MBComTreeExec(D_8011E0CC_3B344C_w06[D_8011C8C8_3B1C48_w06]);
    if (i == 0) {
        for (; i < 16; i++) {
            u8 val = D_8011E004_3B3384_w06[player->chr][i];

            if (val == 4 && flag == 0) {
                continue;
            }
            found = func_8010C724_3A1AA4_w06(val);
            if (found == -1) {
                continue;
            }
            if (D_80100F94_114BB4_shared_board[val] > GwPlayer[loc->current_player_index].coin) {
                continue;
            }
            if (MBRandCheck100(D_8011E0A4_3B3424_w06[player->chr][i]) != 0) {
                return found + 1;
            }
        }
    }

    found = func_8010C724_3A1AA4_w06(0);
    if (found != -1) {
        return found + 1;
    }
    D_8011DF80_3B3300_w06 = 1;
    return func_8010C7AC_3A1B2C_w06() + 2;
}

s32 func_8011B4EC_3B086C_w06(void) {
    if (D_8011DF80_3B3300_w06 != 0) {
        D_8011DF80_3B3300_w06 = 0;
        return 2;
    }
    return (s16)MBComTreeExec(D_8011E0D4_3B3454_w06[D_8011C8C8_3B1C48_w06]) + 1;
}
