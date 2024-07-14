#include "..\EQU.H"
#include "COL8A.H"

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

unsigned char col8a0cnt[8] = { 38, 3, 4, 0, 4, 1, 4, 2 };
PALETTEENTRY col8a0col[3] = {
  {  64,   0,  64, 1 }, { 128,   0, 128, 1 }, { 224,   0, 224, 1 }
};
unsigned char col8a1cnt[8] = { 39, 3, 4, 0, 4, 1, 4, 2 };
PALETTEENTRY col8a1col[3] = {
  { 224,   0, 224, 1 }, {  64,   0,  64, 1 }, { 128,   0, 128, 1 }
};
unsigned char col8a2cnt[8] = { 40, 3, 4, 0, 4, 1, 4, 2 };
PALETTEENTRY col8a2col[3] = {
  { 128,   0, 128, 1 }, { 224,   0, 224, 1 }, {  64,   0,  64, 1 }
};
unsigned char col8a3cnt[26] = { 49, 12, 3, 0, 3, 1, 3, 0, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 60, 1 };
PALETTEENTRY col8a3col[2] = {
  {   0,  96, 224, 1 }, {   0,   0,   0, 1 }
};
unsigned char col8a4cnt[26] = { 50, 12, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 1, 3, 0, 3, 0, 3, 0, 3, 0, 60, 0 };
PALETTEENTRY col8a4col[2] = {
  {   0,   0,   0, 1 }, {   0,  96, 224, 1 }
};
unsigned char col8a5cnt[26] = { 51, 12, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 1, 60, 0 };
PALETTEENTRY col8a5col[2] = {
  {   0,   0,   0, 1 }, {   0,  96, 224, 1 }
};
unsigned char col8a6cnt[20] = { 49, 9, 10, 0, 10, 1, 10, 2, 10, 3, 10, 4, 10, 3, 10, 2, 10, 1, 10, 0 };
PALETTEENTRY col8a6col[5] = {
  {   0, 224,   0, 1 }, {   0, 160,   0, 1 }, {   0,  96,   0, 1 }, {   0,  32,   0, 1 }, {   0,   0,   0, 1 }
};
unsigned char col8a7cnt[20] = { 50, 9, 10, 0, 10, 1, 10, 2, 10, 3, 10, 4, 10, 3, 10, 2, 10, 1, 10, 0 };
PALETTEENTRY col8a7col[5] = {
  { 224, 160,   0, 1 }, { 224,  96,   0, 1 }, { 224,   0,   0, 1 }, {  96,   0,   0, 1 }, {   0,   0,   0, 1 }
};
unsigned char col8a8cnt[8] = { 51, 3, 5, 0, 5, 1, 5, 2 };
PALETTEENTRY col8a8col[3] = {
  { 224, 224,   0, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 }
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
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone8colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32,  32, 1 }, {  64,  64,  64, 1 },
  { 128, 128, 128, 1 }, { 224, 224, 224, 1 }, { 224,   0, 224, 1 }, { 128,   0, 128, 1 },
  {  64,   0,  64, 1 }, {  64,  32,   0, 1 }, { 160,  96,   0, 1 }, { 224, 160,   0, 1 },
  {   0,  32,  32, 1 }, {   0,  96,  64, 1 }, {   0, 160, 128, 1 }, {   0, 224, 224, 1 },
  {  32,   0,   0, 1 }, {   0,  96, 224, 1 }, {   0,   0, 192, 1 }, {   0,   0, 128, 1 },
  {   0,  32,   0, 1 }, {   0, 128,   0, 1 }, {   0, 224,   0, 1 }, {   0,   0,  32, 1 },
  {  32,   0,  64, 1 }, {  64,   0, 128, 1 }, {  96,   0, 192, 1 }, {   0,   0,   0, 1 },
  {  64,   0,   0, 1 }, { 128,   0,   0, 1 }, { 224,   0,   0, 1 }, { 224,  96,   0, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32,  32, 1 }, {  64,  64,  64, 1 },
  { 128, 128, 128, 1 }, { 224, 224, 224, 1 }, { 224,   0, 224, 1 }, { 128,   0, 128, 1 },
  {  64,   0,  64, 1 }, {  64,  32,   0, 1 }, { 160,  96,   0, 1 }, { 224, 160,   0, 1 },
  {   0,  32,  32, 1 }, {   0,  96,  64, 1 }, {   0, 160, 128, 1 }, {   0, 224, 224, 1 },
  {   0,   0,   0, 1 }, {   0, 192,   0, 1 }, { 224,  96,   0, 1 }, { 224, 224,   0, 1 },
  {   0,  32,  32, 1 }, {   0,  96,  64, 1 }, {  64, 160,  96, 1 }, {   0, 160, 128, 1 },
  {   0,   0,  32, 1 }, {   0,   0,  64, 1 }, {   0,  32, 128, 1 }, {   0,  64, 224, 1 },
  {  32,   0,  32, 1 }, {  64,   0,  64, 1 }, {  96,   0, 128, 1 }, { 192,   0, 224, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone8colora, 16, 48 },
  { zone8colora, 16, 48 }
};
static int FadeCount;





















