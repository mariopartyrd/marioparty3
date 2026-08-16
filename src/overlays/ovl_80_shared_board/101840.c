#include "common.h"
#include "ovl_80.h"

void func_800EDC4C_10186C_shared_board(s32 arg0);
u8 func_80017AD8_186D8(s32); //TODO: mismatches signature in 276470.c in vine with me
void func_80017954_18554(s16, s16, s16, s16);
void func_800333B0_33FB0(s16);
void func_800EDC90_1018B0_shared_board(s32, s32, s32);
s32 func_8005B68C_5C28C(s16);
s16 func_8005E0C0_5ECC0(s16);
void func_8005FE54_60A54(s16, s16);
void func_800EDFC8_101BE8_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800EE2DC_101EFC_shared_board(s32 arg0, s32 arg1);
void MBPauseHelpMesSet(s32 arg0, s16 arg1);
void MBPauseDlgMesSet(s16 arg0, s32 arg1);
s32 MBPauseHelpMesCreate(s16 arg0, s16 arg1, s16 arg2);
s32 MBPauseMesNumGet(s32 arg0);
s16 func_8006014C_60D4C(s16);

extern s16 D_80105560_119180_shared_board[];
extern s32 D_80101514_115134_shared_board[];
extern s32 D_800A12C0_A1EC0;
extern s32 D_800A12C4_A1EC4;
extern s16 D_801014EA_11510A_shared_board;
extern s32 D_801014EC_11510C_shared_board;
extern s16 D_8010555A_11917A_shared_board;
extern s16 D_8010555E_11917E_shared_board;
extern UnkBoard8* D_80105550_119170_shared_board;
extern s32 D_80105558_119178_shared_board;
extern s32 D_8010555C_11917C_shared_board;
extern s32 D_80101560_115180_shared_board[];
extern s32 D_80101568_115188_shared_board[];
extern s32 D_80101570_115190_shared_board[];
extern s32 D_8010157C_11519C_shared_board[];
extern s32 D_80101588_1151A8_shared_board[];
extern s32 D_80101594_1151B4_shared_board;
extern s32 D_80101598_1151B8_shared_board;

UnkBoard8* MBGuideCreate(s32, s32);
void MBGuideKill(UnkBoard8*);
void func_80060C14_61814(s16, s32);
void func_80060EA8_61AA8(s16, s32);
void func_80061100_61D00(s16, s32);
extern s32 D_80101520_115140_shared_board[];
extern s32 D_80101540_115160_shared_board[];
extern s32 D_8010159C_1151BC_shared_board;
extern s16 D_80105556_119176_shared_board;

void func_800EDC4C_10186C_shared_board(s32 arg0);
u8 func_80017AD8_186D8(s32);
void func_80017954_18554(s16, s16, s16, s16);
void func_800333B0_33FB0(s16);
void func_800EDC90_1018B0_shared_board(s32, s32, s32);
s32 func_8005B68C_5C28C(s16);
s16 func_8005E0C0_5ECC0(s16);
void func_800EDFC8_101BE8_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800EE2DC_101EFC_shared_board(s32 arg0, s32 arg1);
void MBPauseHelpMesSet(s32 arg0, s16 arg1);
void MBPauseDlgMesSet(s16 arg0, s32 arg1);
s32 MBPauseHelpMesCreate(s16 arg0, s16 arg1, s16 arg2);
s32 MBPauseMesNumGet(s32 arg0);
s16 func_8006014C_60D4C(s16);
extern s16 D_80105560_119180_shared_board[];
extern s32 D_80101514_115134_shared_board[];
extern s32 D_800A12C0_A1EC0;
extern s32 D_800A12C4_A1EC4;
extern s16 D_801014E8_115108_shared_board;
extern s16 D_801014EA_11510A_shared_board;
extern s32 D_801014EC_11510C_shared_board;
extern s16 D_8010555A_11917A_shared_board;
extern s16 D_8010555E_11917E_shared_board;
extern UnkBoard8* D_80105550_119170_shared_board;
extern s32 D_80105558_119178_shared_board;
extern s32 D_8010555C_11917C_shared_board;
extern s32 D_80101560_115180_shared_board[];
extern s32 D_80101568_115188_shared_board[];
extern s32 D_80101570_115190_shared_board[];
extern s32 D_8010157C_11519C_shared_board[];
extern s32 D_80101588_1151A8_shared_board[];
extern s32 D_80101594_1151B4_shared_board;
extern s32 D_80101598_1151B8_shared_board;

void func_800EDC20_101840_shared_board(s32 arg0) {
    D_800A12C4_A1EC4 = arg0;
    func_800EDC4C_10186C_shared_board(arg0);
}

s32 func_800EDC40_101860_shared_board(void) {
    return D_800A12C4_A1EC4;
}

void func_800EDC4C_10186C_shared_board(s32 arg0) {
    D_800A12C0_A1EC0 = arg0;
}

void func_800EDC58_101878_shared_board(s32 arg0, s32 arg1) {
    func_800EDC90_1018B0_shared_board(arg0, arg1, 0);
}

void func_800EDC74_101894_shared_board(s32 arg0, s32 arg1) {
    func_800EDC90_1018B0_shared_board(arg0, arg1, 1);
}

