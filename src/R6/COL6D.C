#include "..\EQU.H"
#include "COL6C.H"

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

unsigned char col6a0cnt[8] = { 33, 3, 1, 0, 1, 1, 1, 2 };
palette_entry col6a0col[3] = { { 160, 192, 160, 1 }, {  64,  96,  64, 1 }, {   0,   0,   0, 1 } };
unsigned char col6a1cnt[8] = { 34, 3, 1, 0, 1, 1, 1, 2 };
palette_entry col6a1col[3] = { {  64,  96,  64, 1 }, {   0,   0,   0, 1 }, { 160, 192, 160, 1 } };
unsigned char col6a2cnt[8] = { 35, 3, 1, 0, 1, 1, 1, 2 };
palette_entry col6a2col[3] = { {   0,   0,   0, 1 }, { 160, 192, 160, 1 }, {  64,  96,  64, 1 } };
unsigned char col6a3cnt[14] = { 49, 6, 1, 1, 1, 0, 1, 2, 1, 0, 1, 3, 1, 0 };
palette_entry col6a3col[4] = { {   0,   0,   0, 1 }, {  64,   0,  64, 1 }, { 224, 224,   0, 1 }, { 224, 224, 224, 1 } };
palette_entry col6a3col_stop[4] = { {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 } };
palette_entry advacolor[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 160, 192, 160, 1 }, {  64,  96,  64, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 192, 128,  96, 1 }, { 224, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 192, 128, 1 }, { 224,  96,   0, 1 }, { 160,  32,   0, 1 }, {  64,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  32,   0, 1 }, {  96,  64,  32, 1 }, { 160,  96,  32, 1 },
  {   0,   0,   0, 1 }, {  64,   0,  64, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32, 128, 1 }, {  64,   0,  96, 1 }, {  32,   0,  64, 1 },
  { 128,  32, 128, 1 }, { 160,  96, 160, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 },
  {   0,  32,  32, 1 }, {  64,  64,  32, 1 }, {  96, 128,   0, 1 }, { 224, 160,  32, 1 }
};
palette_entry advacolor2[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 160, 192, 160, 1 }, {  64,  96,  64, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 192, 128,  96, 1 }, { 224, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 192, 128, 1 }, { 224,  96,   0, 1 }, { 160,  32,   0, 1 }, {  64,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  32,   0, 1 }, {  96,  64,  32, 1 }, { 160,  96,  32, 1 },
  {   0,   0,   0, 1 }, {  64,   0,  64, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32, 128, 1 }, {  64,   0,  96, 1 }, {  32,   0,  64, 1 },
  { 128,  32, 128, 1 }, { 160,  96, 160, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 },
  {   0,  32,  32, 1 }, {  64,  64,  32, 1 }, {  96, 128,   0, 1 }, { 224, 160,  32, 1 }
};
palette_entry gamecolor[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 160, 1 },
  {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
palette_entry zone8colora[56] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,   0, 1 }, { 128,  64,   0, 1 },
  { 224, 128,   0, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,   0, 1 }, {   0, 128,   0, 1 }, {  96, 192,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, { 160, 192, 160, 1 }, {  64,  96,  64, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 192, 128,  96, 1 }, { 224, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 192, 128, 1 }, { 224,  96,   0, 1 }, { 160,  32,   0, 1 }, {  64,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  32,   0, 1 }, {  96,  64,  32, 1 }, { 160,  96,  32, 1 },
  {   0,   0,   0, 1 }, {  64,   0,  64, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32, 128, 1 }, {  64,   0,  96, 1 }, {  32,   0,  64, 1 },
  { 128,  32, 128, 1 }, { 160,  96, 160, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 },
  {   0,  32,  32, 1 }, {  64,  64,  32, 1 }, {  96, 128,   0, 1 }, { 224, 160,  32, 1 },
  { 128,  96, 128, 1 }, { 160, 128, 160, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 },
  {  32,  32,  32, 1 }, {  64,  64,  32, 1 }, { 128,  96,  64, 1 }, { 224, 128,  96, 1 }
};
palette_entry zone82colora[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, { 128, 128, 128, 1 },
  {   0,  64, 224, 1 }, {   0,   0, 128, 1 }, { 224, 224, 224, 1 }, {  64,  96, 224, 1 },
  {  96,   0,   0, 1 }, { 224, 128, 224, 1 }, { 224, 128,   0, 1 }, { 224,  64, 160, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,  32,   0, 1 },
  {   0,   0,   0, 1 }, { 160, 192, 160, 1 }, {  64,  96,  64, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 192, 128,  96, 1 }, { 224, 192,   0, 1 }, { 224,   0,   0, 1 },
  { 224, 192, 128, 1 }, { 224,  96,   0, 1 }, { 160,  32,   0, 1 }, {  64,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  32,   0, 1 }, {  96,  64,  32, 1 }, { 160,  96,  32, 1 },
  {   0,   0,   0, 1 }, {  64,   0,  64, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 },
  { 224, 224,  64, 1 }, {  96,  32, 128, 1 }, {  64,   0,  96, 1 }, {  32,   0,  64, 1 },
  { 128,  32, 128, 1 }, { 160,  96, 160, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 },
  {   0,  32,  32, 1 }, {  64,  64,  32, 1 }, {  96, 128,   0, 1 }, { 224, 160,  32, 1 }
};
palette_entry boss6col[16] = {
  { 224, 224,  96, 1 }, {   0,   0,   0, 1 }, { 224,  96,   0, 1 }, { 224,   0,  96, 1 },
  {  96,  96, 128, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 160, 160, 1 },
  {  96, 128, 128, 1 }, {  64,  96,  96, 1 }, {  32,  64,  64, 1 }, {   0,  32,  32, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }
};
palette_entry boss6_col4[88] = {
  {   0,   0,   0, 1 }, {  64,  64, 224, 1 }, { 224,   0, 224, 1 }, {  96,  32, 128, 1 },
  {  64,   0,  96, 1 }, { 224, 192, 160, 1 }, {   0,   0,   0, 1 }, {   0,  32,  32, 1 },
  {  64,  64,  32, 1 }, {  96, 128,   0, 1 }, { 224, 160,  32, 1 }, {  32,  32,  32, 1 },
  {  96,  96, 224, 1 }, { 224,  32, 224, 1 }, { 128,  64, 160, 1 }, {  96,  32, 128, 1 },
  { 224, 224, 192, 1 }, {  32,  32,  32, 1 }, {  32,  64,  64, 1 }, {  96,  96,  64, 1 },
  { 128, 160,  32, 1 }, { 224, 192,  64, 1 }, {  64,  64,  64, 1 }, { 128, 128, 224, 1 },
  { 224,  64, 224, 1 }, { 160,  96, 192, 1 }, { 128,  64, 160, 1 }, { 224, 224, 224, 1 },
  {  64,  64,  64, 1 }, {  64,  96,  96, 1 }, { 128, 128,  96, 1 }, { 160, 192,  64, 1 },
  { 224, 224,  96, 1 }, {  96,  96,  96, 1 }, { 160, 160, 224, 1 }, { 224,  96, 224, 1 },
  { 192, 128, 224, 1 }, { 160,  96, 192, 1 }, { 224, 224, 224, 1 }, {  96,  96,  96, 1 },
  {  96, 128, 128, 1 }, { 160, 160, 128, 1 }, { 192, 224,  96, 1 }, { 224, 224, 128, 1 },
  { 128, 128, 128, 1 }, { 192, 192, 224, 1 }, { 224, 128, 224, 1 }, { 224, 160, 224, 1 },
  { 192, 128, 224, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 }, { 128, 160, 160, 1 },
  { 192, 192, 160, 1 }, { 224, 224, 128, 1 }, { 224, 224, 160, 1 }, { 160, 160, 160, 1 },
  { 224, 224, 224, 1 }, { 224, 160, 224, 1 }, { 224, 192, 224, 1 }, { 224, 160, 224, 1 },
  { 224, 224, 224, 1 }, { 160, 160, 160, 1 }, { 160, 192, 192, 1 }, { 224, 224, 192, 1 },
  { 224, 224, 160, 1 }, { 224, 224, 192, 1 }, { 192, 192, 192, 1 }, { 224, 224, 224, 1 },
  { 224, 192, 224, 1 }, { 224, 224, 224, 1 }, { 224, 192, 224, 1 }, { 224, 224, 224, 1 },
  { 192, 192, 192, 1 }, { 192, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 192, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224, 224, 1 }
};
palette_part colortbl[7] = {
  { advacolor,    0, 64 }, { advacolor,     0, 64 }, { advacolor2, 0, 64 }, { gamecolor, 0, 16 },
  { zone8colora, 16, 48 }, { zone82colora, 16, 48 }, { boss6col,  16, 16 }
};
static int FadeCount;






