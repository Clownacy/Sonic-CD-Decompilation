#include "..\EQU.H"
#include "CHGBAN.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"

static void ami_init(sprite_status* pActwk);
static void ami_move(sprite_status* pActwk);
static void chgban_init(sprite_status* pActwk);
static void chgban_move0(sprite_status* pActwk);
static void chgban_move1(sprite_status* pActwk);
static void chgban_move2(sprite_status* pActwk);
static void spr_r_init(sprite_status* pActwk);
static void spr_r_move0(sprite_status* pActwk);
static void spr_r_move1(sprite_status* pActwk);
static void spr_r_move2(sprite_status* pActwk);
static void spr_r_move3(sprite_status* pActwk);
static void spr_r_move4(sprite_status* pActwk);
static void spr_r_move5(sprite_status* pActwk);
static void spr_r_move6(sprite_status* pActwk);
static void gun7_init(sprite_status* pActwk);
static void gun7_move0(sprite_status* pActwk);
static void gun7_move1(sprite_status* pActwk);
static void gun7_move2(sprite_status* pActwk);
static void hibana_init(sprite_status* pActwk);
static void hibana_move0(sprite_status* pActwk);
static void hibana_move1(sprite_status* pActwk);
static void spr_r_set(sprite_status* pActwk);
static void coli_spr(sprite_status* pActwk);
static unsigned int coli0(sprite_status* pActwk, sprite_status* pPlayerwk, short xOffs, short yOffs);
static void playset(sprite_status* pActwk, sprite_status* pPlayerwk);
static short pposiset(sprite_status* pActwk, sprite_status* pMstwk, sprite_status* pPlayerwk, char* pPostbl);
static void plspdset(sprite_status* pActwk, sprite_status* pPlayerwk, short patcnt);
static void g_move0(sprite_status* pActwk, unsigned char* pPatTbl, unsigned char* pRevTbl, unsigned char* pGposiTbl, unsigned char* pPposiTbl);
static void playset_g(sprite_status* pActwk, sprite_status* pMstadr, sprite_status* pPlayerwk, unsigned char* pPposiTbl);
static void gspdset(sprite_status* pMstadr, sprite_status* pGawaadr);
static void gun7_coli(sprite_status* pActwk);
static void gun7set(sprite_status* pActwk);

static char srevtbl0[9] = { 0, 0, 0, 0, 1, 1, 1, 0, 0 };
static char srevtbl1[9] = { 2, 0, 0, 0, 1, 1, 3, 2, 2 };
static char srevtbl2[9] = { 1, 1, 3, 2, 2, 0, 0, 0, 1 };
static short spositbl0[18] = {
   8, -8,
   8,  0,
   8, -8,
   0, -8,
  -8, -8,
  -8,  0,
  -8, -8,
   0, -8,
   8, -8
};
static short spositbl1[18] = {
   8,  8,
   8,  0,
   8, -8,
   0, -8,
  -8, -8,
  -8,  0,
  -8,  8,
   0,  8,
   8,  8
};
static short spositbl2[18] = {
  -8, -8,
  -8,  0,
  -8,  8,
   0,  8,
   8,  8,
   8,  0,
   8, -8,
   0, -8,
  -8, -8
};
static char ppositbl0[9] = { 1, 0, 1, 2, 3, 4, 3, 2, 1 };
static char ppositbl1[9] = { 7, 0, 1, 2, 3, 4, 5, 6, 7 };
static char ppositblg_0[9] = { 1, 0, 1, 2, 3, 4, 5, 6, 7 };
static char ppositblg_1[9] = { 3, 4, 5, 6, 7, 0, 1, 2, 3 };
static short ppositbl[16] = {
   24,   0,
   24, -24,
    0, -24,
  -24, -24,
  -24,   0,
  -24,  24,
    0,  24,
   24,  24
};
static unsigned char gpattbl[9] = { 4, 2, 4, 3, 4, 2, 4, 3, 4 };
static unsigned char grevtbl0_0[9] = { 0, 0, 0, 0, 2, 2, 2, 0, 0 };
static unsigned char grevtbl0_1[9] = { 3, 2, 3, 1, 1, 0, 1, 1, 3 };
static unsigned char grevtbl1_0[9] = { 1, 0, 0, 0, 2, 2, 3, 1, 1 };
static unsigned char grevtbl1_1[9] = { 2, 2, 3, 1, 1, 0, 0, 0, 2 };
static unsigned char gpositbl0_0[9] = { 1, 0, 1, 2, 3, 4, 3, 2, 1 };
static unsigned char gpositbl0_1[9] = { 9, 8, 9, 10, 11, 12, 11, 10, 9 };
static unsigned char gpositbl1_0[9] = { 7, 0, 1, 2, 3, 4, 5, 6, 7 };
static unsigned char gpositbl1_1[9] = { 3, 4, 5, 6, 7, 0, 1, 2, 3 };
static unsigned char gpositbl2_0[9] = { 11, 12, 13, 14, 15, 8, 9, 10, 11 };
static unsigned char gpositbl2_1[9] = { 15, 8, 9, 10, 11, 12, 13, 14, 15 };
static short gpositbl[32] = {
   24, -16,
    4, -28,
  -16, -24,
  -28,  -4,
  -24,  16,
   -4,  28,
   16,  24,
   28,   4,
   24,  16,
   28,  -4,
   16, -24,
   -4, -28,
  -24, -16,
  -28,   4,
  -16,  24,
    4,  28
};
static short gspdtbl0[18] = {
  -1, -1,
  -1,  0,
  -1,  1,
   0,  1,
   1,  1,
   1,  0,
   1, -1,
   0, -1,
  -1, -1
};
static short gspdtbl1[18] = {
   1,  1,
   1,  0,
   1, -1,
   0, -1,
  -1, -1,
  -1,  0,
  -1,  1,
   0,  1,
   1,  1
};
sprite_pattern amipat0 = {
  1,
  { { -16, -16, 0, 453 } }
};
sprite_pattern* amipat[1] = { &amipat0 };
static void(*ami_act_tbl[2])(sprite_status*) = {
  &ami_init,
  &ami_move
};
static unsigned char chgbanchg0[11] = { 4, 0, 1, 2, 3, 4, 3, 2, 1, 0, 252 };
static unsigned char* chgbanchg[1] = { chgbanchg0 };
sprite_pattern chgbanpat0 = {
  1,
  { { -24, -16, 0, 454 } }
};
sprite_pattern chgbanpat1 = {
  1,
  { { -24, -12, 0, 455 } }
};
sprite_pattern chgbanpat2 = {
  1,
  { { -24, -8, 0, 456 } }
};
sprite_pattern chgbanpat3 = {
  1,
  { { -24, -16, 0, 457 } }
};
sprite_pattern chgbanpat4 = {
  1,
  { { -24, -12, 0, 458 } }
};
sprite_pattern* chgbanpat[5] = {
  &chgbanpat0,
  &chgbanpat1,
  &chgbanpat2,
  &chgbanpat3,
  &chgbanpat4
};
static void(*chgban_act_tbl[4])(sprite_status*) = {
  &chgban_init,
  &chgban_move0,
  &chgban_move1,
  &chgban_move2
};
unsigned char spr_rchg0[10] = { 5, 1, 1, 1, 1, 1, 1, 1, 1, 255 };
unsigned char* spr_rchg[1] = { spr_rchg0 };
sprite_pattern spr_rpat0 = {
  1,
  { { -8, -4, 0, 459 } }
};
sprite_pattern spr_rpat1 = {
  1,
  { { -8, -8, 0, 460 } }
};
sprite_pattern spr_rpat2 = {
  1,
  { { -32, -12, 0, 461 } }
};
sprite_pattern spr_rpat3 = {
  1,
  { { -12, -32, 0, 462 } }
};
sprite_pattern spr_rpat4 = {
  1,
  { { -28, -28, 0, 463 } }
};
sprite_pattern* spr_rpat[5] = {
  &spr_rpat0,
  &spr_rpat1,
  &spr_rpat2,
  &spr_rpat3,
  &spr_rpat4
};
static void(*spring_r_act_tbl[8])(sprite_status*) = {
  &spr_r_init,
  &spr_r_move0,
  &spr_r_move1,
  &spr_r_move2,
  &spr_r_move3,
  &spr_r_move4,
  &spr_r_move5,
  &spr_r_move6
};
extern sprite_pattern* spring90pat2[];
extern unsigned char* springchg[];
static unsigned char prio_sav;
static void(*gun7_act_tbl[4])(sprite_status*) = {
  &gun7_init,
  &gun7_move0,
  &gun7_move1,
  &gun7_move2
};
static unsigned char hibanachg0[6] = { 3, 0, 1, 0, 1, 252 };
static unsigned char* hibanachg[1] = { hibanachg0 };
sprite_pattern hibanapat0 = {
  1,
  { { -32, -32, 0, 464 } }
};
sprite_pattern hibanapat1 = {
  1,
  { { -24, -16, 0, 465 } }
};
sprite_pattern* hibanapat[2] = {
  &hibanapat0,
  &hibanapat1
};
static void(*hibana_act_tbl[3])(sprite_status*) = {
  &hibana_init,
  &hibana_move0,
  &hibana_move1
};











