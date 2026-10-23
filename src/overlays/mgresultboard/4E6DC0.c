#include "common.h"
#include "../ovl_80_shared_board/105D50.h"

typedef struct PlayerResult {
    /* 0x00 */ s8 idx;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s16 score;
    /* 0x06 */ s16 coin;
    /* 0x08 */ s16 gameCoin;
    /* 0x0A */ s16 bonusCoin;
} PlayerResult; // sizeof 0x0C
extern PlayerResult D_8010B018_mgresultboard[4];
extern PlayerResult D_8010B048_mgresultboard[4];
extern s8 D_8010AAFC_mgresultboard;

void func_8000BBFC_main(u16, u8);
void func_8000BC48_main(u16, u16); 
void func_8000BEAC_main(u16, u8, u8, u8);
void func_8010705C_mgresultboard(Gfx**, s32, s32);
void func_80107B40_mgresultboard(void);
void func_80107D00_mgresultboard(void);
void func_80108700_mgresultboard(void);
void func_8010A000_mgresultboard(void);
void func_8010A930_mgresultboard(void);
void func_80105C08_mgresultboard(void);
void func_80105CE8_mgresultboard(omObjData *);
void func_80106DE8_mgresultboard(void);
void func_80106F40_mgresultboard(omObjData *);
void func_80106FC8_mgresultboard(void);
void func_80107188_mgresultboard(void);
void func_80107234_mgresultboard(void);
void func_800E6630_shared_board(u32);
void MBBackCreate(s32, s32);
void func_80107024_mgresultboard(void);
extern s32 D_8010AD0C_mgresultboard[];
void MBBackClose(void);
void MBBackKill(void);
s32 func_80106A80_mgresultboard(s8);
s32 func_80106C80_mgresultboard(s8);
s32 func_80106D50_mgresultboard(s32, s32);
s32 func_80106D88_mgresultboard(s32, s16);
s32 func_80106DB8_mgresultboard(s8, s16);
void func_80107234_mgresultboard(void);
void func_80107650_mgresultboard(s8);
void func_80107800_mgresultboard(s32);
void func_801079B0_mgresultboard(s32);
void func_80107A58_mgresultboard(void);
s32 func_80109A90_mgresultboard(s32, s8, s16);

typedef struct Unk {
    s32 unk_00;
} Unk;

extern Unk D_8010AEA0_mgresultboard; //unknown size
extern u32 D_8010AAF0_mgresultboard;
extern f32 D_8010AAF4_mgresultboard;
extern s32 D_8010AAF8_mgresultboard;
extern s32 D_8010AD90_mgresultboard;
extern s8 D_8010AD94_mgresultboard;
s32 func_8010A864_mgresultboard(omObjData *, s8, s8); /* extern */
extern omObjData *D_8010AFE0_mgresultboard;

// updates mg star coins on results scene load
void func_801059A0_mgresultboard(void) {
    omObjData *obj;
    s32 minigameType;
    s8 i;

    omInitObjMan(0x1E, 0x1E);
    func_8000B690_main(2);
    for (i = 0; i < 2; i++) {
        ScissorSet(i, 0.0f, 0.0f, 320.0f, 240.0f);
        ViewportSet(i, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
        Hu3DCamSetPerspective(i, 30.0f, 80.0f, 8000.0f);
    }

    obj = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = 2;
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    minigameType = D_800A6D44_main[GwSystem.minigame_index - 1].minigameType;

    if (minigameType < MINIGAME_ITEM) {
        if (minigameType >= MINIGAME_4P) {
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                u16 newMgStarCoins = GwPlayer[i].gameCoin + GwPlayer[i].bonusCoin + GwPlayer[i].gamePrize;
                GwPlayer[i].gamePrize = newMgStarCoins;
            }
        }
    }

    func_80107234_mgresultboard();
    omAddPrcObj(func_80105C08_mgresultboard, 0x1001, 0x2000, 0);
    omAddObj(0, 0, 0, -1, func_80105CE8_mgresultboard);
    omAddObj(0, 0, 0, -1, func_80106F40_mgresultboard);
    func_80106FC8_mgresultboard();
    func_80107188_mgresultboard();
    func_80106DE8_mgresultboard();
}

