#include "ChillyWaters.h"
#include "../ovl_80_shared_board/ovl_80.h"

// Get toad space index for current start space index.
s16 func_80105E80_31B9F0_ChillyWaters(void) {
    return D_8011D2C0_332E30_ChillyWaters[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80105EA8_31BA18_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80105FB0_31BB20_ChillyWaters);

void func_8010603C_31BBAC_ChillyWaters(void) {
    GW_SYSTEM* system = &GwSystem;
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_8011D2A0_332E10_ChillyWaters); i++) {
        GWBoardFlagSet(D_8011D2A0_332E10_ChillyWaters[i]);
    }

    SetSpaceType(D_8011D2B0_332E20_ChillyWaters[system->star_spawn_indices[system->current_star_spawn]], 0xE);
    GWBoardFlagClear(D_8011D2A0_332E10_ChillyWaters[system->star_spawn_indices[system->current_star_spawn]]);
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801060E0_31BC50_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80106154_31BCC4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80106544_31C0B4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801065D0_31C140_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010698C_31C4FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80106EEC_31CA5C_ChillyWaters);

// View board map
void func_80106F60_31CAD0_ChillyWaters(void) {
    D_800CDD58_CE958 = 1;
    D_800D037C_D0F7C = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800CDD58_CE958 = 0;
    D_800D037C_D0F7C = 1;
}

// Exit the board map?
void func_80106FE8_31CB58_ChillyWaters(void) {
    D_800D037C_D0F7C = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
    D_800D037C_D0F7C = 1;
}

