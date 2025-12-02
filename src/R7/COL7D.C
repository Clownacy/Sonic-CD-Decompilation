#include "..\EQU.H"
#include "COL7A.H"

static void clchg_sub0(unsigned char** ppChgTim, unsigned char** ppChgCnt, char* pCnttbl, PALETTEENTRY* pPlttbl);
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  64,  64,  32, 1 }, { 224, 224,  64, 1 }, { 160, 192, 128, 1 }, {  96, 160,  96, 1 },
  {  64,  96,  32, 1 }, {  64,  64,   0, 1 }, { 224, 224,   0, 1 }, { 160, 192, 128, 1 },
  { 192, 160,  96, 1 }, { 128,  96,  64, 1 }, {  64,  64,  32, 1 }, { 192, 160, 128, 1 },
  { 128,  96,  64, 1 }, { 224, 192, 160, 1 }, { 224, 160,  96, 1 }, { 160,  96,  64, 1 },
  {  64,  64,  32, 1 }, {  64,  64,  32, 1 }, {  32,  32,   0, 1 }, { 160, 128,  96, 1 },
  { 224, 128, 128, 1 }, { 128,  96,  64, 1 }, { 192,  96,  96, 1 }, { 160,  96,  64, 1 },
  { 160,  64,  32, 1 }, { 128,  64,  32, 1 }, { 192, 128, 128, 1 }, { 192, 128, 160, 1 },
  { 128, 128,  96, 1 }, { 160, 128,  64, 1 }, { 192,  96, 128, 1 }, { 160, 192, 160, 1 }
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
PALETTEENTRY zone8colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  32,   0,   0, 1 }, { 192, 192,  96, 1 }, {   0, 128, 160, 1 }, {   0,  64,  96, 1 },
  {   0,  32,  32, 1 }, {   0,   0,   0, 1 }, { 224, 224, 160, 1 }, { 224, 128,  64, 1 },
  { 128,  96,   0, 1 }, {  64,  32,   0, 1 }, {  32,   0,   0, 1 }, { 128,  32, 192, 1 },
  {  64,  32,  64, 1 }, { 192, 128, 128, 1 }, { 192,  64,  64, 1 }, {  96,   0,   0, 1 },
  {  32,   0,   0, 1 }, {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0, 224, 1 },
  { 160,   0, 160, 1 }, {  96,   0,  96, 1 }, { 160,   0,  64, 1 }, { 128,   0,  32, 1 },
  {  96,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,   0,  96, 1 }, { 224,  96, 192, 1 },
  {  32,  32,  64, 1 }, {  64,  64,  96, 1 }, { 128,   0,  96, 1 }, {  64, 160, 128, 1 }
};
PALETTEENTRY bosscolor[6] = {
  {  32,  32,  32, 1 }, { 224,   0, 128, 1 }, { 224,  96,   0, 1 }, { 224, 224,   0, 1 },
  { 224, 224, 224, 1 }, {   0, 224,   0, 1 }
};
palette_part colortbl[7] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone8colora, 16, 48 },
  { 0, 0, 0 },
  { bosscolor, 16, 6 }
};
static int FadeCount;









































































