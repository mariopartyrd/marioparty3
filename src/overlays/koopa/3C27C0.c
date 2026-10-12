#include "common.h"
#include "../ovl_80_shared_board/ECA50.h"
#include "../ovl_80_shared_board/106A50.h"
#include "../ovl_80_shared_board/FA250.h"
#include "../ovl_80_shared_board/F5B90.h"
#include "../ovl_80_shared_board/101840.h"
#include "../ovl_80_shared_board/105D50.h"
#include "../ovl_80_shared_board/10C230.h"
#include "../ovl_80_shared_board/FFB10.h"
#include "../ovl_80_shared_board/113520.h"

typedef struct UnkBowser {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} UnkBowser; // sizeof 0x8

typedef struct UnkBowser2 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
} UnkBowser2; // sizeof 0x24

void func_8005A6B0_main(void);
void func_80108D2C_koopa(void);
void func_80109220_koopa(omObjData *);
s32 func_8010926C_koopa(void);
void func_801092D4_koopa(void);
void func_80107724_koopa(void);
s32 func_80107A9C_koopa(void);
s32 func_80107DDC_koopa(void);
s32 func_801085E4_koopa(void);
s32 func_80108664_koopa(void);
s32 func_801086E4_koopa(void);
s32 func_80108A2C_koopa(void);
s32 func_80108BB0_koopa(void);
s32 func_8010778C_koopa(void);
s32 func_801078CC_koopa(void);

extern s16 D_801094F6_koopa;
extern Object *D_801094F8_koopa;
extern char D_80109508_koopa[];

extern u8 D_801094F0_koopa;
extern s32 D_801094F4_koopa;
extern u32 D_800D2094_main;
extern s32 D_8010956C_koopa;
extern omObjData *D_80109550_koopa;
extern s16 D_80109518_koopa[5][5];
extern s16 D_80109554_koopa[2];
extern s16 D_80109558_koopa;
extern s16 D_8010955A_koopa;
extern s16 D_8010955C_koopa;
extern s16 D_8010955E_koopa;
extern s16 D_80109560_koopa;
extern s16 D_80109562_koopa;
extern s16 D_80109564_koopa;
extern s32 D_80109568_koopa;
extern s32 D_80109500_koopa;
extern s32 D_80109504_koopa;
extern s16 D_8010951A_koopa[];

//.data
void *D_80109350_koopa = 0;

s32 D_80109354_koopa[] = {
    0x00004200,
    0x00004201,
    0x00004202,
    0x00004203,
    0x00004204,
    0x00004205,
    0x00004206,
    0x00004207,
    0x00004208,
    0x00004209,
};

UnkBowser D_8010937C_koopa[] = {
    { 64, -206, 200, 20 },
    { 64, -186, 200, 20 },
    { 64, -166, 200, 20 },
    { 64, -146, 200, 20 },
    { 64, -126, 200, 20 }
};

u8 D_801093A4_koopa = 94;
u8 D_801093A8_koopa[][2] = {
    { 1, 0 },
    { 9, 15 },
    { 11, 8 },
    { 13, 0 }
};
Vec D_801093B0_koopa = { 0.0f, 0.0f, 2250.0f };
Vec D_801093BC_koopa = { 0.0f, 0.0f, -1000.0f };

UnkBowser2 D_801093C8_koopa = {
    0x00000008, 0x000A0035, 0x000A0032, 0x000A0038,
    0x000A0040, 0x000A0043, 0x000A0041, 0x000A0042, 0x000A0044
};

void *D_801093EC_koopa[] = {
    func_8010778C_koopa,
    func_801078CC_koopa,
    func_80107A9C_koopa,
    func_80107DDC_koopa,
    func_801085E4_koopa,
    func_80108664_koopa,
    func_801086E4_koopa,
    func_80108A2C_koopa,
    func_80108BB0_koopa,
    func_80108BB0_koopa
};

u32 D_80109414_koopa = 0;
s16 D_80109418_koopa[] = { 90, 89, 87, 71, 70, 84, 85, 86, 62, 61, 58, 59, 60, -1 };
u16 D_80109434_koopa[2][3][4] = {
    { { 20, 20, 10, 10 },
      { 20, 20, 15, 15 },
      { 30, 30, 20, 20 } },
    { { 10, 10, 10, 10 },
      { 20, 20, 20, 20 },
      { 30, 30, 30, 30 } }
};

