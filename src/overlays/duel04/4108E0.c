#include "common.h"

void func_80105B64_410AA4_duel04(void);
void func_80105BA0_410AE0_duel04(void);
void func_8010DA88_4189C8_duel04(void);
void func_8010DB10_418A50_duel04(void);

OvlEntrypoint D_80119C70_424BB0_duel04[] = {
    {0, func_80105B64_410AA4_duel04},
    {1, func_80105BA0_410AE0_duel04},
    {2, func_8010DA88_4189C8_duel04},
    {3, func_8010DB10_418A50_duel04},
    {-1, NULL}
};

void func_801059A0_4108E0_duel04(void) {
    ovlEventCall(D_80119C70_424BB0_duel04, omovlevtno);
}
