#include "common.h"
#include "malloc.h"
#include "F9DE0.h"
#include "105D50.h"
#include "FA250.h"
#include "ECA50.h"
#include "EC3B0.h"
#include "1006F0.h"

typedef struct UnkObj {
    Object *unk_00;
    f32 unk_04;
} UnkObj;

typedef struct UnkTemp {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
} UnkTemp; //sizeof 0x10

extern UnkTemp D_80100850_114470_shared_board[];
extern Object* D_80102AB0_1166D0_shared_board;
extern u16 D_80102AB4_1166D4_shared_board;
extern u8 D_800D6A90_D7690;
extern s16 D_80102AB8_1166D8_shared_board[128];

static void func_800D93C0_ECFE0_shared_board(omObjData *playerObj);
static void func_800D95D0_ED1F0_shared_board(omObjData* arg0);

static void func_800D8E30_ECA50_shared_board(void) {
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_80102AB8_1166D8_shared_board); i++) {
        D_80102AB8_1166D8_shared_board[i] = 0;
    }
}

static s16 MBMotionLock(s16 arg0) {
    D_80102AB8_1166D8_shared_board[arg0]++;
    return arg0;
}

s16 func_800D8E88_ECAA8_shared_board(s32 arg0) {
    s16 res = func_8001F1FC_1FDFC(DataRead(arg0), 8);
    D_80102AB8_1166D8_shared_board[res]++;
    return res;
}

void MBMotionKill(s16 arg0) {
    if (arg0 != -1) {
        if (D_80102AB8_1166D8_shared_board[arg0] != 0) {
            D_80102AB8_1166D8_shared_board[arg0]--;
            if (D_80102AB8_1166D8_shared_board[arg0] == 0) {
                func_8002D4B8_2E0B8(arg0);
            }
        }
    }
}

static s16 func_800D8F30_ECB50_shared_board(s16 arg0) {
    if (D_80102AB8_1166D8_shared_board[arg0] != 0){
        D_80102AB8_1166D8_shared_board[arg0]++;
        return arg0;
    }
    return -1;
}

void MBModelInit(void) {
    D_80102AB0_1166D0_shared_board = NULL;
    D_80102AB4_1166D4_shared_board = 0;
    D_80105706_119326_shared_board = 1;
    func_800D8E30_ECA50_shared_board();
    func_800D95C4_ED1E4_shared_board(100.0f);
}

void MBModelClose(void) {
    while (D_80102AB0_1166D0_shared_board != NULL) {
        MBModelKill(D_80102AB0_1166D0_shared_board);
    }
}

static Object *func_800D9004_ECC24_shared_board(void) {
    Object *temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(Object));
    if (temp_v0 != NULL) {
        D_80102AB4_1166D4_shared_board++;
        temp_v0->prev = D_80102AB0_1166D0_shared_board;
        temp_v0->next = NULL;
        if (D_80102AB0_1166D0_shared_board != NULL) {
            D_80102AB0_1166D0_shared_board->next = temp_v0;
        }
        D_80102AB0_1166D0_shared_board = temp_v0;
        temp_v0->flags = 8;
        HuVecCopyXYZ(&temp_v0->coords, 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&temp_v0->rot, 0.0f, 0.0f, 1.0f);
        HuVecCopyXYZ(&temp_v0->scale, 1.0f, 1.0f, 1.0f);
        temp_v0->velocity.x = 0.0f;
        temp_v0->velocity.y = 0.0f;
        temp_v0->velocity.z = 0.0f;
        temp_v0->unk44 = -1;
        temp_v0->unk46 = -1;
    }
    return temp_v0;
}

Object* MBModelCreate(u8 arg0, u32* arg1) {
    Object* temp_v0;

    temp_v0 = MBModelFileCreate(
        D_80100850_114470_shared_board[arg0].unk_00,
        D_80100850_114470_shared_board[arg0].unk_04,
        D_80100850_114470_shared_board[arg0].unk_08,
        D_80100850_114470_shared_board[arg0].unk_0C, arg1);
    temp_v0->unk8 = arg0;
    return temp_v0;
}

