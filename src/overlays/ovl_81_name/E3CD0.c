#include "common.h"
#include "ovl_81.h"

//this file is a duplicate of 10C230.c in ovl_80_shared_board
typedef struct UnkE3CD0 {
    char unk_00[0xC];
    Vec unk_0C;
    char unk_18[0x18];
    f32 unk_30;
} UnkE3CD0;

void func_8004A950_4B550(void);
extern s32 D_80101AF8_E98C8_name_81;
extern s32 D_80101AFC_E98CC_name_81;
extern s32 D_80101B00_E98D0_name_81;
extern s32 D_80101B04_E98D4_name_81;
extern UnkE3CD0* D_801054B0_ED280_name_81;
extern Vec* D_801054AC_ED27C_name_81;
extern Vec D_801054A0_ED270_name_81;
extern s16 D_8010549E_ED26E_name_81;
extern s16 D_800A12C8;
extern s16 D_800C9930_CA530;
extern f32 D_800C9938_CA538;
extern s16 D_800CE1D0_CEDD0;
extern s16 D_800CE206;
extern s16 D_800D124C_D1E4C;
extern s32 mbWalkNum;
extern s16 D_80101A50_E9820_name_81;
extern s32 D_80101A98_E9868_name_81;
extern void (*D_80101A8C_E985C_name_81)(void);
extern s32 D_80101A70_E9840_name_81[];
extern s32 D_80101A54_E9824_name_81[];
extern s16 D_800D6A48_D7648;
extern s32 mbTurnOnF;
extern s16 D_800C9930_CA530;
extern s16 D_800CE204;
extern s16 D_800CE206;
extern s32 D_80105498_ED268_name_81;
extern s16 D_8010549C_ED26C_name_81;
extern u8 D_80101AF4_E98C4_name_81[];

void func_800FBF00_E3CD0_name_81(s32 id, s16 event, u16 stat) {
    omOvlHisData* overlay = &mbovlhis[mbovlhisidx++];

    if (id != -2) {
        if (id == -1) {
            id = omovlhis[omovlhisidx].overlayID;
            overlay->overlayID = id;
        } else {
            overlay->overlayID = id;
        }
    } else {
        id = D_80101A54_E9824_name_81[GwSystem.current_board_index];
        overlay->overlayID = id;
    }
    
    overlay->event = event;
    overlay->stat = stat;
    
    if (mbovlhisidx >= ARRAY_COUNT(mbovlhis)) {
        mbovlhisidx = ARRAY_COUNT(mbovlhis) - 1;
    }
}

void func_800FBFA4_E3D74_name_81(void) {
    D_800CD2A0_CDEA0.unk_02 = 1;
    mbovlhisidx = 0;
    
    if (GWBoardFlagCheck(1) == 0) {
        func_800FBF00_E3CD0_name_81(-2, 1, 0x4190);
        func_800FBF00_E3CD0_name_81(D_80101A70_E9840_name_81[GwSystem.current_board_index], 0, 0x4190);
    }
    func_800FC5D8_E43A8_name_81();
    func_800EBAD4_D38A4_name_81(GwSystem.message_speed);
    _ClearFlag(0xC);
    D_800D6A48_D7648 = 0;
}

void func_800FC030_E3E00_name_81(void) {
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
        omOvlCallEx(D_80101A54_E9824_name_81[GwSystem.current_board_index], 2, 0x4190);
        return;
    }
    if (D_800D6A48_D7648 != 0) {
        _SetFlag(0xC);
    } else {
        _ClearFlag(0xC);
    }
    omOvlReturnEx(1);
}

void func_800FC108_E3ED8_name_81(void) {
    D_800CD2A0_CDEA0.unk_02 = 0;
}

s16 func_800FC114_E3EE4_name_81(void) {
    return D_800D4190_D4D90.stat;
}

void func_800FC120_E3EF0_name_81(s16 arg0) {
    s16 temp_v0 = mbovlhisidx;
    
    mbovlhis[mbovlhisidx].event = arg0;
    mbovlhisidx = temp_v0 + 1;
    if (mbovlhisidx >= 5) {
        mbovlhisidx = 4;
    }
    func_800FBF00_E3CD0_name_81(-2, 3, 0x4190);
    omOvlReturnEx(1);
}

s32 func_800FC18C_E3F5C_name_81(void) {
    return mbGameMode;
}

