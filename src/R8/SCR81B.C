#include "..\EQU.H"
#include "SCR81A.H"
#include "..\SAVE.H"
#include "COL8B.H"
#include "SCRCHK8.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z81aline(short** ppHscw, char* pScrTbl, short AddrOffs, short LoopNum);
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
  0, 0, 0, 0, 2, 2, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
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
  if (main_play == 0) /* Line 146, Address: 0x1027ce0 */
    return &actwk[0]; /* Line 147, Address: 0x1027cf4 */
  else
    return &actwk[1]; /* Line 149, Address: 0x1027d04 */

} /* Line 151, Address: 0x1027d0c */





































void scr_set() { /* Line 189, Address: 0x1027d20 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x1027d2c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x1027d40 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x1027d54 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x1027d5c */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x1027d64 */
  ++pScrTbl; /* Line 198, Address: 0x1027d70 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x1027d74 */
  ++pScrTbl; /* Line 200, Address: 0x1027d88 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x1027d8c */
  ++pScrTbl; /* Line 202, Address: 0x1027da0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x1027da4 */
  ++pScrTbl; /* Line 204, Address: 0x1027db8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x1027dbc */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x1027dd0 */
  ++pScrTbl; /* Line 207, Address: 0x1027df0 */
  scra_h_count = 16; /* Line 208, Address: 0x1027df4 */
  scra_v_count = 16; /* Line 209, Address: 0x1027e00 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x1027e0c */
  scra_hline = 160; /* Line 212, Address: 0x1027e18 */

  playposiset(); /* Line 214, Address: 0x1027e24 */
} /* Line 215, Address: 0x1027e2c */
















































static void playposiset() { /* Line 264, Address: 0x1027e40 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x1027e54 */
    playload(); /* Line 268, Address: 0x1027e64 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x1027e6c */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x1027e7c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x1027e94 */
    } else { /* Line 273, Address: 0x1027ea4 */
      ywk = 0; /* Line 274, Address: 0x1027eac */
    }
  } /* Line 276, Address: 0x1027eb0 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x1027eb8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x1027ed8 */
    } /* Line 280, Address: 0x1027efc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x1027f04 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x1027f24 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x1027f38 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x1027f4c */
    xwk -= 160; /* Line 292, Address: 0x1027f60 */
  } else { /* Line 293, Address: 0x1027f6c */
    xwk = 0; /* Line 294, Address: 0x1027f74 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x1027f78 */
    xwk = scralim_right; /* Line 299, Address: 0x1027f9c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x1027fac */

  if (ywk > 96) { /* Line 305, Address: 0x1027fb4 */
    ywk -= 96; /* Line 306, Address: 0x1027fc8 */
  } else { /* Line 307, Address: 0x1027fd4 */
    ywk = 0; /* Line 308, Address: 0x1027fdc */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x1027fe0 */
    ywk = scralim_down; /* Line 313, Address: 0x1028004 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x1028014 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102801c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102802c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102803c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102804c */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102805c */
} /* Line 326, Address: 0x102806c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x1028090 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102809c */
  lYwk.w.l = 0; /* Line 351, Address: 0x10280a4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x10280a8 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x10280b4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x10280c0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x10280cc */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x10280d8 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x10280f4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x1028100 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102811c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x1028128 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x1028144 */
} /* Line 366, Address: 0x1028168 */















void scroll() { /* Line 382, Address: 0x1028180 */
  int_union ldwk;
  int_union* pHscrbuf;
  int i;
  int lXwk;
  int lYwk;
  short sYnum;
  short* psHscr;
  short* psHscw;
  static char z81bscrtbl0[9] = {
    3, 3, 1, 5, 1, 1, 1, 1, 1
  };
  static char z81bscrtbl1[7] = {
    3, 1, 1, 3, 1, 1, 1
  };
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };
  static unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 };

  if (scroll_start.b.h) return; /* Line 400, Address: 0x102819c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 405, Address: 0x10281ac */

  scrchk(); /* Line 407, Address: 0x10281d8 */

  scroll_h(); /* Line 409, Address: 0x10281e0 */
  scroll_v(); /* Line 410, Address: 0x10281e8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 412, Address: 0x10281f0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 413, Address: 0x1028200 */


  lXwk = scra_hz << 6; /* Line 416, Address: 0x1028210 */
  scrollz_h(lXwk, 6); /* Line 417, Address: 0x1028224 */

  lXwk = scra_hz << 7; /* Line 419, Address: 0x1028234 */
  scrollc_h(lXwk, 4); /* Line 420, Address: 0x1028248 */

  lXwk = (scra_hz << 4) * 3; /* Line 422, Address: 0x1028258 */
  scrollb_h(lXwk, 2); /* Line 423, Address: 0x1028274 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 425, Address: 0x1028284 */


  scrollb_v(lYwk); /* Line 428, Address: 0x1028298 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 430, Address: 0x10282a8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 432, Address: 0x10282d0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 433, Address: 0x1028308 */

  psHscw = hscrollwork; /* Line 435, Address: 0x102831c */

  z81aline(&psHscw, z81bscrtbl0, 26, 8); /* Line 437, Address: 0x1028328 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 439, Address: 0x1028344 */
  for (i = 0; i < 4; ++i) { /* Line 440, Address: 0x1028364 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x1028370 */
  } /* Line 443, Address: 0x1028384 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 445, Address: 0x1028394 */
  for (i = 0; i < 28; ++i) { /* Line 446, Address: 0x10283b4 */

    *psHscw++ = ldwk.w.l; /* Line 448, Address: 0x10283c0 */
  } /* Line 449, Address: 0x10283d4 */

  z81aline(&psHscw, z81bscrtbl1, 18, 6); /* Line 451, Address: 0x10283e4 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 453, Address: 0x1028400 */
  for (i = 0; i < 8; ++i) { /* Line 454, Address: 0x1028420 */

    *psHscw++ = ldwk.w.l; /* Line 456, Address: 0x102842c */
  } /* Line 457, Address: 0x1028440 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 459, Address: 0x1028450 */
  for (i = 0; i < 12; ++i) { /* Line 460, Address: 0x1028470 */

    *psHscw++ = ldwk.w.l; /* Line 462, Address: 0x102847c */
  } /* Line 463, Address: 0x1028490 */

  pHscrbuf = lphscrollbuff; /* Line 465, Address: 0x10284a0 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 466, Address: 0x10284ac */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 467, Address: 0x10284dc */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 468, Address: 0x102850c */
} /* Line 469, Address: 0x1028528 */













