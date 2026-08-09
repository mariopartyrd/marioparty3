#include "common.h"
#include "malloc.h"
#include "mallocblock.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04; // gid?
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA; // x center
    /* 0x0C */ s16 unkC; // y center
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char unk22[2];
} D_800CD1DC_CDDDC_Struct; // Size 0x24

extern D_800CD1DC_CDDDC_Struct* D_800CD1DC_CDDDC;
extern s16 D_8011B650_4828C0_mgmode;
extern s16 D_8011B652_4828C2_mgmode;
extern void* D_8011B654_4828C4_mgmode[3];
extern void* D_8011B660_4828D0_mgmode;
extern s16 D_8011A3E0_481650_mgmode;

s16 func_80116B20_47DD90_mgmode(void) {
    s16 sprGrp;
    s16 i;

    D_8011A3E0_481650_mgmode = func_8000B838_C438(0x12000E);
    sprGrp = InitEspriteSlot(D_8011A3E0_481650_mgmode, 0, 1);
    D_8011B650_4828C0_mgmode = sprGrp;
    for (i = 0; i < ARRAY_COUNT(D_8011B654_4828C4_mgmode); i++) {
        D_8011B654_4828C4_mgmode[i] = HuMemAllocTag(0x6000, 0x7918);
    }
    D_8011B660_4828D0_mgmode = HuSprGet(D_800CD1DC_CDDDC[sprGrp].unk04, 0)->unk_84->unk00->unk00;
    D_8011B652_4828C2_mgmode = 0;
    func_8000BB94_C794(sprGrp);
    return sprGrp;
}

void func_80116C18_47DE88_mgmode(s16 arg0) {
    u8** sprData;
    u8* palData;
    void* buf;

    sprData = DataRead(arg0 | 0x170000);
    palData = DataRead((arg0 + 1) | 0x170000);
    func_8006A370_6AF70(0xFF);
    func_80069E68_6AA68(palData);
    buf = HuMemMemoryAllocPerm(0xC00);
    func_800698E8_6A4E8(sprData, D_8011B654_4828C4_mgmode[D_8011B652_4828C2_mgmode], 0x80, buf);
    HuMemMemoryFreePerm(buf);
    DataClose(sprData);
    DataClose(palData);
    HuSprGet(D_800CD1DC_CDDDC[D_8011B650_4828C0_mgmode].unk04, 0)->unk_84->unk00->unk00 =
        D_8011B654_4828C4_mgmode[D_8011B652_4828C2_mgmode];
    D_8011B652_4828C2_mgmode++;
    if (D_8011B652_4828C2_mgmode >= ARRAY_COUNT(D_8011B654_4828C4_mgmode)) {
        D_8011B652_4828C2_mgmode = 0;
    }
    func_8000BB54_C754(D_8011B650_4828C0_mgmode);
}

void func_80116D4C_47DFBC_mgmode(void) {
    s16 i;

    if (D_8011A3E0_481650_mgmode != -1) {
        HuSprGet(D_800CD1DC_CDDDC[D_8011B650_4828C0_mgmode].unk04, 0)->unk_84->unk00->unk00 =
            D_8011B660_4828D0_mgmode;
        func_8000C184_CD84(D_8011B650_4828C0_mgmode);
        HuSprKill(D_8011A3E0_481650_mgmode);
        for (i = 0; i < ARRAY_COUNT(D_8011B654_4828C4_mgmode); i++) {
            HuMemFree(D_8011B654_4828C4_mgmode[i]);
        }
        D_8011A3E0_481650_mgmode = -1;
    }
}

typedef struct CamData {
    Vec rot;
    Vec center;
    f32 zoom;
    f32 unk_1C;
} CamData;

extern f32 D_8011B6A4_482914_mgmode;
extern Vec D_8011B898_482B08_mgmode;
extern CamData* D_8011B954_482BC4_mgmode;
extern s8 D_8011B958_482BC8_mgmode;

void func_80116E24_47E094_mgmode(s16 arg0) {
    CRot = D_8011B954_482BC4_mgmode[arg0].rot;
    D_8011B898_482B08_mgmode = CRot;
    
    Center = D_8011B954_482BC4_mgmode[arg0].center;
    CZoom = D_8011B954_482BC4_mgmode[arg0].zoom;
    
    D_8011B6A4_482914_mgmode = D_8011B954_482BC4_mgmode[arg0].unk_1C;
    D_8011B958_482BC8_mgmode = arg0;
}

