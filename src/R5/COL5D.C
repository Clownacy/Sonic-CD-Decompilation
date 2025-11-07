#include "..\EQU.H"
#include "COL5A.H"

typedef struct {
  unsigned char adr;
  unsigned char tate;
  unsigned char yoko;
  unsigned char time;
  PALETTEENTRY colortbl[64];
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
  {   0,   0,   0, 1 }, {  96, 160,   0, 1 }, {  64,  96,   0, 1 }, {  32,  32,   0, 1 },
  {  32,   0,   0, 1 }, { 192, 192,   0, 1 }, { 192, 224,  32, 1 }, { 128, 128,   0, 1 },
  {  64,  64,   0, 1 }, { 128, 192,  32, 1 }, { 224, 224, 192, 1 }, {  96,  96,  64, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, { 160,  32,  32, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,  32,  32, 1 }, {   0,  64,  32, 1 },
  {  32,  96,  64, 1 }, {  32, 128,  96, 1 }, {  32, 160, 160, 1 }, { 224, 224, 224, 1 },
  { 224,   0, 224, 1 }, {  96,   0,  96, 1 }, {  32,   0,  32, 1 }, {   0, 128,   0, 1 },
  {  32,   0,   0, 1 }, { 128,   0,   0, 1 }, { 224,  64,   0, 1 }, { 224, 160,   0, 1 }
};
PALETTEENTRY zone5color1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  { 128, 128, 224, 1 }, { 160,   0,  96, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224,  64, 128, 1 }, { 224, 128, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, {  96, 160,   0, 1 }, {  64,  96,   0, 1 }, {  32,  32,   0, 1 },
  {  32,   0,   0, 1 }, { 192, 192,   0, 1 }, { 192, 224,  32, 1 }, { 128, 128,   0, 1 },
  {  64,  64,   0, 1 }, { 128, 192,  32, 1 }, { 224, 224, 192, 1 }, {  96,  96,  64, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, { 160,  32,  32, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  64,  32,   0, 1 }, {  96,  64,   0, 1 },
  { 128,  96,   0, 1 }, { 160, 160,  32, 1 }, { 128,  32,  64, 1 }, { 160,  32,  64, 1 },
  { 192,  64,  64, 1 }, { 192,  96,  64, 1 }, { 240, 160,  96, 1 }, { 224, 224, 224, 1 },
  {  32,  32,   0, 1 }, {  64,  64,   0, 1 }, { 128, 128,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone5colboss0[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 160, 160, 1 }, {   0,  32,  32, 1 },
  {   0,  64,  64, 1 }, {   0,  96,  96, 1 }, { 224, 224, 224, 1 }, {   0, 224, 224, 1 },
  {  64,  32,  32, 1 }, { 128,  32,  32, 1 }, { 224,  96,  96, 1 }, {  32,   0,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }
};
palette_part colortbl[7] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone5color0, 16, 48 },
  { zone5color1, 16, 48 },
  { zone5colboss0, 16, 16 }
};
static int FadeCount;










































































void clchgctr(void) { /* Line 187, Address: 0x101f540 */
  unsigned char *pChgTime, *pChgCnt;
  color_change_data colchg50 = { /* Line 189, Address: 0x101f548 */
    42, 3, 3, 4,
    {
      { 224, 224, 192, 1 }, {  96,  96,  64, 1 }, {   0,   0,   0, 1 },
      {   0,   0,   0, 1 }, { 224, 224, 192, 1 }, {  96,  96,  64, 1 },
      {  96,  96,  64, 1 }, {   0,   0,   0, 1 }, { 224, 224, 192, 1 }
    }
  };
  color_change_data colchg51 = { /* Line 197, Address: 0x101f584 */
    54, 3, 4, 12,
    {
      { 128,  32,  64, 1 }, { 160,  32,  64, 1 }, { 192,  64,  64, 1 }, { 192,  96,  64, 1 },
      { 160,  32,  64, 1 }, { 192,  32,  64, 1 }, { 224,  64,  64, 1 }, { 224,  96,  64, 1 },
      { 224,  64,  64, 1 }, { 224,  32,  64, 1 }, { 224,  64,  64, 1 }, { 224,  96,  64, 1 }
    }
  };
  color_change_data colchg52 = { /* Line 205, Address: 0x101f5c0 */
    60, 4, 4, 5,
    {
      { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, {  32,  32,   0, 1 },
      { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, {  32,  32,   0, 1 }, { 224, 224,   0, 1 },
      {  64,  64,   0, 1 }, {  32,  32,   0, 1 }, { 224, 224,   0, 1 }, { 128, 128,   0, 1 },
      {  32,  32,   0, 1 }, { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }
    }
  };
  color_change_data colchg53 = { /* Line 214, Address: 0x101f5fc */
    42, 3, 3, 4,
    {
      { 224,   0, 160, 1 }, { 160,   0, 128, 1 }, {  64,   0,  96, 1 },
      { 160,   0, 128, 1 }, {  64,   0,  96, 1 }, { 224,   0, 160, 1 },
      {  64,   0,  96, 1 }, { 224,   0, 160, 1 }, { 160,   0, 128, 1 }
    }
  };

  pChgTime = clchgtim; /* Line 223, Address: 0x101f638 */
  pChgCnt = clchgcnt; /* Line 224, Address: 0x101f644 */

  if (bossflag) { /* Line 226, Address: 0x101f650 */

    ++pChgTime; /* Line 228, Address: 0x101f660 */
    ++pChgCnt; /* Line 229, Address: 0x101f66c */
  } /* Line 230, Address: 0x101f678 */
  else {


    if (!colrevflag) { /* Line 234, Address: 0x101f680 */
      colchgsub(&pChgTime, &pChgCnt, &colchg50); /* Line 235, Address: 0x101f690 */
    } else { /* Line 236, Address: 0x101f6a4 */
      colchgsub(&pChgTime, &pChgCnt, &colchg53); /* Line 237, Address: 0x101f6ac */
    }
  }

  if (enkeino & 1) { /* Line 241, Address: 0x101f6c0 */
    colchgsub(&pChgTime, &pChgCnt, &colchg51); /* Line 242, Address: 0x101f6d8 */
    colchgsub(&pChgTime, &pChgCnt, &colchg52); /* Line 243, Address: 0x101f6ec */
  }
} /* Line 245, Address: 0x101f700 */



static void colchgsub(unsigned char** ppChgTime, unsigned char** ppChgCnt, color_change_data* pColortbl) { /* Line 249, Address: 0x101f710 */
  short cnt;
  PALETTEENTRY *pPalet, *pColtbl;
  int i;

  if ((char)--**ppChgTime < 0) { /* Line 254, Address: 0x101f730 */
    **ppChgTime = pColortbl->time; /* Line 255, Address: 0x101f764 */
    if ((cnt = **ppChgCnt + 1) >= pColortbl->tate) { /* Line 256, Address: 0x101f778 */
      cnt = 0; /* Line 257, Address: 0x101f7c4 */
    }


    **ppChgCnt = cnt; /* Line 261, Address: 0x101f7c8 */


    cnt *= pColortbl->yoko; /* Line 264, Address: 0x101f7d8 */
    pPalet = &lpcolorwk[pColortbl->adr]; /* Line 265, Address: 0x101f7f0 */
    pColtbl = &pColortbl->colortbl[cnt]; /* Line 266, Address: 0x101f80c */

    for (i = 0; i < pColortbl->yoko; ++i) { /* Line 268, Address: 0x101f824 */
      *pPalet++ = *pColtbl++; /* Line 269, Address: 0x101f830 */
    } /* Line 270, Address: 0x101f860 */
  }


  ++*ppChgTime; /* Line 274, Address: 0x101f87c */
  ++*ppChgCnt; /* Line 275, Address: 0x101f890 */
} /* Line 276, Address: 0x101f8a4 */







void fadein0(void) { /* Line 284, Address: 0x101f8c0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 288, Address: 0x101f8cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 290, Address: 0x101f900 */
    lpPe->peRed = 0; /* Line 291, Address: 0x101f90c */
    lpPe->peGreen = 0; /* Line 292, Address: 0x101f910 */
    lpPe->peBlue = 0; /* Line 293, Address: 0x101f914 */
    lpPe->peFlags = 1; /* Line 294, Address: 0x101f918 */
    ++lpPe; /* Line 295, Address: 0x101f920 */
  } /* Line 296, Address: 0x101f924 */
  FadeCount = 0; /* Line 297, Address: 0x101f940 */
  *lpFadeFlag = 1; /* Line 298, Address: 0x101f948 */

} /* Line 300, Address: 0x101f958 */



int fadein0_new(void) { /* Line 304, Address: 0x101f970 */

  int_flg = 18; /* Line 306, Address: 0x101f978 */

  fadein1(); /* Line 308, Address: 0x101f984 */


  if (++FadeCount > 21) { /* Line 311, Address: 0x101f98c */
    FadeCount = 0; /* Line 312, Address: 0x101f9ac */
    return 1; /* Line 313, Address: 0x101f9b4 */
  }
  return 0; /* Line 315, Address: 0x101f9c0 */
} /* Line 316, Address: 0x101f9c4 */



static void fadein1(void) { /* Line 320, Address: 0x101f9e0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 324, Address: 0x101f9f4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 325, Address: 0x101fa28 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 327, Address: 0x101fa5c */
    fadein2(lpPe, lpPe2); /* Line 328, Address: 0x101fa68 */
    ++lpPe; /* Line 329, Address: 0x101fa78 */
    ++lpPe2; /* Line 330, Address: 0x101fa7c */
  } /* Line 331, Address: 0x101fa80 */
  if (stageno.b.h == 1) return; /* Line 332, Address: 0x101fa9c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 334, Address: 0x101fab8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 335, Address: 0x101faec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 337, Address: 0x101fb20 */
    fadein2(lpPe, lpPe2); /* Line 338, Address: 0x101fb2c */
    ++lpPe; /* Line 339, Address: 0x101fb3c */
    ++lpPe2; /* Line 340, Address: 0x101fb40 */
  } /* Line 341, Address: 0x101fb44 */



} /* Line 345, Address: 0x101fb60 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 349, Address: 0x101fb80 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 350, Address: 0x101fb8c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 353, Address: 0x101fbec */
      lpPeDest->peBlue += 32; /* Line 354, Address: 0x101fc10 */
    } /* Line 355, Address: 0x101fc20 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 356, Address: 0x101fc28 */
      lpPeDest->peGreen += 32; /* Line 357, Address: 0x101fc4c */
    } /* Line 358, Address: 0x101fc5c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 359, Address: 0x101fc64 */
      lpPeDest->peRed += 32; /* Line 360, Address: 0x101fc88 */
    }
  }

} /* Line 364, Address: 0x101fc9c */