void clchgctr() { /* Line 139, Address: 0x102c4b0 */
  colchg6a(); /* Line 140, Address: 0x102c4b8 */
} /* Line 141, Address: 0x102c4c0 */

void colchg6a() { /* Line 143, Address: 0x102c4d0 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col6a0cnt, col6a0col); /* Line 144, Address: 0x102c4d8 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col6a1cnt, col6a1col); /* Line 145, Address: 0x102c500 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col6a2cnt, col6a2col); /* Line 146, Address: 0x102c528 */
  if (!(bossflag & 32)) /* Line 147, Address: 0x102c550 */
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col); /* Line 148, Address: 0x102c568 */
  else
    clchg_sub0(&clchgtim[3], &clchgcnt[3], col6a3cnt, col6a3col_stop); /* Line 150, Address: 0x102c598 */
} /* Line 151, Address: 0x102c5c0 */









void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, palette_entry* pColTbl) { /* Line 161, Address: 0x102c5d0 */
  palette_entry* lpPe;

  --*pChgTime; /* Line 164, Address: 0x102c5e8 */
  if ((char)*pChgTime < 0) { /* Line 165, Address: 0x102c5fc */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 167, Address: 0x102c61c */
    ++*pChgCnt; /* Line 168, Address: 0x102c640 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 169, Address: 0x102c654 */

      *pChgCnt = 0; /* Line 171, Address: 0x102c680 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 174, Address: 0x102c688 */
    *pChgTime = pCntTbl[0]; /* Line 175, Address: 0x102c6a4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 176, Address: 0x102c6b4 */
  }





} /* Line 183, Address: 0x102c6ec */


