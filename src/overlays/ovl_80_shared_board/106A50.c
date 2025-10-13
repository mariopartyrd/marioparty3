#include "common.h"
#include "ovl_80.h"

#define HUNDREDS 0
#define TENS 1
#define ONES 2
#define DIGIT_X 10

#define COINS_HUNDREDS_DIGIT 4
#define COINS_TENS_DIGIT 5
#define COINS_ONES_DIGIT 6

#define STARS_TENS_DIGIT 7
#define STARS_ONES_DIGIT 8

#define ITEMS_POS_OFFSET_X 56
#define ITEMS_POS_OFFSET_Y 19

s32 D_80101780_1153A0_shared_board = -1;
s32 D_80101784_1153A4_shared_board = -1;
s32 D_80101788_1153A8_shared_board = -1;
s32 D_8010178C_1153AC_shared_board = -1;
s32 D_80101790_1153B0_shared_board = 1;
s16 PlayerBoardStatusRootPosition[8][2] = {
    {24, 16},   {191, 16},  {24, 186},   {191, 186},
    {-224, 16}, {432, 16},  {-224, 186}, {432, 186}
};

s16 PlayerBoardStatusRootPositionExtras[][2] = {
    {0x0030, 0x004C}, 
    {0x00A0, 0x004C}, 
    {0x0030, 0x007E}, 
    {0x00A0, 0x007E}, 
    {0x0068, 0x0073}, 
    {0x01B0, 0x0010}, 
    {0xFF20, 0x00BA}, 
    {0x01B0, 0x00BA}, 
    {0xFF20, 0x0010}, 
    {0x0068, 0x0073}, 
    {0xFF20, 0x00BA}, 
    {0x01B0, 0x00BA}, 
    {0xFF20, 0x0010}, 
    {0x01B0, 0x0010}, 
    {0x0068, 0x0073}, 
    {0x01B0, 0x00BA}, 
    {0xFF20, 0x0010}, 
    {0x01B0, 0x0010}, 
    {0xFF20, 0x00BA}, 
    {0x0068, 0x0073}, 
    {0x0220, 0x0018}, 
    {0x0220, 0x004A}, 
    {0x0220, 0x007C}, 
    {0x0220, 0x00AE}, 
    {0x00B8, 0x0018}, 
    {0x00B8, 0x004A}, 
    {0x00B8, 0x007C}, 
    {0x00B8, 0x00AE}, 
    {0x0017, 0x008C}, 
    {0x00BE, 0x008C}, 
    {0xFF20, 0x0010}, 
    {0x01B0, 0x0010}, 
    {0xFF20, 0x00BA}, 
    {0x01B0, 0x00BA}
};

s32 D_8010183C_11545C_shared_board[] = {
    0x0028005C, 0x00A8005C, 0x002800B8, 0x00A800B8
};

s32 D_8010184C_11546C_shared_board[] = {
    0x0028005C, 0x00A8005C, 0x002800B8, 0x00A800B8
};

s32 D_8010185C_11547C_shared_board[] = {
    0x00A8005C, 0x00A8008A, 0x00A800B8, 0x0028008A
};

s32 D_8010186C_11548C_shared_board[] = {
    0x0028005C, 0x002800B8, 0x00A8005C, 0x00A800B8
};

s32 D_8010187C_11549C_shared_board[] = {
    0x0020008A, 0x00B0005C, 0x00B0008A, 0x00B000B8
};

//TODO: this probably isn't all RGB data
RGB D_8010188C_1154AC_shared_board[] = {
    {0x80, 0x80, 0x80},
    {0x1A, 0x84, 0xFF},
    {0xFF, 0x1A, 0x2D},
    {0xFF, 0xFF, 0x00},
    {0x1A, 0xFF, 0x5F},
    {0x40, 0xC0, 0x00},
    {0x80, 0x80, 0x00},
    {0xC0, 0x40, 0x00},
    {0xFF, 0x00, 0x00},
    {0xFF, 0x00, 0x00},
    {0xFF, 0x00, 0x00},
    {0xC0, 0x40, 0x00},
    {0x80, 0x80, 0x00},
    {0x40, 0xC0, 0x00},
    {0x00, 0xFF, 0x00},
    {0x00, 0xFF, 0x00},
    {0x00, 0xFF, 0x00},
    {0x00, 0xC0, 0x40},
    {0x00, 0x80, 0x80},
    {0x00, 0x40, 0xC0},
    {0x00, 0x00, 0xFF},
    {0x00, 0x00, 0xFF},
    {0x00, 0x00, 0xFF},
    {0x00, 0x40, 0xC0},
    {0x00, 0x80, 0x80},
    {0x00, 0xC0, 0x40},
    {0x00, 0xFF, 0x00},
    {0x00, 0xFF, 0x00},
    {0x00, 0xFF, 0x00},
};

s16 D_801018E4_115504_shared_board[][2] = {
    {0x0000, 0x0000},
    {0x0000, 0x0000},
    {0x0003, 0x0007},
    {0x0003, 0xFFF7},
    {0x0010, 0x000A},
    {0x001A, 0x000A},
    {0x0024, 0x000A},
    {0x0010, 0xFFFA},
    {0x001A, 0xFFFA},
    {0xFFEC, 0x000E},
    {0xFFD3, 0x0000},
    {0x0003, 0x0017},
    {0x0014, 0x0017},
    {0x0025, 0x0017},
    {0x0003, 0xFFE9},
    {0x0014, 0xFFE9},
    {0x0025, 0xFFE9}    
};

u8 D_80101928_115548_shared_board[] = {
    0, 4, 0, 0, 8, 0, 12, 16, 20, 24, 0, 0, 0, 0, 32, 32, 32, 32, 28, 28, 28, 28, 0, 0, 0, 4, 0, 36
};

s32 D_80101944_115564_shared_board[] = {
    0x00130107, 0x00130108, 0x00130109, 0x0013010A, 0x0013010B, 0x0013010C, 0x0013010D, 0x0013010E
};

s32* D_80101964_115584_shared_board[] = {
    D_8010184C_11546C_shared_board,
    D_8010187C_11549C_shared_board,
    D_8010186C_11548C_shared_board,
    D_8010185C_11547C_shared_board,
    D_8010184C_11546C_shared_board,
    D_8010183C_11545C_shared_board
};

s32 D_8010197C_11559C_shared_board[] = {
    0x0013018E,
    0x0013018F,
    0x00130190,
    0x00130191,
    0x00130192,
    0x00130193,
    0x00130194,
    0x00130195,
    0x00130196,
    0x00130197,
    0x00130198,
    0x00130199,
    0x0013019A,
    0x0013019B,
    0x0013019C,
    0x0013019E,
    0x0013019F,
    0x001301A0,
    0x001301A1,
    0x0013019D,
    0x001301B6
};

