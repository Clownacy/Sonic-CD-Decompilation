#include "..\EQU.H"
#include "COL3D.H"

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

unsigned char col3d0cnt[8] = { 42, 3, 2, 0, 1, 1, 2, 2 };
PALETTEENTRY col3d0col[3] = { {   0, 224, 224, 1 }, {   0, 192,  96, 1 }, {   0,   0,   0, 1 } };
unsigned char col3d1cnt[36] = {
  59, 17,  9,  0,  9,  1,  9,  2,  9,  3,
   9,  4,  9,  5,  9,  6,  9,  7,  9,  8,
   9,  7,  9,  6,  9,  5,  9,  4,  9,  3,
   9,  2,  9,  1,  9,  0
};
PALETTEENTRY col3d1col[9] = {
  { 224,   0, 224, 1 }, { 128,   0, 224, 1 }, {   0, 128, 224, 1 }, {   0, 224, 224, 1 },
  {   0, 224, 128, 1 }, {   0, 224,   0, 1 }, { 128, 224,   0, 1 }, { 224, 224,   0, 1 },
  { 224, 224, 128, 1 }
};
unsigned char col3d2cnt[34] = {
  61, 16, 12,  0,  9,  1,  9,  2,  9,  3,
   9,  4,  9,  5,  9,  6,  9,  7,  9,  8,
   9,  7,  9,  6,  9,  5,  9,  4,  9,  3,
   9,  2,  9,  1
};
PALETTEENTRY col3d2col[9] = {
  { 224, 224,   0, 1 }, { 224, 160,   0, 1 }, { 192, 128,   0, 1 }, { 160,  96,   0, 1 },
  { 128,  64,   0, 1 }, {  96,  32,   0, 1 }, {  64,   0,   0, 1 }, {  32,   0,   0, 1 },
  {   0,   0,   0, 1 }
};
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
  {  64,  32,  32, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone3colord[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  32,  32,   0, 1 }, { 160, 224, 192, 1 }, { 128, 128,  96, 1 }, {  64,  96,  64, 1 },
  {  64,  64,  32, 1 }, {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 192,   0, 1 },
  { 224,  64,   0, 1 }, { 128,   0,   0, 1 }, {   0, 224, 224, 1 }, { 224, 224, 128, 1 },
  {  32, 160,   0, 1 }, {  32,  64,  64, 1 }, {  32,   0,  64, 1 }, {  64,   0,  64, 1 },
  {  32,  32,   0, 1 }, { 224, 160,   0, 1 }, {  64,  64,   0, 1 }, { 224, 224,  96, 1 },
  {  32,   0,  96, 1 }, {   0,   0,   0, 1 }, { 224,  64,   0, 1 }, { 128,   0,   0, 1 },
  {  64,   0,   0, 1 }, {   0, 224,   0, 1 }, {   0,  64,   0, 1 }, { 224,   0, 224, 1 },
  {  64,   0, 160, 1 }, { 224, 160,   0, 1 }, {   0,   0,  32, 1 }, { 224, 224,  32, 1 }
};
PALETTEENTRY zone3colboss0[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }
};
PALETTEENTRY zone3colboss1[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32,  32, 1 }, {  64,  64,  64, 1 },
  {  96,  96,  96, 1 }, { 128, 128, 128, 1 }, { 160, 160, 160, 1 }, { 192, 192, 192, 1 },
  { 224, 224, 224, 1 }, { 192, 160, 224, 1 }, { 128,  96, 160, 1 }, {  96,  64, 128, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }
};
palette_part colortbl[7] = {
  { advacolor,    0, 64 }, { advacolor,      0, 64 }, { advacolor2,     0, 64 }, { gamecolor, 0, 16 },
  { zone3colord, 16, 48 }, { zone3colboss0, 16, 16 }, { zone3colboss1, 16, 16 }
};
static int FadeCount;
void clchgctr() { /* Line 113, Address: 0x1024aa0 */
  colchg3d(); /* Line 114, Address: 0x1024aa8 */
} /* Line 115, Address: 0x1024ab0 */

