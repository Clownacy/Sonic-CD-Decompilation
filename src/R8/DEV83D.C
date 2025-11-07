#include "..\EQU.H"
#include "DEV81A.H"
#include "..\IMPFUNCS.H"

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
  302
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
  310
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
  318
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
  338
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
  334
};




















































































































void cg_change(void) { /* Line 243, Address: 0x102b5e0 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 247, Address: 0x102b5ec */
  pcgchgcnt = cgchgcnt; /* Line 248, Address: 0x102b5f8 */

  if (cg_chg1(&tbl_pis, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 250, Address: 0x102b604 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 252, Address: 0x102b630 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 253, Address: 0x102b63c */
    } /* Line 254, Address: 0x102b65c */
  }
  if (cg_chg1(&tbl_com, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 256, Address: 0x102b678 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 258, Address: 0x102b6a4 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 259, Address: 0x102b6b0 */
    } /* Line 260, Address: 0x102b6d0 */
  }
  if (cg_chg1(&tbl_mot, 15, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 262, Address: 0x102b6ec */

    for (i = 0; i < 16; ++i, ++top) { /* Line 264, Address: 0x102b718 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 265, Address: 0x102b724 */
    } /* Line 266, Address: 0x102b744 */
  }
  if (cg_chg1(&tbl_spo, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 268, Address: 0x102b760 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 270, Address: 0x102b78c */
      ChangeTileBmp(top, playsubdma[i]); /* Line 271, Address: 0x102b798 */
    } /* Line 272, Address: 0x102b7b8 */
  }

  if (shut_flag == 0 || cgchgcnt[0] != 0) { /* Line 275, Address: 0x102b7d4 */


    if (cg_chg1(&tbl_pan, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) == 0) return; /* Line 278, Address: 0x102b7fc */

    for (i = 0; i < 4; ++i, ++top) { /* Line 280, Address: 0x102b828 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 281, Address: 0x102b834 */
    } /* Line 282, Address: 0x102b854 */
  }
} /* Line 284, Address: 0x102b870 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 307, Address: 0x102b890 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 311, Address: 0x102b8b8 */
  if (Timwk >= 0) { /* Line 312, Address: 0x102b8e4 */

    ++*ppChgTim; /* Line 314, Address: 0x102b8f4 */
    ++*ppChgCnt; /* Line 315, Address: 0x102b908 */
    return 0; /* Line 316, Address: 0x102b91c */
  }

  tblidx = **ppChgCnt; /* Line 319, Address: 0x102b928 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 320, Address: 0x102b938 */
    tblidx = 0; /* Line 321, Address: 0x102b958 */
  }


  **ppChgCnt = tblidx; /* Line 325, Address: 0x102b95c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 326, Address: 0x102b96c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 328, Address: 0x102b988 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 329, Address: 0x102b9a8 */

  for ( ; iNum >= 0; --iNum) { /* Line 331, Address: 0x102b9b8 */
    *BmpNo++ = *pNoTbl++; /* Line 332, Address: 0x102b9c0 */
  } /* Line 333, Address: 0x102b9dc */


  ++*ppChgTim; /* Line 336, Address: 0x102b9f4 */
  ++*ppChgCnt; /* Line 337, Address: 0x102ba08 */
  *TileStart = pTbl->TileStart; /* Line 338, Address: 0x102ba1c */
  return 1; /* Line 339, Address: 0x102ba2c */
} /* Line 340, Address: 0x102ba30 */
