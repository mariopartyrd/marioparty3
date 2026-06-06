#include "common.h"
#include "malloc.h"
#include "rom.h"

// string table parsing code.

extern void *D_800B1A40_B2640; // strings ROM pointer
extern s32 D_800B1A44_B2644;   // string directory count
extern u8 *D_800B1A48_B2648;   // string directory table
extern s32 D_800B1A4C_B264C;   // string directory table size

void func_80036380_36F80(Addr stringsRomPtr) {
    s32 stringDirTableSize;
    u8 *stringDirTable;
    u32 *stringsHeader;

    D_800B1A40_B2640 = stringsRomPtr;
    stringsHeader = HuMemMemoryAllocPerm(16);
    dmaRead(stringsRomPtr, (u8 *)stringsHeader, 16);
    D_800B1A44_B2644 = *stringsHeader;
    HuMemMemoryFreePerm(stringsHeader);
    stringDirTableSize = D_800B1A44_B2644 * 4;
    D_800B1A4C_B264C = stringDirTableSize;
    stringDirTable = HuMemMemoryAllocPerm(stringDirTableSize);
    D_800B1A48_B2648 = stringDirTable;
    dmaRead(stringsRomPtr + 4, stringDirTable, D_800B1A4C_B264C);
}

void func_80036414_37014(Addr ptr) {
    D_800B1A40_B2640 = ptr;
    dmaRead(ptr + 4, D_800B1A48_B2648, D_800B1A4C_B264C);
}

struct str80036448 {
    void *unk0;
    s32 unk4; // decompressed size
    s32 unk8; // compression type
};

struct string_dir_header {
    s32 decompressedSize;
    s32 compressionType;
};

void func_80036448_37048(s32 arg0, struct str80036448 *arg1) {
    u8 *temp_a0;
    struct string_dir_header *dirHeader;

    dirHeader = HuMemMemoryAllocPerm(16);
    temp_a0 = ((u8 *)D_800B1A40_B2640) + *((u32 *)D_800B1A48_B2648 + arg0);
    arg1->unk0 = temp_a0;
    dmaRead(temp_a0, (u8 *)dirHeader, 16);
    arg1->unk0 = arg1->unk0 + 8;
    arg1->unk4 = dirHeader->decompressedSize;
    arg1->unk8 = dirHeader->compressionType;
    HuMemMemoryFreePerm(dirHeader);
}

INCLUDE_ASM("asm/nonmatchings/36F80", func_800364DC_370DC);

void func_800365E8_371E8(void *ptr) {
    if (ptr != NULL) {
        HuMemMemoryFreePerm(ptr);
    }
}
