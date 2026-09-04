#include "common.h"
#include "game/board.h"
#include "101840.h"
#include "106A50.h"
#include "105D50.h"

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
    { 24, 16 }, { 191, 16 }, { 24, 186 }, { 191, 186 }, { -224, 16 }, { 432, 16 }, { -224, 186 }, { 432, 186 }
};

s16 PlayerBoardStatusRootPositionExtras[][2] = {
    { 0x0030, 0x004C },
    { 0x00A0, 0x004C },
    { 0x0030, 0x007E },
    { 0x00A0, 0x007E },
    { 0x0068, 0x0073 },
    { 0x01B0, 0x0010 },
    { 0xFF20, 0x00BA },
    { 0x01B0, 0x00BA },
    { 0xFF20, 0x0010 },
    { 0x0068, 0x0073 },
    { 0xFF20, 0x00BA },
    { 0x01B0, 0x00BA },
    { 0xFF20, 0x0010 },
    { 0x01B0, 0x0010 },
    { 0x0068, 0x0073 },
    { 0x01B0, 0x00BA },
    { 0xFF20, 0x0010 },
    { 0x01B0, 0x0010 },
    { 0xFF20, 0x00BA },
    { 0x0068, 0x0073 },
    { 0x0220, 0x0018 },
    { 0x0220, 0x004A },
    { 0x0220, 0x007C },
    { 0x0220, 0x00AE },
    { 0x00B8, 0x0018 },
    { 0x00B8, 0x004A },
    { 0x00B8, 0x007C },
    { 0x00B8, 0x00AE },
    { 0x0017, 0x008C },
    { 0x00BE, 0x008C },
    { 0xFF20, 0x0010 },
    { 0x01B0, 0x0010 },
    { 0xFF20, 0x00BA },
    { 0x01B0, 0x00BA }
};

s16 D_8010183C_11545C_shared_board[4][2] = {
    {0x0028, 0x005C}, {0x00A8, 0x005C}, {0x0028, 0x00B8}, {0x00A8, 0x00B8}
};

s16 D_8010184C_11546C_shared_board[4][2] = {
    {0x0028, 0x005C}, {0x00A8, 0x005C}, {0x0028, 0x00B8}, {0x00A8, 0x00B8}
};

s16 D_8010185C_11547C_shared_board[4][2] = {
    {0x00A8, 0x005C}, {0x00A8, 0x008A}, {0x00A8, 0x00B8}, {0x0028, 0x008A}
};

s16 D_8010186C_11548C_shared_board[4][2] = {
    {0x0028, 0x005C}, {0x0028, 0x00B8}, {0x00A8, 0x005C}, {0x00A8, 0x00B8}
};

s16 D_8010187C_11549C_shared_board[4][2] = {
    {0x0020, 0x008A}, {0x00B0, 0x005C}, {0x00B0, 0x008A}, {0x00B0, 0x00B8}
};

// TODO: this probably isn't all RGB data
RGB D_8010188C_1154AC_shared_board[] = {
    { 0x80, 0x80, 0x80 },
    { 0x1A, 0x84, 0xFF },
    { 0xFF, 0x1A, 0x2D },
    { 0xFF, 0xFF, 0x00 },
    { 0x1A, 0xFF, 0x5F },
    { 0x40, 0xC0, 0x00 },
    { 0x80, 0x80, 0x00 },
    { 0xC0, 0x40, 0x00 },
    { 0xFF, 0x00, 0x00 },
    { 0xFF, 0x00, 0x00 },
    { 0xFF, 0x00, 0x00 },
    { 0xC0, 0x40, 0x00 },
    { 0x80, 0x80, 0x00 },
    { 0x40, 0xC0, 0x00 },
    { 0x00, 0xFF, 0x00 },
    { 0x00, 0xFF, 0x00 },
    { 0x00, 0xFF, 0x00 },
    { 0x00, 0xC0, 0x40 },
    { 0x00, 0x80, 0x80 },
    { 0x00, 0x40, 0xC0 },
    { 0x00, 0x00, 0xFF },
    { 0x00, 0x00, 0xFF },
    { 0x00, 0x00, 0xFF },
    { 0x00, 0x40, 0xC0 },
    { 0x00, 0x80, 0x80 },
    { 0x00, 0xC0, 0x40 },
    { 0x00, 0xFF, 0x00 },
    { 0x00, 0xFF, 0x00 },
    { 0x00, 0xFF, 0x00 },
};

s16 D_801018E4_115504_shared_board[][2] = {
    { 0x0000, 0x0000 },
    { 0x0000, 0x0000 },
    { 0x0003, 0x0007 },
    { 0x0003, 0xFFF7 },
    { 0x0010, 0x000A },
    { 0x001A, 0x000A },
    { 0x0024, 0x000A },
    { 0x0010, 0xFFFA },
    { 0x001A, 0xFFFA },
    { 0xFFEC, 0x000E },
    { 0xFFD3, 0x0000 },
    { 0x0003, 0x0017 },
    { 0x0014, 0x0017 },
    { 0x0025, 0x0017 },
    { 0x0003, 0xFFE9 },
    { 0x0014, 0xFFE9 },
    { 0x0025, 0xFFE9 }
};

u8 D_80101928_115548_shared_board[] = {
    0, 4, 0, 0, 8, 0, 12, 16, 20, 24, 0, 0, 0, 0, 32, 32, 32, 32, 28, 28, 28, 28, 0, 0, 0, 4, 0, 36
};

s32 D_80101944_115564_shared_board[] = {
    0x00130107, 0x00130108, 0x00130109, 0x0013010A, 0x0013010B, 0x0013010C, 0x0013010D, 0x0013010E
};