void func_800EDC90_1018B0_shared_board(s32 arg0, s32 arg1, s32 arg2) {
    s16 sp18[MB_MAX_PLAYERS];
    s32 hasCom = 0;
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    s32 sp2C;
    s32 i;

    hasCom = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == arg1) {
            if (GwPlayer[i].stat & 1) {
                hasCom = 1;
                sp18[GwPlayer[i].pad] = -0x8000;
            } else {
                func_8005FE54_60A54(arg0, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (hasCom != 0) {
        func_8005B63C_5C23C(arg0, 2, 2);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        D_800A12C0_A1EC0 = D_800A12C4_A1EC4;
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    if (arg2 == 0) {
        while (func_8005E0C0_5ECC0(arg0) != 0) {
            HuPrcVSleep();
        }
    } else {
        while ((func_8005E0C0_5ECC0(arg0) != 0) && !(func_8005B68C_5C28C(arg0) & 0x200)) {
            HuPrcVSleep();
        }
        D_800CC69C_CD29C[arg0].unk20 = 7;
    }
    func_8005F904_60504();
}

void func_800EDF90_101BB0_shared_board(s32 arg0, s32 arg1, s32 arg2) {
    func_800EDFC8_101BE8_shared_board(arg0, arg1, arg2, 0);
}

void func_800EDFAC_101BCC_shared_board(s32 arg0, s32 arg1, s32 arg2) {
    func_800EDFC8_101BE8_shared_board(arg0, arg1, arg2, 1);
}

void func_800EDFC8_101BE8_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    u8 mask;
    s32 i;

    mask = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((i == arg1) || (i == arg2)) {
            if (GwPlayer[i].stat & 1) {
                sp18[GwPlayer[i].pad] = -0x8000;
            } else {
                mask |= sp20[GwPlayer[i].pad];
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (mask) {
        func_8005FE54_60A54(arg0, mask);
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    } else {
        func_8005B63C_5C23C(arg0, 2, 2);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], D_800A12C0_A1EC0);
        D_800A12C0_A1EC0 = D_800A12C4_A1EC4;
    }

    if (arg3 == 0) {
        while (func_8005E0C0_5ECC0(arg0) != 0) {
            HuPrcVSleep();
        }
    } else {
        while ((func_8005E0C0_5ECC0(arg0) != 0) && !(func_8005B68C_5C28C(arg0) & 0x200)) {
            HuPrcVSleep();
        }
        D_800CC69C_CD29C[arg0].unk20 = 7;
    }
    func_8005F904_60504();
}

void func_800EE2A4_101EC4_shared_board(s32 arg0) {
    func_800EE2DC_101EFC_shared_board(arg0, 0);
}

void func_800EE2C0_101EE0_shared_board(s32 arg0) {
    func_800EE2DC_101EFC_shared_board(arg0, 1);
}

void func_800EE2DC_101EFC_shared_board(s32 arg0, s32 arg1) {
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = {1, 2, 4, 8};
    u8 mask;
    s32 i;

    mask = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (!(GwPlayer[i].stat & 1)) {
            break;
        }
    }

    if (i == 4) {
        func_8005B63C_5C23C(arg0, 2, 2);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        func_8005F698_60298(-0x8000, -0x8000, -0x8000, -0x8000, D_800A12C0_A1EC0);
        D_800A12C0_A1EC0 = D_800A12C4_A1EC4;
        if (arg1 == 0) {
            while (func_8005E0C0_5ECC0(arg0) != 0) {
                HuPrcVSleep();
            }
        } else {
            while ((func_8005E0C0_5ECC0(arg0) != 0) && !(func_8005B68C_5C28C(arg0) & 0x200)) {
                HuPrcVSleep();
            }
            D_800CC69C_CD29C[arg0].unk20 = 7;
        }
    } else {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (GwPlayer[i].stat & 1) {
                sp18[GwPlayer[i].pad] = 0;
            } else {
                mask |= sp20[GwPlayer[i].pad];
                sp18[GwPlayer[i].pad] = -1;
            }
        }
        func_8005FE54_60A54(arg0, mask);
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
        if (arg1 == 0) {
            while (func_8005E0C0_5ECC0(arg0) != 0) {
                HuPrcVSleep();
            }
        } else {
            while ((func_8005E0C0_5ECC0(arg0) != 0) && !(func_8005B68C_5C28C(arg0) & 0x200)) {
                HuPrcVSleep();
            }
            D_800CC69C_CD29C[arg0].unk20 = 7;
        }
    }
    func_8005F904_60504();
}

const u8 pad[4] = {0, 0, 0, 0};

void func_800EE614_102234_shared_board(s32 arg0) {
    func_8005FE54_60A54(arg0, 0xF);
    func_8005F744_60344(-1, -1, -1, -1);
    while ((func_8005E0C0_5ECC0(arg0)) != 0) {
        HuPrcVSleep();
    }
    func_8005F904_60504();
}

void func_800EE688_1022A8_shared_board(Object* arg0, f32 arg1, f32 arg2) {
    arg0->velocity.y = arg1;
    arg0->velocity.z = arg2;
}

s32 func_800EE694_1022B4_shared_board(Object* arg0) {
    if (arg0->velocity.z == 0.0f) {
        return 0;
    } else {
        return 1;
    }
}

void func_800EE6C0_1022E0_shared_board(Object* arg0) {
    while (func_800EE694_1022B4_shared_board(arg0) != 0) {
        HuPrcVSleep();
    }
}

void func_800EE700_102320_shared_board(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80105718_119338_shared_board); i++) {
        D_80105718_119338_shared_board[i].unk_04 = NULL;
        D_80105718_119338_shared_board[i].unk_08 = NULL;
    }
}

void func_800EE740_102360_shared_board(void) {
    UnkBoard* temp_s1;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80105718_119338_shared_board); i++) {
        temp_s1 = &D_80105718_119338_shared_board[i];
        if (temp_s1->unk_08 != NULL) {
            omDelObj(temp_s1->unk_08);
            temp_s1->unk_08 = NULL;
        }
    }
}

