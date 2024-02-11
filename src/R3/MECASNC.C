#include "..\EQU.H"
#include "MECASNC.H"

static unsigned char bCarry;
void(*msnc_tbl[6])(sprite_status*) = {
  &mecasnc3_init,
  &mecasnc3_matu1,
  &mecasnc3_come,
  &mecasnc3_hovr,
  &mecasnc3_upmv,
  &mecasnc3_rght
};
static unsigned char jmp_flg;
extern sprite_pattern* mecasnc3pat[];
unsigned char vatck_pchg[5] = { 0, 0, 1, 0, 255 };
unsigned char elec_pchg[9] = { 6, 1, 7, 1, 8, 1, 9, 1, 255 };
unsigned char hover_pchg[3] = { 14, 1, 255 };
unsigned char* msc_pchg[3] = {
  vatck_pchg,
  elec_pchg,
  hover_pchg
};
extern palette_entry zone3colora[];
void(*emie3_tbl[3])(sprite_status*) = {
  &emie3_init,
  &emie3_walk,
  &emie3_help
};
extern unsigned char* em_pchg[];
extern sprite_pattern* emie3pat[];
static palette_entry emie3_clr[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 128,  32,  96, 1 }, { 160,  64, 128, 1 },
  { 224,  96, 224, 1 }, { 224, 160, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 192,  96,   0, 1 },
  {  32, 192,   0, 1 }, {   0, 128,   0, 1 }, {  96,   0, 128, 1 }, { 224,   0,   0, 1 }
};
void(*hari_tbl[3])(sprite_status*) = {
  &hari3x_init,
  &hari3x_move,
  &hari3x_brkn
};
extern sprite_pattern* hari3xpat[];
short spd_tbl[8] = { 512, -512, -256, -1024, -256, -512, 512, -1024 };
void(*heart_tbl[2])(sprite_status*) = {
  &heart3_init,
  &heart3_move
};
void(*msfire_tbl[2])(sprite_status*) = {
  &msnc3fire_init,
  &msnc3fire_move
};
unsigned char fire_pchg0[6] = { 1, 12, 15, 13, 15, 255 };
unsigned char* fire_pchg[1] = { fire_pchg0 };



























































































unsigned char CSset_b(unsigned char bySrc, unsigned char byDst) { /* Line 145, Address: 0x10256a0 */
  unsigned short wk, wSrc, wDst;

  wSrc = bySrc; /* Line 148, Address: 0x10256b8 */
  wDst = byDst; /* Line 149, Address: 0x10256c4 */
  wk = wSrc + wDst; /* Line 150, Address: 0x10256d0 */
  if (wk >= 255) return 1; /* Line 151, Address: 0x10256e4 */
  return 0; /* Line 152, Address: 0x1025700 */
} /* Line 153, Address: 0x1025704 */






















void mecasnc3(sprite_status* pActwk) { /* Line 176, Address: 0x1025720 */
  sprite_status* pPlaywk;

  jmp_flg = 0; /* Line 179, Address: 0x1025730 */
  msnc_tbl[pActwk->r_no0 / 2](pActwk); /* Line 180, Address: 0x1025738 */










  pPlaywk = &actwk[0]; /* Line 191, Address: 0x102577c */
  if (pPlaywk->xposi.w.h >= 1216) /* Line 192, Address: 0x1025784 */
    mecasnc3_fout(pActwk); /* Line 193, Address: 0x102579c */
  else
    actionsub(pActwk); /* Line 195, Address: 0x10257b0 */
} /* Line 196, Address: 0x10257bc */











void mecasnc3_init(sprite_status* pActwk) { /* Line 208, Address: 0x10257d0 */
  pActwk->r_no0 += 2; /* Line 209, Address: 0x10257dc */
  pActwk->actflg |= 4; /* Line 210, Address: 0x10257ec */
  pActwk->sproffset = 976; /* Line 211, Address: 0x10257fc */
  pActwk->sprpri = 2; /* Line 212, Address: 0x1025808 */
  pActwk->patbase = mecasnc3pat; /* Line 213, Address: 0x1025814 */
  pActwk->patno = 14; /* Line 214, Address: 0x1025824 */
  pActwk->sprvsize = 32; /* Line 215, Address: 0x1025830 */
  pActwk->actfree[16] = 60; /* Line 216, Address: 0x102583c */
  pActwk->colino = 0; /* Line 217, Address: 0x1025848 */
  mecasnc3_matu1(pActwk); /* Line 218, Address: 0x1025850 */
} /* Line 219, Address: 0x102585c */











void mecasnc3_matu1(sprite_status* pActwk) { /* Line 231, Address: 0x1025870 */
  if (pActwk->actfree[16] != 0) { /* Line 232, Address: 0x102587c */

    --pActwk->actfree[16]; /* Line 234, Address: 0x1025890 */
    return; /* Line 235, Address: 0x10258a0 */
  }

  dir_left(pActwk); /* Line 238, Address: 0x10258a8 */
  ((short*)pActwk)[33] = -16; /* Line 239, Address: 0x10258b4 */
  pActwk->r_no0 += 2; /* Line 240, Address: 0x10258c0 */

  if (pActwk->actflg & 128) /* Line 242, Address: 0x10258d0 */
    soundset(202); /* Line 243, Address: 0x10258e8 */
} /* Line 244, Address: 0x10258f4 */











