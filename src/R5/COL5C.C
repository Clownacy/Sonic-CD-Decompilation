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
  {   0,   0,   0, 1 }, { 224, 224, 160, 1 }, {   0,   0,   0, 1 }, {  64,  64,  96, 1 },
  {   0,   0,  32, 1 }, {   0,   0,  96, 1 }, {  32,  32, 192, 1 }, {   0, 160, 224, 1 },
  { 224, 192,   0, 1 }, { 160,  96,   0, 1 }, {   0,  32,   0, 1 }, {   0, 128,   0, 1 },
  {  32, 192,  96, 1 }, {  64,  32,   0, 1 }, {  32,   0,  32, 1 }, {  96,  96, 128, 1 },
  {   0,   0,   0, 1 }, {   0,  32,  32, 1 }, {   0,  64,  64, 1 }, {   0, 128, 128, 1 },
  {   0, 224, 224, 1 }, {   0,  32,   0, 1 }, {   0,  96,   0, 1 }, {   0, 192,   0, 1 },
  { 224, 224,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,  32, 1 }, {   0,   0,  64, 1 },
  {  32,   0,  96, 1 }, {  64,   0, 224, 1 }, { 192,   0, 224, 1 }, { 192, 128, 224, 1 }
};
PALETTEENTRY zone5color1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  { 128, 128, 224, 1 }, { 160,   0,  96, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224,  64, 128, 1 }, { 224, 128, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  64, 128, 224, 1 }, { 224, 224, 160, 1 }, {   0,   0,   0, 1 }, {  64,  64,  96, 1 },
  {   0,   0,  32, 1 }, {   0,   0,  96, 1 }, {  32,  32, 192, 1 }, {   0, 160, 224, 1 },
  { 224, 192,   0, 1 }, { 160,  96,   0, 1 }, {   0,  32,   0, 1 }, {   0, 128,   0, 1 },
  {  32, 192,  96, 1 }, {  64,  32,   0, 1 }, {  32,   0,  32, 1 }, {  96,  96, 128, 1 },
  {  64, 128, 224, 1 }, {  64,  32, 128, 1 }, {  96,   0, 160, 1 }, { 192,   0, 224, 1 },
  { 224,  96, 192, 1 }, {   0,  32,  32, 1 }, {   0,  64,  64, 1 }, {   0, 128, 128, 1 },
  {   0, 192, 192, 1 }, { 160, 224, 224, 1 }, {   0,  32,   0, 1 }, {   0, 128,   0, 1 },
  {  64, 224,   0, 1 }, { 224, 224,   0, 1 }, { 224, 224, 192, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY zone5colboss0[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 160,  96, 160, 1 }, {  32,   0,  32, 1 },
  {  64,  32,  64, 1 }, {  96,  64,  96, 1 }, { 224, 224, 224, 1 }, { 224, 160, 224, 1 },
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










































































void clchgctr(void) { /* Line 187, Address: 0x101b940 */
  unsigned char *pChgTime, *pChgCnt;
  color_change_data colchg50 = { /* Line 189, Address: 0x101b948 */
    42, 3, 3, 4,
    {
      {   0,  32,   0, 1 }, {   0, 128,   0, 1 }, {  32, 192,  96, 1 },
      {  32, 192,  96, 1 }, {   0,  32,   0, 1 }, {   0, 128,   0, 1 },
      {   0, 128,   0, 1 }, {  32, 192,  96, 1 }, {   0,  32,   0, 1 }
    }
  };
  color_change_data colchg51 = { /* Line 197, Address: 0x101b984 */
    42, 3, 3, 4,
    {
      {  64,   0,  64, 1 }, { 128,   0, 160, 1 }, { 224,   0, 224, 1 },
      { 128,   0, 160, 1 }, { 224,   0, 224, 1 }, {  64,   0,  64, 1 },
      { 224,   0, 224, 1 }, {  64,   0,  64, 1 }, { 128,   0, 160, 1 }
    }
  };

  if (!bossflag) { /* Line 206, Address: 0x101b9c0 */



    pChgTime = clchgtim; /* Line 210, Address: 0x101b9d0 */
    pChgCnt = clchgcnt; /* Line 211, Address: 0x101b9dc */


    if (!colrevflag) { /* Line 214, Address: 0x101b9e8 */
      colchgsub(&pChgTime, &pChgCnt, &colchg50); /* Line 215, Address: 0x101b9f8 */
    } else { /* Line 216, Address: 0x101ba0c */
      colchgsub(&pChgTime, &pChgCnt, &colchg51); /* Line 217, Address: 0x101ba14 */
    }
  }
} /* Line 220, Address: 0x101ba28 */



static void colchgsub(unsigned char** ppChgTime, unsigned char** ppChgCnt, color_change_data* pColortbl) { /* Line 224, Address: 0x101ba40 */
  short cnt;
  PALETTEENTRY *pPalet, *pColtbl;
  int i;

  if ((char)--**ppChgTime < 0) { /* Line 229, Address: 0x101ba60 */
    **ppChgTime = pColortbl->time; /* Line 230, Address: 0x101ba94 */
    if ((cnt = **ppChgCnt + 1) >= pColortbl->tate) { /* Line 231, Address: 0x101baa8 */
      cnt = 0; /* Line 232, Address: 0x101baf4 */
    }


    **ppChgCnt = cnt; /* Line 236, Address: 0x101baf8 */


    cnt *= pColortbl->yoko; /* Line 239, Address: 0x101bb08 */
    pPalet = &lpcolorwk[pColortbl->adr]; /* Line 240, Address: 0x101bb20 */
    pColtbl = &pColortbl->colortbl[cnt]; /* Line 241, Address: 0x101bb3c */

    for (i = 0; i < pColortbl->yoko; ++i) { /* Line 243, Address: 0x101bb54 */
      *pPalet++ = *pColtbl++; /* Line 244, Address: 0x101bb60 */
    } /* Line 245, Address: 0x101bb90 */
  }


  ++*ppChgTime; /* Line 249, Address: 0x101bbac */
  ++*ppChgCnt; /* Line 250, Address: 0x101bbc0 */
} /* Line 251, Address: 0x101bbd4 */







void fadein0(void) { /* Line 259, Address: 0x101bbf0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 263, Address: 0x101bbfc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 265, Address: 0x101bc30 */
    lpPe->peRed = 0; /* Line 266, Address: 0x101bc3c */
    lpPe->peGreen = 0; /* Line 267, Address: 0x101bc40 */
    lpPe->peBlue = 0; /* Line 268, Address: 0x101bc44 */
    lpPe->peFlags = 1; /* Line 269, Address: 0x101bc48 */
    ++lpPe; /* Line 270, Address: 0x101bc50 */
  } /* Line 271, Address: 0x101bc54 */
  FadeCount = 0; /* Line 272, Address: 0x101bc70 */
  *lpFadeFlag = 1; /* Line 273, Address: 0x101bc78 */

} /* Line 275, Address: 0x101bc88 */



