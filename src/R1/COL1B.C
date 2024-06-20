#include "..\EQU.H"
#include "COL1B.H"

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

PALETTEENTRY clst1_1a0[12][4] = {
  { { 160, 224, 224, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  96, 224, 192, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { { 224, 224, 224, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  64, 192, 128, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  64, 192, 128, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { { 160, 224, 224, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { { 160, 224, 224, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  96, 224, 192, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  96, 224, 192, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  64, 192, 128, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { {  96, 224, 192, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
  { { 160, 224, 224, 1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } }
};
PALETTEENTRY clst1_1a1[12] = {
  { 192, 224, 224, 1 }, {  96, 224, 192, 1 }, {   0, 160, 160, 1 }, {  64, 192, 128, 1 },
  {  96, 224, 192, 1 }, {  64, 192, 128, 1 }, {   0, 160, 160, 1 }, { 192, 224, 224, 1 },
  {  64, 192, 128, 1 }, { 192, 224, 224, 1 }, {   0, 160, 160, 1 }, {  96, 224, 192, 1 }
};
PALETTEENTRY advacolor[64] = {
  {   0,  32, 160, 1 }, {   0,   0,  96, 1 }, {   0,   0, 192, 1 }, {  64,  64, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 224, 160,   0, 1 },
  { 160,  96,   0, 1 }, {  96,  32,   0, 1 }, { 224, 224,   0, 1 }, { 160, 160, 224, 1 },
  { 192,   0,   0, 1 }, { 96 ,   0,   0, 1 }, { 32 ,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {  32,  32, 224, 1 }, {  64,  64, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  96,  96,  96, 1 }, {  64,  64,  64, 1 }, { 128,  64,  32, 1 },
  { 224, 160, 128, 1 }, { 192, 128,  96, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0, 128, 1 }, {  32,   0,   0, 1 }, { 224, 224, 224, 1 }, {  96,  32,   0, 1 },
  { 128,  64,   0, 1 }, { 192,  96,   0, 1 }, { 224, 128,   0, 1 }, { 224, 192,   0, 1 },
  {  32,  64, 192, 1 }, {  96, 128, 224, 1 }, { 160, 192, 224, 1 }, { 192, 224, 224, 1 },
  {   0,  64,   0, 1 }, {   0,  96,   0, 1 }, {  64, 160,   0, 1 }, { 128, 224,   0, 1 },
  {  32, 128, 192, 1 }, {  32,   0, 160, 1 }, {  32,  64, 192, 1 }, {  96, 128, 224, 1 },
  { 160, 192, 224, 1 }, { 192, 224, 224, 1 }, { 224, 224, 224, 1 }, { 192, 160, 224, 1 },
  { 160, 128, 224, 1 }, { 128,  96, 224, 1 }, { 128, 224,   0, 1 }, {  64, 160,   0, 1 },
  {  32,   0,   0, 1 }, {  96,  32,   0, 1 }, { 192,  96,   0, 1 }, { 224, 192,   0, 1 }
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
  {  96, 128, 192, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone1colorb0[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  64, 160, 128, 1 }, { 224, 224, 192, 1 }, {  64, 160, 224, 1 }, {  32,   0,   0, 1 },
  { 224, 160,  96, 1 }, { 128, 224, 224, 1 }, { 160,  64,   0, 1 }, {  96,  32,   0, 1 },
  { 192, 224,   0, 1 }, { 128, 160,   0, 1 }, {  64,  96,   0, 1 }, {   0,  64,  32, 1 },
  { 192, 224, 224, 1 }, {  96, 224, 192, 1 }, {   0, 160, 160, 1 }, {  64, 192, 128, 1 },
  {  64, 160, 128, 1 }, { 160, 224, 224, 1 }, {  64, 192, 128, 1 }, {  96, 224, 192, 1 },
  { 192,  96, 160, 1 }, { 128,  64,  96, 1 }, {  96,  32,  64, 1 }, {  64,   0,  32, 1 },
  {  32,   0,   0, 1 }, { 128, 160,   0, 1 }, {  64,  96,   0, 1 }, {   0,  64,  32, 1 },
  { 224, 224, 224, 1 }, { 160, 224, 224, 1 }, {  64, 192, 128, 1 }, {  32, 160,  96, 1 }
};
PALETTEENTRY zone1colorb[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  96, 128, 192, 1 }, { 224, 224, 192, 1 }, {  64, 160, 224, 1 }, {  32,   0,   0, 1 },
  { 224, 160,  96, 1 }, {   0,   0,   0, 1 }, { 160,  64,   0, 1 }, {  96,  32,   0, 1 },
  { 128, 224,   0, 1 }, {   0, 160,  96, 1 }, {   0,  96,  64, 1 }, {   0,  64,  32, 1 },
  { 192, 224, 224, 1 }, {  96, 224, 192, 1 }, {   0, 160, 160, 1 }, {  64, 192, 128, 1 },
  {  96, 128, 192, 1 }, {  64, 160, 128, 1 }, { 128, 192, 160, 1 }, { 160, 224, 192, 1 },
  { 224, 224, 224, 1 }, { 160, 224, 224, 1 }, {  96, 224, 192, 1 }, { 224, 224, 224, 1 },
  {  64, 192, 128, 1 }, {  64,  96,   0, 1 }, { 128, 160,   0, 1 }, { 192, 224,   0, 1 },
  {  64,   0,   0, 1 }, {  96,  32,  32, 1 }, { 160, 128,  64, 1 }, { 224, 192,  96, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 }, { advacolor,    0, 64 }, { advacolor2,    0, 64 },
  { gamecolor, 0, 16 }, { zone1colorb, 16, 48 }, { zone1colorb0, 16, 48 }
};
unsigned char col1a0cnt[8] = { 49, 3, 8, 0, 8, 1, 8, 2 };
PALETTEENTRY col1a0col[3] = {
  { 160, 224, 224, 1 },
  {  96, 224, 192, 1 },
  {  10, 192,  50, 1 }
};
unsigned char col1a1cnt[8] = { 50, 3, 8, 0, 8, 1, 8, 2 };
PALETTEENTRY col1a1col[3] = {
  {  64, 192, 128, 1 },
  { 160, 224, 224, 1 },
  {  96, 224, 192, 1 }
};
unsigned char col1a2cnt[8] = { 51, 3, 8, 0, 8, 1, 8, 2 };
PALETTEENTRY col1a2col[3] = {
  {  96, 224, 192, 1 },
  {  64, 192, 128, 1 },
  { 160, 224, 224, 1 }
};
unsigned char col1a3cnt[8] = { 44, 3, 6, 0, 6, 1, 6, 2 };
PALETTEENTRY col1a3col[3] = {
  { 192, 224, 224, 1 },
  {  96, 224, 192, 1 },
  {  64, 192, 128, 1 }
};
unsigned char col1a4cnt[8] = { 45, 3, 6, 0, 6, 1, 6, 2 };
PALETTEENTRY col1a4col[3] = {
  {  96, 224, 192, 1 },
  {  64, 192, 128, 1 },
  { 192, 224, 224, 1 }
};
unsigned char col1a5cnt[8] = { 47, 3, 6, 0, 6, 1, 6, 2 };
PALETTEENTRY col1a5col[3] = {
  {  64, 192, 128, 1 },
  { 192, 224, 224, 1 },
  {  96, 224, 192, 1 }
};
static int FadeCount;

void clchgctr() { /* Line 147, Address: 0x1024d50 */

  colchg11b(); /* Line 149, Address: 0x1024d58 */

} /* Line 151, Address: 0x1024d60 */





void colchg11b() { /* Line 157, Address: 0x1024d70 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col1a0cnt, col1a0col); /* Line 158, Address: 0x1024d78 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col1a1cnt, col1a1col); /* Line 159, Address: 0x1024da0 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col1a2cnt, col1a2col); /* Line 160, Address: 0x1024dc8 */
  clchg_sub0(&clchgtim[3], &clchgcnt[3], col1a3cnt, col1a3col); /* Line 161, Address: 0x1024df0 */
  clchg_sub0(&clchgtim[4], &clchgcnt[4], col1a4cnt, col1a4col); /* Line 162, Address: 0x1024e18 */
  clchg_sub0(&clchgtim[5], &clchgcnt[5], col1a5cnt, col1a5col); /* Line 163, Address: 0x1024e40 */

} /* Line 165, Address: 0x1024e68 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 175, Address: 0x1024e80 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 178, Address: 0x1024e98 */
  if ((char)*pChgTime < 0) { /* Line 179, Address: 0x1024eac */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 181, Address: 0x1024ecc */
    ++*pChgCnt; /* Line 182, Address: 0x1024ef0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 183, Address: 0x1024f04 */

      *pChgCnt = 0; /* Line 185, Address: 0x1024f30 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 188, Address: 0x1024f38 */
    *pChgTime = pCntTbl[0]; /* Line 189, Address: 0x1024f54 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 190, Address: 0x1024f64 */
  }
} /* Line 192, Address: 0x1024f9c */


void fadein0() { /* Line 195, Address: 0x1024fb0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 199, Address: 0x1024fbc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 201, Address: 0x1024ff0 */
    lpPe->peRed = 0; /* Line 202, Address: 0x1024ffc */
    lpPe->peGreen = 0; /* Line 203, Address: 0x1025000 */
    lpPe->peBlue = 0; /* Line 204, Address: 0x1025004 */
    lpPe->peFlags = 1; /* Line 205, Address: 0x1025008 */
    ++lpPe; /* Line 206, Address: 0x1025010 */
  } /* Line 207, Address: 0x1025014 */
  FadeCount = 0; /* Line 208, Address: 0x1025030 */
  *lpFadeFlag = 1; /* Line 209, Address: 0x1025038 */

} /* Line 211, Address: 0x1025048 */



int fadein0_new() { /* Line 215, Address: 0x1025060 */

  int_flg = 18; /* Line 217, Address: 0x1025068 */

  fadein1(); /* Line 219, Address: 0x1025074 */


  if (++FadeCount > 21) { /* Line 222, Address: 0x102507c */
    FadeCount = 0; /* Line 223, Address: 0x102509c */
    return 1; /* Line 224, Address: 0x10250a4 */
  }
  return 0; /* Line 226, Address: 0x10250b0 */
} /* Line 227, Address: 0x10250b4 */



static void fadein1() { /* Line 231, Address: 0x10250d0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 235, Address: 0x10250e4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 236, Address: 0x1025118 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 238, Address: 0x102514c */
    fadein2(lpPe, lpPe2); /* Line 239, Address: 0x1025158 */
    ++lpPe; /* Line 240, Address: 0x1025168 */
    ++lpPe2; /* Line 241, Address: 0x102516c */
  } /* Line 242, Address: 0x1025170 */
  if (stageno.b.h == 1) return; /* Line 243, Address: 0x102518c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 245, Address: 0x10251a8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 246, Address: 0x10251dc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 248, Address: 0x1025210 */
    fadein2(lpPe, lpPe2); /* Line 249, Address: 0x102521c */
    ++lpPe; /* Line 250, Address: 0x102522c */
    ++lpPe2; /* Line 251, Address: 0x1025230 */
  } /* Line 252, Address: 0x1025234 */



} /* Line 256, Address: 0x1025250 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 260, Address: 0x1025270 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 261, Address: 0x102527c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 264, Address: 0x10252dc */
      lpPeDest->peBlue += 32; /* Line 265, Address: 0x1025300 */
    } /* Line 266, Address: 0x1025310 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 267, Address: 0x1025318 */
      lpPeDest->peGreen += 32; /* Line 268, Address: 0x102533c */
    } /* Line 269, Address: 0x102534c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 270, Address: 0x1025354 */
      lpPeDest->peRed += 32; /* Line 271, Address: 0x1025378 */
    }
  }

} /* Line 275, Address: 0x102538c */


void fadeout() {
  startcolor = 0; /* Line 279, Address: 0x10253a0 */
  colorcnt = 63; /* Line 280, Address: 0x10253a8 */

  FadeCount = 0; /* Line 282, Address: 0x10253b4 */
  *lpFadeFlag = 2; /* Line 283, Address: 0x10253bc */

} /* Line 285, Address: 0x10253cc */



static int fadeout_new() { /* Line 289, Address: 0x10253e0 */

  int_flg = 18; /* Line 291, Address: 0x10253e8 */

  fadeout1(); /* Line 293, Address: 0x10253f4 */


  if (++FadeCount > 21) { /* Line 296, Address: 0x10253fc */
    FadeCount = 0; /* Line 297, Address: 0x102541c */
    return 1; /* Line 298, Address: 0x1025424 */
  }
  return 0; /* Line 300, Address: 0x1025430 */
} /* Line 301, Address: 0x1025434 */


static void fadeout1() { /* Line 304, Address: 0x1025450 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 308, Address: 0x1025460 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 310, Address: 0x1025494 */
    fadeout2(lpPe); /* Line 311, Address: 0x10254a0 */
    ++lpPe; /* Line 312, Address: 0x10254ac */
  } /* Line 313, Address: 0x10254b0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 314, Address: 0x10254cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 316, Address: 0x1025500 */
    fadeout2(lpPe); /* Line 317, Address: 0x102550c */
    ++lpPe; /* Line 318, Address: 0x1025518 */
  } /* Line 319, Address: 0x102551c */


} /* Line 322, Address: 0x1025538 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 325, Address: 0x1025550 */
  if (lpPeDest->peRed) { /* Line 326, Address: 0x1025558 */
    lpPeDest->peRed -= 32; /* Line 327, Address: 0x1025568 */
  } /* Line 328, Address: 0x102557c */
  else if (lpPeDest->peGreen) { /* Line 329, Address: 0x1025584 */
    lpPeDest->peGreen -= 32; /* Line 330, Address: 0x1025594 */
  } /* Line 331, Address: 0x10255a4 */
  else if (lpPeDest->peBlue) { /* Line 332, Address: 0x10255ac */
    lpPeDest->peBlue -= 32; /* Line 333, Address: 0x10255bc */
  }

} /* Line 336, Address: 0x10255cc */




