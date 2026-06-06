#include "common.h"
#include "input.h"

void ContDataInit(void) {
    s16 i;
    for (i = 0; i < MAXCONTROLLERS; ++i) {
        D_800D5546_D6146[i] =
            D_800D1350_D1F50[i] =
                D_800C9520_CA120[i] =
                    D_800D0590_D1190[i] =
                        D_800D10F8_D1CF8[i] = 0;
    }
}

void ContDataUpdate(void) {
    s16 i;
    s32 temp_v0_3;
    s32 temp_v0_5;
    u16 var_a2;
    s8 temp_v0_2;
    s8 temp_v0_4;

    for (i = 0; i < MAXCONTROLLERS; ++i) {
        D_800D1350_D1F50[i] = D_800D5546_D6146[i];
        var_a2 = D_800CDA7C_CE67C[i];
        temp_v0_2 = D_800CBB6E_CC76E[i];
        temp_v0_3 = ((temp_v0_2 >> 7) | 1);

        if (((temp_v0_2 * temp_v0_3) - 0x1E) > 0) {
            if (temp_v0_3 > 0) {
                var_a2 = (var_a2 & 0xFDFF) | 0x100;
            } else {
                var_a2 = (var_a2 & 0xFEFF) | 0x200;
            }
        }

        temp_v0_4 = D_800D20A1_D2CA1[i];
        temp_v0_5 = ((temp_v0_4 >> 7) | 1);

        if (((temp_v0_4 * temp_v0_5) - 0x1E) > 0) {
            if (temp_v0_5 > 0) {
                var_a2 = (var_a2 & 0xFBFF) | 0x800;
            } else {
                var_a2 = (var_a2 & 0xF7FF) | 0x400;
            }
        }

        D_800D5546_D6146[i] = var_a2;
        D_800C9520_CA120[i] = var_a2 & (var_a2 ^ D_800D1350_D1F50[i]);

        if ((var_a2 & 0xFFFF) != D_800D1350_D1F50[i]) {
            D_800D10F8_D1CF8[i] = 0xA;
            D_800D0590_D1190[i] = D_800C9520_CA120[i];
        } else {
            if (D_800D10F8_D1CF8[i] > 0) {
                D_800D10F8_D1CF8[i] = D_800D10F8_D1CF8[i] - 1;
                D_800D0590_D1190[i] = D_800C9520_CA120[i];
            } else {
                D_800D10F8_D1CF8[i] = 1;
                D_800D0590_D1190[i] = var_a2;
            }
        }
    }
}
