#include "..\EQU.H"
#include "COLI1.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYER.H"
#include "..\SCORE.H"

extern short actwkchk(sprite_status** ppActwk);

unsigned short escoretbl[4] = { 10, 20, 50, 100 };
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
  {   8,  16 }, {  16,  16 },
  {  12,  12 }, {  16,  16 },
  {   4,   4 }, {  16,  16 },
  {  22,  26 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {   0,   0 },
  {   0,   0 }, {  40,  36 },
  {  18,  17 }, {  32,  24 },
  {  12,  20 }, {  32,  12 },
  {  12,  16 }, {   0,   0 }
};
static unsigned char bCarry;


























short pcol(sprite_status* pActwk) { /* Line 73, Address: 0x101fc70 */
  short iXwork = pActwk->xposi.w.h, /* Line 74, Address: 0x101fc9c */
        iYwork = pActwk->yposi.w.h,
        iSprvs = pActwk->sprvsize - 3;
  short iXcollichk = 16; /* Line 77, Address: 0x101fcdc */
  short i, iRet, iColino;
  sprite_status* pColliAct;

  iXwork -= 8; /* Line 81, Address: 0x101fce8 */
  iYwork -= iSprvs; /* Line 82, Address: 0x101fcf4 */

  if (pActwk->patno == 57) /* Line 84, Address: 0x101fd00 */
  {
    iYwork += 12; /* Line 86, Address: 0x101fd18 */
    iSprvs = 10; /* Line 87, Address: 0x101fd24 */
  }

  iXcollichk = 16; /* Line 90, Address: 0x101fd30 */
  iSprvs += iSprvs; /* Line 91, Address: 0x101fd3c */

  pColliAct = &actwk[32]; /* Line 93, Address: 0x101fd48 */

  for (i = 0; i < 96; ++i, ++pColliAct) /* Line 95, Address: 0x101fd50 */
  {

    if (pColliAct->actflg & 128) /* Line 98, Address: 0x101fd5c */
    {
      iColino = pColliAct->colino; /* Line 100, Address: 0x101fd70 */
      if (iColino != 0) /* Line 101, Address: 0x101fd80 */
      {
        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 103, Address: 0x101fd90 */
        if (iRet == -1) /* Line 104, Address: 0x101fdb4 */
          return iRet; /* Line 105, Address: 0x101fdc8 */
      }
    }
  } /* Line 108, Address: 0x101fdd4 */
  iColino = 0; /* Line 109, Address: 0x101fdf8 */
  return iColino; /* Line 110, Address: 0x101fdfc */
} /* Line 111, Address: 0x101fe00 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 131, Address: 0x101fe30 */
  short iColiNo = pColliAct->colino; /* Line 132, Address: 0x101fe58 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 136, Address: 0x101fe6c */
  iColiData = colitbl[iColiNo][0]; /* Line 137, Address: 0x101fe8c */

  iColiwk = pColliAct->xposi.w.h - iColiData; /* Line 139, Address: 0x101feb4 */
  bCarry = CCset(iColiwk, iXposi); /* Line 140, Address: 0x101fee0 */
  iColiwk = iColiwk - iXposi; /* Line 141, Address: 0x101ff04 */

  if (bCarry == 1) /* Line 143, Address: 0x101ff2c */
  {
    iColiData += iColiData; /* Line 145, Address: 0x101ff44 */
    bCarry = CSset(iColiwk, iColiData); /* Line 146, Address: 0x101ff50 */
    iColiwk += iColiData; /* Line 147, Address: 0x101ff68 */
    if (bCarry == 1) /* Line 148, Address: 0x101ff74 */
      return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 149, Address: 0x101ff8c */
    else
      return 0; /* Line 151, Address: 0x101ffb4 */
  }

  if (iColiwk > 16) /* Line 154, Address: 0x101ffc0 */
    return 0; /* Line 155, Address: 0x101ffd4 */


  return CollitblDataYchk(pActwk, pColliAct, iXposi, iYposi, iColiNo, iD5); /* Line 158, Address: 0x101ffe0 */

} /* Line 160, Address: 0x1020000 */





















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5) { /* Line 182, Address: 0x1020020 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 186, Address: 0x1020048 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 188, Address: 0x1020074 */
  bCarry = CCset(iYwork, iYposi); /* Line 189, Address: 0x10200a0 */
  iYwork = iYwork - iYposi; /* Line 190, Address: 0x10200c4 */
  if (bCarry == 1) /* Line 191, Address: 0x10200ec */
  {
    iColiData += iColiData; /* Line 193, Address: 0x1020104 */
    bCarry = CSset(iColiData, iYwork); /* Line 194, Address: 0x1020110 */
    iColiData += iYwork; /* Line 195, Address: 0x1020128 */
    if (bCarry == 1) /* Line 196, Address: 0x1020134 */
      return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 197, Address: 0x102014c */
    else
      return 0; /* Line 199, Address: 0x1020170 */
  }


  if (iYwork > iD5) /* Line 203, Address: 0x102017c */
    return 0; /* Line 204, Address: 0x102019c */


  return ColliHitChk(pActwk, pColliAct, iXposi, iYwork, iD5); /* Line 207, Address: 0x10201a8 */

} /* Line 209, Address: 0x10201c4 */
























