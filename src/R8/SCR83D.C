#include "..\EQU.H"
#include "SCR82C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL8D.H"
#include "SCRCHK8.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
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

static unsigned char z81awrttbl[33] = {
  0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 6, 6,
  6, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4
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
short scr_dir_tbl[6] = { 4, 0, 3735, 0, 784, 96 };
short playpositbl[1][2] = { { 48, 588 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;










































































































void scr_set() { /* Line 166, Address: 0x102ba50 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 169, Address: 0x102ba5c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 170, Address: 0x102ba70 */
  scr_timer.b.h = 0; /* Line 171, Address: 0x102ba84 */

  pScrTbl = scr_dir_tbl; /* Line 173, Address: 0x102ba8c */
  scrar_no = *pScrTbl; /* Line 174, Address: 0x102ba94 */
  ++pScrTbl; /* Line 175, Address: 0x102baa0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 176, Address: 0x102baa4 */
  ++pScrTbl; /* Line 177, Address: 0x102bab8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 178, Address: 0x102babc */
  ++pScrTbl; /* Line 179, Address: 0x102bad0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 180, Address: 0x102bad4 */
  ++pScrTbl; /* Line 181, Address: 0x102bae8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 182, Address: 0x102baec */
  scra_h_keep = *pScrTbl + 576; /* Line 183, Address: 0x102bb00 */
  ++pScrTbl; /* Line 184, Address: 0x102bb20 */
  scra_h_count = 16; /* Line 185, Address: 0x102bb24 */
  scra_v_count = 16; /* Line 186, Address: 0x102bb30 */

  scra_vline = *pScrTbl; /* Line 188, Address: 0x102bb3c */
  scra_hline = 160; /* Line 189, Address: 0x102bb48 */

  playposiset(); /* Line 191, Address: 0x102bb54 */
} /* Line 192, Address: 0x102bb5c */





































static void playposiset() { /* Line 230, Address: 0x102bb70 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 233, Address: 0x102bb84 */
    playload(); /* Line 234, Address: 0x102bb94 */
    xwk = actwk[0].xposi.w.h; /* Line 235, Address: 0x102bb9c */

    if (actwk[0].yposi.w.h > 0) { /* Line 237, Address: 0x102bbac */
      ywk = actwk[0].yposi.w.h; /* Line 238, Address: 0x102bbc4 */
    } else { /* Line 239, Address: 0x102bbd4 */
      ywk = 0; /* Line 240, Address: 0x102bbdc */
    }
  } /* Line 242, Address: 0x102bbe0 */
  else {
    pPositbl = playpositbl[demoflag.w]; /* Line 244, Address: 0x102bbe8 */
    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 245, Address: 0x102bc08 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 246, Address: 0x102bc1c */
  }


  if (xwk > 160) { /* Line 250, Address: 0x102bc30 */
    xwk -= 160; /* Line 251, Address: 0x102bc44 */
  } else { /* Line 252, Address: 0x102bc50 */
    xwk = 0; /* Line 253, Address: 0x102bc58 */
  }


  if (xwk > scralim_right) { /* Line 257, Address: 0x102bc5c */
    xwk = scralim_right; /* Line 258, Address: 0x102bc80 */
  }


  scra_h_posit.w.h = xwk; /* Line 262, Address: 0x102bc90 */

  if (ywk > 96) { /* Line 264, Address: 0x102bc98 */
    ywk -= 96; /* Line 265, Address: 0x102bcac */
  } else { /* Line 266, Address: 0x102bcb8 */
    ywk = 0; /* Line 267, Address: 0x102bcc0 */
  }


  if (ywk > scralim_down) { /* Line 271, Address: 0x102bcc4 */
    ywk = scralim_down; /* Line 272, Address: 0x102bce8 */
  }


  scra_v_posit.w.h = ywk; /* Line 276, Address: 0x102bcf8 */

  scrbinit(xwk, ywk); /* Line 278, Address: 0x102bd00 */


  loopmapno = playmapnotbl[0]; /* Line 281, Address: 0x102bd10 */
  loopmapno2 = playmapnotbl[1]; /* Line 282, Address: 0x102bd20 */
  ballmapno = playmapnotbl[2]; /* Line 283, Address: 0x102bd30 */
  ballmapno2 = playmapnotbl[3]; /* Line 284, Address: 0x102bd40 */
} /* Line 285, Address: 0x102bd50 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 306, Address: 0x102bd70 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 309, Address: 0x102bd7c */
  lYwk.w.l = 0; /* Line 310, Address: 0x102bd84 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 312, Address: 0x102bd88 */
  scrb_v_posit.l = lYwk.l; /* Line 313, Address: 0x102bd94 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 314, Address: 0x102bda0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 315, Address: 0x102bdac */

  scrc_h_posit.w.h = sXpos + 112; /* Line 317, Address: 0x102bdb8 */

  sXpos = (unsigned short)sXpos >> 2; /* Line 319, Address: 0x102bdd8 */
  scrz_h_posit.w.h = sXpos * 3 + 112; /* Line 320, Address: 0x102bdf4 */

  sXpos = (unsigned short)sXpos * 2; /* Line 322, Address: 0x102be1c */
  scrb_h_posit.w.h = sXpos + 112; /* Line 323, Address: 0x102be38 */
} /* Line 324, Address: 0x102be58 */















void scroll() { /* Line 340, Address: 0x102be70 */
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

  if (scroll_start.b.h) return; /* Line 352, Address: 0x102be90 */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 357, Address: 0x102bea0 */

  scrchk(); /* Line 359, Address: 0x102becc */

  scroll_h(); /* Line 361, Address: 0x102bed4 */
  scroll_v(); /* Line 362, Address: 0x102bedc */

  vscroll.w.h = scra_v_posit.w.h; /* Line 364, Address: 0x102bee4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 365, Address: 0x102bef4 */


  lXwk = (scra_hz << 6) * 3; /* Line 368, Address: 0x102bf04 */
  scrollz_h(lXwk, 6); /* Line 369, Address: 0x102bf20 */

  lXwk = scra_hz << 8; /* Line 371, Address: 0x102bf30 */
  scrollc_h(lXwk, 4); /* Line 372, Address: 0x102bf44 */

  lXwk = scra_hz << 7; /* Line 374, Address: 0x102bf54 */
  scrollb_h(lXwk, 2); /* Line 375, Address: 0x102bf68 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 377, Address: 0x102bf78 */


  scrollb_v(lYwk); /* Line 380, Address: 0x102bf8c */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 382, Address: 0x102bf9c */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 384, Address: 0x102bfc4 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 385, Address: 0x102bffc */

  psHscw = hscrollwork; /* Line 387, Address: 0x102c010 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 389, Address: 0x102c018 */
  for (i = 0; i < 34; ++i) { /* Line 390, Address: 0x102c038 */

    *psHscw++ = ldwk.w.l; /* Line 392, Address: 0x102c044 */
  } /* Line 393, Address: 0x102c054 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 395, Address: 0x102c064 */
  for (i = 0; i < 6; ++i) { /* Line 396, Address: 0x102c084 */

    *psHscw++ = ldwk.w.l; /* Line 398, Address: 0x102c090 */
  } /* Line 399, Address: 0x102c0a0 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 401, Address: 0x102c0b0 */
  for (i = 0; i < 8; ++i) { /* Line 402, Address: 0x102c0d0 */

    *psHscw++ = ldwk.w.l; /* Line 404, Address: 0x102c0dc */
  } /* Line 405, Address: 0x102c0ec */

  pHscrbuf = lphscrollbuff; /* Line 407, Address: 0x102c0fc */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 408, Address: 0x102c108 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 409, Address: 0x102c138 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 410, Address: 0x102c168 */
} /* Line 411, Address: 0x102c184 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 432, Address: 0x102c1b0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 436, Address: 0x102c1cc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 437, Address: 0x102c1d0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 439, Address: 0x102c1f0 */
    ldwk.w.l = *pHscrwk; /* Line 440, Address: 0x102c20c */
    ++pHscrwk; /* Line 441, Address: 0x102c218 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 443, Address: 0x102c224 */
      (*pHscrbuf)->l = ldwk.l; /* Line 444, Address: 0x102c22c */
    } /* Line 445, Address: 0x102c23c */
  } /* Line 446, Address: 0x102c260 */
} /* Line 447, Address: 0x102c280 */









































































