void ami(sprite_status* pActwk) { /* Line 265, Address: 0x101a320 */
  ami_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 266, Address: 0x101a32c */
  actionsub(pActwk); /* Line 267, Address: 0x101a370 */
  frameout_s(pActwk); /* Line 268, Address: 0x101a37c */
} /* Line 269, Address: 0x101a388 */





static void ami_init(sprite_status* pActwk) { /* Line 275, Address: 0x101a3a0 */
  pActwk->actflg |= 4; /* Line 276, Address: 0x101a3ac */
  pActwk->sproffset = 17144; /* Line 277, Address: 0x101a3bc */
  pActwk->patbase = amipat; /* Line 278, Address: 0x101a3c8 */
  pActwk->r_no0 += 2; /* Line 279, Address: 0x101a3d8 */

  ami_move(pActwk); /* Line 281, Address: 0x101a3e8 */
} /* Line 282, Address: 0x101a3f4 */





static void ami_move(sprite_status* pActwk) { /* Line 288, Address: 0x101a410 */
  if (prio_flag) { /* Line 289, Address: 0x101a418 */
    pActwk->sprpri = 0; /* Line 290, Address: 0x101a428 */
  } else { /* Line 291, Address: 0x101a430 */
    pActwk->sprpri = 4; /* Line 292, Address: 0x101a438 */
  }
} /* Line 294, Address: 0x101a444 */
























































void chgban(sprite_status* pActwk) { /* Line 351, Address: 0x101a450 */
  chgban_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 352, Address: 0x101a45c */
  actionsub(pActwk); /* Line 353, Address: 0x101a4a0 */
  frameout_s(pActwk); /* Line 354, Address: 0x101a4ac */
} /* Line 355, Address: 0x101a4b8 */





static void chgban_init(sprite_status* pActwk) { /* Line 361, Address: 0x101a4d0 */
  if (pActwk->userflag.b.h) { /* Line 362, Address: 0x101a4dc */
    pActwk->actflg |= 2; /* Line 363, Address: 0x101a4ec */
  }


  pActwk->r_no0 += 2; /* Line 367, Address: 0x101a4fc */
  pActwk->actflg |= 4; /* Line 368, Address: 0x101a50c */
  pActwk->sproffset = 845; /* Line 369, Address: 0x101a51c */

  if (!prio_flag) { /* Line 371, Address: 0x101a528 */
    pActwk->sproffset |= 32768; /* Line 372, Address: 0x101a538 */
  }


  pActwk->patbase = chgbanpat; /* Line 376, Address: 0x101a548 */
  pActwk->sprhs = pActwk->sprhsize = pActwk->sprvsize = 24; /* Line 377, Address: 0x101a558 */

  chgban_move0(pActwk); /* Line 379, Address: 0x101a57c */
} /* Line 380, Address: 0x101a588 */





static void chgban_move0(sprite_status* pActwk) { /* Line 386, Address: 0x101a5a0 */
  short xsz, xdst, ysz, ydst;

  if (pActwk->actfree[0]) { /* Line 389, Address: 0x101a5b8 */
    --pActwk->actfree[0]; /* Line 390, Address: 0x101a5c8 */
    return; /* Line 391, Address: 0x101a5d8 */
  }


  xsz = (short)(char)pActwk->sprhs + (short)(char)actwk[0].sprhs; /* Line 395, Address: 0x101a5e0 */
  xdst = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 396, Address: 0x101a634 */

  ysz = (short)(char)pActwk->sprvsize + (short)(char)actwk[0].sprvsize; /* Line 398, Address: 0x101a668 */

  ydst = pActwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 400, Address: 0x101a6bc */

  if ((xdst += xsz) < 0 || xdst >= xsz * 2 /* Line 402, Address: 0x101a6f0 */
      ||
      (ydst += ysz) < 0 || ydst >= ysz * 2) {
    if (((pActwk->sproffset & 32768) && prio_flag) /* Line 405, Address: 0x101a778 */
        ||
        (!(pActwk->sproffset & 32768) && !prio_flag)) {
      pActwk->actfree[0] = 60; /* Line 408, Address: 0x101a7c8 */
      pActwk->r_no0 += 2; /* Line 409, Address: 0x101a7d4 */
    }
  } else { /* Line 411, Address: 0x101a7e4 */
    pActwk->actfree[0] = 60; /* Line 412, Address: 0x101a7ec */
    pActwk->r_no0 += 2; /* Line 413, Address: 0x101a7f8 */
    prio_flag ^= 1; /* Line 414, Address: 0x101a808 */
  }
} /* Line 416, Address: 0x101a81c */