void func_800EE7AC_1023CC_shared_board(omObjData *func) {
    UnkBoard *temp_s0;

    temp_s0 = &D_80105718_119338_shared_board[func->work[0]];
    if (HmfModelData[temp_s0->unk_04->omObj1->model[0]].unk40 ==
        D_800CCF58_CDB58[HmfModelData[temp_s0->unk_04->omObj1->model[0]].unk02].unk02) {
        MBMotionShiftSet(temp_s0->unk_04, temp_s0->unk_00, 0, 0xA, temp_s0->unk_02);
        temp_s0->unk_04 = NULL;
        temp_s0->unk_08 = NULL;
        omDelObj(func);
    }
}

u32 func_800EE884_1024A4_shared_board(Object *arg0, s16 arg1, s16 arg2) {
    omObjData *obj;
    UnkBoard *temp_s1;
    s32 i;
    s32 ret;

    for (i = 0; i < ARRAY_COUNT(D_80105718_119338_shared_board); i++) {
        temp_s1 = &D_80105718_119338_shared_board[i];
        if (temp_s1->unk_08 == NULL) {
            break;
        }
    }

    if (i != ARRAY_COUNT(D_80105718_119338_shared_board)) {
        obj = omAddObj(0x2000, 0, 0, -1, func_800EE7AC_1023CC_shared_board);
        temp_s1->unk_08 = obj;
        obj->work[0] = i;
        temp_s1->unk_04 = arg0;
        temp_s1->unk_00 = arg1;
        temp_s1->unk_02 = arg2;
        ret = i;
    } else {
        ret = -1;
    }
    return ret;
}

void func_800EE94C_10256C_shared_board(Object *arg0, s16 arg1, s32 arg2) {
    MBMotionShiftSet(arg0, arg1, 0, 0xA, arg2);
}

void MBModelMotionWait(Object *arg0) {
    while (!(MBMotionCheck(arg0) & 1)) {
        HuPrcVSleep();
    }
}

s32 BoardPlayerRankCalc(s32 player) {
    s32 rank;
    s32 i;
    s32 score[4];

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        score[i] = MBPlayerScoreGet(i);
    }

    for (rank = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((i != player) && (score[player] < score[i])) {
            rank++;
        }
    }
    return rank;
}

s32 MBPlayerStealRankGet(s32 arg0) {
    s32 var_a0_2;
    s32 var_a0;
    s32 i;
    s32 score[MB_MAX_PLAYERS];

    if (GWBoardFlagCheck(0xF) == 0) {
        return BoardPlayerRankCalc(arg0);
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        score[i] = MBPlayerScoreGet(i);
    }

    // calc what the highest mg coin total is
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].gamePrize) {
            var_a0_2 = GwPlayer[i].gamePrize;
        }
    }

    // award players 1000 points (a star) for having the highest mg coin total
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].gamePrize == var_a0_2) {
            score[i] += 1000;
        }
    }

    // calc what the highest amount of coins collected was
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].coinPrize) {
            var_a0_2 = GwPlayer[i].coinPrize;
        }
    }

    // award players 1000 points (a star) for having the highest amount of coins
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].coinPrize == var_a0_2) {
            score[i] += 1000;
        }
    }

    // calc what the highest amount of happening spaces landed on was
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].stats.prize.hatenaPrize) {
            var_a0_2 = GwPlayer[i].stats.prize.hatenaPrize;
        }
    }

    // award players 1000 points (a star) for landing on the most happening spaces
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].stats.prize.hatenaPrize == var_a0_2) {
            score[i] += 1000;
        }
    }

    for (i = 0, var_a0 = 0; i < MB_MAX_PLAYERS; i++) {
        if (i != arg0) {
            var_a0 += score[arg0] < score[i];
        }
    }

    return var_a0;
}

s32 MBPlayerScoreGet(s32 arg0) {
    return GwPlayer[arg0].star * 1000 + GwPlayer[arg0].coin;
}

s32 func_800EECF0_102910_shared_board(s32 arg0) {
    s32 var_a0_2;
    s32 i;
    s32 playerBaseScore;

    playerBaseScore = (GwPlayer[arg0].star * 1000) + GwPlayer[arg0].coin;

    if (GWBoardFlagCheck(0xF) != 0) {
        // calc what the highest mg coin total is
        for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
            if (var_a0_2 < GwPlayer[i].gamePrize) {
                var_a0_2 = GwPlayer[i].gamePrize;
            }
        }

        if (GwPlayer[arg0].gamePrize == var_a0_2) {
            playerBaseScore += 1000;
        }

        // calc what the highest amount of coins collected was
        for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
            if (var_a0_2 < GwPlayer[i].coinPrize) {
                var_a0_2 = GwPlayer[i].coinPrize;
            }
        }

        if (GwPlayer[arg0].coinPrize == var_a0_2) {
            playerBaseScore += 1000;
        }

        for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
            if (var_a0_2 < GwPlayer[i].stats.prize.hatenaPrize) {
                var_a0_2 = GwPlayer[i].stats.prize.hatenaPrize;
            }
        }

        if (GwPlayer[arg0].stats.prize.hatenaPrize == var_a0_2) {
            playerBaseScore += 1000;
        }
    }
    return playerBaseScore;
}

extern u16 D_800D5558_D6158[];

