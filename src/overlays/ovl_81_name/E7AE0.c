#include "common.h"
#include "ovl_81.h"

#define UNK_ARR_SIZE 4

extern s32 D_800D41B0_D4DB0[];
extern u16 D_800D5546_D6146[];

void func_80049FB8_4ABB8(void);
void func_8004A0E0_4ACE0(void);
void func_8004A9DC_4B5DC(s32);
void func_8005F904_60504(void);

extern omObjData* D_80105500_ED2D0_name_81;
extern UnkBoard4* D_80105504_ED2D4_name_81;
extern s16 D_80105508_ED2D8_name_81[UNK_ARR_SIZE][2];
extern UnkBoard4* D_80105518_ED2E8_name_81;
extern Process* D_8010551C_ED2EC_name_81;
extern Object* D_80105520_ED2F0_name_81[MBD_MAX_PLAYERS];
extern f32 D_80105528_ED2F8_name_81;
extern f32 D_8010552C_ED2FC_name_81[5]; //unknown type, maybe right size

f32 D_80101B20_E98F0_name_81[] = {
    0.8999999762f, 0.8999999762f, 1.200000048f,
    1.100000024f, 1.100000024f,
    1.5f, 0.8999999762f, 1.200000048f
};

s16 D_80101B40_E9910_name_81[UNK_ARR_SIZE][2] = {
    {0x22, 0x80}, {0x11E, 0x80},
    {0xA0, 0x18}, {0xA0, 0xD8}
};

s16 D_80101B50_E9920_name_81[UNK_ARR_SIZE][2] = {
    {0x0092, 0x0080}, {0x00AE, 0x0080},
    {0x00A0, 0x006C}, {0x00A0, 0x0084}
};

s16 D_80101B60_E9930_name_81[UNK_ARR_SIZE][2] = {
    {0xFFF0, 0x0000}, {0x0010, 0x0000},
    {0x0000, 0xFFF4}, {0x0000, 0x000C}
};

f32 D_80101B70_E9940_name_81[UNK_ARR_SIZE] = {
    90.0f, -90.0f, 0.0f, 180.0f
};

s16 D_80101B80_E9950_name_81[][2] = {
    {0x00F0, 0x0034}, {0x00F0, 0x0034},
    {0x00F0, 0x0034}, {0x00F0, 0x0034},
    {0x00F0, 0x0034}
};

s32 D_80101B94_E9964_name_81[] = {
    0x00130117, 0x00130118, 0x00130119, 0x0013011A, 0x0013011B
};

s32 D_80101BA8_E9978_name_81[] = {
    0x00130117, 0x00130136, 0x00130138, 0x0013013B, 0x0013013D, 0x0013013F
};

s32 D_80101BC0_E9990_name_81[] = {
    0x00130118, 0x00130137, 0x00130139, 0x0013013C, 0x0013013E, 0x00130140
};

s32 D_80101BD8_E99A8_name_81[] = {
    0x001300B3, 0x001300B4, 0x001300B5, 0x001300B6, 0x001300B7, 0x001300B8, 0x001300B9, 0x001300BA
};

f32 D_80101BF8_E99C8_name_81[] = {
    0.6499999762f, 0.6499999762f, 0.6499999762f, 0.6499999762f,
    0.6499999762f, 0.5849999785f, 0.6499999762f, 0.6499999762f, 
};

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
    
    for (i = 0; i < UNK_ARR_SIZE; i++) {
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
    
    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        temp_v0 = MBDGetPlayerStruct(i);
        D_80105520_ED2F0_name_81[i] = func_800D8314_C00E4_name_81(D_80101BD8_E99A8_name_81[temp_v0->chr], 9, 1.0f, D_80101B20_E98F0_name_81[temp_v0->chr], 0);
        obj = &D_80105520_ED2F0_name_81[i]; //TODO: this is odd
        Hu3DModelScaleSet(D_80105520_ED2F0_name_81[i]->omObj1->model[0], 0.0f, 0.0f, 0.0f);
        Hu3DModelScaleSet((*obj)->omObj2->model[0], 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&(*obj)->scale, D_80101BF8_E99C8_name_81[temp_v0->chr], D_80101BF8_E99C8_name_81[temp_v0->chr], D_80101BF8_E99C8_name_81[temp_v0->chr]);
    }

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        temp_v0 = MBDGetPlayerStruct(i);
        temp_a0 = temp_v0->player_obj;
        temp_v0->player_obj = D_80105520_ED2F0_name_81[i];
        D_80105520_ED2F0_name_81[i] = temp_a0;
    }

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        func_800FCF50_E4D20_name_81(i, 1);
    }

    HuPrcVSleep();

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        func_800D8F0C_C0CDC_name_81(D_80105520_ED2F0_name_81[i]);
    }
}

