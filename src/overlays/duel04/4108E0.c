#include "common.h"

void func_80105B64_duel04(void);
void func_80105BA0_duel04(void);
void func_8010DA88_duel04(void);
void func_8010DB10_duel04(void);

OvlEntrypoint D_80119C70_duel04[] = {
    { 0, func_80105B64_duel04 },
    { 1, func_80105BA0_duel04 },
    { 2, func_8010DA88_duel04 },
    { 3, func_8010DB10_duel04 },
    { -1, NULL }
};

void func_801059A0_duel04(void) {
    ovlEventCall(D_80119C70_duel04, omovlevtno);
}
