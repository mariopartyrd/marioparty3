#include "game/data.h"
#include "rom.h"
#include "malloc.h"
#include "mallocblock.h"
#include "decode.h"

// -----------------------------------------------------------------

void DataInit(u8* fsRomPtr)
{
    s32 dirTblSize;
    HuArchive * archiveHeader;

    DataRomAddr = fsRomPtr;
    archiveHeader = &gArchive;

    dmaRead(fsRomPtr, (u8*)archiveHeader, 16);

    DataDirMax = archiveHeader->count;
    dirTblSize = archiveHeader->count * 4;
    DataDirTbl = (s32 *)HuMemMemoryAllocPerm(dirTblSize);

    dmaRead((u8*)fsRomPtr + 4, (u8*)DataDirTbl, dirTblSize);

    DataFileRomAddr = DataRomAddr;
    DataFileMax = DataDirMax;
    DataFileTbl = DataDirTbl;
}

// -----------------------------------------------------------------

void DataInfoRead(EArchiveType type, s32 index, HuFileInfo* info)
{
    HuArchive* archiveHeader;
    archiveHeader = &gArchive;

    switch (type) {
        case ARCHIVE_DIRECT:
            info->bytes = (u8 *)DataRomAddr + DataDirTbl[index];
            break;
        case ARCHIVE_CACHED:
            info->bytes = (u8 *)DataFileRomAddr+ DataFileTbl[index];
            break;
    }

    dmaRead(info->bytes, (u8*)archiveHeader, 16);

    info->bytes += 8;
    info->size = archiveHeader->count;
    info->compType = archiveHeader->offsets[0];
}

// -----------------------------------------------------------------

/**
 * Reads a file from the main filesystem and decodes it.
 * File is in the permanent heap.
 */
void* DataRead(s32 dirAndFile)
{
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < DataDirMax) {
        DataDirInit(ARCHIVE_DIRECT, dir);

        if (file < DataFileMax) {
            return DataDecode(ARCHIVE_CACHED, file);
        }
    }

    return NULL;
}

// -----------------------------------------------------------------

void* DataReadTemp(s32 dirAndFile)
{
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < DataDirMax) {
        DataDirInit(ARCHIVE_DIRECT, dir);

        if (file < DataFileMax) {
            return DataDecodeTemp(ARCHIVE_CACHED, file);
        }
    }

    return NULL;
}

// -----------------------------------------------------------------

void* DataReadNum(s32 dirAndFile, s32 tag)
{
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < DataDirMax) {
        DataDirInit(ARCHIVE_DIRECT, dir);

        if (file < DataFileMax) {
            return DataDecodeNum(ARCHIVE_CACHED, file, tag);
        }
    }

    return NULL;
}

// -----------------------------------------------------------------

/**
 * Read file, allocate space in perm heap, decode it.
 */
void * DataDecode(EArchiveType type, s32 index) {
    HuFileInfo info;
    void * ret;

    DataInfoRead(type, index, &info);
    ret = HuMemMemoryAllocPerm((info.size + 1) & -2);
    if (ret != NULL) {
        DecodeData(info.bytes, ret, info.size, info.compType);
    }
    return ret;
}

// -----------------------------------------------------------------

/**
 * Read file, allocate space in temp heap, decode it.
 */
void * DataDecodeTemp(EArchiveType type, s32 index) {
    HuFileInfo info;
    void * ret;

    DataInfoRead(type, index, &info);
    ret = HuMemMemoryAllocTemp((info.size + 1) & -2);
    if (ret != NULL) {
        DecodeData(info.bytes, ret, info.size, info.compType);
    }
    return ret;
}

// -----------------------------------------------------------------

void * DataDecodeNum(EArchiveType type, s32 index, s32 tag) {
    HuFileInfo info;
    void * block;

    DataInfoRead(type, index, &info);
    block = HuMemAllocTag((info.size + 1) & ~1, tag);
    if (block != NULL) {
        DecodeData(info.bytes, block, info.size, info.compType);
    }
    return block;
}

// -----------------------------------------------------------------

void DataClose(void * data)
{
    if (data != NULL) {
        HuMemMemoryFreePerm(data);
    }
}

// -----------------------------------------------------------------

void DataCloseTemp(void * data)
{
    if (data != NULL) {
        /* ! - should be HuMemMemoryFreeTemp, but is fine
            because Free is heap-independant and does not need
            a source heap */
        HuMemMemoryFreePerm(data);
    }
}

