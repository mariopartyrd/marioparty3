#ifndef _INPUT_H
#define _INPUT_H

#include "common.h"

extern u16 D_800C9520_CA120[];
extern s16 D_800D0590_D1190[];
extern s16 D_800D10F8_D1CF8[];
extern u16 D_800D1350_D1F50[];
extern u16 D_800D5546_D6146[];

extern s8 D_800CBB6E_CC76E[];
extern s16 D_800CDA7C_CE67C[];
extern s8 D_800D20A1_D2CA1[];

void ContDataInit(void);
void ContDataUpdate(void);

#endif