int fadein0_new(void) { /* Line 279, Address: 0x101bca0 */

  int_flg = 18; /* Line 281, Address: 0x101bca8 */

  fadein1(); /* Line 283, Address: 0x101bcb4 */


  if (++FadeCount > 21) { /* Line 286, Address: 0x101bcbc */
    FadeCount = 0; /* Line 287, Address: 0x101bcdc */
    return 1; /* Line 288, Address: 0x101bce4 */
  }
  return 0; /* Line 290, Address: 0x101bcf0 */
} /* Line 291, Address: 0x101bcf4 */



static void fadein1(void) { /* Line 295, Address: 0x101bd10 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 299, Address: 0x101bd24 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 300, Address: 0x101bd58 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 302, Address: 0x101bd8c */
    fadein2(lpPe, lpPe2); /* Line 303, Address: 0x101bd98 */
    ++lpPe; /* Line 304, Address: 0x101bda8 */
    ++lpPe2; /* Line 305, Address: 0x101bdac */
  } /* Line 306, Address: 0x101bdb0 */
  if (stageno.b.h == 1) return; /* Line 307, Address: 0x101bdcc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 309, Address: 0x101bde8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 310, Address: 0x101be1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 312, Address: 0x101be50 */
    fadein2(lpPe, lpPe2); /* Line 313, Address: 0x101be5c */
    ++lpPe; /* Line 314, Address: 0x101be6c */
    ++lpPe2; /* Line 315, Address: 0x101be70 */
  } /* Line 316, Address: 0x101be74 */



} /* Line 320, Address: 0x101be90 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 324, Address: 0x101beb0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 325, Address: 0x101bebc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 328, Address: 0x101bf1c */
      lpPeDest->peBlue += 32; /* Line 329, Address: 0x101bf40 */
    } /* Line 330, Address: 0x101bf50 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 331, Address: 0x101bf58 */
      lpPeDest->peGreen += 32; /* Line 332, Address: 0x101bf7c */
    } /* Line 333, Address: 0x101bf8c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 334, Address: 0x101bf94 */
      lpPeDest->peRed += 32; /* Line 335, Address: 0x101bfb8 */
    }
  }

} /* Line 339, Address: 0x101bfcc */


