#include "EQU.H"
#include "FCOL.H"

extern unsigned char scdtblwk[257][16];
extern unsigned char scddirtbl[256];
extern unsigned char scdtblwk2[257][16];
extern unsigned char mapwka[8][64];










































short fcol(act_info* pActwk) { /* Line 50, Address: 0x1001350 */
  short iColliVal;
  unsigned char byDirec;
  char cDirecWork;

  if (pActwk->cddat & 8) { /* Line 55, Address: 0x1001368 */

    dirstk[0] = 0; /* Line 57, Address: 0x1001380 */
    dirstk[2] = 0; /* Line 58, Address: 0x1001388 */
    return 0; /* Line 59, Address: 0x1001390 */
  }

  dirstk[0] = 3; /* Line 62, Address: 0x100139c */
  dirstk[2] = 3; /* Line 63, Address: 0x10013a8 */

  cDirecWork = pActwk->direc.b.h; /* Line 65, Address: 0x10013b4 */
  if ((char)(cDirecWork + 32) < 0) { /* Line 66, Address: 0x10013c4 */

    if (cDirecWork < 0) { /* Line 68, Address: 0x10013e8 */
      --cDirecWork; /* Line 69, Address: 0x10013f8 */
    }
    cDirecWork += 32; /* Line 71, Address: 0x1001404 */
  } /* Line 72, Address: 0x1001410 */
  else {


    if (cDirecWork < 0) { /* Line 76, Address: 0x1001418 */
      ++cDirecWork; /* Line 77, Address: 0x1001428 */
    }
    cDirecWork += 31; /* Line 79, Address: 0x1001434 */
  }

  byDirec = cDirecWork & 192; /* Line 82, Address: 0x1001440 */

  switch (byDirec) { /* Line 84, Address: 0x1001454 */

    case 64:
      iColliVal = fcol_l(pActwk); /* Line 87, Address: 0x1001484 */
      break; /* Line 88, Address: 0x1001498 */
    case 128:
      iColliVal = fcol_u(pActwk); /* Line 90, Address: 0x10014a0 */
      break; /* Line 91, Address: 0x10014b4 */
    case 192:
      iColliVal = fcol_r(pActwk); /* Line 93, Address: 0x10014bc */
      break; /* Line 94, Address: 0x10014d0 */
    default:
      iColliVal = fcol_d(pActwk); /* Line 96, Address: 0x10014d8 */
      break;
  }
  if (iColliVal == 1) iColliVal = 1; /* Line 99, Address: 0x10014ec */
  else iColliVal = 0; /* Line 100, Address: 0x1001514 */
  return iColliVal; /* Line 101, Address: 0x1001518 */
} /* Line 102, Address: 0x100151c */













short fcol_d(act_info* pActwk) { /* Line 116, Address: 0x1001540 */
  short iXposi, iYposi;
  short iScd, iScd0, iScd1;
  char* cpDirStk;

  iXposi = pActwk->xposi.w.h + pActwk->sprhs; /* Line 121, Address: 0x1001564 */
  iYposi = pActwk->yposi.w.h + pActwk->sprvsize; /* Line 122, Address: 0x100159c */
  cpDirStk = &dirstk[0]; /* Line 123, Address: 0x10015d4 */
  iScd0 = scdchk(pActwk, iXposi, iYposi, 16, 0, 13, cpDirStk); /* Line 124, Address: 0x10015dc */


  iXposi = pActwk->xposi.w.h - pActwk->sprhs; /* Line 127, Address: 0x1001608 */
  iYposi = pActwk->yposi.w.h + pActwk->sprvsize; /* Line 128, Address: 0x1001640 */
  cpDirStk = &dirstk[2]; /* Line 129, Address: 0x1001678 */
  iScd1 = scdchk(pActwk, iXposi, iYposi, 16, 0, 13, cpDirStk); /* Line 130, Address: 0x1001680 */



  if (dirstk[2] != -1) { /* Line 134, Address: 0x10016ac */

    if (iScd0 == 0 && iScd1 == 0) { /* Line 136, Address: 0x10016c8 */
      if (dirstk[2] >= -64 && dirstk[2] < -16) { /* Line 137, Address: 0x10016e8 */







        dirstk[2] = -1; /* Line 145, Address: 0x1001720 */
      }
    }
  }


  iScd = dirchk(pActwk, iScd0, iScd1); /* Line 151, Address: 0x100172c */

  if (iScd == 0) /* Line 153, Address: 0x1001748 */
    return 0; /* Line 154, Address: 0x1001758 */

  if (iScd < 0) { /* Line 156, Address: 0x1001764 */


    if (iScd >= -14) /* Line 159, Address: 0x1001774 */
      pActwk->yposi.w.h += iScd; /* Line 160, Address: 0x1001788 */
    return 1; /* Line 161, Address: 0x1001798 */
  }



  if (iScd < 15) { /* Line 166, Address: 0x10017a4 */


    pActwk->yposi.w.h += iScd; /* Line 169, Address: 0x10017b8 */
    return 1; /* Line 170, Address: 0x10017c8 */
  }

  if (pActwk->actfree[14] == 0) { /* Line 173, Address: 0x10017d4 */

    pActwk->cddat |= 2; /* Line 175, Address: 0x10017e8 */
    pActwk->cddat &= 223; /* Line 176, Address: 0x10017f8 */
    pActwk->mstno.b.l = 1; /* Line 177, Address: 0x1001808 */
  } /* Line 178, Address: 0x1001814 */
  else {


    pActwk->yposi.w.h += iScd; /* Line 182, Address: 0x100181c */
  }
  return 1; /* Line 184, Address: 0x100182c */

} /* Line 186, Address: 0x1001830 */