short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 234, Address: 0x10201e0 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 235, Address: 0x1020200 */

  if (iColino == 0) /* Line 237, Address: 0x1020218 */
  {
    pcolnomal(pActwk, pColliAct); /* Line 239, Address: 0x1020224 */
    return 1; /* Line 240, Address: 0x1020234 */
  }
  if (iColino == 192) /* Line 242, Address: 0x1020240 */
  {
    pcolspecial(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 244, Address: 0x1020250 */
    return 1; /* Line 245, Address: 0x102026c */
  }
  if ((char)iColino < 0) /* Line 247, Address: 0x1020278 */
  {
    pcolplay(pActwk, pColliAct); /* Line 249, Address: 0x1020290 */
    return 1; /* Line 250, Address: 0x10202a0 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 254, Address: 0x10202ac */

} /* Line 256, Address: 0x10202bc */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 271, Address: 0x10202d0 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) /* Line 274, Address: 0x10202e4 */
  {

    if (((unsigned short*)pActwk)[26] < 90) /* Line 277, Address: 0x1020300 */
      pColliAct->r_no0 += 2; /* Line 278, Address: 0x1020318 */
  } /* Line 279, Address: 0x1020328 */
  else
  {

    if (pActwk->yspeed.w < 0) /* Line 283, Address: 0x1020330 */
    {
      iD0 = pActwk->yposi.w.h - 16; /* Line 285, Address: 0x1020348 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 286, Address: 0x102036c */
      if (bCarry == 0) /* Line 287, Address: 0x1020394 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 289, Address: 0x10203a8 */
        pColliAct->yspeed.w = -384; /* Line 290, Address: 0x10203cc */
        if (pColliAct->r_no1 == 0) /* Line 291, Address: 0x10203d8 */
          pColliAct->r_no1 += 4; /* Line 292, Address: 0x10203ec */
      }
    } /* Line 294, Address: 0x10203fc */
    else
    {

      if (pActwk->mstno.b.h == 2) /* Line 298, Address: 0x1020404 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 300, Address: 0x1020420 */
        pColliAct->r_no0 += 2; /* Line 301, Address: 0x1020444 */
      }
    }
  }
  return -1; /* Line 305, Address: 0x1020454 */
} /* Line 306, Address: 0x1020458 */















