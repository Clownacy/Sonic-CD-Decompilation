#include "..\EQU.H"
#include "EMIE7.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\GOAL.H"
#include "..\LOADER2.H"

void actionsub(sprite_status* pActwk);
void frameout(sprite_status* pActwk);

static void emie7_init(sprite_status* pActwk);
static void emie7_move0(sprite_status* pActwk);
static void emie7_move1(sprite_status* pActwk);
static void emie7_tobii(sprite_status* pActwk);
static void emie7_tobim(sprite_status* pActwk);
static void emie7_daki2(sprite_status* pActwk);
static void emie7_end(sprite_status* pActwk);
static void setdirect(sprite_status* pEmiewk, sprite_status* pSonicwk);
static void speedset(sprite_status* pActwk);
static void speedsetx(sprite_status* pActwk);
static void speedsety(sprite_status* pActwk);
static void dakicheck(sprite_status* pActwk);
static void empatchg(sprite_status* pActwk, char** pPattbl);
static void emie7clrsetx(PALETTEENTRY* pPalet);
static void heartset(sprite_status* pActwk);
static void heart1_init(sprite_status* pActwk);
static void heart1_move(sprite_status* pActwk);

static void(*em7_tbl[9])(sprite_status*) = {
  &emie7_init,
  &emie7_move0,
  &emie7_move1,
  &emie7_move1,
  &emie7_tobim,
  &emie7_daki2,
  &emie7_end,
  &emie7_tobii,
  &emie7_tobim
};
extern PALETTEENTRY gamecolor[];
extern char* em_pchg[];
extern sprite_pattern* emie7pat[];
static void(*ht1_tbl[2])(sprite_status*) = {
  &heart1_init,
  &heart1_move
};



































































































void emie7(sprite_status* pActwk) { /* Line 147, Address: 0x10228b0 */
  em7_tbl[pActwk->r_no0 / 2](pActwk); /* Line 148, Address: 0x10228bc */
  actionsub(pActwk); /* Line 149, Address: 0x1022900 */
  frameout_s(pActwk); /* Line 150, Address: 0x102290c */

  if (pActwk->actno != 51) { /* Line 152, Address: 0x1022918 */
    emie7clrsetx(&gamecolor[16]); /* Line 153, Address: 0x1022930 */
  }
} /* Line 155, Address: 0x1022940 */





static void emie7_init(sprite_status* pActwk) { /* Line 161, Address: 0x1022950 */
  sprite_status* pNewact;

  pActwk->actflg |= 4; /* Line 164, Address: 0x102295c */
  pActwk->sproffset = 41931; /* Line 165, Address: 0x102296c */
  pActwk->sprpri = 1; /* Line 166, Address: 0x1022978 */
  pActwk->patbase = emie7pat; /* Line 167, Address: 0x1022984 */

  pActwk->sprhsize = 12; /* Line 169, Address: 0x1022994 */
  pActwk->sprvsize = 16; /* Line 170, Address: 0x10229a0 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 171, Address: 0x10229ac */
  pActwk->colino = 245; /* Line 172, Address: 0x10229bc */

  if (!generate_flag) { /* Line 174, Address: 0x10229c8 */
    pActwk->xposi.w.h = 16195; /* Line 175, Address: 0x10229d8 */
    pActwk->yposi.w.h = 427; /* Line 176, Address: 0x10229e4 */
  }


  pActwk->mstno.b.h = 6; /* Line 180, Address: 0x10229f0 */
  if (pActwk->colicnt) { /* Line 181, Address: 0x10229fc */
    if (actwkchk(&pNewact) == 0) { /* Line 182, Address: 0x1022a0c */
      pNewact->actno = 24; /* Line 183, Address: 0x1022a20 */
      pNewact->r_no1 = 1; /* Line 184, Address: 0x1022a2c */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 185, Address: 0x1022a38 */
      pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 186, Address: 0x1022a48 */
      soundset(158); /* Line 187, Address: 0x1022a58 */
    }


    actwk[0].yspeed.w *= -1; /* Line 191, Address: 0x1022a64 */
    pActwk->r_no0 += 2; /* Line 192, Address: 0x1022a78 */
    ((short*)pActwk)[26] = 600; /* Line 193, Address: 0x1022a88 */
  } /* Line 194, Address: 0x1022a94 */
  else {
    empatchg(pActwk, em_pchg); /* Line 196, Address: 0x1022a9c */
  }
} /* Line 198, Address: 0x1022ab0 */





