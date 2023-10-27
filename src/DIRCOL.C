#include "EQU.H"
#include "DIRCOL.H"
#include "FCOL.H"






















unsigned int swap(int lSrc) { /* Line 26, Address: 0x100dab0 */
  unsigned short iLow, iHi = (unsigned int)(lSrc & -65536) >> 16; /* Line 27, Address: 0x100dac0 */
  iLow = lSrc; /* Line 28, Address: 0x100dad8 */
  return (iHi << 16) | iLow; /* Line 29, Address: 0x100dae8 */
} /* Line 30, Address: 0x100daf8 */















short dircolm(act_info* pActwk, char* cpDirec) { /* Line 46, Address: 0x100db10 */
  return dircol(pActwk, cpDirec); /* Line 47, Address: 0x100db20 */
} /* Line 48, Address: 0x100db30 */

short dircol(act_info* pActwk, char* cpDirec) { /* Line 50, Address: 0x100db40 */
  unsigned char bDirwk, bDirSave;
  short iXposi, iYposi;
  int_union lXposi, lYposi;
  int_union iXspeed, iYspeed;

  lXposi.l = pActwk->xposi.l; /* Line 56, Address: 0x100db60 */
  lYposi.l = pActwk->yposi.l; /* Line 57, Address: 0x100db6c */
  iXspeed.l = pActwk->xspeed.w << 8; /* Line 58, Address: 0x100db78 */
  iYspeed.l = pActwk->yspeed.w << 8; /* Line 59, Address: 0x100db90 */
  lXposi.l += iXspeed.l; /* Line 60, Address: 0x100dba8 */
  lYposi.l += iYspeed.l; /* Line 61, Address: 0x100dbb8 */

  iXposi = lXposi.w.h; /* Line 63, Address: 0x100dbc8 */
  iYposi = lYposi.w.h; /* Line 64, Address: 0x100dbd4 */

  bDirwk = *cpDirec; /* Line 66, Address: 0x100dbe0 */
  bDirSave = bDirwk; /* Line 67, Address: 0x100dbec */
  dirstk[0] = bDirwk; /* Line 68, Address: 0x100dbf0 */
  dirstk[2] = bDirwk; /* Line 69, Address: 0x100dbf8 */
  if ((bDirwk + 32) < 0) /* Line 70, Address: 0x100dc00 */
  {
    if (bDirwk < 0) --bDirwk; /* Line 72, Address: 0x100dc20 */
    bDirwk += 32; /* Line 73, Address: 0x100dc40 */
  } /* Line 74, Address: 0x100dc48 */
  else
  {
    if (bDirwk < 0) ++bDirwk; /* Line 77, Address: 0x100dc50 */
    bDirwk += 31; /* Line 78, Address: 0x100dc70 */
  }


  bDirwk = bDirwk & 192; /* Line 82, Address: 0x100dc78 */

  if (bDirwk == 0) /* Line 84, Address: 0x100dc88 */
    return dircol_d3(pActwk, iXposi, iYposi); /* Line 85, Address: 0x100dc94 */
  if (bDirwk == 128) /* Line 86, Address: 0x100dcb0 */
    return dircol_u3(pActwk, iXposi, iYposi); /* Line 87, Address: 0x100dcc0 */
  bDirSave &= 56; /* Line 88, Address: 0x100dcdc */
  if (bDirSave == 0) iYposi = iYposi + 8; /* Line 89, Address: 0x100dce4 */
  if (bDirwk == 64) /* Line 90, Address: 0x100dcfc */
    return dircol_l3(pActwk, iXposi, iYposi); /* Line 91, Address: 0x100dd0c */

  return dircol_r3(pActwk, iXposi, iYposi); /* Line 93, Address: 0x100dd28 */
} /* Line 94, Address: 0x100dd3c */












