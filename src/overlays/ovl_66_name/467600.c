#include "common.h"

#define DEFAULT_X_POS 24
#define DEFAULT_Y_POS 16

#define GET_TEXT_X_POSITION(j) ((j) * 20 + 48)
#define INCREMENT_TEXT_Y_POSITION() (TextYPos += 8)

//.data
//screen scissor dimensions
RectF ScissorDimensions = {0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT};
s16 StringBufferIndex = 0; //only used once and never written to?
u16 TextYPos = DEFAULT_Y_POS;

extern s32 fontcolor;
extern u8 D_801068C0_4684F0_name_66[512];

void func_80106108_467D38_name_66(omObjData*);
void func_80106134_467D64_name_66(void);
void func_80105C6C_46789C_name_66(s16 arg0);
void func_801062A0_467ED0_name_66(void);

void func_801059D0_467600_name_66(void) {
    omInitObjMan(10, 10);
    func_8004A208_4AE08();
    Hu3DCamInit(1);
    CameraScissorSet(0, &ScissorDimensions);
    HmfLightMaxSet(1);
    HmfLightColorSet(0, 120, 120, 120);
    HmfLightColorSet(1, 64, 64, 96);
    HmfLightDirSet(1, -100.0f, 100.0f, 100.0f);
    omAddPrcObj(func_80106134_467D64_name_66, 0xE000, 0, 0);
    omAddObj(0x500, 0, 0, -1, func_80106108_467D38_name_66);
    WipeCreateIn(0, 0);
}

void func_80105A98_4676C8_name_66(void) {
    s32 var_s2;
    s32 i, j;

    var_s2 = StringBufferIndex;
    fontcolor = 15;
    
    for (i = 0; i < 16 && (i * 8) < ARRAY_COUNT(D_801068C0_4684F0_name_66); i++) {
        sprintf(D_800D5218_D5E18, "%3X:", var_s2);
        print8(40, (i * 10 + 48), D_800D5218_D5E18);
        for (j = 0; j < 8; j++) {
            sprintf(D_800D5218_D5E18, "%02X", D_801068C0_4684F0_name_66[var_s2 + j]);
            print8((j * 24 + 80), (i * 10 + 48), D_800D5218_D5E18);
        }
        var_s2 += 8;
    }
}

void func_80105BB4_4677E4_name_66(void) {
    s16 var_s1;
    s16 i;

    var_s1 = 0;
    SLCurBoxNoSet(0);
    func_80050974_51574();
    while (1) {
        HuPrcVSleep();
        if (D_800D5558_D6158[0] & 0x8000) {
            var_s1 = (var_s1 == 0) ? 2 : 0;
        }

        TextYPos = DEFAULT_Y_POS;

        for (i = var_s1; i < var_s1 + 2; i++) {
            func_80105C6C_46789C_name_66(i);
        }        
    }
}

void func_80105C6C_46789C_name_66(s16 playerIndex) {
    char buffer[256];

    fontcolor = 10;
    sprintf(buffer, "PLAYER%d", playerIndex);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    fontcolor = 15;

    sprintf(buffer, "PAD:%2X,CHR:%2X,STAT:%2x,GCOIN:%4X", GwPlayer[playerIndex].pad, GwPlayer[playerIndex].chr, GwPlayer[playerIndex].stat, GwPlayer[playerIndex].gameCoin);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "BCOIN:%4X,COIN:%4X,CCOIN:%4x", GwPlayer[playerIndex].bonusCoin, GwPlayer[playerIndex].coin, GwPlayer[playerIndex].checkCoin);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "STAR:%2X,CLINK:%2X,CIDX:%2x,NLINK:%2X", GwPlayer[playerIndex].star, GwPlayer[playerIndex].clink, GwPlayer[playerIndex].cidx, GwPlayer[playerIndex].nlink);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "NIDX:%2X,NNLINK:%2X,NNIDX:%2X,BLINK:%2X", GwPlayer[playerIndex].nidx, GwPlayer[playerIndex].nnlink, GwPlayer[playerIndex].nnidx, GwPlayer[playerIndex].blink);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "BIDX:%2X,REV:%2X,ITEM0#%2d,ITEM1#%2d", GwPlayer[playerIndex].bidx, GwPlayer[playerIndex].rev, GwPlayer[playerIndex].itemNo[0], GwPlayer[playerIndex].itemNo[1]);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "ITEM2#%2d,ITURN:%2X,COL:%2X,TURN:%2X", GwPlayer[playerIndex].itemNo[2], GwPlayer[playerIndex].itemTurn, GwPlayer[playerIndex].color, GwPlayer[playerIndex].turn);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "GPRZ:%4X,CPRZ:%4X,HPRZ:%4X", GwPlayer[playerIndex].gamePrize, GwPlayer[playerIndex].coinPrize, GwPlayer[playerIndex].stats.prize.hatenaPrize);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "RPRZ:%2X,BPRZ:%2X,EPRZ:%2X,KPRZ:%2X", GwPlayer[playerIndex].stats.prize.redPrize, GwPlayer[playerIndex].stats.prize.bluePrize, GwPlayer[playerIndex].stats.prize.eventPrize, GwPlayer[playerIndex].stats.prize.kupaPrize);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "BTLPRZ:%2X,IPRZ:%2X,BNKPRZ:%2X", GwPlayer[playerIndex].stats.prize.battlePrize, GwPlayer[playerIndex].stats.prize.itemPrize, GwPlayer[playerIndex].stats.prize.bankPrize);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

    sprintf(buffer, "GBPRZ#%2d,DUEL#%2d", GwPlayer[playerIndex].stats.prize.gamblePrize, GwPlayer[playerIndex].stats.prize.duelNo);
    print8(DEFAULT_X_POS, TextYPos, buffer);
    INCREMENT_TEXT_Y_POSITION();

}

