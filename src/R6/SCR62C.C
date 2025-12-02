#include "..\EQU.H"
#include "SCR62A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
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
short scr_dir_tbl[6] = { 4, 0, 9111, 0, 1808, 96 };
short playpositbl[1][2] = { { 48, 412 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;































































































































void scr_set() { /* Line 190, Address: 0x102c590 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x102c59c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x102c5b0 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x102c5c4 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x102c5cc */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x102c5d4 */
  ++pScrTbl; /* Line 199, Address: 0x102c5e0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x102c5e4 */
  ++pScrTbl; /* Line 201, Address: 0x102c5f8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x102c5fc */
  ++pScrTbl; /* Line 203, Address: 0x102c610 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x102c614 */
  ++pScrTbl; /* Line 205, Address: 0x102c628 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x102c62c */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x102c640 */
  ++pScrTbl; /* Line 208, Address: 0x102c660 */
  scra_h_count = 16; /* Line 209, Address: 0x102c664 */
  scra_v_count = 16; /* Line 210, Address: 0x102c670 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x102c67c */
  scra_hline = 160; /* Line 213, Address: 0x102c688 */

  playposiset(); /* Line 215, Address: 0x102c694 */
} /* Line 216, Address: 0x102c69c */






































void playposiset() { /* Line 255, Address: 0x102c6b0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 258, Address: 0x102c6c4 */
    playload(); /* Line 259, Address: 0x102c6d4 */
    xwk = actwk[0].xposi.w.h; /* Line 260, Address: 0x102c6dc */

    if (actwk[0].yposi.w.h > 0) { /* Line 262, Address: 0x102c6ec */
      ywk = actwk[0].yposi.w.h; /* Line 263, Address: 0x102c704 */
    } else { /* Line 264, Address: 0x102c714 */
      ywk = 0; /* Line 265, Address: 0x102c71c */
    }
  } /* Line 267, Address: 0x102c720 */
  else {













    pPositbl = playpositbl[0]; /* Line 282, Address: 0x102c728 */
    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 283, Address: 0x102c730 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 284, Address: 0x102c744 */
  }


  if (xwk > 160) { /* Line 288, Address: 0x102c758 */
    xwk -= 160; /* Line 289, Address: 0x102c76c */
  } else { /* Line 290, Address: 0x102c778 */
    xwk = 0; /* Line 291, Address: 0x102c780 */
  }


  if (xwk > scralim_right) { /* Line 295, Address: 0x102c784 */
    xwk = scralim_right; /* Line 296, Address: 0x102c7a8 */
  }


  scra_h_posit.w.h = xwk; /* Line 300, Address: 0x102c7b8 */

  if (ywk > 96) { /* Line 302, Address: 0x102c7c0 */
    ywk -= 96; /* Line 303, Address: 0x102c7d4 */
  } else { /* Line 304, Address: 0x102c7e0 */
    ywk = 0; /* Line 305, Address: 0x102c7e8 */
  }


  if (ywk > scralim_down) { /* Line 309, Address: 0x102c7ec */
    ywk = scralim_down; /* Line 310, Address: 0x102c810 */
  }


  scra_v_posit.w.h = ywk; /* Line 314, Address: 0x102c820 */

  scrbinit(xwk, ywk); /* Line 316, Address: 0x102c828 */


  loopmapno = playmapnotbl[0]; /* Line 319, Address: 0x102c838 */
  loopmapno2 = playmapnotbl[1]; /* Line 320, Address: 0x102c848 */
  ballmapno = playmapnotbl[2]; /* Line 321, Address: 0x102c858 */
  ballmapno2 = playmapnotbl[3]; /* Line 322, Address: 0x102c868 */
} /* Line 323, Address: 0x102c878 */




















static void scrbinit(short sXpos, short sYpos) {
  int_union lYwk;
 /* Line 344, Address: 0x102c8a0 */
  lYwk.w.h = sYpos;
  lYwk.w.l = 0;
 /* Line 347, Address: 0x102c8ac */
  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 348, Address: 0x102c8b4 */
  scrb_v_posit.l = lYwk.l;
  scrc_v_posit.w.h = lYwk.w.h; /* Line 350, Address: 0x102c8b8 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 351, Address: 0x102c8c4 */
 /* Line 352, Address: 0x102c8d0 */
  sXpos = (unsigned short)sXpos >> 1; /* Line 353, Address: 0x102c8dc */
  scrc_h_posit.w.h = sXpos;
 /* Line 355, Address: 0x102c8e8 */
  sXpos = (unsigned short)sXpos >> 1; /* Line 356, Address: 0x102c904 */
  scrz_h_posit.w.h = sXpos;
 /* Line 358, Address: 0x102c910 */
  sXpos = (unsigned short)sXpos >> 2; /* Line 359, Address: 0x102c92c */
  scrb_h_posit.w.h = sXpos * 3;
} /* Line 361, Address: 0x102c938 */
 /* Line 362, Address: 0x102c954 */
 /* Line 363, Address: 0x102c978 */













void scroll() { /* Line 379, Address: 0x102c990 */
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

  if (scroll_start.b.h) return; /* Line 391, Address: 0x102c9ac */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 396, Address: 0x102c9bc */

  scrchk(); /* Line 398, Address: 0x102c9e8 */

  scroll_h(); /* Line 400, Address: 0x102c9f0 */
  scroll_v(); /* Line 401, Address: 0x102c9f8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 403, Address: 0x102ca00 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 404, Address: 0x102ca10 */


  lXwk = scra_hz << 6; /* Line 407, Address: 0x102ca20 */
  scrollz_h(lXwk, 6); /* Line 408, Address: 0x102ca34 */

  lXwk = scra_hz << 7; /* Line 410, Address: 0x102ca44 */
  scrollc_h(lXwk, 4); /* Line 411, Address: 0x102ca58 */

  lXwk = (scra_hz << 4) * 3; /* Line 413, Address: 0x102ca68 */
  scrollb_h(lXwk, 2); /* Line 414, Address: 0x102ca84 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 416, Address: 0x102ca94 */


  scrollb_v(lYwk); /* Line 419, Address: 0x102caa8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 421, Address: 0x102cab8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 423, Address: 0x102cae0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 424, Address: 0x102cb18 */

  psHscw = hscrollwork; /* Line 426, Address: 0x102cb2c */

  z61aline(&psHscw); /* Line 428, Address: 0x102cb38 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 430, Address: 0x102cb44 */
  for (i = 0; i < 24; ++i) { /* Line 431, Address: 0x102cb64 */

    *psHscw++ = ldwk.w.l; /* Line 433, Address: 0x102cb70 */
  } /* Line 434, Address: 0x102cb84 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 436, Address: 0x102cb94 */
  for (i = 0; i < 46; ++i) { /* Line 437, Address: 0x102cbb4 */

    *psHscw++ = ldwk.w.l; /* Line 439, Address: 0x102cbc0 */
  } /* Line 440, Address: 0x102cbd4 */

  pHscrbuf = lphscrollbuff; /* Line 442, Address: 0x102cbe4 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 443, Address: 0x102cbf0 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 444, Address: 0x102cc20 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 445, Address: 0x102cc50 */
} /* Line 446, Address: 0x102cc6c */













void z61aline(short** ppHscw) { /* Line 460, Address: 0x102cc90 */
  char z81ascrtbl[9] = { /* Line 461, Address: 0x102ccb4 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk;


  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 469, Address: 0x102cce0 */
  radwk = 0; /* Line 470, Address: 0x102cd04 */
  sXwk = scrb_h_posit.w.h; /* Line 471, Address: 0x102cd08 */

  *ppHscw += 26; /* Line 473, Address: 0x102cd18 */

  for (i = 8; i >= 0; --i) { /* Line 475, Address: 0x102cd2c */

    sinset(radwk, &sinwk, &coswk); /* Line 477, Address: 0x102cd38 */
    hwk = -(sXwk + (short)((unsigned short)((256 - coswk) * lXwk) >> 8)); /* Line 478, Address: 0x102cd4c */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 479, Address: 0x102cda0 */

      --*ppHscw; /* Line 481, Address: 0x102cdb8 */
      **ppHscw = hwk; /* Line 482, Address: 0x102cdcc */
    } /* Line 483, Address: 0x102cdd8 */

    radwk += 6; /* Line 485, Address: 0x102cde4 */
  } /* Line 486, Address: 0x102cdf0 */

  *ppHscw += 26; /* Line 488, Address: 0x102cdfc */
} /* Line 489, Address: 0x102ce10 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 510, Address: 0x102ce40 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 514, Address: 0x102ce5c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 515, Address: 0x102ce60 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 517, Address: 0x102ce80 */
    ldwk.w.l = *pHscrwk; /* Line 518, Address: 0x102ce9c */
    ++pHscrwk; /* Line 519, Address: 0x102cea8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 521, Address: 0x102ceb4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 522, Address: 0x102cebc */
    } /* Line 523, Address: 0x102cecc */
  } /* Line 524, Address: 0x102cef0 */
} /* Line 525, Address: 0x102cf10 */









































































































