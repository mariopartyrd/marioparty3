#include "common.h"

void func_801059D0_duelcall(void);
void func_80105A44_duelcall(void);
void func_80105A98_duelcall(void);

OvlEntrypoint D_80105AE0_duelcall[] = {
    { 0, func_801059D0_duelcall },
    { 1, func_80105A44_duelcall },
    { 2, func_80105A98_duelcall },
    { -1, NULL }
};

void func_801059A0_duelcall(void) {
    ovlEventCall(D_80105AE0_duelcall, omovlevtno);
}
