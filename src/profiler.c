#include "common.h"
#include "PR/os.h"

#define PROF_MAX_SAMPLES 10

typedef struct
{
    s16 unk0;
    s16 unk2;
} ProfTaskConfig;

typedef struct
{
    s32 unk0;
    s16 sampleCount;
    s32 unk8;
    s32 colors[PROF_MAX_SAMPLES];               // 000C
    u32 startTimes[PROF_MAX_SAMPLES];           // 0034
    u32 endTimes[PROF_MAX_SAMPLES];        
} ProfSampleBuff;

OSTime func_8004D638_4E238(ProfSampleBuff * buffer, s16 sampleIdx);

extern u8 D_8008F1C0_8FDC0;
extern ProfTaskConfig D_800B246E_B306E;
extern ProfTaskConfig D_800B24F6_B30F6;
extern OSMesgQueue D_800B2578_B3178;
extern void* D_800B2590_B3190;
extern OSMesg D_800B25A0_B31A0;
extern s32 D_800B25A4_B31A4;
extern u8 * D_800B25A8_B31A8;
extern s32 D_800B25AC_B31AC;
extern s32 D_800B25B0_B31B0;
extern s32 D_800B25B4_B31B4;
extern s32 D_800B25B8_B31B8;
extern s32 D_800B25BC_B31BC;
extern s32 D_800B25C4_B31C4;
extern u8 * D_800B25D0_B31D0;
extern s32 D_800B25D4_B31D4;
extern s32 D_800B25DC_B31DC;
extern OSMesgQueue* D_800B25E0_B31E0;
extern s32 D_800B25E4_B31E4;
extern Gfx D_800B25F0_B31F0[];
extern s32 * gUCodeAddresses;
extern long long int rspbootTextStart[];

void HuProfInit(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    D_800B246E_B306E.unk0 = arg1;
    D_800B246E_B306E.unk2 = arg2;
    D_800B24F6_B30F6.unk0 = arg3;
    D_800B24F6_B30F6.unk2 = arg4;
    D_800B25E0_B31E0 = &D_800B2578_B3178;
    D_800B25E4_B31E4 = 0;
    D_800B25A0_B31A0 = (OSMesg)1;
    D_800B25A4_B31A4 = 2;
    D_800B25A8_B31A8 = (u8*)&rspbootTextStart;
    D_800B25AC_B31AC = (u32)&D_8008F1C0_8FDC0 - (u32)&rspbootTextStart;
    D_800B25B4_B31B4 = 0x1000;
    D_800B25BC_B31BC = 0x800;
    D_800B25C4_B31C4 = 0x400;
    D_800B25D0_B31D0 = (u8*)&D_800B25F0_B31F0;
    D_800B25D4_B31D4 = 0;
    D_800B25DC_B31DC = 0xC00;
    D_800B25B0_B31B0 = gUCodeAddresses[arg0 * 2];
    D_800B25B8_B31B8 = gUCodeAddresses[(arg0 * 2) | 1];
    osCreateMesgQueue(&D_800B2578_B3178, &D_800B2590_B3190, 3);
}

extern u32 D_800B2574_B3174;
extern OSMesgQueue D_800B2578_B3178;

void HuProfRecordAwaitRsp(void) {
    D_800B2574_B3174 = (u32) osGetTime();
    while (osRecvMesg(&D_800B2578_B3178, NULL, 0) == 0);
}

s16 HuProfRecordSample(ProfSampleBuff * buffer, s32 red, s32 green, u32 blue) {

    if (buffer->sampleCount >= PROF_MAX_SAMPLES) {
        return -1;
    }
    
    buffer->startTimes[buffer->sampleCount] = (u32) osGetTime();
    buffer->colors[buffer->sampleCount] = (((((red << 8) & 0xF800) | ((green * 8) & 0x7C0) | ((blue >> 2) & 0x3E)) | 1) << 0x10)
        | (((red << 8) & 0xF800) | ((green * 8) & 0x7C0) | ((blue >> 2) & 0x3E) | 1);
    
    return buffer->sampleCount++;
}

