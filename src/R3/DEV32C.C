#include "..\EQU.H"
#include "DEV32A.H"

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 7, 7, 129 };
int drum_re0cg[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int drum_re1cg[8] = { 10, 11, 12, 13, 14, 15, 16, 17 };
int drum_no0cg[10] = { 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
int drum_no1cg[8] = { 28, 29, 30, 31, 32, 33, 34, 35 };
tile_changes tbl_drumg00 = {
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
  438
};
tile_changes tbl_drumg01 = {
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
  464
};
extern void(*ChangeTileBmp)(int, int);




















































































void cg_change() { /* Line 120, Address: 0x1026ce0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 124, Address: 0x1026cec */
  pcgchgcnt = cgchgcnt; /* Line 125, Address: 0x1026cf8 */

  if (cg_chg1(&tbl_drumg00, 9, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 127, Address: 0x1026d04 */

    for (i = 0; i < 10; ++i, ++top) { /* Line 129, Address: 0x1026d30 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 130, Address: 0x1026d3c */
    } /* Line 131, Address: 0x1026d5c */
  }

  if (cg_chg1(&tbl_drumg01, 5, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 134, Address: 0x1026d78 */

    for (i = 0; i < 6; ++i, ++top) { /* Line 136, Address: 0x1026da4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 137, Address: 0x1026db0 */
    } /* Line 138, Address: 0x1026dd0 */
  }
} /* Line 140, Address: 0x1026dec */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 163, Address: 0x1026e00 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 167, Address: 0x1026e28 */
  if (Timwk >= 0) { /* Line 168, Address: 0x1026e54 */

    ++*ppChgTim; /* Line 170, Address: 0x1026e64 */
    ++*ppChgCnt; /* Line 171, Address: 0x1026e78 */
    return 0; /* Line 172, Address: 0x1026e8c */
  }

  tblidx = **ppChgCnt; /* Line 175, Address: 0x1026e98 */
  if (++tblidx >= pTbl->chgcnt) /* Line 176, Address: 0x1026ea8 */
    tblidx = 0; /* Line 177, Address: 0x1026ec8 */



  **ppChgCnt = tblidx; /* Line 181, Address: 0x1026ecc */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 182, Address: 0x1026edc */

  tblidx = pTbl->dattbl[tblidx].no; /* Line 184, Address: 0x1026ef8 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 185, Address: 0x1026f18 */

  for ( ; iNum >= 0; --iNum) { /* Line 187, Address: 0x1026f28 */
    *BmpNo++ = *pNoTbl++; /* Line 188, Address: 0x1026f30 */
  } /* Line 189, Address: 0x1026f4c */


  ++*ppChgTim; /* Line 192, Address: 0x1026f64 */
  ++*ppChgCnt; /* Line 193, Address: 0x1026f78 */
  *TileStart = pTbl->TileStart; /* Line 194, Address: 0x1026f8c */
  return 1; /* Line 195, Address: 0x1026f9c */
} /* Line 196, Address: 0x1026fa0 */
