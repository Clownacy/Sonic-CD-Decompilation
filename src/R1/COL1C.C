#include "..\EQU.H"
#include "COL1C.H"

static void fadein1();
static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc);
static int fadeout_new();
static void fadeout1();
static void fadeout2(palette_entry* lpPeDest);
static int flashin_new();
static void flashin1();
static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc);
static int flashout_new();
static void flashout1();
static void flashout2(palette_entry* lpPeDest);

palette_entry clst1_1c0[3][4] = {
  { { 192, 192, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 }, { 128, 160, 224, 1 } },
  { { 128, 160, 224, 1 }, { 192, 192, 224, 1 }, { 192, 192, 224, 1 }, { 160, 192, 224, 1 } },
  { { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, { 160, 192, 224, 1 }, { 192, 192, 224, 1 } }
};
palette_entry clst1_1c1[3][4] = {
  { { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96, 128, 224, 1 } },
  { { 128, 160, 224, 1 }, {  96, 128, 224, 1 }, {   0,  96, 192, 1 }, { 160, 192, 224, 1 } },
  { {  96, 128, 224, 1 }, { 160, 192, 224, 1 }, {   0,  96, 192, 1 }, { 128, 160, 224, 1 } }
};
palette_entry advacolor[64] = {
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
palette_entry advacolor2[64] = {
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
palette_entry gamecolor[16] = {
  {  32,  32, 160, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
palette_entry zone1colorc[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  32,  32, 160, 1 }, { 224, 224, 128, 1 }, { 224,   0, 224, 1 }, {  32,   0,   0, 1 },
  { 224, 160,   0, 1 }, { 128, 192,   0, 1 }, { 160,  64,   0, 1 }, {  96,  32,   0, 1 },
  { 128, 224,  32, 1 }, {   0, 160,   0, 1 }, {   0,  96,   0, 1 }, {   0,  64,   0, 1 },
  { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96, 128, 224, 1 },
  {  32,  32, 160, 1 }, {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 192, 192, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  { 128, 160, 224, 1 }, {   0,  96,   0, 1 }, {  64, 160,   0, 1 }, { 128, 224,   0, 1 },
  {   0,  64,  32, 1 }, {  96,  32,  32, 1 }, { 160,  96,   0, 1 }, { 160, 160,   0, 1 }
};
palette_entry zone1colboss1[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 160, 1 },
  { 128, 128, 192, 1 }, { 160, 160, 224, 1 }, { 224, 224, 224, 1 }, { 224, 128, 224, 1 },
  { 224,  32, 224, 1 }, { 128,   0, 128, 1 }, {  32,  64,  64, 1 }, {  32,  32,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor,  0, 64 }, { advacolor,    0, 64 }, { advacolor2,     0, 64 },
  { gamecolor,  0, 16 }, { zone1colorc, 16, 48 }, { zone1colboss1, 16, 16 }
};
static int FadeCount;

void clchgctr() { /* Line 94, Address: 0x1021080 */
  palette_entry *lpPe, *lpPe2;
  int i;

  --clchgtim[0]; /* Line 98, Address: 0x1021090 */
  if (clchgtim[0] & 128) { /* Line 99, Address: 0x10210a4 */
    clchgtim[0] = 7; /* Line 100, Address: 0x10210bc */
    if (clchgcnt[0] == 2) { /* Line 101, Address: 0x10210c8 */
      clchgcnt[0] = 0; /* Line 102, Address: 0x10210e0 */
    } /* Line 103, Address: 0x10210e8 */
    else {
      ++clchgcnt[0]; /* Line 105, Address: 0x10210f0 */
    }
  }
  lpPe = &lpcolorwk[53]; /* Line 108, Address: 0x1021104 */
  lpPe2 = clst1_1c0[clchgcnt[0]]; /* Line 109, Address: 0x1021110 */
  for (i = 0; i < 4; ++i) { /* Line 110, Address: 0x102112c */
    *lpPe++ = *lpPe2++; /* Line 111, Address: 0x1021138 */
  } /* Line 112, Address: 0x1021168 */

  --clchgtim[1]; /* Line 114, Address: 0x1021178 */
  if (clchgtim[1] & 128) { /* Line 115, Address: 0x102118c */
    clchgtim[1] = 5; /* Line 116, Address: 0x10211a4 */
    if (clchgcnt[1] == 2) { /* Line 117, Address: 0x10211b0 */
      clchgcnt[1] = 0; /* Line 118, Address: 0x10211c8 */
    } /* Line 119, Address: 0x10211d0 */
    else {
      ++clchgcnt[1]; /* Line 121, Address: 0x10211d8 */
    }
  }
  lpPe = &lpcolorwk[44]; /* Line 124, Address: 0x10211ec */
  lpPe2 = clst1_1c1[clchgcnt[1]]; /* Line 125, Address: 0x10211f8 */
  for (i = 0; i < 4; ++i) { /* Line 126, Address: 0x1021214 */
    *lpPe++ = *lpPe2++; /* Line 127, Address: 0x1021220 */
  } /* Line 128, Address: 0x1021250 */
} /* Line 129, Address: 0x1021260 */












void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 142, Address: 0x1021280 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 145, Address: 0x1021298 */
  if ((char)*pChgTime < 0) { /* Line 146, Address: 0x10212ac */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 148, Address: 0x10212cc */
    ++*pChgCnt; /* Line 149, Address: 0x10212f0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 150, Address: 0x1021304 */

      *pChgCnt = 0; /* Line 152, Address: 0x1021330 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 155, Address: 0x1021338 */
    *pChgTime = pCntTbl[0]; /* Line 156, Address: 0x1021354 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 157, Address: 0x1021364 */
  }
} /* Line 159, Address: 0x102139c */


void fadein0() { /* Line 162, Address: 0x10213b0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 166, Address: 0x10213bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 168, Address: 0x10213f0 */
    lpPe->peRed = 0; /* Line 169, Address: 0x10213fc */
    lpPe->peGreen = 0; /* Line 170, Address: 0x1021400 */
    lpPe->peBlue = 0; /* Line 171, Address: 0x1021404 */
    lpPe->peFlags = 1; /* Line 172, Address: 0x1021408 */
    ++lpPe; /* Line 173, Address: 0x1021410 */
  } /* Line 174, Address: 0x1021414 */
  FadeCount = 0; /* Line 175, Address: 0x1021430 */
  *lpFadeFlag = 1; /* Line 176, Address: 0x1021438 */

} /* Line 178, Address: 0x1021448 */



int fadein0_new() { /* Line 182, Address: 0x1021460 */

  int_flg = 18; /* Line 184, Address: 0x1021468 */

  fadein1(); /* Line 186, Address: 0x1021474 */


  if (++FadeCount > 21) { /* Line 189, Address: 0x102147c */
    FadeCount = 0; /* Line 190, Address: 0x102149c */
    return 1; /* Line 191, Address: 0x10214a4 */
  }
  return 0; /* Line 193, Address: 0x10214b0 */
} /* Line 194, Address: 0x10214b4 */



static void fadein1() { /* Line 198, Address: 0x10214d0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 202, Address: 0x10214e4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 203, Address: 0x1021518 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 205, Address: 0x102154c */
    fadein2(lpPe, lpPe2); /* Line 206, Address: 0x1021558 */
    ++lpPe; /* Line 207, Address: 0x1021568 */
    ++lpPe2; /* Line 208, Address: 0x102156c */
  } /* Line 209, Address: 0x1021570 */
  if (stageno.b.h == 1) return; /* Line 210, Address: 0x102158c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 212, Address: 0x10215a8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 213, Address: 0x10215dc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 215, Address: 0x1021610 */
    fadein2(lpPe, lpPe2); /* Line 216, Address: 0x102161c */
    ++lpPe; /* Line 217, Address: 0x102162c */
    ++lpPe2; /* Line 218, Address: 0x1021630 */
  } /* Line 219, Address: 0x1021634 */



} /* Line 223, Address: 0x1021650 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 227, Address: 0x1021670 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 228, Address: 0x102167c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 231, Address: 0x10216dc */
      lpPeDest->peBlue += 32; /* Line 232, Address: 0x1021700 */
    } /* Line 233, Address: 0x1021710 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 234, Address: 0x1021718 */
      lpPeDest->peGreen += 32; /* Line 235, Address: 0x102173c */
    } /* Line 236, Address: 0x102174c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 237, Address: 0x1021754 */
      lpPeDest->peRed += 32; /* Line 238, Address: 0x1021778 */
    }
  }

} /* Line 242, Address: 0x102178c */


