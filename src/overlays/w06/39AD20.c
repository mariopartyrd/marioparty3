#include "common.h"

void func_80107744_39CAC4_w06(void);
void func_80107780_39CB00_w06(void);
void func_80107B54_39CED4_w06(void);
void func_80107BD8_39CF58_w06(void);
void func_8011A848_3AFBC8_w06(void);

OvlEntrypoint D_8011B550_3B08D0_w06[] = {
    {0, func_80107744_39CAC4_w06},
    {1, func_80107780_39CB00_w06},
    {2, func_80107B54_39CED4_w06},
    {3, func_80107BD8_39CF58_w06},
    {4, func_8011A848_3AFBC8_w06},
    {-1, NULL},
};

void func_801059A0_39AD20_w06(void) {
    ovlEventCall(D_8011B550_3B08D0_w06, omovlevtno);
}