s32 D_801019D0_1155F0_shared_board[] = {
    0x001301A2,
    0x001301A3,
    0x001301A4,
    0x001301A5,
    0x001301A6,
    0x001301A7,
    0x001301A8,
    0x001301A9,
    0x001301AA,
    0x001301AB,
    0x001301AC,
    0x001301AD,
    0x001301AE,
    0x001301AF,
    0x001301B0,
    0x001301B2,
    0x001301B3,
    0x001301B4,
    0x001301B5, 
};

void UpdatePlayerBoardStatus(s32 playerIndex) {
    UnkCoinThing coinDigits;
    BoardStatus* playerBoardStatus;
    s32 var_v1;
    s32 i;
    
    playerBoardStatus = &D_801057E0_119400_shared_board[playerIndex];
    if (playerBoardStatus->prevCoins != GwPlayer[playerIndex].coin) {
        coinDigits.digits[HUNDREDS] = GwPlayer[playerIndex].coin / 100;
        coinDigits.digits[TENS] = GwPlayer[playerIndex].coin / 10 % 10;
        coinDigits.digits[ONES] = GwPlayer[playerIndex].coin % 10;
        if (coinDigits.digits[HUNDREDS] != 0) {
            var_v1 = ((coinDigits.digits[HUNDREDS] != 0) ? 3 : 2);
        } else if (coinDigits.digits[TENS] != 0) {
            var_v1 = ((coinDigits.digits[HUNDREDS] != 0) ? 3 : 2);
        } else {
            var_v1 = 1;
        }
        
        if (var_v1 == 1) {
            HuSprAttrSet(playerBoardStatus->playerIndex, COINS_ONES_DIGIT, 0x8000);
            coinDigits.digits[TENS] = coinDigits.digits[ONES];
        } else {
            HuSprAttrReset(playerBoardStatus->playerIndex, COINS_ONES_DIGIT, 0x8000);
        }
    
        if (coinDigits.digits[HUNDREDS] == 0) {
            coinDigits.digits[HUNDREDS] = DIGIT_X;
        }
        for (i = 0; i < ARRAY_COUNT(coinDigits.digits); i++) {
            func_80055140_55D40(playerBoardStatus->playerIndex, i + COINS_HUNDREDS_DIGIT, coinDigits.digits[i], 0);
            func_800550F4_55CF4(playerBoardStatus->playerIndex, i + COINS_HUNDREDS_DIGIT, 1);
        }
    
        playerBoardStatus->prevCoins = GwPlayer[playerIndex].coin;
    }

    if (playerBoardStatus->prevStars != GwPlayer[playerIndex].star) {
        if (GwPlayer[playerIndex].star > 99) {
            func_80055140_55D40(playerBoardStatus->playerIndex, STARS_TENS_DIGIT, 9, 0);
            func_80055140_55D40(playerBoardStatus->playerIndex, STARS_ONES_DIGIT, 9, 0);
        } else {
            if (GwPlayer[playerIndex].star > 9) {
                func_80055140_55D40(playerBoardStatus->playerIndex, STARS_TENS_DIGIT, (GwPlayer[playerIndex].star / 10), 0);
            } else {
                func_80055140_55D40(playerBoardStatus->playerIndex, STARS_TENS_DIGIT, DIGIT_X, 0);
            }
            func_80055140_55D40(playerBoardStatus->playerIndex, STARS_ONES_DIGIT, GwPlayer[playerIndex].star % 10, 0);
        }
        func_800550F4_55CF4(playerBoardStatus->playerIndex, STARS_TENS_DIGIT, 1);
        func_800550F4_55CF4(playerBoardStatus->playerIndex, STARS_ONES_DIGIT, 1);
    
        playerBoardStatus->prevStars = GwPlayer[playerIndex].star;
    }
    coinDigits.unk_08[0] = GwPlayer[playerIndex].coin;
    coinDigits.unk_08[1] = GwPlayer[playerIndex].star;
    
    for (i = 0; i < ARRAY_COUNT(coinDigits.unk_08); i++) {
        if ((i != 0 && playerBoardStatus->counts[i] != coinDigits.unk_08[i]) || (i == 0 && D_801055E8_119208_shared_board[playerIndex] != NULL)) {
            if (playerBoardStatus->unk2[i] == 0) {
                func_800550B4_55CB4(playerBoardStatus->playerIndex, i + 2, 1.0f);
                playerBoardStatus->unk2[i] = 0xF;
            }
        }

        if (playerBoardStatus->unk2[i] != 0) {
            playerBoardStatus->unk2[i]--;
            if (playerBoardStatus->unk2[i] == 0) {
                if (i != 0 || D_801055E8_119208_shared_board[playerIndex] == NULL) {
                    func_80055140_55D40(playerBoardStatus->playerIndex, i + 2, 0, 0);
                    func_800550B4_55CB4(playerBoardStatus->playerIndex, i + 2, 0.0f);
                    func_800550F4_55CF4(playerBoardStatus->playerIndex, i + 2, 1);                       
                }
            }
        }
        playerBoardStatus->counts[i] = coinDigits.unk_08[i];
    }
    if (playerBoardStatus->unk1 != -1) {
        func_80055140_55D40(playerBoardStatus->playerIndex, DIGIT_X, playerBoardStatus->unk1, 0);
        func_800550F4_55CF4(playerBoardStatus->playerIndex, DIGIT_X, 1);
        return;
    }
    if (playerBoardStatus->prevRank != BoardPlayerRankCalc(playerIndex)) {
        func_80055140_55D40(playerBoardStatus->playerIndex, DIGIT_X, BoardPlayerRankCalc(playerIndex), 0);
        func_800550F4_55CF4(playerBoardStatus->playerIndex, DIGIT_X, 1);
        playerBoardStatus->prevRank = BoardPlayerRankCalc(playerIndex);
    }
}

void func_800F3370_106F90_shared_board(void) {
    s32 i, j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        BoardStatus* boardStatus = &D_801057E0_119400_shared_board[i];
        for (j = 0; j < 14; j++) {
            HuSprAttrSet(boardStatus->playerIndex, j, 0x8000);
        }
    }
}

