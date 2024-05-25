#include "..\EQU.H"
#include "COLI5.H"
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
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {  23,  48 },
  {  16,  16 }, {  12,   5 },
  {  20,  16 }, {   3,   3 },
  {   8,   8 }, {   8,  12 },
  {  24,  24 }, {  24,  16 },
  {  12,   8 }, {  16,  16 },
  {   4,  16 }, {  40,  36 },
  {  18,  17 }, {  14,  24 },
  {   8,   8 }, {  32,  56 },
  {  30,  32 }, {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };































short pcol(sprite_status* pActwk) { /* Line 77, Address: 0x1016860 */
  short iXwork = pActwk->xposi.w.h, /* Line 78, Address: 0x101688c */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 81, Address: 0x10168cc */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  iXwork -= 8; /* Line 85, Address: 0x10168d8 */
  iYwork -= iSprvs; /* Line 86, Address: 0x10168e4 */

  if (pActwk->patno == 57) { /* Line 88, Address: 0x10168f0 */

    iYwork += 12; /* Line 90, Address: 0x1016908 */
    iSprvs = 10; /* Line 91, Address: 0x1016914 */
  }

  iXcollichk = 16; /* Line 94, Address: 0x1016920 */
  iSprvs += iSprvs; /* Line 95, Address: 0x101692c */

  pColliAct = &actwk[32]; /* Line 97, Address: 0x1016938 */

  for (i = 0; i < 96; ++i, ++pColliAct) { /* Line 99, Address: 0x1016940 */


    if (pColliAct->actflg & 128) { /* Line 102, Address: 0x101694c */

      iColino = pColliAct->colino; /* Line 104, Address: 0x1016960 */
      if (iColino != 0) { /* Line 105, Address: 0x1016970 */

        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 107, Address: 0x1016980 */
        if (iRet) /* Line 108, Address: 0x10169a4 */
          return iRet; /* Line 109, Address: 0x10169ac */
      }
    }
  } /* Line 112, Address: 0x10169b8 */
  iColino = 0; /* Line 113, Address: 0x10169dc */
  return iColino; /* Line 114, Address: 0x10169e0 */
} /* Line 115, Address: 0x10169e4 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 135, Address: 0x1016a20 */
  short iColiNo = pColliAct->colino; /* Line 136, Address: 0x1016a48 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 140, Address: 0x1016a5c */
  iColiwk = colitbl[iColiNo][0]; /* Line 141, Address: 0x1016a7c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 143, Address: 0x1016aa4 */
  bCarry = CCset(iColiData, iXposi); /* Line 144, Address: 0x1016ad0 */
  iColiData = iColiData - iXposi; /* Line 145, Address: 0x1016af4 */

  if (bCarry == 1) { /* Line 147, Address: 0x1016b1c */

    iColiwk += iColiwk; /* Line 149, Address: 0x1016b34 */
    bCarry = CSset(iColiData, iColiwk); /* Line 150, Address: 0x1016b40 */
    iColiData += iColiwk; /* Line 151, Address: 0x1016b58 */
    if (bCarry == 1) /* Line 152, Address: 0x1016b64 */
      return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 153, Address: 0x1016b7c */
    else
      return 0; /* Line 155, Address: 0x1016ba4 */
  }

  if (iColiData > 16) { /* Line 158, Address: 0x1016bb0 */
    return 0; /* Line 159, Address: 0x1016bc4 */
  }

  return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 162, Address: 0x1016bd0 */

} /* Line 164, Address: 0x1016bf0 */





















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5) { /* Line 186, Address: 0x1016c10 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 190, Address: 0x1016c38 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 192, Address: 0x1016c64 */
  bCarry = CCset(iYwork, iYposi); /* Line 193, Address: 0x1016c90 */
  iYwork = iYwork - iYposi; /* Line 194, Address: 0x1016cb4 */
  if (bCarry == 1) { /* Line 195, Address: 0x1016cdc */

    iColiData += iColiData; /* Line 197, Address: 0x1016cf4 */
    bCarry = CSset(iColiData, iYwork); /* Line 198, Address: 0x1016d00 */
    iColiData += iYwork; /* Line 199, Address: 0x1016d18 */
    if (bCarry == 1) /* Line 200, Address: 0x1016d24 */
      return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 201, Address: 0x1016d3c */
    else
      return 0; /* Line 203, Address: 0x1016d60 */
  }


  if (iYwork > iD5) { /* Line 207, Address: 0x1016d6c */
    return 0; /* Line 208, Address: 0x1016d8c */
  }

  return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 211, Address: 0x1016d98 */

} /* Line 213, Address: 0x1016db4 */
























