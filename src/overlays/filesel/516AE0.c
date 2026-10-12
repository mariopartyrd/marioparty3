#include "common.h"
#include "game/vibrator.h"

#define UNK_VALUE 0x91

typedef struct UnkFileSelect2 {
    s16 unk_00;
    u32 unk_04; // can be messageID or message pointer
    void *unk_08;
} UnkFileSelect2;

typedef struct UnkFileSelect {
    u8 unk_00;
    u8 unk_01[0xB];
    char unk_0C[0x78];
} UnkFileSelect; // sizeof 0x84

void func_801076D0_filesel(s32, u32);
s32 func_80108834_filesel(void);
void func_8010AB1C_filesel(s32, u32);
void func_8010AB58_filesel(s32, u32);
void func_8010AB60_filesel(s32, u32);
void func_80110FB0_filesel(u32);
void func_801110F0_filesel(u32);
s32 func_80111B14_filesel(s32);
void func_80019C00_main(s32);
u32 func_80106AD8_filesel(u32);
s32 func_8010AC58_filesel(s32);
s32 func_80112494_filesel(s32, u8 *);

extern u16 D_800D1244_main;
extern UnkFileSelect D_801142DC_filesel[3];
extern UnkFileSelect2 D_80114158_filesel[];

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801059A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801059D0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105BC0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105BF0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105C1C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CB0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CC4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105CE0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105D18_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105D70_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105DD8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105E48_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105E7C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105EC0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105EEC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F24_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F54_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105F84_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105FA0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80105FBC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106014_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106044_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106094_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801060CC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106100_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106134_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106168_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801061D4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106220_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801062BC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106344_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801063F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010642C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106450_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106474_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801064DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106550_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801065B8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010660C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106654_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010669C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801066DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010671C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106760_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801067D0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106814_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010684C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801068B0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106950_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801069D8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106A48_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106AAC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106AD8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106B40_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106D8C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80106ED8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107040_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801071E8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801072B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107380_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010744C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107490_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107574_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801075D8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107608_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107670_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801076A0_filesel);

