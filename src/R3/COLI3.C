#include "..\EQU.H"
#include "COLI3.H"

static unsigned char bCarry;
unsigned char colitbl[64][2] =
{
  {  20,  20 },
  {  16,  12 },
  {  12,  16 },
  {   4,  16 },
  {  12,  18 },
  {  16,  16 },
  {   6,   6 },
  {  24,  12 },
  {  12,  16 },
  {  16,  12 },
  {   8,   8 },
  {  20,  16 },
  {  20,   8 },
  {  14,  14 },
  {  24,  24 },
  {  40,  16 },
  {  16,  24 },
  {   8,  16 },
  {  32, 112 },
  {  64,  32 },
  { 128,  32 },
  {  32,  32 },
  {   8,   8 },
  {   4,   4 },
  {  32,   8 },
  {  12,  12 },
  {   8,   4 },
  {  24,   4 },
  {  40,   4 },
  {   4,   8 },
  {   4,  24 },
  {   4,  40 },
  {   4,  32 },
  {  24,  24 },
  {  12,  24 },
  {  72,   8 },
  {   8,  12 },
  {  16,   8 },
  {  32,  16 },
  {  32,  16 },
  {   8,   8 },
  {  16,  16 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {  40,  36 },
  {  18,  17 },
  {   0,   0 },
  {   0,   0 },
  {  48,  16 },
  {  64,  16 },
  {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };







short pcol(sprite_status* pActwk) { /* Line 80, Address: 0x101b500 */
  short iXwork = pActwk->xposi.w.h, /* Line 81, Address: 0x101b52c */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 84, Address: 0x101b56c */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  if (pActwk->actfree[2] & 64) /* Line 88, Address: 0x101b578 */
    return 0; /* Line 89, Address: 0x101b590 */

  iXwork -= 8; /* Line 91, Address: 0x101b59c */
  iYwork -= iSprvs; /* Line 92, Address: 0x101b5a8 */
  if (pActwk->patno == 57) /* Line 93, Address: 0x101b5b4 */
  {
    iYwork += 12; /* Line 95, Address: 0x101b5cc */
    iSprvs = 10; /* Line 96, Address: 0x101b5d8 */
  }

  iXcollichk = 16; /* Line 99, Address: 0x101b5e4 */
  iSprvs += iSprvs; /* Line 100, Address: 0x101b5f0 */

  pColliAct = &actwk[32]; /* Line 102, Address: 0x101b5fc */

  for (i = 0; i < 96; ++i, ++pColliAct) /* Line 104, Address: 0x101b604 */
  {

    if (pActwk->actflg & 128) /* Line 107, Address: 0x101b610 */
    {
      iColino = pActwk->colino; /* Line 109, Address: 0x101b624 */
      if (iColino != 0) /* Line 110, Address: 0x101b634 */
      {
        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 112, Address: 0x101b644 */
        if (iRet != 0) /* Line 113, Address: 0x101b668 */
          return iRet; /* Line 114, Address: 0x101b670 */
      }
    }
  } /* Line 117, Address: 0x101b67c */
  return 0; /* Line 118, Address: 0x101b6a0 */
} /* Line 119, Address: 0x101b6a4 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 139, Address: 0x101b6e0 */
  short iColiNo = pActwk->colino; /* Line 140, Address: 0x101b708 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 144, Address: 0x101b71c */
  iColiwk = colitbl[iColiNo][0]; /* Line 145, Address: 0x101b73c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 147, Address: 0x101b764 */
  bCarry = CCset(iColiData, iXposi); /* Line 148, Address: 0x101b790 */
  iColiData -= iXposi; /* Line 149, Address: 0x101b7b4 */
  if (bCarry == 1) /* Line 150, Address: 0x101b7dc */
  {
    iColiwk += iColiwk; /* Line 152, Address: 0x101b7f4 */
    bCarry = CSset(iColiData, iColiwk); /* Line 153, Address: 0x101b800 */
    iColiData += iColiwk; /* Line 154, Address: 0x101b818 */
    if (bCarry == 1) /* Line 155, Address: 0x101b824 */
      return CollitblDataYchk(pActwk, pColliAct, iYposi, iColiNo, iD5); /* Line 156, Address: 0x101b83c */

    return 0; /* Line 158, Address: 0x101b860 */
  }

  if (iColiData >= 17) /* Line 161, Address: 0x101b86c */
    return 0; /* Line 162, Address: 0x101b880 */


  CollitblDataYchk(pActwk, pColliAct, iYposi, iColiNo, iD5); /* Line 165, Address: 0x101b88c */

} /* Line 167, Address: 0x101b8a8 */




















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iYposi, short iColiNo, short iD5) { /* Line 188, Address: 0x101b8d0 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 192, Address: 0x101b8f4 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 194, Address: 0x101b920 */
  bCarry = CCset(iYwork, iYposi); /* Line 195, Address: 0x101b94c */
  iYwork -= iYposi; /* Line 196, Address: 0x101b970 */
  if (bCarry == 1) /* Line 197, Address: 0x101b998 */
  {
    iColiData += iColiData; /* Line 199, Address: 0x101b9b0 */
    bCarry = CSset(iColiData, iYwork); /* Line 200, Address: 0x101b9bc */
    iColiData += iYwork; /* Line 201, Address: 0x101b9d4 */
    if (bCarry == 1) /* Line 202, Address: 0x101b9e0 */
      return ColliHitChk(pActwk, pColliAct); /* Line 203, Address: 0x101b9f8 */

    return 0; /* Line 205, Address: 0x101ba10 */
  }


  if (iYwork > iD5) /* Line 209, Address: 0x101ba1c */
    return 0; /* Line 210, Address: 0x101ba3c */


  return ColliHitChk(pActwk, pColliAct); /* Line 213, Address: 0x101ba48 */

} /* Line 215, Address: 0x101ba58 */





















