#include "..\EQU.H"
#include "COL6B.H"

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

PALETTEENTRY zone3colora[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  64,   0, 128, 1 }, { 224, 224,  96, 1 }, { 224,  96, 160, 1 }, { 224,  64, 128, 1 },
  { 192,  32, 128, 1 }, {  96,   0,  64, 1 }, {  64,   0,  32, 1 }, {  32, 224,   0, 1 },
  {   0, 160,   0, 1 }, {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 224, 1 }, { 160,   0,  64, 1 }, { 224, 160,   0, 1 },
  {  64,   0, 128, 1 }, { 224, 224,   0, 1 }, { 224,  96,   0, 1 }, { 160,  64,   0, 1 },
  { 128,  32,   0, 1 }, {  32,   0,   0, 1 }, { 224,  96,   0, 1 }, { 192,   0, 128, 1 },
  { 128,   0, 128, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 128, 128, 1 },
  { 224, 224,   0, 1 }, { 224,   0, 224, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }
};
unsigned char col6a0cnt[8] = { 33, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a0col[3] = { { 224,   0, 224, 1 }, {  96,   0,  96, 1 }, {   0,   0,   0, 1 } };
unsigned char col6a1cnt[8] = { 34, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a1col[3] = { {  96,   0,  96, 1 }, {   0,   0,   0, 1 }, { 224,   0, 224, 1 } };
unsigned char col6a2cnt[8] = { 35, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a2col[3] = { {   0,   0,   0, 1 }, { 224,   0, 224, 1 }, {  96,   0,  96, 1 } };
unsigned char col6a3cnt[124] = {
  49, 61, 1, 1, 1, 0, 1, 2, 1, 0,
  1, 3, 1, 0, 1, 1, 1, 0, 1, 2,
  1, 0, 1, 3, 1, 0, 1, 1, 1, 0,
  1, 2, 1, 0, 1, 3, 1, 0, 1, 1,
  1, 0, 1, 2, 1, 0, 1, 3, 1, 0,
  1, 1, 1, 0, 1, 2, 1, 0, 1, 3,
  1, 0, 1, 1, 1, 0, 1, 2, 1, 0,
  1, 3, 1, 0, 1, 1, 1, 0, 1, 2,
  1, 0, 1, 3, 1, 0, 1, 1, 1, 0,
  1, 2, 1, 0, 1, 3, 1, 0, 1, 1,
  1, 0, 1, 2, 1, 0, 1, 3, 1, 0,
  1, 1, 1, 0, 1, 2, 1, 0, 1, 3,
  1, 0, 60, 1
};
PALETTEENTRY col6a3col[4] = { {   0,   0,   0, 1 }, {  32,  64, 128, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 } };
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  96,  64, 128, 1 }, { 224,   0, 224, 1 }, {  96,   0,  96, 1 }, {   0,   0,   0, 1 },
  {  96, 224,  96, 1 }, { 128, 224, 224, 1 }, { 224,   0, 160, 1 }, { 224,   0,   0, 1 },
  { 224, 224,  96, 1 }, { 224, 128,   0, 1 }, { 192,  64,   0, 1 }, {  96,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  64,  32, 1 }, {  32, 160,  32, 1 }, {  32, 224,  64, 1 },
  {  96,  64, 128, 1 }, {  32,  64, 128, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32,  96, 1 }, { 224, 224,  96, 1 }, { 128,  64, 128, 1 },
  { 192,  64,  96, 1 }, { 224,  96,  64, 1 }, { 224, 160,  32, 1 }, {  32,   0,   0, 1 },
  {  64,   0,   0, 1 }, { 128,   0,  32, 1 }, { 192,   0,  32, 1 }, { 224,   0,  32, 1 }
};
PALETTEENTRY gamecolor[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone8colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  96,  64, 128, 1 }, { 224,   0, 224, 1 }, {  96,   0,  96, 1 }, {   0,   0,   0, 1 },
  {  96, 224,  96, 1 }, { 128, 224, 224, 1 }, { 224,   0, 160, 1 }, { 224,   0,   0, 1 },
  { 224, 224,  96, 1 }, { 224, 128,   0, 1 }, { 192,  64,   0, 1 }, {  96,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  64,  32, 1 }, {  32, 160,  32, 1 }, {  32, 224,  64, 1 },
  {  96,  64, 128, 1 }, {  32,  64, 128, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32,  96, 1 }, { 224, 224,  96, 1 }, { 128,  64, 128, 1 },
  { 192,  64,  96, 1 }, { 224,  96,  64, 1 }, { 224, 160,  32, 1 }, {  32,   0,   0, 1 },
  {  64,   0,   0, 1 }, { 128,   0,  32, 1 }, { 192,   0,  32, 1 }, { 224,   0,  32, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, { 128, 128, 128, 1 },
  {   0,  64, 224, 1 }, {   0,   0, 128, 1 }, { 224, 224, 224, 1 }, {  64,  96, 224, 1 },
  {  96,   0,   0, 1 }, { 224, 128, 224, 1 }, { 224, 128,   0, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  96,  64, 128, 1 }, { 224,   0, 224, 1 }, {  96,   0,  96, 1 }, {   0,   0,   0, 1 },
  {  96, 224,  96, 1 }, { 128, 224, 224, 1 }, { 224,   0, 160, 1 }, { 224,   0,   0, 1 },
  { 224, 224,  96, 1 }, { 224, 128,   0, 1 }, { 192,  64,   0, 1 }, {  96,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  64,  32, 1 }, {  32, 160,  32, 1 }, {  32, 224,  64, 1 },
  {  96,  64, 128, 1 }, {  32,  64, 128, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32,  96, 1 }, { 224, 224,  96, 1 }, { 128,  64, 128, 1 },
  { 192,  64,  96, 1 }, { 224,  96,  64, 1 }, { 224, 160,  32, 1 }, {  32,   0,   0, 1 },
  {  64,   0,   0, 1 }, { 128,   0,  32, 1 }, { 192,   0,  32, 1 }, { 224,   0,  32, 1 }
};
palette_part colortbl[6] = {
  { advacolor,    0, 64 }, { advacolor,     0, 64 }, { advacolor2, 0, 64 }, { gamecolor, 0, 16 },
  { zone8colora, 16, 48 }, { zone82colora, 16, 48 }
};
static int FadeCount;




void clchgctr(void) { /* Line 132, Address: 0x1029f40 */
  colchg6b(); /* Line 133, Address: 0x1029f48 */
} /* Line 134, Address: 0x1029f50 */

void colchg6b(void) { /* Line 136, Address: 0x1029f60 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col6a0cnt, col6a0col); /* Line 137, Address: 0x1029f68 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col6a1cnt, col6a1col); /* Line 138, Address: 0x1029f90 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col6a2cnt, col6a2col); /* Line 139, Address: 0x1029fb8 */
  clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col); /* Line 140, Address: 0x1029fe0 */

} /* Line 142, Address: 0x102a008 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 152, Address: 0x102a020 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 155, Address: 0x102a038 */
  if ((char)*pChgTime < 0) { /* Line 156, Address: 0x102a04c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 158, Address: 0x102a06c */
    ++*pChgCnt; /* Line 159, Address: 0x102a090 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 160, Address: 0x102a0a4 */

      *pChgCnt = 0; /* Line 162, Address: 0x102a0d0 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 165, Address: 0x102a0d8 */
    *pChgTime = pCntTbl[0]; /* Line 166, Address: 0x102a0f4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 167, Address: 0x102a104 */
  }





} /* Line 174, Address: 0x102a13c */


