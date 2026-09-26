#include "common.h"
#include "math.h"
#include "mallocblock.h"

typedef struct {
    u8 unk00;
    char unk01[0x32];
    u8 unk33;
} HmfObjectLinkData;

typedef struct {
    u8 unk00;
    s8 unk01[3];
    s16 unk04[4];
    s32 unk0C[4];
    s32 unk1C[4];
    u8 unk2C[4];
    s16 unk30;
    s16 unk32;
} HmfFaceData;

typedef struct {
    u8 unk00;
    s8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    u8 unk06;
    s8 unk07;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    char unk0B[1];
    s16 unk0C;
    s16 unk0E;
    s16 unk10;
    char unk12[0xA];
    u8 unk1C;
    char unk1D[3];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    char unk2C[0x16];
    s16 unk42[3];
    s16 unk48[3];
    char unk4E[2];
    s32 unk50;
    HmfObjectLinkData *unk54;
    void *unk58;
    char unk5C[0xC];
} HmfObjectData;

typedef struct {
    s16 unk00;
    char unk02[2];
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    char unk4F[1];
    void *unk50;
    void *unk54;
    char unk58[0x40];
} HmfMotionData;

typedef struct {
    char unk00[0x1C];
    s16 unk1C;
    char unk1E[2];
    s32 unk20;
    s32 unk24;
    s32 unk28;
} HmfMapData;

typedef struct {
    char unk00[0x1C];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    char unk22[2];
    f32 unk24;
    s16 *unk28;
    s16 *unk2C;
    u8 *unk30;
} HmfDispData;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 *unk04;
} HmfMtnData;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    char unk06[2];
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
} HmfData_UnkBC;

typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
} HmfData_Unk88_Entry;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    char unk06[2];
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    char unk46[2];
    void *unk48;
    char unk4C[0x40];
} HmfSkeletonData;

typedef struct {
    u8 unk00;
    s8 unk01;
    char unk02[8];
    u8 unk0A;
    s8 unk0B;
    s8 unk0C;
    char unk0D[1];
    s16 unk0E;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    char unk18[4];
    u16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    char unk28[4];
    u8 *unk2C;
    u8 *unk30;
    u8 *unk34;
    u8 *unk38;
    HmfModelData_Unk64_Unk3C_Struct *unk3C;
    void *unk40;
    Vtx *unk44[3];
    void *unk50;
    u8 *unk54;
    void *unk58;
    void *unk5C;
    HmfObjectData *unk60;
    s16 unk64;
    char unk66[2];
    HmfSkeletonData *unk68;
    char unk6C[0x14];
    HmfMotionData *unk80;
    HmfData_Unk84_Entry *unk84;
    HmfData_Unk88_Entry *unk88;
    HmfModelData_Unk64_Unk8C_Struct *unk8C;
    HmfModelData_Unk64_Unk8C_Struct *unk90;
    HmfModelData_Unk64_Unk8C_Struct *unk94;
    HmfModelData_Unk64_Unk98_Struct *unk98;
    void *unk9C;
    s32 unkA0;
    f32 unkA4;
    f32 unkA8;
    f32 unkAC;
    void *unkB0;
    HmfDispData *unkB4;
    HmfMtnData *unkB8;
    HmfData_UnkBC *unkBC;
    void *unkC0;
    HmfMapData *unkC4;
    s32 unkC8;
    void *unkCC;
    HmfData_UnkD0 *unkD0;
    void (*unkD4)(f32 *, f32, f32, f32);
    void (*unkD8)(f32 *, f32, f32, f32);
} HmfLoadData;

typedef struct {
    char unk00[6];
    s16 loopIndex;
    char unk08[6];
    s16 recordCount;
    char unk10[6];
    s16 mapCount;
    char unk18[6];
    s16 recordSize;
    char unk20[6];
    s16 unk3BCount;
    char unk28[4];
    s32 flagsMask;
} HmfLoadWork;

typedef union {
    s32 word;
    f32 single;
} HmfFloatBits;

extern u8 *D_800B19B0_main;
extern u8 *D_800B19B4_main;
extern u8 *D_800B19B8_main;
extern u8 *D_800B19BC_main;
extern u8 *D_800B19C0_main;
extern u8 *D_800B19C4_main;
extern u8 *D_800B19C8_main;
extern u8 *D_800B19CC_main;
extern u8 *D_800B19D0_main;
extern u8 D_800CB8B0_main;
extern u8 D_800CCF85_main;
extern s16 D_800A0544_main;
extern s16 D_800CDD6A_main;
extern s16 D_800D5204_main;

void osSyncPrintf(const char *fmt, ...);
void func_80017D24_main(f32 *, f32, f32, f32);
void func_8001866C_main(f32 *, f32, f32, f32);
void func_80018978_main(f32 *, f32, f32, f32);
void func_80088910_main(f32 *, f32, f32, f32);
s16 func_8000FA34_main(HmfLoadData *, void *);
s16 func_8000FDAC_main(void *, s16);
void func_8000FEE4_main(HmfLoadData *);
s16 func_800100EC_main(HmfLoadData *);
s16 func_8001052C_main(HmfLoadData *);
s16 func_8001073C_main(HmfLoadData *, u16, void *);
u8 *func_80010A38_main(s32, void *, void *);
void *func_80010AC8_main(void *);
void func_80010AF8_main(HmfLoadData *, s16, s16, s16);
void func_80010EB0_main(HmfFaceData *, u8 *, HmfLoadData *, u16 *);
void func_8001116C_main(s8 *, u16 *, u16 *, u16 *);
HmfData_Unk84_Entry2 *func_80031A08_main(HmfLoadData *, s16);
s16 func_80011334_main(HmfLoadData *, void *, s16);
s32 func_800114C0_main(HmfLoadData *);
s32 func_80011874_main(HmfLoadData *);
void func_80011B94_main(HmfLoadData *, void *, s16);
s32 func_80011C40_main(HmfLoadData *, void *);
void func_80011F9C_main(HmfLoadData *);
void func_8001203C_main(HmfLoadData *, u8 *, s32);
void func_8002CAE4_main(HmfLoadData *);
void func_80031630_main(HmfLoadData *);
void func_800339D0_main(HmfLoadData *);

