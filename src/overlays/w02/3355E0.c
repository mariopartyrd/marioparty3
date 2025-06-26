#include "common.h"

void func_80107744_337384_w02(void);
void func_80107780_3373C0_w02(void);
void func_80107B4C_33778C_w02(void);
void func_80107BD0_337810_w02(void);
void func_8011B934_34B574_w02(void);

OvlEntrypoint D_8011C630_34C270_w02[] = {
    {0, func_80107744_337384_w02},
    {1, func_80107780_3373C0_w02},
    {2, func_80107B4C_33778C_w02},
    {3, func_80107BD0_337810_w02},
    {4, func_8011B934_34B574_w02},
    {-1, NULL},
};

void func_801059A0_3355E0_w02(void) {
    ovlEventCall(D_8011C630_34C270_w02, omovlevtno);
}
