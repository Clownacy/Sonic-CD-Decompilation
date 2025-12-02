#include "..\EQU.H"
#include "BOSS_4_2.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\GOAL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\SCORE.H"
#include "PLAYSUB4.H"

typedef struct {
  char xpos;
  char ypos;
  int xspd;
  int yspd;
}
tama;

static void egg4_warai_chk(sprite_status* pActwk);
static void egg4_warai(sprite_status* pActwk);
static unsigned int egg4_ini(sprite_status* pActwk);
static void make_egg4meca(sprite_status* pActwk);
static unsigned int egg4_scrset(sprite_status* pActwk);
static unsigned int egg4_scrreset(sprite_status* pActwk);
static unsigned int egg4_awademo1(sprite_status* pActwk);
static void egg4_posiini(sprite_status* pActwk);
static void make_awa(sprite_status* pActwk, sprite_status** pNewact);
static void make_awa2(sprite_status* pActwk, sprite_status** pNewact);
static unsigned int egg4_awademo2(sprite_status* pActwk);
static unsigned int egg4_awademo3(sprite_status* pActwk);
static unsigned int egg4_movel(sprite_status* pActwk);
static void egg4_hitchk(sprite_status* pActwk);
static void make_tama(sprite_status* pActwk);
static void egg4_posiset(sprite_status* pActwk);
static unsigned int egg4_mover(sprite_status* pActwk);
static unsigned int egg4_wait(sprite_status* pActwk);
static unsigned int egg4_die(sprite_status* pActwk);
static void bom_set(sprite_status* pActwk);
static unsigned int egg4_esc(sprite_status* pActwk);
static unsigned int egg4_movec(sprite_status* pActwk);
static unsigned int egg4_movec2(sprite_status* pActwk);
static unsigned int egg4_movec3(sprite_status* pActwk);
static void egg4meca_ini(sprite_status* pActwk);
static void egg4meca_01(sprite_status* pActwk);
static unsigned int egg4awa_ini(sprite_status* pActwk);
static unsigned int egg4awa_deru(sprite_status* pActwk);
static unsigned int egg4awa_tuku(sprite_status* pActwk);
static unsigned int egg4awa_hiro(sprite_status* pActwk);
static void awa_hitchk(sprite_status* pActwk);
static unsigned int egg4awa_roll(sprite_status* pActwk);
static unsigned int egg4awa_ychg(sprite_status* pActwk);
static void ychg_ret(sprite_status* pActwk, sprite_status* pEggwk);
static void ychg_rad_endproc(sprite_status* pActwk);
static unsigned int egg4awa_del(sprite_status* pActwk);
static unsigned int egg4awa_out(sprite_status* pActwk);
static unsigned int egg4awa_chi(sprite_status* pActwk);
static unsigned int egg4tama_ini(sprite_status* pActwk);
static unsigned int egg4tama_01(sprite_status* pActwk);
static unsigned int egg4tama_02(sprite_status* pActwk);
static unsigned int egg4tama_kill(sprite_status* pActwk);
static unsigned int frameout_chk(sprite_status* pActwk);

static sprite_pattern egg4_pat0 = {
  1,
  { { -32, -28, 0, 452 } }
};
static sprite_pattern egg4_pat1 = {
  1,
  { { -32, -28, 0, 453 } }
};
static sprite_pattern egg4_pat2 = {
  1,
  { { -32, -28, 0, 454 } }
};
static sprite_pattern egg4_pat3 = {
  1,
  { { -32, -28, 0, 455 } }
};
static sprite_pattern egg4_pat4 = {
  1,
  { { -32, -28, 0, 456 } }
};
static sprite_pattern egg4_pat5 = {
  1,
  { { -32, -44, 0, 457 } }
};
static sprite_pattern egg4_pat6 = {
  1,
  { { -32, -44, 0, 458 } }
};
sprite_pattern* egg4_pat[7] = {
  &egg4_pat0,
  &egg4_pat1,
  &egg4_pat2,
  &egg4_pat3,
  &egg4_pat4,
  &egg4_pat5,
  &egg4_pat6
};
static unsigned char egg4_pchg0[3] = { 255, 0, 255 };
static unsigned char egg4_pchg1[4] = { 7, 1, 2, 255 };
static unsigned char egg4_pchg2[3] = { 255, 3, 255 };
static unsigned char egg4_pchg3[6] = { 3, 5, 4, 6, 4, 255 };
static unsigned char* egg4_pchg[4] = {
  egg4_pchg0,
  egg4_pchg1,
  egg4_pchg2,
  egg4_pchg3
};
static unsigned int(*egg4_act_tbl[14])(sprite_status*) = {
  &egg4_ini,
  &egg4_scrset,
  &egg4_scrreset,
  &egg4_awademo1,
  &egg4_awademo2,
  &egg4_awademo3,
  &egg4_movel,
  &egg4_mover,
  &egg4_wait,
  &egg4_die,
  &egg4_esc,
  &egg4_movec,
  &egg4_movec2,
  &egg4_movec3
};
extern unsigned short scr_dir_tbl[];
static sprite_pattern egg4meca_pat0 = {
  1,
  { { -32, -28, 0, 459 } }
};
static sprite_pattern egg4meca_pat1 = {
  1,
  { { -32, -28, 0, 460 } }
};
sprite_pattern* egg4meca_pat[2] = {
  &egg4meca_pat0,
  &egg4meca_pat1
};
static void(*egg4meca_act_tbl[2])(sprite_status*) = {
  &egg4meca_ini,
  &egg4meca_01
};
static unsigned char egg4awa_pchg0[7] = { 9, 0, 1, 2, 3, 4, 255 };
static unsigned char egg4awa_pchg1[3] = { 255, 4, 255 };
static unsigned char egg4awa_pchg2[5] = { 19, 4, 5, 6, 255 };
static unsigned char egg4awa_pchg3[3] = { 255, 6, 255 };
static unsigned char egg4awa_pchg4[4] = { 19, 7, 8, 252 };
static unsigned char* egg4awa_pchg[5] = {
  egg4awa_pchg0,
  egg4awa_pchg1,
  egg4awa_pchg2,
  egg4awa_pchg3,
  egg4awa_pchg4
};
static sprite_pattern egg4awa_pat0 = {
  1,
  { { -4, -4, 0, 463 } }
};
static sprite_pattern egg4awa_pat1 = {
  1,
  { { -4, -4, 0, 464 } }
};
static sprite_pattern egg4awa_pat2 = {
  1,
  { { -4, -4, 0, 465 } }
};
static sprite_pattern egg4awa_pat3 = {
  1,
  { { -8, -8, 0, 466 } }
};
static sprite_pattern egg4awa_pat4 = {
  1,
  { { -8, -8, 0, 467 } }
};
static sprite_pattern egg4awa_pat5 = {
  1,
  { { -12, -12, 0, 468 } }
};
static sprite_pattern egg4awa_pat6 = {
  1,
  { { -16, -16, 0, 469 } }
};
static sprite_pattern egg4awa_pat7 = {
  1,
  { { -16, -16, 0, 470 } }
};
static sprite_pattern egg4awa_pat8 = {
  1,
  { { -16, -16, 0, 471 } }
};
sprite_pattern* egg4awa_pat[9] = {
  &egg4awa_pat0,
  &egg4awa_pat1,
  &egg4awa_pat2,
  &egg4awa_pat3,
  &egg4awa_pat4,
  &egg4awa_pat5,
  &egg4awa_pat6,
  &egg4awa_pat7,
  &egg4awa_pat8
};
static unsigned int(*egg4awa_act_tbl[9])(sprite_status*) = {
  &egg4awa_ini,
  &egg4awa_deru,
  &egg4awa_tuku,
  &egg4awa_hiro,
  &egg4awa_roll,
  &egg4awa_ychg,
  &egg4awa_del,
  &egg4awa_out,
  &egg4awa_chi
};
static sprite_pattern egg4tama_pat0 = {
  1,
  { { -4, -4, 0, 461 } }
};
static sprite_pattern egg4tama_pat1 = {
  1,
  { { -4, -4, 0, 462 } }
};
sprite_pattern* egg4tama_pat[2] = {
  &egg4tama_pat0,
  &egg4tama_pat1
};
static unsigned char egg4tama_pchg0[4] = { 1, 0, 1, 255 };
static unsigned char* egg4tama_pchg[1] = { egg4tama_pchg0 };
static unsigned int(*egg4tama_act_tbl[3])(sprite_status*) = {
  &egg4tama_ini,
  &egg4tama_01,
  &egg4tama_02
};






















































