void clchgctr(void) { /* Line 161, Address: 0x1023c70 */
  unsigned char *pChgTime, *pChgCnt;
  char col6a0cnt[14] = { /* Line 163, Address: 0x1023c78 */
     39,   6,   5,   0,  35,   1,   5,
      0,   5,   1,  10,   0, 100,   1
  };
  PALETTEENTRY col6a0col[4] = { /* Line 167, Address: 0x1023cac */
    { 224, 128,  64, 1 }, {   0,   0,   0, 1 },
    { 224, 128,  64, 1 },
    {   0,   0,   0, 1 }
  };
  char col6a1cnt[8] = { /* Line 172, Address: 0x1023ce0 */
    45,  3,  4,  0,
     4,  1,  4,  2
  };
  PALETTEENTRY col6a1col[6] = { /* Line 176, Address: 0x1023d14 */
    { 192, 128, 128, 1 }, { 192,  64,  64, 1 }, {  96,   0,   0, 1 },
    { 192, 128, 128, 1 }, { 192,  64,  64, 1 }, {  96,   0,   0, 1 }
  };
  char col6a2cnt[8] = { /* Line 180, Address: 0x1023d48 */
    46,  3,  4,  0,
     4,  1,  4,  2
  };
  PALETTEENTRY col6a2col[6] = { /* Line 184, Address: 0x1023d7c */
    { 192,  64,  64, 1 }, {  96,   0,   0, 1 }, { 192, 128, 128, 1 },
    { 192,  64,  64, 1 }, {  96,   0,   0, 1 }, { 192, 128, 128, 1 }
  };
  char col6a3cnt[8] = { /* Line 188, Address: 0x1023db0 */
    47,  3,  4,  0,
     4,  1,  4,  2
  };
  PALETTEENTRY col6a3col[6] = { /* Line 192, Address: 0x1023de4 */
    {  96,   0,   0, 1 }, { 192, 128, 128, 1 }, { 192,  64,   0, 1 },
    {  96,   0,   0, 1 }, { 192, 128, 128, 1 }, { 192,  64,   0, 1 }
  };
  char col6a4cnt[6] = { /* Line 196, Address: 0x1023e18 */
    49,  2,  4,
     0,  4,  1
  };
  PALETTEENTRY col6a4col[4] = { /* Line 200, Address: 0x1023e4c */
    {  32,   0,   0, 1 }, { 160,   0,   0, 1 },
    {  32,   0,   0, 1 }, { 160,   0,   0, 1 }
  };
  char col6a5cnt[18] = { /* Line 204, Address: 0x1023e80 */
     49,   8, 100,   0, 100,   0, 100,   0, 100,
      0, 100,   0,   2,   1,   5,   2,  30,   3
  };
  PALETTEENTRY col6a5col[8] = { /* Line 208, Address: 0x1023eb4 */
    {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, { 192, 128, 160, 1 }, { 128,   0,   0, 1 },
    {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, { 192, 128, 160, 1 }, { 128,   0,   0, 1 }
  };
  char col6a6cnt[18] = { /* Line 212, Address: 0x1023ee8 */
     62,   8, 100,   0, 100,   0, 100,   0, 100,
      0, 100,   0,   2,   1,   5,   2,  30,   3
  };
  PALETTEENTRY col6a6col[8] = { /* Line 216, Address: 0x1023f1c */
    {  32,   0,   0, 1 }, { 192,  96, 160, 1 }, {  32,   0,   0, 1 }, { 192,  96, 160, 1 },
    {  32,   0,   0, 1 }, { 192,  96, 160, 1 }, {  32,   0,   0, 1 }, { 192,  96, 160, 1 }
  };
  char col6a6cnt1[18] = { /* Line 220, Address: 0x1023f50 */
     58,   8, 100,   0, 100,   0, 100,   0, 100,
      0, 100,   0,   2,   1,   5,   2,  30,   3
  };

  pChgTime = clchgtim; /* Line 225, Address: 0x1023f84 */
  pChgCnt = clchgcnt; /* Line 226, Address: 0x1023f90 */

  clchg_sub0(&pChgTime, &pChgCnt, col6a0cnt, col6a0col); /* Line 228, Address: 0x1023f9c */
  clchg_sub0(&pChgTime, &pChgCnt, col6a1cnt, col6a1col); /* Line 229, Address: 0x1023fb4 */
  clchg_sub0(&pChgTime, &pChgCnt, col6a2cnt, col6a2col); /* Line 230, Address: 0x1023fcc */
  clchg_sub0(&pChgTime, &pChgCnt, col6a3cnt, col6a3col); /* Line 231, Address: 0x1023fe4 */
  clchg_sub0(&pChgTime, &pChgCnt, col6a5cnt, col6a5col); /* Line 232, Address: 0x1023ffc */

  if (stageno.b.l) { /* Line 234, Address: 0x1024014 */

    clchg_sub0(&pChgTime, &pChgCnt, col6a6cnt1, col6a6col); /* Line 236, Address: 0x1024024 */
  } else { /* Line 237, Address: 0x102403c */
    clchg_sub0(&pChgTime, &pChgCnt, col6a6cnt, col6a6col); /* Line 238, Address: 0x1024044 */
  }
} /* Line 240, Address: 0x102405c */



void clchg_sub0(unsigned char** ppChgTim, unsigned char** ppChgCnt, char* pCnttbl, PALETTEENTRY* pPlttbl) { /* Line 244, Address: 0x1024070 */
  short idx, cnt, timwk;
  PALETTEENTRY* pPalet;

  if (--**(char**)ppChgTim < 0) { /* Line 248, Address: 0x1024094 */
    idx = *pCnttbl++; /* Line 249, Address: 0x10240c4 */
    cnt = *pCnttbl++; /* Line 250, Address: 0x10240e4 */

    pPalet = &lpcolorwk[idx]; /* Line 252, Address: 0x1024104 */
    timwk = **ppChgCnt; /* Line 253, Address: 0x102411c */
    if (++timwk >= cnt) { /* Line 254, Address: 0x1024134 */
      timwk = 0; /* Line 255, Address: 0x1024164 */
    }
    **ppChgCnt = timwk; /* Line 257, Address: 0x1024168 */

    timwk *= 2; /* Line 259, Address: 0x1024178 */
    **ppChgTim = pCnttbl[timwk]; /* Line 260, Address: 0x1024184 */
    timwk = (pCnttbl + timwk)[1]; /* Line 261, Address: 0x10241a4 */
    *pPalet = pPlttbl[timwk]; /* Line 262, Address: 0x10241c8 */
    cnt += timwk; /* Line 263, Address: 0x10241fc */
    lpcolorwk3[idx] = pPlttbl[cnt]; /* Line 264, Address: 0x1024208 */
  }


  ++*ppChgCnt; /* Line 268, Address: 0x1024254 */
  ++*ppChgTim; /* Line 269, Address: 0x1024268 */
} /* Line 270, Address: 0x102427c */







void fadein0(void) { /* Line 278, Address: 0x10242a0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 282, Address: 0x10242ac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 284, Address: 0x10242e0 */
    lpPe->peRed = 0; /* Line 285, Address: 0x10242ec */
    lpPe->peGreen = 0; /* Line 286, Address: 0x10242f0 */
    lpPe->peBlue = 0; /* Line 287, Address: 0x10242f4 */
    lpPe->peFlags = 1; /* Line 288, Address: 0x10242f8 */
    ++lpPe; /* Line 289, Address: 0x1024300 */
  } /* Line 290, Address: 0x1024304 */
  FadeCount = 0; /* Line 291, Address: 0x1024320 */
  *lpFadeFlag = 1; /* Line 292, Address: 0x1024328 */

} /* Line 294, Address: 0x1024338 */



int fadein0_new(void) { /* Line 298, Address: 0x1024350 */

  int_flg = 18; /* Line 300, Address: 0x1024358 */

  fadein1(); /* Line 302, Address: 0x1024364 */


  if (++FadeCount > 21) { /* Line 305, Address: 0x102436c */
    FadeCount = 0; /* Line 306, Address: 0x102438c */
    return 1; /* Line 307, Address: 0x1024394 */
  }
  return 0; /* Line 309, Address: 0x10243a0 */
} /* Line 310, Address: 0x10243a4 */



static void fadein1(void) { /* Line 314, Address: 0x10243c0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 318, Address: 0x10243d4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 319, Address: 0x1024408 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 321, Address: 0x102443c */
    fadein2(lpPe, lpPe2); /* Line 322, Address: 0x1024448 */
    ++lpPe; /* Line 323, Address: 0x1024458 */
    ++lpPe2; /* Line 324, Address: 0x102445c */
  } /* Line 325, Address: 0x1024460 */
  if (stageno.b.h == 1) return; /* Line 326, Address: 0x102447c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 328, Address: 0x1024498 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 329, Address: 0x10244cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 331, Address: 0x1024500 */
    fadein2(lpPe, lpPe2); /* Line 332, Address: 0x102450c */
    ++lpPe; /* Line 333, Address: 0x102451c */
    ++lpPe2; /* Line 334, Address: 0x1024520 */
  } /* Line 335, Address: 0x1024524 */



} /* Line 339, Address: 0x1024540 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 343, Address: 0x1024560 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 344, Address: 0x102456c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 347, Address: 0x10245cc */
      lpPeDest->peBlue += 32; /* Line 348, Address: 0x10245f0 */
    } /* Line 349, Address: 0x1024600 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 350, Address: 0x1024608 */
      lpPeDest->peGreen += 32; /* Line 351, Address: 0x102462c */
    } /* Line 352, Address: 0x102463c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 353, Address: 0x1024644 */
      lpPeDest->peRed += 32; /* Line 354, Address: 0x1024668 */
    }
  }

} /* Line 358, Address: 0x102467c */


