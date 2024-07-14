#include "..\EQU.H"
#include "SCR81A.H"

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
  0, 2, 2, 2, 0, 0, 0, 0, 0, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
  2, 2, 2
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

















































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 151, Address: 0x102b300 */
    return &actwk[0]; /* Line 152, Address: 0x102b314 */
  else
    return &actwk[1]; /* Line 154, Address: 0x102b324 */

} /* Line 156, Address: 0x102b32c */





































void scr_set() { /* Line 194, Address: 0x102b340 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 197, Address: 0x102b34c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x102b360 */
  scr_timer.b.h = 0; /* Line 199, Address: 0x102b374 */

  pScrTbl = scr_dir_tbl; /* Line 201, Address: 0x102b37c */
  scrar_no = *pScrTbl; /* Line 202, Address: 0x102b384 */
  ++pScrTbl; /* Line 203, Address: 0x102b390 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 204, Address: 0x102b394 */
  ++pScrTbl; /* Line 205, Address: 0x102b3a8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 206, Address: 0x102b3ac */
  ++pScrTbl; /* Line 207, Address: 0x102b3c0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 208, Address: 0x102b3c4 */
  ++pScrTbl; /* Line 209, Address: 0x102b3d8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 210, Address: 0x102b3dc */
  scra_h_keep = *pScrTbl + 576; /* Line 211, Address: 0x102b3f0 */
  ++pScrTbl; /* Line 212, Address: 0x102b410 */
  scra_h_count = 16; /* Line 213, Address: 0x102b414 */
  scra_v_count = 16; /* Line 214, Address: 0x102b420 */

  scra_vline = *pScrTbl; /* Line 216, Address: 0x102b42c */
  scra_hline = 160; /* Line 217, Address: 0x102b438 */

  playposiset(); /* Line 219, Address: 0x102b444 */
} /* Line 220, Address: 0x102b44c */
















































static void playposiset() { /* Line 269, Address: 0x102b460 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 272, Address: 0x102b474 */
    playload(); /* Line 273, Address: 0x102b484 */
    xwk = actwk[0].xposi.w.h; /* Line 274, Address: 0x102b48c */

    if (actwk[0].yposi.w.h > 0) { /* Line 276, Address: 0x102b49c */
      ywk = actwk[0].yposi.w.h; /* Line 277, Address: 0x102b4b4 */
    } else { /* Line 278, Address: 0x102b4c4 */
      ywk = 0; /* Line 279, Address: 0x102b4cc */
    }
  } /* Line 281, Address: 0x102b4d0 */
  else {
    if (demoflag.w & -32768) { /* Line 283, Address: 0x102b4d8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 284, Address: 0x102b4f8 */
    } /* Line 285, Address: 0x102b51c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 287, Address: 0x102b524 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 291, Address: 0x102b544 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 292, Address: 0x102b558 */
  }


  if (xwk > 160) { /* Line 296, Address: 0x102b56c */
    xwk -= 160; /* Line 297, Address: 0x102b580 */
  } else { /* Line 298, Address: 0x102b58c */
    xwk = 0; /* Line 299, Address: 0x102b594 */
  }


  if (xwk > scralim_right) { /* Line 303, Address: 0x102b598 */
    xwk = scralim_right; /* Line 304, Address: 0x102b5bc */
  }


  scra_h_posit.w.h = xwk; /* Line 308, Address: 0x102b5cc */

  if (ywk > 96) { /* Line 310, Address: 0x102b5d4 */
    ywk -= 96; /* Line 311, Address: 0x102b5e8 */
  } else { /* Line 312, Address: 0x102b5f4 */
    ywk = 0; /* Line 313, Address: 0x102b5fc */
  }


  if (ywk > scralim_down) { /* Line 317, Address: 0x102b600 */
    ywk = scralim_down; /* Line 318, Address: 0x102b624 */
  }


  scra_v_posit.w.h = ywk; /* Line 322, Address: 0x102b634 */

  scrbinit(xwk, ywk); /* Line 324, Address: 0x102b63c */


  loopmapno = playmapnotbl[0]; /* Line 327, Address: 0x102b64c */
  loopmapno2 = playmapnotbl[1]; /* Line 328, Address: 0x102b65c */
  ballmapno = playmapnotbl[2]; /* Line 329, Address: 0x102b66c */
  ballmapno2 = playmapnotbl[3]; /* Line 330, Address: 0x102b67c */
} /* Line 331, Address: 0x102b68c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 352, Address: 0x102b6b0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 355, Address: 0x102b6bc */
  lYwk.w.l = 0; /* Line 356, Address: 0x102b6c4 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 358, Address: 0x102b6c8 */
  scrb_v_posit.l = lYwk.l; /* Line 359, Address: 0x102b6d4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 360, Address: 0x102b6e0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 361, Address: 0x102b6ec */

  sXpos = (unsigned short)sXpos >> 1; /* Line 363, Address: 0x102b6f8 */
  scrc_h_posit.w.h = sXpos; /* Line 364, Address: 0x102b714 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 366, Address: 0x102b720 */
  scrz_h_posit.w.h = sXpos; /* Line 367, Address: 0x102b73c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 369, Address: 0x102b748 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 370, Address: 0x102b764 */
} /* Line 371, Address: 0x102b788 */