short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 237, Address: 0x101ba70 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 238, Address: 0x101ba84 */

  if (iColino == 0) /* Line 240, Address: 0x101ba9c */
  {
    pcolnomal(pActwk, pColliAct); /* Line 242, Address: 0x101baa8 */
    return 1; /* Line 243, Address: 0x101bab8 */
  }
  if (iColino == 192) /* Line 245, Address: 0x101bac4 */
  {
    pcolspecial(pActwk, pColliAct); /* Line 247, Address: 0x101bad4 */
    return 1; /* Line 248, Address: 0x101bae4 */
  }
  if ((char)iColino < 0) /* Line 250, Address: 0x101baf0 */
  {
    pcolplay(pActwk, pColliAct); /* Line 252, Address: 0x101bb08 */
    return 1; /* Line 253, Address: 0x101bb18 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 257, Address: 0x101bb24 */

} /* Line 259, Address: 0x101bb34 */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 274, Address: 0x101bb50 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) /* Line 277, Address: 0x101bb64 */
  {

    if (((unsigned short*)pActwk)[26] < 90) /* Line 280, Address: 0x101bb80 */
      pColliAct->r_no0 += 2; /* Line 281, Address: 0x101bb98 */
  } /* Line 282, Address: 0x101bba8 */
  else
  {

    if (pActwk->yspeed.w < 0) /* Line 286, Address: 0x101bbb0 */
    {
      iD0 = pActwk->yposi.w.h - 16; /* Line 288, Address: 0x101bbc8 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 289, Address: 0x101bbec */
      if (bCarry == 0) /* Line 290, Address: 0x101bc14 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 292, Address: 0x101bc28 */
        pColliAct->yspeed.w = -384; /* Line 293, Address: 0x101bc4c */
        if (pColliAct->r_no1 == 0) /* Line 294, Address: 0x101bc58 */
          pColliAct->r_no1 += 4; /* Line 295, Address: 0x101bc6c */
      }
    } /* Line 297, Address: 0x101bc7c */
    else
    {

      if (pActwk->mstno.b.h == 2) /* Line 301, Address: 0x101bc84 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 303, Address: 0x101bca0 */
        pColliAct->r_no0 += 2; /* Line 304, Address: 0x101bcc4 */
      }
    }
  }
  return -1; /* Line 308, Address: 0x101bcd4 */
} /* Line 309, Address: 0x101bcd8 */