void colchg3d() { /* Line 117, Address: 0x1024ac0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col3d0cnt, col3d0col); /* Line 118, Address: 0x1024ac8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col3d1cnt, col3d1col); /* Line 119, Address: 0x1024af0 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col3d2cnt, col3d2col); /* Line 120, Address: 0x1024b18 */
} /* Line 121, Address: 0x1024b40 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 130, Address: 0x1024b50 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 133, Address: 0x1024b68 */
  if ((char)*pChgTime < 0) { /* Line 134, Address: 0x1024b7c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 136, Address: 0x1024b9c */
    ++*pChgCnt; /* Line 137, Address: 0x1024bc0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 138, Address: 0x1024bd4 */

      *pChgCnt = 0; /* Line 140, Address: 0x1024c00 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 143, Address: 0x1024c08 */
    *pChgTime = pCntTbl[0]; /* Line 144, Address: 0x1024c24 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 145, Address: 0x1024c34 */
  }





} /* Line 152, Address: 0x1024c6c */


void fadein0() { /* Line 155, Address: 0x1024c80 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 159, Address: 0x1024c8c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 161, Address: 0x1024cc0 */
    lpPe->peRed = 0; /* Line 162, Address: 0x1024ccc */
    lpPe->peGreen = 0; /* Line 163, Address: 0x1024cd0 */
    lpPe->peBlue = 0; /* Line 164, Address: 0x1024cd4 */
    lpPe->peFlags = 1; /* Line 165, Address: 0x1024cd8 */
    ++lpPe; /* Line 166, Address: 0x1024ce0 */
  } /* Line 167, Address: 0x1024ce4 */
  FadeCount = 0; /* Line 168, Address: 0x1024d00 */
  *lpFadeFlag = 1; /* Line 169, Address: 0x1024d08 */

} /* Line 171, Address: 0x1024d18 */



int fadein0_new() { /* Line 175, Address: 0x1024d30 */

  int_flg = 18; /* Line 177, Address: 0x1024d38 */

  fadein1(); /* Line 179, Address: 0x1024d44 */


  if (++FadeCount > 21) { /* Line 182, Address: 0x1024d4c */
    FadeCount = 0; /* Line 183, Address: 0x1024d6c */
    return 1; /* Line 184, Address: 0x1024d74 */
  }
  return 0; /* Line 186, Address: 0x1024d80 */
} /* Line 187, Address: 0x1024d84 */



static void fadein1() { /* Line 191, Address: 0x1024da0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 195, Address: 0x1024db4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 196, Address: 0x1024de8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 198, Address: 0x1024e1c */
    fadein2(lpPe, lpPe2); /* Line 199, Address: 0x1024e28 */
    ++lpPe; /* Line 200, Address: 0x1024e38 */
    ++lpPe2; /* Line 201, Address: 0x1024e3c */
  } /* Line 202, Address: 0x1024e40 */
  if (stageno.b.h == 1) return; /* Line 203, Address: 0x1024e5c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 205, Address: 0x1024e78 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 206, Address: 0x1024eac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 208, Address: 0x1024ee0 */
    fadein2(lpPe, lpPe2); /* Line 209, Address: 0x1024eec */
    ++lpPe; /* Line 210, Address: 0x1024efc */
    ++lpPe2; /* Line 211, Address: 0x1024f00 */
  } /* Line 212, Address: 0x1024f04 */



} /* Line 216, Address: 0x1024f20 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 220, Address: 0x1024f40 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 221, Address: 0x1024f4c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 224, Address: 0x1024fac */
      lpPeDest->peBlue += 32; /* Line 225, Address: 0x1024fd0 */
    } /* Line 226, Address: 0x1024fe0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 227, Address: 0x1024fe8 */
      lpPeDest->peGreen += 32; /* Line 228, Address: 0x102500c */
    } /* Line 229, Address: 0x102501c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 230, Address: 0x1025024 */
      lpPeDest->peRed += 32; /* Line 231, Address: 0x1025048 */
    }
  }

} /* Line 235, Address: 0x102505c */


void fadeout() {
  startcolor = 0; /* Line 239, Address: 0x1025070 */
  colorcnt = 63; /* Line 240, Address: 0x1025078 */

  FadeCount = 0; /* Line 242, Address: 0x1025084 */
  *lpFadeFlag = 2; /* Line 243, Address: 0x102508c */

} /* Line 245, Address: 0x102509c */



static int fadeout_new() { /* Line 249, Address: 0x10250b0 */

  int_flg = 18; /* Line 251, Address: 0x10250b8 */

  fadeout1(); /* Line 253, Address: 0x10250c4 */


  if (++FadeCount > 21) { /* Line 256, Address: 0x10250cc */
    FadeCount = 0; /* Line 257, Address: 0x10250ec */
    return 1; /* Line 258, Address: 0x10250f4 */
  }
  return 0; /* Line 260, Address: 0x1025100 */
} /* Line 261, Address: 0x1025104 */


