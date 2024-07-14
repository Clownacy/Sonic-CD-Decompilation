#include "..\EQU.H"
#include "SCR81A.H"
#include "..\SAVE.H"
#include "COL8D.H"
#include "SCRCHK8.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z81aline(short** ppHscw);
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
  0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
  2, 2, 2, 2, 2, 2, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
  2, 2, 2, 4, 4, 4, 4, 4, 4
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
short scr_dir_tbl[6] = { 4, 0, 7831, 0, 1808, 96 };
short endplpositbl[8][2] = {
  { 80, 944 },
  { 3744, 1132 },
  { 5968, 189 },
  { 2560, 1580 },
  { 2992, 76 },
  { 5488, 364 },
  { 432, 1836 },
  { 5120, 684 }
};
short playpositbl[1][2] = { { 48, 1696 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;









































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x10280e0 */
    return &actwk[0]; /* Line 147, Address: 0x10280f4 */
  else
    return &actwk[1]; /* Line 149, Address: 0x1028104 */

} /* Line 151, Address: 0x102810c */





































void scr_set() { /* Line 189, Address: 0x1028120 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x102812c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x1028140 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x1028154 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x102815c */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x1028164 */
  ++pScrTbl; /* Line 198, Address: 0x1028170 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x1028174 */
  ++pScrTbl; /* Line 200, Address: 0x1028188 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x102818c */
  ++pScrTbl; /* Line 202, Address: 0x10281a0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x10281a4 */
  ++pScrTbl; /* Line 204, Address: 0x10281b8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x10281bc */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x10281d0 */
  ++pScrTbl; /* Line 207, Address: 0x10281f0 */
  scra_h_count = 16; /* Line 208, Address: 0x10281f4 */
  scra_v_count = 16; /* Line 209, Address: 0x1028200 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102820c */
  scra_hline = 160; /* Line 212, Address: 0x1028218 */

  playposiset(); /* Line 214, Address: 0x1028224 */
} /* Line 215, Address: 0x102822c */
















































static void playposiset() { /* Line 264, Address: 0x1028240 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x1028254 */
    playload(); /* Line 268, Address: 0x1028264 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x102826c */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x102827c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x1028294 */
    } else { /* Line 273, Address: 0x10282a4 */
      ywk = 0; /* Line 274, Address: 0x10282ac */
    }
  } /* Line 276, Address: 0x10282b0 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x10282b8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x10282d8 */
    } /* Line 280, Address: 0x10282fc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x1028304 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x1028324 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x1028338 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x102834c */
    xwk -= 160; /* Line 292, Address: 0x1028360 */
  } else { /* Line 293, Address: 0x102836c */
    xwk = 0; /* Line 294, Address: 0x1028374 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x1028378 */
    xwk = scralim_right; /* Line 299, Address: 0x102839c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x10283ac */

  if (ywk > 96) { /* Line 305, Address: 0x10283b4 */
    ywk -= 96; /* Line 306, Address: 0x10283c8 */
  } else { /* Line 307, Address: 0x10283d4 */
    ywk = 0; /* Line 308, Address: 0x10283dc */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x10283e0 */
    ywk = scralim_down; /* Line 313, Address: 0x1028404 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x1028414 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102841c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102842c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102843c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102844c */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102845c */
} /* Line 326, Address: 0x102846c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x1028490 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102849c */
  lYwk.w.l = 0; /* Line 351, Address: 0x10284a4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x10284a8 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x10284b4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x10284c0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x10284cc */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x10284d8 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x10284f4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x1028500 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102851c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x1028528 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x1028544 */
} /* Line 366, Address: 0x1028568 */















void scroll() { /* Line 382, Address: 0x1028580 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x102859c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x10285ac */

  scrchk(); /* Line 401, Address: 0x10285d8 */

  scroll_h(); /* Line 403, Address: 0x10285e0 */
  scroll_v(); /* Line 404, Address: 0x10285e8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x10285f0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x1028600 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x1028610 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x1028624 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x1028634 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x1028648 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x1028658 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x1028674 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x1028684 */


  scrollb_v(lYwk); /* Line 422, Address: 0x1028698 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x10286a8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x10286d0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x1028708 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102871c */

  z81aline(&psHscw); /* Line 431, Address: 0x1028728 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 433, Address: 0x1028734 */
  for (i = 0; i < 16; ++i) { /* Line 434, Address: 0x1028754 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x1028760 */
  } /* Line 437, Address: 0x1028774 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x1028784 */
  for (i = 0; i < 28; ++i) { /* Line 440, Address: 0x10287a4 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x10287b0 */
  } /* Line 443, Address: 0x10287c4 */

  z81aline(&psHscw); /* Line 445, Address: 0x10287d4 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 447, Address: 0x10287e0 */
  for (i = 0; i < 12; ++i) { /* Line 448, Address: 0x1028800 */

    *psHscw++ = ldwk.w.l; /* Line 450, Address: 0x102880c */
  } /* Line 451, Address: 0x1028820 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 453, Address: 0x1028830 */
  for (i = 0; i < 12; ++i) { /* Line 454, Address: 0x1028850 */

    *psHscw++ = ldwk.w.l; /* Line 456, Address: 0x102885c */
  } /* Line 457, Address: 0x1028870 */

  pHscrbuf = lphscrollbuff; /* Line 459, Address: 0x1028880 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 460, Address: 0x102888c */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 461, Address: 0x10288bc */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 462, Address: 0x10288ec */
} /* Line 463, Address: 0x1028908 */













