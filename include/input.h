#ifndef _INPUT_H
#define _INPUT_H

#include "common.h"

extern u16 D_800C9520_main[];
extern s16 D_800D0590_main[];
extern s16 D_800D10F8_main[];
extern u16 D_800D1350_main[];
extern u16 D_800D5546_main[];

extern s8 D_800CBB6E_main[];
extern s16 D_800CDA7C_main[];
extern s8 D_800D20A1_main[];

void ContDataInit(void);
void ContDataUpdate(void);

#endif