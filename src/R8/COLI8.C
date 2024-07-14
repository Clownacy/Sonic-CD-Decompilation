#include "..\EQU.H"
#include "COLI8.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYER.H"
#include "..\SCORE.H"

extern short actwkchk(sprite_status** ppActwk);

static unsigned char bCarry;
unsigned char colitbl[64][2] = {
  {  20,  20 },
  {  18,  12 },
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
  {  40,  36 },
  {  12,  24 },
  {  28,  28 },
  {  56,   6 },
  {  16,  16 },
  {   6,   6 },
  {  32,   4 },
  {  28,  28 },
  {  16,  14 },
  {  12,  16 },
  {  16,   9 },
  {  16,  16 },
  {  12,  14 },
  {   8,   8 },
  {  24,  11 },
  {  16,  60 },
  {  16,  36 },
  {  36,  16 },
  {  24,  24 },
  {  22,  22 },
  {  16,  16 },
  {  24,  20 },
  {  24,  24 },
  {  15,  32 },
  {  32,  15 },
  {   8,  32 },
  {  16,  32 },
  {  28,  28 },
  {  32,  16 },
  {  32,   8 },
  {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };

short pcol(sprite_status* pActwk) { /* Line 79, Address: 0x101acd0 */
  short iXwork = pActwk->xposi.w.h, /* Line 80, Address: 0x101acfc */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 83, Address: 0x101ad3c */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  if (pActwk->actfree[2] & 1) { /* Line 87, Address: 0x101ad48 */
    return 0; /* Line 88, Address: 0x101ad60 */
  }


  iXwork -= 8; /* Line 92, Address: 0x101ad6c */
  iYwork -= iSprvs; /* Line 93, Address: 0x101ad78 */

  if (pActwk->patno == 57) { /* Line 95, Address: 0x101ad84 */

    iYwork += 12; /* Line 97, Address: 0x101ad9c */
    iSprvs = 10; /* Line 98, Address: 0x101ada8 */
  }

  iXcollichk = 16; /* Line 101, Address: 0x101adb4 */
  iSprvs += iSprvs; /* Line 102, Address: 0x101adc0 */

  pColliAct = &actwk[32]; /* Line 104, Address: 0x101adcc */

  for (i = 0; i < 96; ++i, ++pColliAct) { /* Line 106, Address: 0x101add4 */


    if (pColliAct->actflg & 128) { /* Line 109, Address: 0x101ade0 */

      iColino = pColliAct->colino; /* Line 111, Address: 0x101adf4 */
      if (iColino != 0) { /* Line 112, Address: 0x101ae04 */

        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 114, Address: 0x101ae14 */
        if (iRet) /* Line 115, Address: 0x101ae38 */
          return iRet; /* Line 116, Address: 0x101ae40 */
      }
    }
  } /* Line 119, Address: 0x101ae4c */
  iColino = 0; /* Line 120, Address: 0x101ae70 */
  return iColino; /* Line 121, Address: 0x101ae74 */
} /* Line 122, Address: 0x101ae78 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 142, Address: 0x101aeb0 */
  short iColiNo = pColliAct->colino; /* Line 143, Address: 0x101aed8 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 147, Address: 0x101aeec */
  iColiwk = colitbl[iColiNo][0]; /* Line 148, Address: 0x101af0c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 150, Address: 0x101af34 */
  bCarry = CCset(iColiData, iXposi); /* Line 151, Address: 0x101af60 */
  iColiData = iColiData - iXposi; /* Line 152, Address: 0x101af84 */

  if (bCarry == 1) { /* Line 154, Address: 0x101afac */

    iColiwk += iColiwk; /* Line 156, Address: 0x101afc4 */
    bCarry = CSset(iColiData, iColiwk); /* Line 157, Address: 0x101afd0 */
    iColiData += iColiwk; /* Line 158, Address: 0x101afe8 */
    if (bCarry == 1) /* Line 159, Address: 0x101aff4 */
      return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 160, Address: 0x101b00c */
    else
      return 0; /* Line 162, Address: 0x101b034 */
  }

  if (iColiData > 16) { /* Line 165, Address: 0x101b040 */
    return 0; /* Line 166, Address: 0x101b054 */
  }

  return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 169, Address: 0x101b060 */

} /* Line 171, Address: 0x101b080 */





















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5) { /* Line 193, Address: 0x101b0a0 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 197, Address: 0x101b0c8 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 199, Address: 0x101b0f4 */
  bCarry = CCset(iYwork, iYposi); /* Line 200, Address: 0x101b120 */
  iYwork = iYwork - iYposi; /* Line 201, Address: 0x101b144 */
  if (bCarry == 1) { /* Line 202, Address: 0x101b16c */

    iColiData += iColiData; /* Line 204, Address: 0x101b184 */
    bCarry = CSset(iColiData, iYwork); /* Line 205, Address: 0x101b190 */
    iColiData += iYwork; /* Line 206, Address: 0x101b1a8 */
    if (bCarry == 1) /* Line 207, Address: 0x101b1b4 */
      return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 208, Address: 0x101b1cc */
    else
      return 0; /* Line 210, Address: 0x101b1f0 */
  }


  if (iYwork > iD5) { /* Line 214, Address: 0x101b1fc */
    return 0; /* Line 215, Address: 0x101b21c */
  }

  return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 218, Address: 0x101b228 */

} /* Line 220, Address: 0x101b244 */
























