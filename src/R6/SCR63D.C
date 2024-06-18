#include "..\EQU.H"
#include "SCR61A.H"
#include "..\ETC.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL6C.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z61aline(short** ppHscw);
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

static unsigned char z81awrttbl[49] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4
};
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
short scr_dir_tbl[6] = { 4, 0, 3479, 0, 1808, 96 };
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
short playpositbl[1][2] = { { 48, 1580 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;








































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x102e0e0 */
    return &actwk[0]; /* Line 147, Address: 0x102e0f4 */
  else
    return &actwk[1]; /* Line 149, Address: 0x102e104 */

} /* Line 151, Address: 0x102e10c */





































void scr_set() { /* Line 189, Address: 0x102e120 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x102e12c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x102e140 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x102e154 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x102e15c */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x102e164 */
  ++pScrTbl; /* Line 198, Address: 0x102e170 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x102e174 */
  ++pScrTbl; /* Line 200, Address: 0x102e188 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x102e18c */
  ++pScrTbl; /* Line 202, Address: 0x102e1a0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x102e1a4 */
  ++pScrTbl; /* Line 204, Address: 0x102e1b8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x102e1bc */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x102e1d0 */
  ++pScrTbl; /* Line 207, Address: 0x102e1f0 */
  scra_h_count = 16; /* Line 208, Address: 0x102e1f4 */
  scra_v_count = 16; /* Line 209, Address: 0x102e200 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102e20c */
  scra_hline = 160; /* Line 212, Address: 0x102e218 */

  playposiset(); /* Line 214, Address: 0x102e224 */
} /* Line 215, Address: 0x102e22c */
















































static void playposiset() { /* Line 264, Address: 0x102e240 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x102e254 */
    playload(); /* Line 268, Address: 0x102e264 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x102e26c */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x102e27c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x102e294 */
    } else { /* Line 273, Address: 0x102e2a4 */
      ywk = 0; /* Line 274, Address: 0x102e2ac */
    }
  } /* Line 276, Address: 0x102e2b0 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x102e2b8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x102e2d8 */
    } /* Line 280, Address: 0x102e2fc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x102e304 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x102e324 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x102e338 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x102e34c */
    xwk -= 160; /* Line 292, Address: 0x102e360 */
  } else { /* Line 293, Address: 0x102e36c */
    xwk = 0; /* Line 294, Address: 0x102e374 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x102e378 */
    xwk = scralim_right; /* Line 299, Address: 0x102e39c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x102e3ac */

  if (ywk > 96) { /* Line 305, Address: 0x102e3b4 */
    ywk -= 96; /* Line 306, Address: 0x102e3c8 */
  } else { /* Line 307, Address: 0x102e3d4 */
    ywk = 0; /* Line 308, Address: 0x102e3dc */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x102e3e0 */
    ywk = scralim_down; /* Line 313, Address: 0x102e404 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x102e414 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102e41c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102e42c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102e43c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102e44c */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102e45c */
} /* Line 326, Address: 0x102e46c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x102e490 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102e49c */
  lYwk.w.l = 0; /* Line 351, Address: 0x102e4a4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x102e4a8 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x102e4b4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x102e4c0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102e4cc */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x102e4d8 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x102e4f4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x102e500 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102e51c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x102e528 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x102e544 */
} /* Line 366, Address: 0x102e568 */















void scroll() { /* Line 382, Address: 0x102e580 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x102e59c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x102e5ac */

  scrchk(); /* Line 401, Address: 0x102e5d8 */

  scroll_h(); /* Line 403, Address: 0x102e5e0 */
  scroll_v(); /* Line 404, Address: 0x102e5e8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x102e5f0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x102e600 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x102e610 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x102e624 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x102e634 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x102e648 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x102e658 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x102e674 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x102e684 */


  scrollb_v(lYwk); /* Line 422, Address: 0x102e698 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x102e6a8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x102e6d0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x102e708 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102e71c */

  z61aline(&psHscw); /* Line 431, Address: 0x102e728 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 433, Address: 0x102e734 */
  for (i = 0; i < 24; ++i) { /* Line 434, Address: 0x102e754 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x102e760 */
  } /* Line 437, Address: 0x102e774 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x102e784 */
  for (i = 0; i < 46; ++i) { /* Line 440, Address: 0x102e7a4 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x102e7b0 */
  } /* Line 443, Address: 0x102e7c4 */

  pHscrbuf = lphscrollbuff; /* Line 445, Address: 0x102e7d4 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 446, Address: 0x102e7e0 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 447, Address: 0x102e810 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 448, Address: 0x102e840 */
} /* Line 449, Address: 0x102e85c */