short fcol_r(act_info* pActwk) { /* Line 199, Address: 0x1001860 */
  short iXposi, iYposi;
  short scd0, scd1;
  char* cpDirStk;

  iXposi = pActwk->xposi.w.h + pActwk->sprvsize; /* Line 204, Address: 0x1001880 */
  iYposi = pActwk->yposi.w.h - pActwk->sprhs; /* Line 205, Address: 0x10018b8 */
  cpDirStk = &dirstk[0]; /* Line 206, Address: 0x10018f0 */
  scd0 = scdchk_r(pActwk, iXposi, iYposi, 16, 0, 13, cpDirStk); /* Line 207, Address: 0x10018f8 */


  iXposi = pActwk->xposi.w.h + pActwk->sprvsize; /* Line 210, Address: 0x1001924 */
  iYposi = pActwk->yposi.w.h + pActwk->sprhs; /* Line 211, Address: 0x100195c */
  cpDirStk = &dirstk[2]; /* Line 212, Address: 0x1001994 */
  scd1 = scdchk_r(pActwk, iXposi, iYposi, 16, 0, 13, cpDirStk); /* Line 213, Address: 0x100199c */

  if ((scd0 = dirchk(pActwk, scd0, scd1)) == 0) /* Line 215, Address: 0x10019c8 */
    return 0; /* Line 216, Address: 0x10019fc */
  if (scd0 < 0) { /* Line 217, Address: 0x1001a08 */


    if (scd0 >= -13) /* Line 220, Address: 0x1001a18 */
      pActwk->xposi.w.h += scd0; /* Line 221, Address: 0x1001a2c */
    return 1; /* Line 222, Address: 0x1001a3c */
  }



  if (scd0 >= 15) { /* Line 227, Address: 0x1001a48 */


    if (pActwk->actfree[14] == 0) { /* Line 230, Address: 0x1001a5c */

      pActwk->cddat |= 2; /* Line 232, Address: 0x1001a70 */
      pActwk->cddat &= 223; /* Line 233, Address: 0x1001a80 */
      pActwk->mstno.b.l = 1; /* Line 234, Address: 0x1001a90 */
    } /* Line 235, Address: 0x1001a9c */
    else
      pActwk->xposi.w.h += scd0; /* Line 237, Address: 0x1001aa4 */
    return 1; /* Line 238, Address: 0x1001ab4 */
  }

  pActwk->xposi.w.h += scd0; /* Line 241, Address: 0x1001ac0 */
  return 1; /* Line 242, Address: 0x1001ad0 */

} /* Line 244, Address: 0x1001ad4 */












short fcol_u(act_info* pActwk) { /* Line 257, Address: 0x1001b00 */
  short iXposi, iYposi;
  short scd0, scd1;
  char* cpDirStk;

  iYposi = (pActwk->yposi.w.h - pActwk->sprvsize) ^ 15; /* Line 262, Address: 0x1001b20 */
  iXposi = pActwk->xposi.w.h + pActwk->sprhs; /* Line 263, Address: 0x1001b5c */
  cpDirStk = &dirstk[0]; /* Line 264, Address: 0x1001b94 */
  scd0 = scdchk(pActwk, iXposi, iYposi, -16, 4096, 13, cpDirStk); /* Line 265, Address: 0x1001b9c */


  iYposi = (pActwk->yposi.w.h - pActwk->sprvsize) ^ 15; /* Line 268, Address: 0x1001bc8 */
  iXposi = pActwk->xposi.w.h - pActwk->sprhs; /* Line 269, Address: 0x1001c04 */
  cpDirStk = &dirstk[2]; /* Line 270, Address: 0x1001c3c */
  scd1 = scdchk(pActwk, iXposi, iYposi, -16, 4096, 13, cpDirStk); /* Line 271, Address: 0x1001c44 */

  if ((scd0 = dirchk(pActwk, scd0, scd1)) == 0) /* Line 273, Address: 0x1001c70 */
    return 0; /* Line 274, Address: 0x1001ca4 */

  if (scd0 < 0) { /* Line 276, Address: 0x1001cb0 */


    if (scd0 >= -13) /* Line 279, Address: 0x1001cc0 */
      pActwk->yposi.w.h -= scd0; /* Line 280, Address: 0x1001cd4 */
    return 1; /* Line 281, Address: 0x1001ce4 */
  }

  if (scd0 >= 15) { /* Line 284, Address: 0x1001cf0 */


    if (pActwk->actfree[14] == 0) { /* Line 287, Address: 0x1001d04 */

      pActwk->cddat |= 2; /* Line 289, Address: 0x1001d18 */
      pActwk->cddat &= 223; /* Line 290, Address: 0x1001d28 */
      pActwk->mstno.b.l = 1; /* Line 291, Address: 0x1001d38 */
    } /* Line 292, Address: 0x1001d44 */
    else
      pActwk->yposi.w.h -= scd0; /* Line 294, Address: 0x1001d4c */
    return 1; /* Line 295, Address: 0x1001d5c */
  }

  pActwk->yposi.w.h -= scd0; /* Line 298, Address: 0x1001d68 */
  return 1; /* Line 299, Address: 0x1001d78 */
} /* Line 300, Address: 0x1001d7c */