void func_800F3400_107020_shared_board(omObjData* arg0) {
    BoardStatus* temp_s2;
    s32 var_v1;
    s32 i, j;

    while (1) {
        if (D_800D20B1_D2CB1 == 0) {
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                if (D_80101780_1153A0_shared_board != -1 &&
                    D_80101784_1153A4_shared_board != -1 &&
                    i != D_80101780_1153A0_shared_board &&
                    i != D_80101784_1153A4_shared_board) {
                    continue;
                }

                temp_s2 = &D_801057E0_119400_shared_board[i];

                if (temp_s2->uiUpdatePaused == FALSE) {
                    if (temp_s2->uiVisible & 1) {
                        for (j = 0; j < 14; j++) {
                            HuSprAttrSet(temp_s2->playerIndex, j, 0x8000);
                        }
                        continue;
                    }

                    for (j = 0; j < 14; j++) {
                        switch (j) {
                        case 9:
                            if (GwPlayer[i].stat & 1) {
                                break;
                            }
                            continue;
                        case 11:
                        case 12:
                        case 13:
                            if (GwPlayer[i].itemNo[j - 11] == ITEM_NONE) {
                                continue;
                            }

                            func_80055024_55C24(temp_s2->playerIndex, j, D_80105588_1191A8_shared_board[GwPlayer[i].itemNo[j - 11] + 10], 0);
                            func_800550F4_55CF4(temp_s2->playerIndex, j, 0);
                            HuSprPriSet(temp_s2->playerIndex, j, (i * 5) + 0x478E);
                            HuSprAttrSet(temp_s2->playerIndex, j, 0);
                            var_v1 = j;
                            if (i >= 2) {
                                var_v1 = j + 3;
                            }
                            func_80054904_55504(temp_s2->playerIndex, j, D_801018E4_115504_shared_board[var_v1][0], D_801018E4_115504_shared_board[var_v1][1]);
                            HuSprAttrSet(temp_s2->playerIndex, j, 0x8000);
                            if (D_80101790_1153B0_shared_board != 0) {
                                break;
                            }
                            continue;
                        case 6:
                            if (GwPlayer[i].coin < 10) {
                                continue;
                            }
                            break;
                        }
                        HuSprAttrReset(temp_s2->playerIndex, j, 0x8000);
                    }
                    UpdatePlayerBoardStatus(i);
                } else {
                    if (temp_s2->uiVisible & 1) {
                        for (j = 0; j < 5; j++) {
                            HuSprAttrSet(temp_s2->playerIndex, j, 0x8000);
                        }
                        HuSprAttrSet(temp_s2->playerIndex, 9, 0x8000);
                        continue;
                    }

                    for (j = 0; j < 2; j++) {
                        HuSprAttrReset(temp_s2->playerIndex, j, 0x8000);
                    }

                    for (j = 0; j < 3; j++) {
                        if (temp_s2->unk_40[j] != -1) {
                            HuSprAttrReset(temp_s2->playerIndex, (j + 2), 0x8000);
                        }
                    }

                    if ((GwPlayer[i].stat & 1) && !(temp_s2->uiVisible & 1)) {
                        HuSprAttrReset(temp_s2->playerIndex, 9, 0x8000);
                    } else {
                        HuSprAttrSet(temp_s2->playerIndex, 9, 0x8000);
                    }
                }
                if (temp_s2->unkE > 0) {
                    temp_s2->unkE--;
                    temp_s2->xPos += temp_s2->unk_20;
                    temp_s2->yPos += temp_s2->unk_24;
                    temp_s2->unk_20 += temp_s2->unk_28;
                    temp_s2->unk_24 += temp_s2->unk_2C;
                } else if (temp_s2->unkE == -1) {
                    temp_s2->unkE = -2;
                } else if (temp_s2->unkE != -2) {
                    temp_s2->xPos = temp_s2->unk_18;
                    temp_s2->yPos = temp_s2->unk_1C;
                    temp_s2->unkE = -1;
                }
                func_80054904_55504(temp_s2->playerIndex, 0,
                                    (s16)((s32)(temp_s2->xPos + 0.5f) + ITEMS_POS_OFFSET_X),
                                    (s16)((s32)(temp_s2->yPos + 0.5f) + ITEMS_POS_OFFSET_Y));
            }

            if (D_801055C2_1191E2_shared_board != -1) {
                D_801055C8_1191E8_shared_board += 0.1f;
                if (D_801055C8_1191E8_shared_board > 1.0f) {
                    D_801055C8_1191E8_shared_board = 1.0f;
                }
                HuSprScaleSet(D_801055C2_1191E2_shared_board, 0, D_801055C8_1191E8_shared_board, D_801055C8_1191E8_shared_board);
                if (D_801055E4_119204_shared_board > 0) {
                    D_801055E4_119204_shared_board--;
                    D_801055CC_1191EC_shared_board.x += D_801055D4_1191F4_shared_board.x;
                    D_801055CC_1191EC_shared_board.y += D_801055D4_1191F4_shared_board.y;
                    D_801055D4_1191F4_shared_board.x += D_801055DC_1191FC_shared_board.x;
                    D_801055D4_1191F4_shared_board.y += D_801055DC_1191FC_shared_board.y;
                    func_80054904_55504(D_801055C2_1191E2_shared_board, 0,
                                        D_801055CC_1191EC_shared_board.x,
                                        D_801055CC_1191EC_shared_board.y);
                }
            }
        }
        HuPrcVSleep();
    }
}

void func_800F39C0_1075E0_shared_board(s32 playerIndex) {
    s16 temp_s1;

    temp_s1 = D_801057E0_119400_shared_board[playerIndex].playerIndex;
    func_80055024_55C24(temp_s1, 1, D_80105588_1191A8_shared_board[playerIndex+1], 0);
    func_800550F4_55CF4(temp_s1, 1, 0);
    HuSprPriSet(temp_s1, 1, ((playerIndex * 5) + 0x4790));
    HuSprAttrSet(temp_s1, 1, 0);
    func_80054904_55504(temp_s1, 1, D_801018E4_115504_shared_board[1][0], D_801018E4_115504_shared_board[1][1]);
}

void func_800F3A80_1076A0_shared_board(s32 arg0) {
    s16 temp_s2;
    s32 i;

    temp_s2 = D_801057E0_119400_shared_board[arg0].playerIndex;

    for (i = 0; i < 2; i++) {
        func_80055024_55C24(temp_s2, i + 2, D_80105588_1191A8_shared_board[i+5], 0);
        HuSprPriSet(temp_s2, i + 2, ((arg0 * 5) + 0x4790));
        HuSprAttrReset(temp_s2, i + 2, 0xFFFF);
        HuSprAttrSet(temp_s2, i + 2, 0x1000);
        func_800552DC_55EDC(temp_s2, i + 2, 0.0f);
        func_80054904_55504(temp_s2, i + 2, D_801018E4_115504_shared_board[i + 2][0], D_801018E4_115504_shared_board[i + 2][1]);
        func_800550B4_55CB4(temp_s2, i + 2, 0.0f);
        func_80055458_56058(temp_s2, i + 2, 0x100);
    }
}

