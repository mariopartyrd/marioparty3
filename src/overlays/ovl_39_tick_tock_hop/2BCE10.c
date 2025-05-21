#include "ovl_39.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

// EXTERN

s32 func_80036C4C_3784C();

void Hu3DModelRotSet(s16, f32, f32, f32);
void* HuMemAllocTag(s32, s32);
s32 func_8000B638_C238(void);
s32 func_80017BB8_187B8(s32, s32);
f32 func_8001C7D0_1D3D0(s32);
s32 func_80037030_37C30(void);
void func_80045010_45C10(const s16*, s32);
void func_80045F1C_46B1C(s32, s32, s32);
void func_8004ABE8_4B7E8(s32, s32);
void func_8004AC10_4B810(s32, s32);
void func_8004AC98_4B898(s32, s16);
void func_8004AD50_4B950(s32);
void func_8004B25C_4BE5C(s16, s32, s32, s32);
void func_80054FF8_55BF8(s32, s32, s32);
void func_800E18D8_B4458_name_82(void);
void func_800E19F0_B4570_name_82(s32);
void func_800E1BA8_B4728_name_82(omObjData*, s32, s32, u16, s32, s32);
void func_800E4E30_B79B0_name_82(omObjData*);
void func_800E5690_B8210_name_82(omObjData*, u16);
void func_800E5A00_B8580_name_82(omObjData*, s32, s32, s32, s32);

extern s32 D_800A178C[][6];
extern s16 D_800EBE28_BE9A8_name_82;
extern s16 D_800EC1B8_BED38_name_82;
extern omObjData* D_800EC1C0_BED40_name_82;
extern u16 D_800EC280_BEE00_name_82;
extern omObjData* D_800EC598_BF118_name_82[];
extern s8 D_800CBB6E_CC76E[];
extern u16 D_800CDA7C_CE67C[];
extern f32 D_800CE1C8_CEDC8;
extern f32 D_800D138C_D1F8C[];
extern s8 D_800D20A1_D2CA1[];
extern f32 D_800D6ABC_D76BC[];

// LOCAL

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s8 unk28;
    /* 0x29 */ char unk29[0x33];
} D_8010E6E0_2C5B50_Struct; // Size 0x5C

void func_801059BC_2BCE2C_tick_tock_hop(void);
void func_80105B90_2BD000_tick_tock_hop(void);
void func_80105C9C_2BD10C_tick_tock_hop(omObjData* arg0);
void func_80105D1C_2BD18C_tick_tock_hop(omObjData* arg0);
void func_80105CE4_2BD154_tick_tock_hop(omObjData* arg0);
void func_80105E1C_2BD28C_tick_tock_hop(omObjData* arg0);
void func_80105FB4_2BD424_tick_tock_hop(omObjData* arg0);
void func_80105FF0_2BD460_tick_tock_hop(omObjData* arg0);
void func_80106504_2BD974_tick_tock_hop(omObjData* arg0);
void func_80106534_2BD9A4_tick_tock_hop(omObjData* arg0);
void func_801068D4_2BDD44_tick_tock_hop(omObjData* arg0);
void func_80106904_2BDD74_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80106980_2BDDF0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80106AA8_2BDF18_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80106D80_2BE1F0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80107380_2BE7F0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_801074CC_2BE93C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80107838_2BECA8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80107E88_2BF2F8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80108094_2BF504_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
f32 func_801082A0_2BF710_tick_tock_hop(s16 arg0, s16 arg1);
void func_80108368_2BF7D8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_8010847C_2BF8EC_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80108678_2BFAE8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_801087BC_2BFC2C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80108B18_2BFF88_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80108C24_2C0094_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80108D90_2C0200_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_8010908C_2C04FC_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_8010942C_2C089C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_8010955C_2C09CC_tick_tock_hop(D_8010E6E4_2C5B54_Struct* arg0, s32 arg1, s32 arg2);
void func_80109568_2C09D8_tick_tock_hop(D_8010E6E4_2C5B54_Struct* arg0, s32 arg1);
void func_80109570_2C09E0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_801096B0_2C0B20_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80109700_2C0B70_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);

D_8010E6E0_2C5B50_Struct* D_8010E6E0_2C5B50_tick_tock_hop;
D_8010E6E4_2C5B54_Struct* D_8010E6E4_2C5B54_tick_tock_hop;
s16 D_8010E6E8_2C5B58_tick_tock_hop[2];
s16 D_8010E6EC_2C5B5C_tick_tock_hop[2];

s16 D_8010E4A0_2C5910_tick_tock_hop = 1;
s16 D_8010E4A2_2C5912_tick_tock_hop = 0;
s16 D_8010E4A4_2C5914_tick_tock_hop = 0;
s16 D_8010E4A6_2C5916_tick_tock_hop = 0;
s16 D_8010E4A8_2C5918_tick_tock_hop = 0;
s16 D_8010E4AA_2C591A_tick_tock_hop = 0;

const s16 D_8010E5F0_2C5A60_tick_tock_hop[] = {
    0x8272, 0x8273, 0x8260, 0x8271, 0x8273, 0x0000
};

const s16 D_8010E5FC_2C5A6C_tick_tock_hop[] = {
    0x8265, 0x8268, 0x826D, 0x8268, 0x8272, 0x8267, 0x0000, 0x0000
};

const s16 D_8010E60C_2C5A7C_tick_tock_hop[] = {
    0x8263, 0x8271, 0x8260, 0x8276, 0x0000, 0x0000
};

void func_801059A0_2BCE10_tick_tock_hop() {
    func_801059BC_2BCE2C_tick_tock_hop();
}

void func_801059BC_2BCE2C_tick_tock_hop(void) {
    s32 temp_s0;

    Hu3DAnimInit(50);
    func_800142A0_14EA0(0x30);
    omInitObjMan(50, 0);
    func_8004A208_4AE08();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_8004B340_4BF40), 0xA0);
    HmfLightColorSet(0, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightDirSet(1, -56.0f, 50.0f, 56.0f);
    func_8000B5F0_C1F0(1);
    temp_s0 = func_8000B638_C238();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 60.0f, 80.0f, 4000.0f);
    D_800EC1B8_BED38_name_82 = 0;
    D_800EC280_BEE00_name_82 = 0;
    D_800EBE28_BE9A8_name_82 = 0;
    func_80109A00_2C0E70_tick_tock_hop();
    func_80105B90_2BD000_tick_tock_hop();
    omAddObj(1000, 0, 0, -1, func_80105E1C_2BD28C_tick_tock_hop);
    omAddObj(2000, 0, 0, -1, func_80105C9C_2BD10C_tick_tock_hop);
    func_80045010_45C10(D_8010E5F0_2C5A60_tick_tock_hop, 1);
    func_80045010_45C10(D_8010E5FC_2C5A6C_tick_tock_hop, 1);
    func_80045010_45C10(D_8010E60C_2C5A7C_tick_tock_hop, 1);
}

void func_80105B90_2BD000_tick_tock_hop(void) {
    s16 var_a2 = 0;
    s16 var_a1 = 0;
    s16 var_a0;

    for (var_a0 = 0; var_a0 < 4; var_a0++) {
        if (GwPlayer[var_a0].group == 0) {
            if (var_a2 == 0) {
                D_8010E6E8_2C5B58_tick_tock_hop[0] = var_a0;
                var_a2 = 1;
            }
        } else if (GwPlayer[var_a0].group == 1) {
            if (var_a1 == 0) {
                D_8010E6E8_2C5B58_tick_tock_hop[1] = var_a0;
                var_a1 = 1;
            }
        }
    }
    D_8010E6E0_2C5B50_tick_tock_hop = HuMemAllocTag(sizeof(*D_8010E6E0_2C5B50_tick_tock_hop), 31000);
    memset(D_8010E6E0_2C5B50_tick_tock_hop, 0, sizeof(*D_8010E6E0_2C5B50_tick_tock_hop));
    D_8010E6E4_2C5B54_tick_tock_hop = HuMemAllocTag(2 * sizeof(*D_8010E6E4_2C5B54_tick_tock_hop), 31000);
    memset(D_8010E6E4_2C5B54_tick_tock_hop, 0, 2 * sizeof(*D_8010E6E4_2C5B54_tick_tock_hop));
}