#ifdef NON_MATCHING
void func_80116ED4_47E144_mgmode(s16 presetIdx, s16 duration, s16 easeType, void (*callback)(s16*)) {
    Vec rotDelta;                       /* sp10 */
    Vec centerDelta;                    /* sp20 */
    Vec rotStart;                       /* sp30 */
    Vec centerStart;                    /* sp40 */
    Vec rot;                            /* sp50 */
    Vec center;                         /* sp60 */
    s16 cbArg[24];                      /* sp70..sp9F (0x30 bytes) */
    Vec eye;                            /* spA0 */
    void (*cb)(s16*);                   /* s8 */
    f32 zoom;                           /* f22 */
    f32 zoomDelta;                      /* f24 */
    f32 zoomStart;                      /* f22_2 */
    f32 unkDelta;                       /* f28 */
    f32 unkStart;                       /* f26 */
    f64 mag;
    f64 diff;
    f64 rate;
    s16 i;
    f32 hundred;

    cb = callback;
    rot = D_8011B954_482BC4_mgmode[presetIdx].rot;
    center = D_8011B954_482BC4_mgmode[presetIdx].center;
    zoom = D_8011B954_482BC4_mgmode[presetIdx].zoom;

    eye.x = HuMathSin(rot.y) * HuMathCos(rot.x) * zoom + center.x;
    eye.y = -HuMathSin(rot.x) * zoom + center.y;
    eye.z = HuMathCos(rot.y) * HuMathCos(rot.x) * zoom + center.z;
    hundred = 100.0f;
    mag = hundred / zoom;
    center.x = eye.x + (center.x - eye.x) * mag;
    center.y = eye.y + (center.y - eye.y) * mag;
    center.z = eye.z + (center.z - eye.z) * mag;

    diff = rot.x - CRot.x;
    WRAP180(rotDelta.x, diff, rot.x, CRot.x);
    diff = rot.y - CRot.y;
    WRAP180(rotDelta.y, diff, rot.y, CRot.y);
    diff = rot.z - CRot.z;
    WRAP180(rotDelta.z, diff, rot.z, CRot.z);

    centerDelta.x = center.x - Center.x;
    centerDelta.y = center.y - Center.y;
    centerDelta.z = center.z - Center.z;
    zoomDelta = hundred - CZoom;
    unkDelta = D_8011B954_482BC4_mgmode[presetIdx].unk_1C - D_8011B6A4_482914_mgmode;
    cbArg[1] = duration;
    centerStart = Center;
    rotStart = CRot;
    zoomStart = CZoom;
    unkStart = D_8011B6A4_482914_mgmode;

    if (easeType == 1 || easeType == 2) {
        for (i = 0; i < duration; i++) {
            if (easeType != 2) {
                rate = HuMathSin(i * 90.0f / duration);
            } else if (i <= duration / 2) {
                rate = (1.0f - HuMathCos(i * 180.0f / duration)) * 0.5f;
            } else {
                rate = -HuMathCos(i * 180.0f / duration) * 0.5f + 0.5f;
            }
            D_8011B898_482B08_mgmode.x = CRot.x = rate * rotDelta.x + rotStart.x;
            D_8011B898_482B08_mgmode.y = CRot.y = rate * rotDelta.y + rotStart.y;
            D_8011B898_482B08_mgmode.z = CRot.z = rate * rotDelta.z + rotStart.z;
            Center.x = rate * centerDelta.x + centerStart.x;
            Center.y = rate * centerDelta.y + centerStart.y;
            Center.z = rate * centerDelta.z + centerStart.z;
            CZoom = rate * zoomDelta + zoomStart;
            D_8011B6A4_482914_mgmode = rate * unkDelta + unkStart;
            if (callback != (void (*)(s16*))-1) {
                cbArg[0] = i;
                cb(cbArg);
            }
            HuPrcVSleep();
        }
    } else {
        for (i = 0; i <= duration; i++) {
            rate = (1.0f / duration) * i;
            D_8011B898_482B08_mgmode.x = CRot.x = rate * rotDelta.x + rotStart.x;
            D_8011B898_482B08_mgmode.y = CRot.y = rate * rotDelta.y + rotStart.y;
            D_8011B898_482B08_mgmode.z = CRot.z = rate * rotDelta.z + rotStart.z;
            Center.x = rate * centerDelta.x + centerStart.x;
            Center.y = rate * centerDelta.y + centerStart.y;
            Center.z = rate * centerDelta.z + centerStart.z;
            CZoom = rate * zoomDelta + zoomStart;
            if (callback != (void (*)(s16*))-1) {
                cbArg[0] = i;
                cb(cbArg);
            }
            HuPrcVSleep();
        }
    }
    func_80116E24_47E094_mgmode(presetIdx);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80116ED4_47E144_mgmode);
#endif

#ifdef NON_MATCHING
void func_801177BC_47EA2C_mgmode(Vec* arg0, Vec* arg1) {
    f32 temp_f0;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;

    temp_f22 = arg0->x - arg1->x;
    temp_f28 = arg0->y - arg1->y;
    temp_f24 = arg0->z - arg1->z;
    CZoom = HuSqrtf((temp_f22 * temp_f22) + (temp_f28 * temp_f28) + (temp_f24 * temp_f24));
    temp_f0 = _atan2d(temp_f24, temp_f22);
    CRot.y = -(temp_f0 - 90.0f);
    temp_f26 = HuMathCos(-temp_f0);
    CRot.x = -_atan2d(temp_f28, (temp_f22 * temp_f26) + (temp_f24 * -HuMathSin(-temp_f0)));
    CRot.z = 0.0f;
    Center = *arg1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801177BC_47EA2C_mgmode);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801178E0_47EB50_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80117DD0_47F040_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801180A4_47F314_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801181F4_47F464_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_8011822C_47F49C_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_8011829C_47F50C_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801182A8_47F518_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801182B4_47F524_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801182C0_47F530_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801182DC_47F54C_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118624_47F894_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118678_47F8E8_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118888_47FAF8_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801188A4_47FB14_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801188BC_47FB2C_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_801189C4_47FC34_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118B8C_47FDFC_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118CD8_47FF48_mgmode);

INCLUDE_ASM("asm/nonmatchings/overlays/mgmode/47DD90", func_80118D0C_47FF7C_mgmode);
