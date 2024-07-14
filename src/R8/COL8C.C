#include "..\EQU.H"
#include "COL8C.H"

static void fadein1(); static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int fadeout_new(); static void fadeout1(); static void fadeout2(PALETTEENTRY* lpPeDest);
static int flashin_new(); static void flashin1(); static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int flashout_new(); static void flashout1(); static void flashout2(PALETTEENTRY* lpPeDest);
static void colorset00(int ColorNo, int WorkOffs);

unsigned char col8a0cnt[8] = { 38, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a0col[3] = { {  96, 224, 224, 1 }, {   0, 160, 192, 1 }, {   0,  96, 160, 1 } };
unsigned char col8a1cnt[8] = { 39, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a1col[3] = { {   0, 160, 192, 1 }, {   0,  96, 160, 1 }, {  96, 224, 224, 1 } };
unsigned char col8a2cnt[8] = { 40, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a2col[3] = { {   0,  96, 160, 1 }, {  96, 224, 224, 1 }, {   0, 160, 192, 1 } };
unsigned char col8a3cnt[13] = { 49, 6, 2, 0, 2, 1, 2, 22, 0, 2, 1, 66, 2 };
PALETTEENTRY col8a3col[3] = { { 224, 224,   0, 1 }, {   0, 224, 224, 1 }, {   0,   0,   0, 1 } };
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
  {   0,   0,   0, 1 }, {  32,  32,  64, 1 }, {   0,   0,   0, 1 }, {   0, 128,   0, 1 },
  {   0, 224,   0, 1 }, {   0,  64,   0, 1 }, {  96, 224, 224, 1 }, {   0, 160, 192, 1 },
  {   0,  96, 160, 1 }, {  96,   0,   0, 1 }, { 160,  64,   0, 1 }, { 224, 160,   0, 1 },
  {  64,  96, 160, 1 }, {  96, 160, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {  64,   0,  32, 1 }, { 128,   0,  96, 1 },
  { 224,   0, 192, 1 }, { 224, 128, 192, 1 }, { 224, 224, 224, 1 }, {   0,  64,   0, 1 },
  {   0, 128,   0, 1 }, {   0, 224,   0, 1 }, {   0,   0,  64, 1 }, {  32,  32, 128, 1 },
  {   0,  64, 192, 1 }, {  32, 128, 224, 1 }, {  96, 160, 224, 1 }, { 128, 224, 224, 1 }
};
PALETTEENTRY zone83ccolor[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  32,   0, 160, 1 }, {  32,  32,  64, 1 }, {   0,   0,   0, 1 }, {   0, 128,   0, 1 },
  {   0, 224,   0, 1 }, {   0,  64,   0, 1 }, {  96, 224, 224, 1 }, {   0, 160, 192, 1 },
  {   0,  96, 160, 1 }, {  96,   0,   0, 1 }, { 160,  64,   0, 1 }, { 224, 160,   0, 1 },
  {  64,  96, 160, 1 }, {  96, 160, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  {  32,   0, 160, 1 }, {   0,   0,  32, 1 }, { 128, 128, 224, 1 }, { 192, 160, 160, 1 },
  {   0,   0,   0, 1 }, {  32,  64,  32, 1 }, {  32,  96,   0, 1 }, {  32, 160,   0, 1 },
  { 192, 192, 224, 1 }, {  64,  64, 128, 1 }, {  64, 128, 128, 1 }, {  96, 192, 160, 1 },
  {   0,  32, 128, 1 }, {  96,  32, 192, 1 }, { 128,  64, 224, 1 }, {   0,   0,  96, 1 }
};
PALETTEENTRY zone82ccolor[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {  32,   0, 160, 1 }, {  32,  32,  64, 1 }, {   0,   0,   0, 1 }, {   0, 128,   0, 1 },
  {   0, 224,   0, 1 }, {   0,  64,   0, 1 }, {  96, 224, 224, 1 }, {   0, 160, 192, 1 },
  {   0,  96, 160, 1 }, {  96,   0,   0, 1 }, { 160,  64,   0, 1 }, { 224, 160,   0, 1 },
  {  64,  96, 160, 1 }, {  96, 160, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 },
  {  32,   0, 160, 1 }, {   0,   0,  32, 1 }, { 128, 128, 224, 1 }, { 192, 160, 160, 1 },
  {  32,  32,   0, 1 }, {  32,  64,  32, 1 }, {  32,  96,   0, 1 }, {  32, 160,   0, 1 },
  { 192, 192, 224, 1 }, {  64,  96, 128, 1 }, {  64, 160, 128, 1 }, { 128, 224, 160, 1 },
  {  32,  32, 128, 1 }, {  96,  32, 192, 1 }, { 128,  64, 224, 1 }, {   0,   0,  96, 1 }
};
PALETTEENTRY boss8col_0[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 }
};
PALETTEENTRY boss8col_1[16] = {
  { 224, 224,  32, 1 }, {   0,   0,   0, 1 }, {  96, 128, 160, 1 }, {   0,  32,  64, 1 },
  {  32,  64,  96, 1 }, {  64,  96, 128, 1 }, { 224, 224, 224, 1 }, { 128, 160, 192, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 }
};
PALETTEENTRY emie8col[16] = {
  {  96,  96, 192, 1 }, {   0,   0,   0, 1 }, { 128,  32,  96, 1 }, { 160,  64, 128, 1 },
  { 224,  96, 224, 1 }, { 224, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 192,  96,   0, 1 },
  {  32, 192,   0, 1 }, {   0, 128,   0, 1 }, {  96,   0, 128, 1 }, { 224,   0,   0, 1 }
};
palette_part colortbl[12] = {
  { advacolor,     0, 64 }, { advacolor,     0, 64 }, { advacolor2,    0, 64 }, { gamecolor,     0, 16 },
  { zone8colora,  16, 48 }, { zone83ccolor, 16, 48 }, { zone82ccolor, 16, 48 }, { boss8col_1,   80, 16 },
  { boss8col_0,   16, 16 }, { boss8col_0,   16, 16 }, { 0,             0,  0 }, { emie8col, 16, 16 }
};
PALETTEENTRY boss8_col1[40] = {
  {   0,   0,   0, 1 }, { 224,  96,   0, 1 }, {   0,   0, 224, 1 }, { 224,   0, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 192,  96,   0, 1 }, {  64,   0,  96, 1 }, {   0, 160, 224, 1 }, { 128, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224, 224,   0, 1 }, {   0, 224,   0, 1 }, { 224,   0, 224, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, {   0,  96, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0, 224, 1 }, { 224, 224,   0, 1 }, {   0, 224, 224, 1 }, { 224,  96,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
};
static int FadeCount;






void clchgctr() { /* Line 144, Address: 0x101c410 */
  colchg8c(); /* Line 145, Address: 0x101c418 */
} /* Line 146, Address: 0x101c420 */

void colchg8c() { /* Line 148, Address: 0x101c430 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col8a0cnt, col8a0col); /* Line 149, Address: 0x101c438 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col8a1cnt, col8a1col); /* Line 150, Address: 0x101c460 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col8a2cnt, col8a2col); /* Line 151, Address: 0x101c488 */
  if (stageno.b.l == 0) { /* Line 152, Address: 0x101c4b0 */

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a3cnt, col8a3col); /* Line 154, Address: 0x101c4c8 */
  }
} /* Line 156, Address: 0x101c4f0 */





















void colchg_boss8(unsigned char* a3, unsigned char* a4) { /* Line 178, Address: 0x101c500 */
  PALETTEENTRY* lpPe;
  char d0;

  if (bossstart == 0) return; /* Line 182, Address: 0x101c514 */
  if (++*a4 >= 4) { /* Line 183, Address: 0x101c528 */
    *a4 = 0; /* Line 184, Address: 0x101c550 */
    d0 = *a3 + 4; /* Line 185, Address: 0x101c558 */
    if (d0 >= 40) d0 = 0; /* Line 186, Address: 0x101c578 */

    *a3 = d0; /* Line 188, Address: 0x101c590 */
    lpPe = &lpcolorwk[24]; /* Line 189, Address: 0x101c598 */
    *lpPe++ = boss8_col1[d0]; /* Line 190, Address: 0x101c5a4 */
    *lpPe++ = boss8_col1[d0 + 1]; /* Line 191, Address: 0x101c5e4 */
    *lpPe++ = boss8_col1[d0 + 2]; /* Line 192, Address: 0x101c628 */
    *lpPe++ = boss8_col1[d0 + 3]; /* Line 193, Address: 0x101c66c */
  }
} /* Line 195, Address: 0x101c6b0 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 204, Address: 0x101c6d0 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 207, Address: 0x101c6e8 */
  if ((char)*pChgTime < 0) { /* Line 208, Address: 0x101c6fc */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 210, Address: 0x101c71c */
    ++*pChgCnt; /* Line 211, Address: 0x101c740 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 212, Address: 0x101c754 */

      *pChgCnt = 0; /* Line 214, Address: 0x101c780 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 217, Address: 0x101c788 */
    *pChgTime = pCntTbl[0]; /* Line 218, Address: 0x101c7a4 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 219, Address: 0x101c7b4 */
  }





} /* Line 226, Address: 0x101c7ec */

void fadein0() { /* Line 228, Address: 0x101c800 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 232, Address: 0x101c80c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 234, Address: 0x101c840 */
    lpPe->peRed = 0; /* Line 235, Address: 0x101c84c */
    lpPe->peGreen = 0; /* Line 236, Address: 0x101c850 */
    lpPe->peBlue = 0; /* Line 237, Address: 0x101c854 */
    lpPe->peFlags = 1; /* Line 238, Address: 0x101c858 */
    ++lpPe; /* Line 239, Address: 0x101c860 */
  } /* Line 240, Address: 0x101c864 */
  FadeCount = 0; /* Line 241, Address: 0x101c880 */
  *lpFadeFlag = 1; /* Line 242, Address: 0x101c888 */

} /* Line 244, Address: 0x101c898 */



int fadein0_new() { /* Line 248, Address: 0x101c8b0 */

  int_flg = 18; /* Line 250, Address: 0x101c8b8 */

  fadein1(); /* Line 252, Address: 0x101c8c4 */


  if (++FadeCount > 21) { /* Line 255, Address: 0x101c8cc */
    FadeCount = 0; /* Line 256, Address: 0x101c8ec */
    return 1; /* Line 257, Address: 0x101c8f4 */
  }
  return 0; /* Line 259, Address: 0x101c900 */
} /* Line 260, Address: 0x101c904 */



static void fadein1() { /* Line 264, Address: 0x101c920 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 268, Address: 0x101c934 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 269, Address: 0x101c968 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 271, Address: 0x101c99c */
    fadein2(lpPe, lpPe2); /* Line 272, Address: 0x101c9a8 */
    ++lpPe; /* Line 273, Address: 0x101c9b8 */
    ++lpPe2; /* Line 274, Address: 0x101c9bc */
  } /* Line 275, Address: 0x101c9c0 */
  if (stageno.b.h == 1) return; /* Line 276, Address: 0x101c9dc */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 278, Address: 0x101c9f8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 279, Address: 0x101ca2c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 281, Address: 0x101ca60 */
    fadein2(lpPe, lpPe2); /* Line 282, Address: 0x101ca6c */
    ++lpPe; /* Line 283, Address: 0x101ca7c */
    ++lpPe2; /* Line 284, Address: 0x101ca80 */
  } /* Line 285, Address: 0x101ca84 */



} /* Line 289, Address: 0x101caa0 */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 293, Address: 0x101cac0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 294, Address: 0x101cacc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 297, Address: 0x101cb2c */
      lpPeDest->peBlue += 32; /* Line 298, Address: 0x101cb50 */
    } /* Line 299, Address: 0x101cb60 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 300, Address: 0x101cb68 */
      lpPeDest->peGreen += 32; /* Line 301, Address: 0x101cb8c */
    } /* Line 302, Address: 0x101cb9c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 303, Address: 0x101cba4 */
      lpPeDest->peRed += 32; /* Line 304, Address: 0x101cbc8 */
    }
  }

} /* Line 308, Address: 0x101cbdc */





