#include "..\EQU.H"
#include "SCR82C.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z82bline0(short** ppHscw);
static void z82bline1(short** ppHscw);
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
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 6, 6, 6, 6, 6, 6, 6, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 4, 4, 4,
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
short playpositbl[1][2] = { { 46, 1164 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;








































































































void scr_set() { /* Line 173, Address: 0x102b0f0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 176, Address: 0x102b0fc */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 177, Address: 0x102b110 */
  scr_timer.b.h = 0; /* Line 178, Address: 0x102b124 */

  pScrTbl = scr_dir_tbl; /* Line 180, Address: 0x102b12c */
  scrar_no = *pScrTbl; /* Line 181, Address: 0x102b134 */
  ++pScrTbl; /* Line 182, Address: 0x102b140 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 183, Address: 0x102b144 */
  ++pScrTbl; /* Line 184, Address: 0x102b158 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 185, Address: 0x102b15c */
  ++pScrTbl; /* Line 186, Address: 0x102b170 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 187, Address: 0x102b174 */
  ++pScrTbl; /* Line 188, Address: 0x102b188 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 189, Address: 0x102b18c */
  scra_h_keep = *pScrTbl + 576; /* Line 190, Address: 0x102b1a0 */
  ++pScrTbl; /* Line 191, Address: 0x102b1c0 */
  scra_h_count = 16; /* Line 192, Address: 0x102b1c4 */
  scra_v_count = 16; /* Line 193, Address: 0x102b1d0 */

  scra_vline = *pScrTbl; /* Line 195, Address: 0x102b1dc */
  scra_hline = 160; /* Line 196, Address: 0x102b1e8 */

  playposiset(); /* Line 198, Address: 0x102b1f4 */
} /* Line 199, Address: 0x102b1fc */
















































static void playposiset() { /* Line 248, Address: 0x102b210 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 251, Address: 0x102b224 */
    playload(); /* Line 252, Address: 0x102b234 */
    xwk = actwk[0].xposi.w.h; /* Line 253, Address: 0x102b23c */

    if (actwk[0].yposi.w.h > 0) { /* Line 255, Address: 0x102b24c */
      ywk = actwk[0].yposi.w.h; /* Line 256, Address: 0x102b264 */
    } else { /* Line 257, Address: 0x102b274 */
      ywk = 0; /* Line 258, Address: 0x102b27c */
    }
  } /* Line 260, Address: 0x102b280 */
  else {
    if (demoflag.w & -32768) { /* Line 262, Address: 0x102b288 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 263, Address: 0x102b2a8 */
    } /* Line 264, Address: 0x102b2cc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 266, Address: 0x102b2d4 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 270, Address: 0x102b2f4 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 271, Address: 0x102b308 */
  }


  if (xwk > 160) { /* Line 275, Address: 0x102b31c */
    xwk -= 160; /* Line 276, Address: 0x102b330 */
  } else { /* Line 277, Address: 0x102b33c */
    xwk = 0; /* Line 278, Address: 0x102b344 */
  }


  if (xwk > scralim_right) { /* Line 282, Address: 0x102b348 */
    xwk = scralim_right; /* Line 283, Address: 0x102b36c */
  }


  scra_h_posit.w.h = xwk; /* Line 287, Address: 0x102b37c */

  if (ywk > 96) { /* Line 289, Address: 0x102b384 */
    ywk -= 96; /* Line 290, Address: 0x102b398 */
  } else { /* Line 291, Address: 0x102b3a4 */
    ywk = 0; /* Line 292, Address: 0x102b3ac */
  }


  if (ywk > scralim_down) { /* Line 296, Address: 0x102b3b0 */
    ywk = scralim_down; /* Line 297, Address: 0x102b3d4 */
  }


  scra_v_posit.w.h = ywk; /* Line 301, Address: 0x102b3e4 */

  scrbinit(xwk, ywk); /* Line 303, Address: 0x102b3ec */


  loopmapno = playmapnotbl[0]; /* Line 306, Address: 0x102b3fc */
  loopmapno2 = playmapnotbl[1]; /* Line 307, Address: 0x102b40c */
  ballmapno = playmapnotbl[2]; /* Line 308, Address: 0x102b41c */
  ballmapno2 = playmapnotbl[3]; /* Line 309, Address: 0x102b42c */
} /* Line 310, Address: 0x102b43c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 331, Address: 0x102b460 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 334, Address: 0x102b46c */
  lYwk.w.l = 0; /* Line 335, Address: 0x102b474 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 337, Address: 0x102b478 */
  scrb_v_posit.l = lYwk.l; /* Line 338, Address: 0x102b484 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 339, Address: 0x102b490 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 340, Address: 0x102b49c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 342, Address: 0x102b4a8 */
  scrc_h_posit.w.h = sXpos; /* Line 343, Address: 0x102b4c4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 345, Address: 0x102b4d0 */
  scrz_h_posit.w.h = sXpos; /* Line 346, Address: 0x102b4ec */

  sXpos = (unsigned short)sXpos >> 2; /* Line 348, Address: 0x102b4f8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 349, Address: 0x102b514 */
} /* Line 350, Address: 0x102b538 */















