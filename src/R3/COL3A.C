#include "..\EQU.H"
#include "COL3A.H"

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
  { 128,   0, 128, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
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
palette_entry zone3colora2[48] = {
  {  96,  96,  96, 1 }, {   0,   0,   0, 1 }, {  32,  64, 224, 1 }, {  96, 128, 224, 1 },
  {   0,  96,   0, 1 }, {   0, 160,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  32, 192, 1 }, {  96,   0,   0, 1 }, { 224,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  64,   0, 128, 1 }, { 224, 224,  96, 1 }, { 224,  96, 160, 1 }, { 224,  64, 128, 1 },
  { 192,  32, 128, 1 }, {  96,   0,  64, 1 }, {  64,   0,  32, 1 }, {   0, 224,   0, 1 },
  {   0, 160,   0, 1 }, {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 224, 1 }, { 160,   0,  64, 1 }, { 224, 160,   0, 1 },
  {  64,   0, 128, 1 }, { 224, 224,   0, 1 }, { 224,  96,   0, 1 }, { 160,  64,   0, 1 },
  { 128,  32,   0, 1 }, {  32,   0,   0, 1 }, { 224,  96,   0, 1 }, { 192,   0, 128, 1 },
  { 128,   0, 128, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 128, 128, 1 },
  { 224, 224,   0, 1 }, { 224,   0, 224, 1 }, {   0,   0,   0, 1 }, {   0, 224,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 }, { advacolor,    0, 64 }, { advacolor2,    0, 64 },
  { gamecolor, 0, 16 }, { zone3colora, 16, 48 }, { zone3colora2, 16, 48 }
};
unsigned char col3a0cnt[8] = { 47, 3, 1, 0, 1, 1, 2, 2 };
palette_entry col3a0col[3] = { { 224, 224,   0, 1 }, { 224,   0,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col3a1cnt[34] = {
  60, 16,  1,  0,  2,  1,  1,  0,  2,  1,
   1,  0,  2,  1,  1,  0,  2,  1,  1,  0,
   2,  1,  1,  0,  2,  1,  1,  0,  2,  1,
   1,  0,  8,  1
};
palette_entry col3a1col[2] = { { 224, 224,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col3a2cnt[32] = {
  61, 15, 22,  0,  2,  1,  2,  0,  2,  1,
   2,  0,  2,  1,  2,  0,  2,  1,  2,  0,
   1,  2,  2,  1,  1,  2,  2,  1,  1,  2,
   2,  1
};
palette_entry col3a2col[3] = { {   0,   0,   0, 1 }, { 224,   0, 224, 1 }, { 224, 160, 224, 1 } };
unsigned char col3a3cnt[6] = { 63, 2, 1, 0, 2, 1 };
palette_entry col3a3col[2] = { {   0, 224, 224, 1 }, {   0,   0,   0, 1 } };
static int FadeCount;




unsigned short cntplus(unsigned char* work, unsigned short plus_data, unsigned short under_limit, unsigned short upper_limit) { /* Line 114, Address: 0x10244c0 */
  if ((*work += plus_data) > upper_limit) *work = under_limit; /* Line 115, Address: 0x10244d4 */
  return *work; /* Line 116, Address: 0x102451c */
} /* Line 117, Address: 0x1024528 */

void clchgctr() { /* Line 119, Address: 0x1024540 */
  colchg3a(); /* Line 120, Address: 0x1024548 */
} /* Line 121, Address: 0x1024550 */

void colchg3a() { /* Line 123, Address: 0x1024560 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col3a0cnt, col3a0col); /* Line 124, Address: 0x1024568 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col3a1cnt, col3a1col); /* Line 125, Address: 0x1024590 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col3a2cnt, col3a2col); /* Line 126, Address: 0x10245b8 */
  clchg_sub0(&clchgtim[3], &clchgcnt[3], col3a3cnt, col3a3col); /* Line 127, Address: 0x10245e0 */

} /* Line 129, Address: 0x1024608 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 139, Address: 0x1024620 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 142, Address: 0x1024638 */
  if ((char)*pChgTime < 0) { /* Line 143, Address: 0x102464c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 145, Address: 0x102466c */
    ++*pChgCnt; /* Line 146, Address: 0x1024690 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 147, Address: 0x10246a4 */

      *pChgCnt = 0; /* Line 149, Address: 0x10246d0 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 152, Address: 0x10246d8 */
    *pChgTime = pCntTbl[0]; /* Line 153, Address: 0x10246f4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 154, Address: 0x1024704 */
  }





} /* Line 161, Address: 0x102473c */


void fadein0() { /* Line 164, Address: 0x1024750 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 168, Address: 0x102475c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 170, Address: 0x1024790 */
    lpPe->peRed = 0; /* Line 171, Address: 0x102479c */
    lpPe->peGreen = 0; /* Line 172, Address: 0x10247a0 */
    lpPe->peBlue = 0; /* Line 173, Address: 0x10247a4 */
    lpPe->peFlags = 1; /* Line 174, Address: 0x10247a8 */
    ++lpPe; /* Line 175, Address: 0x10247b0 */
  } /* Line 176, Address: 0x10247b4 */
  FadeCount = 0; /* Line 177, Address: 0x10247d0 */
  *lpFadeFlag = 1; /* Line 178, Address: 0x10247d8 */

} /* Line 180, Address: 0x10247e8 */



int fadein0_new() { /* Line 184, Address: 0x1024800 */

  int_flg = 18; /* Line 186, Address: 0x1024808 */

  fadein1(); /* Line 188, Address: 0x1024814 */


  if (++FadeCount > 21) { /* Line 191, Address: 0x102481c */
    FadeCount = 0; /* Line 192, Address: 0x102483c */
    return 1; /* Line 193, Address: 0x1024844 */
  }
  return 0; /* Line 195, Address: 0x1024850 */
} /* Line 196, Address: 0x1024854 */



static void fadein1() { /* Line 200, Address: 0x1024870 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 204, Address: 0x1024884 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 205, Address: 0x10248b8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 207, Address: 0x10248ec */
    fadein2(lpPe, lpPe2); /* Line 208, Address: 0x10248f8 */
    ++lpPe; /* Line 209, Address: 0x1024908 */
    ++lpPe2; /* Line 210, Address: 0x102490c */
  } /* Line 211, Address: 0x1024910 */
  if (stageno.b.h == 1) return; /* Line 212, Address: 0x102492c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 214, Address: 0x1024948 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 215, Address: 0x102497c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 217, Address: 0x10249b0 */
    fadein2(lpPe, lpPe2); /* Line 218, Address: 0x10249bc */
    ++lpPe; /* Line 219, Address: 0x10249cc */
    ++lpPe2; /* Line 220, Address: 0x10249d0 */
  } /* Line 221, Address: 0x10249d4 */



} /* Line 225, Address: 0x10249f0 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 229, Address: 0x1024a10 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 230, Address: 0x1024a1c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 233, Address: 0x1024a7c */
      lpPeDest->peBlue += 32; /* Line 234, Address: 0x1024aa0 */
    } /* Line 235, Address: 0x1024ab0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 236, Address: 0x1024ab8 */
      lpPeDest->peGreen += 32; /* Line 237, Address: 0x1024adc */
    } /* Line 238, Address: 0x1024aec */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 239, Address: 0x1024af4 */
      lpPeDest->peRed += 32; /* Line 240, Address: 0x1024b18 */
    }
  }

} /* Line 244, Address: 0x1024b2c */


