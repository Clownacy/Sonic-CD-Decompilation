#include "..\EQU.H"
#include "COL3C.H"

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

unsigned char col3c0cnt[8] = { 44, 3, 1, 0, 2, 1, 1, 2 };
PALETTEENTRY col3c0col[3] = { { 224, 224, 224, 1 }, { 224,   0, 224, 1 }, {   0,   0,   0, 1 } };
unsigned char col3c1cnt[34] = {
  61, 16, 30,  0,  5,  1, 15,  0,  5,  1,
   1,  0,  5,  1,  1,  0, 60,  1,  1,  0,
   8,  1,  1,  0,  8,  1,  1,  0,  8,  1,
   1,  0,  8,  1
};
PALETTEENTRY col3c1col[2] = { { 224, 160,   0, 1 }, {   0,   0,   0, 1 } };
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
  {  32,  32, 160, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone3colorc12[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0, 224, 1 }, { 224, 224, 128, 1 }, {   0, 224, 160, 1 }, {   0, 160, 128, 1 },
  {   0,  96,  96, 1 }, {   0,   0,  96, 1 }, {   0,   0,  32, 1 }, { 160, 224,   0, 1 },
  {   0, 192,   0, 1 }, {   0,  96,   0, 1 }, {   0,   0,   0, 1 }, { 192,  64, 224, 1 },
  { 224,   0, 224, 1 }, { 128,   0, 192, 1 }, {  64,   0, 128, 1 }, {   0,   0, 160, 1 },
  {   0,   0, 224, 1 }, { 128, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  96,   0, 1 },
  {   0,  64,   0, 1 }, {   0,   0,  96, 1 }, { 224, 224, 224, 1 }, {   0, 160, 224, 1 },
  {   0,  32, 224, 1 }, { 224, 160,   0, 1 }, { 224,  64,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 160,   0, 1 }, {   0,  32,   0, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY zone3colorc[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0, 224, 1 }, { 224, 224, 128, 1 }, {   0, 224, 160, 1 }, {   0, 160, 128, 1 },
  {   0,  96,  96, 1 }, {   0,   0,  96, 1 }, {   0,   0,  32, 1 }, { 160, 224,   0, 1 },
  {   0, 192,   0, 1 }, {   0,  96,   0, 1 }, {   0,   0,   0, 1 }, { 192,  64, 224, 1 },
  { 224,   0, 224, 1 }, { 128,   0, 192, 1 }, {  64,   0, 128, 1 }, {   0,   0, 160, 1 },
  {   0,   0, 224, 1 }, { 128, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  96,   0, 1 },
  {   0,  64,   0, 1 }, {   0,   0,  96, 1 }, { 224, 224, 224, 1 }, {   0, 160, 224, 1 },
  {   0,  32, 224, 1 }, { 224, 160,   0, 1 }, { 224,  64,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 160,   0, 1 }, {   0,  32,   0, 1 }, {  96, 128,  64, 1 }
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
palette_part colortbl[8] = {
  { advacolor,    0, 64 }, { advacolor,      0, 64 }, {     advacolor2, 0, 64 }, {      gamecolor, 0, 16 },
  { zone3colorc, 16, 48 }, { zone3colboss0, 16, 16 }, { zone3colboss1, 16, 16 }, { zone3colorc12, 16, 48 }
};
static int FadeCount;



void clchgctr(void) { /* Line 115, Address: 0x1025bb0 */
  colchg3c(); /* Line 116, Address: 0x1025bb8 */
} /* Line 117, Address: 0x1025bc0 */

void colchg3c(void) { /* Line 119, Address: 0x1025bd0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col3c0cnt, col3c0col); /* Line 120, Address: 0x1025bd8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col3c1cnt, col3c1col); /* Line 121, Address: 0x1025c00 */
} /* Line 122, Address: 0x1025c28 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 132, Address: 0x1025c40 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 135, Address: 0x1025c58 */
  if ((char)*pChgTime < 0) { /* Line 136, Address: 0x1025c6c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 138, Address: 0x1025c8c */
    ++*pChgCnt; /* Line 139, Address: 0x1025cb0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 140, Address: 0x1025cc4 */

      *pChgCnt = 0; /* Line 142, Address: 0x1025cf0 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 145, Address: 0x1025cf8 */
    *pChgTime = pCntTbl[0]; /* Line 146, Address: 0x1025d14 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 147, Address: 0x1025d24 */
  }





} /* Line 154, Address: 0x1025d5c */


void fadein0(void) { /* Line 157, Address: 0x1025d70 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 161, Address: 0x1025d7c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 163, Address: 0x1025db0 */
    lpPe->peRed = 0; /* Line 164, Address: 0x1025dbc */
    lpPe->peGreen = 0; /* Line 165, Address: 0x1025dc0 */
    lpPe->peBlue = 0; /* Line 166, Address: 0x1025dc4 */
    lpPe->peFlags = 1; /* Line 167, Address: 0x1025dc8 */
    ++lpPe; /* Line 168, Address: 0x1025dd0 */
  } /* Line 169, Address: 0x1025dd4 */
  FadeCount = 0; /* Line 170, Address: 0x1025df0 */
  *lpFadeFlag = 1; /* Line 171, Address: 0x1025df8 */

} /* Line 173, Address: 0x1025e08 */



