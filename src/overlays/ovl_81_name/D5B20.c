#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDD50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDDBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDE1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDEC4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDF48_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDF78_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EDFAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE0D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE0F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE114_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE40C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE468_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EE74C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EEC40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED24_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EED84_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EEDA0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF0A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF0BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF0D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF3B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF3D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF3EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF3F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF754_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF7C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF7D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF800_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF840_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF880_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF8EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EF9C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFA8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFABC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFB00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFB3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFBE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFC28_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFD24_name_81);

s32 func_800EFE20_name_81(f32 arg0) { // 800EEF80 in party mode
    // rand8 returns an unsigned byte
    u8 randomByte1 = rand8();
    u8 randomByte2 = rand8();
    s32 shiftedByte1 = (randomByte1 << 8);

    // Normalize the 16-bit number to the range [0, 1), then multiply by arg0
    s32 scaledRandom = ((randomByte2 | shiftedByte1) / 65536.0f) * arg0;

    return scaledRandom;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFE8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFEAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFEC8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800EFFBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F001C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F008C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/D5B20", D_80102580_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0208_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F03C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F03F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0480_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F04FC_name_81);

void func_800F05AC_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F05B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F061C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F06A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F06D4_name_81);

s32 func_800F0700_name_81(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0708_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F08BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0C30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0C4C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0D1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0DF8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0E4C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0EA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F0FE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F1340_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F13C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F140C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F14A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F159C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F1784_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F2090_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F21CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F2238_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F22E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F23FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F2408_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F24DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F2618_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F32CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F336C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3500_name_81);

s16 MBDGetCurrentPlayerIndex(void) {
    return GwSystem.current_player_index;
}

GW_PLAYER *MBDGetPlayerStruct(s32 player) {
    if (player < 0) {
        player = MBDGetCurrentPlayerIndex();
    }
    return &GwPlayer[player];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F379C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F37B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F37E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3850_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3880_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F38DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F397C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3A04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3AF4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3B54_name_81);

void func_800F3B8C_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3B94_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3C28_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3C98_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3D50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3D74_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3DC0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3DFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3E58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3E88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3EC0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3F18_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F3F4C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D5B20", func_800F4030_name_81);
