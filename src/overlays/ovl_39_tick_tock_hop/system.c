#include "overlays/ovl_39.h"
#include "gcc/memory.h"
#include "game/esprite.h"
#include "game/sprite.h"
#include "mallocblock.h"

#define FUNC_GRP_MAX 5
#define SPRITES_MAX 8
#define ANIMMDL_MAX 8
#define BILLS_MAX 2
#define COLLIDERS_MAX 2

#define VECMagXZ(a) sqrtf(((a)->x*(a)->x)+((a)->z*(a)->z))
#define M_ID(m, i, j) ((m)[(i) * 4 + (j)])

// 14EA0
void func_80017D24_18924(f32*, f32, f32, f32);

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

void m257_SortFuncGroup(FuncGroup* group);
s32 func_8010AD60_2C21D0_tick_tock_hop(HuSprite_Unk84_Struct* arg0, f32 arg1);
s32 func_8010B4D0_2C2940_tick_tock_hop(HuSprite_Unk84_Struct* arg0, f32 arg1);
void func_8010CCD4_2C4144_tick_tock_hop(u16 modelId, HuSprite_Unk84_Struct* arg1, u16 arg2);
s16 func_8010CED8_2C4348_tick_tock_hop(HuSprite_Unk84_Struct* arg0, HmfModelData_Unk64_Struct* arg1, f32 arg2, u16 arg3, u16 arg4);
void m257_UpdateColliders(FuncGroupContext* groupCtx, FuncContext* ctx);
f32 m257_CalcSideOfEdge(QuadCollider* collider, ModelTracker* model, Vec* a, Vec* b);

BillboardData* BSS m257_billboards;
FuncGroup* BSS m257_funcGroups;
SpriteData* BSS m257_sprites;
AnimModelData* BSS m257_animModels;
QuadCollider* BSS m257_colliders;

// TODO: the following arrays work but trigger multiple warnings: "missing braces around initializer"
// Ideally we should use these and remove the u32 arrays below.
/*
Gfx D_8010E4B0_2C5920_tick_tock_hop[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList()
};

Gfx D_8010E568_2C59D8_tick_tock_hop[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList()
};

Gfx D_8010E588_2C59F8_tick_tock_hop[] = {
    gsSPDisplayList(D_8010E568_2C59D8_tick_tock_hop),
    gsSPDisplayList(D_8010E4B0_2C5920_tick_tock_hop),
    gsSPEndDisplayList()
};

Gfx D_8010E5A0_2C5A10_tick_tock_hop[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_8010E588_2C59F8_tick_tock_hop),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList()
};
*/

u32 D_8010E4B0_2C5920_tick_tock_hop[] = {
    0xDB060000, 0x00000000, 0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xE3000800, 0x00800000,
    0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000C00, 0x00000000,
    0xF2000000, 0x00000000, 0xF2000000, 0x01000000, 0xF5000000, 0x00000000, 0xF5000000, 0x01000000,
    0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xFCFFFFFF, 0xFFFE793C, 0xE3001700, 0x00000000,
    0xE2001E01, 0x00000000, 0xE2001D00, 0x00000000, 0xE200001C, 0x0F0A4000, 0x00000000, 0x00000000,
    0xE3001801, 0x000000C0, 0xE7000000, 0x00000000, 0xDF000000, 0x00000000, 0xD9000000, 0x00000000,
    0xD7000000, 0x00000000, 0xD9FFFFFF, 0x00200004, 0xDF000000, 0x00000000, 0xDE000000, 0x8010E568,
    0xDE000000, 0x8010E4B0, 0xDF000000, 0x00000000
};

u32 D_8010E5A0_2C5A10_tick_tock_hop[] = {
    0xE7000000, 0x00000000, 0xDE000000, 0x8010E588, 0xE3000A01, 0x00000000, 0xD9FFFFFF, 0x00220401,
    0xF9000000, 0x00000000, 0xFA000000, 0x000000FF, 0xD7000002, 0xFFFFFFFF, 0xDF000000, 0x00000000
};