s16 (*D_80101964_115584_shared_board[])[2] = {
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

extern s16 D_80105588_1191A8_shared_board[];
extern RGB D_8010188C_1154AC_shared_board[];
extern s16 D_801055C2_1191E2_shared_board;
extern s16 D_801055C4_1191E4_shared_board;
extern f32 D_801055C8_1191E8_shared_board;
extern s16 D_801055E4_119204_shared_board;
extern Vec2f D_801055CC_1191EC_shared_board;
extern Vec2f D_801055DC_1191FC_shared_board;
extern Vec2f D_801055D4_1191F4_shared_board;
extern Process* D_80105580_1191A0_shared_board;

#define SHARED_BOARD_UNK_SIZE_0 4
extern s16 D_801055FC_11921C_shared_board[SHARED_BOARD_UNK_SIZE_0];
extern s16 D_80105608_119228_shared_board[SHARED_BOARD_UNK_SIZE_0][3];

static void MBStatusNumUpdate(s32 playerIndex) {
    UnkCoinThing coinDigits;
    BoardStatus *playerBoardStatus;
    s32 var_v1;
    s32 i;

    playerBoardStatus = &mbStatusData[playerIndex];
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
        if (GwPlayer[playerIndex].star > STARS_MAX) {
            func_80055140_55D40(playerBoardStatus->playerIndex, STARS_TENS_DIGIT, 9, 0);
            func_80055140_55D40(playerBoardStatus->playerIndex, STARS_ONES_DIGIT, 9, 0);
        } else {
            if (GwPlayer[playerIndex].star > (STARS_MAX % 10)) {
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
        BoardStatus *boardStatus = &mbStatusData[i];
        for (j = 0; j < 14; j++) {
            HuSprAttrSet(boardStatus->playerIndex, j, 0x8000);
        }
    }
}

static void MBStatusMain(omObjData *obj) {
    BoardStatus *temp_s2;
    s32 var_v1;
    s32 i, j;

    while (1) {
        if (HmfPauseF == 0) {
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                if (D_80101780_1153A0_shared_board != -1 &&
                    D_80101784_1153A4_shared_board != -1 &&
                    i != D_80101780_1153A0_shared_board &&
                    i != D_80101784_1153A4_shared_board) {
                    continue;
                }

                temp_s2 = &mbStatusData[i];

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
                    MBStatusNumUpdate(i);
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

static void MBStatusCharSprCreate(s32 playerIndex) {
    s16 temp_s1;

    temp_s1 = mbStatusData[playerIndex].playerIndex;
    func_80055024_55C24(temp_s1, 1, D_80105588_1191A8_shared_board[playerIndex + 1], 0);
    func_800550F4_55CF4(temp_s1, 1, 0);
    HuSprPriSet(temp_s1, 1, ((playerIndex * 5) + 0x4790));
    HuSprAttrSet(temp_s1, 1, 0);
    func_80054904_55504(temp_s1, 1, D_801018E4_115504_shared_board[1][0], D_801018E4_115504_shared_board[1][1]);
}

static void MBStatusIconSprCreate(s32 arg0) {
    s32 i;
    s16 temp_s2 = mbStatusData[arg0].playerIndex;

    for (i = 0; i < 2; i++) {
        func_80055024_55C24(temp_s2, i + 2, D_80105588_1191A8_shared_board[i + 5], 0);
        HuSprPriSet(temp_s2, i + 2, ((arg0 * 5) + 0x4790));
        HuSprAttrReset(temp_s2, i + 2, 0xFFFF);
        HuSprAttrSet(temp_s2, i + 2, 0x1000);
        func_800552DC_55EDC(temp_s2, i + 2, 0.0f);
        func_80054904_55504(temp_s2, i + 2, D_801018E4_115504_shared_board[i + 2][0], D_801018E4_115504_shared_board[i + 2][1]);
        func_800550B4_55CB4(temp_s2, i + 2, 0.0f);
        func_80055458_56058(temp_s2, i + 2, 0x100);
    }
}

static void MBStatusNumSprCreate(s32 arg0) {
    BoardStatus *temp_s4 = &mbStatusData[arg0];
    s16 temp_s2;
    void *temp_v0;
    s32 i;

    temp_s4->prevCoins = -1;
    temp_s4->prevStars = -1;
    temp_v0 = DataRead(0x1300CF);
    temp_s4->unk_3A = func_80055810_56410(temp_v0);
    temp_s2 = temp_s4->playerIndex;
    for (i = 0; i < 5; i++) {
        func_80055024_55C24(temp_s2, i + 4, temp_s4->unk_3A, 0);
        func_800550F4_55CF4(temp_s2, i + 4, 1);
        func_80055140_55D40(temp_s2, i + 4, 0xA, 0);
        HuSprPriSet(temp_s2, i + 4, ((arg0 * 5) + 0x4790));
        HuSprAttrReset(temp_s2, i + 4, 0xFFFF);
        HuSprAttrSet(temp_s2, i + 4, 0);
        func_80054904_55504(temp_s2, i + 4, D_801018E4_115504_shared_board[i + 4][0], D_801018E4_115504_shared_board[i + 4][1]);
        func_80055420_56020(temp_s2, i + 4, 0xFF, 0xFF, 0xFF);
        func_80055458_56058(temp_s2, i + 4, 0x100);
        func_800552DC_55EDC(temp_s2, i + 4, 0.0f);
    }
    DataClose(temp_v0);
}

static void MBStatusBackSprCreate(s32 playerNo) {
    BoardStatus *temp_s0 = &mbStatusData[playerNo];
    s16 temp_v0 = HuSprGrpCreate(0xE, 2);

    temp_s0->playerIndex = temp_v0;
    func_80055024_55C24(temp_v0, 0, D_80105588_1191A8_shared_board[0], 0);
    HuSprPriSet(temp_v0, 0, ((playerNo * 5) + 0x4790));
    HuSprAttrSet(temp_v0, 0, 0x1000);
    func_80054904_55504(temp_v0, 0, 0, 0);
}

static void MBStatusRankSprCreate(s32 playerNo) {
    BoardStatus *temp_v0 = &mbStatusData[playerNo];
    s16 temp_s0;

    temp_v0->prevRank = -1;
    temp_s0 = temp_v0->playerIndex;
    func_80055024_55C24(temp_s0, 0xA, D_80105588_1191A8_shared_board[8], 0);
    func_800550F4_55CF4(temp_s0, 0xA, 1);
    func_80055140_55D40(temp_s0, 0xA, 0, 0);
    HuSprPriSet(temp_s0, 0xA, ((playerNo * 5) + 0x478F));
    HuSprAttrSet(temp_s0, 0xA, 0);
    func_80054904_55504(temp_s0, 0xA, D_801018E4_115504_shared_board[10][0], D_801018E4_115504_shared_board[10][1]);
}

static void MBStatusComSprCreate(s32 playerNo) {
    s16 temp_s2;

    temp_s2 = mbStatusData[playerNo].playerIndex;
    func_80055024_55C24(temp_s2, 9, D_80105588_1191A8_shared_board[9], 0);
    func_800550F4_55CF4(temp_s2, 9, 0);
    HuSprPriSet(temp_s2, 9, ((playerNo * 5) + 0x478E));
    HuSprAttrSet(temp_s2, 9, 0);
    func_80054904_55504(temp_s2, 9, D_801018E4_115504_shared_board[9][0], D_801018E4_115504_shared_board[9][1]);
    if (!(GwPlayer[playerNo].stat & 1)) {
        HuSprAttrSet(temp_s2, 9, 0x8000);
    }
}

static void MBStatusItemIconSprCreate(s32 playerNo) {
    s32 temp_s3 = mbStatusData[playerNo].playerIndex;
    s16 var_s1;
    s32 i;
    s32 curItem;

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        curItem = GwPlayer[playerNo].itemNo[i];
        curItem = (curItem == -1) ? 0 : curItem;
        func_80055024_55C24(temp_s3, i + 0xB, D_80105588_1191A8_shared_board[curItem + 10], 0);
        func_800550F4_55CF4(temp_s3, i + 0xB, 0);
        HuSprPriSet(temp_s3, i + 0xB, ((playerNo * 5) + 0x478E));
        HuSprAttrSet(temp_s3, i + 0xB, 0);
        var_s1 = i + 0xB;
        if (playerNo >= 2) {
            var_s1 = i + 0xE;
        }
        func_80054904_55504(temp_s3, i + 0xB, D_801018E4_115504_shared_board[var_s1][0], D_801018E4_115504_shared_board[var_s1][1]);
        if (GwPlayer[playerNo].itemNo[i] == -1) {
            HuSprAttrSet(temp_s3, i + 0xB, 0x8000);
        }
    }
}

// create sprite IDs for hud elements
static void MBStatusAnimCreate(void) {
    void *temp_v0;
    s32 i;
    s16 *spriteIDs;
    s32 sp10[2] = { 0x130112, 0x130111 };

    spriteIDs = D_80105588_1191A8_shared_board;
    // unk sprite id
    temp_v0 = DataRead(0x13010F);
    spriteIDs[0] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    // create player sprite ids
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0 = DataRead(D_80101944_115564_shared_board[GwPlayer[i].chr]);
        spriteIDs[i + 1] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    // create coin and star sprite ids
    for (i = 0; i < ARRAY_COUNT(sp10); i++) {
        temp_v0 = DataRead(sp10[i]);
        spriteIDs[i + 5] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    // create placement sprite id
    temp_v0 = DataRead(0x130110);
    spriteIDs[8] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    // create COM text sprite id
    temp_v0 = DataRead(0x1300D1);
    spriteIDs[9] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    // create item sprite ids
    for (i = 0; i < ITEMS_END; i++) {
        temp_v0 = DataRead(D_801019D0_1155F0_shared_board[i]);
        spriteIDs[i + 10] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }
}

static void MBStatusAnimKill(void) {
    s32 i;
    s16 *spriteIDs = D_80105588_1191A8_shared_board;

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

static void func_800F43FC_10801C_shared_board(s32 playerNo) {
    BoardStatus *temp_s2 = &mbStatusData[playerNo];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(temp_s2->unk2); i++) {
        temp_s2->unk2[i] = 0;
    }

    temp_s2->counts[0] = GwPlayer[playerNo].coin;
    temp_s2->counts[1] = GwPlayer[playerNo].star;
    temp_s2->uiVisible = 0;
    temp_s2->unk1 = -1;
    temp_s2->prevCoins = -1;
    temp_s2->prevStars = -1;
    temp_s2->prevRank = -1;
    temp_s2->uiUpdatePaused = FALSE;
    MBStatusBackSprCreate(playerNo);
    MBStatusColorSet(playerNo, 0);
    MBStatusPosSet(playerNo, PlayerBoardStatusRootPosition[playerNo][0], PlayerBoardStatusRootPosition[playerNo][1]);
    MBStatusCharSprCreate(playerNo);
    MBStatusIconSprCreate(playerNo);
    MBStatusNumSprCreate(playerNo);
    MBStatusRankSprCreate(playerNo);
    MBStatusComSprCreate(playerNo);
    MBStatusItemIconSprCreate(playerNo);
    MBStatusNumUpdate(playerNo);
    D_801055E8_119208_shared_board[playerNo] = NULL;
    temp_s2->unk30 = 0;
}

void func_800F453C_10815C_shared_board(void) {
    s32 i, j;

    MBStatusAnimCreate();

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F43FC_10801C_shared_board(i);
    }

    D_80105580_1191A0_shared_board = omAddPrcObj(MBStatusMain, 0, 0x2000, 0);
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

static void func_800F462C_10824C_shared_board(s32 playerNo) {
    BoardStatus *temp_s2 = &mbStatusData[playerNo];
    s32 i;

    HuSprGrpKill(temp_s2->playerIndex);

    switch (temp_s2->uiUpdatePaused) {
        case 0:
            HuSprKill(temp_s2->unk_3A);
            break;
        case 1:
            for (i = 0; i < 3; i++) {
                if (temp_s2->unk_40[i] != -1) {
                    HuSprKill(temp_s2->unk_40[i]);
                    temp_s2->unk_40[i] = -1;
                }
            }
    }

    if (temp_s2->unk30 != 0) {
        omDelObj(temp_s2->unk30);
        temp_s2->unk30 = 0;
    }

    if (D_801055E8_119208_shared_board[playerNo] != NULL) {
        omDelObj(D_801055E8_119208_shared_board[playerNo]);
        D_801055E8_119208_shared_board[playerNo] = NULL;
    }
}

void func_800F4730_108350_shared_board(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F462C_10824C_shared_board(i);
    }

    MBStatusAnimKill();
    HuPrcKill(D_80105580_1191A0_shared_board);
    MBVsSprKill();
    D_80101780_1153A0_shared_board = -1;
    D_80101784_1153A4_shared_board = -1;
}

void MBStatusColorSet(u32 playerNo, s32 turnStatus) {
    if (playerNo < MB_MAX_PLAYERS) {
        func_80055420_56020(mbStatusData[playerNo].playerIndex, 0, D_8010188C_1154AC_shared_board[turnStatus].r, D_8010188C_1154AC_shared_board[turnStatus].g, D_8010188C_1154AC_shared_board[turnStatus].b);
        mbStatusData[playerNo].spaceType = turnStatus;
    }
}

s32 func_800F482C_10844C_shared_board(s32 playerNo) {
    return mbStatusData[playerNo].spaceType;
}

void func_800F4850_108470_shared_board(s32 playerNo, s32 arg1) {
    mbStatusData[playerNo].unk1 = arg1;
}

void MBStatusPosSet(s32 playerIndex, s16 arg1, s16 arg2) {
    BoardStatus *boardStatus;
    f32 temp_f0;
    f32 temp_f0_2;

    boardStatus = &mbStatusData[playerIndex];
    boardStatus->unk_18 = arg1;
    boardStatus->xPos = arg1;
    boardStatus->unk_1C = arg2;
    boardStatus->yPos = arg2;
    boardStatus->unk_20 = boardStatus->unk_24 = 0;
    boardStatus->unkE = -2;
    func_80054904_55504(boardStatus->playerIndex, 0, arg1 + ITEMS_POS_OFFSET_X, arg2 + ITEMS_POS_OFFSET_Y);
}

void MBStatusDispSideSet(s32 playerNo, s32 arg1) {
    s32 index = (arg1 * 4) + playerNo;
    MBStatusPosSet(playerNo, PlayerBoardStatusRootPosition[index][0], PlayerBoardStatusRootPosition[index][1]);
}

void MBStatusSideSet(s32 playerNo, s32 arg1) {
    MBStatusPosSet(playerNo, PlayerBoardStatusRootPosition[arg1][0], PlayerBoardStatusRootPosition[arg1][1]);
}

s32 MBStatusDispMoveSet(s32 arg0) {
    u8 slot[8];
    u8 group1[8];
    u8 group2[8];
    BoardStatus *sp;
    s32 i;
    u8 group1Count;
    u8 group2Count;
    u8 otherCount;

    group1Count = 0;
    group2Count = 0;

    if (arg0 == 2) {
        otherCount = 0;
        group1Count = 0;
        for (i = 0; i < 4; i++) {
            switch (mbStatusData[i].spaceType) {
            case 1:
                group1[group1Count++] = i;
                break;
            case 2:
                group2[group2Count++] = i;
                break;
            default:
                otherCount++;
                break;
            }
        }

        if (otherCount != 0) {
            for (i = 0; i < 5; i++) {
                group1[i] = i;
            }
            group1Count = 5;
            group2Count = 0;
        }
        otherCount = 0;
        for (i = 0; i < group1Count; i++) {
            slot[group1[i]] = otherCount++;
        }
        for (i = 0; i < group2Count; i++) {
            slot[group2[i]] = otherCount++;
        }
    }

    for (i = 0; i < 4; i++) {
        sp = &mbStatusData[i];

        /* Modes 10-13, 14-17 and 18-21 target one specific player only. */
        if ((arg0 >= 10) && (arg0 <= 13) && (i != arg0 - 10)) continue;
        if ((arg0 >= 14) && (arg0 <= 17) && (i != arg0 - 14)) continue;
        if ((arg0 >= 18) && (arg0 <= 21) && (i != arg0 - 18)) continue;
        if ((arg0 == 22) && (i != D_80101780_1153A0_shared_board)) continue;
        if ((arg0 == 23) && (i != D_80101784_1153A4_shared_board)) continue;
        if ((arg0 == 24) && (i != D_80101784_1153A4_shared_board)) continue;

        switch (arg0) {
        case 0:
        case 10:
        case 11:
        case 12:
        case 13:
            MBStatusPosSet(i, PlayerBoardStatusRootPosition[i + 4][0],
                              PlayerBoardStatusRootPosition[i + 4][1]);
            break;
        case 22:
            MBStatusPosSet(D_80101780_1153A0_shared_board,
                           PlayerBoardStatusRootPosition[4][0],
                           PlayerBoardStatusRootPosition[4][1] + 0x20);
            break;
        case 23:
            MBStatusPosSet(D_80101784_1153A4_shared_board,
                           PlayerBoardStatusRootPosition[5][0],
                           PlayerBoardStatusRootPosition[5][1] + 0x20);
            break;
        case 24:
            MBStatusPosSet(D_80101784_1153A4_shared_board,
                           PlayerBoardStatusRootPosition[5][0],
                           PlayerBoardStatusRootPosition[5][1]);
            break;
        }

        sp->unkE = 19;
        switch (arg0) {
        case 25: // 0xCC
        case 26: // 0xD0
            sp->unkE = 5;
            goto dummy;
        case 6: // 0x80
        case 7:
        case 8:
        case 9: // 0x8C
            sp->unkE = 15;
            goto dummy;
        case 0: // 0x68
        case 1: // 0x6C
        case 3: // 0x74
        case 4: // 0x78
        case 10: // 0x90
        case 11:
        case 12:
        case 13: // 0x9C
            dummy:
            sp->unk_18 = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + i][0];
            sp->unk_1C = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + i][1];
            break;
        case 2: // 0x70
            sp->unk_18 = D_80101964_115584_shared_board[group1Count][slot[i]][0];
            sp->unk_1C = D_80101964_115584_shared_board[group1Count][slot[i]][1];
            sp->unkE = 9;
            break;
        case 5:
            /* Slide off whichever side of the screen it is already on. */
            if (sp->xPos >= 160.0f) {
                sp->unk_18 = sp->xPos + 1920.0f;
            } else {
                sp->unk_18 = sp->xPos - 1920.0f;
            }
            sp->unk_1C = sp->yPos;
            sp->unkE = 19;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            sp->unk_18 = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + i][0];
            sp->unk_1C = sp->yPos;
            break;
        case 22:
            sp->unk_18 = PlayerBoardStatusRootPosition[0][0];
            sp->unk_1C = PlayerBoardStatusRootPosition[0][1] + 0x20;
            break;
        case 23:
            sp->unk_18 = PlayerBoardStatusRootPosition[1][0];
            sp->unk_1C = PlayerBoardStatusRootPosition[1][1] + 0x20;
            break;
        case 24:
            sp->unk_18 = PlayerBoardStatusRootPosition[1][0];
            sp->unk_1C = PlayerBoardStatusRootPosition[1][1];
            break;
        case 27:
            if (i == D_80101788_1153A8_shared_board) {
                sp->unk_18 = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0]][0];
                sp->unk_1C = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0]][1];
            } else if (i == D_8010178C_1153AC_shared_board) {
                sp->unk_18 = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + 1][0];
                sp->unk_1C = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + 1][1];
            } else {
                sp->unk_18 = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + 2 + i][0];
                sp->unk_1C = PlayerBoardStatusRootPosition[D_80101928_115548_shared_board[arg0] + 2 + i][1];
            }
            break;
        }

        sp->unk_20 = sp->unk_28 = (2.0f * (sp->unk_18 - sp->xPos)) / (f32) ((sp->unkE + 1) * (sp->unkE + 1));
        sp->unk_24 = sp->unk_2C = (2.0f * (sp->unk_1C - sp->yPos)) / (f32) ((sp->unkE + 1) * (sp->unkE + 1));

        if (arg0 == 5) {
            D_801055D4_1191F4_shared_board.x = D_801055DC_1191FC_shared_board.x = 0.0f;
            D_801055D4_1191F4_shared_board.y = D_801055DC_1191FC_shared_board.y = 2.0f;
            D_801055E4_119204_shared_board = sp->unkE;
        }
    }

    if ((arg0 == 2) && (group1Count != 5)) {
        if ((group1Count == 4) || (group1Count == 0)) {
            /* Free-for-all: everyone in their own group. */
            for (i = 0; i < 4; i++) {
                GwPlayer[i].group = i;
            }
        } else if (group1Count == 3) {
            for (i = 0; i < group1Count; i++) {
                GwPlayer[group1[i]].group = 1;
            }
            for (i = 0; i < group2Count; i++) {
                GwPlayer[group2[i]].group = 0;
            }
        } else {
            for (i = 0; i < group1Count; i++) {
                GwPlayer[group1[i]].group = 0;
            }
            for (i = 0; i < group2Count; i++) {
                GwPlayer[group2[i]].group = 1;
            }
        }
    }

    if ((arg0 == 6) || (arg0 == 7) || (arg0 == 8) || (arg0 == 9)) {
        for (i = 0; i < 4; i++) {
            if (i == arg0 - 6) {
                GwPlayer[i].group = 0;
            } else {
                GwPlayer[i].group = 1;
            }
        }
    }

    return 0;
}


