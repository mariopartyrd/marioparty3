#include "common.h"
#include "rom.h"
#include "ovl_81.h"
#include "mallocblock.h"

typedef struct HVQHeader {
    /* 0x00 */ s32 allocSize;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ char unk_08[8];
} HVQHeader; //sizeof 0x10

typedef struct UnkModelStruct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} UnkModelStruct; //sizeof 0x3C

typedef struct UnkHvqStruct {
    s32 unk_00;
    s32 unk_04;
    u8* dest;
    s32 dmaSize;
    u32 src;
} UnkHvqStruct;

typedef struct OverlayBgEntry {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} OverlayBgEntry; //sizeof 0x14

extern f32 D_80104848_name_81[2];
extern u8 D_80100FFC_name_81;
extern f32 D_80101000_name_81;
extern f32 D_801031D0_name_81;
extern f32 D_80104848_name_81[2];
extern f32 D_80102D2C_name_81; // Camera speed
extern u32 D_80102D20_name_81;
extern s32 D_80102D24_name_81;
extern u32 D_80102D28_name_81;
extern s32* D_80100FF0_name_81;
extern u32* D_80100FF4_name_81;
extern UnkModelStruct* D_80100FF8_name_81;
extern f32 D_80101004_name_81;
extern f32 D_80101008_name_81;
extern u8* D_80102D3C_name_81;
extern u16 D_80102D30_name_81;
extern s16 D_80102D32_name_81;
extern s16 D_80102D34_name_81;
extern s16 D_80102D36_name_81;
extern s16 D_80102D38_name_81;
extern u8* D_801031C0_name_81;
extern Vec D_80103204_name_81;
extern s32 D_80105628_name_81;
extern OSMesgQueue D_80103210_name_81;
extern OSMesgQueue D_80104660_name_81;
extern OSMesgQueue D_80104820_name_81;
extern HvqHeader* D_80102D40_name_81;
extern OSMesgQueue D_80104740_name_81;
extern void* D_80103228_name_81;
extern void* D_80104678_name_81;
extern void* D_80104758_name_81;
extern void* D_80104838_name_81;
extern OSPri D_80103E50_name_81;
extern OSThread D_80103CA0_name_81;
extern OSThread D_801032F0_name_81;
extern OverlayBgEntry D_80102D48_name_81[50];
extern OverlayBgEntry *D_80103130_name_81[6][6];
extern u32 D_8010100C_name_81;
extern Gfx D_80101010_name_81[];
extern Process* D_801031C8_name_81;
extern Vec D_801031D4_name_81;
extern Vec D_801031E0_name_81;
extern Vec D_801031EC_name_81;
extern Vec D_801031F8_name_81;
extern Vec2f D_80104840_name_81;
extern f32 D_801031CC_name_81;
extern Process* D_801031C4_name_81;
extern UnkBoard7 D_80104850_name_81[64];
extern s32 D_8010105C_name_81;
extern s32 D_80105050_name_81;
extern Process* D_80101058_name_81;
extern Object* D_80105058_name_81[16];

static s32 func_800E5CC4_name_81(u16);
void func_800E77D8_name_81(Gfx** arg0, s32 arg1, u8 arg2);
static void func_800E7EF8_name_81(void);
static void func_800E8164_name_81(void);
void func_800E8194_name_81(void);
static void func_800E9200_name_81(void);
static void func_800E9230_name_81(void);

void func_800E4F50_name_81(Addr arg0) {
    HVQHeader* temp_v0;
    s32* temp_v0_2;
    u32 temp_s0;

    D_80102D20_name_81 = (u32)arg0;
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead((u32)arg0, (u8*)temp_v0, sizeof(HVQHeader));
    D_80102D24_name_81 = temp_v0->allocSize;
    HuMemMemoryFreeTemp(temp_v0);
    temp_s0 = D_80102D24_name_81 * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_80100FF0_name_81 = temp_v0_2;
    dmaRead((u32)(arg0 + 4), (u8*)temp_v0_2, temp_s0);
    D_80102D3C_name_81 = HuMemMemoryAllocTemp(0x300);
    D_80100FF8_name_81 = NULL;
}

void func_800E4FF4_name_81(void) {
    D_80100FF8_name_81 = NULL;
}

void MBDBackClose(void) {
    if (D_80100FF0_name_81 != NULL) {
        HuMemMemoryFreeTemp(D_80100FF0_name_81);
        D_80100FF0_name_81 = NULL;
        HuMemMemoryFreeTemp(D_80102D3C_name_81);
    }
}

void MBDBackCreate(s32 arg0, s32 arg1) {
    UnkModelStruct* temp_v0_3;
    u32 temp_s0;
    s32* temp_v0;
    u32* temp_v0_2;

    D_80105628_name_81 = arg0;
    D_80102D28_name_81 = D_80102D20_name_81 + D_80100FF0_name_81[arg0];
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead(D_80102D28_name_81, (u8*)temp_v0, sizeof(HVQHeader));
    arg0 = *temp_v0;
    HuMemMemoryFreeTemp(temp_v0);
    arg0++;
    temp_s0 = arg0 * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_80100FF4_name_81 = temp_v0_2;
    dmaRead(D_80102D28_name_81 + 4, (u8*)temp_v0_2, temp_s0);
    temp_v0_3 = HuMemMemoryAllocTemp(sizeof(UnkModelStruct));
    D_80100FF8_name_81 = temp_v0_3;
    dmaRead(D_80102D28_name_81 + D_80100FF4_name_81[0], (u8*)&temp_v0_3->unk0, sizeof(UnkModelStruct));
    D_80103204_name_81.x = D_80100FF8_name_81->unk18;
    D_80103204_name_81.y = D_80100FF8_name_81->unk1C;
    D_80103204_name_81.z = D_80100FF8_name_81->unk20;
    D_80100FF8_name_81->unk18 *= 5.0f;
    D_80100FF8_name_81->unk1C *= 5.0f;
    D_80100FF8_name_81->unk20 *= 5.0f;
    D_80100FF8_name_81->unk24 *= 5.0f;
    D_80100FF8_name_81->unk28 *= 5.0f;
    D_80100FF8_name_81->unk2C *= 5.0f;
    D_801031C0_name_81 = HuMemMemoryAllocTemp(func_800E5CC4_name_81(0));
    dmaRead(D_80102D28_name_81 + D_80100FF4_name_81[1], D_801031C0_name_81, func_800E5CC4_name_81(0));
    D_80102D34_name_81 = 0;
    D_80102D32_name_81 = 0;
    D_80102D36_name_81 = D_80100FF8_name_81->unk0 * D_80100FF8_name_81->unk8 / 2;
    D_80102D38_name_81 = D_80100FF8_name_81->unk4 * D_80100FF8_name_81->unkC / 2;
    D_80102D30_name_81 = 1;
    func_8001F95C_main(0, func_800E77D8_name_81);
    func_800E5BE8_name_81();
    func_800E5954_name_81();
    if (arg1 != 0) {
        func_800E7EF8_name_81();
    }
    func_800E856C_name_81(1.0f);
    MBDBackTPLvlSet(0xFF);
    MBDCameraSpeedSet(-1.0f);
    D_80101004_name_81 = 0.0f;
    D_80101008_name_81 = 0.0f;
    MBDCameraZoomSet(1.0f);
}