void scroll() { /* Line 366, Address: 0x102b550 */
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

  if (scroll_start.b.h) return; /* Line 378, Address: 0x102b56c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 383, Address: 0x102b57c */

  scrchk(); /* Line 385, Address: 0x102b5a8 */

  scroll_h(); /* Line 387, Address: 0x102b5b0 */
  scroll_v(); /* Line 388, Address: 0x102b5b8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 390, Address: 0x102b5c0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 391, Address: 0x102b5d0 */


  lXwk = scra_hz << 6; /* Line 394, Address: 0x102b5e0 */
  scrollz_h(lXwk, 6); /* Line 395, Address: 0x102b5f4 */

  lXwk = scra_hz << 7; /* Line 397, Address: 0x102b604 */
  scrollc_h(lXwk, 4); /* Line 398, Address: 0x102b618 */

  lXwk = (scra_hz << 4) * 3; /* Line 400, Address: 0x102b628 */
  scrollb_h(lXwk, 2); /* Line 401, Address: 0x102b644 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 403, Address: 0x102b654 */


  scrollb_v(lYwk); /* Line 406, Address: 0x102b668 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 408, Address: 0x102b678 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 410, Address: 0x102b6a0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 411, Address: 0x102b6d8 */

  psHscw = hscrollwork; /* Line 413, Address: 0x102b6ec */

  z82bline1(&psHscw); /* Line 415, Address: 0x102b6f8 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 417, Address: 0x102b704 */
  for (i = 0; i < 14; ++i) { /* Line 418, Address: 0x102b724 */

    *psHscw++ = ldwk.w.l; /* Line 420, Address: 0x102b730 */
  } /* Line 421, Address: 0x102b744 */

  z82bline0(&psHscw); /* Line 423, Address: 0x102b754 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 425, Address: 0x102b760 */
  for (i = 0; i < 12; ++i) { /* Line 426, Address: 0x102b780 */

    *psHscw++ = ldwk.w.l; /* Line 428, Address: 0x102b78c */
  } /* Line 429, Address: 0x102b7a0 */

  pHscrbuf = lphscrollbuff; /* Line 431, Address: 0x102b7b0 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 432, Address: 0x102b7bc */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 433, Address: 0x102b7ec */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 434, Address: 0x102b81c */
} /* Line 435, Address: 0x102b838 */




static void z82bline0(short** ppHscw) { /* Line 440, Address: 0x102b860 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl0[7] = {
    9, 1, 1, 0, 0, 0, 0
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 449, Address: 0x102b878 */
  lXwk = (unsigned int)(lXwk << 5) / 7 << 11; /* Line 450, Address: 0x102b89c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 451, Address: 0x102b8bc */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 452, Address: 0x102b8dc */

  for (i = 6; i >= 0; --i) { /* Line 454, Address: 0x102b8e8 */

    wk = -ldwk.w.l; /* Line 456, Address: 0x102b8f4 */

    for (j = z82bscrtbl0[i]; j >= 0; --j) { /* Line 458, Address: 0x102b914 */

      **ppHscw = wk; /* Line 460, Address: 0x102b934 */
      ++*ppHscw; /* Line 461, Address: 0x102b940 */
    } /* Line 462, Address: 0x102b954 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 464, Address: 0x102b960 */
    ldwk.l += lXwk; /* Line 465, Address: 0x102b984 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 466, Address: 0x102b990 */
  } /* Line 467, Address: 0x102b9b4 */
} /* Line 468, Address: 0x102b9c0 */




static void z82bline1(short** ppHscw) { /* Line 473, Address: 0x102b9e0 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl1[5] = {
    3, 3, 3, 3, 3
  };

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 482, Address: 0x102b9f8 */
  lXwk = (unsigned int)(lXwk << 5) / 5 << 11; /* Line 483, Address: 0x102ba1c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 484, Address: 0x102ba3c */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 485, Address: 0x102ba5c */
  *ppHscw += 20; /* Line 486, Address: 0x102ba68 */

  for (i = 4; i >= 0; --i) { /* Line 488, Address: 0x102ba7c */

    wk = -ldwk.w.l; /* Line 490, Address: 0x102ba88 */

    for (j = z82bscrtbl1[i]; j >= 0; --j) { /* Line 492, Address: 0x102baa8 */

      --*ppHscw; /* Line 494, Address: 0x102bac8 */
      **ppHscw = wk; /* Line 495, Address: 0x102badc */
    } /* Line 496, Address: 0x102bae8 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 498, Address: 0x102baf4 */
    ldwk.l += lXwk; /* Line 499, Address: 0x102bb18 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 500, Address: 0x102bb24 */
  } /* Line 501, Address: 0x102bb48 */
  *ppHscw += 20; /* Line 502, Address: 0x102bb54 */
} /* Line 503, Address: 0x102bb68 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 524, Address: 0x102bb90 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 528, Address: 0x102bbac */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 529, Address: 0x102bbb0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 531, Address: 0x102bbd0 */
    ldwk.w.l = *pHscrwk; /* Line 532, Address: 0x102bbec */
    ++pHscrwk; /* Line 533, Address: 0x102bbf8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 535, Address: 0x102bc04 */
      (*pHscrbuf)->l = ldwk.l; /* Line 536, Address: 0x102bc0c */
    } /* Line 537, Address: 0x102bc1c */
  } /* Line 538, Address: 0x102bc40 */
} /* Line 539, Address: 0x102bc60 */









































































































