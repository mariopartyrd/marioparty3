#include "common.h"
#include "ovl_80.h"
#include "game/object.h"
#include "game/board.h"

void func_800E982C_FD44C_shared_board(f32*);
void func_800E98E8_FD508_shared_board(f32*);
void func_800E9748_FD368_shared_board(Vec*);
void func_800ED35C_100F7C_shared_board(Vec*, Vec*, Vec*, s32);
void func_800035E8_41E8(s16);
void func_800DB56C_EF18C_shared_board(void);
void func_800DF7F4_F3414_shared_board(void);
void func_800F2484_1060A4_shared_board(s32);
void func_8004A950_4B550(void);
void func_800F92A0_10CEC0_shared_board(void);
s32 func_800F933C_10CF5C_shared_board(void);
s16 func_800EBCD4_FF8F4_shared_board(u8);
void func_800EC5EC_10020C_shared_board(s16 arg0, s32 arg1, s16 arg2);

extern const char D_801025D0_1161F0_shared_board[];
extern Vec2f D_80101D5C_11597C_shared_board[];
extern Vec2f D_80101D84_1159A4_shared_board[];
extern s16 D_800C9930_CA530;
extern u8 D_800CB8B1_CC4B1[];
extern s16 D_800CE206;
extern s32 D_80105668_119288_shared_board;
extern s16 D_8010566C_11928C_shared_board;
extern s16 D_800D037E_D0F7E;
extern s32 D_800A12DC;
extern s16 D_8010566E_11928E_shared_board;
extern Vec D_80105670_119290_shared_board;
extern Vec* D_8010567C_11929C_shared_board;
extern f32 D_80101B70_115790_shared_board[][2];
extern f32 D_80101B90_1157B0_shared_board[][2];
extern f32 D_80101BA8_1157C8_shared_board[][2];
extern f32 D_80101BB8_1157D8_shared_board[][2];
extern f32 D_80101BD8_1157F8_shared_board[][2];
extern f32 D_80101BF0_115810_shared_board[][2];
extern Vec D_80105680_1192A0_shared_board[];
extern Object* D_801056B0_1192D0_shared_board;
extern Object* D_801056B4_1192D4_shared_board;
extern omObjData* D_801056B8_1192D8_shared_board;
extern s16 D_800A12C8;
extern s16 D_800C9930_CA530;
extern f32 D_800C9938_CA538;
extern s16 D_800CE206;
extern s16 D_800D2130;
extern s32 D_800D41C0_D4DC0;
extern s16 D_800D1708_D2308;
extern s16 D_800D4080_D4C80;
extern s16 D_800D1F7A_D2B7A;
extern s16 D_800D6A44_D7644;
extern s16 D_800D1FEC_D2BEC;
extern u16 D_800D03FC;
extern u16 D_800CE208;
extern u16 D_800CDD68;
extern s16 gPrevItemBlockSpaceIndexes[10];
extern s16 gPrevCoinBlockSpaceIndexes[10];
extern s16 gPrevStarBlockSpaceIndexes[10];
extern s8 D_80101DAC_1159CC_shared_board[][4][2];
extern s16 D_80101DCC_1159EC_shared_board[][3];

// s8 D_80101DAC_1159CC_shared_board[4][4][2] = {
//     {
//         { 0xFF, 0x01 },
//         { 0x03, 0x02 },
//         { 0x03, 0x03 },
//         { 0x03, 0x03 },
//     },
//     {
//         { 0x00, 0x01 },
//         { 0xFF, 0x01 },
//         { 0x01, 0x02 },
//         { 0x01, 0x02 },
//     },
//     {
//         { 0x00, 0x01 },
//         { 0x00, 0x01 },
//         { 0xFF, 0x01 },
//         { 0x01, 0x02 },
//     },
//     {
//         { 0x00, 0x00 },
//         { 0x00, 0x01 },
//         { 0x00, 0x01 },
//         { 0xFF, 0xFF },
//     },
// };

// s16 D_80101DCC_1159EC_shared_board[][3] = {
//     {0x2D, 0x5A, 100},
//     {0x46, 0x5F, 100},
//     {0x55, 0x5F, 0x64}
// };

void func_800F8610_10C230_shared_board(s32 id, s16 event, u16 stat) {
    omOvlHisData* overlay = &D_800D20F0_D2CF0[D_800D6B48_D7748->unk_18++];

    if (id != -2) {
        if (id == -1) {
            id = omovlhis[omovlhisidx].overlayID;
            overlay->overlayID = id;
        } else {
            overlay->overlayID = id;
        }
    } else {
        id = D_80101B40_115760_shared_board[GwSystem.current_board_index];
        overlay->overlayID = id;
    }
    
    overlay->event = event;
    overlay->stat = stat;
    
    if (D_800D6B48_D7748->unk_18 >= ARRAY_COUNT(D_800D20F0_D2CF0)) {
        D_800D6B48_D7748->unk_18 = ARRAY_COUNT(D_800D20F0_D2CF0) - 1;
    }
}

void func_800F86B4_10C2D4_shared_board(void) {
    D_800CD2A0_CDEA0.unk_02 = 1;
    D_800D6B48_D7748->unk_18 = 0;

    if (GWBoardFlagCheck(1) == 0) {
        if ((GwSystem.current_board_index != 6) && (func_800F8610_10C230_shared_board(-2, 4, 0x192), (GwSystem.current_board_index != 6))) {
            func_800F8610_10C230_shared_board(0x53, 0, 0x192);
        } else {
            func_800F8610_10C230_shared_board(0x54, 0, 0x192);
        }
        
        func_800F8610_10C230_shared_board(-2, 1, 0x192);
    }
    
    func_800F8D84_10C9A4_shared_board();
    func_800ECF9C_100BBC_shared_board(GwSystem.message_speed);
    _ClearFlag(0xC);
    D_800D6A48_D7648 = 0;
}

