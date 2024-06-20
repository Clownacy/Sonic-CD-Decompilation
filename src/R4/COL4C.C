#include "..\EQU.H"
#include "COL4A.H"

static void fadein1();
static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int fadeout_new();
static void fadeout1();
static void fadeout2(PALETTEENTRY* lpPeDest);
static int flashin_new();
static void flashin1();
static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int flashout_new();
static void flashout1();
static void flashout2(PALETTEENTRY* lpPeDest);
static void colorset00(int ColorNo, int WorkOffs);

PALETTEENTRY advacolor[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  64, 160, 1 }, {   0,  96, 192, 1 },
  {   0, 128, 192, 1 }, {  32, 160, 224, 1 }, { 224, 224, 224, 1 }, {  64, 192, 128, 1 },
  {  32, 160,  96, 1 }, {   0,  96,  32, 1 }, { 128, 192,  96, 1 }, {  64, 128,  32, 1 },
  { 128,  32,   0, 1 }, {  32,   0,   0, 1 }, {   0,  32,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, {  64, 224, 224, 1 }, {   0,   0,   0, 1 }, { 160, 224, 128, 1 },
  {   0, 128,   0, 1 }, {   0, 160,  32, 1 }, {   0,  64,   0, 1 }, {   0, 224,  32, 1 },
  {   0,  96,  64, 1 }, {   0, 160, 128, 1 }, {   0, 192, 192, 1 }, {   0,   0,  32, 1 },
  {   0,  64,  96, 1 }, {   0,  96, 160, 1 }, {  32, 160, 192, 1 }, {  64, 192, 192, 1 },
  {   0,   0,   0, 1 }, { 128, 192, 160, 1 }, {  96, 128,  64, 1 }, { 128, 128, 128, 1 },
  { 160, 160, 128, 1 }, {   0,  32,   0, 1 }, {   0,  96,   0, 1 }, {   0, 192,   0, 1 },
  {   0,  32,   0, 1 }, {   0,  96,  32, 1 }, {  32, 160,  96, 1 }, {   0,   0,   0, 1 },
  {   0,   0,  32, 1 }, {   0,  32,  32, 1 }, {  32,  64,  64, 1 }, {  96, 128, 128, 1 }
};
PALETTEENTRY advacolor2[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  32,   0,   0, 1 },
  {  64,  32,  32, 1 }, {  64,  32,  32, 1 }, {  96,  64,  64, 1 }, {  96,  64,  64, 1 },
  {  64,  32,  32, 1 }, {  64,  32,  32, 1 }, {  96,  64,  64, 1 }, { 128,  96,  96, 1 },
  {  64,  32,  32, 1 }, {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  64,  32,  32, 1 },
  {  64,  32,  32, 1 }, {  96,  64,  64, 1 }, { 128,  96,  96, 1 }, {  64,  32,  32, 1 },
  {  96,  64,  64, 1 }, {  64,  32,  32, 1 }, {  32,   0,   0, 1 }, {  64,  32,  32, 1 },
  {  96,  64,  64, 1 }, {  64,  32,  32, 1 }, {   0,   0,   0, 1 }, {  64,  32,  32, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 192, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 192, 224, 224, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY gamecolor[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone4colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 224, 192,  64, 1 },
  {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, { 192, 192,  96, 1 }, {   0, 224,   0, 1 },
  {   0,  64, 128, 1 }, {  32, 128, 192, 1 }, { 128, 192, 224, 1 }, {  32,   0,  32, 1 },
  { 128,   0,  64, 1 }, { 192,  32, 160, 1 }, { 224,  96, 192, 1 }, { 224, 160, 224, 1 },
  {   0,   0,   0, 1 }, { 192, 192, 192, 1 }, {  32, 128, 192, 1 }, {  96, 160, 224, 1 },
  { 160, 192, 224, 1 }, {   0,  64,   0, 1 }, {   0, 128,   0, 1 }, {   0, 224,   0, 1 },
  {   0,  32,  32, 1 }, {  32,  96,  96, 1 }, {  96, 160, 160, 1 }, {   0,   0, 128, 1 },
  {   0,   0,  32, 1 }, {  64,  32,  96, 1 }, {  96,  64, 128, 1 }, { 160, 128, 192, 1 }
};
PALETTEENTRY boss4color[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone4colora, 16, 48 },
  { boss4color, 16, 16 }
};
unsigned char col4c0cnt[10] = { 49, 4, 2, 0, 2, 1, 2, 2, 2, 3 };
unsigned char col4c1cnt[10] = { 50, 4, 2, 1, 2, 2, 2, 3, 2, 0 };
unsigned char col4c2cnt[10] = { 51, 4, 2, 2, 2, 3, 2, 0, 2, 1 };
unsigned char col4c3cnt[10] = { 52, 4, 2, 3, 2, 0, 2, 1, 2, 2 };
PALETTEENTRY col4c0col[4] = {
  { 192, 192, 192, 1 }, {  32, 128, 192, 1 }, {  96, 160, 224, 1 }, { 160, 192, 224, 1 }
};
static int FadeCount;



































