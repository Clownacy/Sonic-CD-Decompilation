#include "..\EQU.H"
#include "COL5A.H"

typedef struct {
  unsigned char adr;
  unsigned char tate;
  unsigned char yoko;
  unsigned char time;
  PALETTEENTRY colortbl[60];
}
color_change_data;

static void colchgsub(unsigned char** ppChgTime, unsigned char** ppChgCnt, color_change_data* pColortbl);
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone5color0[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  { 128, 128, 224, 1 }, { 160,   0,  96, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224,  64, 128, 1 }, { 224, 128, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,  32, 1 }, {  96,  96, 128, 1 },
  {  32,  32,  64, 1 }, { 224, 224,  64, 1 }, { 224, 128,  64, 1 }, { 128,  32,  32, 1 },
  {  64,   0,   0, 1 }, {   0,  64,  32, 1 }, { 128,  96, 160, 1 }, { 192, 160, 224, 1 },
  {  64,  32, 128, 1 }, {  96, 224, 192, 1 }, {  64, 192, 128, 1 }, {  32, 128,  96, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 160,  32, 128, 1 },
  {  96,   0,  96, 1 }, {  32,   0,  32, 1 }, { 192, 224,   0, 1 }, { 224, 160,   0, 1 },
  { 224,  96,  96, 1 }, {   0,   0,   0, 1 }, {   0, 160, 224, 1 }, {   0,  96, 160, 1 },
  {   0,  64, 128, 1 }, {   0,  32,  96, 1 }, {   0,   0,  64, 1 }, {  32,   0,   0, 1 }
};
PALETTEENTRY zone5color1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  { 128, 128, 224, 1 }, { 160,   0,  96, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224,  64, 128, 1 }, { 224, 128, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,  64, 224, 1 }, { 224, 224, 224, 1 }, {   0,   0,  32, 1 }, {  96,  96, 128, 1 },
  {  32,  32,  64, 1 }, { 224, 224,  64, 1 }, { 224, 128,  64, 1 }, { 128,  32,  32, 1 },
  {  64,   0,   0, 1 }, {   0,  64,  32, 1 }, { 128,  96, 160, 1 }, { 192, 160, 224, 1 },
  {  64,  32, 128, 1 }, {  96, 224, 192, 1 }, {  64, 192, 128, 1 }, {  32, 128,  96, 1 },
  {   0,  64, 224, 1 }, {  64,  96, 224, 1 }, {  96, 160, 224, 1 }, { 160, 192, 224, 1 },
  { 192, 224, 224, 1 }, {   0,  32,   0, 1 }, {   0,  96,   0, 1 }, {   0, 160,   0, 1 },
  {   0,   0, 160, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 }, {   0,   0,   0, 1 },
  {   0,   0,  32, 1 }, {  96,   0,  32, 1 }, { 160,  64,  32, 1 }, { 192, 128,  32, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone5color0, 16, 48 },
  { zone5color1, 16, 48 }
};
static int FadeCount;









































































