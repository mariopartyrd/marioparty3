#include "common.h"
#include "ovl_81.h"

#define UNK_ARR_SIZE 4

UnkBoard4* func_800F4528_DC2F8_name_81(s16, s16);
void func_800F4584_DC354_name_81(UnkBoard4*);
void func_80100124_E7EF4_name_81(UnkBoard4*, s32);
Object* func_800D8314_C00E4_name_81(s32, s32, f32, s32, s32);
void func_800FCF50_E4D20_name_81(s32, s32);
void func_800D8E88_C0C58_name_81(Object*);
void func_800D8F3C_C0D0C_name_81(Object*);
void func_800F8C68_E0A38_name_81(s32);
void func_80100604_E83D4_name_81(void);
void func_800F740C_DF1DC_name_81(void);
void func_800F89D0_E07A0_name_81(s32, s32, s32, s32);
void func_801007C4_E8594_name_81(void);
void MBDCameraPos3DSet(Vec*);
void func_80049FB8_4ABB8(void);
void func_8004A0E0_4ACE0(void);
void func_800E5954_CD724_name_81(void);
void func_800E5964_CD734_name_81(void);
f32 MBDCameraZoomGet(void);
Process* MBDCameraZoomMotStart(f32);
void MBDCameraPos2DGet(f32*);
void MBDCamera3Dto2D(Vec*, f32*);
void func_801008E8_E86B8_name_81(void);
void func_80100CA0_E8A70_name_81(void);

extern s8 D_800CB99C_CC59C;
extern f32 D_80105528_ED2F8_name_81;
extern f32 D_8010552C_ED2FC_name_81[5]; //unknown type, maybe right size
extern s16 D_80101B40_E9910_name_81[UNK_ARR_SIZE][2];
extern s16 D_80101B60_E9930_name_81[UNK_ARR_SIZE][2];
extern UnkBoard4* D_80105504_ED2D4_name_81;
extern s16 D_80105508_ED2D8_name_81[UNK_ARR_SIZE][2];
extern s16 D_80101B50_E9920_name_81[UNK_ARR_SIZE][2];
extern f32 D_80101B70_E9940_name_81[UNK_ARR_SIZE];
extern omObjData* D_80105500_ED2D0_name_81;
extern UnkBoard4* D_80105518_ED2E8_name_81;
extern s16 D_80101B80_E9950_name_81[5][2];
extern s32 D_80101B94_E9964_name_81[];
extern s32 D_80101BA8_E9978_name_81[];
extern s32 D_80101BC0_E9990_name_81[];
extern Process* D_8010551C_ED2EC_name_81;
extern s32 D_80101B20_E98F0_name_81[];
extern s32 D_80101BD8_E99A8_name_81[];
extern f32 D_80101BF8_E99C8_name_81[];
extern Object* D_80105520_ED2F0_name_81[];

void func_800FFD10_E7AE0_name_81(omObjData* obj) {
    s32 i;

    for (i = 0; i < UNK_ARR_SIZE; i++) {
        D_80105508_ED2D8_name_81[i][0] += D_80101B60_E9930_name_81[i][0];
        D_80105508_ED2D8_name_81[i][1] += D_80101B60_E9930_name_81[i][1];
        if (D_80101B60_E9930_name_81[i][0] < 0) {
            if (D_80105508_ED2D8_name_81[i][0] < D_80101B40_E9910_name_81[i][0]) {
                D_80105508_ED2D8_name_81[i][0] = D_80101B40_E9910_name_81[i][0];
            }
        }

        if (D_80101B60_E9930_name_81[i][0] > 0) {
            if (D_80105508_ED2D8_name_81[i][0] > D_80101B40_E9910_name_81[i][0]) {
                D_80105508_ED2D8_name_81[i][0] = D_80101B40_E9910_name_81[i][0];
            }
        }

        if (D_80101B60_E9930_name_81[i][1] < 0) {
            if (D_80105508_ED2D8_name_81[i][1] < D_80101B40_E9910_name_81[i][1]) {
                D_80105508_ED2D8_name_81[i][1] = D_80101B40_E9910_name_81[i][1];
            }
        }

        if (D_80101B60_E9930_name_81[i][1] > 0) {
            if (D_80105508_ED2D8_name_81[i][1] > D_80101B40_E9910_name_81[i][1]) {
                D_80105508_ED2D8_name_81[i][1] = D_80101B40_E9910_name_81[i][1];
            }
        }
        func_80054904_55504(D_80105504_ED2D4_name_81->unk_0A, i, D_80105508_ED2D8_name_81[i][0], D_80105508_ED2D8_name_81[i][1]);
    }
}

