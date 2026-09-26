#include "common.h"
#include "duel01.h"

void func_80105B64_duel01(void);
void func_80105B9C_duel01(void);
void func_8010DA84_duel01(void);
void func_8010DB00_duel01(void);

OvlEntrypoint D_801186E0_duel01[] = {
    { 0, func_80105B64_duel01 },
    { 1, func_80105B9C_duel01 },
    { 2, func_8010DA84_duel01 },
    { 3, func_8010DB00_duel01 },
    { -1, NULL }
};

void func_801059A0_duel01(void) {
    ovlEventCall(D_801186E0_duel01, omovlevtno);
}
