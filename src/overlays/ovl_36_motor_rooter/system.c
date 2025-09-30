#include "overlays/ovl_36.h"
#include "gcc/memory.h"
#include "game/esprite.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "mallocblock.h"

#define FUNC_GRP_MAX 6
#define FUNC_PRIO_MAX 10
#define SPRITES_MAX 52
#define ANIMMDL_MAX 0

#define VECMagXZ(a) sqrtf(((a)->x*(a)->x)+((a)->z*(a)->z))
#define M_ID(m, i, j) ((m)[(i) * 4 + (j)])

// EXTERN

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ s16 unk02;
    /* 0x04 */ char unk04[0x14];
} D_800CCF58_CDB58_Struct; // Size 0x18

extern D_800CCF58_CDB58_Struct* D_800CCF58_CDB58; // esprite

// 8EA10
f32 atan2d(f32, f32);

// 8EFF0
f32 HuMathCos(f32);

// 8FB20
f32 HuMathSin(f32);

// unknown
extern s16 D_800CDD6A_CE96A;
extern u8 D_800D2008_D2C08;

// LOCAL

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA;

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

void m254_InitFuncGroup(FuncGroup* group, s16 maxFuncs);
void m254_SortFuncGroup(FuncGroup* group);
s16 func_80110A00_2AC490_motor_rooter(HuSprite_Unk84_Struct* arg0, HmfData* arg1, f32 arg2, u16 arg3, u16 arg4);

extern SpriteData* m254_sprites;
extern AnimModelData* m254_animModels;
extern FuncGroup* m254_funcGroups;

extern Gfx D_801135A0_2AF030_motor_rooter[];

void m254_CreateSystem(void) {
    s8 maxFuncs[FUNC_GRP_MAX] = { 4, 4, 4, 2, 8, 8 };
    s16 i;

    m254_sprites = HuMemAllocTag(SPRITES_MAX * sizeof(SpriteData), 31000);
    memset(m254_sprites, 0, SPRITES_MAX * sizeof(SpriteData));
    m254_funcGroups = HuMemAllocTag(FUNC_GRP_MAX * sizeof(FuncGroup), 31000);
    for (i = 0; i < FUNC_GRP_MAX; i++) {
        m254_InitFuncGroup(&m254_funcGroups[i], maxFuncs[i]);
    }
}