// -----------------------------------------------------------------

typedef struct
{
    u8* tablePtr;
    s32 unk0004;    // not used
    s32 unk0008;    // not used
    s32 unk000C;    // not used
} HuDataInfo;

void DataDirInit(EArchiveType type, s32 dir)
{
    s32 dirCount;
    HuArchive * fsHeader;
    HuDataInfo info;

    info.tablePtr = &DataRomAddr[DataDirTbl[dir]];
    
    if (DataFileRomAddr!= info.tablePtr) {
        if (DataFileRomAddr!= DataRomAddr) {
            HuMemMemoryFreePerm(DataFileTbl);
        }
        
        DataFileRomAddr= info.tablePtr;
        
        fsHeader = &gArchive;
        dmaRead(DataFileRomAddr, (u8*)fsHeader, 16);
        
        DataFileMax = gArchive.count;
        dirCount = DataFileMax * 4;
        DataFileTbl = HuMemMemoryAllocPerm(dirCount);

        dmaRead((info.tablePtr + 4), (u8*)DataFileTbl, dirCount);
    }
}

// -----------------------------------------------------------------

// STARTING HERE ARE DEPRECATED FUNCTIONS THAT ARE NOT UTILIZED

// -----------------------------------------------------------------

HuFileInfoD * FileCreate(EArchiveType type, s32 index)
{
    HuFileInfo info;
    HuFileInfoD * dataInfo; // ! - deprecated

    dataInfo = HuMemMemoryAllocPerm(sizeof(HuFileInfoD));
    if (dataInfo == NULL) return NULL;

    DataInfoRead(type, index, &info);
    
    dataInfo->size      = info.size;
    dataInfo->compType  = info.compType;
    dataInfo->block     = HuMemMemoryAllocPerm(0x400);
    dataInfo->unkC      = 1;
    dataInfo->unkE      = 0;
    dataInfo->bytes     =
    dataInfo->bytesCopy = info.bytes;

    return dataInfo;
}

// -----------------------------------------------------------------

void FileClose(HuFileInfoD * info)
{
    HuMemMemoryFreePerm(info->block);
    HuMemMemoryFreePerm(info);
}

// -----------------------------------------------------------------

s32 FileRead(HuFileInfoD * info)
{   
    if (((info->bytesCopy - info->bytes) + info->unkE) >= info->size) {
        return -1;
    }

    if (info->unkE >= 0x400) {
        info->unkC = 1;
        info->bytesCopy = (void* ) (info->unkE + info->bytesCopy);
        info->unkE = 0;
    }
    
    if (info->unkC != 0) {
        info->unkC = 0;
        dmaRead(info->bytesCopy, info->block, 0x400);
    }
    
    return info->block[info->unkE++];
}

// -----------------------------------------------------------------

s32 FileReadBuf(s8 * arg0, s32 arg1, s32 arg2, HuFileInfoD * arg3)
{
    s32 temp_v0;
    s8* var_s1;

    s32 i = 0;
    s32 b = arg1 * arg2;
    var_s1 = arg0;
    
    while (TRUE)
    {
        temp_v0 = FileRead(arg3);

        if (temp_v0 == -1) {
            break;
        }

        *var_s1 = temp_v0;
        ++i;

        if (i >= b) {
            break;
        }

        var_s1++;     
    }
    return i;
}

// -----------------------------------------------------------------

void FileSeek(HuFileInfoD * info, s32 arg1, s32 arg2)
{
    switch (arg2) {
        case 0:
            arg2 = (u32)(info->bytes + arg1);
            break;
        case 1:
            arg2 = (u32)(info->bytesCopy + info->unkE + arg1);
            break;
        case 2:
            arg2 = (u32)(info->bytes + info->size + arg1);
            break;
        default:
            return;
    }
    arg2 = ((u32)arg2 < (u32)info->bytes) ? (u32)info->bytes : (u32)arg2;
    arg2 = ((u32)arg2 >= (u32)(info->bytes + info->size)) ? (u32)(info->bytes + info->size - 1) : (u32)arg2;

    if (((u32)arg2 < (u32)info->bytesCopy) || ((u32)arg2 >= (u32)(info->bytesCopy + 0x400))) {
        info->unkC = 1;
        info->unkE = arg2 & 1;
        info->bytesCopy = (u8*)(arg2 - info->unkE);
    } else {
        info->unkE = arg2 - (u32)info->bytesCopy;
    }
}

// -----------------------------------------------------------------