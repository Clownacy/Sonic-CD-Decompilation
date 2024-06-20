#include "..\EQU.H"
#include "COL3B.H"

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
  { 192,  96,  32, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone3colorb[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  { 192,  96,  32, 1 }, { 224, 224, 160, 1 }, { 224, 192,  32, 1 }, { 192, 128,  32, 1 },
  { 128,  64,   0, 1 }, {  64,   0,   0, 1 }, {  32,   0,   0, 1 }, {   0, 224,  64, 1 },
  {   0, 128,   0, 1 }, {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224,   0, 1 },
  { 224,   0, 192, 1 }, {  96,   0,  32, 1 }, { 160,   0,   0, 1 }, {  32,   0, 224, 1 },
  { 192,  96,  32, 1 }, { 224, 224,  64, 1 }, {  64, 160,  32, 1 }, {   0,  96,  96, 1 },
  {   0,  64,  64, 1 }, {   0,   0,  64, 1 }, { 224, 224, 128, 1 }, { 224, 192,   0, 1 },
  { 224, 128,  32, 1 }, {   0, 224,   0, 1 }, { 192,  64,  96, 1 }, { 128,   0,  96, 1 },
  {   0,  32,  32, 1 }, { 224,   0, 224, 1 }, { 128,   0, 128, 1 }, { 224, 224, 224, 1 }
};
palette_part colortbl[5] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone3colorb, 16, 48 }
};
static int FadeCount;



void clchgctr() {} /* Line 83, Address: 0x1025bb0 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 92, Address: 0x1025bc0 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 95, Address: 0x1025bd8 */
  if ((char)*pChgTime < 0) { /* Line 96, Address: 0x1025bec */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 98, Address: 0x1025c0c */
    ++*pChgCnt; /* Line 99, Address: 0x1025c30 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 100, Address: 0x1025c44 */

      *pChgCnt = 0; /* Line 102, Address: 0x1025c70 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 105, Address: 0x1025c78 */
    *pChgTime = pCntTbl[0]; /* Line 106, Address: 0x1025c94 */

    *lpPe = pColTbl[pCntTbl[1]]; /* Line 108, Address: 0x1025ca4 */
  }





} /* Line 115, Address: 0x1025cdc */


void fadein0() { /* Line 118, Address: 0x1025cf0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 122, Address: 0x1025cfc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 124, Address: 0x1025d30 */
    lpPe->peRed = 0; /* Line 125, Address: 0x1025d3c */
    lpPe->peGreen = 0; /* Line 126, Address: 0x1025d40 */
    lpPe->peBlue = 0; /* Line 127, Address: 0x1025d44 */
    lpPe->peFlags = 1; /* Line 128, Address: 0x1025d48 */
    ++lpPe; /* Line 129, Address: 0x1025d50 */
  } /* Line 130, Address: 0x1025d54 */
  FadeCount = 0; /* Line 131, Address: 0x1025d70 */
  *lpFadeFlag = 1; /* Line 132, Address: 0x1025d78 */

} /* Line 134, Address: 0x1025d88 */



int fadein0_new() { /* Line 138, Address: 0x1025da0 */

  int_flg = 18; /* Line 140, Address: 0x1025da8 */

  fadein1(); /* Line 142, Address: 0x1025db4 */


  if (++FadeCount > 21) { /* Line 145, Address: 0x1025dbc */
    FadeCount = 0; /* Line 146, Address: 0x1025ddc */
    return 1; /* Line 147, Address: 0x1025de4 */
  }
  return 0; /* Line 149, Address: 0x1025df0 */
} /* Line 150, Address: 0x1025df4 */



static void fadein1() { /* Line 154, Address: 0x1025e10 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 158, Address: 0x1025e24 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 159, Address: 0x1025e58 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 161, Address: 0x1025e8c */
    fadein2(lpPe, lpPe2); /* Line 162, Address: 0x1025e98 */
    ++lpPe; /* Line 163, Address: 0x1025ea8 */
    ++lpPe2; /* Line 164, Address: 0x1025eac */
  } /* Line 165, Address: 0x1025eb0 */
  if (stageno.b.h == 1) return; /* Line 166, Address: 0x1025ecc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 168, Address: 0x1025ee8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 169, Address: 0x1025f1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 171, Address: 0x1025f50 */
    fadein2(lpPe, lpPe2); /* Line 172, Address: 0x1025f5c */
    ++lpPe; /* Line 173, Address: 0x1025f6c */
    ++lpPe2; /* Line 174, Address: 0x1025f70 */
  } /* Line 175, Address: 0x1025f74 */



} /* Line 179, Address: 0x1025f90 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 183, Address: 0x1025fb0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 184, Address: 0x1025fbc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 187, Address: 0x102601c */
      lpPeDest->peBlue += 32; /* Line 188, Address: 0x1026040 */
    } /* Line 189, Address: 0x1026050 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 190, Address: 0x1026058 */
      lpPeDest->peGreen += 32; /* Line 191, Address: 0x102607c */
    } /* Line 192, Address: 0x102608c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 193, Address: 0x1026094 */
      lpPeDest->peRed += 32; /* Line 194, Address: 0x10260b8 */
    }
  }

} /* Line 198, Address: 0x10260cc */


