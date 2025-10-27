#include "common.h"
#include "../ovl_80_shared_board/ovl_80.h"

typedef struct UnkBowser {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} UnkBowser; //sizeof 0x8

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
} UnkBowser2; //sizeof 0x24

void func_8005A6B0_5B2B0(void);
void func_80108D2C_3C5B4C_koopa(void);
void func_80109220_3C6040_koopa(omObjData*);
s32 func_8010926C_3C608C_koopa(void);
s32 func_801092D4_3C60F4_koopa(void);
void func_80107724_3C4544_koopa(void);
s32 func_80107A9C_3C48BC_koopa(void);
s32 func_80107DDC_3C4BFC_koopa(void);
s32 func_801085E4_3C5404_koopa(void);
s32 func_80108664_3C5484_koopa(void);
s32 func_801086E4_3C5504_koopa(void);
s32 func_80108A2C_3C584C_koopa(void);
s32 func_80108BB0_3C59D0_koopa(void);
s32 func_8010778C_3C45AC_koopa(void);
s32 func_801078CC_3C46EC_koopa(void);

extern s16 D_801094F6_3C6316_koopa;
extern Object* D_801094F8_3C6318_koopa;
extern char D_80109508_3C6328_koopa[];

extern u8 D_801094F0_3C6310_koopa;
extern s32 D_801094F4_3C6314_koopa;
extern u32 D_800D2094_D2C94;
extern s32 D_8010956C_3C638C_koopa;
extern omObjData* D_80109550_3C6370_koopa;
extern s16 D_80109518_3C6338_koopa[5][5];
extern s16 D_80109554_3C6374_koopa[2];
extern s16 D_80109558_3C6378_koopa;
extern s16 D_8010955A_3C637A_koopa;
extern s16 D_8010955C_3C637C_koopa;
extern s16 D_8010955E_3C637E_koopa;
extern s16 D_80109560_3C6380_koopa;
extern s16 D_80109562_3C6382_koopa;
extern s16 D_80109564_3C6384_koopa;
extern s32 D_80109568_3C6388_koopa;
extern s32 D_80109500_3C6320_koopa;
extern s32 D_80109504_3C6324_koopa;
extern s16 D_8010951A_3C633A_koopa[];

//.data
void* D_80109350_3C6170_koopa = 0;

s32 D_80109354_3C6174_koopa[] = {
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

UnkBowser D_8010937C_3C619C_koopa[] = {
    {64, -206, 200, 20},
    {64, -186, 200, 20},
    {64, -166, 200, 20},
    {64, -146, 200, 20},
    {64, -126, 200, 20}
};

u8 D_801093A4_3C61C4_koopa = 94;
u8 D_801093A8_3C61C8_koopa[][2] = {
    {1, 0},
    {9, 15},
    {11, 8},
    {13, 0}
};
Vec D_801093B0_3C61D0_koopa = {0.0f, 0.0f, 2250.0f};
Vec D_801093BC_3C61DC_koopa = {0.0f, 0.0f, -1000.0f};

UnkBowser2 D_801093C8_3C61E8_koopa = {
    0x00000008, 0x000A0035, 0x000A0032, 0x000A0038,
    0x000A0040, 0x000A0043, 0x000A0041, 0x000A0042, 0x000A0044
};

void* D_801093EC_3C620C_koopa[] = {
    func_8010778C_3C45AC_koopa,
    func_801078CC_3C46EC_koopa,
    func_80107A9C_3C48BC_koopa,
    func_80107DDC_3C4BFC_koopa,
    func_801085E4_3C5404_koopa,
    func_80108664_3C5484_koopa,
    func_801086E4_3C5504_koopa,
    func_80108A2C_3C584C_koopa,
    func_80108BB0_3C59D0_koopa,
    func_80108BB0_3C59D0_koopa
};

u32 D_80109414_3C6234_koopa = 0;
s16 D_80109418_3C6238_koopa[] = {90, 89, 87, 71, 70, 84, 85, 86, 62, 61, 58, 59, 60, -1};
u16 D_80109434_3C6254_koopa[2][3][4] = {
    {
        {20, 20, 10, 10},
        {20, 20, 15, 15},
        {30, 30, 20, 20}
    },
    {
        {10, 10, 10, 10},
        {20, 20, 20, 20},
        {30, 30, 30, 30}
    }
};

//unused
s16 D_80109464_3C6284_koopa[][2] = {
    {20, 20},
    {30, 30},
    {30, 30},
    {40, 40},
    {30, 40},
    {50, 50},
    {0, 0}
};

//.text
void func_801059A0_3C27C0_koopa(void) {
    s32 i;
    
    D_801094F0_3C6310_koopa = GwSystem.current_board_index;
    D_801094F4_3C6314_koopa = GwSystem.playerIndexVisitingBowser;
    omInitObjMan(0x32, 0x32);
    func_801092D4_3C60F4_koopa();
    func_8010926C_3C608C_koopa();
    func_800D95C4_ED1E4_shared_board(1000.0f);
    func_8005A6B0_5B2B0();
    func_800F453C_10815C_shared_board();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_800F4874_108494_shared_board(i, 0x1E, -0x32);
    }
    omAddPrcObj(func_80108D2C_3C5B4C_koopa, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_80109220_3C6040_koopa);
    func_800EA60C_FE22C_shared_board();
    MBMasuCreate(0x13, 0x23A);
    func_8004A208_4AE08();
}

