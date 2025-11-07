#include "..\EQU.H"
#include "COL6C.H"

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

unsigned char col6a0cnt[8] = { 33, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a0col[3] = { { 224, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  64,   0, 1 } };
unsigned char col6a1cnt[8] = { 34, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a1col[3] = { {   0, 192,   0, 1 }, {   0,  64,   0, 1 }, { 224, 224,   0, 1 } };
unsigned char col6a2cnt[8] = { 35, 3, 1, 0, 1, 1, 1, 2 };
PALETTEENTRY col6a2col[3] = { {   0,  64,   0, 1 }, { 224, 224,   0, 1 }, {   0, 192,   0, 1 } };
unsigned char col6a3cnt[14] = { 49, 6, 1, 1, 1, 0, 1, 2, 1, 0, 1, 3, 1, 0 };
PALETTEENTRY col6a3col[4] = { {   0,   0,   0, 1 }, {  64,   0, 224, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 } };
PALETTEENTRY col6a3col_stop[4] = { {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 } };
PALETTEENTRY advacolor[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  64,   0, 1 },
  { 224, 160,   0, 1 }, {  64,   0, 192, 1 }, {   0, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 192, 1 }, {  96, 224, 224, 1 }, {   0, 160, 224, 1 }, {   0,  32, 224, 1 },
  {   0,   0,  64, 1 }, {  96,  32, 224, 1 }, { 224, 128, 224, 1 }, { 224, 192, 192, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {   0,  32,  32, 1 }, {   0,  32,  32, 1 },
  {   0,  32,  32, 1 }, { 192, 224,  64, 1 }, { 224, 224, 224, 1 }, {   0,  64,  32, 1 },
  {   0, 160,  96, 1 }, {   0, 224, 160, 1 }, {   0, 224, 224, 1 }, {   0,   0,  32, 1 },
  {  32,   0,  96, 1 }, {  64,   0, 160, 1 }, {  32,  96, 160, 1 }, {   0, 128, 224, 1 }
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
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  64,   0, 1 },
  { 224, 160,   0, 1 }, {  64,   0, 192, 1 }, {   0, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 192, 1 }, {  96, 224, 224, 1 }, {   0, 160, 224, 1 }, {   0,  32, 224, 1 },
  {   0,   0,  64, 1 }, {  96,  32, 224, 1 }, { 224, 128, 224, 1 }, { 224, 192, 192, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {   0,  32,  32, 1 }, {   0,  32,  32, 1 },
  {   0,  32,  32, 1 }, { 192, 224,  64, 1 }, { 224, 224, 224, 1 }, {   0,  64,  32, 1 },
  {   0, 160,  96, 1 }, {   0, 224, 160, 1 }, {   0, 224, 224, 1 }, {   0,   0,  32, 1 },
  {  32,   0,  96, 1 }, {  64,   0, 160, 1 }, {  32,  96, 160, 1 }, {   0, 128, 224, 1 }
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
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  64,   0, 1 },
  { 224, 160,   0, 1 }, {  64,   0, 192, 1 }, {   0, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 192, 1 }, {  96, 224, 224, 1 }, {   0, 160, 224, 1 }, {   0,  32, 224, 1 },
  {   0,   0,  64, 1 }, {  96,  32, 224, 1 }, { 224, 128, 224, 1 }, { 224, 192, 192, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {   0,  32,  32, 1 }, {   0,  32,  32, 1 },
  {   0,  32,  32, 1 }, { 192, 224,  64, 1 }, { 224, 224, 224, 1 }, {   0,  64,  32, 1 },
  {   0, 160,  96, 1 }, {   0, 224, 160, 1 }, {   0, 224, 224, 1 }, {   0,   0,  32, 1 },
  {  32,   0,  96, 1 }, {  64,   0, 160, 1 }, {  32,  96, 160, 1 }, {   0, 128, 224, 1 }
};
PALETTEENTRY zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, { 128, 128, 128, 1 },
  {   0,  64, 224, 1 }, {   0,   0, 128, 1 }, { 224, 224, 224, 1 }, {  64,  96, 224, 1 },
  {  96,   0,   0, 1 }, { 224, 128, 224, 1 }, { 224, 128,   0, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0, 192,   0, 1 }, {   0,  64,   0, 1 },
  { 224, 160,   0, 1 }, {  64,   0, 192, 1 }, {   0, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 224, 192, 1 }, {  96, 224, 224, 1 }, {   0, 160, 224, 1 }, {   0,  32, 224, 1 },
  {   0,   0,  64, 1 }, {  96,  32, 224, 1 }, { 224, 128, 224, 1 }, { 224, 192, 192, 1 },
  {   0,   0,   0, 1 }, { 128,  32, 192, 1 }, {   0,  32,  32, 1 }, {   0,  32,  32, 1 },
  {   0,  32,  32, 1 }, { 192, 224,  64, 1 }, { 224, 224, 224, 1 }, {   0,  64,  32, 1 },
  {   0, 160,  96, 1 }, {   0, 224, 160, 1 }, {   0, 224, 224, 1 }, {   0,   0,  32, 1 },
  {  32,   0,  96, 1 }, {  64,   0, 160, 1 }, {  32,  96, 160, 1 }, {   0, 128, 224, 1 }
};
PALETTEENTRY boss6col[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224,  96,   0, 1 }, { 224,   0,  96, 1 },
  {  96,  96, 128, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 160, 128, 192, 1 },
  { 128,  96, 160, 1 }, {  96,  64, 128, 1 }, {  64,  32,  96, 1 }, {  32,   0,  64, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }
};
PALETTEENTRY boss6_col4[80] = {
  {   0,   0,   0, 1 }, {   0,  64,  32, 1 }, {   0, 160,  96, 1 }, {   0, 224, 160, 1 },
  {   0, 224, 224, 1 }, {   0,   0,  32, 1 }, {  32,   0,  96, 1 }, {  64,   0, 160, 1 },
  {  32,  96, 160, 1 }, {   0, 128, 224, 1 }, {  32,  32,  32, 1 }, {  32,  96,  64, 1 },
  {  32, 192, 128, 1 }, {  32, 224, 192, 1 }, {  32, 224, 224, 1 }, {  32,  32,  64, 1 },
  {  64,  32, 128, 1 }, {  96,  32, 192, 1 }, {  64, 128, 192, 1 }, {  32, 160, 224, 1 },
  {  64,  64,  64, 1 }, {  64, 128,  96, 1 }, {  64, 224, 160, 1 }, {  64, 224, 224, 1 },
  {  64, 224, 224, 1 }, {  64,  64,  96, 1 }, {  96,  64, 160, 1 }, { 128,  64, 224, 1 },
  {  96, 160, 224, 1 }, {  64, 192, 224, 1 }, {  96,  96,  96, 1 }, {  96, 160, 128, 1 },
  {  96, 224, 192, 1 }, {  96, 224, 224, 1 }, {  96, 224, 224, 1 }, {  96,  96, 128, 1 },
  { 128,  96, 192, 1 }, { 160,  96, 224, 1 }, { 128, 192, 224, 1 }, {  96, 224, 224, 1 },
  { 128, 128, 128, 1 }, { 128, 192, 160, 1 }, { 128, 224, 224, 1 }, { 128, 224, 224, 1 },
  { 128, 224, 224, 1 }, { 128, 128, 160, 1 }, { 160, 128, 224, 1 }, { 192, 128, 224, 1 },
  { 160, 224, 224, 1 }, { 128, 224, 224, 1 }, { 160, 160, 160, 1 }, { 160, 224, 192, 1 },
  { 160, 224, 224, 1 }, { 160, 224, 224, 1 }, { 160, 224, 224, 1 }, { 160, 160, 192, 1 },
  { 192, 160, 224, 1 }, { 224, 160, 224, 1 }, { 192, 224, 224, 1 }, { 160, 224, 224, 1 },
  { 192, 192, 192, 1 }, { 192, 224, 224, 1 }, { 192, 224, 224, 1 }, { 192, 224, 224, 1 },
  { 192, 224, 224, 1 }, { 192, 192, 224, 1 }, { 224, 192, 224, 1 }, { 224, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 192, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }
};
palette_part colortbl[7] = {
  { advacolor,    0, 64 }, { advacolor,     0, 64 }, { advacolor2, 0, 64 }, { gamecolor, 0, 16 },
  { zone8colora, 16, 48 }, { zone82colora, 16, 48 }, { boss6col,  16, 16 }
};
static int FadeCount;









