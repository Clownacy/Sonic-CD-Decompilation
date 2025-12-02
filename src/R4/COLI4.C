#include "..\EQU.H"
#include "COLI4.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYER.H"
#include "..\SCORE.H"
#include "PLAYSUB4.H"

extern short actwkchk(sprite_status** ppActwk);

static unsigned char bCarry;
unsigned char colitbl[64][2] =
{
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
  {  12,  12 }, {   0,   0 },
  {   0,   0 }, {  24,   8 },
  {  20,   8 }, {   2,   2 },
  {  24,  12 }, {  14,  19 },
  {  12,   8 }, {   4,   4 },
  {  22,  18 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {  40,  36 },
  {  18,  17 }, {  32,  20 },
  {  32,  24 }, {   3,   3 },
  {   4,   4 }, {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };


























short pcol(sprite_status* pActwk) { /* Line 74, Address: 0x1015640 */
  short iXwork = pActwk->xposi.w.h, /* Line 75, Address: 0x101566c */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 78, Address: 0x10156ac */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  iXwork -= 8; /* Line 82, Address: 0x10156b8 */
  iYwork -= iSprvs; /* Line 83, Address: 0x10156c4 */

  if (pActwk->patno == 57) /* Line 85, Address: 0x10156d0 */
  {
    iYwork += 12; /* Line 87, Address: 0x10156e8 */
    iSprvs = 10; /* Line 88, Address: 0x10156f4 */
  }

  iXcollichk = 16; /* Line 91, Address: 0x1015700 */
  iSprvs += iSprvs; /* Line 92, Address: 0x101570c */

  pColliAct = &actwk[32]; /* Line 94, Address: 0x1015718 */

  for (i = 0; i < 96; ++i, ++pColliAct) /* Line 96, Address: 0x1015720 */
  {

    if (pColliAct->actflg & 128) /* Line 99, Address: 0x101572c */
    {
      iColino = pColliAct->colino; /* Line 101, Address: 0x1015740 */
      if (iColino != 0) /* Line 102, Address: 0x1015750 */
      {
        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 104, Address: 0x1015760 */
        if (iRet == -1) /* Line 105, Address: 0x1015784 */
          return iRet; /* Line 106, Address: 0x1015798 */
      }
    }
  } /* Line 109, Address: 0x10157a4 */
  iColino = 0; /* Line 110, Address: 0x10157c8 */
  return iColino; /* Line 111, Address: 0x10157cc */
} /* Line 112, Address: 0x10157d0 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 132, Address: 0x1015800 */
  short iColiNo = pColliAct->colino; /* Line 133, Address: 0x1015828 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 137, Address: 0x101583c */
  iColiwk = colitbl[iColiNo][0]; /* Line 138, Address: 0x101585c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 140, Address: 0x1015884 */
  bCarry = CCset(iColiData, iXposi); /* Line 141, Address: 0x10158b0 */
  iColiData = iColiData - iXposi; /* Line 142, Address: 0x10158d4 */

  if (bCarry == 1) /* Line 144, Address: 0x10158fc */
  {
    iColiwk += iColiwk; /* Line 146, Address: 0x1015914 */
    bCarry = CSset(iColiData, iColiwk); /* Line 147, Address: 0x1015920 */
    iColiData += iColiwk; /* Line 148, Address: 0x1015938 */
    if (bCarry == 1) /* Line 149, Address: 0x1015944 */
      return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 150, Address: 0x101595c */
    else
      return 0; /* Line 152, Address: 0x1015984 */
  }

  if (iColiData > 16) /* Line 155, Address: 0x1015990 */
    return 0; /* Line 156, Address: 0x10159a4 */


  return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 159, Address: 0x10159b0 */

} /* Line 161, Address: 0x10159d0 */





















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5) { /* Line 183, Address: 0x10159f0 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 187, Address: 0x1015a18 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 189, Address: 0x1015a44 */
  bCarry = CCset(iYwork, iYposi); /* Line 190, Address: 0x1015a70 */
  iYwork = iYwork - iYposi; /* Line 191, Address: 0x1015a94 */
  if (bCarry == 1) /* Line 192, Address: 0x1015abc */
  {
    iColiData += iColiData; /* Line 194, Address: 0x1015ad4 */
    bCarry = CSset(iColiData, iYwork); /* Line 195, Address: 0x1015ae0 */
    iColiData += iYwork; /* Line 196, Address: 0x1015af8 */
    if (bCarry == 1) /* Line 197, Address: 0x1015b04 */
      return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 198, Address: 0x1015b1c */
    else
      return 0; /* Line 200, Address: 0x1015b40 */
  }


  if (iYwork > iD5) /* Line 204, Address: 0x1015b4c */
    return 0; /* Line 205, Address: 0x1015b6c */


  return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 208, Address: 0x1015b78 */

} /* Line 210, Address: 0x1015b94 */
























