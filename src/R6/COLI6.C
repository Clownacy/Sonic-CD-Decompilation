#include "..\EQU.H"
#include "COLI6.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYER6.H"
#include "..\SCORE.H"

static unsigned char bCarry;
unsigned char colitbl[64][2] =
{
  {  20,  20 },
  {  18,  12 },
  {  16,  16 },
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
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   0,   0 },
  {   8,  19 },
  {   8,  28 },
  {  24,  12 },
  {  16,  16 },
  {   4,   4 },
  {   8,  16 },
  {  16,   5 },
  {  12,  12 },
  {   8,   8 },
  {  26,  30 },
  {   8,   8 },
  {  40,  36 },
  {  18,  17 },
  {  30,  48 },
  {  60,  32 },
  {  16,   8 },
  {   2,  12 },
  {   0,   0 }
};
unsigned short escoretbl[4] = { 10, 20, 50, 100 };


short pcol(sprite_status* pActwk) { /* Line 80, Address: 0x1015a40 */
  short iXwork = pActwk->xposi.w.h, iYwork = pActwk->yposi.w.h, iSprvs = pActwk->sprvsize - 3; /* Line 81, Address: 0x1015a6c */
  short iXcollichk;
  short i;
  short iRet;
  short iColino;
  sprite_status* pColliAct;

  if (pActwk->actfree[2] & 64) /* Line 88, Address: 0x1015aac */
    return 0; /* Line 89, Address: 0x1015ac4 */

  iXwork -= 8; /* Line 91, Address: 0x1015ad0 */
  iYwork -= iSprvs; /* Line 92, Address: 0x1015adc */
  if (pActwk->patno == 57) /* Line 93, Address: 0x1015ae8 */
  {
    iYwork += 12; /* Line 95, Address: 0x1015b00 */
    iSprvs = 10; /* Line 96, Address: 0x1015b0c */
  }

  iXcollichk = 16; /* Line 99, Address: 0x1015b18 */
  iSprvs += iSprvs; /* Line 100, Address: 0x1015b24 */
  pColliAct = &actwk[32]; /* Line 101, Address: 0x1015b30 */

  for (i = 0; i < 96; ++i, ++pColliAct) /* Line 103, Address: 0x1015b38 */
  {

    if (pColliAct->actflg & 128) /* Line 106, Address: 0x1015b44 */
    {
      iColino = pColliAct->colino; /* Line 108, Address: 0x1015b58 */
      if (iColino != 0) /* Line 109, Address: 0x1015b68 */
      {
        iRet = CollitblDataXchk(pActwk, pColliAct, iXwork, iYwork, iSprvs); /* Line 111, Address: 0x1015b78 */
        if (iRet) /* Line 112, Address: 0x1015b9c */
          return iRet; /* Line 113, Address: 0x1015ba4 */
      }
    }
  } /* Line 116, Address: 0x1015bb0 */
  return 0; /* Line 117, Address: 0x1015bd4 */
} /* Line 118, Address: 0x1015bd8 */



















short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5) { /* Line 138, Address: 0x1015c10 */
  short iColiNo = pColliAct->colino; /* Line 139, Address: 0x1015c38 */
  short iColiwk;
  short iColiData;

  iColiNo = (iColiNo & 63) - 1; /* Line 143, Address: 0x1015c4c */
  iColiwk = colitbl[iColiNo][0]; /* Line 144, Address: 0x1015c6c */

  iColiData = pColliAct->xposi.w.h - iColiwk; /* Line 146, Address: 0x1015c94 */
  bCarry = CCset(iColiData, iXposi); /* Line 147, Address: 0x1015cc0 */
  iColiData = iColiData - iXposi; /* Line 148, Address: 0x1015ce4 */
  if (bCarry == 1) /* Line 149, Address: 0x1015d0c */
  {
    iColiwk += iColiwk; /* Line 151, Address: 0x1015d24 */
    bCarry = CSset(iColiData, iColiwk); /* Line 152, Address: 0x1015d30 */
    iColiData += iColiwk; /* Line 153, Address: 0x1015d48 */
    if (bCarry == 1) /* Line 154, Address: 0x1015d54 */
      return CollitblDataYchk(pActwk, pColliAct, iYposi, iColiNo, iD5); /* Line 155, Address: 0x1015d6c */
    else
      return 0; /* Line 157, Address: 0x1015d90 */
  }

  if (iColiData > 16) /* Line 160, Address: 0x1015d9c */
    return 0; /* Line 161, Address: 0x1015db0 */

  return CollitblDataYchk(pActwk, pColliAct, iYposi, iColiNo, iD5); /* Line 163, Address: 0x1015dbc */
} /* Line 164, Address: 0x1015dd8 */




