void clchgctr(void) { /* Line 138, Address: 0x10273b0 */
  colchg6a(); /* Line 139, Address: 0x10273b8 */
} /* Line 140, Address: 0x10273c0 */

void colchg6a(void) { /* Line 142, Address: 0x10273d0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col6a0cnt, col6a0col); /* Line 143, Address: 0x10273d8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col6a1cnt, col6a1col); /* Line 144, Address: 0x1027400 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col6a2cnt, col6a2col); /* Line 145, Address: 0x1027428 */
  if (!(bossflag & 32)) /* Line 146, Address: 0x1027450 */
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col); /* Line 147, Address: 0x1027468 */
  else
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col_stop); /* Line 149, Address: 0x1027498 */
} /* Line 150, Address: 0x10274c0 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 160, Address: 0x10274d0 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 163, Address: 0x10274e8 */
  if ((char)*pChgTime < 0) { /* Line 164, Address: 0x10274fc */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 166, Address: 0x102751c */
    ++*pChgCnt; /* Line 167, Address: 0x1027540 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 168, Address: 0x1027554 */

      *pChgCnt = 0; /* Line 170, Address: 0x1027580 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 173, Address: 0x1027588 */
    *pChgTime = pCntTbl[0]; /* Line 174, Address: 0x10275a4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 175, Address: 0x10275b4 */
  }





} /* Line 182, Address: 0x10275ec */


