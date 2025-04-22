#include "common.h"

void func_80107934_3507A4_SpinyDesert(void);
void func_80107970_3507E0_SpinyDesert(void);
void func_80107CA4_350B14_SpinyDesert(void);
void func_80107D28_350B98_SpinyDesert(void);
void func_8011B41C_36428C_SpinyDesert(void);

board_overlay_entrypoint D_8011C0E0_364F50_SpinyDesert[] = {
    {0, func_80107934_3507A4_SpinyDesert},
    {1, func_80107970_3507E0_SpinyDesert},
    {2, func_80107CA4_350B14_SpinyDesert},
    {3, func_80107D28_350B98_SpinyDesert},
    {4, func_8011B41C_36428C_SpinyDesert},
    {-1, NULL},
};

void func_801059A0_34E810_SpinyDesert(void) {
    ovlEventCall(D_8011C0E0_364F50_SpinyDesert, omovlevtno);
}