void func_800EEE84_102AA4_shared_board(void) {
    s32 i;

    HuPrcSleep(2);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (!(GwPlayer[i].stat & 1)) {
            break;
        }
    }

    if (i == MB_MAX_PLAYERS) {
        HuPrcSleep(30);
        return;
    }

    while (1) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (!(GwPlayer[i].stat & 1) &&
                (D_800D5558_D6158[GwPlayer[i].pad] & (A_BUTTON | B_BUTTON))) {
                break;
            }
        }

        if (i == MB_MAX_PLAYERS) {
            HuPrcVSleep();
        } else {
            break;
        }
    }
}

s32 MBRand(f32 arg0) { // 800EFE20 in duel mode,
    // rand8 returns an unsigned byte
    u8 randomByte1 = rand8();
    u8 randomByte2 = rand8();
    s32 shiftedByte1 = (randomByte1 << 8);

    // Normalize the 16-bit number to the range [0, 1), then multiply by arg0
    s32 scaledRandom = ((randomByte2 | shiftedByte1) / 65536.0f) * arg0;

    return scaledRandom;
}

// is there some kind of macro at play here? the cast to u8 is weird because `work` used to be u8[] in mp1/mp2
void MBGuideFaceCreate(Object *arg0, s16 arg1, s16 arg2, s32 arg3) {
    arg0->omObj1->work[0] = (u8)func_80017790_18390(arg0->omObj1->model[0], arg1, arg2, arg3);
    arg0->omObj1->work[1] = (u8)arg1;
    arg0->omObj1->work[2] = (u8)arg2;
}

void func_800EF068_102C88_shared_board(void) {
}

void MBGuideFaceSet(Object* arg0, s32 arg1) {
    func_800333B0_33FB0(arg0->omObj1->work[0]);
    arg0->omObj1->work[0] = func_80017AD8_186D8(arg1);
    func_80017954_18554(arg0->omObj1->model[0], arg0->omObj1->work[1], arg0->omObj1->work[2], arg0->omObj1->work[0]);
}

s32 func_800EF0D8_102CF8_shared_board(s32 arg0) {
    s32 randVal;
    s32 scoreIndex;
    s32 score[MB_MAX_PLAYERS];
    s32 curPlayerScore;
    s32 i, j;

    for (i = 0, scoreIndex = 0; i < MB_MAX_PLAYERS; i++) {
        for (j = 0; j < MB_MAX_PLAYERS; j++) {
            if (BoardPlayerRankCalc(j) == i) {
                score[scoreIndex++] = j;
            }
        }
    }

    while (1) {
        randVal = MBRand(100.0f);
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (D_801014C0_1150E0_shared_board[i] < randVal) {
                continue;
            } else {
                break;
            }
        }

        if (arg0 != 0 && score[i] == GwSystem.current_player_index) {
            continue;
        } else {
            break;
        }
    }

    // for some reason this requires reassigning i
    i = score[i];
    if (i >= MB_MAX_PLAYERS) {
        i = GwSystem.current_player_index + 1;
        i = (i < MB_MAX_PLAYERS) ? i : 0;
    }

    return i;
}

s32 MBPauseMesNumGet(s32 arg0) {
    return arg0;
}

// const u8 D_80102320_115F40_shared_board[] = {1, 2, 4, 8, 0, 0, 0, 0}; //0s are padding maybe?

extern s32 D_801014F0_115110_shared_board;
extern u8 D_801014F4_115114_shared_board[][3];
extern s32 D_801014D0_1150F0_shared_board[];
extern s32 D_80101504_115124_shared_board[];
void func_800EF208_102E28_shared_board(UnkBoard8* arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    u8 temp_s0;
    void* temp_s5;
    s32 i;

    temp_s5 = DataRead(0x13008A);
    sprintf(D_800D5218_D5E18, "%2d", arg2);
    
    for (i = 0; i < 2; i++) {
        temp_s0 = D_800D5218_D5E18[i];
        arg0->model[arg1] = func_80055810_56410(temp_s5);
        if (temp_s0 != 0x20) {
            func_80055024_55C24(arg0->spriteGroup, arg1, arg0->model[arg1], temp_s0 - 0x30);
        } else {
            func_80055024_55C24(arg0->spriteGroup, arg1, arg0->model[arg1], 0xA);
        }
        
        HuSprPriSet(arg0->spriteGroup, arg1, 7);
        HuSprAttrSet(arg0->spriteGroup, arg1, 0x01001000);
        func_80054904_55504(arg0->spriteGroup, arg1, arg3, arg4);
        func_80055420_56020(arg0->spriteGroup, arg1, D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][0], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][1], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][2]);
        arg1 += 1;
        arg3 += 0xE;        
    }
    DataClose(temp_s5);
}

