#include "common.h"

void func_80105B64_duel02(void);
void func_80105BA0_duel02(void);
void func_8010DA88_duel02(void);
void func_8010DB04_duel02(void);

OvlEntrypoint D_80116570_duel02[] = {
    { 0, func_80105B64_duel02 },
    { 1, func_80105BA0_duel02 },
    { 2, func_8010DA88_duel02 },
    { 3, func_8010DB04_duel02 },
    { -1, NULL }
};

void func_801059A0_duel02(void) {
    ovlEventCall(D_80116570_duel02, omovlevtno);
}