void func_800FC198_E3F68_name_81(omObjData* obj) {
    s32* temp_s0 = HuPrcCurrentGet()->user_data;

    while (1) {
        if (
            (func_800F37B8_DB588_name_81(temp_s0[0]) == 0) && 
            (D_800A12D8 == 0) && 
            ((GwSystem.current_player_index != temp_s0[0]) || (D_800A12D4 == 0)) && 
            (D_800C9520_CA120[GwPlayer[temp_s0[0]].pad] & 0x20)
        ) {
            func_8004ACE0_4B8E0(0x2BD, temp_s0[0]);
        }
        HuPrcVSleep();
    }
}

void func_800FC260_E4030_name_81(s32 arg0, s16 arg1) {
    Process* temp_v0_2;
    UnkOvl81_1* temp_v0_3;
    s32 frontPartnerID;
    s32 backPartnerID;
    Object* playerObj;
    s32 i;

    func_800E8D10_D0AE0_name_81();
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);

    if (arg0 >= 0) {
        MBDBackLoad(arg0);
    }

    func_800E94D0_D12A0_name_81();

    if (arg1 >= 0) {
        func_800E9B10_D18E0_name_81(0x13, arg1);
    }

    func_800D7EB8_BFC88_name_81();
    func_800F3F4C_DBD1C_name_81();
    func_800F3DFC_DBBCC_name_81(0);
    func_800F3DFC_DBBCC_name_81(1);

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        func_800D8944_C0714_name_81(MBDGetPlayerStruct(i)->player_obj);
        playerObj = MBDGetPlayerStruct(i)->player_obj;
        playerObj->flags |= 2;
        func_800D8E88_C0C58_name_81(MBDGetPlayerStruct(i)->player_obj);
    }

    func_8001FDE8_209E8(MBDGetPlayerStruct(0)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(MBDGetPlayerStruct(1)->player_obj->omObj1->model[0]);
    func_800F8C68_E0A38_name_81(0);
    func_800F8C68_E0A38_name_81(1);
    func_800F4300_DC0D0_name_81();
    func_800DF1B0_C6F80_name_81();
    func_800E0CEC_C8ABC_name_81();
    func_800E2870_CA640_name_81();
    func_800F6390_DE160_name_81();

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        frontPartnerID = GwPlayer[i].stats.partners.frontID;
        backPartnerID = GwPlayer[i].stats.partners.backID;
        GwPlayer[i].stats.partners.frontID = PARTNER_KOOPA; //?
        GwPlayer[i].stats.partners.backID = PARTNER_KOOPA; //?
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
        GwPlayer[i].stats.partners.frontID = frontPartnerID;
        GwPlayer[i].stats.partners.backID = backPartnerID;
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
    }

    func_800DAB1C_C28EC_name_81();
    func_8005A6B0_5B2B0();
    func_800EB664_D3434_name_81();

    D_80105494_ED264_name_81 = -1;
    D_800D1360.unk_20 = 0;
    D_80105496_ED266_name_81 = 0;
    func_800F4080_DBE50_name_81();
    D_80101A8C_E985C_name_81 = NULL;
    D_80101A90_E9860_name_81 = 0;
    D_80101A94_E9864_name_81 = 0;
    D_80101A98_E9868_name_81 = 0;
    for (i = 0; i < 2; i++) {
        temp_v0_2 = omAddPrcObj(func_800FC198_E3F68_name_81, 0, 0, 0x40);
        temp_v0_3 = HuMemMemoryAlloc(temp_v0_2->heap, sizeof(UnkOvl81_1));
        temp_v0_2->user_data = temp_v0_3;
        temp_v0_3->unk_00 = i;
        omPrcSetStatBit(temp_v0_2, 0xA0);
    }
}

void func_800FC4E4_E42B4_name_81(void) {
    func_800DBEB0_C3C80_name_81();
    func_800F64FC_DE2CC_name_81();
    func_800E28B0_CA680_name_81();
    func_800E0E38_C8C08_name_81();
    func_800DF210_C6FE0_name_81();
    func_800F4314_DC0E4_name_81();
    func_8005F524_60124();
    func_800F4030_DBE00_name_81();
    func_800D7F0C_BFCDC_name_81();
    func_800E9D9C_D1B6C_name_81();
    func_800E9564_D1334_name_81();
    MBDBackKill();
    MBDBackClose();
    func_800E4FF4_CCDC4_name_81();
    func_800E90B4_D0E84_name_81();
    
    if (D_80101A8C_E985C_name_81 != NULL) {
        D_80101A8C_E985C_name_81();
    }
    
    func_800FD55C_E532C_name_81();
}

//file split? many setters here
void func_800FC590_E4360_name_81(s32 arg0) {
    D_80101A98_E9868_name_81 = arg0;
}

