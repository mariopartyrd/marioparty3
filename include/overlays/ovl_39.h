#ifndef _OVL_39_H
#define _OVL_39_H

#include "ultra64.h"
#include "math.h"

#include "game/hmfman.h"
#include "game/object.h"
#include "game/util.h"

#define BSS __attribute__((section(".bss")))

#define ABS(x) ((x) > 0 ? (x) : -(x))

// EXTERN

//also defined in variables.h
typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ s16 unk02;
    /* 0x04 */ char unk04[0x14];
} D_800CCF58_CDB58_Struct; // Size 0x18

extern D_800CCF58_CDB58_Struct* D_800CCF58_CDB58; // esprite

// LOCAL

typedef struct {
    /* 0x00 */ s8 s8[16];
    /* 0x10 */ s16 s16[8];
    /* 0x20 */ f32 f32[4];
} Work; // Size 0x30

typedef struct {
    /* 0x00 */ omObjData* object;
    /* 0x04 */ s16* modelIds;
    /* 0x08 */ s16 maxModels;
} FuncGroupContext; // Size 0xC

typedef struct func_context {
    /* 0x00 */ s8 set;
    /* 0x02 */ s16 id;
    /* 0x04 */ s8 state;
    /* 0x05 */ s8 tag;
    /* 0x08 */ s32 prio;
    /* 0x0C */ Work work;
    /* 0x3C */ void* data;
    /* 0x40 */ void (*func)(FuncGroupContext*, struct func_context*);
} FuncContext; // Size 0x44

typedef struct {
    /* 0x00 */ u32 prio;
    /* 0x04 */ s16 next;
    /* 0x06 */ s16 prev;
    /* 0x08 */ s16 id;
} FuncOrder; // Size 0xC

typedef struct {
    /* 0x00 */ FuncGroupContext* groupCtx;
    /* 0x04 */ FuncContext* funcCtx;
    /* 0x08 */ s16 maxFuncs;
    /* 0x0C */ FuncOrder* order;
    /* 0x10 */ s8 sort;
} FuncGroup; // Size 0x14

#define SPRITE_STATE_NOTSET 0
#define SPRITE_STATE_INVISIBLE 1
#define SPRITE_STATE_VISIBLE 2

typedef struct {
    /* 0x00 */ s8 state;
    /* 0x01 */ u8 groupId;
    /* 0x02 */ u8 unk02;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ s16 unk06;
} SpriteData; // Size 8

#define ANIMMDL_ATTR_DISPON 1

#define ANIMMDL_STATE_INVISIBLE -1
#define ANIMMDL_STATE_WAIT 0
#define ANIMMDL_STATE_ANIM 1

typedef struct {
    /* 0x00 */ s8 set;
    /* 0x04 */ s32 attr;
    /* 0x08 */ s8 state;
    /* 0x0A */ s16 modelId;
    /* 0x0C */ f32 freq;
    /* 0x10 */ f32 animTimer;
    /* 0x14 */ f32 animStart;
} AnimModelData; // Size 0x18

#define BILL_ATTR_01 1
#define BILL_ATTR_ANIM 2
#define BILL_ATTR_LOOP 4
#define BILL_ATTR_DISPOFF 8
#define BILL_ATTR_REF 0x10

typedef struct {
    /* 0x00 */ s8 set;
    /* 0x04 */ s32 attr;
    /* 0x08 */ u8 unk08;
    /* 0x0A */ s16 modelId;
    /* 0x0C */ s16 duration;
    /* 0x0E */ s16 timer;
    /* 0x10 */ f32* posX;
    /* 0x14 */ f32* posY;
    /* 0x18 */ f32* posZ;
} BillboardData; // Size 0x1C

typedef struct {
    /* 0x00 */ u8 colliding;
    /* 0x04 */ f32* posX;
    /* 0x08 */ f32* posY;
    /* 0x0C */ f32* posZ;
} ModelTracker; // Size 0x10

typedef struct {
    /* 0x00 */ Vec vertices[4];
} Quad; // Size 0x30

