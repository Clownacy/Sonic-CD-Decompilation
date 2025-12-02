#include "..\EQU.H"
#include "COL8D.H"

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

unsigned char col8a0cnt[8] = { 38, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a0col[3] = { { 224, 160,   0, 1 }, { 192,  64,   0, 1 }, { 160,  32,   0, 1 } };
unsigned char col8a1cnt[8] = { 39, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a1col[3] = { { 192,  64,   0, 1 }, { 160,  32,   0, 1 }, { 224, 160,   0, 1 } };
unsigned char col8a2cnt[8] = { 40, 3, 4, 2, 4, 1, 4, 0 };
PALETTEENTRY col8a2col[3] = { { 160,  32,   0, 1 }, { 224, 160,   0, 1 }, { 192,  64,   0, 1 } };
unsigned char col8a3cnt[10] = { 49, 4, 3, 0, 3, 1, 3, 0, 84, 1 };
PALETTEENTRY col8a3col[2] = { { 224, 224,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8a4cnt[12] = { 50, 5, 12, 0, 3, 1, 3, 0, 3, 1, 72, 0 };
PALETTEENTRY col8a4col[2] = { {   0,   0,   0, 1 }, { 224, 224,   0, 1 } };
unsigned char col8a5cnt[12] = { 51, 5, 24, 0, 3, 1, 3, 0, 3, 1, 60, 0 };
PALETTEENTRY col8a5col[2] = { {   0,   0,   0, 1 }, { 224, 224,   0, 1 } };
unsigned char col8a6cnt[14] = { 49, 6, 19, 0, 19, 1, 19, 2, 19, 3, 19, 2, 19, 1 };
PALETTEENTRY col8a6col[4] = { { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8a7cnt[6] = { 50, 2, 2, 0, 2, 1 };
PALETTEENTRY col8a7col[2] = { {   0, 224,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8a8cnt[38] = { 51, 18, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 55, 1, 2, 0, 2, 1, 2, 0, 10, 1, 2, 0, 10, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 25, 1 };
PALETTEENTRY col8a8col[2] = { { 224, 128,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8a9cnt[18] = { 49, 8, 11, 0, 11, 1, 11, 2, 11, 3, 11, 3, 11, 3, 11, 2, 11, 1 };
PALETTEENTRY col8a9col[4] = { { 224,   0,   0, 1 }, { 160,   0,   0, 1 }, {  96,   0,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8aacnt[18] = { 50, 8, 11, 0, 11, 1, 11, 2, 11, 3, 11, 4, 11, 3, 11, 2, 11, 1 };
PALETTEENTRY col8aacol[5] = { { 224, 128,   0, 1 }, { 192,  96,   0, 1 }, {  96,  64,   0, 1 }, {  32,  32,   0, 1 }, {   0,   0,   0, 1 } };
unsigned char col8abcnt[6] = { 51, 2, 2, 0, 2, 1 };
PALETTEENTRY col8abcol[2] = { {   0, 224,   0, 1 }, {   0,   0,   0, 1 } };
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
  {   0,  32,  32, 1 }, {   0,   0,   0, 1 }, {  96,  32,   0, 1 }, { 160,  64,  32, 1 },
  { 224, 128,  96, 1 }, { 224, 192, 128, 1 }, { 224, 160,   0, 1 }, { 192,  64,   0, 1 },
  { 160,  32,   0, 1 }, {  64,   0,  32, 1 }, { 128,   0,  64, 1 }, { 224,   0, 128, 1 },
  {  32,  32,   0, 1 }, {  96,  64,   0, 1 }, { 128,  96,  32, 1 }, { 192, 128,  64, 1 },
  {   0,  32,  32, 1 }, { 224, 224,   0, 1 }, { 160, 160,   0, 1 }, {  64,  64,   0, 1 },
  {  32,  32,   0, 1 }, {  64,  64,   0, 1 }, { 128,  96,   0, 1 }, {  32,   0,   0, 1 },
  {  64,   0,   0, 1 }, {  96,  32,   0, 1 }, { 160,  96,   0, 1 }, {   0,   0,   0, 1 },
  {   0,  32,  64, 1 }, {   0,  64,  96, 1 }, {   0,  96, 128, 1 }, {   0, 160, 192, 1 }
};
PALETTEENTRY zone82dcolor[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  96,  32,   0, 1 }, { 160,  64,  32, 1 },
  { 224, 128,  96, 1 }, { 224, 192, 128, 1 }, { 224, 160,   0, 1 }, { 192,  64,   0, 1 },
  { 160,  32,   0, 1 }, {  64,   0,  32, 1 }, { 128,   0,  64, 1 }, { 224,   0, 128, 1 },
  {  32,  32,   0, 1 }, {  96,  64,   0, 1 }, { 128,  96,  32, 1 }, { 192, 128,  64, 1 },
  {   0,   0,   0, 1 }, { 224,   0,   0, 1 }, { 224, 128,   0, 1 }, {   0, 224,   0, 1 },
  {   0,   0,  64, 1 }, {   0,   0, 160, 1 }, {   0,  96, 224, 1 }, {  96, 192,   0, 1 },
  {  32,   0,   0, 1 }, {  32,  32,   0, 1 }, {  64,  64,  32, 1 }, {  64,  96,  64, 1 },
  {  64,   0,   0, 1 }, { 128,  32,  64, 1 }, { 192,  96,  32, 1 }, { 224, 224,   0, 1 }
};
PALETTEENTRY zone83dcolor[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 128, 192, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 },
  {  64,  64,  64, 1 }, {   0,  96,  64, 1 }, {   0, 160,  96, 1 }, { 192,  96,   0, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  96,  32,   0, 1 }, { 160,  64,  32, 1 },
  { 224, 128,  96, 1 }, { 224, 192, 128, 1 }, { 224, 160,   0, 1 }, { 192,  64,   0, 1 },
  { 160,  32,   0, 1 }, {  64,   0,  32, 1 }, { 128,   0,  64, 1 }, { 224,   0, 128, 1 },
  {  32,  32,   0, 1 }, {  96,  64,   0, 1 }, { 128,  96,  32, 1 }, { 192, 128,  64, 1 },
  {   0,   0,   0, 1 }, { 224,   0,   0, 1 }, { 224, 128,   0, 1 }, {   0, 224,   0, 1 },
  {  64,  32,   0, 1 }, {  64,  64,   0, 1 }, {  96, 128,  32, 1 }, {  64, 192, 128, 1 },
  {  32,   0,   0, 1 }, {   0,  64, 128, 1 }, {   0,  32,  96, 1 }, {   0,  32,  64, 1 },
  {  32,   0,  32, 1 }, {  64,  32,  64, 1 }, {  96,  64, 128, 1 }, {  96, 128, 192, 1 }
};
PALETTEENTRY boss8col_0[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224,   0,   0, 1 }
};
PALETTEENTRY boss8col_00[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
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
  { zone8colora,  16, 48 }, { zone83dcolor, 16, 48 }, { 0,             0,  0 }, { boss8col_1,   80, 16 },
  { boss8col_0,   16, 16 }, { boss8col_00,  48, 16 }, { zone82dcolor, 16, 48 }, { emie8col,     16, 16 }
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







































void clchgctr(void) { /* Line 206, Address: 0x102a000 */
  colchg8d(); /* Line 207, Address: 0x102a008 */
} /* Line 208, Address: 0x102a010 */

void colchg8d(void) { /* Line 210, Address: 0x102a020 */
  clchg_sub0(&clchgtim[0], &clchgcnt[0], col8a0cnt, col8a0col); /* Line 211, Address: 0x102a028 */
  clchg_sub0(&clchgtim[1], &clchgcnt[1], col8a1cnt, col8a1col); /* Line 212, Address: 0x102a050 */
  clchg_sub0(&clchgtim[2], &clchgcnt[2], col8a2cnt, col8a2col); /* Line 213, Address: 0x102a078 */
  if (stageno.b.l == 0) { /* Line 214, Address: 0x102a0a0 */

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a3cnt, col8a3col); /* Line 216, Address: 0x102a0b8 */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a4cnt, col8a4col); /* Line 217, Address: 0x102a0e0 */
    clchg_sub0(&clchgtim[5], &clchgcnt[5], col8a5cnt, col8a5col); /* Line 218, Address: 0x102a108 */
    return; /* Line 219, Address: 0x102a130 */
  }

  if (stageno.b.h + 1 == 1) { /* Line 222, Address: 0x102a138 */

    clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a6cnt, col8a6col); /* Line 224, Address: 0x102a158 */
    clchg_sub0(&clchgtim[4], &clchgcnt[4], col8a7cnt, col8a7col); /* Line 225, Address: 0x102a180 */
    clchg_sub0(&clchgtim[5], &clchgcnt[5], col8a8cnt, col8a8col); /* Line 226, Address: 0x102a1a8 */
    return; /* Line 227, Address: 0x102a1d0 */
  }

  clchg_sub0(&clchgtim[3], &clchgcnt[3], col8a9cnt, col8a9col); /* Line 230, Address: 0x102a1d8 */
  clchg_sub0(&clchgtim[4], &clchgcnt[4], col8aacnt, col8aacol); /* Line 231, Address: 0x102a200 */
  clchg_sub0(&clchgtim[5], &clchgcnt[5], col8abcnt, col8abcol); /* Line 232, Address: 0x102a228 */

} /* Line 234, Address: 0x102a250 */





















void colchg_boss8(unsigned char* a3, unsigned char* a4) { /* Line 256, Address: 0x102a260 */
  PALETTEENTRY* lpPe;
  char d0;

  if (bossstart == 0) return; /* Line 260, Address: 0x102a274 */
  if (++*a4 >= 4) { /* Line 261, Address: 0x102a288 */
    *a4 = 0; /* Line 262, Address: 0x102a2b0 */
    d0 = *a3 + 4; /* Line 263, Address: 0x102a2b8 */
    if (d0 >= 40) d0 = 0; /* Line 264, Address: 0x102a2d8 */

    *a3 = d0; /* Line 266, Address: 0x102a2f0 */
    lpPe = &lpcolorwk[24]; /* Line 267, Address: 0x102a2f8 */
    *lpPe++ = boss8_col1[d0]; /* Line 268, Address: 0x102a304 */
    *lpPe++ = boss8_col1[d0 + 1]; /* Line 269, Address: 0x102a344 */
    *lpPe++ = boss8_col1[d0 + 2]; /* Line 270, Address: 0x102a388 */
    *lpPe++ = boss8_col1[d0 + 3]; /* Line 271, Address: 0x102a3cc */
  }
} /* Line 273, Address: 0x102a410 */








void clchg_sub0(unsigned char* pChgTime, unsigned char* pChgCnt, unsigned char* pCntTbl, PALETTEENTRY* pColTbl) { /* Line 282, Address: 0x102a430 */
  PALETTEENTRY* lpPe;

  --*pChgTime; /* Line 285, Address: 0x102a448 */
  if ((char)*pChgTime < 0) { /* Line 286, Address: 0x102a45c */

    lpPe = &lpcolorwk[*pCntTbl++]; /* Line 288, Address: 0x102a47c */
    ++*pChgCnt; /* Line 289, Address: 0x102a4a0 */
    if (*pChgCnt >= *pCntTbl++) { /* Line 290, Address: 0x102a4b4 */

      *pChgCnt = 0; /* Line 292, Address: 0x102a4e0 */
    }

    pCntTbl = &pCntTbl[*pChgCnt * 2]; /* Line 295, Address: 0x102a4e8 */
    *pChgTime = pCntTbl[0]; /* Line 296, Address: 0x102a504 */
    *lpPe = pColTbl[pCntTbl[1]]; /* Line 297, Address: 0x102a514 */
  }





} /* Line 304, Address: 0x102a54c */

void fadein0(void) { /* Line 306, Address: 0x102a560 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 310, Address: 0x102a56c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 312, Address: 0x102a5a0 */
    lpPe->peRed = 0; /* Line 313, Address: 0x102a5ac */
    lpPe->peGreen = 0; /* Line 314, Address: 0x102a5b0 */
    lpPe->peBlue = 0; /* Line 315, Address: 0x102a5b4 */
    lpPe->peFlags = 1; /* Line 316, Address: 0x102a5b8 */
    ++lpPe; /* Line 317, Address: 0x102a5c0 */
  } /* Line 318, Address: 0x102a5c4 */
  FadeCount = 0; /* Line 319, Address: 0x102a5e0 */
  *lpFadeFlag = 1; /* Line 320, Address: 0x102a5e8 */

} /* Line 322, Address: 0x102a5f8 */



int fadein0_new(void) { /* Line 326, Address: 0x102a610 */

  int_flg = 18; /* Line 328, Address: 0x102a618 */

  fadein1(); /* Line 330, Address: 0x102a624 */


  if (++FadeCount > 21) { /* Line 333, Address: 0x102a62c */
    FadeCount = 0; /* Line 334, Address: 0x102a64c */
    return 1; /* Line 335, Address: 0x102a654 */
  }
  return 0; /* Line 337, Address: 0x102a660 */
} /* Line 338, Address: 0x102a664 */



void fadein1(void) { /* Line 342, Address: 0x102a680 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 346, Address: 0x102a694 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 347, Address: 0x102a6c8 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 349, Address: 0x102a6fc */
    fadein2(lpPe, lpPe2); /* Line 350, Address: 0x102a708 */
    ++lpPe; /* Line 351, Address: 0x102a718 */
    ++lpPe2; /* Line 352, Address: 0x102a71c */
  } /* Line 353, Address: 0x102a720 */
  if (stageno.b.h == 1) return; /* Line 354, Address: 0x102a73c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 356, Address: 0x102a758 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 357, Address: 0x102a78c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 359, Address: 0x102a7c0 */
    fadein2(lpPe, lpPe2); /* Line 360, Address: 0x102a7cc */
    ++lpPe; /* Line 361, Address: 0x102a7dc */
    ++lpPe2; /* Line 362, Address: 0x102a7e0 */
  } /* Line 363, Address: 0x102a7e4 */



} /* Line 367, Address: 0x102a800 */



void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 371, Address: 0x102a820 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 372, Address: 0x102a82c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 375, Address: 0x102a88c */
      lpPeDest->peBlue += 32; /* Line 376, Address: 0x102a8b0 */
    } /* Line 377, Address: 0x102a8c0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 378, Address: 0x102a8c8 */
      lpPeDest->peGreen += 32; /* Line 379, Address: 0x102a8ec */
    } /* Line 380, Address: 0x102a8fc */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 381, Address: 0x102a904 */
      lpPeDest->peRed += 32; /* Line 382, Address: 0x102a928 */
    }
  }

} /* Line 386, Address: 0x102a93c */