void fadeout(void) {
  startcolor = 0; /* Line 362, Address: 0x1024690 */
  colorcnt = 63; /* Line 363, Address: 0x1024698 */

  FadeCount = 0; /* Line 365, Address: 0x10246a4 */
  *lpFadeFlag = 2; /* Line 366, Address: 0x10246ac */

} /* Line 368, Address: 0x10246bc */



static int fadeout_new(void) { /* Line 372, Address: 0x10246d0 */

  int_flg = 18; /* Line 374, Address: 0x10246d8 */

  fadeout1(); /* Line 376, Address: 0x10246e4 */


  if (++FadeCount > 21) { /* Line 379, Address: 0x10246ec */
    FadeCount = 0; /* Line 380, Address: 0x102470c */
    return 1; /* Line 381, Address: 0x1024714 */
  }
  return 0; /* Line 383, Address: 0x1024720 */
} /* Line 384, Address: 0x1024724 */


static void fadeout1(void) { /* Line 387, Address: 0x1024740 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 391, Address: 0x1024750 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 393, Address: 0x1024784 */
    fadeout2(lpPe); /* Line 394, Address: 0x1024790 */
    ++lpPe; /* Line 395, Address: 0x102479c */
  } /* Line 396, Address: 0x10247a0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 397, Address: 0x10247bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 399, Address: 0x10247f0 */
    fadeout2(lpPe); /* Line 400, Address: 0x10247fc */
    ++lpPe; /* Line 401, Address: 0x1024808 */
  } /* Line 402, Address: 0x102480c */


} /* Line 405, Address: 0x1024828 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 408, Address: 0x1024840 */
  if (lpPeDest->peRed) { /* Line 409, Address: 0x1024848 */
    lpPeDest->peRed -= 32; /* Line 410, Address: 0x1024858 */
  } /* Line 411, Address: 0x102486c */
  else if (lpPeDest->peGreen) { /* Line 412, Address: 0x1024874 */
    lpPeDest->peGreen -= 32; /* Line 413, Address: 0x1024884 */
  } /* Line 414, Address: 0x1024894 */
  else if (lpPeDest->peBlue) { /* Line 415, Address: 0x102489c */
    lpPeDest->peBlue -= 32; /* Line 416, Address: 0x10248ac */
  }

} /* Line 419, Address: 0x10248bc */




