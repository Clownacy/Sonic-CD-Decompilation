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
  {   0,   0,  32, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 160, 160, 160, 1 },
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, { 160, 192,   0, 1 }, {   0, 160,   0, 1 },
  {   0,  64,   0, 1 }, {   0,  32,   0, 1 }, { 224, 224,   0, 1 }, { 160, 128,   0, 1 },
  { 128,  96,  64, 1 }, {  96,  64,  32, 1 }, {  64,  32,   0, 1 }, {  32,   0,   0, 1 },
  {   0,   0,  32, 1 }, {   0, 224, 160, 1 }, { 224, 192,   0, 1 }, { 128,  96,   0, 1 },
  {   0,   0,  64, 1 }, {  32,  32,   0, 1 }, {   0, 224, 128, 1 }, {   0, 224,  96, 1 },
  {   0, 224,  32, 1 }, {  64,  32,  96, 1 }, { 128, 192, 224, 1 }, { 192, 224, 224, 1 },
  {  64, 192, 160, 1 }, {  64, 160, 128, 1 }, { 160, 224, 224, 1 }, { 224, 224, 224, 1 }
};
PALETTEENTRY zone5color1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  { 128, 128, 224, 1 }, { 160,   0,  96, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224,  64, 128, 1 }, { 224, 128, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 160, 160, 160, 1 },
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, { 160, 192,   0, 1 }, {   0, 160,   0, 1 },
  {   0,  64,   0, 1 }, {   0,  32,   0, 1 }, { 224, 224,   0, 1 }, { 160, 128,   0, 1 },
  { 128,  96,  64, 1 }, {  96,  64,  32, 1 }, {  64,  32,   0, 1 }, {  32,   0,   0, 1 },
  { 128, 128, 224, 1 }, { 128, 160, 224, 1 }, { 128, 224,   0, 1 }, {  96, 160,   0, 1 },
  {  64, 128,   0, 1 }, { 192, 224, 224, 1 }, {  64,  64, 128, 1 }, { 192, 160,   0, 1 },
  { 160,  96,   0, 1 }, {  96,  64,   0, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  { 160, 160, 224, 1 }, {  96,  96, 192, 1 }, { 224, 224,   0, 1 }, {  32,  96,   0, 1 }
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









































































void clchgctr() { /* Line 179, Address: 0x10228e0 */
  unsigned char *pChgTime, *pChgCnt;
  color_change_data colchg50 = { /* Line 181, Address: 0x10228e8 */
    35, 3, 3, 4,
    {
      { 160, 160, 160, 1 }, {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 160, 160, 160, 1 },
      {  96,  96,  96, 1 }, {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, { 160, 160, 160, 1 }
    }
  };

  color_change_data colchg51 = { /* Line 189, Address: 0x1022924 */
    62, 8, 2, 20,
    {
      { 224, 224, 224, 1 }, {  96, 224, 224, 1 },
      { 224, 224, 224, 1 }, {  96, 224, 224, 1 }, { 224, 224, 224, 1 },
      {  96, 224, 224, 1 }, { 160, 224, 224, 1 },
      { 160, 224, 224, 1 }, {  96, 224, 224, 1 },
      { 224, 224, 224, 1 }, {  96, 224, 224, 1 }, { 224, 224, 224, 1 },
      {  96, 224, 224, 1 }, { 224, 224, 224, 1 },
      { 160, 224, 224, 1 }, { 160, 224, 224, 1 }
    }
  };

  color_change_data colchg52 = { /* Line 202, Address: 0x1022960 */
    35, 3, 3, 4,
    {
      { 224, 192,   0, 1 }, { 224,  64,   0, 1 }, {  64,   0,   0, 1 },
      { 224,  64,   0, 1 }, {  64,   0,   0, 1 }, { 224, 192,   0, 1 },
      {  64,   0,   0, 1 }, { 224, 192,   0, 1 }, { 224,  64,   0, 1 }
    }
  };

  pChgTime = clchgtim; /* Line 211, Address: 0x102299c */
  pChgCnt = clchgcnt; /* Line 212, Address: 0x10229a8 */


  if (!colrevflag) { /* Line 215, Address: 0x10229b4 */
    colchgsub(&pChgTime, &pChgCnt, &colchg50); /* Line 216, Address: 0x10229c4 */
  } else { /* Line 217, Address: 0x10229d8 */
    colchgsub(&pChgTime, &pChgCnt, &colchg52); /* Line 218, Address: 0x10229e0 */
  }

  if (!(enkeino & 1)) { /* Line 221, Address: 0x10229f4 */
    colchgsub(&pChgTime, &pChgCnt, &colchg51); /* Line 222, Address: 0x1022a0c */
  }

} /* Line 225, Address: 0x1022a20 */



static void colchgsub(unsigned char** ppChgTime, unsigned char** ppChgCnt, color_change_data* pColortbl) { /* Line 229, Address: 0x1022a30 */
  short cnt;
  PALETTEENTRY *pPalet, *pColtbl;
  int i;

  if ((char)--**ppChgTime < 0) { /* Line 234, Address: 0x1022a50 */
    **ppChgTime = pColortbl->time; /* Line 235, Address: 0x1022a84 */
    if ((cnt = **ppChgCnt + 1) >= pColortbl->tate) { /* Line 236, Address: 0x1022a98 */
      cnt = 0; /* Line 237, Address: 0x1022ae4 */
    }


    **ppChgCnt = cnt; /* Line 241, Address: 0x1022ae8 */


    cnt *= pColortbl->yoko; /* Line 244, Address: 0x1022af8 */
    pPalet = &lpcolorwk[pColortbl->adr]; /* Line 245, Address: 0x1022b10 */
    pColtbl = &pColortbl->colortbl[cnt]; /* Line 246, Address: 0x1022b2c */

    for (i = 0; i < pColortbl->yoko; ++i) { /* Line 248, Address: 0x1022b44 */
      *pPalet++ = *pColtbl++; /* Line 249, Address: 0x1022b50 */
    } /* Line 250, Address: 0x1022b80 */
  }


  ++*ppChgTime; /* Line 254, Address: 0x1022b9c */
  ++*ppChgCnt; /* Line 255, Address: 0x1022bb0 */
} /* Line 256, Address: 0x1022bc4 */







void fadein0() { /* Line 264, Address: 0x1022be0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 268, Address: 0x1022bec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 270, Address: 0x1022c20 */
    lpPe->peRed = 0; /* Line 271, Address: 0x1022c2c */
    lpPe->peGreen = 0; /* Line 272, Address: 0x1022c30 */
    lpPe->peBlue = 0; /* Line 273, Address: 0x1022c34 */
    lpPe->peFlags = 1; /* Line 274, Address: 0x1022c38 */
    ++lpPe; /* Line 275, Address: 0x1022c40 */
  } /* Line 276, Address: 0x1022c44 */
  FadeCount = 0; /* Line 277, Address: 0x1022c60 */
  *lpFadeFlag = 1; /* Line 278, Address: 0x1022c68 */

} /* Line 280, Address: 0x1022c78 */



int fadein0_new() { /* Line 284, Address: 0x1022c90 */

  int_flg = 18; /* Line 286, Address: 0x1022c98 */

  fadein1(); /* Line 288, Address: 0x1022ca4 */


  if (++FadeCount > 21) { /* Line 291, Address: 0x1022cac */
    FadeCount = 0; /* Line 292, Address: 0x1022ccc */
    return 1; /* Line 293, Address: 0x1022cd4 */
  }
  return 0; /* Line 295, Address: 0x1022ce0 */
} /* Line 296, Address: 0x1022ce4 */



static void fadein1() { /* Line 300, Address: 0x1022d00 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 304, Address: 0x1022d14 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 305, Address: 0x1022d48 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 307, Address: 0x1022d7c */
    fadein2(lpPe, lpPe2); /* Line 308, Address: 0x1022d88 */
    ++lpPe; /* Line 309, Address: 0x1022d98 */
    ++lpPe2; /* Line 310, Address: 0x1022d9c */
  } /* Line 311, Address: 0x1022da0 */
  if (stageno.b.h == 1) return; /* Line 312, Address: 0x1022dbc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 314, Address: 0x1022dd8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 315, Address: 0x1022e0c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 317, Address: 0x1022e40 */
    fadein2(lpPe, lpPe2); /* Line 318, Address: 0x1022e4c */
    ++lpPe; /* Line 319, Address: 0x1022e5c */
    ++lpPe2; /* Line 320, Address: 0x1022e60 */
  } /* Line 321, Address: 0x1022e64 */



} /* Line 325, Address: 0x1022e80 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 329, Address: 0x1022ea0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 330, Address: 0x1022eac */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 333, Address: 0x1022f0c */
      lpPeDest->peBlue += 32; /* Line 334, Address: 0x1022f30 */
    } /* Line 335, Address: 0x1022f40 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 336, Address: 0x1022f48 */
      lpPeDest->peGreen += 32; /* Line 337, Address: 0x1022f6c */
    } /* Line 338, Address: 0x1022f7c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 339, Address: 0x1022f84 */
      lpPeDest->peRed += 32; /* Line 340, Address: 0x1022fa8 */
    }
  }

} /* Line 344, Address: 0x1022fbc */


