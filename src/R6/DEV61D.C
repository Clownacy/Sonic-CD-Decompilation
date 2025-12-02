#include "..\EQU.H"
#include "DEV61A.H"
#include "..\IMPFUNCS.H"

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
  380
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
  376
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
  372
};























































































void cg_change() { /* Line 149, Address: 0x102b6c0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 153, Address: 0x102b6cc */
  pcgchgcnt = cgchgcnt; /* Line 154, Address: 0x102b6d8 */

  if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 156, Address: 0x102b6e4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 158, Address: 0x102b710 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 159, Address: 0x102b71c */
    } /* Line 160, Address: 0x102b73c */
  }


  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 164, Address: 0x102b758 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 166, Address: 0x102b784 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 167, Address: 0x102b790 */
    } /* Line 168, Address: 0x102b7b0 */
  }


  if (cg_chg1(&tbl_light, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 172, Address: 0x102b7cc */

    for (i = 0; i < 4; ++i, ++top) { /* Line 174, Address: 0x102b7f8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 175, Address: 0x102b804 */
    } /* Line 176, Address: 0x102b824 */
  }
} /* Line 178, Address: 0x102b840 */






















unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 201, Address: 0x102b860 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 205, Address: 0x102b888 */
  if (Timwk >= 0) { /* Line 206, Address: 0x102b8b4 */

    ++*ppChgTim; /* Line 208, Address: 0x102b8c4 */
    ++*ppChgCnt; /* Line 209, Address: 0x102b8d8 */
    return 0; /* Line 210, Address: 0x102b8ec */
  }

  tblidx = **ppChgCnt; /* Line 213, Address: 0x102b8f8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 214, Address: 0x102b908 */
    tblidx = 0; /* Line 215, Address: 0x102b928 */
  }


  **ppChgCnt = tblidx; /* Line 219, Address: 0x102b92c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 220, Address: 0x102b93c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 222, Address: 0x102b958 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 223, Address: 0x102b978 */

  for ( ; iNum >= 0; --iNum) { /* Line 225, Address: 0x102b988 */
    *BmpNo++ = *pNoTbl++; /* Line 226, Address: 0x102b990 */
  } /* Line 227, Address: 0x102b9ac */


  ++*ppChgTim; /* Line 230, Address: 0x102b9c4 */
  ++*ppChgCnt; /* Line 231, Address: 0x102b9d8 */
  *TileStart = pTbl->TileStart; /* Line 232, Address: 0x102b9ec */
  return 1; /* Line 233, Address: 0x102b9fc */
} /* Line 234, Address: 0x102ba00 */