// unused
s16 D_80109464_koopa[][2] = {
    { 20, 20 },
    { 30, 30 },
    { 30, 30 },
    { 40, 40 },
    { 30, 40 },
    { 50, 50 },
    { 0, 0 }
};

//.text
void func_801059A0_koopa(void) {
    s32 i;

    D_801094F0_koopa = GwSystem.current_board_index;
    D_801094F4_koopa = GwSystem.playerIndexVisitingBowser;
    omInitObjMan(0x32, 0x32);
    func_801092D4_koopa();
    func_8010926C_koopa();
    func_800D95C4_shared_board(1000.0f);
    func_8005A6B0_main();
    func_800F453C_shared_board();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        MBStatusPosSet(i, 0x1E, -0x32);
    }
    omAddPrcObj(func_80108D2C_koopa, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_80109220_koopa);
    func_800EA60C_shared_board();
    MBMasuCreate(0x13, 0x23A);
    func_8004A208_main();
}

void func_80105A8C_koopa(void) {
    if (D_800D2094_main >= (D_80109414_koopa + 4)) {
        HuAudFXPlay(0x104);
        D_80109414_koopa = D_800D2094_main;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80105AD8_koopa);

s32 func_80106968_koopa(void) {
    return D_80109568_koopa;
}

s32 func_80106974_koopa(void) {
    return D_8010956C_koopa;
}

s32 func_80106980_koopa(void) {
    if (D_80109550_koopa == NULL) {
        return -1;
    }
    return D_80109550_koopa->work[0];
}

void func_8010699C_koopa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80109518_koopa); i++) {
        D_80109518_koopa[i][0] = -1;
    }

    D_80109550_koopa = NULL;

    for (i = 0; i < ARRAY_COUNT(D_80109554_koopa); i++) {
        D_80109554_koopa[i] = -1;
    }

    D_80109558_koopa = -1;
    D_8010955C_koopa = -1;
    D_8010955A_koopa = -1;
    D_80109560_koopa = -1;
    D_8010955E_koopa = -1;
    D_80109564_koopa = -1;
    D_80109562_koopa = -1;
    D_80109568_koopa = -1;
    D_80109350_koopa = 0;
}

void func_80106A54_koopa(void) {
    if (D_80109562_koopa != -1) {
        HuSprGrpKill(D_80109562_koopa);
        D_80109562_koopa = -1;
    }
    if (D_80109564_koopa != -1) {
        HuSprKill(D_80109564_koopa);
        D_80109564_koopa = -1;
    }
}

void func_80106AB8_koopa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80109518_koopa); i++) {
        s16 *temp = D_80109518_koopa[i];
        if (temp[0] != -1) {
            func_8005F364_main(temp[0]);
            temp[0] = -1;
        }
    }

    if (D_80109350_koopa != 0) {
        MBHelpWinKill(D_80109350_koopa);
        D_80109350_koopa = 0;
    }

    if (D_80109550_koopa != NULL) {
        omDelObj(D_80109550_koopa);
        D_80109550_koopa = NULL;
    }

    if (D_8010955E_koopa != -1) {
        HuSprGrpKill(D_8010955E_koopa);
        D_8010955E_koopa = -1;
    }

    if (D_80109560_koopa != -1) {
        HuSprKill(D_80109560_koopa);
        D_80109560_koopa = -1;
    }

    if (D_8010955A_koopa != -1) {
        HuSprGrpKill(D_8010955A_koopa);
        D_8010955A_koopa = -1;
    }

    if (D_8010955C_koopa != -1) {
        HuSprKill(D_8010955C_koopa);
        D_8010955C_koopa = -1;
    }

    for (i = 0; i < ARRAY_COUNT(D_80109554_koopa); i++) {
        if (D_80109554_koopa[i] != -1) {
            HuSprGrpKill(D_80109554_koopa[i]);
            D_80109554_koopa[i] = -1;
        }
    }

    if (D_80109558_koopa != -1) {
        HuSprKill(D_80109558_koopa);
        D_80109558_koopa = -1;
    }

    func_80106A54_koopa();
}