void m254_InitFuncGroup(FuncGroup* group, s16 maxFuncs) {
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

FuncContext* m254_SetFunc(s8 groupId, s8 prio, s16 param, void* data, void (*func)(FuncContext*), s8 tag, s8 execFunc) {
    FuncGroup* group = &m254_funcGroups[groupId];
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
            ctx->tag = tag;
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
    group->sort = TRUE;
    return ctx;
}

void m254_ResetFunc(s8 groupId, FuncContext* ctx) {
    s8 next = ctx->next;

    memset(ctx, 0, sizeof(FuncContext));
    ctx->next = next;
    m254_funcGroups[groupId].sort = TRUE;
}

void m254_ResetFuncTag(s8 groupId, s8 tag) {
    FuncGroup* group = &m254_funcGroups[groupId];
    FuncContext* ctx;
    s16 i;

    ctx = group->funcCtx;
    for (i = 0; i < group->maxFuncs; i++, ctx++) {
        if (ctx->tag == tag) {
            m254_ResetFunc(groupId, ctx);
        }
    }
}

void m254_ResetFuncGroup(s8 groupId) {
    FuncGroup* group = &m254_funcGroups[groupId];
    s8 i = 0;

    memset(group->funcCtx, 0, group->maxFuncs * sizeof(FuncContext));
    memset(group->order, -1, sizeof(group->order));
    for (i = 0; i < group->maxFuncs; i++) {
        group->funcCtx[i].next = -1;
    }
}

void m254_UpdateFuncGroup(s8 groupId) {
    FuncGroup* group = &m254_funcGroups[groupId];
    FuncContext* ctx = group->funcCtx;
    s8 i;

    if (group->sort) {
        m254_SortFuncGroup(group);
    }
    for (i = 0; i < FUNC_PRIO_MAX; i++) {
        s8 funcId = group->order[i];

        while (funcId != -1) {
            group->funcCtx[funcId].func(&ctx[funcId]);
            funcId = group->funcCtx[funcId].next;
        }
    }
}

void m254_SortFuncGroup(FuncGroup* group) {
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

s16 m254_SetSprite(u16 prio, s32 dir, s32 file, u16 arg3, s32 attr) {
    SpriteData* sprite;
    HuSprite* temp_v0_2;
    s16 i;

    sprite = m254_sprites;
    for (i = 0; i < SPRITES_MAX; i++, sprite++) {
        if (sprite->state == SPRITE_STATE_NOTSET) {
            sprite->unk02 = func_8000B838_C438((dir << 16) | file);
            sprite->groupId = HuSprGrpCreate(1, 0);
            sprite->unk06 = 0xFF;
            HuSprAttrReset(sprite->groupId, 0, -1);
            func_80055024_55C24(sprite->groupId, 0, sprite->unk02, 0);
            HuSprAttrSet(sprite->groupId, 0, attr);
            func_800550F4_55CF4(sprite->groupId, 0, arg3);
            HuSprPriSet(sprite->groupId, 0, prio);
            func_80054FF8_55BF8(sprite->groupId, 0, 0);
            func_800550B4_55CB4(sprite->groupId, 0, 1.0f);
            HuSprScaleSet(sprite->groupId, 0, 1.0f, 1.0f);
            func_80054904_55504(sprite->groupId, 0, 100, 100);
            temp_v0_2 = HuSprGet(sprite->groupId, 0);
            if (arg3 == 0) {
                sprite->unk04 = 99;
            } else {
                sprite->unk04 = temp_v0_2->unk_84->unk10;
            }
            sprite->state = SPRITE_STATE_VISIBLE;
            m254_SetSpriteDispOff(i);
            break;
        }
    }
    return i;
}

void m254_SetSpriteDispOn(s16 spriteId, s32 posX, s32 posY) {
    SpriteData* sprite = &m254_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        func_80054FF8_55BF8(sprite->groupId, 0, 0);
        HuSprAttrReset(sprite->groupId, 0, 0x8000);
        func_80054904_55504(sprite->groupId, 0, posX, posY);
        sprite->state = SPRITE_STATE_VISIBLE;
    }
}

void m254_SetSpriteDispOff(s16 spriteId) {
    SpriteData* sprite = &m254_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        HuSprAttrSet(sprite->groupId, 0, 0x8000);
        sprite->state = SPRITE_STATE_INVISIBLE;
    }
}

