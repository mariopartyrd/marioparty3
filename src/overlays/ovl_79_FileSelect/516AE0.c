#include "common.h"

#define UNK_VALUE 0x91

typedef struct UnkFileSelect2 {
    s16 unk_00;
    u32 unk_04; //can be messageID or message pointer
    void* unk_08;
} UnkFileSelect2;
typedef struct UnkFileSelect {
    u8 unk_00;
    char unk_01[0x83];
} UnkFileSelect;

void func_8005A674_5B274(s32, s32, s32, s32);
void func_801076D0_518810_FileSelect(s32, u32);
s32 func_80108834_519974_FileSelect(void);
void func_8010AB1C_51BC5C_FileSelect(s32, u32);
void func_8010AB58_51BC98_FileSelect(s32, u32);
void func_8010AB60_51BCA0_FileSelect(s32, u32);
void func_80110FB0_5220F0_FileSelect(u32);
void func_801110F0_522230_FileSelect(u32);
s32 func_80111B14_522C54_FileSelect(s32);
void func_80019C00_1A800(s32);
void func_8005D294_5DE94(s16);
u32 func_80106AD8_517C18_FileSelect(u32);

extern u16 D_800D1244_D1E44;
extern u16 D_800D5558_D6158;
extern UnkFileSelect D_801142DC_52541C_FileSelect[3];
extern UnkFileSelect2 D_80114158_525298_FileSelect[];

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801059A0_516AE0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801059D0_516B10_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105BC0_516D00_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105BF0_516D30_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105C1C_516D5C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105CB0_516DF0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105CC4_516E04_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105CE0_516E20_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105D18_516E58_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105D70_516EB0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105DD8_516F18_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105E48_516F88_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105E7C_516FBC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105EC0_517000_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105EEC_51702C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105F24_517064_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105F54_517094_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105F84_5170C4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105FA0_5170E0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80105FBC_5170FC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106014_517154_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106044_517184_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106094_5171D4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801060CC_51720C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106100_517240_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106134_517274_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106168_5172A8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801061D4_517314_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106220_517360_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801062BC_5173FC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106344_517484_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801063F4_517534_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010642C_51756C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106450_517590_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106474_5175B4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801064DC_51761C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106550_517690_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801065B8_5176F8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010660C_51774C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106654_517794_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010669C_5177DC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801066DC_51781C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010671C_51785C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106760_5178A0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801067D0_517910_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106814_517954_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010684C_51798C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801068B0_5179F0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106950_517A90_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801069D8_517B18_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106A48_517B88_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106AAC_517BEC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106AD8_517C18_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106B40_517C80_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106D8C_517ECC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80106ED8_518018_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107040_518180_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801071E8_518328_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801072B4_5183F4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107380_5184C0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010744C_51858C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107490_5185D0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107574_5186B4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801075D8_518718_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107608_518748_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107670_5187B0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801076A0_5187E0_FileSelect);

void func_801076D0_518810_FileSelect(s32 arg0, u32 arg1) {
    u32 temp_v0;

    func_8005D294_5DE94(D_80114158_525298_FileSelect[arg0].unk_00);
    if (D_80114158_525298_FileSelect[arg0].unk_04 != 0) {
        func_80019C00_1A800((u32)D_80114158_525298_FileSelect[arg0].unk_04);
        D_80114158_525298_FileSelect[arg0].unk_04 = 0;
    }
    
    temp_v0 = func_80106AD8_517C18_FileSelect(arg1);
    //pointer check
    if (temp_v0 > 0x80000000U) {
        D_80114158_525298_FileSelect[arg0].unk_04 = temp_v0;
    }
    func_8005B43C_5C03C(D_80114158_525298_FileSelect[arg0].unk_00, temp_v0, -1, -1);
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010779C_5188DC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801077D8_518918_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107810_518950_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010782C_51896C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107880_5189C0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801078BC_5189FC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801078F4_518A34_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107AA8_518BE8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107C50_518D90_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107C84_518DC4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80107CF8_518E38_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801083AC_5194EC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108440_519580_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112A64_523BA4_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112A68_523BA8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010846C_5195AC_FileSelect);

