#include "..\EQU.H"
#include "SCR62A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL6A.H"

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
  0, 0, 0, 0, 0, 0, 6, 6, 6, 6,
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































































































































void scr_set() { /* Line 190, Address: 0x102be20 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x102be2c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x102be40 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x102be54 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x102be5c */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x102be64 */
  ++pScrTbl; /* Line 199, Address: 0x102be70 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x102be74 */
  ++pScrTbl; /* Line 201, Address: 0x102be88 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x102be8c */
  ++pScrTbl; /* Line 203, Address: 0x102bea0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x102bea4 */
  ++pScrTbl; /* Line 205, Address: 0x102beb8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x102bebc */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x102bed0 */
  ++pScrTbl; /* Line 208, Address: 0x102bef0 */
  scra_h_count = 16; /* Line 209, Address: 0x102bef4 */
  scra_v_count = 16; /* Line 210, Address: 0x102bf00 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x102bf0c */
  scra_hline = 160; /* Line 213, Address: 0x102bf18 */

  playposiset(); /* Line 215, Address: 0x102bf24 */
} /* Line 216, Address: 0x102bf2c */





































void playposiset() { /* Line 254, Address: 0x102bf40 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 257, Address: 0x102bf54 */
    playload(); /* Line 258, Address: 0x102bf64 */
    xwk = actwk[0].xposi.w.h; /* Line 259, Address: 0x102bf6c */

    if (actwk[0].yposi.w.h > 0) { /* Line 261, Address: 0x102bf7c */
      ywk = actwk[0].yposi.w.h; /* Line 262, Address: 0x102bf94 */
    } else { /* Line 263, Address: 0x102bfa4 */
      ywk = 0; /* Line 264, Address: 0x102bfac */
    }
  } /* Line 266, Address: 0x102bfb0 */
  else {












    pPositbl = playpositbl[0]; /* Line 280, Address: 0x102bfb8 */
    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 281, Address: 0x102bfc0 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 282, Address: 0x102bfd4 */
  }


  if (xwk > 160) { /* Line 286, Address: 0x102bfe8 */
    xwk -= 160; /* Line 287, Address: 0x102bffc */
  } else { /* Line 288, Address: 0x102c008 */
    xwk = 0; /* Line 289, Address: 0x102c010 */
  }


  if (xwk > scralim_right) { /* Line 293, Address: 0x102c014 */
    xwk = scralim_right; /* Line 294, Address: 0x102c038 */
  }


  scra_h_posit.w.h = xwk; /* Line 298, Address: 0x102c048 */

  if (ywk > 96) { /* Line 300, Address: 0x102c050 */
    ywk -= 96; /* Line 301, Address: 0x102c064 */
  } else { /* Line 302, Address: 0x102c070 */
    ywk = 0; /* Line 303, Address: 0x102c078 */
  }


  if (ywk > scralim_down) { /* Line 307, Address: 0x102c07c */
    ywk = scralim_down; /* Line 308, Address: 0x102c0a0 */
  }


  scra_v_posit.w.h = ywk; /* Line 312, Address: 0x102c0b0 */

  scrbinit(xwk, ywk); /* Line 314, Address: 0x102c0b8 */


  loopmapno = playmapnotbl[0]; /* Line 317, Address: 0x102c0c8 */
  loopmapno2 = playmapnotbl[1]; /* Line 318, Address: 0x102c0d8 */
  ballmapno = playmapnotbl[2]; /* Line 319, Address: 0x102c0e8 */
  ballmapno2 = playmapnotbl[3]; /* Line 320, Address: 0x102c0f8 */
} /* Line 321, Address: 0x102c108 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 342, Address: 0x102c130 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 345, Address: 0x102c13c */
  lYwk.w.l = 0; /* Line 346, Address: 0x102c144 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 348, Address: 0x102c148 */
  scrb_v_posit.l = lYwk.l; /* Line 349, Address: 0x102c154 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 350, Address: 0x102c160 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 351, Address: 0x102c16c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 353, Address: 0x102c178 */
  scrc_h_posit.w.h = sXpos; /* Line 354, Address: 0x102c194 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 356, Address: 0x102c1a0 */
  scrz_h_posit.w.h = sXpos; /* Line 357, Address: 0x102c1bc */

  sXpos = (unsigned short)sXpos >> 2; /* Line 359, Address: 0x102c1c8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 360, Address: 0x102c1e4 */
} /* Line 361, Address: 0x102c208 */