int fadein0_new(void) { /* Line 177, Address: 0x1025e20 */

  int_flg = 18; /* Line 179, Address: 0x1025e28 */

  fadein1(); /* Line 181, Address: 0x1025e34 */


  if (++FadeCount > 21) { /* Line 184, Address: 0x1025e3c */
    FadeCount = 0; /* Line 185, Address: 0x1025e5c */
    return 1; /* Line 186, Address: 0x1025e64 */
  }
  return 0; /* Line 188, Address: 0x1025e70 */
} /* Line 189, Address: 0x1025e74 */



static void fadein1(void) { /* Line 193, Address: 0x1025e90 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 197, Address: 0x1025ea4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 198, Address: 0x1025ed8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 200, Address: 0x1025f0c */
    fadein2(lpPe, lpPe2); /* Line 201, Address: 0x1025f18 */
    ++lpPe; /* Line 202, Address: 0x1025f28 */
    ++lpPe2; /* Line 203, Address: 0x1025f2c */
  } /* Line 204, Address: 0x1025f30 */
  if (stageno.b.h == 1) return; /* Line 205, Address: 0x1025f4c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 207, Address: 0x1025f68 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 208, Address: 0x1025f9c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 210, Address: 0x1025fd0 */
    fadein2(lpPe, lpPe2); /* Line 211, Address: 0x1025fdc */
    ++lpPe; /* Line 212, Address: 0x1025fec */
    ++lpPe2; /* Line 213, Address: 0x1025ff0 */
  } /* Line 214, Address: 0x1025ff4 */



} /* Line 218, Address: 0x1026010 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 222, Address: 0x1026030 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 223, Address: 0x102603c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 226, Address: 0x102609c */
      lpPeDest->peBlue += 32; /* Line 227, Address: 0x10260c0 */
    } /* Line 228, Address: 0x10260d0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 229, Address: 0x10260d8 */
      lpPeDest->peGreen += 32; /* Line 230, Address: 0x10260fc */
    } /* Line 231, Address: 0x102610c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 232, Address: 0x1026114 */
      lpPeDest->peRed += 32; /* Line 233, Address: 0x1026138 */
    }
  }

} /* Line 237, Address: 0x102614c */


void fadeout(void) {
  startcolor = 0; /* Line 241, Address: 0x1026160 */
  colorcnt = 63; /* Line 242, Address: 0x1026168 */

  FadeCount = 0; /* Line 244, Address: 0x1026174 */
  *lpFadeFlag = 2; /* Line 245, Address: 0x102617c */

} /* Line 247, Address: 0x102618c */



static int fadeout_new(void) { /* Line 251, Address: 0x10261a0 */

  int_flg = 18; /* Line 253, Address: 0x10261a8 */

  fadeout1(); /* Line 255, Address: 0x10261b4 */


  if (++FadeCount > 21) { /* Line 258, Address: 0x10261bc */
    FadeCount = 0; /* Line 259, Address: 0x10261dc */
    return 1; /* Line 260, Address: 0x10261e4 */
  }
  return 0; /* Line 262, Address: 0x10261f0 */
} /* Line 263, Address: 0x10261f4 */