short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 235, Address: 0x1015bb0 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 236, Address: 0x1015bd0 */

  if (iColino == 0) /* Line 238, Address: 0x1015be8 */
  {
    pcolnomal(pActwk, pColliAct); /* Line 240, Address: 0x1015bf4 */
    return 1; /* Line 241, Address: 0x1015c04 */
  }
  if (iColino == 192) /* Line 243, Address: 0x1015c10 */
  {
    pcolspecial(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 245, Address: 0x1015c20 */
    return 1; /* Line 246, Address: 0x1015c3c */
  }
  if ((char)iColino < 0) /* Line 248, Address: 0x1015c48 */
  {
    pcolplay(pActwk, pColliAct); /* Line 250, Address: 0x1015c60 */
    return 1; /* Line 251, Address: 0x1015c70 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 255, Address: 0x1015c7c */

} /* Line 257, Address: 0x1015c8c */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 272, Address: 0x1015ca0 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) /* Line 275, Address: 0x1015cb4 */
  {

    if (((unsigned short*)pActwk)[26] < 90) /* Line 278, Address: 0x1015cd0 */
      pColliAct->r_no0 += 2; /* Line 279, Address: 0x1015ce8 */
  } /* Line 280, Address: 0x1015cf8 */
  else
  {

    if (pActwk->yspeed.w < 0) /* Line 284, Address: 0x1015d00 */
    {
      iD0 = pActwk->yposi.w.h - 16; /* Line 286, Address: 0x1015d18 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 287, Address: 0x1015d3c */
      if (bCarry == 0) /* Line 288, Address: 0x1015d64 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 290, Address: 0x1015d78 */
        pColliAct->yspeed.w = -384; /* Line 291, Address: 0x1015d9c */
        if (pColliAct->r_no1 == 0) /* Line 292, Address: 0x1015da8 */
          pColliAct->r_no1 += 4; /* Line 293, Address: 0x1015dbc */
      }
    } /* Line 295, Address: 0x1015dcc */
    else
    {

      if (pActwk->mstno.b.h == 2) /* Line 299, Address: 0x1015dd4 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 301, Address: 0x1015df0 */
        pColliAct->r_no0 += 2; /* Line 302, Address: 0x1015e14 */
      }
    }
  }
  return -1; /* Line 306, Address: 0x1015e24 */
} /* Line 307, Address: 0x1015e28 */















