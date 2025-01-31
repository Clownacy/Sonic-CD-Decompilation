#include "..\EQU.H"
#include "SCR81A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL8A.H"
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
  {   80,  944 },
  { 3744, 1132 },
  { 5968,  189 },
  { 2560, 1580 },
  { 2992,   76 },
  { 5488,  364 },
  {  432, 1836 },
  { 5120,  684 }
};
short playpositbl[1][2] = { { 48, 1696 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;









































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x101db60 */
    return &actwk[0]; /* Line 147, Address: 0x101db74 */
  else
    return &actwk[1]; /* Line 149, Address: 0x101db84 */

} /* Line 151, Address: 0x101db8c */





































void scr_set() { /* Line 189, Address: 0x101dba0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x101dbac */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x101dbc0 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x101dbd4 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x101dbdc */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x101dbe4 */
  ++pScrTbl; /* Line 198, Address: 0x101dbf0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x101dbf4 */
  ++pScrTbl; /* Line 200, Address: 0x101dc08 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x101dc0c */
  ++pScrTbl; /* Line 202, Address: 0x101dc20 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x101dc24 */
  ++pScrTbl; /* Line 204, Address: 0x101dc38 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x101dc3c */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x101dc50 */
  ++pScrTbl; /* Line 207, Address: 0x101dc70 */
  scra_h_count = 16; /* Line 208, Address: 0x101dc74 */
  scra_v_count = 16; /* Line 209, Address: 0x101dc80 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x101dc8c */
  scra_hline = 160; /* Line 212, Address: 0x101dc98 */

  playposiset(); /* Line 214, Address: 0x101dca4 */
} /* Line 215, Address: 0x101dcac */
















































static void playposiset() { /* Line 264, Address: 0x101dcc0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x101dcd4 */
    playload(); /* Line 268, Address: 0x101dce4 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x101dcec */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x101dcfc */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x101dd14 */
    } else { /* Line 273, Address: 0x101dd24 */
      ywk = 0; /* Line 274, Address: 0x101dd2c */
    }
  } /* Line 276, Address: 0x101dd30 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x101dd38 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x101dd58 */
    } /* Line 280, Address: 0x101dd7c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x101dd84 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x101dda4 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x101ddb8 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x101ddcc */
    xwk -= 160; /* Line 292, Address: 0x101dde0 */
  } else { /* Line 293, Address: 0x101ddec */
    xwk = 0; /* Line 294, Address: 0x101ddf4 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x101ddf8 */
    xwk = scralim_right; /* Line 299, Address: 0x101de1c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x101de2c */

  if (ywk > 96) { /* Line 305, Address: 0x101de34 */
    ywk -= 96; /* Line 306, Address: 0x101de48 */
  } else { /* Line 307, Address: 0x101de54 */
    ywk = 0; /* Line 308, Address: 0x101de5c */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x101de60 */
    ywk = scralim_down; /* Line 313, Address: 0x101de84 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x101de94 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x101de9c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x101deac */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x101debc */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x101decc */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x101dedc */
} /* Line 326, Address: 0x101deec */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x101df10 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x101df1c */
  lYwk.w.l = 0; /* Line 351, Address: 0x101df24 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x101df28 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x101df34 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x101df40 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x101df4c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x101df58 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x101df74 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x101df80 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x101df9c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x101dfa8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x101dfc4 */
} /* Line 366, Address: 0x101dfe8 */















void scroll() { /* Line 382, Address: 0x101e000 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x101e01c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x101e02c */

  scrchk(); /* Line 401, Address: 0x101e058 */

  scroll_h(); /* Line 403, Address: 0x101e060 */
  scroll_v(); /* Line 404, Address: 0x101e068 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x101e070 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x101e080 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x101e090 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x101e0a4 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x101e0b4 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x101e0c8 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x101e0d8 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x101e0f4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x101e104 */


  scrollb_v(lYwk); /* Line 422, Address: 0x101e118 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x101e128 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x101e150 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x101e188 */

  psHscw = hscrollwork; /* Line 429, Address: 0x101e19c */

  z81aline(&psHscw); /* Line 431, Address: 0x101e1a8 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 433, Address: 0x101e1b4 */
  for (i = 0; i < 16; ++i) { /* Line 434, Address: 0x101e1d4 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x101e1e0 */
  } /* Line 437, Address: 0x101e1f4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x101e204 */
  for (i = 0; i < 28; ++i) { /* Line 440, Address: 0x101e224 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x101e230 */
  } /* Line 443, Address: 0x101e244 */

  z81aline(&psHscw); /* Line 445, Address: 0x101e254 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 447, Address: 0x101e260 */
  for (i = 0; i < 12; ++i) { /* Line 448, Address: 0x101e280 */

    *psHscw++ = ldwk.w.l; /* Line 450, Address: 0x101e28c */
  } /* Line 451, Address: 0x101e2a0 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 453, Address: 0x101e2b0 */
  for (i = 0; i < 12; ++i) { /* Line 454, Address: 0x101e2d0 */

    *psHscw++ = ldwk.w.l; /* Line 456, Address: 0x101e2dc */
  } /* Line 457, Address: 0x101e2f0 */

  pHscrbuf = lphscrollbuff; /* Line 459, Address: 0x101e300 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 460, Address: 0x101e30c */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 461, Address: 0x101e33c */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 462, Address: 0x101e36c */
} /* Line 463, Address: 0x101e388 */













