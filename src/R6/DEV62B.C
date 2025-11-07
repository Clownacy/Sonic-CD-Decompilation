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
  333
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
  329
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
  325
};























































































void cg_change(void) { /* Line 149, Address: 0x102b0a0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 153, Address: 0x102b0ac */
  pcgchgcnt = cgchgcnt; /* Line 154, Address: 0x102b0b8 */

  if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 156, Address: 0x102b0c4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 158, Address: 0x102b0f0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 159, Address: 0x102b0fc */
    } /* Line 160, Address: 0x102b11c */
  }


  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 164, Address: 0x102b138 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 166, Address: 0x102b164 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 167, Address: 0x102b170 */
    } /* Line 168, Address: 0x102b190 */
  }


  if (cg_chg1(&tbl_light, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 172, Address: 0x102b1ac */

    for (i = 0; i < 4; ++i, ++top) { /* Line 174, Address: 0x102b1d8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 175, Address: 0x102b1e4 */
    } /* Line 176, Address: 0x102b204 */
  }
} /* Line 178, Address: 0x102b220 */






















unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 201, Address: 0x102b240 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 205, Address: 0x102b268 */
  if (Timwk >= 0) { /* Line 206, Address: 0x102b294 */

    ++*ppChgTim; /* Line 208, Address: 0x102b2a4 */
    ++*ppChgCnt; /* Line 209, Address: 0x102b2b8 */
    return 0; /* Line 210, Address: 0x102b2cc */
  }

  tblidx = **ppChgCnt; /* Line 213, Address: 0x102b2d8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 214, Address: 0x102b2e8 */
    tblidx = 0; /* Line 215, Address: 0x102b308 */
  }


  **ppChgCnt = tblidx; /* Line 219, Address: 0x102b30c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 220, Address: 0x102b31c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 222, Address: 0x102b338 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 223, Address: 0x102b358 */

  for ( ; iNum >= 0; --iNum) { /* Line 225, Address: 0x102b368 */
    *BmpNo++ = *pNoTbl++; /* Line 226, Address: 0x102b370 */
  } /* Line 227, Address: 0x102b38c */


  ++*ppChgTim; /* Line 230, Address: 0x102b3a4 */
  ++*ppChgCnt; /* Line 231, Address: 0x102b3b8 */
  *TileStart = pTbl->TileStart; /* Line 232, Address: 0x102b3cc */
  return 1; /* Line 233, Address: 0x102b3dc */
} /* Line 234, Address: 0x102b3e0 */
