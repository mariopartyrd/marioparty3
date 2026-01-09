#include "ultra64.h"

void func_8008A0D0_8ACD0(Mtx* arg0) {
    arg0->m[0][1] =
    arg0->m[0][3] =
    arg0->m[1][0] =
    arg0->m[1][2] =
    arg0->m[2][0] =
    arg0->m[2][1] =
    arg0->m[2][2] =
    arg0->m[2][3] =
    arg0->m[3][0] =
    arg0->m[3][1] =
    arg0->m[3][2] =
    arg0->m[3][3] = 0;
    arg0->m[0][0] = arg0->m[1][1] = 0x10000;
    arg0->m[0][2] = arg0->m[1][3] = 1;
}
