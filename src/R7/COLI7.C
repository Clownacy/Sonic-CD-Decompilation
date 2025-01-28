#include "..\EQU.H"
#include "COLI7.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYER.H"
#include "..\SCORE.H"

extern short actwkchk(sprite_status** ppActwk);

static unsigned char bCarry;
unsigned char colitbl[64][2] = {
  {  20,  20 }, {  18,  12 },
  {  12,  16 }, {   4,  16 },
  {  12,  18 }, {  16,  16 },
  {   6,   6 }, {  24,  12 },
  {  12,  16 }, {  16,  12 },
  {   8,   8 }, {  20,  16 },
  {  20,   8 }, {  14,  14 },
  {  24,  24 }, {  40,  16 },
  {  16,  24 }, {   8,  16 },
  {  32, 112 }, {  64,  32 },
  { 128,  32 }, {  32,  32 },
  {   8,   8 }, {   4,   4 },
  {  32,   8 }, {  12,  12 },
  {   8,   4 }, {  24,   4 },
  {  40,   4 }, {   4,   8 },
  {   4,  24 }, {   4,  40 },
  {   4,  32 }, {  24,  24 },
  {  12,  24 }, {  72,   8 },
  {   8,  12 }, {  16,   8 },
  {  32,  16 }, {  32,  16 },
  {  40,   4 }, {   0,   0 },
  {   0,   0 }, {  16,   9 },
  {  16,  16 }, {   0,   0 },
  {  16,  16 }, {  12,  12 },
  {   5,   5 }, {  16,   8 },
  {   8,  16 }, {   8,   8 },
  {  12,  12 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {  40,  36 },
  {  18,  17 }, {  24,  12 },
  {  20,  20 }, {   8,  16 },
  {   0,   0 }, {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };































short pcol(sprite_status* pActwk) { /* Line 77, Address: 0x101cb00 */
  short iXwork = pActwk->xposi.w.h, /* Line 78, Address: 0x101cb2c */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 81, Address: 0x101cb6c */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  iXwork -= 8; /* Line 85, Address: 0x101cb78 */
  iYwork -= iSprvs; /* Line 86, Address: 0x101cb84 */

  if (pActwk->patno == 57) { /* Line 88, Address: 0x101cb90 */

    iYwork += 12; /* Line 90, Address: 0x101cba8 */
    iSprvs = 10; /* Line 91, Address: 0x101cbb4 */
  }

  iXcollichk = 16; /* Line 94, Address: 0x101cbc0 */
  iSprvs += iSprvs; /* Line 95, Address: 0x101cbcc */

  pColliAct = &actwk[32]; /* Line 97, Address: 0x101cbd8 */

  for (i = 0; i < 96; ++i, ++pColliAct) { /* Line 99, Address: 0x101cbe0 */


    if (pColliAct->actflg & 128) { /* Line 102, Address: 0x101cbec */

      iColino = pColliAct->colino; /* Line 104, Address: 0x101cc00 */
      if (iColino != 0) { /* Line 105, Address: 0x101cc10 */

        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 107, Address: 0x101cc20 */
        if (iRet == -1) /* Line 108, Address: 0x101cc44 */
          return iRet; /* Line 109, Address: 0x101cc58 */
      }
    }
  } /* Line 112, Address: 0x101cc64 */
  iColino = 0; /* Line 113, Address: 0x101cc88 */
  return iColino; /* Line 114, Address: 0x101cc8c */
} /* Line 115, Address: 0x101cc90 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 135, Address: 0x101ccc0 */
  short iColiNo = pColliAct->colino; /* Line 136, Address: 0x101cce8 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 140, Address: 0x101ccfc */
  iColiwk = colitbl[iColiNo][0]; /* Line 141, Address: 0x101cd1c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 143, Address: 0x101cd44 */
  bCarry = CCset(iColiData, iXposi); /* Line 144, Address: 0x101cd70 */
  iColiData = iColiData - iXposi; /* Line 145, Address: 0x101cd94 */

  if (bCarry == 1) { /* Line 147, Address: 0x101cdbc */

    iColiwk += iColiwk; /* Line 149, Address: 0x101cdd4 */
    bCarry = CSset(iColiData, iColiwk); /* Line 150, Address: 0x101cde0 */
    iColiData += iColiwk; /* Line 151, Address: 0x101cdf8 */
    if (bCarry == 1) /* Line 152, Address: 0x101ce04 */
      return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 153, Address: 0x101ce1c */
    else
      return 0; /* Line 155, Address: 0x101ce44 */
  }

  if (iColiData > 16) { /* Line 158, Address: 0x101ce50 */
    return 0; /* Line 159, Address: 0x101ce64 */
  }

  return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 162, Address: 0x101ce70 */

} /* Line 164, Address: 0x101ce90 */





















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5) { /* Line 186, Address: 0x101ceb0 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 190, Address: 0x101ced8 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 192, Address: 0x101cf04 */
  bCarry = CCset(iYwork, iYposi); /* Line 193, Address: 0x101cf30 */
  iYwork = iYwork - iYposi; /* Line 194, Address: 0x101cf54 */
  if (bCarry == 1) { /* Line 195, Address: 0x101cf7c */

    iColiData += iColiData; /* Line 197, Address: 0x101cf94 */
    bCarry = CSset(iColiData, iYwork); /* Line 198, Address: 0x101cfa0 */
    iColiData += iYwork; /* Line 199, Address: 0x101cfb8 */
    if (bCarry == 1) /* Line 200, Address: 0x101cfc4 */
      return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 201, Address: 0x101cfdc */
    else
      return 0; /* Line 203, Address: 0x101d000 */
  }


  if (iYwork > iD5) { /* Line 207, Address: 0x101d00c */
    return 0; /* Line 208, Address: 0x101d02c */
  }

  return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 211, Address: 0x101d038 */

} /* Line 213, Address: 0x101d054 */
























