#include "common.h"

void func_80105C08_4E7028_name_71(void);
void func_80105CE8_4E7108_name_71(omObjData*);
void func_80106DE8_4E8208_name_71(void);
void func_80106F40_4E8360_name_71(omObjData*);
void func_80106FC8_4E83E8_name_71(void);
void func_80107188_4E85A8_name_71(void);
void func_80107234_4E8654_name_71(void);
void func_800E6630_FA250_shared_board(Addr);
void func_800E6720_FA340_shared_board(s32, s32);
void func_80107024_4E8444_name_71(void);
extern s32 D_8010AD0C_4EC12C_name_71[];

//updates mg star coins on results scene load
void func_801059A0_4E6DC0_name_71(void) {
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
            for (i = 0; i < MAX_PLAYERS; i++) {
                u16 newMgStarCoins = GwPlayer[i].gameCoin + GwPlayer[i].bonusCoin + GwPlayer[i].gamePrize;
                GwPlayer[i].gamePrize = newMgStarCoins;
            }
        }
    }

    func_80107234_4E8654_name_71();
    omAddPrcObj(func_80105C08_4E7028_name_71, 0x1001, 0x2000, 0);
    omAddObj(0, 0, 0, -1, func_80105CE8_4E7108_name_71);
    omAddObj(0, 0, 0, -1, func_80106F40_4E8360_name_71);
    func_80106FC8_4E83E8_name_71();
    func_80107188_4E85A8_name_71();
    func_80106DE8_4E8208_name_71();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80105C08_4E7028_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80105CE8_4E7108_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106A80_4E7EA0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106C80_4E80A0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106D50_4E8170_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106D88_4E81A8_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106DB8_4E81D8_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106DE8_4E8208_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80106F40_4E8360_name_71);

void func_80106FC8_4E83E8_name_71(void) {
    GW_SYSTEM* system = &GwSystem;

    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    
    if (!(system->playMode & 2)) {
        func_800E6720_FA340_shared_board(D_8010AD0C_4EC12C_name_71[system->current_board_index], 0);
    } else {
        func_800E6720_FA340_shared_board(0x17, 0);
    }
    func_80107024_4E8444_name_71();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107024_4E8444_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010705C_4E847C_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107188_4E85A8_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107234_4E8654_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107650_4E8A70_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107800_4E8C20_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801079B0_4E8DD0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107A58_4E8E78_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107B40_4E8F60_name_71);

void func_80107CEC_4E910C_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107CF4_4E9114_name_71);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", D_8010AD0C_4EC12C_name_71);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", D_8010AD24_4EC144_name_71);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", D_8010AD28_4EC148_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80107D00_4E9120_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801080C4_4E94E4_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108150_4E9570_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801081CC_4E95EC_name_71);

void func_801081E8_4E9608_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801081F0_4E9610_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108250_4E9670_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108330_4E9750_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108700_4E9B20_name_71);

void func_80108BBC_4E9FDC_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108BC4_4E9FE4_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80108C60_4EA080_name_71);

void func_8010913C_4EA55C_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109144_4EA564_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801092E0_4EA700_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109498_4EA8B8_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109650_4EAA70_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_801096E0_4EAB00_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109744_4EAB64_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109878_4EAC98_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109A90_4EAEB0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109CB0_4EB0D0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109D44_4EB164_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109DAC_4EB1CC_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_80109F30_4EB350_name_71);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", D_8010AD58_4EC178_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A000_4EB420_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A334_4EB754_name_71);

void func_8010A350_4EB770_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A358_4EB778_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A3E4_4EB804_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A454_4EB874_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A4A0_4EB8C0_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A864_4EBC84_name_71);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010A930_4EBD50_name_71);

void func_8010AADC_4EBEFC_name_71(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_71_name/4E6DC0", func_8010AAE4_4EBF04_name_71);
