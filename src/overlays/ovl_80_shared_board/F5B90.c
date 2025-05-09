#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E1F70_F5B90_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2074_F5C94_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E20A4_F5CC4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E210C_F5D2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E21F4_F5E14_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2260_F5E80_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E22B4_F5ED4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E22CC_F5EEC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E22DC_F5EFC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2354_F5F74_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2390_F5FB0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2904_F6524_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2954_F6574_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2960_F6580_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2974_F6594_shared_board);

s32 func_800E29E8_F6608_shared_board(void) {
    GW_PLAYER* player;
    GW_SYSTEM* system = &GwSystem;

    player = GetPlayerStruct(CUR_PLAYER);
    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3 && player->rev & 0x80) {
        player->rev &= ~0x80;
        func_800EC590_1001B0_shared_board(-1, 0x3A2B);
    } else {
        if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
            func_800EC590_1001B0_shared_board(-1, 0x3A27);
        }
        if (player->rev & 0x80) {
            player->rev &= ~0x80;
            func_800EC590_1001B0_shared_board(-1, 0x3A29);
        }        
    }

    func_800DCA64_F0684_shared_board(GwSystem.current_player_index);
    D_80102C70_116890_shared_board();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = -1;
    FixUpPlayerItemSlots(GwSystem.current_player_index);
    func_800DE9AC_F25CC_shared_board(GwSystem.current_player_index, 2);
    func_800FF900_113520_shared_board(CUR_PLAYER, 2);
    func_800DC128_EFD48_shared_board(GwSystem.current_player_index);
    HuPrcSleep(0xF);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2B24_F6744_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2B4C_F676C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2BCC_F67EC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2C4C_F686C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2C74_F6894_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2C9C_F68BC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2CC4_F68E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2CEC_F690C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2E28_F6A48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E2F38_F6B58_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3074_F6C94_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3158_F6D78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E31E4_F6E04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3284_F6EA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3394_F6FB4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3420_F7040_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3448_F7068_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3470_F7090_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3498_F70B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E34BC_F70DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E34E0_F7100_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3584_F71A4_shared_board);

f32 HuMathSin(f32);
void func_800F696C_10A58C_shared_board(s32, s32, f32, f32);

void func_800E35F8_F7218_shared_board(void) {
    f32 temp_f0;
    f32 var_f20;
    s32* temp_s0;
    s32 prev;

    temp_s0 = HuPrcCurrentGet()->user_data;
    var_f20 = 0.0f;
    prev = *temp_s0;
    while (*temp_s0 != -1) {
        if (*temp_s0 != prev) {
            func_800F696C_10A58C_shared_board(GwSystem.current_player_index, prev, 1.0f, 1.0f);
            var_f20 = 0.0f;
            prev = *temp_s0;
        }
        if (var_f20 > 360.0f) {
            var_f20 -= 360.0f;
        }
        temp_f0 = (HuMathSin(var_f20) * 0.2f) + 1.0f;
        func_800F696C_10A58C_shared_board(GwSystem.current_player_index, *temp_s0, temp_f0, temp_f0);
        HuPrcVSleep();
        var_f20 += 13.0f;
        
    }
    func_800F696C_10A58C_shared_board(GwSystem.current_player_index, prev, 1.0f, 1.0f);
    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3734_F7354_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E378C_F73AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E3F54_F7B74_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E400C_F7C2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4160_F7D80_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E41FC_F7E1C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E44E4_F8104_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102180_115DA0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102188_115DA8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102194_115DB4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021A4_115DC4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021AC_115DCC_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021B8_115DD8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021C4_115DE4_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021D0_115DF0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021DC_115DFC_shared_board);