void fadeout(void) {
  startcolor = 0; /* Line 343, Address: 0x101bfe0 */
  colorcnt = 63; /* Line 344, Address: 0x101bfe8 */

  FadeCount = 0; /* Line 346, Address: 0x101bff4 */
  *lpFadeFlag = 2; /* Line 347, Address: 0x101bffc */

} /* Line 349, Address: 0x101c00c */



static int fadeout_new(void) { /* Line 353, Address: 0x101c020 */

  int_flg = 18; /* Line 355, Address: 0x101c028 */

  fadeout1(); /* Line 357, Address: 0x101c034 */


  if (++FadeCount > 21) { /* Line 360, Address: 0x101c03c */
    FadeCount = 0; /* Line 361, Address: 0x101c05c */
    return 1; /* Line 362, Address: 0x101c064 */
  }
  return 0; /* Line 364, Address: 0x101c070 */
} /* Line 365, Address: 0x101c074 */


static void fadeout1(void) { /* Line 368, Address: 0x101c090 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 372, Address: 0x101c0a0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 374, Address: 0x101c0d4 */
    fadeout2(lpPe); /* Line 375, Address: 0x101c0e0 */
    ++lpPe; /* Line 376, Address: 0x101c0ec */
  } /* Line 377, Address: 0x101c0f0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 378, Address: 0x101c10c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 380, Address: 0x101c140 */
    fadeout2(lpPe); /* Line 381, Address: 0x101c14c */
    ++lpPe; /* Line 382, Address: 0x101c158 */
  } /* Line 383, Address: 0x101c15c */


} /* Line 386, Address: 0x101c178 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 389, Address: 0x101c190 */
  if (lpPeDest->peRed) { /* Line 390, Address: 0x101c198 */
    lpPeDest->peRed -= 32; /* Line 391, Address: 0x101c1a8 */
  } /* Line 392, Address: 0x101c1bc */
  else if (lpPeDest->peGreen) { /* Line 393, Address: 0x101c1c4 */
    lpPeDest->peGreen -= 32; /* Line 394, Address: 0x101c1d4 */
  } /* Line 395, Address: 0x101c1e4 */
  else if (lpPeDest->peBlue) { /* Line 396, Address: 0x101c1ec */
    lpPeDest->peBlue -= 32; /* Line 397, Address: 0x101c1fc */
  }

} /* Line 400, Address: 0x101c20c */




