#include "common.h"
#include "malloc.h"
#include "rom.h"

// string table parsing code.

extern u32 D_800B1A40_main; // strings ROM pointer
extern s32 D_800B1A44_main;   // string directory count
extern u32 *D_800B1A48_main;   // string directory table
extern s32 D_800B1A4C_main;   // string directory table size

void func_80036380_main(u32 stringsRomPtr) {
    s32 stringDirTableSize;
    u32 *stringDirTable;
    u32 *stringsHeader;

    D_800B1A40_main = stringsRomPtr;
    stringsHeader = HuMemMemoryAllocPerm(16);
    dmaRead(stringsRomPtr, (u8 *)stringsHeader, 16);
    D_800B1A44_main = *stringsHeader;
    HuMemMemoryFreePerm(stringsHeader);
    stringDirTableSize = D_800B1A44_main * 4;
    D_800B1A4C_main = stringDirTableSize;
    stringDirTable = HuMemMemoryAllocPerm(stringDirTableSize);
    D_800B1A48_main = stringDirTable;
    dmaRead(stringsRomPtr + 4, (u8*)stringDirTable, D_800B1A4C_main);
}

void func_80036414_main(u32 ptr) {
    D_800B1A40_main = ptr;
    dmaRead(ptr + 4, (u8*)D_800B1A48_main, D_800B1A4C_main);
}

struct str80036448 {
    u32 unk0;
    s32 unk4; // decompressed size
    s32 unk8; // compression type
};

struct string_dir_header {
    s32 decompressedSize;
    s32 compressionType;
};

void func_80036448_main(s32 arg0, struct str80036448 *arg1) {
    u32 temp_a0;
    struct string_dir_header *dirHeader;

    dirHeader = HuMemMemoryAllocPerm(16);
    temp_a0 = D_800B1A40_main + D_800B1A48_main[arg0];
    arg1->unk0 = temp_a0;
    dmaRead(temp_a0, (u8 *)dirHeader, 16);
    arg1->unk0 = arg1->unk0 + 8;
    arg1->unk4 = dirHeader->decompressedSize;
    arg1->unk8 = dirHeader->compressionType;
    HuMemMemoryFreePerm(dirHeader);
}

INCLUDE_ASM("asm/nonmatchings/36F80", func_800364DC_main);

void func_800365E8_main(void *ptr) {
    if (ptr != NULL) {
        HuMemMemoryFreePerm(ptr);
    }
}
