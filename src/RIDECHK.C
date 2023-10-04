#include "EQU.H"
#include "RIDECHK.H"
#include "DIRCOL.H"

extern void soundset(short ReqNo);
extern short playdieset(act_info* pActwk);



























































short ride_on_clr(act_info* pActwk, act_info* pPlayerwk) { /* Line 66, Address: 0x1019540 */
  unsigned short wActwkNo;
  unsigned char byPlwk;

  if (!(pActwk->cddat & 8)) /* Line 70, Address: 0x1019558 */
    return -1; /* Line 71, Address: 0x1019570 */
  if (!(pPlayerwk->cddat & 8)) /* Line 72, Address: 0x101957c */
    return -1; /* Line 73, Address: 0x1019594 */

  wActwkNo = pPlayerwk->actfree[19]; /* Line 75, Address: 0x10195a0 */

  if ((unsigned short)(pActwk - actwk) != wActwkNo) /* Line 77, Address: 0x10195b0 */
    return -1; /* Line 78, Address: 0x10195ec */

  if (pPlayerwk->actfree[0] != 0) /* Line 80, Address: 0x10195f8 */
    soundset(171); /* Line 81, Address: 0x101960c */

  pPlayerwk->actfree[14] = 0; /* Line 83, Address: 0x1019618 */
  pPlayerwk->cddat |= 2; /* Line 84, Address: 0x1019620 */
  pPlayerwk->cddat &= 247; /* Line 85, Address: 0x1019630 */
  pActwk->cddat &= 247; /* Line 86, Address: 0x1019640 */
  byPlwk = pPlayerwk->actfree[2]; /* Line 87, Address: 0x1019650 */
  if (!(byPlwk & 64)) /* Line 88, Address: 0x101965c */
    if (pPlayerwk->mstno.b.h != 23) /* Line 89, Address: 0x101966c */
      byPlwk &= 254; /* Line 90, Address: 0x1019688 */

  pPlayerwk->actfree[2] = byPlwk; /* Line 92, Address: 0x1019690 */
  pPlayerwk->actfree[19] = 0; /* Line 93, Address: 0x1019698 */
  if (pPlayerwk->mstno.b.h == 43) /* Line 94, Address: 0x10196a0 */
    pPlayerwk->cddat &= 253; /* Line 95, Address: 0x10196bc */
  return 0; /* Line 96, Address: 0x10196cc */
} /* Line 97, Address: 0x10196d0 */