void Hmfload(HmfLoadData *hmf, void *fileData, s32 flags) {
    s16 i;
    s16 recordCount;
    s16 motionCount;
    s16 mapCount;
    s16 recordSize;
    s16 unk3BCount;
    s32 flagsMask;
    s16 modelCount;
    u8 *file;
    char *fileHeader;
    u8 *record;
    u8 *recordStart;
    s16 extraCount;
    s16 objectIndex;
    HmfObjectData *data;

    file = fileData;
    fileHeader = (char *)file;
    if (fileHeader[0] != 'F' || fileHeader[1] != 'O') {
        osSyncPrintf("Unknown Hmf Format!\n");
    }
    hmf->unk2C = file;
    hmf->unk34 = file + 0xC;
    hmf->unk30 = hmf->unk2C + (hmf->unk2C[5] << 0x10) + (hmf->unk2C[6] << 8) + hmf->unk2C[7] + 8;

    D_800B19B4_main = func_80010A38_main(0x56545831, hmf->unk34, hmf->unk30);
    D_800B19B8_main = func_80010A38_main(0x46414331, hmf->unk34, hmf->unk30);
    D_800B19BC_main = func_80010A38_main(0x4F424A31, hmf->unk34, hmf->unk30);
    D_800B19C0_main = func_80010A38_main(0x4D415431, hmf->unk34, hmf->unk30);
    D_800B19C4_main = func_80010A38_main(0x434F4C31, hmf->unk34, hmf->unk30);
    D_800B19C8_main = func_80010A38_main(0x41545231, hmf->unk34, hmf->unk30);
    D_800B19CC_main = func_80010A38_main(0x4D544E31, hmf->unk34, hmf->unk30);
    D_800B19D0_main = func_80010A38_main(0x53545247, hmf->unk34, hmf->unk30);
    hmf->unk38 = func_80010A38_main(0x4D415031, hmf->unk34, hmf->unk30);

    hmf->unk16 = 0;
    hmf->unk14 = 0;
    hmf->unk12 = 0;
    hmf->unk10 = 0;
    hmf->unk40 = NULL;
    hmf->unk3C = NULL;
    hmf->unkB0 = NULL;
    hmf->unk9C = NULL;
    hmf->unk0A = 0;
    hmf->unkBC = NULL;
    hmf->unk5C = NULL;
    hmf->unk58 = NULL;
    hmf->unkCC = NULL;
    hmf->unkD0 = NULL;

    D_800B19B0_main = func_80010A38_main(0x4D4F4445, hmf->unk34, hmf->unk30);
    func_80011F9C_main(hmf);
    if (D_800B19B4_main != NULL) {
        func_8000FEE4_main(hmf);
    }
    if (D_800B19C0_main != NULL) {
        func_800100EC_main(hmf);
    }
    D_800CCF85_main = flags;
    func_80031630_main(hmf);
    if (D_800B19C8_main != NULL) {
        func_8001052C_main(hmf);
    }
    hmf->unk90 = NULL;
    hmf->unk8C = NULL;
    hmf->unk98 = NULL;

    record = D_800B19BC_main + 8;
    recordCount = record[0];
    recordCount = (recordCount << 8) + record[1];
    hmf->unk64 = 0;
    hmf->unk80 = (HmfMotionData *)-1;
    if ((recordCount << 0x10) == 0) {
        hmf->unk16 = 0;
        hmf->unk10 = 0;
        return;
    }

    record += 4;
    recordStart = record;
    i = 0;
    unk3BCount = 0;
    mapCount = 0;
    modelCount = 0;
    motionCount = 0;
    extraCount = 0;
    for (; i < recordCount; i++) {
        switch (record[2]) {
            case 0x3A:
                modelCount++;
                break;

            case 0x3D:
                motionCount++;
                break;

            case 0x61:
                mapCount++;
                break;

            case 0x5D:
                extraCount++;
                break;

            case 0x3B:
                unk3BCount++;
                break;
        }
        record += ((record[0] << 8) + record[1]) + 2;
    }

    if (motionCount != 0) {
        hmf->unk80 = HuMemAllocTag(recordCount * sizeof(HmfMotionData), D_800CDD6A_main);
    }

    if (flags & 0x200000) {
        if (mapCount != 0) {
            hmf->unkC4 = HuMemAllocTag(mapCount * sizeof(HmfMapData), D_800CDD6A_main);
            hmf->unk26 = mapCount;
        }
        if (extraCount != 0) {
            hmf->unkBC = HuMemAllocTag(sizeof(HmfData_UnkBC), D_800CDD6A_main);
        } else {
            hmf->unkBC = NULL;
        }
    } else {
        hmf->unkC4 = NULL;
        hmf->unkBC = NULL;
    }

    if (unk3BCount != 0) {
        hmf->unk20 = unk3BCount;
        hmf->unkC0 = HuMemAllocTag((unk3BCount * 8) - unk3BCount, D_800CDD6A_main);
    } else {
        hmf->unkC0 = NULL;
        hmf->unk20 = 0;
    }

    hmf->unk60 = HuMemAllocTag(modelCount * sizeof(HmfObjectData), D_800CDD6A_main);
    record = recordStart;
    hmf->unk1C = 0;
    i = 0;
    unk3BCount = 0;
    objectIndex = 0;
    mapCount = 0;
    motionCount = 0;
    for (; i < recordCount; i++) {
        switch (record[2]) {
            case 0x3A: {
                s16 linkIndex;
                s16 vertexCount;
                s32 attrMask;

                recordStart = record + 5;
                recordSize = (record[0] << 8) + record[1];
                linkIndex = (record[6] << 8) + record[7];
                hmf->unk60[objectIndex].unk26 = func_80011334_main(hmf, &hmf->unk60[objectIndex], (record[3] << 8) + record[4]);
                data = &hmf->unk60[objectIndex];
                vertexCount = (record[8] << 8) + record[9];
                data->unk22 = vertexCount;
                hmf->unk1C += vertexCount;
                hmf->unk60[objectIndex].unk50 = 0x2B00;
                hmf->unk60[objectIndex].unk58 = NULL;
                hmf->unk60[objectIndex].unk20 = -1;
                if (hmf->unk14 != 0) {
                    func_80010AF8_main(hmf, objectIndex, linkIndex, vertexCount);
                    if (vertexCount != 0) {
                        hmf->unk60[objectIndex].unk1C = hmf->unk60[objectIndex].unk54->unk33;
                    } else {
                        hmf->unk60[objectIndex].unk1C = 0xFF;
                    }
                }
                attrMask = hmf->unk60[objectIndex].unk50 & 0x10000;
                hmf->unk60[objectIndex].unk24 = 0;
                if (((D_800CB8B0_main != 0) & (recordSize >= 0x3A)) && recordStart[0x35] != 0 && recordStart[0x36] == 0) {
                    if (recordSize == 0x3E) {
                        hmf->unk60[objectIndex].unk50 = (recordStart[0x37] << 0x18) | (recordStart[0x39] << 8) | recordStart[0x3A] | attrMask;
                    } else {
                        hmf->unk60[objectIndex].unk50 = (recordStart[0x37] << 0x18) | attrMask;
                    }
                    hmf->unk60[objectIndex].unk24 = recordStart[0x38];
                }
                objectIndex++;
                break;
            }

            case 0x10:
                func_8000FA34_main(hmf, record + 5);
                break;

            case 0x3D:
                func_8001073C_main(hmf, motionCount, record + 5);
                motionCount++;
                break;

            case 0x61: {
                if (flags & 0x200000) {
                    hmf->unkC4[mapCount].unk1C = func_80011334_main(hmf, &hmf->unkC4[mapCount], (record[3] << 8) + record[4]);
                    func_80011B94_main(hmf, record + 5, mapCount);
                    mapCount++;
                }
                break;
            }

            case 0x5D:
                if (flags & 0x200000) {
                    func_80011C40_main(hmf, record + 5);
                }
                break;

            case 0x3B:
                func_8001203C_main(hmf, record + 5, unk3BCount);
                unk3BCount++;
                break;
        }
        record += ((record[0] << 8) + record[1]) + 2;
    }

    hmf->unk10 = objectIndex;
    hmf->unk16 = motionCount;
    func_8002CAE4_main(hmf);
    func_800339D0_main(hmf);
    func_800114C0_main(hmf);
}