short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 238, Address: 0x101d070 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 239, Address: 0x101d090 */

  if (iColino == 0) { /* Line 241, Address: 0x101d0a8 */

    pcolnomal(pActwk, pColliAct); /* Line 243, Address: 0x101d0b4 */
    return 1; /* Line 244, Address: 0x101d0c4 */
  }
  if (iColino == 192) { /* Line 246, Address: 0x101d0d0 */

    pcolspecial(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 248, Address: 0x101d0e0 */
    return 1; /* Line 249, Address: 0x101d0fc */
  }
  if ((char)iColino < 0) { /* Line 251, Address: 0x101d108 */

    pcolplay(pActwk, pColliAct); /* Line 253, Address: 0x101d120 */
    return 1; /* Line 254, Address: 0x101d130 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 258, Address: 0x101d13c */

} /* Line 260, Address: 0x101d14c */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 275, Address: 0x101d160 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) { /* Line 278, Address: 0x101d174 */


    if (((unsigned short*)pActwk)[26] < 90) /* Line 281, Address: 0x101d190 */
      pColliAct->r_no0 += 2; /* Line 282, Address: 0x101d1a8 */
  } /* Line 283, Address: 0x101d1b8 */
  else {


    if (pActwk->yspeed.w < 0) { /* Line 287, Address: 0x101d1c0 */

      iD0 = pActwk->yposi.w.h - 16; /* Line 289, Address: 0x101d1d8 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 290, Address: 0x101d1fc */
      if (bCarry == 0) { /* Line 291, Address: 0x101d224 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 293, Address: 0x101d238 */
        pColliAct->yspeed.w = -384; /* Line 294, Address: 0x101d25c */
        if (pColliAct->r_no1 == 0) /* Line 295, Address: 0x101d268 */
          pColliAct->r_no1 += 4; /* Line 296, Address: 0x101d27c */
      }
    } /* Line 298, Address: 0x101d28c */
    else {


      if (pActwk->mstno.b.h == 2) { /* Line 302, Address: 0x101d294 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 304, Address: 0x101d2b0 */
        pColliAct->r_no0 += 2; /* Line 305, Address: 0x101d2d4 */
      }
    }
  }
  return -1; /* Line 309, Address: 0x101d2e4 */
} /* Line 310, Address: 0x101d2e8 */