void egg4(sprite_status* pActwk) { /* Line 319, Address: 0x1022240 */
  pActwk->actfree[2] &= 191; /* Line 320, Address: 0x102224c */
  if (!pActwk->actfree[1]) { /* Line 321, Address: 0x102225c */

    egg4_warai_chk(pActwk); /* Line 323, Address: 0x102226c */
  } else if (--pActwk->actfree[1] == 0) { /* Line 324, Address: 0x1022278 */
    pActwk->mstno.b.h = 0; /* Line 325, Address: 0x10222a0 */
    pActwk->patno = 0; /* Line 326, Address: 0x10222a8 */
    pActwk->patcnt = 0; /* Line 327, Address: 0x10222b0 */
    pActwk->pattim = 0; /* Line 328, Address: 0x10222b8 */
    pActwk->pattimm = 0; /* Line 329, Address: 0x10222c0 */
  }


  if (egg4_act_tbl[pActwk->r_no0 / 2](pActwk) != 0) { /* Line 333, Address: 0x10222c8 */
    patchg(pActwk, egg4_pchg); /* Line 334, Address: 0x1022314 */
    actionsub(pActwk); /* Line 335, Address: 0x1022328 */
  }
} /* Line 337, Address: 0x1022334 */





static void egg4_warai_chk(sprite_status* pActwk) { /* Line 343, Address: 0x1022350 */
  if (!pActwk->mstno.b.h) { /* Line 344, Address: 0x102235c */

    if (((short*)&actwk[0])[26] || actwk[0].r_no0 == 6) { /* Line 346, Address: 0x102236c */


      egg4_warai(pActwk); /* Line 349, Address: 0x1022394 */
    }
  }
} /* Line 352, Address: 0x10223a0 */





static void egg4_warai(sprite_status* pActwk) { /* Line 358, Address: 0x10223b0 */
  pActwk->actfree[1] = 120; /* Line 359, Address: 0x10223b8 */
  pActwk->mstno.b.h = 1; /* Line 360, Address: 0x10223c4 */
  pActwk->patno = 0; /* Line 361, Address: 0x10223d0 */
  pActwk->patcnt = 0; /* Line 362, Address: 0x10223d8 */
  pActwk->pattim = 0; /* Line 363, Address: 0x10223e0 */
  pActwk->pattimm = 0; /* Line 364, Address: 0x10223e8 */
} /* Line 365, Address: 0x10223f0 */








static unsigned int egg4_ini(sprite_status* pActwk) { /* Line 374, Address: 0x1022400 */
  pActwk->r_no0 += 2; /* Line 375, Address: 0x102240c */
  pActwk->actflg = 4; /* Line 376, Address: 0x102241c */
  pActwk->sprpri = 4; /* Line 377, Address: 0x1022428 */
  pActwk->sprhsize = 32; /* Line 378, Address: 0x1022434 */
  pActwk->sprvsize = 44; /* Line 379, Address: 0x1022440 */
  pActwk->sproffset = 798; /* Line 380, Address: 0x102244c */
  pActwk->patbase = egg4_pat; /* Line 381, Address: 0x1022458 */
  pActwk->colicnt = 2; /* Line 382, Address: 0x1022468 */

  make_egg4meca(pActwk); /* Line 384, Address: 0x1022474 */

  return 1; /* Line 386, Address: 0x1022480 */
} /* Line 387, Address: 0x1022484 */





static void make_egg4meca(sprite_status* pActwk) { /* Line 393, Address: 0x10224a0 */
  sprite_status* pNewact;

  if (actwkchk(&pNewact) == 0) { /* Line 396, Address: 0x10224ac */
    ((short*)pActwk)[26] = pNewact - actwk; /* Line 397, Address: 0x10224c0 */
    ((short*)pNewact)[25] = pActwk - actwk; /* Line 398, Address: 0x10224f8 */
    pNewact->actno = 77; /* Line 399, Address: 0x1022530 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 400, Address: 0x102253c */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 401, Address: 0x102254c */
  }
} /* Line 403, Address: 0x102255c */








static unsigned int egg4_scrset(sprite_status* pActwk) { /* Line 412, Address: 0x1022570 */
  short xwk;

  scralim_right = scralim_n_right = 2480; /* Line 415, Address: 0x1022580 */

  if ((xwk = actwk[0].xposi.w.h - 160) >= scralim_left) { /* Line 417, Address: 0x102259c */
    if (actwk[0].xposi.w.h >= 2640) { /* Line 418, Address: 0x10225ec */

      sub_sync(103); /* Line 420, Address: 0x1022608 */

      pActwk->r_no0 = 6; /* Line 422, Address: 0x1022614 */
      scralim_right = scralim_n_right = 2480; /* Line 423, Address: 0x1022620 */
      xwk = 2480; /* Line 424, Address: 0x102263c */
    }


    scralim_left = scralim_n_left = xwk; /* Line 428, Address: 0x1022648 */
  }


  return 1; /* Line 432, Address: 0x1022658 */
} /* Line 433, Address: 0x102265c */








static unsigned int egg4_scrreset(sprite_status* pActwk) { /* Line 442, Address: 0x1022670 */
  short *pScrdir, sLeft, sRight, sUp, sDown, BgmNo;

  pScrdir = (short*)&scr_dir_tbl[1]; /* Line 445, Address: 0x1022694 */
  sLeft = *pScrdir++; /* Line 446, Address: 0x102269c */
  sRight = *pScrdir++; /* Line 447, Address: 0x10226b0 */
  sUp = *pScrdir++; /* Line 448, Address: 0x10226c4 */
  sDown = *pScrdir++; /* Line 449, Address: 0x10226d8 */

  scralim_right += 6; /* Line 451, Address: 0x10226ec */
  scralim_n_right += 6; /* Line 452, Address: 0x1022700 */

  if (scralim_right < sRight) { /* Line 454, Address: 0x1022714 */
    return 0; /* Line 455, Address: 0x1022738 */
  }


  bossstart = 0; /* Line 459, Address: 0x1022744 */
  scralim_right = scralim_n_right = sRight; /* Line 460, Address: 0x102274c */

  if (generate_flag) { /* Line 462, Address: 0x102275c */
    BgmNo = 22; /* Line 463, Address: 0x102276c */
  } else { /* Line 464, Address: 0x1022778 */
    BgmNo = 23; /* Line 465, Address: 0x1022780 */
  }

  sub_sync(BgmNo); /* Line 468, Address: 0x102278c */
  genecolor(); /* Line 469, Address: 0x1022798 */
  frameout(pActwk); /* Line 470, Address: 0x10227a0 */

  return 0; /* Line 472, Address: 0x10227ac */
} /* Line 473, Address: 0x10227b0 */








static unsigned int egg4_awademo1(sprite_status* pActwk) { /* Line 482, Address: 0x10227e0 */
  sprite_status* pNewact;

  egg4_posiini(pActwk); /* Line 485, Address: 0x10227ec */
  ++pActwk->actfree[0]; /* Line 486, Address: 0x10227f8 */

  if (pActwk->actfree[0] == 10) { /* Line 488, Address: 0x1022808 */
    make_awa2(pActwk, &pNewact); /* Line 489, Address: 0x1022820 */
  }


  if (pActwk->actfree[0] == 20 || pActwk->actfree[0] >= 30) { /* Line 493, Address: 0x1022830 */


    soundset(182); /* Line 496, Address: 0x1022860 */

    pActwk->actfree[0] = 0; /* Line 498, Address: 0x102286c */
    make_awa(pActwk, &pNewact); /* Line 499, Address: 0x1022874 */

    pNewact->actfree[3] = pActwk->actfree[3]++; /* Line 501, Address: 0x1022884 */

    if (pActwk->actfree[3] == 16) { /* Line 503, Address: 0x102289c */
      pActwk->r_no0 = 8; /* Line 504, Address: 0x10228b4 */
    }
  }

  return 1; /* Line 508, Address: 0x10228c0 */
} /* Line 509, Address: 0x10228c4 */





