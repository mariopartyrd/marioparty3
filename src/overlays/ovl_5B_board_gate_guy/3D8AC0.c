#include "common.h"
#include "GateGuy.h"

void func_801059D0_3D8AC0_board_gate_guy(void) {
    D_800CDD58_CE958 = 1;
    D_800D037C_D0F7C = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80100CEC_E8ABC_name_81(GwPlayer[GwSystem.current_player_index].pad);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800CDD58_CE958 = 0;
    D_800D037C_D0F7C = 1;
}

void func_80105A58_3D8B48_board_gate_guy(void) {
    while (func_800E88FC_D06CC_name_81() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80119470_3EC560_board_gate_guy = func_800E1824_C95F4_name_81(0, 0xA0, 1);
    D_80119474_3EC564_board_gate_guy = func_800E1824_C95F4_name_81(0xD, 0xAE, 1);
    D_80119478_3EC568_board_gate_guy = func_800E1824_C95F4_name_81(1, 0xBC, 1);
    D_8011947C_3EC56C_board_gate_guy = func_800E1824_C95F4_name_81(3, 0xCA, 1);
    HuPrcSleep(3);
    D_800CDD58_CE958 = 1;
    D_800D51F8_D5DF8 = 1;
}

void func_80105B10_3D8C00_board_gate_guy(void) {
    D_800CDD58_CE958 = 0;
    D_800D51F8_D5DF8 = 0;
    func_800E1854_C9624_name_81(D_80119470_3EC560_board_gate_guy);
    func_800E1854_C9624_name_81(D_80119474_3EC564_board_gate_guy);
    func_800E1854_C9624_name_81(D_80119478_3EC568_board_gate_guy);
    func_800E1854_C9624_name_81(D_8011947C_3EC56C_board_gate_guy);
}

void func_80105B64_3D8C54_board_gate_guy(void) {
    GwSystem.current_board_index = 0;
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x5A, 0, 0x4190);
}

void func_80105B9C_3D8C8C_board_gate_guy(void) {
    s8 sp10;
    s8 sp11;

    omInitObjMan(0xA, 0);
    func_800E94D0_D12A0_name_81();
    func_800E9B10_D18E0_name_81(0x13, 0x241);
    func_800E9F4C_D1D1C_name_81(0x1C, &sp10, &sp11);
    func_800ECD0C_D4ADC_name_81(0, sp10, sp11);
    func_800E9F4C_D1D1C_name_81(0x1B, &sp10, &sp11);
    func_800ECD0C_D4ADC_name_81(1, sp10, sp11);
    GwPlayer[0].nnlink = -1;
    GwPlayer[0].nnidx = -1;
    GwPlayer[1].nnlink = -1;
    GwPlayer[1].nnidx = -1;
    func_800E9D9C_D1B6C_name_81();
    func_800E9564_D1334_name_81();
    GwSystem.bank_coins = 5;
    GwSystem.playerIndexVisitingBowser = 0;
    func_800EA760_D2530_name_81();
    omOvlReturnEx(1);
}

void func_80105C64_3D8D54_board_gate_guy(s32 arg0, s32 arg1, unkStruct01* arg2) {
    f32 temp_f20;

    func_800EB708_D34D8_name_81(arg0, arg1, arg2);
    temp_f20 = func_800D76D0_EB2F0_shared_board(arg2) + 15.0f;//could also potentially be func_800D76D0_BF4A0_name_81
    arg2->unk_00 = HuMathSin(temp_f20);
    arg2->unk_08 = HuMathCos(temp_f20);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80105CC0_3D8DB0_board_gate_guy);