void clchgctr() { /* Line 130, Address: 0x101f6e0 */
  if (stageno.b.l) { /* Line 131, Address: 0x101f6e8 */

    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4c1cnt, col4c0col); /* Line 133, Address: 0x101f6f8 */
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4c2cnt, col4c0col); /* Line 134, Address: 0x101f720 */
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4c3cnt, col4c0col); /* Line 135, Address: 0x101f748 */
  }
} /* Line 137, Address: 0x101f770 */







void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 145, Address: 0x101f780 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 148, Address: 0x101f798 */
  if ((char)*pChgTime < 0) { /* Line 149, Address: 0x101f7ac */
    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 150, Address: 0x101f7cc */
    ++*pChgCnt; /* Line 151, Address: 0x101f7f0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 152, Address: 0x101f804 */
      *pChgCnt = 0; /* Line 153, Address: 0x101f830 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 156, Address: 0x101f838 */
    *pChgTime = pCntTbl[0]; /* Line 157, Address: 0x101f854 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 158, Address: 0x101f864 */
  }





} /* Line 165, Address: 0x101f89c */


void fadein0() { /* Line 168, Address: 0x101f8b0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 172, Address: 0x101f8bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 174, Address: 0x101f8f0 */
    lpPe->peRed = 0; /* Line 175, Address: 0x101f8fc */
    lpPe->peGreen = 0; /* Line 176, Address: 0x101f900 */
    lpPe->peBlue = 0; /* Line 177, Address: 0x101f904 */
    lpPe->peFlags = 1; /* Line 178, Address: 0x101f908 */
    ++lpPe; /* Line 179, Address: 0x101f910 */
  } /* Line 180, Address: 0x101f914 */
  FadeCount = 0; /* Line 181, Address: 0x101f930 */
  *lpFadeFlag = 1; /* Line 182, Address: 0x101f938 */

} /* Line 184, Address: 0x101f948 */



int fadein0_new() { /* Line 188, Address: 0x101f960 */

  int_flg = 18; /* Line 190, Address: 0x101f968 */

  fadein1(); /* Line 192, Address: 0x101f974 */


  if (++FadeCount > 21) { /* Line 195, Address: 0x101f97c */
    FadeCount = 0; /* Line 196, Address: 0x101f99c */
    return 1; /* Line 197, Address: 0x101f9a4 */
  }
  return 0; /* Line 199, Address: 0x101f9b0 */
} /* Line 200, Address: 0x101f9b4 */


static void fadein1() { /* Line 203, Address: 0x101f9d0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 207, Address: 0x101f9e4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 208, Address: 0x101fa18 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 210, Address: 0x101fa4c */
    fadein2(lpPe, lpPe2); /* Line 211, Address: 0x101fa58 */
    ++lpPe; /* Line 212, Address: 0x101fa68 */
    ++lpPe2; /* Line 213, Address: 0x101fa6c */
  } /* Line 214, Address: 0x101fa70 */
  if (stageno.b.h == 1) return; /* Line 215, Address: 0x101fa8c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 217, Address: 0x101faa8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 218, Address: 0x101fadc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 220, Address: 0x101fb10 */
    fadein2(lpPe, lpPe2); /* Line 221, Address: 0x101fb1c */
    ++lpPe; /* Line 222, Address: 0x101fb2c */
    ++lpPe2; /* Line 223, Address: 0x101fb30 */
  } /* Line 224, Address: 0x101fb34 */



} /* Line 228, Address: 0x101fb50 */




static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 233, Address: 0x101fb70 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 234, Address: 0x101fb7c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 237, Address: 0x101fbdc */
      lpPeDest->peBlue += 32; /* Line 238, Address: 0x101fc00 */
    } /* Line 239, Address: 0x101fc10 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 240, Address: 0x101fc18 */
      lpPeDest->peGreen += 32; /* Line 241, Address: 0x101fc3c */
    } /* Line 242, Address: 0x101fc4c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 243, Address: 0x101fc54 */
      lpPeDest->peRed += 32; /* Line 244, Address: 0x101fc78 */
    }
  }

} /* Line 248, Address: 0x101fc8c */


void fadeout() {
  startcolor = 0; /* Line 252, Address: 0x101fca0 */
  colorcnt = 63; /* Line 253, Address: 0x101fca8 */

  FadeCount = 0; /* Line 255, Address: 0x101fcb4 */
  *lpFadeFlag = 2; /* Line 256, Address: 0x101fcbc */

} /* Line 258, Address: 0x101fccc */



