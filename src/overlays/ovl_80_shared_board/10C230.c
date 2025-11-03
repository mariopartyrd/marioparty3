#include "common.h"
#include "ovl_80.h"
#include "game/object.h"
#include "game/board.h"

void func_800E982C_FD44C_shared_board(f32*);
void func_800E98E8_FD508_shared_board(f32*);
void func_800E9748_FD368_shared_board(Vec*);
Process* func_800ED35C_100F7C_shared_board(Vec*, Vec*, Vec*, s32);
void func_800035E8_41E8(s16);
void func_800DB56C_EF18C_shared_board(void);
void func_800DF7F4_F3414_shared_board(void);
void func_800F2484_1060A4_shared_board(s32);
void func_8004A950_4B550(void);
void MBNextPlayerTurn(void);
s32 MBLast5Check(void);
s16 MBMasuKakusiBlockGet(u8);
void func_800EC5EC_10020C_shared_board(s16 arg0, s32 arg1, s16 arg2);
extern s16 D_800D4080_D4C80;
s16 RNGPercentChance(s8 arg0);
void func_800500E0_50CE0(s32);                           /* extern */
s16 func_8005E0C0_5ECC0(s16);                       /* extern */
void func_800600C0_60CC0(s16, s32);                      /* extern */
s32 func_80061188_61D88(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5);
void func_80061A5C_6265C(s16, s32);                      /* extern */
void func_800DBFBC_EFBDC_shared_board(s8);             /* extern */
s32 func_800DCD9C_F09BC_shared_board(s8);           /* extern */
Process* func_800DD6C4_F12E4_shared_board(s8);      /* extern */
Process* func_800DDDD4_F19F4_shared_board(s8);      /* extern */
void func_800DE414_F2034_shared_board(s8, u8);         /* extern */
Process* func_800DE7E4_F2404_shared_board(s8);      /* extern */
u8 func_800DE84C_F246C_shared_board(void);             /* extern */
void func_800DE858_F2478_shared_board(void);               /* extern */
void func_800DE868_F2488_shared_board(void);               /* extern */
Process* func_800E0A14_F4634_shared_board(void);        /* extern */
Process* func_800E0C3C_F485C_shared_board(void);        /* extern */
Process* func_800E0F84_F4BA4_shared_board(void);        /* extern */
void MBItemKoopaNKinokoExec(void);               /* extern */
void MBItemKoopaRKinokoExec(void);               /* extern */
void func_800E455C_F817C_shared_board(void);               /* extern */
void func_800E4954_F8574_shared_board(void);               /* extern */
Process* func_800E5CE0_F9900_shared_board(s8);      /* extern */
void func_800E648C_FA0AC_shared_board(void);               /* extern */
void func_800E8DD4_FC9F4_shared_board(f32);              /* extern */
Process* func_800E8EDC_FCAFC_shared_board(f32);       /* extern */
void func_800EB97C_FF59C_shared_board(s16);            /* extern */
s32 func_800EBAC8_FF6E8_shared_board(s16, s32);       /* extern */
void func_800EBCBC_FF8DC_shared_board(s16);            /* extern */
s16 func_800EBCC8_FF8E8_shared_board(void);             /* extern */
void func_800EBEC8_FFAE8_shared_board(void);               /* extern */
void func_800ECC28_100848_shared_board(short);           /* extern */
void func_800ECDD4_1009F4_shared_board(s32, u8);         /* extern */
void func_800ED1E4_100E04_shared_board(Vec*, Vec*, Vec*, s32); /* extern */
void func_800ED410_101030_shared_board(s8, s32);         /* extern */
Process* func_800EDB98_1017B8_shared_board(Object*, f32, f32); /* extern */
void func_800EE688_1022A8_shared_board(Object*, f32, f32); /* extern */
void func_800F22C0_105EE0_shared_board(s32);             /* extern */
void func_800F2388_105FA8_shared_board(s32, s32, s32, s32, s32); /* extern */
Process* func_800F292C_10654C_shared_board(void);       /* extern */
Process* func_800F29EC_10660C_shared_board(void);       /* extern */
void func_800F482C_10844C_shared_board(s32);           /* extern */
void func_800F70F8_10AD18_shared_board(void);              /* extern */
void func_800F7108_10AD28_shared_board(void);              /* extern */
void func_800F85C0_10C1E0_shared_board(void);              /* extern */
void func_800F85E4_10C204_shared_board(void);              /* extern */
void MBNextPlayerTurn(void);              /* extern */
s32 MBLast5Check(void);            /* extern */
void func_800F965C_10D27C_shared_board(s16);            /* extern */
void func_800F96E0_10D300_shared_board(s32, s32);      /* extern */
void MBKettouResultExec(void);              /* extern */
void MBBattleKuriboStart(GW_PLAYER*, s32); /* extern */
void MBKettouComResultSet(void);              /* extern */
s32 MBKettouExec(GW_PLAYER*, s32); /* extern */
s32 func_800FB624_10F244_shared_board(GW_PLAYER*);  /* extern */
void func_800FC3D0_10FFF0_shared_board(void);              /* extern */
void func_800FC4E0_110100_shared_board(void);              /* extern */
void func_800FC7C8_1103E8_shared_board(void);              /* extern */
void func_800FF794_1133B4_shared_board(s32, s32, s32, s32);    /* extern */
void func_800FF840_113460_shared_board(s32);             /* extern */
void func_8004A670_4B270(s32);
Process* func_800E11C0_F4DE0_shared_board(s8, s32);
void func_800E2260_F5E80_shared_board(s32, char*);
Unk3* func_800E210C_F5D2C_shared_board(s16 arg0, s16 arg1, u8 arg2);
void func_800FF7C4_1133E4_shared_board(s32, s32, s32);
void MBExit(void);
extern Unk3* D_80101E60_115A80_shared_board;
extern Unk3* D_80101E64_115A84_shared_board;
extern Unk3* D_80101E68_115A88_shared_board;
extern Unk3* D_80101E6C_115A8C_shared_board;
extern s16 D_800D1380_D1F80;
extern s32 D_800A12CC;
extern f32 D_800C9938_CA538;
extern s16 D_800CC4A0_CD0A0;
extern s16 D_800D2130;
extern s32 D_800D41C0_D4DC0;
extern u8 D_80101C00_115820_shared_board[4];
extern u8 D_80101C04_115824_shared_board[4];
extern u16 D_80101C08_115828_shared_board[4][2];
extern u16 D_80101C24_115844_shared_board[];
extern u16 D_80101C2C_11584C_shared_board[4][8];
extern u8 D_80101E70_115A90_shared_board[4][2];
extern s32 D_80105660_119280_shared_board;
extern s16 D_800CDD64_CE964;
extern void* D_800D2140_D2D40[];
extern s16 D_800D6A44_D7644;
extern s16 D_800D1FEC_D2BEC;
extern s16 D_800D1708_D2308;
extern s16 D_800D1F7A_D2B7A;
extern u16 D_80101D2C_11594C_shared_board[2][4][3];
extern s32 D_80101C4C_11586C_shared_board[][8];
extern u16 D_80101C8C_1158AC_shared_board[][5][8];

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
extern Object* mbBattleKuriboMdl;
extern Object* mbBattleKuriboUpperMdl;
extern omObjData* mbBattleKuriboObj;
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
extern s16 kakusiMasuItemOld[10];
extern s16 kakusiMasuCoinOld[10];
extern s16 kakusiMasuStarOld[10];
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

void MBOvlCall(s32 id, s16 event, u16 stat) {
    omOvlHisData* overlay = &mbovlhis[mbovlhisidx++];

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
    
    if (mbovlhisidx >= ARRAY_COUNT(mbovlhis)) {
        mbovlhisidx = ARRAY_COUNT(mbovlhis) - 1;
    }
}

void MBOvlCallInit(void) {
    D_800CD2A0_CDEA0.unk_02 = 1;
    mbovlhisidx = 0;

    if (GWBoardFlagCheck(1) == 0) {
        if ((GwSystem.current_board_index != 6) && (MBOvlCall(-2, 4, 0x192), (GwSystem.current_board_index != 6))) {
            MBOvlCall(0x53, 0, 0x192);
        } else {
            MBOvlCall(0x54, 0, 0x192);
        }
        
        MBOvlCall(-2, 1, 0x192);
    }
    
    MBSaveInit();
    func_800ECF9C_100BBC_shared_board(GwSystem.message_speed);
    _ClearFlag(0xC);
    D_800D6A48_D7648 = 0;
}

