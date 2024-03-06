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
  {   0,   0,   0, 1 }, {  64,  32,   0, 1 }, {   0,  32, 128, 1 }, {   0,  64, 160, 1 },
  {  32,  96, 192, 1 }, {  64, 128, 192, 1 }, { 224, 224, 224, 1 }, { 160, 128, 128, 1 },
  { 128,  96,  96, 1 }, {  64,  32,  32, 1 }, { 192, 128,  96, 1 }, { 128,  64,  32, 1 },
  { 224,  64,  32, 1 }, { 128,   0,  32, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 128, 160, 160, 1 }, {   0,   0,   0, 1 }, {   0, 160, 160, 1 },
  {  32,   0,   0, 1 }, {  96,  32,   0, 1 }, { 160,  96,   0, 1 }, {   0,   0,  32, 1 },
  {   0,  32,  32, 1 }, {   0,  64,  96, 1 }, {  64,  96, 128, 1 }, {   0,   0,   0, 1 },
  {   0,  32,   0, 1 }, {  32,  64,   0, 1 }, { 128, 128,   0, 1 }, { 160, 160,  32, 1 },
  {   0,   0,   0, 1 }, { 160, 224, 192, 1 }, {   0, 192, 192, 1 }, {   0, 224, 224, 1 },
  {  64, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0, 160,  32, 1 }, {   0,  32,   0, 1 }, { 192, 128,  64, 1 }, {   0,   0,   0, 1 },
  {  32,   0,   0, 1 }, {  64,  32,   0, 1 }, { 160,  64,   0, 1 }, { 192, 128,   0, 1 }
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
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0, 224, 224, 1 },
  {  64,  32,   0, 1 }, { 192,  96,   0, 1 }, { 224, 160,  32, 1 }, {   0,   0,  32, 1 },
  {  32,  32,  96, 1 }, {  96,  96, 160, 1 }, { 160, 160, 224, 1 }, {  32,  32,   0, 1 },
  {   0,  64,   0, 1 }, {  32, 128,   0, 1 }, {  96, 192,  32, 1 }, { 224, 224,  96, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0, 192, 192, 1 }, {   0, 224, 224, 1 },
  {  64, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,  96,   0, 1 }, { 224, 192, 160, 1 }, {  32,  32,   0, 1 },
  {  64,  64,   0, 1 }, {  96,  96,   0, 1 }, { 192, 128,  32, 1 }, { 224, 192,  64, 1 }
};
palette_part colortbl[5] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone4colora, 16, 48 }
};
unsigned char col4b0cnt[8] = { 50, 3, 2, 0, 2, 1, 2, 2 };
unsigned char col4b1cnt[8] = { 51, 3, 2, 1, 2, 2, 2, 0 };
unsigned char col4b2cnt[8] = { 52, 3, 2, 2, 2, 0, 2, 1 };
palette_entry col4b0col[3] = {
  {   0, 192, 192, 1 },
  {   0, 224, 224, 1 },
  {  64, 224, 224, 1 }
};
static int FadeCount;
































void clchgctr() { /* Line 121, Address: 0x1001b10 */
  if (stageno.b.l) { /* Line 122, Address: 0x1001b18 */

    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4b0cnt, col4b0col); /* Line 124, Address: 0x1001b28 */
    clchg_sub0(&clchgtim[1], &clchgcnt[1], col4b1cnt, col4b0col); /* Line 125, Address: 0x1001b50 */
    clchg_sub0(&clchgtim[2], &clchgcnt[2], col4b2cnt, col4b0col); /* Line 126, Address: 0x1001b78 */
  }
} /* Line 128, Address: 0x1001ba0 */







void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 136, Address: 0x1001bb0 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 139, Address: 0x1001bc8 */
  if ((char)*pChgTime < 0) { /* Line 140, Address: 0x1001bdc */
    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 141, Address: 0x1001bfc */
    ++*pChgCnt; /* Line 142, Address: 0x1001c20 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 143, Address: 0x1001c34 */
      *pChgCnt = 0; /* Line 144, Address: 0x1001c60 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 147, Address: 0x1001c68 */
    *pChgTime = pCntTbl[0]; /* Line 148, Address: 0x1001c84 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 149, Address: 0x1001c94 */
  }





} /* Line 156, Address: 0x1001ccc */