void fadein0(void) { /* Line 185, Address: 0x1027600 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 189, Address: 0x102760c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 191, Address: 0x1027640 */
    lpPe->peRed = 0; /* Line 192, Address: 0x102764c */
    lpPe->peGreen = 0; /* Line 193, Address: 0x1027650 */
    lpPe->peBlue = 0; /* Line 194, Address: 0x1027654 */
    lpPe->peFlags = 1; /* Line 195, Address: 0x1027658 */
    ++lpPe; /* Line 196, Address: 0x1027660 */
  } /* Line 197, Address: 0x1027664 */
  FadeCount = 0; /* Line 198, Address: 0x1027680 */
  *lpFadeFlag = 1; /* Line 199, Address: 0x1027688 */

} /* Line 201, Address: 0x1027698 */



int fadein0_new(void) { /* Line 205, Address: 0x10276b0 */

  int_flg = 18; /* Line 207, Address: 0x10276b8 */

  fadein1(); /* Line 209, Address: 0x10276c4 */


  if (++FadeCount > 21) { /* Line 212, Address: 0x10276cc */
    FadeCount = 0; /* Line 213, Address: 0x10276ec */
    return 1; /* Line 214, Address: 0x10276f4 */
  }
  return 0; /* Line 216, Address: 0x1027700 */
} /* Line 217, Address: 0x1027704 */



