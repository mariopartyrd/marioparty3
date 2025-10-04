#include "common.h"

void func_80105D9C_4DEF5C_inst(omObjData*);      /* extern */
void func_801061EC_4DF3AC_inst(void);                   /* extern */
void func_80106310_4DF4D0_inst(omObjData*);      /* extern */
void func_80106388_4DF548_inst(void);                   /* extern */
void func_8010674C_4DF90C_inst(omObjData*);      /* extern */
void func_801067CC_4DF98C_inst(void);                   /* extern */
void func_80106850_4DFA10_inst(Vec*, Vec*);             /* extern */
void func_80106898_4DFA58_inst(void);                   /* extern */
void func_80106EB4_4E0074_inst(void);                   /* extern */
void func_80107308_4E04C8_inst(void);                   /* extern */
void func_80107470_4E0630_inst(void);                /* extern */
void func_80108350_4E1510_inst(void);                /* extern */
void func_801094B0_4E2670_inst(void);                /* extern */
void func_80109A90_4E2C50_inst(void);                /* extern */
void func_8010A1D0_4E3390_inst(void);                /* extern */
void func_8010B990_4E4B50_inst(void);                /* extern */

extern s8 D_8010D400_4E65C0_inst[7];
extern s8 D_8010D407_4E65C7_inst;
extern s8 D_8010D408_4E65C8_inst;
extern s8 D_8010D40A_4E65CA_inst;
extern s8 D_8010D40B_4E65CB_inst;
extern s8 D_8010D411_4E65D1_inst;
extern Vec D_8010D45C_4E661C_inst;
extern Vec D_8010D48C_4E664C_inst;


void func_801059A0_4DEB60_inst(void) {
    void (*procFunc)(void) = NULL;
    s16 var_a1 = 0;
    s16 i;
    s16 j;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MB_MAX_PLAYERS; j++) {
            if (i != GwPlayer[j].group) {
                continue;
            }
            D_8010D400_4E65C0_inst[var_a1] = j;
            var_a1++;

            if (var_a1 >= 4) {
                break;
            }
        }
        if (var_a1 >= 4) {
            break;
        }
    }
    D_8010D40B_4E65CB_inst = GwSystem.minigame_index - 1;
    D_8010D40A_4E65CA_inst = D_800A6D44_A7944[D_8010D40B_4E65CB_inst].minigameType;
    
    if (_CheckFlag(0xF) != 0) {
        D_8010D407_4E65C7_inst = 1;
        D_8010D408_4E65C8_inst = 1;
    } else {
        D_8010D407_4E65C7_inst = 0;
        if ((GWMgUnlockCheck(D_8010D40B_4E65CB_inst)) != 0) {
            D_8010D408_4E65C8_inst = 1;
        }        
    }

    GWMgUnlockSet(-1);
    _ClearFlag(0xF);
    func_80106EB4_4E0074_inst();
    func_80106898_4DFA58_inst();
    func_80107308_4E04C8_inst();
    
    if ((GwSystem.show_minigame_explanations == 1) || (D_8010D40A_4E65CA_inst == 6)) {
        func_801061EC_4DF3AC_inst();
        return;
    }
    
    Hu3DAnimInit(1);
    omInitObjMan(0x1E, 0x1E);
    func_8005A6B0_5B2B0();
    func_8000B5F0_C1F0(1);
    ScissorSet(0U, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0U, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 15.0f, 500.0f, 8000.0f);
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, func_8010674C_4DF90C_inst), 0xA0U);
    func_800142A0_14EA0(0x28);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    omAddPrcObj(func_80107470_4E0630_inst, 0x1001U, 0x1000, 0);
    omAddPrcObj(func_8010B990_4E4B50_inst, 0x1001U, 0x1000, 0);
    omAddPrcObj(func_8010A1D0_4E3390_inst, 0x1001U, 0x1000, 0);
    
    switch (D_8010D40A_4E65CA_inst) {
    case 5:
        procFunc = func_801094B0_4E2670_inst;
        D_8010D411_4E65D1_inst = 1;
        break;
    case 4:
        if (omovlhisidx <= 0) {
            break;
        }
        if (GwSystem.playMode & 2) {
            procFunc = func_80108350_4E1510_inst;
            D_8010D411_4E65D1_inst = 0;
            break;
        }
    case 3:
        procFunc = func_80109A90_4E2C50_inst;
        D_8010D411_4E65D1_inst = 2;
        break;
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
    default:
        procFunc = func_80108350_4E1510_inst;
        D_8010D411_4E65D1_inst = 0;
        break;
    }

    omAddPrcObj(procFunc, 0x1001U, 0x800, 0);
    omAddObj(0, 0, 0, -1, func_80105D9C_4DEF5C_inst);
    omAddObj(0, 0, 0, -1, func_80106310_4DF4D0_inst);
    func_80106388_4DF548_inst();
    func_80106850_4DFA10_inst(&D_8010D45C_4E661C_inst, &D_8010D48C_4E664C_inst);
    func_801067CC_4DF98C_inst();
    WipeCreateIn(0xFF, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80105D9C_4DEF5C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801061EC_4DF3AC_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106310_4DF4D0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106388_4DF548_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801063F4_4DF5B4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D658_4E6818_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106418_4DF5D8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010674C_4DF90C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801067CC_4DF98C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106850_4DFA10_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106898_4DFA58_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D6B0_4E6870_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D6D8_4E6898_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D6E4_4E68A4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D70C_4E68CC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D718_4E68D8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D724_4E68E4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80106EB4_4E0074_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107308_4E04C8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107470_4E0630_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107938_4E0AF8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801079CC_4E0B8C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107A24_4E0BE4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107BE4_4E0DA4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D770_4E6930_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D784_4E6944_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D78C_4E694C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D794_4E6954_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D79C_4E695C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7A4_4E6964_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7AC_4E696C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7B0_4E6970_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7C4_4E6984_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7CC_4E698C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7D4_4E6994_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7DC_4E699C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7E4_4E69A4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D7EC_4E69AC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D800_4E69C0_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D808_4E69C8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D810_4E69D0_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D818_4E69D8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D820_4E69E0_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D828_4E69E8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D83C_4E69FC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D844_4E6A04_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D84C_4E6A0C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D854_4E6A14_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D85C_4E6A1C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D864_4E6A24_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D870_4E6A30_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D878_4E6A38_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D880_4E6A40_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D888_4E6A48_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D890_4E6A50_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D89C_4E6A5C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8B4_4E6A74_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8BC_4E6A7C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8C4_4E6A84_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8CC_4E6A8C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8D4_4E6A94_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8DC_4E6A9C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8E4_4E6AA4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8EC_4E6AAC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8F4_4E6AB4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D8FC_4E6ABC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D904_4E6AC4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D90C_4E6ACC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D910_4E6AD0_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D954_4E6B14_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D978_4E6B38_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D980_4E6B40_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107BF8_4E0DB8_inst);