void func_80105C9C_2BD10C_tick_tock_hop(omObjData* arg0) {
    if (D_800D530C_D5F0C == 1) {
        WipeCreateOut(0, 20);
        arg0->func = func_80105CE4_2BD154_tick_tock_hop;
    }
}

void func_80105CE4_2BD154_tick_tock_hop(omObjData* arg0) {
    if (WipeStatGet() == 0) {
        arg0->func = func_80105D1C_2BD18C_tick_tock_hop;
    }
}

void func_80105D1C_2BD18C_tick_tock_hop(omObjData* arg0) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80105D40_2BD1B0_tick_tock_hop(void) {
    if (D_800D138C_D1F8C[0] > 360.0f) {
        D_800D138C_D1F8C[0] -= 360.0f;
    } else if (D_800D138C_D1F8C[0] < 0.0f) {
        D_800D138C_D1F8C[0] += 360.0f;
    }
    if (D_800D138C_D1F8C[1] > 360.0f) {
        D_800D138C_D1F8C[1] -= 360.0f;
    } else if (D_800D138C_D1F8C[1] < 0.0f) {
        D_800D138C_D1F8C[1] += 360.0f;
    }
    func_80109E2C_2C129C_tick_tock_hop(0);
}

void func_80105E1C_2BD28C_tick_tock_hop(omObjData* arg0) {
    D_8010E6F4_2C5B64_Unk04_Struct* temp_a1;
    s16 temp_smth;
    s16 var_s0;

    func_800E18D8_B4458_name_82();
    func_800E19F0_B4570_name_82(1);
    func_80109A94_2C0F04_tick_tock_hop(NULL, 0, 0, 4);
    func_80109BE4_2C1054_tick_tock_hop(0, 0, NULL, func_80106904_2BDD74_tick_tock_hop, 0);
    arg0->work[1] = 1;
    func_80109A94_2C0F04_tick_tock_hop(arg0, arg0->work[1], 0, 4);
    temp_smth = func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0xFFFF, NULL, func_8010D2FC_2C476C_tick_tock_hop, arg0->work[1]);
    temp_a1 = &D_8010E6F4_2C5B64_tick_tock_hop[arg0->work[1]].unk04[temp_smth];
    temp_a1->unk40(NULL, temp_a1);
    func_8010DA80_2C4EF0_tick_tock_hop(D_8010E6EC_2C5B5C_tick_tock_hop, 2);
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        D_800EC598_BF118_name_82[var_s0] = omAddObj(300, 9, 0x27, -1, func_80106534_2BD9A4_tick_tock_hop);
    }
    D_800EC1C0_BED40_name_82 = omAddObj(10, 5, 0, -1, func_80105FF0_2BD460_tick_tock_hop);
    WipeCreateIn(0xFF, 16);
    arg0->func = func_80105FB4_2BD424_tick_tock_hop;
}

void func_80105FB4_2BD424_tick_tock_hop(omObjData* arg0) {
    func_80109E2C_2C129C_tick_tock_hop(1);
    func_80105D40_2BD1B0_tick_tock_hop();
    func_8010A300_2C1770_tick_tock_hop();
    func_8010A620_2C1A90_tick_tock_hop();
    func_8010ABCC_2C203C_tick_tock_hop();
}