void scroll() { /* Line 387, Address: 0x102b7a0 */
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

  if (scroll_start.b.h) return; /* Line 399, Address: 0x102b7bc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 404, Address: 0x102b7cc */

  scrchk(); /* Line 406, Address: 0x102b7f8 */

  scroll_h(); /* Line 408, Address: 0x102b800 */
  scroll_v(); /* Line 409, Address: 0x102b808 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 411, Address: 0x102b810 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 412, Address: 0x102b820 */


  lXwk = scra_hz << 6; /* Line 415, Address: 0x102b830 */
  scrollz_h(lXwk, 6); /* Line 416, Address: 0x102b844 */

  lXwk = scra_hz << 7; /* Line 418, Address: 0x102b854 */
  scrollc_h(lXwk, 4); /* Line 419, Address: 0x102b868 */

  lXwk = (scra_hz << 4) * 3; /* Line 421, Address: 0x102b878 */
  scrollb_h(lXwk, 2); /* Line 422, Address: 0x102b894 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 424, Address: 0x102b8a4 */


  scrollb_v(lYwk); /* Line 427, Address: 0x102b8b8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 429, Address: 0x102b8c8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 431, Address: 0x102b8f0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 432, Address: 0x102b928 */

  psHscw = hscrollwork; /* Line 434, Address: 0x102b93c */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 436, Address: 0x102b948 */
  for (i = 0; i < 6; ++i) { /* Line 437, Address: 0x102b968 */

    *psHscw++ = ldwk.w.l; /* Line 439, Address: 0x102b974 */
  } /* Line 440, Address: 0x102b988 */

  z82bline0(&psHscw); /* Line 442, Address: 0x102b998 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 444, Address: 0x102b9a4 */
  for (i = 0; i < 18; ++i) { /* Line 445, Address: 0x102b9c4 */

    *psHscw++ = ldwk.w.l; /* Line 447, Address: 0x102b9d0 */
  } /* Line 448, Address: 0x102b9e4 */

  z82bline1(&psHscw); /* Line 450, Address: 0x102b9f4 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 452, Address: 0x102ba00 */
  for (i = 0; i < 10; ++i) { /* Line 453, Address: 0x102ba20 */

    *psHscw++ = ldwk.w.l; /* Line 455, Address: 0x102ba2c */
  } /* Line 456, Address: 0x102ba40 */

  pHscrbuf = lphscrollbuff; /* Line 458, Address: 0x102ba50 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 459, Address: 0x102ba5c */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 460, Address: 0x102ba8c */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 461, Address: 0x102babc */
} /* Line 462, Address: 0x102bad8 */




static void z82bline0(short** ppHscw) { /* Line 467, Address: 0x102bb00 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl0[7] = {
    0, 0, 0, 0, 1, 1, 1
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 476, Address: 0x102bb18 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 477, Address: 0x102bb3c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 478, Address: 0x102bb5c */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 479, Address: 0x102bb7c */

  for (i = 6; i >= 0; --i) { /* Line 481, Address: 0x102bb88 */

    wk = -ldwk.w.l; /* Line 483, Address: 0x102bb94 */

    for (j = z82bscrtbl0[i]; j >= 0; --j) { /* Line 485, Address: 0x102bbb4 */

      **ppHscw = wk; /* Line 487, Address: 0x102bbd4 */
      ++*ppHscw; /* Line 488, Address: 0x102bbe0 */
    } /* Line 489, Address: 0x102bbf4 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 491, Address: 0x102bc00 */
    ldwk.l += lXwk; /* Line 492, Address: 0x102bc24 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 493, Address: 0x102bc30 */
  } /* Line 494, Address: 0x102bc54 */
} /* Line 495, Address: 0x102bc60 */




static void z82bline1(short** ppHscw) { /* Line 500, Address: 0x102bc80 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl1[7] = {
    0, 0, 0, 0, 1, 9, 1
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 509, Address: 0x102bc98 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 510, Address: 0x102bcbc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 511, Address: 0x102bcdc */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 512, Address: 0x102bcfc */
  *ppHscw += 18; /* Line 513, Address: 0x102bd08 */

  for (i = 6; i >= 0; --i) { /* Line 515, Address: 0x102bd1c */

    wk = -ldwk.w.l; /* Line 517, Address: 0x102bd28 */

    for (j = z82bscrtbl1[i]; j >= 0; --j) { /* Line 519, Address: 0x102bd48 */

      --*ppHscw; /* Line 521, Address: 0x102bd68 */
      **ppHscw = wk; /* Line 522, Address: 0x102bd7c */
    } /* Line 523, Address: 0x102bd88 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 525, Address: 0x102bd94 */
    ldwk.l += lXwk; /* Line 526, Address: 0x102bdb8 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 527, Address: 0x102bdc4 */
  } /* Line 528, Address: 0x102bde8 */
  *ppHscw += 18; /* Line 529, Address: 0x102bdf4 */
} /* Line 530, Address: 0x102be08 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 551, Address: 0x102be30 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 555, Address: 0x102be4c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 556, Address: 0x102be50 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 558, Address: 0x102be70 */
    ldwk.w.l = *pHscrwk; /* Line 559, Address: 0x102be8c */
    ++pHscrwk; /* Line 560, Address: 0x102be98 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 562, Address: 0x102bea4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 563, Address: 0x102beac */
    } /* Line 564, Address: 0x102bebc */
  } /* Line 565, Address: 0x102bee0 */
} /* Line 566, Address: 0x102bf00 */









































































