static void fadeout1() { /* Line 264, Address: 0x1025120 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 268, Address: 0x1025130 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 270, Address: 0x1025164 */
    fadeout2(lpPe); /* Line 271, Address: 0x1025170 */
    ++lpPe; /* Line 272, Address: 0x102517c */
  } /* Line 273, Address: 0x1025180 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 274, Address: 0x102519c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 276, Address: 0x10251d0 */
    fadeout2(lpPe); /* Line 277, Address: 0x10251dc */
    ++lpPe; /* Line 278, Address: 0x10251e8 */
  } /* Line 279, Address: 0x10251ec */


} /* Line 282, Address: 0x1025208 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 285, Address: 0x1025220 */
  if (lpPeDest->peRed) { /* Line 286, Address: 0x1025228 */
    lpPeDest->peRed -= 32; /* Line 287, Address: 0x1025238 */
  } /* Line 288, Address: 0x102524c */
  else if (lpPeDest->peGreen) { /* Line 289, Address: 0x1025254 */
    lpPeDest->peGreen -= 32; /* Line 290, Address: 0x1025264 */
  } /* Line 291, Address: 0x1025274 */
  else if (lpPeDest->peBlue) { /* Line 292, Address: 0x102527c */
    lpPeDest->peBlue -= 32; /* Line 293, Address: 0x102528c */
  }

} /* Line 296, Address: 0x102529c */




void flashin() { /* Line 301, Address: 0x10252b0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 305, Address: 0x10252bc */
  colorcnt = 63; /* Line 306, Address: 0x10252c4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 308, Address: 0x10252d0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 310, Address: 0x1025304 */
    lpPe->peRed = 224; /* Line 311, Address: 0x1025310 */
    lpPe->peGreen = 224; /* Line 312, Address: 0x1025318 */
    lpPe->peBlue = 224; /* Line 313, Address: 0x1025320 */
    lpPe->peFlags = 1; /* Line 314, Address: 0x1025328 */
    ++lpPe; /* Line 315, Address: 0x1025330 */
  } /* Line 316, Address: 0x1025334 */
  FadeCount = 0; /* Line 317, Address: 0x1025350 */
  *lpFadeFlag = 3; /* Line 318, Address: 0x1025358 */

} /* Line 320, Address: 0x1025368 */

static int flashin_new() { /* Line 322, Address: 0x1025380 */

  int_flg = 18; /* Line 324, Address: 0x1025388 */

  flashin1(); /* Line 326, Address: 0x1025394 */


  if (++FadeCount > 21) { /* Line 329, Address: 0x102539c */
    FadeCount = 0; /* Line 330, Address: 0x10253bc */
    return 1; /* Line 331, Address: 0x10253c4 */
  }
  return 0; /* Line 333, Address: 0x10253d0 */
} /* Line 334, Address: 0x10253d4 */

static void flashin1() { /* Line 336, Address: 0x10253f0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 340, Address: 0x1025404 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 341, Address: 0x1025438 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 343, Address: 0x102546c */
    flashin2(lpPe, lpPe2); /* Line 344, Address: 0x1025478 */
    ++lpPe; /* Line 345, Address: 0x1025488 */
    ++lpPe2; /* Line 346, Address: 0x102548c */
  } /* Line 347, Address: 0x1025490 */
  if (stageno.b.h == 1) return; /* Line 348, Address: 0x10254ac */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 350, Address: 0x10254c8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 351, Address: 0x10254fc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 353, Address: 0x1025530 */
    flashin2(lpPe, lpPe2); /* Line 354, Address: 0x102553c */
    ++lpPe; /* Line 355, Address: 0x102554c */
    ++lpPe2; /* Line 356, Address: 0x1025550 */
  } /* Line 357, Address: 0x1025554 */



} /* Line 361, Address: 0x1025570 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 365, Address: 0x1025590 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 366, Address: 0x102559c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 369, Address: 0x10255fc */
      lpPeDest->peBlue -= 32; /* Line 370, Address: 0x1025620 */
    } /* Line 371, Address: 0x1025630 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 372, Address: 0x1025638 */
      lpPeDest->peGreen -= 32; /* Line 373, Address: 0x102565c */
    } /* Line 374, Address: 0x102566c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 375, Address: 0x1025674 */
      lpPeDest->peRed -= 32; /* Line 376, Address: 0x1025698 */
    }
  }

} /* Line 380, Address: 0x10256ac */


