#include "common.h"
#include "ovl_81.h"

void Duel_ClearPartnerObjects(void) {
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

Object* func_800F8050_DFE20_name_81(s32 partnerID) {
    Object* obj = func_800D8010_BFDE0_name_81(PartnersBaseStats[partnerID].unk_00, D_801017DC_E95AC_name_81[partnerID]);

    if (partnerID == PARTNER_BOO) {
        func_8001FA68_20668(obj->omObj1->model[0]);
        func_8001F9E4_205E4(obj->omObj1->model[0], 0xFF);
        func_8001FA68_20668(obj->omObj2->model[0]);
        func_8001F9E4_205E4(obj->omObj2->model[0], 0xFF);
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
        func_8001FDE8_209E8(frontPartnerObj->omObj1->model[0]);
    }

    backPartnerObj = Duel_PartnerObjects[arg0][1];
    if (backPartnerObj != NULL) {
        func_8001FDE8_209E8(backPartnerObj->omObj1->model[0]);
    }
}

void func_800F8CD8_E0AA8_name_81(s32 playerIndex, f32 arg1) {
    GW_PLAYER* player = Duel_GetPlayerStruct(playerIndex);

    if (playerIndex == PARTNER_NONE) {
        playerIndex = Duel_GetCurrentPlayerIndex();
    }
    
    if (player->stats.partners.frontID != PARTNER_NONE) {
        func_8001C92C_1D52C(Duel_PartnerObjects[playerIndex][0]->omObj1->model[0], arg1);
    }
    
    if (player->stats.partners.backID != PARTNER_NONE) {
        func_8001C92C_1D52C(Duel_PartnerObjects[playerIndex][1]->omObj1->model[0], arg1);
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

//what does this do? (arg4 is unused)
void func_800F8EB8_E0C88_name_81(u32 partnerID, s32 arg1, s32* damageAmount, s32* arg3, s32 arg4) {
    *arg3 = 0;
    
    switch (partnerID) {
    case PARTNER_KOOPA:
    case PARTNER_GOOMBA:
    case PARTNER_TOAD:
    case PARTNER_BOO:
    case PARTNER_WHOMP:
    case PARTNER_SNIFIT:
    case PARTNER_PIRANHA_PLANT:
    case PARTNER_MR_BLIZZARD:
        break;
    case PARTNER_BOB_OMB:
        *damageAmount = -*damageAmount;
        break;
    case PARTNER_THWOMP:
        if (arg1 != -1) {
            *damageAmount = 100;
        } else {
            *damageAmount = 0;
        }
        break;
    case PARTNER_BABY_BOWSER:
        if (func_800EFE20_D7BF0_name_81(100.0f) < 40) {
            *damageAmount *= 3;
        } else {
            *damageAmount = 0;
        }
        break;
    case PARTNER_CHOMP:
        if (*damageAmount == 4) {
            *damageAmount = 0xCA;
        } else if (*damageAmount == 2) {
            *damageAmount = 0xC9;
        } else {
            *damageAmount = 0xC8;
        }
        break;
    }

    if (*damageAmount > 0) {
        if ((*damageAmount < 0xC8) || (*damageAmount >= 0xCA)) {
            if (*damageAmount != 0xCA) {
                if (arg1 != -1) {
                    //related to miss chance potentially? gets a 10% chance of something...
                    if (func_800EFE20_D7BF0_name_81(10.0f) == 0) {
                        *damageAmount = 0x12C;
                    }
                }
            }
        }
    }

    switch (arg1) {
        case 4:
            if (*damageAmount == 0xC8) {
                *arg3 = 1;
            } else if (*damageAmount == 0xC9) {
                *arg3 = 2;
            } else if (*damageAmount == 0xCA) {
                *arg3 = 4;
            } else {
                if ((*damageAmount > 0) && (*damageAmount != 0x64)) {
                    if (*damageAmount != 0x12C) {
                        *arg3 = *damageAmount;
                    }
                }                
            }
            break;

        case -1:
            if ((*damageAmount > 0) && ((*damageAmount < 0xC8) || (*damageAmount >= 0xCA)) && (*damageAmount != 0xCA)) {
                *damageAmount = -*damageAmount;
            }
            break;
    }

    if ((*arg3 > 0) && ((*arg3 < 0xC8) || (*arg3 >= 0xCA)) && (*arg3 != 0xCA) && (func_800EFE20_D7BF0_name_81(10.0f) == 0)) {
        *arg3 = 0x12C;
    }
}


void func_8005FBA4_607A4(u8*, s32);                     /* extern */
s32 func_80061188_61D88(s16 arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4, u16 arg5);
void func_80061A5C_6265C(s16, s32);                      /* extern */
void func_800EED68_D6B38_name_81(s16, s32);            /* extern */
void func_800EF3B4_D7184_name_81(s16);                 /* extern */

// void func_800F90BC_E0E8C_name_81(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
//     u8 sp18[64];
//     u8 spB8[64];
//     u8 sp98[64];
//     s16 spD8[2];
//     s32 temp_v0;

//     if (arg1 != 0) {
//         func_8005FBA4_607A4(sp98, arg1);
//         func_8006022C_60E2C(sp98, 0);
//     }
//     if (arg2 != 0) {
//         func_8005FBA4_607A4(spB8, arg2);
//         func_8006022C_60E2C(spB8, 1);
//     }
    
//     func_8005FBA4_607A4(sp18, arg0);
//     func_80060394_60F94(1, spD8, sp18);
//     temp_v0 = func_80061188_61D88(-1, 0xA0 - spD8[0] / 2, 0x78 - spD8[1] / 2, spD8[0], spD8[0], 0);
    
//     if (arg1 != 0) {
//         func_8005B6BC_5C2BC(temp_v0, (u32)sp98, 0);
//     }
//     if (arg2 != 0) {
//         func_8005B6BC_5C2BC(temp_v0, (u32)spB8, 1);
//     }
    
//     func_8005B43C_5C03C(temp_v0, sp18, -1, -1);
//     func_80061388_61F88(temp_v0);
    
//     if (arg3 == -1) {
//         func_800EF3B4_D7184_name_81(temp_v0);
//     } else {
//         func_800EED68_D6B38_name_81(temp_v0, arg3);
//     }
//     func_80061A5C_6265C(temp_v0, 0);
//     func_8005F364_5FF64(temp_v0);
// }

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800F90BC_E0E8C_name_81);

void func_800F924C_E101C_name_81(s32 arg0) {
    UnkDiceRelated *new_var;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp2C;
    s32 sp34;
    Object *sp3C;
    Object *sp44;
    s32 sp4C;
    s32 sp54;
    void (*temp_v0_10)(void);
    void (*temp_v0_9)(void);
    GW_PLAYER *opposingPlayer;
    GW_PLAYER *player;
    Object *temp_v0_6;
    Object *temp_v0_8;
    Process *temp_s6;
    s32 curPlayerIndex;
    s32 opposingPlayerIndex;
    s32 var_s0;
    s32 var_s1;
    s32 var_s5;
    s32 i;
    
    sp2C = 0;
    curPlayerIndex = Duel_GetCurrentPlayerIndex();
    opposingPlayerIndex = curPlayerIndex ^ 1;
    player = Duel_GetPlayerStruct(curPlayerIndex);
    opposingPlayer = Duel_GetPlayerStruct(opposingPlayerIndex);
    temp_s6 = HuPrcCurrentGet();
    func_800E5964_CD734_name_81();
    func_800FAEE8_E2CB8_name_81();
    func_800F8D9C_E0B6C_name_81(arg0, &sp18, &sp1C);
    new_var = D_800CDBC8_CE7C8;
    
    if (sp18 == 0xA) {
        switch (arg0) {
        case 0:
            arg0 = 3;
            break;
        case 3:
            arg0 = 0;
            break;
        case 2:
            arg0 = 1;
            break;
        case 1:
            arg0 = 2;
            break;
        }
    }
    
    D_80105620_ED3F0_name_81 = arg0;
    func_800F8D9C_E0B6C_name_81(arg0, &sp18, &sp1C);
    
    if (sp18 == (-1)) {
        HuPrcChildLink(temp_s6, func_800E7D18_CFAE8_name_81(1.0f));
        HuPrcChildWait();
        func_800EAFC4_D2D94_name_81(0x1E00);
        HuPrcChildLink(temp_s6, func_800E7D18_CFAE8_name_81(1.7f));
        HuPrcChildWait();
    } else {
        sp20 = 0;
        var_s5 = 0;
        sp34 = 0;
        sp4C = 0;
        var_s1 = 0;
        switch (arg0) {
        case 0:
            D_80101968_E9738_name_81 = &player->stats.partners.frontHp;
            D_8010196C_E973C_name_81 = &opposingPlayer->stats.partners.backHp;
            D_80101970_E9740_name_81 = &opposingPlayer->stats.partners.frontHp;
            D_80101974_E9744_name_81 = &player->stats.partners.frontID;
            D_80101978_E9748_name_81 = &opposingPlayer->stats.partners.backID;
            D_8010197C_E974C_name_81 = &opposingPlayer->stats.partners.frontID;
            sp2C = player->stats.partners.frontPoweredUp;
            sp20 = player->stats.partners.frontPower;
            sp34 = 0;
            var_s5 = 1;
            break;
        case 2:
            D_80101968_E9738_name_81 = &player->stats.partners.backHp;
            D_8010196C_E973C_name_81 = &opposingPlayer->stats.partners.backHp;
            D_80101970_E9740_name_81 = &opposingPlayer->stats.partners.frontHp;
            D_80101974_E9744_name_81 = &player->stats.partners.backID;
            D_80101978_E9748_name_81 = &opposingPlayer->stats.partners.backID;
            D_8010197C_E974C_name_81 = &opposingPlayer->stats.partners.frontID;
            sp2C = player->stats.partners.backPoweredUp;
            sp20 = player->stats.partners.backPower;
            sp34 = 1;
            var_s5 = 1;
            break;
        case 1:
            D_80101968_E9738_name_81 = &player->stats.partners.backHp;
            D_8010196C_E973C_name_81 = &opposingPlayer->stats.partners.frontHp;
            D_80101970_E9740_name_81 = &opposingPlayer->stats.partners.backHp;
            D_80101974_E9744_name_81 = &player->stats.partners.backID;
            D_80101978_E9748_name_81 = &opposingPlayer->stats.partners.frontID;
            D_8010197C_E974C_name_81 = &opposingPlayer->stats.partners.backID;
            sp2C = player->stats.partners.backPoweredUp;
            sp20 = player->stats.partners.backPower;
            sp34 = 1;
            var_s5 = 0;
            break;
        case 3:
            D_80101968_E9738_name_81 = &player->stats.partners.frontHp;
            D_8010196C_E973C_name_81 = &opposingPlayer->stats.partners.frontHp;
            D_80101970_E9740_name_81 = &opposingPlayer->stats.partners.backHp;
            D_80101974_E9744_name_81 = &player->stats.partners.frontID;
            D_80101978_E9748_name_81 = &opposingPlayer->stats.partners.frontID;
            D_8010197C_E974C_name_81 = &opposingPlayer->stats.partners.backID;
            sp2C = player->stats.partners.frontPoweredUp;
            sp20 = player->stats.partners.frontPower;
            sp34 = 0;
            var_s5 = 0;
            break;
        }

        sp3C = Duel_GetPlayerPartnerRef(curPlayerIndex, sp34);
        sp44 = Duel_GetPlayerPartnerRef(opposingPlayerIndex, var_s5);
        D_800D037C_D0F7C = 0;
        var_s0 = 0x7F;
        HuPrcChildLink(temp_s6, func_800E7D18_CFAE8_name_81(1.0f));
        
        while (HuPrcChildGet(temp_s6) != 0) {
            func_800036E8_42E8(D_800CDBC8_CE7C8->unk_00, var_s0);
            var_s0 = ((var_s0 - 5) > 0) ? (var_s0 - 5) : (0);
            HuPrcVSleep();
        }

        func_80003A70_4670(new_var->unk_00);
        func_800036E8_42E8(D_800CDBC8_CE7C8->unk_00, 0x7F);
        sp54 = func_8004A5C4_4B1C4(0x17);
        func_800FFAE0_E78B0_name_81(0, 2);
        func_800FFAE0_E78B0_name_81(1, 2);
        HuPrcChildLink(temp_s6, func_800E415C_CBF2C_name_81());
        HuPrcChildWait();
        HuPrcChildLink(temp_s6, func_800E7D18_CFAE8_name_81(3.0f));
        HuPrcChildWait();
        func_800F74E4_DF2B4_name_81(-1);
        HuVecCopy3F(&D_80105540_ED310_name_81, &player->player_obj->coords);
        func_800FC888_E4658_name_81(4);
        func_800FC8C4_E4694_name_81(&D_80105540_ED310_name_81);
        HuPrcChildLink(temp_s6, func_800EC1E4_D3FB4_name_81(&D_80105540_ED310_name_81, &sp3C->coords, &D_80105540_ED310_name_81, 4.0f));
        HuPrcChildWait();
        func_800FC8C4_E4694_name_81(&sp3C->coords);
        func_800F8EB8_E0C88_name_81(sp18, sp1C, &sp20, &sp24, sp2C);
        D_80105550_ED320_name_81 = 0;
        D_80105558_ED328_name_81 = 0;
        
        loop_38:
        if (opposingPlayer->star != 0) {
            if (sp20 == 0x12C) {
                sp20 = 0;
                var_s1 |= 8;
            } else if (sp20 == 0xC8) {
                opposingPlayer->star--;
                if (opposingPlayer->star < 0) {
                    opposingPlayer->star = 0;
                }
                *D_8010196C_E973C_name_81 -= 1;
                *D_80101970_E9740_name_81 -= 1;
                sp20 = 0;
                var_s1 |= 4;
            } else if (sp20 == 0xC9) {
                
                opposingPlayer->star -= 2;
                if (opposingPlayer->star < 0) {
                    opposingPlayer->star = 0;
                }
                
                *D_8010196C_E973C_name_81 -= 2;
                if ((*D_8010196C_E973C_name_81) < 0) {
                    *D_8010196C_E973C_name_81 = 0;
                }
                
                *D_80101970_E9740_name_81 -= 2;
                if ((*D_80101970_E9740_name_81) < 0) {
                    *D_80101970_E9740_name_81 = 0;
                }
                
                sp20 = 0;
                var_s1 |= 0x10;
            } else if (sp20 == 0xCA) {
                opposingPlayer->star -= 4;
                if (opposingPlayer->star < 0) {
                    opposingPlayer->star = 0;
                }
                
                *D_8010196C_E973C_name_81 -= 4;
                if ((*D_8010196C_E973C_name_81) < 0) {
                    *D_8010196C_E973C_name_81 = 0;
                }
                
                *D_80101970_E9740_name_81 -= 4;
                if ((*D_80101970_E9740_name_81) < 0) {
                    *D_80101970_E9740_name_81 = 0;
                }
                sp20 = 0;
                var_s1 |= 0x20;
            } else if (sp20 < 0) {
                opposingPlayer->star += sp20;
                if (opposingPlayer->star < 0) {
                    opposingPlayer->star = 0;
                }
                
                D_80105558_ED328_name_81 = -sp20;
                sp20 = 0;
                var_s1 |= 2;
            } else if (sp20 > 0) {
                *D_8010196C_E973C_name_81 -= sp20;
                if ((*D_8010196C_E973C_name_81) < 0) {
                    D_80105550_ED320_name_81 = (*D_8010196C_E973C_name_81) + sp20;
                    if (sp20 != 0x64) {
                        sp20 = *D_8010196C_E973C_name_81;
                    } else {
                        sp20 = 0;
                    }
                    *D_8010196C_E973C_name_81 = 0;
                } else {
                    D_80105550_ED320_name_81 = sp20;
                    sp20 = 0;
                }
                var_s1 |= 1;
                goto loop_38;
            }
            
            D_80105718_ED4E8_name_81 = 0;
            
            if (opposingPlayer->star <= 0) {
                D_80105718_ED4E8_name_81 = 1;
            }
            
            if ((*D_8010196C_E973C_name_81) <= 0) {
                if (sp24 == 0) {
                    D_80105718_ED4E8_name_81 |= 8;
                    D_80105718_ED4E8_name_81 |= 2 << var_s5;
                } else {
                    D_80105718_ED4E8_name_81 |= 0x10;
                }
            }
            
            if ((*D_80101970_E9740_name_81) <= 0) {
                D_80105718_ED4E8_name_81 |= 2 << (var_s5 ^ 1);
            }
            
            for (i = 255; i > 64; i -= 16) {
                func_800E8870_D0640_name_81(i);
                HuPrcVSleep();
            }

            func_800E8870_D0640_name_81(0x40);
            HuPrcChildLink(temp_s6, func_800E47B8_CC588_name_81(curPlayerIndex, *D_80101974_E9744_name_81, &player->player_obj->coords, &opposingPlayer->player_obj->coords, 1));
            temp_v0_6 = func_800D8010_BFDE0_name_81(0x36, 0);
            HuVecCopy3F(&temp_v0_6->coords, &sp3C->coords);
            func_8001C814_1D414(temp_v0_6->omObj1->model[0], 2, 0);
            HuAudFXPlay(0x1CC);
            func_800EFABC_D788C_name_81(temp_v0_6);
            func_800D8F3C_C0D0C_name_81(temp_v0_6);
            HuPrcChildWait();
            
            if (curPlayerIndex == 0) {
                if (GWBoardFlagCheck(0x12) != 0) {
                    HuAudFXPlay(0x20E);
                }
            } else if (GWBoardFlagCheck(0x13) != 0) {
                HuAudFXPlay(0x20E);
            }
            
            func_800FAB1C_E28EC_name_81();
            
            if (PartnersBaseStats[*D_80101974_E9744_name_81].func1 != 0) {
                D_8010571C_ED4EC_name_81 = (D_80101978_E9748_name_81 == 0) ? (-1) : (*D_80101978_E9748_name_81);
                D_8010570C_ED4DC_name_81 = (D_8010197C_E974C_name_81 == 0) ? (-1) : (*D_8010197C_E974C_name_81);
                PartnersBaseStats[*D_80101974_E9744_name_81].func1(curPlayerIndex, opposingPlayerIndex, sp3C, sp44, var_s1, sp2C);
            }

            func_800FAC4C_E2A1C_name_81();
            D_80105550_ED320_name_81 = 0;
            D_80105558_ED328_name_81 = 0;
            
            loop_99:
            if (player->star != 0) {
                if (sp24 == 0x12C) {
                    sp24 = 0;
                    sp4C |= 8;
                } else if (sp24 < 0) {
                    player->star += (u8) sp24;
                    if (player->star < 0) {
                        player->star = 0;
                    }
                    D_80105558_ED328_name_81 = -sp24;
                    sp24 = 0;
                    sp4C |= 2;
                } else if (sp24 > 0) {
                    *D_80101968_E9738_name_81 -= sp24;
                    if ((*D_80101968_E9738_name_81) < 0) {
                        D_80105550_ED320_name_81 = (*D_80101968_E9738_name_81) + sp24;
                        sp24 = *D_80101968_E9738_name_81;
                        *D_80101968_E9738_name_81 = 0;
                    } else {
                        D_80105550_ED320_name_81 = sp24;
                        sp24 = 0;
                    }
                    sp4C |= 1;
                    goto loop_99;
                }

                D_8010554C_ED31C_name_81 = 0;
                if (player->star <= 0) {
                    D_8010554C_ED31C_name_81 = 1;
                }

                if ((*D_80101968_E9738_name_81) <= 0) {
                    D_8010554C_ED31C_name_81 |= 8;
                    D_8010554C_ED31C_name_81 |= 2 << sp34;
                }

                if (sp4C != 0) {
                    HuVecCopy3F(&D_80105540_ED310_name_81, func_800FC8D0_E46A0_name_81());
                    func_800FC8C4_E4694_name_81(&D_80105540_ED310_name_81);
                    func_800FC888_E4658_name_81(4);
                    HuPrcChildLink(temp_s6, func_800EC1E4_D3FB4_name_81(&D_80105540_ED310_name_81, &sp44->coords, &D_80105540_ED310_name_81, 4.0f));
                    HuPrcChildWait();
                    func_800FC8C4_E4694_name_81(&sp44->coords);
                    HuPrcChildLink(temp_s6, func_800E47B8_CC588_name_81(opposingPlayerIndex, *D_80101978_E9748_name_81, &opposingPlayer->player_obj->coords, &player->player_obj->coords, 0));
                    temp_v0_8 = func_800D8010_BFDE0_name_81(0x36, 0);
                    HuVecCopy3F(&temp_v0_8->coords, &sp44->coords);
                    func_8001C814_1D414(temp_v0_8->omObj1->model[0], 2, 0);
                    HuAudFXPlay(0x1CC);
                    func_800EFABC_D788C_name_81(temp_v0_8);
                    func_800D8F3C_C0D0C_name_81(temp_v0_8);
                    HuPrcChildWait();
                    switch (arg0) {
                    case 0:
                        arg0 = 1;
                        break;
                    case 3:
                        arg0 = 3;
                        break;
                    case 2:
                        arg0 = 2;
                        break;
                    case 1:
                        arg0 = 0;
                        break;
                    }

                    D_80105620_ED3F0_name_81 = arg0;
                    func_800FAB1C_E28EC_name_81();

                    if (((*D_80101978_E9748_name_81) != (-1)) && (PartnersBaseStats[*D_80101978_E9748_name_81].func2 != 0)) {
                        s8 temp = *D_80101974_E9744_name_81;
                        D_8010571C_ED4EC_name_81 = !(temp) == 0 ? temp : -1;
                        D_8010570C_ED4DC_name_81 = -1;
                        PartnersBaseStats[*D_80101978_E9748_name_81].func2(opposingPlayerIndex, curPlayerIndex, sp44, sp3C, sp4C, sp2C + 0x10);
                    }
                    func_800FAC4C_E2A1C_name_81();
                }

                if ((*D_80101974_E9744_name_81) != (-1)) {
                    temp_v0_9 = PartnersBaseStats[*D_80101974_E9744_name_81].func3;
                    if (temp_v0_9 != 0) {
                        temp_v0_9();
                    }
                }

                if ((*D_80101978_E9748_name_81) != (-1)) {
                    temp_v0_10 = PartnersBaseStats[*D_80101978_E9748_name_81].func4;
                    if (temp_v0_10 != 0) {
                        temp_v0_10();
                    }
                }

                if ((*D_80101968_E9738_name_81) <= 0) {
                    *D_80101974_E9744_name_81 = -1;
                    *D_80101968_E9738_name_81 = 0;
                    func_800F8358_E0128_name_81(curPlayerIndex);
                    func_800F57B0_DD580_name_81(curPlayerIndex);
                    func_800F5E2C_DDBFC_name_81(curPlayerIndex);
                }

                if ((*D_8010196C_E973C_name_81) <= 0) {
                    *D_80101978_E9748_name_81 = -1;
                    *D_8010196C_E973C_name_81 = 0;
                    func_800F8358_E0128_name_81(opposingPlayerIndex);
                    func_800F57B0_DD580_name_81(opposingPlayerIndex);
                    func_800F5E2C_DDBFC_name_81(opposingPlayerIndex);
                }

                if ((*D_80101970_E9740_name_81) <= 0) {
                    *D_8010197C_E974C_name_81 = -1;
                    *D_80101970_E9740_name_81 = 0;
                    func_800F8358_E0128_name_81(opposingPlayerIndex);
                    func_800F57B0_DD580_name_81(opposingPlayerIndex);
                    func_800F5E2C_DDBFC_name_81(opposingPlayerIndex);
                }
                
                for (i = 64; i < 255; i += 16) {
                    func_800E8870_D0640_name_81(i);
                    HuPrcVSleep();
                }

                func_800E8870_D0640_name_81(0xFF);
                func_800F75EC_DF3BC_name_81(-1);
                HuVecCopy3F(&D_80105540_ED310_name_81, func_800FC8D0_E46A0_name_81());
                func_800FC8C4_E4694_name_81(&D_80105540_ED310_name_81);
                func_800FC888_E4658_name_81(4);
                HuPrcChildLink(temp_s6, func_800EC1E4_D3FB4_name_81(&D_80105540_ED310_name_81, &player->player_obj->coords, &D_80105540_ED310_name_81, 4.0f));
                HuPrcChildWait();
                func_800FC888_E4658_name_81(1);
                D_800D037C_D0F7C = 1;
            }
        }

        if (sp54 != (-1)) {
            func_800039A4_45A4(sp54, 0x1E);
            func_80003B70_4770(D_800CDBC8_CE7C8->unk_00, 0x5A);
        }
    }
    
    func_800FAFAC_E2D7C_name_81();
    func_800E5954_CD724_name_81();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FA120_E1EF0_name_81);

void func_800FAB1C_E28EC_name_81(void) {
    Object* temp_v0;

    D_80101980_E9750_name_81 = 0;
    D_80101984_E9754_name_81 = 0;
    temp_v0 = func_800D8010_BFDE0_name_81(0x3C, 0);
    D_80101988_E9758_name_81 = temp_v0;
    func_800D8944_C0714_name_81(temp_v0);
    func_800D8F0C_C0CDC_name_81(D_80101988_E9758_name_81);
}

Process* func_800FAB68_E2938_name_81(s32 arg0, s32 arg1, s16* arg2, f32* arg3, f32* arg4) {
    Process* temp_v0;
    u8* temp_a0;
    UnkBoard5* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800FA120_E1EF0_name_81, 0U, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkBoard5));
    temp_v0->user_data = temp_v0_2;
    temp_a0 = D_80101980_E9750_name_81;
    D_80101980_E9750_name_81++;
    temp_v0_2->unk_00 = temp_a0;
    temp_v0_2->unk_04 = arg0;
    temp_v0_2->unk_08 = arg1;
    temp_v0_2->unk_0C = arg2;
    temp_v0_2->unk_10 = arg3;
    temp_v0_2->unk_14 = arg4;
    return temp_v0;
}