void func_8000F978_main(HmfLoadData *hmf) {
    s16 i;

    if (hmf->unk80 != (HmfMotionData *)-1) {
        if (hmf->unk16 > 0) {
            i = 0;
            do {
                HuMemFree(hmf->unk80[i].unk50);
                i++;
            } while (i < hmf->unk16);
        }
        HuMemFree(hmf->unk80);

    } else if (hmf->unk64 != 0) {
        HuMemFree(hmf->unk68);
    }
    HuMemFree(hmf->unk60);
}

s16 func_8000FA34_main(HmfLoadData *hmf, void *arg1) {
    u8 *data;
    u8 *argData;
    HmfSkeletonData *entry;
    s16 target;
    s16 count;
    s16 i;
    s32 value;
    s32 value2;
    s32 value3;

    argData = arg1;
    target = (argData[0] << 8) + argData[1];
    data = hmf->unk34;
    while (data < hmf->unk30) {
        data = func_80010A38_main(0x534B4C31, data, hmf->unk30);
        if (data == NULL) {
            return 0;
        }
        if (((data[8] << 8) + data[9]) == target) {
            break;
        }
        data = func_80010AC8_main(data + 4);
    }

    count = data[0xA];
    hmf->unk64 = count;
    hmf->unk68 = HuMemAllocTag(count * sizeof(HmfSkeletonData), D_800CDD6A_main);
    data += 0xB;
    for (i = 0; i < count; i++) {
        entry = &hmf->unk68[i];
        entry->unk00 = func_8000FDAC_main(hmf, (data[1] << 8) + data[2]);
        entry->unk48 = hmf;
        data += (data[0] << 1) + 1;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk08 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk0C = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk10 = value + data[0xB];
        data += 0xC;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk14 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk18 = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk1C = value + data[0xB];
        data += 0xC;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk20 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk24 = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk28 = value + data[0xB];
        data += 0x18;
        entry->unk02 = (data[0] << 8) + data[1];
        entry->unk04 = (data[2] << 8) + data[3];
        value2 = entry->unk08;
        value = entry->unk0C;
        value3 = entry->unk10;
        entry->unk2C = value2;
        entry->unk30 = value;
        entry->unk34 = value3;
        value2 = entry->unk14;
        value = entry->unk18;
        value3 = entry->unk1C;
        entry->unk38 = value2;
        entry->unk3C = value;
        entry->unk40 = value3;
        entry->unk45 = 0;
        entry->unk44 = 0;
        data += 5;
    }
    return count;
}