void func_80105FF0_2BD460_tick_tock_hop(omObjData* arg0) {
    D_8010E6F4_2C5B64_Unk00_Struct* temp_s3;
    s32 var_s4 = 0xB9;
    s32 var_s0 = 0x4000;
    D_8010E700_2C5B70_Unk60_Struct sp28 = { {
        {  30.000002f, 0.0f, 100.0f },
        { -30.000002f, 0.0f, 100.0f },
        { -30.000002f, 0.0f, 400.0f },
        {  30.000002f, 0.0f, 400.0f }
    } };
    D_8010E700_2C5B70_Unk60_Struct sp58 = { {
        {  90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 400.0f },
        {  90.0f, 0.0f, 400.0f }
    } };
    f32 sp88[] = { 35.0f, 60.0f, 120.0f, 145.0f, 215.0f, 240.0f, 300.0f, 325.0f };
    f32 temp_f22;
    f32 temp_f20;
    s16 temp_s1;
    s16 var_s2;

    temp_s3 = func_80109A94_2C0F04_tick_tock_hop(arg0, 2, 5, 16)->unk00;
    temp_s3->unk04[0] = D_8010E6E0_2C5B50_tick_tock_hop->unk10 = func_8000B108_BD08(0x5A0000, var_s4);
    temp_s3->unk04[1] = D_8010E6E0_2C5B50_tick_tock_hop->unk12 = func_8000B108_BD08(0x5A0001, var_s4);
    temp_s3->unk04[2] = func_8000B108_BD08(0x5A0002, var_s4);
    temp_s3->unk04[3] = func_8000B108_BD08(0x5A0003, var_s4);
    func_8010A21C_2C168C_tick_tock_hop(func_8010A07C_2C14EC_tick_tock_hop(0xFFFF, 0x5A, 6, 0, var_s0), 0xA0, 0x78);
    for (var_s2 = 0; var_s2 < 8; var_s2++) {
        temp_f22 = HuMathSin(sp88[var_s2]) * 600.0f;
        temp_f20 = HuMathCos(sp88[var_s2]) * 600.0f;
        if (var_s2 % 2 != 0) {
            temp_s1 = func_8010A3A8_2C1818_tick_tock_hop(90, 5, 0.25f, 1, var_s4);
        } else {
            temp_s1 = func_8010A3A8_2C1818_tick_tock_hop(90, 4, 0.25f, 1, var_s4);
        }
        func_8010A4A8_2C1918_tick_tock_hop(temp_s1, temp_f22, -25.0f, temp_f20, 0.0f, 0.0f, 0.0f, 0.4f, rand16() % 31);
        func_8001C258_1CE58(D_8010E6FC_2C5B6C_tick_tock_hop[temp_s1].unk0A, 4, 0);
    }
    D_8010E6E0_2C5B50_tick_tock_hop->unk14 = func_8010A07C_2C14EC_tick_tock_hop(0xF, 0, 0x2D, 0, 0);
    D_8010E6E0_2C5B50_tick_tock_hop->unk16 = temp_s1 = func_8010A07C_2C14EC_tick_tock_hop(0xF, 0, 0x2D, 0, 0);
    func_8010A21C_2C168C_tick_tock_hop(temp_s1, 0x118, 0x20);
    D_8010E6E0_2C5B50_tick_tock_hop->unk00 = 270.0f;
    D_8010E6E0_2C5B50_tick_tock_hop->unk04 = 0.0f;
    Hu3DModelRotSet(temp_s3->unk04[0], D_8010E6E0_2C5B50_tick_tock_hop->unk04, D_8010E6E0_2C5B50_tick_tock_hop->unk00, D_8010E6E0_2C5B50_tick_tock_hop->unk04);
    Hu3DModelRotSet(temp_s3->unk04[1], 0.0f, D_8010E6E0_2C5B50_tick_tock_hop->unk04, 0.0f);
    Hu3DModelPosSet(temp_s3->unk04[0], 0.0f, 25.0f, 0.0f);
    Hu3DModelPosSet(temp_s3->unk04[1], 0.0f, 0.0f, 0.0f);
    Hu3DModelPosSet(temp_s3->unk04[2], 0.0f, 30.0f, 0.0f);
    Hu3DModelPosSet(temp_s3->unk04[3], 0.0f, -40.0f, 0.0f);
    func_80109BE4_2C1054_tick_tock_hop(2, 0xF, NULL, func_80108094_2BF504_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(2, 0xF, NULL, func_80107E88_2BF2F8_tick_tock_hop, 0);
    D_8010E6E0_2C5B50_tick_tock_hop->unk18 = func_8010D34C_2C47BC_tick_tock_hop(temp_s3->unk04[0], &sp28, 25.0f, 2, 1);
    D_8010E6E0_2C5B50_tick_tock_hop->unk1A = func_8010D34C_2C47BC_tick_tock_hop(temp_s3->unk04[0], &sp58, 0.0f, 2, 4);
    D_8010E6E0_2C5B50_tick_tock_hop->unk08 = 0.0f;
    D_8010E6E0_2C5B50_tick_tock_hop->unk0C = 0.0f;
    D_8010E6E0_2C5B50_tick_tock_hop->unk28 = 0;
    arg0->model[0] = temp_s3->unk04[0];
    func_8010DB8C_2C4FFC_tick_tock_hop(arg0);
    func_80109BE4_2C1054_tick_tock_hop(2, 0, NULL, func_801074CC_2BE93C_tick_tock_hop, 0);
    arg0->func = func_80106504_2BD974_tick_tock_hop;
}

void func_80106504_2BD974_tick_tock_hop(omObjData* arg0) {
    func_80109E2C_2C129C_tick_tock_hop(2);
    func_8010DB8C_2C4FFC_tick_tock_hop(arg0);
}

void func_80106534_2BD9A4_tick_tock_hop(omObjData* arg0) {
    D_8010E6E4_2C5B54_Struct* temp_s0;
    s32 var_a0 = 0x2B9;
    s32 temp_a1;
    s32 temp_a2;

    arg0->work[0] = D_800EC280_BEE00_name_82;
    temp_s0 = &D_8010E6E4_2C5B54_tick_tock_hop[D_800EC280_BEE00_name_82];
    temp_s0->unk02 = GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[D_800EC280_BEE00_name_82]].chr;
    temp_a1 = D_800A178C[temp_s0->unk02][0];
    temp_a2 = D_800A178C[temp_s0->unk02][1];
    func_800E1BA8_B4728_name_82(arg0, temp_a1, temp_a2, D_8010E6E8_2C5B58_tick_tock_hop[arg0->work[0]], var_a0, var_a0);
    arg0->model[7] = func_8000B108_BD08(8, var_a0);
    func_8001C258_1CE58(arg0->model[7], 4, 4);
    temp_s0->unk52 = func_8010A788_2C1BF8_tick_tock_hop(0x57, 0x10, 0xB);
    func_800E5A00_B8580_name_82(arg0, 0, func_80017BB8_187B8(temp_s0->unk02, 0), 1, 0);
    func_800E5A00_B8580_name_82(arg0, 2, func_80017BB8_187B8(temp_s0->unk02, 2), 1, 0);
    func_800E5A00_B8580_name_82(arg0, 6, func_80017BB8_187B8(temp_s0->unk02, 4), 1, 19);
    func_800E5A00_B8580_name_82(arg0, 0x15, func_80017BB8_187B8(temp_s0->unk02, 0x1F), 1, 999);
    func_800E5A00_B8580_name_82(arg0, 0xD, func_80017BB8_187B8(temp_s0->unk02, 0x30), 1, 999);
    func_800E5A00_B8580_name_82(arg0, 0xE, func_80017BB8_187B8(temp_s0->unk02, 0x1A), 1, 0);
    func_800E5A00_B8580_name_82(arg0, 0x26, func_80017BB8_187B8(temp_s0->unk02, 0x36), 1, 999);
    func_8010955C_2C09CC_tick_tock_hop(temp_s0, 0, 1);
    temp_s0->unk0C = -1;
    temp_s0->unk00 = ((s8*) arg0->data)[0x57]; // TODO: figure out type.
    temp_s0->unk04 = 1;
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    D_800EC280_BEE00_name_82++;
    temp_s0->unk40 = func_8010D49C_2C490C_tick_tock_hop(D_8010E6E0_2C5B50_tick_tock_hop->unk18, arg0->model[0]);
    temp_s0->unk44 = func_8010D49C_2C490C_tick_tock_hop(D_8010E6E0_2C5B50_tick_tock_hop->unk1A, arg0->model[0]);
    arg0->work[1] = arg0->work[0] + 3;
    func_80109A94_2C0F04_tick_tock_hop(arg0, arg0->work[1], 0, 0xA);
    temp_s0->unk20 = arg0->work[1];
    temp_s0->unk22 = func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0, temp_s0, func_801096B0_2C0B20_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0xF, temp_s0, func_80108368_2BF7D8_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0x1F, temp_s0, func_8010847C_2BF8EC_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0x1F, temp_s0, func_80108678_2BFAE8_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0xEFFF, temp_s0, func_80108B18_2BFF88_tick_tock_hop, 0);
    func_80109BE4_2C1054_tick_tock_hop(arg0->work[1], 0xFFFF, temp_s0, func_8010942C_2C089C_tick_tock_hop, 0);
    arg0->func = func_801068D4_2BDD44_tick_tock_hop;
}

void func_801068D4_2BDD44_tick_tock_hop(omObjData* arg0) {
    func_80109E2C_2C129C_tick_tock_hop(arg0->work[1]);
    func_800E4E30_B79B0_name_82(arg0);
}

void func_80106904_2BDD74_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_800D6ABC_D76BC[0] = 0.0f;
    D_800D6ABC_D76BC[1] = 0.0f;
    D_800D6ABC_D76BC[2] = -137.0f;
    D_800D138C_D1F8C[0] = 298.0f;
    D_800D138C_D1F8C[1] = 180.0f;
    D_800D138C_D1F8C[2] = 0.0f;
    D_800CE1C8_CEDC8 = 990.0f;
    func_80109CC0_2C1130_tick_tock_hop(0, arg1);
}

void func_80106980_2BDDF0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    s16 temp_s1;
    s16 temp_f2;

    temp_s1 = D_8010E6E0_2C5B50_tick_tock_hop->unk1C % 10;
    temp_f2 = D_8010E6E0_2C5B50_tick_tock_hop->unk1C * 0.1f;
    if (temp_f2 != 0) {
        func_8010A21C_2C168C_tick_tock_hop(D_8010E6E0_2C5B50_tick_tock_hop->unk14, 0x108, 0x20);
    } else {
        func_8010A2B0_2C1720_tick_tock_hop(D_8010E6E0_2C5B50_tick_tock_hop->unk14);
    }
    func_80054FF8_55BF8(D_8010E6F8_2C5B68_tick_tock_hop[D_8010E6E0_2C5B50_tick_tock_hop->unk14].unk01, 0, temp_f2);
    func_80054FF8_55BF8(D_8010E6F8_2C5B68_tick_tock_hop[D_8010E6E0_2C5B50_tick_tock_hop->unk16].unk01, 0, temp_s1);
}

