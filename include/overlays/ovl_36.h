#ifndef _OVL_36_H
#define _OVL_36_H

#include "ultra64.h"

#include "game/object.h"
#include "game/util.h"

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
    /* 0x08 */ s8 tag;
    /* 0x09 */ s8 prio;
    /* 0x0A */ s8 next;
    /* 0x0C */ Work work;
    /* 0x3C */ void* data;
    /* 0x40 */ void (*func)(struct func_context*);
} FuncContext; // Size 0x44

void m254_CreateSystem(void);

FuncContext* m254_SetFunc(s8 groupId, s8 prio, s16 param, void* data, void (*func)(FuncContext*), s8 tag, s8 execFunc);
void m254_ResetFunc(s8 groupId, FuncContext* ctx);
void m254_ResetFuncTag(s8 groupId, s8 tag);
void m254_ResetFuncGroup(s8 groupId);
void m254_UpdateFuncGroup(s8 groupId);

s16 m254_SetSprite(u16 prio, s32 dir, s32 file, u16 arg3, s32 attr);
void m254_SetSpriteDispOn(s16 spriteId, s32 posX, s32 posY);
void m254_SetSpriteDispOff(s16 spriteId);
void m254_UpdateSprites(void);

s32 m254_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4);
s32 m254_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart);
void m254_UpdateAnimModels(void);

u8 m254_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration);
f32 m254_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2);
void m254_MakeRandPermutation(s16* out, s16 n);
void m254_SyncWithModel(omObjData* object);
void m254_CalcPitchAndYaw(Vec from, Vec to, f32* out);

void m254_MakeIdentityMtx(f32* out);
void m254_MakeRotXMtx(f32* out, f32 angle);
void m254_MakeRotYMtx(f32* out, f32 angle);
void m254_MultiplyMtx(f32* a, f32* b, f32* out);
void func_801114B0_2ACF40_motor_rooter(f32* arg0, Vec* arg1, f32* out);

#endif
