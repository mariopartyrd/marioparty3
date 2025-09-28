#include "common.h"
#include "../ovl_81_name/ovl_81.h"

void func_8010BA98_3BF768_boardresult(void);
void func_8010BBF0_3BF8C0_boardresult(omObjData*);
void func_8010BC3C_3BF90C_boardresult(void);
void func_8010BCA4_3BF974_boardresult(void);
extern s32 D_8010E72C_3C23FC_boardresult[];
extern u32 D_8010E738_3C2408_boardresult[];
extern s32 D_8010E73C_3C240C_boardresult[];
extern s32* D_8010E88C_3C255C_boardresult[];
extern s32* D_8010E8AC_3C257C_boardresult[];
extern u8 D_8010EAF0_3C27C0_boardresult;

void func_801059A0_3B9670_boardresult(void) {
    s32 i;
    u32 j;

    D_8010EAF0_3C27C0_boardresult = GwSystem.current_board_index;
    omInitObjMan(0x32, 0x32);
    func_8010BCA4_3BF974_boardresult();
    func_8010BC3C_3BF90C_boardresult();
    func_800D87DC_C05AC_name_81(700.0f);
    func_800D85A8_C0378_name_81(1.6f);
    func_8005A6B0_5B2B0();
    omAddPrcObj(func_8010BA98_3BF768_boardresult, 0x300U, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_8010BBF0_3BF8C0_boardresult);

    for (i = 1; i < 8; i++) {
        for (j = 0; j < D_8010E72C_3C23FC_boardresult[0]; j++) {
            D_8010E88C_3C255C_boardresult[i][j+1] = func_80017BB8_187B8(i, D_8010E72C_3C23FC_boardresult[j+1]);
        }              
    }

    for (i = 1; i < 8; i++) {
        for (j = 0; j < D_8010E738_3C2408_boardresult[0]; j++) {
            D_8010E8AC_3C257C_boardresult[i][j+1] = func_80017BB8_187B8(i, D_8010E738_3C2408_boardresult[j+1]);
        }              
    }

    func_800EF3EC_D71BC_name_81(4);
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80105B68_3B9838_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80105BD8_3B98A8_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010685C_3BA52C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106968_3BA638_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106A38_3BA708_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106A80_3BA750_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106CA8_3BA978_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106DA4_3BAA74_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80106F54_3BAC24_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_801070F8_3BADC8_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80107598_3BB268_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_801076A0_3BB370_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80107AB4_3BB784_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80107B50_3BB820_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80107EE8_3BBBB8_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80107F84_3BBC54_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80108378_3BC048_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80109128_3BCDF8_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80109320_3BCFF0_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010935C_3BD02C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_801094A8_3BD178_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EA60_3C2730_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EA70_3C2740_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EA80_3C2750_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EA90_3C2760_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EAB0_3C2780_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_80109754_3BD424_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BA98_3BF768_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BAD8_3BF7A8_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BBF0_3BF8C0_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BC3C_3BF90C_boardresult);

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BC70_3BF940_boardresult);

void func_8010BCA4_3BF974_boardresult(void) {
    Hu3DCamInit(1);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    MBDBackLoad(0);
    func_800E8180_CFF50_name_81(1000.0f, 10000.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/boardresult/3B9670", func_8010BD04_3BF9D4_boardresult);

INCLUDE_RODATA("asm/nonmatchings/overlays/boardresult/3B9670", D_8010EADC_3C27AC_boardresult);