short ride_on_set(act_info* pActwk, act_info* pPlayerwk) { /* Line 112, Address: 0x10196f0 */
  unsigned char byCCR;
  unsigned short wActwkNo;
  act_info* pRideAct;

  if (pPlayerwk->r_no0 == 4) /* Line 117, Address: 0x101970c */
  {
    pPlayerwk->r_no0 -= 2; /* Line 119, Address: 0x1019724 */
    ((short*)pPlayerwk)[26] = 120; /* Line 120, Address: 0x1019734 */
  }

  pActwk->r_no1 = 0; /* Line 123, Address: 0x1019740 */
  pPlayerwk->actfree[18] = 0; /* Line 124, Address: 0x1019748 */

  if (!(pActwk->cddat & 8)) byCCR = 0; /* Line 126, Address: 0x1019750 */
  else byCCR = 1; /* Line 127, Address: 0x1019774 */
  pActwk->cddat |= 8; /* Line 128, Address: 0x101977c */
  if (byCCR == 0) /* Line 129, Address: 0x101978c */
  {
    if (pPlayerwk->mstno.b.h == 43) /* Line 131, Address: 0x1019798 */
    {
      pActwk->cddat &= 247; /* Line 133, Address: 0x10197b4 */
      return ride_on_clr(pActwk, pPlayerwk); /* Line 134, Address: 0x10197c4 */
    }



    pPlayerwk->cddat &= 239; /* Line 139, Address: 0x10197dc */
    if (!(pPlayerwk->cddat & 4)) byCCR = 0; /* Line 140, Address: 0x10197ec */
    else byCCR = 1; /* Line 141, Address: 0x1019810 */
    pPlayerwk->cddat &= 251; /* Line 142, Address: 0x1019818 */
    if (byCCR == 1) /* Line 143, Address: 0x1019828 */
    {
      if (chibi_flag != 0) /* Line 145, Address: 0x1019838 */
      {
        pPlayerwk->sprvsize = 10; /* Line 147, Address: 0x101984c */
        pPlayerwk->sprhs = 5; /* Line 148, Address: 0x1019858 */
        pPlayerwk->yposi.w.h -= 2; /* Line 149, Address: 0x1019864 */
      } /* Line 150, Address: 0x1019874 */
      else
      {

        pPlayerwk->sprvsize = 19; /* Line 154, Address: 0x101987c */
        pPlayerwk->sprhs = 9; /* Line 155, Address: 0x1019888 */
        pPlayerwk->yposi.w.h -= 5; /* Line 156, Address: 0x1019894 */
      }

      pPlayerwk->mstno.b.h = 0; /* Line 159, Address: 0x10198a4 */
    }
  }


  if (!(pPlayerwk->cddat & 8)) byCCR = 0; /* Line 164, Address: 0x10198ac */
  else byCCR = 1; /* Line 165, Address: 0x10198d0 */
  pPlayerwk->cddat |= 8; /* Line 166, Address: 0x10198d8 */
  if (byCCR == 1) /* Line 167, Address: 0x10198e8 */
  {
    wActwkNo = pPlayerwk->actfree[19]; /* Line 169, Address: 0x10198f8 */
    if ((unsigned short)(pActwk - actwk) == wActwkNo) /* Line 170, Address: 0x1019908 */
      return -1; /* Line 171, Address: 0x1019944 */
    pRideAct = &actwk[wActwkNo]; /* Line 172, Address: 0x1019950 */
    pRideAct->cddat &= 247; /* Line 173, Address: 0x101996c */
  }

  pPlayerwk->actfree[19] = pActwk - actwk; /* Line 176, Address: 0x1019978 */
  pPlayerwk->direc.w = 0; /* Line 177, Address: 0x10199ac */
  pPlayerwk->yspeed.w = 0; /* Line 178, Address: 0x10199b4 */

  if (pActwk->actno != 10 || pActwk->r_no0 != 2) /* Line 180, Address: 0x10199bc */
    pPlayerwk->mspeed.w = pPlayerwk->xspeed.w; /* Line 181, Address: 0x10199ec */

  pPlayerwk->cddat &= 253; /* Line 183, Address: 0x10199fc */
  return 0; /* Line 184, Address: 0x1019a0c */
} /* Line 185, Address: 0x1019a10 */















short hitchk_u(act_info* pActwk, act_info* pPlayerwk) { /* Line 201, Address: 0x1019a30 */
  pActwk->r_no1 = 2; /* Line 202, Address: 0x1019a40 */
  ride_on_chk(pActwk, pPlayerwk); /* Line 203, Address: 0x1019a4c */
} /* Line 204, Address: 0x1019a5c */















short ridechk(act_info* pActwk, act_info* pPlayerwk) { /* Line 220, Address: 0x1019a70 */
  pActwk->r_no1 = 1; /* Line 221, Address: 0x1019a80 */
  ride_on_chk(pActwk, pPlayerwk); /* Line 222, Address: 0x1019a8c */
} /* Line 223, Address: 0x1019a9c */













short ride_on_chk(act_info* pActwk, act_info* pPlayerwk) { /* Line 237, Address: 0x1019ab0 */
  hitchk(pActwk, pPlayerwk); /* Line 238, Address: 0x1019ac0 */
} /* Line 239, Address: 0x1019ad0 */