void func_800F3BD0_1077F0_shared_board(s32 arg0) {
    BoardStatus* temp_s4;
    s16 temp_s2;
    void* temp_v0;
    s32 i;

    temp_s4 = &D_801057E0_119400_shared_board[arg0];
    temp_s4->prevCoins = -1;
    temp_s4->prevStars = -1;
    temp_v0 = DataRead(0x1300CF);
    temp_s4->unk_3A = func_80055810_56410(temp_v0);
    temp_s2 = temp_s4->playerIndex;
    for (i = 0; i < 5; i++) {
        func_80055024_55C24(temp_s2, i + 4, temp_s4->unk_3A, 0);
        func_800550F4_55CF4(temp_s2, i + 4, 1);
        func_80055140_55D40(temp_s2, i + 4, 0xAU, 0);
        HuSprPriSet(temp_s2, i + 4, ((arg0 * 5) + 0x4790) & 0xFFFF);
        HuSprAttrReset(temp_s2, i + 4, 0xFFFFU);
        HuSprAttrSet(temp_s2, i + 4, 0U);
        func_80054904_55504(temp_s2, i + 4, D_801018E4_115504_shared_board[i + 4][0], D_801018E4_115504_shared_board[i + 4][1]);
        func_80055420_56020(temp_s2, i + 4, 0xFFU, 0xFFU, 0xFF);
        func_80055458_56058(temp_s2, i + 4, 0x100U);
        func_800552DC_55EDC(temp_s2, i + 4, 0.0f);        
    }
    DataClose(temp_v0);
}

void func_800F3D70_107990_shared_board(s32 arg0) {
    BoardStatus* temp_s0;
    s16 temp_v0;
    
    temp_s0 = &D_801057E0_119400_shared_board[arg0];
    temp_v0 = HuSprGrpCreate(0xE, 2);
    temp_s0->playerIndex = temp_v0;
    func_80055024_55C24(temp_v0, 0, D_80105588_1191A8_shared_board[0], 0);
    HuSprPriSet(temp_v0, 0, ((arg0 * 5) + 0x4790));
    HuSprAttrSet(temp_v0, 0, 0x1000);
    func_80054904_55504(temp_v0, 0, 0, 0);
}

void func_800F3E34_107A54_shared_board(s32 arg0) {
    BoardStatus* temp_v0;
    s16 temp_s0;

    temp_v0 = &D_801057E0_119400_shared_board[arg0];
    temp_v0->prevRank = -1;
    temp_s0 = temp_v0->playerIndex;
    func_80055024_55C24(temp_s0, 0xA, D_80105588_1191A8_shared_board[8], 0);
    func_800550F4_55CF4(temp_s0, 0xA, 1);
    func_80055140_55D40(temp_s0, 0xA, 0, 0);
    HuSprPriSet(temp_s0, 0xA, ((arg0 * 5) + 0x478F) & 0xFFFF);
    HuSprAttrSet(temp_s0, 0xA, 0);
    func_80054904_55504(temp_s0, 0xA, D_801018E4_115504_shared_board[10][0], D_801018E4_115504_shared_board[10][1]);
}

void func_800F3F0C_107B2C_shared_board(s32 playerIndex) {
    s16 temp_s2;

    temp_s2 = D_801057E0_119400_shared_board[playerIndex].playerIndex;
    func_80055024_55C24(temp_s2, 9, D_80105588_1191A8_shared_board[9], 0);
    func_800550F4_55CF4(temp_s2, 9, 0);
    HuSprPriSet(temp_s2, 9, ((playerIndex * 5) + 0x478E) & 0xFFFF);
    HuSprAttrSet(temp_s2, 9, 0);
    func_80054904_55504(temp_s2, 9, D_801018E4_115504_shared_board[9][0], D_801018E4_115504_shared_board[9][1]);
    if (!(GwPlayer[playerIndex].stat & 1)) {
        HuSprAttrSet(temp_s2, 9, 0x8000);
    }
}

void func_800F3FF4_107C14_shared_board(s32 arg0) {
    s32 temp_s3;
    s16 var_s1;
    s32 i;
    s32 curItem;
    temp_s3 = D_801057E0_119400_shared_board[arg0].playerIndex;

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        curItem = GwPlayer[arg0].itemNo[i];
        curItem = (curItem == -1) ? 0 : curItem;
        func_80055024_55C24(temp_s3, i + 0xB, D_80105588_1191A8_shared_board[curItem + 10], 0);
        func_800550F4_55CF4(temp_s3, i + 0xB, 0);
        HuSprPriSet(temp_s3, i + 0xB, ((arg0 * 5) + 0x478E));
        HuSprAttrSet(temp_s3, i + 0xB, 0);
        var_s1 = i + 0xB;
        if (arg0 >= 2) {
            var_s1 = i + 0xE;
        }
        func_80054904_55504(temp_s3, i + 0xB, D_801018E4_115504_shared_board[var_s1][0], D_801018E4_115504_shared_board[var_s1][1]);
        if (GwPlayer[arg0].itemNo[i] == -1) {
            HuSprAttrSet(temp_s3, i + 0xB, 0x8000);
        }
    }
}


//create sprite IDs for hud elements
void func_800F4190_107DB0_shared_board(void) {
    void* temp_v0;
    s32 i;
    s16* spriteIDs;
    s32 sp10[2] = {0x130112, 0x130111};

    spriteIDs = D_80105588_1191A8_shared_board;
    //unk sprite id
    temp_v0 = DataRead(0x13010F);
    spriteIDs[0] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);
    
    //create player sprite ids
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0 = DataRead(D_80101944_115564_shared_board[GwPlayer[i].chr]);
        spriteIDs[i + 1] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    //create coin and star sprite ids
    for (i = 0; i < ARRAY_COUNT(sp10); i++) {
        temp_v0 = DataRead(sp10[i]);
        spriteIDs[i + 5] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    //create placement sprite id
    temp_v0 = DataRead(0x130110);
    spriteIDs[8] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    //create COM text sprite id
    temp_v0 = DataRead(0x1300D1);
    spriteIDs[9] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    //create item sprite ids
    for (i = 0; i < ITEMS_END; i++) {
        temp_v0 = DataRead(D_801019D0_1155F0_shared_board[i]);
        spriteIDs[i + 10] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }
}

void func_800F4348_107F68_shared_board(void) {
    s32 i;
    s16* spriteIDs = D_80105588_1191A8_shared_board;

    HuSprKill(spriteIDs[0]);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        HuSprKill(spriteIDs[i + 1]);
    }

    for (i = 0; i < 2; i++) {
        HuSprKill(spriteIDs[i + 5]);
    }

    HuSprKill(spriteIDs[8]);
    HuSprKill(spriteIDs[9]);

    for (i = 0; i < ITEMS_END; i++) {
        HuSprKill(spriteIDs[i + 10]);
    }
}

