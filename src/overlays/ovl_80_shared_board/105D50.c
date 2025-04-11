#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", GetCurrentPlayerIndex);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", GetPlayerStruct);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F217C_105D9C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2198_105DB8_shared_board);

void AdjustPlayerCoins(s32 arg0, s32 arg1) {
    GW_PLAYER* player;

    player = GetPlayerStruct(arg0);
    player->coin = player->coin + arg1;
    if (player->coin >= 1000) {
        player->coin = 999;
    }
    if (player->coin < 0) {
        player->coin = 0;
    }
    if (player->coinPrize <= player->coin) {
        player->coinPrize = player->coin;
    }
}

s32 PlayerHasCoins(s32 playerIndex, s32 requiredCoins) {
    return GetPlayerStruct(playerIndex)->coin >= requiredCoins;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2260_105E80_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F22C0_105EE0_shared_board);

void func_800F2304_105F24_shared_board(s32 playerIndex, s16 arg1, u16 arg2) {
    GW_PLAYER* player;

    player = GetPlayerStruct(playerIndex);
    if (player == GetPlayerStruct(CUR_PLAYER)) {
        func_800D9CE8_ED908_shared_board(player->player_obj, arg1, arg2);
        if ((player->itemTurn != 0) & (arg1 < 7)) {
            func_800E6420_FA040_shared_board(arg1, arg2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2388_105FA8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F244C_10606C_shared_board);

void func_800F2484_1060A4_shared_board(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F248C_1060AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F24FC_10611C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F25B4_1061D4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F25D8_1061F8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2624_106244_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2660_106280_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F2690_1062B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F26E8_106308_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/105D50", func_800F27C4_1063E4_shared_board);
