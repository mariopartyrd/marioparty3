#include "common.h"

void func_801059D0_3D8960_duelcall(void);
void func_80105A44_3D89D4_duelcall(void);
void func_80105A98_3D8A28_duelcall(void);

OvlEntrypoint D_80105AE0_3D8A70_duelcall[] = {
    {0, func_801059D0_3D8960_duelcall},
    {1, func_80105A44_3D89D4_duelcall},
    {2, func_80105A98_3D8A28_duelcall},
    {-1, NULL}
};

void func_801059A0_3D8930_duelcall(void) {
    ovlEventCall(D_80105AE0_3D8A70_duelcall, omovlevtno);
}