static void egg4_posiini(sprite_status* pActwk) { /* Line 515, Address: 0x10228e0 */
  if (pActwk->yposi.w.h >= 1312) { /* Line 516, Address: 0x10228e8 */

    pActwk->xposi.w.h = 2736; /* Line 518, Address: 0x1022904 */
    pActwk->xposi.w.l = 0; /* Line 519, Address: 0x1022910 */
    pActwk->yposi.w.h = 1312; /* Line 520, Address: 0x1022918 */
    pActwk->yposi.w.l = 0; /* Line 521, Address: 0x1022924 */
  } else { /* Line 522, Address: 0x102292c */
    pActwk->yposi.l += 18000; /* Line 523, Address: 0x1022934 */
  }
} /* Line 525, Address: 0x1022944 */





static void make_awa(sprite_status* pActwk, sprite_status** pNewact) { /* Line 531, Address: 0x1022950 */
  sprite_status* pMakeact;

  if (actwkchk(&pMakeact) == 0) { /* Line 534, Address: 0x1022960 */
    *pNewact = pMakeact; /* Line 535, Address: 0x1022974 */
    ((short*)pMakeact)[25] = pActwk - actwk; /* Line 536, Address: 0x1022980 */
    pMakeact->actno = 79; /* Line 537, Address: 0x10229b8 */
    pMakeact->xposi.w.h = pActwk->xposi.w.h; /* Line 538, Address: 0x10229c4 */
    pMakeact->yposi.w.h = 1464; /* Line 539, Address: 0x10229d4 */
  }
} /* Line 541, Address: 0x10229e0 */





static void make_awa2(sprite_status* pActwk, sprite_status** pNewact) { /* Line 547, Address: 0x10229f0 */
  make_awa(pActwk, pNewact); /* Line 548, Address: 0x1022a00 */
  (*pNewact)->r_no1 = 1; /* Line 549, Address: 0x1022a10 */
} /* Line 550, Address: 0x1022a20 */








static unsigned int egg4_awademo2(sprite_status* pActwk) { /* Line 559, Address: 0x1022a30 */
  egg4_posiini(pActwk); /* Line 560, Address: 0x1022a3c */

  if (++pActwk->actfree[0] == 150) { /* Line 562, Address: 0x1022a48 */
    pActwk->actfree[0] = 0; /* Line 563, Address: 0x1022a6c */
    pActwk->r_no0 = 10; /* Line 564, Address: 0x1022a74 */
  }

  return 1; /* Line 567, Address: 0x1022a80 */
} /* Line 568, Address: 0x1022a84 */








static unsigned int egg4_awademo3(sprite_status* pActwk) { /* Line 577, Address: 0x1022aa0 */
  if (++pActwk->actfree[0] == 150) { /* Line 578, Address: 0x1022aa8 */
    pActwk->r_no0 = 12; /* Line 579, Address: 0x1022acc */
    ((short*)pActwk)[33] = 96; /* Line 580, Address: 0x1022ad8 */
    pActwk->yspeed.w = 64; /* Line 581, Address: 0x1022ae4 */
    ((short*)pActwk)[28] = 0; /* Line 582, Address: 0x1022af0 */
    ((short*)pActwk)[30] = 96; /* Line 583, Address: 0x1022af8 */
    ((short*)pActwk)[31] = 0; /* Line 584, Address: 0x1022b04 */
    ((short*)pActwk)[23] = 0; /* Line 585, Address: 0x1022b0c */
  }

  return 1; /* Line 588, Address: 0x1022b14 */
} /* Line 589, Address: 0x1022b18 */








static unsigned int egg4_movel(sprite_status* pActwk) { /* Line 598, Address: 0x1022b30 */
  egg4_hitchk(pActwk); /* Line 599, Address: 0x1022b3c */

  ((short*)pActwk)[28] += 256; /* Line 601, Address: 0x1022b48 */
  if (((short*)pActwk)[28] == 2048) { /* Line 602, Address: 0x1022b58 */
    make_tama(pActwk); /* Line 603, Address: 0x1022b74 */
  }


  if (((unsigned short*)pActwk)[28] == 32768) { /* Line 607, Address: 0x1022b80 */

    pActwk->actfree[0] = 0; /* Line 609, Address: 0x1022b98 */
    pActwk->r_no0 = 16; /* Line 610, Address: 0x1022ba0 */
    pActwk->actfree[2] |= 16; /* Line 611, Address: 0x1022bac */
  } else { /* Line 612, Address: 0x1022bbc */
    pActwk->xposi.w.h -= ((short*)pActwk)[30]; /* Line 613, Address: 0x1022bc4 */
    pActwk->yposi.w.h -= ((short*)pActwk)[31]; /* Line 614, Address: 0x1022bdc */
    egg4_posiset(pActwk); /* Line 615, Address: 0x1022bf4 */
  }

  return 1; /* Line 618, Address: 0x1022c00 */
} /* Line 619, Address: 0x1022c04 */





static void egg4_hitchk(sprite_status* pActwk) { /* Line 625, Address: 0x1022c20 */
  if (pActwk->colino) return; /* Line 626, Address: 0x1022c2c */




  pActwk->colino = 60; /* Line 631, Address: 0x1022c3c */
  if (pActwk->colicnt != 1) return; /* Line 632, Address: 0x1022c48 */




  pActwk->actfree[0] = 0; /* Line 637, Address: 0x1022c60 */
  pActwk->r_no0 = 18; /* Line 638, Address: 0x1022c68 */
  pActwk->actfree[2] |= 128; /* Line 639, Address: 0x1022c74 */
  pActwk->mstno.b.h = 2; /* Line 640, Address: 0x1022c84 */
  pActwk->patno = pActwk->patcnt = pActwk->pattim = pActwk->pattimm = 0; /* Line 641, Address: 0x1022c90 */
  egg4_die(pActwk); /* Line 642, Address: 0x1022cbc */
} /* Line 643, Address: 0x1022cc8 */





static void make_tama(sprite_status* pActwk) { /* Line 649, Address: 0x1022ce0 */
  int i;
  sprite_status* pNewact;
  short xposwk;
  int xspdwk;
  static tama tama_tbl[4] = {
    { -29, 23, -81000,  81000 },
    {  -6, 31,      0, 114688 },
    {  16, 28,  57344,  99319 },
    {  29, 17,  81000,  81000 }
  };

















  for (i = 0; i < 4; ++i) { /* Line 677, Address: 0x1022cf8 */
    if (actwkchk(&pNewact) != 0) break; /* Line 678, Address: 0x1022d04 */




    ((short*)pNewact)[25] = pActwk - actwk; /* Line 683, Address: 0x1022d18 */
    pNewact->actno = 78; /* Line 684, Address: 0x1022d50 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 685, Address: 0x1022d5c */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 686, Address: 0x1022d6c */

    xposwk = tama_tbl[i].xpos; /* Line 688, Address: 0x1022d7c */
    xspdwk = tama_tbl[i].xspd; /* Line 689, Address: 0x1022da8 */

    if (pActwk->cddat & 1) { /* Line 691, Address: 0x1022dc4 */

      xposwk = -xposwk; /* Line 693, Address: 0x1022ddc */
      xspdwk = -xspdwk; /* Line 694, Address: 0x1022df8 */
    }


    ((short*)pNewact)[30] = xposwk; /* Line 698, Address: 0x1022dfc */
    ((short*)pNewact)[31] = tama_tbl[i].ypos; /* Line 699, Address: 0x1022e04 */
    ((int*)pNewact)[16] = xspdwk; /* Line 700, Address: 0x1022e30 */
    ((int*)pNewact)[4] = tama_tbl[i].yspd; /* Line 701, Address: 0x1022e38 */
  } /* Line 702, Address: 0x1022e5c */
} /* Line 703, Address: 0x1022e6c */





