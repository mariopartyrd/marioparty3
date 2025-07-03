#include "common.h"

void func_80105B64_3EC724_duel02(void);
void func_80105BA0_3EC760_duel02(void);
void func_8010DA88_3F4648_duel02(void);
void func_8010DB04_3F46C4_duel02(void);

OvlEntrypoint D_80116570_3FD130_duel02[] = {
    {0, func_80105B64_3EC724_duel02},
    {1, func_80105BA0_3EC760_duel02},
    {2, func_8010DA88_3F4648_duel02},
    {3, func_8010DB04_3F46C4_duel02},
    {-1, NULL}
};

void func_801059A0_3EC560_duel02(void) {
    ovlEventCall(D_80116570_3FD130_duel02, omovlevtno);
}