short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iYposi, short iColiNo, short iD5) { /* Line 185, Address: 0x1015e00 */
  short iColiData;
  short iYwork;

  iColiData = colitbl[iColiNo][1]; /* Line 189, Address: 0x1015e24 */

  iYwork = pColliAct->yposi.w.h - iColiData; /* Line 191, Address: 0x1015e50 */
  bCarry = CCset(iYwork, iYposi); /* Line 192, Address: 0x1015e7c */
  iYwork = iYwork - iYposi; /* Line 193, Address: 0x1015ea0 */
  if (bCarry == 1) /* Line 194, Address: 0x1015ec8 */
  {
    iColiData += iColiData; /* Line 196, Address: 0x1015ee0 */
    bCarry = CSset(iColiData, iYwork); /* Line 197, Address: 0x1015eec */
    iColiData += iYwork; /* Line 198, Address: 0x1015f04 */
    if (bCarry == 1) /* Line 199, Address: 0x1015f10 */
      return ColliHitChk(pActwk, pColliAct); /* Line 200, Address: 0x1015f28 */
    else
      return 0; /* Line 202, Address: 0x1015f40 */
  }

  if (iYwork > iD5) /* Line 205, Address: 0x1015f4c */
    return 0; /* Line 206, Address: 0x1015f6c */

  return ColliHitChk(pActwk, pColliAct); /* Line 208, Address: 0x1015f78 */
} /* Line 209, Address: 0x1015f88 */





















short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 231, Address: 0x1015fa0 */
  unsigned char iColino = pColliAct->colino & 192; /* Line 232, Address: 0x1015fb4 */

  if (iColino == 0) /* Line 234, Address: 0x1015fcc */
  {
    pcolnomal(pActwk, pColliAct); /* Line 236, Address: 0x1015fd8 */
    return 1; /* Line 237, Address: 0x1015fe8 */
  }
  if (iColino == 192) /* Line 239, Address: 0x1015ff4 */
  {
    pcolspecial(pActwk, pColliAct); /* Line 241, Address: 0x1016004 */
    return 1; /* Line 242, Address: 0x1016014 */
  }
  if ((char)iColino < 0) /* Line 244, Address: 0x1016020 */
  {
    pcolplay(pActwk, pColliAct); /* Line 246, Address: 0x1016038 */
    return 1; /* Line 247, Address: 0x1016048 */
  }


  return pcolitem(pActwk, pColliAct); /* Line 251, Address: 0x1016054 */

} /* Line 253, Address: 0x1016064 */














short pcolitem(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 268, Address: 0x1016080 */
  short iD0;

  if ((pColliAct->colino & 63) != 6) { /* Line 271, Address: 0x1016094 */


    if (((unsigned short*)pActwk)[26] < 90) /* Line 274, Address: 0x10160b0 */
      pColliAct->r_no0 += 2; /* Line 275, Address: 0x10160c8 */
  } /* Line 276, Address: 0x10160d8 */
  else {


    if (pActwk->yspeed.w < 0) /* Line 280, Address: 0x10160e0 */
    {
      iD0 = pActwk->yposi.w.h - 16; /* Line 282, Address: 0x10160f8 */
      bCarry = CCset(iD0, pColliAct->yposi.w.h); /* Line 283, Address: 0x101611c */
      if (bCarry == 0) /* Line 284, Address: 0x1016144 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 286, Address: 0x1016158 */
        pColliAct->yspeed.w = -384; /* Line 287, Address: 0x101617c */
        if (pColliAct->r_no1 == 0) /* Line 288, Address: 0x1016188 */
          pColliAct->r_no1 += 4; /* Line 289, Address: 0x101619c */
      }
    } /* Line 291, Address: 0x10161ac */
    else
    {

      if (pActwk->mstno.b.h == 2) /* Line 295, Address: 0x10161b4 */
      {
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 297, Address: 0x10161d0 */
        pColliAct->r_no0 += 2; /* Line 298, Address: 0x10161f4 */
      }
    }
  }
  return -1; /* Line 302, Address: 0x1016204 */
} /* Line 303, Address: 0x1016208 */














