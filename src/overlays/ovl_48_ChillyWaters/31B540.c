#include "ChillyWaters.h"

#define X_OFFSET 66
#define Y_OFFSET 44

typedef struct IceWork {
    /* 0x00 */ f32 unk0;       /* sprite X */
    /* 0x04 */ f32 unk4;       /* sprite Y */
    /* 0x08 */ s16 unk8;       /* sprite id  */
    /* 0x0A */ s16 unkA;       /* sprite group id */
    /* 0x0C */ u8 *imgData;    /* revealed-pixel buffer */
    /* 0x10 */ u8 *unk10;      /* original image data */
    /* 0x14 */ Process *unk14;
} IceWork; /* size 0x18 */

typedef struct unkfunc_801059D0 {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    void* imgData; // may or may not include palette data and form header, unsure
    u32 unk10;
    Process *unk14;
} unkfunc_801059D0;

typedef struct ESprite3 {
    u8 *rasterData; // is this actually correct?
    s16 unk4;
    s16 unk6;
} ESprite3; // unknown size

typedef struct ESprite2 {
    char unk_00[0x14];
    u16 unk_14;
    char unk_18[0x30];
    f32 unk_48;
    f32 unk_4C;
    char unk_50[0x34];
    ESprite3 **unk_84;
} ESprite2; // unknown size

typedef struct ESprite {
    char unk_00[8];
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    ESprite2 *unk_10[4]; // unknown size
} ESprite;               // unknown size

void func_80105A64_31B5D4_ChillyWaters(void);
void func_8010BCA4_3BF974_boardresult(void);
void func_800555E8_561E8(s16 group, s16 member, u16 arg2, u16 arg3, u16 arg4, u16 arg5);

void func_801059D0_31B540_ChillyWaters(s16 arg0, s16 arg1) {
    Process *process;
    unkfunc_801059D0 *temp_v0;

    process = omAddPrcObj(func_80105A64_31B5D4_ChillyWaters, 0x3F00, 0x1000, 0);
    temp_v0 = HuMemAllocTag(sizeof(unkfunc_801059D0), 0x7918);
    process->user_data = temp_v0;
    temp_v0->unk14 = process;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
}

void func_80105A64_31B5D4_ChillyWaters(void) {
    HuSprite *spr;
    HuSprite_Unk84_Unk00_Struct *img;
    u8 *src;
    u8 *dst;
    u8 *srcBase;
    s16 sprId;
    s16 grpId;
    s16 width;
    s16 height;
    s16 radius;
    s16 frame;
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    s32 size;
    f32 r2;
    IceWork *work = HuPrcCurrentGet()->user_data;
    u8 growth[] = {2, 2, 16, 6, 8, 6, 20, 4};
    s16 new_var;

    sprId = func_8000B838_C438(0xB004A);
    work->unk8 = sprId;
    grpId = HuSprGrpCreate(1, 0);
    work->unkA = grpId;
    func_80055024_55C24(grpId, 0, sprId, 0);
    func_80054904_55504(grpId, 0, work->unk0, work->unk4);
    HuSprAttrSet(grpId, 0, 0x5000);
    func_80055420_56020(grpId, 0, 0x20, 0xA0, 0x90);
    func_800555E8_561E8(grpId, 0, 0x10, 0xC, 0x130, 0xE4);

    spr = HuSprGet(grpId, 0);
    img = spr->unk_84->unk00;
    width = img->unk04;
    height = img->unk06;
    srcBase = (work->unk10 = img->unk00);

    work->imgData = HuMemAlloc((width * height) / 2);
    memset(work->imgData, 0, (width * height) / 2);
    spr->unk_84->unk00->unk00 = work->imgData;

    radius = 0;
    frame = 0;
    while (radius < width - X_OFFSET) {
        r2 = radius * radius;
        for (y = 0; y < height; y++) {
            src = srcBase + ((y * width) / 2);
            dst = work->imgData + ((y * width) / 2);
            new_var = y - Y_OFFSET;
            dy = new_var * new_var;
            for (x = 0; x < width; x += 2) {
                dx = x - X_OFFSET;
                if (dx * dx + dy < r2) {
                    *dst = *src;
                }
                src++;
                dst++;
            }
        }
        radius += growth[frame & (ARRAY_COUNT(growth)-1)];
        frame++;
        HuPrcSleep(2);
    }

    while (1) {
        HuPrcVSleep();
    }
}

const s32 pad4[] = {0,0};

void func_80105DB8_31B928_ChillyWaters(IceWork* arg0) {
    HuSprGet(arg0->unkA, 0)->unk_84->unk00->unk00 = arg0->unk10;
    HuSprGrpKill(arg0->unkA);
    HuSprKill(arg0->unk8);
    HuMemFree(arg0->imgData);
    HuMemFree(arg0);
    omDelPrcObj(arg0->unk14);
}

void func_80105E20_31B990_ChillyWaters(IceWork* arg0, f32 x, f32 y) {
    arg0->unk0 = x;
    arg0->unk4 = y;
    func_80054904_55504(arg0->unkA, 0, arg0->unk0, arg0->unk4);
}