void func_800F43FC_10801C_shared_board(s32 arg0) {
    BoardStatus* temp_s2;
    s32 i;

    temp_s2 = &D_801057E0_119400_shared_board[arg0];

    for (i = 0; i < ARRAY_COUNT(temp_s2->unk2); i++) {
        temp_s2->unk2[i] = 0;
    }

    temp_s2->counts[0] = GwPlayer[arg0].coin;
    temp_s2->counts[1] = GwPlayer[arg0].star;
    temp_s2->uiVisible = 0;
    temp_s2->unk1 = -1;
    temp_s2->prevCoins = -1;
    temp_s2->prevStars = -1;
    temp_s2->prevRank = -1;
    temp_s2->uiUpdatePaused = FALSE;
    func_800F3D70_107990_shared_board(arg0);
    func_800F4798_1083B8_shared_board(arg0, 0);
    func_800F4874_108494_shared_board(arg0, PlayerBoardStatusRootPosition[arg0][0], PlayerBoardStatusRootPosition[arg0][1]);
    func_800F39C0_1075E0_shared_board(arg0);
    func_800F3A80_1076A0_shared_board(arg0);
    func_800F3BD0_1077F0_shared_board(arg0);
    func_800F3E34_107A54_shared_board(arg0);
    func_800F3F0C_107B2C_shared_board(arg0);
    func_800F3FF4_107C14_shared_board(arg0);
    UpdatePlayerBoardStatus(arg0);
    D_801055E8_119208_shared_board[arg0] = NULL;
    temp_s2->unk30 = 0;
}

void func_800F453C_10815C_shared_board(void) {
    s32 i, j;

    func_800F4190_107DB0_shared_board();
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F43FC_10801C_shared_board(i);
    }
    
    D_80105580_1191A0_shared_board = omAddPrcObj(func_800F3400_107020_shared_board, 0U, 0x2000, 0);
    omPrcSetStatBit(D_80105580_1191A0_shared_board, 0x80);
    
    D_801055C4_1191E4_shared_board = -1;
    D_801055C2_1191E2_shared_board = -1;
    D_80101780_1153A0_shared_board = -1;
    D_80101784_1153A4_shared_board = -1;
    
    for (i = 0; i < SHARED_BOARD_UNK_SIZE_0; i++) {
        D_801055FC_11921C_shared_board[i] = -1;
        for (j = 0; j < ARRAY_COUNT_2D_COLS(D_80105608_119228_shared_board); j++) {
            D_80105608_119228_shared_board[i][j] = -1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F462C_10824C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F4730_108350_shared_board);

void func_800F4798_1083B8_shared_board(u32 playerIndex, s32 turnStatus) {
    if (playerIndex < MB_MAX_PLAYERS) {
        func_80055420_56020(D_801057E0_119400_shared_board[playerIndex].playerIndex, 0, D_8010188C_1154AC_shared_board[turnStatus].r, D_8010188C_1154AC_shared_board[turnStatus].g, D_8010188C_1154AC_shared_board[turnStatus].b);
        D_801057E0_119400_shared_board[playerIndex].spaceType = turnStatus;
    }
}

s32 func_800F482C_10844C_shared_board(s32 arg0) {
    return D_801057E0_119400_shared_board[arg0].spaceType;
}

void func_800F4850_108470_shared_board(s32 arg0, s32 arg1) {
    D_801057E0_119400_shared_board[arg0].unk1 = arg1;
}

//initialize player UIs
void func_800F4874_108494_shared_board(s32 playerIndex, s16 arg1, s16 arg2) {
    BoardStatus* boardStatus;
    f32 temp_f0;
    f32 temp_f0_2;

    boardStatus = &D_801057E0_119400_shared_board[playerIndex];
    boardStatus->unk_18 = arg1;
    boardStatus->xPos = arg1;
    boardStatus->unk_1C = arg2;
    boardStatus->yPos = arg2;
    boardStatus->unk_20 = boardStatus->unk_24 = 0;
    boardStatus->unkE = -2;
    func_80054904_55504(boardStatus->playerIndex, 0, arg1 + ITEMS_POS_OFFSET_X, arg2 + ITEMS_POS_OFFSET_Y);
}

//?
void func_800F4924_108544_shared_board(s32 arg0, s32 arg1) {
    s32 index = (arg1 * 4) + arg0;
    func_800F4874_108494_shared_board(arg0, PlayerBoardStatusRootPosition[index][0], PlayerBoardStatusRootPosition[index][1]);
}

void func_800F4960_108580_shared_board(s32 arg0, s32 arg1) {
    func_800F4874_108494_shared_board(arg0, PlayerBoardStatusRootPosition[arg1][0], PlayerBoardStatusRootPosition[arg1][1]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F4994_1085B4_shared_board);

s32 func_800F5278_108E98_shared_board(void) {
    s32 var_a0;
    s32 i;

    var_a0 = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) { //TODO: should this be MB_MAX_PLAYERS?
        if (D_801057E0_119400_shared_board[i].unkE != -2) {
            var_a0 = 1;
        }
    }
    return var_a0;
}

//decide what type of minigame will be played
s32 func_800F52C4_108EE4_shared_board(void) {
    u8 type1Indices[4];
    u8 type2Indices[4];
    u8 otherCount = 0;
    u8 type2Count = 0;
    u8 type1Count = 0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        switch (D_801057E0_119400_shared_board[i].spaceType) {
        case 1:
            type1Indices[type1Count++] = i;
            break;
        case 2:
            type2Indices[type2Count++] = i;
            break;
        default:
            otherCount++;
        }
    }

    // Determine result based on counts
    if (otherCount > 0) {
        return -1;
    }

    if (type1Count == 0 || type1Count == 4) {
        return 0;
    }

    if (type1Count == 1) {
        D_801055F8_119218_shared_board = type1Indices[0];
        return 1;
    }

    if (type1Count == 3) {
        D_801055F8_119218_shared_board = type2Indices[0];
        return 1;
    }

    return 2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F53B4_108FD4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F54FC_10911C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F5644_109264_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F56A8_1092C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F5828_109448_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106A50", func_800F591C_10953C_shared_board);

void func_800F59B4_1095D4_shared_board(omObjData* arg0) {
    s32 var_s1;

    var_s1 = 0;
    while (arg0->scale.y <= 0.0f) {
        if (arg0->trans.x > 0.0f) {
            AdjustPlayerCoins(arg0->work[0], 1);
            if (((arg0->work[3] != 0) & (var_s1 == 0)) && (arg0->scale.z >= 3.0f)) {
                HuAudFXPlay(0x106);
                var_s1 = 1;
                arg0->scale.z -= 3.0f;
            }
            arg0->trans.x -= 1.0f;

        } else {
            AdjustPlayerCoins(arg0->work[0], -1);
            arg0->trans.x += 1.0f;
            if (arg0->work[3] != 0) {
                if ((var_s1 == 0) && (arg0->scale.z >= 3.0f)) {
                    HuAudFXPlay(0x109);
                    var_s1 = 1;
                    arg0->scale.z -= 3.0f;
                }
                if ((arg0->trans.x == 0.0f) || (GwPlayer[arg0->work[0]].coin == 0)) {
                    HuAudFXPlay(0x10A);
                }
            }
        }
        
        if ((arg0->trans.x == 0.0f) || (GwPlayer[arg0->work[0]].coin == 0)) {
            D_801055E8_119208_shared_board[arg0->work[0]] = NULL;
            omDelObj(arg0);
            return;
        }
        arg0->scale.y += arg0->scale.x;
    }

    arg0->scale.y -= 1.0f;
    arg0->scale.z += 2.0f;
}

void func_800F5BF4_109814_shared_board(s32 playerIndex, s32 coinAmount, s32 arg2) {
    if (coinAmount != 0) {
        if (D_801055E8_119208_shared_board[playerIndex] != NULL) {
            AdjustPlayerCoins(playerIndex, coinAmount);
            return;
        }
        
        if ((GwPlayer[playerIndex].coin == 0) && (coinAmount < 0)) {
            return;
        }
        
        D_801055E8_119208_shared_board[playerIndex] = omAddObj(-0x8000, 0, 0, -1, func_800F59B4_1095D4_shared_board);
        D_801055E8_119208_shared_board[playerIndex]->work[0] = playerIndex;
        D_801055E8_119208_shared_board[playerIndex]->trans.x = coinAmount;

        D_801055E8_119208_shared_board[playerIndex]->scale.x = coinAmount > 0.0f ? (30.0f / coinAmount) : (30.0f / (0.0f - coinAmount));
        
        (D_801055E8_119208_shared_board[playerIndex])->scale.y = 0.0f;
        (D_801055E8_119208_shared_board[playerIndex])->scale.z  = 3.0f;
        (D_801055E8_119208_shared_board[playerIndex])->work[3] = arg2;
    }
}

void func_800F5D44_109964_shared_board(s32 arg0, s32 arg1) {
    func_800F5BF4_109814_shared_board(arg0, arg1, 1);
}

s32 func_800F5D60_109980_shared_board(s32 arg0) {
    if (D_801055E8_119208_shared_board[arg0]) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_800F5D78_109998_shared_board(void) {
    if (D_801057E0_119400_shared_board->uiVisible & 1) {
        return 0;
    } else {
        return 1;
    }
}

//toggle hide player UI bit on
void func_800F5D8C_1099AC_shared_board(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        D_801057E0_119400_shared_board[i].uiVisible |= 1;
    }
}

//toggle hide player UI bit off
void func_800F5DD8_1099F8_shared_board(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        D_801057E0_119400_shared_board[i].uiVisible &= ~1;
    }
}