static void scrollb_v(short yPos) { /* Line 631, Address: 0x102cf30 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 634, Address: 0x102cf40 */
  scrb_v_posit.w.h = yPos; /* Line 635, Address: 0x102cf50 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 636, Address: 0x102cf5c */

  if (!ywk) { /* Line 638, Address: 0x102cf94 */
    scrb_v_count ^= 16; /* Line 639, Address: 0x102cf9c */
    if (yPos - ysv < 0) { /* Line 640, Address: 0x102cfb0 */
      scrflagb.b.h |= 1; /* Line 641, Address: 0x102cfd0 */
    } /* Line 642, Address: 0x102cfe4 */
    else {
      scrflagb.b.h |= 2; /* Line 644, Address: 0x102cfec */
    }
  }


} /* Line 649, Address: 0x102d000 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 667, Address: 0x102d020 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 671, Address: 0x102d034 */
  lXwk = lXsv + xoffs; /* Line 672, Address: 0x102d03c */
  scrb_h_posit.l = lXwk; /* Line 673, Address: 0x102d044 */
  ldXwk.l = lXwk; /* Line 674, Address: 0x102d04c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 675, Address: 0x102d050 */
  ldXwk.w.l &= 16; /* Line 676, Address: 0x102d074 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 677, Address: 0x102d080 */

  if (!ldXwk.b.b4) { /* Line 679, Address: 0x102d09c */
    scrb_h_count ^= 16; /* Line 680, Address: 0x102d0a8 */
    if (lXwk - lXsv < 0) { /* Line 681, Address: 0x102d0bc */
      scrflagb.b.h |= 1 << flgbit; /* Line 682, Address: 0x102d0c8 */
    } /* Line 683, Address: 0x102d0ec */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 685, Address: 0x102d0f4 */
    }
  }


} /* Line 690, Address: 0x102d11c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 708, Address: 0x102d130 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 712, Address: 0x102d144 */
  lXwk = lXsv + xoffs; /* Line 713, Address: 0x102d14c */
  scrc_h_posit.l = lXwk; /* Line 714, Address: 0x102d154 */
  ldXwk.l = lXwk; /* Line 715, Address: 0x102d15c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 716, Address: 0x102d160 */
  ldXwk.w.l &= 16; /* Line 717, Address: 0x102d184 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 718, Address: 0x102d190 */

  if (!ldXwk.b.b4) { /* Line 720, Address: 0x102d1ac */
    scrc_h_count ^= 16; /* Line 721, Address: 0x102d1b8 */
    if (lXwk - lXsv < 0) { /* Line 722, Address: 0x102d1cc */
      scrflagc.b.h |= 1 << flgbit; /* Line 723, Address: 0x102d1d8 */
    } /* Line 724, Address: 0x102d1fc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 726, Address: 0x102d204 */
    }
  }


} /* Line 731, Address: 0x102d22c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 749, Address: 0x102d240 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 753, Address: 0x102d254 */
  lXwk = lXsv + xoffs; /* Line 754, Address: 0x102d25c */
  scrz_h_posit.l = lXwk; /* Line 755, Address: 0x102d264 */
  ldXwk.l = lXwk; /* Line 756, Address: 0x102d26c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 757, Address: 0x102d270 */
  ldXwk.w.l &= 16; /* Line 758, Address: 0x102d294 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 759, Address: 0x102d2a0 */

  if (!ldXwk.b.b4) { /* Line 761, Address: 0x102d2bc */
    scrz_h_count ^= 16; /* Line 762, Address: 0x102d2c8 */
    if (lXwk - lXsv < 0) { /* Line 763, Address: 0x102d2dc */
      scrflagz.b.h |= 1 << flgbit; /* Line 764, Address: 0x102d2e8 */
    } /* Line 765, Address: 0x102d30c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 767, Address: 0x102d314 */
    }
  }


} /* Line 772, Address: 0x102d33c */