short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 238, Address: 0x1016dd0 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 239, Address: 0x1016df0 */

  if (iColino == 0) { /* Line 241, Address: 0x1016e08 */

    pcolnomal(pActwk, pColliAct); /* Line 243, Address: 0x1016e14 */
    return 1; /* Line 244, Address: 0x1016e24 */
  }
  if (iColino == 192) { /* Line 246, Address: 0x1016e30 */

    pcolspecial(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 248, Address: 0x1016e40 */
    return 1; /* Line 249, Address: 0x1016e5c */
  }
  if ((char)iColino < 0) { /* Line 251, Address: 0x1016e68 */

    pcolplay(pActwk, pColliAct); /* Line 253, Address: 0x1016e80 */
    return 1; /* Line 254, Address: 0x1016e90 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 258, Address: 0x1016e9c */

} /* Line 260, Address: 0x1016eac */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 275, Address: 0x1016ec0 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) { /* Line 278, Address: 0x1016ed4 */


    if (((unsigned short*)pActwk)[26] < 90) /* Line 281, Address: 0x1016ef0 */
      pColliAct->r_no0 += 2; /* Line 282, Address: 0x1016f08 */
  } /* Line 283, Address: 0x1016f18 */
  else {


    if (pActwk->yspeed.w < 0) { /* Line 287, Address: 0x1016f20 */

      iD0 = pActwk->yposi.w.h - 16; /* Line 289, Address: 0x1016f38 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 290, Address: 0x1016f5c */
      if (bCarry == 0) { /* Line 291, Address: 0x1016f84 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 293, Address: 0x1016f98 */
        pColliAct->yspeed.w = -384; /* Line 294, Address: 0x1016fbc */
        if (pColliAct->r_no1 == 0) /* Line 295, Address: 0x1016fc8 */
          pColliAct->r_no1 += 4; /* Line 296, Address: 0x1016fdc */
      }
    } /* Line 298, Address: 0x1016fec */
    else {


      if (pActwk->mstno.b.h == 2) { /* Line 302, Address: 0x1016ff4 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 304, Address: 0x1017010 */
        pColliAct->r_no0 += 2; /* Line 305, Address: 0x1017034 */
      }
    }
  }
  return -1; /* Line 309, Address: 0x1017044 */
} /* Line 310, Address: 0x1017048 */















