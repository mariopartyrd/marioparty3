#ifndef _AUDIO_H
#define _AUDIO_H

#include "ultra64.h"

s16 HuAudSeqPlay(s16 musId);
s16 func_8004A5C4_4B1C4(s32);
void HuAudSeqFadeOut(s16 speed);
s16 HuAudFXPlay(s16 seId);
void func_8004AAD0_4B6D0(s16, s8);
void func_8004AB0C_4B70C(s32);
void HuAudFXPitchSet(s32 seNo, s32 pitch);
s16 CharFXPlay(s16 seId, u8 charNo);
s32 func_8004AC5C_4B85C(s16 arg0, s16 arg1);
s16 func_8004AC98_4B898(s16, s16);
void func_8004ACE0_4B8E0(s32, s16);
void HuAudFXStop(s32 seNo);
void func_8004AEF0_4BAF0(s16, s32);
void omVibrate(s16 arg0, s32 arg1, s32 arg2, s32 arg3);

#endif