Object *MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32 *arg4) {
    Object *object;
    omObjData *objData;
    UnkObj *work;
    HmfModel *model;
    u32 *dataPtr;
    s16 mdlIdx;
    s16 motionCnt;
    s16 i;
    u8 temp;

    dataPtr = arg4;
    motionCnt = 0;

    object = func_800D9004_ECC24_shared_board();
    if (object != NULL) {
        object->unk8 = 0xFF;

        if (dataPtr != NULL) {
            motionCnt = dataPtr[0];
            dataPtr++;
        }

        objData = object->omObj1 = omAddObj(0x4000, 1, motionCnt, -1, func_800D93C0_ECFE0_shared_board);

        mdlIdx = func_8000B108_BD08(arg0, 0x6A9);
        omSetStatBit(objData, 0x80);
        objData->model[0] = mdlIdx;
        omSetRot(objData, 0.0f, 0.0f, 0.0f);
        func_8001C814_1D414(mdlIdx, 2, 2);
        func_8001C8A8_1D4A8(mdlIdx, 1);
        Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);
        if (HmfModelData[mdlIdx].unk02 != 0xFF) {
            object->unk44 = MBMotionLock(HmfModelData[mdlIdx].unk02);
        }

        work = HuMemMemoryAllocTemp(sizeof(UnkObj));
        objData->data = work;
        work->unk_00 = object;
        work->unk_04 = arg2;

        for (i = 0; i < motionCnt; i++) {
            objData->motion[i] = func_800D8E88_ECAA8_shared_board(*dataPtr++);
        }

        if ((arg1 >= 0) && (arg3 > 0.0f)) {
            objData = object->omObj2 = omAddObj(0x4000, 1, 0, -1, func_800D95D0_ED1F0_shared_board);
            mdlIdx = func_8000B108_BD08(arg1, 0x229);
            omSetStatBit(objData, 0x80);
            objData->model[0] = mdlIdx;
            omSetRot(objData, 0.0f, 0.0f, 0.0f);
            func_8001C8A8_1D4A8(mdlIdx, 1);
            Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);

            work = HuMemMemoryAllocTemp(sizeof(UnkObj));
            objData->data = work;
            work->unk_00 = object;
            work->unk_04 = arg3;
        } else {
            object->omObj2 = NULL;
        }
    }
    return object;
}

static void func_800D93C0_ECFE0_shared_board(omObjData *playerObj) {
    f32 sp10[2];
    Object *temp_s0;
    UnkObj *temp_s2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    temp_s2 = playerObj->data;
    temp_s0 = temp_s2->unk_00;

    if ((D_800D6A90_D7690 == 0) || (temp_s0->flags & 0x10)) {
        if (temp_s0->velocity.z != 0.0f) {
            temp_s0->velocity.y += temp_s0->velocity.z;
            temp_s0->velocity.x = temp_s0->velocity.x + temp_s0->velocity.y;
            if (temp_s0->velocity.x < 0.0f) {
                temp_s0->velocity.x = 0.0f;
                temp_s0->velocity.y = 0.0f;
                temp_s0->velocity.z = 0.0f;
            }
        }
    }

    if (!(temp_s0->flags & 4)) {
        playerObj->rot.y = MBVecAngleGet(&temp_s0->rot);
    }

    playerObj->trans.x = temp_s0->coords.x;
    playerObj->trans.y = temp_s0->coords.y + temp_s0->velocity.x;
    playerObj->trans.z = temp_s0->coords.z;
    playerObj->scale.x = temp_s0->scale.x * temp_s2->unk_04 * MBBackMdlScaleGet();
    playerObj->scale.y = temp_s0->scale.y * temp_s2->unk_04 * MBBackMdlScaleGet();
    playerObj->scale.z = temp_s0->scale.z * temp_s2->unk_04 * MBBackMdlScaleGet();

    if (!(D_80105706_119326_shared_board & 1)) {
        MBModelAttrSetDispOff(temp_s0);
        return;
    }

    if (!(temp_s0->flags & 8)) {
        MBModelAttrSetDispOff(temp_s0);
        return;
    }

    if (temp_s0->flags & 2) {
        MBCamera3Dto2D(&temp_s0->coords, sp10);
        if ((sp10[0] > 370.0f) ||
            (sp10[0] < -50.0f) ||
            (sp10[1] > 290.0f) ||
            (sp10[1] < -20.0f)) {
            MBModelAttrSetDispOff(temp_s0);
            return;
        }
    }
    MBModelAttrSetDispOn(temp_s0);
}