static void scroll_h() { /* Line 787, Address: 0x102d350 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 791, Address: 0x102d360 */

  scrh_move(); /* Line 793, Address: 0x102d370 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 794, Address: 0x102d378 */
  if (!bXwk) { /* Line 795, Address: 0x102d3ac */
    scra_h_count ^= 16; /* Line 796, Address: 0x102d3b4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 797, Address: 0x102d3c8 */
      scrflaga.b.h |= 4; /* Line 798, Address: 0x102d3ec */
    } else { /* Line 799, Address: 0x102d400 */
      scrflaga.b.h |= 8; /* Line 800, Address: 0x102d408 */
    }
  }


} /* Line 805, Address: 0x102d41c */
















static void scrh_move() { /* Line 822, Address: 0x102d440 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 825, Address: 0x102d448 */
  if (xwk == 0) { /* Line 826, Address: 0x102d490 */

    scra_hz = 0; /* Line 828, Address: 0x102d4a0 */
    return; /* Line 829, Address: 0x102d4a8 */
  } else if (xwk < 0) { /* Line 830, Address: 0x102d4b0 */

    if (xwk < -16) { /* Line 832, Address: 0x102d4c0 */
      xwk = -16; /* Line 833, Address: 0x102d4d4 */
    }


    xwk += scra_h_posit.w.h; /* Line 837, Address: 0x102d4e0 */
    if (xwk < scralim_left) { /* Line 838, Address: 0x102d4f4 */
      xwk = scralim_left; /* Line 839, Address: 0x102d518 */
    }
  } /* Line 841, Address: 0x102d528 */
  else {
    if (xwk > 16) { /* Line 843, Address: 0x102d530 */
      xwk = 16; /* Line 844, Address: 0x102d544 */
    }


    xwk += scra_h_posit.w.h; /* Line 848, Address: 0x102d550 */
    if (xwk > scralim_right) { /* Line 849, Address: 0x102d564 */
      xwk = scralim_right; /* Line 850, Address: 0x102d588 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 855, Address: 0x102d598 */
  scra_h_posit.w.h = xwk; /* Line 856, Address: 0x102d5c8 */
} /* Line 857, Address: 0x102d5d0 */














static void scroll_v() { /* Line 872, Address: 0x102d5e0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 875, Address: 0x102d5ec */
  if (actwk[0].cddat & 4) { /* Line 876, Address: 0x102d620 */
    ywk -= 5; /* Line 877, Address: 0x102d638 */
  }


  if (actwk[0].cddat & 2) { /* Line 881, Address: 0x102d644 */
    ywk += 32; /* Line 882, Address: 0x102d65c */
    if (ywk < scra_vline) { /* Line 883, Address: 0x102d668 */
      ywk -= scra_vline; /* Line 884, Address: 0x102d68c */
      sv_move_main2(ywk); /* Line 885, Address: 0x102d6a0 */
      return; /* Line 886, Address: 0x102d6ac */
    } else if (ywk >= scra_vline + 64) { /* Line 887, Address: 0x102d6b4 */
      ywk -= scra_vline + 64; /* Line 888, Address: 0x102d6dc */
      sv_move_main2(ywk); /* Line 889, Address: 0x102d704 */
      return; /* Line 890, Address: 0x102d710 */
    }
    ywk -= scra_vline + 64; /* Line 892, Address: 0x102d718 */
    if (!limmoveflag) goto label1; /* Line 893, Address: 0x102d740 */
    sv_move_sub2(); /* Line 894, Address: 0x102d750 */
    return; /* Line 895, Address: 0x102d758 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 900, Address: 0x102d760 */
    sv_move_main(ywk); /* Line 901, Address: 0x102d78c */
    return; /* Line 902, Address: 0x102d798 */
  } else if (!limmoveflag) goto label1; /* Line 903, Address: 0x102d7a0 */
  sv_move_sub2(); /* Line 904, Address: 0x102d7b0 */
  return; /* Line 905, Address: 0x102d7b8 */



label1:
  scra_vz = 0; /* Line 910, Address: 0x102d7c0 */
} /* Line 911, Address: 0x102d7c8 */













static void sv_move_main(short yPos) { /* Line 925, Address: 0x102d7e0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 928, Address: 0x102d7f0 */
    if (actwk[0].mspeed.w < 0) { /* Line 929, Address: 0x102d80c */
      spdwk = -actwk[0].mspeed.w; /* Line 930, Address: 0x102d824 */
    } else { /* Line 931, Address: 0x102d848 */
      spdwk = actwk[0].mspeed.w; /* Line 932, Address: 0x102d850 */
    }


    if (spdwk >= 2048) { /* Line 936, Address: 0x102d860 */
      sv_move_main2(yPos); /* Line 937, Address: 0x102d874 */
    } /* Line 938, Address: 0x102d880 */
    else {

      if (yPos > 6) { /* Line 941, Address: 0x102d888 */
        sv_move_plus(1536); /* Line 942, Address: 0x102d8a0 */
      } else if (yPos < -6) { /* Line 943, Address: 0x102d8ac */
        sv_move_minus(1536); /* Line 944, Address: 0x102d8cc */
      } /* Line 945, Address: 0x102d8d8 */
      else sv_move_sub(yPos); /* Line 946, Address: 0x102d8e0 */
    }
  } /* Line 948, Address: 0x102d8ec */
  else {
    if (yPos > 2) { /* Line 950, Address: 0x102d8f4 */
      sv_move_plus(512); /* Line 951, Address: 0x102d90c */
    } else if (yPos < -2) { /* Line 952, Address: 0x102d918 */
      sv_move_minus(512); /* Line 953, Address: 0x102d938 */
    } /* Line 954, Address: 0x102d944 */
    else sv_move_sub(yPos); /* Line 955, Address: 0x102d94c */
  }

} /* Line 958, Address: 0x102d958 */













static void sv_move_main2(short yPos) { /* Line 972, Address: 0x102d970 */
  short spdwk;

  spdwk = 4096; /* Line 975, Address: 0x102d980 */

  if (yPos > 16) { /* Line 977, Address: 0x102d98c */
    sv_move_plus(spdwk); /* Line 978, Address: 0x102d9a4 */
  } else if (yPos < -16) { /* Line 979, Address: 0x102d9b0 */
    sv_move_minus(spdwk); /* Line 980, Address: 0x102d9d0 */
  } else { /* Line 981, Address: 0x102d9dc */
    sv_move_sub(yPos); /* Line 982, Address: 0x102d9e4 */
  }
} /* Line 984, Address: 0x102d9f0 */














static void sv_move_sub(short yPos) { /* Line 999, Address: 0x102da10 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1002, Address: 0x102da1c */
  if (yPos < 0) { /* Line 1003, Address: 0x102da48 */
    scrv_up_ch(lSpd); /* Line 1004, Address: 0x102da5c */
  } else { /* Line 1005, Address: 0x102da68 */
    scrv_down_ch(lSpd); /* Line 1006, Address: 0x102da70 */
  }
} /* Line 1008, Address: 0x102da7c */



static void sv_move_sub2() { /* Line 1012, Address: 0x102da90 */
  limmoveflag = 0; /* Line 1013, Address: 0x102da98 */

  sv_move_sub(0); /* Line 1015, Address: 0x102daa0 */
} /* Line 1016, Address: 0x102daac */













static void sv_move_minus(short speed) { /* Line 1030, Address: 0x102dac0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1033, Address: 0x102dacc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1034, Address: 0x102daf0 */
  scrv_up_ch(lSpd); /* Line 1035, Address: 0x102db14 */
} /* Line 1036, Address: 0x102db20 */














static void scrv_up_ch(int_union lSpd) { /* Line 1051, Address: 0x102db30 */
  if (lSpd.w.l <= scralim_up) { /* Line 1052, Address: 0x102db3c */
    if (lSpd.w.l > -256) { /* Line 1053, Address: 0x102db64 */

      lSpd.w.l = scralim_up; /* Line 1055, Address: 0x102db7c */
    } else { /* Line 1056, Address: 0x102db88 */
      lSpd.w.l &= 2047; /* Line 1057, Address: 0x102db90 */
      actwk[0].yposi.w.l &= 2047; /* Line 1058, Address: 0x102db9c */
      scra_v_posit.w.h &= 2047; /* Line 1059, Address: 0x102dbb0 */
      scrb_v_posit.w.h &= 1023; /* Line 1060, Address: 0x102dbc4 */
    }
  }

  scrv_move(lSpd); /* Line 1064, Address: 0x102dbd8 */
} /* Line 1065, Address: 0x102dbe4 */













static void sv_move_plus(short sSpd) { /* Line 1079, Address: 0x102dc00 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1082, Address: 0x102dc0c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1083, Address: 0x102dc2c */
  scrv_down_ch(lSpd); /* Line 1084, Address: 0x102dc50 */
} /* Line 1085, Address: 0x102dc5c */














static void scrv_down_ch(int_union lSpd) { /* Line 1100, Address: 0x102dc70 */
  if (lSpd.w.l >= scralim_down) { /* Line 1101, Address: 0x102dc7c */
    if (lSpd.w.l < 2048) { /* Line 1102, Address: 0x102dca4 */

      lSpd.w.l = scralim_down; /* Line 1104, Address: 0x102dcbc */
    } else { /* Line 1105, Address: 0x102dcc8 */
      lSpd.w.l -= 2048; /* Line 1106, Address: 0x102dcd0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1107, Address: 0x102dcdc */
      scra_v_posit.w.h -= 2048; /* Line 1108, Address: 0x102dcf0 */
      scrb_v_posit.w.h &= 1023; /* Line 1109, Address: 0x102dd04 */
    }
  }

  scrv_move(lSpd); /* Line 1113, Address: 0x102dd18 */
} /* Line 1114, Address: 0x102dd24 */
















static void scrv_move(int_union lSpd) { /* Line 1131, Address: 0x102dd40 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1135, Address: 0x102dd50 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1136, Address: 0x102dd60 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1137, Address: 0x102dd84 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1138, Address: 0x102dd98 */
  scra_vz = spdwk.w.l; /* Line 1139, Address: 0x102ddb0 */

  scra_v_posit.l = lSpd.l; /* Line 1141, Address: 0x102ddbc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1143, Address: 0x102ddc8 */
  if (!ywk) { /* Line 1144, Address: 0x102de04 */
    scra_v_count ^= 16; /* Line 1145, Address: 0x102de0c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1146, Address: 0x102de20 */
    if (ywk < 0) { /* Line 1147, Address: 0x102de4c */
      scrflaga.b.h |= 1; /* Line 1148, Address: 0x102de5c */
    } else { /* Line 1149, Address: 0x102de70 */
      scrflaga.b.h |= 2; /* Line 1150, Address: 0x102de78 */
    }
  }


} /* Line 1155, Address: 0x102de8c */

















void scrollwrt() { /* Line 1173, Address: 0x102dea0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1182, Address: 0x102dec0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1183, Address: 0x102dec4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1184, Address: 0x102ded0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1185, Address: 0x102dedc */
  pScrFlag = &scrflagbw.b.h; /* Line 1186, Address: 0x102dee4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1187, Address: 0x102deec */

  VramBase = 16384; /* Line 1189, Address: 0x102df00 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1190, Address: 0x102df04 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1191, Address: 0x102df10 */
  pMapWk = (unsigned char*)mapwka; /* Line 1192, Address: 0x102df1c */
  pScrFlag = &scrflagaw.b.h; /* Line 1193, Address: 0x102df24 */

  if (*pScrFlag) { /* Line 1195, Address: 0x102df2c */
    if (*pScrFlag & 1) { /* Line 1196, Address: 0x102df38 */
      *pScrFlag &= 254; /* Line 1197, Address: 0x102df4c */

      lD4.l = -16; /* Line 1199, Address: 0x102df58 */
      wD5 = 65520; /* Line 1200, Address: 0x102df60 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1202, Address: 0x102df68 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1204, Address: 0x102df88 */
    }




    if (*pScrFlag & 2) { /* Line 1210, Address: 0x102dfb4 */
      *pScrFlag &= 253; /* Line 1211, Address: 0x102dfc8 */

      lD4.l = 224; /* Line 1213, Address: 0x102dfd4 */
      wD5 = 65520; /* Line 1214, Address: 0x102dfdc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1215, Address: 0x102dfe4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1217, Address: 0x102e004 */
    }




    if (*pScrFlag & 4) { /* Line 1223, Address: 0x102e030 */
      *pScrFlag &= 251; /* Line 1224, Address: 0x102e044 */

      lD4.l = -16; /* Line 1226, Address: 0x102e050 */
      wD5 = 65520; /* Line 1227, Address: 0x102e058 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1228, Address: 0x102e060 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1230, Address: 0x102e080 */
    }




    if (*pScrFlag & 8) { /* Line 1236, Address: 0x102e0ac */
      *pScrFlag &= 247; /* Line 1237, Address: 0x102e0c0 */

      lD4.l = -16; /* Line 1239, Address: 0x102e0cc */
      wD5 = 320; /* Line 1240, Address: 0x102e0d4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1241, Address: 0x102e0dc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1243, Address: 0x102e0fc */
    }
  }






} /* Line 1252, Address: 0x102e128 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1269, Address: 0x102e150 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1280, Address: 0x102e17c */

  if (*pScrFlag & 1) { /* Line 1282, Address: 0x102e184 */
    *pScrFlag &= 254; /* Line 1283, Address: 0x102e19c */
  } /* Line 1284, Address: 0x102e1b0 */
  else {
    *pScrFlag &= 254; /* Line 1286, Address: 0x102e1b8 */

    if (*pScrFlag & 2) { /* Line 1288, Address: 0x102e1cc */
      *pScrFlag &= 253; /* Line 1289, Address: 0x102e1e4 */
      lD4.w.l = 224; /* Line 1290, Address: 0x102e1f8 */
    } /* Line 1291, Address: 0x102e200 */
    else {
      *pScrFlag &= 253; /* Line 1293, Address: 0x102e208 */
      goto label1; /* Line 1294, Address: 0x102e21c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1299, Address: 0x102e224 */
  wD0 &= 127; /* Line 1300, Address: 0x102e274 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1301, Address: 0x102e27c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1307, Address: 0x102e29c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1308, Address: 0x102e2bc */
  if (wD0 != 0) { /* Line 1309, Address: 0x102e2e0 */
    wD5 = 65520; /* Line 1310, Address: 0x102e2ec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1311, Address: 0x102e2f4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1313, Address: 0x102e314 */



  } /* Line 1317, Address: 0x102e340 */
  else {

    wD5 = 0; /* Line 1320, Address: 0x102e348 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1321, Address: 0x102e34c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1325, Address: 0x102e36c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1332, Address: 0x102e398 */






    lD4.l = -16; /* Line 1339, Address: 0x102e3ac */
    wD5 = 65520; /* Line 1340, Address: 0x102e3b4 */
    if (*pScrFlag & 168) { /* Line 1341, Address: 0x102e3bc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1342, Address: 0x102e3d4 */
      wD5 = 320; /* Line 1343, Address: 0x102e3f4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1347, Address: 0x102e3fc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1349, Address: 0x102e42c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1350, Address: 0x102e438 */



    for (i = 0; i < 16; ++i) { /* Line 1354, Address: 0x102e448 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1355, Address: 0x102e454 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1356, Address: 0x102e474 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1357, Address: 0x102e4ac */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1358, Address: 0x102e4cc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1360, Address: 0x102e4f0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1363, Address: 0x102e514 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1365, Address: 0x102e534 */
      }
      lD4.w.l += 16; /* Line 1367, Address: 0x102e548 */
    } /* Line 1368, Address: 0x102e554 */
    *pScrFlag = 0; /* Line 1369, Address: 0x102e564 */
  }
} /* Line 1371, Address: 0x102e56c */





void scrollwrtc() {} /* Line 1377, Address: 0x102e5a0 */




void scrollwrtz() {} /* Line 1382, Address: 0x102e5b0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1400, Address: 0x102e5c0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1413, Address: 0x102e5e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1416, Address: 0x102e608 */
    pTilePoint->x += 2; /* Line 1417, Address: 0x102e61c */
    if (pTilePoint->x >= 64) { /* Line 1418, Address: 0x102e630 */
      pTilePoint->x -= 64; /* Line 1419, Address: 0x102e644 */
    }
    xOffs += 16; /* Line 1421, Address: 0x102e658 */
  } while (--lpcnt >= 0); /* Line 1422, Address: 0x102e664 */
} /* Line 1423, Address: 0x102e678 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1427, Address: 0x102e690 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1431, Address: 0x102e6b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1434, Address: 0x102e6d8 */
    pTilePoint->x += 2; /* Line 1435, Address: 0x102e6ec */
    if (pTilePoint->x >= 64) { /* Line 1436, Address: 0x102e700 */
      pTilePoint->x -= 64; /* Line 1437, Address: 0x102e714 */
    }
    xOffs += 16; /* Line 1439, Address: 0x102e728 */
  } while (--lpcnt >= 0); /* Line 1440, Address: 0x102e734 */
} /* Line 1441, Address: 0x102e748 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1461, Address: 0x102e760 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1465, Address: 0x102e788 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1468, Address: 0x102e7a8 */
    pTilePoint->y += 2; /* Line 1469, Address: 0x102e7bc */
    if (pTilePoint->y >= 32) { /* Line 1470, Address: 0x102e7cc */
      pTilePoint->y -= 32; /* Line 1471, Address: 0x102e7e0 */
    }
    yOffs += 16; /* Line 1473, Address: 0x102e7f0 */
  } while (--lpcnt >= 0); /* Line 1474, Address: 0x102e7fc */
} /* Line 1475, Address: 0x102e810 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1494, Address: 0x102e820 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1500, Address: 0x102e854 */

    base = 1; /* Line 1502, Address: 0x102e864 */
  } /* Line 1503, Address: 0x102e868 */
  else if (VramBase == 16384) { /* Line 1504, Address: 0x102e870 */

    base = 0; /* Line 1506, Address: 0x102e880 */
  }
  x = pTilePoint->x; /* Line 1508, Address: 0x102e884 */
  y = pTilePoint->y; /* Line 1509, Address: 0x102e88c */


  frip = BlkIndex & 6144; /* Line 1512, Address: 0x102e894 */
  BlkIndex &= 1023; /* Line 1513, Address: 0x102e89c */
  if (frip == 6144) { /* Line 1514, Address: 0x102e8a8 */

    p0 = 3, p1 = 2; /* Line 1516, Address: 0x102e8b4 */
    p2 = 1, p3 = 0; /* Line 1517, Address: 0x102e8bc */
  } /* Line 1518, Address: 0x102e8c4 */
  else if (frip & 4096) { /* Line 1519, Address: 0x102e8cc */

    p0 = 2, p1 = 3; /* Line 1521, Address: 0x102e8d8 */
    p2 = 0, p3 = 1; /* Line 1522, Address: 0x102e8e0 */
  } /* Line 1523, Address: 0x102e8e8 */
  else if (frip & 2048) { /* Line 1524, Address: 0x102e8f0 */

    p0 = 1, p1 = 0; /* Line 1526, Address: 0x102e8fc */
    p2 = 3, p3 = 2; /* Line 1527, Address: 0x102e904 */
  } /* Line 1528, Address: 0x102e90c */
  else {

    p0 = 0, p1 = 1; /* Line 1531, Address: 0x102e914 */
    p2 = 2, p3 = 3; /* Line 1532, Address: 0x102e91c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1535, Address: 0x102e924 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1536, Address: 0x102e968 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1537, Address: 0x102e9ac */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1538, Address: 0x102e9f0 */

} /* Line 1540, Address: 0x102ea34 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1557, Address: 0x102ea70 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1558, Address: 0x102ea90 */
} /* Line 1559, Address: 0x102eab0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1561, Address: 0x102eac0 */
  wH_posiw = 0; /* Line 1562, Address: 0x102eae0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1563, Address: 0x102eae4 */
} /* Line 1564, Address: 0x102eb04 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1571, Address: 0x102eb20 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1577, Address: 0x102eb50 */
  yOffs += wV_posiw; /* Line 1578, Address: 0x102eb60 */





  if ((short)xOffs < 0) /* Line 1584, Address: 0x102eb70 */
    xOffs = 0; /* Line 1585, Address: 0x102eb8c */
  if ((short)yOffs < 0) /* Line 1586, Address: 0x102eb90 */
    yOffs = 0; /* Line 1587, Address: 0x102ebac */
  if ((short)xOffs >= 16384) /* Line 1588, Address: 0x102ebb0 */
    xOffs = 16383; /* Line 1589, Address: 0x102ebd0 */
  if ((short)yOffs >= 2048) /* Line 1590, Address: 0x102ebd8 */
    yOffs = 2047; /* Line 1591, Address: 0x102ebf8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1592, Address: 0x102ec00 */
  if (i < 0) i = 0; /* Line 1593, Address: 0x102ec48 */

  ScreenNo = pMapWk[i] & 127; /* Line 1595, Address: 0x102ec54 */

  if (ScreenNo) { /* Line 1597, Address: 0x102ec70 */




    xOffs &= 32767; /* Line 1602, Address: 0x102ec78 */
    yOffs &= 32767; /* Line 1603, Address: 0x102ec84 */


    xBlk = xOffs; /* Line 1606, Address: 0x102ec90 */
    xBlk %= 256; /* Line 1607, Address: 0x102ec98 */
    xBlk /= 16; /* Line 1608, Address: 0x102ecb8 */
    yBlk = yOffs; /* Line 1609, Address: 0x102ecd4 */
    yBlk %= 256; /* Line 1610, Address: 0x102ecdc */
    yBlk /= 16; /* Line 1611, Address: 0x102ecfc */

    lpw = pmapwk; /* Line 1613, Address: 0x102ed18 */
    lpw += xBlk; /* Line 1614, Address: 0x102ed20 */
    lpw += yBlk * 16; /* Line 1615, Address: 0x102ed28 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1616, Address: 0x102ed34 */
    *pIndex = *lpw; /* Line 1617, Address: 0x102ed4c */

    return 1; /* Line 1619, Address: 0x102ed5c */
  }

  *pIndex = 0; /* Line 1622, Address: 0x102ed68 */
  return 0; /* Line 1623, Address: 0x102ed70 */
} /* Line 1624, Address: 0x102ed74 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1644, Address: 0x102eda0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1652, Address: 0x102edc8 */
  if (ScreenNo) { /* Line 1653, Address: 0x102ee2c */





    xBlk = xOffs; /* Line 1659, Address: 0x102ee34 */
    xBlk %= 256; /* Line 1660, Address: 0x102ee3c */
    xBlk /= 16; /* Line 1661, Address: 0x102ee5c */
    yBlk = yOffs; /* Line 1662, Address: 0x102ee78 */
    yBlk %= 256; /* Line 1663, Address: 0x102ee80 */
    yBlk /= 16; /* Line 1664, Address: 0x102eea0 */


    lpw = pmapwk; /* Line 1667, Address: 0x102eebc */
    lpw += xBlk; /* Line 1668, Address: 0x102eec4 */
    lpw += yBlk * 16; /* Line 1669, Address: 0x102eecc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1670, Address: 0x102eed8 */
    *ppBlockNo = lpw; /* Line 1671, Address: 0x102eef0 */
    *pIndex = *lpw; /* Line 1672, Address: 0x102eef8 */




    return 1; /* Line 1677, Address: 0x102ef08 */
  }

  *pIndex = 0; /* Line 1680, Address: 0x102ef14 */
  return 0; /* Line 1681, Address: 0x102ef1c */
} /* Line 1682, Address: 0x102ef20 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1696, Address: 0x102ef40 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1703, Address: 0x102ef5c */
  pMapWk = (unsigned char*)mapwka; /* Line 1704, Address: 0x102ef60 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1705, Address: 0x102ef68 */
    *pBlockIndex = BlockNo; /* Line 1706, Address: 0x102ef8c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1707, Address: 0x102ef98 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1708, Address: 0x102efb0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1709, Address: 0x102efc4 */
    }
  }


} /* Line 1714, Address: 0x102efdc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1728, Address: 0x102f000 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1729, Address: 0x102f00c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1730, Address: 0x102f038 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1731, Address: 0x102f084 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1732, Address: 0x102f0b0 */

          return 0; /* Line 1734, Address: 0x102f0fc */
        }
      }
    }
  }

  return 1; /* Line 1740, Address: 0x102f108 */
} /* Line 1741, Address: 0x102f10c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1758, Address: 0x102f120 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1759, Address: 0x102f13c */

} /* Line 1761, Address: 0x102f158 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1763, Address: 0x102f170 */
  wH_posiw = 0; /* Line 1764, Address: 0x102f18c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1765, Address: 0x102f190 */

} /* Line 1767, Address: 0x102f1ac */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1769, Address: 0x102f1c0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1770, Address: 0x102f1d4 */

} /* Line 1772, Address: 0x102f1f0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1774, Address: 0x102f200 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x102f21c */

} /* Line 1777, Address: 0x102f238 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102f250 */
  xOffs += wH_posiw; /* Line 1780, Address: 0x102f268 */
  yOffs += wV_posiw; /* Line 1781, Address: 0x102f278 */
  yOffs &= 240; /* Line 1782, Address: 0x102f288 */
  xOffs &= 496; /* Line 1783, Address: 0x102f294 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1785, Address: 0x102f2a0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1786, Address: 0x102f2cc */


} /* Line 1789, Address: 0x102f2f8 */















