#include "common.h"
#include "game/board.h"
#include "1006F0.h"
#include "101840.h"
#include "105D50.h"
#include "F5E80.h"

extern s32 (*D_80102BC4_1167E4_shared_board)(void);
extern s32 D_80102BC0_1167E0_shared_board;
extern s16 D_80102BC2_1167E2_shared_board;
extern s16 D_80100D50_114970_shared_board[];

// main CPU decision logic function
s16 MBComTreeExec(DecisionTreeNonLeafNode *arg0) {
    char pad[38];
    DecisionTreeNonLeafNode *node = arg0;
    GW_PLAYER *player;
    s16 cmp;
    s16 clink;
    s16 cidxMin;
    s16 cidxMax;
    u32 idx;
    s32 turns;
    u32 limit;
    s32 pct;
    s32 i;

    for (;; node++) {
        switch (node->type) {
            case 1:
                if (MBPlayerCoinCheck(-1, node->node_data1.data) != 0) {
                    break;
                }
                continue;

            case 2:
                for (i = 0; i < 8; i++) {
                    if (!((1 << i) & node->node_data1.data)) {
                        continue;
                    }
                    if (GwSystem.current_board_index == 2) {
                        if ((GwSystem.boardData.halfWordBytes[2] >> GwSystem.current_player_index) & 1) {
                            if (GWBoardFlagCheck(0x12) == 0) {
                                if (i == GwSystem.boardData.halfWordBytes[0]) {
                                    break;
                                } else {
                                    continue;
                                }
                            }
                        }
                    }
                    if (!GWBoardFlagCheck(D_80100D50_114970_shared_board[i])) {
                        break;
                    }
                }
                if (i == 8) {
                    continue;
                }
                break;

            case 3:
                if ((1 << (mbWalkNum - 1)) & node->node_data1.data) {
                    break;
                }
                continue;

            case 4:
                idx = node->node_data1.data >> 0x14;
                cmp = node->node_data1.data_u16[1];
                idx &= 0xFF;
                switch ((node->node_data1.data >> 0x10) & 0xF) {
                    case 0:
                        if (GwSystem.boardData.halfWordBytes[idx] == cmp) {
                            break;
                        }
                        continue;
                    case 1:
                        if (GwSystem.boardData.halfWordBytes[idx] != cmp) {
                            break;
                        }
                        continue;
                    case 2:
                        if (GwSystem.boardData.halfWordBytes[idx] < cmp) {
                            break;
                        }
                        continue;
                    case 3:
                        if (GwSystem.boardData.halfWordBytes[idx] <= cmp) {
                            break;
                        }
                        continue;
                    case 4:
                        if (GwSystem.boardData.halfWordBytes[idx] > cmp) {
                            break;
                        }
                        continue;
                    case 5:
                        if (GwSystem.boardData.halfWordBytes[idx] >= cmp) {
                            break;
                        }
                        continue;
                }
                break;

            case 0:
                break;

            case 5:
                if ((1 << BoardPlayerRankCalc(MBPlayerTurnGet())) & node->node_data1.data) {
                    break;
                }
                continue;

            case 6:
                if (node->node_data1.func() != 0) {
                    break;
                }
                continue;

            case 7:
                turns = MBTurnRemain();
                limit = node->node_data1.signed_data;
                if ((limit > turns) == 0) {
                    break;
                }
                continue;

            case 8:
                if (MBItemFind(GwSystem.current_player_index, node->node_data1.data) != -1) {
                    break;
                }
                continue;

            case 9:
                limit = node->node_data1.signed_data;
                turns = mbWalkNum;
                if ((limit > turns) == 0) {
                    break;
                }
                continue;

            case 10:
                clink = node->node_data1.data_u8[1];
                cidxMin = node->node_data1.data_u8[2];
                cidxMax = node->node_data1.data_u8[3];
                player = MBPlayerGet(-1);
                if (player->clink != clink) {
                    continue;
                }
                if (player->cidx >= cidxMin && player->cidx <= cidxMax) {
                    break;
                }
                continue;

            case 11:
                clink = node->node_data1.data_u8[1];
                cidxMin = node->node_data1.data_u8[2];
                cidxMax = node->node_data1.data_u8[3];
                for (i = 0; i < 4; i++) {
                    if (i == MBPlayerTurnGet()) {
                        continue;
                    }
                    player = MBPlayerGet(i);
                    if (player->clink != clink) {
                        continue;
                    }
                    if (player->cidx >= cidxMin && player->cidx <= cidxMax) {
                        break;
                    }
                }
                if (i >= 4) {
                    continue;
                }
                /* fallthrough */
            case 12:
                if (MBPlayerCoinCheck(-1, node->node_data1.data) == 0) {
                    break;
                }
                continue;

            case 13:
                if ((GwPlayer[MBPlayerTurnGet()].chr != node->node_data1.data) == 0) {
                    break;
                }
                continue;

            case 14:
                clink = node->node_data1.data_u8[1];
                cidxMin = node->node_data1.data_u8[2];
                cidxMax = node->node_data1.data_u8[3];
                player = MBPlayerGet(node->node_data1.data_u8[0]);
                if (player->clink != clink) {
                    continue;
                }
                if (player->cidx >= cidxMin && player->cidx <= cidxMax) {
                    break;
                }
                continue;

            case 15:
                clink = node->node_data1.data_u8[1];
                cidxMin = node->node_data1.data_u8[2];
                cidxMax = node->node_data1.data_u8[3];
                player = MBPlayerGet(D_80102BC2_1167E2_shared_board);
                if (player->clink != clink) {
                    continue;
                }
                if (player->cidx >= cidxMin && player->cidx <= cidxMax) {
                    break;
                }
                continue;

            case 16:
                for (i = 0; i < 4; i++) {
                    if (MBPlayerTurnGet() == i) {
                        continue;
                    }
                    if (MBPlayerCoinCheck(i, node->node_data1.data) != 0) {
                        i++;
                        goto next_node;
                    }
                }
                continue;
        }

        if ((s32)node->node_data2.node_data < 0) {
            node = node->node_data2.node_data - 1;
            continue;
        }

        switch (MBPlayerGet(-1)->cpu_difficulty) {
            case 0:
                pct = node->node_data2.data_u8[3] & 0x7F;
                break;
            case 1:
                pct = (node->node_data2.data >> 7) & 0x7F;
                break;
            case 2:
                pct = (node->node_data2.data >> 0xE) & 0x7F;
                break;
            case 3:
                pct = (node->node_data2.data >> 0x15) & 0x7F;
                break;
            default:
                pct = 0;
                break;
        }

        if (MBRandCheck100(pct) != 0) {
            cmp = (node->node_data2.data >> 0x1C) & 1;
        } else {
            cmp = ((node->node_data2.data >> 0x1C) ^ 1) & 1;
        }
        return cmp;
    next_node:;
    }
}

void MBComItemDecideHookSet(s32 (*arg0)(void)) {
    D_80102BC4_1167E4_shared_board = arg0;
}

s32 MBComItemDecide(void) {
    return D_80102BC4_1167E4_shared_board();
}

void func_800DA778_EE398_shared_board(s32 arg0) {
    D_80102BC0_1167E0_shared_board = arg0;
}