void func_800E455C_F817C_shared_board(void) {
    s8 sp20[4];
    Vec sp28;
    char sp38[16];
    s32 sp4C;
    GW_PLAYER* curPlayer;
    s16 absSpace;
    s32 temp_s0_2;
    s32 coinsToLose;
    s32 totalCoinsToLose;
    s32 playerPassed;
    s32 curPlayerIndex;
    s32 i;


    curPlayerIndex = GwSystem.current_player_index;
    curPlayer = GetPlayerStruct(CUR_PLAYER);
    if (GwPlayer[curPlayerIndex].itemTurn != 0) {
        for (playerPassed = 0, i = 0; i < MAX_PLAYERS; i++) {
            if (i == curPlayerIndex) {
                continue;
            }
            absSpace = func_800EB184_FEDA4_shared_board(GwPlayer[curPlayerIndex].clink, GwPlayer[curPlayerIndex].cidx);
            if (absSpace == func_800EB184_FEDA4_shared_board(GwPlayer[i].clink, GwPlayer[i].cidx)) {
                sp20[playerPassed++] = i;
            }
        }
        if (playerPassed != 0) {
            sp4C = func_800DBEC0_EFAE0_shared_board(curPlayerIndex);
            func_800E6420_FA040_shared_board(-1, 2);
            func_800ECC0C_10082C_shared_board(&sp28);
            func_800ED128_100D48_shared_board(&curPlayer->player_obj->unk18, &sp28, &curPlayer->player_obj->unk18, 8);
            HuPrcSleep(8);
            totalCoinsToLose = 0;

            for (i = 0; i < playerPassed; i++) {
                if (GwPlayer[sp20[i]].coin != 0) {
                    if (GwPlayer[sp20[i]].coin < 20) {
                        coinsToLose = GwPlayer[sp20[i]].coin;
                    } else {
                        coinsToLose = 20;
                    }
                    sprintf(sp38, "%2d", coinsToLose);
                    ShowMessage(-1, 0x3A15, D_801014A0_1150C0_shared_board[GwPlayer[sp20[i]].chr], (s32)sp38, D_801014A0_1150C0_shared_board[GwPlayer[curPlayerIndex].chr], 0, 0);
                    temp_s0_2 = -coinsToLose;
                    func_800EC6C8_1002E8_shared_board();
                    totalCoinsToLose += coinsToLose;
                    func_800EC6EC_10030C_shared_board();
                    func_8004ACE0_4B8E0(0, sp20[i]);
                    func_800E1F28_F5B48_shared_board(sp20[i], temp_s0_2);
                    func_800F5D44_109964_shared_board(sp20[i], temp_s0_2);
                    HuPrcSleep(30);
                } else {
                    ShowMessage(-1, 0x3A16, D_801014A0_1150C0_shared_board[GwPlayer[sp20[i]].chr], NULL, 0, 0, 0);
                    func_800EC6C8_1002E8_shared_board();
                    func_800EC6EC_10030C_shared_board();
                    do {} while(0); //TODO: required to match
                }
            }
            
            if (totalCoinsToLose != 0) {
                ShowPlayerCoinChange(curPlayerIndex, totalCoinsToLose);
                func_800F5D44_109964_shared_board(curPlayerIndex, totalCoinsToLose);
                HuPrcSleep(30);
            }
            if (sp4C != 0) {
                func_800DB884_EF4A4_shared_board(GwSystem.current_player_index);
            }
            func_800E6420_FA040_shared_board(0, 2);
        }
    }
    
    if (D_800D41B0_D4DB0[4] == 0) {
        func_800E48F4_F8514_shared_board();
    }
}

void func_800E48F4_F8514_shared_board(void) {
    s32 curPlayerIndex = GwSystem.current_player_index;
    if (GwPlayer[curPlayerIndex].itemTurn != 0) {
        D_80102C58_116878_shared_board[5]();
        GwPlayer[curPlayerIndex].itemTurn = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4954_F8574_shared_board);

s32 PlayerHasItem(s32 playerIndex, s32 itemID) {
    s32 i;

    if (playerIndex == CUR_PLAYER) {
        playerIndex = GwSystem.current_player_index;
    }

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo); i++) {
        if (GwPlayer[playerIndex].itemNo[i] == itemID) {
            break;
        }
    }

    if (i == 3) {
        return -1;
    } else {
        return i;
    }
}

s32 PlayerHasEmptyItemSlot(s32 arg0) {
    if (arg0 == CUR_PLAYER) {
        arg0 = GwSystem.current_player_index;
    }
    
    return PlayerHasItem(arg0, -1);
}