short hitchk(act_info* pActwk, act_info* pPlayerwk) { /* Line 243, Address: 0x1019ae0 */
  short iD0, iD1, iD2;
  unsigned char byPlflg;

  if (pPlayerwk->mstno.b.h == 23) /* Line 247, Address: 0x1019b00 */
    return hit_e(pActwk, pPlayerwk); /* Line 248, Address: 0x1019b1c */
  byPlflg = pPlayerwk->actfree[2]; /* Line 249, Address: 0x1019b34 */
  if (byPlflg & 64) /* Line 250, Address: 0x1019b40 */
    return hit_e(pActwk, pPlayerwk); /* Line 251, Address: 0x1019b50 */
  if (pPlayerwk->r_no0 >= 6) /* Line 252, Address: 0x1019b68 */
    return hit_e(pActwk, pPlayerwk); /* Line 253, Address: 0x1019b80 */
  if (pPlayerwk->actno == 0) /* Line 254, Address: 0x1019b98 */
    return hit_e(pActwk, pPlayerwk); /* Line 255, Address: 0x1019bac */
  if (!(pActwk->actflg & 128)) /* Line 256, Address: 0x1019bc4 */
    return hit_e(pActwk, pPlayerwk); /* Line 257, Address: 0x1019bdc */
  if (editmode.b.h != 0) /* Line 258, Address: 0x1019bf4 */
    return hit_e(pActwk, pPlayerwk); /* Line 259, Address: 0x1019c0c */

  iD1 = pActwk->sprhsize + 10; /* Line 261, Address: 0x1019c24 */
  iD0 = pPlayerwk->xposi.w.h - pActwk->xposi.w.h; /* Line 262, Address: 0x1019c4c */
  iD0 += iD1; /* Line 263, Address: 0x1019c80 */
  if (iD0 < 0) /* Line 264, Address: 0x1019c8c */
    return hit_e(pActwk, pPlayerwk); /* Line 265, Address: 0x1019c9c */

  iD2 = iD1; /* Line 267, Address: 0x1019cb4 */
  iD2 += iD2; /* Line 268, Address: 0x1019cbc */
  if ((unsigned short)iD0 >= (unsigned short)iD2) /* Line 269, Address: 0x1019cc8 */
    return hit_e(pActwk, pPlayerwk); /* Line 270, Address: 0x1019ce4 */

  if (pPlayerwk->mstno.b.h == 43) /* Line 272, Address: 0x1019cfc */
  {
    if (pActwk->cddat & 8) /* Line 274, Address: 0x1019d18 */
      return hit_v(pActwk, pPlayerwk, iD0, iD1); /* Line 275, Address: 0x1019d30 */
    else
      return hit_e(pActwk, pPlayerwk); /* Line 277, Address: 0x1019d50 */
  }

  if (pActwk->r_no1 != 1) /* Line 280, Address: 0x1019d68 */
    return hit_v(pActwk, pPlayerwk, iD0, iD1); /* Line 281, Address: 0x1019d80 */
  if (pPlayerwk->yspeed.w == 0) /* Line 282, Address: 0x1019da0 */
    return hit_v(pActwk, pPlayerwk, iD0, iD1); /* Line 283, Address: 0x1019db8 */
  if (pPlayerwk->yspeed.w < 0) /* Line 284, Address: 0x1019dd8 */
    return hit_e(pActwk, pPlayerwk); /* Line 285, Address: 0x1019df0 */

  return hit_v(pActwk, pPlayerwk, iD0, iD1); /* Line 287, Address: 0x1019e08 */
} /* Line 288, Address: 0x1019e20 */
