void func_80106C78_koopa(void) {
    s32 randVal;
    s32 var_v0_2;
    void *temp_v0;
    s32 i;

    if (D_8010955E_koopa == -1) {
        D_8010955E_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301EB);
        D_80109560_koopa = func_80055810_main(temp_v0);
        DataClose(temp_v0);
        func_80055024_main(D_8010955E_koopa, 0, D_80109560_koopa, 0);
        HuSprPriSet(D_8010955E_koopa, 0, 0x4770);
        HuSprAttrSet(D_8010955E_koopa, 0, 0x1000);
        func_80054904_main(D_8010955E_koopa, 0, D_8010951A_koopa[0] + 0x64, D_8010951A_koopa[1] + 0x32);
        func_80055420_main(D_8010955E_koopa, 0, 0, 0, 0);
        D_8010955A_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301E9);
        D_8010955C_koopa = func_80055810_main(temp_v0);
        DataClose(temp_v0);
        func_80055024_main(D_8010955A_koopa, 0, D_8010955C_koopa, 0);
        HuSprPriSet(D_8010955A_koopa, 0, 0x4770);
        HuSprAttrSet(D_8010955A_koopa, 0, 0x1000);
        func_80054904_main(D_8010955A_koopa, 0, D_8010951A_koopa[0] + 0x64, D_8010951A_koopa[1] - 0x1E);
        temp_v0 = DataRead(0x130260);
        D_80109558_koopa = func_80055810_main(temp_v0);
        DataClose(temp_v0);
        randVal = MBRand(5.0f);
        for (i = 0; i < ARRAY_COUNT(D_80109554_koopa); i++) {
            D_80109554_koopa[i] = HuSprGrpCreate(1, 5);
            func_80055024_main(D_80109554_koopa[i], 0, D_80109558_koopa, 1);
            HuSprPriSet(D_80109554_koopa[i], 0, 0x4770);
            HuSprAttrSet(D_80109554_koopa[i], 0, 0x1000);
            func_80054904_main(D_80109554_koopa[i], 0, D_8010951A_koopa[0] + (i * 0xC8), (D_8010951A_koopa[1] - 0x28));
            if ((randVal == 0) && (D_80109504_koopa == 0)) {
                var_v0_2 = D_80109500_koopa;
                if (var_v0_2 == 0) {
                    func_80055420_main(D_80109554_koopa[i], 0, 0, 0, 0xFF);
                } else {
                    if (var_v0_2 < 0) {
                        var_v0_2 = -var_v0_2;
                    }
                    if (var_v0_2 < 2) {
                        func_80055420_main(D_80109554_koopa[i], 0, 0xFF, 0xFF, 0);
                    } else {
                        func_80055420_main(D_80109554_koopa[i], 0, 0xFF, 0, 0);
                    }
                }
            } else {
                func_80055420_main(D_80109554_koopa[i], 0, 0xFF, 0, 0);
            }
        }
    }
}

void func_80106FC8_koopa(void) {
    void *temp_v0;

    if (D_80109562_koopa == -1) {
        D_80109562_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301EA);
        D_80109564_koopa = func_80055810_main(temp_v0);
        DataClose(temp_v0);
        func_80055024_main(D_80109562_koopa, 0, D_80109564_koopa, 0);
        HuSprPriSet(D_80109562_koopa, 0, 0x100);
        HuSprAttrSet(D_80109562_koopa, 0, 0x1000);
        func_80054904_main(D_80109562_koopa, 0, 0x32, D_801093A4_koopa);
    }
}

