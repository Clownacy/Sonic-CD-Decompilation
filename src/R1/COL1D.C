#include "..\EQU.H"
#include "COL1D.H"

palette_entry clst1_1d0[3][4] = {
  { { 128, 128, 128, 1 }, {  96,  96,  96, 1 }, { 128, 128, 128, 1 }, {  64,  64,  64, 1 } },
  { {  64,  64,  64, 1 }, { 128, 128, 128, 1 }, {  96,  96,  96, 1 }, {  96,  96,  96, 1 } },
  { {  96,  96,  96, 1 }, {  64,  64,  64, 1 }, {  64,  64,  64, 1 }, { 128, 128, 128, 1 } }
};
palette_entry clst1_1d1[3][4] = {
  { { 224, 160, 192, 1 }, { 192, 128, 192, 1 }, {  64,  64, 160, 1 }, { 160,  96, 192, 1 } },
  { { 192, 128, 192, 1 }, { 160,  96, 192, 1 }, {  64,  64, 160, 1 }, { 224, 160, 192, 1 } },
  { { 160,  96, 192, 1 }, { 224, 160, 192, 1 }, {  64,  64, 160, 1 }, { 192, 128, 192, 1 } }
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
  {  96,  64,  96, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
palette_entry zone1colord[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  96,  64,  96, 1 }, { 192, 160, 224, 1 }, {  64, 128,   0, 1 }, {   0,   0,  32, 1 },
  {  96,  96, 160, 1 }, { 192,  64,   0, 1 }, {  64,  64,  96, 1 }, {  32,  32,  64, 1 },
  { 224, 128,  32, 1 }, { 128,  32,   0, 1 }, {  64,  32,   0, 1 }, {  32,  32,   0, 1 },
  { 224, 160, 192, 1 }, { 192, 128, 192, 1 }, {  96,  64, 128, 1 }, {  64,  96, 192, 1 },
  {  96,  64,  32, 1 }, { 128,  64,  64, 1 }, { 160,  96,  96, 1 }, { 192, 128, 160, 1 },
  { 224, 160, 160, 1 }, { 128, 128, 128, 1 }, {  96,  96,  96, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {  64,  64,  96, 1 }, { 128,  96, 128, 1 }, { 224, 160, 224, 1 },
  {   0,   0,   0, 1 }, {  96,  32,  32, 1 }, { 160,  96,   0, 1 }, { 224, 160,   0, 1 }
};
palette_entry zone1colboss1[16] = {
  {  64,  96,  96, 1 }, {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, {  96,  96,  96, 1 },
  { 128, 128, 128, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 128,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224, 224,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone1colord, 16, 48 },
  { zone1colboss1, 16, 16 }
};
unsigned char col1d0cnt[18] = { 34, 8, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 3, 4, 2, 4, 1 };
palette_entry col1d0col[5] = {
  { 224,   0,   0, 1 },
  { 192,   0,   0, 1 },
  { 160,   0,   0, 1 },
  { 128,   0,   0, 1 },
  {  96,   0,   0, 1 }
};
static int FadeCount;











void clchgctr() { /* Line 104, Address: 0x10232a0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  --clchgtim[0]; /* Line 108, Address: 0x10232b4 */
  if (clchgtim[0] & 128) { /* Line 109, Address: 0x10232c8 */
    clchgtim[0] = 7; /* Line 110, Address: 0x10232e0 */
    if (clchgcnt[0] == 2) { /* Line 111, Address: 0x10232ec */
      clchgcnt[0] = 0; /* Line 112, Address: 0x1023304 */
    } /* Line 113, Address: 0x102330c */
    else {
      ++clchgcnt[0]; /* Line 115, Address: 0x1023314 */
    }
  }
  lpPe = &lpcolorwk[53]; /* Line 118, Address: 0x1023328 */
  lpPe2 = clst1_1d0[clchgcnt[0]]; /* Line 119, Address: 0x1023334 */
  for (i = 0; i < 4; ++i) { /* Line 120, Address: 0x1023350 */
    *lpPe++ = *lpPe2++; /* Line 121, Address: 0x102335c */
  } /* Line 122, Address: 0x102338c */

  --clchgtim[1]; /* Line 124, Address: 0x102339c */
  if (clchgtim[1] & 128) { /* Line 125, Address: 0x10233b0 */
    clchgtim[1] = 5; /* Line 126, Address: 0x10233c8 */
    if (clchgtim[1] == 2) { /* Line 127, Address: 0x10233d4 */
      clchgcnt[1] = 0; /* Line 128, Address: 0x10233ec */
    } /* Line 129, Address: 0x10233f4 */
    else {
      ++clchgcnt[1]; /* Line 131, Address: 0x10233fc */
    }
  }
  lpPe = &lpcolorwk[44]; /* Line 134, Address: 0x1023410 */
  lpPe2 = clst1_1d1[clchgcnt[1]]; /* Line 135, Address: 0x102341c */
  for (i = 0; i < 4; ++i) { /* Line 136, Address: 0x1023438 */
    *lpPe++ = *lpPe2++; /* Line 137, Address: 0x1023444 */
  } /* Line 138, Address: 0x1023474 */

  clchg_sub0(&clchgtim[2], &clchgcnt[2], col1d0cnt, col1d0col); /* Line 140, Address: 0x1023484 */
} /* Line 141, Address: 0x10234ac */












void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 154, Address: 0x10234d0 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 157, Address: 0x10234e8 */
  if ((char)*pChgTime < 0) { /* Line 158, Address: 0x10234fc */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 160, Address: 0x102351c */
    ++*pChgCnt; /* Line 161, Address: 0x1023540 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 162, Address: 0x1023554 */

      *pChgCnt = 0; /* Line 164, Address: 0x1023580 */
    }
  }
  pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 167, Address: 0x1023588 */
  *pChgTime = pCntTbl[0]; /* Line 168, Address: 0x10235a4 */
  *lpPe = pColTbl[pCntTbl[1]]; /* Line 169, Address: 0x10235b4 */

} /* Line 171, Address: 0x10235ec */


void fadein0() { /* Line 174, Address: 0x1023600 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 178, Address: 0x102360c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 180, Address: 0x1023640 */
    lpPe->peRed = 0; /* Line 181, Address: 0x102364c */
    lpPe->peGreen = 0; /* Line 182, Address: 0x1023650 */
    lpPe->peBlue = 0; /* Line 183, Address: 0x1023654 */
    lpPe->peFlags = 1; /* Line 184, Address: 0x1023658 */
    ++lpPe; /* Line 185, Address: 0x1023660 */
  } /* Line 186, Address: 0x1023664 */
  FadeCount = 0; /* Line 187, Address: 0x1023680 */
  *lpFadeFlag = 1; /* Line 188, Address: 0x1023688 */

} /* Line 190, Address: 0x1023698 */



