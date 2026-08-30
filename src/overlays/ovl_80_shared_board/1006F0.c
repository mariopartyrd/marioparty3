#include "common.h"
#include "105D50.h"
#include "FA250.h"
#include "EC3B0.h"
#include "10C230.h"

typedef struct UnkProcess {
    /* 0x00 */ Vec vec1;
    /* 0x0C */ Vec vec2;
    /* 0x18 */ Vec *outVec;
    /* 0x1C */ s32 interpolationTime;
} UnkProcess;

extern s32 D_80101490_1150B0_shared_board[];

void MBMasuPosGet(s16 playerNo, s16 spaceIdx, Vec* out) {
    SpaceData* space = MBMasuGet(spaceIdx);

    out->x = space->coords.x;
    out->y = space->coords.y;
    out->z = space->coords.z;
}

void MBPlayerPosMasuSet(s16 playerNo, s16 spaceIdx) {
    MBMasuPosGet(playerNo, spaceIdx, &GwPlayer[playerNo].player_obj->coords);
}

void MBVecDirGet(Vec *arg0, Vec *arg1, Vec *arg2) {
    HuVecSubtract(arg2, arg1, arg0);
    MBVecNormalize(arg2);
}

void func_800ECB90_1007B0_shared_board(s16 playerIdx, Vec* arg1) {
    Object* playerObj;

    playerObj = MBPlayerGet(playerIdx)->player_obj;
    MBVecDirGet(&playerObj->coords, arg1, &playerObj->rot);
}

void func_800ECBD0_1007F0_shared_board(Object* arg0, s16 arg1) {
    MBVecDirGet(&arg0->coords, &MBMasuGet(arg1)->coords, &arg0->rot);
}

void MBVecForwardSet(Vec* out) {
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 1.0f;
}

void MBPlayerForwardSet(s16 playerNo) {
    MBVecForwardSet(&MBPlayerGet(playerNo)->player_obj->rot);
}

void func_800ECC54_100874_shared_board(Object* obj) {
    Vec sp10;
    Vec sp20;

    HuVecSubtract(&sp10, &gCameraList->pos, &obj->coords);
    HuVecCopyXYZ(&sp20, sp10.x, 0.0f, sp10.z);
    obj->omObj1->rot.x = -func_800D8DAC_EC9CC_shared_board(&sp10, &sp20);
    MBVecDirGet(&obj->coords, &gCameraList->pos, &sp10);
    obj->omObj1->rot.y = MBVecAngleGet(&sp10);
    obj->omObj1->rot.z = 0;
}

void MBPlayerMasuSwap(s16 playerNoOne, s16 playerNoTwo) {
    GW_PLAYER* playerOne = MBPlayerGet(playerNoOne);
    GW_PLAYER* playerTwo = MBPlayerGet(playerNoTwo);
    u8 prevClink;
    u8 prevCidx;
    u8 prevNlink;
    u8 prevNidx;
    u8 prevBlink;
    u8 prevBidx;
    u8 prevRev;

    prevClink = playerOne->clink;
    playerOne->clink = playerTwo->clink;
    playerTwo->clink = prevClink;
    prevCidx = playerOne->cidx;
    playerOne->cidx = playerTwo->cidx;
    playerTwo->cidx = prevCidx;
    prevNlink = playerOne->nlink;
    playerOne->nlink = playerTwo->nlink;
    playerTwo->nlink = prevNlink;
    prevNidx = playerOne->nidx;
    playerOne->nidx = playerTwo->nidx;
    playerTwo->nidx = prevNidx;
    prevBlink = playerOne->blink;
    playerOne->blink = playerTwo->blink;
    playerTwo->blink = prevBlink;
    prevBidx = playerOne->bidx;
    playerOne->bidx = playerTwo->bidx;
    playerTwo->bidx = prevBidx;
    prevRev = playerOne->rev;
    playerOne->rev &= ~1;
    playerOne->rev = (prevRev & ~1) | (playerTwo->rev & 1);
    playerTwo->rev = (playerTwo->rev & ~1) | (prevRev & 1);
}

void MBPlayerMasuColorSet(s16 playerNo, s16 spaceType) {
    GW_PLAYER* player = MBPlayerGet(playerNo);
    u8 newColor;

    switch (spaceType) {
    case SPACE_BLUE:
        newColor = 1;
        break;
    case SPACE_RED:
    case SPACE_BOWSER:
        newColor = 2;
        break;
    case SPACE_NONE:
    case SPACE_HAPPENING:
    case SPACE_CHANCE_TIME:
    case SPACE_ITEM:
    case SPACE_BANK:
    case SPACE_BATTLE:
    case SPACE_GAME_GUY:
        newColor = 4;
        break;
    default:
        newColor = 0;
        break;
    }
    player->color = newColor;
}

