#include "common.h"
#include "ovl_80.h"

void func_800E1934_F5554_shared_board(s32 arg0, s32 arg1);
void func_800E1828_F5448_shared_board(s32);
void func_800E1828_F5448_shared_board(s32);

extern f32 D_80100F00_114B20_shared_board[][2];
extern s16 D_80102C20_116840_shared_board[];
extern u8 D_80102C48_116868_shared_board;
extern s16 D_80102C28_116848_shared_board[][2];
extern omObjData* D_80102C38_116858_shared_board[];

void func_800E1450_F5070_shared_board(omObjData* arg0) {
    Vec sp10;
    f32 sp20[2];
    s32 i;

    if (D_80102C48_116868_shared_board != 0) {
        sp10.x = GwPlayer[arg0->work[3]].player_obj->coords.x;
        sp10.y = GwPlayer[arg0->work[3]].player_obj->coords.y + 30.0f;
        sp10.z = GwPlayer[arg0->work[3]].player_obj->coords.z;
        func_800E9940_FD560_shared_board(&sp10, sp20);
    } else {
        sp20[0] = D_80100F00_114B20_shared_board[arg0->work[3]][0];
        sp20[1] = D_80100F00_114B20_shared_board[arg0->work[3]][1];
    }
    
    if (arg0->work[0] < 10) {
        if (arg0->rot.x > 0.0f) {
            arg0->trans.y -= 1.5f;
        } else {
            arg0->trans.y += 1.5f;
        }
        func_80054904_55504(D_80102C20_116840_shared_board[arg0->work[3]], 0, sp20[0], (sp20[1] + arg0->trans.y));
    } else if (arg0->work[0] >= 0x18U) {
        arg0->scale.x += 0.4f;
        arg0->scale.y -= 0.3f;

        if (arg0->scale.x < 0.0f) {
            arg0->scale.x = 0.0f;
        }
        if (arg0->scale.y < 0.0f) {
            arg0->scale.y = 0.0f;
        }
        
        for (i = 1; i < arg0->work[1]; i++) {
            HuSprScaleSet(D_80102C20_116840_shared_board[arg0->work[3]], i, arg0->scale.x, arg0->scale.y);
        }            
    } else if (arg0->work[0] >= 22) {
        arg0->scale.y -= 0.3f;
        if (arg0->scale.y < 0.0f) {
            arg0->scale.y = 0.0f;
        }

        for (i = 1; i < arg0->work[1]; i++) {
            HuSprScaleSet(D_80102C20_116840_shared_board[arg0->work[3]], i, arg0->scale.x, arg0->scale.y);
        }            
    }
    
    if (arg0->work[0] >= 30) {
        func_800E1828_F5448_shared_board(arg0->work[3]);
        return;
    }
    
    arg0->work[0]++;
}


void func_800E17B0_F53D0_shared_board(void) {
    s32 i, j;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        D_80102C20_116840_shared_board[i] = -1;
        D_80102C38_116858_shared_board[i] = 0;
        for (j = 0; j < 2; j++) {
            D_80102C28_116848_shared_board[i][j] = -1;
        }
    }
}

void func_800E1828_F5448_shared_board(s32 arg0) {
    s32 i;
    
    if (D_80102C20_116840_shared_board[arg0] != -1) {
        HuSprGrpKill(D_80102C20_116840_shared_board[arg0]);
        D_80102C20_116840_shared_board[arg0] = -1;
    }
    if (D_80102C38_116858_shared_board[arg0] != 0) {
        omDelObj(D_80102C38_116858_shared_board[arg0]);
        D_80102C38_116858_shared_board[arg0] = 0;
    }

    for (i = 0; i < 2; i++) {
        if (D_80102C28_116848_shared_board[arg0][i] != -1) {
            HuSprKill(D_80102C28_116848_shared_board[arg0][i]);
            D_80102C28_116848_shared_board[arg0][i] = -1;
        }
    }
}

void func_800E18FC_F551C_shared_board(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800E1828_F5448_shared_board(i);
    }
}

