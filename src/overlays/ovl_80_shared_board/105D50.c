#include "common.h"
#include "ovl_80.h"

u8 D_80101630_115250_shared_board[] = {0, 1, 2, 3};

u32 D_80101634_115254_shared_board[] = {
    7,
    0x00020001,
    0x00020002,
    0x00020004,
    0x00020036,
    0x00020015,
    0x00020032,
    0x00020035, 
};

u32 D_80101654_115274_shared_board[] = {
    7,
    0x00030001,
    0x00030002,
    0x00030004,
    0x00030036,
    0x00030015,
    0x00030032,
    0x00030035
};

u32 D_80101674_115294_shared_board[] = {
    7,
    0x00070001,
    0x00070002,
    0x00070004,
    0x00070036,
    0x00070015,
    0x00070032,
    0x00070035,
};

u32 D_80101694_1152B4_shared_board[] = {
    7,
    0x00040001,
    0x00040002,
    0x00040004,
    0x00040036,
    0x00040015,
    0x00040032,
    0x00040035,
};

u32 D_801016B4_1152D4_shared_board[] = {
    7,
    0x00050001,
    0x00050002,
    0x00050004,
    0x00050036,
    0x00050015,
    0x00050032,
    0x00050035,
};

u32 D_801016D4_1152F4_shared_board[] = {
    7,
    0x00060001,
    0x00060002,
    0x00060004,
    0x00060036,
    0x00060015,
    0x00060032,
    0x00060035,
};

u32 D_801016F4_115314_shared_board[] = {
    7,
    0x00020001,
    0x00020002,
    0x00020004,
    0x00020036,
    0x00020015,
    0x00020032,
    0x00020035,
};

u32 D_80101714_115334_shared_board[] = {
    7,
    0x00070001,
    0x00070002,
    0x00070004,
    0x00070036,
    0x00070015,
    0x00070032,
    0x00070035,
};

u32* D_80101734_115354_shared_board[] = {
    D_80101634_115254_shared_board,
    D_80101654_115274_shared_board,
    D_80101674_115294_shared_board,
    D_80101694_1152B4_shared_board,
    D_801016B4_1152D4_shared_board,
    D_801016D4_1152F4_shared_board,
    D_801016F4_115314_shared_board,
    D_80101714_115334_shared_board
};

u8 D_80101754_115374_shared_board[] = {
    0, 1, 2, 3, 4, 5, 6, 7
};

u8 D_8010175C_11537C_shared_board[] = {
    14, 15, 16, 17, 18, 19, 20, 21
};

s16 GetCurrentPlayerIndex(void) {
    return GwSystem.current_player_index;
}

GW_PLAYER* MBGetPlayerStruct(s32 playerIndex) {
    if (playerIndex < 0) {
        playerIndex = GetCurrentPlayerIndex();
    }
    return &GwPlayer[playerIndex];
}


