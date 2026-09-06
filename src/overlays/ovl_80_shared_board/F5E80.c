#include "common.h"
#include "F2910.h"
#include "ECA50.h"
#include "FA250.h"
#include "105D50.h"
#include "106A50.h"
#include "10C230.h"
#include "1006F0.h"
#include "113520.h"
#include "FFB10.h"
#include "EE660.h"
#include "F5E80.h"
#include "F5B90.h"
#include "113750.h"
#include "EB2F0.h"
#include "101840.h"
#include "F9DE0.h"
#include "F5070.h"
#include "mallocblock.h"
#include "malloc.h"

typedef struct TelopData {
    s32 unk_00;
    s32 playerNo;
    char unk_08[8];
} TelopData;

// void func_80049FB8_4ABB8(void);
// void func_800E9AF0_FD710_shared_board(Vec *, s32);
// void MBPlayerPosMasuSet(s16, s16);
// void MBPlayerMasuSwap(s16, s16);
// void MBCameraFocusModeSet(s32);
// void MBPlayerPosFixSet(s32, s32);
// void func_8004A0E0_4ACE0(void);
// void MBKettouResultExec(void);
// void MBKettouComResultSet(void);
// s32 MBKettouExec(GW_PLAYER *);
// void func_800FC968_110588_shared_board(void);
// void MBMasuCurSet(s16);
// void MBStatusItemIconSprReinit(s32);
// void func_8003B128_3BD28(char*);
// void func_8005FBA4_607A4(u8 *, s32);
// s32 func_80060880_61480(s32 arg0, s32 arg1, s32 arg2);
// extern void func_8008EBD0_8F7D0(f32, f32*, f32*);
// void func_800610E0_61CE0(s16);
// void func_800FC938_110558_shared_board(void);
// f32 HuMathSin(f32);
// void MBStatusItemScaleSet(s32, s32, f32, f32);
// void func_800DC06C_EFC8C_shared_board(void);
// void func_800DC0E0_EFD00_shared_board(s32 playerNo);
// void func_800FC7C8_1103E8_shared_board(void);
// static void MBItemKSuitEnd(void);
// s16 func_8003A308_3AF08(char* arg0, char* arg1, s32 arg2, s16 arg3, u16 arg4);
// s32 func_800F52C4_108EE4_shared_board(void);

extern char* D_80101170_114D90_shared_board[];
extern Vec D_8010125C_114E7C_shared_board;
extern s8 D_80101194_114DB4_shared_board[];
extern f32 D_80102D94_1169B4_shared_board;
extern u8 D_80102D36_116956_shared_board;
extern s16 D_80102C50_116870_shared_board;
extern s16 D_80102C52_116872_shared_board;
extern f32 D_801049F8_118618_shared_board[2];
extern s32 D_80101060_114C80_shared_board[];
extern s32 D_801010F8_114D18_shared_board[];
extern s16 D_80101148_114D68_shared_board[];
extern s16 D_80102D34_116954_shared_board;
extern s16 D_80102D38_116958_shared_board;
extern s16 D_80102D3A_11695A_shared_board[];
extern omObjData* D_80102D40_116960_shared_board;
extern omObjData* D_80102D44_116964_shared_board;
extern char D_80102CC0_1168E0_shared_board[0x20];
extern s16 D_80102D48_116968_shared_board[];
extern s16 D_80102D4C_11696C_shared_board[];
extern s16 D_801052B8_118ED8_shared_board[];
extern s16 D_801054B6_1190D6_shared_board;
extern s16 D_801054B8_1190D8_shared_board[];
extern s16 D_801054F8_119118_shared_board;
extern Vec D_80102D60_116980_shared_board;
extern Vec D_80102D6C_11698C_shared_board;
extern Vec D_80102D78_116998_shared_board;
extern Vec D_80102D84_1169A4_shared_board;
extern Vec D_80102D90_1169B0_shared_board;
extern Object* D_80102D54_116974_shared_board;
extern s16 D_80102CE0_116900_shared_board[];
extern s32 D_80102D58_116978_shared_board;
extern s8 D_8010118C_114DAC_shared_board[];
extern s32 D_80100F90_114BB0_shared_board;
extern s32 D_80102CB4_1168D4_shared_board;
extern s16 D_801010E8_114D08_shared_board[][2];
extern s32 D_80102CB0_1168D0_shared_board;
extern s32 (*MBItemFunctions[])(void);
extern s32 D_800D41B0_D4DB0[];

typedef struct SomeStruct {
    u8 unk_00[10];
} SomeStruct;

extern SomeStruct D_80102250_115E70_shared_board;
extern s32 D_80102D50_116970_shared_board;

typedef struct SomeStruct2 {
    u16 unk_00[8];
} SomeStruct2;

extern SomeStruct2 D_8010225C_115E7C_shared_board;

// s32 D_80100F90_114BB0_shared_board = -1;
// s8 D_80100F94_114BB4_shared_board[] = {5, 5, 5, 5, 5, 5, 10, 10, 10, 10, 10, 15, 10, 10, 20, -1, -1, -1, -1, 30};
// s32 D_80100FA8_114BC8_shared_board[] = {3, 1, 2, 4, 3, 2, 4, 2, 3, 5, 5, 6, 3, 3, 7, 4, 6, 6, 6};
// s32 D_80100FF4_114C14_shared_board[] = {3, 1, 2, 4, 3, 2, 4, 2, 3, 5, 5, 8, 1, 3, 10, 1, 7, 6, 9};
// s32 D_80101040_114C60_shared_board[] = {0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71};

// TODO: fix (u8*)arg1 hack
void func_800E2260_F5E80_shared_board(s32 arg0, char *arg1) {
    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }
    func_8005FBA4_607A4((u8 *)arg1, D_80101060_114C80_shared_board[GwPlayer[arg0].chr]);
}

void MBItemWarpBlockSwapInit(void) {
    D_80102C50_116870_shared_board = -1;
    D_80102C52_116872_shared_board = -1;
}

s16 func_800E22CC_F5EEC_shared_board(s32 arg0, s32 arg1) {
    return ((arg1 ^ arg0) << 0x10) != 0;
}

static void func_800E22DC_F5EFC_shared_board(s16 arg0, s16 arg1) {
    if (arg1 == MBPlayerTurnGet()) {
        D_80102C50_116870_shared_board = arg1;
        D_80102C52_116872_shared_board = arg0;
        return;
    }
    D_80102C50_116870_shared_board = arg0;
    D_80102C52_116872_shared_board = arg1;
}

s32 MBItemWarpBlockSwapPlayerSet(s16 arg0) {
    func_800E22DC_F5EFC_shared_board(MBPlayerGet(CUR_PLAYER)->turn, arg0);
    return 1;
}