void mecasnc3_come(sprite_status* pActwk) { /* Line 256, Address: 0x1025910 */
  short iD0, iD1;

  emie_speedsetx(pActwk); /* Line 259, Address: 0x1025924 */
  iD0 = ((short*)pActwk)[33]; /* Line 260, Address: 0x1025930 */
  iD0 += pActwk->xspeed.w; /* Line 261, Address: 0x1025940 */
  if (iD0 < -767) /* Line 262, Address: 0x1025954 */
    iD0 = -768; /* Line 263, Address: 0x1025968 */

  pActwk->xspeed.w = iD0; /* Line 265, Address: 0x1025974 */

  iD0 = 992; /* Line 267, Address: 0x102597c */
  iD1 = ((unsigned short*)pActwk)[28]; /* Line 268, Address: 0x1025988 */
  if (iD1 != 0) /* Line 269, Address: 0x1025998 */
    iD0 = actwk[iD1].xposi.w.h + 32; /* Line 270, Address: 0x10259a8 */

  if (iD0 >= pActwk->xposi.w.h) { /* Line 272, Address: 0x10259e8 */

    pActwk->xspeed.w = 0; /* Line 274, Address: 0x1025a0c */
    ((short*)pActwk)[33] = 0; /* Line 275, Address: 0x1025a14 */
    pActwk->actfree[19] = 255; /* Line 276, Address: 0x1025a1c */
    pActwk->mstno.b.h = 2; /* Line 277, Address: 0x1025a28 */
    setfire(pActwk); /* Line 278, Address: 0x1025a34 */
    pActwk->colino = 0; /* Line 279, Address: 0x1025a40 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 280, Address: 0x1025a48 */
    pActwk->r_no0 += 2; /* Line 281, Address: 0x1025a58 */
  }

  empatchg(pActwk, msc_pchg); /* Line 284, Address: 0x1025a68 */
} /* Line 285, Address: 0x1025a7c */











void mecasnc3_hovr(sprite_status* pActwk) { /* Line 297, Address: 0x1025aa0 */
  sprite_status* pPlaywk;
  char wWk;

  pPlaywk = &actwk[0]; /* Line 301, Address: 0x1025ab4 */
  setdirect(pActwk, pPlaywk); /* Line 302, Address: 0x1025abc */
  yposisetsub(pActwk); /* Line 303, Address: 0x1025acc */


  pActwk->actfree[16] += 4; /* Line 306, Address: 0x1025ad8 */
  wWk = ((char*)pActwk)[62]; /* Line 307, Address: 0x1025ae8 */
  if (wWk < 0) { /* Line 308, Address: 0x1025af8 */

    pActwk->r_no0 += 2; /* Line 310, Address: 0x1025b08 */
    pActwk->yspeed.w = -704; /* Line 311, Address: 0x1025b18 */
    ((short*)pActwk)[33] = 11; /* Line 312, Address: 0x1025b24 */
    pActwk->actfree[17] = 64; /* Line 313, Address: 0x1025b30 */
    pActwk->actfree[6] = 80; /* Line 314, Address: 0x1025b3c */
  }

  empatchg(pActwk, msc_pchg); /* Line 317, Address: 0x1025b48 */
} /* Line 318, Address: 0x1025b5c */











void yposisetsub(sprite_status* pActwk) { /* Line 330, Address: 0x1025b80 */
  unsigned char byR = pActwk->actfree[16]; /* Line 331, Address: 0x1025b90 */
  short iSin, iCos;
  int_union lD0;

  sinset(byR, &iSin, &iCos); /* Line 335, Address: 0x1025b9c */
  lD0.l = iSin << 2; /* Line 336, Address: 0x1025bb0 */
  if (-2147483648 & lD0.l) lD0.l <<= 8, lD0.l |= -2147483648; else lD0.l <<= 8; /* Line 337, Address: 0x1025bc4 */

  lD0.w.h += ((short*)pActwk)[27]; /* Line 339, Address: 0x1025c08 */
  pActwk->yposi.l = lD0.l; /* Line 340, Address: 0x1025c1c */
} /* Line 341, Address: 0x1025c28 */











void mecasnc3_upmv(sprite_status* pActwk) { /* Line 353, Address: 0x1025c40 */
  sprite_status* pPlaywk;
  short_union iD0;

  pPlaywk = &actwk[0]; /* Line 357, Address: 0x1025c50 */
  setdirect(pActwk, pPlaywk); /* Line 358, Address: 0x1025c58 */
  if (pActwk->actfree[17] != 0) { /* Line 359, Address: 0x1025c68 */

    emie_speedset(pActwk); /* Line 361, Address: 0x1025c7c */
    pActwk->yspeed.w += ((short*)pActwk)[33]; /* Line 362, Address: 0x1025c88 */

    if (--pActwk->actfree[17] == 0) { /* Line 364, Address: 0x1025ca0 */

      ((short*)pActwk)[33] = 0; /* Line 366, Address: 0x1025cc0 */
      pActwk->yspeed.w = 0; /* Line 367, Address: 0x1025cc8 */
      ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 368, Address: 0x1025cd0 */
    } /* Line 369, Address: 0x1025ce0 */
    else {

      empatchg(pActwk, msc_pchg); /* Line 372, Address: 0x1025ce8 */
      return; /* Line 373, Address: 0x1025cfc */
    }
  }

  yposisetsub(pActwk); /* Line 377, Address: 0x1025d04 */
  pActwk->actfree[16] += 4; /* Line 378, Address: 0x1025d10 */

  iD0.w = pActwk->xposi.w.h; /* Line 380, Address: 0x1025d20 */
  bCarry = CCset(iD0.w, pPlaywk->xposi.w.h); /* Line 381, Address: 0x1025d2c */
  iD0.w -= pPlaywk->xposi.w.h; /* Line 382, Address: 0x1025d54 */
  if (bCarry == 0) { /* Line 383, Address: 0x1025d64 */

    if ((unsigned char)iD0.b.l >= 160) { /* Line 385, Address: 0x1025d78 */

      empatchg(pActwk, msc_pchg); /* Line 387, Address: 0x1025d90 */
      return; /* Line 388, Address: 0x1025da4 */
    }
  }

  if (--pActwk->actfree[6] == 0) { /* Line 392, Address: 0x1025dac */

    dir_right(pActwk); /* Line 394, Address: 0x1025dcc */
    pActwk->xspeed.w = 0; /* Line 395, Address: 0x1025dd8 */
    ((short*)pActwk)[33] = 96; /* Line 396, Address: 0x1025de0 */
    pActwk->r_no0 += 2; /* Line 397, Address: 0x1025dec */
  }

  empatchg(pActwk, msc_pchg); /* Line 400, Address: 0x1025dfc */
} /* Line 401, Address: 0x1025e10 */