void MBOvlCallExec(void) {
    omOvlHisData* overlay;

    D_800D4190_D4D90.stat = 1;
    if (mbovlhisidx != 0) {
        mbovlhisidx--;
        overlay = &mbovlhis[mbovlhisidx];
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
    s16 temp_v0 = mbovlhisidx;
    
    mbovlhis[mbovlhisidx].event = arg0;
    mbovlhisidx = temp_v0 + 1;
    if (mbovlhisidx >= 5) {
        mbovlhisidx = 4;
    }
    MBOvlCall(-2, 3, 0x192);
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

void MBObjectSetup(s32 arg0, s16 arg1, s32 arg2, s32 unused) {
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
    MBModelInit();
    func_800F26E8_106308_shared_board();
    func_800E63F0_FA010_shared_board();
    func_800F25D8_1061F8_shared_board(0);
    func_800F25D8_1061F8_shared_board(1);
    func_800F25D8_1061F8_shared_board(2);
    func_800F25D8_1061F8_shared_board(3);
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        MBModelTempAllocFree(MBGetPlayerStruct(i)->player_obj);
        temp_v0 = MBGetPlayerStruct(i)->player_obj;
        temp_v0->flags |= 2;
        MBModelDispOn(MBGetPlayerStruct(i)->player_obj);
    }
    
    system = &GwSystem;
    playerIndex = system->current_player_index;
    if ((playerIndex < 4) && (GwPlayer[system->current_player_index].itemTurn != 0)) {
        func_800E6264_F9E84_shared_board();
        MBModelDispOff(GwPlayer[system->current_player_index].player_obj);
    }
    
    func_8001FDE8_209E8(MBGetPlayerStruct(0)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(1)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(2)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
    func_800F2A20_106640_shared_board();
    func_800DF854_F3474_shared_board();
    MBCoinChangeInit();
    func_800E4B60_F8780_shared_board();
    func_800F453C_10815C_shared_board();
    func_800DB5DC_EF1FC_shared_board();
    func_8005A6B0_5B2B0();
    func_800ECAB4_1006D4_shared_board();
    D_80105664_119284_shared_board = -1;
    D_800D1360.unk_20 = 0;
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

void MBExit(void) {
    func_800DCB8C_F07AC_shared_board();
    func_800F4730_108350_shared_board();
    func_800E4BA0_F87C0_shared_board();
    func_800E18FC_F551C_shared_board();
    func_800DF8B4_F34D4_shared_board();
    func_800F2A34_106654_shared_board();
    func_8005F524_60124();
    func_800E6404_FA024_shared_board();
    func_800F27C4_1063E4_shared_board();
    MBModelClose();
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

void MBSaveInit(void) {
    GW_PLAYER* player;
    s32 i, j;
    GW_SYSTEM* system = &GwSystem;
    GW_COMMON* common = &GwCommon;

    D_800D1240_D1E40 = 0;
    D_800D41C0_D4DC0 = 0;
    D_800CDD68 = 0;
    D_800CE208 = 0;
    D_800D03FC = 0;
    kakusiMasuItem = -1;
    kakusiMasuStar = -1;
    kakusiMasuCoin = -1;
    D_800D1708_D2308 = 0;
    D_800D4080_D4C80 = 0;
    D_800D2130 = 0;

    for (i = 0; i < 10; i++) {
        kakusiMasuCoinOld[i] =
        kakusiMasuStarOld[i] =
        kakusiMasuItemOld[i] = -1;
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

void MBNextPlayerTurn(void) {
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

s32 MBLast5Check(void) {
    GW_SYSTEM* system = &GwSystem;
    
    //TODO: is there another way to write this?
    if ((system->current_player_index == MB_MAX_PLAYERS-1) || (system->current_player_index < 0) || (system->current_player_index >= MB_MAX_PLAYERS)) {
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
        
        WipeCreateOut((s32) D_800D1360.unk_20, 0x10);
        HuPrcSleep(0x11);
        MBExit();
        
        if (D_80105664_119284_shared_board & 0x20) {
            D_800D6A48_D7648 = 1;
            if (GwSystem.current_board_index == 5) {
                _CheckFlag(9);
            }
            MBOvlCall(0x4F, 0, 0x4190);
            func_800F884C_10C46C_shared_board();
        }
        
        if (D_80105664_119284_shared_board & 1) {
            if (MBLast5Check() != 0) {
                MBOvlCall(0x51, 0, 0x192);
            }
            MBNextPlayerTurn();
        }
        
        if (D_80105664_119284_shared_board & 2) {
            for (i = 0; i< 4; i++) {
                if (D_801057E0_119400_shared_board[i].spaceType == 1) {
                    D_800CB8B1_CC4B1[i] = 0;
                } else {
                    D_800CB8B1_CC4B1[i] = 1;
                }
            }
            MBOvlCall(0x70, 0, 0x192);
        }
        
        if (D_80105664_119284_shared_board & 8) {
            MBOvlCall(D_80105668_119288_shared_board, D_8010566C_11928C_shared_board, 0x192);
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
    var_f4 = MBVecAngleGet(&sp10);
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

void MBBattleKuriboObjMain(omObjData* arg0) {
    mbBattleKuriboMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    mbBattleKuriboUpperMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
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
    i = sp10[MBRand(var_s1)];
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
    randRange = (minCoinAmount + MBRand(randRange)) + 1;
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
                func_8005FE54_60A54(mbDlgWinId, sp20[GwPlayer[i].pad]);
                sp18[GwPlayer[i].pad] = -1;
            }
        } else {
            sp18[GwPlayer[i].pad] = 0;
        }
    }

    if (var_s2 != 0) {
        func_8005B63C_5C23C(mbDlgWinId, 2, 2);
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
            func_8006010C_60D0C(mbDlgWinId, i);
        }
    }
    
    i = 0;
    do {
        i = func_8005E1D8_5EDD8(mbDlgWinId, i, 1);
    } while (arg0[i] == 0);
    return i;
}

void MBBattleKuriboEnd(void) {
    omDelObj(mbBattleKuriboObj);
    
    while (mbBattleKuriboMdl->unk30.x <= 120.0f) {
        HuPrcVSleep();
        mbBattleKuriboMdl->unk30.x += 3.0f;
        mbBattleKuriboUpperMdl->unk30.x += 3.0f;
    }
    
    MBModelKill(mbBattleKuriboMdl);
    MBModelKill(mbBattleKuriboUpperMdl);
}


void MBKettouResultExec(void) {
    char sp20[4];
    s32 temp_s1;
    s32 var_s0;
    GW_SYSTEM* system = &GwSystem;

    if ((GwPlayer[system->current_player_index].bonusCoin == 0) && (GwPlayer[GwSystem.unk_58].bonusCoin == 0)) {
        MBDlgWinExecY(6, 0x4006, 0x88);
        MBCoinChangeStatusCreate(system->current_player_index, GwSystem.playerIndexVisitingBowser);
        func_800F5BF4_109814_shared_board(system->current_player_index, GwSystem.playerIndexVisitingBowser, 0);
        MBCoinChangeStatusCreate(GwSystem.unk_58, GwSystem.playerIndexVisitingBowser);
        func_800F5BF4_109814_shared_board(GwSystem.unk_58, GwSystem.playerIndexVisitingBowser, 1);
    } else {
        var_s0 = (GwPlayer[system->current_player_index].bonusCoin != 0) ? system->current_player_index : GwSystem.unk_58;
        temp_s1 = GwSystem.playerIndexVisitingBowser * 2;
        sprintf(sp20, D_801025D0_1161F0_shared_board, temp_s1);
        MBDlgWinInsertCreateY(6, 0x4005, D_801014A0_1150C0_shared_board[GwPlayer[var_s0].chr], (u32)sp20, 0, 0, 0, 0x88);
        MBDlgWinClose();
        MBDlgWinKill();
        if (GwPlayer[system->current_player_index].bonusCoin != 0) {
            MBCoinChangeStatusCreate(system->current_player_index, temp_s1);
            func_800F5BF4_109814_shared_board(system->current_player_index, temp_s1, 1);
        }
        if (GwPlayer[GwSystem.unk_58].bonusCoin != 0) {
            MBCoinChangeStatusCreate(GwSystem.unk_58, temp_s1);
            func_800F5BF4_109814_shared_board(GwSystem.unk_58, temp_s1, 1);
        }        
    }
    
    MBBattleKuriboEnd();
}

void MBBattleKuriboStart(GW_PLAYER* arg0, s32 arg1) {
    mbBattleKuriboMdl = MBModelCreate(0xCU, 0);
    Hu3DModelScaleSet(mbBattleKuriboMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(mbBattleKuriboMdl->omObj1->model[0]);
    
    mbBattleKuriboMdl->flags |= 1;
    mbBattleKuriboUpperMdl = MBModelCreate(0x1F, 0);
    
    Hu3DModelScaleSet(mbBattleKuriboUpperMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&mbBattleKuriboMdl->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&mbBattleKuriboUpperMdl->coords, &arg0->player_obj->coords);
    
    mbBattleKuriboMdl->unk30.x = 120.0f;
    mbBattleKuriboUpperMdl->unk30.x = 122.0f;
    
    while (mbBattleKuriboMdl->unk30.x > 30.0f) {
        if (arg1 == 0) {
            HuPrcVSleep();
        }
        mbBattleKuriboMdl->unk30.x -= 1.0f;
        mbBattleKuriboUpperMdl->unk30.x -= 1.0f;
    }
    mbBattleKuriboObj = omAddObj(0x1F4, 0, 0, -1, MBBattleKuriboObjMain);
    mbBattleKuriboObj->rot.x = 180.0f;
}

s32 MBKettouPlayerBitGet(s32 arg0) {
    GW_SYSTEM* system =  &GwSystem;
    GW_PLAYER* player;
    s16 temp_s3;
    s16 var_s2;
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

void MBKettouComResultSet(void) {
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
    
    temp_a0_2 = MBRand(100.0f);
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

s32 MBKettouExec(GW_PLAYER* arg0, s32 arg1) {
    char sp20[MB_MAX_PLAYERS][16];
    u8 sp60[MB_MAX_PLAYERS+2]; //+2?
    s16 sp68[2];
    s32 sp84;
    
    Process* temp_s0_2;
    s32 temp_v1;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_s5;
    s32 var_a1;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s6;
    s32 var_s7;
    s32 i;
    s8* showComMinigames = &GwSystem.show_com_minigames;

    var_s7 = 0;
    var_s4 = 0;
    D_800D037C_D0F7C = 0;
    func_8004A670_4B270(0xF);
    HuPrcSleep(0x10);
    D_800C9930_CA530 = func_8004A5C4_4B1C4(0x3E);
    D_800D037C_D0F7C = 1;
    mbBattleKuriboMdl = MBModelCreate(0xCU, 0);
    Hu3DModelScaleSet(mbBattleKuriboMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(mbBattleKuriboMdl->omObj1->model[0]);
    mbBattleKuriboMdl->flags |= 1;
    mbBattleKuriboUpperMdl = MBModelCreate(0x1FU, 0);
    Hu3DModelScaleSet(mbBattleKuriboUpperMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&mbBattleKuriboMdl->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&mbBattleKuriboUpperMdl->coords, &arg0->player_obj->coords);
    mbBattleKuriboMdl->unk30.x = 120.0f;
    mbBattleKuriboUpperMdl->unk30.x = 122.0f;
    
    while (mbBattleKuriboMdl->unk30.x > 30.0f) {
        HuPrcVSleep();
        mbBattleKuriboMdl->unk30.x -= 1.0f;
        mbBattleKuriboUpperMdl->unk30.x -= 1.0f;
    }
    
    mbBattleKuriboObj = omAddObj(0x1F4, 0U, 0U, -1, MBBattleKuriboObjMain);
    mbBattleKuriboObj->rot.x = 180.0f;
    HuAudFXPlay(0x25B);
    var_s1 = 0;
    
    if (GwPlayer[arg0->turn].coin != 0) {
        var_s6 = 0;
        
        do { //reg alloc hack
        // Count valid duel targets
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if ((GwSystem.unk_58 >> i) & 1 && GwPlayer[i].coin != 0) {
                var_s7++; //valid duel target
                var_s4 = i;
                var_s1++;
                sp20[var_s4][0] = 8;
                sp60[var_s4] = 1;
                var_s6 |= 1 << var_s4;
            } else {
                sp20[i][0] = 1; //invalid duel target (disable prompt?)
                sp60[i] = 0;
            }
            
            func_800E2260_F5E80_shared_board(i, &sp20[i][1]);
        }
        } while(0);
        
        if (var_s1 == 0) {
            MBDlgWinExecY(6, 0x4002, 0x88);
            MBBattleKuriboEnd();
            D_800D037C_D0F7C = 0;
            func_8004A7C4_4B3C4(0x1E);
            HuPrcSleep(0xF);
            func_8004A72C_4B32C(0x1E);
            D_800D037C_D0F7C = 1;
            D_800C9930_CA530 = -1;
            D_800CE206 = 0;
            omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
            HuPrcSleep(0x1F);
            return 0;
        } else {
            MBDlgWinExecY(6, 0x4000, 0x88);
        }
    } else {
        MBDlgWinExecY(6, 0x4001, 0x88);
        MBBattleKuriboEnd();
        D_800D037C_D0F7C = 0;
        func_8004A7C4_4B3C4(0x1E);
        HuPrcSleep(0xF);
        func_8004A72C_4B32C(0x1E);
        D_800D037C_D0F7C = 1;
        D_800C9930_CA530 = -1;
        D_800CE206 = 0;
        omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
        HuPrcSleep(0x1F);
        return 0;
    }

    // Target selection loop
    while (1) {
        if (var_s7 >= 2 || (GwSystem.playerIndexVisitingBowser & 0x8000)) {
            tempLabel:
            //?
            sp60[4] = 1;
            sp60[5] = 1;
            MBDlgWinInsertCreate(6, 0x5C02, (u32) sp20[0], (u32) sp20[1], (u32) sp20[2], (u32) sp20[3], 0);
            var_s4 = func_800FA104_10DD24_shared_board(sp60);
            MBDlgWinClose();
            MBDlgWinKill();

            switch (var_s4) {
            case 4:
                i = 0;
                var_s1 = var_s7;
                for (i = 0; i < MB_MAX_PLAYERS; i++) {
                    if (var_s6 & (1 << i)) {
                        if (var_s1-- != 0) {
                            break;
                        }
                    }
                }
                var_s4 = i;
                break;
            case 5:
                D_800CDD58_CE958 = 1;
                D_800D037C_D0F7C = 0;
                omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
                func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
                omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
                D_800CDD58_CE958 = 0;
                D_800D037C_D0F7C = 1;
                func_800FC8A4_1104C4_shared_board();
                goto tempLabel; // Go back to selection menu
            }
        }
        
        var_s3 = 0;
        break; // Exit selection loop
    }
    
    // Coin wager selection
    sprintf(sp20[0], D_801025D0_1161F0_shared_board, 0x3E7);
    func_8006022C_60E2C((u32)sp20[0], 0);
    func_80060394_60F94(1, sp68, 0x4003);
    sp84 = MBWinCreate(6, sp68, 0x64);
    
    var_s1_3 = 1;
    
    var_s5 = 1;
    
    if (GwPlayer[GwSystem.current_player_index].coin <= GwPlayer[var_s4].coin) {
        var_s2 = GwPlayer[GwSystem.current_player_index].coin;
    } else {
        var_s2 = GwPlayer[var_s4].coin;
    }
    
    sprintf(sp20[0], D_801025D0_1161F0_shared_board, var_s1_3);
    func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
    func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
    func_80061388_61F88(sp84);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        var_s3 = func_800F9F84_10DBA4_shared_board(var_s4);
        do { //reg alloc hack
        if (var_s2 < var_s3) {
            var_s3 = var_s2;
        }
        if (var_s3 <= 0) {
            var_s3 = 1;
        }
        } while(0);
    }
    
    var_s0_3 = 5;
    
    // Coin amount input loop
    while (1) {
        if (func_800F2198_105DB8_shared_board(-1) == 0) {
            // Player controlled input
            if (D_800C9520_CA120[GwPlayer[GwSystem.current_player_index].pad] & 0x8000) { //?
                break; // Player confirmed selection
            }
            
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x800) {
                var_s1_3++;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x400) {
                var_s1_3--;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x200) {
                var_s1_3 -= 0xA;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x100) {
                var_s1_3 += 0xA;
            }
        } else {
            var_s0_3--;
            // AI controlled input
            
            if (var_s0_3 == -1) {
                if (var_s3 != var_s1_3) {
                    if ((var_s3 % 10) != (var_s1_3 % 10)) {
                        var_s1_3 += 1;
                        var_s0_3 = 5;
                    } else if ((var_s3 / 10) != (var_s1_3 / 10)) {
                        var_s1_3 += 0xA;
                        var_s0_3 = 5;
                    }
                } else {
                    break; // AI finished selecting amount
                }
            }
        }
            
        // Clamp value to valid range
        if (var_s5 == 1 && var_s1_3 < 1) {
            var_s1_3 = var_s2;
        }
        if (var_s5 == var_s2 && var_s2 < var_s1_3) {
            var_s1_3 = 1;
        }
        if (var_s1_3 <= 0) {
            var_s1_3 = 1;
        }
        if (var_s2 < var_s1_3) {
            var_s1_3 = var_s2;
        }
        
        if (var_s5 != var_s1_3) {
            HuAudFXPlay(0x246);
        }
        
        var_s5 = var_s1_3;
        
        sprintf(sp20[0], D_801025D0_1161F0_shared_board, var_s1_3);
        func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
        func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
        
        
        HuPrcVSleep();
    }
    
    HuAudFXPlay(0x247);
    func_80061A5C_6265C(sp84, 0);
    func_8005F364_5FF64(sp84);
    HuPrcSleep(0xA);
    MBCoinChangeStatusCreate(GwSystem.current_player_index, -var_s1_3);
    func_800F5BF4_109814_shared_board(GwSystem.current_player_index, -var_s1_3, 0);
    MBCoinChangeStatusCreate(var_s4, -var_s1_3);
    func_800F5BF4_109814_shared_board(var_s4, -var_s1_3, 1);
    HuPrcSleep(0x1E);
    MBDlgWinExecY(6, 0x4004, 0x88);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        if ((func_800F2198_105DB8_shared_board(var_s4) != 0)) {
            if (*showComMinigames != 0) {
                GwSystem.unk_58 = var_s4;
                GwSystem.playerIndexVisitingBowser = var_s1_3;
                return 2;                
            }
        }
    }
    
    D_800D037C_D0F7C = 0;
    func_800F7108_10AD28_shared_board();
    temp_s0_2 = func_800E11C0_F4DE0_shared_board(GwSystem.current_player_index, var_s4);
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0_2);
    HuPrcChildWait();
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        GwPlayer[i].group = 2;
    }

    arg0->group = 0;
    GwPlayer[var_s4].group = 1;
    GwSystem.unk_58 = var_s4;
    GwSystem.playerIndexVisitingBowser = var_s1_3;

    D_800D1240_D1E40 = (arg1 == 0) ? 8 : 9;
    
    D_80105664_119284_shared_board = 2;
    D_80105666_119286_shared_board = 1;
    D_800D1380_D1F80 = 8;
    return 1;
}

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

extern s16 D_800CC698_CD298;
void func_800ECA38_100658_shared_board(void);              /* extern */
extern u16 D_80101DE0_115A00_shared_board[];
extern u16 D_80101E44_115A64_shared_board[];
extern u8 D_80101E04_115A24_shared_board[3][5];
extern u8 D_80101E14_115A34_shared_board[3][5];
extern u8 D_80101E24_115A44_shared_board[3][5];
extern u8 D_80101E34_115A54_shared_board[3][5];
extern u8 (*D_80101E50_115A70_shared_board[])[3][5];
void func_800EC980_1005A0_shared_board(s32, s32, char*, s32, s32, s32, s32, s32);
#ifdef NON_EQUIVALENT //close, but not quite matching in logic
s32 func_800FB624_10F244_shared_board(GW_PLAYER* arg0) {
    char sp20[16];
    omObjData* sp34;
    omObjData* kuriboObj;
    s32 sp3C;
    s32 sp44;
    s32 sp4C;
    Object* temp_v0;
    Object* temp_v0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f22;
    f32 var_f22_2;
    omObjData* temp_v0_3;
    s32 temp_a1;
    s32 temp_s5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s2_2;
    s32 var_s4;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 turnTier;
    s32 temp_s5_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s0_6;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s6;
    s32 var_s6_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_s4_2;
    void* temp_v0_4;
    void* temp_v0_5;
    s32 i, j;
    
    s32 var_s5;
    
    D_800D037C_D0F7C = 0;
    func_8004A670_4B270(0xF);
    HuPrcSleep(0x10);
    D_800C9930_CA530 = func_8004A5C4_4B1C4(0x3E);
    D_800D037C_D0F7C = 1;
    
    mbBattleKuriboMdl = MBModelCreate(0xCU, 0);
    Hu3DModelScaleSet(mbBattleKuriboMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(mbBattleKuriboMdl->omObj1->model[0]);
    
    mbBattleKuriboMdl->flags |= 1;
    mbBattleKuriboUpperMdl = MBModelCreate(0x1F, 0);
    
    Hu3DModelScaleSet(mbBattleKuriboUpperMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&mbBattleKuriboMdl->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&mbBattleKuriboUpperMdl->coords, &arg0->player_obj->coords);
    
    mbBattleKuriboMdl->unk30.x = 120.0f;
    mbBattleKuriboUpperMdl->unk30.x = 122.0f;
    
    while (mbBattleKuriboMdl->unk30.x > 30.0f) {
        HuPrcVSleep();
        mbBattleKuriboMdl->unk30.x -= 1.0f;
        mbBattleKuriboUpperMdl->unk30.x -= 1.0f;
    }
    
    kuriboObj = omAddObj(0x1F4, 0, 0, -1, MBBattleKuriboObjMain);
    kuriboObj->rot.x = 180.0f;

    for (i = 0, var_s0 = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].coin >= 10) {
            break;
        }
    }
    
    HuAudFXPlay(0x25B);
    var_s6 = 0;
    if (i == 4) {
        func_800EC5EC_10020C_shared_board(6, 0x1301, 0x88);
    } else {
        turnTier = BoardGetTurnTier(-1);
        var_s4 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if (var_s4 < GwPlayer[i].coin) {
                var_s4 = GwPlayer[i].coin;
            }
        }
        
        for (j = 0; j < 3; j++) {
            if (var_s4 < D_80101DE0_115A00_shared_board[j]) {
                break;
            }
        }

        temp_s2 = MBRand(100.0f);
        for (i = 0; i < 5; i++) {
            if (temp_s2 < (*D_80101E50_115A70_shared_board[j])[turnTier][i]) {
                break;
            }
        }

        var_s4 = D_80101E44_115A64_shared_board[i];
        var_s6_2 = i;
        sp3C = RNGPercentChance(0xA);
        if ((turnTier == 0) && ((RNGPercentChance(0x1E)) != 0)) {
            var_s6_2 = 0;
            var_s4 = D_80101E44_115A64_shared_board[0];
        }
        func_800EC980_1005A0_shared_board(6, 0x1300, NULL, 0, 0, 0, 0, 0x88);
        func_800ECA38_100658_shared_board();
        MBDlgWinClose();
        MBDlgWinKill();
        temp_s5 = HuSprGrpCreate(2U, 2U);
        temp_v0_4 = DataRead(0x130113);
        sp44 = func_80055810_56410(temp_v0_4);
        DataClose(temp_v0_4);
        func_80055024_55C24(temp_s5, 0, sp44, 0);
        HuSprPriSet(temp_s5, 0, 0x14U);
        func_800550F4_55CF4(temp_s5, 0, 0);
        HuSprAttrSet(temp_s5, 0, 0x1000);
        func_80054904_55504(temp_s5, 0, 0xA0, 0x78);
        func_800554C4_560C4(temp_s5, 0, -1);
        temp_v0_5 = DataRead(0x130114);
        sp4C = func_80055810_56410(temp_v0_5);
        DataClose(temp_v0_5);
        func_80055024_55C24(temp_s5, 1, sp4C, 0);
        HuSprPriSet(temp_s5, 1, 0xAU);
        func_800550F4_55CF4(temp_s5, 1, 1);
        HuSprAttrSet(temp_s5, 1, 0x1000);
        func_80054904_55504(temp_s5, 1, -0x28, 0x10);
        func_800554C4_560C4(temp_s5, 1, 0);
        
        for (var_f20 = 0.0f; var_f20 < 1.0f; var_f20 += 0.1f) {
            HuSprScaleSet(temp_s5, 0, var_f20, var_f20);
            HuSprScaleSet(temp_s5, 1, var_f20, var_f20);
            HuPrcVSleep();            
        }
        
        HuSprScaleSet(temp_s5, 0, 1.0f, 1.0f);
        HuSprScaleSet(temp_s5, 1, 1.0f, 1.0f);
        var_s0_4 = 0;  /* current index */
        var_s3 = 0;    /* tick counter */
        var_s1_2 = 1;  /* spin speed */
        var_s2 = 0;    /* slowdown counter */
    
        for (;; HuPrcVSleep()) {
            /* Update sprite to current index */
            func_80055024_55C24(temp_s5, 1, sp4C, var_s0_4);
    
            /* Count frames before next tick */
            var_s3++;
            if (var_s3 > var_s1_2) {
                var_s3 = 0;
                HuAudFXPlay(0x116);
    
                var_s0_4++;
                if (var_s0_4 >= 5) {
                    var_s0_4 = 0;
                }
            }
    
            /* Slow down the spinner gradually */
            var_s2++;
            if (var_s2 < 9) {
                continue;
            }
            var_s2 = 0;
            var_s1_2++;
            if (var_s1_2 <= 6) {
                continue;
            }
            var_s1_2 = 6;
            
            /* Check stop conditions */
            if (sp3C != 0) {
                /* Overshoot case (10% RNG) */
                if (var_s6_2 != 4) {
                    if (var_s0_4 == (var_s6_2 + 1)) {
                        break;
                    }
                } else {
                    if (var_s0_4 == 0) {
                        break;
                    }
                }
            } else {
                /* Normal stop */
                if (var_s0_4 == var_s6_2) {
                    break;
                }
            }
        }
        func_80055024_55C24(temp_s5, 1, sp4C, var_s0_4);
        HuPrcSleep(0x14);
        if (sp3C != 0) {
            HuAudFXPlay(0x116);
            func_80055024_55C24(temp_s5, 1, sp4C, var_s6_2);
            HuPrcSleep(0xA);
        }

        if (var_s6_2 != 0) {
            HuAudFXPlay(0x117);
        } else {
            HuAudFXPlay(0x118);
        }
        
        func_800F6A88_10A6A8_shared_board(temp_s5, 0);
        func_80054904_55504(temp_s5, 1, 0x78, 0x88);
        if (var_s6_2 == 4) {
            for (var_f22_2 = 0.0f; var_f22_2 <= 1080.0f; var_f22_2 += 50.0f) {
                temp_f20_3 = (HuMathSin(var_f22_2) * 0.5f) + 1.0f;
                HuSprScaleSet(temp_s5, 1, temp_f20_3, temp_f20_3);
                HuPrcVSleep();                
            }

            for (; var_f22_2 <= 1440.0f; var_f22_2 += 40.0f) {
                temp_f20_3 = (HuMathSin(var_f22_2) * 0.5f) + 1.0f;
                HuSprScaleSet(temp_s5, 1, temp_f20_3, temp_f20_3);
                HuPrcVSleep();               
            }
        } else {
            for (var_f22_2 = 0.0f; var_f22_2 <= 720.0f; var_f22_2 += 40.0f) {
                temp_f20_3 = (HuMathSin(var_f22_2) * 0.5f) + 1.0f;
                HuSprScaleSet(temp_s5, 1, temp_f20_3, temp_f20_3);
                HuPrcVSleep();                
            }

            for (; var_f22_2 <= 1080.0f; var_f22_2 += 30.0f) {
                temp_f20_3 = (HuMathSin(var_f22_2) * 0.5f) + 1.0f;
                HuSprScaleSet(temp_s5, 1, temp_f20_3, temp_f20_3);
                HuPrcVSleep();               
            }
        }
        HuSprScaleSet(temp_s5, 1, 1.0f, 1.0f);
        func_800F6A88_10A6A8_shared_board(temp_s5, 2U);
        func_80054904_55504(temp_s5, 1, -0x28, 0x10);
        HuPrcSleep(0x1E);
        
        for (var_f20 = 1.0f; var_f20 > 0.0f; var_f20 -= 0.1f) {
            HuSprScaleSet(temp_s5, 0, var_f20, var_f20);
            HuSprScaleSet(temp_s5, 1, var_f20, var_f20);
            HuPrcVSleep();            
        }

        HuSprScaleSet(temp_s5, 0, 0.0f, 0.0f);
        HuSprScaleSet(temp_s5, 1, 0.0f, 0.0f);
        HuSprGrpKill(temp_s5);
        HuSprKill(sp44);
        HuSprKill(sp4C);
        HuPrcSleep(3);

        if (var_s4 == 0) {
            var_s3_2 = -1;
            var_s6 = 0;
            func_800EC980_1005A0_shared_board(6, 0x1304, NULL, 0, 0, 0, 0, 0x88);
            func_800ECA38_100658_shared_board();
            MBDlgWinClose();
            MBDlgWinKill();
        } else {
            var_s6 = 1;
            var_s3_2 = -1;
            var_a0_2 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                if (GwPlayer[i].coin >= var_s4) {
                    var_s3_2 = i;
                    break;
                } else {
                    if (var_a0_2 < GwPlayer[i].coin) {
                        var_s3_2 = i;
                        var_a0_2 = GwPlayer[i].coin;
                    }
                }
            }
            
            var_s2_2 = 0; //coin total
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                if (GwPlayer[i].coin < var_s4) {
                    GwPlayer[i].checkCoin = GwPlayer[i].coin;
                    var_s2_2 += GwPlayer[i].coin;
                    MBCoinChangeStatusCreate(i, -GwPlayer[i].coin);
                    if (i == var_s3_2) {
                        func_800F5BF4_109814_shared_board(i, -GwPlayer[i].coin, 1);
                    } else {
                        func_800F5BF4_109814_shared_board(i, -GwPlayer[i].coin, 0);
                    }
                } else {
                    GwPlayer[i].checkCoin = var_s4;
                    var_s2_2 += var_s4;
                    MBCoinChangeStatusCreate(i, -var_s4);
                    if (i == var_s3_2) {
                        func_800F5BF4_109814_shared_board(i, -var_s4, 1);
                    } else {
                        func_800F5BF4_109814_shared_board(i, -var_s4, 0);
                    }
                }
            }

            HuPrcSleep(0x1E);
            sprintf(sp20, D_801025D0_1161F0_shared_board, var_s2_2);
            if (var_s2_2 < (var_s4 * 4)) {
                func_800EC980_1005A0_shared_board(6, 0x1303, sp20, 0, 0, 0, 0, 0x88);
                func_800ECA38_100658_shared_board();
            } else {
                func_800EC980_1005A0_shared_board(6, 0x1302, sp20, 0, 0, 0, 0, 0x88);
            }
            func_800ECA38_100658_shared_board();
            MBDlgWinClose();
            MBDlgWinKill();
            D_800CC698_CD298 = var_s2_2;
        }
    }
    
    if (var_s6 == 0) {
        omDelObj(kuriboObj);
        while (mbBattleKuriboMdl->unk30.x <= 120.0f) {
            HuPrcVSleep();
            mbBattleKuriboMdl->unk30.x += 3.0f;
            mbBattleKuriboUpperMdl->unk30.x += 3.0f;
        }
        MBModelKill(mbBattleKuriboMdl);
        MBModelKill(mbBattleKuriboUpperMdl);
        D_800D037C_D0F7C = 0;
        func_8004A7C4_4B3C4(0x1E);
        HuPrcSleep(0xF);
        func_8004A72C_4B32C(0x1E);
        D_800D037C_D0F7C = 1;
        D_800C9930_CA530 = -1;
        D_800CE206 = 0;
        omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
        HuPrcSleep(2);
        return 0;
    } else {
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FB624_10F244_shared_board);
#endif

void func_800FC3D0_10FFF0_shared_board(void) {
    s32 var_a0;
    s32 var_s1;
    s32 i, j;

    MBDlgWinExecY(6, 0x1305, 0x88);
    var_s1 = 0;
    var_a0 = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (var_a0 < GwPlayer[i].checkCoin) {
            var_a0 = GwPlayer[i].checkCoin;
            var_s1 = i;
        }
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].checkCoin != 0) {
            MBCoinChangeStatusCreate(i, GwPlayer[i].checkCoin);
        }
        if (i == var_s1) {
            func_800F5BF4_109814_shared_board(i, GwPlayer[i].checkCoin, 1);
        } else {
            if (GwPlayer[i].checkCoin != 0) {
                func_800F5BF4_109814_shared_board(i, GwPlayer[i].checkCoin, 0);
            }
        }
    }

    MBBattleKuriboEnd();
}


