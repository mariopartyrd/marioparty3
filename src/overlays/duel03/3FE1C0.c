#include "common.h"

void func_80105B64_3FE384_duel03(void);
void func_80105BA0_3FE3C0_duel03(void);
void func_8010DA88_4062A8_duel03(void);
void func_8010DB04_406324_duel03(void);

OvlEntrypoint D_80117400_40FC20_duel03[] = {
    {0, func_80105B64_3FE384_duel03},
    {1, func_80105BA0_3FE3C0_duel03},
    {2, func_8010DA88_4062A8_duel03},
    {3, func_8010DB04_406324_duel03},
    {-1, NULL}
};

void func_801059A0_3FE1C0_duel03(void) {
    ovlEventCall(D_80117400_40FC20_duel03, omovlevtno);
}