short hit_v(act_info* pActwk, act_info* pPlayerwk, short iHitXs, short iHitHs) { /* Line 305, Address: 0x1019e40 */
  short iHitYs;
  short iHitVs;
  short iD4, iD5;
  short iwk;

  if (pActwk->actno == 25 && actwk[0].cddat & 4) /* Line 311, Address: 0x1019e6c */
    iwk = -2; /* Line 312, Address: 0x1019e9c */
  else
    iwk = 2; /* Line 314, Address: 0x1019eb0 */


  iHitVs = (unsigned short)pActwk->sprvsize + (unsigned short)pPlayerwk->sprvsize + iwk; /* Line 317, Address: 0x1019ebc */







  iHitYs = pPlayerwk->yposi.w.h - pActwk->yposi.w.h; /* Line 325, Address: 0x1019f04 */
  iHitYs += iHitVs; /* Line 326, Address: 0x1019f38 */
  if (iHitYs < 0) /* Line 327, Address: 0x1019f44 */
    return hit_e(pActwk, pPlayerwk); /* Line 328, Address: 0x1019f54 */
  iD4 = iHitVs + iHitVs; /* Line 329, Address: 0x1019f6c */
  if (iHitYs >= iD4) /* Line 330, Address: 0x1019f90 */
    return hit_e(pActwk, pPlayerwk); /* Line 331, Address: 0x1019fac */

  iD4 = iHitXs; /* Line 333, Address: 0x1019fc4 */
  if (iHitHs < iHitXs) /* Line 334, Address: 0x1019fd0 */
  {
    iHitHs += iHitHs; /* Line 336, Address: 0x1019ff4 */
    iHitXs -= iHitHs; /* Line 337, Address: 0x101a004 */
    iD4 = -iHitXs; /* Line 338, Address: 0x101a014 */
  }


  iD5 = iHitYs; /* Line 342, Address: 0x101a034 */
  if (iHitVs < iHitYs) /* Line 343, Address: 0x101a03c */
  {
    iHitVs += iHitVs; /* Line 345, Address: 0x101a058 */
    iHitYs -= iHitVs; /* Line 346, Address: 0x101a064 */
    iD5 = -iHitYs; /* Line 347, Address: 0x101a070 */
  }

  if (iD5 < iD4) /* Line 350, Address: 0x101a08c */
    return hit_y(pActwk, pPlayerwk, iHitYs); /* Line 351, Address: 0x101a0a8 */

  return hit_x(pActwk, pPlayerwk, iHitXs, iD5); /* Line 353, Address: 0x101a0c4 */
} /* Line 354, Address: 0x101a0dc */


















short hit_x(act_info* pActwk, act_info* pPlayerwk, short iHitXs, short iD5) { /* Line 373, Address: 0x101a100 */
  if (pActwk->r_no1 == 1) /* Line 374, Address: 0x101a118 */
    return hit_e(pActwk, pPlayerwk); /* Line 375, Address: 0x101a130 */
  if (pActwk->actno == 10) /* Line 376, Address: 0x101a148 */
    if (pPlayerwk->cddat & 2) /* Line 377, Address: 0x101a160 */
    return hit_e(pActwk, pPlayerwk); /* Line 378, Address: 0x101a178 */

  if ((unsigned short)iD5 < 5) /* Line 380, Address: 0x101a190 */
    return hit_e(pActwk, pPlayerwk); /* Line 381, Address: 0x101a1a8 */
  hit_set(pActwk, pPlayerwk); /* Line 382, Address: 0x101a1c0 */
  ride_on_clr(pActwk, pPlayerwk); /* Line 383, Address: 0x101a1d0 */
  pActwk->r_no1 = 0; /* Line 384, Address: 0x101a1e0 */
  pPlayerwk->xposi.w.h -= iHitXs; /* Line 385, Address: 0x101a1e8 */
  if (iHitXs >= 0) /* Line 386, Address: 0x101a1fc */
  {

    if (pPlayerwk->xspeed.w > 0) /* Line 389, Address: 0x101a210 */
      return push_set(pActwk, pPlayerwk); /* Line 390, Address: 0x101a228 */
    else
      return push_clr(pActwk, pPlayerwk); /* Line 392, Address: 0x101a240 */
  }



  if (pPlayerwk->xspeed.w >= 0) /* Line 397, Address: 0x101a258 */
    return push_clr(pActwk, pPlayerwk); /* Line 398, Address: 0x101a270 */
  else
    return push_set(pActwk, pPlayerwk); /* Line 400, Address: 0x101a288 */

} /* Line 402, Address: 0x101a298 */














