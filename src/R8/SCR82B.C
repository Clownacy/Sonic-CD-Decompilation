#include "..\EQU.H"
#include "SCR81A.H"
#include "..\IMPFUNCS.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void z82bline0(short** ppHscw);
static void z82bline1(short** ppHscw);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_v(short yPos);
static void scrollb_h(int xoffs, int flgbit);
static void scrollc_h(int xoffs, int flgbit);
static void scrollz_h(int xoffs, int flgbit);
static void scroll_h(void);
static void scrh_move(void);
static void scroll_v(void);
static void sv_move_main(short yPos);
static void sv_move_main2(short yPos);
static void sv_move_sub(short yPos);
static void sv_move_sub2(void);
static void sv_move_minus(short speed);
static void scrv_up_ch(int_union lSpd);
static void sv_move_plus(short sSpd);
static void scrv_down_ch(int_union lSpd);
static void scrv_move(int_union lSpd);

static unsigned char z81awrttbl[33];
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
extern map_init_data mapinittbl;






















































































sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 151, Address: 0x102ad50 */
    return &actwk[0]; /* Line 152, Address: 0x102ad64 */
  else
    return &actwk[1]; /* Line 154, Address: 0x102ad74 */

} /* Line 156, Address: 0x102ad7c */





































void scr_set(void) { /* Line 194, Address: 0x102ad90 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 197, Address: 0x102ad9c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x102adb0 */
  scr_timer.b.h = 0; /* Line 199, Address: 0x102adc4 */

  pScrTbl = scr_dir_tbl; /* Line 201, Address: 0x102adcc */
  scrar_no = *pScrTbl; /* Line 202, Address: 0x102add4 */
  ++pScrTbl; /* Line 203, Address: 0x102ade0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 204, Address: 0x102ade4 */
  ++pScrTbl; /* Line 205, Address: 0x102adf8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 206, Address: 0x102adfc */
  ++pScrTbl; /* Line 207, Address: 0x102ae10 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 208, Address: 0x102ae14 */
  ++pScrTbl; /* Line 209, Address: 0x102ae28 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 210, Address: 0x102ae2c */
  scra_h_keep = *pScrTbl + 576; /* Line 211, Address: 0x102ae40 */
  ++pScrTbl; /* Line 212, Address: 0x102ae60 */
  scra_h_count = 16; /* Line 213, Address: 0x102ae64 */
  scra_v_count = 16; /* Line 214, Address: 0x102ae70 */

  scra_vline = *pScrTbl; /* Line 216, Address: 0x102ae7c */
  scra_hline = 160; /* Line 217, Address: 0x102ae88 */

  playposiset(); /* Line 219, Address: 0x102ae94 */
} /* Line 220, Address: 0x102ae9c */
















































static void playposiset(void) { /* Line 269, Address: 0x102aeb0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 272, Address: 0x102aec4 */
    playload(); /* Line 273, Address: 0x102aed4 */
    xwk = actwk[0].xposi.w.h; /* Line 274, Address: 0x102aedc */

    if (actwk[0].yposi.w.h > 0) { /* Line 276, Address: 0x102aeec */
      ywk = actwk[0].yposi.w.h; /* Line 277, Address: 0x102af04 */
    } else { /* Line 278, Address: 0x102af14 */
      ywk = 0; /* Line 279, Address: 0x102af1c */
    }
  } /* Line 281, Address: 0x102af20 */
  else {
    if (demoflag.w & -32768) { /* Line 283, Address: 0x102af28 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 284, Address: 0x102af48 */
    } /* Line 285, Address: 0x102af6c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 287, Address: 0x102af74 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 291, Address: 0x102af94 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 292, Address: 0x102afa8 */
  }


  if (xwk > 160) { /* Line 296, Address: 0x102afbc */
    xwk -= 160; /* Line 297, Address: 0x102afd0 */
  } else { /* Line 298, Address: 0x102afdc */
    xwk = 0; /* Line 299, Address: 0x102afe4 */
  }


  if (xwk > scralim_right) { /* Line 303, Address: 0x102afe8 */
    xwk = scralim_right; /* Line 304, Address: 0x102b00c */
  }


  scra_h_posit.w.h = xwk; /* Line 308, Address: 0x102b01c */

  if (ywk > 96) { /* Line 310, Address: 0x102b024 */
    ywk -= 96; /* Line 311, Address: 0x102b038 */
  } else { /* Line 312, Address: 0x102b044 */
    ywk = 0; /* Line 313, Address: 0x102b04c */
  }


  if (ywk > scralim_down) { /* Line 317, Address: 0x102b050 */
    ywk = scralim_down; /* Line 318, Address: 0x102b074 */
  }


  scra_v_posit.w.h = ywk; /* Line 322, Address: 0x102b084 */

  scrbinit(xwk, ywk); /* Line 324, Address: 0x102b08c */


  loopmapno = playmapnotbl[0]; /* Line 327, Address: 0x102b09c */
  loopmapno2 = playmapnotbl[1]; /* Line 328, Address: 0x102b0ac */
  ballmapno = playmapnotbl[2]; /* Line 329, Address: 0x102b0bc */
  ballmapno2 = playmapnotbl[3]; /* Line 330, Address: 0x102b0cc */
} /* Line 331, Address: 0x102b0dc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 352, Address: 0x102b100 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 355, Address: 0x102b10c */
  lYwk.w.l = 0; /* Line 356, Address: 0x102b114 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 358, Address: 0x102b118 */
  scrb_v_posit.l = lYwk.l; /* Line 359, Address: 0x102b124 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 360, Address: 0x102b130 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 361, Address: 0x102b13c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 363, Address: 0x102b148 */
  scrc_h_posit.w.h = sXpos; /* Line 364, Address: 0x102b164 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 366, Address: 0x102b170 */
  scrz_h_posit.w.h = sXpos; /* Line 367, Address: 0x102b18c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 369, Address: 0x102b198 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 370, Address: 0x102b1b4 */
} /* Line 371, Address: 0x102b1d8 */















