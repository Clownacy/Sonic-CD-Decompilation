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
static int bal1cg[16] = { 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163 };
static int bal2cg[16] = { 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179 };
static int bal3cg[16] = { 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195 };
static int bal4cg[16] = { 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211 };
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
  333
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
  341
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
  349
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
  365
};
static tile_changes tbl_bal = {
  16,
  0,
  {
    { 3, 0 },
    { 3, 1 },
    { 12, 2 },
    { 3, 3 },
    { 3, 0 },
    { 3, 1 },
    { 12, 2 },
    { 3, 3 },
    { 3, 0 },
    { 3, 1 },
    { 12, 2 },
    { 3, 3 },
    { 50, 0 },
    { 3, 1 },
    { 12, 2 },
    { 3, 3 }
  },
  {
    bal1cg,
    bal2cg,
    bal3cg,
    bal4cg
  },
  529
};
extern void(*ChangeTileBmp)(int, int);






















































































































void cg_change() { /* Line 251, Address: 0x101d710 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 255, Address: 0x101d71c */
  pcgchgcnt = cgchgcnt; /* Line 256, Address: 0x101d728 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 258, Address: 0x101d734 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 260, Address: 0x101d760 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 261, Address: 0x101d76c */
    } /* Line 262, Address: 0x101d78c */
  }

  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 265, Address: 0x101d7a8 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 267, Address: 0x101d7d4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 268, Address: 0x101d7e0 */
    } /* Line 269, Address: 0x101d800 */
  }

  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 272, Address: 0x101d81c */

    for (i = 0; i < 16; ++i, ++top) { /* Line 274, Address: 0x101d848 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 275, Address: 0x101d854 */
    } /* Line 276, Address: 0x101d874 */
  }

  if (cg_chg1(&tbl_bal, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 279, Address: 0x101d890 */

    for (i = 0; i < 16; ++i, ++top) { /* Line 281, Address: 0x101d8bc */
      ChangeTileBmp(top, playsubdma[i]); /* Line 282, Address: 0x101d8c8 */
    } /* Line 283, Address: 0x101d8e8 */
  }

  if (cg_chg1(&tbl_spo, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 286, Address: 0x101d904 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 288, Address: 0x101d930 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 289, Address: 0x101d93c */
    } /* Line 290, Address: 0x101d95c */
  }
} /* Line 292, Address: 0x101d978 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 315, Address: 0x101d990 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 319, Address: 0x101d9b8 */
  if (Timwk >= 0) { /* Line 320, Address: 0x101d9e4 */

    ++*ppChgTim; /* Line 322, Address: 0x101d9f4 */
    ++*ppChgCnt; /* Line 323, Address: 0x101da08 */
    return 0; /* Line 324, Address: 0x101da1c */
  }

  tblidx = **ppChgCnt; /* Line 327, Address: 0x101da28 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 328, Address: 0x101da38 */
    tblidx = 0; /* Line 329, Address: 0x101da58 */
  }


  **ppChgCnt = tblidx; /* Line 333, Address: 0x101da5c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 334, Address: 0x101da6c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 336, Address: 0x101da88 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 337, Address: 0x101daa8 */

  for ( ; iNum >= 0; --iNum) { /* Line 339, Address: 0x101dab8 */
    *BmpNo++ = *pNoTbl++; /* Line 340, Address: 0x101dac0 */
  } /* Line 341, Address: 0x101dadc */


  ++*ppChgTim; /* Line 344, Address: 0x101daf4 */
  ++*ppChgCnt; /* Line 345, Address: 0x101db08 */
  *TileStart = pTbl->TileStart; /* Line 346, Address: 0x101db1c */
  return 1; /* Line 347, Address: 0x101db2c */
} /* Line 348, Address: 0x101db30 */
