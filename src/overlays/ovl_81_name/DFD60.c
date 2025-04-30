#include "common.h"
#include "ovl_81.h"

void func_800F7F90_DFD60_name_81(void) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++){
            Duel_PartnerObjects[i][j] = NULL;
        }
    }
}

void func_800F7FDC_DFDAC_name_81(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_800F82EC_E00BC_name_81(i);
    }

    if (D_8010195C_E972C_name_81 != 0) {
        omDelPrcObj(D_8010195C_E972C_name_81);
        D_8010195C_E972C_name_81 = 0;
    }
}

//partnerIndex arg goes unused?
Object* func_800F8034_DFE04_name_81(s32 partnerIndex) {
    return func_800F8050_DFE20_name_81(7);
}

Object* func_800F8050_DFE20_name_81(s32 partnerIndex) {
    Object* obj = func_800D8010_BFDE0_name_81(PartnersBaseStats[partnerIndex].unk_00, D_801017DC_E95AC_name_81[partnerIndex]);

    if (partnerIndex == PARTNER_BOO) {
        func_8001FA68_20668(obj->unk3C->model[0]);
        func_8001F9E4_205E4(obj->unk3C->model[0], 0xFF);
        func_8001FA68_20668(obj->unk40->model[0]);
        func_8001F9E4_205E4(obj->unk40->model[0], 0xFF);
    }

    func_800D8944_C0714_name_81(obj);
    return obj;
}

void func_800F8108_DFED8_name_81(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    
    if (Duel_PartnerObjects[playerIndex][0] != NULL) {
        func_800D8F3C_C0D0C_name_81(Duel_PartnerObjects[playerIndex][0]);
        Duel_PartnerObjects[playerIndex][0] = NULL;
    }

    if (player->stats.partners.frontID != -1) {
        if (player->stats.partners.frontID == 7) {
            Duel_PartnerObjects[playerIndex][0] = func_800F8034_DFE04_name_81(playerIndex);
        } else {
            Duel_PartnerObjects[playerIndex][0] = func_800F8050_DFE20_name_81(player->stats.partners.frontID);
        }
    }

    if (Duel_PartnerObjects[playerIndex][1] != 0) {
        func_800D8F3C_C0D0C_name_81(Duel_PartnerObjects[playerIndex][1]);
        Duel_PartnerObjects[playerIndex][1] = 0;
    }

    if (player->stats.partners.backID != -1) {
        if (player->stats.partners.backID == 7) {
            Duel_PartnerObjects[playerIndex][1] = func_800F8034_DFE04_name_81(playerIndex);
        } else {
            Duel_PartnerObjects[playerIndex][1] = func_800F8050_DFE20_name_81(player->stats.partners.backID);
        }
    }
}

void func_800F821C_DFFEC_name_81(s32 playerIndex, s32 partnerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    Object* partnerObj = Duel_PartnerObjects[playerIndex][partnerIndex];
    s32 partnerID;
    
    if (partnerObj != NULL) {
        func_800D8F3C_C0D0C_name_81(partnerObj);
        Duel_PartnerObjects[playerIndex][partnerIndex] = NULL;
    }
    
    if (partnerIndex == 0) {
        partnerID = player->stats.partners.frontID;
    } else {
        partnerID = player->stats.partners.backID;
    }
    
    if (partnerID != PARTNER_NONE) {
        if (partnerID == PARTNER_PIRANHA_PLANT) {
            Duel_PartnerObjects[playerIndex][partnerIndex] = func_800F8034_DFE04_name_81(playerIndex);
        } else {
            Duel_PartnerObjects[playerIndex][partnerIndex] = func_800F8050_DFE20_name_81(partnerID);
        }
    }
}

void func_800F82EC_E00BC_name_81(s32 playerIndex) {
    s32 i;
    
    for (i = 0; i < 2; i++) {
        if (Duel_PartnerObjects[playerIndex][i] != NULL) {
            func_800D8F3C_C0D0C_name_81(Duel_PartnerObjects[playerIndex][i]);
            Duel_PartnerObjects[playerIndex][i] = NULL;
        }
    }
}

