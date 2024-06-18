#include "..\EQU.H"
#include "SCR61A.H"

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
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 2, 2, 2, 2, 2,
  2, 2, 6, 4, 4, 6, 6, 6, 6, 6,
  6, 4, 4, 6, 6, 6, 6, 6, 6, 4,
  4, 0, 0, 0, 0, 0, 0, 0, 0
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
short playpositbl[1][2] = { { 48, 412 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;












































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x102b400 */
    return &actwk[0]; /* Line 147, Address: 0x102b414 */
  else
    return &actwk[1]; /* Line 149, Address: 0x102b424 */

} /* Line 151, Address: 0x102b42c */





































void scr_set() { /* Line 189, Address: 0x102b440 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x102b44c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x102b460 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x102b474 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x102b47c */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x102b484 */
  ++pScrTbl; /* Line 198, Address: 0x102b490 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x102b494 */
  ++pScrTbl; /* Line 200, Address: 0x102b4a8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x102b4ac */
  ++pScrTbl; /* Line 202, Address: 0x102b4c0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x102b4c4 */
  ++pScrTbl; /* Line 204, Address: 0x102b4d8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x102b4dc */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x102b4f0 */
  ++pScrTbl; /* Line 207, Address: 0x102b510 */
  scra_h_count = 16; /* Line 208, Address: 0x102b514 */
  scra_v_count = 16; /* Line 209, Address: 0x102b520 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102b52c */
  scra_hline = 160; /* Line 212, Address: 0x102b538 */

  playposiset(); /* Line 214, Address: 0x102b544 */
} /* Line 215, Address: 0x102b54c */
















































static void playposiset() { /* Line 264, Address: 0x102b560 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x102b574 */
    playload(); /* Line 268, Address: 0x102b584 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x102b58c */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x102b59c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x102b5b4 */
    } else { /* Line 273, Address: 0x102b5c4 */
      ywk = 0; /* Line 274, Address: 0x102b5cc */
    }
  } /* Line 276, Address: 0x102b5d0 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x102b5d8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x102b5f8 */
    } /* Line 280, Address: 0x102b61c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x102b624 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x102b644 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x102b658 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x102b66c */
    xwk -= 160; /* Line 292, Address: 0x102b680 */
  } else { /* Line 293, Address: 0x102b68c */
    xwk = 0; /* Line 294, Address: 0x102b694 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x102b698 */
    xwk = scralim_right; /* Line 299, Address: 0x102b6bc */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x102b6cc */

  if (ywk > 96) { /* Line 305, Address: 0x102b6d4 */
    ywk -= 96; /* Line 306, Address: 0x102b6e8 */
  } else { /* Line 307, Address: 0x102b6f4 */
    ywk = 0; /* Line 308, Address: 0x102b6fc */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x102b700 */
    ywk = scralim_down; /* Line 313, Address: 0x102b724 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x102b734 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102b73c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102b74c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102b75c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102b76c */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102b77c */
} /* Line 326, Address: 0x102b78c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x102b7b0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102b7bc */
  lYwk.w.l = 0; /* Line 351, Address: 0x102b7c4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x102b7c8 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x102b7d4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x102b7e0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102b7ec */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x102b7f8 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x102b814 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x102b820 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102b83c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x102b848 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x102b864 */
} /* Line 366, Address: 0x102b888 */















void scroll() { /* Line 382, Address: 0x102b8a0 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x102b8bc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x102b8cc */

  scrchk(); /* Line 401, Address: 0x102b8f8 */

  scroll_h(); /* Line 403, Address: 0x102b900 */
  scroll_v(); /* Line 404, Address: 0x102b908 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x102b910 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x102b920 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x102b930 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x102b944 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x102b954 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x102b968 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x102b978 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x102b994 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x102b9a4 */


  scrollb_v(lYwk); /* Line 422, Address: 0x102b9b8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x102b9c8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x102b9f0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x102ba28 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102ba3c */

  z81aline(&psHscw); /* Line 431, Address: 0x102ba48 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 433, Address: 0x102ba54 */
  for (i = 0; i < 14; ++i) { /* Line 434, Address: 0x102ba74 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x102ba80 */
  } /* Line 437, Address: 0x102ba94 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 439, Address: 0x102baa4 */
  for (i = 0; i < 2; ++i) { /* Line 440, Address: 0x102bac4 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x102bad0 */
  } /* Line 443, Address: 0x102bae4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 445, Address: 0x102baf4 */
  for (i = 0; i < 4; ++i) { /* Line 446, Address: 0x102bb14 */

    *psHscw++ = ldwk.w.l; /* Line 448, Address: 0x102bb20 */
  } /* Line 449, Address: 0x102bb34 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 451, Address: 0x102bb44 */
  for (i = 0; i < 12; ++i) { /* Line 452, Address: 0x102bb64 */

    *psHscw++ = ldwk.w.l; /* Line 454, Address: 0x102bb70 */
  } /* Line 455, Address: 0x102bb84 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 457, Address: 0x102bb94 */
  for (i = 0; i < 4; ++i) { /* Line 458, Address: 0x102bbb4 */

    *psHscw++ = ldwk.w.l; /* Line 460, Address: 0x102bbc0 */
  } /* Line 461, Address: 0x102bbd4 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 463, Address: 0x102bbe4 */
  for (i = 0; i < 12; ++i) { /* Line 464, Address: 0x102bc04 */

    *psHscw++ = ldwk.w.l; /* Line 466, Address: 0x102bc10 */
  } /* Line 467, Address: 0x102bc24 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 469, Address: 0x102bc34 */
  for (i = 0; i < 4; ++i) { /* Line 470, Address: 0x102bc54 */

    *psHscw++ = ldwk.w.l; /* Line 472, Address: 0x102bc60 */
  } /* Line 473, Address: 0x102bc74 */

  pHscrbuf = lphscrollbuff; /* Line 475, Address: 0x102bc84 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 476, Address: 0x102bc90 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 477, Address: 0x102bcc0 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 478, Address: 0x102bcf0 */
} /* Line 479, Address: 0x102bd0c */













