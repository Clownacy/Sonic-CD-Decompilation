#include "..\EQU.H"
#include "COL1A.H"

static int fadein0_new();
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
static void colorset3(int ColorNo);
static void colorset00(int ColorNo, int WorkOffs);

palette_entry clst1_1a0[3][4] = {
  { { 192, 192, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 }, { 128, 160, 224, 1 } },
  { { 128, 160, 224, 1 }, { 192, 192, 224, 1 }, { 192, 192, 224, 1 }, { 160, 192, 224, 1 } },
  { { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, { 160, 192, 224, 1 }, { 192, 192, 224, 1 } }
};
palette_entry clst1_1a1[12] = {
  { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96, 128, 224, 1 },
  { 128, 160, 224, 1 }, {  96, 128, 224, 1 }, {   0,  96, 192, 1 }, { 160, 192, 224, 1 },
  {  96, 128, 224, 1 }, { 160, 192, 224, 1 }, {   0,  96, 192, 1 }, { 128, 160, 224, 1 }
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
palette_entry zone1colora0[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  96, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  {  96,  96,  96, 1 }, {  64,  64,  64, 1 }, { 224,  96, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, {  96,  96,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0, 160, 1 }, { 224, 224,  96, 1 }, { 224,   0,  96, 1 }, {  64,   0,   0, 1 },
  { 224,  96,   0, 1 }, {   0,   0,   0, 1 }, { 192,  64,   0, 1 }, {  96,  32,   0, 1 },
  {  96, 224,  32, 1 }, {   0, 160,   0, 1 }, {   0,  96,   0, 1 }, {   0,  64,   0, 1 },
  { 160, 192, 224, 1 }, {  96, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96,  96, 224, 1 },
  {   0,   0, 160, 1 }, { 224, 224, 224, 1 }, { 160, 224, 224, 1 }, {  96, 192, 192, 1 },
  {  64,  96, 224, 1 }, { 224, 224,   0, 1 }, { 224,  96,   0, 1 }, { 160,  96,   0, 1 },
  {  64,  32,   0, 1 }, {   0,   0,   0, 1 }, { 192, 224, 224, 1 }, {  96, 192, 224, 1 },
  {  96,  96, 224, 1 }, {  32,  64,   0, 1 }, {  96, 160,   0, 1 }, {  64,  96,   0, 1 }
};
palette_entry zone1colora1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  32,  32, 160, 1 }, { 224, 224, 128, 1 }, { 224,   0, 224, 1 }, {  32,   0,   0, 1 },
  { 224, 160,   0, 1 }, {   0,   0,   0, 1 }, { 160,  64,   0, 1 }, {  96,  32,   0, 1 },
  { 128, 224,  32, 1 }, {   0, 160,   0, 1 }, {   0,  96,   0, 1 }, {   0,  64,   0, 1 },
  { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96, 128, 224, 1 },
  {  32,  32, 160, 1 }, {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 192, 192, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  { 128, 160, 224, 1 }, {   0,  96,   0, 1 }, {  64, 160,   0, 1 }, { 128, 224,   0, 1 },
  {  32,   0,  64, 1 }, {  96,  32,  32, 1 }, { 160,  96,   0, 1 }, { 224, 160,   0, 1 }
};
palette_entry zone1colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0, 160, 1 }, { 224, 224, 128, 1 }, { 224,   0, 128, 1 }, {  64,   0,   0, 1 },
  { 224, 128,   0, 1 }, {   0,   0,   0, 1 }, { 192,  64,   0, 1 }, {  96,  32,   0, 1 },
  { 128, 224,  32, 1 }, {   0, 160,   0, 1 }, {   0,  96,   0, 1 }, {   0,  64,   0, 1 },
  { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {   0,  96, 192, 1 }, {  96, 128, 224, 1 },
  {   0,   0, 160, 1 }, { 224, 224, 224, 1 }, { 160, 224, 224, 1 }, {  96, 192, 192, 1 },
  {  64,  96, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 }, { 160,  96,   0, 1 },
  {  64,  32,   0, 1 }, {   0,   0,   0, 1 }, { 192, 224, 224, 1 }, { 128, 192, 224, 1 },
  {  96, 128, 224, 1 }, {  32,  64,   0, 1 }, {  96, 160,   0, 1 }, {  64,  96,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 }, { advacolor,     0, 64 }, { advacolor2,    0, 64 },
  { gamecolor, 0, 16 }, { zone1colora1, 16, 48 }, { zone1colora0, 16, 48 }
};
unsigned char col1a0cnt[8] = { 49, 3, 8, 0, 8, 1, 8, 2 };
palette_entry col1a0col[3] = {
  { 224, 224, 224, 1 },
  {  96, 192, 192, 1 },
  { 160, 224, 224, 1 }
};
unsigned char col1a1cnt[8] = { 50, 3, 8, 0, 8, 1, 8, 2 };
palette_entry col1a1col[3] = {
  { 160, 224, 224, 1 },
  { 224, 224, 224, 1 },
  {  96, 192, 192, 1 }
};
unsigned char col1a2cnt[8] = { 51, 3, 8, 0, 8, 1, 8, 2 };
palette_entry col1a2col[3] = {
  {  96, 192, 192, 1 },
  { 160, 224, 224, 1 },
  { 224, 224, 224, 1 }
};
unsigned char col1a3cnt[8] = { 44, 3, 6, 0, 6, 1, 6, 2 };
palette_entry col1a3col[3] = {
  { 160, 192, 224, 1 },
  { 128, 160, 224, 1 },
  {  96, 128, 224, 1 }
};
unsigned char col1a4cnt[8] = { 45, 3, 6, 0, 6, 1, 6, 2 };
palette_entry col1a4col[3] = {
  { 128, 160, 224, 1 },
  {  96, 128, 224, 1 },
  { 160, 192, 224, 1 }
};
unsigned char col1a5cnt[8] = { 47, 3, 6, 0, 6, 1, 6, 2 };
palette_entry col1a5col[3] = {
  {  96, 128, 192, 1 },
  { 160, 192, 224, 1 },
  { 128, 160, 224, 1 }
};
static int FadeCount;





















void clchgctr() { /* Line 175, Address: 0x101fab0 */



  colchg11a(); /* Line 179, Address: 0x101fab8 */


















} /* Line 198, Address: 0x101fac0 */





void colchg11a() { /* Line 204, Address: 0x101fad0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col1a0cnt, col1a0col); /* Line 205, Address: 0x101fad8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col1a1cnt, col1a1col); /* Line 206, Address: 0x101fb00 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col1a2cnt, col1a2col); /* Line 207, Address: 0x101fb28 */
  clchg_sub0(&clchgtim[3], &clchgcnt[3], col1a3cnt, col1a3col); /* Line 208, Address: 0x101fb50 */
  clchg_sub0(&clchgtim[4], &clchgcnt[4], col1a4cnt, col1a4col); /* Line 209, Address: 0x101fb78 */
  clchg_sub0(&clchgtim[5], &clchgcnt[5], col1a5cnt, col1a5col); /* Line 210, Address: 0x101fba0 */

} /* Line 212, Address: 0x101fbc8 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 222, Address: 0x101fbe0 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 225, Address: 0x101fbf8 */
  if ((char)*pChgTime < 0) { /* Line 226, Address: 0x101fc0c */
    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 227, Address: 0x101fc2c */
    ++*pChgCnt; /* Line 228, Address: 0x101fc50 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 229, Address: 0x101fc64 */
      *pChgCnt = 0; /* Line 230, Address: 0x101fc90 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 233, Address: 0x101fc98 */
    *pChgTime = pCntTbl[0]; /* Line 234, Address: 0x101fcb4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 235, Address: 0x101fcc4 */
  }





} /* Line 242, Address: 0x101fcfc */