static void egg4_posiset(sprite_status* pActwk) { /* Line 709, Address: 0x1022e90 */
  short sinwk, coswk;
  int_union xwk, ywk;

  sinset(pActwk->actfree[11], &sinwk, &coswk); /* Line 713, Address: 0x1022e9c */
  xwk.l = ((short*)pActwk)[33]; /* Line 714, Address: 0x1022eb4 */
  ywk.l = pActwk->yspeed.w; /* Line 715, Address: 0x1022ec8 */
  ywk.l *= sinwk; /* Line 716, Address: 0x1022edc */
  xwk.l *= coswk; /* Line 717, Address: 0x1022ef4 */
  ywk.l >>= 8; /* Line 718, Address: 0x1022f0c */
  xwk.l >>= 8; /* Line 719, Address: 0x1022f18 */

  ((short*)pActwk)[30] = xwk.w.l; /* Line 721, Address: 0x1022f24 */
  ((short*)pActwk)[31] = ywk.w.l; /* Line 722, Address: 0x1022f30 */
  pActwk->xposi.w.h += xwk.w.l; /* Line 723, Address: 0x1022f3c */
  pActwk->yposi.w.h += ywk.w.l; /* Line 724, Address: 0x1022f50 */
} /* Line 725, Address: 0x1022f64 */








static unsigned int egg4_mover(sprite_status* pActwk) { /* Line 734, Address: 0x1022f80 */
  egg4_hitchk(pActwk); /* Line 735, Address: 0x1022f8c */

  ((short*)pActwk)[28] -= 256; /* Line 737, Address: 0x1022f98 */
  if (((short*)pActwk)[28] == 30720) { /* Line 738, Address: 0x1022fa8 */
    make_tama(pActwk); /* Line 739, Address: 0x1022fc4 */
  }


  if (((short*)pActwk)[28] == 0) { /* Line 743, Address: 0x1022fd0 */

    pActwk->actfree[0] = 0; /* Line 745, Address: 0x1022fe8 */
    pActwk->r_no0 = 16; /* Line 746, Address: 0x1022ff0 */
    pActwk->actfree[2] |= 16; /* Line 747, Address: 0x1022ffc */
  } else { /* Line 748, Address: 0x102300c */
    pActwk->xposi.w.h -= ((short*)pActwk)[30]; /* Line 749, Address: 0x1023014 */
    pActwk->yposi.w.h -= ((short*)pActwk)[31]; /* Line 750, Address: 0x102302c */
    egg4_posiset(pActwk); /* Line 751, Address: 0x1023044 */
  }

  return 1; /* Line 754, Address: 0x1023050 */
} /* Line 755, Address: 0x1023054 */








static unsigned int egg4_wait(sprite_status* pActwk) { /* Line 764, Address: 0x1023070 */
  char awaposi_cnt_tbl[8] = { /* Line 765, Address: 0x1023084 */
    14, 12, 10, 8, 6, 4, -1, -1
  };
  char cnt;
  sprite_status* pChildact;

  pActwk->actfree[2] &= 207; /* Line 771, Address: 0x10230b8 */
  egg4_hitchk(pActwk); /* Line 772, Address: 0x10230c8 */
  ++pActwk->actfree[0]; /* Line 773, Address: 0x10230d4 */

  if ((long int)(int)pActwk->actfree[0] == 48) { /* Line 775, Address: 0x10230e4 */

    pChildact = &actwk[((short*)pActwk)[26]]; /* Line 777, Address: 0x1023104 */
    pChildact->actflg ^= 1; /* Line 778, Address: 0x102312c */
    pChildact->cddat ^= 1; /* Line 779, Address: 0x1023138 */
    pActwk->actflg ^= 1; /* Line 780, Address: 0x1023144 */
    pActwk->cddat ^= 1; /* Line 781, Address: 0x1023154 */
  } else if (pActwk->actfree[0] == 96) { /* Line 782, Address: 0x1023164 */

    pActwk->actfree[0] = 0; /* Line 784, Address: 0x1023184 */
    if (pActwk->cddat & 1) { /* Line 785, Address: 0x102318c */

      pActwk->actfree[2] |= 8; /* Line 787, Address: 0x10231a4 */
      pActwk->r_no0 = 14; /* Line 788, Address: 0x10231b4 */
    } /* Line 789, Address: 0x10231c0 */
    else {
      pActwk->actfree[2] &= 247; /* Line 791, Address: 0x10231c8 */
      pActwk->r_no0 = 12; /* Line 792, Address: 0x10231d8 */
    }


    while ((cnt = awaposi_cnt_tbl[pActwk->actfree[9]]) >= 0) { /* Line 796, Address: 0x10231e4 */
      if (pActwk->actfree[3] > cnt) break; /* Line 797, Address: 0x10231ec */




      ++pActwk->actfree[9]; /* Line 802, Address: 0x102320c */
      pActwk->r_no0 = 22; /* Line 803, Address: 0x102321c */
    } /* Line 804, Address: 0x1023228 */
  }

  return 1; /* Line 807, Address: 0x1023254 */
} /* Line 808, Address: 0x1023258 */








static unsigned int egg4_die(sprite_status* pActwk) { /* Line 817, Address: 0x1023270 */
  ++pActwk->actfree[0]; /* Line 818, Address: 0x102327c */

  if (pActwk->actfree[0] < 60) { /* Line 820, Address: 0x102328c */
    bom_set(pActwk); /* Line 821, Address: 0x10232a4 */
  } else if (pActwk->actfree[0] == 60) { /* Line 822, Address: 0x10232b0 */

    pActwk->mstno.b.h = 3; /* Line 824, Address: 0x10232d0 */
    pActwk->actfree[1] = 255; /* Line 825, Address: 0x10232dc */
    pActwk->patno = pActwk->patcnt = pActwk->pattim = pActwk->pattimm = 0; /* Line 826, Address: 0x10232e8 */

    pActwk->patno = 1; /* Line 828, Address: 0x1023314 */
  } else if (pActwk->actfree[0] == 61) { /* Line 829, Address: 0x1023320 */

    pActwk->actfree[0] = 0; /* Line 831, Address: 0x1023340 */
    pActwk->r_no0 = 20; /* Line 832, Address: 0x1023348 */
    pActwk->actflg |= 1; /* Line 833, Address: 0x1023354 */
    pActwk->cddat |= 1; /* Line 834, Address: 0x1023364 */
    actwk[((short*)pActwk)[26]].actflg |= 1; /* Line 835, Address: 0x1023374 */
    actwk[((short*)pActwk)[26]].cddat |= 1; /* Line 836, Address: 0x10233a8 */
    scoreup(100); /* Line 837, Address: 0x10233dc */
  }

  return 1; /* Line 840, Address: 0x10233e8 */
} /* Line 841, Address: 0x10233ec */





