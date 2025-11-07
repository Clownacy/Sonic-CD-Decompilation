#include "..\EQU.H"
#include "DEV32A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int drum_re0cg[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static int drum_re1cg[8] = { 10, 11, 12, 13, 14, 15, 16, 17 };
static int drum_no0cg[10] = { 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
static int drum_no1cg[8] = { 28, 29, 30, 31, 32, 33, 34, 35 };
static tile_changes tbl_drumb00 = {
  2,
  0,
  {
    { 10, 0 },
    { 10, 1 }
  },
  {
    drum_no0cg,
    drum_re0cg
  },
  417
};
static tile_changes tbl_drumb01 = {
  2,
  0,
  {
    { 10, 0 },
    { 10, 1 }
  },
  {
    drum_no1cg,
    drum_re1cg
  },
  443
};

















































































void cg_change(void) { /* Line 119, Address: 0x1026d00 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 123, Address: 0x1026d0c */
  pcgchgcnt = cgchgcnt; /* Line 124, Address: 0x1026d18 */

  if (cg_chg1(&tbl_drumb00, 9, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 126, Address: 0x1026d24 */

    for (i = 0; i < 10; ++i, ++top) { /* Line 128, Address: 0x1026d50 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 129, Address: 0x1026d5c */
    } /* Line 130, Address: 0x1026d7c */
  }

  if (cg_chg1(&tbl_drumb01, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 133, Address: 0x1026d98 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 135, Address: 0x1026dc4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 136, Address: 0x1026dd0 */
    } /* Line 137, Address: 0x1026df0 */
  }
} /* Line 139, Address: 0x1026e0c */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 162, Address: 0x1026e20 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 166, Address: 0x1026e48 */
  if (Timwk >= 0) { /* Line 167, Address: 0x1026e74 */

    ++*ppChgTim; /* Line 169, Address: 0x1026e84 */
    ++*ppChgCnt; /* Line 170, Address: 0x1026e98 */
    return 0; /* Line 171, Address: 0x1026eac */
  }

  tblidx = **ppChgCnt; /* Line 174, Address: 0x1026eb8 */
  if (++tblidx >= pTbl->chgcnt) /* Line 175, Address: 0x1026ec8 */
    tblidx = 0; /* Line 176, Address: 0x1026ee8 */



  **ppChgCnt = tblidx; /* Line 180, Address: 0x1026eec */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 181, Address: 0x1026efc */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 183, Address: 0x1026f18 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 184, Address: 0x1026f38 */

  for ( ; iNum >= 0; --iNum) { /* Line 186, Address: 0x1026f48 */
    *BmpNo++ = *pNoTbl++; /* Line 187, Address: 0x1026f50 */
  } /* Line 188, Address: 0x1026f6c */


  ++*ppChgTim; /* Line 191, Address: 0x1026f84 */
  ++*ppChgCnt; /* Line 192, Address: 0x1026f98 */
  *TileStart = pTbl->TileStart; /* Line 193, Address: 0x1026fac */
  return 1; /* Line 194, Address: 0x1026fbc */
} /* Line 195, Address: 0x1026fc0 */