void func_800FC59C_E436C_name_81(s32 arg0) {
    D_80101A94_E9864_name_81 = arg0;
}

void func_800FC5A8_E4378_name_81(process_func arg0) {
    D_80101A90_E9860_name_81 = arg0;
}

void func_800FC5B4_E4384_name_81(void (*arg0)(void)) {
    D_80101A8C_E985C_name_81 = arg0;
}

void func_800FC5C0_E4390_name_81(s32 arg0) {
    D_800CC0B8_CCCB8 = arg0;
}

s16 func_800FC5CC_E439C_name_81(void) {
    return D_800CC0B8_CCCB8;
}

void func_800FC5D8_E43A8_name_81(void) {
    GW_PLAYER* player;
    GW_SYSTEM* system = &GwSystem;
    GW_COMMON* common = &GwCommon;
    s32 i, j;

    mbGameMode = 0;
    mbWalkNum = 0;
    D_800CE1D0_CEDD0 = 0;
    D_800D124C_D1E4C = 0;
    D_80101A50_E9820_name_81 = 0;
    D_800C9938_CA538 = 1.4f;
    func_800DF154_C6F24_name_81();
    func_800DAAB0_C2880_name_81();
    D_800A12C8 = -1;
    D_800C9930_CA530 = -1;
    D_800CE206 = 0;
    D_800A12D4 = 1;
    D_800A12D8 = 0;

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
        system->current_turn = 1;
        system->current_player_index = 0;
        system->minigame_index = 0;
        
        if (system->total_turns == -1U) { //?
            system->total_turns = 50;
        } else {
            system->total_turns = 20;
        }

        for (i = 0; i < MBD_MAX_PLAYERS; i++) {
            player = MBDGetPlayerStruct(i);
            player->coin = 0;
            player->gamePrize = 0;
            player->coinPrize = 0;
            player->stats.partners.frontID = -1;
            player->stats.partners.backID = -1;
            player->stats.partners.frontPoweredUp = 0;
            player->stats.partners.backPoweredUp = 0;
            player->stats.partners.frontHp = 0;
            player->stats.partners.backHp = 0;
            player->stats.partners.frontCost = 0;
            player->stats.partners.backCost = 0;
            player->stats.partners.frontPower = 0;
            player->stats.partners.backPower = 0;
            
            for (j = 0; j < ARRAY_COUNT(player->itemNo); j++) {
                player->itemNo[j] = -1;
            }
            
            player->itemTurn = 0;
            player->rev = 0;   
        }
        
        #ifdef BUG_FIX
        for (i = 0; i < ARRAY_COUNT(GwSystem.boardData.halfWordBytes); i++) {
            GwSystem.boardData.halfWordBytes[i] = 0;
        }        
        #else
        //potentially this used to be 16 in length, then was shortened?
        for (i = 0; i < 16; i++) {
            GwSystem.boardData.halfWordBytes[i] = 0;
        }
        #endif

        GWBoardFlagClear(0x12);
        GWBoardFlagClear(0x13);
        GWBoardFlagClear(0x14);
        GWBoardFlagClear(0x15);
        GWBoardFlagClear(0x16);
        GWBoardFlagClear(0x17);
        GWBoardFlagClear(1);
        GWBoardFlagClear(0x11);

        if (GwSystem.playMode & 4) {
            if (_CheckFlag(0x28) != 0) {
                GWBoardFlagSet(0);
                return;
            }
            GWBoardFlagClear(0);
            return;
        }

        if (_CheckFlag(0x17) != 0) {
            GWBoardFlagSet(0);
            return;
        }

        GWBoardFlagClear(0);
    }
}

void func_800FC888_E4658_name_81(s32 arg0) {
    D_8010549E_ED26E_name_81 = arg0;
}

s16 func_800FC894_E4664_name_81(void) {
    return D_8010549E_ED26E_name_81;
}

void func_800FC8A0_E4670_name_81(Vec* arg0) {
    D_801054A0_ED270_name_81 = *arg0;
}

void func_800FC8C4_E4694_name_81(Vec* arg0) {
    D_801054AC_ED27C_name_81 = arg0;
}

Vec* func_800FC8D0_E46A0_name_81(void) {
    return D_801054AC_ED27C_name_81;
}

void func_800FC8DC_E46AC_name_81(UnkE3CD0* arg0) {
    D_801054B0_ED280_name_81 = arg0;
}