void z61aline(short** ppHscw) { /* Line 463, Address: 0x102e880 */
  char z81ascrtbl[9] = { /* Line 464, Address: 0x102e8a4 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk;


  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 472, Address: 0x102e8d0 */
  radwk = 0; /* Line 473, Address: 0x102e8f4 */
  sXwk = scrb_h_posit.w.h; /* Line 474, Address: 0x102e8f8 */

  *ppHscw += 26; /* Line 476, Address: 0x102e908 */

  for (i = 8; i >= 0; --i) { /* Line 478, Address: 0x102e91c */

    sinset(radwk, &sinwk, &coswk); /* Line 480, Address: 0x102e928 */
    hwk = -(sXwk + (short)((unsigned short)((256 - coswk) * lXwk) >> 8)); /* Line 481, Address: 0x102e93c */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 482, Address: 0x102e990 */

      --*ppHscw; /* Line 484, Address: 0x102e9a8 */
      **ppHscw = hwk; /* Line 485, Address: 0x102e9bc */
    } /* Line 486, Address: 0x102e9c8 */

    radwk += 6; /* Line 488, Address: 0x102e9d4 */
  } /* Line 489, Address: 0x102e9e0 */

  *ppHscw += 26; /* Line 491, Address: 0x102e9ec */
} /* Line 492, Address: 0x102ea00 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 513, Address: 0x102ea30 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 517, Address: 0x102ea4c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 518, Address: 0x102ea50 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 520, Address: 0x102ea70 */
    ldwk.w.l = *pHscrwk; /* Line 521, Address: 0x102ea8c */
    ++pHscrwk; /* Line 522, Address: 0x102ea98 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 524, Address: 0x102eaa4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 525, Address: 0x102eaac */
    } /* Line 526, Address: 0x102eabc */
  } /* Line 527, Address: 0x102eae0 */
} /* Line 528, Address: 0x102eb00 */









































































































static void scrollb_v(short yPos) { /* Line 634, Address: 0x102eb20 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 637, Address: 0x102eb30 */
  scrb_v_posit.w.h = yPos; /* Line 638, Address: 0x102eb40 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 639, Address: 0x102eb4c */

  if (!ywk) { /* Line 641, Address: 0x102eb84 */
    scrb_v_count ^= 16; /* Line 642, Address: 0x102eb8c */
    if (yPos - ysv < 0) { /* Line 643, Address: 0x102eba0 */
      scrflagb.b.h |= 1; /* Line 644, Address: 0x102ebc0 */
    } /* Line 645, Address: 0x102ebd4 */
    else {
      scrflagb.b.h |= 2; /* Line 647, Address: 0x102ebdc */
    }
  }


} /* Line 652, Address: 0x102ebf0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 670, Address: 0x102ec10 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 674, Address: 0x102ec24 */
  lXwk = lXsv + xoffs; /* Line 675, Address: 0x102ec2c */
  scrb_h_posit.l = lXwk; /* Line 676, Address: 0x102ec34 */
  ldXwk.l = lXwk; /* Line 677, Address: 0x102ec3c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 678, Address: 0x102ec40 */
  ldXwk.w.l &= 16; /* Line 679, Address: 0x102ec64 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 680, Address: 0x102ec70 */

  if (!ldXwk.b.b4) { /* Line 682, Address: 0x102ec8c */
    scrb_h_count ^= 16; /* Line 683, Address: 0x102ec98 */
    if (lXwk - lXsv < 0) { /* Line 684, Address: 0x102ecac */
      scrflagb.b.h |= 1 << flgbit; /* Line 685, Address: 0x102ecb8 */
    } /* Line 686, Address: 0x102ecdc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 688, Address: 0x102ece4 */
    }
  }


} /* Line 693, Address: 0x102ed0c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 711, Address: 0x102ed20 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 715, Address: 0x102ed34 */
  lXwk = lXsv + xoffs; /* Line 716, Address: 0x102ed3c */
  scrc_h_posit.l = lXwk; /* Line 717, Address: 0x102ed44 */
  ldXwk.l = lXwk; /* Line 718, Address: 0x102ed4c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 719, Address: 0x102ed50 */
  ldXwk.w.l &= 16; /* Line 720, Address: 0x102ed74 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 721, Address: 0x102ed80 */

  if (!ldXwk.b.b4) { /* Line 723, Address: 0x102ed9c */
    scrc_h_count ^= 16; /* Line 724, Address: 0x102eda8 */
    if (lXwk - lXsv < 0) { /* Line 725, Address: 0x102edbc */
      scrflagc.b.h |= 1 << flgbit; /* Line 726, Address: 0x102edc8 */
    } /* Line 727, Address: 0x102edec */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 729, Address: 0x102edf4 */
    }
  }


} /* Line 734, Address: 0x102ee1c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 752, Address: 0x102ee30 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 756, Address: 0x102ee44 */
  lXwk = lXsv + xoffs; /* Line 757, Address: 0x102ee4c */
  scrz_h_posit.l = lXwk; /* Line 758, Address: 0x102ee54 */
  ldXwk.l = lXwk; /* Line 759, Address: 0x102ee5c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 760, Address: 0x102ee60 */
  ldXwk.w.l &= 16; /* Line 761, Address: 0x102ee84 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 762, Address: 0x102ee90 */

  if (!ldXwk.b.b4) { /* Line 764, Address: 0x102eeac */
    scrz_h_count ^= 16; /* Line 765, Address: 0x102eeb8 */
    if (lXwk - lXsv < 0) { /* Line 766, Address: 0x102eecc */
      scrflagz.b.h |= 1 << flgbit; /* Line 767, Address: 0x102eed8 */
    } /* Line 768, Address: 0x102eefc */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 770, Address: 0x102ef04 */
    }
  }


} /* Line 775, Address: 0x102ef2c */