s32 func_800F5278_108E98_shared_board(void) {
    s32 var_a0 = FALSE;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (mbStatusData[i].unkE != -2) {
            var_a0 = TRUE;
        }
    }
    return var_a0;
}

// decide what type of minigame will be played
s32 func_800F52C4_108EE4_shared_board(void) {
    u8 type1Indices[4];
    u8 type2Indices[4];
    u8 otherCount = 0;
    u8 redCount = 0;
    u8 blueCount = 0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        switch (mbStatusData[i].spaceType) {
            case SPACE_BLUE:
                type1Indices[blueCount++] = i;
                break;
            case SPACE_RED:
                type2Indices[redCount++] = i;
                break;
            default:
                otherCount++;
        }
    }

    // Determine result based on counts
    if (otherCount > 0) {
        return -1;
    }

    if (blueCount == 0 || blueCount == 4) {
        return 0;
    }

    if (blueCount == 1) {
        D_801055F8_119218_shared_board = type1Indices[0];
        return 1;
    }

    if (blueCount == 3) {
        D_801055F8_119218_shared_board = type2Indices[0];
        return 1;
    }

    return 2;
}

void MBVsSprCreate(void) {
    void *temp_s0;

    if (D_801055C2_1191E2_shared_board == -1) {
        D_801055C2_1191E2_shared_board = HuSprGrpCreate(1, 0);
        temp_s0 = DataRead(0x130115);
        D_801055CC_1191EC_shared_board.y = 158.0f;
        D_801055C4_1191E4_shared_board = func_80055810_56410(temp_s0);
        DataClose(temp_s0);
        func_80055024_55C24(D_801055C2_1191E2_shared_board, 0, D_801055C4_1191E4_shared_board, 0);
        HuSprPriSet(D_801055C2_1191E2_shared_board, 0, 0x4780);
        HuSprAttrSet(D_801055C2_1191E2_shared_board, 0, 0x1000);
        func_80054904_55504(D_801055C2_1191E2_shared_board, 0, 0xA0, D_801055CC_1191EC_shared_board.y);
        HuSprScaleSet(D_801055C2_1191E2_shared_board, 0, 0.0f, 0.0f);
        D_801055C8_1191E8_shared_board = 0.0f;
        D_801055CC_1191EC_shared_board.x = 160.0f;
        D_801055D4_1191F4_shared_board.x = D_801055D4_1191F4_shared_board.y = 0.0f;

        D_801055E4_119204_shared_board = 0;
    }
}