void clchgctr() { /* Line 153, Address: 0x101acd0 */
  colchg8a(); /* Line 154, Address: 0x101acd8 */
} /* Line 155, Address: 0x101ace0 */

void colchg8a() { /* Line 157, Address: 0x101acf0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col8a0cnt, col8a0col); /* Line 158, Address: 0x101acf8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col8a1cnt, col8a1col); /* Line 159, Address: 0x101ad20 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col8a2cnt, col8a2col); /* Line 160, Address: 0x101ad48 */
  if (stageno.b.l != 1) { /* Line 161, Address: 0x101ad70 */

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a3cnt, col8a3col); /* Line 163, Address: 0x101ad8c */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a4cnt, col8a4col); /* Line 164, Address: 0x101adb4 */
    clchg_sub0(&clchgtim[5], &clchgcnt[5], col8a5cnt, col8a5col); /* Line 165, Address: 0x101addc */
  } /* Line 166, Address: 0x101ae04 */
  else {

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a6cnt, col8a6col); /* Line 169, Address: 0x101ae0c */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a7cnt, col8a7col); /* Line 170, Address: 0x101ae34 */
    clchg_sub0(&clchgtim[5], &clchgcnt[5], col8a8cnt, col8a8col); /* Line 171, Address: 0x101ae5c */
  }

} /* Line 174, Address: 0x101ae84 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 183, Address: 0x101aea0 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 186, Address: 0x101aeb8 */
  if ((char)*pChgTime < 0) { /* Line 187, Address: 0x101aecc */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 189, Address: 0x101aeec */
    ++*pChgCnt; /* Line 190, Address: 0x101af10 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 191, Address: 0x101af24 */

      *pChgCnt = 0; /* Line 193, Address: 0x101af50 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 196, Address: 0x101af58 */
    *pChgTime = pCntTbl[0]; /* Line 197, Address: 0x101af74 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 198, Address: 0x101af84 */
  }





} /* Line 205, Address: 0x101afbc */


void fadein0() { /* Line 208, Address: 0x101afd0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 212, Address: 0x101afdc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 214, Address: 0x101b010 */
    lpPe->peRed = 0; /* Line 215, Address: 0x101b01c */
    lpPe->peGreen = 0; /* Line 216, Address: 0x101b020 */
    lpPe->peBlue = 0; /* Line 217, Address: 0x101b024 */
    lpPe->peFlags = 1; /* Line 218, Address: 0x101b028 */
    ++lpPe; /* Line 219, Address: 0x101b030 */
  } /* Line 220, Address: 0x101b034 */
  FadeCount = 0; /* Line 221, Address: 0x101b050 */
  *lpFadeFlag = 1; /* Line 222, Address: 0x101b058 */

} /* Line 224, Address: 0x101b068 */