void scroll() { /* Line 377, Address: 0x102c220 */
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

  if (scroll_start.b.h) return; /* Line 389, Address: 0x102c23c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 394, Address: 0x102c24c */

  scrchk(); /* Line 396, Address: 0x102c278 */

  scroll_h(); /* Line 398, Address: 0x102c280 */
  scroll_v(); /* Line 399, Address: 0x102c288 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 401, Address: 0x102c290 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 402, Address: 0x102c2a0 */


  lXwk = scra_hz << 6; /* Line 405, Address: 0x102c2b0 */
  scrollz_h(lXwk, 6); /* Line 406, Address: 0x102c2c4 */

  lXwk = scra_hz << 7; /* Line 408, Address: 0x102c2d4 */
  scrollc_h(lXwk, 4); /* Line 409, Address: 0x102c2e8 */

  lXwk = (scra_hz << 4) * 3; /* Line 411, Address: 0x102c2f8 */
  scrollb_h(lXwk, 2); /* Line 412, Address: 0x102c314 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 414, Address: 0x102c324 */


  scrollb_v(lYwk); /* Line 417, Address: 0x102c338 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 419, Address: 0x102c348 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 421, Address: 0x102c370 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 422, Address: 0x102c3a8 */

  psHscw = hscrollwork; /* Line 424, Address: 0x102c3bc */

  z61aline(&psHscw); /* Line 426, Address: 0x102c3c8 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 428, Address: 0x102c3d4 */
  for (i = 0; i < 20; ++i) { /* Line 429, Address: 0x102c3f4 */

    *psHscw++ = ldwk.w.l; /* Line 431, Address: 0x102c400 */
  } /* Line 432, Address: 0x102c414 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 434, Address: 0x102c424 */
  for (i = 0; i < 46; ++i) { /* Line 435, Address: 0x102c444 */

    *psHscw++ = ldwk.w.l; /* Line 437, Address: 0x102c450 */
  } /* Line 438, Address: 0x102c464 */

  pHscrbuf = lphscrollbuff; /* Line 440, Address: 0x102c474 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 441, Address: 0x102c480 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 442, Address: 0x102c4b0 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 443, Address: 0x102c4e0 */
} /* Line 444, Address: 0x102c4fc */













static void z61aline(short** ppHscw) { /* Line 458, Address: 0x102c520 */
  char z81ascrtbl[10] = { /* Line 459, Address: 0x102c544 */
    5, 3, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk;

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 466, Address: 0x102c578 */
  radwk = 0; /* Line 467, Address: 0x102c59c */
  sXwk = scrb_h_posit.w.h; /* Line 468, Address: 0x102c5a0 */

  *ppHscw += 30; /* Line 470, Address: 0x102c5b0 */

  for (i = 9; i >= 0; --i) { /* Line 472, Address: 0x102c5c4 */

    sinset(radwk, &sinwk, &coswk); /* Line 474, Address: 0x102c5d0 */
    hwk = -(sXwk + (short)((unsigned short)((256 - coswk) * lXwk) >> 8)); /* Line 475, Address: 0x102c5e4 */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 476, Address: 0x102c638 */

      --*ppHscw; /* Line 478, Address: 0x102c650 */
      **ppHscw = hwk; /* Line 479, Address: 0x102c664 */
    } /* Line 480, Address: 0x102c670 */

    radwk += 6; /* Line 482, Address: 0x102c67c */
  } /* Line 483, Address: 0x102c688 */

  *ppHscw += 30; /* Line 485, Address: 0x102c694 */
} /* Line 486, Address: 0x102c6a8 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 507, Address: 0x102c6d0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 511, Address: 0x102c6ec */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 512, Address: 0x102c6f0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 514, Address: 0x102c710 */
    ldwk.w.l = *pHscrwk; /* Line 515, Address: 0x102c72c */
    ++pHscrwk; /* Line 516, Address: 0x102c738 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 518, Address: 0x102c744 */
      (*pHscrbuf)->l = ldwk.l; /* Line 519, Address: 0x102c74c */
    } /* Line 520, Address: 0x102c75c */
  } /* Line 521, Address: 0x102c780 */
} /* Line 522, Address: 0x102c7a0 */









































































































