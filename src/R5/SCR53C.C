#include "..\EQU.H"
#include "SCR53C.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51cline(short** ppHscw);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_v(short yPos);
static void scrollb_h(int xoffs, int flgbit);
static void scrollc_h(int xoffs, int flgbit);
static void scrollz_h(int xoffs, int flgbit);
static void scroll_h();
static void scrh_move();
static void scroll_v();
static void sv_move_main(short yPos);
static void sv_move_main2(short yPos);
static void sv_move_sub(short yPos);
static void sv_move_sub2();
static void sv_move_minus(short speed);
static void scrv_up_ch(int_union lSpd);
static void sv_move_plus(short sSpd);
static void scrv_down_ch(int_union lSpd);
static void scrv_move(int_union lSpd);

static unsigned char z81awrttbl[65];
static int_union* vblockwrtbtbl[8] = {
  &scrb_h_posiw,
  &scrb_v_posiw,
  &scrb_h_posiw,
  &scrb_v_posiw,
  &scrc_h_posiw,
  &scrc_v_posiw,
  &scrz_h_posiw,
  &scrz_v_posiw
};
static int_union* mapwrt_tbl[8] = {
  &scrb_h_posiw,
  &scrb_v_posiw,
  &scrb_h_posiw,
  &scrb_v_posiw,
  &scrc_h_posiw,
  &scrc_v_posiw,
  &scrz_h_posiw,
  &scrz_v_posiw
};
short scr_dir_tbl[6] = { 4, 0, 3735, 0, 800, 96 };
short endplpositbl[8][2] = {
  {   80,  944 },
  { 3744, 1132 },
  { 5968,  189 },
  { 2560, 1580 },
  { 2992,   76 },
  { 5488,  364 },
  {  432, 1836 },
  { 5120,  684 }
};
short playpositbl[1][2] = { { 64, 620 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;
extern void(*ChangeTileBmp)(int, int);


















































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 150, Address: 0x101cb70 */
    return &actwk[0]; /* Line 151, Address: 0x101cb84 */
  else
    return &actwk[1]; /* Line 153, Address: 0x101cb94 */

} /* Line 155, Address: 0x101cb9c */





































void scr_set() { /* Line 193, Address: 0x101cbb0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 196, Address: 0x101cbbc */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x101cbd0 */
  scr_timer.b.h = 0; /* Line 198, Address: 0x101cbe4 */

  pScrTbl = scr_dir_tbl; /* Line 200, Address: 0x101cbec */
  scrar_no = *pScrTbl; /* Line 201, Address: 0x101cbf4 */
  ++pScrTbl; /* Line 202, Address: 0x101cc00 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 203, Address: 0x101cc04 */
  ++pScrTbl; /* Line 204, Address: 0x101cc18 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 205, Address: 0x101cc1c */
  ++pScrTbl; /* Line 206, Address: 0x101cc30 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 207, Address: 0x101cc34 */
  ++pScrTbl; /* Line 208, Address: 0x101cc48 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 209, Address: 0x101cc4c */
  scra_h_keep = *pScrTbl + 576; /* Line 210, Address: 0x101cc60 */
  ++pScrTbl; /* Line 211, Address: 0x101cc80 */
  scra_h_count = 16; /* Line 212, Address: 0x101cc84 */
  scra_v_count = 16; /* Line 213, Address: 0x101cc90 */

  scra_vline = *pScrTbl; /* Line 215, Address: 0x101cc9c */
  scra_hline = 160; /* Line 216, Address: 0x101cca8 */

  playposiset(); /* Line 218, Address: 0x101ccb4 */
} /* Line 219, Address: 0x101ccbc */
















































static void playposiset() { /* Line 268, Address: 0x101ccd0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 271, Address: 0x101cce4 */
    playload(); /* Line 272, Address: 0x101ccf4 */
    xwk = actwk[0].xposi.w.h; /* Line 273, Address: 0x101ccfc */

    if (actwk[0].yposi.w.h > 0) { /* Line 275, Address: 0x101cd0c */
      ywk = actwk[0].yposi.w.h; /* Line 276, Address: 0x101cd24 */
    } else { /* Line 277, Address: 0x101cd34 */
      ywk = 0; /* Line 278, Address: 0x101cd3c */
    }
  } /* Line 280, Address: 0x101cd40 */
  else {
    if (demoflag.w & -32768) { /* Line 282, Address: 0x101cd48 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 283, Address: 0x101cd68 */
    } /* Line 284, Address: 0x101cd8c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 286, Address: 0x101cd94 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 290, Address: 0x101cdb4 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 291, Address: 0x101cdc8 */
  }


  if (xwk > 160) { /* Line 295, Address: 0x101cddc */
    xwk -= 160; /* Line 296, Address: 0x101cdf0 */
  } else { /* Line 297, Address: 0x101cdfc */
    xwk = 0; /* Line 298, Address: 0x101ce04 */
  }


  if (xwk > scralim_right) { /* Line 302, Address: 0x101ce08 */
    xwk = scralim_right; /* Line 303, Address: 0x101ce2c */
  }


  scra_h_posit.w.h = xwk; /* Line 307, Address: 0x101ce3c */

  if (ywk > 96) { /* Line 309, Address: 0x101ce44 */
    ywk -= 96; /* Line 310, Address: 0x101ce58 */
  } else { /* Line 311, Address: 0x101ce64 */
    ywk = 0; /* Line 312, Address: 0x101ce6c */
  }


  if (ywk > scralim_down) { /* Line 316, Address: 0x101ce70 */
    ywk = scralim_down; /* Line 317, Address: 0x101ce94 */
  }


  scra_v_posit.w.h = ywk; /* Line 321, Address: 0x101cea4 */

  scrbinit(xwk, ywk); /* Line 323, Address: 0x101ceac */


  loopmapno = playmapnotbl[0]; /* Line 326, Address: 0x101cebc */
  loopmapno2 = playmapnotbl[1]; /* Line 327, Address: 0x101cecc */
  ballmapno = playmapnotbl[2]; /* Line 328, Address: 0x101cedc */
  ballmapno2 = playmapnotbl[3]; /* Line 329, Address: 0x101ceec */
} /* Line 330, Address: 0x101cefc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 351, Address: 0x101cf20 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 354, Address: 0x101cf2c */
  lYwk.w.l = 0; /* Line 355, Address: 0x101cf34 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 357, Address: 0x101cf38 */

  scrb_v_posit.l = lYwk.l; /* Line 359, Address: 0x101cf44 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 360, Address: 0x101cf50 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 361, Address: 0x101cf5c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 363, Address: 0x101cf68 */
  scrb_h_posit.w.h = sXpos; /* Line 364, Address: 0x101cf84 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 366, Address: 0x101cf90 */
  scrc_h_posit.w.h = sXpos; /* Line 367, Address: 0x101cfac */

  sXpos >>= 2; /* Line 369, Address: 0x101cfb8 */
  scrz_h_posit.w.h = sXpos * 3; /* Line 370, Address: 0x101cfc4 */
} /* Line 371, Address: 0x101cfe8 */