short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 326, Address: 0x101d300 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) { /* Line 330, Address: 0x101d318 */



    pcolplay(pActwk, pColliAct); /* Line 334, Address: 0x101d35c */
    return -1; /* Line 335, Address: 0x101d36c */
  }


  if (pColliAct->colicnt != 0) { /* Line 339, Address: 0x101d378 */

    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 341, Address: 0x101d38c */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 342, Address: 0x101d3b0 */
    pActwk->xspeed.w /= 2; /* Line 343, Address: 0x101d3d4 */
    pActwk->yspeed.w /= 2; /* Line 344, Address: 0x101d3f8 */
    pColliAct->colino = 0; /* Line 345, Address: 0x101d41c */
    --pColliAct->colicnt; /* Line 346, Address: 0x101d424 */
    if (pColliAct->colicnt == 0) /* Line 347, Address: 0x101d434 */
      pColliAct->cddat |= 128; /* Line 348, Address: 0x101d448 */
  } /* Line 349, Address: 0x101d458 */
  else {


    pColliAct->cddat |= 128; /* Line 353, Address: 0x101d460 */
    iScoreCntwk = emyscorecnt; /* Line 354, Address: 0x101d470 */
    emyscorecnt += 2; /* Line 355, Address: 0x101d480 */
    if ((unsigned short)iScoreCntwk >= 6) { /* Line 356, Address: 0x101d494 */
      iScoreCntwk = 6; /* Line 357, Address: 0x101d4a8 */
    }
    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 359, Address: 0x101d4b4 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 360, Address: 0x101d4bc */
    if ((unsigned short)emyscorecnt >= 32) { /* Line 361, Address: 0x101d4f8 */

      iScoreData = 1000; /* Line 363, Address: 0x101d514 */
      ((short*)pColliAct)[33] = 10; /* Line 364, Address: 0x101d520 */
    }

    scoreup(iScoreData); /* Line 367, Address: 0x101d52c */
    soundset(150); /* Line 368, Address: 0x101d53c */
    pColliAct->actno = 24; /* Line 369, Address: 0x101d548 */
    pColliAct->r_no0 = 0; /* Line 370, Address: 0x101d554 */
    pColliAct->userflag.b.h = 1; /* Line 371, Address: 0x101d55c */

    if (pActwk->yspeed.w >= 0) { /* Line 373, Address: 0x101d568 */

      if (pColliAct->yposi.w.h > pActwk->yposi.w.h) /* Line 375, Address: 0x101d580 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 376, Address: 0x101d5ac */
      else
        pActwk->yspeed.w -= 256; /* Line 378, Address: 0x101d5d8 */
    } /* Line 379, Address: 0x101d5e8 */
    else
      pActwk->yspeed.w += 256; /* Line 381, Address: 0x101d5f0 */
  }
  return -1; /* Line 383, Address: 0x101d600 */
} /* Line 384, Address: 0x101d604 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 400, Address: 0x101d620 */
  pColliAct->cddat |= 128; /* Line 401, Address: 0x101d630 */
  return pcolplay(pActwk, pColliAct); /* Line 402, Address: 0x101d640 */
} /* Line 403, Address: 0x101d650 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 418, Address: 0x101d660 */
  if (plpower_m == 0) /* Line 419, Address: 0x101d670 */
    return pcole(pActwk, pColliAct); /* Line 420, Address: 0x101d684 */
  else
    return -1; /* Line 422, Address: 0x101d69c */
} /* Line 423, Address: 0x101d6a0 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 438, Address: 0x101d6b0 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 439, Address: 0x101d6c0 */
    return -1; /* Line 440, Address: 0x101d6d4 */
  else
    return playdamageset(pActwk, pColliAct); /* Line 442, Address: 0x101d6e0 */
} /* Line 443, Address: 0x101d6f0 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 458, Address: 0x101d700 */


  pActwk->actfree[0] = 0; /* Line 461, Address: 0x101d710 */
  if (!(plpower_b & 1)) /* Line 462, Address: 0x101d718 */
    conbine_flag = 0; /* Line 463, Address: 0x101d730 */
  plpower_b &= 254; /* Line 464, Address: 0x101d738 */

  pActwk->r_no0 = 4; /* Line 466, Address: 0x101d74c */
  jumpcolsub(); /* Line 467, Address: 0x101d758 */
  pActwk->cddat |= 2; /* Line 468, Address: 0x101d760 */
  if (pActwk->cddat & 64) { /* Line 469, Address: 0x101d770 */

    pActwk->yspeed.w = -512; /* Line 471, Address: 0x101d788 */
    pActwk->xspeed.w = -256; /* Line 472, Address: 0x101d794 */
  } /* Line 473, Address: 0x101d7a0 */
  else {

    pActwk->yspeed.w = -1024; /* Line 476, Address: 0x101d7a8 */
    pActwk->xspeed.w = -512; /* Line 477, Address: 0x101d7b4 */
  }

  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) { /* Line 480, Address: 0x101d7c0 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 481, Address: 0x101d7ec */
  }
  pActwk->mspeed.w = 0; /* Line 483, Address: 0x101d810 */
  pActwk->mstno.b.h = 26; /* Line 484, Address: 0x101d818 */
  ((short*)pActwk)[26] = 120; /* Line 485, Address: 0x101d824 */
} /* Line 486, Address: 0x101d830 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 501, Address: 0x101d840 */
  sprite_status* pFreeAct;
  short iRet;

  if (plpower_b != 0) { /* Line 505, Address: 0x101d854 */

    playdamagechk(pActwk, pColliAct); /* Line 507, Address: 0x101d868 */
    return -1; /* Line 508, Address: 0x101d878 */
  }
  if (plring != 0) { /* Line 510, Address: 0x101d884 */

    iRet = actwkchk(&pFreeAct); /* Line 512, Address: 0x101d89c */
    if (iRet == 0) { /* Line 513, Address: 0x101d8b0 */

      pFreeAct->actno = 17; /* Line 515, Address: 0x101d8c0 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 516, Address: 0x101d8cc */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 517, Address: 0x101d8dc */
    }

    playdamagechk(pActwk, pColliAct); /* Line 520, Address: 0x101d8ec */
    return -1; /* Line 521, Address: 0x101d8fc */
  }

  if (debugflag.w != 0) { /* Line 524, Address: 0x101d908 */

    playdamagechk(pActwk, pColliAct); /* Line 526, Address: 0x101d920 */
    return -1; /* Line 527, Address: 0x101d930 */
  }
  return playdieset(pActwk); /* Line 529, Address: 0x101d93c */
} /* Line 530, Address: 0x101d948 */