void fadeout() {
  startcolor = 0; /* Line 246, Address: 0x10217a0 */
  colorcnt = 63; /* Line 247, Address: 0x10217a8 */

  FadeCount = 0; /* Line 249, Address: 0x10217b4 */
  *lpFadeFlag = 2; /* Line 250, Address: 0x10217bc */

} /* Line 252, Address: 0x10217cc */



static int fadeout_new() { /* Line 256, Address: 0x10217e0 */

  int_flg = 18; /* Line 258, Address: 0x10217e8 */

  fadeout1(); /* Line 260, Address: 0x10217f4 */


  if (++FadeCount > 21) { /* Line 263, Address: 0x10217fc */
    FadeCount = 0; /* Line 264, Address: 0x102181c */
    return 1; /* Line 265, Address: 0x1021824 */
  }
  return 0; /* Line 267, Address: 0x1021830 */
} /* Line 268, Address: 0x1021834 */


static void fadeout1() { /* Line 271, Address: 0x1021850 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 275, Address: 0x1021860 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 277, Address: 0x1021894 */
    fadeout2(lpPe); /* Line 278, Address: 0x10218a0 */
    ++lpPe; /* Line 279, Address: 0x10218ac */
  } /* Line 280, Address: 0x10218b0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 281, Address: 0x10218cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 283, Address: 0x1021900 */
    fadeout2(lpPe); /* Line 284, Address: 0x102190c */
    ++lpPe; /* Line 285, Address: 0x1021918 */
  } /* Line 286, Address: 0x102191c */


} /* Line 289, Address: 0x1021938 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 292, Address: 0x1021950 */
  if (lpPeDest->peRed) { /* Line 293, Address: 0x1021958 */
    lpPeDest->peRed -= 32; /* Line 294, Address: 0x1021968 */
  } /* Line 295, Address: 0x102197c */
  else if (lpPeDest->peGreen) { /* Line 296, Address: 0x1021984 */
    lpPeDest->peGreen -= 32; /* Line 297, Address: 0x1021994 */
  } /* Line 298, Address: 0x10219a4 */
  else if (lpPeDest->peBlue) { /* Line 299, Address: 0x10219ac */
    lpPeDest->peBlue -= 32; /* Line 300, Address: 0x10219bc */
  }

} /* Line 303, Address: 0x10219cc */