void fadeout(void) {
  startcolor = 0; /* Line 368, Address: 0x101fcb0 */
  colorcnt = 63; /* Line 369, Address: 0x101fcb8 */

  FadeCount = 0; /* Line 371, Address: 0x101fcc4 */
  *lpFadeFlag = 2; /* Line 372, Address: 0x101fccc */

} /* Line 374, Address: 0x101fcdc */



static int fadeout_new(void) { /* Line 378, Address: 0x101fcf0 */

  int_flg = 18; /* Line 380, Address: 0x101fcf8 */

  fadeout1(); /* Line 382, Address: 0x101fd04 */


  if (++FadeCount > 21) { /* Line 385, Address: 0x101fd0c */
    FadeCount = 0; /* Line 386, Address: 0x101fd2c */
    return 1; /* Line 387, Address: 0x101fd34 */
  }
  return 0; /* Line 389, Address: 0x101fd40 */
} /* Line 390, Address: 0x101fd44 */


static void fadeout1(void) { /* Line 393, Address: 0x101fd60 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 397, Address: 0x101fd70 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 399, Address: 0x101fda4 */
    fadeout2(lpPe); /* Line 400, Address: 0x101fdb0 */
    ++lpPe; /* Line 401, Address: 0x101fdbc */
  } /* Line 402, Address: 0x101fdc0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 403, Address: 0x101fddc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 405, Address: 0x101fe10 */
    fadeout2(lpPe); /* Line 406, Address: 0x101fe1c */
    ++lpPe; /* Line 407, Address: 0x101fe28 */
  } /* Line 408, Address: 0x101fe2c */


} /* Line 411, Address: 0x101fe48 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 414, Address: 0x101fe60 */
  if (lpPeDest->peRed) { /* Line 415, Address: 0x101fe68 */
    lpPeDest->peRed -= 32; /* Line 416, Address: 0x101fe78 */
  } /* Line 417, Address: 0x101fe8c */
  else if (lpPeDest->peGreen) { /* Line 418, Address: 0x101fe94 */
    lpPeDest->peGreen -= 32; /* Line 419, Address: 0x101fea4 */
  } /* Line 420, Address: 0x101feb4 */
  else if (lpPeDest->peBlue) { /* Line 421, Address: 0x101febc */
    lpPeDest->peBlue -= 32; /* Line 422, Address: 0x101fecc */
  }

} /* Line 425, Address: 0x101fedc */