static void z81aline(short** ppHscw, char* pScrTbl, short AddrOffs, short LoopNum) { /* Line 483, Address: 0x1028550 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 489, Address: 0x1028574 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 490, Address: 0x1028598 */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 491, Address: 0x10285b8 */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 492, Address: 0x10285d8 */
  *ppHscw += AddrOffs; /* Line 493, Address: 0x10285e4 */

  for (i = LoopNum; i >= 0; --i) { /* Line 495, Address: 0x1028608 */

    wk = -ldwk.w.l; /* Line 497, Address: 0x102861c */

    for (j = pScrTbl[i]; j >= 0; --j) { /* Line 499, Address: 0x102863c */

      --*ppHscw; /* Line 501, Address: 0x1028658 */
      **ppHscw = wk; /* Line 502, Address: 0x102866c */
    } /* Line 503, Address: 0x1028678 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 505, Address: 0x1028684 */
    ldwk.l += lXwk; /* Line 506, Address: 0x10286a8 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 507, Address: 0x10286b4 */
  } /* Line 508, Address: 0x10286d8 */

  *ppHscw += AddrOffs; /* Line 510, Address: 0x10286e4 */
} /* Line 511, Address: 0x1028708 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 532, Address: 0x1028730 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 536, Address: 0x102874c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 537, Address: 0x1028750 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 539, Address: 0x1028770 */
    ldwk.w.l = *pHscrwk; /* Line 540, Address: 0x102878c */
    ++pHscrwk; /* Line 541, Address: 0x1028798 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 543, Address: 0x10287a4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 544, Address: 0x10287ac */
    } /* Line 545, Address: 0x10287bc */
  } /* Line 546, Address: 0x10287e0 */
} /* Line 547, Address: 0x1028800 */









































































































static void scrollb_v(short yPos) { /* Line 653, Address: 0x1028820 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 656, Address: 0x1028830 */
  scrb_v_posit.w.h = yPos; /* Line 657, Address: 0x1028840 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 658, Address: 0x102884c */

  if (!ywk) { /* Line 660, Address: 0x1028884 */
    scrb_v_count ^= 16; /* Line 661, Address: 0x102888c */
    if (yPos - ysv < 0) { /* Line 662, Address: 0x10288a0 */
      scrflagb.b.h |= 1; /* Line 663, Address: 0x10288c0 */
    } /* Line 664, Address: 0x10288d4 */
    else {
      scrflagb.b.h |= 2; /* Line 666, Address: 0x10288dc */
    }
  }


} /* Line 671, Address: 0x10288f0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 689, Address: 0x1028910 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 693, Address: 0x1028924 */
  lXwk = lXsv + xoffs; /* Line 694, Address: 0x102892c */
  scrb_h_posit.l = lXwk; /* Line 695, Address: 0x1028934 */
  ldXwk.l = lXwk; /* Line 696, Address: 0x102893c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 697, Address: 0x1028940 */
  ldXwk.w.l &= 16; /* Line 698, Address: 0x1028964 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 699, Address: 0x1028970 */

  if (!ldXwk.b.b4) { /* Line 701, Address: 0x102898c */
    scrb_h_count ^= 16; /* Line 702, Address: 0x1028998 */
    if (lXwk - lXsv < 0) { /* Line 703, Address: 0x10289ac */
      scrflagb.b.h |= 1 << flgbit; /* Line 704, Address: 0x10289b8 */
    } /* Line 705, Address: 0x10289dc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 707, Address: 0x10289e4 */
    }
  }


} /* Line 712, Address: 0x1028a0c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 730, Address: 0x1028a20 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 734, Address: 0x1028a34 */
  lXwk = lXsv + xoffs; /* Line 735, Address: 0x1028a3c */
  scrc_h_posit.l = lXwk; /* Line 736, Address: 0x1028a44 */
  ldXwk.l = lXwk; /* Line 737, Address: 0x1028a4c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 738, Address: 0x1028a50 */
  ldXwk.w.l &= 16; /* Line 739, Address: 0x1028a74 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 740, Address: 0x1028a80 */

  if (!ldXwk.b.b4) { /* Line 742, Address: 0x1028a9c */
    scrc_h_count ^= 16; /* Line 743, Address: 0x1028aa8 */
    if (lXwk - lXsv < 0) { /* Line 744, Address: 0x1028abc */
      scrflagc.b.h |= 1 << flgbit; /* Line 745, Address: 0x1028ac8 */
    } /* Line 746, Address: 0x1028aec */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 748, Address: 0x1028af4 */
    }
  }


} /* Line 753, Address: 0x1028b1c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 771, Address: 0x1028b30 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 775, Address: 0x1028b44 */
  lXwk = lXsv + xoffs; /* Line 776, Address: 0x1028b4c */
  scrz_h_posit.l = lXwk; /* Line 777, Address: 0x1028b54 */
  ldXwk.l = lXwk; /* Line 778, Address: 0x1028b5c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 779, Address: 0x1028b60 */
  ldXwk.w.l &= 16; /* Line 780, Address: 0x1028b84 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 781, Address: 0x1028b90 */

  if (!ldXwk.b.b4) { /* Line 783, Address: 0x1028bac */
    scrz_h_count ^= 16; /* Line 784, Address: 0x1028bb8 */
    if (lXwk - lXsv < 0) { /* Line 785, Address: 0x1028bcc */
      scrflagz.b.h |= 1 << flgbit; /* Line 786, Address: 0x1028bd8 */
    } /* Line 787, Address: 0x1028bfc */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 789, Address: 0x1028c04 */
    }
  }


} /* Line 794, Address: 0x1028c2c */