short dircol2(act_info* pActwk, char* cpDirec) { /* Line 107, Address: 0x100dd60 */
  short iDirect;
  short iD0, iD1, iD3;
  unsigned char bDirwk;

  dirstk[0] = *cpDirec; /* Line 112, Address: 0x100dd78 */
  dirstk[2] = *cpDirec; /* Line 113, Address: 0x100dd88 */
  *cpDirec += 32; /* Line 114, Address: 0x100dd98 */
  *cpDirec = *cpDirec & 192; /* Line 115, Address: 0x100ddbc */
  bDirwk = *cpDirec; /* Line 116, Address: 0x100dde0 */

  switch (bDirwk) /* Line 118, Address: 0x100ddec */
  {
    case 64:
      iDirect = dircol_l(pActwk, &iD0, &iD1, &iD3); /* Line 121, Address: 0x100de1c */
      break; /* Line 122, Address: 0x100de3c */
    case 128:
      iDirect = dircol_u(pActwk, &iD0, &iD1, &iD3); /* Line 124, Address: 0x100de44 */
      break; /* Line 125, Address: 0x100de64 */
    case 192:
      iDirect = dircol_r(pActwk, &iD0, &iD1, &iD3); /* Line 127, Address: 0x100de6c */
      break; /* Line 128, Address: 0x100de8c */
    default:
      iDirect = dircol_d(pActwk, &iD0, &iD1, &iD3); /* Line 130, Address: 0x100de94 */
      break;
  }
  return iDirect; /* Line 133, Address: 0x100deb4 */
} /* Line 134, Address: 0x100deb8 */


















short dircol_d(act_info* pActwk, short* ipD0, short* ipD1, short* ipD3) { /* Line 153, Address: 0x100ded0 */
  short iXwork;
  short iYwork;
  char cDirect;
  char* cpDirStk;

  iYwork = pActwk->yposi.w.h + pActwk->sprvsize; /* Line 159, Address: 0x100def4 */
  iXwork = pActwk->xposi.w.h + pActwk->sprhs; /* Line 160, Address: 0x100df2c */
  cpDirStk = &dirstk[0]; /* Line 161, Address: 0x100df64 */
  *ipD0 = scdchk(pActwk, iXwork, iYwork, 16, 0, 13, cpDirStk); /* Line 162, Address: 0x100df6c */


  iYwork = pActwk->yposi.w.h + pActwk->sprvsize; /* Line 165, Address: 0x100df98 */
  iXwork = pActwk->xposi.w.h - pActwk->sprhs; /* Line 166, Address: 0x100dfc8 */
  cpDirStk = &dirstk[2]; /* Line 167, Address: 0x100dff8 */
  *ipD1 = scdchk(pActwk, iXwork, iYwork, 16, 0, 13, cpDirStk); /* Line 168, Address: 0x100e000 */

  cDirect = 0; /* Line 170, Address: 0x100e02c */
  return dircolchk(ipD0, ipD1, ipD3, &cDirect); /* Line 171, Address: 0x100e030 */
} /* Line 172, Address: 0x100e048 */
















short dircol_d3(act_info* pActwk, short iXposi, short iYposi) { /* Line 189, Address: 0x100e070 */
  short iScd;
  char* cpDirStk = &dirstk[0]; /* Line 191, Address: 0x100e08c */

  iYposi += 10; /* Line 193, Address: 0x100e094 */
  iScd = scdchk(pActwk, iXposi, iYposi, 16, 0, 14, cpDirStk); /* Line 194, Address: 0x100e0a0 */
  dircolchk1(0); /* Line 195, Address: 0x100e0cc */
  return iScd; /* Line 196, Address: 0x100e0d8 */
} /* Line 197, Address: 0x100e0dc */


















short dircol_r(act_info* pActwk, short* ipD0, short* ipD1, short* ipD3) { /* Line 216, Address: 0x100e100 */
  short iXwork;
  short iYwork;
  char cDirect;
  char* cpDirStk;

  iYwork = pActwk->yposi.w.h - pActwk->sprhs; /* Line 222, Address: 0x100e124 */
  iXwork = pActwk->xposi.w.h + pActwk->sprvsize; /* Line 223, Address: 0x100e15c */
  cpDirStk = &dirstk[0]; /* Line 224, Address: 0x100e194 */
  *ipD0 = scdchk_r(pActwk, iXwork, iYwork, 16, 0, 14, cpDirStk); /* Line 225, Address: 0x100e19c */


  iYwork = pActwk->yposi.w.h + pActwk->sprhs; /* Line 228, Address: 0x100e1c8 */
  iXwork = pActwk->xposi.w.h + pActwk->sprvsize; /* Line 229, Address: 0x100e200 */
  cpDirStk = &dirstk[2]; /* Line 230, Address: 0x100e238 */
  *ipD1 = scdchk_r(pActwk, iXwork, iYwork, 16, 0, 14, cpDirStk); /* Line 231, Address: 0x100e240 */

  cDirect = -64; /* Line 233, Address: 0x100e26c */
  return dircolchk(ipD0, ipD1, ipD3, &cDirect); /* Line 234, Address: 0x100e274 */
} /* Line 235, Address: 0x100e28c */