static void emie7_move0(sprite_status* pActwk) { /* Line 204, Address: 0x1022ac0 */
  if (((char*)pActwk)[64] >= 0) { /* Line 205, Address: 0x1022acc */

    pActwk->yspeed.w += 16; /* Line 207, Address: 0x1022ae4 */
    speedsety(pActwk); /* Line 208, Address: 0x1022af4 */

    if (pActwk->yposi.w.h >= 464) { /* Line 210, Address: 0x1022b00 */
      pActwk->yposi.w.h = 464; /* Line 211, Address: 0x1022b1c */
      pActwk->yspeed.w = 0; /* Line 212, Address: 0x1022b28 */
      ((char*)pActwk)[64] = -1; /* Line 213, Address: 0x1022b30 */
    }
  } /* Line 215, Address: 0x1022b3c */
  else {
    setdirect(pActwk, &actwk[0]); /* Line 217, Address: 0x1022b44 */
    pActwk->actfree[21] = 60; /* Line 218, Address: 0x1022b58 */
    pActwk->r_no0 += 2; /* Line 219, Address: 0x1022b64 */
    empatchg(pActwk, em_pchg); /* Line 220, Address: 0x1022b74 */
  }
} /* Line 222, Address: 0x1022b88 */





static void emie7_move1(sprite_status* pActwk) { /* Line 228, Address: 0x1022ba0 */
  short lenwk, maxspd, spdwk, scdwk;

  heartset(pActwk); /* Line 231, Address: 0x1022bbc */
  setdirect(pActwk, &actwk[0]); /* Line 232, Address: 0x1022bc8 */

  if (((short*)pActwk)[26]) { /* Line 234, Address: 0x1022bdc */
    if (!(--((short*)pActwk)[26])) { /* Line 235, Address: 0x1022bec */

      ((char*)pActwk)[60] = -1; /* Line 237, Address: 0x1022c0c */
      pltime_f = 0; /* Line 238, Address: 0x1022c18 */
      pActwk->actfree[0] = 1; /* Line 239, Address: 0x1022c20 */
      goal_move2(pActwk); /* Line 240, Address: 0x1022c2c */
      return; /* Line 241, Address: 0x1022c38 */
    }
  }


  if (!pActwk->actfree[21] || !(--pActwk->actfree[21])) { /* Line 246, Address: 0x1022c40 */

    dakicheck(pActwk); /* Line 248, Address: 0x1022c6c */


    if ((lenwk = actwk[0].xposi.w.h - pActwk->xposi.w.h) < 0) { /* Line 251, Address: 0x1022c78 */
      lenwk *= -1; /* Line 252, Address: 0x1022cc4 */
    }


    if (((pActwk->actfree[20] & 4) && lenwk < 32) /* Line 256, Address: 0x1022cd0 */
        ||
        (!(actwk[0].xspeed.w) && lenwk < 10)) {
      pActwk->actfree[20] |= 4; /* Line 259, Address: 0x1022d20 */
      pActwk->xspeed.w = 0; /* Line 260, Address: 0x1022d30 */


      pActwk->mstno.b.h = 1; /* Line 263, Address: 0x1022d38 */
      empatchg(pActwk, em_pchg); /* Line 264, Address: 0x1022d44 */
      return; /* Line 265, Address: 0x1022d58 */
    }
  }


  spdwk = -32; /* Line 270, Address: 0x1022d60 */
  if (!(pActwk->cddat & 1)) { /* Line 271, Address: 0x1022d6c */
    spdwk *= -1; /* Line 272, Address: 0x1022d84 */
  }


  spdwk += pActwk->xspeed.w; /* Line 276, Address: 0x1022d90 */
  lenwk = spdwk; /* Line 277, Address: 0x1022da4 */
  maxspd = 640; /* Line 278, Address: 0x1022dac */

  if (lenwk < 0) { /* Line 280, Address: 0x1022db8 */
    lenwk *= -1; /* Line 281, Address: 0x1022dc8 */
    maxspd *= -1; /* Line 282, Address: 0x1022dd4 */
  }


  if (lenwk >= 640) { /* Line 286, Address: 0x1022de0 */
    spdwk = maxspd; /* Line 287, Address: 0x1022df4 */
  }


  pActwk->xspeed.w = spdwk; /* Line 291, Address: 0x1022dfc */


  if (pActwk->xspeed.w < 0) { /* Line 294, Address: 0x1022e04 */

    lenwk = ((short*)pActwk)[29]; /* Line 296, Address: 0x1022e1c */

    if (generate_flag) { /* Line 298, Address: 0x1022e2c */
      lenwk -= 96; /* Line 299, Address: 0x1022e3c */
    } else { /* Line 300, Address: 0x1022e48 */
      lenwk -= 128; /* Line 301, Address: 0x1022e50 */
    }

    if (lenwk >= pActwk->xposi.w.h) { /* Line 304, Address: 0x1022e5c */

      pActwk->xspeed.w = 0; /* Line 306, Address: 0x1022e80 */


      pActwk->mstno.b.h = 1; /* Line 309, Address: 0x1022e88 */
      empatchg(pActwk, em_pchg); /* Line 310, Address: 0x1022e94 */
      return; /* Line 311, Address: 0x1022ea8 */
    }
  }


  scdwk = emycol_d(pActwk); /* Line 316, Address: 0x1022eb0 */
  if (scdwk < 7 && scdwk >= -7) { /* Line 317, Address: 0x1022ec4 */
    pActwk->yposi.w.h += scdwk; /* Line 318, Address: 0x1022eec */
  }


  speedsetx(pActwk); /* Line 322, Address: 0x1022efc */

  pActwk->mstno.b.h = 2; /* Line 324, Address: 0x1022f08 */
  empatchg(pActwk, em_pchg); /* Line 325, Address: 0x1022f14 */

} /* Line 327, Address: 0x1022f28 */