static void fadeout1(void) { /* Line 266, Address: 0x1026210 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 270, Address: 0x1026220 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 272, Address: 0x1026254 */
    fadeout2(lpPe); /* Line 273, Address: 0x1026260 */
    ++lpPe; /* Line 274, Address: 0x102626c */
  } /* Line 275, Address: 0x1026270 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 276, Address: 0x102628c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 278, Address: 0x10262c0 */
    fadeout2(lpPe); /* Line 279, Address: 0x10262cc */
    ++lpPe; /* Line 280, Address: 0x10262d8 */
  } /* Line 281, Address: 0x10262dc */


} /* Line 284, Address: 0x10262f8 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 287, Address: 0x1026310 */
  if (lpPeDest->peRed) { /* Line 288, Address: 0x1026318 */
    lpPeDest->peRed -= 32; /* Line 289, Address: 0x1026328 */
  } /* Line 290, Address: 0x102633c */
  else if (lpPeDest->peGreen) { /* Line 291, Address: 0x1026344 */
    lpPeDest->peGreen -= 32; /* Line 292, Address: 0x1026354 */
  } /* Line 293, Address: 0x1026364 */
  else if (lpPeDest->peBlue) { /* Line 294, Address: 0x102636c */
    lpPeDest->peBlue -= 32; /* Line 295, Address: 0x102637c */
  }

} /* Line 298, Address: 0x102638c */




void flashin(void) { /* Line 303, Address: 0x10263a0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 307, Address: 0x10263ac */
  colorcnt = 63; /* Line 308, Address: 0x10263b4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 310, Address: 0x10263c0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 312, Address: 0x10263f4 */
    lpPe->peRed = 224; /* Line 313, Address: 0x1026400 */
    lpPe->peGreen = 224; /* Line 314, Address: 0x1026408 */
    lpPe->peBlue = 224; /* Line 315, Address: 0x1026410 */
    lpPe->peFlags = 1; /* Line 316, Address: 0x1026418 */
    ++lpPe; /* Line 317, Address: 0x1026420 */
  } /* Line 318, Address: 0x1026424 */
  FadeCount = 0; /* Line 319, Address: 0x1026440 */
  *lpFadeFlag = 3; /* Line 320, Address: 0x1026448 */

} /* Line 322, Address: 0x1026458 */

static int flashin_new(void) { /* Line 324, Address: 0x1026470 */

  int_flg = 18; /* Line 326, Address: 0x1026478 */

  flashin1(); /* Line 328, Address: 0x1026484 */


  if (++FadeCount > 21) { /* Line 331, Address: 0x102648c */
    FadeCount = 0; /* Line 332, Address: 0x10264ac */
    return 1; /* Line 333, Address: 0x10264b4 */
  }
  return 0; /* Line 335, Address: 0x10264c0 */
} /* Line 336, Address: 0x10264c4 */

static void flashin1(void) { /* Line 338, Address: 0x10264e0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 342, Address: 0x10264f4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 343, Address: 0x1026528 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 345, Address: 0x102655c */
    flashin2(lpPe, lpPe2); /* Line 346, Address: 0x1026568 */
    ++lpPe; /* Line 347, Address: 0x1026578 */
    ++lpPe2; /* Line 348, Address: 0x102657c */
  } /* Line 349, Address: 0x1026580 */
  if (stageno.b.h == 1) return; /* Line 350, Address: 0x102659c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 352, Address: 0x10265b8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 353, Address: 0x10265ec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 355, Address: 0x1026620 */
    flashin2(lpPe, lpPe2); /* Line 356, Address: 0x102662c */
    ++lpPe; /* Line 357, Address: 0x102663c */
    ++lpPe2; /* Line 358, Address: 0x1026640 */
  } /* Line 359, Address: 0x1026644 */



} /* Line 363, Address: 0x1026660 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 367, Address: 0x1026680 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 368, Address: 0x102668c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 371, Address: 0x10266ec */
      lpPeDest->peBlue -= 32; /* Line 372, Address: 0x1026710 */
    } /* Line 373, Address: 0x1026720 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 374, Address: 0x1026728 */
      lpPeDest->peGreen -= 32; /* Line 375, Address: 0x102674c */
    } /* Line 376, Address: 0x102675c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 377, Address: 0x1026764 */
      lpPeDest->peRed -= 32; /* Line 378, Address: 0x1026788 */
    }
  }

} /* Line 382, Address: 0x102679c */