void fadein_boss8(void) { /* Line 392, Address: 0x102a950 */
  PALETTEENTRY *lpPe, *lpPe2;

  int_flg = 18; /* Line 395, Address: 0x102a960 */
  lpPe = &lpcolorwk[16]; /* Line 396, Address: 0x102a96c */
  lpPe2 = &lpcolorwk2[16]; /* Line 397, Address: 0x102a978 */
  fadein1_boss8(lpPe, lpPe2); /* Line 398, Address: 0x102a984 */

  lpPe = &lpcolorwk[48]; /* Line 400, Address: 0x102a994 */
  lpPe2 = &lpcolorwk2[48]; /* Line 401, Address: 0x102a9a0 */
  fadein1_boss8(lpPe, lpPe2); /* Line 402, Address: 0x102a9ac */
} /* Line 403, Address: 0x102a9bc */

void fadein1_boss8(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 405, Address: 0x102a9e0 */
  short i;

  for (i = 0; i < 16; ++i) { /* Line 408, Address: 0x102a9f4 */
    fadein2(lpPeDest, lpPeSrc); /* Line 409, Address: 0x102aa00 */
    ++lpPeDest; /* Line 410, Address: 0x102aa10 */
    ++lpPeSrc; /* Line 411, Address: 0x102aa1c */
  } /* Line 412, Address: 0x102aa28 */
} /* Line 413, Address: 0x102aa48 */