void m254_UpdateSprites(void) {
    SpriteData* sprite;
    s16 i;

    sprite = m254_sprites;
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

s32 m254_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m254_animModels;
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

s32 m254_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart) {
    AnimModelData* animModel;
    HmfModel* HmfModel;

    if (animModelId >= ANIMMDL_MAX) {
        return FALSE;
    }
    if (!m254_animModels[animModelId].set) {
        return FALSE;
    }
    animModel = &m254_animModels[animModelId];
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

void m254_UpdateAnimModels(void) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m254_animModels;
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

// Similar to func_8010AD60_2C21D0_tick_tock_hop (ovl_39/M257)
s16 func_8010E888_2AA318_motor_rooter(HuSprite_Unk84_Struct* arg0, f32 arg1) {
    HmfData* temp_s6;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    u32 temp_s5;
    s32 temp_s0;
    s32 var_s7;
    s16 temp_v0_2;
    s16 var_s4;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s6 = HmfModelData[temp_v0_2].hmf;
    temp_s6->unk60->unk50 |= 0x01010000;
    temp_s5 = func_80110A00_2AC490_motor_rooter(arg0, temp_s6, 1.0f, 0, 0x14);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_801135A0_2AF030_motor_rooter));
    gDPPipeSync(temp_v0++);
    gDPSetCycleType(temp_v0++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0++);
    gSPClearGeometryMode(temp_v0++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetColorDither(temp_v0++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0++, G_AC_NONE);
    gDPSetBlendColor(temp_v0++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0++);
    gDPSetRenderMode(temp_v0++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    gDPPipeSync(temp_v0++);
    gSPTexture(temp_v0++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0++, G_TT_RGBA16);
        var_s7 = 0x800;
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0++, arg0->unk0C);
        }
    } else {
        gDPSetTextureLUT(temp_v0++, G_TT_NONE);
        var_s7 = 0x1000;
    }
    gDPPipeSync(temp_v0++);
    for (var_s4 = 0; var_s4 < temp_s5; var_s4++) {
        gSPSegment(temp_v0++, 0x02, osVirtualToPhysical(arg0->unk08 + var_s7 * var_s4));
        gDPLoadTextureBlock(temp_v0++, 0x02000000, G_IM_FMT_CI, G_IM_SIZ_8b,
            arg0->unk00->unk04, arg0->unk00->unk06 / temp_s5, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(temp_v0++);
        gSPSegment(temp_v0++, 0x01, osVirtualToPhysical(&temp_s6->unk44[0][var_s4 * 4]));
        gSPVertex(temp_v0++, 0x01000000, 4, 0);
        gSP2Triangles(temp_v0++, 0, 1, 2, 0, 1, 3, 2, 0);
    }
    gSPClearGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0++);
    gSPEndDisplayList(temp_v0++);
    temp_s0 = (u32) temp_v0 - (u32) temp_v0_0;
    temp_s6->unk3C->unk00 = HuMemAllocTag(temp_s0, temp_s6->unk0E);
    bcopy(temp_v0_0, temp_s6->unk3C->unk00, temp_s0);
    HuMemFree(temp_v0_0);
    return temp_v0_2;
}