void func_80106AA8_2BDF18_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    s16 var_s0;

    if (arg1->unk04 == 0) {
        arg1->unk1C[0] = 0;
        arg1->unk04 = 1;
    }
    arg1->unk1C[0]++;
    switch (arg1->unk1C[0]) {
        case 5:
            func_80036C4C_3784C(6);
            HuAudFXPlay(0xE);
            D_8010E4A4_2C5914_tick_tock_hop = 1;
            break;
        case 30:
            D_8010E4A2_2C5912_tick_tock_hop = 1;
            break;
        default:
            if (D_8010E4A2_2C5912_tick_tock_hop != 0 && func_80037030_37C30() == 2) {
                D_8010E4A0_2C5910_tick_tock_hop = 1;
                D_8010E6E0_2C5B50_tick_tock_hop->unk08 = 0.0f;
                D_8010E6E0_2C5B50_tick_tock_hop->unk0C = 3.0f;
                for (var_s0 = 0; var_s0 < 2; var_s0++) {
                    if (GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[var_s0]].stat & 1) {
                        func_80109BE4_2C1054_tick_tock_hop(var_s0 + 3, 0, &D_8010E6E4_2C5B54_tick_tock_hop[var_s0], func_80109570_2C09E0_tick_tock_hop, 0);
                    } else {
                        func_80109CC0_2C1130_tick_tock_hop(D_8010E6E4_2C5B54_tick_tock_hop[var_s0].unk20, &D_8010E6F4_2C5B64_tick_tock_hop[D_8010E6E4_2C5B54_tick_tock_hop[var_s0].unk20].unk04[D_8010E6E4_2C5B54_tick_tock_hop[var_s0].unk22]);
                    }
                }
                func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80106980_2BDDF0_tick_tock_hop, 0);
                arg1->unk40 = func_80106D80_2BE1F0_tick_tock_hop;
            }
            break;
    }
    if (D_8010E4A4_2C5914_tick_tock_hop != 0 && func_80037030_37C30() != 0) {
        D_8010E4A4_2C5914_tick_tock_hop++;
        if (D_8010E4A4_2C5914_tick_tock_hop >= 45) {
            HuAudSeqPlay(0x2F);
            D_8010E4A4_2C5914_tick_tock_hop = 0;
        }
    }
}

void func_80106D14_2BE184_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    switch (arg1->unk04) {
        case 0:
            WipeCreateOut(0, 20);
            arg1->unk04 = 1;
            break;
        case 1:
            if (WipeStatGet() == 0) {
                omOvlReturnEx(1);
            }
            break;
    }
}

void func_80106D80_2BE1F0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* var_a1 = D_8010E6E4_2C5B54_tick_tock_hop;
    s16 sp18[2];
    f32 sp20;
    f32 sp24;
    s16 var_a0;
    s16 var_s0;

    sp18[0] = -1;
    sp18[1] = -1;
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk1C == 99) {
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk28 == 0) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk28 = 1;
        }
        sp20 = HmfModelData[D_8010E6E0_2C5B50_tick_tock_hop->unk12].unk2C;
        sp24 = HmfModelData[D_8010E6E0_2C5B50_tick_tock_hop->unk10].unk2C;
        func_8010DE30_2C52A0_tick_tock_hop(&sp20, &sp24);
        if (ABS(sp20 - sp24) > 90.0f) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk08 = D_8010E6E0_2C5B50_tick_tock_hop->unk0C = 0.0f;
            func_8004A994_4B594(0x78);
            func_80036C4C_3784C(0x11);
            func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80107380_2BE7F0_tick_tock_hop, 0);
            for (var_a0 = 0; var_a0 < 2; var_a0++) {
                D_8010E6E4_2C5B54_tick_tock_hop[var_a0].unk04 |= 8;
            }
            func_80109CC0_2C1130_tick_tock_hop(1, arg1);
        }
    } else {
        var_s0 = 0;
        for (var_a0 = 0; var_a0 < 2; var_a0++, var_a1++) {
            if (var_a1->unk04 & 8) {
                sp18[var_s0] = var_a0;
                var_s0++;
            }
        }
        if (var_s0 == 0) {
            return;
        }
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk28 == 0) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk28 = 1;
        }
        sp20 = HmfModelData[D_8010E6E0_2C5B50_tick_tock_hop->unk12].unk2C;
        sp24 = HmfModelData[D_8010E6E0_2C5B50_tick_tock_hop->unk10].unk2C;
        func_8010DE30_2C52A0_tick_tock_hop(&sp20, &sp24);
        if (ABS(sp20 - sp24) > 90.0f) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk08 = D_8010E6E0_2C5B50_tick_tock_hop->unk0C = 0.0f;
            func_8004A994_4B594(0x78);
            func_80036C4C_3784C(0x11);
            if (var_s0 == 2) {
                func_80109CC0_2C1130_tick_tock_hop(1, arg1);
                func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80107380_2BE7F0_tick_tock_hop, 0);
            } else {
                var_a0 = (sp18[0] == 0);
                D_8010E6E4_2C5B54_tick_tock_hop[var_a0].unk04 |= 0x10;
                func_80109BE4_2C1054_tick_tock_hop(var_a0 + 3, 0xFF, &D_8010E6E4_2C5B54_tick_tock_hop[var_a0], func_80108D90_2C0200_tick_tock_hop, 0);
                func_80109CC0_2C1130_tick_tock_hop(1, arg1);
            }
        }
    }
}

void func_80107140_2BE5B0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s2 = &D_8010E6E4_2C5B54_tick_tock_hop[0];
    D_8010E6E4_2C5B54_Struct* temp_s3 = &D_8010E6E4_2C5B54_tick_tock_hop[1];

    if (arg1->unk04 == 0) {
        arg1->unk1C[0] = 0;
        arg1->unk04 = 1;
    }
    if (D_8010E4A6_2C5916_tick_tock_hop == 0) {
        if (func_80037030_37C30() == 0) {
            D_8010E4A6_2C5916_tick_tock_hop = 1;
        }
    } else if (D_8010E4A6_2C5916_tick_tock_hop >= 2) {
        if (func_80037030_37C30() == 0) {
            D_8010E4A6_2C5916_tick_tock_hop = 3;
        }
        if (D_8010E4A6_2C5916_tick_tock_hop == 3) {
            arg1->unk1C[0]++;
            if (arg1->unk1C[0] >= 15) {
                func_80109CC0_2C1130_tick_tock_hop(1, arg1);
                func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80106D14_2BE184_tick_tock_hop, 0);
            }
        }
    } else {
        arg1->unk1C[0]++;
        if (arg1->unk1C[0] == 15) {
            HuAudSeqPlay(0x67);
            func_8010955C_2C09CC_tick_tock_hop(temp_s2, 0xD, 1);
            func_8010955C_2C09CC_tick_tock_hop(temp_s3, 0xD, 1);
            func_8004AC98_4B898(GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[0]].chr + 0x290, D_8010E6E8_2C5B58_tick_tock_hop[0]);
            func_8004AC98_4B898(GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[1]].chr + 0x290, D_8010E6E8_2C5B58_tick_tock_hop[1]);
            func_80036C4C_3784C(0x1E, temp_s2->unk02, temp_s3->unk02);
            GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[D_800EC598_BF118_name_82[0]->work[0]]].bonusCoin += 10;
            GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[D_800EC598_BF118_name_82[1]->work[0]]].bonusCoin += 10;
        }
        if (func_80037030_37C30() != 0) {
            arg1->unk1C[0] = 0;
            D_8010E4A6_2C5916_tick_tock_hop = 2;
        }
    }
}

void func_80107380_2BE7F0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    if (arg1->unk04 == 0) {
        arg1->unk1C[0] = 0;
        arg1->unk04 = 1;
    }
    if (D_8010E4A8_2C5918_tick_tock_hop == 0) {
        if (func_80037030_37C30() == 0) {
            D_8010E4A8_2C5918_tick_tock_hop = 1;
        }
    } else if (D_8010E4A8_2C5918_tick_tock_hop >= 2) {
        if (func_80037030_37C30() == 0) {
            D_8010E4A8_2C5918_tick_tock_hop = 3;
        }
        if (D_8010E4A8_2C5918_tick_tock_hop == 3) {
            arg1->unk1C[0]++;
            if (arg1->unk1C[0] >= 15) {
                func_80109CC0_2C1130_tick_tock_hop(1, arg1);
                func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80106D14_2BE184_tick_tock_hop, 0);
            }
        }
    } else {
        arg1->unk1C[0]++;
        if (arg1->unk1C[0] == 15) {
            func_8010955C_2C09CC_tick_tock_hop(&D_8010E6E4_2C5B54_tick_tock_hop[0], 0x26, 1);
            func_8010955C_2C09CC_tick_tock_hop(&D_8010E6E4_2C5B54_tick_tock_hop[1], 0x26, 1);
            func_80036C4C_3784C(0x20);
            HuAudSeqPlay(0x6C);
        }
        if (func_80037030_37C30() != 0) {
            arg1->unk1C[0] = 0;
            D_8010E4A8_2C5918_tick_tock_hop = 2;
        }
    }
}

