#include "..\EQU.H"
#include "COL4A.H"

void fadein1();
void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc);
int fadeout_new();
void fadeout1();
void fadeout2(palette_entry* lpPeDest);
int flashin_new();
void flashin1();
void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc);
int flashout_new();
void flashout1();
void flashout2(palette_entry* lpPeDest);
void colorset00(int ColorNo, int WorkOffs);

palette_entry advacolor[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,   0, 160, 1 }, {  64,   0, 192, 1 },
  {  96,   0, 224, 1 }, { 128,  32, 224, 1 }, { 224, 224, 224, 1 }, { 160,  64, 128, 1 },
  { 128,  32,  96, 1 }, {  64,   0,  32, 1 }, { 224,  64,  96, 1 }, { 160,   0,  32, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 160, 192, 1 }, {   0,   0,   0, 1 }, { 224,  32,  32, 1 },
  { 224, 128,  32, 1 }, {   0,   0,   0, 1 }, { 128,  32,  32, 1 }, { 192,  64,  32, 1 },
  {  64,   0,   0, 1 }, {  96,  32,  32, 1 }, { 160,  64,  32, 1 }, {  64,  32,  32, 1 },
  {  64,  32,  64, 1 }, { 128,  64, 128, 1 }, { 160,  96, 160, 1 }, { 192, 128, 192, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,  96, 1 }, { 128,  64, 160, 1 },
  { 192, 128, 224, 1 }, {  32, 128,   0, 1 }, { 192,  96,  32, 1 }, { 160,  32,  32, 1 },
  {  32,   0,  32, 1 }, {  64,   0,  32, 1 }, {  96,   0,  32, 1 }, {  96,  32,  32, 1 },
  {   0,   0,   0, 1 }, {  64,   0,  32, 1 }, {  96,   0,  32, 1 }, {  96,  32,  32, 1 }
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
palette_entry zone4colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 224,  64,   0, 1 },
  { 224, 192,   0, 1 }, {   0,   0,   0, 1 }, { 128,  32,   0, 1 }, { 192,  96,   0, 1 },
  {  64,  32,   0, 1 }, {  96,  64,   0, 1 }, { 160, 128,  64, 1 }, {   0,   0,  32, 1 },
  {  64,  64,  96, 1 }, { 128, 128, 160, 1 }, { 160, 160, 192, 1 }, { 192, 192, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 160,  96, 192, 1 }, { 192, 128, 192, 1 },
  { 224, 160, 192, 1 }, {   0, 224,  64, 1 }, { 224, 224,   0, 1 }, { 224,  64,   0, 1 },
  {   0,  32,   0, 1 }, {  32,  32,   0, 1 }, {  64,  96,   0, 1 }, { 128, 128,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  96,  32,   0, 1 }, { 128,  64,   0, 1 }
};
palette_entry boss4color[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 }
};
palette_part colortbl[6] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone4colora, 16, 48 },
  { boss4color, 16, 16 }
};
unsigned char col4d0cnt[8] = { 50, 3, 2, 0, 2, 1, 2, 2 };
unsigned char col4d1cnt[8] = { 51, 3, 2, 1, 2, 2, 2, 0 };
unsigned char col4d2cnt[8] = { 52, 3, 2, 2, 2, 0, 2, 1 };
palette_entry col4d0col[3] = {
  { 160,  96, 192, 1 }, { 192, 128, 192, 1 }, { 224, 160, 192, 1 }
};
static int FadeCount;






























void clchgctr() { /* Line 124, Address: 0x10262f0 */
  if (stageno.b.l) { /* Line 125, Address: 0x10262f8 */

    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4d0cnt, col4d0col); /* Line 127, Address: 0x1026308 */
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4d1cnt, col4d0col); /* Line 128, Address: 0x1026330 */
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4d2cnt, col4d0col); /* Line 129, Address: 0x1026358 */
  }
} /* Line 131, Address: 0x1026380 */







void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 139, Address: 0x1026390 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 142, Address: 0x10263a8 */
  if ((char)*pChgTime < 0) { /* Line 143, Address: 0x10263bc */
    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 144, Address: 0x10263dc */
    ++*pChgCnt; /* Line 145, Address: 0x1026400 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 146, Address: 0x1026414 */
      *pChgCnt = 0; /* Line 147, Address: 0x1026440 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 150, Address: 0x1026448 */
    *pChgTime = pCntTbl[0]; /* Line 151, Address: 0x1026464 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 152, Address: 0x1026474 */
  }





} /* Line 159, Address: 0x10264ac */