static void z81aline(short** ppHscw) { /* Line 493, Address: 0x102bd30 */
  char z81ascrtbl[17] = { /* Line 494, Address: 0x102bd44 */
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0
  };
  int i;
  int j;
  int_union radwk;
  int lXwk;



  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 504, Address: 0x102bd70 */
  radwk.w.l = scrb_h_posit.w.h; /* Line 505, Address: 0x102bd94 */
  lXwk <<= 7; /* Line 506, Address: 0x102bda0 */
  lXwk /= 17; /* Line 507, Address: 0x102bda4 */
  lXwk <<= 9; /* Line 508, Address: 0x102bdbc */


  *ppHscw += 28; /* Line 511, Address: 0x102bdc0 */

  for (i = 16; i >= 0; --i) { /* Line 513, Address: 0x102bdd4 */

    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 515, Address: 0x102bde0 */
      --*ppHscw; /* Line 516, Address: 0x102bdf8 */
      **ppHscw = -radwk.w.l; /* Line 517, Address: 0x102be0c */
    } /* Line 518, Address: 0x102be30 */

    radwk.l = (unsigned int)radwk.l >> 16 & 65535 | radwk.l << 16 & -65536; /* Line 520, Address: 0x102be3c */
    radwk.l += lXwk; /* Line 521, Address: 0x102be60 */
    radwk.l = (unsigned int)radwk.l >> 16 & 65535 | radwk.l << 16 & -65536; /* Line 522, Address: 0x102be6c */
  } /* Line 523, Address: 0x102be90 */

  *ppHscw += 28; /* Line 525, Address: 0x102be9c */
} /* Line 526, Address: 0x102beb0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 547, Address: 0x102bed0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 551, Address: 0x102beec */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 552, Address: 0x102bef0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 554, Address: 0x102bf10 */
    ldwk.w.l = *pHscrwk; /* Line 555, Address: 0x102bf2c */
    ++pHscrwk; /* Line 556, Address: 0x102bf38 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 558, Address: 0x102bf44 */
      (*pHscrbuf)->l = ldwk.l; /* Line 559, Address: 0x102bf4c */
    } /* Line 560, Address: 0x102bf5c */
  } /* Line 561, Address: 0x102bf80 */
} /* Line 562, Address: 0x102bfa0 */









































































