void fadein0() { /* Line 245, Address: 0x101fd10 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 249, Address: 0x101fd1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 251, Address: 0x101fd50 */
    lpPe->peRed = 0; /* Line 252, Address: 0x101fd5c */
    lpPe->peGreen = 0; /* Line 253, Address: 0x101fd60 */
    lpPe->peBlue = 0; /* Line 254, Address: 0x101fd64 */
    lpPe->peFlags = 1; /* Line 255, Address: 0x101fd68 */
    ++lpPe; /* Line 256, Address: 0x101fd70 */
  } /* Line 257, Address: 0x101fd74 */
  FadeCount = 0; /* Line 258, Address: 0x101fd90 */
  *lpFadeFlag = 1; /* Line 259, Address: 0x101fd98 */

} /* Line 261, Address: 0x101fda8 */



static int fadein0_new() { /* Line 265, Address: 0x101fdc0 */

  int_flg = 18; /* Line 267, Address: 0x101fdc8 */

  fadein1(); /* Line 269, Address: 0x101fdd4 */


  if (++FadeCount > 21) { /* Line 272, Address: 0x101fddc */
    FadeCount = 0; /* Line 273, Address: 0x101fdfc */
    return 1; /* Line 274, Address: 0x101fe04 */
  }
  return 0; /* Line 276, Address: 0x101fe10 */
} /* Line 277, Address: 0x101fe14 */