// Similar to func_8010B4D0_2C2940_tick_tock_hop (ovl_39/M257)
s16 func_8010EFF8_2AAA88_motor_rooter(HuSprite_Unk84_Struct* arg0, f32 arg1) {
    HmfData* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    s32 temp_s0;
    s16 temp_v0_2;
    s16 var_a2;
    s16 var_s1;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0_2].hmf;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x14, D_800CDD6A_CE96A);
    func_80110A00_2AC490_motor_rooter(arg0, temp_s4, 1.0f, 0, 6);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_801135A0_2AF030_motor_rooter));
    gDPPipeSync(temp_v0++);
    gDPSetCycleType(temp_v0++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0++);
    gSPClearGeometryMode(temp_v0++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(temp_v0++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0++, G_AC_NONE);
    gDPSetBlendColor(temp_v0++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0++);
    gDPSetRenderMode(temp_v0++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (arg0->unk1A >= 2) {
        gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    } else {
        if (arg0->unk18 & 0x8000) {
            gDPSetCombineLERP(temp_v0++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        } else {
            gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        }
        gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    }
    gDPPipeSync(temp_v0++);
    gSPTexture(temp_v0++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0++, G_TT_RGBA16);
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0++, arg0->unk0C);
        }
        gDPPipeSync(temp_v0++);
        var_a2 = 2;
    } else {
        gDPSetTextureLUT(temp_v0++, G_TT_NONE);
        gDPPipeSync(temp_v0++);
        var_a2 = (arg0->unk18 & 0x8000) ? 4 : 0;
    }
    switch (arg0->unk18 & 0xFFF) {
        case 4:
            gDPLoadTextureBlock_4b(temp_v0++, 0x02000000, var_a2,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 8:
            gDPLoadTextureBlock(temp_v0++, 0x02000000, var_a2, G_IM_SIZ_8b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 16:
            gDPLoadTextureBlock(temp_v0++, 0x02000000, var_a2, G_IM_SIZ_16b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
    }
    gDPPipeSync(temp_v0++);
    gSPSegment(temp_v0++, 0x01, osVirtualToPhysical(temp_s4->unk44[0]));
    gSPVertex(temp_v0++, 0x01000000, 4, 0);
    gSP2Triangles(temp_v0++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0++);
    gSPEndDisplayList(temp_v0++);
    temp_s0 = (u32) temp_v0 - (u32) temp_v0_0;
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk10 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk00, temp_s0);
    HuMemFree(temp_v0_0);
    for (var_s1 = 0; var_s1 < D_800D1FF0_D2BF0; var_s1++) {
        temp_v0 = *(temp_s4->unk3C->unk04 + var_s1) = HuMemAllocTag(0x100, temp_s4->unk0E);
        gDPPipeSync(temp_v0++);
        gSPSegment(temp_v0++, 0x02, osVirtualToPhysical(arg0->unk00->unk00));
        gSPDisplayList(temp_v0++, osVirtualToPhysical(temp_s4->unk3C->unk10));
        gSPEndDisplayList(temp_v0++);
    }
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk04[D_800D2008_D2C08];
    return temp_v0_2;
}

// Identical to func_8010C0E8_2C3558_tick_tock_hop (ovl_39/M257)
s16 func_8010FC10_2AB6A0_motor_rooter(HuSprite_Unk84_Struct* arg0, RGBA* arg1) {
    HmfData* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0_2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s1;

    temp_v0_0 = temp_v0_2 = HuMemAlloc(0x10000);
    temp_v0 = func_8001A894_1B494(0x8C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0].hmf;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x18, D_800CDD6A_CE96A);
    func_80110A00_2AC490_motor_rooter(arg0, temp_s4, 1.0f, 0, 0);
    gSPDisplayList(temp_v0_2++, osVirtualToPhysical(D_801135A0_2AF030_motor_rooter));
    gDPPipeSync(temp_v0_2++);
    gDPSetCycleType(temp_v0_2++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0_2++);
    gSPClearGeometryMode(temp_v0_2++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0_2++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(temp_v0_2++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0_2++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0_2++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0_2++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0_2++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0_2++, G_AC_NONE);
    gDPSetBlendColor(temp_v0_2++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0_2++);
    gDPSetRenderMode(temp_v0_2++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (arg0->unk18 & 0x8000) {
        gDPSetCombineLERP(temp_v0_2++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    } else {
        gDPSetCombineLERP(temp_v0_2++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    }
    gDPPipeSync(temp_v0_2++);
    gSPEndDisplayList(temp_v0_2++);
    temp_s0 = (u32) temp_v0_2 - (u32) temp_v0_0;
    temp_s4->unk3C->unk10 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk10, temp_s0);
    HuMemFree(temp_v0_0);
    temp_v0_0 = temp_v0_2 = HuMemAlloc(0x10000);
    gSPTexture(temp_v0_2++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0_2++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0_2++, G_TT_RGBA16);
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0_2++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0_2++, arg0->unk0C);
        }
        gDPPipeSync(temp_v0_2++);
        var_a2 = 2;
    } else {
        gDPSetTextureLUT(temp_v0_2++, G_TT_NONE);
        gDPPipeSync(temp_v0_2++);
        var_a2 = (arg0->unk18 & 0x8000) ? 4 : 0;
    }
    switch (arg0->unk18 & 0xFFF) {
        case 4:
            gDPLoadTextureBlock_4b(temp_v0_2++, 0x02000000, var_a2,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 8:
            gDPLoadTextureBlock(temp_v0_2++, 0x02000000, var_a2, G_IM_SIZ_8b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 16:
            gDPLoadTextureBlock(temp_v0_2++, 0x02000000, var_a2, G_IM_SIZ_16b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
    }
    gDPPipeSync(temp_v0_2++);
    gSPSegment(temp_v0_2++, 0x01, osVirtualToPhysical(temp_s4->unk44[0]));
    gSPVertex(temp_v0_2++, 0x01000000, 4, 0);
    gSP2Triangles(temp_v0_2++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(temp_v0_2++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0_2++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0_2++);
    gSPEndDisplayList(temp_v0_2++);
    temp_s0 = (u32) temp_v0_2 - (u32) temp_v0_0;
    temp_s4->unk3C->unk14 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk14, temp_s0);
    HuMemFree(temp_v0_0);
    for (var_s1 = 0; var_s1 < D_800D1FF0_D2BF0; var_s1++) {
        temp_v0_2 = temp_s4->unk3C->unk04[var_s1] = HuMemAllocTag(0x100, temp_s4->unk0E);
        gDPPipeSync(temp_v0_2++);
        gSPSegment(temp_v0_2++, 0x02, osVirtualToPhysical(arg0->unk00->unk00));
        gSPDisplayList(temp_v0_2++, osVirtualToPhysical(temp_s4->unk3C->unk10));
        gDPSetPrimColor(temp_v0_2++, 0, 0, arg1->r, arg1->g, arg1->b, arg1->a);
        gDPPipeSync(temp_v0_2++);
        gSPDisplayList(temp_v0_2++, osVirtualToPhysical(temp_s4->unk3C->unk14));
        gDPPipeSync(temp_v0_2++);
        gSPEndDisplayList(temp_v0_2++);
    }
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk04[D_800D2008_D2C08];
    return temp_v0;
}

// Identical to func_8010CCD4_2C4144_tick_tock_hop (ovl_39/M257)
void func_801107FC_2AC28C_motor_rooter(u16 modelId, HuSprite_Unk84_Struct* arg1, u16 arg2) {
    HmfModel* model = &HmfModelData[modelId];
    HmfData* temp_s2 = model->hmf;
    Gfx* temp_s0 = temp_s2->unk3C->unk04[D_800D2008_D2C08];

    temp_s2->unk3C->unk00 = temp_s0;
    gDPPipeSync(&temp_s0[0]);
    gSPSegment(&temp_s0[1], 0x02, osVirtualToPhysical(arg1->unk00[arg2].unk00));
    gSPDisplayList(&temp_s0[2], osVirtualToPhysical(temp_s2->unk3C->unk10));
    gDPPipeSync(&temp_s0[3]);
    gSPEndDisplayList(&temp_s0[4]);
}

// Identical to func_801108CC_2AC35C_motor_rooter (ovl_39/M257)
void func_801108CC_2AC35C_motor_rooter(u16 modelId, HuSprite_Unk84_Struct* arg1, u16 arg2, RGBA* arg3) {
    HmfModel* model = &HmfModelData[modelId];
    HmfData* temp_s3 = model->hmf;
    HmfModelData_Unk64_Unk3C_Struct* temp_v1 = temp_s3->unk3C;
    Gfx* temp_s0 = temp_v1->unk04[D_800D2008_D2C08];

    temp_v1->unk00 = temp_s0;
    gDPPipeSync(&temp_s0[0]);
    gSPSegment(&temp_s0[1], 0x02, osVirtualToPhysical(arg1->unk00[arg2].unk00));
    gSPDisplayList(&temp_s0[2], osVirtualToPhysical(temp_s3->unk3C->unk10));
    gDPSetPrimColor(&temp_s0[3], 0, 0, arg3->r, arg3->g, arg3->b, arg3->a);
    gDPPipeSync(&temp_s0[4]);
    gSPDisplayList(&temp_s0[5], osVirtualToPhysical(temp_s3->unk3C->unk14));
    gDPPipeSync(&temp_s0[6]);
    gSPEndDisplayList(&temp_s0[7]);
}

// Similar to func_8010CED8_2C4348_tick_tock_hop (ovl_39/M257)
s16 func_80110A00_2AC490_motor_rooter(HuSprite_Unk84_Struct* arg0, HmfData* arg1, f32 arg2, u16 arg3, u16 arg4) {
    Vtx* temp_s7;
    Vtx* var_s1;
    Vtx_t* var_t0;
    Vtx_t* var_a3;
    s32 var_a2;
    s32 temp_s4;
    s32 temp_a1;
    s32 sp24;
    s32 temp_f2;
    s32 var_s0;
    s32 var_s2;
    s32 sp2C;
    s32 temp_lo;
    s32 temp_s3;
    s32 var_s0_2;
    s32 var_a2_2;

    if (arg0->unk1A >= 2) {
        var_a2 = 0x800;
    } else {
        var_a2 = 0x1000;
    }
    temp_s4 = arg0->unk00->unk04;
    temp_a1 = arg0->unk00->unk06;
    sp24 = temp_s4 * 20.0 * arg2 / 32.0;
    temp_f2 = temp_a1 * 20.0 * arg2 / 32.0;
    if ((arg0->unk18 & 0xFFF) == 4) {
        var_s0 = ((temp_s4 + 1) & 0xFFFE) * temp_a1 * 4;
    } else {
        var_s0 = temp_s4 * temp_a1 * arg0->unk18;
    }
    var_s0 = (var_s0 < 0) ? (var_s0 + 7) : var_s0;
    var_s0 >>= 3;
    var_s2 = var_s0 / var_a2;
    if (var_s2 <= 0) {
        var_s2 = 1;
    }
    sp2C = temp_a1 / var_s2;
    temp_lo = temp_f2 / var_s2;
    temp_s3 = var_s2 * 4;
    temp_s7 = var_s1 = HuMemAllocTag(temp_s3 * sizeof(Vtx), arg1->unk0E);
    memset(temp_s7, 0, temp_s3 * sizeof(Vtx));
    for (var_s0_2 = 0; var_s0_2 < var_s2; var_s0_2++, var_s1 += 4) {
        var_s1[0].v.ob[0] = (s32) (sp24 * 0.5);
        var_s1[0].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * var_s0_2);
        var_s1[0].v.tc[0] = (temp_s4 - 1) * 64;
        var_s1[0].v.tc[1] = 0;
        var_s1[1].v.ob[0] = (s32) (sp24 * 0.5);
        var_s1[1].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * (var_s0_2 + 1));
        var_s1[1].v.tc[0] = (temp_s4 - 1) * 64;
        var_s1[1].v.tc[1] = (sp2C - 1) * 64;
        var_s1[2].v.ob[0] = (s32) -(sp24 * 0.5);
        var_s1[2].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * var_s0_2);
        var_s1[2].v.tc[0] = 0;
        var_s1[2].v.tc[1] = 0;
        var_s1[3].v.ob[0] = (s32) -(sp24 * 0.5);
        var_s1[3].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * (var_s0_2 + 1));
        var_s1[3].v.tc[0] = 0;
        var_s1[3].v.tc[1] = (sp2C - 1) * 64;
        for (var_a2_2 = 0; var_a2_2 < 4; var_a2_2++) {
            var_s1[var_a2_2].v.ob[0] += arg3;
            var_s1[var_a2_2].v.ob[1] += arg4;
            var_s1[var_a2_2].v.ob[2] = 0;
            var_s1[var_a2_2].v.flag = 0;
            var_s1[var_a2_2].v.cn[3] = 0xFF;
            var_s1[var_a2_2].v.cn[0] = var_s1[var_a2_2].v.cn[1] = var_s1[var_a2_2].v.cn[2] = 0;
        }
    }
    var_s1 = temp_s7;
    for (var_s0_2 = 0; var_s0_2 < D_800D1FF0_D2BF0; var_s0_2++) {
        arg1->unk44[var_s0_2] = HuMemAllocTag(temp_s3 * sizeof(Vtx), arg1->unk0E);
        var_t0 = &arg1->unk44[var_s0_2]->v;
        var_a3 = &var_s1->v;
        for (var_a2_2 = 0; var_a2_2 < temp_s3; var_a2_2++) {
            *(var_t0++) = *(var_a3++);
        }
    }
    HuMemFree(temp_s7);
    return var_s2;
}