short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 245, Address: 0x101b260 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 246, Address: 0x101b280 */

  if (iColino == 0) { /* Line 248, Address: 0x101b298 */

    pcolnomal(pActwk, pColliAct); /* Line 250, Address: 0x101b2a4 */
    return 1; /* Line 251, Address: 0x101b2b4 */
  }
  if (iColino == 192) { /* Line 253, Address: 0x101b2c0 */

    pcolspecial(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 255, Address: 0x101b2d0 */
    return 1; /* Line 256, Address: 0x101b2ec */
  }
  if ((char)iColino < 0) { /* Line 258, Address: 0x101b2f8 */

    if (plpower_m) { /* Line 260, Address: 0x101b310 */

      return 0; /* Line 262, Address: 0x101b320 */
    }
    pcolplay(pActwk, pColliAct); /* Line 264, Address: 0x101b32c */
    return 1; /* Line 265, Address: 0x101b33c */
  }


  return pcolitem(pActwk, pColliAct); /* Line 269, Address: 0x101b348 */

} /* Line 271, Address: 0x101b358 */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 286, Address: 0x101b370 */
  short iD0;

  if ((prio_flag && !pColliAct->userflag.b.l) || (!prio_flag && pColliAct->userflag.b.l)) { /* Line 289, Address: 0x101b384 */

    return -1; /* Line 291, Address: 0x101b3c4 */
  }


  if ((pColliAct->colino & 63) != 6) { /* Line 295, Address: 0x101b3d0 */


    if (((unsigned short*)pActwk)[26] < 90) /* Line 298, Address: 0x101b3ec */
      pColliAct->r_no0 += 2; /* Line 299, Address: 0x101b404 */
  } /* Line 300, Address: 0x101b414 */
  else {


    if (pActwk->yspeed.w < 0) { /* Line 304, Address: 0x101b41c */

      iD0 = pActwk->yposi.w.h - 16; /* Line 306, Address: 0x101b434 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 307, Address: 0x101b458 */
      if (bCarry == 0) { /* Line 308, Address: 0x101b480 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 310, Address: 0x101b494 */
        pColliAct->yspeed.w = -384; /* Line 311, Address: 0x101b4b8 */
        if (pColliAct->r_no1 == 0) /* Line 312, Address: 0x101b4c4 */
          pColliAct->r_no1 += 4; /* Line 313, Address: 0x101b4d8 */
      }
    } /* Line 315, Address: 0x101b4e8 */
    else {


      if (pActwk->mstno.b.h == 2) { /* Line 319, Address: 0x101b4f0 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 321, Address: 0x101b50c */
        pColliAct->r_no0 += 2; /* Line 322, Address: 0x101b530 */
      }
    }
  }
  return -1; /* Line 326, Address: 0x101b540 */
} /* Line 327, Address: 0x101b544 */















