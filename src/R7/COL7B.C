#include "..\EQU.H"
#include "COL7A.H"

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
  {   0,   0,  32, 1 }, { 128, 224, 160, 1 }, {  96, 192,   0, 1 }, {  32,  96,   0, 1 },
  {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, { 128,   0,   0, 1 }, {   0,  32,   0, 1 },
  { 224, 160,   0, 1 }, {   0,   0,  96, 1 }, {  32,   0,   0, 1 }, { 192, 192,  64, 1 },
  {  96,  64,  32, 1 }, {  64,  96,   0, 1 }, { 224, 160, 224, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, {   0,   0,   0, 1 }, {   0,  32,  32, 1 }, {  32,  32,   0, 1 },
  {  64,  64,   0, 1 }, {   0,  64, 224, 1 }, { 224, 224, 160, 1 }, { 224, 224, 224, 1 },
  {  96,   0, 160, 1 }, { 128, 128, 128, 1 }, { 224, 128,   0, 1 }, {  64,   0, 128, 1 },
  {  32,   0,  96, 1 }, {   0,   0,  64, 1 }, { 224, 224,  96, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, { 128, 224, 160, 1 }, {  96, 192,   0, 1 }, {  32,  96,   0, 1 },
  {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, { 128,   0,   0, 1 }, {   0,  32,   0, 1 },
  { 224, 160,   0, 1 }, {   0,   0,  96, 1 }, {  32,   0,   0, 1 }, { 192, 192,  64, 1 },
  {  96,  64,  32, 1 }, {  64,  96,   0, 1 }, { 224, 160, 224, 1 }, { 224,   0,   0, 1 },
  {   0,   0,  32, 1 }, {   0,   0,   0, 1 }, {   0,  32,  32, 1 }, {  32,  32,   0, 1 },
  {  64,  64,   0, 1 }, {   0,  64, 224, 1 }, { 224, 224, 160, 1 }, { 224, 224, 224, 1 },
  {  96,   0, 160, 1 }, { 128, 128, 128, 1 }, { 224, 128,   0, 1 }, {  64,   0, 128, 1 },
  {  32,   0,  96, 1 }, {   0,   0,  64, 1 }, { 224, 224,  96, 1 }, { 224, 224,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor, 0, 16 },
  { &advacolor[16], 16, 48 },
  { zone82colora, 16, 48 }
};
static int FadeCount;
















































































void clchgctr(void) {} /* Line 138, Address: 0x1023ac0 */







void fadein0(void) { /* Line 146, Address: 0x1023ad0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 150, Address: 0x1023adc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 152, Address: 0x1023b10 */
    lpPe->peRed = 0; /* Line 153, Address: 0x1023b1c */
    lpPe->peGreen = 0; /* Line 154, Address: 0x1023b20 */
    lpPe->peBlue = 0; /* Line 155, Address: 0x1023b24 */
    lpPe->peFlags = 1; /* Line 156, Address: 0x1023b28 */
    ++lpPe; /* Line 157, Address: 0x1023b30 */
  } /* Line 158, Address: 0x1023b34 */
  FadeCount = 0; /* Line 159, Address: 0x1023b50 */
  *lpFadeFlag = 1; /* Line 160, Address: 0x1023b58 */

} /* Line 162, Address: 0x1023b68 */



int fadein0_new(void) { /* Line 166, Address: 0x1023b80 */

  int_flg = 18; /* Line 168, Address: 0x1023b88 */

  fadein1(); /* Line 170, Address: 0x1023b94 */


  if (++FadeCount > 21) { /* Line 173, Address: 0x1023b9c */
    FadeCount = 0; /* Line 174, Address: 0x1023bbc */
    return 1; /* Line 175, Address: 0x1023bc4 */
  }
  return 0; /* Line 177, Address: 0x1023bd0 */
} /* Line 178, Address: 0x1023bd4 */



static void fadein1(void) { /* Line 182, Address: 0x1023bf0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 186, Address: 0x1023c04 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 187, Address: 0x1023c38 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 189, Address: 0x1023c6c */
    fadein2(lpPe, lpPe2); /* Line 190, Address: 0x1023c78 */
    ++lpPe; /* Line 191, Address: 0x1023c88 */
    ++lpPe2; /* Line 192, Address: 0x1023c8c */
  } /* Line 193, Address: 0x1023c90 */
  if (stageno.b.h == 1) return; /* Line 194, Address: 0x1023cac */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 196, Address: 0x1023cc8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 197, Address: 0x1023cfc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 199, Address: 0x1023d30 */
    fadein2(lpPe, lpPe2); /* Line 200, Address: 0x1023d3c */
    ++lpPe; /* Line 201, Address: 0x1023d4c */
    ++lpPe2; /* Line 202, Address: 0x1023d50 */
  } /* Line 203, Address: 0x1023d54 */



} /* Line 207, Address: 0x1023d70 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 211, Address: 0x1023d90 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 212, Address: 0x1023d9c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 215, Address: 0x1023dfc */
      lpPeDest->peBlue += 32; /* Line 216, Address: 0x1023e20 */
    } /* Line 217, Address: 0x1023e30 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 218, Address: 0x1023e38 */
      lpPeDest->peGreen += 32; /* Line 219, Address: 0x1023e5c */
    } /* Line 220, Address: 0x1023e6c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 221, Address: 0x1023e74 */
      lpPeDest->peRed += 32; /* Line 222, Address: 0x1023e98 */
    }
  }

} /* Line 226, Address: 0x1023eac */


