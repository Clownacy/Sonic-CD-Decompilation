#include "..\EQU.H"
#include "COL4A.H"

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
  {   0,   0,   0, 1 }, {  32,  32,  32, 1 }, {   0,  96, 224, 1 }, {  32, 128, 224, 1 },
  {  64, 160, 224, 1 }, {  96, 192, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 192, 224, 160, 1 }, { 128, 160,  96, 1 },
  { 192,  96,  64, 1 }, { 128,  64,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  32,   0,  32, 1 }, { 224, 224, 224, 1 }, {   0,   0,  32, 1 }, {  32, 224, 224, 1 },
  {  64,   0,  96, 1 }, {  96,   0, 160, 1 }, { 160,  96, 224, 1 }, {   0,  32,   0, 1 },
  {   0, 128,  32, 1 }, {   0, 192,  64, 1 }, { 160, 224,  96, 1 }, {  32,  32,   0, 1 },
  {  96,  96,   0, 1 }, { 160, 160,   0, 1 }, { 224, 224,  96, 1 }, { 224, 224, 128, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 160, 192, 224, 1 }, { 128, 160, 224, 1 },
  {  96, 128, 224, 1 }, {   0,   0,   0, 1 }, {   0, 160, 128, 1 }, {  96,  64,  96, 1 },
  { 160, 128, 160, 1 }, { 224, 224, 224, 1 }, {   0,  64,  32, 1 }, {   0,   0,  32, 1 },
  {   0,  32,   0, 1 }, {   0,  64,  32, 1 }, {   0,  96,  64, 1 }, {   0, 128,  96, 1 }
};
palette_entry advacolor2[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {  64,  96, 224, 1 }, {  96,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 128,   0, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0, 224, 128, 1 }, {   0, 128,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {  32,   0,  32, 1 }, { 192, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0, 224, 224, 1 },
  {  64,   0,  32, 1 }, { 160,   0,  96, 1 }, { 224,  64, 224, 1 }, {   0,   0,  32, 1 },
  {  64,  32, 160, 1 }, {  64, 128, 224, 1 }, { 128, 192, 224, 1 }, {  96,  32,   0, 1 },
  { 128,  64,   0, 1 }, { 192, 128,   0, 1 }, { 224, 160,   0, 1 }, { 224, 224,   0, 1 },
  {  32,   0,  32, 1 }, { 224, 192, 160, 1 }, { 224, 128,   0, 1 }, { 128,  32,   0, 1 },
  {  64,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 },
  { 224, 128,   0, 1 }, { 160,   0,  96, 1 }, {  64,   0,  32, 1 }, {  32,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  96,  64,  64, 1 }, { 128,  96,  96, 1 }
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
  {  32,   0,  32, 1 }, { 192, 224, 224, 1 }, {   0,   0,   0, 1 }, {   0, 224, 224, 1 },
  {  64,   0,  32, 1 }, { 160,   0,  96, 1 }, { 224,  64, 224, 1 }, {   0,   0,  32, 1 },
  {  64,  32, 160, 1 }, {  64, 128, 224, 1 }, { 128, 192, 224, 1 }, {  96,  32,   0, 1 },
  { 128,  64,   0, 1 }, { 192, 128,   0, 1 }, { 224, 160,   0, 1 }, { 224, 224,   0, 1 },
  {  32,   0,  32, 1 }, { 224, 192, 160, 1 }, { 224, 128,   0, 1 }, { 128,  32,   0, 1 },
  {  64,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 },
  { 224, 128,   0, 1 }, { 160,   0,  96, 1 }, {  64,   0,  32, 1 }, {  32,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,   0,   0, 1 }, {  96,  64,  64, 1 }, { 128,  96,  96, 1 }
};
palette_part colortbl[5] = {
  { advacolor, 0, 64 },
  { advacolor, 0, 64 },
  { advacolor2, 0, 64 },
  { gamecolor, 0, 16 },
  { zone4colora, 16, 48 }
};
unsigned char col4a0cnt[18] = { 32, 8, 60, 0, 8, 1, 8, 2, 8, 3, 8, 3, 8, 0, 6, 0, 6, 0 };
palette_entry col4a0col[4] = {
  {  32,   0,   0, 1 }, { 160,  64,   0, 1 }, { 128,  32,   0, 1 }, {  64,   0,   0, 1 }
};
unsigned char col4a1cnt[18] = { 50, 8, 60, 0, 8, 1, 8, 2, 8, 3, 8, 4, 8, 0, 6, 0, 6, 0 };
palette_entry col4a1col[5] = {
  {   0, 128, 160, 1 }, { 224,  64, 160, 1 }, { 192, 128, 224, 1 }, { 128,  64, 160, 1 },
  {   0,  96, 160, 1 }
};
unsigned char col4a2cnt[18] = { 51, 8, 60, 0, 8, 1, 8, 2, 8, 3, 8, 3, 8, 0, 6, 0, 6, 0 };
palette_entry col4a2col[4] = {
  {   0,  32,  96, 1 }, { 128,   0,  64, 1 }, { 128,  64, 160, 1 }, {  64,  32,  96, 1 }
};
unsigned char col4a3cnt[18] = { 52, 8, 60, 0, 8, 1, 8, 2, 8, 3, 8, 4, 8, 0, 6, 0, 6, 0 };
palette_entry col4a3col[5] = {
  {   0,  96, 160, 1 }, { 192,  32, 128, 1 }, { 160,  96, 192, 1 }, {  96,  32, 128, 1 },
  {  32,  64, 128, 1 }
};
unsigned char col4a4cnt[18] = { 57, 8, 60, 0, 8, 1, 8, 1, 8, 0, 8, 0, 8, 0, 6, 0, 6, 0 };
palette_entry col4a4col[2] = {
  { 192,  64,  96, 1 }, { 192,  96,  96, 1 }
};
unsigned char col4a5cnt[18] = { 58, 8, 60, 0, 8, 1, 8, 1, 8, 0, 8, 0, 8, 0, 6, 0, 6, 0 };
palette_entry col4a5col[2] = {
  { 128, 0, 64, 1 }, { 160, 32, 64, 1 }
};
unsigned char col4a6cnt[10] = { 49, 4, 2, 0, 2, 1, 2, 2, 2, 3 };
unsigned char col4a7cnt[10] = { 50, 4, 2, 1, 2, 2, 2, 3, 2, 0 };
unsigned char col4a8cnt[10] = { 51, 4, 2, 2, 2, 3, 2, 0, 2, 1 };
unsigned char col4a9cnt[10] = { 52, 4, 2, 3, 2, 0, 2, 1, 2, 2 };
palette_entry col4a6col[4] = {
  { 224, 224, 224, 1 }, { 160, 192, 224, 1 }, { 128, 160, 224, 1 }, {  96, 128, 224, 1 }
};
static int FadeCount;



































































void clchgctr() { /* Line 181, Address: 0x1015640 */
  if (stageno.b.l) goto label1; /* Line 182, Address: 0x1015648 */
  if ((unsigned short)scra_h_posit.w.h >= 640) goto label1; /* Line 183, Address: 0x1015658 */
  if ((unsigned short)scra_v_posit.w.h >= 352) { /* Line 184, Address: 0x1015674 */
    if (clchgtim[4] & 128) { /* Line 185, Address: 0x1015690 */

      clchgtim[4] |= 128; /* Line 187, Address: 0x10156a8 */
      goto label1; /* Line 188, Address: 0x10156bc */
    }
    clchgtim[4] |= 128; /* Line 190, Address: 0x10156c4 */
    colorset2(4); /* Line 191, Address: 0x10156d8 */
label1:
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4a6cnt, col4a6col); /* Line 193, Address: 0x10156e4 */
    clchg_sub0(&clchgtim[1], &clchgcnt[1], col4a7cnt, col4a6col); /* Line 194, Address: 0x101570c */
    clchg_sub0(&clchgtim[2], &clchgcnt[2], col4a8cnt, col4a6col); /* Line 195, Address: 0x1015734 */
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col4a9cnt, col4a6col); /* Line 196, Address: 0x101575c */
  } /* Line 197, Address: 0x1015784 */
  else {
    clchg_sub0(&clchgtim[0], &clchgcnt[0], col4a0cnt, col4a0col); /* Line 199, Address: 0x101578c */
    clchg_sub0(&clchgtim[1], &clchgcnt[1], col4a1cnt, col4a1col); /* Line 200, Address: 0x10157b4 */
    clchg_sub0(&clchgtim[2], &clchgcnt[2], col4a2cnt, col4a2col); /* Line 201, Address: 0x10157dc */
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col4a3cnt, col4a3col); /* Line 202, Address: 0x1015804 */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col4a4cnt, col4a4col); /* Line 203, Address: 0x101582c */
    clchg_sub0(&clchgtim[5], &clchgcnt[5], col4a5cnt, col4a5col); /* Line 204, Address: 0x1015854 */
  }
} /* Line 206, Address: 0x101587c */