static void scroll_h() { /* Line 809, Address: 0x1028c40 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 813, Address: 0x1028c50 */

  scrh_move(); /* Line 815, Address: 0x1028c60 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 816, Address: 0x1028c68 */
  if (!bXwk) { /* Line 817, Address: 0x1028c9c */
    scra_h_count ^= 16; /* Line 818, Address: 0x1028ca4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 819, Address: 0x1028cb8 */
      scrflaga.b.h |= 4; /* Line 820, Address: 0x1028cdc */
    } else { /* Line 821, Address: 0x1028cf0 */
      scrflaga.b.h |= 8; /* Line 822, Address: 0x1028cf8 */
    }
  }


} /* Line 827, Address: 0x1028d0c */
















static void scrh_move() { /* Line 844, Address: 0x1028d30 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 847, Address: 0x1028d38 */
  if (xwk == 0) { /* Line 848, Address: 0x1028d80 */

    scra_hz = 0; /* Line 850, Address: 0x1028d90 */
    return; /* Line 851, Address: 0x1028d98 */
  } else if (xwk < 0) { /* Line 852, Address: 0x1028da0 */

    if (xwk < -16) { /* Line 854, Address: 0x1028db0 */
      xwk = -16; /* Line 855, Address: 0x1028dc4 */
    }


    xwk += scra_h_posit.w.h; /* Line 859, Address: 0x1028dd0 */
    if (xwk < scralim_left) { /* Line 860, Address: 0x1028de4 */
      xwk = scralim_left; /* Line 861, Address: 0x1028e08 */
    }
  } /* Line 863, Address: 0x1028e18 */
  else {
    if (xwk > 16) { /* Line 865, Address: 0x1028e20 */
      xwk = 16; /* Line 866, Address: 0x1028e34 */
    }


    xwk += scra_h_posit.w.h; /* Line 870, Address: 0x1028e40 */
    if (xwk > scralim_right) { /* Line 871, Address: 0x1028e54 */
      xwk = scralim_right; /* Line 872, Address: 0x1028e78 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 877, Address: 0x1028e88 */
  scra_h_posit.w.h = xwk; /* Line 878, Address: 0x1028eb8 */
} /* Line 879, Address: 0x1028ec0 */














static void scroll_v() { /* Line 894, Address: 0x1028ed0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 897, Address: 0x1028edc */
  if (actwk[0].cddat & 4) { /* Line 898, Address: 0x1028f10 */
    ywk -= 5; /* Line 899, Address: 0x1028f28 */
  }


  if (actwk[0].cddat & 2) { /* Line 903, Address: 0x1028f34 */
    ywk += 32; /* Line 904, Address: 0x1028f4c */
    if (ywk < scra_vline) { /* Line 905, Address: 0x1028f58 */
      ywk -= scra_vline; /* Line 906, Address: 0x1028f7c */
      sv_move_main2(ywk); /* Line 907, Address: 0x1028f90 */
      return; /* Line 908, Address: 0x1028f9c */
    } else if (ywk >= scra_vline + 64) { /* Line 909, Address: 0x1028fa4 */
      ywk -= scra_vline + 64; /* Line 910, Address: 0x1028fcc */
      sv_move_main2(ywk); /* Line 911, Address: 0x1028ff4 */
      return; /* Line 912, Address: 0x1029000 */
    }
    ywk -= scra_vline + 64; /* Line 914, Address: 0x1029008 */
    if (!limmoveflag) goto label1; /* Line 915, Address: 0x1029030 */
    sv_move_sub2(); /* Line 916, Address: 0x1029040 */
    return; /* Line 917, Address: 0x1029048 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 922, Address: 0x1029050 */
    sv_move_main(ywk); /* Line 923, Address: 0x102907c */
    return; /* Line 924, Address: 0x1029088 */
  } else if (!limmoveflag) goto label1; /* Line 925, Address: 0x1029090 */
  sv_move_sub2(); /* Line 926, Address: 0x10290a0 */
  return; /* Line 927, Address: 0x10290a8 */



label1:
  scra_vz = 0; /* Line 932, Address: 0x10290b0 */
} /* Line 933, Address: 0x10290b8 */













static void sv_move_main(short yPos) { /* Line 947, Address: 0x10290d0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 950, Address: 0x10290e0 */
    if (actwk[0].mspeed.w < 0) { /* Line 951, Address: 0x10290fc */
      spdwk = -actwk[0].mspeed.w; /* Line 952, Address: 0x1029114 */
    } else { /* Line 953, Address: 0x1029138 */
      spdwk = actwk[0].mspeed.w; /* Line 954, Address: 0x1029140 */
    }


    if (spdwk >= 2048) { /* Line 958, Address: 0x1029150 */
      sv_move_main2(yPos); /* Line 959, Address: 0x1029164 */
    } /* Line 960, Address: 0x1029170 */
    else {

      if (yPos > 6) { /* Line 963, Address: 0x1029178 */
        sv_move_plus(1536); /* Line 964, Address: 0x1029190 */
      } else if (yPos < -6) { /* Line 965, Address: 0x102919c */
        sv_move_minus(1536); /* Line 966, Address: 0x10291bc */
      } /* Line 967, Address: 0x10291c8 */
      else sv_move_sub(yPos); /* Line 968, Address: 0x10291d0 */
    }
  } /* Line 970, Address: 0x10291dc */
  else {
    if (yPos > 2) { /* Line 972, Address: 0x10291e4 */
      sv_move_plus(512); /* Line 973, Address: 0x10291fc */
    } else if (yPos < -2) { /* Line 974, Address: 0x1029208 */
      sv_move_minus(512); /* Line 975, Address: 0x1029228 */
    } /* Line 976, Address: 0x1029234 */
    else sv_move_sub(yPos); /* Line 977, Address: 0x102923c */
  }

} /* Line 980, Address: 0x1029248 */













static void sv_move_main2(short yPos) { /* Line 994, Address: 0x1029260 */
  short spdwk;

  spdwk = 4096; /* Line 997, Address: 0x1029270 */

  if (yPos > 16) { /* Line 999, Address: 0x102927c */
    sv_move_plus(spdwk); /* Line 1000, Address: 0x1029294 */
  } else if (yPos < -16) { /* Line 1001, Address: 0x10292a0 */
    sv_move_minus(spdwk); /* Line 1002, Address: 0x10292c0 */
  } else { /* Line 1003, Address: 0x10292cc */
    sv_move_sub(yPos); /* Line 1004, Address: 0x10292d4 */
  }
} /* Line 1006, Address: 0x10292e0 */














static void sv_move_sub(short yPos) { /* Line 1021, Address: 0x1029300 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1024, Address: 0x102930c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1025, Address: 0x1029310 */
  if (yPos < 0) { /* Line 1026, Address: 0x102933c */
    scrv_up_ch(lSpd); /* Line 1027, Address: 0x1029350 */
  } else { /* Line 1028, Address: 0x102935c */
    scrv_down_ch(lSpd); /* Line 1029, Address: 0x1029364 */
  }
} /* Line 1031, Address: 0x1029370 */



static void sv_move_sub2() { /* Line 1035, Address: 0x1029380 */
  limmoveflag = 0; /* Line 1036, Address: 0x1029388 */

  sv_move_sub(0); /* Line 1038, Address: 0x1029390 */
} /* Line 1039, Address: 0x102939c */













static void sv_move_minus(short speed) { /* Line 1053, Address: 0x10293b0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1056, Address: 0x10293bc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1057, Address: 0x10293e0 */
  scrv_up_ch(lSpd); /* Line 1058, Address: 0x1029404 */
} /* Line 1059, Address: 0x1029410 */














static void scrv_up_ch(int_union lSpd) { /* Line 1074, Address: 0x1029420 */
  if (lSpd.w.l <= scralim_up) { /* Line 1075, Address: 0x102942c */
    if (lSpd.w.l > -256) { /* Line 1076, Address: 0x1029454 */

      lSpd.w.l = scralim_up; /* Line 1078, Address: 0x102946c */
    } else { /* Line 1079, Address: 0x1029478 */
      lSpd.w.l &= 2047; /* Line 1080, Address: 0x1029480 */
      actwk[0].yposi.w.l &= 2047; /* Line 1081, Address: 0x102948c */
      scra_v_posit.w.h &= 2047; /* Line 1082, Address: 0x10294a0 */
      scrb_v_posit.w.h &= 1023; /* Line 1083, Address: 0x10294b4 */
    }
  }

  scrv_move(lSpd); /* Line 1087, Address: 0x10294c8 */
} /* Line 1088, Address: 0x10294d4 */













static void sv_move_plus(short sSpd) { /* Line 1102, Address: 0x10294f0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1105, Address: 0x10294fc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1106, Address: 0x102951c */
  scrv_down_ch(lSpd); /* Line 1107, Address: 0x1029540 */
} /* Line 1108, Address: 0x102954c */














static void scrv_down_ch(int_union lSpd) { /* Line 1123, Address: 0x1029560 */
  if (lSpd.w.l >= scralim_down) { /* Line 1124, Address: 0x102956c */
    if (lSpd.w.l < 2048) { /* Line 1125, Address: 0x1029594 */

      lSpd.w.l = scralim_down; /* Line 1127, Address: 0x10295ac */
    } else { /* Line 1128, Address: 0x10295b8 */
      lSpd.w.l -= 2048; /* Line 1129, Address: 0x10295c0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1130, Address: 0x10295cc */
      scra_v_posit.w.h -= 2048; /* Line 1131, Address: 0x10295e0 */
      scrb_v_posit.w.h &= 1023; /* Line 1132, Address: 0x10295f4 */
    }
  }

  scrv_move(lSpd); /* Line 1136, Address: 0x1029608 */
} /* Line 1137, Address: 0x1029614 */
















static void scrv_move(int_union lSpd) { /* Line 1154, Address: 0x1029630 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1158, Address: 0x1029640 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1159, Address: 0x1029650 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1160, Address: 0x1029674 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1161, Address: 0x1029688 */
  scra_vz = spdwk.w.l; /* Line 1162, Address: 0x10296a0 */

  scra_v_posit.l = lSpd.l; /* Line 1164, Address: 0x10296ac */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1166, Address: 0x10296b8 */
  if (!ywk) { /* Line 1167, Address: 0x10296f4 */
    scra_v_count ^= 16; /* Line 1168, Address: 0x10296fc */
    ywk = scra_v_posit.w.h - ysv; /* Line 1169, Address: 0x1029710 */
    if (ywk < 0) { /* Line 1170, Address: 0x102973c */
      scrflaga.b.h |= 1; /* Line 1171, Address: 0x102974c */
    } else { /* Line 1172, Address: 0x1029760 */
      scrflaga.b.h |= 2; /* Line 1173, Address: 0x1029768 */
    }
  }


} /* Line 1178, Address: 0x102977c */

















void scrollwrt() { /* Line 1196, Address: 0x1029790 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1205, Address: 0x10297b0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1206, Address: 0x10297b4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1207, Address: 0x10297c0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1208, Address: 0x10297cc */
  pScrFlag = &scrflagbw.b.h; /* Line 1209, Address: 0x10297d4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1210, Address: 0x10297dc */

  VramBase = 16384; /* Line 1212, Address: 0x10297f0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1213, Address: 0x10297f4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1214, Address: 0x1029800 */
  pMapWk = (unsigned char*)mapwka; /* Line 1215, Address: 0x102980c */
  pScrFlag = &scrflagaw.b.h; /* Line 1216, Address: 0x1029814 */

  if (*pScrFlag) { /* Line 1218, Address: 0x102981c */
    if (*pScrFlag & 1) { /* Line 1219, Address: 0x1029828 */
      *pScrFlag &= 254; /* Line 1220, Address: 0x102983c */

      lD4.l = -16; /* Line 1222, Address: 0x1029848 */
      wD5 = 65520; /* Line 1223, Address: 0x1029850 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1225, Address: 0x1029858 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1227, Address: 0x1029878 */
    }




    if (*pScrFlag & 2) { /* Line 1233, Address: 0x10298a4 */
      *pScrFlag &= 253; /* Line 1234, Address: 0x10298b8 */

      lD4.l = 224; /* Line 1236, Address: 0x10298c4 */
      wD5 = 65520; /* Line 1237, Address: 0x10298cc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1238, Address: 0x10298d4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1240, Address: 0x10298f4 */
    }




    if (*pScrFlag & 4) { /* Line 1246, Address: 0x1029920 */
      *pScrFlag &= 251; /* Line 1247, Address: 0x1029934 */

      lD4.l = -16; /* Line 1249, Address: 0x1029940 */
      wD5 = 65520; /* Line 1250, Address: 0x1029948 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1251, Address: 0x1029950 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1253, Address: 0x1029970 */
    }




    if (*pScrFlag & 8) { /* Line 1259, Address: 0x102999c */
      *pScrFlag &= 247; /* Line 1260, Address: 0x10299b0 */

      lD4.l = -16; /* Line 1262, Address: 0x10299bc */
      wD5 = 320; /* Line 1263, Address: 0x10299c4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1264, Address: 0x10299cc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1266, Address: 0x10299ec */
    }
  }






} /* Line 1275, Address: 0x1029a18 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1292, Address: 0x1029a40 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1303, Address: 0x1029a6c */

  if (*pScrFlag & 1) { /* Line 1305, Address: 0x1029a74 */
    *pScrFlag &= 254; /* Line 1306, Address: 0x1029a8c */
  } /* Line 1307, Address: 0x1029aa0 */
  else {
    *pScrFlag &= 254; /* Line 1309, Address: 0x1029aa8 */

    if (*pScrFlag & 2) { /* Line 1311, Address: 0x1029abc */
      *pScrFlag &= 253; /* Line 1312, Address: 0x1029ad4 */
      lD4.w.l = 224; /* Line 1313, Address: 0x1029ae8 */
    } /* Line 1314, Address: 0x1029af0 */
    else {
      *pScrFlag &= 253; /* Line 1316, Address: 0x1029af8 */
      goto label1; /* Line 1317, Address: 0x1029b0c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1322, Address: 0x1029b14 */
  wD0 &= 127; /* Line 1323, Address: 0x1029b64 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1324, Address: 0x1029b6c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1330, Address: 0x1029b8c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1331, Address: 0x1029bac */
  if (wD0 != 0) { /* Line 1332, Address: 0x1029bd0 */
    wD5 = 65520; /* Line 1333, Address: 0x1029bdc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1334, Address: 0x1029be4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1336, Address: 0x1029c04 */



  } /* Line 1340, Address: 0x1029c30 */
  else {

    wD5 = 0; /* Line 1343, Address: 0x1029c38 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1344, Address: 0x1029c3c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1348, Address: 0x1029c5c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1355, Address: 0x1029c88 */






    lD4.l = -16; /* Line 1362, Address: 0x1029c9c */
    wD5 = 65520; /* Line 1363, Address: 0x1029ca4 */
    if (*pScrFlag & 168) { /* Line 1364, Address: 0x1029cac */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1365, Address: 0x1029cc4 */
      wD5 = 320; /* Line 1366, Address: 0x1029ce4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1370, Address: 0x1029cec */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1372, Address: 0x1029d1c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1373, Address: 0x1029d28 */



    for (i = 0; i < 16; ++i) { /* Line 1377, Address: 0x1029d38 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1378, Address: 0x1029d44 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1379, Address: 0x1029d64 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1380, Address: 0x1029d9c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1381, Address: 0x1029dbc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1383, Address: 0x1029de0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1386, Address: 0x1029e04 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1388, Address: 0x1029e24 */
      }
      lD4.w.l += 16; /* Line 1390, Address: 0x1029e38 */
    } /* Line 1391, Address: 0x1029e44 */
    *pScrFlag = 0; /* Line 1392, Address: 0x1029e54 */
  }
} /* Line 1394, Address: 0x1029e5c */





void scrollwrtc() {} /* Line 1400, Address: 0x1029e90 */




void scrollwrtz() {} /* Line 1405, Address: 0x1029ea0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1423, Address: 0x1029eb0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1436, Address: 0x1029ed8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1439, Address: 0x1029ef8 */
    pTilePoint->x += 2; /* Line 1440, Address: 0x1029f0c */
    if (pTilePoint->x >= 64) { /* Line 1441, Address: 0x1029f20 */
      pTilePoint->x -= 64; /* Line 1442, Address: 0x1029f34 */
    }
    xOffs += 16; /* Line 1444, Address: 0x1029f48 */
  } while (--lpcnt >= 0); /* Line 1445, Address: 0x1029f54 */
} /* Line 1446, Address: 0x1029f68 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1450, Address: 0x1029f80 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1454, Address: 0x1029fa8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1457, Address: 0x1029fc8 */
    pTilePoint->x += 2; /* Line 1458, Address: 0x1029fdc */
    if (pTilePoint->x >= 64) { /* Line 1459, Address: 0x1029ff0 */
      pTilePoint->x -= 64; /* Line 1460, Address: 0x102a004 */
    }
    xOffs += 16; /* Line 1462, Address: 0x102a018 */
  } while (--lpcnt >= 0); /* Line 1463, Address: 0x102a024 */
} /* Line 1464, Address: 0x102a038 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1484, Address: 0x102a050 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1488, Address: 0x102a078 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1491, Address: 0x102a098 */
    pTilePoint->y += 2; /* Line 1492, Address: 0x102a0ac */
    if (pTilePoint->y >= 32) { /* Line 1493, Address: 0x102a0bc */
      pTilePoint->y -= 32; /* Line 1494, Address: 0x102a0d0 */
    }
    yOffs += 16; /* Line 1496, Address: 0x102a0e0 */
  } while (--lpcnt >= 0); /* Line 1497, Address: 0x102a0ec */
} /* Line 1498, Address: 0x102a100 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1517, Address: 0x102a110 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1523, Address: 0x102a144 */

    base = 1; /* Line 1525, Address: 0x102a154 */
  } /* Line 1526, Address: 0x102a158 */
  else if (VramBase == 16384) { /* Line 1527, Address: 0x102a160 */

    base = 0; /* Line 1529, Address: 0x102a170 */
  }
  x = pTilePoint->x; /* Line 1531, Address: 0x102a174 */
  y = pTilePoint->y; /* Line 1532, Address: 0x102a17c */


  frip = BlkIndex & 6144; /* Line 1535, Address: 0x102a184 */
  BlkIndex &= 1023; /* Line 1536, Address: 0x102a18c */
  if (frip == 6144) { /* Line 1537, Address: 0x102a198 */

    p0 = 3, p1 = 2; /* Line 1539, Address: 0x102a1a4 */
    p2 = 1, p3 = 0; /* Line 1540, Address: 0x102a1ac */
  } /* Line 1541, Address: 0x102a1b4 */
  else if (frip & 4096) { /* Line 1542, Address: 0x102a1bc */

    p0 = 2, p1 = 3; /* Line 1544, Address: 0x102a1c8 */
    p2 = 0, p3 = 1; /* Line 1545, Address: 0x102a1d0 */
  } /* Line 1546, Address: 0x102a1d8 */
  else if (frip & 2048) { /* Line 1547, Address: 0x102a1e0 */

    p0 = 1, p1 = 0; /* Line 1549, Address: 0x102a1ec */
    p2 = 3, p3 = 2; /* Line 1550, Address: 0x102a1f4 */
  } /* Line 1551, Address: 0x102a1fc */
  else {

    p0 = 0, p1 = 1; /* Line 1554, Address: 0x102a204 */
    p2 = 2, p3 = 3; /* Line 1555, Address: 0x102a20c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1558, Address: 0x102a214 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1559, Address: 0x102a258 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1560, Address: 0x102a29c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1561, Address: 0x102a2e0 */

} /* Line 1563, Address: 0x102a324 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1581, Address: 0x102a360 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1582, Address: 0x102a380 */
} /* Line 1583, Address: 0x102a3a0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1585, Address: 0x102a3b0 */
  wH_posiw = 0; /* Line 1586, Address: 0x102a3d0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1587, Address: 0x102a3d4 */
} /* Line 1588, Address: 0x102a3f4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1595, Address: 0x102a410 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1601, Address: 0x102a440 */
  yOffs += wV_posiw; /* Line 1602, Address: 0x102a450 */





  if ((short)xOffs < 0) /* Line 1608, Address: 0x102a460 */
    xOffs = 0; /* Line 1609, Address: 0x102a47c */
  if ((short)yOffs < 0) /* Line 1610, Address: 0x102a480 */
    yOffs = 0; /* Line 1611, Address: 0x102a49c */
  if ((short)xOffs >= 16384) /* Line 1612, Address: 0x102a4a0 */
    xOffs = 16383; /* Line 1613, Address: 0x102a4c0 */
  if ((short)yOffs >= 2048) /* Line 1614, Address: 0x102a4c8 */
    yOffs = 2047; /* Line 1615, Address: 0x102a4e8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1616, Address: 0x102a4f0 */
  if (i < 0) i = 0; /* Line 1617, Address: 0x102a538 */

  ScreenNo = pMapWk[i] & 127; /* Line 1619, Address: 0x102a544 */

  if (ScreenNo) { /* Line 1621, Address: 0x102a560 */




    xOffs &= 32767; /* Line 1626, Address: 0x102a568 */
    yOffs &= 32767; /* Line 1627, Address: 0x102a574 */


    xBlk = xOffs; /* Line 1630, Address: 0x102a580 */
    xBlk %= 256; /* Line 1631, Address: 0x102a588 */
    xBlk /= 16; /* Line 1632, Address: 0x102a5a8 */
    yBlk = yOffs; /* Line 1633, Address: 0x102a5c4 */
    yBlk %= 256; /* Line 1634, Address: 0x102a5cc */
    yBlk /= 16; /* Line 1635, Address: 0x102a5ec */

    lpw = pmapwk; /* Line 1637, Address: 0x102a608 */
    lpw += xBlk; /* Line 1638, Address: 0x102a610 */
    lpw += yBlk * 16; /* Line 1639, Address: 0x102a618 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1640, Address: 0x102a624 */
    *pIndex = *lpw; /* Line 1641, Address: 0x102a63c */

    return 1; /* Line 1643, Address: 0x102a64c */
  }

  *pIndex = 0; /* Line 1646, Address: 0x102a658 */
  return 0; /* Line 1647, Address: 0x102a660 */
} /* Line 1648, Address: 0x102a664 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1668, Address: 0x102a690 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1676, Address: 0x102a6b8 */
  if (ScreenNo) { /* Line 1677, Address: 0x102a71c */





    xBlk = xOffs; /* Line 1683, Address: 0x102a724 */
    xBlk %= 256; /* Line 1684, Address: 0x102a72c */
    xBlk /= 16; /* Line 1685, Address: 0x102a74c */
    yBlk = yOffs; /* Line 1686, Address: 0x102a768 */
    yBlk %= 256; /* Line 1687, Address: 0x102a770 */
    yBlk /= 16; /* Line 1688, Address: 0x102a790 */


    lpw = pmapwk; /* Line 1691, Address: 0x102a7ac */
    lpw += xBlk; /* Line 1692, Address: 0x102a7b4 */
    lpw += yBlk * 16; /* Line 1693, Address: 0x102a7bc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1694, Address: 0x102a7c8 */
    *ppBlockNo = lpw; /* Line 1695, Address: 0x102a7e0 */
    *pIndex = *lpw; /* Line 1696, Address: 0x102a7e8 */




    return 1; /* Line 1701, Address: 0x102a7f8 */
  }

  *pIndex = 0; /* Line 1704, Address: 0x102a804 */
  return 0; /* Line 1705, Address: 0x102a80c */
} /* Line 1706, Address: 0x102a810 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1720, Address: 0x102a830 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1727, Address: 0x102a84c */
  pMapWk = (unsigned char*)mapwka; /* Line 1728, Address: 0x102a850 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1729, Address: 0x102a858 */
    *pBlockIndex = BlockNo; /* Line 1730, Address: 0x102a87c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1731, Address: 0x102a888 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1732, Address: 0x102a8a0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1733, Address: 0x102a8b4 */
    }
  }


} /* Line 1738, Address: 0x102a8cc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1752, Address: 0x102a8f0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1753, Address: 0x102a8fc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1754, Address: 0x102a928 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1755, Address: 0x102a974 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1756, Address: 0x102a9a0 */

          return 0; /* Line 1758, Address: 0x102a9ec */
        }
      }
    }
  }

  return 1; /* Line 1764, Address: 0x102a9f8 */
} /* Line 1765, Address: 0x102a9fc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1782, Address: 0x102aa10 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1783, Address: 0x102aa2c */

} /* Line 1785, Address: 0x102aa48 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1787, Address: 0x102aa60 */
  wH_posiw = 0; /* Line 1788, Address: 0x102aa7c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1789, Address: 0x102aa80 */

} /* Line 1791, Address: 0x102aa9c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1793, Address: 0x102aab0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1794, Address: 0x102aac4 */

} /* Line 1796, Address: 0x102aae0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1798, Address: 0x102aaf0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1799, Address: 0x102ab0c */

} /* Line 1801, Address: 0x102ab28 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1803, Address: 0x102ab40 */
  xOffs += wH_posiw; /* Line 1804, Address: 0x102ab58 */
  yOffs += wV_posiw; /* Line 1805, Address: 0x102ab68 */
  yOffs &= 240; /* Line 1806, Address: 0x102ab78 */
  xOffs &= 496; /* Line 1807, Address: 0x102ab84 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1809, Address: 0x102ab90 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1810, Address: 0x102abbc */


} /* Line 1813, Address: 0x102abe8 */