static void scrollb_v(short yPos) { /* Line 628, Address: 0x102c7c0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 631, Address: 0x102c7d0 */
  scrb_v_posit.w.h = yPos; /* Line 632, Address: 0x102c7e0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 633, Address: 0x102c7ec */

  if (!ywk) { /* Line 635, Address: 0x102c824 */
    scrb_v_count ^= 16; /* Line 636, Address: 0x102c82c */
    if (yPos - ysv < 0) { /* Line 637, Address: 0x102c840 */
      scrflagb.b.h |= 1; /* Line 638, Address: 0x102c860 */
    } /* Line 639, Address: 0x102c874 */
    else {
      scrflagb.b.h |= 2; /* Line 641, Address: 0x102c87c */
    }
  }


} /* Line 646, Address: 0x102c890 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 664, Address: 0x102c8b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 668, Address: 0x102c8c4 */
  lXwk = lXsv + xoffs; /* Line 669, Address: 0x102c8cc */
  scrb_h_posit.l = lXwk; /* Line 670, Address: 0x102c8d4 */
  ldXwk.l = lXwk; /* Line 671, Address: 0x102c8dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 672, Address: 0x102c8e0 */
  ldXwk.w.l &= 16; /* Line 673, Address: 0x102c904 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 674, Address: 0x102c910 */

  if (!ldXwk.b.b4) { /* Line 676, Address: 0x102c92c */
    scrb_h_count ^= 16; /* Line 677, Address: 0x102c938 */
    if (lXwk - lXsv < 0) { /* Line 678, Address: 0x102c94c */
      scrflagb.b.h |= 1 << flgbit; /* Line 679, Address: 0x102c958 */
    } /* Line 680, Address: 0x102c97c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 682, Address: 0x102c984 */
    }
  }


} /* Line 687, Address: 0x102c9ac */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 705, Address: 0x102c9c0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 709, Address: 0x102c9d4 */
  lXwk = lXsv + xoffs; /* Line 710, Address: 0x102c9dc */
  scrc_h_posit.l = lXwk; /* Line 711, Address: 0x102c9e4 */
  ldXwk.l = lXwk; /* Line 712, Address: 0x102c9ec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 713, Address: 0x102c9f0 */
  ldXwk.w.l &= 16; /* Line 714, Address: 0x102ca14 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 715, Address: 0x102ca20 */

  if (!ldXwk.b.b4) { /* Line 717, Address: 0x102ca3c */
    scrc_h_count ^= 16; /* Line 718, Address: 0x102ca48 */
    if (lXwk - lXsv < 0) { /* Line 719, Address: 0x102ca5c */
      scrflagc.b.h |= 1 << flgbit; /* Line 720, Address: 0x102ca68 */
    } /* Line 721, Address: 0x102ca8c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 723, Address: 0x102ca94 */
    }
  }


} /* Line 728, Address: 0x102cabc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 746, Address: 0x102cad0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 750, Address: 0x102cae4 */
  lXwk = lXsv + xoffs; /* Line 751, Address: 0x102caec */
  scrz_h_posit.l = lXwk; /* Line 752, Address: 0x102caf4 */
  ldXwk.l = lXwk; /* Line 753, Address: 0x102cafc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 754, Address: 0x102cb00 */
  ldXwk.w.l &= 16; /* Line 755, Address: 0x102cb24 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 756, Address: 0x102cb30 */

  if (!ldXwk.b.b4) { /* Line 758, Address: 0x102cb4c */
    scrz_h_count ^= 16; /* Line 759, Address: 0x102cb58 */
    if (lXwk - lXsv < 0) { /* Line 760, Address: 0x102cb6c */
      scrflagz.b.h |= 1 << flgbit; /* Line 761, Address: 0x102cb78 */
    } /* Line 762, Address: 0x102cb9c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 764, Address: 0x102cba4 */
    }
  }


} /* Line 769, Address: 0x102cbcc */














static void scroll_h() { /* Line 784, Address: 0x102cbe0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 788, Address: 0x102cbf0 */

  scrh_move(); /* Line 790, Address: 0x102cc00 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 791, Address: 0x102cc08 */
  if (!bXwk) { /* Line 792, Address: 0x102cc3c */
    scra_h_count ^= 16; /* Line 793, Address: 0x102cc44 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 794, Address: 0x102cc58 */
      scrflaga.b.h |= 4; /* Line 795, Address: 0x102cc7c */
    } else { /* Line 796, Address: 0x102cc90 */
      scrflaga.b.h |= 8; /* Line 797, Address: 0x102cc98 */
    }
  }


} /* Line 802, Address: 0x102ccac */
















