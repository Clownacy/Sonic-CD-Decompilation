#include "..\EQU.H"
#include "COL8B.H"

static void fadein1(void);
static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int fadeout_new(void);
static void fadeout1(void);
static void fadeout2(PALETTEENTRY* lpPeDest);
static int flashin_new(void);
static void flashin1(void);
static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int flashout_new(void);
static void flashout1(void);
static void flashout2(PALETTEENTRY* lpPeDest);
static void colorset00(int ColorNo, int WorkOffs);

unsigned char col8a0cnt[8] = { 38, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a0col[3] = {
  {  96, 224, 224, 1 }, {   0, 160, 192, 1 }, {   0,  96, 160, 1 }
};
unsigned char col8a1cnt[8] = { 39, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a1col[3] = {
  {   0, 160, 192, 1 }, {   0,  96, 160, 1 }, {  96, 224, 224, 1 }
};
unsigned char col8a2cnt[8] = { 40, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a2col[3] = {
  {   0,  96, 160, 1 }, {  96, 224, 224, 1 }, {   0, 160, 192, 1 }
};
unsigned char col8a3cnt[18] = { 62, 8, 99, 0, 2, 1, 2, 0, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1 };
PALETTEENTRY col8a3col[3] = {
  {   0, 192, 192, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }
};
unsigned char col8a4cnt[6] = { 63, 2, 15, 0, 15, 1 };
PALETTEENTRY col8a4col[2] = {
  {   0, 224,   0, 1 }, { 224, 224,   0, 1 }
};
unsigned char col8a5cnt[16] = { 49, 7, 22, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 33, 0 };
PALETTEENTRY col8a5col[2] = {
  { 0, 0, 0, 1 },
  { 224, 224, 224, 1 }
};
unsigned char col8a6cnt[14] = { 50, 6, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 55, 1 };
PALETTEENTRY col8a6col[2] = {
  { 224, 224, 224, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY advacolor[64] = {
  {   0,  32, 160, 1 }, {   0,   0,  96, 1 }, {   0,   0, 192, 1 }, {  64,  64, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 224, 160,   0, 1 },
  { 160,  96,   0, 1 }, {  96,  32,   0, 1 }, { 224, 224,   0, 1 }, { 160, 160, 224, 1 },
  { 192,   0,   0, 1 }, {  96,   0,   0, 1 }, {  32,   0,   0, 1 }, {   0,   0,   0, 1 },
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
  {  96,  32, 128, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone8colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  96,  32, 128, 1 }, {  32,   0,  32, 1 }, {   0, 128,  64, 1 }, {   0, 192, 128, 1 },
  {  64, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 160,  96, 1 }, { 192,  96,  64, 1 },
  { 160,  32,  32, 1 }, { 224,   0, 128, 1 }, { 224, 128,   0, 1 }, { 224, 192,  64, 1 },
  {  96,  64,  96, 1 }, { 128,  96, 224, 1 }, {  32, 192, 224, 1 }, {  96, 224, 224, 1 },
  {  96,  32, 128, 1 }, { 160,  32, 128, 1 }, { 224,  64,  96, 1 }, { 224, 192,  32, 1 },
  {   0,   0,  96, 1 }, {   0,  32, 192, 1 }, {   0,  96, 224, 1 }, {   0,   0,  64, 1 },
  {  64,   0,  96, 1 }, { 192,  32, 128, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 },
  {  32,   0,   0, 1 }, { 192,   0,  64, 1 }, {   0, 192, 192, 1 }, {   0, 224,   0, 1 }
};
PALETTEENTRY zone8colorb[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  64,   0, 160, 1 }, {  32,   0,  32, 1 }, {   0, 128,  64, 1 }, {   0, 192, 128, 1 },
  {  64, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 160,  96, 1 }, { 192,  96,  64, 1 },
  { 160,  32,  32, 1 }, { 224,   0, 128, 1 }, { 224, 128,   0, 1 }, { 224, 192,  64, 1 },
  {  96,  64,  96, 1 }, { 128,  96, 224, 1 }, {  32, 192, 224, 1 }, {  96, 224, 224, 1 },
  {  96,  32, 128, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, {   0,   0,  64, 1 },
  {   0,   0,   0, 1 }, {  64,  32,   0, 1 }, { 128,  96,   0, 1 }, { 224, 160,   0, 1 },
  {   0,   0,  96, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  {  96,   0, 224, 1 }, {  96,  96, 224, 1 }, { 128, 160, 224, 1 }, { 224, 224, 224, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone8colora, 16, 48 },
  { zone8colorb, 16, 48 }
};
static int FadeCount;













void clchgctr(void) { /* Line 138, Address: 0x10298e0 */
  colchg8b(); /* Line 139, Address: 0x10298e8 */
} /* Line 140, Address: 0x10298f0 */

void colchg8b(void) { /* Line 142, Address: 0x1029900 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col8a0cnt, col8a0col); /* Line 143, Address: 0x1029908 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col8a1cnt, col8a1col); /* Line 144, Address: 0x1029930 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col8a2cnt, col8a2col); /* Line 145, Address: 0x1029958 */
  if (stageno.b.l != 1) { /* Line 146, Address: 0x1029980 */

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a3cnt, col8a3col); /* Line 148, Address: 0x102999c */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a4cnt, col8a4col); /* Line 149, Address: 0x10299c4 */
  } /* Line 150, Address: 0x10299ec */
  else {

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a5cnt, col8a5col); /* Line 153, Address: 0x10299f4 */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a6cnt, col8a6col); /* Line 154, Address: 0x1029a1c */
  }

} /* Line 157, Address: 0x1029a44 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 166, Address: 0x1029a60 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 169, Address: 0x1029a78 */
  if ((char)*pChgTime < 0) { /* Line 170, Address: 0x1029a8c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 172, Address: 0x1029aac */
    ++*pChgCnt; /* Line 173, Address: 0x1029ad0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 174, Address: 0x1029ae4 */

      *pChgCnt = 0; /* Line 176, Address: 0x1029b10 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 179, Address: 0x1029b18 */
    *pChgTime = pCntTbl[0]; /* Line 180, Address: 0x1029b34 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 181, Address: 0x1029b44 */
  }





} /* Line 188, Address: 0x1029b7c */


void fadein0(void) { /* Line 191, Address: 0x1029b90 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 195, Address: 0x1029b9c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 197, Address: 0x1029bd0 */
    lpPe->peRed = 0; /* Line 198, Address: 0x1029bdc */
    lpPe->peGreen = 0; /* Line 199, Address: 0x1029be0 */
    lpPe->peBlue = 0; /* Line 200, Address: 0x1029be4 */
    lpPe->peFlags = 1; /* Line 201, Address: 0x1029be8 */
    ++lpPe; /* Line 202, Address: 0x1029bf0 */
  } /* Line 203, Address: 0x1029bf4 */
  FadeCount = 0; /* Line 204, Address: 0x1029c10 */
  *lpFadeFlag = 1; /* Line 205, Address: 0x1029c18 */

} /* Line 207, Address: 0x1029c28 */



