#include "overlays/ovl_37.h"
#include "gcc/memory.h"
#include "game/esprite.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/util.h"
#include "mallocblock.h"

#define FUNC_GRP_MAX 6
#define FUNC_PRIO_MAX 10
#define SPRITES_MAX 1
#define ANIMMDL_MAX 0

// EXTERN

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ s16 unk02;
    /* 0x04 */ char unk04[0x14];
} D_800CCF58_CDB58_Struct; // Size 0x18

extern D_800CCF58_CDB58_Struct* D_800CCF58_CDB58; // esprite

// LOCAL

typedef struct {
    /* 0x00 */ FuncContext* funcCtx;
    /* 0x04 */ s8 maxFuncs;
    /* 0x05 */ u8 sort;
    /* 0x06 */ s8 order[FUNC_PRIO_MAX];
} FuncGroup; // Size 0x10

#define SPRITE_STATE_NOTSET 0
#define SPRITE_STATE_INVISIBLE 1
#define SPRITE_STATE_VISIBLE 2

typedef struct {
    /* 0x00 */ s8 state;
    /* 0x01 */ u8 groupId;
    /* 0x02 */ u8 unk02;
    /* 0x04 */ u16 unk04;
} SpriteData; // Size 6

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

void m255_InitFuncGroup(FuncGroup* group, s16 maxFuncs);
void m255_SortFuncGroup(FuncGroup* group);

SpriteData* BSS m255_sprites;
FuncGroup* BSS m255_funcGroups;
AnimModelData* BSS m255_animModels;

void m255_CreateSystem(void) {
    s8 maxFuncs[FUNC_GRP_MAX] = { 6, 4, 3, 3, 8, 8 };
    s16 i;

    m255_sprites = HuMemAllocTag(SPRITES_MAX * sizeof(SpriteData), 31000);
    memset(m255_sprites, 0, SPRITES_MAX * sizeof(SpriteData));
    m255_funcGroups = HuMemAllocTag(FUNC_GRP_MAX * sizeof(FuncGroup), 31000);
    for (i = 0; i < FUNC_GRP_MAX; i++) {
        m255_InitFuncGroup(&m255_funcGroups[i], maxFuncs[i]);
    }
}

void m255_InitFuncGroup(FuncGroup* group, s16 maxFuncs) {
    s16 i;

    group->funcCtx = HuMemAllocTag(maxFuncs * sizeof(FuncContext), 31000);
    memset(group->funcCtx, 0, maxFuncs * sizeof(FuncContext));
    memset(group->order, -1, sizeof(group->order));
    for (i = 0; i < maxFuncs; i++) {
        group->funcCtx[i].next = -1;
    }
    group->sort = FALSE;
    group->maxFuncs = maxFuncs;
}

FuncContext* m255_SetFunc(s8 groupId, s8 prio, s16 param, void* data, void (*func)(FuncContext*), u8 sort, s8 execFunc) {
    FuncGroup* group = &m255_funcGroups[groupId];
    FuncContext* ctx = group->funcCtx;
    s16 i = 0;
    s16 maxFuncs = group->maxFuncs;

    for (i = 0; i < maxFuncs; i++, ctx++) {
        if (!ctx->set) {
            ctx->set = TRUE;
            if (prio > FUNC_PRIO_MAX - 1) {
                prio = FUNC_PRIO_MAX - 1;
            }
            ctx->prio = prio;
            ctx->id = i;
            ctx->param = param;
            ctx->state = 0;
            ctx->data = data;
            ctx->func = func;
            break;
        }
    }
    if (i == maxFuncs) {
        osSyncPrintf("SetFunc Error %d!\n", groupId);
    }
    if (execFunc) {
        ctx->func(ctx);
    }
    if (sort) {
        m255_SortFuncGroup(group);
        group->sort = FALSE;
    } else {
        group->sort = TRUE;
    }
    return ctx;
}

void m255_ResetFunc(s8 groupId, FuncContext* ctx) {
    s8 next = ctx->next;

    memset(ctx, 0, sizeof(FuncContext));
    ctx->next = next;
    m255_funcGroups[groupId].sort = TRUE;
}