static void chgban_move1(sprite_status* pActwk) { /* Line 422, Address: 0x101a840 */
  patchg(pActwk, chgbanchg); /* Line 423, Address: 0x101a84c */
} /* Line 424, Address: 0x101a860 */





static void chgban_move2(sprite_status* pActwk) { /* Line 430, Address: 0x101a870 */
  if (!prio_flag) { /* Line 431, Address: 0x101a878 */
    pActwk->sproffset |= 32768; /* Line 432, Address: 0x101a888 */
    pActwk->sprpri = 4; /* Line 433, Address: 0x101a898 */
  } else { /* Line 434, Address: 0x101a8a4 */
    pActwk->sproffset &= 32767; /* Line 435, Address: 0x101a8ac */
    pActwk->sprpri = 0; /* Line 436, Address: 0x101a8bc */
  }


  pActwk->patcnt = 0; /* Line 440, Address: 0x101a8c4 */
  pActwk->r_no0 -= 4; /* Line 441, Address: 0x101a8cc */
} /* Line 442, Address: 0x101a8dc */




























































void spring_r(sprite_status* pActwk) { /* Line 503, Address: 0x101a8f0 */
  int mstwkno, gawa0wkno, gawa1wkno;

  if (pActwk->r_no0 >= 4 && pActwk->actfree[20]) { /* Line 506, Address: 0x101a908 */
    frameout(pActwk); /* Line 507, Address: 0x101a930 */
    return; /* Line 508, Address: 0x101a93c */
  }


  if (!pActwk->r_no0 || actwk[0].r_no0 < 6) { /* Line 512, Address: 0x101a944 */

    spring_r_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 514, Address: 0x101a96c */
    if (pActwk->r_no0 != 4 || !pActwk->userflag.b.h) { /* Line 515, Address: 0x101a9b0 */

      actionsub(pActwk); /* Line 517, Address: 0x101a9d8 */
    }
  } /* Line 519, Address: 0x101a9e4 */
  else {
    actionsub(pActwk); /* Line 521, Address: 0x101a9ec */
  }


  if (pActwk->r_no0 != 2) return; /* Line 525, Address: 0x101a9f8 */




  mstwkno = *(int*)&pActwk->actfree[0]; /* Line 530, Address: 0x101aa10 */
  gawa0wkno = *(int*)&pActwk->actfree[12]; /* Line 531, Address: 0x101aa1c */
  gawa1wkno = *(int*)&pActwk->actfree[16]; /* Line 532, Address: 0x101aa28 */

  if (frameout_s00(pActwk, ((short*)pActwk)[28]) != 0) { /* Line 534, Address: 0x101aa34 */

    actwk[mstwkno].actfree[20] = 1; /* Line 536, Address: 0x101aa50 */
    actwk[gawa0wkno].actfree[20] = 1; /* Line 537, Address: 0x101aa70 */
    actwk[gawa1wkno].actfree[20] = 1; /* Line 538, Address: 0x101aa90 */
  }
} /* Line 540, Address: 0x101aab0 */





static void spr_r_init(sprite_status* pActwk) { /* Line 546, Address: 0x101aad0 */
  sprite_status *pNewact, *pTstwk;
  int i;
  unsigned char r_nowk;

  pActwk->r_no0 += 2; /* Line 551, Address: 0x101aae4 */
  ((short*)pActwk)[28] = pActwk->xposi.w.h; /* Line 552, Address: 0x101aaf4 */
  pActwk->actflg |= 4; /* Line 553, Address: 0x101ab04 */
  pActwk->sproffset = 768; /* Line 554, Address: 0x101ab14 */
  pActwk->patbase = spr_rpat; /* Line 555, Address: 0x101ab20 */
  pActwk->sprhs = 8; /* Line 556, Address: 0x101ab30 */
  pActwk->sprvsize = 8; /* Line 557, Address: 0x101ab3c */
  pActwk->patno = 1; /* Line 558, Address: 0x101ab48 */

  if (pActwk->userflag.b.h >= 2) { /* Line 560, Address: 0x101ab54 */
    pActwk->userflag.b.l = pActwk->patcnt = pActwk->userflag.b.h - 1; /* Line 561, Address: 0x101ab70 */
    pActwk->userflag.b.h = 0; /* Line 562, Address: 0x101aba4 */
  }


  pNewact = pActwk; /* Line 566, Address: 0x101abac */
  for (i = 0; i < 3; ++i) { /* Line 567, Address: 0x101abb4 */

    if (actwkchk2(pNewact, &pTstwk) != 0) { /* Line 569, Address: 0x101abc0 */
      frameout(pActwk); /* Line 570, Address: 0x101abd8 */
      return; /* Line 571, Address: 0x101abe4 */
    }

    pNewact = pTstwk; /* Line 574, Address: 0x101abec */
  } /* Line 575, Address: 0x101abf4 */

  r_nowk = 4; /* Line 577, Address: 0x101ac04 */
  for (i = 2; i >= 0; --i) { /* Line 578, Address: 0x101ac0c */

    actwkchk2(pActwk, &pNewact); /* Line 580, Address: 0x101ac18 */

    pNewact->actno = 30; /* Line 582, Address: 0x101ac28 */
    pNewact->actflg |= 4; /* Line 583, Address: 0x101ac34 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 584, Address: 0x101ac44 */
    ((short*)pNewact)[28] = pActwk->xposi.w.h; /* Line 585, Address: 0x101ac54 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 586, Address: 0x101ac64 */

    if (i == 2) { /* Line 588, Address: 0x101ac74 */
      pNewact->sproffset = 1312; /* Line 589, Address: 0x101ac80 */
      pNewact->patbase = spring90pat2; /* Line 590, Address: 0x101ac8c */
      pNewact->sprpri = 5; /* Line 591, Address: 0x101ac9c */
      *(int*)&pActwk->actfree[0] = pNewact - actwk; /* Line 592, Address: 0x101aca8 */
    } /* Line 593, Address: 0x101acdc */
    else {
      pNewact->sproffset = 768; /* Line 595, Address: 0x101ace4 */
      pNewact->patbase = spr_rpat; /* Line 596, Address: 0x101acf0 */
      pNewact->sprhs = 32; /* Line 597, Address: 0x101ad00 */
      pNewact->sprvsize = 32; /* Line 598, Address: 0x101ad0c */

      if (i == 1) { /* Line 600, Address: 0x101ad18 */
        *(int*)&pActwk->actfree[12] = pNewact - actwk; /* Line 601, Address: 0x101ad24 */
      } /* Line 602, Address: 0x101ad58 */
      else {
        *(int*)&pActwk->actfree[16] = pNewact - actwk; /* Line 604, Address: 0x101ad60 */
      }
    }


    pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 609, Address: 0x101ad94 */
    *(int*)&pNewact->actfree[0] = pActwk - actwk; /* Line 610, Address: 0x101ada4 */
    pNewact->r_no0 = r_nowk; /* Line 611, Address: 0x101add8 */

    if (i == 2) { /* Line 613, Address: 0x101ade0 */
      r_nowk += 4; /* Line 614, Address: 0x101adec */
    }

    r_nowk += 2; /* Line 617, Address: 0x101adf4 */
  } /* Line 618, Address: 0x101adfc */

  spr_r_move0(pActwk); /* Line 620, Address: 0x101ae08 */
} /* Line 621, Address: 0x101ae14 */