static void scrollb_v(short yPos) { /* Line 668, Address: 0x102bfc0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 671, Address: 0x102bfd0 */
  scrb_v_posit.w.h = yPos; /* Line 672, Address: 0x102bfe0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 673, Address: 0x102bfec */

  if (!ywk) { /* Line 675, Address: 0x102c024 */
    scrb_v_count ^= 16; /* Line 676, Address: 0x102c02c */
    if (yPos - ysv < 0) { /* Line 677, Address: 0x102c040 */
      scrflagb.b.h |= 1; /* Line 678, Address: 0x102c060 */
    } /* Line 679, Address: 0x102c074 */
    else {
      scrflagb.b.h |= 2; /* Line 681, Address: 0x102c07c */
    }
  }


} /* Line 686, Address: 0x102c090 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 704, Address: 0x102c0b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 708, Address: 0x102c0c4 */
  lXwk = lXsv + xoffs; /* Line 709, Address: 0x102c0cc */
  scrb_h_posit.l = lXwk; /* Line 710, Address: 0x102c0d4 */
  ldXwk.l = lXwk; /* Line 711, Address: 0x102c0dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 712, Address: 0x102c0e0 */
  ldXwk.w.l &= 16; /* Line 713, Address: 0x102c104 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 714, Address: 0x102c110 */

  if (!ldXwk.b.b4) { /* Line 716, Address: 0x102c12c */
    scrb_h_count ^= 16; /* Line 717, Address: 0x102c138 */
    if (lXwk - lXsv < 0) { /* Line 718, Address: 0x102c14c */
      scrflagb.b.h |= 1 << flgbit; /* Line 719, Address: 0x102c158 */
    } /* Line 720, Address: 0x102c17c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 722, Address: 0x102c184 */
    }
  }


} /* Line 727, Address: 0x102c1ac */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 745, Address: 0x102c1c0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 749, Address: 0x102c1d4 */
  lXwk = lXsv + xoffs; /* Line 750, Address: 0x102c1dc */
  scrc_h_posit.l = lXwk; /* Line 751, Address: 0x102c1e4 */
  ldXwk.l = lXwk; /* Line 752, Address: 0x102c1ec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 753, Address: 0x102c1f0 */
  ldXwk.w.l &= 16; /* Line 754, Address: 0x102c214 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 755, Address: 0x102c220 */

  if (!ldXwk.b.b4) { /* Line 757, Address: 0x102c23c */
    scrc_h_count ^= 16; /* Line 758, Address: 0x102c248 */
    if (lXwk - lXsv < 0) { /* Line 759, Address: 0x102c25c */
      scrflagc.b.h |= 1 << flgbit; /* Line 760, Address: 0x102c268 */
    } /* Line 761, Address: 0x102c28c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 763, Address: 0x102c294 */
    }
  }


} /* Line 768, Address: 0x102c2bc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 786, Address: 0x102c2d0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 790, Address: 0x102c2e4 */
  lXwk = lXsv + xoffs; /* Line 791, Address: 0x102c2ec */
  scrz_h_posit.l = lXwk; /* Line 792, Address: 0x102c2f4 */
  ldXwk.l = lXwk; /* Line 793, Address: 0x102c2fc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 794, Address: 0x102c300 */
  ldXwk.w.l &= 16; /* Line 795, Address: 0x102c324 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 796, Address: 0x102c330 */

  if (!ldXwk.b.b4) { /* Line 798, Address: 0x102c34c */
    scrz_h_count ^= 16; /* Line 799, Address: 0x102c358 */
    if (lXwk - lXsv < 0) { /* Line 800, Address: 0x102c36c */
      scrflagz.b.h |= 1 << flgbit; /* Line 801, Address: 0x102c378 */
    } /* Line 802, Address: 0x102c39c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 804, Address: 0x102c3a4 */
    }
  }


} /* Line 809, Address: 0x102c3cc */














static void scroll_h() { /* Line 824, Address: 0x102c3e0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 828, Address: 0x102c3f0 */

  scrh_move(); /* Line 830, Address: 0x102c400 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 831, Address: 0x102c408 */
  if (!bXwk) { /* Line 832, Address: 0x102c43c */
    scra_h_count ^= 16; /* Line 833, Address: 0x102c444 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 834, Address: 0x102c458 */
      scrflaga.b.h |= 4; /* Line 835, Address: 0x102c47c */
    } else { /* Line 836, Address: 0x102c490 */
      scrflaga.b.h |= 8; /* Line 837, Address: 0x102c498 */
    }
  }


} /* Line 842, Address: 0x102c4ac */
















