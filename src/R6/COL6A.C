#include "..\EQU.H"
#include "COL6A.H"

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
static void colorset00(int ColorNo, int WorkOffs);

palette_entry zone3colora[48] = {
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
palette_entry col6a0col[3] = { { 224, 224,   0, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col6a1cnt[8] = { 34, 3, 1, 0, 1, 1, 1, 2 };
palette_entry col6a1col[3] = { { 224,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224,   0, 1 } };
unsigned char col6a2cnt[8] = { 35, 3, 1, 0, 1, 1, 1, 2 };
palette_entry col6a2col[3] = { {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, { 224,   0,   0, 1 } };
unsigned char col6a3cnt[184] = {
  49, 91, 1, 1, 1, 0, 1, 2, 1, 0,
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
  1, 0, 1, 1, 1, 0, 1, 2, 1, 0,
  1, 3, 1, 0, 1, 1, 1, 0, 1, 2,
  1, 0, 1, 3, 1, 0, 1, 1, 1, 0,
  1, 2, 1, 0, 1, 3, 1, 0, 1, 1,
  1, 0, 1, 2, 1, 0, 1, 3, 1, 0,
  1, 1, 1, 0, 1, 2, 1, 0, 1, 3,
  1, 0, 30, 1
};
palette_entry col6a3col[4] = { {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 } };
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
palette_entry zone8colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 128, 192, 224, 1 }, { 224, 160,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 160,  96,   0, 1 }, {  64,  32,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,  64, 1 }, {  96,   0, 224, 1 }, { 128,  96, 224, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, { 160,   0,   0, 1 }, {  32,   0,   0, 1 }, {  64,   0,  64, 1 },
  {  64,  32, 160, 1 }, {  64, 128, 160, 1 }, { 224, 224, 224, 1 }, {   0,  32,  32, 1 },
  {   0,  64,  32, 1 }, {   0,  96, 160, 1 }, {   0, 192, 224, 1 }, {   0, 224, 224, 1 }
};
palette_entry zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, { 128, 128, 128, 1 },
  {   0,  64, 224, 1 }, {   0,   0, 128, 1 }, { 224, 224, 224, 1 }, {  64,  96, 224, 1 },
  {  96,   0,   0, 1 }, { 224, 128, 224, 1 }, { 224, 128,   0, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 128, 192, 224, 1 }, { 224, 160,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 160,  96,   0, 1 }, {  64,  32,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,  64, 1 }, {  96,  32, 224, 1 }, { 128,  96, 224, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, { 160,   0,   0, 1 }, {  32,   0,   0, 1 }, {  64,   0,  64, 1 },
  {  64,  32, 160, 1 }, {  64, 128, 160, 1 }, { 224, 224, 224, 1 }, {   0,  32,  32, 1 },
  {   0,  64,  32, 1 }, {   0,  96, 160, 1 }, {   0, 192, 224, 1 }, {   0, 224, 224, 1 }
};
palette_part colortbl[6] = {
  { advacolor,    0, 64 }, { advacolor,     0, 64 }, { advacolor2, 0, 64 }, { gamecolor, 0, 16 },
  { zone8colora, 16, 48 }, { zone82colora, 16, 48 }
};
static int FadeCount;





void clchgctr() { /* Line 139, Address: 0x1029f10 */
  colchg6a(); /* Line 140, Address: 0x1029f18 */
} /* Line 141, Address: 0x1029f20 */

void colchg6a() { /* Line 143, Address: 0x1029f30 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col6a0cnt, col6a0col); /* Line 144, Address: 0x1029f38 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col6a1cnt, col6a1col); /* Line 145, Address: 0x1029f60 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col6a2cnt, col6a2col); /* Line 146, Address: 0x1029f88 */
  clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col); /* Line 147, Address: 0x1029fb0 */

} /* Line 149, Address: 0x1029fd8 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 159, Address: 0x1029ff0 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 162, Address: 0x102a008 */
  if ((char)*pChgTime < 0) { /* Line 163, Address: 0x102a01c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 165, Address: 0x102a03c */
    ++*pChgCnt; /* Line 166, Address: 0x102a060 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 167, Address: 0x102a074 */

      *pChgCnt = 0; /* Line 169, Address: 0x102a0a0 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 172, Address: 0x102a0a8 */
    *pChgTime = pCntTbl[0]; /* Line 173, Address: 0x102a0c4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 174, Address: 0x102a0d4 */
  }





} /* Line 181, Address: 0x102a10c */


void fadein0() { /* Line 184, Address: 0x102a120 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 188, Address: 0x102a12c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 190, Address: 0x102a160 */
    lpPe->peRed = 0; /* Line 191, Address: 0x102a16c */
    lpPe->peGreen = 0; /* Line 192, Address: 0x102a170 */
    lpPe->peBlue = 0; /* Line 193, Address: 0x102a174 */
    lpPe->peFlags = 1; /* Line 194, Address: 0x102a178 */
    ++lpPe; /* Line 195, Address: 0x102a180 */
  } /* Line 196, Address: 0x102a184 */
  FadeCount = 0; /* Line 197, Address: 0x102a1a0 */
  *lpFadeFlag = 1; /* Line 198, Address: 0x102a1a8 */

} /* Line 200, Address: 0x102a1b8 */



