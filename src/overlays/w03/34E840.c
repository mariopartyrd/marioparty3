#include "SpinyDesert.h"
#include "common.h"
#include "game/object.h"
#include "../ovl_80_shared_board/ovl_80.h"

void func_80105DB0_34EC20_w03(void);
void func_801061A0_34F010_w03(UnkMBGuideData*);
extern s16 D_8011C150_364FC0_w03[];
extern Object* D_8011EAC8_367938_w03[];
extern Process* D_8011EB08_367978_w03;
extern Object* D_8011EB0C_36797C_w03;

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801059D0_34E840_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801059F8_34E868_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80105B44_34E9B4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80105C50_34EAC0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80105D20_34EB90_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80105DB0_34EC20_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801061A0_34F010_w03);

// Star tour.
void func_8010622C_34F09C_w03(void) {
    UnkMBGuideData *guide;
    Process *proc;
    SpaceData *first;
    SpaceData *second;
    SpaceData *temp;
    s32 mesNum;
    GW_SYSTEM* system = &GwSystem;

    D_800A12D4_A1ED4 = 0;
    guide = MBGuideCreate(0, 0);
    HuAudSeqPlay(0x12);
    MBGuideFaceCreate(guide->obj, 2, 0xF, 0xA007E);
    func_800FFF44_113B64_shared_board();
    MBModelDispOff(D_8011EAC8_367938_w03[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]);
    MBModelDispOff(D_8011EAC8_367938_w03[GwSystem.boardData.halfWordBytes[0]]);
    WipeCreateIn(2, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    func_800E6FCC_FABEC_shared_board();
    func_800E9730_FD350_shared_board(3.0f);
    func_801061A0_34F010_w03(guide);

    first = MBMasuGet(D_8011C150_364FC0_w03[system->star_spawn_indices[system->current_star_spawn]]);
    second = MBMasuGet(D_8011C150_364FC0_w03[GwSystem.boardData.halfWordBytes[0]]);

    if (MBRandCheck100(50) != 0) {
        temp = first;
        first = second;
        second = temp;
    }
    
    if ((system->current_star_spawn == 0) && (GWBoardFlagCheck(4) == 0)) {
        mesNum = 0x5E09;
    } else {
        mesNum = 0x5E0A;
    }

    
    func_8005B43C_5C03C(guide->amount, mesNum, -1, -1);
    func_80060C14_61814(guide->amount, 1);
    HuAudFXPlay(0x2A7);
    temp = first;
    func_800EE2C0_101EE0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(guide->amount, 1);
    func_8001FDE8_209E8(guide->obj->omObj1->model[0]);

    MBCameraPos3DSet(&temp->coords);
    MBCameraSpeedSet(5.0f);
    HuPrcSleep(5);
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);

    MBMotionSet(guide->obj, -1, 2);
    proc = omAddPrcObj(func_80105DB0_34EC20_w03, 0x4800, 0, 0);
    D_8011EB08_367978_w03 = proc;
    proc->user_data = temp;
    HuPrcSleep(30);
    D_800CC69C_CD29C[guide->amount].unk20 = 1;
    HuPrcVSleep();
    func_80060C14_61814(guide->amount, 1);
    func_800EE2C0_101EE0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_61AA8(guide->amount, 1);

    while (D_8011EB08_367978_w03 != NULL) {
        HuPrcVSleep();
    }
    temp = second;
    MBCameraPos3DSet(&temp->coords);
    MBCameraSpeedSet(5.0f);
    HuPrcSleep(5);
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);

    proc = omAddPrcObj(func_80105DB0_34EC20_w03, 0x4800, 0, 0);
    D_8011EB08_367978_w03 = proc;
    proc->user_data = temp;
    HuPrcSleep(30);
    D_800CC69C_CD29C[guide->amount].unk20 = 1;
    HuPrcVSleep();
    func_80060C14_61814(guide->amount, 1);
    func_800EE2C0_101EE0_shared_board(guide->amount);
    func_80060EA8_61AA8(guide->amount, 1);

    HuAudSeqFadeOut(0x5A);
    HuPrcSleep(30);
    WipeCreateOut(2, 0x10);
    HuPrcSleep(0x11);
    D_800A12D4_A1ED4 = 1;
    func_80100130_113D50_shared_board();
    func_80046558_47158(D_8011EB0C_36797C_w03->omObj1->model[0]);
    MBModelKill(D_8011EB0C_36797C_w03);
    MBModelDispOn(D_8011EAC8_367938_w03[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]);
    MBModelDispOn(D_8011EAC8_367938_w03[GwSystem.boardData.halfWordBytes[0]]);
    MBGuideKill(guide);
    MBExit();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}


INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801066CC_34F53C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106C2C_34FA9C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106CA0_34FB10_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106D28_34FB98_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106D84_34FBF4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106E54_34FCC4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80106EB4_34FD24_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107148_34FFB8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107360_3501D0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107490_350300_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107628_350498_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801078F4_350764_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107914_350784_w03);

// entrypoint 0
INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107934_3507A4_w03);

// entrypoint 1
INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107970_3507E0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107A04_350874_w03);