short push_set(act_info* pActwk, act_info* pPlayerwk) { /* Line 417, Address: 0x101a2b0 */
  side_coli(pActwk, pPlayerwk); /* Line 418, Address: 0x101a2c0 */
  if (!(pPlayerwk->cddat & 2)) /* Line 419, Address: 0x101a2d0 */
  {
    pActwk->cddat |= 32; /* Line 421, Address: 0x101a2e8 */
    pPlayerwk->cddat |= 32; /* Line 422, Address: 0x101a2f8 */
    pPlayerwk->mspeed.w = 0; /* Line 423, Address: 0x101a308 */
  }

  pPlayerwk->xspeed.w = 0; /* Line 426, Address: 0x101a310 */
  return 0; /* Line 427, Address: 0x101a318 */
} /* Line 428, Address: 0x101a31c */















short push_clr(act_info* pActwk, act_info* pPlayerwk) { /* Line 444, Address: 0x101a330 */
  hit_clr(pActwk, pPlayerwk); /* Line 445, Address: 0x101a340 */
  side_coli(pActwk, pPlayerwk); /* Line 446, Address: 0x101a350 */
  pActwk->cddat &= 223; /* Line 447, Address: 0x101a360 */
  pPlayerwk->cddat &= 223; /* Line 448, Address: 0x101a370 */
  return 0; /* Line 449, Address: 0x101a380 */
} /* Line 450, Address: 0x101a384 */
















short hit_y(act_info* pActwk, act_info* pPlayerwk, short iHitYs) { /* Line 467, Address: 0x101a3a0 */
  short iSprVchk;
  short iDirCol;
  short iD0, iD1, iD3;
  char cDirec;
  int lXspeed, lYspeed;

  if (pActwk->actno == 25 && pPlayerwk->cddat & 4) /* Line 474, Address: 0x101a3c4 */
    return hit_e(pActwk, pPlayerwk); /* Line 475, Address: 0x101a3f4 */

  iSprVchk = pActwk->sprvsize; /* Line 477, Address: 0x101a40c */
  iSprVchk += pPlayerwk->sprvsize; /* Line 478, Address: 0x101a420 */

  if (iHitYs != 0) /* Line 480, Address: 0x101a438 */
    if (iHitYs < 0) /* Line 481, Address: 0x101a44c */
      return hit_yu(pActwk, pPlayerwk, iHitYs); /* Line 482, Address: 0x101a460 */



  if (pPlayerwk->mstno.b.h != 43) /* Line 486, Address: 0x101a47c */
    if (pPlayerwk->yspeed.w != 0) /* Line 487, Address: 0x101a498 */
      if (pPlayerwk->yspeed.w < 0) return hit_e(pActwk, pPlayerwk); /* Line 488, Address: 0x101a4b0 */

  pPlayerwk->yposi.w.h = pActwk->yposi.w.h; /* Line 490, Address: 0x101a4e0 */
  pPlayerwk->yposi.w.h -= iSprVchk; /* Line 491, Address: 0x101a4f0 */
  lXspeed = pActwk->xspeed.w; /* Line 492, Address: 0x101a500 */
  lXspeed = lXspeed << 8; /* Line 493, Address: 0x101a510 */
  pPlayerwk->xposi.l += lXspeed; /* Line 494, Address: 0x101a514 */

  cDirec = -64; /* Line 496, Address: 0x101a524 */
  if (pActwk->xspeed.w < 0) /* Line 497, Address: 0x101a52c */
    cDirec = -cDirec; /* Line 498, Address: 0x101a544 */
  if (pActwk->xspeed.w != 0) /* Line 499, Address: 0x101a560 */
  {


    iDirCol = dircolm(pPlayerwk, &cDirec); /* Line 503, Address: 0x101a578 */
    if (iDirCol < 0) /* Line 504, Address: 0x101a590 */
    {
      if (pActwk->xspeed.w < 0) /* Line 506, Address: 0x101a5a0 */
        iDirCol = -iDirCol; /* Line 507, Address: 0x101a5b8 */
      pPlayerwk->xposi.w.h += iDirCol; /* Line 508, Address: 0x101a5c4 */
    }
  }



  lYspeed = pActwk->yspeed.w << 8; /* Line 514, Address: 0x101a5d4 */
  pPlayerwk->yposi.l += lYspeed; /* Line 515, Address: 0x101a5e8 */

  if (pActwk->actno != 10) /* Line 517, Address: 0x101a5f8 */
  {
    if (pActwk->yspeed.w >= 0) /* Line 519, Address: 0x101a610 */
    {
      iDirCol = dircol_d(pPlayerwk, &iD0, &iD1, &iD3); /* Line 521, Address: 0x101a628 */
      if (iDirCol < 0) /* Line 522, Address: 0x101a648 */
      {
        pPlayerwk->yposi.w.h += iDirCol; /* Line 524, Address: 0x101a658 */
        return hit_e(pActwk, pPlayerwk); /* Line 525, Address: 0x101a668 */
      }
    }

    if (pActwk->yspeed.w < 0) /* Line 529, Address: 0x101a680 */
    {
      iDirCol = dircol_u2(pPlayerwk); /* Line 531, Address: 0x101a698 */
      if (iDirCol < 0) /* Line 532, Address: 0x101a6ac */
      {
        playdieset(pPlayerwk); /* Line 534, Address: 0x101a6bc */
        return hit_e(pActwk, pPlayerwk); /* Line 535, Address: 0x101a6c8 */
      }
    }
  }

  ride_on_set(pActwk, pPlayerwk); /* Line 540, Address: 0x101a6e0 */
  return 1; /* Line 541, Address: 0x101a6f0 */
} /* Line 542, Address: 0x101a6f4 */















