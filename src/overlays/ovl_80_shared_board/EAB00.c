#include "common.h"
#include "ovl_80.h"

UnkBoard2* func_800D6B70_EA790_shared_board(s32);
UnkEA790Struct* func_800D6C6C_EA88C_shared_board(void);
void func_800D6D2C_EA94C_shared_board(void*, UnkBoard2*, s32);
void func_800D7568_EB188_shared_board(UnkBoard2*, Vec*, Vec*, f32);
void func_800D6EE0_EAB00_shared_board(void);
s32 func_800D7250_EAE70_shared_board(UnkEA790Struct*, s32);
void func_800D7280_EAEA0_shared_board(void);
UnkBoard2* func_800D6EC8_EAAE8_shared_board(UnkEA790Struct*, s16);
f32 func_800D8DAC_EC9CC_shared_board(Vec*, Vec*);
s16 func_800ECF18_100B38_shared_board(s16, f32);

void func_800D6EE0_EAB00_shared_board(void) {
    s32 mesg;
    s32 ret;
    UnkEA790Struct *work;
    Vec *scale;
    f32 scaleX;
    f32 scaleZ;
    f32 speed;
    f32 angle;
    s16 timer;
    s16 sel;
    s16 delay;
    s32 i;

    timer = -1;
    work = HuPrcCurrentGet()->user_data;
    sel = work->unk_0C;
    angle = 0.0f;
    delay = 0;

    while (timer != 0) {
        HuPrcVSleep();

        if (timer < 0) {
            if (delay == 0) {
                ret = osRecvMesg(&work->unk10, (OSMesg *)&mesg, 0);
                if (ret == -1) {
                    mesg = ret;
                }
                if (work->unk_00 & 1) {
                    delay = 8;
                }
            } else {
                mesg = -1;
                delay--;
            }

            switch (mesg) {
            case -1:
                break;
            case -2:
                work->unk_0C++;
                if (work->unk_0C >= work->unk_02) {
                    work->unk_0C = 0;
                }
                break;
            case -3:
                work->unk_0C--;
                if (work->unk_0C < 0) {
                    work->unk_0C = work->unk_02 - 1;
                }
                break;
            case -4:
                if (work->unk_0C >= 0) {
                    HuAudFXPlay(3);
                    mbCameraBtnF = 0;
                    D_800D51F8_D5DF8 = 0;
                    timer = 30;
                }
                break;
            case -5:
                HuAudFXPlay(4);
                work->unk_0C = -1;
                timer = 0;
                break;
            case -6:
                work->unk_0C = -1;
                break;
            default:
                if (mesg < work->unk_02) {
                    work->unk_0C = mesg;
                }
                break;
            }

            if (sel != work->unk_0C) {
                HuAudFXPlay(1);
                if (sel >= 0) {
                    HuVecCopyXYZ(&func_800D6EC8_EAAE8_shared_board(work, sel)->obj->scale, 1.0f, 1.0f, 1.0f);
                    angle = 0.0f;
                }
                sel = work->unk_0C;
            }
        }

        if (sel >= 0) {
            f32 temp;
            if (timer >= 0) {
                speed = 50.0f;
            } else {
                speed = 25.0f;
            }
            angle += speed;
            temp = 360.0f;
            if (angle > temp) {
                angle -= temp;
            }
            scaleZ = (HuMathCos(angle) * 0.3f) + 1.2f;
            scaleX = (HuMathCos(angle) * 0.2f) + 1.2f;
            HuVecCopyXYZ(&func_800D6EC8_EAAE8_shared_board(work, sel)->obj->scale, scaleX, 1.0f, scaleZ);
        }

        if (timer > 0) {
            timer--;
            scaleZ = timer * (1.0f / 30.0f);
            for (i = 0; i < work->unk_02; i++) {
                if (i != sel) {
                    scale = &func_800D6EC8_EAAE8_shared_board(work, i)->obj->scale;
                    HuVecMulScalar(scale, scaleZ, scale);
                }
            }
        }
    }
    omDelPrcObj(NULL);
}

s32 func_800D7250_EAE70_shared_board(UnkEA790Struct* arg0, s32 arg1) {
    if (arg0->proc != NULL) {
        return osSendMesg(&arg0->unk10, (void* ) arg1, 0);
    }
    return - 1;
}