short dircol_r2(act_info* pActwk) { /* Line 247, Address: 0x100e2b0 */
  return dircol_r3(pActwk, pActwk->xposi.w.h, pActwk->yposi.w.h); /* Line 248, Address: 0x100e2bc */
} /* Line 249, Address: 0x100e2d8 */
















short dircol_r3(act_info* pActwk, short iXposi, short iYposi) { /* Line 266, Address: 0x100e2f0 */
  short iScd = 0; /* Line 267, Address: 0x100e30c */
  char* cpDirStk = &dirstk[0]; /* Line 268, Address: 0x100e310 */

  iXposi += 10; /* Line 270, Address: 0x100e318 */
  iScd = scdchk_r(pActwk, iXposi, iYposi, 16, 0, 14, cpDirStk); /* Line 271, Address: 0x100e324 */
  dircolchk1(-64); /* Line 272, Address: 0x100e350 */
  return iScd; /* Line 273, Address: 0x100e35c */
} /* Line 274, Address: 0x100e360 */



















short dircol_l(act_info* pActwk, short* ipD0, short* ipD1, short* ipD3) { /* Line 294, Address: 0x100e380 */
  short iXwork;
  short iYwork;
  char cDirect;
  char* cpDirstk;

  iYwork = pActwk->yposi.w.h - pActwk->sprhs; /* Line 300, Address: 0x100e3a4 */
  iXwork = (pActwk->xposi.w.h - pActwk->sprvsize) ^ 15; /* Line 301, Address: 0x100e3dc */
  cpDirstk = &dirstk[0]; /* Line 302, Address: 0x100e418 */
  *ipD0 = scdchk_r(pActwk, iXwork, iYwork, -16, 2048, 14, cpDirstk); /* Line 303, Address: 0x100e420 */


  iYwork = pActwk->yposi.w.h + pActwk->sprhs; /* Line 306, Address: 0x100e44c */
  iXwork = (pActwk->xposi.w.h - pActwk->sprvsize) ^ 15; /* Line 307, Address: 0x100e484 */
  cpDirstk = &dirstk[2]; /* Line 308, Address: 0x100e4c0 */
  *ipD1 = scdchk_r(pActwk, iXwork, iYwork, -16, 2048, 14, cpDirstk); /* Line 309, Address: 0x100e4c8 */

  cDirect = 64; /* Line 311, Address: 0x100e4f4 */
  return dircolchk(ipD0, ipD1, ipD3, &cDirect); /* Line 312, Address: 0x100e4fc */
} /* Line 313, Address: 0x100e514 */











short dircol_l2(act_info* pActwk) { /* Line 325, Address: 0x100e530 */
  return dircol_l3(pActwk, pActwk->xposi.w.h, pActwk->yposi.w.h); /* Line 326, Address: 0x100e53c */
} /* Line 327, Address: 0x100e558 */
















short dircol_l3(act_info* pActwk, short iXposi, short iYposi) { /* Line 344, Address: 0x100e570 */
  char* cpDirStk = &dirstk[0]; /* Line 345, Address: 0x100e58c */
  short iScd;

  iXposi = (iXposi + -10) ^ 15; /* Line 348, Address: 0x100e594 */
  iScd = scdchk_r(pActwk, iXposi, iYposi, -16, 2048, 14, cpDirStk); /* Line 349, Address: 0x100e5b4 */
  dircolchk1(64); /* Line 350, Address: 0x100e5e0 */
  return iScd; /* Line 351, Address: 0x100e5ec */
} /* Line 352, Address: 0x100e5f0 */


















