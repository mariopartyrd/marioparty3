#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F7F90_DFD60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F7FDC_DFDAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8034_DFE04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8050_DFE20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8108_DFED8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F821C_DFFEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F82EC_E00BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8358_E0128_name_81);

void func_800F8418_E01E8_name_81(s32 playerIndex, s32 partnerID, s32 frontOrBackIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    switch (frontOrBackIndex) {
        case PARTNER_FRONT:
        player->stats.partners.frontID = partnerID;
        player->stats.partners.frontPoweredUp = POWERUP_NONE;
        player->stats.partners.frontHp = PartnersBaseStats[partnerID].hp;
        player->stats.partners.frontCost = PartnersBaseStats[partnerID].cost;
        player->stats.partners.frontPower = PartnersBaseStats[partnerID].power;
        break;
    case PARTNER_BACK:
        player->stats.partners.backID = partnerID;
        player->stats.partners.backPoweredUp = POWERUP_NONE;
        player->stats.partners.backHp = PartnersBaseStats[partnerID].hp;
        player->stats.partners.backCost = PartnersBaseStats[partnerID].cost;
        player->stats.partners.backPower = PartnersBaseStats[partnerID].power;
        break;
    }

    if (player->stats.partners.frontID != PARTNER_NONE) {
        player->stats.partners.frontPower = PartnersBaseStats[player->stats.partners.frontID].power;
        player->stats.partners.frontCost = PartnersBaseStats[player->stats.partners.frontID].cost;
    }

    if (player->stats.partners.backID != PARTNER_NONE) {
        player->stats.partners.backPower = PartnersBaseStats[player->stats.partners.backID].power;
        player->stats.partners.backCost = PartnersBaseStats[player->stats.partners.backID].cost;
    }

    if (playerIndex == 0) {
        GWBoardFlagClear(0x12);
    } else {
        GWBoardFlagClear(0x13);
    }
}

void func_800F85A4_E0374_name_81(s32 playerIndex, s32 frontOrBackIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    switch (frontOrBackIndex) {
    case PARTNER_FRONT:
        player->stats.partners.frontID = PARTNER_NONE;
        player->stats.partners.frontPoweredUp = 0;
        player->stats.partners.frontHp = 0;
        player->stats.partners.frontCost = 0;
        player->stats.partners.frontPower = 0;
        break;
    case PARTNER_BACK:
        player->stats.partners.backID = PARTNER_NONE;
        player->stats.partners.backPoweredUp = 0;
        player->stats.partners.backHp = 0;
        player->stats.partners.backCost = 0;
        player->stats.partners.backPower = 0;
        break;
    }

    if (player->stats.partners.frontID != PARTNER_NONE) {
        player->stats.partners.frontPower = PartnersBaseStats[player->stats.partners.frontID].power * player->stats.partners.frontPoweredUp;
        player->stats.partners.frontCost = PartnersBaseStats[player->stats.partners.frontID].cost * player->stats.partners.frontPoweredUp;
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        player->stats.partners.backPower = PartnersBaseStats[player->stats.partners.backID].power * player->stats.partners.backPoweredUp;
        player->stats.partners.backCost = PartnersBaseStats[player->stats.partners.backID].cost * player->stats.partners.backPoweredUp;
    }

    //TODO: what are these flags?
    if (playerIndex == 0) {
        GWBoardFlagClear(0x12);
    } else {
        GWBoardFlagClear(0x13);
    }
}