void fadein0() { /* Line 186, Address: 0x102c700 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 190, Address: 0x102c70c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 192, Address: 0x102c740 */
    lpPe->peRed = 0; /* Line 193, Address: 0x102c74c */
    lpPe->peGreen = 0; /* Line 194, Address: 0x102c750 */
    lpPe->peBlue = 0; /* Line 195, Address: 0x102c754 */
    lpPe->peFlags = 1; /* Line 196, Address: 0x102c758 */
    ++lpPe; /* Line 197, Address: 0x102c760 */
  } /* Line 198, Address: 0x102c764 */
  FadeCount = 0; /* Line 199, Address: 0x102c780 */
  *lpFadeFlag = 1; /* Line 200, Address: 0x102c788 */

} /* Line 202, Address: 0x102c798 */



int fadein0_new() { /* Line 206, Address: 0x102c7b0 */

  int_flg = 18; /* Line 208, Address: 0x102c7b8 */

  fadein1(); /* Line 210, Address: 0x102c7c4 */


  if (++FadeCount > 21) { /* Line 213, Address: 0x102c7cc */
    FadeCount = 0; /* Line 214, Address: 0x102c7ec */
    return 1; /* Line 215, Address: 0x102c7f4 */
  }
  return 0; /* Line 217, Address: 0x102c800 */
} /* Line 218, Address: 0x102c804 */



static void fadein1() { /* Line 222, Address: 0x102c820 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 226, Address: 0x102c834 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 227, Address: 0x102c868 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 229, Address: 0x102c89c */
    fadein2(lpPe, lpPe2); /* Line 230, Address: 0x102c8a8 */
    ++lpPe; /* Line 231, Address: 0x102c8b8 */
    ++lpPe2; /* Line 232, Address: 0x102c8bc */
  } /* Line 233, Address: 0x102c8c0 */
  if (stageno.b.h != 1) return; /* Line 234, Address: 0x102c8dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 236, Address: 0x102c8f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 237, Address: 0x102c92c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 239, Address: 0x102c960 */
    fadein2(lpPe, lpPe2); /* Line 240, Address: 0x102c96c */
    ++lpPe; /* Line 241, Address: 0x102c97c */
    ++lpPe2; /* Line 242, Address: 0x102c980 */
  } /* Line 243, Address: 0x102c984 */



} /* Line 247, Address: 0x102c9a0 */