static void fadein1() { /* Line 281, Address: 0x101fe30 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 285, Address: 0x101fe44 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 286, Address: 0x101fe78 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 288, Address: 0x101feac */
    fadein2(lpPe, lpPe2); /* Line 289, Address: 0x101feb8 */
    ++lpPe; /* Line 290, Address: 0x101fec8 */
    ++lpPe2; /* Line 291, Address: 0x101fecc */
  } /* Line 292, Address: 0x101fed0 */
  if (stageno.b.h == 1) return; /* Line 293, Address: 0x101feec */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 295, Address: 0x101ff08 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 296, Address: 0x101ff3c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 298, Address: 0x101ff70 */
    fadein2(lpPe, lpPe2); /* Line 299, Address: 0x101ff7c */
    ++lpPe; /* Line 300, Address: 0x101ff8c */
    ++lpPe2; /* Line 301, Address: 0x101ff90 */
  } /* Line 302, Address: 0x101ff94 */



} /* Line 306, Address: 0x101ffb0 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 310, Address: 0x101ffd0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 311, Address: 0x101ffdc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 314, Address: 0x102003c */
      lpPeDest->peBlue += 32; /* Line 315, Address: 0x1020060 */
    } /* Line 316, Address: 0x1020070 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 317, Address: 0x1020078 */
      lpPeDest->peGreen += 32; /* Line 318, Address: 0x102009c */
    } /* Line 319, Address: 0x10200ac */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 320, Address: 0x10200b4 */
      lpPeDest->peRed += 32; /* Line 321, Address: 0x10200d8 */
    }
  }

} /* Line 325, Address: 0x10200ec */


void fadeout() {
  startcolor = 0; /* Line 329, Address: 0x1020100 */
  colorcnt = 63; /* Line 330, Address: 0x1020108 */

  FadeCount = 0; /* Line 332, Address: 0x1020114 */
  *lpFadeFlag = 2; /* Line 333, Address: 0x102011c */

} /* Line 335, Address: 0x102012c */



static int fadeout_new() { /* Line 339, Address: 0x1020140 */

  int_flg = 18; /* Line 341, Address: 0x1020148 */

  fadeout1(); /* Line 343, Address: 0x1020154 */


  if (++FadeCount > 21) { /* Line 346, Address: 0x102015c */
    FadeCount = 0; /* Line 347, Address: 0x102017c */
    return 1; /* Line 348, Address: 0x1020184 */
  }
  return 0; /* Line 350, Address: 0x1020190 */
} /* Line 351, Address: 0x1020194 */


