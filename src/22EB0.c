#include "common.h"
#include "mallocblock.h"

void func_80018544_main(s32, s32);
void func_80019C00_main(void *data);
void func_80022660_main(HmfData *);
extern s16 D_800CDD6A_main;
extern u16 D_800D5204_main;

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800222B0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800224BC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800225D4_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80022660_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80022F08_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80022FF4_main);

void func_800230F8_main(HmfData *arg0) {
    s16 textureIndex;
    s16 i, j;

    textureIndex = 4; // TODO: why does this start at 4?

    for (i = 0; i < arg0->unk12; i++) {
        /* Skip entries marked as 0xFF */
        if (arg0->unk84[i].unk9 == 0xFF) {
            continue;
        }

        /* Find first entry with different unkC value */
        for (j = 0; j < i; j++) {
            if (arg0->unk84[i].unkC == arg0->unk84[j].unkC) {
                break;
            }
        }

        /* Copy or assign texture indices */
        if (j != i) {
            arg0->unk84[i].unk3 = arg0->unk84[j].unk3;
            arg0->unk84[i].unk4 = arg0->unk84[j].unk4;
        } else {
            arg0->unk84[i].unk3 = textureIndex++;
            if (arg0->unk84[i].unkC->unk_30 != NULL) {
                arg0->unk84[i].unk4 = textureIndex++;
            }

            if (textureIndex > 16) {
                osSyncPrintf("Texture Anime Over\n");
                return;
            }
        }
    }
}

s32 func_80023264_main(HmfData *arg0) {
    s32 var_s2;
    s16 i;

    var_s2 = 0;
    if (arg0->unk40 != NULL) {
        for (i = 0; i < ARRAY_COUNT(arg0->unk44); i++) {
            if (arg0->unk40 != arg0->unk44[i]) {
                if (arg0->unk0A != 0) {
                    func_80019C00_main(arg0->unk44[i]);
                } else {
                    HuMemFree(arg0->unk44[i]);
                }
                arg0->unk44[i] = arg0->unk40;
                var_s2 = 1;
            }
        }

        if (arg0->unk0A != 0) {
            func_80019C00_main(arg0->unk40);
        } else {
            HuMemFree(arg0->unk40);
        }
    }
    if (arg0->unk3C != NULL) {
        for (i = 0; i < arg0->unk10; i++) {
            if (arg0->unk0A != 0) {
                func_80019C00_main(arg0->unk3C->unk00[i]);
            } else {
                HuMemFree(arg0->unk3C->unk00[i]);
            }
        }

        if (arg0->unk0A != 0) {
            func_80019C00_main(arg0->unk3C);
        } else {
            HuMemFree(arg0->unk3C);
        }
    }
    D_800D5204_main = arg0->unk0E;
    D_800CDD6A_main = arg0->unk0E + 1;
    func_80022660_main(arg0);
    return var_s2;
}

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80023404_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002367C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80023700_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80023AF8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002404C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80024354_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80024814_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80024D94_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80024DF0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800250D4_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800257BC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_800260F0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80029FB4_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002A358_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002AC5C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002AF40_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002AFEC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002B104_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002B2AC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C0EC_main);

s32 func_8002C4C0_main(HmfData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    if (!(arg0->unk60[arg1].unk50 & 0x70000000)) {
        return 0;
    }
    func_80018544_main(arg2, arg3);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C520_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C5B8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C834_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C914_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002C960_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002CAE4_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002CB6C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002CDF4_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D094_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D260_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D2D8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D3AC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D3D0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D4B8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D514_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002D5B0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002DA98_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002DD4C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002DF2C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002DFF8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002E78C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002E8E8_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002EAC0_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002F60C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FB08_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FB98_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FC14_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FC7C_main);

void func_8002FD48_main(HmfData *arg0) {
    arg0->unkA0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FD50_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FD70_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FD8C_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FDCC_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_8002FE08_main);

INCLUDE_ASM("asm/nonmatchings/22EB0", func_80030030_main);