static void bom_set(sprite_status* pActwk) { /* Line 847, Address: 0x1023400 */
  int_union tmwk;
  int wk;
  short bom_tbl[20] = { /* Line 850, Address: 0x1023410 */
    -48, -16,
     48,  16,
    -16, -16,
     16,  16,
    -32,   0,
     48, -16,
    -48,  16,
    -16,  16,
     16, -16,
     32,   0
  };
  sprite_status* pNewact;

  tmwk.l = 0; /* Line 864, Address: 0x1023444 */
  tmwk.b.b4 = pActwk->actfree[0]; /* Line 865, Address: 0x1023448 */
  wk = tmwk.l; /* Line 866, Address: 0x1023454 */
  tmwk.w.l = wk % 4; /* Line 867, Address: 0x1023458 */
  tmwk.w.h = wk / 4; /* Line 868, Address: 0x1023480 */
  if (tmwk.w.l == 0) { /* Line 869, Address: 0x10234a4 */
    tmwk.l = (unsigned int)tmwk.l >> 16 & 65535 | tmwk.l << 16 & -65536; /* Line 870, Address: 0x10234b8 */
    tmwk.l %= 10; /* Line 871, Address: 0x10234dc */
    tmwk.l <<= 1; /* Line 872, Address: 0x10234f0 */
    if (actwkchk(&pNewact) == 0) { /* Line 873, Address: 0x10234fc */
      pNewact->r_no1 = 1; /* Line 874, Address: 0x1023510 */
      pNewact->actno = 24; /* Line 875, Address: 0x102351c */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 876, Address: 0x1023528 */
      pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 877, Address: 0x1023538 */
      pNewact->xposi.w.h += bom_tbl[tmwk.l++]; /* Line 878, Address: 0x1023548 */
      pNewact->yposi.w.h += bom_tbl[tmwk.l]; /* Line 879, Address: 0x1023570 */
      soundset(158); /* Line 880, Address: 0x1023590 */
    }
  }
} /* Line 883, Address: 0x102359c */








static unsigned int egg4_esc(sprite_status* pActwk) { /* Line 892, Address: 0x10235b0 */
  if (++pActwk->actfree[0] < 60) { /* Line 893, Address: 0x10235bc */
    return 1; /* Line 894, Address: 0x10235e0 */
  }

  pActwk->xposi.l += 114688; /* Line 897, Address: 0x10235ec */
  if (pActwk->xposi.w.h >= 2864) { /* Line 898, Address: 0x1023604 */

    pActwk->r_no0 = 4; /* Line 900, Address: 0x1023620 */
    frameout(&actwk[((short*)pActwk)[26]]); /* Line 901, Address: 0x102362c */
  }

  return 1; /* Line 904, Address: 0x102365c */
} /* Line 905, Address: 0x1023660 */








static unsigned int egg4_movec(sprite_status* pActwk) { /* Line 914, Address: 0x1023670 */
  int_union offswk;

  ++pActwk->actfree[0]; /* Line 917, Address: 0x102367c */

  switch (pActwk->actfree[0]) { /* Line 919, Address: 0x102368c */

    case 20:
      egg4_warai(pActwk); /* Line 922, Address: 0x10236c4 */
      pActwk->actfree[8] = 0; /* Line 923, Address: 0x10236d0 */
      pActwk->actfree[2] |= 32; /* Line 924, Address: 0x10236d8 */
      break; /* Line 925, Address: 0x10236e8 */


    case 21:
      pActwk->actfree[2] &= 223; /* Line 929, Address: 0x10236f0 */
      break; /* Line 930, Address: 0x1023700 */


    case 45:
      make_tama(pActwk); /* Line 934, Address: 0x1023708 */
      break;
  }





  if (pActwk->actfree[2] & 8) { /* Line 942, Address: 0x1023714 */

    pActwk->xposi.l += 65536; /* Line 944, Address: 0x102372c */
    if (pActwk->xposi.w.h >= 2736) goto label1; /* Line 945, Address: 0x1023740 */
    return 1; /* Line 946, Address: 0x102375c */
  }


  pActwk->xposi.l -= 65536; /* Line 950, Address: 0x1023768 */
  if (pActwk->xposi.w.h <= 2544) goto label1; /* Line 951, Address: 0x102377c */
  return 1; /* Line 952, Address: 0x1023798 */



label1:
  ((int*)pActwk)[15] *= -1; /* Line 957, Address: 0x10237a4 */
  ((unsigned short*)pActwk)[28] += 32768; /* Line 958, Address: 0x10237b4 */
  pActwk->xposi.w.h = 2640; /* Line 959, Address: 0x10237c8 */
  pActwk->xposi.w.l = 0; /* Line 960, Address: 0x10237d4 */

  offswk.w.h = ((short*)pActwk)[30]; /* Line 962, Address: 0x10237dc */
  offswk.w.l = ((short*)pActwk)[31]; /* Line 963, Address: 0x10237e8 */
  pActwk->xposi.l += offswk.l; /* Line 964, Address: 0x10237f4 */

  pActwk->yposi.w.h = 1312; /* Line 966, Address: 0x1023808 */
  pActwk->yposi.w.l = 0; /* Line 967, Address: 0x1023814 */

  pActwk->actfree[0] = 0; /* Line 969, Address: 0x102381c */
  pActwk->r_no0 = 16; /* Line 970, Address: 0x1023824 */
  pActwk->actfree[2] |= 16; /* Line 971, Address: 0x1023830 */

  return 1; /* Line 973, Address: 0x1023840 */
} /* Line 974, Address: 0x1023844 */








static unsigned int egg4_movec2(sprite_status* pActwk) { /* Line 983, Address: 0x1023860 */
  pActwk = pActwk; /* Line 984, Address: 0x1023868 */
  return 1; /* Line 985, Address: 0x1023870 */
} /* Line 986, Address: 0x1023874 */








static unsigned int egg4_movec3(sprite_status* pActwk) { /* Line 995, Address: 0x1023880 */
  pActwk = pActwk; /* Line 996, Address: 0x1023888 */
  return 1; /* Line 997, Address: 0x1023890 */
} /* Line 998, Address: 0x1023894 */




































void egg4meca(sprite_status* pActwk) { /* Line 1035, Address: 0x10238a0 */
  egg4meca_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1036, Address: 0x10238ac */
  actionsub(pActwk); /* Line 1037, Address: 0x10238f0 */
} /* Line 1038, Address: 0x10238fc */








static void egg4meca_ini(sprite_status* pActwk) { /* Line 1047, Address: 0x1023910 */
  pActwk->r_no0 += 2; /* Line 1048, Address: 0x102391c */
  pActwk->actflg = 4; /* Line 1049, Address: 0x102392c */
  pActwk->sprpri = 4; /* Line 1050, Address: 0x1023938 */
  pActwk->sprhsize = 32; /* Line 1051, Address: 0x1023944 */
  pActwk->sprvsize = 28; /* Line 1052, Address: 0x1023950 */
  pActwk->sproffset = 798; /* Line 1053, Address: 0x102395c */
  pActwk->patbase = egg4meca_pat; /* Line 1054, Address: 0x1023968 */

  egg4meca_01(pActwk); /* Line 1056, Address: 0x1023978 */
} /* Line 1057, Address: 0x1023984 */








static void egg4meca_01(sprite_status* pActwk) { /* Line 1066, Address: 0x10239a0 */
  sprite_status* pEggact;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1069, Address: 0x10239ac */
  pActwk->xposi.w.h = pEggact->xposi.w.h; /* Line 1070, Address: 0x10239d4 */
  pActwk->yposi.w.h = pEggact->yposi.w.h; /* Line 1071, Address: 0x10239e0 */
} /* Line 1072, Address: 0x10239ec */

































































































void egg4awa(sprite_status* pActwk) { /* Line 1170, Address: 0x1023a00 */
  if (egg4awa_act_tbl[pActwk->r_no0 / 2](pActwk) != 0) { /* Line 1171, Address: 0x1023a0c */
    actionsub(pActwk); /* Line 1172, Address: 0x1023a58 */
  }
} /* Line 1174, Address: 0x1023a64 */