void func_800FAC1C_E29EC_name_81(Vec* arg0) {
    HuVecCopy3F(&D_80105460_ED230_name_81, arg0);
    func_800FC8C4_E4694_name_81(&D_80105460_ED230_name_81);
}

void func_800FAC4C_E2A1C_name_81(void) {
    while (D_80101980_E9750_name_81 != 0) {
        HuPrcVSleep();
    }
    func_800D8F3C_C0D0C_name_81(D_80101988_E9758_name_81);
}

void func_800FAC94_E2A64_name_81(PartnerFunc* arg0, PartnerFunc* arg1) {
    s32 i;

    for (i = 0; i < 12; i++) {
        PartnersBaseStats[i].func1 = arg0[i];
    }

    for (i = 0; i < 12; i++) {
        PartnersBaseStats[i].func2 = arg1[i];
    }
}

void func_800FAD04_E2AD4_name_81(s32 arg0) {
    s32* var_s1;
    s32 i;

    var_s1 = D_8010180C_E95DC_name_81[arg0];
    if (var_s1 == NULL) {
        D_80101990_E9760_name_81 = 0;
        return;
    }

    D_80101990_E9760_name_81 = *var_s1++;
    
    for (i = 0; i < D_80101990_E9760_name_81; i++) {
        D_80105470_ED240_name_81[i] = func_8001F1FC_1FDFC(ReadMainFS(*var_s1++), 8);
    }
}