static void scroll_h() { /* Line 790, Address: 0x102ef40 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 794, Address: 0x102ef50 */

  scrh_move(); /* Line 796, Address: 0x102ef60 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 797, Address: 0x102ef68 */
  if (!bXwk) { /* Line 798, Address: 0x102ef9c */
    scra_h_count ^= 16; /* Line 799, Address: 0x102efa4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 800, Address: 0x102efb8 */
      scrflaga.b.h |= 4; /* Line 801, Address: 0x102efdc */
    } else { /* Line 802, Address: 0x102eff0 */
      scrflaga.b.h |= 8; /* Line 803, Address: 0x102eff8 */
    }
  }


} /* Line 808, Address: 0x102f00c */
















static void scrh_move() { /* Line 825, Address: 0x102f030 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 828, Address: 0x102f038 */
  if (xwk == 0) { /* Line 829, Address: 0x102f080 */

    scra_hz = 0; /* Line 831, Address: 0x102f090 */
    return; /* Line 832, Address: 0x102f098 */
  } else if (xwk < 0) { /* Line 833, Address: 0x102f0a0 */

    if (xwk < -16) { /* Line 835, Address: 0x102f0b0 */
      xwk = -16; /* Line 836, Address: 0x102f0c4 */
    }


    xwk += scra_h_posit.w.h; /* Line 840, Address: 0x102f0d0 */
    if (xwk < scralim_left) { /* Line 841, Address: 0x102f0e4 */
      xwk = scralim_left; /* Line 842, Address: 0x102f108 */
    }
  } /* Line 844, Address: 0x102f118 */
  else {
    if (xwk > 16) { /* Line 846, Address: 0x102f120 */
      xwk = 16; /* Line 847, Address: 0x102f134 */
    }


    xwk += scra_h_posit.w.h; /* Line 851, Address: 0x102f140 */
    if (xwk > scralim_right) { /* Line 852, Address: 0x102f154 */
      xwk = scralim_right; /* Line 853, Address: 0x102f178 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 858, Address: 0x102f188 */
  scra_h_posit.w.h = xwk; /* Line 859, Address: 0x102f1b8 */
} /* Line 860, Address: 0x102f1c0 */














static void scroll_v() { /* Line 875, Address: 0x102f1d0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 878, Address: 0x102f1dc */
  if (actwk[0].cddat & 4) { /* Line 879, Address: 0x102f210 */
    ywk -= 5; /* Line 880, Address: 0x102f228 */
  }


  if (actwk[0].cddat & 2) { /* Line 884, Address: 0x102f234 */
    ywk += 32; /* Line 885, Address: 0x102f24c */
    if (ywk < scra_vline) { /* Line 886, Address: 0x102f258 */
      ywk -= scra_vline; /* Line 887, Address: 0x102f27c */
      sv_move_main2(ywk); /* Line 888, Address: 0x102f290 */
      return; /* Line 889, Address: 0x102f29c */
    } else if (ywk >= scra_vline + 64) { /* Line 890, Address: 0x102f2a4 */
      ywk -= scra_vline + 64; /* Line 891, Address: 0x102f2cc */
      sv_move_main2(ywk); /* Line 892, Address: 0x102f2f4 */
      return; /* Line 893, Address: 0x102f300 */
    }
    ywk -= scra_vline + 64; /* Line 895, Address: 0x102f308 */
    if (!limmoveflag) goto label1; /* Line 896, Address: 0x102f330 */
    sv_move_sub2(); /* Line 897, Address: 0x102f340 */
    return; /* Line 898, Address: 0x102f348 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 903, Address: 0x102f350 */
    sv_move_main(ywk); /* Line 904, Address: 0x102f37c */
    return; /* Line 905, Address: 0x102f388 */
  } else if (!limmoveflag) goto label1; /* Line 906, Address: 0x102f390 */
  sv_move_sub2(); /* Line 907, Address: 0x102f3a0 */
  return; /* Line 908, Address: 0x102f3a8 */



label1:
  scra_vz = 0; /* Line 913, Address: 0x102f3b0 */
} /* Line 914, Address: 0x102f3b8 */













static void sv_move_main(short yPos) { /* Line 928, Address: 0x102f3d0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 931, Address: 0x102f3e0 */
    if (actwk[0].mspeed.w < 0) { /* Line 932, Address: 0x102f3fc */
      spdwk = -actwk[0].mspeed.w; /* Line 933, Address: 0x102f414 */
    } else { /* Line 934, Address: 0x102f438 */
      spdwk = actwk[0].mspeed.w; /* Line 935, Address: 0x102f440 */
    }


    if (spdwk >= 2048) { /* Line 939, Address: 0x102f450 */
      sv_move_main2(yPos); /* Line 940, Address: 0x102f464 */
    } /* Line 941, Address: 0x102f470 */
    else {

      if (yPos > 6) { /* Line 944, Address: 0x102f478 */
        sv_move_plus(1536); /* Line 945, Address: 0x102f490 */
      } else if (yPos < -6) { /* Line 946, Address: 0x102f49c */
        sv_move_minus(1536); /* Line 947, Address: 0x102f4bc */
      } /* Line 948, Address: 0x102f4c8 */
      else sv_move_sub(yPos); /* Line 949, Address: 0x102f4d0 */
    }
  } /* Line 951, Address: 0x102f4dc */
  else {
    if (yPos > 2) { /* Line 953, Address: 0x102f4e4 */
      sv_move_plus(512); /* Line 954, Address: 0x102f4fc */
    } else if (yPos < -2) { /* Line 955, Address: 0x102f508 */
      sv_move_minus(512); /* Line 956, Address: 0x102f528 */
    } /* Line 957, Address: 0x102f534 */
    else sv_move_sub(yPos); /* Line 958, Address: 0x102f53c */
  }

} /* Line 961, Address: 0x102f548 */













static void sv_move_main2(short yPos) { /* Line 975, Address: 0x102f560 */
  short spdwk;

  spdwk = 4096; /* Line 978, Address: 0x102f570 */

  if (yPos > 16) { /* Line 980, Address: 0x102f57c */
    sv_move_plus(spdwk); /* Line 981, Address: 0x102f594 */
  } else if (yPos < -16) { /* Line 982, Address: 0x102f5a0 */
    sv_move_minus(spdwk); /* Line 983, Address: 0x102f5c0 */
  } else { /* Line 984, Address: 0x102f5cc */
    sv_move_sub(yPos); /* Line 985, Address: 0x102f5d4 */
  }
} /* Line 987, Address: 0x102f5e0 */














static void sv_move_sub(short yPos) { /* Line 1002, Address: 0x102f600 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1005, Address: 0x102f60c */
  if (yPos < 0) { /* Line 1006, Address: 0x102f638 */
    scrv_up_ch(lSpd); /* Line 1007, Address: 0x102f64c */
  } else { /* Line 1008, Address: 0x102f658 */
    scrv_down_ch(lSpd); /* Line 1009, Address: 0x102f660 */
  }
} /* Line 1011, Address: 0x102f66c */



static void sv_move_sub2() { /* Line 1015, Address: 0x102f680 */
  limmoveflag = 0; /* Line 1016, Address: 0x102f688 */

  sv_move_sub(0); /* Line 1018, Address: 0x102f690 */
} /* Line 1019, Address: 0x102f69c */













static void sv_move_minus(short speed) { /* Line 1033, Address: 0x102f6b0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1036, Address: 0x102f6bc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1037, Address: 0x102f6e0 */
  scrv_up_ch(lSpd); /* Line 1038, Address: 0x102f704 */
} /* Line 1039, Address: 0x102f710 */














static void scrv_up_ch(int_union lSpd) { /* Line 1054, Address: 0x102f720 */
  if (lSpd.w.l <= scralim_up) { /* Line 1055, Address: 0x102f72c */
    if (lSpd.w.l > -256) { /* Line 1056, Address: 0x102f754 */

      lSpd.w.l = scralim_up; /* Line 1058, Address: 0x102f76c */
    } else { /* Line 1059, Address: 0x102f778 */
      lSpd.w.l &= 2047; /* Line 1060, Address: 0x102f780 */
      actwk[0].yposi.w.l &= 2047; /* Line 1061, Address: 0x102f78c */
      scra_v_posit.w.h &= 2047; /* Line 1062, Address: 0x102f7a0 */
      scrb_v_posit.w.h &= 1023; /* Line 1063, Address: 0x102f7b4 */
    }
  }

  scrv_move(lSpd); /* Line 1067, Address: 0x102f7c8 */
} /* Line 1068, Address: 0x102f7d4 */













static void sv_move_plus(short sSpd) { /* Line 1082, Address: 0x102f7f0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1085, Address: 0x102f7fc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1086, Address: 0x102f81c */
  scrv_down_ch(lSpd); /* Line 1087, Address: 0x102f840 */
} /* Line 1088, Address: 0x102f84c */














static void scrv_down_ch(int_union lSpd) { /* Line 1103, Address: 0x102f860 */
  if (lSpd.w.l >= scralim_down) { /* Line 1104, Address: 0x102f86c */
    if (lSpd.w.l < 2048) { /* Line 1105, Address: 0x102f894 */

      lSpd.w.l = scralim_down; /* Line 1107, Address: 0x102f8ac */
    } else { /* Line 1108, Address: 0x102f8b8 */
      lSpd.w.l -= 2048; /* Line 1109, Address: 0x102f8c0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1110, Address: 0x102f8cc */
      scra_v_posit.w.h -= 2048; /* Line 1111, Address: 0x102f8e0 */
      scrb_v_posit.w.h &= 1023; /* Line 1112, Address: 0x102f8f4 */
    }
  }

  scrv_move(lSpd); /* Line 1116, Address: 0x102f908 */
} /* Line 1117, Address: 0x102f914 */
















static void scrv_move(int_union lSpd) { /* Line 1134, Address: 0x102f930 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1138, Address: 0x102f940 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1139, Address: 0x102f950 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1140, Address: 0x102f974 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1141, Address: 0x102f988 */
  scra_vz = spdwk.w.l; /* Line 1142, Address: 0x102f9a0 */

  scra_v_posit.l = lSpd.l; /* Line 1144, Address: 0x102f9ac */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1146, Address: 0x102f9b8 */
  if (!ywk) { /* Line 1147, Address: 0x102f9f4 */
    scra_v_count ^= 16; /* Line 1148, Address: 0x102f9fc */
    ywk = scra_v_posit.w.h - ysv; /* Line 1149, Address: 0x102fa10 */
    if (ywk < 0) { /* Line 1150, Address: 0x102fa3c */
      scrflaga.b.h |= 1; /* Line 1151, Address: 0x102fa4c */
    } else { /* Line 1152, Address: 0x102fa60 */
      scrflaga.b.h |= 2; /* Line 1153, Address: 0x102fa68 */
    }
  }


} /* Line 1158, Address: 0x102fa7c */

















void scrollwrt() { /* Line 1176, Address: 0x102fa90 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1185, Address: 0x102fab0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1186, Address: 0x102fab4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1187, Address: 0x102fac0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1188, Address: 0x102facc */
  pScrFlag = &scrflagbw.b.h; /* Line 1189, Address: 0x102fad4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1190, Address: 0x102fadc */

  VramBase = 16384; /* Line 1192, Address: 0x102faf0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1193, Address: 0x102faf4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1194, Address: 0x102fb00 */
  pMapWk = (unsigned char*)mapwka; /* Line 1195, Address: 0x102fb0c */
  pScrFlag = &scrflagaw.b.h; /* Line 1196, Address: 0x102fb14 */

  if (*pScrFlag) { /* Line 1198, Address: 0x102fb1c */
    if (*pScrFlag & 1) { /* Line 1199, Address: 0x102fb28 */
      *pScrFlag &= 254; /* Line 1200, Address: 0x102fb3c */

      lD4.l = -16; /* Line 1202, Address: 0x102fb48 */
      wD5 = 65520; /* Line 1203, Address: 0x102fb50 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1205, Address: 0x102fb58 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1207, Address: 0x102fb78 */
    }




    if (*pScrFlag & 2) { /* Line 1213, Address: 0x102fba4 */
      *pScrFlag &= 253; /* Line 1214, Address: 0x102fbb8 */

      lD4.l = 224; /* Line 1216, Address: 0x102fbc4 */
      wD5 = 65520; /* Line 1217, Address: 0x102fbcc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1218, Address: 0x102fbd4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1220, Address: 0x102fbf4 */
    }




    if (*pScrFlag & 4) { /* Line 1226, Address: 0x102fc20 */
      *pScrFlag &= 251; /* Line 1227, Address: 0x102fc34 */

      lD4.l = -16; /* Line 1229, Address: 0x102fc40 */
      wD5 = 65520; /* Line 1230, Address: 0x102fc48 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1231, Address: 0x102fc50 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1233, Address: 0x102fc70 */
    }




    if (*pScrFlag & 8) { /* Line 1239, Address: 0x102fc9c */
      *pScrFlag &= 247; /* Line 1240, Address: 0x102fcb0 */

      lD4.l = -16; /* Line 1242, Address: 0x102fcbc */
      wD5 = 320; /* Line 1243, Address: 0x102fcc4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x102fccc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1246, Address: 0x102fcec */
    }
  }






} /* Line 1255, Address: 0x102fd18 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1272, Address: 0x102fd40 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1283, Address: 0x102fd6c */

  if (*pScrFlag & 1) { /* Line 1285, Address: 0x102fd74 */
    *pScrFlag &= 254; /* Line 1286, Address: 0x102fd8c */
  } /* Line 1287, Address: 0x102fda0 */
  else {
    *pScrFlag &= 254; /* Line 1289, Address: 0x102fda8 */

    if (*pScrFlag & 2) { /* Line 1291, Address: 0x102fdbc */
      *pScrFlag &= 253; /* Line 1292, Address: 0x102fdd4 */
      lD4.w.l = 224; /* Line 1293, Address: 0x102fde8 */
    } /* Line 1294, Address: 0x102fdf0 */
    else {
      *pScrFlag &= 253; /* Line 1296, Address: 0x102fdf8 */
      goto label1; /* Line 1297, Address: 0x102fe0c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1302, Address: 0x102fe14 */
  wD0 &= 127; /* Line 1303, Address: 0x102fe64 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1304, Address: 0x102fe6c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1310, Address: 0x102fe8c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1311, Address: 0x102feac */
  if (wD0 != 0) { /* Line 1312, Address: 0x102fed0 */
    wD5 = 65520; /* Line 1313, Address: 0x102fedc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1314, Address: 0x102fee4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1316, Address: 0x102ff04 */



  } /* Line 1320, Address: 0x102ff30 */
  else {

    wD5 = 0; /* Line 1323, Address: 0x102ff38 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1324, Address: 0x102ff3c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1328, Address: 0x102ff5c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1335, Address: 0x102ff88 */






    lD4.l = -16; /* Line 1342, Address: 0x102ff9c */
    wD5 = 65520; /* Line 1343, Address: 0x102ffa4 */
    if (*pScrFlag & 168) { /* Line 1344, Address: 0x102ffac */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1345, Address: 0x102ffc4 */
      wD5 = 320; /* Line 1346, Address: 0x102ffe4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1350, Address: 0x102ffec */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1352, Address: 0x103001c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1353, Address: 0x1030028 */



    for (i = 0; i < 16; ++i) { /* Line 1357, Address: 0x1030038 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1358, Address: 0x1030044 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1359, Address: 0x1030064 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1360, Address: 0x103009c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1361, Address: 0x10300bc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1363, Address: 0x10300e0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1366, Address: 0x1030104 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1368, Address: 0x1030124 */
      }
      lD4.w.l += 16; /* Line 1370, Address: 0x1030138 */
    } /* Line 1371, Address: 0x1030144 */
    *pScrFlag = 0; /* Line 1372, Address: 0x1030154 */
  }
} /* Line 1374, Address: 0x103015c */





void scrollwrtc() {} /* Line 1380, Address: 0x1030190 */




void scrollwrtz() {} /* Line 1385, Address: 0x10301a0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1403, Address: 0x10301b0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1416, Address: 0x10301d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1419, Address: 0x10301f8 */
    pTilePoint->x += 2; /* Line 1420, Address: 0x103020c */
    if (pTilePoint->x >= 64) { /* Line 1421, Address: 0x1030220 */
      pTilePoint->x -= 64; /* Line 1422, Address: 0x1030234 */
    }
    xOffs += 16; /* Line 1424, Address: 0x1030248 */
  } while (--lpcnt >= 0); /* Line 1425, Address: 0x1030254 */
} /* Line 1426, Address: 0x1030268 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1430, Address: 0x1030280 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1434, Address: 0x10302a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1437, Address: 0x10302c8 */
    pTilePoint->x += 2; /* Line 1438, Address: 0x10302dc */
    if (pTilePoint->x >= 64) { /* Line 1439, Address: 0x10302f0 */
      pTilePoint->x -= 64; /* Line 1440, Address: 0x1030304 */
    }
    xOffs += 16; /* Line 1442, Address: 0x1030318 */
  } while (--lpcnt >= 0); /* Line 1443, Address: 0x1030324 */
} /* Line 1444, Address: 0x1030338 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1464, Address: 0x1030350 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1468, Address: 0x1030378 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1471, Address: 0x1030398 */
    pTilePoint->y += 2; /* Line 1472, Address: 0x10303ac */
    if (pTilePoint->y >= 32) { /* Line 1473, Address: 0x10303bc */
      pTilePoint->y -= 32; /* Line 1474, Address: 0x10303d0 */
    }
    yOffs += 16; /* Line 1476, Address: 0x10303e0 */
  } while (--lpcnt >= 0); /* Line 1477, Address: 0x10303ec */
} /* Line 1478, Address: 0x1030400 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1497, Address: 0x1030410 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1503, Address: 0x1030444 */

    base = 1; /* Line 1505, Address: 0x1030454 */
  } /* Line 1506, Address: 0x1030458 */
  else if (VramBase == 16384) { /* Line 1507, Address: 0x1030460 */

    base = 0; /* Line 1509, Address: 0x1030470 */
  }
  x = pTilePoint->x; /* Line 1511, Address: 0x1030474 */
  y = pTilePoint->y; /* Line 1512, Address: 0x103047c */


  frip = BlkIndex & 6144; /* Line 1515, Address: 0x1030484 */
  BlkIndex &= 1023; /* Line 1516, Address: 0x103048c */
  if (frip == 6144) { /* Line 1517, Address: 0x1030498 */

    p0 = 3, p1 = 2; /* Line 1519, Address: 0x10304a4 */
    p2 = 1, p3 = 0; /* Line 1520, Address: 0x10304ac */
  } /* Line 1521, Address: 0x10304b4 */
  else if (frip & 4096) { /* Line 1522, Address: 0x10304bc */

    p0 = 2, p1 = 3; /* Line 1524, Address: 0x10304c8 */
    p2 = 0, p3 = 1; /* Line 1525, Address: 0x10304d0 */
  } /* Line 1526, Address: 0x10304d8 */
  else if (frip & 2048) { /* Line 1527, Address: 0x10304e0 */

    p0 = 1, p1 = 0; /* Line 1529, Address: 0x10304ec */
    p2 = 3, p3 = 2; /* Line 1530, Address: 0x10304f4 */
  } /* Line 1531, Address: 0x10304fc */
  else {

    p0 = 0, p1 = 1; /* Line 1534, Address: 0x1030504 */
    p2 = 2, p3 = 3; /* Line 1535, Address: 0x103050c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1538, Address: 0x1030514 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1539, Address: 0x1030558 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1540, Address: 0x103059c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1541, Address: 0x10305e0 */

} /* Line 1543, Address: 0x1030624 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1561, Address: 0x1030660 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1562, Address: 0x1030680 */
} /* Line 1563, Address: 0x10306a0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1565, Address: 0x10306b0 */
  wH_posiw = 0; /* Line 1566, Address: 0x10306d0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1567, Address: 0x10306d4 */
} /* Line 1568, Address: 0x10306f4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1575, Address: 0x1030710 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1581, Address: 0x1030740 */
  yOffs += wV_posiw; /* Line 1582, Address: 0x1030750 */





  if ((short)xOffs < 0) /* Line 1588, Address: 0x1030760 */
    xOffs = 0; /* Line 1589, Address: 0x103077c */
  if ((short)yOffs < 0) /* Line 1590, Address: 0x1030780 */
    yOffs = 0; /* Line 1591, Address: 0x103079c */
  if ((short)xOffs >= 16384) /* Line 1592, Address: 0x10307a0 */
    xOffs = 16383; /* Line 1593, Address: 0x10307c0 */
  if ((short)yOffs >= 2048) /* Line 1594, Address: 0x10307c8 */
    yOffs = 2047; /* Line 1595, Address: 0x10307e8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1596, Address: 0x10307f0 */
  if (i < 0) i = 0; /* Line 1597, Address: 0x1030838 */

  ScreenNo = pMapWk[i] & 127; /* Line 1599, Address: 0x1030844 */

  if (ScreenNo) { /* Line 1601, Address: 0x1030860 */




    xOffs &= 32767; /* Line 1606, Address: 0x1030868 */
    yOffs &= 32767; /* Line 1607, Address: 0x1030874 */


    xBlk = xOffs; /* Line 1610, Address: 0x1030880 */
    xBlk %= 256; /* Line 1611, Address: 0x1030888 */
    xBlk /= 16; /* Line 1612, Address: 0x10308a8 */
    yBlk = yOffs; /* Line 1613, Address: 0x10308c4 */
    yBlk %= 256; /* Line 1614, Address: 0x10308cc */
    yBlk /= 16; /* Line 1615, Address: 0x10308ec */

    lpw = pmapwk; /* Line 1617, Address: 0x1030908 */
    lpw += xBlk; /* Line 1618, Address: 0x1030910 */
    lpw += yBlk * 16; /* Line 1619, Address: 0x1030918 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1620, Address: 0x1030924 */
    *pIndex = *lpw; /* Line 1621, Address: 0x103093c */

    return 1; /* Line 1623, Address: 0x103094c */
  }

  *pIndex = 0; /* Line 1626, Address: 0x1030958 */
  return 0; /* Line 1627, Address: 0x1030960 */
} /* Line 1628, Address: 0x1030964 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1648, Address: 0x1030990 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1656, Address: 0x10309b8 */
  if (ScreenNo) { /* Line 1657, Address: 0x1030a1c */





    xBlk = xOffs; /* Line 1663, Address: 0x1030a24 */
    xBlk %= 256; /* Line 1664, Address: 0x1030a2c */
    xBlk /= 16; /* Line 1665, Address: 0x1030a4c */
    yBlk = yOffs; /* Line 1666, Address: 0x1030a68 */
    yBlk %= 256; /* Line 1667, Address: 0x1030a70 */
    yBlk /= 16; /* Line 1668, Address: 0x1030a90 */


    lpw = pmapwk; /* Line 1671, Address: 0x1030aac */
    lpw += xBlk; /* Line 1672, Address: 0x1030ab4 */
    lpw += yBlk * 16; /* Line 1673, Address: 0x1030abc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1674, Address: 0x1030ac8 */
    *ppBlockNo = lpw; /* Line 1675, Address: 0x1030ae0 */
    *pIndex = *lpw; /* Line 1676, Address: 0x1030ae8 */




    return 1; /* Line 1681, Address: 0x1030af8 */
  }

  *pIndex = 0; /* Line 1684, Address: 0x1030b04 */
  return 0; /* Line 1685, Address: 0x1030b0c */
} /* Line 1686, Address: 0x1030b10 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1700, Address: 0x1030b30 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1707, Address: 0x1030b4c */
  pMapWk = (unsigned char*)mapwka; /* Line 1708, Address: 0x1030b50 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1709, Address: 0x1030b58 */
    *pBlockIndex = BlockNo; /* Line 1710, Address: 0x1030b7c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1711, Address: 0x1030b88 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1712, Address: 0x1030ba0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1713, Address: 0x1030bb4 */
    }
  }


} /* Line 1718, Address: 0x1030bcc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1732, Address: 0x1030bf0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1733, Address: 0x1030bfc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1734, Address: 0x1030c28 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1735, Address: 0x1030c74 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1736, Address: 0x1030ca0 */

          return 0; /* Line 1738, Address: 0x1030cec */
        }
      }
    }
  }

  return 1; /* Line 1744, Address: 0x1030cf8 */
} /* Line 1745, Address: 0x1030cfc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1762, Address: 0x1030d10 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1763, Address: 0x1030d2c */

} /* Line 1765, Address: 0x1030d48 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1767, Address: 0x1030d60 */
  wH_posiw = 0; /* Line 1768, Address: 0x1030d7c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1769, Address: 0x1030d80 */

} /* Line 1771, Address: 0x1030d9c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1773, Address: 0x1030db0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1774, Address: 0x1030dc4 */

} /* Line 1776, Address: 0x1030de0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1778, Address: 0x1030df0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1779, Address: 0x1030e0c */

} /* Line 1781, Address: 0x1030e28 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1783, Address: 0x1030e40 */
  xOffs += wH_posiw; /* Line 1784, Address: 0x1030e58 */
  yOffs += wV_posiw; /* Line 1785, Address: 0x1030e68 */
  yOffs &= 240; /* Line 1786, Address: 0x1030e78 */
  xOffs &= 496; /* Line 1787, Address: 0x1030e84 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1789, Address: 0x1030e90 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1790, Address: 0x1030ebc */


} /* Line 1793, Address: 0x1030ee8 */















