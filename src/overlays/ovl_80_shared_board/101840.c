#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC20_101840_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC40_101860_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EDC4C_10186C_shared_board);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE694_1022B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE6C0_1022E0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE700_102320_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE740_102360_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EE7AC_1023CC_shared_board);

u32 func_800EE884_1024A4_shared_board(Object* arg0, s16 arg1, s16 arg2) {
    omObjData* obj;
    UnkBoard* temp_s1;
    s32 i;
    s32 ret;

    for (i = 0; i < ARRAY_COUNT(D_80105718_119338_shared_board); i++) {
        temp_s1 = &D_80105718_119338_shared_board[i];
        if (temp_s1->unk_08 == NULL) {
            break;
        }
    }

    if (i != ARRAY_COUNT(D_80105718_119338_shared_board)) {
        obj = omAddObj(0x2000, 0U, 0U, -1, func_800EE7AC_1023CC_shared_board);
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

void func_800EE94C_10256C_shared_board(Object* arg0, s16 arg1, s32 arg2) {
    MBMotionShiftSet(arg0, arg1, 0, 0xA, arg2);
}

void func_800EE97C_10259C_shared_board(Object* arg0) {
    while (!(MBMotionCheck(arg0) & 1)) {
        HuPrcVSleep();
    }
}

s32 BoardPlayerRankCalc(s32 player) {
    s32 rank;
    s32 i;
    s32 score[4];

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        score[i] = func_800EECB0_1028D0_shared_board(i);
    }

    for (rank = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((i != player) && (score[player] < score[i])) {
            rank++;
        }
    }
    return rank;
}

s32 func_800EEA58_102678_shared_board(s32 arg0) {
    s32 var_a0_2;
    s32 var_a0;
    s32 i;
    s32 score[MB_MAX_PLAYERS];

    if (GWBoardFlagCheck(0xF) == 0) {
        return BoardPlayerRankCalc(arg0);
    }
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        score[i] = func_800EECB0_1028D0_shared_board(i);
    }

    //calc what the highest mg coin total is
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].gamePrize) {
            var_a0_2 = GwPlayer[i].gamePrize;
        }
    }

    //award players 1000 points (a star) for having the highest mg coin total
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].gamePrize == var_a0_2) {
            score[i] += 1000;
        }
    }

    //calc what the highest amount of coins collected was
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].coinPrize) {
            var_a0_2 = GwPlayer[i].coinPrize;
        }
    }

    //award players 1000 points (a star) for having the highest amount of coins
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].coinPrize == var_a0_2) {
            score[i] += 1000;
        }
    }

    //calc what the highest amount of happening spaces landed on was
    for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
        if (var_a0_2 < GwPlayer[i].stats.prize.hatenaPrize) {
            var_a0_2 =  GwPlayer[i].stats.prize.hatenaPrize;
        }
    }

    //award players 1000 points (a star) for landing on the most happening spaces
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

s32 func_800EECB0_1028D0_shared_board(s32 arg0) {
    return GwPlayer[arg0].star * 1000 + GwPlayer[arg0].coin;
}

s32 func_800EECF0_102910_shared_board(s32 arg0) {
    s32 var_a0_2;
    s32 i;
    s32 playerBaseScore;

    playerBaseScore = (GwPlayer[arg0].star * 1000) + GwPlayer[arg0].coin;

    if (GWBoardFlagCheck(0xF) != 0) {
        //calc what the highest mg coin total is
        for (i = 0, var_a0_2 = -100000; i < MB_MAX_PLAYERS; i++) {
            if (var_a0_2 < GwPlayer[i].gamePrize) {
                var_a0_2 = GwPlayer[i].gamePrize;
            }
        }
        
        if (GwPlayer[arg0].gamePrize == var_a0_2) {
            playerBaseScore += 1000;
        }

        //calc what the highest amount of coins collected was
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
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].stat & 1)) {
            break;
        }
    }

    if (i == 4) {
        HuPrcSleep(30);
        return;
    }

    while (1) {
        for (i = 0; i < 4; i++) {
            if (!(GwPlayer[i].stat & 1) &&
                (D_800D5558_D6158[GwPlayer[i].pad] & (A_BUTTON | B_BUTTON))) {     
                break;
            }
        }
    
        if (i == 4) {
            HuPrcVSleep();
        } else {
            break;
        }
    }
}

s32 MBRand(f32 arg0) { //800EFE20 in duel mode,
    // rand8 returns an unsigned byte
    u8 randomByte1 = rand8();
    u8 randomByte2 = rand8();
    s32 shiftedByte1 = (randomByte1 << 8);

    // Normalize the 16-bit number to the range [0, 1), then multiply by arg0
    s32 scaledRandom = ((randomByte2 | shiftedByte1) / 65536.0f) * arg0;
    
    return scaledRandom;
}

//is there some kind of macro at play here? the cast to u8 is weird because `work` used to be u8[] in mp1/mp2
void func_800EEFEC_102C0C_shared_board(Object* arg0, s16 arg1, s16 arg2, s32 arg3) {
    arg0->omObj1->work[0] = (u8)func_80017790_18390(arg0->omObj1->model[0], arg1, arg2, arg3);
    arg0->omObj1->work[1] = (u8)arg1;
    arg0->omObj1->work[2] = (u8)arg2;
}

void func_800EF068_102C88_shared_board(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF070_102C90_shared_board);

s32 func_800EF0D8_102CF8_shared_board(s32 arg0) {
    s32 randVal;
    s32 scoreIndex;
    s32 score[4];
    s32 curPlayerScore;
    s32 i, j;

    for (i = 0, scoreIndex = 0; i < MB_MAX_PLAYERS; i++) {
        for (j = 0; j < 4; j++) {
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

    //for some reason this requires reassigning i
    i = score[i];
    if (i >= 4) {
        i = GwSystem.current_player_index + 1;
        i = (i < 4) ? i : 0;
    }
    
    return i;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF200_102E20_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/101840", D_80102320_115F40_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF208_102E28_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF3BC_102FDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF67C_10329C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF698_1032B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF768_103388_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF844_103464_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF898_1034B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EF8F4_103514_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFA34_103654_shared_board);

//draws a message?
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFD8C_1039AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFE0C_103A2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFE58_103A78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFEF4_103B14_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800EFFE8_103C08_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F01D0_103DF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0ABC_1046DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0BF8_104818_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0C64_104884_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0D14_104934_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E28_104A48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0E34_104A54_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F0EF0_104B10_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F102C_104C4C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F1C94_1058B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F1D34_105954_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/101840", func_800F1EC8_105AE8_shared_board);