u8 m254_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration) {
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
f32 m254_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2) {
    if (t > 1.0f) {
        t = 1.0f;
    }
    return (1.0f - t) * (1.0f - t) * p0 + 2.0f * (1.0f - t) * t * p1 + t * t * p2;
}

// Fisher-Yates shuffle on [0, n-1].
void m254_MakeRandPermutation(s16* out, s16 n) {
    s16 temp;
    s16 i;

    for (i = 0; i < n; i++) {
        out[i] = i;
    }
    for (i = n - 1; i >= 0; i--) {
        s16 rand = rand16() % (i + 1);

        temp = out[i];
        out[i] = out[rand];
        out[rand] = temp;
    }
}

void m254_SyncWithModel(omObjData* object) {
    HmfModel* model = &HmfModelData[object->model[0]];

    object->scale.x = model->scale.x;
    object->scale.y = model->scale.y;
    object->scale.z = model->scale.z;
    object->trans.x = model->pos.x;
    object->trans.y = model->pos.y;
    object->trans.z = model->pos.z;
    if (model->rot.x >= 360.0f) {
        model->rot.x -= 360.0f;
    }
    if (model->rot.x < 0.0f) {
        model->rot.x += 360.0f;
    }
    if (model->rot.y >= 360.0f) {
        model->rot.y -= 360.0f;
    }
    if (model->rot.y < 0.0f) {
        model->rot.y += 360.0f;
    }
    if (model->rot.z >= 360.0f) {
        model->rot.z -= 360.0f;
    }
    if (model->rot.z < 0.0f) {
        model->rot.z += 360.0f;
    }
    object->rot.x = model->rot.x;
    object->rot.y = model->rot.y;
    object->rot.z = model->rot.z;
}