int fadein0_new() { /* Line 204, Address: 0x102a1d0 */

  int_flg = 18; /* Line 206, Address: 0x102a1d8 */

  fadein1(); /* Line 208, Address: 0x102a1e4 */


  if (++FadeCount > 21) { /* Line 211, Address: 0x102a1ec */
    FadeCount = 0; /* Line 212, Address: 0x102a20c */
    return 1; /* Line 213, Address: 0x102a214 */
  }
  return 0; /* Line 215, Address: 0x102a220 */
} /* Line 216, Address: 0x102a224 */



static void fadein1() { /* Line 220, Address: 0x102a240 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 224, Address: 0x102a254 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 225, Address: 0x102a288 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 227, Address: 0x102a2bc */
    fadein2(lpPe, lpPe2); /* Line 228, Address: 0x102a2c8 */
    ++lpPe; /* Line 229, Address: 0x102a2d8 */
    ++lpPe2; /* Line 230, Address: 0x102a2dc */
  } /* Line 231, Address: 0x102a2e0 */
  if (stageno.b.h == 1) return; /* Line 232, Address: 0x102a2fc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 234, Address: 0x102a318 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 235, Address: 0x102a34c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 237, Address: 0x102a380 */
    fadein2(lpPe, lpPe2); /* Line 238, Address: 0x102a38c */
    ++lpPe; /* Line 239, Address: 0x102a39c */
    ++lpPe2; /* Line 240, Address: 0x102a3a0 */
  } /* Line 241, Address: 0x102a3a4 */



} /* Line 245, Address: 0x102a3c0 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 249, Address: 0x102a3e0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 250, Address: 0x102a3ec */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 253, Address: 0x102a44c */
      lpPeDest->peBlue += 32; /* Line 254, Address: 0x102a470 */
    } /* Line 255, Address: 0x102a480 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 256, Address: 0x102a488 */
      lpPeDest->peGreen += 32; /* Line 257, Address: 0x102a4ac */
    } /* Line 258, Address: 0x102a4bc */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 259, Address: 0x102a4c4 */
      lpPeDest->peRed += 32; /* Line 260, Address: 0x102a4e8 */
    }
  }

} /* Line 264, Address: 0x102a4fc */


void fadeout() {
  startcolor = 0; /* Line 268, Address: 0x102a510 */
  colorcnt = 63; /* Line 269, Address: 0x102a518 */

  FadeCount = 0; /* Line 271, Address: 0x102a524 */
  *lpFadeFlag = 2; /* Line 272, Address: 0x102a52c */

} /* Line 274, Address: 0x102a53c */



static int fadeout_new() { /* Line 278, Address: 0x102a550 */

  int_flg = 18; /* Line 280, Address: 0x102a558 */

  fadeout1(); /* Line 282, Address: 0x102a564 */


  if (++FadeCount > 21) { /* Line 285, Address: 0x102a56c */
    FadeCount = 0; /* Line 286, Address: 0x102a58c */
    return 1; /* Line 287, Address: 0x102a594 */
  }
  return 0; /* Line 289, Address: 0x102a5a0 */
} /* Line 290, Address: 0x102a5a4 */


