#ifndef _WALUIGIS_ISLAND_H
#define _WALUIGIS_ISLAND_H

#include "common.h"
#include "game/board.h"

typedef struct StarMasuSlot {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ s16 masuId;
} StarMasuSlot __attribute__((aligned(4))); // size 0x4

typedef struct MasuIdTable {
    /* 0x00 */ StarMasuSlot entries[3];
} MasuIdTable; // size 0xC

typedef struct ModelIdTable {
    /* 0x00 */ s32 entries[3];
} ModelIdTable; // size 0xC

typedef struct MessageTable {
    /* 0x00 */ s32 entries[4];
} MessageTable; // size 0x10

typedef struct BranchLink {
    /* 0x00 */ s16 link;
    /* 0x02 */ s16 idx;
    /* 0x04 */ s16 rev;
} BranchLink; // size 0x6

typedef struct {
    /* 0x00 */ u16 multiplier;
    /* 0x02 */ u16 threshold;
} GameGuyReward;

/* Overlay functions */
void func_80108B9C_39DF1C_w06(void);
void func_8010980C_39EB8C_w06(void);
void func_80109870_39EBF0_w06(void);
void func_80109918_39EC98_w06(void);
void func_80109950_39ECD0_w06(void);
void func_80109988_39ED08_w06(void);
void func_80109A50_39EDD0_w06(void);
void func_80109B1C_39EE9C_w06(void);
void func_80109B54_39EED4_w06(void);
void func_80109C04_39EF84_w06(void);
void func_80109CA4_39F024_w06(void);
void func_80109D44_39F0C4_w06(void);
void func_80109E28_39F1A8_w06(void);
void func_80109F10_39F290_w06(void);
void func_80109F68_39F2E8_w06(void);
void func_80109FC0_39F340_w06(void);
void func_8010A018_39F398_w06(void);
void func_8010A0C8_39F448_w06(void);
void func_8010A120_39F4A0_w06(void);
void func_8010A178_39F4F8_w06(void);
void func_8010A1D8_39F558_w06(void);
void func_8010A238_39F5B8_w06(void);
void func_8010A298_39F618_w06(void);
void func_8010A2F8_39F678_w06(void);
void func_8010A358_39F6D8_w06(void);
void func_8010A3B8_39F738_w06(void);
void func_8010A418_39F798_w06(void);
void func_8010A488_39F808_w06(void);
void func_8010A4F8_39F878_w06(void);
void func_8010A560_39F8E0_w06(void);
void func_8010A5C0_39F940_w06(void);
void func_8010A620_39F9A0_w06(void);
void func_8010A680_39FA00_w06(void);
void func_8010A6E0_39FA60_w06(void);
void func_8010A740_39FAC0_w06(void);
void func_8010A7A0_39FB20_w06(void);
void func_8010A800_39FB80_w06(void);
void func_8010A860_39FBE0_w06(void);
void func_8010AE18_3A0198_w06(void);
void func_8010B088_3A0408_w06(void);
void func_8010B844_3A0BC4_w06(void);
void func_8010BBF0_3A0F70_w06(void);
void func_8010C9EC_3A1D6C_w06(void);
void func_801103E0_3A5760_w06(void);
void func_801103FC_3A577C_w06(void);
void func_80117F30_3AD2B0_w06(void);
void func_80118864_3ADBE4_w06(void);
void func_8011A2A0_3AF620_w06(void);
void func_8011A30C_3AF68C_w06(void);
s32 func_80107438_39C7B8_w06(u8 *arg0, s32 arg1, s32 arg2);
void func_80107828_39CBA8_w06(void);
void func_801088F4_39DC74_w06(void);
void func_80117814_3ACB94_w06(s16 (*masu)[3], BranchLink (*links)[2], DecisionTreeNonLeafNode **trees);
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