void fadein0() { /* Line 162, Address: 0x10264c0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 166, Address: 0x10264cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 168, Address: 0x1026500 */
    lpPe->peRed = 0; /* Line 169, Address: 0x102650c */
    lpPe->peGreen = 0; /* Line 170, Address: 0x1026510 */
    lpPe->peBlue = 0; /* Line 171, Address: 0x1026514 */
    lpPe->peFlags = 1; /* Line 172, Address: 0x1026518 */
    ++lpPe; /* Line 173, Address: 0x1026520 */
  } /* Line 174, Address: 0x1026524 */
  FadeCount = 0; /* Line 175, Address: 0x1026540 */
  *lpFadeFlag = 1; /* Line 176, Address: 0x1026548 */

} /* Line 178, Address: 0x1026558 */



int fadein0_new() { /* Line 182, Address: 0x1026570 */

  int_flg = 18; /* Line 184, Address: 0x1026578 */

  fadein1(); /* Line 186, Address: 0x1026584 */


  if (++FadeCount >= 22) { /* Line 189, Address: 0x102658c */
    FadeCount = 0; /* Line 190, Address: 0x10265ac */
    return 1; /* Line 191, Address: 0x10265b4 */
  }
  return 0; /* Line 193, Address: 0x10265c0 */
} /* Line 194, Address: 0x10265c4 */


static void fadein1() { /* Line 197, Address: 0x10265e0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 201, Address: 0x10265f4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 202, Address: 0x1026628 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 204, Address: 0x102665c */
    fadein2(lpPe, lpPe2); /* Line 205, Address: 0x1026668 */
    ++lpPe; /* Line 206, Address: 0x1026678 */
    ++lpPe2; /* Line 207, Address: 0x102667c */
  } /* Line 208, Address: 0x1026680 */
  if (stageno.b.h == 1) return; /* Line 209, Address: 0x102669c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 211, Address: 0x10266b8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 212, Address: 0x10266ec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 214, Address: 0x1026720 */
    fadein2(lpPe, lpPe2); /* Line 215, Address: 0x102672c */
    ++lpPe; /* Line 216, Address: 0x102673c */
    ++lpPe2; /* Line 217, Address: 0x1026740 */
  } /* Line 218, Address: 0x1026744 */



} /* Line 222, Address: 0x1026760 */




static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 227, Address: 0x1026780 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 228, Address: 0x102678c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 231, Address: 0x10267ec */
      lpPeDest->peBlue += 32; /* Line 232, Address: 0x1026810 */
    } /* Line 233, Address: 0x1026820 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 234, Address: 0x1026828 */
      lpPeDest->peGreen += 32; /* Line 235, Address: 0x102684c */
    } /* Line 236, Address: 0x102685c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 237, Address: 0x1026864 */
      lpPeDest->peRed += 32; /* Line 238, Address: 0x1026888 */
    }
  }

} /* Line 242, Address: 0x102689c */


void fadeout() {
  startcolor = 0; /* Line 246, Address: 0x10268b0 */
  colorcnt = 63; /* Line 247, Address: 0x10268b8 */

  FadeCount = 0; /* Line 249, Address: 0x10268c4 */
  *lpFadeFlag = 2; /* Line 250, Address: 0x10268cc */

} /* Line 252, Address: 0x10268dc */



static int fadeout_new() { /* Line 256, Address: 0x10268f0 */

  int_flg = 18; /* Line 258, Address: 0x10268f8 */

  fadeout1(); /* Line 260, Address: 0x1026904 */


  if (++FadeCount >= 22) { /* Line 263, Address: 0x102690c */
    FadeCount = 0; /* Line 264, Address: 0x102692c */
    return 1; /* Line 265, Address: 0x1026934 */
  }
  return 0; /* Line 267, Address: 0x1026940 */
} /* Line 268, Address: 0x1026944 */


static void fadeout1() { /* Line 271, Address: 0x1026960 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 275, Address: 0x1026970 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 277, Address: 0x10269a4 */
    fadeout2(lpPe); /* Line 278, Address: 0x10269b0 */
    ++lpPe; /* Line 279, Address: 0x10269bc */
  } /* Line 280, Address: 0x10269c0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 281, Address: 0x10269dc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 283, Address: 0x1026a10 */
    fadeout2(lpPe); /* Line 284, Address: 0x1026a1c */
    ++lpPe; /* Line 285, Address: 0x1026a28 */
  } /* Line 286, Address: 0x1026a2c */


} /* Line 289, Address: 0x1026a48 */