short hit_yu(act_info* pActwk, act_info* pPlayerwk, short iHitYs) { /* Line 558, Address: 0x101a720 */
  if (pActwk->r_no1 == 1) /* Line 559, Address: 0x101a734 */
    return hit_e(pActwk, pPlayerwk); /* Line 560, Address: 0x101a74c */
  if (pActwk->actno == 9) /* Line 561, Address: 0x101a764 */
    return hit_e(pActwk, pPlayerwk); /* Line 562, Address: 0x101a77c */
  if (pActwk->actno != 10) /* Line 563, Address: 0x101a794 */
    return hit_yu1(pActwk, pPlayerwk, iHitYs); /* Line 564, Address: 0x101a7ac */
  if (pActwk->r_no1 == 2) /* Line 565, Address: 0x101a7c8 */
    return hit_yu0(pActwk, pPlayerwk, iHitYs); /* Line 566, Address: 0x101a7e0 */
  if (pActwk->actflg & 2) /* Line 567, Address: 0x101a7fc */
    return hit_yu0(pActwk, pPlayerwk, iHitYs); /* Line 568, Address: 0x101a814 */

  return hit_e(pActwk, pPlayerwk); /* Line 570, Address: 0x101a830 */
} /* Line 571, Address: 0x101a840 */















short hit_yu1(act_info* pActwk, act_info* pPlayerwk, short iHitYs) { /* Line 587, Address: 0x101a850 */
  if (pPlayerwk->cddat & 2) /* Line 588, Address: 0x101a864 */
    return hit_yu0(pActwk, pPlayerwk, iHitYs); /* Line 589, Address: 0x101a87c */
  if (pActwk->yspeed.w <= 0) /* Line 590, Address: 0x101a898 */
    return hit_yu0(pActwk, pPlayerwk, iHitYs); /* Line 591, Address: 0x101a8b0 */
  playdieset(pPlayerwk); /* Line 592, Address: 0x101a8cc */
  return hit_yu0(pActwk, pPlayerwk, iHitYs); /* Line 593, Address: 0x101a8d8 */
} /* Line 594, Address: 0x101a8ec */















short hit_yu0(act_info* pActwk, act_info* pPlayerwk, short iHitYs) {/* Line 610, Address: 0x101a900 */
  pPlayerwk->yposi.w.h -= iHitYs;/* Line 611, Address: 0x101a914 */
  pPlayerwk->yspeed.w = 0;/* Line 612, Address: 0x101a928 */
  hit_clr(pActwk, pPlayerwk);/* Line 613, Address: 0x101a930 */
  ride_on_clr(pActwk, pPlayerwk);/* Line 614, Address: 0x101a940 */
  pActwk->r_no1 = 0;/* Line 615, Address: 0x101a950 */
  return 1;/* Line 616, Address: 0x101a958 */
}/* Line 617, Address: 0x101a95c */