static void spr_r_move0(sprite_status* pActwk) { /* Line 627, Address: 0x101ae30 */
  sprite_status* pMstwk;

  if (!pActwk->userflag.b.l) { /* Line 630, Address: 0x101ae40 */
    pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 631, Address: 0x101ae50 */

    if (pMstwk->r_no0 < 6 || pMstwk->userflag.b.l == 2) { /* Line 633, Address: 0x101ae74 */

      patchg(pActwk, spr_rchg); /* Line 635, Address: 0x101aea0 */
    }
  }
} /* Line 638, Address: 0x101aeb4 */





static void spr_r_move1(sprite_status* pActwk) { /* Line 644, Address: 0x101aed0 */
  if (!pActwk->userflag.b.h) { /* Line 645, Address: 0x101aedc */
    spr_r_set(pActwk); /* Line 646, Address: 0x101aeec */
    coli_spr(pActwk); /* Line 647, Address: 0x101aef8 */
  }
} /* Line 649, Address: 0x101af04 */





static void spr_r_move2(sprite_status* pActwk) { /* Line 655, Address: 0x101af20 */
  sprite_status *pMstadr, *pPlayerwk;

  pPlayerwk = &actwk[*(int*)&pActwk->actfree[4]]; /* Line 658, Address: 0x101af34 */

  if (pActwk->userflag.b.h) { /* Line 660, Address: 0x101af58 */

    if (pActwk->userflag.b.l == 4) { /* Line 662, Address: 0x101af68 */

      patchg(pActwk, springchg); /* Line 664, Address: 0x101af84 */


      spr_r_set(pActwk); /* Line 667, Address: 0x101af98 */
    } else if (pActwk->userflag.b.l != 2 || !(swdata.b.l & 112)) { /* Line 668, Address: 0x101afa4 */

      spr_r_set(pActwk); /* Line 670, Address: 0x101afe0 */
    } else { /* Line 671, Address: 0x101afec */
      pActwk->userflag.b.l = 4; /* Line 672, Address: 0x101aff4 */
      pMstadr = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 673, Address: 0x101b000 */
      plspdset(pActwk, pPlayerwk, pMstadr->patcnt); /* Line 674, Address: 0x101b024 */


      actwk[0].actfree[2] &= 254; /* Line 677, Address: 0x101b03c */
      soundset(206); /* Line 678, Address: 0x101b050 */


      patchg(pActwk, springchg); /* Line 681, Address: 0x101b05c */


      spr_r_set(pActwk); /* Line 684, Address: 0x101b070 */
    }
  } /* Line 686, Address: 0x101b07c */
  else {
    if (!pActwk->actfree[8]) { /* Line 688, Address: 0x101b084 */

      patchg(pActwk, springchg); /* Line 690, Address: 0x101b094 */


      spr_r_set(pActwk); /* Line 693, Address: 0x101b0a8 */
    } else if (--pActwk->actfree[8] != 0) { /* Line 694, Address: 0x101b0b4 */

      spr_r_set(pActwk); /* Line 696, Address: 0x101b0dc */
    } /* Line 697, Address: 0x101b0e8 */
    else {
      actwk[0].actfree[2] &= 254; /* Line 699, Address: 0x101b0f0 */
      soundset(206); /* Line 700, Address: 0x101b104 */


      patchg(pActwk, springchg); /* Line 703, Address: 0x101b110 */


      spr_r_set(pActwk); /* Line 706, Address: 0x101b124 */
    }
  }
} /* Line 709, Address: 0x101b130 */





static void spr_r_move3(sprite_status* pActwk) { /* Line 715, Address: 0x101b150 */
  sprite_status *pMstwk, *pGawawk;

  pActwk->r_no0 -= 4; /* Line 718, Address: 0x101b160 */
  pActwk->patcnt = 0; /* Line 719, Address: 0x101b170 */
  pActwk->patno = 0; /* Line 720, Address: 0x101b178 */
  pActwk->userflag.b.l = 0; /* Line 721, Address: 0x101b180 */

  if (pActwk->userflag.b.h) { /* Line 723, Address: 0x101b188 */

    pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 725, Address: 0x101b198 */
    pGawawk = &actwk[*(int*)&pMstwk->actfree[12]]; /* Line 726, Address: 0x101b1bc */
    pGawawk->userflag.b.l = 0; /* Line 727, Address: 0x101b1dc */
    pGawawk = &actwk[*(int*)&pMstwk->actfree[16]]; /* Line 728, Address: 0x101b1e0 */
    pGawawk->userflag.b.l = 0; /* Line 729, Address: 0x101b200 */
    pActwk->userflag.b.l = 0; /* Line 730, Address: 0x101b204 */
  }


} /* Line 734, Address: 0x101b20c */





static void spr_r_move4(sprite_status* pActwk) { /* Line 740, Address: 0x101b220 */
  unsigned char *pPattbl, *pRevtbl, *pPositbl;

  pPattbl = gpattbl; /* Line 743, Address: 0x101b238 */

  if (!pActwk->userflag.b.h) { /* Line 745, Address: 0x101b240 */
    pRevtbl = grevtbl0_0; /* Line 746, Address: 0x101b250 */
    pPositbl = gpositbl0_0; /* Line 747, Address: 0x101b258 */
  } /* Line 748, Address: 0x101b260 */
  else {
    pRevtbl = grevtbl1_0; /* Line 750, Address: 0x101b268 */

    if (!pActwk->userflag.b.l) { /* Line 752, Address: 0x101b270 */
      pPositbl = gpositbl1_0; /* Line 753, Address: 0x101b280 */
    } else { /* Line 754, Address: 0x101b288 */
      pPositbl = gpositbl2_0; /* Line 755, Address: 0x101b290 */
    }
  }


  g_move0(pActwk, pPattbl, pRevtbl, pPositbl, (unsigned char*)ppositblg_0); /* Line 760, Address: 0x101b298 */
} /* Line 761, Address: 0x101b2b8 */





