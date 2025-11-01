#include "common.h"
#include "ovl_80.h"

s16 MBPlayerTurnGet(void) {
    return GwSystem.current_player_index;
}

GW_PLAYER* MBPlayerGet(s32 playerIndex) {
    if (playerIndex < 0) {
        playerIndex = MBPlayerTurnGet();
    }
    return &GwPlayer[playerIndex];
}


s32 MBPlayerCurrentCheck(s16 playerIndex) {
    if (playerIndex == GwSystem.current_player_index) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 MBPlayerComCheck(s16 playerIndex) {
    return MBPlayerGet(playerIndex)->stat & PLAYER_IS_CPU;
}

void MBPlayerCoinAdd(s32 playerIndex, s32 amount) {
    GW_PLAYER* player;

    player = MBPlayerGet(playerIndex);
    player->coin = player->coin + amount;
    if (player->coin > 999) {
        player->coin = 999;
    }
    if (player->coin < 0) {
        player->coin = 0;
    }
    if (player->coinPrize <= player->coin) {
        player->coinPrize = player->coin;
    }
}

s32 MBPlayerCoinCheck(s32 playerIndex, s32 requiredCoins) {
    if (MBPlayerGet(playerIndex)->coin >= requiredCoins) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void MBPlayerSpeedSet(s32 playerIndex, f32 arg1) {
    GW_PLAYER* player = MBPlayerGet(playerIndex);

    if (player->itemTurn != 0) {
        func_8001C92C_1D52C(D_801011FC_114E1C_shared_board->omObj1->model[0], arg1);
    } else {
        func_8001C92C_1D52C(player->player_obj->omObj1->model[0], arg1);
    }
}

void MBPlayerMotionWait(s32 playerNo) {
    GW_PLAYER* player;

    player = MBPlayerGet(playerNo);
    if (player->itemTurn != 0) {
        MBModelMotionWait(D_801011FC_114E1C_shared_board);
    } else {
        MBModelMotionWait(player->player_obj);
    }
}

void MBPlayerMotionSet(s32 playerIndex, s16 arg1, u16 arg2) {
    GW_PLAYER* player;

    player = MBPlayerGet(playerIndex);
    if (player == MBPlayerGet(CUR_PLAYER)) {
        MBMotionSet(player->player_obj, arg1, arg2);
        if ((player->itemTurn != 0) & (arg1 < 7)) {
            MBKSuitMotionSet(arg1, arg2);
        }
    }
}

void func_800F2388_105FA8_shared_board(s32 playerIndex, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    GW_PLAYER* player;

    player = MBPlayerGet(playerIndex);
    if (player == MBPlayerGet(CUR_PLAYER)) {
        MBMotionShiftSet(player->player_obj, arg1, arg2, arg3, arg4);
        if ((player->itemTurn != 0) & (arg1 < 7)) {
            MBKSuitMotionShiftSet(arg1, arg2, arg3, arg4);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F244C_10606C_shared_board);

void func_800F2484_1060A4_shared_board(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F248C_1060AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", MBPlayerModelCreate); //create player sprite

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F25B4_1061D4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F25D8_1061F8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2624_106244_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2660_106280_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2690_1062B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F26E8_106308_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F27C4_1063E4_shared_board);