void fadeout() {
  startcolor = 0; /* Line 348, Address: 0x1022fd0 */
  colorcnt = 63; /* Line 349, Address: 0x1022fd8 */

  FadeCount = 0; /* Line 351, Address: 0x1022fe4 */
  *lpFadeFlag = 2; /* Line 352, Address: 0x1022fec */

} /* Line 354, Address: 0x1022ffc */



static int fadeout_new() { /* Line 358, Address: 0x1023010 */

  int_flg = 18; /* Line 360, Address: 0x1023018 */

  fadeout1(); /* Line 362, Address: 0x1023024 */


  if (++FadeCount > 21) { /* Line 365, Address: 0x102302c */
    FadeCount = 0; /* Line 366, Address: 0x102304c */
    return 1; /* Line 367, Address: 0x1023054 */
  }
  return 0; /* Line 369, Address: 0x1023060 */
} /* Line 370, Address: 0x1023064 */


static void fadeout1() { /* Line 373, Address: 0x1023080 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 377, Address: 0x1023090 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 379, Address: 0x10230c4 */
    fadeout2(lpPe); /* Line 380, Address: 0x10230d0 */
    ++lpPe; /* Line 381, Address: 0x10230dc */
  } /* Line 382, Address: 0x10230e0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 383, Address: 0x10230fc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 385, Address: 0x1023130 */
    fadeout2(lpPe); /* Line 386, Address: 0x102313c */
    ++lpPe; /* Line 387, Address: 0x1023148 */
  } /* Line 388, Address: 0x102314c */


} /* Line 391, Address: 0x1023168 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 394, Address: 0x1023180 */
  if (lpPeDest->peRed) { /* Line 395, Address: 0x1023188 */
    lpPeDest->peRed -= 32; /* Line 396, Address: 0x1023198 */
  } /* Line 397, Address: 0x10231ac */
  else if (lpPeDest->peGreen) { /* Line 398, Address: 0x10231b4 */
    lpPeDest->peGreen -= 32; /* Line 399, Address: 0x10231c4 */
  } /* Line 400, Address: 0x10231d4 */
  else if (lpPeDest->peBlue) { /* Line 401, Address: 0x10231dc */
    lpPeDest->peBlue -= 32; /* Line 402, Address: 0x10231ec */
  }

} /* Line 405, Address: 0x10231fc */