void flashin(void) { /* Line 405, Address: 0x101c220 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 409, Address: 0x101c22c */
  colorcnt = 63; /* Line 410, Address: 0x101c234 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 412, Address: 0x101c240 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 414, Address: 0x101c274 */
    lpPe->peRed = 224; /* Line 415, Address: 0x101c280 */
    lpPe->peGreen = 224; /* Line 416, Address: 0x101c288 */
    lpPe->peBlue = 224; /* Line 417, Address: 0x101c290 */
    lpPe->peFlags = 1; /* Line 418, Address: 0x101c298 */
    ++lpPe; /* Line 419, Address: 0x101c2a0 */
  } /* Line 420, Address: 0x101c2a4 */
  FadeCount = 0; /* Line 421, Address: 0x101c2c0 */
  *lpFadeFlag = 3; /* Line 422, Address: 0x101c2c8 */

} /* Line 424, Address: 0x101c2d8 */

static int flashin_new(void) { /* Line 426, Address: 0x101c2f0 */

  int_flg = 18; /* Line 428, Address: 0x101c2f8 */

  flashin1(); /* Line 430, Address: 0x101c304 */


  if (++FadeCount > 21) { /* Line 433, Address: 0x101c30c */
    FadeCount = 0; /* Line 434, Address: 0x101c32c */
    return 1; /* Line 435, Address: 0x101c334 */
  }
  return 0; /* Line 437, Address: 0x101c340 */
} /* Line 438, Address: 0x101c344 */

static void flashin1(void) { /* Line 440, Address: 0x101c360 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 444, Address: 0x101c374 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 445, Address: 0x101c3a8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 447, Address: 0x101c3dc */
    flashin2(lpPe, lpPe2); /* Line 448, Address: 0x101c3e8 */
    ++lpPe; /* Line 449, Address: 0x101c3f8 */
    ++lpPe2; /* Line 450, Address: 0x101c3fc */
  } /* Line 451, Address: 0x101c400 */
  if (stageno.b.h == 1) return; /* Line 452, Address: 0x101c41c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 454, Address: 0x101c438 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 455, Address: 0x101c46c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 457, Address: 0x101c4a0 */
    flashin2(lpPe, lpPe2); /* Line 458, Address: 0x101c4ac */
    ++lpPe; /* Line 459, Address: 0x101c4bc */
    ++lpPe2; /* Line 460, Address: 0x101c4c0 */
  } /* Line 461, Address: 0x101c4c4 */



} /* Line 465, Address: 0x101c4e0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 469, Address: 0x101c500 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 470, Address: 0x101c50c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 473, Address: 0x101c56c */
      lpPeDest->peBlue -= 32; /* Line 474, Address: 0x101c590 */
    } /* Line 475, Address: 0x101c5a0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 476, Address: 0x101c5a8 */
      lpPeDest->peGreen -= 32; /* Line 477, Address: 0x101c5cc */
    } /* Line 478, Address: 0x101c5dc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 479, Address: 0x101c5e4 */
      lpPeDest->peRed -= 32; /* Line 480, Address: 0x101c608 */
    }
  }

} /* Line 484, Address: 0x101c61c */


void flashout(void) {
  startcolor = 0; /* Line 488, Address: 0x101c630 */
  colorcnt = 63; /* Line 489, Address: 0x101c638 */

  FadeCount = 0; /* Line 491, Address: 0x101c644 */
  *lpFadeFlag = 4; /* Line 492, Address: 0x101c64c */

} /* Line 494, Address: 0x101c65c */

static int flashout_new(void) { /* Line 496, Address: 0x101c670 */

  int_flg = 18; /* Line 498, Address: 0x101c678 */

  flashout1(); /* Line 500, Address: 0x101c684 */


  if (++FadeCount > 21) { /* Line 503, Address: 0x101c68c */
    FadeCount = 0; /* Line 504, Address: 0x101c6ac */
    return 1; /* Line 505, Address: 0x101c6b4 */
  }
  return 0; /* Line 507, Address: 0x101c6c0 */
} /* Line 508, Address: 0x101c6c4 */