void flashin(void) { /* Line 424, Address: 0x10248d0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 428, Address: 0x10248dc */
  colorcnt = 63; /* Line 429, Address: 0x10248e4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 431, Address: 0x10248f0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 433, Address: 0x1024924 */
    lpPe->peRed = 224; /* Line 434, Address: 0x1024930 */
    lpPe->peGreen = 224; /* Line 435, Address: 0x1024938 */
    lpPe->peBlue = 224; /* Line 436, Address: 0x1024940 */
    lpPe->peFlags = 1; /* Line 437, Address: 0x1024948 */
    ++lpPe; /* Line 438, Address: 0x1024950 */
  } /* Line 439, Address: 0x1024954 */
  FadeCount = 0; /* Line 440, Address: 0x1024970 */
  *lpFadeFlag = 3; /* Line 441, Address: 0x1024978 */

} /* Line 443, Address: 0x1024988 */

static int flashin_new(void) { /* Line 445, Address: 0x10249a0 */

  int_flg = 18; /* Line 447, Address: 0x10249a8 */

  flashin1(); /* Line 449, Address: 0x10249b4 */


  if (++FadeCount > 21) { /* Line 452, Address: 0x10249bc */
    FadeCount = 0; /* Line 453, Address: 0x10249dc */
    return 1; /* Line 454, Address: 0x10249e4 */
  }
  return 0; /* Line 456, Address: 0x10249f0 */
} /* Line 457, Address: 0x10249f4 */

