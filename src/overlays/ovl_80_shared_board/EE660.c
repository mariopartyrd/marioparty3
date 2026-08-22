#include "common.h"
#include "ovl_80.h"

typedef struct UnkDice2 {
    s32 unk0;
    s32 unk4;
} UnkDice2;

typedef struct UnkSharedBoard {
    s32 playerNo;
    s32 unk_04;
    char unk_08[8];
} UnkSharedBoard; //sizeof 0x10

extern s16 D_80100D90_1149B0_shared_board[4][2];
extern u8 D_801057D9_1193F9_shared_board;

void func_800DEB50_F2770_shared_board(void);
void func_8004A650_4B250(s32);                              /* extern */
void func_8004A670_4B270(s32);                              /* extern */
void func_8004A880_4B480(s32);                              /* extern */
void func_8004A918_4B518(s32);                              /* extern */
void func_800DBE6C_EFA8C_shared_board(s32);                 /* extern */
void func_800DCBCC_F07EC_shared_board(s32);                 /* extern */
void func_800DE9B8_F25D8_shared_board(s32, s32, s32, s32);  /* extern */
void func_800EE688_1022A8_shared_board(Object *, f32, f32); /* extern */
void MBPlayerMotionSet(s32 playerIndex, s16 arg1, u16 arg2);
void func_8000CD00_D900(s16, f32, f32, f32);                 /* extern */
s16 func_8000CED8_DAD8(s32, s32);                       /* extern */
void func_8000CFA4_DBA4(s16, f32, f32, f32);           /* extern */
void func_8000D018_DC18(s16, f32);                     /* extern */
void func_8000D044_DC44(s16);                          /* extern */
void func_8008A2A0_8AEA0(f32*, f32);                   /* extern */
void func_800ECC54_100874_shared_board(Object*);       /* extern */
void func_800DD724_F1344_shared_board(void);
void func_800DEBF0_F2810_shared_board(void);

typedef struct UnkSharedBoard2 {
    char unk_00[0xC];
    Vec unk_0C;
} UnkSharedBoard2;

extern s8 D_80105704_119324_shared_board;
extern u8 D_8010570E_11932E_shared_board;