void func_800FADB4_E2B84_name_81(void) {
    s32 i;

    for (i = 0; i < D_80101990_E9760_name_81; i++) {
        func_8002D4B8_2E0B8(D_80105470_ED240_name_81[i]);
    }
}

void func_800FAE18_E2BE8_name_81(Object* arg0, s16 arg1, s16 arg2) {
    if (arg1 <= D_80101990_E9760_name_81) {
        func_8001F304_1FF04(arg0->omObj1->model[0], D_80105470_ED240_name_81[arg1]);
        func_8001C814_1D414(arg0->omObj1->model[0], -1, arg2);
    }
}

void func_800FAE98_E2C68_name_81(Object* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_8001C624_1D224(arg0->omObj1->model[0], D_80105470_ED240_name_81[arg1], arg2, arg3, arg4);
}

void func_800FAEE8_E2CB8_name_81(void) {
    D_80101992_E9762_name_81 = 0;
    D_80101994_E9764_name_81 = 0;
}

void func_800FAEFC_E2CCC_name_81(s32 arg0) {
    s32* var_s1;
    s32 i;

    var_s1 = D_8010183C_E960C_name_81[arg0];
    if (var_s1 == NULL) {
        D_80101992_E9762_name_81 = 0;
        return;
    }

    D_80101992_E9762_name_81 = *var_s1++;
    
    for (i = 0; i < D_80101992_E9762_name_81; i++) {
        D_80105480_ED250_name_81[i] = func_8001F1FC_1FDFC(ReadMainFS(*var_s1++), 8);
    }
}