short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 343, Address: 0x101b560 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) { /* Line 347, Address: 0x101b578 */



    pcolplay(pActwk, pColliAct); /* Line 351, Address: 0x101b5bc */
    return -1; /* Line 352, Address: 0x101b5cc */
  }


  if (pColliAct->colicnt != 0) { /* Line 356, Address: 0x101b5d8 */

    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 358, Address: 0x101b5ec */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 359, Address: 0x101b610 */
    pActwk->xspeed.w /= 2; /* Line 360, Address: 0x101b634 */
    pActwk->yspeed.w /= 2; /* Line 361, Address: 0x101b658 */
    pColliAct->colino = 0; /* Line 362, Address: 0x101b67c */
    --pColliAct->colicnt; /* Line 363, Address: 0x101b684 */
    if (pColliAct->colicnt == 0) /* Line 364, Address: 0x101b694 */
      pColliAct->cddat |= 128; /* Line 365, Address: 0x101b6a8 */
  } /* Line 366, Address: 0x101b6b8 */
  else {


    pColliAct->cddat |= 128; /* Line 370, Address: 0x101b6c0 */
    iScoreCntwk = emyscorecnt; /* Line 371, Address: 0x101b6d0 */
    emyscorecnt += 2; /* Line 372, Address: 0x101b6e0 */
    if ((unsigned short)iScoreCntwk >= 6) { /* Line 373, Address: 0x101b6f4 */
      iScoreCntwk = 6; /* Line 374, Address: 0x101b708 */
    }
    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 376, Address: 0x101b714 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 377, Address: 0x101b71c */
    if ((unsigned short)emyscorecnt >= 32) { /* Line 378, Address: 0x101b758 */

      iScoreData = 1000; /* Line 380, Address: 0x101b774 */
      ((short*)pColliAct)[33] = 10; /* Line 381, Address: 0x101b780 */
    }

    scoreup(iScoreData); /* Line 384, Address: 0x101b78c */
    soundset(150); /* Line 385, Address: 0x101b79c */
    pColliAct->actno = 24; /* Line 386, Address: 0x101b7a8 */
    pColliAct->r_no0 = 0; /* Line 387, Address: 0x101b7b4 */
    pColliAct->userflag.b.h = 1; /* Line 388, Address: 0x101b7bc */

    if (pActwk->yspeed.w >= 0) { /* Line 390, Address: 0x101b7c8 */

      if (pColliAct->yposi.w.h > pActwk->yposi.w.h) /* Line 392, Address: 0x101b7e0 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 393, Address: 0x101b80c */
      else
        pActwk->yspeed.w -= 256; /* Line 395, Address: 0x101b838 */
    } /* Line 396, Address: 0x101b848 */
    else
      pActwk->yspeed.w += 256; /* Line 398, Address: 0x101b850 */
  }
  return -1; /* Line 400, Address: 0x101b860 */
} /* Line 401, Address: 0x101b864 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 417, Address: 0x101b880 */
  pColliAct->cddat |= 128; /* Line 418, Address: 0x101b890 */
  pcolplay(pActwk, pColliAct); /* Line 419, Address: 0x101b8a0 */
} /* Line 420, Address: 0x101b8b0 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 435, Address: 0x101b8c0 */
  if ((pActwk->actfree[2] & 1) || plpower_a || plpower_m) { /* Line 436, Address: 0x101b8d0 */

    return -1; /* Line 438, Address: 0x101b908 */
  }
  return pcole(pActwk, pColliAct); /* Line 440, Address: 0x101b914 */

} /* Line 442, Address: 0x101b924 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 457, Address: 0x101b940 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 458, Address: 0x101b950 */
    return -1; /* Line 459, Address: 0x101b964 */
  else
    return playdamageset(pActwk, pColliAct); /* Line 461, Address: 0x101b970 */
} /* Line 462, Address: 0x101b980 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 477, Address: 0x101b990 */


  pActwk->actfree[0] = 0; /* Line 480, Address: 0x101b9a0 */
  if (!(plpower_b & 1)) /* Line 481, Address: 0x101b9a8 */
    conbine_flag = 0; /* Line 482, Address: 0x101b9c0 */
  plpower_b &= 254; /* Line 483, Address: 0x101b9c8 */

  pActwk->r_no0 = 4; /* Line 485, Address: 0x101b9dc */
  jumpcolsub(); /* Line 486, Address: 0x101b9e8 */
  pActwk->cddat |= 2; /* Line 487, Address: 0x101b9f0 */
  if (pActwk->cddat & 64) { /* Line 488, Address: 0x101ba00 */

    pActwk->yspeed.w = -512; /* Line 490, Address: 0x101ba18 */
    pActwk->xspeed.w = -256; /* Line 491, Address: 0x101ba24 */
  } /* Line 492, Address: 0x101ba30 */
  else {

    pActwk->yspeed.w = -1024; /* Line 495, Address: 0x101ba38 */
    pActwk->xspeed.w = -512; /* Line 496, Address: 0x101ba44 */
  }

  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) { /* Line 499, Address: 0x101ba50 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 500, Address: 0x101ba7c */
  }
  pActwk->mspeed.w = 0; /* Line 502, Address: 0x101baa0 */
  pActwk->mstno.b.h = 26; /* Line 503, Address: 0x101baa8 */
  ((short*)pActwk)[26] = 120; /* Line 504, Address: 0x101bab4 */
} /* Line 505, Address: 0x101bac0 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 520, Address: 0x101bad0 */
  sprite_status* pFreeAct;
  short iRet;

  if (plpower_b != 0) { /* Line 524, Address: 0x101bae4 */

    playdamagechk(pActwk, pColliAct); /* Line 526, Address: 0x101baf8 */
    return -1; /* Line 527, Address: 0x101bb08 */
  }
  if (plring != 0) { /* Line 529, Address: 0x101bb14 */

    iRet = actwkchk(&pFreeAct); /* Line 531, Address: 0x101bb2c */
    if (iRet == 0) { /* Line 532, Address: 0x101bb40 */

      pFreeAct->actno = 17; /* Line 534, Address: 0x101bb50 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 535, Address: 0x101bb5c */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 536, Address: 0x101bb6c */

      if (prio_flag) { /* Line 538, Address: 0x101bb7c */
        pFreeAct->userflag.b.l = 1; /* Line 539, Address: 0x101bb8c */
      }
    }



    playdamagechk(pActwk, pColliAct); /* Line 545, Address: 0x101bb98 */
    return -1; /* Line 546, Address: 0x101bba8 */
  }

  if (debugflag.w != 0) { /* Line 549, Address: 0x101bbb4 */

    playdamagechk(pActwk, pColliAct); /* Line 551, Address: 0x101bbcc */
    return -1; /* Line 552, Address: 0x101bbdc */
  }
  playdieset(pActwk); /* Line 554, Address: 0x101bbe8 */
} /* Line 555, Address: 0x101bbf4 */












