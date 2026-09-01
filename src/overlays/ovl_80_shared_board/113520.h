#ifndef _ovl_80_113520
#define _ovl_80_113520

#include "common.h"
#include "game/board.h"

void MBPlayerVibrate(s16 playerIndex, s16 vibrationStrength);
UnkVibrateProcess* MBPlayerVibrateObjCreate(s16 playerNo, s16 vibrateStrength, s32 sleepTime);
void MBPlayerVibrateObjKill(UnkVibrateProcess* arg0);

#endif //_ovl_80_113520