void MBDBackLoad(s32 arg0) {
    MBDBackCreate(arg0, 1);
}

void MBDBackKill(void) {
    if (D_80100FF4_name_81 != NULL) {
        HuMemMemoryFreeTemp(D_80100FF4_name_81);
        D_80100FF4_name_81 = NULL;
        HuMemMemoryFreeTemp(D_80100FF8_name_81);
        HuMemMemoryFreeTemp(D_801031C0_name_81);
        func_8001F95C_main(0, 0);
        func_800E5C20_name_81();
        func_800E8164_name_81();
    }
}

static void MBDBackOffsetSet(s16 arg0, s16 arg1) {
    D_80102D32_name_81 = arg0;
    D_80102D34_name_81 = arg1;
}

static f32 MBDBackMinXGet(void) {
    return ((-D_80102D36_name_81 + 160.0f) / D_801031D0_name_81) + 160.0f;
}

static f32 MBDBackMaxXGet(void) {
    return ((D_80102D36_name_81 - 160.0f) / D_801031D0_name_81) + 160.0f;
}

static f32 MBDBackMinYGet(void) {
    return ((-D_80102D38_name_81 + 120.0f) / D_801031D0_name_81) + 120.0f;
}

static f32 MBDBackMaxYGet(void) {
    return ((D_80102D38_name_81 - 120.0f) / D_801031D0_name_81) + 120.0f;
}

static u16 MBDBackPosClamp(Vec2f* arg0, f32 arg1) {
    u16 var_v1;

    var_v1 = 0;
    if (arg0->x <= (((-D_80102D36_name_81 + 160.0f) / arg1) + 160.0f)) {
        arg0->x = ((-D_80102D36_name_81 + 160.0f) / arg1) + 160.0f;
        var_v1 = 1;
    }
    if (((D_80102D36_name_81 - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_80101000_name_81))) <= arg0->x) {
        arg0->x = ((D_80102D36_name_81 - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_80101000_name_81)));
        var_v1 |= 2;
    }
    if (arg0->y <= ((-D_80102D38_name_81 + 120.0f) / arg1) + 120.0f) {
        arg0->y = ((-D_80102D38_name_81 + 120.0f) / arg1) + 120.0f;
        var_v1 |= 4;
    }
    if (((D_80102D38_name_81 - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_80101000_name_81))) <= arg0->y) {
        arg0->y = ((D_80102D38_name_81 - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_80101000_name_81)));
        var_v1 |= 8;
    }
    return var_v1;
}

void MBDBackDispSet(u16 arg0) {
    if (arg0) {
        D_80102D30_name_81 = D_80102D30_name_81 | 1;
    } else {
        D_80102D30_name_81 = D_80102D30_name_81 & ~1;
    }
}

static void func_800E5618_name_81(void) {
    UnkHvqStruct* sp10;

    while (1) {
        osRecvMesg(&D_80103210_name_81, (OSMesg)&sp10, OS_MESG_BLOCK);
        if (sp10 == NULL) {
            break;
        }
        dmaRead(sp10->src, sp10->dest, sp10->dmaSize);
        osSendMesg(&D_80104660_name_81, (OSMesg)sp10, OS_MESG_NOBLOCK);
    }

    osSendMesg(&D_80104820_name_81, (OSMesg)1, OS_MESG_NOBLOCK);
    osDestroyThread(NULL);
}

#define SlideReadUint(buffer, src)    \
    do {                              \
        (buffer) = ((*src++) << 24);  \
        (buffer) += ((*src++) << 16); \
        (buffer) += ((*src++) << 8);  \
        (buffer) += (*src++);         \
    } while (0)

static void func_800E5690_name_81(u8 *input, u8 *output, s32 compressedSize) {
    u8 *src = input + 4;       // Skip metadata
    s32 flagLen = 0;           // Remaining bits in the bit buffer
    s32 flag = 0;              // Buffer holding bits for control decisions
    s32 size = compressedSize; // Bytes left to decompress
    u8 *matchPtr;              // Pointer for back-reference matches
    u32 offset, len;           // Offset and length for back-references
    u32 dist;                  // Temporary value for reading data

    while (size != 0) {
        // Refill the bit buffer if empty
        if (flagLen == 0) {
            SlideReadUint(flag, src);
            flagLen = 32;
        }

        // Determine if the next data is a literal or back-reference
        if (flag >> 31) {
            *output++ = *src++; // Write literal byte
            size--;
        } else {
            // Read the next 16 bits for the back-reference
            dist = (*src++ << 8);
            dist += (*src++);
            len = (dist >> 12) & 0xF;
            dist &= 0xFFF;
            // Calculate the pointer for the back-reference match
            matchPtr = output - dist;

            // Handle extended match lengths
            if (len == 0) {
                len = (*src++) + 0x12;
            } else {
                len += 2;
            }

            size -= len;
            if (size < 0) {
                break; // Prevent buffer overflow
            }

            // Copy the match data from the back-reference
            while (len > 0) {
                *output++ = matchPtr[-1];
                matchPtr++;
                len--;
            }
        }

        // Shift the bit buffer and decrement remaining bits
        flag <<= 1;
        flagLen--;

        // Exit if all bytes have been decompressed
        if (size == 0) {
            break;
        }
    }
}