void MBVsSprCreateY(f32 arg0, f32 arg1) {
    void *temp_s0;

    if (D_801055C2_1191E2_shared_board == -1) {
        D_801055C2_1191E2_shared_board = HuSprGrpCreate(1, 5);
        temp_s0 = DataRead(0x130115);
        D_801055CC_1191EC_shared_board.y = arg1;
        D_801055C4_1191E4_shared_board = func_80055810_56410(temp_s0);
        DataClose(temp_s0);
        func_80055024_55C24(D_801055C2_1191E2_shared_board, 0, D_801055C4_1191E4_shared_board, 0);
        HuSprPriSet(D_801055C2_1191E2_shared_board, 0, 0x4780);
        HuSprAttrSet(D_801055C2_1191E2_shared_board, 0, 0x1000);
        func_80054904_55504(D_801055C2_1191E2_shared_board, 0, 0xA0, D_801055CC_1191EC_shared_board.y);
        HuSprScaleSet(D_801055C2_1191E2_shared_board, 0, 0.0f, 0.0f);
        D_801055C8_1191E8_shared_board = 0.0f;
        D_801055CC_1191EC_shared_board.x = arg0;
        D_801055D4_1191F4_shared_board.x = D_801055D4_1191F4_shared_board.y = 0.0f;
        D_801055E4_119204_shared_board = 0;
    }
}

