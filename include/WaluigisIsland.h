#ifndef _WALUIGIS_ISLAND_H
#define _WALUIGIS_ISLAND_H

#include "common.h"

typedef struct StarMasuSlot {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ s16 masuId;
} StarMasuSlot __attribute__((aligned(4))); // size 0x4

typedef struct StarMasuTable {
    /* 0x00 */ StarMasuSlot entries[4];
} StarMasuTable; // size 0x10

typedef struct MasuIdTable {
    /* 0x00 */ StarMasuSlot entries[3];
} MasuIdTable; // size 0xC

typedef struct ChanceTable {
    /* 0x00 */ s32 entries[4];
} ChanceTable; // size 0x10

typedef struct ModelIdTable {
    /* 0x00 */ s32 entries[3];
} ModelIdTable; // size 0xC

typedef struct MessageTable {
    /* 0x00 */ s32 entries[4];
} MessageTable; // size 0x10

typedef struct StarDelayTable {
    /* 0x00 */ u8 times[10];
} StarDelayTable; // size 0xA

typedef struct {
    /* 0x00 */ u16 multiplier;
    /* 0x02 */ u16 threshold;
} GameGuyReward;

/* Overlay data */
extern s16 D_8011B5C0_3B0940_w06[8];
extern const Vec D_8011E158_3B34D8_w06[8];
extern s16 D_8011B60C_3B098C_w06; // unknown type
extern s16 D_8011B610_3B0990_w06[];
extern s32 D_8011B5D0_3B0950_w06[];
extern s32 D_8011B5EC_3B096C_w06[];
extern s16 D_8011B5A0_3B0920_w06[];
extern s16 D_8011B5B0_3B0930_w06[];
extern s16 D_8011B580_3B0900_w06[];
extern s16 D_8011B590_3B0910_w06[];
extern s32 D_8011B7C8_3B0B48_w06[];
extern s32 D_8011B780_3B0B00_w06[];
extern s32 D_8011B7A4_3B0B24_w06[];
extern s16 D_8011B7A6_3B0B26_w06[][2];
extern s32 D_8011B7EC_3B0B6C_w06[];
extern s8 D_8011C790_3B1B10_w06[][5][7];
extern u8 D_8011CC1C_3B1F9C_w06[];
extern s16 D_8011CBF8_3B1F78_w06[];
extern const u8 D_8011E0E0_3B3460_w06[];
extern const StarMasuTable D_8011E0F0_3B3470_w06;
extern const StarDelayTable D_8011E100_3B3480_w06;
extern const ChanceTable D_8011E10C_3B348C_w06;
extern const ChanceTable D_8011E11C_3B349C_w06;
extern const ChanceTable D_8011E12C_3B34AC_w06;
extern const ChanceTable D_8011E13C_3B34BC_w06;
extern u8 D_8011C054_3B13D4_w06[];
extern u8 D_8011C078_3B13F8_w06[];
extern s32 D_8011E334_3B36B4_w06;
extern s32 D_8011E338_3B36B8_w06;
extern s32 D_8011E33C_3B36BC_w06;
extern s32 D_8011E340_3B36C0_w06;
extern u8 *D_8011E344_3B36C4_w06;
extern s32 D_8011E34C_3B36CC_w06;
extern s16 D_8011E34E_3B36CE_w06;
extern s32 D_8011E360_3B36E0_w06;
extern s32 D_8011E364_3B36E4_w06;
extern char D_8011CAC4_3B1E44_w06[];
extern s32 D_8011E2B8_3B3638_w06;
extern s32 D_8011B608_3B0988_w06;
extern Object *D_8011E2BC_3B363C_w06;
extern Unk3 *D_8011E2C0_3B3640_w06;
extern Unk3 *D_8011E2C4_3B3644_w06;
extern Unk3 *D_8011E2C8_3B3648_w06;
extern Unk3 *D_8011E2CC_3B364C_w06;
extern Unk3 *D_8011E2D0_3B3650_w06;
extern omObjData *D_8011E398_3B3718_w06[];
extern void *D_8011B828_3B0BA8_w06;
extern s16 D_8011B82C_3B0BAC_w06;
extern s16 D_8011C120_3B14A0_w06[];
extern s32 D_8011C134_3B14B4_w06[];
extern s32 D_8011B99C_3B0D1C_w06[];
extern s16 D_8011C168_3B14E8_w06[];
extern s32 D_8011C17C_3B14FC_w06[];
extern s32 D_8011BA2C_3B0DAC_w06[];
extern s16 D_8011C240_3B15C0_w06[];
extern s32 D_8011C254_3B15D4_w06[];
extern s32 D_8011BB4C_3B0ECC_w06[];
extern RectF D_8011CDE8_3B2168_w06;
extern Process *D_8011E298_3B3618_w06[];
extern char D_8011C9BC_3B1D3C_w06[];
extern char D_8011CC58_3B1FD8_w06[];
extern char D_8011CA34_3B1DB4_w06[];
extern char D_8011CBC8_3B1F48_w06[];
extern Object *D_8011E270_3B35F0_w06;
extern Object *D_8011E278_3B35F8_w06[];
extern s16 D_8011B698_3B0A18_w06[];
extern s16 D_8011B640_3B09C0_w06[][2];
extern s16 D_8011B688_3B0A08_w06[];
extern s16 D_8011B660_3B09E0_w06[][2];
extern s16 D_8011B6A8_3B0A28_w06[];
extern u8 D_8011B72D_3B0AAD_w06[][2];
extern u32 *D_8011B768_3B0AE8_w06[];
extern s16 D_8011B728_3B0AA8_w06[];
extern s16 D_8011B680_3B0A00_w06[][2];
extern s16 D_8011B678_3B09F8_w06[][2];
extern s16 D_8011B6AC_3B0A2C_w06[];
extern Vec D_8011B6B0_3B0A30_w06[];
extern Vec D_8011B6EC_3B0A6C_w06[];
extern Object *D_8011E32C_3B36AC_w06[];
extern Object *D_8011B83C_3B0BBC_w06;
extern s16 D_8011B830_3B0BB0_w06[];
extern s16 D_8011B834_3B0BB4_w06[][2];
extern s16 D_8011B836_3B0BB6_w06[][2];
extern s16 D_8011C3F0_3B1770_w06[];
extern s32 D_8011C404_3B1784_w06[];
extern s32 D_8011BD98_3B1118_w06[];
extern s16 D_8011C438_3B17B8_w06[];
extern s32 D_8011C44C_3B17CC_w06[];
extern s32 D_8011BE04_3B1184_w06[];
extern s16 D_8011C480_3B1800_w06[];
extern s32 D_8011C494_3B1814_w06[];
extern s32 D_8011BE64_3B11E4_w06[];
extern s16 D_8011C4C8_3B1848_w06[];
extern s32 D_8011C4DC_3B185C_w06[];
extern s32 D_8011BEC4_3B1244_w06[];
extern s16 D_8011C510_3B1890_w06[];
extern s32 D_8011C524_3B18A4_w06[];
extern s32 D_8011BEE8_3B1268_w06[];
extern s16 D_8011C548_3B18C8_w06[];
extern s32 D_8011C55C_3B18DC_w06[];
extern s32 D_8011BF9C_3B131C_w06[];
extern s16 D_8011C590_3B1910_w06[];
extern s32 D_8011C5A4_3B1924_w06[];
extern s32 D_8011C014_3B1394_w06[];
extern s16 D_8011C2D0_3B1650_w06[];
extern s32 D_8011C2E4_3B1664_w06[];
extern s32 D_8011BBB8_3B0F38_w06[];
extern s16 D_8011C318_3B1698_w06[];
extern s32 D_8011C32C_3B16AC_w06[];
extern s32 D_8011BBD0_3B0F50_w06[];
extern s16 D_8011C288_3B1608_w06[];
extern s32 D_8011C29C_3B161C_w06[];
extern s32 D_8011BBA0_3B0F20_w06[];
extern Object *D_8011E2DC_3B365C_w06;
extern s32 D_8011E2D4_3B3654_w06;
extern s32 D_8011E2D8_3B3658_w06;
extern void *D_8011E2E0_3B3660_w06[];
extern Object *D_8011E2E4_3B3664_w06;
extern void *D_8011E2E8_3B3668_w06[];
extern Object *D_8011E310_3B3690_w06;
extern Object *D_8011E348_3B36C8_w06;
extern Object *D_8011E358_3B36D8_w06;
extern Object *D_8011E314_3B3694_w06[];
extern s32 D_8011E370_3B36F0_w06[];
extern Vec2f D_8011CA44_3B1DC4_w06[];
extern Vec2f D_8011CA64_3B1DE4_w06[];
extern s32 D_8011E350_3B36D0_w06;
extern s32 D_8011E354_3B36D4_w06;
extern s16 D_8011E356_3B36D6_w06;
extern s32 D_8011DF80_3B3300_w06;
extern s32 D_8011C8C8_3B1C48_w06;
extern void *D_8011E0D4_3B3454_w06[];
extern u8 *D_8011E004_3B3384_w06[];
extern s8 *D_8011E0A4_3B3424_w06[];
extern void *D_8011E0C4_3B3444_w06[];
extern void *D_8011E0CC_3B344C_w06[];
extern RGB D_8011CBA8_3B1F28_w06[];
extern s16 D_8011E37E_3B36FE_w06;
extern s32 D_8011CB30_3B1EB0_w06[];
extern s32 D_8011CB44_3B1EC4_w06;
extern s16 D_8011CBD8_3B1F58_w06[];
extern const ModelIdTable D_8011E1F8_3B3578_w06;
extern const MessageTable D_8011E204_3B3584_w06;
extern const MasuIdTable D_8011E214_3B3594_w06;
extern Vec2f D_8011C8DC_3B1C5C_w06[];
extern Vec2f D_8011C8E0_3B1C60_w06[];
extern Vec2f D_8011C8FC_3B1C7C_w06[];
extern Vec2f D_8011C900_3B1C80_w06[];
extern Vec2f D_8011CB50_3B1ED0_w06[];
extern Vec2f D_8011CB54_3B1ED4_w06[];
extern Vec2f D_8011CA84_3B1E04_w06[];
extern Vec2f D_8011CAA4_3B1E24_w06[];
extern s32 D_8011CB80_3B1F00_w06;
extern u8 D_8011CB84_3B1F04_w06[];
extern u8 D_8011CB88_3B1F08_w06[];
extern GameGuyReward D_8011CB8C_3B1F0C_w06[];
extern u8 D_8011C91C_3B1C9C_w06[][3];
extern u8 D_8011C930_3B1CB0_w06[][3];
extern u8 D_8011C95C_3B1CDC_w06[];
extern s32 D_8011C964_3B1CE4_w06[];
extern s32 D_8011C970_3B1CF0_w06[];
extern u8 D_8011D0E0_3B2460_w06[];
extern u8 D_8011D14C_3B24CC_w06[];
extern u8 D_8011D2F0_3B2670_w06[];
extern u8 D_8011D44C_3B27CC_w06[];
extern u8 D_8011D5C0_3B2940_w06[];
extern u8 D_8011DA3C_3B2DBC_w06[];
extern u8 D_8011DDDC_3B315C_w06[];
extern s32 D_8011E3A8_3B3728_w06;
extern s32 D_8011E3AC_3B372C_w06;
extern const f64 D_8011E1B8_3B3538_w06;
extern s16 D_8011C090_3B1410_w06[];
extern s32 D_8011C0A4_3B1424_w06[];
extern s32 D_8011B870_3B0BF0_w06[];
extern s16 D_8011C0D8_3B1458_w06[];
extern s32 D_8011C0EC_3B146C_w06[];
extern s32 D_8011B924_3B0CA4_w06[];
extern s16 D_8011C1B0_3B1530_w06[];
extern s32 D_8011C1C4_3B1544_w06[];
extern s32 D_8011BA8C_3B0E0C_w06[];
extern s16 D_8011C1F8_3B1578_w06[];
extern s32 D_8011C20C_3B158C_w06[];
extern s32 D_8011BB04_3B0E84_w06[];
extern s16 D_8011C360_3B16E0_w06[];
extern s32 D_8011C374_3B16F4_w06[];
extern s32 D_8011BC78_3B0FF8_w06[];
extern s16 D_8011C3A8_3B1728_w06[];
extern s32 D_8011C3BC_3B173C_w06[];
extern s32 D_8011BD38_3B10B8_w06[];
extern Object *D_8011E380_3B3700_w06;
extern Object *D_8011E388_3B3708_w06[];
extern Object *D_8011E368_3B36E8_w06;
extern Object *D_8011E35C_3B36DC_w06;
extern Object *D_8011B824_3B0BA4_w06;
extern Object *D_8011E328_3B36A8_w06;
extern Object *D_8011E31C_3B369C_w06[];
extern s16 D_8011B81C_3B0B9C_w06[];
extern s16 D_8011B810_3B0B90_w06[];
extern s16 D_8011B668_3B09E8_w06[][2];
extern s16 D_8011B814_3B0B94_w06[];
extern s16 D_8011B670_3B09F0_w06[][2];
extern Object *D_8011B818_3B0B98_w06;
extern const char D_8011E14C_3B34CC_w06[];
extern u32 D_8011C760_3B1AE0_w06[];
extern s32 D_8011C748_3B1AC8_w06[];
extern u8 D_8011C778_3B1AF8_w06[2][3][4];
extern u8 D_8011C7D8_3B1B58_w06[2][3][4];
extern s8 D_8011C7F0_3B1B70_w06[2][5][10];
extern u8 D_8011C854_3B1BD4_w06[2][10];
extern s32 D_8011C868_3B1BE8_w06[5][2];
extern s32 D_8011C890_3B1C10_w06[2];
extern s32 D_8011C898_3B1C18_w06[2];
extern s32 D_8011C8A0_3B1C20_w06[2];
extern s32 D_8011C8A8_3B1C28_w06[2];
extern s32 D_8011C8B0_3B1C30_w06[2];
extern u32 D_8011C8B8_3B1C38_w06[];
extern u32 D_8011C8C0_3B1C40_w06[];
extern s32 D_8011D788_3B2B08_w06[];
extern u8 D_8011D650_3B29D0_w06[];
extern s32 D_8011DD9C_3B311C_w06[];
extern s32 D_8011DDBC_3B313C_w06[];