// decodes HVQ board image tile?
static void func_800E5784_name_81(void) {
    HvqUnk *sp10;
    HvqHeader *temp_a0;

    func_8006A370_main(0xFF);
    func_80069E68_main(D_801031C0_name_81); //"HVQ-MPS 1.1"
    while (1) {
        osRecvMesg(&D_80104660_name_81, (OSMesg)&sp10, OS_MESG_BLOCK);
        if (sp10 != NULL) {
            temp_a0 = sp10->unk8;
            D_80102D40_name_81 = sp10->unk8;
            if (temp_a0->magic == 0x48565153) { //"HVQS"
                                                // is HVQS, decode it
                func_800698E8_main(&temp_a0->unk4, sp10->unk4, 0x40, D_80102D3C_name_81);
            } else {
                // 0x1800 size for decoded tile
                func_800E5690_name_81((u8*)&D_80102D40_name_81->unk4, sp10->unk4, 0x1800);
            }
            osSendMesg(&D_80104740_name_81, (OSMesg)sp10, OS_MESG_NOBLOCK);
        } else {
            break;
        }
    }

    osSendMesg(&D_80104820_name_81, (OSMesg)2, OS_MESG_NOBLOCK);
    osDestroyThread(NULL);
}

static void func_800E5860_name_81(void) {
    osCreateMesgQueue(&D_80103210_name_81, &D_80103228_name_81, 50);
    osCreateMesgQueue(&D_80104660_name_81, &D_80104678_name_81, 50);
    osCreateMesgQueue(&D_80104740_name_81, &D_80104758_name_81, 50);
    osCreateMesgQueue(&D_80104820_name_81, &D_80104838_name_81, 2);
    D_80103E50_name_81 = 1;
    osCreateThread(&D_80103CA0_name_81, 0x64, (void (*)(void*))func_800E5784_name_81, NULL, &D_80104660_name_81, D_80103E50_name_81);
    osStartThread(&D_80103CA0_name_81);
    osCreateThread(&D_801032F0_name_81, 0x65, (void (*)(void*))func_800E5618_name_81, NULL, &D_80103CA0_name_81, 4);
    osStartThread(&D_801032F0_name_81);
}

void func_800E5954_name_81(void) {
    D_80103E50_name_81 = 3;
}

void func_800E5964_name_81(void) {
    D_80103E50_name_81 = 1;
}

static void func_800E5974_name_81(void) {
    if (osGetThreadPri(&D_80103CA0_name_81) != D_80103E50_name_81) {
        osSetThreadPri(&D_80103CA0_name_81, D_80103E50_name_81);
    }
}

static void func_800E59B0_name_81(void) {
    UnkHvqStruct* sp10;

    while (1) {
        if (osRecvMesg(&D_80104740_name_81, (OSMesg)&sp10, 0) != OS_MESG_NOBLOCK) {
            break;
        }
        if (sp10 != NULL) {
            HuMemMemoryFreePerm(sp10->dest);
            sp10->dest = NULL;
        }
    }
}

static void func_800E5A00_name_81(void) {
    s32 i;

    osJamMesg(&D_80103210_name_81, NULL, OS_MESG_NOBLOCK);
    osJamMesg(&D_80104660_name_81, NULL, OS_MESG_NOBLOCK);

    func_800E5954_name_81();
    func_800E5974_name_81();

    osRecvMesg(&D_80104820_name_81, NULL, OS_MESG_BLOCK);
    osRecvMesg(&D_80104820_name_81, NULL, OS_MESG_BLOCK);

    for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++) {
        OverlayBgEntry* temp = &D_80102D48_name_81[i];
        if (temp->unk_08 != NULL) {
            HuMemMemoryFreePerm(temp->unk_08);
            temp->unk_08 = NULL;
        }
    }
}

static void func_800E5AC8_name_81(void) {
    OverlayBgEntry* var_s0 = D_80102D48_name_81;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = -1;
        var_s0->unk4 = HuMemAlloc(0x1800);
        var_s0->unk_08 = NULL;
    }

    bzero(D_80103130_name_81, sizeof(D_80103130_name_81));
}

static void func_800E5B3C_name_81(void) {
    OverlayBgEntry* var_v1 = D_80102D48_name_81;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++, var_v1++) {
        if ((var_v1->unk_08 == NULL) && (var_v1->unk0 == 0)) {
            var_v1->unk2 = -1;
        }
        var_v1->unk0 = 0;
    }
}

static void func_800E5B80_name_81(void) {
    OverlayBgEntry* var_s0 = D_80102D48_name_81;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = -1;

        if (var_s0->unk4 != NULL) {
            HuMemFree(var_s0->unk4);
            var_s0->unk4 = NULL;
        }
    }
}

void func_800E5BE8_name_81(void) {
    func_800E5AC8_name_81();
    func_800E5860_name_81();
    D_80102D30_name_81 |= 4;
}

void func_800E5C20_name_81(void) {
    func_800E5A00_name_81();
    func_800E5B80_name_81();
    D_80102D30_name_81 &= ~4;
}

void func_800E5C58_name_81(void) {
    D_80102D30_name_81 &= ~4;
}

f32 MBDBackMdlScaleGet(void) {
    if (D_80100FF8_name_81 == NULL) {
        return 1.0f;
    } else {
        return D_80100FF8_name_81->unk14;
    }
}

static u16 func_800E5C94_name_81(s32 arg0, s32 arg1) {
    return ((((D_80100FF8_name_81->unkC - arg1) - 1) * D_80100FF8_name_81->unk8) + arg0 + 1);
}

static s32 func_800E5CC4_name_81(u16 arg0) {
    arg0++;
    return D_80100FF4_name_81[(arg0 + 1)] - D_80100FF4_name_81[(arg0 + 0)];
}

static s32 func_800E5CEC_name_81(u16 arg0) {
    arg0++;
    return D_80102D28_name_81 + D_80100FF4_name_81[(arg0)];
}

OverlayBgEntry *func_800E5D18_name_81(u16 arg0) {
    OverlayBgEntry *entry;
    OverlayBgEntry *slot;
    s32 i;
    s32 size;

    slot = NULL;
    entry = D_80102D48_name_81;

    for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++, entry++) {
        if (entry->unk2 == -1) {
            slot = entry;
        } else if (entry->unk2 == arg0) {
            entry->unk0 = 1;
            return entry;
        }
    }

    if (slot != NULL) {
        slot->unk0 = 1;
        slot->unk2 = arg0;
        slot->unk10 = func_800E5CEC_name_81(arg0);
        size = func_800E5CC4_name_81(arg0);
        slot->unkC = size;
        slot->unk_08 = HuMemMemoryAllocPerm(size);
        osSendMesg(&D_80103210_name_81, slot, OS_MESG_NOBLOCK);
    }
    return slot;
}

