#include "common.h"

void func_80107744_381D24_w05(void);
void func_80107780_381D60_w05(void);
void func_80107B90_382170_w05(void);
void func_80107C14_3821F4_w05(void);
void func_8011C348_396928_w05(void);

OvlEntrypoint D_8011D010_3975F0_w05[] = {
    {0, func_80107744_381D24_w05},
    {1, func_80107780_381D60_w05},
    {2, func_80107B90_382170_w05},
    {3, func_80107C14_3821F4_w05},
    {4, func_8011C348_396928_w05},
    {-1, NULL},
};

void func_801059A0_37FF80_w05(void) {
    ovlEventCall(D_8011D010_3975F0_w05, omovlevtno);
}