short fcol_l(act_info* pActwk) { /* Line 313, Address: 0x1001da0 */
  short iXposi, iYposi;
  short scd0, scd1;
  char* cpDirStk;

  iYposi = pActwk->yposi.w.h - pActwk->sprhs; /* Line 318, Address: 0x1001dc0 */
  iXposi = (pActwk->xposi.w.h - pActwk->sprvsize) ^ 15; /* Line 319, Address: 0x1001df8 */
  cpDirStk = &dirstk[0]; /* Line 320, Address: 0x1001e34 */
  scd0 = scdchk_r(pActwk, iXposi, iYposi, -16, 2048, 13, cpDirStk); /* Line 321, Address: 0x1001e3c */


  iYposi = pActwk->yposi.w.h + pActwk->sprhs; /* Line 324, Address: 0x1001e68 */
  iXposi = (pActwk->xposi.w.h - pActwk->sprvsize) ^ 15; /* Line 325, Address: 0x1001ea0 */
  cpDirStk = &dirstk[2]; /* Line 326, Address: 0x1001edc */
  scd1 = scdchk_r(pActwk, iXposi, iYposi, -16, 2048, 13, cpDirStk); /* Line 327, Address: 0x1001ee4 */

  if ((scd0 = dirchk(pActwk, scd0, scd1)) == 0) /* Line 329, Address: 0x1001f10 */
    return 0; /* Line 330, Address: 0x1001f44 */
  if (scd0 < 0) { /* Line 331, Address: 0x1001f50 */


    if (scd0 >= -13) /* Line 334, Address: 0x1001f60 */
      pActwk->xposi.w.h -= scd0; /* Line 335, Address: 0x1001f74 */
    return 1; /* Line 336, Address: 0x1001f84 */
  }

  if (scd0 >= 15) { /* Line 339, Address: 0x1001f90 */


    if (pActwk->actfree[14] == 0) { /* Line 342, Address: 0x1001fa4 */

      pActwk->cddat |= 2; /* Line 344, Address: 0x1001fb8 */
      pActwk->cddat &= 223; /* Line 345, Address: 0x1001fc8 */
      pActwk->mstno.b.l = 1; /* Line 346, Address: 0x1001fd8 */
    } /* Line 347, Address: 0x1001fe4 */
    else
      pActwk->xposi.w.h -= scd0; /* Line 349, Address: 0x1001fec */
    return 1; /* Line 350, Address: 0x1001ffc */
  }
  pActwk->xposi.w.h -= scd0; /* Line 352, Address: 0x1002008 */
  return 1; /* Line 353, Address: 0x1002018 */
} /* Line 354, Address: 0x100201c */










