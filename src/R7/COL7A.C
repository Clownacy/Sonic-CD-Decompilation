#include "..\EQU.H"
#include "COL7A.H"

static void clchg_sub0(unsigned char** ppChgTim, unsigned char** ppChgCnt, char* pCnttbl, PALETTEENTRY* pPlttbl);
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, { 160, 224, 160, 1 }, { 128, 224,   0, 1 }, {  96, 160,   0, 1 },
  {  32,  96,   0, 1 }, {   0,  64,   0, 1 }, { 160,  96,   0, 1 }, {   0, 128,   0, 1 },
  {  96, 192,  96, 1 }, {  64, 224,  64, 1 }, {  32,  64,   0, 1 }, { 128, 192, 128, 1 },
  {  64,  96,  64, 1 }, {  32,  64,  32, 1 }, { 160, 192,   0, 1 }, { 128, 192, 160, 1 },
  {   0,   0,  32, 1 }, {   0,   0,   0, 1 }, {  32,   0,  96, 1 }, {  96,   0, 192, 1 },
  { 160,   0, 160, 1 }, {   0,  64, 224, 1 }, { 224,  96, 224, 1 }, { 128,   0,  64, 1 },
  { 224,   0, 224, 1 }, { 224, 192, 224, 1 }, { 160, 128,   0, 1 }, {  64,  64,   0, 1 },
  {  32,  32,   0, 1 }, { 160, 224,   0, 1 }, { 224, 224, 224, 1 }, {   0, 224,   0, 1 }
};
PALETTEENTRY gamecolor[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, { 192, 192, 192, 1 }, { 192, 192,   0, 1 }, { 128,  96,   0, 1 },
  {  64,  32,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 }, {   0,  96,  64, 1 },
  {  64, 160,  96, 1 }, {   0, 224,   0, 1 }, {  32,   0,   0, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {  32,  32,  32, 1 }, { 192,  96,   0, 1 }, {   0,   0, 224, 1 },
  {   0,   0,  32, 1 }, {   0,   0,   0, 1 }, {  32,   0,  96, 1 }, {  96,   0, 192, 1 },
  { 160,   0, 160, 1 }, {   0,  64, 224, 1 }, { 224,  96, 224, 1 }, { 128,   0,  64, 1 },
  { 224,   0, 224, 1 }, { 224, 192, 224, 1 }, { 160, 128,   0, 1 }, {  64,  64,   0, 1 },
  {  32,  32,   0, 1 }, { 160, 224,   0, 1 }, { 224, 224, 224, 1 }, {   0, 224,   0, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, { 192, 192, 192, 1 }, { 192, 192,   0, 1 }, { 128,  96,   0, 1 },
  {  64,  32,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 }, {   0,  96,  64, 1 },
  {  64, 160,  96, 1 }, {   0, 224,   0, 1 }, {  32,   0,   0, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {  32,  32,  32, 1 }, { 192,  96,   0, 1 }, {   0,   0, 224, 1 },
  {   0,   0,  32, 1 }, {   0,   0,   0, 1 }, {  32,   0,  96, 1 }, {  96,   0, 192, 1 },
  { 160,   0, 160, 1 }, {   0,  64, 224, 1 }, { 224,  96, 224, 1 }, { 128,   0,  64, 1 },
  { 224,   0, 224, 1 }, { 224, 192, 224, 1 }, { 160, 128,   0, 1 }, {  64,  64,   0, 1 },
  {  32,  32,   0, 1 }, { 160, 224,   0, 1 }, { 224, 224, 224, 1 }, {   0, 224,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { gamecolor, 0, 64 },
  { gamecolor, 0, 16 },
  { &gamecolor[16], 16, 48 },
  { zone82colora, 16, 48 }
};
static int FadeCount;













































































void clchgctr() { /* Line 154, Address: 0x101cbb0 */
  unsigned char *pChgTime, *pChgCnt;
  char col6a0cnt[6] = { /* Line 156, Address: 0x101cbb8 */
    41,  2,  4,
     0,  4,  1
  };
  PALETTEENTRY col6a0col[4] = { /* Line 160, Address: 0x101cbec */
    {   0, 224,   0, 1 }, {   0,   0,   0, 1 },
    {   0, 224,   0, 1 }, {   0,   0,   0, 1 }
  };
  char col6a1cnt[6] = { /* Line 164, Address: 0x101cc20 */
    62,  2,  4,
     0,  4,  1
  };
  PALETTEENTRY col6a1col[4] = { /* Line 168, Address: 0x101cc54 */
    { 224, 224, 224, 1 }, {  32,   0,   0, 1 },
    { 224, 224, 224, 1 }, {  32,   0,   0, 1 }
  };
  char col6a2cnt[6] = { /* Line 172, Address: 0x101cc88 */
    63,  2,  4,
     0,  4,  1
  };
  PALETTEENTRY col6a2col[4] = { /* Line 176, Address: 0x101ccbc */
    {   0, 224,   0, 1 }, {  32,   0,   0, 1 },
    {   0, 224,   0, 1 }, {  32,   0,   0, 1 }
  };

  pChgTime = clchgtim; /* Line 181, Address: 0x101ccf0 */
  pChgCnt = clchgcnt; /* Line 182, Address: 0x101ccfc */

  clchg_sub0(&pChgTime, &pChgCnt, col6a0cnt, col6a0col); /* Line 184, Address: 0x101cd08 */
  clchg_sub0(&pChgTime, &pChgCnt, col6a1cnt, col6a1col); /* Line 185, Address: 0x101cd20 */
  clchg_sub0(&pChgTime, &pChgCnt, col6a2cnt, col6a2col); /* Line 186, Address: 0x101cd38 */
} /* Line 187, Address: 0x101cd50 */



static void clchg_sub0(unsigned char** ppChgTim, unsigned char** ppChgCnt, char* pCnttbl, PALETTEENTRY* pPlttbl) { /* Line 191, Address: 0x101cd60 */
  short idx, cnt, timwk;
  PALETTEENTRY* pPalet;

  if (--**(char**)ppChgTim < 0) { /* Line 195, Address: 0x101cd84 */
    idx = *pCnttbl++; /* Line 196, Address: 0x101cdb4 */
    cnt = *pCnttbl++; /* Line 197, Address: 0x101cdd4 */

    pPalet = &lpcolorwk[idx]; /* Line 199, Address: 0x101cdf4 */
    timwk = **ppChgCnt; /* Line 200, Address: 0x101ce0c */
    if (++timwk >= cnt) { /* Line 201, Address: 0x101ce24 */
      timwk = 0; /* Line 202, Address: 0x101ce54 */
    }
    **ppChgCnt = timwk; /* Line 204, Address: 0x101ce58 */

    timwk *= 2; /* Line 206, Address: 0x101ce68 */
    **ppChgTim = pCnttbl[timwk]; /* Line 207, Address: 0x101ce74 */
    timwk = (pCnttbl + timwk)[1]; /* Line 208, Address: 0x101ce94 */
    *pPalet = pPlttbl[timwk]; /* Line 209, Address: 0x101ceb8 */
    cnt += timwk; /* Line 210, Address: 0x101ceec */
    lpcolorwk3[idx] = pPlttbl[cnt]; /* Line 211, Address: 0x101cef8 */
  }


  ++*ppChgCnt; /* Line 215, Address: 0x101cf44 */
  ++*ppChgTim; /* Line 216, Address: 0x101cf58 */
} /* Line 217, Address: 0x101cf6c */







void fadein0() { /* Line 225, Address: 0x101cf90 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 229, Address: 0x101cf9c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 231, Address: 0x101cfd0 */
    lpPe->peRed = 0; /* Line 232, Address: 0x101cfdc */
    lpPe->peGreen = 0; /* Line 233, Address: 0x101cfe0 */
    lpPe->peBlue = 0; /* Line 234, Address: 0x101cfe4 */
    lpPe->peFlags = 1; /* Line 235, Address: 0x101cfe8 */
    ++lpPe; /* Line 236, Address: 0x101cff0 */
  } /* Line 237, Address: 0x101cff4 */
  FadeCount = 0; /* Line 238, Address: 0x101d010 */
  *lpFadeFlag = 1; /* Line 239, Address: 0x101d018 */

} /* Line 241, Address: 0x101d028 */



int fadein0_new() { /* Line 245, Address: 0x101d040 */

  int_flg = 18; /* Line 247, Address: 0x101d048 */

  fadein1(); /* Line 249, Address: 0x101d054 */


  if (++FadeCount > 21) { /* Line 252, Address: 0x101d05c */
    FadeCount = 0; /* Line 253, Address: 0x101d07c */
    return 1; /* Line 254, Address: 0x101d084 */
  }
  return 0; /* Line 256, Address: 0x101d090 */
} /* Line 257, Address: 0x101d094 */



static void fadein1() { /* Line 261, Address: 0x101d0b0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 265, Address: 0x101d0c4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 266, Address: 0x101d0f8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 268, Address: 0x101d12c */
    fadein2(lpPe, lpPe2); /* Line 269, Address: 0x101d138 */
    ++lpPe; /* Line 270, Address: 0x101d148 */
    ++lpPe2; /* Line 271, Address: 0x101d14c */
  } /* Line 272, Address: 0x101d150 */
  if (stageno.b.h == 1) return; /* Line 273, Address: 0x101d16c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 275, Address: 0x101d188 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 276, Address: 0x101d1bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 278, Address: 0x101d1f0 */
    fadein2(lpPe, lpPe2); /* Line 279, Address: 0x101d1fc */
    ++lpPe; /* Line 280, Address: 0x101d20c */
    ++lpPe2; /* Line 281, Address: 0x101d210 */
  } /* Line 282, Address: 0x101d214 */



} /* Line 286, Address: 0x101d230 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 290, Address: 0x101d250 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 291, Address: 0x101d25c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 294, Address: 0x101d2bc */
      lpPeDest->peBlue += 32; /* Line 295, Address: 0x101d2e0 */
    } /* Line 296, Address: 0x101d2f0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 297, Address: 0x101d2f8 */
      lpPeDest->peGreen += 32; /* Line 298, Address: 0x101d31c */
    } /* Line 299, Address: 0x101d32c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 300, Address: 0x101d334 */
      lpPeDest->peRed += 32; /* Line 301, Address: 0x101d358 */
    }
  }

} /* Line 305, Address: 0x101d36c */