void func_800F8774_10C394_shared_board(void) {
    omOvlHisData* overlay;

    D_800D4190_D4D90.stat = 1;
    if (D_800D6B48_D7748->unk_18 != 0) {
        D_800D6B48_D7748->unk_18--;
        overlay = &D_800D20F0_D2CF0[D_800D6B48_D7748->unk_18];
        omOvlCallEx(overlay->overlayID, overlay->event, overlay->stat);
        return;
    }
    if (D_800CD2A0_CDEA0.unk_02 != 0) {
        D_800D4190_D4D90.stat = 0;
        omOvlCallEx(D_80101B40_115760_shared_board[GwSystem.current_board_index], 2, 0x192);
        return;
    }
    if (D_800D6A48_D7648 != 0) {
        _SetFlag(0xC);
    } else {
        _ClearFlag(0xC);
    }
    omOvlReturnEx(1);
}

void func_800F884C_10C46C_shared_board(void) {
    D_800CD2A0_CDEA0.unk_02 = 0;
}


s16 func_800F8858_10C478_shared_board(void) {
    return D_800D4190_D4D90.stat;
}

void func_800F8864_10C484_shared_board(s16 arg0) {
    s16 temp_v0 = D_800D6B48_D7748->unk_18;
    
    D_800D20F0_D2CF0[D_800D6B48_D7748->unk_18].event = arg0;
    D_800D6B48_D7748->unk_18 = temp_v0 + 1;
    if (D_800D6B48_D7748->unk_18 >= 5) {
        D_800D6B48_D7748->unk_18 = 4;
    }
    func_800F8610_10C230_shared_board(-2, 3, 0x192);
    omOvlReturnEx(1);
}

void func_800F88D0_10C4F0_shared_board(void) {
    if (GWBoardFlagCheck(0x17)) {
        GWBoardFlagSet(0x10);
    }
}

s32 func_800F88FC_10C51C_shared_board(void) {
    return D_800D1240_D1E40;
}

void func_800F8908_10C528_shared_board(void) {
    s32* temp_s0 = HuPrcCurrentGet()->user_data;

    while (1) {
        if (
            (func_800F2198_105DB8_shared_board(temp_s0[0]) == 0) && 
            (D_800A12D8 == 0) && 
            ((GwSystem.current_player_index != temp_s0[0]) || (D_800A12D4 == 0)) && 
            (D_800C9520_CA120[GwPlayer[temp_s0[0]].pad] & 0x20)
        ) {
            func_8004ACE0_4B8E0(0x2BD, temp_s0[0]);
        }
        HuPrcVSleep();
    }
}

void func_800F89D0_10C5F0_shared_board(s32 arg0, s16 arg1, s32 arg2, s32 unused) {
    Process* temp_v0_2;
    UnkOvl81_1* temp_v0_3;
    u8 playerIndex;
    Object* temp_v0;
    s32 i;
    GW_SYSTEM* system;

    func_800E9EF4_FDB14_shared_board();
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    
    if (arg0 >= 0) {
        func_800E69BC_FA5DC_shared_board(arg0);
    }
    
    func_800EA60C_FE22C_shared_board();
    if (arg1 >= 0) {
        MBMasuCreate(0x13, (s32) arg1);
    }
    
    func_800D76D0_EB2F0_shared_board(arg2);
    func_800D8F80_ECBA0_shared_board();
    func_800F26E8_106308_shared_board();
    func_800E63F0_FA010_shared_board();
    func_800F25D8_1061F8_shared_board(0);
    func_800F25D8_1061F8_shared_board(1);
    func_800F25D8_1061F8_shared_board(2);
    func_800F25D8_1061F8_shared_board(3);
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800D9714_ED334_shared_board(MBGetPlayerStruct(i)->player_obj);
        temp_v0 = MBGetPlayerStruct(i)->player_obj;
        temp_v0->flags |= 2;
        func_800D9AA4_ED6C4_shared_board(MBGetPlayerStruct(i)->player_obj);
    }
    
    system = &GwSystem;
    playerIndex = system->current_player_index;
    if ((playerIndex < 4) && (GwPlayer[system->current_player_index].itemTurn != 0)) {
        func_800E6264_F9E84_shared_board();
        func_800D9B24_ED744_shared_board(GwPlayer[system->current_player_index].player_obj);
    }
    
    func_8001FDE8_209E8(MBGetPlayerStruct(0)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(1)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(2)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
    func_800F2A20_106640_shared_board();
    func_800DF854_F3474_shared_board();
    func_800E17B0_F53D0_shared_board();
    func_800E4B60_F8780_shared_board();
    func_800F453C_10815C_shared_board();
    func_800DB5DC_EF1FC_shared_board();
    func_8005A6B0_5B2B0();
    func_800ECAB4_1006D4_shared_board();
    D_80105664_119284_shared_board = -1;
    D_800D1360_D1F60.unk_20 = 0;
    D_80105666_119286_shared_board = 0;
    func_800F27D0_1063F0_shared_board();
    D_80101B64_115784_shared_board = NULL;
    D_80101B68_115788_shared_board = NULL;
    D_80101B6C_11578C_shared_board = NULL;
    func_8004CF30_4DB30();
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0_2 = omAddPrcObj(func_800F8908_10C528_shared_board, 0, 0, 0x40);
        temp_v0_3 = HuMemMemoryAlloc(temp_v0_2->heap, sizeof(UnkOvl81_1));
        temp_v0_2->user_data = temp_v0_3;
        temp_v0_3->unk_00 = i;
        omPrcSetStatBit(temp_v0_2, 0xA0);
    }
}