short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 323, Address: 0x1015e40 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) /* Line 327, Address: 0x1015e58 */
  {


    pcolplay(pActwk, pColliAct); /* Line 331, Address: 0x1015e9c */
    return -1; /* Line 332, Address: 0x1015eac */
  }


  if (pColliAct->colicnt != 0) /* Line 336, Address: 0x1015eb8 */
  {
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 338, Address: 0x1015ecc */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 339, Address: 0x1015ef0 */
    pActwk->xspeed.w /= 2; /* Line 340, Address: 0x1015f14 */
    pActwk->yspeed.w /= 2; /* Line 341, Address: 0x1015f38 */
    pColliAct->colino = 0; /* Line 342, Address: 0x1015f5c */
    --pColliAct->colicnt; /* Line 343, Address: 0x1015f64 */
    if (pColliAct->colicnt == 0) /* Line 344, Address: 0x1015f74 */
      pColliAct->cddat |= 128; /* Line 345, Address: 0x1015f88 */
  } /* Line 346, Address: 0x1015f98 */
  else
  {

    pColliAct->cddat |= 128; /* Line 350, Address: 0x1015fa0 */
    iScoreCntwk = emyscorecnt; /* Line 351, Address: 0x1015fb0 */
    emyscorecnt += 2; /* Line 352, Address: 0x1015fc0 */
    if ((unsigned short)iScoreCntwk >= 6) /* Line 353, Address: 0x1015fd4 */
      iScoreCntwk = 6; /* Line 354, Address: 0x1015fe8 */

    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 356, Address: 0x1015ff4 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 357, Address: 0x1015ffc */
    if (emyscorecnt >= 32) /* Line 358, Address: 0x1016038 */
    {
      iScoreData = 1000; /* Line 360, Address: 0x1016054 */
      ((short*)pColliAct)[33] = 10; /* Line 361, Address: 0x1016060 */
    }

    scoreup(iScoreData); /* Line 364, Address: 0x101606c */
    soundset(150); /* Line 365, Address: 0x101607c */
    pColliAct->actno = 24; /* Line 366, Address: 0x1016088 */
    pColliAct->r_no0 = 0; /* Line 367, Address: 0x1016094 */
    pColliAct->userflag.b.h = 1; /* Line 368, Address: 0x101609c */

    if (pActwk->yspeed.w >= 0) /* Line 370, Address: 0x10160a8 */
    {
      bCarry = CCset(pActwk->yposi.w.h, pColliAct->yposi.w.h); /* Line 372, Address: 0x10160c0 */
      if (bCarry == 1) /* Line 373, Address: 0x10160f0 */

        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 375, Address: 0x1016108 */
      else
        pActwk->yspeed.w -= 256; /* Line 377, Address: 0x1016134 */
    } /* Line 378, Address: 0x1016144 */
    else
    {
      pActwk->yspeed.w += 256; /* Line 381, Address: 0x101614c */
    }
  }
  return -1; /* Line 384, Address: 0x101615c */
} /* Line 385, Address: 0x1016160 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 401, Address: 0x1016180 */
  pColliAct->cddat |= 128; /* Line 402, Address: 0x1016190 */
  return pcolplay(pActwk, pColliAct); /* Line 403, Address: 0x10161a0 */
} /* Line 404, Address: 0x10161b0 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 419, Address: 0x10161c0 */
  if (plpower_m == 0) /* Line 420, Address: 0x10161d0 */
    return pcole(pActwk, pColliAct); /* Line 421, Address: 0x10161e4 */
  else
    return -1; /* Line 423, Address: 0x10161fc */
} /* Line 424, Address: 0x1016200 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 439, Address: 0x1016210 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 440, Address: 0x1016220 */
    return -1; /* Line 441, Address: 0x1016234 */
  else
    return playdamageset(pActwk, pColliAct); /* Line 443, Address: 0x1016240 */
} /* Line 444, Address: 0x1016250 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 459, Address: 0x1016260 */


  pActwk->actfree[0] = 0; /* Line 462, Address: 0x1016270 */
  if (!(plpower_b & 1)) /* Line 463, Address: 0x1016278 */
    conbine_flag = 0; /* Line 464, Address: 0x1016290 */
  plpower_b &= 254; /* Line 465, Address: 0x1016298 */

  pActwk->r_no0 = 4; /* Line 467, Address: 0x10162ac */
  jumpcolsub(); /* Line 468, Address: 0x10162b8 */
  pActwk->cddat |= 2; /* Line 469, Address: 0x10162c0 */
  if (pActwk->cddat & 64) /* Line 470, Address: 0x10162d0 */
  {
    pActwk->yspeed.w = -512; /* Line 472, Address: 0x10162e8 */
    pActwk->xspeed.w = -256; /* Line 473, Address: 0x10162f4 */
  } /* Line 474, Address: 0x1016300 */
  else
  {
    pActwk->yspeed.w = -1024; /* Line 477, Address: 0x1016308 */
    pActwk->xspeed.w = -512; /* Line 478, Address: 0x1016314 */
  }

  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) /* Line 481, Address: 0x1016320 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 482, Address: 0x101634c */

  pActwk->mspeed.w = 0; /* Line 484, Address: 0x1016370 */
  pActwk->mstno.b.h = 26; /* Line 485, Address: 0x1016378 */
  ((short*)pActwk)[26] = 120; /* Line 486, Address: 0x1016384 */
} /* Line 487, Address: 0x1016390 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 502, Address: 0x10163a0 */
  sprite_status* pFreeAct;
  short iRet;

  if (plpower_b != 0) /* Line 506, Address: 0x10163b4 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 508, Address: 0x10163c8 */
    return -1; /* Line 509, Address: 0x10163d8 */
  }
  if (plring != 0) /* Line 511, Address: 0x10163e4 */
  {
    iRet = actwkchk(&pFreeAct); /* Line 513, Address: 0x10163fc */
    if (iRet == 0) /* Line 514, Address: 0x1016410 */
    {
      pFreeAct->actno = 17; /* Line 516, Address: 0x1016420 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 517, Address: 0x101642c */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 518, Address: 0x101643c */
    }

    playdamagechk(pActwk, pColliAct); /* Line 521, Address: 0x101644c */
    return -1; /* Line 522, Address: 0x101645c */
  }

  if (debugflag.w != 0) /* Line 525, Address: 0x1016468 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 527, Address: 0x1016480 */
    return -1; /* Line 528, Address: 0x1016490 */
  }
  return playdieset(pActwk); /* Line 530, Address: 0x101649c */
} /* Line 531, Address: 0x10164a8 */