static void fadein2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 251, Address: 0x102c9c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 252, Address: 0x102c9cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 255, Address: 0x102ca2c */
      lpPeDest->peBlue += 32; /* Line 256, Address: 0x102ca50 */
    } /* Line 257, Address: 0x102ca60 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 258, Address: 0x102ca68 */
      lpPeDest->peGreen += 32; /* Line 259, Address: 0x102ca8c */
    } /* Line 260, Address: 0x102ca9c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 261, Address: 0x102caa4 */
      lpPeDest->peRed += 32; /* Line 262, Address: 0x102cac8 */
    }
  }

} /* Line 266, Address: 0x102cadc */


void fadeout() {
  startcolor = 0; /* Line 270, Address: 0x102caf0 */
  colorcnt = 63; /* Line 271, Address: 0x102caf8 */

  FadeCount = 0; /* Line 273, Address: 0x102cb04 */
  *lpFadeFlag = 2; /* Line 274, Address: 0x102cb0c */

} /* Line 276, Address: 0x102cb1c */



static int fadeout_new() { /* Line 280, Address: 0x102cb30 */

  int_flg = 18; /* Line 282, Address: 0x102cb38 */

  fadeout1(); /* Line 284, Address: 0x102cb44 */


  if (++FadeCount > 21) { /* Line 287, Address: 0x102cb4c */
    FadeCount = 0; /* Line 288, Address: 0x102cb6c */
    return 1; /* Line 289, Address: 0x102cb74 */
  }
  return 0; /* Line 291, Address: 0x102cb80 */
} /* Line 292, Address: 0x102cb84 */


static void fadeout1() { /* Line 295, Address: 0x102cba0 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 299, Address: 0x102cbb0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 301, Address: 0x102cbe4 */
    fadeout2(lpPe); /* Line 302, Address: 0x102cbf0 */
    ++lpPe; /* Line 303, Address: 0x102cbfc */
  } /* Line 304, Address: 0x102cc00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 305, Address: 0x102cc1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 307, Address: 0x102cc50 */
    fadeout2(lpPe); /* Line 308, Address: 0x102cc5c */
    ++lpPe; /* Line 309, Address: 0x102cc68 */
  } /* Line 310, Address: 0x102cc6c */


} /* Line 313, Address: 0x102cc88 */


static void fadeout2(palette_entry* lpPeDest) { /* Line 316, Address: 0x102cca0 */
  if (lpPeDest->peRed) { /* Line 317, Address: 0x102cca8 */
    lpPeDest->peRed -= 32; /* Line 318, Address: 0x102ccb8 */
  } /* Line 319, Address: 0x102cccc */
  else if (lpPeDest->peGreen) { /* Line 320, Address: 0x102ccd4 */
    lpPeDest->peGreen -= 32; /* Line 321, Address: 0x102cce4 */
  } /* Line 322, Address: 0x102ccf4 */
  else if (lpPeDest->peBlue) { /* Line 323, Address: 0x102ccfc */
    lpPeDest->peBlue -= 32; /* Line 324, Address: 0x102cd0c */
  }

} /* Line 327, Address: 0x102cd1c */




void flashin() { /* Line 332, Address: 0x102cd30 */
  palette_entry* lpPe;
  int i;

  startcolor = 0; /* Line 336, Address: 0x102cd3c */
  colorcnt = 63; /* Line 337, Address: 0x102cd44 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 339, Address: 0x102cd50 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 341, Address: 0x102cd84 */
    lpPe->peRed = 224; /* Line 342, Address: 0x102cd90 */
    lpPe->peGreen = 224; /* Line 343, Address: 0x102cd98 */
    lpPe->peBlue = 224; /* Line 344, Address: 0x102cda0 */
    lpPe->peFlags = 1; /* Line 345, Address: 0x102cda8 */
    ++lpPe; /* Line 346, Address: 0x102cdb0 */
  } /* Line 347, Address: 0x102cdb4 */
  FadeCount = 0; /* Line 348, Address: 0x102cdd0 */
  *lpFadeFlag = 3; /* Line 349, Address: 0x102cdd8 */

} /* Line 351, Address: 0x102cde8 */