void fadeout(void) {
  startcolor = 0; /* Line 416, Address: 0x102aa60 */
  colorcnt = 63; /* Line 417, Address: 0x102aa68 */

  FadeCount = 0; /* Line 419, Address: 0x102aa74 */
  *lpFadeFlag = 2; /* Line 420, Address: 0x102aa7c */

} /* Line 422, Address: 0x102aa8c */



static int fadeout_new(void) { /* Line 426, Address: 0x102aaa0 */

  int_flg = 18; /* Line 428, Address: 0x102aaa8 */

  fadeout1(); /* Line 430, Address: 0x102aab4 */


  if (++FadeCount > 21) { /* Line 433, Address: 0x102aabc */
    FadeCount = 0; /* Line 434, Address: 0x102aadc */
    return 1; /* Line 435, Address: 0x102aae4 */
  }
  return 0; /* Line 437, Address: 0x102aaf0 */
} /* Line 438, Address: 0x102aaf4 */


static void fadeout1(void) { /* Line 441, Address: 0x102ab10 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 445, Address: 0x102ab20 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 447, Address: 0x102ab54 */
    fadeout2(lpPe); /* Line 448, Address: 0x102ab60 */
    ++lpPe; /* Line 449, Address: 0x102ab6c */
  } /* Line 450, Address: 0x102ab70 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 451, Address: 0x102ab8c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 453, Address: 0x102abc0 */
    fadeout2(lpPe); /* Line 454, Address: 0x102abcc */
    ++lpPe; /* Line 455, Address: 0x102abd8 */
  } /* Line 456, Address: 0x102abdc */


} /* Line 459, Address: 0x102abf8 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 462, Address: 0x102ac10 */
  if (lpPeDest->peRed) { /* Line 463, Address: 0x102ac18 */
    lpPeDest->peRed -= 32; /* Line 464, Address: 0x102ac28 */
  } /* Line 465, Address: 0x102ac3c */
  else if (lpPeDest->peGreen) { /* Line 466, Address: 0x102ac44 */
    lpPeDest->peGreen -= 32; /* Line 467, Address: 0x102ac54 */
  } /* Line 468, Address: 0x102ac64 */
  else if (lpPeDest->peBlue) { /* Line 469, Address: 0x102ac6c */
    lpPeDest->peBlue -= 32; /* Line 470, Address: 0x102ac7c */
  }

} /* Line 473, Address: 0x102ac8c */