int fadein0_new() { /* Line 194, Address: 0x10236b0 */

  int_flg = 18; /* Line 196, Address: 0x10236b8 */

  fadein1(); /* Line 198, Address: 0x10236c4 */


  if (++FadeCount >= 22) { /* Line 201, Address: 0x10236cc */
    FadeCount = 0; /* Line 202, Address: 0x10236ec */
    return 1; /* Line 203, Address: 0x10236f4 */
  }
  return 0; /* Line 205, Address: 0x1023700 */
} /* Line 206, Address: 0x1023704 */



static void fadein1() { /* Line 210, Address: 0x1023720 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 214, Address: 0x1023734 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 215, Address: 0x1023768 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 217, Address: 0x102379c */
    fadein2(lpPe, lpPe2); /* Line 218, Address: 0x10237a8 */
    ++lpPe; /* Line 219, Address: 0x10237b8 */
    ++lpPe2; /* Line 220, Address: 0x10237bc */
  } /* Line 221, Address: 0x10237c0 */
  if (stageno.b.h == 1) return; /* Line 222, Address: 0x10237dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 224, Address: 0x10237f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 225, Address: 0x102382c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 227, Address: 0x1023860 */
    fadein2(lpPe, lpPe2); /* Line 228, Address: 0x102386c */
    ++lpPe; /* Line 229, Address: 0x102387c */
    ++lpPe2; /* Line 230, Address: 0x1023880 */
  } /* Line 231, Address: 0x1023884 */



} /* Line 235, Address: 0x10238a0 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 239, Address: 0x10238c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 240, Address: 0x10238cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 243, Address: 0x102392c */
      lpPeDest->peBlue += 32; /* Line 244, Address: 0x1023950 */
    } /* Line 245, Address: 0x1023960 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 246, Address: 0x1023968 */
      lpPeDest->peGreen += 32; /* Line 247, Address: 0x102398c */
    } /* Line 248, Address: 0x102399c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 249, Address: 0x10239a4 */
      lpPeDest->peRed += 32; /* Line 250, Address: 0x10239c8 */
    }
  }

} /* Line 254, Address: 0x10239dc */


void fadeout() {
  startcolor = 0; /* Line 258, Address: 0x10239f0 */
  colorcnt = 63; /* Line 259, Address: 0x10239f8 */

  FadeCount = 0; /* Line 261, Address: 0x1023a04 */
  *lpFadeFlag = 2; /* Line 262, Address: 0x1023a0c */

} /* Line 264, Address: 0x1023a1c */