void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 214, Address: 0x1015890 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 217, Address: 0x10158a8 */
  if ((char)*pChgTime < 0) { /* Line 218, Address: 0x10158bc */
    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 219, Address: 0x10158dc */
    ++*pChgCnt; /* Line 220, Address: 0x1015900 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 221, Address: 0x1015914 */
      *pChgCnt = 0; /* Line 222, Address: 0x1015940 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 225, Address: 0x1015948 */
    *pChgTime = pCntTbl[0]; /* Line 226, Address: 0x1015964 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 227, Address: 0x1015974 */
  }





} /* Line 234, Address: 0x10159ac */


void fadein0() { /* Line 237, Address: 0x10159c0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 241, Address: 0x10159cc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 243, Address: 0x1015a00 */
    lpPe->peRed = 0; /* Line 244, Address: 0x1015a0c */
    lpPe->peGreen = 0; /* Line 245, Address: 0x1015a10 */
    lpPe->peBlue = 0; /* Line 246, Address: 0x1015a14 */
    lpPe->peFlags = 1; /* Line 247, Address: 0x1015a18 */
    ++lpPe; /* Line 248, Address: 0x1015a20 */
  } /* Line 249, Address: 0x1015a24 */
  FadeCount = 0; /* Line 250, Address: 0x1015a40 */
  *lpFadeFlag = 1; /* Line 251, Address: 0x1015a48 */

} /* Line 253, Address: 0x1015a58 */