static void spr_r_move5(sprite_status* pActwk) { /* Line 767, Address: 0x101b2e0 */
  unsigned char *pPattbl, *pRevtbl, *pPositbl;

  pPattbl = gpattbl; /* Line 770, Address: 0x101b2f8 */

  if (!pActwk->userflag.b.h) { /* Line 772, Address: 0x101b300 */
    pRevtbl = grevtbl0_1; /* Line 773, Address: 0x101b310 */
    pPositbl = gpositbl0_1; /* Line 774, Address: 0x101b318 */
  } /* Line 775, Address: 0x101b320 */
  else {
    pRevtbl = grevtbl1_1; /* Line 777, Address: 0x101b328 */

    if (!pActwk->userflag.b.l) { /* Line 779, Address: 0x101b330 */
      pPositbl = gpositbl1_1; /* Line 780, Address: 0x101b340 */
    } else { /* Line 781, Address: 0x101b348 */
      pPositbl = gpositbl2_1; /* Line 782, Address: 0x101b350 */
    }
  }


  g_move0(pActwk, pPattbl, pRevtbl, pPositbl, (unsigned char*)ppositblg_1); /* Line 787, Address: 0x101b358 */
} /* Line 788, Address: 0x101b378 */





static void spr_r_move6(sprite_status* pActwk) { /* Line 794, Address: 0x101b3a0 */
  sprite_status* pMstwk;

  if (!(--pActwk->actfree[8])) { /* Line 797, Address: 0x101b3b0 */
    pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 798, Address: 0x101b3cc */
    pMstwk = &actwk[*(int*)&pMstwk->actfree[0]]; /* Line 799, Address: 0x101b3f0 */
    pMstwk->userflag.b.l = 2; /* Line 800, Address: 0x101b410 */
    pActwk->r_no0 = pActwk->r_no1; /* Line 801, Address: 0x101b418 */
    soundset(192); /* Line 802, Address: 0x101b428 */

    actwk[0].sproffset |= prio_sav << 8; /* Line 804, Address: 0x101b434 */
    prio_sav = 0; /* Line 805, Address: 0x101b45c */
  }



  pActwk->xposi.w.h += pActwk->xspeed.w; /* Line 810, Address: 0x101b464 */
  pActwk->yposi.w.h += pActwk->yspeed.w; /* Line 811, Address: 0x101b47c */
} /* Line 812, Address: 0x101b494 */

























void gun7(sprite_status* pActwk) { /* Line 838, Address: 0x101b4b0 */
  gun7_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 839, Address: 0x101b4bc */
  actionsub(pActwk); /* Line 840, Address: 0x101b500 */
  frameout_s(pActwk); /* Line 841, Address: 0x101b50c */
} /* Line 842, Address: 0x101b518 */





static void gun7_init(sprite_status* pActwk) { /* Line 848, Address: 0x101b530 */
  pActwk->r_no0 += 2; /* Line 849, Address: 0x101b53c */
  pActwk->actflg |= 4; /* Line 850, Address: 0x101b54c */
  pActwk->sproffset = 768; /* Line 851, Address: 0x101b55c */
  pActwk->patbase = spr_rpat; /* Line 852, Address: 0x101b568 */
  pActwk->sprhsize = 32; /* Line 853, Address: 0x101b578 */
  pActwk->sprvsize = 12; /* Line 854, Address: 0x101b584 */

  pActwk->patno = 2; /* Line 856, Address: 0x101b590 */
  if (!pActwk->userflag.b.h) { /* Line 857, Address: 0x101b59c */
    gun7_move0(pActwk); /* Line 858, Address: 0x101b5ac */
  } else { /* Line 859, Address: 0x101b5b8 */
    pActwk->patno = 0; /* Line 860, Address: 0x101b5c0 */
    pActwk->yspeed.w = -2048; /* Line 861, Address: 0x101b5c8 */
    pActwk->r_no0 = 6; /* Line 862, Address: 0x101b5d4 */
    gun7_move2(pActwk); /* Line 863, Address: 0x101b5e0 */
  }
} /* Line 865, Address: 0x101b5ec */





static void gun7_move0(sprite_status* pActwk) { /* Line 871, Address: 0x101b600 */
  gun7_coli(pActwk); /* Line 872, Address: 0x101b60c */
} /* Line 873, Address: 0x101b618 */





static void gun7_move1(sprite_status* pActwk) { /* Line 879, Address: 0x101b630 */
  if (pActwk->actfree[0]) { /* Line 880, Address: 0x101b63c */
    speedset2(pActwk); /* Line 881, Address: 0x101b64c */

    if (--pActwk->actfree[0]) return; /* Line 883, Address: 0x101b658 */
    pActwk->xspeed.w *= -1; /* Line 884, Address: 0x101b674 */

  } /* Line 886, Address: 0x101b684 */
  else {
    speedset2(pActwk); /* Line 888, Address: 0x101b68c */

    if (pActwk->xposi.w.h == ((short*)pActwk)[24]) { /* Line 890, Address: 0x101b698 */
      pActwk->r_no0 -= 2; /* Line 891, Address: 0x101b6c0 */
    }
  }
} /* Line 894, Address: 0x101b6d0 */





static void gun7_move2(sprite_status* pActwk) { /* Line 900, Address: 0x101b6e0 */
  pActwk->yspeed.w += 64; /* Line 901, Address: 0x101b6ec */
  speedset2(pActwk); /* Line 902, Address: 0x101b6fc */
  if (scra_v_posit.w.h + 232 < pActwk->yposi.w.h) { /* Line 903, Address: 0x101b708 */
    frameout(pActwk); /* Line 904, Address: 0x101b738 */
  }
} /* Line 906, Address: 0x101b744 */














































void hibana(sprite_status* pActwk) { /* Line 953, Address: 0x101b760 */
  hibana_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 954, Address: 0x101b76c */
  actionsub(pActwk); /* Line 955, Address: 0x101b7b0 */
} /* Line 956, Address: 0x101b7bc */





static void hibana_init(sprite_status* pActwk) { /* Line 962, Address: 0x101b7d0 */
  pActwk->r_no0 += 2; /* Line 963, Address: 0x101b7d8 */
  pActwk->actflg |= 4; /* Line 964, Address: 0x101b7e8 */
  pActwk->sproffset = 33592; /* Line 965, Address: 0x101b7f8 */
  pActwk->patbase = hibanapat; /* Line 966, Address: 0x101b804 */
} /* Line 967, Address: 0x101b814 */





static void hibana_move0(sprite_status* pActwk) { /* Line 973, Address: 0x101b820 */
  patchg(pActwk, hibanachg); /* Line 974, Address: 0x101b82c */
} /* Line 975, Address: 0x101b840 */





static void hibana_move1(sprite_status* pActwk) { /* Line 981, Address: 0x101b850 */
  frameout(pActwk); /* Line 982, Address: 0x101b85c */
} /* Line 983, Address: 0x101b868 */
















