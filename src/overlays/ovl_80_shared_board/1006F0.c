#include "common.h"
#include "ovl_80.h"

typedef struct UnkProcess {
    /* 0x00 */ Vec vec1;
    /* 0x0C */ Vec vec2;
    /* 0x18 */ Vec *outVec;
    /* 0x1C */ s32 interpolationTime;
} UnkProcess;

f32 func_800D8DAC_EC9CC_shared_board(Vec*, Vec*);
Process *MBPlayerPosMoveCreate(Vec *, Vec *, Vec *, s32);
void MBVecNormalize(Vec *);

void MBMasuPosGet(s16 playerNo, s16 spaceIdx, Vec* arg2) {
    SpaceData* space;

    space = MBMasuGet(spaceIdx);
    arg2->x = space->coords.x;
    arg2->y = space->coords.y;
    arg2->z = space->coords.z;
}

void MBPlayerPosMasuSet(s16 playerNo, s16 arg1) {
    MBMasuPosGet(playerNo, arg1, &GwPlayer[playerNo].player_obj->coords);
}

void MBVecDirGet(Vec *arg0, Vec *arg1, Vec *arg2) {
    HuVecSubtract(arg2, arg1, arg0);
    MBVecNormalize(arg2);
}

void func_800ECB90_1007B0_shared_board(s16 playerIdx, Vec* arg1) {
    Object* playerObj;

    playerObj = MBPlayerGet(playerIdx)->player_obj;
    MBVecDirGet(&playerObj->coords, arg1, &playerObj->unk18);
}

void func_800ECBD0_1007F0_shared_board(Object* arg0, s16 arg1) {
    MBVecDirGet(&arg0->coords, &MBMasuGet(arg1)->coords, &arg0->unk18);
}

void MBVecForwardSet(Vec* arg0) {
    arg0->x = 0.0f;
    arg0->y = 0.0f;
    arg0->z = 1.0f;
}

void MBPlayerForwardSet(s16 arg0) {
    MBVecForwardSet(&MBPlayerGet(arg0)->player_obj->unk18);
}

void func_800ECC54_100874_shared_board(Object* arg0) {
    Vec sp10;
    Vec sp20;

    HuVecSubtract(&sp10, &gCameraList->pos, &arg0->coords);
    HuVecCopyXYZ(&sp20, sp10.x, 0.0f, sp10.z);
    arg0->omObj1->rot.x = -func_800D8DAC_EC9CC_shared_board(&sp10, &sp20);
    MBVecDirGet(&arg0->coords, &gCameraList->pos, &sp10);
    arg0->omObj1->rot.y = MBVecAngleGet(&sp10);
    arg0->omObj1->rot.z = 0;
}

void MBPlayerMasuSwap(s16 playerNoOne, s16 playerNoTwo) {
    GW_PLAYER* playerOne;
    GW_PLAYER* playerTwo;
    u8 prevClink;
    u8 prevCidx;
    u8 prevNlink;
    u8 prevNidx;
    u8 prevBlink;
    u8 prevBidx;
    u8 prevRev;

    playerOne = MBPlayerGet(playerNoOne);
    playerTwo = MBPlayerGet(playerNoTwo);
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
    GW_PLAYER* player;
    u8 newColor;

    player = MBPlayerGet(playerNo);
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

s32 MBRandCheck100(s8 arg0) {
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

void func_800ECFC8_100BE8_shared_board(void) {
    UnkVecStruct* temp_s0;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f22;
    s32 temp_s1;

    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_s1 = temp_s0->unk_1C;
    var_f22 = MBVecAngleGet(&temp_s0->unk_00);
    var_f20 = MBVecAngleGet(&temp_s0->coords) - var_f22;
    
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
    Process* temp_v0;
    UnkVecStruct* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800ECFC8_100BE8_shared_board, 0x4002U, 0, 0x80);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkVecStruct));
    temp_v0->user_data = temp_v0_2;
    HuVecCopyXYZ(&temp_v0_2->unk_00, arg0->x, 0.0f, arg0->z);
    HuVecCopyXYZ(&temp_v0_2->coords, arg1->x, 0.0f, arg1->z);
    temp_v0_2->unk_18 = arg2;
    temp_v0_2->unk_1C = arg3;
    temp_v0_2->unk_20 = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED1E4_100E04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED20C_100E2C_shared_board);

void func_800ED290_100EB0_shared_board(omObjData *obj) {
    UnkProcess *temp_s0;
    s32 interpolationTime;

    temp_s0 = HuPrcCurrentGet()->user_data;
    interpolationTime = temp_s0->interpolationTime;

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
    Process *interpProcess;
    UnkProcess *temp_v0_2;

    interpProcess = omAddPrcObj(func_800ED290_100EB0_shared_board, 0x4002, 0, 0x50);
    temp_v0_2 = HuMemMemoryAlloc(interpProcess->heap, sizeof(UnkProcess));
    interpProcess->user_data = temp_v0_2;
    temp_v0_2->vec1 = *arg0;
    temp_v0_2->vec2 = *arg1;
    temp_v0_2->outVec = outVec;
    temp_v0_2->interpolationTime = interpolationTime;
    return interpProcess;
}

// given a playerNo and interpolation time, walks a player to the next space
void MBPlayerPosMoveSet(s16 playerNo, s32 interpolationTime) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER *temp_v0;
    Process *temp_s0;

    temp_v0 = MBPlayerGet(playerNo);
    MBMasuPosGet(playerNo, MBMasuLinkMasuIdGet(temp_v0->clink, temp_v0->cidx), &sp10);     // get pos of current space
    MBMasuPosGet(playerNo, MBMasuLinkMasuIdGet(temp_v0->nlink, temp_v0->nidx), &sp20);     // get pos of next space
    MBVecDirGet(&sp10, &sp20, &temp_v0->player_obj->unk18);                                            // interpolate player position from cur space to next space
    temp_s0 = MBPlayerPosMoveCreate(&sp10, &sp20, &temp_v0->player_obj->coords, interpolationTime); // start process, return process handle
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0);                                                                 // wait on previous process to complete
    HuPrcChildWait();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED518_101138_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED5E0_101200_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED694_1012B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED75C_10137C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED810_101430_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", MBMoveMasuSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", MBMoveNextMasuSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", MBMoveBackMasuSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDA58_101678_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDAF0_101710_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDB98_1017B8_shared_board);