int fadein0_new(void) { /* Line 211, Address: 0x1029c40 */

  int_flg = 18; /* Line 213, Address: 0x1029c48 */

  fadein1(); /* Line 215, Address: 0x1029c54 */


  if (++FadeCount > 21) { /* Line 218, Address: 0x1029c5c */
    FadeCount = 0; /* Line 219, Address: 0x1029c7c */
    return 1; /* Line 220, Address: 0x1029c84 */
  }
  return 0; /* Line 222, Address: 0x1029c90 */
} /* Line 223, Address: 0x1029c94 */



static void fadein1(void) { /* Line 227, Address: 0x1029cb0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 231, Address: 0x1029cc4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 232, Address: 0x1029cf8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 234, Address: 0x1029d2c */
    fadein2(lpPe, lpPe2); /* Line 235, Address: 0x1029d38 */
    ++lpPe; /* Line 236, Address: 0x1029d48 */
    ++lpPe2; /* Line 237, Address: 0x1029d4c */
  } /* Line 238, Address: 0x1029d50 */
  if (stageno.b.h == 1) return; /* Line 239, Address: 0x1029d6c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 241, Address: 0x1029d88 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 242, Address: 0x1029dbc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 244, Address: 0x1029df0 */
    fadein2(lpPe, lpPe2); /* Line 245, Address: 0x1029dfc */
    ++lpPe; /* Line 246, Address: 0x1029e0c */
    ++lpPe2; /* Line 247, Address: 0x1029e10 */
  } /* Line 248, Address: 0x1029e14 */



} /* Line 252, Address: 0x1029e30 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 256, Address: 0x1029e50 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 257, Address: 0x1029e5c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 260, Address: 0x1029ebc */
      lpPeDest->peBlue += 32; /* Line 261, Address: 0x1029ee0 */
    } /* Line 262, Address: 0x1029ef0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 263, Address: 0x1029ef8 */
      lpPeDest->peGreen += 32; /* Line 264, Address: 0x1029f1c */
    } /* Line 265, Address: 0x1029f2c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 266, Address: 0x1029f34 */
      lpPeDest->peRed += 32; /* Line 267, Address: 0x1029f58 */
    }
  }

} /* Line 271, Address: 0x1029f6c */


void fadeout(void) {
  startcolor = 0; /* Line 275, Address: 0x1029f80 */
  colorcnt = 63; /* Line 276, Address: 0x1029f88 */

  FadeCount = 0; /* Line 278, Address: 0x1029f94 */
  *lpFadeFlag = 2; /* Line 279, Address: 0x1029f9c */

} /* Line 281, Address: 0x1029fac */