void setfire(sprite_status* pActwk) { /* Line 413, Address: 0x1025e30 */
  sprite_status* pActfree;

  if (actwkchk(&pActfree) == 0) { /* Line 416, Address: 0x1025e3c */

    pActfree->actno = 52; /* Line 418, Address: 0x1025e50 */
    ((unsigned short*)pActfree)[28] = pActwk - actwk; /* Line 419, Address: 0x1025e5c */
  }

} /* Line 422, Address: 0x1025e90 */











void mecasnc3_rght(sprite_status* pActwk) { /* Line 434, Address: 0x1025ea0 */
  short iD0;

  emie_speedsetx(pActwk); /* Line 437, Address: 0x1025eb0 */
  iD0 = ((short*)pActwk)[33]; /* Line 438, Address: 0x1025ebc */
  iD0 += pActwk->xspeed.w; /* Line 439, Address: 0x1025ecc */
  if (iD0 >= 1024) /* Line 440, Address: 0x1025ee0 */
    iD0 = 1024; /* Line 441, Address: 0x1025ef4 */

  pActwk->xspeed.w = iD0; /* Line 443, Address: 0x1025f00 */
  if (pActwk->xposi.w.h < 1320) /* Line 444, Address: 0x1025f08 */
    empatchg(pActwk, msc_pchg); /* Line 445, Address: 0x1025f24 */
  else

    mecasnc3_fout(pActwk); /* Line 448, Address: 0x1025f40 */
} /* Line 449, Address: 0x1025f4c */











void mecasnc3_fout(sprite_status* pActwk) { /* Line 461, Address: 0x1025f60 */

  emie3end = 255; /* Line 463, Address: 0x1025f6c */
  emie3clrsetx(zone3colora); /* Line 464, Address: 0x1025f78 */
  frameout(pActwk); /* Line 465, Address: 0x1025f88 */
  jmp_flg = 1; /* Line 466, Address: 0x1025f94 */
} /* Line 467, Address: 0x1025fa0 */



















void emie_speedset(sprite_status* pActwk) { /* Line 487, Address: 0x1025fb0 */
  emie_speedsetx(pActwk); /* Line 488, Address: 0x1025fbc */
  emie_speedsety(pActwk); /* Line 489, Address: 0x1025fc8 */
} /* Line 490, Address: 0x1025fd4 */

void emie_speedsety(sprite_status* pActwk) { /* Line 492, Address: 0x1025ff0 */
  int_union lD0;

  lD0.l = pActwk->yspeed.w; /* Line 495, Address: 0x1025ff8 */
  if (lD0.l & -2147483648) lD0.l <<= 8, lD0.l |= -2147483648; else lD0.l <<= 8; /* Line 496, Address: 0x102600c */
  pActwk->yposi.l += lD0.l; /* Line 497, Address: 0x1026050 */
} /* Line 498, Address: 0x1026064 */

void emie_speedsetx(sprite_status* pActwk) { /* Line 500, Address: 0x1026070 */
  int_union lD0;

  lD0.l = pActwk->xspeed.w; /* Line 503, Address: 0x1026078 */
  if (lD0.l & -2147483648) lD0.l <<= 8, lD0.l |= -2147483648; else lD0.l <<= 8; /* Line 504, Address: 0x102608c */
  pActwk->xposi.l += lD0.l; /* Line 505, Address: 0x10260d0 */
} /* Line 506, Address: 0x10260e4 */
































void emie3(sprite_status* pActwk) { /* Line 539, Address: 0x10260f0 */
  sprite_status* pPlaywk;

  jmp_flg = 0; /* Line 542, Address: 0x1026100 */
  if (ta_flag == 0 && emie3end == 0) { /* Line 543, Address: 0x1026108 */


    emie3_tbl[pActwk->r_no0 / 2](pActwk); /* Line 546, Address: 0x1026130 */
    pPlaywk = &actwk[0]; /* Line 547, Address: 0x1026174 */
    if (pPlaywk->xposi.w.h >= 1216) /* Line 548, Address: 0x102617c */
      mecasnc3_fout(pActwk); /* Line 549, Address: 0x1026194 */
    else
      actionsub(pActwk); /* Line 551, Address: 0x10261a8 */
  } /* Line 552, Address: 0x10261b4 */
  else {

    mecasnc3_fout(pActwk); /* Line 555, Address: 0x10261bc */
  }
  jmp_flg = 0; /* Line 557, Address: 0x10261c8 */
} /* Line 558, Address: 0x10261d0 */











void emie3_init(sprite_status* pActwk) { /* Line 570, Address: 0x10261f0 */
  sprite_status* pPlaywk;

  if (pActwk->actfree[20] == 0) { /* Line 573, Address: 0x1026200 */


    pActwk->actfree[20] = 255; /* Line 576, Address: 0x1026214 */
  }

  pActwk->actflg |= 4; /* Line 579, Address: 0x1026220 */
  pActwk->sproffset = 9054; /* Line 580, Address: 0x1026230 */
  pActwk->sprpri = 1; /* Line 581, Address: 0x102623c */
  pActwk->patbase = emie3pat; /* Line 582, Address: 0x1026248 */
  emie3clrset(); /* Line 583, Address: 0x1026258 */
  pPlaywk = &actwk[0]; /* Line 584, Address: 0x1026260 */
  setdirect(pActwk, pPlaywk); /* Line 585, Address: 0x1026268 */
  if (pPlaywk->xposi.w.h >= pActwk->xposi.w.h) /* Line 586, Address: 0x1026278 */
    pActwk->r_no0 += 2; /* Line 587, Address: 0x10262a0 */

  empatchg(pActwk, em_pchg); /* Line 589, Address: 0x10262b0 */

} /* Line 591, Address: 0x10262c4 */