short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 326, Address: 0x1017060 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) { /* Line 330, Address: 0x1017078 */



    pcolplay(pActwk, pColliAct); /* Line 334, Address: 0x10170bc */
    return -1; /* Line 335, Address: 0x10170cc */
  }


  if (pColliAct->colicnt != 0) { /* Line 339, Address: 0x10170d8 */

    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 341, Address: 0x10170ec */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 342, Address: 0x1017110 */
    pActwk->xspeed.w /= 2; /* Line 343, Address: 0x1017134 */
    pActwk->yspeed.w /= 2; /* Line 344, Address: 0x1017158 */
    pColliAct->colino = 0; /* Line 345, Address: 0x101717c */
    --pColliAct->colicnt; /* Line 346, Address: 0x1017184 */
    if (pColliAct->colicnt == 0) /* Line 347, Address: 0x1017194 */
      pColliAct->cddat |= 128; /* Line 348, Address: 0x10171a8 */
  } /* Line 349, Address: 0x10171b8 */
  else {


    pColliAct->cddat |= 128; /* Line 353, Address: 0x10171c0 */
    iScoreCntwk = emyscorecnt; /* Line 354, Address: 0x10171d0 */
    emyscorecnt += 2; /* Line 355, Address: 0x10171e0 */
    if ((unsigned short)iScoreCntwk >= 6) { /* Line 356, Address: 0x10171f4 */
      iScoreCntwk = 6; /* Line 357, Address: 0x1017208 */
    }
    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 359, Address: 0x1017214 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 360, Address: 0x101721c */
    if ((unsigned short)emyscorecnt >= 32) { /* Line 361, Address: 0x1017258 */

      iScoreData = 1000; /* Line 363, Address: 0x1017274 */
      ((short*)pColliAct)[33] = 10; /* Line 364, Address: 0x1017280 */
    }

    scoreup(iScoreData); /* Line 367, Address: 0x101728c */
    soundset(150); /* Line 368, Address: 0x101729c */
    pColliAct->actno = 24; /* Line 369, Address: 0x10172a8 */
    pColliAct->r_no0 = 0; /* Line 370, Address: 0x10172b4 */
    pColliAct->userflag.b.h = 1; /* Line 371, Address: 0x10172bc */

    if (pActwk->yspeed.w >= 0) { /* Line 373, Address: 0x10172c8 */



      if (pColliAct->yposi.w.h > pActwk->yposi.w.h) /* Line 377, Address: 0x10172e0 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 378, Address: 0x101730c */
      else
        pActwk->yspeed.w -= 256; /* Line 380, Address: 0x1017338 */
    } /* Line 381, Address: 0x1017348 */
    else
      pActwk->yspeed.w += 256; /* Line 383, Address: 0x1017350 */
  }
  return -1; /* Line 385, Address: 0x1017360 */
} /* Line 386, Address: 0x1017364 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 402, Address: 0x1017380 */
  pColliAct->cddat |= 128; /* Line 403, Address: 0x1017390 */
  pcolplay(pActwk, pColliAct); /* Line 404, Address: 0x10173a0 */
} /* Line 405, Address: 0x10173b0 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 420, Address: 0x10173c0 */
  if (plpower_m == 0) /* Line 421, Address: 0x10173d0 */
    return pcole(pActwk, pColliAct); /* Line 422, Address: 0x10173e4 */
  else
    return -1; /* Line 424, Address: 0x10173fc */
} /* Line 425, Address: 0x1017400 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 440, Address: 0x1017410 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 441, Address: 0x1017420 */
    return -1; /* Line 442, Address: 0x1017434 */
  else
    return playdamageset(pActwk, pColliAct); /* Line 444, Address: 0x1017440 */
} /* Line 445, Address: 0x1017450 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 460, Address: 0x1017460 */


  pActwk->actfree[0] = 0; /* Line 463, Address: 0x1017470 */
  if (!(plpower_b & 1)) /* Line 464, Address: 0x1017478 */
    conbine_flag = 0; /* Line 465, Address: 0x1017490 */
  plpower_b &= 254; /* Line 466, Address: 0x1017498 */

  pActwk->r_no0 = 4; /* Line 468, Address: 0x10174ac */
  jumpcolsub(); /* Line 469, Address: 0x10174b8 */
  pActwk->cddat |= 2; /* Line 470, Address: 0x10174c0 */
  if (pActwk->cddat & 64) { /* Line 471, Address: 0x10174d0 */

    pActwk->yspeed.w = -512; /* Line 473, Address: 0x10174e8 */
    pActwk->xspeed.w = -256; /* Line 474, Address: 0x10174f4 */
  } /* Line 475, Address: 0x1017500 */
  else {

    pActwk->yspeed.w = -1024; /* Line 478, Address: 0x1017508 */
    pActwk->xspeed.w = -512; /* Line 479, Address: 0x1017514 */
  }

  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) { /* Line 482, Address: 0x1017520 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 483, Address: 0x101754c */
  }
  pActwk->mspeed.w = 0; /* Line 485, Address: 0x1017570 */
  pActwk->mstno.b.h = 26; /* Line 486, Address: 0x1017578 */
  ((short*)pActwk)[26] = 120; /* Line 487, Address: 0x1017584 */
} /* Line 488, Address: 0x1017590 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 503, Address: 0x10175a0 */
  sprite_status* pFreeAct;
  short iRet;

  if (plpower_b != 0) { /* Line 507, Address: 0x10175b4 */

    playdamagechk(pActwk, pColliAct); /* Line 509, Address: 0x10175c8 */
    return -1; /* Line 510, Address: 0x10175d8 */
  }
  if (plring != 0) { /* Line 512, Address: 0x10175e4 */

    iRet = actwkchk(&pFreeAct); /* Line 514, Address: 0x10175fc */
    if (iRet == 0) { /* Line 515, Address: 0x1017610 */

      pFreeAct->actno = 17; /* Line 517, Address: 0x1017620 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 518, Address: 0x101762c */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 519, Address: 0x101763c */
    }

    playdamagechk(pActwk, pColliAct); /* Line 522, Address: 0x101764c */
    return -1; /* Line 523, Address: 0x101765c */
  }

  if (debugflag.w != 0) { /* Line 526, Address: 0x1017668 */

    playdamagechk(pActwk, pColliAct); /* Line 528, Address: 0x1017680 */
    return -1; /* Line 529, Address: 0x1017690 */
  }
  playdieset(pActwk); /* Line 531, Address: 0x101769c */
} /* Line 532, Address: 0x10176a8 */