s32 func_800F217C_105D9C_shared_board(s16 playerIndex) {
    if (playerIndex == GwSystem.current_player_index) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 func_800F2198_105DB8_shared_board(s16 playerIndex) {
    return MBGetPlayerStruct(playerIndex)->stat & PLAYER_IS_CPU;
}

void AdjustPlayerCoins(s32 playerIndex, s32 amount) {
    GW_PLAYER* player;

    player = MBGetPlayerStruct(playerIndex);
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

s32 PlayerHasCoins(s32 playerIndex, s32 requiredCoins) {
    if (MBGetPlayerStruct(playerIndex)->coin >= requiredCoins) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void func_800F2260_105E80_shared_board(s32 playerIndex, f32 arg1) {
    GW_PLAYER* player = MBGetPlayerStruct(playerIndex);

    if (player->itemTurn != 0) {
        func_8001C92C_1D52C(D_801011FC_114E1C_shared_board->omObj1->model[0], arg1);
    } else {
        func_8001C92C_1D52C(player->player_obj->omObj1->model[0], arg1);
    }
}

void func_800F22C0_105EE0_shared_board(s32 playerNo) {
    GW_PLAYER* player;

    player = MBGetPlayerStruct(playerNo);
    if (player->itemTurn != 0) {
        func_800EE97C_10259C_shared_board(D_801011FC_114E1C_shared_board);
    } else {
        func_800EE97C_10259C_shared_board(player->player_obj);
    }
}

void func_800F2304_105F24_shared_board(s32 playerIndex, s16 arg1, u16 arg2) {
    GW_PLAYER* player;

    player = MBGetPlayerStruct(playerIndex);
    if (player == MBGetPlayerStruct(CUR_PLAYER)) {
        MBMotionSet(player->player_obj, arg1, arg2);
        if ((player->itemTurn != 0) & (arg1 < 7)) {
            func_800E6420_FA040_shared_board(arg1, arg2);
        }
    }
}

void func_800F2388_105FA8_shared_board(s32 playerIndex, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    GW_PLAYER* player;

    player = MBGetPlayerStruct(playerIndex);
    if (player == MBGetPlayerStruct(CUR_PLAYER)) {
        MBMotionShiftSet(player->player_obj, arg1, arg2, arg3, arg4);
        if ((player->itemTurn != 0) & (arg1 < 7)) {
            func_800E644C_FA06C_shared_board(arg1, arg2, arg3, arg4);
        }
    }
}

void func_800F244C_10606C_shared_board(s32 arg0, u8 arg1) {
    MBGetPlayerStruct(arg0)->cpu_difficulty = D_80101630_115250_shared_board[arg1];
}

void func_800F2484_1060A4_shared_board(void) {
}

void func_800F248C_1060AC_shared_board(void) {
    GW_PLAYER* curPlayer = HuPrcCurrentGet()->user_data;
    
    while (1) {
        HuPrcVSleep();
        if (curPlayer->stat & 4) {
            continue;
        }
        HuVecCopyXYZ(&curPlayer->player_obj->scale, 1.0f, 1.0f, 1.0f);
    }
}

//create player sprite
void func_800F24FC_10611C_shared_board(s16 playerNo, u32* arg1, s32 arg2) {
    GW_PLAYER* player;
    Process* proc;
    u8 chr;
    
    
    player = MBGetPlayerStruct(playerNo);
    player->turn = playerNo;
    chr = player->chr;
    
    switch (arg2) {
        case 0:
            player->player_obj = MBModelCreate(D_80101754_115374_shared_board[chr], arg1);
            break;
        case 1:
        case 2:
            player->player_obj = MBModelCreate(D_8010175C_11537C_shared_board[chr], arg1);
            break;
    }
    
    proc = omAddPrcObj(func_800F248C_1060AC_shared_board, 0x5000, 0, 0);
    player->unk_20 = proc;
    proc->user_data = player;
}

void func_800F25B4_1061D4_shared_board(s16 arg0, u32* arg1) {
    func_800F24FC_10611C_shared_board(arg0, arg1, 0);
}

void func_800F25D8_1061F8_shared_board(s16 playerNo) {
    GW_PLAYER* player = MBGetPlayerStruct(playerNo);
    
    func_800F24FC_10611C_shared_board(playerNo, D_80101734_115354_shared_board[player->chr], 0);
}

void func_800F2624_106244_shared_board(s16 playerNo) {
    GW_PLAYER* player = MBGetPlayerStruct(playerNo); //remnants of a debug build or the below function was changed to take a playerNo
    
    func_800F24FC_10611C_shared_board(playerNo, 0, 0);
}

u8 func_800F2660_106280_shared_board(s16 playerNo) {
    return D_8010175C_11537C_shared_board[MBGetPlayerStruct(playerNo)->chr];
}

void func_800F2690_1062B0_shared_board(s16 playerNo) {
    GW_PLAYER* player = MBGetPlayerStruct(playerNo);

    if (player->player_obj != NULL) {
        if (player->unk_20 != NULL) {
            omDelPrcObj(player->unk_20);
        }
        MBModelKill(player->player_obj);
        player->player_obj = NULL;
    }
}

void func_800F26E8_106308_shared_board(void) {
    s32 i, j;

    for (j = 0; j < ARRAY_COUNT(GwPlayer); j++) { //clear all 5 "players" (bowser bomb remnants)
        MBGetPlayerStruct(j)->player_obj = NULL;
    }

    for (i = 1; i < 8; i++) {
        for (j = 0; j < D_80101634_115254_shared_board[0]; j++) {
            D_80101734_115354_shared_board[i][j+1] = func_80017BB8_187B8(i, D_80101634_115254_shared_board[j+1]);
        }
    }
}

void func_800F27C4_1063E4_shared_board(void) {
    
}