void MBVsSprKill(void) {
    if (D_801055C2_1191E2_shared_board != -1) {
        HuSprGrpKill(D_801055C2_1191E2_shared_board);
        D_801055C2_1191E2_shared_board = -1;
    }
    if (D_801055C4_1191E4_shared_board != -1) {
        HuSprKill(D_801055C4_1191E4_shared_board);
        D_801055C4_1191E4_shared_board = -1;
    }
}

static void func_800F56A8_1092C8_shared_board(omObjData *arg0) {
    BoardStatus *temp_s2 = &mbStatusData[arg0->work[0]];
    f32 var_f0;
    f32 var_f0_2;
    s32 i;

    for (i = 0; i < 0xE; i++) {
        if ((HuMathSin(arg0->rot.x) * 0.15f) > 0.0f) {
            var_f0 = (HuMathSin(arg0->rot.x) * 0.15f) + 1.0f;
        } else {
            var_f0 = (0.0f - (HuMathSin(arg0->rot.x) * 0.15f)) + 1.0f;
        }

        if ((HuMathSin(arg0->rot.x) * 0.15f) > 0.0f) {
            var_f0_2 = (HuMathSin(arg0->rot.x) * 0.15f) + 1.0f;
        } else {
            var_f0_2 = (0.0f - (HuMathSin(arg0->rot.x) * 0.15f)) + 1.0f;
        }
        HuSprScaleSet(temp_s2->playerIndex, i, var_f0, var_f0_2);
    }

    arg0->rot.x += 10.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
}