s16 MBTotalStarGet(void) {
    s32 starTotal = 0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        starTotal += MBPlayerGet(i)->star;
    }
    return starTotal;
}

s16 MBRandCheck100(s8 arg0) {
    u8 randByte = rand8();
    s32 chance = arg0;
    return (randByte * 99 >> 8) < chance;
}

s16 MBTurnRemain(void) {
    GW_SYSTEM *system = &GwSystem;

    return system->total_turns - system->current_turn + 1;
}

s32 func_800ECF18_100B38_shared_board(s16 arg0, f32 arg1) {
    Vec sp10;
    s32 var_v0;

    sp10.x = D_800CBB6E_CC76E[arg0];
    sp10.y = 0.0f;
    sp10.z = D_800D20A1_D2CA1[arg0];
    
    if (!(arg1 <= HuVecGetLength3F(&sp10))) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }
    return var_v0;
}

void func_800ECF9C_100BBC_shared_board(s16 arg0) {
    func_800EDC20_101840_shared_board(D_80101490_1150B0_shared_board[arg0]);
}

typedef struct UnkVecStruct {
    Vec unk_00;
    Vec coords; //?
    Vec* unk_18;
    s32 unk_1C;
    s32 unk_20;
} UnkVecStruct; //sizeof 0x24

typedef struct UnkVecStruct2 {
    Vec unk_00;
    Vec coords; //?
    Vec* unk_18;
    f32 unk_1C;
} UnkVecStruct2; //sizeof 0x20

static void func_800ECFC8_100BE8_shared_board(void) {
    UnkVecStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    s32 temp_s1 = temp_s0->unk_1C;
    f32 var_f22 = MBVecAngleGet(&temp_s0->unk_00);
    f32 var_f20 = MBVecAngleGet(&temp_s0->coords) - var_f22;
    f32 temp_f2;
    
    if (var_f20 < -180.0f) {
        var_f20 += 360.0f;
    }
    if (var_f20 > 180.0f) {
        var_f20 -= 360.0f;
    }
    
    temp_f2 = (f32) temp_s1;
    var_f20 = var_f20 / temp_f2;
    
    if (temp_s0->unk_20 != 0) {
        if (var_f20 >= 0.0f) {
            var_f20 += 720.0f / temp_f2;
        } else {
            var_f20 -= 720.0f / temp_f2;
        }
    }

    for (var_f22 = 0.0f; temp_s0->unk_1C != 0; ) {
        HuVecCopy3F(temp_s0->unk_18, &temp_s0->unk_00);
        var_f22 += var_f20;
        MBVecRotateY(temp_s0->unk_18, var_f22);
        temp_s0->unk_1C--;
        HuPrcVSleep();        
    }

    omDelPrcObj(NULL);
}

Process* func_800ED128_100D48_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3) {
    Process* temp_v0 = omAddPrcObj(func_800ECFC8_100BE8_shared_board, 0x4002U, 0, 0x80);
    UnkVecStruct* temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkVecStruct));

    temp_v0->user_data = temp_v0_2;
    HuVecCopyXYZ(&temp_v0_2->unk_00, arg0->x, 0.0f, arg0->z);
    HuVecCopyXYZ(&temp_v0_2->coords, arg1->x, 0.0f, arg1->z);
    temp_v0_2->unk_18 = arg2;
    temp_v0_2->unk_1C = arg3;
    temp_v0_2->unk_20 = 0;
    return temp_v0;
}

Process* func_800ED1E4_100E04_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3) {
    Process* proc = func_800ED128_100D48_shared_board(arg0, arg1, arg2, arg3);
    ((UnkVecStruct*)(proc->user_data))->unk_20 = 1;
    return proc;
}

void func_800ED20C_100E2C_shared_board(s16 playerNo, s32 arg1, s16 masuAbsIndex) {
    GW_PLAYER* player = MBPlayerGet(playerNo);
    Vec sp10;

    HuVecSubtract(&sp10, &MBMasuGet(masuAbsIndex)->coords, &player->player_obj->coords);
    MBVecNormalize(&sp10);
    func_800ED128_100D48_shared_board(&player->player_obj->rot, &sp10, &player->player_obj->rot, arg1);
}