void emiewalkret(sprite_status* pActwk) { /* Line 594, Address: 0x10262e0 */
  empatchg(pActwk, em_pchg); /* Line 595, Address: 0x10262ec */
  heartset(pActwk); /* Line 596, Address: 0x1026300 */
} /* Line 597, Address: 0x102630c */










void emie3_walk(sprite_status* pActwk) { /* Line 608, Address: 0x1026320 */
  short iD0, iD1, iD2;
  sprite_status *pPlaywk, *pRideAct;

  pPlaywk = &actwk[0]; /* Line 612, Address: 0x102633c */
  iD0 = ((short*)pActwk)[28]; /* Line 613, Address: 0x1026348 */
  if (iD0 != 0) { /* Line 614, Address: 0x1026358 */

    pRideAct = &actwk[iD0]; /* Line 616, Address: 0x1026368 */
    if (pRideAct->actfree[19] != 0) { /* Line 617, Address: 0x1026388 */

      pActwk->r_no0 = 4; /* Line 619, Address: 0x1026398 */
      sub_sync(125); /* Line 620, Address: 0x10263a4 */
      emiewalkret(pActwk); /* Line 621, Address: 0x10263b0 */
      return; /* Line 622, Address: 0x10263bc */
    }
  }

  setdirect(pActwk, pPlaywk); /* Line 626, Address: 0x10263c4 */
  if (pActwk->cddat & 1) { /* Line 627, Address: 0x10263d4 */

    if (pActwk->xposi.w.h < 128) { /* Line 629, Address: 0x10263ec */

      pActwk->mstno.b.h = 0; /* Line 631, Address: 0x1026408 */
      pActwk->xspeed.w = 0; /* Line 632, Address: 0x1026410 */
      emiewalkret(pActwk); /* Line 633, Address: 0x1026418 */
      return; /* Line 634, Address: 0x1026424 */
    }
  }

  if (pActwk->xposi.w.h < 960) { /* Line 638, Address: 0x102642c */


    iD0 = -32; /* Line 641, Address: 0x1026448 */
    if (!(pActwk->cddat & 1)) /* Line 642, Address: 0x1026454 */
      iD0 = -iD0; /* Line 643, Address: 0x102646c */

    iD0 += pActwk->xspeed.w; /* Line 645, Address: 0x1026488 */
    iD1 = iD0; /* Line 646, Address: 0x102649c */
    iD2 = 512; /* Line 647, Address: 0x10264a4 */
    if (iD1 < 0) { /* Line 648, Address: 0x10264b0 */

      iD1 = -iD1; /* Line 650, Address: 0x10264c0 */
      iD2 = -iD2; /* Line 651, Address: 0x10264dc */
    }

    if (iD1 >= 512) /* Line 654, Address: 0x10264f8 */
      iD0 = iD2; /* Line 655, Address: 0x102650c */

    pActwk->xspeed.w = iD0; /* Line 657, Address: 0x1026514 */
    emie_speedsetx(pActwk); /* Line 658, Address: 0x102651c */
    pActwk->mstno.b.h = 1; /* Line 659, Address: 0x1026528 */
    if (pActwk->xposi.w.h < 960) { /* Line 660, Address: 0x1026534 */

      emiewalkret(pActwk); /* Line 662, Address: 0x1026550 */
      return; /* Line 663, Address: 0x102655c */
    }
  }

  pActwk->mstno.b.h = 0; /* Line 667, Address: 0x1026564 */

  if (((short*)pActwk)[28] == 0) { /* Line 669, Address: 0x102656c */

    if (actwkchk(&pPlaywk) == 0) { /* Line 671, Address: 0x1026584 */

      pPlaywk->actno = 49; /* Line 673, Address: 0x1026598 */
      pPlaywk->xposi.w.h = 1280; /* Line 674, Address: 0x10265a4 */
      pPlaywk->yposi.w.h = 1000; /* Line 675, Address: 0x10265b0 */

      ((unsigned short*)pPlaywk)[28] = pActwk - actwk; /* Line 677, Address: 0x10265bc */

      ((unsigned short*)pActwk)[28] = pPlaywk - actwk; /* Line 679, Address: 0x10265f0 */
    }
  }
  emiewalkret(pActwk); /* Line 682, Address: 0x1026624 */
} /* Line 683, Address: 0x1026630 */











void emie3_help(sprite_status* pActwk) { /* Line 695, Address: 0x1026650 */
  short iD0;
  sprite_status* pRideAct;

  iD0 = ((short*)pActwk)[28]; /* Line 699, Address: 0x1026664 */
  pRideAct = &actwk[iD0]; /* Line 700, Address: 0x1026674 */
  if (pRideAct->actno == 49) { /* Line 701, Address: 0x1026694 */

    iD0 = 8; /* Line 703, Address: 0x10266a8 */
    dir_left(pActwk); /* Line 704, Address: 0x10266b4 */
    if (pRideAct->cddat & 1) { /* Line 705, Address: 0x10266c0 */

      iD0 = -iD0; /* Line 707, Address: 0x10266d4 */
      dir_right(pActwk); /* Line 708, Address: 0x10266f0 */
    }

    iD0 += pRideAct->xposi.w.h; /* Line 711, Address: 0x10266fc */
    pActwk->xposi.w.h = iD0; /* Line 712, Address: 0x102670c */
    pActwk->yposi.w.h = pRideAct->yposi.w.h + 4; /* Line 713, Address: 0x1026714 */
    pActwk->mstno.b.h = 2; /* Line 714, Address: 0x1026734 */
    empatchg(pActwk, em_pchg); /* Line 715, Address: 0x1026740 */
    return; /* Line 716, Address: 0x1026754 */
  }

  frameout(pActwk); /* Line 719, Address: 0x102675c */
  jmp_flg = 1; /* Line 720, Address: 0x1026768 */
} /* Line 721, Address: 0x1026774 */