void func_801007C4_E8594_name_81(void) {
    GW_PLAYER* temp_v0;
    Object* temp_a0;
    s32 i;

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        temp_v0 = MBDGetPlayerStruct(i);
        temp_a0 = temp_v0->player_obj;
        temp_v0->player_obj = D_80105520_ED2F0_name_81[i];
        D_80105520_ED2F0_name_81[i] = temp_a0;
    }

    for (i = 0; i < MBD_MAX_PLAYERS; i++) {
        temp_v0 = MBDGetPlayerStruct(i);
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

void func_801008E8_E86B8_name_81(void) {
    f32 sp10[2];
    f32 temp_f20;
    f32 temp_f22;
    s16* temp_s0;
    s32 temp_s2;
    UnkBoard4* temp_s3;
    s32 temp_s6;
    s16 var_s1;
    s32 var_s4;
    s32 var_s7;
    s16 sixteen;
    f32 sixteenFloat;

    var_s4 = 0;

    //TODO: do-while(0) required for matching
    do {
    temp_s2 = (s32)HuPrcCurrentGet()->user_data;
    var_s7 = 0;
    var_s1 = 0;
    temp_f22 = MBDCameraSpeedGet();
    if ((func_800FC114_E3EE4_name_81()) == 0) {
        var_s7 = func_800DB3E0_C31B0_name_81(GwSystem.current_player_index);
        func_800DB544_C3314_name_81(GwSystem.current_player_index);
        func_8004A9DC_4B5DC(0x60);
    }
    func_80100864_E8634_name_81();
    temp_s3 = func_800FFEEC_E7CBC_name_81();
    temp_s6 = func_800E1824_C95F4_name_81(4, 0xA0, 0);
    if (D_800D41B0_D4DB0[4] != 0) {
        var_s4 = func_800E1824_C95F4_name_81(6, 0x3C, 0);
    }
    D_80105518_ED2E8_name_81 = func_80100420_E81F0_name_81();
    MBDCameraSpeedSet(3.5f);

    do {
        sixteen = 16;
        HuPrcVSleep();
        MBDCameraPos2DGet(sp10);
        func_801000A4_E7E74_name_81(temp_s3, MBDCameraPos2DSet(sp10));
        
        if (D_800D5546_D6146[temp_s2] & 0x200) {
            sp10[0] -= sixteen;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x100) {
            sp10[0] += sixteen;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x800) {
            sp10[1] -= sixteen;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x400) {
            sp10[1] += sixteen;
            var_s1 = 0xF;
        }
        
        MBDCameraPos2DSet(sp10);
        
        if (var_s1 != 0) {
            var_s1 -= 1;
            func_800F73C0_DF190_name_81();
        } else {
            func_800F740C_DF1DC_name_81();
        }
        
        if (GwPlayer[GwSystem.current_player_index].stat & 1) {
            func_8005F904_60504();
            goto label; //break doesn't work here for some reason
        }
    } while (mbCameraBtnF != 0 && !(D_800C9520_CA120[temp_s2] & 0xE010));

    while (1) {
        label:
        func_800E1854_C9624_name_81(temp_s6);
        if (var_s4 != 0) {
            func_800E1854_C9624_name_81(var_s4);
        }
        func_80100070_E7E40_name_81(temp_s3);
        func_801005DC_E83AC_name_81(D_80105518_ED2E8_name_81);
        WipeCreateOut(0, 4);
        HuPrcSleep(4);
        if ((func_800FC114_E3EE4_name_81()) == 0) {
            func_800E5C20_CD9F0_name_81();
            func_800E5BE8_CD9B8_name_81();
            MBDCameraSpeedSet(-1.0f);
            temp_f20 = func_800E8578_D0348_name_81();
            func_800E856C_D033C_name_81(1.0f);
            func_800E5954_CD724_name_81();
            MBDCameraZoomSet(D_80105528_ED2F8_name_81);
            MBDCameraPos2DSet(D_8010552C_ED2FC_name_81);
            HuPrcVSleep();
            func_800E856C_D033C_name_81(temp_f20);
            if (var_s7 != 0) {
                func_800DADA0_C2B70_name_81(GwSystem.current_player_index);
            }
            func_800DB5AC_C337C_name_81(GwSystem.current_player_index);
            func_80100890_E8660_name_81();
            func_8004A9DC_4B5DC(0x7F);
            WipeCreateIn(0, 4);
            HuPrcSleep(4);
            MBDCameraSpeedSet(temp_f22);
            omDelPrcObj(0);
            return;
        } else {
            break;
        }
        func_8005F904_60504();
    }
    func_80100890_E8660_name_81();
    MBDCameraSpeedSet(temp_f22);
    omDelPrcObj(0);
    } while (0);
}


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