static void func_800E5DD8_name_81(void) {
    s32 tileX;
    s32 tileY;
    s32 x;
    s32 y;

    tileY = (s32)(((f32)((D_80102D38_name_81 + D_80102D34_name_81) - 0x78) -
                   ((240.0f - (240.0f / D_80101000_name_81)) / 2.0f)) / 48.0f);

    for (y = 0; y < 6; y++, tileY++) {
        tileX = (s32)(((f32)((D_80102D36_name_81 + D_80102D32_name_81) - 0xA0) -
                       ((320.0f - (320.0f / D_80101000_name_81)) / 2.0f)) / 64.0f);

        for (x = 0; x < 6; x++, tileX++) {
            if ((tileX < 0) || (tileY < 0) ||
                (tileX >= D_80100FF8_name_81->unk8) ||
                (tileY >= D_80100FF8_name_81->unkC)) {
                D_80103130_name_81[x][y] = NULL;
            } else {
                D_80103130_name_81[x][y] =
                    func_800E5D18_name_81(func_800E5C94_name_81(tileX, tileY));
            }
        }
    }
}

#define gSPScisTextureRectangle_MP(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | \
    _SHIFTL(MAX((s16)(xh),0), 12, 12) | \
    _SHIFTL(MAX((s16)(yh),0), 0, 12)); \
    _g->words.w1 = (_SHIFTL((tile), 24, 3) | \
    _SHIFTL(MAX((s16)(xl),0), 12, 12) | \
    _SHIFTL(MAX((s16)(yl),0), 0, 12)); \
    gImmp1(pkt, G_RDPHALF_1, \
    (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl)*(s16)(dsdx))>>7),0)) : (MIN((((s16)(xl)*(s16)(dsdx))>>7),0))) : 0)), 16, 16) |\
    _SHIFTL(((t) - (((s32)(yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl)*(s16)(dtdy))>>7),0)) : (MIN((((s16)(yl)*(s16)(dtdy))>>7),0))) : 0)), 0, 16))); \
    gImmp1(pkt, G_RDPHALF_2, (_SHIFTL((s16)(dsdx), 16, 16) | _SHIFTL((s16)(dtdy), 0, 16))); \
}

