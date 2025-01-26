#include "..\EQU.H"
#include "COL7A.H"

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
  { 160, 192, 160, 1 }, { 128, 128,   0, 1 }, {  96,  96,  96, 1 }, {  96,  64,  96, 1 },
  {  96,  32,  96, 1 }, {  64,   0,  96, 1 }, {   0,   0,   0, 1 }, {   0,  32,  96, 1 },
  {   0,   0,  64, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,   0, 1 },
  {   0,  96,   0, 1 }, { 192, 128,   0, 1 }, { 224,   0,   0, 1 }, { 224, 192,   0, 1 },
  { 160, 192, 160, 1 }, { 160, 160, 160, 1 }, { 128, 192, 160, 1 }, { 160, 224, 192, 1 },
  {  96, 224, 192, 1 }, { 192,  96, 224, 1 }, { 224, 160, 224, 1 }, { 224, 192, 224, 1 },
  { 224, 224,  96, 1 }, { 224, 224, 224, 1 }, { 224, 224,  96, 1 }, { 224,  96, 128, 1 },
  { 224, 224,  96, 1 }, { 224, 224, 224, 1 }, { 224, 192, 224, 1 }, { 224, 128, 192, 1 }
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
  {   0,  32,   0, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 }, { 224, 160, 224, 1 },
  { 192, 128, 192, 1 }, { 160,  96, 192, 1 }, {  96,  64,  64, 1 }, { 128,  96, 224, 1 },
  {  96,  32, 160, 1 }, {  32,  32,  32, 1 }, {   0,  64,  32, 1 }, {  32, 128,  96, 1 },
  {  96, 192,  32, 1 }, { 192, 128,   0, 1 }, { 224,   0,   0, 1 }, { 224, 192,   0, 1 },
  {   0,  32,  32, 1 }, { 224,  32,  32, 1 }, {   0,  64,  32, 1 }, {   0,  96,  64, 1 },
  {   0, 160,  96, 1 }, {  96,   0, 128, 1 }, { 128,   0, 192, 1 }, { 224,  64, 192, 1 },
  { 224, 224,   0, 1 }, { 192, 192, 192, 1 }, { 224, 128,   0, 1 }, { 224,   0,  32, 1 },
  { 224, 224,   0, 1 }, { 224, 160, 192, 1 }, { 224,  96, 128, 1 }, { 224,  32,  96, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, { 128, 224, 128, 1 },
  {   0,  64, 224, 1 }, {   0, 128, 192, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 128, 1 }, { 128,   0, 128, 1 }, { 224, 128, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,  32,   0, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 }, { 224, 160, 224, 1 },
  { 192, 128, 192, 1 }, { 160,  96, 192, 1 }, {  96,  64,  64, 1 }, { 128,  96, 224, 1 },
  {  96,  32, 160, 1 }, {  32,  32,  32, 1 }, {   0,  64,  32, 1 }, {  32, 128,  96, 1 },
  {  96, 192,  32, 1 }, { 192, 128,   0, 1 }, { 224,   0,   0, 1 }, { 224, 192,   0, 1 },
  {   0,  32,  32, 1 }, { 224,  32,  32, 1 }, {   0,  64,  32, 1 }, {   0,  96,  64, 1 },
  {   0, 160,  96, 1 }, {  96,   0, 128, 1 }, { 128,   0, 192, 1 }, { 224,  64, 192, 1 },
  { 224, 224,   0, 1 }, { 192, 192, 192, 1 }, { 224, 128,   0, 1 }, { 224,   0,  32, 1 },
  { 224, 224,   0, 1 }, { 224, 160, 192, 1 }, { 224,  96, 128, 1 }, { 224,  32,  96, 1 }
};
PALETTEENTRY bosscolor[6] = {
  {  32,  32,  32, 1 }, { 224,   0, 128, 1 }, { 224,  96,   0, 1 }, { 224, 224,   0, 1 },
  { 224, 224, 224, 1 }, {   0, 224,   0, 1 }
};
palette_part colortbl[7] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { gamecolor, 0, 64 },
  { gamecolor, 0, 16 },
  { &gamecolor[16], 16, 48 },
  { zone82colora, 16, 48 },
  { bosscolor, 16, 6 }
};
static int FadeCount;


















































































void clchgctr() {} /* Line 162, Address: 0x1027470 */