void fadeout() {
  startcolor = 0; /* Line 309, Address: 0x101d380 */
  colorcnt = 63; /* Line 310, Address: 0x101d388 */

  FadeCount = 0; /* Line 312, Address: 0x101d394 */
  *lpFadeFlag = 2; /* Line 313, Address: 0x101d39c */

} /* Line 315, Address: 0x101d3ac */



static int fadeout_new() { /* Line 319, Address: 0x101d3c0 */

  int_flg = 18; /* Line 321, Address: 0x101d3c8 */

  fadeout1(); /* Line 323, Address: 0x101d3d4 */


  if (++FadeCount > 21) { /* Line 326, Address: 0x101d3dc */
    FadeCount = 0; /* Line 327, Address: 0x101d3fc */
    return 1; /* Line 328, Address: 0x101d404 */
  }
  return 0; /* Line 330, Address: 0x101d410 */
} /* Line 331, Address: 0x101d414 */


static void fadeout1() { /* Line 334, Address: 0x101d430 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 338, Address: 0x101d440 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 340, Address: 0x101d474 */
    fadeout2(lpPe); /* Line 341, Address: 0x101d480 */
    ++lpPe; /* Line 342, Address: 0x101d48c */
  } /* Line 343, Address: 0x101d490 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 344, Address: 0x101d4ac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 346, Address: 0x101d4e0 */
    fadeout2(lpPe); /* Line 347, Address: 0x101d4ec */
    ++lpPe; /* Line 348, Address: 0x101d4f8 */
  } /* Line 349, Address: 0x101d4fc */


} /* Line 352, Address: 0x101d518 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 355, Address: 0x101d530 */
  if (lpPeDest->peRed) { /* Line 356, Address: 0x101d538 */
    lpPeDest->peRed -= 32; /* Line 357, Address: 0x101d548 */
  } /* Line 358, Address: 0x101d55c */
  else if (lpPeDest->peGreen) { /* Line 359, Address: 0x101d564 */
    lpPeDest->peGreen -= 32; /* Line 360, Address: 0x101d574 */
  } /* Line 361, Address: 0x101d584 */
  else if (lpPeDest->peBlue) { /* Line 362, Address: 0x101d58c */
    lpPeDest->peBlue -= 32; /* Line 363, Address: 0x101d59c */
  }

} /* Line 366, Address: 0x101d5ac */