static int fadeout_new() { /* Line 268, Address: 0x1023a30 */

  int_flg = 18; /* Line 270, Address: 0x1023a38 */

  fadeout1(); /* Line 272, Address: 0x1023a44 */


  if (++FadeCount >= 22) { /* Line 275, Address: 0x1023a4c */
    FadeCount = 0; /* Line 276, Address: 0x1023a6c */
    return 1; /* Line 277, Address: 0x1023a74 */
  }
  return 0; /* Line 279, Address: 0x1023a80 */
} /* Line 280, Address: 0x1023a84 */


static void fadeout1() { /* Line 283, Address: 0x1023aa0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 287, Address: 0x1023ab0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 289, Address: 0x1023ae4 */
    fadeout2(lpPe); /* Line 290, Address: 0x1023af0 */
    ++lpPe; /* Line 291, Address: 0x1023afc */
  } /* Line 292, Address: 0x1023b00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 293, Address: 0x1023b1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 295, Address: 0x1023b50 */
    fadeout2(lpPe); /* Line 296, Address: 0x1023b5c */
    ++lpPe; /* Line 297, Address: 0x1023b68 */
  } /* Line 298, Address: 0x1023b6c */


} /* Line 301, Address: 0x1023b88 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 304, Address: 0x1023ba0 */
  if (lpPeDest->peRed) { /* Line 305, Address: 0x1023ba8 */
    lpPeDest->peRed -= 32; /* Line 306, Address: 0x1023bb8 */
  } /* Line 307, Address: 0x1023bcc */
  else if (lpPeDest->peGreen) { /* Line 308, Address: 0x1023bd4 */
    lpPeDest->peGreen -= 32; /* Line 309, Address: 0x1023be4 */
  } /* Line 310, Address: 0x1023bf4 */
  else if (lpPeDest->peBlue) { /* Line 311, Address: 0x1023bfc */
    lpPeDest->peBlue -= 32; /* Line 312, Address: 0x1023c0c */
  }

} /* Line 315, Address: 0x1023c1c */




void flashin() { /* Line 320, Address: 0x1023c30 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 324, Address: 0x1023c3c */
  colorcnt = 63; /* Line 325, Address: 0x1023c44 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 327, Address: 0x1023c50 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 329, Address: 0x1023c84 */
    lpPe->peRed = 224; /* Line 330, Address: 0x1023c90 */
    lpPe->peGreen = 224; /* Line 331, Address: 0x1023c98 */
    lpPe->peBlue = 224; /* Line 332, Address: 0x1023ca0 */
    lpPe->peFlags = 1; /* Line 333, Address: 0x1023ca8 */
    ++lpPe; /* Line 334, Address: 0x1023cb0 */
  } /* Line 335, Address: 0x1023cb4 */
  FadeCount = 0; /* Line 336, Address: 0x1023cd0 */
  *lpFadeFlag = 3; /* Line 337, Address: 0x1023cd8 */

} /* Line 339, Address: 0x1023ce8 */

static int flashin_new() { /* Line 341, Address: 0x1023d00 */

  int_flg = 18; /* Line 343, Address: 0x1023d08 */

  flashin1(); /* Line 345, Address: 0x1023d14 */


  if (++FadeCount >= 22) { /* Line 348, Address: 0x1023d1c */
    FadeCount = 0; /* Line 349, Address: 0x1023d3c */
    return 1; /* Line 350, Address: 0x1023d44 */
  }
  return 0; /* Line 352, Address: 0x1023d50 */
} /* Line 353, Address: 0x1023d54 */

static void flashin1() { /* Line 355, Address: 0x1023d70 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 359, Address: 0x1023d84 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 360, Address: 0x1023db8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 362, Address: 0x1023dec */
    flashin2(lpPe, lpPe2); /* Line 363, Address: 0x1023df8 */
    ++lpPe; /* Line 364, Address: 0x1023e08 */
    ++lpPe2; /* Line 365, Address: 0x1023e0c */
  } /* Line 366, Address: 0x1023e10 */
  if (stageno.b.h == 1) return; /* Line 367, Address: 0x1023e2c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 369, Address: 0x1023e48 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 370, Address: 0x1023e7c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 372, Address: 0x1023eb0 */
    flashin2(lpPe, lpPe2); /* Line 373, Address: 0x1023ebc */
    ++lpPe; /* Line 374, Address: 0x1023ecc */
    ++lpPe2; /* Line 375, Address: 0x1023ed0 */
  } /* Line 376, Address: 0x1023ed4 */



} /* Line 380, Address: 0x1023ef0 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 384, Address: 0x1023f10 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 385, Address: 0x1023f1c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 388, Address: 0x1023f7c */
      lpPeDest->peBlue -= 32; /* Line 389, Address: 0x1023fa0 */
    } /* Line 390, Address: 0x1023fb0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 391, Address: 0x1023fb8 */
      lpPeDest->peGreen -= 32; /* Line 392, Address: 0x1023fdc */
    } /* Line 393, Address: 0x1023fec */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 394, Address: 0x1023ff4 */
      lpPeDest->peRed -= 32; /* Line 395, Address: 0x1024018 */
    }
  }

} /* Line 399, Address: 0x102402c */