void func_800FC4E0_110100_shared_board(void) {
    if (GwPlayer[GwSystem.playerIndexVisitingBowser].gameCoin != 0) {
        if (GwPlayer[GwSystem.playerIndexVisitingBowser].bonusCoin != 0) {
            MBCoinChangeStatusCreate(GwSystem.playerIndexVisitingBowser, GwPlayer[GwSystem.playerIndexVisitingBowser].gameCoin * GwPlayer[GwSystem.playerIndexVisitingBowser].bonusCoin);
            func_800F5BF4_109814_shared_board(GwSystem.playerIndexVisitingBowser, GwPlayer[GwSystem.playerIndexVisitingBowser].gameCoin * GwPlayer[GwSystem.playerIndexVisitingBowser].bonusCoin, 1);
        }
    }
    HuPrcSleep(30);
}

void MBBlockMasuUpdate(void) {
    s32 i;

    if (GWBoardFlagCheck(0xF)) {
        while (kakusiMasuCoin == -1 || kakusiMasuCoin == kakusiMasuStar || kakusiMasuCoin == kakusiMasuItem) {
            kakusiMasuCoin = MBMasuKakusiBlockGet(D_800D03FC);
            D_800D03FC++;
            for (i = 0; i < ARRAY_COUNT(kakusiMasuCoinOld); i++) {
                if (kakusiMasuCoin == kakusiMasuCoinOld[i]) {
                    break;
                }
            }
            if (i != ARRAY_COUNT(kakusiMasuCoinOld)) {
                kakusiMasuCoin = -1;
            }
        }
        while (kakusiMasuStar == -1 || kakusiMasuCoin == kakusiMasuStar || kakusiMasuItem == kakusiMasuStar) {
            kakusiMasuStar = MBMasuKakusiBlockGet(D_800CE208);
            D_800CE208++;
            for (i = 0; i < ARRAY_COUNT(kakusiMasuStarOld); i++) {
                if (kakusiMasuStar == kakusiMasuStarOld[i]) {
                    break;
                }
            }
            if (i != ARRAY_COUNT(kakusiMasuStarOld)) {
                kakusiMasuStar = -1;
            }
        }
        
        while (kakusiMasuItem == -1 || kakusiMasuCoin == kakusiMasuItem || kakusiMasuStar == kakusiMasuItem) {
            kakusiMasuItem = MBMasuKakusiBlockGet(D_800CDD68);
            D_800CDD68++;
            for (i = 0; i < ARRAY_COUNT(kakusiMasuItemOld); i++) {
                if (kakusiMasuItem == kakusiMasuItemOld[i]) {
                    break;
                }
            }
            if (i != ARRAY_COUNT(kakusiMasuItemOld)) {
                kakusiMasuItem = -1;
            }
        }
    }
}