void fadein0() { /* Line 159, Address: 0x1001ce0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 163, Address: 0x1001cec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 165, Address: 0x1001d20 */
    lpPe->peRed = 0; /* Line 166, Address: 0x1001d2c */
    lpPe->peGreen = 0; /* Line 167, Address: 0x1001d30 */
    lpPe->peBlue = 0; /* Line 168, Address: 0x1001d34 */
    lpPe->peFlags = 1; /* Line 169, Address: 0x1001d38 */
    ++lpPe; /* Line 170, Address: 0x1001d40 */
  } /* Line 171, Address: 0x1001d44 */
  FadeCount = 0; /* Line 172, Address: 0x1001d60 */
  *lpFadeFlag = 1; /* Line 173, Address: 0x1001d68 */

} /* Line 175, Address: 0x1001d78 */



int fadein0_new() { /* Line 179, Address: 0x1001d90 */

  int_flg = 18; /* Line 181, Address: 0x1001d98 */

  fadein1(); /* Line 183, Address: 0x1001da4 */


  if (++FadeCount >= 22) { /* Line 186, Address: 0x1001dac */
    FadeCount = 0; /* Line 187, Address: 0x1001dcc */
    return 1; /* Line 188, Address: 0x1001dd4 */
  }
  return 0; /* Line 190, Address: 0x1001de0 */
} /* Line 191, Address: 0x1001de4 */


static void fadein1() { /* Line 194, Address: 0x1001e00 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 198, Address: 0x1001e14 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 199, Address: 0x1001e48 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 201, Address: 0x1001e7c */
    fadein2(lpPe, lpPe2); /* Line 202, Address: 0x1001e88 */
    ++lpPe; /* Line 203, Address: 0x1001e98 */
    ++lpPe2; /* Line 204, Address: 0x1001e9c */
  } /* Line 205, Address: 0x1001ea0 */
  if (stageno.b.h == 1) return; /* Line 206, Address: 0x1001ebc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 208, Address: 0x1001ed8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 209, Address: 0x1001f0c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 211, Address: 0x1001f40 */
    fadein2(lpPe, lpPe2); /* Line 212, Address: 0x1001f4c */
    ++lpPe; /* Line 213, Address: 0x1001f5c */
    ++lpPe2; /* Line 214, Address: 0x1001f60 */
  } /* Line 215, Address: 0x1001f64 */



} /* Line 219, Address: 0x1001f80 */




static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 224, Address: 0x1001fa0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 225, Address: 0x1001fac */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 228, Address: 0x100200c */
      lpPeDest->peBlue += 32; /* Line 229, Address: 0x1002030 */
    } /* Line 230, Address: 0x1002040 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 231, Address: 0x1002048 */
      lpPeDest->peGreen += 32; /* Line 232, Address: 0x100206c */
    } /* Line 233, Address: 0x100207c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 234, Address: 0x1002084 */
      lpPeDest->peRed += 32; /* Line 235, Address: 0x10020a8 */
    }
  }

} /* Line 239, Address: 0x10020bc */


void fadeout() {
  startcolor = 0;
  colorcnt = 63; /* Line 244, Address: 0x10020d8 */

  FadeCount = 0; /* Line 246, Address: 0x10020e4 */
  *lpFadeFlag = 2; /* Line 247, Address: 0x10020ec */

} /* Line 249, Address: 0x10020fc */



static int fadeout_new() { /* Line 253, Address: 0x1002110 */

  int_flg = 18; /* Line 255, Address: 0x1002118 */

  fadeout1(); /* Line 257, Address: 0x1002124 */


  if (++FadeCount >= 22) { /* Line 260, Address: 0x100212c */
    FadeCount = 0; /* Line 261, Address: 0x100214c */
    return 1; /* Line 262, Address: 0x1002154 */
  }
  return 0; /* Line 264, Address: 0x1002160 */
} /* Line 265, Address: 0x1002164 */


static void fadeout1() { /* Line 268, Address: 0x1002180 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 272, Address: 0x1002190 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 274, Address: 0x10021c4 */
    fadeout2(lpPe); /* Line 275, Address: 0x10021d0 */
    ++lpPe; /* Line 276, Address: 0x10021dc */
  } /* Line 277, Address: 0x10021e0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 278, Address: 0x10021fc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 280, Address: 0x1002230 */
    fadeout2(lpPe); /* Line 281, Address: 0x100223c */
    ++lpPe; /* Line 282, Address: 0x1002248 */
  } /* Line 283, Address: 0x100224c */


} /* Line 286, Address: 0x1002268 */