static void z81aline(short** ppHscw) { /* Line 477, Address: 0x1028930 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z81ascrtbl[5] = {
    3, 4, 2, 0, 0
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 486, Address: 0x1028948 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 487, Address: 0x102896c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 488, Address: 0x102898c */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 489, Address: 0x10289ac */
  *ppHscw += 14; /* Line 490, Address: 0x10289b8 */

  for (i = 4; i >= 0; --i) { /* Line 492, Address: 0x10289cc */

    wk = -ldwk.w.l; /* Line 494, Address: 0x10289d8 */

    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 496, Address: 0x10289f8 */

      --*ppHscw; /* Line 498, Address: 0x1028a18 */
      **ppHscw = wk; /* Line 499, Address: 0x1028a2c */
    } /* Line 500, Address: 0x1028a38 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 502, Address: 0x1028a44 */
    ldwk.l += lXwk; /* Line 503, Address: 0x1028a68 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 504, Address: 0x1028a74 */
  } /* Line 505, Address: 0x1028a98 */

  *ppHscw += 14; /* Line 507, Address: 0x1028aa4 */
} /* Line 508, Address: 0x1028ab8 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 529, Address: 0x1028ae0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 533, Address: 0x1028afc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 534, Address: 0x1028b00 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 536, Address: 0x1028b20 */
    ldwk.w.l = *pHscrwk; /* Line 537, Address: 0x1028b3c */
    ++pHscrwk; /* Line 538, Address: 0x1028b48 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 540, Address: 0x1028b54 */
      (*pHscrbuf)->l = ldwk.l; /* Line 541, Address: 0x1028b5c */
    } /* Line 542, Address: 0x1028b6c */
  } /* Line 543, Address: 0x1028b90 */
} /* Line 544, Address: 0x1028bb0 */









































































































static void scrollb_v(short yPos) { /* Line 650, Address: 0x1028bd0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 653, Address: 0x1028be0 */
  scrb_v_posit.w.h = yPos; /* Line 654, Address: 0x1028bf0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 655, Address: 0x1028bfc */

  if (!ywk) { /* Line 657, Address: 0x1028c34 */
    scrb_v_count ^= 16; /* Line 658, Address: 0x1028c3c */
    if (yPos - ysv < 0) { /* Line 659, Address: 0x1028c50 */
      scrflagb.b.h |= 1; /* Line 660, Address: 0x1028c70 */
    } /* Line 661, Address: 0x1028c84 */
    else {
      scrflagb.b.h |= 2; /* Line 663, Address: 0x1028c8c */
    }
  }


} /* Line 668, Address: 0x1028ca0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 686, Address: 0x1028cc0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 690, Address: 0x1028cd4 */
  lXwk = lXsv + xoffs; /* Line 691, Address: 0x1028cdc */
  scrb_h_posit.l = lXwk; /* Line 692, Address: 0x1028ce4 */
  ldXwk.l = lXwk; /* Line 693, Address: 0x1028cec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 694, Address: 0x1028cf0 */
  ldXwk.w.l &= 16; /* Line 695, Address: 0x1028d14 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 696, Address: 0x1028d20 */

  if (!ldXwk.b.b4) { /* Line 698, Address: 0x1028d3c */
    scrb_h_count ^= 16; /* Line 699, Address: 0x1028d48 */
    if (lXwk - lXsv < 0) { /* Line 700, Address: 0x1028d5c */
      scrflagb.b.h |= 1 << flgbit; /* Line 701, Address: 0x1028d68 */
    } /* Line 702, Address: 0x1028d8c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 704, Address: 0x1028d94 */
    }
  }


} /* Line 709, Address: 0x1028dbc */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 727, Address: 0x1028dd0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 731, Address: 0x1028de4 */
  lXwk = lXsv + xoffs; /* Line 732, Address: 0x1028dec */
  scrc_h_posit.l = lXwk; /* Line 733, Address: 0x1028df4 */
  ldXwk.l = lXwk; /* Line 734, Address: 0x1028dfc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 735, Address: 0x1028e00 */
  ldXwk.w.l &= 16; /* Line 736, Address: 0x1028e24 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 737, Address: 0x1028e30 */

  if (!ldXwk.b.b4) { /* Line 739, Address: 0x1028e4c */
    scrc_h_count ^= 16; /* Line 740, Address: 0x1028e58 */
    if (lXwk - lXsv < 0) { /* Line 741, Address: 0x1028e6c */
      scrflagc.b.h |= 1 << flgbit; /* Line 742, Address: 0x1028e78 */
    } /* Line 743, Address: 0x1028e9c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 745, Address: 0x1028ea4 */
    }
  }


} /* Line 750, Address: 0x1028ecc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 768, Address: 0x1028ee0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 772, Address: 0x1028ef4 */
  lXwk = lXsv + xoffs; /* Line 773, Address: 0x1028efc */
  scrz_h_posit.l = lXwk; /* Line 774, Address: 0x1028f04 */
  ldXwk.l = lXwk; /* Line 775, Address: 0x1028f0c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 776, Address: 0x1028f10 */
  ldXwk.w.l &= 16; /* Line 777, Address: 0x1028f34 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 778, Address: 0x1028f40 */

  if (!ldXwk.b.b4) { /* Line 780, Address: 0x1028f5c */
    scrz_h_count ^= 16; /* Line 781, Address: 0x1028f68 */
    if (lXwk - lXsv < 0) { /* Line 782, Address: 0x1028f7c */
      scrflagz.b.h |= 1 << flgbit; /* Line 783, Address: 0x1028f88 */
    } /* Line 784, Address: 0x1028fac */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 786, Address: 0x1028fb4 */
    }
  }


} /* Line 791, Address: 0x1028fdc */