int fadein0_new() { /* Line 257, Address: 0x1015a70 */

  int_flg = 18; /* Line 259, Address: 0x1015a78 */

  fadein1(); /* Line 261, Address: 0x1015a84 */


  if (++FadeCount > 21) { /* Line 264, Address: 0x1015a8c */
    FadeCount = 0; /* Line 265, Address: 0x1015aac */
    return 1; /* Line 266, Address: 0x1015ab4 */
  }
  return 0; /* Line 268, Address: 0x1015ac0 */
} /* Line 269, Address: 0x1015ac4 */


static void fadein1() { /* Line 272, Address: 0x1015ae0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 276, Address: 0x1015af4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 277, Address: 0x1015b28 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 279, Address: 0x1015b5c */
    fadein2(lpPe, lpPe2); /* Line 280, Address: 0x1015b68 */
    ++lpPe; /* Line 281, Address: 0x1015b78 */
    ++lpPe2; /* Line 282, Address: 0x1015b7c */
  } /* Line 283, Address: 0x1015b80 */
  if (stageno.b.h == 1) return; /* Line 284, Address: 0x1015b9c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 286, Address: 0x1015bb8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 287, Address: 0x1015bec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 289, Address: 0x1015c20 */
    fadein2(lpPe, lpPe2); /* Line 290, Address: 0x1015c2c */
    ++lpPe; /* Line 291, Address: 0x1015c3c */
    ++lpPe2; /* Line 292, Address: 0x1015c40 */
  } /* Line 293, Address: 0x1015c44 */



} /* Line 297, Address: 0x1015c60 */




static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 302, Address: 0x1015c80 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 303, Address: 0x1015c8c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 306, Address: 0x1015cec */
      lpPeDest->peBlue += 32; /* Line 307, Address: 0x1015d10 */
    } /* Line 308, Address: 0x1015d20 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 309, Address: 0x1015d28 */
      lpPeDest->peGreen += 32; /* Line 310, Address: 0x1015d4c */
    } /* Line 311, Address: 0x1015d5c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 312, Address: 0x1015d64 */
      lpPeDest->peRed += 32; /* Line 313, Address: 0x1015d88 */
    }
  }

} /* Line 317, Address: 0x1015d9c */


void fadeout() {
  startcolor = 0; /* Line 321, Address: 0x1015db0 */
  colorcnt = 63; /* Line 322, Address: 0x1015db8 */

  FadeCount = 0; /* Line 324, Address: 0x1015dc4 */
  *lpFadeFlag = 2; /* Line 325, Address: 0x1015dcc */

} /* Line 327, Address: 0x1015ddc */



static int fadeout_new() { /* Line 331, Address: 0x1015df0 */

  int_flg = 18; /* Line 333, Address: 0x1015df8 */

  fadeout1(); /* Line 335, Address: 0x1015e04 */


  if (++FadeCount > 21) { /* Line 338, Address: 0x1015e0c */
    FadeCount = 0; /* Line 339, Address: 0x1015e2c */
    return 1; /* Line 340, Address: 0x1015e34 */
  }
  return 0; /* Line 342, Address: 0x1015e40 */
} /* Line 343, Address: 0x1015e44 */


