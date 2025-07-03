#include "common.h"

typedef s16 Array2D[2][18];

void func_8000BBFC_C7FC(u16, s16);
void func_8000BC48_C848(u16, s32);
void func_8000BCC8_C8C8(u16, s32);
void func_8000BE5C_CA5C(u16, f32, f32);
void func_8000C184_CD84(u16);
void func_8001ACDC_1B8DC(s16);
void Hu3DModelRotSet(s16, f32, f32, f32);
void Hu3DModelScaleSet(s16, f32, f32, f32);
void func_8001C258_1CE58(s16, s32, s32);
void HuSprKill(s16);
void func_8010B82C_507A8C_msetup(s32);
void func_8010B858_507AB8_msetup();
void func_8010B998_507BF8_msetup();
s32 func_8010D684_5098E4_msetup(s16, s16*);
void func_8010DDD8_50A038_msetup(void*);
omObjData* func_8010DE38_50A098_msetup(s32, s32, s32);
void func_8010E4BC_50A71C_msetup(Array2D*, s32, s32);
void func_8010E4D8_50A738_msetup(Array2D*, s32);
void func_8010E8C8_50AB28_msetup(Array2D*, s32, s32, f32, f32, f32, f32, s32);
void func_8010F320_50B580_msetup(s32, s32, s16, s16);
extern s32 D_80119420_515680_msetup;
extern s32 D_80119E94_5160F4_msetup[];
extern s32 D_80119EAC_51610C_msetup[];
extern s32 D_80119EC4_516124_msetup[];
extern s32 D_80119EE0_516140_msetup[];
extern s16 D_8011A938_516B98_msetup;
extern s16 D_8011A948_516BA8_msetup;
extern u8 D_8011AA45_516CA5_msetup; //board index chosen
typedef struct UnkStarLift {
    char unk_00[0x04];
    s16 unk4;
} UnkStarLift;

s32 _CheckFlag(s32);                                  /* extern */
s16 func_80055810_56410(void*);                       /* extern */

s32 func_80113ED4_510134_msetup(UnkStarLift* arg0);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801059A0_501C00_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105C4C_501EAC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105DB4_502014_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105E90_5020F0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80105F7C_5021DC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106030_502290_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010610C_50236C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801061E0_502440_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106208_502468_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106260_5024C0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106320_502580_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801068F4_502B54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106DF8_503058_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80106FC0_503220_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801070FC_50335C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107428_503688_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801077E0_503A40_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107840_503AA0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107964_503BC4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107A58_503CB8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107B8C_503DEC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107CF4_503F54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107D84_503FE4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107E48_5040A8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107ECC_50412C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107F88_5041E8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80107FB4_504214_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108464_5046C4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801084C4_504724_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801085D4_504834_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801086C8_504928_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801087F4_504A54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801088A8_504B08_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108938_504B98_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801089FC_504C5C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108AB8_504D18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80108F74_5051D4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109218_505478_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109868_505AC8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109EA0_506100_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F04_506164_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80109F7C_5061DC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A10C_50636C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A204_506464_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A2B0_506510_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A35C_5065BC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A780_5069E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7A0_506A00_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010A7EC_506A4C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC78_506ED8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AC94_506EF4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010ACB0_506F10_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010ACC0_506F20_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010AF40_5071A0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B1F4_507454_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B388_5075E8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B4B8_507718_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B588_5077E8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B5D0_507830_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B82C_507A8C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B858_507AB8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B8E0_507B40_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B968_507BC8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B998_507BF8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010B9B8_507C18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BA10_507C70_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BA3C_507C9C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BA6C_507CCC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BBF4_507E54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BC18_507E78_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BE8C_5080EC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BEB0_508110_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010BEF8_508158_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010CAF0_508D50_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010CC70_508ED0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010CD14_508F74_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010CE8C_5090EC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D060_5092C0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D094_5092F4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D0C8_509328_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D234_509494_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D4DC_50973C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D5EC_50984C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D684_5098E4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010D6D0_509930_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010DAC4_509D24_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010DDD8_50A038_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010DE38_50A098_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E00C_50A26C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E044_50A2A4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E09C_50A2FC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E21C_50A47C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E32C_50A58C_msetup);

void func_8010E32C_50A58C_msetup(Array2D*, s32, s32, s32);