void fadein0(void) { /* Line 177, Address: 0x102a150 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 181, Address: 0x102a15c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 183, Address: 0x102a190 */
    lpPe->peRed = 0; /* Line 184, Address: 0x102a19c */
    lpPe->peGreen = 0; /* Line 185, Address: 0x102a1a0 */
    lpPe->peBlue = 0; /* Line 186, Address: 0x102a1a4 */
    lpPe->peFlags = 1; /* Line 187, Address: 0x102a1a8 */
    ++lpPe; /* Line 188, Address: 0x102a1b0 */
  } /* Line 189, Address: 0x102a1b4 */
  FadeCount = 0; /* Line 190, Address: 0x102a1d0 */
  *lpFadeFlag = 1; /* Line 191, Address: 0x102a1d8 */

} /* Line 193, Address: 0x102a1e8 */



int fadein0_new(void) { /* Line 197, Address: 0x102a200 */

  int_flg = 18; /* Line 199, Address: 0x102a208 */

  fadein1(); /* Line 201, Address: 0x102a214 */


  if (++FadeCount > 21) { /* Line 204, Address: 0x102a21c */
    FadeCount = 0; /* Line 205, Address: 0x102a23c */
    return 1; /* Line 206, Address: 0x102a244 */
  }
  return 0; /* Line 208, Address: 0x102a250 */
} /* Line 209, Address: 0x102a254 */



