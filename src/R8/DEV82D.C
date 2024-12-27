#include "..\EQU.H"
#include "DEV81A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 10, 10, 129 };
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
  438
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
  446
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
  454
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
  470
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
  474
};



















































































































void cg_change() { /* Line 242, Address: 0x102aec0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 246, Address: 0x102aecc */
  pcgchgcnt = cgchgcnt; /* Line 247, Address: 0x102aed8 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 249, Address: 0x102aee4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 251, Address: 0x102af10 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 252, Address: 0x102af1c */
    } /* Line 253, Address: 0x102af3c */
  }
  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 255, Address: 0x102af58 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 257, Address: 0x102af84 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 258, Address: 0x102af90 */
    } /* Line 259, Address: 0x102afb0 */
  }
  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 261, Address: 0x102afcc */

    for (i = 0; i < 16; ++i, ++top) { /* Line 263, Address: 0x102aff8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 264, Address: 0x102b004 */
    } /* Line 265, Address: 0x102b024 */
  }
  if (cg_chg1(&tbl_spo, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 267, Address: 0x102b040 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 269, Address: 0x102b06c */
      ChangeTileBmp(top, playsubdma[i]); /* Line 270, Address: 0x102b078 */
    } /* Line 271, Address: 0x102b098 */
  }
  if (cg_chg1(&tbl_pan, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 273, Address: 0x102b0b4 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 275, Address: 0x102b0e0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 276, Address: 0x102b0ec */
    } /* Line 277, Address: 0x102b10c */
  }
} /* Line 279, Address: 0x102b128 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 302, Address: 0x102b140 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 306, Address: 0x102b168 */
  if (Timwk >= 0) { /* Line 307, Address: 0x102b194 */

    ++*ppChgTim; /* Line 309, Address: 0x102b1a4 */
    ++*ppChgCnt; /* Line 310, Address: 0x102b1b8 */
    return 0; /* Line 311, Address: 0x102b1cc */
  }

  tblidx = **ppChgCnt; /* Line 314, Address: 0x102b1d8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 315, Address: 0x102b1e8 */
    tblidx = 0; /* Line 316, Address: 0x102b208 */
  }


  **ppChgCnt = tblidx; /* Line 320, Address: 0x102b20c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 321, Address: 0x102b21c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 323, Address: 0x102b238 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 324, Address: 0x102b258 */

  for ( ; iNum >= 0; --iNum) { /* Line 326, Address: 0x102b268 */
    *BmpNo++ = *pNoTbl++; /* Line 327, Address: 0x102b270 */
  } /* Line 328, Address: 0x102b28c */


  ++*ppChgTim; /* Line 331, Address: 0x102b2a4 */
  ++*ppChgCnt; /* Line 332, Address: 0x102b2b8 */
  *TileStart = pTbl->TileStart; /* Line 333, Address: 0x102b2cc */
  return 1; /* Line 334, Address: 0x102b2dc */
} /* Line 335, Address: 0x102b2e0 */
