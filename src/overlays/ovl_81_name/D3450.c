#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB6C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB708_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB740_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB780_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB7BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB7D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB804_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB8B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB984_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EB9D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBA1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBA50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBAD4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBB00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBC60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBD1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBDDC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBE60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBF2C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EBFE0_name_81);

void func_800EC114_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC11C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC1E4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC298_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC36C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC420_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC548_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC6F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC91C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EC99C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECBB4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECC34_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECD0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECD88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECDE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECE10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECE38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ECF1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED118_name_81);

void func_800ED214_name_81(s32 playerIndex) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER *player = MBDGetPlayerStruct(playerIndex);
    Object *partner;

    func_800ECF1C_name_81(playerIndex, &sp10, &sp20);

    if (player->stats.partners.frontID != PARTNER_NONE) {
        partner = MBDGetPlayerPartnerRef(playerIndex, PARTNER_FRONT);
        HuVecCopy3F(&partner->coords, &player->player_obj->coords);
        HuVecAdd(&partner->coords, &partner->coords, &sp10);
        func_800D7828_name_81(&sp10);
        HuVecCopy3F(&partner->rot, &sp10);
    }

    if (player->stats.partners.backID != PARTNER_NONE) {
        partner = MBDGetPlayerPartnerRef(playerIndex, PARTNER_BACK);
        HuVecCopy3F(&partner->coords, &player->player_obj->coords);
        HuVecAdd(&partner->coords, &partner->coords, &sp20);
        func_800D7828_name_81(&sp20);
        func_800D7934_name_81(&sp20, 180.0f);
        HuVecCopy3F(&partner->rot, &sp20);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED31C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED4AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED520_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED68C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED70C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED788_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED7EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800ED9C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDA38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDBEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDC6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D3450", func_800EDCE8_name_81);
