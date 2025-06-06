#include "common.h"

void func_801059D0_31B3E0_name_47(void);
void func_80105A44_31B454_name_47(void);
void func_80105A98_31B4A8_name_47(void);

OvlEntrypoint D_80105AE0_31B4F0_name_47[] = {
    {0, func_801059D0_31B3E0_name_47},
    {1, func_80105A44_31B454_name_47},
    {2, func_80105A98_31B4A8_name_47},
    {-1, NULL},
};

void func_801059A0_31B3B0_name_47(void) {
    ovlEventCall(D_80105AE0_31B4F0_name_47, omovlevtno);
}