void setdirect(sprite_status* pActwk, sprite_status* pPlaywk) { /* Line 733, Address: 0x1026790 */
  dir_right(pActwk); /* Line 734, Address: 0x10267a0 */
  if (pActwk->xposi.l >= pPlaywk->xposi.l) /* Line 735, Address: 0x10267ac */
    dir_left(pActwk); /* Line 736, Address: 0x10267c8 */
} /* Line 737, Address: 0x10267d4 */











void dir_right(sprite_status* pActwk) { /* Line 749, Address: 0x10267f0 */
  pActwk->cddat &= 254; /* Line 750, Address: 0x10267f8 */
  pActwk->actflg &= 254; /* Line 751, Address: 0x1026808 */
} /* Line 752, Address: 0x1026818 */











void dir_left(sprite_status* pActwk) { /* Line 764, Address: 0x1026830 */
  pActwk->cddat |= 1; /* Line 765, Address: 0x1026838 */
  pActwk->actflg |= 1; /* Line 766, Address: 0x1026848 */
} /* Line 767, Address: 0x1026858 */












void empatchg(sprite_status* pActwk, unsigned char** bppPtbl) { /* Line 780, Address: 0x1026870 */
  unsigned char byD0;
  unsigned char byD1;
  unsigned char byPwk;
  unsigned char* bpPchg;

  byD0 = pActwk->mstno.b.h; /* Line 786, Address: 0x102688c */
  if (byD0 != pActwk->mstno.b.l) { /* Line 787, Address: 0x1026898 */

    pActwk->mstno.b.l = byD0; /* Line 789, Address: 0x10268b4 */
    pActwk->patcnt = 0; /* Line 790, Address: 0x10268c4 */
    pActwk->pattim = 0; /* Line 791, Address: 0x10268cc */
  }

  --pActwk->pattim; /* Line 794, Address: 0x10268d4 */
  if ((char)pActwk->pattim >= 0) return; /* Line 795, Address: 0x10268e4 */

  bpPchg = bppPtbl[byD0]; /* Line 797, Address: 0x1026904 */


  do {

    byD0 = pActwk->patcnt; /* Line 802, Address: 0x1026918 */
    byPwk = byD0; /* Line 803, Address: 0x1026924 */
    byD0 = bpPchg[byPwk]; /* Line 804, Address: 0x1026928 */
    if (byD0 != 255) break; /* Line 805, Address: 0x1026938 */
    pActwk->patcnt = 0; /* Line 806, Address: 0x1026948 */
  } while (1); /* Line 807, Address: 0x1026950 */


  byD1 = byD0; /* Line 810, Address: 0x1026958 */
  byD0 &= 31; /* Line 811, Address: 0x102695c */
  pActwk->patno = byD0; /* Line 812, Address: 0x1026964 */
  byD0 = pActwk->cddat; /* Line 813, Address: 0x102696c */
  byD1 >>= 5; /* Line 814, Address: 0x1026978 */
  byD1 ^= byD0; /* Line 815, Address: 0x1026980 */
  byD1 &= 3; /* Line 816, Address: 0x1026988 */
  pActwk->actflg &= 252; /* Line 817, Address: 0x1026990 */
  pActwk->actflg |= byD1; /* Line 818, Address: 0x10269a0 */
  pActwk->pattim = bpPchg[byPwk + 1]; /* Line 819, Address: 0x10269b0 */

  if (pActwk->pattim < 2) /* Line 821, Address: 0x10269c8 */
    ++pActwk->pattim; /* Line 822, Address: 0x10269e0 */

  pActwk->patcnt += 2; /* Line 824, Address: 0x10269f0 */
} /* Line 825, Address: 0x1026a00 */


















void emie3clrsetx(palette_entry* pPalet) { /* Line 844, Address: 0x1026a20 */
  palette_entry* pColorwk;
  short i;


  pColorwk = &lpcolorwk[16]; /* Line 849, Address: 0x1026a30 */

  for (i = 0; i < 16; ++i) { /* Line 851, Address: 0x1026a3c */
    *pColorwk = *pPalet; /* Line 852, Address: 0x1026a48 */
    ++pColorwk; /* Line 853, Address: 0x1026a6c */
    ++pPalet; /* Line 854, Address: 0x1026a70 */
  } /* Line 855, Address: 0x1026a7c */
} /* Line 856, Address: 0x1026a9c */

void emie3clrset() { /* Line 858, Address: 0x1026ab0 */
  emie3clrsetx(emie3_clr); /* Line 859, Address: 0x1026ab8 */
} /* Line 860, Address: 0x1026ac8 */










void heartset(sprite_status* pActwk) { /* Line 871, Address: 0x1026ae0 */
  unsigned char bywk;
  short iD1, wk;
  sprite_status* pActfree;

  bywk = pActwk->actfree[17]; /* Line 876, Address: 0x1026af8 */
  wk = bywk + 8; /* Line 877, Address: 0x1026b04 */
  pActwk->actfree[17] += 8; /* Line 878, Address: 0x1026b24 */
  if (wk < 256) return; /* Line 879, Address: 0x1026b34 */


  if (actwkchk(&pActfree) != 0) return; /* Line 882, Address: 0x1026b48 */
  pActfree->actno = 51; /* Line 883, Address: 0x1026b5c */
  if (!(pActwk->cddat & 1)) /* Line 884, Address: 0x1026b68 */
    iD1 = 12; /* Line 885, Address: 0x1026b80 */
  else
    iD1 = -14; /* Line 887, Address: 0x1026b94 */
  pActfree->xposi.w.h = pActwk->xposi.w.h + iD1; /* Line 888, Address: 0x1026ba0 */
  pActfree->yposi.w.h = pActwk->yposi.w.h - 12; /* Line 889, Address: 0x1026bcc */
} /* Line 890, Address: 0x1026bf0 */