void scroll() { /* Line 387, Address: 0x101d000 */
  int_union ldwk;
  int_union* pHscrbuf;
  int i;
  int lXwk;
  int lYwk;
  short sYnum;
  short* psHscr;
  short* psHscw;
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };
  static unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 };

  if (scroll_start.b.h) return; /* Line 399, Address: 0x101d01c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 404, Address: 0x101d02c */

  scrchk(); /* Line 406, Address: 0x101d058 */

  scroll_h(); /* Line 408, Address: 0x101d060 */
  scroll_v(); /* Line 409, Address: 0x101d068 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 411, Address: 0x101d070 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 412, Address: 0x101d080 */


  lXwk = scra_hz * 16 * 3; /* Line 415, Address: 0x101d090 */
  scrollz_h(lXwk, 6); /* Line 416, Address: 0x101d0ac */

  lXwk = scra_hz * 64; /* Line 418, Address: 0x101d0bc */
  scrollc_h(lXwk, 4); /* Line 419, Address: 0x101d0d0 */

  lXwk = scra_hz * 128; /* Line 421, Address: 0x101d0e0 */
  scrollb_h(lXwk, 2); /* Line 422, Address: 0x101d0f4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 424, Address: 0x101d104 */


  scrollb_v(lYwk); /* Line 427, Address: 0x101d118 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 429, Address: 0x101d128 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 430, Address: 0x101d150 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 431, Address: 0x101d188 */

  psHscw = hscrollwork; /* Line 433, Address: 0x101d19c */


  ldwk.w.l = -scrz_h_posit.w.h; /* Line 436, Address: 0x101d1a8 */
  for (i = 0; i < 14; ++i) { /* Line 437, Address: 0x101d1c8 */

    *psHscw++ = ldwk.w.l; /* Line 439, Address: 0x101d1d4 */
  } /* Line 440, Address: 0x101d1e8 */
  z51cline(&psHscw); /* Line 441, Address: 0x101d1f8 */


  pHscrbuf = lphscrollbuff; /* Line 444, Address: 0x101d204 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 445, Address: 0x101d210 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 446, Address: 0x101d240 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 447, Address: 0x101d270 */
} /* Line 448, Address: 0x101d28c */













static void z51cline(short** ppHscw) { /* Line 462, Address: 0x101d2b0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51cscrtbl[3] = { /* Line 467, Address: 0x101d2c8 */
    39, 3, 9
  };

  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 471, Address: 0x101d2ec */
  lHwk = (unsigned int)lHwk * 128 / 12; /* Line 472, Address: 0x101d310 */
  lHwk *= 512; /* Line 473, Address: 0x101d32c */

  ldHposwk.l = 0; /* Line 475, Address: 0x101d330 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 476, Address: 0x101d334 */

  for (i = 2; i >= 0; --i) { /* Line 478, Address: 0x101d340 */

    wk = -ldHposwk.w.l; /* Line 480, Address: 0x101d34c */

    for (j = z51cscrtbl[i]; j >= 0; --j) { /* Line 482, Address: 0x101d36c */

      **ppHscw = wk; /* Line 484, Address: 0x101d384 */
      ++*ppHscw; /* Line 485, Address: 0x101d390 */
    } /* Line 486, Address: 0x101d3a4 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 488, Address: 0x101d3b0 */
    ldHposwk.l += lHwk; /* Line 489, Address: 0x101d3d4 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 490, Address: 0x101d3e0 */
  } /* Line 491, Address: 0x101d404 */
} /* Line 492, Address: 0x101d410 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 513, Address: 0x101d430 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 517, Address: 0x101d44c */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 519, Address: 0x101d450 */
    ldwk.w.l = *pHscrwk; /* Line 520, Address: 0x101d46c */
    ++pHscrwk; /* Line 521, Address: 0x101d478 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 523, Address: 0x101d484 */
      (*pHscrbuf)->l = ldwk.l; /* Line 524, Address: 0x101d48c */
    } /* Line 525, Address: 0x101d49c */
  } /* Line 526, Address: 0x101d4c0 */
} /* Line 527, Address: 0x101d4e0 */









































































