void func_800F8358_E0128_name_81(s32 playerIndex) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    if (player->stats.partners.frontID == PARTNER_NONE) {
        if (Duel_PartnerObjects[playerIndex][0] != NULL) {
            func_800D8F3C_C0D0C_name_81(Duel_PartnerObjects[playerIndex][0]);
            Duel_PartnerObjects[playerIndex][0] = NULL;
            func_800F85A4_E0374_name_81(playerIndex, 0);
        }
    }
    
    if (player->stats.partners.backID == PARTNER_NONE) {
        if (Duel_PartnerObjects[playerIndex][1] != NULL) {
            func_800D8F3C_C0D0C_name_81(Duel_PartnerObjects[playerIndex][1]);
            Duel_PartnerObjects[playerIndex][1] = 0;
            func_800F85A4_E0374_name_81(playerIndex, 1);
        }
    }
}

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

s32 func_800F89D0_E07A0_name_81(s32 playerIndex, s32 frontOrBackIndex, s16 arg2, s16 arg3) {
    s32 partnerCount = 0;
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    
    if (playerIndex == CUR_PLAYER) {
        playerIndex = Duel_GetCurrentPlayerIndex();
    }

    if (frontOrBackIndex == PARTNER_FRONT) {
        if ((player->stats.partners.frontID != PARTNER_NONE) && (D_801017DC_E95AC_name_81[player->stats.partners.frontID] != NULL)) {
            func_800D90D0_C0EA0_name_81(Duel_PartnerObjects[playerIndex][0], arg2, arg3);
            partnerCount++;
        }
    }

    if (frontOrBackIndex == PARTNER_BACK) {
        if ((player->stats.partners.backID != PARTNER_NONE) && (D_801017DC_E95AC_name_81[player->stats.partners.backID] != NULL)) {
            func_800D90D0_C0EA0_name_81(Duel_PartnerObjects[playerIndex][1], arg2, arg3);
            partnerCount++;
        }
    }
    return partnerCount;
}

s32 func_800F8AEC_E08BC_name_81(s32 playerIndex, s32 arg1, s16 arg2, s16 arg3, u16 arg4, u16 flags) {
    s32 partnerCount = 0;
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);
    u16 flagsCopy = flags;
    
    if (playerIndex == CUR_PLAYER) {
        playerIndex = Duel_GetCurrentPlayerIndex();
    }
    
    if (arg1 == 0) {
        if ((player->stats.partners.frontID != PARTNER_NONE) && (D_801017DC_E95AC_name_81[player->stats.partners.frontID] != NULL)) {
            if (player->stats.partners.frontID == PARTNER_THWOMP) {
                flagsCopy &= ~4;
            }
            func_800D918C_C0F5C_name_81(Duel_PartnerObjects[playerIndex][0], arg2, arg3, arg4, flagsCopy);
            partnerCount++;
        }
    }
    
    if (arg1 == 1) {
        if ((player->stats.partners.backID != PARTNER_NONE) && (D_801017DC_E95AC_name_81[player->stats.partners.backID] != NULL)) {
            if (player->stats.partners.backID == PARTNER_THWOMP) {
                flags &= ~4;
            }
            func_800D918C_C0F5C_name_81(Duel_PartnerObjects[playerIndex][1], arg2, arg3, arg4, flags);
            partnerCount++;
        }
    }
    
    return partnerCount;
}

void func_800F8C68_E0A38_name_81(s32 arg0) {
    Object* frontPartnerObj = Duel_PartnerObjects[arg0][0];
    Object* backPartnerObj;
    
    if (frontPartnerObj != NULL) {
        func_8001FDE8_209E8(frontPartnerObj->unk3C->model[0]);
    }

    backPartnerObj = Duel_PartnerObjects[arg0][1];
    if (backPartnerObj != NULL) {
        func_8001FDE8_209E8(backPartnerObj->unk3C->model[0]);
    }
}