void scroll(void) { /* Line 387, Address: 0x102b1f0 */
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

  if (scroll_start.b.h) return; /* Line 399, Address: 0x102b20c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 404, Address: 0x102b21c */

  scrchk(); /* Line 406, Address: 0x102b248 */

  scroll_h(); /* Line 408, Address: 0x102b250 */
  scroll_v(); /* Line 409, Address: 0x102b258 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 411, Address: 0x102b260 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 412, Address: 0x102b270 */


  lXwk = scra_hz << 6; /* Line 415, Address: 0x102b280 */
  scrollz_h(lXwk, 6); /* Line 416, Address: 0x102b294 */

  lXwk = scra_hz << 7; /* Line 418, Address: 0x102b2a4 */
  scrollc_h(lXwk, 4); /* Line 419, Address: 0x102b2b8 */

  lXwk = (scra_hz << 4) * 3; /* Line 421, Address: 0x102b2c8 */
  scrollb_h(lXwk, 2); /* Line 422, Address: 0x102b2e4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 424, Address: 0x102b2f4 */


  scrollb_v(lYwk); /* Line 427, Address: 0x102b308 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 429, Address: 0x102b318 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 431, Address: 0x102b340 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 432, Address: 0x102b378 */

  psHscw = hscrollwork; /* Line 434, Address: 0x102b38c */

  z82bline1(&psHscw); /* Line 436, Address: 0x102b398 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 438, Address: 0x102b3a4 */
  for (i = 0; i < 4; ++i) { /* Line 439, Address: 0x102b3c4 */

    *psHscw++ = ldwk.w.l; /* Line 441, Address: 0x102b3d0 */
  } /* Line 442, Address: 0x102b3e4 */

  z82bline0(&psHscw); /* Line 444, Address: 0x102b3f4 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 446, Address: 0x102b400 */
  for (i = 0; i < 10; ++i) { /* Line 447, Address: 0x102b420 */

    *psHscw++ = ldwk.w.l; /* Line 449, Address: 0x102b42c */
  } /* Line 450, Address: 0x102b440 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 452, Address: 0x102b450 */
  for (i = 0; i < 12; ++i) { /* Line 453, Address: 0x102b470 */

    *psHscw++ = ldwk.w.l; /* Line 455, Address: 0x102b47c */
  } /* Line 456, Address: 0x102b490 */

  pHscrbuf = lphscrollbuff; /* Line 458, Address: 0x102b4a0 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 459, Address: 0x102b4ac */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 460, Address: 0x102b4dc */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 461, Address: 0x102b50c */
} /* Line 462, Address: 0x102b528 */




static void z82bline0(short** ppHscw) { /* Line 467, Address: 0x102b550 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl0[8] = {
    1, 1, 0, 0, 0, 0, 0, 0
  };

  lXwk = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 476, Address: 0x102b568 */
  lXwk = (unsigned int)(lXwk << 6) / 8 << 10; /* Line 477, Address: 0x102b58c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 478, Address: 0x102b59c */
  ldwk.w.l = scrb_h_posit.w.h; /* Line 479, Address: 0x102b5bc */

  for (i = 7; i >= 0; --i) { /* Line 481, Address: 0x102b5c8 */

    wk = -ldwk.w.l; /* Line 483, Address: 0x102b5d4 */

    for (j = z82bscrtbl0[i]; j >= 0; --j) { /* Line 485, Address: 0x102b5f4 */

      **ppHscw = wk; /* Line 487, Address: 0x102b614 */
      ++*ppHscw; /* Line 488, Address: 0x102b620 */
    } /* Line 489, Address: 0x102b634 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 491, Address: 0x102b640 */
    ldwk.l += lXwk; /* Line 492, Address: 0x102b664 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 493, Address: 0x102b670 */
  } /* Line 494, Address: 0x102b694 */
} /* Line 495, Address: 0x102b6a0 */




static void z82bline1(short** ppHscw) { /* Line 500, Address: 0x102b6c0 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl1[12] = {
    1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1
  };

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 509, Address: 0x102b6d8 */
  lXwk = (unsigned int)(lXwk << 6) / 12 << 10; /* Line 510, Address: 0x102b6fc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 511, Address: 0x102b71c */
  ldwk.w.l = scrb_h_posit.w.h; /* Line 512, Address: 0x102b73c */
  *ppHscw += 28; /* Line 513, Address: 0x102b748 */

  for (i = 11; i >= 0; --i) { /* Line 515, Address: 0x102b75c */

    wk = -ldwk.w.l; /* Line 517, Address: 0x102b768 */

    for (j = z82bscrtbl1[i]; j >= 0; --j) { /* Line 519, Address: 0x102b788 */

      --*ppHscw; /* Line 521, Address: 0x102b7a8 */
      **ppHscw = wk; /* Line 522, Address: 0x102b7bc */
    } /* Line 523, Address: 0x102b7c8 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 525, Address: 0x102b7d4 */
    ldwk.l += lXwk; /* Line 526, Address: 0x102b7f8 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 527, Address: 0x102b804 */
  } /* Line 528, Address: 0x102b828 */
  *ppHscw += 28; /* Line 529, Address: 0x102b834 */
} /* Line 530, Address: 0x102b848 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 551, Address: 0x102b870 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 555, Address: 0x102b88c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 556, Address: 0x102b890 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 558, Address: 0x102b8b0 */
    ldwk.w.l = *pHscrwk; /* Line 559, Address: 0x102b8cc */
    ++pHscrwk; /* Line 560, Address: 0x102b8d8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 562, Address: 0x102b8e4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 563, Address: 0x102b8ec */
    } /* Line 564, Address: 0x102b8fc */
  } /* Line 565, Address: 0x102b920 */
} /* Line 566, Address: 0x102b940 */









































































