void func_801074CC_2BE93C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    s16 var_s1;

    switch (arg1->unk04) {
        case 0:
            arg1->unk0C = 0;
            arg1->unk22 = 0;
            for (var_s1 = 0; var_s1 < 2; var_s1++) {
                arg1->unk1C[var_s1] = func_80109BE4_2C1054_tick_tock_hop(var_s1 + 3, 0xF, &D_8010E6E4_2C5B54_tick_tock_hop[var_s1], func_80108C24_2C0094_tick_tock_hop, 0);
            }
            arg1->unk04 = 1;
            break;
        case 1:
            arg1->unk22++;
            if (arg1->unk22 < 30.0f) {
                return;
            }
            arg1->unk04 = 2;
            HuAudFXPlay(0x4BB);
            arg1->unk24 = HuAudFXPlay(0x4BC);
            func_8004ABE8_4B7E8(arg1->unk24, 0);
            break;
    }
    if (arg1->unk0C == 0) {
        D_8010E6E0_2C5B50_tick_tock_hop->unk04 -= 4.0f;
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk04 < 0.0f) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk04 += 360.0f;
        }
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk04 < 180.0f) {
            func_8004AD50_4B950(arg1->unk24);
            arg1->unk10 = 0;
            arg1->unk0C = 1;
        }
    } else if (++arg1->unk0C >= 11) {
        if (arg1->unk0D == 0) {
            arg1->unk24 = HuAudFXPlay(0x4BC);
            func_8004ABE8_4B7E8(arg1->unk24, 0);
            HuAudFXPlay(0x4BB);
            arg1->unk0D = 1;
        }
        arg1->unk0C = 10;
        D_8010E6E0_2C5B50_tick_tock_hop->unk04 += 4.0f;
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk04 > 360.0f) {
            func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80106AA8_2BDF18_tick_tock_hop, 0);
            for (var_s1 = 0; var_s1 < 2; var_s1++) {
                func_80109CC0_2C1130_tick_tock_hop(var_s1 + 3, &D_8010E6F4_2C5B64_tick_tock_hop[var_s1 + 3].unk04[arg1->unk1C[var_s1]]);
            }
            D_8010E4A0_2C5910_tick_tock_hop = 0;
            D_8010E700_2C5B70_tick_tock_hop[D_8010E6E0_2C5B50_tick_tock_hop->unk18].unk00 &= ~1;
            D_8010E700_2C5B70_tick_tock_hop[D_8010E6E0_2C5B50_tick_tock_hop->unk18].unk00 = D_8010E700_2C5B70_tick_tock_hop[D_8010E6E0_2C5B50_tick_tock_hop->unk18].unk00;
            func_8004AD50_4B950(arg1->unk24);
            arg1->unk0D = 0;
            arg1->unk40 = func_80107838_2BECA8_tick_tock_hop;
            arg1->unk04 = 0;
        }
    }
}

void func_80107838_2BECA8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s2 = D_8010E6E4_2C5B54_tick_tock_hop;
    s16 var_v0 = 0;
    f32 sp10;
    f32 sp14;

    if (D_8010E6E0_2C5B50_tick_tock_hop->unk28 != 0) {
        return;
    }
    if (arg1->unk04 == 0) {
        arg1->unk0C = 0;
        D_8010E6E0_2C5B50_tick_tock_hop->unk24 = 1.0f;
        D_8010E6E0_2C5B50_tick_tock_hop->unk1C = 0;
        D_8010E6E0_2C5B50_tick_tock_hop->unk1E = 0;
        D_8010E6E0_2C5B50_tick_tock_hop->unk20 = rand16() % 3 + 1;
        arg1->unk04 = 1;
    }
    if (temp_s2->unk44->unk00 != 0) {
        if (arg1->unk0C == 0) {
            arg1->unk0C = 1;
        }
    } else {
        if (arg1->unk0C != 0) {
            D_8010E6E0_2C5B50_tick_tock_hop->unk1E++;
            D_8010E6E0_2C5B50_tick_tock_hop->unk1C++;
            D_8010E6E0_2C5B50_tick_tock_hop->unk24 = D_8010E6E0_2C5B50_tick_tock_hop->unk1C * 0.03f + 1.0f;
        }
        arg1->unk0C = 0;
    }
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk1E > D_8010E6E0_2C5B50_tick_tock_hop->unk20) {
        if (arg1->unk0D == 0) {
            var_v0 = 0;
            arg1->unk0D = 1;
            arg1->unk38 = 120 + rand16() % 60;
            switch (rand16() % 3) {
                case 0:
                    if (rand16() & 1) {
                        arg1->unk2C = 0.0f;
                        arg1->unk30 = func_801082A0_2BF710_tick_tock_hop(3, 4);
                    } else {
                        arg1->unk2C = func_801082A0_2BF710_tick_tock_hop(3, 4);
                        arg1->unk30 = 0.0f;
                    }
                    break;
                case 1:
                    if (rand16() & 1) {
                        if (rand16() & 1) {
                            arg1->unk2C = 3.0f;
                            arg1->unk30 = 1.0f;
                        } else {
                            arg1->unk2C = 1.0f;
                            arg1->unk30 = 3.0f;
                        }
                    } else {
                        if (rand16() & 1) {
                            arg1->unk2C = -3.0f;
                            arg1->unk30 = -1.0f;
                        } else {
                            arg1->unk2C = -1.0f;
                            arg1->unk30 = -3.0f;
                        }
                    }
                    break;
                case 2:
                    arg1->unk2C = func_801082A0_2BF710_tick_tock_hop(2, 3);
                    if (arg1->unk2C > 0.0f) {
                        arg1->unk30 = -(f32) ((rand16() & 1) + 2);
                    } else {
                        arg1->unk30 = (f32) ((rand16() & 1) + 2);
                    }
                    break;
            }
        } else {
            var_v0 = 0;
            sp10 = HmfModelData[arg0->unk04[1]].unk2C;
            sp14 = HmfModelData[arg0->unk04[0]].unk2C;
            func_8010DE30_2C52A0_tick_tock_hop(&sp10, &sp14);
            if (arg1->unk38 < ABS(sp10 - sp14)) {
                if (D_8010E6E0_2C5B50_tick_tock_hop->unk0C > 0.0f) {
                    if (arg1->unk2C < 0.0f) {
                        HuAudFXPlay(0x4BB);
                        var_v0 = 1;
                    }
                } else if (D_8010E6E0_2C5B50_tick_tock_hop->unk0C < 0.0f) {
                    if (arg1->unk2C > 0.0f) {
                        HuAudFXPlay(0x4BB);
                        var_v0 = 1;
                    }
                } else {
                    if (arg1->unk2C != 0.0f) {
                        HuAudFXPlay(0x4BB);
                        var_v0 = 1;
                    }
                }
                if (var_v0 == 0) {
                    if (D_8010E6E0_2C5B50_tick_tock_hop->unk08 > 0.0f) {
                        if (arg1->unk30 < 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else if (D_8010E6E0_2C5B50_tick_tock_hop->unk08 < 0.0f) {
                        if (arg1->unk30 > 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    } else {
                        if (arg1->unk30 != 0.0f) {
                            HuAudFXPlay(0x4BB);
                        }
                    }
                }
                D_8010E6E0_2C5B50_tick_tock_hop->unk0C = arg1->unk2C;
                D_8010E6E0_2C5B50_tick_tock_hop->unk08 = arg1->unk30;
                arg1->unk0D = 0;
                D_8010E6E0_2C5B50_tick_tock_hop->unk1E = 0;
                D_8010E6E0_2C5B50_tick_tock_hop->unk20 = (rand16() & 1) + 2;
            }
        }
    }
}

void func_80107E88_2BF2F8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    s32 var_a0;
    s16 var_s1;
    s16 var_a1;
    s16 var_a1_0;

    var_s1 = arg1->unk1C[0];
    D_8010E6E0_2C5B50_tick_tock_hop->unk04 += D_8010E6E0_2C5B50_tick_tock_hop->unk0C * D_8010E6E0_2C5B50_tick_tock_hop->unk24;
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk04 < 0.0f) {
        D_8010E6E0_2C5B50_tick_tock_hop->unk04 += 360.0f;
    } else if (D_8010E6E0_2C5B50_tick_tock_hop->unk04 > 360.0f) {
        D_8010E6E0_2C5B50_tick_tock_hop->unk04 -= 360.0f;
    }
    Hu3DModelRotSet(arg0->unk04[0], 0.0f, D_8010E6E0_2C5B50_tick_tock_hop->unk04, 0.0f);
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk0C != 0.0f) {
        if (arg1->unk0C == 0) {
            var_s1 = arg1->unk1C[0] = HuAudFXPlay(0x4BC);
            arg1->unk0C = 1;
        }
        var_a1_0 = D_8010E6E0_2C5B50_tick_tock_hop->unk24 * 150.0f;
        switch ((s16) ABS(D_8010E6E0_2C5B50_tick_tock_hop->unk0C)) {
            case 1:
                var_a0 = var_s1;
                var_a1 = var_a1_0;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 2:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 150;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 3:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 300;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 4:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 450;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
        }
    } else if (arg1->unk0C != 0) {
        func_8004AD50_4B950(var_s1);
        arg1->unk0C = 0;
    }
}

