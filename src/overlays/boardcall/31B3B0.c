#include "common.h"

void func_801059D0_boardcall(void);
void func_80105A44_boardcall(void);
void func_80105A98_boardcall(void);

OvlEntrypoint D_80105AE0_boardcall[] = {
    { 0, func_801059D0_boardcall },
    { 1, func_80105A44_boardcall },
    { 2, func_80105A98_boardcall },
    { -1, NULL },
};

void func_801059A0_boardcall(void) {
    ovlEventCall(D_80105AE0_boardcall, omovlevtno);
}
