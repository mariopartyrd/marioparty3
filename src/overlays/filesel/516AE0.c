#include "common.h"
#include "game/vibrator.h"

#define UNK_VALUE 0x91

typedef struct UnkFileSelect2 {
    s16 unk_00;
    u32 unk_04; //can be messageID or message pointer
    void* unk_08;
} UnkFileSelect2;

typedef struct UnkFileSelect {
    u8 unk_00;
    u8 unk_01[0xB];
    char unk_0C[0x78];
} UnkFileSelect; //sizeof 0x84

void func_801076D0_518810_filesel(s32, u32);
s32 func_80108834_519974_filesel(void);
void func_8010AB1C_51BC5C_filesel(s32, u32);
void func_8010AB58_51BC98_filesel(s32, u32);
void func_8010AB60_51BCA0_filesel(s32, u32);
void func_80110FB0_5220F0_filesel(u32);
void func_801110F0_522230_filesel(u32);
s32 func_80111B14_522C54_filesel(s32);
void func_80019C00_1A800(s32);
u32 func_80106AD8_517C18_filesel(u32);
s32 func_8010AC58_51BD98_filesel(s32);
s32 func_80112494_5235D4_filesel(s32, u8*);

extern u16 D_800D1244_D1E44;
extern UnkFileSelect D_801142DC_52541C_filesel[3];
extern UnkFileSelect2 D_80114158_525298_filesel[];

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801059A0_516AE0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801059D0_516B10_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105BC0_516D00_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105BF0_516D30_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105C1C_516D5C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CB0_516DF0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CC4_516E04_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CE0_516E20_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105D18_516E58_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105D70_516EB0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105DD8_516F18_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105E48_516F88_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105E7C_516FBC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105EC0_517000_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105EEC_51702C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F24_517064_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F54_517094_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F84_5170C4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105FA0_5170E0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105FBC_5170FC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106014_517154_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106044_517184_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106094_5171D4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801060CC_51720C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106100_517240_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106134_517274_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106168_5172A8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801061D4_517314_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106220_517360_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801062BC_5173FC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106344_517484_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801063F4_517534_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010642C_51756C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106450_517590_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106474_5175B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801064DC_51761C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106550_517690_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801065B8_5176F8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010660C_51774C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106654_517794_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010669C_5177DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801066DC_51781C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010671C_51785C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106760_5178A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801067D0_517910_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106814_517954_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010684C_51798C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801068B0_5179F0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106950_517A90_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801069D8_517B18_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106A48_517B88_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106AAC_517BEC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106AD8_517C18_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106B40_517C80_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106D8C_517ECC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106ED8_518018_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107040_518180_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801071E8_518328_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801072B4_5183F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107380_5184C0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010744C_51858C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107490_5185D0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107574_5186B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801075D8_518718_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107608_518748_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107670_5187B0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801076A0_5187E0_filesel);

void func_801076D0_518810_filesel(s32 arg0, u32 arg1) {
    u32 temp_v0;

    func_8005D294_5DE94(D_80114158_525298_filesel[arg0].unk_00);
    if (D_80114158_525298_filesel[arg0].unk_04 != 0) {
        func_80019C00_1A800((u32)D_80114158_525298_filesel[arg0].unk_04);
        D_80114158_525298_filesel[arg0].unk_04 = 0;
    }
    
    temp_v0 = func_80106AD8_517C18_filesel(arg1);
    //pointer check
    if (temp_v0 > 0x80000000U) {
        D_80114158_525298_filesel[arg0].unk_04 = temp_v0;
    }
    func_8005B43C_5C03C(D_80114158_525298_filesel[arg0].unk_00, temp_v0, -1, -1);
}


INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010779C_5188DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801077D8_518918_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107810_518950_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010782C_51896C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107880_5189C0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801078BC_5189FC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801078F4_518A34_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107AA8_518BE8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107C50_518D90_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107C84_518DC4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107CF8_518E38_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801083AC_5194EC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108440_519580_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112A64_523BA4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112A68_523BA8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010846C_5195AC_filesel);

s32 func_80108834_519974_filesel(void) {
    s32 i;
    s32 total;

    for (i = 0, total = 0; i < ARRAY_COUNT(D_801142DC_52541C_filesel); i++) {
        if (D_801142DC_52541C_filesel[i].unk_00 == UNK_VALUE) {
            total++;
        }
    }
    
    return total;
}


INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108878_5199B8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801088DC_519A1C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108A94_519BD4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108C34_519D74_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108D74_519EB4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108EB8_519FF8_filesel);

