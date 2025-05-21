#include "common.h"

void func_80105AF0_3D72A0_name_58(omObjData*);
void func_80105C80_3D7430_name_58(void);
void func_80105BA4_3D7354_name_58(omObjData*);
void func_801059D0_3D7180_name_58(void);
void func_80105C14_3D73C4_name_58(omObjData*);

/* .bss */
extern Process* D_80105F10_3D76C0_name_58;

/* .data */
s32 D_80105F00_3D76B0_name_58 = 0;
s32 D_80105F04_3D76B4_name_58 = 0;

void func_801059D0_3D7180_name_58(void) {
    Hu3DCamInit(1);
    omInitObjMan(0x10, 4);
    D_800D6A58_D7658 = 1;
    
    if (D_80105F00_3D76B0_name_58 == 0) {
        GWContErrorSet();
        D_80105F10_3D76C0_name_58 = omAddPrcObj(func_80105C80_3D7430_name_58, 0xAU, 0, 0);
        omAddObj(0x3E8, 0U, 0U, -1, func_80105AF0_3D72A0_name_58);
    } else {
        D_80105F10_3D76C0_name_58 = omAddPrcObj(func_80105C80_3D7430_name_58, 0xAU, 0, 0);
        omAddObj(0x3E8, 0U, 0U, -1, func_80105AF0_3D72A0_name_58);
        omAddObj(0xA, 0U, 0U, -1, func_80105C14_3D73C4_name_58);
    }
}

void func_80105AAC_3D725C_name_58(void) {
    D_80105F00_3D76B0_name_58 = 0;
    func_801059D0_3D7180_name_58();
}

void func_80105ACC_3D727C_name_58(void) {
    D_80105F00_3D76B0_name_58 = 1;
    func_801059D0_3D7180_name_58();
}

void func_80105AF0_3D72A0_name_58(omObjData* arg0) {
    if (((D_800D530C_D5F0C != 0) || (D_80105F04_3D76B4_name_58 != 0)) && (WipeStatGet() == 0)) {
        WipeColorSet(0U, 0U, 0U);
        WipeCreateOut(0xB, 9);
        arg0->func = &func_80105BA4_3D7354_name_58;
        
        if ((D_800D530C_D5F0C != 0) && (WipeStatGet() == 0)) {
            WipeColorSet(0U, 0U, 0U);
            WipeCreateOut(0xB, 9);
            arg0->func = &func_80105BA4_3D7354_name_58;
        }
    }
}

void func_80105BA4_3D7354_name_58(omObjData* arg0) {
    if (WipeStatGet() == 0) {
        func_8005F524_60124();
        if (D_80105F00_3D76B0_name_58 != 0) {
            omOvlGotoEx(name_7A, 2, 0x92);
            return;
        }
        omOvlCallEx(name_7A, 2, 0x92);
        omOvlHisChg(1, name_7A, 2, 0x92);
    }
}

void func_80105C14_3D73C4_name_58(omObjData* arg0) {
    s32 temp_v0;

    if (WipeStatGet() == 0) {
        temp_v0 = GWContErrorGet();
        if ((temp_v0 == 1) && (CheckControllerRead(0) != 0) && (D_800D5558_D6158[0] & 0x1000)) {
            D_80105F04_3D76B4_name_58 = temp_v0;
        }
    }
}

void func_80105C80_3D7430_name_58(void) {
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_s0_3;
    u16 temp_v0_2;
    u16 temp_v0_4;

    temp_v0 = func_8000B838_C438(0x00110000);
    temp_v0_2 = InitEspriteSlot(temp_v0, 0, 1);
    func_8000BBD4_C7D4(temp_v0_2, 0xA0, 0x78);
    func_8000BB54_C754(temp_v0_2);
    func_8000BCC8_C8C8(temp_v0_2, 0xFFFF);
    WipeCreateIn(0xB, 30);

    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(37);
    WipeCreateOut(0xB, 9);
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    func_8000C184_CD84(temp_v0_2);
    func_80055670_56270(temp_v0);
    HuPrcSleep(9);
    temp_v0_3 = func_8000B838_C438(0x00110001);
    temp_v0_4 = InitEspriteSlot(temp_v0_3, 0, 1);
    func_8000BBD4_C7D4(temp_v0_4, 0xA0, 0x78);
    func_8000BB54_C754(temp_v0_4);
    func_8000BCC8_C8C8(temp_v0_4, 0xFFFF);
    WipeCreateIn(0xB, 9);
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(37);
    WipeCreateOut(0xB, 9);
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    func_8000C184_CD84(temp_v0_4);
    func_80055670_56270(temp_v0_3);
    HuPrcSleep(9);
    temp_s0_3 = InitEspriteSlot(func_8000B838_C438(0x110002), 0, 1);
    func_8000BBD4_C7D4(temp_s0_3, 0xA0, 0x78);
    func_8000BB54_C754(temp_s0_3);
    func_8000BCC8_C8C8(temp_s0_3, 0xFFFF);
    WipeCreateIn(0xB, 9);
    
    while (WipeStatGet() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(37);
    D_800D530C_D5F0C = 1;
    
    while (1) {
        HuPrcVSleep();
    }
}