u8 m257_quadEdges[][3] = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } };

void m257_CreateSystem(void) {
    m257_sprites = HuMemAllocTag(SPRITES_MAX * sizeof(SpriteData), 31000);
    memset(m257_sprites, 0, SPRITES_MAX * sizeof(SpriteData));
    m257_animModels = HuMemAllocTag(ANIMMDL_MAX * sizeof(AnimModelData), 31000);
    memset(m257_animModels, 0, ANIMMDL_MAX * sizeof(AnimModelData));
    m257_billboards = HuMemAllocTag(BILLS_MAX * sizeof(BillboardData), 31000);
    memset(m257_billboards, 0, BILLS_MAX * sizeof(BillboardData));
    m257_funcGroups = HuMemAllocTag(5 * sizeof(FuncGroup), 31000);
}

FuncGroup* m257_CreateFuncGroup(omObjData* object, s8 groupId, s16 maxModels, s16 maxFuncs) {
    FuncGroup* group;

    if (groupId >= FUNC_GRP_MAX) {
        return NULL;
    }
    group = &m257_funcGroups[groupId];
    if (maxFuncs != 0) {
        group->funcCtx = HuMemAllocTag(maxFuncs * sizeof(FuncContext), 31000);
        memset(group->funcCtx, 0, maxFuncs * sizeof(FuncContext));
        group->order = HuMemAllocTag((maxFuncs + 1) * sizeof(FuncOrder), 31000);
    }
    group->maxFuncs = maxFuncs;
    group->groupCtx = HuMemAllocTag(sizeof(FuncGroupContext), 31000);
    if (maxModels != 0) {
        group->groupCtx->modelIds = HuMemAllocTag(maxModels * sizeof(s16), 31000);
        memset(group->groupCtx->modelIds, 0, maxModels * sizeof(s16));
    }
    group->groupCtx->maxModels = maxModels;
    group->sort = TRUE;
    group->groupCtx->object = object;
    return group;
}

s16 m257_SetFunc(s8 groupId, s32 prio, void* data, void (*func)(FuncGroupContext*, FuncContext*), s8 tag) {
    FuncGroup* group = &m257_funcGroups[groupId];
    FuncContext* ctx = group->funcCtx;
    s16 maxFuncs = group->maxFuncs;
    s16 i;

    for (i = 0; i < maxFuncs; i++, ctx++) {
        if (!ctx->set) {
            ctx->set = TRUE;
            ctx->prio = prio;
            ctx->id = i;
            ctx->tag = tag;
            ctx->state = 0;
            ctx->data = data;
            ctx->func = func;
            break;
        }
    }
    if (i == maxFuncs) {
        osSyncPrintf("SetFunc Error %d!\n", groupId);
        return -1;
    }
    group->sort = TRUE;
    return i;
}

void m257_ResetFunc(s8 groupId, FuncContext* ctx) {
    memset(ctx, 0, sizeof(FuncContext));
    m257_funcGroups[groupId].sort = TRUE;
}

void m257_ResetFuncTag(s8 groupId, s8 tag) {
    FuncGroup* group = &m257_funcGroups[groupId];
    FuncContext* ctx;
    s16 i;

    ctx = group->funcCtx;
    for (i = 0; i < group->maxFuncs; i++, ctx++) {
        if (ctx->tag == tag) {
            m257_ResetFunc(groupId, ctx);
        }
    }
}

void m257_ResetFuncGroup(s8 groupId) {
    FuncGroup* group = &m257_funcGroups[groupId];

    memset(group->funcCtx, 0, group->maxFuncs * sizeof(FuncContext));
    group->sort = TRUE;
}

void m257_UpdateFuncGroup(s8 groupId) {
    FuncGroup* group = &m257_funcGroups[groupId];
    FuncContext* ctx;
    s8 orderId;

    if (group->sort) {
        m257_SortFuncGroup(group);
    }
    orderId = 0;
    while (group->order[orderId].next != -1) {
        orderId = group->order[orderId].next;
        ctx = &group->funcCtx[group->order[orderId].id];
        if (ctx->set) {
            ctx->func(group->groupCtx, ctx);
        }
    }
}