void fadein_boss8() { /* Line 314, Address: 0x101cbf0 */
  PALETTEENTRY *lpPe, *lpPe2;

  int_flg = 18; /* Line 317, Address: 0x101cc00 */
  lpPe = &lpcolorwk[16]; /* Line 318, Address: 0x101cc0c */
  lpPe2 = &lpcolorwk2[16]; /* Line 319, Address: 0x101cc18 */
  fadein1_boss8(lpPe, lpPe2); /* Line 320, Address: 0x101cc24 */
} /* Line 321, Address: 0x101cc34 */

void fadein1_boss8(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 323, Address: 0x101cc50 */
  short i;

  for (i = 0; i < 16; ++i) { /* Line 326, Address: 0x101cc64 */
    fadein2(lpPeDest, lpPeSrc); /* Line 327, Address: 0x101cc70 */
    ++lpPeDest; /* Line 328, Address: 0x101cc80 */
    ++lpPeSrc; /* Line 329, Address: 0x101cc8c */
  } /* Line 330, Address: 0x101cc98 */
} /* Line 331, Address: 0x101ccb8 */

void fadeout() {
  startcolor = 0; /* Line 334, Address: 0x101ccd0 */
  colorcnt = 63; /* Line 335, Address: 0x101ccd8 */

  FadeCount = 0; /* Line 337, Address: 0x101cce4 */
  *lpFadeFlag = 2; /* Line 338, Address: 0x101ccec */

} /* Line 340, Address: 0x101ccfc */



