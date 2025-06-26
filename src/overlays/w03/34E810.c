#include "common.h"

void func_80107934_3507A4_w03(void);
void func_80107970_3507E0_w03(void);
void func_80107CA4_350B14_w03(void);
void func_80107D28_350B98_w03(void);
void func_8011B41C_36428C_w03(void);

OvlEntrypoint D_8011C0E0_364F50_w03[] = {
    {0, func_80107934_3507A4_w03},
    {1, func_80107970_3507E0_w03},
    {2, func_80107CA4_350B14_w03},
    {3, func_80107D28_350B98_w03},
    {4, func_8011B41C_36428C_w03},
    {-1, NULL},
};

void func_801059A0_34E810_w03(void) {
    ovlEventCall(D_8011C0E0_364F50_w03, omovlevtno);
}