static void flashin1(void) { /* Line 459, Address: 0x1024a10 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 463, Address: 0x1024a24 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 464, Address: 0x1024a58 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 466, Address: 0x1024a8c */
    flashin2(lpPe, lpPe2); /* Line 467, Address: 0x1024a98 */
    ++lpPe; /* Line 468, Address: 0x1024aa8 */
    ++lpPe2; /* Line 469, Address: 0x1024aac */
  } /* Line 470, Address: 0x1024ab0 */
  if (stageno.b.h == 1) return; /* Line 471, Address: 0x1024acc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 473, Address: 0x1024ae8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 474, Address: 0x1024b1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 476, Address: 0x1024b50 */
    flashin2(lpPe, lpPe2); /* Line 477, Address: 0x1024b5c */
    ++lpPe; /* Line 478, Address: 0x1024b6c */
    ++lpPe2; /* Line 479, Address: 0x1024b70 */
  } /* Line 480, Address: 0x1024b74 */



} /* Line 484, Address: 0x1024b90 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 488, Address: 0x1024bb0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 489, Address: 0x1024bbc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 492, Address: 0x1024c1c */
      lpPeDest->peBlue -= 32; /* Line 493, Address: 0x1024c40 */
    } /* Line 494, Address: 0x1024c50 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 495, Address: 0x1024c58 */
      lpPeDest->peGreen -= 32; /* Line 496, Address: 0x1024c7c */
    } /* Line 497, Address: 0x1024c8c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 498, Address: 0x1024c94 */
      lpPeDest->peRed -= 32; /* Line 499, Address: 0x1024cb8 */
    }
  }

} /* Line 503, Address: 0x1024ccc */


void flashout(void) {
  startcolor = 0; /* Line 507, Address: 0x1024ce0 */
  colorcnt = 63; /* Line 508, Address: 0x1024ce8 */

  FadeCount = 0; /* Line 510, Address: 0x1024cf4 */
  *lpFadeFlag = 4; /* Line 511, Address: 0x1024cfc */

} /* Line 513, Address: 0x1024d0c */

static int flashout_new(void) { /* Line 515, Address: 0x1024d20 */

  int_flg = 18; /* Line 517, Address: 0x1024d28 */

  flashout1(); /* Line 519, Address: 0x1024d34 */


  if (++FadeCount > 21) { /* Line 522, Address: 0x1024d3c */
    FadeCount = 0; /* Line 523, Address: 0x1024d5c */
    return 1; /* Line 524, Address: 0x1024d64 */
  }
  return 0; /* Line 526, Address: 0x1024d70 */
} /* Line 527, Address: 0x1024d74 */