static void scroll_h() { /* Line 806, Address: 0x1028ff0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 810, Address: 0x1029000 */

  scrh_move(); /* Line 812, Address: 0x1029010 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 813, Address: 0x1029018 */
  if (!bXwk) { /* Line 814, Address: 0x102904c */
    scra_h_count ^= 16; /* Line 815, Address: 0x1029054 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 816, Address: 0x1029068 */
      scrflaga.b.h |= 4; /* Line 817, Address: 0x102908c */
    } else { /* Line 818, Address: 0x10290a0 */
      scrflaga.b.h |= 8; /* Line 819, Address: 0x10290a8 */
    }
  }


} /* Line 824, Address: 0x10290bc */
















static void scrh_move() { /* Line 841, Address: 0x10290e0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 844, Address: 0x10290e8 */
  if (xwk == 0) { /* Line 845, Address: 0x1029130 */

    scra_hz = 0; /* Line 847, Address: 0x1029140 */
    return; /* Line 848, Address: 0x1029148 */
  } else if (xwk < 0) { /* Line 849, Address: 0x1029150 */

    if (xwk < -16) { /* Line 851, Address: 0x1029160 */
      xwk = -16; /* Line 852, Address: 0x1029174 */
    }


    xwk += scra_h_posit.w.h; /* Line 856, Address: 0x1029180 */
    if (xwk < scralim_left) { /* Line 857, Address: 0x1029194 */
      xwk = scralim_left; /* Line 858, Address: 0x10291b8 */
    }
  } /* Line 860, Address: 0x10291c8 */
  else {
    if (xwk > 16) { /* Line 862, Address: 0x10291d0 */
      xwk = 16; /* Line 863, Address: 0x10291e4 */
    }


    xwk += scra_h_posit.w.h; /* Line 867, Address: 0x10291f0 */
    if (xwk > scralim_right) { /* Line 868, Address: 0x1029204 */
      xwk = scralim_right; /* Line 869, Address: 0x1029228 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 874, Address: 0x1029238 */
  scra_h_posit.w.h = xwk; /* Line 875, Address: 0x1029268 */
} /* Line 876, Address: 0x1029270 */














static void scroll_v() { /* Line 891, Address: 0x1029280 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 894, Address: 0x102928c */
  if (actwk[0].cddat & 4) { /* Line 895, Address: 0x10292c0 */
    ywk -= 5; /* Line 896, Address: 0x10292d8 */
  }


  if (actwk[0].cddat & 2) { /* Line 900, Address: 0x10292e4 */
    ywk += 32; /* Line 901, Address: 0x10292fc */
    if (ywk < scra_vline) { /* Line 902, Address: 0x1029308 */
      ywk -= scra_vline; /* Line 903, Address: 0x102932c */
      sv_move_main2(ywk); /* Line 904, Address: 0x1029340 */
      return; /* Line 905, Address: 0x102934c */
    } else if (ywk >= scra_vline + 64) { /* Line 906, Address: 0x1029354 */
      ywk -= scra_vline + 64; /* Line 907, Address: 0x102937c */
      sv_move_main2(ywk); /* Line 908, Address: 0x10293a4 */
      return; /* Line 909, Address: 0x10293b0 */
    }
    ywk -= scra_vline + 64; /* Line 911, Address: 0x10293b8 */
    if (!limmoveflag) goto label1; /* Line 912, Address: 0x10293e0 */
    sv_move_sub2(); /* Line 913, Address: 0x10293f0 */
    return; /* Line 914, Address: 0x10293f8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 919, Address: 0x1029400 */
    sv_move_main(ywk); /* Line 920, Address: 0x102942c */
    return; /* Line 921, Address: 0x1029438 */
  } else if (!limmoveflag) goto label1; /* Line 922, Address: 0x1029440 */
  sv_move_sub2(); /* Line 923, Address: 0x1029450 */
  return; /* Line 924, Address: 0x1029458 */



label1:
  scra_vz = 0; /* Line 929, Address: 0x1029460 */
} /* Line 930, Address: 0x1029468 */













static void sv_move_main(short yPos) { /* Line 944, Address: 0x1029480 */
  short spdwk;

  if (scra_vline == 96) { /* Line 947, Address: 0x1029490 */
    if (actwk[0].mspeed.w < 0) { /* Line 948, Address: 0x10294ac */
      spdwk = -actwk[0].mspeed.w; /* Line 949, Address: 0x10294c4 */
    } else { /* Line 950, Address: 0x10294e8 */
      spdwk = actwk[0].mspeed.w; /* Line 951, Address: 0x10294f0 */
    }


    if (spdwk >= 2048) { /* Line 955, Address: 0x1029500 */
      sv_move_main2(yPos); /* Line 956, Address: 0x1029514 */
    } /* Line 957, Address: 0x1029520 */
    else {

      if (yPos > 6) { /* Line 960, Address: 0x1029528 */
        sv_move_plus(1536); /* Line 961, Address: 0x1029540 */
      } else if (yPos < -6) { /* Line 962, Address: 0x102954c */
        sv_move_minus(1536); /* Line 963, Address: 0x102956c */
      } /* Line 964, Address: 0x1029578 */
      else sv_move_sub(yPos); /* Line 965, Address: 0x1029580 */
    }
  } /* Line 967, Address: 0x102958c */
  else {
    if (yPos > 2) { /* Line 969, Address: 0x1029594 */
      sv_move_plus(512); /* Line 970, Address: 0x10295ac */
    } else if (yPos < -2) { /* Line 971, Address: 0x10295b8 */
      sv_move_minus(512); /* Line 972, Address: 0x10295d8 */
    } /* Line 973, Address: 0x10295e4 */
    else sv_move_sub(yPos); /* Line 974, Address: 0x10295ec */
  }

} /* Line 977, Address: 0x10295f8 */













static void sv_move_main2(short yPos) { /* Line 991, Address: 0x1029610 */
  short spdwk;

  spdwk = 4096; /* Line 994, Address: 0x1029620 */

  if (yPos > 16) { /* Line 996, Address: 0x102962c */
    sv_move_plus(spdwk); /* Line 997, Address: 0x1029644 */
  } else if (yPos < -16) { /* Line 998, Address: 0x1029650 */
    sv_move_minus(spdwk); /* Line 999, Address: 0x1029670 */
  } else { /* Line 1000, Address: 0x102967c */
    sv_move_sub(yPos); /* Line 1001, Address: 0x1029684 */
  }
} /* Line 1003, Address: 0x1029690 */














static void sv_move_sub(short yPos) { /* Line 1018, Address: 0x10296b0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1021, Address: 0x10296bc */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1022, Address: 0x10296c0 */
  if (yPos < 0) { /* Line 1023, Address: 0x10296ec */
    scrv_up_ch(lSpd); /* Line 1024, Address: 0x1029700 */
  } else { /* Line 1025, Address: 0x102970c */
    scrv_down_ch(lSpd); /* Line 1026, Address: 0x1029714 */
  }
} /* Line 1028, Address: 0x1029720 */



static void sv_move_sub2() { /* Line 1032, Address: 0x1029730 */
  limmoveflag = 0; /* Line 1033, Address: 0x1029738 */

  sv_move_sub(0); /* Line 1035, Address: 0x1029740 */
} /* Line 1036, Address: 0x102974c */













static void sv_move_minus(short speed) { /* Line 1050, Address: 0x1029760 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1053, Address: 0x102976c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1054, Address: 0x1029790 */
  scrv_up_ch(lSpd); /* Line 1055, Address: 0x10297b4 */
} /* Line 1056, Address: 0x10297c0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1071, Address: 0x10297d0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1072, Address: 0x10297dc */
    if (lSpd.w.l > -256) { /* Line 1073, Address: 0x1029804 */

      lSpd.w.l = scralim_up; /* Line 1075, Address: 0x102981c */
    } else { /* Line 1076, Address: 0x1029828 */
      lSpd.w.l &= 2047; /* Line 1077, Address: 0x1029830 */
      actwk[0].yposi.w.l &= 2047; /* Line 1078, Address: 0x102983c */
      scra_v_posit.w.h &= 2047; /* Line 1079, Address: 0x1029850 */
      scrb_v_posit.w.h &= 1023; /* Line 1080, Address: 0x1029864 */
    }
  }

  scrv_move(lSpd); /* Line 1084, Address: 0x1029878 */
} /* Line 1085, Address: 0x1029884 */