void func_800FC7C8_1103E8_shared_board(void) {
    s32 var_s0 = 0xA0;

    if (D_80101E60_115A80_shared_board == NULL) {
        D_80101E60_115A80_shared_board = func_800E210C_F5D2C_shared_board(2, 0xA0, 1);
    }
    if ((D_80101E64_115A84_shared_board == NULL) && !(GwSystem.cur_player_used_item & 1)) {
        var_s0 += 14;
        D_80101E64_115A84_shared_board = func_800E210C_F5D2C_shared_board(0xD, var_s0, 1);
    }
    if (D_80101E68_115A88_shared_board == NULL) {
        var_s0 += 14;
        D_80101E68_115A88_shared_board = func_800E210C_F5D2C_shared_board(3, var_s0, 1);
    }
    if (D_80101E6C_115A8C_shared_board == NULL) {
        var_s0 += 14;
        D_80101E6C_115A8C_shared_board = func_800E210C_F5D2C_shared_board(0xB, var_s0, 1);
    }
}

void func_800FC8A4_1104C4_shared_board(void) {
    if (D_80101E60_115A80_shared_board != NULL) {
        MBHelpWinKill(D_80101E60_115A80_shared_board);
        D_80101E60_115A80_shared_board = NULL;
    }
    if (D_80101E64_115A84_shared_board != NULL) {
        MBHelpWinKill(D_80101E64_115A84_shared_board);
        D_80101E64_115A84_shared_board = NULL;
    }
    if (D_80101E68_115A88_shared_board != NULL) {
        MBHelpWinKill(D_80101E68_115A88_shared_board);
        D_80101E68_115A88_shared_board = NULL;
    }
    if (D_80101E6C_115A8C_shared_board != NULL) {
        MBHelpWinKill(D_80101E6C_115A8C_shared_board);
        D_80101E6C_115A8C_shared_board = NULL;
    }
}

void func_800FC938_110558_shared_board(void) {
    D_800D1240_D1E40 = 0xA;
    D_800D1380_D1F80 = 8;
    func_800FC8A4_1104C4_shared_board();
}

