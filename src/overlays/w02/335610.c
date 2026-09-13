#include "common.h"
#include "../ovl_80_shared_board/F5E80.h"
#include "../ovl_80_shared_board/101840.h"
#include "../ovl_80_shared_board/113750.h"
#include "../ovl_80_shared_board/ECA50.h"
#include "../ovl_80_shared_board/FA250.h"
#include "../ovl_80_shared_board/10C230.h"

void func_80105CA4_w02(void);
void func_80106094_w02(void*);
extern s32 D_8011C6B0_w02[];
extern s32 D_8011C6CC_w02[];
extern Object* D_8011EBD8_w02[];
extern Process* D_8011EC18_w02;
extern Object* D_8011EC1C_w02;
extern s16 D_8011C6A0_w02[]; //mb2ev_StarGuideMasu

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801059D0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801059F8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80105B00_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80105B8C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80105C30_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80105CA4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106094_w02);

#define GET_STAR_MODEL() D_8011EBD8_w02[GwSystem.star_spawn_indices[GwSystem.current_star_spawn]]
//MB3Ev_StarMapView
void func_80106120_w02(void) {
    UnkMBGuideData *guide;
    Process *proc;
    SpaceData *space;
    s32 face;
    s32 mesNum;
    GW_SYSTEM* system = &GwSystem;

    D_800A12D4_main = 0;
    guide = MBGuideCreate(0, 0);
    HuAudSeqPlay(0x12);
    MBGuideFaceCreate(guide->obj, 2, 0xF, D_8011C6B0_w02[0]);
    func_800FFF44_shared_board();
    MBModelDispOff(GET_STAR_MODEL());
    WipeCreateIn(2, 0x10);
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }

    func_800E6FCC_shared_board();
    func_800E9730_shared_board(3.0f);
    func_80106094_w02(guide);

    if ((system->current_star_spawn == 0) && (GWBoardFlagCheck(4) == 0)) {
        if (system->current_board_index == 2) {
            mesNum = 0x5E09;
        } else {
            mesNum = 0x5E00;
        }
    } else {
        if (system->current_board_index == 2) {
            mesNum = 0x5E09;
        } else {
            mesNum = 0x5E01;
        }
    }
    func_8005B43C_main(guide->amount, mesNum, -1, -1);
    func_80060C14_main(guide->amount, 1);
    HuAudFXPlay(0x2A7);
    func_800EE2C0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_main(guide->amount, 1);
    func_8001FDE8_main(guide->obj->omObj1->model[0]);

    if ((system->current_board_index != SPINY_DESERT) || (rand8() & 1)) {
        space = MBMasuGet(D_8011C6A0_w02[system->star_spawn_indices[system->current_star_spawn]]);
    }
    MBCameraPos3DSet(&space->coords);
    MBCameraSpeedSet(5.0f);
    HuPrcSleep(5);
    while (MBCameraStopCheck() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);

    face = MBRand(7.0f);
    MBGuideFaceSet(guide->obj, D_8011C6B0_w02[face]);
    MBMotionSet(guide->obj, -1, 2);

    if (system->current_board_index != 2) {
        proc = omAddPrcObj(func_80105CA4_w02, 0x4800, 0, 0);
        D_8011EC18_w02 = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_8011EC18_w02 = NULL;
    }

    func_8005B43C_main(guide->amount, D_8011C6CC_w02[face], -1, -1);
    func_80060C14_main(guide->amount, 1);
    func_800EE2C0_shared_board(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_80060EA8_main(guide->amount, 1);

    HuAudSeqFadeOut(0x5A);
    HuPrcSleep(30);
    WipeCreateOut(2, 0x10);
    HuPrcSleep(0x11);
    D_800A12D4_main = 1;
    func_80100130_shared_board();
    func_80046558_main(D_8011EC1C_w02->omObj1->model[0]);
    MBModelKill(D_8011EC1C_w02);
    MBModelDispOn(GET_STAR_MODEL());
    MBGuideKill(guide);
    MBExit();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}


INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801064DC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106A3C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106AB0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106B38_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106B94_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106C64_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106CC4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80106F58_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107170_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801072A0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107438_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107704_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107724_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107744_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107780_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107830_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107B4C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107BD0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107BFC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107D24_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107D88_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107E34_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107F54_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80107FB0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801080AC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108218_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108280_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801083EC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010844C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801084A8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108570_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108620_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010865C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801086DC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108754_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801087F8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108870_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801088EC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801089C0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108A20_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108A58_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108A8C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108AC4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108B6C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108BA4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108C4C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108C7C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108CC0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108CF0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108D34_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108D64_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108DA8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108DD8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108E1C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108E4C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108F8C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80108FEC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010904C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801090AC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010910C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010916C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801091CC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010922C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010928C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801092EC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010934C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801093AC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010940C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010946C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801094CC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010952C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010958C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801095EC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010964C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010985C_w02);

void func_80109C80_w02(void) {
}

void func_80109C88_w02(void) {
}

void func_80109C90_w02(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80109C98_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80109F1C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80109FD8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010A018_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010A3C4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010AF00_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010AF88_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010AFF0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010B1C8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010C47C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010C51C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010C5BC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010CA04_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010CA28_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010D854_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010D9A8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010D9E4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010EBB8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010EBD4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010EBF0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010ED4C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010EE64_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F22C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F298_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F458_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F6BC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F78C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010F9BC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010FB8C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8010FCFC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80110048_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011020C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801104A4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80110730_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80110970_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80110B80_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80110E40_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801111E0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80111BDC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112124_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112340_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112734_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801127F0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112944_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112980_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112B10_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80112ECC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80113164_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80113270_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011344C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801140F8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801141B8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801146E8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80114FF4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011512C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011529C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80115464_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801156E8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80115FEC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801161E4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011625C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801162C0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011646C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011656C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80116608_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80116708_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80116914_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80116A74_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80116AC4_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011703C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011720C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80117344_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801177C8_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80117E70_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80118480_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119244_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119360_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801193C0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801193D0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801193DC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119408_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119438_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011946C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119680_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_801199EC_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119D84_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_80119DB0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011B038_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011B8A0_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011B934_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011B988_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011BA58_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011BB30_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011BB84_w02);

INCLUDE_RODATA("asm/nonmatchings/overlays/w02/335610", D_8011EB68_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011BC6C_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011C274_w02);

INCLUDE_ASM("asm/nonmatchings/overlays/w02/335610", func_8011C5D8_w02);
