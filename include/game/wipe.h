#ifndef _WIPE_H
#define _WIPE_H

#include "ultra64.h"

void WipeInit(void);
void WipeCreateIn(s32, s32);
s32 WipeCreateOut(s32, s32);
s32 WipeStatGet(void);
void WipeColorSet(u8, u8, u8);

#endif //_WIPE_H