static void emie7_tobii(sprite_status* pActwk) { /* Line 332, Address: 0x1022f50 */
  short lenwk;

  pActwk->patno = 6; /* Line 335, Address: 0x1022f60 */

  if ((lenwk = pActwk->xposi.w.h - ((short*)pActwk)[29]) < 0) { /* Line 337, Address: 0x1022f6c */

    lenwk = -lenwk; /* Line 339, Address: 0x1022fb8 */
  }

  if (lenwk >= 128) { /* Line 342, Address: 0x1022fd4 */
    pActwk->xspeed.w = 0; /* Line 343, Address: 0x1022fe8 */
  } else { /* Line 344, Address: 0x1022ff0 */
    if (pActwk->cddat & 1) { /* Line 345, Address: 0x1022ff8 */

      pActwk->xspeed.w = 128; /* Line 347, Address: 0x1023010 */
    } else { /* Line 348, Address: 0x102301c */
      pActwk->xspeed.w = -128; /* Line 349, Address: 0x1023024 */
    }
  }

  pActwk->yspeed.w = -768; /* Line 353, Address: 0x1023030 */
  pActwk->r_no0 += 2; /* Line 354, Address: 0x102303c */

  emie7_tobim(pActwk); /* Line 356, Address: 0x102304c */
} /* Line 357, Address: 0x1023058 */





static void emie7_tobim(sprite_status* pActwk) { /* Line 363, Address: 0x1023070 */
  speedset(pActwk); /* Line 364, Address: 0x102307c */
  if ((pActwk->yspeed.w += 64) >= 0) { /* Line 365, Address: 0x1023088 */
    pActwk->patno = 7; /* Line 366, Address: 0x10230b0 */
  }

  if (pActwk->yposi.w.h >= 464) { /* Line 369, Address: 0x10230bc */

    pActwk->yposi.w.h = 464; /* Line 371, Address: 0x10230d8 */
    pActwk->xspeed.w = 0; /* Line 372, Address: 0x10230e4 */
    pActwk->yspeed.w = 0; /* Line 373, Address: 0x10230ec */

    if ((short)pActwk->actfree[16] + 16 < 256) { /* Line 375, Address: 0x10230f4 */
      pActwk->actfree[16] += 16; /* Line 376, Address: 0x1023118 */
      return; /* Line 377, Address: 0x1023128 */
    }

    pActwk->actfree[16] += 16; /* Line 380, Address: 0x1023130 */
    pActwk->r_no0 = 4; /* Line 381, Address: 0x1023140 */
  }
} /* Line 383, Address: 0x102314c */