void func_800DAA40_EE660_shared_board(s32 arg0) {
    UnkDiceRelated* temp_s0;

    temp_s0 = &D_800CDBD0_CE7D0[arg0];
    if ((temp_s0->unk28 == -1) && (temp_s0->dice->unk_4C == 1)) {
        temp_s0->unk28 = HuAudFXPlay(0x100);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DAAAC_EE6CC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DAF1C_EEB3C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DB318_EEF38_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DB56C_EF18C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DB5DC_EF1FC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DB6A8_EF2C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DB884_EF4A4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBC2C_EF84C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBE6C_EFA8C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBEC0_EFAE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBFBC_EFBDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC024_EFC44_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC06C_EFC8C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC08C_EFCAC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC0E0_EFD00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC104_EFD24_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC128_EFD48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC718_F0338_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC9F8_F0618_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCA64_F0684_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCB8C_F07AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCBCC_F07EC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCCE0_F0900_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCD00_F0920_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCD2C_F094C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCD64_F0984_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DCD9C_F09BC_shared_board);

void func_800DCDD4_F09F4_shared_board(void) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f20_10;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    s16 var_a0;
    s16 var_a1;
    s32 temp_s0;
    s32 var_s1;
    s32 var_s5;
    s32 i, j;
    UnkDice2 *temp_s3;
    UnkDiceRelated *temp_s4;
    var_s1 = 0;
    temp_s3 = HuPrcCurrentGet()->user_data;
    temp_s4 = &D_800CDBD0_CE7D0[temp_s3->unk0];
    var_s5 = 0;
    while (1) {
        switch (temp_s3->unk4) {
            case 0:
                D_80105704_119324_shared_board = 0;
                func_800DC128_EFD48_shared_board(temp_s3->unk0);
                D_80105704_119324_shared_board = 1;
                temp_s3->unk4++;
                HuPrcSleep(0x14);
                break;
            case 1:
                if (((GwPlayer[temp_s3->unk0].stat & 1) || (D_800D5558_D6158[GwPlayer[temp_s3->unk0].pad] & 0x8000)) && !(HmfModelData[D_800CDBD0_CE7D0[temp_s3->unk0].unk_16].unk18 & 4) && (GWBoardFlagCheck(0x11) == 0)) {
                    temp_s3->unk4++;
                    MBPlayerMotionSet(temp_s3->unk0, 2, 0);
                    func_800EE688_1022A8_shared_board(GwPlayer[temp_s3->unk0].player_obj, 2.0f, -0.3f);
                    mbCameraBtnF = 0;
                    D_800CDD64_CE964 = 0;
                }
                break;
            case 2:
                if (++var_s1 >= 5) {
                    func_800DCBCC_F07EC_shared_board(temp_s3->unk0);
                    func_800F2388_105FA8_shared_board(temp_s3->unk0, -1, 0, 0xA, 2);
                    temp_s3->unk4++;
                }
                break;
            case 3:
                HuPrcSleep(20);
                if (++var_s5 != D_8010570E_11932E_shared_board) {
                    HuPrcSleep(10);
                    var_s1 = 0;
                    func_800DBE6C_EFA8C_shared_board(temp_s3->unk0);
                    {
                        s16 *temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                        s16 *temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                        func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk_08, *temp0, *temp1);
                    }
                    temp_s4->unk_08++;
                    temp_s3->unk4 = 0;
                } else {
                    if (D_8010570E_11932E_shared_board != 1) {
                        HuPrcSleep(10);
                        func_800DBE6C_EFA8C_shared_board(temp_s3->unk0);
                        {
                            s16 *temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                            s16 *temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                            func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk_08, *temp0, *temp1);
                        }
                        HuPrcSleep(20);
                        if (D_8010570E_11932E_shared_board == 2) {
                            if (temp_s4->unk_05 != temp_s4->unk_06) {
                            } else {
                                HuAudFXPlay(0x15D);
                                if (temp_s4->unk_05 == 7) {
                                    MBPlayerVibrate(-1, 3);
                                } else {
                                    MBPlayerVibrate(-1, 2);
                                }
                                for (j = 0; j < 37; j++) {
                                    temp_f22 = (f32)(((j * 4) + j) * 4);
                                    temp_f20 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    temp_f20_2 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_2, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    if (temp_s4->unk_05 == 0xA) {
                                        temp_f20_3 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_3, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                        temp_f20_4 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_4, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    }
                                    HuPrcVSleep();
                                }
                                if (temp_s4->unk_05 == 7) {
                                    MBDlgWinExec(0x16, 0x3A24);
                                    MBCoinChangeCreate(temp_s3->unk0, 20);
                                    MBCoinTakeCreate(temp_s3->unk0, 20);
                                } else {
                                    MBDlgWinExec(0x16, 0x3A26);
                                    MBCoinChangeCreate(temp_s3->unk0, 10);
                                    MBCoinTakeCreate(temp_s3->unk0, 10);
                                }
                                func_8004ACE0_4B8E0(0x274, temp_s3->unk0);
                                MBPlayerMotionSet(temp_s3->unk0, 5, 0);
                                HuPrcSleep(0x1E);
                                MBPlayerMotionSet(temp_s3->unk0, -1, 2);
                            }
                        } else {
                            if (D_8010570E_11932E_shared_board == 3) {
                                if ((temp_s4->unk_05 == temp_s4->unk_06) && (temp_s4->unk_05 == temp_s4->unk_07)) {
                                    if (temp_s4->unk_05 == 7) {
                                        mbItemBtnF = 0;
                                        HuAudFXPlay(0x15E);
                                        func_8004A670_4B270(0);
                                        func_8004A918_4B518(0x69);
                                        func_8004A880_4B480(0);
                                        func_8004A650_4B250(0xF);
                                        MBPlayerVibrate(-1, 4);
                                    } else {
                                        HuAudFXPlay(0x15D);
                                        MBPlayerVibrate(-1, 3);
                                    }
                                    for (i = 0; i < 73; i++, HuPrcVSleep()) {
                                        var_s1 = i;
                                        temp_s0 = (i * 4) + var_s1;
                                        temp_f24 = (f32)(temp_s0 * 4);
                                        temp_f20_5 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20_5, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_6 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_6, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_7 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_12, 0, temp_f20_7, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        if (temp_s4->unk_05 == 0xA) {
                                            temp_f20_8 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_8, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_9 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_9, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_10 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_12, 1, temp_f20_10, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        }
                                    }
                                    if (temp_s4->unk_05 == 7) {
                                        MBDlgWinExec(0x16, 0x3A25);
                                        MBCoinChangeCreate(temp_s3->unk0, 0x32);
                                        MBCoinTakeCreate(temp_s3->unk0, 0x32);
                                        D_800CC0C0_CCCC0 = 1;
                                    } else {
                                        MBDlgWinExec(0x16, 0x3A24);
                                        MBCoinChangeCreate(temp_s3->unk0, 0x14);
                                        MBCoinTakeCreate(temp_s3->unk0, 0x14);
                                    }
                                    func_8004ACE0_4B8E0(0x274, temp_s3->unk0);
                                    MBPlayerMotionSet(temp_s3->unk0, 5, 0);
                                    HuPrcSleep(0x1E);
                                    if (temp_s4->unk_05 == 7) {
                                        mbItemBtnF = 1;
                                    }
                                    MBPlayerMotionSet(temp_s3->unk0, -1, 2);
                                }
                            }
                        }
                        for (var_s1 = 0; var_s1 < 50; HuPrcVSleep(), var_s1 += 2) {
                            func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 0, D_80100D90_1149B0_shared_board[1][0] + var_s1, D_80100D90_1149B0_shared_board[1][1] + (var_s1 / 2));
                            func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 1, D_80100D90_1149B0_shared_board[2][0] - var_s1, D_80100D90_1149B0_shared_board[2][1] + (var_s1 / 2));
                            if (D_8010570E_11932E_shared_board == 3) {
                                func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 2, D_80100D90_1149B0_shared_board[3][0], D_80100D90_1149B0_shared_board[3][1] + (var_s1 / 2));
                            }
                        }
                        if (D_8010570E_11932E_shared_board == 2) {
                            HuAudFXPlay(0x140);
                        } else if (D_8010570E_11932E_shared_board == 3) {
                            HuAudFXPlay(0x146);
                        }
                        D_8010570E_11932E_shared_board = 1;
                        temp_s4->unk_08 = 0;
                        temp_s4->unk_05 += temp_s4->unk_06 + temp_s4->unk_07;
                        temp_s4->unk_07 = 0;
                        temp_s4->unk_06 = 0;
                        func_800DBEC0_EFAE0_shared_board(temp_s3->unk0);
                        func_800DB884_EF4A4_shared_board(temp_s3->unk0);
                        HuPrcSleep(0x14);
                    }
                    omDelPrcObj(0);
                }
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_800DD6C4_F12E4_shared_board(s32 playerNo) {
    Process* proc;
    UnkSharedBoard* temp_v0_2;

    proc = omAddPrcObj(func_800DCDD4_F09F4_shared_board, 0U, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(proc->heap, sizeof(UnkSharedBoard));
    proc->user_data = temp_v0_2;
    temp_v0_2->playerNo = playerNo;
    temp_v0_2->unk_04 = 0;
    return proc;
}

void func_800DD724_F1344_shared_board(void) {
    Vec sp10;
    GW_PLAYER* temp_s4;
    Object* temp_v0;
    Object* temp_v0_3;
    Vec* temp_a2;
    f32 var_f20;
    f32 var_f22;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    UnkSharedBoard2* temp_s0;
    s32 i;

    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_s4 = MBPlayerGet(-1);
    HuAudFXPlay(0x11B);
    temp_v0 = MBModelCreate(0x1AU, NULL);
    temp_v0->flags |= 4;
    func_800ECC54_100874_shared_board(temp_v0);
    HuVecCopyXYZ(&temp_v0->coords, temp_s0->unk_0C.x, temp_s0->unk_0C.y + 10.0f, temp_s0->unk_0C.z - 10.0f);
    HuVecCopyXYZ(&sp10, gCameraList->pos.x, gCameraList->pos.y, gCameraList->pos.z);
    temp_v0->velocity.x = 15.0f;
    temp_v0_2 = func_8000CED8_DAD8(0xB0004, 0xAA9);
    func_8000CD00_D900(temp_v0_2, 1.0f, 20.0f, 1.0f);
    func_8000D018_DC18(temp_v0_2, 15.0f);
    func_8001C8A8_1D4A8(temp_v0_2, 1);
    func_8000CFA4_DBA4(temp_v0_2, temp_v0->coords.x, temp_v0->coords.y + temp_v0->velocity.x, temp_v0->coords.z);
    
    for (var_f20 = 0.0f, i = 0; i < 6; i++) {
        HuVecCopyXYZ(&temp_v0->scale, var_f20, var_f20, var_f20);
        var_f20 += 0.5f;
        func_8000D018_DC18(temp_v0_2, var_f20 * 15.0f);
        HuPrcVSleep();
    }

    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&temp_v0->scale, var_f20, var_f20, var_f20);
        var_f20 -= 0.4f;
        func_8000D018_DC18(temp_v0_2, var_f20 * 15.0f);
        HuPrcVSleep();
    }

    func_8000D018_DC18(temp_v0_2, var_f20 * 15.0f);
    HuPrcSleep(0x14);
    func_800DE858_F2478_shared_board();

    //? this seems overlay complex for how simple it is
    while (1) {
        if (D_801057D9_1193F9_shared_board != 0) {
            HuPrcVSleep();
        } else {
            break;
        }        
    }

    
    HuAudFXPlay(0x132);
    var_f22 = 0.0f;
    temp_v0_3 = temp_s4->player_obj;
    HuVecCopyXYZ(&sp10, temp_v0_3->coords.x, temp_v0_3->coords.y - 10.0f, temp_v0_3->coords.z);
    temp_a2 = &temp_v0->coords;
    MBPlayerPosMoveCreate(temp_a2, &sp10, temp_a2, 0x28);

    for (i = 0; i < 0x28; i++) {
        func_8008A2A0_8AEA0(HmfModelData[temp_v0->omObj1->model[0]].mtx, var_f22);
        var_f22 += 20.0f;
        var_f20 -= 0.05f;
        
        if (var_f20 < 0.0f) {
            var_f20 = 0.0f;
        }
        HuVecCopyXYZ(&temp_v0->scale, var_f20, var_f20, var_f20);
        func_8000D018_DC18(temp_v0_2, var_f20 * 15.0f);
        func_8000CFA4_DBA4(temp_v0_2, temp_v0->coords.x, temp_v0->coords.y + temp_v0->velocity.x, temp_v0->coords.z);
        HuPrcVSleep();
    }

    MBModelKill(temp_v0);
    func_8000D044_DC44(temp_v0_2);
    MBPlayerVibrate(-1, 5);
    func_8004A670_4B270(0xE);

    GwPlayer[GwSystem.current_player_index].star++;

    if (GwPlayer[GwSystem.current_player_index].star > 99) {
        GwPlayer[GwSystem.current_player_index].star = 99;
    }
    
    MBVecForwardSet(&temp_s4->player_obj->rot);
    MBPlayerMotionSet(-1, 6, 0);
    func_8004ACE0_4B8E0(0x262, GwSystem.current_player_index);
    HuPrcSleep(16);
    func_80003A70_4670(D_800CDBC8_CE7C8);
    func_8004A918_4B518(0x6F);
    func_8004A880_4B480(0);
    HuPrcSleep(110);
    func_80003B70_4770(D_800CDBC8_CE7C8, 0);
    func_8004A72C_4B32C(0xF);
    omDelPrcObj(NULL);
}