static void fadein1(void) { /* Line 213, Address: 0x102a270 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 217, Address: 0x102a284 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 218, Address: 0x102a2b8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 220, Address: 0x102a2ec */
    fadein2(lpPe, lpPe2); /* Line 221, Address: 0x102a2f8 */
    ++lpPe; /* Line 222, Address: 0x102a308 */
    ++lpPe2; /* Line 223, Address: 0x102a30c */
  } /* Line 224, Address: 0x102a310 */
  if (stageno.b.h == 1) return; /* Line 225, Address: 0x102a32c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 227, Address: 0x102a348 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 228, Address: 0x102a37c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 230, Address: 0x102a3b0 */
    fadein2(lpPe, lpPe2); /* Line 231, Address: 0x102a3bc */
    ++lpPe; /* Line 232, Address: 0x102a3cc */
    ++lpPe2; /* Line 233, Address: 0x102a3d0 */
  } /* Line 234, Address: 0x102a3d4 */



} /* Line 238, Address: 0x102a3f0 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 242, Address: 0x102a410 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 243, Address: 0x102a41c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 246, Address: 0x102a47c */
      lpPeDest->peBlue += 32; /* Line 247, Address: 0x102a4a0 */
    } /* Line 248, Address: 0x102a4b0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 249, Address: 0x102a4b8 */
      lpPeDest->peGreen += 32; /* Line 250, Address: 0x102a4dc */
    } /* Line 251, Address: 0x102a4ec */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 252, Address: 0x102a4f4 */
      lpPeDest->peRed += 32; /* Line 253, Address: 0x102a518 */
    }
  }

} /* Line 257, Address: 0x102a52c */


void fadeout(void) {
  startcolor = 0; /* Line 261, Address: 0x102a540 */
  colorcnt = 63; /* Line 262, Address: 0x102a548 */

  FadeCount = 0; /* Line 264, Address: 0x102a554 */
  *lpFadeFlag = 2; /* Line 265, Address: 0x102a55c */

} /* Line 267, Address: 0x102a56c */



static int fadeout_new(void) { /* Line 271, Address: 0x102a580 */

  int_flg = 18; /* Line 273, Address: 0x102a588 */

  fadeout1(); /* Line 275, Address: 0x102a594 */


  if (++FadeCount > 21) { /* Line 278, Address: 0x102a59c */
    FadeCount = 0; /* Line 279, Address: 0x102a5bc */
    return 1; /* Line 280, Address: 0x102a5c4 */
  }
  return 0; /* Line 282, Address: 0x102a5d0 */
} /* Line 283, Address: 0x102a5d4 */


static void fadeout1(void) { /* Line 286, Address: 0x102a5f0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 290, Address: 0x102a600 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 292, Address: 0x102a634 */
    fadeout2(lpPe); /* Line 293, Address: 0x102a640 */
    ++lpPe; /* Line 294, Address: 0x102a64c */
  } /* Line 295, Address: 0x102a650 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 296, Address: 0x102a66c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 298, Address: 0x102a6a0 */
    fadeout2(lpPe); /* Line 299, Address: 0x102a6ac */
    ++lpPe; /* Line 300, Address: 0x102a6b8 */
  } /* Line 301, Address: 0x102a6bc */


} /* Line 304, Address: 0x102a6d8 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 307, Address: 0x102a6f0 */
  if (lpPeDest->peRed) { /* Line 308, Address: 0x102a6f8 */
    lpPeDest->peRed -= 32; /* Line 309, Address: 0x102a708 */
  } /* Line 310, Address: 0x102a71c */
  else if (lpPeDest->peGreen) { /* Line 311, Address: 0x102a724 */
    lpPeDest->peGreen -= 32; /* Line 312, Address: 0x102a734 */
  } /* Line 313, Address: 0x102a744 */
  else if (lpPeDest->peBlue) { /* Line 314, Address: 0x102a74c */
    lpPeDest->peBlue -= 32; /* Line 315, Address: 0x102a75c */
  }

} /* Line 318, Address: 0x102a76c */