void flashin() { /* Line 308, Address: 0x10219e0 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 312, Address: 0x10219ec */
  colorcnt = 63; /* Line 313, Address: 0x10219f4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 315, Address: 0x1021a00 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 317, Address: 0x1021a34 */
    lpPe->peRed = 224; /* Line 318, Address: 0x1021a40 */
    lpPe->peGreen = 224; /* Line 319, Address: 0x1021a48 */
    lpPe->peBlue = 224; /* Line 320, Address: 0x1021a50 */
    lpPe->peFlags = 1; /* Line 321, Address: 0x1021a58 */
    ++lpPe; /* Line 322, Address: 0x1021a60 */
  } /* Line 323, Address: 0x1021a64 */
  FadeCount = 0; /* Line 324, Address: 0x1021a80 */
  *lpFadeFlag = 3; /* Line 325, Address: 0x1021a88 */

} /* Line 327, Address: 0x1021a98 */

static int flashin_new() { /* Line 329, Address: 0x1021ab0 */

  int_flg = 18; /* Line 331, Address: 0x1021ab8 */

  flashin1(); /* Line 333, Address: 0x1021ac4 */


  if (++FadeCount > 21) { /* Line 336, Address: 0x1021acc */
    FadeCount = 0; /* Line 337, Address: 0x1021aec */
    return 1; /* Line 338, Address: 0x1021af4 */
  }
  return 0; /* Line 340, Address: 0x1021b00 */
} /* Line 341, Address: 0x1021b04 */

static void flashin1() { /* Line 343, Address: 0x1021b20 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 347, Address: 0x1021b34 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 348, Address: 0x1021b68 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 350, Address: 0x1021b9c */
    flashin2(lpPe, lpPe2); /* Line 351, Address: 0x1021ba8 */
    ++lpPe; /* Line 352, Address: 0x1021bb8 */
    ++lpPe2; /* Line 353, Address: 0x1021bbc */
  } /* Line 354, Address: 0x1021bc0 */
  if (stageno.b.h == 1) return; /* Line 355, Address: 0x1021bdc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 357, Address: 0x1021bf8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 358, Address: 0x1021c2c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 360, Address: 0x1021c60 */
    flashin2(lpPe, lpPe2); /* Line 361, Address: 0x1021c6c */
    ++lpPe; /* Line 362, Address: 0x1021c7c */
    ++lpPe2; /* Line 363, Address: 0x1021c80 */
  } /* Line 364, Address: 0x1021c84 */



} /* Line 368, Address: 0x1021ca0 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 372, Address: 0x1021cc0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 373, Address: 0x1021ccc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 376, Address: 0x1021d2c */
      lpPeDest->peBlue -= 32; /* Line 377, Address: 0x1021d50 */
    } /* Line 378, Address: 0x1021d60 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 379, Address: 0x1021d68 */
      lpPeDest->peGreen -= 32; /* Line 380, Address: 0x1021d8c */
    } /* Line 381, Address: 0x1021d9c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 382, Address: 0x1021da4 */
      lpPeDest->peRed -= 32; /* Line 383, Address: 0x1021dc8 */
    }
  }

} /* Line 387, Address: 0x1021ddc */