void flashin() { /* Line 371, Address: 0x101d5c0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 375, Address: 0x101d5cc */
  colorcnt = 63; /* Line 376, Address: 0x101d5d4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 378, Address: 0x101d5e0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 380, Address: 0x101d614 */
    lpPe->peRed = 224; /* Line 381, Address: 0x101d620 */
    lpPe->peGreen = 224; /* Line 382, Address: 0x101d628 */
    lpPe->peBlue = 224; /* Line 383, Address: 0x101d630 */
    lpPe->peFlags = 1; /* Line 384, Address: 0x101d638 */
    ++lpPe; /* Line 385, Address: 0x101d640 */
  } /* Line 386, Address: 0x101d644 */
  FadeCount = 0; /* Line 387, Address: 0x101d660 */
  *lpFadeFlag = 3; /* Line 388, Address: 0x101d668 */

} /* Line 390, Address: 0x101d678 */

static int flashin_new() { /* Line 392, Address: 0x101d690 */

  int_flg = 18; /* Line 394, Address: 0x101d698 */

  flashin1(); /* Line 396, Address: 0x101d6a4 */


  if (++FadeCount > 21) { /* Line 399, Address: 0x101d6ac */
    FadeCount = 0; /* Line 400, Address: 0x101d6cc */
    return 1; /* Line 401, Address: 0x101d6d4 */
  }
  return 0; /* Line 403, Address: 0x101d6e0 */
} /* Line 404, Address: 0x101d6e4 */