static void fadeout2(palette_entry* lpPeDest) { /* Line 293, Address: 0x1026a60 */
  if (lpPeDest->peRed) { /* Line 294, Address: 0x1026a68 */
    lpPeDest->peRed -= 32; /* Line 295, Address: 0x1026a78 */
  } /* Line 296, Address: 0x1026a8c */
  else if (lpPeDest->peGreen) { /* Line 297, Address: 0x1026a94 */
    lpPeDest->peGreen -= 32; /* Line 298, Address: 0x1026aa4 */
  } /* Line 299, Address: 0x1026ab4 */
  else if (lpPeDest->peBlue) { /* Line 300, Address: 0x1026abc */
    lpPeDest->peBlue -= 32; /* Line 301, Address: 0x1026acc */
  }

} /* Line 304, Address: 0x1026adc */


void flashin() { /* Line 307, Address: 0x1026af0 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 311, Address: 0x1026afc */
  colorcnt = 63; /* Line 312, Address: 0x1026b04 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 314, Address: 0x1026b10 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 316, Address: 0x1026b44 */
    lpPe->peRed = 224; /* Line 317, Address: 0x1026b50 */
    lpPe->peGreen = 224; /* Line 318, Address: 0x1026b58 */
    lpPe->peBlue = 224; /* Line 319, Address: 0x1026b60 */
    lpPe->peFlags = 1; /* Line 320, Address: 0x1026b68 */
    ++lpPe; /* Line 321, Address: 0x1026b70 */
  } /* Line 322, Address: 0x1026b74 */
  FadeCount = 0; /* Line 323, Address: 0x1026b90 */
  *lpFadeFlag = 3; /* Line 324, Address: 0x1026b98 */

} /* Line 326, Address: 0x1026ba8 */


static int flashin_new() { /* Line 329, Address: 0x1026bc0 */

  int_flg = 18; /* Line 331, Address: 0x1026bc8 */

  flashin1(); /* Line 333, Address: 0x1026bd4 */


  if (++FadeCount >= 22) { /* Line 336, Address: 0x1026bdc */
    FadeCount = 0; /* Line 337, Address: 0x1026bfc */
    return 1; /* Line 338, Address: 0x1026c04 */
  }
  return 0; /* Line 340, Address: 0x1026c10 */
} /* Line 341, Address: 0x1026c14 */


static void flashin1() { /* Line 344, Address: 0x1026c30 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 348, Address: 0x1026c44 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 349, Address: 0x1026c78 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 351, Address: 0x1026cac */
    flashin2(lpPe, lpPe2); /* Line 352, Address: 0x1026cb8 */
    ++lpPe; /* Line 353, Address: 0x1026cc8 */
    ++lpPe2; /* Line 354, Address: 0x1026ccc */
  } /* Line 355, Address: 0x1026cd0 */
  if (stageno.b.h == 1) return; /* Line 356, Address: 0x1026cec */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 358, Address: 0x1026d08 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 359, Address: 0x1026d3c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 361, Address: 0x1026d70 */
    flashin2(lpPe, lpPe2); /* Line 362, Address: 0x1026d7c */
    ++lpPe; /* Line 363, Address: 0x1026d8c */
    ++lpPe2; /* Line 364, Address: 0x1026d90 */
  } /* Line 365, Address: 0x1026d94 */



} /* Line 369, Address: 0x1026db0 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 373, Address: 0x1026dd0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 374, Address: 0x1026ddc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 377, Address: 0x1026e3c */
      lpPeDest->peBlue -= 32; /* Line 378, Address: 0x1026e60 */
    } /* Line 379, Address: 0x1026e70 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 380, Address: 0x1026e78 */
      lpPeDest->peGreen -= 32; /* Line 381, Address: 0x1026e9c */
    } /* Line 382, Address: 0x1026eac */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 383, Address: 0x1026eb4 */
      lpPeDest->peRed -= 32; /* Line 384, Address: 0x1026ed8 */
    }
  }

} /* Line 388, Address: 0x1026eec */