void m255_ResetFuncGroup(s8 groupId) {
    FuncGroup* group = &m255_funcGroups[groupId];
    s8 i = 0;

    memset(group->funcCtx, 0, group->maxFuncs * sizeof(FuncContext));
    memset(group->order, -1, sizeof(group->order));
    for (i = 0; i < group->maxFuncs; i++) {
        group->funcCtx[i].next = -1;
    }
}

void m255_UpdateFuncGroup(s8 groupId) {
    FuncGroup* group = &m255_funcGroups[groupId];
    FuncContext* ctx = group->funcCtx;
    s8 i;

    if (group->sort) {
        m255_SortFuncGroup(group);
    }
    for (i = 0; i < FUNC_PRIO_MAX; i++) {
        s8 funcId = group->order[i];

        while (funcId != -1) {
            group->funcCtx[funcId].func(&ctx[funcId]);
            funcId = group->funcCtx[funcId].next;
        }
    }
}

void m255_SortFuncGroup(FuncGroup* group) {
    FuncContext* currCtx = group->funcCtx;
    s8 prio;
    s8 i;

    for (i = 0; i < FUNC_PRIO_MAX; i++) {
        group->order[i] = -1;
    }
    for (i = 0; i < group->maxFuncs; i++, currCtx++) {
        if (!currCtx->set) {
            continue;
        }
        prio = currCtx->prio;
        currCtx->next = group->order[prio];
        group->order[prio] = i;
    }
    group->sort = FALSE;
}

s16 m255_SetSprite(s32 dir, s32 file, u16 arg2, s32 attr) {
    SpriteData* sprite;
    HuSprite* temp_v0_2;
    s16 i;

    sprite = m255_sprites;
    for (i = 0; i < SPRITES_MAX; i++, sprite++) {
        if (sprite->state == SPRITE_STATE_NOTSET) {
            sprite->unk02 = func_8000B838_C438((dir << 16) | file);
            sprite->groupId = HuSprGrpCreate(1, 0);
            HuSprAttrReset(sprite->groupId, 0, -1);
            func_80055024_55C24(sprite->groupId, 0, sprite->unk02, 0);
            HuSprAttrSet(sprite->groupId, 0, attr);
            func_800550F4_55CF4(sprite->groupId, 0, arg2);
            HuSprPriSet(sprite->groupId, 0, 0xFFF0);
            func_80054FF8_55BF8(sprite->groupId, 0, 0);
            func_800550B4_55CB4(sprite->groupId, 0, 1.0f);
            HuSprScaleSet(sprite->groupId, 0, 1.0f, 1.0f);
            func_80054904_55504(sprite->groupId, 0, 100, 100);
            temp_v0_2 = HuSprGet(sprite->groupId, 0);
            if (arg2 == 0) {
                sprite->unk04 = 99;
            } else {
                sprite->unk04 = temp_v0_2->unk_84->unk10;
            }
            sprite->state = SPRITE_STATE_INVISIBLE;
            break;
        }
    }
    return i;
}

void m255_SetSpriteDispOn(s16 spriteId, s32 posX, s32 posY) {
    SpriteData* sprite = &m255_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        func_80054FF8_55BF8(sprite->groupId, 0, 0);
        HuSprAttrReset(sprite->groupId, 0, 0x8000);
        func_80054904_55504(sprite->groupId, 0, posX, posY);
        sprite->state = SPRITE_STATE_VISIBLE;
    }
}

void m255_SetSpriteDispOff(s16 spriteId) {
    SpriteData* sprite = &m255_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        HuSprAttrSet(sprite->groupId, 0, 0x8000);
        sprite->state = SPRITE_STATE_INVISIBLE;
    }
}

void m255_UpdateSprites(void) {
    SpriteData* sprite;
    s16 i;

    sprite = m255_sprites;
    for (i = 0; i < SPRITES_MAX; i++, sprite++) {
        switch (sprite->state) {
            case SPRITE_STATE_VISIBLE:
                if (HuSprGet(sprite->groupId, 0)->unk_90 + 1 >= sprite->unk04) {
                    HuSprAttrSet(sprite->groupId, 0, 0x8000);
                    func_80054FF8_55BF8(sprite->groupId, 0, 0);
                }
                break;
        }
    }
}