static void sv_move_plus(short sSpd) { /* Line 1099, Address: 0x10298a0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1102, Address: 0x10298ac */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1103, Address: 0x10298cc */
  scrv_down_ch(lSpd); /* Line 1104, Address: 0x10298f0 */
} /* Line 1105, Address: 0x10298fc */














static void scrv_down_ch(int_union lSpd) { /* Line 1120, Address: 0x1029910 */
  if (lSpd.w.l >= scralim_down) { /* Line 1121, Address: 0x102991c */
    if (lSpd.w.l < 2048) { /* Line 1122, Address: 0x1029944 */

      lSpd.w.l = scralim_down; /* Line 1124, Address: 0x102995c */
    } else { /* Line 1125, Address: 0x1029968 */
      lSpd.w.l -= 2048; /* Line 1126, Address: 0x1029970 */
      actwk[0].yposi.w.l &= 2047; /* Line 1127, Address: 0x102997c */
      scra_v_posit.w.h -= 2048; /* Line 1128, Address: 0x1029990 */
      scrb_v_posit.w.h &= 1023; /* Line 1129, Address: 0x10299a4 */
    }
  }

  scrv_move(lSpd); /* Line 1133, Address: 0x10299b8 */
} /* Line 1134, Address: 0x10299c4 */
