void m257_SortFuncGroup(FuncGroup* group) {
    FuncOrder* order = group->order;
    FuncContext* currCtx = group->funcCtx;
    s16 orderId;
    s16 prevId;
    s16 i, j;

    order[0].next = -1;
    orderId = 1;
    for (i = 0; i < group->maxFuncs; i++, currCtx++) {
        if (!currCtx->set) {
            continue;
        }
        prevId = j = 0;
        while (order[j].next != -1) {
            j = order[j].next;
            if (order[j].prio < currCtx->prio) {
                prevId = j;
                break;
            }
        }
        order[orderId].id = i;
        order[orderId].prio = currCtx->prio;
        order[orderId].next = order[prevId].next;
        order[orderId].prev = prevId;
        order[prevId].next = orderId;
        if (order[orderId].next != -1) {
            order[order[orderId].next].prev = orderId;
        }
        orderId++;
    }
    group->sort = FALSE;
}

s16 m257_SetSprite(u16 prio, s32 dir, s32 file, u16 arg3, s32 attr) {
    SpriteData* sprite;
    HuSprite* temp_v0_2;
    s16 i;

    sprite = m257_sprites;
    for (i = 0; i < SPRITES_MAX; i++, sprite++) {
        if (sprite->state == SPRITE_STATE_NOTSET) {
            sprite->unk02 = func_8000B838_C438((dir << 16) | file); // esprite.
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
            m257_SetSpriteDispOff(i);
            break;
        }
    }
    return i;
}

void m257_SetSpriteDispOn(s16 spriteId, s32 posX, s32 posY) {
    SpriteData* sprite = &m257_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        func_80054FF8_55BF8(sprite->groupId, 0, 0);
        HuSprAttrReset(sprite->groupId, 0, 0x8000);
        func_80054904_55504(sprite->groupId, 0, posX, posY);
        sprite->state = SPRITE_STATE_VISIBLE;
    }
}

void m257_SetSpriteDispOff(s16 spriteId) {
    SpriteData* sprite = &m257_sprites[spriteId];

    if (sprite->state != SPRITE_STATE_NOTSET) {
        HuSprAttrSet(sprite->groupId, 0, 0x8000);
        sprite->state = SPRITE_STATE_INVISIBLE;
    }
}