void flashout() {
  startcolor = 0; /* Line 403, Address: 0x1024040 */
  colorcnt = 63; /* Line 404, Address: 0x1024048 */

  FadeCount = 0; /* Line 406, Address: 0x1024054 */
  *lpFadeFlag = 4; /* Line 407, Address: 0x102405c */

} /* Line 409, Address: 0x102406c */

static int flashout_new() { /* Line 411, Address: 0x1024080 */

  int_flg = 18; /* Line 413, Address: 0x1024088 */

  flashout1(); /* Line 415, Address: 0x1024094 */


  if (++FadeCount >= 22) { /* Line 418, Address: 0x102409c */
    FadeCount = 0; /* Line 419, Address: 0x10240bc */
    return 1; /* Line 420, Address: 0x10240c4 */
  }
  return 0; /* Line 422, Address: 0x10240d0 */
} /* Line 423, Address: 0x10240d4 */


static void flashout1() { /* Line 426, Address: 0x10240f0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 430, Address: 0x1024100 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 432, Address: 0x1024134 */
    flashout2(lpPe); /* Line 433, Address: 0x1024140 */
    ++lpPe; /* Line 434, Address: 0x102414c */
  } /* Line 435, Address: 0x1024150 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 436, Address: 0x102416c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 438, Address: 0x10241a0 */
    flashout2(lpPe); /* Line 439, Address: 0x10241ac */
    ++lpPe; /* Line 440, Address: 0x10241b8 */
  } /* Line 441, Address: 0x10241bc */


} /* Line 444, Address: 0x10241d8 */


static void flashout2(palette_entry* lpPeDest) { /* Line 447, Address: 0x10241f0 */
  if (lpPeDest->peRed != 224) { /* Line 448, Address: 0x10241f8 */
    lpPeDest->peRed += 32; /* Line 449, Address: 0x1024210 */
  } /* Line 450, Address: 0x1024224 */
  else if (lpPeDest->peGreen != 224) { /* Line 451, Address: 0x102422c */
    lpPeDest->peGreen += 32; /* Line 452, Address: 0x1024244 */
  } /* Line 453, Address: 0x1024254 */
  else if (lpPeDest->peBlue != 224) { /* Line 454, Address: 0x102425c */
    lpPeDest->peBlue += 32; /* Line 455, Address: 0x1024274 */
  }


} /* Line 459, Address: 0x1024284 */


void colorset(int ColorNo) { /* Line 462, Address: 0x1024290 */
  colorset00(ColorNo, 1); /* Line 463, Address: 0x102429c */
} /* Line 464, Address: 0x10242ac */

void colorset2(int ColorNo) { /* Line 466, Address: 0x10242c0 */
  colorset00(ColorNo, 0); /* Line 467, Address: 0x10242cc */
} /* Line 468, Address: 0x10242dc */

void colorset3(int ColorNo) { /* Line 470, Address: 0x10242f0 */
  colorset00(ColorNo, 0); /* Line 471, Address: 0x10242fc */
} /* Line 472, Address: 0x102430c */





void colorset00(int ColorNo, int WorkOffs) { /* Line 478, Address: 0x1024320 */
  palette_entry *lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 483, Address: 0x1024340 */
    case 0:
      lppe = lpcolorwk; break; /* Line 485, Address: 0x10243a8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 487, Address: 0x10243b8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 489, Address: 0x10243c8 */
    default:
      lppe = lpcolorwk4; break; /* Line 491, Address: 0x10243d8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 494, Address: 0x10243e0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 495, Address: 0x10243f8 */
  n = colortbl[ColorNo].cnt; /* Line 496, Address: 0x1024420 */
  for (i = 0; i < n; ++i) { /* Line 497, Address: 0x1024440 */
    *lpPeDest++ = *lpPeSrc++; /* Line 498, Address: 0x102444c */
  } /* Line 499, Address: 0x102447c */

} /* Line 501, Address: 0x102448c */




int FadeProc() { /* Line 506, Address: 0x10244b0 */
  switch (*lpFadeFlag) { /* Line 507, Address: 0x10244b8 */
    case 1:
      return fadein0_new(); /* Line 509, Address: 0x10244fc */
    case 2:
      return fadeout_new(); /* Line 511, Address: 0x102450c */
    case 3:
      return flashin_new(); /* Line 513, Address: 0x102451c */
    case 4:
      return flashout_new(); /* Line 515, Address: 0x102452c */
  }
  return 1; /* Line 517, Address: 0x102453c */

} /* Line 519, Address: 0x1024540 */
