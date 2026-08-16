#include "common.h"
#include "ovl_80.h"

void func_800EDC4C_10186C_shared_board(s32 arg0);
u8 func_80017AD8_186D8(s32); //TODO: mismatches signature in 276470.c in vine with me
void func_80017954_18554(s16, s16, s16, s16);
void func_800333B0_33FB0(s16);
extern s32 D_800A12C0_A1EC0;
extern s32 D_800A12C4_A1EC4;

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC58_101878_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC74_101894_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC90_1018B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDF90_101BB0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDFAC_101BCC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDFC8_101BE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE2A4_101EC4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE2C0_101EE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE2DC_101EFC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE614_102234_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE688_1022A8_shared_board);

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

const u8 D_80102320_115F40_shared_board[] = {1, 2, 4, 8, 0, 0, 0, 0}; //0s are padding maybe?

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseDlgMesSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseHelpMesSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseHelpMesCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseMesMain);

// draws a message?
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseMesCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFE0C_103A2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseQuitMesCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFEF4_103B14_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFFE8_103C08_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseOptionExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseQuitWinExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0BF8_104818_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0C64_104884_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0D14_104934_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E28_104A48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E34_104A54_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0EF0_104B10_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPausePadCfgExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseModeExec);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", MBPauseCreate);