short dircol_u(act_info* pActwk, short* ipD0, short* ipD1, short* ipD3) { /* Line 371, Address: 0x100e610 */
  short iXwork;
  short iYwork;
  char cDirect;
  char* cpDirStk;

  iYwork = (pActwk->yposi.w.h - pActwk->sprvsize) ^ 15; /* Line 377, Address: 0x100e634 */
  iXwork = pActwk->xposi.w.h + pActwk->sprhs; /* Line 378, Address: 0x100e670 */
  cpDirStk = &dirstk[0]; /* Line 379, Address: 0x100e6a8 */
  *ipD0 = scdchk(pActwk, iXwork, iYwork, -16, 4096, 14, cpDirStk); /* Line 380, Address: 0x100e6b0 */


  iYwork = (pActwk->yposi.w.h - pActwk->sprvsize) ^ 15; /* Line 383, Address: 0x100e6dc */
  iXwork = pActwk->xposi.w.h - pActwk->sprhs; /* Line 384, Address: 0x100e718 */
  cpDirStk = &dirstk[2]; /* Line 385, Address: 0x100e750 */
  *ipD1 = scdchk(pActwk, iXwork, iYwork, -16, 4096, 14, cpDirStk); /* Line 386, Address: 0x100e758 */

  cDirect = -128; /* Line 388, Address: 0x100e784 */
  return dircolchk(ipD0, ipD1, ipD3, &cDirect); /* Line 389, Address: 0x100e78c */
} /* Line 390, Address: 0x100e7a4 */











short dircol_u2(act_info* pActwk) { /* Line 402, Address: 0x100e7c0 */
  return dircol_u3(pActwk, pActwk->xposi.w.h, pActwk->yposi.w.h); /* Line 403, Address: 0x100e7cc */
} /* Line 404, Address: 0x100e7e8 */
















short dircol_u3(act_info* pActwk, short iXposi, short iYposi) { /* Line 421, Address: 0x100e800 */
  short iScd;
  char* cpDirStk = &dirstk[0]; /* Line 423, Address: 0x100e81c */

  iYposi = (iYposi + -10) ^ 15; /* Line 425, Address: 0x100e824 */
  iScd = scdchk(pActwk, iXposi, iYposi, -16, 4096, 14, cpDirStk); /* Line 426, Address: 0x100e844 */
  dircolchk1(-128); /* Line 427, Address: 0x100e870 */
  return iScd; /* Line 428, Address: 0x100e87c */
} /* Line 429, Address: 0x100e880 */











short emycol_u(act_info* pActwk) { /* Line 441, Address: 0x100e8a0 */
  short iXwork, iYwork, iScd;
  char* cpDirStk = &dirstk[0]; /* Line 443, Address: 0x100e8bc */

  iYwork = (pActwk->yposi.w.h - pActwk->sprvsize) ^ 15; /* Line 445, Address: 0x100e8c4 */
  iXwork = pActwk->xposi.w.h; /* Line 446, Address: 0x100e8f8 */
  iScd = scdchk(pActwk, iXwork, iYwork, -16, 4096, 14, cpDirStk); /* Line 447, Address: 0x100e908 */


  return iScd; /* Line 450, Address: 0x100e934 */
} /* Line 451, Address: 0x100e938 */











short emycol_d(act_info* pActwk) { /* Line 463, Address: 0x100e960 */
  return emycol_d2(pActwk, pActwk->xposi.w.h); /* Line 464, Address: 0x100e96c */
} /* Line 465, Address: 0x100e980 */











short emycol_d2(act_info* pActwk, short iXposi) { /* Line 477, Address: 0x100e990 */
  short iYposi;

  iYposi = pActwk->yposi.w.h + pActwk->sprvsize; /* Line 480, Address: 0x100e9a4 */
  return emycol_d3(pActwk, iXposi, iYposi); /* Line 481, Address: 0x100e9e8 */
} /* Line 482, Address: 0x100e9fc */