static void scrollb_v(short yPos) { /* Line 633, Address: 0x101d500 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 636, Address: 0x101d510 */
  scrb_v_posit.w.h = yPos; /* Line 637, Address: 0x101d520 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 638, Address: 0x101d52c */

  if (!ywk) { /* Line 640, Address: 0x101d564 */
    scrb_v_count ^= 16; /* Line 641, Address: 0x101d56c */
    if (yPos - ysv < 0) { /* Line 642, Address: 0x101d580 */
      scrflagb.b.h |= 1; /* Line 643, Address: 0x101d5a0 */
    } /* Line 644, Address: 0x101d5b4 */
    else {
      scrflagb.b.h |= 2; /* Line 646, Address: 0x101d5bc */
    }
  }


} /* Line 651, Address: 0x101d5d0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 669, Address: 0x101d5f0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 673, Address: 0x101d604 */
  lXwk = lXsv + xoffs; /* Line 674, Address: 0x101d60c */
  scrb_h_posit.l = lXwk; /* Line 675, Address: 0x101d614 */
  ldXwk.l = lXwk; /* Line 676, Address: 0x101d61c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 677, Address: 0x101d620 */
  ldXwk.w.l &= 16; /* Line 678, Address: 0x101d644 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 679, Address: 0x101d650 */

  if (!ldXwk.b.b4) { /* Line 681, Address: 0x101d66c */
    scrb_h_count ^= 16; /* Line 682, Address: 0x101d678 */
    if (lXwk - lXsv < 0) { /* Line 683, Address: 0x101d68c */
      scrflagb.b.h |= 1 << flgbit; /* Line 684, Address: 0x101d698 */
    } /* Line 685, Address: 0x101d6bc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 687, Address: 0x101d6c4 */
    }
  }


} /* Line 692, Address: 0x101d6ec */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 710, Address: 0x101d700 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 714, Address: 0x101d714 */
  lXwk = lXsv + xoffs; /* Line 715, Address: 0x101d71c */
  scrc_h_posit.l = lXwk; /* Line 716, Address: 0x101d724 */
  ldXwk.l = lXwk; /* Line 717, Address: 0x101d72c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 718, Address: 0x101d730 */
  ldXwk.w.l &= 16; /* Line 719, Address: 0x101d754 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 720, Address: 0x101d760 */

  if (!ldXwk.b.b4) { /* Line 722, Address: 0x101d77c */
    scrc_h_count ^= 16; /* Line 723, Address: 0x101d788 */
    if (lXwk - lXsv < 0) { /* Line 724, Address: 0x101d79c */
      scrflagc.b.h |= 1 << flgbit; /* Line 725, Address: 0x101d7a8 */
    } /* Line 726, Address: 0x101d7cc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 728, Address: 0x101d7d4 */
    }
  }


} /* Line 733, Address: 0x101d7fc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 751, Address: 0x101d810 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 755, Address: 0x101d824 */
  lXwk = lXsv + xoffs; /* Line 756, Address: 0x101d82c */
  scrz_h_posit.l = lXwk; /* Line 757, Address: 0x101d834 */
  ldXwk.l = lXwk; /* Line 758, Address: 0x101d83c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 759, Address: 0x101d840 */
  ldXwk.w.l &= 16; /* Line 760, Address: 0x101d864 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 761, Address: 0x101d870 */

  if (!ldXwk.b.b4) { /* Line 763, Address: 0x101d88c */
    scrz_h_count ^= 16; /* Line 764, Address: 0x101d898 */
    if (lXwk - lXsv < 0) { /* Line 765, Address: 0x101d8ac */
      scrflagz.b.h |= 1 << flgbit; /* Line 766, Address: 0x101d8b8 */
    } /* Line 767, Address: 0x101d8dc */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 769, Address: 0x101d8e4 */
    }
  }


} /* Line 774, Address: 0x101d90c */














static void scroll_h() { /* Line 789, Address: 0x101d920 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 793, Address: 0x101d930 */

  scrh_move(); /* Line 795, Address: 0x101d940 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 796, Address: 0x101d948 */
  if (!bXwk) { /* Line 797, Address: 0x101d97c */
    scra_h_count ^= 16; /* Line 798, Address: 0x101d984 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 799, Address: 0x101d998 */
      scrflaga.b.h |= 4; /* Line 800, Address: 0x101d9bc */
    } else { /* Line 801, Address: 0x101d9d0 */
      scrflaga.b.h |= 8; /* Line 802, Address: 0x101d9d8 */
    }
  }


} /* Line 807, Address: 0x101d9ec */
