void flashin() { /* Line 341, Address: 0x10255e0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 345, Address: 0x10255ec */
  colorcnt = 63; /* Line 346, Address: 0x10255f4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 348, Address: 0x1025600 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 350, Address: 0x1025634 */
    lpPe->peRed = 224; /* Line 351, Address: 0x1025640 */
    lpPe->peGreen = 224; /* Line 352, Address: 0x1025648 */
    lpPe->peBlue = 224; /* Line 353, Address: 0x1025650 */
    lpPe->peFlags = 1; /* Line 354, Address: 0x1025658 */
    ++lpPe; /* Line 355, Address: 0x1025660 */
  } /* Line 356, Address: 0x1025664 */
  FadeCount = 0; /* Line 357, Address: 0x1025680 */
  *lpFadeFlag = 3; /* Line 358, Address: 0x1025688 */

} /* Line 360, Address: 0x1025698 */

static int flashin_new() { /* Line 362, Address: 0x10256b0 */

  int_flg = 18; /* Line 364, Address: 0x10256b8 */

  flashin1(); /* Line 366, Address: 0x10256c4 */


  if (++FadeCount > 21) { /* Line 369, Address: 0x10256cc */
    FadeCount = 0; /* Line 370, Address: 0x10256ec */
    return 1; /* Line 371, Address: 0x10256f4 */
  }
  return 0; /* Line 373, Address: 0x1025700 */
} /* Line 374, Address: 0x1025704 */