void flashin(void) { /* Line 478, Address: 0x102aca0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 482, Address: 0x102acac */
  colorcnt = 63; /* Line 483, Address: 0x102acb4 */

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 485, Address: 0x102acc0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 487, Address: 0x102acf4 */
    lpPe->peRed = 224; /* Line 488, Address: 0x102ad00 */
    lpPe->peGreen = 224; /* Line 489, Address: 0x102ad08 */
    lpPe->peBlue = 224; /* Line 490, Address: 0x102ad10 */
    lpPe->peFlags = 1; /* Line 491, Address: 0x102ad18 */
    ++lpPe; /* Line 492, Address: 0x102ad20 */
  } /* Line 493, Address: 0x102ad24 */
  FadeCount = 0; /* Line 494, Address: 0x102ad40 */
  *lpFadeFlag = 3; /* Line 495, Address: 0x102ad48 */

} /* Line 497, Address: 0x102ad58 */

static int flashin_new(void) { /* Line 499, Address: 0x102ad70 */

  int_flg = 18; /* Line 501, Address: 0x102ad78 */

  flashin1(); /* Line 503, Address: 0x102ad84 */


  if (++FadeCount > 21) { /* Line 506, Address: 0x102ad8c */
    FadeCount = 0; /* Line 507, Address: 0x102adac */
    return 1; /* Line 508, Address: 0x102adb4 */
  }
  return 0; /* Line 510, Address: 0x102adc0 */
} /* Line 511, Address: 0x102adc4 */