static void emie7_daki2(sprite_status* pActwk) { /* Line 389, Address: 0x1023160 */
  heartset(pActwk); /* Line 390, Address: 0x102316c */

  plautoflag |= 1; /* Line 392, Address: 0x1023178 */
  swdata.w = 0; /* Line 393, Address: 0x102318c */
  actwk[0].mstno.b.h = 5; /* Line 394, Address: 0x1023194 */
  setdirect(pActwk, &actwk[0]); /* Line 395, Address: 0x10231a0 */

  if (actwk[0].cddat & 1) { /* Line 397, Address: 0x10231b4 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h + 12; /* Line 398, Address: 0x10231cc */
  } else { /* Line 399, Address: 0x10231f0 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h - 12; /* Line 400, Address: 0x10231f8 */
  }

  pActwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 403, Address: 0x102321c */
  pActwk->patno = 14; /* Line 404, Address: 0x102322c */
  if (!pActwk->actfree[14]) { /* Line 405, Address: 0x1023238 */
    pltime_f = 0; /* Line 406, Address: 0x1023248 */
    pActwk->actfree[0] = 1; /* Line 407, Address: 0x1023250 */
    goal_move2(pActwk); /* Line 408, Address: 0x102325c */
  }
} /* Line 410, Address: 0x1023268 */





static void emie7_end(sprite_status* pActwk) { /* Line 416, Address: 0x1023280 */
  heartset(pActwk); /* Line 417, Address: 0x102328c */
  setdirect(pActwk, &actwk[0]); /* Line 418, Address: 0x1023298 */

  if (actwk[0].cddat & 1) { /* Line 420, Address: 0x10232ac */
    pActwk->xposi.w.h = actwk[0].xposi.w.h + 12; /* Line 421, Address: 0x10232c4 */
  } else { /* Line 422, Address: 0x10232e8 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h - 12; /* Line 423, Address: 0x10232f0 */
  }

  pActwk->patno = 14; /* Line 426, Address: 0x1023314 */
} /* Line 427, Address: 0x1023320 */
















static void setdirect(sprite_status* pEmiewk, sprite_status* pSonicwk) { /* Line 444, Address: 0x1023330 */
  if (pEmiewk->xposi.w.h < pSonicwk->xposi.w.h) { /* Line 445, Address: 0x102333c */

    pEmiewk->cddat &= 254; /* Line 447, Address: 0x1023368 */
    pEmiewk->actflg &= 254; /* Line 448, Address: 0x1023378 */
  } /* Line 449, Address: 0x1023388 */
  else {
    pEmiewk->cddat |= 1; /* Line 451, Address: 0x1023390 */
    pEmiewk->actflg |= 1; /* Line 452, Address: 0x10233a0 */
  }
} /* Line 454, Address: 0x10233b0 */











static void speedset(sprite_status* pActwk) { /* Line 466, Address: 0x10233c0 */
  speedsetx(pActwk); /* Line 467, Address: 0x10233cc */
  speedsety(pActwk); /* Line 468, Address: 0x10233d8 */
} /* Line 469, Address: 0x10233e4 */


static void speedsetx(sprite_status* pActwk) { /* Line 472, Address: 0x1023400 */
  pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 473, Address: 0x1023408 */
} /* Line 474, Address: 0x102342c */


static void speedsety(sprite_status* pActwk) { /* Line 477, Address: 0x1023440 */
  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 478, Address: 0x1023448 */
} /* Line 479, Address: 0x102346c */











