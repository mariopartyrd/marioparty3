#include "common.h"
#include "malloc.h"
#include "ovl_80.h"

typedef struct UnkBoard3 {
/* 0x00 */ void* doublyLinkedList;
/* 0x04 */ s32 unk_04;
/* 0x08 */ char unk_08[2];
/* 0x0A */ s16 unk_0A;
/* 0x0C */ Vec vec0;
/* 0x18 */ Vec vec1;
/* 0x24 */ Vec vec2;
/* 0x30 */ Vec vec3; //could also be 3 s32s
/* 0x3C */ char unk_3C[8];
/* 0x44 */ s16 unk_44;
/* 0x46 */ s16 unk_46;
} UnkBoard3; //sizeof 0x48

typedef struct Node {
/* 0x00 */ struct Node* next;
/* 0x04 */ struct Node* prev;
} Node;

extern Node* D_80102AB0_1166D0_shared_board;
extern u16 D_80102AB4_1166D4_shared_board;
extern u8 D_800D6A90_D7690;

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E30_ECA50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E60_ECA80_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8E88_ECAA8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8ED4_ECAF4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8F30_ECB50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8F80_ECBA0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D8FC4_ECBE4_shared_board);

UnkBoard3* func_800D9004_ECC24_shared_board(void) {
    UnkBoard3* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard3));
    if (temp_v0 != NULL) {
        D_80102AB4_1166D4_shared_board++;
        temp_v0->doublyLinkedList = D_80102AB0_1166D0_shared_board;
        temp_v0->unk_04 = 0;
        if (D_80102AB0_1166D0_shared_board != NULL) {
            D_80102AB0_1166D0_shared_board->prev = (Node* ) temp_v0;
        }
        D_80102AB0_1166D0_shared_board = (Node* ) temp_v0;
        temp_v0->unk_0A = 8;
        HuVecCopyXYZ(&temp_v0->vec0, 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&temp_v0->vec1, 0.0f, 0.0f, 1.0f);
        HuVecCopyXYZ(&temp_v0->vec2, 1.0f, 1.0f, 1.0f);
        temp_v0->vec3.x = 0.0f;
        temp_v0->vec3.y = 0.0f;
        temp_v0->vec3.z = 0.0f;
        temp_v0->unk_44 = -1;
        temp_v0->unk_46 = -1;
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", MBModelCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", MBModelFileCreate);

typedef struct UnkObj {
    Object* unk_00;
    f32 unk_04;
} UnkObj;

void func_800D93C0_ECFE0_shared_board(omObjData* playerObj) {
    f32 sp10[2];
    Object* temp_s0;
    UnkObj* temp_s2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    temp_s2 = playerObj->data;
    temp_s0 = temp_s2->unk_00;

    if ((D_800D6A90_D7690 == 0) || (temp_s0->flags & 0x10)) {
        if (temp_s0->unk30.z != 0.0f) {
            temp_s0->unk30.y +=  temp_s0->unk30.z;
            temp_s0->unk30.x = temp_s0->unk30.x + temp_s0->unk30.y;
            if (temp_s0->unk30.x < 0.0f) {
                temp_s0->unk30.x = 0.0f;
                temp_s0->unk30.y = 0.0f;
                temp_s0->unk30.z = 0.0f;
            }
        }
    }

    if (!(temp_s0->flags & 4)) {
        playerObj->rot.y = func_800D8790_EC3B0_shared_board(&temp_s0->unk18);
    }
    
    playerObj->trans.x = temp_s0->coords.x;
    playerObj->trans.y = temp_s0->coords.y + temp_s0->unk30.x;
    playerObj->trans.z = temp_s0->coords.z;
    playerObj->scale.x = temp_s0->scale.x * temp_s2->unk_04 * func_800E72DC_FAEFC_shared_board();
    playerObj->scale.y = temp_s0->scale.y * temp_s2->unk_04 * func_800E72DC_FAEFC_shared_board();
    playerObj->scale.z = temp_s0->scale.z * temp_s2->unk_04 * func_800E72DC_FAEFC_shared_board();

    if (!(D_80105706_119326_shared_board & 1)) {
        func_800D9AD0_ED6F0_shared_board(temp_s0);
        return;
    }
    
    if (!(temp_s0->flags & 8)) {
        func_800D9AD0_ED6F0_shared_board(temp_s0);
        return;
    }
    
    if (temp_s0->flags & 2) {
        func_800E9940_FD560_shared_board(&temp_s0->coords, sp10);
        if ((sp10[0] > 370.0f) || 
            (sp10[0] < -50.0f) || 
            (sp10[1] > 290.0f) || 
            (sp10[1] < -20.0f)) {
            func_800D9AD0_ED6F0_shared_board(temp_s0);
            return;
        }
    }
    MBModelAttrSetDispOff(temp_s0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D95C4_ED1E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D95D0_ED1F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9714_ED334_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D975C_ED37C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9A40_ED660_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", MBModelAttrSetDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", MBModelDispOff);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9AD0_ED6F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9B24_ED744_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9B54_ED774_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9CB0_ED8D0_shared_board);

void func_800D9CE8_ED908_shared_board(Object* arg0, s16 arg1, u16 arg2) {
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9D84_ED9A4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9E0C_EDA2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9E80_EDAA0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9ED0_EDAF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800D9F5C_EDB7C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/ECA50", func_800DA09C_EDCBC_shared_board);
