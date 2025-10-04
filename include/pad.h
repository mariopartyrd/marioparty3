#ifndef __PAD_H
#define __PAD_H

#include "common.h"
#include "siman.h"
#include "input.h"

#define PAD_NOT_INSERTED 0

typedef struct {
    OSContPad pad;
    s32 unk[4];
} HuPad;

extern s16 D_800ABF80_ACB80;
extern s16 D_800ABF82_ACB82;
extern s16 D_800ABF84_ACB84;
extern u8 D_800ABF8A_ACB8A[];
extern u16 D_800CBB66_CC766[];
extern s16 D_800CDA7C_CE67C[];
extern s16 D_800D056A_D116A[];
extern s16 D_800D1244_D1E44[];
extern s16 D_800D1382_D1F82[];
extern s16 gNumOfControllers;
extern s8 D_800D20A1_D2CA1[];
extern unkMesg D_800ABF00_ACB00[];
extern s16 D_800ABF9C_ACB9C;
extern OSMesgQueue D_800ABFA0_ACBA0;
extern void* D_800ABFB8_ACBB8;

extern functionListEntry D_800ABF90_ACB90;

extern OSContPad D_800ABE40_ACA40[8];

extern s8 D_800ABF8E_ACB8E;
extern s8 D_800ABF8F_ACB8F;

extern s8 D_800ABF86_ACB86[];

s32 _InitController(u16* channel);
s16 InitController(s16 ch, s32 arg1);
s32 _ReadController(s32 arg0);
void SetStickValueLimit(s8 arg0, s8 arg1);
s16 UpdateController(void);
void _AutoReadController(void);
void SetAutoReadController(void);
void ResetAutoReadController(void);
s32 CheckControllerRead(s16 padNum);

#endif