void func_80108094_2BF504_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    s32 var_a0;
    s16 var_s1;
    s16 var_a1;
    s16 var_a1_0;

    var_s1 = arg1->unk1C[0];
    D_8010E6E0_2C5B50_tick_tock_hop->unk00 += D_8010E6E0_2C5B50_tick_tock_hop->unk08 * D_8010E6E0_2C5B50_tick_tock_hop->unk24;
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk00 < 0.0f) {
        D_8010E6E0_2C5B50_tick_tock_hop->unk00 += 360.0f;
    } else if (D_8010E6E0_2C5B50_tick_tock_hop->unk00 > 360.0f) {
        D_8010E6E0_2C5B50_tick_tock_hop->unk00 -= 360.0f;
    }
    Hu3DModelRotSet(arg0->unk04[1], 0.0f, D_8010E6E0_2C5B50_tick_tock_hop->unk00, 0.0f);
    if (D_8010E6E0_2C5B50_tick_tock_hop->unk08 != 0.0f) {
        if (arg1->unk0C == 0) {
            var_s1 = arg1->unk1C[0] = HuAudFXPlay(0x4BD);
            arg1->unk0C = 1;
        }
        var_a1_0 = D_8010E6E0_2C5B50_tick_tock_hop->unk24 * 150.0f;
        switch ((s16) ABS(D_8010E6E0_2C5B50_tick_tock_hop->unk08)) {
            case 1:
                var_a0 = var_s1;
                var_a1 = var_a1_0;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 2:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 150;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 3:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 300;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
            case 4:
                var_a0 = var_s1;
                var_a1 = var_a1_0 + 450;
                func_8004ABE8_4B7E8(var_a0, var_a1);
                break;
        }
    } else if (arg1->unk0C != 0) {
        func_8004AD50_4B950(var_s1);
        arg1->unk0C = 0;
    }
}

f32 func_801082A0_2BF710_tick_tock_hop(s16 arg0, s16 arg1) {
    f32 var_f20;

    var_f20 = rand16() % (arg1 - arg0 + 1) + arg0;
    if (rand16() & 1) {
        var_f20 = -var_f20;
    }
    return var_f20;
}

void func_80108368_2BF7D8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_a2 = arg1->unk3C;
    omObjData* temp_s0 = arg0->unk00;
    D_8010E6F4_2C5B64_Unk04_Struct* temp_a1;

    if (D_8010E4A0_2C5910_tick_tock_hop == 0) {
        return;
    }
    if (temp_a2->unk04 & 0x18) {
        func_80109CC0_2C1130_tick_tock_hop(temp_s0->work[1], arg1);
    } else if (D_800CDA7C_CE67C[temp_a2->unk00] & 0x8000) {
        if (arg1->unk0C == 0 && !(temp_a2->unk04 & 2) && temp_a2->unk0A != 0x15) {
            arg1->unk0C = 1;
            temp_a2->unk04 |= 2;
            temp_a1 = &D_8010E6F4_2C5B64_tick_tock_hop[temp_s0->work[1]].unk04[func_80109BE4_2C1054_tick_tock_hop(temp_s0->work[1], 0xEFFF, temp_a2, func_801087BC_2BFC2C_tick_tock_hop, 0)];
            temp_a1->unk40(arg0, temp_a1);
        }
    } else {
        arg1->unk0C = 0;
    }
}

void func_8010847C_2BF8EC_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* var_v1 = arg1->unk3C;
    omObjData* temp_s1 = arg0->unk00;
    f32 temp_f20 = D_8010E6E0_2C5B50_tick_tock_hop->unk00;

    if (var_v1->unk04 & 8) {
        return;
    }
    if (arg1->unk04 == 0) {
        if (D_8010E6EC_2C5B5C_tick_tock_hop[temp_s1->work[0]] == 0) {
            arg1->unk2C = 185.0f;
            arg1->unk30 = 185.0f;
        } else {
            arg1->unk2C = 315.0f;
            arg1->unk30 = 315.0f;
        }
        arg1->unk04 = 1;
    }
    temp_s1->trans.x = HuMathSin(temp_f20) * arg1->unk2C;
    temp_s1->trans.z = HuMathCos(temp_f20) * arg1->unk30;
    HmfModelData[temp_s1->model[1]].unk1C = temp_s1->trans.x;
    HmfModelData[temp_s1->model[1]].unk24 = temp_s1->trans.z;
    if (ABS(D_8010E6E0_2C5B50_tick_tock_hop->unk00 - D_8010E6E0_2C5B50_tick_tock_hop->unk04) < 10.0f) {
        HmfModelData[temp_s1->model[1]].unk20 = 30.0f;
    } else {
        HmfModelData[temp_s1->model[1]].unk20 = 5.0f;
    }
}

