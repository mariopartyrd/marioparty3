#include "common.h"

typedef struct PlayerResult {
/* 0x00 */ s8 idx;
/* 0x01 */ s8 unk_01;
/* 0x02 */ s8 unk_02;
/* 0x03 */ s8 unk_03;
/* 0x04 */ s16 score;
/* 0x06 */ s16 coin;
/* 0x08 */ s16 gameCoin;
/* 0x0A */ s16 bonusCoin;
} PlayerResult; //sizeof 0x0C
extern PlayerResult D_8010B018_4EC438_mgresultboard[4];
extern PlayerResult D_8010B048_4EC468_mgresultboard[4];

void func_80105C08_4E7028_mgresultboard(void);
void func_80105CE8_4E7108_mgresultboard(omObjData*);
void func_80106DE8_4E8208_mgresultboard(void);
void func_80106F40_4E8360_mgresultboard(omObjData*);
void func_80106FC8_4E83E8_mgresultboard(void);
void func_80107188_4E85A8_mgresultboard(void);
void func_80107234_4E8654_mgresultboard(void);
void func_800E6630_FA250_shared_board(Addr);
void func_800E6720_FA340_shared_board(s32, s32);
void func_80107024_4E8444_mgresultboard(void);
extern s32 D_8010AD0C_4EC12C_mgresultboard[];
void func_800E66E0_FA300_shared_board(void);
void func_800E69D8_FA5F8_shared_board(void);
s32 func_80106A80_4E7EA0_mgresultboard(s8);
s32 func_80106C80_4E80A0_mgresultboard(s8);
void func_80106D50_4E8170_mgresultboard(s32, s32);
s32 func_80106D88_4E81A8_mgresultboard(s32, s16);
s32 func_80106DB8_4E81D8_mgresultboard(s32, s16);
void func_80107234_4E8654_mgresultboard(void);
void func_80107650_4E8A70_mgresultboard(s8);
void func_80107800_4E8C20_mgresultboard(s32);
void func_801079B0_4E8DD0_mgresultboard(s32);
void func_80107A58_4E8E78_mgresultboard(void);
extern u32 D_8010AAF0_4EBF10_mgresultboard;
extern f32 D_8010AAF4_4EBF14_mgresultboard;
extern s32 D_8010AAF8_4EBF18_mgresultboard;
extern s32 D_8010AD90_4EC1B0_mgresultboard;
extern s8 D_8010AD94_4EC1B4_mgresultboard;

//updates mg star coins on results scene load
void func_801059A0_4E6DC0_mgresultboard(void) {
    omObjData* obj;
    s32 minigameType;
    s8 i;

    omInitObjMan(0x1E, 0x1E);
    func_8000B690_C290(2);
    for (i = 0; i < 2; i++) {
        ScissorSet(i, 0.0f, 0.0f, 320.0f, 240.0f);
        ViewportSet(i, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
        Hu3DCamSetPerspective(i, 30.0f, 80.0f, 8000.0f);        
    }

    obj = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = 2;
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    minigameType = D_800A6D44_A7944[GwSystem.minigame_index - 1].minigameType;

    if (minigameType < MINIGAME_ITEM) {
        if (minigameType >= MINIGAME_4P) {
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                u16 newMgStarCoins = GwPlayer[i].gameCoin + GwPlayer[i].bonusCoin + GwPlayer[i].gamePrize;
                GwPlayer[i].gamePrize = newMgStarCoins;
            }
        }
    }

    func_80107234_4E8654_mgresultboard();
    omAddPrcObj(func_80105C08_4E7028_mgresultboard, 0x1001, 0x2000, 0);
    omAddObj(0, 0, 0, -1, func_80105CE8_4E7108_mgresultboard);
    omAddObj(0, 0, 0, -1, func_80106F40_4E8360_mgresultboard);
    func_80106FC8_4E83E8_mgresultboard();
    func_80107188_4E85A8_mgresultboard();
    func_80106DE8_4E8208_mgresultboard();
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80105C08_4E7028_mgresultboard);

