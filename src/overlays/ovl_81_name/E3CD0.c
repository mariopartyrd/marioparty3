#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FBF00_E3CD0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FBFA4_E3D74_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC030_E3E00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC108_E3ED8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC114_E3EE4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC120_E3EF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC18C_E3F5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC198_E3F68_name_81);

void func_800FC260_E4030_name_81(s32 arg0, s16 arg1) {
    Process* temp_v0_2;
    Object* temp_a0;
    UnkOvl81_1* temp_v0_3;
    s32 frontPartnerID;
    s32 backPartnerID;
    Object* temp_v0;
    s32 i;

    func_800E8D10_D0AE0_name_81();
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    if (arg0 >= 0) {
        func_800E52DC_CD0AC_name_81(arg0);
    }
    func_800E94D0_D12A0_name_81();
    if (arg1 >= 0) {
        func_800E9B10_D18E0_name_81(0x13, arg1);
    }
    func_800D7EB8_BFC88_name_81();
    func_800F3F4C_DBD1C_name_81();
    func_800F3DFC_DBBCC_name_81(0);
    func_800F3DFC_DBBCC_name_81(1);
    for (i = 0; i < 2; i++) {
        func_800D8944_C0714_name_81(DuelGetPlayerStruct(i)->player_obj);
        temp_v0 = DuelGetPlayerStruct(i)->player_obj;
        temp_v0->unkA |= 2;
        temp_a0 = DuelGetPlayerStruct(i)->player_obj;
        func_800D8E88_C0C58_name_81(temp_a0);
    }

    func_8001FDE8_209E8(DuelGetPlayerStruct(0)->player_obj->unk3C->model[0]);
    func_8001FDE8_209E8(DuelGetPlayerStruct(1)->player_obj->unk3C->model[0]);
    func_800F8C68_E0A38_name_81(0);
    func_800F8C68_E0A38_name_81(1);
    func_800F4300_DC0D0_name_81();
    func_800DF1B0_C6F80_name_81();
    func_800E0CEC_C8ABC_name_81();
    func_800E2870_CA640_name_81();
    func_800F6390_DE160_name_81();
    for (i = 0; i < 2; i++) {
        frontPartnerID = GwPlayer[i].stats.partners.frontID;
        backPartnerID = GwPlayer[i].stats.partners.backID;
        GwPlayer[i].stats.partners.frontID = PARTNER_KOOPA; //?
        GwPlayer[i].stats.partners.backID = PARTNER_KOOPA; //?
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
        GwPlayer[i].stats.partners.frontID = frontPartnerID;
        GwPlayer[i].stats.partners.backID = backPartnerID;
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
    }
    func_800DAB1C_C28EC_name_81();
    func_8005A6B0_5B2B0();
    func_800EB664_D3434_name_81();
    D_80105494_ED264_name_81 = -1;
    D_800D1360_D1F60.unk_20 = 0;
    D_80105496_ED266_name_81 = 0;
    func_800F4080_DBE50_name_81();
    D_80101A8C_E985C_name_81 = 0;
    D_80101A90_E9860_name_81 = 0;
    D_80101A94_E9864_name_81 = 0;
    D_80101A98_E9868_name_81 = 0;
    for (i = 0; i < 2; i++) {
        temp_v0_2 = omAddPrcObj(func_800FC198_E3F68_name_81, 0, 0, 0x40);
        temp_v0_3 = HuMemMemoryAlloc(temp_v0_2->heap, sizeof(UnkOvl81_1));
        temp_v0_2->user_data = temp_v0_3;
        temp_v0_3->unk_00 = i;
        omPrcSetStatBit(temp_v0_2, 0xA0);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC4E4_E42B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC590_E4360_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC59C_E436C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5A8_E4378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5B4_E4384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5C0_E4390_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5CC_E439C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC5D8_E43A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC888_E4658_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC894_E4664_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8A0_E4670_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8C4_E4694_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8D0_E46A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8DC_E46AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC8E8_E46B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FC9FC_E47CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCAB4_E4884_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCC84_E4A54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCCCC_E4A9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCD44_E4B14_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FCF50_E4D20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD298_E5068_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD498_E5268_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD4DC_E52AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD55C_E532C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD5F0_E53C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD620_E53F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FD6F4_E54C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF420_E71F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF480_E7250_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF640_E7410_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF944_E7714_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF970_E7740_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF97C_E774C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9AC_E777C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9D8_E77A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FF9E8_E77B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FFA1C_E77EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E3CD0", func_800FFA28_E77F8_name_81);