void func_800F8C74_10C894_shared_board(void) {
    func_800DCB8C_F07AC_shared_board();
    func_800F4730_108350_shared_board();
    func_800E4BA0_F87C0_shared_board();
    func_800E18FC_F551C_shared_board();
    func_800DF8B4_F34D4_shared_board();
    func_800F2A34_106654_shared_board();
    func_8005F524_60124();
    func_800E6404_FA024_shared_board();
    func_800F27C4_1063E4_shared_board();
    func_800D8FC4_ECBE4_shared_board();
    func_800D7714_EB334_shared_board();
    func_800EB09C_FECBC_shared_board();
    func_800EA694_FE2B4_shared_board();
    func_800E69D8_FA5F8_shared_board();
    func_800E66E0_FA300_shared_board();
    func_800E66D4_FA2F4_shared_board();
    func_800EA284_FDEA4_shared_board();
    if (D_80101B64_115784_shared_board != NULL) {
        D_80101B64_115784_shared_board();
    }
    if (D_80101B68_115788_shared_board != NULL) {
        D_80101B68_115788_shared_board();
    }
    func_800FC8A4_1104C4_shared_board();
}

//unknown type
void func_800F8D48_10C968_shared_board(void (*arg0)(void)) {
    D_80101B6C_11578C_shared_board = arg0;
}
void func_800F8D54_10C974_shared_board(void (*arg0)(void)) {
    D_80101B64_115784_shared_board = arg0;
}

void func_800F8D60_10C980_shared_board(void (*arg0)()) {
    D_80101B68_115788_shared_board = arg0;
}

void func_800F8D6C_10C98C_shared_board(s32 arg0) {
    D_800CC0B8_CCCB8 = arg0;
}

s16 func_800F8D78_10C998_shared_board(void) {
    return D_800CC0B8_CCCB8;
}

void func_800F8D84_10C9A4_shared_board(void) {
    GW_PLAYER* player;
    s32 i, j;
    GW_SYSTEM* system = &GwSystem;
    GW_COMMON* common = &GwCommon;

    D_800D1240_D1E40 = 0;
    D_800D41C0_D4DC0 = 0;
    D_800CDD68 = 0;
    D_800CE208 = 0;
    D_800D03FC = 0;
    gItemBlockSpaceIndex = -1;
    gStarBlockSpaceIndex = -1;
    gCoinBlockSpaceIndex = -1;
    D_800D1708_D2308 = 0;
    D_800D4080_D4C80 = 0;
    D_800D2130 = 0;

    for (i = 0; i < 10; i++) {
        gPrevCoinBlockSpaceIndexes[i] =
        gPrevStarBlockSpaceIndexes[i] =
        gPrevItemBlockSpaceIndexes[i] = -1;
    }

    D_800D1F7A_D2B7A = 0;
    D_800D6A44_D7644 = 0;
    D_800D1FEC_D2BEC = 0;
    D_800C9938_CA538 = 1.0f;

    func_800DF7F4_F3414_shared_board();
    func_800DB56C_EF18C_shared_board(); //clear lucky 7 flag for buffing golden mushrooms

    D_800A12C8 = -1;
    D_800C9930_CA530 = -1;
    D_800CE206 = 0;
    D_800A12D4 = 1;
    D_800A12D8 = 0;

    func_800F2484_1060A4_shared_board(0);
    func_800F2484_1060A4_shared_board(1);
    func_800F2484_1060A4_shared_board(2);
    func_800F2484_1060A4_shared_board(3);

    if (((common->unk9E == 3) | (common->unk9E == 1)) != 0) {
        common->unk9E = 2;
    }
    if (common->unk9F == 3) {
        common->unk9F = 0;
    }
    if (common->unkA0 == 3) {
        common->unkA0 = 1;
    }
    if (common->unkA1 == 3) {
        common->unkA1 = 1;
    }
    if (common->unkA2 == 3) {
        common->unkA2 = 0;
    }

    system->save_mode = common->unk9E;
    system->show_minigame_explanations = common->unk9F;
    system->message_speed = common->unkA0;
    system->walk_speed = common->unkA1;
    system->show_com_minigames = common->unkA2;

    if (GWBoardFlagCheck(1) == 0) {
        system->current_star_spawn = 0;
        system->current_turn = 1;
        system->current_player_index = 0;
        system->minigame_index = 0;

        #ifdef BUG_FIX
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
        #else
        for (i = 0; i < 5; i++) { // 5??
        #endif
            player = MBGetPlayerStruct(i);
            player->coin = 0;
            player->gamePrize = 0;
            player->coinPrize = 0;
            player->stats.prize.hatenaPrize = 0;
            player->stats.prize.redPrize = 0;
            player->stats.prize.bluePrize = 0;
            player->stats.prize.eventPrize = 0;
            player->stats.prize.gamblePrize = 0;
            player->stats.prize.kupaPrize = 0;
            player->stats.prize.battlePrize = 0;
            player->stats.prize.itemPrize = 0;
            player->stats.prize.bankPrize = 0;
            player->rev = 0;
            for (j = 0; j < ARRAY_COUNT(player->itemNo); j++) {
                player->itemNo[j] = -1;
            }
            player->itemTurn = 0;
        }

        //TODO: 16?
        for (i = 0; i < 16; i++) {
            GwSystem.boardData.halfWordBytes[i] = 0;
        }

        GWBoardFlagClear(6);
        GWBoardFlagClear(7);
        GWBoardFlagClear(8);
        GWBoardFlagClear(9);
        GWBoardFlagClear(10);
        GWBoardFlagClear(11);
        GWBoardFlagClear(12);
        GWBoardFlagClear(13);
        GWBoardFlagClear(18);
        GWBoardFlagClear(19);
        GWBoardFlagClear(20);
        GWBoardFlagClear(21);
        GWBoardFlagClear(22);
        GWBoardFlagClear(23);
        GWBoardFlagClear(2);
        GWBoardFlagClear(3);
        GWBoardFlagClear(4);
        GWBoardFlagClear(14);
        GWBoardFlagClear(1);
        GWBoardFlagClear(17);
        GWBoardFlagClear(16);

        if (_CheckFlag(0x1B) != 0) {
            GWBoardFlagSet(0xF);
        } else {
            GWBoardFlagClear(0xF);
        }

        if (GwSystem.playMode & 4) {
            if (_CheckFlag(0x28) != 0) {
                GWBoardFlagSet(0);
                return;
            }
            GWBoardFlagClear(0);
            return;
        }

        if (_CheckFlag(0x16) != 0) {
            GWBoardFlagSet(0);
            return;
        }

        GWBoardFlagClear(0);
    }
}