extern f32 D_80100D40_114960_shared_board;

void func_800D95C4_ED1E4_shared_board(f32 arg0) {
    D_80100D40_114960_shared_board = arg0;
}

static void func_800D95D0_ED1F0_shared_board(omObjData* arg0) {
    f32 var_f20;
    Object* temp_s0;
    UnkObj* temp_s2;

    temp_s2 = (UnkObj*)arg0->data;
    temp_s0 = temp_s2->unk_00;
    var_f20 = 1.0f;
    arg0->rot.y = MBVecAngleGet(&temp_s0->rot);
    if (temp_s0->flags & 1) {
        var_f20 = 0.0f;
    } else {
        if (temp_s0->velocity.x != 0.0f) {
            var_f20 = 1.0f - (temp_s0->velocity.x / D_80100D40_114960_shared_board);
            if (var_f20 <= 0.0f) {
                var_f20 = 0.0f;
            }
            if (var_f20 >= 1.0f) {
                var_f20 = 1.0f;
            }
        }
    }
    arg0->scale.x = var_f20 * temp_s0->scale.x * temp_s2->unk_04 * MBBackMdlScaleGet();
    arg0->scale.y = MBBackMdlScaleGet();
    arg0->scale.z = var_f20 * temp_s0->scale.z * temp_s2->unk_04 * MBBackMdlScaleGet();
    arg0->trans.x = temp_s0->coords.x;
    arg0->trans.y = temp_s0->coords.y;
    arg0->trans.z = temp_s0->coords.z;
}

void MBModelTempAllocFree(Object* arg0) {
    func_8001C514_1D114(arg0->omObj1->model[0]);
    
    if (arg0->omObj2 != NULL) {
        func_8001C514_1D114(arg0->omObj2->model[0]);
    }
}

Object *MBModelLinkCreate(Object *src) {
    Object *object;
    omObjData *objData;
    UnkObj *work;
    HmfModel *model;
    s16 mdlIdx;
    s16 i;

    object = func_800D9004_ECC24_shared_board();
    if (object != NULL) {
        object->unk8 = src->unk8;

        objData = object->omObj1 = omAddObj(0x4000, 1, src->omObj1->mtncnt, -1, func_800D93C0_ECFE0_shared_board);

        mdlIdx = Hu3DModelLink(src->omObj1->model[0]);
        omSetStatBit(objData, 0x80);
        objData->model[0] = mdlIdx;
        omSetRot(objData, 0.0f, 0.0f, 0.0f);
        func_8001C814_1D414(mdlIdx, 2, 2);
        func_8001C8A8_1D4A8(mdlIdx, 1);
        Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);

        if (HmfModelData[mdlIdx].unk02 != 0xFF) {
            object->unk44 = func_800D8F30_ECB50_shared_board(HmfModelData[mdlIdx].unk02);
        }

        work = HuMemMemoryAllocTemp(sizeof(UnkObj));
        objData->data = work;
        work->unk_00 = object;
        if (object->unk8 != 0xFF) {
            work->unk_04 = D_80100850_114470_shared_board[object->unk8].unk_08;
        } else {
            work->unk_04 = 1.0f;
        }

        for (i = 0; i < src->omObj1->mtncnt; i++) {
            objData->motion[i] = func_800D8F30_ECB50_shared_board(src->omObj1->motion[i]);
        }

        if ((src->omObj2 != NULL) && (object->unk8 != 0xFF) &&
            (D_80100850_114470_shared_board[object->unk8].unk_0C > 0.0f)) {
            objData = object->omObj2= omAddObj(0x4000, 1, 0, -1, func_800D95D0_ED1F0_shared_board);

            mdlIdx = Hu3DModelLink(src->omObj2->model[0]);
            omSetStatBit(objData, 0x80);
            objData->model[0] = mdlIdx;
            omSetRot(objData, 0.0f, 0.0f, 0.0f);
            func_8001C8A8_1D4A8(mdlIdx, 1);
            Hu3DModelScaleSet(mdlIdx, 0.0f, 0.0f, 0.0f);

            work = HuMemMemoryAllocTemp(sizeof(UnkObj));
            objData->data = work;
            work->unk_00 = object;
            work->unk_04 = D_80100850_114470_shared_board[object->unk8].unk_0C;
        } else {
            object->omObj2 = NULL;
        }
    }
    return object;
}