static void scrh_move() { /* Line 859, Address: 0x102c4d0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 862, Address: 0x102c4d8 */
  if (xwk == 0) { /* Line 863, Address: 0x102c520 */

    scra_hz = 0; /* Line 865, Address: 0x102c530 */
    return; /* Line 866, Address: 0x102c538 */
  } else if (xwk < 0) { /* Line 867, Address: 0x102c540 */

    if (xwk < -16) { /* Line 869, Address: 0x102c550 */
      xwk = -16; /* Line 870, Address: 0x102c564 */
    }


    xwk += scra_h_posit.w.h; /* Line 874, Address: 0x102c570 */
    if (xwk < scralim_left) { /* Line 875, Address: 0x102c584 */
      xwk = scralim_left; /* Line 876, Address: 0x102c5a8 */
    }
  } /* Line 878, Address: 0x102c5b8 */
  else {
    if (xwk > 16) { /* Line 880, Address: 0x102c5c0 */
      xwk = 16; /* Line 881, Address: 0x102c5d4 */
    }


    xwk += scra_h_posit.w.h; /* Line 885, Address: 0x102c5e0 */
    if (xwk > scralim_right) { /* Line 886, Address: 0x102c5f4 */
      xwk = scralim_right; /* Line 887, Address: 0x102c618 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 892, Address: 0x102c628 */
  scra_h_posit.w.h = xwk; /* Line 893, Address: 0x102c658 */
} /* Line 894, Address: 0x102c660 */














static void scroll_v() { /* Line 909, Address: 0x102c670 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 912, Address: 0x102c67c */
  if (actwk[0].cddat & 4) { /* Line 913, Address: 0x102c6b0 */
    ywk -= 5; /* Line 914, Address: 0x102c6c8 */
  }


  if (actwk[0].cddat & 2) { /* Line 918, Address: 0x102c6d4 */
    ywk += 32; /* Line 919, Address: 0x102c6ec */
    if (ywk < scra_vline) { /* Line 920, Address: 0x102c6f8 */
      ywk -= scra_vline; /* Line 921, Address: 0x102c71c */
      sv_move_main2(ywk); /* Line 922, Address: 0x102c730 */
      return; /* Line 923, Address: 0x102c73c */
    } else if (ywk >= scra_vline + 64) { /* Line 924, Address: 0x102c744 */
      ywk -= scra_vline + 64; /* Line 925, Address: 0x102c76c */
      sv_move_main2(ywk); /* Line 926, Address: 0x102c794 */
      return; /* Line 927, Address: 0x102c7a0 */
    }
    ywk -= scra_vline + 64; /* Line 929, Address: 0x102c7a8 */
    if (!limmoveflag) goto label1; /* Line 930, Address: 0x102c7d0 */
    sv_move_sub2(); /* Line 931, Address: 0x102c7e0 */
    return; /* Line 932, Address: 0x102c7e8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 937, Address: 0x102c7f0 */
    sv_move_main(ywk); /* Line 938, Address: 0x102c81c */
    return; /* Line 939, Address: 0x102c828 */
  } else if (!limmoveflag) goto label1; /* Line 940, Address: 0x102c830 */
  sv_move_sub2(); /* Line 941, Address: 0x102c840 */
  return; /* Line 942, Address: 0x102c848 */



label1:
  scra_vz = 0; /* Line 947, Address: 0x102c850 */
} /* Line 948, Address: 0x102c858 */













static void sv_move_main(short yPos) { /* Line 962, Address: 0x102c870 */
  short spdwk;

  if (scra_vline == 96) { /* Line 965, Address: 0x102c880 */
    if (actwk[0].mspeed.w < 0) { /* Line 966, Address: 0x102c89c */
      spdwk = -actwk[0].mspeed.w; /* Line 967, Address: 0x102c8b4 */
    } else { /* Line 968, Address: 0x102c8d8 */
      spdwk = actwk[0].mspeed.w; /* Line 969, Address: 0x102c8e0 */
    }


    if (spdwk >= 2048) { /* Line 973, Address: 0x102c8f0 */
      sv_move_main2(yPos); /* Line 974, Address: 0x102c904 */
    } /* Line 975, Address: 0x102c910 */
    else {

      if (yPos > 6) { /* Line 978, Address: 0x102c918 */
        sv_move_plus(1536); /* Line 979, Address: 0x102c930 */
      } else if (yPos < -6) { /* Line 980, Address: 0x102c93c */
        sv_move_minus(1536); /* Line 981, Address: 0x102c95c */
      } /* Line 982, Address: 0x102c968 */
      else sv_move_sub(yPos); /* Line 983, Address: 0x102c970 */
    }
  } /* Line 985, Address: 0x102c97c */
  else {
    if (yPos > 2) { /* Line 987, Address: 0x102c984 */
      sv_move_plus(512); /* Line 988, Address: 0x102c99c */
    } else if (yPos < -2) { /* Line 989, Address: 0x102c9a8 */
      sv_move_minus(512); /* Line 990, Address: 0x102c9c8 */
    } /* Line 991, Address: 0x102c9d4 */
    else sv_move_sub(yPos); /* Line 992, Address: 0x102c9dc */
  }

} /* Line 995, Address: 0x102c9e8 */













static void sv_move_main2(short yPos) { /* Line 1009, Address: 0x102ca00 */
  short spdwk;

  spdwk = 4096; /* Line 1012, Address: 0x102ca10 */

  if (yPos > 16) { /* Line 1014, Address: 0x102ca1c */
    sv_move_plus(spdwk); /* Line 1015, Address: 0x102ca34 */
  } else if (yPos < -16) { /* Line 1016, Address: 0x102ca40 */
    sv_move_minus(spdwk); /* Line 1017, Address: 0x102ca60 */
  } else { /* Line 1018, Address: 0x102ca6c */
    sv_move_sub(yPos); /* Line 1019, Address: 0x102ca74 */
  }
} /* Line 1021, Address: 0x102ca80 */














static void sv_move_sub(short yPos) { /* Line 1036, Address: 0x102caa0 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1039, Address: 0x102caac */
  if (yPos < 0) { /* Line 1040, Address: 0x102cad8 */
    scrv_up_ch(lSpd); /* Line 1041, Address: 0x102caec */
  } else { /* Line 1042, Address: 0x102caf8 */
    scrv_down_ch(lSpd); /* Line 1043, Address: 0x102cb00 */
  }
} /* Line 1045, Address: 0x102cb0c */



static void sv_move_sub2() { /* Line 1049, Address: 0x102cb20 */
  limmoveflag = 0; /* Line 1050, Address: 0x102cb28 */

  sv_move_sub(0); /* Line 1052, Address: 0x102cb30 */
} /* Line 1053, Address: 0x102cb3c */













static void sv_move_minus(short speed) { /* Line 1067, Address: 0x102cb50 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1070, Address: 0x102cb5c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1071, Address: 0x102cb80 */
  scrv_up_ch(lSpd); /* Line 1072, Address: 0x102cba4 */
} /* Line 1073, Address: 0x102cbb0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1088, Address: 0x102cbc0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1089, Address: 0x102cbcc */
    if (lSpd.w.l > -256) { /* Line 1090, Address: 0x102cbf4 */

      lSpd.w.l = scralim_up; /* Line 1092, Address: 0x102cc0c */
    } else { /* Line 1093, Address: 0x102cc18 */
      lSpd.w.l &= 2047; /* Line 1094, Address: 0x102cc20 */
      actwk[0].yposi.w.l &= 2047; /* Line 1095, Address: 0x102cc2c */
      scra_v_posit.w.h &= 2047; /* Line 1096, Address: 0x102cc40 */
      scrb_v_posit.w.h &= 1023; /* Line 1097, Address: 0x102cc54 */
    }
  }

  scrv_move(lSpd); /* Line 1101, Address: 0x102cc68 */
} /* Line 1102, Address: 0x102cc74 */