static void scrollb_v(short yPos) { /* Line 672, Address: 0x102b960 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 675, Address: 0x102b970 */
  scrb_v_posit.w.h = yPos; /* Line 676, Address: 0x102b980 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 677, Address: 0x102b98c */

  if (!ywk) { /* Line 679, Address: 0x102b9c4 */
    scrb_v_count ^= 16; /* Line 680, Address: 0x102b9cc */
    if (yPos - ysv < 0) { /* Line 681, Address: 0x102b9e0 */
      scrflagb.b.h |= 1; /* Line 682, Address: 0x102ba00 */
    } /* Line 683, Address: 0x102ba14 */
    else {
      scrflagb.b.h |= 2; /* Line 685, Address: 0x102ba1c */
    }
  }


} /* Line 690, Address: 0x102ba30 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 708, Address: 0x102ba50 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 712, Address: 0x102ba64 */
  lXwk = lXsv + xoffs; /* Line 713, Address: 0x102ba6c */
  scrb_h_posit.l = lXwk; /* Line 714, Address: 0x102ba74 */
  ldXwk.l = lXwk; /* Line 715, Address: 0x102ba7c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 716, Address: 0x102ba80 */
  ldXwk.w.l &= 16; /* Line 717, Address: 0x102baa4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 718, Address: 0x102bab0 */

  if (!ldXwk.b.b4) { /* Line 720, Address: 0x102bacc */
    scrb_h_count ^= 16; /* Line 721, Address: 0x102bad8 */
    if (lXwk - lXsv < 0) { /* Line 722, Address: 0x102baec */
      scrflagb.b.h |= 1 << flgbit; /* Line 723, Address: 0x102baf8 */
    } /* Line 724, Address: 0x102bb1c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 726, Address: 0x102bb24 */
    }
  }


} /* Line 731, Address: 0x102bb4c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 749, Address: 0x102bb60 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 753, Address: 0x102bb74 */
  lXwk = lXsv + xoffs; /* Line 754, Address: 0x102bb7c */
  scrc_h_posit.l = lXwk; /* Line 755, Address: 0x102bb84 */
  ldXwk.l = lXwk; /* Line 756, Address: 0x102bb8c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 757, Address: 0x102bb90 */
  ldXwk.w.l &= 16; /* Line 758, Address: 0x102bbb4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 759, Address: 0x102bbc0 */

  if (!ldXwk.b.b4) { /* Line 761, Address: 0x102bbdc */
    scrc_h_count ^= 16; /* Line 762, Address: 0x102bbe8 */
    if (lXwk - lXsv < 0) { /* Line 763, Address: 0x102bbfc */
      scrflagc.b.h |= 1 << flgbit; /* Line 764, Address: 0x102bc08 */
    } /* Line 765, Address: 0x102bc2c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 767, Address: 0x102bc34 */
    }
  }


} /* Line 772, Address: 0x102bc5c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 790, Address: 0x102bc70 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 794, Address: 0x102bc84 */
  lXwk = lXsv + xoffs; /* Line 795, Address: 0x102bc8c */
  scrz_h_posit.l = lXwk; /* Line 796, Address: 0x102bc94 */
  ldXwk.l = lXwk; /* Line 797, Address: 0x102bc9c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 798, Address: 0x102bca0 */
  ldXwk.w.l &= 16; /* Line 799, Address: 0x102bcc4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 800, Address: 0x102bcd0 */

  if (!ldXwk.b.b4) { /* Line 802, Address: 0x102bcec */
    scrz_h_count ^= 16; /* Line 803, Address: 0x102bcf8 */
    if (lXwk - lXsv < 0) { /* Line 804, Address: 0x102bd0c */
      scrflagz.b.h |= 1 << flgbit; /* Line 805, Address: 0x102bd18 */
    } /* Line 806, Address: 0x102bd3c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 808, Address: 0x102bd44 */
    }
  }


} /* Line 813, Address: 0x102bd6c */














static void scroll_h(void) { /* Line 828, Address: 0x102bd80 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 832, Address: 0x102bd90 */

  scrh_move(); /* Line 834, Address: 0x102bda0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 835, Address: 0x102bda8 */
  if (!bXwk) { /* Line 836, Address: 0x102bddc */
    scra_h_count ^= 16; /* Line 837, Address: 0x102bde4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 838, Address: 0x102bdf8 */
      scrflaga.b.h |= 4; /* Line 839, Address: 0x102be1c */
    } else { /* Line 840, Address: 0x102be30 */
      scrflaga.b.h |= 8; /* Line 841, Address: 0x102be38 */
    }
  }


} /* Line 846, Address: 0x102be4c */
