#define CLAMP_BELOW(val, limit) ((val) < (limit) ? (val) : 0)

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
u32 func_80109570_51A6B0_filesel(s32 arg0) {
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
        temp_v0 = func_80111B14_522C54_filesel(0);
        if (temp_v0 != -1) {
            pressedInput |= temp_v0;
        }
        if (D_800D5558_D6158[0] & A_BUTTON) {
            switch (selectedOption) {
            case OPTION_FILE0:
                RepeatVibrator(0, 5, 0, 5);
                func_80110FB0_5220F0_filesel(selectedOption);
                break;
            case OPTION_FILE1:
                RepeatVibrator(0, 5, 0, 5);
                func_80110FB0_5220F0_filesel(selectedOption);
                break;
            case OPTION_FILE2:
                RepeatVibrator(0, 5, 0, 5);
                func_80110FB0_5220F0_filesel(selectedOption);
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
        if ((D_800D5558_D6158[0] & B_BUTTON)) {
            if (selectedOption > OPTION_MAX)  {
                goto checkIfCursorIndexChanged;
            }
        }
        switch (selectedOption) {
        case OPTION_FILE0:
        case OPTION_FILE1:
        case OPTION_FILE2:
            temp_v1 = func_80108834_519974_filesel();
            if (pressedInput & (L_JPAD | R_JPAD)) {
                func_801076D0_518810_filesel(4, 0x2A00);
                func_80110FB0_5220F0_filesel(selectedOption);
                cursorIndex = selectedOption + 1;
                if (pressedInput & L_JPAD) {
                    cursorIndex = selectedOption - 1;
                    //if less than 0, wrap index back around to file index 2
                    if (cursorIndex < 0) {
                        cursorIndex = OPTION_FILE2;
                    }
                } else {
                    cursorIndex = CLAMP_BELOW(cursorIndex, OPTION_FILES_END);
                }
            } else if (pressedInput & (U_JPAD | D_JPAD)) {
                if (pressedInput & U_JPAD) {
                    cursorIndex = OPTION_COPY;
                    if ((temp_v1 - 1) < (OPTION_FILES_END - 1)) {
                        func_801076D0_518810_filesel(4, 0x2A01);
                    } else {
                        func_801076D0_518810_filesel(4, 0x2A03);
                    }
                    func_80110FB0_5220F0_filesel(selectedOption);
                } else {
                    if (D_801142DC_52541C_filesel[cursorIndex].unk_00 == unkValue) {
                        cursorIndex = selectedOption + OPTION_FILES_NAME_BEGIN;
                        func_80110FB0_5220F0_filesel(selectedOption);
                    }
                }
            }
            break;
        case OPTION_COPY:
            temp_v1 = func_80108834_519974_filesel();
            if (pressedInput & (L_JPAD | R_JPAD)) {
                if (temp_v1 == 0) {
                    func_801076D0_518810_filesel(4, 0x2A13);
                } else {
                    func_801076D0_518810_filesel(4, 0x2A07);
                }
                cursorIndex = OPTION_ERASE;
            }
            if (pressedInput & D_JPAD) {
                cursorIndex = OPTION_FILE1;
                func_801076D0_518810_filesel(4, 0x2A00);
            }
            break;
        case OPTION_ERASE:
            temp_v1 = func_80108834_519974_filesel() ;
            if (pressedInput & (L_JPAD | R_JPAD)) {
                cursorIndex = OPTION_FILES_END;
                if ((temp_v1 - 1) < 2) {
                    func_801076D0_518810_filesel(4, 0x2A01);
                } else {
                    func_801076D0_518810_filesel(4, 0x2A03);
                }
            }
            if (pressedInput & D_JPAD) {
                cursorIndex = 2;
                func_801076D0_518810_filesel(4, 0x2A00);
            }
            break;
        case OPTION_FILE0_NAME:
        case OPTION_FILE1_NAME:
        case OPTION_FILE2_NAME:
            func_801076D0_518810_filesel(4, 0x2A11);
            if (pressedInput & L_JPAD) {
                cursorIndex = selectedOption;
                do {
                    cursorIndex -= 1;
                    if (cursorIndex < OPTION_FILES_NAME_BEGIN) {
                        cursorIndex = 7;
                    }
                } while (D_801142DC_52541C_filesel[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
            } else {
                if (pressedInput & R_JPAD) {
                    cursorIndex = selectedOption;
                    do {
                        //if cursor goes over max, wrap around back to file 0 name
                        if (++cursorIndex > OPTION_MAX) {
                            cursorIndex = OPTION_FILE0_NAME;
                        }
                    } while (D_801142DC_52541C_filesel[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
                }
            }
            if (pressedInput & U_JPAD) {
                cursorIndex = selectedOption - OPTION_FILES_NAME_BEGIN;
                func_801076D0_518810_filesel(4, 0x2A00);
            }
            break;
        }            
        
        checkIfCursorIndexChanged:
        if (selectedOption != cursorIndex) {
            //animate cursor to new position
            func_8010AB60_51BCA0_filesel(18, cursorIndex);
            selectedOption = cursorIndex;
            
            if (selectedOption < OPTION_FILES_END) {
                func_801110F0_522230_filesel(selectedOption);
            }
        }
        func_8010AB1C_51BC5C_filesel(18, selectedOption);
        
        animTimerAdjusted = (animTimer < 0) ? animTimer + 7 : animTimer;
        animTimerAdjusted = (animTimerAdjusted >> 3);
        func_8010AB58_51BC98_filesel(18, -animTimerAdjusted);

        animTimer = (animTimer < 20) ? animTimer + 1 : 0;
        
        HuPrcVSleep();
    }
    return selectedOption;
}

s32 func_80109904_51AA44_filesel(s32 arg0) {
    u8 buf[32]; //TODO: figure out correct type of this
    s32 temp_s0;

    bzero(&buf, sizeof(buf));
    func_80112494_5235D4_filesel(arg0, buf);
    HuPrcSleep(3);
    func_801076D0_518810_filesel(4, 0x2A11);
    temp_s0 = func_8010AC58_51BD98_filesel(arg0);
    HuPrcSleep(3);
    return temp_s0;
}

s32 func_80109968_51AAA8_filesel(s32 arg0) {
    s32 temp_s0;

    HuPrcSleep(3);
    temp_s0 = func_8010AC58_51BD98_filesel(arg0);
    HuPrcSleep(3);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801099A8_51AAE8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80109B2C_51AC6C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE0_523C20_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE4_523C24_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE8_523C28_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A028_51B168_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A680_51B7C0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A7D8_51B918_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A978_51BAB8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AF0_523C30_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A9B4_51BAF4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AB1C_51BC5C_filesel);

void func_8010AB58_51BC98_filesel(s32 arg0, u32 arg1) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AB60_51BCA0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AC58_51BD98_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B4D0_51C610_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B4FC_51C63C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B528_51C668_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B554_51C694_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B598_51C6D8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B5D4_51C714_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B684_51C7C4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B6F4_51C834_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B80C_51C94C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B18_523C58_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B24_523C64_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B30_523C70_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B3C_523C7C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B48_523C88_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B54_523C94_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B60_523CA0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B6C_523CAC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B78_523CB8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B84_523CC4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B90_523CD0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B9C_523CDC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BA8_523CE8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BB4_523CF4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BC0_523D00_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BCC_523D0C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BD8_523D18_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BE4_523D24_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BF0_523D30_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BFC_523D3C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C08_523D48_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C14_523D54_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C20_523D60_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C2C_523D6C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C38_523D78_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C44_523D84_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C50_523D90_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C5C_523D9C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C68_523DA8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C74_523DB4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C80_523DC0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C8C_523DCC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C98_523DD8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CA4_523DE4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CB0_523DF0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CBC_523DFC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CC8_523E08_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CE4_523E24_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D00_523E40_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D1C_523E5C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D38_523E78_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B998_51CAD8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BDC4_51CF04_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BE14_51CF54_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BE30_51CF70_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C25C_51D39C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C688_51D7C8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D6C_523EAC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D7C_523EBC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D8C_523ECC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D9C_523EDC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DAC_523EEC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DBC_523EFC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C9B4_51DAF4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010CCA8_51DDE8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010D13C_51E27C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010D660_51E7A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DD54_51EE94_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DDC0_51EF00_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DEEC_51F02C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DF58_51F098_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DFF4_51F134_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E1B4_51F2F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E250_51F390_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E740_51F880_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E864_51F9A4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F10C_52024C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F12C_52026C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F168_5202A8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F5C8_520708_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F65C_52079C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DF8_523F38_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112E08_523F48_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F678_5207B8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F760_5208A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F844_520984_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F874_5209B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F8A4_5209E4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FBE0_520D20_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FC58_520D98_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FF48_521088_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FFA0_5210E0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801102F0_521430_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110320_521460_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801103A0_5214E0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801106FC_52183C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011072C_52186C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801107AC_5218EC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110B4C_521C8C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110B7C_521CBC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110C84_521DC4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110CC0_521E00_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110D0C_521E4C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110E70_521FB0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110F04_522044_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110FB0_5220F0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111004_522144_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801110F0_522230_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111144_522284_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011132C_52246C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011139C_5224DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801113E8_522528_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111660_5227A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111790_5228D0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111944_522A84_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801119F4_522B34_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111A08_522B48_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111B14_522C54_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111C30_522D70_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111CBC_522DFC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111E78_522FB8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111FFC_52313C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112184_5232C4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801122B0_5233F0_filesel);

s32 func_80112494_5235D4_filesel(s32 arg0, u8* arg1) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_801142DC_52541C_filesel[arg0].unk_01[i] = arg1[i];
    }
    
    //terminate string
    D_801142DC_52541C_filesel[arg0].unk_01[i] = '\0';
    D_801142DC_52541C_filesel[arg0].unk_01[i+1] = '\0';
    return i;
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112508_523648_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112584_5236C4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801125E8_523728_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112630_523770_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112684_5237C4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801126C0_523800_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112758_523898_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112E68_523FA8_filesel);