short scdend(act_info* pActwk, short iXposi, short iYposi, short iOffset, short iBlkMsk, short iRideon, char* cpDirStk) { /* Line 365, Address: 0x1002040 */
  short iScd;

  iYposi += iOffset; /* Line 368, Address: 0x1002068 */
  iScd = scdchk2(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 369, Address: 0x1002078 */
  iYposi -= iOffset; /* Line 370, Address: 0x10020a4 */
  return iScd + 16; /* Line 371, Address: 0x10020b4 */
} /* Line 372, Address: 0x10020c8 */






















short scdchk(act_info* pActwk, short iXposi, short iYposi, short iOffset, short iBlkMsk, short iRideon, char* cpDirStk) { /* Line 395, Address: 0x10020e0 */
  short iBlkNo;
  short iBlkOffset;
  short iXwork;
  short iScdData;
  unsigned short iScdNo;
  char cDirect;
  unsigned char bySCDwk;
  char cScdwk;



  iBlkNo = scramapad(pActwk, iXposi, iYposi); /* Line 407, Address: 0x1002124 */

  iBlkOffset = iBlkNo & 1023; /* Line 409, Address: 0x1002140 */
  if (iBlkOffset == 0 || ((1 << iRideon) & iBlkNo) == 0) { /* Line 410, Address: 0x100215c */

    return scdend(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 412, Address: 0x1002194 */
  }


  bySCDwk = scdadr[iBlkOffset]; /* Line 416, Address: 0x10021c0 */
  iScdNo = bySCDwk; /* Line 417, Address: 0x10021dc */
  if (iScdNo == 0) { /* Line 418, Address: 0x10021ec */

    return scdend(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 420, Address: 0x10021f8 */
  }


  bySCDwk = scddirtbl[iScdNo]; /* Line 424, Address: 0x1002224 */
  cDirect = bySCDwk; /* Line 425, Address: 0x100223c */

  iXwork = iXposi; /* Line 427, Address: 0x1002244 */

  if (iBlkNo & 2048) { /* Line 429, Address: 0x1002250 */


    iXwork = ~iXwork; /* Line 432, Address: 0x1002264 */
    cDirect = -cDirect; /* Line 433, Address: 0x1002280 */
  }
  if (iBlkNo & 4096) { /* Line 435, Address: 0x100229c */


    cDirect = -(cDirect + 64) + -64; /* Line 438, Address: 0x10022b0 */
  }
  *cpDirStk = cDirect; /* Line 440, Address: 0x10022d4 */
  iXwork &= 15; /* Line 441, Address: 0x10022dc */


  cScdwk = scdtblwk[iScdNo][iXwork]; /* Line 444, Address: 0x10022e8 */
  iScdData = cScdwk; /* Line 445, Address: 0x1002314 */

  iBlkNo ^= iBlkMsk; /* Line 447, Address: 0x1002324 */
  if (iBlkNo & 4096) { /* Line 448, Address: 0x1002334 */
    iScdData = -iScdData; /* Line 449, Address: 0x1002348 */
  }

  if (iScdData == 0) /* Line 452, Address: 0x1002364 */
    return scdend(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 453, Address: 0x1002374 */
  if (iScdData >= 0) { /* Line 454, Address: 0x10023a0 */
    if (iScdData != 16) { /* Line 455, Address: 0x10023b0 */
label1:
      return 15 - (iScdData + (iYposi & 15)); /* Line 457, Address: 0x10023c4 */
    }
  } else if (iOffset == 16) { /* Line 459, Address: 0x10023f8 */

      iScdData = 16; /* Line 461, Address: 0x1002410 */
      *cpDirStk = 0; /* Line 462, Address: 0x100241c */
      goto label1; /* Line 463, Address: 0x1002424 */
  }
  else {
    iScdData += iYposi & 15; /* Line 466, Address: 0x100242c */
    if (iScdData >= 0) /* Line 467, Address: 0x1002450 */
      return scdend(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 468, Address: 0x1002460 */
  }
  iYposi -= iOffset; /* Line 470, Address: 0x100248c */
  iScdData = scdchk2(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirStk); /* Line 471, Address: 0x100249c */
  iYposi += iOffset; /* Line 472, Address: 0x10024c8 */
  return iScdData + -16; /* Line 473, Address: 0x10024d8 */
} /* Line 474, Address: 0x10024ec */























short scdchk2(act_info* pActwk, short iXposi, short iYposi, short iOffset, short iBlkMsk, short iRideon, char* cpDirStk) { /* Line 498, Address: 0x1002520 */
  short iBlkNo;
  short iBlkOffset;
  short iScd;
  short iXwork;
  short iScdData;
  char cDirect;
  unsigned short iScdNo;
  unsigned char bySCDwk;
  char cScdwk;

  iBlkNo = scramapad(pActwk, iXposi, iYposi); /* Line 509, Address: 0x1002568 */
  iBlkOffset = iBlkNo & 1023; /* Line 510, Address: 0x1002584 */
  if (iBlkOffset == 0 || ((1 << iRideon) & iBlkNo) == 0) { /* Line 511, Address: 0x10025a0 */


    return 15 - (iYposi & 15); /* Line 514, Address: 0x10025d8 */
  }

  bySCDwk = scdadr[iBlkOffset]; /* Line 517, Address: 0x1002600 */
  iScdNo = bySCDwk; /* Line 518, Address: 0x100261c */
  if (iScdNo == 0) { /* Line 519, Address: 0x100262c */


    return 15 - (iYposi & 15); /* Line 522, Address: 0x1002638 */
  }

  cDirect = scddirtbl[iScdNo]; /* Line 525, Address: 0x1002660 */
  iXwork = iXposi; /* Line 526, Address: 0x100267c */
  if (iBlkNo & 2048) { /* Line 527, Address: 0x1002688 */


    iXwork = ~iXwork; /* Line 530, Address: 0x100269c */
    cDirect = -cDirect; /* Line 531, Address: 0x10026b8 */
  }
  if (iBlkNo & 4096) { /* Line 533, Address: 0x10026d4 */



    cDirect = -(cDirect + 64) + -64; /* Line 537, Address: 0x10026e8 */
  }
  *cpDirStk = cDirect; /* Line 539, Address: 0x100270c */

  iXwork &= 15; /* Line 541, Address: 0x1002714 */


  cScdwk = scdtblwk[iScdNo][iXwork]; /* Line 544, Address: 0x1002720 */
  iScdData = cScdwk; /* Line 545, Address: 0x100274c */

  iBlkNo ^= iBlkMsk; /* Line 547, Address: 0x100275c */
  if (iBlkNo & 4096) iScdData = -iScdData; /* Line 548, Address: 0x100276c */

  if (iScdData == 0) /* Line 550, Address: 0x100278c */

    return 15 - (iYposi & 15); /* Line 552, Address: 0x100279c */
  if (iScdData >= 0) { /* Line 553, Address: 0x10027c4 */
label1:
    iYposi &= 15; /* Line 555, Address: 0x10027d4 */
    iScdData += iYposi; /* Line 556, Address: 0x10027e0 */
    return 15 - iScdData; /* Line 557, Address: 0x10027f0 */
  }

  if (iOffset == 16) { /* Line 560, Address: 0x1002810 */

    iScdData = 16; /* Line 562, Address: 0x1002828 */
    *cpDirStk = 0; /* Line 563, Address: 0x1002834 */
    goto label1; /* Line 564, Address: 0x100283c */
  }

  iScd = iYposi & 15; /* Line 567, Address: 0x1002844 */
  if (iScd + iScdData > 0) { /* Line 568, Address: 0x1002864 */
    return 15 - iScd; /* Line 569, Address: 0x1002880 */
  }
  return ~iScd; /* Line 571, Address: 0x10028a0 */
} /* Line 572, Address: 0x10028b4 */










short scdend_r(act_info* pActwk, short iXposi, short iYposi, short iOffset, short iBlkMsk, short iRideon, char* cpDirstk) { /* Line 583, Address: 0x10028f0 */
  short iScd;

  iXposi += iOffset; /* Line 586, Address: 0x1002918 */
  iScd = scdchk2_r(pActwk, iXposi, iYposi, iBlkMsk, iRideon, cpDirstk); /* Line 587, Address: 0x1002928 */
  iXposi -= iOffset; /* Line 588, Address: 0x1002950 */
  return iScd + 16; /* Line 589, Address: 0x1002960 */
} /* Line 590, Address: 0x1002974 */























short scdchk_r(act_info* pActwk, short iXposi, short iYposi, short iOffset, short iBlkMsk, short iRideon, char* cpDirstk) { /* Line 614, Address: 0x1002990 */
  short iBlkNo;
  short iBlkOffset;
  short iXwork;
  short iYwork;
  short iScdData;
  char cDirect;
  unsigned short iScdNo;
  unsigned char bySCDwk;
  char cScdwk;

  iBlkNo = scramapad(pActwk, iXposi, iYposi); /* Line 625, Address: 0x10029d8 */
  iBlkOffset = iBlkNo & 1023; /* Line 626, Address: 0x10029f4 */
  if (iBlkOffset == 0 || (iBlkNo & (1 << iRideon)) == 0) { /* Line 627, Address: 0x1002a10 */

    return scdend_r(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirstk); /* Line 629, Address: 0x1002a48 */
  }


  bySCDwk = scdadr[iBlkOffset]; /* Line 633, Address: 0x1002a74 */
  iScdNo = bySCDwk; /* Line 634, Address: 0x1002a90 */
  if (iScdNo == 0) { /* Line 635, Address: 0x1002aa0 */

    return scdend_r(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirstk); /* Line 637, Address: 0x1002aac */
  }

  cDirect = scddirtbl[iScdNo]; /* Line 640, Address: 0x1002ad8 */
  iYwork = iYposi; /* Line 641, Address: 0x1002af4 */

  if (iBlkNo & 4096) { /* Line 643, Address: 0x1002b00 */


    iYwork = ~iYwork; /* Line 646, Address: 0x1002b14 */
    cDirect = -(cDirect + 64) + -64; /* Line 647, Address: 0x1002b30 */
  }
  if (iBlkNo & 2048) { /* Line 649, Address: 0x1002b54 */


    cDirect = -cDirect; /* Line 652, Address: 0x1002b68 */
  }
  *cpDirstk = cDirect; /* Line 654, Address: 0x1002b84 */


  iYwork &= 15; /* Line 657, Address: 0x1002b8c */

  cScdwk = scdtblwk2[iScdNo][iYwork]; /* Line 659, Address: 0x1002b98 */
  iScdData = cScdwk; /* Line 660, Address: 0x1002bc4 */

  iBlkNo ^= iBlkMsk; /* Line 662, Address: 0x1002bd4 */
  if (iBlkNo & 2048) iScdData = -iScdData; /* Line 663, Address: 0x1002be4 */

  if (iScdData == 0) /* Line 665, Address: 0x1002c04 */
    return scdend_r(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirstk); /* Line 666, Address: 0x1002c14 */
  if (iScdData >= 0) { /* Line 667, Address: 0x1002c40 */
    if (iScdData == 16) goto label1; /* Line 668, Address: 0x1002c50 */

    iXposi &= 15; /* Line 670, Address: 0x1002c64 */
    return 15 - (iScdData + iXposi); /* Line 671, Address: 0x1002c70 */
  }
  iXwork = iXposi & 15; /* Line 673, Address: 0x1002ca0 */
  iScdData += iXwork; /* Line 674, Address: 0x1002cc0 */
  if (iScdData >= 0) /* Line 675, Address: 0x1002ccc */
    return scdend_r(pActwk, iXposi, iYposi, iOffset, iBlkMsk, iRideon, cpDirstk); /* Line 676, Address: 0x1002cdc */
label1:
  iXposi -= iOffset; /* Line 678, Address: 0x1002d08 */
  iScdData = scdchk2_r(pActwk, iXposi, iYposi, iBlkMsk, iRideon, cpDirstk); /* Line 679, Address: 0x1002d18 */
  iXposi += iOffset; /* Line 680, Address: 0x1002d40 */
  return iScdData + -16; /* Line 681, Address: 0x1002d50 */
} /* Line 682, Address: 0x1002d64 */




















short scdchk2_r(act_info* pActwk, short iXposi, short iYposi, short iBlkMsk, short iRideon, char* cpDirstk) { /* Line 703, Address: 0x1002da0 */
  short iBlkNo;
  short iBlkOffset;
  short iXwork;
  short iYwork;
  short iScdData;
  char cDirect;
  unsigned short iScdNo;
  unsigned char bySCDwk;
  char cScdwk;


  iBlkNo = scramapad(pActwk, iXposi, iYposi); /* Line 715, Address: 0x1002de4 */
  iBlkOffset = iBlkNo & 1023; /* Line 716, Address: 0x1002e00 */
  if (iBlkOffset == 0 || ((1 << iRideon) & iBlkNo) == 0) { /* Line 717, Address: 0x1002e1c */


    return 15 - (iXposi & 15); /* Line 720, Address: 0x1002e54 */
  }

  bySCDwk = scdadr[iBlkOffset]; /* Line 723, Address: 0x1002e7c */
  iScdNo = bySCDwk; /* Line 724, Address: 0x1002e98 */
  if (iScdNo == 0) { /* Line 725, Address: 0x1002ea8 */


    return 15 - (iXposi & 15); /* Line 728, Address: 0x1002eb4 */
  }

  cDirect = scddirtbl[iScdNo]; /* Line 731, Address: 0x1002edc */
  iYwork = iYposi; /* Line 732, Address: 0x1002ef8 */
  if (iBlkNo & 4096) { /* Line 733, Address: 0x1002f04 */


    iYwork = ~iYwork; /* Line 736, Address: 0x1002f18 */
    cDirect = -(cDirect + 64) + -64; /* Line 737, Address: 0x1002f34 */
  }
  if (iBlkNo & 2048) { /* Line 739, Address: 0x1002f58 */


    cDirect = -cDirect; /* Line 742, Address: 0x1002f6c */
  }
  *cpDirstk = cDirect; /* Line 744, Address: 0x1002f88 */


  iYwork &= 15; /* Line 747, Address: 0x1002f90 */

  cScdwk = scdtblwk2[iScdNo][iYwork]; /* Line 749, Address: 0x1002f9c */
  iScdData = cScdwk; /* Line 750, Address: 0x1002fc8 */

  iBlkNo ^= iBlkMsk; /* Line 752, Address: 0x1002fd8 */
  if (iBlkNo & 2048) iScdData = -iScdData; /* Line 753, Address: 0x1002fe8 */

  if (iScdData == 0) { /* Line 755, Address: 0x1003008 */

    return 15 - (iXposi & 15); /* Line 757, Address: 0x1003018 */
  }
  if (iScdData >= 0) { /* Line 759, Address: 0x1003040 */


    iXwork = iXposi & 15; /* Line 762, Address: 0x1003050 */
    iXwork += iScdData; /* Line 763, Address: 0x1003070 */
    iXwork = 15 - iXwork; /* Line 764, Address: 0x100307c */
    return iXwork; /* Line 765, Address: 0x100309c */
  }

  iXwork = iXposi & 15; /* Line 768, Address: 0x10030a8 */
  if ((iXwork + iScdData) >= 0) { /* Line 769, Address: 0x10030c8 */


    return 15 - (iXposi & 15); /* Line 772, Address: 0x10030e4 */
  }
  return ~iXwork; /* Line 774, Address: 0x100310c */
} /* Line 775, Address: 0x1003120 */














short scramapad(act_info* pActwk, short iXposi, short iYposi) { /* Line 790, Address: 0x1003160 */
  char cBlkNo;
  short iBlkNo;
  short iMapNo;
  short iXwork, iYwork;
  unsigned short* lpw;

  if (stageno.w == 0 || stageno.b.h == 6) { /* Line 797, Address: 0x100318c */

    if (iYposi < 0) /* Line 799, Address: 0x10031c0 */
      iYposi = 0; /* Line 800, Address: 0x10031d4 */
    if (iXposi < 0) /* Line 801, Address: 0x10031d8 */
      iXposi = 0; /* Line 802, Address: 0x10031ec */
  }



  iYwork = (iYposi >> 8) & 7; /* Line 807, Address: 0x10031f0 */
  if (stageno.b.h == 2) { /* Line 808, Address: 0x1003214 */
    iYwork &= 63; /* Line 809, Address: 0x1003230 */
  }

  iXwork = iXposi & 63; /* Line 812, Address: 0x100323c */

  iYwork = iYposi >> 1; /* Line 814, Address: 0x100325c */
  iYwork &= 1920; /* Line 815, Address: 0x100327c */
  iYwork = iYwork >> 7; /* Line 816, Address: 0x1003288 */
  iYwork &= 7; /* Line 817, Address: 0x1003294 */

  iXwork = iXposi >> 8; /* Line 819, Address: 0x10032a0 */
  iXwork &= 127; /* Line 820, Address: 0x10032c0 */
  iXwork &= 63; /* Line 821, Address: 0x10032cc */

  if (stageno.w != 0) { /* Line 823, Address: 0x10032d8 */

    if (iYwork < 0) iYwork = 0; /* Line 825, Address: 0x10032f0 */
    if (iXwork < 0) iXwork = 0; /* Line 826, Address: 0x1003304 */
  }

  cBlkNo = mapwka[iYwork][iXwork]; /* Line 829, Address: 0x1003318 */
  if (cBlkNo == 0) /* Line 830, Address: 0x1003348 */
    return 0; /* Line 831, Address: 0x1003358 */
  if (cBlkNo > 0) { /* Line 832, Address: 0x1003364 */

    if (stageno.b.h == 5 || stageno.b.h == 6) { /* Line 834, Address: 0x1003374 */

      pActwk->sproffset &= 32767; /* Line 836, Address: 0x10033ac */
    }
    if (stageno.b.h == 4) { /* Line 838, Address: 0x10033bc */
      pActwk->actflg &= 191; /* Line 839, Address: 0x10033d8 */
    }

    iBlkNo = cBlkNo & 127; /* Line 842, Address: 0x10033e8 */

    iYwork = (iYposi & 240) >> 4; /* Line 844, Address: 0x1003404 */
    iXwork = (iXposi & 240) >> 4; /* Line 845, Address: 0x1003438 */

    iMapNo = 0; /* Line 847, Address: 0x100346c */


    lpw = pmapwk; /* Line 850, Address: 0x1003470 */
    lpw += iXwork; /* Line 851, Address: 0x1003478 */
    lpw += iYwork << 4; /* Line 852, Address: 0x1003488 */
    lpw += (iBlkNo + -1 << 4) << 4; /* Line 853, Address: 0x100349c */
    iMapNo = *lpw; /* Line 854, Address: 0x10034b8 */
    return iMapNo; /* Line 855, Address: 0x10034c4 */
  }

  iBlkNo = cBlkNo & 127; /* Line 858, Address: 0x10034d0 */
  switch (stageno.b.h) { /* Line 859, Address: 0x10034ec */

    case 4:
      iBlkNo = st_wackyDataChk(iBlkNo, pActwk); /* Line 862, Address: 0x1003528 */
      break; /* Line 863, Address: 0x1003540 */
    case 5:
      iBlkNo = st_starDataChk(iBlkNo, pActwk); /* Line 865, Address: 0x1003548 */
      break; /* Line 866, Address: 0x1003560 */
    case 6:
      iBlkNo = st_metalDataChk(iBlkNo, pActwk); /* Line 868, Address: 0x1003568 */
      break; /* Line 869, Address: 0x1003580 */
    default:
      iBlkNo = st_elseDataChk(iBlkNo, pActwk); /* Line 871, Address: 0x1003588 */
  }
  iBlkNo &= 127; /* Line 873, Address: 0x10035a0 */
  iYwork = (iYposi & 240) >> 4; /* Line 874, Address: 0x10035bc */
  iXwork = (iXposi & 240) >> 4; /* Line 875, Address: 0x10035f0 */


  lpw = pmapwk; /* Line 878, Address: 0x1003624 */
  lpw += iXwork; /* Line 879, Address: 0x100362c */
  lpw += iYwork << 4; /* Line 880, Address: 0x100363c */
  lpw += (iBlkNo + -1 << 4) << 4; /* Line 881, Address: 0x1003650 */
  return *lpw; /* Line 882, Address: 0x100366c */

} /* Line 884, Address: 0x1003678 */















short dirchk(act_info* pActwk, short scd0, short scd1) { /* Line 900, Address: 0x10036a0 */
  unsigned char cDirectWk;

  cDirectWk = dirstk[2]; /* Line 903, Address: 0x10036b4 */
  if (scd1 > scd0) { /* Line 904, Address: 0x10036c0 */

    cDirectWk = dirstk[0]; /* Line 906, Address: 0x10036e4 */
    scd1 = scd0; /* Line 907, Address: 0x10036f0 */
  }

  if ((cDirectWk & 1) == 0) { /* Line 910, Address: 0x10036f8 */
    pActwk->direc.b.h = cDirectWk; /* Line 911, Address: 0x1003708 */
  }
  else {

    cDirectWk = pActwk->direc.b.h; /* Line 915, Address: 0x1003718 */
    cDirectWk += 32; /* Line 916, Address: 0x1003724 */
    cDirectWk &= 192; /* Line 917, Address: 0x100372c */
    pActwk->direc.b.h = cDirectWk; /* Line 918, Address: 0x1003734 */
  }









  return scd1; /* Line 929, Address: 0x100373c */
} /* Line 930, Address: 0x1003740 */












short scdcnv() {
  return 0; /* Line 944, Address: 0x1003750 */
} /* Line 945, Address: 0x1003754 */
















short st_elseDataChk(short iBlkNo, act_info* pActwk) { /* Line 962, Address: 0x1003760 */
  if ((pActwk->actflg & 64) == 0) /* Line 963, Address: 0x100376c */
    return iBlkNo; /* Line 964, Address: 0x1003784 */
  if (++iBlkNo == 41) /* Line 965, Address: 0x1003790 */
    return 81; /* Line 966, Address: 0x10037b8 */
  return iBlkNo; /* Line 967, Address: 0x10037c4 */
} /* Line 968, Address: 0x10037c8 */















short st_wackyDataChk(short iBlkNo, act_info* pActwk) { /* Line 984, Address: 0x10037e0 */
  if (pActwk->actflg & 64) { /* Line 985, Address: 0x10037ec */


    switch (iBlkNo) { /* Line 988, Address: 0x1003804 */

      case 21:
        iBlkNo = 96; /* Line 991, Address: 0x1003848 */
        break; /* Line 992, Address: 0x1003850 */
      case 30:
        iBlkNo = 97; /* Line 994, Address: 0x1003858 */
        break; /* Line 995, Address: 0x1003860 */
      case 31:
        iBlkNo = 98; /* Line 997, Address: 0x1003868 */
        break; /* Line 998, Address: 0x1003870 */
      case 50:
        iBlkNo = 99; /* Line 1000, Address: 0x1003878 */
        break;
    }
  } /* Line 1003, Address: 0x1003880 */
  else {

    if (iBlkNo == 20) { /* Line 1006, Address: 0x1003888 */

      pActwk->actflg |= 64; /* Line 1008, Address: 0x10038a0 */
      pActwk->sproffset &= 32767; /* Line 1009, Address: 0x10038b0 */
    }
  }
  return iBlkNo; /* Line 1012, Address: 0x10038c0 */
} /* Line 1013, Address: 0x10038c4 */














short st_starDataChk(short iBlkNo, act_info* pActwk) { /* Line 1028, Address: 0x10038d0 */

  pActwk->sproffset |= 32768; /* Line 1030, Address: 0x10038dc */
  if (iBlkNo == 4 || iBlkNo == 6) { /* Line 1031, Address: 0x10038ec */


    pActwk->sproffset &= 32767; /* Line 1034, Address: 0x100391c */
    if (pActwk->actflg & 64) /* Line 1035, Address: 0x100392c */
      ++iBlkNo; /* Line 1036, Address: 0x1003944 */
    return iBlkNo; /* Line 1037, Address: 0x1003950 */
  }
  if (prio_flag == 0) /* Line 1039, Address: 0x100395c */
    return iBlkNo; /* Line 1040, Address: 0x1003970 */

  pActwk->sproffset &= 32767; /* Line 1042, Address: 0x100397c */
  switch (iBlkNo) { /* Line 1043, Address: 0x100398c */

    case 40:
    case 60:
    case 55:
    case 47:
    case 22:
      ++iBlkNo; /* Line 1050, Address: 0x10039dc */
      break;
  }
  return iBlkNo; /* Line 1053, Address: 0x10039e8 */
} /* Line 1054, Address: 0x10039ec */















short st_metalDataChk(short iBlkNo, act_info* pActwk) { /* Line 1070, Address: 0x1003a00 */

  if (pActwk->actno >= 3) /* Line 1072, Address: 0x1003a0c */
    return iBlkNo; /* Line 1073, Address: 0x1003a24 */
  pActwk->sproffset |= 32768; /* Line 1074, Address: 0x1003a30 */
  if (prio_flag == 0) /* Line 1075, Address: 0x1003a40 */
    return iBlkNo; /* Line 1076, Address: 0x1003a54 */
  pActwk->sproffset &= 32767; /* Line 1077, Address: 0x1003a60 */

  switch (iBlkNo) { /* Line 1079, Address: 0x1003a70 */

    case 70:
      iBlkNo = 106; /* Line 1082, Address: 0x1003acc */
      break; /* Line 1083, Address: 0x1003ad4 */
    case 72:
      iBlkNo = 107; /* Line 1085, Address: 0x1003adc */
      break; /* Line 1086, Address: 0x1003ae4 */
    case 74:
      iBlkNo = 108; /* Line 1088, Address: 0x1003aec */
      break; /* Line 1089, Address: 0x1003af4 */
    case 16:
      iBlkNo = 109; /* Line 1091, Address: 0x1003afc */
      break; /* Line 1092, Address: 0x1003b04 */
    case 99:
      iBlkNo = 110; /* Line 1094, Address: 0x1003b0c */
      break; /* Line 1095, Address: 0x1003b14 */
    case 67:
      iBlkNo = 111; /* Line 1097, Address: 0x1003b1c */
      break;
  }
  return iBlkNo; /* Line 1100, Address: 0x1003b24 */
} /* Line 1101, Address: 0x1003b28 */



unsigned char CCset(int lSrc, int lDst) { /* Line 1105, Address: 0x1003b40 */
  lSrc -= lDst; /* Line 1106, Address: 0x1003b4c */
  if (lSrc < 0) return 1; /* Line 1107, Address: 0x1003b5c */
  return 0; /* Line 1108, Address: 0x1003b74 */
} /* Line 1109, Address: 0x1003b78 */


unsigned char CSset(unsigned short wSrc, unsigned short wDst) { /* Line 1112, Address: 0x1003b90 */
  unsigned int wk, lSrc, lDst;

  lSrc = wSrc; /* Line 1115, Address: 0x1003ba8 */
  lDst = wDst; /* Line 1116, Address: 0x1003bb0 */
  wk = lSrc + lDst; /* Line 1117, Address: 0x1003bb8 */
  if (wk >= 1) return 1; /* Line 1118, Address: 0x1003bbc */
  return 0; /* Line 1119, Address: 0x1003bd8 */
} /* Line 1120, Address: 0x1003bdc */







unsigned char bchg(unsigned char bySrc, unsigned char byDst) { /* Line 1128, Address: 0x1003c00 */
  bySrc = 1 << bySrc; /* Line 1129, Address: 0x1003c0c */
  byDst = bySrc ^ byDst; /* Line 1130, Address: 0x1003c24 */
  return byDst; /* Line 1131, Address: 0x1003c40 */
} /* Line 1132, Address: 0x1003c44 */
