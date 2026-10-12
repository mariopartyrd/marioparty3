#include "common.h"

void func_80107744_w04(void);
void func_80107780_w04(void);
void func_80107B34_w04(void);
void func_80107BB8_w04(void);
void func_8011AA10_w04(void);

OvlEntrypoint D_8011B710_w04[] = {
    { 0, func_80107744_w04 },
    { 1, func_80107780_w04 },
    { 2, func_80107B34_w04 },
    { 3, func_80107BB8_w04 },
    { 4, func_8011AA10_w04 },
    { -1, NULL },
};

void func_801059A0_w04(void) {
    ovlEventCall(D_8011B710_w04, omovlevtno);
}