int fadein0_new() { /* Line 228, Address: 0x101b080 */

  int_flg = 18; /* Line 230, Address: 0x101b088 */

  fadein1(); /* Line 232, Address: 0x101b094 */


  if (++FadeCount > 21) { /* Line 235, Address: 0x101b09c */
    FadeCount = 0; /* Line 236, Address: 0x101b0bc */
    return 1; /* Line 237, Address: 0x101b0c4 */
  }
  return 0; /* Line 239, Address: 0x101b0d0 */
} /* Line 240, Address: 0x101b0d4 */



static void fadein1() { /* Line 244, Address: 0x101b0f0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 248, Address: 0x101b104 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 249, Address: 0x101b138 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 251, Address: 0x101b16c */
    fadein2(lpPe, lpPe2); /* Line 252, Address: 0x101b178 */
    ++lpPe; /* Line 253, Address: 0x101b188 */
    ++lpPe2; /* Line 254, Address: 0x101b18c */
  } /* Line 255, Address: 0x101b190 */
  if (stageno.b.h == 1) return; /* Line 256, Address: 0x101b1ac */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 258, Address: 0x101b1c8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 259, Address: 0x101b1fc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 261, Address: 0x101b230 */
    fadein2(lpPe, lpPe2); /* Line 262, Address: 0x101b23c */
    ++lpPe; /* Line 263, Address: 0x101b24c */
    ++lpPe2; /* Line 264, Address: 0x101b250 */
  } /* Line 265, Address: 0x101b254 */



} /* Line 269, Address: 0x101b270 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 273, Address: 0x101b290 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 274, Address: 0x101b29c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 277, Address: 0x101b2fc */
      lpPeDest->peBlue += 32; /* Line 278, Address: 0x101b320 */
    } /* Line 279, Address: 0x101b330 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 280, Address: 0x101b338 */
      lpPeDest->peGreen += 32; /* Line 281, Address: 0x101b35c */
    } /* Line 282, Address: 0x101b36c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 283, Address: 0x101b374 */
      lpPeDest->peRed += 32; /* Line 284, Address: 0x101b398 */
    }
  }

} /* Line 288, Address: 0x101b3ac */


void fadeout() {
  startcolor = 0; /* Line 292, Address: 0x101b3c0 */
  colorcnt = 63; /* Line 293, Address: 0x101b3c8 */

  FadeCount = 0; /* Line 295, Address: 0x101b3d4 */
  *lpFadeFlag = 2; /* Line 296, Address: 0x101b3dc */

} /* Line 298, Address: 0x101b3ec */



static int fadeout_new() { /* Line 302, Address: 0x101b400 */

  int_flg = 18; /* Line 304, Address: 0x101b408 */

  fadeout1(); /* Line 306, Address: 0x101b414 */


  if (++FadeCount > 21) { /* Line 309, Address: 0x101b41c */
    FadeCount = 0; /* Line 310, Address: 0x101b43c */
    return 1; /* Line 311, Address: 0x101b444 */
  }
  return 0; /* Line 313, Address: 0x101b450 */
} /* Line 314, Address: 0x101b454 */


static void fadeout1() { /* Line 317, Address: 0x101b470 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 321, Address: 0x101b480 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 323, Address: 0x101b4b4 */
    fadeout2(lpPe); /* Line 324, Address: 0x101b4c0 */
    ++lpPe; /* Line 325, Address: 0x101b4cc */
  } /* Line 326, Address: 0x101b4d0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 327, Address: 0x101b4ec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 329, Address: 0x101b520 */
    fadeout2(lpPe); /* Line 330, Address: 0x101b52c */
    ++lpPe; /* Line 331, Address: 0x101b538 */
  } /* Line 332, Address: 0x101b53c */


} /* Line 335, Address: 0x101b558 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 338, Address: 0x101b570 */
  if (lpPeDest->peRed) { /* Line 339, Address: 0x101b578 */
    lpPeDest->peRed -= 32; /* Line 340, Address: 0x101b588 */
  } /* Line 341, Address: 0x101b59c */
  else if (lpPeDest->peGreen) { /* Line 342, Address: 0x101b5a4 */
    lpPeDest->peGreen -= 32; /* Line 343, Address: 0x101b5b4 */
  } /* Line 344, Address: 0x101b5c4 */
  else if (lpPeDest->peBlue) { /* Line 345, Address: 0x101b5cc */
    lpPeDest->peBlue -= 32; /* Line 346, Address: 0x101b5dc */
  }

} /* Line 349, Address: 0x101b5ec */