short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 324, Address: 0x101bcf0 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) /* Line 328, Address: 0x101bd08 */
  {


    pcolplay(pActwk, pColliAct); /* Line 332, Address: 0x101bd4c */
    return -1; /* Line 333, Address: 0x101bd5c */
  }


  if (pColliAct->colicnt != 0) /* Line 337, Address: 0x101bd68 */
  {
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 339, Address: 0x101bd7c */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 340, Address: 0x101bda0 */
    pActwk->xspeed.w /= 2; /* Line 341, Address: 0x101bdc4 */
    pActwk->yspeed.w /= 2; /* Line 342, Address: 0x101bde8 */
    pColliAct->colino = 0; /* Line 343, Address: 0x101be0c */
    --pColliAct->colicnt; /* Line 344, Address: 0x101be14 */
    if (pColliAct->colicnt == 0) /* Line 345, Address: 0x101be24 */
      pColliAct->cddat |= 128; /* Line 346, Address: 0x101be38 */
  } /* Line 347, Address: 0x101be48 */
  else
  {

    pColliAct->cddat |= 128; /* Line 351, Address: 0x101be50 */
    iScoreCntwk = emyscorecnt; /* Line 352, Address: 0x101be60 */
    emyscorecnt += 2; /* Line 353, Address: 0x101be70 */
    if ((unsigned short)iScoreCntwk >= 6) /* Line 354, Address: 0x101be84 */
      iScoreCntwk = 6; /* Line 355, Address: 0x101be98 */

    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 357, Address: 0x101bea4 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 358, Address: 0x101beac */
    if (emyscorecnt >= 32) /* Line 359, Address: 0x101bee8 */
    {
      iScoreData = 1000; /* Line 361, Address: 0x101bf04 */
      ((short*)pColliAct)[33] = 10; /* Line 362, Address: 0x101bf10 */
    }

    scoreup(iScoreData); /* Line 365, Address: 0x101bf1c */
    soundset(150); /* Line 366, Address: 0x101bf2c */
    pColliAct->actno = 24; /* Line 367, Address: 0x101bf38 */
    pColliAct->r_no0 = 0; /* Line 368, Address: 0x101bf44 */
    pColliAct->userflag.b.h = 1; /* Line 369, Address: 0x101bf4c */

    if (pActwk->yspeed.w >= 0) /* Line 371, Address: 0x101bf58 */
    {
      if (pActwk->yposi.w.h < pColliAct->yposi.w.h) /* Line 373, Address: 0x101bf70 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 374, Address: 0x101bf9c */
      else
        pActwk->yspeed.w -= 256; /* Line 376, Address: 0x101bfc8 */
    } /* Line 377, Address: 0x101bfd8 */
    else
      pActwk->yspeed.w += 256; /* Line 379, Address: 0x101bfe0 */
  }
  return -1; /* Line 381, Address: 0x101bff0 */
} /* Line 382, Address: 0x101bff4 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 398, Address: 0x101c010 */
  pColliAct->cddat |= 128; /* Line 399, Address: 0x101c020 */
  return pcolplay(pActwk, pColliAct); /* Line 400, Address: 0x101c030 */
} /* Line 401, Address: 0x101c040 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 416, Address: 0x101c050 */
  if (plpower_m == 0) /* Line 417, Address: 0x101c060 */
    return pcole(pActwk, pColliAct); /* Line 418, Address: 0x101c074 */

  return -1; /* Line 420, Address: 0x101c08c */
} /* Line 421, Address: 0x101c090 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 436, Address: 0x101c0a0 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 437, Address: 0x101c0b0 */
    return -1; /* Line 438, Address: 0x101c0c4 */

  return playdamageset(pActwk, pColliAct); /* Line 440, Address: 0x101c0d0 */
} /* Line 441, Address: 0x101c0e0 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 456, Address: 0x101c0f0 */


  pActwk->actfree[0] = 0; /* Line 459, Address: 0x101c100 */
  if (!(plpower_b & 1)) /* Line 460, Address: 0x101c108 */
    conbine_flag = 0; /* Line 461, Address: 0x101c120 */
  plpower_b &= 254; /* Line 462, Address: 0x101c128 */

  pActwk->r_no0 = 4; /* Line 464, Address: 0x101c13c */
  jumpcolsub(); /* Line 465, Address: 0x101c148 */
  pActwk->cddat |= 2; /* Line 466, Address: 0x101c150 */

  if (pActwk->cddat & 64) /* Line 468, Address: 0x101c160 */
  {
    pActwk->yspeed.w = -512; /* Line 470, Address: 0x101c178 */
    pActwk->xspeed.w = -256; /* Line 471, Address: 0x101c184 */
  } /* Line 472, Address: 0x101c190 */
  else
  {
    pActwk->yspeed.w = -1024; /* Line 475, Address: 0x101c198 */
    pActwk->xspeed.w = -512; /* Line 476, Address: 0x101c1a4 */
  }


  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) /* Line 480, Address: 0x101c1b0 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 481, Address: 0x101c1dc */

  pActwk->mspeed.w = 0; /* Line 483, Address: 0x101c200 */
  pActwk->mstno.b.h = 26; /* Line 484, Address: 0x101c208 */
  ((short*)pActwk)[26] = 120; /* Line 485, Address: 0x101c214 */
} /* Line 486, Address: 0x101c220 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 501, Address: 0x101c230 */
  sprite_status* pFreeAct;
  int iRet;

  if (plpower_b != 0) /* Line 505, Address: 0x101c244 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 507, Address: 0x101c258 */
    return -1; /* Line 508, Address: 0x101c268 */
  }
  if (plring != 0) /* Line 510, Address: 0x101c274 */
  {
    iRet = actwkchk(&pFreeAct); /* Line 512, Address: 0x101c28c */
    if (iRet == 0) /* Line 513, Address: 0x101c29c */
    {
      pFreeAct->actno = 17; /* Line 515, Address: 0x101c2a4 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 516, Address: 0x101c2b0 */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 517, Address: 0x101c2c0 */
    }

    playdamagechk(pActwk, pColliAct); /* Line 520, Address: 0x101c2d0 */
    return -1; /* Line 521, Address: 0x101c2e0 */
  }

  if (debugflag.w != 0) /* Line 524, Address: 0x101c2ec */
  {
    playdamagechk(pActwk, pColliAct); /* Line 526, Address: 0x101c304 */
    return -1; /* Line 527, Address: 0x101c314 */
  }
  playdieset(pActwk); /* Line 529, Address: 0x101c320 */
} /* Line 530, Address: 0x101c32c */