void clchgctr(void) { /* Line 179, Address: 0x1016910 */
  unsigned char *pChgTime, *pChgCnt;
  color_change_data colchg50 = { /* Line 181, Address: 0x1016918 */
    42, 3, 3, 4,
    {
      { 128,  96, 160, 1 }, { 192, 160, 224, 1 }, {  64,  32, 128, 1 }, {  64,  32, 128, 1 }, { 128,  96, 160, 1 },
      { 192, 160, 224, 1 }, { 192, 160, 224, 1 }, {  64,  32, 128, 1 }, { 128,  96, 160, 1 }
    }
  };

  color_change_data colchg51 = { /* Line 189, Address: 0x101694c */
    58, 12, 5, 5,
    {
      {   0, 160, 224, 1 }, {   0,  96, 160, 1 }, {   0,  64, 128, 1 }, {   0,  32,  96, 1 }, {   0,   0,  64, 1 },
      {  32, 160, 224, 1 }, {  32,  96, 160, 1 }, {  32,  64, 128, 1 }, {  32,  32,  96, 1 }, {  32,   0,  64, 1 },
      {  64, 160, 224, 1 }, {  64,  96, 160, 1 }, {  64,  64, 128, 1 }, {  64,  32,  96, 1 }, {  64,   0,  64, 1 },
      {  96, 160, 224, 1 }, {  96,  96, 160, 1 }, {  96,  64, 128, 1 }, {  96,  32,  96, 1 }, {  96,   0,  64, 1 },
      { 128, 160, 224, 1 }, { 128,  96, 160, 1 }, { 128,  64, 128, 1 }, { 128,  32,  96, 1 }, { 128,   0,  64, 1 },
      { 160, 160, 224, 1 }, { 160,  96, 160, 1 }, { 160,  64, 128, 1 }, { 160,  32,  96, 1 }, { 160,   0,  64, 1 },
      { 160, 160, 224, 1 }, { 160,  96, 160, 1 }, { 160,  64, 128, 1 }, { 160,  32,  96, 1 }, { 160,   0,  64, 1 },
      { 128, 160, 224, 1 }, { 128,  96, 160, 1 }, { 128,  64, 128, 1 }, { 128,  32,  96, 1 }, { 128,   0,  64, 1 },
      {  96, 160, 224, 1 }, {  96,  96, 160, 1 }, {  96,  64, 128, 1 }, {  96,  32,  96, 1 }, {  96,   0,  64, 1 },
      {  64, 160, 224, 1 }, {  64,  96, 160, 1 }, {  64,  64, 128, 1 }, {  64,  32,  96, 1 }, {  64,   0,  64, 1 },
      {  32, 160, 224, 1 }, {  32,  96, 160, 1 }, {  32,  64, 128, 1 }, {  32,  32,  96, 1 }, {  32,   0,  64, 1 },
      {   0, 160, 224, 1 }, {   0,  96, 160, 1 }, {   0,  64, 128, 1 }, {   0,  32,  96, 1 }, {   0,   0,  64, 1 }
    }
  };

  color_change_data colchg52 = { /* Line 207, Address: 0x1016980 */
    56, 3, 3, 4,
    {
      {   0,   0, 160, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 }, {   0, 160, 224, 1 }, {   0,   0, 160, 1 },
      {   0,  64, 224, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 }, {   0,   0,   0, 1 }
    }
  };

  color_change_data colchg53 = { /* Line 215, Address: 0x10169b4 */
    42, 3, 3, 4,
    {
      { 192,  96,   0, 1 }, { 224, 224,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }, {  64,   0,   0, 1 },
      { 192,  96,   0, 1 }, {  64,   0,   0, 1 }, { 192,  96,   0, 1 }, { 224, 224,   0, 1 }
    }
  };


  pChgTime = clchgtim; /* Line 224, Address: 0x10169e8 */
  pChgCnt = clchgcnt; /* Line 225, Address: 0x10169f4 */


  if (!colrevflag) { /* Line 228, Address: 0x1016a00 */
    colchgsub(&pChgTime, &pChgCnt, &colchg50); /* Line 229, Address: 0x1016a10 */
  } else { /* Line 230, Address: 0x1016a24 */
    colchgsub(&pChgTime, &pChgCnt, &colchg53); /* Line 231, Address: 0x1016a2c */
  }

  if (enkeino & 1) { /* Line 234, Address: 0x1016a40 */
    colchgsub(&pChgTime, &pChgCnt, &colchg52); /* Line 235, Address: 0x1016a58 */
  } /* Line 236, Address: 0x1016a6c */
  else {
    colchgsub(&pChgTime, &pChgCnt, &colchg51); /* Line 238, Address: 0x1016a74 */
  }

} /* Line 241, Address: 0x1016a88 */



static void colchgsub(unsigned char** ppChgTime, unsigned char** ppChgCnt, color_change_data* pColortbl) { /* Line 245, Address: 0x1016aa0 */
  short cnt;
  PALETTEENTRY *pPalet, *pColtbl;
  int i;

  if ((char)--**ppChgTime < 0) { /* Line 250, Address: 0x1016ac0 */
    **ppChgTime = pColortbl->time; /* Line 251, Address: 0x1016af4 */
    if ((cnt = **ppChgCnt + 1) >= pColortbl->tate) { /* Line 252, Address: 0x1016b08 */
      cnt = 0; /* Line 253, Address: 0x1016b54 */
    }


    **ppChgCnt = cnt; /* Line 257, Address: 0x1016b58 */


    cnt *= pColortbl->yoko; /* Line 260, Address: 0x1016b68 */
    pPalet = &lpcolorwk[pColortbl->adr]; /* Line 261, Address: 0x1016b80 */
    pColtbl = &pColortbl->colortbl[cnt]; /* Line 262, Address: 0x1016b9c */

    for (i = 0; i < pColortbl->yoko; ++i) { /* Line 264, Address: 0x1016bb4 */
      *pPalet++ = *pColtbl++; /* Line 265, Address: 0x1016bc0 */
    } /* Line 266, Address: 0x1016bf0 */
  }


  ++*ppChgTime; /* Line 270, Address: 0x1016c0c */
  ++*ppChgCnt; /* Line 271, Address: 0x1016c20 */
} /* Line 272, Address: 0x1016c34 */