static void MBItemWarpBlockSwap(void) {
    GW_PLAYER *temp_s4;
    GW_PLAYER *temp_s5;
    GW_PLAYER *playerCopy;
    Object *playerObj;
    Object *playerObjSecond;
    Object *model;
    Vec *temp_s0;
    f32 temp_f0;
    f32 temp_f2;
    s32 i;

    MBCameraFocusModeSet(0);
    temp_s4 = MBPlayerGet(D_80102C50_116870_shared_board);
    temp_s5 = MBPlayerGet(D_80102C52_116872_shared_board);
    temp_s4->stat |= 4;
    temp_s5->stat |= 4;
    playerObj = temp_s4->player_obj;
    playerObjSecond = temp_s5->player_obj;
    HuAudFXPlay(0x107);
    model = MBModelCreate(0x1C, NULL);
    MBMotionSet(model, -1, 0);
    HuVecCopy3F(&model->coords, &playerObj->coords);

    for (i = 0; i < 15; i++) {
        temp_f0 = (f32)i / 15.0f;
        temp_f2 = 1.0f - temp_f0;
        temp_f0 += 1.0f;
        playerObj->scale.x = temp_f2;
        playerObj->scale.y = temp_f0;
        playerObj->scale.z = temp_f2;
        playerObj->velocity.x += 6.0f;
        HuPrcVSleep();
    }

    playerObj->scale.x = 0.0f;
    playerObj->scale.y = 0.0f;
    playerObj->scale.z = 0.0f;

    HuPrcVSleep();
    playerObj->flags &= ~2;
    MBModelDispOff(playerObj);
    MBModelKill(model);
    HuAudFXPlay(0x107);
    model = MBModelCreate(0x1C, NULL);
    MBMotionSet(model, -1, 0);
    HuVecCopy3F(&model->coords, &playerObjSecond->coords);

    for (i = 0; i < 15; i++) {
        temp_f0 = (f32)i / 15.0f;
        temp_f2 = 1.0f - temp_f0;
        temp_f0 += 1.0f;
        playerObjSecond->scale.x = temp_f2;
        playerObjSecond->scale.y = temp_f0;
        playerObjSecond->scale.z = temp_f2;
        playerObjSecond->velocity.x += 6.0f;
        HuPrcVSleep();
    }

    playerCopy = temp_s4;
    MBModelKill(model);
    MBPlayerMasuSwap(D_80102C50_116870_shared_board, D_80102C52_116872_shared_board);
    MBPlayerPosMasuSet(D_80102C50_116870_shared_board, MBMasuLinkMasuIdGet(playerCopy->clink, temp_s4->cidx));
    MBPlayerPosMasuSet(D_80102C52_116872_shared_board, MBMasuLinkMasuIdGet(temp_s5->clink, temp_s5->cidx));
    HuAudFXPlay(0x107);
    model = MBModelCreate(0x1C, NULL);
    MBMotionSet(model, -1, 0);
    HuVecCopy3F(&model->coords, &playerObjSecond->coords);

    for (i = 14; i >= 0; i--) {
        temp_f0 = (f32)i / 15.0f;
        temp_f2 = 1.0f - temp_f0;
        temp_f0 += 1.0f;
        playerObjSecond->scale.x = temp_f2;
        playerObjSecond->scale.y = temp_f0;
        playerObjSecond->scale.z = temp_f2;
        playerObjSecond->velocity.x -= 6.0f;
        HuPrcVSleep();
    }

    MBModelKill(model);
    MBPlayerVibrate(D_80102C52_116872_shared_board, 3);
    WipeCreateOut(0, 0x10);
    HuPrcSleep(0x10);
    func_800E9AF0_FD710_shared_board(&playerObj->coords, 0);
    MBPlayerPosFixSet(0, 1);
    MBPlayerPosFixSet(1, 1);
    MBPlayerPosFixSet(2, 1);
    MBPlayerPosFixSet(3, 1);
    WipeCreateIn(0, 0x10);
    HuPrcSleep(0x10);
    HuAudFXPlay(0x107);
    playerObj->flags |= 2;
    MBModelDispOn(playerObj);
    model = MBModelCreate(0x1C, NULL);
    MBMotionSet(model, -1, 0);
    HuVecCopy3F(&model->coords, &playerObj->coords);

    for (i = 14; i >= 0; i--) {
        temp_f0 = (f32)i / 15.0f;
        temp_f2 = 1.0f - temp_f0;
        temp_f0 += 1.0f;
        playerObj->scale.x = temp_f2;
        playerObj->scale.y = temp_f0;
        playerObj->scale.z = temp_f2;
        playerObj->velocity.x -= 6.0f;
        HuPrcVSleep();
    }

    MBModelKill(model);
    MBPlayerVibrate(D_80102C50_116870_shared_board, 3);
    playerCopy->stat &= ~4;
    temp_s5->stat &= ~4;

    if (D_80102C50_116870_shared_board != MBPlayerTurnGet()) {
        HuPrcSleep(15);
        WipeCreateOut(0, 16);
        HuPrcSleep(16);
        func_800E9AF0_FD710_shared_board(&MBPlayerGet(CUR_PLAYER)->player_obj->coords, 0);
        WipeCreateIn(0, 16);
        HuPrcSleep(16);
    }

    HuPrcSleep(15);
    MBDlgWinInsertCreate(-1, 0x3A10, mbCharNameMesTbl[GwPlayer[D_80102C50_116870_shared_board].chr], mbCharNameMesTbl[GwPlayer[D_80102C52_116872_shared_board].chr], 0, 0, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    MBCameraFocusModeSet(1);
    MBItemWarpBlockSwapInit();
    omDelPrcObj(NULL);
}

void MBItemWarpBlockSwapCreate(void) {
    Process *proc;

    proc = HuPrcCurrentGet();
    HuPrcChildLink(proc, omAddPrcObj(MBItemWarpBlockSwap, 0x1003, 0, 0));
    HuPrcChildWait();
}

s16 func_800E2954_F6574_shared_board(void) {
    return D_80102C50_116870_shared_board;
}

void MBItemHookSet(s32 idx, void (*func)()) {
    MBItemSubFunctions[idx] = func;
}

s32 MBItemNullExec(void) {
    MBDlgWinInsertCreate(-1, 0x3A00, mbCharNameMesTbl[GwPlayer[GwSystem.current_player_index].chr], 0, 0, 0, 0);
    MBDlgWinClose();
    MBDlgWinKill();
    return 0;
}

s32 MBItemKinokoExec(void) {
    GW_SYSTEM *system = &GwSystem;
    GW_PLAYER *player = MBPlayerGet(CUR_PLAYER);

    if ((func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1)) && player->rev & 0x80) {
        player->rev &= ~0x80;
        MBDlgWinExec(-1, 0x3A2B);
    } else {
        if (func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1)) {
            MBDlgWinExec(-1, 0x3A27);
        }
        if (player->rev & 0x80) {
            player->rev &= ~0x80;
            MBDlgWinExec(-1, 0x3A29);
        }
    }

    func_800DCA64_F0684_shared_board(GwSystem.current_player_index);
    MBItemSubFunctions[IFUNC_MUSHROOM]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    func_800DE9AC_F25CC_shared_board(GwSystem.current_player_index, 2);
    MBPlayerVibrate(CUR_PLAYER, 2);
    func_800DC128_EFD48_shared_board(GwSystem.current_player_index);
    HuPrcSleep(15);
    return 1;
}

s32 MBItemKeymanExec(void) {
    MBItemSubFunctions[17]();
    return 1;
}

s32 MBItemNKinokoExec(void) {
    MBItemSubFunctions[8]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBItemSubFunctions[10]();
    return 1;
}

s32 MBItemRKinokoExec(void) {
    void *temp_s0;

    MBItemSubFunctions[8]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBItemSubFunctions[11]();
    return 1;
}

s32 MBItemShopPhoneExec(void) {
    MBItemSubFunctions[14]();
    return 1;
}

s32 MBItemKoopaPhoneExec(void) {
    MBItemSubFunctions[15]();
    return 1;
}

s32 MBItemStarYokeExec(void) {
    MBItemSubFunctions[16]();
    return 1;
}

s32 MBItemRobBoxExec(void) {
    MBItemSubFunctions[3]();
    return 1;
}

s32 MBItemKettouExec(void) {
    s32 temp_v0;

    MBItemSubFunctions[7]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);

    if (func_800DEB2C_F274C_shared_board(GwSystem.current_player_index) == (MB_MAX_PLAYERS - 1)) {
        GWBoardFlagSet(0x17);
    } else {
        GWBoardFlagClear(0x17);
    }

    GwSystem.unk_58 = ~(1 << MBPlayerTurnGet());
    GwSystem.playerIndexVisitingBowser = ((1 << MBPlayerTurnGet()) | 0x8000);
    temp_v0 = MBKettouExec(MBPlayerGet(CUR_PLAYER)); //intentionally implicit; required (this is supposed to have 2 args)

    if (temp_v0 != 0) {
        if (temp_v0 == 1) {
            func_800FC968_110588_shared_board();
            func_800FC8A4_1104C4_shared_board();
            func_8004A0E0_4ACE0();
            HuPrcSleep(-1);
        }
        MBKettouComResultSet();
        MBKettouResultExec();
    }
    return 1;
}