void func_80105A8C_3C28AC_koopa(void) {
    if (D_800D2094_D2C94 >= (D_80109414_3C6234_koopa + 4)) {
        HuAudFXPlay(0x104);
        D_80109414_3C6234_koopa = D_800D2094_D2C94;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80105AD8_3C28F8_koopa);

s32 func_80106968_3C3788_koopa(void) {
    return D_80109568_3C6388_koopa;
}

s32 func_80106974_3C3794_koopa(void) {
    return D_8010956C_3C638C_koopa;
}

s32 func_80106980_3C37A0_koopa(void) {
    if (D_80109550_3C6370_koopa == NULL) {
        return -1;
    }
    return D_80109550_3C6370_koopa->work[0];
}

void func_8010699C_3C37BC_koopa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80109518_3C6338_koopa); i++) {
        D_80109518_3C6338_koopa[i][0] = -1;
    }

    D_80109550_3C6370_koopa = NULL;

    for (i = 0; i < ARRAY_COUNT(D_80109554_3C6374_koopa); i++) {
        D_80109554_3C6374_koopa[i] = -1;
    }

    D_80109558_3C6378_koopa = -1;
    D_8010955C_3C637C_koopa = -1;
    D_8010955A_3C637A_koopa = -1;
    D_80109560_3C6380_koopa = -1;
    D_8010955E_3C637E_koopa = -1;
    D_80109564_3C6384_koopa = -1;
    D_80109562_3C6382_koopa = -1;
    D_80109568_3C6388_koopa = -1;
    D_80109350_3C6170_koopa = 0;
}

void func_80106A54_3C3874_koopa(void) {
    if (D_80109562_3C6382_koopa != -1) {
        HuSprGrpKill(D_80109562_3C6382_koopa);
        D_80109562_3C6382_koopa = -1;
    }
    if (D_80109564_3C6384_koopa != -1) {
        HuSprKill(D_80109564_3C6384_koopa);
        D_80109564_3C6384_koopa = -1;
    }
}