static void fadein1(void) { /* Line 221, Address: 0x1027720 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 225, Address: 0x1027734 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 226, Address: 0x1027768 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 228, Address: 0x102779c */
    fadein2(lpPe, lpPe2); /* Line 229, Address: 0x10277a8 */
    ++lpPe; /* Line 230, Address: 0x10277b8 */
    ++lpPe2; /* Line 231, Address: 0x10277bc */
  } /* Line 232, Address: 0x10277c0 */
  if (stageno.b.h == 1) return; /* Line 233, Address: 0x10277dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 235, Address: 0x10277f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 236, Address: 0x102782c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 238, Address: 0x1027860 */
    fadein2(lpPe, lpPe2); /* Line 239, Address: 0x102786c */
    ++lpPe; /* Line 240, Address: 0x102787c */
    ++lpPe2; /* Line 241, Address: 0x1027880 */
  } /* Line 242, Address: 0x1027884 */



} /* Line 246, Address: 0x10278a0 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 250, Address: 0x10278c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 251, Address: 0x10278cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 254, Address: 0x102792c */
      lpPeDest->peBlue += 32; /* Line 255, Address: 0x1027950 */
    } /* Line 256, Address: 0x1027960 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 257, Address: 0x1027968 */
      lpPeDest->peGreen += 32; /* Line 258, Address: 0x102798c */
    } /* Line 259, Address: 0x102799c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 260, Address: 0x10279a4 */
      lpPeDest->peRed += 32; /* Line 261, Address: 0x10279c8 */
    }
  }

} /* Line 265, Address: 0x10279dc */


void fadeout(void) {
  startcolor = 0; /* Line 269, Address: 0x10279f0 */
  colorcnt = 63; /* Line 270, Address: 0x10279f8 */

  FadeCount = 0; /* Line 272, Address: 0x1027a04 */
  *lpFadeFlag = 2; /* Line 273, Address: 0x1027a0c */

} /* Line 275, Address: 0x1027a1c */



static int fadeout_new(void) { /* Line 279, Address: 0x1027a30 */

  int_flg = 18; /* Line 281, Address: 0x1027a38 */

  fadeout1(); /* Line 283, Address: 0x1027a44 */


  if (++FadeCount > 21) { /* Line 286, Address: 0x1027a4c */
    FadeCount = 0; /* Line 287, Address: 0x1027a6c */
    return 1; /* Line 288, Address: 0x1027a74 */
  }
  return 0; /* Line 290, Address: 0x1027a80 */
} /* Line 291, Address: 0x1027a84 */


static void fadeout1(void) { /* Line 294, Address: 0x1027aa0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 298, Address: 0x1027ab0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 300, Address: 0x1027ae4 */
    fadeout2(lpPe); /* Line 301, Address: 0x1027af0 */
    ++lpPe; /* Line 302, Address: 0x1027afc */
  } /* Line 303, Address: 0x1027b00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 304, Address: 0x1027b1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 306, Address: 0x1027b50 */
    fadeout2(lpPe); /* Line 307, Address: 0x1027b5c */
    ++lpPe; /* Line 308, Address: 0x1027b68 */
  } /* Line 309, Address: 0x1027b6c */


} /* Line 312, Address: 0x1027b88 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 315, Address: 0x1027ba0 */
  if (lpPeDest->peRed) { /* Line 316, Address: 0x1027ba8 */
    lpPeDest->peRed -= 32; /* Line 317, Address: 0x1027bb8 */
  } /* Line 318, Address: 0x1027bcc */
  else if (lpPeDest->peGreen) { /* Line 319, Address: 0x1027bd4 */
    lpPeDest->peGreen -= 32; /* Line 320, Address: 0x1027be4 */
  } /* Line 321, Address: 0x1027bf4 */
  else if (lpPeDest->peBlue) { /* Line 322, Address: 0x1027bfc */
    lpPeDest->peBlue -= 32; /* Line 323, Address: 0x1027c0c */
  }

} /* Line 326, Address: 0x1027c1c */