s32 func_80108834_519974_FileSelect(void) {
    s32 i;
    s32 total;

    for (i = 0, total = 0; i < ARRAY_COUNT(D_801142DC_52541C_FileSelect); i++) {
        if (D_801142DC_52541C_FileSelect[i].unk_00 == UNK_VALUE) {
            total++;
        }
    }
    
    return total;
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108878_5199B8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801088DC_519A1C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108A94_519BD4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108C34_519D74_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108D74_519EB4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80108EB8_519FF8_FileSelect);

#define CLAMP_BELOW(val, limit) ((val) < (limit) ? (val) : 0)

#define DPAD_RIGHT 0x100
#define DPAD_LEFT 0x200
#define DPAD_DOWN 0x400
#define DPAD_UP 0x800

#define BUTTON_A 0x8000
#define BUTTON_B 0x4000

enum OptionsFileSelect {
    OPTION_FILE0 = 0,
    OPTION_FILE1 = 1,
    OPTION_FILE2 = 2,
    OPTION_FILES_END,
    OPTION_COPY = 3,
    OPTION_ERASE = 4,
    OPTION_FILES_NAME_BEGIN,
    OPTION_FILE0_NAME = 5,
    OPTION_FILE1_NAME = 6,
    OPTION_FILE2_NAME = 7,
    OPTION_MAX = 7,
};