void fadeout(void) {
  startcolor = 0; /* Line 230, Address: 0x1023ec0 */
  colorcnt = 63; /* Line 231, Address: 0x1023ec8 */

  FadeCount = 0; /* Line 233, Address: 0x1023ed4 */
  *lpFadeFlag = 2; /* Line 234, Address: 0x1023edc */

} /* Line 236, Address: 0x1023eec */



static int fadeout_new(void) { /* Line 240, Address: 0x1023f00 */

  int_flg = 18; /* Line 242, Address: 0x1023f08 */

  fadeout1(); /* Line 244, Address: 0x1023f14 */


  if (++FadeCount > 21) { /* Line 247, Address: 0x1023f1c */
    FadeCount = 0; /* Line 248, Address: 0x1023f3c */
    return 1; /* Line 249, Address: 0x1023f44 */
  }
  return 0; /* Line 251, Address: 0x1023f50 */
} /* Line 252, Address: 0x1023f54 */


static void fadeout1(void) { /* Line 255, Address: 0x1023f70 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 259, Address: 0x1023f80 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 261, Address: 0x1023fb4 */
    fadeout2(lpPe); /* Line 262, Address: 0x1023fc0 */
    ++lpPe; /* Line 263, Address: 0x1023fcc */
  } /* Line 264, Address: 0x1023fd0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 265, Address: 0x1023fec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 267, Address: 0x1024020 */
    fadeout2(lpPe); /* Line 268, Address: 0x102402c */
    ++lpPe; /* Line 269, Address: 0x1024038 */
  } /* Line 270, Address: 0x102403c */


} /* Line 273, Address: 0x1024058 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 276, Address: 0x1024070 */
  if (lpPeDest->peRed) { /* Line 277, Address: 0x1024078 */
    lpPeDest->peRed -= 32; /* Line 278, Address: 0x1024088 */
  } /* Line 279, Address: 0x102409c */
  else if (lpPeDest->peGreen) { /* Line 280, Address: 0x10240a4 */
    lpPeDest->peGreen -= 32; /* Line 281, Address: 0x10240b4 */
  } /* Line 282, Address: 0x10240c4 */
  else if (lpPeDest->peBlue) { /* Line 283, Address: 0x10240cc */
    lpPeDest->peBlue -= 32; /* Line 284, Address: 0x10240dc */
  }

} /* Line 287, Address: 0x10240ec */