void mapwrt() { /* Line 1809, Address: 0x1030f00 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1816, Address: 0x1030f18 */
  wV_posiw = scra_v_posit.w.h; /* Line 1817, Address: 0x1030f24 */
  pMapWk = (unsigned char*)mapwka; /* Line 1818, Address: 0x1030f30 */
  VramBase = 16384; /* Line 1819, Address: 0x1030f38 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1820, Address: 0x1030f3c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1824, Address: 0x1030f54 */
  VramBase = 24576; /* Line 1825, Address: 0x1030f5c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1826, Address: 0x1030f60 */

} /* Line 1828, Address: 0x1030f70 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1831, Address: 0x1030f90 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1832, Address: 0x1030fa8 */
} /* Line 1833, Address: 0x1030fc8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1838, Address: 0x1030fe0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1842, Address: 0x1031000 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1845, Address: 0x103101c */



    wD4 += 16; /* Line 1849, Address: 0x1031044 */
  } while ((short)--wD6 >= 0); /* Line 1850, Address: 0x1031050 */

} /* Line 1852, Address: 0x1031078 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1858, Address: 0x1031090 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1861, Address: 0x10310ac */
  wD6 = 15; /* Line 1862, Address: 0x10310b4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1865, Address: 0x10310bc */

    mapwrt_sub(z81awrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1867, Address: 0x10310e0 */
    wD4 += 16; /* Line 1868, Address: 0x1031100 */
  } while ((short)--wD6 >= 0); /* Line 1869, Address: 0x1031108 */
} /* Line 1870, Address: 0x103112c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1896, Address: 0x1031150 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1901, Address: 0x1031178 */
  wD0 = pWrttbl[wD0]; /* Line 1902, Address: 0x1031188 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1904, Address: 0x10311a4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1905, Address: 0x10311c8 */
  if (wD0) { /* Line 1906, Address: 0x10311f0 */
    wD5 = 65520; /* Line 1907, Address: 0x10311fc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1908, Address: 0x1031204 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1911, Address: 0x1031220 */



  } /* Line 1915, Address: 0x1031248 */
  else {

    wD5 = 0; /* Line 1918, Address: 0x1031250 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1919, Address: 0x1031254 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1923, Address: 0x1031270 */
  }





} /* Line 1930, Address: 0x1031298 */










void mapinit() { /* Line 1941, Address: 0x10312c0 */

  colorset2(mapinittbl.colorno2); /* Line 1943, Address: 0x10312c8 */
  colorset(mapinittbl.colorno2); /* Line 1944, Address: 0x10312dc */


  if (play_start & 2) divdevset(); /* Line 1947, Address: 0x10312f0 */
} /* Line 1948, Address: 0x1031310 */




void mapset() {} /* Line 1953, Address: 0x1031320 */



void divdevset() {} /* Line 1957, Address: 0x1031330 */



void enecginit() {} /* Line 1961, Address: 0x1031340 */