static void scrh_move() { /* Line 824, Address: 0x101da10 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 827, Address: 0x101da18 */
  if (xwk == 0) { /* Line 828, Address: 0x101da60 */

    scra_hz = 0; /* Line 830, Address: 0x101da70 */
    return; /* Line 831, Address: 0x101da78 */
  } else if (xwk < 0) { /* Line 832, Address: 0x101da80 */

    if (xwk < -16) { /* Line 834, Address: 0x101da90 */
      xwk = -16; /* Line 835, Address: 0x101daa4 */
    }


    xwk += scra_h_posit.w.h; /* Line 839, Address: 0x101dab0 */
    if (xwk < scralim_left) { /* Line 840, Address: 0x101dac4 */
      xwk = scralim_left; /* Line 841, Address: 0x101dae8 */
    }
  } /* Line 843, Address: 0x101daf8 */
  else {
    if (xwk > 16) { /* Line 845, Address: 0x101db00 */
      xwk = 16; /* Line 846, Address: 0x101db14 */
    }


    xwk += scra_h_posit.w.h; /* Line 850, Address: 0x101db20 */
    if (xwk > scralim_right) { /* Line 851, Address: 0x101db34 */
      xwk = scralim_right; /* Line 852, Address: 0x101db58 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 857, Address: 0x101db68 */
  scra_h_posit.w.h = xwk; /* Line 858, Address: 0x101db98 */
} /* Line 859, Address: 0x101dba0 */














static void scroll_v() { /* Line 874, Address: 0x101dbb0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 877, Address: 0x101dbbc */
  if (actwk[0].cddat & 4) { /* Line 878, Address: 0x101dbf0 */
    ywk -= 5; /* Line 879, Address: 0x101dc08 */
  }


  if (actwk[0].cddat & 2) { /* Line 883, Address: 0x101dc14 */
    ywk += 32; /* Line 884, Address: 0x101dc2c */
    if (ywk < scra_vline) { /* Line 885, Address: 0x101dc38 */
      ywk -= scra_vline; /* Line 886, Address: 0x101dc5c */
      sv_move_main2(ywk); /* Line 887, Address: 0x101dc70 */
      return; /* Line 888, Address: 0x101dc7c */
    } else if (ywk >= scra_vline + 64) { /* Line 889, Address: 0x101dc84 */
      ywk -= scra_vline + 64; /* Line 890, Address: 0x101dcac */
      sv_move_main2(ywk); /* Line 891, Address: 0x101dcd4 */
      return; /* Line 892, Address: 0x101dce0 */
    }
    ywk -= scra_vline + 64; /* Line 894, Address: 0x101dce8 */
    if (!limmoveflag) goto label1; /* Line 895, Address: 0x101dd10 */
    sv_move_sub2(); /* Line 896, Address: 0x101dd20 */
    return; /* Line 897, Address: 0x101dd28 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 902, Address: 0x101dd30 */
    sv_move_main(ywk); /* Line 903, Address: 0x101dd5c */
    return; /* Line 904, Address: 0x101dd68 */
  } else if (!limmoveflag) goto label1; /* Line 905, Address: 0x101dd70 */
  sv_move_sub2(); /* Line 906, Address: 0x101dd80 */
  return; /* Line 907, Address: 0x101dd88 */



label1:
  scra_vz = 0; /* Line 912, Address: 0x101dd90 */
} /* Line 913, Address: 0x101dd98 */













static void sv_move_main(short yPos) { /* Line 927, Address: 0x101ddb0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 930, Address: 0x101ddc0 */
    if (actwk[0].mspeed.w < 0) { /* Line 931, Address: 0x101dddc */
      spdwk = -actwk[0].mspeed.w; /* Line 932, Address: 0x101ddf4 */
    } else { /* Line 933, Address: 0x101de18 */
      spdwk = actwk[0].mspeed.w; /* Line 934, Address: 0x101de20 */
    }


    if (spdwk >= 2048) { /* Line 938, Address: 0x101de30 */
      sv_move_main2(yPos); /* Line 939, Address: 0x101de44 */
    } /* Line 940, Address: 0x101de50 */
    else {

      if (yPos > 6) { /* Line 943, Address: 0x101de58 */
        sv_move_plus(1536); /* Line 944, Address: 0x101de70 */
      } else if (yPos < -6) { /* Line 945, Address: 0x101de7c */
        sv_move_minus(1536); /* Line 946, Address: 0x101de9c */
      } /* Line 947, Address: 0x101dea8 */
      else sv_move_sub(yPos); /* Line 948, Address: 0x101deb0 */
    }
  } /* Line 950, Address: 0x101debc */
  else {
    if (yPos > 2) { /* Line 952, Address: 0x101dec4 */
      sv_move_plus(512); /* Line 953, Address: 0x101dedc */
    } else if (yPos < -2) { /* Line 954, Address: 0x101dee8 */
      sv_move_minus(512); /* Line 955, Address: 0x101df08 */
    } /* Line 956, Address: 0x101df14 */
    else sv_move_sub(yPos); /* Line 957, Address: 0x101df1c */
  }

} /* Line 960, Address: 0x101df28 */













static void sv_move_main2(short yPos) { /* Line 974, Address: 0x101df40 */
  short spdwk;

  spdwk = 4096; /* Line 977, Address: 0x101df50 */

  if (yPos > 16) { /* Line 979, Address: 0x101df5c */
    sv_move_plus(spdwk); /* Line 980, Address: 0x101df74 */
  } else if (yPos < -16) { /* Line 981, Address: 0x101df80 */
    sv_move_minus(spdwk); /* Line 982, Address: 0x101dfa0 */
  } else { /* Line 983, Address: 0x101dfac */
    sv_move_sub(yPos); /* Line 984, Address: 0x101dfb4 */
  }
} /* Line 986, Address: 0x101dfc0 */














static void sv_move_sub(short yPos) { /* Line 1001, Address: 0x101dfe0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1004, Address: 0x101dfec */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1005, Address: 0x101dff0 */
  if (yPos < 0) { /* Line 1006, Address: 0x101e01c */
    scrv_up_ch(lSpd); /* Line 1007, Address: 0x101e030 */
  } else { /* Line 1008, Address: 0x101e03c */
    scrv_down_ch(lSpd); /* Line 1009, Address: 0x101e044 */
  }
} /* Line 1011, Address: 0x101e050 */



static void sv_move_sub2() { /* Line 1015, Address: 0x101e060 */
  limmoveflag = 0; /* Line 1016, Address: 0x101e068 */

  sv_move_sub(0); /* Line 1018, Address: 0x101e070 */
} /* Line 1019, Address: 0x101e07c */













static void sv_move_minus(short speed) { /* Line 1033, Address: 0x101e090 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1036, Address: 0x101e09c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1037, Address: 0x101e0c0 */
  scrv_up_ch(lSpd); /* Line 1038, Address: 0x101e0e4 */
} /* Line 1039, Address: 0x101e0f0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1054, Address: 0x101e100 */
  if (lSpd.w.l <= scralim_up) { /* Line 1055, Address: 0x101e10c */
    if (lSpd.w.l > -256) { /* Line 1056, Address: 0x101e134 */

      lSpd.w.l = scralim_up; /* Line 1058, Address: 0x101e14c */
    } else { /* Line 1059, Address: 0x101e158 */
      lSpd.w.l &= 2047; /* Line 1060, Address: 0x101e160 */
      actwk[0].yposi.w.l &= 2047; /* Line 1061, Address: 0x101e16c */
      scra_v_posit.w.h &= 2047; /* Line 1062, Address: 0x101e180 */
      scrb_v_posit.w.h &= 1023; /* Line 1063, Address: 0x101e194 */
    }
  }

  scrv_move(lSpd); /* Line 1067, Address: 0x101e1a8 */
} /* Line 1068, Address: 0x101e1b4 */













