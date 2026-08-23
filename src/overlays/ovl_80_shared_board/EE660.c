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

typedef struct UnkCoinProc {
    /* 0x00 */ s32  playerNo;
    /* 0x04 */ s32  state;
    /* 0x08 */ s32  unk_08;    // item ID; also indexes D_8010197C texture table
    /* 0x0C */ char unk_0C[4];
} UnkCoinProc;

extern s16 D_80100D90_1149B0_shared_board[4][2];
extern u8 D_801057D9_1193F9_shared_board;

void func_80033430_34030(s16);
void func_800DC9F8_F0618_shared_board(s32);
void func_800EE6C0_1022E0_shared_board(Object*);
void func_800DEB50_F2770_shared_board(void);
void func_8004A650_4B250(s32);
void func_8004A670_4B270(s32);
void func_8004A880_4B480(s32);
void func_8004A918_4B518(s32);
void func_800DBE6C_EFA8C_shared_board(s32);
void func_800DCBCC_F07EC_shared_board(s32);
void func_800DE9B8_F25D8_shared_board(s32, s32, s32, s32);
void func_800EE688_1022A8_shared_board(Object *, f32, f32);
void MBPlayerMotionSet(s32 playerIndex, s16 arg1, u16 arg2);
void func_8000CD00_D900(s16, f32, f32, f32);
s16 func_8000CED8_DAD8(s32, s32);
void func_8000CFA4_DBA4(s16, f32, f32, f32);
void func_8000D018_DC18(s16, f32);
void func_8000D044_DC44(s16);
void func_8008A2A0_8AEA0(f32*, f32);
void func_800ECC54_100874_shared_board(Object*);
void func_800DD724_F1344_shared_board(void);
void func_800DEBF0_F2810_shared_board(void);
void func_800DBC2C_EF84C_shared_board(s32);
void func_800DAF1C_EEB3C_shared_board(omObjData*);
void func_800DB318_EEF38_shared_board(omObjData*);
void func_800DB6A8_EF2C8_shared_board(s32);

typedef struct UnkSharedBoard2 {
    char unk_00[0xC];
    Vec unk_0C;
} UnkSharedBoard2;

extern s8 D_80105704_119324_shared_board;
extern u8 D_8010570E_11932E_shared_board;
extern f32 D_80105708_119328_shared_board;
extern u8 D_8010570F_11932F_shared_board;

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

void func_800DB884_EF4A4_shared_board(s32 arg0) {
    UnkDiceRelated *entry;
    omObjData *obj;
    Vec pos;
    f32 pos2d[2];
    s8 roll;

    entry = &D_800CDBD0_CE7D0[arg0];

    if (entry->unk_05[entry->unk_08] != 0) {
        if ((entry->dice == NULL) || (entry->dice->unk_4C == 2)) {
            pos.x = GwPlayer[arg0].player_obj->coords.x;
            pos.y = GwPlayer[arg0].player_obj->coords.y + D_80105708_119328_shared_board;
            pos.z = GwPlayer[arg0].player_obj->coords.z;
            MBCamera3Dto2D(&pos, pos2d);

            if (entry->unk_0E[entry->unk_08] == -1) {
                func_800DB6A8_EF2C8_shared_board(arg0);
                entry->unk_0B = 0;
            } else {
                roll = entry->unk_08;
                func_80055140_55D40(entry->unk_0E[roll], 0, entry->unk_05[roll], 0);
                HuSprPriSet(entry->unk_0E[entry->unk_08], 0, 0x4000);
                func_800550F4_55CF4(entry->unk_0E[entry->unk_08], 0, 1);
            }

            if ((func_800F8858_10C478_shared_board() == 0) && (D_8010570F_11932F_shared_board == 0)) {
                func_800DE9B8_F25D8_shared_board(arg0, entry->unk_08, pos2d[0], pos2d[1] - 8.0f);
            } else {
                func_80054904_55504(entry->unk_0E[entry->unk_08], 0, pos2d[0], pos2d[1]);
            }

            if ((pos2d[0] >= 0.0f) && (pos2d[0] <= 320.0f) &&
                (pos2d[1] >= 0.0f) && (pos2d[1] <= 240.0f)) {
                func_80054904_55504(entry->unk_0E[entry->unk_08], 0, 160,
                                    120 - (s32)(MBCameraZoomGet() * 24.0f));
            }

            HuSprAttrReset(entry->unk_0E[entry->unk_08], 0, 0x8000);

            if (entry->omObj == NULL) {
                if ((func_800F8858_10C478_shared_board() == 0) && (D_8010570F_11932F_shared_board == 0)) {
                    obj = omAddObj(-0x8000, 0, 0, -1, func_800DAF1C_EEB3C_shared_board);
                    entry->omObj = obj;
                    obj->scale.z = 3.0f;
                    obj->work[1] = entry->unk_08;
                } else {
                    obj = omAddObj(-0x8000, 0, 0, -1, func_800DB318_EEF38_shared_board);
                    entry->omObj = obj;
                    obj->scale.z = 1.0f;
                }
                obj->work[0] = 0;
                obj->work[3] = arg0;
                obj->scale.x = 0.0f;
                obj->rot.x = 270.0f;
                obj->trans.y = 0.0f;
            }
        }
    }
}