/* Overlay functions */
s32 func_80107438_39C7B8_w06(u8 *arg0, s32 arg1, s32 arg2);
void func_80107828_39CBA8_w06(void);
void func_801088F4_39DC74_w06(void);
void func_80117814_3ACB94_w06(s16 *arg0, s32 *arg1, s32 *arg2);
s32 func_8011B188_3B0508_w06(void);
s32 func_8011B4EC_3B086C_w06(void);
void func_80106120_39B4A0_w06(void);
void func_80107C04_39CF84_w06(s16 arg0);
void func_8011A110_3AF490_w06(void);
void func_801091EC_39E56C_w06(void);
void func_80119748_3AEAC8_w06(void);
void func_80119E00_3AF180_w06(s32 arg0);
void func_80108580_39D900_w06(void);
void func_80108BD0_39DF50_w06(void);
void func_8010F07C_3A43FC_w06(void);
void func_80114018_3A9398_w06(void);
void func_80119698_3AEA18_w06(void);
void func_801064DC_39B85C_w06(void);
void func_80108290_39D610_w06(s16 arg0);
void func_80117AE8_3ACE68_w06(omObjData *arg0);
void func_80107E44_39D1C4_w06(s16 arg0);
void func_801080BC_39D43C_w06(s16 arg0);
void func_80107FC0_39D340_w06(void);
void func_80113B68_3A8EE8_w06(void);
void func_8010F20C_3A458C_w06(void);
void func_8011068C_3A5A0C_w06(void);
void func_801111E4_3A6564_w06(void);
void func_80110A54_3A5DD4_w06(void);
void func_80110AC0_3A5E40_w06(void);
void func_80118FF0_3AE370_w06(void);
void func_80111CCC_3A704C_w06(void);
void func_80111F58_3A72D8_w06(void);
void func_80110FB4_3A6334_w06(void);
void func_80111524_3A68A4_w06(void);
void func_80111870_3A6BF0_w06(void);
void func_801182EC_3AD66C_w06(void);
void func_80118B6C_3ADEEC_w06(void);
void func_801123A8_3A7728_w06(void);
void func_80112668_3A79E8_w06(void);
void func_80112A08_3A7D88_w06(void);
void func_80113404_3A8784_w06(void);
void func_80113F5C_3A92DC_w06(void);
void func_80114C74_3A9FF4_w06(void);
s32 func_801146F4_3A9A74_w06(u8 *arg0, s32 arg1);
void func_80115F10_3AB290_w06(void);
void func_80116F10_3AC290_w06(void);
void func_8011813C_3AD4BC_w06(void);
void func_80118A34_3ADDB4_w06(void);
s32 func_8011AB80_3AFF00_w06(void);
void func_80107D98_39D118_w06(void);
void func_80107F64_39D2E4_w06(void);
void func_80108228_39D5A8_w06(void);
void func_801083FC_39D77C_w06(void);
void func_8010866C_39D9EC_w06(void);
void func_801086EC_39DA6C_w06(void);
void func_80108764_39DAE4_w06(void);
void func_801087DC_39DB5C_w06(void);
void func_80108950_39DCD0_w06(void);
void func_80108A2C_39DDAC_w06(void);
void func_8011A1E8_3AF568_w06(void);
void func_80117E30_3AD1B0_w06(void);
void func_801159E0_3AAD60_w06(void);
void func_80114338_3A96B8_w06(void);
void func_80110574_3A58F4_w06(omObjData *arg0);

#endif /* _WALUIGIS_ISLAND_H */