static void sv_move_plus(short sSpd) { /* Line 1082, Address: 0x101e1d0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1085, Address: 0x101e1dc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1086, Address: 0x101e1fc */
  scrv_down_ch(lSpd); /* Line 1087, Address: 0x101e220 */
} /* Line 1088, Address: 0x101e22c */














static void scrv_down_ch(int_union lSpd) { /* Line 1103, Address: 0x101e240 */
  if (lSpd.w.l >= scralim_down) { /* Line 1104, Address: 0x101e24c */
    if (lSpd.w.l < 2048) { /* Line 1105, Address: 0x101e274 */

      lSpd.w.l = scralim_down; /* Line 1107, Address: 0x101e28c */
    } else { /* Line 1108, Address: 0x101e298 */
      lSpd.w.l -= 2048; /* Line 1109, Address: 0x101e2a0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1110, Address: 0x101e2ac */
      scra_v_posit.w.h -= 2048; /* Line 1111, Address: 0x101e2c0 */
      scrb_v_posit.w.h &= 1023; /* Line 1112, Address: 0x101e2d4 */
    }
  }

  scrv_move(lSpd); /* Line 1116, Address: 0x101e2e8 */
} /* Line 1117, Address: 0x101e2f4 */
















static void scrv_move(int_union lSpd) { /* Line 1134, Address: 0x101e310 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1138, Address: 0x101e320 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1139, Address: 0x101e330 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1140, Address: 0x101e354 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1141, Address: 0x101e368 */
  scra_vz = spdwk.w.l; /* Line 1142, Address: 0x101e380 */

  scra_v_posit.l = lSpd.l; /* Line 1144, Address: 0x101e38c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1146, Address: 0x101e398 */
  if (!ywk) { /* Line 1147, Address: 0x101e3d4 */
    scra_v_count ^= 16; /* Line 1148, Address: 0x101e3dc */
    ywk = scra_v_posit.w.h - ysv; /* Line 1149, Address: 0x101e3f0 */
    if (ywk < 0) { /* Line 1150, Address: 0x101e41c */
      scrflaga.b.h |= 1; /* Line 1151, Address: 0x101e42c */
    } else { /* Line 1152, Address: 0x101e440 */
      scrflaga.b.h |= 2; /* Line 1153, Address: 0x101e448 */
    }
  }


} /* Line 1158, Address: 0x101e45c */

