static void dakicheck(sprite_status* pActwk) { /* Line 491, Address: 0x1023480 */
  short spdwk, poswk1, poswk2;

  if (editmode.b.h) return; /* Line 494, Address: 0x1023498 */






  if (actwk[0].cddat & 1) { /* Line 501, Address: 0x10234a8 */

    poswk1 = actwk[0].xposi.w.h; /* Line 503, Address: 0x10234c0 */
    poswk2 = pActwk->xposi.w.h; /* Line 504, Address: 0x10234d0 */
  } else { /* Line 505, Address: 0x10234e0 */
    poswk1 = pActwk->xposi.w.h; /* Line 506, Address: 0x10234e8 */
    poswk2 = actwk[0].xposi.w.h; /* Line 507, Address: 0x10234f8 */
  }


  if (poswk1 < poswk2) return; /* Line 511, Address: 0x1023508 */



  if ((poswk1 -= poswk2) < 8 || poswk1 >= 28) { /* Line 515, Address: 0x1023524 */
    return; /* Line 516, Address: 0x1023560 */
  }


  poswk1 = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 520, Address: 0x1023568 */
  if ((poswk1 += 8) < 0 || poswk1 >= 16) { /* Line 521, Address: 0x102359c */
    return; /* Line 522, Address: 0x10235d4 */
  }

  if ((spdwk = actwk[0].xspeed.w) < 0) { /* Line 525, Address: 0x10235dc */
    spdwk *= -1; /* Line 526, Address: 0x10235fc */
  }


  if ((actwk[0].cddat & 2) || (actwk[0].cddat & 4)) { /* Line 530, Address: 0x1023608 */

    pActwk->r_no0 = 14; /* Line 532, Address: 0x1023638 */
  } else { /* Line 533, Address: 0x1023644 */
    pActwk->actfree[20] |= 129; /* Line 534, Address: 0x102364c */
    pActwk->xspeed.w = pActwk->yspeed.w = 0; /* Line 535, Address: 0x102365c */
    pActwk->patno = 7; /* Line 536, Address: 0x1023674 */
    pActwk->r_no0 = 10; /* Line 537, Address: 0x1023680 */

    sub_sync(124); /* Line 539, Address: 0x102368c */
  }
} /* Line 541, Address: 0x1023698 */












static void empatchg(sprite_status* pActwk, char** pPattbl) { /* Line 554, Address: 0x10236c0 */
  char *pPatdat, patnowk;

  if (pActwk->mstno.b.h != pActwk->mstno.b.l) { /* Line 557, Address: 0x10236d4 */

    pActwk->mstno.b.l = pActwk->mstno.b.h; /* Line 559, Address: 0x10236fc */
    pActwk->patcnt = 0; /* Line 560, Address: 0x102370c */
    pActwk->pattim = 0; /* Line 561, Address: 0x1023714 */
  }

  if ((char)--pActwk->pattim <= 0) { /* Line 564, Address: 0x102371c */
    pPatdat = pPattbl[pActwk->mstno.b.l]; /* Line 565, Address: 0x1023748 */
    if ((patnowk = pPatdat[pActwk->patcnt]) < 0) { /* Line 566, Address: 0x1023768 */

      pActwk->patcnt = 0; /* Line 568, Address: 0x1023794 */
      patnowk = pPatdat[pActwk->patcnt]; /* Line 569, Address: 0x102379c */
    }


    pActwk->patno = patnowk & 31; /* Line 573, Address: 0x10237b8 */


    pActwk->actflg &= 252; /* Line 576, Address: 0x10237d0 */
    pActwk->actflg |= (pActwk->cddat ^ (patnowk << 3 | patnowk >> 5)) & 3; /* Line 577, Address: 0x10237e0 */



    pActwk->pattim = pPatdat[pActwk->patcnt + 1]; /* Line 581, Address: 0x1023824 */


    pActwk->patcnt += 2; /* Line 584, Address: 0x1023844 */
  }
} /* Line 586, Address: 0x1023854 */











static void emie7clrsetx(PALETTEENTRY* pPalet) { /* Line 598, Address: 0x1023870 */
  PALETTEENTRY* pColorwk;
  short i;

  pColorwk = &lpcolorwk[16]; /* Line 602, Address: 0x1023880 */

  for (i = 0; i < 16; ++i) { /* Line 604, Address: 0x102388c */
    *pColorwk = *pPalet; /* Line 605, Address: 0x1023898 */
    ++pColorwk; /* Line 606, Address: 0x10238bc */
    ++pPalet; /* Line 607, Address: 0x10238c0 */
  } /* Line 608, Address: 0x10238cc */
} /* Line 609, Address: 0x10238ec */