UnkBoard8* MBPauseTurnNumCreate(void) {
    UnkBoard8* temp_s2;
    void* temp_v0_2;
    void* temp_v0_4;
    void* var_s0;

    temp_s2 = func_800F2C48_106868_shared_board(0x10, 0);
    D_801014F0_115110_shared_board = GwSystem.current_game_length;
    if (GwSystem.playMode & 4) {
        var_s0 = DataRead(0x13008B);
        D_801014F0_115110_shared_board = 4;
    } else {
        var_s0 = DataRead(D_80101504_115124_shared_board[GwSystem.current_game_length]);
    }
    temp_s2->model[0] = func_80055810_56410(var_s0);
    func_80055024_55C24(temp_s2->spriteGroup, 0, temp_s2->model[0], 0);
    HuSprPriSet(temp_s2->spriteGroup, 0, 7);
    HuSprAttrSet(temp_s2->spriteGroup, 0, 0x1000);
    func_80054904_55504(temp_s2->spriteGroup, 0, 0xA0, 0x73);
    func_80055420_56020(temp_s2->spriteGroup, 0, D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][0], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][1], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][2]);
    DataClose(var_s0);
    temp_v0_2 = DataRead(0x130088);
    temp_s2->model[1] = func_80055810_56410(temp_v0_2);
    func_80055024_55C24(temp_s2->spriteGroup, 1, temp_s2->model[1], 0);
    HuSprPriSet(temp_s2->spriteGroup, 1, 7);
    HuSprAttrSet(temp_s2->spriteGroup, 1, 0x1000);
    func_80054904_55504(temp_s2->spriteGroup, 1, 0xA0, 0x90);
    func_80055420_56020(temp_s2->spriteGroup, 1, D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][0], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][1], D_801014F4_115114_shared_board[D_801014F0_115110_shared_board][2]);
    DataClose(temp_v0_2);
    func_800EF208_102E28_shared_board(temp_s2, 2, GwSystem.total_turns, 0xCB, 0x90);
    func_800EF208_102E28_shared_board(temp_s2, 4, GwSystem.current_turn, 0xA1, 0x90);
    temp_v0_4 = DataRead(D_801014D0_1150F0_shared_board[GwSystem.current_board_index]);
    temp_s2->model[6] = func_80055810_56410(temp_v0_4);
    func_80055024_55C24(temp_s2->spriteGroup, 6, temp_s2->model[6], 0);
    HuSprPriSet(temp_s2->spriteGroup, 6, 7);
    HuSprAttrSet(temp_s2->spriteGroup, 6, 0x1000);
    func_80054904_55504(temp_s2->spriteGroup, 6, 0xA0, 0x3C);
    DataClose(temp_v0_4);
    return temp_s2;
}

void func_800EF67C_10329C_shared_board(UnkBoard8* arg0) {
    func_800F2CA4_1068C4_shared_board(arg0);
}

s16 MBPauseMainScrExec(s32 arg0) {
    Unk3* temp_s2;
    Unk3* temp_s3;
    s16 var_s0;
    UnkBoard8* temp_s1;

    temp_s3 = func_800E210C_F5D2C_shared_board(0xA, 0xAE, 0);
    temp_s2 = func_800E210C_F5D2C_shared_board(5, 0xBC, 0);
    temp_s1 = MBPauseTurnNumCreate();
    HuPrcVSleep();

    while (1) {
        HuPrcVSleep();
        if (D_800D5558_D6158[arg0] & 0x8000) {
            var_s0 = 4;
            break;
        } else if (D_800D5558_D6158[arg0] & 0x1000) {
            var_s0 = 0;
            break;
        }       
    }

    func_800EF67C_10329C_shared_board(temp_s1);
    MBHelpWinKill(temp_s3);
    MBHelpWinKill(temp_s2);
    return var_s0;
}

void func_800EF768_103388_shared_board(UnkBoard8* arg0, s16 arg1) {
    s32 i;
    Object* temp_v0;
    s16 temp_s2;
    s16 temp = arg0->spriteGroup;
    
    temp_v0 = arg0->unk_00; //TODO: this is wrong
    temp_v0->velocity.y = 4.0f;
    temp_v0->velocity.z = -0.5f;
    temp_s2 = (arg1 - temp) / 14;

    for (i = 0; i < 14; i++) {
        temp = arg0->spriteGroup;
        MBGuidePosSet(arg0, (temp + temp_s2), 8);
        HuPrcVSleep();        
    }
    MBGuidePosSet(arg0, arg1, 8);
}

void MBPauseDlgMesSet(s16 arg0, s32 arg1) {
    func_8005D294_5DE94(arg0);
    func_8005B43C_5C03C(arg0, MBPauseMesNumGet(arg1), -1, -1);
}

void MBPauseHelpMesSet(s32 arg0, s16 arg1) {
    func_8005D294_5DE94(arg0);
    func_8005B43C_5C03C(arg0, D_80101514_115134_shared_board[arg1], -2, -2);
}

s32 MBPauseHelpMesCreate(s16 arg0, s16 arg1, s16 arg2) {
    s16 sp18[2];
    s16 sp20[2];
    s32 win;

    func_80060394_60F94(1, sp18, D_80101514_115134_shared_board[0]);
    func_80060394_60F94(1, sp20, D_80101514_115134_shared_board[1]);

    if (sp20[0] > sp18[0]) {
        D_80105560_119180_shared_board[0] = sp20[0];
    } else {
        D_80105560_119180_shared_board[0] = sp18[0];
    }
    D_80105560_119180_shared_board[1] = sp18[1];
    arg1 += 0xA0;
    win = func_8005A968_5B568(arg1 - (D_80105560_119180_shared_board[0] / 2), arg2,
                              D_80105560_119180_shared_board[0], D_80105560_119180_shared_board[1], 0, 4);
    func_8005BE30_5CA30(win, 9);
    func_8005BEE0_5CAE0(win, 0);
    func_8005BDFC_5C9FC(win, 0);
    func_8005B63C_5C23C(win, 0, 0x20000);
    MBPauseHelpMesSet(win, arg0);
    return win;
}

typedef struct UnkPauseMesWork {
    /* 0x00 */ s32 *mes;
    /* 0x04 */ u16 unk_04;
} UnkPauseMesWork;