static void scrollb_v(short yPos) { /* Line 645, Address: 0x102bc80 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 648, Address: 0x102bc90 */
  scrb_v_posit.w.h = yPos; /* Line 649, Address: 0x102bca0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 650, Address: 0x102bcac */

  if (!ywk) { /* Line 652, Address: 0x102bce4 */
    scrb_v_count ^= 16; /* Line 653, Address: 0x102bcec */
    if (yPos - ysv < 0) { /* Line 654, Address: 0x102bd00 */
      scrflagb.b.h |= 1; /* Line 655, Address: 0x102bd20 */
    } /* Line 656, Address: 0x102bd34 */
    else {
      scrflagb.b.h |= 2; /* Line 658, Address: 0x102bd3c */
    }
  }


} /* Line 663, Address: 0x102bd50 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 681, Address: 0x102bd70 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 685, Address: 0x102bd84 */
  lXwk = lXsv + xoffs; /* Line 686, Address: 0x102bd8c */
  scrb_h_posit.l = lXwk; /* Line 687, Address: 0x102bd94 */
  ldXwk.l = lXwk; /* Line 688, Address: 0x102bd9c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 689, Address: 0x102bda0 */
  ldXwk.w.l &= 16; /* Line 690, Address: 0x102bdc4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 691, Address: 0x102bdd0 */

  if (!ldXwk.b.b4) { /* Line 693, Address: 0x102bdec */
    scrb_h_count ^= 16; /* Line 694, Address: 0x102bdf8 */
    if (lXwk - lXsv < 0) { /* Line 695, Address: 0x102be0c */
      scrflagb.b.h |= 1 << flgbit; /* Line 696, Address: 0x102be18 */
    } /* Line 697, Address: 0x102be3c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 699, Address: 0x102be44 */
    }
  }


} /* Line 704, Address: 0x102be6c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 722, Address: 0x102be80 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 726, Address: 0x102be94 */
  lXwk = lXsv + xoffs; /* Line 727, Address: 0x102be9c */
  scrc_h_posit.l = lXwk; /* Line 728, Address: 0x102bea4 */
  ldXwk.l = lXwk; /* Line 729, Address: 0x102beac */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 730, Address: 0x102beb0 */
  ldXwk.w.l &= 16; /* Line 731, Address: 0x102bed4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 732, Address: 0x102bee0 */

  if (!ldXwk.b.b4) { /* Line 734, Address: 0x102befc */
    scrc_h_count ^= 16; /* Line 735, Address: 0x102bf08 */
    if (lXwk - lXsv < 0) { /* Line 736, Address: 0x102bf1c */
      scrflagc.b.h |= 1 << flgbit; /* Line 737, Address: 0x102bf28 */
    } /* Line 738, Address: 0x102bf4c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 740, Address: 0x102bf54 */
    }
  }


} /* Line 745, Address: 0x102bf7c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 763, Address: 0x102bf90 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 767, Address: 0x102bfa4 */
  lXwk = lXsv + xoffs; /* Line 768, Address: 0x102bfac */
  scrz_h_posit.l = lXwk; /* Line 769, Address: 0x102bfb4 */
  ldXwk.l = lXwk; /* Line 770, Address: 0x102bfbc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 771, Address: 0x102bfc0 */
  ldXwk.w.l &= 16; /* Line 772, Address: 0x102bfe4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 773, Address: 0x102bff0 */

  if (!ldXwk.b.b4) { /* Line 775, Address: 0x102c00c */
    scrz_h_count ^= 16; /* Line 776, Address: 0x102c018 */
    if (lXwk - lXsv < 0) { /* Line 777, Address: 0x102c02c */
      scrflagz.b.h |= 1 << flgbit; /* Line 778, Address: 0x102c038 */
    } /* Line 779, Address: 0x102c05c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 781, Address: 0x102c064 */
    }
  }


} /* Line 786, Address: 0x102c08c */














static void scroll_h() { /* Line 801, Address: 0x102c0a0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 805, Address: 0x102c0b0 */

  scrh_move(); /* Line 807, Address: 0x102c0c0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 808, Address: 0x102c0c8 */
  if (!bXwk) { /* Line 809, Address: 0x102c0fc */
    scra_h_count ^= 16; /* Line 810, Address: 0x102c104 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 811, Address: 0x102c118 */
      scrflaga.b.h |= 4; /* Line 812, Address: 0x102c13c */
    } else { /* Line 813, Address: 0x102c150 */
      scrflaga.b.h |= 8; /* Line 814, Address: 0x102c158 */
    }
  }


} /* Line 819, Address: 0x102c16c */
