//main state machine behind scoreboard and how it animates
void func_80105CE8_4E7108_mgresultboard(omObjData* arg0) {
    PlayerResult* temp_v0_13;
    s32 temp_a1;
    s32 temp_a2;
    s16 var_a1;
    s32 temp_v0;
    s8 var_a0;
    u16 var_a0_3;
    u16 var_a1_3;
    s32 var_s3;
    s32 var_s5;
    u32 var_s4;
    s32 var_v1_3;
    PlayerResult* temp_a0_5;
    s8 i;
    s8 new_var;
    
    var_s5 = 0;
    var_s4 = D_8010AAF0_4EBF10_mgresultboard;
    var_s3 = 0;
    switch (var_s4) {
    case 0:
        HuAudSeqPlay(0x14);
        D_8010AD90_4EC1B0_mgresultboard = 0;
        var_s4++;
        break;
    case 1:
        if (D_8010AAF8_4EBF18_mgresultboard == 1) {
            WipeCreateIn(0xFF, 0x10);
            var_s4++;
        }
        break;
    case 2:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard >= 0x14) {
            D_8010AD94_4EC1B4_mgresultboard = 0;
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 3:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard >= ((s32) (40.0f / D_8010AAF4_4EBF14_mgresultboard) + (s32) (15.0f / D_8010AAF4_4EBF14_mgresultboard))) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            D_8010AD94_4EC1B4_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 4:
        D_8010AD94_4EC1B4_mgresultboard = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            //temp_v0_2 = D_8010B048_4EC468_mgresultboard[var_v1 >> 0x18].idx * 0x38;
            temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].bonusCoin;
            temp_a1 += GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].gameCoin;
            if (temp_a1 <= 0) {
                D_8010AD94_4EC1B4_mgresultboard++;
            }
        }

        if (D_8010AD94_4EC1B4_mgresultboard >= 4) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4 = 0x10;
        } else {
            D_8010AD94_4EC1B4_mgresultboard = 0;
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 5:
        var_s3 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            //temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].gameCoin;
            new_var = D_8010B048_4EC468_mgresultboard[i].idx;
            temp_a1 = GwPlayer[new_var].gameCoin;
            temp_a1 += GwPlayer[new_var].bonusCoin;
            if (temp_a1 > 0) {
                var_s5++;
                var_s3 = func_80106D88_4E81A8_mgresultboard(i, ((((rand8()) << 8) | (rand8())) % 1000));
                func_80107800_4E8C20_mgresultboard(i);               
            } else {
                func_80107650_4E8A70_mgresultboard(i);
            }
        }

        if (var_s3 == 1) {
            if (++D_8010AD90_4EC1B0_mgresultboard >= 2) {
                D_8010AD90_4EC1B0_mgresultboard = 0;
                var_s4++;
            }
        }
        break;
    case 6:
        var_s3 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].gameCoin;
            temp_a1 += GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].bonusCoin;
            if (temp_a1 > 0) {
                var_s3 = func_80106D88_4E81A8_mgresultboard(i, temp_a1);
                func_80107800_4E8C20_mgresultboard(i);
                var_s5++;
            } else {
                func_80107650_4E8A70_mgresultboard(i);
            }
        }

        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].bonusCoin;
            if (temp_a1 >= 10) {
                func_80106D50_4E8170_mgresultboard(i, 4);
                var_s5++;
            }
        }
        if (var_s3 == 1) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }

        break;
    case 7:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (!(D_8010AD90_4EC1B0_mgresultboard < ((s32) (40.0f / D_8010AAF4_4EBF14_mgresultboard) + (s32) (15.0f / D_8010AAF4_4EBF14_mgresultboard)))) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 8:
        var_s3 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].gameCoin;
            temp_a1 += GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].bonusCoin;
            if (temp_a1 > 0) {
                var_s5++;
                var_s3 = func_80106DB8_4E81D8_mgresultboard(i, ((((rand8()) << 8) | (rand8())) % 1000));
                func_80107800_4E8C20_mgresultboard(i);
                
            } else {
                func_80107650_4E8A70_mgresultboard(i);
            }
        }

        if (var_s3 == 1) {
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard >= 2) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break; //TODO: fallthrough?
        }
        break;
    case 9:
        var_s3 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_a2 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].coin;
            temp_a1 = GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].gameCoin;
            if ((temp_a1 += GwPlayer[D_8010B048_4EC468_mgresultboard[i].idx].bonusCoin) > 0) {  //TODO: this check is wrong i think
                var_s3 = func_80106DB8_4E81D8_mgresultboard(i, temp_a2 + temp_a1);
                func_80107800_4E8C20_mgresultboard(i);
                var_s5++;
            } else {
                func_80107650_4E8A70_mgresultboard(i);
            }
        }
 
        if (var_s3 == 1) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 10:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard < ((s32) (40.0f / D_8010AAF4_4EBF14_mgresultboard) + (s32) (15.0f / D_8010AAF4_4EBF14_mgresultboard))) {

        } else {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 11:
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            D_8010B018_4EC438_mgresultboard[i] = D_8010B048_4EC468_mgresultboard[i];
            new_var = D_8010B048_4EC468_mgresultboard[i].idx;
            temp_a2 = GwPlayer[new_var].coin;
            temp_a1 = GwPlayer[new_var].gameCoin;
            temp_a1 += GwPlayer[new_var].bonusCoin;
            
            if (temp_a2 + temp_a1 < 0x3E8){
                GwPlayer[new_var].coin = temp_a2 + temp_a1;
            } else {
                GwPlayer[new_var].coin = 0x3E7;
            }
            GwPlayer[new_var].gameCoin = 0;
            GwPlayer[new_var].bonusCoin = 0;
        }
        var_s4++;
        func_80107234_4E8654_mgresultboard();
        break;
    case 12:
        D_8010AD94_4EC1B4_mgresultboard = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            var_a0 = 0;
            if (D_8010B048_4EC468_mgresultboard[i].unk_01 != D_8010B018_4EC438_mgresultboard[i].unk_01) {
                D_8010AD94_4EC1B4_mgresultboard++;
                var_a0 = 1;
            }

            if (D_8010B048_4EC468_mgresultboard[i].idx != D_8010B018_4EC438_mgresultboard[i].idx) {
                D_8010AD94_4EC1B4_mgresultboard++;
                var_a0++;
            }

            if (D_8010B018_4EC438_mgresultboard[i].bonusCoin >= 10) {
                D_8010AD94_4EC1B4_mgresultboard++;
                var_a0++;
            }

            if (var_a0 > 0) {
                new_var = D_8010B048_4EC468_mgresultboard[i].idx; //??? why does this help so much
                if (GwPlayer[new_var].stat & 1) {
                    continue;
                } else {
                    omVibrate(new_var, 5, 0, 5);
                }
            }
        }

        if (D_8010AD94_4EC1B4_mgresultboard == 0) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4 = 0xF;
        } else {
            D_8010AD94_4EC1B4_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 13:
        var_s3 = 0;
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            var_a1 = D_8010B048_4EC468_mgresultboard[i].unk_01 != D_8010B018_4EC438_mgresultboard[i].unk_01;
            if (D_8010B048_4EC468_mgresultboard[i].idx != D_8010B018_4EC438_mgresultboard[i].idx) {
                var_a1 = 1;
            }
            if (D_8010B018_4EC438_mgresultboard[i].bonusCoin >= 10) {
                var_a1 = 1;
            }
            if (var_a1 == 1) {
                var_s3 = func_80106A80_4E7EA0_mgresultboard(i);
                func_80107800_4E8C20_mgresultboard(i);
                var_s5 += 1;
            } else {
                func_80107650_4E8A70_mgresultboard(i);
            }        
        }
 
        if (var_s3 == 1) {
            D_8010AD94_4EC1B4_mgresultboard += 1;
        }
        if (D_8010AD94_4EC1B4_mgresultboard >= 2) {
            D_8010AD94_4EC1B4_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 14:
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            var_a1 = D_8010B048_4EC468_mgresultboard[i].unk_01 != D_8010B018_4EC438_mgresultboard[i].unk_01;
            if (D_8010B048_4EC468_mgresultboard[i].idx != D_8010B018_4EC438_mgresultboard[i].idx) {
                var_a1 = 1;
            }
            if (D_8010B018_4EC438_mgresultboard[i].bonusCoin >= 10) {
                var_a1 = 1;
            }
            if (var_a1 == 1) {
                var_s3 = func_80106C80_4E80A0_mgresultboard(i);
                func_80107800_4E8C20_mgresultboard(i);
                var_s5++;
            }
        }

        if (var_s3 == 1) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 15:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard >= 0x1E) {
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                func_80107800_4E8C20_mgresultboard(i);
            }
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 16:
        D_8010AD90_4EC1B0_mgresultboard++;
        if (D_8010AD90_4EC1B0_mgresultboard >= 0x28) {
            D_8010AD90_4EC1B0_mgresultboard = 0;
            var_s4++;
        }
        break;
    case 17:
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            AdjustPlayerCoins(i, 0);
        }
        WipeCreateOut(0, 0x14);
        HuAudSeqFadeOut(0x1E);
        var_s4++;
        break;
    case 18:
        if (WipeStatGet() == 0) {
            func_80037258_37E58();
            func_800E69D8_FA5F8_shared_board();
            func_800E66E0_FA300_shared_board();
            omOvlReturnEx(1);
        }
        break;
    }
    
    if (var_s5 > 0) {
        func_801079B0_4E8DD0_mgresultboard(var_s5);
    } else {
        func_80107A58_4E8E78_mgresultboard();
    }
    
    D_8010AAF0_4EBF10_mgresultboard = var_s4;
    var_a0_3 = 0;
    var_a1_3 = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (!(GwPlayer[i].stat & 1)) {
            var_a0_3 |= D_800CDA7C_CE67C[GwPlayer[i].pad];
        } else {
            var_a1_3++;
        }
    }
    
    D_8010AAF4_4EBF14_mgresultboard = ((var_a0_3 & 0x8000) || (var_a1_3 >= 4)) ? 4.0f : 1.0f;
}


INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106A80_4E7EA0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106C80_4E80A0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106D50_4E8170_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106D88_4E81A8_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106DB8_4E81D8_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106DE8_4E8208_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80106F40_4E8360_mgresultboard);

void func_80106FC8_4E83E8_mgresultboard(void) {
    GW_SYSTEM* system = &GwSystem;

    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    
    if (!(system->playMode & 2)) {
        func_800E6720_FA340_shared_board(D_8010AD0C_4EC12C_mgresultboard[system->current_board_index], 0);
    } else {
        func_800E6720_FA340_shared_board(0x17, 0);
    }
    func_80107024_4E8444_mgresultboard();
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107024_4E8444_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010705C_4E847C_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107188_4E85A8_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107234_4E8654_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107650_4E8A70_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107800_4E8C20_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801079B0_4E8DD0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107A58_4E8E78_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107B40_4E8F60_mgresultboard);

void func_80107CEC_4E910C_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107CF4_4E9114_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD0C_4EC12C_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD24_4EC144_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD28_4EC148_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107D00_4E9120_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801080C4_4E94E4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108150_4E9570_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801081CC_4E95EC_mgresultboard);

void func_801081E8_4E9608_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801081F0_4E9610_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108250_4E9670_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108330_4E9750_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108700_4E9B20_mgresultboard);

void func_80108BBC_4E9FDC_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108BC4_4E9FE4_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80108C60_4EA080_mgresultboard);

void func_8010913C_4EA55C_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109144_4EA564_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801092E0_4EA700_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109498_4EA8B8_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109650_4EAA70_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801096E0_4EAB00_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109744_4EAB64_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109878_4EAC98_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109A90_4EAEB0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109CB0_4EB0D0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109D44_4EB164_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109DAC_4EB1CC_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80109F30_4EB350_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD58_4EC178_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A000_4EB420_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A334_4EB754_mgresultboard);

void func_8010A350_4EB770_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A358_4EB778_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A3E4_4EB804_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A454_4EB874_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A4A0_4EB8C0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A864_4EBC84_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010A930_4EBD50_mgresultboard);

void func_8010AADC_4EBEFC_mgresultboard(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010AAE4_4EBF04_mgresultboard);
