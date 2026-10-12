#include "common.h"
#include "siman.h"
#include "pad.h"

s32 _InitController(u16 *channel) {
    OSContStatus contStat[MAXCONTROLLERS];
    u8 pattern;
    s16 i;

    osContInit(&D_800CE1A0_main, &pattern, contStat);

    D_800ABF80_main = D_800ABF82_main = D_800ABF84_main = 0;
    gNumOfControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; ++i) {
        if (((pattern >> i) & 1) && ((contStat[i].errno & CONT_NO_RESPONSE_ERROR) == 0)) {
            if (++gNumOfControllers == *channel) {
                break;
            }
        }

        D_800CDA7C_main[i] =
            D_800D5558_main[i] =
                D_800CBB66_main[i] =
                    D_800D1244_main[i] =
                        0;
        D_800D056A_main[i] =
            D_800D1382_main[i] =
                0;
        D_800D20A1_main[i] = 0;
        D_800CBB6E_main[i] = 0;
        D_800ABF8A_main[i] = 0;
    }

    osContSetCh(*channel);
    return 0;
}

s16 InitController(s16 ch, s32 arg1) {
    unkMesg siMesg;
    RequestSIFunction(&siMesg, (void *)&_InitController, &ch, 1);

    D_800ABF9C_main = 0;

    if (arg1 & 1) {
        SetAutoReadController();
    }

    SetStickValueLimit(0x46, 0x46);
    osCreateMesgQueue(&D_800ABFA0_main, &D_800ABFB8_main, 1);
    osSendMesg(&D_800ABFA0_main, 0, 1);

    return gNumOfControllers;
}

s32 _ReadController(s32 arg0) {
    osRecvMesg(&D_800ABFA0_main, 0, 1);

    if (D_800ABF80_main < 8) {
        osSendMesg(&D_800ABFA0_main, 0, 1);
        osContStartReadData(&D_800CE1A0_main);
        osRecvMesg(&D_800CE1A0_main, 0, 1);
        osContGetReadData(&D_800ABE40_main[D_800ABF84_main * 4]); //?
        osRecvMesg(&D_800ABFA0_main, 0, 1);

        ++D_800ABF80_main;

        if (++D_800ABF84_main >= 8) {
            D_800ABF84_main = 0;
        }
    }

    osSendMesg(&D_800ABFA0_main, 0, 1);
    return 0;
}

void ReadController(void) {
    osRecvMesg(&D_800ABFA0_main, NULL, 1);
    if (D_800ABF80_main < 8) {
        RequestSIFunction(&D_800ABF00_main[D_800ABF84_main], &_ReadController, 0, 0);
    }
    osSendMesg(&D_800ABFA0_main, NULL, 1);
}

void SetStickValueLimit(s8 arg0, s8 arg1) {
    D_800ABF8E_main = arg0;
    D_800ABF8F_main = arg1;
}

#define MAX_CONTROLLERS 4

s16 UpdateController(void) {
    s16 i;
    s16 temp_s0;
    u16 temp_v0_3;
    OSContPad *pads;
    u8 temp;

    osRecvMesg(&D_800ABFA0_main, 0, 1);
    temp_s0 = D_800ABF80_main;

    if (temp_s0 != 0) {
        --D_800ABF80_main;

        pads = &D_800ABE40_main[D_800ABF82_main * 4];
        ++D_800ABF82_main;
        if (D_800ABF82_main >= 8) {
            D_800ABF82_main = 0;
        }

        for (i = 0; i < MAX_CONTROLLERS; i++) {
            D_800ABF8A_main[i] = pads[i].errno != 8;
            temp_v0_3 =
                D_800CDA7C_main[i] = pads[i].button;
            D_800CBB6E_main[i] = pads[i].stick_x;
            D_800D056A_main[i] = D_800CBB6E_main[i];
            D_800D1382_main[i] =
                D_800D20A1_main[i] = pads[i].stick_y;
            D_800D5558_main[i] = temp_v0_3 & (temp_v0_3 ^ D_800CBB66_main[i]);
            if (D_800CBB66_main[i] == temp_v0_3) {
                if (!(--D_800ABF86_main[i] & 0xFF)) {
                    D_800D1244_main[i] = temp_v0_3;
                    D_800ABF86_main[i] = 0xA;
                } else {
                    D_800D1244_main[i] = 0;
                }
            } else {
                D_800D1244_main[i] = D_800D5558_main[i];
                D_800ABF86_main[i] = 0x1E;
            }

            temp = D_800CBB6E_main[i] + 9;

            if (temp < 0x13) {
                D_800CBB6E_main[i] = 0;
            } else if (D_800CBB6E_main[i] > D_800ABF8E_main) {
                D_800CBB6E_main[i] = D_800ABF8E_main;
            } else if (D_800CBB6E_main[i] < -D_800ABF8E_main) {
                D_800CBB6E_main[i] = -D_800ABF8E_main;
            }

            temp = D_800D20A1_main[i] + 9;

            if (temp < 0x13) {
                D_800D20A1_main[i] = 0;
            } else if (D_800D20A1_main[i] > D_800ABF8F_main) {
                D_800D20A1_main[i] = D_800ABF8F_main;
            } else {
                if (D_800D20A1_main[i] < -D_800ABF8F_main) {
                    D_800D20A1_main[i] = -D_800ABF8F_main;
                }
            }
            D_800CBB66_main[i] = temp_v0_3;
        }
    }
    osSendMesg(&D_800ABFA0_main, 0, 1);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/pad", FlushController);

void _AutoReadController(void) {
    _ReadController(0);
}

void SetAutoReadController(void) {
    if (D_800ABF9C_main != 0) {
        ResetAutoReadController();
    }
    AddSIClient(&D_800ABF90_main, 0, &_AutoReadController);
    D_800ABF9C_main = 1;
}

void ResetAutoReadController(void) {
    if (D_800ABF9C_main != 0) {
        RemoveSIClient(&D_800ABF90_main);
    }
    D_800ABF9C_main = 0;
}

s32 CheckControllerRead(s16 padNum) {
    return D_800ABF8A_main[padNum];
}