static void flashin1() { /* Line 376, Address: 0x1025720 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 380, Address: 0x1025734 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 381, Address: 0x1025768 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 383, Address: 0x102579c */
    flashin2(lpPe, lpPe2); /* Line 384, Address: 0x10257a8 */
    ++lpPe; /* Line 385, Address: 0x10257b8 */
    ++lpPe2; /* Line 386, Address: 0x10257bc */
  } /* Line 387, Address: 0x10257c0 */
  if (stageno.b.h == 1) return; /* Line 388, Address: 0x10257dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 390, Address: 0x10257f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 391, Address: 0x102582c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 393, Address: 0x1025860 */
    flashin2(lpPe, lpPe2); /* Line 394, Address: 0x102586c */
    ++lpPe; /* Line 395, Address: 0x102587c */
    ++lpPe2; /* Line 396, Address: 0x1025880 */
  } /* Line 397, Address: 0x1025884 */



} /* Line 401, Address: 0x10258a0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 405, Address: 0x10258c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 406, Address: 0x10258cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 409, Address: 0x102592c */
      lpPeDest->peBlue -= 32; /* Line 410, Address: 0x1025950 */
    } /* Line 411, Address: 0x1025960 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 412, Address: 0x1025968 */
      lpPeDest->peGreen -= 32; /* Line 413, Address: 0x102598c */
    } /* Line 414, Address: 0x102599c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 415, Address: 0x10259a4 */
      lpPeDest->peRed -= 32; /* Line 416, Address: 0x10259c8 */
    }
  }

} /* Line 420, Address: 0x10259dc */