static void flashin1(void) { /* Line 513, Address: 0x102ade0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 517, Address: 0x102adf4 */
  lpPe2 = &lpcolorwk2[startcolor / 2]; /* Line 518, Address: 0x102ae28 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 520, Address: 0x102ae5c */
    flashin2(lpPe, lpPe2); /* Line 521, Address: 0x102ae68 */
    ++lpPe; /* Line 522, Address: 0x102ae78 */
    ++lpPe2; /* Line 523, Address: 0x102ae7c */
  } /* Line 524, Address: 0x102ae80 */
  if (stageno.b.h == 1) return; /* Line 525, Address: 0x102ae9c */

  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 527, Address: 0x102aeb8 */
  lpPe2 = &lpcolorwk4[startcolor / 2]; /* Line 528, Address: 0x102aeec */

  for (i = 0; colorcnt >= i; ++i) { /* Line 530, Address: 0x102af20 */
    flashin2(lpPe, lpPe2); /* Line 531, Address: 0x102af2c */
    ++lpPe; /* Line 532, Address: 0x102af3c */
    ++lpPe2; /* Line 533, Address: 0x102af40 */
  } /* Line 534, Address: 0x102af44 */



} /* Line 538, Address: 0x102af60 */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 542, Address: 0x102af80 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 543, Address: 0x102af8c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 546, Address: 0x102afec */
      lpPeDest->peBlue -= 32; /* Line 547, Address: 0x102b010 */
    } /* Line 548, Address: 0x102b020 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 549, Address: 0x102b028 */
      lpPeDest->peGreen -= 32; /* Line 550, Address: 0x102b04c */
    } /* Line 551, Address: 0x102b05c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 552, Address: 0x102b064 */
      lpPeDest->peRed -= 32; /* Line 553, Address: 0x102b088 */
    }
  }

} /* Line 557, Address: 0x102b09c */