void flashin(void) { /* Line 331, Address: 0x1027c30 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 335, Address: 0x1027c3c */
  colorcnt = 63; /* Line 336, Address: 0x1027c44 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 338, Address: 0x1027c50 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 340, Address: 0x1027c84 */
    lpPe->peRed = 224; /* Line 341, Address: 0x1027c90 */
    lpPe->peGreen = 224; /* Line 342, Address: 0x1027c98 */
    lpPe->peBlue = 224; /* Line 343, Address: 0x1027ca0 */
    lpPe->peFlags = 1; /* Line 344, Address: 0x1027ca8 */
    ++lpPe; /* Line 345, Address: 0x1027cb0 */
  } /* Line 346, Address: 0x1027cb4 */
  FadeCount = 0; /* Line 347, Address: 0x1027cd0 */
  *lpFadeFlag = 3; /* Line 348, Address: 0x1027cd8 */

} /* Line 350, Address: 0x1027ce8 */

static int flashin_new(void) { /* Line 352, Address: 0x1027d00 */
  PALETTEENTRY* lpPe;

  lpPe = &lpcolorwk[32]; /* Line 355, Address: 0x1027d0c */

  int_flg = 18; /* Line 357, Address: 0x1027d18 */

  flashin1(); /* Line 359, Address: 0x1027d24 */

  lpPe->peRed = 224; /* Line 361, Address: 0x1027d2c */
  lpPe->peGreen = 224; /* Line 362, Address: 0x1027d34 */
  lpPe->peBlue = 224; /* Line 363, Address: 0x1027d3c */
  lpPe->peFlags = 1; /* Line 364, Address: 0x1027d44 */

  if (++FadeCount > 21) { /* Line 366, Address: 0x1027d4c */
    FadeCount = 0; /* Line 367, Address: 0x1027d6c */
    return 1; /* Line 368, Address: 0x1027d74 */
  }
  return 0; /* Line 370, Address: 0x1027d80 */
} /* Line 371, Address: 0x1027d84 */

static void flashin1(void) { /* Line 373, Address: 0x1027da0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 377, Address: 0x1027db4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 378, Address: 0x1027de8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 380, Address: 0x1027e1c */
    flashin2(lpPe, lpPe2); /* Line 381, Address: 0x1027e28 */
    ++lpPe; /* Line 382, Address: 0x1027e38 */
    ++lpPe2; /* Line 383, Address: 0x1027e3c */
  } /* Line 384, Address: 0x1027e40 */
  if (stageno.b.h == 1) return; /* Line 385, Address: 0x1027e5c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 387, Address: 0x1027e78 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 388, Address: 0x1027eac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 390, Address: 0x1027ee0 */
    flashin2(lpPe, lpPe2); /* Line 391, Address: 0x1027eec */
    ++lpPe; /* Line 392, Address: 0x1027efc */
    ++lpPe2; /* Line 393, Address: 0x1027f00 */
  } /* Line 394, Address: 0x1027f04 */



} /* Line 398, Address: 0x1027f20 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 402, Address: 0x1027f40 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 403, Address: 0x1027f4c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 406, Address: 0x1027fac */
      lpPeDest->peBlue -= 32; /* Line 407, Address: 0x1027fd0 */
    } /* Line 408, Address: 0x1027fe0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 409, Address: 0x1027fe8 */
      lpPeDest->peGreen -= 32; /* Line 410, Address: 0x102800c */
    } /* Line 411, Address: 0x102801c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 412, Address: 0x1028024 */
      lpPeDest->peRed -= 32; /* Line 413, Address: 0x1028048 */
    }
  }

} /* Line 417, Address: 0x102805c */


void flashout(void) {
  startcolor = 0; /* Line 421, Address: 0x1028070 */
  colorcnt = 63; /* Line 422, Address: 0x1028078 */

  FadeCount = 0; /* Line 424, Address: 0x1028084 */
  *lpFadeFlag = 4; /* Line 425, Address: 0x102808c */

} /* Line 427, Address: 0x102809c */

static int flashout_new(void) { /* Line 429, Address: 0x10280b0 */

  int_flg = 18; /* Line 431, Address: 0x10280b8 */

  flashout1(); /* Line 433, Address: 0x10280c4 */


  if (++FadeCount > 21) { /* Line 436, Address: 0x10280cc */
    FadeCount = 0; /* Line 437, Address: 0x10280ec */
    return 1; /* Line 438, Address: 0x10280f4 */
  }
  return 0; /* Line 440, Address: 0x1028100 */
} /* Line 441, Address: 0x1028104 */