void FixUpPlayerItemSlots(s32 arg0) {
    s8* playerItems;
    s32 i;


    if (arg0 == -1) {
        arg0 = GwSystem.current_player_index;
    }

    playerItems = GwPlayer[arg0].itemNo;

    for (i = 0; i < ARRAY_COUNT(GwPlayer->itemNo) - 1; i++) {
        if (playerItems[i] == -1) {
            playerItems[i] = playerItems[i+1];
            playerItems[i+1] = -1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4A6C_F868C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4A7C_F869C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4A88_F86A8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4A94_F86B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4B18_F8738_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4B60_F8780_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4BA0_F87C0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4C68_F8888_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E4DC0_F89E0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5100_F8D20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E53A4_F8FC4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5604_F9224_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E57C8_F93E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E57D8_F93F8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5840_F9460_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5B80_F97A0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5B90_F97B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5BE4_F9804_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5CE0_F9900_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5D40_F9960_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5DA8_F99C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E5DD4_F99F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E60D8_F9CF8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6120_F9D40_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E61C0_F9DE0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021EC_115E0C_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801021F0_115E10_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102200_115E20_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102210_115E30_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102220_115E40_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102230_115E50_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102240_115E60_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102250_115E70_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_8010225C_115E7C_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_8010226C_115E8C_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102280_115EA0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_80102290_115EB0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801022A0_115EC0_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801022B8_115ED8_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", D_801022CC_115EEC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6264_F9E84_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E639C_F9FBC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E63F0_FA010_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6404_FA024_shared_board);

void func_800E6420_FA040_shared_board(s16 arg0, s32 arg1) {
    func_800D9CE8_ED908_shared_board(D_801011FC_114E1C_shared_board, arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E644C_FA06C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E648C_FA0AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6500_FA120_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E650C_FA12C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6538_FA158_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6564_FA184_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6630_FA250_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E66D4_FA2F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E66E0_FA300_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6720_FA340_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E69BC_FA5DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E69D8_FA5F8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6A40_FA660_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6A54_FA674_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6A8C_FA6AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6AC4_FA6E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6C4C_FA86C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6C80_FA8A0_shared_board);

#define SlideReadUint(buffer, src) \
    do { \
        (buffer) = ((*src++) << 24); \
        (buffer) += ((*src++) << 16); \
        (buffer) += ((*src++) << 8);  \
        (buffer) += (*src++);         \
    } while (0)

void func_800E6CF8_FA918_shared_board(u8* input, u8* output, s32 compressedSize) {
    u8* src = input + 4;       // Skip metadata
    s32 flagLen = 0;         // Remaining bits in the bit buffer
    s32 flag = 0;             // Buffer holding bits for control decisions
    s32 size = compressedSize; // Bytes left to decompress
    u8* matchPtr;                  // Pointer for back-reference matches
    u32 offset, len;       // Offset and length for back-references
    u32 dist;                 // Temporary value for reading data

    while (size != 0) {
        // Refill the bit buffer if empty
        if (flagLen == 0) {
            SlideReadUint(flag, src);
            flagLen = 32;
        }

        // Determine if the next data is a literal or back-reference
        if (flag >> 31) {
            *output++ = *src++; // Write literal byte
            size--;
        } else {
            // Read the next 16 bits for the back-reference
            dist = (*src++ << 8);
            dist += (*src++);
            len = (dist >> 12) & 0xF;
            dist &= 0xFFF;
            // Calculate the pointer for the back-reference match
            matchPtr = output - dist;

            // Handle extended match lengths
            if (len == 0) {
                len = (*src++) + 0x12;
            } else {
                len += 2;
            }

            size -= len;
            if (size < 0) {
                break; // Prevent buffer overflow
            }

            // Copy the match data from the back-reference
            while (len > 0) {
                *output++ = matchPtr[-1];
                matchPtr++;
                len--;
            }
        }

        // Shift the bit buffer and decrement remaining bits
        flag <<= 1;
        flagLen--;

        // Exit if all bytes have been decompressed
        if (size == 0) {
            break;
        }
    }
}

//decodes HVQ board image tile?
void func_800E6DEC_FAA0C_shared_board(void) {
    HvqUnk* sp10;
    HvqHeader* temp_a0;

    func_8006A370_6AF70(0xFF);
    func_80069E68_6AA68(D_80103138_116D58_shared_board); //"HVQ-MPS 1.1"
    while (1) {
        osRecvMesg(&D_80104880_1184A0_shared_board, (void*)&sp10, 1);
        if (sp10 != NULL) {
            temp_a0 = sp10->unk8;
            D_80102DD0_1169F0_shared_board = sp10->unk8;
            if (temp_a0->magic == 0x48565153) { //"HVQS"
            //is HVQS, decode it
                func_800698E8_6A4E8(&temp_a0->unk4, sp10->unk4, 0x40, D_80102DCC_1169EC_shared_board);
            } else {
                //0x1800 size for decoded tile
                func_800E6CF8_FA918_shared_board((u8*)&D_80102DD0_1169F0_shared_board->unk4, sp10->unk4, 0x1800);
            }
            osSendMesg(&D_80104928_118548_shared_board, sp10, 0);
        } else {
            break;
        }
    }

    osSendMesg(&D_801049D0_1185F0_shared_board, (void* )2, 0);
    osDestroyThread(NULL);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6EC8_FAAE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6FBC_FABDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6FCC_FABEC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E6FDC_FABFC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7018_FAC38_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7068_FAC88_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7130_FAD50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E71A8_FADC8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E71EC_FAE0C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7254_FAE74_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E728C_FAEAC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E72C4_FAEE4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E72DC_FAEFC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7300_FAF20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7330_FAF50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7358_FAF78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7384_FAFA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E7514_FB134_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E76EC_FB30C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E86CC_FC2EC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E8DC8_FC9E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E8DD4_FC9F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E8DE0_FCA00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E8EDC_FCAFC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E8F54_FCB74_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9044_FCC64_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E90BC_FCCDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E92D4_FCEF4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9328_FCF48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9344_FCF64_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9358_FCF78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9730_FD350_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E973C_FD35C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9748_FD368_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E982C_FD44C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E989C_FD4BC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E98E8_FD508_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9940_FD560_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9A54_FD674_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9A60_FD680_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9A94_FD6B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9AC8_FD6E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9AD4_FD6F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9AE0_FD700_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9AF0_FD710_shared_board);

void func_800E9BB0_FD7D0_shared_board(void) {
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9BD0_FD7F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9C00_FD820_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9C28_FD848_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9C94_FD8B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9EF4_FDB14_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800E9F24_FDB44_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA0B8_FDCD8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA200_FDE20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA284_FDEA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA2BC_FDEDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA2D0_FDEF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA2E4_FDF04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA320_FDF40_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA348_FDF68_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA358_FDF78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA364_FDF84_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA4CC_FE0EC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA4F0_FE110_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA5A4_FE1C4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA60C_FE22C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA660_FE280_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA694_FE2B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA6B0_FE2D0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EA6E0_FE300_shared_board);

void func_80012640_13240(s32, Gfx**);
void func_800127C4_133C4(s32, Gfx**);
void func_80017C10_18810(Mtx*, f32, f32, f32);
void func_80017CD0_188D0(Mtx*, f32, f32, f32);
void func_800185A4_191A4(Mtx*, f32);
u16 func_8004D6AC_4E2AC(s32, s32, s32);
void func_8004D6E8_4E2E8(s16);
void func_800898F0_8A4F0(Mtx*, Mtx*);
void func_80089980_8A580(Mtx*, Mtx*);
void func_800E989C_FD4BC_shared_board(void*);
extern Addr D_101358;
extern Addr D_101398;
extern s16 D_800CCF28_CDB28;
extern Mtx* D_800D1F68_D2B68;
extern u16 D_80105210_118E30_shared_board;
extern s16 D_80105260_118E80_shared_board;
extern u16 D_80105262_118E82_shared_board;
extern u8 D_80101308_114F28_shared_board[]; //u8 array that links space type to render type
extern Gfx D_801013D8_114FF8_shared_board[];
extern u8* D_80105220_118E40_shared_board[]; //space form images
extern f32 D_80105290_118EB0_shared_board[];
extern s32 D_801052B0_118ED0_shared_board;
extern u8 (*D_801012C4_114EE4_shared_board)[SPACES_MAX];

void DrawSpaces(Gfx** arg0, Mtx* arg1, s32 arg2) {
    Gfx** gfxPos = arg0;
    Mtx sp10;
    char sp50[4]; //unknown type and size
    Mtx* sp5C;
    u8* sp64;
    u8* sp6C;
    s32 sp74;
    u16 sp7E;
    s32 sp84;
    s32 sp94;
    SpaceData* temp_s0;
    s16 var_v0;
    Mtx* temp_s0_3;
    s32 i, j;
    s32 var_s5;
    u32 temp_s4;

    sp5C = arg1;
    var_s5 = 0;
    if (!(arg2 & 0xFF) && (D_80105262_118E82_shared_board != 0) && (D_801012C4_114EE4_shared_board != 0)) {
        sp7E = func_8004D6AC_4E2AC(0xC8, 0xC8, 0xC8);
        gSPDisplayList((*gfxPos)++, D_801013D8_114FF8_shared_board);
        func_80012640_13240(0, gfxPos);
        func_800127C4_133C4(0, gfxPos);
        func_800E989C_FD4BC_shared_board(&sp50);
        
        if ((D_80105260_118E80_shared_board == 0) || (var_v0 = 8, (D_80105260_118E80_shared_board != 1))) {
            var_v0 = 0x10;
            sp64 = D_101358;
            sp6C = D_80101308_114F28_shared_board;
            sp74 = 0;
        } else {
            var_v0 = 8;
            sp64 = D_101398;
            sp6C = NULL;
            sp74 = 1;
        }
        //iterate over all space types
        for (i = 0; i < 16; i++) {
            if (D_80105220_118E40_shared_board[i] != 0) {
                if (sp74 == 0) {
                    switch (sp6C[i]) {
                    case 0:
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    case 1:
                        // + 0x10 to skip image header data
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    case 2:
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    }
                } else {
                    gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            var_v0, var_v0, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                }
                //read over a space types space array
                for (j = 0; j < D_80105210_118E30_shared_board; j++) {
                    s32 spaceId = D_801012C4_114EE4_shared_board[i][j];
                    if (spaceId == 0xff) {
                        break;
                    }
                    temp_s0 = GetSpaceData(spaceId);
                    func_80089980_8A580(&sp10, &sp5C[1]);
                    func_80017C10_18810(&sp10, temp_s0->coords.x, temp_s0->coords.y, temp_s0->coords.z);
                    if ((i == 0xD) && (var_s5 < D_801052B0_118ED0_shared_board)) {
                        func_800185A4_191A4(&sp10, D_80105290_118EB0_shared_board[var_s5++]);
                    }
                    func_80017CD0_188D0(&sp10, temp_s0->rot.x, 1.0f, temp_s0->rot.z);
                    temp_s0_3 = &D_800D1F68_D2B68[D_800CCF28_CDB28++];
                    func_800898F0_8A4F0(&sp10, temp_s0_3);
                    gSPMatrix((*gfxPos)++, OS_K0_TO_PHYSICAL(temp_s0_3), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPVertex((*gfxPos)++, sp64, 4, 0);
                    gSP1Quadrangle((*gfxPos)++, 0, 1, 2, 3, 0);
                }
            }            
        }

        func_8004D6E8_4E2E8(sp7E);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EAE00_FEA20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EAE10_FEA30_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB09C_FECBC_shared_board);

SpaceData* GetSpaceData(s16 arg0) {
    return &D_80105214_118E34_shared_board[arg0];
}

s16 func_800EB184_FEDA4_shared_board(u16 arg0, u16 arg1) {
    return D_80105218_118E38_shared_board[arg0].spaces[arg1];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB1B0_FEDD0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB1CC_FEDEC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB24C_FEE6C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB310_FEF30_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB3C0_FEFE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB4F0_FF110_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB5DC_FF1FC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", SetSpaceType);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB820_FF440_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB8BC_FF4DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB97C_FF59C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EB9C0_FF5E0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBA60_FF680_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBAC8_FF6E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBCB0_FF8D0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBCBC_FF8DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBCC8_FF8E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBCD4_FF8F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBCFC_FF91C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBD54_FF974_shared_board);

void func_800EBDAC_FF9CC_shared_board(void) {
    s32 var_s0;
    s32 i, j;

    if (D_801012C4_114EE4_shared_board != NULL) {
        HuMemMemoryFreeTemp(D_801012C4_114EE4_shared_board);
    }
    D_801012C4_114EE4_shared_board = HuMemMemoryAllocTemp(SPACE_TYPES_TOTAL * SPACES_MAX);
    for (i = 0; i < 16; i++) {
        var_s0 = 0;

        for (j = 0; j < D_80105210_118E30_shared_board; j++) {
            if (GetSpaceData(j)->space_type == i) {
                D_801012C4_114EE4_shared_board[i][var_s0] = j;
                var_s0++;
            }                
        }
        
        D_801012C4_114EE4_shared_board[i][var_s0] = 0xFF;
        D_80105268_118E88_shared_board[i] = var_s0;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBEAC_FFACC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBEC8_FFAE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F5B90", func_800EBED8_FFAF8_shared_board);