void func_80108678_2BFAE8_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s0 = arg1->unk3C;
    omObjData* temp_s1 = arg0->unk00;
    Vec sp20;
    Vec sp30;
    f32 sp40[3];

    if (temp_s0->unk04 & 0x18) {
        func_80109CC0_2C1130_tick_tock_hop(temp_s1->work[1], arg1);
        return;
    }
    if (temp_s0->unk0A == 0x15 || temp_s0->unk0A == 6) {
        return;
    }
    if (D_800CBB6E_CC76E[temp_s0->unk00] == 0 && D_800D20A1_D2CA1[temp_s0->unk00] == 0) {
        func_8010955C_2C09CC_tick_tock_hop(temp_s0, 0, 1);
    } else {
        func_8010955C_2C09CC_tick_tock_hop(temp_s0, 2, 1);
        sp20.x = -D_800CBB6E_CC76E[temp_s0->unk00];
        sp20.y = 0.0f;
        sp20.z = D_800D20A1_D2CA1[temp_s0->unk00];
        sp30.x = 0.0f;
        sp30.y = 0.0f;
        sp30.z = 0.0f;
        func_8010DD00_2C5170_tick_tock_hop(sp30, sp20, sp40);
        temp_s1->rot.y = sp40[1];
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_801087BC_2BFC2C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s1 = arg1->unk3C;
    omObjData* temp_s0 = arg0->unk00;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f0_2;

    if ((temp_s0->trans.y == 0.0f) && (temp_s1->unk04 & 8)) {
        func_80109CC0_2C1130_tick_tock_hop(temp_s0->work[1], arg1);
        return;
    }
    if (arg1->unk04 == 0) {
        temp_s1->unk48 = -1.47f;
        func_8010A9B0_2C1E20_tick_tock_hop(temp_s1->unk52, &temp_s0->trans.x, 0, &temp_s0->trans.z);
        func_8010955C_2C09CC_tick_tock_hop(temp_s1, 6, 1);
        func_8004AC10_4B810(0x3A, GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[temp_s0->work[0]]].chr);
        arg1->unk04 = 1;
    }
    var_f2 = func_8001C7D0_1D3D0(temp_s0->model[0]);
    if (var_f2 == -1.0f) {
        var_f2 = HmfModelData[temp_s0->model[0]].unk40;
    }
    if (var_f2 > 5.0f && var_f2 < 7.0f && !(D_800CDA7C_CE67C[temp_s1->unk00] & 0x8000)) {
        temp_s1->unk48 = -0.294f;
    }
    var_f2_2 = temp_s1->unk48;
    if (var_f2_2 > 1.7f) {
        var_f2_2 = 1.7f;
    }
    temp_s0->trans.y += var_f2_2 * var_f2_2 * (var_f2_2 >= 0.0f ? -35.0f : 35.0f);
    temp_s1->unk48 += 0.15f;
    var_f0_2 = 1.0f - temp_s0->trans.y / 300.0f;
    if (var_f0_2 > 1.0f) {
        var_f0_2 = 1.0f;
    } else if (var_f0_2 < 0.5f) {
        var_f0_2 = 0.5f;
    }
    Hu3DModelScaleSet(temp_s0->model[1], var_f0_2, var_f0_2, var_f0_2);
    if (temp_s0->trans.y < 0.0f) {
        temp_s0->trans.y = 0.0f;
        temp_s1->unk04 &= ~2;
        temp_s1->unk04 |= 1;
        func_8010A9B0_2C1E20_tick_tock_hop(temp_s1->unk52, &temp_s0->trans.x, 0, &temp_s0->trans.z);
        func_8004AC10_4B810(0x31, GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[temp_s0->work[0]]].chr);
        func_8010955C_2C09CC_tick_tock_hop(temp_s1, 0x15, 1);
        func_80109568_2C09D8_tick_tock_hop(temp_s1, 0);
        func_80109CC0_2C1130_tick_tock_hop(temp_s0->work[1], arg1);
    }
}

void func_80108B18_2BFF88_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s1 = arg1->unk3C;
    omObjData* temp_s0 = arg0->unk00;

    if (!(temp_s1->unk04 & 0x18) && D_8010E6E0_2C5B50_tick_tock_hop->unk1C != 99 && temp_s1->unk40->unk00 != 0) {
        func_8001C258_1CE58(temp_s0->model[7], 4, 0);
        Hu3DModelPosSet(temp_s0->model[7], temp_s0->trans.x, 10.0f, temp_s0->trans.z);
        func_8010955C_2C09CC_tick_tock_hop(temp_s1, 0xE, 1);
        func_80109BE4_2C1054_tick_tock_hop(temp_s0->work[1], 0xFF, temp_s1, func_8010908C_2C04FC_tick_tock_hop, 0);
        temp_s1->unk04 |= 8;
        if (!(GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[temp_s0->work[0]]].stat & 1)) {
            func_8004B25C_4BE5C(temp_s0->work[0], 2, 2, 0x14);
        }
    }
}

void func_80108C24_2C0094_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s1 = arg1->unk3C;

    D_800CDA7C_CE67C[temp_s1->unk00] = 0;
    D_800CBB6E_CC76E[temp_s1->unk00] = 0;
    D_800D20A1_D2CA1[temp_s1->unk00] = 0;
    if (temp_s1->unk44->unk00 != 0) {
        arg1->unk0D = 1;
        arg1->unk0C++;
        if (arg1->unk0C < 5) {
            D_800CDA7C_CE67C[temp_s1->unk00] = 0x8000;
        }
    } else {
        arg1->unk0C = 0;
        if (arg1->unk0D != 0 && arg1->unk0E == 0) {
            D_800CBB6E_CC76E[temp_s1->unk00] = HuMathSin(arg1->unk2C) * 70.0f;
            D_800D20A1_D2CA1[temp_s1->unk00] = HuMathCos(arg1->unk2C) * 70.0f;
            arg1->unk2C += 10.0f;
            if (arg1->unk2C > 180.0f) {
                arg1->unk2C = 180.0f;
                arg1->unk0E = 1;
            }
        }
    }
}

void func_80108D90_2C0200_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s1 = arg1->unk3C;
    omObjData* temp_s2 = arg0->unk00;
    f32 var_f4;

    arg1->unk22++;
    if (arg1->unk22 < 40) {
        return;
    }
    switch (arg1->unk04) {
        case 0:
            if (temp_s1->unk0A == 0 || temp_s1->unk0A == 2) {
                arg1->unk1C[0] = 0;
                arg1->unk2C = temp_s2->rot.y;
                if (temp_s2->rot.y != 180.0f) {
                    func_8010955C_2C09CC_tick_tock_hop(temp_s1, 2, 1);
                    arg1->unk04 = 1;
                } else {
                    func_8010955C_2C09CC_tick_tock_hop(temp_s1, 0, 1);
                    arg1->unk04 = 2;
                }
            }
            break;
        case 1:
            var_f4 = arg1->unk1C[0] / 10.0f;
            if (var_f4 > 1.0f) {
                var_f4 = 1.0f;
            }
            temp_s2->rot.y = (180.0f - arg1->unk2C) * var_f4 + arg1->unk2C;
            arg1->unk1C[0]++;
            if (arg1->unk1C[0] >= 11) {
                arg1->unk1C[0] = 0;
                temp_s2->rot.y = 180.0f;
                func_8010955C_2C09CC_tick_tock_hop(temp_s1, 0, 1);
                arg1->unk04 = 2;
            }
            break;
        default:
            if (D_8010E6E0_2C5B50_tick_tock_hop->unk1C == 99) {
                func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80107140_2BE5B0_tick_tock_hop, 0);
                func_80109CC0_2C1130_tick_tock_hop(temp_s2->work[1], arg1);
            } else if (D_8010E4AA_2C591A_tick_tock_hop == 0) {
                if (func_80037030_37C30() == 0) {
                    D_8010E4AA_2C591A_tick_tock_hop = 1;
                }
            } else if (D_8010E4AA_2C591A_tick_tock_hop >= 2) {
                if (func_80037030_37C30() == 0) {
                    D_8010E4AA_2C591A_tick_tock_hop = 3;
                }
                if (D_8010E4AA_2C591A_tick_tock_hop == 3) {
                    arg1->unk1C[0]++;
                    if (arg1->unk1C[0] >= 15) {
                        func_80109CC0_2C1130_tick_tock_hop(1, arg1);
                        func_80109BE4_2C1054_tick_tock_hop(1, 0, NULL, func_80106D14_2BE184_tick_tock_hop, 0);
                    }
                }
            } else {
                arg1->unk1C[0]++;
                if (arg1->unk1C[0] == 15) {
                    HuAudSeqPlay(0x67);
                    func_8010955C_2C09CC_tick_tock_hop(temp_s1, 0xD, 1);
                    func_80036C4C_3784C(0x16, temp_s1->unk02);
                    GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[temp_s2->work[0]]].bonusCoin += 10;
                }
                if (func_80037030_37C30() != 0) {
                    arg1->unk1C[0] = 0;
                    D_8010E4AA_2C591A_tick_tock_hop = 2;
                }
            }
            break;
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_8010908C_2C04FC_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    omObjData* temp_s1 = arg0->unk00;
    f32 var_f2;
    f32 var_f2_2;
    f32 temp_fv0;
    s16 temp_a1;

    if (arg1->unk04 == 0) {
        if (D_8010E6E0_2C5B50_tick_tock_hop->unk0C == 0.0f) {
            if (D_8010E6E0_2C5B50_tick_tock_hop->unk08 < 0.0f) {
                var_f2 = 1.0f;
            } else {
                var_f2 = -1.0f;
            }
        } else {
            if (D_8010E6E0_2C5B50_tick_tock_hop->unk0C < 0.0f) {
                var_f2 = -1.0f;
            } else {
                var_f2 = 1.0f;
            }
        }
        arg1->unk2C = D_8010E6E0_2C5B50_tick_tock_hop->unk00 + var_f2 * 90.0f;
        while (arg1->unk2C < 0.0f) {
            arg1->unk2C += 360.0f;
        }
        while (arg1->unk2C > 360.0f) {
            arg1->unk2C -= 360.0f;
        }
        arg1->unk30 = arg1->unk34 = HuMathSin(45.0f) * 60.000004f;
        arg1->unk1C[0] = 0;
        temp_a1 = D_8010E6E8_2C5B58_tick_tock_hop[temp_s1->work[0]];
        func_8004AC98_4B898(GwPlayer[temp_a1].chr + 0x287, temp_a1);
        func_8004AC98_4B898(0x4BE, temp_s1->work[0]);
        arg1->unk04 = 1;
    }
    temp_s1->trans.y += arg1->unk30;
    arg1->unk30 = arg1->unk34 - arg1->unk1C[0] * 2.45f;
    arg1->unk1C[0]++;
    temp_s1->trans.x += HuMathSin(arg1->unk2C) * 20.0f * 5.0f * 0.25f;
    temp_s1->trans.z += HuMathCos(arg1->unk2C) * 20.0f * 5.0f * 0.25f;
    temp_fv0 = temp_s1->trans.y;
    var_f2_2 = 300.0f;
    var_f2_2 = 1.0f - temp_fv0 / var_f2_2;
    if (var_f2_2 > 1.0f) {
        var_f2_2 = 1.0f;
    } else if (var_f2_2 < 0.5f) {
        var_f2_2 = 0.5f;
    }
    Hu3DModelScaleSet(temp_s1->model[1], var_f2_2, var_f2_2, var_f2_2);
    HmfModelData[temp_s1->model[1]].unk1C = temp_s1->trans.x;
    HmfModelData[temp_s1->model[1]].unk24 = temp_s1->trans.z;
    if (temp_s1->trans.y < 10.0f) {
        arg1->unk1C[0] = 0;
        temp_s1->trans.y = 10.0f;
        func_8001C258_1CE58(temp_s1->model[0], 4, 4);
        func_8001C258_1CE58(temp_s1->model[1], 4, 4);
        func_80109CC0_2C1130_tick_tock_hop(temp_s1->work[1], arg1);
    }
}