static void scrollb_v(short yPos) { /* Line 672, Address: 0x102bf20 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 675, Address: 0x102bf30 */
  scrb_v_posit.w.h = yPos; /* Line 676, Address: 0x102bf40 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 677, Address: 0x102bf4c */

  if (!ywk) { /* Line 679, Address: 0x102bf84 */
    scrb_v_count ^= 16; /* Line 680, Address: 0x102bf8c */
    if (yPos - ysv < 0) { /* Line 681, Address: 0x102bfa0 */
      scrflagb.b.h |= 1; /* Line 682, Address: 0x102bfc0 */
    } /* Line 683, Address: 0x102bfd4 */
    else {
      scrflagb.b.h |= 2; /* Line 685, Address: 0x102bfdc */
    }
  }


} /* Line 690, Address: 0x102bff0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 708, Address: 0x102c010 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 712, Address: 0x102c024 */
  lXwk = lXsv + xoffs; /* Line 713, Address: 0x102c02c */
  scrb_h_posit.l = lXwk; /* Line 714, Address: 0x102c034 */
  ldXwk.l = lXwk; /* Line 715, Address: 0x102c03c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 716, Address: 0x102c040 */
  ldXwk.w.l &= 16; /* Line 717, Address: 0x102c064 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 718, Address: 0x102c070 */

  if (!ldXwk.b.b4) { /* Line 720, Address: 0x102c08c */
    scrb_h_count ^= 16; /* Line 721, Address: 0x102c098 */
    if (lXwk - lXsv < 0) { /* Line 722, Address: 0x102c0ac */
      scrflagb.b.h |= 1 << flgbit; /* Line 723, Address: 0x102c0b8 */
    } /* Line 724, Address: 0x102c0dc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 726, Address: 0x102c0e4 */
    }
  }


} /* Line 731, Address: 0x102c10c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 749, Address: 0x102c120 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 753, Address: 0x102c134 */
  lXwk = lXsv + xoffs; /* Line 754, Address: 0x102c13c */
  scrc_h_posit.l = lXwk; /* Line 755, Address: 0x102c144 */
  ldXwk.l = lXwk; /* Line 756, Address: 0x102c14c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 757, Address: 0x102c150 */
  ldXwk.w.l &= 16; /* Line 758, Address: 0x102c174 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 759, Address: 0x102c180 */

  if (!ldXwk.b.b4) { /* Line 761, Address: 0x102c19c */
    scrc_h_count ^= 16; /* Line 762, Address: 0x102c1a8 */
    if (lXwk - lXsv < 0) { /* Line 763, Address: 0x102c1bc */
      scrflagc.b.h |= 1 << flgbit; /* Line 764, Address: 0x102c1c8 */
    } /* Line 765, Address: 0x102c1ec */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 767, Address: 0x102c1f4 */
    }
  }


} /* Line 772, Address: 0x102c21c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 790, Address: 0x102c230 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 794, Address: 0x102c244 */
  lXwk = lXsv + xoffs; /* Line 795, Address: 0x102c24c */
  scrz_h_posit.l = lXwk; /* Line 796, Address: 0x102c254 */
  ldXwk.l = lXwk; /* Line 797, Address: 0x102c25c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 798, Address: 0x102c260 */
  ldXwk.w.l &= 16; /* Line 799, Address: 0x102c284 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 800, Address: 0x102c290 */

  if (!ldXwk.b.b4) { /* Line 802, Address: 0x102c2ac */
    scrz_h_count ^= 16; /* Line 803, Address: 0x102c2b8 */
    if (lXwk - lXsv < 0) { /* Line 804, Address: 0x102c2cc */
      scrflagz.b.h |= 1 << flgbit; /* Line 805, Address: 0x102c2d8 */
    } /* Line 806, Address: 0x102c2fc */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 808, Address: 0x102c304 */
    }
  }


} /* Line 813, Address: 0x102c32c */














static void scroll_h() { /* Line 828, Address: 0x102c340 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 832, Address: 0x102c350 */

  scrh_move(); /* Line 834, Address: 0x102c360 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 835, Address: 0x102c368 */
  if (!bXwk) { /* Line 836, Address: 0x102c39c */
    scra_h_count ^= 16; /* Line 837, Address: 0x102c3a4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 838, Address: 0x102c3b8 */
      scrflaga.b.h |= 4; /* Line 839, Address: 0x102c3dc */
    } else { /* Line 840, Address: 0x102c3f0 */
      scrflaga.b.h |= 8; /* Line 841, Address: 0x102c3f8 */
    }
  }


} /* Line 846, Address: 0x102c40c */
