void func_800ED290_100EB0_shared_board(omObjData *obj) {
    UnkProcess *temp_s0 = HuPrcCurrentGet()->user_data;
    s32 interpolationTime = temp_s0->interpolationTime;

    while (temp_s0->interpolationTime) {
        HuVecSubtract(temp_s0->outVec, &temp_s0->vec2, &temp_s0->vec1);
        HuVecMulScalar(temp_s0->outVec, 1.0f - ((1.0f / (f32)interpolationTime) * (f32)(temp_s0->interpolationTime - 1)), temp_s0->outVec);
        HuVecAdd(temp_s0->outVec, temp_s0->outVec, &temp_s0->vec1);
        temp_s0->interpolationTime--;
        HuPrcVSleep();
    }

    omDelPrcObj(NULL);
}

Process *MBPlayerPosMoveCreate(Vec *arg0, Vec *arg1, Vec *outVec, s32 interpolationTime) {
    Process *interpolationProcess = omAddPrcObj(func_800ED290_100EB0_shared_board, 0x4002, 0, 0x50);
    UnkProcess *temp_v0_2 = HuMemMemoryAlloc(interpolationProcess->heap, sizeof(UnkProcess));

    interpolationProcess->user_data = temp_v0_2;
    temp_v0_2->vec1 = *arg0;
    temp_v0_2->vec2 = *arg1;
    temp_v0_2->outVec = outVec;
    temp_v0_2->interpolationTime = interpolationTime;
    return interpolationProcess;
}

// given a playerNo and interpolation time, walks a player to the next space
void MBPlayerPosMoveSet(s16 playerNo, s32 interpolationFrameTotal) {
    Vec sp10;
    Vec sp20;
    Process *temp_s0;
    GW_PLAYER *player = MBPlayerGet(playerNo);

    MBMasuPosGet(playerNo, MBMasuLinkMasuIdGet(player->clink, player->cidx), &sp10);
    MBMasuPosGet(playerNo, MBMasuLinkMasuIdGet(player->nlink, player->nidx), &sp20);
    MBVecDirGet(&sp10, &sp20, &player->player_obj->rot);
    temp_s0 = MBPlayerPosMoveCreate(&sp10, &sp20, &player->player_obj->coords, interpolationFrameTotal);
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0);
    HuPrcChildWait();
}

static void func_800ED518_101138_shared_board(void) {
    UnkVecStruct2* temp_s0 = HuPrcCurrentGet()->user_data;
    f32 temp_f20 = temp_s0->unk_1C;
    Vec* temp_s1 = &temp_s0->coords;
    
    while (!(HuVecDistance(&temp_s0->unk_00, temp_s1) < temp_f20)) {
        HuVecSubtract(temp_s0->unk_18, temp_s1, &temp_s0->unk_00);
        MBVecNormalize(temp_s0->unk_18);
        HuVecMulScalar(temp_s0->unk_18, temp_f20, temp_s0->unk_18);
        HuVecAdd(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        HuVecCopy3F(&temp_s0->unk_00, temp_s0->unk_18);
        HuPrcVSleep();
    }

    HuVecCopy3F(temp_s0->unk_18, &temp_s0->coords);
    omDelPrcObj(NULL);
}

static Process* func_800ED5E0_101200_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Process* temp_v0 = omAddPrcObj(func_800ED518_101138_shared_board, 0x4002, 0, 0x50);
    UnkVecStruct2* temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkVecStruct2));

    temp_v0->user_data = temp_v0_2;
    temp_v0_2->unk_00 = *arg0;
    temp_v0_2->coords = *arg1;
    temp_v0_2->unk_18 = arg2;
    temp_v0_2->unk_1C = arg3;
    return temp_v0;
}


static void func_800ED694_1012B4_shared_board(void) {
    UnkVecStruct2* temp_s0 = HuPrcCurrentGet()->user_data;
    f32 temp_f20 = temp_s0->unk_1C;
    s32 var_s1 = 0;

    while (1) {
        if (HuVecDistance(&temp_s0->unk_00, &temp_s0->coords) < temp_f20) {
            var_s1 = 1;
        }
        HuVecSubtract(temp_s0->unk_18, &temp_s0->coords, &temp_s0->unk_00);
        MBVecNormalize(temp_s0->unk_18);
        HuVecMulScalar(temp_s0->unk_18, temp_f20, temp_s0->unk_18);
        HuVecAdd(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        HuVecCopy3F(&temp_s0->unk_00, temp_s0->unk_18);
            
        if (var_s1 != 0) {
            break;
        }
        HuPrcVSleep();
    }
    

    omDelPrcObj(NULL);
}

Process* func_800ED75C_10137C_shared_board(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Process* temp_v0 = omAddPrcObj(func_800ED694_1012B4_shared_board, 0x4002, 0, 0x50);
    UnkVecStruct2* temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkVecStruct2));

    temp_v0->user_data = temp_v0_2;
    temp_v0_2->unk_00 = *arg0;
    temp_v0_2->coords = *arg1;
    temp_v0_2->unk_18 = arg2;
    temp_v0_2->unk_1C = arg3;
    return temp_v0;
}

