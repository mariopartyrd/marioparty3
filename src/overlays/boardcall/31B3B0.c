#include "common.h"

void func_801059D0_31B3E0_boardcall(void);
void func_80105A44_31B454_boardcall(void);
void func_80105A98_31B4A8_boardcall(void);

OvlEntrypoint D_80105AE0_31B4F0_boardcall[] = {
    {0, func_801059D0_31B3E0_boardcall},
    {1, func_80105A44_31B454_boardcall},
    {2, func_80105A98_31B4A8_boardcall},
    {-1, NULL},
};

void func_801059A0_31B3B0_boardcall(void) {
    ovlEventCall(D_80105AE0_31B4F0_boardcall, omovlevtno);
}