s32 MBItemWarpBlockExec(void) {
    GW_PLAYER *temp_s0;
    GW_SYSTEM *system = &GwSystem;

    temp_s0 = MBPlayerGet(CUR_PLAYER);
    GwPlayer[system->current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(system->current_player_index);

    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1) && (temp_s0->rev & 0x80)) {
        temp_s0->rev = temp_s0->rev & 0x7F;
        MBDlgWinExec(-1, 0x3A13);
    } else {
        if (func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1)) {
            MBDlgWinExec(-1, 0x3A11);
        }

        if (temp_s0->rev & 0x80) {
            temp_s0->rev = temp_s0->rev & 0x7F;
            MBDlgWinExec(-1, 0x3A12);
        }
    }

    func_800FC938_110558_shared_board();
    MBItemSubFunctions[2]();
    return 1;
}

s32 MBItemSKinokoExec(void) {
    GW_PLAYER *temp_s0;
    GW_SYSTEM *system = &GwSystem;

    temp_s0 = MBPlayerGet(CUR_PLAYER);
    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1) && (temp_s0->rev & 0x80)) {
        temp_s0->rev &= 0x7F;
        MBDlgWinExec(-1, 0x3A2C);
    } else {
        if (func_800DEB2C_F274C_shared_board(system->current_player_index) == (MB_MAX_PLAYERS - 1)) {
            MBDlgWinExec(-1, 0x3A28);
        }

        if (temp_s0->rev & 0x80) {
            temp_s0->rev &= 0x7F;
            MBDlgWinExec(-1, 0x3A2A);
        }
    }

    func_800DCA64_F0684_shared_board(GwSystem.current_player_index);
    MBItemSubFunctions[6]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    func_800DE9AC_F25CC_shared_board(GwSystem.current_player_index, 3);
    MBPlayerVibrate(-1, 3);
    func_800DC128_EFD48_shared_board(GwSystem.current_player_index);
    HuPrcSleep(0xF);
    return 1;
}

s32 MBItemTereBellExec(void) {
    GW_PLAYER *temp_s0;

    temp_s0 = MBPlayerGet(CUR_PLAYER);
    MBItemSubFunctions[7]();
    MBMasuCurSet(MBMasuLinkMasuIdGet(temp_s0->clink, temp_s0->cidx));
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);
    MBItemSubFunctions[0]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBStatusItemIconSprReinit(-1);
    return 1;
}

s32 MBItemTereYokeSprayExec(void) {
    MBItemSubFunctions[8]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBDlgWinExec(-1, 0x3A1C);
    MBItemSubFunctions[18]();
    return 1;
}

s32 MBItemKSuitExec(void) {
    MBItemSubFunctions[IFUNC_MUSHROOM]();
    MBItemSubFunctions[IFUNC_BOWSER_SUIT_BEGIN]();
    GwPlayer[GwSystem.current_player_index].itemTurn = 1;
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    return 1;
}

s32 MBItemMajinLampExec(void) {
    GW_PLAYER* temp_s0;
    GW_SYSTEM* system = &GwSystem;

    temp_s0 = MBPlayerGet(CUR_PLAYER);
    GwPlayer[system->current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(system->current_player_index);
    MBStatusItemIconSprReinit(-1);
    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
        if (temp_s0->rev & 0x80) {
            temp_s0->rev &= ~0x80;
            MBDlgWinExec(-1, 0x3A1B);
            MBItemSubFunctions[1]();
            return 1;
        }
    }
    
    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
        MBDlgWinExec(-1, 0x3A19);
    }
    if (temp_s0->rev & 0x80) {
        temp_s0->rev &= ~0x80;
        MBDlgWinExec(-1, 0x3A1A);
    }        
    
    MBItemSubFunctions[1]();
    return 1;
}


s32 MBItemKoopaCardExec(void) {
    MBItemSubFunctions[8]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = ITEM_NONE;
    MBItemRemoveEmpty(GwSystem.current_player_index);
    MBDlgWinExec(-1, 0x3A22);
    MBItemSubFunctions[IFUNC_KOOPA_KARD]();
    return 1;
}

s32 MBItemExchangeBoxExec(void) {
    MBItemSubFunctions[IFUNC_EXHANGE_BOX]();
    return 1;
}

s32 MBItemGambleCoinExec(void) {
    MBItemSubFunctions[0x14]();
    return 1;
}

s32 MBItemAfter5Exec(void) {
    MBItemSubFunctions[0x15]();
    return 1;
}

void MBItemKoopaNKinokoExec(void) {
    MBItemSubFunctions[12]();
}

void MBItemKoopaRKinokoExec(void) {
    MBItemSubFunctions[13]();
}

//file split starting here? functions kind of change the general idea of what they accomplish at this point
extern Unk3* D_801010D0_114CF0_shared_board;
extern Unk3* D_801010D4_114CF4_shared_board;
extern Unk3* D_801010D8_114CF8_shared_board;
extern Unk3* D_801010DC_114CFC_shared_board;
extern Unk3* D_801010E0_114D00_shared_board;
extern Unk3* D_801010E4_114D04_shared_board;

static void MBItemHelpCreate(void) {
    D_801010E4_114D04_shared_board = func_800E210C_F5D2C_shared_board(0, 0x84, 0);
    D_801010D0_114CF0_shared_board = func_800E210C_F5D2C_shared_board(0xE, 0x92, 0);
    D_801010D4_114CF4_shared_board = func_800E210C_F5D2C_shared_board(4, 0xA0, 0);
    D_801010D8_114CF8_shared_board = func_800E210C_F5D2C_shared_board(3, 0xAE, 0);
    D_801010DC_114CFC_shared_board = func_800E210C_F5D2C_shared_board(0xB, 0xBC, 0);
    D_801010E0_114D00_shared_board = func_800E210C_F5D2C_shared_board(0xF, 0xCA, 0);
}

static void func_800E3584_F71A4_shared_board(void) {
    if (D_801010D0_114CF0_shared_board != NULL) {
        MBHelpWinKill(D_801010E4_114D04_shared_board);
        MBHelpWinKill(D_801010D0_114CF0_shared_board);
        MBHelpWinKill(D_801010D4_114CF4_shared_board);
        MBHelpWinKill(D_801010D8_114CF8_shared_board);
        MBHelpWinKill(D_801010DC_114CFC_shared_board);
        MBHelpWinKill(D_801010E0_114D00_shared_board);
        D_801010D0_114CF0_shared_board = NULL;
    }
}

// does pulsing effect of item when hovering over it as an item to use
static void MBItemScaleEff(void) {
    f32 temp_f0;
    f32 var_f20;
    s32 *temp_s0;
    s32 prev;

    temp_s0 = HuPrcCurrentGet()->user_data;
    var_f20 = 0.0f;
    prev = *temp_s0;
    while (*temp_s0 != -1) {
        if (*temp_s0 != prev) {
            MBStatusItemScaleSet(GwSystem.current_player_index, prev, 1.0f, 1.0f);
            var_f20 = 0.0f;
            prev = *temp_s0;
        }
        if (var_f20 > 360.0f) {
            var_f20 -= 360.0f;
        }
        temp_f0 = (HuMathSin(var_f20) * 0.2f) + 1.0f;
        MBStatusItemScaleSet(GwSystem.current_player_index, *temp_s0, temp_f0, temp_f0);
        HuPrcVSleep();
        var_f20 += 13.0f;
    }
    MBStatusItemScaleSet(GwSystem.current_player_index, prev, 1.0f, 1.0f);
    omDelPrcObj(0);
}

static void MBItemScaleEffCreate(void) {
    if (MBItemFindEmpty(-1) != 0) {
        HuSprAttrReset(mbItemCursorGrpId, 0, 0x8000);
        omAddPrcObj(MBItemScaleEff, 0x1005U, 0, 0)->user_data = &D_80102CB4_1168D4_shared_board;
    }
}