short playdieset(sprite_status* pActwk) { /* Line 568, Address: 0x101bc10 */
  if (editmode.w != 0) /* Line 569, Address: 0x101bc1c */
    return -1; /* Line 570, Address: 0x101bc34 */
  plpower_m = 0; /* Line 571, Address: 0x101bc40 */
  pActwk->r_no0 = 6; /* Line 572, Address: 0x101bc48 */
  jumpcolsub(); /* Line 573, Address: 0x101bc54 */
  pActwk->cddat |= 2; /* Line 574, Address: 0x101bc5c */
  pActwk->yspeed.w = -1792; /* Line 575, Address: 0x101bc6c */
  pActwk->xspeed.w = 0; /* Line 576, Address: 0x101bc78 */
  pActwk->mspeed.w = 0; /* Line 577, Address: 0x101bc80 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 578, Address: 0x101bc88 */
  pActwk->mstno.b.h = 24; /* Line 579, Address: 0x101bc98 */
  pActwk->sproffset |= 32768; /* Line 580, Address: 0x101bca4 */
  pActwk->sprpri = 0; /* Line 581, Address: 0x101bcb4 */
  soundset(147); /* Line 582, Address: 0x101bcbc */
  return -1; /* Line 583, Address: 0x101bcc8 */
} /* Line 584, Address: 0x101bccc */



















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 604, Address: 0x101bce0 */
  unsigned char flgwk;
  char cColiNo = pColliAct->colino & 63; /* Line 606, Address: 0x101bcf8 */

  switch (cColiNo) { /* Line 608, Address: 0x101bd18 */

    case 45:
      if (!(pActwk->cddat & 4)) { /* Line 611, Address: 0x101bd7c */
        pcolnomal(pActwk, pColliAct); /* Line 612, Address: 0x101bd94 */
        break; /* Line 613, Address: 0x101bda4 */
      }




    case 23:
    case 31:
    case 35:
      ++pColliAct->colicnt; /* Line 622, Address: 0x101bdac */
      break; /* Line 623, Address: 0x101bdbc */


    case 6:
      if (pActwk->yspeed.w < 0) { /* Line 627, Address: 0x101bdc4 */
        if (pActwk->yposi.w.h - 16 >= pColliAct->yposi.w.h) { /* Line 628, Address: 0x101bddc */
          pActwk->yspeed.w *= -1; /* Line 629, Address: 0x101be0c */
          pColliAct->yspeed.w = -384; /* Line 630, Address: 0x101be1c */

          if (!pColliAct->r_no1) { /* Line 632, Address: 0x101be28 */
            pColliAct->r_no1 += 4; /* Line 633, Address: 0x101be38 */
          }
        }


      } /* Line 638, Address: 0x101be48 */
      else {
        if (pActwk->mstno.b.h == 2) { /* Line 640, Address: 0x101be50 */
          pActwk->yspeed.w *= -1; /* Line 641, Address: 0x101be6c */
          pColliAct->r_no0 += 2; /* Line 642, Address: 0x101be7c */
        }
      }
      break; /* Line 645, Address: 0x101be8c */


    case 34:
      main_attack(pActwk, pColliAct); /* Line 649, Address: 0x101be94 */
      break; /* Line 650, Address: 0x101bea4 */


    case 48:
      if (pActwk->xposi.w.h - pColliAct->xposi.w.h < 0) { /* Line 654, Address: 0x101beac */
        flgwk = 255; /* Line 655, Address: 0x101bed8 */
      } else { /* Line 656, Address: 0x101bee0 */
        flgwk = 0; /* Line 657, Address: 0x101bee8 */
      }

      if (!((unsigned char)pColliAct->userflag.b.l ^ flgwk)) { /* Line 660, Address: 0x101beec */
        pcolnomal(pActwk, pColliAct); /* Line 661, Address: 0x101bf0c */
      } /* Line 662, Address: 0x101bf1c */
      else {
        ++pColliAct->colicnt; /* Line 664, Address: 0x101bf24 */
      }

      break; /* Line 667, Address: 0x101bf34 */

    default:
      switch (bossstart) { /* Line 670, Address: 0x101bf3c */
        case 0:
          break;

        case 4:
          if (cColiNo == 63) { /* Line 675, Address: 0x101bf7c */

            if (pActwk->cddat & 20) { /* Line 677, Address: 0x101bf90 */
              pActwk->cddat &= 235; /* Line 678, Address: 0x101bfa8 */
              pColliAct->colino = 0; /* Line 679, Address: 0x101bfb8 */


              pActwk->mstno.b.h = 21; /* Line 682, Address: 0x101bfc0 */
              pActwk->yspeed.w = 1024; /* Line 683, Address: 0x101bfcc */
              if (pActwk->xposi.w.h < pColliAct->xposi.w.h) { /* Line 684, Address: 0x101bfd8 */
                pActwk->xspeed.w = -512; /* Line 685, Address: 0x101c004 */
              } else { /* Line 686, Address: 0x101c010 */
                pActwk->xspeed.w = 512; /* Line 687, Address: 0x101c018 */
              }
            } else { /* Line 689, Address: 0x101c024 */
              return -1; /* Line 690, Address: 0x101c02c */
            }
          } else if (cColiNo == 62) { /* Line 692, Address: 0x101c038 */

            pcolplay(pActwk, pColliAct); /* Line 694, Address: 0x101c04c */


            ++pColliAct->colicnt; /* Line 697, Address: 0x101c05c */
          } else { /* Line 698, Address: 0x101c06c */
            return -1; /* Line 699, Address: 0x101c074 */
          }
          break;


        case 5:
          if (cColiNo == 61) { /* Line 705, Address: 0x101c080 */

            pcolplay(pActwk, pColliAct); /* Line 707, Address: 0x101c094 */


            ++pColliAct->colicnt; /* Line 710, Address: 0x101c0a4 */
          } else { /* Line 711, Address: 0x101c0b4 */
            return -1; /* Line 712, Address: 0x101c0bc */
          }
          break;


        case 1:
        default:
          if (cColiNo < 60 || cColiNo > 63) { /* Line 719, Address: 0x101c0c8 */
            return -1; /* Line 720, Address: 0x101c0f0 */
          }

          pcolnomal(pActwk, pColliAct); /* Line 723, Address: 0x101c0fc */
          if (pColliAct->colino == 0) { /* Line 724, Address: 0x101c10c */
            pColliAct->colicnt += 3; /* Line 725, Address: 0x101c120 */
          }


          pColliAct->colino = 0; /* Line 729, Address: 0x101c130 */


          ++pColliAct->colicnt; /* Line 732, Address: 0x101c138 */
          break;
      }
  }

  return -1; /* Line 737, Address: 0x101c148 */
} /* Line 738, Address: 0x101c14c */














