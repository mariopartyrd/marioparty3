#include "common.h"
#include "ovl_80.h"

typedef struct UnkProcess {
/* 0x00 */ Vec vec1;
/* 0x0C */ Vec vec2;
/* 0x18 */ Vec* outVec;
/* 0x1C */ s32 interpolationTime;
} UnkProcess;

void func_800ECAD0_1006F0_shared_board(s16, s16, Vec*);
Process* func_800ED35C_100F7C_shared_board(Vec*, Vec*, Vec*, s32);
void HuVecNormalizeSafe3F(Vec*);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECAD0_1006F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECB14_100734_shared_board);

void HuVecDirectionSafe3F(Vec* arg0, Vec* arg1, Vec* arg2) {
    HuVecSubtract(arg2, arg1, arg0);
    HuVecNormalizeSafe3F(arg2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECB90_1007B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECBD0_1007F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC0C_10082C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC28_100848_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC54_100874_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECD00_100920_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECDD4_1009F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECE4C_100A6C_shared_board);

s32 RNGPercentChance(s8 arg0) {
    u8 randByte = rand8();
    s32 chance = arg0;
    return (randByte * 99 >> 8) < chance;
}

s16 GetTurnsElapsed(void) {
    GW_SYSTEM* system = &GwSystem;
    
    return system->total_turns - system->current_turn + 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECF18_100B38_shared_board);

void func_800ECF9C_100BBC_shared_board(s16 arg0) {
    func_800EDC20_101840_shared_board(D_80101490_1150B0_shared_board[arg0]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECFC8_100BE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED128_100D48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED1E4_100E04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED20C_100E2C_shared_board);

void func_800ED290_100EB0_shared_board(omObjData* obj) {
    UnkProcess* temp_s0;
    s32 interpolationTime;

    temp_s0 = HuPrcCurrentGet()->user_data;
    interpolationTime = temp_s0->interpolationTime;
    
    while (temp_s0->interpolationTime) {
        HuVecSubtract(temp_s0->outVec, &temp_s0->vec2, &temp_s0->vec1);
        HuVecMulScalar(temp_s0->outVec, 1.0f - ((1.0f / (f32) interpolationTime) * (f32) (temp_s0->interpolationTime - 1)), temp_s0->outVec);
        HuVecAdd(temp_s0->outVec, temp_s0->outVec, &temp_s0->vec1);
        temp_s0->interpolationTime--;
        HuPrcVSleep();
    }

    omDelPrcObj(NULL);
}

Process* func_800ED35C_100F7C_shared_board(Vec* arg0, Vec* arg1, Vec* outVec, s32 interpolationTime) {
    Process* interpProcess;
    UnkProcess* temp_v0_2;

    interpProcess = omAddPrcObj(func_800ED290_100EB0_shared_board, 0x4002, 0, 0x50);
    temp_v0_2 = HuMemMemoryAlloc(interpProcess->heap, sizeof(UnkProcess));
    interpProcess->user_data = temp_v0_2;
    temp_v0_2->vec1 = *arg0;
    temp_v0_2->vec2 = *arg1;
    temp_v0_2->outVec = outVec;
    temp_v0_2->interpolationTime = interpolationTime;
    return interpProcess;
}

//given a playerNo and interpolation time, walks a player to the next space
void func_800ED410_101030_shared_board(s16 playerNo, s32 interpolationTime) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* temp_v0;
    Process* temp_s0;

    temp_v0 = MBGetPlayerStruct(playerNo);
    func_800ECAD0_1006F0_shared_board(playerNo, MBMasuLinkMasuIdGet(temp_v0->clink, temp_v0->cidx), &sp10); //get pos of current space
    func_800ECAD0_1006F0_shared_board(playerNo, MBMasuLinkMasuIdGet(temp_v0->nlink, temp_v0->nidx), &sp20); //get pos of next space
    HuVecDirectionSafe3F(&sp10, &sp20, &temp_v0->player_obj->unk18); //interpolate player position from cur space to next space
    temp_s0 = func_800ED35C_100F7C_shared_board(&sp10, &sp20, &temp_v0->player_obj->coords, interpolationTime); //start process, return process handle
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0); //wait on previous process to complete
    HuPrcChildWait();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED518_101138_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED5E0_101200_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED694_1012B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED75C_10137C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED810_101430_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED91C_10153C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED998_1015B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED9F8_101618_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDA58_101678_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDAF0_101710_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDB98_1017B8_shared_board);