static void scrh_move() { /* Line 819, Address: 0x102ccd0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 822, Address: 0x102ccd8 */
  if (xwk == 0) { /* Line 823, Address: 0x102cd20 */

    scra_hz = 0; /* Line 825, Address: 0x102cd30 */
    return; /* Line 826, Address: 0x102cd38 */
  } else if (xwk < 0) { /* Line 827, Address: 0x102cd40 */

    if (xwk < -16) { /* Line 829, Address: 0x102cd50 */
      xwk = -16; /* Line 830, Address: 0x102cd64 */
    }


    xwk += scra_h_posit.w.h; /* Line 834, Address: 0x102cd70 */
    if (xwk < scralim_left) { /* Line 835, Address: 0x102cd84 */
      xwk = scralim_left; /* Line 836, Address: 0x102cda8 */
    }
  } /* Line 838, Address: 0x102cdb8 */
  else {
    if (xwk > 16) { /* Line 840, Address: 0x102cdc0 */
      xwk = 16; /* Line 841, Address: 0x102cdd4 */
    }


    xwk += scra_h_posit.w.h; /* Line 845, Address: 0x102cde0 */
    if (xwk > scralim_right) { /* Line 846, Address: 0x102cdf4 */
      xwk = scralim_right; /* Line 847, Address: 0x102ce18 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 852, Address: 0x102ce28 */
  scra_h_posit.w.h = xwk; /* Line 853, Address: 0x102ce58 */
} /* Line 854, Address: 0x102ce60 */














static void scroll_v() { /* Line 869, Address: 0x102ce70 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 872, Address: 0x102ce7c */
  if (actwk[0].cddat & 4) { /* Line 873, Address: 0x102ceb0 */
    ywk -= 5; /* Line 874, Address: 0x102cec8 */
  }


  if (actwk[0].cddat & 2) { /* Line 878, Address: 0x102ced4 */
    ywk += 32; /* Line 879, Address: 0x102ceec */
    if (ywk < scra_vline) { /* Line 880, Address: 0x102cef8 */
      ywk -= scra_vline; /* Line 881, Address: 0x102cf1c */
      sv_move_main2(ywk); /* Line 882, Address: 0x102cf30 */
      return; /* Line 883, Address: 0x102cf3c */
    } else if (ywk >= scra_vline + 64) { /* Line 884, Address: 0x102cf44 */
      ywk -= scra_vline + 64; /* Line 885, Address: 0x102cf6c */
      sv_move_main2(ywk); /* Line 886, Address: 0x102cf94 */
      return; /* Line 887, Address: 0x102cfa0 */
    }
    ywk -= scra_vline + 64; /* Line 889, Address: 0x102cfa8 */
    if (!limmoveflag) goto label1; /* Line 890, Address: 0x102cfd0 */
    sv_move_sub2(); /* Line 891, Address: 0x102cfe0 */
    return; /* Line 892, Address: 0x102cfe8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 897, Address: 0x102cff0 */
    sv_move_main(ywk); /* Line 898, Address: 0x102d01c */
    return; /* Line 899, Address: 0x102d028 */
  } else if (!limmoveflag) goto label1; /* Line 900, Address: 0x102d030 */
  sv_move_sub2(); /* Line 901, Address: 0x102d040 */
  return; /* Line 902, Address: 0x102d048 */



label1:
  scra_vz = 0; /* Line 907, Address: 0x102d050 */
} /* Line 908, Address: 0x102d058 */













static void sv_move_main(short yPos) { /* Line 922, Address: 0x102d070 */
  short spdwk;

  if (scra_vline == 96) { /* Line 925, Address: 0x102d080 */
    if (actwk[0].mspeed.w < 0) { /* Line 926, Address: 0x102d09c */
      spdwk = -actwk[0].mspeed.w; /* Line 927, Address: 0x102d0b4 */
    } else { /* Line 928, Address: 0x102d0d8 */
      spdwk = actwk[0].mspeed.w; /* Line 929, Address: 0x102d0e0 */
    }


    if (spdwk >= 2048) { /* Line 933, Address: 0x102d0f0 */
      sv_move_main2(yPos); /* Line 934, Address: 0x102d104 */
    } /* Line 935, Address: 0x102d110 */
    else {

      if (yPos > 6) { /* Line 938, Address: 0x102d118 */
        sv_move_plus(1536); /* Line 939, Address: 0x102d130 */
      } else if (yPos < -6) { /* Line 940, Address: 0x102d13c */
        sv_move_minus(1536); /* Line 941, Address: 0x102d15c */
      } /* Line 942, Address: 0x102d168 */
      else sv_move_sub(yPos); /* Line 943, Address: 0x102d170 */
    }
  } /* Line 945, Address: 0x102d17c */
  else {
    if (yPos > 2) { /* Line 947, Address: 0x102d184 */
      sv_move_plus(512); /* Line 948, Address: 0x102d19c */
    } else if (yPos < -2) { /* Line 949, Address: 0x102d1a8 */
      sv_move_minus(512); /* Line 950, Address: 0x102d1c8 */
    } /* Line 951, Address: 0x102d1d4 */
    else sv_move_sub(yPos); /* Line 952, Address: 0x102d1dc */
  }

} /* Line 955, Address: 0x102d1e8 */













static void sv_move_main2(short yPos) { /* Line 969, Address: 0x102d200 */
  short spdwk;

  spdwk = 4096; /* Line 972, Address: 0x102d210 */

  if (yPos > 16) { /* Line 974, Address: 0x102d21c */
    sv_move_plus(spdwk); /* Line 975, Address: 0x102d234 */
  } else if (yPos < -16) { /* Line 976, Address: 0x102d240 */
    sv_move_minus(spdwk); /* Line 977, Address: 0x102d260 */
  } else { /* Line 978, Address: 0x102d26c */
    sv_move_sub(yPos); /* Line 979, Address: 0x102d274 */
  }
} /* Line 981, Address: 0x102d280 */














static void sv_move_sub(short yPos) { /* Line 996, Address: 0x102d2a0 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 999, Address: 0x102d2ac */
  if (yPos < 0) { /* Line 1000, Address: 0x102d2d8 */
    scrv_up_ch(lSpd); /* Line 1001, Address: 0x102d2ec */
  } else { /* Line 1002, Address: 0x102d2f8 */
    scrv_down_ch(lSpd); /* Line 1003, Address: 0x102d300 */
  }
} /* Line 1005, Address: 0x102d30c */



static void sv_move_sub2() { /* Line 1009, Address: 0x102d320 */
  limmoveflag = 0; /* Line 1010, Address: 0x102d328 */

  sv_move_sub(0); /* Line 1012, Address: 0x102d330 */
} /* Line 1013, Address: 0x102d33c */













static void sv_move_minus(short speed) { /* Line 1027, Address: 0x102d350 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1030, Address: 0x102d35c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1031, Address: 0x102d380 */
  scrv_up_ch(lSpd); /* Line 1032, Address: 0x102d3a4 */
} /* Line 1033, Address: 0x102d3b0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1048, Address: 0x102d3c0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1049, Address: 0x102d3cc */
    if (lSpd.w.l > -256) { /* Line 1050, Address: 0x102d3f4 */

      lSpd.w.l = scralim_up; /* Line 1052, Address: 0x102d40c */
    } else { /* Line 1053, Address: 0x102d418 */
      lSpd.w.l &= 2047; /* Line 1054, Address: 0x102d420 */
      actwk[0].yposi.w.l &= 2047; /* Line 1055, Address: 0x102d42c */
      scra_v_posit.w.h &= 2047; /* Line 1056, Address: 0x102d440 */
      scrb_v_posit.w.h &= 1023; /* Line 1057, Address: 0x102d454 */
    }
  }

  scrv_move(lSpd); /* Line 1061, Address: 0x102d468 */
} /* Line 1062, Address: 0x102d474 */