short playdieset(sprite_status* pActwk) { /* Line 543, Address: 0x101c340 */
  if (editmode.w != 0) /* Line 544, Address: 0x101c34c */
    return -1; /* Line 545, Address: 0x101c364 */
  plpower_m = 0; /* Line 546, Address: 0x101c370 */
  pActwk->r_no0 = 6; /* Line 547, Address: 0x101c378 */
  jumpcolsub(); /* Line 548, Address: 0x101c384 */
  pActwk->cddat |= 2; /* Line 549, Address: 0x101c38c */
  pActwk->yspeed.w = -1792; /* Line 550, Address: 0x101c39c */
  pActwk->xspeed.w = 0; /* Line 551, Address: 0x101c3a8 */
  pActwk->mspeed.w = 0; /* Line 552, Address: 0x101c3b0 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 553, Address: 0x101c3b8 */
  pActwk->mstno.b.h = 24; /* Line 554, Address: 0x101c3c8 */
  pActwk->sproffset |= 32768; /* Line 555, Address: 0x101c3d4 */
  pActwk->sprpri = 0; /* Line 556, Address: 0x101c3e4 */
  soundset(147); /* Line 557, Address: 0x101c3ec */
  return -1; /* Line 558, Address: 0x101c3f8 */
} /* Line 559, Address: 0x101c3fc */
















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 576, Address: 0x101c410 */
  char cColiNo = pColliAct->colino & 63; /* Line 577, Address: 0x101c424 */

  switch (cColiNo) /* Line 579, Address: 0x101c444 */
  {
    case 23:
    case 31:
    case 35:
    case 39:
      ++pColliAct->colicnt; /* Line 585, Address: 0x101c49c */
      break; /* Line 586, Address: 0x101c4ac */
    case 58:
    case 59:
      main_attack(pActwk, pColliAct); /* Line 589, Address: 0x101c4b4 */
      break; /* Line 590, Address: 0x101c4c4 */
    default:
      eggman_chk(pActwk, pColliAct, cColiNo); /* Line 592, Address: 0x101c4cc */
      break;
  }
  return -1; /* Line 595, Address: 0x101c4e0 */
} /* Line 596, Address: 0x101c4e4 */
