void func_800D9A40_ED660_shared_board(Object* arg0) {
    arg0->flags |= 8;
}

void MBModelAttrSetDispOn(Object* arg0) {
    func_8001C258_1CE58(arg0->omObj1->model[0], 4, 0);
    if (arg0->omObj2 != NULL) {
        func_8001C258_1CE58(arg0->omObj2->model[0], 4, 0);
    }
}

void MBModelDispOn(Object* arg0) {
    MBModelAttrSetDispOn(arg0);
    func_800D9A40_ED660_shared_board(arg0);
}

void MBModelAttrSetDispOff(Object* arg0) {
    func_8001C258_1CE58(arg0->omObj1->model[0], 4, 4);
    if (arg0->omObj2 != NULL) {
        func_8001C258_1CE58(arg0->omObj2->model[0], 4, 4);
    }
}

void MBModelDispOff(Object* arg0) {
    MBModelAttrSetDispOff(arg0);
    arg0->flags &= ~8;
}

void MBModelKill(Object* arg0) {
    s32 i;

    if (D_80102AB0_1166D0_shared_board != NULL) {
        if (arg0->prev != NULL) {
            arg0->prev->next = arg0->next;
        }
        if (arg0->next != NULL) {
            arg0->next->prev = arg0->prev;
        } else {
            D_80102AB0_1166D0_shared_board = arg0->prev;
        }
        func_8001F304_1FF04(arg0->omObj1->model[0], -1);
        func_8001ACDC_1B8DC(arg0->omObj1->model[0]);
        if (arg0->omObj2 != NULL) {
            func_8001ACDC_1B8DC(arg0->omObj2->model[0]);
        }

        for (i = 0; i < arg0->omObj1->mtncnt; i++) {
            MBMotionKill(arg0->omObj1->motion[i]);
        }
        
        if (arg0->unk44 != -1) {
            MBMotionKill(arg0->unk44);
        }
        
        HuMemMemoryFreeTemp(arg0->omObj1->data);
        
        arg0->omObj1->data = NULL;
        omDelObj(arg0->omObj1);
        
        if (arg0->omObj2 != NULL) {
            HuMemMemoryFreeTemp(arg0->omObj2->data);
            arg0->omObj2->data = NULL;
            omDelObj(arg0->omObj2);
        }
        HuMemMemoryFreeTemp(arg0);
        D_80102AB4_1166D4_shared_board -= 1;
    }
}

//return 1 if object is found in linked list, 0 if we step the whole linked list and never find it
//unused
s32 func_800D9CB0_ED8D0_shared_board(Object* arg0) {
    Object* var_v0;

    var_v0 = D_80102AB0_1166D0_shared_board;
    
    while (var_v0 != NULL) {
        if (var_v0 == arg0) {
            return 1;
        }
        var_v0 = var_v0->prev;       
    }
    
    return 0;
}