void hari3x_fout(sprite_status* pActwk) { /* Line 903, Address: 0x1026c10 */
  frameout(pActwk); /* Line 904, Address: 0x1026c1c */
  jmp_flg = 1; /* Line 905, Address: 0x1026c28 */
} /* Line 906, Address: 0x1026c34 */
















void hari3x(sprite_status* pActwk) { /* Line 923, Address: 0x1026c50 */
  jmp_flg = 0; /* Line 924, Address: 0x1026c5c */
  if (ta_flag == 0) { /* Line 925, Address: 0x1026c64 */

    hari_tbl[pActwk->r_no0 / 2](pActwk); /* Line 927, Address: 0x1026c78 */
    if (jmp_flg == 0) /* Line 928, Address: 0x1026cbc */
      actionsub(pActwk); /* Line 929, Address: 0x1026cd0 */
  } /* Line 930, Address: 0x1026cdc */
  else
    hari3x_fout(pActwk); /* Line 932, Address: 0x1026ce4 */
  jmp_flg = 0; /* Line 933, Address: 0x1026cf0 */
} /* Line 934, Address: 0x1026cf8 */











void hari3x_ridechk(sprite_status* pActwk) { /* Line 946, Address: 0x1026d10 */
  sprite_status* pPlaywk;
  int lD0, lD3;

  if (pActwk->userflag.b.h != 1) { /* Line 950, Address: 0x1026d28 */

    hitchk(pActwk, &actwk[0]); /* Line 952, Address: 0x1026d44 */
    return; /* Line 953, Address: 0x1026d58 */
  }

  if (hitchk(pActwk, &actwk[0]) == 0) return; /* Line 956, Address: 0x1026d60 */

  if (!(pActwk->cddat & 8)) return; /* Line 958, Address: 0x1026d84 */


  if (plpower_a == 0) /* Line 961, Address: 0x1026d9c */
    if (plpower_m != 0) return; /* Line 962, Address: 0x1026db0 */

  pPlaywk = &actwk[0]; /* Line 964, Address: 0x1026dc4 */
  if (pPlaywk->r_no0 < 4) { /* Line 965, Address: 0x1026dcc */

    if (((unsigned short*)pPlaywk)[26] == 0) { /* Line 967, Address: 0x1026de0 */

      lD3 = pPlaywk->yposi.l; /* Line 969, Address: 0x1026df0 */
      lD0 = pPlaywk->yspeed.w; /* Line 970, Address: 0x1026df4 */
      if (-2147483648 & lD0) lD0 <<= 8, lD0 |= -2147483648; else lD0 <<= 8; /* Line 971, Address: 0x1026e00 */
      lD3 -= lD0; /* Line 972, Address: 0x1026e28 */
      pPlaywk->yposi.l = lD3; /* Line 973, Address: 0x1026e2c */
      playdamageset(pPlaywk, pActwk); /* Line 974, Address: 0x1026e30 */
    }
  }
} /* Line 977, Address: 0x1026e40 */











void hari3x_init(sprite_status* pActwk) { /* Line 989, Address: 0x1026e60 */
  if (emie3end != 0) { /* Line 990, Address: 0x1026e6c */

    hari3x_fout(pActwk); /* Line 992, Address: 0x1026e80 */
    return; /* Line 993, Address: 0x1026e8c */
  }
  pActwk->r_no0 += 2; /* Line 995, Address: 0x1026e94 */
  pActwk->actflg |= 4; /* Line 996, Address: 0x1026ea4 */
  pActwk->sproffset = 798; /* Line 997, Address: 0x1026eb4 */
  pActwk->sprpri = 3; /* Line 998, Address: 0x1026ec0 */
  pActwk->patbase = hari3xpat; /* Line 999, Address: 0x1026ecc */
  pActwk->sprhsize = 18; /* Line 1000, Address: 0x1026edc */
  pActwk->sprvsize = 8; /* Line 1001, Address: 0x1026ee8 */

  if (pActwk->userflag.b.h != 1) { /* Line 1003, Address: 0x1026ef4 */

    pActwk->sprvsize = 32; /* Line 1005, Address: 0x1026f10 */
    if (pActwk->userflag.b.h != 0) { /* Line 1006, Address: 0x1026f1c */

      if (pActwk->userflag.b.h != 2) /* Line 1008, Address: 0x1026f34 */
        pActwk->patno = 14; /* Line 1009, Address: 0x1026f50 */
      else
        pActwk->patno = 9; /* Line 1011, Address: 0x1026f64 */
      pActwk->colino = 134; /* Line 1012, Address: 0x1026f70 */
      pActwk->sprhsize = 12; /* Line 1013, Address: 0x1026f7c */
    }
  }

  if (pActwk->actfree[18] == 0) { /* Line 1017, Address: 0x1026f88 */

    hari3x_move(pActwk); /* Line 1019, Address: 0x1026f9c */
    return; /* Line 1020, Address: 0x1026fa8 */
  }
  pActwk->colino = 0; /* Line 1022, Address: 0x1026fb0 */
  pActwk->r_no0 += 2; /* Line 1023, Address: 0x1026fb8 */
  hari3x_spdset(pActwk); /* Line 1024, Address: 0x1026fc8 */
  hari3x_brkn(pActwk); /* Line 1025, Address: 0x1026fd4 */
} /* Line 1026, Address: 0x1026fe0 */