static unsigned int egg4awa_ini(sprite_status* pActwk) { /* Line 1183, Address: 0x1023a80 */
  int_union RndNum;
  uint_union uRndNum;

  pActwk->r_no0 = 2; /* Line 1187, Address: 0x1023a8c */
  pActwk->actflg = 4; /* Line 1188, Address: 0x1023a98 */
  pActwk->sprpri = 3; /* Line 1189, Address: 0x1023aa4 */
  pActwk->sprhsize = 16; /* Line 1190, Address: 0x1023ab0 */
  pActwk->sprvsize = 16; /* Line 1191, Address: 0x1023abc */
  pActwk->sproffset = 798; /* Line 1192, Address: 0x1023ac8 */
  pActwk->patbase = egg4awa_pat; /* Line 1193, Address: 0x1023ad4 */

  RndNum.l = random(); /* Line 1195, Address: 0x1023ae4 */
  RndNum.l = RndNum.w.l; /* Line 1196, Address: 0x1023af0 */
  RndNum.w.l = RndNum.l % 1280; /* Line 1197, Address: 0x1023b00 */
  if (RndNum.w.l < 0) { /* Line 1198, Address: 0x1023b1c */

    RndNum.w.l -= 128; /* Line 1200, Address: 0x1023b30 */
  } else { /* Line 1201, Address: 0x1023b3c */
    RndNum.w.l += 128; /* Line 1202, Address: 0x1023b44 */
  }


  ((short*)pActwk)[29] = RndNum.w.l; /* Line 1206, Address: 0x1023b50 */

  uRndNum.l = random(); /* Line 1208, Address: 0x1023b5c */
  uRndNum.w.h = 0; /* Line 1209, Address: 0x1023b68 */
  uRndNum.w.l = (short)(uRndNum.l % 16 + 10); /* Line 1210, Address: 0x1023b6c */
  ((short*)pActwk)[33] = uRndNum.w.l; /* Line 1211, Address: 0x1023b8c */

  egg4awa_deru(pActwk); /* Line 1213, Address: 0x1023b98 */
} /* Line 1214, Address: 0x1023ba4 */








static unsigned int egg4awa_deru(sprite_status* pActwk) { /* Line 1223, Address: 0x1023bc0 */
  sprite_status* pEggact;
  short xwk;

  pActwk->yposi.l += -98304; /* Line 1227, Address: 0x1023bd4 */
  if (pActwk->r_no1) { /* Line 1228, Address: 0x1023bec */

    if (pActwk->yposi.w.h < 1136) { /* Line 1230, Address: 0x1023bfc */
      return egg4awa_out(pActwk); /* Line 1231, Address: 0x1023c18 */
    }
  }
  else {
    pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1235, Address: 0x1023c2c */
    if (pEggact->yposi.w.h >= pActwk->yposi.w.h) { /* Line 1236, Address: 0x1023c54 */

      if ((xwk = pActwk->xposi.w.h - pEggact->xposi.w.h) >= 0) { /* Line 1238, Address: 0x1023c7c */

        ((unsigned short*)pActwk)[28] = 32768; /* Line 1240, Address: 0x1023cc4 */
      } else { /* Line 1241, Address: 0x1023cd0 */
        ((unsigned short*)pActwk)[28] = 0; /* Line 1242, Address: 0x1023cd8 */
      }


      ((short*)pActwk)[33] = xwk; /* Line 1246, Address: 0x1023ce0 */
      pActwk->yspeed.w = xwk; /* Line 1247, Address: 0x1023ce8 */
      ((short*)pActwk)[30] = -xwk; /* Line 1248, Address: 0x1023cf0 */
      ((short*)pActwk)[31] = 0; /* Line 1249, Address: 0x1023d0c */
      pActwk->xposi.w.h = pEggact->xposi.w.h; /* Line 1250, Address: 0x1023d14 */
      pActwk->yposi.w.h = pEggact->yposi.w.h; /* Line 1251, Address: 0x1023d20 */
      pActwk->r_no0 = 4; /* Line 1252, Address: 0x1023d2c */
      pActwk->mstno.b.h = 2; /* Line 1253, Address: 0x1023d38 */
      return 1; /* Line 1254, Address: 0x1023d44 */
    }
  }


  ((short*)pActwk)[28] += ((short*)pActwk)[29]; /* Line 1259, Address: 0x1023d50 */


  pActwk->xposi.w.h -= ((short*)pActwk)[30]; /* Line 1262, Address: 0x1023d68 */
  egg4_posiset(pActwk); /* Line 1263, Address: 0x1023d80 */

  if (pActwk->patcnt == 4) { /* Line 1265, Address: 0x1023d8c */
    pActwk->mstno.b.h = 1; /* Line 1266, Address: 0x1023da4 */
    pActwk->patcnt = 0; /* Line 1267, Address: 0x1023db0 */
  }


  patchg(pActwk, egg4awa_pchg); /* Line 1271, Address: 0x1023db8 */
  return 1; /* Line 1272, Address: 0x1023dcc */
} /* Line 1273, Address: 0x1023dd0 */








static unsigned int egg4awa_tuku(sprite_status* pActwk) { /* Line 1282, Address: 0x1023df0 */
  sprite_status* pEggact;
  short RadSpd;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1286, Address: 0x1023e04 */
  pActwk->xposi.w.h = pEggact->xposi.w.h; /* Line 1287, Address: 0x1023e2c */
  pActwk->yposi.w.h = pEggact->yposi.w.h; /* Line 1288, Address: 0x1023e38 */
  egg4_posiset(pActwk); /* Line 1289, Address: 0x1023e44 */

  if ((RadSpd = ((short*)pActwk)[29]) >= 0) { /* Line 1291, Address: 0x1023e50 */
    RadSpd *= -1; /* Line 1292, Address: 0x1023e70 */
  }


  ((short*)pActwk)[28] += RadSpd; /* Line 1296, Address: 0x1023e7c */
  if (pEggact->r_no0 == 10) { /* Line 1297, Address: 0x1023e8c */
    ((short*)pActwk)[30] = 0; /* Line 1298, Address: 0x1023ea0 */
    ((short*)pActwk)[31] = 0; /* Line 1299, Address: 0x1023ea8 */
    pActwk->r_no0 = 6; /* Line 1300, Address: 0x1023eb0 */
    pActwk->xposi.l = pEggact->xposi.l; /* Line 1301, Address: 0x1023ebc */
    pActwk->yposi.l = pEggact->yposi.l; /* Line 1302, Address: 0x1023ec8 */


    RadSpd = (char)pActwk->actfree[3]; /* Line 1305, Address: 0x1023ed4 */
    RadSpd = (unsigned short)RadSpd << 12; /* Line 1306, Address: 0x1023ef4 */
    ((short*)pActwk)[28] = RadSpd; /* Line 1307, Address: 0x1023f10 */
    ((short*)pActwk)[33] = 16; /* Line 1308, Address: 0x1023f18 */
    pActwk->yspeed.w = 16; /* Line 1309, Address: 0x1023f24 */
  }

  return 1; /* Line 1312, Address: 0x1023f30 */
} /* Line 1313, Address: 0x1023f34 */








static unsigned int egg4awa_hiro(sprite_status* pActwk) { /* Line 1322, Address: 0x1023f50 */
  int flg;
  sprite_status* pEggact;

  if (pActwk->actfree[2] & 2) { /* Line 1326, Address: 0x1023f64 */
    awa_hitchk(pActwk); /* Line 1327, Address: 0x1023f7c */
  }


  flg = 0; /* Line 1331, Address: 0x1023f88 */

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1333, Address: 0x1023f8c */
  pActwk->xposi.l = pEggact->xposi.l; /* Line 1334, Address: 0x1023fb4 */
  pActwk->yposi.l = pEggact->yposi.l; /* Line 1335, Address: 0x1023fc0 */

  if ((long int)(int)((short*)pActwk)[33] < 48) { /* Line 1337, Address: 0x1023fcc */
    ((int*)pActwk)[16] += 16384; /* Line 1338, Address: 0x1023ff0 */
  } /* Line 1339, Address: 0x1024000 */
  else {
    ((short*)pActwk)[33] = 48; /* Line 1341, Address: 0x1024008 */
    ++flg; /* Line 1342, Address: 0x1024014 */
  }


  if ((long int)(int)pActwk->yspeed.w < 48) { /* Line 1346, Address: 0x1024018 */
    ((int*)pActwk)[4] += 16384; /* Line 1347, Address: 0x102403c */
  } /* Line 1348, Address: 0x102404c */
  else {
    pActwk->yspeed.w = 48; /* Line 1350, Address: 0x1024054 */
    ++flg; /* Line 1351, Address: 0x1024060 */
  }


  if (pEggact->actfree[2] & 8) { /* Line 1355, Address: 0x1024064 */

    ((short*)pActwk)[28] += 1152; /* Line 1357, Address: 0x1024078 */
  } /* Line 1358, Address: 0x1024088 */
  else {
    ((short*)pActwk)[28] -= 1152; /* Line 1360, Address: 0x1024090 */
  }


  egg4_posiset(pActwk); /* Line 1364, Address: 0x10240a0 */

  if (pActwk->patcnt == 2) { /* Line 1366, Address: 0x10240ac */
    pActwk->mstno.b.h = 3; /* Line 1367, Address: 0x10240c4 */
    pActwk->patcnt = 0; /* Line 1368, Address: 0x10240d0 */
  }


  if (flg == 2) { /* Line 1372, Address: 0x10240d8 */
    pActwk->r_no0 = 8; /* Line 1373, Address: 0x10240e4 */
    flg = pActwk->actfree[2]; /* Line 1374, Address: 0x10240f0 */

    if (!(pActwk->actfree[2] & 2)) { /* Line 1376, Address: 0x10240fc */
      pActwk->colino = 255; /* Line 1377, Address: 0x1024114 */
      pActwk->colicnt = 2; /* Line 1378, Address: 0x1024120 */
    }

    pActwk->actfree[2] |= 2; /* Line 1381, Address: 0x102412c */
  }


  patchg(pActwk, egg4awa_pchg); /* Line 1385, Address: 0x102413c */

  return 1; /* Line 1387, Address: 0x1024150 */
} /* Line 1388, Address: 0x1024154 */