s32 func_80107090_koopa(void) {
    s32 var_s3;
    GW_PLAYER *temp_s1;
    s32 i, j;

    if (GwSystem.current_board_index == CHILLY_WATERS) {
        for (var_s3 = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_s1 = MBPlayerGet(i);
            for (j = 0; D_80109418_koopa[j] != -1; j++) {
                if (MBMasuLinkMasuIdGet(temp_s1->clink, temp_s1->cidx) == D_80109418_koopa[j]) {
                    var_s3++;
                    break;
                }
            }
        }
        if (var_s3 < 2) {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

const char D_801094C0_koopa[] = "%d";
const char D_801094C4_koopa[] = "";

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107190_koopa);

void func_80107648_koopa(void) {
    D_80109550_koopa->work[0] = 0;
}

s32 func_80107658_koopa(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 playerRank;

    temp_s0 = BoardGetTurnTier(CUR_TURN);
    playerRank = BoardPlayerRankCalc(arg1);
    return D_80109434_koopa[arg0][temp_s0][playerRank];
}

u16 func_801076CC_koopa(s32 playerIndex, s32 arg1) {
    s32 temp_s0;
    s32 playerRank;

    temp_s0 = BoardGetTurnTier(CUR_TURN);
    playerRank = BoardPlayerRankCalc(playerIndex);
    return D_80109434_koopa[2][temp_s0][playerRank];
}

void func_80107724_koopa(void) {
    func_800F5E24_shared_board(D_801094F4_koopa);
    MBStatusDispMoveSet(0x18);
    func_800F5E24_shared_board(-1);
    HuPrcSleep(20);
}

void func_8010775C_koopa(void) {
    func_800F5E24_shared_board(D_801094F4_koopa);
    MBStatusDispMoveSet(0x18);
    func_800F5E24_shared_board(-1);
}

s32 func_8010778C_koopa(void) {
    s32 temp_v0;

    temp_v0 = func_80107658_koopa(0, D_801094F4_koopa);
    sprintf(D_80109508_koopa, D_801094C0_koopa, temp_v0);
    if (GwPlayer[D_801094F4_koopa].coin >= temp_v0) {
        MBWinInsertOpen(0x420D, D_80109508_koopa, 0, 0, 0, 0);
    } else {
        MBWinInsertOpen(0x420E, D_80109508_koopa, 0, 0, 0, 0);
    }

    func_800EC3C0_shared_board(D_801094F4_koopa);
    func_800EC3E4_shared_board();
    func_80107724_koopa();
    MBMotionShiftSet(D_801094F8_koopa, 2, 0, 5, 0);
    func_800EE884_shared_board(D_801094F8_koopa, -1, 2);
    HuPrcSleep(14);
    HuAudFXPlay(0x29F);
    MBCoinTakeCreate(D_801094F4_koopa, -temp_v0);
    MBPlayerVibrate(D_801094F6_koopa, 3);
    HuPrcSleep(30);
    MBWinOpen(0x420F);
    func_800EC3C0_shared_board(D_801094F4_koopa);
    func_800EC3E4_shared_board();
    return 0;
}

s32 func_801078CC_koopa(void) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a0_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 i;

    temp_v0 = func_80107658_koopa(1, D_801094F4_koopa);
    sprintf(D_80109508_koopa, D_801094C0_koopa, temp_v0);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].coin < temp_v0) {
            break;
        }
    }

    if (i == 4) {
        MBWinInsertOpen(0x4210, D_80109508_koopa, 0, 0, 0, 0);
    } else {
        MBWinInsertOpen(0x4211, D_80109508_koopa, 0, 0, 0, 0);
    }

    func_800EC3C0_shared_board(D_801094F4_koopa);
    func_800EC3E4_shared_board();
    MBStatusDispMoveSet(0);
    HuPrcSleep(20);
    MBMotionShiftSet(D_801094F8_koopa, 2, 0, 5, 0);
    func_800EE884_shared_board(D_801094F8_koopa, -1, 2);
    HuPrcSleep(14);
    HuAudFXPlay(0x29F);
    var_a0_2 = -10000;
    var_s1 = 0;
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v1 = GwPlayer[i].coin - temp_v0;
        if (var_a0_2 < temp_v1) {
            var_a0_2 = temp_v1;
            var_s1 = i;
        }
    }
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        MBCoinTakeCreateSound(i, -temp_v0, i == var_s1);
        MBPlayerVibrate(i, 3);
    }

    HuPrcSleep(30);
    MBWinOpen(0x420F);
    func_800EC3C0_shared_board(D_801094F4_koopa);
    func_800EC3E4_shared_board();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107A9C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107DDC_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108360_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801085E4_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108664_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801086E4_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801087F0_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108A2C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108BB0_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108D2C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801091C4_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80109220_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_8010926C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801092A0_koopa);

void func_801092D4_koopa(void) {
    Hu3DCamInit(1);
    func_800E6630_shared_board((u32)hvq_data_ROM_START);
    MBBackLoad(2);
    func_800E9344_shared_board(100.0f, 10000.0f);
}

void func_80109320_koopa(void) {
    MBBackKill();
    MBBackClose();
}