void func_80105C08_mgresultboard(void) {
    D_8010AAF8_mgresultboard = 0;
    HuPrcSleep(2);
    omAddPrcObj(func_8010A000_mgresultboard, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80107D00_mgresultboard, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80107B40_mgresultboard, 0x1001, 0x2000, 0);
    omAddPrcObj(func_8010A930_mgresultboard, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80108700_mgresultboard, 0x1001, 0x2000, 0);
    HuPrcVSleep();
    func_80106C80_mgresultboard(0);
    func_80106C80_mgresultboard(1);
    func_80106C80_mgresultboard(2);
    func_80106C80_mgresultboard(3);
    D_8010AAF8_mgresultboard = 1;
    while (1) {
        HuPrcVSleep();
    }
}

// main state machine behind scoreboard and how it animates
void func_80105CE8_mgresultboard(omObjData *arg0) {
    PlayerResult *temp_v0_13;
    s32 coinTotal;
    s32 currentCoin;
    s16 var_a1;
    s32 temp_v0;
    s8 var_a0;
    u16 buttonPressed;
    u16 cpuCount;
    s32 var_s3;
    s32 var_s5;
    u32 state;
    s32 var_v1_3;
    PlayerResult *temp_a0_5;
    s8 i;
    s8 playerIdx;

    var_s5 = 0;
    state = D_8010AAF0_mgresultboard;
    var_s3 = 0;

    switch (state) {
        case 0:
            HuAudSeqPlay(0x14);
            D_8010AD90_mgresultboard = 0;
            state++;
            break;
        case 1:
            if (D_8010AAF8_mgresultboard == 1) {
                WipeCreateIn(0xFF, 0x10);
                state++;
            }
            break;
        case 2:
            D_8010AD90_mgresultboard++;
            if (D_8010AD90_mgresultboard >= 0x14) {
                D_8010AD94_mgresultboard = 0;
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 3:
            D_8010AD90_mgresultboard++;
            if (D_8010AD90_mgresultboard >= ((s32)(40.0f / D_8010AAF4_mgresultboard) + (s32)(15.0f / D_8010AAF4_mgresultboard))) {
                D_8010AD90_mgresultboard = 0;
                D_8010AD94_mgresultboard = 0;
                state++;
            }
            break;
        case 4:
            D_8010AD94_mgresultboard = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                coinTotal = GwPlayer[D_8010B048_mgresultboard[i].idx].bonusCoin;
                coinTotal += GwPlayer[D_8010B048_mgresultboard[i].idx].gameCoin;
                if (coinTotal <= 0) {
                    D_8010AD94_mgresultboard++;
                }
            }

            if (D_8010AD94_mgresultboard >= 4) {
                D_8010AD90_mgresultboard = 0;
                state = 0x10;
            } else {
                D_8010AD94_mgresultboard = 0;
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 5:
            var_s3 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                playerIdx = D_8010B048_mgresultboard[i].idx;
                coinTotal = GwPlayer[playerIdx].gameCoin;
                coinTotal += GwPlayer[playerIdx].bonusCoin;
                if (coinTotal > 0) {
                    var_s5++;
                    var_s3 = func_80106D88_mgresultboard(i, ((((rand8()) << 8) | (rand8())) % 1000));
                    func_80107800_mgresultboard(i);
                } else {
                    func_80107650_mgresultboard(i);
                }
            }

            if (var_s3 == 1) {
                if (++D_8010AD90_mgresultboard >= 2) {
                    D_8010AD90_mgresultboard = 0;
                    state++;
                }
            }
            break;
        case 6:
            var_s3 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                coinTotal = GwPlayer[D_8010B048_mgresultboard[i].idx].gameCoin;
                coinTotal += GwPlayer[D_8010B048_mgresultboard[i].idx].bonusCoin;
                if (coinTotal > 0) {
                    var_s3 = func_80106D88_mgresultboard(i, coinTotal);
                    func_80107800_mgresultboard(i);
                    var_s5++;
                } else {
                    func_80107650_mgresultboard(i);
                }
            }

            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                coinTotal = GwPlayer[D_8010B048_mgresultboard[i].idx].bonusCoin;
                if (coinTotal >= 10) {
                    func_80106D50_mgresultboard(i, 4);
                    var_s5++;
                }
            }
            if (var_s3 == 1) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }

            break;
        case 7:
            D_8010AD90_mgresultboard++;
            if (!(D_8010AD90_mgresultboard < ((s32)(40.0f / D_8010AAF4_mgresultboard) + (s32)(15.0f / D_8010AAF4_mgresultboard)))) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 8:
            var_s3 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                coinTotal = GwPlayer[D_8010B048_mgresultboard[i].idx].gameCoin;
                coinTotal += GwPlayer[D_8010B048_mgresultboard[i].idx].bonusCoin;
                if (coinTotal > 0) {
                    var_s5++;
                    var_s3 = func_80106DB8_mgresultboard(i, ((((rand8()) << 8) | (rand8())) % 1000));
                    func_80107800_mgresultboard(i);

                } else {
                    func_80107650_mgresultboard(i);
                }
            }

            if (var_s3 == 1) {
                D_8010AD90_mgresultboard++;
                if (D_8010AD90_mgresultboard >= 2) {
                    D_8010AD90_mgresultboard = 0;
                    state++;
                }
                break;
            }
            break;
        case 9:
            var_s3 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                currentCoin = GwPlayer[D_8010B048_mgresultboard[i].idx].coin;
                coinTotal = GwPlayer[D_8010B048_mgresultboard[i].idx].gameCoin;
                if ((coinTotal += GwPlayer[D_8010B048_mgresultboard[i].idx].bonusCoin) > 0) {
                    var_s3 = func_80106DB8_mgresultboard(i, currentCoin + coinTotal);
                    func_80107800_mgresultboard(i);
                    var_s5++;
                } else {
                    func_80107650_mgresultboard(i);
                }
            }

            if (var_s3 == 1) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 10:
            D_8010AD90_mgresultboard++;
            if (!(D_8010AD90_mgresultboard < ((s32)(40.0f / D_8010AAF4_mgresultboard) + (s32)(15.0f / D_8010AAF4_mgresultboard)))) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 11:
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                D_8010B018_mgresultboard[i] = D_8010B048_mgresultboard[i];
                playerIdx = D_8010B048_mgresultboard[i].idx;
                currentCoin = GwPlayer[playerIdx].coin;
                coinTotal = GwPlayer[playerIdx].gameCoin;
                coinTotal += GwPlayer[playerIdx].bonusCoin;

                if (currentCoin + coinTotal < 0x3E8) {
                    GwPlayer[playerIdx].coin = currentCoin + coinTotal;
                } else {
                    GwPlayer[playerIdx].coin = 0x3E7;
                }
                GwPlayer[playerIdx].gameCoin = 0;
                GwPlayer[playerIdx].bonusCoin = 0;
            }
            state++;
            func_80107234_mgresultboard();
            break;
        case 12:
            D_8010AD94_mgresultboard = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                var_a0 = 0;
                if (D_8010B048_mgresultboard[i].unk_01 != D_8010B018_mgresultboard[i].unk_01) {
                    D_8010AD94_mgresultboard++;
                    var_a0 = 1;
                }

                if (D_8010B048_mgresultboard[i].idx != D_8010B018_mgresultboard[i].idx) {
                    D_8010AD94_mgresultboard++;
                    var_a0++;
                }

                if (D_8010B018_mgresultboard[i].bonusCoin >= 10) {
                    D_8010AD94_mgresultboard++;
                    var_a0++;
                }

                if (var_a0 > 0) {
                    playerIdx = D_8010B048_mgresultboard[i].idx; //??? why does this help so much
                    if (GwPlayer[playerIdx].stat & 1) {
                        continue;
                    } else {
                        omVibrate(playerIdx, 5, 0, 5);
                    }
                }
            }

            if (D_8010AD94_mgresultboard == 0) {
                D_8010AD90_mgresultboard = 0;
                state = 0xF;
            } else {
                D_8010AD94_mgresultboard = 0;
                state++;
            }
            break;
        case 13:
            var_s3 = 0;
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                var_a1 = D_8010B048_mgresultboard[i].unk_01 != D_8010B018_mgresultboard[i].unk_01;
                if (D_8010B048_mgresultboard[i].idx != D_8010B018_mgresultboard[i].idx) {
                    var_a1 = 1;
                }
                if (D_8010B018_mgresultboard[i].bonusCoin >= 10) {
                    var_a1 = 1;
                }
                if (var_a1 == 1) {
                    var_s3 = func_80106A80_mgresultboard(i);
                    func_80107800_mgresultboard(i);
                    var_s5 += 1;
                } else {
                    func_80107650_mgresultboard(i);
                }
            }

            if (var_s3 == 1) {
                D_8010AD94_mgresultboard += 1;
            }
            if (D_8010AD94_mgresultboard >= 2) {
                D_8010AD94_mgresultboard = 0;
                state++;
            }
            break;
        case 14:
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                var_a1 = D_8010B048_mgresultboard[i].unk_01 != D_8010B018_mgresultboard[i].unk_01;
                if (D_8010B048_mgresultboard[i].idx != D_8010B018_mgresultboard[i].idx) {
                    var_a1 = 1;
                }
                if (D_8010B018_mgresultboard[i].bonusCoin >= 10) {
                    var_a1 = 1;
                }
                if (var_a1 == 1) {
                    var_s3 = func_80106C80_mgresultboard(i);
                    func_80107800_mgresultboard(i);
                    var_s5++;
                }
            }

            if (var_s3 == 1) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 15:
            D_8010AD90_mgresultboard++;
            if (D_8010AD90_mgresultboard >= 30) {
                for (i = 0; i < MB_MAX_PLAYERS; i++) {
                    func_80107800_mgresultboard(i);
                }
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 16:
            D_8010AD90_mgresultboard++;
            if (D_8010AD90_mgresultboard >= 40) {
                D_8010AD90_mgresultboard = 0;
                state++;
            }
            break;
        case 17:
            for (i = 0; i < MB_MAX_PLAYERS; i++) {
                MBPlayerCoinAdd(i, 0);
            }
            WipeCreateOut(0, 0x14);
            HuAudSeqFadeOut(0x1E);
            state++;
            break;
        case 18:
            if (WipeStatGet() == 0) {
                func_80037258_main();
                MBBackKill();
                MBBackClose();
                omOvlReturnEx(1);
            }
            break;
    }

    if (var_s5 > 0) {
        func_801079B0_mgresultboard(var_s5);
    } else {
        func_80107A58_mgresultboard();
    }

    D_8010AAF0_mgresultboard = state;
    buttonPressed = 0;
    cpuCount = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (!(GwPlayer[i].stat & 1)) {
            buttonPressed |= D_800CDA7C_main[GwPlayer[i].pad];
        } else {
            cpuCount++;
        }
    }

    D_8010AAF4_mgresultboard = ((buttonPressed & 0x8000) || (cpuCount >= 4)) ? 4.0f : 1.0f;
}