void func_800E5FB0_name_81(Gfx** arg0, void* arg1, s16 arg2, s16 arg3) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;

    temp_f20 = ((f32) arg2 + (D_80104848_name_81[0] / 4.0f)) - (f32) (s32) (D_80104848_name_81[0] / 4.0f);
    temp_f22 = ((f32) arg3 + (D_80104848_name_81[1] / 4.0f)) - (f32) (s32) (D_80104848_name_81[1] / 4.0f);

    if (D_8010100C_name_81 == 0) {
        func_8003465C_main(arg0, arg1, 0, 2, 0x40, 0x20, 0, 0, 0x40, 0x20, 0, 1, 1, 6, 5, 0, 0);
    } else {
        gDPLoadTextureBlock((*arg0)++, arg1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_MIRROR,
                            G_TX_MIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    if (!(D_80102D30_name_81 & 0x10)) {
        if (D_8010100C_name_81 == 0) {
            gSPScisTextureRectangle_MP((*arg0)++,
                /*xl*/(temp_f20 * D_80101000_name_81 * 4.0f),
                /*yl*/((temp_f22 * D_80101000_name_81 * 4.0f)),
                /*xh*/(temp_f20 + 64.0f) * D_80101000_name_81 * 4.0f,
                /*yh*/(temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f,
                /*tile*/0,
                /*s*/0,
                /*t*/0,
                /*dsdx*/(s16)(1024.0f / D_80101000_name_81),
                /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
            );
        } else {
            gSPScisTextureRectangle_MP((*arg0)++,
                /*xl*/(temp_f20 * D_80101000_name_81 * 4.0f),
                /*yl*/((temp_f22 * D_80101000_name_81 * 4.0f)),
                /*xh*/(temp_f20 + 64.0f) * D_80101000_name_81 * 4.0f,
                /*yh*/(temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f,
                /*tile*/0,
                /*s*/0,
                /*t*/0,
                /*dsdx*/(s16)(1024.0f / D_80101000_name_81),
                /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
            );
        }
    } else {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/((256.0f - temp_f20) * D_80101000_name_81 * 4.0f),
            /*yl*/((temp_f22 * D_80101000_name_81 * 4.0f)),
            /*xh*/((320.0f - temp_f20) * D_80101000_name_81 * 4.0f),
            /*yh*/((temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f),
            /*tile*/0,
            /*s*/0x7e0,
            /*t*/0,
            /*dsdx*/-(s16)(1024.0f / D_80101000_name_81),
            /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
        );
    }

    if (D_8010100C_name_81 == 0) {
        func_8003465C_main(arg0, arg1 + 0x1000, 0, 2, 0x40, 0x10, 0, 0, 0x40, 0x10, 0, 1, 1, 6, 4, 0, 0);
    } else {
        gDPLoadTextureBlock((*arg0)++, arg1 + 0x1000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0,
                            G_TX_MIRROR, G_TX_MIRROR, 6, 4, G_TX_NOLOD, G_TX_NOLOD);
    }

    if (!(D_80102D30_name_81 & 0x10)) {
        if (D_8010100C_name_81 == 0) {
            gSPScisTextureRectangle_MP((*arg0)++,
                /*xl*/(temp_f20 * D_80101000_name_81 * 4.0f),
                /*yl*/((temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f),
                /*xh*/((temp_f20 + 64.0f) * D_80101000_name_81 * 4.0f),
                /*yh*/((temp_f22 + 48.0f) * D_80101000_name_81 * 4.0f),
                /*tile*/0,
                /*s*/0,
                /*t*/0,
                /*dsdx*/(s16)(1024.0f / D_80101000_name_81),
                /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
            );
        } else {
            gSPScisTextureRectangle_MP((*arg0)++,
                /*xl*/(temp_f20 * D_80101000_name_81 * 4.0f),
                /*yl*/((temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f),
                /*xh*/((temp_f20 + 64.0f) * D_80101000_name_81 * 4.0f),
                /*yh*/((temp_f22 + 48.0f) * D_80101000_name_81 * 4.0f),
                /*tile*/0,
                /*s*/0,
                /*t*/0,
                /*dsdx*/(s16)(1024.0f / D_80101000_name_81),
                /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
            );
        }
    } else {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/((256.0f - temp_f20) * D_80101000_name_81 * 4.0f),
            /*yl*/((temp_f22 + 32.0f) * D_80101000_name_81 * 4.0f),
            /*xh*/((320.0f - temp_f20) * D_80101000_name_81 * 4.0f),
            /*yh*/((temp_f22 + 48.0f) * D_80101000_name_81 * 4.0f),
            /*tile*/0,
            /*s*/0x7e0,
            /*t*/0,
            /*dsdx*/-(s16)(1024.0f / D_80101000_name_81),
            /*dtdy*/(s16)(1024.0f / D_80101000_name_81)
        );
    }
}

void func_800E77D8_name_81(Gfx** arg0, s32 arg1, u8 arg2) {
    u16 sp1E;
    u16 sp26;
    s16 spY;
    s16 spX;
    s16 row;
    s16 col;
    s16 temp_s0;
    OverlayBgEntry* bgEntry;

    if (arg2 || !(D_80102D30_name_81 & 4)) {
        return;
    }

    func_800E59B0_name_81();
    if (!(D_80102D30_name_81 & 1)) {
        return;
    }

    func_800E5B3C_name_81();
    temp_s0 = func_8004D6AC_main(0xC8, 0, 0);
    func_800E5DD8_name_81();
    func_8004D6E8_main(temp_s0);

    sp26 = ((D_80102D38_name_81 + D_80102D34_name_81) - 120) % 48;
    sp1E = ((D_80102D36_name_81 + D_80102D32_name_81) - 160) % 64;

    spY = (s32)(((f32)(((D_80102D38_name_81 + D_80102D34_name_81)) - 120) - ((240.0f - (240.0f / D_80101000_name_81)) / 2.0f)) / 48.0f) - ((((D_80102D38_name_81 + D_80102D34_name_81)) - 120) / 48);
    spX = (s32)(((f32)(((D_80102D36_name_81 + D_80102D32_name_81)) - 160) - ((320.0f - (320.0f / D_80101000_name_81)) / 2.0f)) / 64.0f) - ((((D_80102D36_name_81 + D_80102D32_name_81)) - 160) / 64);

    gSPDisplayList((*arg0)++, D_80101010_name_81);
    gDPSetEnvColor((*arg0)++, 0xFF, 0xFF, 0xFF, D_80100FFC_name_81);

    if (D_80100FFC_name_81 < 0xFF) {
        if (D_80102D30_name_81 & 8) {
            gDPSetCombineLERP((*arg0)++, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
        } else {
            gDPSetCombineLERP((*arg0)++, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT);
        }
        gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    } else {
        if (D_80102D30_name_81 & 8) {
            gDPSetCombineLERP((*arg0)++, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0);
        }

        gDPSetRenderMode((*arg0)++, G_RM_AA_SUB_SURF, G_RM_AA_SUB_SURF2);
    }

    for (row = 0; row < 6; row++) {
        for (col = 0; col < 6; col++) {
            bgEntry = D_80103130_name_81[col][row];
            if (bgEntry != NULL) {
                func_800E5FB0_name_81(
                    arg0,
                    bgEntry->unk4,
                    ((col + spX) * 64) - sp1E,
                    ((row + spY) * 48) - sp26
                );
            }
        }
    }

    func_800E5974_name_81();
}

f32 MBDCameraZoomGet(void) {
    return D_80101000_name_81;
}

void MBDCameraZoomSet(f32 zoom) {
    D_80101000_name_81 = zoom;
}

static void func_800E7C1C_name_81(void) {
    f32 target;
    f32 diff;
    f32 step;
    f32 next;
    f32 temp;

    target = *(f32 *)HuPrcCurrentGet()->user_data;

    while (1) {
        diff = D_80101000_name_81 - target;
        step = (0.0f < diff) ? diff : 0.0f - (D_80101000_name_81 - target);
        
        if (step <= 0.005f) {
            break;
        }
        
        step /= 4.0f;
        if (step < 0.005f) {
            step = 0.005f;
        }
        if (target < D_80101000_name_81) {
            next = D_80101000_name_81 - step;
        } else {
            next = step + D_80101000_name_81;
        }
        D_80101000_name_81 = next;
        HuPrcVSleep();
    }

    D_80101000_name_81 = target;
    D_801031C8_name_81 = NULL;
    omDelPrcObj(NULL);
}

Process* MBDCameraZoomMotStart(f32 arg0) {
    Process* temp_v0;
    f32* temp_v0_2;

    if (D_801031C8_name_81 != NULL) {
        omDelPrcObj(D_801031C8_name_81);
    }
    D_801031C8_name_81 = omAddPrcObj(func_800E7C1C_name_81, 1U, 0, 0x40);

    temp_v0_2 = HuMemMemoryAlloc(D_801031C8_name_81->heap, 0x10);
    D_801031C8_name_81->user_data = temp_v0_2;
    *temp_v0_2 = arg0;
    return D_801031C8_name_81;
}

static void func_800E7D90_name_81(void) {
    f32 temp_f22;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;
    s32 var_s0;
    s32 i;

    temp_f22 = *(f32*)HuPrcCurrentGet()->user_data;
    temp_f2 = D_80101000_name_81 - temp_f22;
    if (temp_f2 > 0.0f) {
        var_f20 = temp_f2 / 5.0f;
    } else {
        var_f20 = (0.0f - (D_80101000_name_81 - temp_f22)) / 5.0f;
    }
    for (i = 0; i < 5; i++, HuPrcVSleep()) {
        if (temp_f22 < D_80101000_name_81) {
            D_80101000_name_81 = D_80101000_name_81 - var_f20;
        } else {
            D_80101000_name_81 = var_f20 + D_80101000_name_81;
        }
    }

    D_80101000_name_81 = temp_f22;
    D_801031C8_name_81 = NULL;
    omDelPrcObj(NULL);
}

Process* func_800E7E80_name_81(f32 arg0) {
    Process* proc;
    f32* temp_v0_2;

    if (D_801031C8_name_81 != NULL) {
        omDelPrcObj(D_801031C8_name_81);
    }

    proc = omAddPrcObj(func_800E7D90_name_81, 1, 0, 0x40);
    D_801031C8_name_81 = proc;
    temp_v0_2 = HuMemMemoryAlloc(proc->heap, 0x10);
    D_801031C8_name_81->user_data = temp_v0_2;
    *temp_v0_2 = arg0;
    return D_801031C8_name_81;
}

static void func_800E7EF8_name_81(void) {
    Process* temp_v0;
    f32 temp_f2;
    f32 temp_f4;

    temp_f2 = (f32) (D_80100FF8_name_81->unk4 * D_80100FF8_name_81->unkC) / 240.0f;
    D_801031D0_name_81 = temp_f2;
    temp_f4 = (f32) (D_80100FF8_name_81->unk0 * D_80100FF8_name_81->unk8) / 320.0f;
    if (temp_f2 < temp_f4) {
        D_801031D0_name_81 = temp_f4;
    }
    D_801031D4_name_81.x = D_80100FF8_name_81->unk18;
    D_801031D4_name_81.y = D_80100FF8_name_81->unk1C;
    D_801031D4_name_81.z = D_80100FF8_name_81->unk20;
    D_801031E0_name_81.x = D_80100FF8_name_81->unk24;
    D_801031E0_name_81.y = D_80100FF8_name_81->unk28;
    D_801031E0_name_81.z = D_80100FF8_name_81->unk2C;
    D_801031EC_name_81.x = D_80100FF8_name_81->unk30;
    D_801031EC_name_81.y = D_80100FF8_name_81->unk34;
    D_801031EC_name_81.z = D_80100FF8_name_81->unk38;
    D_801031F8_name_81.x = (f32) (D_801031D0_name_81 * 640.0f);
    D_801031F8_name_81.y = (f32) (D_801031D0_name_81 * 480.0f);
    D_801031F8_name_81.z = 511.0f;
    D_80104848_name_81[0] = 640.0f;
    D_80104848_name_81[1] = 480.0f;
    D_80104840_name_81.x = 159.5f;
    D_80104840_name_81.y = 119.5f;
    D_801031CC_name_81 = 1.0f;
    temp_v0 = omAddPrcObj(func_800E8194_name_81, 0x1001, 0, 0);
    D_801031C4_name_81 = temp_v0;
    omPrcSetStatBit(temp_v0, 0x80);
    D_801031C8_name_81 = 0;
    Hu3DCamSetPerspective(0, D_80100FF8_name_81->unk10, 10.0f, 200.0f);
    Hu3DCamSetPositionOrientation(0, &D_801031D4_name_81, &D_801031E0_name_81, &D_801031EC_name_81);
    Hu3DCamUpdateMtx(0);
}

void func_800E8110_name_81(void) {
    if (D_801031C4_name_81 != NULL) {
        omDelPrcObj(D_801031C4_name_81);
        D_801031C4_name_81 = NULL;
    }
    if (D_801031C8_name_81 != NULL) {
        omDelPrcObj(D_801031C8_name_81);
        D_801031C8_name_81 = NULL;
    }
}

static void func_800E8164_name_81(void) {
    func_800E8110_name_81();
}

void func_800E8180_name_81(f32 arg0, f32 arg1) {
    D_80101008_name_81 = arg0;
    D_80101004_name_81 = arg1;
}

void func_800E8194_name_81(void) {
    Vec sp10;
    s16 sp20[2];
    Vec sp28;
    Vec sp38;
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f2;

    while (1) {
        temp_f4 = HuVecDistance(&D_801031D4_name_81, &D_801031E0_name_81);
        var_f2 = D_80101004_name_81;
        if ((var_f2 == 0.0f) || (var_f0 = D_80101008_name_81, (var_f0 == 0.0f))) {
            var_f2 = temp_f4 + 1000.0f;
            var_f0 = var_f2 - 2000.0f;
        }
        if (var_f0 < 10.0f) {
            var_f0 = 10.0f;
        }
        Hu3DCamSetPerspective(0, D_80100FF8_name_81->unk10, var_f0, var_f2);
        Hu3DCamSetPositionOrientation(0, &D_801031D4_name_81, &D_801031E0_name_81, &D_801031EC_name_81);
        Hu3DCamUpdateMtx(0);

        sp38.x = ((((D_80104840_name_81.x - 160.0f) * D_801031D0_name_81 * -4.0f) + 640.0f) - D_80104848_name_81[0]) / D_801031CC_name_81;
        sp38.y = ((((D_80104840_name_81.y - 120.0f) * D_801031D0_name_81 * -4.0f) + 480.0f) - D_80104848_name_81[1]) / D_801031CC_name_81;
        sp38.z = 0.0f;

        temp_f2 = HuVecGetLength3F(&sp38) / 4.0f;

        if (temp_f2 <= 1.0f) {
            D_80102D30_name_81 &= 0xFFFD;
            D_80104848_name_81[0] = ((D_80104840_name_81.x - 160.0f) * D_801031D0_name_81 * -4.0f) + 640.0f;
            D_80104848_name_81[1] = ((D_80104840_name_81.y - 120.0f) * D_801031D0_name_81 * -4.0f) + 480.0f;
        } else {
            D_80102D30_name_81 |= 2;
            if ((D_80102D2C_name_81 >= 0.0f) && (D_80102D2C_name_81 < temp_f2)) {
                func_800D7828_name_81(&sp38);
                HuVecMulScalar(&sp38, D_80102D2C_name_81 * 4.0f, &sp38);
            }
            D_80104848_name_81[0] += sp38.x;
            D_80104848_name_81[1] = D_80104848_name_81[1] + sp38.y;
        }

        sp20[0] = D_80104848_name_81[0] / 4.0f;
        sp20[1] = D_80104848_name_81[1] / 4.0f;

        sp10.x = D_80104848_name_81[0] * D_80101000_name_81;
        sp10.y = D_80104848_name_81[1] * D_80101000_name_81;
        sp10.z = 511.5f;

        sp28.x = D_801031D0_name_81 * 640.0f * D_80101000_name_81;
        sp28.y = D_801031D0_name_81 * 480.0f * D_80101000_name_81;
        sp28.z = 511.0f;

        CameraViewportSet(0, &sp28, &sp10);
        MBDBackOffsetSet(-sp20[0] + 0xA0, -sp20[1] + 0x78);
        HuPrcVSleep();
    }
}

void func_800E856C_name_81(f32 arg0) {
    D_801031CC_name_81 = arg0;
}

f32 func_800E8578_name_81(void) {
    return D_801031CC_name_81;
}

u16 MBDCameraPos3DSet(Vec *arg0) {
    Vec sp10;
    f32 scale;
    f32 halfW;
    f32 halfH;
    Vec2f* temp;

    HuVecCopyXYZ(&sp10, arg0->x, arg0->y + 10.0f, arg0->z);
    Hu3DCam3DToScreen(0, &sp10, &D_80104840_name_81);

    temp = &D_80104840_name_81;

    halfW = 320.0f / (2.0f * D_801031D0_name_81);
    temp->x += halfW - (halfW / D_80101000_name_81);

    halfH = 240.0f / (2.0f * D_801031D0_name_81);
    D_80104840_name_81.y += halfH - (halfH / D_80101000_name_81);

    return MBDBackPosClamp(&D_80104840_name_81, D_801031D0_name_81);
}

u16 MBDCameraPos2DSet(Vec2f *arg0) {
    D_80104840_name_81.x = arg0->x / D_801031D0_name_81 + 160.0f;
    D_80104840_name_81.y = arg0->y / D_801031D0_name_81 + 120.0f;
    return MBDBackPosClamp(&D_80104840_name_81, D_801031D0_name_81);
}

void MBDCameraPos3DGet(Vec2f* arg0) {
    arg0->x = (D_80104840_name_81.x - 160.0f) * D_801031D0_name_81;
    arg0->y = (D_80104840_name_81.y - 120.0f) * D_801031D0_name_81;
}

void MBDCameraPos2DGet(Vec2f *arg0) {
    arg0->x = -((D_80104848_name_81[0] / 4.0f) - 160.0f);
    arg0->y = -((D_80104848_name_81[1] / 4.0f) - 120.0f);
}

void MBDCamera3Dto2D(Vec *arg0, Vec2f *arg1) {
    typedef struct UnkData {
        Vec2f vec;
        f32 unk_08;
        f32 unk_0C;
    } UnkData;

    UnkData sp10;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f6;

    Hu3DCam3DToScreen(0, arg0, &sp10.vec);
    temp_f6 = 2.0f * D_801031D0_name_81;
    temp_f2 = 320.0f / temp_f6;
    sp10.vec.x = (temp_f2 - (temp_f2 / D_80101000_name_81)) + sp10.vec.x;
    temp_f0 = 240.0f / temp_f6;
    sp10.vec.y = (temp_f0 - (temp_f0 / D_80101000_name_81)) + sp10.vec.y;
    sp10.vec.x = ((sp10.vec.x - 160.0f) * D_801031D0_name_81) + 160.0f;
    sp10.vec.y = ((sp10.vec.y - 120.0f) * D_801031D0_name_81) + 120.0f;
    sp10.unk_08 = (D_80104848_name_81[0] / 4.0f) - 160.0f;
    sp10.unk_0C = (D_80104848_name_81[1] / 4.0f) - 120.0f;
    arg1->x = sp10.vec.x + sp10.unk_08;
    arg1->y = sp10.vec.y + sp10.unk_0C;
}

void MBDBackTPLvlSet(u8 arg0) {
    D_80100FFC_name_81 = arg0;
}

void MBDBackInvertSet(s16 arg0) {
    if (arg0) {
        D_80102D30_name_81 |= 8;
    } else {
        D_80102D30_name_81 &= ~8;
    }
}

void MBDBackFlipSet(s16 arg0) {
    if (arg0) {
        D_80102D30_name_81 |= 0x10;
    } else {
        D_80102D30_name_81 &= ~0x10;
    }
}

void MBDCameraSpeedSet(f32 speed) {
    D_80102D2C_name_81 = speed;
}

f32 MBDCameraSpeedGet(void) {
    return D_80102D2C_name_81;
}

s32 func_800E88FC_name_81(void) {
    return D_80102D30_name_81 & 2;
}

void func_800E890C_name_81(Vec* arg0, s32 arg1) {
    f32 temp_f20;
    f32 temp_f22;

    func_800E5C20_name_81();
    func_800E5BE8_name_81();
    temp_f22 = MBDCameraSpeedGet();
    MBDCameraSpeedSet(-1.0f);
    temp_f20 = func_800E8578_name_81();
    func_800E856C_name_81(1.0f);
    func_800E5954_name_81();
    
    if (arg0 != NULL) {
        MBDCameraPos3DSet(arg0);
    }
    HuPrcVSleep();
    
    if (arg1 != 0) {
        func_800E5964_name_81();
    }
    
    func_800E856C_name_81(temp_f20);
    MBDCameraSpeedSet(temp_f22);
}

void func_800E89CC_name_81(void) {
    func_800E4F50_name_81(hvq_data_ROM_START);
}

void func_800E89EC_name_81(s32 arg0) {
    MBDBackCreate(arg0, 1);
    omDelPrcObj(D_801031C4_name_81);
    D_801031C4_name_81 = NULL;
}

void MBDCameraBackOffsetSet(s16 arg0, s16 arg1) {
    MBDBackOffsetSet(arg0, arg1);
}

void func_800E8A44_name_81(s16 arg0, s16 arg1) {
    D_80104840_name_81.x = (arg0 / D_801031D0_name_81) + 160.0f;
    D_80104840_name_81.y = (arg1 / D_801031D0_name_81) + 120.0f;
}

void func_800E8AB0_name_81(void) {
    UnkBoard7 *obj;
    Vec2f pos;
    f32 maxX, maxY;
    f32 x, y;
    s32 i;

    while (TRUE) {
        for (i = 0; i < ARRAY_COUNT(D_80104850_name_81); i++) {
            obj = &D_80104850_name_81[i];

            if (!(obj->unk_00 & 1)) {
                continue;
            }

            MBDCamera3Dto2D(&obj->pos, &pos);

            if (obj->unk_01 != 0) {
                func_80054904_main(obj->unk_02, 0, (D_80104848_name_81[0] / (f32)obj->unk_01) + pos.x, (D_80104848_name_81[1] / (f32)obj->unk_01) + pos.y);
            } else {
                func_80054904_main(obj->unk_02, 0, pos.x, pos.y);
            }
            
            func_80055458_main(obj->unk_02, 0, obj->unk_06);

            if (obj->vel.x != 0.0f) {
                maxX = MBDBackMaxXGet();
                obj->pos.x += obj->vel.x;
                if (obj->pos.x >= maxX) {
                    obj->pos.x -= 2.0f * maxX;
                }
                if (obj->pos.x <= -maxX) {
                    obj->pos.x += 2.0f * maxX;
                }
            }

            if (obj->vel.z != 0.0f) {
                maxY = MBDBackMaxYGet() * 1.5f;
                obj->pos.z += obj->vel.z;
                if (obj->pos.z >= maxY) {
                    obj->pos.z -= 2.0f * maxY;
                }
                if (obj->pos.z <= -maxY) {
                    obj->pos.z += 2.0f * maxY;
                }
            }

            if (obj->vel.y != 0.0f) {
                obj->pos.y += obj->vel.y;
            }

            if (D_8010105C_name_81 != 0) {
                HuSprAttrReset(obj->unk_02, 0, 0x8000);
            } else {
                HuSprAttrSet(obj->unk_02, 0, 0x8000);
            }
        }
        HuPrcVSleep();
    }
}

void func_800E8D10_name_81(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80104850_name_81); i++) {
        D_80104850_name_81[i].unk_00 = 0;
    }

    D_80105050_name_81 = 0;

    func_800E9200_name_81();
}

s32 func_800E8D54_name_81(s32 arg0, Vec *arg1) {
    UnkBoard7 *obj;
    Process *proc;
    void *data;
    s32 count;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80104850_name_81); i++) {
        obj = &D_80104850_name_81[i];
        if (obj->unk_00 & 1) {
            continue;
        }
    
        obj->unk_00 = 1;
        obj->unk_06 = 0x100;
        obj->unk_01 = 0;
    
        HuVecCopy3F(&obj->pos, arg1);
        HuVecCopyXYZ(&obj->vel, 0, 0, 0);
    
        obj->unk_02 = HuSprGrpCreate(1, 0);
    
        data = DataRead(arg0);
        obj->unk_04 = func_80055810_main(data);
        DataClose(data);
    
        func_80055024_main(obj->unk_02, 0, obj->unk_04, 0);
        func_800550F4_main(obj->unk_02, 0, 1);
        HuSprPriSet(obj->unk_02, 0, 0x8000);
        HuSprAttrSet(obj->unk_02, 0, 0x9000);
        func_800555E8_main(obj->unk_02, 0, 0x10, 0xC, 0x130, 0xE4);
    
        if (D_80105050_name_81 == 0) {
            proc = omAddPrcObj(func_800E8AB0_name_81, 0x1001, 0, 0);
            D_80101058_name_81 = proc;
            omPrcSetStatBit(proc, 0x80);
        }
        
        D_80105050_name_81++;
        return i;
    }
    return -1;
}

s32 func_800E8EE8_name_81(s32 arg0, Vec *arg1) {
    UnkBoard7 *unkBoard7;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80104850_name_81); i++) {
        unkBoard7 = &D_80104850_name_81[i];
        if (unkBoard7->unk_00 & 1) {
            continue;
        }

        unkBoard7->unk_00 = 3;
        unkBoard7->unk_06 = 0x100;
        unkBoard7->unk_01 = 0;

        HuVecCopy3F(&unkBoard7->pos, arg1);
        HuVecCopyXYZ(&unkBoard7->vel, 0, 0, 0);

        unkBoard7->unk_02 = HuSprGrpCreate(1, 0);

        func_80055024_main(unkBoard7->unk_02, 0,
                            D_80104850_name_81[arg0].unk_04, 0);
        func_800550F4_main(unkBoard7->unk_02, 0, 1);
        HuSprPriSet(unkBoard7->unk_02, 0, 0x8000);
        HuSprAttrSet(unkBoard7->unk_02, 0, 0x9000);
        func_800555E8_main(unkBoard7->unk_02, 0, 0x10, 0xC, 0x130, 0xE4);

        D_80105050_name_81++;
        return i;
    }
    return -1;
}