static void sv_move_plus(short sSpd) { /* Line 1076, Address: 0x102d490 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1079, Address: 0x102d49c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1080, Address: 0x102d4bc */
  scrv_down_ch(lSpd); /* Line 1081, Address: 0x102d4e0 */
} /* Line 1082, Address: 0x102d4ec */














static void scrv_down_ch(int_union lSpd) { /* Line 1097, Address: 0x102d500 */
  if (lSpd.w.l >= scralim_down) { /* Line 1098, Address: 0x102d50c */
    if (lSpd.w.l < 2048) { /* Line 1099, Address: 0x102d534 */

      lSpd.w.l = scralim_down; /* Line 1101, Address: 0x102d54c */
    } else { /* Line 1102, Address: 0x102d558 */
      lSpd.w.l -= 2048; /* Line 1103, Address: 0x102d560 */
      actwk[0].yposi.w.l &= 2047; /* Line 1104, Address: 0x102d56c */
      scra_v_posit.w.h -= 2048; /* Line 1105, Address: 0x102d580 */
      scrb_v_posit.w.h &= 1023; /* Line 1106, Address: 0x102d594 */
    }
  }

  scrv_move(lSpd); /* Line 1110, Address: 0x102d5a8 */
} /* Line 1111, Address: 0x102d5b4 */
















static void scrv_move(int_union lSpd) { /* Line 1128, Address: 0x102d5d0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1132, Address: 0x102d5e0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1133, Address: 0x102d5f0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1134, Address: 0x102d614 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1135, Address: 0x102d628 */
  scra_vz = spdwk.w.l; /* Line 1136, Address: 0x102d640 */

  scra_v_posit.l = lSpd.l; /* Line 1138, Address: 0x102d64c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1140, Address: 0x102d658 */
  if (!ywk) { /* Line 1141, Address: 0x102d694 */
    scra_v_count ^= 16; /* Line 1142, Address: 0x102d69c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1143, Address: 0x102d6b0 */
    if (ywk < 0) { /* Line 1144, Address: 0x102d6dc */
      scrflaga.b.h |= 1; /* Line 1145, Address: 0x102d6ec */
    } else { /* Line 1146, Address: 0x102d700 */
      scrflaga.b.h |= 2; /* Line 1147, Address: 0x102d708 */
    }
  }


} /* Line 1152, Address: 0x102d71c */

