void fadein0() { /* Line 170, Address: 0x1027480 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 174, Address: 0x102748c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 176, Address: 0x10274c0 */
    lpPe->peRed = 0; /* Line 177, Address: 0x10274cc */
    lpPe->peGreen = 0; /* Line 178, Address: 0x10274d0 */
    lpPe->peBlue = 0; /* Line 179, Address: 0x10274d4 */
    lpPe->peFlags = 1; /* Line 180, Address: 0x10274d8 */
    ++lpPe; /* Line 181, Address: 0x10274e0 */
  } /* Line 182, Address: 0x10274e4 */
  FadeCount = 0; /* Line 183, Address: 0x1027500 */
  *lpFadeFlag = 1; /* Line 184, Address: 0x1027508 */

} /* Line 186, Address: 0x1027518 */



int fadein0_new() { /* Line 190, Address: 0x1027530 */

  int_flg = 18; /* Line 192, Address: 0x1027538 */

  fadein1(); /* Line 194, Address: 0x1027544 */


  if (++FadeCount > 21) { /* Line 197, Address: 0x102754c */
    FadeCount = 0; /* Line 198, Address: 0x102756c */
    return 1; /* Line 199, Address: 0x1027574 */
  }
  return 0; /* Line 201, Address: 0x1027580 */
} /* Line 202, Address: 0x1027584 */



static void fadein1() { /* Line 206, Address: 0x10275a0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 210, Address: 0x10275b4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 211, Address: 0x10275e8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 213, Address: 0x102761c */
    fadein2(lpPe, lpPe2); /* Line 214, Address: 0x1027628 */
    ++lpPe; /* Line 215, Address: 0x1027638 */
    ++lpPe2; /* Line 216, Address: 0x102763c */
  } /* Line 217, Address: 0x1027640 */
  if (stageno.b.h == 1) return; /* Line 218, Address: 0x102765c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 220, Address: 0x1027678 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 221, Address: 0x10276ac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 223, Address: 0x10276e0 */
    fadein2(lpPe, lpPe2); /* Line 224, Address: 0x10276ec */
    ++lpPe; /* Line 225, Address: 0x10276fc */
    ++lpPe2; /* Line 226, Address: 0x1027700 */
  } /* Line 227, Address: 0x1027704 */



} /* Line 231, Address: 0x1027720 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 235, Address: 0x1027740 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 236, Address: 0x102774c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 239, Address: 0x10277ac */
      lpPeDest->peBlue += 32; /* Line 240, Address: 0x10277d0 */
    } /* Line 241, Address: 0x10277e0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 242, Address: 0x10277e8 */
      lpPeDest->peGreen += 32; /* Line 243, Address: 0x102780c */
    } /* Line 244, Address: 0x102781c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 245, Address: 0x1027824 */
      lpPeDest->peRed += 32; /* Line 246, Address: 0x1027848 */
    }
  }

} /* Line 250, Address: 0x102785c */


void fadeout() {
  startcolor = 0; /* Line 254, Address: 0x1027870 */
  colorcnt = 63; /* Line 255, Address: 0x1027878 */

  FadeCount = 0; /* Line 257, Address: 0x1027884 */
  *lpFadeFlag = 2; /* Line 258, Address: 0x102788c */

} /* Line 260, Address: 0x102789c */



static int fadeout_new() { /* Line 264, Address: 0x10278b0 */

  int_flg = 18; /* Line 266, Address: 0x10278b8 */

  fadeout1(); /* Line 268, Address: 0x10278c4 */


  if (++FadeCount > 21) { /* Line 271, Address: 0x10278cc */
    FadeCount = 0; /* Line 272, Address: 0x10278ec */
    return 1; /* Line 273, Address: 0x10278f4 */
  }
  return 0; /* Line 275, Address: 0x1027900 */
} /* Line 276, Address: 0x1027904 */