static void func_800E9030_name_81(s32 arg0) {
    UnkBoard7* temp_s0 = &D_80104850_name_81[arg0];

    if (temp_s0->unk_00 & 1) {
        if (!(temp_s0->unk_00 & 2)) {
            HuSprKill(temp_s0->unk_04);
        }
        HuSprGrpKill(temp_s0->unk_02);
        temp_s0->unk_00 = 0;
        D_80105050_name_81--;
        if (D_80105050_name_81 == 0) {
            omDelPrcObj(D_80101058_name_81);
            D_80101058_name_81 = NULL;
        }
    }
}

void func_800E90B4_name_81(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80104850_name_81); i++) {
        func_800E9030_name_81(i);
    }

    func_800E9230_name_81();
}

void func_800E90F4_name_81(s32 arg0, s8 arg1) {
    D_80104850_name_81[arg0].unk_01 = arg1;
}

void func_800E9108_name_81(s32 arg0, s16 arg1) {
    D_80104850_name_81[arg0].unk_06 = arg1;
}

void func_800E911C_name_81(s32 arg0, RGB* arg1) {
    func_80055420_main(D_80104850_name_81[arg0].unk_02, 0, arg1->r, arg1->g, arg1->b);
}

void func_800E9158_name_81(s32 arg0, Vec* arg1) {
    HuVecCopy3F(&D_80104850_name_81[arg0].vel, arg1);
}