void flashin() { /* Line 354, Address: 0x101b600 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 358, Address: 0x101b60c */
  colorcnt = 63; /* Line 359, Address: 0x101b614 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 361, Address: 0x101b620 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 363, Address: 0x101b654 */
    lpPe->peRed = 224; /* Line 364, Address: 0x101b660 */
    lpPe->peGreen = 224; /* Line 365, Address: 0x101b668 */
    lpPe->peBlue = 224; /* Line 366, Address: 0x101b670 */
    lpPe->peFlags = 1; /* Line 367, Address: 0x101b678 */
    ++lpPe; /* Line 368, Address: 0x101b680 */
  } /* Line 369, Address: 0x101b684 */
  FadeCount = 0; /* Line 370, Address: 0x101b6a0 */
  *lpFadeFlag = 3; /* Line 371, Address: 0x101b6a8 */

} /* Line 373, Address: 0x101b6b8 */

static int flashin_new() { /* Line 375, Address: 0x101b6d0 */

  int_flg = 18; /* Line 377, Address: 0x101b6d8 */

  flashin1(); /* Line 379, Address: 0x101b6e4 */


  if (++FadeCount > 21) { /* Line 382, Address: 0x101b6ec */
    FadeCount = 0; /* Line 383, Address: 0x101b70c */
    return 1; /* Line 384, Address: 0x101b714 */
  }
  return 0; /* Line 386, Address: 0x101b720 */
} /* Line 387, Address: 0x101b724 */

static void flashin1() { /* Line 389, Address: 0x101b740 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 393, Address: 0x101b754 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 394, Address: 0x101b788 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 396, Address: 0x101b7bc */
    flashin2(lpPe, lpPe2); /* Line 397, Address: 0x101b7c8 */
    ++lpPe; /* Line 398, Address: 0x101b7d8 */
    ++lpPe2; /* Line 399, Address: 0x101b7dc */
  } /* Line 400, Address: 0x101b7e0 */
  if (stageno.b.h == 1) return; /* Line 401, Address: 0x101b7fc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 403, Address: 0x101b818 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 404, Address: 0x101b84c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 406, Address: 0x101b880 */
    flashin2(lpPe, lpPe2); /* Line 407, Address: 0x101b88c */
    ++lpPe; /* Line 408, Address: 0x101b89c */
    ++lpPe2; /* Line 409, Address: 0x101b8a0 */
  } /* Line 410, Address: 0x101b8a4 */



} /* Line 414, Address: 0x101b8c0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 418, Address: 0x101b8e0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 419, Address: 0x101b8ec */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 422, Address: 0x101b94c */
      lpPeDest->peBlue -= 32; /* Line 423, Address: 0x101b970 */
    } /* Line 424, Address: 0x101b980 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 425, Address: 0x101b988 */
      lpPeDest->peGreen -= 32; /* Line 426, Address: 0x101b9ac */
    } /* Line 427, Address: 0x101b9bc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 428, Address: 0x101b9c4 */
      lpPeDest->peRed -= 32; /* Line 429, Address: 0x101b9e8 */
    }
  }

} /* Line 433, Address: 0x101b9fc */


void flashout() {
  startcolor = 0; /* Line 437, Address: 0x101ba10 */
  colorcnt = 63; /* Line 438, Address: 0x101ba18 */

  FadeCount = 0; /* Line 440, Address: 0x101ba24 */
  *lpFadeFlag = 4; /* Line 441, Address: 0x101ba2c */

} /* Line 443, Address: 0x101ba3c */