short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 322, Address: 0x1020470 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 /* Line 326, Address: 0x1020488 */
      && plpower_m == 0
      && pActwk->mstno.b.h != 2)
  {
    pcolplay(pActwk, pColliAct); /* Line 330, Address: 0x10204cc */
    return -1; /* Line 331, Address: 0x10204dc */
  }


  if (pColliAct->colicnt != 0) /* Line 335, Address: 0x10204e8 */
  {
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 337, Address: 0x10204fc */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 338, Address: 0x1020520 */
    pActwk->xspeed.w /= 2; /* Line 339, Address: 0x1020544 */
    pActwk->yspeed.w /= 2; /* Line 340, Address: 0x1020568 */
    pColliAct->colino = 0; /* Line 341, Address: 0x102058c */
    --pColliAct->colicnt; /* Line 342, Address: 0x1020594 */
    if (pColliAct->colicnt == 0) /* Line 343, Address: 0x10205a4 */
      pColliAct->cddat |= 128; /* Line 344, Address: 0x10205b8 */
  } /* Line 345, Address: 0x10205c8 */
  else
  {

    pColliAct->cddat |= 128; /* Line 349, Address: 0x10205d0 */
    iScoreCntwk = emyscorecnt; /* Line 350, Address: 0x10205e0 */
    emyscorecnt += 2; /* Line 351, Address: 0x10205f0 */
    if ((unsigned short)iScoreCntwk >= 6) /* Line 352, Address: 0x1020604 */
      iScoreCntwk = 6; /* Line 353, Address: 0x1020618 */

    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 355, Address: 0x1020624 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 356, Address: 0x102062c */
    if (emyscorecnt >= 32) /* Line 357, Address: 0x1020668 */
    {
      iScoreData = 1000; /* Line 359, Address: 0x1020684 */
      ((short*)pColliAct)[33] = 10; /* Line 360, Address: 0x1020690 */
    }

    scoreup(iScoreData); /* Line 363, Address: 0x102069c */
    soundset(150); /* Line 364, Address: 0x10206ac */
    pColliAct->actno = 24; /* Line 365, Address: 0x10206b8 */
    pColliAct->r_no0 = 0; /* Line 366, Address: 0x10206c4 */
    pColliAct->userflag.b.h = 1; /* Line 367, Address: 0x10206cc */

    if (pActwk->yspeed.w >= 0) /* Line 369, Address: 0x10206d8 */
    {
      if (pActwk->yposi.w.h < pColliAct->yposi.w.h) /* Line 371, Address: 0x10206f0 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 372, Address: 0x102071c */
      else
        pActwk->yspeed.w -= 256; /* Line 374, Address: 0x1020748 */
    } /* Line 375, Address: 0x1020758 */
    else
      pActwk->yspeed.w += 256; /* Line 377, Address: 0x1020760 */
  }
  return -1; /* Line 379, Address: 0x1020770 */
} /* Line 380, Address: 0x1020774 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 396, Address: 0x1020790 */
  pColliAct->cddat |= 128; /* Line 397, Address: 0x10207a0 */
  return pcolplay(pActwk, pColliAct); /* Line 398, Address: 0x10207b0 */
} /* Line 399, Address: 0x10207c0 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 414, Address: 0x10207d0 */
  if (plpower_m == 0) /* Line 415, Address: 0x10207e0 */
    return pcole(pActwk, pColliAct); /* Line 416, Address: 0x10207f4 */

  return -1; /* Line 418, Address: 0x102080c */
} /* Line 419, Address: 0x1020810 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 434, Address: 0x1020820 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 435, Address: 0x1020830 */
    return -1; /* Line 436, Address: 0x1020844 */

  return playdamageset(pActwk, pColliAct); /* Line 438, Address: 0x1020850 */
} /* Line 439, Address: 0x1020860 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 454, Address: 0x1020870 */


  pActwk->actfree[0] = 0; /* Line 457, Address: 0x1020880 */
  if ((plpower_b & 1) == 0) /* Line 458, Address: 0x1020888 */
    conbine_flag = 0; /* Line 459, Address: 0x10208a0 */
  plpower_b &= 254; /* Line 460, Address: 0x10208a8 */

  pActwk->r_no0 = 4; /* Line 462, Address: 0x10208bc */
  jumpcolsub(); /* Line 463, Address: 0x10208c8 */
  pActwk->cddat |= 2; /* Line 464, Address: 0x10208d0 */

  if (pActwk->cddat & 64) /* Line 466, Address: 0x10208e0 */
  {
    pActwk->yspeed.w = -512; /* Line 468, Address: 0x10208f8 */
    pActwk->xspeed.w = -256; /* Line 469, Address: 0x1020904 */
  } /* Line 470, Address: 0x1020910 */
  else
  {
    pActwk->yspeed.w = -1024; /* Line 473, Address: 0x1020918 */
    pActwk->xspeed.w = -512; /* Line 474, Address: 0x1020924 */
  }

  if ((unsigned short)pColliAct->xposi.w.h <= (unsigned short)pActwk->xposi.w.h) /* Line 477, Address: 0x1020930 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 478, Address: 0x102095c */

  pActwk->mspeed.w = 0; /* Line 480, Address: 0x1020980 */
  pActwk->mstno.b.h = 26; /* Line 481, Address: 0x1020988 */
  ((short*)pActwk)[26] = 120; /* Line 482, Address: 0x1020994 */
} /* Line 483, Address: 0x10209a0 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 498, Address: 0x10209b0 */
  sprite_status* pFreeAct;
  short iRet;

  if (plpower_b != 0) /* Line 502, Address: 0x10209c4 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 504, Address: 0x10209d8 */
    return -1; /* Line 505, Address: 0x10209e8 */
  }
  if (plring != 0) /* Line 507, Address: 0x10209f4 */
  {
    iRet = actwkchk(&pFreeAct); /* Line 509, Address: 0x1020a0c */
    if (iRet == 0) /* Line 510, Address: 0x1020a20 */
    {
      pFreeAct->actno = 17; /* Line 512, Address: 0x1020a30 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 513, Address: 0x1020a3c */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 514, Address: 0x1020a4c */
    }

    playdamagechk(pActwk, pColliAct); /* Line 517, Address: 0x1020a5c */
    return -1; /* Line 518, Address: 0x1020a6c */
  }

  if (debugflag.w != 0) /* Line 521, Address: 0x1020a78 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 523, Address: 0x1020a90 */
    return -1; /* Line 524, Address: 0x1020aa0 */
  }
  return playdieset(pActwk); /* Line 526, Address: 0x1020aac */
} /* Line 527, Address: 0x1020ab8 */