void fadeout() {
  startcolor = 0; /* Line 202, Address: 0x10260e0 */
  colorcnt = 63; /* Line 203, Address: 0x10260e8 */

  FadeCount = 0; /* Line 205, Address: 0x10260f4 */
  *lpFadeFlag = 2; /* Line 206, Address: 0x10260fc */

} /* Line 208, Address: 0x102610c */



static int fadeout_new() { /* Line 212, Address: 0x1026120 */

  int_flg = 18; /* Line 214, Address: 0x1026128 */

  fadeout1(); /* Line 216, Address: 0x1026134 */


  if (++FadeCount > 21) { /* Line 219, Address: 0x102613c */
    FadeCount = 0; /* Line 220, Address: 0x102615c */
    return 1; /* Line 221, Address: 0x1026164 */
  }
  return 0; /* Line 223, Address: 0x1026170 */
} /* Line 224, Address: 0x1026174 */


static void fadeout1() { /* Line 227, Address: 0x1026190 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 231, Address: 0x10261a0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 233, Address: 0x10261d4 */
    fadeout2(lpPe); /* Line 234, Address: 0x10261e0 */
    ++lpPe; /* Line 235, Address: 0x10261ec */
  } /* Line 236, Address: 0x10261f0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 237, Address: 0x102620c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 239, Address: 0x1026240 */
    fadeout2(lpPe); /* Line 240, Address: 0x102624c */
    ++lpPe; /* Line 241, Address: 0x1026258 */
  } /* Line 242, Address: 0x102625c */


} /* Line 245, Address: 0x1026278 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 248, Address: 0x1026290 */
  if (lpPeDest->peRed) { /* Line 249, Address: 0x1026298 */
    lpPeDest->peRed -= 32; /* Line 250, Address: 0x10262a8 */
  } /* Line 251, Address: 0x10262bc */
  else if (lpPeDest->peGreen) { /* Line 252, Address: 0x10262c4 */
    lpPeDest->peGreen -= 32; /* Line 253, Address: 0x10262d4 */
  } /* Line 254, Address: 0x10262e4 */
  else if (lpPeDest->peBlue) { /* Line 255, Address: 0x10262ec */
    lpPeDest->peBlue -= 32; /* Line 256, Address: 0x10262fc */
  }

} /* Line 259, Address: 0x102630c */




void flashin() { /* Line 264, Address: 0x1026320 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 268, Address: 0x102632c */
  colorcnt = 63; /* Line 269, Address: 0x1026334 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 271, Address: 0x1026340 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 273, Address: 0x1026374 */
    lpPe->peRed = 224; /* Line 274, Address: 0x1026380 */
    lpPe->peGreen = 224; /* Line 275, Address: 0x1026388 */
    lpPe->peBlue = 224; /* Line 276, Address: 0x1026390 */
    lpPe->peFlags = 1; /* Line 277, Address: 0x1026398 */
    ++lpPe; /* Line 278, Address: 0x10263a0 */
  } /* Line 279, Address: 0x10263a4 */
  FadeCount = 0; /* Line 280, Address: 0x10263c0 */
  *lpFadeFlag = 3; /* Line 281, Address: 0x10263c8 */

} /* Line 283, Address: 0x10263d8 */

static int flashin_new() { /* Line 285, Address: 0x10263f0 */

  int_flg = 18; /* Line 287, Address: 0x10263f8 */

  flashin1(); /* Line 289, Address: 0x1026404 */


  if (++FadeCount > 21) { /* Line 292, Address: 0x102640c */
    FadeCount = 0; /* Line 293, Address: 0x102642c */
    return 1; /* Line 294, Address: 0x1026434 */
  }
  return 0; /* Line 296, Address: 0x1026440 */
} /* Line 297, Address: 0x1026444 */

static void flashin1() { /* Line 299, Address: 0x1026460 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 303, Address: 0x1026474 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 304, Address: 0x10264a8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 306, Address: 0x10264dc */
    flashin2(lpPe, lpPe2); /* Line 307, Address: 0x10264e8 */
    ++lpPe; /* Line 308, Address: 0x10264f8 */
    ++lpPe2; /* Line 309, Address: 0x10264fc */
  } /* Line 310, Address: 0x1026500 */
  if (stageno.b.h == 1) return; /* Line 311, Address: 0x102651c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 313, Address: 0x1026538 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 314, Address: 0x102656c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 316, Address: 0x10265a0 */
    flashin2(lpPe, lpPe2); /* Line 317, Address: 0x10265ac */
    ++lpPe; /* Line 318, Address: 0x10265bc */
    ++lpPe2; /* Line 319, Address: 0x10265c0 */
  } /* Line 320, Address: 0x10265c4 */



} /* Line 324, Address: 0x10265e0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 328, Address: 0x1026600 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 329, Address: 0x102660c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 332, Address: 0x102666c */
      lpPeDest->peBlue -= 32; /* Line 333, Address: 0x1026690 */
    } /* Line 334, Address: 0x10266a0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 335, Address: 0x10266a8 */
      lpPeDest->peGreen -= 32; /* Line 336, Address: 0x10266cc */
    } /* Line 337, Address: 0x10266dc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 338, Address: 0x10266e4 */
      lpPeDest->peRed -= 32; /* Line 339, Address: 0x1026708 */
    }
  }

} /* Line 343, Address: 0x102671c */


