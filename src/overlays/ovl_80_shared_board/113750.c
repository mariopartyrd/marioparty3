#include "common.h"
#include "ovl_80.h"

void func_800FFB30_113750_shared_board(omObjData*);
void func_800E6FCC_FABEC_shared_board(void);
extern omObjData* D_801056C0_1192E0_shared_board;
extern UnkBoard8* D_801056C4_1192E4_shared_board;
extern Object* D_801056D8_1192F8_shared_board[];

extern f32 D_801056E8_119308_shared_board;

// start of 113750 .data section
f32 D_80101E90_115AB0_shared_board[] = {
    0.9f, 0.9f, 1.2f, 1.1f, 1.1f, 1.5f, 0.9f, 1.2f,
};

s16 D_80101EB0_115AD0_shared_board[][2] = {
    { 34, 128 },
    { 286, 128 },
    { 160, 24 },
    { 160, 216 }
};

s16 D_80101EC0_115AE0_shared_board[][2] = {
    {0x0092, 0x0080},
    {0x00AE, 0x0080},
    {0x00A0, 0x006C},
    {0x00A0, 0x0084}
};

s16 D_80101ED0_115AF0_shared_board[][2] = {
    { -16, 0 },
    { 16, 0 },
    { 0, -12 },
    { 0, 12 }
};

f32 D_80101EE0_115B00_shared_board[] = {
    90.0f, -90.0f, 0.0f, 180.0f
};

s32 D_80101EF0_115B10_shared_board[] = {
    0x001300B3,
    0x001300B4,
    0x001300B5,
    0x001300B6,
    0x001300B7,
    0x001300B8,
    0x001300B9,
    0x001300BA
};

s32 D_80101F10_115B30_shared_board[] = {
    0x001300C7,
    0x001300C8,
    0x001300C9,
    0x001300CA,
    0x001300CB,
    0x001300CC,
    0x001300CD,
    0x001300CE
};

extern UnkBoard8* D_801056C4_1192E4_shared_board;
extern s16 D_801056C8_1192E8_shared_board[][2];

void func_800FFB30_113750_shared_board(omObjData* arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_801056C8_1192E8_shared_board[i][0] += D_80101ED0_115AF0_shared_board[i][0];
        D_801056C8_1192E8_shared_board[i][1] += D_80101ED0_115AF0_shared_board[i][1];

        if (D_80101ED0_115AF0_shared_board[i][0] < 0) {
            if (D_801056C8_1192E8_shared_board[i][0] < D_80101EB0_115AD0_shared_board[i][0]) {
                D_801056C8_1192E8_shared_board[i][0] = D_80101EB0_115AD0_shared_board[i][0];
            }
        }

        if (D_80101ED0_115AF0_shared_board[i][0] > 0) {
            if (D_801056C8_1192E8_shared_board[i][0] > D_80101EB0_115AD0_shared_board[i][0]) {
                D_801056C8_1192E8_shared_board[i][0] = D_80101EB0_115AD0_shared_board[i][0];
            }
        }

        if (D_80101ED0_115AF0_shared_board[i][1] < 0) {
            if (D_801056C8_1192E8_shared_board[i][1] < D_80101EB0_115AD0_shared_board[i][1]) {
                D_801056C8_1192E8_shared_board[i][1] = D_80101EB0_115AD0_shared_board[i][1];
            }
        }

        if (D_80101ED0_115AF0_shared_board[i][1] > 0) {
            if (D_801056C8_1192E8_shared_board[i][1] > D_80101EB0_115AD0_shared_board[i][1]) {
                D_801056C8_1192E8_shared_board[i][1] = D_80101EB0_115AD0_shared_board[i][1];
            }
        }
        func_80054904_55504(D_801056C4_1192E4_shared_board->spriteGroup, i, D_801056C8_1192E8_shared_board[i][0], D_801056C8_1192E8_shared_board[i][1]);
    }
}

UnkBoard8* func_800FFD0C_11392C_shared_board(void) {
    UnkBoard8* temp_v0;
    s32 i;
    void* temp_s4;

    temp_v0 = func_800F2C48_106868_shared_board(5, 0);
    D_801056C4_1192E4_shared_board = temp_v0;
    temp_s4 = DataRead(0x1301D4);

    for (i = 0; i < 4; i++) {
        temp_v0->model[i] = func_80055810_56410(temp_s4);
        func_80055024_55C24(temp_v0->spriteGroup, i, temp_v0->model[i], 0);
        HuSprPriSet(temp_v0->spriteGroup, i, 0U);
        HuSprAttrSet(temp_v0->spriteGroup, i, 0x8000);
        func_80054904_55504(temp_v0->spriteGroup, i, D_80101EC0_115AE0_shared_board[i][0], D_80101EC0_115AE0_shared_board[i][1]);
        D_801056C8_1192E8_shared_board[i][0] = D_80101EC0_115AE0_shared_board[i][0];
        D_801056C8_1192E8_shared_board[i][1] = D_80101EC0_115AE0_shared_board[i][1];
        func_800552DC_55EDC(temp_v0->spriteGroup, i, D_80101EE0_115B00_shared_board[i]);
    }

    DataClose(temp_s4);
    D_801056C0_1192E0_shared_board = omAddObj(0x1000, 0U, 0U, -1, func_800FFB30_113750_shared_board);
    omSetStatBit(D_801056C0_1192E0_shared_board, 0x20);
    return temp_v0;
}