void func_800FAFAC_E2D7C_name_81(void) {
    s32 i;

    while (D_80101994_E9764_name_81 != 0) {
        HuPrcVSleep();
    }
    
    for (i = 0; i < D_80101992_E9762_name_81; i++) {
        func_8002D4B8_2E0B8(D_80105480_ED250_name_81[i]);
    }
}

void func_800FB038_E2E08_name_81(Object* arg0, s16 arg1, u16 arg2) {
    if (arg1 < D_80101992_E9762_name_81) {
        func_8001F304_1FF04(arg0->omObj1->model[0], D_80105480_ED250_name_81[arg1]);
        func_8001C814_1D414(arg0->omObj1->model[0], -1, arg2);
    }
}

void func_800FB0B8_E2E88_name_81(Object* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk8 == 0x2C) {
        if (D_80101992_E9762_name_81 == 0) {
            func_800FAEFC_E2CCC_name_81(7);
        }
        func_800FB038_E2E08_name_81(arg0, arg1 - 1, arg2);
        return;
    }
    func_800D90D0_C0EA0_name_81(arg0, arg1, arg2);
}

void func_800FB148_E2F18_name_81(void) {
    *D_80101968_E9738_name_81 = 0;
}

void func_800FB158_E2F28_name_81(void) {
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_80102758_EA528_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_80102788_EA558_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027B8_EA588_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027C8_EA598_name_81);