static int fadeout_new() { /* Line 262, Address: 0x101fce0 */

  int_flg = 18; /* Line 264, Address: 0x101fce8 */

  fadeout1(); /* Line 266, Address: 0x101fcf4 */


  if (++FadeCount > 21) { /* Line 269, Address: 0x101fcfc */
    FadeCount = 0; /* Line 270, Address: 0x101fd1c */
    return 1; /* Line 271, Address: 0x101fd24 */
  }
  return 0; /* Line 273, Address: 0x101fd30 */
} /* Line 274, Address: 0x101fd34 */


static void fadeout1() { /* Line 277, Address: 0x101fd50 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 281, Address: 0x101fd60 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 283, Address: 0x101fd94 */
    fadeout2(lpPe); /* Line 284, Address: 0x101fda0 */
    ++lpPe; /* Line 285, Address: 0x101fdac */
  } /* Line 286, Address: 0x101fdb0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 287, Address: 0x101fdcc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 289, Address: 0x101fe00 */
    fadeout2(lpPe); /* Line 290, Address: 0x101fe0c */
    ++lpPe; /* Line 291, Address: 0x101fe18 */
  } /* Line 292, Address: 0x101fe1c */


} /* Line 295, Address: 0x101fe38 */



static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 299, Address: 0x101fe50 */
  if (lpPeDest->peRed) { /* Line 300, Address: 0x101fe58 */
    lpPeDest->peRed -= 32; /* Line 301, Address: 0x101fe68 */
  } /* Line 302, Address: 0x101fe7c */
  else if (lpPeDest->peGreen) { /* Line 303, Address: 0x101fe84 */
    lpPeDest->peGreen -= 32; /* Line 304, Address: 0x101fe94 */
  } /* Line 305, Address: 0x101fea4 */
  else if (lpPeDest->peBlue) { /* Line 306, Address: 0x101feac */
    lpPeDest->peBlue -= 32; /* Line 307, Address: 0x101febc */
  }

} /* Line 310, Address: 0x101fecc */


void flashin() { /* Line 313, Address: 0x101fee0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 317, Address: 0x101feec */
  colorcnt = 63; /* Line 318, Address: 0x101fef4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 320, Address: 0x101ff00 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 322, Address: 0x101ff34 */
    lpPe->peRed = 224; /* Line 323, Address: 0x101ff40 */
    lpPe->peGreen = 224; /* Line 324, Address: 0x101ff48 */
    lpPe->peBlue = 224; /* Line 325, Address: 0x101ff50 */
    lpPe->peFlags = 1; /* Line 326, Address: 0x101ff58 */
    ++lpPe; /* Line 327, Address: 0x101ff60 */
  } /* Line 328, Address: 0x101ff64 */
  FadeCount = 0; /* Line 329, Address: 0x101ff80 */
  *lpFadeFlag = 3; /* Line 330, Address: 0x101ff88 */

} /* Line 332, Address: 0x101ff98 */


static int flashin_new() { /* Line 335, Address: 0x101ffb0 */

  int_flg = 18; /* Line 337, Address: 0x101ffb8 */

  flashin1(); /* Line 339, Address: 0x101ffc4 */


  if (++FadeCount > 21) { /* Line 342, Address: 0x101ffcc */
    FadeCount = 0; /* Line 343, Address: 0x101ffec */
    return 1; /* Line 344, Address: 0x101fff4 */
  }
  return 0; /* Line 346, Address: 0x1020000 */
} /* Line 347, Address: 0x1020004 */


static void flashin1() { /* Line 350, Address: 0x1020020 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 354, Address: 0x1020034 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 355, Address: 0x1020068 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 357, Address: 0x102009c */
    flashin2(lpPe, lpPe2); /* Line 358, Address: 0x10200a8 */
    ++lpPe; /* Line 359, Address: 0x10200b8 */
    ++lpPe2; /* Line 360, Address: 0x10200bc */
  } /* Line 361, Address: 0x10200c0 */
  if (stageno.b.h == 1) return; /* Line 362, Address: 0x10200dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 364, Address: 0x10200f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 365, Address: 0x102012c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 367, Address: 0x1020160 */
    flashin2(lpPe, lpPe2); /* Line 368, Address: 0x102016c */
    ++lpPe; /* Line 369, Address: 0x102017c */
    ++lpPe2; /* Line 370, Address: 0x1020180 */
  } /* Line 371, Address: 0x1020184 */



} /* Line 375, Address: 0x10201a0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 379, Address: 0x10201c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 380, Address: 0x10201cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 383, Address: 0x102022c */
      lpPeDest->peBlue -= 32; /* Line 384, Address: 0x1020250 */
    } /* Line 385, Address: 0x1020260 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 386, Address: 0x1020268 */
      lpPeDest->peGreen -= 32; /* Line 387, Address: 0x102028c */
    } /* Line 388, Address: 0x102029c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 389, Address: 0x10202a4 */
      lpPeDest->peRed -= 32; /* Line 390, Address: 0x10202c8 */
    }
  }

} /* Line 394, Address: 0x10202dc */