static void spr_r_set(sprite_status* pActwk) { /* Line 1000, Address: 0x101b880 */
  char* pRevtbl;
  short* pPostbl;
  short patcntwk;
  sprite_status* pMstwk;
  static sprite_pattern** tbl1[3];
  static char tbl0[9];




  switch (pActwk->userflag.b.h) { /* Line 1011, Address: 0x101b898 */
    case 0:
      pRevtbl = srevtbl0; /* Line 1013, Address: 0x101b8c4 */
      pPostbl = spositbl0; /* Line 1014, Address: 0x101b8cc */
      break; /* Line 1015, Address: 0x101b8d4 */

    case 1:
      pRevtbl = srevtbl1; /* Line 1018, Address: 0x101b8dc */
      pPostbl = spositbl1; /* Line 1019, Address: 0x101b8e4 */
      break; /* Line 1020, Address: 0x101b8ec */

    default:
      pRevtbl = srevtbl2; /* Line 1023, Address: 0x101b8f4 */
      pPostbl = spositbl2; /* Line 1024, Address: 0x101b8fc */
      break;
  }



  pActwk->sproffset = 1312; /* Line 1030, Address: 0x101b904 */
  pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1031, Address: 0x101b910 */
  patcntwk = pMstwk->patcnt; /* Line 1032, Address: 0x101b934 */

  if (!(patcntwk & 1)) { /* Line 1034, Address: 0x101b944 */
    pActwk->sproffset = 1266; /* Line 1035, Address: 0x101b958 */
  }


  pActwk->patbase = tbl1[tbl0[patcntwk]]; /* Line 1039, Address: 0x101b964 */
  pActwk->actflg &= 252; /* Line 1040, Address: 0x101b9a0 */
  pActwk->actflg |= pRevtbl[patcntwk]; /* Line 1041, Address: 0x101b9b0 */
  pActwk->xposi.w.h = pMstwk->xposi.w.h + pPostbl[patcntwk * 2]; /* Line 1042, Address: 0x101b9d4 */
  pActwk->yposi.w.h = pMstwk->yposi.w.h + pPostbl[patcntwk * 2 + 1]; /* Line 1043, Address: 0x101ba14 */
} /* Line 1044, Address: 0x101ba58 */













static void coli_spr(sprite_status* pActwk) { /* Line 1058, Address: 0x101ba80 */
  if (editmode.b.h) return; /* Line 1059, Address: 0x101ba8c */



  if (coli0(pActwk, &actwk[0], 32, 32) != 0) { /* Line 1063, Address: 0x101ba9c */
    playset(pActwk, &actwk[0]); /* Line 1064, Address: 0x101bac0 */
  }
} /* Line 1066, Address: 0x101bad4 */






static unsigned int coli0(sprite_status* pActwk, sprite_status* pPlayerwk, short xOffs, short yOffs) { /* Line 1073, Address: 0x101baf0 */
  short sizwk, poswk;

  if (pPlayerwk->r_no0 == 4) { /* Line 1076, Address: 0x101bb0c */
    pPlayerwk->r_no0 -= 2; /* Line 1077, Address: 0x101bb24 */
    ((short*)pPlayerwk)[26] = 120; /* Line 1078, Address: 0x101bb34 */
  }


  if (pPlayerwk->mstno.b.h == 43 || pPlayerwk->r_no0 >= 6) { /* Line 1082, Address: 0x101bb40 */
    return 0; /* Line 1083, Address: 0x101bb74 */
  }

  sizwk = (short)(char)pPlayerwk->sprhs + xOffs; /* Line 1086, Address: 0x101bb80 */
  poswk = pActwk->xposi.w.h - pPlayerwk->xposi.w.h; /* Line 1087, Address: 0x101bbc0 */

  if ((poswk += sizwk) < 0 || poswk >= sizwk * 2) { /* Line 1089, Address: 0x101bbf4 */
    return 0; /* Line 1090, Address: 0x101bc38 */
  }

  sizwk = (short)(char)pPlayerwk->sprvsize + yOffs; /* Line 1093, Address: 0x101bc44 */
  poswk = pActwk->yposi.w.h - pPlayerwk->yposi.w.h; /* Line 1094, Address: 0x101bc84 */

  if ((poswk += sizwk) < 0 || poswk >= sizwk * 2) { /* Line 1096, Address: 0x101bcb8 */
    return 0; /* Line 1097, Address: 0x101bcfc */
  }

  return 1; /* Line 1100, Address: 0x101bd08 */
} /* Line 1101, Address: 0x101bd0c */













static void playset(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 1115, Address: 0x101bd20 */
  sprite_status* pMstwk;
  short cntwk;

  pPlayerwk->actfree[18] = 0; /* Line 1119, Address: 0x101bd38 */
  pPlayerwk->actfree[2] |= 1; /* Line 1120, Address: 0x101bd40 */
  pPlayerwk->cddat |= 4; /* Line 1121, Address: 0x101bd50 */
  pPlayerwk->sprvsize = 14; /* Line 1122, Address: 0x101bd60 */
  pPlayerwk->sprhs = 7; /* Line 1123, Address: 0x101bd6c */
  pPlayerwk->mstno.b.h = 2; /* Line 1124, Address: 0x101bd78 */


  prio_sav = (pPlayerwk->sproffset & 32768) >> 8; /* Line 1127, Address: 0x101bd84 */
  pPlayerwk->sproffset &= 32767; /* Line 1128, Address: 0x101bda4 */

  *(int*)&pActwk->actfree[4] = pPlayerwk - actwk; /* Line 1130, Address: 0x101bdb4 */
  pActwk->actfree[8] = 60; /* Line 1131, Address: 0x101bde8 */
  pActwk->r_no0 += 2; /* Line 1132, Address: 0x101bdf4 */

  pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1134, Address: 0x101be04 */
  cntwk = pposiset(pActwk, pMstwk, pPlayerwk, ppositbl0); /* Line 1135, Address: 0x101be28 */

  plspdset(pActwk, pPlayerwk, cntwk); /* Line 1137, Address: 0x101be4c */
} /* Line 1138, Address: 0x101be60 */






static short pposiset(sprite_status* pActwk, sprite_status* pMstwk, sprite_status* pPlayerwk, char* pPostbl) { /* Line 1145, Address: 0x101be80 */
  short poswk, cntsv;

  cntsv = pMstwk->patcnt; /* Line 1148, Address: 0x101be9c */
  poswk = pPostbl[cntsv]; /* Line 1149, Address: 0x101beb0 */
  poswk *= 2; /* Line 1150, Address: 0x101bed4 */

  pPlayerwk->xposi.w.h = pActwk->xposi.w.h + ppositbl[poswk]; /* Line 1152, Address: 0x101bee0 */
  pPlayerwk->yposi.w.h = pActwk->yposi.w.h + ppositbl[poswk + 1]; /* Line 1153, Address: 0x101bf28 */

  return cntsv; /* Line 1155, Address: 0x101bf74 */
} /* Line 1156, Address: 0x101bf78 */