void func_800E9180_name_81(void) {
    D_8010105C_name_81 = 1;
}

void func_800E9190_name_81(void) {
    D_8010105C_name_81 = 0;
}

void func_800E919C_name_81(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80105058_name_81); i++) {
        if (D_80105058_name_81[i] != NULL) {
            func_800D8F3C_name_81(D_80105058_name_81[i]);
            D_80105058_name_81[i] = NULL;
        }
    }
}

void func_800E9200_name_81(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80105058_name_81); i++) {
        D_80105058_name_81[i] = NULL;
    }
}

static void func_800E9230_name_81(void){
    func_800E919C_name_81();
}

#define BG_TEXEL(entry, off) (*(u16 *)((u8 *)(entry)->unk4 + (off)))
#define BG_TEX_SIZE (64 * 48 * 2)

void func_800E924C_name_81(s16 arg0) {
    OverlayBgEntry *entry;
    u16 color;
    u8 r, g, b;
    s32 lum;
    s32 gray;
    s32 i;
    u32 offset;

    switch (arg0) {
        case 0:
            func_800E890C_name_81(NULL, 0);
            break;

        case 1:
            for (i = 0; i < ARRAY_COUNT(D_80102D48_name_81); i++) {
                entry = &D_80102D48_name_81[i];
                if (entry->unk4 == NULL) {
                    continue;
                }

                for (offset = 0; offset < BG_TEX_SIZE; offset += 2) {
                    color = BG_TEXEL(entry, offset);
                    r = (((color >> 11) & 0x1F) * 8) + 4;
                    g = (((color >>  6) & 0x1F) * 8) + 4;
                    b = (((color >>  1) & 0x1F) * 8) + 4;

                    lum = (r * 0.299f) + (g * 0.587f) + (b * 0.114f);
                    if (lum > 255) {
                        lum = 255;
                    }
                    lum = (lum >> 3) & 0x1F;
                    gray = (lum << 11) + (lum << 6) + (lum << 1);
                    BG_TEXEL(entry, offset) = gray;
                }
            }
            break;
    }
}
