#include "common.h"

void func_80107744_w06(void);
void func_80107780_w06(void);
void func_80107B54_w06(void);
void func_80107BD8_w06(void);
void func_8011A848_w06(void);

OvlEntrypoint D_8011B550_w06[] = {
    { 0, func_80107744_w06 },
    { 1, func_80107780_w06 },
    { 2, func_80107B54_w06 },
    { 3, func_80107BD8_w06 },
    { 4, func_8011A848_w06 },
    { -1, NULL },
};

void func_801059A0_w06(void) {
    ovlEventCall(D_8011B550_w06, omovlevtno);
}