s32 func_80108250_mgresultboard(s32, s32, s8, s8);  /* extern */
s32 func_801092E0_mgresultboard(s32, s32, s16);     /* extern */
s32 func_80109878_mgresultboard(s32, s32, s16);     /* extern */
extern s32 D_8010AFA8_mgresultboard;

s32 func_80106A80_mgresultboard(s8 arg0) {
    u16 var_s0;
    s32 var_s3;

    var_s0 = rand16();
    var_s3 = 0;

    if (func_8010A864_mgresultboard(D_8010AFE0_mgresultboard, arg0, var_s0 & 3) == 1) {
        var_s3 = 1;
        var_s0 = rand16();
    }
    if (func_80108250_mgresultboard(D_8010AFA8_mgresultboard, arg0, D_8010B048_mgresultboard[var_s0 & 3].unk_02, ((var_s0 / 8) % 3)) == 1) {
        var_s0 = rand16();
    }
    if (func_801092E0_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, ((var_s0) % 100)) == 1) {
        var_s0 = rand16();
    }
    if (func_80109878_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, ((var_s0) % 1000)) == 1) {
        rand8();
        rand8();
    }
    return var_s3;
}

s32 func_80106C80_mgresultboard(s8 arg0) {
    s32 temp_s3;

    temp_s3 = func_8010A864_mgresultboard(D_8010AFE0_mgresultboard, arg0, D_8010B048_mgresultboard[arg0].unk_01) == 1;
    func_80108250_mgresultboard(D_8010AFA8_mgresultboard, arg0, D_8010B048_mgresultboard[arg0].unk_02, D_8010B048_mgresultboard[arg0].unk_03);
    func_801092E0_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, D_8010B048_mgresultboard[arg0].score);
    func_80109878_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, D_8010B048_mgresultboard[arg0].coin);
    return temp_s3;
}