static void flashin1() { /* Line 406, Address: 0x101d700 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 410, Address: 0x101d714 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 411, Address: 0x101d748 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 413, Address: 0x101d77c */
    flashin2(lpPe, lpPe2); /* Line 414, Address: 0x101d788 */
    ++lpPe; /* Line 415, Address: 0x101d798 */
    ++lpPe2; /* Line 416, Address: 0x101d79c */
  } /* Line 417, Address: 0x101d7a0 */
  if (stageno.b.h == 1) return; /* Line 418, Address: 0x101d7bc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 420, Address: 0x101d7d8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 421, Address: 0x101d80c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 423, Address: 0x101d840 */
    flashin2(lpPe, lpPe2); /* Line 424, Address: 0x101d84c */
    ++lpPe; /* Line 425, Address: 0x101d85c */
    ++lpPe2; /* Line 426, Address: 0x101d860 */
  } /* Line 427, Address: 0x101d864 */



} /* Line 431, Address: 0x101d880 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 435, Address: 0x101d8a0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 436, Address: 0x101d8ac */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 439, Address: 0x101d90c */
      lpPeDest->peBlue -= 32; /* Line 440, Address: 0x101d930 */
    } /* Line 441, Address: 0x101d940 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 442, Address: 0x101d948 */
      lpPeDest->peGreen -= 32; /* Line 443, Address: 0x101d96c */
    } /* Line 444, Address: 0x101d97c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 445, Address: 0x101d984 */
      lpPeDest->peRed -= 32; /* Line 446, Address: 0x101d9a8 */
    }
  }

} /* Line 450, Address: 0x101d9bc */


void flashout() {
  startcolor = 0; /* Line 454, Address: 0x101d9d0 */
  colorcnt = 63; /* Line 455, Address: 0x101d9d8 */

  FadeCount = 0; /* Line 457, Address: 0x101d9e4 */
  *lpFadeFlag = 4; /* Line 458, Address: 0x101d9ec */

} /* Line 460, Address: 0x101d9fc */

