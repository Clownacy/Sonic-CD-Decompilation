#include "..\EQU.H"
#include "DEV81A.H"
#include "..\IMPFUNCS.H"

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
  360
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
  368
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
  376
};
































































































void cg_change(void) { /* Line 166, Address: 0x102b280 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 170, Address: 0x102b28c */
  pcgchgcnt = cgchgcnt; /* Line 171, Address: 0x102b298 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 173, Address: 0x102b2a4 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 175, Address: 0x102b2d0 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 176, Address: 0x102b2dc */
    } /* Line 177, Address: 0x102b2fc */
  }

  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 180, Address: 0x102b318 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 182, Address: 0x102b344 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 183, Address: 0x102b350 */
    } /* Line 184, Address: 0x102b370 */
  }

  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 187, Address: 0x102b38c */

    for (i = 0; i < 16; ++i, ++top) { /* Line 189, Address: 0x102b3b8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 190, Address: 0x102b3c4 */
    } /* Line 191, Address: 0x102b3e4 */
  }
} /* Line 193, Address: 0x102b400 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 216, Address: 0x102b420 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 220, Address: 0x102b448 */
  if (Timwk >= 0) { /* Line 221, Address: 0x102b474 */

    ++*ppChgTim; /* Line 223, Address: 0x102b484 */
    ++*ppChgCnt; /* Line 224, Address: 0x102b498 */
    return 0; /* Line 225, Address: 0x102b4ac */
  }

  tblidx = **ppChgCnt; /* Line 228, Address: 0x102b4b8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 229, Address: 0x102b4c8 */
    tblidx = 0; /* Line 230, Address: 0x102b4e8 */
  }


  **ppChgCnt = tblidx; /* Line 234, Address: 0x102b4ec */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 235, Address: 0x102b4fc */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 237, Address: 0x102b518 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 238, Address: 0x102b538 */

  for ( ; iNum >= 0; --iNum) { /* Line 240, Address: 0x102b548 */
    *BmpNo++ = *pNoTbl++; /* Line 241, Address: 0x102b550 */
  } /* Line 242, Address: 0x102b56c */


  ++*ppChgTim; /* Line 245, Address: 0x102b584 */
  ++*ppChgCnt; /* Line 246, Address: 0x102b598 */
  *TileStart = pTbl->TileStart; /* Line 247, Address: 0x102b5ac */
  return 1; /* Line 248, Address: 0x102b5bc */
} /* Line 249, Address: 0x102b5c0 */
