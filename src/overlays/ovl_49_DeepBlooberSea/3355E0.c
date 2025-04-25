#include "common.h"

void func_80107744_337384_DeepBlooberSea(void);
void func_80107780_3373C0_DeepBlooberSea(void);
void func_80107B4C_33778C_DeepBlooberSea(void);
void func_80107BD0_337810_DeepBlooberSea(void);
void func_8011B934_34B574_DeepBlooberSea(void);

OvlEntrypoint D_8011C630_34C270_DeepBlooberSea[] = {
    {0, func_80107744_337384_DeepBlooberSea},
    {1, func_80107780_3373C0_DeepBlooberSea},
    {2, func_80107B4C_33778C_DeepBlooberSea},
    {3, func_80107BD0_337810_DeepBlooberSea},
    {4, func_8011B934_34B574_DeepBlooberSea},
    {-1, NULL},
};

void func_801059A0_3355E0_DeepBlooberSea(void) {
    ovlEventCall(D_8011C630_34C270_DeepBlooberSea, omovlevtno);
}