void fadein0(void) { /* Line 280, Address: 0x1016c50 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 284, Address: 0x1016c5c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 286, Address: 0x1016c90 */
    lpPe->peRed = 0; /* Line 287, Address: 0x1016c9c */
    lpPe->peGreen = 0; /* Line 288, Address: 0x1016ca0 */
    lpPe->peBlue = 0; /* Line 289, Address: 0x1016ca4 */
    lpPe->peFlags = 1; /* Line 290, Address: 0x1016ca8 */
    ++lpPe; /* Line 291, Address: 0x1016cb0 */
  } /* Line 292, Address: 0x1016cb4 */
  FadeCount = 0; /* Line 293, Address: 0x1016cd0 */
  *lpFadeFlag = 1; /* Line 294, Address: 0x1016cd8 */

} /* Line 296, Address: 0x1016ce8 */



int fadein0_new(void) { /* Line 300, Address: 0x1016d00 */

  int_flg = 18; /* Line 302, Address: 0x1016d08 */

  fadein1(); /* Line 304, Address: 0x1016d14 */


  if (++FadeCount > 21) { /* Line 307, Address: 0x1016d1c */
    FadeCount = 0; /* Line 308, Address: 0x1016d3c */
    return 1; /* Line 309, Address: 0x1016d44 */
  }
  return 0; /* Line 311, Address: 0x1016d50 */
} /* Line 312, Address: 0x1016d54 */



static void fadein1(void) { /* Line 316, Address: 0x1016d70 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 320, Address: 0x1016d84 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 321, Address: 0x1016db8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 323, Address: 0x1016dec */
    fadein2(lpPe, lpPe2); /* Line 324, Address: 0x1016df8 */
    ++lpPe; /* Line 325, Address: 0x1016e08 */
    ++lpPe2; /* Line 326, Address: 0x1016e0c */
  } /* Line 327, Address: 0x1016e10 */
  if (stageno.b.h == 1) return; /* Line 328, Address: 0x1016e2c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 330, Address: 0x1016e48 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 331, Address: 0x1016e7c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 333, Address: 0x1016eb0 */
    fadein2(lpPe, lpPe2); /* Line 334, Address: 0x1016ebc */
    ++lpPe; /* Line 335, Address: 0x1016ecc */
    ++lpPe2; /* Line 336, Address: 0x1016ed0 */
  } /* Line 337, Address: 0x1016ed4 */



} /* Line 341, Address: 0x1016ef0 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 345, Address: 0x1016f10 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 346, Address: 0x1016f1c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 349, Address: 0x1016f7c */
      lpPeDest->peBlue += 32; /* Line 350, Address: 0x1016fa0 */
    } /* Line 351, Address: 0x1016fb0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 352, Address: 0x1016fb8 */
      lpPeDest->peGreen += 32; /* Line 353, Address: 0x1016fdc */
    } /* Line 354, Address: 0x1016fec */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 355, Address: 0x1016ff4 */
      lpPeDest->peRed += 32; /* Line 356, Address: 0x1017018 */
    }
  }

} /* Line 360, Address: 0x101702c */


void fadeout(void) {
  startcolor = 0; /* Line 364, Address: 0x1017040 */
  colorcnt = 63; /* Line 365, Address: 0x1017048 */

  FadeCount = 0; /* Line 367, Address: 0x1017054 */
  *lpFadeFlag = 2; /* Line 368, Address: 0x101705c */

} /* Line 370, Address: 0x101706c */



static int fadeout_new(void) { /* Line 374, Address: 0x1017080 */

  int_flg = 18; /* Line 376, Address: 0x1017088 */

  fadeout1(); /* Line 378, Address: 0x1017094 */


  if (++FadeCount > 21) { /* Line 381, Address: 0x101709c */
    FadeCount = 0; /* Line 382, Address: 0x10170bc */
    return 1; /* Line 383, Address: 0x10170c4 */
  }
  return 0; /* Line 385, Address: 0x10170d0 */
} /* Line 386, Address: 0x10170d4 */


