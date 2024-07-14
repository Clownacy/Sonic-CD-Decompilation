#include "..\EQU.H"
#include "DEV81A.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 5, 5, 129 };
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
static int pan1cg[4] = { 148, 149, 150, 151 };
static int pan2cg[4] = { 152, 153, 154, 155 };
static int pan3cg[4] = { 156, 157, 158, 159 };
static int pan4cg[4] = { 160, 161, 162, 163 };
static int pan5cg[4] = { 164, 165, 166, 167 };
static int pan6cg[4] = { 168, 169, 170, 171 };
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
  435
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
  443
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
  451
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
  467
};
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
  471
};
extern void(*ChangeTileBmp)(int, int);



















































































































void cg_change() { /* Line 242, Address: 0x1025ba0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 246, Address: 0x1025bac */
  pcgchgcnt = cgchgcnt; /* Line 247, Address: 0x1025bb8 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 249, Address: 0x1025bc4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 251, Address: 0x1025bf0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 252, Address: 0x1025bfc */
    } /* Line 253, Address: 0x1025c1c */
  }

  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 256, Address: 0x1025c38 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 258, Address: 0x1025c64 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 259, Address: 0x1025c70 */
    } /* Line 260, Address: 0x1025c90 */
  }

  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 263, Address: 0x1025cac */

    for (i = 0; i < 16; ++i, ++top) { /* Line 265, Address: 0x1025cd8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 266, Address: 0x1025ce4 */
    } /* Line 267, Address: 0x1025d04 */
  }

  if (cg_chg1(&tbl_spo, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 270, Address: 0x1025d20 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 272, Address: 0x1025d4c */
      ChangeTileBmp(top, playsubdma[i]); /* Line 273, Address: 0x1025d58 */
    } /* Line 274, Address: 0x1025d78 */
  }

  if (cg_chg1(&tbl_pan, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 277, Address: 0x1025d94 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 279, Address: 0x1025dc0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 280, Address: 0x1025dcc */
    } /* Line 281, Address: 0x1025dec */
  }
} /* Line 283, Address: 0x1025e08 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 306, Address: 0x1025e20 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 310, Address: 0x1025e48 */
  if (Timwk >= 0) { /* Line 311, Address: 0x1025e74 */

    ++*ppChgTim; /* Line 313, Address: 0x1025e84 */
    ++*ppChgCnt; /* Line 314, Address: 0x1025e98 */
    return 0; /* Line 315, Address: 0x1025eac */
  }

  tblidx = **ppChgCnt; /* Line 318, Address: 0x1025eb8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 319, Address: 0x1025ec8 */
    tblidx = 0; /* Line 320, Address: 0x1025ee8 */
  }


  **ppChgCnt = tblidx; /* Line 324, Address: 0x1025eec */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 325, Address: 0x1025efc */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 327, Address: 0x1025f18 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 328, Address: 0x1025f38 */

  for ( ; iNum >= 0; --iNum) { /* Line 330, Address: 0x1025f48 */
    *BmpNo++ = *pNoTbl++; /* Line 331, Address: 0x1025f50 */
  } /* Line 332, Address: 0x1025f6c */


  ++*ppChgTim; /* Line 335, Address: 0x1025f84 */
  ++*ppChgCnt; /* Line 336, Address: 0x1025f98 */
  *TileStart = pTbl->TileStart; /* Line 337, Address: 0x1025fac */
  return 1; /* Line 338, Address: 0x1025fbc */
} /* Line 339, Address: 0x1025fc0 */