void flashout(void) {
  startcolor = 0; /* Line 386, Address: 0x10267b0 */
  colorcnt = 63; /* Line 387, Address: 0x10267b8 */

  FadeCount = 0; /* Line 389, Address: 0x10267c4 */
  *lpFadeFlag = 4; /* Line 390, Address: 0x10267cc */

} /* Line 392, Address: 0x10267dc */

static int flashout_new(void) { /* Line 394, Address: 0x10267f0 */

  int_flg = 18; /* Line 396, Address: 0x10267f8 */

  flashout1(); /* Line 398, Address: 0x1026804 */


  if (++FadeCount > 21) { /* Line 401, Address: 0x102680c */
    FadeCount = 0; /* Line 402, Address: 0x102682c */
    return 1; /* Line 403, Address: 0x1026834 */
  }
  return 0; /* Line 405, Address: 0x1026840 */
} /* Line 406, Address: 0x1026844 */


static void flashout1(void) { /* Line 409, Address: 0x1026860 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 413, Address: 0x1026870 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 415, Address: 0x10268a4 */
    flashout2(lpPe); /* Line 416, Address: 0x10268b0 */
    ++lpPe; /* Line 417, Address: 0x10268bc */
  } /* Line 418, Address: 0x10268c0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 419, Address: 0x10268dc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 421, Address: 0x1026910 */
    flashout2(lpPe); /* Line 422, Address: 0x102691c */
    ++lpPe; /* Line 423, Address: 0x1026928 */
  } /* Line 424, Address: 0x102692c */


} /* Line 427, Address: 0x1026948 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 430, Address: 0x1026960 */
  if (lpPeDest->peRed != 224) { /* Line 431, Address: 0x1026968 */
    lpPeDest->peRed += 32; /* Line 432, Address: 0x1026980 */
  } /* Line 433, Address: 0x1026994 */
  else if (lpPeDest->peGreen != 224) { /* Line 434, Address: 0x102699c */
    lpPeDest->peGreen += 32; /* Line 435, Address: 0x10269b4 */
  } /* Line 436, Address: 0x10269c4 */
  else if (lpPeDest->peBlue != 224) { /* Line 437, Address: 0x10269cc */
    lpPeDest->peBlue += 32; /* Line 438, Address: 0x10269e4 */
  }


} /* Line 442, Address: 0x10269f4 */


void colorset(int ColorNo) { /* Line 445, Address: 0x1026a00 */
  colorset00(ColorNo, 1); /* Line 446, Address: 0x1026a0c */
} /* Line 447, Address: 0x1026a1c */

void colorset2(int ColorNo) { /* Line 449, Address: 0x1026a30 */
  colorset00(ColorNo, 0); /* Line 450, Address: 0x1026a3c */
} /* Line 451, Address: 0x1026a4c */

void colorset3(int ColorNo) { /* Line 453, Address: 0x1026a60 */
  colorset00(ColorNo, 0); /* Line 454, Address: 0x1026a6c */
} /* Line 455, Address: 0x1026a7c */





void colorset00(int ColorNo, int WorkOffs) { /* Line 461, Address: 0x1026a90 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 466, Address: 0x1026ab0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 468, Address: 0x1026b18 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 470, Address: 0x1026b28 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 472, Address: 0x1026b38 */
    default:
      lppe = lpcolorwk4; break; /* Line 474, Address: 0x1026b48 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 477, Address: 0x1026b50 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 478, Address: 0x1026b68 */
  n = colortbl[ColorNo].cnt; /* Line 479, Address: 0x1026b90 */
  for (i = 0; i < n; ++i) { /* Line 480, Address: 0x1026bb0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 481, Address: 0x1026bbc */
  } /* Line 482, Address: 0x1026bec */

} /* Line 484, Address: 0x1026bfc */




int FadeProc(void) { /* Line 489, Address: 0x1026c20 */
  switch (*lpFadeFlag) { /* Line 490, Address: 0x1026c28 */
    case 1:
      return fadein0_new(); /* Line 492, Address: 0x1026c6c */
    case 2:
      return fadeout_new(); /* Line 494, Address: 0x1026c7c */
    case 3:
      return flashin_new(); /* Line 496, Address: 0x1026c8c */
    case 4:
      return flashout_new(); /* Line 498, Address: 0x1026c9c */
  }
  return 1; /* Line 500, Address: 0x1026cac */

} /* Line 502, Address: 0x1026cb0 */