static void fadeout1() { /* Line 354, Address: 0x10201b0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 358, Address: 0x10201c0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 360, Address: 0x10201f4 */
    fadeout2(lpPe); /* Line 361, Address: 0x1020200 */
    ++lpPe; /* Line 362, Address: 0x102020c */
  } /* Line 363, Address: 0x1020210 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 364, Address: 0x102022c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 366, Address: 0x1020260 */
    fadeout2(lpPe); /* Line 367, Address: 0x102026c */
    ++lpPe; /* Line 368, Address: 0x1020278 */
  } /* Line 369, Address: 0x102027c */


} /* Line 372, Address: 0x1020298 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 375, Address: 0x10202b0 */
  if (lpPeDest->peRed) { /* Line 376, Address: 0x10202b8 */
    lpPeDest->peRed -= 32; /* Line 377, Address: 0x10202c8 */
  } /* Line 378, Address: 0x10202dc */
  else if (lpPeDest->peGreen) { /* Line 379, Address: 0x10202e4 */
    lpPeDest->peGreen -= 32; /* Line 380, Address: 0x10202f4 */
  } /* Line 381, Address: 0x1020304 */
  else if (lpPeDest->peBlue) { /* Line 382, Address: 0x102030c */
    lpPeDest->peBlue -= 32; /* Line 383, Address: 0x102031c */
  }

} /* Line 386, Address: 0x102032c */




void flashin() { /* Line 391, Address: 0x1020340 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 395, Address: 0x102034c */
  colorcnt = 63; /* Line 396, Address: 0x1020354 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 398, Address: 0x1020360 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 400, Address: 0x1020394 */
    lpPe->peRed = 224; /* Line 401, Address: 0x10203a0 */
    lpPe->peGreen = 224; /* Line 402, Address: 0x10203a8 */
    lpPe->peBlue = 224; /* Line 403, Address: 0x10203b0 */
    lpPe->peFlags = 1; /* Line 404, Address: 0x10203b8 */
    ++lpPe; /* Line 405, Address: 0x10203c0 */
  } /* Line 406, Address: 0x10203c4 */
  FadeCount = 0; /* Line 407, Address: 0x10203e0 */
  *lpFadeFlag = 3; /* Line 408, Address: 0x10203e8 */

} /* Line 410, Address: 0x10203f8 */

static int flashin_new() { /* Line 412, Address: 0x1020410 */

  int_flg = 18; /* Line 414, Address: 0x1020418 */

  flashin1(); /* Line 416, Address: 0x1020424 */


  if (++FadeCount > 21) { /* Line 419, Address: 0x102042c */
    FadeCount = 0; /* Line 420, Address: 0x102044c */
    return 1; /* Line 421, Address: 0x1020454 */
  }
  return 0; /* Line 423, Address: 0x1020460 */
} /* Line 424, Address: 0x1020464 */

static void flashin1() { /* Line 426, Address: 0x1020480 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 430, Address: 0x1020494 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 431, Address: 0x10204c8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 433, Address: 0x10204fc */
    flashin2(lpPe, lpPe2); /* Line 434, Address: 0x1020508 */
    ++lpPe; /* Line 435, Address: 0x1020518 */
    ++lpPe2; /* Line 436, Address: 0x102051c */
  } /* Line 437, Address: 0x1020520 */
  if (stageno.b.h == 1) return; /* Line 438, Address: 0x102053c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 440, Address: 0x1020558 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 441, Address: 0x102058c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 443, Address: 0x10205c0 */
    flashin2(lpPe, lpPe2); /* Line 444, Address: 0x10205cc */
    ++lpPe; /* Line 445, Address: 0x10205dc */
    ++lpPe2; /* Line 446, Address: 0x10205e0 */
  } /* Line 447, Address: 0x10205e4 */



} /* Line 451, Address: 0x1020600 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 455, Address: 0x1020620 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 456, Address: 0x102062c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 459, Address: 0x102068c */
      lpPeDest->peBlue -= 32; /* Line 460, Address: 0x10206b0 */
    } /* Line 461, Address: 0x10206c0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 462, Address: 0x10206c8 */
      lpPeDest->peGreen -= 32; /* Line 463, Address: 0x10206ec */
    } /* Line 464, Address: 0x10206fc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 465, Address: 0x1020704 */
      lpPeDest->peRed -= 32; /* Line 466, Address: 0x1020728 */
    }
  }

} /* Line 470, Address: 0x102073c */


void flashout() {
  startcolor = 0; /* Line 474, Address: 0x1020750 */
  colorcnt = 63; /* Line 475, Address: 0x1020758 */

  FadeCount = 0; /* Line 477, Address: 0x1020764 */
  *lpFadeFlag = 4; /* Line 478, Address: 0x102076c */

} /* Line 480, Address: 0x102077c */