UnkBoard4* func_800FFEEC_E7CBC_name_81(void) {
    UnkBoard4* temp_v0;
    omObjData* temp_v0_2;
    void* temp_s4;
    s32 i;

    temp_v0 = func_800F4528_DC2F8_name_81(4, 0);
    D_80105504_ED2D4_name_81 = temp_v0;
    temp_s4 = DataRead(0x001301D4);
    
    for (i = 0; i < 4; i++) {
        temp_v0->unk_0C[i] = func_80055810_56410(temp_s4);
        func_80055024_55C24(temp_v0->unk_0A, i, temp_v0->unk_0C[i], 0);
        HuSprPriSet(temp_v0->unk_0A, i, 0);
        HuSprAttrSet(temp_v0->unk_0A, i, 0x8000);
        func_80054904_55504(temp_v0->unk_0A, i, D_80101B50_E9920_name_81[i][0], D_80101B50_E9920_name_81[i][1]);
        D_80105508_ED2D8_name_81[i][0] = D_80101B50_E9920_name_81[i][0];
        D_80105508_ED2D8_name_81[i][1] = D_80101B50_E9920_name_81[i][1];
        func_800552DC_55EDC(temp_v0->unk_0A, i, D_80101B70_E9940_name_81[i]);
    }

    DataClose(temp_s4);
    temp_v0_2 = omAddObj(0x1000, 0, 0, -1, func_800FFD10_E7AE0_name_81);
    D_80105500_ED2D0_name_81 = temp_v0_2;
    omSetStatBit(temp_v0_2, 0x20);
    return temp_v0;
}

void func_80100070_E7E40_name_81(UnkBoard4* arg0) {
    omDelObj(D_80105500_ED2D0_name_81);
    func_800F4584_DC354_name_81(arg0);
}

void func_801000A4_E7E74_name_81(UnkBoard4* arg0, u16 arg1) {
    s32 var_v0;
    s32 i;

    for (i = 0; i < 4; i++) {
        var_v0 = arg1 >> i;
        if (var_v0 & 1) {
            HuSprAttrSet(arg0->unk_0A, i, 0x8000);
        } else {
            HuSprAttrReset(arg0->unk_0A, i, 0x8000);
        }
    }
}

void func_80100124_E7EF4_name_81(UnkBoard4* arg0, s32 arg1) {
    f32 sp10[2];
    f32 sp18[2];

    MBDCameraPos2DGet(sp10);
    func_80054904_55504(arg0->unk_0A, 2, (D_80101B80_E9950_name_81[2][0] + (sp10[0] / 9.0f)), (D_80101B80_E9950_name_81[2][1] + (sp10[1] / 9.0f)));
    MBDCamera3Dto2D(&GwPlayer[0].player_obj->coords, sp18);
    func_80054904_55504(arg0->unk_0A, 3, (D_80101B80_E9950_name_81[3][0] + (sp10[0] / 9.0f) + ((sp18[0] - 160.0f) / 9.0f)), ((D_80101B80_E9950_name_81[3][1] + (sp10[1] / 9.0f) + ((sp18[1] - 120.0f) / 9.0f)) - 4.0f));
    MBDCamera3Dto2D(&GwPlayer[1].player_obj->coords, sp18);
    func_80054904_55504(arg0->unk_0A, 4, (D_80101B80_E9950_name_81[4][0] + (sp10[0] / 9.0f) + ((sp18[0] - 160.0f) / 9.0f)), ((D_80101B80_E9950_name_81[4][1] + (sp10[1] / 9.0f) + ((sp18[1] - 120.0f) / 9.0f)) - 4.0f));
    
    if (arg1 == 0) {
        HuSprAttrSet(arg0->unk_0A, 3, 0x8000);
        HuSprAttrReset(arg0->unk_0A, 4, 0x8000);
        return;
    }
    
    HuSprAttrReset(arg0->unk_0A, 3, 0x8000);
    HuSprAttrSet(arg0->unk_0A, 4, 0x8000);
}

//TODO: what is this?
void func_801003C8_E8198_name_81(void) {
    s32 counter = 32;
    
    while (1) {
        UnkBoard4* data = D_80105518_ED2E8_name_81;
        s32 adjusted = (counter < 0) ? (counter + 0x1F) : counter;
        func_80100124_E7EF4_name_81(data, adjusted >> 5);
        
        counter++;
        if (counter >= 64) {
            counter = 0; 
        }
        
        HuPrcVSleep();
    }
}

void* func_80100420_E81F0_name_81(void) {
    UnkBoard4* temp_s2;
    void* temp_v0;
    s32 i;

    temp_s2 = func_800F4528_DC2F8_name_81(5, 0);
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            temp_v0 = DataRead(D_80101BA8_E9978_name_81[GwSystem.current_board_index]);
        } else if (i == 1) {
            temp_v0 = DataRead(D_80101BC0_E9990_name_81[GwSystem.current_board_index]);
        } else {
            temp_v0 = DataRead(D_80101B94_E9964_name_81[i]);
        }

        temp_s2->unk_0C[i] = func_80055810_56410(temp_v0);
        func_80055024_55C24(temp_s2->unk_0A, i, temp_s2->unk_0C[i], 0);
        HuSprPriSet(temp_s2->unk_0A, i, 0);
        if (i == 0) {
            HuSprAttrSet(temp_s2->unk_0A, 0, 0x1000);
            func_80055458_56058(temp_s2->unk_0A, 0, 0x80U);
        } else {
            HuSprAttrSet(temp_s2->unk_0A, i, 0);
        }
        func_80054904_55504(temp_s2->unk_0A, i, D_80101B80_E9950_name_81[i][0], D_80101B80_E9950_name_81[i][1]);
        DataClose(temp_v0);     
    }
    D_8010551C_ED2EC_name_81 = omAddPrcObj(func_801003C8_E8198_name_81, 0x1005U, 0, 0);
    func_80100124_E7EF4_name_81(temp_s2, 1);
    return temp_s2;
}