s32 m255_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m255_animModels;
    for (i = 0; i < ANIMMDL_MAX; i++, animModel++) {
        if (!animModel->set) {
            animModel->modelId = func_8000B108_BD08((dir << 16) | file, arg4);
            func_8001C258_1CE58(animModel->modelId, 4, 4);
            hmfModel = &HmfModelData[animModel->modelId];
            hmfModel->unk40 = 0.0f;
            hmfModel->unk44 = 0.0f;
            if (hmfModel->hmf->unk98 != NULL) {
                hmfModel->hmf->unk98->unk08 = 0;
            }
            animModel->attr = attr;
            animModel->freq = freq;
            animModel->state = ANIMMDL_STATE_INVISIBLE;
            animModel->set = TRUE;
            break;
        }
    }
    return i;
}

s32 m255_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart) {
    AnimModelData* animModel;
    HmfModel* HmfModel;

    if (animModelId >= ANIMMDL_MAX) {
        return FALSE;
    }
    if (!m255_animModels[animModelId].set) {
        return FALSE;
    }
    animModel = &m255_animModels[animModelId];
    HmfModel = &HmfModelData[animModel->modelId];
    if ((HmfModel->unk18 & 4) && animModel->state == ANIMMDL_STATE_INVISIBLE) {
        Hu3DModelPosSet(animModel->modelId, posX, posY, posZ);
        Hu3DModelRotSet(animModel->modelId, rotX, rotY, rotZ);
        Hu3DModelScaleSet(animModel->modelId, scale, scale, scale);
        if (animStart == 0.0f) {
            func_8001C258_1CE58(animModel->modelId, 4, 0);
            animModel->state = ANIMMDL_STATE_ANIM;
            animModel->animStart = 0.0f;
            animModel->animTimer = 0.0f;
            HmfModel->unk44 = animModel->freq;
        } else {
            animModel->state = ANIMMDL_STATE_WAIT;
            animModel->animStart = animStart;
            animModel->animTimer = 0.0f;
        }
        return TRUE;
    }
    return FALSE;
}

void m255_UpdateAnimModels(void) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m255_animModels;
    for (i = 0; i < ANIMMDL_MAX; i++, animModel++) {
        if (!animModel->set || animModel->state == ANIMMDL_STATE_INVISIBLE) {
            continue;
        }
        hmfModel = &HmfModelData[animModel->modelId];
        switch (animModel->state) {
            default:
                if (D_800CCF58_CDB58[hmfModel->unk02].unk02 <= hmfModel->unk40) {
                    hmfModel->unk40 = 0.0f;
                    if (hmfModel->hmf->unk98 != NULL) {
                        hmfModel->hmf->unk98->unk08 = 0;
                    }
                    if (!(animModel->attr & ANIMMDL_ATTR_DISPON)) {
                        func_8001C258_1CE58(animModel->modelId, 4, 4);
                        animModel->state = ANIMMDL_STATE_INVISIBLE;
                        hmfModel->unk44 = 0.0f;
                    }
                }
                break;
            case ANIMMDL_STATE_WAIT:
                if (animModel->animStart <= animModel->animTimer++) {
                    func_8001C258_1CE58(animModel->modelId, 4, 0);
                    animModel->state = ANIMMDL_STATE_ANIM;
                    hmfModel->unk44 = animModel->freq;
                }
                break;
        }
    }
}

u8 m255_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration) {
    f32 t = *timer / duration;

    *out = start + (end - start) * t;
    if (++(*timer) > duration) {
        *timer = 0;
        *out = end;
        return TRUE;
    }
    return FALSE;
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
f32 m255_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2) {
    f32 u = 1.0f - t;
    f32 ret;

    ret = u * u * p0;
    ret += 2.0f * u * t * p1;
    ret += u * u * p2; // Bug? Should be t * t * p2.
    return ret;
}

void m255_SyncWithModel(omObjData* object) {
    object->trans.x = HmfModelData[object->model[0]].pos.x;
    object->trans.y = HmfModelData[object->model[0]].pos.y;
    object->trans.z = HmfModelData[object->model[0]].pos.z;
    object->rot.x = HmfModelData[object->model[0]].rot.x;
    object->rot.y = HmfModelData[object->model[0]].rot.y;
    object->rot.z = HmfModelData[object->model[0]].rot.z;
}