void func_800F5E24_109A44_shared_board(s32 arg0) {
    D_80101784_1153A4_shared_board = arg0;
}

void func_800F5E30_109A50_shared_board(void) {
    s32 i;

    func_800F4190_107DB0_shared_board();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F43FC_10801C_shared_board(i);
        func_800F4874_108494_shared_board(i, PlayerBoardStatusRootPosition[i + 4][0], PlayerBoardStatusRootPosition[i + 4][1]);
        func_800F4798_1083B8_shared_board(i, GwPlayer[i].color);
    }

    D_80105580_1191A0_shared_board = omAddPrcObj(&func_800F3400_107020_shared_board, 0, 0x2000, 0);
    omPrcSetStatBit(D_80105580_1191A0_shared_board, 0x80);
    D_801055C4_1191E4_shared_board = -1;
    D_801055C2_1191E2_shared_board = -1;
}

void func_800F5EF0_109B10_shared_board(void) {
    func_800F462C_10824C_shared_board(D_80101780_1153A0_shared_board);
    func_800F462C_10824C_shared_board(D_80101784_1153A4_shared_board);
    func_800F4348_107F68_shared_board();
    HuPrcKill(D_80105580_1191A0_shared_board);
    func_800F5644_109264_shared_board();
    D_80101780_1153A0_shared_board = -1;
    D_80101784_1153A4_shared_board = -1;
}

void func_800F5F4C_109B6C_shared_board(s32 arg0, s32 arg1) {
    D_80101780_1153A0_shared_board = arg0;
    D_80101784_1153A4_shared_board = arg1;
}

void func_800F5F60_109B80_shared_board(void) {
    func_800F4994_1085B4_shared_board(0x16);
}

void func_800F5F7C_109B9C_shared_board(void) {
    func_800F4994_1085B4_shared_board(0x17);
}

void func_800F5F98_109BB8_shared_board(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    BoardStatus* temp_s7;
    s16 temp_s5;
    s16 i;
    void* var_s2;

    temp_s7 = &D_801057E0_119400_shared_board[arg0];
    temp_s5 = temp_s7->playerIndex;
    var_s2 = NULL;
    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        var_s2 = NULL;
        if (GwPlayer[arg0].itemNo[i] != -1) {
            var_s2 = DataRead(D_8010197C_11559C_shared_board[GwPlayer[arg0].itemNo[i]]);
        } else {
            if (i == 0) {
                var_s2 = DataRead(0x13025E);
            }
        }

        if (var_s2 != NULL) {
            temp_s7->unk_40[i] = func_80055810_56410(var_s2);
            DataClose(var_s2);
            func_80055024_55C24(temp_s5, i + 2, temp_s7->unk_40[i], 0);
            if (i != 0) {
                HuSprPriSet(temp_s5, i + 2, (arg0 * 5) + 0x4790);
            } else {
                HuSprPriSet(temp_s5, i + 2, ((arg0 * 5) + 0x478F) & 0xFFFF);
            }
            HuSprAttrSet(temp_s5, i + 2, 0x180CU);
            HuSprAttrReset(temp_s5, i + 2, 0x8000U);
            func_800552DC_55EDC(temp_s5, i + 2, 0.0f);
            if (GwPlayer[arg0].itemNo[0] != ITEM_NONE) {
                if (arg1 != 0) {
                    func_800F6E4C_10AA6C_shared_board(arg0, i, &sp10, &sp14);
                    func_80054904_55504(temp_s7->playerIndex, i + 2, sp10, sp14);
                } else {
                    switch (i) {
                    case 0:
                        func_80054904_55504(temp_s5, i + 2, (i * 0x12) + 3, 5);
                        break;
                    case 1:
                        func_80054904_55504(temp_s5, i + 2, (i * 0x12) + 3, -5);
                        break;
                    case 2:
                        func_80054904_55504(temp_s5, i + 2, (i * 0x12) + 3, 5);
                        break;
                    }                    
                }
            } else {
                if (arg1 != 0) {
                    f32 xPos, yPos;
                    xPos = (PlayerBoardStatusRootPosition[arg0][0] + 0x38);
                    yPos = (PlayerBoardStatusRootPosition[arg0][1] + 0x13);
                    xPos = xPos + 22.0f;
                    xPos = xPos - 4.0f;
                    
                    func_80054904_55504(temp_s7->playerIndex, 2, xPos, yPos);
                } else {
                    func_80054904_55504(temp_s5, 2, 0x12, 0);
                }
            }
            HuSprScaleSet(temp_s5, i + 2, 1.0f, 1.0f);
            func_800550B4_55CB4(temp_s5, i + 2, 0.0f);
            if (arg0 == GwSystem.current_player_index) {
                func_80055458_56058(temp_s5, i + 2, 0x100);
            } else {
                func_80055458_56058(temp_s5, i + 2, 0x80);
            }
            
        } else {
            temp_s7->unk_40[i] = -1;
        }
    }
}