s32 func_80106D50_mgresultboard(s32 arg0, s32 arg1) {
    if (func_8010A864_mgresultboard(D_8010AFE0_mgresultboard, arg0, arg1) ^ 1) {
        return 0;
    } else {
        return 1;
    }
}

s32 func_80106D88_mgresultboard(s32 arg0, s16 arg1) {
    return func_80109A90_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, arg1);
}

s32 func_80106DB8_mgresultboard(s8 arg0, s16 arg1) {
    return func_80109878_mgresultboard(D_8010AEA0_mgresultboard.unk_00, arg0, arg1);
}

void func_80106DE8_mgresultboard(void) {
    f32 fov = 30.0f;
    s8 i;

    CZoom = 1652.7628f;
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 26.4f;
    Center.z = -1050.0f;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        CRotM[i] = CRot;
        CenterM[i] = Center;
        CZoomM[i] = CZoom;
        Hu3DCamSetPerspective(i, fov, 80.0f, 8000.0f);        
    }
}

void func_80106F40_mgresultboard(omObjData* arg0) {
    if (D_800D530C_main == 1) {
        if (D_8010AAFC_mgresultboard == 0) {
            WipeCreateOut(0, 0x14);
            D_8010AAFC_mgresultboard = 1;
            return;
        }
        if (WipeStatGet() == 0) {
            HuAudSeqFadeOut(30);
            func_80037258_main();
            MBBackKill();
            MBBackClose();
            omOvlReturnEx(1);
        }
    }
}