static void plspdset(sprite_status* pActwk, sprite_status* pPlayerwk, short patcnt) { /* Line 1163, Address: 0x101bf90 */
  int_union sinwk, coswk;

  if (!(patcnt & 1)) { /* Line 1166, Address: 0x101bfa4 */

    sinset(224, &sinwk.w.l, &coswk.w.l); /* Line 1168, Address: 0x101bfbc */
    sinwk.l <<= 12; /* Line 1169, Address: 0x101bfd0 */
    coswk.l <<= 12; /* Line 1170, Address: 0x101bfdc */
    sinwk.l = (unsigned int)sinwk.l >> 8; /* Line 1171, Address: 0x101bfe8 */
    coswk.l = (unsigned int)coswk.l >> 8; /* Line 1172, Address: 0x101bff4 */
    pPlayerwk->yspeed.w = sinwk.w.l; /* Line 1173, Address: 0x101c000 */
    pPlayerwk->xspeed.w = coswk.w.l; /* Line 1174, Address: 0x101c00c */

    if (pActwk->actflg & 2) { /* Line 1176, Address: 0x101c018 */
      pPlayerwk->yspeed.w *= -1; /* Line 1177, Address: 0x101c030 */
    }


    pPlayerwk->cddat &= 254; /* Line 1181, Address: 0x101c040 */

    if (pActwk->actflg & 1) { /* Line 1183, Address: 0x101c050 */
      pPlayerwk->cddat |= 1; /* Line 1184, Address: 0x101c068 */
      pPlayerwk->xspeed.w *= -1; /* Line 1185, Address: 0x101c078 */
    }
  } /* Line 1187, Address: 0x101c088 */
  else {
    if (!(patcnt & 2)) { /* Line 1189, Address: 0x101c090 */

      pPlayerwk->yspeed.w = 0; /* Line 1191, Address: 0x101c0a8 */
      pPlayerwk->xspeed.w = 4096; /* Line 1192, Address: 0x101c0b0 */

      if (pActwk->actflg & 1) { /* Line 1194, Address: 0x101c0bc */
        pPlayerwk->xspeed.w *= -1; /* Line 1195, Address: 0x101c0d4 */
      }
    } /* Line 1197, Address: 0x101c0e4 */
    else {
      pPlayerwk->xspeed.w = 0; /* Line 1199, Address: 0x101c0ec */
      pPlayerwk->yspeed.w = -4096; /* Line 1200, Address: 0x101c0f4 */

      if (pActwk->actflg & 2) { /* Line 1202, Address: 0x101c100 */
        pPlayerwk->yspeed.w *= -1; /* Line 1203, Address: 0x101c118 */
      }
    }
  }


  pPlayerwk->cddat |= 2; /* Line 1209, Address: 0x101c128 */
  pPlayerwk->cddat &= 247; /* Line 1210, Address: 0x101c138 */
} /* Line 1211, Address: 0x101c148 */






static void g_move0(sprite_status* pActwk, unsigned char* pPatTbl, unsigned char* pRevTbl, unsigned char* pGposiTbl, unsigned char* pPposiTbl) { /* Line 1218, Address: 0x101c160 */
  sprite_status *pMstwk, *pMstwk2, *pPlayerwk;
  unsigned char cntwk;

  pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1222, Address: 0x101c18c */
  cntwk = pMstwk->patcnt; /* Line 1223, Address: 0x101c1b0 */

  pActwk->patno = pPatTbl[cntwk]; /* Line 1225, Address: 0x101c1b8 */
  pActwk->actflg &= 252; /* Line 1226, Address: 0x101c1d0 */
  pActwk->actflg |= pRevTbl[cntwk]; /* Line 1227, Address: 0x101c1e0 */
  cntwk = pGposiTbl[cntwk]; /* Line 1228, Address: 0x101c200 */
  cntwk *= 2; /* Line 1229, Address: 0x101c214 */
  pActwk->xposi.w.h = pMstwk->xposi.w.h + gpositbl[cntwk]; /* Line 1230, Address: 0x101c224 */
  pActwk->yposi.w.h = pMstwk->yposi.w.h + gpositbl[cntwk + 1]; /* Line 1231, Address: 0x101c264 */


  if (pActwk->userflag.b.h) { /* Line 1234, Address: 0x101c2a8 */





    pMstwk2 = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1240, Address: 0x101c2b8 */
    pMstwk2 = &actwk[*(int*)&pMstwk2->actfree[0]]; /* Line 1241, Address: 0x101c2dc */

    if (pMstwk2->userflag.b.l) { /* Line 1243, Address: 0x101c2fc */
      if (pMstwk2->userflag.b.l == 2 && !pActwk->userflag.b.l) { /* Line 1244, Address: 0x101c308 */
        pPlayerwk = &actwk[*(int*)&pMstwk2->actfree[4]]; /* Line 1245, Address: 0x101c330 */
        pposiset(pMstwk2, pMstwk, pPlayerwk, (char*)pPposiTbl); /* Line 1246, Address: 0x101c350 */
      }
    } /* Line 1248, Address: 0x101c368 */
    else {
      if (!editmode.b.h) { /* Line 1250, Address: 0x101c370 */
        if (coli0(pActwk, &actwk[0], 24, 24) != 0) { /* Line 1251, Address: 0x101c380 */
          playset_g(pActwk, pMstwk, &actwk[0], pPposiTbl); /* Line 1252, Address: 0x101c3a4 */
        } else { /* Line 1253, Address: 0x101c3c0 */
          pActwk->userflag.b.l = 0; /* Line 1254, Address: 0x101c3c8 */
        }
      }
    }
  }

} /* Line 1260, Address: 0x101c3d0 */













