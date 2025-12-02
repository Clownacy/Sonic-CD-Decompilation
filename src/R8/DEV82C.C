#include "..\EQU.H"
#include "DEV81A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 6, 6, 129 };
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
static int pan1cg[4] = { 120, 121, 122, 123 };
static int pan2cg[4] = { 124, 125, 126, 127 };
static int pan3cg[4] = { 128, 129, 130, 131 };
static int pan4cg[4] = { 132, 133, 134, 135 };
static int pan5cg[4] = { 136, 137, 138, 139 };
static int pan6cg[4] = { 140, 141, 142, 143 };
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
  422
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
  430
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
  438
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
  458
};









































































































void cg_change(void) { /* Line 202, Address: 0x102ad20 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 206, Address: 0x102ad2c */
  pcgchgcnt = cgchgcnt; /* Line 207, Address: 0x102ad38 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 209, Address: 0x102ad44 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 211, Address: 0x102ad70 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 212, Address: 0x102ad7c */
    } /* Line 213, Address: 0x102ad9c */
  }
  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 215, Address: 0x102adb8 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 217, Address: 0x102ade4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 218, Address: 0x102adf0 */
    } /* Line 219, Address: 0x102ae10 */
  }
  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 221, Address: 0x102ae2c */

    for (i = 0; i < 16; ++i, ++top) { /* Line 223, Address: 0x102ae58 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 224, Address: 0x102ae64 */
    } /* Line 225, Address: 0x102ae84 */
  }
  if (cg_chg1(&tbl_pan, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 227, Address: 0x102aea0 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 229, Address: 0x102aecc */
      ChangeTileBmp(top, playsubdma[i]); /* Line 230, Address: 0x102aed8 */
    } /* Line 231, Address: 0x102aef8 */
  }

} /* Line 234, Address: 0x102af14 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 257, Address: 0x102af30 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 261, Address: 0x102af58 */
  if (Timwk >= 0) { /* Line 262, Address: 0x102af84 */

    ++*ppChgTim; /* Line 264, Address: 0x102af94 */
    ++*ppChgCnt; /* Line 265, Address: 0x102afa8 */
    return 0; /* Line 266, Address: 0x102afbc */
  }

  tblidx = **ppChgCnt; /* Line 269, Address: 0x102afc8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 270, Address: 0x102afd8 */
    tblidx = 0; /* Line 271, Address: 0x102aff8 */
  }


  **ppChgCnt = tblidx; /* Line 275, Address: 0x102affc */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 276, Address: 0x102b00c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 278, Address: 0x102b028 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 279, Address: 0x102b048 */

  for ( ; iNum >= 0; --iNum) { /* Line 281, Address: 0x102b058 */
    *BmpNo++ = *pNoTbl++; /* Line 282, Address: 0x102b060 */
  } /* Line 283, Address: 0x102b07c */


  ++*ppChgTim; /* Line 286, Address: 0x102b094 */
  ++*ppChgCnt; /* Line 287, Address: 0x102b0a8 */
  *TileStart = pTbl->TileStart; /* Line 288, Address: 0x102b0bc */
  return 1; /* Line 289, Address: 0x102b0cc */
} /* Line 290, Address: 0x102b0d0 */