short playdieset(sprite_status* pActwk) { /* Line 540, Address: 0x1020ad0 */
  if (editmode.w != 0) /* Line 541, Address: 0x1020adc */
    return -1; /* Line 542, Address: 0x1020af4 */
  plpower_m = 0; /* Line 543, Address: 0x1020b00 */
  pActwk->r_no0 = 6; /* Line 544, Address: 0x1020b08 */
  jumpcolsub(); /* Line 545, Address: 0x1020b14 */
  pActwk->cddat |= 2; /* Line 546, Address: 0x1020b1c */
  pActwk->yspeed.w = -1792; /* Line 547, Address: 0x1020b2c */
  pActwk->xspeed.w = 0; /* Line 548, Address: 0x1020b38 */
  pActwk->mspeed.w = 0; /* Line 549, Address: 0x1020b40 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 550, Address: 0x1020b48 */
  pActwk->mstno.b.h = 24; /* Line 551, Address: 0x1020b58 */
  pActwk->sproffset |= 32768; /* Line 552, Address: 0x1020b64 */
  pActwk->sprpri = 0; /* Line 553, Address: 0x1020b74 */
  soundset(147); /* Line 554, Address: 0x1020b7c */
  return -1; /* Line 555, Address: 0x1020b88 */
} /* Line 556, Address: 0x1020b8c */



















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 576, Address: 0x1020ba0 */
  char cColiNo = pColliAct->colino & 63; /* Line 577, Address: 0x1020bc0 */

  switch (cColiNo) /* Line 579, Address: 0x1020be0 */
  {
    case 11:
      pcolplay2(pActwk, pColliAct); /* Line 582, Address: 0x1020c5c */
      break; /* Line 583, Address: 0x1020c6c */
    case 12:
      yago(pActwk, pColliAct, iXposi, iChkPosi, iD5); /* Line 585, Address: 0x1020c74 */
      break; /* Line 586, Address: 0x1020c90 */
    case 23:
    case 33:
    case 31:
    case 35:
      ++pColliAct->colicnt; /* Line 591, Address: 0x1020c98 */
      break; /* Line 592, Address: 0x1020ca8 */
    case 47:
    case 58:
    case 59:
      main_attack(pActwk, pColliAct); /* Line 596, Address: 0x1020cb0 */
      break; /* Line 597, Address: 0x1020cc0 */
    default:
      if (cColiNo < 60) return -1; /* Line 599, Address: 0x1020cc8 */
      if (cColiNo > 63) return -1; /* Line 600, Address: 0x1020ce8 */
      eggman_chk(pActwk, pColliAct); /* Line 601, Address: 0x1020d08 */
  }
  return -1; /* Line 603, Address: 0x1020d18 */
} /* Line 604, Address: 0x1020d1c */