static int fadeout_new(void) { /* Line 285, Address: 0x1029fc0 */

  int_flg = 18; /* Line 287, Address: 0x1029fc8 */

  fadeout1(); /* Line 289, Address: 0x1029fd4 */


  if (++FadeCount > 21) { /* Line 292, Address: 0x1029fdc */
    FadeCount = 0; /* Line 293, Address: 0x1029ffc */
    return 1; /* Line 294, Address: 0x102a004 */
  }
  return 0; /* Line 296, Address: 0x102a010 */
} /* Line 297, Address: 0x102a014 */


static void fadeout1(void) { /* Line 300, Address: 0x102a030 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 304, Address: 0x102a040 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 306, Address: 0x102a074 */
    fadeout2(lpPe); /* Line 307, Address: 0x102a080 */
    ++lpPe; /* Line 308, Address: 0x102a08c */
  } /* Line 309, Address: 0x102a090 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 310, Address: 0x102a0ac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 312, Address: 0x102a0e0 */
    fadeout2(lpPe); /* Line 313, Address: 0x102a0ec */
    ++lpPe; /* Line 314, Address: 0x102a0f8 */
  } /* Line 315, Address: 0x102a0fc */


} /* Line 318, Address: 0x102a118 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 321, Address: 0x102a130 */
  if (lpPeDest->peRed) { /* Line 322, Address: 0x102a138 */
    lpPeDest->peRed -= 32; /* Line 323, Address: 0x102a148 */
  } /* Line 324, Address: 0x102a15c */
  else if (lpPeDest->peGreen) { /* Line 325, Address: 0x102a164 */
    lpPeDest->peGreen -= 32; /* Line 326, Address: 0x102a174 */
  } /* Line 327, Address: 0x102a184 */
  else if (lpPeDest->peBlue) { /* Line 328, Address: 0x102a18c */
    lpPeDest->peBlue -= 32; /* Line 329, Address: 0x102a19c */
  }

} /* Line 332, Address: 0x102a1ac */




void flashin(void) { /* Line 337, Address: 0x102a1c0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 341, Address: 0x102a1cc */
  colorcnt = 63; /* Line 342, Address: 0x102a1d4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 344, Address: 0x102a1e0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 346, Address: 0x102a214 */
    lpPe->peRed = 224; /* Line 347, Address: 0x102a220 */
    lpPe->peGreen = 224; /* Line 348, Address: 0x102a228 */
    lpPe->peBlue = 224; /* Line 349, Address: 0x102a230 */
    lpPe->peFlags = 1; /* Line 350, Address: 0x102a238 */
    ++lpPe; /* Line 351, Address: 0x102a240 */
  } /* Line 352, Address: 0x102a244 */
  FadeCount = 0; /* Line 353, Address: 0x102a260 */
  *lpFadeFlag = 3; /* Line 354, Address: 0x102a268 */

} /* Line 356, Address: 0x102a278 */

static int flashin_new(void) { /* Line 358, Address: 0x102a290 */

  int_flg = 18; /* Line 360, Address: 0x102a298 */

  flashin1(); /* Line 362, Address: 0x102a2a4 */


  if (++FadeCount > 21) { /* Line 365, Address: 0x102a2ac */
    FadeCount = 0; /* Line 366, Address: 0x102a2cc */
    return 1; /* Line 367, Address: 0x102a2d4 */
  }
  return 0; /* Line 369, Address: 0x102a2e0 */
} /* Line 370, Address: 0x102a2e4 */

static void flashin1(void) { /* Line 372, Address: 0x102a300 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 376, Address: 0x102a314 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 377, Address: 0x102a348 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 379, Address: 0x102a37c */
    flashin2(lpPe, lpPe2); /* Line 380, Address: 0x102a388 */
    ++lpPe; /* Line 381, Address: 0x102a398 */
    ++lpPe2; /* Line 382, Address: 0x102a39c */
  } /* Line 383, Address: 0x102a3a0 */
  if (stageno.b.h == 1) return; /* Line 384, Address: 0x102a3bc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 386, Address: 0x102a3d8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 387, Address: 0x102a40c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 389, Address: 0x102a440 */
    flashin2(lpPe, lpPe2); /* Line 390, Address: 0x102a44c */
    ++lpPe; /* Line 391, Address: 0x102a45c */
    ++lpPe2; /* Line 392, Address: 0x102a460 */
  } /* Line 393, Address: 0x102a464 */



} /* Line 397, Address: 0x102a480 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 401, Address: 0x102a4a0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 402, Address: 0x102a4ac */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 405, Address: 0x102a50c */
      lpPeDest->peBlue -= 32; /* Line 406, Address: 0x102a530 */
    } /* Line 407, Address: 0x102a540 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 408, Address: 0x102a548 */
      lpPeDest->peGreen -= 32; /* Line 409, Address: 0x102a56c */
    } /* Line 410, Address: 0x102a57c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 411, Address: 0x102a584 */
      lpPeDest->peRed -= 32; /* Line 412, Address: 0x102a5a8 */
    }
  }

} /* Line 416, Address: 0x102a5bc */