short emycol_d3(act_info* pActwk, short iXposi, short iYposi) { /* Line 495, Address: 0x100ea10 */
  short iScd;
  char* cpDirStk = &dirstk[0]; /* Line 497, Address: 0x100ea2c */

  *cpDirStk = 0; /* Line 499, Address: 0x100ea34 */
  iScd = scdchk(pActwk, iXposi, iYposi, 16, 0, 13, cpDirStk); /* Line 500, Address: 0x100ea38 */


  return iScd; /* Line 503, Address: 0x100ea64 */
} /* Line 504, Address: 0x100ea68 */












short emycol_l(act_info* pActwk, unsigned char sprhs) { /* Line 517, Address: 0x100ea80 */
  short iXwork;
  char cSprhs;

  cSprhs = sprhs; /* Line 521, Address: 0x100ea98 */
  iXwork = pActwk->xposi.w.h + cSprhs; /* Line 522, Address: 0x100eaa4 */
  return emycol_l3(pActwk, iXwork, pActwk->yposi.w.h); /* Line 523, Address: 0x100ead8 */
} /* Line 524, Address: 0x100eaf0 */













short emycol_l3(act_info* pActwk, short iXposi, short iYposi) { /* Line 538, Address: 0x100eb10 */
  short iScd;
  char* cpDirStk = &dirstk[0]; /* Line 540, Address: 0x100eb2c */

  *cpDirStk = 0; /* Line 542, Address: 0x100eb34 */
  iScd = scdchk_r(pActwk, iXposi, iYposi, -16, 2048, 14, cpDirStk); /* Line 543, Address: 0x100eb38 */


  return iScd; /* Line 546, Address: 0x100eb64 */
} /* Line 547, Address: 0x100eb68 */











short emycol_r(act_info* pActwk, unsigned char sprhs) { /* Line 559, Address: 0x100eb80 */
  short iXwork;
  char cSprhs;

  cSprhs = sprhs; /* Line 563, Address: 0x100eb98 */
  iXwork = pActwk->xposi.w.h + cSprhs; /* Line 564, Address: 0x100eba4 */
  return emycol_r3(pActwk, iXwork, pActwk->yposi.w.h); /* Line 565, Address: 0x100ebd8 */
} /* Line 566, Address: 0x100ebf0 */












short emycol_r3(act_info* pActwk, short iXposi, short iYposi) { /* Line 579, Address: 0x100ec10 */
  short iScd;
  char* cpDirStk = &dirstk[0]; /* Line 581, Address: 0x100ec2c */

  iScd = scdchk_r(pActwk, iXposi, iYposi, 16, 0, 14, cpDirStk); /* Line 583, Address: 0x100ec34 */


  return iScd; /* Line 586, Address: 0x100ec60 */
} /* Line 587, Address: 0x100ec64 */



















short dircolchk(short* ipD0, short* ipD1, short* ipD3, char* cpDirec) { /* Line 607, Address: 0x100ec80 */
  short iWork;


  if (*ipD1 < *ipD0) /* Line 611, Address: 0x100ec98 */
  {
    iWork = *ipD1; /* Line 613, Address: 0x100ecc4 */
    *ipD1 = *ipD0; /* Line 614, Address: 0x100ecd4 */
    *ipD0 = iWork; /* Line 615, Address: 0x100ece4 */
    *ipD3 = dirstk[0]; /* Line 616, Address: 0x100ecec */
  } /* Line 617, Address: 0x100ed04 */
  else
    *ipD3 = dirstk[2]; /* Line 619, Address: 0x100ed0c */

  if (*ipD3 & 1) /* Line 621, Address: 0x100ed24 */
    *ipD3 = *cpDirec; /* Line 622, Address: 0x100ed40 */
  return *ipD1; /* Line 623, Address: 0x100ed58 */
} /* Line 624, Address: 0x100ed60 */











short dircolchk1(char cDirec) { /* Line 636, Address: 0x100ed70 */
  char cDirWk = dirstk[0]; /* Line 637, Address: 0x100ed7c */

  if (cDirWk & 1) cDirWk = cDirec; /* Line 639, Address: 0x100ed8c */
  return cDirWk; /* Line 640, Address: 0x100edac */
} /* Line 641, Address: 0x100edb4 */