static void z81aline(short** ppHscw) { /* Line 477, Address: 0x101e3b0 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z81ascrtbl[5] = {
    3, 4, 2, 0, 0
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 486, Address: 0x101e3c8 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 487, Address: 0x101e3ec */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 488, Address: 0x101e40c */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 489, Address: 0x101e42c */
  *ppHscw += 14; /* Line 490, Address: 0x101e438 */

  for (i = 4; i >= 0; --i) { /* Line 492, Address: 0x101e44c */

    wk = -ldwk.w.l; /* Line 494, Address: 0x101e458 */

    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 496, Address: 0x101e478 */

      --*ppHscw; /* Line 498, Address: 0x101e498 */
      **ppHscw = wk; /* Line 499, Address: 0x101e4ac */
    } /* Line 500, Address: 0x101e4b8 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 502, Address: 0x101e4c4 */
    ldwk.l += lXwk; /* Line 503, Address: 0x101e4e8 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 504, Address: 0x101e4f4 */
  } /* Line 505, Address: 0x101e518 */

  *ppHscw += 14; /* Line 507, Address: 0x101e524 */
} /* Line 508, Address: 0x101e538 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 529, Address: 0x101e560 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 533, Address: 0x101e57c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 534, Address: 0x101e580 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 536, Address: 0x101e5a0 */
    ldwk.w.l = *pHscrwk; /* Line 537, Address: 0x101e5bc */
    ++pHscrwk; /* Line 538, Address: 0x101e5c8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 540, Address: 0x101e5d4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 541, Address: 0x101e5dc */
    } /* Line 542, Address: 0x101e5ec */
  } /* Line 543, Address: 0x101e610 */
} /* Line 544, Address: 0x101e630 */









































































































static void scrollb_v(short yPos) { /* Line 650, Address: 0x101e650 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 653, Address: 0x101e660 */
  scrb_v_posit.w.h = yPos; /* Line 654, Address: 0x101e670 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 655, Address: 0x101e67c */

  if (!ywk) { /* Line 657, Address: 0x101e6b4 */
    scrb_v_count ^= 16; /* Line 658, Address: 0x101e6bc */
    if (yPos - ysv < 0) { /* Line 659, Address: 0x101e6d0 */
      scrflagb.b.h |= 1; /* Line 660, Address: 0x101e6f0 */
    } /* Line 661, Address: 0x101e704 */
    else {
      scrflagb.b.h |= 2; /* Line 663, Address: 0x101e70c */
    }
  }


} /* Line 668, Address: 0x101e720 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 686, Address: 0x101e740 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 690, Address: 0x101e754 */
  lXwk = lXsv + xoffs; /* Line 691, Address: 0x101e75c */
  scrb_h_posit.l = lXwk; /* Line 692, Address: 0x101e764 */
  ldXwk.l = lXwk; /* Line 693, Address: 0x101e76c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 694, Address: 0x101e770 */
  ldXwk.w.l &= 16; /* Line 695, Address: 0x101e794 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 696, Address: 0x101e7a0 */

  if (!ldXwk.b.b4) { /* Line 698, Address: 0x101e7bc */
    scrb_h_count ^= 16; /* Line 699, Address: 0x101e7c8 */
    if (lXwk - lXsv < 0) { /* Line 700, Address: 0x101e7dc */
      scrflagb.b.h |= 1 << flgbit; /* Line 701, Address: 0x101e7e8 */
    } /* Line 702, Address: 0x101e80c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 704, Address: 0x101e814 */
    }
  }


} /* Line 709, Address: 0x101e83c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 727, Address: 0x101e850 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 731, Address: 0x101e864 */
  lXwk = lXsv + xoffs; /* Line 732, Address: 0x101e86c */
  scrc_h_posit.l = lXwk; /* Line 733, Address: 0x101e874 */
  ldXwk.l = lXwk; /* Line 734, Address: 0x101e87c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 735, Address: 0x101e880 */
  ldXwk.w.l &= 16; /* Line 736, Address: 0x101e8a4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 737, Address: 0x101e8b0 */

  if (!ldXwk.b.b4) { /* Line 739, Address: 0x101e8cc */
    scrc_h_count ^= 16; /* Line 740, Address: 0x101e8d8 */
    if (lXwk - lXsv < 0) { /* Line 741, Address: 0x101e8ec */
      scrflagc.b.h |= 1 << flgbit; /* Line 742, Address: 0x101e8f8 */
    } /* Line 743, Address: 0x101e91c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 745, Address: 0x101e924 */
    }
  }


} /* Line 750, Address: 0x101e94c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 768, Address: 0x101e960 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 772, Address: 0x101e974 */
  lXwk = lXsv + xoffs; /* Line 773, Address: 0x101e97c */
  scrz_h_posit.l = lXwk; /* Line 774, Address: 0x101e984 */
  ldXwk.l = lXwk; /* Line 775, Address: 0x101e98c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 776, Address: 0x101e990 */
  ldXwk.w.l &= 16; /* Line 777, Address: 0x101e9b4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 778, Address: 0x101e9c0 */

  if (!ldXwk.b.b4) { /* Line 780, Address: 0x101e9dc */
    scrz_h_count ^= 16; /* Line 781, Address: 0x101e9e8 */
    if (lXwk - lXsv < 0) { /* Line 782, Address: 0x101e9fc */
      scrflagz.b.h |= 1 << flgbit; /* Line 783, Address: 0x101ea08 */
    } /* Line 784, Address: 0x101ea2c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 786, Address: 0x101ea34 */
    }
  }


} /* Line 791, Address: 0x101ea5c */