void func_800F915C_10CD7C_shared_board(s16 arg0) {
    D_8010566E_11928E_shared_board = arg0;
}

s16 func_800F9168_10CD88_shared_board(void) {
    return D_8010566E_11928E_shared_board;
}

void func_800F9174_10CD94_shared_board(Vec* arg0) {
    D_80105670_119290_shared_board = *arg0;
}

void func_800F9198_10CDB8_shared_board(Vec* arg0) {
    D_8010567C_11929C_shared_board = arg0;
}

void func_800F91A4_10CDC4_shared_board(void) {
    f32 sp10[2];

    while (1) {
        switch (D_8010566E_11928E_shared_board) {
        case 1:
            func_800E9748_FD368_shared_board(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
            break;
        case 2:
            func_800E9748_FD368_shared_board(&D_80105670_119290_shared_board);
            break;
        case 4:
            func_800E9748_FD368_shared_board(D_8010567C_11929C_shared_board);
            break;
        case 3:
            func_800E98E8_FD508_shared_board(sp10);
            func_800E982C_FD44C_shared_board(sp10);
            break;
        }
        HuPrcVSleep();    
    }
}

void func_800F92A0_10CEC0_shared_board(void) {
    GW_SYSTEM* system = &GwSystem;
    
    system->current_player_index++;
    
    if (system->current_player_index >= 4) {
        system->current_player_index = 0;
        if (D_800A12DC == 0) {
            if (GwSystem.unk_52 != 2) {
                system->current_turn++;
            } else {
                GwSystem.unk_52 = 3;
                system->current_turn = system->total_turns - 4;
            }
            if (system->current_turn >= 99) {
                system->current_turn = 99;
            }
        }
    }
}

s32 func_800F933C_10CF5C_shared_board(void) {
    GW_SYSTEM* system = &GwSystem;
    
    //TODO: is there another way to write this?
    if ((system->current_player_index == 3) || (system->current_player_index < 0) || (system->current_player_index >= 4)) {
        if (system->total_turns >= 0) {
            if (system->current_turn == (system->total_turns - 5)) {
                return 1;
            }
        }
        
        if (GwSystem.unk_52 == 2) {
            return 1;
        }            
    }
    
    return 0;
}

void func_800F93A4_10CFC4_shared_board(void) {
    s32 i;

    do {
        HuPrcVSleep();
    } while (WipeStatGet() != 0);

    while (1) {
        HuPrcVSleep();
        if (D_800D530C_D5F0C == 0 && D_80105664_119284_shared_board < 0) {
            continue;
        }        

        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        
        if (D_80105666_119286_shared_board != 0) {
            HuAudSeqFadeOut(0x5A);
            if (D_800C9930_CA530 != -1) {
                func_800039A4_45A4(D_800C9930_CA530, 0x5A);
                D_800C9930_CA530 = -1;
                func_8004A950_4B550();
            }
            if (D_800CE206 != 0) {
                func_8004A950_4B550();
                D_800CE206 = 0;
            }
        }
        
        WipeCreateOut((s32) D_800D1360_D1F60.unk_20, 0x10);
        HuPrcSleep(0x11);
        func_800F8C74_10C894_shared_board();
        
        if (D_80105664_119284_shared_board & 0x20) {
            D_800D6A48_D7648 = 1;
            if (GwSystem.current_board_index == 5) {
                _CheckFlag(9);
            }
            func_800F8610_10C230_shared_board(0x4F, 0, 0x4190);
            func_800F884C_10C46C_shared_board();
        }
        
        if (D_80105664_119284_shared_board & 1) {
            if (func_800F933C_10CF5C_shared_board() != 0) {
                func_800F8610_10C230_shared_board(0x51, 0, 0x192);
            }
            func_800F92A0_10CEC0_shared_board();
        }
        
        if (D_80105664_119284_shared_board & 2) {
            for (i = 0; i< 4; i++) {
                if (D_801057E0_119400_shared_board[i].spaceType == 1) {
                    D_800CB8B1_CC4B1[i] = 0;
                } else {
                    D_800CB8B1_CC4B1[i] = 1;
                }
            }
            func_800F8610_10C230_shared_board(0x70, 0, 0x192);
        }
        
        if (D_80105664_119284_shared_board & 8) {
            func_800F8610_10C230_shared_board(D_80105668_119288_shared_board, D_8010566C_11928C_shared_board, 0x192);
        }
        
        GWBoardFlagClear(5);
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

void func_800F95FC_10D21C_shared_board(s16 arg0) {
    switch (--arg0) {
    case 13:
        if (GwSystem.current_player_index != MB_MAX_PLAYERS) {
            HuAudFXPlay(0x123);
            return;
        }
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 11:
    case 14:
        HuAudFXPlay(0x101);
        break;
    }
}

void func_800F965C_10D27C_shared_board(s16 arg0) {
    switch (--arg0) {
    case 3:
    case 5:
        HuAudFXPlay(0x108);
        break;
    case 0:
        HuAudFXPlay(0x121);
        break;
    case 1:
        HuAudFXPlay(0x122);
        break;
    case 11:
        HuAudFXPlay(0x124);
        break;
    case 4:
        HuAudFXPlay(0x12F);
        break;
    case 8:
    case 14:
        HuAudFXPlay(0x12E);
        break;
    case 6:
        HuAudFXPlay(0x130);
        break;
    case 13:
        HuAudFXPlay(0x123);
        break;
    }
}

void func_800F96E0_10D300_shared_board(s32 playerNo, s32 arg1) {
    GW_PLAYER* player;
    GW_PLAYER* playerCur;
    SpaceData* space;
    s32 var_s1;
    s32 var_s4;
    s32 playersShareSpace;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    player = MBGetPlayerStruct(playerNo);
    space = GET_SPACE_FROM_CHAIN(player->clink, player->cidx);
    if (system->current_player_index == playerNo) {
        HuVecCopy3F(&player->player_obj->coords, &space->coords);
        return;
    }
    
    playersShareSpace = 0;
    playerCur = MBGetPlayerStruct(system->current_player_index);
    var_s4 = 0;
    
    if (player->clink == playerCur->clink) {
        playersShareSpace = player->cidx == playerCur->cidx;
    }
    
    var_s1 = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((playerNo != i) && (i != system->current_player_index)) {
            GW_PLAYER* curPlayer = MBGetPlayerStruct(i);
            if ((player->clink == curPlayer->clink) && (player->cidx == curPlayer->cidx)) {
                var_s1 += 1;
                var_s4 += i < playerNo;
            }
        }        
    }

    if (playersShareSpace == 1) {
        if (var_s1 == 2) {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101BD8_1157F8_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101BD8_1157F8_shared_board[var_s4][1]);
        } else if (var_s1 == 3) {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101BB8_1157D8_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101BB8_1157D8_shared_board[var_s4][1]);
        } else {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101BF0_115810_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101BF0_115810_shared_board[var_s4][1]);
        }
    } else {
        if (var_s1 == 0) {
            HuVecCopy3F(&D_80105680_1192A0_shared_board[playerNo], &space->coords);
        } else if (var_s1 == 2) {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101B90_1157B0_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101B90_1157B0_shared_board[var_s4][1]);            
        } else if (var_s1 == 3) {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101B70_115790_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101B70_115790_shared_board[var_s4][1]);
        } else {
            HuVecCopyXYZ(&D_80105680_1192A0_shared_board[playerNo], space->coords.x + D_80101BA8_1157C8_shared_board[var_s4][0], space->coords.y, space->coords.z + D_80101BA8_1157C8_shared_board[var_s4][1]);            
        }
    }

    if (arg1 < 2) {
        HuVecCopy3F(&player->player_obj->coords, &D_80105680_1192A0_shared_board[playerNo]);
        return;
    }
    func_800ED35C_100F7C_shared_board(&player->player_obj->coords, &D_80105680_1192A0_shared_board[playerNo], &player->player_obj->coords, arg1);
}