void MBPauseMesMain(void) {
    UnkPauseMesWork *work;
    s32 *mes;
    s16 sel;
    s16 sel2;
    s16 prev;
    s32 help;
    s32 i;
    GW_SYSTEM* system;

    work = HuPrcCurrentGet()->user_data;
    
    mes = work->mes;
    sel = work->unk_04;
    system = &GwSystem;
    prev = -1;

    if (D_801014EC_11510C_shared_board != 0) {
        D_80105558_119178_shared_board = MBPauseHelpMesCreate(0, 0, 0x92);
        D_8010555C_11917C_shared_board = MBPauseHelpMesCreate(2, 0x64, 0x92);
    }

    while (1) {
        if (D_801014EC_11510C_shared_board != 0) {
            sel2 = D_801014E8_115108_shared_board;
        } else {
            sel2 = func_8006014C_60D4C(sel);
        }

        if (((sel2 != prev) && (sel2 != -1)) || (D_801014EA_11510A_shared_board != 0)) {
            if ((D_801014EA_11510A_shared_board == 0) && (D_801014EC_11510C_shared_board != 0)) {
                switch (sel2) {
                case 0:
                case 7:
                    MBPauseHelpMesSet(D_80105558_119178_shared_board, 0);
                    break;
                default:
                    MBPauseHelpMesSet(D_80105558_119178_shared_board, 1);
                }
            }

            prev = sel2;
            D_801014EA_11510A_shared_board = 0;

            switch (mes[prev]) {
            case 0x5101:
                for (i = 0; i < 4; i++) {
                    if (GwPlayer[i].stat & 1) {
                        func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5104), i);
                    } else {
                        func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5103), i);
                    }
                }
                break;

            case 0x5105:
                if (system->show_minigame_explanations == 0) {
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5106), 0);
                } else {
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5107), 0);
                }
                break;

            case 0x5108:
                switch (system->message_speed) {
                case 0:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5109), 0);
                    break;
                case 1:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x510A), 0);
                    break;
                case 2:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x510B), 0);
                    break;
                }
                break;

            case 0x510C:
                switch (system->save_mode) {
                case 0:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x510D), 0);
                    break;
                case 1:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x510E), 0);
                    break;
                case 2:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x510F), 0);
                    break;
                }
                break;

            case 0x5121:
                switch (system->walk_speed) {
                case 0:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5122), 0);
                    break;
                case 1:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5123), 0);
                    break;
                case 2:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5124), 0);
                    break;
                }
                break;

            case 0x5127:
                switch (system->show_com_minigames) {
                case 0:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5128), 0);
                    break;
                case 1:
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x5129), 0);
                    break;
                }
                break;

            case 0x512C:
                if (_CheckFlag(0x20) != 0) {
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x512B), 0);
                } else {
                    func_8005B6BC_5C2BC(D_80105550_119170_shared_board->amount, MBPauseMesNumGet(0x512A), 0);
                }
                break;
            }

            MBPauseDlgMesSet(D_80105550_119170_shared_board->amount, mes[prev]);
        }
        HuPrcVSleep();
    }
}

