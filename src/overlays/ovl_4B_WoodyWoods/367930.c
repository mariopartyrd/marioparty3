#include "common.h"

void func_80107744_3696D4_WoodyWoods(void);
void func_80107780_369710_WoodyWoods(void);
void func_80107B34_369AC4_WoodyWoods(void);
void func_80107BB8_369B48_WoodyWoods(void);
void func_8011AA10_37C9A0_WoodyWoods(void);

OvlEntrypoint D_8011B710_37D6A0_WoodyWoods[] = {
    {0, func_80107744_3696D4_WoodyWoods},
    {1, func_80107780_369710_WoodyWoods},
    {2, func_80107B34_369AC4_WoodyWoods},
    {3, func_80107BB8_369B48_WoodyWoods},
    {4, func_8011AA10_37C9A0_WoodyWoods},
    {-1, NULL},
};

void func_801059A0_367930_WoodyWoods(void) {
    ovlEventCall(D_8011B710_37D6A0_WoodyWoods, omovlevtno);
}