void func_800FC968_110588_shared_board(void) {
    D_800D1240_D1E40 = 0xC;
    D_800D1380_D1F80 = 8;
    func_800FC8A4_1104C4_shared_board();
}

void func_800FC998_1105B8_shared_board(void) {
    D_800D1240_D1E40 = 0xD;
    D_80105664_119284_shared_board = 2;
    D_80105666_119286_shared_board = 1;
    D_800D1380_D1F80 = 9;
    func_800FC8A4_1104C4_shared_board();
}

void func_800FC9E0_110600_shared_board(void) {
    D_800D1240_D1E40 = 0xB;
    func_800FC8A4_1104C4_shared_board();
    func_800FF7C4_1133E4_shared_board(0x52, 0, 0xB);
}

void func_800FCA14_110634_shared_board(void) {
    D_800D1240_D1E40 = 0xF;
    D_800D1380_D1F80 = 0xB;
    D_80105666_119286_shared_board = 0;
    func_800FC8A4_1104C4_shared_board();
}

void func_800FCA4C_11066C_shared_board(void) {
    D_800D1240_D1E40 = 0xE;
    D_800D1380_D1F80 = 3;
    func_800FC8A4_1104C4_shared_board();
}

const char D_801025D0_1161F0_shared_board[] = "%d";

