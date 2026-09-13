#include "common.h"

typedef s16 Array2D[2][18];

void func_8000BBFC_main(u16, s16);
void func_8000BC48_main(u16, s32);
void func_8000BCC8_main(u16, s32);
void func_8000BE5C_main(u16, f32, f32);
void func_8000C184_main(u16);
void func_8001ACDC_main(s16);
void Hu3DModelRotSet(s16, f32, f32, f32);
void Hu3DModelScaleSet(s16, f32, f32, f32);
void func_8001C258_main(s16, s32, s32);
void HuSprKill(s16);
void func_8010B82C_msetup(s32);
void func_8010B858_msetup();
void func_8010B998_msetup();
s32 func_8010D684_msetup(s16, s16 *);
void func_8010DDD8_msetup(void *);
omObjData *func_8010DE38_msetup(s32, s32, s32);
void func_8010E4BC_msetup(Array2D *, s32, s32);
void func_8010E4D8_msetup(Array2D *, s32);
void func_8010E8C8_msetup(Array2D *, s32, s32, f32, f32, f32, f32, s32);
void func_8010F320_msetup(s32, s32, s16, s16);
extern s32 D_80119420_msetup;
extern s32 D_80119E94_msetup[];
extern s32 D_80119EAC_msetup[];
extern s32 D_80119EC4_msetup[];
extern s32 D_80119EE0_msetup[];
extern s16 D_8011A938_msetup;
extern s16 D_8011A948_msetup;
extern u8 D_8011AA45_msetup; // board index chosen
typedef struct UnkStarLift {
    char unk_00[0x04];
    s16 unk4;
} UnkStarLift;

s32 _CheckFlag(s32);             /* extern */
s16 func_80055810_main(void *); /* extern */

s32 func_80113ED4_msetup(UnkStarLift *arg0);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801059A0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105C4C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105DB4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105E90_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105F7C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106030_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010610C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801061E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106208_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106260_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106320_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801068F4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106DF8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106FC0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801070FC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107428_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801077E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107840_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107964_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107A58_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107B8C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107CF4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107D84_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107E48_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107ECC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107F88_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107FB4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108464_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801084C4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801085D4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801086C8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801087F4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801088A8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108938_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801089FC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108AB8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108F74_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109218_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109868_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109EA0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F04_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F7C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A10C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A204_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A2B0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A35C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A780_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7A0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7EC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC78_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC94_msetup);

void func_8010ACB0_msetup(void) {
}