static void awa_hitchk(sprite_status* pActwk) { /* Line 1394, Address: 0x1024170 */
  sprite_status* pEggact;
  unsigned char flgwk;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1398, Address: 0x1024184 */
  if (pEggact->r_no0 != 20) { /* Line 1399, Address: 0x10241ac */
    if (pActwk->colino) return; /* Line 1400, Address: 0x10241c0 */




    flgwk = pEggact->actfree[2]; /* Line 1405, Address: 0x10241d0 */
    pEggact->actfree[2] |= 64; /* Line 1406, Address: 0x10241d8 */
    if (flgwk & 64) { /* Line 1407, Address: 0x10241e4 */

      pActwk->colino = 255; /* Line 1409, Address: 0x10241f4 */
      pActwk->colicnt = 2; /* Line 1410, Address: 0x1024200 */
      return; /* Line 1411, Address: 0x102420c */
    }
  }


  pActwk->r_no0 = 12; /* Line 1416, Address: 0x1024214 */
  pActwk->mstno.b.h = 4; /* Line 1417, Address: 0x1024220 */
  pActwk->patno = pActwk->patcnt = pActwk->pattim = pActwk->pattimm = 0; /* Line 1418, Address: 0x102422c */
  --pEggact->actfree[3]; /* Line 1419, Address: 0x1024258 */
  egg4awa_del(pActwk); /* Line 1420, Address: 0x1024264 */
} /* Line 1421, Address: 0x1024270 */








static unsigned int egg4awa_roll(sprite_status* pActwk) { /* Line 1430, Address: 0x1024290 */
  sprite_status* pEggact;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1433, Address: 0x10242a0 */
  pActwk->xposi.l = pEggact->xposi.l; /* Line 1434, Address: 0x10242c8 */
  pActwk->yposi.l = pEggact->yposi.l; /* Line 1435, Address: 0x10242d4 */

  if (pEggact->actfree[2] & 16) { /* Line 1437, Address: 0x10242e0 */
    pActwk->r_no0 = 10; /* Line 1438, Address: 0x10242f4 */
    return egg4awa_ychg(pActwk); /* Line 1439, Address: 0x1024300 */
  }


  if (pEggact->actfree[2] & 32) { /* Line 1443, Address: 0x1024314 */
    pActwk->r_no0 = 16; /* Line 1444, Address: 0x1024328 */
    pActwk->sprpri = 3; /* Line 1445, Address: 0x1024334 */
    return egg4awa_chi(pActwk); /* Line 1446, Address: 0x1024340 */
  }


  awa_hitchk(pActwk); /* Line 1450, Address: 0x1024354 */
  if (pEggact->actfree[2] & 8) { /* Line 1451, Address: 0x1024360 */

    ((short*)pActwk)[28] += 384; /* Line 1453, Address: 0x1024374 */
  } /* Line 1454, Address: 0x1024384 */
  else {
    ((short*)pActwk)[28] -= 384; /* Line 1456, Address: 0x102438c */
  }


  egg4_posiset(pActwk); /* Line 1460, Address: 0x102439c */
  return 1; /* Line 1461, Address: 0x10243a8 */
} /* Line 1462, Address: 0x10243ac */








static unsigned int egg4awa_ychg(sprite_status* pActwk) { /* Line 1471, Address: 0x10243c0 */
  sprite_status* pEggact;

  awa_hitchk(pActwk); /* Line 1474, Address: 0x10243d0 */

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1476, Address: 0x10243dc */
  pActwk->xposi.l = pEggact->xposi.l; /* Line 1477, Address: 0x1024404 */
  pActwk->yposi.l = pEggact->yposi.l; /* Line 1478, Address: 0x1024410 */

  if (pActwk->r_no1) { /* Line 1480, Address: 0x102441c */

    ((int*)pActwk)[16] -= 65536; /* Line 1482, Address: 0x102442c */
    if ((long int)((int*)pActwk)[16] > -3145728) { /* Line 1483, Address: 0x1024440 */
      ychg_ret(pActwk, pEggact); /* Line 1484, Address: 0x1024464 */
    } /* Line 1485, Address: 0x1024474 */
    else {
      ((int*)pActwk)[16] = 3145728; /* Line 1487, Address: 0x102447c */
      pActwk->r_no0 = 8; /* Line 1488, Address: 0x1024488 */


      ychg_rad_endproc(pActwk); /* Line 1491, Address: 0x1024494 */
      ychg_ret(pActwk, pEggact); /* Line 1492, Address: 0x10244a0 */
      pActwk->r_no1 = 0; /* Line 1493, Address: 0x10244b0 */
    }
  } /* Line 1495, Address: 0x10244b8 */
  else {
    if ((((int*)pActwk)[16] -= 65536) < 0) { /* Line 1497, Address: 0x10244c0 */

      ++pActwk->r_no1; /* Line 1499, Address: 0x10244dc */
    }

    ychg_ret(pActwk, pEggact); /* Line 1502, Address: 0x10244ec */
  }

  return 1; /* Line 1505, Address: 0x10244fc */
} /* Line 1506, Address: 0x1024500 */





static void ychg_ret(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 1512, Address: 0x1024520 */
  short spdwk;
  unsigned char radwk;

  spdwk = 1152; /* Line 1516, Address: 0x1024538 */

  if (!(pEggwk->actfree[2]) & 8) { /* Line 1518, Address: 0x1024544 */
    spdwk *= -1; /* Line 1519, Address: 0x1024560 */
  }


  ((short*)pActwk)[28] += spdwk; /* Line 1523, Address: 0x102456c */

  radwk = pActwk->actfree[11] - 64; /* Line 1525, Address: 0x102457c */
  if (pEggwk->actfree[2] & 8) { /* Line 1526, Address: 0x1024594 */
    radwk ^= 128; /* Line 1527, Address: 0x10245ac */
  }


  if (radwk & 128) { /* Line 1531, Address: 0x10245b4 */

    pActwk->sprpri = 5; /* Line 1533, Address: 0x10245c4 */
  } /* Line 1534, Address: 0x10245d0 */
  else {
    pActwk->sprpri = 3; /* Line 1536, Address: 0x10245d8 */
  }

  egg4_posiset(pActwk); /* Line 1539, Address: 0x10245e4 */
} /* Line 1540, Address: 0x10245f0 */





