#include "..\EQU.H"
#include "DEV61A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int nullcg[8];
static int sp1cg[4] = { 1, 2, 3, 4 };
static int sp2cg[4] = { 5, 6, 7, 8 };
static int t1cg[8] = { 9, 10, 11, 12, 13, 14, 15, 16 };
static int t2cg[8] = { 17, 18, 19, 20, 21, 22, 23, 24 };
static int t3cg[8] = { 25, 26, 27, 28, 29, 30, 31, 32 };
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
  347
};
static tile_changes tbl_null = {
  3,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 }
  },
  {
    nullcg,
    nullcg,
    nullcg
  },
  347
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
  343
};


















































































void cg_change(void) { /* Line 139, Address: 0x102b660 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 143, Address: 0x102b66c */
  pcgchgcnt = cgchgcnt; /* Line 144, Address: 0x102b678 */

  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 146, Address: 0x102b684 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 148, Address: 0x102b6b0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 149, Address: 0x102b6bc */
    } /* Line 150, Address: 0x102b6dc */
  }

  --cgchgtim[2]; /* Line 153, Address: 0x102b6f8 */
  if ((char)cgchgtim[2] < 0) { /* Line 154, Address: 0x102b70c */


    cgchgtim[2] ^= 1; /* Line 157, Address: 0x102b72c */
    if (cgchgtim[2] == 0) cgchgtim[2] = 90; /* Line 158, Address: 0x102b740 */
    else cgchgtim[2] = 30; /* Line 159, Address: 0x102b768 */
  }

  if (cgchgtim[2] != 0) { /* Line 162, Address: 0x102b774 */


    if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 165, Address: 0x102b788 */

      for (i = 0; i < 8; ++i, ++top) { /* Line 167, Address: 0x102b7b4 */
        ChangeTileBmp(top, playsubdma[i]); /* Line 168, Address: 0x102b7c0 */
      } /* Line 169, Address: 0x102b7e0 */
    }
    return; /* Line 171, Address: 0x102b7fc */
  }

  if (cg_chg1(&tbl_null, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 174, Address: 0x102b804 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 176, Address: 0x102b830 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 177, Address: 0x102b83c */
    } /* Line 178, Address: 0x102b85c */
  }
} /* Line 180, Address: 0x102b878 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 203, Address: 0x102b890 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 207, Address: 0x102b8b8 */
  if (Timwk >= 0) { /* Line 208, Address: 0x102b8e4 */

    ++*ppChgTim; /* Line 210, Address: 0x102b8f4 */
    ++*ppChgCnt; /* Line 211, Address: 0x102b908 */
    return 0; /* Line 212, Address: 0x102b91c */
  }

  tblidx = **ppChgCnt; /* Line 215, Address: 0x102b928 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 216, Address: 0x102b938 */
    tblidx = 0; /* Line 217, Address: 0x102b958 */
  }


  **ppChgCnt = tblidx; /* Line 221, Address: 0x102b95c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 222, Address: 0x102b96c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 224, Address: 0x102b988 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 225, Address: 0x102b9a8 */

  for ( ; iNum >= 0; --iNum) { /* Line 227, Address: 0x102b9b8 */
    *BmpNo++ = *pNoTbl++; /* Line 228, Address: 0x102b9c0 */
  } /* Line 229, Address: 0x102b9dc */


  ++*ppChgTim; /* Line 232, Address: 0x102b9f4 */
  ++*ppChgCnt; /* Line 233, Address: 0x102ba08 */
  *TileStart = pTbl->TileStart; /* Line 234, Address: 0x102ba1c */
  return 1; /* Line 235, Address: 0x102ba2c */
} /* Line 236, Address: 0x102ba30 */