static int flashin_new() { /* Line 353, Address: 0x102ce00 */
  palette_entry* lpPe;

  lpPe = &lpcolorwk[32]; /* Line 356, Address: 0x102ce0c */

  int_flg = 18; /* Line 358, Address: 0x102ce18 */

  flashin1(); /* Line 360, Address: 0x102ce24 */

  lpPe->peRed = 224; /* Line 362, Address: 0x102ce2c */
  lpPe->peGreen = 224; /* Line 363, Address: 0x102ce34 */
  lpPe->peBlue = 224; /* Line 364, Address: 0x102ce3c */
  lpPe->peFlags = 1; /* Line 365, Address: 0x102ce44 */

  if (++FadeCount > 21) { /* Line 367, Address: 0x102ce4c */
    FadeCount = 0; /* Line 368, Address: 0x102ce6c */
    return 1; /* Line 369, Address: 0x102ce74 */
  }
  return 0; /* Line 371, Address: 0x102ce80 */
} /* Line 372, Address: 0x102ce84 */

static void flashin1() { /* Line 374, Address: 0x102cea0 */
  palette_entry *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 378, Address: 0x102ceb4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 379, Address: 0x102cee8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 381, Address: 0x102cf1c */
    flashin2(lpPe, lpPe2); /* Line 382, Address: 0x102cf28 */
    ++lpPe; /* Line 383, Address: 0x102cf38 */
    ++lpPe2; /* Line 384, Address: 0x102cf3c */
  } /* Line 385, Address: 0x102cf40 */
  if (stageno.b.h != 1) return; /* Line 386, Address: 0x102cf5c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 388, Address: 0x102cf78 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 389, Address: 0x102cfac */

  for (i = 0; colorcnt >= i; ++i) { /* Line 391, Address: 0x102cfe0 */
    flashin2(lpPe, lpPe2); /* Line 392, Address: 0x102cfec */
    ++lpPe; /* Line 393, Address: 0x102cffc */
    ++lpPe2; /* Line 394, Address: 0x102d000 */
  } /* Line 395, Address: 0x102d004 */



} /* Line 399, Address: 0x102d020 */



static void flashin2(palette_entry* lpPeDest, palette_entry* lpPeSrc) { /* Line 403, Address: 0x102d040 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 404, Address: 0x102d04c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 407, Address: 0x102d0ac */
      lpPeDest->peBlue -= 32; /* Line 408, Address: 0x102d0d0 */
    } /* Line 409, Address: 0x102d0e0 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 410, Address: 0x102d0e8 */
      lpPeDest->peGreen -= 32; /* Line 411, Address: 0x102d10c */
    } /* Line 412, Address: 0x102d11c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 413, Address: 0x102d124 */
      lpPeDest->peRed -= 32; /* Line 414, Address: 0x102d148 */
    }
  }

} /* Line 418, Address: 0x102d15c */


void flashout() {
  startcolor = 0; /* Line 422, Address: 0x102d170 */
  colorcnt = 63; /* Line 423, Address: 0x102d178 */

  FadeCount = 0; /* Line 425, Address: 0x102d184 */
  *lpFadeFlag = 4; /* Line 426, Address: 0x102d18c */

} /* Line 428, Address: 0x102d19c */

static int flashout_new() { /* Line 430, Address: 0x102d1b0 */

  int_flg = 18; /* Line 432, Address: 0x102d1b8 */

  flashout1(); /* Line 434, Address: 0x102d1c4 */


  if (++FadeCount > 21) { /* Line 437, Address: 0x102d1cc */
    FadeCount = 0; /* Line 438, Address: 0x102d1ec */
    return 1; /* Line 439, Address: 0x102d1f4 */
  }
  return 0; /* Line 441, Address: 0x102d200 */
} /* Line 442, Address: 0x102d204 */