void flashout() {
  startcolor = 0; /* Line 384, Address: 0x10256c0 */
  colorcnt = 63; /* Line 385, Address: 0x10256c8 */

  FadeCount = 0; /* Line 387, Address: 0x10256d4 */
  *lpFadeFlag = 4; /* Line 388, Address: 0x10256dc */

} /* Line 390, Address: 0x10256ec */

static int flashout_new() { /* Line 392, Address: 0x1025700 */

  int_flg = 18; /* Line 394, Address: 0x1025708 */

  flashout1(); /* Line 396, Address: 0x1025714 */


  if (++FadeCount > 21) { /* Line 399, Address: 0x102571c */
    FadeCount = 0; /* Line 400, Address: 0x102573c */
    return 1; /* Line 401, Address: 0x1025744 */
  }
  return 0; /* Line 403, Address: 0x1025750 */
} /* Line 404, Address: 0x1025754 */


static void flashout1() { /* Line 407, Address: 0x1025770 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 411, Address: 0x1025780 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 413, Address: 0x10257b4 */
    flashout2(lpPe); /* Line 414, Address: 0x10257c0 */
    ++lpPe; /* Line 415, Address: 0x10257cc */
  } /* Line 416, Address: 0x10257d0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 417, Address: 0x10257ec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 419, Address: 0x1025820 */
    flashout2(lpPe); /* Line 420, Address: 0x102582c */
    ++lpPe; /* Line 421, Address: 0x1025838 */
  } /* Line 422, Address: 0x102583c */


} /* Line 425, Address: 0x1025858 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 428, Address: 0x1025870 */
  if (lpPeDest->peRed != 224) { /* Line 429, Address: 0x1025878 */
    lpPeDest->peRed += 32; /* Line 430, Address: 0x1025890 */
  } /* Line 431, Address: 0x10258a4 */
  else if (lpPeDest->peGreen != 224) { /* Line 432, Address: 0x10258ac */
    lpPeDest->peGreen += 32; /* Line 433, Address: 0x10258c4 */
  } /* Line 434, Address: 0x10258d4 */
  else if (lpPeDest->peBlue != 224) { /* Line 435, Address: 0x10258dc */
    lpPeDest->peBlue += 32; /* Line 436, Address: 0x10258f4 */
  }


} /* Line 440, Address: 0x1025904 */


void colorset(int ColorNo) { /* Line 443, Address: 0x1025910 */
  colorset00(ColorNo, 1); /* Line 444, Address: 0x102591c */
} /* Line 445, Address: 0x102592c */

void colorset2(int ColorNo) { /* Line 447, Address: 0x1025940 */
  colorset00(ColorNo, 0); /* Line 448, Address: 0x102594c */
} /* Line 449, Address: 0x102595c */

void colorset3(int ColorNo) { /* Line 451, Address: 0x1025970 */
  colorset00(ColorNo, 0); /* Line 452, Address: 0x102597c */
} /* Line 453, Address: 0x102598c */





void colorset00(int ColorNo, int WorkOffs) { /* Line 459, Address: 0x10259a0 */
  PALETTEENTRY *lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 464, Address: 0x10259c0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 466, Address: 0x1025a28 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 468, Address: 0x1025a38 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 470, Address: 0x1025a48 */
    default:
      lppe = lpcolorwk4; break; /* Line 472, Address: 0x1025a58 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 475, Address: 0x1025a60 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 476, Address: 0x1025a78 */
  n = colortbl[ColorNo].cnt; /* Line 477, Address: 0x1025aa0 */
  for (i = 0; i < n; ++i) { /* Line 478, Address: 0x1025ac0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 479, Address: 0x1025acc */
  } /* Line 480, Address: 0x1025afc */

} /* Line 482, Address: 0x1025b0c */




int FadeProc() { /* Line 487, Address: 0x1025b30 */
  switch (*lpFadeFlag) { /* Line 488, Address: 0x1025b38 */
    case 1:
      return fadein0_new(); /* Line 490, Address: 0x1025b7c */
    case 2:
      return fadeout_new(); /* Line 492, Address: 0x1025b8c */
    case 3:
      return flashin_new(); /* Line 494, Address: 0x1025b9c */
    case 4:
      return flashout_new(); /* Line 496, Address: 0x1025bac */
  }
  return 1; /* Line 498, Address: 0x1025bbc */

} /* Line 500, Address: 0x1025bc0 */