void fadeout() {
  startcolor = 0; /* Line 248, Address: 0x1024b40 */
  colorcnt = 63; /* Line 249, Address: 0x1024b48 */

  FadeCount = 0; /* Line 251, Address: 0x1024b54 */
  *lpFadeFlag = 2; /* Line 252, Address: 0x1024b5c */

} /* Line 254, Address: 0x1024b6c */



static int fadeout_new() { /* Line 258, Address: 0x1024b80 */

  int_flg = 18; /* Line 260, Address: 0x1024b88 */

  fadeout1(); /* Line 262, Address: 0x1024b94 */


  if (++FadeCount > 21) { /* Line 265, Address: 0x1024b9c */
    FadeCount = 0; /* Line 266, Address: 0x1024bbc */
    return 1; /* Line 267, Address: 0x1024bc4 */
  }
  return 0; /* Line 269, Address: 0x1024bd0 */
} /* Line 270, Address: 0x1024bd4 */


static void fadeout1() { /* Line 273, Address: 0x1024bf0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 277, Address: 0x1024c00 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 279, Address: 0x1024c34 */
    fadeout2(lpPe); /* Line 280, Address: 0x1024c40 */
    ++lpPe; /* Line 281, Address: 0x1024c4c */
  } /* Line 282, Address: 0x1024c50 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 283, Address: 0x1024c6c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 285, Address: 0x1024ca0 */
    fadeout2(lpPe); /* Line 286, Address: 0x1024cac */
    ++lpPe; /* Line 287, Address: 0x1024cb8 */
  } /* Line 288, Address: 0x1024cbc */


} /* Line 291, Address: 0x1024cd8 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 294, Address: 0x1024cf0 */
  if (lpPeDest->peRed) { /* Line 295, Address: 0x1024cf8 */
    lpPeDest->peRed -= 32; /* Line 296, Address: 0x1024d08 */
  } /* Line 297, Address: 0x1024d1c */
  else if (lpPeDest->peGreen) { /* Line 298, Address: 0x1024d24 */
    lpPeDest->peGreen -= 32; /* Line 299, Address: 0x1024d34 */
  } /* Line 300, Address: 0x1024d44 */
  else if (lpPeDest->peBlue) { /* Line 301, Address: 0x1024d4c */
    lpPeDest->peBlue -= 32; /* Line 302, Address: 0x1024d5c */
  }

} /* Line 305, Address: 0x1024d6c */