static void scrv_move(int_union lSpd) { /* Line 1151, Address: 0x10299e0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1155, Address: 0x10299f0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1156, Address: 0x1029a00 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1157, Address: 0x1029a24 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1158, Address: 0x1029a38 */
  scra_vz = spdwk.w.l; /* Line 1159, Address: 0x1029a50 */

  scra_v_posit.l = lSpd.l; /* Line 1161, Address: 0x1029a5c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1163, Address: 0x1029a68 */
  if (!ywk) { /* Line 1164, Address: 0x1029aa4 */
    scra_v_count ^= 16; /* Line 1165, Address: 0x1029aac */
    ywk = scra_v_posit.w.h - ysv; /* Line 1166, Address: 0x1029ac0 */
    if (ywk < 0) { /* Line 1167, Address: 0x1029aec */
      scrflaga.b.h |= 1; /* Line 1168, Address: 0x1029afc */
    } else { /* Line 1169, Address: 0x1029b10 */
      scrflaga.b.h |= 2; /* Line 1170, Address: 0x1029b18 */
    }
  }


} /* Line 1175, Address: 0x1029b2c */

















void scrollwrt() { /* Line 1193, Address: 0x1029b40 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1202, Address: 0x1029b60 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1203, Address: 0x1029b64 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1204, Address: 0x1029b70 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1205, Address: 0x1029b7c */
  pScrFlag = &scrflagbw.b.h; /* Line 1206, Address: 0x1029b84 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1207, Address: 0x1029b8c */

  VramBase = 16384; /* Line 1209, Address: 0x1029ba0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1210, Address: 0x1029ba4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1211, Address: 0x1029bb0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1212, Address: 0x1029bbc */
  pScrFlag = &scrflagaw.b.h; /* Line 1213, Address: 0x1029bc4 */

  if (*pScrFlag) { /* Line 1215, Address: 0x1029bcc */
    if (*pScrFlag & 1) { /* Line 1216, Address: 0x1029bd8 */
      *pScrFlag &= 254; /* Line 1217, Address: 0x1029bec */

      lD4.l = -16; /* Line 1219, Address: 0x1029bf8 */
      wD5 = 65520; /* Line 1220, Address: 0x1029c00 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1222, Address: 0x1029c08 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1224, Address: 0x1029c28 */
    }




    if (*pScrFlag & 2) { /* Line 1230, Address: 0x1029c54 */
      *pScrFlag &= 253; /* Line 1231, Address: 0x1029c68 */

      lD4.l = 224; /* Line 1233, Address: 0x1029c74 */
      wD5 = 65520; /* Line 1234, Address: 0x1029c7c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1235, Address: 0x1029c84 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1237, Address: 0x1029ca4 */
    }




    if (*pScrFlag & 4) { /* Line 1243, Address: 0x1029cd0 */
      *pScrFlag &= 251; /* Line 1244, Address: 0x1029ce4 */

      lD4.l = -16; /* Line 1246, Address: 0x1029cf0 */
      wD5 = 65520; /* Line 1247, Address: 0x1029cf8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1248, Address: 0x1029d00 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1250, Address: 0x1029d20 */
    }




    if (*pScrFlag & 8) { /* Line 1256, Address: 0x1029d4c */
      *pScrFlag &= 247; /* Line 1257, Address: 0x1029d60 */

      lD4.l = -16; /* Line 1259, Address: 0x1029d6c */
      wD5 = 320; /* Line 1260, Address: 0x1029d74 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1261, Address: 0x1029d7c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1263, Address: 0x1029d9c */
    }
  }






} /* Line 1272, Address: 0x1029dc8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1289, Address: 0x1029df0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1300, Address: 0x1029e1c */

  if (*pScrFlag & 1) { /* Line 1302, Address: 0x1029e24 */
    *pScrFlag &= 254; /* Line 1303, Address: 0x1029e3c */
  } /* Line 1304, Address: 0x1029e50 */
  else {
    *pScrFlag &= 254; /* Line 1306, Address: 0x1029e58 */

    if (*pScrFlag & 2) { /* Line 1308, Address: 0x1029e6c */
      *pScrFlag &= 253; /* Line 1309, Address: 0x1029e84 */
      lD4.w.l = 224; /* Line 1310, Address: 0x1029e98 */
    } /* Line 1311, Address: 0x1029ea0 */
    else {
      *pScrFlag &= 253; /* Line 1313, Address: 0x1029ea8 */
      goto label1; /* Line 1314, Address: 0x1029ebc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1319, Address: 0x1029ec4 */
  wD0 &= 127; /* Line 1320, Address: 0x1029f14 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1321, Address: 0x1029f1c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1327, Address: 0x1029f3c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1328, Address: 0x1029f5c */
  if (wD0 != 0) { /* Line 1329, Address: 0x1029f80 */
    wD5 = 65520; /* Line 1330, Address: 0x1029f8c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x1029f94 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1333, Address: 0x1029fb4 */



  } /* Line 1337, Address: 0x1029fe0 */
  else {

    wD5 = 0; /* Line 1340, Address: 0x1029fe8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1341, Address: 0x1029fec */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1345, Address: 0x102a00c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1352, Address: 0x102a038 */






    lD4.l = -16; /* Line 1359, Address: 0x102a04c */
    wD5 = 65520; /* Line 1360, Address: 0x102a054 */
    if (*pScrFlag & 168) { /* Line 1361, Address: 0x102a05c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1362, Address: 0x102a074 */
      wD5 = 320; /* Line 1363, Address: 0x102a094 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1367, Address: 0x102a09c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1369, Address: 0x102a0cc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1370, Address: 0x102a0d8 */



    for (i = 0; i < 16; ++i) { /* Line 1374, Address: 0x102a0e8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1375, Address: 0x102a0f4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1376, Address: 0x102a114 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1377, Address: 0x102a14c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1378, Address: 0x102a16c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1380, Address: 0x102a190 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1383, Address: 0x102a1b4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1385, Address: 0x102a1d4 */
      }
      lD4.w.l += 16; /* Line 1387, Address: 0x102a1e8 */
    } /* Line 1388, Address: 0x102a1f4 */
    *pScrFlag = 0; /* Line 1389, Address: 0x102a204 */
  }
} /* Line 1391, Address: 0x102a20c */





void scrollwrtc() {} /* Line 1397, Address: 0x102a240 */




void scrollwrtz() {} /* Line 1402, Address: 0x102a250 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1420, Address: 0x102a260 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1433, Address: 0x102a288 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1436, Address: 0x102a2a8 */
    pTilePoint->x += 2; /* Line 1437, Address: 0x102a2bc */
    if (pTilePoint->x >= 64) { /* Line 1438, Address: 0x102a2d0 */
      pTilePoint->x -= 64; /* Line 1439, Address: 0x102a2e4 */
    }
    xOffs += 16; /* Line 1441, Address: 0x102a2f8 */
  } while (--lpcnt >= 0); /* Line 1442, Address: 0x102a304 */
} /* Line 1443, Address: 0x102a318 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1447, Address: 0x102a330 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1451, Address: 0x102a358 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1454, Address: 0x102a378 */
    pTilePoint->x += 2; /* Line 1455, Address: 0x102a38c */
    if (pTilePoint->x >= 64) { /* Line 1456, Address: 0x102a3a0 */
      pTilePoint->x -= 64; /* Line 1457, Address: 0x102a3b4 */
    }
    xOffs += 16; /* Line 1459, Address: 0x102a3c8 */
  } while (--lpcnt >= 0); /* Line 1460, Address: 0x102a3d4 */
} /* Line 1461, Address: 0x102a3e8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1481, Address: 0x102a400 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1485, Address: 0x102a428 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1488, Address: 0x102a448 */
    pTilePoint->y += 2; /* Line 1489, Address: 0x102a45c */
    if (pTilePoint->y >= 32) { /* Line 1490, Address: 0x102a46c */
      pTilePoint->y -= 32; /* Line 1491, Address: 0x102a480 */
    }
    yOffs += 16; /* Line 1493, Address: 0x102a490 */
  } while (--lpcnt >= 0); /* Line 1494, Address: 0x102a49c */
} /* Line 1495, Address: 0x102a4b0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1514, Address: 0x102a4c0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1520, Address: 0x102a4f4 */

    base = 1; /* Line 1522, Address: 0x102a504 */
  } /* Line 1523, Address: 0x102a508 */
  else if (VramBase == 16384) { /* Line 1524, Address: 0x102a510 */

    base = 0; /* Line 1526, Address: 0x102a520 */
  }
  x = pTilePoint->x; /* Line 1528, Address: 0x102a524 */
  y = pTilePoint->y; /* Line 1529, Address: 0x102a52c */


  frip = BlkIndex & 6144; /* Line 1532, Address: 0x102a534 */
  BlkIndex &= 1023; /* Line 1533, Address: 0x102a53c */
  if (frip == 6144) { /* Line 1534, Address: 0x102a548 */

    p0 = 3, p1 = 2; /* Line 1536, Address: 0x102a554 */
    p2 = 1, p3 = 0; /* Line 1537, Address: 0x102a55c */
  } /* Line 1538, Address: 0x102a564 */
  else if (frip & 4096) { /* Line 1539, Address: 0x102a56c */

    p0 = 2, p1 = 3; /* Line 1541, Address: 0x102a578 */
    p2 = 0, p3 = 1; /* Line 1542, Address: 0x102a580 */
  } /* Line 1543, Address: 0x102a588 */
  else if (frip & 2048) { /* Line 1544, Address: 0x102a590 */

    p0 = 1, p1 = 0; /* Line 1546, Address: 0x102a59c */
    p2 = 3, p3 = 2; /* Line 1547, Address: 0x102a5a4 */
  } /* Line 1548, Address: 0x102a5ac */
  else {

    p0 = 0, p1 = 1; /* Line 1551, Address: 0x102a5b4 */
    p2 = 2, p3 = 3; /* Line 1552, Address: 0x102a5bc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1555, Address: 0x102a5c4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1556, Address: 0x102a608 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1557, Address: 0x102a64c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1558, Address: 0x102a690 */

} /* Line 1560, Address: 0x102a6d4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1578, Address: 0x102a710 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1579, Address: 0x102a730 */
} /* Line 1580, Address: 0x102a750 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1582, Address: 0x102a760 */
  wH_posiw = 0; /* Line 1583, Address: 0x102a780 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1584, Address: 0x102a784 */
} /* Line 1585, Address: 0x102a7a4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1592, Address: 0x102a7c0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1598, Address: 0x102a7f0 */
  yOffs += wV_posiw; /* Line 1599, Address: 0x102a800 */





  if ((short)xOffs < 0) /* Line 1605, Address: 0x102a810 */
    xOffs = 0; /* Line 1606, Address: 0x102a82c */
  if ((short)yOffs < 0) /* Line 1607, Address: 0x102a830 */
    yOffs = 0; /* Line 1608, Address: 0x102a84c */
  if ((short)xOffs >= 16384) /* Line 1609, Address: 0x102a850 */
    xOffs = 16383; /* Line 1610, Address: 0x102a870 */
  if ((short)yOffs >= 2048) /* Line 1611, Address: 0x102a878 */
    yOffs = 2047; /* Line 1612, Address: 0x102a898 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1613, Address: 0x102a8a0 */
  if (i < 0) i = 0; /* Line 1614, Address: 0x102a8e8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1616, Address: 0x102a8f4 */

  if (ScreenNo) { /* Line 1618, Address: 0x102a910 */




    xOffs &= 32767; /* Line 1623, Address: 0x102a918 */
    yOffs &= 32767; /* Line 1624, Address: 0x102a924 */


    xBlk = xOffs; /* Line 1627, Address: 0x102a930 */
    xBlk %= 256; /* Line 1628, Address: 0x102a938 */
    xBlk /= 16; /* Line 1629, Address: 0x102a958 */
    yBlk = yOffs; /* Line 1630, Address: 0x102a974 */
    yBlk %= 256; /* Line 1631, Address: 0x102a97c */
    yBlk /= 16; /* Line 1632, Address: 0x102a99c */

    lpw = pmapwk; /* Line 1634, Address: 0x102a9b8 */
    lpw += xBlk; /* Line 1635, Address: 0x102a9c0 */
    lpw += yBlk * 16; /* Line 1636, Address: 0x102a9c8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1637, Address: 0x102a9d4 */
    *pIndex = *lpw; /* Line 1638, Address: 0x102a9ec */

    return 1; /* Line 1640, Address: 0x102a9fc */
  }

  *pIndex = 0; /* Line 1643, Address: 0x102aa08 */
  return 0; /* Line 1644, Address: 0x102aa10 */
} /* Line 1645, Address: 0x102aa14 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1665, Address: 0x102aa40 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1673, Address: 0x102aa68 */
  if (ScreenNo) { /* Line 1674, Address: 0x102aacc */





    xBlk = xOffs; /* Line 1680, Address: 0x102aad4 */
    xBlk %= 256; /* Line 1681, Address: 0x102aadc */
    xBlk /= 16; /* Line 1682, Address: 0x102aafc */
    yBlk = yOffs; /* Line 1683, Address: 0x102ab18 */
    yBlk %= 256; /* Line 1684, Address: 0x102ab20 */
    yBlk /= 16; /* Line 1685, Address: 0x102ab40 */


    lpw = pmapwk; /* Line 1688, Address: 0x102ab5c */
    lpw += xBlk; /* Line 1689, Address: 0x102ab64 */
    lpw += yBlk * 16; /* Line 1690, Address: 0x102ab6c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1691, Address: 0x102ab78 */
    *ppBlockNo = lpw; /* Line 1692, Address: 0x102ab90 */
    *pIndex = *lpw; /* Line 1693, Address: 0x102ab98 */




    return 1; /* Line 1698, Address: 0x102aba8 */
  }

  *pIndex = 0; /* Line 1701, Address: 0x102abb4 */
  return 0; /* Line 1702, Address: 0x102abbc */
} /* Line 1703, Address: 0x102abc0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1717, Address: 0x102abe0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1724, Address: 0x102abfc */
  pMapWk = (unsigned char*)mapwka; /* Line 1725, Address: 0x102ac00 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1726, Address: 0x102ac08 */
    *pBlockIndex = BlockNo; /* Line 1727, Address: 0x102ac2c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1728, Address: 0x102ac38 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1729, Address: 0x102ac50 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1730, Address: 0x102ac64 */
    }
  }


} /* Line 1735, Address: 0x102ac7c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1749, Address: 0x102aca0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1750, Address: 0x102acac */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1751, Address: 0x102acd8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1752, Address: 0x102ad24 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1753, Address: 0x102ad50 */

          return 0; /* Line 1755, Address: 0x102ad9c */
        }
      }
    }
  }

  return 1; /* Line 1761, Address: 0x102ada8 */
} /* Line 1762, Address: 0x102adac */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102adc0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x102addc */

} /* Line 1782, Address: 0x102adf8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x102ae10 */
  wH_posiw = 0; /* Line 1785, Address: 0x102ae2c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1786, Address: 0x102ae30 */

} /* Line 1788, Address: 0x102ae4c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1790, Address: 0x102ae60 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1791, Address: 0x102ae74 */

} /* Line 1793, Address: 0x102ae90 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1795, Address: 0x102aea0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1796, Address: 0x102aebc */

} /* Line 1798, Address: 0x102aed8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1800, Address: 0x102aef0 */
  xOffs += wH_posiw; /* Line 1801, Address: 0x102af08 */
  yOffs += wV_posiw; /* Line 1802, Address: 0x102af18 */
  yOffs &= 240; /* Line 1803, Address: 0x102af28 */
  xOffs &= 496; /* Line 1804, Address: 0x102af34 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1806, Address: 0x102af40 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1807, Address: 0x102af6c */


} /* Line 1810, Address: 0x102af98 */