void flashin() { /* Line 410, Address: 0x1023210 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 414, Address: 0x102321c */
  colorcnt = 63; /* Line 415, Address: 0x1023224 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 417, Address: 0x1023230 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 419, Address: 0x1023264 */
    lpPe->peRed = 224; /* Line 420, Address: 0x1023270 */
    lpPe->peGreen = 224; /* Line 421, Address: 0x1023278 */
    lpPe->peBlue = 224; /* Line 422, Address: 0x1023280 */
    lpPe->peFlags = 1; /* Line 423, Address: 0x1023288 */
    ++lpPe; /* Line 424, Address: 0x1023290 */
  } /* Line 425, Address: 0x1023294 */
  FadeCount = 0; /* Line 426, Address: 0x10232b0 */
  *lpFadeFlag = 3; /* Line 427, Address: 0x10232b8 */

} /* Line 429, Address: 0x10232c8 */

static int flashin_new() { /* Line 431, Address: 0x10232e0 */

  int_flg = 18; /* Line 433, Address: 0x10232e8 */

  flashin1(); /* Line 435, Address: 0x10232f4 */


  if (++FadeCount > 21) { /* Line 438, Address: 0x10232fc */
    FadeCount = 0; /* Line 439, Address: 0x102331c */
    return 1; /* Line 440, Address: 0x1023324 */
  }
  return 0; /* Line 442, Address: 0x1023330 */
} /* Line 443, Address: 0x1023334 */