static void flashout1() { /* Line 445, Address: 0x102d220 */
  palette_entry* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 449, Address: 0x102d230 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 451, Address: 0x102d264 */
    flashout2(lpPe); /* Line 452, Address: 0x102d270 */
    ++lpPe; /* Line 453, Address: 0x102d27c */
  } /* Line 454, Address: 0x102d280 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 455, Address: 0x102d29c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 457, Address: 0x102d2d0 */
    flashout2(lpPe); /* Line 458, Address: 0x102d2dc */
    ++lpPe; /* Line 459, Address: 0x102d2e8 */
  } /* Line 460, Address: 0x102d2ec */


} /* Line 463, Address: 0x102d308 */


static void flashout2(palette_entry* lpPeDest) { /* Line 466, Address: 0x102d320 */
  if (lpPeDest->peRed != 224) { /* Line 467, Address: 0x102d328 */
    lpPeDest->peRed += 32; /* Line 468, Address: 0x102d340 */
  } /* Line 469, Address: 0x102d354 */
  else if (lpPeDest->peGreen != 224) { /* Line 470, Address: 0x102d35c */
    lpPeDest->peGreen += 32; /* Line 471, Address: 0x102d374 */
  } /* Line 472, Address: 0x102d384 */
  else if (lpPeDest->peBlue != 224) { /* Line 473, Address: 0x102d38c */
    lpPeDest->peBlue += 32; /* Line 474, Address: 0x102d3a4 */
  }


} /* Line 478, Address: 0x102d3b4 */


void colorset(int ColorNo) { /* Line 481, Address: 0x102d3c0 */
  colorset00(ColorNo, 1); /* Line 482, Address: 0x102d3cc */
} /* Line 483, Address: 0x102d3dc */

void colorset2(int ColorNo) { /* Line 485, Address: 0x102d3f0 */
  colorset00(ColorNo, 0); /* Line 486, Address: 0x102d3fc */
} /* Line 487, Address: 0x102d40c */

void colorset3(int ColorNo) { /* Line 489, Address: 0x102d420 */
  colorset00(ColorNo, 0); /* Line 490, Address: 0x102d42c */
} /* Line 491, Address: 0x102d43c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 497, Address: 0x102d450 */
  palette_entry* lppe;
  palette_entry *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 502, Address: 0x102d470 */
    case 0:
      lppe = lpcolorwk; break; /* Line 504, Address: 0x102d4d8 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 506, Address: 0x102d4e8 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 508, Address: 0x102d4f8 */
    default:
      lppe = lpcolorwk4; break; /* Line 510, Address: 0x102d508 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 513, Address: 0x102d510 */
  lpPeDest = &lppe[colortbl[ColorNo].offset]; /* Line 514, Address: 0x102d528 */
  n = colortbl[ColorNo].cnt; /* Line 515, Address: 0x102d550 */
  for (i = 0; i < n; ++i) { /* Line 516, Address: 0x102d570 */
    *lpPeDest++ = *lpPeSrc++; /* Line 517, Address: 0x102d57c */
  } /* Line 518, Address: 0x102d5ac */

} /* Line 520, Address: 0x102d5bc */




int FadeProc() { /* Line 525, Address: 0x102d5e0 */
  switch (*lpFadeFlag) { /* Line 526, Address: 0x102d5e8 */
    case 1:
      return fadein0_new(); /* Line 528, Address: 0x102d62c */
    case 2:
      return fadeout_new(); /* Line 530, Address: 0x102d63c */
    case 3:
      return flashin_new(); /* Line 532, Address: 0x102d64c */
    case 4:
      return flashout_new(); /* Line 534, Address: 0x102d65c */
  }
  return 1; /* Line 536, Address: 0x102d66c */

} /* Line 538, Address: 0x102d670 */