void hari3x_move(sprite_status* pActwk) { /* Line 1038, Address: 0x1026ff0 */
  short i, iD0, iD1;
  sprite_status* pActmsnc;

  if (pActwk->userflag.b.h == 1) { /* Line 1042, Address: 0x102700c */

    hari3x_ridechk(pActwk); /* Line 1044, Address: 0x1027028 */
    return; /* Line 1045, Address: 0x1027034 */
  }

  pActmsnc = &actwk[32]; /* Line 1048, Address: 0x102703c */

  for (i = 0; i < 96; ++i, ++pActmsnc) { /* Line 1050, Address: 0x1027044 */

    if (pActmsnc->actno == 49) break; /* Line 1052, Address: 0x1027050 */
  } /* Line 1053, Address: 0x1027064 */
  if (pActmsnc->actno != 49) { /* Line 1054, Address: 0x1027088 */

    hari3x_ridechk(pActwk); /* Line 1056, Address: 0x102709c */
    return; /* Line 1057, Address: 0x10270a8 */
  }

  iD1 = (char)pActwk->sprhsize; /* Line 1060, Address: 0x10270b0 */
  iD1 += 16; /* Line 1061, Address: 0x10270d0 */
  iD0 = pActmsnc->xposi.w.h - pActwk->xposi.w.h; /* Line 1062, Address: 0x10270dc */
  iD0 += iD1; /* Line 1063, Address: 0x102710c */
  if (iD0 < 0) { /* Line 1064, Address: 0x1027118 */

    hari3x_ridechk(pActwk); /* Line 1066, Address: 0x1027128 */
    return; /* Line 1067, Address: 0x1027134 */
  }
  iD1 += iD1; /* Line 1069, Address: 0x102713c */
  if (iD1 >= iD0) { /* Line 1070, Address: 0x1027148 */

    hari3x_ridechk(pActwk); /* Line 1072, Address: 0x1027164 */
    return; /* Line 1073, Address: 0x1027170 */
  }

  iD1 = (char)pActwk->sprvsize; /* Line 1076, Address: 0x1027178 */
  iD1 += iD1; /* Line 1077, Address: 0x1027198 */
  iD0 = pActmsnc->xposi.w.h - pActwk->yposi.w.h; /* Line 1078, Address: 0x10271a4 */
  iD0 += iD1; /* Line 1079, Address: 0x10271d4 */
  if (iD0 < 0) { /* Line 1080, Address: 0x10271e0 */

    hari3x_ridechk(pActwk); /* Line 1082, Address: 0x10271f0 */
    return; /* Line 1083, Address: 0x10271fc */
  }
  iD1 += iD1; /* Line 1085, Address: 0x1027204 */
  if (iD0 >= iD1) { /* Line 1086, Address: 0x1027210 */

    hari3x_ridechk(pActwk); /* Line 1088, Address: 0x102722c */
    return; /* Line 1089, Address: 0x1027238 */
  }
  pActwk->r_no0 += 2; /* Line 1091, Address: 0x1027240 */
  brknset(pActwk); /* Line 1092, Address: 0x1027250 */
  ride_on_clr(pActwk, &actwk[0]); /* Line 1093, Address: 0x102725c */
} /* Line 1094, Address: 0x1027270 */











void brknset(sprite_status* pActwk) { /* Line 1106, Address: 0x1027290 */
  short iD1, iD2;
  sprite_status* pActfree;

  iD1 = 3; /* Line 1110, Address: 0x10272a4 */
  pActwk->patno = 4; /* Line 1111, Address: 0x10272b0 */
  iD2 = 0; /* Line 1112, Address: 0x10272bc */
  if (pActwk->userflag.b.h != 0) { /* Line 1113, Address: 0x10272c0 */

    pActwk->patno = 8; /* Line 1115, Address: 0x10272d8 */
    iD2 = 4; /* Line 1116, Address: 0x10272e4 */
    if (pActwk->userflag.b.h != 2) { /* Line 1117, Address: 0x10272f0 */

      pActwk->patno = 13; /* Line 1119, Address: 0x102730c */
      iD2 = 9; /* Line 1120, Address: 0x1027318 */
    }
  }

  while (iD1 > 0) { /* Line 1124, Address: 0x1027324 */

    if (actwkchk(&pActfree) == 0) { /* Line 1126, Address: 0x102732c */

      pActfree->actno = 48; /* Line 1128, Address: 0x1027340 */
      pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 1129, Address: 0x102734c */
      pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 1130, Address: 0x102735c */
      pActfree->patno = iD1 + iD2; /* Line 1131, Address: 0x102736c */
      pActfree->actfree[18] = iD1; /* Line 1132, Address: 0x102738c */
    }

    --iD1; /* Line 1135, Address: 0x1027398 */
  } /* Line 1136, Address: 0x10273a4 */
  if (pActwk->actflg & 128) { /* Line 1137, Address: 0x10273b4 */

    soundset(163); /* Line 1139, Address: 0x10273cc */
  }
  hari3x_spdset(pActwk); /* Line 1141, Address: 0x10273d8 */
} /* Line 1142, Address: 0x10273e4 */


















void hari3x_spdset(sprite_status* pActwk) { /* Line 1161, Address: 0x1027400 */
  unsigned char byD0;

  byD0 = pActwk->actfree[18]; /* Line 1164, Address: 0x102740c */
  byD0 *= 2; /* Line 1165, Address: 0x1027418 */
  pActwk->xspeed.w = spd_tbl[byD0]; /* Line 1166, Address: 0x1027428 */
  pActwk->yspeed.w = spd_tbl[byD0 + 1]; /* Line 1167, Address: 0x1027448 */
  ((short*)pActwk)[33] = 96; /* Line 1168, Address: 0x102746c */
  pActwk->actfree[16] = 120; /* Line 1169, Address: 0x1027478 */
} /* Line 1170, Address: 0x1027484 */











void hari3x_brkn(sprite_status* pActwk) { /* Line 1182, Address: 0x10274a0 */
  short iD0;

  emie_speedset(pActwk); /* Line 1185, Address: 0x10274b0 */
  iD0 = ((short*)pActwk)[33]; /* Line 1186, Address: 0x10274bc */
  pActwk->yspeed.w += iD0; /* Line 1187, Address: 0x10274cc */
  --pActwk->actfree[16]; /* Line 1188, Address: 0x10274dc */
  if (pActwk->actfree[16] == 0) { /* Line 1189, Address: 0x10274ec */

    frameout(pActwk); /* Line 1191, Address: 0x1027500 */
    jmp_flg = 1; /* Line 1192, Address: 0x102750c */
  }
} /* Line 1194, Address: 0x1027518 */


