void func_800DBC2C_EF84C_shared_board(s32 arg0) {
    UnkDiceRelated *entry;
    s8 forced;
    s32 i;

    entry = &D_800CDBD0_CE7D0[arg0];

    if ((entry->unk_0B == 0) ) {
        if ((entry->unk_08 == 0)) {
            func_800DBEC0_EFAE0_shared_board(arg0);
        }
    }

    entry->unk_0B = 0;

    if (D_8010570F_11932F_shared_board == 1) {
        do {
            if (entry->unk_02[entry->unk_08] != 0) {
                entry->unk_05[entry->unk_08] = entry->unk_02[entry->unk_08];
                entry->unk_02[entry->unk_08] = 0;
            } else {
                entry->unk_05[entry->unk_08] = (rand8() % 10) + 1;
            }

            for (i = 0; i < 5; i++) {
                if (i == arg0) {
                    continue;
                }
                if (D_800CDBD0_CE7D0[i].unk_05[D_800CDBD0_CE7D0[i].unk_08] == entry->unk_05[entry->unk_08]) {
                    break;
                }
            }
        } while (i != 5);
    } else {
        switch (entry->unk_0A) {
            case 0:
            case 1:
            case 2:
            case 4:
                forced = entry->unk_02[entry->unk_08];
                if (forced != 0) {
                    entry->unk_05[entry->unk_08] = forced;
                    entry->unk_02[entry->unk_08] = 0;
                } else {
                    entry->unk_05[entry->unk_08] = (rand8() % 10) + 1;
                }
                break;

            case 3:
                entry->unk_05[entry->unk_08] = (rand8() % 3) + 1;
                break;

            case 5:
                entry->unk_05[entry->unk_08] = 0;
                break;
        }
    }

    func_800DB884_EF4A4_shared_board(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBE6C_EFA8C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBEC0_EFAE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DBFBC_EFBDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC024_EFC44_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC06C_EFC8C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC08C_EFCAC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC0E0_EFD00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC104_EFD24_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DC128_EFD48_shared_board);

s16 func_80032694_33294(HmfData*, u16, s32, s32);
void func_800DAAAC_EE6CC_shared_board(omObjData*);
extern u8 D_80105700_119320_shared_board;

void func_800DC718_F0338_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    UnkDiceRelated *entry;
    omObjData *dice;
    f32 height;
    s32 i;

    entry = &D_800CDBD0_CE7D0[arg0];

    if (entry->unk_16 == -1) {
        if (D_8010570F_11932F_shared_board == 1) {
            D_80105708_119328_shared_board = 250.0f;
        } else {
            D_80105708_119328_shared_board = 25.0f;
        }

        func_800DBEC0_EFAE0_shared_board(arg0);
        entry->unk_0A = 0;

        entry->unk_16 = Hu3DModelCreate(DataRead(arg1), 0x6A9);
        func_8001C8A8_1D4A8(entry->unk_16, 1);
        Hu3DModelScaleSet(entry->unk_16, 0.0f, 0.0f, 0.0f);
        func_8001C2FC_1CEFC(entry->unk_16, 0x20000, 0x20000);
        
        
        if (arg2 != -1) {
            entry->unk_2C = DataRead(arg2);
        } else {
            entry->unk_2C = NULL;
        }

        for (i = 0; i < 6; i++) {
            if (arg3[i] != 0) {
                if (i == 0) {
                    entry->unk_1A[0] = HmfAnimCreate(HmfModelData[entry->unk_16].hmf, entry->unk_2C, 0, arg3[0]);
                } else {
                    entry->unk_1A[1] = func_80032694_33294(HmfModelData[entry->unk_16].hmf, entry->unk_1A[0], 0, arg3[i]);
                }
            } else {
                entry->unk_1A[i] = -1;
            }
        }

        func_8001C448_1D048(entry->unk_16);
        func_8001C954_1D554(entry->unk_16);
        D_80105700_119320_shared_board = 0;

        dice = omAddObj(-0x8000, 1, 1, -1, func_800DAAAC_EE6CC_shared_board);
        entry->dice = dice;
        dice->model[0] = entry->unk_16;
        omSetStatBit(dice, 0xA0);
        dice->trans.x = GwPlayer[arg0].player_obj->coords.x;
        dice->trans.y = GwPlayer[arg0].player_obj->coords.y + D_80105708_119328_shared_board;
        dice->trans.z = GwPlayer[arg0].player_obj->coords.z;
        dice->rot.y = -90.0f;
        dice->scale.z =
        dice->scale.y =
        dice->scale.x =
        dice->rot.x =
        dice->rot.z = 0.0f;
        dice->work[0] = 0;
        dice->work[1] = 0x87;
        dice->work[2] = 0;
        dice->work[3] = arg0;

        entry->unk48 = 1.0f;
        entry->unk40 = 0.0f;
        entry->unk44 = 1.0f;

        HuAudFXPlay(0x10E);
    }
}