void func_800FFE90_113AB0_shared_board(UnkBoard8* arg0) {
    omDelObj(D_801056C0_1192E0_shared_board);
    func_800F2CA4_1068C4_shared_board(arg0);
}

void func_800FFEC4_113AE4_shared_board(UnkBoard8* arg0, u16 arg1) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((arg1 >> i) & 1) {
            HuSprAttrSet(arg0->spriteGroup, i, 0x8000);
        } else {
            HuSprAttrReset(arg0->spriteGroup, i, 0x8000);
        }
    }
}

void func_800FFF44_113B64_shared_board(void) {
    GW_PLAYER* temp_a1;
    s32 i;
    Object* temp_a0_2;

    for (i = 0; i < 4; i++) {
        temp_a1 = MBPlayerGet(i);
        if (GwPlayer[i].itemTurn != 0) {
            D_801056D8_1192F8_shared_board[i] = MBModelFileCreate(D_80101F10_115B30_shared_board[temp_a1->chr], 9, 1.0f, D_80101E90_115AB0_shared_board[temp_a1->chr], NULL);
        } else {
            D_801056D8_1192F8_shared_board[i] = MBModelFileCreate(D_80101EF0_115B10_shared_board[temp_a1->chr], 9, 1.0f, D_80101E90_115AB0_shared_board[temp_a1->chr], NULL);
        }

        Hu3DModelScaleSet(D_801056D8_1192F8_shared_board[i]->omObj1->model[0], 0.0f, 0.0f, 0.0f);
        Hu3DModelScaleSet(D_801056D8_1192F8_shared_board[i]->omObj2->model[0], 0.0f, 0.0f, 0.0f);
    }

    for (i = 0; i < 4; i++) {
        temp_a1 = MBPlayerGet(i);
        temp_a0_2 = temp_a1->player_obj;
        temp_a1->player_obj = D_801056D8_1192F8_shared_board[i];
        D_801056D8_1192F8_shared_board[i] = temp_a0_2; 
    }

    for (i = 0; i < 4; i++) {
        MBPlayerPosFixSet(i, 1);
    }

    
    HuPrcVSleep();

    if (D_801011FC_114E1C_shared_board != NULL) {
        MBModelDispOff(D_801011FC_114E1C_shared_board);
    }
    
    for (i = 0; i < 4; i++){
        MBModelDispOff(D_801056D8_1192F8_shared_board[i]);
    }
}

void func_80100130_113D50_shared_board(void) {
    GW_PLAYER* player;
    Object* temp_a0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        player = MBPlayerGet(i);
        temp_a0 = player->player_obj;
        player->player_obj = D_801056D8_1192F8_shared_board[i];
        D_801056D8_1192F8_shared_board[i] = temp_a0;
    }

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        player = MBPlayerGet(i);
        if (GwPlayer[i].itemTurn == 0) {
            MBModelDispOn(player->player_obj);
        }
        MBModelKill(D_801056D8_1192F8_shared_board[i]);
    }
    
    if (D_801011FC_114E1C_shared_board != NULL) {
        MBModelDispOn(D_801011FC_114E1C_shared_board);
    }
}

void func_8010020C_113E2C_shared_board(void) {
    func_800FFF44_113B64_shared_board();
}

void func_80100228_113E48_shared_board(void) {
    func_80100130_113D50_shared_board();
    MBStatusShowAll();
}

