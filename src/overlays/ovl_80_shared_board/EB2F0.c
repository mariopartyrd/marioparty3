#include "common.h"
#include "ovl_80.h"

extern s32 D_80102700_116320_shared_board;
extern s16 D_80102704_116324_shared_board;

typedef struct UnkBoard6 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ Object* unk4;
    /* 0x08 */ Process *process;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ Vec unk10;
} UnkBoard6;

typedef struct StarGlowData {
    s16 x;
    s16 y;
} StarGlowData; //sizeof 0x4

extern UnkBoard6 D_80102708_116328_shared_board[32];
extern s16 D_80102704_116324_shared_board;
void func_80055484_56084(s16 group, s16 member, u8 arg2, u8 arg3, u8 arg4, u16 arg5);
void MBMapFullMain(void);
void func_8004A0E0_4ACE0(void);
void func_80049FB8_4ABB8(void);

void func_800D76D0_EB2F0_shared_board(s32 arg0) {
    s32 i;

    D_80102700_116320_shared_board = arg0;
    for (i = 0; i < ARRAY_COUNT(D_80102708_116328_shared_board); i++) {
        D_80102708_116328_shared_board[i].unk_00 = -1;
    }

    D_80102704_116324_shared_board = 0;
}

void func_800D7714_EB334_shared_board(void) {
}

s32 func_800D771C_EB33C_shared_board(s8 arg0, Object* arg1, s16 arg2, s16 arg3) {
    UnkBoard6* temp_v0;

    temp_v0 = &D_80102708_116328_shared_board[D_80102704_116324_shared_board++];
    temp_v0->unk_00 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unkC = arg2;
    temp_v0->unkE = arg3;
    return D_80102704_116324_shared_board - 1;
}

void func_800D7770_EB390_shared_board(s32 arg0) {
    D_80102708_116328_shared_board[arg0].unk_00 = -1;
}

void func_800D7790_EB3B0_shared_board(s8 arg0, Vec* arg1, s16 arg2, s16 arg3) {
    UnkBoard6* temp_v1;

    temp_v1 = &D_80102708_116328_shared_board[D_80102704_116324_shared_board++];
    temp_v1->unk_00 = arg0;
    temp_v1->unk4 = 0;
    temp_v1->unkC = arg2;
    temp_v1->unkE = arg3;
    HuVecCopy3F(&temp_v1->unk10, arg1);
}

void MBMapFullStarGlowKill(void) {
    UnkBoard6 *entry;
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_80102708_116328_shared_board); i++) {
        entry = &D_80102708_116328_shared_board[i];
        if (entry->unk_00 >= 0) {
            if (entry->process != NULL) {
                omDelPrcObj(entry->process);
            }
            entry->process = NULL;
        }
    }
}

void MBMapFullStarGrow(void) {
    f32 temp_f0;
    f32 var_f20;
    f32 var_f22;
    StarGlowData* temp_s0;
    s32 temp;

    temp_s0 = HuPrcCurrentGet()->user_data;
    var_f20 = 0.0f;
    var_f22 = 0.0f;
    while (1) {
        temp_f0 = HuMathSin(var_f22);
        temp_f0 = ((temp_f0 < 0.0f)) ? -temp_f0 : temp_f0;

        temp = (s32) (temp_f0 * 255.0f);
        var_f22 += 6.0f;
        
        if (var_f22 > 360.0f) {
            var_f22 -= 360.0f;
        }
        
        func_80055484_56084(temp_s0->x, temp_s0->y, 0xFF, temp, 0, 0xC0);

        temp_f0 = HuMathSin(var_f20);
        temp_f0 = (temp_f0 < 0.0f) ? 0.0f : 0.2f;
        
        var_f20 += 15.0f;
        if (var_f20 > 360.0f) {
            var_f20 -= 360.0f;
        }

        HuSprScaleSet(temp_s0->x, temp_s0->y, temp_f0 + 1.0f, temp_f0 + 1.0f);
        HuPrcVSleep();        
    }
}

Process* MBMapFullStarGlowCreate(s16 xPos, s16 yPos) {
    StarGlowData* starGlowData;
    Process* starGlowProc;

    starGlowProc = omAddPrcObj(MBMapFullStarGrow, 0x1005, 0, 0x40);
    starGlowData = HuMemMemoryAlloc(starGlowProc->heap, sizeof(StarGlowData));
    starGlowProc->user_data = starGlowData;
    starGlowData->x = xPos;
    starGlowData->y = yPos;
    return starGlowProc;
}

extern s16 D_801007F4_114414_shared_board[];
extern s16 D_801007FC_11441C_shared_board[];
extern s16 D_80102A88_1166A8_shared_board[];
extern s16 D_80102A90_1166B0_shared_board[];