void mapwrt() { /* Line 1829, Address: 0x102ac00 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1836, Address: 0x102ac18 */
  wV_posiw = scra_v_posit.w.h; /* Line 1837, Address: 0x102ac24 */
  pMapWk = (unsigned char*)mapwka; /* Line 1838, Address: 0x102ac30 */
  VramBase = 16384; /* Line 1839, Address: 0x102ac38 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1840, Address: 0x102ac3c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1844, Address: 0x102ac54 */
  VramBase = 24576; /* Line 1845, Address: 0x102ac5c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1846, Address: 0x102ac60 */

} /* Line 1848, Address: 0x102ac70 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1851, Address: 0x102ac90 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1852, Address: 0x102aca8 */
} /* Line 1853, Address: 0x102acc8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1858, Address: 0x102ace0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1862, Address: 0x102ad00 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1865, Address: 0x102ad1c */



    wD4 += 16; /* Line 1869, Address: 0x102ad44 */
  } while ((short)--wD6 >= 0); /* Line 1870, Address: 0x102ad50 */

} /* Line 1872, Address: 0x102ad78 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1878, Address: 0x102ad90 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1881, Address: 0x102adac */
  wD6 = 15; /* Line 1882, Address: 0x102adb4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1885, Address: 0x102adbc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1887, Address: 0x102ade0 */
    wD4 += 16; /* Line 1888, Address: 0x102ae00 */
  } while ((short)--wD6 >= 0); /* Line 1889, Address: 0x102ae08 */
} /* Line 1890, Address: 0x102ae2c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1916, Address: 0x102ae50 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1921, Address: 0x102ae78 */
  wD0 = pWrttbl[wD0]; /* Line 1922, Address: 0x102ae88 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1924, Address: 0x102aea4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1925, Address: 0x102aec8 */
  if (wD0) { /* Line 1926, Address: 0x102aef0 */
    wD5 = 65520; /* Line 1927, Address: 0x102aefc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1928, Address: 0x102af04 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1931, Address: 0x102af20 */



  } /* Line 1935, Address: 0x102af48 */
  else {

    wD5 = 0; /* Line 1938, Address: 0x102af50 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1939, Address: 0x102af54 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1943, Address: 0x102af70 */
  }





} /* Line 1950, Address: 0x102af98 */










void mapinit() { /* Line 1961, Address: 0x102afc0 */

  colorset2(mapinittbl.colorno2); /* Line 1963, Address: 0x102afc8 */
  colorset(mapinittbl.colorno2); /* Line 1964, Address: 0x102afdc */

  if (plflag) enecginit(); /* Line 1966, Address: 0x102aff0 */
  if (play_start & 2) divdevset(); /* Line 1967, Address: 0x102b008 */
} /* Line 1968, Address: 0x102b028 */




void mapset() {} /* Line 1973, Address: 0x102b040 */



void divdevset() {} /* Line 1977, Address: 0x102b050 */



void enecginit() {} /* Line 1981, Address: 0x102b060 */