static void fadeout1() { /* Line 293, Address: 0x102a5c0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 297, Address: 0x102a5d0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 299, Address: 0x102a604 */
    fadeout2(lpPe); /* Line 300, Address: 0x102a610 */
    ++lpPe; /* Line 301, Address: 0x102a61c */
  } /* Line 302, Address: 0x102a620 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 303, Address: 0x102a63c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 305, Address: 0x102a670 */
    fadeout2(lpPe); /* Line 306, Address: 0x102a67c */
    ++lpPe; /* Line 307, Address: 0x102a688 */
  } /* Line 308, Address: 0x102a68c */


} /* Line 311, Address: 0x102a6a8 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 314, Address: 0x102a6c0 */
  if (lpPeDest->peRed) { /* Line 315, Address: 0x102a6c8 */
    lpPeDest->peRed -= 32; /* Line 316, Address: 0x102a6d8 */
  } /* Line 317, Address: 0x102a6ec */
  else if (lpPeDest->peGreen) { /* Line 318, Address: 0x102a6f4 */
    lpPeDest->peGreen -= 32; /* Line 319, Address: 0x102a704 */
  } /* Line 320, Address: 0x102a714 */
  else if (lpPeDest->peBlue) { /* Line 321, Address: 0x102a71c */
    lpPeDest->peBlue -= 32; /* Line 322, Address: 0x102a72c */
  }

} /* Line 325, Address: 0x102a73c */




void flashin() { /* Line 330, Address: 0x102a750 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 334, Address: 0x102a75c */
  colorcnt = 63; /* Line 335, Address: 0x102a764 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 337, Address: 0x102a770 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 339, Address: 0x102a7a4 */
    lpPe->peRed = 224; /* Line 340, Address: 0x102a7b0 */
    lpPe->peGreen = 224; /* Line 341, Address: 0x102a7b8 */
    lpPe->peBlue = 224; /* Line 342, Address: 0x102a7c0 */
    lpPe->peFlags = 1; /* Line 343, Address: 0x102a7c8 */
    ++lpPe; /* Line 344, Address: 0x102a7d0 */
  } /* Line 345, Address: 0x102a7d4 */
  FadeCount = 0; /* Line 346, Address: 0x102a7f0 */
  *lpFadeFlag = 3; /* Line 347, Address: 0x102a7f8 */

} /* Line 349, Address: 0x102a808 */

static int flashin_new() { /* Line 351, Address: 0x102a820 */

  int_flg = 18; /* Line 353, Address: 0x102a828 */

  flashin1(); /* Line 355, Address: 0x102a834 */


  if (++FadeCount > 21) { /* Line 358, Address: 0x102a83c */
    FadeCount = 0; /* Line 359, Address: 0x102a85c */
    return 1; /* Line 360, Address: 0x102a864 */
  }
  return 0; /* Line 362, Address: 0x102a870 */
} /* Line 363, Address: 0x102a874 */

static void flashin1() { /* Line 365, Address: 0x102a890 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 369, Address: 0x102a8a4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 370, Address: 0x102a8d8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 372, Address: 0x102a90c */
    flashin2(lpPe, lpPe2); /* Line 373, Address: 0x102a918 */
    ++lpPe; /* Line 374, Address: 0x102a928 */
    ++lpPe2; /* Line 375, Address: 0x102a92c */
  } /* Line 376, Address: 0x102a930 */
  if (stageno.b.h == 1) return; /* Line 377, Address: 0x102a94c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 379, Address: 0x102a968 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 380, Address: 0x102a99c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 382, Address: 0x102a9d0 */
    flashin2(lpPe, lpPe2); /* Line 383, Address: 0x102a9dc */
    ++lpPe; /* Line 384, Address: 0x102a9ec */
    ++lpPe2; /* Line 385, Address: 0x102a9f0 */
  } /* Line 386, Address: 0x102a9f4 */



} /* Line 390, Address: 0x102aa10 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 394, Address: 0x102aa30 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 395, Address: 0x102aa3c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 398, Address: 0x102aa9c */
      lpPeDest->peBlue -= 32; /* Line 399, Address: 0x102aac0 */
    } /* Line 400, Address: 0x102aad0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 401, Address: 0x102aad8 */
      lpPeDest->peGreen -= 32; /* Line 402, Address: 0x102aafc */
    } /* Line 403, Address: 0x102ab0c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 404, Address: 0x102ab14 */
      lpPeDest->peRed -= 32; /* Line 405, Address: 0x102ab38 */
    }
  }

} /* Line 409, Address: 0x102ab4c */