static void scrh_move(void) { /* Line 863, Address: 0x102be70 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 866, Address: 0x102be78 */
  if (xwk == 0) { /* Line 867, Address: 0x102bec0 */

    scra_hz = 0; /* Line 869, Address: 0x102bed0 */
    return; /* Line 870, Address: 0x102bed8 */
  } else if (xwk < 0) { /* Line 871, Address: 0x102bee0 */

    if (xwk < -16) { /* Line 873, Address: 0x102bef0 */
      xwk = -16; /* Line 874, Address: 0x102bf04 */
    }


    xwk += scra_h_posit.w.h; /* Line 878, Address: 0x102bf10 */
    if (xwk < scralim_left) { /* Line 879, Address: 0x102bf24 */
      xwk = scralim_left; /* Line 880, Address: 0x102bf48 */
    }
  } /* Line 882, Address: 0x102bf58 */
  else {
    if (xwk > 16) { /* Line 884, Address: 0x102bf60 */
      xwk = 16; /* Line 885, Address: 0x102bf74 */
    }


    xwk += scra_h_posit.w.h; /* Line 889, Address: 0x102bf80 */
    if (xwk > scralim_right) { /* Line 890, Address: 0x102bf94 */
      xwk = scralim_right; /* Line 891, Address: 0x102bfb8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 896, Address: 0x102bfc8 */
  scra_h_posit.w.h = xwk; /* Line 897, Address: 0x102bff8 */
} /* Line 898, Address: 0x102c000 */














static void scroll_v(void) { /* Line 913, Address: 0x102c010 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 916, Address: 0x102c01c */
  if (actwk[0].cddat & 4) { /* Line 917, Address: 0x102c050 */
    ywk -= 5; /* Line 918, Address: 0x102c068 */
  }


  if (actwk[0].cddat & 2) { /* Line 922, Address: 0x102c074 */
    ywk += 32; /* Line 923, Address: 0x102c08c */
    if (ywk < scra_vline) { /* Line 924, Address: 0x102c098 */
      ywk -= scra_vline; /* Line 925, Address: 0x102c0bc */
      sv_move_main2(ywk); /* Line 926, Address: 0x102c0d0 */
      return; /* Line 927, Address: 0x102c0dc */
    } else if (ywk >= scra_vline + 64) { /* Line 928, Address: 0x102c0e4 */
      ywk -= scra_vline + 64; /* Line 929, Address: 0x102c10c */
      sv_move_main2(ywk); /* Line 930, Address: 0x102c134 */
      return; /* Line 931, Address: 0x102c140 */
    }
    ywk -= scra_vline + 64; /* Line 933, Address: 0x102c148 */
    if (!limmoveflag) goto label1; /* Line 934, Address: 0x102c170 */
    sv_move_sub2(); /* Line 935, Address: 0x102c180 */
    return; /* Line 936, Address: 0x102c188 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 941, Address: 0x102c190 */
    sv_move_main(ywk); /* Line 942, Address: 0x102c1bc */
    return; /* Line 943, Address: 0x102c1c8 */
  } else if (!limmoveflag) goto label1; /* Line 944, Address: 0x102c1d0 */
  sv_move_sub2(); /* Line 945, Address: 0x102c1e0 */
  return; /* Line 946, Address: 0x102c1e8 */



label1:
  scra_vz = 0; /* Line 951, Address: 0x102c1f0 */
} /* Line 952, Address: 0x102c1f8 */













static void sv_move_main(short yPos) { /* Line 966, Address: 0x102c210 */
  short spdwk;

  if (scra_vline == 96) { /* Line 969, Address: 0x102c220 */
    if (actwk[0].mspeed.w < 0) { /* Line 970, Address: 0x102c23c */
      spdwk = -actwk[0].mspeed.w; /* Line 971, Address: 0x102c254 */
    } else { /* Line 972, Address: 0x102c278 */
      spdwk = actwk[0].mspeed.w; /* Line 973, Address: 0x102c280 */
    }


    if (spdwk >= 2048) { /* Line 977, Address: 0x102c290 */
      sv_move_main2(yPos); /* Line 978, Address: 0x102c2a4 */
    } /* Line 979, Address: 0x102c2b0 */
    else {

      if (yPos > 6) { /* Line 982, Address: 0x102c2b8 */
        sv_move_plus(1536); /* Line 983, Address: 0x102c2d0 */
      } else if (yPos < -6) { /* Line 984, Address: 0x102c2dc */
        sv_move_minus(1536); /* Line 985, Address: 0x102c2fc */
      } /* Line 986, Address: 0x102c308 */
      else sv_move_sub(yPos); /* Line 987, Address: 0x102c310 */
    }
  } /* Line 989, Address: 0x102c31c */
  else {
    if (yPos > 2) { /* Line 991, Address: 0x102c324 */
      sv_move_plus(512); /* Line 992, Address: 0x102c33c */
    } else if (yPos < -2) { /* Line 993, Address: 0x102c348 */
      sv_move_minus(512); /* Line 994, Address: 0x102c368 */
    } /* Line 995, Address: 0x102c374 */
    else sv_move_sub(yPos); /* Line 996, Address: 0x102c37c */
  }

} /* Line 999, Address: 0x102c388 */













static void sv_move_main2(short yPos) { /* Line 1013, Address: 0x102c3a0 */
  short spdwk;

  spdwk = 4096; /* Line 1016, Address: 0x102c3b0 */

  if (yPos > 16) { /* Line 1018, Address: 0x102c3bc */
    sv_move_plus(spdwk); /* Line 1019, Address: 0x102c3d4 */
  } else if (yPos < -16) { /* Line 1020, Address: 0x102c3e0 */
    sv_move_minus(spdwk); /* Line 1021, Address: 0x102c400 */
  } else { /* Line 1022, Address: 0x102c40c */
    sv_move_sub(yPos); /* Line 1023, Address: 0x102c414 */
  }
} /* Line 1025, Address: 0x102c420 */














static void sv_move_sub(short yPos) { /* Line 1040, Address: 0x102c440 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1043, Address: 0x102c44c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1044, Address: 0x102c450 */
  if (yPos < 0) { /* Line 1045, Address: 0x102c47c */
    scrv_up_ch(lSpd); /* Line 1046, Address: 0x102c490 */
  } else { /* Line 1047, Address: 0x102c49c */
    scrv_down_ch(lSpd); /* Line 1048, Address: 0x102c4a4 */
  }
} /* Line 1050, Address: 0x102c4b0 */



static void sv_move_sub2(void) { /* Line 1054, Address: 0x102c4c0 */
  limmoveflag = 0; /* Line 1055, Address: 0x102c4c8 */

  sv_move_sub(0); /* Line 1057, Address: 0x102c4d0 */
} /* Line 1058, Address: 0x102c4dc */













static void sv_move_minus(short speed) { /* Line 1072, Address: 0x102c4f0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1075, Address: 0x102c4fc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1076, Address: 0x102c520 */
  scrv_up_ch(lSpd); /* Line 1077, Address: 0x102c544 */
} /* Line 1078, Address: 0x102c550 */














static void scrv_up_ch(int_union lSpd) { /* Line 1093, Address: 0x102c560 */
  if (lSpd.w.l <= scralim_up) { /* Line 1094, Address: 0x102c56c */
    if (lSpd.w.l > -256) { /* Line 1095, Address: 0x102c594 */

      lSpd.w.l = scralim_up; /* Line 1097, Address: 0x102c5ac */
    } else { /* Line 1098, Address: 0x102c5b8 */
      lSpd.w.l &= 2047; /* Line 1099, Address: 0x102c5c0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1100, Address: 0x102c5cc */
      scra_v_posit.w.h &= 2047; /* Line 1101, Address: 0x102c5e0 */
      scrb_v_posit.w.h &= 1023; /* Line 1102, Address: 0x102c5f4 */
    }
  }

  scrv_move(lSpd); /* Line 1106, Address: 0x102c608 */
} /* Line 1107, Address: 0x102c614 */













static void sv_move_plus(short sSpd) { /* Line 1121, Address: 0x102c630 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1124, Address: 0x102c63c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1125, Address: 0x102c65c */
  scrv_down_ch(lSpd); /* Line 1126, Address: 0x102c680 */
} /* Line 1127, Address: 0x102c68c */














static void scrv_down_ch(int_union lSpd) { /* Line 1142, Address: 0x102c6a0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1143, Address: 0x102c6ac */
    if (lSpd.w.l < 2048) { /* Line 1144, Address: 0x102c6d4 */

      lSpd.w.l = scralim_down; /* Line 1146, Address: 0x102c6ec */
    } else { /* Line 1147, Address: 0x102c6f8 */
      lSpd.w.l -= 2048; /* Line 1148, Address: 0x102c700 */
      actwk[0].yposi.w.h &= 2047; /* Line 1149, Address: 0x102c70c */
      scra_v_posit.w.h -= 2048; /* Line 1150, Address: 0x102c720 */
      scrb_v_posit.w.h &= 1023; /* Line 1151, Address: 0x102c734 */
    }
  }

  scrv_move(lSpd); /* Line 1155, Address: 0x102c748 */
} /* Line 1156, Address: 0x102c754 */
















static void scrv_move(int_union lSpd) { /* Line 1173, Address: 0x102c770 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1177, Address: 0x102c780 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1178, Address: 0x102c790 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1179, Address: 0x102c7b4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1180, Address: 0x102c7c8 */
  scra_vz = spdwk.w.l; /* Line 1181, Address: 0x102c7e0 */

  scra_v_posit.l = lSpd.l; /* Line 1183, Address: 0x102c7ec */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1185, Address: 0x102c7f8 */
  if (!ywk) { /* Line 1186, Address: 0x102c834 */
    scra_v_count ^= 16; /* Line 1187, Address: 0x102c83c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1188, Address: 0x102c850 */
    if (ywk < 0) { /* Line 1189, Address: 0x102c87c */
      scrflaga.b.h |= 1; /* Line 1190, Address: 0x102c88c */
    } else { /* Line 1191, Address: 0x102c8a0 */
      scrflaga.b.h |= 2; /* Line 1192, Address: 0x102c8a8 */
    }
  }


} /* Line 1197, Address: 0x102c8bc */

















void scrollwrt(void) { /* Line 1215, Address: 0x102c8d0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1224, Address: 0x102c8f0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1225, Address: 0x102c8f4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1226, Address: 0x102c900 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1227, Address: 0x102c90c */
  pScrFlag = &scrflagbw.b.h; /* Line 1228, Address: 0x102c914 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1229, Address: 0x102c91c */

  VramBase = 16384; /* Line 1231, Address: 0x102c930 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1232, Address: 0x102c934 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1233, Address: 0x102c940 */
  pMapWk = (unsigned char*)mapwka; /* Line 1234, Address: 0x102c94c */
  pScrFlag = &scrflagaw.b.h; /* Line 1235, Address: 0x102c954 */

  if (*pScrFlag) { /* Line 1237, Address: 0x102c95c */
    if (*pScrFlag & 1) { /* Line 1238, Address: 0x102c968 */
      *pScrFlag &= 254; /* Line 1239, Address: 0x102c97c */

      lD4.l = -16; /* Line 1241, Address: 0x102c988 */
      wD5 = 65520; /* Line 1242, Address: 0x102c990 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x102c998 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1246, Address: 0x102c9b8 */
    }




    if (*pScrFlag & 2) { /* Line 1252, Address: 0x102c9e4 */
      *pScrFlag &= 253; /* Line 1253, Address: 0x102c9f8 */

      lD4.l = 224; /* Line 1255, Address: 0x102ca04 */
      wD5 = 65520; /* Line 1256, Address: 0x102ca0c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1257, Address: 0x102ca14 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1259, Address: 0x102ca34 */
    }




    if (*pScrFlag & 4) { /* Line 1265, Address: 0x102ca60 */
      *pScrFlag &= 251; /* Line 1266, Address: 0x102ca74 */

      lD4.l = -16; /* Line 1268, Address: 0x102ca80 */
      wD5 = 65520; /* Line 1269, Address: 0x102ca88 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1270, Address: 0x102ca90 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1272, Address: 0x102cab0 */
    }




    if (*pScrFlag & 8) { /* Line 1278, Address: 0x102cadc */
      *pScrFlag &= 247; /* Line 1279, Address: 0x102caf0 */

      lD4.l = -16; /* Line 1281, Address: 0x102cafc */
      wD5 = 320; /* Line 1282, Address: 0x102cb04 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1283, Address: 0x102cb0c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1285, Address: 0x102cb2c */
    }
  }






} /* Line 1294, Address: 0x102cb58 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1311, Address: 0x102cb80 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1322, Address: 0x102cbac */

  if (*pScrFlag & 1) { /* Line 1324, Address: 0x102cbb4 */
    *pScrFlag &= 254; /* Line 1325, Address: 0x102cbcc */
  } /* Line 1326, Address: 0x102cbe0 */
  else {
    *pScrFlag &= 254; /* Line 1328, Address: 0x102cbe8 */

    if (*pScrFlag & 2) { /* Line 1330, Address: 0x102cbfc */
      *pScrFlag &= 253; /* Line 1331, Address: 0x102cc14 */
      lD4.w.l = 224; /* Line 1332, Address: 0x102cc28 */
    } /* Line 1333, Address: 0x102cc30 */
    else {
      *pScrFlag &= 253; /* Line 1335, Address: 0x102cc38 */
      goto label1; /* Line 1336, Address: 0x102cc4c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1341, Address: 0x102cc54 */
  wD0 &= 127; /* Line 1342, Address: 0x102cca4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1343, Address: 0x102ccac */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1349, Address: 0x102cccc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1350, Address: 0x102ccec */
  if (wD0 != 0) { /* Line 1351, Address: 0x102cd10 */
    wD5 = 65520; /* Line 1352, Address: 0x102cd1c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1353, Address: 0x102cd24 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1355, Address: 0x102cd44 */



  } /* Line 1359, Address: 0x102cd70 */
  else {

    wD5 = 0; /* Line 1362, Address: 0x102cd78 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1363, Address: 0x102cd7c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1367, Address: 0x102cd9c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1374, Address: 0x102cdc8 */






    lD4.l = -16; /* Line 1381, Address: 0x102cddc */
    wD5 = 65520; /* Line 1382, Address: 0x102cde4 */
    if (*pScrFlag & 168) { /* Line 1383, Address: 0x102cdec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1384, Address: 0x102ce04 */
      wD5 = 320; /* Line 1385, Address: 0x102ce24 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1389, Address: 0x102ce2c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1391, Address: 0x102ce5c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1392, Address: 0x102ce68 */



    for (i = 0; i < 16; ++i) { /* Line 1396, Address: 0x102ce78 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1397, Address: 0x102ce84 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1398, Address: 0x102cea4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1399, Address: 0x102cedc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1400, Address: 0x102cefc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1402, Address: 0x102cf20 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1405, Address: 0x102cf44 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1407, Address: 0x102cf64 */
      }
      lD4.w.l += 16; /* Line 1409, Address: 0x102cf78 */
    } /* Line 1410, Address: 0x102cf84 */
    *pScrFlag = 0; /* Line 1411, Address: 0x102cf94 */
  }
} /* Line 1413, Address: 0x102cf9c */





void scrollwrtc(void) {} /* Line 1419, Address: 0x102cfd0 */




void scrollwrtz(void) {} /* Line 1424, Address: 0x102cfe0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1442, Address: 0x102cff0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1455, Address: 0x102d018 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1458, Address: 0x102d038 */
    pTilePoint->x += 2; /* Line 1459, Address: 0x102d04c */
    if (pTilePoint->x >= 64) { /* Line 1460, Address: 0x102d060 */
      pTilePoint->x -= 64; /* Line 1461, Address: 0x102d074 */
    }
    xOffs += 16; /* Line 1463, Address: 0x102d088 */
  } while (--lpcnt >= 0); /* Line 1464, Address: 0x102d094 */
} /* Line 1465, Address: 0x102d0a8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1469, Address: 0x102d0c0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1473, Address: 0x102d0e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1476, Address: 0x102d108 */
    pTilePoint->x += 2; /* Line 1477, Address: 0x102d11c */
    if (pTilePoint->x >= 64) { /* Line 1478, Address: 0x102d130 */
      pTilePoint->x -= 64; /* Line 1479, Address: 0x102d144 */
    }
    xOffs += 16; /* Line 1481, Address: 0x102d158 */
  } while (--lpcnt >= 0); /* Line 1482, Address: 0x102d164 */
} /* Line 1483, Address: 0x102d178 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1503, Address: 0x102d190 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1507, Address: 0x102d1b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1510, Address: 0x102d1d8 */
    pTilePoint->y += 2; /* Line 1511, Address: 0x102d1ec */
    if (pTilePoint->y >= 32) { /* Line 1512, Address: 0x102d1fc */
      pTilePoint->y -= 32; /* Line 1513, Address: 0x102d210 */
    }
    yOffs += 16; /* Line 1515, Address: 0x102d220 */
  } while (--lpcnt >= 0); /* Line 1516, Address: 0x102d22c */
} /* Line 1517, Address: 0x102d240 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1536, Address: 0x102d250 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1542, Address: 0x102d284 */

    base = 1; /* Line 1544, Address: 0x102d294 */
  } /* Line 1545, Address: 0x102d298 */
  else if (VramBase == 16384) { /* Line 1546, Address: 0x102d2a0 */

    base = 0; /* Line 1548, Address: 0x102d2b0 */
  }
  x = pTilePoint->x; /* Line 1550, Address: 0x102d2b4 */
  y = pTilePoint->y; /* Line 1551, Address: 0x102d2bc */


  frip = BlkIndex & 6144; /* Line 1554, Address: 0x102d2c4 */
  BlkIndex &= 1023; /* Line 1555, Address: 0x102d2cc */
  if (frip == 6144) { /* Line 1556, Address: 0x102d2d8 */

    p0 = 3, p1 = 2; /* Line 1558, Address: 0x102d2e4 */
    p2 = 1, p3 = 0; /* Line 1559, Address: 0x102d2ec */
  } /* Line 1560, Address: 0x102d2f4 */
  else if (frip & 4096) { /* Line 1561, Address: 0x102d2fc */

    p0 = 2, p1 = 3; /* Line 1563, Address: 0x102d308 */
    p2 = 0, p3 = 1; /* Line 1564, Address: 0x102d310 */
  } /* Line 1565, Address: 0x102d318 */
  else if (frip & 2048) { /* Line 1566, Address: 0x102d320 */

    p0 = 1, p1 = 0; /* Line 1568, Address: 0x102d32c */
    p2 = 3, p3 = 2; /* Line 1569, Address: 0x102d334 */
  } /* Line 1570, Address: 0x102d33c */
  else {

    p0 = 0, p1 = 1; /* Line 1573, Address: 0x102d344 */
    p2 = 2, p3 = 3; /* Line 1574, Address: 0x102d34c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1577, Address: 0x102d354 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1578, Address: 0x102d398 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1579, Address: 0x102d3dc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1580, Address: 0x102d420 */

} /* Line 1582, Address: 0x102d464 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1600, Address: 0x102d4a0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1601, Address: 0x102d4c0 */
} /* Line 1602, Address: 0x102d4e0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1604, Address: 0x102d4f0 */
  wH_posiw = 0; /* Line 1605, Address: 0x102d510 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1606, Address: 0x102d514 */
} /* Line 1607, Address: 0x102d534 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1614, Address: 0x102d550 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1620, Address: 0x102d580 */
  yOffs += wV_posiw; /* Line 1621, Address: 0x102d590 */





  if ((short)xOffs < 0) /* Line 1627, Address: 0x102d5a0 */
    xOffs = 0; /* Line 1628, Address: 0x102d5bc */
  if ((short)yOffs < 0) /* Line 1629, Address: 0x102d5c0 */
    yOffs = 0; /* Line 1630, Address: 0x102d5dc */
  if ((short)xOffs >= 16384) /* Line 1631, Address: 0x102d5e0 */
    xOffs = 16383; /* Line 1632, Address: 0x102d600 */
  if ((short)yOffs >= 2048) /* Line 1633, Address: 0x102d608 */
    yOffs = 2047; /* Line 1634, Address: 0x102d628 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1635, Address: 0x102d630 */
  if (i < 0) i = 0; /* Line 1636, Address: 0x102d678 */

  ScreenNo = pMapWk[i] & 127; /* Line 1638, Address: 0x102d684 */

  if (ScreenNo) { /* Line 1640, Address: 0x102d6a0 */




    xOffs &= 32767; /* Line 1645, Address: 0x102d6a8 */
    yOffs &= 32767; /* Line 1646, Address: 0x102d6b4 */


    xBlk = xOffs; /* Line 1649, Address: 0x102d6c0 */
    xBlk %= 256; /* Line 1650, Address: 0x102d6c8 */
    xBlk /= 16; /* Line 1651, Address: 0x102d6e8 */
    yBlk = yOffs; /* Line 1652, Address: 0x102d704 */
    yBlk %= 256; /* Line 1653, Address: 0x102d70c */
    yBlk /= 16; /* Line 1654, Address: 0x102d72c */

    lpw = pmapwk; /* Line 1656, Address: 0x102d748 */
    lpw += xBlk; /* Line 1657, Address: 0x102d750 */
    lpw += yBlk * 16; /* Line 1658, Address: 0x102d758 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1659, Address: 0x102d764 */
    *pIndex = *lpw; /* Line 1660, Address: 0x102d77c */

    return 1; /* Line 1662, Address: 0x102d78c */
  }

  *pIndex = 0; /* Line 1665, Address: 0x102d798 */
  return 0; /* Line 1666, Address: 0x102d7a0 */
} /* Line 1667, Address: 0x102d7a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1687, Address: 0x102d7d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1695, Address: 0x102d7f8 */
  if (ScreenNo) { /* Line 1696, Address: 0x102d85c */





    xBlk = xOffs; /* Line 1702, Address: 0x102d864 */
    xBlk %= 256; /* Line 1703, Address: 0x102d86c */
    xBlk /= 16; /* Line 1704, Address: 0x102d88c */
    yBlk = yOffs; /* Line 1705, Address: 0x102d8a8 */
    yBlk %= 256; /* Line 1706, Address: 0x102d8b0 */
    yBlk /= 16; /* Line 1707, Address: 0x102d8d0 */


    lpw = pmapwk; /* Line 1710, Address: 0x102d8ec */
    lpw += xBlk; /* Line 1711, Address: 0x102d8f4 */
    lpw += yBlk * 16; /* Line 1712, Address: 0x102d8fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1713, Address: 0x102d908 */
    *ppBlockNo = lpw; /* Line 1714, Address: 0x102d920 */
    *pIndex = *lpw; /* Line 1715, Address: 0x102d928 */




    return 1; /* Line 1720, Address: 0x102d938 */
  }

  *pIndex = 0; /* Line 1723, Address: 0x102d944 */
  return 0; /* Line 1724, Address: 0x102d94c */
} /* Line 1725, Address: 0x102d950 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1739, Address: 0x102d970 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1746, Address: 0x102d98c */
  pMapWk = (unsigned char*)mapwka; /* Line 1747, Address: 0x102d990 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1748, Address: 0x102d998 */
    *pBlockIndex = BlockNo; /* Line 1749, Address: 0x102d9bc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1750, Address: 0x102d9c8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1751, Address: 0x102d9e0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1752, Address: 0x102d9f4 */
    }
  }


} /* Line 1757, Address: 0x102da0c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1771, Address: 0x102da30 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1772, Address: 0x102da3c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1773, Address: 0x102da68 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1774, Address: 0x102dab4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1775, Address: 0x102dae0 */

          return 0; /* Line 1777, Address: 0x102db2c */
        }
      }
    }
  }

  return 1; /* Line 1783, Address: 0x102db38 */
} /* Line 1784, Address: 0x102db3c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1801, Address: 0x102db50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1802, Address: 0x102db6c */

} /* Line 1804, Address: 0x102db88 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1806, Address: 0x102dba0 */
  wH_posiw = 0; /* Line 1807, Address: 0x102dbbc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1808, Address: 0x102dbc0 */

} /* Line 1810, Address: 0x102dbdc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1812, Address: 0x102dbf0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1813, Address: 0x102dc04 */

} /* Line 1815, Address: 0x102dc20 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1817, Address: 0x102dc30 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1818, Address: 0x102dc4c */

} /* Line 1820, Address: 0x102dc68 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1822, Address: 0x102dc80 */
  xOffs += wH_posiw; /* Line 1823, Address: 0x102dc98 */
  yOffs += wV_posiw; /* Line 1824, Address: 0x102dca8 */
  yOffs &= 240; /* Line 1825, Address: 0x102dcb8 */
  xOffs &= 496; /* Line 1826, Address: 0x102dcc4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1828, Address: 0x102dcd0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1829, Address: 0x102dcfc */


} /* Line 1832, Address: 0x102dd28 */















