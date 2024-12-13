#include "..\EQU.H"
#include "DEV61A.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int sp1cg[4] = { 0, 1, 2, 3 };
static int sp2cg[4] = { 4, 5, 6, 7 };
static int t1cg[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };
static int t2cg[8] = { 16, 17, 18, 19, 20, 21, 22, 23 };
static int t3cg[8] = { 24, 25, 26, 27, 28, 29, 30, 31 };
static int r01cg[4] = { 32, 33, 34, 35 };
static int r02cg[4] = { 36, 37, 38, 39 };
static int r03cg[4] = { 40, 41, 42, 43 };
static int r04cg[4] = { 44, 45, 46, 47 };
static tile_changes tbl_thund = {
  3,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 }
  },
  {
    t1cg,
    t2cg,
    t3cg
  },
  321
};
static tile_changes tbl_sp = {
  2,
  0,
  {
    { 2, 0 },
    { 2, 1 }
  },
  {
    sp1cg,
    sp2cg
  },
  317
};
static tile_changes tbl_light = {
  4,
  0,
  {
    { 4, 0 },
    { 9, 1 },
    { 4, 2 },
    { 15, 3 }
  },
  {
    r01cg,
    r02cg,
    r03cg,
    r04cg
  },
  313
};
extern void(*ChangeTileBmp)(int, int);























































































void cg_change() { /* Line 149, Address: 0x102bac0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 153, Address: 0x102bacc */
  pcgchgcnt = cgchgcnt; /* Line 154, Address: 0x102bad8 */

  if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 156, Address: 0x102bae4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 158, Address: 0x102bb10 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 159, Address: 0x102bb1c */
    } /* Line 160, Address: 0x102bb3c */
  }


  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 164, Address: 0x102bb58 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 166, Address: 0x102bb84 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 167, Address: 0x102bb90 */
    } /* Line 168, Address: 0x102bbb0 */
  }


  if (cg_chg1(&tbl_light, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 172, Address: 0x102bbcc */

    for (i = 0; i < 4; ++i, ++top) { /* Line 174, Address: 0x102bbf8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 175, Address: 0x102bc04 */
    } /* Line 176, Address: 0x102bc24 */
  }
} /* Line 178, Address: 0x102bc40 */






















unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 201, Address: 0x102bc60 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 205, Address: 0x102bc88 */
  if (Timwk >= 0) { /* Line 206, Address: 0x102bcb4 */

    ++*ppChgTim; /* Line 208, Address: 0x102bcc4 */
    ++*ppChgCnt; /* Line 209, Address: 0x102bcd8 */
    return 0; /* Line 210, Address: 0x102bcec */
  }

  tblidx = **ppChgCnt; /* Line 213, Address: 0x102bcf8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 214, Address: 0x102bd08 */
    tblidx = 0; /* Line 215, Address: 0x102bd28 */
  }


  **ppChgCnt = tblidx; /* Line 219, Address: 0x102bd2c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 220, Address: 0x102bd3c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 222, Address: 0x102bd58 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 223, Address: 0x102bd78 */

  for ( ; iNum >= 0; --iNum) { /* Line 225, Address: 0x102bd88 */
    *BmpNo++ = *pNoTbl++; /* Line 226, Address: 0x102bd90 */
  } /* Line 227, Address: 0x102bdac */


  ++*ppChgTim; /* Line 230, Address: 0x102bdc4 */
  ++*ppChgCnt; /* Line 231, Address: 0x102bdd8 */
  *TileStart = pTbl->TileStart; /* Line 232, Address: 0x102bdec */
  return 1; /* Line 233, Address: 0x102bdfc */
} /* Line 234, Address: 0x102be00 */