static void fadeout1() { /* Line 346, Address: 0x1015e60 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 350, Address: 0x1015e70 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 352, Address: 0x1015ea4 */
    fadeout2(lpPe); /* Line 353, Address: 0x1015eb0 */
    ++lpPe; /* Line 354, Address: 0x1015ebc */
  } /* Line 355, Address: 0x1015ec0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 356, Address: 0x1015edc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 358, Address: 0x1015f10 */
    fadeout2(lpPe); /* Line 359, Address: 0x1015f1c */
    ++lpPe; /* Line 360, Address: 0x1015f28 */
  } /* Line 361, Address: 0x1015f2c */


} /* Line 364, Address: 0x1015f48 */



static void fadeout2(palette_entry* lpPeDest) { /* Line 368, Address: 0x1015f60 */
  if (lpPeDest->peRed) { /* Line 369, Address: 0x1015f68 */
    lpPeDest->peRed -= 32; /* Line 370, Address: 0x1015f78 */
  } /* Line 371, Address: 0x1015f8c */
  else if (lpPeDest->peGreen) { /* Line 372, Address: 0x1015f94 */
    lpPeDest->peGreen -= 32; /* Line 373, Address: 0x1015fa4 */
  } /* Line 374, Address: 0x1015fb4 */
  else if (lpPeDest->peBlue) { /* Line 375, Address: 0x1015fbc */
    lpPeDest->peBlue -= 32; /* Line 376, Address: 0x1015fcc */
  }

} /* Line 379, Address: 0x1015fdc */


void flashin() { /* Line 382, Address: 0x1015ff0 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 386, Address: 0x1015ffc */
  colorcnt = 63; /* Line 387, Address: 0x1016004 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 389, Address: 0x1016010 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 391, Address: 0x1016044 */
    lpPe->peRed = 224; /* Line 392, Address: 0x1016050 */
    lpPe->peGreen = 224; /* Line 393, Address: 0x1016058 */
    lpPe->peBlue = 224; /* Line 394, Address: 0x1016060 */
    lpPe->peFlags = 1; /* Line 395, Address: 0x1016068 */
    ++lpPe; /* Line 396, Address: 0x1016070 */
  } /* Line 397, Address: 0x1016074 */
  FadeCount = 0; /* Line 398, Address: 0x1016090 */
  *lpFadeFlag = 3; /* Line 399, Address: 0x1016098 */

} /* Line 401, Address: 0x10160a8 */


static int flashin_new() { /* Line 404, Address: 0x10160c0 */

  int_flg = 18; /* Line 406, Address: 0x10160c8 */

  flashin1(); /* Line 408, Address: 0x10160d4 */


  if (++FadeCount > 21) { /* Line 411, Address: 0x10160dc */
    FadeCount = 0; /* Line 412, Address: 0x10160fc */
    return 1; /* Line 413, Address: 0x1016104 */
  }
  return 0; /* Line 415, Address: 0x1016110 */
} /* Line 416, Address: 0x1016114 */


static void flashin1() { /* Line 419, Address: 0x1016130 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 423, Address: 0x1016144 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 424, Address: 0x1016178 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 426, Address: 0x10161ac */
    flashin2(lpPe, lpPe2); /* Line 427, Address: 0x10161b8 */
    ++lpPe; /* Line 428, Address: 0x10161c8 */
    ++lpPe2; /* Line 429, Address: 0x10161cc */
  } /* Line 430, Address: 0x10161d0 */
  if (stageno.b.h == 1) return; /* Line 431, Address: 0x10161ec */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 433, Address: 0x1016208 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 434, Address: 0x101623c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 436, Address: 0x1016270 */
    flashin2(lpPe, lpPe2); /* Line 437, Address: 0x101627c */
    ++lpPe; /* Line 438, Address: 0x101628c */
    ++lpPe2; /* Line 439, Address: 0x1016290 */
  } /* Line 440, Address: 0x1016294 */



} /* Line 444, Address: 0x10162b0 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 448, Address: 0x10162d0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 449, Address: 0x10162dc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 452, Address: 0x101633c */
      lpPeDest->peBlue -= 32; /* Line 453, Address: 0x1016360 */
    } /* Line 454, Address: 0x1016370 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 455, Address: 0x1016378 */
      lpPeDest->peGreen -= 32; /* Line 456, Address: 0x101639c */
    } /* Line 457, Address: 0x10163ac */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 458, Address: 0x10163b4 */
      lpPeDest->peRed -= 32; /* Line 459, Address: 0x10163d8 */
    }
  }

} /* Line 463, Address: 0x10163ec */