static void scrollb_v(short yPos) { /* Line 553, Address: 0x102c2a0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 556, Address: 0x102c2b0 */
  scrb_v_posit.w.h = yPos; /* Line 557, Address: 0x102c2c0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 558, Address: 0x102c2cc */

  if (!ywk) { /* Line 560, Address: 0x102c304 */
    scrb_v_count ^= 16; /* Line 561, Address: 0x102c30c */
    if (yPos - ysv < 0) { /* Line 562, Address: 0x102c320 */
      scrflagb.b.h |= 1; /* Line 563, Address: 0x102c340 */
    } /* Line 564, Address: 0x102c354 */
    else {
      scrflagb.b.h |= 2; /* Line 566, Address: 0x102c35c */
    }
  }


} /* Line 571, Address: 0x102c370 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 589, Address: 0x102c390 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 593, Address: 0x102c3a4 */
  lXwk = lXsv + xoffs; /* Line 594, Address: 0x102c3ac */
  scrb_h_posit.l = lXwk; /* Line 595, Address: 0x102c3b4 */
  ldXwk.l = lXwk; /* Line 596, Address: 0x102c3bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 597, Address: 0x102c3c0 */
  ldXwk.w.l &= 16; /* Line 598, Address: 0x102c3e4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 599, Address: 0x102c3f0 */

  if (!ldXwk.b.b4) { /* Line 601, Address: 0x102c40c */
    scrb_h_count ^= 16; /* Line 602, Address: 0x102c418 */
    if (lXwk - lXsv < 0) { /* Line 603, Address: 0x102c42c */
      scrflagb.b.h |= 1 << flgbit; /* Line 604, Address: 0x102c438 */
    } /* Line 605, Address: 0x102c45c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 607, Address: 0x102c464 */
    }
  }


} /* Line 612, Address: 0x102c48c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 630, Address: 0x102c4a0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 634, Address: 0x102c4b4 */
  lXwk = lXsv + xoffs; /* Line 635, Address: 0x102c4bc */
  scrc_h_posit.l = lXwk; /* Line 636, Address: 0x102c4c4 */
  ldXwk.l = lXwk; /* Line 637, Address: 0x102c4cc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 638, Address: 0x102c4d0 */
  ldXwk.w.l &= 16; /* Line 639, Address: 0x102c4f4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 640, Address: 0x102c500 */

  if (!ldXwk.b.b4) { /* Line 642, Address: 0x102c51c */
    scrc_h_count ^= 16; /* Line 643, Address: 0x102c528 */
    if (lXwk - lXsv < 0) { /* Line 644, Address: 0x102c53c */
      scrflagc.b.h |= 1 << flgbit; /* Line 645, Address: 0x102c548 */
    } /* Line 646, Address: 0x102c56c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 648, Address: 0x102c574 */
    }
  }


} /* Line 653, Address: 0x102c59c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 671, Address: 0x102c5b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 675, Address: 0x102c5c4 */
  lXwk = lXsv + xoffs; /* Line 676, Address: 0x102c5cc */
  scrz_h_posit.l = lXwk; /* Line 677, Address: 0x102c5d4 */
  ldXwk.l = lXwk; /* Line 678, Address: 0x102c5dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 679, Address: 0x102c5e0 */
  ldXwk.w.l &= 16; /* Line 680, Address: 0x102c604 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 681, Address: 0x102c610 */

  if (!ldXwk.b.b4) { /* Line 683, Address: 0x102c62c */
    scrz_h_count ^= 16; /* Line 684, Address: 0x102c638 */
    if (lXwk - lXsv < 0) { /* Line 685, Address: 0x102c64c */
      scrflagz.b.h |= 1 << flgbit; /* Line 686, Address: 0x102c658 */
    } /* Line 687, Address: 0x102c67c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 689, Address: 0x102c684 */
    }
  }


} /* Line 694, Address: 0x102c6ac */