static void flashout1(void) { /* Line 530, Address: 0x1024d90 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 534, Address: 0x1024da0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 536, Address: 0x1024dd4 */
    flashout2(lpPe); /* Line 537, Address: 0x1024de0 */
    ++lpPe; /* Line 538, Address: 0x1024dec */
  } /* Line 539, Address: 0x1024df0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 540, Address: 0x1024e0c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 542, Address: 0x1024e40 */
    flashout2(lpPe); /* Line 543, Address: 0x1024e4c */
    ++lpPe; /* Line 544, Address: 0x1024e58 */
  } /* Line 545, Address: 0x1024e5c */


} /* Line 548, Address: 0x1024e78 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 551, Address: 0x1024e90 */
  if (lpPeDest->peRed != 224) { /* Line 552, Address: 0x1024e98 */
    lpPeDest->peRed += 32; /* Line 553, Address: 0x1024eb0 */
  } /* Line 554, Address: 0x1024ec4 */
  else if (lpPeDest->peGreen != 224) { /* Line 555, Address: 0x1024ecc */
    lpPeDest->peGreen += 32; /* Line 556, Address: 0x1024ee4 */
  } /* Line 557, Address: 0x1024ef4 */
  else if (lpPeDest->peBlue != 224) { /* Line 558, Address: 0x1024efc */
    lpPeDest->peBlue += 32; /* Line 559, Address: 0x1024f14 */
  }


} /* Line 563, Address: 0x1024f24 */


void colorset(int ColorNo) { /* Line 566, Address: 0x1024f30 */
  colorset00(ColorNo, 1); /* Line 567, Address: 0x1024f3c */
} /* Line 568, Address: 0x1024f4c */

void colorset2(int ColorNo) { /* Line 570, Address: 0x1024f60 */
  colorset00(ColorNo, 0); /* Line 571, Address: 0x1024f6c */
} /* Line 572, Address: 0x1024f7c */

void colorset3(int ColorNo) { /* Line 574, Address: 0x1024f90 */
  colorset00(ColorNo, 1); /* Line 575, Address: 0x1024f9c */
} /* Line 576, Address: 0x1024fac */

void colorset4(int ColorNo) { /* Line 578, Address: 0x1024fc0 */
  colorset00(ColorNo, 2); /* Line 579, Address: 0x1024fcc */
} /* Line 580, Address: 0x1024fdc */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 586, Address: 0x1024ff0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 591, Address: 0x1025010 */
    case 0:
      lppe = lpcolorwk; break; /* Line 593, Address: 0x1025078 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 595, Address: 0x1025088 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 597, Address: 0x1025098 */
    default:
      lppe = lpcolorwk4; break; /* Line 599, Address: 0x10250a8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 602, Address: 0x10250b0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 603, Address: 0x10250c8 */
  n = colortbl[ColorNo].cnt; /* Line 604, Address: 0x10250f0 */
  for (i = 0; i < n; ++i) { /* Line 605, Address: 0x1025110 */
    *lpPeDest++ = *lpPeSrc++; /* Line 606, Address: 0x102511c */
  } /* Line 607, Address: 0x102514c */

} /* Line 609, Address: 0x102515c */




int FadeProc(void) { /* Line 614, Address: 0x1025180 */
  switch (*lpFadeFlag) { /* Line 615, Address: 0x1025188 */
    case 1:
      return fadein0_new(); /* Line 617, Address: 0x10251cc */
    case 2:
      return fadeout_new(); /* Line 619, Address: 0x10251dc */
    case 3:
      return flashin_new(); /* Line 621, Address: 0x10251ec */
    case 4:
      return flashout_new(); /* Line 623, Address: 0x10251fc */
  }
  return 1; /* Line 625, Address: 0x102520c */

} /* Line 627, Address: 0x1025210 */