void func_8010E4BC_50A71C_msetup(Array2D* arg0, s32 arg1, s32 arg2) {
    func_8010E32C_50A58C_msetup(arg0, arg1, arg2, 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E4D8_50A738_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E52C_50A78C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010E8C8_50AB28_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010EB94_50ADF4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F2BC_50B51C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F2F4_50B554_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F320_50B580_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F33C_50B59C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F43C_50B69C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F4E0_50B740_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8010F87C_50BADC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_8011035C_50C5BC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80110954_50CBB4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80111650_50D8B0_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A6D8_516938_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A6E4_516944_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A6F0_516950_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A6FC_51695C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A708_516968_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A714_516974_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A720_516980_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A72C_51698C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A738_516998_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A744_5169A4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A74C_5169AC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A754_5169B4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A75C_5169BC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A764_5169C4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A76C_5169CC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A774_5169D4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A77C_5169DC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A784_5169E4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A78C_5169EC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A794_5169F4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A79C_5169FC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7A4_516A04_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7AC_516A0C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80112804_50EA64_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80112E08_50F068_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80112F5C_50F1BC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801132C4_50F524_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801138F8_50FB58_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80113DEC_51004C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80113E20_510080_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80113E54_5100B4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80113E88_5100E8_msetup);

s32 func_80113ED4_510134_msetup(UnkStarLift* arg0) {
    #define MODE_PARTY 0
    #define MODE_DUEL 1
    #define FLAG_WALUIGIS_ISLAND 0x31
    #define FLAG_BACKTRACK 0x30
    Array2D sp20;
    s16 unk_68;
    s32* mainFSArray;
    s32 boardCountMaxCopy;
    f32 var_f20;
    void* temp_v0_4;
    omObjData* temp_s5;
    s16 prevBoardIndex;
    s16 backgroundEspriteSlot;
    s16 var_s6;
    s32 pad;
    s32 var_fp;
    s32 boardCountMax;
    s32* boardDescriptionId;
    s16 curBoardIndex;
    s16 temp;
    s32 i;
    f32 tempFloat;

    boardDescriptionId = NULL;
    mainFSArray = NULL;
    curBoardIndex = D_8011AA45_516CA5_msetup;
    arg0->unk4 = 0;
    backgroundEspriteSlot = -1;
    var_s6 = -1;
    boardCountMax = 6;
    var_fp = 70;
    tempFloat = 1.0f;

    switch (D_8011A938_516B98_msetup) { //current mode
    case MODE_PARTY:
        boardDescriptionId = D_80119EC4_516124_msetup;
        mainFSArray = D_80119E94_5160F4_msetup; //party mode board backgrounds
        tempFloat = 1.0f;
        var_fp = 74;
        boardCountMax = 5;
        if (_CheckFlag(FLAG_WALUIGIS_ISLAND) != 0) {
            boardCountMax = 6;
        }
        break;
    case MODE_DUEL:
        boardDescriptionId = D_80119EE0_516140_msetup;
        mainFSArray = D_80119EAC_51610C_msetup; //duel mode board backgrounds
        var_fp = 74;
        boardCountMax = 5;
        if (_CheckFlag(FLAG_BACKTRACK) != 0) {
            boardCountMax = 6;
        }
        break;
    }

    func_8010B998_507BF8_msetup();
    func_8010E4BC_50A71C_msetup(&sp20, 2, 0);
    func_8010E4D8_50A738_msetup(&sp20, 2);
    temp = sp20[0][12];
    temp_s5 = func_8010DE38_50A098_msetup(0x40, 0x100, 0x48);
    func_8010B82C_507A8C_msetup(boardDescriptionId[6]);
    func_8010B858_507AB8_msetup();
    HuAudFXPlay(0x2D9);
    func_8010E8C8_50AB28_msetup(&sp20, 2, 0xF, 720.0f, 565.0f, 0.1f, 1.0f, 1);
    func_8001C258_1CE58(sp20[1][12], 4, 4);
    
    for (var_f20 = 0.0f; var_f20 < 180.0f; var_f20 += (180.0f / 7.0f)) {
        Hu3DModelRotSet(temp, 0, var_f20, 0);
        HuPrcVSleep();
    }
    
    Hu3DModelRotSet(temp, 0, 180.0f, 0);
    temp_s5->work[0] = 1;
    temp_s5->work[1] = 36;
    
    for (var_f20 = 1.0f; var_f20 < 2.5f; var_f20 += (3.0f / 14.0f)) {
        Hu3DModelScaleSet(temp, var_f20, var_f20, var_f20);
        HuPrcVSleep();
    }
    
    Hu3DModelScaleSet(temp, 2.5f, 2.5f, 2.5f);
    prevBoardIndex = -1;
    pad = func_8010D684_5098E4_msetup(D_8011A948_516BA8_msetup, &unk_68);
    boardCountMaxCopy = boardCountMax;
    while (1) {
        pad = func_8010D684_5098E4_msetup(D_8011A948_516BA8_msetup, &unk_68);
        if (pad & A_BUTTON) {
            HuAudFXPlay(2);
            break;
        }
        if (pad & B_BUTTON) {
            HuAudFXPlay(4);
            curBoardIndex = -1;
            break;
        }
        if (pad & (U_JPAD | R_JPAD)) {
            curBoardIndex++;
            curBoardIndex = (boardCountMaxCopy <= curBoardIndex) ? 0 : curBoardIndex;
            HuAudFXPlay(1);
            temp_s5->work[0] = 4;
        } else {
            if (pad & (D_JPAD | L_JPAD)) {
                if (--curBoardIndex < 0) {
                    curBoardIndex = boardCountMax - 1;
                }
                HuAudFXPlay(1);
                temp_s5->work[0] = 3;
            }
        }
        //check if background image should update
        if (prevBoardIndex != curBoardIndex) {
            if (backgroundEspriteSlot >= 0) {
                for (i = 255; i > 0; i -= (255 / 5)) {
                    func_8000BBFC_C7FC(backgroundEspriteSlot, i);
                    HuPrcVSleep();
                }
                func_8000C184_CD84(backgroundEspriteSlot);
                HuSprKill(var_s6);
            }
            temp_v0_4 = DataReadTemp(mainFSArray[curBoardIndex]);
            var_s6 = func_80055810_56410(temp_v0_4);
            DataCloseTemp(temp_v0_4);
            backgroundEspriteSlot = InitEspriteSlot(var_s6, 0, 1);
            func_8000BC48_C848(backgroundEspriteSlot, 0x1000);
            func_8000BCC8_C8C8(backgroundEspriteSlot, 1);
            func_8000BBD4_C7D4(backgroundEspriteSlot, 0xA0, var_fp);
            func_8000BE5C_CA5C(backgroundEspriteSlot, tempFloat, tempFloat);
            for (i = 0; i < 255; i += (255 / 5)) {
                func_8000BBFC_C7FC(backgroundEspriteSlot, i);
                HuPrcVSleep();
            }
            func_8000BBFC_C7FC(backgroundEspriteSlot, 0xFF);
            prevBoardIndex = curBoardIndex;
            func_8010B82C_507A8C_msetup(boardDescriptionId[curBoardIndex]);
        }
        HuPrcVSleep();
    }
    
    arg0->unk4 = curBoardIndex;
    if (curBoardIndex >= 0) {
        D_8011AA45_516CA5_msetup = curBoardIndex;
    }

    temp_s5->work[0] = 2;
    temp_s5->work[1] = 17;
    
    for (i = 255; i > 0; i -= (255 / 5)) {
        func_8000BBFC_C7FC(backgroundEspriteSlot, i);
        HuPrcVSleep();
    }

    func_8000BBFC_C7FC(backgroundEspriteSlot, 0);

    for (var_f20 = 2.5f; var_f20 > 1.0f; var_f20 += -(3.0f / 14.0f)) {
        Hu3DModelScaleSet(temp, var_f20, var_f20, var_f20);
        HuPrcVSleep();
    }

    Hu3DModelScaleSet(temp, 1.0f, 1.0f, 1.0f);

    for (var_f20 = 180.0f; var_f20 < 360.0f; var_f20 += (180.0f / 7.0f)) {
        Hu3DModelRotSet(temp, 0, var_f20, 0);
        HuPrcVSleep();
    }

    Hu3DModelRotSet(temp, 0, 0.0f, 0);
    func_8001C258_1CE58(sp20[1][12], 4, 0);
    HuAudFXPlay(0x2DA);
    func_8010E8C8_50AB28_msetup(&sp20, 2, 7, 360.0f, 400.0f, 1.0f, 0.1f, 1);

    if (curBoardIndex >= 0) {
        func_8010F320_50B580_msetup(D_80119420_515680_msetup, 0, sp20[0][12], -1);
        func_8010F320_50B580_msetup(D_80119420_515680_msetup, 2, backgroundEspriteSlot, var_s6);
        func_8001ACDC_1B8DC(sp20[1][12]);
    } else {
        for (i = 0; i < 2; i++) {
            func_8001ACDC_1B8DC(sp20[i][12]);
        }
        func_8000C184_CD84(backgroundEspriteSlot);
        HuSprKill(var_s6);
    }
    func_8010DDD8_50A038_msetup(temp_s5);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801145D0_510830_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80114AA0_510D00_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801150A0_511300_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801152C4_511524_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801157B8_511A18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80115A9C_511CFC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80115E78_5120D8_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7D8_516A38_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7E0_516A40_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7E8_516A48_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7F0_516A50_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A7F8_516A58_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/501C00", D_8011A800_516A60_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80115EE0_512140_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_801167B8_512A18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80116FE0_513240_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80117818_513A78_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80117820_513A80_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80117910_513B70_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80117A3C_513C9C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/501C00", func_80118D48_514FA8_msetup);
