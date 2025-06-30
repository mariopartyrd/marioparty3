#ifndef _OVL_37_H
#define _OVL_37_H

#include "ultra64.h"

#include "game/object.h"

#define BSS __attribute__((section(".bss")))

typedef struct {
    /* 0x00 */ s8 s8[16];
    /* 0x10 */ s16 s16[8];
    /* 0x20 */ f32 f32[4];
} Work; // Size 0x30

typedef struct func_context {
    /* 0x00 */ s8 set;
    /* 0x02 */ s16 id;
    /* 0x04 */ s8 state;
    /* 0x06 */ s16 param;
    /* 0x08 */ s8 prio;
    /* 0x09 */ s8 next;
    /* 0x0C */ Work work;
    /* 0x3C */ void* data;
    /* 0x40 */ void (*func)(struct func_context*);
} FuncContext; // Size 0x44

void m255_CreateSystem(void);

FuncContext* m255_SetFunc(s8 groupId, s8 prio, s16 param, void* data, void (*func)(FuncContext*), u8 sort, s8 execFunc);
void m255_ResetFunc(s8 groupId, FuncContext* ctx);
void m255_ResetFuncGroup(s8 groupId);
void m255_UpdateFuncGroup(s8 groupId);

s16 m255_SetSprite(s32 dir, s32 file, u16 arg2, s32 attr);
void m255_SetSpriteDispOn(s16 spriteId, s32 x, s32 y);
void m255_SetSpriteDispOff(s16 spriteId);
void m255_UpdateSprites(void);

s32 m255_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4);
s32 m255_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart);
void m255_UpdateAnimModels(void);

u8 m255_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration);
f32 m255_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2);
void m255_SyncWithModel(omObjData* object);

#endif