void func_80107E18_4E0FD8_inst(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107E20_4E0FE0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107E98_4E1058_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107EE0_4E10A0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107F18_4E10D8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80107F98_4E1158_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801080A8_4E1268_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801080FC_4E12BC_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010815C_4E131C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108350_4E1510_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010872C_4E18EC_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108808_4E19C8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108870_4E1A30_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108954_4E1B14_inst);

void func_80108A10_4E1BD0_inst(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108A18_4E1BD8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80108AF0_4E1CB0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801094B0_4E2670_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801097DC_4E299C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010986C_4E2A2C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801098D8_4E2A98_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_801099C0_4E2B80_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80109A84_4E2C44_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80109A90_4E2C50_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80109E94_4E3054_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_80109F50_4E3110_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010A000_4E31C0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010A0E8_4E32A8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010A1BC_4E337C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010A1D0_4E3390_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010A750_4E3910_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010AC04_4E3DC4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010AC30_4E3DF0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010AD78_4E3F38_inst);

void func_8010B038_4E41F8_inst(void) {
}

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D9C8_4E6B88_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010D9E8_4E6BA8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA24_4E6BE4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA34_4E6BF4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA44_4E6C04_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA54_4E6C14_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA64_4E6C24_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA74_4E6C34_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA84_4E6C44_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DA94_4E6C54_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DAA4_4E6C64_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DAB0_4E6C70_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DABC_4E6C7C_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DAC8_4E6C88_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B040_4E4200_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B0FC_4E42BC_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B10C_4E42CC_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B118_4E42D8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B124_4E42E4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B2A4_4E4464_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B628_4E47E8_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010B990_4E4B50_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010BE28_4E4FE8_inst);

void func_8010BE70_4E5030_inst(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010BE78_4E5038_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DAF8_4E6CB8_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DB04_4E6CC4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DB10_4E6CD0_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DB1C_4E6CDC_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DB24_4E6CE4_inst);

INCLUDE_RODATA("asm/nonmatchings/overlays/inst/4DEB60", D_8010DB30_4E6CF0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C124_4E52E4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C55C_4E571C_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C5C4_4E5784_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C848_4E5A08_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C890_4E5A50_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C8B4_4E5A74_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C8D0_4E5A90_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010C8E0_4E5AA0_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CA74_4E5C34_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CBB8_4E5D78_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CC14_4E5DD4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CDE4_4E5FA4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CED0_4E6090_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CF14_4E60D4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CF98_4E6158_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010CFF4_4E61B4_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010D044_4E6204_inst);

INCLUDE_ASM("asm/nonmatchings/overlays/inst/4DEB60", func_8010D1D4_4E6394_inst);