static int flashout_new() { /* Line 482, Address: 0x1020790 */

  int_flg = 18; /* Line 484, Address: 0x1020798 */

  flashout1(); /* Line 486, Address: 0x10207a4 */


  if (++FadeCount > 21) { /* Line 489, Address: 0x10207ac */
    FadeCount = 0; /* Line 490, Address: 0x10207cc */
    return 1; /* Line 491, Address: 0x10207d4 */
  }
  return 0; /* Line 493, Address: 0x10207e0 */
} /* Line 494, Address: 0x10207e4 */


static void flashout1() { /* Line 497, Address: 0x1020800 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 501, Address: 0x1020810 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 503, Address: 0x1020844 */
    flashout2(lpPe); /* Line 504, Address: 0x1020850 */
    ++lpPe; /* Line 505, Address: 0x102085c */
  } /* Line 506, Address: 0x1020860 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 507, Address: 0x102087c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 509, Address: 0x10208b0 */
    flashout2(lpPe); /* Line 510, Address: 0x10208bc */
    ++lpPe; /* Line 511, Address: 0x10208c8 */
  } /* Line 512, Address: 0x10208cc */


} /* Line 515, Address: 0x10208e8 */


static void flashout2(palette_entry* lpPeDest) { /* Line 518, Address: 0x1020900 */
  if (lpPeDest->peRed != 224) { /* Line 519, Address: 0x1020908 */
    lpPeDest->peRed += 32; /* Line 520, Address: 0x1020920 */
  } /* Line 521, Address: 0x1020934 */
  else if (lpPeDest->peGreen != 224) { /* Line 522, Address: 0x102093c */
    lpPeDest->peGreen += 32; /* Line 523, Address: 0x1020954 */
  } /* Line 524, Address: 0x1020964 */
  else if (lpPeDest->peBlue != 224) { /* Line 525, Address: 0x102096c */
    lpPeDest->peBlue += 32; /* Line 526, Address: 0x1020984 */
  }


} /* Line 530, Address: 0x1020994 */


void colorset(int ColorNo) { /* Line 533, Address: 0x10209a0 */
  colorset00(ColorNo, 1); /* Line 534, Address: 0x10209ac */
} /* Line 535, Address: 0x10209bc */

void colorset2(int ColorNo) { /* Line 537, Address: 0x10209d0 */
  colorset00(ColorNo, 0); /* Line 538, Address: 0x10209dc */
} /* Line 539, Address: 0x10209ec */

static void colorset3(int ColorNo) { /* Line 541, Address: 0x1020a00 */
  colorset00(ColorNo, 0); /* Line 542, Address: 0x1020a0c */
} /* Line 543, Address: 0x1020a1c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 549, Address: 0x1020a30 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 554, Address: 0x1020a50 */
    case 0:
      lppe = lpcolorwk; break; /* Line 556, Address: 0x1020ab8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 558, Address: 0x1020ac8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 560, Address: 0x1020ad8 */
    default:
      lppe = lpcolorwk4; break; /* Line 562, Address: 0x1020ae8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 565, Address: 0x1020af0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 566, Address: 0x1020b08 */
  n = colortbl[ColorNo].cnt; /* Line 567, Address: 0x1020b30 */
  for (i = 0; i < n; ++i) { /* Line 568, Address: 0x1020b50 */
    *lpPeDest++ = *lpPeSrc++; /* Line 569, Address: 0x1020b5c */
  } /* Line 570, Address: 0x1020b8c */

} /* Line 572, Address: 0x1020b9c */




int FadeProc() { /* Line 577, Address: 0x1020bc0 */
  switch (*lpFadeFlag) { /* Line 578, Address: 0x1020bc8 */
    case 1:
      return fadein0_new(); /* Line 580, Address: 0x1020c0c */
    case 2:
      return fadeout_new(); /* Line 582, Address: 0x1020c1c */
    case 3:
      return flashin_new(); /* Line 584, Address: 0x1020c2c */
    case 4:
      return flashout_new(); /* Line 586, Address: 0x1020c3c */
  }
  return 1; /* Line 588, Address: 0x1020c4c */

} /* Line 590, Address: 0x1020c50 */