void func_801005DC_E83AC_name_81(UnkBoard4* arg0) {
    func_800F4584_DC354_name_81(arg0);
    omDelPrcObj(D_8010551C_ED2EC_name_81);
}

void func_80100604_E83D4_name_81(void) {
    GW_PLAYER* temp_v0;
    s32 i;
    Object** obj;
    Object* temp_a0;
    
    for (i = 0; i < 2; i++) {
        temp_v0 = Duel_GetPlayerStruct(i);
        D_80105520_ED2F0_name_81[i] = func_800D8314_C00E4_name_81(D_80101BD8_E99A8_name_81[temp_v0->chr], 9, 1.0f, D_80101B20_E98F0_name_81[temp_v0->chr], 0);
        obj = &D_80105520_ED2F0_name_81[i]; //TODO: this is odd
        Hu3DModelScaleSet(D_80105520_ED2F0_name_81[i]->omObj1->model[0], 0.0f, 0.0f, 0.0f);
        Hu3DModelScaleSet((*obj)->omObj2->model[0], 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&(*obj)->scale, D_80101BF8_E99C8_name_81[temp_v0->chr], D_80101BF8_E99C8_name_81[temp_v0->chr], D_80101BF8_E99C8_name_81[temp_v0->chr]);
    }

    for (i = 0; i < 2; i++) {
        temp_v0 = Duel_GetPlayerStruct(i);
        temp_a0 = temp_v0->player_obj;
        temp_v0->player_obj = D_80105520_ED2F0_name_81[i];
        D_80105520_ED2F0_name_81[i] = temp_a0;
    }

    for (i = 0; i < 2; i++) {
        func_800FCF50_E4D20_name_81(i, 1);
    }

    HuPrcVSleep();

    for (i = 0; i < 2; i++) {
        func_800D8F0C_C0CDC_name_81(D_80105520_ED2F0_name_81[i]);
    }
}

void func_801007C4_E8594_name_81(void) {
    GW_PLAYER* temp_v0;
    Object* temp_a0;
    s32 i;

    for (i = 0; i < 2; i++) {
        temp_v0 = Duel_GetPlayerStruct(i);
        temp_a0 = temp_v0->player_obj;
        temp_v0->player_obj = D_80105520_ED2F0_name_81[i];
        D_80105520_ED2F0_name_81[i] = temp_a0;
    }

    for (i = 0; i < 2; i++) {
        temp_v0 = Duel_GetPlayerStruct(i);
        func_800D8E88_C0C58_name_81(temp_v0->player_obj);
        func_800D8F3C_C0D0C_name_81(D_80105520_ED2F0_name_81[i]);
    }
}

void func_80100864_E8634_name_81(void) {
    func_80100604_E83D4_name_81();
    func_800F8C68_E0A38_name_81(0);
    func_800F8C68_E0A38_name_81(1);
}

void func_80100890_E8660_name_81(void) {
    func_801007C4_E8594_name_81();
    func_800F740C_DF1DC_name_81();
    func_800F89D0_E07A0_name_81(GwSystem.current_player_index, 0, -1, 2);
    func_800F89D0_E07A0_name_81(GwSystem.current_player_index, 1, -1, 2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_801008E8_E86B8_name_81);

void func_80100CA0_E8A70_name_81(void) {
    while (1) {
        MBDCameraPos3DSet(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
        HuPrcVSleep();
    }
}

void func_80100CEC_E8ABC_name_81(s32 padIdx) {
    Process* proc;
    Process* proc2;
    Process* procObj;

    D_80105528_ED2F8_name_81 = MBDCameraZoomGet();
    MBDCameraPos2DGet(D_8010552C_ED2FC_name_81);
    D_800CB99C_CC59C = 1;
    func_80049FB8_4ABB8();
    func_800E5964_CD734_name_81();
    procObj = omAddPrcObj(func_80100CA0_E8A70_name_81, 0x1005U, 0, 0);
    omPrcSetStatBit(procObj, 0x20);
    proc = HuPrcCurrentGet();
    HuPrcChildLink(proc, MBDCameraZoomMotStart(1.0f));
    HuPrcChildWait();
    omDelPrcObj(procObj);
    proc2 = HuPrcCurrentGet();
    procObj = omAddPrcObj(func_801008E8_E86B8_name_81, 0x1005U, 0, 0);
    procObj->user_data = (void*)padIdx;
    omPrcSetStatBit(procObj, 0x80);
    HuPrcChildLink(proc2, procObj);
    HuPrcChildWait();
    func_8004A0E0_4ACE0();
    D_800CB99C_CC59C = 0;
    func_800E5954_CD724_name_81();
}