void scrollwrt() { /* Line 1170, Address: 0x102d730 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1179, Address: 0x102d750 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1180, Address: 0x102d754 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1181, Address: 0x102d760 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1182, Address: 0x102d76c */
  pScrFlag = &scrflagbw.b.h; /* Line 1183, Address: 0x102d774 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1184, Address: 0x102d77c */

  VramBase = 16384; /* Line 1186, Address: 0x102d790 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1187, Address: 0x102d794 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1188, Address: 0x102d7a0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1189, Address: 0x102d7ac */
  pScrFlag = &scrflagaw.b.h; /* Line 1190, Address: 0x102d7b4 */

  if (*pScrFlag) { /* Line 1192, Address: 0x102d7bc */
    if (*pScrFlag & 1) { /* Line 1193, Address: 0x102d7c8 */
      *pScrFlag &= 254; /* Line 1194, Address: 0x102d7dc */

      lD4.l = -16; /* Line 1196, Address: 0x102d7e8 */
      wD5 = 65520; /* Line 1197, Address: 0x102d7f0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1199, Address: 0x102d7f8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1201, Address: 0x102d818 */
    }




    if (*pScrFlag & 2) { /* Line 1207, Address: 0x102d844 */
      *pScrFlag &= 253; /* Line 1208, Address: 0x102d858 */

      lD4.l = 224; /* Line 1210, Address: 0x102d864 */
      wD5 = 65520; /* Line 1211, Address: 0x102d86c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1212, Address: 0x102d874 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1214, Address: 0x102d894 */
    }




    if (*pScrFlag & 4) { /* Line 1220, Address: 0x102d8c0 */
      *pScrFlag &= 251; /* Line 1221, Address: 0x102d8d4 */

      lD4.l = -16; /* Line 1223, Address: 0x102d8e0 */
      wD5 = 65520; /* Line 1224, Address: 0x102d8e8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1225, Address: 0x102d8f0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1227, Address: 0x102d910 */
    }




    if (*pScrFlag & 8) { /* Line 1233, Address: 0x102d93c */
      *pScrFlag &= 247; /* Line 1234, Address: 0x102d950 */

      lD4.l = -16; /* Line 1236, Address: 0x102d95c */
      wD5 = 320; /* Line 1237, Address: 0x102d964 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1238, Address: 0x102d96c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1240, Address: 0x102d98c */
    }
  }






} /* Line 1249, Address: 0x102d9b8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1266, Address: 0x102d9e0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1277, Address: 0x102da0c */

  if (*pScrFlag & 1) { /* Line 1279, Address: 0x102da14 */
    *pScrFlag &= 254; /* Line 1280, Address: 0x102da2c */
  } /* Line 1281, Address: 0x102da40 */
  else {
    *pScrFlag &= 254; /* Line 1283, Address: 0x102da48 */

    if (*pScrFlag & 2) { /* Line 1285, Address: 0x102da5c */
      *pScrFlag &= 253; /* Line 1286, Address: 0x102da74 */
      lD4.w.l = 224; /* Line 1287, Address: 0x102da88 */
    } /* Line 1288, Address: 0x102da90 */
    else {
      *pScrFlag &= 253; /* Line 1290, Address: 0x102da98 */
      goto label1; /* Line 1291, Address: 0x102daac */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1296, Address: 0x102dab4 */
  wD0 &= 127; /* Line 1297, Address: 0x102db04 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1298, Address: 0x102db0c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1304, Address: 0x102db2c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1305, Address: 0x102db4c */
  if (wD0 != 0) { /* Line 1306, Address: 0x102db70 */
    wD5 = 65520; /* Line 1307, Address: 0x102db7c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1308, Address: 0x102db84 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1310, Address: 0x102dba4 */



  } /* Line 1314, Address: 0x102dbd0 */
  else {

    wD5 = 0; /* Line 1317, Address: 0x102dbd8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1318, Address: 0x102dbdc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1322, Address: 0x102dbfc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1329, Address: 0x102dc28 */






    lD4.l = -16; /* Line 1336, Address: 0x102dc3c */
    wD5 = 65520; /* Line 1337, Address: 0x102dc44 */
    if (*pScrFlag & 168) { /* Line 1338, Address: 0x102dc4c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1339, Address: 0x102dc64 */
      wD5 = 320; /* Line 1340, Address: 0x102dc84 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1344, Address: 0x102dc8c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1346, Address: 0x102dcbc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1347, Address: 0x102dcc8 */



    for (i = 0; i < 16; ++i) { /* Line 1351, Address: 0x102dcd8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1352, Address: 0x102dce4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1353, Address: 0x102dd04 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1354, Address: 0x102dd3c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1355, Address: 0x102dd5c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1357, Address: 0x102dd80 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1360, Address: 0x102dda4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1362, Address: 0x102ddc4 */
      }
      lD4.w.l += 16; /* Line 1364, Address: 0x102ddd8 */
    } /* Line 1365, Address: 0x102dde4 */
    *pScrFlag = 0; /* Line 1366, Address: 0x102ddf4 */
  }
} /* Line 1368, Address: 0x102ddfc */





void scrollwrtc() {} /* Line 1374, Address: 0x102de30 */




void scrollwrtz() {} /* Line 1379, Address: 0x102de40 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1397, Address: 0x102de50 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1410, Address: 0x102de78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1413, Address: 0x102de98 */
    pTilePoint->x += 2; /* Line 1414, Address: 0x102deac */
    if (pTilePoint->x >= 64) { /* Line 1415, Address: 0x102dec0 */
      pTilePoint->x -= 64; /* Line 1416, Address: 0x102ded4 */
    }
    xOffs += 16; /* Line 1418, Address: 0x102dee8 */
  } while (--lpcnt >= 0); /* Line 1419, Address: 0x102def4 */
} /* Line 1420, Address: 0x102df08 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1424, Address: 0x102df20 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1428, Address: 0x102df48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1431, Address: 0x102df68 */
    pTilePoint->x += 2; /* Line 1432, Address: 0x102df7c */
    if (pTilePoint->x >= 64) { /* Line 1433, Address: 0x102df90 */
      pTilePoint->x -= 64; /* Line 1434, Address: 0x102dfa4 */
    }
    xOffs += 16; /* Line 1436, Address: 0x102dfb8 */
  } while (--lpcnt >= 0); /* Line 1437, Address: 0x102dfc4 */
} /* Line 1438, Address: 0x102dfd8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1458, Address: 0x102dff0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1462, Address: 0x102e018 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1465, Address: 0x102e038 */
    pTilePoint->y += 2; /* Line 1466, Address: 0x102e04c */
    if (pTilePoint->y >= 32) { /* Line 1467, Address: 0x102e05c */
      pTilePoint->y -= 32; /* Line 1468, Address: 0x102e070 */
    }
    yOffs += 16; /* Line 1470, Address: 0x102e080 */
  } while (--lpcnt >= 0); /* Line 1471, Address: 0x102e08c */
} /* Line 1472, Address: 0x102e0a0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1491, Address: 0x102e0b0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1497, Address: 0x102e0e4 */

    base = 1; /* Line 1499, Address: 0x102e0f4 */
  } /* Line 1500, Address: 0x102e0f8 */
  else if (VramBase == 16384) { /* Line 1501, Address: 0x102e100 */

    base = 0; /* Line 1503, Address: 0x102e110 */
  }
  x = pTilePoint->x; /* Line 1505, Address: 0x102e114 */
  y = pTilePoint->y; /* Line 1506, Address: 0x102e11c */


  frip = BlkIndex & 6144; /* Line 1509, Address: 0x102e124 */
  BlkIndex &= 1023; /* Line 1510, Address: 0x102e12c */
  if (frip == 6144) { /* Line 1511, Address: 0x102e138 */

    p0 = 3, p1 = 2; /* Line 1513, Address: 0x102e144 */
    p2 = 1, p3 = 0; /* Line 1514, Address: 0x102e14c */
  } /* Line 1515, Address: 0x102e154 */
  else if (frip & 4096) { /* Line 1516, Address: 0x102e15c */

    p0 = 2, p1 = 3; /* Line 1518, Address: 0x102e168 */
    p2 = 0, p3 = 1; /* Line 1519, Address: 0x102e170 */
  } /* Line 1520, Address: 0x102e178 */
  else if (frip & 2048) { /* Line 1521, Address: 0x102e180 */

    p0 = 1, p1 = 0; /* Line 1523, Address: 0x102e18c */
    p2 = 3, p3 = 2; /* Line 1524, Address: 0x102e194 */
  } /* Line 1525, Address: 0x102e19c */
  else {

    p0 = 0, p1 = 1; /* Line 1528, Address: 0x102e1a4 */
    p2 = 2, p3 = 3; /* Line 1529, Address: 0x102e1ac */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1532, Address: 0x102e1b4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1533, Address: 0x102e1f8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1534, Address: 0x102e23c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1535, Address: 0x102e280 */

} /* Line 1537, Address: 0x102e2c4 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1554, Address: 0x102e300 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1555, Address: 0x102e320 */
} /* Line 1556, Address: 0x102e340 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1558, Address: 0x102e350 */
  wH_posiw = 0; /* Line 1559, Address: 0x102e370 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1560, Address: 0x102e374 */
} /* Line 1561, Address: 0x102e394 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1568, Address: 0x102e3b0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1574, Address: 0x102e3e0 */
  yOffs += wV_posiw; /* Line 1575, Address: 0x102e3f0 */





  if ((short)xOffs < 0) /* Line 1581, Address: 0x102e400 */
    xOffs = 0; /* Line 1582, Address: 0x102e41c */
  if ((short)yOffs < 0) /* Line 1583, Address: 0x102e420 */
    yOffs = 0; /* Line 1584, Address: 0x102e43c */
  if ((short)xOffs >= 16384) /* Line 1585, Address: 0x102e440 */
    xOffs = 16383; /* Line 1586, Address: 0x102e460 */
  if ((short)yOffs >= 2048) /* Line 1587, Address: 0x102e468 */
    yOffs = 2047; /* Line 1588, Address: 0x102e488 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1589, Address: 0x102e490 */
  if (i < 0) i = 0; /* Line 1590, Address: 0x102e4d8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1592, Address: 0x102e4e4 */

  if (ScreenNo) { /* Line 1594, Address: 0x102e500 */




    xOffs &= 32767; /* Line 1599, Address: 0x102e508 */
    yOffs &= 32767; /* Line 1600, Address: 0x102e514 */


    xBlk = xOffs; /* Line 1603, Address: 0x102e520 */
    xBlk %= 256; /* Line 1604, Address: 0x102e528 */
    xBlk /= 16; /* Line 1605, Address: 0x102e548 */
    yBlk = yOffs; /* Line 1606, Address: 0x102e564 */
    yBlk %= 256; /* Line 1607, Address: 0x102e56c */
    yBlk /= 16; /* Line 1608, Address: 0x102e58c */

    lpw = pmapwk; /* Line 1610, Address: 0x102e5a8 */
    lpw += xBlk; /* Line 1611, Address: 0x102e5b0 */
    lpw += yBlk * 16; /* Line 1612, Address: 0x102e5b8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1613, Address: 0x102e5c4 */
    *pIndex = *lpw; /* Line 1614, Address: 0x102e5dc */

    return 1; /* Line 1616, Address: 0x102e5ec */
  }

  *pIndex = 0; /* Line 1619, Address: 0x102e5f8 */
  return 0; /* Line 1620, Address: 0x102e600 */
} /* Line 1621, Address: 0x102e604 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1641, Address: 0x102e630 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1649, Address: 0x102e658 */
  if (ScreenNo) { /* Line 1650, Address: 0x102e6bc */





    xBlk = xOffs; /* Line 1656, Address: 0x102e6c4 */
    xBlk %= 256; /* Line 1657, Address: 0x102e6cc */
    xBlk /= 16; /* Line 1658, Address: 0x102e6ec */
    yBlk = yOffs; /* Line 1659, Address: 0x102e708 */
    yBlk %= 256; /* Line 1660, Address: 0x102e710 */
    yBlk /= 16; /* Line 1661, Address: 0x102e730 */


    lpw = pmapwk; /* Line 1664, Address: 0x102e74c */
    lpw += xBlk; /* Line 1665, Address: 0x102e754 */
    lpw += yBlk * 16; /* Line 1666, Address: 0x102e75c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1667, Address: 0x102e768 */
    *ppBlockNo = lpw; /* Line 1668, Address: 0x102e780 */
    *pIndex = *lpw; /* Line 1669, Address: 0x102e788 */




    return 1; /* Line 1674, Address: 0x102e798 */
  }

  *pIndex = 0; /* Line 1677, Address: 0x102e7a4 */
  return 0; /* Line 1678, Address: 0x102e7ac */
} /* Line 1679, Address: 0x102e7b0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1693, Address: 0x102e7d0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1700, Address: 0x102e7ec */
  pMapWk = (unsigned char*)mapwka; /* Line 1701, Address: 0x102e7f0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1702, Address: 0x102e7f8 */
    *pBlockIndex = BlockNo; /* Line 1703, Address: 0x102e81c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1704, Address: 0x102e828 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1705, Address: 0x102e840 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1706, Address: 0x102e854 */
    }
  }


} /* Line 1711, Address: 0x102e86c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1725, Address: 0x102e890 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1726, Address: 0x102e89c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1727, Address: 0x102e8c8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1728, Address: 0x102e914 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1729, Address: 0x102e940 */

          return 0; /* Line 1731, Address: 0x102e98c */
        }
      }
    }
  }

  return 1; /* Line 1737, Address: 0x102e998 */
} /* Line 1738, Address: 0x102e99c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1755, Address: 0x102e9b0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1756, Address: 0x102e9cc */

} /* Line 1758, Address: 0x102e9e8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1760, Address: 0x102ea00 */
  wH_posiw = 0; /* Line 1761, Address: 0x102ea1c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1762, Address: 0x102ea20 */

} /* Line 1764, Address: 0x102ea3c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1766, Address: 0x102ea50 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1767, Address: 0x102ea64 */

} /* Line 1769, Address: 0x102ea80 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1771, Address: 0x102ea90 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1772, Address: 0x102eaac */

} /* Line 1774, Address: 0x102eac8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1776, Address: 0x102eae0 */
  xOffs += wH_posiw; /* Line 1777, Address: 0x102eaf8 */
  yOffs += wV_posiw; /* Line 1778, Address: 0x102eb08 */
  yOffs &= 240; /* Line 1779, Address: 0x102eb18 */
  xOffs &= 496; /* Line 1780, Address: 0x102eb24 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1782, Address: 0x102eb30 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1783, Address: 0x102eb5c */


} /* Line 1786, Address: 0x102eb88 */