void func_800F5828_109448_shared_board(s32 arg0) {
    BoardStatus *temp_s1 = &mbStatusData[arg0];
    omObjData *temp_v0;
    s32 i, j;

    if (temp_s1->unk30 == NULL) {
        temp_v0 = omAddObj(-0x8000, 0, 0, -1, func_800F56A8_1092C8_shared_board);
        temp_s1->unk30 = temp_v0;
        temp_v0->rot.x = 0;
        temp_v0->work[0] = arg0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            for (j = 0; j < 0xE; j++) {
                HuSprScaleSet(mbStatusData[i].playerIndex, j, 1.0f, 1.0f);
            }
        }
    }
}

void func_800F591C_10953C_shared_board(s32 arg0) {
    BoardStatus *temp_s1 = &mbStatusData[arg0];
    s32 i;

    if (temp_s1->unk30 != NULL) {
        omDelObj((omObjData *)temp_s1->unk30);
        temp_s1->unk30 = 0;
        for (i = 0; i < 0xE; i++) {
            HuSprScaleSet(temp_s1->playerIndex, i, 1.0f, 1.0f);
        }
    }
}

static void func_800F59B4_1095D4_shared_board(omObjData *obj) {
    s32 var_s1 = 0;

    while (obj->scale.y <= 0.0f) {
        if (obj->trans.x > 0.0f) {
            MBPlayerCoinAdd(obj->work[0], 1);
            if (((obj->work[3] != 0) & (var_s1 == 0)) && (obj->scale.z >= 3.0f)) {
                HuAudFXPlay(0x106);
                var_s1 = 1;
                obj->scale.z -= 3.0f;
            }
            obj->trans.x -= 1.0f;

        } else {
            MBPlayerCoinAdd(obj->work[0], -1);
            obj->trans.x += 1.0f;
            if (obj->work[3] != 0) {
                if ((var_s1 == 0) && (obj->scale.z >= 3.0f)) {
                    HuAudFXPlay(0x109);
                    var_s1 = 1;
                    obj->scale.z -= 3.0f;
                }
                if ((obj->trans.x == 0.0f) || (GwPlayer[obj->work[0]].coin == 0)) {
                    HuAudFXPlay(0x10A);
                }
            }
        }

        if ((obj->trans.x == 0.0f) || (GwPlayer[obj->work[0]].coin == 0)) {
            D_801055E8_119208_shared_board[obj->work[0]] = NULL;
            omDelObj(obj);
            return;
        }
        obj->scale.y += obj->scale.x;
    }

    obj->scale.y -= 1.0f;
    obj->scale.z += 2.0f;
}