static void sv_move_plus(short sSpd) { /* Line 1116, Address: 0x102cc90 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1119, Address: 0x102cc9c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1120, Address: 0x102ccbc */
  scrv_down_ch(lSpd); /* Line 1121, Address: 0x102cce0 */
} /* Line 1122, Address: 0x102ccec */














static void scrv_down_ch(int_union lSpd) { /* Line 1137, Address: 0x102cd00 */
  if (lSpd.w.l >= scralim_down) { /* Line 1138, Address: 0x102cd0c */
    if (lSpd.w.l < 2048) { /* Line 1139, Address: 0x102cd34 */

      lSpd.w.l = scralim_down; /* Line 1141, Address: 0x102cd4c */
    } else { /* Line 1142, Address: 0x102cd58 */
      lSpd.w.l -= 2048; /* Line 1143, Address: 0x102cd60 */
      actwk[0].yposi.w.l &= 2047; /* Line 1144, Address: 0x102cd6c */
      scra_v_posit.w.h -= 2048; /* Line 1145, Address: 0x102cd80 */
      scrb_v_posit.w.h &= 1023; /* Line 1146, Address: 0x102cd94 */
    }
  }

  scrv_move(lSpd); /* Line 1150, Address: 0x102cda8 */
} /* Line 1151, Address: 0x102cdb4 */
















static void scrv_move(int_union lSpd) { /* Line 1168, Address: 0x102cdd0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1172, Address: 0x102cde0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1173, Address: 0x102cdf0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1174, Address: 0x102ce14 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1175, Address: 0x102ce28 */
  scra_vz = spdwk.w.l; /* Line 1176, Address: 0x102ce40 */

  scra_v_posit.l = lSpd.l; /* Line 1178, Address: 0x102ce4c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1180, Address: 0x102ce58 */
  if (!ywk) { /* Line 1181, Address: 0x102ce94 */
    scra_v_count ^= 16; /* Line 1182, Address: 0x102ce9c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1183, Address: 0x102ceb0 */
    if (ywk < 0) { /* Line 1184, Address: 0x102cedc */
      scrflaga.b.h |= 1; /* Line 1185, Address: 0x102ceec */
    } else { /* Line 1186, Address: 0x102cf00 */
      scrflaga.b.h |= 2; /* Line 1187, Address: 0x102cf08 */
    }
  }


} /* Line 1192, Address: 0x102cf1c */

