static void scroll_h() { /* Line 806, Address: 0x101ea70 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 810, Address: 0x101ea80 */

  scrh_move(); /* Line 812, Address: 0x101ea90 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 813, Address: 0x101ea98 */
  if (!bXwk) { /* Line 814, Address: 0x101eacc */
    scra_h_count ^= 16; /* Line 815, Address: 0x101ead4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 816, Address: 0x101eae8 */
      scrflaga.b.h |= 4; /* Line 817, Address: 0x101eb0c */
    } else { /* Line 818, Address: 0x101eb20 */
      scrflaga.b.h |= 8; /* Line 819, Address: 0x101eb28 */
    }
  }


} /* Line 824, Address: 0x101eb3c */
















static void scrh_move() { /* Line 841, Address: 0x101eb60 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 844, Address: 0x101eb68 */
  if (xwk == 0) { /* Line 845, Address: 0x101ebb0 */

    scra_hz = 0; /* Line 847, Address: 0x101ebc0 */
    return; /* Line 848, Address: 0x101ebc8 */
  } else if (xwk < 0) { /* Line 849, Address: 0x101ebd0 */

    if (xwk < -16) { /* Line 851, Address: 0x101ebe0 */
      xwk = -16; /* Line 852, Address: 0x101ebf4 */
    }


    xwk += scra_h_posit.w.h; /* Line 856, Address: 0x101ec00 */
    if (xwk < scralim_left) { /* Line 857, Address: 0x101ec14 */
      xwk = scralim_left; /* Line 858, Address: 0x101ec38 */
    }
  } /* Line 860, Address: 0x101ec48 */
  else {
    if (xwk > 16) { /* Line 862, Address: 0x101ec50 */
      xwk = 16; /* Line 863, Address: 0x101ec64 */
    }


    xwk += scra_h_posit.w.h; /* Line 867, Address: 0x101ec70 */
    if (xwk > scralim_right) { /* Line 868, Address: 0x101ec84 */
      xwk = scralim_right; /* Line 869, Address: 0x101eca8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 874, Address: 0x101ecb8 */
  scra_h_posit.w.h = xwk; /* Line 875, Address: 0x101ece8 */
} /* Line 876, Address: 0x101ecf0 */














static void scroll_v() { /* Line 891, Address: 0x101ed00 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 894, Address: 0x101ed0c */
  if (actwk[0].cddat & 4) { /* Line 895, Address: 0x101ed40 */
    ywk -= 5; /* Line 896, Address: 0x101ed58 */
  }


  if (actwk[0].cddat & 2) { /* Line 900, Address: 0x101ed64 */
    ywk += 32; /* Line 901, Address: 0x101ed7c */
    if (ywk < scra_vline) { /* Line 902, Address: 0x101ed88 */
      ywk -= scra_vline; /* Line 903, Address: 0x101edac */
      sv_move_main2(ywk); /* Line 904, Address: 0x101edc0 */
      return; /* Line 905, Address: 0x101edcc */
    } else if (ywk >= scra_vline + 64) { /* Line 906, Address: 0x101edd4 */
      ywk -= scra_vline + 64; /* Line 907, Address: 0x101edfc */
      sv_move_main2(ywk); /* Line 908, Address: 0x101ee24 */
      return; /* Line 909, Address: 0x101ee30 */
    }
    ywk -= scra_vline + 64; /* Line 911, Address: 0x101ee38 */
    if (!limmoveflag) goto label1; /* Line 912, Address: 0x101ee60 */
    sv_move_sub2(); /* Line 913, Address: 0x101ee70 */
    return; /* Line 914, Address: 0x101ee78 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 919, Address: 0x101ee80 */
    sv_move_main(ywk); /* Line 920, Address: 0x101eeac */
    return; /* Line 921, Address: 0x101eeb8 */
  } else if (!limmoveflag) goto label1; /* Line 922, Address: 0x101eec0 */
  sv_move_sub2(); /* Line 923, Address: 0x101eed0 */
  return; /* Line 924, Address: 0x101eed8 */



label1:
  scra_vz = 0; /* Line 929, Address: 0x101eee0 */
} /* Line 930, Address: 0x101eee8 */













static void sv_move_main(short yPos) { /* Line 944, Address: 0x101ef00 */
  short spdwk;

  if (scra_vline == 96) { /* Line 947, Address: 0x101ef10 */
    if (actwk[0].mspeed.w < 0) { /* Line 948, Address: 0x101ef2c */
      spdwk = -actwk[0].mspeed.w; /* Line 949, Address: 0x101ef44 */
    } else { /* Line 950, Address: 0x101ef68 */
      spdwk = actwk[0].mspeed.w; /* Line 951, Address: 0x101ef70 */
    }


    if (spdwk >= 2048) { /* Line 955, Address: 0x101ef80 */
      sv_move_main2(yPos); /* Line 956, Address: 0x101ef94 */
    } /* Line 957, Address: 0x101efa0 */
    else {

      if (yPos > 6) { /* Line 960, Address: 0x101efa8 */
        sv_move_plus(1536); /* Line 961, Address: 0x101efc0 */
      } else if (yPos < -6) { /* Line 962, Address: 0x101efcc */
        sv_move_minus(1536); /* Line 963, Address: 0x101efec */
      } /* Line 964, Address: 0x101eff8 */
      else sv_move_sub(yPos); /* Line 965, Address: 0x101f000 */
    }
  } /* Line 967, Address: 0x101f00c */
  else {
    if (yPos > 2) { /* Line 969, Address: 0x101f014 */
      sv_move_plus(512); /* Line 970, Address: 0x101f02c */
    } else if (yPos < -2) { /* Line 971, Address: 0x101f038 */
      sv_move_minus(512); /* Line 972, Address: 0x101f058 */
    } /* Line 973, Address: 0x101f064 */
    else sv_move_sub(yPos); /* Line 974, Address: 0x101f06c */
  }

} /* Line 977, Address: 0x101f078 */













static void sv_move_main2(short yPos) { /* Line 991, Address: 0x101f090 */
  short spdwk;

  spdwk = 4096; /* Line 994, Address: 0x101f0a0 */

  if (yPos > 16) { /* Line 996, Address: 0x101f0ac */
    sv_move_plus(spdwk); /* Line 997, Address: 0x101f0c4 */
  } else if (yPos < -16) { /* Line 998, Address: 0x101f0d0 */
    sv_move_minus(spdwk); /* Line 999, Address: 0x101f0f0 */
  } else { /* Line 1000, Address: 0x101f0fc */
    sv_move_sub(yPos); /* Line 1001, Address: 0x101f104 */
  }
} /* Line 1003, Address: 0x101f110 */














static void sv_move_sub(short yPos) { /* Line 1018, Address: 0x101f130 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1021, Address: 0x101f13c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1022, Address: 0x101f140 */
  if (yPos < 0) { /* Line 1023, Address: 0x101f16c */
    scrv_up_ch(lSpd); /* Line 1024, Address: 0x101f180 */
  } else { /* Line 1025, Address: 0x101f18c */
    scrv_down_ch(lSpd); /* Line 1026, Address: 0x101f194 */
  }
} /* Line 1028, Address: 0x101f1a0 */



static void sv_move_sub2() { /* Line 1032, Address: 0x101f1b0 */
  limmoveflag = 0; /* Line 1033, Address: 0x101f1b8 */

  sv_move_sub(0); /* Line 1035, Address: 0x101f1c0 */
} /* Line 1036, Address: 0x101f1cc */













static void sv_move_minus(short speed) { /* Line 1050, Address: 0x101f1e0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1053, Address: 0x101f1ec */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1054, Address: 0x101f210 */
  scrv_up_ch(lSpd); /* Line 1055, Address: 0x101f234 */
} /* Line 1056, Address: 0x101f240 */














static void scrv_up_ch(int_union lSpd) { /* Line 1071, Address: 0x101f250 */
  if (lSpd.w.l <= scralim_up) { /* Line 1072, Address: 0x101f25c */
    if (lSpd.w.l > -256) { /* Line 1073, Address: 0x101f284 */

      lSpd.w.l = scralim_up; /* Line 1075, Address: 0x101f29c */
    } else { /* Line 1076, Address: 0x101f2a8 */
      lSpd.w.l &= 2047; /* Line 1077, Address: 0x101f2b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1078, Address: 0x101f2bc */
      scra_v_posit.w.h &= 2047; /* Line 1079, Address: 0x101f2d0 */
      scrb_v_posit.w.h &= 1023; /* Line 1080, Address: 0x101f2e4 */
    }
  }

  scrv_move(lSpd); /* Line 1084, Address: 0x101f2f8 */
} /* Line 1085, Address: 0x101f304 */













static void sv_move_plus(short sSpd) { /* Line 1099, Address: 0x101f320 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1102, Address: 0x101f32c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1103, Address: 0x101f34c */
  scrv_down_ch(lSpd); /* Line 1104, Address: 0x101f370 */
} /* Line 1105, Address: 0x101f37c */














static void scrv_down_ch(int_union lSpd) { /* Line 1120, Address: 0x101f390 */
  if (lSpd.w.l >= scralim_down) { /* Line 1121, Address: 0x101f39c */
    if (lSpd.w.l < 2048) { /* Line 1122, Address: 0x101f3c4 */

      lSpd.w.l = scralim_down; /* Line 1124, Address: 0x101f3dc */
    } else { /* Line 1125, Address: 0x101f3e8 */
      lSpd.w.l -= 2048; /* Line 1126, Address: 0x101f3f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1127, Address: 0x101f3fc */
      scra_v_posit.w.h -= 2048; /* Line 1128, Address: 0x101f410 */
      scrb_v_posit.w.h &= 1023; /* Line 1129, Address: 0x101f424 */
    }
  }

  scrv_move(lSpd); /* Line 1133, Address: 0x101f438 */
} /* Line 1134, Address: 0x101f444 */
















static void scrv_move(int_union lSpd) { /* Line 1151, Address: 0x101f460 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1155, Address: 0x101f470 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1156, Address: 0x101f480 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1157, Address: 0x101f4a4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1158, Address: 0x101f4b8 */
  scra_vz = spdwk.w.l; /* Line 1159, Address: 0x101f4d0 */

  scra_v_posit.l = lSpd.l; /* Line 1161, Address: 0x101f4dc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1163, Address: 0x101f4e8 */
  if (!ywk) { /* Line 1164, Address: 0x101f524 */
    scra_v_count ^= 16; /* Line 1165, Address: 0x101f52c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1166, Address: 0x101f540 */
    if (ywk < 0) { /* Line 1167, Address: 0x101f56c */
      scrflaga.b.h |= 1; /* Line 1168, Address: 0x101f57c */
    } else { /* Line 1169, Address: 0x101f590 */
      scrflaga.b.h |= 2; /* Line 1170, Address: 0x101f598 */
    }
  }


} /* Line 1175, Address: 0x101f5ac */

















void scrollwrt() { /* Line 1193, Address: 0x101f5c0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1202, Address: 0x101f5e0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1203, Address: 0x101f5e4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1204, Address: 0x101f5f0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1205, Address: 0x101f5fc */
  pScrFlag = &scrflagbw.b.h; /* Line 1206, Address: 0x101f604 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1207, Address: 0x101f60c */

  VramBase = 16384; /* Line 1209, Address: 0x101f620 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1210, Address: 0x101f624 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1211, Address: 0x101f630 */
  pMapWk = (unsigned char*)mapwka; /* Line 1212, Address: 0x101f63c */
  pScrFlag = &scrflagaw.b.h; /* Line 1213, Address: 0x101f644 */

  if (*pScrFlag) { /* Line 1215, Address: 0x101f64c */
    if (*pScrFlag & 1) { /* Line 1216, Address: 0x101f658 */
      *pScrFlag &= 254; /* Line 1217, Address: 0x101f66c */

      lD4.l = -16; /* Line 1219, Address: 0x101f678 */
      wD5 = 65520; /* Line 1220, Address: 0x101f680 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1222, Address: 0x101f688 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1224, Address: 0x101f6a8 */
    }




    if (*pScrFlag & 2) { /* Line 1230, Address: 0x101f6d4 */
      *pScrFlag &= 253; /* Line 1231, Address: 0x101f6e8 */

      lD4.l = 224; /* Line 1233, Address: 0x101f6f4 */
      wD5 = 65520; /* Line 1234, Address: 0x101f6fc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1235, Address: 0x101f704 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1237, Address: 0x101f724 */
    }




    if (*pScrFlag & 4) { /* Line 1243, Address: 0x101f750 */
      *pScrFlag &= 251; /* Line 1244, Address: 0x101f764 */

      lD4.l = -16; /* Line 1246, Address: 0x101f770 */
      wD5 = 65520; /* Line 1247, Address: 0x101f778 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1248, Address: 0x101f780 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1250, Address: 0x101f7a0 */
    }




    if (*pScrFlag & 8) { /* Line 1256, Address: 0x101f7cc */
      *pScrFlag &= 247; /* Line 1257, Address: 0x101f7e0 */

      lD4.l = -16; /* Line 1259, Address: 0x101f7ec */
      wD5 = 320; /* Line 1260, Address: 0x101f7f4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1261, Address: 0x101f7fc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1263, Address: 0x101f81c */
    }
  }






} /* Line 1272, Address: 0x101f848 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1289, Address: 0x101f870 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1300, Address: 0x101f89c */

  if (*pScrFlag & 1) { /* Line 1302, Address: 0x101f8a4 */
    *pScrFlag &= 254; /* Line 1303, Address: 0x101f8bc */
  } /* Line 1304, Address: 0x101f8d0 */
  else {
    *pScrFlag &= 254; /* Line 1306, Address: 0x101f8d8 */

    if (*pScrFlag & 2) { /* Line 1308, Address: 0x101f8ec */
      *pScrFlag &= 253; /* Line 1309, Address: 0x101f904 */
      lD4.w.l = 224; /* Line 1310, Address: 0x101f918 */
    } /* Line 1311, Address: 0x101f920 */
    else {
      *pScrFlag &= 253; /* Line 1313, Address: 0x101f928 */
      goto label1; /* Line 1314, Address: 0x101f93c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1319, Address: 0x101f944 */
  wD0 &= 127; /* Line 1320, Address: 0x101f994 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1321, Address: 0x101f99c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1327, Address: 0x101f9bc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1328, Address: 0x101f9dc */
  if (wD0 != 0) { /* Line 1329, Address: 0x101fa00 */
    wD5 = 65520; /* Line 1330, Address: 0x101fa0c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x101fa14 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1333, Address: 0x101fa34 */



  } /* Line 1337, Address: 0x101fa60 */
  else {

    wD5 = 0; /* Line 1340, Address: 0x101fa68 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1341, Address: 0x101fa6c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1345, Address: 0x101fa8c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1352, Address: 0x101fab8 */






    lD4.l = -16; /* Line 1359, Address: 0x101facc */
    wD5 = 65520; /* Line 1360, Address: 0x101fad4 */
    if (*pScrFlag & 168) { /* Line 1361, Address: 0x101fadc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1362, Address: 0x101faf4 */
      wD5 = 320; /* Line 1363, Address: 0x101fb14 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1367, Address: 0x101fb1c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1369, Address: 0x101fb4c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1370, Address: 0x101fb58 */



    for (i = 0; i < 16; ++i) { /* Line 1374, Address: 0x101fb68 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1375, Address: 0x101fb74 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1376, Address: 0x101fb94 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1377, Address: 0x101fbcc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1378, Address: 0x101fbec */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1380, Address: 0x101fc10 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1383, Address: 0x101fc34 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1385, Address: 0x101fc54 */
      }
      lD4.w.l += 16; /* Line 1387, Address: 0x101fc68 */
    } /* Line 1388, Address: 0x101fc74 */
    *pScrFlag = 0; /* Line 1389, Address: 0x101fc84 */
  }
} /* Line 1391, Address: 0x101fc8c */





void scrollwrtc() {} /* Line 1397, Address: 0x101fcc0 */




void scrollwrtz() {} /* Line 1402, Address: 0x101fcd0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1420, Address: 0x101fce0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1433, Address: 0x101fd08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1436, Address: 0x101fd28 */
    pTilePoint->x += 2; /* Line 1437, Address: 0x101fd3c */
    if (pTilePoint->x >= 64) { /* Line 1438, Address: 0x101fd50 */
      pTilePoint->x -= 64; /* Line 1439, Address: 0x101fd64 */
    }
    xOffs += 16; /* Line 1441, Address: 0x101fd78 */
  } while (--lpcnt >= 0); /* Line 1442, Address: 0x101fd84 */
} /* Line 1443, Address: 0x101fd98 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1447, Address: 0x101fdb0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1451, Address: 0x101fdd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1454, Address: 0x101fdf8 */
    pTilePoint->x += 2; /* Line 1455, Address: 0x101fe0c */
    if (pTilePoint->x >= 64) { /* Line 1456, Address: 0x101fe20 */
      pTilePoint->x -= 64; /* Line 1457, Address: 0x101fe34 */
    }
    xOffs += 16; /* Line 1459, Address: 0x101fe48 */
  } while (--lpcnt >= 0); /* Line 1460, Address: 0x101fe54 */
} /* Line 1461, Address: 0x101fe68 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1481, Address: 0x101fe80 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1485, Address: 0x101fea8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1488, Address: 0x101fec8 */
    pTilePoint->y += 2; /* Line 1489, Address: 0x101fedc */
    if (pTilePoint->y >= 32) { /* Line 1490, Address: 0x101feec */
      pTilePoint->y -= 32; /* Line 1491, Address: 0x101ff00 */
    }
    yOffs += 16; /* Line 1493, Address: 0x101ff10 */
  } while (--lpcnt >= 0); /* Line 1494, Address: 0x101ff1c */
} /* Line 1495, Address: 0x101ff30 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1514, Address: 0x101ff40 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1520, Address: 0x101ff74 */

    base = 1; /* Line 1522, Address: 0x101ff84 */
  } /* Line 1523, Address: 0x101ff88 */
  else if (VramBase == 16384) { /* Line 1524, Address: 0x101ff90 */

    base = 0; /* Line 1526, Address: 0x101ffa0 */
  }
  x = pTilePoint->x; /* Line 1528, Address: 0x101ffa4 */
  y = pTilePoint->y; /* Line 1529, Address: 0x101ffac */


  frip = BlkIndex & 6144; /* Line 1532, Address: 0x101ffb4 */
  BlkIndex &= 1023; /* Line 1533, Address: 0x101ffbc */
  if (frip == 6144) { /* Line 1534, Address: 0x101ffc8 */

    p0 = 3, p1 = 2; /* Line 1536, Address: 0x101ffd4 */
    p2 = 1, p3 = 0; /* Line 1537, Address: 0x101ffdc */
  } /* Line 1538, Address: 0x101ffe4 */
  else if (frip & 4096) { /* Line 1539, Address: 0x101ffec */

    p0 = 2, p1 = 3; /* Line 1541, Address: 0x101fff8 */
    p2 = 0, p3 = 1; /* Line 1542, Address: 0x1020000 */
  } /* Line 1543, Address: 0x1020008 */
  else if (frip & 2048) { /* Line 1544, Address: 0x1020010 */

    p0 = 1, p1 = 0; /* Line 1546, Address: 0x102001c */
    p2 = 3, p3 = 2; /* Line 1547, Address: 0x1020024 */
  } /* Line 1548, Address: 0x102002c */
  else {

    p0 = 0, p1 = 1; /* Line 1551, Address: 0x1020034 */
    p2 = 2, p3 = 3; /* Line 1552, Address: 0x102003c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1555, Address: 0x1020044 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1556, Address: 0x1020088 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1557, Address: 0x10200cc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1558, Address: 0x1020110 */

} /* Line 1560, Address: 0x1020154 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1578, Address: 0x1020190 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1579, Address: 0x10201b0 */
} /* Line 1580, Address: 0x10201d0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1582, Address: 0x10201e0 */
  wH_posiw = 0; /* Line 1583, Address: 0x1020200 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1584, Address: 0x1020204 */
} /* Line 1585, Address: 0x1020224 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1592, Address: 0x1020240 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1598, Address: 0x1020270 */
  yOffs += wV_posiw; /* Line 1599, Address: 0x1020280 */





  if ((short)xOffs < 0) /* Line 1605, Address: 0x1020290 */
    xOffs = 0; /* Line 1606, Address: 0x10202ac */
  if ((short)yOffs < 0) /* Line 1607, Address: 0x10202b0 */
    yOffs = 0; /* Line 1608, Address: 0x10202cc */
  if ((short)xOffs >= 16384) /* Line 1609, Address: 0x10202d0 */
    xOffs = 16383; /* Line 1610, Address: 0x10202f0 */
  if ((short)yOffs >= 2048) /* Line 1611, Address: 0x10202f8 */
    yOffs = 2047; /* Line 1612, Address: 0x1020318 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1613, Address: 0x1020320 */
  if (i < 0) i = 0; /* Line 1614, Address: 0x1020368 */

  ScreenNo = pMapWk[i] & 127; /* Line 1616, Address: 0x1020374 */

  if (ScreenNo) { /* Line 1618, Address: 0x1020390 */




    xOffs &= 32767; /* Line 1623, Address: 0x1020398 */
    yOffs &= 32767; /* Line 1624, Address: 0x10203a4 */


    xBlk = xOffs; /* Line 1627, Address: 0x10203b0 */
    xBlk %= 256; /* Line 1628, Address: 0x10203b8 */
    xBlk /= 16; /* Line 1629, Address: 0x10203d8 */
    yBlk = yOffs; /* Line 1630, Address: 0x10203f4 */
    yBlk %= 256; /* Line 1631, Address: 0x10203fc */
    yBlk /= 16; /* Line 1632, Address: 0x102041c */

    lpw = pmapwk; /* Line 1634, Address: 0x1020438 */
    lpw += xBlk; /* Line 1635, Address: 0x1020440 */
    lpw += yBlk * 16; /* Line 1636, Address: 0x1020448 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1637, Address: 0x1020454 */
    *pIndex = *lpw; /* Line 1638, Address: 0x102046c */

    return 1; /* Line 1640, Address: 0x102047c */
  }

  *pIndex = 0; /* Line 1643, Address: 0x1020488 */
  return 0; /* Line 1644, Address: 0x1020490 */
} /* Line 1645, Address: 0x1020494 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1665, Address: 0x10204c0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1673, Address: 0x10204e8 */
  if (ScreenNo) { /* Line 1674, Address: 0x102054c */





    xBlk = xOffs; /* Line 1680, Address: 0x1020554 */
    xBlk %= 256; /* Line 1681, Address: 0x102055c */
    xBlk /= 16; /* Line 1682, Address: 0x102057c */
    yBlk = yOffs; /* Line 1683, Address: 0x1020598 */
    yBlk %= 256; /* Line 1684, Address: 0x10205a0 */
    yBlk /= 16; /* Line 1685, Address: 0x10205c0 */


    lpw = pmapwk; /* Line 1688, Address: 0x10205dc */
    lpw += xBlk; /* Line 1689, Address: 0x10205e4 */
    lpw += yBlk * 16; /* Line 1690, Address: 0x10205ec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1691, Address: 0x10205f8 */
    *ppBlockNo = lpw; /* Line 1692, Address: 0x1020610 */
    *pIndex = *lpw; /* Line 1693, Address: 0x1020618 */




    return 1; /* Line 1698, Address: 0x1020628 */
  }

  *pIndex = 0; /* Line 1701, Address: 0x1020634 */
  return 0; /* Line 1702, Address: 0x102063c */
} /* Line 1703, Address: 0x1020640 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1717, Address: 0x1020660 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1724, Address: 0x102067c */
  pMapWk = (unsigned char*)mapwka; /* Line 1725, Address: 0x1020680 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1726, Address: 0x1020688 */
    *pBlockIndex = BlockNo; /* Line 1727, Address: 0x10206ac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1728, Address: 0x10206b8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1729, Address: 0x10206d0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1730, Address: 0x10206e4 */
    }
  }


} /* Line 1735, Address: 0x10206fc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1749, Address: 0x1020720 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1750, Address: 0x102072c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1751, Address: 0x1020758 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1752, Address: 0x10207a4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1753, Address: 0x10207d0 */

          return 0; /* Line 1755, Address: 0x102081c */
        }
      }
    }
  }

  return 1; /* Line 1761, Address: 0x1020828 */
} /* Line 1762, Address: 0x102082c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x1020840 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x102085c */

} /* Line 1782, Address: 0x1020878 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x1020890 */
  wH_posiw = 0; /* Line 1785, Address: 0x10208ac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1786, Address: 0x10208b0 */

} /* Line 1788, Address: 0x10208cc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1790, Address: 0x10208e0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1791, Address: 0x10208f4 */

} /* Line 1793, Address: 0x1020910 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1795, Address: 0x1020920 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1796, Address: 0x102093c */

} /* Line 1798, Address: 0x1020958 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1800, Address: 0x1020970 */
  xOffs += wH_posiw; /* Line 1801, Address: 0x1020988 */
  yOffs += wV_posiw; /* Line 1802, Address: 0x1020998 */
  yOffs &= 240; /* Line 1803, Address: 0x10209a8 */
  xOffs &= 496; /* Line 1804, Address: 0x10209b4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1806, Address: 0x10209c0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1807, Address: 0x10209ec */


} /* Line 1810, Address: 0x1020a18 */