void mapwrt() { /* Line 1802, Address: 0x102eba0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1809, Address: 0x102ebb8 */
  wV_posiw = scra_v_posit.w.h; /* Line 1810, Address: 0x102ebc4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1811, Address: 0x102ebd0 */
  VramBase = 16384; /* Line 1812, Address: 0x102ebd8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1813, Address: 0x102ebdc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1817, Address: 0x102ebf4 */
  VramBase = 24576; /* Line 1818, Address: 0x102ebfc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1819, Address: 0x102ec00 */

} /* Line 1821, Address: 0x102ec10 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1824, Address: 0x102ec30 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1825, Address: 0x102ec48 */
} /* Line 1826, Address: 0x102ec68 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1831, Address: 0x102ec80 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1835, Address: 0x102eca0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1838, Address: 0x102ecbc */



    wD4 += 16; /* Line 1842, Address: 0x102ece4 */
  } while ((short)--wD6 >= 0); /* Line 1843, Address: 0x102ecf0 */

} /* Line 1845, Address: 0x102ed18 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1851, Address: 0x102ed30 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1854, Address: 0x102ed4c */
  wD6 = 15; /* Line 1855, Address: 0x102ed54 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1858, Address: 0x102ed5c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1860, Address: 0x102ed80 */
    wD4 += 16; /* Line 1861, Address: 0x102eda0 */
  } while ((short)--wD6 >= 0); /* Line 1862, Address: 0x102eda8 */
} /* Line 1863, Address: 0x102edcc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1889, Address: 0x102edf0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1894, Address: 0x102ee18 */
  wD0 = pWrttbl[wD0]; /* Line 1895, Address: 0x102ee28 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1897, Address: 0x102ee44 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1898, Address: 0x102ee68 */
  if (wD0) { /* Line 1899, Address: 0x102ee90 */
    wD5 = 65520; /* Line 1900, Address: 0x102ee9c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1901, Address: 0x102eea4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1904, Address: 0x102eec0 */



  } /* Line 1908, Address: 0x102eee8 */
  else {

    wD5 = 0; /* Line 1911, Address: 0x102eef0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1912, Address: 0x102eef4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1916, Address: 0x102ef10 */
  }





} /* Line 1923, Address: 0x102ef38 */










void mapinit() { /* Line 1934, Address: 0x102ef60 */

  colorset2(mapinittbl.colorno2); /* Line 1936, Address: 0x102ef68 */
  colorset(mapinittbl.colorno2); /* Line 1937, Address: 0x102ef7c */


  if (play_start & 2) divdevset(); /* Line 1940, Address: 0x102ef90 */
} /* Line 1941, Address: 0x102efb0 */




void mapset() {} /* Line 1946, Address: 0x102efc0 */



void divdevset() {} /* Line 1950, Address: 0x102efd0 */



void enecginit() {} /* Line 1954, Address: 0x102efe0 */