static void scrh_move() { /* Line 836, Address: 0x102c190 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 839, Address: 0x102c198 */
  if (xwk == 0) { /* Line 840, Address: 0x102c1e0 */

    scra_hz = 0; /* Line 842, Address: 0x102c1f0 */
    return; /* Line 843, Address: 0x102c1f8 */
  } else if (xwk < 0) { /* Line 844, Address: 0x102c200 */

    if (xwk < -16) { /* Line 846, Address: 0x102c210 */
      xwk = -16; /* Line 847, Address: 0x102c224 */
    }


    xwk += scra_h_posit.w.h; /* Line 851, Address: 0x102c230 */
    if (xwk < scralim_left) { /* Line 852, Address: 0x102c244 */
      xwk = scralim_left; /* Line 853, Address: 0x102c268 */
    }
  } /* Line 855, Address: 0x102c278 */
  else {
    if (xwk > 16) { /* Line 857, Address: 0x102c280 */
      xwk = 16; /* Line 858, Address: 0x102c294 */
    }


    xwk += scra_h_posit.w.h; /* Line 862, Address: 0x102c2a0 */
    if (xwk > scralim_right) { /* Line 863, Address: 0x102c2b4 */
      xwk = scralim_right; /* Line 864, Address: 0x102c2d8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 869, Address: 0x102c2e8 */
  scra_h_posit.w.h = xwk; /* Line 870, Address: 0x102c318 */
} /* Line 871, Address: 0x102c320 */














static void scroll_v() { /* Line 886, Address: 0x102c330 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 889, Address: 0x102c33c */
  if (actwk[0].cddat & 4) { /* Line 890, Address: 0x102c370 */
    ywk -= 5; /* Line 891, Address: 0x102c388 */
  }


  if (actwk[0].cddat & 2) { /* Line 895, Address: 0x102c394 */
    ywk += 32; /* Line 896, Address: 0x102c3ac */
    if (ywk < scra_vline) { /* Line 897, Address: 0x102c3b8 */
      ywk -= scra_vline; /* Line 898, Address: 0x102c3dc */
      sv_move_main2(ywk); /* Line 899, Address: 0x102c3f0 */
      return; /* Line 900, Address: 0x102c3fc */
    } else if (ywk >= scra_vline + 64) { /* Line 901, Address: 0x102c404 */
      ywk -= scra_vline + 64; /* Line 902, Address: 0x102c42c */
      sv_move_main2(ywk); /* Line 903, Address: 0x102c454 */
      return; /* Line 904, Address: 0x102c460 */
    }
    ywk -= scra_vline + 64; /* Line 906, Address: 0x102c468 */
    if (!limmoveflag) goto label1; /* Line 907, Address: 0x102c490 */
    sv_move_sub2(); /* Line 908, Address: 0x102c4a0 */
    return; /* Line 909, Address: 0x102c4a8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 914, Address: 0x102c4b0 */
    sv_move_main(ywk); /* Line 915, Address: 0x102c4dc */
    return; /* Line 916, Address: 0x102c4e8 */
  } else if (!limmoveflag) goto label1; /* Line 917, Address: 0x102c4f0 */
  sv_move_sub2(); /* Line 918, Address: 0x102c500 */
  return; /* Line 919, Address: 0x102c508 */



label1:
  scra_vz = 0; /* Line 924, Address: 0x102c510 */
} /* Line 925, Address: 0x102c518 */













static void sv_move_main(short yPos) { /* Line 939, Address: 0x102c530 */
  short spdwk;

  if (scra_vline == 96) { /* Line 942, Address: 0x102c540 */
    if (actwk[0].mspeed.w < 0) { /* Line 943, Address: 0x102c55c */
      spdwk = -actwk[0].mspeed.w; /* Line 944, Address: 0x102c574 */
    } else { /* Line 945, Address: 0x102c598 */
      spdwk = actwk[0].mspeed.w; /* Line 946, Address: 0x102c5a0 */
    }


    if (spdwk >= 2048) { /* Line 950, Address: 0x102c5b0 */
      sv_move_main2(yPos); /* Line 951, Address: 0x102c5c4 */
    } /* Line 952, Address: 0x102c5d0 */
    else {

      if (yPos > 6) { /* Line 955, Address: 0x102c5d8 */
        sv_move_plus(1536); /* Line 956, Address: 0x102c5f0 */
      } else if (yPos < -6) { /* Line 957, Address: 0x102c5fc */
        sv_move_minus(1536); /* Line 958, Address: 0x102c61c */
      } /* Line 959, Address: 0x102c628 */
      else sv_move_sub(yPos); /* Line 960, Address: 0x102c630 */
    }
  } /* Line 962, Address: 0x102c63c */
  else {
    if (yPos > 2) { /* Line 964, Address: 0x102c644 */
      sv_move_plus(512); /* Line 965, Address: 0x102c65c */
    } else if (yPos < -2) { /* Line 966, Address: 0x102c668 */
      sv_move_minus(512); /* Line 967, Address: 0x102c688 */
    } /* Line 968, Address: 0x102c694 */
    else sv_move_sub(yPos); /* Line 969, Address: 0x102c69c */
  }

} /* Line 972, Address: 0x102c6a8 */













static void sv_move_main2(short yPos) { /* Line 986, Address: 0x102c6c0 */
  short spdwk;

  spdwk = 4096; /* Line 989, Address: 0x102c6d0 */

  if (yPos > 16) { /* Line 991, Address: 0x102c6dc */
    sv_move_plus(spdwk); /* Line 992, Address: 0x102c6f4 */
  } else if (yPos < -16) { /* Line 993, Address: 0x102c700 */
    sv_move_minus(spdwk); /* Line 994, Address: 0x102c720 */
  } else { /* Line 995, Address: 0x102c72c */
    sv_move_sub(yPos); /* Line 996, Address: 0x102c734 */
  }
} /* Line 998, Address: 0x102c740 */














static void sv_move_sub(short yPos) { /* Line 1013, Address: 0x102c760 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1016, Address: 0x102c76c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1017, Address: 0x102c770 */
  if (yPos < 0) { /* Line 1018, Address: 0x102c79c */
    scrv_up_ch(lSpd); /* Line 1019, Address: 0x102c7b0 */
  } else { /* Line 1020, Address: 0x102c7bc */
    scrv_down_ch(lSpd); /* Line 1021, Address: 0x102c7c4 */
  }
} /* Line 1023, Address: 0x102c7d0 */



static void sv_move_sub2() { /* Line 1027, Address: 0x102c7e0 */
  limmoveflag = 0; /* Line 1028, Address: 0x102c7e8 */

  sv_move_sub(0); /* Line 1030, Address: 0x102c7f0 */
} /* Line 1031, Address: 0x102c7fc */













static void sv_move_minus(short speed) { /* Line 1045, Address: 0x102c810 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1048, Address: 0x102c81c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1049, Address: 0x102c840 */
  scrv_up_ch(lSpd); /* Line 1050, Address: 0x102c864 */
} /* Line 1051, Address: 0x102c870 */














static void scrv_up_ch(int_union lSpd) { /* Line 1066, Address: 0x102c880 */
  if (lSpd.w.l <= scralim_up) { /* Line 1067, Address: 0x102c88c */
    if (lSpd.w.l > -256) { /* Line 1068, Address: 0x102c8b4 */

      lSpd.w.l = scralim_up; /* Line 1070, Address: 0x102c8cc */
    } else { /* Line 1071, Address: 0x102c8d8 */
      lSpd.w.l &= 2047; /* Line 1072, Address: 0x102c8e0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1073, Address: 0x102c8ec */
      scra_v_posit.w.h &= 2047; /* Line 1074, Address: 0x102c900 */
      scrb_v_posit.w.h &= 1023; /* Line 1075, Address: 0x102c914 */
    }
  }

  scrv_move(lSpd); /* Line 1079, Address: 0x102c928 */
} /* Line 1080, Address: 0x102c934 */













static void sv_move_plus(short sSpd) { /* Line 1094, Address: 0x102c950 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1097, Address: 0x102c95c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1098, Address: 0x102c97c */
  scrv_down_ch(lSpd); /* Line 1099, Address: 0x102c9a0 */
} /* Line 1100, Address: 0x102c9ac */














static void scrv_down_ch(int_union lSpd) { /* Line 1115, Address: 0x102c9c0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1116, Address: 0x102c9cc */
    if (lSpd.w.l < 2048) { /* Line 1117, Address: 0x102c9f4 */

      lSpd.w.l = scralim_down; /* Line 1119, Address: 0x102ca0c */
    } else { /* Line 1120, Address: 0x102ca18 */
      lSpd.w.l -= 2048; /* Line 1121, Address: 0x102ca20 */
      actwk[0].yposi.w.l &= 2047; /* Line 1122, Address: 0x102ca2c */
      scra_v_posit.w.h -= 2048; /* Line 1123, Address: 0x102ca40 */
      scrb_v_posit.w.h &= 1023; /* Line 1124, Address: 0x102ca54 */
    }
  }

  scrv_move(lSpd); /* Line 1128, Address: 0x102ca68 */
} /* Line 1129, Address: 0x102ca74 */
















static void scrv_move(int_union lSpd) { /* Line 1146, Address: 0x102ca90 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1150, Address: 0x102caa0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1151, Address: 0x102cab0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1152, Address: 0x102cad4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1153, Address: 0x102cae8 */
  scra_vz = spdwk.w.l; /* Line 1154, Address: 0x102cb00 */

  scra_v_posit.l = lSpd.l; /* Line 1156, Address: 0x102cb0c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1158, Address: 0x102cb18 */
  if (!ywk) { /* Line 1159, Address: 0x102cb54 */
    scra_v_count ^= 16; /* Line 1160, Address: 0x102cb5c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1161, Address: 0x102cb70 */
    if (ywk < 0) { /* Line 1162, Address: 0x102cb9c */
      scrflaga.b.h |= 1; /* Line 1163, Address: 0x102cbac */
    } else { /* Line 1164, Address: 0x102cbc0 */
      scrflaga.b.h |= 2; /* Line 1165, Address: 0x102cbc8 */
    }
  }


} /* Line 1170, Address: 0x102cbdc */

















void scrollwrt() { /* Line 1188, Address: 0x102cbf0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1197, Address: 0x102cc10 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1198, Address: 0x102cc14 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1199, Address: 0x102cc20 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1200, Address: 0x102cc2c */
  pScrFlag = &scrflagbw.b.h; /* Line 1201, Address: 0x102cc34 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1202, Address: 0x102cc3c */

  VramBase = 16384; /* Line 1204, Address: 0x102cc50 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1205, Address: 0x102cc54 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1206, Address: 0x102cc60 */
  pMapWk = (unsigned char*)mapwka; /* Line 1207, Address: 0x102cc6c */
  pScrFlag = &scrflagaw.b.h; /* Line 1208, Address: 0x102cc74 */

  if (*pScrFlag) { /* Line 1210, Address: 0x102cc7c */
    if (*pScrFlag & 1) { /* Line 1211, Address: 0x102cc88 */
      *pScrFlag &= 254; /* Line 1212, Address: 0x102cc9c */

      lD4.l = -16; /* Line 1214, Address: 0x102cca8 */
      wD5 = 65520; /* Line 1215, Address: 0x102ccb0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1217, Address: 0x102ccb8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1219, Address: 0x102ccd8 */
    }




    if (*pScrFlag & 2) { /* Line 1225, Address: 0x102cd04 */
      *pScrFlag &= 253; /* Line 1226, Address: 0x102cd18 */

      lD4.l = 224; /* Line 1228, Address: 0x102cd24 */
      wD5 = 65520; /* Line 1229, Address: 0x102cd2c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1230, Address: 0x102cd34 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1232, Address: 0x102cd54 */
    }




    if (*pScrFlag & 4) { /* Line 1238, Address: 0x102cd80 */
      *pScrFlag &= 251; /* Line 1239, Address: 0x102cd94 */

      lD4.l = -16; /* Line 1241, Address: 0x102cda0 */
      wD5 = 65520; /* Line 1242, Address: 0x102cda8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1243, Address: 0x102cdb0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1245, Address: 0x102cdd0 */
    }




    if (*pScrFlag & 8) { /* Line 1251, Address: 0x102cdfc */
      *pScrFlag &= 247; /* Line 1252, Address: 0x102ce10 */

      lD4.l = -16; /* Line 1254, Address: 0x102ce1c */
      wD5 = 320; /* Line 1255, Address: 0x102ce24 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1256, Address: 0x102ce2c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1258, Address: 0x102ce4c */
    }
  }






} /* Line 1267, Address: 0x102ce78 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1284, Address: 0x102cea0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1295, Address: 0x102cecc */

  if (*pScrFlag & 1) { /* Line 1297, Address: 0x102ced4 */
    *pScrFlag &= 254; /* Line 1298, Address: 0x102ceec */
  } /* Line 1299, Address: 0x102cf00 */
  else {
    *pScrFlag &= 254; /* Line 1301, Address: 0x102cf08 */

    if (*pScrFlag & 2) { /* Line 1303, Address: 0x102cf1c */
      *pScrFlag &= 253; /* Line 1304, Address: 0x102cf34 */
      lD4.w.l = 224; /* Line 1305, Address: 0x102cf48 */
    } /* Line 1306, Address: 0x102cf50 */
    else {
      *pScrFlag &= 253; /* Line 1308, Address: 0x102cf58 */
      goto label1; /* Line 1309, Address: 0x102cf6c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1314, Address: 0x102cf74 */
  wD0 &= 127; /* Line 1315, Address: 0x102cfc4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1316, Address: 0x102cfcc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1322, Address: 0x102cfec */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1323, Address: 0x102d00c */
  if (wD0 != 0) { /* Line 1324, Address: 0x102d030 */
    wD5 = 65520; /* Line 1325, Address: 0x102d03c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1326, Address: 0x102d044 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1328, Address: 0x102d064 */



  } /* Line 1332, Address: 0x102d090 */
  else {

    wD5 = 0; /* Line 1335, Address: 0x102d098 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1336, Address: 0x102d09c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1340, Address: 0x102d0bc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1347, Address: 0x102d0e8 */






    lD4.l = -16; /* Line 1354, Address: 0x102d0fc */
    wD5 = 65520; /* Line 1355, Address: 0x102d104 */
    if (*pScrFlag & 168) { /* Line 1356, Address: 0x102d10c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1357, Address: 0x102d124 */
      wD5 = 320; /* Line 1358, Address: 0x102d144 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1362, Address: 0x102d14c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1364, Address: 0x102d17c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1365, Address: 0x102d188 */



    for (i = 0; i < 16; ++i) { /* Line 1369, Address: 0x102d198 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1370, Address: 0x102d1a4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1371, Address: 0x102d1c4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1372, Address: 0x102d1fc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1373, Address: 0x102d21c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1375, Address: 0x102d240 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1378, Address: 0x102d264 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1380, Address: 0x102d284 */
      }
      lD4.w.l += 16; /* Line 1382, Address: 0x102d298 */
    } /* Line 1383, Address: 0x102d2a4 */
    *pScrFlag = 0; /* Line 1384, Address: 0x102d2b4 */
  }
} /* Line 1386, Address: 0x102d2bc */





void scrollwrtc() {} /* Line 1392, Address: 0x102d2f0 */




void scrollwrtz() {} /* Line 1397, Address: 0x102d300 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1415, Address: 0x102d310 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1428, Address: 0x102d338 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1431, Address: 0x102d358 */
    pTilePoint->x += 2; /* Line 1432, Address: 0x102d36c */
    if (pTilePoint->x >= 64) { /* Line 1433, Address: 0x102d380 */
      pTilePoint->x -= 64; /* Line 1434, Address: 0x102d394 */
    }
    xOffs += 16; /* Line 1436, Address: 0x102d3a8 */
  } while (--lpcnt >= 0); /* Line 1437, Address: 0x102d3b4 */
} /* Line 1438, Address: 0x102d3c8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1442, Address: 0x102d3e0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1446, Address: 0x102d408 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1449, Address: 0x102d428 */
    pTilePoint->x += 2; /* Line 1450, Address: 0x102d43c */
    if (pTilePoint->x >= 64) { /* Line 1451, Address: 0x102d450 */
      pTilePoint->x -= 64; /* Line 1452, Address: 0x102d464 */
    }
    xOffs += 16; /* Line 1454, Address: 0x102d478 */
  } while (--lpcnt >= 0); /* Line 1455, Address: 0x102d484 */
} /* Line 1456, Address: 0x102d498 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1476, Address: 0x102d4b0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1480, Address: 0x102d4d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1483, Address: 0x102d4f8 */
    pTilePoint->y += 2; /* Line 1484, Address: 0x102d50c */
    if (pTilePoint->y >= 32) { /* Line 1485, Address: 0x102d51c */
      pTilePoint->y -= 32; /* Line 1486, Address: 0x102d530 */
    }
    yOffs += 16; /* Line 1488, Address: 0x102d540 */
  } while (--lpcnt >= 0); /* Line 1489, Address: 0x102d54c */
} /* Line 1490, Address: 0x102d560 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1509, Address: 0x102d570 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1515, Address: 0x102d5a4 */

    base = 1; /* Line 1517, Address: 0x102d5b4 */
  } /* Line 1518, Address: 0x102d5b8 */
  else if (VramBase == 16384) { /* Line 1519, Address: 0x102d5c0 */

    base = 0; /* Line 1521, Address: 0x102d5d0 */
  }
  x = pTilePoint->x; /* Line 1523, Address: 0x102d5d4 */
  y = pTilePoint->y; /* Line 1524, Address: 0x102d5dc */


  frip = BlkIndex & 6144; /* Line 1527, Address: 0x102d5e4 */
  BlkIndex &= 1023; /* Line 1528, Address: 0x102d5ec */
  if (frip == 6144) { /* Line 1529, Address: 0x102d5f8 */

    p0 = 3, p1 = 2; /* Line 1531, Address: 0x102d604 */
    p2 = 1, p3 = 0; /* Line 1532, Address: 0x102d60c */
  } /* Line 1533, Address: 0x102d614 */
  else if (frip & 4096) { /* Line 1534, Address: 0x102d61c */

    p0 = 2, p1 = 3; /* Line 1536, Address: 0x102d628 */
    p2 = 0, p3 = 1; /* Line 1537, Address: 0x102d630 */
  } /* Line 1538, Address: 0x102d638 */
  else if (frip & 2048) { /* Line 1539, Address: 0x102d640 */

    p0 = 1, p1 = 0; /* Line 1541, Address: 0x102d64c */
    p2 = 3, p3 = 2; /* Line 1542, Address: 0x102d654 */
  } /* Line 1543, Address: 0x102d65c */
  else {

    p0 = 0, p1 = 1; /* Line 1546, Address: 0x102d664 */
    p2 = 2, p3 = 3; /* Line 1547, Address: 0x102d66c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1550, Address: 0x102d674 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1551, Address: 0x102d6b8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1552, Address: 0x102d6fc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1553, Address: 0x102d740 */

} /* Line 1555, Address: 0x102d784 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1573, Address: 0x102d7c0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1574, Address: 0x102d7e0 */
} /* Line 1575, Address: 0x102d800 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1577, Address: 0x102d810 */
  wH_posiw = 0; /* Line 1578, Address: 0x102d830 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1579, Address: 0x102d834 */
} /* Line 1580, Address: 0x102d854 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1587, Address: 0x102d870 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1593, Address: 0x102d8a0 */
  yOffs += wV_posiw; /* Line 1594, Address: 0x102d8b0 */





  if ((short)xOffs < 0) /* Line 1600, Address: 0x102d8c0 */
    xOffs = 0; /* Line 1601, Address: 0x102d8dc */
  if ((short)yOffs < 0) /* Line 1602, Address: 0x102d8e0 */
    yOffs = 0; /* Line 1603, Address: 0x102d8fc */
  if ((short)xOffs >= 16384) /* Line 1604, Address: 0x102d900 */
    xOffs = 16383; /* Line 1605, Address: 0x102d920 */
  if ((short)yOffs >= 2048) /* Line 1606, Address: 0x102d928 */
    yOffs = 2047; /* Line 1607, Address: 0x102d948 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1608, Address: 0x102d950 */
  if (i < 0) i = 0; /* Line 1609, Address: 0x102d998 */

  ScreenNo = pMapWk[i] & 127; /* Line 1611, Address: 0x102d9a4 */

  if (ScreenNo) { /* Line 1613, Address: 0x102d9c0 */




    xOffs &= 32767; /* Line 1618, Address: 0x102d9c8 */
    yOffs &= 32767; /* Line 1619, Address: 0x102d9d4 */


    xBlk = xOffs; /* Line 1622, Address: 0x102d9e0 */
    xBlk %= 256; /* Line 1623, Address: 0x102d9e8 */
    xBlk /= 16; /* Line 1624, Address: 0x102da08 */
    yBlk = yOffs; /* Line 1625, Address: 0x102da24 */
    yBlk %= 256; /* Line 1626, Address: 0x102da2c */
    yBlk /= 16; /* Line 1627, Address: 0x102da4c */

    lpw = pmapwk; /* Line 1629, Address: 0x102da68 */
    lpw += xBlk; /* Line 1630, Address: 0x102da70 */
    lpw += yBlk * 16; /* Line 1631, Address: 0x102da78 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1632, Address: 0x102da84 */
    *pIndex = *lpw; /* Line 1633, Address: 0x102da9c */

    return 1; /* Line 1635, Address: 0x102daac */
  }

  *pIndex = 0; /* Line 1638, Address: 0x102dab8 */
  return 0; /* Line 1639, Address: 0x102dac0 */
} /* Line 1640, Address: 0x102dac4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1660, Address: 0x102daf0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1668, Address: 0x102db18 */
  if (ScreenNo) { /* Line 1669, Address: 0x102db7c */





    xBlk = xOffs; /* Line 1675, Address: 0x102db84 */
    xBlk %= 256; /* Line 1676, Address: 0x102db8c */
    xBlk /= 16; /* Line 1677, Address: 0x102dbac */
    yBlk = yOffs; /* Line 1678, Address: 0x102dbc8 */
    yBlk %= 256; /* Line 1679, Address: 0x102dbd0 */
    yBlk /= 16; /* Line 1680, Address: 0x102dbf0 */


    lpw = pmapwk; /* Line 1683, Address: 0x102dc0c */
    lpw += xBlk; /* Line 1684, Address: 0x102dc14 */
    lpw += yBlk * 16; /* Line 1685, Address: 0x102dc1c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1686, Address: 0x102dc28 */
    *ppBlockNo = lpw; /* Line 1687, Address: 0x102dc40 */
    *pIndex = *lpw; /* Line 1688, Address: 0x102dc48 */




    return 1; /* Line 1693, Address: 0x102dc58 */
  }

  *pIndex = 0; /* Line 1696, Address: 0x102dc64 */
  return 0; /* Line 1697, Address: 0x102dc6c */
} /* Line 1698, Address: 0x102dc70 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1712, Address: 0x102dc90 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1719, Address: 0x102dcac */
  pMapWk = (unsigned char*)mapwka; /* Line 1720, Address: 0x102dcb0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1721, Address: 0x102dcb8 */
    *pBlockIndex = BlockNo; /* Line 1722, Address: 0x102dcdc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1723, Address: 0x102dce8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1724, Address: 0x102dd00 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1725, Address: 0x102dd14 */
    }
  }


} /* Line 1730, Address: 0x102dd2c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1744, Address: 0x102dd50 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1745, Address: 0x102dd5c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1746, Address: 0x102dd88 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1747, Address: 0x102ddd4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1748, Address: 0x102de00 */

          return 0; /* Line 1750, Address: 0x102de4c */
        }
      }
    }
  }

  return 1; /* Line 1756, Address: 0x102de58 */
} /* Line 1757, Address: 0x102de5c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1774, Address: 0x102de70 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x102de8c */

} /* Line 1777, Address: 0x102dea8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102dec0 */
  wH_posiw = 0; /* Line 1780, Address: 0x102dedc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1781, Address: 0x102dee0 */

} /* Line 1783, Address: 0x102defc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1785, Address: 0x102df10 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1786, Address: 0x102df24 */

} /* Line 1788, Address: 0x102df40 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1790, Address: 0x102df50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1791, Address: 0x102df6c */

} /* Line 1793, Address: 0x102df88 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1795, Address: 0x102dfa0 */
  xOffs += wH_posiw; /* Line 1796, Address: 0x102dfb8 */
  yOffs += wV_posiw; /* Line 1797, Address: 0x102dfc8 */
  yOffs &= 240; /* Line 1798, Address: 0x102dfd8 */
  xOffs &= 496; /* Line 1799, Address: 0x102dfe4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1801, Address: 0x102dff0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1802, Address: 0x102e01c */


} /* Line 1805, Address: 0x102e048 */