void flashout() {
  startcolor = 0; /* Line 467, Address: 0x1016400 */
  colorcnt = 63; /* Line 468, Address: 0x1016408 */

  FadeCount = 0; /* Line 470, Address: 0x1016414 */
  *lpFadeFlag = 4; /* Line 471, Address: 0x101641c */

} /* Line 473, Address: 0x101642c */


static int flashout_new() { /* Line 476, Address: 0x1016440 */

  int_flg = 18; /* Line 478, Address: 0x1016448 */

  flashout1(); /* Line 480, Address: 0x1016454 */


  if (++FadeCount > 21) { /* Line 483, Address: 0x101645c */
    FadeCount = 0; /* Line 484, Address: 0x101647c */
    return 1; /* Line 485, Address: 0x1016484 */
  }
  return 0; /* Line 487, Address: 0x1016490 */
} /* Line 488, Address: 0x1016494 */


static void flashout1() { /* Line 491, Address: 0x10164b0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 495, Address: 0x10164c0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 497, Address: 0x10164f4 */
    flashout2(lpPe); /* Line 498, Address: 0x1016500 */
    ++lpPe; /* Line 499, Address: 0x101650c */
  } /* Line 500, Address: 0x1016510 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 501, Address: 0x101652c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 503, Address: 0x1016560 */
    flashout2(lpPe); /* Line 504, Address: 0x101656c */
    ++lpPe; /* Line 505, Address: 0x1016578 */
  } /* Line 506, Address: 0x101657c */


} /* Line 509, Address: 0x1016598 */



static void flashout2(palette_entry* lpPeDest) { /* Line 513, Address: 0x10165b0 */
  if (lpPeDest->peRed != 224) { /* Line 514, Address: 0x10165b8 */
    lpPeDest->peRed += 32; /* Line 515, Address: 0x10165d0 */
  } /* Line 516, Address: 0x10165e4 */
  else if (lpPeDest->peGreen != 224) { /* Line 517, Address: 0x10165ec */
    lpPeDest->peGreen += 32; /* Line 518, Address: 0x1016604 */
  } /* Line 519, Address: 0x1016614 */
  else if (lpPeDest->peBlue != 224) { /* Line 520, Address: 0x101661c */
    lpPeDest->peBlue += 32; /* Line 521, Address: 0x1016634 */
  }


} /* Line 525, Address: 0x1016644 */


void colorset(int ColorNo) { /* Line 528, Address: 0x1016650 */
  colorset00(ColorNo, 1); /* Line 529, Address: 0x101665c */
} /* Line 530, Address: 0x101666c */

void colorset2(int ColorNo) { /* Line 532, Address: 0x1016680 */
  colorset00(ColorNo, 0); /* Line 533, Address: 0x101668c */
} /* Line 534, Address: 0x101669c */

void colorset3(int ColorNo) { /* Line 536, Address: 0x10166b0 */
  colorset00(ColorNo, 2); /* Line 537, Address: 0x10166bc */
} /* Line 538, Address: 0x10166cc */




static void colorset00(int ColorNo, int WorkOffs) { /* Line 543, Address: 0x10166e0 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 548, Address: 0x1016700 */
    case 0:
      lppe = lpcolorwk; break; /* Line 550, Address: 0x1016768 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 552, Address: 0x1016778 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 554, Address: 0x1016788 */
    default:
      lppe = lpcolorwk4; break; /* Line 556, Address: 0x1016798 */
  }
  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 558, Address: 0x10167a0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 559, Address: 0x10167b8 */
  n = colortbl[ColorNo].cnt; /* Line 560, Address: 0x10167e0 */
  for (i = 0; i < n; ++i) { /* Line 561, Address: 0x1016800 */
    *lpPeDest++ = *lpPeSrc++; /* Line 562, Address: 0x101680c */
  } /* Line 563, Address: 0x101683c */

} /* Line 565, Address: 0x101684c */


int FadeProc() { /* Line 568, Address: 0x1016870 */
  switch (*lpFadeFlag) { /* Line 569, Address: 0x1016878 */
    case 1:
      return fadein0_new(); /* Line 571, Address: 0x10168bc */
    case 2:
      return fadeout_new(); /* Line 573, Address: 0x10168cc */
    case 3:
      return flashin_new(); /* Line 575, Address: 0x10168dc */
    case 4:
      return flashout_new(); /* Line 577, Address: 0x10168ec */
  }
  return 1; /* Line 579, Address: 0x10168fc */

} /* Line 581, Address: 0x1016900 */