void flashout() {
  startcolor = 0; /* Line 347, Address: 0x1026730 */
  colorcnt = 63; /* Line 348, Address: 0x1026738 */

  FadeCount = 0; /* Line 350, Address: 0x1026744 */
  *lpFadeFlag = 4; /* Line 351, Address: 0x102674c */

} /* Line 353, Address: 0x102675c */

static int flashout_new() { /* Line 355, Address: 0x1026770 */

  int_flg = 18; /* Line 357, Address: 0x1026778 */

  flashout1(); /* Line 359, Address: 0x1026784 */


  if (++FadeCount > 21) { /* Line 362, Address: 0x102678c */
    FadeCount = 0; /* Line 363, Address: 0x10267ac */
    return 1; /* Line 364, Address: 0x10267b4 */
  }
  return 0; /* Line 366, Address: 0x10267c0 */
} /* Line 367, Address: 0x10267c4 */


static void flashout1() { /* Line 370, Address: 0x10267e0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 374, Address: 0x10267f0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 376, Address: 0x1026824 */
    flashout2(lpPe); /* Line 377, Address: 0x1026830 */
    ++lpPe; /* Line 378, Address: 0x102683c */
  } /* Line 379, Address: 0x1026840 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 380, Address: 0x102685c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 382, Address: 0x1026890 */
    flashout2(lpPe); /* Line 383, Address: 0x102689c */
    ++lpPe; /* Line 384, Address: 0x10268a8 */
  } /* Line 385, Address: 0x10268ac */


} /* Line 388, Address: 0x10268c8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 391, Address: 0x10268e0 */
  if (lpPeDest->peRed != 224) { /* Line 392, Address: 0x10268e8 */
    lpPeDest->peRed += 32; /* Line 393, Address: 0x1026900 */
  } /* Line 394, Address: 0x1026914 */
  else if (lpPeDest->peGreen != 224) { /* Line 395, Address: 0x102691c */
    lpPeDest->peGreen += 32; /* Line 396, Address: 0x1026934 */
  } /* Line 397, Address: 0x1026944 */
  else if (lpPeDest->peBlue != 224) { /* Line 398, Address: 0x102694c */
    lpPeDest->peBlue += 32; /* Line 399, Address: 0x1026964 */
  }


} /* Line 403, Address: 0x1026974 */


void colorset(int ColorNo) { /* Line 406, Address: 0x1026980 */
  colorset00(ColorNo, 1); /* Line 407, Address: 0x102698c */
} /* Line 408, Address: 0x102699c */

void colorset2(int ColorNo) { /* Line 410, Address: 0x10269b0 */
  colorset00(ColorNo, 0); /* Line 411, Address: 0x10269bc */
} /* Line 412, Address: 0x10269cc */

void colorset3(int ColorNo) { /* Line 414, Address: 0x10269e0 */
  colorset00(ColorNo, 0); /* Line 415, Address: 0x10269ec */
} /* Line 416, Address: 0x10269fc */





void colorset00(int ColorNo, int WorkOffs) { /* Line 422, Address: 0x1026a10 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 427, Address: 0x1026a30 */
    case 0:
      lppe = lpcolorwk; break; /* Line 429, Address: 0x1026a98 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 431, Address: 0x1026aa8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 433, Address: 0x1026ab8 */
    default:
      lppe = lpcolorwk4; break; /* Line 435, Address: 0x1026ac8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 438, Address: 0x1026ad0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 439, Address: 0x1026ae8 */
  n = colortbl[ColorNo].cnt; /* Line 440, Address: 0x1026b10 */
  for (i = 0; i < n; ++i) { /* Line 441, Address: 0x1026b30 */
    *lpPeDest++ = *lpPeSrc++; /* Line 442, Address: 0x1026b3c */
  } /* Line 443, Address: 0x1026b6c */

} /* Line 445, Address: 0x1026b7c */




int FadeProc() { /* Line 450, Address: 0x1026ba0 */
  switch (*lpFadeFlag) { /* Line 451, Address: 0x1026ba8 */
    case 1:
      return fadein0_new(); /* Line 453, Address: 0x1026bec */
    case 2:
      return fadeout_new(); /* Line 455, Address: 0x1026bfc */
    case 3:
      return flashin_new(); /* Line 457, Address: 0x1026c0c */
    case 4:
      return flashout_new(); /* Line 459, Address: 0x1026c1c */
  }
  return 1; /* Line 461, Address: 0x1026c2c */

} /* Line 463, Address: 0x1026c30 */