static int fadeout_new() { /* Line 344, Address: 0x101cd10 */

  int_flg = 18; /* Line 346, Address: 0x101cd18 */

  fadeout1(); /* Line 348, Address: 0x101cd24 */


  if (++FadeCount > 21) { /* Line 351, Address: 0x101cd2c */
    FadeCount = 0; /* Line 352, Address: 0x101cd4c */
    return 1; /* Line 353, Address: 0x101cd54 */
  }
  return 0; /* Line 355, Address: 0x101cd60 */
} /* Line 356, Address: 0x101cd64 */


static void fadeout1() { /* Line 359, Address: 0x101cd80 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 363, Address: 0x101cd90 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 365, Address: 0x101cdc4 */
    fadeout2(lpPe); /* Line 366, Address: 0x101cdd0 */
    ++lpPe; /* Line 367, Address: 0x101cddc */
  } /* Line 368, Address: 0x101cde0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 369, Address: 0x101cdfc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 371, Address: 0x101ce30 */
    fadeout2(lpPe); /* Line 372, Address: 0x101ce3c */
    ++lpPe; /* Line 373, Address: 0x101ce48 */
  } /* Line 374, Address: 0x101ce4c */


} /* Line 377, Address: 0x101ce68 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 380, Address: 0x101ce80 */
  if (lpPeDest->peRed) { /* Line 381, Address: 0x101ce88 */
    lpPeDest->peRed -= 32; /* Line 382, Address: 0x101ce98 */
  } /* Line 383, Address: 0x101ceac */
  else if (lpPeDest->peGreen) { /* Line 384, Address: 0x101ceb4 */
    lpPeDest->peGreen -= 32; /* Line 385, Address: 0x101cec4 */
  } /* Line 386, Address: 0x101ced4 */
  else if (lpPeDest->peBlue) { /* Line 387, Address: 0x101cedc */
    lpPeDest->peBlue -= 32; /* Line 388, Address: 0x101ceec */
  }

} /* Line 391, Address: 0x101cefc */