void MBMotionSet(Object *arg0, s16 arg1, u16 arg2) {
    u16 var_v1;

    if (arg1 == -1) {
        var_v1 = arg0->unk44;
        arg0->unk46 = arg1;
    } else {
        var_v1 = arg0->omObj1->motion[arg1];
        arg0->unk46 = arg1;
    }
    func_8001F304_1FF04(arg0->omObj1->model[0], var_v1);
    func_8001C814_1D414(arg0->omObj1->model[0], -1, arg2);
}

void MBMotionShiftSet(Object* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    s16 var;
    
    if (arg1 == -1) {
        var = arg0->unk44;
        arg0->unk46 = arg1;
    } else {
        var = arg0->omObj1->motion[arg1];
        arg0->unk46 = arg1;
    }
    func_8001C624_1D224(arg0->omObj1->model[0], var, arg2, arg3, arg4);
}

u16 MBMotionCheck(Object* arg0) {
    u16 ret = 0;
    
    if (HmfModelData[arg0->omObj1->model[0]].unk40 == D_800CCF58_CDB58[HmfModelData[arg0->omObj1->model[0]].unk02].unk02) {
        ret = 1;
    }
    return ret;
}

u16 func_800D9E80_EDAA0_shared_board(Object* arg0) {
    u16 ret;

    ret = 0;
    if (HmfModelData[arg0->omObj1->model[0]].unk40 == 0.0f) {
        ret = 1;
    }
    return ret;
}

static void func_800D9ED0_EDAF0_shared_board(omObjData* arg0) {
    Object* temp_s1;

    temp_s1 = arg0->data;
    
    if (--arg0->work[1] == 0) {
        temp_s1->rot.x = arg0->rot.x;
        temp_s1->rot.y = arg0->rot.y;
        temp_s1->rot.z = arg0->rot.z;
        arg0->data = NULL;
        omDelObj(arg0);
        return;
    }
    
    arg0->scale.y += arg0->scale.x;
    temp_s1->rot.x = HuMathSin(arg0->scale.y);
    temp_s1->rot.y = 0.0f;
    temp_s1->rot.z = HuMathCos(arg0->scale.y);
}

//unused
omObjData* func_800D9F5C_EDB7C_shared_board(Object* arg0, Vec* arg1, s32 arg2) {
    Vec sp18;
    f32 var_f20;
    f32 var_f4;
    omObjData* temp_v0;

    MBVecDirGet(&arg0->coords, arg1, &sp18);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800D9ED0_EDAF0_shared_board);
    temp_v0->work[1] = arg2;
    temp_v0->rot.x = sp18.x;
    temp_v0->rot.y = sp18.y;
    temp_v0->rot.z = sp18.z;
    var_f20 = MBVecAngleGet(&arg0->rot);
    var_f4 = MBVecAngleGet(&sp18);
    if ((var_f4 < var_f20)) {
        if ((var_f20 - var_f4) >= 180.0f) {
            var_f4 += 360.0f;
        }
    } else if ((var_f4 - var_f20 ) >= 180.0f) {
        var_f20 += 360.0f;
    }
    temp_v0->scale.y = var_f20;
    temp_v0->scale.x = (var_f4 - var_f20) / (f32) arg2;
    temp_v0->data = arg0;
    return temp_v0;
}

void MBPlayerMotionLoad(s32 arg0, s32 arg1, s32 arg2) {
    Object* player;
    omObjData* playerOmObjData;
    s32 temp_s0;

    player = MBPlayerGet(arg0)->player_obj;
    playerOmObjData = player->omObj1;

    if (GwPlayer[arg0].itemTurn != 0) {
        MBKSuitMotionLoad(arg1, arg2);
        return;
    }

    temp_s0 = func_80017BB8_187B8(GwPlayer[arg0].chr, arg2);

    if ((playerOmObjData->motion[arg1] != -1) && (player->unk46 != arg1)) {
        MBMotionKill(playerOmObjData->motion[arg1]);
    }

    playerOmObjData->motion[arg1] = func_800D8E88_ECAA8_shared_board(temp_s0);
}