static void heartset(sprite_status* pActwk) { /* Line 621, Address: 0x1023900 */
  sprite_status* pHeartact;
  short wk;

  if (pActwk->actfree[17] + 6 > 255) { /* Line 625, Address: 0x1023910 */
    if (actwkchk(&pHeartact) == 0) { /* Line 626, Address: 0x102392c */
      pHeartact->actno = 52; /* Line 627, Address: 0x1023940 */
      wk = 8; /* Line 628, Address: 0x102394c */

      if (pActwk->cddat & 1) { /* Line 630, Address: 0x1023958 */
        wk = -10; /* Line 631, Address: 0x1023970 */
      }


      if (pActwk->actfree[20] & 1) { /* Line 635, Address: 0x102397c */
        wk *= -1; /* Line 636, Address: 0x1023994 */
      }


      pHeartact->xposi.w.h = pActwk->xposi.w.h + wk; /* Line 640, Address: 0x10239a0 */
      pHeartact->yposi.w.h = pActwk->yposi.w.h - 12; /* Line 641, Address: 0x10239cc */
    }
  }


  pActwk->actfree[17] += 6; /* Line 646, Address: 0x10239f0 */
} /* Line 647, Address: 0x1023a00 */




















void heart7(sprite_status* pActwk) { /* Line 668, Address: 0x1023a20 */
  ht1_tbl[pActwk->r_no0 / 2](pActwk); /* Line 669, Address: 0x1023a2c */
  actionsub(pActwk); /* Line 670, Address: 0x1023a70 */
  frameout_s(pActwk); /* Line 671, Address: 0x1023a7c */
} /* Line 672, Address: 0x1023a88 */





static void heart1_init(sprite_status* pActwk) { /* Line 678, Address: 0x1023aa0 */
  pActwk->r_no0 += 2; /* Line 679, Address: 0x1023aac */
  pActwk->actflg |= 4; /* Line 680, Address: 0x1023abc */
  pActwk->sproffset = 971; /* Line 681, Address: 0x1023acc */
  pActwk->patbase = emie7pat; /* Line 682, Address: 0x1023ad8 */
  pActwk->patno = 8; /* Line 683, Address: 0x1023ae8 */
  pActwk->yspeed.w = -96; /* Line 684, Address: 0x1023af4 */
  pActwk->sprpri = 3; /* Line 685, Address: 0x1023b00 */

  heart1_move(pActwk); /* Line 687, Address: 0x1023b0c */
} /* Line 688, Address: 0x1023b18 */





static void heart1_move(sprite_status* pActwk) { /* Line 694, Address: 0x1023b30 */
  short sinwk, coswk;

  if (!pActwk->actfree[18]) { /* Line 697, Address: 0x1023b3c */
    sinset(pActwk->actfree[16] * 3, &sinwk, &coswk); /* Line 698, Address: 0x1023b4c */
    pActwk->xspeed.w = sinwk >> 2; /* Line 699, Address: 0x1023b74 */
  }


  speedset(pActwk); /* Line 703, Address: 0x1023b94 */
  if (++pActwk->actfree[16] == 20) { /* Line 704, Address: 0x1023ba0 */
    ++pActwk->patno; /* Line 705, Address: 0x1023bc4 */
  } else if (pActwk->actfree[16] == 110) { /* Line 706, Address: 0x1023bd4 */
    ++pActwk->patno; /* Line 707, Address: 0x1023bf4 */
    pActwk->xspeed.w = pActwk->yspeed.w = 0; /* Line 708, Address: 0x1023c04 */
    pActwk->actfree[18] = 1; /* Line 709, Address: 0x1023c1c */
  } else if (pActwk->actfree[16] == 120) { /* Line 710, Address: 0x1023c28 */
    frameout(pActwk); /* Line 711, Address: 0x1023c48 */
  }
} /* Line 713, Address: 0x1023c54 */