void func_800F63F0_10A010_shared_board(s32 arg0) {
    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }
    func_800F3FF4_107C14_shared_board(arg0);
}

void func_800F641C_10A03C_shared_board(s32 playerIndex) {
    BoardStatus* temp_s2;
    s32 i;

    if (playerIndex == CUR_PLAYER) {
        playerIndex = GwSystem.current_player_index;
    }
    
    temp_s2 = &D_801057E0_119400_shared_board[playerIndex];
    
    for (i = 0; i < ARRAY_COUNT(temp_s2->unk_40); i++) {
        if (temp_s2->unk_40[i] != -1) {
            func_800F6AA4_10A6C4_shared_board(temp_s2->playerIndex, i + 2);
            HuSprKill(temp_s2->unk_40[i]);
            temp_s2->unk_40[i] = -1;
        }
    }

    func_800F5F98_109BB8_shared_board(playerIndex, 1);
}

void func_800F64E4_10A104_shared_board(s32 arg0, s32 arg1) {
    BoardStatus* temp_s2;
    s32 i;

    temp_s2 = &D_801057E0_119400_shared_board[arg0];
    if (temp_s2->uiUpdatePaused != arg1) {
        temp_s2->uiUpdatePaused = arg1;
        switch (arg1) {
        case FALSE:
            for (i = 0; i < ARRAY_COUNT(temp_s2->unk_40); i++) {
                if (temp_s2->unk_40[i] != -1) {
                    HuSprAttrSet(temp_s2->playerIndex, i + 2, 0x8000);
                    HuSprKill(temp_s2->unk_40[i]);
                    temp_s2->unk_40[i] = -1;
                }
            }

            func_800F3A80_1076A0_shared_board(arg0);
            func_800F3BD0_1077F0_shared_board(arg0);
            func_800F3E34_107A54_shared_board(arg0);
            func_800F3FF4_107C14_shared_board(arg0);
            break;

        case TRUE:
            for (i = 0; i < 2; i++) {
                HuSprAttrSet(temp_s2->playerIndex, i + 2, 0x8000);
                func_800550F4_55CF4(temp_s2->playerIndex, i + 2, 0);
            }

            HuSprKill(temp_s2->unk_3A);
            
            for (i = 0; i < 5; i++) {
                HuSprAttrSet(temp_s2->playerIndex, i + 4, 0x8000);
                func_800550F4_55CF4(temp_s2->playerIndex, i + 4, 0);
            }
            
            temp_s2->unk_3A = -1;
            HuSprAttrSet(temp_s2->playerIndex, 0xA, 0x8000);
            func_800550F4_55CF4(temp_s2->playerIndex, 0xA, 0);
            
            for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
                HuSprAttrSet(temp_s2->playerIndex, i + 0x0B, 0x8000);
                func_800550F4_55CF4(temp_s2->playerIndex, i + 0x0B, 0);
            }
            func_800F5F98_109BB8_shared_board(arg0, 0);
            break;
        }
    }
}

void func_800F66DC_10A2FC_shared_board(s32 arg0) {
    s32 i;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F64E4_10A104_shared_board(i, arg0);
    }
}

s32 func_800F6724_10A344_shared_board(s32 arg0) {
    return D_801057E0_119400_shared_board[arg0].uiUpdatePaused;
}

void func_800F6748_10A368_shared_board(s16 arg0, s16 arg1, f32* arg2, f32* arg3) {
    HuSprite* sprite = HuSprGrpData[arg0]->members[arg1];

    *arg2 = sprite->unk_48;
    *arg3 = sprite->unk_4C;
}

void func_800F6780_10A3A0_shared_board(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f20;
    f32 temp_f22;
    s32 temp_s1;

    temp_s1 = D_801057E0_119400_shared_board[arg0].playerIndex;
    func_800F6748_10A368_shared_board(temp_s1, arg1 + 2, &temp_f20, &temp_f22);
    temp_f20 += arg2;
    temp_f22 += arg3;
    func_80054904_55504(temp_s1, arg1 + 2, temp_f20, temp_f22);
}

void func_800F6848_10A468_shared_board(s32 arg0, s32 arg1, f32* arg2, f32* arg3) {
    func_800F6748_10A368_shared_board(D_801057E0_119400_shared_board[arg0].playerIndex, (arg1 + 2), arg2, arg3);
}

void func_800F688C_10A4AC_shared_board(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    func_80054904_55504(D_801057E0_119400_shared_board[arg0].playerIndex, (arg1 + 2), arg2, arg3);
}

void func_800F68E0_10A500_shared_board(s32 arg0, s32 arg1, s16 arg2) {
    func_80055458_56058(D_801057E0_119400_shared_board[arg0].playerIndex, (arg1 + 2), arg2);
}

void func_800F6928_10A548_shared_board(s32 arg0, s32 arg1, f32 arg2) {
    func_800552DC_55EDC(D_801057E0_119400_shared_board[arg0].playerIndex, (arg1 + 2), arg2);
}

void func_800F696C_10A58C_shared_board(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    HuSprScaleSet(D_801057E0_119400_shared_board[arg0].playerIndex, arg1 + 2, arg2, arg3);
}

void func_800F69B0_10A5D0_shared_board(s32 arg0, s32 arg1, u16 arg2) {
    HuSprPriSet(D_801057E0_119400_shared_board[arg0].playerIndex, arg1 + 2, arg2);
}