// function that runs immediately when pressing "B" to use an item
static void MBItemSel(void) {
    f32 sp10[2];
    s32 sp1C;
    s32 prevSelectedItemSlot;
    s32 playerNo;
    s32 var_s5;
    s32 playerPadNo;
    void *temp_v0;

    playerNo = (s32)HuPrcCurrentGet()->user_data;
    playerPadNo = GwPlayer[playerNo].pad;

    MBStatusShrink(-1);
    MBStatusItemDispSetAll(1);
    MBStatusGrow(-1);

    mbItemCursorGrpId = HuSprGrpCreate(1, 5);
    temp_v0 = DataRead(D_80101040_114C60_shared_board[GwPlayer[GwSystem.current_player_index].chr]);
    sp1C = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    func_80055024_55C24(mbItemCursorGrpId, 0, sp1C, 0);
    HuSprPriSet(mbItemCursorGrpId, 0, 0xA);
    func_800550F4_55CF4(mbItemCursorGrpId, 0, 1);

    if (GwSystem.current_player_index & 1) {
        HuSprAttrSet(mbItemCursorGrpId, 0, 0x1001);
    } else {
        HuSprAttrSet(mbItemCursorGrpId, 0, 0x1000);
    }

    var_s5 = 20;

    D_80100F90_114BB0_shared_board = 0;
    D_80102CB4_1168D4_shared_board = 0;

    if (MBItemFindEmpty(-1) == 0) {
        HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
    } else {
        omAddPrcObj(MBItemScaleEff, 0x1005, 0, 0)->user_data = &D_80102CB4_1168D4_shared_board;
    }

    func_800F6848_10A468_shared_board(GwSystem.current_player_index, D_80102CB4_1168D4_shared_board, &sp10[0], &sp10[1]);
    MBStatusItemPriSet(GwSystem.current_player_index, D_80102CB4_1168D4_shared_board, ((GwSystem.current_player_index * 5) + 0x478F));
    func_80054904_55504(mbItemCursorGrpId, 0,
                        D_801010E8_114D08_shared_board[GwSystem.current_player_index][0] + sp10[0],
                        D_801010E8_114D08_shared_board[GwSystem.current_player_index][1] + sp10[1]);

    MBItemHelpCreate();

    while (1) {
        prevSelectedItemSlot = D_80100F90_114BB0_shared_board;

        if (GwPlayer[GwSystem.current_player_index].itemNo[0] != -1) {
            if (D_800C9520_CA120[playerPadNo] & 0x200) {
                do {
                    if (--D_80100F90_114BB0_shared_board < 0)
                        D_80100F90_114BB0_shared_board = ARRAY_COUNT(GwPlayer->itemNo) - 1;
                } while (GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] == -1);
            }

            if ((D_800C9520_CA120[playerPadNo] & 0x100) || ((D_80100F90_114BB0_shared_board != D_80102CB0_1168D0_shared_board) && (var_s5-- == 0) && (MBPlayerComCheck(playerNo) != 0))) {
                var_s5 = 20;
                do {
                    if (++D_80100F90_114BB0_shared_board >= ARRAY_COUNT(GwPlayer->itemNo))
                        D_80100F90_114BB0_shared_board = 0;
                } while (GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] == -1);
            }

            if (prevSelectedItemSlot != D_80100F90_114BB0_shared_board) {
                HuAudFXPlay(1);
                D_80102CB4_1168D4_shared_board = D_80100F90_114BB0_shared_board;
                func_800F6848_10A468_shared_board(GwSystem.current_player_index, D_80100F90_114BB0_shared_board, &sp10[0], &sp10[1]);
                func_80054904_55504(mbItemCursorGrpId, 0,
                                    D_801010E8_114D08_shared_board[GwSystem.current_player_index][0] + sp10[0],
                                    D_801010E8_114D08_shared_board[GwSystem.current_player_index][1] + sp10[1]);
                MBStatusItemPriSet(GwSystem.current_player_index, prevSelectedItemSlot, ((GwSystem.current_player_index * 5) + 0x4790));
                MBStatusItemPriSet(GwSystem.current_player_index, D_80100F90_114BB0_shared_board, ((GwSystem.current_player_index * 5) + 0x478F));
            }
        }

        if ((D_800C9520_CA120[playerPadNo] & 0x8000) || ((MBPlayerComCheck(playerNo) != 0) && (D_80102CB0_1168D0_shared_board == D_80100F90_114BB0_shared_board))) {
            D_80102CB4_1168D4_shared_board = -1;
            func_800E3584_F71A4_shared_board();
            GwSystem.cur_player_used_item |= 1;

            if (MBItemFunctions[GwPlayer[playerNo].itemNo[D_80100F90_114BB0_shared_board] + 1]() == 0) {
                MBItemHelpCreate();
                GwSystem.cur_player_used_item &= ~1;
                MBStatusItemPriSet(GwSystem.current_player_index, D_80102CB4_1168D4_shared_board, ((GwSystem.current_player_index * 5) + 0x478F));
                func_80054904_55504(mbItemCursorGrpId, 0,
                                    D_801010E8_114D08_shared_board[GwSystem.current_player_index][0] + sp10[0],
                                    D_801010E8_114D08_shared_board[GwSystem.current_player_index][1] + sp10[1]);
            } else {
                break;
            }
        }

        if (!(D_800C9520_CA120[playerPadNo] & 0x4000)) {
            if (D_800C9520_CA120[playerPadNo] & 8) {
                D_80102CB4_1168D4_shared_board = -1;
                HuPrcVSleep();
                HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
                func_800E3584_F71A4_shared_board();
                MBItemDescExec(playerNo);
                MBItemHelpCreate();
                D_80102CB4_1168D4_shared_board = D_80100F90_114BB0_shared_board;
                MBItemScaleEffCreate();
            }

            if (D_800C9520_CA120[playerPadNo] & 0x10) {
                D_80102CB4_1168D4_shared_board = -1;
                HuPrcVSleep();
                HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
                func_800E3584_F71A4_shared_board();
                MBMapScrollExec(playerPadNo);
                MBItemHelpCreate();
                D_800CB99C_CC59C = 1;
                func_80049FB8_4ABB8();
                D_80102CB4_1168D4_shared_board = D_80100F90_114BB0_shared_board;
                MBItemScaleEffCreate();
            }

            if (D_800C9520_CA120[playerPadNo] & 0x2000) {
                D_80102CB4_1168D4_shared_board = -1;
                HuPrcVSleep();
                HuSprAttrSet(mbItemCursorGrpId, 0, 0x8000);
                func_800E3584_F71A4_shared_board();
                MBMapFullExec(playerPadNo);
                MBItemHelpCreate();
                D_800CB99C_CC59C = 1;
                func_80049FB8_4ABB8();
                D_80102CB4_1168D4_shared_board = D_80100F90_114BB0_shared_board;
                MBItemScaleEffCreate();
            }

            HuPrcVSleep();
            continue;
        }
        break;
    }

    func_800E3584_F71A4_shared_board();
    D_80102CB4_1168D4_shared_board = -1;
    HuSprGrpKill(mbItemCursorGrpId);
    HuSprKill(sp1C);

    if (MBStatusItemDispGet(0) != 0) {
        MBStatusShrink(-1);
        MBStatusItemDispSetAll(0);
        MBStatusGrow(-1);
    }

    omDelPrcObj(NULL);
}

void MBItemSelExec(s32 playerNo, s32 arg1) {
    Process* temp_s2;
    Process* temp_v0;

    func_800DC06C_EFC8C_shared_board(playerNo);
    
    D_800CB99C_CC59C = 1;
    func_80049FB8_4ABB8();
    D_80102CB0_1168D0_shared_board = arg1;
    temp_s2 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(MBItemSel, 0x1005, 0x1000, 0);
    temp_v0->user_data = (void*)playerNo;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s2, temp_v0);
    HuPrcChildWait();
    func_8004A0E0_4ACE0();
    D_800CB99C_CC59C = 0;
    func_800DC0E0_EFD00_shared_board(playerNo);
    func_800FC7C8_1103E8_shared_board();
}