static void scrh_move() { /* Line 863, Address: 0x102c430 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 866, Address: 0x102c438 */
  if (xwk == 0) { /* Line 867, Address: 0x102c480 */

    scra_hz = 0; /* Line 869, Address: 0x102c490 */
    return; /* Line 870, Address: 0x102c498 */
  } else if (xwk < 0) { /* Line 871, Address: 0x102c4a0 */

    if (xwk < -16) { /* Line 873, Address: 0x102c4b0 */
      xwk = -16; /* Line 874, Address: 0x102c4c4 */
    }


    xwk += scra_h_posit.w.h; /* Line 878, Address: 0x102c4d0 */
    if (xwk < scralim_left) { /* Line 879, Address: 0x102c4e4 */
      xwk = scralim_left; /* Line 880, Address: 0x102c508 */
    }
  } /* Line 882, Address: 0x102c518 */
  else {
    if (xwk > 16) { /* Line 884, Address: 0x102c520 */
      xwk = 16; /* Line 885, Address: 0x102c534 */
    }


    xwk += scra_h_posit.w.h; /* Line 889, Address: 0x102c540 */
    if (xwk > scralim_right) { /* Line 890, Address: 0x102c554 */
      xwk = scralim_right; /* Line 891, Address: 0x102c578 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 896, Address: 0x102c588 */
  scra_h_posit.w.h = xwk; /* Line 897, Address: 0x102c5b8 */
} /* Line 898, Address: 0x102c5c0 */














static void scroll_v() { /* Line 913, Address: 0x102c5d0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 916, Address: 0x102c5dc */
  if (actwk[0].cddat & 4) { /* Line 917, Address: 0x102c610 */
    ywk -= 5; /* Line 918, Address: 0x102c628 */
  }


  if (actwk[0].cddat & 2) { /* Line 922, Address: 0x102c634 */
    ywk += 32; /* Line 923, Address: 0x102c64c */
    if (ywk < scra_vline) { /* Line 924, Address: 0x102c658 */
      ywk -= scra_vline; /* Line 925, Address: 0x102c67c */
      sv_move_main2(ywk); /* Line 926, Address: 0x102c690 */
      return; /* Line 927, Address: 0x102c69c */
    } else if (ywk >= scra_vline + 64) { /* Line 928, Address: 0x102c6a4 */
      ywk -= scra_vline + 64; /* Line 929, Address: 0x102c6cc */
      sv_move_main2(ywk); /* Line 930, Address: 0x102c6f4 */
      return; /* Line 931, Address: 0x102c700 */
    }
    ywk -= scra_vline + 64; /* Line 933, Address: 0x102c708 */
    if (!limmoveflag) goto label1; /* Line 934, Address: 0x102c730 */
    sv_move_sub2(); /* Line 935, Address: 0x102c740 */
    return; /* Line 936, Address: 0x102c748 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 941, Address: 0x102c750 */
    sv_move_main(ywk); /* Line 942, Address: 0x102c77c */
    return; /* Line 943, Address: 0x102c788 */
  } else if (!limmoveflag) goto label1; /* Line 944, Address: 0x102c790 */
  sv_move_sub2(); /* Line 945, Address: 0x102c7a0 */
  return; /* Line 946, Address: 0x102c7a8 */



label1:
  scra_vz = 0; /* Line 951, Address: 0x102c7b0 */
} /* Line 952, Address: 0x102c7b8 */













static void sv_move_main(short yPos) { /* Line 966, Address: 0x102c7d0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 969, Address: 0x102c7e0 */
    if (actwk[0].mspeed.w < 0) { /* Line 970, Address: 0x102c7fc */
      spdwk = -actwk[0].mspeed.w; /* Line 971, Address: 0x102c814 */
    } else { /* Line 972, Address: 0x102c838 */
      spdwk = actwk[0].mspeed.w; /* Line 973, Address: 0x102c840 */
    }


    if (spdwk >= 2048) { /* Line 977, Address: 0x102c850 */
      sv_move_main2(yPos); /* Line 978, Address: 0x102c864 */
    } /* Line 979, Address: 0x102c870 */
    else {

      if (yPos > 6) { /* Line 982, Address: 0x102c878 */
        sv_move_plus(1536); /* Line 983, Address: 0x102c890 */
      } else if (yPos < -6) { /* Line 984, Address: 0x102c89c */
        sv_move_minus(1536); /* Line 985, Address: 0x102c8bc */
      } /* Line 986, Address: 0x102c8c8 */
      else sv_move_sub(yPos); /* Line 987, Address: 0x102c8d0 */
    }
  } /* Line 989, Address: 0x102c8dc */
  else {
    if (yPos > 2) { /* Line 991, Address: 0x102c8e4 */
      sv_move_plus(512); /* Line 992, Address: 0x102c8fc */
    } else if (yPos < -2) { /* Line 993, Address: 0x102c908 */
      sv_move_minus(512); /* Line 994, Address: 0x102c928 */
    } /* Line 995, Address: 0x102c934 */
    else sv_move_sub(yPos); /* Line 996, Address: 0x102c93c */
  }

} /* Line 999, Address: 0x102c948 */













static void sv_move_main2(short yPos) { /* Line 1013, Address: 0x102c960 */
  short spdwk;

  spdwk = 4096; /* Line 1016, Address: 0x102c970 */

  if (yPos > 16) { /* Line 1018, Address: 0x102c97c */
    sv_move_plus(spdwk); /* Line 1019, Address: 0x102c994 */
  } else if (yPos < -16) { /* Line 1020, Address: 0x102c9a0 */
    sv_move_minus(spdwk); /* Line 1021, Address: 0x102c9c0 */
  } else { /* Line 1022, Address: 0x102c9cc */
    sv_move_sub(yPos); /* Line 1023, Address: 0x102c9d4 */
  }
} /* Line 1025, Address: 0x102c9e0 */














static void sv_move_sub(short yPos) { /* Line 1040, Address: 0x102ca00 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1043, Address: 0x102ca0c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1044, Address: 0x102ca10 */
  if (yPos < 0) { /* Line 1045, Address: 0x102ca3c */
    scrv_up_ch(lSpd); /* Line 1046, Address: 0x102ca50 */
  } else { /* Line 1047, Address: 0x102ca5c */
    scrv_down_ch(lSpd); /* Line 1048, Address: 0x102ca64 */
  }
} /* Line 1050, Address: 0x102ca70 */



static void sv_move_sub2() { /* Line 1054, Address: 0x102ca80 */
  limmoveflag = 0; /* Line 1055, Address: 0x102ca88 */

  sv_move_sub(0); /* Line 1057, Address: 0x102ca90 */
} /* Line 1058, Address: 0x102ca9c */













static void sv_move_minus(short speed) { /* Line 1072, Address: 0x102cab0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1075, Address: 0x102cabc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1076, Address: 0x102cae0 */
  scrv_up_ch(lSpd); /* Line 1077, Address: 0x102cb04 */
} /* Line 1078, Address: 0x102cb10 */














static void scrv_up_ch(int_union lSpd) { /* Line 1093, Address: 0x102cb20 */
  if (lSpd.w.l <= scralim_up) { /* Line 1094, Address: 0x102cb2c */
    if (lSpd.w.l > -256) { /* Line 1095, Address: 0x102cb54 */

      lSpd.w.l = scralim_up; /* Line 1097, Address: 0x102cb6c */
    } else { /* Line 1098, Address: 0x102cb78 */
      lSpd.w.l &= 2047; /* Line 1099, Address: 0x102cb80 */
      actwk[0].yposi.w.l &= 2047; /* Line 1100, Address: 0x102cb8c */
      scra_v_posit.w.h &= 2047; /* Line 1101, Address: 0x102cba0 */
      scrb_v_posit.w.h &= 1023; /* Line 1102, Address: 0x102cbb4 */
    }
  }

  scrv_move(lSpd); /* Line 1106, Address: 0x102cbc8 */
} /* Line 1107, Address: 0x102cbd4 */













static void sv_move_plus(short sSpd) { /* Line 1121, Address: 0x102cbf0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1124, Address: 0x102cbfc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1125, Address: 0x102cc1c */
  scrv_down_ch(lSpd); /* Line 1126, Address: 0x102cc40 */
} /* Line 1127, Address: 0x102cc4c */














static void scrv_down_ch(int_union lSpd) { /* Line 1142, Address: 0x102cc60 */
  if (lSpd.w.l >= scralim_down) { /* Line 1143, Address: 0x102cc6c */
    if (lSpd.w.l < 2048) { /* Line 1144, Address: 0x102cc94 */

      lSpd.w.l = scralim_down; /* Line 1146, Address: 0x102ccac */
    } else { /* Line 1147, Address: 0x102ccb8 */
      lSpd.w.l -= 2048; /* Line 1148, Address: 0x102ccc0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1149, Address: 0x102cccc */
      scra_v_posit.w.h -= 2048; /* Line 1150, Address: 0x102cce0 */
      scrb_v_posit.w.h &= 1023; /* Line 1151, Address: 0x102ccf4 */
    }
  }

  scrv_move(lSpd); /* Line 1155, Address: 0x102cd08 */
} /* Line 1156, Address: 0x102cd14 */
















static void scrv_move(int_union lSpd) { /* Line 1173, Address: 0x102cd30 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1177, Address: 0x102cd40 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1178, Address: 0x102cd50 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1179, Address: 0x102cd74 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1180, Address: 0x102cd88 */
  scra_vz = spdwk.w.l; /* Line 1181, Address: 0x102cda0 */

  scra_v_posit.l = lSpd.l; /* Line 1183, Address: 0x102cdac */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1185, Address: 0x102cdb8 */
  if (!ywk) { /* Line 1186, Address: 0x102cdf4 */
    scra_v_count ^= 16; /* Line 1187, Address: 0x102cdfc */
    ywk = scra_v_posit.w.h - ysv; /* Line 1188, Address: 0x102ce10 */
    if (ywk < 0) { /* Line 1189, Address: 0x102ce3c */
      scrflaga.b.h |= 1; /* Line 1190, Address: 0x102ce4c */
    } else { /* Line 1191, Address: 0x102ce60 */
      scrflaga.b.h |= 2; /* Line 1192, Address: 0x102ce68 */
    }
  }


} /* Line 1197, Address: 0x102ce7c */

















void scrollwrt() { /* Line 1215, Address: 0x102ce90 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1224, Address: 0x102ceb0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1225, Address: 0x102ceb4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1226, Address: 0x102cec0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1227, Address: 0x102cecc */
  pScrFlag = &scrflagbw.b.h; /* Line 1228, Address: 0x102ced4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1229, Address: 0x102cedc */

  VramBase = 16384; /* Line 1231, Address: 0x102cef0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1232, Address: 0x102cef4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1233, Address: 0x102cf00 */
  pMapWk = (unsigned char*)mapwka; /* Line 1234, Address: 0x102cf0c */
  pScrFlag = &scrflagaw.b.h; /* Line 1235, Address: 0x102cf14 */

  if (*pScrFlag) { /* Line 1237, Address: 0x102cf1c */
    if (*pScrFlag & 1) { /* Line 1238, Address: 0x102cf28 */
      *pScrFlag &= 254; /* Line 1239, Address: 0x102cf3c */

      lD4.l = -16; /* Line 1241, Address: 0x102cf48 */
      wD5 = 65520; /* Line 1242, Address: 0x102cf50 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x102cf58 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1246, Address: 0x102cf78 */
    }




    if (*pScrFlag & 2) { /* Line 1252, Address: 0x102cfa4 */
      *pScrFlag &= 253; /* Line 1253, Address: 0x102cfb8 */

      lD4.l = 224; /* Line 1255, Address: 0x102cfc4 */
      wD5 = 65520; /* Line 1256, Address: 0x102cfcc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1257, Address: 0x102cfd4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1259, Address: 0x102cff4 */
    }




    if (*pScrFlag & 4) { /* Line 1265, Address: 0x102d020 */
      *pScrFlag &= 251; /* Line 1266, Address: 0x102d034 */

      lD4.l = -16; /* Line 1268, Address: 0x102d040 */
      wD5 = 65520; /* Line 1269, Address: 0x102d048 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1270, Address: 0x102d050 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1272, Address: 0x102d070 */
    }




    if (*pScrFlag & 8) { /* Line 1278, Address: 0x102d09c */
      *pScrFlag &= 247; /* Line 1279, Address: 0x102d0b0 */

      lD4.l = -16; /* Line 1281, Address: 0x102d0bc */
      wD5 = 320; /* Line 1282, Address: 0x102d0c4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1283, Address: 0x102d0cc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1285, Address: 0x102d0ec */
    }
  }






} /* Line 1294, Address: 0x102d118 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1311, Address: 0x102d140 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1322, Address: 0x102d16c */

  if (*pScrFlag & 1) { /* Line 1324, Address: 0x102d174 */
    *pScrFlag &= 254; /* Line 1325, Address: 0x102d18c */
  } /* Line 1326, Address: 0x102d1a0 */
  else {
    *pScrFlag &= 254; /* Line 1328, Address: 0x102d1a8 */

    if (*pScrFlag & 2) { /* Line 1330, Address: 0x102d1bc */
      *pScrFlag &= 253; /* Line 1331, Address: 0x102d1d4 */
      lD4.w.l = 224; /* Line 1332, Address: 0x102d1e8 */
    } /* Line 1333, Address: 0x102d1f0 */
    else {
      *pScrFlag &= 253; /* Line 1335, Address: 0x102d1f8 */
      goto label1; /* Line 1336, Address: 0x102d20c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1341, Address: 0x102d214 */
  wD0 &= 127; /* Line 1342, Address: 0x102d264 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1343, Address: 0x102d26c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1349, Address: 0x102d28c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1350, Address: 0x102d2ac */
  if (wD0 != 0) { /* Line 1351, Address: 0x102d2d0 */
    wD5 = 65520; /* Line 1352, Address: 0x102d2dc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1353, Address: 0x102d2e4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1355, Address: 0x102d304 */



  } /* Line 1359, Address: 0x102d330 */
  else {

    wD5 = 0; /* Line 1362, Address: 0x102d338 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1363, Address: 0x102d33c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1367, Address: 0x102d35c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1374, Address: 0x102d388 */






    lD4.l = -16; /* Line 1381, Address: 0x102d39c */
    wD5 = 65520; /* Line 1382, Address: 0x102d3a4 */
    if (*pScrFlag & 168) { /* Line 1383, Address: 0x102d3ac */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1384, Address: 0x102d3c4 */
      wD5 = 320; /* Line 1385, Address: 0x102d3e4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1389, Address: 0x102d3ec */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1391, Address: 0x102d41c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1392, Address: 0x102d428 */



    for (i = 0; i < 16; ++i) { /* Line 1396, Address: 0x102d438 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1397, Address: 0x102d444 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1398, Address: 0x102d464 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1399, Address: 0x102d49c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1400, Address: 0x102d4bc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1402, Address: 0x102d4e0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1405, Address: 0x102d504 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1407, Address: 0x102d524 */
      }
      lD4.w.l += 16; /* Line 1409, Address: 0x102d538 */
    } /* Line 1410, Address: 0x102d544 */
    *pScrFlag = 0; /* Line 1411, Address: 0x102d554 */
  }
} /* Line 1413, Address: 0x102d55c */





void scrollwrtc() {} /* Line 1419, Address: 0x102d590 */




void scrollwrtz() {} /* Line 1424, Address: 0x102d5a0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1442, Address: 0x102d5b0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1455, Address: 0x102d5d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1458, Address: 0x102d5f8 */
    pTilePoint->x += 2; /* Line 1459, Address: 0x102d60c */
    if (pTilePoint->x >= 64) { /* Line 1460, Address: 0x102d620 */
      pTilePoint->x -= 64; /* Line 1461, Address: 0x102d634 */
    }
    xOffs += 16; /* Line 1463, Address: 0x102d648 */
  } while (--lpcnt >= 0); /* Line 1464, Address: 0x102d654 */
} /* Line 1465, Address: 0x102d668 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1469, Address: 0x102d680 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1473, Address: 0x102d6a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1476, Address: 0x102d6c8 */
    pTilePoint->x += 2; /* Line 1477, Address: 0x102d6dc */
    if (pTilePoint->x >= 64) { /* Line 1478, Address: 0x102d6f0 */
      pTilePoint->x -= 64; /* Line 1479, Address: 0x102d704 */
    }
    xOffs += 16; /* Line 1481, Address: 0x102d718 */
  } while (--lpcnt >= 0); /* Line 1482, Address: 0x102d724 */
} /* Line 1483, Address: 0x102d738 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1503, Address: 0x102d750 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1507, Address: 0x102d778 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1510, Address: 0x102d798 */
    pTilePoint->y += 2; /* Line 1511, Address: 0x102d7ac */
    if (pTilePoint->y >= 32) { /* Line 1512, Address: 0x102d7bc */
      pTilePoint->y -= 32; /* Line 1513, Address: 0x102d7d0 */
    }
    yOffs += 16; /* Line 1515, Address: 0x102d7e0 */
  } while (--lpcnt >= 0); /* Line 1516, Address: 0x102d7ec */
} /* Line 1517, Address: 0x102d800 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1536, Address: 0x102d810 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1542, Address: 0x102d844 */

    base = 1; /* Line 1544, Address: 0x102d854 */
  } /* Line 1545, Address: 0x102d858 */
  else if (VramBase == 16384) { /* Line 1546, Address: 0x102d860 */

    base = 0; /* Line 1548, Address: 0x102d870 */
  }
  x = pTilePoint->x; /* Line 1550, Address: 0x102d874 */
  y = pTilePoint->y; /* Line 1551, Address: 0x102d87c */


  frip = BlkIndex & 6144; /* Line 1554, Address: 0x102d884 */
  BlkIndex &= 1023; /* Line 1555, Address: 0x102d88c */
  if (frip == 6144) { /* Line 1556, Address: 0x102d898 */

    p0 = 3, p1 = 2; /* Line 1558, Address: 0x102d8a4 */
    p2 = 1, p3 = 0; /* Line 1559, Address: 0x102d8ac */
  } /* Line 1560, Address: 0x102d8b4 */
  else if (frip & 4096) { /* Line 1561, Address: 0x102d8bc */

    p0 = 2, p1 = 3; /* Line 1563, Address: 0x102d8c8 */
    p2 = 0, p3 = 1; /* Line 1564, Address: 0x102d8d0 */
  } /* Line 1565, Address: 0x102d8d8 */
  else if (frip & 2048) { /* Line 1566, Address: 0x102d8e0 */

    p0 = 1, p1 = 0; /* Line 1568, Address: 0x102d8ec */
    p2 = 3, p3 = 2; /* Line 1569, Address: 0x102d8f4 */
  } /* Line 1570, Address: 0x102d8fc */
  else {

    p0 = 0, p1 = 1; /* Line 1573, Address: 0x102d904 */
    p2 = 2, p3 = 3; /* Line 1574, Address: 0x102d90c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1577, Address: 0x102d914 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1578, Address: 0x102d958 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1579, Address: 0x102d99c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1580, Address: 0x102d9e0 */

} /* Line 1582, Address: 0x102da24 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1600, Address: 0x102da60 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1601, Address: 0x102da80 */
} /* Line 1602, Address: 0x102daa0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1604, Address: 0x102dab0 */
  wH_posiw = 0; /* Line 1605, Address: 0x102dad0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1606, Address: 0x102dad4 */
} /* Line 1607, Address: 0x102daf4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1614, Address: 0x102db10 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1620, Address: 0x102db40 */
  yOffs += wV_posiw; /* Line 1621, Address: 0x102db50 */





  if ((short)xOffs < 0) /* Line 1627, Address: 0x102db60 */
    xOffs = 0; /* Line 1628, Address: 0x102db7c */
  if ((short)yOffs < 0) /* Line 1629, Address: 0x102db80 */
    yOffs = 0; /* Line 1630, Address: 0x102db9c */
  if ((short)xOffs >= 16384) /* Line 1631, Address: 0x102dba0 */
    xOffs = 16383; /* Line 1632, Address: 0x102dbc0 */
  if ((short)yOffs >= 2048) /* Line 1633, Address: 0x102dbc8 */
    yOffs = 2047; /* Line 1634, Address: 0x102dbe8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1635, Address: 0x102dbf0 */
  if (i < 0) i = 0; /* Line 1636, Address: 0x102dc38 */

  ScreenNo = pMapWk[i] & 127; /* Line 1638, Address: 0x102dc44 */

  if (ScreenNo) { /* Line 1640, Address: 0x102dc60 */




    xOffs &= 32767; /* Line 1645, Address: 0x102dc68 */
    yOffs &= 32767; /* Line 1646, Address: 0x102dc74 */


    xBlk = xOffs; /* Line 1649, Address: 0x102dc80 */
    xBlk %= 256; /* Line 1650, Address: 0x102dc88 */
    xBlk /= 16; /* Line 1651, Address: 0x102dca8 */
    yBlk = yOffs; /* Line 1652, Address: 0x102dcc4 */
    yBlk %= 256; /* Line 1653, Address: 0x102dccc */
    yBlk /= 16; /* Line 1654, Address: 0x102dcec */

    lpw = pmapwk; /* Line 1656, Address: 0x102dd08 */
    lpw += xBlk; /* Line 1657, Address: 0x102dd10 */
    lpw += yBlk * 16; /* Line 1658, Address: 0x102dd18 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1659, Address: 0x102dd24 */
    *pIndex = *lpw; /* Line 1660, Address: 0x102dd3c */

    return 1; /* Line 1662, Address: 0x102dd4c */
  }

  *pIndex = 0; /* Line 1665, Address: 0x102dd58 */
  return 0; /* Line 1666, Address: 0x102dd60 */
} /* Line 1667, Address: 0x102dd64 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1687, Address: 0x102dd90 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1695, Address: 0x102ddb8 */
  if (ScreenNo) { /* Line 1696, Address: 0x102de1c */





    xBlk = xOffs; /* Line 1702, Address: 0x102de24 */
    xBlk %= 256; /* Line 1703, Address: 0x102de2c */
    xBlk /= 16; /* Line 1704, Address: 0x102de4c */
    yBlk = yOffs; /* Line 1705, Address: 0x102de68 */
    yBlk %= 256; /* Line 1706, Address: 0x102de70 */
    yBlk /= 16; /* Line 1707, Address: 0x102de90 */


    lpw = pmapwk; /* Line 1710, Address: 0x102deac */
    lpw += xBlk; /* Line 1711, Address: 0x102deb4 */
    lpw += yBlk * 16; /* Line 1712, Address: 0x102debc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1713, Address: 0x102dec8 */
    *ppBlockNo = lpw; /* Line 1714, Address: 0x102dee0 */
    *pIndex = *lpw; /* Line 1715, Address: 0x102dee8 */




    return 1; /* Line 1720, Address: 0x102def8 */
  }

  *pIndex = 0; /* Line 1723, Address: 0x102df04 */
  return 0; /* Line 1724, Address: 0x102df0c */
} /* Line 1725, Address: 0x102df10 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1739, Address: 0x102df30 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1746, Address: 0x102df4c */
  pMapWk = (unsigned char*)mapwka; /* Line 1747, Address: 0x102df50 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1748, Address: 0x102df58 */
    *pBlockIndex = BlockNo; /* Line 1749, Address: 0x102df7c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1750, Address: 0x102df88 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1751, Address: 0x102dfa0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1752, Address: 0x102dfb4 */
    }
  }


} /* Line 1757, Address: 0x102dfcc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1771, Address: 0x102dff0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1772, Address: 0x102dffc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1773, Address: 0x102e028 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1774, Address: 0x102e074 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1775, Address: 0x102e0a0 */

          return 0; /* Line 1777, Address: 0x102e0ec */
        }
      }
    }
  }

  return 1; /* Line 1783, Address: 0x102e0f8 */
} /* Line 1784, Address: 0x102e0fc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1801, Address: 0x102e110 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1802, Address: 0x102e12c */

} /* Line 1804, Address: 0x102e148 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1806, Address: 0x102e160 */
  wH_posiw = 0; /* Line 1807, Address: 0x102e17c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1808, Address: 0x102e180 */

} /* Line 1810, Address: 0x102e19c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1812, Address: 0x102e1b0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1813, Address: 0x102e1c4 */

} /* Line 1815, Address: 0x102e1e0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1817, Address: 0x102e1f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1818, Address: 0x102e20c */

} /* Line 1820, Address: 0x102e228 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1822, Address: 0x102e240 */
  xOffs += wH_posiw; /* Line 1823, Address: 0x102e258 */
  yOffs += wV_posiw; /* Line 1824, Address: 0x102e268 */
  yOffs &= 240; /* Line 1825, Address: 0x102e278 */
  xOffs &= 496; /* Line 1826, Address: 0x102e284 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1828, Address: 0x102e290 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1829, Address: 0x102e2bc */


} /* Line 1832, Address: 0x102e2e8 */