//TODO: can the gotos be removed?
//main function for handling input when an option hasn't been select yet
u32 func_80109570_51A6B0_FileSelect(s32 arg0) {
    s32 temp_v0;
    u32 temp_v1;
    s32 animTimerAdjusted;
    s32 animTimer;
    u16 pressedInput;
    s32 cursorIndex;
    u32 selectedOption;
    s32 unkValue;

    animTimer = 0;
    
    if (arg0 < 0) {
        arg0 = 0;
    }
    
    selectedOption = arg0;
    cursorIndex = selectedOption;
    unkValue = UNK_VALUE;
    
    while (1) {
        pressedInput = D_800D1244_D1E44;
        temp_v0 = func_80111B14_522C54_FileSelect(0);
        if (temp_v0 != -1) {
            pressedInput |= temp_v0;
        }
        if (D_800D5558_D6158 & BUTTON_A) {
            switch (selectedOption) {
            case OPTION_FILE0:
                func_8005A674_5B274(0, 5, 0, 5);
                func_80110FB0_5220F0_FileSelect(selectedOption);
                break;
            case OPTION_FILE1:
                func_8005A674_5B274(0, 5, 0, 5);
                func_80110FB0_5220F0_FileSelect(selectedOption);
                break;
            case OPTION_FILE2:
                func_8005A674_5B274(0, 5, 0, 5);
                func_80110FB0_5220F0_FileSelect(selectedOption);
                break;
            case OPTION_COPY:
            case OPTION_ERASE:
            case OPTION_FILE0_NAME:
            case OPTION_FILE1_NAME:
            case OPTION_FILE2_NAME:
                break;
            default:
                goto checkIfCursorIndexChanged;
            }
            return selectedOption;
        }
        if ((D_800D5558_D6158 & BUTTON_B)) {
            if (selectedOption > OPTION_MAX)  {
                goto checkIfCursorIndexChanged;
            }
        }
        switch (selectedOption) {
        case OPTION_FILE0:
        case OPTION_FILE1:
        case OPTION_FILE2:
            temp_v1 = func_80108834_519974_FileSelect();
            if (pressedInput & (DPAD_LEFT | DPAD_RIGHT)) {
                func_801076D0_518810_FileSelect(4, 0x2A00);
                func_80110FB0_5220F0_FileSelect(selectedOption);
                cursorIndex = selectedOption + 1;
                if (pressedInput & DPAD_LEFT) {
                    cursorIndex = selectedOption - 1;
                    //if less than 0, wrap index back around to file index 2
                    if (cursorIndex < 0) {
                        cursorIndex = OPTION_FILE2;
                    }
                } else {
                    cursorIndex = CLAMP_BELOW(cursorIndex, OPTION_FILES_END);
                }
            } else if (pressedInput & (DPAD_UP | DPAD_DOWN)) {
                if (pressedInput & DPAD_UP) {
                    cursorIndex = OPTION_COPY;
                    if ((temp_v1 - 1) < (OPTION_FILES_END - 1)) {
                        func_801076D0_518810_FileSelect(4, 0x2A01);
                    } else {
                        func_801076D0_518810_FileSelect(4, 0x2A03);
                    }
                    func_80110FB0_5220F0_FileSelect(selectedOption);
                } else {
                    if (D_801142DC_52541C_FileSelect[cursorIndex].unk_00 == unkValue) {
                        cursorIndex = selectedOption + OPTION_FILES_NAME_BEGIN;
                        func_80110FB0_5220F0_FileSelect(selectedOption);
                    }
                }
            }
            break;
        case OPTION_COPY:
            temp_v1 = func_80108834_519974_FileSelect();
            if (pressedInput & (DPAD_LEFT | DPAD_RIGHT)) {
                if (temp_v1 == 0) {
                    func_801076D0_518810_FileSelect(4, 0x2A13);
                } else {
                    func_801076D0_518810_FileSelect(4, 0x2A07);
                }
                cursorIndex = OPTION_ERASE;
            }
            if (pressedInput & DPAD_DOWN) {
                cursorIndex = OPTION_FILE1;
                func_801076D0_518810_FileSelect(4, 0x2A00);
            }
            break;
        case OPTION_ERASE:
            temp_v1 = func_80108834_519974_FileSelect() ;
            if (pressedInput & (DPAD_LEFT | DPAD_RIGHT)) {
                cursorIndex = OPTION_FILES_END;
                if ((temp_v1 - 1) < 2) {
                    func_801076D0_518810_FileSelect(4, 0x2A01);
                } else {
                    func_801076D0_518810_FileSelect(4, 0x2A03);
                }
            }
            if (pressedInput & DPAD_DOWN) {
                cursorIndex = 2;
                func_801076D0_518810_FileSelect(4, 0x2A00);
            }
            break;
        case OPTION_FILE0_NAME:
        case OPTION_FILE1_NAME:
        case OPTION_FILE2_NAME:
            func_801076D0_518810_FileSelect(4, 0x2A11);
            if (pressedInput & DPAD_LEFT) {
                cursorIndex = selectedOption;
                do {
                    cursorIndex -= 1;
                    if (cursorIndex < OPTION_FILES_NAME_BEGIN) {
                        cursorIndex = 7;
                    }
                } while (D_801142DC_52541C_FileSelect[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
            } else {
                if (pressedInput & DPAD_RIGHT) {
                    cursorIndex = selectedOption;
                    do {
                        //if cursor goes over max, wrap around back to file 0 name
                        if (++cursorIndex > OPTION_MAX) {
                            cursorIndex = OPTION_FILE0_NAME;
                        }
                    } while (D_801142DC_52541C_FileSelect[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
                }
            }
            if (pressedInput & DPAD_UP) {
                cursorIndex = selectedOption - OPTION_FILES_NAME_BEGIN;
                func_801076D0_518810_FileSelect(4, 0x2A00);
            }
            break;
        }            
        
        checkIfCursorIndexChanged:
        if (selectedOption != cursorIndex) {
            //animate cursor to new position
            func_8010AB60_51BCA0_FileSelect(18, cursorIndex);
            selectedOption = cursorIndex;
            
            if (selectedOption < OPTION_FILES_END) {
                func_801110F0_522230_FileSelect(selectedOption);
            }
        }
        func_8010AB1C_51BC5C_FileSelect(18, selectedOption);
        
        animTimerAdjusted = (animTimer < 0) ? animTimer + 7 : animTimer;
        animTimerAdjusted = (animTimerAdjusted >> 3);
        func_8010AB58_51BC98_FileSelect(18, -animTimerAdjusted);

        animTimer = (animTimer < 20) ? animTimer + 1 : 0;
        
        HuPrcVSleep();
    }
    return selectedOption;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80109904_51AA44_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80109968_51AAA8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801099A8_51AAE8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80109B2C_51AC6C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112AE0_523C20_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112AE4_523C24_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112AE8_523C28_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010A028_51B168_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010A680_51B7C0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010A7D8_51B918_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010A978_51BAB8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112AF0_523C30_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010A9B4_51BAF4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010AB1C_51BC5C_FileSelect);

void func_8010AB58_51BC98_FileSelect(s32 arg0, u32 arg1) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010AB60_51BCA0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010AC58_51BD98_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B4D0_51C610_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B4FC_51C63C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B528_51C668_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B554_51C694_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B598_51C6D8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B5D4_51C714_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B684_51C7C4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B6F4_51C834_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B80C_51C94C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B18_523C58_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B24_523C64_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B30_523C70_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B3C_523C7C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B48_523C88_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B54_523C94_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B60_523CA0_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B6C_523CAC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B78_523CB8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B84_523CC4_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B90_523CD0_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112B9C_523CDC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BA8_523CE8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BB4_523CF4_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BC0_523D00_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BCC_523D0C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BD8_523D18_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BE4_523D24_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BF0_523D30_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112BFC_523D3C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C08_523D48_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C14_523D54_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C20_523D60_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C2C_523D6C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C38_523D78_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C44_523D84_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C50_523D90_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C5C_523D9C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C68_523DA8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C74_523DB4_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C80_523DC0_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C8C_523DCC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112C98_523DD8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112CA4_523DE4_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112CB0_523DF0_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112CBC_523DFC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112CC8_523E08_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112CE4_523E24_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D00_523E40_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D1C_523E5C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D38_523E78_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010B998_51CAD8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010BDC4_51CF04_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010BE14_51CF54_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010BE30_51CF70_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010C25C_51D39C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010C688_51D7C8_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D6C_523EAC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D7C_523EBC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D8C_523ECC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112D9C_523EDC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112DAC_523EEC_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112DBC_523EFC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010C9B4_51DAF4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010CCA8_51DDE8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010D13C_51E27C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010D660_51E7A0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010DD54_51EE94_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010DDC0_51EF00_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010DEEC_51F02C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010DF58_51F098_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010DFF4_51F134_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010E1B4_51F2F4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010E250_51F390_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010E740_51F880_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010E864_51F9A4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F10C_52024C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F12C_52026C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F168_5202A8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F5C8_520708_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F65C_52079C_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112DF8_523F38_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112E08_523F48_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F678_5207B8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F760_5208A0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F844_520984_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F874_5209B4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010F8A4_5209E4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010FBE0_520D20_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010FC58_520D98_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010FF48_521088_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8010FFA0_5210E0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801102F0_521430_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110320_521460_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801103A0_5214E0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801106FC_52183C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8011072C_52186C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801107AC_5218EC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110B4C_521C8C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110B7C_521CBC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110C84_521DC4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110CC0_521E00_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110D0C_521E4C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110E70_521FB0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110F04_522044_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80110FB0_5220F0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111004_522144_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801110F0_522230_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111144_522284_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8011132C_52246C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_8011139C_5224DC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801113E8_522528_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111660_5227A0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111790_5228D0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111944_522A84_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801119F4_522B34_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111A08_522B48_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111B14_522C54_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111C30_522D70_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111CBC_522DFC_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111E78_522FB8_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80111FFC_52313C_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112184_5232C4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801122B0_5233F0_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112494_5235D4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112508_523648_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112584_5236C4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801125E8_523728_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112630_523770_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112684_5237C4_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_801126C0_523800_FileSelect);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", func_80112758_523898_FileSelect);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_79_FileSelect/516AE0", D_80112E68_523FA8_FileSelect);