void func_8010942C_2C089C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s0 = arg1->unk3C;
    omObjData* temp_s1 = arg0->unk00;
    HmfModelData_Struct* temp_v1 = &HmfModelData[temp_s1->model[0]];
    s16 temp_a2;

    if (D_800CCF58_CDB58[temp_v1->unk02].unk02 - 1 <= temp_v1->unk40) {
        temp_s0->unk08 = 1;
    }
    if (temp_s0->unk08 == 0) {
        return;
    }
    func_800E5690_B8210_name_82(temp_s1, temp_s0->unk0A);
    if (temp_s0->unk0A == 0xD) {
        temp_a2 = D_8010E6E8_2C5B58_tick_tock_hop[temp_s1->work[0]];
        func_80045F1C_46B1C(D_800A178C[GwPlayer[temp_a2].chr][0] | 0x30, -1, temp_a2);
    }
    temp_s0->unk08 = 0;
    if (temp_s0->unk0C != -1) {
        temp_s0->unk0A = temp_s0->unk0C;
        temp_s0->unk0C = -1;
    }
}

void func_8010955C_2C09CC_tick_tock_hop(D_8010E6E4_2C5B54_Struct* arg0, s32 arg1, s32 arg2) {
    arg0->unk08 = arg2;
    arg0->unk0A = arg1;
}

void func_80109568_2C09D8_tick_tock_hop(D_8010E6E4_2C5B54_Struct* arg0, s32 arg1) {
    arg0->unk0C = arg1;
}

void func_80109570_2C09E0_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_t0 = arg1->unk3C;
    omObjData* var_t1 = arg0->unk00;
    D_8010E700_2C5B70_Unk60_Struct sp10 = { {
        {  90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 100.0f },
        { -90.0f, 0.0f, 400.0f },
        {  90.0f, 0.0f, 400.0f }
    } };

    switch (GwPlayer[D_8010E6E8_2C5B58_tick_tock_hop[var_t1->work[0]]].cpu_difficulty) {
        case 0:
            temp_t0->unk4C = 4;
            temp_t0->unk4E = 0;
            temp_t0->unk50 = 10;
            break;
        case 1:
            temp_t0->unk4C = 3;
            temp_t0->unk4E = 2;
            temp_t0->unk50 = 20;
            break;
        case 2:
            temp_t0->unk4C = 1;
            temp_t0->unk4E = 10;
            temp_t0->unk50 = 30;
            break;
        case 3:
            temp_t0->unk4C = 0;
            temp_t0->unk4E = 99;
            temp_t0->unk50 = 40;
            break;
    }
    func_8010D568_2C49D8_tick_tock_hop(D_8010E6E0_2C5B50_tick_tock_hop->unk1A, &sp10, 0.0f);
    arg1->unk40 = func_80109700_2C0B70_tick_tock_hop;
}

void func_801096B0_2C0B20_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_a0 = arg1->unk3C;

    if (temp_a0->unk24 != 99) {
        D_800CDA7C_CE67C[temp_a0->unk00] = 0;
        D_800CBB6E_CC76E[temp_a0->unk00] = 0;
        D_800D20A1_D2CA1[temp_a0->unk00] = 0;
    }
}

void func_80109700_2C0B70_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E6E4_2C5B54_Struct* temp_s3 = arg1->unk3C;

    temp_s3->unk24 = 99;
    D_800CDA7C_CE67C[temp_s3->unk00] = 0;
    D_800CBB6E_CC76E[temp_s3->unk00] = 0;
    D_800D20A1_D2CA1[temp_s3->unk00] = 0;
    if (temp_s3->unk04 & 0x20) {
        return;
    }
    if (arg1->unk0C == 0) {
        if (temp_s3->unk44->unk00 != 0) {
            if (D_8010E6E0_2C5B50_tick_tock_hop->unk1C > temp_s3->unk50 && rand16() % 6 == 0) {
                temp_s3->unk04 |= 0x20;
            }
            if (arg1->unk0D == 0) {
                arg1->unk0C = 1;
                arg1->unk0D = 1;
            }
        } else {
            arg1->unk0D = 0;
        }
    }
    if (arg1->unk0C == 1) {
        arg1->unk1C[0]++;
        if (arg1->unk1C[0] > rand16() % (temp_s3->unk4C + 1)) {
            arg1->unk1C[0] = 0;
            arg1->unk0C = 2;
            if (rand16() % (temp_s3->unk4E + 1) != 0
                && ABS(D_8010E6E0_2C5B50_tick_tock_hop->unk08 - D_8010E6E0_2C5B50_tick_tock_hop->unk0C) > 2.0f)
            {
                arg1->unk1C[1] = 1;
            } else {
                arg1->unk1C[1] = 6;
            }
        }
    }
    if (arg1->unk0C == 2) {
        arg1->unk1C[0]++;
        if (arg1->unk1C[0] <= arg1->unk1C[1]) {
            D_800CDA7C_CE67C[temp_s3->unk00] = 0x8000;
        } else {
            arg1->unk1C[0] = 0;
            arg1->unk0C = 0;
        }
    }
}
