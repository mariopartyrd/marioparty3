#include "common.h"
#include "ovl_80.h"

//TODO: properly split data/rodata in F5E80.c and F9DE0.c

extern u16 D_80101204_114E24_shared_board[24];
extern u32 D_801011A0_114DC0_shared_board;
extern char* D_801011C0_114DE0_shared_board[];
extern u32 D_801011E0_114E00_shared_board;
extern omObjData* D_80101200_114E20_shared_board;
extern s16 D_80102DA0_1169C0_shared_board;
extern Object* D_80105710_119330_shared_board;

void MBKSuitKill(void);
void func_80017358_17F58(s16, s32, s16, const char*);
void func_800EB24C_FEE6C_shared_board(s16 arg0, s8 *chainOut, s8 *linkOut);
void MBMotionKill(s16 arg0);
s16 func_800D8E88_ECAA8_shared_board(s32);

static void MBKSuitMain(omObjData* arg0) {
    GW_PLAYER* player;

    player = MBPlayerGet(arg0->work[0]);
    HuVecCopy3F(&D_801011FC_114E1C_shared_board->coords, &player->player_obj->coords);
    HuVecCopy3F(&D_801011FC_114E1C_shared_board->rot, &player->player_obj->rot);
    HuVecCopy3F(&D_801011FC_114E1C_shared_board->scale, &player->player_obj->scale);
    D_801011FC_114E1C_shared_board->velocity.x = player->player_obj->velocity.x;
    D_801011FC_114E1C_shared_board->flags &= ~1;
    D_801011FC_114E1C_shared_board->flags = D_801011FC_114E1C_shared_board->flags | (player->player_obj->flags & 1);
}

const char D_801021F0_115E10_shared_board[] = " 1 VS 1 GAME";
const char D_80102200_115E20_shared_board[] = " BATTLE GAME";
const char D_80102210_115E30_shared_board[] = " ITEM   GAME";
const char D_80102220_115E40_shared_board[] = " 2 VS 2 GAME";
const char D_80102230_115E50_shared_board[] = " 1 VS 3 GAME";
const char D_80102240_115E60_shared_board[] = "4=PLAYER GAME";


INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_80102250_115E70_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_8010225C_115E7C_shared_board);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_8010226C_115E8C_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_80102280_115EA0_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_80102290_115EB0_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_801022A0_115EC0_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_801022B8_115ED8_shared_board);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_801022CC_115EEC_shared_board);

// char const D_8010226C_115E8C_shared_board[] = "c005_000-bmerge1";
// char const D_80102280_115EA0_shared_board[] = "Luigi1-atama_1";
// char const D_80102290_115EB0_shared_board[] = "c003_000-head_1";
// char const D_801022A0_115EC0_shared_board[] = "C002_000b-bmerge10_1";
// char const D_801022B8_115ED8_shared_board[] = "c001_000-atama_2";
// char const D_801022CC_115EEC_shared_board[] = "atama_3";

// INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", D_801022CC_115EEC_shared_board);

// const char D_801022CC_115EEC_shared_board[] = "atama_3";

extern const char D_801022CC_115EEC_shared_board[];
//matches, rodata/data issues
// Object* MBKSuitCreate(void) {
//     GW_PLAYER* temp_s1;
//     Object* temp_v0_2;
//     omObjData* temp_v0;
//     u32 temp_s0;

//     temp_s0 = GwSystem.current_player_index;
//     temp_s1 = MBPlayerGet(CUR_PLAYER);
//     MBKSuitKill();
//     if (temp_s0 < 4) {
//         D_801011FC_114E1C_shared_board = MBModelCreate(0x23, &D_801011A0_114DC0_shared_board);
//         temp_v0 = omAddObj(0x3FFF, 0U, 0U, -1, MBKSuitMain);
//         D_80101200_114E20_shared_board = temp_v0;
//         temp_v0->work[0] = temp_s0 & 0xFF; //? forced cast, remaining from mp1 where work is u8?
//         func_80017358_17F58(temp_s1->player_obj->omObj1->model[0], D_801011C0_114DE0_shared_board[GwPlayer[temp_s0].chr], D_801011FC_114E1C_shared_board->omObj1->model[0], D_801022CC_115EEC_shared_board);
//         HuVecCopy3F(&D_801011FC_114E1C_shared_board->coords, &temp_s1->player_obj->coords);
//     } else {
//         temp_v0_2 = MBModelCreate(8, &D_801011E0_114E00_shared_board);
//         D_801011FC_114E1C_shared_board = temp_v0_2;
//         GwPlayer[4].player_obj = temp_v0_2;
//         MBModelDispOff(temp_v0_2);
//     }
//     return D_801011FC_114E1C_shared_board;
// }

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F9DE0", MBKSuitCreate);

void MBKSuitKill(void) {
    if (D_801011FC_114E1C_shared_board != NULL) {
        MBModelKill(D_801011FC_114E1C_shared_board);
        D_801011FC_114E1C_shared_board = NULL;
    }
    if (D_80101200_114E20_shared_board != NULL) {
        omDelObj(D_80101200_114E20_shared_board);
        D_80101200_114E20_shared_board = NULL;
    }
}

void MBKSuitInit(void) {
    D_801011FC_114E1C_shared_board = NULL;
    D_80101200_114E20_shared_board = NULL;
}

void MBKSuitClose(void) {
    MBKSuitKill();
}

void MBKSuitMotionSet(s16 arg0, s32 arg1) {
    MBMotionSet(D_801011FC_114E1C_shared_board, arg0, arg1);
}

void MBKSuitMotionShiftSet(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    MBMotionShiftSet(D_801011FC_114E1C_shared_board, arg0, arg1, arg2, arg3);
}

void func_800E648C_FA0AC_shared_board(void) {
    HuVecCopy3F(&D_801011FC_114E1C_shared_board->coords, &D_80105710_119330_shared_board->coords);
    func_800EB24C_FEE6C_shared_board(D_80102DA0_1169C0_shared_board, &GwPlayer[4].clink, &GwPlayer[4].clink + 1);
    func_800EB24C_FEE6C_shared_board(D_80102DA0_1169C0_shared_board, &GwPlayer[4].nlink, &GwPlayer[4].nlink + 1);
    GwPlayer[4].nidx = GwPlayer[4].nidx + 1;
}

void func_800E6500_FA120_shared_board(s16 arg0) {
    D_80102DA0_1169C0_shared_board = arg0;
}

void MBKSuitDispOn(void) {
    if (D_801011FC_114E1C_shared_board != NULL) {
        MBModelDispOff(D_801011FC_114E1C_shared_board);
    }
}

void MBKSuitDispOff(void) {
    if (D_801011FC_114E1C_shared_board != NULL) {
        MBModelDispOn(D_801011FC_114E1C_shared_board);
    }
}

void MBKSuitMotionLoad(s32 arg0, s32 arg1) {
    omObjData *objData;
    s16 motion;
    s32 dataNum;
    u32 i;
    Object* obj = D_801011FC_114E1C_shared_board;

    objData = obj->omObj1;

    for (i = 0; i < ARRAY_COUNT(D_80101204_114E24_shared_board); i += 2) {
        if (D_80101204_114E24_shared_board[i] == arg1) {
            break;
        }
    }
    dataNum = D_80101204_114E24_shared_board[i+1] | 0xA0000;

    motion = objData->motion[arg0];
    if ((motion != -1) && (obj->unk46 != arg0)) {
        MBMotionKill(motion);
    }
    objData->motion[arg0] = func_800D8E88_ECAA8_shared_board(dataNum);
}