short playdieset(sprite_status* pActwk) { /* Line 545, Address: 0x10176c0 */
  if (editmode.w != 0) /* Line 546, Address: 0x10176cc */
    return -1; /* Line 547, Address: 0x10176e4 */
  plpower_m = 0; /* Line 548, Address: 0x10176f0 */
  pActwk->r_no0 = 6; /* Line 549, Address: 0x10176f8 */
  jumpcolsub(); /* Line 550, Address: 0x1017704 */
  pActwk->cddat |= 2; /* Line 551, Address: 0x101770c */
  pActwk->yspeed.w = -1792; /* Line 552, Address: 0x101771c */
  pActwk->xspeed.w = 0; /* Line 553, Address: 0x1017728 */
  pActwk->mspeed.w = 0; /* Line 554, Address: 0x1017730 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 555, Address: 0x1017738 */
  pActwk->mstno.b.h = 24; /* Line 556, Address: 0x1017748 */
  pActwk->sproffset |= 32768; /* Line 557, Address: 0x1017754 */
  pActwk->sprpri = 0; /* Line 558, Address: 0x1017764 */
  soundset(147); /* Line 559, Address: 0x101776c */
  return -1; /* Line 560, Address: 0x1017778 */
} /* Line 561, Address: 0x101777c */



















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 581, Address: 0x1017790 */
  char cColiNo = pColliAct->colino & 63; /* Line 582, Address: 0x10177a4 */

  switch (cColiNo) { /* Line 584, Address: 0x10177c4 */




    case 31:
    case 35:
    case 55:
      ++pColliAct->colicnt; /* Line 592, Address: 0x1017834 */
      goto label1; /* Line 593, Address: 0x1017844 */


    case 56:
      ++pColliAct->colicnt; /* Line 597, Address: 0x101784c */
      pcolplay(pActwk, pColliAct); /* Line 598, Address: 0x101785c */
      goto label1; /* Line 599, Address: 0x101786c */





    case 46:
    case 58:
    case 59:
    case 60:
      main_attack(pActwk, pColliAct); /* Line 609, Address: 0x1017874 */
      goto label1; /* Line 610, Address: 0x1017884 */
  }

  switch (bossstart) { /* Line 613, Address: 0x101788c */

    case 0: return -1; /* Line 615, Address: 0x10178cc */


    case 4:
      if (cColiNo == 63) { /* Line 619, Address: 0x10178d8 */

        if (pActwk->cddat & 20) { /* Line 621, Address: 0x10178ec */
          pActwk->cddat &= 235; /* Line 622, Address: 0x1017904 */
          pColliAct->colino = 0; /* Line 623, Address: 0x1017914 */


          pActwk->mstno.b.h = 21; /* Line 626, Address: 0x101791c */
          pActwk->yspeed.w = 1024; /* Line 627, Address: 0x1017928 */
          if (pActwk->xposi.w.h < pColliAct->xposi.w.h) { /* Line 628, Address: 0x1017934 */
            pActwk->xspeed.w = -512; /* Line 629, Address: 0x1017960 */
          } else { /* Line 630, Address: 0x101796c */
            pActwk->xspeed.w = 512; /* Line 631, Address: 0x1017974 */
          }
          break; /* Line 633, Address: 0x1017980 */
        } else return -1; /* Line 634, Address: 0x1017988 */
      }
      else if (cColiNo == 62) { /* Line 636, Address: 0x1017994 */

        pcolplay(pActwk, pColliAct); /* Line 638, Address: 0x10179a8 */


        ++pColliAct->colicnt; /* Line 641, Address: 0x10179b8 */
      } /* Line 642, Address: 0x10179c8 */
      else return -1; /* Line 643, Address: 0x10179d0 */
      break;



    case 5:
      if (cColiNo == 61) { /* Line 649, Address: 0x10179dc */

        pcolplay(pActwk, pColliAct); /* Line 651, Address: 0x10179f0 */


        ++pColliAct->colicnt; /* Line 654, Address: 0x1017a00 */
      } /* Line 655, Address: 0x1017a10 */
      else return -1; /* Line 656, Address: 0x1017a18 */
      break;




    case 1:
    default:
      if (cColiNo >= 60 && cColiNo > 63) { /* Line 664, Address: 0x1017a24 */
        return -1; /* Line 665, Address: 0x1017a4c */
      }

      pcolnomal(pActwk, pColliAct); /* Line 668, Address: 0x1017a58 */
      if (pColliAct->colino == 0) /* Line 669, Address: 0x1017a68 */
        pColliAct->colicnt += 3; /* Line 670, Address: 0x1017a7c */



        pColliAct->colino = 0; /* Line 674, Address: 0x1017a8c */


        ++pColliAct->colicnt; /* Line 677, Address: 0x1017a94 */
      break;
  }