static void flashin1() { /* Line 445, Address: 0x1023350 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 449, Address: 0x1023364 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 450, Address: 0x1023398 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 452, Address: 0x10233cc */
    flashin2(lpPe, lpPe2); /* Line 453, Address: 0x10233d8 */
    ++lpPe; /* Line 454, Address: 0x10233e8 */
    ++lpPe2; /* Line 455, Address: 0x10233ec */
  } /* Line 456, Address: 0x10233f0 */
  if (stageno.b.h == 1) return; /* Line 457, Address: 0x102340c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 459, Address: 0x1023428 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 460, Address: 0x102345c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 462, Address: 0x1023490 */
    flashin2(lpPe, lpPe2); /* Line 463, Address: 0x102349c */
    ++lpPe; /* Line 464, Address: 0x10234ac */
    ++lpPe2; /* Line 465, Address: 0x10234b0 */
  } /* Line 466, Address: 0x10234b4 */



} /* Line 470, Address: 0x10234d0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 474, Address: 0x10234f0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 475, Address: 0x10234fc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 478, Address: 0x102355c */
      lpPeDest->peBlue -= 32; /* Line 479, Address: 0x1023580 */
    } /* Line 480, Address: 0x1023590 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 481, Address: 0x1023598 */
      lpPeDest->peGreen -= 32; /* Line 482, Address: 0x10235bc */
    } /* Line 483, Address: 0x10235cc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 484, Address: 0x10235d4 */
      lpPeDest->peRed -= 32; /* Line 485, Address: 0x10235f8 */
    }
  }

} /* Line 489, Address: 0x102360c */


void flashout() {
  startcolor = 0; /* Line 493, Address: 0x1023620 */
  colorcnt = 63; /* Line 494, Address: 0x1023628 */

  FadeCount = 0; /* Line 496, Address: 0x1023634 */
  *lpFadeFlag = 4; /* Line 497, Address: 0x102363c */

} /* Line 499, Address: 0x102364c */

static int flashout_new() { /* Line 501, Address: 0x1023660 */

  int_flg = 18; /* Line 503, Address: 0x1023668 */

  flashout1(); /* Line 505, Address: 0x1023674 */


  if (++FadeCount > 21) { /* Line 508, Address: 0x102367c */
    FadeCount = 0; /* Line 509, Address: 0x102369c */
    return 1; /* Line 510, Address: 0x10236a4 */
  }
  return 0; /* Line 512, Address: 0x10236b0 */
} /* Line 513, Address: 0x10236b4 */