short playdieset(sprite_status* pActwk) { /* Line 544, Address: 0x10164c0 */
  if (editmode.w != 0) /* Line 545, Address: 0x10164cc */
    return -1; /* Line 546, Address: 0x10164e4 */
  plpower_m = 0; /* Line 547, Address: 0x10164f0 */
  pActwk->r_no0 = 6; /* Line 548, Address: 0x10164f8 */
  jumpcolsub(); /* Line 549, Address: 0x1016504 */
  pActwk->cddat |= 2; /* Line 550, Address: 0x101650c */
  pActwk->yspeed.w = -1792; /* Line 551, Address: 0x101651c */
  pActwk->xspeed.w = 0; /* Line 552, Address: 0x1016528 */
  pActwk->mspeed.w = 0; /* Line 553, Address: 0x1016530 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 554, Address: 0x1016538 */
  pActwk->mstno.b.h = 24; /* Line 555, Address: 0x1016548 */
  pActwk->sproffset |= 32768; /* Line 556, Address: 0x1016554 */
  pActwk->sprpri = 0; /* Line 557, Address: 0x1016564 */
  soundset(147); /* Line 558, Address: 0x101656c */
  return -1; /* Line 559, Address: 0x1016578 */
} /* Line 560, Address: 0x101657c */



















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 580, Address: 0x1016590 */
  char cColiNo = pColliAct->colino & 63; /* Line 581, Address: 0x10165a4 */

  switch (cColiNo) /* Line 583, Address: 0x10165c4 */
  {
    case 31:
    case 35:
      ++pColliAct->colicnt; /* Line 587, Address: 0x1016610 */
      goto label1; /* Line 588, Address: 0x1016620 */
    case 51:
    case 58:
    case 59:
      main_attack(pActwk, pColliAct); /* Line 592, Address: 0x1016628 */
      goto label1; /* Line 593, Address: 0x1016638 */
  }

  switch (bossstart) /* Line 596, Address: 0x1016640 */
  {
    case 0: return -1; /* Line 598, Address: 0x1016680 */

    case 1:
      if (cColiNo < 60) return -1; /* Line 601, Address: 0x101668c */
      if (cColiNo > 63) return -1; /* Line 602, Address: 0x10166ac */
      eggman_chk(pActwk, pColliAct); /* Line 603, Address: 0x10166cc */
      goto label1; /* Line 604, Address: 0x10166dc */


    case 4:
      if (cColiNo == 63) /* Line 608, Address: 0x10166e4 */
      {
        if (pActwk->cddat & 20) /* Line 610, Address: 0x10166f8 */
        {
          pActwk->cddat &= 251; /* Line 612, Address: 0x1016710 */
          pActwk->cddat &= 239; /* Line 613, Address: 0x1016720 */
          pColliAct->colino = 0; /* Line 614, Address: 0x1016730 */
          pActwk->mstno.b.h = 21; /* Line 615, Address: 0x1016738 */
          soundset(173); /* Line 616, Address: 0x1016744 */
          plairset(); /* Line 617, Address: 0x1016750 */
          pActwk->yspeed.w = 1024; /* Line 618, Address: 0x1016758 */
          pActwk->xspeed.w = -512; /* Line 619, Address: 0x1016764 */
          if (pActwk->xposi.w.h >= pColliAct->xposi.w.h) pActwk->xspeed.w *= -1; /* Line 620, Address: 0x1016770 */
        }
      } /* Line 622, Address: 0x10167ac */
      else if (cColiNo == 62) /* Line 623, Address: 0x10167b4 */
      {
        pcolplay(pActwk, pColliAct); /* Line 625, Address: 0x10167c8 */
        ++pColliAct->colicnt; /* Line 626, Address: 0x10167d8 */
      } /* Line 627, Address: 0x10167e8 */
      else
      {
        return -1; /* Line 630, Address: 0x10167f0 */
      }
      break;


    case 5:
      if (cColiNo == 61) /* Line 636, Address: 0x10167fc */
      {
        pcolplay(pActwk, pColliAct); /* Line 638, Address: 0x1016810 */
        ++pColliAct->colicnt; /* Line 639, Address: 0x1016820 */
      }
      break;
  }



label1:
  return -1; /* Line 647, Address: 0x1016830 */
} /* Line 648, Address: 0x1016834 */














short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 663, Address: 0x1016850 */
  pcolnomal(pActwk, pColliAct); /* Line 664, Address: 0x1016860 */
  if (pColliAct->colino == 0) pColliAct->colicnt += 3; /* Line 665, Address: 0x1016870 */
  pColliAct->colino = 0; /* Line 666, Address: 0x1016894 */
  ++pColliAct->colicnt; /* Line 667, Address: 0x101689c */
  return 1; /* Line 668, Address: 0x10168ac */
} /* Line 669, Address: 0x10168b0 */














short main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 684, Address: 0x10168c0 */
  if (pActwk->mstno.b.h == 2) /* Line 685, Address: 0x10168cc */
    ++pColliAct->colicnt; /* Line 686, Address: 0x10168e8 */
  return 1; /* Line 687, Address: 0x10168f8 */
} /* Line 688, Address: 0x10168fc */