void flashin(void) { /* Line 292, Address: 0x1024100 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 296, Address: 0x102410c */
  colorcnt = 63; /* Line 297, Address: 0x1024114 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 299, Address: 0x1024120 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 301, Address: 0x1024154 */
    lpPe->peRed = 224; /* Line 302, Address: 0x1024160 */
    lpPe->peGreen = 224; /* Line 303, Address: 0x1024168 */
    lpPe->peBlue = 224; /* Line 304, Address: 0x1024170 */
    lpPe->peFlags = 1; /* Line 305, Address: 0x1024178 */
    ++lpPe; /* Line 306, Address: 0x1024180 */
  } /* Line 307, Address: 0x1024184 */
  FadeCount = 0; /* Line 308, Address: 0x10241a0 */
  *lpFadeFlag = 3; /* Line 309, Address: 0x10241a8 */

} /* Line 311, Address: 0x10241b8 */

static int flashin_new(void) { /* Line 313, Address: 0x10241d0 */

  int_flg = 18; /* Line 315, Address: 0x10241d8 */

  flashin1(); /* Line 317, Address: 0x10241e4 */


  if (++FadeCount > 21) { /* Line 320, Address: 0x10241ec */
    FadeCount = 0; /* Line 321, Address: 0x102420c */
    return 1; /* Line 322, Address: 0x1024214 */
  }
  return 0; /* Line 324, Address: 0x1024220 */
} /* Line 325, Address: 0x1024224 */

static void flashin1(void) { /* Line 327, Address: 0x1024240 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 331, Address: 0x1024254 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 332, Address: 0x1024288 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 334, Address: 0x10242bc */
    flashin2(lpPe, lpPe2); /* Line 335, Address: 0x10242c8 */
    ++lpPe; /* Line 336, Address: 0x10242d8 */
    ++lpPe2; /* Line 337, Address: 0x10242dc */
  } /* Line 338, Address: 0x10242e0 */
  if (stageno.b.h == 1) return; /* Line 339, Address: 0x10242fc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 341, Address: 0x1024318 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 342, Address: 0x102434c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 344, Address: 0x1024380 */
    flashin2(lpPe, lpPe2); /* Line 345, Address: 0x102438c */
    ++lpPe; /* Line 346, Address: 0x102439c */
    ++lpPe2; /* Line 347, Address: 0x10243a0 */
  } /* Line 348, Address: 0x10243a4 */



} /* Line 352, Address: 0x10243c0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 356, Address: 0x10243e0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 357, Address: 0x10243ec */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 360, Address: 0x102444c */
      lpPeDest->peBlue -= 32; /* Line 361, Address: 0x1024470 */
    } /* Line 362, Address: 0x1024480 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 363, Address: 0x1024488 */
      lpPeDest->peGreen -= 32; /* Line 364, Address: 0x10244ac */
    } /* Line 365, Address: 0x10244bc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 366, Address: 0x10244c4 */
      lpPeDest->peRed -= 32; /* Line 367, Address: 0x10244e8 */
    }
  }

} /* Line 371, Address: 0x10244fc */


void flashout(void) {
  startcolor = 0; /* Line 375, Address: 0x1024510 */
  colorcnt = 63; /* Line 376, Address: 0x1024518 */

  FadeCount = 0; /* Line 378, Address: 0x1024524 */
  *lpFadeFlag = 4; /* Line 379, Address: 0x102452c */

} /* Line 381, Address: 0x102453c */

static int flashout_new(void) { /* Line 383, Address: 0x1024550 */

  int_flg = 18; /* Line 385, Address: 0x1024558 */

  flashout1(); /* Line 387, Address: 0x1024564 */


  if (++FadeCount > 21) { /* Line 390, Address: 0x102456c */
    FadeCount = 0; /* Line 391, Address: 0x102458c */
    return 1; /* Line 392, Address: 0x1024594 */
  }
  return 0; /* Line 394, Address: 0x10245a0 */
} /* Line 395, Address: 0x10245a4 */