static void flashout1(void) { /* Line 511, Address: 0x101c6e0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 515, Address: 0x101c6f0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 517, Address: 0x101c724 */
    flashout2(lpPe); /* Line 518, Address: 0x101c730 */
    ++lpPe; /* Line 519, Address: 0x101c73c */
  } /* Line 520, Address: 0x101c740 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 521, Address: 0x101c75c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 523, Address: 0x101c790 */
    flashout2(lpPe); /* Line 524, Address: 0x101c79c */
    ++lpPe; /* Line 525, Address: 0x101c7a8 */
  } /* Line 526, Address: 0x101c7ac */


} /* Line 529, Address: 0x101c7c8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 532, Address: 0x101c7e0 */
  if (lpPeDest->peRed != 224) { /* Line 533, Address: 0x101c7e8 */
    lpPeDest->peRed += 32; /* Line 534, Address: 0x101c800 */
  } /* Line 535, Address: 0x101c814 */
  else if (lpPeDest->peGreen != 224) { /* Line 536, Address: 0x101c81c */
    lpPeDest->peGreen += 32; /* Line 537, Address: 0x101c834 */
  } /* Line 538, Address: 0x101c844 */
  else if (lpPeDest->peBlue != 224) { /* Line 539, Address: 0x101c84c */
    lpPeDest->peBlue += 32; /* Line 540, Address: 0x101c864 */
  }


} /* Line 544, Address: 0x101c874 */


void colorset(int ColorNo) { /* Line 547, Address: 0x101c880 */
  colorset00(ColorNo, 1); /* Line 548, Address: 0x101c88c */
} /* Line 549, Address: 0x101c89c */

void colorset2(int ColorNo) { /* Line 551, Address: 0x101c8b0 */
  colorset00(ColorNo, 0); /* Line 552, Address: 0x101c8bc */
} /* Line 553, Address: 0x101c8cc */

void colorset3(int ColorNo) { /* Line 555, Address: 0x101c8e0 */
  colorset00(ColorNo, 1); /* Line 556, Address: 0x101c8ec */
} /* Line 557, Address: 0x101c8fc */

void colorset4(int ColorNo) { /* Line 559, Address: 0x101c910 */
  colorset00(ColorNo, 2); /* Line 560, Address: 0x101c91c */
} /* Line 561, Address: 0x101c92c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 567, Address: 0x101c940 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 572, Address: 0x101c960 */
    case 0:
      lppe = lpcolorwk; break; /* Line 574, Address: 0x101c9c8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 576, Address: 0x101c9d8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 578, Address: 0x101c9e8 */
    default:
      lppe = lpcolorwk4; break; /* Line 580, Address: 0x101c9f8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 583, Address: 0x101ca00 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 584, Address: 0x101ca18 */
  n = colortbl[ColorNo].cnt; /* Line 585, Address: 0x101ca40 */
  for (i = 0; i < n; ++i) { /* Line 586, Address: 0x101ca60 */
    *lpPeDest++ = *lpPeSrc++; /* Line 587, Address: 0x101ca6c */
  } /* Line 588, Address: 0x101ca9c */

} /* Line 590, Address: 0x101caac */




int FadeProc(void) { /* Line 595, Address: 0x101cad0 */
  switch (*lpFadeFlag) { /* Line 596, Address: 0x101cad8 */
    case 1:
      return fadein0_new(); /* Line 598, Address: 0x101cb1c */
    case 2:
      return fadeout_new(); /* Line 600, Address: 0x101cb2c */
    case 3:
      return flashin_new(); /* Line 602, Address: 0x101cb3c */
    case 4:
      return flashout_new(); /* Line 604, Address: 0x101cb4c */
  }
  return 1; /* Line 606, Address: 0x101cb5c */

} /* Line 608, Address: 0x101cb60 */