//if player should jump to next space
s32 func_800F9A68_10D688_shared_board(s32 arg0) {
    Vec sp10;
    GW_PLAYER* curPlayer;
    GW_PLAYER* player;
    f32 var_f4;
    SpaceData* space;
    SpaceData* nextSpace;
    s32 var_s2;
    s32 var_s4;
    s32 i;
    Vec* temp;

    curPlayer = MBGetPlayerStruct(arg0);
    var_s2 = 0;
    var_s4 = 0;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == arg0) {
            continue;
        }
        player = MBGetPlayerStruct(i);
        if (curPlayer->clink == player->clink) {
            var_s4 += curPlayer->cidx == player->cidx;
        }
        if (curPlayer->nlink == player->clink) {
            var_s2 += curPlayer->nidx == player->cidx;
        }        
    }
    
    space = GET_SPACE_FROM_CHAIN(curPlayer->clink, curPlayer->cidx);
    HuVecSubtract(&sp10, &GET_SPACE_FROM_CHAIN(curPlayer->nlink, curPlayer->nidx)->coords, &space->coords);
    var_f4 = func_800D8790_EC3B0_shared_board(&sp10);
    if ((var_s4 == 0) || (!(D_80101D5C_11597C_shared_board[var_s4].x < var_f4)) || (!(var_f4 <= D_80101D5C_11597C_shared_board[var_s4].y))) {
        if (var_s2 != 0) {
            if (D_80101D84_1159A4_shared_board[var_s2].x < 0.0f) {
                var_f4 -= 360.0f;
            }
            if (!(D_80101D84_1159A4_shared_board[var_s2].x < var_f4) || (!(var_f4 <= D_80101D84_1159A4_shared_board[var_s2].y))) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

void func_800F9C68_10D888_shared_board(void) {
    HuPrcSleep(30);
    func_800035E8_41E8(D_800D037E_D0F7E);
    D_800CE206 = 0;
    omDelPrcObj(NULL);
}

void func_800F9CA0_10D8C0_shared_board(omObjData* arg0) {
    D_801056B0_1192D0_shared_board->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    D_801056B4_1192D4_shared_board->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    arg0->rot.x += 10.0f;
}

//related to how CPUs decide who to duel?
s32 func_800F9D1C_10D93C_shared_board(void) {
    s32 i;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 sp10[MB_MAX_PLAYERS];
    GW_SYSTEM* system = &GwSystem;

    for (i = 0, var_s2 = 99; i < MB_MAX_PLAYERS; i++) {
        if ((i != system->current_player_index) && ((GwSystem.unk_58 >> i) & 1) && (BoardPlayerRankCalc(i) < var_s2) && GwPlayer[i].coin != 0) {
            var_s2 = BoardPlayerRankCalc(i);
        }
    }
    
    var_s1 = 0;
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if ((i != system->current_player_index) && ((GwSystem.unk_58 >> i) & 1) && (BoardPlayerRankCalc(i) == var_s2)) {
            sp10[var_s1] = i;
            var_s1 += 1;
        }        
    }
    
    if (MBGetPlayerStruct(CUR_PLAYER)->coin >= 20) {
        if (MBGetPlayerStruct(sp10[0])->coin < 20) {
            for (i = 0, var_s2 = 99, var_s3 = 0; i < MB_MAX_PLAYERS; i++) {
                if ((i != system->current_player_index) && (MBGetPlayerStruct(i)->coin >= 20)) {
                    var_s3 = 1;
                    if (BoardPlayerRankCalc(i) < var_s2) {
                        var_s2 = BoardPlayerRankCalc(i);
                    }
                }
            }
            
            if (var_s3 != 0) {
                for (i = 0, var_s1 = 0; i < MB_MAX_PLAYERS; i++) {
                    if ((i != system->current_player_index) && ((GwSystem.unk_58 >> i) & 1) && (BoardPlayerRankCalc(i) == var_s2) && GwPlayer[i].coin != 0) {
                        sp10[var_s1] = i;
                        var_s1++;
                    }
                }
            }
        }
    }
    i = sp10[func_800EEF80_102BA0_shared_board(var_s1)];
    if (GwPlayer[i].coin == 0) {
        i = 4;
    }
    return i;
}

s32 func_800F9F84_10DBA4_shared_board(s32 playerNo) {
    s32 randRange;
    s32 minCoinAmount;
    s32 starDifference;
    s32 rank;
    GW_SYSTEM* system = &GwSystem;

    starDifference = GwPlayer[system->current_player_index].star - GwPlayer[playerNo].star;
    
    if ((GwPlayer[system->current_player_index].star - GwPlayer[playerNo].star) < 0) {
        starDifference = GwPlayer[playerNo].star - GwPlayer[system->current_player_index].star;
    }

    //@bug this should've been  if (starDifference >= 1) {
    if (starDifference <= 1) {
        starDifference = 1;
    }
    
    rank = BoardPlayerRankCalc(system->current_player_index);
    switch (D_80101DAC_1159CC_shared_board[rank][playerNo][starDifference]) {
    case 0:
        randRange = 10; 
        minCoinAmount = 90;
        break;
    case 1:
        randRange = 20;
        minCoinAmount = 60;
        break;
    case 2:
        randRange = 20;
        minCoinAmount = 20;
        break;
    default:
        randRange = 9;
        minCoinAmount = 1;
        break;
    }
    randRange = (minCoinAmount + func_800EEF80_102BA0_shared_board(randRange)) + 1;
    return GwPlayer[system->current_player_index].coin * (randRange / 100.0f);
}


s32 func_800FA104_10DD24_shared_board(u8* arg0) {
    s32 var_s2 = 0;
    s16 sp18[4];
    u8 sp20[4] = {1, 2, 4, 8};
    s32 j;
    s32 i;
    GW_SYSTEM* system = &GwSystem;
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i == system->current_player_index) {
            if (GwPlayer[i].stat & 1) {
                var_s2 = 1; //why does this change codegen
                var_s2 = func_800F9D1C_10D93C_shared_board() + 1;
                sp18[GwPlayer[i].pad] = 0x400;
            } else {
                func_8005FE54_60A54(D_80105702_119322_shared_board, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (var_s2 != 0) {
        func_8005B63C_5C23C(D_80105702_119322_shared_board, 2, 2);
        for (j = 0; var_s2 != 0; j++) {
            var_s2--;
            if (var_s2 == 0) {
                sp18[GwPlayer[system->current_player_index].pad] = -0x8000;
            }
            if (j == 0) {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], func_800EDC40_101860_shared_board());
            } else {
                func_8005F698_60298(sp18[0], sp18[1], sp18[2], sp18[3], 5);
            }            
        }
    } else {
        func_8005F744_60344(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (arg0[i] == 0) {
            func_8006010C_60D0C(D_80105702_119322_shared_board, i);
        }
    }
    
    i = 0;
    do {
        i = func_8005E1D8_5EDD8(D_80105702_119322_shared_board, i, 1);
    } while (arg0[i] == 0);
    return i;
}

void func_800FA388_10DFA8_shared_board(void) {
    omDelObj(D_801056B8_1192D8_shared_board);
    
    while (D_801056B0_1192D0_shared_board->unk30.x <= 120.0f) {
        HuPrcVSleep();
        D_801056B0_1192D0_shared_board->unk30.x += 3.0f;
        D_801056B4_1192D4_shared_board->unk30.x += 3.0f;
    }
    
    func_800D9B54_ED774_shared_board(D_801056B0_1192D0_shared_board);
    func_800D9B54_ED774_shared_board(D_801056B4_1192D4_shared_board);
}


void func_800FA448_10E068_shared_board(void) {
    char sp20[4];
    s32 temp_s1;
    s32 var_s0;
    GW_SYSTEM* system = &GwSystem;

    if ((GwPlayer[system->current_player_index].bonusCoin == 0) && (GwPlayer[GwSystem.unk_58].bonusCoin == 0)) {
        func_800EC4E4_100104_shared_board(6, 0x4006, 0x88);
        func_800E1F28_F5B48_shared_board(system->current_player_index, GwSystem.playerIndexVisitingBowser);
        func_800F5BF4_109814_shared_board(system->current_player_index, GwSystem.playerIndexVisitingBowser, 0);
        func_800E1F28_F5B48_shared_board(GwSystem.unk_58, GwSystem.playerIndexVisitingBowser);
        func_800F5BF4_109814_shared_board(GwSystem.unk_58, GwSystem.playerIndexVisitingBowser, 1);
    } else {
        var_s0 = (GwPlayer[system->current_player_index].bonusCoin != 0) ? system->current_player_index : GwSystem.unk_58;
        temp_s1 = GwSystem.playerIndexVisitingBowser * 2;
        sprintf(sp20, D_801025D0_1161F0_shared_board, temp_s1);
        func_800EC70C_10032C_shared_board(6, 0x4005, D_801014A0_1150C0_shared_board[GwPlayer[var_s0].chr], (u32)sp20, 0, 0, 0, 0x88);
        func_800EC6C8_1002E8_shared_board();
        func_800EC6EC_10030C_shared_board();
        if (GwPlayer[system->current_player_index].bonusCoin != 0) {
            func_800E1F28_F5B48_shared_board(system->current_player_index, temp_s1);
            func_800F5BF4_109814_shared_board(system->current_player_index, temp_s1, 1);
        }
        if (GwPlayer[GwSystem.unk_58].bonusCoin != 0) {
            func_800E1F28_F5B48_shared_board(GwSystem.unk_58, temp_s1);
            func_800F5BF4_109814_shared_board(GwSystem.unk_58, temp_s1, 1);
        }        
    }
    
    func_800FA388_10DFA8_shared_board();
}

void func_800FA640_10E260_shared_board(GW_PLAYER* arg0, s32 arg1) {
    D_801056B0_1192D0_shared_board = MBModelCreate(0xCU, 0);
    Hu3DModelScaleSet(D_801056B0_1192D0_shared_board->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(D_801056B0_1192D0_shared_board->omObj1->model[0]);
    
    D_801056B0_1192D0_shared_board->flags |= 1;
    D_801056B4_1192D4_shared_board = MBModelCreate(0x1F, 0);
    
    Hu3DModelScaleSet(D_801056B4_1192D4_shared_board->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&D_801056B0_1192D0_shared_board->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&D_801056B4_1192D4_shared_board->coords, &arg0->player_obj->coords);
    
    D_801056B0_1192D0_shared_board->unk30.x = 120.0f;
    D_801056B4_1192D4_shared_board->unk30.x = 122.0f;
    
    while (D_801056B0_1192D0_shared_board->unk30.x > 30.0f) {
        if (arg1 == 0) {
            HuPrcVSleep();
        }
        D_801056B0_1192D0_shared_board->unk30.x -= 1.0f;
        D_801056B4_1192D4_shared_board->unk30.x -= 1.0f;
    }
    D_801056B8_1192D8_shared_board = omAddObj(0x1F4, 0, 0, -1, func_800F9CA0_10D8C0_shared_board);
    D_801056B8_1192D8_shared_board->rot.x = 180.0f;
}

s16 func_800FA818_10E438_shared_board(s32 arg0) {
    GW_SYSTEM* system =  &GwSystem;
    GW_PLAYER* player;
    s16 temp_s3;
    s32 var_s2;
    s32 i;

    var_s2 = 0;
    if ((system->total_turns - system->current_turn) >= 5) {
        return 0;
    }

    temp_s3 = MBMasuLinkMasuIdGet(MBGetPlayerStruct(CUR_PLAYER)->clink, MBGetPlayerStruct(CUR_PLAYER)->cidx);
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (i != MBGetPlayerStruct(CUR_PLAYER)->turn) {
            if (temp_s3 == MBMasuLinkMasuIdGet(MBGetPlayerStruct(i)->clink, MBGetPlayerStruct(i)->cidx)) {
                var_s2 |= 1 << i;
                if (arg0 != 0) {
                    func_800FF900_113520_shared_board(i, 3);
                }
            }
        }    
    }
    return var_s2;
}

void func_800FA95C_10E57C_shared_board(void) {
    s32 var_s0;
    s32 temp_a0_2;
    s32 var_a0;
    s32 var_a1;
    s32 temp_a3;
    s32 i;
    GW_SYSTEM* system = &GwSystem;
    s32 var_s1;

    WipeCreateOut(8, 0x10);
    HuPrcSleep(17);
    HuPrcSleep(5);
    var_s1 = GwSystem.unk_58;
    var_s0 = GwPlayer[system->current_player_index].cpu_difficulty - GwPlayer[var_s1].cpu_difficulty;
    
    if ((GwPlayer[system->current_player_index].cpu_difficulty - GwPlayer[var_s1].cpu_difficulty) < 0) {
        var_s0 = GwPlayer[GwSystem.unk_58].cpu_difficulty - GwPlayer[system->current_player_index].cpu_difficulty;
    }
    
    if (var_s0 > 2) {
        var_s0 = 2;
    }
    
    temp_a0_2 = func_800EEF80_102BA0_shared_board(100.0f);
    for (i = 0; i < 3; i++) {
        if (!(D_80101DCC_1159EC_shared_board[var_s0][i] < temp_a0_2)) {
            break;
        }
    }

    //this whole block just sets both players to zero coins with pointless extra logic to do so
    var_a0 = system->current_player_index;
    var_a1 = var_s1;
    temp_a3 = var_a0;
    
    if (GwPlayer[var_a0].cpu_difficulty < GwPlayer[var_a1].cpu_difficulty) {
        var_a0 = var_a1;
        var_a1 = temp_a3;
    }
    GwPlayer[var_a0].bonusCoin = 0;
    GwPlayer[var_a1].bonusCoin = 0;
    //end of block

    switch(i) {
    case 0:
        GwPlayer[var_a0].bonusCoin = 10;
        break;
    case 1:
        GwPlayer[var_a1].bonusCoin = 10;
        break;
    }

    D_800D037C_D0F7C = 0;
    func_8004A7C4_4B3C4(0x1E);
    HuPrcSleep(0xF);
    func_8004A72C_4B32C(0x1E);
    D_800D037C_D0F7C = 1;
    D_800C9930_CA530 = -1;
    D_800CE206 = 0;
    omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0, 0, 0), 0xA0);
    WipeCreateIn(8, 0x10);
    HuPrcSleep(17);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FAB98_10E7B8_shared_board);