void mapwrt() { /* Line 1821, Address: 0x102e060 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1828, Address: 0x102e078 */
  wV_posiw = scra_v_posit.w.h; /* Line 1829, Address: 0x102e084 */
  pMapWk = (unsigned char*)mapwka; /* Line 1830, Address: 0x102e090 */
  VramBase = 16384; /* Line 1831, Address: 0x102e098 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1832, Address: 0x102e09c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1836, Address: 0x102e0b4 */
  VramBase = 24576; /* Line 1837, Address: 0x102e0bc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1838, Address: 0x102e0c0 */

} /* Line 1840, Address: 0x102e0d0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1843, Address: 0x102e0f0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1844, Address: 0x102e108 */
} /* Line 1845, Address: 0x102e128 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1850, Address: 0x102e140 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1854, Address: 0x102e160 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1857, Address: 0x102e17c */



    wD4 += 16; /* Line 1861, Address: 0x102e1a4 */
  } while ((short)--wD6 >= 0); /* Line 1862, Address: 0x102e1b0 */

} /* Line 1864, Address: 0x102e1d8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1870, Address: 0x102e1f0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1873, Address: 0x102e20c */
  wD6 = 15; /* Line 1874, Address: 0x102e214 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1877, Address: 0x102e21c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1879, Address: 0x102e240 */
    wD4 += 16; /* Line 1880, Address: 0x102e260 */
  } while ((short)--wD6 >= 0); /* Line 1881, Address: 0x102e268 */
} /* Line 1882, Address: 0x102e28c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1908, Address: 0x102e2b0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1913, Address: 0x102e2d8 */
  wD0 = pWrttbl[wD0]; /* Line 1914, Address: 0x102e2e8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1916, Address: 0x102e304 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1917, Address: 0x102e328 */
  if (wD0) { /* Line 1918, Address: 0x102e350 */
    wD5 = 65520; /* Line 1919, Address: 0x102e35c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1920, Address: 0x102e364 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1923, Address: 0x102e380 */



  } /* Line 1927, Address: 0x102e3a8 */
  else {

    wD5 = 0; /* Line 1930, Address: 0x102e3b0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1931, Address: 0x102e3b4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1935, Address: 0x102e3d0 */
  }





} /* Line 1942, Address: 0x102e3f8 */










void mapinit() { /* Line 1953, Address: 0x102e420 */

  colorset2(mapinittbl.colorno2); /* Line 1955, Address: 0x102e428 */
  colorset(mapinittbl.colorno2); /* Line 1956, Address: 0x102e43c */

  if (plflag) enecginit(); /* Line 1958, Address: 0x102e450 */
  if (play_start & 2) divdevset(); /* Line 1959, Address: 0x102e468 */
} /* Line 1960, Address: 0x102e488 */




void mapset() {} /* Line 1965, Address: 0x102e4a0 */



void divdevset() {} /* Line 1969, Address: 0x102e4b0 */



void enecginit() {} /* Line 1973, Address: 0x102e4c0 */
