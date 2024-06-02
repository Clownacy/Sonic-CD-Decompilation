#include "..\EQU.H"
#include "DEV41A.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int fire0cg[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
static int fire1cg[16] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
static int fire2cg[16] = { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 };
static int fire3cg[16] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 };
static int fire4cg[16] = { 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 };
static int fire5cg[16] = { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95 };
static int fire6cg[16] = { 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111 };
static int fire7cg[16] = { 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127 };
static tile_changes tbl_fir0 = {
  24,
  0,
  {
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 },
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 },
    { 60, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  6, 0 },
    {  6, 0 }
  },
  {
    fire0cg,
    fire1cg,
    fire2cg,
    fire3cg,
    fire4cg,
    fire5cg,
    fire6cg,
    fire7cg
  },
  558
};
static tile_changes tbl_fir1 = {
  24,
  0,
  {
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 },
    { 60, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  6, 0 },
    {  6, 0 },
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 }
  },
  {
    fire0cg,
    fire1cg,
    fire2cg,
    fire3cg,
    fire4cg,
    fire5cg,
    fire6cg,
    fire7cg
  },
  574
};
static tile_changes tbl_fir2 = {
  24,
  0,
  {
    { 60, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  8, 0 },
    {  6, 0 },
    {  6, 0 },
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 },
    { 60, 0 },
    {  8, 1 },
    {  8, 2 },
    {  8, 3 },
    {  8, 4 },
    {  8, 5 },
    {  6, 6 },
    {  6, 7 }
  },
  {
    fire0cg,
    fire1cg,
    fire2cg,
    fire3cg,
    fire4cg,
    fire5cg,
    fire6cg,
    fire7cg
  },
  590
};
extern void(*ChangeTileBmp)(int, int);















































































void cg_change() { /* Line 218, Address: 0x1017cc0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  if (pauseflag.b.h) return; /* Line 222, Address: 0x1017ccc */






  if (scra_h_posit.w.h >= 640 || scra_v_posit.w.h >= 352) /* Line 229, Address: 0x1017cdc */
    return; /* Line 230, Address: 0x1017d14 */


  pcgchgtim = cgchgtim; /* Line 233, Address: 0x1017d1c */
  pcgchgcnt = cgchgcnt; /* Line 234, Address: 0x1017d28 */

  if (cg_chg1(&tbl_fir0, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 236, Address: 0x1017d34 */

    for (i = 0; i < 16; ++i, ++top) { /* Line 238, Address: 0x1017d60 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 239, Address: 0x1017d6c */
    } /* Line 240, Address: 0x1017d8c */
  }


  if (cg_chg1(&tbl_fir1, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 244, Address: 0x1017da8 */

    for (i = 0; i < 16; ++i, ++top) { /* Line 246, Address: 0x1017dd4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 247, Address: 0x1017de0 */
    } /* Line 248, Address: 0x1017e00 */
  }


  if (cg_chg1(&tbl_fir2, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 252, Address: 0x1017e1c */

    for (i = 0; i < 16; ++i, ++top) { /* Line 254, Address: 0x1017e48 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 255, Address: 0x1017e54 */
    } /* Line 256, Address: 0x1017e74 */
  }
} /* Line 258, Address: 0x1017e90 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 281, Address: 0x1017eb0 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 285, Address: 0x1017ed8 */
  if (Timwk >= 0) { /* Line 286, Address: 0x1017f04 */

    ++*ppChgTim; /* Line 288, Address: 0x1017f14 */
    ++*ppChgCnt; /* Line 289, Address: 0x1017f28 */
    return 0; /* Line 290, Address: 0x1017f3c */
  }

  tblidx = **ppChgCnt; /* Line 293, Address: 0x1017f48 */
  if (++tblidx >= pTbl->chgcnt) /* Line 294, Address: 0x1017f58 */
    tblidx = 0; /* Line 295, Address: 0x1017f78 */



  **ppChgCnt = tblidx; /* Line 299, Address: 0x1017f7c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 300, Address: 0x1017f8c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 302, Address: 0x1017fa8 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 303, Address: 0x1017fc8 */

  for ( ; iNum >= 0; --iNum) { /* Line 305, Address: 0x1017fd8 */
    *BmpNo++ = *pNoTbl++; /* Line 306, Address: 0x1017fe0 */
  } /* Line 307, Address: 0x1017ffc */


  ++*ppChgTim; /* Line 310, Address: 0x1018014 */
  ++*ppChgCnt; /* Line 311, Address: 0x1018028 */
  *TileStart = pTbl->TileStart; /* Line 312, Address: 0x101803c */
  return 1; /* Line 313, Address: 0x101804c */
} /* Line 314, Address: 0x1018050 */