void flashin() { /* Line 396, Address: 0x101cf10 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 400, Address: 0x101cf1c */
  colorcnt = 63; /* Line 401, Address: 0x101cf24 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 403, Address: 0x101cf30 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 405, Address: 0x101cf64 */
    lpPe->peRed = 224; /* Line 406, Address: 0x101cf70 */
    lpPe->peGreen = 224; /* Line 407, Address: 0x101cf78 */
    lpPe->peBlue = 224; /* Line 408, Address: 0x101cf80 */
    lpPe->peFlags = 1; /* Line 409, Address: 0x101cf88 */
    ++lpPe; /* Line 410, Address: 0x101cf90 */
  } /* Line 411, Address: 0x101cf94 */
  FadeCount = 0; /* Line 412, Address: 0x101cfb0 */
  *lpFadeFlag = 3; /* Line 413, Address: 0x101cfb8 */

} /* Line 415, Address: 0x101cfc8 */

static int flashin_new() { /* Line 417, Address: 0x101cfe0 */

  int_flg = 18; /* Line 419, Address: 0x101cfe8 */

  flashin1(); /* Line 421, Address: 0x101cff4 */


  if (++FadeCount > 21) { /* Line 424, Address: 0x101cffc */
    FadeCount = 0; /* Line 425, Address: 0x101d01c */
    return 1; /* Line 426, Address: 0x101d024 */
  }
  return 0; /* Line 428, Address: 0x101d030 */
} /* Line 429, Address: 0x101d034 */