void func_800F8CD8_E0AA8_name_81(s32 playerIndex, f32 arg1) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    if (playerIndex == PARTNER_NONE) {
        playerIndex = Duel_GetCurrentPlayerIndex();
    }
    
    if (player->stats.partners.frontID != PARTNER_NONE) {
        func_8001C92C_1D52C(Duel_PartnerObjects[playerIndex][0]->unk3C->model[0], arg1);
    }
    
    if (player->stats.partners.backID != PARTNER_NONE) {
        func_8001C92C_1D52C(Duel_PartnerObjects[playerIndex][1]->unk3C->model[0], arg1);
    }
}

void func_800F8D9C_E0B6C_name_81(s32 arg0, s32* arg1, s32* arg2) {
    GW_PLAYER* curPlayer = NULL;
    GW_PLAYER* opponent = NULL;
    s32 i;
    
    for (i = 0; i < 2; i++) {
        if (i == Duel_GetCurrentPlayerIndex()) {
            curPlayer = Duel_GetPlayerStruct(i);
        } else {
            opponent = Duel_GetPlayerStruct(i);
        }
    }

    switch (arg0) {
    case 0:
        *arg1 = curPlayer->stats.partners.frontID;
        *arg2 = opponent->stats.partners.backID;
        return;
    case 1:
        *arg1 = curPlayer->stats.partners.backID;
        *arg2 = opponent->stats.partners.frontID;
        return;
    case 2:
        *arg1 = curPlayer->stats.partners.backID;
        *arg2 = opponent->stats.partners.backID;
        return;
    case 3:
        *arg1 = curPlayer->stats.partners.frontID;
        *arg2 = opponent->stats.partners.frontID;
        return;
    }
}

//what does this do?
void func_800F8EB8_E0C88_name_81(u32 arg0, s32 arg1, s32* arg2, s32* arg3) {
    *arg3 = 0;
    
    switch (arg0) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
        break;
    case 3:
        *arg2 = -*arg2;
        break;
    case 9:
        if (arg1 != -1) {
            *arg2 = 100;
        } else {
            *arg2 = 0;
        }
        break;
    case 11:
        if (func_800EFE20_D7BF0_name_81(100.0f) < 40) {
            *arg2 *= 3;
        } else {
            *arg2 = 0;
        }
        break;
    case 8:
        if (*arg2 == 4) {
            *arg2 = 0xCA;
        } else if (*arg2 == 2) {
            *arg2 = 0xC9;
        } else {
            *arg2 = 0xC8;
        }
        break;
    }

    if (*arg2 > 0) {
        if ((*arg2 - 0xC8) >= 2U) {
            if (*arg2 != 0xCA) {
                if (arg1 != -1) {
                    if (func_800EFE20_D7BF0_name_81(10.0f) == 0) {
                        *arg2 = 0x12C;
                    }
                }
            }
        }
    }

    if (arg1 != -1) {
        if (arg1 == 4) {
            if (*arg2 == 0xC8) {
                *arg3 = 1;
            } else if (*arg2 == 0xC9) {
                *arg3 = 2;
            } else if (*arg2 == 0xCA) {
                *arg3 = 4;
            } else {
                if ((*arg2 > 0) && (*arg2 != 0x64)) {
                    if (*arg2 != 0x12C) {
                        *arg3 = *arg2;
                    }
                }                
            }
        }
    } else {
        if ((*arg2 > 0) && ((u32)(*arg2 - 0xC8) >= 2U) && (*arg2 != 0xCA)) {
            *arg2 = -*arg2;
        }
    }

    if ((*arg3 > 0) && ((u32)(*arg3 - 0xC8) >= 2U) && (*arg3 != 0xCA) && (func_800EFE20_D7BF0_name_81(10.0f) == 0)) {
        *arg3 = 0x12C;
    }
}

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
