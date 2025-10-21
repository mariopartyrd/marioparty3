#include "common.h"
#include "../ovl_80_shared_board/ovl_80.h"

void func_801061F0_524820_opening(void);
void func_80110B90_52F1C0_opening(void);
void func_80110F48_52F578_opening(void);
void func_80112944_530F74_opening(void);
void opContErrorCreate(void);

extern Vec D_80114BB8_5331E8_opening;
extern Vec D_80114BC4_5331F4_opening;
extern RectF D_80114BD0_533200_opening;

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801059A0_523FD0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opObjectInit);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleObjectSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80105C2C_52425C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjectSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opEventInit);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEventCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80105F68_524598_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opBtnStartCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndReset);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801061F0_524820_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8010621C_52484C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opAnimIdGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opEspIdGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opAnimCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opAnimKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opEspCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opEspKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprBGCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprKillAll);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprDispOn);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprBGDispOn);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprBGDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprPosSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprPosGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprScaleSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprAlphaSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprAttrSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSprAttrReset);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106734_524D64_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106768_524D98_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801067D4_524E04_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelKillAll);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelIdGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionIdGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelRotSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelPosSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelScaleSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelPosGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelRotGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelScaleGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opModelDispOn);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionFlagSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionShiftSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106DD0_525400_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionSpeedSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionTimeSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionEndWait);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionEndCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107048_525678_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801070AC_5256DC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801070D8_525708_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107140_525770_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8010738C_5259BC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801074D8_525B08_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107640_525C70_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801077E8_525E18_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801078B4_525EE4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107980_525FB0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107A4C_52607C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107A90_5260C0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107B74_5261A4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107BD8_526208_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107C08_526238_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107C70_5262A0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107CA0_5262D0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107CD0_526300_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107D9C_5263CC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107DD8_526408_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E10_526440_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E2C_52645C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E80_5264B0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107EBC_5264EC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107EF4_526524_opening);

void opDemoEventSetup(void) {
    func_801061F0_524820_opening();
    func_80110F48_52F578_opening();
    CameraViewportSet(0, &D_80114BB8_5331E8_opening, &D_80114BC4_5331F4_opening);
    CameraScissorSet(0, &D_80114BD0_533200_opening);
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    func_80112944_530F74_opening();
    func_80110B90_52F1C0_opening();
    opContErrorCreate();
}

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80108118_526748_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114CE4_533314_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D84_5333B4_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D90_5333C0_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D9C_5333CC_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114DA8_5333D8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEvent);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEventKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110B90_52F1C0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110B9C_52F1CC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110C04_52F234_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110D8C_52F3BC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoCharCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoShadowCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoModelKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoSprKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110F48_52F578_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110FB0_52F5E0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111028_52F658_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011105C_52F68C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111090_52F6C0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801110AC_52F6DC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801110F0_52F720_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111164_52F794_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801111AC_52F7DC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011124C_52F87C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111490_52FAC0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111580_52FBB0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801117D4_52FE04_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111984_52FFB4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111B34_530164_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C08_530238_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C30_530260_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C88_5302B8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111DDC_53040C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111F58_530588_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112120_530750_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleSprMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112944_530F74_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjKillAll);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112A74_5310A4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112BA0_5311D0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112C8C_5312BC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112D30_531360_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoOutEffMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoOutEffCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoGuideInEffMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoGuideInEffCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoStarWaitMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoStarWaitCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801134FC_531B2C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011361C_531C4C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011373C_531D6C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801139B0_531FE0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80113AE8_532118_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80113E8C_5324BC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80114150_532780_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80114250_532880_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeDraw);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeColorSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeInMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeOutMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeInCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeOutCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeWhiteInCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeWhiteOutCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801149A4_532FD4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSleep);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorDispOn);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorKill);