short hit_e(act_info* pActwk, act_info* pPlayerwk) { /* Line 632, Address: 0x101a970 */
  hit_clr(pActwk, pPlayerwk); /* Line 633, Address: 0x101a980 */
  ride_on_clr(pActwk, pPlayerwk); /* Line 634, Address: 0x101a990 */
  pActwk->r_no1 = 0; /* Line 635, Address: 0x101a9a0 */
  return 0; /* Line 636, Address: 0x101a9a8 */
} /* Line 637, Address: 0x101a9ac */














void side_coli(act_info* pActwk, act_info* pPlayerwk) { /* Line 652, Address: 0x101a9c0 */
  char cDirect = -64; /* Line 653, Address: 0x101a9d4 */
  short iDirCol;

  if (pActwk->xspeed.w == 0) return; /* Line 656, Address: 0x101a9dc */

  if (pActwk->actno == 10) return; /* Line 658, Address: 0x101a9f4 */

  if (pActwk->xspeed.w < 0) /* Line 660, Address: 0x101aa0c */
    cDirect = -cDirect; /* Line 661, Address: 0x101aa24 */

  iDirCol = dircol(pPlayerwk, &cDirect); /* Line 663, Address: 0x101aa40 */
  if (iDirCol >= 0) return; /* Line 664, Address: 0x101aa58 */

  playdieset(pPlayerwk); /* Line 666, Address: 0x101aa68 */
} /* Line 667, Address: 0x101aa74 */














void hit_set(act_info* pActwk, act_info* pPlayerwk) { /* Line 682, Address: 0x101aa90 */
  short iHitActno;
  act_info* pHitAct;

  if (pActwk->actno == 10) /* Line 686, Address: 0x101aaa8 */
  {
    pPlayerwk->colino = 0; /* Line 688, Address: 0x101aac0 */
    return; /* Line 689, Address: 0x101aac8 */
  }

  iHitActno = (unsigned short)pPlayerwk->colino; /* Line 692, Address: 0x101aad0 */
  if (iHitActno != 0) /* Line 693, Address: 0x101aaec */
  {
    pHitAct = &actwk[iHitActno]; /* Line 695, Address: 0x101aafc */
    if (pHitAct == pActwk) return; /* Line 696, Address: 0x101ab1c */

    if (pActwk->xspeed.w == 0 && pHitAct->xspeed.w == 0) return; /* Line 698, Address: 0x101ab28 */


    if (pPlayerwk->xposi.w.h >= pActwk->xposi.w.h && pPlayerwk->xposi.w.h >= pHitAct->xposi.w.h) return; /* Line 701, Address: 0x101ab54 */




    if (pActwk->actno == 21) return; /* Line 706, Address: 0x101aba8 */





    if (stageno.w == 768 && pActwk->actno == 39 && pHitAct->actno == 39) return; /* Line 712, Address: 0x101abc0 */



    playdieset(pPlayerwk); /* Line 716, Address: 0x101ac08 */
    return; /* Line 717, Address: 0x101ac14 */
  }

  pPlayerwk->colino = pActwk - actwk; /* Line 720, Address: 0x101ac1c */
} /* Line 721, Address: 0x101ac50 */














void hit_clr(act_info* pActwk, act_info* pPlayerwk) { /* Line 736, Address: 0x101ac70 */
  unsigned short iHitAct;

  iHitAct = pPlayerwk->colino; /* Line 739, Address: 0x101ac80 */
  if (pActwk == &actwk[iHitAct]) return; /* Line 740, Address: 0x101ac90 */

  pPlayerwk->colino = 0; /* Line 742, Address: 0x101acb8 */
} /* Line 743, Address: 0x101acc0 */