static void fadeout1(void) { /* Line 389, Address: 0x10170f0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 393, Address: 0x1017100 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 395, Address: 0x1017134 */
    fadeout2(lpPe); /* Line 396, Address: 0x1017140 */
    ++lpPe; /* Line 397, Address: 0x101714c */
  } /* Line 398, Address: 0x1017150 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 399, Address: 0x101716c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 401, Address: 0x10171a0 */
    fadeout2(lpPe); /* Line 402, Address: 0x10171ac */
    ++lpPe; /* Line 403, Address: 0x10171b8 */
  } /* Line 404, Address: 0x10171bc */


} /* Line 407, Address: 0x10171d8 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 410, Address: 0x10171f0 */
  if (lpPeDest->peRed) { /* Line 411, Address: 0x10171f8 */
    lpPeDest->peRed -= 32; /* Line 412, Address: 0x1017208 */
  } /* Line 413, Address: 0x101721c */
  else if (lpPeDest->peGreen) { /* Line 414, Address: 0x1017224 */
    lpPeDest->peGreen -= 32; /* Line 415, Address: 0x1017234 */
  } /* Line 416, Address: 0x1017244 */
  else if (lpPeDest->peBlue) { /* Line 417, Address: 0x101724c */
    lpPeDest->peBlue -= 32; /* Line 418, Address: 0x101725c */
  }

} /* Line 421, Address: 0x101726c */




void flashin(void) { /* Line 426, Address: 0x1017280 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 430, Address: 0x101728c */
  colorcnt = 63; /* Line 431, Address: 0x1017294 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 433, Address: 0x10172a0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 435, Address: 0x10172d4 */
    lpPe->peRed = 224; /* Line 436, Address: 0x10172e0 */
    lpPe->peGreen = 224; /* Line 437, Address: 0x10172e8 */
    lpPe->peBlue = 224; /* Line 438, Address: 0x10172f0 */
    lpPe->peFlags = 1; /* Line 439, Address: 0x10172f8 */
    ++lpPe; /* Line 440, Address: 0x1017300 */
  } /* Line 441, Address: 0x1017304 */
  FadeCount = 0; /* Line 442, Address: 0x1017320 */
  *lpFadeFlag = 3; /* Line 443, Address: 0x1017328 */

} /* Line 445, Address: 0x1017338 */

static int flashin_new(void) { /* Line 447, Address: 0x1017350 */

  int_flg = 18; /* Line 449, Address: 0x1017358 */

  flashin1(); /* Line 451, Address: 0x1017364 */


  if (++FadeCount > 21) { /* Line 454, Address: 0x101736c */
    FadeCount = 0; /* Line 455, Address: 0x101738c */
    return 1; /* Line 456, Address: 0x1017394 */
  }
  return 0; /* Line 458, Address: 0x10173a0 */
} /* Line 459, Address: 0x10173a4 */

static void flashin1(void) { /* Line 461, Address: 0x10173c0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 465, Address: 0x10173d4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 466, Address: 0x1017408 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 468, Address: 0x101743c */
    flashin2(lpPe, lpPe2); /* Line 469, Address: 0x1017448 */
    ++lpPe; /* Line 470, Address: 0x1017458 */
    ++lpPe2; /* Line 471, Address: 0x101745c */
  } /* Line 472, Address: 0x1017460 */
  if (stageno.b.h == 1) return; /* Line 473, Address: 0x101747c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 475, Address: 0x1017498 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 476, Address: 0x10174cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 478, Address: 0x1017500 */
    flashin2(lpPe, lpPe2); /* Line 479, Address: 0x101750c */
    ++lpPe; /* Line 480, Address: 0x101751c */
    ++lpPe2; /* Line 481, Address: 0x1017520 */
  } /* Line 482, Address: 0x1017524 */



} /* Line 486, Address: 0x1017540 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 490, Address: 0x1017560 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 491, Address: 0x101756c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 494, Address: 0x10175cc */
      lpPeDest->peBlue -= 32; /* Line 495, Address: 0x10175f0 */
    } /* Line 496, Address: 0x1017600 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 497, Address: 0x1017608 */
      lpPeDest->peGreen -= 32; /* Line 498, Address: 0x101762c */
    } /* Line 499, Address: 0x101763c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 500, Address: 0x1017644 */
      lpPeDest->peRed -= 32; /* Line 501, Address: 0x1017668 */
    }
  }

} /* Line 505, Address: 0x101767c */


