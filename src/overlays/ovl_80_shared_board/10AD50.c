#include "common.h"
#include "101840.h"
#include "105D50.h"
#include "106A50.h"
#include "F5E80.h"
#include "ECA50.h"
#include "FA250.h"
#include "106640.h"
#include "FFB10.h"

extern Object *D_80105620_shared_board;
extern Object *D_80105624_shared_board;
extern Object* D_80105628_shared_board;

extern s32 D_80105630_shared_board[3];
extern s32 D_80105634_shared_board; //TODO: fake symbol
extern s32 D_80105638_shared_board; //TODO: fake symbol
extern f32 D_80105650_shared_board;
extern s32 D_80105654_shared_board;
extern s32 D_80105658_shared_board;
extern s32 D_8010565C_shared_board;

static void func_800F7CF0_shared_board(void);
static void func_800F7D10_shared_board(void);
static void func_800F7D4C_shared_board(void);
static void func_800F7D98_shared_board(void);
static void func_800F7DD4_shared_board(void);
static void func_800F7E1C_shared_board(void);
static void func_800F7E64_shared_board(void);
static void func_800F7EAC_shared_board(void);
static void func_800F7EF4_shared_board(void);
static void func_800F7F30_shared_board(void);
static void func_800F7F7C_shared_board(void);
static void func_800F7FC8_shared_board(void);


// item ids
s32 D_80101A20_shared_board[] = {
    ITEM_MUSHROOM, ITEM_SKELETON_KEY, ITEM_BOO_REPELLENT,
    ITEM_DUEL_GLOVE, ITEM_WARP_BLOCK, ITEM_GOLDEN_MUSHROOM,
    ITEM_MAGIC_LAMP, ITEM_CELLULAR_SHOPPER
};

// rare item ids?
s32 D_80101A40_shared_board[] = {
    ITEM_KOOPA_KARD, ITEM_BARTER_BOX, ITEM_LUCKY_CHARM,
    ITEM_WACKY_WATCH
};

s32 D_80101A50_shared_board[] = {
    ITEM_SKELETON_KEY, ITEM_PLUNDER_CHEST, ITEM_BOWSER_PHONE,
    ITEM_WARP_BLOCK, ITEM_BOO_BELL, ITEM_BOWSER_SUIT,
    ITEM_POISON_MUSHROOM, ITEM_REVERSE_MUSHROOM, ITEM_LUCKY_LAMP
};

f32 D_80101A74_shared_board[][2] = {
    { 88.0f, 44.0f }, { 245.0f, 44.0f }, { 88.0f, 220.0f }, { 245.0f, 220.0f }
};

s32 D_80101A94_shared_board[] = {
    [ITEM_MUSHROOM] 0,
    [ITEM_SKELETON_KEY] 0,
    [ITEM_POISON_MUSHROOM] 0,
    [ITEM_REVERSE_MUSHROOM] 0,
    [ITEM_CELLULAR_SHOPPER] 0,
    [ITEM_WARP_BLOCK] 0,
    [ITEM_PLUNDER_CHEST] 0,
    [ITEM_BOWSER_PHONE] 0,
    [ITEM_DUEL_GLOVE] 0,
    [ITEM_LUCKY_LAMP] 0,
    [ITEM_GOLDEN_MUSHROOM] 0,
    [ITEM_BOO_BELL] 0,
    [ITEM_BOO_REPELLENT] 0,
    [ITEM_BOWSER_SUIT] 0,
    [ITEM_MAGIC_LAMP] 0,
    [ITEM_KOOPA_KARD] 0x00003C0E,
    [ITEM_BARTER_BOX] 0x00003C10,
    [ITEM_LUCKY_CHARM] 0x00003C11,
    [ITEM_WACKY_WATCH] 0x00003C0F
};

void (*D_80101AE0_shared_board[])(void) = {
    func_800F7CF0_shared_board,
    func_800F7D10_shared_board,
    func_800F7D4C_shared_board,
    func_800F7D98_shared_board,
    func_800F7DD4_shared_board,
    func_800F7E1C_shared_board
};

void (*D_80101AF8_shared_board[])(void) = {
    func_800F7E64_shared_board,
    func_800F7EAC_shared_board,
    func_800F7EF4_shared_board,
    func_800F7F30_shared_board,
    func_800F7F7C_shared_board,
    func_800F7FC8_shared_board
};

s32 D_80101B10_shared_board[] = {
    0x00003C03, 0x00003C04, 0x00003C05, 0x00003C06, 0x00003C07
};