void fin_boss6(unsigned char* pChgTime, unsigned char* pChgCnt) { /* Line 550, Address: 0x102d680 */
  char d0;

  if (++*pChgTime < 12) return; /* Line 553, Address: 0x102d694 */

  *pChgTime = 0; /* Line 555, Address: 0x102d6bc */
  d0 = *pChgCnt; /* Line 556, Address: 0x102d6c4 */
  d0 -= 11; /* Line 557, Address: 0x102d6d4 */
  if (d0 < 0) d0 = 0; /* Line 558, Address: 0x102d6e0 */
  fset_boss6(d0, pChgCnt); /* Line 559, Address: 0x102d6f4 */
} /* Line 560, Address: 0x102d704 */

void fout_boss6(unsigned char* pChgTime, unsigned char* pChgCnt) { /* Line 562, Address: 0x102d720 */
  unsigned char d0;

  if (++*pChgTime < 12) return; /* Line 565, Address: 0x102d734 */

  *pChgTime = 0; /* Line 567, Address: 0x102d75c */
  d0 = *pChgCnt; /* Line 568, Address: 0x102d764 */
  d0 += 11; /* Line 569, Address: 0x102d770 */
  if (d0 == 88) d0 = 77; /* Line 570, Address: 0x102d778 */
  fset_boss6(d0, pChgCnt); /* Line 571, Address: 0x102d790 */
} /* Line 572, Address: 0x102d7a4 */

void fset_boss6(char d0, unsigned char* pChgCnt) { /* Line 574, Address: 0x102d7c0 */
  palette_entry* lpPe;

  *pChgCnt = d0; /* Line 577, Address: 0x102d7d0 */
  lpPe = &lpcolorwk[32]; /* Line 578, Address: 0x102d7dc */
  *lpPe++ = boss6_col4[d0++]; /* Line 579, Address: 0x102d7e8 */
  lpPe = &lpcolorwk[50]; /* Line 580, Address: 0x102d834 */
  *lpPe++ = boss6_col4[d0++]; /* Line 581, Address: 0x102d840 */
  *lpPe++ = boss6_col4[d0++]; /* Line 582, Address: 0x102d88c */
  ++lpPe; /* Line 583, Address: 0x102d8d8 */
  *lpPe++ = boss6_col4[d0++]; /* Line 584, Address: 0x102d8dc */
  *lpPe++ = boss6_col4[d0++]; /* Line 585, Address: 0x102d928 */
  ++lpPe; /* Line 586, Address: 0x102d974 */
  ++lpPe; /* Line 587, Address: 0x102d978 */
  ++lpPe; /* Line 588, Address: 0x102d97c */
  *lpPe++ = boss6_col4[d0++]; /* Line 589, Address: 0x102d980 */
  *lpPe++ = boss6_col4[d0++]; /* Line 590, Address: 0x102d9cc */
  *lpPe++ = boss6_col4[d0++]; /* Line 591, Address: 0x102da18 */
  *lpPe++ = boss6_col4[d0++]; /* Line 592, Address: 0x102da64 */
  *lpPe++ = boss6_col4[d0++]; /* Line 593, Address: 0x102dab0 */
  *lpPe++ = boss6_col4[d0++]; /* Line 594, Address: 0x102dafc */
} /* Line 595, Address: 0x102db48 */




void flashin_boss6() { /* Line 600, Address: 0x102db60 */
  short d0;
  palette_entry* lpPe;

  startcolor = 0; /* Line 604, Address: 0x102db6c */
  colorcnt = 47; /* Line 605, Address: 0x102db74 */
  lpPe = &lpcolorwk[startcolor >> 1]; /* Line 606, Address: 0x102db80 */
  for (d0 = 0; d0 <= colorcnt; ++d0) { /* Line 607, Address: 0x102dba0 */

    lpPe->peRed = 224; /* Line 609, Address: 0x102dbac */
    lpPe->peGreen = 224; /* Line 610, Address: 0x102dbb4 */
    lpPe->peBlue = 224; /* Line 611, Address: 0x102dbbc */
    lpPe->peFlags = 1; /* Line 612, Address: 0x102dbc4 */
    ++lpPe; /* Line 613, Address: 0x102dbcc */
  } /* Line 614, Address: 0x102dbd0 */

  FadeCount = 0; /* Line 616, Address: 0x102dbfc */
  *lpFadeFlag = 3; /* Line 617, Address: 0x102dc04 */
} /* Line 618, Address: 0x102dc14 */