static void MBItemView(void) {
    s32 playerIdx;
    s32 padNo;

    playerIdx = (s32)(HuPrcCurrentGet()->user_data);
    padNo = GwPlayer[playerIdx].pad;
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(1);
    MBStatusGrow(-1);
    D_80100F90_114BB0_shared_board = 0;
    D_801010D4_114CF4_shared_board = func_800E210C_F5D2C_shared_board(4, 0xA0, 0);
    D_801010E0_114D00_shared_board = func_800E210C_F5D2C_shared_board(0xF, 0xAE, 0);
    while (1) {
        if ((D_800C9520_CA120[padNo] & B_BUTTON)) {
            break;
        }
        if (D_800C9520_CA120[padNo] & U_CBUTTONS) {
            MBHelpWinKill(D_801010D4_114CF4_shared_board);
            MBHelpWinKill(D_801010E0_114D00_shared_board);
            MBItemDescExec(playerIdx);
            D_801010D4_114CF4_shared_board = func_800E210C_F5D2C_shared_board(4, 0xA0, 0);
            D_801010E0_114D00_shared_board = func_800E210C_F5D2C_shared_board(0xF, 0xAE, 0);
        }
        HuPrcVSleep();      
    }

    MBHelpWinKill(D_801010D4_114CF4_shared_board);
    MBHelpWinKill(D_801010E0_114D00_shared_board);
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);
    omDelPrcObj(NULL);
}

void MBItemViewExec(s32 playerNo) {
    Process* temp_s1;
    Process* temp_v0;

    D_800CB99C_CC59C = 1;
    func_80049FB8_4ABB8();
    temp_s1 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(MBItemView, 0x1005, 0, 0);
    temp_v0->user_data = (void*)playerNo;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s1, temp_v0);
    HuPrcChildWait();
    func_8004A0E0_4ACE0();
    D_800CB99C_CC59C = 0;
}

static void MBItemDesc(void) {
    s16 sp18[2];
    s16 temp_v0_2;
    s32 playerNo;
    s8 itemID;
    s32 savedItemID;
    s32 padNo;

    playerNo = (s32)(HuPrcCurrentGet()->user_data);
    padNo = GwPlayer[playerNo].pad;
    savedItemID = 0;
    
    if (D_80100F90_114BB0_shared_board != -1) {
        itemID = GwPlayer[playerNo].itemNo[D_80100F90_114BB0_shared_board];
        if (itemID != -1) {
            savedItemID = itemID;
        }
    }
    
    func_800604A8_610A8(sp18, 0x3E00, 0x3E0A);
    temp_v0_2 = func_80061188_61D88(D_80101148_114D68_shared_board[savedItemID], 0xA0 - (sp18[0] / 2), 0x3C, sp18[0], sp18[1], 0);
    func_8005FBF8_607F8(temp_v0_2, 1, 0xBC, 0xE7);
    func_8005B43C_5C03C(temp_v0_2, D_801010F8_114D18_shared_board[savedItemID], -1, -1);
    func_80061388_61F88(temp_v0_2);
    D_801010D4_114CF4_shared_board = func_800E210C_F5D2C_shared_board(0x10, 0xA0, 0);
    D_801010D8_114CF8_shared_board = func_800E210C_F5D2C_shared_board(0x11, 0xAE, 0);
    D_801010DC_114CFC_shared_board = func_800E210C_F5D2C_shared_board(4, 0xBC, 0);
    
    while (1) {
        if ((D_800C9520_CA120[padNo] & B_BUTTON)) {
            break;
        }
        if (D_800D0590_D1190[padNo] & R_CBUTTONS) {
            savedItemID++;
            savedItemID %= 20;
            func_8005D294_5DE94(temp_v0_2);
            func_8005B43C_5C03C(temp_v0_2, D_801010F8_114D18_shared_board[savedItemID], -1, -1);
            func_80061934_62534(temp_v0_2, D_80101148_114D68_shared_board[savedItemID]);
        }
        if (D_800D0590_D1190[padNo] & L_CBUTTONS) {
            savedItemID -= 1;
            if (savedItemID < 0) {
                savedItemID = 19;
            }
            func_8005D294_5DE94(temp_v0_2);
            func_8005B43C_5C03C(temp_v0_2, D_801010F8_114D18_shared_board[savedItemID], -1, -1);
            func_80061934_62534(temp_v0_2, D_80101148_114D68_shared_board[savedItemID]);
        }
        HuPrcVSleep();
             
    }

    MBHelpWinKill(D_801010D4_114CF4_shared_board);
    MBHelpWinKill(D_801010D8_114CF8_shared_board);
    MBHelpWinKill(D_801010DC_114CFC_shared_board);
    func_80061A5C_6265C(temp_v0_2, 0);
    func_8005F364_5FF64(temp_v0_2);
    omDelPrcObj(NULL);
}


void MBItemDescExec(s32 arg0) {
    Process* temp_s2;
    Process* temp_v0;

    temp_s2 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(MBItemDesc, 0x1005, 0, 0);
    temp_v0->user_data = (void*)arg0;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s2, temp_v0);
    HuPrcChildWait();
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_80102188_115DA8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_80102194_115DB4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021A4_115DC4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021AC_115DCC_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021B8_115DD8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021C4_115DE4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021D0_115DF0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5E80", D_801021DC_115DFC_shared_board);

void MBItemKSuitWalkExec(void) {
    s8 sp20[4];
    Vec sp28;
    char sp38[16];
    s32 sp4C;
    GW_PLAYER *curPlayer;
    s16 absSpace;
    s32 temp_s0_2;
    s32 coinsToLose;
    s32 totalCoinsToLose;
    s32 playersPassed;
    s32 curPlayerIndex;
    s32 i;

    curPlayerIndex = GwSystem.current_player_index;
    curPlayer = MBPlayerGet(CUR_PLAYER);
    if (GwPlayer[curPlayerIndex].itemTurn != 0) {
        for (playersPassed = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
            if (i == curPlayerIndex) {
                continue;
            }
            absSpace = MBMasuLinkMasuIdGet(GwPlayer[curPlayerIndex].clink, GwPlayer[curPlayerIndex].cidx);
            if (absSpace == MBMasuLinkMasuIdGet(GwPlayer[i].clink, GwPlayer[i].cidx)) {
                sp20[playersPassed++] = i;
            }
        }
        if (playersPassed != 0) {
            sp4C = func_800DBEC0_EFAE0_shared_board(curPlayerIndex);
            MBKSuitMotionSet(-1, 2);
            MBVecForwardSet(&sp28);
            func_800ED128_100D48_shared_board(&curPlayer->player_obj->rot, &sp28, &curPlayer->player_obj->rot, 8);
            HuPrcSleep(8);
            totalCoinsToLose = 0;

            for (i = 0; i < playersPassed; i++) {
                if (GwPlayer[sp20[i]].coin != 0) {
                    if (GwPlayer[sp20[i]].coin < 20) {
                        coinsToLose = GwPlayer[sp20[i]].coin;
                    } else {
                        coinsToLose = 20;
                    }
                    sprintf(sp38, "%2d", coinsToLose);
                    MBDlgWinInsertCreate(-1, 0x3A15, mbCharNameMesTbl[GwPlayer[sp20[i]].chr], (s32)sp38, mbCharNameMesTbl[GwPlayer[curPlayerIndex].chr], 0, 0);
                    temp_s0_2 = -coinsToLose;
                    MBDlgWinClose();
                    totalCoinsToLose += coinsToLose;
                    MBDlgWinKill();
                    func_8004ACE0_4B8E0(0, sp20[i]);
                    MBCoinChangeStatusCreate(sp20[i], temp_s0_2);
                    MBCoinTakeCreate(sp20[i], temp_s0_2);
                    HuPrcSleep(30);
                } else {
                    MBDlgWinInsertCreate(-1, 0x3A16, mbCharNameMesTbl[GwPlayer[sp20[i]].chr], NULL, 0, 0, 0);
                    MBDlgWinClose();
                    MBDlgWinKill();
                    do {
                    } while (0); // TODO: required to match
                }
            }

            if (totalCoinsToLose != 0) {
                MBCoinChangeCreate(curPlayerIndex, totalCoinsToLose);
                MBCoinTakeCreate(curPlayerIndex, totalCoinsToLose);
                HuPrcSleep(30);
            }
            if (sp4C != 0) {
                func_800DB884_EF4A4_shared_board(GwSystem.current_player_index);
            }
            MBKSuitMotionSet(0, 2);
        }
    }

    if (D_800D41B0_D4DB0[4] == 0) {
        MBItemKSuitEnd();
    }
}