short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 753, Address: 0x101c170 */
  if (bossstart != 1) return -1; /* Line 754, Address: 0x101c180 */
  pcolnomal(pActwk, pColliAct); /* Line 755, Address: 0x101c1a4 */
  if (pColliAct->colino == 0) pColliAct->colicnt += 3; /* Line 756, Address: 0x101c1b4 */
  pColliAct->colino = 0; /* Line 757, Address: 0x101c1d8 */
  ++pColliAct->colicnt; /* Line 758, Address: 0x101c1e0 */
  return 1; /* Line 759, Address: 0x101c1f0 */
} /* Line 760, Address: 0x101c1f4 */



















short yago(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 780, Address: 0x101c210 */
  iD5 -= iChkPosi; /* Line 781, Address: 0x101c22c */
  if (iD5 >= 8) /* Line 782, Address: 0x101c23c */
    return pcolnomal(pActwk, pColliAct); /* Line 783, Address: 0x101c254 */
  iChkPosi = pColliAct->xposi.w.h - 4; /* Line 784, Address: 0x101c26c */
  if (pColliAct->cddat & 1) /* Line 785, Address: 0x101c28c */
    iChkPosi -= 16; /* Line 786, Address: 0x101c2a4 */

  bCarry = CCset(iChkPosi, iXposi); /* Line 788, Address: 0x101c2b0 */
  iChkPosi -= iXposi; /* Line 789, Address: 0x101c2d8 */
  if (bCarry == 1) /* Line 790, Address: 0x101c2e8 */
  {
    bCarry = CSset(iChkPosi, 24); /* Line 792, Address: 0x101c300 */
    iChkPosi += 24; /* Line 793, Address: 0x101c31c */
    if (bCarry == 1) /* Line 794, Address: 0x101c328 */
      return pcolplay(pActwk, pColliAct); /* Line 795, Address: 0x101c340 */
    else
      return pcolnomal(pActwk, pColliAct); /* Line 797, Address: 0x101c358 */
  }

  if ((unsigned short)iChkPosi >= 16) /* Line 800, Address: 0x101c370 */
    return pcolplay(pActwk, pColliAct); /* Line 801, Address: 0x101c388 */
  else
    return pcolnomal(pActwk, pColliAct); /* Line 803, Address: 0x101c3a0 */
} /* Line 804, Address: 0x101c3b0 */














short main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 819, Address: 0x101c3c0 */
  if (pActwk->mstno.b.h == 2) /* Line 820, Address: 0x101c3cc */
    ++pColliAct->colicnt; /* Line 821, Address: 0x101c3e8 */
  return 1; /* Line 822, Address: 0x101c3f8 */
} /* Line 823, Address: 0x101c3fc */