void func_800DC9F8_F0618_shared_board(s32 arg0) {
    s32 anims[6] =  {0, 0, 0, 0, 0, 0};

    func_800DC718_F0338_shared_board(arg0, 0x1301FB, -1, anims);
    D_8010570F_11932F_shared_board = 2;
}

s32 const pad2[2] = {0 , 0};

void func_800DCA64_F0684_shared_board(s32 arg0) {
    UnkDiceRelated *entry;
    s16 id;
    s32 i;

    entry = &D_800CDBD0_CE7D0[arg0];

    if (entry->unk_16 != -1) {
        func_8001ACDC_1B8DC(entry->unk_16);
        for (i = 0; i < 6; i++) {
            if (entry->unk_1A[i] != -1) {
                func_80033430_34030(entry->unk_1A[i]);
            }
        }
        if (entry->unk_2C != NULL) {
            DataClose(entry->unk_2C);
        }
        omDelObj((omObjData *)entry->dice);
        entry->dice = NULL;
        entry->unk_16 = -1;
    }

    if (entry->unk_18 != -1) {
        func_8001ACDC_1B8DC(entry->unk_18);
        entry->unk_18 = -1;
        if (entry->unk_38 != NULL) {
            omDelObj(entry->unk_38);
            entry->unk_38 = NULL;
        }
    }

    if (entry->unk_26 != -1) {
        func_80033430_34030(entry->unk_26);
        entry->unk_26 = -1;
    }

    if (entry->unk_30 != NULL) {
        DataClose(entry->unk_30);
        entry->unk_30 = NULL;
    }
}

void func_800DCB8C_F07AC_shared_board(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_800DCA64_F0684_shared_board(i);
        func_800DBEC0_EFAE0_shared_board(i);        
    }
}