void MBItemKSuitEnd(void) {
    s32 curPlayerIndex = GwSystem.current_player_index;
    if (GwPlayer[curPlayerIndex].itemTurn) {
        MBItemSubFunctions[IFUNC_BOWSER_SUIT_END]();
        GwPlayer[curPlayerIndex].itemTurn = 0;
    }
}

void MBItemMajinLampStarExec(void) {
    MBItemSubFunctions[9]();
}

s32 MBItemFind(s32 playerNo, s32 itemID) {
    s32 i;

    if (playerNo == CUR_PLAYER) {
        playerNo = GwSystem.current_player_index;
    }

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        if (GwPlayer[playerNo].itemNo[i] == itemID) {
            break;
        }
    }

    if (i == ARRAY_COUNT(GwPlayer->itemNo)) {
        return ITEM_NONE;
    } else {
        return i;
    }
}

s32 MBItemFindEmpty(s32 arg0) {
    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }

    return MBItemFind(arg0, -1);
}

void MBItemRemoveEmpty(s32 arg0) {
    s8 *playerItems;
    s32 i;

    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }

    playerItems = GwPlayer[arg0].itemNo;

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo) - 1; i++) {
        if (playerItems[i] == ITEM_NONE) {
            playerItems[i] = playerItems[i + 1];
            playerItems[i + 1] = ITEM_NONE;
        }
    }
}

void MBItemSelNoClear(void) {
    D_80100F90_114BB0_shared_board = -1;
}

s32 MBItemSelNoGet(void) {
    return D_80100F90_114BB0_shared_board;
}

void MBItemSelNoSet(s32 arg0) {
    D_80100F90_114BB0_shared_board = arg0;
}

void func_800E4A94_F86B4_shared_board(void) {
    GW_PLAYER* temp_v0;
    GW_PLAYER* temp_v0_2;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0 = MBPlayerGet(i);
        temp_v0->rev &= ~(0x40 | 0x04 | 0x02);
        temp_v0_2 = MBPlayerGet(i);
        temp_v0_2->rev |= (0x20 | 0x08);
        GwSystem.slow_dice_flags |= (1 << i);
    }
}

void func_800E4B18_F8738_shared_board(void) {
    GW_PLAYER* temp_v0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0 = MBPlayerGet(i);
        temp_v0->rev &= ~(0x20 | 0x04 | 0x02);
        temp_v0->rev |= (0x80 | 0x40 | 0x10);
    }
}

void MBTelopInit(void) {
    D_80102D34_116954_shared_board = -1;
    D_80102D36_116956_shared_board = 0;
    D_80102D38_116958_shared_board = -1;
    D_80102D3A_11695A_shared_board[0] = D_80102D3A_11695A_shared_board[1] = -1;
    D_80102D40_116960_shared_board = NULL;
    D_80102D44_116964_shared_board = NULL;
}

void MBTelopClose(void) {
    if (D_80102D36_116956_shared_board & 0x20) {
        func_8003B128_3BD28(D_80102CC0_1168E0_shared_board);
    }
    if (D_80102D36_116956_shared_board & 0x10) {
        HuSprGrpKill(D_80102D38_116958_shared_board);
        HuSprKill(D_80102D3A_11695A_shared_board[0]);
        HuSprKill(D_80102D3A_11695A_shared_board[1]);
    }
    if (D_80102D40_116960_shared_board != NULL) {
        omDelObj(D_80102D40_116960_shared_board);
        D_80102D40_116960_shared_board = NULL;
    }
    if (D_80102D44_116964_shared_board != NULL) {
        omDelObj(D_80102D44_116964_shared_board);
        D_80102D44_116964_shared_board = NULL;
    }
    D_80102D36_116956_shared_board &= ~(0x20 | 0x10);
}


static void MBTelopLast5Main(omObjData *obj) {
    s32 i;
    f32 scale;

    switch (obj->work[0]) {
    case 0:
        obj->rot.x += 30.0f;
        scale = HuMathSin(obj->rot.x) * 0.5f + 1.0f;
        obj->scale.x = scale;
        HuSprScaleSet(D_80102D48_116968_shared_board[0], 0, scale, scale);
        if (obj->rot.x >= 360.0f) {
            obj->rot.x -= 360.0f;
        }
        break;
    case 1:
        break;

    case 2:
        for (i = 0; i < 2; i++) {
            if (D_80102D4C_11696C_shared_board[i] != -1) {
                HuSprKill(D_80102D4C_11696C_shared_board[i]);
            }
            if (D_80102D48_116968_shared_board[i] != -1) {
                HuSprGrpKill(D_80102D48_116968_shared_board[i]);
            }
        }
        D_80102D44_116964_shared_board = 0;
        omDelObj(obj);
        break;
    }
}

static void MBTelopPlayerMain(omObjData* arg0) {
    GW_PLAYER* player;
    s32 i;

    if (arg0->rot.y > 0.0f) {
        arg0->rot.y = arg0->rot.y - 1.0f;
    }
    
    switch (arg0->work[0]) {
    case 0:
        arg0->scale.x += 0.2f;
        HuSprScaleSet(D_80102D38_116958_shared_board, 0, arg0->scale.x, arg0->scale.x);
        if (arg0->scale.x >= 1.0f) {
            arg0->work[0] = 1;
            arg0->work[1] = 0xC;
            return;
        }
        break;
        
    case 1:
        if (arg0->work[3] == 6) {
            return;
        }
        
        if (arg0->work[1] != 0) {
            arg0->work[1]--;
            return;
        }
        
        if (!(GwPlayer[arg0->work[3]].stat & 1)) {
            if (!(arg0->rot.y <= 0.0f)) {
                if (!(D_800D5558_D6158[GwPlayer[arg0->work[3]].pad] & (A_BUTTON | B_BUTTON))) {
                    return;
                }
            }
        }
        arg0->work[0] = 2;
        return;

    case 2:
        arg0->scale.x += 0.2f;
        HuSprScaleSet(D_80102D38_116958_shared_board, 0, arg0->scale.x, arg0->scale.x);
        func_80055458_56058(D_80102D38_116958_shared_board, 0, (2.0f - arg0->scale.x) * 256.0f);
        if (arg0->scale.x >= 2.0f) {
            arg0->work[0] = 3;
            return;
        }
        break;
    case 3:
        HuSprGrpKill(D_80102D38_116958_shared_board);
        HuSprKill(D_80102D3A_11695A_shared_board[0]);
        D_80102D38_116958_shared_board = -1;
        D_80102D3A_11695A_shared_board[0] = -1;
        if (D_80102D44_116964_shared_board != NULL) {
            for (i = 0; i < 2; i++) {
                if (D_80102D4C_11696C_shared_board[i] != -1) {
                    HuSprKill(D_80102D4C_11696C_shared_board[i]);
                }
                if (D_80102D48_116968_shared_board[i] != -1) {
                    HuSprGrpKill(D_80102D48_116968_shared_board[i]);
                }
            }
            omDelObj(D_80102D44_116964_shared_board);
            D_80102D44_116964_shared_board = NULL;
        }
        D_80102D40_116960_shared_board = 0;
        omDelObj(arg0);
        break;
    }
}

static void MBTelopMgTypeMain(omObjData *obj) {
    s32 i;

    if (obj->work[3] != 0) {
        obj->work[3]--;
        if (obj->work[3] < 2 && (u32)(obj->work[0] - 4) < 2) {
            HuAudFXPlay(0x206);
        }
    } else {
        HuVecCopyXYZ(&D_80102D54_116974_shared_board->scale /* 0x24 */,
                     obj->trans.z, 1.0f, 1.0f);
        obj->trans.z += 0.12f;
        if (obj->trans.z > 1.0f) {
            obj->trans.z = 1.0f;
        }
    }

    if (obj->work[2] != 0) {
        obj->work[2]--;
        return;
    }

    obj->scale.x += 0.05f;
    if (obj->scale.x >= 1.0f) {
        obj->scale.x = 1.0f;
        obj->rot.z += 20.0f;
        if (obj->rot.z >= 360.0f) {
            obj->rot.z -= 360.0f;
        }
    }

    func_80054904_55504(D_80102CE0_116900_shared_board[D_80102D34_116954_shared_board],
        0,
        (obj->rot.x + 80.0f),
        (D_80102D58_116978_shared_board + 2.0f * HuMathSin(obj->rot.z)));

    for (i = 1; D_8010118C_114DAC_shared_board[obj->work[0]] >= i; i++) {
        func_80055458_56058(D_80102CE0_116900_shared_board[D_80102D34_116954_shared_board], i, (obj->scale.x * 256.0f));
    }
}