static void fadeout2(palette_entry* lpPeDest) { /* Line 290, Address: 0x1002280 */
  if (lpPeDest->peRed) { /* Line 291, Address: 0x1002288 */
    lpPeDest->peRed -= 32; /* Line 292, Address: 0x1002298 */
  } /* Line 293, Address: 0x10022ac */
  else if (lpPeDest->peGreen) { /* Line 294, Address: 0x10022b4 */
    lpPeDest->peGreen -= 32; /* Line 295, Address: 0x10022c4 */
  } /* Line 296, Address: 0x10022d4 */
  else if (lpPeDest->peBlue) { /* Line 297, Address: 0x10022dc */
    lpPeDest->peBlue -= 32; /* Line 298, Address: 0x10022ec */
  }

} /* Line 301, Address: 0x10022fc */


void flashin() { /* Line 304, Address: 0x1002310 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 308, Address: 0x100231c */
  colorcnt = 63; /* Line 309, Address: 0x1002324 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 311, Address: 0x1002330 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 313, Address: 0x1002364 */
    lpPe->peRed = 224; /* Line 314, Address: 0x1002370 */
    lpPe->peGreen = 224; /* Line 315, Address: 0x1002378 */
    lpPe->peBlue = 224; /* Line 316, Address: 0x1002380 */
    lpPe->peFlags = 1; /* Line 317, Address: 0x1002388 */
    ++lpPe; /* Line 318, Address: 0x1002390 */
  } /* Line 319, Address: 0x1002394 */
  FadeCount = 0; /* Line 320, Address: 0x10023b0 */
  *lpFadeFlag = 3; /* Line 321, Address: 0x10023b8 */

} /* Line 323, Address: 0x10023c8 */


static int flashin_new() { /* Line 326, Address: 0x10023e0 */

  int_flg = 18; /* Line 328, Address: 0x10023e8 */

  flashin1(); /* Line 330, Address: 0x10023f4 */


  if (++FadeCount >= 22) { /* Line 333, Address: 0x10023fc */
    FadeCount = 0; /* Line 334, Address: 0x100241c */
    return 1; /* Line 335, Address: 0x1002424 */
  }
  return 0; /* Line 337, Address: 0x1002430 */
} /* Line 338, Address: 0x1002434 */


static void flashin1() { /* Line 341, Address: 0x1002450 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 345, Address: 0x1002464 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 346, Address: 0x1002498 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 348, Address: 0x10024cc */
    flashin2(lpPe, lpPe2); /* Line 349, Address: 0x10024d8 */
    ++lpPe; /* Line 350, Address: 0x10024e8 */
    ++lpPe2; /* Line 351, Address: 0x10024ec */
  } /* Line 352, Address: 0x10024f0 */
  if (stageno.b.h == 1) return; /* Line 353, Address: 0x100250c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 355, Address: 0x1002528 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 356, Address: 0x100255c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 358, Address: 0x1002590 */
    flashin2(lpPe, lpPe2); /* Line 359, Address: 0x100259c */
    ++lpPe; /* Line 360, Address: 0x10025ac */
    ++lpPe2; /* Line 361, Address: 0x10025b0 */
  } /* Line 362, Address: 0x10025b4 */



} /* Line 366, Address: 0x10025d0 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 370, Address: 0x10025f0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 371, Address: 0x10025fc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 374, Address: 0x100265c */
      lpPeDest->peBlue -= 32; /* Line 375, Address: 0x1002680 */
    } /* Line 376, Address: 0x1002690 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 377, Address: 0x1002698 */
      lpPeDest->peGreen -= 32; /* Line 378, Address: 0x10026bc */
    } /* Line 379, Address: 0x10026cc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 380, Address: 0x10026d4 */
      lpPeDest->peRed -= 32; /* Line 381, Address: 0x10026f8 */
    }
  }

} /* Line 385, Address: 0x100270c */


void flashout() {
  startcolor = 0;
  colorcnt = 63; /* Line 390, Address: 0x1002728 */

  FadeCount = 0; /* Line 392, Address: 0x1002734 */
  *lpFadeFlag = 4; /* Line 393, Address: 0x100273c */

} /* Line 395, Address: 0x100274c */