void flashout(void) {
  startcolor = 0; /* Line 509, Address: 0x1017690 */
  colorcnt = 63; /* Line 510, Address: 0x1017698 */

  FadeCount = 0; /* Line 512, Address: 0x10176a4 */
  *lpFadeFlag = 4; /* Line 513, Address: 0x10176ac */

} /* Line 515, Address: 0x10176bc */

static int flashout_new(void) { /* Line 517, Address: 0x10176d0 */

  int_flg = 18; /* Line 519, Address: 0x10176d8 */

  flashout1(); /* Line 521, Address: 0x10176e4 */


  if (++FadeCount > 21) { /* Line 524, Address: 0x10176ec */
    FadeCount = 0; /* Line 525, Address: 0x101770c */
    return 1; /* Line 526, Address: 0x1017714 */
  }
  return 0; /* Line 528, Address: 0x1017720 */
} /* Line 529, Address: 0x1017724 */


static void flashout1(void) { /* Line 532, Address: 0x1017740 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 536, Address: 0x1017750 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 538, Address: 0x1017784 */
    flashout2(lpPe); /* Line 539, Address: 0x1017790 */
    ++lpPe; /* Line 540, Address: 0x101779c */
  } /* Line 541, Address: 0x10177a0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 542, Address: 0x10177bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 544, Address: 0x10177f0 */
    flashout2(lpPe); /* Line 545, Address: 0x10177fc */
    ++lpPe; /* Line 546, Address: 0x1017808 */
  } /* Line 547, Address: 0x101780c */


} /* Line 550, Address: 0x1017828 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 553, Address: 0x1017840 */
  if (lpPeDest->peRed != 224) { /* Line 554, Address: 0x1017848 */
    lpPeDest->peRed += 32; /* Line 555, Address: 0x1017860 */
  } /* Line 556, Address: 0x1017874 */
  else if (lpPeDest->peGreen != 224) { /* Line 557, Address: 0x101787c */
    lpPeDest->peGreen += 32; /* Line 558, Address: 0x1017894 */
  } /* Line 559, Address: 0x10178a4 */
  else if (lpPeDest->peBlue != 224) { /* Line 560, Address: 0x10178ac */
    lpPeDest->peBlue += 32; /* Line 561, Address: 0x10178c4 */
  }


} /* Line 565, Address: 0x10178d4 */


void colorset(int ColorNo) { /* Line 568, Address: 0x10178e0 */
  colorset00(ColorNo, 1); /* Line 569, Address: 0x10178ec */
} /* Line 570, Address: 0x10178fc */

void colorset2(int ColorNo) { /* Line 572, Address: 0x1017910 */
  colorset00(ColorNo, 0); /* Line 573, Address: 0x101791c */
} /* Line 574, Address: 0x101792c */

void colorset3(int ColorNo) { /* Line 576, Address: 0x1017940 */
  colorset00(ColorNo, 1); /* Line 577, Address: 0x101794c */
} /* Line 578, Address: 0x101795c */

void colorset4(int ColorNo) { /* Line 580, Address: 0x1017970 */
  colorset00(ColorNo, 2); /* Line 581, Address: 0x101797c */
} /* Line 582, Address: 0x101798c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 588, Address: 0x10179a0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 593, Address: 0x10179c0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 595, Address: 0x1017a28 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 597, Address: 0x1017a38 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 599, Address: 0x1017a48 */
    default:
      lppe = lpcolorwk4; break; /* Line 601, Address: 0x1017a58 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 604, Address: 0x1017a60 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 605, Address: 0x1017a78 */
  n = colortbl[ColorNo].cnt; /* Line 606, Address: 0x1017aa0 */
  for (i = 0; i < n; ++i) { /* Line 607, Address: 0x1017ac0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 608, Address: 0x1017acc */
  } /* Line 609, Address: 0x1017afc */

} /* Line 611, Address: 0x1017b0c */




int FadeProc(void) { /* Line 616, Address: 0x1017b30 */
  switch (*lpFadeFlag) { /* Line 617, Address: 0x1017b38 */
    case 1:
      return fadein0_new(); /* Line 619, Address: 0x1017b7c */
    case 2:
      return fadeout_new(); /* Line 621, Address: 0x1017b8c */
    case 3:
      return flashin_new(); /* Line 623, Address: 0x1017b9c */
    case 4:
      return flashout_new(); /* Line 625, Address: 0x1017bac */
  }
  return 1; /* Line 627, Address: 0x1017bbc */

} /* Line 629, Address: 0x1017bc0 */