void MBMapFullLinePosFix(UnkBoard8* arg0, s16 arg1) {
    Vec sp10;
    f32 vecAngle;

    func_80054904_55504(arg0->spriteGroup, 0, D_801007F4_114414_shared_board[arg1], D_801007FC_11441C_shared_board[arg1]);
    func_80054904_55504(arg0->spriteGroup, 1, D_801007F4_114414_shared_board[arg1], D_801007FC_11441C_shared_board[arg1]);
    sp10.x = D_80102A88_1166A8_shared_board[arg1] - D_801007F4_114414_shared_board[arg1];
    sp10.y = 0;
    sp10.z = D_80102A90_1166B0_shared_board[arg1] - D_801007FC_11441C_shared_board[arg1];
    vecAngle = MBVecAngleGet(&sp10);
    HuSprScaleSet(arg0->spriteGroup, 0, 0.25f, HuSqrtf((sp10.x * sp10.x) + (sp10.z * sp10.z)) / 32.0f);
    func_800552DC_55EDC(arg0->spriteGroup, 0, vecAngle);
}

extern UnkBoard8* D_80102A98_1166B8_shared_board[];

void MBMapFullLineCreate(void) {
    UnkBoard8* temp_s0;
    s32 i;
    void* temp_v0;
    void* temp_v0_2;

    for (i = 0; i < 4; i++) {
        temp_s0 = func_800F2C48_106868_shared_board(2, 0);
        temp_v0 = DataRead(0x1301CE);
        temp_s0->model[0] = func_80055810_56410(temp_v0);
        func_80055024_55C24(temp_s0->spriteGroup, 0, temp_s0->model[0], 0);
        HuSprAttrSet(temp_s0->spriteGroup, 0, 0x01001808);
        HuSprPriSet(temp_s0->spriteGroup, 0, 2);
        func_80055484_56084(temp_s0->spriteGroup, 0, 0, 0, 0xFF, 0x80);
        DataClose(temp_v0);
        temp_v0_2 = DataRead(0x1301CD);
        temp_s0->model[1] = func_80055810_56410(temp_v0_2);
        func_80055024_55C24(temp_s0->spriteGroup, 1, temp_s0->model[1], 0);
        HuSprAttrSet(temp_s0->spriteGroup, 1, 0x01001808);
        HuSprPriSet(temp_s0->spriteGroup, 1, 2);
        func_80055484_56084(temp_s0->spriteGroup, 1, 0, 0, 0xFF, 0x80);
        DataClose(temp_v0_2);
        MBMapFullLinePosFix(temp_s0, i);
        D_80102A98_1166B8_shared_board[i] = temp_s0;    
    }
}

void func_800D7D00_EB920_shared_board(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800F2CA4_1068C4_shared_board(D_80102A98_1166B8_shared_board[i]);
    }
}

extern UnkBoard8* D_80102A98_1166B8_shared_board[];
extern s16 D_80102AA8_1166C8_shared_board;

void MBMapFullLineFlash(void) {
    UnkBoard8 *entry;
    s16 sel;
    s32 i;
    s16 alpha;
    f32 angle;

    sel = -1;
    angle = 90.0f;

    while (1) {
        //TODO: matching hack
        if (entry->spriteGroup) {
            HuPrcVSleep();
        } else {
            HuPrcVSleep();
        }
        
        if (sel != D_80102AA8_1166C8_shared_board) {
            sel = D_80102AA8_1166C8_shared_board;
            for (i = 0; i < 4; i++) {
                entry = D_80102A98_1166B8_shared_board[i];
                if (i == sel) {
                    HuSprPriSet(entry->spriteGroup, 0, 2);
                    HuSprPriSet(entry->spriteGroup, 1, 2);
                } else {
                    func_80055484_56084(entry->spriteGroup, 0, 0, 0, 0xFF, 0xA0);
                    func_80055484_56084(entry->spriteGroup, 1, 0, 0, 0xFF, 0xFF);
                    HuSprPriSet(entry->spriteGroup, 0, 3);
                    HuSprPriSet(entry->spriteGroup, 1, 3);
                }
                
                HuSprAttrReset(entry->spriteGroup, 0, 0x8000);
                HuSprAttrReset(entry->spriteGroup, 1, 0x8000);
            }
        }

        entry = D_80102A98_1166B8_shared_board[sel];
        alpha = (HuMathSin(angle) * 255.0f);
        alpha = (alpha < 0) ? -alpha : alpha;
        
        angle += 6.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
 
        func_80055484_56084(entry->spriteGroup, 0, 0xFF, alpha, 0, 0xA0);
        func_80055484_56084(entry->spriteGroup, 1, 0xFF, alpha, 0, 0xFF);
    }
}