static void scroll_h() { /* Line 709, Address: 0x102c6c0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 713, Address: 0x102c6d0 */

  scrh_move(); /* Line 715, Address: 0x102c6e0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 716, Address: 0x102c6e8 */
  if (!bXwk) { /* Line 717, Address: 0x102c71c */
    scra_h_count ^= 16; /* Line 718, Address: 0x102c724 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 719, Address: 0x102c738 */
      scrflaga.b.h |= 4; /* Line 720, Address: 0x102c75c */
    } else { /* Line 721, Address: 0x102c770 */
      scrflaga.b.h |= 8; /* Line 722, Address: 0x102c778 */
    }
  }


} /* Line 727, Address: 0x102c78c */
















static void scrh_move() { /* Line 744, Address: 0x102c7b0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 747, Address: 0x102c7b8 */
  if (xwk == 0) { /* Line 748, Address: 0x102c800 */

    scra_hz = 0; /* Line 750, Address: 0x102c810 */
    return; /* Line 751, Address: 0x102c818 */
  } else if (xwk < 0) { /* Line 752, Address: 0x102c820 */

    if (xwk < -16) { /* Line 754, Address: 0x102c830 */
      xwk = -16; /* Line 755, Address: 0x102c844 */
    }


    xwk += scra_h_posit.w.h; /* Line 759, Address: 0x102c850 */
    if (xwk < scralim_left) { /* Line 760, Address: 0x102c864 */
      xwk = scralim_left; /* Line 761, Address: 0x102c888 */
    }
  } /* Line 763, Address: 0x102c898 */
  else {
    if (xwk > 16) { /* Line 765, Address: 0x102c8a0 */
      xwk = 16; /* Line 766, Address: 0x102c8b4 */
    }


    xwk += scra_h_posit.w.h; /* Line 770, Address: 0x102c8c0 */
    if (xwk > scralim_right) { /* Line 771, Address: 0x102c8d4 */
      xwk = scralim_right; /* Line 772, Address: 0x102c8f8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 777, Address: 0x102c908 */
  scra_h_posit.w.h = xwk; /* Line 778, Address: 0x102c938 */
} /* Line 779, Address: 0x102c940 */














static void scroll_v() { /* Line 794, Address: 0x102c950 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 797, Address: 0x102c95c */
  if (actwk[0].cddat & 4) { /* Line 798, Address: 0x102c990 */
    ywk -= 5; /* Line 799, Address: 0x102c9a8 */
  }


  if (actwk[0].cddat & 2) { /* Line 803, Address: 0x102c9b4 */
    ywk += 32; /* Line 804, Address: 0x102c9cc */
    if (ywk < scra_vline) { /* Line 805, Address: 0x102c9d8 */
      ywk -= scra_vline; /* Line 806, Address: 0x102c9fc */
      sv_move_main2(ywk); /* Line 807, Address: 0x102ca10 */
      return; /* Line 808, Address: 0x102ca1c */
    } else if (ywk >= scra_vline + 64) { /* Line 809, Address: 0x102ca24 */
      ywk -= scra_vline + 64; /* Line 810, Address: 0x102ca4c */
      sv_move_main2(ywk); /* Line 811, Address: 0x102ca74 */
      return; /* Line 812, Address: 0x102ca80 */
    }
    ywk -= scra_vline + 64; /* Line 814, Address: 0x102ca88 */
    if (!limmoveflag) goto label1; /* Line 815, Address: 0x102cab0 */
    sv_move_sub2(); /* Line 816, Address: 0x102cac0 */
    return; /* Line 817, Address: 0x102cac8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 822, Address: 0x102cad0 */
    sv_move_main(ywk); /* Line 823, Address: 0x102cafc */
    return; /* Line 824, Address: 0x102cb08 */
  } else if (!limmoveflag) goto label1; /* Line 825, Address: 0x102cb10 */
  sv_move_sub2(); /* Line 826, Address: 0x102cb20 */
  return; /* Line 827, Address: 0x102cb28 */



label1:
  scra_vz = 0; /* Line 832, Address: 0x102cb30 */
} /* Line 833, Address: 0x102cb38 */













static void sv_move_main(short yPos) { /* Line 847, Address: 0x102cb50 */
  short spdwk;

  if (scra_vline == 96) { /* Line 850, Address: 0x102cb60 */
    if (actwk[0].mspeed.w < 0) { /* Line 851, Address: 0x102cb7c */
      spdwk = -actwk[0].mspeed.w; /* Line 852, Address: 0x102cb94 */
    } else { /* Line 853, Address: 0x102cbb8 */
      spdwk = actwk[0].mspeed.w; /* Line 854, Address: 0x102cbc0 */
    }


    if (spdwk >= 2048) { /* Line 858, Address: 0x102cbd0 */
      sv_move_main2(yPos); /* Line 859, Address: 0x102cbe4 */
    } /* Line 860, Address: 0x102cbf0 */
    else {

      if (yPos > 6) { /* Line 863, Address: 0x102cbf8 */
        sv_move_plus(1536); /* Line 864, Address: 0x102cc10 */
      } else if (yPos < -6) { /* Line 865, Address: 0x102cc1c */
        sv_move_minus(1536); /* Line 866, Address: 0x102cc3c */
      } /* Line 867, Address: 0x102cc48 */
      else sv_move_sub(yPos); /* Line 868, Address: 0x102cc50 */
    }
  } /* Line 870, Address: 0x102cc5c */
  else {
    if (yPos > 2) { /* Line 872, Address: 0x102cc64 */
      sv_move_plus(512); /* Line 873, Address: 0x102cc7c */
    } else if (yPos < -2) { /* Line 874, Address: 0x102cc88 */
      sv_move_minus(512); /* Line 875, Address: 0x102cca8 */
    } /* Line 876, Address: 0x102ccb4 */
    else sv_move_sub(yPos); /* Line 877, Address: 0x102ccbc */
  }

} /* Line 880, Address: 0x102ccc8 */













static void sv_move_main2(short yPos) { /* Line 894, Address: 0x102cce0 */
  short spdwk;

  spdwk = 4096; /* Line 897, Address: 0x102ccf0 */

  if (yPos > 16) { /* Line 899, Address: 0x102ccfc */
    sv_move_plus(spdwk); /* Line 900, Address: 0x102cd14 */
  } else if (yPos < -16) { /* Line 901, Address: 0x102cd20 */
    sv_move_minus(spdwk); /* Line 902, Address: 0x102cd40 */
  } else { /* Line 903, Address: 0x102cd4c */
    sv_move_sub(yPos); /* Line 904, Address: 0x102cd54 */
  }
} /* Line 906, Address: 0x102cd60 */














static void sv_move_sub(short yPos) { /* Line 921, Address: 0x102cd80 */
  int_union lSpd;

  lSpd.l = 0; /* Line 924, Address: 0x102cd8c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 925, Address: 0x102cd90 */
  if (yPos < 0) { /* Line 926, Address: 0x102cdbc */
    scrv_up_ch(lSpd); /* Line 927, Address: 0x102cdd0 */
  } else { /* Line 928, Address: 0x102cddc */
    scrv_down_ch(lSpd); /* Line 929, Address: 0x102cde4 */
  }
} /* Line 931, Address: 0x102cdf0 */



static void sv_move_sub2() { /* Line 935, Address: 0x102ce00 */
  limmoveflag = 0; /* Line 936, Address: 0x102ce08 */

  sv_move_sub(0); /* Line 938, Address: 0x102ce10 */
} /* Line 939, Address: 0x102ce1c */













static void sv_move_minus(short speed) { /* Line 953, Address: 0x102ce30 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 956, Address: 0x102ce3c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 957, Address: 0x102ce60 */
  scrv_up_ch(lSpd); /* Line 958, Address: 0x102ce84 */
} /* Line 959, Address: 0x102ce90 */














static void scrv_up_ch(int_union lSpd) { /* Line 974, Address: 0x102cea0 */
  if (lSpd.w.l <= scralim_up) { /* Line 975, Address: 0x102ceac */
    if (lSpd.w.l > -256) { /* Line 976, Address: 0x102ced4 */

      lSpd.w.l = scralim_up; /* Line 978, Address: 0x102ceec */
    } else { /* Line 979, Address: 0x102cef8 */
      lSpd.w.l &= 2047; /* Line 980, Address: 0x102cf00 */
      actwk[0].yposi.w.h &= 2047; /* Line 981, Address: 0x102cf0c */
      scra_v_posit.w.h &= 2047; /* Line 982, Address: 0x102cf20 */
      scrb_v_posit.w.h &= 1023; /* Line 983, Address: 0x102cf34 */
    }
  }

  scrv_move(lSpd); /* Line 987, Address: 0x102cf48 */
} /* Line 988, Address: 0x102cf54 */













static void sv_move_plus(short sSpd) { /* Line 1002, Address: 0x102cf70 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1005, Address: 0x102cf7c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1006, Address: 0x102cf9c */
  scrv_down_ch(lSpd); /* Line 1007, Address: 0x102cfc0 */
} /* Line 1008, Address: 0x102cfcc */














static void scrv_down_ch(int_union lSpd) { /* Line 1023, Address: 0x102cfe0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1024, Address: 0x102cfec */
    if (lSpd.w.l < 2048) { /* Line 1025, Address: 0x102d014 */

      lSpd.w.l = scralim_down; /* Line 1027, Address: 0x102d02c */
    } else { /* Line 1028, Address: 0x102d038 */
      lSpd.w.l -= 2048; /* Line 1029, Address: 0x102d040 */
      actwk[0].yposi.w.h &= 2047; /* Line 1030, Address: 0x102d04c */
      scra_v_posit.w.h -= 2048; /* Line 1031, Address: 0x102d060 */
      scrb_v_posit.w.h &= 1023; /* Line 1032, Address: 0x102d074 */
    }
  }

  scrv_move(lSpd); /* Line 1036, Address: 0x102d088 */
} /* Line 1037, Address: 0x102d094 */
















static void scrv_move(int_union lSpd) { /* Line 1054, Address: 0x102d0b0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1058, Address: 0x102d0c0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1059, Address: 0x102d0d0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1060, Address: 0x102d0f4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1061, Address: 0x102d108 */
  scra_vz = spdwk.w.l; /* Line 1062, Address: 0x102d120 */

  scra_v_posit.l = lSpd.l; /* Line 1064, Address: 0x102d12c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1066, Address: 0x102d138 */
  if (!ywk) { /* Line 1067, Address: 0x102d174 */
    scra_v_count ^= 16; /* Line 1068, Address: 0x102d17c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1069, Address: 0x102d190 */
    if (ywk < 0) { /* Line 1070, Address: 0x102d1bc */
      scrflaga.b.h |= 1; /* Line 1071, Address: 0x102d1cc */
    } else { /* Line 1072, Address: 0x102d1e0 */
      scrflaga.b.h |= 2; /* Line 1073, Address: 0x102d1e8 */
    }
  }


} /* Line 1078, Address: 0x102d1fc */

















void scrollwrt() { /* Line 1096, Address: 0x102d210 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1105, Address: 0x102d230 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1106, Address: 0x102d234 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1107, Address: 0x102d240 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1108, Address: 0x102d24c */
  pScrFlag = &scrflagbw.b.h; /* Line 1109, Address: 0x102d254 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1110, Address: 0x102d25c */

  VramBase = 16384; /* Line 1112, Address: 0x102d270 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1113, Address: 0x102d274 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1114, Address: 0x102d280 */
  pMapWk = (unsigned char*)mapwka; /* Line 1115, Address: 0x102d28c */
  pScrFlag = &scrflagaw.b.h; /* Line 1116, Address: 0x102d294 */

  if (*pScrFlag) { /* Line 1118, Address: 0x102d29c */
    if (*pScrFlag & 1) { /* Line 1119, Address: 0x102d2a8 */
      *pScrFlag &= 254; /* Line 1120, Address: 0x102d2bc */

      lD4.l = -16; /* Line 1122, Address: 0x102d2c8 */
      wD5 = 65520; /* Line 1123, Address: 0x102d2d0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1125, Address: 0x102d2d8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1127, Address: 0x102d2f8 */
    }




    if (*pScrFlag & 2) { /* Line 1133, Address: 0x102d324 */
      *pScrFlag &= 253; /* Line 1134, Address: 0x102d338 */

      lD4.l = 224; /* Line 1136, Address: 0x102d344 */
      wD5 = 65520; /* Line 1137, Address: 0x102d34c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1138, Address: 0x102d354 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1140, Address: 0x102d374 */
    }




    if (*pScrFlag & 4) { /* Line 1146, Address: 0x102d3a0 */
      *pScrFlag &= 251; /* Line 1147, Address: 0x102d3b4 */

      lD4.l = -16; /* Line 1149, Address: 0x102d3c0 */
      wD5 = 65520; /* Line 1150, Address: 0x102d3c8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1151, Address: 0x102d3d0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1153, Address: 0x102d3f0 */
    }




    if (*pScrFlag & 8) { /* Line 1159, Address: 0x102d41c */
      *pScrFlag &= 247; /* Line 1160, Address: 0x102d430 */

      lD4.l = -16; /* Line 1162, Address: 0x102d43c */
      wD5 = 320; /* Line 1163, Address: 0x102d444 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1164, Address: 0x102d44c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1166, Address: 0x102d46c */
    }
  }






} /* Line 1175, Address: 0x102d498 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1192, Address: 0x102d4c0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1203, Address: 0x102d4ec */

  if (*pScrFlag & 1) { /* Line 1205, Address: 0x102d4f4 */
    *pScrFlag &= 254; /* Line 1206, Address: 0x102d50c */
  } /* Line 1207, Address: 0x102d520 */
  else {
    *pScrFlag &= 254; /* Line 1209, Address: 0x102d528 */

    if (*pScrFlag & 2) { /* Line 1211, Address: 0x102d53c */
      *pScrFlag &= 253; /* Line 1212, Address: 0x102d554 */
      lD4.w.l = 224; /* Line 1213, Address: 0x102d568 */
    } /* Line 1214, Address: 0x102d570 */
    else {
      *pScrFlag &= 253; /* Line 1216, Address: 0x102d578 */
      goto label1; /* Line 1217, Address: 0x102d58c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1222, Address: 0x102d594 */
  wD0 &= 127; /* Line 1223, Address: 0x102d5e4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1224, Address: 0x102d5ec */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1230, Address: 0x102d60c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1231, Address: 0x102d62c */
  if (wD0 != 0) { /* Line 1232, Address: 0x102d650 */
    wD5 = 65520; /* Line 1233, Address: 0x102d65c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1234, Address: 0x102d664 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1236, Address: 0x102d684 */



  } /* Line 1240, Address: 0x102d6b0 */
  else {

    wD5 = 0; /* Line 1243, Address: 0x102d6b8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x102d6bc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1248, Address: 0x102d6dc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1255, Address: 0x102d708 */






    lD4.l = -16; /* Line 1262, Address: 0x102d71c */
    wD5 = 65520; /* Line 1263, Address: 0x102d724 */
    if (*pScrFlag & 168) { /* Line 1264, Address: 0x102d72c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1265, Address: 0x102d744 */
      wD5 = 320; /* Line 1266, Address: 0x102d764 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1270, Address: 0x102d76c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1272, Address: 0x102d79c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1273, Address: 0x102d7a8 */



    for (i = 0; i < 16; ++i) { /* Line 1277, Address: 0x102d7b8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1278, Address: 0x102d7c4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1279, Address: 0x102d7e4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1280, Address: 0x102d81c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1281, Address: 0x102d83c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1283, Address: 0x102d860 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1286, Address: 0x102d884 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1288, Address: 0x102d8a4 */
      }
      lD4.w.l += 16; /* Line 1290, Address: 0x102d8b8 */
    } /* Line 1291, Address: 0x102d8c4 */
    *pScrFlag = 0; /* Line 1292, Address: 0x102d8d4 */
  }
} /* Line 1294, Address: 0x102d8dc */





void scrollwrtc() {} /* Line 1300, Address: 0x102d910 */




void scrollwrtz() {} /* Line 1305, Address: 0x102d920 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1323, Address: 0x102d930 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1336, Address: 0x102d958 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1339, Address: 0x102d978 */
    pTilePoint->x += 2; /* Line 1340, Address: 0x102d98c */
    if (pTilePoint->x >= 64) { /* Line 1341, Address: 0x102d9a0 */
      pTilePoint->x -= 64; /* Line 1342, Address: 0x102d9b4 */
    }
    xOffs += 16; /* Line 1344, Address: 0x102d9c8 */
  } while (--lpcnt >= 0); /* Line 1345, Address: 0x102d9d4 */
} /* Line 1346, Address: 0x102d9e8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1350, Address: 0x102da00 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1354, Address: 0x102da28 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1357, Address: 0x102da48 */
    pTilePoint->x += 2; /* Line 1358, Address: 0x102da5c */
    if (pTilePoint->x >= 64) { /* Line 1359, Address: 0x102da70 */
      pTilePoint->x -= 64; /* Line 1360, Address: 0x102da84 */
    }
    xOffs += 16; /* Line 1362, Address: 0x102da98 */
  } while (--lpcnt >= 0); /* Line 1363, Address: 0x102daa4 */
} /* Line 1364, Address: 0x102dab8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1384, Address: 0x102dad0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1388, Address: 0x102daf8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1391, Address: 0x102db18 */
    pTilePoint->y += 2; /* Line 1392, Address: 0x102db2c */
    if (pTilePoint->y >= 32) { /* Line 1393, Address: 0x102db3c */
      pTilePoint->y -= 32; /* Line 1394, Address: 0x102db50 */
    }
    yOffs += 16; /* Line 1396, Address: 0x102db60 */
  } while (--lpcnt >= 0); /* Line 1397, Address: 0x102db6c */
} /* Line 1398, Address: 0x102db80 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1417, Address: 0x102db90 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1423, Address: 0x102dbc4 */

    base = 1; /* Line 1425, Address: 0x102dbd4 */
  } /* Line 1426, Address: 0x102dbd8 */
  else if (VramBase == 16384) { /* Line 1427, Address: 0x102dbe0 */

    base = 0; /* Line 1429, Address: 0x102dbf0 */
  }
  x = pTilePoint->x; /* Line 1431, Address: 0x102dbf4 */
  y = pTilePoint->y; /* Line 1432, Address: 0x102dbfc */


  frip = BlkIndex & 6144; /* Line 1435, Address: 0x102dc04 */
  BlkIndex &= 1023; /* Line 1436, Address: 0x102dc0c */
  if (frip == 6144) { /* Line 1437, Address: 0x102dc18 */

    p0 = 3, p1 = 2; /* Line 1439, Address: 0x102dc24 */
    p2 = 1, p3 = 0; /* Line 1440, Address: 0x102dc2c */
  } /* Line 1441, Address: 0x102dc34 */
  else if (frip & 4096) { /* Line 1442, Address: 0x102dc3c */

    p0 = 2, p1 = 3; /* Line 1444, Address: 0x102dc48 */
    p2 = 0, p3 = 1; /* Line 1445, Address: 0x102dc50 */
  } /* Line 1446, Address: 0x102dc58 */
  else if (frip & 2048) { /* Line 1447, Address: 0x102dc60 */

    p0 = 1, p1 = 0; /* Line 1449, Address: 0x102dc6c */
    p2 = 3, p3 = 2; /* Line 1450, Address: 0x102dc74 */
  } /* Line 1451, Address: 0x102dc7c */
  else {

    p0 = 0, p1 = 1; /* Line 1454, Address: 0x102dc84 */
    p2 = 2, p3 = 3; /* Line 1455, Address: 0x102dc8c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1458, Address: 0x102dc94 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1459, Address: 0x102dcd8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1460, Address: 0x102dd1c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1461, Address: 0x102dd60 */

} /* Line 1463, Address: 0x102dda4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1481, Address: 0x102dde0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1482, Address: 0x102de00 */
} /* Line 1483, Address: 0x102de20 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1485, Address: 0x102de30 */
  wH_posiw = 0; /* Line 1486, Address: 0x102de50 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1487, Address: 0x102de54 */
} /* Line 1488, Address: 0x102de74 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1495, Address: 0x102de90 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1501, Address: 0x102dec0 */
  yOffs += wV_posiw; /* Line 1502, Address: 0x102ded0 */





  if ((short)xOffs < 0) /* Line 1508, Address: 0x102dee0 */
    xOffs = 0; /* Line 1509, Address: 0x102defc */
  if ((short)yOffs < 0) /* Line 1510, Address: 0x102df00 */
    yOffs = 0; /* Line 1511, Address: 0x102df1c */
  if ((short)xOffs >= 16384) /* Line 1512, Address: 0x102df20 */
    xOffs = 16383; /* Line 1513, Address: 0x102df40 */
  if ((short)yOffs >= 2048) /* Line 1514, Address: 0x102df48 */
    yOffs = 2047; /* Line 1515, Address: 0x102df68 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1516, Address: 0x102df70 */
  if (i < 0) i = 0; /* Line 1517, Address: 0x102dfb8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1519, Address: 0x102dfc4 */

  if (ScreenNo) { /* Line 1521, Address: 0x102dfe0 */




    xOffs &= 32767; /* Line 1526, Address: 0x102dfe8 */
    yOffs &= 32767; /* Line 1527, Address: 0x102dff4 */


    xBlk = xOffs; /* Line 1530, Address: 0x102e000 */
    xBlk %= 256; /* Line 1531, Address: 0x102e008 */
    xBlk /= 16; /* Line 1532, Address: 0x102e028 */
    yBlk = yOffs; /* Line 1533, Address: 0x102e044 */
    yBlk %= 256; /* Line 1534, Address: 0x102e04c */
    yBlk /= 16; /* Line 1535, Address: 0x102e06c */

    lpw = pmapwk; /* Line 1537, Address: 0x102e088 */
    lpw += xBlk; /* Line 1538, Address: 0x102e090 */
    lpw += yBlk * 16; /* Line 1539, Address: 0x102e098 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1540, Address: 0x102e0a4 */
    *pIndex = *lpw; /* Line 1541, Address: 0x102e0bc */

    return 1; /* Line 1543, Address: 0x102e0cc */
  }

  *pIndex = 0; /* Line 1546, Address: 0x102e0d8 */
  return 0; /* Line 1547, Address: 0x102e0e0 */
} /* Line 1548, Address: 0x102e0e4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1568, Address: 0x102e110 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1576, Address: 0x102e138 */
  if (ScreenNo) { /* Line 1577, Address: 0x102e19c */





    xBlk = xOffs; /* Line 1583, Address: 0x102e1a4 */
    xBlk %= 256; /* Line 1584, Address: 0x102e1ac */
    xBlk /= 16; /* Line 1585, Address: 0x102e1cc */
    yBlk = yOffs; /* Line 1586, Address: 0x102e1e8 */
    yBlk %= 256; /* Line 1587, Address: 0x102e1f0 */
    yBlk /= 16; /* Line 1588, Address: 0x102e210 */


    lpw = pmapwk; /* Line 1591, Address: 0x102e22c */
    lpw += xBlk; /* Line 1592, Address: 0x102e234 */
    lpw += yBlk * 16; /* Line 1593, Address: 0x102e23c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1594, Address: 0x102e248 */
    *ppBlockNo = lpw; /* Line 1595, Address: 0x102e260 */
    *pIndex = *lpw; /* Line 1596, Address: 0x102e268 */




    return 1; /* Line 1601, Address: 0x102e278 */
  }

  *pIndex = 0; /* Line 1604, Address: 0x102e284 */
  return 0; /* Line 1605, Address: 0x102e28c */
} /* Line 1606, Address: 0x102e290 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1620, Address: 0x102e2b0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1627, Address: 0x102e2cc */
  pMapWk = (unsigned char*)mapwka; /* Line 1628, Address: 0x102e2d0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1629, Address: 0x102e2d8 */

    if (block_chk(xOffs, yOffs) == 0) { /* Line 1631, Address: 0x102e2fc */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1632, Address: 0x102e314 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1633, Address: 0x102e328 */
    }
  }


} /* Line 1638, Address: 0x102e340 */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1652, Address: 0x102e360 */
  if ((unsigned short)((scra_v_posit.w.h & 65520) - 16) <= yOffs) { /* Line 1653, Address: 0x102e36c */
    if ((short)((scra_v_posit.w.h + 240 & 65520) - 16) > (short)yOffs) { /* Line 1654, Address: 0x102e3a0 */
      if ((unsigned short)((scra_h_posit.w.h & 65520) - 16) < xOffs) { /* Line 1655, Address: 0x102e3ec */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1656, Address: 0x102e420 */

          return 0; /* Line 1658, Address: 0x102e46c */
        }
      }
    }
  }

  return 1; /* Line 1664, Address: 0x102e478 */
} /* Line 1665, Address: 0x102e47c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1682, Address: 0x102e490 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1683, Address: 0x102e4ac */

} /* Line 1685, Address: 0x102e4c8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1687, Address: 0x102e4e0 */
  wH_posiw = 0; /* Line 1688, Address: 0x102e4fc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1689, Address: 0x102e500 */

} /* Line 1691, Address: 0x102e51c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1693, Address: 0x102e530 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1694, Address: 0x102e544 */

} /* Line 1696, Address: 0x102e560 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1698, Address: 0x102e570 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1699, Address: 0x102e58c */

} /* Line 1701, Address: 0x102e5a8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1703, Address: 0x102e5c0 */
  xOffs += wH_posiw; /* Line 1704, Address: 0x102e5d8 */
  yOffs += wV_posiw; /* Line 1705, Address: 0x102e5e8 */
  yOffs &= 240; /* Line 1706, Address: 0x102e5f8 */
  xOffs &= 496; /* Line 1707, Address: 0x102e604 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1709, Address: 0x102e610 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1710, Address: 0x102e63c */


} /* Line 1713, Address: 0x102e668 */















