#include "common.h"

void func_80107744_w02(void);
void func_80107780_w02(void);
void func_80107B4C_w02(void);
void func_80107BD0_w02(void);
void func_8011B934_w02(void);

OvlEntrypoint D_8011C630_w02[] = {
    { 0, func_80107744_w02 },
    { 1, func_80107780_w02 },
    { 2, func_80107B4C_w02 },
    { 3, func_80107BD0_w02 },
    { 4, func_8011B934_w02 },
    { -1, NULL },
};

void func_801059A0_w02(void) {
    ovlEventCall(D_8011C630_w02, omovlevtno);
}