s16 func_8000FDAC_main(void *arg0, s16 arg1) {
    u8 *base;
    u8 *data;
    s16 recordCount;
    s16 i;
    s32 modelCount;
    s32 motionCount;
    s32 mapCount;
    s32 id;

    base = D_800B19BC_main;
    recordCount = (base[8] << 8) + base[9];
    data = base + 0xC;
    i = 0;
    modelCount = 0;
    motionCount = 0;
    mapCount = 0;
    if (recordCount > 0) {
        do {
            switch (data[2]) {
                case 0x3A:
                    id = (data[3] << 8) + data[4];
                    if (arg1 == id) {
                        return modelCount;
                    }
                    modelCount++;
                    break;

                case 0x3D:
                    id = (data[3] << 8) + data[4];
                    if (arg1 == id) {
                        return motionCount | 0x8000;
                    }
                    motionCount++;
                    break;

                case 0x61:
                    id = (data[3] << 8) + data[4];
                    if (arg1 == id) {
                        return mapCount | 0x4000;
                    }
                    mapCount++;
                    break;
            }
            data += ((data[0] << 8) + data[1]) + 2;
            i++;
        } while (i < recordCount);
    }
    return -1;
}

void func_8000FEE4_main(HmfLoadData *hmf) {
    u8 *data;
    s16 count;
    s16 count2;
    s16 *coords;
    u8 *colors;
    s32 coordBytes;
    HmfFloatBits scale;
    s32 value;
    s16 i;

    data = D_800B19B4_main;
    count = (data[8] << 8) + data[9];
    hmf->unk14 = count;
    count2 = count;
    if (count2 != 0) {
        coordBytes = count2 << 1;
        coordBytes += count2;
        hmf->unk50 = HuMemAllocTag(coordBytes * 2, D_800D5204_main);
        coords = hmf->unk50;
        hmf->unk54 = HuMemAllocTag(coordBytes, D_800D5204_main);
        colors = hmf->unk54;
        value = data[0xC] << 0x18;
        value += data[0xD] << 0x10;
        value += data[0xE] << 8;
        scale.word = value + data[0xF];
        data += 0x10;
        i = 0;
        if (count2 > 0) {
            do {
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *colors++ = *data++;
                *colors++ = *data++;
                *colors++ = *data++;
                i++;
            } while (i < count);
        }
    }
}

s16 func_800100EC_main(HmfLoadData *hmf) {
    u8 *records;
    u8 *src;
    HmfData_Unk88_Entry *entry;
    s16 count;
    s16 i;

    count = (D_800B19C0_main[8] << 8) + D_800B19C0_main[9];
    if (count == 0) {
        D_800B19C0_main = 0;
        return 0;
    }
    hmf->unk1E = count;
    hmf->unk88 = HuMemAllocTag(count * sizeof(HmfData_Unk88_Entry), D_800CDD6A_main);
    records = D_800B19C0_main + 0xA;
    for (i = 0; i < count; ++i) {
        entry = &hmf->unk88[i];
        entry->unk00 = i;
        entry->unk09 = 0;
        src = D_800B19C4_main + (((records[0] << 8) + records[1]) * 4 + 0xA);
        entry->unk01 = ((f32)src[0] > 255.0f) ? 255 : (u32)(f32)src[0];
        entry->unk02 = ((f32)src[1] > 255.0f) ? 255 : (u32)(f32)src[1];
        entry->unk03 = ((f32)src[2] > 255.0f) ? 255 : (u32)(f32)src[2];
        entry->unk04 = src[3];
        src = D_800B19C4_main + (((records[2] << 8) + records[3]) * 4 + 0xA);
        entry->unk05 = ((f32)src[0] > 255.0f) ? 255 : (u32)(f32)src[0];
        entry->unk06 = ((f32)src[1] > 255.0f) ? 255 : (u32)(f32)src[1];
        entry->unk07 = ((f32)src[2] > 255.0f) ? 255 : (u32)(f32)src[2];
        entry->unk08 = src[3];
        if (entry->unk08 != 255) {
            entry->unk09 |= 1;
            entry->unk0A = entry->unk08;
        } else {
            entry->unk0A = 255;
        }
        records += 0xC;
    }
    return count;
}