void func_800FB160_E2F30_name_81(void) {
    s16 sp18[2];
    u16 sp36;
    s32 sp3C;
    UnkBoard4* temp_s4;
    u16* temp_s1;
    s32 temp_fp;
    s32 temp_s7;
    s32 var_s3;
    u8 playerPad;
    void* temp_v0_2;
    s32 playerIndex = (s32)HuPrcCurrentGet()->user_data;
    const s32 sp20[3] = {0x001300D3, 0x001300D2, 0x001300D4};
    s32 i;
    
    playerPad = GwPlayer[playerIndex].pad;
    var_s3 = 0;
    func_80060388_60F88(0x78);
    func_800604A8_610A8(sp18, 0x4F00, 0x4F0A);
    sp36 = func_80061188_61D88(D_801019C8_E9798_name_81[0], 0xA0 - sp18[0] / 2, 0x3C, sp18[0], sp18[1], 0);
    func_8005E1A8_5EDA8(sp36, 0x78);
    func_8005FBF8_607F8(sp36, 1, 0xB9, 0xE7);
    func_8005B43C_5C03C(sp36, D_80101998_E9768_name_81[0], -1, -1);
    func_80061388_61F88(sp36);
    temp_s4 = func_800F4528_DC2F8_name_81(3, 2);
    
    for (i = 0; i < 3; i++) {
        temp_v0_2 = ReadMainFS(sp20[i]);
        temp_s4->unk_0C[i] = func_80055810_56410(temp_v0_2);
        HuFreeFilePerm(temp_v0_2);
        func_80055024_55C24(temp_s4->unk_0A, i, temp_s4->unk_0C[i], 0);
        SprPriSet(temp_s4->unk_0A, i, 1U);
        SprAttrSet(temp_s4->unk_0A, i, 0U);
        if (i == 0) {
            func_80054904_55504(temp_s4->unk_0A, 0, 0xA0, 0x7E); 
        } else {
            func_80054904_55504(temp_s4->unk_0A, i, 0, i * 0xE);      
        }   
    }

    sp3C = func_800E1824_C95F4_name_81(0x10, 0xA0, 0);
    temp_fp = func_800E1824_C95F4_name_81(0x11, 0xAE, 0);
    temp_s7 = func_800E1824_C95F4_name_81(4, 0xBC, 0);
    
    while (1) {
        if (D_800C9520_CA120[playerPad] & B_BUTTON) {
            break;
        }
        if (D_800D0590_D1190[playerPad] & 1) {
            var_s3++;
            var_s3 %= 12;
            func_8005D294_5DE94(sp36);
            func_8005B43C_5C03C(sp36, D_80101998_E9768_name_81[var_s3], -1, -1);
            func_80061934_62534(sp36, D_801019C8_E9798_name_81[var_s3]);
        }
        if (D_800D0590_D1190[playerPad] & 2) {
            var_s3--;
            if (var_s3 < 0) {
                var_s3 = 0xB;
            }
            func_8005D294_5DE94(sp36);
            func_8005B43C_5C03C(sp36, D_80101998_E9768_name_81[var_s3], -1, -1);
            func_80061934_62534(sp36, D_801019C8_E9798_name_81[var_s3]);
        }
        HuPrcVSleep();
    }
    
    func_800F4584_DC354_name_81(temp_s4);
    func_800E1854_C9624_name_81(sp3C);
    func_800E1854_C9624_name_81(temp_fp);
    func_800E1854_C9624_name_81(temp_s7);
    func_80061A5C_6265C(sp36, 0);
    func_8005F364_5FF64(sp36);
    omDelPrcObj(0);
}

