#include "..\EQU.H"
#include "DEV61A.H"
#include "..\IMPFUNCS.H"

static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart);

map_init_data mapinittbl = { 0, 0, 0, 3, 2, 0, 0, 4, 4, 129 };
static int nullcg[8];
static int sp1cg[4] = { 1, 2, 3, 4 };
static int sp2cg[4] = { 5, 6, 7, 8 };
static int t1cg[8] = { 9, 10, 11, 12, 13, 14, 15, 16 };
static int t2cg[8] = { 17, 18, 19, 20, 21, 22, 23, 24 };
static int t3cg[8] = { 25, 26, 27, 28, 29, 30, 31, 32 };
static int r01cg[4] = { 33, 34, 35, 36 };
static int r02cg[4] = { 37, 38, 39, 40 };
static int r03cg[4] = { 41, 42, 43, 44 };
static int r04cg[4] = { 45, 46, 47, 48 };
static tile_changes tbl_thund = {
  3,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 }
  },
  {
    t1cg,
    t2cg,
    t3cg
  },
  380
};
static tile_changes tbl_null = {
  3,
  0,
  {
    { 4, 0 },
    { 4, 1 },
    { 4, 2 }
  },
  {
    nullcg,
    nullcg,
    nullcg
  },
  380
};
static tile_changes tbl_sp = {
  2,
  0,
  {
    { 2, 0 },
    { 2, 1 }
  },
  {
    sp1cg,
    sp2cg
  },
  376
};
static tile_changes tbl_light = {
  4,
  0,
  {
    { 4, 0 },
    { 9, 1 },
    { 4, 2 },
    { 15, 3 }
  },
  {
    r01cg,
    r02cg,
    r03cg,
    r04cg
  },
  372
};
























































































void cg_change(void) { /* Line 166, Address: 0x102dc30 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 170, Address: 0x102dc3c */
  pcgchgcnt = cgchgcnt; /* Line 171, Address: 0x102dc48 */

  if (bossflag & 64) { /* Line 173, Address: 0x102dc54 */


    bossflag |= 128; /* Line 176, Address: 0x102dc6c */
    if (cg_chg1(&tbl_null, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 177, Address: 0x102dc80 */

      for (i = 0; i < 8; ++i, ++top) { /* Line 179, Address: 0x102dcac */
        ChangeTileBmp(top, playsubdma[i]); /* Line 180, Address: 0x102dcb8 */
      } /* Line 181, Address: 0x102dcd8 */
    }
    goto label1; /* Line 183, Address: 0x102dcf4 */
  }

  if (!(bossflag & 128)) { /* Line 186, Address: 0x102dcfc */

    if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 188, Address: 0x102dd14 */

      for (i = 0; i < 8; ++i, ++top) { /* Line 190, Address: 0x102dd40 */
        ChangeTileBmp(top, playsubdma[i]); /* Line 191, Address: 0x102dd4c */
      } /* Line 192, Address: 0x102dd6c */
    }
    goto label1; /* Line 194, Address: 0x102dd88 */
  }

  if (cg_chg1(&tbl_null, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 197, Address: 0x102dd90 */

    for (i = 0; i < 8; ++i, ++top) { /* Line 199, Address: 0x102ddbc */
      ChangeTileBmp(top, playsubdma[i]); /* Line 200, Address: 0x102ddc8 */
    } /* Line 201, Address: 0x102dde8 */
  }

label1:
  bossflag &= 191; /* Line 205, Address: 0x102de04 */

  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 207, Address: 0x102de18 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 209, Address: 0x102de44 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 210, Address: 0x102de50 */
    } /* Line 211, Address: 0x102de70 */
  }

  if (cg_chg1(&tbl_light, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 214, Address: 0x102de8c */

    for (i = 0; i < 4; ++i, ++top) { /* Line 216, Address: 0x102deb8 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 217, Address: 0x102dec4 */
    } /* Line 218, Address: 0x102dee4 */
  }
} /* Line 220, Address: 0x102df00 */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 243, Address: 0x102df20 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 247, Address: 0x102df48 */
  if (Timwk >= 0) { /* Line 248, Address: 0x102df74 */

    ++*ppChgTim; /* Line 250, Address: 0x102df84 */
    ++*ppChgCnt; /* Line 251, Address: 0x102df98 */
    return 0; /* Line 252, Address: 0x102dfac */
  }

  tblidx = **ppChgCnt; /* Line 255, Address: 0x102dfb8 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 256, Address: 0x102dfc8 */
    tblidx = 0; /* Line 257, Address: 0x102dfe8 */
  }


  **ppChgCnt = tblidx; /* Line 261, Address: 0x102dfec */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 262, Address: 0x102dffc */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 264, Address: 0x102e018 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 265, Address: 0x102e038 */

  for ( ; iNum >= 0; --iNum) { /* Line 267, Address: 0x102e048 */
    *BmpNo++ = *pNoTbl++; /* Line 268, Address: 0x102e050 */
  } /* Line 269, Address: 0x102e06c */


  ++*ppChgTim; /* Line 272, Address: 0x102e084 */
  ++*ppChgCnt; /* Line 273, Address: 0x102e098 */
  *TileStart = pTbl->TileStart; /* Line 274, Address: 0x102e0ac */
  return 1; /* Line 275, Address: 0x102e0bc */
} /* Line 276, Address: 0x102e0c0 */