void flashin(void) { /* Line 430, Address: 0x101fef0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 434, Address: 0x101fefc */
  colorcnt = 63; /* Line 435, Address: 0x101ff04 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 437, Address: 0x101ff10 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 439, Address: 0x101ff44 */
    lpPe->peRed = 224; /* Line 440, Address: 0x101ff50 */
    lpPe->peGreen = 224; /* Line 441, Address: 0x101ff58 */
    lpPe->peBlue = 224; /* Line 442, Address: 0x101ff60 */
    lpPe->peFlags = 1; /* Line 443, Address: 0x101ff68 */
    ++lpPe; /* Line 444, Address: 0x101ff70 */
  } /* Line 445, Address: 0x101ff74 */
  FadeCount = 0; /* Line 446, Address: 0x101ff90 */
  *lpFadeFlag = 3; /* Line 447, Address: 0x101ff98 */

} /* Line 449, Address: 0x101ffa8 */

static int flashin_new(void) { /* Line 451, Address: 0x101ffc0 */

  int_flg = 18; /* Line 453, Address: 0x101ffc8 */

  flashin1(); /* Line 455, Address: 0x101ffd4 */


  if (++FadeCount > 21) { /* Line 458, Address: 0x101ffdc */
    FadeCount = 0; /* Line 459, Address: 0x101fffc */
    return 1; /* Line 460, Address: 0x1020004 */
  }
  return 0; /* Line 462, Address: 0x1020010 */
} /* Line 463, Address: 0x1020014 */