void scrollwrt() { /* Line 1210, Address: 0x102cf30 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1219, Address: 0x102cf50 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1220, Address: 0x102cf54 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1221, Address: 0x102cf60 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1222, Address: 0x102cf6c */
  pScrFlag = &scrflagbw.b.h; /* Line 1223, Address: 0x102cf74 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1224, Address: 0x102cf7c */

  VramBase = 16384; /* Line 1226, Address: 0x102cf90 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1227, Address: 0x102cf94 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1228, Address: 0x102cfa0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1229, Address: 0x102cfac */
  pScrFlag = &scrflagaw.b.h; /* Line 1230, Address: 0x102cfb4 */

  if (*pScrFlag) { /* Line 1232, Address: 0x102cfbc */
    if (*pScrFlag & 1) { /* Line 1233, Address: 0x102cfc8 */
      *pScrFlag &= 254; /* Line 1234, Address: 0x102cfdc */

      lD4.l = -16; /* Line 1236, Address: 0x102cfe8 */
      wD5 = 65520; /* Line 1237, Address: 0x102cff0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1239, Address: 0x102cff8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1241, Address: 0x102d018 */
    }




    if (*pScrFlag & 2) { /* Line 1247, Address: 0x102d044 */
      *pScrFlag &= 253; /* Line 1248, Address: 0x102d058 */

      lD4.l = 224; /* Line 1250, Address: 0x102d064 */
      wD5 = 65520; /* Line 1251, Address: 0x102d06c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1252, Address: 0x102d074 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1254, Address: 0x102d094 */
    }




    if (*pScrFlag & 4) { /* Line 1260, Address: 0x102d0c0 */
      *pScrFlag &= 251; /* Line 1261, Address: 0x102d0d4 */

      lD4.l = -16; /* Line 1263, Address: 0x102d0e0 */
      wD5 = 65520; /* Line 1264, Address: 0x102d0e8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1265, Address: 0x102d0f0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1267, Address: 0x102d110 */
    }




    if (*pScrFlag & 8) { /* Line 1273, Address: 0x102d13c */
      *pScrFlag &= 247; /* Line 1274, Address: 0x102d150 */

      lD4.l = -16; /* Line 1276, Address: 0x102d15c */
      wD5 = 320; /* Line 1277, Address: 0x102d164 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1278, Address: 0x102d16c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1280, Address: 0x102d18c */
    }
  }






} /* Line 1289, Address: 0x102d1b8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1306, Address: 0x102d1e0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1317, Address: 0x102d20c */

  if (*pScrFlag & 1) { /* Line 1319, Address: 0x102d214 */
    *pScrFlag &= 254; /* Line 1320, Address: 0x102d22c */
  } /* Line 1321, Address: 0x102d240 */
  else {
    *pScrFlag &= 254; /* Line 1323, Address: 0x102d248 */

    if (*pScrFlag & 2) { /* Line 1325, Address: 0x102d25c */
      *pScrFlag &= 253; /* Line 1326, Address: 0x102d274 */
      lD4.w.l = 224; /* Line 1327, Address: 0x102d288 */
    } /* Line 1328, Address: 0x102d290 */
    else {
      *pScrFlag &= 253; /* Line 1330, Address: 0x102d298 */
      goto label1; /* Line 1331, Address: 0x102d2ac */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1336, Address: 0x102d2b4 */
  wD0 &= 127; /* Line 1337, Address: 0x102d304 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1338, Address: 0x102d30c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1344, Address: 0x102d32c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1345, Address: 0x102d34c */
  if (wD0 != 0) { /* Line 1346, Address: 0x102d370 */
    wD5 = 65520; /* Line 1347, Address: 0x102d37c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1348, Address: 0x102d384 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1350, Address: 0x102d3a4 */



  } /* Line 1354, Address: 0x102d3d0 */
  else {

    wD5 = 0; /* Line 1357, Address: 0x102d3d8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1358, Address: 0x102d3dc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1362, Address: 0x102d3fc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1369, Address: 0x102d428 */






    lD4.l = -16; /* Line 1376, Address: 0x102d43c */
    wD5 = 65520; /* Line 1377, Address: 0x102d444 */
    if (*pScrFlag & 168) { /* Line 1378, Address: 0x102d44c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1379, Address: 0x102d464 */
      wD5 = 320; /* Line 1380, Address: 0x102d484 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1384, Address: 0x102d48c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1386, Address: 0x102d4bc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1387, Address: 0x102d4c8 */



    for (i = 0; i < 16; ++i) { /* Line 1391, Address: 0x102d4d8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1392, Address: 0x102d4e4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1393, Address: 0x102d504 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1394, Address: 0x102d53c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1395, Address: 0x102d55c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1397, Address: 0x102d580 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1400, Address: 0x102d5a4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1402, Address: 0x102d5c4 */
      }
      lD4.w.l += 16; /* Line 1404, Address: 0x102d5d8 */
    } /* Line 1405, Address: 0x102d5e4 */
    *pScrFlag = 0; /* Line 1406, Address: 0x102d5f4 */
  }
} /* Line 1408, Address: 0x102d5fc */





void scrollwrtc() {} /* Line 1414, Address: 0x102d630 */




void scrollwrtz() {} /* Line 1419, Address: 0x102d640 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1437, Address: 0x102d650 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1450, Address: 0x102d678 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1453, Address: 0x102d698 */
    pTilePoint->x += 2; /* Line 1454, Address: 0x102d6ac */
    if (pTilePoint->x >= 64) { /* Line 1455, Address: 0x102d6c0 */
      pTilePoint->x -= 64; /* Line 1456, Address: 0x102d6d4 */
    }
    xOffs += 16; /* Line 1458, Address: 0x102d6e8 */
  } while (--lpcnt >= 0); /* Line 1459, Address: 0x102d6f4 */
} /* Line 1460, Address: 0x102d708 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1464, Address: 0x102d720 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1468, Address: 0x102d748 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1471, Address: 0x102d768 */
    pTilePoint->x += 2; /* Line 1472, Address: 0x102d77c */
    if (pTilePoint->x >= 64) { /* Line 1473, Address: 0x102d790 */
      pTilePoint->x -= 64; /* Line 1474, Address: 0x102d7a4 */
    }
    xOffs += 16; /* Line 1476, Address: 0x102d7b8 */
  } while (--lpcnt >= 0); /* Line 1477, Address: 0x102d7c4 */
} /* Line 1478, Address: 0x102d7d8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1498, Address: 0x102d7f0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1502, Address: 0x102d818 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1505, Address: 0x102d838 */
    pTilePoint->y += 2; /* Line 1506, Address: 0x102d84c */
    if (pTilePoint->y >= 32) { /* Line 1507, Address: 0x102d85c */
      pTilePoint->y -= 32; /* Line 1508, Address: 0x102d870 */
    }
    yOffs += 16; /* Line 1510, Address: 0x102d880 */
  } while (--lpcnt >= 0); /* Line 1511, Address: 0x102d88c */
} /* Line 1512, Address: 0x102d8a0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1531, Address: 0x102d8b0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1537, Address: 0x102d8e4 */

    base = 1; /* Line 1539, Address: 0x102d8f4 */
  } /* Line 1540, Address: 0x102d8f8 */
  else if (VramBase == 16384) { /* Line 1541, Address: 0x102d900 */

    base = 0; /* Line 1543, Address: 0x102d910 */
  }
  x = pTilePoint->x; /* Line 1545, Address: 0x102d914 */
  y = pTilePoint->y; /* Line 1546, Address: 0x102d91c */


  frip = BlkIndex & 6144; /* Line 1549, Address: 0x102d924 */
  BlkIndex &= 1023; /* Line 1550, Address: 0x102d92c */
  if (frip == 6144) { /* Line 1551, Address: 0x102d938 */

    p0 = 3, p1 = 2; /* Line 1553, Address: 0x102d944 */
    p2 = 1, p3 = 0; /* Line 1554, Address: 0x102d94c */
  } /* Line 1555, Address: 0x102d954 */
  else if (frip & 4096) { /* Line 1556, Address: 0x102d95c */

    p0 = 2, p1 = 3; /* Line 1558, Address: 0x102d968 */
    p2 = 0, p3 = 1; /* Line 1559, Address: 0x102d970 */
  } /* Line 1560, Address: 0x102d978 */
  else if (frip & 2048) { /* Line 1561, Address: 0x102d980 */

    p0 = 1, p1 = 0; /* Line 1563, Address: 0x102d98c */
    p2 = 3, p3 = 2; /* Line 1564, Address: 0x102d994 */
  } /* Line 1565, Address: 0x102d99c */
  else {

    p0 = 0, p1 = 1; /* Line 1568, Address: 0x102d9a4 */
    p2 = 2, p3 = 3; /* Line 1569, Address: 0x102d9ac */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1572, Address: 0x102d9b4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1573, Address: 0x102d9f8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1574, Address: 0x102da3c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1575, Address: 0x102da80 */

} /* Line 1577, Address: 0x102dac4 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1594, Address: 0x102db00 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1595, Address: 0x102db20 */
} /* Line 1596, Address: 0x102db40 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1598, Address: 0x102db50 */
  wH_posiw = 0; /* Line 1599, Address: 0x102db70 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1600, Address: 0x102db74 */
} /* Line 1601, Address: 0x102db94 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1608, Address: 0x102dbb0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1614, Address: 0x102dbe0 */
  yOffs += wV_posiw; /* Line 1615, Address: 0x102dbf0 */





  if ((short)xOffs < 0) /* Line 1621, Address: 0x102dc00 */
    xOffs = 0; /* Line 1622, Address: 0x102dc1c */
  if ((short)yOffs < 0) /* Line 1623, Address: 0x102dc20 */
    yOffs = 0; /* Line 1624, Address: 0x102dc3c */
  if ((short)xOffs >= 16384) /* Line 1625, Address: 0x102dc40 */
    xOffs = 16383; /* Line 1626, Address: 0x102dc60 */
  if ((short)yOffs >= 2048) /* Line 1627, Address: 0x102dc68 */
    yOffs = 2047; /* Line 1628, Address: 0x102dc88 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1629, Address: 0x102dc90 */
  if (i < 0) i = 0; /* Line 1630, Address: 0x102dcd8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1632, Address: 0x102dce4 */

  if (ScreenNo) { /* Line 1634, Address: 0x102dd00 */




    xOffs &= 32767; /* Line 1639, Address: 0x102dd08 */
    yOffs &= 32767; /* Line 1640, Address: 0x102dd14 */


    xBlk = xOffs; /* Line 1643, Address: 0x102dd20 */
    xBlk %= 256; /* Line 1644, Address: 0x102dd28 */
    xBlk /= 16; /* Line 1645, Address: 0x102dd48 */
    yBlk = yOffs; /* Line 1646, Address: 0x102dd64 */
    yBlk %= 256; /* Line 1647, Address: 0x102dd6c */
    yBlk /= 16; /* Line 1648, Address: 0x102dd8c */

    lpw = pmapwk; /* Line 1650, Address: 0x102dda8 */
    lpw += xBlk; /* Line 1651, Address: 0x102ddb0 */
    lpw += yBlk * 16; /* Line 1652, Address: 0x102ddb8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1653, Address: 0x102ddc4 */
    *pIndex = *lpw; /* Line 1654, Address: 0x102dddc */

    return 1; /* Line 1656, Address: 0x102ddec */
  }

  *pIndex = 0; /* Line 1659, Address: 0x102ddf8 */
  return 0; /* Line 1660, Address: 0x102de00 */
} /* Line 1661, Address: 0x102de04 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1681, Address: 0x102de30 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1689, Address: 0x102de58 */
  if (ScreenNo) { /* Line 1690, Address: 0x102debc */





    xBlk = xOffs; /* Line 1696, Address: 0x102dec4 */
    xBlk %= 256; /* Line 1697, Address: 0x102decc */
    xBlk /= 16; /* Line 1698, Address: 0x102deec */
    yBlk = yOffs; /* Line 1699, Address: 0x102df08 */
    yBlk %= 256; /* Line 1700, Address: 0x102df10 */
    yBlk /= 16; /* Line 1701, Address: 0x102df30 */


    lpw = pmapwk; /* Line 1704, Address: 0x102df4c */
    lpw += xBlk; /* Line 1705, Address: 0x102df54 */
    lpw += yBlk * 16; /* Line 1706, Address: 0x102df5c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1707, Address: 0x102df68 */
    *ppBlockNo = lpw; /* Line 1708, Address: 0x102df80 */
    *pIndex = *lpw; /* Line 1709, Address: 0x102df88 */




    return 1; /* Line 1714, Address: 0x102df98 */
  }

  *pIndex = 0; /* Line 1717, Address: 0x102dfa4 */
  return 0; /* Line 1718, Address: 0x102dfac */
} /* Line 1719, Address: 0x102dfb0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1733, Address: 0x102dfd0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1740, Address: 0x102dfec */
  pMapWk = (unsigned char*)mapwka; /* Line 1741, Address: 0x102dff0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1742, Address: 0x102dff8 */
    *pBlockIndex = BlockNo; /* Line 1743, Address: 0x102e01c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1744, Address: 0x102e028 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1745, Address: 0x102e040 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1746, Address: 0x102e054 */
    }
  }


} /* Line 1751, Address: 0x102e06c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1765, Address: 0x102e090 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1766, Address: 0x102e09c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1767, Address: 0x102e0c8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1768, Address: 0x102e114 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1769, Address: 0x102e140 */

          return 0; /* Line 1771, Address: 0x102e18c */
        }
      }
    }
  }

  return 1; /* Line 1777, Address: 0x102e198 */
} /* Line 1778, Address: 0x102e19c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1795, Address: 0x102e1b0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1796, Address: 0x102e1cc */

} /* Line 1798, Address: 0x102e1e8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1800, Address: 0x102e200 */
  wH_posiw = 0; /* Line 1801, Address: 0x102e21c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1802, Address: 0x102e220 */

} /* Line 1804, Address: 0x102e23c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1806, Address: 0x102e250 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1807, Address: 0x102e264 */

} /* Line 1809, Address: 0x102e280 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1811, Address: 0x102e290 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1812, Address: 0x102e2ac */

} /* Line 1814, Address: 0x102e2c8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1816, Address: 0x102e2e0 */
  xOffs += wH_posiw; /* Line 1817, Address: 0x102e2f8 */
  yOffs += wV_posiw; /* Line 1818, Address: 0x102e308 */
  yOffs &= 240; /* Line 1819, Address: 0x102e318 */
  xOffs &= 496; /* Line 1820, Address: 0x102e324 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1822, Address: 0x102e330 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1823, Address: 0x102e35c */


} /* Line 1826, Address: 0x102e388 */















