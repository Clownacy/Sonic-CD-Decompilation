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
























































































void cg_change(void) { /* Line 150, Address: 0x10264c0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 154, Address: 0x10264cc */
  pcgchgcnt = cgchgcnt; /* Line 155, Address: 0x10264d8 */

  if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 157, Address: 0x10264e4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 159, Address: 0x1026510 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 160, Address: 0x102651c */
    } /* Line 161, Address: 0x102653c */
  }


  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 165, Address: 0x1026558 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 167, Address: 0x1026584 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 168, Address: 0x1026590 */
    } /* Line 169, Address: 0x10265b0 */
  }


  if (cg_chg1(&tbl_light, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 173, Address: 0x10265cc */

    for (i = 0; i < 4; ++i, ++top) { /* Line 175, Address: 0x10265f8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 176, Address: 0x1026604 */
    } /* Line 177, Address: 0x1026624 */
  }
} /* Line 179, Address: 0x1026640 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 202, Address: 0x1026660 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 206, Address: 0x1026688 */
  if (Timwk >= 0) { /* Line 207, Address: 0x10266b4 */

    ++*ppChgTim; /* Line 209, Address: 0x10266c4 */
    ++*ppChgCnt; /* Line 210, Address: 0x10266d8 */
    return 0; /* Line 211, Address: 0x10266ec */
  }

  tblidx = **ppChgCnt; /* Line 214, Address: 0x10266f8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 215, Address: 0x1026708 */
    tblidx = 0; /* Line 216, Address: 0x1026728 */
  }


  **ppChgCnt = tblidx; /* Line 220, Address: 0x102672c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 221, Address: 0x102673c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 223, Address: 0x1026758 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 224, Address: 0x1026778 */

  for ( ; iNum >= 0; --iNum) { /* Line 226, Address: 0x1026788 */
    *BmpNo++ = *pNoTbl++; /* Line 227, Address: 0x1026790 */
  } /* Line 228, Address: 0x10267ac */


  ++*ppChgTim; /* Line 231, Address: 0x10267c4 */
  ++*ppChgCnt; /* Line 232, Address: 0x10267d8 */
  *TileStart = pTbl->TileStart; /* Line 233, Address: 0x10267ec */
  return 1; /* Line 234, Address: 0x10267fc */
} /* Line 235, Address: 0x1026800 */