void func_800FB524_E32F4_name_81(void* arg0) {
    Process* curProcess;
    Process* newProcess;

    curProcess = HuPrcCurrentGet();
    newProcess = omAddPrcObj(func_800FB160_E2F30_name_81, 0x1005U, 0, 0);
    newProcess->user_data = arg0;
    omPrcSetStatBit(newProcess, 0x80);
    HuPrcChildLink(curProcess, newProcess);
    HuPrcChildWait();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DFD60", func_800FB59C_E336C_name_81);

void func_800FBDD4_E3BA4_name_81(void) {
    s32 sp20[1][2];
    GW_PLAYER* player;
    s32 i;
    //TODO: these vars seem rather fake
    s32 *new_var2;
    s32 (*new_var3)[2];

    player = Duel_GetPlayerStruct(-1);
    if ((player->stats.partners.frontID != -1) && (player->stats.partners.backID != -1)) {
        if (player->stats.partners.frontID < player->stats.partners.backID) {
            sp20[0][0] = player->stats.partners.frontID;
            sp20[0][1] = player->stats.partners.backID;
        } else {
            sp20[0][0] = player->stats.partners.backID;
            sp20[0][1] = player->stats.partners.frontID;
        }

        for (i = 0, new_var3 = D_801019E0_E97B0_name_81; i < 5; i++) {
            if (sp20[0][0] == new_var3[i][0]) {
                new_var2 = &D_801019E0_E97B0_name_81[i][1];
                if (sp20[0][1] == new_var2[0]) {
                    func_800EB49C_D326C_name_81(0x16, D_80101A08_E97D8_name_81[i], D_80101A1C_E97EC_name_81[player->stats.partners.frontID], D_80101A1C_E97EC_name_81[player->stats.partners.backID], 0, 0, 0);
                    func_800EB58C_D335C_name_81();
                    func_800EB58C_D335C_name_81();
                    func_800EB278_D3048_name_81();
                    func_800EB29C_D306C_name_81();
                    return;
                }
            }            
        }
    }
}

// INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/DFD60", D_801027EC_EA5BC_name_81);