void m257_UpdateSprites(void) {
    SpriteData* sprite;
    s16 i;

    sprite = m257_sprites;
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

s32 m257_SetAnimModel(s32 dir, s32 file, f32 freq, s32 attr, s32 arg4) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m257_animModels;
    for (i = 0; i < ANIMMDL_MAX; i++, animModel++) {
        if (!animModel->set) {
            animModel->modelId = func_8000B108_BD08((dir << 16) | file, arg4);
            func_8001C258_1CE58(animModel->modelId, 4, 4);
            hmfModel = &HmfModelData[animModel->modelId];
            hmfModel->unk40 = 0.0f;
            hmfModel->unk44 = 0.0f;
            if (hmfModel->unk64->unk98 != NULL) {
                hmfModel->unk64->unk98->unk08 = 0;
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

s32 m257_SetAnimModelDispOn(s16 animModelId, f32 posX, f32 posY, f32 posZ, f32 rotX, f32 rotY, f32 rotZ, f32 scale, f32 animStart) {
    AnimModelData* animModel;
    HmfModel* hmfModel;

    if (animModelId >= ANIMMDL_MAX) {
        return FALSE;
    }
    if (!m257_animModels[animModelId].set) {
        return FALSE;
    }
    animModel = &m257_animModels[animModelId];
    hmfModel = &HmfModelData[animModel->modelId];
    if ((hmfModel->unk18 & 4) && animModel->state == ANIMMDL_STATE_INVISIBLE) {
        Hu3DModelPosSet(animModel->modelId, posX, posY, posZ);
        Hu3DModelRotSet(animModel->modelId, rotX, rotY, rotZ);
        Hu3DModelScaleSet(animModel->modelId, scale, scale, scale);
        if (animStart == 0.0f) {
            func_8001C258_1CE58(animModel->modelId, 4, 0);
            animModel->state = ANIMMDL_STATE_ANIM;
            animModel->animStart = 0.0f;
            animModel->animTimer = 0.0f;
            hmfModel->unk44 = animModel->freq;
        } else {
            animModel->state = ANIMMDL_STATE_WAIT;
            animModel->animStart = animStart;
            animModel->animTimer = 0.0f;
        }
        return TRUE;
    }
    return FALSE;
}

void m257_UpdateAnimModels(void) {
    AnimModelData* animModel;
    HmfModel* hmfModel;
    s16 i;

    animModel = m257_animModels;
    for (i = 0; i < ANIMMDL_MAX; i++, animModel++) {
        if (!animModel->set || animModel->state == ANIMMDL_STATE_INVISIBLE) {
            continue;
        }
        hmfModel = &HmfModelData[animModel->modelId];
        switch (animModel->state) {
            default:
                if (D_800CCF58_CDB58[hmfModel->unk02].unk02 <= hmfModel->unk40) {
                    hmfModel->unk40 = 0.0f;
                    if (hmfModel->unk64->unk98 != NULL) {
                        hmfModel->unk64->unk98->unk08 = 0;
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

s32 m257_SetBill(s32 dir, s32 file, s32 attr) {
    BillboardData* bill;
    s16 temp_v0_2;
    s16 i;

    bill = m257_billboards;
    for (i = 0; i < BILLS_MAX; i++, bill++) {
        if (!bill->set) {
            bill->unk08 = temp_v0_2 = func_8000B838_C438((dir << 16) | file);
            if (attr & BILL_ATTR_01) {
                bill->modelId = func_8010B4D0_2C2940_tick_tock_hop(func_80055194_55D94(temp_v0_2), 1.0f);
            } else {
                bill->modelId = func_8010AD60_2C21D0_tick_tock_hop(func_80055194_55D94(temp_v0_2), 1.0f);
            }
            if (attr & BILL_ATTR_DISPOFF) {
                func_8001C258_1CE58(bill->modelId, 4, 4);
            }
            bill->posX = &HmfModelData[bill->modelId].pos.x;
            bill->posY = &HmfModelData[bill->modelId].pos.y;
            bill->posZ = &HmfModelData[bill->modelId].pos.z;
            bill->attr = attr;
            bill->duration = func_80055194_55D94(temp_v0_2)->unk10;
            bill->timer = 0;
            bill->set = TRUE;
            break;
        }
    }
    if (i == BILLS_MAX) {
        osSyncPrintf("SetBill Error! \n");
    }
    return i;
}

void m257_SetBillDispOn(s16 billId, f32 posX, f32 posY, f32 posZ) {
    if (billId < BILLS_MAX) {
        HmfModel* model = &HmfModelData[m257_billboards[billId].modelId];

        model->pos.x = posX;
        model->pos.y = posY;
        model->pos.z = posZ;
        func_8001C258_1CE58(m257_billboards[billId].modelId, 4, 0);
        m257_billboards[billId].attr &= ~(BILL_ATTR_DISPOFF | BILL_ATTR_REF);
    }
}

void m257_SetBillDispOnRef(s16 billId, f32* posX, f32* posY, f32* posZ) {
    if (billId < BILLS_MAX) {
        HmfModel* model = &HmfModelData[m257_billboards[billId].modelId];

        if (posX != NULL) {
            m257_billboards[billId].posX = posX;
        } else {
            m257_billboards[billId].posX = &model->pos.x;
        }
        if (posY != NULL) {
            m257_billboards[billId].posY = posY;
        } else {
            m257_billboards[billId].posY = &model->pos.y;
        }
        if (posZ != NULL) {
            m257_billboards[billId].posZ = posZ;
        } else {
            m257_billboards[billId].posZ = &model->pos.z;
        }
        func_8001C258_1CE58(m257_billboards[billId].modelId, 4, 0);
        m257_billboards[billId].attr &= ~(BILL_ATTR_DISPOFF | BILL_ATTR_REF);
        m257_billboards[billId].attr |= BILL_ATTR_REF;
    }
}

BillboardData* m257_GetBill(s16 billId) {
    if (billId >= BILLS_MAX) {
        return NULL;
    }
    return &m257_billboards[billId];
}

HmfModel* m257_GetBillModel(s16 billId) {
    if (billId >= BILLS_MAX) {
        return NULL;
    }
    return &HmfModelData[m257_billboards[billId].modelId];
}

void m257_UpdateBills(void) {
    BillboardData* bill;
    HmfModel* model;
    s16 i;

    bill = m257_billboards;
    for (i = 0; i < BILLS_MAX; i++, bill++) {
        if (!bill->set || (bill->attr & BILL_ATTR_DISPOFF)) {
            continue;
        }
        model = &HmfModelData[bill->modelId];
        if (bill->attr & BILL_ATTR_REF) {
            model->pos.x = *bill->posX;
            model->pos.y = *bill->posY;
            model->pos.z = *bill->posZ;
        }
        model->rot.x = CRot.x;
        model->rot.y = CRot.y;
        m257_MakeIdentityMtx(model->unk74);
        func_80017D24_18924(model->unk74, 0.0f, 0.0f, CRot.z);
        if (bill->attr & BILL_ATTR_01) {
            if (bill->attr & BILL_ATTR_ANIM) {
                func_8010CCD4_2C4144_tick_tock_hop(bill->modelId, func_80055194_55D94(bill->unk08), bill->timer);
                bill->timer++;
                if (bill->timer >= bill->duration) {
                    if (bill->attr & BILL_ATTR_LOOP) {
                        bill->timer = 0;
                    } else {
                        bill->timer = 0;
                        bill->attr |= BILL_ATTR_DISPOFF;
                        func_8001C258_1CE58(bill->modelId, 4, 4);
                    }
                }
            }
        }
    }
}

s32 func_8010AD60_2C21D0_tick_tock_hop(HuSprite_Unk84_Struct* arg0, f32 arg1) {
    HmfModelData_Unk64_Struct* temp_s6;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    u32 temp_s5;
    s32 temp_s0;
    s32 var_s7;
    s16 temp_v0_2;
    s16 var_s4;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s6 = HmfModelData[temp_v0_2].unk64;
    temp_s6->unk60->unk50 |= 0x01010000;
    temp_s5 = func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s6, 1.0f, 0, 0x64);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
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

s32 func_8010B4D0_2C2940_tick_tock_hop(HuSprite_Unk84_Struct* arg0, f32 arg1) {
    HmfModelData_Unk64_Struct* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    s32 temp_s0;
    s16 temp_v0_2;
    s16 var_a2;
    s16 var_s1;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0_2].unk64;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x14, D_800CDD6A_CE96A);
    func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s4, 1.0f, 0, 0x1E);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
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

s16 func_8010C0E8_2C3558_tick_tock_hop(HuSprite_Unk84_Struct* arg0, RGBA* arg1) {
    HmfModelData_Unk64_Struct* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0_2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s1;

    temp_v0_0 = temp_v0_2 = HuMemAlloc(0x10000);
    temp_v0 = func_8001A894_1B494(0x8C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0].unk64;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x18, D_800CDD6A_CE96A);
    func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s4, 1.0f, 0, 0);
    gSPDisplayList(temp_v0_2++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
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

void func_8010CCD4_2C4144_tick_tock_hop(u16 modelId, HuSprite_Unk84_Struct* arg1, u16 arg2) {
    HmfModel* model = &HmfModelData[modelId];
    HmfModelData_Unk64_Struct* temp_s2 = model->unk64;
    Gfx* temp_s0 = temp_s2->unk3C->unk04[D_800D2008_D2C08];

    temp_s2->unk3C->unk00 = temp_s0;
    gDPPipeSync(&temp_s0[0]);
    gSPSegment(&temp_s0[1], 0x02, osVirtualToPhysical(arg1->unk00[arg2].unk00));
    gSPDisplayList(&temp_s0[2], osVirtualToPhysical(temp_s2->unk3C->unk10));
    gDPPipeSync(&temp_s0[3]);
    gSPEndDisplayList(&temp_s0[4]);
}

void func_8010CDA4_2C4214_tick_tock_hop(u16 modelId, HuSprite_Unk84_Struct* arg1, u16 arg2, RGBA* arg3) {
    HmfModel* model = &HmfModelData[modelId];
    HmfModelData_Unk64_Struct* temp_s3 = model->unk64;
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

s16 func_8010CED8_2C4348_tick_tock_hop(HuSprite_Unk84_Struct* arg0, HmfModelData_Unk64_Struct* arg1, f32 arg2, u16 arg3, u16 arg4) {
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
    sp24 = (f64) (temp_s4 * 0x64) * arg2 / 32.0;
    temp_f2 = (f64) (temp_a1 * 0x64) * arg2 / 32.0;
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

void m257_CreateColliders(FuncGroupContext* groupCtx, FuncContext* ctx) {
    m257_colliders = HuMemAllocTag(COLLIDERS_MAX * sizeof(QuadCollider), 31000);
    memset(m257_colliders, 0, COLLIDERS_MAX * sizeof(QuadCollider));
    ctx->func = m257_UpdateColliders;
}

s32 m257_SetCollider(s16 modelId, Quad* baseQuad, f32 height, s16 maxTrackers, s32 attr) {
    HmfModel* model = &HmfModelData[modelId];
    QuadCollider* collider;
    s16 i;

    collider = m257_colliders;
    for (i = 0; i < COLLIDERS_MAX; i++, collider++) {
        if (!collider->set) {
            collider->posX = &model->pos.x;
            collider->posY = &model->pos.y;
            collider->posZ = &model->pos.z;
            collider->rotX = &model->rot.x;
            collider->rotY = &model->rot.y;
            collider->rotZ = &model->rot.z;
            collider->baseQuad = *baseQuad;
            collider->height = height;
            collider->vertexCount = 4;
            if (maxTrackers != 0) {
                collider->modelTrackers = HuMemAllocTag(maxTrackers * sizeof(ModelTracker), 31000);
            }
            collider->maxTrackers = maxTrackers;
            collider->trackerCount = 0;
            collider->attr = attr;
            collider->set = TRUE;
            break;
        }
    }
    if (i == COLLIDERS_MAX) {
        return -1;
    }
    return i;
}

ModelTracker* m257_SetModelTracker(s16 colliderId, s16 modelId) {
    ModelTracker* tracker;
    HmfModel* model;

    if (colliderId >= COLLIDERS_MAX) {
        return NULL;
    }
    if (!m257_colliders[colliderId].set) {
        return NULL;
    }
    if (m257_colliders[colliderId].trackerCount >= m257_colliders[colliderId].maxTrackers) {
        return NULL;
    }
    tracker = &m257_colliders[colliderId].modelTrackers[m257_colliders[colliderId].trackerCount];
    model = &HmfModelData[modelId];
    tracker->posX = &model->pos.x;
    tracker->posY = &model->pos.y;
    tracker->posZ = &model->pos.z;
    m257_colliders[colliderId].trackerCount++;
    return tracker;
}

void m257_SetColliderBaseQuad(s16 colliderId, Quad* baseQuad, f32 height) {
    if (colliderId < COLLIDERS_MAX && m257_colliders[colliderId].set) {
        QuadCollider* collider = &m257_colliders[colliderId];

        memcpy(&collider->baseQuad, baseQuad, collider->vertexCount * sizeof(Vec));
        collider->height = height;
    }
}

void m257_UpdateColliders(FuncGroupContext* groupCtx, FuncContext* ctx) {
    QuadCollider* collider;
    Vec currQuad[4];
    f32 side;
    s16 i, j, k;

    collider = m257_colliders;
    for (i = 0; i < COLLIDERS_MAX; i++, collider++) {
        if (!collider->set) {
            continue;
        }
        if (collider->attr & COLLIDER_ATTR_DISABLED) {
            for (j = 0; j < collider->trackerCount; j++) {
                collider->modelTrackers[j].colliding = FALSE;
            }
            continue;
        }
        m257_MakeTransformMtx(*collider->posX, *collider->posY, *collider->posZ, *collider->rotX, *collider->rotY, *collider->rotZ, collider->transMtx);
        m257_ApplyTransformMtx(collider->baseQuad.vertices, 4, collider->transMtx, currQuad);
        for (j = 0; j < collider->trackerCount; j++) {
            ModelTracker* model = &collider->modelTrackers[j];

            if (!(collider->attr & COLLIDER_ATTR_HEIGHT_DISABLED)) {
                if (*model->posY > collider->height) {
                    model->colliding = FALSE;
                    continue;
                }
            }
            side = m257_CalcSideOfEdge(collider, model, &currQuad[m257_quadEdges[0][0]], &currQuad[m257_quadEdges[0][1]]);
            if (side == 0.0f) {
                model->colliding = FALSE;
                continue;
            }
            if (side > 0.0f) {
                model->colliding = TRUE;
                for (k = 1; k < 4; k++) {
                    side = m257_CalcSideOfEdge(collider, model, &currQuad[m257_quadEdges[k][0]], &currQuad[m257_quadEdges[k][1]]);
                    if (side == 0.0f) {
                        model->colliding = TRUE;
                        break;
                    }
                    if (side < 0.0f) {
                        model->colliding = FALSE;
                        break;
                    }
                }
            } else {
                model->colliding = TRUE;
                for (k = 1; k < 4; k++) {
                    side = m257_CalcSideOfEdge(collider, model, &currQuad[m257_quadEdges[k][0]], &currQuad[m257_quadEdges[k][1]]);
                    if (side == 0.0f) {
                        model->colliding = TRUE;
                        break;
                    }
                    if (side > 0.0f) {
                        model->colliding = FALSE;
                        break;
                    }
                }
            }
        }
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
f32 m257_CalcSideOfEdge(QuadCollider* collider, ModelTracker* model, Vec* a, Vec* b) {
    Vec modelPos;
    Vec ma;
    Vec mb;

    modelPos.x = *model->posX;
    modelPos.z = *model->posZ;
    ma.x = a->x - modelPos.x;
    ma.z = a->z - modelPos.z;
    mb.x = b->x - modelPos.x;
    mb.z = b->z - modelPos.z;
    return ma.z * mb.x - ma.x * mb.z;
}

u8 m257_CalcLerp(f32* out, u8* timer, f32 start, f32 end, f32 duration) {
    f32 t = *timer / duration;

    *out = start + (end - start) * t;
    if (++(*timer) > duration) {
        *timer = 0;
        *out = end;
        return TRUE;
    }
    return FALSE;
}

f32 m257_CalcQuadraticBezier(f32 t, f32 p0, f32 p1, f32 p2) {
    if (t > 1.0f) {
        t = 1.0f;
    }
    return (1.0f - t) * (1.0f - t) * p0 + 2.0f * (1.0f - t) * t * p1 + t * t * p2;
}

// Fisher-Yates shuffle on [0, n-1].
void m257_MakeRandPermutation(s16* out, s16 n) {
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

void m257_SyncWithModel(omObjData* object) {
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

// TODO: doesn't work with -Wa,--vr4300mul-off.
void m257_CalcPitchAndYaw(Vec from, Vec to, f32* out) {
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

void m257_MinimizeAngleDiff(f32* a, f32* b) {
    f32 diff;

    while (*b < 0.0f) {
        *b += 360.0f;
    }
    while (*b >= 360.0f) {
        *b -= 360.0f;
    }
    while (*a < 0.0f) {
        *a += 360.0f;
    }
    while (*a >= 360.0f) {
        *a -= 360.0f;
    }
    diff = ABS(*b - *a);
    if (diff > 180.0f) {
        if (*a < *b) {
            *b -= 360.0f;
        } else {
            *a -= 360.0f;
        }
    }
}

void m257_MakeIdentityMtx(f32* out) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(out, i, j) = 0.0f;
        }
        M_ID(out, i, i) = 1.0f;
    }
}

void m257_MakeTranslationMtx(f32* out, f32 x, f32 y, f32 z) {
    m257_MakeIdentityMtx(out);
    M_ID(out, 3, 0) = x;
    M_ID(out, 3, 1) = y;
    M_ID(out, 3, 2) = z;
}

void m257_MakeRotXMtx(f32* out, f32 angle) {
    m257_MakeIdentityMtx(out);
    M_ID(out, 1, 1) = HuMathCos(angle);
    M_ID(out, 1, 2) = HuMathSin(angle);
    M_ID(out, 2, 1) = -HuMathSin(angle);
    M_ID(out, 2, 2) = HuMathCos(angle);
}

void m257_MakeRotYMtx(f32* out, f32 angle) {
    m257_MakeIdentityMtx(out);
    M_ID(out, 0, 0) = HuMathCos(angle);
    M_ID(out, 0, 2) = -HuMathSin(angle);
    M_ID(out, 2, 0) = HuMathSin(angle);
    M_ID(out, 2, 2) = HuMathCos(angle);
}

void m257_MultiplyMtx(f32* a, f32* b, f32* out) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(out, i, j) = M_ID(a, i, 0) * M_ID(b, 0, j) + M_ID(a, i, 1) * M_ID(b, 1, j) + M_ID(a, i, 2) * M_ID(b, 2, j) + M_ID(a, i, 3) * M_ID(b, 3, j);
        }
    }
}

void func_8010E214_2C5684_tick_tock_hop(f32* arg0, f32* out) {
    *(out++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 0) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 0) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 0);
    *(out++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 1) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 1) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 1);
    *(out++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 2) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 2) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 2);
}

void m257_MakeTransformMtx(f32 transX, f32 transY, f32 transZ, f32 rotX, f32 rotY, f32 rotZ, f32* out) {
    f32 translationMtx[16];
    f32 rotXMtx[16];
    f32 rotYMtx[16];
    f32 rotMtx[16];

    m257_MakeTranslationMtx(translationMtx, transX, transY, transZ);
    m257_MakeRotXMtx(rotXMtx, rotX);
    m257_MakeRotYMtx(rotYMtx, rotY);
    m257_MultiplyMtx(rotXMtx, rotYMtx, rotMtx);
    m257_MultiplyMtx(rotMtx, translationMtx, out);
}

void m257_ApplyTransformMtx(Vec* in, s16 n, f32* mtx, Vec* out) {
    s16 i;

    for (i = 0; i < n; i++) {
        out[i].x = (M_ID(mtx, 3, 0) + in[i].x) * M_ID(mtx, 0, 0) + (M_ID(mtx, 3, 1) + in[i].y) * M_ID(mtx, 1, 0) + (M_ID(mtx, 3, 2) + in[i].z) * M_ID(mtx, 2, 0);
        out[i].y = (M_ID(mtx, 3, 0) + in[i].x) * M_ID(mtx, 0, 1) + (M_ID(mtx, 3, 1) + in[i].y) * M_ID(mtx, 1, 1) + (M_ID(mtx, 3, 2) + in[i].z) * M_ID(mtx, 2, 1);
        out[i].z = (M_ID(mtx, 3, 0) + in[i].x) * M_ID(mtx, 0, 2) + (M_ID(mtx, 3, 1) + in[i].y) * M_ID(mtx, 1, 2) + (M_ID(mtx, 3, 2) + in[i].z) * M_ID(mtx, 2, 2);
    }
}