short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 318, Address: 0x1016220 */
  short iScoreCntwk;
  short iScoreData;

  if (plpower_a == 0 && plpower_m == 0 && pActwk->mstno.b.h != 2) /* Line 322, Address: 0x1016238 */
  {


    pcolplay(pActwk, pColliAct); /* Line 326, Address: 0x101627c */
    return -1; /* Line 327, Address: 0x101628c */
  }


  if (pColliAct->colicnt != 0) /* Line 331, Address: 0x1016298 */
  {
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 333, Address: 0x10162ac */
    pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 334, Address: 0x10162d0 */
    pActwk->xspeed.w /= 2; /* Line 335, Address: 0x10162f4 */
    pActwk->yspeed.w /= 2; /* Line 336, Address: 0x1016318 */
    pColliAct->colino = 0; /* Line 337, Address: 0x101633c */
    --pColliAct->colicnt; /* Line 338, Address: 0x1016344 */
    if (pColliAct->colicnt == 0) /* Line 339, Address: 0x1016354 */
      pColliAct->cddat |= 128; /* Line 340, Address: 0x1016368 */
  } /* Line 341, Address: 0x1016378 */
  else
  {

    pColliAct->cddat |= 128; /* Line 345, Address: 0x1016380 */
    iScoreCntwk = emyscorecnt; /* Line 346, Address: 0x1016390 */
    emyscorecnt += 2; /* Line 347, Address: 0x10163a0 */
    if ((unsigned short)iScoreCntwk >= 6) { /* Line 348, Address: 0x10163b4 */
      iScoreCntwk = 6; /* Line 349, Address: 0x10163c8 */
    }
    ((short*)pColliAct)[33] = iScoreCntwk; /* Line 351, Address: 0x10163d4 */
    iScoreData = escoretbl[iScoreCntwk / 2]; /* Line 352, Address: 0x10163dc */
    if (emyscorecnt >= 32) /* Line 353, Address: 0x1016418 */
    {
      iScoreData = 1000; /* Line 355, Address: 0x1016434 */
      ((short*)pColliAct)[33] = 10; /* Line 356, Address: 0x1016440 */
    }

    scoreup(iScoreData); /* Line 359, Address: 0x101644c */
    soundset(150); /* Line 360, Address: 0x101645c */
    pColliAct->actno = 24; /* Line 361, Address: 0x1016468 */
    pColliAct->r_no0 = 0; /* Line 362, Address: 0x1016474 */
    pColliAct->userflag.b.h = 1; /* Line 363, Address: 0x101647c */

    if (pActwk->yspeed.w >= 0) /* Line 365, Address: 0x1016488 */
    {
      if (pActwk->yposi.w.h < pColliAct->yposi.w.h) /* Line 367, Address: 0x10164a0 */
        pActwk->yspeed.w = -pActwk->yspeed.w; /* Line 368, Address: 0x10164cc */
      else
        pActwk->yspeed.w -= 256; /* Line 370, Address: 0x10164f8 */
    } /* Line 371, Address: 0x1016508 */
    else
      pActwk->yspeed.w += 256; /* Line 373, Address: 0x1016510 */
  }
  return -1; /* Line 375, Address: 0x1016520 */
} /* Line 376, Address: 0x1016524 */















short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 392, Address: 0x1016540 */
  pColliAct->cddat |= 128; /* Line 393, Address: 0x1016550 */
  pcolplay(pActwk, pColliAct); /* Line 394, Address: 0x1016560 */
} /* Line 395, Address: 0x1016570 */














short pcolplay(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 410, Address: 0x1016580 */
  if (plpower_a != 0) /* Line 411, Address: 0x1016590 */
    return -1; /* Line 412, Address: 0x10165a4 */
  if (plpower_m == 0) /* Line 413, Address: 0x10165b0 */
    return pcole(pActwk, pColliAct); /* Line 414, Address: 0x10165c4 */
  else
    return -1; /* Line 416, Address: 0x10165dc */
} /* Line 417, Address: 0x10165e0 */














short pcole(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 432, Address: 0x10165f0 */
  if (((unsigned short*)pActwk)[26] != 0) /* Line 433, Address: 0x1016600 */
    return -1; /* Line 434, Address: 0x1016614 */
  else
    return playdamageset(pActwk, pColliAct); /* Line 436, Address: 0x1016620 */
} /* Line 437, Address: 0x1016630 */