static void flashout1() { /* Line 516, Address: 0x10236d0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 520, Address: 0x10236e0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 522, Address: 0x1023714 */
    flashout2(lpPe); /* Line 523, Address: 0x1023720 */
    ++lpPe; /* Line 524, Address: 0x102372c */
  } /* Line 525, Address: 0x1023730 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 526, Address: 0x102374c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 528, Address: 0x1023780 */
    flashout2(lpPe); /* Line 529, Address: 0x102378c */
    ++lpPe; /* Line 530, Address: 0x1023798 */
  } /* Line 531, Address: 0x102379c */


} /* Line 534, Address: 0x10237b8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 537, Address: 0x10237d0 */
  if (lpPeDest->peRed != 224) { /* Line 538, Address: 0x10237d8 */
    lpPeDest->peRed += 32; /* Line 539, Address: 0x10237f0 */
  } /* Line 540, Address: 0x1023804 */
  else if (lpPeDest->peGreen != 224) { /* Line 541, Address: 0x102380c */
    lpPeDest->peGreen += 32; /* Line 542, Address: 0x1023824 */
  } /* Line 543, Address: 0x1023834 */
  else if (lpPeDest->peBlue != 224) { /* Line 544, Address: 0x102383c */
    lpPeDest->peBlue += 32; /* Line 545, Address: 0x1023854 */
  }


} /* Line 549, Address: 0x1023864 */


void colorset(int ColorNo) { /* Line 552, Address: 0x1023870 */
  colorset00(ColorNo, 1); /* Line 553, Address: 0x102387c */
} /* Line 554, Address: 0x102388c */

void colorset2(int ColorNo) { /* Line 556, Address: 0x10238a0 */
  colorset00(ColorNo, 0); /* Line 557, Address: 0x10238ac */
} /* Line 558, Address: 0x10238bc */

void colorset3(int ColorNo) { /* Line 560, Address: 0x10238d0 */
  colorset00(ColorNo, 1); /* Line 561, Address: 0x10238dc */
} /* Line 562, Address: 0x10238ec */

void colorset4(int ColorNo) { /* Line 564, Address: 0x1023900 */
  colorset00(ColorNo, 2); /* Line 565, Address: 0x102390c */
} /* Line 566, Address: 0x102391c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 572, Address: 0x1023930 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 577, Address: 0x1023950 */
    case 0:
      lppe = lpcolorwk; break; /* Line 579, Address: 0x10239b8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 581, Address: 0x10239c8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 583, Address: 0x10239d8 */
    default:
      lppe = lpcolorwk4; break; /* Line 585, Address: 0x10239e8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 588, Address: 0x10239f0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 589, Address: 0x1023a08 */
  n = colortbl[ColorNo].cnt; /* Line 590, Address: 0x1023a30 */
  for (i = 0; i < n; ++i) { /* Line 591, Address: 0x1023a50 */
    *lpPeDest++ = *lpPeSrc++; /* Line 592, Address: 0x1023a5c */
  } /* Line 593, Address: 0x1023a8c */

} /* Line 595, Address: 0x1023a9c */




int FadeProc() { /* Line 600, Address: 0x1023ac0 */
  switch (*lpFadeFlag) { /* Line 601, Address: 0x1023ac8 */
    case 1:
      return fadein0_new(); /* Line 603, Address: 0x1023b0c */
    case 2:
      return fadeout_new(); /* Line 605, Address: 0x1023b1c */
    case 3:
      return flashin_new(); /* Line 607, Address: 0x1023b2c */
    case 4:
      return flashout_new(); /* Line 609, Address: 0x1023b3c */
  }
  return 1; /* Line 611, Address: 0x1023b4c */

} /* Line 613, Address: 0x1023b50 */