void flashin(void) { /* Line 323, Address: 0x102a780 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 327, Address: 0x102a78c */
  colorcnt = 63; /* Line 328, Address: 0x102a794 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 330, Address: 0x102a7a0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 332, Address: 0x102a7d4 */
    lpPe->peRed = 224; /* Line 333, Address: 0x102a7e0 */
    lpPe->peGreen = 224; /* Line 334, Address: 0x102a7e8 */
    lpPe->peBlue = 224; /* Line 335, Address: 0x102a7f0 */
    lpPe->peFlags = 1; /* Line 336, Address: 0x102a7f8 */
    ++lpPe; /* Line 337, Address: 0x102a800 */
  } /* Line 338, Address: 0x102a804 */
  FadeCount = 0; /* Line 339, Address: 0x102a820 */
  *lpFadeFlag = 3; /* Line 340, Address: 0x102a828 */

} /* Line 342, Address: 0x102a838 */

static int flashin_new(void) { /* Line 344, Address: 0x102a850 */

  int_flg = 18; /* Line 346, Address: 0x102a858 */

  flashin1(); /* Line 348, Address: 0x102a864 */


  if (++FadeCount > 21) { /* Line 351, Address: 0x102a86c */
    FadeCount = 0; /* Line 352, Address: 0x102a88c */
    return 1; /* Line 353, Address: 0x102a894 */
  }
  return 0; /* Line 355, Address: 0x102a8a0 */
} /* Line 356, Address: 0x102a8a4 */

static void flashin1(void) { /* Line 358, Address: 0x102a8c0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 362, Address: 0x102a8d4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 363, Address: 0x102a908 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 365, Address: 0x102a93c */
    flashin2(lpPe, lpPe2); /* Line 366, Address: 0x102a948 */
    ++lpPe; /* Line 367, Address: 0x102a958 */
    ++lpPe2; /* Line 368, Address: 0x102a95c */
  } /* Line 369, Address: 0x102a960 */
  if (stageno.b.h == 1) return; /* Line 370, Address: 0x102a97c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 372, Address: 0x102a998 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 373, Address: 0x102a9cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 375, Address: 0x102aa00 */
    flashin2(lpPe, lpPe2); /* Line 376, Address: 0x102aa0c */
    ++lpPe; /* Line 377, Address: 0x102aa1c */
    ++lpPe2; /* Line 378, Address: 0x102aa20 */
  } /* Line 379, Address: 0x102aa24 */



} /* Line 383, Address: 0x102aa40 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 387, Address: 0x102aa60 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 388, Address: 0x102aa6c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 391, Address: 0x102aacc */
      lpPeDest->peBlue -= 32; /* Line 392, Address: 0x102aaf0 */
    } /* Line 393, Address: 0x102ab00 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 394, Address: 0x102ab08 */
      lpPeDest->peGreen -= 32; /* Line 395, Address: 0x102ab2c */
    } /* Line 396, Address: 0x102ab3c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 397, Address: 0x102ab44 */
      lpPeDest->peRed -= 32; /* Line 398, Address: 0x102ab68 */
    }
  }

} /* Line 402, Address: 0x102ab7c */


void flashout(void) {
  startcolor = 0; /* Line 406, Address: 0x102ab90 */
  colorcnt = 63; /* Line 407, Address: 0x102ab98 */

  FadeCount = 0; /* Line 409, Address: 0x102aba4 */
  *lpFadeFlag = 4; /* Line 410, Address: 0x102abac */

} /* Line 412, Address: 0x102abbc */

