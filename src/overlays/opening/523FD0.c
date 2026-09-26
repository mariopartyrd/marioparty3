#include "common.h"
#include "../ovl_80_shared_board/FA250.h"

void func_801061F0_opening(void);
void func_80110B90_opening(void);
void func_80110F48_opening(void);
void func_80112944_opening(void);
void opContErrorCreate(void);

extern Vec D_80114BB8_opening;
extern Vec D_80114BC4_opening;
extern RectF D_80114BD0_opening;

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801059A0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opObjectInit);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleObjectSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80105C2C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjectSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opEventInit);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEventCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80105F68_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opBtnStartCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndReset);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEndGet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801061F0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8010621C_opening);

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

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106734_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106768_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801067D4_opening);

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

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80106DD0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionSpeedSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionTimeSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionEndWait);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionEndCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opMotionSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107048_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801070AC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801070D8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107140_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8010738C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801074D8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107640_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801077E8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801078B4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107980_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107A4C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107A90_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107B74_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107BD8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107C08_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107C70_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107CA0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107CD0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107D9C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107DD8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E10_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E2C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107E80_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107EBC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80107EF4_opening);

void opDemoEventSetup(void) {
    func_801061F0_opening();
    func_80110F48_opening();
    CameraViewportSet(0, &D_80114BB8_opening, &D_80114BC4_opening);
    CameraScissorSet(0, &D_80114BD0_opening);
    func_800E6630_shared_board((u32)hvq_data_ROM_START);
    func_80112944_opening();
    func_80110B90_opening();
    opContErrorCreate();
}

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80108118_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114CE4_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D84_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D90_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114D9C_opening);

INCLUDE_RODATA("asm/nonmatchings/overlays/opening/523FD0", D_80114DA8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEvent);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoEventKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110B90_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110B9C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110C04_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110D8C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoCharCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoShadowCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoModelKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoSprKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110F48_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80110FB0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111028_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011105C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111090_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801110AC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801110F0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111164_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801111AC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011124C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111490_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111580_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801117D4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111984_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111B34_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C08_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C30_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111C88_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111DDC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80111F58_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112120_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleSprMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opTitleKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112944_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjKillAll);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoObjCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112A74_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112BA0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112C8C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80112D30_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoOutEffMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoOutEffCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoGuideInEffMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoGuideInEffCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoStarWaitMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opDemoStarWaitCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801134FC_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011361C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_8011373C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801139B0_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80113AE8_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80113E8C_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80114150_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_80114250_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeDraw);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeColorSet);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeInMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeOutMain);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeKill);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeInCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeOutCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeWhiteInCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opWipeWhiteOutCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", func_801149A4_opening);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opSleep);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorDispOn);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/opening/523FD0", opContErrorKill);
