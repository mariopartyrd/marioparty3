#include "common.h"

typedef s16 Array2D[2][18];

void func_8000BBFC_C7FC(u16, s16);
void func_8000BC48_C848(u16, s32);
void func_8000BCC8_C8C8(u16, s32);
void func_8000BE5C_CA5C(u16, f32, f32);
void func_8000C184_CD84(u16);
void func_8001ACDC_1B8DC(s16);
void Hu3DModelRotSet(s16, f32, f32, f32);
void Hu3DModelScaleSet(s16, f32, f32, f32);
void func_8001C258_1CE58(s16, s32, s32);
void HuSprKill(s16);
void func_8010B82C_507A8C_msetup(s32);
void func_8010B858_507AB8_msetup();
void func_8010B998_507BF8_msetup();
s32 func_8010D684_5098E4_msetup(s16, s16 *);
void func_8010DDD8_50A038_msetup(void *);
omObjData *func_8010DE38_50A098_msetup(s32, s32, s32);
void func_8010E4BC_50A71C_msetup(Array2D *, s32, s32);
void func_8010E4D8_50A738_msetup(Array2D *, s32);
void func_8010E8C8_50AB28_msetup(Array2D *, s32, s32, f32, f32, f32, f32, s32);
void func_8010F320_50B580_msetup(s32, s32, s16, s16);
extern s32 D_80119420_515680_msetup;
extern s32 D_80119E94_5160F4_msetup[];
extern s32 D_80119EAC_51610C_msetup[];
extern s32 D_80119EC4_516124_msetup[];
extern s32 D_80119EE0_516140_msetup[];
extern s16 D_8011A938_516B98_msetup;
extern s16 D_8011A948_516BA8_msetup;
extern u8 D_8011AA45_516CA5_msetup; // board index chosen
typedef struct UnkStarLift {
    char unk_00[0x04];
    s16 unk4;
} UnkStarLift;

s32 _CheckFlag(s32);             /* extern */
s16 func_80055810_56410(void *); /* extern */

s32 func_80113ED4_510134_msetup(UnkStarLift *arg0);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801059A0_501C00_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105C4C_501EAC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105DB4_502014_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105E90_5020F0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105F7C_5021DC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106030_502290_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010610C_50236C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801061E0_502440_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106208_502468_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106260_5024C0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106320_502580_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801068F4_502B54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106DF8_503058_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106FC0_503220_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801070FC_50335C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107428_503688_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801077E0_503A40_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107840_503AA0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107964_503BC4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107A58_503CB8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107B8C_503DEC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107CF4_503F54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107D84_503FE4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107E48_5040A8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107ECC_50412C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107F88_5041E8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107FB4_504214_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108464_5046C4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801084C4_504724_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801085D4_504834_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801086C8_504928_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801087F4_504A54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801088A8_504B08_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108938_504B98_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801089FC_504C5C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108AB8_504D18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108F74_5051D4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109218_505478_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109868_505AC8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109EA0_506100_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F04_506164_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F7C_5061DC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A10C_50636C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A204_506464_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A2B0_506510_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A35C_5065BC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A780_5069E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7A0_506A00_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7EC_506A4C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC78_506ED8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC94_506EF4_msetup);

void func_8010ACB0_506F10_msetup(void) {
}