//swaps front and back partners for playerIndex player
void Duel_SwapPartnerPositions(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    s32 frontID = player->stats.partners.frontID;
    s32 frontHP = player->stats.partners.frontHp;
    s32 frontPoweredUp = player->stats.partners.frontPoweredUp;
    s32 frontCost = player->stats.partners.frontCost;
    s32 frontPower = player->stats.partners.frontPower;
    Object* tempPartner;

    player->stats.partners.frontID = player->stats.partners.backID;
    player->stats.partners.frontHp = player->stats.partners.backHp;
    player->stats.partners.frontPoweredUp = player->stats.partners.backPoweredUp;
    player->stats.partners.frontCost = player->stats.partners.backCost;
    player->stats.partners.frontPower = player->stats.partners.backPower;

    player->stats.partners.backID = frontID;
    player->stats.partners.backHp = frontHP;
    player->stats.partners.backPoweredUp = frontPoweredUp;
    player->stats.partners.backCost = frontCost;
    player->stats.partners.backPower = frontPower;

    tempPartner = Duel_PartnerObjects[playerIndex][PARTNER_FRONT];
    Duel_PartnerObjects[playerIndex][PARTNER_FRONT] = Duel_PartnerObjects[playerIndex][PARTNER_BACK];
    Duel_PartnerObjects[playerIndex][PARTNER_BACK] = tempPartner;

    func_800ED214_D4FE4_name_81(playerIndex);
    func_800F5BB4_DD984_name_81(playerIndex);
    func_800F5EB0_DDC80_name_81(playerIndex);
}

void Duel_PowerUpPartners(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    if ((player->stats.partners.frontID != PARTNER_NONE)
        && (player->stats.partners.frontPoweredUp == POWERUP_NONE)) {
        player->stats.partners.frontPoweredUp = 2;
        player->stats.partners.frontHp *= 2;
        player->stats.partners.frontCost *= 2;
        player->stats.partners.frontPower *= 2;
    }
    if ((player->stats.partners.backID != PARTNER_NONE) &&
        (player->stats.partners.backPoweredUp == POWERUP_NONE)) {
        player->stats.partners.backPoweredUp = 2;
        player->stats.partners.backHp *= 2;
        player->stats.partners.backCost *= 2;
        player->stats.partners.backPower *= 2;
    }
}

void Duel_PowerDownPartners(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    
    if ((player->stats.partners.frontID != PARTNER_NONE) && (player->stats.partners.frontPoweredUp == POWERUP_ACTIVE)) {
        player->stats.partners.frontPoweredUp = POWERUP_NONE;
        player->stats.partners.frontHp = (player->stats.partners.frontHp + 1) / 2;
        player->stats.partners.frontCost = player->stats.partners.frontCost / 2;
        player->stats.partners.frontPower = player->stats.partners.frontPower / 2;
    }
    if ((player->stats.partners.backID != PARTNER_NONE) && (player->stats.partners.backPoweredUp == POWERUP_ACTIVE)) {
        player->stats.partners.backPoweredUp = POWERUP_NONE;
        player->stats.partners.backHp = (player->stats.partners.backHp + 1) / 2;
        player->stats.partners.backCost = player->stats.partners.backCost / 2;
        player->stats.partners.backPower = player->stats.partners.backPower / 2;
    }
}

Object* Duel_GetPlayerPartnerRef(s32 playerIndex, s32 frontOrBackIndex) {
    return Duel_PartnerObjects[playerIndex][frontOrBackIndex];
}

s32 func_800F8980_E0750_name_81(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    s32 totalPartnerCost = 0;
    
    if (player->stats.partners.frontID != PARTNER_NONE) {
        totalPartnerCost = player->stats.partners.frontCost;
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        totalPartnerCost += player->stats.partners.backCost;
    }
    return totalPartnerCost;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F89D0_E07A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8AEC_E08BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8C68_E0A38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8CD8_E0AA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8D9C_E0B6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F8EB8_E0C88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F90BC_E0E8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F924C_E101C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FA120_E1EF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAB1C_E28EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAB68_E2938_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAC1C_E29EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAC4C_E2A1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAC94_E2A64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAD04_E2AD4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FADB4_E2B84_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAE18_E2BE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAE98_E2C68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAEE8_E2CB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAEFC_E2CCC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FAFAC_E2D7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB038_E2E08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB0B8_E2E88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB148_E2F18_name_81);

void func_800FB158_E2F28_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB160_E2F30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB524_E32F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB59C_E336C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FBDD4_E3BA4_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_80102758_EA528_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_80102788_EA558_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027B8_EA588_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027C8_EA598_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027EC_EA5BC_name_81);