void flashout() {
  startcolor = 0; /* Line 424, Address: 0x10259f0 */
  colorcnt = 63; /* Line 425, Address: 0x10259f8 */

  FadeCount = 0; /* Line 427, Address: 0x1025a04 */
  *lpFadeFlag = 4; /* Line 428, Address: 0x1025a0c */

} /* Line 430, Address: 0x1025a1c */

static int flashout_new() { /* Line 432, Address: 0x1025a30 */

  int_flg = 18; /* Line 434, Address: 0x1025a38 */

  flashout1(); /* Line 436, Address: 0x1025a44 */


  if (++FadeCount > 21) { /* Line 439, Address: 0x1025a4c */
    FadeCount = 0; /* Line 440, Address: 0x1025a6c */
    return 1; /* Line 441, Address: 0x1025a74 */
  }
  return 0; /* Line 443, Address: 0x1025a80 */
} /* Line 444, Address: 0x1025a84 */


static void flashout1() { /* Line 447, Address: 0x1025aa0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 451, Address: 0x1025ab0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 453, Address: 0x1025ae4 */
    flashout2(lpPe); /* Line 454, Address: 0x1025af0 */
    ++lpPe; /* Line 455, Address: 0x1025afc */
  } /* Line 456, Address: 0x1025b00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 457, Address: 0x1025b1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 459, Address: 0x1025b50 */
    flashout2(lpPe); /* Line 460, Address: 0x1025b5c */
    ++lpPe; /* Line 461, Address: 0x1025b68 */
  } /* Line 462, Address: 0x1025b6c */


} /* Line 465, Address: 0x1025b88 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 468, Address: 0x1025ba0 */
  if (lpPeDest->peRed != 224) { /* Line 469, Address: 0x1025ba8 */
    lpPeDest->peRed += 32; /* Line 470, Address: 0x1025bc0 */
  } /* Line 471, Address: 0x1025bd4 */
  else if (lpPeDest->peGreen != 224) { /* Line 472, Address: 0x1025bdc */
    lpPeDest->peGreen += 32; /* Line 473, Address: 0x1025bf4 */
  } /* Line 474, Address: 0x1025c04 */
  else if (lpPeDest->peBlue != 224) { /* Line 475, Address: 0x1025c0c */
    lpPeDest->peBlue += 32; /* Line 476, Address: 0x1025c24 */
  }


} /* Line 480, Address: 0x1025c34 */


