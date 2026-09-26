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

extern s16 D_800ABF80_main;
extern s16 D_800ABF82_main;
extern s16 D_800ABF84_main;
extern u8 D_800ABF8A_main[];
extern u16 D_800CBB66_main[];
extern s16 D_800CDA7C_main[];
extern s16 D_800D056A_main[];
extern s16 D_800D1244_main[];
extern s16 D_800D1382_main[];
extern s16 gNumOfControllers;
extern s8 D_800D20A1_main[];
extern unkMesg D_800ABF00_main[];
extern s16 D_800ABF9C_main;
extern OSMesgQueue D_800ABFA0_main;
extern void* D_800ABFB8_main;

extern functionListEntry D_800ABF90_main;

extern OSContPad D_800ABE40_main[8];

extern s8 D_800ABF8E_main;
extern s8 D_800ABF8F_main;

extern s8 D_800ABF86_main[];

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