#include "..\EQU.H"
#include "DEV32A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 5, 5, 129 };
static int drum_re0cg[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static int drum_re1cg[6] = { 10, 11, 12, 13, 14, 15 };
static int drum_no0cg[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
static int drum_no1cg[6] = { 26, 27, 28, 29, 30, 31 };
static tile_changes tbl_drum00 = {
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
  436
};
static tile_changes tbl_drum01 = {
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
  462
};

















































































void cg_change(void) { /* Line 119, Address: 0x10297c0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 123, Address: 0x10297cc */
  pcgchgcnt = cgchgcnt; /* Line 124, Address: 0x10297d8 */

  if (cg_chg1(&tbl_drum00, 9, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 126, Address: 0x10297e4 */

    for (i = 0; i < 10; ++i, ++top) { /* Line 128, Address: 0x1029810 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 129, Address: 0x102981c */
    } /* Line 130, Address: 0x102983c */
  }

  if (cg_chg1(&tbl_drum01, 5, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 133, Address: 0x1029858 */

    for (i = 0; i < 6; ++i, ++top) { /* Line 135, Address: 0x1029884 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 136, Address: 0x1029890 */
    } /* Line 137, Address: 0x10298b0 */
  }
} /* Line 139, Address: 0x10298cc */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 162, Address: 0x10298e0 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 166, Address: 0x1029908 */
  if (Timwk >= 0) { /* Line 167, Address: 0x1029934 */

    ++*ppChgTim; /* Line 169, Address: 0x1029944 */
    ++*ppChgCnt; /* Line 170, Address: 0x1029958 */
    return 0; /* Line 171, Address: 0x102996c */
  }

  tblidx = **ppChgCnt; /* Line 174, Address: 0x1029978 */
  if (++tblidx >= pTbl->chgcnt) /* Line 175, Address: 0x1029988 */
    tblidx = 0; /* Line 176, Address: 0x10299a8 */



  **ppChgCnt = tblidx; /* Line 180, Address: 0x10299ac */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 181, Address: 0x10299bc */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 183, Address: 0x10299d8 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 184, Address: 0x10299f8 */

  for ( ; iNum >= 0; --iNum) { /* Line 186, Address: 0x1029a08 */
    *BmpNo++ = *pNoTbl++; /* Line 187, Address: 0x1029a10 */
  } /* Line 188, Address: 0x1029a2c */


  ++*ppChgTim; /* Line 191, Address: 0x1029a44 */
  ++*ppChgCnt; /* Line 192, Address: 0x1029a58 */
  *TileStart = pTbl->TileStart; /* Line 193, Address: 0x1029a6c */
  return 1; /* Line 194, Address: 0x1029a7c */
} /* Line 195, Address: 0x1029a80 */
