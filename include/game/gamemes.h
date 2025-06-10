#ifndef _GAME_GAMEMES_H
#define _GAME_GAMEMES_H

#include "ultra64.h"

#define GMES_ID_NONE -1

#define GMES_MAX 8

#define GMES_STRMAX 16

#define GMES_MES_0 0 // START (ALT?)
#define GMES_MES_1 1 // START (ALT?)
#define GMES_MES_2 2 // START (ALT?)
#define GMES_MES_3 3
#define GMES_MES_4 4
#define GMES_MES_5 5
#define GMES_MES_MG_START 6
#define GMES_MES_7 7
#define GMES_MES_8 8
#define GMES_MES_9 9
#define GMES_MES_10 10
#define GMES_MES_11 11 // FINISH (ALT?)
#define GMES_MES_12 12 // FINISH (ALT?)
#define GMES_MES_13 13 // TIME UP
#define GMES_MES_14 14
#define GMES_MES_15 15
#define GMES_MES_16 16
#define GMES_MES_MG_FINISH 17
#define GMES_MES_18 18
#define GMES_MES_19 19
#define GMES_MES_20 20
#define GMES_MES_21 21
#define GMES_MES_MG_WINNER 22
#define GMES_MES_MG_LOSER 23
#define GMES_MES_24 24
#define GMES_MES_25 25
#define GMES_MES_TIMER 26
#define GMES_MES_MG_RECORD 27
#define GMES_MES_28 28
#define GMES_MES_29 29 // GAME_OVER
#define GMES_MES_MG_WINNERS_2 30
#define GMES_MES_31 31 // TIME UP (ALT?)
#define GMES_MES_MG_DRAW 32
#define GMES_MES_33 33 // GOAL
#define GMES_MES_MG_WINNERS_3 34
#define GMES_MES_MG_WINNERS_4 35
#define GMES_MES_36 36 // GOT ITEM
#define GMES_MES_37 37 // GOT ITEM?

#define GMES_STAT_NONE 0
#define GMES_STAT_EXIST (1 << 0)
#define GMES_STAT_KILL (1 << 2)

s16 GMesCreate(s16 mesNo, ...);
s32 GMesStatGet(void);
void GMesClose(void);
void func_80037258_37E58(void);
void func_8003F578_40178(s16);
void func_8003F5C0_401C0(void);
void func_80045010_45C10(const s16*, s32);

#endif