void func_80106AB8_3C38D8_koopa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80109518_3C6338_koopa); i++) {
        s16* temp = D_80109518_3C6338_koopa[i];
        if (temp[0] != -1) {
            func_8005F364_5FF64(temp[0]);
            temp[0] = -1;
        }
    }
    
    if (D_80109350_3C6170_koopa != 0) {
        MBHelpWinKill(D_80109350_3C6170_koopa);
        D_80109350_3C6170_koopa = 0;
    }
    
    if (D_80109550_3C6370_koopa != NULL) {
        omDelObj(D_80109550_3C6370_koopa);
        D_80109550_3C6370_koopa = NULL;
    }
    
    if (D_8010955E_3C637E_koopa != -1) {
        HuSprGrpKill(D_8010955E_3C637E_koopa);
        D_8010955E_3C637E_koopa = -1;
    }
    
    if (D_80109560_3C6380_koopa != -1) {
        HuSprKill(D_80109560_3C6380_koopa);
        D_80109560_3C6380_koopa = -1;
    }
    
    if (D_8010955A_3C637A_koopa != -1) {
        HuSprGrpKill(D_8010955A_3C637A_koopa);
        D_8010955A_3C637A_koopa = -1;
    }
    
    if (D_8010955C_3C637C_koopa != -1) {
        HuSprKill(D_8010955C_3C637C_koopa);
        D_8010955C_3C637C_koopa = -1;
    }
    
    for (i = 0; i < ARRAY_COUNT(D_80109554_3C6374_koopa); i++) {
        if (D_80109554_3C6374_koopa[i] != -1) {
            HuSprGrpKill(D_80109554_3C6374_koopa[i]);
            D_80109554_3C6374_koopa[i] = -1;
        }
    }

    if (D_80109558_3C6378_koopa != -1) {
        HuSprKill(D_80109558_3C6378_koopa);
        D_80109558_3C6378_koopa = -1;
    }
    
    func_80106A54_3C3874_koopa();
}

void func_80106C78_3C3A98_koopa(void) {
    s32 randVal;
    s32 var_v0_2;
    void* temp_v0;
    s32 i;

    if (D_8010955E_3C637E_koopa == -1) {
        D_8010955E_3C637E_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301EB);
        D_80109560_3C6380_koopa = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        func_80055024_55C24(D_8010955E_3C637E_koopa, 0, D_80109560_3C6380_koopa, 0);
        HuSprPriSet(D_8010955E_3C637E_koopa, 0, 0x4770);
        HuSprAttrSet(D_8010955E_3C637E_koopa, 0, 0x1000);
        func_80054904_55504(D_8010955E_3C637E_koopa, 0, D_8010951A_3C633A_koopa[0] + 0x64, D_8010951A_3C633A_koopa[1] + 0x32);
        func_80055420_56020(D_8010955E_3C637E_koopa, 0, 0, 0, 0);
        D_8010955A_3C637A_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301E9);
        D_8010955C_3C637C_koopa = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        func_80055024_55C24(D_8010955A_3C637A_koopa, 0, D_8010955C_3C637C_koopa, 0);
        HuSprPriSet(D_8010955A_3C637A_koopa, 0, 0x4770);
        HuSprAttrSet(D_8010955A_3C637A_koopa, 0, 0x1000);
        func_80054904_55504(D_8010955A_3C637A_koopa, 0, D_8010951A_3C633A_koopa[0] + 0x64, D_8010951A_3C633A_koopa[1] - 0x1E);
        temp_v0 = DataRead(0x130260);
        D_80109558_3C6378_koopa = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        randVal = MBRand(5.0f);
        for (i = 0; i < ARRAY_COUNT(D_80109554_3C6374_koopa); i++) {
            D_80109554_3C6374_koopa[i] = HuSprGrpCreate(1, 5);
            func_80055024_55C24(D_80109554_3C6374_koopa[i], 0, D_80109558_3C6378_koopa, 1);
            HuSprPriSet(D_80109554_3C6374_koopa[i], 0, 0x4770);
            HuSprAttrSet(D_80109554_3C6374_koopa[i], 0, 0x1000);
            func_80054904_55504(D_80109554_3C6374_koopa[i], 0, D_8010951A_3C633A_koopa[0] + (i * 0xC8), (D_8010951A_3C633A_koopa[1] - 0x28));
            if ((randVal == 0) && (D_80109504_3C6324_koopa == 0)) {
                var_v0_2 = D_80109500_3C6320_koopa;
                if (var_v0_2 == 0) {
                    func_80055420_56020(D_80109554_3C6374_koopa[i], 0, 0, 0, 0xFF);     
                } else {
                    if (var_v0_2 < 0) {
                        var_v0_2 = -var_v0_2;
                    }
                    if (var_v0_2 < 2) {
                        func_80055420_56020(D_80109554_3C6374_koopa[i], 0, 0xFF, 0xFF, 0);
                    } else {
                        func_80055420_56020(D_80109554_3C6374_koopa[i], 0, 0xFF, 0, 0);                      
                    }
                }
            } else {
                func_80055420_56020(D_80109554_3C6374_koopa[i], 0, 0xFF, 0, 0);   
            }
        }
    }
}