static void MBTelopLast5Create(void) {
    omObjData *obj;
    void *data;
    SomeStruct sp18 = D_80102250_115E70_shared_board;

    obj = omAddObj(-0x8000, 0, 0, -1, MBTelopLast5Main);
    D_80102D44_116964_shared_board = obj;
    obj->rot.x = 0.0f;

    if (D_80102D50_116970_shared_board == 0) {
        D_80102D48_116968_shared_board[0] = HuSprGrpCreate(1, 0);
        data = DataRead(0x1301E0);
        D_80102D4C_11696C_shared_board[0] = func_80055810_56410(data);
        DataClose(data);
        func_80055024_55C24(D_80102D48_116968_shared_board[0], 0,
                            D_80102D4C_11696C_shared_board[0], 0);
        HuSprPriSet(D_80102D48_116968_shared_board[0], 0, 0x10);
        HuSprAttrSet(D_80102D48_116968_shared_board[0], 0, 0x1000);
        func_80054904_55504(D_80102D48_116968_shared_board[0], 0, 0xA0, 0x32);
        D_80102D4C_11696C_shared_board[1] = -1;
        D_80102D48_116968_shared_board[1] = -1;
        obj->work[0] = 1;
        return;
    }

    D_80102D48_116968_shared_board[0] = HuSprGrpCreate(1, 0);
    data = DataRead(0x1301DF);
    D_80102D4C_11696C_shared_board[0] = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(D_80102D48_116968_shared_board[0], 0,
                        D_80102D4C_11696C_shared_board[0],
                        sp18.unk_00[D_80102D50_116970_shared_board]);
    HuSprPriSet(D_80102D48_116968_shared_board[0], 0, 0x10);
    HuSprAttrSet(D_80102D48_116968_shared_board[0], 0, 0x1000);
    func_80054904_55504(D_80102D48_116968_shared_board[0], 0, 0xA0, 0x32);

    D_80102D48_116968_shared_board[1] = HuSprGrpCreate(1, 0);
    data = DataRead(0x1301DE);
    D_80102D4C_11696C_shared_board[1] = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(D_80102D48_116968_shared_board[1], 0,
                        D_80102D4C_11696C_shared_board[1], 0);
    HuSprPriSet(D_80102D48_116968_shared_board[1], 0, 0x11);
    HuSprAttrSet(D_80102D48_116968_shared_board[1], 0, 0x1000);
    func_80054904_55504(D_80102D48_116968_shared_board[1], 0, 0xA0, 0x32);
    obj->work[0] = 0;
}

static void MBTelopPlayerCreate(s32 arg0) {
    omObjData* temp_v0_2;
    void* temp_v0;
    SomeStruct2 sp18 = D_8010225C_115E7C_shared_board;

    D_80102D38_116958_shared_board = HuSprGrpCreate(1U, 0);
    temp_v0 = DataRead(sp18.unk_00[GwPlayer[arg0].chr] | 0x130000);
    D_80102D3A_11695A_shared_board[0] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);
    func_80055024_55C24(D_80102D38_116958_shared_board, 0, D_80102D3A_11695A_shared_board[0], 0);
    HuSprPriSet(D_80102D38_116958_shared_board, 0, 0x10);
    HuSprAttrSet(D_80102D38_116958_shared_board, 0, 0x1000);
    func_80054904_55504(D_80102D38_116958_shared_board, 0, 0xA0, 0x78);
    temp_v0_2 = omAddObj(-0x8000, 0U, 0U, -1, MBTelopPlayerMain);
    D_80102D40_116960_shared_board = temp_v0_2;
    
    temp_v0_2->scale.x = 0;
    temp_v0_2->rot.x = 180.0f;
    temp_v0_2->rot.y = 150.0f;
    temp_v0_2->work[2] = 30;
    temp_v0_2->work[0] = 0;
    temp_v0_2->work[1] = 12;
    
    if (D_80102D44_116964_shared_board != 0) {
        temp_v0_2->work[1] = 24;
    }
    temp_v0_2->work[3] = arg0;
    if (arg0 >= 4) {
        temp_v0_2->work[3] = 4;
    }
}

s32 MBTelopPlayerCheck(void) {
    return D_80102D36_116956_shared_board & 4;
}

void MBTelopPlayerKill(void) {
    HuSprGrpKill(D_80102D38_116958_shared_board);
    HuSprKill(D_80102D3A_11695A_shared_board[0]);
    HuSprKill(D_80102D3A_11695A_shared_board[1]);
    omDelObj(D_80102D40_116960_shared_board);
    D_80102D40_116960_shared_board = 0;
    D_80102D36_116956_shared_board &= ~(0x20 | 0x10 | 0x08 | 0x04);
}

void MBTelopMgTypeCreate(s32 arg0, u32 arg1) {
    f32 sp18[2];
    Object* modelObj;
    omObjData* temp_v0_2;
    s32 i;
    s32 var_a0;
    s32 var_s1;

    if (!((u8) D_80102D36_116956_shared_board & 4) && ((var_s1 = func_800F52C4_108EE4_shared_board(), (((~var_s1 == 0) | (arg0 != 0)) == 0)) || (var_s1 = arg0 + 2, (arg0 != 0)))) {
        modelObj = MBModelFileCreate(0x130204, -1, 1.8f, 0, 0);
        D_80102D54_116974_shared_board = modelObj;
        func_8001C258_1CE58(modelObj->omObj1->model[0], 0x180, 0);
        func_8001C8E4_1D4E4(D_80102D54_116974_shared_board->omObj1->model[0], 0x1800U);
        func_8001C448_1D048(D_80102D54_116974_shared_board->omObj1->model[0]);
        MBModelTempAllocFree(D_80102D54_116974_shared_board);
        HuVecCopy3F(&D_80102D54_116974_shared_board->coords, &D_8010125C_114E7C_shared_board);
        HuVecCopyXYZ(&D_80102D54_116974_shared_board->scale, 0.0f, 1.0f, 1.0f);
        D_80102D54_116974_shared_board->coords.y += 56.0f;
        D_80102D34_116954_shared_board = func_8003A308_3AF08(D_80102CC0_1168E0_shared_board, D_80101170_114D90_shared_board[var_s1], 0, 0, 0U);
        MBCamera3Dto2D(&D_80102D54_116974_shared_board->coords, sp18);
        D_80102D58_116978_shared_board = (sp18[1] - 14.0f);
        D_80102D58_116978_shared_board = D_80102D58_116978_shared_board + ((1.3f - MBCameraZoomGet()) * 50.0f);
        func_80054904_55504(D_80102CE0_116900_shared_board[D_80102D34_116954_shared_board], 0, (D_80101194_114DB4_shared_board[var_s1] + 0x50), D_80102D58_116978_shared_board);
        
        for (i = 1; D_8010118C_114DAC_shared_board[var_s1] >= i; i++) {
            func_80055458_56058(D_80102CE0_116900_shared_board[D_80102D34_116954_shared_board], i, 0);
        }
        
        temp_v0_2 = omAddObj(-0x8000, 0, 0, -1, MBTelopMgTypeMain);
        D_80102D40_116960_shared_board = temp_v0_2;
        temp_v0_2->scale.x = 0.0f;
        temp_v0_2->trans.x = 400.0f;
        temp_v0_2->trans.z = 0.0f;
        temp_v0_2->rot.x = D_80101194_114DB4_shared_board[var_s1];
        temp_v0_2->rot.y = 0.0f;
        temp_v0_2->rot.z = 0.0f;
        temp_v0_2->work[0] = var_s1;
        temp_v0_2->work[1] = D_80102D34_116954_shared_board;
        temp_v0_2->work[2] = arg1 + 8;
        temp_v0_2->work[3] = arg1;
        D_80102D36_116956_shared_board = 38;
        if (var_s1 >= 3) {
            MBMgCallListCreate(var_s1 - 3);
        } else {
            MBMgCallListCreate(-1);
        }
    }
}