void func_800DCBCC_F07EC_shared_board(s32 arg0) {
    UnkDiceRelated *entry;
    s16 sound;
    s32 count;
    s32 i;

    entry = &D_800CDBD0_CE7D0[arg0];

    if (entry->unk_16 != -1) {
        entry->dice->unk_4C = 2;

        if (D_8010570F_11932F_shared_board != 2) {
            func_800DBC2C_EF84C_shared_board(arg0);
        }

        
        if (D_8010570F_11932F_shared_board == 1) {
            count = 0;
            for (i = 0; i < 4; i++) {
                if (D_800CDBD0_CE7D0[i].unk28 != -1) {
                    count++;
                }
            }
        } else {
            count = 1;
        }

        if (count == 1) {
            HuAudFXStop(entry->unk28);
        }
        entry->unk28 = -1;
        entry->unk2A = 0;

        if ((D_8010570F_11932F_shared_board == 2) || (entry->unk_0A == 5)) {
            HuAudFXPlay(0x10D);
        } else {
            HuAudFXPlay(0x103);
        }
        
    }
}

void func_800DCCE0_F0900_shared_board(void) {
    D_8010570F_11932F_shared_board = 1;
    D_80105708_119328_shared_board = 250.0f;
}

s32 func_800DCD00_F0920_shared_board(s32 arg0) {
    if (~D_800CDBD0_CE7D0[arg0].unk_16) {
        return 1;
    } else {
        return 0;
    }
}

void func_800DCD2C_F094C_shared_board(s32 arg0, s32 arg1) {
    D_800CDBD0_CE7D0[arg0].unk_05[D_800CDBD0_CE7D0[arg0].unk_08] = arg1;
}

void func_800DCD64_F0984_shared_board(s32 arg0, s32 arg1) {
    D_800CDBD0_CE7D0[arg0].unk_02[D_800CDBD0_CE7D0[arg0].unk_08] = arg1;
}