void func_801076D0_filesel(s32 arg0, u32 arg1) {
    u32 temp_v0;

    func_8005D294_main(D_80114158_filesel[arg0].unk_00);
    if (D_80114158_filesel[arg0].unk_04 != 0) {
        func_80019C00_main((u32)D_80114158_filesel[arg0].unk_04);
        D_80114158_filesel[arg0].unk_04 = 0;
    }

    temp_v0 = func_80106AD8_filesel(arg1);
    // pointer check
    if (temp_v0 > 0x80000000U) {
        D_80114158_filesel[arg0].unk_04 = temp_v0;
    }
    func_8005B43C_main(D_80114158_filesel[arg0].unk_00, temp_v0, -1, -1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010779C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801077D8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107810_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010782C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107880_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801078BC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801078F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107AA8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107C50_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107C84_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80107CF8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801083AC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108440_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112A64_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112A68_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010846C_filesel);

s32 func_80108834_filesel(void) {
    s32 i;
    s32 total;

    for (i = 0, total = 0; i < ARRAY_COUNT(D_801142DC_filesel); i++) {
        if (D_801142DC_filesel[i].unk_00 == UNK_VALUE) {
            total++;
        }
    }

    return total;
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108878_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801088DC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108A94_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108C34_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108D74_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80108EB8_filesel);

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

// TODO: can the gotos be removed?
// main function for handling input when an option hasn't been select yet
u32 func_80109570_filesel(s32 arg0) {
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
        pressedInput = D_800D1244_main;
        temp_v0 = func_80111B14_filesel(0);
        if (temp_v0 != -1) {
            pressedInput |= temp_v0;
        }
        if (D_800D5558_main[0] & A_BUTTON) {
            switch (selectedOption) {
                case OPTION_FILE0:
                    RepeatVibrator(0, 5, 0, 5);
                    func_80110FB0_filesel(selectedOption);
                    break;
                case OPTION_FILE1:
                    RepeatVibrator(0, 5, 0, 5);
                    func_80110FB0_filesel(selectedOption);
                    break;
                case OPTION_FILE2:
                    RepeatVibrator(0, 5, 0, 5);
                    func_80110FB0_filesel(selectedOption);
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
        if ((D_800D5558_main[0] & B_BUTTON)) {
            if (selectedOption > OPTION_MAX) {
                goto checkIfCursorIndexChanged;
            }
        }
        switch (selectedOption) {
            case OPTION_FILE0:
            case OPTION_FILE1:
            case OPTION_FILE2:
                temp_v1 = func_80108834_filesel();
                if (pressedInput & (L_JPAD | R_JPAD)) {
                    func_801076D0_filesel(4, 0x2A00);
                    func_80110FB0_filesel(selectedOption);
                    cursorIndex = selectedOption + 1;
                    if (pressedInput & L_JPAD) {
                        cursorIndex = selectedOption - 1;
                        // if less than 0, wrap index back around to file index 2
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
                            func_801076D0_filesel(4, 0x2A01);
                        } else {
                            func_801076D0_filesel(4, 0x2A03);
                        }
                        func_80110FB0_filesel(selectedOption);
                    } else {
                        if (D_801142DC_filesel[cursorIndex].unk_00 == unkValue) {
                            cursorIndex = selectedOption + OPTION_FILES_NAME_BEGIN;
                            func_80110FB0_filesel(selectedOption);
                        }
                    }
                }
                break;
            case OPTION_COPY:
                temp_v1 = func_80108834_filesel();
                if (pressedInput & (L_JPAD | R_JPAD)) {
                    if (temp_v1 == 0) {
                        func_801076D0_filesel(4, 0x2A13);
                    } else {
                        func_801076D0_filesel(4, 0x2A07);
                    }
                    cursorIndex = OPTION_ERASE;
                }
                if (pressedInput & D_JPAD) {
                    cursorIndex = OPTION_FILE1;
                    func_801076D0_filesel(4, 0x2A00);
                }
                break;
            case OPTION_ERASE:
                temp_v1 = func_80108834_filesel();
                if (pressedInput & (L_JPAD | R_JPAD)) {
                    cursorIndex = OPTION_FILES_END;
                    if ((temp_v1 - 1) < 2) {
                        func_801076D0_filesel(4, 0x2A01);
                    } else {
                        func_801076D0_filesel(4, 0x2A03);
                    }
                }
                if (pressedInput & D_JPAD) {
                    cursorIndex = 2;
                    func_801076D0_filesel(4, 0x2A00);
                }
                break;
            case OPTION_FILE0_NAME:
            case OPTION_FILE1_NAME:
            case OPTION_FILE2_NAME:
                func_801076D0_filesel(4, 0x2A11);
                if (pressedInput & L_JPAD) {
                    cursorIndex = selectedOption;
                    do {
                        cursorIndex -= 1;
                        if (cursorIndex < OPTION_FILES_NAME_BEGIN) {
                            cursorIndex = 7;
                        }
                    } while (D_801142DC_filesel[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
                } else {
                    if (pressedInput & R_JPAD) {
                        cursorIndex = selectedOption;
                        do {
                            // if cursor goes over max, wrap around back to file 0 name
                            if (++cursorIndex > OPTION_MAX) {
                                cursorIndex = OPTION_FILE0_NAME;
                            }
                        } while (D_801142DC_filesel[cursorIndex - OPTION_FILES_NAME_BEGIN].unk_00 != unkValue);
                    }
                }
                if (pressedInput & U_JPAD) {
                    cursorIndex = selectedOption - OPTION_FILES_NAME_BEGIN;
                    func_801076D0_filesel(4, 0x2A00);
                }
                break;
        }

    checkIfCursorIndexChanged:
        if (selectedOption != cursorIndex) {
            // animate cursor to new position
            func_8010AB60_filesel(18, cursorIndex);
            selectedOption = cursorIndex;

            if (selectedOption < OPTION_FILES_END) {
                func_801110F0_filesel(selectedOption);
            }
        }
        func_8010AB1C_filesel(18, selectedOption);

        animTimerAdjusted = (animTimer < 0) ? animTimer + 7 : animTimer;
        animTimerAdjusted = (animTimerAdjusted >> 3);
        func_8010AB58_filesel(18, -animTimerAdjusted);

        animTimer = (animTimer < 20) ? animTimer + 1 : 0;

        HuPrcVSleep();
    }
    return selectedOption;
}

s32 func_80109904_filesel(s32 arg0) {
    u8 buf[32]; // TODO: figure out correct type of this
    s32 temp_s0;

    bzero(&buf, sizeof(buf));
    func_80112494_filesel(arg0, buf);
    HuPrcSleep(3);
    func_801076D0_filesel(4, 0x2A11);
    temp_s0 = func_8010AC58_filesel(arg0);
    HuPrcSleep(3);
    return temp_s0;
}

s32 func_80109968_filesel(s32 arg0) {
    s32 temp_s0;

    HuPrcSleep(3);
    temp_s0 = func_8010AC58_filesel(arg0);
    HuPrcSleep(3);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801099A8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80109B2C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AE8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A028_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A680_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A7D8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A978_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112AF0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010A9B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AB1C_filesel);

void func_8010AB58_filesel(s32 arg0, u32 arg1) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AB60_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010AC58_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B4D0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B4FC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B528_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B554_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B598_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B5D4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B684_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B6F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B80C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B18_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B24_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B30_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B3C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B48_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B54_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B60_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B6C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B78_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B84_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B90_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112B9C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BA8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BB4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BC0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BCC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BD8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BE4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BF0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112BFC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C08_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C14_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C20_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C2C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C38_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C44_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C50_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C5C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C68_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C74_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C80_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C8C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112C98_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CA4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CB0_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CBC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CC8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112CE4_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D00_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D1C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D38_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010B998_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BDC4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BE14_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010BE30_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C25C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C688_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D6C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D7C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D8C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112D9C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DAC_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DBC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010C9B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010CCA8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010D13C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010D660_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DD54_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DDC0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DEEC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DF58_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010DFF4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E1B4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E250_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E740_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010E864_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F10C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F12C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F168_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F5C8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F65C_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112DF8_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112E08_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F678_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F760_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F844_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F874_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010F8A4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FBE0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FC58_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FF48_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8010FFA0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801102F0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110320_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801103A0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801106FC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011072C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801107AC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110B4C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110B7C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110C84_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110CC0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110D0C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110E70_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110F04_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80110FB0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111004_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801110F0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111144_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011132C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_8011139C_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801113E8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111660_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111790_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111944_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801119F4_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111A08_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111B14_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111C30_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111CBC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111E78_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80111FFC_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112184_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801122B0_filesel);

s32 func_80112494_filesel(s32 arg0, u8 *arg1) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_801142DC_filesel[arg0].unk_01[i] = arg1[i];
    }

    // terminate string
    D_801142DC_filesel[arg0].unk_01[i] = '\0';
    D_801142DC_filesel[arg0].unk_01[i + 1] = '\0';
    return i;
}

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112508_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112584_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801125E8_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112630_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112684_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_801126C0_filesel);

INCLUDE_ASM("asm/nonmatchings/overlays/filesel/516AE0", func_80112758_filesel);

INCLUDE_RODATA("asm/nonmatchings/overlays/filesel/516AE0", D_80112E68_filesel);