void func_80106108_467D38_name_66(omObjData* arg0) {
    if (D_800D530C_D5F0C != 0) {
        omOvlReturnEx(1);
    }
}

void func_80106134_467D64_name_66(void) {
    s16 i, j;

    SLCurBoxNoSet(0);
    func_80050ABC_516BC();
    while (1) {
        HuPrcVSleep();
        func_801062A0_467ED0_name_66();
        if (D_800D5558_D6158[0] & 0x8000) {
            for (j = 0; j < ARRAY_COUNT(GwStory.unk3); j++) {
                GwStory.unk3[j] = 0;
            }
            for (i = 0; i < ARRAY_COUNT_2D_ROWS(GwStory.unk10); i++) {
                for (j = 0; j < ARRAY_COUNT_2D_COLS(GwStory.unk10); j++) {
                    GwStory.unk10[i][j] = 0;
                }
            }
            for (j = 0; j < ARRAY_COUNT(GwStory.unk58); j++) {
                GwStory.unk58[j] = 0;
            }
            for (j = 0; j < ARRAY_COUNT(GwStory.unk5E); j++) {
                GwStory.unk5E[j] = 0;
            }
            func_8005035C_50F5C(1);
        }
        TextYPos = DEFAULT_Y_POS;
    }
}

void func_801062A0_467ED0_name_66(void) {
    char sp18[0x120];
    s16 i, j;
    
    fontcolor = 15;
    sprintf(sp18, "INDEX:%2X,CHR:%2X,DIF:%2X,LAST:%2X", GwStory.unk0, GwStory.unk1, GwStory.unk2, GwStory.unkF);
    print8(DEFAULT_X_POS, TextYPos, sp18);
    INCREMENT_TEXT_Y_POSITION();

    print8(DEFAULT_X_POS, TextYPos, "SC:");
    //iterate over first half of the array
    for (j = 0; j < ARRAY_COUNT(GwStory.unk3) / 2; j++) {
        sprintf(sp18, "%2X", GwStory.unk3[j]);
        print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);
    }

    INCREMENT_TEXT_Y_POSITION();

    //iterate over last half of the array
    for (j = 0; j < ARRAY_COUNT(GwStory.unk3) / 2; j++) {
        sprintf(sp18, "%2X", GwStory.unk3[j + 6]);
        print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);
    }

    INCREMENT_TEXT_Y_POSITION();

    print8(DEFAULT_X_POS, TextYPos, "HS:");
    
    for (i = 0; i < ARRAY_COUNT_2D_ROWS(GwStory.unk10); i++) {
        //iterate over first half of array
        for (j = 0; j < ARRAY_COUNT_2D_COLS(GwStory.unk10) / 2; j++) {
            sprintf(sp18, "%2X", GwStory.unk10[i][j]);
            print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);
        }

        INCREMENT_TEXT_Y_POSITION();

        //iterate over last half of array
        for (j = 0; j < ARRAY_COUNT_2D_COLS(GwStory.unk10) / 2; j++) {
            sprintf(sp18, "%2X", GwStory.unk10[i][j + 6]);
            print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);       
        }

        INCREMENT_TEXT_Y_POSITION();
    }

    print8(DEFAULT_X_POS, TextYPos, "HL:");

    for (j = 0; j < ARRAY_COUNT(GwStory.unk58); j++) {
        sprintf(sp18, "%2X", GwStory.unk58[j]);
        print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);        
    }

    INCREMENT_TEXT_Y_POSITION();

    print8(DEFAULT_X_POS, TextYPos, "HD:");

    for (j = 0; j < ARRAY_COUNT(GwStory.unk5E); j++) {
        sprintf(sp18, "%2X", GwStory.unk5E[j]);
        print8(GET_TEXT_X_POSITION(j), TextYPos, sp18);        
    }

    INCREMENT_TEXT_Y_POSITION();
}