void m254_CalcPitchAndYaw(Vec from, Vec to, f32* out) {
    Vec direction;
    f32 fullRot = 360.0f;
    f32 pitch;
    f32 yaw;

    direction.x = to.x - from.x;
    direction.y = to.y - from.y;
    direction.z = to.z - from.z;
    pitch = atan2d(direction.y, VECMagXZ(&direction));
    if (pitch < 0.0f) {
        pitch += fullRot;
    } else if (pitch >= fullRot) {
        pitch -= fullRot;
    }
    *(out++) = pitch;
    yaw = atan2d(direction.x, direction.z);
    if (yaw < 0.0f) {
        yaw += fullRot;
    } else if (yaw >= fullRot) {
        yaw -= fullRot;
    }
    *(out++) = yaw;
}

void m254_MakeIdentityMtx(f32* out) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(out, i, j) = 0.0f;
        }
        M_ID(out, i, i) = 1.0f;
    }
}

void m254_MakeRotXMtx(f32* out, f32 angle) {
    m254_MakeIdentityMtx(out);
    M_ID(out, 1, 1) = HuMathCos(angle);
    M_ID(out, 1, 2) = HuMathSin(angle);
    M_ID(out, 2, 1) = -HuMathSin(angle);
    M_ID(out, 2, 2) = HuMathCos(angle);
}