static int flashout_new() { /* Line 398, Address: 0x1002760 */

  int_flg = 18; /* Line 400, Address: 0x1002768 */

  flashout1(); /* Line 402, Address: 0x1002774 */


  if (++FadeCount >= 22) { /* Line 405, Address: 0x100277c */
    FadeCount = 0; /* Line 406, Address: 0x100279c */
    return 1; /* Line 407, Address: 0x10027a4 */
  }
  return 0; /* Line 409, Address: 0x10027b0 */
} /* Line 410, Address: 0x10027b4 */


static void flashout1() { /* Line 413, Address: 0x10027d0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 417, Address: 0x10027e0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 419, Address: 0x1002814 */
    flashout2(lpPe); /* Line 420, Address: 0x1002820 */
    ++lpPe; /* Line 421, Address: 0x100282c */
  } /* Line 422, Address: 0x1002830 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 423, Address: 0x100284c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 425, Address: 0x1002880 */
    flashout2(lpPe); /* Line 426, Address: 0x100288c */
    ++lpPe; /* Line 427, Address: 0x1002898 */
  } /* Line 428, Address: 0x100289c */


} /* Line 431, Address: 0x10028b8 */



static void flashout2(palette_entry* lpPeDest) { /* Line 435, Address: 0x10028d0 */
  if (lpPeDest->peRed != 224) { /* Line 436, Address: 0x10028d8 */
    lpPeDest->peRed += 32; /* Line 437, Address: 0x10028f0 */
  } /* Line 438, Address: 0x1002904 */
  else if (lpPeDest->peGreen != 224) { /* Line 439, Address: 0x100290c */
    lpPeDest->peGreen += 32; /* Line 440, Address: 0x1002924 */
  } /* Line 441, Address: 0x1002934 */
  else if (lpPeDest->peBlue != 224) { /* Line 442, Address: 0x100293c */
    lpPeDest->peBlue += 32; /* Line 443, Address: 0x1002954 */
  }


} /* Line 447, Address: 0x1002964 */


void colorset(int ColorNo) { /* Line 450, Address: 0x1002970 */
  colorset00(ColorNo, 1); /* Line 451, Address: 0x100297c */
} /* Line 452, Address: 0x100298c */

void colorset2(int ColorNo) { /* Line 454, Address: 0x10029a0 */
  colorset00(ColorNo, 0); /* Line 455, Address: 0x10029ac */
} /* Line 456, Address: 0x10029bc */

void colorset3(int ColorNo) { /* Line 458, Address: 0x10029d0 */
  colorset00(ColorNo, 2); /* Line 459, Address: 0x10029dc */
} /* Line 460, Address: 0x10029ec */




static void colorset00(int ColorNo, int WorkOffs) { /* Line 465, Address: 0x1002a00 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 470, Address: 0x1002a20 */
    case 0:
      lppe = lpcolorwk; break; /* Line 472, Address: 0x1002a88 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 474, Address: 0x1002a98 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 476, Address: 0x1002aa8 */
    default:
      lppe = lpcolorwk4; break; /* Line 478, Address: 0x1002ab8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 481, Address: 0x1002ac0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 482, Address: 0x1002ad8 */
  n = colortbl[ColorNo].cnt; /* Line 483, Address: 0x1002b00 */
  for (i = 0; i < n; ++i) { /* Line 484, Address: 0x1002b20 */
    *lpPeDest++ = *lpPeSrc++; /* Line 485, Address: 0x1002b2c */
  } /* Line 486, Address: 0x1002b5c */

} /* Line 488, Address: 0x1002b6c */


int FadeProc() { /* Line 491, Address: 0x1002b90 */
  switch (*lpFadeFlag) { /* Line 492, Address: 0x1002b98 */
    case 1:
      return fadein0_new(); /* Line 494, Address: 0x1002bdc */
    case 2:
      return fadeout_new(); /* Line 496, Address: 0x1002bec */
    case 3:
      return flashin_new(); /* Line 498, Address: 0x1002bfc */
    case 4:
      return flashout_new(); /* Line 500, Address: 0x1002c0c */
  }
  return 1; /* Line 502, Address: 0x1002c1c */

} /* Line 504, Address: 0x1002c20 */