s32 func_800DCD9C_F09BC_shared_board(s32 arg0) {
    return D_800CDBD0_CE7D0[arg0].unk_05[D_800CDBD0_CE7D0[arg0].unk_08];
}

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
                            if (temp_s4->unk_05[0] != temp_s4->unk_05[1]) {
                            } else {
                                HuAudFXPlay(0x15D);
                                if (temp_s4->unk_05[0] == 7) {
                                    MBPlayerVibrate(-1, 3);
                                } else {
                                    MBPlayerVibrate(-1, 2);
                                }
                                for (j = 0; j < 37; j++) {
                                    temp_f22 = (f32)(((j * 4) + j) * 4);
                                    temp_f20 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E[0], 0, temp_f20, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    temp_f20_2 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E[1], 0, temp_f20_2, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    if (temp_s4->unk_05[0] == 0xA) {
                                        temp_f20_3 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E[0], 1, temp_f20_3, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                        temp_f20_4 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E[1], 1, temp_f20_4, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    }
                                    HuPrcVSleep();
                                }
                                if (temp_s4->unk_05[0] == 7) {
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
                                if ((temp_s4->unk_05[0] == temp_s4->unk_05[1]) && (temp_s4->unk_05[0] == temp_s4->unk_05[2])) {
                                    if (temp_s4->unk_05[0] == 7) {
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
                                        HuSprScaleSet(temp_s4->unk_0E[0], 0, temp_f20_5, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_6 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E[1], 0, temp_f20_6, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_7 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E[2], 0, temp_f20_7, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        if (temp_s4->unk_05[0] == 0xA) {
                                            temp_f20_8 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_0E[0], 1, temp_f20_8, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_9 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_0E[1], 1, temp_f20_9, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                            temp_f20_10 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                            HuSprScaleSet(temp_s4->unk_0E[2], 1, temp_f20_10, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        }
                                    }
                                    if (temp_s4->unk_05[0] == 7) {
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
                                    if (temp_s4->unk_05[0] == 7) {
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
                        temp_s4->unk_05[0] += temp_s4->unk_05[1] + temp_s4->unk_05[2];
                        temp_s4->unk_05[2] = 0;
                        temp_s4->unk_05[1] = 0;
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

void func_800DDC3C_F185C_shared_board(void) {
    UnkCoinProc *work;
    s32 timer;

    work = HuPrcCurrentGet()->user_data;
    timer = 0;

    while (TRUE) {
        switch (work->state) {
            case 0:
                D_80105704_119324_shared_board = 0;
                func_800DC9F8_F0618_shared_board(work->playerNo);
                D_80105704_119324_shared_board = 1;
                work->state++;
                HuPrcSleep(20);
                break;

            case 1:
                if (D_801057D9_1193F9_shared_board == 0) {
                    work->state++;
                    MBPlayerMotionSet(work->playerNo, 2, 0);
                    func_800EE688_1022A8_shared_board(GwPlayer[work->playerNo].player_obj, 2.0f, -0.3f);
                    mbCameraBtnF = 0;
                    D_800CDD64_CE964 = 0;
                }
                break;

            case 2:
                timer++;
                if (timer >= 5) {
                    func_800DCBCC_F07EC_shared_board(work->playerNo);
                    func_800F2388_105FA8_shared_board(work->playerNo, -1, 0, 10, 2);
                    work->state++;
                }
                break;

            case 3:
                func_800DDBC8_F17E8_shared_board(GwPlayer[work->playerNo].player_obj);
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_800DDDD4_F19F4_shared_board(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800DDC3C_F185C_shared_board, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_801057D9_1193F9_shared_board = 0;
    return temp_v0;
}

void func_800DDE3C_F1A5C_shared_board(void);
#ifdef NOP_FIX //only issue is nops
void func_800DDE3C_F1A5C_shared_board(void) {
    UnkCoinProc *work;
    f32 scale, amp, angle;
    s32 grp, anim, motion;
    s32 gotItem, timer, i;
    void *data;

    gotItem = 0;
    work = HuPrcCurrentGet()->user_data;
    timer = 0;

    while (TRUE) {
        switch (work->state) {
            case 0:
                D_80105704_119324_shared_board = 0;
                func_800DC9F8_F0618_shared_board(work->playerNo);
                D_80105704_119324_shared_board = 1;
                work->state++;
                HuPrcSleep(20);
                break;

            case 1:
                if (D_801057D9_1193F9_shared_board == 0) {
                    work->state++;
                    MBPlayerMotionSet(work->playerNo, 2, 0);
                    func_800EE688_1022A8_shared_board(GwPlayer[work->playerNo].player_obj, 2.0f, -0.3f);
                    mbCameraBtnF = 0;
                    D_800CDD64_CE964 = 0;
                }
                break;

            case 2:
                timer++;
                if (timer >= 5) {
                    func_800DCBCC_F07EC_shared_board(work->playerNo);
                    func_800F2388_105FA8_shared_board(work->playerNo, -1, 0, 10, 2);
                    work->state++;
                }
                break;

            case 3:
                HuAudFXPlay(0x19);
                grp = HuSprGrpCreate(1, 5);
                data = DataRead(D_8010197C_11559C_shared_board[work->unk_08]);
                anim = func_80055810_56410(data);
                DataClose(data);
                func_80055024_55C24(grp, 0, anim, 0);
                HuSprPriSet(grp, 0, 0xB);
                func_800550F4_55CF4(grp, 0, 0);
                HuSprAttrSet(grp, 0, 0x180C);
                func_80054904_55504(grp, 0, 160, 90);
                func_80055458_56058(grp, 0, 0);

                amp = 1.0f / HuMathSin(20.0f);
                //for (angle = 0.0f; angle < 90.0f; HuSprScaleSet(grp, 0, HuMathSin(angle) * amp * 0.8f + 0.2f, HuMathSin(angle) * amp * 0.8f + 0.2f), func_80055458_56058(grp, 0, 0x100), HuPrcVSleep(), angle += 11.25f) {}
                
                for (angle = 0.0f; angle < 90.0f; angle += 11.25f) {
                    //temp variables seem to not impact codegen?
                    f32 temp1 = HuMathSin(angle) * amp * 0.8f + 0.2f;
                    f32 temp2 = HuMathSin(angle) * amp * 0.8f + 0.2f;
                    HuSprScaleSet(grp, 0, temp1, temp2);
                    func_80055458_56058(grp, 0, 0x100);
                    HuPrcVSleep();
                }
                
                //for (; angle > 20.0f; HuSprScaleSet(grp, 0, HuMathSin(angle) * amp * 0.8f + 0.2f, HuMathSin(angle) * amp * 0.8f + 0.2f), HuPrcVSleep(), angle -= 11.25f) {}
                while (angle > 20.0f) {
                    f32 temp1 = HuMathSin(angle) * amp * 0.8f + 0.2f;
                    f32 temp2 = HuMathSin(angle) * amp * 0.8f + 0.2f;
                    HuSprScaleSet(grp, 0, temp1, temp2);
                    HuPrcVSleep();
                    angle -= 11.25f;
                }
                HuSprScaleSet(grp, 0, 1.0f, 1.0f);
                func_80055458_56058(grp, 0, 0x100);

                func_800DE858_F2478_shared_board();
                HuPrcSleep(5);
                while (!func_800DE84C_F246C_shared_board()) {
                    HuPrcVSleep();
                }
                func_800DE868_F2488_shared_board();
                HuPrcSleep(10);

                if (MBItemFindEmpty(work->playerNo) != -1) {
                    gotItem = 1;
                    GwPlayer[work->playerNo].itemNo[MBItemFindEmpty(work->playerNo)] = work->unk_08;
                    HuAudFXPlay(0x10);
                } else {
                    for (i = 1; i < 64; i++) {
                        func_80055458_56058(grp, 0, 255.0f - (i * 3.984f));
                        HuPrcVSleep();
                    }
                    func_80055458_56058(grp, 0, 0);
                }

                HuSprKill(anim);
                HuSprGrpKill(grp);

                if (gotItem != 0) {
                    func_8004ACE0_4B8E0(0x274, work->playerNo);
                    MBPlayerMotionSet(work->playerNo, 5, 0);
                } else {
                    func_8004ACE0_4B8E0(0x286, work->playerNo);
                    MBPlayerMotionSet(work->playerNo, 3, 0);
                }
                
                MBPlayerMotionWait(work->playerNo);
                func_800F2388_105FA8_shared_board(work->playerNo, -1, 0, 10, 2);
                func_800DE858_F2478_shared_board();
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DDE3C_F1A5C_shared_board);
#endif

Process* func_800DE414_F2034_shared_board(s32 arg0, s32 arg1) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800DDE3C_F1A5C_shared_board, 0U, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, 0x10);
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    temp_v0_2->unk_08 = arg1;
    D_801057D9_1193F9_shared_board = 0;
    return temp_v0;
}

void func_800DE48C_F20AC_shared_board(void) {
    Object* temp_v0;
    Object* temp_s0;
    f32 var_f20;
    s32 i;
    
    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_v0 = MBModelCreate(0x19U, NULL);
    HuVecCopyXYZ(&temp_v0->coords, temp_s0->coords.x, 0.0f, temp_s0->coords.z);
    HuVecCopyXYZ(&temp_v0->scale, 2.0f, 2.0f, 2.0f);
    temp_v0->velocity.x = 35.0f;
    var_f20 = (f32) MBRand(360.0f);

    for (i = 0; i < 5; i++) {
        HuPrcVSleep();
        temp_v0->velocity.x += 3.0f;
        var_f20 += 40.0f;
        func_8008A2A0_8AEA0(HmfModelData[temp_v0->omObj1->model[0]].mtx, var_f20);        
    }

    MBModelKill(temp_v0);
    omDelPrcObj(NULL);
}

void func_800DE5B0_F21D0_shared_board(void* arg0) {
    omAddPrcObj(func_800DE48C_F20AC_shared_board, 0x4800U, 0, 0)->user_data = arg0;
}

void func_800DE5EC_F220C_shared_board(void) {
    UnkCoinProc *work;
    s32 i;

    work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        switch (work->state) {
            case 0:
                D_80105704_119324_shared_board = 0;
                func_800DC9F8_F0618_shared_board(work->playerNo);
                D_80105704_119324_shared_board = 1;
                work->state++;
                HuPrcSleep(20);
                break;

            case 1:
                if (D_801057D9_1193F9_shared_board == 0) {
                    work->state++;
                    mbCameraBtnF = 0;
                    D_800CDD64_CE964 = 0;
                }
                break;

            case 2:
                func_800DE858_F2478_shared_board();
                for (i = 0; i < 20; i++) {
                    MBPlayerMotionSet(work->playerNo, 2, 0);
                    func_800EE688_1022A8_shared_board(GwPlayer[work->playerNo].player_obj, 8.0f, -2.4f);
                    HuPrcSleep(2);
                    func_800DE5B0_F21D0_shared_board(GwPlayer[work->playerNo].player_obj);
                    MBCoinTakeCreate(work->playerNo, 1);
                    if (i == 19) {
                        func_800DCBCC_F07EC_shared_board(work->playerNo);
                    }
                    func_800EE6C0_1022E0_shared_board(GwPlayer[work->playerNo].player_obj);
                }
                func_8004ACE0_4B8E0(0x274, work->playerNo);
                MBPlayerMotionSet(work->playerNo, 5, 0);
                HuPrcSleep(30);
                MBPlayerMotionSet(work->playerNo, -1, 2);
                work->state++;
                break;

            case 3:
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_800DE7E4_F2404_shared_board(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800DE5EC_F220C_shared_board, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_801057D9_1193F9_shared_board = 0;
    return temp_v0;
}

u8 func_800DE84C_F246C_shared_board(void) {
    return D_801057D9_1193F9_shared_board;
}

void func_800DE858_F2478_shared_board(void) {
    D_801057D9_1193F9_shared_board = 1;
}

void func_800DE868_F2488_shared_board(void) {
    D_801057D9_1193F9_shared_board = 0;
}


void func_800DE874_F2494_shared_board(s32 arg0) {
    UnkDiceRelated* temp_s0 = &D_800CDBD0_CE7D0[arg0];

    if (temp_s0->unk28 != -1) {
        HuAudFXStop(temp_s0->unk28);
        temp_s0->unk28 = -1;
    }
    temp_s0->unk2A = 1;
}

void func_800DE8D8_F24F8_shared_board(s32 arg0) {
    DiceInstance* temp_v0;
    UnkDiceRelated* temp_s0;
    
    temp_s0 = &D_800CDBD0_CE7D0[arg0];
    if ((temp_s0->unk2A == 1) && (temp_s0->unk_16 != -1)) {
        if ((temp_s0->dice != NULL) && (temp_s0->dice->unk_4C != 2) && (temp_s0->unk_0A != 5) && (D_8010570F_11932F_shared_board != 2)) {
            temp_s0->unk28 = HuAudFXPlay(0x100);
        }
    }
    temp_s0->unk2A = 0;
}

void func_800DE97C_F259C_shared_board(s8 arg0) {
    D_8010570F_11932F_shared_board = arg0;
}

void func_800DE988_F25A8_shared_board(s32 arg0, s32 arg1) {
    D_800CDBD0_CE7D0[arg0].unk_08 = arg1;
}

void func_800DE9AC_F25CC_shared_board(s32 arg0, s32 arg1) {
    D_8010570E_11932E_shared_board = arg1;
}

void func_800DE9B8_F25D8_shared_board(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UnkDiceRelated *entry;

    entry = &D_800CDBD0_CE7D0[arg0];

    if (entry->unk_05[arg1] >= 10) {
        HuSprAttrReset(entry->unk_0E[arg1], 1, 0x8000);
        func_80054904_55504(entry->unk_0E[arg1], 0, arg2 + 10, arg3);
        func_80054904_55504(entry->unk_0E[arg1], 1, -0x1C, 0);
    } else {
        HuSprAttrSet(entry->unk_0E[arg1], 1, 0x8000);
        func_80054904_55504(entry->unk_0E[arg1], 0, arg2, arg3);
    }
}

void func_800DEAA0_F26C0_shared_board(s32 arg0) {
    UnkDiceRelated* temp_a1 = &D_800CDBD0_CE7D0[arg0];
    
    if (temp_a1->dice != NULL) {
        temp_a1->dice->coords.x = GwPlayer[arg0].player_obj->coords.x;
        temp_a1->dice->coords.y = GwPlayer[arg0].player_obj->coords.y + D_80105708_119328_shared_board;
        temp_a1->dice->coords.z = GwPlayer[arg0].player_obj->coords.z;
    }
}

s32 func_800DEB2C_F274C_shared_board(s32 arg0) {
    return D_800CDBD0_CE7D0[arg0].unk_0A;
}

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

// INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", D_80102070_115C90_shared_board);