void m254_MakeRotYMtx(f32* out, f32 angle) {
    m254_MakeIdentityMtx(out);
    M_ID(out, 0, 0) = HuMathCos(angle);
    M_ID(out, 0, 2) = -HuMathSin(angle);
    M_ID(out, 2, 0) = HuMathSin(angle);
    M_ID(out, 2, 2) = HuMathCos(angle);
}

void m254_MultiplyMtx(f32* a, f32* b, f32* out) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(out, i, j) = M_ID(a, i, 0) * M_ID(b, 0, j) + M_ID(a, i, 1) * M_ID(b, 1, j) + M_ID(a, i, 2) * M_ID(b, 2, j) + M_ID(a, i, 3) * M_ID(b, 3, j);
        }
    }
}

void func_801114B0_2ACF40_motor_rooter(f32* arg0, Vec* arg1, f32* out) {
    *(out++) = arg1->x * M_ID(arg0, 0, 0) + arg1->y * M_ID(arg0, 1, 0) + arg1->z * M_ID(arg0, 2, 0);
    *(out++) = arg1->x * M_ID(arg0, 0, 1) + arg1->y * M_ID(arg0, 1, 1) + arg1->z * M_ID(arg0, 2, 1);
    *(out++) = arg1->x * M_ID(arg0, 0, 2) + arg1->y * M_ID(arg0, 1, 2) + arg1->z * M_ID(arg0, 2, 2);
}