// static const u8 D_80101DE8_115A08_shared_board[9][3] = {
//     {  4,  7, 11 }, // 10 turns
//     {  6, 11, 16 }, // 15 turns
//     {  6, 16, 21 }, // 20 turns
//     {  9, 17, 26 }, // 25 turns
//     { 11, 21, 31 }, // 30 turns
//     { 11, 21, 36 }, // 35 turns
//     { 14, 27, 41 }, // 40 turns
//     { 16, 31, 46 }, // 45 turns
//     { 16, 36, 51 }, // 50 turns
// };

/**
 * @brief Gets the current game phase based on the given turn number.
 *
 * This function determines which phase of the game the given turn falls into:
 * early game (0), mid game (1), or late game (2). The thresholds for these
 * phases depend on the total number of turns set for the game and are defined
 * in a lookup table.
 *
 * If the special value `CUR_TURN` is passed, the current turn from GwSystem
 * is used.
 *
 * @param turn The turn number to check. Pass `CUR_TURN` to use the current game turn.
 * @return An integer representing the game phase:
 *         - 0: Early game
 *         - 1: Mid game
 *         - 2: Late game
 */
s32 BoardGetTurnTier(s32 turn) {
    u32 turnTierIndex;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    if (turn == CUR_TURN) {
        turn = system->current_turn;
    }

    turnTierIndex = (system->total_turns / 5) - 2;

    if (system->total_turns < turn) {
        turn = system->total_turns;
    }

    if (turnTierIndex >= 9) {
        turnTierIndex = 0;
    }

    for (i = 0; i < 3; i++) {
        if (D_80101DE8_115A08_shared_board[turnTierIndex][i] > turn) {
            break;
        }
    }

    return i;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FB624_10F244_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC3D0_10FFF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC4E0_110100_shared_board);