void mapwrt() { /* Line 1848, Address: 0x102e300 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1855, Address: 0x102e318 */
  wV_posiw = scra_v_posit.w.h; /* Line 1856, Address: 0x102e324 */
  pMapWk = (unsigned char*)mapwka; /* Line 1857, Address: 0x102e330 */
  VramBase = 16384; /* Line 1858, Address: 0x102e338 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1859, Address: 0x102e33c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1863, Address: 0x102e354 */
  VramBase = 24576; /* Line 1864, Address: 0x102e35c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1865, Address: 0x102e360 */

} /* Line 1867, Address: 0x102e370 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1870, Address: 0x102e390 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1871, Address: 0x102e3a8 */
} /* Line 1872, Address: 0x102e3c8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1877, Address: 0x102e3e0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1881, Address: 0x102e400 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1884, Address: 0x102e41c */



    wD4 += 16; /* Line 1888, Address: 0x102e444 */
  } while ((short)--wD6 >= 0); /* Line 1889, Address: 0x102e450 */

} /* Line 1891, Address: 0x102e478 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1897, Address: 0x102e490 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1900, Address: 0x102e4ac */
  wD6 = 15; /* Line 1901, Address: 0x102e4b4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1904, Address: 0x102e4bc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1906, Address: 0x102e4e0 */
    wD4 += 16; /* Line 1907, Address: 0x102e500 */
  } while ((short)--wD6 >= 0); /* Line 1908, Address: 0x102e508 */
} /* Line 1909, Address: 0x102e52c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1935, Address: 0x102e550 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1940, Address: 0x102e578 */
  wD0 = pWrttbl[wD0]; /* Line 1941, Address: 0x102e588 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1943, Address: 0x102e5a4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1944, Address: 0x102e5c8 */
  if (wD0) { /* Line 1945, Address: 0x102e5f0 */
    wD5 = 65520; /* Line 1946, Address: 0x102e5fc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1947, Address: 0x102e604 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1950, Address: 0x102e620 */



  } /* Line 1954, Address: 0x102e648 */
  else {

    wD5 = 0; /* Line 1957, Address: 0x102e650 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1958, Address: 0x102e654 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1962, Address: 0x102e670 */
  }





} /* Line 1969, Address: 0x102e698 */










void mapinit() { /* Line 1980, Address: 0x102e6c0 */

  colorset2(mapinittbl.colorno2); /* Line 1982, Address: 0x102e6c8 */
  colorset(mapinittbl.colorno2); /* Line 1983, Address: 0x102e6dc */

  if (plflag) enecginit(); /* Line 1985, Address: 0x102e6f0 */
  if (play_start & 2) divdevset(); /* Line 1986, Address: 0x102e708 */
} /* Line 1987, Address: 0x102e728 */




void mapset() {} /* Line 1992, Address: 0x102e740 */



void divdevset() {} /* Line 1996, Address: 0x102e750 */



void enecginit() {} /* Line 2000, Address: 0x102e760 */