s32 D_80101B24_shared_board[] = {
    0x00003C15, 0x00003C16, 0x00003C17,
    0x00003C18, 0x00003C19, 0x00003C1A
};

static void func_800F7130_shared_board(omObjData *arg0) {
    D_80105620_shared_board->coords.y = -HuMathSin(arg0->rot.x) * 3.0f;
    D_80105624_shared_board->coords.y = -HuMathSin(arg0->rot.x) * 3.0f;
    arg0->rot.x += 3.0f;
}

static void func_800F71A8_shared_board(omObjData *obj) {
    D_80105650_shared_board += 20.0f;
    if (D_80105650_shared_board >= 360.0f) {
        D_80105650_shared_board -= 360.0f;
    }

    func_8008A430_main(&HmfModelData[D_80105628_shared_board->omObj1->model[0]].mtx, D_80105650_shared_board);
}

static s32 func_800F7240_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 sp18[MB_MAX_PLAYERS];
    u8 sp20[MB_MAX_PLAYERS] = { 1, 2, 4, 8 };
    s32 var_v0;
    s32 i;
    s32 j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == GwSystem.current_player_index) {
            if (GwPlayer[i].stat & 1) {
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_main(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }

        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (arg2 != 0) {
        func_8005B63C_main(mbDlgWinId, 2, 2);
        for (j = 0; arg2 != 0; j++) {
            if (--arg2 == 0) {
                sp18[GwPlayer[GwSystem.current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_main(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_shared_board());
            } else {
                func_8005F698_main(sp18[0], sp18[1], sp18[2], sp18[3], 0x10);
            }
        }
    } else {
        func_8005F744_main(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    for (i = 0; i < arg3; i++) {
        if ((arg0 != 0) && ((u8 *)arg0)[i] == 0) {
            func_8006010C_main(mbDlgWinId, i);
        }
    }

    i = 0;

    while (1) {
        i = func_8005E1D8_main(mbDlgWinId, i, arg1);
        if (arg1 != 0) {
            if ((arg0 == 0) || ((((u8 *)arg0)[i] != 0))) {
                return i;
            }
        } else if (i == -1) {
            return -1;
        } else {
            if ((arg0 == 0) || ((((u8 *)arg0)[i] != 0))) {
                return i;
            }
        }
    }
}

// All items you can carry from item space
void func_800F74E4_shared_board(void) {
    s32 prev;
    s32 i;
    s32 *boardItemIds;

    prev = -1;
    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        boardItemIds = &D_80105630_shared_board[i];
        while (1) {
            *boardItemIds = D_80101A20_shared_board[MBRand(ARRAY_COUNT(D_80101A20_shared_board))];
            if (*boardItemIds != prev) {
                prev = *boardItemIds;
                break;
            }
        }
    }
}

#ifdef NON_MATCHING
// more readable version of the function as the matching version is very jank
void func_800F7578_shared_board(void) {
    s32 *temp2 = D_80101A40_shared_board;
    s32 itemID;

    while (1) {
        itemID = temp2[MBRand(ARRAY_COUNT(D_80101A40_shared_board))];
        D_80105630_shared_board[0] = itemID;

        if (itemID == ITEM_WACKY_WATCH && GwSystem.unk_52 == WATCH_AVAILABLE) {
            GwSystem.unk_52 = 1;
            break;
        }

        if (itemID != ITEM_WACKY_WATCH) {
            break;
        }
    }

    D_80105634_shared_board = -1;
    D_8010565C_shared_board = itemID;
}
#else
// TODO: cleanup this jank function
void func_800F7578_shared_board(void) {
    s32 itemID;
    
    while (1) {
        itemID = D_80105630_shared_board[0] = D_80101A40_shared_board[MBRand(ARRAY_COUNT(D_80101A40_shared_board))];
        if (itemID != ITEM_WACKY_WATCH) {
            break;
        }

        //is wacky watch to get here
        if (GwSystem.wackyWatchUsedState == WATCH_AVAILABLE) {
            if (itemID == ITEM_WACKY_WATCH) {
                GwSystem.wackyWatchUsedState = WATCH_ISSUED;
            }
            break;
        }
        if (itemID != ITEM_WACKY_WATCH) {
            GwSystem.wackyWatchUsedState = WATCH_ISSUED;
        }
    }

    D_80105634_shared_board = -1;
    D_8010565C_shared_board = itemID;
}
#endif

// All items you can carry from item space
void func_800F7610_shared_board(void) {
    s32 prev;
    s32 i;
    s32 *boardItemIds;

    prev = -1;
    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        boardItemIds = &D_80105630_shared_board[i];
        while (1) {
            *boardItemIds = D_80101A50_shared_board[MBRand(ARRAY_COUNT(D_80101A50_shared_board))];
            if (*boardItemIds != prev) {
                prev = *boardItemIds;
                break;
            }
        }
    }
}

void func_800F76A4_shared_board(s32 arg0) {
    f32 sp20[2];
    GW_PLAYER *player;
    UnkBoard8 *temp_s2;
    f32 var_f20;
    f32 var_f28;
    omObjData *obj;
    s32 playerNo;
    s32 temp_s6;
    s32 var_s4;
    void *temp_v0;
    s32 i;

    player = MBPlayerGet(CUR_PLAYER);
    playerNo = MBPlayerTurnGet();
    MBStatusShrink(-1);
    MBStatusItemDispSetAll(1);
    MBStatusGrow(-1);

    var_s4 = 0;
    if (arg0 == 0) {
        var_f28 = 5.0f;
    } else {
        var_f28 = 10.0f;
    }

    while ((MBItemFindEmpty(playerNo) != ITEM_NONE) && (D_80105630_shared_board[var_s4] != -1)) {
        if (D_80105654_shared_board != 0) {
            D_80105628_shared_board = MBModelCreate(0x22, NULL);
        } else {
            D_80105628_shared_board = MBModelFileCreate(0xB0036, -1, 1.0f, 0, 0);
        }
        func_8001C258_main(D_80105628_shared_board->omObj1->model[0], 0x180, 0);
        func_8001C8E4_main(D_80105628_shared_board->omObj1->model[0], 0x1800);
        func_8001C448_main(D_80105628_shared_board->omObj1->model[0]);
        HuVecCopy3F(&D_80105628_shared_board->coords, &player->player_obj->coords);
        D_80105628_shared_board->coords.y += 25.0f;
        MBCamera3Dto2D(&D_80105628_shared_board->coords, sp20);
        HuAudFXPlay(0x143);
        D_80105650_shared_board = 0;

        obj = omAddObj(0x1F4, 0, 0, -1, func_800F71A8_shared_board);
        for (var_f20 = 1.0f; var_f20 < var_f28; var_f20 += 0.5) {
            HuVecCopyXYZ(&D_80105628_shared_board->scale, var_f20, var_f20, var_f20);
            HuPrcVSleep();
        }

        var_f20 = var_f20 - 0.5f;

        HuAudFXPlay(0x11C);
        temp_s6 = D_80105630_shared_board[var_s4++];
        temp_s2 = func_800F2C48_shared_board(1, 0);
        temp_v0 = DataRead(D_8010197C_shared_board[temp_s6]);
        temp_s2->model[0] = func_80055810_main(temp_v0);
        DataClose(temp_v0);
        func_80055024_main(temp_s2->spriteGroup, 0, temp_s2->model[0], 0);
        HuSprAttrReset(temp_s2->spriteGroup, 0, 0xFFFF);
        HuSprAttrSet(temp_s2->spriteGroup, 0, 0x1000);
        HuSprPriSet(temp_s2->spriteGroup, 0, 0x1000U);
        func_80054904_main(temp_s2->spriteGroup, 0, sp20[0], sp20[1]);

        for (i = 0; i < 15; i++) {
            func_80055458_main(temp_s2->spriteGroup, 0, ((i * 16) + i));
            HuPrcVSleep();
        }

        func_80055458_main(temp_s2->spriteGroup, 0, 0xFF);

        if (arg0 == 1) {
            MBDlgWinInsertCreateY(-1, 0x3C0D, D_80101A94_shared_board[D_8010565C_shared_board], 0, 0, 0, 0, 0x8C);
            MBDlgWinClose();
            MBDlgWinKill();
        }
        for (i = 0; i < 70; i += 5) {
            // this sure is a line of code
            func_80054904_main(temp_s2->spriteGroup, 0, (((HuMathSin(i) * (D_80101A74_shared_board[playerNo][0] - sp20[0])) + sp20[0])), ((sp20[1] - (HuMathSin((i + 0x5A)) * (D_80101A74_shared_board[playerNo][1] - sp20[1]))) + (D_80101A74_shared_board[playerNo][1] - sp20[1])));
            func_80055458_main(temp_s2->spriteGroup, 0, (256.0 - (i * 1.5)));
            HuSprScaleSet(temp_s2->spriteGroup, 0, (1.0f - (i / 200.0f)), (1.0f - (i / 200.0f)));
            HuPrcVSleep();
        }

        func_800F2CA4_shared_board(temp_s2);
        GwPlayer[playerNo].itemNo[MBItemFindEmpty(playerNo)] = temp_s6;
        MBStatusItemSprKill(playerNo);

        for (; var_f20 >= 1.0f; var_f20 -= 0.5) {
            HuVecCopyXYZ(&D_80105628_shared_board->scale, var_f20, var_f20, var_f20);
            HuPrcVSleep();
        }

        omDelObj(obj);
        MBModelKill(D_80105628_shared_board);
    }

    MBStatusShrink(-1);
    MBStatusItemDispSetAll(0);
    MBStatusGrow(-1);
}

// probably a file split here
static void func_800F7CF0_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C08);
}

static void func_800F7D10_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C09);
    func_800F74E4_shared_board();
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_TOAD, 0x3C0A);
}

