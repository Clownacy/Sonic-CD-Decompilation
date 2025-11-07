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
  347
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
  347
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
  343
};


















































































void cg_change(void) { /* Line 139, Address: 0x1029640 */
  unsigned char *pcgchgtim, *pcgchgcnt;
  int i, playsubdma[16], top;

  pcgchgtim = cgchgtim; /* Line 143, Address: 0x102964c */
  pcgchgcnt = cgchgcnt; /* Line 144, Address: 0x1029658 */

  if (bossflag & 64) { /* Line 146, Address: 0x1029664 */


    bossflag |= 128; /* Line 149, Address: 0x102967c */
    if (cg_chg1(&tbl_null, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 150, Address: 0x1029690 */

      for (i = 0; i < 8; ++i, ++top) { /* Line 152, Address: 0x10296bc */
        ChangeTileBmp(top, playsubdma[i]); /* Line 153, Address: 0x10296c8 */
      } /* Line 154, Address: 0x10296e8 */
    }
    goto label1; /* Line 156, Address: 0x1029704 */
  }

  if (!(bossflag & 128)) { /* Line 159, Address: 0x102970c */

    if (cg_chg1(&tbl_thund, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 161, Address: 0x1029724 */



      for (i = 0; i < 8; ++i, ++top) { /* Line 165, Address: 0x1029750 */
        ChangeTileBmp(top, playsubdma[i]); /* Line 166, Address: 0x102975c */
      } /* Line 167, Address: 0x102977c */
    }
    goto label1; /* Line 169, Address: 0x1029798 */
  }

  if (cg_chg1(&tbl_null, 7, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 172, Address: 0x10297a0 */


    for (i = 0; i < 8; ++i, ++top) { /* Line 175, Address: 0x10297cc */
      ChangeTileBmp(top, playsubdma[i]); /* Line 176, Address: 0x10297d8 */
    } /* Line 177, Address: 0x10297f8 */
  }

label1:
  bossflag &= 191; /* Line 181, Address: 0x1029814 */

  if (cg_chg1(&tbl_sp, 3, &pcgchgtim, &pcgchgcnt, playsubdma, &top) != 0) { /* Line 183, Address: 0x1029828 */

    for (i = 0; i < 4; ++i, ++top) { /* Line 185, Address: 0x1029854 */
      ChangeTileBmp(top, playsubdma[i]); /* Line 186, Address: 0x1029860 */
    } /* Line 187, Address: 0x1029880 */
  }
} /* Line 189, Address: 0x102989c */






















static unsigned int cg_chg1(tile_changes* pTbl, int iNum, unsigned char** ppChgTim, unsigned char** ppChgCnt, int* BmpNo, int* TileStart) { /* Line 212, Address: 0x10298b0 */
  int tblidx, *pNoTbl;
  char Timwk;

  Timwk = --**ppChgTim; /* Line 216, Address: 0x10298d8 */
  if (Timwk >= 0) { /* Line 217, Address: 0x1029904 */

    ++*ppChgTim; /* Line 219, Address: 0x1029914 */
    ++*ppChgCnt; /* Line 220, Address: 0x1029928 */
    return 0; /* Line 221, Address: 0x102993c */
  }

  tblidx = **ppChgCnt; /* Line 224, Address: 0x1029948 */
  if (++tblidx >= pTbl->chgcnt) { /* Line 225, Address: 0x1029958 */
    tblidx = 0; /* Line 226, Address: 0x1029978 */
  }


  **ppChgCnt = tblidx; /* Line 230, Address: 0x102997c */
  **ppChgTim = pTbl->dattbl[tblidx].tim; /* Line 231, Address: 0x102998c */

  tblidx = (short)pTbl->dattbl[tblidx].no; /* Line 233, Address: 0x10299a8 */
  pNoTbl = pTbl->TileNoTbl[tblidx]; /* Line 234, Address: 0x10299c8 */

  for ( ; iNum >= 0; --iNum) { /* Line 236, Address: 0x10299d8 */
    *BmpNo++ = *pNoTbl++; /* Line 237, Address: 0x10299e0 */
  } /* Line 238, Address: 0x10299fc */


  ++*ppChgTim; /* Line 241, Address: 0x1029a14 */
  ++*ppChgCnt; /* Line 242, Address: 0x1029a28 */
  *TileStart = pTbl->TileStart; /* Line 243, Address: 0x1029a3c */
  return 1; /* Line 244, Address: 0x1029a4c */
} /* Line 245, Address: 0x1029a50 */