void MBCoinTakeCreateSound(s32 playerIndex, s32 coinAmount, s32 arg2) {
    if (coinAmount != 0) {
        if (D_801055E8_119208_shared_board[playerIndex] != NULL) {
            MBPlayerCoinAdd(playerIndex, coinAmount);
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
        (D_801055E8_119208_shared_board[playerIndex])->scale.z = 3.0f;
        (D_801055E8_119208_shared_board[playerIndex])->work[3] = arg2;
    }
}

void MBCoinTakeCreate(s32 playerNo, s32 arg1) {
    MBCoinTakeCreateSound(playerNo, arg1, 1);
}

s32 MBCoinTakeCheck(s32 playerNo) {
    if (D_801055E8_119208_shared_board[playerNo]) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 MBStatusHideCheck(void) {
    if (mbStatusData->uiVisible & 1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

// toggle hide player UI bit on
void MBStatusHideAll(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        mbStatusData[i].uiVisible |= 1;
    }
}

// toggle hide player UI bit off
void MBStatusShowAll(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        mbStatusData[i].uiVisible &= ~1;
    }
}

void func_800F5E24_109A44_shared_board(s32 arg0) {
    D_80101784_1153A4_shared_board = arg0;
}

void func_800F5E30_109A50_shared_board(void) {
    s32 i;

    MBStatusAnimCreate();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F43FC_10801C_shared_board(i);
        MBStatusPosSet(i, PlayerBoardStatusRootPosition[i + 4][0], PlayerBoardStatusRootPosition[i + 4][1]);
        MBStatusColorSet(i, GwPlayer[i].color);
    }

    D_80105580_1191A0_shared_board = omAddPrcObj(MBStatusMain, 0, 0x2000, 0);
    omPrcSetStatBit(D_80105580_1191A0_shared_board, 0x80);
    D_801055C4_1191E4_shared_board = -1;
    D_801055C2_1191E2_shared_board = -1;
}

void func_800F5EF0_109B10_shared_board(void) {
    func_800F462C_10824C_shared_board(D_80101780_1153A0_shared_board);
    func_800F462C_10824C_shared_board(D_80101784_1153A4_shared_board);
    MBStatusAnimKill();
    HuPrcKill(D_80105580_1191A0_shared_board);
    MBVsSprKill();
    D_80101780_1153A0_shared_board = -1;
    D_80101784_1153A4_shared_board = -1;
}

void func_800F5F4C_109B6C_shared_board(s32 arg0, s32 arg1) {
    D_80101780_1153A0_shared_board = arg0;
    D_80101784_1153A4_shared_board = arg1;
}

void func_800F5F60_109B80_shared_board(void) {
    MBStatusDispMoveSet(0x16);
}

void func_800F5F7C_109B9C_shared_board(void) {
    MBStatusDispMoveSet(0x17);
}

static void MBStatusItemSprCreate(s32 playerNo, s32 arg1) {
    BoardStatus *temp_s7 = &mbStatusData[playerNo];
    s16 temp_s5 = temp_s7->playerIndex;
    void *var_s2 = NULL;
    s32 sp10;
    s32 sp14;
    s16 i;
    
    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        var_s2 = NULL;
        if (GwPlayer[playerNo].itemNo[i] != ITEM_NONE) {
            var_s2 = DataRead(D_8010197C_11559C_shared_board[GwPlayer[playerNo].itemNo[i]]);
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
                HuSprPriSet(temp_s5, i + 2, (playerNo * 5) + 0x4790);
            } else {
                HuSprPriSet(temp_s5, i + 2, ((playerNo * 5) + 0x478F) & 0xFFFF);
            }
            HuSprAttrSet(temp_s5, i + 2, 0x180C);
            HuSprAttrReset(temp_s5, i + 2, 0x8000);
            func_800552DC_55EDC(temp_s5, i + 2, 0.0f);
            if (GwPlayer[playerNo].itemNo[0] != ITEM_NONE) {
                if (arg1 != 0) {
                    MBStatusItemPosGet(playerNo, i, &sp10, &sp14);
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
                    xPos = (PlayerBoardStatusRootPosition[playerNo][0] + 0x38);
                    yPos = (PlayerBoardStatusRootPosition[playerNo][1] + 0x13);
                    xPos = xPos + 22.0f;
                    xPos = xPos - 4.0f;

                    func_80054904_55504(temp_s7->playerIndex, 2, xPos, yPos);
                } else {
                    func_80054904_55504(temp_s5, 2, 0x12, 0);
                }
            }
            HuSprScaleSet(temp_s5, i + 2, 1.0f, 1.0f);
            func_800550B4_55CB4(temp_s5, i + 2, 0.0f);
            if (playerNo == GwSystem.current_player_index) {
                func_80055458_56058(temp_s5, i + 2, 0x100);
            } else {
                func_80055458_56058(temp_s5, i + 2, 0x80);
            }

        } else {
            temp_s7->unk_40[i] = -1;
        }
    }
}

void MBStatusItemIconSprReinit(s32 arg0) {
    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }
    MBStatusItemIconSprCreate(arg0);
}

void MBStatusItemSprKill(s32 playerIndex) {
    BoardStatus *temp_s2;
    s32 i;

    if (playerIndex == CUR_PLAYER) {
        playerIndex = GwSystem.current_player_index;
    }

    temp_s2 = &mbStatusData[playerIndex];

    for (i = 0; i < ARRAY_COUNT(temp_s2->unk_40); i++) {
        if (temp_s2->unk_40[i] != -1) {
            MBStatusSprBmpClear(temp_s2->playerIndex, i + 2);
            HuSprKill(temp_s2->unk_40[i]);
            temp_s2->unk_40[i] = -1;
        }
    }

    MBStatusItemSprCreate(playerIndex, 1);
}

void MBStatusItemDispSet(s32 playerNo, s32 arg1) {
    BoardStatus *temp_s2;
    s32 i;

    temp_s2 = &mbStatusData[playerNo];
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

                MBStatusIconSprCreate(playerNo);
                MBStatusNumSprCreate(playerNo);
                MBStatusRankSprCreate(playerNo);
                MBStatusItemIconSprCreate(playerNo);
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
                MBStatusItemSprCreate(playerNo, 0);
                break;
        }
    }
}

void MBStatusItemDispSetAll(s32 arg0) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        MBStatusItemDispSet(i, arg0);
    }
}

s32 MBStatusItemDispGet(s32 playerNo) {
    return mbStatusData[playerNo].uiUpdatePaused;
}

void MBStatusSprPosGet(s16 arg0, s16 arg1, f32 *arg2, f32 *arg3) {
    HuSprite *sprite = HuSprGrpData[arg0]->members[arg1];

    *arg2 = sprite->unk_48;
    *arg3 = sprite->unk_4C;
}

void MBStatusItemOfsApply(s32 playerNo, s32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f20;
    f32 temp_f22;
    s32 temp_s1;

    temp_s1 = mbStatusData[playerNo].playerIndex;
    MBStatusSprPosGet(temp_s1, arg1 + 2, &temp_f20, &temp_f22);
    temp_f20 += arg2;
    temp_f22 += arg3;
    func_80054904_55504(temp_s1, arg1 + 2, temp_f20, temp_f22);
}

void func_800F6848_10A468_shared_board(s32 playerNo, s32 arg1, f32 *arg2, f32 *arg3) {
    MBStatusSprPosGet(mbStatusData[playerNo].playerIndex, (arg1 + 2), arg2, arg3);
}