void flashout() {
  startcolor = 0; /* Line 413, Address: 0x102ab60 */
  colorcnt = 63; /* Line 414, Address: 0x102ab68 */

  FadeCount = 0; /* Line 416, Address: 0x102ab74 */
  *lpFadeFlag = 4; /* Line 417, Address: 0x102ab7c */

} /* Line 419, Address: 0x102ab8c */

static int flashout_new() { /* Line 421, Address: 0x102aba0 */

  int_flg = 18; /* Line 423, Address: 0x102aba8 */

  flashout1(); /* Line 425, Address: 0x102abb4 */


  if (++FadeCount > 21) { /* Line 428, Address: 0x102abbc */
    FadeCount = 0; /* Line 429, Address: 0x102abdc */
    return 1; /* Line 430, Address: 0x102abe4 */
  }
  return 0; /* Line 432, Address: 0x102abf0 */
} /* Line 433, Address: 0x102abf4 */


static void flashout1() { /* Line 436, Address: 0x102ac10 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 440, Address: 0x102ac20 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 442, Address: 0x102ac54 */
    flashout2(lpPe); /* Line 443, Address: 0x102ac60 */
    ++lpPe; /* Line 444, Address: 0x102ac6c */
  } /* Line 445, Address: 0x102ac70 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 446, Address: 0x102ac8c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 448, Address: 0x102acc0 */
    flashout2(lpPe); /* Line 449, Address: 0x102accc */
    ++lpPe; /* Line 450, Address: 0x102acd8 */
  } /* Line 451, Address: 0x102acdc */


} /* Line 454, Address: 0x102acf8 */


static void flashout2(palette_entry* lpPeDest) { /* Line 457, Address: 0x102ad10 */
  if (lpPeDest->peRed != 224) { /* Line 458, Address: 0x102ad18 */
    lpPeDest->peRed += 32; /* Line 459, Address: 0x102ad30 */
  } /* Line 460, Address: 0x102ad44 */
  else if (lpPeDest->peGreen != 224) { /* Line 461, Address: 0x102ad4c */
    lpPeDest->peGreen += 32; /* Line 462, Address: 0x102ad64 */
  } /* Line 463, Address: 0x102ad74 */
  else if (lpPeDest->peBlue != 224) { /* Line 464, Address: 0x102ad7c */
    lpPeDest->peBlue += 32; /* Line 465, Address: 0x102ad94 */
  }


} /* Line 469, Address: 0x102ada4 */


void colorset(int ColorNo) { /* Line 472, Address: 0x102adb0 */
  colorset00(ColorNo, 1); /* Line 473, Address: 0x102adbc */
} /* Line 474, Address: 0x102adcc */

void colorset2(int ColorNo) { /* Line 476, Address: 0x102ade0 */
  colorset00(ColorNo, 0); /* Line 477, Address: 0x102adec */
} /* Line 478, Address: 0x102adfc */

void colorset3(int ColorNo) { /* Line 480, Address: 0x102ae10 */
  colorset00(ColorNo, 0); /* Line 481, Address: 0x102ae1c */
} /* Line 482, Address: 0x102ae2c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 488, Address: 0x102ae40 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 493, Address: 0x102ae60 */
    case 0:
      lppe = lpcolorwk; break; /* Line 495, Address: 0x102aec8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 497, Address: 0x102aed8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 499, Address: 0x102aee8 */
    default:
      lppe = lpcolorwk4; break; /* Line 501, Address: 0x102aef8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 504, Address: 0x102af00 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 505, Address: 0x102af18 */
  n = colortbl[ColorNo].cnt; /* Line 506, Address: 0x102af40 */
  for (i = 0; i < n; ++i) { /* Line 507, Address: 0x102af60 */
    *lpPeDest++ = *lpPeSrc++; /* Line 508, Address: 0x102af6c */
  } /* Line 509, Address: 0x102af9c */

} /* Line 511, Address: 0x102afac */




int FadeProc() { /* Line 516, Address: 0x102afd0 */
  switch (*lpFadeFlag) { /* Line 517, Address: 0x102afd8 */
    case 1:
      return fadein0_new(); /* Line 519, Address: 0x102b01c */
    case 2:
      return fadeout_new(); /* Line 521, Address: 0x102b02c */
    case 3:
      return flashin_new(); /* Line 523, Address: 0x102b03c */
    case 4:
      return flashout_new(); /* Line 525, Address: 0x102b04c */
  }
  return 1; /* Line 527, Address: 0x102b05c */

} /* Line 529, Address: 0x102b060 */