void func_8010024C_113E6C_shared_board(void) {
    f32 sp10[2];
    Unk3* temp_s6;
    Unk3* var_s4;
    UnkBoard8* temp_s3;
    f32 temp_f20;
    f32 temp_f22;
    s32 temp_s2;
    s16 var_s1;
    s32 var_s7;
    u16* temp_s0;
    s32 temp;

    var_s4 = NULL;
    temp_s2 = (s32)HuPrcCurrentGet()->user_data;
    var_s7 = 0;
    var_s1 = 0;
    
    temp_f22 = MBCameraSpeedGet();
    
    if (func_800F8858_10C478_shared_board() == 0) {
        var_s7 = func_800DBEC0_EFAE0_shared_board(GwSystem.current_player_index);
        func_800DC024_EFC44_shared_board(GwSystem.current_player_index);
        if (D_800C9930_CA530 != -1) {
            func_800036E8_42E8(D_800C9930_CA530, 0x60);
        } else {
            func_8004A9DC_4B5DC(0x60);
        }
    }
    
    func_8010020C_113E2C_shared_board();
    temp_s3 = func_800FFD0C_11392C_shared_board();
    temp_s6 = func_800E210C_F5D2C_shared_board(4, 0xA0, 0);
    
    if (mbWalkNum != 0) {
        var_s4 = func_800E210C_F5D2C_shared_board(6, 0x3C, 0);
    }
    MBCameraSpeedSet(4.0f);
    while (1) {
        s16 temp2 = 16;
        HuPrcVSleep();
        MBCameraPos2DGet(sp10);
        temp = MBCameraPos2DSet(sp10);
        func_800FFEC4_113AE4_shared_board(temp_s3, temp);
        if (D_800D5546_D6146[temp_s2] & 0x200) {
            sp10[0] -= 16.0f;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x100) {
            sp10[0] += temp2;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x800) {
            sp10[1] -= temp2;
            var_s1 = 0xF;
        }
        if (D_800D5546_D6146[temp_s2] & 0x400) {
            sp10[1] += temp2;
            var_s1 = 0xF;
        }
        MBCameraPos2DSet(sp10);
        if (var_s1 != 0) {
            var_s1 -= 1;
            MBStatusHideAll();
        } else {
            MBStatusShowAll();
        }

        if (GwPlayer[GwSystem.current_player_index].stat & 1) {
            func_8005F904_60504();
            break;
        }
        if (mbCameraBtnF == 0) {
            break;
        }
        if (D_800C9520_CA120[temp_s2] & 0xE010) {
            break;
        }
    }       
    
    MBHelpWinKill(temp_s6);
    if (var_s4 != NULL) {
        MBHelpWinKill(var_s4);
    }
    func_800FFE90_113AB0_shared_board(temp_s3);
    WipeCreateOut(0, 4);
    HuPrcSleep(4);
    if ((func_800F8858_10C478_shared_board()) == 0) {
        func_800E728C_FAEAC_shared_board();
        func_800E7254_FAE74_shared_board();
        MBCameraSpeedSet(-1.0f);
        temp_f20 = func_800E973C_FD35C_shared_board();
        func_800E9730_FD350_shared_board(1.0f);
        func_800E6FBC_FABDC_shared_board();
        MBCameraZoomSet(D_801056E8_119308_shared_board);
        MBCameraPos2DSet(D_801056EC_11930C_shared_board);
        HuPrcVSleep();
        func_800E9730_FD350_shared_board(temp_f20);
        
        if (var_s7 != 0) {
            func_800DB884_EF4A4_shared_board(GwSystem.current_player_index);
        }
        
        func_800DC08C_EFCAC_shared_board(GwSystem.current_player_index);
        func_80100228_113E48_shared_board();
        
        if (D_800C9930_CA530 != -1) {
            func_800036E8_42E8(D_800C9930_CA530, 0x7F);
        } else {
            func_8004A9DC_4B5DC(0x7F);
        }
        
        WipeCreateIn(0, 4);
        HuPrcSleep(4);
    } else {
        func_80100228_113E48_shared_board();
    }
    MBCameraSpeedSet(temp_f22);
    omDelPrcObj(NULL);
}


void func_80100630_114250_shared_board(void) {
    while (1) {
        MBCameraPos3DSet(&GwPlayer[GwSystem.current_player_index].player_obj->coords);
        HuPrcVSleep();        
    }
}

void MBMapScrollExec(s32 arg0) {
    Process* temp_s0;
    Process* temp_v0;

    D_801056E8_119308_shared_board = MBCameraZoomGet();
    MBCameraPos2DGet(D_801056EC_11930C_shared_board);
    D_800CB99C_CC59C = 1;
    func_80049FB8_4ABB8();
    func_800E6FCC_FABEC_shared_board();
    temp_v0 = omAddPrcObj(func_80100630_114250_shared_board, 0x1005, 0, 0);
    omPrcSetStatBit(temp_v0, 0x20);
    HuPrcChildLink(HuPrcCurrentGet(), MBCameraZoomMotStart(1.0f));
    HuPrcChildWait();
    omDelPrcObj(temp_v0);
    temp_s0 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(func_8010024C_113E6C_shared_board, 0x1005, 0, 0);
    temp_v0->user_data = (void*)arg0;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s0, temp_v0);
    HuPrcChildWait();
    func_8004A0E0_4ACE0();
    D_800CB99C_CC59C = 0;
    func_800E6FBC_FABDC_shared_board();
}