s16 func_8001052C_main(HmfLoadData *hmf) {
    u8 *data;
    u8 *colorData;
    HmfData_Unk84_Entry *entry;
    void *temp;
    s16 count;
    s16 i;
    s8 type;

    count = (D_800B19C8_main[8] << 8) + D_800B19C8_main[9];
    hmf->unk84 = HuMemAllocTag(count * sizeof(HmfData_Unk84_Entry), D_800CDD6A_main);
    temp = HuMemAlloc(count * sizeof(s16));
    data = D_800B19C8_main + 0xA;
    hmf->unk12 = count;
    for (i = 0; i < count; i++) {
        s8 fill;

        entry = &hmf->unk84[i];
        type = data[2];
        entry->unk0[0] = type;
        colorData = D_800B19C4_main + (((data[3] << 8) + data[4]) * 4 + 0xA);
        if (type == 0x2B) {
            entry->unk5[0] = colorData[0];
            entry->unk5[1] = colorData[1];
            entry->unk5[2] = colorData[2];
            entry->unk5[3] = colorData[3];
        } else {
            entry->unk5[3] = 0;
            entry->unk5[2] = 0;
            entry->unk5[1] = 0;
            entry->unk5[0] = 0;
        }
        switch (data[5]) {
            case 0x2D:
                entry->unk0[1] = 0;
                break;

            case 0x2E:
                entry->unk0[1] = 2;
                break;

            default:
                entry->unk0[1] = 1;
                break;
        }
        switch (data[6]) {
            case 0x2D:
                entry->unk0[2] = 0;
                break;

            case 0x2E:
                entry->unk0[2] = 2;
                break;

            default:
                entry->unk0[2] = 1;
                break;
        }
        entry->unkC = func_80031A08_main(hmf, (data[0xA] << 8) + data[0xB]);
        fill = -1;
        entry->unk3 = fill;
        entry->unk4 = fill;
        entry->unk9 = 0xFF;
        data += ((data[0] << 8) + data[1]) + 2;
    }
    HuMemFree(temp);
    return count;
}

s16 func_8001073C_main(HmfLoadData *hmf, u16 motionIndex, void *arg2) {
    u8 *data;
    HmfMotionData *entry;
    s16 count;
    s16 count2;
    s32 value;
    s32 value2;
    s32 value3;
    s16 i;

    data = arg2;
    entry = &hmf->unk80[motionIndex];
    entry->unk00 = count2 = (data[0] << 8) + data[1];
    count = count2;
    entry->unk50 = HuMemAllocTag(count2 * sizeof(s16), D_800CDD6A_main);
    data += 2;
    for (i = 0; i < count; i++) {
        ((s16 *)entry->unk50)[i] = func_8000FDAC_main(hmf, (data[0] << 8) + data[1]);
        data += 2;
    }
    entry->unk54 = hmf;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk04 = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk08 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk0C = value + data[0xB];
    data += 0xC;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk10 = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk14 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk18 = value + data[0xB];
    data += 0xC;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk1C = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk20 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk24 = value + data[0xB];
    value2 = entry->unk04;
    value = entry->unk08;
    value3 = entry->unk0C;
    entry->unk28 = value2;
    entry->unk2C = value;
    entry->unk30 = value3;
    value2 = entry->unk10;
    value = entry->unk14;
    value3 = entry->unk18;
    entry->unk34 = value2;
    entry->unk38 = value;
    entry->unk3C = value3;
    value2 = entry->unk1C;
    value = entry->unk20;
    value3 = entry->unk24;
    entry->unk40 = value2;
    entry->unk44 = value;
    entry->unk48 = value3;
    entry->unk4E = 0;
    entry->unk4D = 0;
    entry->unk4C = 0;
    return count;
}

u8 *func_80010A38_main(s32 tag, void *start, void *end) {
    u8 *cur;
    u8 *endPtr;
    s32 value;

    cur = start;
    endPtr = end;
    if (cur < endPtr) {
        do {
            value = cur[0];
            value <<= 0x18;
            value += cur[1] << 0x10;
            value += cur[2] << 8;
            value += cur[3];
            if (tag == value) {
                return cur;
            }
            cur += 4;
            value = cur[0];
            value <<= 0x18;
            value += cur[1] << 0x10;
            value += cur[2] << 8;
            value += cur[3];
            value += 4;
            cur += value;
            cur += (u32)cur & 1;
        } while (cur < endPtr);
    }
    return NULL;
}

void *func_80010AC8_main(void *arg0) {
    u8 *data;
    s32 value;

    data = arg0;
    value = data[1] << 0x10;
    value += data[2] << 8;
    value += data[3];
    value += 4;
    data += value;
    return data + ((u32)data & 1);
}

void func_80010AF8_main(HmfLoadData *hmf, s16 objectIndex, s16 linkIndex, s16 faceCount) {
    u8 *record;
    u8 *next;
    HmfFaceData *faces;
    s16 *p;
    s16 *bounds;
    s16 pointCount;
    u16 flags;
    s16 v;
    s16 count;
    s16 minX;
    s16 minY;
    s16 minZ;
    s16 maxX;
    s16 maxY;
    s16 maxZ;
    s16 i;
    s16 j;

    count = linkIndex;
    if (hmf->unk14 == 0) {
        return;
    }

    hmf->unk60[objectIndex].unk54 = (HmfObjectLinkData *)HuMemAllocTag(faceCount * sizeof(HmfFaceData), D_800D5204_main);
    faces = (HmfFaceData *)hmf->unk60[objectIndex].unk54;
    record = D_800B19B8_main + 0x10;
    for (i = 0; i < linkIndex; i++) {
        if (record[0] == 0x16) {
            next = record + 0x2A;
        } else if (record[0] != 0x35) {
            next = record + 0xC;
        } else {
            next = record + 0x36;
        }
        record = next;
    }

    minX = minY = minZ = 0x7FFF;
    maxX = maxY = maxZ = -0x8000;
    flags = 0;

    for (i = 0; i < faceCount; i++) {
        func_80010EB0_main(&faces[i], record, hmf, &flags);
        if (record[0] == 0x16) {
            pointCount = 3;
        } else if (record[0] == 0x35) {
            pointCount = 4;
        } else {
            pointCount = 2;
        }

        for (j = 0; j < pointCount; j++) {
            p = &((s16 *)hmf->unk50)[faces[i].unk04[j] * 3];
            v = p[0];
            if (minX > v) {
                minX = v;
            }
            if (maxX < v) {
                maxX = v;
            }
            v = p[1];
            if (minY > v) {
                minY = v;
            }
            if (maxY < v) {
                maxY = v;
            }
            v = p[2];
            if (minZ > v) {
                minZ = v;
            }
            if (maxZ < v) {
                maxZ = v;
            }
        }
        switch (record[0]) {
            case 0x35:
                next = record + 0x36;
                break;
            case 0x16:
                next = record + 0x2A;
                break;
            default:
                next = record + 0xC;
                break;
        }
        record = next;
    }

    hmf->unk60[objectIndex].unk50 =
        (flags & 1) ? (hmf->unk60[objectIndex].unk50 | 0x10000) : hmf->unk60[objectIndex].unk50;
    bounds = hmf->unk60[objectIndex].unk42;
    bounds[0] = minX;
    bounds[1] = minY;
    bounds[2] = minZ;
    bounds = hmf->unk60[objectIndex].unk48;
    bounds[0] = maxX;
    bounds[1] = maxY;
    bounds[2] = maxZ;
}