void func_800D7280_EAEA0_shared_board(void) {
    Vec stick;
    Vec diff;
    UnkEA790Struct *work;
    GW_PLAYER *player;
    s32 sel;
    s32 i;
    s16 run;

    run = 1;
    work = HuPrcCurrentGet()->user_data;
    player = work->player;
    sel = work->unk_0C;

    while (run) {
        HuPrcVSleep();

        stick.x = D_800CBB6E_CC76E[work->unkE];
        stick.z = D_800D20A1_D2CA1[work->unkE];
        stick.z = -stick.z;
        stick.y = 0.0f;

        if (func_800ECF18_100B38_shared_board(work->unkE, 40.0f) != 0) {
            for (i = 0; i < work->unk_02; i++) {
                HuVecSubtract(&diff,
                              &func_800D6EC8_EAAE8_shared_board(work, i)->obj->coords,
                              &player->player_obj->coords);
                diff.y = 0.0f;
                if (func_800D8DAC_EC9CC_shared_board(&stick, &diff) <= 38.0f) {
                    if (sel != i) {
                        sel = i;
                        func_800D7250_EAE70_shared_board(work, sel);
                    }
                    break;
                }
            }
        }

        if ((D_800C9520_CA120[work->unkE] & 0x8000) && (sel >= 0)) {
            sel = -4;
            func_800D7250_EAE70_shared_board(work, sel);
            run = 0;
        }
    }
    omDelPrcObj(NULL);
}


s32 func_800D742C_EB04C_shared_board(UnkEA790Struct* arg0, s16 playerNo, s32 arg2) {
    GW_PLAYER* player;
    Process* proc;

    if (arg0->proc == NULL) {
        proc = omAddPrcObj(func_800D6EE0_EAB00_shared_board, 0xEFFFU, 0x1000, 0);
        arg0->proc = proc;
        proc->user_data = arg0;
        osCreateMesgQueue(&arg0->unk10, &arg0->unk28, 0x10);
        arg0->unk_00 = arg2 | arg0->unk_00;
        player = MBPlayerGet(playerNo);
        if (player->stat & 1) {
            arg0->unk_00 |= 1;
            func_800D7250_EAE70_shared_board(arg0, -1);
        } else {
            arg0->unkE = player->pad;
            omAddPrcObj(func_800D7280_EAEA0_shared_board, 0xEFFFU, 0x1000, 0)->user_data = arg0;
        }
        return player->stat & 1;
    }
    return -1;
}

s16 func_800D7518_EB138_shared_board(UnkEA790Struct* arg0) {
    if (arg0->proc != NULL) {
        HuPrcChildLink(HuPrcCurrentGet(), arg0->proc);
        HuPrcChildWait();
        arg0->proc = NULL;
    }
    return arg0->unk_0C;
}

void func_800D7568_EB188_shared_board(UnkBoard2* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Vec sp10;

    MBVecDirGet(arg1, arg2, &sp10);
    HuVecCopy3F(&arg0->obj->rot, &sp10);
    HuVecMulScalar(&sp10, arg3, &sp10);
    HuVecAdd(&arg0->obj->coords, &sp10, arg1);
}

UnkEA790Struct* func_800D75E8_EB208_shared_board(s16 arg0, s16* arg1, s32 arg2) {
    GW_PLAYER* player;
    UnkBoard2* temp_s0;
    UnkEA790Struct* temp_v0;

    player = MBPlayerGet(arg0);
    temp_v0 = func_800D6C6C_EA88C_shared_board();
    temp_v0->player = player;
    for (; *arg1 >= 0; arg1++) {
        temp_s0 = func_800D6B70_EA790_shared_board(arg2);
        func_800D7568_EB188_shared_board(temp_s0, &player->player_obj->coords, &MBMasuGet(*arg1)->coords, 18.0f);
        func_800D6D2C_EA94C_shared_board(temp_v0, temp_s0, 0);        
    }
    
    return temp_v0;
}

UnkEA790Struct* func_800D76A0_EB2C0_shared_board(s16 arg0, s16* arg1) {
    return func_800D75E8_EB208_shared_board(arg0, arg1, 0);
}