void func_800FC594_1101B4_shared_board(void) {
    s32 i;

    if (GWBoardFlagCheck(0xF) != 0) {
        while (gCoinBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gStarBlockSpaceIndex || gCoinBlockSpaceIndex == gItemBlockSpaceIndex) {
            gCoinBlockSpaceIndex = func_800EBCD4_FF8F4_shared_board(D_800D03FC);
            D_800D03FC++;
            for (i = 0; i < 10; i++) {
                if (gCoinBlockSpaceIndex == gPrevCoinBlockSpaceIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gCoinBlockSpaceIndex = -1;
            }
        }
        while (gStarBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gStarBlockSpaceIndex || gItemBlockSpaceIndex == gStarBlockSpaceIndex) {
            gStarBlockSpaceIndex = func_800EBCD4_FF8F4_shared_board(D_800CE208);
            D_800CE208++;
            for (i = 0; i < 10; i++) {
                if (gStarBlockSpaceIndex == gPrevStarBlockSpaceIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gStarBlockSpaceIndex = -1;
            }
        }
        
        while (gItemBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gItemBlockSpaceIndex || gStarBlockSpaceIndex == gItemBlockSpaceIndex) {
            gItemBlockSpaceIndex = func_800EBCD4_FF8F4_shared_board(D_800CDD68);
            D_800CDD68++;
            for (i = 0; i < 10; i++) {
                if (gItemBlockSpaceIndex == gPrevItemBlockSpaceIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gItemBlockSpaceIndex = -1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC7C8_1103E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC8A4_1104C4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC938_110558_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC968_110588_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC998_1105B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FC9E0_110600_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FCA14_110634_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FCA4C_11066C_shared_board);

// INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", D_801025CC_1161EC_shared_board);

const char D_801025D0_1161F0_shared_board[] = "%d";

// INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", D_801025D0_1161F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FCA7C_11069C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF0F8_112D18_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF158_112D78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF41C_11303C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF75C_11337C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF788_1133A8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF794_1133B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF7C4_1133E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF7F0_113410_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF800_113420_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF834_113454_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF840_113460_shared_board);
