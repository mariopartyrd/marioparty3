#include "common.h"

void func_8004F83C_5043C(s32);

extern u8 gEncodedSaveBuffer[220];
extern s32 D_800BBAA0_BC6A0;
extern s32 D_800BBAA4_BC6A4;
//extern char D_800A7B40_A8740[];

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F290_4FE90);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F504_50104);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F524_50124);

INCLUDE_ASM("asm/nonmatchings/saveEncode", SavePlayerStruct);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F564_50164);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F584_50184);

s32 SaveFileEncode(u8* sourceData, u8* encodingScheme) {
    s32 phi_s0;
    s16 phi_v1_2;
    u8* currentDataPtr;
    s16 fieldIndex, byteIndex, bitIndex, schemeIndex;

    for (schemeIndex = 0; schemeIndex < ARRAY_COUNT(gEncodedSaveBuffer); schemeIndex++) {
        gEncodedSaveBuffer[schemeIndex] = 0;
    }

    D_800BBAA4_BC6A4 = 0;
    D_800BBAA0_BC6A0 = 0;

    while (*encodingScheme != 0) {
        currentDataPtr = (sourceData + encodingScheme[2]);
        for (fieldIndex = 0; fieldIndex < encodingScheme[1]; fieldIndex++) {
            if (encodingScheme[0] > 16) {
                for (byteIndex = 0; byteIndex < (encodingScheme[0] >> 3); byteIndex++, currentDataPtr++) {
                    phi_s0 = *currentDataPtr;
                    for (bitIndex = 0; bitIndex < 8; bitIndex++, phi_s0 *= 2) {
                        func_8004F83C_5043C(phi_s0 & 0x80);
                    }
                }
                continue;
            } else {
                if (encodingScheme[0] > 8) {
                    phi_s0 = *currentDataPtr << (16 - encodingScheme[0]);
                    phi_v1_2 = encodingScheme[0] - 8;
                    for (bitIndex = 0; bitIndex < phi_v1_2; bitIndex++, phi_s0 *=2) {
                        func_8004F83C_5043C(phi_s0 & 0x80);
                    }
                    currentDataPtr++;
                    phi_s0 = *currentDataPtr;
                    phi_v1_2 = 8;
                } else {
                    phi_s0 = *currentDataPtr << (8 - encodingScheme[0]);
                    phi_v1_2 = encodingScheme[0];
                }
                for (bitIndex = 0; bitIndex < phi_v1_2; bitIndex++, phi_s0 *= 2) {
                    func_8004F83C_5043C(phi_s0 & 0x80);
                }     
            }
            currentDataPtr++;
        }
        encodingScheme += 3; //advance to next encoding tuplet
    }
    

    gEncodedSaveBuffer[D_800BBAA0_BC6A0] <<= 8 - D_800BBAA4_BC6A4;
    if (D_800BBAA4_BC6A4 == 0) {
        D_800BBAA0_BC6A0--;
    }
    if (D_800BBAA0_BC6A0 > ARRAY_COUNT(gEncodedSaveBuffer)) {
        osSyncPrintf("SaveCompBuffer Max Over!\n");
    }
    return D_800BBAA0_BC6A0 + 1;
}

void func_8004F83C_5043C(s32 arg0) {
    gEncodedSaveBuffer[D_800BBAA0_BC6A0] *= 2;
    gEncodedSaveBuffer[D_800BBAA0_BC6A0] |= arg0 ? 1 : 0;
    
    if (++D_800BBAA4_BC6A4 >= 8) {
        D_800BBAA0_BC6A0++;
        D_800BBAA4_BC6A4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F8BC_504BC);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F90C_5050C);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F95C_5055C);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F9AC_505AC);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004F9FC_505FC);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004FA4C_5064C);

INCLUDE_ASM("asm/nonmatchings/saveEncode", func_8004FC84_50884);