static void flashout1(void) { /* Line 444, Address: 0x1028120 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 448, Address: 0x1028130 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 450, Address: 0x1028164 */
    flashout2(lpPe); /* Line 451, Address: 0x1028170 */
    ++lpPe; /* Line 452, Address: 0x102817c */
  } /* Line 453, Address: 0x1028180 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 454, Address: 0x102819c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 456, Address: 0x10281d0 */
    flashout2(lpPe); /* Line 457, Address: 0x10281dc */
    ++lpPe; /* Line 458, Address: 0x10281e8 */
  } /* Line 459, Address: 0x10281ec */


} /* Line 462, Address: 0x1028208 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 465, Address: 0x1028220 */
  if (lpPeDest->peRed != 224) { /* Line 466, Address: 0x1028228 */
    lpPeDest->peRed += 32; /* Line 467, Address: 0x1028240 */
  } /* Line 468, Address: 0x1028254 */
  else if (lpPeDest->peGreen != 224) { /* Line 469, Address: 0x102825c */
    lpPeDest->peGreen += 32; /* Line 470, Address: 0x1028274 */
  } /* Line 471, Address: 0x1028284 */
  else if (lpPeDest->peBlue != 224) { /* Line 472, Address: 0x102828c */
    lpPeDest->peBlue += 32; /* Line 473, Address: 0x10282a4 */
  }


} /* Line 477, Address: 0x10282b4 */


void colorset(int ColorNo) { /* Line 480, Address: 0x10282c0 */
  colorset00(ColorNo, 1); /* Line 481, Address: 0x10282cc */
} /* Line 482, Address: 0x10282dc */

void colorset2(int ColorNo) { /* Line 484, Address: 0x10282f0 */
  colorset00(ColorNo, 0); /* Line 485, Address: 0x10282fc */
} /* Line 486, Address: 0x102830c */

void colorset3(int ColorNo) { /* Line 488, Address: 0x1028320 */
  colorset00(ColorNo, 0); /* Line 489, Address: 0x102832c */
} /* Line 490, Address: 0x102833c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 496, Address: 0x1028350 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 501, Address: 0x1028370 */
    case 0:
      lppe = lpcolorwk; break; /* Line 503, Address: 0x10283d8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 505, Address: 0x10283e8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 507, Address: 0x10283f8 */
    default:
      lppe = lpcolorwk4; break; /* Line 509, Address: 0x1028408 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 512, Address: 0x1028410 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 513, Address: 0x1028428 */
  n = colortbl[ColorNo].cnt; /* Line 514, Address: 0x1028450 */
  for (i = 0; i < n; ++i) { /* Line 515, Address: 0x1028470 */
    *lpPeDest++ = *lpPeSrc++; /* Line 516, Address: 0x102847c */
  } /* Line 517, Address: 0x10284ac */

} /* Line 519, Address: 0x10284bc */




int FadeProc(void) { /* Line 524, Address: 0x10284e0 */
  switch (*lpFadeFlag) { /* Line 525, Address: 0x10284e8 */
    case 1:
      return fadein0_new(); /* Line 527, Address: 0x102852c */
    case 2:
      return fadeout_new(); /* Line 529, Address: 0x102853c */
    case 3:
      return flashin_new(); /* Line 531, Address: 0x102854c */
    case 4:
      return flashout_new(); /* Line 533, Address: 0x102855c */
  }
  return 1; /* Line 535, Address: 0x102856c */

} /* Line 537, Address: 0x1028570 */