static void playset_g(sprite_status* pActwk, sprite_status* pMstadr, sprite_status* pPlayerwk, unsigned char* pPposiTbl) { /* Line 1274, Address: 0x101c3f0 */
  sprite_status *pMstwk, *pGawaadr, *pMstsv;

  pPlayerwk->actfree[18] = 0; /* Line 1277, Address: 0x101c414 */
  pPlayerwk->actfree[2] |= 1; /* Line 1278, Address: 0x101c41c */
  pPlayerwk->cddat |= 4; /* Line 1279, Address: 0x101c42c */
  pPlayerwk->sprvsize = 14; /* Line 1280, Address: 0x101c43c */
  pPlayerwk->sprhs = 7; /* Line 1281, Address: 0x101c448 */
  pPlayerwk->mstno.b.h = 2; /* Line 1282, Address: 0x101c454 */

  pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1284, Address: 0x101c460 */
  pMstwk = &actwk[*(int*)&pMstwk->actfree[0]]; /* Line 1285, Address: 0x101c484 */
  pMstwk->r_no0 += 2; /* Line 1286, Address: 0x101c4a4 */
  pMstwk->userflag.b.l = 1; /* Line 1287, Address: 0x101c4b0 */
  *(int*)&pMstwk->actfree[4] = pPlayerwk - actwk; /* Line 1288, Address: 0x101c4b8 */
  pposiset(pMstwk, pMstadr, pPlayerwk, (char*)pPposiTbl); /* Line 1289, Address: 0x101c4e8 */

  pMstwk = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1291, Address: 0x101c500 */

  if (pActwk->r_no0 == 10) { /* Line 1293, Address: 0x101c524 */
    pGawaadr = &actwk[*(int*)&pMstwk->actfree[16]]; /* Line 1294, Address: 0x101c53c */
  } else { /* Line 1295, Address: 0x101c55c */
    pGawaadr = &actwk[*(int*)&pMstwk->actfree[12]]; /* Line 1296, Address: 0x101c564 */
  }

  pGawaadr->r_no1 = pGawaadr->r_no0; /* Line 1299, Address: 0x101c584 */
  pMstsv = pMstadr; /* Line 1300, Address: 0x101c58c */
  pMstadr = &actwk[*(int*)&pActwk->actfree[0]]; /* Line 1301, Address: 0x101c590 */
  pMstadr = &actwk[*(int*)&pMstadr->actfree[0]]; /* Line 1302, Address: 0x101c5b8 */

  if (pGawaadr->r_no0 == 10) { /* Line 1304, Address: 0x101c5e0 */
    pMstadr->userflag.b.h = 2; /* Line 1305, Address: 0x101c5f4 */
    spr_r_move4(pGawaadr); /* Line 1306, Address: 0x101c600 */
  } /* Line 1307, Address: 0x101c60c */
  else {
    pMstadr->userflag.b.h = 1; /* Line 1309, Address: 0x101c614 */
    spr_r_move5(pGawaadr); /* Line 1310, Address: 0x101c620 */
  }


  pGawaadr->r_no0 = 14; /* Line 1314, Address: 0x101c62c */
  pGawaadr->userflag.b.l = 1; /* Line 1315, Address: 0x101c634 */
  gspdset(pMstsv, pGawaadr); /* Line 1316, Address: 0x101c63c */
} /* Line 1317, Address: 0x101c64c */






static void gspdset(sprite_status* pMstadr, sprite_status* pGawaadr) { /* Line 1324, Address: 0x101c670 */
  short* pGspdTbl;
  unsigned char r_nowk, cntwk;

  pGspdTbl = gspdtbl0; /* Line 1328, Address: 0x101c688 */
  r_nowk = pGawaadr->r_no1; /* Line 1329, Address: 0x101c690 */

  if ((r_nowk -= 10) != 0) { /* Line 1331, Address: 0x101c69c */
    pGspdTbl = gspdtbl1; /* Line 1332, Address: 0x101c6b4 */
  }


  cntwk = pMstadr->patcnt; /* Line 1336, Address: 0x101c6bc */
  cntwk *= 2; /* Line 1337, Address: 0x101c6c8 */
  pGawaadr->xspeed.w = pGspdTbl[cntwk]; /* Line 1338, Address: 0x101c6d8 */
  pGawaadr->yspeed.w = pGspdTbl[cntwk + 1]; /* Line 1339, Address: 0x101c6f0 */
  pGawaadr->actfree[8] = 26; /* Line 1340, Address: 0x101c70c */
} /* Line 1341, Address: 0x101c718 */






static void gun7_coli(sprite_status* pActwk) { /* Line 1348, Address: 0x101c730 */
  if (!editmode.b.h) { /* Line 1349, Address: 0x101c73c */
    if (!(actwk[0].cddat & 2)) { /* Line 1350, Address: 0x101c74c */
      if (coli0(pActwk, &actwk[0], 32, 16) != 0) { /* Line 1351, Address: 0x101c764 */
        gun7set(pActwk); /* Line 1352, Address: 0x101c788 */
      }
    }
  }


} /* Line 1358, Address: 0x101c794 */





static void gun7set(sprite_status* pActwk) { /* Line 1364, Address: 0x101c7b0 */
  sprite_status *pNewact, *pGunact;

  actwk[0].actfree[2] = 0; /* Line 1367, Address: 0x101c7c0 */
  pNewact = pGunact = 0; /* Line 1368, Address: 0x101c7c8 */

  if (actwkchk(&pNewact) == 0) { /* Line 1370, Address: 0x101c7d0 */
    pNewact->actno = 8; /* Line 1371, Address: 0x101c7e4 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 1372, Address: 0x101c7f0 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 1373, Address: 0x101c800 */
    pNewact->userflag.b.h = 1; /* Line 1374, Address: 0x101c810 */
    pGunact = pNewact; /* Line 1375, Address: 0x101c81c */

    if (actwkchk(&pNewact) == 0) { /* Line 1377, Address: 0x101c820 */
      pNewact->actno = 9; /* Line 1378, Address: 0x101c834 */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 1379, Address: 0x101c840 */
      pNewact->yposi.w.h = pActwk->yposi.w.h - 6; /* Line 1380, Address: 0x101c850 */
    }
  }


  soundset(206); /* Line 1385, Address: 0x101c874 */

  pActwk->r_no0 += 2; /* Line 1387, Address: 0x101c880 */
  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 1388, Address: 0x101c890 */
  pActwk->actfree[0] = 6; /* Line 1389, Address: 0x101c8a0 */

  if (pActwk->xposi.w.h < actwk[0].xposi.w.h) { /* Line 1391, Address: 0x101c8ac */

    if (pGunact != 0) { /* Line 1393, Address: 0x101c8d8 */
      pGunact->xspeed.w = 512; /* Line 1394, Address: 0x101c8e0 */
    }

    if (pNewact != 0) { /* Line 1397, Address: 0x101c8e8 */
      pNewact->cddat |= 1; /* Line 1398, Address: 0x101c8f4 */
      pNewact->xposi.w.h += 16; /* Line 1399, Address: 0x101c904 */
    }
    actwk[0].xspeed.w = -4096; /* Line 1401, Address: 0x101c914 */
    actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1402, Address: 0x101c920 */
    actwk[0].cddat |= 1; /* Line 1403, Address: 0x101c930 */

    pActwk->xspeed.w = 2048; /* Line 1405, Address: 0x101c944 */
  } /* Line 1406, Address: 0x101c950 */
  else {
    if (pGunact != 0) { /* Line 1408, Address: 0x101c958 */
      pGunact->xspeed.w = -512; /* Line 1409, Address: 0x101c960 */
    }

    if (pNewact != 0) { /* Line 1412, Address: 0x101c968 */
      pNewact->cddat &= 254; /* Line 1413, Address: 0x101c974 */
      pNewact->xposi.w.h -= 16; /* Line 1414, Address: 0x101c984 */
    }

    actwk[0].xspeed.w = 4096; /* Line 1417, Address: 0x101c994 */
    actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1418, Address: 0x101c9a0 */
    actwk[0].cddat &= 254; /* Line 1419, Address: 0x101c9b0 */

    pActwk->xspeed.w = -2048; /* Line 1421, Address: 0x101c9c4 */
  }
} /* Line 1423, Address: 0x101c9d0 */