short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 619, Address: 0x1020d30 */
  if (bossstart != 1) return -1; /* Line 620, Address: 0x1020d40 */
  pcolnomal(pActwk, pColliAct); /* Line 621, Address: 0x1020d64 */
  if (pColliAct->colino == 0) pColliAct->colicnt += 3; /* Line 622, Address: 0x1020d74 */
  pColliAct->colino = 0; /* Line 623, Address: 0x1020d98 */
  ++pColliAct->colicnt; /* Line 624, Address: 0x1020da0 */
  return 1; /* Line 625, Address: 0x1020db0 */
} /* Line 626, Address: 0x1020db4 */



















short yago(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5) { /* Line 646, Address: 0x1020dd0 */
  iD5 -= iChkPosi; /* Line 647, Address: 0x1020dec */
  if (iD5 >= 8) /* Line 648, Address: 0x1020dfc */
    return pcolnomal(pActwk, pColliAct); /* Line 649, Address: 0x1020e14 */
  iChkPosi = pColliAct->xposi.w.h - 4; /* Line 650, Address: 0x1020e2c */
  if (pColliAct->cddat & 1) /* Line 651, Address: 0x1020e4c */
    iChkPosi -= 16; /* Line 652, Address: 0x1020e64 */

  bCarry = CCset(iChkPosi, iXposi); /* Line 654, Address: 0x1020e70 */
  iChkPosi -= iXposi; /* Line 655, Address: 0x1020e98 */
  if (bCarry == 1) /* Line 656, Address: 0x1020ea8 */
  {
    bCarry = CSset(iChkPosi, 24); /* Line 658, Address: 0x1020ec0 */
    iChkPosi += 24; /* Line 659, Address: 0x1020edc */
    if (bCarry == 1) /* Line 660, Address: 0x1020ee8 */
      return pcolplay(pActwk, pColliAct); /* Line 661, Address: 0x1020f00 */
    else
      return pcolnomal(pActwk, pColliAct); /* Line 663, Address: 0x1020f18 */
  }

  if ((unsigned short)iChkPosi >= 16) /* Line 666, Address: 0x1020f30 */
    return pcolplay(pActwk, pColliAct); /* Line 667, Address: 0x1020f48 */
  else
    return pcolnomal(pActwk, pColliAct); /* Line 669, Address: 0x1020f60 */
} /* Line 670, Address: 0x1020f70 */














short main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 685, Address: 0x1020f80 */
  if (pActwk->mstno.b.h == 2) /* Line 686, Address: 0x1020f8c */
    ++pColliAct->colicnt; /* Line 687, Address: 0x1020fa8 */
  return 1; /* Line 688, Address: 0x1020fb8 */
} /* Line 689, Address: 0x1020fbc */