void func_800F69F8_10A618_shared_board(s32 arg0, s32 arg1, u16 arg2) {
    HuSprAttrSet(D_801057E0_119400_shared_board[arg0].playerIndex, arg1 + 2, arg2);
}

void func_800F6A40_10A660_shared_board(s32 arg0, s32 arg1, u16 arg2) {
    HuSprAttrReset(D_801057E0_119400_shared_board[arg0].playerIndex, arg1 + 2, arg2);
}

void func_800F6A88_10A6A8_shared_board(s16 arg0, u16 arg1) {
    HuSprGrpData[arg0]->unk_08 = arg1;
}

void func_800F6AA4_10A6C4_shared_board(s16 arg0, s16 arg1) {
    HuSprGrpData[arg0]->members[arg1]->unk_84 = NULL;
}

void func_800F6AD0_10A6F0_shared_board(s32 arg0, f32 xScale, f32 yScale) {
    BoardStatus* temp_s1;
    s32 i;

    temp_s1 = &D_801057E0_119400_shared_board[arg0];
    switch(temp_s1->uiUpdatePaused) {
    case FALSE:
        for (i = 0; i < 14; i++) {
            HuSprScaleSet(temp_s1->playerIndex, i, xScale, yScale);
        }
        break;
    case TRUE:
        for (i = 0; i < 5; i++) {
            HuSprScaleSet(temp_s1->playerIndex, i, xScale, yScale);
        }
        HuSprScaleSet(temp_s1->playerIndex, 9, xScale, yScale);
        break;
    }
}

void func_800F6BC4_10A7E4_shared_board(s32 arg0) {
    BoardStatus* temp_s2;
    f32 var_f20;
    s32 i, j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0 == CUR_PLAYER || arg0 == i) {
            temp_s2 = &D_801057E0_119400_shared_board[i];
            if (temp_s2->uiUpdatePaused == TRUE) {
                func_800F6A88_10A6A8_shared_board(temp_s2->playerIndex, 2);
                func_80054904_55504(temp_s2->playerIndex, 1, D_801018E4_115504_shared_board[1][0], D_801018E4_115504_shared_board[1][1]);
                if (GwPlayer[i].itemNo[0] != ITEM_NONE) {
                    //used for item positions when closing items screen
                    for (j = 0; j < ARRAY_COUNT(GwPlayer->itemNo); j++) {
                        switch (j) {
                        case 0:
                            func_80054904_55504(temp_s2->playerIndex, j + 2, j * 0x12 + 3, 5);
                            break;
                        case 1:
                            func_80054904_55504(temp_s2->playerIndex, j + 2, j * 0x12 + 3, -5);
                            break;
                        case 2:
                            func_80054904_55504(temp_s2->playerIndex, j + 2, j * 0x12 + 3, 5);
                            break;
                        }
                    }
                } else {
                    func_80054904_55504(temp_s2->playerIndex, 2, 0x12, 0);
                }
            }
        }
    }
    
    for (var_f20 = 0.0f; var_f20 <= 90.0f; var_f20 += 15.0f) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (arg0 == CUR_PLAYER || arg0 == i) {
                func_800F6AD0_10A6F0_shared_board(i, HuMathCos(var_f20), 1.0f);
            }            
        }
        HuPrcVSleep();
    }
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0 == CUR_PLAYER || arg0 == i) {
            func_800F6AD0_10A6F0_shared_board(i, 0.0f, 0);
        }
    }
    HuPrcVSleep();
}

//sets item positions when pressing B and you have control of hand cursor
void func_800F6E4C_10AA6C_shared_board(s32 playerIndex, s32 itemIndex, s32* xPos, s32* yPos) {
    s32 xPosTemp;
    
    if (playerIndex == CUR_PLAYER) {
        playerIndex = GwSystem.current_player_index;
    }

    *xPos = PlayerBoardStatusRootPosition[playerIndex][0] + ITEMS_POS_OFFSET_X;
    *yPos = PlayerBoardStatusRootPosition[playerIndex][1] + ITEMS_POS_OFFSET_Y;

    xPosTemp = *xPos + 3;
    *xPos = xPosTemp + (itemIndex * 18);
    //if item index is 1, move item up on the screen 5 units
    //if item index 0 or 2, move down on the screen 5 units
    if (itemIndex == 1) {
        *yPos -= 5;
    } else {
        *yPos += 5;
    }
}

void func_800F6ECC_10AAEC_shared_board(s32 arg0) {
    s32 sp10;
    s32 sp14;
    BoardStatus* temp_s2;
    f32 var_f20;
    s32 i, j;
    
    for (var_f20 = 90.0f; var_f20 >= 0.0f; var_f20 -= 15.0f) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (arg0 == CUR_PLAYER || arg0 == i) {
                func_800F6AD0_10A6F0_shared_board(i, HuMathCos(var_f20), 1.0f);
            }            
        }
        HuPrcVSleep();
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0 == CUR_PLAYER || arg0 == i) {
            func_800F6AD0_10A6F0_shared_board(i, 1.0f, 1.0f);
            temp_s2 = &D_801057E0_119400_shared_board[i];
            if (temp_s2->uiUpdatePaused == TRUE) {
                func_800F6A88_10A6A8_shared_board(temp_s2->playerIndex, 0);
                sp10 = PlayerBoardStatusRootPosition[i][0] + ITEMS_POS_OFFSET_X;
                sp14 = PlayerBoardStatusRootPosition[i][1] + ITEMS_POS_OFFSET_Y;
                func_80054904_55504(temp_s2->playerIndex, 1, sp10, sp14);
                if (GwPlayer[i].itemNo[0] != ITEM_NONE) {
                    for (j = 0; j < ARRAY_COUNT(GwPlayer->itemNo); j++) {
                        func_800F6E4C_10AA6C_shared_board(i, j, &sp10, &sp14);
                        func_80054904_55504(temp_s2->playerIndex, j + 2, sp10, sp14);
                    }
                } else {
                    func_80054904_55504(temp_s2->playerIndex, 2, (sp10 + 0x12), sp14);
                }
            }
        }
    }
    HuPrcVSleep();
}

//draw item icons
void func_800F70F8_10AD18_shared_board(void) {
    D_80101790_1153B0_shared_board = 1;
}

//hide item icons
void func_800F7108_10AD28_shared_board(void) {
    D_80101790_1153B0_shared_board = 0;
}

void func_800F7114_10AD34_shared_board(s32 arg0, s32 arg1) {
    D_80101788_1153A8_shared_board = arg0;
    D_8010178C_1153AC_shared_board = arg1;
}