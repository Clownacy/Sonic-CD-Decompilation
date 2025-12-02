#include "..\EQU.H"
#include "DEV81A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 5, 5, 129 };
static int pan1cg[4] = { 0, 1, 2, 3 };
static int pan2cg[4] = { 4, 5, 6, 7 };
static int pan3cg[4] = { 8, 9, 10, 11 };
static int pan4cg[4] = { 12, 13, 14, 15 };
static int pan5cg[4] = { 16, 17, 18, 19 };
static int pan6cg[4] = { 20, 21, 22, 23 };
static tile_changes tbl_pan = {
  6,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 },
    { 4, 3 },
    { 4, 4 },
    { 4, 5 }
  },
  {
    pan1cg,
    pan2cg,
    pan3cg,
    pan4cg,
    pan5cg,
    pan6cg
  },
  444
};


















































































void cg_change(void) { /* Line 117, Address: 0x102aae0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 121, Address: 0x102aaec */
  pcgchgcnt = cgchgcnt; /* Line 122, Address: 0x102aaf8 */

  if (cg_chg1(&tbl_pan, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 124, Address: 0x102ab04 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 126, Address: 0x102ab30 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 127, Address: 0x102ab3c */
    } /* Line 128, Address: 0x102ab5c */
  }
} /* Line 130, Address: 0x102ab78 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 153, Address: 0x102ab90 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 157, Address: 0x102abb8 */
  if (Timwk >= 0) { /* Line 158, Address: 0x102abe4 */

    ++*ppChgTim; /* Line 160, Address: 0x102abf4 */
    ++*ppChgCnt; /* Line 161, Address: 0x102ac08 */
    return 0; /* Line 162, Address: 0x102ac1c */
  }

  tblidx = **ppChgCnt; /* Line 165, Address: 0x102ac28 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 166, Address: 0x102ac38 */
    tblidx = 0; /* Line 167, Address: 0x102ac58 */
  }


  **ppChgCnt = tblidx; /* Line 171, Address: 0x102ac5c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 172, Address: 0x102ac6c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 174, Address: 0x102ac88 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 175, Address: 0x102aca8 */

  for ( ; iNum >= 0; --iNum) { /* Line 177, Address: 0x102acb8 */
    *BmpNo++ = *pNoTbl++; /* Line 178, Address: 0x102acc0 */
  } /* Line 179, Address: 0x102acdc */


  ++*ppChgTim; /* Line 182, Address: 0x102acf4 */
  ++*ppChgCnt; /* Line 183, Address: 0x102ad08 */
  *TileStart = pTbl->TileStart; /* Line 184, Address: 0x102ad1c */
  return 1; /* Line 185, Address: 0x102ad2c */
} /* Line 186, Address: 0x102ad30 */