static void flashin1(void) { /* Line 465, Address: 0x1020030 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 469, Address: 0x1020044 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 470, Address: 0x1020078 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 472, Address: 0x10200ac */
    flashin2(lpPe, lpPe2); /* Line 473, Address: 0x10200b8 */
    ++lpPe; /* Line 474, Address: 0x10200c8 */
    ++lpPe2; /* Line 475, Address: 0x10200cc */
  } /* Line 476, Address: 0x10200d0 */
  if (stageno.b.h == 1) return; /* Line 477, Address: 0x10200ec */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 479, Address: 0x1020108 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 480, Address: 0x102013c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 482, Address: 0x1020170 */
    flashin2(lpPe, lpPe2); /* Line 483, Address: 0x102017c */
    ++lpPe; /* Line 484, Address: 0x102018c */
    ++lpPe2; /* Line 485, Address: 0x1020190 */
  } /* Line 486, Address: 0x1020194 */



} /* Line 490, Address: 0x10201b0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 494, Address: 0x10201d0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 495, Address: 0x10201dc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 498, Address: 0x102023c */
      lpPeDest->peBlue -= 32; /* Line 499, Address: 0x1020260 */
    } /* Line 500, Address: 0x1020270 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 501, Address: 0x1020278 */
      lpPeDest->peGreen -= 32; /* Line 502, Address: 0x102029c */
    } /* Line 503, Address: 0x10202ac */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 504, Address: 0x10202b4 */
      lpPeDest->peRed -= 32; /* Line 505, Address: 0x10202d8 */
    }
  }

} /* Line 509, Address: 0x10202ec */


void flashout(void) {
  startcolor = 0; /* Line 513, Address: 0x1020300 */
  colorcnt = 63; /* Line 514, Address: 0x1020308 */

  FadeCount = 0; /* Line 516, Address: 0x1020314 */
  *lpFadeFlag = 4; /* Line 517, Address: 0x102031c */

} /* Line 519, Address: 0x102032c */