void fin_boss6(unsigned char* pChgTime, unsigned char* pChgCnt) { /* Line 549, Address: 0x1028580 */
  char d0;

  if (++*pChgTime < 12) return; /* Line 552, Address: 0x1028594 */

  *pChgTime = 0; /* Line 554, Address: 0x10285bc */
  d0 = *pChgCnt; /* Line 555, Address: 0x10285c4 */
  d0 -= 10; /* Line 556, Address: 0x10285d4 */
  if (d0 < 0) d0 = 0; /* Line 557, Address: 0x10285e0 */
  fset_boss6(d0, pChgCnt); /* Line 558, Address: 0x10285f4 */
} /* Line 559, Address: 0x1028604 */

void fout_boss6(unsigned char* pChgTime, unsigned char* pChgCnt) { /* Line 561, Address: 0x1028620 */
  unsigned char d0;

  if (++*pChgTime < 12) return; /* Line 564, Address: 0x1028634 */

  *pChgTime = 0; /* Line 566, Address: 0x102865c */
  d0 = *pChgCnt; /* Line 567, Address: 0x1028664 */
  d0 += 10; /* Line 568, Address: 0x1028670 */
  if (d0 == 80) d0 = 70; /* Line 569, Address: 0x1028678 */
  fset_boss6(d0, pChgCnt); /* Line 570, Address: 0x1028690 */
} /* Line 571, Address: 0x10286a4 */

void fset_boss6(char d0, unsigned char* pChgCnt) { /* Line 573, Address: 0x10286c0 */
  PALETTEENTRY* lpPe;

  *pChgCnt = d0; /* Line 576, Address: 0x10286d0 */
  lpPe = &lpcolorwk[32]; /* Line 577, Address: 0x10286dc */
  *lpPe++ = boss6_col4[d0++]; /* Line 578, Address: 0x10286e8 */
  lpPe = &lpcolorwk[55]; /* Line 579, Address: 0x1028734 */
  *lpPe++ = boss6_col4[d0++]; /* Line 580, Address: 0x1028740 */
  *lpPe++ = boss6_col4[d0++]; /* Line 581, Address: 0x102878c */
  *lpPe++ = boss6_col4[d0++]; /* Line 582, Address: 0x10287d8 */
  *lpPe++ = boss6_col4[d0++]; /* Line 583, Address: 0x1028824 */
  *lpPe++ = boss6_col4[d0++]; /* Line 584, Address: 0x1028870 */
  *lpPe++ = boss6_col4[d0++]; /* Line 585, Address: 0x10288bc */
  *lpPe++ = boss6_col4[d0++]; /* Line 586, Address: 0x1028908 */
  *lpPe++ = boss6_col4[d0++]; /* Line 587, Address: 0x1028954 */
  *lpPe++ = boss6_col4[d0++]; /* Line 588, Address: 0x10289a0 */
} /* Line 589, Address: 0x10289ec */




void flashin_boss6() { /* Line 594, Address: 0x1028a00 */
  short d0;
  PALETTEENTRY* lpPe;

  startcolor = 0; /* Line 598, Address: 0x1028a0c */
  colorcnt = 47; /* Line 599, Address: 0x1028a14 */
  lpPe = &lpcolorwk[startcolor >> 1]; /* Line 600, Address: 0x1028a20 */
  for (d0 = 0; d0 <= colorcnt; ++d0) { /* Line 601, Address: 0x1028a40 */

    lpPe->peRed = 224; /* Line 603, Address: 0x1028a4c */
    lpPe->peGreen = 224; /* Line 604, Address: 0x1028a54 */
    lpPe->peBlue = 224; /* Line 605, Address: 0x1028a5c */
    lpPe->peFlags = 1; /* Line 606, Address: 0x1028a64 */
    ++lpPe; /* Line 607, Address: 0x1028a6c */
  } /* Line 608, Address: 0x1028a70 */

  FadeCount = 0; /* Line 610, Address: 0x1028a9c */
  *lpFadeFlag = 3; /* Line 611, Address: 0x1028aa4 */
} /* Line 612, Address: 0x1028ab4 */