void scrollwrt() { /* Line 1176, Address: 0x101e470 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1185, Address: 0x101e490 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1186, Address: 0x101e494 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1187, Address: 0x101e4a0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1188, Address: 0x101e4ac */
  pScrFlag = &scrflagbw.b.h; /* Line 1189, Address: 0x101e4b4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1190, Address: 0x101e4bc */

  VramBase = 16384; /* Line 1192, Address: 0x101e4d0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1193, Address: 0x101e4d4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1194, Address: 0x101e4e0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1195, Address: 0x101e4ec */
  pScrFlag = &scrflagaw.b.h; /* Line 1196, Address: 0x101e4f4 */

  if (*pScrFlag) { /* Line 1198, Address: 0x101e4fc */
    if (*pScrFlag & 1) { /* Line 1199, Address: 0x101e508 */
      *pScrFlag &= 254; /* Line 1200, Address: 0x101e51c */

      lD4.l = -16; /* Line 1202, Address: 0x101e528 */
      wD5 = 65520; /* Line 1203, Address: 0x101e530 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1205, Address: 0x101e538 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1207, Address: 0x101e558 */
    }




    if (*pScrFlag & 2) { /* Line 1213, Address: 0x101e584 */
      *pScrFlag &= 253; /* Line 1214, Address: 0x101e598 */

      lD4.l = 224; /* Line 1216, Address: 0x101e5a4 */
      wD5 = 65520; /* Line 1217, Address: 0x101e5ac */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1218, Address: 0x101e5b4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1220, Address: 0x101e5d4 */
    }




    if (*pScrFlag & 4) { /* Line 1226, Address: 0x101e600 */
      *pScrFlag &= 251; /* Line 1227, Address: 0x101e614 */

      lD4.l = -16; /* Line 1229, Address: 0x101e620 */
      wD5 = 65520; /* Line 1230, Address: 0x101e628 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1231, Address: 0x101e630 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1233, Address: 0x101e650 */
    }




    if (*pScrFlag & 8) { /* Line 1239, Address: 0x101e67c */
      *pScrFlag &= 247; /* Line 1240, Address: 0x101e690 */

      lD4.l = -16; /* Line 1242, Address: 0x101e69c */
      wD5 = 320; /* Line 1243, Address: 0x101e6a4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x101e6ac */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1246, Address: 0x101e6cc */
    }
  }






} /* Line 1255, Address: 0x101e6f8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1272, Address: 0x101e720 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1283, Address: 0x101e74c */

  if (*pScrFlag & 1) { /* Line 1285, Address: 0x101e754 */
    *pScrFlag &= 254; /* Line 1286, Address: 0x101e76c */
  } /* Line 1287, Address: 0x101e780 */
  else {
    *pScrFlag &= 254; /* Line 1289, Address: 0x101e788 */

    if (*pScrFlag & 2) { /* Line 1291, Address: 0x101e79c */
      *pScrFlag &= 253; /* Line 1292, Address: 0x101e7b4 */
      lD4.w.l = 224; /* Line 1293, Address: 0x101e7c8 */
    } /* Line 1294, Address: 0x101e7d0 */
    else {
      *pScrFlag &= 253; /* Line 1296, Address: 0x101e7d8 */
      goto label1; /* Line 1297, Address: 0x101e7ec */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1302, Address: 0x101e7f4 */
  wD0 &= 127; /* Line 1303, Address: 0x101e844 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1304, Address: 0x101e84c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1310, Address: 0x101e86c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1311, Address: 0x101e88c */
  if (wD0 != 0) { /* Line 1312, Address: 0x101e8b0 */
    wD5 = 65520; /* Line 1313, Address: 0x101e8bc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1314, Address: 0x101e8c4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1316, Address: 0x101e8e4 */



  } /* Line 1320, Address: 0x101e910 */
  else {

    wD5 = 0; /* Line 1323, Address: 0x101e918 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1324, Address: 0x101e91c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1328, Address: 0x101e93c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1335, Address: 0x101e968 */






    lD4.l = -16; /* Line 1342, Address: 0x101e97c */
    wD5 = 65520; /* Line 1343, Address: 0x101e984 */
    if (*pScrFlag & 168) { /* Line 1344, Address: 0x101e98c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1345, Address: 0x101e9a4 */
      wD5 = 320; /* Line 1346, Address: 0x101e9c4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1350, Address: 0x101e9cc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1352, Address: 0x101e9fc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1353, Address: 0x101ea08 */



    for (i = 0; i < 16; ++i) { /* Line 1357, Address: 0x101ea18 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1358, Address: 0x101ea24 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1360, Address: 0x101ea44 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1361, Address: 0x101ea7c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1362, Address: 0x101ea9c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1364, Address: 0x101eac0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1367, Address: 0x101eae4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1369, Address: 0x101eb04 */
      }
      lD4.w.l += 16; /* Line 1371, Address: 0x101eb18 */
    } /* Line 1372, Address: 0x101eb24 */
    *pScrFlag = 0; /* Line 1373, Address: 0x101eb34 */
  }
} /* Line 1375, Address: 0x101eb3c */





void scrollwrtc() {} /* Line 1381, Address: 0x101eb70 */




void scrollwrtz() {} /* Line 1386, Address: 0x101eb80 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1404, Address: 0x101eb90 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1417, Address: 0x101ebb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1420, Address: 0x101ebd8 */
    pTilePoint->x += 2; /* Line 1421, Address: 0x101ebec */
    if (pTilePoint->x >= 64) { /* Line 1422, Address: 0x101ec00 */
      pTilePoint->x -= 64; /* Line 1423, Address: 0x101ec14 */
    }
    xOffs += 16; /* Line 1425, Address: 0x101ec28 */
  } while (--lpcnt >= 0); /* Line 1426, Address: 0x101ec34 */
} /* Line 1427, Address: 0x101ec48 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1431, Address: 0x101ec60 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1435, Address: 0x101ec88 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1438, Address: 0x101eca8 */
    pTilePoint->x += 2; /* Line 1439, Address: 0x101ecbc */
    if (pTilePoint->x >= 64) { /* Line 1440, Address: 0x101ecd0 */
      pTilePoint->x -= 64; /* Line 1441, Address: 0x101ece4 */
    }
    xOffs += 16; /* Line 1443, Address: 0x101ecf8 */
  } while (--lpcnt >= 0); /* Line 1444, Address: 0x101ed04 */
} /* Line 1445, Address: 0x101ed18 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1465, Address: 0x101ed30 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1469, Address: 0x101ed58 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1472, Address: 0x101ed78 */
    pTilePoint->y += 2; /* Line 1473, Address: 0x101ed8c */
    if (pTilePoint->y >= 32) { /* Line 1474, Address: 0x101ed9c */
      pTilePoint->y -= 32; /* Line 1475, Address: 0x101edb0 */
    }
    yOffs += 16; /* Line 1477, Address: 0x101edc0 */
  } while (--lpcnt >= 0); /* Line 1478, Address: 0x101edcc */
} /* Line 1479, Address: 0x101ede0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1498, Address: 0x101edf0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1504, Address: 0x101ee24 */

    base = 1; /* Line 1506, Address: 0x101ee34 */
  } /* Line 1507, Address: 0x101ee38 */
  else if (VramBase == 16384) { /* Line 1508, Address: 0x101ee40 */

    base = 0; /* Line 1510, Address: 0x101ee50 */
  }
  x = pTilePoint->x; /* Line 1512, Address: 0x101ee54 */
  y = pTilePoint->y; /* Line 1513, Address: 0x101ee5c */


  frip = BlkIndex & 6144; /* Line 1516, Address: 0x101ee64 */
  BlkIndex &= 1023; /* Line 1517, Address: 0x101ee6c */
  if (frip == 6144) { /* Line 1518, Address: 0x101ee78 */

    p0 = 3, p1 = 2; /* Line 1520, Address: 0x101ee84 */
    p2 = 1, p3 = 0; /* Line 1521, Address: 0x101ee8c */
  } /* Line 1522, Address: 0x101ee94 */
  else if (frip & 4096) { /* Line 1523, Address: 0x101ee9c */

    p0 = 2, p1 = 3; /* Line 1525, Address: 0x101eea8 */
    p2 = 0, p3 = 1; /* Line 1526, Address: 0x101eeb0 */
  } /* Line 1527, Address: 0x101eeb8 */
  else if (frip & 2048) { /* Line 1528, Address: 0x101eec0 */

    p0 = 1, p1 = 0; /* Line 1530, Address: 0x101eecc */
    p2 = 3, p3 = 2; /* Line 1531, Address: 0x101eed4 */
  } /* Line 1532, Address: 0x101eedc */
  else {

    p0 = 0, p1 = 1; /* Line 1535, Address: 0x101eee4 */
    p2 = 2, p3 = 3; /* Line 1536, Address: 0x101eeec */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1539, Address: 0x101eef4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1540, Address: 0x101ef38 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1541, Address: 0x101ef7c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1542, Address: 0x101efc0 */

} /* Line 1544, Address: 0x101f004 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1562, Address: 0x101f040 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1563, Address: 0x101f060 */
} /* Line 1564, Address: 0x101f080 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1566, Address: 0x101f090 */
  wH_posiw = 0; /* Line 1567, Address: 0x101f0b0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1568, Address: 0x101f0b4 */
} /* Line 1569, Address: 0x101f0d4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1576, Address: 0x101f0f0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1582, Address: 0x101f120 */
  yOffs += wV_posiw; /* Line 1583, Address: 0x101f130 */





  if ((short)xOffs < 0) /* Line 1589, Address: 0x101f140 */
    xOffs = 0; /* Line 1590, Address: 0x101f15c */
  if ((short)yOffs < 0) /* Line 1591, Address: 0x101f160 */
    yOffs = 0; /* Line 1592, Address: 0x101f17c */
  if ((short)xOffs >= 16384) /* Line 1593, Address: 0x101f180 */
    xOffs = 16383; /* Line 1594, Address: 0x101f1a0 */
  if ((short)yOffs >= 2048) /* Line 1595, Address: 0x101f1a8 */
    yOffs = 2047; /* Line 1596, Address: 0x101f1c8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1597, Address: 0x101f1d0 */
  if (i < 0) i = 0; /* Line 1598, Address: 0x101f218 */

  ScreenNo = pMapWk[i] & 127; /* Line 1600, Address: 0x101f224 */

  if (ScreenNo) { /* Line 1602, Address: 0x101f240 */




    xOffs &= 32767; /* Line 1607, Address: 0x101f248 */
    yOffs &= 32767; /* Line 1608, Address: 0x101f254 */


    xBlk = xOffs; /* Line 1611, Address: 0x101f260 */
    xBlk %= 256; /* Line 1612, Address: 0x101f268 */
    xBlk /= 16; /* Line 1613, Address: 0x101f288 */
    yBlk = yOffs; /* Line 1614, Address: 0x101f2a4 */
    yBlk %= 256; /* Line 1615, Address: 0x101f2ac */
    yBlk /= 16; /* Line 1616, Address: 0x101f2cc */

    lpw = pmapwk; /* Line 1618, Address: 0x101f2e8 */
    lpw += xBlk; /* Line 1619, Address: 0x101f2f0 */
    lpw += yBlk * 16; /* Line 1620, Address: 0x101f2f8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1621, Address: 0x101f304 */
    *pIndex = *lpw; /* Line 1622, Address: 0x101f31c */

    return 1; /* Line 1624, Address: 0x101f32c */
  }

  *pIndex = 0; /* Line 1627, Address: 0x101f338 */
  return 0; /* Line 1628, Address: 0x101f340 */
} /* Line 1629, Address: 0x101f344 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1649, Address: 0x101f370 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1657, Address: 0x101f398 */
  if (ScreenNo) { /* Line 1658, Address: 0x101f3fc */





    xBlk = xOffs; /* Line 1664, Address: 0x101f404 */
    xBlk %= 256; /* Line 1665, Address: 0x101f40c */
    xBlk /= 16; /* Line 1666, Address: 0x101f42c */
    yBlk = yOffs; /* Line 1667, Address: 0x101f448 */
    yBlk %= 256; /* Line 1668, Address: 0x101f450 */
    yBlk /= 16; /* Line 1669, Address: 0x101f470 */


    lpw = pmapwk; /* Line 1672, Address: 0x101f48c */
    lpw += xBlk; /* Line 1673, Address: 0x101f494 */
    lpw += yBlk * 16; /* Line 1674, Address: 0x101f49c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1675, Address: 0x101f4a8 */
    *ppBlockNo = lpw; /* Line 1676, Address: 0x101f4c0 */
    *pIndex = *lpw; /* Line 1677, Address: 0x101f4c8 */




    return 1; /* Line 1682, Address: 0x101f4d8 */
  }

  *pIndex = 0; /* Line 1685, Address: 0x101f4e4 */
  return 0; /* Line 1686, Address: 0x101f4ec */
} /* Line 1687, Address: 0x101f4f0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1701, Address: 0x101f510 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1708, Address: 0x101f52c */
  pMapWk = (unsigned char*)mapwka; /* Line 1709, Address: 0x101f530 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1710, Address: 0x101f538 */
    *pBlockIndex = BlockNo; /* Line 1711, Address: 0x101f55c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1712, Address: 0x101f568 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1713, Address: 0x101f580 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1714, Address: 0x101f594 */
    }
  }


} /* Line 1719, Address: 0x101f5ac */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1733, Address: 0x101f5d0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1734, Address: 0x101f5dc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1735, Address: 0x101f608 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1736, Address: 0x101f654 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1737, Address: 0x101f680 */

          return 0; /* Line 1739, Address: 0x101f6cc */
        }
      }
    }
  }

  return 1; /* Line 1745, Address: 0x101f6d8 */
} /* Line 1746, Address: 0x101f6dc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1763, Address: 0x101f6f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1764, Address: 0x101f70c */

} /* Line 1766, Address: 0x101f728 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1768, Address: 0x101f740 */
  wH_posiw = 0; /* Line 1769, Address: 0x101f75c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1770, Address: 0x101f760 */

} /* Line 1772, Address: 0x101f77c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1774, Address: 0x101f790 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x101f7a4 */

} /* Line 1777, Address: 0x101f7c0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x101f7d0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x101f7ec */

} /* Line 1782, Address: 0x101f808 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x101f820 */
  xOffs += wH_posiw; /* Line 1785, Address: 0x101f838 */
  yOffs += wV_posiw; /* Line 1786, Address: 0x101f848 */
  yOffs &= 240; /* Line 1787, Address: 0x101f858 */
  xOffs &= 496; /* Line 1788, Address: 0x101f864 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1790, Address: 0x101f870 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1791, Address: 0x101f89c */


} /* Line 1794, Address: 0x101f8c8 */