void mapwrt(void) { /* Line 1848, Address: 0x102dd40 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1855, Address: 0x102dd58 */
  wV_posiw = scra_v_posit.w.h; /* Line 1856, Address: 0x102dd64 */
  pMapWk = (unsigned char*)mapwka; /* Line 1857, Address: 0x102dd70 */
  VramBase = 16384; /* Line 1858, Address: 0x102dd78 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1859, Address: 0x102dd7c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1863, Address: 0x102dd94 */
  VramBase = 24576; /* Line 1864, Address: 0x102dd9c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1865, Address: 0x102dda0 */

} /* Line 1867, Address: 0x102ddb0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1870, Address: 0x102ddd0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1871, Address: 0x102dde8 */
} /* Line 1872, Address: 0x102de08 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1877, Address: 0x102de20 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1881, Address: 0x102de40 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1884, Address: 0x102de5c */



    wD4 += 16; /* Line 1888, Address: 0x102de84 */
  } while ((short)--wD6 >= 0); /* Line 1889, Address: 0x102de90 */

} /* Line 1891, Address: 0x102deb8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1897, Address: 0x102ded0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1900, Address: 0x102deec */
  wD6 = 15; /* Line 1901, Address: 0x102def4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1904, Address: 0x102defc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1906, Address: 0x102df20 */
    wD4 += 16; /* Line 1907, Address: 0x102df40 */
  } while ((short)--wD6 >= 0); /* Line 1908, Address: 0x102df48 */
} /* Line 1909, Address: 0x102df6c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1935, Address: 0x102df90 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1940, Address: 0x102dfb8 */
  wD0 = pWrttbl[wD0]; /* Line 1941, Address: 0x102dfc8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1943, Address: 0x102dfe4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1944, Address: 0x102e008 */
  if (wD0) { /* Line 1945, Address: 0x102e030 */
    wD5 = 65520; /* Line 1946, Address: 0x102e03c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1947, Address: 0x102e044 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1950, Address: 0x102e060 */



  } /* Line 1954, Address: 0x102e088 */
  else {

    wD5 = 0; /* Line 1957, Address: 0x102e090 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1958, Address: 0x102e094 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1962, Address: 0x102e0b0 */
  }





} /* Line 1969, Address: 0x102e0d8 */










void mapinit(void) { /* Line 1980, Address: 0x102e100 */

  colorset2(mapinittbl.colorno2); /* Line 1982, Address: 0x102e108 */
  colorset(mapinittbl.colorno2); /* Line 1983, Address: 0x102e11c */

  if (plflag) enecginit(); /* Line 1985, Address: 0x102e130 */
  if (play_start & 2) divdevset(); /* Line 1986, Address: 0x102e148 */
} /* Line 1987, Address: 0x102e168 */




void mapset(void) {} /* Line 1992, Address: 0x102e180 */



void divdevset() {} /* Line 1996, Address: 0x102e190 */



void enecginit(void) {} /* Line 2000, Address: 0x102e1a0 */