short playdieset(sprite_status* pActwk) { /* Line 543, Address: 0x101d960 */
  if (editmode.w != 0) /* Line 544, Address: 0x101d96c */
    return -1; /* Line 545, Address: 0x101d984 */
  plpower_m = 0; /* Line 546, Address: 0x101d990 */
  pActwk->r_no0 = 6; /* Line 547, Address: 0x101d998 */
  jumpcolsub(); /* Line 548, Address: 0x101d9a4 */
  pActwk->cddat |= 2; /* Line 549, Address: 0x101d9ac */
  pActwk->yspeed.w = -1792; /* Line 550, Address: 0x101d9bc */
  pActwk->xspeed.w = 0; /* Line 551, Address: 0x101d9c8 */
  pActwk->mspeed.w = 0; /* Line 552, Address: 0x101d9d0 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 553, Address: 0x101d9d8 */
  pActwk->mstno.b.h = 24; /* Line 554, Address: 0x101d9e8 */
  pActwk->sproffset |= 32768; /* Line 555, Address: 0x101d9f4 */
  pActwk->sprpri = 0; /* Line 556, Address: 0x101da04 */
  soundset(147); /* Line 557, Address: 0x101da0c */
  return -1; /* Line 558, Address: 0x101da18 */
} /* Line 559, Address: 0x101da1c */



















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 579, Address: 0x101da30 */
  char cColiNo = pColliAct->colino & 63; /* Line 580, Address: 0x101da44 */

  switch (cColiNo) { /* Line 582, Address: 0x101da64 */



    case 45:
    case 49:
      if (!(pActwk->cddat & 4)) { /* Line 588, Address: 0x101dac8 */
        pcolnomal(pActwk, pColliAct); /* Line 589, Address: 0x101dae0 */
        break; /* Line 590, Address: 0x101daf0 */
      }



    case 31:
    case 35:
      ++pColliAct->colicnt; /* Line 597, Address: 0x101daf8 */
      break; /* Line 598, Address: 0x101db08 */




    case 53:
    case 58:
    case 59:
      main_attack(pActwk, pColliAct); /* Line 606, Address: 0x101db10 */
      break; /* Line 607, Address: 0x101db20 */

    default:
      switch (bossstart) { /* Line 610, Address: 0x101db28 */
        case 0:
          return -1; /* Line 612, Address: 0x101db68 */


        case 1:
          if (cColiNo < 60 || cColiNo > 63) { /* Line 616, Address: 0x101db74 */
            return -1; /* Line 617, Address: 0x101db9c */
          }

          pcolnomal(pActwk, pColliAct); /* Line 620, Address: 0x101dba8 */
          if (pColliAct->colino == 0) { /* Line 621, Address: 0x101dbb8 */
            pColliAct->colicnt += 3; /* Line 622, Address: 0x101dbcc */
          }


          pColliAct->colino = 0; /* Line 626, Address: 0x101dbdc */


          ++pColliAct->colicnt; /* Line 629, Address: 0x101dbe4 */
          break; /* Line 630, Address: 0x101dbf4 */


        case 4:
          if (cColiNo == 63) { /* Line 634, Address: 0x101dbfc */

            if (pActwk->cddat & 20) { /* Line 636, Address: 0x101dc10 */
              pActwk->cddat &= 235; /* Line 637, Address: 0x101dc28 */
              pColliAct->colino = 0; /* Line 638, Address: 0x101dc38 */


              pActwk->mstno.b.h = 21; /* Line 641, Address: 0x101dc40 */
              pActwk->yspeed.w = 1024; /* Line 642, Address: 0x101dc4c */
              if (pActwk->xposi.w.h < pColliAct->xposi.w.h) { /* Line 643, Address: 0x101dc58 */
                pActwk->xspeed.w = -512; /* Line 644, Address: 0x101dc84 */
              } else { /* Line 645, Address: 0x101dc90 */
                pActwk->xspeed.w = 512; /* Line 646, Address: 0x101dc98 */
              }
            } else { /* Line 648, Address: 0x101dca4 */
              return -1; /* Line 649, Address: 0x101dcac */
            }
          } else if (cColiNo == 62) { /* Line 651, Address: 0x101dcb8 */

            pcolplay(pActwk, pColliAct); /* Line 653, Address: 0x101dccc */


            ++pColliAct->colicnt; /* Line 656, Address: 0x101dcdc */
          } else { /* Line 657, Address: 0x101dcec */
            return -1; /* Line 658, Address: 0x101dcf4 */
          }
          break;


        case 5:
          if (cColiNo == 61) { /* Line 664, Address: 0x101dd00 */

            pcolplay(pActwk, pColliAct); /* Line 666, Address: 0x101dd14 */


            ++pColliAct->colicnt; /* Line 669, Address: 0x101dd24 */
          } else { /* Line 670, Address: 0x101dd34 */
            return -1; /* Line 671, Address: 0x101dd3c */
          }
          break;
      }
  }


  return -1; /* Line 678, Address: 0x101dd48 */
} /* Line 679, Address: 0x101dd4c */