void flashout() {
  startcolor = 0; /* Line 392, Address: 0x1026f00 */
  colorcnt = 63; /* Line 393, Address: 0x1026f08 */

  FadeCount = 0; /* Line 395, Address: 0x1026f14 */
  *lpFadeFlag = 4; /* Line 396, Address: 0x1026f1c */

} /* Line 398, Address: 0x1026f2c */


static int flashout_new() { /* Line 401, Address: 0x1026f40 */

  int_flg = 18; /* Line 403, Address: 0x1026f48 */

  flashout1(); /* Line 405, Address: 0x1026f54 */


  if (++FadeCount >= 22) { /* Line 408, Address: 0x1026f5c */
    FadeCount = 0; /* Line 409, Address: 0x1026f7c */
    return 1; /* Line 410, Address: 0x1026f84 */
  }
  return 0; /* Line 412, Address: 0x1026f90 */
} /* Line 413, Address: 0x1026f94 */


static void flashout1() { /* Line 416, Address: 0x1026fb0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 420, Address: 0x1026fc0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 422, Address: 0x1026ff4 */
    flashout2(lpPe); /* Line 423, Address: 0x1027000 */
    ++lpPe; /* Line 424, Address: 0x102700c */
  } /* Line 425, Address: 0x1027010 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 426, Address: 0x102702c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 428, Address: 0x1027060 */
    flashout2(lpPe); /* Line 429, Address: 0x102706c */
    ++lpPe; /* Line 430, Address: 0x1027078 */
  } /* Line 431, Address: 0x102707c */


} /* Line 434, Address: 0x1027098 */



static void flashout2(palette_entry* lpPeDest) { /* Line 438, Address: 0x10270b0 */
  if (lpPeDest->peRed != 224) { /* Line 439, Address: 0x10270b8 */
    lpPeDest->peRed += 32; /* Line 440, Address: 0x10270d0 */
  } /* Line 441, Address: 0x10270e4 */
  else if (lpPeDest->peGreen != 224) { /* Line 442, Address: 0x10270ec */
    lpPeDest->peGreen += 32; /* Line 443, Address: 0x1027104 */
  } /* Line 444, Address: 0x1027114 */
  else if (lpPeDest->peBlue != 224) { /* Line 445, Address: 0x102711c */
    lpPeDest->peBlue += 32; /* Line 446, Address: 0x1027134 */
  }


} /* Line 450, Address: 0x1027144 */


void colorset(int ColorNo) { /* Line 453, Address: 0x1027150 */
  colorset00(ColorNo, 1); /* Line 454, Address: 0x102715c */
} /* Line 455, Address: 0x102716c */

void colorset2(int ColorNo) { /* Line 457, Address: 0x1027180 */
  colorset00(ColorNo, 0); /* Line 458, Address: 0x102718c */
} /* Line 459, Address: 0x102719c */

void colorset3(int ColorNo) { /* Line 461, Address: 0x10271b0 */
  colorset00(ColorNo, 2); /* Line 462, Address: 0x10271bc */
} /* Line 463, Address: 0x10271cc */




static void colorset00(int ColorNo, int WorkOffs) { /* Line 468, Address: 0x10271e0 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 473, Address: 0x1027200 */
    case 0:
      lppe = lpcolorwk; break; /* Line 475, Address: 0x1027268 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 477, Address: 0x1027278 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 479, Address: 0x1027288 */
    default:
      lppe = lpcolorwk4; break; /* Line 481, Address: 0x1027298 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 484, Address: 0x10272a0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 485, Address: 0x10272b8 */
  n = colortbl[ColorNo].cnt; /* Line 486, Address: 0x10272e0 */
  for (i = 0; i < n; ++i) { /* Line 487, Address: 0x1027300 */
    *lpPeDest++ = *lpPeSrc++; /* Line 488, Address: 0x102730c */
  } /* Line 489, Address: 0x102733c */

} /* Line 491, Address: 0x102734c */


int FadeProc() { /* Line 494, Address: 0x1027370 */
  switch (*lpFadeFlag) { /* Line 495, Address: 0x1027378 */
    case 1:
      return fadein0_new(); /* Line 497, Address: 0x10273bc */
    case 2:
      return fadeout_new(); /* Line 499, Address: 0x10273cc */
    case 3:
      return flashin_new(); /* Line 501, Address: 0x10273dc */
    case 4:
      return flashout_new(); /* Line 503, Address: 0x10273ec */
  }
  return 1; /* Line 505, Address: 0x10273fc */

} /* Line 507, Address: 0x1027400 */