// Toad gives all skeleton keys
static void func_800F7D4C_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C0B);
    D_80105630_shared_board[0] =
        D_80105630_shared_board[1] =
            D_80105630_shared_board[2] = ITEM_SKELETON_KEY;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_TOAD, 0x3C0A);
}

static void func_800F7D98_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C0C);
    func_800F7578_shared_board();
    func_800F76A4_shared_board(1);
    MBDlgWinExec(CHAR_TOAD, 0x3C0A);
}

static void func_800F7DD4_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C12);
    func_800F74E4_shared_board();
    D_80105638_shared_board = -1;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_TOAD, 0x3C0A);
}

static void func_800F7E1C_shared_board(void) {
    MBDlgWinExec(CHAR_TOAD, 0x3C13);
    D_80105630_shared_board[0] =
        D_80105630_shared_board[1] =
            D_80105630_shared_board[2] = ITEM_MUSHROOM;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_TOAD, 0x3C0A);
}

static void func_800F7E64_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1C);
    func_800F7610_shared_board();
    D_80105634_shared_board = -1;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1D);
}

static void func_800F7EAC_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1E);
    func_800F7610_shared_board();
    D_80105638_shared_board = -1;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1D);
}

static void func_800F7EF4_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1F);
    func_800F7610_shared_board();
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1D);
}