void func_800E1934_F5554_shared_board(s32 arg0, s32 arg1) {
    Vec sp18;
    f32 sp28[2];
    omObjData* temp_v0;
    omObjData** temp_v1;
    s16 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    void* temp_v0_3;
    s32 i;

    var_s3 = arg1;
    if (D_80102C20_116840_shared_board[arg0] == -1) {
        if (var_s3 < -0x3E7) {
            var_s3 = -0x3E7;
        }
        if (var_s3 >= 0x3E8) {
            var_s3 = 0x3E7;
        }
        D_80102C38_116858_shared_board[arg0] = omAddObj(-0x8000, 0U, 0U, -1, func_800E1450_F5070_shared_board);
        D_80102C38_116858_shared_board[arg0]->work[0] = 0;
        D_80102C38_116858_shared_board[arg0]->rot.x = var_s3;
        D_80102C38_116858_shared_board[arg0]->trans.y = 0.0f;
        D_80102C38_116858_shared_board[arg0]->scale.x = 1.0f;
        D_80102C38_116858_shared_board[arg0]->scale.y = 2.0f;
        D_80102C38_116858_shared_board[arg0]->work[3] = arg0;
        D_80102C38_116858_shared_board[arg0]->work[1] = 6;
        D_80102C20_116840_shared_board[arg0] = temp_v0_2 = HuSprGrpCreate(6U, 5U);
        temp_v0_3 = DataRead(0x00130112);
        D_80102C28_116848_shared_board[arg0][0] = func_80055810_56410(temp_v0_3);
        DataClose(temp_v0_3);
        if (var_s3 > 0) {
            temp_v0_3 = DataRead(0x00130213);
        } else {
            temp_v0_3 = DataRead(0x00130214);
        }
        
        D_80102C28_116848_shared_board[arg0][1] = func_80055810_56410(temp_v0_3);
        DataClose(temp_v0_3);
        func_80055024_55C24(temp_v0_2, 1, D_80102C28_116848_shared_board[arg0][0], 0);
        HuSprPriSet(temp_v0_2, 1, 0x2010U);
        HuSprAttrSet(temp_v0_2, 1, 0x1000);
        var_s2 = 2;
        func_80055024_55C24(temp_v0_2, 2, D_80102C28_116848_shared_board[arg0][1], 0);
        func_800550F4_55CF4(temp_v0_2, 2, 1);
        if (var_s3 > 0) {
            func_80055140_55D40(temp_v0_2, var_s2, 0xA, 0);
        } else {
            func_80055140_55D40(temp_v0_2, var_s2, 0xB, 0);
        }
        
        HuSprPriSet(temp_v0_2, var_s2, 0x2010U);
        HuSprAttrSet(temp_v0_2, var_s2, 0x1000);
        var_s2++;
        var_s3 = (var_s3 < 0) ? -var_s3 : var_s3;
        if (var_s3 >= 100) {
            func_80055024_55C24(temp_v0_2, var_s2, D_80102C28_116848_shared_board[arg0][1], 0);
            func_800550F4_55CF4(temp_v0_2, var_s2, 1);
            func_80055140_55D40((s32) temp_v0_2, var_s2, (var_s3 / 100), 0);
            HuSprPriSet(temp_v0_2, var_s2, 0x2010U);
            HuSprAttrSet(temp_v0_2, var_s2, 0x1000);
            var_s2++;
        }
        if (var_s3 >= 10) {
            func_80055024_55C24(temp_v0_2, var_s2, D_80102C28_116848_shared_board[arg0][1], 0);
            func_800550F4_55CF4(temp_v0_2, var_s2, 1);
            func_80055140_55D40((s32) temp_v0_2, var_s2, ((var_s3 / 10) % 10), 0);
            HuSprPriSet(temp_v0_2, var_s2, 0x2010U);
            HuSprAttrSet(temp_v0_2, var_s2, 0x1000);
            var_s2 += 1;
        }
        var_s3 = var_s3 % 10;
        func_80055024_55C24(temp_v0_2, var_s2, D_80102C28_116848_shared_board[arg0][1], 0);
        func_800550F4_55CF4(temp_v0_2, var_s2, 1);
        func_80055140_55D40(temp_v0_2, var_s2, var_s3, 0);
        HuSprPriSet(temp_v0_2, var_s2, 0x2010U);
        HuSprAttrSet(temp_v0_2, var_s2, 0x1000);
        var_s2++;
        if (D_80102C48_116868_shared_board != 0) {
            sp18.x = GwPlayer[arg0].player_obj->coords.x;
            sp18.y = GwPlayer[arg0].player_obj->coords.y + 30.0f;
            sp18.z = GwPlayer[arg0].player_obj->coords.z;
            func_800E9940_FD560_shared_board(&sp18, sp28);
            func_80054904_55504(temp_v0_2, 0, sp28[0], sp28[1]);
        } else {
            func_80054904_55504(temp_v0_2, 0, D_80100F00_114B20_shared_board[arg0][0], D_80100F00_114B20_shared_board[arg0][1]);
        }

        var_s1 = (var_s2 - 2);
        var_s1 = -( var_s1 * 8);

        for (i = 1; i < var_s2; i++) {
            func_80054904_55504(temp_v0_2, i, var_s1, 0);
            var_s1 += 16;
        }

        for (; var_s2 < 6; var_s2++) {
            HuSprAttrSet(temp_v0_2, var_s2, 0x8000);
        }

    }
}

void func_800E1F28_F5B48_shared_board(s32 arg0, s32 arg1) {
    D_80102C48_116868_shared_board = 0;
    func_800E1934_F5554_shared_board(arg0, arg1);
}

void ShowPlayerCoinChange(s32 player, s32 coins) {
    D_80102C48_116868_shared_board = 1;
    func_800E1934_F5554_shared_board(player, coins);
}