static int flashout_new() { /* Line 445, Address: 0x101ba50 */

  int_flg = 18; /* Line 447, Address: 0x101ba58 */

  flashout1(); /* Line 449, Address: 0x101ba64 */


  if (++FadeCount > 21) { /* Line 452, Address: 0x101ba6c */
    FadeCount = 0; /* Line 453, Address: 0x101ba8c */
    return 1; /* Line 454, Address: 0x101ba94 */
  }
  return 0; /* Line 456, Address: 0x101baa0 */
} /* Line 457, Address: 0x101baa4 */


static void flashout1() { /* Line 460, Address: 0x101bac0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 464, Address: 0x101bad0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 466, Address: 0x101bb04 */
    flashout2(lpPe); /* Line 467, Address: 0x101bb10 */
    ++lpPe; /* Line 468, Address: 0x101bb1c */
  } /* Line 469, Address: 0x101bb20 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 470, Address: 0x101bb3c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 472, Address: 0x101bb70 */
    flashout2(lpPe); /* Line 473, Address: 0x101bb7c */
    ++lpPe; /* Line 474, Address: 0x101bb88 */
  } /* Line 475, Address: 0x101bb8c */


} /* Line 478, Address: 0x101bba8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 481, Address: 0x101bbc0 */
  if (lpPeDest->peRed != 224) { /* Line 482, Address: 0x101bbc8 */
    lpPeDest->peRed += 32; /* Line 483, Address: 0x101bbe0 */
  } /* Line 484, Address: 0x101bbf4 */
  else if (lpPeDest->peGreen != 224) { /* Line 485, Address: 0x101bbfc */
    lpPeDest->peGreen += 32; /* Line 486, Address: 0x101bc14 */
  } /* Line 487, Address: 0x101bc24 */
  else if (lpPeDest->peBlue != 224) { /* Line 488, Address: 0x101bc2c */
    lpPeDest->peBlue += 32; /* Line 489, Address: 0x101bc44 */
  }


} /* Line 493, Address: 0x101bc54 */


void colorset(int ColorNo) { /* Line 496, Address: 0x101bc60 */
  colorset00(ColorNo, 1); /* Line 497, Address: 0x101bc6c */
} /* Line 498, Address: 0x101bc7c */

void colorset2(int ColorNo) { /* Line 500, Address: 0x101bc90 */
  colorset00(ColorNo, 0); /* Line 501, Address: 0x101bc9c */
} /* Line 502, Address: 0x101bcac */

void colorset3(int ColorNo) { /* Line 504, Address: 0x101bcc0 */
  colorset00(ColorNo, 0); /* Line 505, Address: 0x101bccc */
} /* Line 506, Address: 0x101bcdc */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 512, Address: 0x101bcf0 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 517, Address: 0x101bd10 */
    case 0:
      lppe = lpcolorwk; break; /* Line 519, Address: 0x101bd78 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 521, Address: 0x101bd88 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 523, Address: 0x101bd98 */
    default:
      lppe = lpcolorwk4; break; /* Line 525, Address: 0x101bda8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 528, Address: 0x101bdb0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 529, Address: 0x101bdc8 */
  n = colortbl[ColorNo].cnt; /* Line 530, Address: 0x101bdf0 */
  for (i = 0; i < n; ++i) { /* Line 531, Address: 0x101be10 */
    *lpPeDest++ = *lpPeSrc++; /* Line 532, Address: 0x101be1c */
  } /* Line 533, Address: 0x101be4c */

} /* Line 535, Address: 0x101be5c */




int FadeProc() { /* Line 540, Address: 0x101be80 */
  switch (*lpFadeFlag) { /* Line 541, Address: 0x101be88 */
    case 1:
      return fadein0_new(); /* Line 543, Address: 0x101becc */
    case 2:
      return fadeout_new(); /* Line 545, Address: 0x101bedc */
    case 3:
      return flashin_new(); /* Line 547, Address: 0x101beec */
    case 4:
      return flashout_new(); /* Line 549, Address: 0x101befc */
  }
  return 1; /* Line 551, Address: 0x101bf0c */

} /* Line 553, Address: 0x101bf10 */