short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 694, Address: 0x101dd60 */
  if (bossstart != 1) return -1; /* Line 695, Address: 0x101dd70 */
  pcolnomal(pActwk, pColliAct); /* Line 696, Address: 0x101dd94 */
  if (pColliAct->colino == 0) pColliAct->colicnt += 3; /* Line 697, Address: 0x101dda4 */
  pColliAct->colino = 0; /* Line 698, Address: 0x101ddc8 */
  ++pColliAct->colicnt; /* Line 699, Address: 0x101ddd0 */
  return 1; /* Line 700, Address: 0x101dde0 */
} /* Line 701, Address: 0x101dde4 */



















short yago(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 721, Address: 0x101de00 */
  iD5 -= iChkPosi; /* Line 722, Address: 0x101de1c */
  if (iD5 >= 8) /* Line 723, Address: 0x101de2c */
    return pcolnomal(pActwk, pColliAct); /* Line 724, Address: 0x101de44 */
  iChkPosi = pColliAct->xposi.w.h - 4; /* Line 725, Address: 0x101de5c */
  if (pColliAct->cddat & 1) /* Line 726, Address: 0x101de7c */
    iChkPosi -= 16; /* Line 727, Address: 0x101de94 */

  bCarry = CCset(iChkPosi, iXposi); /* Line 729, Address: 0x101dea0 */
  iChkPosi -= iXposi; /* Line 730, Address: 0x101dec8 */
  if (bCarry == 1) /* Line 731, Address: 0x101ded8 */
  {
    bCarry = CSset(iChkPosi, 24); /* Line 733, Address: 0x101def0 */
    iChkPosi += 24; /* Line 734, Address: 0x101df0c */
    if (bCarry == 1) /* Line 735, Address: 0x101df18 */
      return pcolplay(pActwk, pColliAct); /* Line 736, Address: 0x101df30 */
    else
      return pcolnomal(pActwk, pColliAct); /* Line 738, Address: 0x101df48 */
  }

  if ((unsigned short)iChkPosi >= 16) /* Line 741, Address: 0x101df60 */
    return pcolplay(pActwk, pColliAct); /* Line 742, Address: 0x101df78 */
  else
    return pcolnomal(pActwk, pColliAct); /* Line 744, Address: 0x101df90 */
} /* Line 745, Address: 0x101dfa0 */














short main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 760, Address: 0x101dfb0 */
  if (pActwk->mstno.b.h == 2) /* Line 761, Address: 0x101dfbc */
    ++pColliAct->colicnt; /* Line 762, Address: 0x101dfd8 */
  return 1; /* Line 763, Address: 0x101dfe8 */
} /* Line 764, Address: 0x101dfec */