static int flashout_new(void) { /* Line 414, Address: 0x102abd0 */

  int_flg = 18; /* Line 416, Address: 0x102abd8 */

  flashout1(); /* Line 418, Address: 0x102abe4 */


  if (++FadeCount > 21) { /* Line 421, Address: 0x102abec */
    FadeCount = 0; /* Line 422, Address: 0x102ac0c */
    return 1; /* Line 423, Address: 0x102ac14 */
  }
  return 0; /* Line 425, Address: 0x102ac20 */
} /* Line 426, Address: 0x102ac24 */


static void flashout1(void) { /* Line 429, Address: 0x102ac40 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 433, Address: 0x102ac50 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 435, Address: 0x102ac84 */
    flashout2(lpPe); /* Line 436, Address: 0x102ac90 */
    ++lpPe; /* Line 437, Address: 0x102ac9c */
  } /* Line 438, Address: 0x102aca0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 439, Address: 0x102acbc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 441, Address: 0x102acf0 */
    flashout2(lpPe); /* Line 442, Address: 0x102acfc */
    ++lpPe; /* Line 443, Address: 0x102ad08 */
  } /* Line 444, Address: 0x102ad0c */


} /* Line 447, Address: 0x102ad28 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 450, Address: 0x102ad40 */
  if (lpPeDest->peRed != 224) { /* Line 451, Address: 0x102ad48 */
    lpPeDest->peRed += 32; /* Line 452, Address: 0x102ad60 */
  } /* Line 453, Address: 0x102ad74 */
  else if (lpPeDest->peGreen != 224) { /* Line 454, Address: 0x102ad7c */
    lpPeDest->peGreen += 32; /* Line 455, Address: 0x102ad94 */
  } /* Line 456, Address: 0x102ada4 */
  else if (lpPeDest->peBlue != 224) { /* Line 457, Address: 0x102adac */
    lpPeDest->peBlue += 32; /* Line 458, Address: 0x102adc4 */
  }


} /* Line 462, Address: 0x102add4 */


void colorset(int ColorNo) { /* Line 465, Address: 0x102ade0 */
  colorset00(ColorNo, 1); /* Line 466, Address: 0x102adec */
} /* Line 467, Address: 0x102adfc */

void colorset2(int ColorNo) { /* Line 469, Address: 0x102ae10 */
  colorset00(ColorNo, 0); /* Line 470, Address: 0x102ae1c */
} /* Line 471, Address: 0x102ae2c */

void colorset3(int ColorNo) { /* Line 473, Address: 0x102ae40 */
  colorset00(ColorNo, 0); /* Line 474, Address: 0x102ae4c */
} /* Line 475, Address: 0x102ae5c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 481, Address: 0x102ae70 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 486, Address: 0x102ae90 */
    case 0:
      lppe = lpcolorwk; break; /* Line 488, Address: 0x102aef8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 490, Address: 0x102af08 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 492, Address: 0x102af18 */
    default:
      lppe = lpcolorwk4; break; /* Line 494, Address: 0x102af28 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 497, Address: 0x102af30 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 498, Address: 0x102af48 */
  n = colortbl[ColorNo].cnt; /* Line 499, Address: 0x102af70 */
  for (i = 0; i < n; ++i) { /* Line 500, Address: 0x102af90 */
    *lpPeDest++ = *lpPeSrc++; /* Line 501, Address: 0x102af9c */
  } /* Line 502, Address: 0x102afcc */

} /* Line 504, Address: 0x102afdc */




int FadeProc(void) { /* Line 509, Address: 0x102b000 */
  switch (*lpFadeFlag) { /* Line 510, Address: 0x102b008 */
    case 1:
      return fadein0_new(); /* Line 512, Address: 0x102b04c */
    case 2:
      return fadeout_new(); /* Line 514, Address: 0x102b05c */
    case 3:
      return flashin_new(); /* Line 516, Address: 0x102b06c */
    case 4:
      return flashout_new(); /* Line 518, Address: 0x102b07c */
  }
  return 1; /* Line 520, Address: 0x102b08c */

} /* Line 522, Address: 0x102b090 */
