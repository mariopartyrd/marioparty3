#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB680_D3450_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB6C4_D3494_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB708_D34D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB740_D3510_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB780_D3550_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB7BC_D358C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB7D8_D35A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB804_D35D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB8B0_D3680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB984_D3754_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB9D4_D37A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBA1C_D37EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBA50_D3820_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBAD4_D38A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBB00_D38D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBC60_D3A30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBD1C_D3AEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBDDC_D3BAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBE60_D3C30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBF2C_D3CFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBFE0_D3DB0_name_81);

void func_800EC114_D3EE4_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC11C_D3EEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC1E4_D3FB4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC298_D4068_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC36C_D413C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC420_D41F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC548_D4318_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC6F4_D44C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC91C_D46EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC99C_D476C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECBB4_D4984_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECC34_D4A04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECD0C_D4ADC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECD88_D4B58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECDE8_D4BB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECE10_D4BE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECE38_D4C08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECF1C_D4CEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED118_D4EE8_name_81);

void func_800ED214_D4FE4_name_81(s32 playerIndex) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* player;
    Object* partner;

    player = Duel_GetPlayerStruct(playerIndex);
    func_800ECF1C_D4CEC_name_81(playerIndex, &sp10, &sp20);

    if (player->stats.partners.frontID != PARTNER_NONE) {
        partner = Duel_GetPlayerPartnerRef(playerIndex, PARTNER_FRONT);
        HuVecCopy3F(&partner->coords, &player->player_obj->coords);
        HuVecAdd(&partner->coords, &partner->coords, &sp10);
        func_800D7828_BF5F8_name_81(&sp10);
        HuVecCopy3F(&partner->unk18, &sp10);
    }

    if (player->stats.partners.backID != PARTNER_NONE) {
        partner = Duel_GetPlayerPartnerRef(playerIndex, PARTNER_BACK);
        HuVecCopy3F(&partner->coords, &player->player_obj->coords);
        HuVecAdd(&partner->coords, &partner->coords, &sp20);
        func_800D7828_BF5F8_name_81(&sp20);
        func_800D7934_BF704_name_81(&sp20, 180.0f);
        HuVecCopy3F(&partner->unk18, &sp20);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED31C_D50EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED4AC_D527C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED520_D52F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED68C_D545C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED70C_D54DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED788_D5558_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED7EC_D55BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED9C4_D5794_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDA38_D5808_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDBEC_D59BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDC6C_D5A3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDCE8_D5AB8_name_81);