void func_800FC8E8_E46B8_name_81(void) {
    f32 sp10[2];
    Vec sp18;
    
    while (1) {
        switch (D_8010549E_ED26E_name_81) {
        case 1:
            MBDCameraPos3DSet(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
            break;
        case 2:
            MBDCameraPos3DSet(&D_801054A0_ED270_name_81);
            break;
        case 4:
            MBDCameraPos3DSet(D_801054AC_ED27C_name_81);
            break;
        case 5:
            HuVecCopy3F(&sp18, &D_801054B0_ED280_name_81->unk_0C);
            sp18.y += D_801054B0_ED280_name_81->unk_30;
            MBDCameraPos3DSet(&sp18);
            break;
        case 3:
            MBDCameraPos2DGet(sp10);
            MBDCameraPos2DSet(sp10);
            break;
        }
        HuPrcVSleep();        
    }
}

void func_800FC9FC_E47CC_name_81(void) {
    GW_SYSTEM* system = &GwSystem;

    system->current_player_index++;
    if ((system->current_player_index >= 2) && (system->current_player_index = 0, (mbTurnOnF == 0))) {
        system->current_turn++;
        if ((system->current_board_index == 4) && (system->total_turns == 50)) {
            if (system->current_turn > 20) {
                system->current_turn = 19;
            }
        } else if (system->current_turn >= 20) {
            system->current_turn = 20;
        }
    }
}

void func_800FCAB4_E4884_name_81(void) {
    do {
        HuPrcVSleep();
    } while (WipeStatGet() != 0);
    
    while (1) {
        HuPrcVSleep();
        if (D_800D530C_D5F0C == 0) {
            if (D_80105494_ED264_name_81 < 0) {
                continue;
            }
        }        

        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        
        if (D_80105496_ED266_name_81 != 0) {
            HuAudSeqFadeOut(0x5A);
            D_800C9930_CA530 = D_800C9930_CA530;
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
        func_800FC4E4_E42B4_name_81();
        if (D_80105494_ED264_name_81 & 0x20) {
            D_800D6A48_D7648 = 1;
            if (GwSystem.current_board_index == 5) {
                _CheckFlag(9);
            }
            func_800FBF00_E3CD0_name_81(0x62, 0, 0x4190);
            func_800FC108_E3ED8_name_81();
        }
        if (D_80105494_ED264_name_81 & 1) {
            func_800FC9FC_E47CC_name_81();
        }
        if (D_80105494_ED264_name_81 & 2) {
            func_800FBF00_E3CD0_name_81(0x70, 0, 0x192);
        }
        if (D_80105494_ED264_name_81 & 8) {
            func_800FBF00_E3CD0_name_81(D_80105498_ED268_name_81, D_8010549C_ED26C_name_81, 0x192);
        }
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

void func_800FCC84_E4A54_name_81(s16 arg0) {
    arg0 -= 2;

    switch (arg0) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        HuAudFXPlay(0x101);
        break;
    }
}

void func_800FCCCC_E4A9C_name_81(s16 arg0) {
    arg0 -= 2;

    switch (arg0) {
    case 3:
        if (GwSystem.current_board_index == 5) {
            HuAudFXPlay(0x1D4);
        } else {
            HuAudFXPlay(0x1D3);
        }
        break;
    case 8:
        HuAudFXPlay(0x1D2);
        break;
    case 1:
        HuAudFXPlay(0x12E);
        break;
    case 0:
    case 4:
    case 6:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        HuAudFXPlay(0x108);
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCD44_E4B14_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCF50_E4D20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD298_E5068_name_81);

u8 func_800FD498_E5268_name_81(void) {
    s32 var_a0 = (GwSystem.current_turn - 1) / 5;

    if (var_a0 > 3) {
        var_a0 = 3;
    }
    return D_80101AF4_E98C4_name_81[var_a0];
}

void func_800FD4DC_E52AC_name_81(void) {
    if (D_80101AF8_E98C8_name_81 == 0) {
        D_80101AF8_E98C8_name_81 = func_800E1824_C95F4_name_81(2, 0xAE, 1);
    }
    if (D_80101B00_E98D0_name_81 == 0) {
        D_80101B00_E98D0_name_81 = func_800E1824_C95F4_name_81(3, 0xCA, 1);
    }
    if (D_80101B04_E98D4_name_81 == 0) {
        D_80101B04_E98D4_name_81 = func_800E1824_C95F4_name_81(0xD, 0xBC, 1);
    }
}

void func_800FD55C_E532C_name_81(void) {
    if (D_80101AF8_E98C8_name_81 != 0) {
        func_800E1854_C9624_name_81(D_80101AF8_E98C8_name_81);
        D_80101AF8_E98C8_name_81 = 0;
    }
    if (D_80101AFC_E98CC_name_81 != 0) {
        func_800E1854_C9624_name_81(D_80101AFC_E98CC_name_81);
        D_80101AFC_E98CC_name_81 = 0;
    }
    if (D_80101B00_E98D0_name_81 != 0) {
        func_800E1854_C9624_name_81(D_80101B00_E98D0_name_81);
        D_80101B00_E98D0_name_81 = 0;
    }
    if (D_80101B04_E98D4_name_81 != 0) {
        func_800E1854_C9624_name_81(D_80101B04_E98D4_name_81);
        D_80101B04_E98D4_name_81 = 0;
    }
}

void func_800FD5F0_E53C0_name_81(void) {
    mbGameMode = 7;
    D_800D1360.unk_20 = 8;
    func_800FD55C_E532C_name_81();
}


void func_800FD620_E53F0_name_81(void) {
    Process* temp_s1;
    GW_PLAYER* temp_s0;

    temp_s0 = MBDGetPlayerStruct(CUR_PLAYER);
    temp_s1 = HuPrcCurrentGet();
    mbItemBtnF = 0;
    func_8001FDE8_209E8(temp_s0->player_obj->omObj1->model[0]);
    func_800F8C68_E0A38_name_81(GwSystem.current_player_index);
    D_800A12D4 = 0;
    HuPrcChildLink(temp_s1, func_800E0888_C8658_name_81());
    HuPrcChildWait();
    mbGameMode = 10;
    D_80105494_ED264_name_81 = 2;
    D_80105496_ED266_name_81 = 1;
    D_800D1360.unk_20 = 10;
    GwPlayer[0].group = 0;
    GwPlayer[1].group = 1;
    GwPlayer[2].group = 2;
    GwPlayer[3].group = 3;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD6F4_E54C4_name_81);

void func_800FF420_E71F0_name_81(void) {
    HuPrcVSleep();
    func_80100CEC_E8ABC_name_81(GwPlayer[GwSystem.current_player_index].pad);
    func_800FC4E4_E42B4_name_81();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF480_E7250_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF640_E7410_name_81);

void func_800FF944_E7714_name_81(s16 arg0) {
    D_800CD2A0_CDEA0.unk_02 = 1;
    D_80105494_ED264_name_81 = 0x40;
    D_800D1360.unk_20 = arg0;
    D_80105496_ED266_name_81 = 0;
}

void func_800FF970_E7740_name_81(s32 arg0) {
    D_800A12C8 = arg0;
}

void func_800FF97C_E774C_name_81(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_80105498_ED268_name_81 = arg0;
    D_8010549C_ED26C_name_81 = arg1;
    D_80105494_ED264_name_81 = 8;
    D_800D1360.unk_20 = arg2;
    D_80105496_ED266_name_81 = arg3;
}

void func_800FF9AC_E777C_name_81(s32 arg0, s16 arg1, s16 arg2) {
    func_800FF97C_E774C_name_81(arg0, arg1, arg2, 0);
}

void func_800FF9D8_E77A8_name_81(void) {
    D_800D530C_D5F0C = 1;
}

void func_800FF9E8_E77B8_name_81(s16 arg0, s16 arg1) {
    D_80105494_ED264_name_81 = 0x10;
    D_800D1360.unk_20 = arg0;
    D_80105496_ED266_name_81 = arg1;
    func_800FC108_E3ED8_name_81();
}

s16 func_800FFA1C_E77EC_name_81(void) {
    return D_80105494_ED264_name_81;
}

void func_800FFA28_E77F8_name_81(Vec* arg0) {
    f32 temp_f20;
    f32 temp_f22;
    Vec* var_s0;

    var_s0 = arg0;
    func_800E5C20_CD9F0_name_81();
    func_800E5BE8_CD9B8_name_81();
    temp_f22 = MBDCameraSpeedGet();
    MBDCameraSpeedSet(-1.0f);
    temp_f20 = func_800E8578_D0348_name_81();
    func_800E856C_D033C_name_81(1.0f);
    func_800E5954_CD724_name_81();
    if (var_s0 == NULL) {
        var_s0 = &MBDGetPlayerStruct(CUR_PLAYER)->player_obj->coords;
    }
    MBDCameraPos3DSet(var_s0);
    HuPrcVSleep();
    func_800E856C_D033C_name_81(temp_f20);
    MBDCameraSpeedSet(temp_f22);
}