#define COLLIDER_ATTR_ENABLED 0
#define COLLIDER_ATTR_DISABLED 1
#define COLLIDER_ATTR_HEIGHT_DISABLED 4

typedef struct {
    /* 0x00 */ s32 attr;
    /* 0x04 */ s8 set;
    /* 0x08 */ f32* posX;
    /* 0x0C */ f32* posY;
    /* 0x10 */ f32* posZ;
    /* 0x14 */ f32* rotX;
    /* 0x18 */ f32* rotY;
    /* 0x1C */ f32* rotZ;
    /* 0x20 */ f32 transMtx[16];
    /* 0x60 */ Quad baseQuad;
    /* 0x90 */ s16 vertexCount;
    /* 0x94 */ f32 height;
    /* 0x98 */ ModelTracker* modelTrackers;
    /* 0x9C */ s16 maxTrackers;
    /* 0x9E */ s16 trackerCount;
} QuadCollider; // Size 0xA0

void m257_CreateSystem(void);

FuncGroup* m257_CreateFuncGroup(omObjData* object, s8 groupId, s16 maxModels, s16 maxFuncs);
s16 m257_SetFunc(s8 groupId, s32 prio, void* data, void (*func)(FuncGroupContext*, FuncContext*), s8 tag);
void m257_ResetFunc(s8 groupId, FuncContext* ctx);
void m257_ResetFuncTag(s8 groupId, s8 tag);
void m257_ResetFuncGroup(s8 groupId);
void m257_UpdateFuncGroup(s8 groupId);

s16 m257_SetSprite(u16 prio, s32 dir, s32 file, u16 arg3, s32 attr);
void m257_SetSpriteDispOn(s16 spriteId, s32 posX, s32 posY);
void m257_SetSpriteDispOff(s16 spriteId);
void m257_UpdateSprites(void);

s32 m257_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4);
s32 m257_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart);
void m257_UpdateAnimModels(void);

s32 m257_SetBill(s32 dir, s32 file, s32 attr);
void m257_SetBillDispOn(s16 billId, f32 posX, f32 posY, f32 posZ);
void m257_SetBillDispOnRef(s16 billId, f32* posX, f32* posY, f32* posZ);
BillboardData* m257_GetBill(s16 billId);
HmfModel* m257_GetBillModel(s16 billId);
void m257_UpdateBills(void);

void m257_CreateColliders(FuncGroupContext* groupCtx, FuncContext* ctx);
s32 m257_SetCollider(s16 modelId, Quad* baseQuad, f32 height, s16 maxTrackers, s32 attr);
ModelTracker* m257_SetModelTracker(s16 colliderId, s16 modelId);
void m257_SetColliderBaseQuad(s16 colliderId, Quad* baseQuad, f32 height);

u8 m257_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration);
f32 m257_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2);
void m257_MakeRandPermutation(s16* out, s16 n);
void m257_SyncWithModel(omObjData* object);
void m257_CalcPitchAndYaw(Vec from, Vec to, f32* out);
void m257_MinimizeAngleDiff(f32* a, f32* b);

void m257_MakeIdentityMtx(f32* out);
void m257_MakeTranslationMtx(f32* out, f32 x, f32 y, f32 z);
void m257_MakeRotXMtx(f32* out, f32 angle);
void m257_MakeRotYMtx(f32* out, f32 angle);
void m257_MultiplyMtx(f32* a, f32* b, f32* out);
void func_8010E214_2C5684_tick_tock_hop(f32* arg0, f32* out);
void m257_MakeTransformMtx(f32 transX, f32 transY, f32 transZ, f32 rotX, f32 rotY, f32 rotZ, f32* out);
void m257_ApplyTransformMtx(Vec* in, s16 n, f32* mtx, Vec* out);

extern BillboardData* m257_billboards;
extern FuncGroup* m257_funcGroups;
extern SpriteData* m257_sprites;
extern AnimModelData* m257_animModels;
extern QuadCollider* m257_colliders;

#endif