void func_80106FC8_3C3DE8_koopa(void) {
    void* temp_v0;

    if (D_80109562_3C6382_koopa == -1) {
        D_80109562_3C6382_koopa = HuSprGrpCreate(1, 5);
        temp_v0 = DataRead(0x1301EA);
        D_80109564_3C6384_koopa = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
        func_80055024_55C24(D_80109562_3C6382_koopa, 0, D_80109564_3C6384_koopa, 0);
        HuSprPriSet(D_80109562_3C6382_koopa, 0, 0x100);
        HuSprAttrSet(D_80109562_3C6382_koopa, 0, 0x1000);
        func_80054904_55504(D_80109562_3C6382_koopa, 0, 0x32, D_801093A4_3C61C4_koopa);
    }
}

s32 func_80107090_3C3EB0_koopa(void) {
    s32 var_s3;
    GW_PLAYER* temp_s1;
    s32 i, j;

    if (GwSystem.current_board_index == 0) {
        for (var_s3 = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
            temp_s1 = MBGetPlayerStruct(i);
            for (j = 0; D_80109418_3C6238_koopa[j] != -1; j++) {
                if (MBMasuLinkMasuIdGet(temp_s1->clink, temp_s1->cidx) == D_80109418_3C6238_koopa[j]) {
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

const char D_801094C0_3C62E0_koopa[] = "%d";
const char D_801094C4_3C62E4_koopa[] = "";

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107190_3C3FB0_koopa);

void func_80107648_3C4468_koopa(void) {
    D_80109550_3C6370_koopa->work[0] = 0;
}

s32 func_80107658_3C4478_koopa(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 playerRank;

    temp_s0 = BoardGetTurnTier(CUR_TURN);
    playerRank = BoardPlayerRankCalc(arg1);
    return D_80109434_3C6254_koopa[arg0][temp_s0][playerRank];
}

u16 func_801076CC_3C44EC_koopa(s32 playerIndex, s32 arg1) {
    s32 temp_s0;
    s32 playerRank;

    temp_s0 = BoardGetTurnTier(CUR_TURN);
    playerRank = BoardPlayerRankCalc(playerIndex);
    return D_80109434_3C6254_koopa[2][temp_s0][playerRank];
}

void func_80107724_3C4544_koopa(void) {
    func_800F5E24_109A44_shared_board(D_801094F4_3C6314_koopa);
    func_800F4994_1085B4_shared_board(0x18);
    func_800F5E24_109A44_shared_board(-1);
    HuPrcSleep(20);
}

void func_8010775C_3C457C_koopa(void) {
    func_800F5E24_109A44_shared_board(D_801094F4_3C6314_koopa);
    func_800F4994_1085B4_shared_board(0x18);
    func_800F5E24_109A44_shared_board(-1);
}

s32 func_8010778C_3C45AC_koopa(void) {
    s32 temp_v0;

    temp_v0 = func_80107658_3C4478_koopa(0, D_801094F4_3C6314_koopa);
    sprintf(D_80109508_3C6328_koopa, D_801094C0_3C62E0_koopa, temp_v0);
    if (GwPlayer[D_801094F4_3C6314_koopa].coin >= temp_v0) {
        MBWinInsertOpen(0x420D, D_80109508_3C6328_koopa, 0, 0, 0, 0);
    } else {
        MBWinInsertOpen(0x420E, D_80109508_3C6328_koopa, 0, 0, 0, 0);
    }
    
    func_800EC3C0_FFFE0_shared_board(D_801094F4_3C6314_koopa);
    func_800EC3E4_100004_shared_board();
    func_80107724_3C4544_koopa();
    MBMotionShiftSet(D_801094F8_3C6318_koopa, 2, 0, 5, 0);
    func_800EE884_1024A4_shared_board(D_801094F8_3C6318_koopa, -1, 2);
    HuPrcSleep(14);
    HuAudFXPlay(0x29F);
    func_800F5D44_109964_shared_board(D_801094F4_3C6314_koopa, -temp_v0);
    func_800FF900_113520_shared_board(D_801094F6_3C6316_koopa, 3);
    HuPrcSleep(30);
    MBWinOpen(0x420F);
    func_800EC3C0_FFFE0_shared_board(D_801094F4_3C6314_koopa);
    func_800EC3E4_100004_shared_board();
    return 0;
}

s32 func_801078CC_3C46EC_koopa(void) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a0_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 i;

    temp_v0 = func_80107658_3C4478_koopa(1, D_801094F4_3C6314_koopa);
    sprintf(D_80109508_3C6328_koopa, D_801094C0_3C62E0_koopa, temp_v0);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].coin < temp_v0) {
            break;
        }
    }

    if (i == 4) {
        MBWinInsertOpen(0x4210, D_80109508_3C6328_koopa, 0, 0, 0, 0);
    } else {
        MBWinInsertOpen(0x4211, D_80109508_3C6328_koopa, 0, 0, 0, 0);
    }
    
    func_800EC3C0_FFFE0_shared_board(D_801094F4_3C6314_koopa);
    func_800EC3E4_100004_shared_board();
    func_800F4994_1085B4_shared_board(0);
    HuPrcSleep(20);
    MBMotionShiftSet(D_801094F8_3C6318_koopa, 2, 0, 5, 0);
    func_800EE884_1024A4_shared_board(D_801094F8_3C6318_koopa, -1, 2);
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
    for (i = 0; i < 4; i++) {
        func_800F5BF4_109814_shared_board(i, -temp_v0, i == var_s1);
        func_800FF900_113520_shared_board(i, 3);
    }

    HuPrcSleep(30);
    MBWinOpen(0x420F);
    func_800EC3C0_FFFE0_shared_board(D_801094F4_3C6314_koopa);
    func_800EC3E4_100004_shared_board();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107A9C_3C48BC_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80107DDC_3C4BFC_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108360_3C5180_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801085E4_3C5404_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108664_3C5484_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801086E4_3C5504_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801087F0_3C5610_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108A2C_3C584C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108BB0_3C59D0_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80108D2C_3C5B4C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801091C4_3C5FE4_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_80109220_3C6040_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_8010926C_3C608C_koopa);

INCLUDE_ASM("asm/nonmatchings/overlays/koopa/3C27C0", func_801092A0_3C60C0_koopa);

s32 func_801092D4_3C60F4_koopa(void) {
    Hu3DCamInit(1);
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    func_800E69BC_FA5DC_shared_board(2);
    return func_800E9344_FCF64_shared_board(100.0f, 10000.0f);
}

void func_80109320_3C6140_koopa(void) {
    func_800E69D8_FA5F8_shared_board();
    func_800E66E0_FA300_shared_board();
}