s32 MBTelopMgTypeStatGet(void) {
    return D_80102D36_116956_shared_board & (8 | 4);
}

void MBTelopMgTypeKill(void) {
    MBModelKill(D_80102D54_116974_shared_board);
    omDelObj(D_80102D40_116960_shared_board);
    D_80102D40_116960_shared_board = NULL;
    func_8003B128_3BD28(D_80102CC0_1168E0_shared_board);
    D_80102D36_116956_shared_board &= ~(0x20 | 0x10 | 0x08 | 0x04); 
}

static void MBTelopMain(void) {
    s32 temp_v0;
    s32 temp_v1;
    TelopData* temp_s0;

    temp_s0 = HuPrcCurrentGet()->user_data;
    while (1) {
        temp_v0 = temp_s0->unk_00;
        switch (temp_v0) {
        case 0:
            HuAudFXPlay(0x10C);
            if (temp_s0->playerNo == 0) {
                s32 turnsRemaining = GwSystem.total_turns - GwSystem.current_turn;
                D_80102D50_116970_shared_board = turnsRemaining;
                if (turnsRemaining >= 0) {
                    if (turnsRemaining < 5) {
                        MBTelopLast5Create();
                    } else if (turnsRemaining == 9) {
                        MBTelopLast5Create();
                    }
                }
            }
            MBTelopPlayerCreate(temp_s0->playerNo);
            temp_s0->unk_00++;
            break;
        case 1:
            if (D_80102D38_116958_shared_board == -1) {
                omDelPrcObj(NULL);
            }
            break;
        }
        HuPrcVSleep();
    }
}

Process* MBTelopCreate(s32 playerNo) {
    Process* proc;
    TelopData* telopData;

    proc = omAddPrcObj(MBTelopMain, 0, 0, 0x40);
    telopData = HuMemMemoryAlloc(proc->heap, sizeof(TelopData));
    proc->user_data = telopData;
    telopData->unk_00 = 0;
    telopData->playerNo = playerNo;
    return proc;
}

static void MBGuideCameraCreate(void) {
    Hu3DCamSetPerspective(1, 40.0f, 80.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_80102D60_116980_shared_board, &D_80102D6C_11698C_shared_board, &D_80102D78_116998_shared_board);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80102D84_1169A4_shared_board, &D_80102D90_1169B0_shared_board);
}

static void MBGuideMain(void) {
    while (1) {
        MBGuideCameraCreate();
        HuPrcVSleep();       
    }
}

UnkMBGuideData* MBGuideCreate(u32* arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a2;
    s32 var_a1;
    f32 var_f0;
    f32 var_f1;
    HmfModel* temp_a2;
    HmfModel* temp_hmf;
    Object* temp_v0_2;
    Process* temp_v0_7;
    UnkMBGuideData* temp_v0;
    s32 temp;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkMBGuideData));
    if (temp_v0 != NULL) {
        temp_v0_2 = MBModelCreate(0x3B, arg0);
        temp_v0->obj = temp_v0_2;
        temp_v0_2->flags |= 1;

        func_8001C8A8_1D4A8(temp_v0->obj->omObj1->model[0], 2);

        temp_a2 = &HmfModelData[temp_v0->obj->omObj1->model[0]];
        func_8008EBD0_8F7D0(15.0f, &temp_a2->mtx[6], &temp_a2->mtx[5]);

        HmfModelData[temp_v0->obj->omObj1->model[0]].mtx[9] = -HmfModelData[temp_v0->obj->omObj1->model[0]].mtx[6];

        temp_hmf = &HmfModelData[temp_v0->obj->omObj1->model[0]];
        temp_hmf->mtx[10] = temp_hmf->mtx[5];

        temp_hmf = &HmfModelData[temp_v0->obj->omObj1->model[0]];
        var_f0 = 0.0f;
        temp_hmf->mtx[14] = var_f0;
        temp_hmf->mtx[13] = var_f0;
        temp_hmf->mtx[12] = var_f0;
        temp_hmf->mtx[11] = var_f0;
        temp_hmf->mtx[8] = var_f0;
        temp_hmf->mtx[7] = var_f0;
        temp_hmf->mtx[4] = var_f0;
        temp_hmf->mtx[3] = var_f0;
        temp_hmf->mtx[2] = var_f0;
        temp_hmf->mtx[1] = var_f0;

        temp_hmf = &HmfModelData[temp_v0->obj->omObj1->model[0]];
        var_f1 = 1.0f;
        temp_hmf->mtx[15] = var_f1;
        temp_hmf->mtx[0] = var_f1;

        temp_v0_7 = omAddPrcObj(MBGuideMain, 0x4000U, 0, 0);
        temp_v0->unk_04 = temp_v0_7;
        temp_v0_7->user_data = temp_v0;

        temp_v0->spriteGroup = 0x69;

        D_80102D60_116980_shared_board.x = var_f0;
        D_80102D60_116980_shared_board.y = var_f0;
        D_80102D60_116980_shared_board.z = 120.0f;

        D_80102D6C_11698C_shared_board.x = var_f0;
        D_80102D6C_11698C_shared_board.y = var_f0;
        D_80102D6C_11698C_shared_board.z = var_f0;

        D_80102D78_116998_shared_board.x = var_f0;
        D_80102D78_116998_shared_board.y = var_f1;
        D_80102D78_116998_shared_board.z = var_f0;

        D_80102D84_1169A4_shared_board.x = 1280.0f;
        D_80102D84_1169A4_shared_board.y = 960.0f;
        D_80102D84_1169A4_shared_board.z = 511.0f;

        D_80102D90_1169B0_shared_board.x = 240.0f;
        D_80102D90_1169B0_shared_board.y =
            (f32)temp_v0->spriteGroup * 4.0f + 480.0f;
        D_80102D90_1169B0_shared_board.z = 511.5f;

        MBGuideCameraCreate();

        if (arg1 != 0) {
            var_a1 = temp_v0->spriteGroup;
            var_a1 = var_a1 + 0x5a + arg1;        
            temp_v0->amount = func_80060880_61480(0x5b, var_a1, 0x11);
            MBGuidePosSet(temp_v0, 0x69, arg1);
        } else {
            var_a1 = temp_v0->spriteGroup;
            var_a1 = var_a1 + 0x5a + arg1;  
            temp_v0->amount = func_80060880_61480(0x4b, var_a1, 0x10);
            MBGuidePosSet(temp_v0, 0x69, arg1);
        }
    }
    return temp_v0;
}

void MBGuideKill(UnkMBGuideData* arg0) {
    if (arg0 != NULL) {
        MBModelKill(arg0->obj);
        omDelPrcObj(arg0->unk_04);
        func_800610E0_61CE0(arg0->amount);
        HuMemMemoryFreeTemp(arg0);
    }
}

void MBGuidePosSet(UnkMBGuideData* arg0, s16 arg1, s16 arg2) {
    s16 var1;
    s16 var2;

    arg0->spriteGroup = arg1;
    D_80102D94_1169B4_shared_board = (arg1 * 4.0f) + 480.0f;
    if ((arg2) != 0) {
        var1 = 0x5B;
        var2 = 0x50;
        func_8005BA90_5C690(arg0->amount, var1, arg0->spriteGroup + (arg2 + var2));
    } else {
        var1 = 0x4B;
        var2 = 0x5A;
        func_8005BA90_5C690(arg0->amount, var1, arg0->spriteGroup + (arg2 + var2));
    }
}

//this should not be alone; probably belongs with strings like D_801021F0_115E10_shared_board " 1 VS 1 GAME";
const char D_801021EC_115E0C_shared_board[] = "";