void MBMain(void) {
    Process* temp_s6;
    s32 var_s1;
    s16 temp_v0_2;
    s32 temp_v0_3;
    GW_PLAYER* temp_v0_4;
    s16 var_s5; //
    SpaceData* space;
    Vec sp20;
    Process* temp_s1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    s32 temp_v0_8;
    Process* temp_s1_2;
    s32 temp_v0_9;
    s32 temp_v0_10;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_16;
    s32 var_v1;
    s32 var_s0;
    s16 temp_v0_18;
    GW_PLAYER* temp_s0_2;
    s32 temp_v0_20;
    s32 temp_s2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_a0;
    s32 temp_s2_2;
    void* temp_v0_21;
    s32 temp_s3_3;
    Object* temp_v0_22;
    Process* temp_s1_5;
    s32 temp_a0_4;
    s32 var_v1_3;
    s32 temp_v1_8;
    s32 temp_a0_3;
    s32 var_s1_12;
    s32 var_s0_2;
    GW_SYSTEM* system = &GwSystem;
    s16 sp30[2];
    s16 sp38[2];
    s16 sp40[2];
    char sp48[16]; //unknown buffer size
    s32 flag;
    s32 state;
    s32 eight;

    temp_s6 = HuPrcCurrentGet();
    
    while (1) {  // Main game loop
        if (D_800D1240_D1E40 < 2U && system->current_player_index == 0) {
            // Initialize all player colors
            for (var_s1 = 0; var_s1 < 4; var_s1++) {
                MBGetPlayerStruct(var_s1)->color = 0;
                func_800F70F8_10AD18_shared_board();
            }
            
            // Check if we're in the last 5 turns
            if (system->total_turns >= 0) {
                short temp_v0 = (system->total_turns - system->current_turn) + 1;
                if (temp_v0 < 6) {
                    if (temp_v0 > 0) {
                        GWBoardFlagSet(2);  // Last 5 turns flag
                    }
                }
            }
            
            if (!GWBoardFlagCheck(1) && system->current_turn >= 2) {
                switch (system->save_mode) {
                    case 1:
                        system->save_mode = 2;
                    case 0:
                        _SetFlag(0);
                        GWBoardFlagSet(0);
                        
                        func_80060394_60F94(1, sp30, 0x5900);
                        temp_v0_2 = func_8005A968_5B568(0, 0, sp30[0], sp30[1], 0, 2);
                        func_8005BEE0_5CAE0(temp_v0_2, 0);
                        func_8005B43C_5C03C(temp_v0_2, 0x5900, -1, -1);
                        func_8005BDFC_5C9FC(temp_v0_2, 0);
                        
                        while (func_8005E0C0_5ECC0(temp_v0_2) != 0) {
                            HuPrcVSleep();
                        }
                        
                        if (system->playMode & 4) {
                            _SetFlag(0x18);
                            _SetFlag(0x28);
                            func_8005035C_50F5C(1);
                        } else {
                            _SetFlag(0x16);
                            func_800500E0_50CE0(1);
                        }
                        
                        func_8005F364_5FF64(temp_v0_2);
                        func_80060394_60F94(1, sp30, 0x5901);
                        temp_v0_3 = func_8005A968_5B568(0, 0, sp30[0], sp30[1], 0, 2);
                        func_8005BEE0_5CAE0(temp_v0_3, 0);
                        func_8005B43C_5C03C(temp_v0_3, 0x5901, -1, -1);
                        func_8005BDFC_5C9FC(temp_v0_3, 0);
                        HuPrcSleep(0xF);
                        func_8005F364_5FF64(temp_v0_3);
                        break;
                }
            }
            
            GWBoardFlagClear(1);
            D_800A12D4 = 0;
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(-2, 7);
        }
        

        D_800A12D4 = 1;
        
        var_s1 = 0;
        eight = 8; //definitely a hack
        for (; var_s1 < 4; var_s1++) {
            func_800F4798_1083B8_shared_board(var_s1, MBGetPlayerStruct(var_s1)->color);
            func_800F96E0_10D300_shared_board(var_s1, 1);
            
            state = D_800D1240_D1E40;
    
            if (state == eight) {
                // skip
            } else if (state < 8) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            } else if (state >= 0x10) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            } else if (state < 0xA) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            }
        }
        
        MBBlockMasuUpdate();
        temp_v0_4 = MBGetPlayerStruct(system->current_player_index);
        var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
        space = MBMasuGet(var_s5);
        func_800EBCBC_FF8DC_shared_board(var_s5);

        state = D_800D1240_D1E40;

        if (state < 2U) {
            goto temp;
        }
        
        switch (state) {
            case 8:
            case 9:
            case 0xC:
                MBBattleKuriboStart(temp_v0_4, 1);
                break;
        
            case 0x12:
                var_s1 = 0;
                for (; var_s1 < 4; var_s1++) {
                    if (GwPlayer[var_s1].bonusCoin != 3)
                        break;
                }
                if (var_s1 >= 4) {
                    MBBattleKuriboStart(temp_v0_4, 1);
                }
                break;
        
            default:
                break;
        }

        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        
        D_800D037C_D0F7C = 1;
        
        switch (D_800D1240_D1E40) {
        case 12:
            MBKettouResultExec();
            func_800F88D0_10C4F0_shared_board();
            goto label654;

        case 13:  // Bank space
            func_800FC4E0_110100_shared_board();
            
                
        case 15:  // Some event
            func_800F88D0_10C4F0_shared_board();
            goto label654;
        case 14:
            MBItemKoopaNKinokoExec();
            MBItemKoopaRKinokoExec();
            func_800F88D0_10C4F0_shared_board();
            goto label654;
            
        case 11:
            D_800D1240_D1E40 = 0xA;
            func_800E4954_F8574_shared_board();
            func_800ECC0C_10082C_shared_board(&sp20);
            func_800ED128_100D48_shared_board(&temp_v0_4->player_obj->unk18, &sp20, 
                                              &temp_v0_4->player_obj->unk18, 8);
            HuPrcSleep(8);
            goto label654;

            temp:
            func_800EBAC8_FF6E8_shared_board(-4, 7);
            // Hide all player models
            func_8001FDE8_209E8(MBGetPlayerStruct(0)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(1)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(2)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
            
            func_800F2304_105F24_shared_board(-1, -1, 2);
            func_800F915C_10CD7C_shared_board(1);
            
            if (system->current_player_index == 4) {
                func_800E648C_FA0AC_shared_board();
            }
            
            // Camera setup
            if (D_800A12CC == 0) {
                D_800C9938_CA538 = 1.0f;
                func_800E8DD4_FC9F4_shared_board(1.0f);
                HuPrcChildLink(temp_s6, func_800F29EC_10660C_shared_board());
            } else if (system->current_player_index == 4 || system->current_player_index == 0) {
                D_800C9938_CA538 = 1.0f;
                func_800E8DD4_FC9F4_shared_board(1.0f);
                HuPrcChildLink(temp_s6, func_800F29EC_10660C_shared_board());
            } else {
                D_800C9938_CA538 = 1.0f;
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.0f));
            }
            
            HuPrcChildWait();
        default:
            HuPrcSleep(4);
            func_800FF900_113520_shared_board(-1, 3);
            HuPrcChildLink(temp_s6, func_800E5CE0_F9900_shared_board(system->current_player_index));
            HuPrcChildWait();
            func_800EBAC8_FF6E8_shared_board(-5, 7);
            goto label654;
        case 6:
        case 16:
            HuPrcSleep(0x1E);
            goto label2444;

        case 9:
            MBKettouResultExec();
            goto label2444;

        case 10:
            label654:
            // STATE 10: Dice roll and movement
            func_800FC7C8_1103E8_shared_board();
            D_800C9938_CA538 = 1.3f;
            HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
            temp_s1 = func_800DD6C4_F12E4_shared_board(system->current_player_index);
            HuPrcChildWait();
            HuPrcSleep(1);
            
            if (system->current_player_index != 4) {
                D_800CDD58_CE958 = 1;
                D_800D037C_D0F7C = 1;
                D_800CDD64_CE964 = 1;
                D_800CC4A0_CD0A0 = 1;
            }
        
            HuPrcChildLink(temp_s6, temp_s1);
            HuPrcChildWait();
            func_800FC8A4_1104C4_shared_board();
            
            D_800CDD58_CE958 = 0;
            D_800CDD64_CE964 = 0;
            D_800D41C0_D4DC0 = func_800DCD9C_F09BC_shared_board(system->current_player_index);
            
            if (D_80105660_119280_shared_board == 0 && (temp_v0_4->rev & 0x80)) {
                temp_v0_4->nlink = temp_v0_4->blink;
                temp_v0_4->nidx = temp_v0_4->bidx;
                temp_v0_4->rev ^= 1;
            }
        
            var_s5 = func_800EBCC8_FF8E8_shared_board();
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 9);
            func_800F2304_105F24_shared_board(-1, 0, 2);
        
            while (D_800D41C0_D4DC0 != 0) {
                short temp_s3;
                short temp_s0;
                func_800EBAC8_FF6E8_shared_board(var_s5, 8);
                
                // Save current position
                temp_s3 = temp_v0_4->clink;
                temp_s0 = temp_v0_4->cidx;
                
                // Update to next position
                temp_v0_4->clink = temp_v0_4->nlink;
                temp_v0_4->cidx = temp_v0_4->nidx;
                
                // Update walk speed animations
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    func_800F96E0_10D300_shared_board(var_s1, (system->walk_speed * 5) + 5);
                }
                
                // Restore position temporarily
                temp_v0_4->clink = temp_s3;
                temp_v0_4->cidx = temp_s0;
                
                // Check if next space requires jumping
                space = MBMasuGet(MBMasuLinkMasuIdGet(temp_v0_4->nlink, temp_v0_4->nidx));
                
                if ((space->unk_02 & 0x8000) || func_800F9A68_10D688_shared_board(system->current_player_index)) {
                    // Jump animation
                    func_8004ACE0_4B8E0(0x3A, system->current_player_index);
                    func_800F2304_105F24_shared_board(-1, 2, 0);
                    
                    switch (system->walk_speed) {
                    case 0:
                        temp_v0_4->player_obj->unk30.y = 8.0f;
                        temp_v0_4->player_obj->unk30.z = -2.0f;
                        func_800ED410_101030_shared_board(system->current_player_index, 7);
                        break;
                    case 1:
                        temp_v0_4->player_obj->unk30.y = 4.0f;
                        temp_v0_4->player_obj->unk30.z = -0.5f;
                        func_800ED410_101030_shared_board(system->current_player_index, 0xF);
                        break;
                    case 2:
                        temp_v0_4->player_obj->unk30.y = 2.0f;
                        temp_v0_4->player_obj->unk30.z = -0.125f;
                        func_800ED410_101030_shared_board(system->current_player_index, 0x1E);
                        break;
                    }
                } else {
                    // Normal walk animation
                    if (temp_v0_4->player_obj->unk46 != 0) {
                        func_800F2304_105F24_shared_board(-1, 0, 2);
                    }
                    
                    switch (system->walk_speed) {
                    case 0:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 2.0f);
                        func_800ED410_101030_shared_board(system->current_player_index, 5);
                        break;
                    case 1:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 1.0f);
                        func_800ED410_101030_shared_board(system->current_player_index, 0xA);
                        break;
                    case 2:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 0.75f);
                        func_800ED410_101030_shared_board(system->current_player_index, 0xF);
                        break;
                    }
                    func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 1.0f);
                }
                
                // Update position
                temp_v0_4->blink = temp_v0_4->clink;
                temp_v0_4->bidx = temp_v0_4->cidx;
                temp_v0_4->clink = temp_v0_4->nlink;
                temp_v0_4->cidx = temp_v0_4->nidx;
                
                // Calculate next index based on direction
                if (temp_v0_4->rev & 1) {
                    temp_v0_4->nidx = temp_v0_4->nidx - 1;
                } else {
                    temp_v0_4->nidx = temp_v0_4->nidx + 1;
                }
                
                var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
                space = MBMasuGet(var_s5);
                func_800EBCBC_FF8DC_shared_board(var_s5);
                
                // Handle passing over certain space types
                switch (space->space_type) {
                case 1:   // Blue space
                case 2:   // Red space
                case 4:   // Happening space
                case 5:   // Event space
                case 6:   // Item space
                case 7:   // Bank space
                case 9:   // Battle space
                case 12:  // Bowser space
                case 15:  // Game guy space
                    func_800DBFBC_EFBDC_shared_board(system->current_player_index);
                    D_800D41C0_D4DC0--;
                    func_800EB97C_FF59C_shared_board(var_s5);
                    break;
                }
                
                // Play appropriate sound effect
                if (D_800D41C0_D4DC0 != 0) {
                    func_800F95FC_10D21C_shared_board(space->space_type);
                } else {
                    func_800F965C_10D27C_shared_board(space->space_type);
                }
                
                func_800E455C_F817C_shared_board();
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 1);
                
                if (D_80105664_119284_shared_board < 0) {
                    continue;
                }
                
                D_800D1240_D1E40 = 2;
                HuPrcSleep(-1);  // Suspend until resumed
        case 2:
                if (D_80105660_119280_shared_board & 1) {
                    var_s5 = func_800EBCC8_FF8E8_shared_board();
                    D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 2);
                    if (D_80105664_119284_shared_board >= 0) {
                        D_800D1240_D1E40 = 3;
                        HuPrcSleep(-1);
                        
                    }
                }
            /* fallthrough */
        case 3:
                if (D_80105660_119280_shared_board & 2) {
                    D_800D41C0_D4DC0 = 0;
                    continue;
                }
                func_800DB884_EF4A4_shared_board(system->current_player_index);
                HuPrcSleep(0xA);
            }

            if (system->current_board_index == 3) {
                GwSystem.boardData.halfWordBytes[4] = 0;
            }
            
            // Handle reverse direction cleanup
            if (temp_v0_4->rev & 0x80) {
                if (temp_v0_4->rev & 1) {
                    // Swap blink/nlink and bidx/nidx
                    temp_v1_2 = temp_v0_4->blink;
                    temp_v0_4->blink = temp_v0_4->nlink;
                    temp_v0_4->nlink = temp_v1_2;
                    
                    temp_v1_3 = temp_v0_4->bidx;
                    temp_v0_4->bidx = temp_v0_4->nidx;
                    temp_v0_4->nidx = temp_v1_3;
                }
                temp_v0_4->rev &= 0x7E;
            }
            
            func_800F2304_105F24_shared_board(-1, -1, 2);
            var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
            temp_v0_8 = MBMasuGet(var_s5)->space_type;
            
            // Update prize statistics
            switch (temp_v0_8) {
            case 4:  // Happening space
                func_800FF900_113520_shared_board(-1, 3);
                temp_v0_4->stats.prize.hatenaPrize++;
                break;
            case 2:  // Red space
                func_800FF900_113520_shared_board(-1, 1);
                temp_v0_4->stats.prize.redPrize++;
                break;
            case 1:  // Blue space
                temp_v0_4->stats.prize.bluePrize++;
                break;
            case 5:  // Event space
                func_800FF900_113520_shared_board(-1, 4);
                temp_v0_4->stats.prize.eventPrize++;
                break;
            case 15:  // Item space
                func_800FF900_113520_shared_board(-1, 4);
                temp_v0_4->stats.prize.gamblePrize++;
                break;
            case 12:  // Bank space
                func_800FF900_113520_shared_board(-1, 2);
                temp_v0_4->stats.prize.kupaPrize++;
                break;
            case 9:  // Battle space
                func_800FF900_113520_shared_board(0, 2);
                func_800FF900_113520_shared_board(1, 2);
                func_800FF900_113520_shared_board(2, 2);
                func_800FF900_113520_shared_board(3, 2);
                temp_v0_4->stats.prize.battlePrize++;
                break;
            case 6:  // Bowser space
                func_800FF900_113520_shared_board(-1, 2);
                temp_v0_4->stats.prize.itemPrize++;
                break;
            case 7:  // Gambling space
                func_800FF900_113520_shared_board(-1, 3);
                temp_v0_4->stats.prize.bankPrize++;
                break;
            }
            
            D_800D1240_D1E40 = 4;
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 3);
            
            if (D_80105664_119284_shared_board < 0) {
                goto labelE5C;
            }
            HuPrcSleep(-1);
            /* fallthrough */
        case 4:
        // STATE 4 & 5: Additional space handling
            if (D_80105660_119280_shared_board & 1) {
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(func_800EBCC8_FF8E8_shared_board(), 4);
                
                if (D_80105664_119284_shared_board >= 0) {
                    D_800D1240_D1E40 = 5;
                    HuPrcSleep(-1);
                }
            }
            /* fallthrough */
        case 5:
            HuPrcSleep(0x1E);
            labelE5C:
            
            // Return player to space position
            func_800ECC0C_10082C_shared_board(&sp20);
            func_800ED1E4_100E04_shared_board(&temp_v0_4->player_obj->unk18, &sp20, 
                                              &temp_v0_4->player_obj->unk18, 8);
            
            var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
            space = MBMasuGet(var_s5);
            
            if (kakusiMasuStar == var_s5 || D_800D4080_D4C80 != 0) {
                func_800FF900_113520_shared_board(-1, 5);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                temp_s1 = func_800DDDD4_F19F4_shared_board(system->current_player_index);
                func_800DE858_F2478_shared_board();
                
                // Display message window
                func_80060394_60F94(1, sp30, 0x3F00);
                temp_v0_9 = func_80061188_61D88(-1, 0xA0 - (sp30[0] / 2), 0x96, sp30[0], sp30[1], 0);
                func_8005B43C_5C03C(temp_v0_9, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_9);
                func_800600C0_60CC0(temp_v0_9, 1);
                HuPrcChildWait();
                
                func_800600C0_60CC0(temp_v0_9, 0);
                func_800EDC58_101878_shared_board(temp_v0_9, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_9, 0);
                func_8005F364_5FF64(temp_v0_9);
                func_800DE868_F2488_shared_board();
                
                // Wait for player input
                while (!(func_800DE84C_F246C_shared_board())) {
                    HuPrcVSleep();
                }
                
                // Display follow-up message
                func_80060394_60F94(1, sp30, 0x3F01);
                temp_v0_10 = func_80061188_61D88(-1, 0xA0 - (sp30[0] / 2), 0x96, sp30[0], sp30[1], 0);
                func_8005B43C_5C03C(temp_v0_10, 0x3F01, -1, -1);
                func_80061388_61F88(temp_v0_10);
                func_800EDC58_101878_shared_board(temp_v0_10, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_10, 0);
                func_8005F364_5FF64(temp_v0_10);
                func_800DE868_F2488_shared_board();
                
                HuPrcChildLink(temp_s6, temp_s1);
                HuPrcChildWait();
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                
                // Update star block history
                kakusiMasuStarOld[D_800D6A44_D7644++] = kakusiMasuStar;
                D_800D6A44_D7644 = D_800D6A44_D7644 % 10;
                kakusiMasuStar = -1;
                MBBlockMasuUpdate();
            }
            
            // COIN BLOCK HANDLING (similar structure to star block)
            if (kakusiMasuCoin == var_s5 || D_800D2130 != 0) {
                func_800FF900_113520_shared_board(-1, 5);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                temp_s1 = func_800DE7E4_F2404_shared_board(system->current_player_index);
                func_800DE858_F2478_shared_board();
                func_80060394_60F94(1, sp38, 0x3F00);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp38[0] / 2), 0x96, sp38[0], sp38[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800600C0_60CC0(temp_v0_13, 1);
                HuPrcChildWait();
                func_800600C0_60CC0(temp_v0_13, 0);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                func_800DE868_F2488_shared_board();

                while (!func_800DE84C_F246C_shared_board()) {
                    HuPrcVSleep();
                }

                HuPrcChildLink(temp_s6, temp_s1);
                HuPrcChildWait();
                func_80060394_60F94(1, sp38, 0x3F02);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp38[0] / 2), 0x96, sp38[0], sp38[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F02, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                kakusiMasuCoinOld[D_800D1FEC_D2BEC++] = kakusiMasuCoin;
                D_800D1FEC_D2BEC = D_800D1FEC_D2BEC % 10;
                kakusiMasuCoin = -1;
                MBBlockMasuUpdate();
            }
    
            // ITEM BLOCK HANDLING
            if (kakusiMasuItem == var_s5 || D_800D1708_D2308 != 0) {
                short var_s1;
                short temp_v1_6;
                func_800FF900_113520_shared_board(-1, 5);
                
                // Random item selection with weighted probabilities
                do {
                    var_s1 = 0;
                    temp_v1_6 = MBRand(100.0f) + 1;
                    
                    while (1) {
                        if (temp_v1_6 <= D_80101E70_115A90_shared_board[var_s1][1]) break;
                        var_s1++;
                    }
                    
                    // Reroll if Boo item and special flag is set
                } while (GwSystem.unk_52 != 0 && D_80101E70_115A90_shared_board[var_s1][0] == 0x12);
                
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                func_800DE414_F2034_shared_board(system->current_player_index, 
                                                D_80101E70_115A90_shared_board[var_s1][0]);
                func_800DE858_F2478_shared_board();
                
                // Display item message window
                func_80060394_60F94(1, sp40, 0x3F00);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp40[0] / 2), 0x96, sp40[0], sp40[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800600C0_60CC0(temp_v0_13, 1);
                HuPrcChildWait();
                
                func_800600C0_60CC0(temp_v0_13, 0);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                func_800DE868_F2488_shared_board();
                
                // Wait for input
                while (!(func_800DE84C_F246C_shared_board() & 0xFF)) {
                    HuPrcVSleep();
                }
                
                func_800DE868_F2488_shared_board();
                func_8006022C_60E2C(var_s1 + 0x3F04, 0);
                
                // Display item received message
                func_80060394_60F94(1, sp40, 0x3F03);
                temp_v0_14 = func_80061188_61D88(-1, 0xA0 - (sp40[0] / 2), 0x96, sp40[0], sp40[1], 0);
                func_8005B6BC_5C2BC(temp_v0_14, var_s1 + 0x3F04, 0);
                func_8005B43C_5C03C(temp_v0_14, 0x3F03, -1, -1);
                func_80061388_61F88(temp_v0_14);
                func_800EDC58_101878_shared_board(temp_v0_14, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_14, 0);
                func_8005F364_5FF64(temp_v0_14);
                
                // Check if player has empty item slot
                if (PlayerHasEmptyItemSlot(system->current_player_index) == -1) {
                    MBDlgResultWinExec(0x3F0A);  // Inventory full message
                }
                
                func_800DE858_F2478_shared_board();
                HuPrcSleep(5);
                
                // Wait for input
                while (!(func_800DE84C_F246C_shared_board() & 0xFF)) {
                    HuPrcVSleep();
                }
                
                HuPrcSleep(0xA);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                
                // Update item block history
                kakusiMasuItemOld[D_800D1F7A_D2B7A++] = kakusiMasuItem;
                D_800D1F7A_D2B7A = D_800D1F7A_D2B7A % 10;
                kakusiMasuItem = -1;
                MBBlockMasuUpdate();
            }
            
            // HAPPENING SPACE: Check for duel minigame
            if (space->space_type == 4) {
                goto label;
            } else {
                short temp_v0_15;
                temp_v0_15 = MBKettouPlayerBitGet(1);
                
                if (temp_v0_15 == 0) {
                    goto label;
                } else {
                    GwSystem.unk_58 = temp_v0_15;
                    GwSystem.playerIndexVisitingBowser = (1 << temp_v0_4->turn); //?
                    func_800FF900_113520_shared_board(temp_v0_4->turn, 3);
                    
                    temp_v0_16 = MBKettouExec(temp_v0_4, 0);
                    
                    if (temp_v0_16 == 0) {
                        goto label; //?
                        MBKettouResultExec();
                    } else if (temp_v0_16 == 1) {
                        HuPrcSleep(-1);
                    }
                    MBKettouComResultSet();
                }
            }
            /* fallthrough */
        case 8: 
            MBKettouResultExec();
            label:
            func_800ECDD4_1009F4_shared_board(-1, space->space_type);
            func_800F4798_1083B8_shared_board(system->current_player_index, temp_v0_4->color);
            
            switch (space->space_type) {
            case 1:  // BLUE SPACE
                var_v1 = (GWBoardFlagCheck(2) != 0) ? 2 : 1;  // Last 5 turns doubles coins
                var_s0 = var_v1*2;
                var_s0 += var_v1;

                label181C:
                MBCoinChangeCreate(system->current_player_index, var_s0);
                func_800F5D44_109964_shared_board(system->current_player_index, var_s0);
                HuPrcSleep(0x1E);
                goto label2444;
               
                
            case 2:  // RED SPACE
                var_v1 = (GWBoardFlagCheck(2) != 0) ? 2 : 1;
                var_s0 = var_v1*2;
                var_s0 += var_v1;
                var_s0 = -var_s0;
                goto label181C;
                
                // MBCoinChangeCreate(system->current_player_index, var_s0);
                // func_800F5D44_109964_shared_board(system->current_player_index, var_s0);
                break;
                
            case 4:  // HAPPENING SPACE
                if (D_80101B6C_11578C_shared_board == 0) {
                    goto label2444;
                }
                
                // Execute board-specific happening event
                HuPrcChildLink(temp_s6, omAddPrcObj(D_80101B6C_11578C_shared_board, 0x4800U, 0, 0));
                HuPrcChildWait();
                
                // Special handling for board 3
                if (system->current_board_index == 3 && GwSystem.boardData.halfWordBytes[3] != 0) {
                    GwSystem.boardData.halfWordBytes[3] = 0;
                    goto label654;  // Jump back to state 10 (dice roll)
                }
                
                // Check for another duel minigame
                temp_v0_18 = MBKettouPlayerBitGet(1);
                
                if (temp_v0_18 == 0) {
                    goto label2444;
                }
                GwSystem.unk_58 = temp_v0_18;
                GwSystem.playerIndexVisitingBowser = (1 << MBGetPlayerStruct(-1)->turn); //?
                func_800FF900_113520_shared_board(MBGetPlayerStruct(-1)->turn, 3);
                
                temp_v0_16 = MBKettouExec(temp_v0_4, 1);
                
                if (temp_v0_16 == 0) {
                    goto label2444;
                } else if (temp_v0_16 == 1) {
                    HuPrcSleep(-1);
                }
                MBKettouComResultSet();
                MBKettouResultExec();
                goto label2444;
                
            case 5:  // EVENT SPACE
                D_800D1240_D1E40 = 0x10;
                
                // Set up team groups
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    temp_s0_2 = MBGetPlayerStruct(var_s1);
                    temp_s0_2->group = (var_s1 != GetCurrentPlayerIndex());
                }
                
                // Trigger event minigame
                func_800FF794_1133B4_shared_board(0x6A, 0, 5, 1);
                HuPrcSleep(-1);
                HuPrcSleep(0x1E);
                goto label2444;
                
            case 6:  // ITEM SPACE
                D_800D037C_D0F7C = 0;
                HuPrcSleep(8);
                
                // Check if last turn
                if (system->current_turn == system->total_turns) {
                    MBDlgResultWinExec(0x3C01);  // Last turn message
                    goto label2444;
                }
                
                // Check if inventory full
                if (PlayerHasEmptyItemSlot(system->current_player_index) == -1) {
                    MBDlgResultWinExec(0x3C00);  // Inventory full
                    goto label2444;
                }
                
                // Item shop - random outcome
                temp_v0_20 = MBRand(5.0f);

                switch (temp_v0_20) {
                case 0:
                    func_800F85C0_10C1E0_shared_board();  // Shop outcome 1
                    goto label2444;                    
                case 1:
                    func_800F85E4_10C204_shared_board();  // Shop outcome 2
                    goto label2444;                    
                default:
                    // Item minigame option
                    if (func_800F2198_105DB8_shared_board(-1) == 0 || system->show_com_minigames == 0) {
                        goto label1d70;
                    }
                                                // COM item minigame logic
                    WipeCreateOut(6, 0x10);
                    HuPrcSleep(0x11);
                    HuPrcSleep(5);
                    WipeCreateIn(6, 0x10);
                    HuPrcSleep(0x11);

                    temp_s2 = RNGPercentChance(0x42) ? 0 : 1;
                    
                    // AI decision logic
                    if (!(MBRand(100.0f) >= D_80101C24_115844_shared_board[GwPlayer[system->current_player_index].cpu_difficulty])) {
                        // AI accepts - determine item
                        var_s1 = 0;
                        temp_s0_3 = BoardPlayerRankCalc(system->current_player_index);
                        //extern s8 D_80101DAC_1159CC_shared_board[][4][2];
                        temp_s0_4 = D_80101D2C_11594C_shared_board[temp_s2][temp_s0_3][BoardGetTurnTier(-1)];
                        temp_a0 = MBRand(100.0f);

                        
                        
                        // Find item based on weighted table
                        //something is slightly off here...
                        for (var_s1 = 0; var_s1 < 8; var_s1++) {
                            if (D_80101C8C_1158AC_shared_board[temp_s2][temp_s0_4][var_s1] > temp_a0) {
                                break;
                            }               
                        }                            
                        

                        // Display message
                        MBDlgWinInsertCreate(-1, 0x3C22, D_80101C4C_11586C_shared_board[temp_s2][var_s1], 0, 0, 0, 0);
                        MBDlgWinClose();
                        MBDlgWinKill();
                        
                        // Store item
                        GwPlayer[system->current_player_index].bonusCoin = D_80101C2C_11584C_shared_board[temp_s2][var_s1];
                        
                        // Display item sprite with animation
                        temp_s2_2 = HuSprGrpCreate(1U, 5U);
                        temp_v0_21 = DataRead(D_8010197C_11559C_shared_board[D_80101C2C_11584C_shared_board[temp_s2][var_s1]]);
                        temp_s3_3 = func_80055810_56410(temp_v0_21);
                        DataClose(temp_v0_21);
                        
                        func_80055024_55C24(temp_s2_2, 0, temp_s3_3, 0);
                        HuSprPriSet(temp_s2_2, 0, 0xAU);
                        func_800550F4_55CF4(temp_s2_2, 0, 0);
                        HuSprAttrSet(temp_s2_2, 0, 0x180C);
                        func_80054904_55504(temp_s2_2, 0, 0xA0, 0x5A);
                        func_80055458_56058(temp_s2_2, 0, 0U);
                        HuAudFXPlay(0x10);
                        
                        // Animate sprite appearing
                        for (var_s1 = 0; var_s1 < 0xA; var_s1++) {
                            func_80055458_56058(temp_s2_2, 0, (var_s1 * 25) & 0xFFFF);
                            HuPrcVSleep();
                        }
                        
                        func_80055458_56058(temp_s2_2, 0, 0x100U);
                        HuPrcSleep(5);
                        func_800F2304_105F24_shared_board(-1, 5, 0);
                        HuPrcSleep(5);
                        func_8004ACE0_4B8E0(0x2BD, system->current_player_index);
                        HuPrcSleep(0x14);
                        func_800F2388_105FA8_shared_board(-1, -1, 0, 5, 2);
                        HuPrcSleep(0xA);
                        
                        // Clean up sprite
                        HuSprGrpKill(temp_s2_2);
                        HuSprKill(temp_s3_3);
                        goto tempCase17;
                    }
                    

                    MBDlgResultWinExec(0x3C32);
                    goto label2444;

                    label1d70:
                    func_800F7108_10AD28_shared_board();
    
                    for (var_s1 = 0; var_s1 < 4; var_s1++) {
                        GwPlayer[var_s1].group = 1;
                    }
                    
                    temp_v0_4->group = 0;
                    HuPrcChildLink(temp_s6, func_800E0F84_F4BA4_shared_board());
                    HuPrcChildWait();
                    
                    D_800D1240_D1E40 = 0x11;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1360.unk_20 = 6;
                    HuPrcSleep(-1);
                    goto label2444;
                }

                tempCase17:
                
                GwPlayer[system->current_player_index].itemNo[PlayerHasEmptyItemSlot(system->current_player_index)] = 
                    GwPlayer[system->current_player_index].bonusCoin;
                HuPrcSleep(0x1E);
                goto label2444;
            case 9:
                if (!(func_800FB624_10F244_shared_board(temp_v0_4))) {
                    goto label2444;
                } else {
                    D_800D037C_D0F7C = 0;
                    func_800F7108_10AD28_shared_board();
                    HuPrcChildLink(temp_s6, func_800E0C3C_F485C_shared_board());
                    HuPrcChildWait();
                    D_800D1240_D1E40 = 0x12;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1380_D1F80 = 8;
                    HuPrcSleep(-1);
                }

                test:
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    if (GwPlayer[var_s1].bonusCoin != 3) {
                        break;
                    }
                }
                
                if (var_s1 >= 4) {
                    // All players done with battle
                    func_800FC3D0_10FFF0_shared_board();
                }
                
                goto label2444;
            case 12:  // BOWSER SPACE
                D_800D1240_D1E40 = 6;
                GwSystem.playerIndexVisitingBowser = system->current_player_index;
                func_800FF794_1133B4_shared_board(0x50, 0, 3, 1);
                HuPrcSleep(-1);
                HuPrcSleep(0x1E);
                goto label2444;
                
            case 15:  // GAME GUY SPACE
                HuPrcSleep(8);
                
                // Create game guy object
                temp_v0_22 = MBModelCreate(0x3EU, 0);
                MBModelTempAllocFree(temp_v0_22);
                HuVecCopy3F(&temp_v0_22->coords, &temp_v0_4->player_obj->coords);
                temp_v0_22->unk30.x = 100.0f;
                
                // Animate game guy appearing on screen
                while (temp_v0_22->unk30.x >= 30.0f) {
                    temp_v0_22->unk30.x -= 2.0f;
                    HuPrcVSleep();
                }
                
                temp_s1 = func_800EDB98_1017B8_shared_board(temp_v0_22, 5.0f, 2.0f);
                HuAudFXPlay(0x2A1);
                
                if (GwPlayer[system->current_player_index].coin != 0) {
                    // Take all coins
                    MBDlgWinExec(0xA, 0x2F00);
                    GwPlayer[system->current_player_index].gameCoin = 
                        GwPlayer[system->current_player_index].coin;
                    
                    MBCoinChangeCreate(system->current_player_index, 
                                       -GwPlayer[system->current_player_index].coin);
                    func_800F5D44_109964_shared_board(system->current_player_index,
                                                     -GwPlayer[system->current_player_index].coin);
                    HuPrcSleep(0x1E);
                    MBDlgWinExec(0xA, 0x2F02);
                    omDelPrcObj(temp_s1);
                    
                    // Animate game guy leaving with player
                    while (temp_v0_22->unk30.x >= 10.0f) {
                        temp_v0_22->unk30.x -= 2.0f;
                        HuPrcVSleep();
                    }
                    
                    func_800EE688_1022A8_shared_board(temp_v0_22, 2.0f, 0.0001f);
                    func_800EE688_1022A8_shared_board(temp_v0_4->player_obj, 2.0f, 0.0001f);
                    HuPrcSleep(0x1E);
                } else {
                    MBDlgWinExec(0xA, 0x2F01);
                    omDelPrcObj(temp_s1);
                    // Animate game guy leaving with player
                    while (temp_v0_22->unk30.x <= 100.0f) {
                        temp_v0_22->unk30.x += 4.0f;
                        HuPrcVSleep();
                    }
                    MBModelKill(temp_v0_22);
                    goto label2488;
                }
                
                    
                if (func_800F2198_105DB8_shared_board(-1) != 0 && system->show_com_minigames != 0) {
                    // COM game guy - immediate result
                    WipeCreateOut(9, 0x10);
                    HuPrcSleep(0x11);
                    MBModelKill(temp_v0_22);
                    func_800EE688_1022A8_shared_board(temp_v0_4->player_obj, 0, 0);
                    temp_v0_4->player_obj->unk30.x = 0.0f;
                    HuPrcSleep(5);
                    WipeCreateIn(9, 0x10);
                    HuPrcSleep(0x11);
                    
                    // Weighted random multiplier
                    temp_v1_8 = MBRand(1000.0f) + 1;

                    for (var_s1 = 0; var_s1 < 7; var_s1++) {
                        if (D_80101C08_115828_shared_board[var_s1][1] >= temp_v1_8) {
                            break;
                        }
                    }

                    
                    temp_a0_3 = D_80101C08_115828_shared_board[var_s1][0];
                    
                    if (temp_a0_3 != 0) {
                        // Won multiplier
                        var_s1_12 = GwPlayer[system->current_player_index].gameCoin * temp_a0_3;
                        
                        if (var_s1_12 > 999) {
                            var_s1_12 = 999;
                        }
                        
                        sprintf(sp48, D_801025D0_1161F0_shared_board, var_s1_12);
                        MBDlgWinInsertCreate(-1, 0x2F03, (s32)sp48, 0, 0, 0, 0);
                        MBDlgWinClose();
                        MBDlgWinKill();
                        
                        MBCoinChangeCreate(system->current_player_index, var_s1_12);
                        func_800F5D44_109964_shared_board(system->current_player_index, var_s1_12);
                        HuPrcSleep(0x14);
                        func_800F2304_105F24_shared_board(-1, 5, 0);
                        func_8004ACE0_4B8E0(0x274, system->current_player_index);
                        func_800F22C0_105EE0_shared_board(-1);
                    } else {
                        // Lost everything
                        MBDlgWinExec(-1, 0x2F04);
                        func_800F2304_105F24_shared_board(-1, 3, 0);
                        func_8004ACE0_4B8E0(0x286, system->current_player_index);
                        func_800F22C0_105EE0_shared_board(-1);
                        HuPrcSleep(0x14);
                    }
                    
                    func_800F2388_105FA8_shared_board(-1, -1, 0, 5, 2);
                    HuPrcSleep(0xA);
                    goto label2488;
                } else {
                    // Setup for game guy minigame
                    D_800D1240_D1E40 = 0x13;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1360.unk_20 = 9;
                    
                    for (var_s1 = 0; var_s1 < 4; var_s1++) {
                        GwPlayer[var_s1].group = 1;
                    }
                    temp_v0_4->group = 0;
                    
                    // Select minigame based on weighted random
                    temp_a0_4 = MBRand(100.0f);
                    var_v1_3 = 0;

                    for (var_v1_3 = 0; var_v1_3 < 4U; var_v1_3++) {
                        if (D_80101C04_115824_shared_board[var_v1_3] > temp_a0_4) {
                            break;
                        }
                    }
                    
                    if (var_v1_3 == 4) {
                        var_v1_3 = 3;
                    }
                    
                    system->minigame_index = D_80101C00_115820_shared_board[var_v1_3];
                    GwSystem.playerIndexVisitingBowser = system->current_player_index;
                }
                
                HuPrcSleep(-1);
                goto label2438;
                
            case 3:   // Star space
            case 7:   // Bank space (already handled)
            case 8:   // Boo space
            case 10:  // Mushroom space
            case 11:  // Warp space
            case 13:  // Chance time space
            case 14:  // Koopa bank space
            default:
                goto label2444;
            }
        case 17:
            goto tempCase17;
        case 18:
            goto test;
        case 19:
            label2438:
                func_800FC4E0_110100_shared_board();
                label2444:
                D_800D1240_D1E40 = 7;
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 5);
                if (D_80105664_119284_shared_board < 0) {
                    goto label2488;
                }
                HuPrcSleep(-1);
        case 7:
            HuPrcSleep(0x1E);
            label2488:
            D_800D037C_D0F7C = 0;
            
            // END OF TURN: Check for end of round minigames
            if (system->current_player_index >= 3) {
                func_800EBAC8_FF6E8_shared_board(-3, 7);
                func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
                D_800A12D4 = 0;
                func_800F7108_10AD28_shared_board();
                
                HuPrcChildLink(temp_s6, func_800E0A14_F4634_shared_board());
                HuPrcChildWait();
                
                if (system->minigame_index >= 0) {
                    D_800D1240_D1E40 = 0;
                    
                    // Determine minigame type
                    if (system->total_turns >= 0 && system->current_turn >= system->total_turns) {
                        if (GwSystem.unk_52 == 2) {
                            D_80105664_119284_shared_board = 3;
                        } else {
                            D_80105664_119284_shared_board = 0x23;
                        }
                    } else {
                        D_80105664_119284_shared_board = 3;
                    }
                    D_80105666_119286_shared_board = 1;
                    D_800D1360.unk_20 = 0xA;
                    
                    for (var_s0_2 = 0; var_s0_2 < 4; var_s0_2++) {
                        func_800F482C_10844C_shared_board(var_s0_2);
                    }
                    
                    HuPrcSleep(-1);
                }
            }
            
            // Check for game end condition
            if (MBLast5Check() != 0) {
                D_800D1240_D1E40 = 0;
                D_80105664_119284_shared_board = 1;
                HuPrcSleep(-1);
            }
            
            HuPrcSleep(4);
            
            HuPrcChildLink(temp_s6, func_800F292C_10654C_shared_board());
            HuPrcChildWait();
            
            MBNextPlayerTurn();
            
            // Hide all players
            for (var_s1 = 0; var_s1 < 4; var_s1++) {
                func_800ECC28_100848_shared_board(var_s1);
                MBMotionSet(MBGetPlayerStruct(var_s1)->player_obj, -1, 2);
            }
            
            HuPrcVSleep();
        
            if (GwSystem.current_board_index == 0 && GWBoardFlagCheck(0x12) != 0) {
                func_800EBEC8_FFAE8_shared_board();
                GWBoardFlagClear(0x12);
            }
            
            func_800FF840_113460_shared_board(0);
            D_800D1240_D1E40 = 1;
        }
    }
}