// Baby bowser gives all skeleton keys
static void func_800F7F30_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C20);
    D_80105630_shared_board[0] =
        D_80105630_shared_board[1] =
            D_80105630_shared_board[2] = ITEM_SKELETON_KEY;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1D);
}

// Baby bowser gives warp blocks from item space
static void func_800F7F7C_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C21);
    D_80105630_shared_board[0] =
        D_80105630_shared_board[1] =
            D_80105630_shared_board[2] = ITEM_WARP_BLOCK;
    func_800F76A4_shared_board(0);
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1D);
}

static void func_800F7FC8_shared_board(void) {
    MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C1B);
}

static void func_800F7FE8_shared_board(void) {
    GW_PLAYER *temp_s1;
    Object *temp_a0;
    f32 var_f12;
    omObjData *temp_v0;
    s16 var_a0;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_v0_2;
    void (*dispatch_func)();

    temp_s1 = MBPlayerGet(CUR_PLAYER);

    if (D_80105654_shared_board != 0) {
        D_80105620_shared_board = MBModelCreate(9, NULL);
        D_80105624_shared_board = MBModelFileCreate(0x1301C8, -1, 1.0f, 0, 0);
        D_80105658_shared_board = func_8000CED8_main(0xB0004, 0xAA9);
        HuAudFXPlay(0x119);
    } else {
        D_80105620_shared_board = MBModelCreate(0x39, NULL);
        D_80105624_shared_board = MBModelFileCreate(0x130203, -1, 1.0f, 0, 0);
        D_80105658_shared_board = func_8000CED8_main(0xB0005, 0xAA9);
        HuAudFXPlay(0x11A);
    }

    func_8001C8A8_main(D_80105658_shared_board, 1);
    func_8000CD00_main(D_80105658_shared_board, 1.0f, 20.0f, 1.0f);
    func_8000D018_main(D_80105658_shared_board, 15.0f);
    MBModelTempAllocFree(D_80105620_shared_board);
    D_80105620_shared_board->flags |= 1;
    MBModelTempAllocFree(D_80105624_shared_board);
    HuVecCopy3F(&D_80105620_shared_board->coords, &temp_s1->player_obj->coords);
    HuVecCopy3F(&D_80105624_shared_board->coords, &temp_s1->player_obj->coords);

    D_80105620_shared_board->velocity.x = 120.0f;
    D_80105624_shared_board->velocity.x = 120.0f;

    while (D_80105620_shared_board->velocity.x > 50.0f) {
        func_8000CFA4_main(D_80105658_shared_board, D_80105620_shared_board->coords.x, D_80105620_shared_board->velocity.x - 10.0f, D_80105620_shared_board->coords.z);
        HuPrcVSleep();
        D_80105620_shared_board->velocity.x -= 2.0f;
        D_80105624_shared_board->velocity.x -= 2.0f;
    }

    temp_v0 = omAddObj(0x1F4, 0, 0, -1, func_800F7130_shared_board);
    temp_v0->rot.x = 180.0f;
    var_s0 = 0;

    if (D_80105654_shared_board != 0) {
        HuAudFXPlay(0x298);
        MBDlgWinExec(CHAR_TOAD, 0x3C02);
        MBDlgWinCreate(CHAR_TOAD, D_80101B10_shared_board[MBRand(ARRAY_COUNT(D_80101B10_shared_board))]);
        if (temp_s1->stat & PLAYER_IS_CPU) {
            var_f12 = 3.0f;
            var_s0 = MBRand(var_f12) + 1;
        }
    } else {
        HuAudFXPlay(0x2A0);
        MBDlgWinExec(CHAR_BABY_BOWSER, 0x3C14);
        MBDlgWinCreate(CHAR_BABY_BOWSER, D_80101B24_shared_board[MBRand(ARRAY_COUNT(D_80101B24_shared_board))]);
        if (temp_s1->stat & PLAYER_IS_CPU) {
            var_f12 = 2.0f;
            var_s0 = MBRand(var_f12) + 1;
        }
    }

    temp_s0 = func_800F7240_shared_board(0, 1, var_s0, -1);
    MBDlgWinClose();
    MBDlgWinKill();
    temp_v1 = MBRand(10.0f);
    if (D_80105654_shared_board != 0) {
        switch (temp_s0) {
            case 0:
                if (temp_v1 < 4) {
                    var_a0_2 = 0;
                } else if (temp_v1 < 8) {
                    var_a0_2 = 1;
                } else {
                    var_a0_2 = 2;
                }
                break;

            case 1:
                if (temp_v1 < 2) {
                    var_a0_2 = 3;
                } else if (temp_v1 >= 8) {
                    var_a0_2 = 1;
                } else {
                    if (MBItemFindEmpty(MBPlayerTurnGet()) == 2) {
                        var_a0_2 = 1;
                    } else {
                        var_a0_2 = 4;
                    }
                }
                break;

            case 2:
            default:
                if (temp_v1 < 3) {
                    var_a0_2 = 3;
                } else if (temp_v1 < 7) {
                    var_a0_2 = 1;
                } else if (temp_v1 < 9) {
                    var_a0_2 = 5;
                } else {
                    var_a0_2 = 2;
                }
                break;
        }

        dispatch_func = D_80101AE0_shared_board[var_a0_2];
    } else {
        if (temp_s0 == 0) {
            if (temp_v1 < 2) {
                var_a0_2 = 0;
            } else if (temp_v1 < 6) {
                if (MBItemFindEmpty(MBPlayerTurnGet()) == 2) {
                    var_a0_2 = 2;
                } else {
                    var_a0_2 = 1;
                }
            } else if (temp_v1 < 8) {
                var_a0_2 = 2;
            } else if (temp_v1 < 9) {
                var_a0_2 = 3;
            } else {
                var_a0_2 = 4;
            }
        } else {
            if (temp_v1 < 2) {
                var_a0_2 = 5;
            } else if (temp_v1 < 6) {
                var_a0_2 = 2;
            } else if (temp_v1 < 8) {
                var_a0_2 = 3;
            } else {
                var_a0_2 = 4;
            }
        }

        dispatch_func = D_80101AF8_shared_board[var_a0_2];
    }

    dispatch_func();
    omDelObj(temp_v0);

    while (D_80105620_shared_board->velocity.x < 120.0f) {
        func_8000CFA4_main(D_80105658_shared_board, D_80105620_shared_board->coords.x, D_80105620_shared_board->velocity.x - 10.0f, D_80105620_shared_board->coords.z);
        HuPrcVSleep();
        D_80105620_shared_board->velocity.x += 4.0f;
        D_80105624_shared_board->velocity.x += 4.0f;
    }

    func_8000D044_main(D_80105658_shared_board);
    MBModelKill(D_80105620_shared_board);
    MBModelKill(D_80105624_shared_board);
}

void func_800F85C0_shared_board(void) {
    D_80105654_shared_board = 1;
    func_800F7FE8_shared_board();
}

void func_800F85E4_shared_board(void) {
    D_80105654_shared_board = 0;
    func_800F7FE8_shared_board();
}