void colorset(int ColorNo) { /* Line 483, Address: 0x1025c40 */
  colorset00(ColorNo, 1); /* Line 484, Address: 0x1025c4c */
} /* Line 485, Address: 0x1025c5c */

void colorset2(int ColorNo) { /* Line 487, Address: 0x1025c70 */
  colorset00(ColorNo, 0); /* Line 488, Address: 0x1025c7c */
} /* Line 489, Address: 0x1025c8c */

void colorset3(int ColorNo) { /* Line 491, Address: 0x1025ca0 */
  colorset00(ColorNo, 0); /* Line 492, Address: 0x1025cac */
} /* Line 493, Address: 0x1025cbc */





void colorset00(int ColorNo, int WorkOffs) { /* Line 499, Address: 0x1025cd0 */
  PALETTEENTRY *lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 504, Address: 0x1025cf0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 506, Address: 0x1025d58 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 508, Address: 0x1025d68 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 510, Address: 0x1025d78 */
    default:
      lppe = lpcolorwk4; break; /* Line 512, Address: 0x1025d88 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 515, Address: 0x1025d90 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 516, Address: 0x1025da8 */
  n = colortbl[ColorNo].cnt; /* Line 517, Address: 0x1025dd0 */
  for (i = 0; i < n; ++i) { /* Line 518, Address: 0x1025df0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 519, Address: 0x1025dfc */
  } /* Line 520, Address: 0x1025e2c */

} /* Line 522, Address: 0x1025e3c */




int FadeProc() { /* Line 527, Address: 0x1025e60 */
  switch (*lpFadeFlag) { /* Line 528, Address: 0x1025e68 */
    case 1:
      return fadein0_new(); /* Line 530, Address: 0x1025eac */
    case 2:
      return fadeout_new(); /* Line 532, Address: 0x1025ebc */
    case 3:
      return flashin_new(); /* Line 534, Address: 0x1025ecc */
    case 4:
      return flashout_new(); /* Line 536, Address: 0x1025edc */
  }
  return 1; /* Line 538, Address: 0x1025eec */

} /* Line 540, Address: 0x1025ef0 */