void func_80106FC8_mgresultboard(void) {
    GW_SYSTEM *system = &GwSystem;

    func_800E6630_shared_board((u32)hvq_data_ROM_START);

    if (!(system->playMode & 2)) {
        MBBackCreate(D_8010AD0C_mgresultboard[system->current_board_index], 0);
    } else {
        MBBackCreate(0x17, 0);
    }
    func_80107024_mgresultboard();
}

void func_80107024_mgresultboard(void) {
    func_8001C8A8_main(func_8001AC8C_main(0, func_8010705C_mgresultboard, 2), 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_8010705C_mgresultboard);

void func_80107188_mgresultboard(void) {
    u16 temp_s0;

    temp_s0 = InitEspriteSlot(func_8000B838_main(0x18000A), 0, 0);
    func_8000BBD4_main(temp_s0, 0xA0, 0x20);
    func_8000BC48_main(temp_s0, 0x1000);
    func_8000BBFC_main(temp_s0, 0xFF);
    func_8000BEAC_main(temp_s0, 0xFF, 0xFF, 0xFF);
    func_8000BBD4_main(InitEspriteSlot(func_8000B838_main(0x180009), 0, 0), 0xA0, 0x20);
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107234_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107650_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107800_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_801079B0_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107A58_mgresultboard);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80107B40_mgresultboard);

void func_80107CEC_mgresultboard(void) {
}

void func_80107CF4_mgresultboard(void) {
}

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD0C_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD24_mgresultboard);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultboard/4E6DC0", D_8010AD28_mgresultboard);