void func_80010EB0_main(HmfFaceData *arg0, u8 *arg1, HmfLoadData *arg2, u16 *arg3) {
    s32 *values1;
    s32 *values2;
    u8 *colors;
    u8 *attr;
    u16 *coords1;
    u16 *coords2;
    u16 *coords3;
    s16 count;
    s16 i;
    s16 hasColor;
    s16 step;
    s32 temp;
    s32 value;

    switch (arg1[0]) {
        case 0x35:
            count = 4;
            step = 0xC;
            break;
        case 0x16:
            count = 3;
            step = 0xC;
            break;
        default:
            count = 2;
            step = 4;
            break;
    }
    arg0->unk00 = count;
    arg1++;
    values1 = &arg0->unk0C[0];
    values2 = &arg0->unk1C[0];
    i = 0;
    hasColor = 0;
    while (i < count) {
        arg0->unk04[i] = (arg1[0] << 8) + arg1[1];
        arg0->unk2C[i] = arg1[3];
        value = arg1[4];
        value <<= 0x18;
        value += arg1[5] << 0x10;
        value += arg1[6] << 8;
        *values1++ = value + arg1[7];
        value = arg1[8];
        value <<= 0x18;
        value += arg1[9] << 0x10;
        value += arg1[0xA] << 8;
        *values2++ = value + arg1[0xB];
        arg0->unk04[i] = (arg1[0] << 8) + arg1[1];
        if (arg1[3] != 0xFF) {
            temp = arg0->unk04[i];
            colors = arg2->unk54;
            colors[temp * 3 + 0] = colors[temp * 3 + 1] = colors[temp * 3 + 2] = 0;
            hasColor = -1;
        }
        arg1 += step;
        i++;
    }
    arg0->unk30 = (arg1[0] << 8) + arg1[1];
    if (hasColor != 0) {
        arg0->unk00 |= 0x80;
    }
    coords1 = &((u16 *)arg2->unk50)[arg0->unk04[0] * 3];
    coords2 = &((u16 *)arg2->unk50)[arg0->unk04[1] * 3];
    coords3 = &((u16 *)arg2->unk50)[arg0->unk04[2] * 3];
    func_8001116C_main(arg0->unk01, coords1, coords2, coords3);
    if (D_800B19C0_main != NULL) {
        *arg3 |= arg2->unk88[arg0->unk30].unk09;
        if (count == 2) {
            arg0->unk32 = -1;
        } else {
            arg0->unk32 = (arg1[2] << 8) + arg1[3];
            if (arg0->unk32 != -1) {
                attr = (u8 *)arg2->unk84[arg0->unk32].unkC;
                if (((attr[0x1C] - 3) < 2U) || attr[0x1D] == 3) {
                    *arg3 |= 1;
                }
            }
        }
    }
}

void func_8001116C_main(s8 *arg0, u16 *arg1, u16 *arg2, u16 *arg3) {
    s32 diffX1;
    s32 diffX2;
    s32 diffY1;
    s32 diffY2;
    s32 diffZ1;
    s32 diffZ2;
    f32 crossX;
    f32 crossY;
    f32 crossZ;
    f32 scale;
    s32 a;

    a = arg1[0];
    diffX1 = a - arg2[0];
    diffX2 = arg3[0] - a;
    a = arg1[1];
    diffY1 = a - arg2[1];
    diffY2 = arg3[1] - a;
    a = arg1[2];
    diffZ1 = a - arg2[2];
    diffZ2 = arg3[2] - a;

    crossX = (s16)diffY1 * (s16)diffZ2 - (s16)diffZ1 * (s16)diffY2;
    crossY = (s16)diffZ1 * (s16)diffX2 - (s16)diffX1 * (s16)diffZ2;
    crossZ = (s16)diffX1 * (s16)diffY2 - (s16)diffY1 * (s16)diffX2;

    scale = 127.0f / HuSqrtf(crossX * crossX + crossY * crossY + crossZ * crossZ);

    arg0[0] = (crossX != 0.0f) ? (crossX * scale) : 0;
    arg0[1] = (crossY != 0.0f) ? (crossY * scale) : 0;
    arg0[2] = (crossZ != 0.0f) ? (crossZ * scale) : 0.0f;
}

