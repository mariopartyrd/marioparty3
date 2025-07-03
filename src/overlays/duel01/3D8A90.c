#include "common.h"
#include "duel01.h"

void func_80105B64_3D8C54_duel01(void);
void func_80105B9C_3D8C8C_duel01(void);
void func_8010DA84_3E0B74_duel01(void);
void func_8010DB00_3E0BF0_duel01(void);

OvlEntrypoint D_801186E0_3EB7D0_duel01[] = {
    {0, func_80105B64_3D8C54_duel01},
    {1, func_80105B9C_3D8C8C_duel01},
    {2, func_8010DA84_3E0B74_duel01},
    {3, func_8010DB00_3E0BF0_duel01},
    {-1, NULL}
};

void func_801059A0_3D8A90_duel01(void) {
    ovlEventCall(D_801186E0_3EB7D0_duel01, omovlevtno);
}