label1:
  return -1; /* Line 682, Address: 0x1017aa4 */
} /* Line 683, Address: 0x1017aa8 */














short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 698, Address: 0x1017ac0 */
  if (bossstart != 1) return -1; /* Line 699, Address: 0x1017ad0 */
  pcolnomal(pActwk, pColliAct); /* Line 700, Address: 0x1017af4 */
  if (pColliAct->colino == 0) pColliAct->colicnt += 3; /* Line 701, Address: 0x1017b04 */
  pColliAct->colino = 0; /* Line 702, Address: 0x1017b28 */
  ++pColliAct->colicnt; /* Line 703, Address: 0x1017b30 */
  return 1; /* Line 704, Address: 0x1017b40 */
} /* Line 705, Address: 0x1017b44 */



















short yago(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 725, Address: 0x1017b60 */
  iD5 -= iChkPosi; /* Line 726, Address: 0x1017b7c */
  if (iD5 >= 8) /* Line 727, Address: 0x1017b8c */
    return pcolnomal(pActwk, pColliAct); /* Line 728, Address: 0x1017ba4 */
  iChkPosi = pColliAct->xposi.w.h - 4; /* Line 729, Address: 0x1017bbc */
  if (pColliAct->cddat & 1) /* Line 730, Address: 0x1017bdc */
    iChkPosi -= 16; /* Line 731, Address: 0x1017bf4 */

  bCarry = CCset(iChkPosi, iXposi); /* Line 733, Address: 0x1017c00 */
  iChkPosi -= iXposi; /* Line 734, Address: 0x1017c28 */
  if (bCarry == 1) /* Line 735, Address: 0x1017c38 */
  {
    bCarry = CSset(iChkPosi, 24); /* Line 737, Address: 0x1017c50 */
    iChkPosi += 24; /* Line 738, Address: 0x1017c6c */
    if (bCarry == 1) /* Line 739, Address: 0x1017c78 */
      return pcolplay(pActwk, pColliAct); /* Line 740, Address: 0x1017c90 */
    else
      return pcolnomal(pActwk, pColliAct); /* Line 742, Address: 0x1017ca8 */
  }

  if ((unsigned short)iChkPosi >= 16) /* Line 745, Address: 0x1017cc0 */
    return pcolplay(pActwk, pColliAct); /* Line 746, Address: 0x1017cd8 */
  else
    return pcolnomal(pActwk, pColliAct); /* Line 748, Address: 0x1017cf0 */
} /* Line 749, Address: 0x1017d00 */














short main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 764, Address: 0x1017d10 */
  if (pActwk->mstno.b.h == 2) /* Line 765, Address: 0x1017d1c */
    ++pColliAct->colicnt; /* Line 766, Address: 0x1017d38 */
  return 1; /* Line 767, Address: 0x1017d48 */
} /* Line 768, Address: 0x1017d4c */