void flashout(void) {
  startcolor = 0; /* Line 561, Address: 0x102b0b0 */
  colorcnt = 63; /* Line 562, Address: 0x102b0b8 */

  FadeCount = 0; /* Line 564, Address: 0x102b0c4 */
  *lpFadeFlag = 4; /* Line 565, Address: 0x102b0cc */

} /* Line 567, Address: 0x102b0dc */

static int flashout_new(void) { /* Line 569, Address: 0x102b0f0 */

  int_flg = 18; /* Line 571, Address: 0x102b0f8 */

  flashout1(); /* Line 573, Address: 0x102b104 */


  if (++FadeCount > 21) { /* Line 576, Address: 0x102b10c */
    FadeCount = 0; /* Line 577, Address: 0x102b12c */
    return 1; /* Line 578, Address: 0x102b134 */
  }
  return 0; /* Line 580, Address: 0x102b140 */
} /* Line 581, Address: 0x102b144 */


static void flashout1(void) { /* Line 584, Address: 0x102b160 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk[startcolor / 2]; /* Line 588, Address: 0x102b170 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 590, Address: 0x102b1a4 */
    flashout2(lpPe); /* Line 591, Address: 0x102b1b0 */
    ++lpPe; /* Line 592, Address: 0x102b1bc */
  } /* Line 593, Address: 0x102b1c0 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 594, Address: 0x102b1dc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 596, Address: 0x102b210 */
    flashout2(lpPe); /* Line 597, Address: 0x102b21c */
    ++lpPe; /* Line 598, Address: 0x102b228 */
  } /* Line 599, Address: 0x102b22c */


} /* Line 602, Address: 0x102b248 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 605, Address: 0x102b260 */
  if (lpPeDest->peRed != 224) { /* Line 606, Address: 0x102b268 */
    lpPeDest->peRed += 32; /* Line 607, Address: 0x102b280 */
  } /* Line 608, Address: 0x102b294 */
  else if (lpPeDest->peGreen != 224) { /* Line 609, Address: 0x102b29c */
    lpPeDest->peGreen += 32; /* Line 610, Address: 0x102b2b4 */
  } /* Line 611, Address: 0x102b2c4 */
  else if (lpPeDest->peBlue != 224) { /* Line 612, Address: 0x102b2cc */
    lpPeDest->peBlue += 32; /* Line 613, Address: 0x102b2e4 */
  }


} /* Line 617, Address: 0x102b2f4 */