s16 func_80011334_main(HmfLoadData *hmf, void *arg1, s16 index) {
    u8 *data;
    u8 *src;
    u8 *dst;
    s16 sum;
    s16 i;
    s16 j;
    s16 len;

    data = D_800B19D0_main;
    sum = data[8];
    sum = (sum << 8) + data[9];
    if (sum == 0) {
        ((u8 *)arg1)[0] = 0;
        return 0;
    }
    data += 0xA;
    src = data + sum;
    for (i = 0; i < index; i++) {
        src += data[0];
        data++;
    }
    len = data[0];
    dst = arg1;
    i = 0;
    sum = 0;
    j = 0;
    for (; i < len; i++) {
        if (j >= 0x1B) {
            *dst = 0;
            return sum;
        }
        if (src[0] == 0x2F) {
            dst = arg1;
            sum = 0;
            j = 0;
            src++;
        } else {
            *dst = src[0];
            src++;
            sum += (j + 1) * *dst;
            dst++;
            j++;
        }
    }
    *dst = 0;
    return sum;
}

s16 func_80011460_main(u8 *arg0) {
    s32 sum = 0;
    s16 i = 1;
    u8 c = arg0[0];

    while (c != 0 && i < 28) {
        sum += i * c;
        arg0++;
        i++;
        c = arg0[0];
    }
    return sum;
}