// entrypoint 2
void func_80107CA4_350B14_w03() {
    HuAudSeqPlay(0x1A);
    D_800CE198_CED98 = 0x1A;
    func_800F8D6C_10C98C_shared_board(0x1A);
    Hu3DCamInit(2);
    func_80107A04_350874_w03();
    MBMasuEventTblAdd(&D_8011D1C4_366034_w03);
    MBMasuEventTblAdd(&D_8011D478_3662E8_w03);
    MBHatenaFuncSet(func_8011A704_363574_w03);
    MBMasuEventTblAdd(&D_8011D23C_3660AC_w03);
    MBMasuEventTblAdd(&D_8011D3D0_366240_w03);
    MBStart(0);
}

// entrypoint 3
INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107D28_350B98_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107D54_350BC4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107ECC_350D3C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107F30_350DA0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80107FF8_350E68_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108118_350F88_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108174_350FE4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108270_3510E0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801083DC_35124C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108444_3512B4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801085B0_351420_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108610_351480_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010866C_3514DC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108734_3515A4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801087E4_351654_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108820_351690_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801088A0_351710_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108918_351788_w03);

INCLUDE_RODATA("asm/nonmatchings/overlays/w03/34E840", D_8011E910_367780_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801089AC_35181C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108AB8_351928_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108ADC_35194C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108B98_351A08_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108C48_351AB8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108C80_351AF0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108CB8_351B28_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108CF0_351B60_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108DA0_351C10_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108DD8_351C48_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108E30_351CA0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108E88_351CF8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108EE0_351D50_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80108F38_351DA8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109268_3520D8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801092C8_352138_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109328_352198_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109388_3521F8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801093E8_352258_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109448_3522B8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801094A8_352318_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109508_352378_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109568_3523D8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801095C8_352438_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109628_352498_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109688_3524F8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801096E8_352558_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109748_3525B8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801097A8_352618_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109808_352678_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109868_3526D8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801098C8_352738_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109AD8_352948_w03);

void func_80109E90_352D00_w03(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109E98_352D08_w03);

void func_80109F3C_352DAC_w03(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80109F44_352DB4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010A1C8_353038_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010A284_3530F4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010A2C4_353134_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010A930_3537A0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010B46C_3542DC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010B4F4_354364_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010B55C_3543CC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010B734_3545A4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010C9EC_35585C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010CA8C_3558FC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010CB2C_35599C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010CF74_355DE4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010CF98_355E08_w03);

INCLUDE_RODATA("asm/nonmatchings/overlays/w03/34E840", D_8011E98C_3677FC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010DDC4_356C34_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010DF18_356D88_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010DF54_356DC4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F128_357F98_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F144_357FB4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F160_357FD0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F2BC_35812C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F3D4_358244_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F79C_35860C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F808_358678_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010F9C8_358838_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010FC2C_358A9C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010FCFC_358B6C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8010FF2C_358D9C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801100FC_358F6C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011026C_3590DC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801105B8_359428_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011077C_3595EC_w03);

INCLUDE_RODATA("asm/nonmatchings/overlays/w03/34E840", D_8011E998_367808_w03);

INCLUDE_RODATA("asm/nonmatchings/overlays/w03/34E840", D_8011E9F8_367868_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80110A14_359884_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80110CA0_359B10_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80110EE0_359D50_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801110F0_359F60_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801113B0_35A220_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80111750_35A5C0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011214C_35AFBC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80112694_35B504_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801128B0_35B720_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80112CA4_35BB14_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80112D60_35BBD0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80112EB4_35BD24_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80112EF0_35BD60_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80113080_35BEF0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011343C_35C2AC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801136D4_35C544_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801137E0_35C650_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801139BC_35C82C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80114668_35D4D8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80114728_35D598_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80114C58_35DAC8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80115564_35E3D4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011569C_35E50C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011580C_35E67C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801159D4_35E844_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80115C58_35EAC8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011655C_35F3CC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116754_35F5C4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801167CC_35F63C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116830_35F6A0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801169DC_35F84C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116ADC_35F94C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116B78_35F9E8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116C78_35FAE8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116E84_35FCF4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80116FE4_35FE54_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80117034_35FEA4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801175AC_36041C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011777C_3605EC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801178B4_360724_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80117D38_360BA8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_801183E0_361250_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80118E3C_361CAC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80118F64_361DD4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011908C_361EFC_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80119120_361F90_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_80119290_362100_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011A2BC_36312C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011A338_3631A8_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011A550_3633C0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011A704_363574_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B1FC_36406C_w03);

// entrypoint 4
void func_8011B41C_36428C_w03() {
    Hu3DCamInit(2);
    CameraScissorSet(1, &D_8011D598_366408_w03);
    func_80107A04_350874_w03();
    MBStart(2);
    omAddPrcObj(func_8010622C_34F09C_w03, 0x1005, 0x1000, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B470_3642E0_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B51C_36438C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B5E0_364450_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B634_3644A4_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011B71C_36458C_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011BD24_364B94_w03);

INCLUDE_ASM("asm/nonmatchings/overlays/w03/34E840", func_8011C088_364EF8_w03);