void mapwrt() { /* Line 1826, Address: 0x1020a30 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1833, Address: 0x1020a48 */
  wV_posiw = scra_v_posit.w.h; /* Line 1834, Address: 0x1020a54 */
  pMapWk = (unsigned char*)mapwka; /* Line 1835, Address: 0x1020a60 */
  VramBase = 16384; /* Line 1836, Address: 0x1020a68 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1837, Address: 0x1020a6c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1841, Address: 0x1020a84 */
  VramBase = 24576; /* Line 1842, Address: 0x1020a8c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1843, Address: 0x1020a90 */

} /* Line 1845, Address: 0x1020aa0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1848, Address: 0x1020ac0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1849, Address: 0x1020ad8 */
} /* Line 1850, Address: 0x1020af8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1855, Address: 0x1020b10 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1859, Address: 0x1020b30 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1862, Address: 0x1020b4c */



    wD4 += 16; /* Line 1866, Address: 0x1020b74 */
  } while ((short)--wD6 >= 0); /* Line 1867, Address: 0x1020b80 */

} /* Line 1869, Address: 0x1020ba8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1875, Address: 0x1020bc0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1878, Address: 0x1020bdc */
  wD6 = 15; /* Line 1879, Address: 0x1020be4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1882, Address: 0x1020bec */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1884, Address: 0x1020c10 */
    wD4 += 16; /* Line 1885, Address: 0x1020c30 */
  } while ((short)--wD6 >= 0); /* Line 1886, Address: 0x1020c38 */
} /* Line 1887, Address: 0x1020c5c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1913, Address: 0x1020c80 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1918, Address: 0x1020ca8 */
  wD0 = pWrttbl[wD0]; /* Line 1919, Address: 0x1020cb8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1921, Address: 0x1020cd4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1922, Address: 0x1020cf8 */
  if (wD0) { /* Line 1923, Address: 0x1020d20 */
    wD5 = 65520; /* Line 1924, Address: 0x1020d2c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1925, Address: 0x1020d34 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1928, Address: 0x1020d50 */



  } /* Line 1932, Address: 0x1020d78 */
  else {

    wD5 = 0; /* Line 1935, Address: 0x1020d80 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1936, Address: 0x1020d84 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1940, Address: 0x1020da0 */
  }





} /* Line 1947, Address: 0x1020dc8 */










void mapinit() { /* Line 1958, Address: 0x1020df0 */

  colorset2(mapinittbl.colorno2); /* Line 1960, Address: 0x1020df8 */
  colorset(mapinittbl.colorno2); /* Line 1961, Address: 0x1020e0c */

  if (plflag) enecginit(); /* Line 1963, Address: 0x1020e20 */
  if (play_start & 2) divdevset(); /* Line 1964, Address: 0x1020e38 */
} /* Line 1965, Address: 0x1020e58 */




void mapset() {} /* Line 1970, Address: 0x1020e70 */



void divdevset() {} /* Line 1974, Address: 0x1020e80 */



void enecginit() {} /* Line 1978, Address: 0x1020e90 */