s32 func_800114C0_main(HmfLoadData *hmf) {
    u8 *data;
    u8 *src;
    HmfDispData *entry;
    s16 *indices;
    s16 *coords;
    u8 *colors;
    HmfFloatBits scale;
    s32 size;
    s16 dispCount;
    s16 dispIndex;
    s16 vtxCount;
    s16 count;
    s16 j;

    data = hmf->unk34;
    dispCount = 0;

    while (1) {
        data = func_80010A38_main(0x44495350, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        data = func_80010AC8_main(data + 4);
        dispCount++;
    }

    if (dispCount == 0) {
        hmf->unk22 = 0;
        hmf->unkB4 = NULL;
        return 0;
    }

    hmf->unkB4 = HuMemAllocTag(dispCount * sizeof(HmfDispData), D_800CDD6A_main);
    hmf->unk22 = dispCount;
    data = hmf->unk34;
    dispIndex = 0;

    while (1) {
        data = func_80010A38_main(0x44495350, data, hmf->unk30);

        if (data == NULL) {
            break;
        }

        if (data[0xC] == 0x43) {
            entry = &hmf->unkB4[dispIndex];
            entry->unk1E = func_80011334_main(hmf, entry, (data[8] << 8) + data[9]);
            vtxCount = (data[0xA] << 8) + data[0xB];
            count = vtxCount;
            entry->unk1C = count;
            size = vtxCount * 2;
            indices = HuMemAllocTag(size, D_800CDD6A_main);
            entry->unk28 = indices;
            size += vtxCount;
            coords = HuMemAllocTag(size * 2, D_800CDD6A_main);
            entry->unk2C = coords;
            colors = HuMemAllocTag(size, D_800CDD6A_main);
            entry->unk30 = colors;
            entry->unk20 = (data[0xD] << 8) + data[0xE];
            scale.word = (data[0xF] << 0x18) + (data[0x10] << 0x10) + (data[0x11] << 8) + data[0x12];
            scale.single *= 5.0f;
            entry->unk24 = scale.single;
            src = data + 0x13;
            for (j = 0; j < count; j++) {
                indices[0] = (src[0] << 8) + src[1];
                coords[0] = (s16)((src[2] << 8) + src[3]) * scale.single;
                coords[1] = (s16)((src[4] << 8) + src[5]) * scale.single;
                coords[2] = (s16)((src[6] << 8) + src[7]) * scale.single;
                if (((s8 *)hmf->unk54)[indices[0] * 3 + 0] == 0 && ((s8 *)hmf->unk54)[indices[0] * 3 + 1] == 0 && ((s8 *)hmf->unk54)[indices[0] * 3 + 2] == 0) {
                    colors[0] = colors[1] = colors[2] = 0;
                } else {
                    colors[0] = src[8];
                    colors[1] = src[9];
                    colors[2] = src[0xA];
                }
                indices++;
                coords += 3;
                colors += 3;
                src += 0xB;
            }
        }
        data = func_80010AC8_main(data + 4);
        dispIndex++;
    }
    func_80011874_main(hmf);
    return 1;
}

s32 func_80011874_main(HmfLoadData *hmf) {
    char buf[0x20];
    u8 *data;
    u8 *sub2;
    u8 *cur;
    HmfMtnData *entry;
    s16 id;
    s16 cnt;
    s16 count2;
    s16 mtnCount;
    s16 subCount;
    s32 subCount1;
    s16 i;
    s16 k;
    s16 m;

    data = hmf->unk34;
    mtnCount = 0;
    while (1) {
        data = func_80010A38_main(0x4D544E31, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        cur = data + 0xD;
        subCount1 = data[0xA];
        for (i = 0; i < subCount1; i++) {
            if (cur[2] == 0xA) {
                mtnCount++;
            }
            cur += ((cur[0] << 8) + cur[1]) + 2;
        }
        data = func_80010AC8_main(data + 4);
    }
    if (mtnCount == 0) {
        hmf->unkB8 = NULL;
        return 0;
    }
    hmf->unkB8 = HuMemAllocTag(mtnCount * sizeof(HmfMtnData), D_800CDD6A_main);
    hmf->unk24 = mtnCount;
    data = hmf->unk34;
    mtnCount = 0;
    while (1) {
        data = func_80010A38_main(0x4D544E31, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        subCount = data[0xA];
        sub2 = data + 0xD;
        entry = &hmf->unkB8[mtnCount];
        for (i = 0; i < subCount; i++) {
            cur = sub2;
            sub2 += ((cur[0] << 8) + cur[1]) + 2;
            if (cur[2] == 0xA) {
                cur += 3;
                entry->unk00 = (cur[0] << 8) + cur[1];
                cnt = (cur[2] << 8) + cur[3];
                count2 = cnt;
                entry->unk02 = count2;
                entry->unk04 = HuMemAllocTag(cnt * 2, D_800CDD6A_main);
                cur += 4;
                for (k = 0; k < count2; k++) {
                    id = func_80011334_main(hmf, buf, (cur[0] << 8) + cur[1]);
                    for (m = 0; m < hmf->unk22; m++) {
                        if (id == hmf->unkB4[m].unk1E && strcmp(hmf->unkB4[m].unk00, buf) == 0) {
                            break;
                        }
                    }
                    if (m == hmf->unk22) {
                        entry->unk04[k] = 0;
                    } else {
                        entry->unk04[k] = m;
                    }
                    cur += 2;
                }
                mtnCount++;
            }
        }
        data = func_80010AC8_main(data + 4);
    }
    return 1;
}

void func_80011B94_main(HmfLoadData *hmf, void *arg1, s16 index) {
    u8 *data;
    HmfMapData *entry;
    s32 value;

    data = arg1;
    entry = &hmf->unkC4[index];
    value = ((data[0] << 0x18) + (data[1] << 0x10)) + (data[2] << 8);
    entry->unk20 = value + data[3];
    value = 0x10;
    value = ((data[4] << 0x18) + (data[5] << value)) + (data[6] << 8);
    entry->unk24 = value + data[7];
    value = ((data[8] << 0x18) + (data[9] << 0x10)) + (data[10] << 8);
    entry->unk28 = value + data[11];
}

s32 func_80011C40_main(HmfLoadData *hmf, void *arg1) {
    char buf[0x20];
    u8 *data;
    HmfData_UnkBC *env;
    s16 id;
    s16 m;
    s32 temp1, temp2, temp3, temp4;

    data = arg1;
    env = hmf->unkBC;
    id = func_80011334_main(hmf, buf, (data[0] << 8) + data[1]);
    for (m = 0; m < hmf->unk26; m++) {
        if (id == hmf->unkC4[m].unk1C && strcmp(hmf->unkC4[m].unk00, buf) == 0) {
            break;
        }
    }
    if (m == hmf->unk26) {
        return 0;
    }
    env->unk08 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk0C = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk10 = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk00 = m;
    id = func_80011334_main(hmf, buf, (data[2] << 8) + data[3]);
    for (m = 0; m < hmf->unk26; m++) {
        if (id == hmf->unkC4[m].unk1C && strcmp(hmf->unkC4[m].unk00, buf) == 0) {
            break;
        }
    }
    if (m == hmf->unk26) {
        return 0;
    }
    env->unk14 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk18 = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk1C = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk02 = m;
    id = func_80011334_main(hmf, buf, (data[4] << 8) + data[5]);
    for (m = 0; m < hmf->unk26; m++) {
        if (id == hmf->unkC4[m].unk1C && strcmp(hmf->unkC4[m].unk00, buf) == 0) {
            break;
        }
    }
    if (m == hmf->unk26) {
        return 0;
    }
    env->unk20 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk24 = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk28 = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk04 = m;
    temp1 = data[6] << 0x18;
    temp1 += data[7] << 0x10;
    temp1 += data[8] << 0x8;
    temp2 = data[9];
    temp1 += temp2;
    temp2 = temp1;
    temp1 = temp2;

    *((s32 *)(&env->unk2C)) = temp1;

    return 1;
}

void func_80011F9C_main(HmfLoadData *hmf) {
    u8 *data;
    s32 value;

    data = D_800B19B0_main;
    value = data[0xC];
    value <<= 0x18;
    value += data[0xD] << 0x10;
    value += data[0xE] << 8;
    value += data[0xF];
    if (value & 2) {
        D_800A0544_main = 1;
    } else {
        D_800A0544_main = 0;
    }
    if (D_800B19B0_main[0x1C] == 0x45) {
        hmf->unkD4 = func_80017D24_main;
        hmf->unkD8 = func_80088910_main;
    } else {
        hmf->unkD4 = func_8001866C_main;
        hmf->unkD8 = func_80018978_main;
    }
}

void func_8001203C_main(HmfLoadData *hmf, u8 *data, s32 index) {
    u8 *entry;
    u8 *colors;
    HmfFloatBits x;
    HmfFloatBits y;
    HmfFloatBits z;
    f32 len;
    s32 value;

    entry = &((u8 *)hmf->unkC0)[index * 7];
    colors = &D_800B19C4_main[((data[0] << 8) + data[1]) * 4 + 0xA];
    entry[0] = colors[0];
    entry[1] = colors[1];
    entry[2] = colors[2];
    data += 3;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    x.word = value + data[3];
    len = x.single * x.single;
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    y.word = value + data[7];
    len += y.single * y.single;
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    z.word = value + data[0xB];
    len += z.single * z.single;
    if (len == 0.0f) {
        entry[4] = 0;
        entry[5] = 0;
        entry[6] = 0x78;
    } else {
        len = HuSqrtf(len);
        entry[4] = (s8)(x.single / len * 120.0f);
        entry[5] = (s8)(y.single / len * 120.0f);
        entry[6] = (s8)(z.single / len * 120.0f);
    }
    entry[3] = 0;
}