void mapwrt() { /* Line 1842, Address: 0x102e3a0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1849, Address: 0x102e3b8 */
  wV_posiw = scra_v_posit.w.h; /* Line 1850, Address: 0x102e3c4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1851, Address: 0x102e3d0 */
  VramBase = 16384; /* Line 1852, Address: 0x102e3d8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1853, Address: 0x102e3dc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1857, Address: 0x102e3f4 */
  VramBase = 24576; /* Line 1858, Address: 0x102e3fc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1859, Address: 0x102e400 */

} /* Line 1861, Address: 0x102e410 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1864, Address: 0x102e430 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1865, Address: 0x102e448 */
} /* Line 1866, Address: 0x102e468 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1871, Address: 0x102e480 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1875, Address: 0x102e4a0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1878, Address: 0x102e4bc */



    wD4 += 16; /* Line 1882, Address: 0x102e4e4 */
  } while ((short)--wD6 >= 0); /* Line 1883, Address: 0x102e4f0 */

} /* Line 1885, Address: 0x102e518 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1891, Address: 0x102e530 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1894, Address: 0x102e54c */
  wD6 = 15; /* Line 1895, Address: 0x102e554 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1898, Address: 0x102e55c */

    mapwrt_sub(z81awrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1900, Address: 0x102e580 */
    wD4 += 16; /* Line 1901, Address: 0x102e5a0 */
  } while ((short)--wD6 >= 0); /* Line 1902, Address: 0x102e5a8 */
} /* Line 1903, Address: 0x102e5cc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1929, Address: 0x102e5f0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1934, Address: 0x102e618 */
  wD0 = pWrttbl[wD0]; /* Line 1935, Address: 0x102e628 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1937, Address: 0x102e644 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1938, Address: 0x102e668 */
  if (wD0) { /* Line 1939, Address: 0x102e690 */
    wD5 = 65520; /* Line 1940, Address: 0x102e69c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1941, Address: 0x102e6a4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1944, Address: 0x102e6c0 */



  } /* Line 1948, Address: 0x102e6e8 */
  else {

    wD5 = 0; /* Line 1951, Address: 0x102e6f0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1952, Address: 0x102e6f4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1956, Address: 0x102e710 */
  }





} /* Line 1963, Address: 0x102e738 */










void mapinit() { /* Line 1974, Address: 0x102e760 */

  colorset2(mapinittbl.colorno2); /* Line 1976, Address: 0x102e768 */
  colorset(mapinittbl.colorno2); /* Line 1977, Address: 0x102e77c */


  if (play_start & 2) divdevset(); /* Line 1980, Address: 0x102e790 */
} /* Line 1981, Address: 0x102e7b0 */




void mapset() {} /* Line 1986, Address: 0x102e7c0 */



void divdevset() {} /* Line 1990, Address: 0x102e7d0 */



void enecginit() {} /* Line 1994, Address: 0x102e7e0 */