void flashout() {
  startcolor = 0; /* Line 391, Address: 0x1021df0 */
  colorcnt = 63; /* Line 392, Address: 0x1021df8 */

  FadeCount = 0; /* Line 394, Address: 0x1021e04 */
  *lpFadeFlag = 4; /* Line 395, Address: 0x1021e0c */

} /* Line 397, Address: 0x1021e1c */

static int flashout_new() { /* Line 399, Address: 0x1021e30 */

  int_flg = 18; /* Line 401, Address: 0x1021e38 */

  flashout1(); /* Line 403, Address: 0x1021e44 */


  if (++FadeCount > 21) { /* Line 406, Address: 0x1021e4c */
    FadeCount = 0; /* Line 407, Address: 0x1021e6c */
    return 1; /* Line 408, Address: 0x1021e74 */
  }
  return 0; /* Line 410, Address: 0x1021e80 */
} /* Line 411, Address: 0x1021e84 */


static void flashout1() { /* Line 414, Address: 0x1021ea0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 418, Address: 0x1021eb0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 420, Address: 0x1021ee4 */
    flashout2(lpPe); /* Line 421, Address: 0x1021ef0 */
    ++lpPe; /* Line 422, Address: 0x1021efc */
  } /* Line 423, Address: 0x1021f00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 424, Address: 0x1021f1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 426, Address: 0x1021f50 */
    flashout2(lpPe); /* Line 427, Address: 0x1021f5c */
    ++lpPe; /* Line 428, Address: 0x1021f68 */
  } /* Line 429, Address: 0x1021f6c */


} /* Line 432, Address: 0x1021f88 */


static void flashout2(palette_entry* lpPeDest) { /* Line 435, Address: 0x1021fa0 */
  if (lpPeDest->peRed != 224) { /* Line 436, Address: 0x1021fa8 */
    lpPeDest->peRed += 32; /* Line 437, Address: 0x1021fc0 */
  } /* Line 438, Address: 0x1021fd4 */
  else if (lpPeDest->peGreen != 224) { /* Line 439, Address: 0x1021fdc */
    lpPeDest->peGreen += 32; /* Line 440, Address: 0x1021ff4 */
  } /* Line 441, Address: 0x1022004 */
  else if (lpPeDest->peBlue != 224) { /* Line 442, Address: 0x102200c */
    lpPeDest->peBlue += 32; /* Line 443, Address: 0x1022024 */
  }


} /* Line 447, Address: 0x1022034 */


void colorset(int ColorNo) { /* Line 450, Address: 0x1022040 */
  colorset00(ColorNo, 1); /* Line 451, Address: 0x102204c */
} /* Line 452, Address: 0x102205c */

void colorset2(int ColorNo) { /* Line 454, Address: 0x1022070 */
  colorset00(ColorNo, 0); /* Line 455, Address: 0x102207c */
} /* Line 456, Address: 0x102208c */

void colorset3(int ColorNo) { /* Line 458, Address: 0x10220a0 */
  colorset00(ColorNo, 0); /* Line 459, Address: 0x10220ac */
} /* Line 460, Address: 0x10220bc */





void colorset00(int ColorNo, int WorkOffs) { /* Line 466, Address: 0x10220d0 */
  palette_entry *lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 471, Address: 0x10220f0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 473, Address: 0x1022158 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 475, Address: 0x1022168 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 477, Address: 0x1022178 */
    default:
      lppe = lpcolorwk4; break; /* Line 479, Address: 0x1022188 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 482, Address: 0x1022190 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 483, Address: 0x10221a8 */
  n = colortbl[ColorNo].cnt; /* Line 484, Address: 0x10221d0 */
  for (i = 0; i < n; ++i) { /* Line 485, Address: 0x10221f0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 486, Address: 0x10221fc */
  } /* Line 487, Address: 0x102222c */

} /* Line 489, Address: 0x102223c */




int FadeProc() { /* Line 494, Address: 0x1022260 */
  switch (*lpFadeFlag) { /* Line 495, Address: 0x1022268 */
    case 1:
      return fadein0_new(); /* Line 497, Address: 0x10222ac */
    case 2:
      return fadeout_new(); /* Line 499, Address: 0x10222bc */
    case 3:
      return flashin_new(); /* Line 501, Address: 0x10222cc */
    case 4:
      return flashout_new(); /* Line 503, Address: 0x10222dc */
  }
  return 1; /* Line 505, Address: 0x10222ec */

} /* Line 507, Address: 0x10222f0 */