short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 613, Address: 0x101c500 */

  if (bossstart != 1) return -1; /* Line 615, Address: 0x101c514 */
  switch (bossstart) /* Line 616, Address: 0x101c538 */
  {
    case 1:
      boss_1(pActwk, pColliAct, cColiNo); /* Line 619, Address: 0x101c570 */
      break; /* Line 620, Address: 0x101c584 */
    case 4:
      boss_4(pActwk, pColliAct, cColiNo); /* Line 622, Address: 0x101c58c */
      break; /* Line 623, Address: 0x101c5a0 */
    case 5:
      boss_5(pActwk, pColliAct, cColiNo); /* Line 625, Address: 0x101c5a8 */
      break; /* Line 626, Address: 0x101c5bc */
    default:
      boss_1(pActwk, pColliAct, cColiNo); /* Line 628, Address: 0x101c5c4 */
      break;
  }
  return 1; /* Line 631, Address: 0x101c5d8 */
} /* Line 632, Address: 0x101c5dc */















void boss_1(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 648, Address: 0x101c5f0 */
  if (cColiNo < 60 || cColiNo >= 64) /* Line 649, Address: 0x101c604 */
    return; /* Line 650, Address: 0x101c634 */






  pcolnomal(pActwk, pColliAct); /* Line 657, Address: 0x101c63c */
  if (pColliAct->colino == 0) /* Line 658, Address: 0x101c64c */
    pColliAct->colicnt += 3; /* Line 659, Address: 0x101c660 */
  pColliAct->colino = 0; /* Line 660, Address: 0x101c670 */

  ++pColliAct->colicnt; /* Line 662, Address: 0x101c678 */
} /* Line 663, Address: 0x101c688 */















void boss_4(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 679, Address: 0x101c6a0 */
  if (cColiNo >= 63) /* Line 680, Address: 0x101c6b4 */
  {

    if (!(pActwk->cddat & 20)) return; /* Line 683, Address: 0x101c6cc */

    pActwk->cddat &= 251; /* Line 685, Address: 0x101c6e4 */
    pActwk->cddat &= 239; /* Line 686, Address: 0x101c6f4 */
    pActwk->colino = 0; /* Line 687, Address: 0x101c704 */
    pActwk->mstno.b.h = 21; /* Line 688, Address: 0x101c70c */

    pActwk->yspeed.w = 1024; /* Line 690, Address: 0x101c718 */
    pActwk->xspeed.w = -512; /* Line 691, Address: 0x101c724 */
    if (pActwk->xposi.w.h >= pColliAct->xposi.w.h) /* Line 692, Address: 0x101c730 */
      pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 693, Address: 0x101c75c */
  } /* Line 694, Address: 0x101c780 */
  else if (cColiNo == 62) /* Line 695, Address: 0x101c788 */
  {
    pcolplay(pActwk, pColliAct); /* Line 697, Address: 0x101c7a0 */
    ++pColliAct->colicnt; /* Line 698, Address: 0x101c7b0 */
  }
} /* Line 700, Address: 0x101c7c0 */














void boss_5(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 715, Address: 0x101c7d0 */
  if (cColiNo == 61) /* Line 716, Address: 0x101c7e4 */
  {
    pcolplay(pActwk, pColliAct); /* Line 718, Address: 0x101c7fc */
    ++pColliAct->colicnt; /* Line 719, Address: 0x101c80c */
  }
} /* Line 721, Address: 0x101c81c */














void main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 736, Address: 0x101c830 */
  if (pActwk->mstno.b.h == 2) /* Line 737, Address: 0x101c83c */
    ++pColliAct->colicnt; /* Line 738, Address: 0x101c858 */
} /* Line 739, Address: 0x101c868 */