void MBStatusItemPosSet(s32 playerNo, s32 arg1, s16 arg2, s16 arg3) {
    func_80054904_55504(mbStatusData[playerNo].playerIndex, (arg1 + 2), arg2, arg3);
}

void MBStatusItemTPLvlSet(s32 playerNo, s32 arg1, s16 arg2) {
    func_80055458_56058(mbStatusData[playerNo].playerIndex, (arg1 + 2), arg2);
}

void MBStatusItemRotSet(s32 playerNo, s32 arg1, f32 arg2) {
    func_800552DC_55EDC(mbStatusData[playerNo].playerIndex, (arg1 + 2), arg2);
}

void MBStatusItemScaleSet(s32 playerNo, s32 arg1, f32 arg2, f32 arg3) {
    HuSprScaleSet(mbStatusData[playerNo].playerIndex, arg1 + 2, arg2, arg3);
}

void MBStatusItemPriSet(s32 playerNo, s32 arg1, u16 arg2) {
    HuSprPriSet(mbStatusData[playerNo].playerIndex, arg1 + 2, arg2);
}

void MBStatusItemAttrSet(s32 playerNo, s32 arg1, u16 arg2) {
    HuSprAttrSet(mbStatusData[playerNo].playerIndex, arg1 + 2, arg2);
}

void MBStatusItemAttrReset(s32 playerNo, s32 arg1, u16 arg2) {
    HuSprAttrReset(mbStatusData[playerNo].playerIndex, arg1 + 2, arg2);
}

void func_800F6A88_10A6A8_shared_board(s16 arg0, u16 arg1) {
    HuSprGrpData[arg0]->unk_08 = arg1;
}

void MBStatusSprBmpClear(s16 arg0, s16 arg1) {
    HuSprGrpData[arg0]->members[arg1]->unk_84 = NULL;
}

void MBStatusScaleSet(s32 arg0, f32 xScale, f32 yScale) {
    BoardStatus *temp_s1 = &mbStatusData[arg0];
    s32 i;

    switch (temp_s1->uiUpdatePaused) {
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

void MBStatusShrink(s32 playerNo) {
    BoardStatus *temp_s2;
    f32 var_f20;
    s32 i, j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (playerNo == CUR_PLAYER || playerNo == i) {
            temp_s2 = &mbStatusData[i];
            if (temp_s2->uiUpdatePaused == TRUE) {
                func_800F6A88_10A6A8_shared_board(temp_s2->playerIndex, 2);
                func_80054904_55504(temp_s2->playerIndex, 1, D_801018E4_115504_shared_board[1][0], D_801018E4_115504_shared_board[1][1]);
                if (GwPlayer[i].itemNo[0] != ITEM_NONE) {
                    // used for item positions when closing items screen
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
            if (playerNo == CUR_PLAYER || playerNo == i) {
                MBStatusScaleSet(i, HuMathCos(var_f20), 1.0f);
            }
        }
        HuPrcVSleep();
    }
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (playerNo == CUR_PLAYER || playerNo == i) {
            MBStatusScaleSet(i, 0.0f, 0);
        }
    }
    HuPrcVSleep();
}

// sets item positions when pressing B and you have control of hand cursor
void MBStatusItemPosGet(s32 playerIndex, s32 itemIndex, s32 *xPos, s32 *yPos) {
    s32 xPosTemp;

    if (playerIndex == CUR_PLAYER) {
        playerIndex = GwSystem.current_player_index;
    }

    *xPos = PlayerBoardStatusRootPosition[playerIndex][0] + ITEMS_POS_OFFSET_X;
    *yPos = PlayerBoardStatusRootPosition[playerIndex][1] + ITEMS_POS_OFFSET_Y;

    xPosTemp = *xPos + 3;
    *xPos = xPosTemp + (itemIndex * 18);
    // if item index is 1, move item up on the screen 5 units
    // if item index 0 or 2, move down on the screen 5 units
    if (itemIndex == 1) {
        *yPos -= 5;
    } else {
        *yPos += 5;
    }
}

void MBStatusGrow(s32 playerNo) {
    s32 sp10;
    s32 sp14;
    BoardStatus *temp_s2;
    f32 var_f20;
    s32 i, j;

    for (var_f20 = 90.0f; var_f20 >= 0.0f; var_f20 -= 15.0f) {
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (playerNo == CUR_PLAYER || playerNo == i) {
                MBStatusScaleSet(i, HuMathCos(var_f20), 1.0f);
            }
        }
        HuPrcVSleep();
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (playerNo == CUR_PLAYER || playerNo == i) {
            MBStatusScaleSet(i, 1.0f, 1.0f);
            temp_s2 = &mbStatusData[i];
            if (temp_s2->uiUpdatePaused == TRUE) {
                func_800F6A88_10A6A8_shared_board(temp_s2->playerIndex, 0);
                sp10 = PlayerBoardStatusRootPosition[i][0] + ITEMS_POS_OFFSET_X;
                sp14 = PlayerBoardStatusRootPosition[i][1] + ITEMS_POS_OFFSET_Y;
                func_80054904_55504(temp_s2->playerIndex, 1, sp10, sp14);
                if (GwPlayer[i].itemNo[0] != ITEM_NONE) {
                    for (j = 0; j < ARRAY_COUNT(GwPlayer->itemNo); j++) {
                        MBStatusItemPosGet(i, j, &sp10, &sp14);
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

// draw item icons
void func_800F70F8_10AD18_shared_board(void) {
    D_80101790_1153B0_shared_board = 1;
}

// hide item icons
void func_800F7108_10AD28_shared_board(void) {
    D_80101790_1153B0_shared_board = 0;
}

void func_800F7114_10AD34_shared_board(s32 arg0, s32 arg1) {
    D_80101788_1153A8_shared_board = arg0;
    D_8010178C_1153AC_shared_board = arg1;
}

//TODO: subsegment align issues. So many things point to rodata aligned to 16, but then certain places have issues at 8...confusing
const u8 padRodata[] = "\0\0\0\0\0\0\0";