void func_800ED810_101430_shared_board(s16 arg0, f32 arg1) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* temp_v0;
    Process* temp_s0;

    temp_v0 = MBPlayerGet(arg0);
    MBMasuPosGet(arg0, MBMasuLinkMasuIdGet(temp_v0->clink, temp_v0->cidx), &sp10);
    MBMasuPosGet(arg0, MBMasuLinkMasuIdGet(temp_v0->nlink, temp_v0->nidx), &sp20);
    MBVecDirGet(&sp10, &sp20, &temp_v0->player_obj->rot);
    temp_s0 = func_800ED5E0_101200_shared_board(&sp10, &sp20, &temp_v0->player_obj->coords, arg1);
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0);
    HuPrcChildWait();
}

void MBMoveMasuSet(s16 playerNo, s16 link, s16 idx) {
    GW_PLAYER* player;

    player = MBPlayerGet(playerNo);
    if (link > -1) {
        player->clink = link;
        player->nlink = link;
        player->blink = link;
    }
    if (idx > -1) {
        player->cidx = idx;
        player->nidx = idx + 1;
        player->bidx = idx - 1;
    }
}


void MBMoveNextMasuSet(s16 playerNo, s16 arg1, s16 arg2) {
    GW_PLAYER* player = MBPlayerGet(playerNo);

    if (arg1 > -1) {
        player->nlink = arg1;
    }
    if (arg2> -1) {
        player->nidx = arg2;
    }
}

void MBMoveBackMasuSet(s16 playerNo, s16 arg1, s16 arg2) {
    GW_PLAYER* player = MBPlayerGet(playerNo);

    if (arg1 > -1) {
        player->blink = arg1;
    }
    if (arg2 > -1) {
        player->bidx = arg2;
    }
}

s32 func_800EDA58_101678_shared_board(void) {
    s32 ret = 0;

    GWBoardFlagSet(GwSystem.unk_0E);
    GWBoardFlagSet(0xE);
    if (func_800F8858_10C478_shared_board() == 1) {
        if (GWBoardFlagCheck(3) != 0) {
            MBOvlCall(-2, 4, 0x192);
            ret = 1;
        }
    } else if (GWBoardFlagCheck(3) != 0) {
        func_800FF7C4_1133E4_shared_board(-2, 4, 2);
        ret = 1;
    }
    return ret;
}

typedef struct UnkUserData {
    Object* obj;
    f32 unk_04;
    f32 unk_08;
    f32 velocity;
} UnkUserData;

static void func_800EDAF0_101710_shared_board(void) {
    UnkUserData* temp_v0 = HuPrcCurrentGet()->user_data;
    Object* temp_s0 = temp_v0->obj;
    f32 temp_f28 = temp_v0->unk_04;
    f32 temp_f26 = temp_v0->unk_08;
    f32 temp_f24 = temp_v0->velocity;
    f32 var_f20 = 0.0f;

    while (1) {
        f32 temp_f0 = temp_f24 - (HuMathSin(var_f20) * temp_f26);
        var_f20 += temp_f28;
        temp_s0->velocity.x = temp_f0;
        if (var_f20 >= 360.0f) {
            var_f20 -= 360.0f;
        }
        HuPrcVSleep();        
    }
}

Process* func_800EDB98_1017B8_shared_board(Object* arg0, f32 arg1, f32 arg2) {
    Process* temp_v0 = omAddPrcObj(func_800EDAF0_101710_shared_board, 0xA, 0, 0x40);
    UnkUserData* temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkUserData));

    temp_v0->user_data = temp_v0_2;
    temp_v0_2->obj = arg0;
    temp_v0_2->unk_04 = arg1;
    temp_v0_2->unk_08 = arg2;
    temp_v0_2->velocity = arg0->velocity.x;
    return temp_v0;
}