static int flashout_new(void) { /* Line 521, Address: 0x1020340 */

  int_flg = 18; /* Line 523, Address: 0x1020348 */

  flashout1(); /* Line 525, Address: 0x1020354 */


  if (++FadeCount > 21) { /* Line 528, Address: 0x102035c */
    FadeCount = 0; /* Line 529, Address: 0x102037c */
    return 1; /* Line 530, Address: 0x1020384 */
  }
  return 0; /* Line 532, Address: 0x1020390 */
} /* Line 533, Address: 0x1020394 */


static void flashout1(void) { /* Line 536, Address: 0x10203b0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 540, Address: 0x10203c0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 542, Address: 0x10203f4 */
    flashout2(lpPe); /* Line 543, Address: 0x1020400 */
    ++lpPe; /* Line 544, Address: 0x102040c */
  } /* Line 545, Address: 0x1020410 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 546, Address: 0x102042c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 548, Address: 0x1020460 */
    flashout2(lpPe); /* Line 549, Address: 0x102046c */
    ++lpPe; /* Line 550, Address: 0x1020478 */
  } /* Line 551, Address: 0x102047c */


} /* Line 554, Address: 0x1020498 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 557, Address: 0x10204b0 */
  if (lpPeDest->peRed != 224) { /* Line 558, Address: 0x10204b8 */
    lpPeDest->peRed += 32; /* Line 559, Address: 0x10204d0 */
  } /* Line 560, Address: 0x10204e4 */
  else if (lpPeDest->peGreen != 224) { /* Line 561, Address: 0x10204ec */
    lpPeDest->peGreen += 32; /* Line 562, Address: 0x1020504 */
  } /* Line 563, Address: 0x1020514 */
  else if (lpPeDest->peBlue != 224) { /* Line 564, Address: 0x102051c */
    lpPeDest->peBlue += 32; /* Line 565, Address: 0x1020534 */
  }


} /* Line 569, Address: 0x1020544 */


void colorset(int ColorNo) { /* Line 572, Address: 0x1020550 */
  colorset00(ColorNo, 1); /* Line 573, Address: 0x102055c */
} /* Line 574, Address: 0x102056c */

void colorset2(int ColorNo) { /* Line 576, Address: 0x1020580 */
  colorset00(ColorNo, 0); /* Line 577, Address: 0x102058c */
} /* Line 578, Address: 0x102059c */

void colorset3(int ColorNo) { /* Line 580, Address: 0x10205b0 */
  colorset00(ColorNo, 1); /* Line 581, Address: 0x10205bc */
} /* Line 582, Address: 0x10205cc */

void colorset4(int ColorNo) { /* Line 584, Address: 0x10205e0 */
  colorset00(ColorNo, 2); /* Line 585, Address: 0x10205ec */
} /* Line 586, Address: 0x10205fc */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 592, Address: 0x1020610 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 597, Address: 0x1020630 */
    case 0:
      lppe = lpcolorwk; break; /* Line 599, Address: 0x1020698 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 601, Address: 0x10206a8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 603, Address: 0x10206b8 */
    default:
      lppe = lpcolorwk4; break; /* Line 605, Address: 0x10206c8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 608, Address: 0x10206d0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 609, Address: 0x10206e8 */
  n = colortbl[ColorNo].cnt; /* Line 610, Address: 0x1020710 */
  for (i = 0; i < n; ++i) { /* Line 611, Address: 0x1020730 */
    *lpPeDest++ = *lpPeSrc++; /* Line 612, Address: 0x102073c */
  } /* Line 613, Address: 0x102076c */

} /* Line 615, Address: 0x102077c */




int FadeProc(void) { /* Line 620, Address: 0x10207a0 */
  switch (*lpFadeFlag) { /* Line 621, Address: 0x10207a8 */
    case 1:
      return fadein0_new(); /* Line 623, Address: 0x10207ec */
    case 2:
      return fadeout_new(); /* Line 625, Address: 0x10207fc */
    case 3:
      return flashin_new(); /* Line 627, Address: 0x102080c */
    case 4:
      return flashout_new(); /* Line 629, Address: 0x102081c */
  }
  return 1; /* Line 631, Address: 0x102082c */

} /* Line 633, Address: 0x1020830 */