void flashout(void) {
  startcolor = 0; /* Line 420, Address: 0x102a5d0 */
  colorcnt = 63; /* Line 421, Address: 0x102a5d8 */

  FadeCount = 0; /* Line 423, Address: 0x102a5e4 */
  *lpFadeFlag = 4; /* Line 424, Address: 0x102a5ec */

} /* Line 426, Address: 0x102a5fc */

static int flashout_new(void) { /* Line 428, Address: 0x102a610 */

  int_flg = 18; /* Line 430, Address: 0x102a618 */

  flashout1(); /* Line 432, Address: 0x102a624 */


  if (++FadeCount > 21) { /* Line 435, Address: 0x102a62c */
    FadeCount = 0; /* Line 436, Address: 0x102a64c */
    return 1; /* Line 437, Address: 0x102a654 */
  }
  return 0; /* Line 439, Address: 0x102a660 */
} /* Line 440, Address: 0x102a664 */


static void flashout1(void) { /* Line 443, Address: 0x102a680 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 447, Address: 0x102a690 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 449, Address: 0x102a6c4 */
    flashout2(lpPe); /* Line 450, Address: 0x102a6d0 */
    ++lpPe; /* Line 451, Address: 0x102a6dc */
  } /* Line 452, Address: 0x102a6e0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 453, Address: 0x102a6fc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 455, Address: 0x102a730 */
    flashout2(lpPe); /* Line 456, Address: 0x102a73c */
    ++lpPe; /* Line 457, Address: 0x102a748 */
  } /* Line 458, Address: 0x102a74c */


} /* Line 461, Address: 0x102a768 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 464, Address: 0x102a780 */
  if (lpPeDest->peRed != 224) { /* Line 465, Address: 0x102a788 */
    lpPeDest->peRed += 32; /* Line 466, Address: 0x102a7a0 */
  } /* Line 467, Address: 0x102a7b4 */
  else if (lpPeDest->peGreen != 224) { /* Line 468, Address: 0x102a7bc */
    lpPeDest->peGreen += 32; /* Line 469, Address: 0x102a7d4 */
  } /* Line 470, Address: 0x102a7e4 */
  else if (lpPeDest->peBlue != 224) { /* Line 471, Address: 0x102a7ec */
    lpPeDest->peBlue += 32; /* Line 472, Address: 0x102a804 */
  }


} /* Line 476, Address: 0x102a814 */


void colorset(int ColorNo) { /* Line 479, Address: 0x102a820 */
  colorset00(ColorNo, 1); /* Line 480, Address: 0x102a82c */
} /* Line 481, Address: 0x102a83c */

void colorset2(int ColorNo) { /* Line 483, Address: 0x102a850 */
  colorset00(ColorNo, 0); /* Line 484, Address: 0x102a85c */
} /* Line 485, Address: 0x102a86c */

void colorset3(int ColorNo) { /* Line 487, Address: 0x102a880 */
  colorset00(ColorNo, 0); /* Line 488, Address: 0x102a88c */
} /* Line 489, Address: 0x102a89c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 495, Address: 0x102a8b0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 500, Address: 0x102a8d0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 502, Address: 0x102a938 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 504, Address: 0x102a948 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 506, Address: 0x102a958 */
    default:
      lppe = lpcolorwk4; break; /* Line 508, Address: 0x102a968 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 511, Address: 0x102a970 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 512, Address: 0x102a988 */
  n = colortbl[ColorNo].cnt; /* Line 513, Address: 0x102a9b0 */
  for (i = 0; i < n; ++i) { /* Line 514, Address: 0x102a9d0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 515, Address: 0x102a9dc */
  } /* Line 516, Address: 0x102aa0c */

} /* Line 518, Address: 0x102aa1c */




int FadeProc(void) { /* Line 523, Address: 0x102aa40 */
  switch (*lpFadeFlag) { /* Line 524, Address: 0x102aa48 */
    case 1:
      return fadein0_new(); /* Line 526, Address: 0x102aa8c */
    case 2:
      return fadeout_new(); /* Line 528, Address: 0x102aa9c */
    case 3:
      return flashin_new(); /* Line 530, Address: 0x102aaac */
    case 4:
      return flashout_new(); /* Line 532, Address: 0x102aabc */
  }
  return 1; /* Line 534, Address: 0x102aacc */

} /* Line 536, Address: 0x102aad0 */