// draws a message?
Process* MBPauseMesCreate(s32* arg0, s32 arg1, s16 arg2) {
    Process* proc;
    UnkPauseMesWork* temp_v0_2;

    proc = omAddPrcObj(MBPauseMesMain, 0x1005, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(proc->heap, sizeof(UnkPauseMesWork));
    proc->user_data = temp_v0_2;
    temp_v0_2->mes = arg0;
    temp_v0_2->unk_04 = arg2;
    D_801014EC_11510C_shared_board = arg1;
    return proc;
}

void func_800EFE0C_103A2C_shared_board(Process* arg0) {
    if (D_801014EC_11510C_shared_board != 0) {
        func_8005F364_5FF64(D_8010555A_11917A_shared_board);
        func_8005F364_5FF64(D_8010555E_11917E_shared_board);
    }
    omDelPrcObj(arg0);
}

s16 MBPauseQuitMesCreate(s32 arg0, s16 arg1) {
    s16 sp18[2];
    s16 temp_v0;

    func_80060394_60F94(1, sp18, arg0);
    temp_v0 = func_8005A968_5B568(0xA0 - sp18[0] / 2, arg1, sp18[0], sp18[1], 0, 0);
    func_8005B43C_5C03C(temp_v0, arg0, -1, -1);
    return temp_v0;
}

s16 func_800EFEF4_103B14_shared_board(void) {
    s16 var_t0;
    s16 var_a1;

    var_t0 = 0;
    var_a1 = D_800CC69C_CD29C->unk64;
    while (D_800CC69C_CD29C[var_a1].unk64 != -1) {
        if (D_800CC69C_CD29C[var_a1].unk_38 & 0x40) {
            var_t0 |= (u8)D_800CC69C_CD29C[var_a1].unk20; //TODO: why required cast?
        }
        var_a1 = D_800CC69C_CD29C[var_a1].unk64;
    }

    if (GwSystem.playMode & 4) {
        var_t0 = 1;
    }
    return var_t0;
}

void func_800EFFE8_103C08_shared_board(UnkBoard8 *arg0, s32 arg1) {
    void *data;
    s32 dataNum;
    GW_SYSTEM* system = &GwSystem;

    switch (arg1) {
    case 1:
        dataNum = D_80101560_115180_shared_board[system->show_minigame_explanations];
        break;
    case 2:
        dataNum = D_80101568_115188_shared_board[system->show_com_minigames];
        break;
    case 5:
        dataNum = D_80101570_115190_shared_board[system->message_speed];
        break;
    case 4:
        dataNum = D_8010157C_11519C_shared_board[system->walk_speed];
        break;
    case 6:
        dataNum = D_80101588_1151A8_shared_board[system->save_mode];
        break;
    case 3:
        if (_CheckFlag(0x20) != 0) {
            dataNum = D_80101598_1151B8_shared_board;
        } else {
            dataNum = D_80101594_1151B4_shared_board;
        }
        break;
    default:
        return;
    }

    data = DataRead(dataNum);
    HuSprKill(arg0->model[arg1]);
    arg0->model[arg1] = func_80055810_56410(data);
    DataClose(data);
    func_80055024_55C24(arg0->spriteGroup, arg1, arg0->model[arg1], 0);
    HuSprPriSet(arg0->spriteGroup, arg1, 8);
    HuSprAttrSet(arg0->spriteGroup, arg1, 0x1000);
    func_80054904_55504(arg0->spriteGroup, arg1,
                        ((arg1 % 4) << 6) + 0x46,
                        ((arg1 / 4) * 0x3C) + 0x3C);
    D_801014EA_11510A_shared_board = 1;
}


s32 MBPauseOptionExec(s32 arg0) {
    void *data;
    Process *mesProc;
    UnkBoard8 *icons;
    UnkBoard8 *cursor;
    s32 dataNum;
    s8 ret;
    s16 sel;
    s16 prevSel;
    s32 i;
    u8 sleepFlag;
    GW_SYSTEM* system;
    GW_COMMON* common = &GwCommon;
    s8 temp;

    ret = 4;
    sel = 0;
    prevSel = 0;
    mesProc =  NULL;
    icons = NULL; // s4
    cursor = NULL;
    sleepFlag = 0;
    system = &GwSystem;
    
    if (!D_80105556_119176_shared_board) {
        sel = D_801014E8_115108_shared_board;
        prevSel = sel;
        icons = func_800F2C48_106868_shared_board(8, 0);
        
        for (i = 0; i < 8; i++) {
            switch (i) {
            case 0:
                if ((func_800EFEF4_103B14_shared_board()) != 0) {
                    dataNum = D_8010159C_1151BC_shared_board;
                } else {
                    dataNum = D_80101540_115160_shared_board[0];
                }
                break;
            case 1:
                dataNum = D_80101560_115180_shared_board[system->show_minigame_explanations];
                break;
            case 2:
                dataNum = D_80101568_115188_shared_board[system->show_com_minigames];
                break;
            case 5:
                dataNum = D_80101570_115190_shared_board[system->message_speed];
                break;
            case 4:
                dataNum = D_8010157C_11519C_shared_board[system->walk_speed];
                break;
            case 6:
                dataNum = D_80101588_1151A8_shared_board[system->save_mode];
                break;
            case 3:
                if (_CheckFlag(0x20) != 0) {
                    dataNum = D_80101598_1151B8_shared_board;
                } else {
                    dataNum = D_80101594_1151B4_shared_board;
                }
                break;
            default:
                dataNum = D_80101540_115160_shared_board[i];
                break;
            }
    
            data = DataRead(dataNum);
            icons->model[i] = func_80055810_56410(data);
            DataClose(data);
            func_80055024_55C24(icons->spriteGroup, i, icons->model[i], 0);
            HuSprPriSet(icons->spriteGroup, i, 8);
            HuSprAttrSet(icons->spriteGroup, i, 0x1000);
            func_80054904_55504(icons->spriteGroup, i,
                                ((i % 4) << 6) + 0x46,
                                ((i / 4) * 0x3C) + 0x3C);
        }
    
        if (D_80105550_119170_shared_board == NULL) {
            HuPrcVSleep();
            D_80105550_119170_shared_board = MBGuideCreate(0, 8);
            func_8005E1A8_5EDA8(D_80105550_119170_shared_board->amount, 0x2D);
            MBModelTempAllocFree(D_80105550_119170_shared_board->unk_00);
            func_8001C258_1CE58(D_80105550_119170_shared_board->unk_00->omObj1->model[0], 0x8000, 0x8000);
            D_80105550_119170_shared_board->unk_00->flags |= 0x10;
            MBGuidePosSet(D_80105550_119170_shared_board, 0x104, 8);
            func_800EF768_103388_shared_board(D_80105550_119170_shared_board, 0x69);
            func_80061100_61D00(D_80105550_119170_shared_board->amount, 5);
            func_80060C14_61814(D_80105550_119170_shared_board->amount, 1);
        }
    
        cursor = func_800F2C48_106868_shared_board(1, 0);
        data = DataRead(0x13009C);
        cursor->model[0] = func_80055810_56410(data);
        DataClose(data);
        func_80055024_55C24(cursor->spriteGroup, 0, cursor->model[0], 0);
        HuSprPriSet(cursor->spriteGroup, 0, 7);
        HuSprAttrSet(cursor->spriteGroup, 0, 0x1000);
        func_80054904_55504(cursor->spriteGroup, 0,
                            ((D_801014E8_115108_shared_board % 4) * 64) + 0x2A,
                            ((D_801014E8_115108_shared_board / 4) * 60) + 0x20);
    
        mesProc = MBPauseMesCreate(D_80101520_115140_shared_board, 1, -1);
    
    restart:
        while (1) {
            HuPrcVSleep();
    
            if (D_800D0590_D1190[arg0] & 0x200) {
                sel--;
                if ((sel == 3) || (sel == -1)) {
                    sel += 4;
                }
            }
            if (D_800D0590_D1190[arg0] & 0x100) {
                sel++;
                if ((sel == 4) || (sel == 8)) {
                    sel -= 4;
                }
            }
            if (D_800D0590_D1190[arg0] & 0x800) {
                sel -= 4;
                if (sel < 0) {
                    sel += 8;
                }
            }
            if (D_800D0590_D1190[arg0] & 0x400) {
                sel += 4;
                if (sel >= 8) {
                    sel -= 8;
                }
            }
    
            if (D_800C9520_CA120[arg0] & 0x8000) {
                HuAudFXPlay(2);
                break;
            }
            if (D_800C9520_CA120[arg0] & 0x4000) {
                HuAudFXPlay(4);
                sel = -1;
                break;
            }
    
            if (sel != -1) {
                D_801014E8_115108_shared_board = sel;
            }
            if (prevSel != sel) {
                prevSel = sel;
                HuAudFXPlay(1);
            }
            func_80054904_55504(cursor->spriteGroup, 0,
                                ((D_801014E8_115108_shared_board % 4) * 64) + 0x2A,
                                ((D_801014E8_115108_shared_board / 4) * 0x3C) + 0x20);
        }
    
        switch (sel) {
        case 0:
            if ((func_800EFEF4_103B14_shared_board()) == 0) {
                ret = 2;
            }
            break;
        case 1:
            system->show_minigame_explanations ^= 1;
            func_800EFFE8_103C08_shared_board(icons, 1);
            break;
        case 2:
            system->show_com_minigames ^= 1;
            func_800EFFE8_103C08_shared_board(icons, 2);
            break;
        case 5:
            temp = (system->message_speed + 1);
            system->message_speed = temp % 3;
            func_800EFFE8_103C08_shared_board(icons, 5);
            break;
        case 4:
            temp = (system->walk_speed + 1);
            system->walk_speed = temp % 3;
            func_800EFFE8_103C08_shared_board(icons, 4);
            break;
        case 6:
            temp = (system->save_mode + 1);
            system->save_mode = temp % 3;
            func_800EFFE8_103C08_shared_board(icons, 6);
            break;
        case 3:
            if (_CheckFlag(0x20) != 0) {
                _ClearFlag(0x20);
            } else {
                _SetFlag(0x20);
            }
            func_800EFFE8_103C08_shared_board(icons, 3);
            break;
        case 7:
            ret = 9;
            break;
        case -1:
            ret = 1;
            break;
        }
    
        common->unk9E = system->save_mode;
        common->unk9F = system->show_minigame_explanations;
        common->unkA0 = system->message_speed;
        common->unkA1 = system->walk_speed;
        common->unkA2 = system->show_com_minigames;
        func_800ECF9C_100BBC_shared_board(common->unkA0);
        if ((ret == 2) || (ret == 9)) {
            func_800F2CA4_1068C4_shared_board(icons);
            func_800F2CA4_1068C4_shared_board(cursor);
            icons = NULL;
            cursor = NULL;
        }
    } else {
        ret = 0;
    }

    switch (ret) {
    case 0:
    case 1:
        if (D_80105550_119170_shared_board != NULL) {
            func_80060EA8_61AA8(D_80105550_119170_shared_board->amount, 1);
            func_800EF768_103388_shared_board(D_80105550_119170_shared_board, 0x104);
            MBGuideKill(D_80105550_119170_shared_board);
            D_80105550_119170_shared_board = NULL;
            if (icons != NULL) {
                func_800F2CA4_1068C4_shared_board(icons);
                func_800F2CA4_1068C4_shared_board(cursor);
            }
            sleepFlag = 1;
        }
        break;
    case 4:
        goto restart;
    }

    if (mesProc != NULL) {
        func_800EFE0C_103A2C_shared_board(mesProc);
    }
    if (sleepFlag != 0) {
        HuPrcSleep(5);
    }
    return ret;
}

s32 MBPauseMesNumGet(s32);
s16 func_8005E0C0_5ECC0(s16);
extern s32 D_801015A0_1151C0_shared_board;

s32 MBPauseQuitWinExec(s32 arg0) {
    Process* temp_s3;
    s16 temp_v0;
    s16 temp;

    temp_v0 = MBPauseQuitMesCreate(MBPauseMesNumGet(0x511E), 0x36);
    func_8005BE30_5CA30(temp_v0, 5);
    func_8005BEE0_5CAE0(temp_v0, 0xFF);
    func_8005B43C_5C03C(temp_v0, MBPauseMesNumGet(0x511E), -1, -1);
    func_8005BDFC_5C9FC(temp_v0, 0);
    
    while ((func_8005E0C0_5ECC0(temp_v0)) != 0) {
        HuPrcVSleep();
    }
    
    temp_s3 = MBPauseMesCreate(&D_801015A0_1151C0_shared_board, 0, temp_v0);
    func_8005FE54_60A54(temp_v0, 1 << arg0);
    temp = func_8005E1D8_5EDD8(temp_v0, 0, 0);
    if (temp == 1) {
        D_80105556_119176_shared_board = 1;
    }
    omDelPrcObj(temp_s3);
    func_8005F364_5FF64(temp_v0);
    return 4;
}

s32 func_800F0BF8_104818_shared_board(s16 arg0) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        player = MBPlayerGet(i);
        if (!(player->stat & 1)) {
            if (player->pad == arg0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_800F0C64_104884_shared_board(GW_PLAYER* arg0, s16 arg1) {
    GW_PLAYER* player;
    s32 i;
    u8 pad;

    pad = arg0->pad;
    if (arg1 < 4) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            player = MBPlayerGet(i);
            if (player->pad != arg1) {
                continue;
            }
            player->pad = pad;
            arg0->pad = arg1;
            arg0->stat &= ~1;
            return;
        }        
    } else {
        arg0->stat |= 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0D14_104934_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E28_104A48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E34_104A54_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0EF0_104B10_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPausePadCfgExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseModeExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseCreate);
