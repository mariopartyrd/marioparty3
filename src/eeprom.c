#include "common.h"
#include "siman.h"

#define SAVE_FILE_HEADER_SIZE 0x20
#define SAVE_FILE_SIZE 0x2A0

typedef struct EepData {
/* 0x00 */ u16 eepFileOffset;
/* 0x04 */ u8* eepromBuffer;
/* 0x08 */ u16 size;
} EepData; //sizeof 0x0C

typedef struct UnkEepStruct {
    char unk_00[0x10];
} UnkEepStruct;

typedef struct unkfunc_8001AFD8 {
    s16 unk0;
    struct unkfunc_8001AFD8* unk4; //is this correct?
    s16 unk8;
} unkfunc_8001AFD8;

typedef struct unkfunc_8007EE0C {
    void* _InitEepromFunc; //func pointer
    unkfunc_8001AFD8* unk4; //is this correct?
    s32 unk8;
    OSMesgQueue* mesgQueue;
} unkfunc_8007EE0C;

extern u8 D_80097710_98310[];
extern u8 D_800D0450_D1050[];
extern u8 D_800AC7F0_AD3F0;
extern u8 D_800AC7F1_AD3F1;
extern u8 D_800D0E50_D1A50[];

void ClearCommonBuf(void);
s32 _WriteEeprom(EepData* arg0);
s32 func_8000C9C8_D5C8(s8);
s32 WriteEeprom(OSMesgQueue* arg0, u8 arg1, u8* arg2, s32 arg3);

s32 _InitEeprom(s8** arg0) {
    s16 eepromProbeResult;
    s32 var_s1;
    s16 i;

    D_800AC7F0_AD3F0 = 0;
    D_800AC7F1_AD3F1 = 0xFF;
    var_s1 = 0;
    eepromProbeResult = osEepromProbe(&D_800CE1A0_CEDA0);
    if ((eepromProbeResult) == 0) {
        for (i = 0; i < 4; i++) {
            eepromProbeResult = osEepromProbe(&D_800CE1A0_CEDA0);
            if (eepromProbeResult != 0) {
                break;
            }
        }

        ASSERT(i != 4);
    }

    ASSERT(eepromProbeResult == EEPROM_TYPE_16K);

    if (osEepromLongRead(&D_800CE1A0_CEDA0, 0, D_800D0E50_D1A50, EEPROM_BLOCK_SIZE) != 0) {
        return EEPROM_TYPE_16K;
    }

    i = 0;
    if (D_80097710_98310[i] != 0) {
        while (1) {
            if (D_800D0E50_D1A50[i] != D_80097710_98310[i]) {
                var_s1 = 1;
                //Write "HUDSON\0\0" header
                for (i = 0; i < EEPROM_BLOCK_SIZE; i++) {
                    D_800D0E50_D1A50[i] = D_80097710_98310[i];
                }

                //Write it again just to be sure
                for (i = 0; i < EEPROM_BLOCK_SIZE; i++) {
                    D_800D0E50_D1A50[i] = D_80097710_98310[i];
                }
                
                ClearCommonBuf();
                WriteEeprom(&D_800CE1A0_CEDA0, 1, D_800D0450_D1050, 0x18);
                
                for (i = 0; i < 3; i++) {
                    if (func_8000C9C8_D5C8(i)) {
                        return EEPROM_TYPE_16K;
                    }
                }
                
                for (i = 0; i < 8; i++) {
                    D_800D0E50_D1A50[i] = D_80097710_98310[i];
                }
                
                if (WriteEeprom(&D_800CE1A0_CEDA0, 0, D_800D0E50_D1A50, 8) == 0) {
                    **arg0 = var_s1;
                    return 0;
                }
                return EEPROM_TYPE_16K;
            }      
            i++;
            if (D_80097710_98310[i] == 0) {
                break;
            }
        }
    }
    **arg0 = var_s1;
    return 0;
}

s32 InitEeprom(unkfunc_8001AFD8* arg0) {
    unkMesg sp10;
    unkfunc_8001AFD8* sp20 = arg0; //?

    return RequestSIFunction(&sp10, (void*)&_InitEeprom, &sp20, 1);
}

s32 _WriteEeprom(EepData* arg0) {
    u16 alignedOffset = (arg0->eepFileOffset >> 3);
    u16 alignedSize = (arg0->size + (arg0->eepFileOffset & 7) + 7) & ~7;
    u8* alignedEepBuffer = (u8*) ((u32)arg0->eepromBuffer & ~7);
    
    return (WriteEeprom(&D_800CE1A0_CEDA0, alignedOffset, alignedEepBuffer, alignedSize) != 0) * 2;
}

INCLUDE_ASM("asm/nonmatchings/eeprom", WriteEepromBox2);

void WriteEepromBox(s8 saveFileIndex) {
    unkMesg sp10;
    EepData sp20;

    D_800AC7F0_AD3F0 = 0;
    sp20.eepFileOffset = (saveFileIndex * SAVE_FILE_SIZE) + SAVE_FILE_HEADER_SIZE;
    sp20.eepromBuffer = D_800D0E50_D1A50;
    sp20.size = SAVE_FILE_SIZE;
    if (RequestSIFunction(&sp10, &_WriteEeprom, &sp20, 1) == 0) {
        D_800AC7F1_AD3F1 = saveFileIndex;
    }
}

INCLUDE_ASM("asm/nonmatchings/eeprom", func_8000C6C0_D2C0);

INCLUDE_ASM("asm/nonmatchings/eeprom", _ReadEeprom);

INCLUDE_ASM("asm/nonmatchings/eeprom", ReadEepromBox);

INCLUDE_ASM("asm/nonmatchings/eeprom", WriteEepromCommonBuf);

INCLUDE_ASM("asm/nonmatchings/eeprom", ReadEepromCommonBuf);

INCLUDE_ASM("asm/nonmatchings/eeprom", func_8000C9C8_D5C8);

INCLUDE_ASM("asm/nonmatchings/eeprom", ClearBoxBuf);

INCLUDE_ASM("asm/nonmatchings/eeprom", ClearCommonBuf);

INCLUDE_ASM("asm/nonmatchings/eeprom", _DestroyEeprom);

INCLUDE_ASM("asm/nonmatchings/eeprom", DestroyEeprom);

u16 CalcChecksumEeprom(u8* data, u16 startIndex, u16 size) {
    u16 checksum = 0;
    u16 remainingBytes = size - 1;

    while (size--) {
        checksum += data[startIndex];
        startIndex += 1;
        remainingBytes += 0xFFFF;
    }

    return ~checksum;
}

s32 WriteEeprom(OSMesgQueue* arg0, u8 arg1, u8* arg2, s32 arg3) {
    UnkEepStruct sp10;

    osEepromLongRead(arg0, (arg1 ^ 1), (u8*)&sp10, 8);
    return osEepromLongWrite(arg0, arg1, arg2, arg3);
}