void func_800DDBC8_F17E8_shared_board(void* arg0) {
    Process* temp_v0;

    mbItemBtnF = 0;
    temp_v0 = omAddPrcObj(func_800DD724_F1344_shared_board, 0x4800U, 0, 0);
    temp_v0->user_data = arg0;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0);
    HuPrcChildWait();
    mbItemBtnF = 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DDC3C_F185C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DDDD4_F19F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DDE3C_F1A5C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE414_F2034_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE48C_F20AC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE5B0_F21D0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE5EC_F220C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE7E4_F2404_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE84C_F246C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE858_F2478_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE868_F2488_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE874_F2494_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE8D8_F24F8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE97C_F259C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE988_F25A8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE9AC_F25CC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DE9B8_F25D8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DEAA0_F26C0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DEB2C_F274C_shared_board);

void func_800DEB50_F2770_shared_board(void) {
    f32 var_f20 = 96.0f;

    func_8004A9DC_4B5DC(0x60);

    while (var_f20 < 127.0f) {
        HuPrcVSleep();
        var_f20 += 1.9375f;
        if (var_f20 >= 127.0f) {
            var_f20 = 127.0f;
        }
        func_8004A9DC_4B5DC(var_f20);        
    }
    omDelPrcObj(NULL);
}

void func_800DEBF0_F2810_shared_board(void) {
    f32 var_f20 = 127.0f;
    
    func_8004A9DC_4B5DC(0x7F);
    while (var_f20 > 96.0f) {
        HuPrcVSleep();
        var_f20 -= 1.9375f;
        if (var_f20 <= 96.0f) {
            var_f20 = 96.0f;
        }
        func_8004A9DC_4B5DC(var_f20);
    }
    omDelPrcObj(NULL);
}

void func_800DEC90_F28B0_shared_board(void) {
    omAddPrcObj(func_800DEBF0_F2810_shared_board, 0xEFFF, 0, 0);
}

void func_800DECBC_F28DC_shared_board(void) {
    omAddPrcObj(func_800DEB50_F2770_shared_board, 0xEFFF, 0, 0);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", D_80102070_115C90_shared_board);