static void fadeout1() { /* Line 279, Address: 0x1027920 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 283, Address: 0x1027930 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 285, Address: 0x1027964 */
    fadeout2(lpPe); /* Line 286, Address: 0x1027970 */
    ++lpPe; /* Line 287, Address: 0x102797c */
  } /* Line 288, Address: 0x1027980 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 289, Address: 0x102799c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 291, Address: 0x10279d0 */
    fadeout2(lpPe); /* Line 292, Address: 0x10279dc */
    ++lpPe; /* Line 293, Address: 0x10279e8 */
  } /* Line 294, Address: 0x10279ec */


} /* Line 297, Address: 0x1027a08 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 300, Address: 0x1027a20 */
  if (lpPeDest->peRed) { /* Line 301, Address: 0x1027a28 */
    lpPeDest->peRed -= 32; /* Line 302, Address: 0x1027a38 */
  } /* Line 303, Address: 0x1027a4c */
  else if (lpPeDest->peGreen) { /* Line 304, Address: 0x1027a54 */
    lpPeDest->peGreen -= 32; /* Line 305, Address: 0x1027a64 */
  } /* Line 306, Address: 0x1027a74 */
  else if (lpPeDest->peBlue) { /* Line 307, Address: 0x1027a7c */
    lpPeDest->peBlue -= 32; /* Line 308, Address: 0x1027a8c */
  }

} /* Line 311, Address: 0x1027a9c */




void flashin() { /* Line 316, Address: 0x1027ab0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 320, Address: 0x1027abc */
  colorcnt = 63; /* Line 321, Address: 0x1027ac4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 323, Address: 0x1027ad0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 325, Address: 0x1027b04 */
    lpPe->peRed = 224; /* Line 326, Address: 0x1027b10 */
    lpPe->peGreen = 224; /* Line 327, Address: 0x1027b18 */
    lpPe->peBlue = 224; /* Line 328, Address: 0x1027b20 */
    lpPe->peFlags = 1; /* Line 329, Address: 0x1027b28 */
    ++lpPe; /* Line 330, Address: 0x1027b30 */
  } /* Line 331, Address: 0x1027b34 */
  FadeCount = 0; /* Line 332, Address: 0x1027b50 */
  *lpFadeFlag = 3; /* Line 333, Address: 0x1027b58 */

} /* Line 335, Address: 0x1027b68 */

static int flashin_new() { /* Line 337, Address: 0x1027b80 */

  int_flg = 18; /* Line 339, Address: 0x1027b88 */

  flashin1(); /* Line 341, Address: 0x1027b94 */


  if (++FadeCount > 21) { /* Line 344, Address: 0x1027b9c */
    FadeCount = 0; /* Line 345, Address: 0x1027bbc */
    return 1; /* Line 346, Address: 0x1027bc4 */
  }
  return 0; /* Line 348, Address: 0x1027bd0 */
} /* Line 349, Address: 0x1027bd4 */

static void flashin1() { /* Line 351, Address: 0x1027bf0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 355, Address: 0x1027c04 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 356, Address: 0x1027c38 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 358, Address: 0x1027c6c */
    flashin2(lpPe, lpPe2); /* Line 359, Address: 0x1027c78 */
    ++lpPe; /* Line 360, Address: 0x1027c88 */
    ++lpPe2; /* Line 361, Address: 0x1027c8c */
  } /* Line 362, Address: 0x1027c90 */
  if (stageno.b.h == 1) return; /* Line 363, Address: 0x1027cac */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 365, Address: 0x1027cc8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 366, Address: 0x1027cfc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 368, Address: 0x1027d30 */
    flashin2(lpPe, lpPe2); /* Line 369, Address: 0x1027d3c */
    ++lpPe; /* Line 370, Address: 0x1027d4c */
    ++lpPe2; /* Line 371, Address: 0x1027d50 */
  } /* Line 372, Address: 0x1027d54 */



} /* Line 376, Address: 0x1027d70 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 380, Address: 0x1027d90 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 381, Address: 0x1027d9c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 384, Address: 0x1027dfc */
      lpPeDest->peBlue -= 32; /* Line 385, Address: 0x1027e20 */
    } /* Line 386, Address: 0x1027e30 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 387, Address: 0x1027e38 */
      lpPeDest->peGreen -= 32; /* Line 388, Address: 0x1027e5c */
    } /* Line 389, Address: 0x1027e6c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 390, Address: 0x1027e74 */
      lpPeDest->peRed -= 32; /* Line 391, Address: 0x1027e98 */
    }
  }

} /* Line 395, Address: 0x1027eac */


void flashout() {
  startcolor = 0; /* Line 399, Address: 0x1027ec0 */
  colorcnt = 63; /* Line 400, Address: 0x1027ec8 */

  FadeCount = 0; /* Line 402, Address: 0x1027ed4 */
  *lpFadeFlag = 4; /* Line 403, Address: 0x1027edc */

} /* Line 405, Address: 0x1027eec */