void mapwrt() { /* Line 1826, Address: 0x102afb0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1833, Address: 0x102afc8 */
  wV_posiw = scra_v_posit.w.h; /* Line 1834, Address: 0x102afd4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1835, Address: 0x102afe0 */
  VramBase = 16384; /* Line 1836, Address: 0x102afe8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1837, Address: 0x102afec */



  pMapWk = (unsigned char*)mapwkb; /* Line 1841, Address: 0x102b004 */
  VramBase = 24576; /* Line 1842, Address: 0x102b00c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1843, Address: 0x102b010 */

} /* Line 1845, Address: 0x102b020 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1848, Address: 0x102b040 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1849, Address: 0x102b058 */
} /* Line 1850, Address: 0x102b078 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1855, Address: 0x102b090 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1859, Address: 0x102b0b0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1862, Address: 0x102b0cc */



    wD4 += 16; /* Line 1866, Address: 0x102b0f4 */
  } while ((short)--wD6 >= 0); /* Line 1867, Address: 0x102b100 */

} /* Line 1869, Address: 0x102b128 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1875, Address: 0x102b140 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1878, Address: 0x102b15c */
  wD6 = 15; /* Line 1879, Address: 0x102b164 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1882, Address: 0x102b16c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1884, Address: 0x102b190 */
    wD4 += 16; /* Line 1885, Address: 0x102b1b0 */
  } while ((short)--wD6 >= 0); /* Line 1886, Address: 0x102b1b8 */
} /* Line 1887, Address: 0x102b1dc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1913, Address: 0x102b200 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1918, Address: 0x102b228 */
  wD0 = pWrttbl[wD0]; /* Line 1919, Address: 0x102b238 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1921, Address: 0x102b254 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1922, Address: 0x102b278 */
  if (wD0) { /* Line 1923, Address: 0x102b2a0 */
    wD5 = 65520; /* Line 1924, Address: 0x102b2ac */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1925, Address: 0x102b2b4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1928, Address: 0x102b2d0 */



  } /* Line 1932, Address: 0x102b2f8 */
  else {

    wD5 = 0; /* Line 1935, Address: 0x102b300 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1936, Address: 0x102b304 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1940, Address: 0x102b320 */
  }





} /* Line 1947, Address: 0x102b348 */










void mapinit() { /* Line 1958, Address: 0x102b370 */

  colorset2(mapinittbl.colorno2); /* Line 1960, Address: 0x102b378 */
  colorset(mapinittbl.colorno2); /* Line 1961, Address: 0x102b38c */

  if (plflag) enecginit(); /* Line 1963, Address: 0x102b3a0 */
  if (play_start & 2) divdevset(); /* Line 1964, Address: 0x102b3b8 */
} /* Line 1965, Address: 0x102b3d8 */




void mapset() {} /* Line 1970, Address: 0x102b3f0 */



void divdevset() {} /* Line 1974, Address: 0x102b400 */



void enecginit() {} /* Line 1978, Address: 0x102b410 */