void* func_80105EB0_3D8FA0_board_gate_guy(unkStruct04* arg0) {
    Process* process;
    unkStruct02* temp_v0_2;

    process = omAddPrcObj(&func_80105CC0_3D8DB0_board_gate_guy, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(process->heap, sizeof(unkStruct02));
    process->user_data = temp_v0_2;
    temp_v0_2->unk_00.x = arg0->unk_0C.x;
    temp_v0_2->unk_00.y = arg0->unk_0C.y;
    temp_v0_2->unk_00.z = arg0->unk_0C.z;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80105F20_3D9010_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801060D0_3D91C0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010615C_3D924C_board_gate_guy);

void func_80106240_3D9330_board_gate_guy(void) {
    func_800FC8C4_E4694_name_81(&D_80105540_ED310_name_81);
}

//TODO: arg0 is a pointer
void func_80106260_3D9350_board_gate_guy(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    arg3 = arg3 + 0.5f;
    if (arg2 & 9) {
        func_800EC1E4_D3FB4_name_81(&D_80105540_ED310_name_81, arg0 + 0xC, &D_80105540_ED310_name_81, arg3);
    } else {
        func_800EC1E4_D3FB4_name_81(&D_80105540_ED310_name_81, arg1->unk_24 + 0xC, &D_80105540_ED310_name_81, arg3);
    }
}

//TODO: arg0 is a pointer
void func_801062C0_3D93B0_board_gate_guy(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    if (arg2 & 9) {
        func_800EBF2C_D3CFC_name_81(&D_80105540_ED310_name_81, arg0 + 0xC, &D_80105540_ED310_name_81);
    } else {
        func_800EBF2C_D3CFC_name_81(&D_80105540_ED310_name_81, arg1->unk_24 + 0xC, &D_80105540_ED310_name_81);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80106308_3D93F8_board_gate_guy);

Process* func_8010645C_3D954C_board_gate_guy(s32 arg0, s32 arg1) {
    Process* process;
    unkStruct06* temp_v0_2;

    process = omAddPrcObj(&func_80106308_3D93F8_board_gate_guy, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(process->heap, sizeof(unkStruct06));
    process->user_data = temp_v0_2;
    temp_v0_2->unk_00 = arg0;
    temp_v0_2->unk_04 = arg1;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801064C8_3D95B8_board_gate_guy);

void* func_80106740_3D9830_board_gate_guy(s32 arg0) {
    Object* obj;

    obj = func_800D8010_BFDE0_name_81(arg0 & 0xFF, 0);
    func_8001C258_1CE58(obj->unk3C->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(obj->unk3C->model[0], 0x1800);
    func_8001C448_1D048(obj->unk3C->model[0]);
    func_800D8944_C0714_name_81(obj);
    func_800D8F0C_C0CDC_name_81(obj);
    func_8001C814_1D414(obj->unk3C->model[0], 2, 1);
    return obj;
}

void func_801067D4_3D98C4_board_gate_guy(Object* arg0, Vec * arg1) {
    func_800D8E88_C0C58_name_81();
    func_8001C814_1D414(arg0->unk3C->model[0], 3, 0);
    HuVecCopy3F(&arg0->coords, arg1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80106828_3D9918_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80107188_3DA278_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118E60_3EBF50_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801079B8_3DAAA8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80107EBC_3DAFAC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801084A4_3DB594_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80108550_3DB640_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80109404_3DC4F4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80109888_3DC978_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010A210_3DD300_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010AAB0_3DDBA0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010AD48_3DDE38_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010AFB4_3DE0A4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B130_3DE220_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B480_3DE570_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B4C0_3DE5B0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B528_3DE618_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B53C_3DE62C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010B54C_3DE63C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010BCD4_3DEDC4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010CE68_3DFF58_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010D424_3E0514_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010D95C_3E0A4C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010D9F4_3E0AE4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DA84_3E0B74_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DB00_3E0BF0_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118E98_3EBF88_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118EA4_3EBF94_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118EB0_3EBFA0_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118EE0_3EBFD0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DB2C_3E0C1C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DC04_3E0CF4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DCA8_3E0D98_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DD3C_3E0E2C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DDEC_3E0EDC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010DF68_3E1058_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E008_3E10F8_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F18_3EC008_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E1B4_3E12A4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E2CC_3E13BC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E2F8_3E13E8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E348_3E1438_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E3F8_3E14E8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E574_3E1664_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E614_3E1704_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E7C0_3E18B0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E8D8_3E19C8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E904_3E19F4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010E954_3E1A44_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EA74_3E1B64_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EAD4_3E1BC4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EB44_3E1C34_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EB88_3E1C78_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EC78_3E1D68_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010ED20_3E1E10_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EDA0_3E1E90_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010EFBC_3E20AC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010F12C_3E221C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8010F99C_3E2A8C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80110068_3E3158_board_gate_guy);

void func_80110B7C_3E3C6C_board_gate_guy(void) {
    unkStruct07* temp_s0;

    temp_s0 = func_800F375C_DB52C_name_81(CUR_PLAYER);
    if (func_800F3750_DB520_name_81() == 0 && !(temp_s0->unk_17 & 4)) {
        func_800F38DC_DB6AC_name_81(-1, -1, 2);
        func_80110068_3E3158_board_gate_guy(0);
    }
}

void func_80110BD8_3E3CC8_board_gate_guy(void) {
    unkStruct07* temp_s0;

    temp_s0 = func_800F375C_DB52C_name_81(CUR_PLAYER);
    if ((func_800F3750_DB520_name_81() == 1) && !(temp_s0->unk_17 & 4)) {
        func_800F38DC_DB6AC_name_81(-1, -1, 2);
        func_80110068_3E3158_board_gate_guy(1);
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F30_3EC020_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F48_3EC038_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F60_3EC050_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F6C_3EC05C_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118F84_3EC074_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118FB4_3EC0A4_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118FE4_3EC0D4_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118FE8_3EC0D8_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80118FF0_3EC0E0_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80119010_3EC100_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80119014_3EC104_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_801190FC_3EC1EC_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_801191E4_3EC2D4_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_801192CC_3EC3BC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80110C3C_3E3D2C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80111DFC_3E4EEC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801123E8_3E54D8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801124D8_3E55C8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80112514_3E5604_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80112590_3E5680_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801125CC_3E56BC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8011264C_3E573C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801129C8_3E5AB8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80112BB4_3E5CA4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80112DA0_3E5E90_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801135D8_3E66C8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801138D0_3E69C0_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8011390C_3E69FC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80113CAC_3E6D9C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801147FC_3E78EC_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_801193E8_3EC4D8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80115850_3E8940_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801159F8_3E8AE8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80116484_3E9574_board_gate_guy);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", D_80119410_3EC500_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117480_3EA570_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117624_3EA714_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801179AC_3EAA9C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117D3C_3EAE2C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117DDC_3EAECC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117E7C_3EAF6C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117ED8_3EAFC8_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80117FFC_3EB0EC_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118058_3EB148_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118178_3EB268_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801181C4_3EB2B4_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118210_3EB300_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_8011825C_3EB34C_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801182A8_3EB398_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_801182E4_3EB3D4_board_gate_guy);

void func_80118320_3EB410_board_gate_guy(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118328_3EB418_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118414_3EB504_board_gate_guy);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_board_gate_guy/3D8AC0", func_80118530_3EB620_board_gate_guy);