void func_800FF0F8_112D18_shared_board(void) {
    HuPrcVSleep();
    func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
    MBExit();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF158_112D78_shared_board);

void MBStart(u32 arg0) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        s16 masuID;
        player = MBGetPlayerStruct(i);
        masuID = MBMasuLinkMasuIdGet(player->clink, player->cidx);
        func_800ECB14_100734_shared_board(i, masuID);
    }


    func_800E6FBC_FABDC_shared_board();
    func_800E9730_FD350_shared_board(1.0f);
    func_800E9AC8_FD6E8_shared_board(-1.0f);
    D_800CD280_CDE80 = 1;
    switch (arg0) {
    case 0:
        switch (D_800D1240_D1E40) {
        case 0:
        case 1:
            WipeCreateIn(0, 0);
            func_800F2834_106454_shared_board();
            break;
        default:
            if (D_800A12C8 != -1) {
                if (D_800A12C8 == 0) { //logic is backwards here
                    WipeColorSet(255, 255, 255);
                } else {
                    WipeColorSet(0, 0, 0);
                }
                WipeCreateIn(D_800A12C8, 0x10);
                D_800A12C8 = -1;
                func_800FF900_113520_shared_board(0, 0);
                func_800FF900_113520_shared_board(1, 0);
                func_800FF900_113520_shared_board(2, 0);
                func_800FF900_113520_shared_board(3, 0);
            } else {
                WipeCreateIn(0xFF, 0x10);
            }
            func_800E8DD4_FC9F4_shared_board(D_800C9938_CA538);
            func_800F27D0_1063F0_shared_board();
            break;
        }
        func_800E9748_FD368_shared_board(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
        omAddPrcObj(MBMain, 0xEFFFU, 0x3000, 0);
        omAddPrcObj(func_800F93A4_10CFC4_shared_board, 0x1005U, 0, 0);
        omPrcSetStatBit(omAddPrcObj(func_800FF158_112D78_shared_board, 0x1001U, 0, 0), 0x80);
        D_800CDD58_CE958 = 0;
        D_800D037C_D0F7C = 0;
        D_800CDD64_CE964 = 0;
        D_800D51F8_D5DF8 = 0;
        omAddPrcObj(func_800F91A4_10CDC4_shared_board, 0x1005U, 0, 0);
        func_800F915C_10CD7C_shared_board(1);
        if (func_800037C4_43C4(D_800CDBC8_CE7C8->unk_00) < 0x7F) {
            func_800DECBC_F28DC_shared_board();
            return;
        }
        return;
    case 1:
        func_800E9748_FD368_shared_board(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            func_800F4798_1083B8_shared_board(i, MBGetPlayerStruct(i)->color);
        }
        omAddPrcObj(func_800F93A4_10CFC4_shared_board, 0x1005, 0, 0);
        omPrcSetStatBit(omAddPrcObj(func_800FF0F8_112D18_shared_board, 0x1005, 0, 0), 0x80);
        D_800CDD58_CE958 = 1;
        return;
    case 2:
        func_800F5D8C_1099AC_shared_board();
        func_800F915C_10CD7C_shared_board(0);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF75C_11337C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF788_1133A8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF794_1133B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF7C4_1133E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF7F0_113410_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF800_113420_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF834_113454_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/10C230", func_800FF840_113460_shared_board);
