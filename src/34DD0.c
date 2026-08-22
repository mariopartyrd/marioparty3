#include "common.h"

extern u32 D_800A11F0_A1DF0[4]; // = { 0, 1, 2, 4 }; //sSizBytes
extern u32 D_800A1200_A1E00[4]; // = { 0, 1, 2, 2 }; //sSizLineBytes
extern u32 D_800A1210_A1E10[4]; // = { 2, 2, 2, 3 }; //sSizLoadBlock
extern u32 D_800A1220_A1E20[4]; // = { 3, 1, 0, 0 }; //sSizIncr
extern u32 D_800A1230_A1E30[4]; // = { 2, 1, 0, 0 }; //sSizShift

INCLUDE_ASM("asm/nonmatchings/34DD0", func_800341D0_34DD0);

INCLUDE_ASM("asm/nonmatchings/34DD0", func_800343FC_34FFC);

//isn't this just gDPLoadTextureBlock?
void func_8003465C_3525C(Gfx **gdl, void *timg, s32 fmt, s32 siz,
                         s32 width, s32 height,
                         s32 uls, s32 ult, s32 lrs, s32 lrt,
                         s32 pal, s32 cms, s32 cmt,
                         s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx *gfx = *gdl;
    timg = (u8 *)timg + ((width * ult) << (siz - 1));

    gDPSetTextureImage(gfx++, fmt, D_800A1210_A1E10[siz], 1,
                       timg);
    gDPSetTile(gfx++, fmt, D_800A1210_A1E10[siz], 0, 0, G_TX_LOADTILE,
               0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0,
                 (((width * height) + D_800A1220_A1E20[siz]) >> D_800A1230_A1E30[siz]) - 1,
                 CALC_DXT(width, D_800A11F0_A1DF0[siz]));
    gDPPipeSync(gfx++);
    gDPSetTile(gfx++, fmt, siz, ((width * D_800A1200_A1E00[siz]) + 7) >> 3, 0,
               G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, uls << 2, ult << 2, lrs << 2, lrt << 2);

    *gdl = gfx;
}

INCLUDE_ASM("asm/nonmatchings/34DD0", func_80034998_35598);

INCLUDE_ASM("asm/nonmatchings/34DD0", func_80034C08_35808);

INCLUDE_ASM("asm/nonmatchings/34DD0", func_80034F70_35B70);

INCLUDE_ASM("asm/nonmatchings/34DD0", func_8003521C_35E1C);

INCLUDE_ASM("asm/nonmatchings/34DD0", func_80035300_35F00);
