#include "common.h"
#include "siman.h"
#include "pad.h"

s32 _InitController(u16* channel)
{
    OSContStatus contStat[MAXCONTROLLERS];
    u8 pattern;
    s16 i;

    osContInit(&D_800CE1A0_CEDA0, &pattern, contStat);

    D_800ABF80_ACB80 = D_800ABF82_ACB82 = D_800ABF84_ACB84 = 0;
    gNumOfControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; ++i)
    {
        if (((pattern >> i) & 1) && ((contStat[i].errno & CONT_NO_RESPONSE_ERROR) == 0)) {
            if (++gNumOfControllers == *channel) {
                break;
            }
        }

        D_800CDA7C_CE67C[i] = 
        D_800D5558_D6158[i] = 
        D_800CBB66_CC766[i] = 
        D_800D1244_D1E44[i] = 
            0;
        D_800D056A_D116A[i] = 
        D_800D1382_D1F82[i] = 
            0;
        D_800D20A1_D2CA1[i] = 0;
        D_800CBB6E_CC76E[i] = 0;
        D_800ABF8A_ACB8A[i] = 0;
        
    }
    
    osContSetCh(*channel);
    return 0;
}

s16 InitController(s16 ch, s32 arg1)
{
    unkMesg siMesg;
    RequestSIFunction(&siMesg, (void*)&_InitController, &ch, 1);
    
    D_800ABF9C_ACB9C = 0;
    
    if (arg1 & 1) {
        SetAutoReadController();
    }
    
    SetStickValueLimit(0x46, 0x46);
    osCreateMesgQueue(&D_800ABFA0_ACBA0, &D_800ABFB8_ACBB8, 1);
    osSendMesg(&D_800ABFA0_ACBA0, 0, 1);
    
    return gNumOfControllers;
}

s32 _ReadController(s32 arg0)
{
    osRecvMesg(&D_800ABFA0_ACBA0, 0, 1);
    
    if (D_800ABF80_ACB80 < 8)
    {
        osSendMesg(&D_800ABFA0_ACBA0, 0, 1);
        osContStartReadData(&D_800CE1A0_CEDA0);
        osRecvMesg(&D_800CE1A0_CEDA0, 0, 1);
        osContGetReadData(&D_800ABE40_ACA40[D_800ABF84_ACB84 * 4]); //?
        osRecvMesg(&D_800ABFA0_ACBA0, 0, 1);
        
        ++D_800ABF80_ACB80;
        
        if (++D_800ABF84_ACB84 >= 8) {
            D_800ABF84_ACB84 = 0;
        }
    }
    
    osSendMesg(&D_800ABFA0_ACBA0, 0, 1);
    return 0;
}

void ReadController(void) {
    osRecvMesg(&D_800ABFA0_ACBA0, NULL, 1);
    if (D_800ABF80_ACB80 < 8) {
        RequestSIFunction(&D_800ABF00_ACB00[D_800ABF84_ACB84], &_ReadController, 0, 0);
    }
    osSendMesg(&D_800ABFA0_ACBA0, NULL, 1);
}

void SetStickValueLimit(s8 arg0, s8 arg1) {
    D_800ABF8E_ACB8E = arg0;
    D_800ABF8F_ACB8F = arg1;
}


#define MAX_CONTROLLERS 4

s16 UpdateController(void)
{
    s16 i;
    s16 temp_s0;
    u16 temp_v0_3;
    OSContPad* pads;
    u8 temp;
    
    osRecvMesg(&D_800ABFA0_ACBA0, 0, 1);
    temp_s0 = D_800ABF80_ACB80;

    if (temp_s0 != 0)
    {
        --D_800ABF80_ACB80;
    
        pads = &D_800ABE40_ACA40[D_800ABF82_ACB82 * 4];
        ++D_800ABF82_ACB82;
        if (D_800ABF82_ACB82 >= 8) {
            D_800ABF82_ACB82 = 0;
        }

        for (i = 0; i < MAX_CONTROLLERS; i++) {
            D_800ABF8A_ACB8A[i] = pads[i].errno != 8;
            temp_v0_3 = 
            D_800CDA7C_CE67C[i] = pads[i].button;
            D_800CBB6E_CC76E[i] = pads[i].stick_x;
            D_800D056A_D116A[i] = D_800CBB6E_CC76E[i];
            D_800D1382_D1F82[i] = 
            D_800D20A1_D2CA1[i] = pads[i].stick_y;
            D_800D5558_D6158[i] = temp_v0_3 & (temp_v0_3 ^ D_800CBB66_CC766[i]);
            if (D_800CBB66_CC766[i] == temp_v0_3) {
                    if (!(--D_800ABF86_ACB86[i] & 0xFF)) {
                        D_800D1244_D1E44[i] = temp_v0_3;
                        D_800ABF86_ACB86[i] = 0xA;
                    } else {
                        D_800D1244_D1E44[i] = 0;
                    }
            } 
            else {
                D_800D1244_D1E44[i] = D_800D5558_D6158[i];
                D_800ABF86_ACB86[i] = 0x1E;
            }

            temp = D_800CBB6E_CC76E[i] + 9;

            if (temp < 0x13) {
                D_800CBB6E_CC76E[i] = 0;
            } else if (D_800CBB6E_CC76E[i] > D_800ABF8E_ACB8E) {
                D_800CBB6E_CC76E[i] = D_800ABF8E_ACB8E;
            } else if (D_800CBB6E_CC76E[i] < -D_800ABF8E_ACB8E) {
                D_800CBB6E_CC76E[i] = -D_800ABF8E_ACB8E;
            }

             temp = D_800D20A1_D2CA1[i] + 9;

            
            if (temp < 0x13) {
                D_800D20A1_D2CA1[i] = 0;
            } else if (D_800D20A1_D2CA1[i] > D_800ABF8F_ACB8F) {
                D_800D20A1_D2CA1[i] = D_800ABF8F_ACB8F;
            } else {
                if (D_800D20A1_D2CA1[i] < -D_800ABF8F_ACB8F) {
                    D_800D20A1_D2CA1[i] = -D_800ABF8F_ACB8F;
                }
            }
            D_800CBB66_CC766[i] = temp_v0_3;
        }
    }
    osSendMesg(&D_800ABFA0_ACBA0, 0, 1);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/pad", FlushController);

void _AutoReadController(void) {
    _ReadController(0);
}

void SetAutoReadController(void) {
    if (D_800ABF9C_ACB9C != 0) {
        ResetAutoReadController();
    }
    AddSIClient(&D_800ABF90_ACB90, 0, &_AutoReadController);
    D_800ABF9C_ACB9C = 1;
}

void ResetAutoReadController(void) {
    if (D_800ABF9C_ACB9C != 0) {
        RemoveSIClient(&D_800ABF90_ACB90);
    }
    D_800ABF9C_ACB9C = 0;
}

s32 CheckControllerRead(s16 padNum) {
    return D_800ABF8A_ACB8A[padNum];
}
