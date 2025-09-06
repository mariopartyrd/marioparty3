#include "common.h"
#include "ovl_81.h"

//this file is a duplicate of 10C230.c in ovl_80_shared_board
void func_800EBAD4_D38A4_name_81(s32);
void func_800FC5D8_E43A8_name_81(void);
void func_8004A950_4B550(void);
void func_800FC4E4_E42B4_name_81(void);
void func_800FC108_E3ED8_name_81(void);
void func_800D7F0C_BFCDC_name_81(void);
void func_800DBEB0_C3C80_name_81(void);
void func_800DF210_C6FE0_name_81(void);
void func_800E0E38_C8C08_name_81(void);
void func_800E28B0_CA680_name_81(void);
void func_800E4FF4_CCDC4_name_81(void);
void func_800E90B4_D0E84_name_81(void);
void func_800E9564_D1334_name_81(void);
void func_800E9D9C_D1B6C_name_81(void);
void func_800F4030_DBE00_name_81(void);
void func_800F4314_DC0E4_name_81(void);
void func_800FD55C_E532C_name_81(void);

extern void (*D_80101A8C_E985C_name_81)(void);
extern s32 D_80101A70_E9840_name_81[];
extern s32 D_80101A54_E9824_name_81[];
extern s16 D_800D6A48_D7648;
extern s32 D_800A12DC;
extern s16 D_800C9930_CA530;
extern s16 D_800CE204;
extern s16 D_800CE206;
extern s32 D_80105498_ED268_name_81;
extern s16 D_8010549C_ED26C_name_81;

void func_800FBF00_E3CD0_name_81(s32 id, s16 event, u16 stat) {
    omOvlHisData* overlay = &D_800D20F0_D2CF0[D_800D6B48_D7748->unk_18++];

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
    
    if (D_800D6B48_D7748->unk_18 >= ARRAY_COUNT(D_800D20F0_D2CF0)) {
        D_800D6B48_D7748->unk_18 = ARRAY_COUNT(D_800D20F0_D2CF0) - 1;
    }
}

void func_800FBFA4_E3D74_name_81(void) {
    D_800CD2A0_CDEA0.unk_02 = 1;
    D_800D6B48_D7748->unk_18 = 0;
    
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
    if (D_800D6B48_D7748->unk_18 != 0) {
        D_800D6B48_D7748->unk_18--;
        overlay = &D_800D20F0_D2CF0[D_800D6B48_D7748->unk_18];
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

s32 func_800FC114_E3EE4_name_81(void) {
    return D_800D4190_D4D90.stat;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC120_E3EF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC18C_E3F5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC198_E3F68_name_81);

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
        func_800E52DC_CD0AC_name_81(arg0);
    }
    func_800E94D0_D12A0_name_81();
    if (arg1 >= 0) {
        func_800E9B10_D18E0_name_81(0x13, arg1);
    }
    func_800D7EB8_BFC88_name_81();
    func_800F3F4C_DBD1C_name_81();
    func_800F3DFC_DBBCC_name_81(0);
    func_800F3DFC_DBBCC_name_81(1);
    for (i = 0; i < 2; i++) {
        func_800D8944_C0714_name_81(Duel_GetPlayerStruct(i)->player_obj);
        playerObj = Duel_GetPlayerStruct(i)->player_obj;
        playerObj->unkA |= 2;
        func_800D8E88_C0C58_name_81(Duel_GetPlayerStruct(i)->player_obj);
    }

    func_8001FDE8_209E8(Duel_GetPlayerStruct(0)->player_obj->omObj1->model[0]);
    func_8001FDE8_209E8(Duel_GetPlayerStruct(1)->player_obj->omObj1->model[0]);
    func_800F8C68_E0A38_name_81(0);
    func_800F8C68_E0A38_name_81(1);
    func_800F4300_DC0D0_name_81();
    func_800DF1B0_C6F80_name_81();
    func_800E0CEC_C8ABC_name_81();
    func_800E2870_CA640_name_81();
    func_800F6390_DE160_name_81();
    for (i = 0; i < 2; i++) {
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
    D_800D1360_D1F60.unk_20 = 0;
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
    func_800E52F8_CD0C8_name_81();
    func_800E5000_CCDD0_name_81();
    func_800E4FF4_CCDC4_name_81();
    func_800E90B4_D0E84_name_81();
    
    if (D_80101A8C_E985C_name_81 != NULL) {
        D_80101A8C_E985C_name_81();
    }
    
    func_800FD55C_E532C_name_81();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC590_E4360_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC59C_E436C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5A8_E4378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5B4_E4384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5C0_E4390_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5CC_E439C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5D8_E43A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC888_E4658_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC894_E4664_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8A0_E4670_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8C4_E4694_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8D0_E46A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8DC_E46AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8E8_E46B8_name_81);

void func_800FC9FC_E47CC_name_81(void) {
    GW_SYSTEM* system = &GwSystem;

    system->current_player_index++;
    if ((system->current_player_index >= 2) && (system->current_player_index = 0, (D_800A12DC == 0))) {
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
        
        WipeCreateOut((s32) D_800D1360_D1F60.unk_20, 0x10);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCC84_E4A54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCCCC_E4A9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCD44_E4B14_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCF50_E4D20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD298_E5068_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD498_E5268_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD4DC_E52AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD55C_E532C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD5F0_E53C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD620_E53F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD6F4_E54C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF420_E71F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF480_E7250_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF640_E7410_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF944_E7714_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF970_E7740_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF97C_E774C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9AC_E777C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9D8_E77A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9E8_E77B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FFA1C_E77EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FFA28_E77F8_name_81);