void flashout() {
  startcolor = 0; /* Line 398, Address: 0x10202f0 */
  colorcnt = 63; /* Line 399, Address: 0x10202f8 */

  FadeCount = 0; /* Line 401, Address: 0x1020304 */
  *lpFadeFlag = 4; /* Line 402, Address: 0x102030c */

} /* Line 404, Address: 0x102031c */


static int flashout_new() { /* Line 407, Address: 0x1020330 */

  int_flg = 18; /* Line 409, Address: 0x1020338 */

  flashout1(); /* Line 411, Address: 0x1020344 */


  if (++FadeCount > 21) { /* Line 414, Address: 0x102034c */
    FadeCount = 0; /* Line 415, Address: 0x102036c */
    return 1; /* Line 416, Address: 0x1020374 */
  }
  return 0; /* Line 418, Address: 0x1020380 */
} /* Line 419, Address: 0x1020384 */


static void flashout1() { /* Line 422, Address: 0x10203a0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 426, Address: 0x10203b0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 428, Address: 0x10203e4 */
    flashout2(lpPe); /* Line 429, Address: 0x10203f0 */
    ++lpPe; /* Line 430, Address: 0x10203fc */
  } /* Line 431, Address: 0x1020400 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 432, Address: 0x102041c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 434, Address: 0x1020450 */
    flashout2(lpPe); /* Line 435, Address: 0x102045c */
    ++lpPe; /* Line 436, Address: 0x1020468 */
  } /* Line 437, Address: 0x102046c */


} /* Line 440, Address: 0x1020488 */



static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 444, Address: 0x10204a0 */
  if (lpPeDest->peRed != 224) { /* Line 445, Address: 0x10204a8 */
    lpPeDest->peRed += 32; /* Line 446, Address: 0x10204c0 */
  } /* Line 447, Address: 0x10204d4 */
  else if (lpPeDest->peGreen != 224) { /* Line 448, Address: 0x10204dc */
    lpPeDest->peGreen += 32; /* Line 449, Address: 0x10204f4 */
  } /* Line 450, Address: 0x1020504 */
  else if (lpPeDest->peBlue != 224) { /* Line 451, Address: 0x102050c */
    lpPeDest->peBlue += 32; /* Line 452, Address: 0x1020524 */
  }


} /* Line 456, Address: 0x1020534 */


void colorset(int ColorNo) { /* Line 459, Address: 0x1020540 */
  colorset00(ColorNo, 1); /* Line 460, Address: 0x102054c */
} /* Line 461, Address: 0x102055c */

void colorset2(int ColorNo) { /* Line 463, Address: 0x1020570 */
  colorset00(ColorNo, 0); /* Line 464, Address: 0x102057c */
} /* Line 465, Address: 0x102058c */

void colorset3(int ColorNo) { /* Line 467, Address: 0x10205a0 */
  colorset00(ColorNo, 2); /* Line 468, Address: 0x10205ac */
} /* Line 469, Address: 0x10205bc */




static void colorset00(int ColorNo, int WorkOffs) { /* Line 474, Address: 0x10205d0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 479, Address: 0x10205f0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 481, Address: 0x1020658 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 483, Address: 0x1020668 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 485, Address: 0x1020678 */
    default:
      lppe = lpcolorwk4; break; /* Line 487, Address: 0x1020688 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 490, Address: 0x1020690 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 491, Address: 0x10206a8 */
  n = colortbl[ColorNo].cnt; /* Line 492, Address: 0x10206d0 */
  for (i = 0; i < n; ++i) { /* Line 493, Address: 0x10206f0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 494, Address: 0x10206fc */
  } /* Line 495, Address: 0x102072c */

} /* Line 497, Address: 0x102073c */


int FadeProc() { /* Line 500, Address: 0x1020760 */
  switch (*lpFadeFlag) { /* Line 501, Address: 0x1020768 */
    case 1:
      return fadein0_new(); /* Line 503, Address: 0x10207ac */
    case 2:
      return fadeout_new(); /* Line 505, Address: 0x10207bc */
    case 3:
      return flashin_new(); /* Line 507, Address: 0x10207cc */
    case 4:
      return flashout_new(); /* Line 509, Address: 0x10207dc */
  }
  return 1; /* Line 511, Address: 0x10207ec */

} /* Line 513, Address: 0x10207f0 */
