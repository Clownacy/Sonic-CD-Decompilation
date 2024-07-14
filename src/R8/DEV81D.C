#include "..\EQU.H"
#include "DEV81A.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int pis1cg[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
static int pis2cg[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };
static int pis3cg[8] = { 16, 17, 18, 19, 20, 21, 22, 23 };
static int com1cg[8] = { 24, 25, 26, 27, 28, 29, 30, 31 };
static int com2cg[8] = { 32, 33, 34, 35, 36, 37, 38, 39 };
static int com3cg[8] = { 40, 41, 42, 43, 44, 45, 46, 47 };
static int com4cg[8] = { 48, 49, 50, 51, 52, 53, 54, 55 };
static int mot1cg[16] = { 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71 };
static int mot2cg[16] = { 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87 };
static int mot3cg[16] = { 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103 };
static int mot4cg[16] = { 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
static int spo1cg[4] = { 120, 121, 122, 123 };
static int spo2cg[4] = { 124, 125, 126, 127 };
static int spo3cg[4] = { 128, 129, 130, 131 };
static int spo4cg[4] = { 132, 133, 134, 135 };
static int spo5cg[4] = { 136, 137, 138, 139 };
static int spo6cg[4] = { 140, 141, 142, 143 };
static int spo7cg[4] = { 144, 145, 146, 147 };
static tile_changes tbl_pis = {
  4,
  0,
  {
    { 6, 0 },
    { 6, 1 },
    { 6, 2 },
    { 6, 3 }
  },
  {
    pis1cg,
    pis2cg,
    pis3cg,
    pis2cg
  },
  349
};
static tile_changes tbl_com = {
  4,
  0,
  {
    { 3, 0 },
    { 3, 1 },
    { 3, 2 },
    { 3, 3 }
  },
  {
    com1cg,
    com2cg,
    com3cg,
    com4cg
  },
  357
};
static tile_changes tbl_mot = {
  4,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 },
    { 4, 3 }
  },
  {
    mot1cg,
    mot2cg,
    mot3cg,
    mot4cg
  },
  365
};
static tile_changes tbl_spo = {
  7,
  0,
  {
    { 7, 0 },
    { 7, 1 },
    { 7, 2 },
    { 7, 3 },
    { 7, 4 },
    { 7, 5 },
    { 7, 6 }
  },
  {
    spo1cg,
    spo2cg,
    spo3cg,
    spo4cg,
    spo5cg,
    spo6cg,
    spo7cg
  },
  381
};
extern void(*ChangeTileBmp)(int, int);











































































































void cg_change() { /* Line 207, Address: 0x102b420 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 211, Address: 0x102b42c */
  pcgchgcnt = cgchgcnt; /* Line 212, Address: 0x102b438 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 214, Address: 0x102b444 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 216, Address: 0x102b470 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 217, Address: 0x102b47c */
    } /* Line 218, Address: 0x102b49c */
  }

  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 221, Address: 0x102b4b8 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 223, Address: 0x102b4e4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 224, Address: 0x102b4f0 */
    } /* Line 225, Address: 0x102b510 */
  }

  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 228, Address: 0x102b52c */

    for (i = 0; i < 16; ++i, ++top) { /* Line 230, Address: 0x102b558 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 231, Address: 0x102b564 */
    } /* Line 232, Address: 0x102b584 */
  }

  if (cg_chg1(&tbl_spo, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 235, Address: 0x102b5a0 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 237, Address: 0x102b5cc */
      ChangeTileBmp(top, playsubdma[i]); /* Line 238, Address: 0x102b5d8 */
    } /* Line 239, Address: 0x102b5f8 */
  }
} /* Line 241, Address: 0x102b614 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 264, Address: 0x102b630 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 268, Address: 0x102b658 */
  if (Timwk >= 0) { /* Line 269, Address: 0x102b684 */

    ++*ppChgTim; /* Line 271, Address: 0x102b694 */
    ++*ppChgCnt; /* Line 272, Address: 0x102b6a8 */
    return 0; /* Line 273, Address: 0x102b6bc */
  }

  tblidx = **ppChgCnt; /* Line 276, Address: 0x102b6c8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 277, Address: 0x102b6d8 */
    tblidx = 0; /* Line 278, Address: 0x102b6f8 */
  }


  **ppChgCnt = tblidx; /* Line 282, Address: 0x102b6fc */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 283, Address: 0x102b70c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 285, Address: 0x102b728 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 286, Address: 0x102b748 */

  for ( ; iNum >= 0; --iNum) { /* Line 288, Address: 0x102b758 */
    *BmpNo++ = *pNoTbl++; /* Line 289, Address: 0x102b760 */
  } /* Line 290, Address: 0x102b77c */


  ++*ppChgTim; /* Line 293, Address: 0x102b794 */
  ++*ppChgCnt; /* Line 294, Address: 0x102b7a8 */
  *TileStart = pTbl->TileStart; /* Line 295, Address: 0x102b7bc */
  return 1; /* Line 296, Address: 0x102b7cc */
} /* Line 297, Address: 0x102b7d0 */