void mapwrt() { /* Line 1805, Address: 0x102f310 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1812, Address: 0x102f328 */
  wV_posiw = scra_v_posit.w.h; /* Line 1813, Address: 0x102f334 */
  pMapWk = (unsigned char*)mapwka; /* Line 1814, Address: 0x102f340 */
  VramBase = 16384; /* Line 1815, Address: 0x102f348 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1816, Address: 0x102f34c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1820, Address: 0x102f364 */
  VramBase = 24576; /* Line 1821, Address: 0x102f36c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1822, Address: 0x102f370 */

} /* Line 1824, Address: 0x102f380 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1827, Address: 0x102f3a0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1828, Address: 0x102f3b8 */
} /* Line 1829, Address: 0x102f3d8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1834, Address: 0x102f3f0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1838, Address: 0x102f410 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1841, Address: 0x102f42c */



    wD4 += 16; /* Line 1845, Address: 0x102f454 */
  } while ((short)--wD6 >= 0); /* Line 1846, Address: 0x102f460 */

} /* Line 1848, Address: 0x102f488 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1854, Address: 0x102f4a0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1857, Address: 0x102f4bc */
  wD6 = 15; /* Line 1858, Address: 0x102f4c4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1861, Address: 0x102f4cc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1863, Address: 0x102f4f0 */
    wD4 += 16; /* Line 1864, Address: 0x102f510 */
  } while ((short)--wD6 >= 0); /* Line 1865, Address: 0x102f518 */
} /* Line 1866, Address: 0x102f53c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1892, Address: 0x102f560 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1897, Address: 0x102f588 */
  wD0 = pWrttbl[wD0]; /* Line 1898, Address: 0x102f598 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1900, Address: 0x102f5b4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1901, Address: 0x102f5d8 */
  if (wD0) { /* Line 1902, Address: 0x102f600 */
    wD5 = 65520; /* Line 1903, Address: 0x102f60c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1904, Address: 0x102f614 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1907, Address: 0x102f630 */



  } /* Line 1911, Address: 0x102f658 */
  else {

    wD5 = 0; /* Line 1914, Address: 0x102f660 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1915, Address: 0x102f664 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1919, Address: 0x102f680 */
  }





} /* Line 1926, Address: 0x102f6a8 */










void mapinit() { /* Line 1937, Address: 0x102f6d0 */

  colorset2(mapinittbl.colorno2); /* Line 1939, Address: 0x102f6d8 */
  colorset(mapinittbl.colorno2); /* Line 1940, Address: 0x102f6ec */


  if (play_start & 2) divdevset(); /* Line 1943, Address: 0x102f700 */
} /* Line 1944, Address: 0x102f720 */




void mapset() {} /* Line 1949, Address: 0x102f730 */



void divdevset() {} /* Line 1953, Address: 0x102f740 */



void enecginit() {} /* Line 1957, Address: 0x102f750 */
