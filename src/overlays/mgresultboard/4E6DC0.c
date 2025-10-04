#include "common.h"

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

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultboard/4E6DC0", func_80105CE8_4E7108_mgresultboard);

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