void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 452, Address: 0x1016640 */


  if (!(plpower_b & 1)) /* Line 455, Address: 0x1016650 */
    conbine_flag = 0; /* Line 456, Address: 0x1016668 */
  plpower_b &= 254; /* Line 457, Address: 0x1016670 */

  pActwk->r_no0 = 4; /* Line 459, Address: 0x1016684 */
  jumpcolsub(); /* Line 460, Address: 0x1016690 */
  pActwk->cddat |= 2; /* Line 461, Address: 0x1016698 */

  if (pActwk->cddat & 64) /* Line 463, Address: 0x10166a8 */
  {
    pActwk->yspeed.w = -512; /* Line 465, Address: 0x10166c0 */
    pActwk->xspeed.w = -256; /* Line 466, Address: 0x10166cc */
  } /* Line 467, Address: 0x10166d8 */
  else
  {
    pActwk->yspeed.w = -1024; /* Line 470, Address: 0x10166e0 */
    pActwk->xspeed.w = -512; /* Line 471, Address: 0x10166ec */
  }


  if (pColliAct->xposi.w.h <= pActwk->xposi.w.h) /* Line 475, Address: 0x10166f8 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 476, Address: 0x1016724 */

  pActwk->mspeed.w = 0; /* Line 478, Address: 0x1016748 */
  pActwk->mstno.b.h = 26; /* Line 479, Address: 0x1016750 */
  ((short*)pActwk)[26] = 120; /* Line 480, Address: 0x101675c */
} /* Line 481, Address: 0x1016768 */














short playdamageset(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 496, Address: 0x1016780 */
  sprite_status* pFreeAct;
  int iRet;

  pActwk->actfree[0] = 0; /* Line 500, Address: 0x1016794 */
  pActwk->actfree[2] &= 231; /* Line 501, Address: 0x101679c */
  ((short*)pActwk)[33] = 0; /* Line 502, Address: 0x10167ac */

  if (plpower_b != 0) /* Line 504, Address: 0x10167b4 */
  {
    playdamagechk(pActwk, pColliAct); /* Line 506, Address: 0x10167c8 */
    return -1; /* Line 507, Address: 0x10167d8 */
  }
  if (plring != 0) /* Line 509, Address: 0x10167e4 */
  {
    iRet = actwkchk(&pFreeAct); /* Line 511, Address: 0x10167fc */
    if (iRet == 0) /* Line 512, Address: 0x101680c */
    {
      pFreeAct->actno = 17; /* Line 514, Address: 0x1016814 */
      pFreeAct->xposi.w.h = pActwk->xposi.w.h; /* Line 515, Address: 0x1016820 */
      pFreeAct->yposi.w.h = pActwk->yposi.w.h; /* Line 516, Address: 0x1016830 */
    }

    playdamagechk(pActwk, pColliAct); /* Line 519, Address: 0x1016840 */
    return -1; /* Line 520, Address: 0x1016850 */
  }

  if (debugflag.w != 0) /* Line 523, Address: 0x101685c */
  {
    playdamagechk(pActwk, pColliAct); /* Line 525, Address: 0x1016874 */
    return -1; /* Line 526, Address: 0x1016884 */
  }
  playdieset(pActwk); /* Line 528, Address: 0x1016890 */
} /* Line 529, Address: 0x101689c */












short playdieset(sprite_status* pActwk) { /* Line 542, Address: 0x10168b0 */
  if (editmode.w != 0) /* Line 543, Address: 0x10168bc */
    return -1; /* Line 544, Address: 0x10168d4 */
  plpower_m = 0; /* Line 545, Address: 0x10168e0 */
  pActwk->r_no0 = 6; /* Line 546, Address: 0x10168e8 */
  jumpcolsub(); /* Line 547, Address: 0x10168f4 */
  pActwk->cddat |= 2; /* Line 548, Address: 0x10168fc */
  pActwk->yspeed.w = -1792; /* Line 549, Address: 0x101690c */
  pActwk->xspeed.w = 0; /* Line 550, Address: 0x1016918 */
  pActwk->mspeed.w = 0; /* Line 551, Address: 0x1016920 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h; /* Line 552, Address: 0x1016928 */
  pActwk->mstno.b.h = 24; /* Line 553, Address: 0x1016938 */
  pActwk->sproffset |= 32768; /* Line 554, Address: 0x1016944 */
  pActwk->sprpri = 0; /* Line 555, Address: 0x1016954 */
  soundset(147); /* Line 556, Address: 0x101695c */
  return -1; /* Line 557, Address: 0x1016968 */
} /* Line 558, Address: 0x101696c */
