void MBCameraPos2DGet(f32 *arg0);
void MBCameraPos2DSet(f32 *);

f32 MBCameraZoomGet(void);                              /* extern */
void MBCameraZoomSet(f32);                             /* extern */
void MBStatusShowAll(void);                                /* extern */
void func_8004A9DC_4B5DC(s32);                           /* extern */
void func_800DC024_EFC44_shared_board(s32);            /* extern */
void func_800DC08C_EFCAC_shared_board(s32);             /* extern */
void func_800EA348_FDF68_shared_board(void);               /* extern */
void func_800EA358_FDF78_shared_board(void);               /* extern */
void func_800EA6B0_FE2D0_shared_board(s16 arg0);              /* extern */
extern s32 D_801007A0_1143C0_shared_board[];
extern s16 D_801007D4_1143F4_shared_board[][4];
extern s32 D_80100804_114424_shared_board[];
extern s32 D_80100824_114444_shared_board[];
extern s32 D_80105990_1195B0_shared_board;

void MBMapFullMain(void) {
    f32 sp10[2];            /* MBCameraPos2DGet target (sp10/sp14) */
    f32 sp18[2];            /* MBCamera3Dto2D target (sp18/sp1C) */
    s32 userData;        /* sp24 */
    s32 savedBack;       /* sp2C */
    s16 sel;             /* sp36 */
    Process *lineFlash;  /* sp3C */
    GW_PLAYER *player;
    UnkBoard6 *entry;
    UnkBoard8 *iconGrp;  /* temp_fp */
    UnkBoard8 *charGrp;  /* temp_s6 */
    Unk3 *help0, *help1;
    Vec *pos;
    f32 savedZoom;
    s16 mid, y;
    s16 dir;
    s32 i, j, k;
    void *data;

    userData = (s32)HuPrcCurrentGet()->user_data; //this is correct, usage is strange here
    savedBack = D_80105990_1195B0_shared_board;
    sel = 0;

    for (i = 0; i < 4; i++) {
        if (MBPlayerComCheck(i) != 0) {
            continue;
        }
        if (GwPlayer[i].pad == userData) {
            sel = i;
            break;
        }
    }

    D_80102AA8_1166C8_shared_board = sel;
    savedZoom = MBCameraZoomGet();
    MBCameraPos2DGet(sp10);
    WipeCreateOut(0, 8);
    HuPrcSleep(8);
    func_800EA358_FDF78_shared_board();
    MBStatusHideAll();
    func_800DC024_EFC44_shared_board(userData);
    HuPrcVSleep();
    HmfPauseF = 1;
    D_80105706_119326_shared_board &= ~1;
    func_800DBEC0_EFAE0_shared_board(GwSystem.current_player_index);
    func_800DC024_EFC44_shared_board(GwSystem.current_player_index);
    func_800EA6B0_FE2D0_shared_board(1);
    MBBackKill();
    MBBackLoad(D_80102700_116320_shared_board);
    iconGrp = func_800F2C48_106868_shared_board(0x20, 0);

    for (i = 0; i < 4; i++) {
        player = MBPlayerGet(i);
        MBCamera3Dto2D(&MBMasuGet(MBMasuLinkMasuIdGet(player->clink, player->cidx))->coords, sp18);
        D_80102A88_1166A8_shared_board[i] = sp18[0];
        D_80102A90_1166B0_shared_board[i] = sp18[1];
    }

    
    for (i = 0, j = 0; j < 0x20; i++, j++) {
        entry = &D_80102708_116328_shared_board[j];
        if (entry->unk_00 >= 0) {
            data = DataRead(D_801007A0_1143C0_shared_board[entry->unk_00]);
            iconGrp->model[i] = func_80055810_56410(data);
            func_80055024_55C24(iconGrp->spriteGroup, i, iconGrp->model[i], 0);
            HuSprAttrSet(iconGrp->spriteGroup, i, 0x01001000);
            if (entry->unk4 != NULL) {
                MBCamera3Dto2D(&entry->unk4->coords, sp18);
            } else {
                MBCamera3Dto2D(&entry->unk10, sp18);
            }
            
            mid = (s32)sp18[0] + entry->unkC;
            y   = (s32)sp18[1] + entry->unkE;
            func_80054904_55504(iconGrp->spriteGroup, i, mid, y);
            HuSprPriSet(iconGrp->spriteGroup, i, ~y);
            DataClose(data);
            if (entry->unk_00 == 0xB) {
                i++;
                data = DataRead(0x1301D3);
                iconGrp->model[i] = func_80055810_56410(data);
                func_80055024_55C24(iconGrp->spriteGroup, i, iconGrp->model[i], 0);
                HuSprAttrSet(iconGrp->spriteGroup, i, 0x01001808);
                func_80054904_55504(iconGrp->spriteGroup, i, mid, y - 1);
                HuSprPriSet(iconGrp->spriteGroup, i, 0xFFFF);
                DataClose(data);
                entry->process = MBMapFullStarGlowCreate(iconGrp->spriteGroup, i);
            }
        }
    }

    MBMapFullLineCreate();
    lineFlash = omAddPrcObj(MBMapFullLineFlash, 0x1005, 0, 0);
    charGrp = func_800F2C48_106868_shared_board(8, 0);

    for (i = 0; i < 4; i++) {
        player = MBPlayerGet(i);
        data = DataRead(D_80100804_114424_shared_board[player->chr]);
        charGrp->model[i] = func_80055810_56410(data);
        func_80055024_55C24(charGrp->spriteGroup, i, charGrp->model[i], 0);
        HuSprPriSet(charGrp->spriteGroup, i, 1);
        HuSprAttrSet(charGrp->spriteGroup, i, 0x01001000);
        func_80054904_55504(charGrp->spriteGroup, i,
                            D_801007F4_114414_shared_board[i] - 0x1E,
                            D_801007FC_11441C_shared_board[i]);
        DataClose(data);

        data = DataRead(D_80100824_114444_shared_board[player->chr]);
        charGrp->model[i+4] = func_80055810_56410(data);
        func_80055024_55C24(charGrp->spriteGroup, i + 4, charGrp->model[i + 4], 0);
        HuSprPriSet(charGrp->spriteGroup, i + 4, 1);
        HuSprAttrSet(charGrp->spriteGroup, i + 4, 0x01001000);
        func_80054904_55504(charGrp->spriteGroup, i + 4,
                            D_801007F4_114414_shared_board[i] + 8,
                            D_801007FC_11441C_shared_board[i]);
        DataClose(data);
    }

    func_8004A9DC_4B5DC(0x60);
    WipeCreateIn(0, 8);
    HuPrcSleep(7);
    help0 = func_800E210C_F5D2C_shared_board(0, 0xC0, 0);
    help1 = func_800E210C_F5D2C_shared_board(4, 0xCE, 0);

    do {
        u16 pad;
        HuPrcVSleep();
        pad = D_800C9520_CA120[userData];
        dir = -((pad & 0x800) == 0);
        if (pad & 0x400) {
            dir = 1;
        }
        if (D_800C9520_CA120[userData] & 0x200) {
            dir = 2;
        }
        if (D_800C9520_CA120[userData] & 0x100) {
            dir = 3;
        }
        if (dir != -1) {
            sel += D_801007D4_1143F4_shared_board[sel][dir];
        }
        D_80102AA8_1166C8_shared_board = sel;
    } while (!(D_800D5558_D6158[userData] & 0xE010));

    WipeCreateOut(0, 8);
    HuPrcSleep(8);
    HmfPauseF = 0;
    MBBackKill();
    MBBackLoad(savedBack);
    MBCameraZoomSet(savedZoom);
    MBCameraPos2DSet(sp10);
    HuPrcVSleep();
    D_80105706_119326_shared_board |= 1;
    func_800DB884_EF4A4_shared_board(GwSystem.current_player_index);
    func_800DC08C_EFCAC_shared_board(GwSystem.current_player_index);
    MBHelpWinKill(help0);
    MBHelpWinKill(help1);
    omDelPrcObj(lineFlash);
    func_800F2CA4_1068C4_shared_board(charGrp);
    func_800F2CA4_1068C4_shared_board(iconGrp);
    func_800D7D00_EB920_shared_board();
    MBMapFullStarGlowKill();
    func_800EA348_FDF68_shared_board();
    func_800DC08C_EFCAC_shared_board(userData);
    MBStatusShowAll();
    func_800EA6B0_FE2D0_shared_board(0);
    func_8004A9DC_4B5DC(0x7F);
    WipeCreateIn(0, 8);
    HuPrcSleep(8);
    omDelPrcObj(NULL);
}

void MBMapFullExec(s32 playerPadNo) {
    Process* temp_s1;
    Process* temp_v0;

    D_800CB99C_CC59C = 1;
    func_80049FB8_4ABB8();
    temp_s1 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(MBMapFullMain, 0x1005, 0, 0);
    temp_v0->user_data = (void*)playerPadNo;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s1, temp_v0);
    HuPrcChildWait();
    func_8004A0E0_4ACE0();
    D_800CB99C_CC59C = 0;
}