static void flashin1() { /* Line 431, Address: 0x101d050 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 435, Address: 0x101d064 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 436, Address: 0x101d098 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 438, Address: 0x101d0cc */
    flashin2(lpPe, lpPe2); /* Line 439, Address: 0x101d0d8 */
    ++lpPe; /* Line 440, Address: 0x101d0e8 */
    ++lpPe2; /* Line 441, Address: 0x101d0ec */
  } /* Line 442, Address: 0x101d0f0 */
  if (stageno.b.h == 1) return; /* Line 443, Address: 0x101d10c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 445, Address: 0x101d128 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 446, Address: 0x101d15c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 448, Address: 0x101d190 */
    flashin2(lpPe, lpPe2); /* Line 449, Address: 0x101d19c */
    ++lpPe; /* Line 450, Address: 0x101d1ac */
    ++lpPe2; /* Line 451, Address: 0x101d1b0 */
  } /* Line 452, Address: 0x101d1b4 */



} /* Line 456, Address: 0x101d1d0 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 460, Address: 0x101d1f0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 461, Address: 0x101d1fc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 464, Address: 0x101d25c */
      lpPeDest->peBlue -= 32; /* Line 465, Address: 0x101d280 */
    } /* Line 466, Address: 0x101d290 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 467, Address: 0x101d298 */
      lpPeDest->peGreen -= 32; /* Line 468, Address: 0x101d2bc */
    } /* Line 469, Address: 0x101d2cc */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 470, Address: 0x101d2d4 */
      lpPeDest->peRed -= 32; /* Line 471, Address: 0x101d2f8 */
    }
  }

} /* Line 475, Address: 0x101d30c */


void flashout() {
  startcolor = 0; /* Line 479, Address: 0x101d320 */
  colorcnt = 63; /* Line 480, Address: 0x101d328 */

  FadeCount = 0; /* Line 482, Address: 0x101d334 */
  *lpFadeFlag = 4; /* Line 483, Address: 0x101d33c */

} /* Line 485, Address: 0x101d34c */