// setup arrows used during player direction decisions.
void func_80107044_31CBB4_ChillyWaters(void) {
    while (func_800E9AE0_FD700_shared_board() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_8011FAC0_335630_ChillyWaters = func_800E210C_F5D2C_shared_board(0, 0x92, 1);
    D_8011FAC4_335634_ChillyWaters = func_800E210C_F5D2C_shared_board(1, 0xA0, 1);
    D_8011FAD0_335640_ChillyWaters = func_800E210C_F5D2C_shared_board(0xD, 0xAE, 1);
    D_8011FAC8_335638_ChillyWaters = func_800E210C_F5D2C_shared_board(3, 0xBC, 1);
    D_8011FACC_33563C_ChillyWaters = func_800E210C_F5D2C_shared_board(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800CDD58_CE958 = 1;
    D_800D51F8_D5DF8 = 1;
}

// teardown arrows
void func_80107114_31CC84_ChillyWaters(void) {
    D_800CDD58_CE958 = 0;
    D_800D51F8_D5DF8 = 0;
    func_800E21F4_F5E14_shared_board(D_8011FAC0_335630_ChillyWaters);
    func_800E21F4_F5E14_shared_board(D_8011FAC4_335634_ChillyWaters);
    func_800E21F4_F5E14_shared_board(D_8011FAD0_335640_ChillyWaters);
    func_800E21F4_F5E14_shared_board(D_8011FAC8_335638_ChillyWaters);
    func_800E21F4_F5E14_shared_board(D_8011FACC_33563C_ChillyWaters);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107174_31CCE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107408_31CF78_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107620_31D190_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107750_31D2C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801078E8_31D458_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107BB4_31D724_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80107BD4_31D744_ChillyWaters);

//entrypoint 0
void func_80107BF4_31D764_ChillyWaters(void) {
    GwSystem.current_board_index = 0;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x47, 0, 0x192);
}

//entrypoint 1
void func_80107C2C_31D79C_ChillyWaters(void) {
    omInitObjMan(0xA, 0);
    func_800ED91C_10153C_shared_board(0, 0, 0);
    func_800ED91C_10153C_shared_board(1, 0, 0);
    func_800ED91C_10153C_shared_board(2, 0, 0);
    func_800ED91C_10153C_shared_board(3, 0, 0);
    GWBoardFlagSet(3);
    func_80105EA8_31BA18_ChillyWaters();
    GWBoardFlagClear(0x12);
    GwSystem.bank_coins = 0;
    GwSystem.slow_dice_flags = 0;
    GwSystem.unk_54 = 0;
    GwSystem.boardData.halfWordBytes[1] = 0;
    omOvlReturnEx(1);
}

void func_80107CC4_31D834_ChillyWaters(void) {
    Vec sp10;
    SpaceData* space;
    s32 i;

    omInitObjMan(0xA0, 0x28);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(2, 0xC8, 0xC8, 0xC8);
    func_800F89D0_10C5F0_shared_board(3, 0x23A, 5, 0);
    func_800EBCFC_FF91C_shared_board(&D_8011D31C_332E8C_ChillyWaters);
    func_800EBD54_FF974_shared_board(&D_8011D320_332E90_ChillyWaters);
    space = GetSpaceData(0x77);
    func_800ECB58_100778_shared_board(&space->coords, &GetSpaceData(0x73)->coords, &sp10);
    func_800EA660_FE280_shared_board(func_800D8790_EC3B0_shared_board(&sp10) + 180.0f);
    space = GetSpaceData(0x7C);
    func_800ECB58_100778_shared_board(&space->coords, &GetSpaceData(0x6E)->coords, &sp10);
    func_800EA660_FE280_shared_board(func_800D8790_EC3B0_shared_board(&sp10) + 180.0f);
    space = GetSpaceData(0x8F);
    func_800ECB58_100778_shared_board(&space->coords, &GetSpaceData(0x80)->coords, &sp10);
    func_800EA660_FE280_shared_board(func_800D8790_EC3B0_shared_board(&sp10) + 180.0f);
    func_800E2960_F6580_shared_board(0, &func_8010DE7C_3239EC_ChillyWaters); //boo event
    func_800E2960_F6580_shared_board(1, &func_8010F2FC_324E6C_ChillyWaters); //magic lamp
    func_800E2960_F6580_shared_board(9, &func_8010F6C4_325234_ChillyWaters);
    func_800E2960_F6580_shared_board(2, &func_8010F730_3252A0_ChillyWaters); //warp block
    func_800E2960_F6580_shared_board(3, &func_80117C60_32D7D0_ChillyWaters); //plunder chest
    func_800E2960_F6580_shared_board(4, &func_8011093C_3264AC_ChillyWaters); //activate bowser suit
    func_800E2960_F6580_shared_board(5, &func_80110BC8_326738_ChillyWaters); //when landing on a space as bowser suit
    func_800E2960_F6580_shared_board(6, &func_8010FC24_325794_ChillyWaters); //mushroom/golden mushroom/bowser suit
    func_800E2960_F6580_shared_board(7, &func_80110194_325D04_ChillyWaters); //dueling glove/boo bell (?)
    func_800E2960_F6580_shared_board(8, &func_801104E0_326050_ChillyWaters);
    func_800E2960_F6580_shared_board(0xA, &func_80116F5C_32CACC_ChillyWaters); //poison mushroom
    func_800E2960_F6580_shared_board(0xB, &func_801177DC_32D34C_ChillyWaters); //reverse mushroom
    func_800E2960_F6580_shared_board(0xE, &func_80111018_326B88_ChillyWaters);
    func_800E2960_F6580_shared_board(0xF, &func_801112D8_326E48_ChillyWaters); //bowser phone
    func_800E2960_F6580_shared_board(0x10, &func_80111678_3271E8_ChillyWaters); //lucky lamp
    func_800E2960_F6580_shared_board(0x11, &func_80112074_327BE4_ChillyWaters); //skeleton key throw away event
    func_800E2960_F6580_shared_board(0x12, &func_80112BCC_32873C_ChillyWaters); //boo repellant/koopa kard thrown away
    func_800E2960_F6580_shared_board(0x13, &func_801138E4_329454_ChillyWaters); //barter box
    func_800E2960_F6580_shared_board(0x14, &func_80114B80_32A6F0_ChillyWaters); //game guy coin
    func_800E2960_F6580_shared_board(0x15, &ItemUseWackyWatch); //wacky watch
    func_800E2960_F6580_shared_board(0xC, &func_80116DAC_32C91C_ChillyWaters);
    func_800E2960_F6580_shared_board(0xD, &func_801176A4_32D214_ChillyWaters);
    func_800DA748_EE368_shared_board(&func_8011C88C_3323FC_ChillyWaters);

    for (i = 0; i < ARRAY_COUNT(D_8011D2C0_332E30_ChillyWaters); i++) {
        func_800EA6E0_FE300_shared_board(i, D_8011D2C0_332E30_ChillyWaters[i]);
    }

    if (GWBoardFlagCheck(0xE) != 0) {
        GWBoardFlagClear(0xE);
        func_80105FB0_31BB20_ChillyWaters();
    }

    func_8010603C_31BBAC_ChillyWaters();
    func_80108250_31DDC0_ChillyWaters();
    func_8010841C_31DF8C_ChillyWaters();
    func_801086E0_31E250_ChillyWaters();
    func_801088B4_31E424_ChillyWaters();
    func_80108B24_31E694_ChillyWaters();
    func_80108BA4_31E714_ChillyWaters();
    func_80116AA0_32C610_ChillyWaters();
    func_800EBDAC_FF9CC_shared_board();
    omAddPrcObj(func_80118B7C_32E6EC_ChillyWaters, 0x4800, 0, 0);
}

//entrypoint 2
void func_80108014_31DB84_ChillyWaters(void) {
    HuAudSeqPlay(0x18);
    D_800CE194_CED94[2] = 0x18;
    func_800F8D6C_10C98C_shared_board(0x18);
    Hu3DCamInit(2);
    func_80107CC4_31D834_ChillyWaters();
    func_800EBA60_FF680_shared_board(&D_8011E2CC_333E3C_ChillyWaters);
    func_800EBA60_FF680_shared_board(&D_8011E718_334288_ChillyWaters);
    func_800F8D48_10C968_shared_board(&func_8011A8D8_330448_ChillyWaters);
    func_800EBA60_FF680_shared_board(&D_8011E344_333EB4_ChillyWaters);
    func_800EBA60_FF680_shared_board(&D_8011E4D8_334048_ChillyWaters);
    func_800FF41C_11303C_shared_board(0);
}

//entrypoint 3
void func_80108098_31DC08_ChillyWaters(void) {
    Hu3DCamInit(1);
    func_80107CC4_31D834_ChillyWaters();
    func_800FF41C_11303C_shared_board(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801080C4_31DC34_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801081EC_31DD5C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108250_31DDC0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801082FC_31DE6C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010841C_31DF8C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108478_31DFE8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108574_31E0E4_ChillyWaters);

void func_801086E0_31E250_ChillyWaters(void) {
    s32 i;

    D_8011FB10_335680_ChillyWaters = 0;
    for (i = 0; i < ARRAY_COUNT(D_8011FB18_335688_ChillyWaters); i++) {
        D_8011FB18_335688_ChillyWaters[i] = 0;
        func_80108574_31E0E4_ChillyWaters(i);
    }
    func_80108478_31DFE8_ChillyWaters();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108748_31E2B8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801088B4_31E424_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108914_31E484_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108970_31E4E0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108A38_31E5A8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108AE8_31E658_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108B24_31E694_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108BA4_31E714_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108C1C_31E78C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108CA4_31E814_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108CC8_31E838_ChillyWaters);

void func_80108D28_31E898_ChillyWaters(void) {
    func_80116484_32BFF4_ChillyWaters(&D_8011DA84_3335F4_ChillyWaters, &D_8011DA98_333608_ChillyWaters, &D_8011D578_3330E8_ChillyWaters);
    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108D60_31E8D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108D98_31E908_ChillyWaters);

void func_80108DD0_31E940_ChillyWaters(void) {
    GW_PLAYER* player;

    player = GetPlayerStruct(CUR_PLAYER);
    if ((func_800EB184_FEDA4_shared_board(player->blink, player->bidx) == 0x4B) && !(player->rev & FLAG_UNK_80)) {
        func_800ED998_1015B8_shared_board(-1, 0xA, 0);
        player->rev &= ~FLAG_REV;
    } else {
        func_80116484_32BFF4_ChillyWaters(D_8011DB5C_3336CC_ChillyWaters, D_8011DB70_3336E0_ChillyWaters, D_8011D77C_3332EC_ChillyWaters);
    }
    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80108E80_31E9F0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109390_31EF00_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801093C8_31EF38_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109400_31EF70_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109430_31EFA0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109474_31EFE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801094A4_31F014_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801094E8_31F058_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109518_31F088_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010955C_31F0CC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010958C_31F0FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801095D0_31F140_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109600_31F170_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109644_31F1B4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109674_31F1E4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801096B8_31F228_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109718_31F288_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010973C_31F2AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109760_31F2D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109784_31F2F4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801097E4_31F354_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109808_31F378_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010982C_31F39C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109850_31F3C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109874_31F3E4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801098D4_31F444_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801098F8_31F468_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010991C_31F48C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109940_31F4B0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109964_31F4D4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109988_31F4F8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099AC_31F51C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099D0_31F540_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801099F4_31F564_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A28_31F598_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A6C_31F5DC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109A90_31F600_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109AB4_31F624_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109AD8_31F648_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109E84_31F9F4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EB4_31FA24_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109EF8_31FA68_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80109F54_31FAC4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A068_31FBD8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A098_31FC08_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A134_31FCA4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A3B8_31FF28_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A474_31FFE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A4B4_320024_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010A860_3203D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B394_320F04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B41C_320F8C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B484_320FF4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010B65C_3211CC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010C914_322484_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010C9B4_322524_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010CA54_3225C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010CE9C_322A0C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010CEC0_322A30_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010DCEC_32385C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010DE40_3239B0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010DE7C_3239EC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F050_324BC0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F06C_324BDC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F088_324BF8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F1E4_324D54_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F2FC_324E6C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F6C4_325234_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F730_3252A0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010F8F0_325460_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010FB54_3256C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010FC24_325794_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8010FE54_3259C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110024_325B94_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110194_325D04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801104E0_326050_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801106A4_326214_ChillyWaters);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", D_8011F940_3354B0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011093C_3264AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110BC8_326738_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80110E08_326978_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80111018_326B88_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801112D8_326E48_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80111678_3271E8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112074_327BE4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801125BC_32812C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801127D8_328348_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112BCC_32873C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112C88_3287F8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112DDC_32894C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112E18_328988_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80112FA8_328B18_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80113364_328ED4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801135FC_32916C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80113708_329278_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801138E4_329454_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114590_32A100_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114650_32A1C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80114B80_32A6F0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011548C_32AFFC_ChillyWaters);

void func_801155C4_32B134_ChillyWaters(omObjData* obj) {
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 i;

    temp_s1 = (s32)HuPrcCurrentGet()->user_data;
    var_s3 = 10;

    switch (temp_s1) {
    case 0:
        func_80054904_55504(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, 0xB1, 0x2C);
        break;
    case 1:
        func_80054904_55504(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, 0x7A, 0x39);
        break;
    default:
        func_80054904_55504(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, 0xA0, 0x98);
        var_s3 = 30;
        break;
    }

    SprAttrReset(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, 0x8000U);
    for (i = 0; i < 255; i += 255 / var_s3) {
        func_80055458_56058(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, i & 0xFFFF);
        HuPrcVSleep();
    }

    func_80055458_56058(D_8011FB80_3356F0_ChillyWaters[temp_s1], 0, 0xFF);
    omDelPrcObj(0);
}

void func_80115734_32B2A4_ChillyWaters(omObjData* obj) {
    RGB2 sp18;
    RGB2 sp28;
    s32 i, j;

    for (i = 0; i <= 0; i++) {
        sp18.r = D_8011E4B8_334028_ChillyWaters[i].r;
        sp18.g = D_8011E4B8_334028_ChillyWaters[i].g;
        sp18.b = D_8011E4B8_334028_ChillyWaters[i].b;

        sp28.r = (D_8011E4B8_334028_ChillyWaters[i+1].r - sp18.r) / 30;
        sp28.g = (D_8011E4B8_334028_ChillyWaters[i+1].g - sp18.g) / 30;
        sp28.b = (D_8011E4B8_334028_ChillyWaters[i+1].b - sp18.b) / 30;

        for (j = 0; j < 30; j++) {
            func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, sp18.r, sp18.g, sp18.b);
            sp18.r += sp28.r;
            sp18.g += sp28.g;
            sp18.b += sp28.b;
            HuPrcVSleep();            
        }
        func_80055420_56020(D_8011FB8E_3356FE_ChillyWaters, 0, D_8011E4B8_334028_ChillyWaters[i+1].r, D_8011E4B8_334028_ChillyWaters[i+1].g, D_8011E4B8_334028_ChillyWaters[i+1].b);
        HuPrcSleep(0xA);        
    }

    omDelPrcObj(0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801158FC_32B46C_ChillyWaters);

//main function for using a wacky watch?
void ItemUseWackyWatch(void) {
    s32 sp18[4];
    f32 sp28[2];
    s32 sp30;
    s32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    Process* temp_v0_4;
    f32 temp_f20;
    f32 var_f20;
    s32 temp_s0_3;
    s32 temp_s4;
    s32 temp_s7;
    s32 temp_s1_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;
    s32* temp_s0;
    void* temp_v0;
    Object* temp_v0_3;
    s32 i;
    s32 j;
    GW_SYSTEM* system = &GwSystem;
    s32 temp;
    
    temp_s4 = func_8005279C_5339C(1, 0);
    temp_v0 = ReadMainFS(D_8010197C_11559C_shared_board[18]);
    temp_s7 = func_80055810_56410(temp_v0);
    HuFreeFilePerm(temp_v0);
    func_80055024_55C24(temp_s4, 0, temp_s7, 0);
    SprPriSet(temp_s4, 0, 0x4776U);
    SprAttrSet(temp_s4, 0, 0x1000U);
    for (i = 0; i < 4; i++) {
        D_8011FB80_3356F0_ChillyWaters[i] = func_8005279C_5339C(1, 0);
        temp_v0 = ReadMainFS((i + 0x1BB) | 0x130000);
        sp18[i] = func_80055810_56410(temp_v0);
        HuFreeFilePerm(temp_v0);
        func_80055024_55C24(D_8011FB80_3356F0_ChillyWaters[i], 0, sp18[i], 0);
        SprPriSet(D_8011FB80_3356F0_ChillyWaters[i], 0, 0x4780U);
        SprAttrSet(D_8011FB80_3356F0_ChillyWaters[i], 0, 0x980CU);
        func_80055458_56058(D_8011FB80_3356F0_ChillyWaters[i], 0, 0U);
        func_80055420_56020(D_8011FB80_3356F0_ChillyWaters[i], 0, 0xFF, 0xFF, 0);
    }
    temp_v0_3 = MBModelCreate(0x46, 0);
    D_8011FB90_335700_ChillyWaters = temp_v0_3;
    func_8001C258_1CE58(temp_v0_3->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(temp_v0_3->omObj1->model[0], 0x1800);
    func_8001C448_1D048(temp_v0_3->omObj1->model[0]);
    func_8001C1A0_1CDA0(temp_v0_3->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&temp_v0_3->coords, &GetPlayerStruct(CUR_PLAYER)->player_obj->coords);
    func_800D9714_ED334_shared_board(temp_v0_3);
    func_800D9B24_ED744_shared_board(temp_v0_3);
    SprAttrSet(D_8010570C_11932C_shared_board, 0, 0x8000U);
    func_800F68E0_10A500_shared_board(system->current_player_index, func_800E4A7C_F869C_shared_board(), 0);
    func_800F6E4C_10AA6C_shared_board(system->current_player_index, func_800E4A7C_F869C_shared_board(), &sp30, &sp34);
    func_80054904_55504(temp_s4, 0, sp30, sp34);
    sp28[0] = 160.0f;
    sp28[1] = 76.0f;
    HuAudFXPlay(0x145);
    func_8011548C_32AFFC_ChillyWaters(temp_s4, 0x1E, sp28);
    GwPlayer[system->current_player_index].itemNo[func_800E4A7C_F869C_shared_board()] = -1;
    FixUpPlayerItemSlots(system->current_player_index);
    func_800F6BC4_10A7E4_shared_board(CUR_PLAYER);
    func_800F66DC_10A2FC_shared_board(0);
    func_800F6ECC_10AAEC_shared_board(CUR_PLAYER);
    HuPrcSleep(0x1E);
    sp28[0] = 203.0f;
    sp28[1] = 44.0f;
    func_8011548C_32AFFC_ChillyWaters(temp_s4, 0xA, sp28);
    temp_v0_4 = omAddPrcObj(func_801155C4_32B134_ChillyWaters, 0x4002U, 0, 0);
    temp_v0_4->user_data = NULL;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[0] -= 76.0f;
    HuAudFXPlay(0x14D);
    func_8011548C_32AFFC_ChillyWaters(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    temp_v0_4 = omAddPrcObj(func_801155C4_32B134_ChillyWaters, 0x4002U, 0, 0);
    temp_v0_4->user_data = (void* )1;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
    sp28[1] += 64.0f;
    HuAudFXPlay(0x14D);
    func_8011548C_32AFFC_ChillyWaters(temp_s4, 0xA, sp28);
    HuPrcChildWait();
    HuPrcSleep(0xA);
    HuAudFXPlay(0x14E);
    func_800F6748_10A368_shared_board(temp_s4, 0, &sp38, &sp3C);
    for (var_f20 = 0.0f, var_s1 = 0; var_f20 < 90.0f; var_f20 += 3.6f) {
        func_80054904_55504(temp_s4, 0, ((HuMathCos((2.0f * var_f20) + 270.0f) * 80.0f) + sp38), (((1.0f - HuMathCos(var_f20)) * 90.0f) + sp3C));
        if (!(var_f20 > 54.0f)) {
            var_v1 = 0;
        } else {
            var_v1 = 1;
        }
        temp = var_v1 != 0;
        if (temp && var_s1 == 0) {
            var_s1 = 1;
            temp_v0_4 = omAddPrcObj(func_801155C4_32B134_ChillyWaters, 0x4002U, 0, 0);
            temp_v0_4->user_data = (void* )2;
            HuPrcChildLink(HuPrcCurrentGet(), temp_v0_4);
        }
        HuPrcVSleep();        
    }

    temp_s0_3 = (s16) (s32) ((HuMathCos(450.0f) * 80.0f) + sp38);
    func_80054904_55504(temp_s4, 0, temp_s0_3, (((1.0f - HuMathCos(90.0f)) * 90.0f) + sp3C));
    
    for (j = 255; j > 0; j -= 0x19, HuPrcVSleep()) {
        func_80055458_56058(temp_s4, 0, j);
    }

    func_800525C8_531C8(temp_s4);
    func_80055670_56270(temp_s7);
    HuPrcChildWait();
    
    for (i = 0; i < 3; i++) {
        SprAttrSet(D_8011FB80_3356F0_ChillyWaters[i], 0, 0x8000);
    }

    SprAttrReset(D_8011FB8E_3356FE_ChillyWaters, 0, 0x8000U);
    func_80055458_56058(D_8011FB8E_3356FE_ChillyWaters, 0, 0xFFU);
    func_80054904_55504(D_8011FB8E_3356FE_ChillyWaters, 0, 0xA0, 0x78);
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_80115734_32B2A4_ChillyWaters, 0x4002U, 0, 0));
    sp40 = 0;
    omAddPrcObj(func_801158FC_32B46C_ChillyWaters, 0x4002U, 0, 0)->user_data = &sp40;
    HuPrcChildWait();
    HuAudFXPlay(0x14F);
    temp_s1_2 = func_800FFA4C_11366C_shared_board(-1, 4, 5);
    
    for (i = 0; i <= 2880; i += 50) {
        temp_f20 = (HuMathSin(i) / 2.0f) + 1.0f;
        SprScale(D_8011FB8E_3356FE_ChillyWaters, 0, temp_f20, (HuMathSin(i) / 3.0f) + 1.0f);
        if (i >= (2880 / 2 + 1)) {
            sp40 = 1;
        }
        HuPrcVSleep();        
    }
    
    HuAudFXPlay(0x129);
    WipeColorSet(0xFF, 0xFF, 0xFF);
    WipeCreateOut(0xB, 0x32);
    func_800FFAEC_11370C_shared_board(temp_s1_2);
    
    for (var_f20 = 0.0f; WipeStatGet() != 0; var_f20 += 0.1f) {
        SprScale(D_8011FB8E_3356FE_ChillyWaters, 0, var_f20, var_f20);
        HuPrcVSleep();
    }
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    sp40 = 2;
    for (i = 0; i < 4; i++) {
        func_800525C8_531C8(D_8011FB80_3356F0_ChillyWaters[i]);
        func_80055670_56270(sp18[i]);
    }
    
    WipeCreateIn(0xB, 0x5A);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    func_800EC414_100034_shared_board(0x3A23);
    GwSystem.unk_52 = 2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116484_32BFF4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011667C_32C1EC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801166F4_32C264_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116758_32C2C8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116904_32C474_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116A04_32C574_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116AA0_32C610_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116BA0_32C710_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116DAC_32C91C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116F0C_32CA7C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80116F5C_32CACC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801174D4_32D044_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801176A4_32D214_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_801177DC_32D34C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80117C60_32D7D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118308_32DE78_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118A98_32E608_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118AE8_32E658_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118B7C_32E6EC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118D6C_32E8DC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118E2C_32E99C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80118EEC_32EA5C_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119924_32F494_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119A20_32F590_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119A60_32F5D0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119B3C_32F6AC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119C54_32F7C4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_80119D08_32F878_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A764_3302D4_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A794_330304_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A838_3303A8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A8B8_330428_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011A8D8_330448_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011B9A0_331510_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BBA4_331714_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD48_3318B8_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BD8C_3318FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011BF3C_331AAC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C470_331FE0_ChillyWaters);

//entrypoint 4
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C58C_3320FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C5E0_332150_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C68C_3321FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C750_3322C0_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C7A4_332314_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011C88C_3323FC_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011CE94_332A04_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B9F0", func_8011D1F8_332D68_ChillyWaters);
