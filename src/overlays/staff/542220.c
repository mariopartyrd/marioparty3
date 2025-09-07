#include "common.h"
#include "../ovl_81_name/ovl_81.h"

typedef struct UnkStaff {
    char unk_00[0x18];
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    s16 unk_1E;
} UnkStaff;

typedef struct UnkStaff_1 {
/* 0x00 */ char unk_00[0x18];
/* 0x18 */ s16 unk_18;
/* 0x1A */ s16 unk_1A;
/* 0x1C */ s16 unk_1C;
/* 0x1E */ s16 unk_1E;
/* 0x20 */ char unk_20[8];
/* 0x28 */ s16 unk_28;
/* 0x2A */ char unk_2A[2];
} UnkStaff_1;

void func_80105E6C_5426EC_staff(void*, s16*, s32);
void func_8010C680_548F00_staff(s16*, s32*, f32*, void*);
void func_8010C8F4_549174_staff(UnkStaff_1*);
void func_8010CD74_5495F4_staff(UnkStaff_1*);
void func_8010CFD4_549854_staff(UnkStaff*);
extern f32 D_80110534_54CDB4_staff;
extern s8 D_80110538_54CDB8_staff;
extern char D_80110FF4_54D874_staff[];  //unk type
extern Vec D_80111534_54DDB4_staff;
extern Vec D_80111540_54DDC0_staff;
extern f32 D_80111560_54DDE0_staff;
extern f32 D_80111564_54DDE4_staff;

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801059A0_542220_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80105BD4_542454_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80105CB4_542534_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80105DB8_542638_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80105E6C_5426EC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80105F48_5427C8_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010601C_54289C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80106044_5428C4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010609C_54291C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010615C_5429DC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80106720_542FA0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010674C_542FCC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80106C50_5434D0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80106E20_5436A0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801073EC_543C6C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107508_543D88_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107740_543FC0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107A9C_54431C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107B1C_54439C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107BA0_544420_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107DBC_54463C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80107EB8_544738_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801085F0_544E70_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801088F4_545174_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010919C_545A1C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801091CC_545A4C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80109264_545AE4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_801095E4_545E64_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010992C_5461AC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010998C_54620C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80109D08_546588_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80109D74_5465F4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_80109F34_5467B4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010A848_5470C8_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B1E0_547A60_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B430_547CB0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B4B4_547D34_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B514_547D94_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B794_548014_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B8C0_548140_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010B9BC_54823C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010BA30_5482B0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010BE20_5486A0_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_8011133C_54DBBC_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111348_54DBC8_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111354_54DBD4_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111360_54DBE0_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_8011136C_54DBEC_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111378_54DBF8_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111384_54DC04_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111390_54DC10_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_8011139C_54DC1C_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113A8_54DC28_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113B4_54DC34_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113C0_54DC40_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113CC_54DC4C_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113D8_54DC58_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113E4_54DC64_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_801113F0_54DC70_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010BF84_548804_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010C680_548F00_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010C8F4_549174_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010CD74_5495F4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010CFD4_549854_staff);

void func_8010D1E8_549A68_staff(void) {
    s16 sp10[3][2];
    UnkStaff sp20[8];
    UnkStaff_1 sp120[3];
    s16 sp1A8;
    s32 sp1AC;
    f32 sp1B0;
    s16 var_v0;
    s16* temp_s2;
    s16 var_s0;
    s32 i;
    UnkStaff_1* temp;
    UnkStaff* temp2;
    s16* temp3;

    temp_s2 = HuPrcCurrentGet()->user_data;
    HmfLightDirSet(1, 0.0f, 0.0f, 100.0f);
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    MBDBackLoad(0x20);
    func_800E8180_CFF50_name_81(1000.0f, 10000.0f);
    func_800E8110_CFEE0_name_81();
    D_80110538_54CDB8_staff = 1;
    D_80111540_54DDC0_staff.x = 350.0f;
    D_80111540_54DDC0_staff.y = 190.0f;
    D_80111540_54DDC0_staff.z = 3770.0f;
    D_80111534_54DDB4_staff.x = -1000.0f;
    D_80111534_54DDB4_staff.y = 130.0f;
    D_80111534_54DDB4_staff.z = 450.0f;
    D_80110534_54CDB4_staff = 40.0f;
    Hu3DCamSetPerspective(0, 40.0f, D_80111564_54DDE4_staff, D_80111560_54DDE0_staff);
    func_80105E6C_5426EC_staff(D_80110FF4_54D874_staff, &sp10[0][0], 3);
    func_8010CFD4_549854_staff(sp20);
    func_8010CD74_5495F4_staff(sp120);
    *temp_s2 = 0;
    sp1A8 = 0;
    sp1B0 = 90.0f;
    sp1AC = 0;
    for (var_s0 = 0; var_s0 >= 0;) {
        if (var_s0 != *temp_s2) {
            if (*temp_s2 == -1) {
                var_s0 = -1;
            } else {
                var_s0 = *temp_s2;
                func_8010C8F4_549174_staff(sp120);
                func_8010C680_548F00_staff(&sp1A8, &sp1AC, &sp1B0, &sp20[3]);
                HuPrcVSleep();
            }
        } else {
            func_8010C8F4_549174_staff(sp120);
            func_8010C680_548F00_staff(&sp1A8, &sp1AC, &sp1B0, &sp20[3]);
            HuPrcVSleep();
        }
    }

    //TODO: fix typing of temp3 or sp10
    for (temp3 = sp10[0], i = 0; i < 3; i++, temp3 += 2) {
        func_8001ACDC_1B8DC(*temp3); //?
    }
    for (temp2 = sp20, i = 0; i < 8; i++, temp2++) {
        func_8001ACDC_1B8DC(temp2->unk_18);
        func_8001ACDC_1B8DC(temp2->unk_1A);
        func_80033354_33F54(temp2->unk_1C);
        if (temp2->unk_1E >= 0) {
            func_8001ACDC_1B8DC(temp2->unk_1E);
        }
    }

    for (temp = sp120, i = 0; i < 3; i++, temp++) {
        func_8001ACDC_1B8DC(temp->unk_28);
    }

    MBDBackKill();
    MBDBackClose();
    *temp_s2 = 0;
    while (1) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010D450_549CD0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010D580_549E00_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010D998_54A218_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DE50_54A6D0_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DEDC_54A75C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DEE4_54A764_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DEF4_54A774_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DF04_54A784_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DF0C_54A78C_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DF24_54A7A4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DF2C_54A7AC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010DF34_54A7B4_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010F04C_54B8CC_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010F3E4_54BC64_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010F4C4_54BD44_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010F9D4_54C254_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010FB28_54C3A8_staff);

INCLUDE_ASM("asm/nonmatchings/overlays/staff/542220", func_8010FB88_54C408_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111430_54DCB0_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_8011143C_54DCBC_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111448_54DCC8_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111454_54DCD4_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111460_54DCE0_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_8011146C_54DCEC_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111478_54DCF8_staff);

INCLUDE_RODATA("asm/nonmatchings/overlays/staff/542220", D_80111484_54DD04_staff);