void mapwrt() { /* Line 1810, Address: 0x101f8e0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1815, Address: 0x101f8f8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1816, Address: 0x101f904 */
  pMapWk = (unsigned char*)mapwka; /* Line 1817, Address: 0x101f910 */
  VramBase = 16384; /* Line 1818, Address: 0x101f918 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1819, Address: 0x101f91c */
  mapwrtb(); /* Line 1820, Address: 0x101f934 */
} /* Line 1821, Address: 0x101f93c */


void mapwrtb() { /* Line 1824, Address: 0x101f960 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1829, Address: 0x101f978 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1830, Address: 0x101f984 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1831, Address: 0x101f990 */
  VramBase = 24576; /* Line 1832, Address: 0x101f998 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1833, Address: 0x101f99c */

} /* Line 1835, Address: 0x101f9ac */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1838, Address: 0x101f9d0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1839, Address: 0x101f9e8 */
} /* Line 1840, Address: 0x101fa08 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1845, Address: 0x101fa20 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1849, Address: 0x101fa40 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1852, Address: 0x101fa5c */



    wD4 += 16; /* Line 1856, Address: 0x101fa84 */
  } while ((short)--wD6 >= 0); /* Line 1857, Address: 0x101fa90 */

} /* Line 1859, Address: 0x101fab8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1865, Address: 0x101fad0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1868, Address: 0x101faec */
  wD6 = 15; /* Line 1869, Address: 0x101faf4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1872, Address: 0x101fafc */

    mapwrt_sub(z81awrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1874, Address: 0x101fb20 */
    wD4 += 16; /* Line 1875, Address: 0x101fb40 */
  } while ((short)--wD6 >= 0); /* Line 1876, Address: 0x101fb48 */
} /* Line 1877, Address: 0x101fb6c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1903, Address: 0x101fb90 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1908, Address: 0x101fbb8 */
  wD0 = pWrttbl[wD0]; /* Line 1909, Address: 0x101fbc8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1911, Address: 0x101fbe4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1912, Address: 0x101fc08 */
  if (wD0) { /* Line 1913, Address: 0x101fc30 */
    wD5 = 65520; /* Line 1914, Address: 0x101fc3c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1915, Address: 0x101fc44 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1918, Address: 0x101fc60 */



  } /* Line 1922, Address: 0x101fc88 */
  else {

    wD5 = 0; /* Line 1925, Address: 0x101fc90 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1926, Address: 0x101fc94 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1930, Address: 0x101fcb0 */
  }





} /* Line 1937, Address: 0x101fcd8 */










void mapinit() { /* Line 1948, Address: 0x101fd00 */
  int i;
  int BmpNo, TileNo;

  TileNo = 592; /* Line 1952, Address: 0x101fd14 */
  i = 99; /* Line 1953, Address: 0x101fd18 */
  BmpNo = 95; /* Line 1954, Address: 0x101fd1c */
  for ( ; i > 0; --i) { /* Line 1955, Address: 0x101fd20 */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 1956, Address: 0x101fd28 */
  } /* Line 1957, Address: 0x101fd48 */


  colorset2(mapinittbl.colorno2); /* Line 1960, Address: 0x101fd54 */
  colorset(mapinittbl.colorno2); /* Line 1961, Address: 0x101fd68 */


  if (play_start & 2) divdevset(); /* Line 1964, Address: 0x101fd7c */
} /* Line 1965, Address: 0x101fd9c */




void mapset() {} /* Line 1970, Address: 0x101fdc0 */



void divdevset() {} /* Line 1974, Address: 0x101fdd0 */



void enecginit() {} /* Line 1978, Address: 0x101fde0 */
