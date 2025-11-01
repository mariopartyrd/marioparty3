#include "common.h"
#include "ovl_80.h"

typedef struct UnkDice2 {
    s32 unk0;
    s32 unk4;
} UnkDice2;

extern s16 D_80100D90_1149B0_shared_board[4][2];

extern s16 D_800CDD64_CE964;
extern u8 D_800CC0C0_CCCC0;
void func_8004A650_4B250(s32);                           /* extern */
void func_8004A670_4B270(s32);                           /* extern */
void func_8004A880_4B480(s32);                           /* extern */
void func_8004A918_4B518(s32);                           /* extern */
void func_800DBE6C_EFA8C_shared_board(s32);            /* extern */
void func_800DCBCC_F07EC_shared_board(s32);            /* extern */
void func_800DE9B8_F25D8_shared_board(s32, s32, s32, s32); /* extern */
void func_800EE688_1022A8_shared_board(Object*, f32, f32);     /* extern */
void MBPlayerMotionSet(s32 playerIndex, s16 arg1, u16 arg2);
void func_800F2388_105FA8_shared_board(s32, s32, s32, s32, s32); /* extern */
extern s8 D_80105704_119324_shared_board;
extern u8 D_8010570E_11932E_shared_board;

void func_800DAA40_EE660_shared_board(s32 arg0) {
    UnkDiceRelatedInner* temp_s0 = &D_800CDBC8_CE7C8[arg0].UnkDiceInner;

    if ((temp_s0->unk_28 == -1) && (temp_s0->dice->unk_4C == 1)) {
        temp_s0->unk_28 = HuAudFXPlay(0x100);
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

//main dice roll func
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
    UnkDice2* temp_s3;
    UnkDiceRelatedInner* temp_s4;

    var_s1 = 0;
    temp_s3 = HuPrcCurrentGet()->user_data;
    temp_s4 = &D_800CDBC8_CE7C8[temp_s3->unk0].UnkDiceInner;
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
            if (((GwPlayer[temp_s3->unk0].stat & 1) || (D_800D5558_D6158[GwPlayer[temp_s3->unk0].pad] & 0x8000)) && !(HmfModelData[D_800CDBC8_CE7C8[temp_s3->unk0].UnkDiceInner.unk16].unk18 & 4) && (GWBoardFlagCheck(0x11) == 0)) {
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
                    s16* temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                    s16* temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                    func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk8, *temp0, *temp1);
                }
                
                temp_s4->unk8++;
                temp_s3->unk4 = 0;
            } else {
                if (D_8010570E_11932E_shared_board != 1) {
                    HuPrcSleep(10);
                    func_800DBE6C_EFA8C_shared_board(temp_s3->unk0);
                    {
                        s16* temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                        s16* temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                        func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk8, *temp0, *temp1);
                    }    
                    
                    HuPrcSleep(20);
                    if (D_8010570E_11932E_shared_board == 2) {
                        if (temp_s4->unk5 != temp_s4->unk6) {

                        } else {
                            HuAudFXPlay(0x15D);
                            if (temp_s4->unk5 == 7) {
                                MBPlayerVibrate(-1, 3);
                            } else {
                                MBPlayerVibrate(-1, 2);
                            }
                            
                            for (j = 0; j < 0x25; j++) {
                                temp_f22 = (f32) (((j * 4) + j) * 4);
                                temp_f20 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                temp_f20_2 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_2, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                if (temp_s4->unk5 == 0xA) {
                                    temp_f20_3 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_3, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    temp_f20_4 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_4, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                }
                                HuPrcVSleep();                            
                            }
    
                            if (temp_s4->unk5 == 7) {
                                MBDlgWinExec(0x16, 0x3A24);
                                MBCoinChangeCreate(temp_s3->unk0, 20); //triples, 20 coins
                                MBCoinTakeCreate(temp_s3->unk0, 20);
                            } else {
                                MBDlgWinExec(0x16, 0x3A26);
                                MBCoinChangeCreate(temp_s3->unk0, 0xA); //doubles, 10 coins
                                MBCoinTakeCreate(temp_s3->unk0, 10); 
                            }
                            
                            func_8004ACE0_4B8E0(0x274, temp_s3->unk0);
                            MBPlayerMotionSet(temp_s3->unk0, 5, 0);
                            HuPrcSleep(0x1E);
                            MBPlayerMotionSet(temp_s3->unk0, -1, 2);
                        }
                    } else {
                        if (D_8010570E_11932E_shared_board == 3) {
                            if ((temp_s4->unk5 == temp_s4->unk6) && (temp_s4->unk5 == temp_s4->unk7)) {
                                if (temp_s4->unk5 == 7) {
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
                                    temp_f24 = (f32) (temp_s0 * 4);
                                    temp_f20_5 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20_5, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    temp_f20_6 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_6, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    temp_f20_7 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_12, 0, temp_f20_7, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    if (temp_s4->unk5 == 0xA) {
                                        temp_f20_8 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_8, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_9 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_9, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_10 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_12, 1, temp_f20_10, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    }                            
                                }
                                
                                if (temp_s4->unk5 == 7) {
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
                                if (temp_s4->unk5 == 7) {
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
                            func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 2, D_80100D90_1149B0_shared_board[3][0], D_80100D90_1149B0_shared_board[3][1]+ (var_s1 / 2));
                        }
                    }
                    
                    if (D_8010570E_11932E_shared_board == 2) {
                        HuAudFXPlay(0x140);
                    } else if (D_8010570E_11932E_shared_board == 3) {
                        HuAudFXPlay(0x146);
                    }
                    D_8010570E_11932E_shared_board = 1;
                    temp_s4->unk8 = 0;
                    temp_s4->unk5 += temp_s4->unk6 + temp_s4->unk7;
                    temp_s4->unk7 = 0;
                    temp_s4->unk6 = 0;
                    func_800DBEC0_EFAE0_shared_board(temp_s3->unk0);
                    func_800DB884_EF4A4_shared_board(temp_s3->unk0);
                    HuPrcSleep(0x14);
                }
                omDelPrcObj(NULL);
            }
            break;
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DD6C4_F12E4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DD724_F1344_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DDBC8_F17E8_shared_board);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DEB50_F2770_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DEBF0_F2810_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DEC90_F28B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", func_800DECBC_F28DC_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/EE660", D_80102070_115C90_shared_board);