static void flashout1(void) { /* Line 398, Address: 0x10245c0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 402, Address: 0x10245d0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 404, Address: 0x1024604 */
    flashout2(lpPe); /* Line 405, Address: 0x1024610 */
    ++lpPe; /* Line 406, Address: 0x102461c */
  } /* Line 407, Address: 0x1024620 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 408, Address: 0x102463c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 410, Address: 0x1024670 */
    flashout2(lpPe); /* Line 411, Address: 0x102467c */
    ++lpPe; /* Line 412, Address: 0x1024688 */
  } /* Line 413, Address: 0x102468c */


} /* Line 416, Address: 0x10246a8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 419, Address: 0x10246c0 */
  if (lpPeDest->peRed != 224) { /* Line 420, Address: 0x10246c8 */
    lpPeDest->peRed += 32; /* Line 421, Address: 0x10246e0 */
  } /* Line 422, Address: 0x10246f4 */
  else if (lpPeDest->peGreen != 224) { /* Line 423, Address: 0x10246fc */
    lpPeDest->peGreen += 32; /* Line 424, Address: 0x1024714 */
  } /* Line 425, Address: 0x1024724 */
  else if (lpPeDest->peBlue != 224) { /* Line 426, Address: 0x102472c */
    lpPeDest->peBlue += 32; /* Line 427, Address: 0x1024744 */
  }


} /* Line 431, Address: 0x1024754 */


void colorset(int ColorNo) { /* Line 434, Address: 0x1024760 */
  colorset00(ColorNo, 1); /* Line 435, Address: 0x102476c */
} /* Line 436, Address: 0x102477c */

void colorset2(int ColorNo) { /* Line 438, Address: 0x1024790 */
  colorset00(ColorNo, 0); /* Line 439, Address: 0x102479c */
} /* Line 440, Address: 0x10247ac */

void colorset3(int ColorNo) { /* Line 442, Address: 0x10247c0 */
  colorset00(ColorNo, 1); /* Line 443, Address: 0x10247cc */
} /* Line 444, Address: 0x10247dc */

void colorset4(int ColorNo) { /* Line 446, Address: 0x10247f0 */
  colorset00(ColorNo, 2); /* Line 447, Address: 0x10247fc */
} /* Line 448, Address: 0x102480c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 454, Address: 0x1024820 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 459, Address: 0x1024840 */
    case 0:
      lppe = lpcolorwk; break; /* Line 461, Address: 0x10248a8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 463, Address: 0x10248b8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 465, Address: 0x10248c8 */
    default:
      lppe = lpcolorwk4; break; /* Line 467, Address: 0x10248d8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 470, Address: 0x10248e0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 471, Address: 0x10248f8 */
  n = colortbl[ColorNo].cnt; /* Line 472, Address: 0x1024920 */
  for (i = 0; i < n; ++i) { /* Line 473, Address: 0x1024940 */
    *lpPeDest++ = *lpPeSrc++; /* Line 474, Address: 0x102494c */
  } /* Line 475, Address: 0x102497c */

} /* Line 477, Address: 0x102498c */




int FadeProc(void) { /* Line 482, Address: 0x10249b0 */
  switch (*lpFadeFlag) { /* Line 483, Address: 0x10249b8 */
    case 1:
      return fadein0_new(); /* Line 485, Address: 0x10249fc */
    case 2:
      return fadeout_new(); /* Line 487, Address: 0x1024a0c */
    case 3:
      return flashin_new(); /* Line 489, Address: 0x1024a1c */
    case 4:
      return flashout_new(); /* Line 491, Address: 0x1024a2c */
  }
  return 1; /* Line 493, Address: 0x1024a3c */

} /* Line 495, Address: 0x1024a40 */