OSTime func_8004D638_4E238(ProfSampleBuff * buffer, s16 sampleIdx) {
    
    if (sampleIdx >= 0) {
        buffer->endTimes[sampleIdx] = (u32) osGetTime();
    }
    
    return buffer->endTimes[sampleIdx] - buffer->startTimes[sampleIdx];
}

extern ProfSampleBuff D_800B2468_B3068;

s16 func_8004D6AC_4E2AC(u8 red, u8 green, u8 blue) {
    return HuProfRecordSample(&D_800B2468_B3068, red, green, blue);
}

void func_8004D6E8_4E2E8(s16 sampleIdx) {
    func_8004D638_4E238(&D_800B2468_B3068, sampleIdx);
}


extern ProfSampleBuff D_800B24F0_B30F0;

s16 func_8004D710_4E310(u8 arg0, u8 arg1, u8 arg2) {
    s16 temp_s0;
    u32 temp_s3;

    temp_s3 = osSetIntMask(1U);
    temp_s0 = HuProfRecordSample(&D_800B24F0_B30F0, arg0, arg1, arg2);
    osSetIntMask(temp_s3);
    return temp_s0;
}

void func_8004D788_4E388(s16 sampleIdx) {
    u32 temp_s1;

    temp_s1 = osSetIntMask(1U);
    func_8004D638_4E238(&D_800B24F0_B30F0, sampleIdx);
    osSetIntMask(temp_s1);
}

extern s16 D_800B246C_B306C;

void func_8004D7D8_4E3D8(void) {
    u32 temp_v0;

    D_800B246C_B306C = 0;
    temp_v0 = osSetIntMask(1U);
    D_800B2468_B3068.unk0 = D_800B2574_B3174;
    osSetIntMask(temp_v0);
}

extern ProfSampleBuff D_800B23E0_B2FE0;

void func_8004D814_4E414(void) {
    u32 temp_s0;

    temp_s0 = osSetIntMask(1U);
    bcopy(&D_800B2468_B3068, &D_800B23E0_B2FE0, sizeof(ProfSampleBuff));
    osSetIntMask(temp_s0);
}

extern s16 D_800B24F4_B30F4;

void func_8004D85C_4E45C(void) {
    //D_800B24F0_B30F0.sampleCount = 0;
    D_800B24F4_B30F4 = 0;
    D_800B24F0_B30F0.unk0 = D_800B2574_B3174;
}

void func_8004D878_4E478(void) {
}

// profiler rendering code was stubbed out
Gfx * func_8004D880_4E480(ProfSampleBuff * arg1, Gfx * arg2, s32 arg3) {
    return arg2;
}

extern s32 D_800B25C0_B31C0;
extern s32 D_800B25C8_B31C8;
extern s32 D_800B25CC_B31CC;
extern s32 D_800B25D8_B31D8;
extern Gfx D_800B25F0_B31F0[];
extern s32 D_800B25F4_B31F4;
extern s32 D_800B25FC_B31FC;
extern s32 D_800B2604_B3204;
extern OSMesgQueue D_800CC3C0_CCFC0;
extern s32 gThread3Stack;
extern s32 gThreadOutStack;
extern s32 gThreadOutStackSize;
extern s32 gThreadYieldStack;

void func_8004D888_4E488(void) {
    Gfx* gfx = D_800B25F0_B31F0;

    D_800B25C0_B31C0 = gThread3Stack;
    D_800B25D8_B31D8 = gThreadYieldStack;
    D_800B25C8_B31C8 = gThreadOutStack;
    D_800B25CC_B31CC = gThreadOutStackSize;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gfx = func_8004D880_4E480(&D_800B23E0_B2FE0, gfx, 0);
    gfx = func_8004D880_4E480(&D_800B24F0_B30F0, gfx, 2);
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    osJamMesg(&D_800CC3C0_CCFC0, &D_800B25A0_B31A0, 0);
}
