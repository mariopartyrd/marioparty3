#ifndef _UTIL_H
#define _UTIL_H

#include "ultra64.h"
#include "game/object.h"

#define rand16() ((rand8() << 8) | rand8())

u16 func_8000B108_BD08(s32 arg0, s32 arg1);
u8 rand8(void);
void ScissorSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void ViewportSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_8000B460_C060(omObjData*, u16, s32);

#endif //_UTIL_H