static int flashout_new() { /* Line 407, Address: 0x1027f00 */

  int_flg = 18; /* Line 409, Address: 0x1027f08 */

  flashout1(); /* Line 411, Address: 0x1027f14 */


  if (++FadeCount > 21) { /* Line 414, Address: 0x1027f1c */
    FadeCount = 0; /* Line 415, Address: 0x1027f3c */
    return 1; /* Line 416, Address: 0x1027f44 */
  }
  return 0; /* Line 418, Address: 0x1027f50 */
} /* Line 419, Address: 0x1027f54 */


static void flashout1() { /* Line 422, Address: 0x1027f70 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 426, Address: 0x1027f80 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 428, Address: 0x1027fb4 */
    flashout2(lpPe); /* Line 429, Address: 0x1027fc0 */
    ++lpPe; /* Line 430, Address: 0x1027fcc */
  } /* Line 431, Address: 0x1027fd0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 432, Address: 0x1027fec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 434, Address: 0x1028020 */
    flashout2(lpPe); /* Line 435, Address: 0x102802c */
    ++lpPe; /* Line 436, Address: 0x1028038 */
  } /* Line 437, Address: 0x102803c */


} /* Line 440, Address: 0x1028058 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 443, Address: 0x1028070 */
  if (lpPeDest->peRed != 224) { /* Line 444, Address: 0x1028078 */
    lpPeDest->peRed += 32; /* Line 445, Address: 0x1028090 */
  } /* Line 446, Address: 0x10280a4 */
  else if (lpPeDest->peGreen != 224) { /* Line 447, Address: 0x10280ac */
    lpPeDest->peGreen += 32; /* Line 448, Address: 0x10280c4 */
  } /* Line 449, Address: 0x10280d4 */
  else if (lpPeDest->peBlue != 224) { /* Line 450, Address: 0x10280dc */
    lpPeDest->peBlue += 32; /* Line 451, Address: 0x10280f4 */
  }


} /* Line 455, Address: 0x1028104 */


void colorset(int ColorNo) { /* Line 458, Address: 0x1028110 */
  colorset00(ColorNo, 1); /* Line 459, Address: 0x102811c */
} /* Line 460, Address: 0x102812c */

void colorset2(int ColorNo) { /* Line 462, Address: 0x1028140 */
  colorset00(ColorNo, 0); /* Line 463, Address: 0x102814c */
} /* Line 464, Address: 0x102815c */

void colorset3(int ColorNo) { /* Line 466, Address: 0x1028170 */
  colorset00(ColorNo, 1); /* Line 467, Address: 0x102817c */
} /* Line 468, Address: 0x102818c */

void colorset4(int ColorNo) { /* Line 470, Address: 0x10281a0 */
  colorset00(ColorNo, 2); /* Line 471, Address: 0x10281ac */
} /* Line 472, Address: 0x10281bc */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 478, Address: 0x10281d0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 483, Address: 0x10281f0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 485, Address: 0x1028258 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 487, Address: 0x1028268 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 489, Address: 0x1028278 */
    default:
      lppe = lpcolorwk4; break; /* Line 491, Address: 0x1028288 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 494, Address: 0x1028290 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 495, Address: 0x10282a8 */
  n = colortbl[ColorNo].cnt; /* Line 496, Address: 0x10282d0 */
  for (i = 0; i < n; ++i) { /* Line 497, Address: 0x10282f0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 498, Address: 0x10282fc */
  } /* Line 499, Address: 0x102832c */

} /* Line 501, Address: 0x102833c */




int FadeProc() { /* Line 506, Address: 0x1028360 */
  switch (*lpFadeFlag) { /* Line 507, Address: 0x1028368 */
    case 1:
      return fadein0_new(); /* Line 509, Address: 0x10283ac */
    case 2:
      return fadeout_new(); /* Line 511, Address: 0x10283bc */
    case 3:
      return flashin_new(); /* Line 513, Address: 0x10283cc */
    case 4:
      return flashout_new(); /* Line 515, Address: 0x10283dc */
  }
  return 1; /* Line 517, Address: 0x10283ec */

} /* Line 519, Address: 0x10283f0 */