void colorset(int ColorNo) { /* Line 619, Address: 0x102b300 */
  colorset00(ColorNo, 1); /* Line 620, Address: 0x102b30c */
} /* Line 621, Address: 0x102b31c */

void colorset2(int ColorNo) { /* Line 623, Address: 0x102b330 */
  colorset00(ColorNo, 0); /* Line 624, Address: 0x102b33c */
} /* Line 625, Address: 0x102b34c */

void colorset3(int ColorNo) { /* Line 627, Address: 0x102b360 */
  colorset00(ColorNo, 0); /* Line 628, Address: 0x102b36c */
} /* Line 629, Address: 0x102b37c */





static void colorset00(int ColorNo, int WorkOffs) { /* Line 635, Address: 0x102b390 */
  PALETTEENTRY* lppe;
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i, n;

  switch (WorkOffs + colortbl[ColorNo].offset / 64) { /* Line 640, Address: 0x102b3b0 */
    case 0:
      lppe = lpcolorwk; break; /* Line 642, Address: 0x102b418 */
    case 1:
      lppe = lpcolorwk2; break; /* Line 644, Address: 0x102b428 */
    case 2:
      lppe = lpcolorwk3; break; /* Line 646, Address: 0x102b438 */
    default:
      lppe = lpcolorwk4; break; /* Line 648, Address: 0x102b448 */
  }

  lpPeSrc = colortbl[ColorNo].PeSrc; /* Line 651, Address: 0x102b450 */
  lpPeDest = &lppe[colortbl[ColorNo].offset % 64]; /* Line 652, Address: 0x102b468 */
  n = colortbl[ColorNo].cnt; /* Line 653, Address: 0x102b4ac */
  for (i = 0; i < n; ++i) { /* Line 654, Address: 0x102b4cc */
    *lpPeDest++ = *lpPeSrc++; /* Line 655, Address: 0x102b4d8 */
  } /* Line 656, Address: 0x102b508 */

} /* Line 658, Address: 0x102b518 */




int FadeProc(void) { /* Line 663, Address: 0x102b540 */
  switch (*lpFadeFlag) { /* Line 664, Address: 0x102b548 */
    case 1:
      return fadein0_new(); /* Line 666, Address: 0x102b58c */
    case 2:
      return fadeout_new(); /* Line 668, Address: 0x102b59c */
    case 3:
      return flashin_new(); /* Line 670, Address: 0x102b5ac */
    case 4:
      return flashout_new(); /* Line 672, Address: 0x102b5bc */
  }
  return 1; /* Line 674, Address: 0x102b5cc */

} /* Line 676, Address: 0x102b5d0 */