static int flashout_new() { /* Line 487, Address: 0x101d360 */

  int_flg = 18; /* Line 489, Address: 0x101d368 */

  flashout1(); /* Line 491, Address: 0x101d374 */


  if (++FadeCount > 21) { /* Line 494, Address: 0x101d37c */
    FadeCount = 0; /* Line 495, Address: 0x101d39c */
    return 1; /* Line 496, Address: 0x101d3a4 */
  }
  return 0; /* Line 498, Address: 0x101d3b0 */
} /* Line 499, Address: 0x101d3b4 */


static void flashout1() { /* Line 502, Address: 0x101d3d0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 506, Address: 0x101d3e0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 508, Address: 0x101d414 */
    flashout2(lpPe); /* Line 509, Address: 0x101d420 */
    ++lpPe; /* Line 510, Address: 0x101d42c */
  } /* Line 511, Address: 0x101d430 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 512, Address: 0x101d44c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 514, Address: 0x101d480 */
    flashout2(lpPe); /* Line 515, Address: 0x101d48c */
    ++lpPe; /* Line 516, Address: 0x101d498 */
  } /* Line 517, Address: 0x101d49c */


} /* Line 520, Address: 0x101d4b8 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 523, Address: 0x101d4d0 */
  if (lpPeDest->peRed != 224) { /* Line 524, Address: 0x101d4d8 */
    lpPeDest->peRed += 32; /* Line 525, Address: 0x101d4f0 */
  } /* Line 526, Address: 0x101d504 */
  else if (lpPeDest->peGreen != 224) { /* Line 527, Address: 0x101d50c */
    lpPeDest->peGreen += 32; /* Line 528, Address: 0x101d524 */
  } /* Line 529, Address: 0x101d534 */
  else if (lpPeDest->peBlue != 224) { /* Line 530, Address: 0x101d53c */
    lpPeDest->peBlue += 32; /* Line 531, Address: 0x101d554 */
  }


} /* Line 535, Address: 0x101d564 */

void colorset(int ColorNo) { /* Line 537, Address: 0x101d570 */
  colorset00(ColorNo, 1); /* Line 538, Address: 0x101d57c */
} /* Line 539, Address: 0x101d58c */

void colorset2(int ColorNo) { /* Line 541, Address: 0x101d5a0 */
  colorset00(ColorNo, 0); /* Line 542, Address: 0x101d5ac */
} /* Line 543, Address: 0x101d5bc */

void colorset3(int ColorNo) { /* Line 545, Address: 0x101d5d0 */
  colorset00(ColorNo, 0); /* Line 546, Address: 0x101d5dc */
} /* Line 547, Address: 0x101d5ec */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 553, Address: 0x101d600 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 558, Address: 0x101d620 */
    case 0:
      lppe = lpcolorwk; break; /* Line 560, Address: 0x101d688 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 562, Address: 0x101d698 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 564, Address: 0x101d6a8 */
    default:
      lppe = lpcolorwk4; break; /* Line 566, Address: 0x101d6b8 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 569, Address: 0x101d6c0 */
  lpPeDest = &lppe[colortbl[ColorNo].offset % 64]; /* Line 570, Address: 0x101d6d8 */
  n = colortbl[ColorNo].cnt; /* Line 571, Address: 0x101d71c */
  for (i = 0; i < n; ++i) { /* Line 572, Address: 0x101d73c */
    *lpPeDest++ = *lpPeSrc++; /* Line 573, Address: 0x101d748 */
  } /* Line 574, Address: 0x101d778 */

} /* Line 576, Address: 0x101d788 */




int FadeProc() { /* Line 581, Address: 0x101d7b0 */
  switch (*lpFadeFlag) { /* Line 582, Address: 0x101d7b8 */
    case 1:
      return fadein0_new(); /* Line 584, Address: 0x101d7fc */
    case 2:
      return fadeout_new(); /* Line 586, Address: 0x101d80c */
    case 3:
      return flashin_new(); /* Line 588, Address: 0x101d81c */
    case 4:
      return flashout_new(); /* Line 590, Address: 0x101d82c */
  }
  return 1; /* Line 592, Address: 0x101d83c */

} /* Line 594, Address: 0x101d840 */