void heart3(sprite_status* pActwk) { /* Line 1213, Address: 0x1027530 */
  jmp_flg = 0; /* Line 1214, Address: 0x102753c */
  heart_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1215, Address: 0x1027544 */
  if (jmp_flg == 0) { /* Line 1216, Address: 0x1027588 */

    actionsub(pActwk); /* Line 1218, Address: 0x102759c */
    frameout_s(pActwk); /* Line 1219, Address: 0x10275a8 */
  }
  jmp_flg = 0; /* Line 1221, Address: 0x10275b4 */
} /* Line 1222, Address: 0x10275bc */











void heart3_init(sprite_status* pActwk) { /* Line 1234, Address: 0x10275d0 */
  pActwk->r_no0 += 2; /* Line 1235, Address: 0x10275dc */
  pActwk->actflg |= 4; /* Line 1236, Address: 0x10275ec */
  pActwk->sproffset = 862; /* Line 1237, Address: 0x10275fc */
  pActwk->patbase = emie3pat; /* Line 1238, Address: 0x1027608 */
  pActwk->sprpri = 3; /* Line 1239, Address: 0x1027618 */
  pActwk->yspeed.w = -96; /* Line 1240, Address: 0x1027624 */
  pActwk->patno = 8; /* Line 1241, Address: 0x1027630 */
  heart3_move(pActwk); /* Line 1242, Address: 0x102763c */
} /* Line 1243, Address: 0x1027648 */











void heart3_move(sprite_status* pActwk) { /* Line 1255, Address: 0x1027660 */
  unsigned char byR;
  short iD0, iD1;

  if (pActwk->actfree[18] == 0) { /* Line 1259, Address: 0x1027670 */

    byR = pActwk->actfree[16]; /* Line 1261, Address: 0x1027684 */
    byR *= 3; /* Line 1262, Address: 0x1027690 */
    sinset(byR, &iD0, &iD1); /* Line 1263, Address: 0x10276a4 */
    iD0 /= 4; /* Line 1264, Address: 0x10276b8 */
    pActwk->xspeed.w = iD0; /* Line 1265, Address: 0x10276d8 */
  }

  emie_speedset(pActwk); /* Line 1268, Address: 0x10276e4 */
  ++pActwk->actfree[16]; /* Line 1269, Address: 0x10276f0 */
  if (pActwk->actfree[16] == 20) /* Line 1270, Address: 0x1027700 */
    ++pActwk->patno; /* Line 1271, Address: 0x1027718 */

  if (pActwk->actfree[16] == 110) { /* Line 1273, Address: 0x1027728 */

    ++pActwk->patno; /* Line 1275, Address: 0x1027740 */
    pActwk->yspeed.w = 0; /* Line 1276, Address: 0x1027750 */
    pActwk->xspeed.w = 0; /* Line 1277, Address: 0x1027758 */
    pActwk->actfree[18] = 255; /* Line 1278, Address: 0x1027760 */
  }

  if (pActwk->actfree[16] == 120) { /* Line 1281, Address: 0x102776c */

    frameout(pActwk); /* Line 1283, Address: 0x1027784 */
    jmp_flg = 1; /* Line 1284, Address: 0x1027790 */
  }
} /* Line 1286, Address: 0x102779c */
















void msnc3fire(sprite_status* pActwk) { /* Line 1303, Address: 0x10277b0 */
  msfire_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1304, Address: 0x10277bc */
  actionsub(pActwk); /* Line 1305, Address: 0x1027800 */
} /* Line 1306, Address: 0x102780c */











void msnc3fire_init(sprite_status* pActwk) { /* Line 1318, Address: 0x1027820 */
  pActwk->r_no0 += 2; /* Line 1319, Address: 0x102782c */
  pActwk->actflg |= 4; /* Line 1320, Address: 0x102783c */
  pActwk->sproffset = 976; /* Line 1321, Address: 0x102784c */
  pActwk->patbase = mecasnc3pat; /* Line 1322, Address: 0x1027858 */
  pActwk->sprpri = 3; /* Line 1323, Address: 0x1027868 */
  msnc3fire_move(pActwk); /* Line 1324, Address: 0x1027874 */
} /* Line 1325, Address: 0x1027880 */











void msnc3fire_move(sprite_status* pActwk) { /* Line 1337, Address: 0x1027890 */
  short iD0;
  sprite_status* pActmsnc;

  iD0 = ((short*)pActwk)[28]; /* Line 1341, Address: 0x10278a4 */
  pActmsnc = &actwk[iD0]; /* Line 1342, Address: 0x10278b4 */
  if (pActmsnc->actno != 49) { /* Line 1343, Address: 0x10278d4 */

    frameout(pActwk); /* Line 1345, Address: 0x10278e8 */
    jmp_flg = 1; /* Line 1346, Address: 0x10278f4 */
    return; /* Line 1347, Address: 0x1027900 */
  }
  iD0 = pActmsnc->xposi.w.h; /* Line 1349, Address: 0x1027908 */
  iD0 -= 16; /* Line 1350, Address: 0x1027914 */
  if (pActmsnc->cddat & 1) /* Line 1351, Address: 0x1027920 */
    iD0 += 32; /* Line 1352, Address: 0x1027934 */

  pActwk->xposi.w.h = iD0; /* Line 1354, Address: 0x1027940 */
  pActwk->yposi.w.h = pActmsnc->yposi.w.h; /* Line 1355, Address: 0x1027948 */

  patchg(pActwk, fire_pchg); /* Line 1357, Address: 0x1027954 */
  jmp_flg = 1; /* Line 1358, Address: 0x1027968 */
} /* Line 1359, Address: 0x1027974 */