static void ychg_rad_endproc(sprite_status* pActwk) { /* Line 1546, Address: 0x1024610 */
  unsigned short radwk;

  radwk = ((unsigned short*)pActwk)[28]; /* Line 1549, Address: 0x102461c */

  if (radwk < 16384) { /* Line 1551, Address: 0x1024628 */

    ((unsigned short*)pActwk)[28] = 32768 - radwk; /* Line 1553, Address: 0x1024638 */









  } /* Line 1563, Address: 0x1024650 */
  else {
    ((unsigned short*)pActwk)[28] = 32768 - radwk; /* Line 1565, Address: 0x1024658 */
  }
} /* Line 1567, Address: 0x1024670 */








static unsigned int egg4awa_del(sprite_status* pActwk) { /* Line 1576, Address: 0x1024680 */
  patchg(pActwk, egg4awa_pchg); /* Line 1577, Address: 0x102468c */

  return 1; /* Line 1579, Address: 0x10246a0 */
} /* Line 1580, Address: 0x10246a4 */








static unsigned int egg4awa_out(sprite_status* pActwk) { /* Line 1589, Address: 0x10246c0 */
  frameout(pActwk); /* Line 1590, Address: 0x10246cc */

  return 0; /* Line 1592, Address: 0x10246d8 */
} /* Line 1593, Address: 0x10246dc */








static unsigned int egg4awa_chi(sprite_status* pActwk) { /* Line 1602, Address: 0x10246f0 */
  sprite_status* pEggact;
  short cntwk, radwk;
  static short rad_tbl[17] = {
    0,
    0,
    -32768,
    21845,
    16384,
    13107,
    10922,
    9362,
    8192,
    7281,
    6553,
    5957,
    5461,
    5041,
    4681,
    4369,
    4096
  };

  awa_hitchk(pActwk); /* Line 1625, Address: 0x1024708 */

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1627, Address: 0x1024714 */
  pActwk->xposi.l = pEggact->xposi.l; /* Line 1628, Address: 0x102473c */
  pActwk->yposi.l = pEggact->yposi.l; /* Line 1629, Address: 0x1024748 */
  ((int*)pActwk)[16] -= 65536; /* Line 1630, Address: 0x1024754 */
  ((int*)pActwk)[4] -= 65536; /* Line 1631, Address: 0x1024768 */

  if ((long int)((int*)pActwk)[16] <= 0x100000) { /* Line 1633, Address: 0x102477c */

    cntwk = pEggact->actfree[3]; /* Line 1635, Address: 0x10247a0 */
    radwk = rad_tbl[cntwk]; /* Line 1636, Address: 0x10247b0 */
    radwk *= pEggact->actfree[8]; /* Line 1637, Address: 0x10247d4 */
    ((short*)pActwk)[28] = radwk; /* Line 1638, Address: 0x10247e8 */

    ++pEggact->actfree[8]; /* Line 1640, Address: 0x10247f0 */

    ((int*)pActwk)[16] = 0x100000; /* Line 1642, Address: 0x10247fc */
    ((int*)pActwk)[4] = 0x100000; /* Line 1643, Address: 0x1024808 */
    pActwk->r_no0 = 6; /* Line 1644, Address: 0x1024814 */
  }


  awa_hitchk(pActwk); /* Line 1648, Address: 0x1024820 */
  if (pEggact->actfree[2] & 8) { /* Line 1649, Address: 0x102482c */

    ((short*)pActwk)[28] += 1152; /* Line 1651, Address: 0x1024840 */
  } /* Line 1652, Address: 0x1024850 */
  else {
    ((short*)pActwk)[28] -= 1152; /* Line 1654, Address: 0x1024858 */
  }


  egg4_posiset(pActwk); /* Line 1658, Address: 0x1024868 */

  return 1; /* Line 1660, Address: 0x1024874 */
} /* Line 1661, Address: 0x1024878 */
















































void egg4tama(sprite_status* pActwk) { /* Line 1710, Address: 0x10248a0 */
  if (egg4tama_act_tbl[pActwk->r_no0 / 2](pActwk) != 0) { /* Line 1711, Address: 0x10248ac */
    patchg(pActwk, egg4tama_pchg); /* Line 1712, Address: 0x10248f8 */
    actionsub(pActwk); /* Line 1713, Address: 0x102490c */
  }
} /* Line 1715, Address: 0x1024918 */





static unsigned int egg4tama_ini(sprite_status* pActwk) { /* Line 1721, Address: 0x1024930 */
  pActwk->r_no0 += 2; /* Line 1722, Address: 0x102493c */
  pActwk->actflg = 4; /* Line 1723, Address: 0x102494c */
  pActwk->sprpri = 6; /* Line 1724, Address: 0x1024958 */
  pActwk->sprhsize = 4; /* Line 1725, Address: 0x1024964 */
  pActwk->sprvsize = 4; /* Line 1726, Address: 0x1024970 */
  pActwk->sproffset = 798; /* Line 1727, Address: 0x102497c */
  pActwk->patbase = egg4tama_pat; /* Line 1728, Address: 0x1024988 */

  egg4tama_01(pActwk); /* Line 1730, Address: 0x1024998 */
} /* Line 1731, Address: 0x10249a4 */





static unsigned int egg4tama_01(sprite_status* pActwk) { /* Line 1737, Address: 0x10249c0 */
  sprite_status* pEggact;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1740, Address: 0x10249d0 */
  if (pEggact->actfree[2] & 128) { /* Line 1741, Address: 0x10249f8 */
    return egg4tama_kill(pActwk); /* Line 1742, Address: 0x1024a0c */
  }

  pActwk->xposi.w.h = pEggact->xposi.w.h; /* Line 1745, Address: 0x1024a20 */
  pActwk->yposi.w.h = pEggact->yposi.w.h; /* Line 1746, Address: 0x1024a2c */
  pActwk->xposi.w.h += ((short*)pActwk)[30]; /* Line 1747, Address: 0x1024a38 */
  pActwk->yposi.w.h += ((short*)pActwk)[31]; /* Line 1748, Address: 0x1024a50 */

  if (++pActwk->actfree[0] == 45) { /* Line 1750, Address: 0x1024a68 */
    pActwk->colino = 254; /* Line 1751, Address: 0x1024a8c */
    pActwk->colicnt = 2; /* Line 1752, Address: 0x1024a98 */
    pActwk->r_no0 += 2; /* Line 1753, Address: 0x1024aa4 */
  }


  return 1; /* Line 1757, Address: 0x1024ab4 */
} /* Line 1758, Address: 0x1024ab8 */





static unsigned int egg4tama_02(sprite_status* pActwk) { /* Line 1764, Address: 0x1024ad0 */
  sprite_status* pEggact;

  pEggact = &actwk[((short*)pActwk)[25]]; /* Line 1767, Address: 0x1024ae0 */
  if (pEggact->actfree[2] & 128) { /* Line 1768, Address: 0x1024b08 */
    return egg4tama_kill(pActwk); /* Line 1769, Address: 0x1024b1c */
  }

  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 1772, Address: 0x1024b30 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 1773, Address: 0x1024b48 */

  if (frameout_chk(pActwk) != 0) { /* Line 1775, Address: 0x1024b60 */
    return egg4tama_kill(pActwk); /* Line 1776, Address: 0x1024b74 */
  }

  return 1; /* Line 1779, Address: 0x1024b88 */
} /* Line 1780, Address: 0x1024b8c */





static unsigned int egg4tama_kill(sprite_status* pActwk) { /* Line 1786, Address: 0x1024ba0 */
  frameout(pActwk); /* Line 1787, Address: 0x1024bac */

  return 0; /* Line 1789, Address: 0x1024bb8 */
} /* Line 1790, Address: 0x1024bbc */





static unsigned int frameout_chk(sprite_status* pActwk) { /* Line 1796, Address: 0x1024bd0 */
  if (pActwk->xposi.w.h < 2464 /* Line 1797, Address: 0x1024bd8 */
      || pActwk->xposi.w.h > 2816
      || pActwk->yposi.w.h > 1488) {
    return 1; /* Line 1800, Address: 0x1024c2c */
  }

  return 0; /* Line 1803, Address: 0x1024c38 */

} /* Line 1805, Address: 0x1024c3c */