void mapwrt() { /* Line 1729, Address: 0x102e680 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1736, Address: 0x102e698 */
  wV_posiw = scra_v_posit.w.h; /* Line 1737, Address: 0x102e6a4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1738, Address: 0x102e6b0 */
  VramBase = 16384; /* Line 1739, Address: 0x102e6b8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1740, Address: 0x102e6bc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1744, Address: 0x102e6d4 */
  VramBase = 24576; /* Line 1745, Address: 0x102e6dc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1746, Address: 0x102e6e0 */

} /* Line 1748, Address: 0x102e6f0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1751, Address: 0x102e710 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1752, Address: 0x102e728 */
} /* Line 1753, Address: 0x102e748 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1758, Address: 0x102e760 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1762, Address: 0x102e780 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1765, Address: 0x102e79c */



    wD4 += 16; /* Line 1769, Address: 0x102e7c4 */
  } while ((short)--wD6 >= 0); /* Line 1770, Address: 0x102e7d0 */

} /* Line 1772, Address: 0x102e7f8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1778, Address: 0x102e810 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1781, Address: 0x102e82c */
  wD6 = 15; /* Line 1782, Address: 0x102e834 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1785, Address: 0x102e83c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1787, Address: 0x102e860 */
    wD4 += 16; /* Line 1788, Address: 0x102e880 */
  } while ((short)--wD6 >= 0); /* Line 1789, Address: 0x102e888 */
} /* Line 1790, Address: 0x102e8ac */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1816, Address: 0x102e8d0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1821, Address: 0x102e8f8 */
  wD0 = pWrttbl[wD0]; /* Line 1822, Address: 0x102e908 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1824, Address: 0x102e924 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1825, Address: 0x102e948 */
  if (wD0) { /* Line 1826, Address: 0x102e970 */
    wD5 = 65520; /* Line 1827, Address: 0x102e97c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1828, Address: 0x102e984 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1831, Address: 0x102e9a0 */



  } /* Line 1835, Address: 0x102e9c8 */
  else {

    wD5 = 0; /* Line 1838, Address: 0x102e9d0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1839, Address: 0x102e9d4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1843, Address: 0x102e9f0 */
  }





} /* Line 1850, Address: 0x102ea18 */










void mapinit() { /* Line 1861, Address: 0x102ea40 */

  colorset2(mapinittbl.colorno2); /* Line 1863, Address: 0x102ea48 */
  colorset(mapinittbl.colorno2); /* Line 1864, Address: 0x102ea5c */

  if (plflag) enecginit(); /* Line 1866, Address: 0x102ea70 */
  if (play_start & 2) divdevset(); /* Line 1867, Address: 0x102ea88 */
} /* Line 1868, Address: 0x102eaa8 */




void mapset() {} /* Line 1873, Address: 0x102eac0 */



void divdevset() {} /* Line 1877, Address: 0x102ead0 */



void enecginit() {} /* Line 1881, Address: 0x102eae0 */