static int flashout_new() { /* Line 462, Address: 0x101da10 */

  int_flg = 18; /* Line 464, Address: 0x101da18 */

  flashout1(); /* Line 466, Address: 0x101da24 */


  if (++FadeCount > 21) { /* Line 469, Address: 0x101da2c */
    FadeCount = 0; /* Line 470, Address: 0x101da4c */
    return 1; /* Line 471, Address: 0x101da54 */
  }
  return 0; /* Line 473, Address: 0x101da60 */
} /* Line 474, Address: 0x101da64 */


static void flashout1() { /* Line 477, Address: 0x101da80 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 481, Address: 0x101da90 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 483, Address: 0x101dac4 */
    flashout2(lpPe); /* Line 484, Address: 0x101dad0 */
    ++lpPe; /* Line 485, Address: 0x101dadc */
  } /* Line 486, Address: 0x101dae0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 487, Address: 0x101dafc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 489, Address: 0x101db30 */
    flashout2(lpPe); /* Line 490, Address: 0x101db3c */
    ++lpPe; /* Line 491, Address: 0x101db48 */
  } /* Line 492, Address: 0x101db4c */


} /* Line 495, Address: 0x101db68 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 498, Address: 0x101db80 */
  if (lpPeDest->peRed != 224) { /* Line 499, Address: 0x101db88 */
    lpPeDest->peRed += 32; /* Line 500, Address: 0x101dba0 */
  } /* Line 501, Address: 0x101dbb4 */
  else if (lpPeDest->peGreen != 224) { /* Line 502, Address: 0x101dbbc */
    lpPeDest->peGreen += 32; /* Line 503, Address: 0x101dbd4 */
  } /* Line 504, Address: 0x101dbe4 */
  else if (lpPeDest->peBlue != 224) { /* Line 505, Address: 0x101dbec */
    lpPeDest->peBlue += 32; /* Line 506, Address: 0x101dc04 */
  }


} /* Line 510, Address: 0x101dc14 */


void colorset(int ColorNo) { /* Line 513, Address: 0x101dc20 */
  colorset00(ColorNo, 1); /* Line 514, Address: 0x101dc2c */
} /* Line 515, Address: 0x101dc3c */

void colorset2(int ColorNo) { /* Line 517, Address: 0x101dc50 */
  colorset00(ColorNo, 0); /* Line 518, Address: 0x101dc5c */
} /* Line 519, Address: 0x101dc6c */

void colorset3(int ColorNo) { /* Line 521, Address: 0x101dc80 */
  colorset00(ColorNo, 1); /* Line 522, Address: 0x101dc8c */
} /* Line 523, Address: 0x101dc9c */

void colorset4(int ColorNo) { /* Line 525, Address: 0x101dcb0 */
  colorset00(ColorNo, 2); /* Line 526, Address: 0x101dcbc */
} /* Line 527, Address: 0x101dccc */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 533, Address: 0x101dce0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 538, Address: 0x101dd00 */
    case 0:
      lppe = lpcolorwk; break; /* Line 540, Address: 0x101dd68 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 542, Address: 0x101dd78 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 544, Address: 0x101dd88 */
    default:
      lppe = lpcolorwk4; break; /* Line 546, Address: 0x101dd98 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 549, Address: 0x101dda0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 550, Address: 0x101ddb8 */
  n = colortbl[ColorNo].cnt; /* Line 551, Address: 0x101dde0 */
  for (i = 0; i < n; ++i) { /* Line 552, Address: 0x101de00 */
    *lpPeDest++ = *lpPeSrc++; /* Line 553, Address: 0x101de0c */
  } /* Line 554, Address: 0x101de3c */

} /* Line 556, Address: 0x101de4c */




int FadeProc() { /* Line 561, Address: 0x101de70 */
  switch (*lpFadeFlag) { /* Line 562, Address: 0x101de78 */
    case 1:
      return fadein0_new(); /* Line 564, Address: 0x101debc */
    case 2:
      return fadeout_new(); /* Line 566, Address: 0x101decc */
    case 3:
      return flashin_new(); /* Line 568, Address: 0x101dedc */
    case 4:
      return flashout_new(); /* Line 570, Address: 0x101deec */
  }
  return 1; /* Line 572, Address: 0x101defc */

} /* Line 574, Address: 0x101df00 */
