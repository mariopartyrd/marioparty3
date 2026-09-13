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
void func_80108B9C_w06(void);
void func_8010980C_w06(void);
void func_80109870_w06(void);
void func_80109918_w06(void);
void func_80109950_w06(void);
void func_80109988_w06(void);
void func_80109A50_w06(void);
void func_80109B1C_w06(void);
void func_80109B54_w06(void);
void func_80109C04_w06(void);
void func_80109CA4_w06(void);
void func_80109D44_w06(void);
void func_80109E28_w06(void);
void func_80109F10_w06(void);
void func_80109F68_w06(void);
void func_80109FC0_w06(void);
void func_8010A018_w06(void);
void func_8010A0C8_w06(void);
void func_8010A120_w06(void);
void func_8010A178_w06(void);
void func_8010A1D8_w06(void);
void func_8010A238_w06(void);
void func_8010A298_w06(void);
void func_8010A2F8_w06(void);
void func_8010A358_w06(void);
void func_8010A3B8_w06(void);
void func_8010A418_w06(void);
void func_8010A488_w06(void);
void func_8010A4F8_w06(void);
void func_8010A560_w06(void);
void func_8010A5C0_w06(void);
void func_8010A620_w06(void);
void func_8010A680_w06(void);
void func_8010A6E0_w06(void);
void func_8010A740_w06(void);
void func_8010A7A0_w06(void);
void func_8010A800_w06(void);
void func_8010A860_w06(void);
void func_8010AE18_w06(void);
void func_8010B088_w06(void);
void func_8010B844_w06(void);
void func_8010BBF0_w06(void);
void func_8010C9EC_w06(void);
void func_801103E0_w06(void);
void func_801103FC_w06(void);
void func_80117F30_w06(void);
void func_80118864_w06(void);
void func_8011A2A0_w06(void);
void func_8011A30C_w06(void);
s32 func_80107438_w06(u8 *arg0, s32 arg1, s32 arg2);
void func_80107828_w06(void);
void func_801088F4_w06(void);
void func_80117814_w06(s16 (*masu)[3], BranchLink (*links)[2], DecisionTreeNonLeafNode **trees);
s32 func_8011B188_w06(void);
s32 func_8011B4EC_w06(void);
void func_80106120_w06(void);
void func_80107C04_w06(s16 arg0);
void func_8011A110_w06(void);
void func_801091EC_w06(void);
void func_80119748_w06(void);
void func_80119E00_w06(s32 arg0);
void func_80108580_w06(void);
void func_80108BD0_w06(void);
void func_8010F07C_w06(void);
void func_80114018_w06(void);
void func_80119698_w06(void);
void func_801064DC_w06(void);
void func_80108290_w06(s16 arg0);
void func_80117AE8_w06(omObjData *arg0);
void func_80107E44_w06(s16 arg0);
void func_801080BC_w06(s16 arg0);
void func_80107FC0_w06(void);
void func_80113B68_w06(void);
void func_8010F20C_w06(void);
void func_8011068C_w06(void);
void func_801111E4_w06(void);
void func_80110A54_w06(void);
void func_80110AC0_w06(void);
void func_80118FF0_w06(void);
void func_80111CCC_w06(void);
void func_80111F58_w06(void);
void func_80110FB4_w06(void);
void func_80111524_w06(void);
void func_80111870_w06(void);
void func_801182EC_w06(void);
void func_80118B6C_w06(void);
void func_801123A8_w06(void);
void func_80112668_w06(void);
void func_80112A08_w06(void);
void func_80113404_w06(void);
void func_80113F5C_w06(void);
void func_80114C74_w06(void);
s32 func_801146F4_w06(u8 *arg0, s32 arg1);
void func_80115F10_w06(void);
void func_80116F10_w06(void);
void func_8011813C_w06(void);
void func_80118A34_w06(void);
s32 func_8011AB80_w06(void);
void func_80107D98_w06(void);
void func_80107F64_w06(void);
void func_80108228_w06(void);
void func_801083FC_w06(void);
void func_8010866C_w06(void);
void func_801086EC_w06(void);
void func_80108764_w06(void);
void func_801087DC_w06(void);
void func_80108950_w06(void);
void func_80108A2C_w06(void);
void func_8011A1E8_w06(void);
void func_80117E30_w06(void);
void func_801159E0_w06(void);
void func_80114338_w06(void);
void func_80110574_w06(omObjData *arg0);

#endif /* _WALUIGIS_ISLAND_H */