short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 575, Address: 0x1016980 */
  char cColiNo = pColliAct->colino & 63; /* Line 576, Address: 0x1016994 */

  switch (cColiNo) /* Line 578, Address: 0x10169b4 */
  {
    case 31:
    case 35:
      ++pColliAct->colicnt; /* Line 582, Address: 0x1016a00 */
      break; /* Line 583, Address: 0x1016a10 */
    case 56:
    case 58:
    case 59:
      main_attack(pActwk, pColliAct); /* Line 587, Address: 0x1016a18 */
      break; /* Line 588, Address: 0x1016a28 */
    default:
      eggman_chk(pActwk, pColliAct, cColiNo); /* Line 590, Address: 0x1016a30 */
      break;
  }
  return -1; /* Line 593, Address: 0x1016a44 */
} /* Line 594, Address: 0x1016a48 */
















short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 611, Address: 0x1016a60 */

  if (bossstart != 1) return -1; /* Line 613, Address: 0x1016a74 */
  switch (bossstart) /* Line 614, Address: 0x1016a98 */
  {
    case 1:
      boss_1(pActwk, pColliAct, cColiNo); /* Line 617, Address: 0x1016ad0 */
      break; /* Line 618, Address: 0x1016ae4 */
    case 4:
      boss_4(pActwk, pColliAct, cColiNo); /* Line 620, Address: 0x1016aec */
      break; /* Line 621, Address: 0x1016b00 */
    case 5:
      boss_5(pActwk, pColliAct, cColiNo); /* Line 623, Address: 0x1016b08 */
      break; /* Line 624, Address: 0x1016b1c */
    default:
      boss_1(pActwk, pColliAct, cColiNo); /* Line 626, Address: 0x1016b24 */
      break;
  }
  return 1; /* Line 629, Address: 0x1016b38 */
} /* Line 630, Address: 0x1016b3c */















void boss_1(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 646, Address: 0x1016b50 */
  if (cColiNo < 60 || cColiNo > 63) /* Line 647, Address: 0x1016b64 */
    return; /* Line 648, Address: 0x1016b94 */






  pcolnomal(pActwk, pColliAct); /* Line 655, Address: 0x1016b9c */
  if (pColliAct->colino == 0) /* Line 656, Address: 0x1016bac */
    pColliAct->colicnt += 3; /* Line 657, Address: 0x1016bc0 */
  pColliAct->colino = 0; /* Line 658, Address: 0x1016bd0 */

  ++pColliAct->colicnt; /* Line 660, Address: 0x1016bd8 */
} /* Line 661, Address: 0x1016be8 */















void boss_4(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 677, Address: 0x1016c00 */
  if (cColiNo == 63) /* Line 678, Address: 0x1016c14 */
  {

    if (!(pActwk->cddat & 20)) return; /* Line 681, Address: 0x1016c2c */

    pActwk->cddat &= 251; /* Line 683, Address: 0x1016c44 */
    pActwk->cddat &= 239; /* Line 684, Address: 0x1016c54 */
    pActwk->colino = 0; /* Line 685, Address: 0x1016c64 */
    pActwk->mstno.b.h = 21; /* Line 686, Address: 0x1016c6c */

    pActwk->yspeed.w = 1024; /* Line 688, Address: 0x1016c78 */
    pActwk->xspeed.w = -512; /* Line 689, Address: 0x1016c84 */
    if (pActwk->xposi.w.h >= pColliAct->xposi.w.h) /* Line 690, Address: 0x1016c90 */
      pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 691, Address: 0x1016cbc */
  } /* Line 692, Address: 0x1016ce0 */
  else if (cColiNo == 62) /* Line 693, Address: 0x1016ce8 */
  {
    pcolplay(pActwk, pColliAct); /* Line 695, Address: 0x1016d00 */
    ++pColliAct->colicnt; /* Line 696, Address: 0x1016d10 */
  }
} /* Line 698, Address: 0x1016d20 */














void boss_5(sprite_status* pActwk, sprite_status* pColliAct, char cColiNo) { /* Line 713, Address: 0x1016d30 */
  if (cColiNo == 61) /* Line 714, Address: 0x1016d44 */
  {
    pcolplay(pActwk, pColliAct); /* Line 716, Address: 0x1016d5c */
    ++pColliAct->colicnt; /* Line 717, Address: 0x1016d6c */
  }
} /* Line 719, Address: 0x1016d7c */














void main_attack(sprite_status* pActwk, sprite_status* pColliAct) { /* Line 734, Address: 0x1016d90 */
  if (pActwk->mstno.b.h == 2) /* Line 735, Address: 0x1016d9c */
    ++pColliAct->colicnt; /* Line 736, Address: 0x1016db8 */
} /* Line 737, Address: 0x1016dc8 */