void flashin() { /* Line 310, Address: 0x1024d80 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 314, Address: 0x1024d8c */
  colorcnt = 63; /* Line 315, Address: 0x1024d94 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 317, Address: 0x1024da0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 319, Address: 0x1024dd4 */
    lpPe->peRed = 224; /* Line 320, Address: 0x1024de0 */
    lpPe->peGreen = 224; /* Line 321, Address: 0x1024de8 */
    lpPe->peBlue = 224; /* Line 322, Address: 0x1024df0 */
    lpPe->peFlags = 1; /* Line 323, Address: 0x1024df8 */
    ++lpPe; /* Line 324, Address: 0x1024e00 */
  } /* Line 325, Address: 0x1024e04 */
  FadeCount = 0; /* Line 326, Address: 0x1024e20 */
  *lpFadeFlag = 3; /* Line 327, Address: 0x1024e28 */

} /* Line 329, Address: 0x1024e38 */

static int flashin_new() { /* Line 331, Address: 0x1024e50 */

  int_flg = 18; /* Line 333, Address: 0x1024e58 */

  flashin1(); /* Line 335, Address: 0x1024e64 */


  if (++FadeCount > 21) { /* Line 338, Address: 0x1024e6c */
    FadeCount = 0; /* Line 339, Address: 0x1024e8c */
    return 1; /* Line 340, Address: 0x1024e94 */
  }
  return 0; /* Line 342, Address: 0x1024ea0 */
} /* Line 343, Address: 0x1024ea4 */

static void flashin1() { /* Line 345, Address: 0x1024ec0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 349, Address: 0x1024ed4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 350, Address: 0x1024f08 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 352, Address: 0x1024f3c */
    flashin2(lpPe, lpPe2); /* Line 353, Address: 0x1024f48 */
    ++lpPe; /* Line 354, Address: 0x1024f58 */
    ++lpPe2; /* Line 355, Address: 0x1024f5c */
  } /* Line 356, Address: 0x1024f60 */
  if (stageno.b.h == 1) return; /* Line 357, Address: 0x1024f7c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 359, Address: 0x1024f98 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 360, Address: 0x1024fcc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 362, Address: 0x1025000 */
    flashin2(lpPe, lpPe2); /* Line 363, Address: 0x102500c */
    ++lpPe; /* Line 364, Address: 0x102501c */
    ++lpPe2; /* Line 365, Address: 0x1025020 */
  } /* Line 366, Address: 0x1025024 */



} /* Line 370, Address: 0x1025040 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 374, Address: 0x1025060 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 375, Address: 0x102506c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 378, Address: 0x10250cc */
      lpPeDest->peBlue -= 32; /* Line 379, Address: 0x10250f0 */
    } /* Line 380, Address: 0x1025100 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 381, Address: 0x1025108 */
      lpPeDest->peGreen -= 32; /* Line 382, Address: 0x102512c */
    } /* Line 383, Address: 0x102513c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 384, Address: 0x1025144 */
      lpPeDest->peRed -= 32; /* Line 385, Address: 0x1025168 */
    }
  }

} /* Line 389, Address: 0x102517c */


void flashout() {
  startcolor = 0; /* Line 393, Address: 0x1025190 */
  colorcnt = 63; /* Line 394, Address: 0x1025198 */

  FadeCount = 0; /* Line 396, Address: 0x10251a4 */
  *lpFadeFlag = 4; /* Line 397, Address: 0x10251ac */

} /* Line 399, Address: 0x10251bc */

static int flashout_new() { /* Line 401, Address: 0x10251d0 */

  int_flg = 18; /* Line 403, Address: 0x10251d8 */

  flashout1(); /* Line 405, Address: 0x10251e4 */


  if (++FadeCount > 21) { /* Line 408, Address: 0x10251ec */
    FadeCount = 0; /* Line 409, Address: 0x102520c */
    return 1; /* Line 410, Address: 0x1025214 */
  }
  return 0; /* Line 412, Address: 0x1025220 */
} /* Line 413, Address: 0x1025224 */


static void flashout1() { /* Line 416, Address: 0x1025240 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 420, Address: 0x1025250 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 422, Address: 0x1025284 */
    flashout2(lpPe); /* Line 423, Address: 0x1025290 */
    ++lpPe; /* Line 424, Address: 0x102529c */
  } /* Line 425, Address: 0x10252a0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 426, Address: 0x10252bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 428, Address: 0x10252f0 */
    flashout2(lpPe); /* Line 429, Address: 0x10252fc */
    ++lpPe; /* Line 430, Address: 0x1025308 */
  } /* Line 431, Address: 0x102530c */


} /* Line 434, Address: 0x1025328 */


static void flashout2(palette_entry* lpPeDest) { /* Line 437, Address: 0x1025340 */
  if (lpPeDest->peRed != 224) { /* Line 438, Address: 0x1025348 */
    lpPeDest->peRed += 32; /* Line 439, Address: 0x1025360 */
  } /* Line 440, Address: 0x1025374 */
  else if (lpPeDest->peGreen != 224) { /* Line 441, Address: 0x102537c */
    lpPeDest->peGreen += 32; /* Line 442, Address: 0x1025394 */
  } /* Line 443, Address: 0x10253a4 */
  else if (lpPeDest->peBlue != 224) { /* Line 444, Address: 0x10253ac */
    lpPeDest->peBlue += 32; /* Line 445, Address: 0x10253c4 */
  }


} /* Line 449, Address: 0x10253d4 */


void colorset(int ColorNo) { /* Line 452, Address: 0x10253e0 */
  colorset00(ColorNo, 1); /* Line 453, Address: 0x10253ec */
} /* Line 454, Address: 0x10253fc */

void colorset2(int ColorNo) { /* Line 456, Address: 0x1025410 */
  colorset00(ColorNo, 0); /* Line 457, Address: 0x102541c */
} /* Line 458, Address: 0x102542c */

void colorset3(int ColorNo) { /* Line 460, Address: 0x1025440 */
  colorset00(ColorNo, 0); /* Line 461, Address: 0x102544c */
} /* Line 462, Address: 0x102545c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 468, Address: 0x1025470 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 473, Address: 0x1025490 */
    case 0:
      lppe = lpcolorwk; break; /* Line 475, Address: 0x10254f8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 477, Address: 0x1025508 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 479, Address: 0x1025518 */
    default:
      lppe = lpcolorwk4; break; /* Line 481, Address: 0x1025528 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 484, Address: 0x1025530 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 485, Address: 0x1025548 */
  n = colortbl[ColorNo].cnt; /* Line 486, Address: 0x1025570 */
  for (i = 0; i < n; ++i) { /* Line 487, Address: 0x1025590 */
    *lpPeDest++ = *lpPeSrc++; /* Line 488, Address: 0x102559c */
  } /* Line 489, Address: 0x10255cc */

} /* Line 491, Address: 0x10255dc */




int FadeProc() { /* Line 496, Address: 0x1025600 */
  switch (*lpFadeFlag) { /* Line 497, Address: 0x1025608 */
    case 1:
      return fadein0_new(); /* Line 499, Address: 0x102564c */
    case 2:
      return fadeout_new(); /* Line 501, Address: 0x102565c */
    case 3:
      return flashin_new(); /* Line 503, Address: 0x102566c */
    case 4:
      return flashout_new(); /* Line 505, Address: 0x102567c */
  }
  return 1; /* Line 507, Address: 0x102568c */

} /* Line 509, Address: 0x1025690 */
