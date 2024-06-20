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
  4, 6, 6, 6, 6, 6, 6, 4, 4
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
short scr_dir_tbl[6] = { 4, 0, 8855, 0, 1808, 96 };
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
short playpositbl[1][2] = { { 160, 1196 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;












































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x102b070 */
    return &actwk[0]; /* Line 147, Address: 0x102b084 */
  else
    return &actwk[1]; /* Line 149, Address: 0x102b094 */

} /* Line 151, Address: 0x102b09c */





































void scr_set() { /* Line 189, Address: 0x102b0b0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x102b0bc */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x102b0d0 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x102b0e4 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x102b0ec */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x102b0f4 */
  ++pScrTbl; /* Line 198, Address: 0x102b100 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x102b104 */
  ++pScrTbl; /* Line 200, Address: 0x102b118 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x102b11c */
  ++pScrTbl; /* Line 202, Address: 0x102b130 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x102b134 */
  ++pScrTbl; /* Line 204, Address: 0x102b148 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x102b14c */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x102b160 */
  ++pScrTbl; /* Line 207, Address: 0x102b180 */
  scra_h_count = 16; /* Line 208, Address: 0x102b184 */
  scra_v_count = 16; /* Line 209, Address: 0x102b190 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102b19c */
  scra_hline = 160; /* Line 212, Address: 0x102b1a8 */

  playposiset(); /* Line 214, Address: 0x102b1b4 */
} /* Line 215, Address: 0x102b1bc */
















































static void playposiset() { /* Line 264, Address: 0x102b1d0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x102b1e4 */
    playload(); /* Line 268, Address: 0x102b1f4 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x102b1fc */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x102b20c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x102b224 */
    } else { /* Line 273, Address: 0x102b234 */
      ywk = 0; /* Line 274, Address: 0x102b23c */
    }
  } /* Line 276, Address: 0x102b240 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x102b248 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x102b268 */
    } /* Line 280, Address: 0x102b28c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x102b294 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x102b2b4 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x102b2c8 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x102b2dc */
    xwk -= 160; /* Line 292, Address: 0x102b2f0 */
  } else { /* Line 293, Address: 0x102b2fc */
    xwk = 0; /* Line 294, Address: 0x102b304 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x102b308 */
    xwk = scralim_right; /* Line 299, Address: 0x102b32c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x102b33c */

  if (ywk > 96) { /* Line 305, Address: 0x102b344 */
    ywk -= 96; /* Line 306, Address: 0x102b358 */
  } else { /* Line 307, Address: 0x102b364 */
    ywk = 0; /* Line 308, Address: 0x102b36c */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x102b370 */
    ywk = scralim_down; /* Line 313, Address: 0x102b394 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x102b3a4 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102b3ac */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102b3bc */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102b3cc */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102b3dc */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102b3ec */
} /* Line 326, Address: 0x102b3fc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x102b420 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102b42c */
  lYwk.w.l = 0; /* Line 351, Address: 0x102b434 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x102b438 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x102b444 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x102b450 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102b45c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x102b468 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x102b484 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x102b490 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102b4ac */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x102b4b8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x102b4d4 */
} /* Line 366, Address: 0x102b4f8 */















void scroll() { /* Line 382, Address: 0x102b510 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x102b52c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x102b53c */

  scrchk(); /* Line 401, Address: 0x102b568 */

  scroll_h(); /* Line 403, Address: 0x102b570 */
  scroll_v(); /* Line 404, Address: 0x102b578 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x102b580 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x102b590 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x102b5a0 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x102b5b4 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x102b5c4 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x102b5d8 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x102b5e8 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x102b604 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x102b614 */


  scrollb_v(lYwk); /* Line 422, Address: 0x102b628 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x102b638 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x102b660 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x102b698 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102b6ac */

  z81aline(&psHscw); /* Line 431, Address: 0x102b6b8 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 433, Address: 0x102b6c4 */
  for (i = 0; i < 14; ++i) { /* Line 434, Address: 0x102b6e4 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x102b6f0 */
  } /* Line 437, Address: 0x102b704 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 439, Address: 0x102b714 */
  for (i = 0; i < 2; ++i) { /* Line 440, Address: 0x102b734 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x102b740 */
  } /* Line 443, Address: 0x102b754 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 445, Address: 0x102b764 */
  for (i = 0; i < 4; ++i) { /* Line 446, Address: 0x102b784 */

    *psHscw++ = ldwk.w.l; /* Line 448, Address: 0x102b790 */
  } /* Line 449, Address: 0x102b7a4 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 451, Address: 0x102b7b4 */
  for (i = 0; i < 12; ++i) { /* Line 452, Address: 0x102b7d4 */

    *psHscw++ = ldwk.w.l; /* Line 454, Address: 0x102b7e0 */
  } /* Line 455, Address: 0x102b7f4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 457, Address: 0x102b804 */
  for (i = 0; i < 4; ++i) { /* Line 458, Address: 0x102b824 */

    *psHscw++ = ldwk.w.l; /* Line 460, Address: 0x102b830 */
  } /* Line 461, Address: 0x102b844 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 463, Address: 0x102b854 */
  for (i = 0; i < 12; ++i) { /* Line 464, Address: 0x102b874 */

    *psHscw++ = ldwk.w.l; /* Line 466, Address: 0x102b880 */
  } /* Line 467, Address: 0x102b894 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 469, Address: 0x102b8a4 */
  for (i = 0; i < 4; ++i) { /* Line 470, Address: 0x102b8c4 */

    *psHscw++ = ldwk.w.l; /* Line 472, Address: 0x102b8d0 */
  } /* Line 473, Address: 0x102b8e4 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 475, Address: 0x102b8f4 */
  for (i = 0; i < 12; ++i) { /* Line 476, Address: 0x102b914 */

    *psHscw++ = ldwk.w.l; /* Line 478, Address: 0x102b920 */
  } /* Line 479, Address: 0x102b934 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 481, Address: 0x102b944 */
  for (i = 0; i < 4; ++i) { /* Line 482, Address: 0x102b964 */

    *psHscw++ = ldwk.w.l; /* Line 484, Address: 0x102b970 */
  } /* Line 485, Address: 0x102b984 */

  pHscrbuf = lphscrollbuff; /* Line 487, Address: 0x102b994 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 488, Address: 0x102b9a0 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 489, Address: 0x102b9d0 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 490, Address: 0x102ba00 */
} /* Line 491, Address: 0x102ba1c */













static void z81aline(short** ppHscw) { /* Line 505, Address: 0x102ba40 */
  char z81ascrtbl[17] = { /* Line 506, Address: 0x102ba54 */
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0
  };
  int i;
  int j;
  int_union radwk;
  int lXwk;

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 514, Address: 0x102ba80 */
  radwk.w.l = scrb_h_posit.w.h; /* Line 515, Address: 0x102baa4 */
  lXwk <<= 7; /* Line 516, Address: 0x102bab0 */
  lXwk /= 17; /* Line 517, Address: 0x102bab4 */
  lXwk <<= 9; /* Line 518, Address: 0x102bacc */


  *ppHscw += 28; /* Line 521, Address: 0x102bad0 */

  for (i = 16; i >= 0; --i) { /* Line 523, Address: 0x102bae4 */

    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 525, Address: 0x102baf0 */
      --*ppHscw; /* Line 526, Address: 0x102bb08 */
      **ppHscw = -radwk.w.l; /* Line 527, Address: 0x102bb1c */
    } /* Line 528, Address: 0x102bb40 */

    radwk.l = (unsigned int)radwk.l >> 16 & 65535 | radwk.l << 16 & -65536; /* Line 530, Address: 0x102bb4c */
    radwk.l += lXwk; /* Line 531, Address: 0x102bb70 */
    radwk.l = (unsigned int)radwk.l >> 16 & 65535 | radwk.l << 16 & -65536; /* Line 532, Address: 0x102bb7c */
  } /* Line 533, Address: 0x102bba0 */

  *ppHscw += 28; /* Line 535, Address: 0x102bbac */
} /* Line 536, Address: 0x102bbc0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 557, Address: 0x102bbe0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 561, Address: 0x102bbfc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 562, Address: 0x102bc00 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 564, Address: 0x102bc20 */
    ldwk.w.l = *pHscrwk; /* Line 565, Address: 0x102bc3c */
    ++pHscrwk; /* Line 566, Address: 0x102bc48 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 568, Address: 0x102bc54 */
      (*pHscrbuf)->l = ldwk.l; /* Line 569, Address: 0x102bc5c */
    } /* Line 570, Address: 0x102bc6c */
  } /* Line 571, Address: 0x102bc90 */


















} /* Line 590, Address: 0x102bcb0 */









































































































static void scrollb_v(short yPos) { /* Line 696, Address: 0x102bcd0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 699, Address: 0x102bce0 */
  scrb_v_posit.w.h = yPos; /* Line 700, Address: 0x102bcf0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 701, Address: 0x102bcfc */

  if (!ywk) { /* Line 703, Address: 0x102bd34 */
    scrb_v_count ^= 16; /* Line 704, Address: 0x102bd3c */
    if (yPos - ysv < 0) { /* Line 705, Address: 0x102bd50 */
      scrflagb.b.h |= 1; /* Line 706, Address: 0x102bd70 */
    } /* Line 707, Address: 0x102bd84 */
    else {
      scrflagb.b.h |= 2; /* Line 709, Address: 0x102bd8c */
    }
  }


} /* Line 714, Address: 0x102bda0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 732, Address: 0x102bdc0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 736, Address: 0x102bdd4 */
  lXwk = lXsv + xoffs; /* Line 737, Address: 0x102bddc */
  scrb_h_posit.l = lXwk; /* Line 738, Address: 0x102bde4 */
  ldXwk.l = lXwk; /* Line 739, Address: 0x102bdec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 740, Address: 0x102bdf0 */
  ldXwk.w.l &= 16; /* Line 741, Address: 0x102be14 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 742, Address: 0x102be20 */

  if (!ldXwk.b.b4) { /* Line 744, Address: 0x102be3c */
    scrb_h_count ^= 16; /* Line 745, Address: 0x102be48 */
    if (lXwk - lXsv < 0) { /* Line 746, Address: 0x102be5c */
      scrflagb.b.h |= 1 << flgbit; /* Line 747, Address: 0x102be68 */
    } /* Line 748, Address: 0x102be8c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 750, Address: 0x102be94 */
    }
  }


} /* Line 755, Address: 0x102bebc */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 773, Address: 0x102bed0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 777, Address: 0x102bee4 */
  lXwk = lXsv + xoffs; /* Line 778, Address: 0x102beec */
  scrc_h_posit.l = lXwk; /* Line 779, Address: 0x102bef4 */
  ldXwk.l = lXwk; /* Line 780, Address: 0x102befc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 781, Address: 0x102bf00 */
  ldXwk.w.l &= 16; /* Line 782, Address: 0x102bf24 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 783, Address: 0x102bf30 */

  if (!ldXwk.b.b4) { /* Line 785, Address: 0x102bf4c */
    scrc_h_count ^= 16; /* Line 786, Address: 0x102bf58 */
    if (lXwk - lXsv < 0) { /* Line 787, Address: 0x102bf6c */
      scrflagc.b.h |= 1 << flgbit; /* Line 788, Address: 0x102bf78 */
    } /* Line 789, Address: 0x102bf9c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 791, Address: 0x102bfa4 */
    }
  }


} /* Line 796, Address: 0x102bfcc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 814, Address: 0x102bfe0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 818, Address: 0x102bff4 */
  lXwk = lXsv + xoffs; /* Line 819, Address: 0x102bffc */
  scrz_h_posit.l = lXwk; /* Line 820, Address: 0x102c004 */
  ldXwk.l = lXwk; /* Line 821, Address: 0x102c00c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 822, Address: 0x102c010 */
  ldXwk.w.l &= 16; /* Line 823, Address: 0x102c034 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 824, Address: 0x102c040 */

  if (!ldXwk.b.b4) { /* Line 826, Address: 0x102c05c */
    scrz_h_count ^= 16; /* Line 827, Address: 0x102c068 */
    if (lXwk - lXsv < 0) { /* Line 828, Address: 0x102c07c */
      scrflagz.b.h |= 1 << flgbit; /* Line 829, Address: 0x102c088 */
    } /* Line 830, Address: 0x102c0ac */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 832, Address: 0x102c0b4 */
    }
  }


} /* Line 837, Address: 0x102c0dc */














static void scroll_h() { /* Line 852, Address: 0x102c0f0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 856, Address: 0x102c100 */

  scrh_move(); /* Line 858, Address: 0x102c110 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 859, Address: 0x102c118 */
  if (!bXwk) { /* Line 860, Address: 0x102c14c */
    scra_h_count ^= 16; /* Line 861, Address: 0x102c154 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 862, Address: 0x102c168 */
      scrflaga.b.h |= 4; /* Line 863, Address: 0x102c18c */
    } else { /* Line 864, Address: 0x102c1a0 */
      scrflaga.b.h |= 8; /* Line 865, Address: 0x102c1a8 */
    }
  }


} /* Line 870, Address: 0x102c1bc */
















static void scrh_move() { /* Line 887, Address: 0x102c1e0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 890, Address: 0x102c1e8 */
  if (xwk == 0) { /* Line 891, Address: 0x102c230 */

    scra_hz = 0; /* Line 893, Address: 0x102c240 */
    return; /* Line 894, Address: 0x102c248 */
  } else if (xwk < 0) { /* Line 895, Address: 0x102c250 */

    if (xwk < -16) { /* Line 897, Address: 0x102c260 */
      xwk = -16; /* Line 898, Address: 0x102c274 */
    }


    xwk += scra_h_posit.w.h; /* Line 902, Address: 0x102c280 */
    if (xwk < scralim_left) { /* Line 903, Address: 0x102c294 */
      xwk = scralim_left; /* Line 904, Address: 0x102c2b8 */
    }
  } /* Line 906, Address: 0x102c2c8 */
  else {
    if (xwk > 16) { /* Line 908, Address: 0x102c2d0 */
      xwk = 16; /* Line 909, Address: 0x102c2e4 */
    }


    xwk += scra_h_posit.w.h; /* Line 913, Address: 0x102c2f0 */
    if (xwk > scralim_right) { /* Line 914, Address: 0x102c304 */
      xwk = scralim_right; /* Line 915, Address: 0x102c328 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 920, Address: 0x102c338 */
  scra_h_posit.w.h = xwk; /* Line 921, Address: 0x102c368 */
} /* Line 922, Address: 0x102c370 */














static void scroll_v() { /* Line 937, Address: 0x102c380 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 940, Address: 0x102c38c */
  if (actwk[0].cddat & 4) { /* Line 941, Address: 0x102c3c0 */
    ywk -= 5; /* Line 942, Address: 0x102c3d8 */
  }


  if (actwk[0].cddat & 2) { /* Line 946, Address: 0x102c3e4 */
    ywk += 32; /* Line 947, Address: 0x102c3fc */
    if (ywk < scra_vline) { /* Line 948, Address: 0x102c408 */
      ywk -= scra_vline; /* Line 949, Address: 0x102c42c */
      sv_move_main2(ywk); /* Line 950, Address: 0x102c440 */
      return; /* Line 951, Address: 0x102c44c */
    } else if (ywk >= scra_vline + 64) { /* Line 952, Address: 0x102c454 */
      ywk -= scra_vline + 64; /* Line 953, Address: 0x102c47c */
      sv_move_main2(ywk); /* Line 954, Address: 0x102c4a4 */
      return; /* Line 955, Address: 0x102c4b0 */
    }
    ywk -= scra_vline + 64; /* Line 957, Address: 0x102c4b8 */
    if (!limmoveflag) goto label1; /* Line 958, Address: 0x102c4e0 */
    sv_move_sub2(); /* Line 959, Address: 0x102c4f0 */
    return; /* Line 960, Address: 0x102c4f8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 965, Address: 0x102c500 */
    sv_move_main(ywk); /* Line 966, Address: 0x102c52c */
    return; /* Line 967, Address: 0x102c538 */
  } else if (!limmoveflag) goto label1; /* Line 968, Address: 0x102c540 */
  sv_move_sub2(); /* Line 969, Address: 0x102c550 */
  return; /* Line 970, Address: 0x102c558 */



label1:
  scra_vz = 0; /* Line 975, Address: 0x102c560 */
} /* Line 976, Address: 0x102c568 */













static void sv_move_main(short yPos) { /* Line 990, Address: 0x102c580 */
  short spdwk;

  if (scra_vline == 96) { /* Line 993, Address: 0x102c590 */
    if (actwk[0].mspeed.w < 0) { /* Line 994, Address: 0x102c5ac */
      spdwk = -actwk[0].mspeed.w; /* Line 995, Address: 0x102c5c4 */
    } else { /* Line 996, Address: 0x102c5e8 */
      spdwk = actwk[0].mspeed.w; /* Line 997, Address: 0x102c5f0 */
    }


    if (spdwk >= 2048) { /* Line 1001, Address: 0x102c600 */
      sv_move_main2(yPos); /* Line 1002, Address: 0x102c614 */
    } /* Line 1003, Address: 0x102c620 */
    else {

      if (yPos > 6) { /* Line 1006, Address: 0x102c628 */
        sv_move_plus(1536); /* Line 1007, Address: 0x102c640 */
      } else if (yPos < -6) { /* Line 1008, Address: 0x102c64c */
        sv_move_minus(1536); /* Line 1009, Address: 0x102c66c */
      } /* Line 1010, Address: 0x102c678 */
      else sv_move_sub(yPos); /* Line 1011, Address: 0x102c680 */
    }
  } /* Line 1013, Address: 0x102c68c */
  else {
    if (yPos > 2) { /* Line 1015, Address: 0x102c694 */
      sv_move_plus(512); /* Line 1016, Address: 0x102c6ac */
    } else if (yPos < -2) { /* Line 1017, Address: 0x102c6b8 */
      sv_move_minus(512); /* Line 1018, Address: 0x102c6d8 */
    } /* Line 1019, Address: 0x102c6e4 */
    else sv_move_sub(yPos); /* Line 1020, Address: 0x102c6ec */
  }

} /* Line 1023, Address: 0x102c6f8 */













static void sv_move_main2(short yPos) { /* Line 1037, Address: 0x102c710 */
  short spdwk;

  spdwk = 4096; /* Line 1040, Address: 0x102c720 */

  if (yPos > 16) { /* Line 1042, Address: 0x102c72c */
    sv_move_plus(spdwk); /* Line 1043, Address: 0x102c744 */
  } else if (yPos < -16) { /* Line 1044, Address: 0x102c750 */
    sv_move_minus(spdwk); /* Line 1045, Address: 0x102c770 */
  } else { /* Line 1046, Address: 0x102c77c */
    sv_move_sub(yPos); /* Line 1047, Address: 0x102c784 */
  }
} /* Line 1049, Address: 0x102c790 */














static void sv_move_sub(short yPos) { /* Line 1064, Address: 0x102c7b0 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1067, Address: 0x102c7bc */
  if (yPos < 0) { /* Line 1068, Address: 0x102c7e8 */
    scrv_up_ch(lSpd); /* Line 1069, Address: 0x102c7fc */
  } else { /* Line 1070, Address: 0x102c808 */
    scrv_down_ch(lSpd); /* Line 1071, Address: 0x102c810 */
  }
} /* Line 1073, Address: 0x102c81c */



static void sv_move_sub2() { /* Line 1077, Address: 0x102c830 */
  limmoveflag = 0; /* Line 1078, Address: 0x102c838 */

  sv_move_sub(0); /* Line 1080, Address: 0x102c840 */
} /* Line 1081, Address: 0x102c84c */













static void sv_move_minus(short speed) { /* Line 1095, Address: 0x102c860 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1098, Address: 0x102c86c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1099, Address: 0x102c890 */
  scrv_up_ch(lSpd); /* Line 1100, Address: 0x102c8b4 */
} /* Line 1101, Address: 0x102c8c0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1116, Address: 0x102c8d0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1117, Address: 0x102c8dc */
    if (lSpd.w.l > -256) { /* Line 1118, Address: 0x102c904 */

      lSpd.w.l = scralim_up; /* Line 1120, Address: 0x102c91c */
    } else { /* Line 1121, Address: 0x102c928 */
      lSpd.w.l &= 2047; /* Line 1122, Address: 0x102c930 */
      actwk[0].yposi.w.l &= 2047; /* Line 1123, Address: 0x102c93c */
      scra_v_posit.w.h &= 2047; /* Line 1124, Address: 0x102c950 */
      scrb_v_posit.w.h &= 1023; /* Line 1125, Address: 0x102c964 */
    }
  }

  scrv_move(lSpd); /* Line 1129, Address: 0x102c978 */
} /* Line 1130, Address: 0x102c984 */













static void sv_move_plus(short sSpd) { /* Line 1144, Address: 0x102c9a0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1147, Address: 0x102c9ac */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1148, Address: 0x102c9cc */
  scrv_down_ch(lSpd); /* Line 1149, Address: 0x102c9f0 */
} /* Line 1150, Address: 0x102c9fc */














static void scrv_down_ch(int_union lSpd) { /* Line 1165, Address: 0x102ca10 */
  if (lSpd.w.l >= scralim_down) { /* Line 1166, Address: 0x102ca1c */
    if (lSpd.w.l < 2048) { /* Line 1167, Address: 0x102ca44 */

      lSpd.w.l = scralim_down; /* Line 1169, Address: 0x102ca5c */
    } else { /* Line 1170, Address: 0x102ca68 */
      lSpd.w.l -= 2048; /* Line 1171, Address: 0x102ca70 */
      actwk[0].yposi.w.l &= 2047; /* Line 1172, Address: 0x102ca7c */
      scra_v_posit.w.h -= 2048; /* Line 1173, Address: 0x102ca90 */
      scrb_v_posit.w.h &= 1023; /* Line 1174, Address: 0x102caa4 */
    }
  }

  scrv_move(lSpd); /* Line 1178, Address: 0x102cab8 */
} /* Line 1179, Address: 0x102cac4 */
















static void scrv_move(int_union lSpd) { /* Line 1196, Address: 0x102cae0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1200, Address: 0x102caf0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1201, Address: 0x102cb00 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1202, Address: 0x102cb24 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1203, Address: 0x102cb38 */
  scra_vz = spdwk.w.l; /* Line 1204, Address: 0x102cb50 */

  scra_v_posit.l = lSpd.l; /* Line 1206, Address: 0x102cb5c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1208, Address: 0x102cb68 */
  if (!ywk) { /* Line 1209, Address: 0x102cba4 */
    scra_v_count ^= 16; /* Line 1210, Address: 0x102cbac */
    ywk = scra_v_posit.w.h - ysv; /* Line 1211, Address: 0x102cbc0 */
    if (ywk < 0) { /* Line 1212, Address: 0x102cbec */
      scrflaga.b.h |= 1; /* Line 1213, Address: 0x102cbfc */
    } else { /* Line 1214, Address: 0x102cc10 */
      scrflaga.b.h |= 2; /* Line 1215, Address: 0x102cc18 */
    }
  }


} /* Line 1220, Address: 0x102cc2c */

















void scrollwrt() { /* Line 1238, Address: 0x102cc40 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1247, Address: 0x102cc60 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1248, Address: 0x102cc64 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1249, Address: 0x102cc70 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1250, Address: 0x102cc7c */
  pScrFlag = &scrflagbw.b.h; /* Line 1251, Address: 0x102cc84 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1252, Address: 0x102cc8c */

  VramBase = 16384; /* Line 1254, Address: 0x102cca0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1255, Address: 0x102cca4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1256, Address: 0x102ccb0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1257, Address: 0x102ccbc */
  pScrFlag = &scrflagaw.b.h; /* Line 1258, Address: 0x102ccc4 */

  if (*pScrFlag) { /* Line 1260, Address: 0x102cccc */
    if (*pScrFlag & 1) { /* Line 1261, Address: 0x102ccd8 */
      *pScrFlag &= 254; /* Line 1262, Address: 0x102ccec */

      lD4.l = -16; /* Line 1264, Address: 0x102ccf8 */
      wD5 = 65520; /* Line 1265, Address: 0x102cd00 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1267, Address: 0x102cd08 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1269, Address: 0x102cd28 */
    }




    if (*pScrFlag & 2) { /* Line 1275, Address: 0x102cd54 */
      *pScrFlag &= 253; /* Line 1276, Address: 0x102cd68 */

      lD4.l = 224; /* Line 1278, Address: 0x102cd74 */
      wD5 = 65520; /* Line 1279, Address: 0x102cd7c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1280, Address: 0x102cd84 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1282, Address: 0x102cda4 */
    }




    if (*pScrFlag & 4) { /* Line 1288, Address: 0x102cdd0 */
      *pScrFlag &= 251; /* Line 1289, Address: 0x102cde4 */

      lD4.l = -16; /* Line 1291, Address: 0x102cdf0 */
      wD5 = 65520; /* Line 1292, Address: 0x102cdf8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1293, Address: 0x102ce00 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1295, Address: 0x102ce20 */
    }




    if (*pScrFlag & 8) { /* Line 1301, Address: 0x102ce4c */
      *pScrFlag &= 247; /* Line 1302, Address: 0x102ce60 */

      lD4.l = -16; /* Line 1304, Address: 0x102ce6c */
      wD5 = 320; /* Line 1305, Address: 0x102ce74 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1306, Address: 0x102ce7c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1308, Address: 0x102ce9c */
    }
  }






} /* Line 1317, Address: 0x102cec8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1334, Address: 0x102cef0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1345, Address: 0x102cf1c */

  if (*pScrFlag & 1) { /* Line 1347, Address: 0x102cf24 */
    *pScrFlag &= 254; /* Line 1348, Address: 0x102cf3c */
  } /* Line 1349, Address: 0x102cf50 */
  else {
    *pScrFlag &= 254; /* Line 1351, Address: 0x102cf58 */

    if (*pScrFlag & 2) { /* Line 1353, Address: 0x102cf6c */
      *pScrFlag &= 253; /* Line 1354, Address: 0x102cf84 */
      lD4.w.l = 224; /* Line 1355, Address: 0x102cf98 */
    } /* Line 1356, Address: 0x102cfa0 */
    else {
      *pScrFlag &= 253; /* Line 1358, Address: 0x102cfa8 */
      goto label1; /* Line 1359, Address: 0x102cfbc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1364, Address: 0x102cfc4 */
  wD0 &= 127; /* Line 1365, Address: 0x102d014 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1366, Address: 0x102d01c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1372, Address: 0x102d03c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1373, Address: 0x102d05c */
  if (wD0 != 0) { /* Line 1374, Address: 0x102d080 */
    wD5 = 65520; /* Line 1375, Address: 0x102d08c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1376, Address: 0x102d094 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1378, Address: 0x102d0b4 */



  } /* Line 1382, Address: 0x102d0e0 */
  else {

    wD5 = 0; /* Line 1385, Address: 0x102d0e8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1386, Address: 0x102d0ec */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1390, Address: 0x102d10c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1397, Address: 0x102d138 */






    lD4.l = -16; /* Line 1404, Address: 0x102d14c */
    wD5 = 65520; /* Line 1405, Address: 0x102d154 */
    if (*pScrFlag & 168) { /* Line 1406, Address: 0x102d15c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1407, Address: 0x102d174 */
      wD5 = 320; /* Line 1408, Address: 0x102d194 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1412, Address: 0x102d19c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1414, Address: 0x102d1cc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1415, Address: 0x102d1d8 */



    for (i = 0; i < 16; ++i) { /* Line 1419, Address: 0x102d1e8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1420, Address: 0x102d1f4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1421, Address: 0x102d214 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1422, Address: 0x102d24c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1423, Address: 0x102d26c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1425, Address: 0x102d290 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1428, Address: 0x102d2b4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1430, Address: 0x102d2d4 */
      }
      lD4.w.l += 16; /* Line 1432, Address: 0x102d2e8 */
    } /* Line 1433, Address: 0x102d2f4 */
    *pScrFlag = 0; /* Line 1434, Address: 0x102d304 */
  }
} /* Line 1436, Address: 0x102d30c */





void scrollwrtc() {} /* Line 1442, Address: 0x102d340 */




void scrollwrtz() {} /* Line 1447, Address: 0x102d350 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1465, Address: 0x102d360 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1478, Address: 0x102d388 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1481, Address: 0x102d3a8 */
    pTilePoint->x += 2; /* Line 1482, Address: 0x102d3bc */
    if (pTilePoint->x >= 64) { /* Line 1483, Address: 0x102d3d0 */
      pTilePoint->x -= 64; /* Line 1484, Address: 0x102d3e4 */
    }
    xOffs += 16; /* Line 1486, Address: 0x102d3f8 */
  } while (--lpcnt >= 0); /* Line 1487, Address: 0x102d404 */
} /* Line 1488, Address: 0x102d418 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1492, Address: 0x102d430 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1496, Address: 0x102d458 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1499, Address: 0x102d478 */
    pTilePoint->x += 2; /* Line 1500, Address: 0x102d48c */
    if (pTilePoint->x >= 64) { /* Line 1501, Address: 0x102d4a0 */
      pTilePoint->x -= 64; /* Line 1502, Address: 0x102d4b4 */
    }
    xOffs += 16; /* Line 1504, Address: 0x102d4c8 */
  } while (--lpcnt >= 0); /* Line 1505, Address: 0x102d4d4 */
} /* Line 1506, Address: 0x102d4e8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1526, Address: 0x102d500 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1530, Address: 0x102d528 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1533, Address: 0x102d548 */
    pTilePoint->y += 2; /* Line 1534, Address: 0x102d55c */
    if (pTilePoint->y >= 32) { /* Line 1535, Address: 0x102d56c */
      pTilePoint->y -= 32; /* Line 1536, Address: 0x102d580 */
    }
    yOffs += 16; /* Line 1538, Address: 0x102d590 */
  } while (--lpcnt >= 0); /* Line 1539, Address: 0x102d59c */
} /* Line 1540, Address: 0x102d5b0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1559, Address: 0x102d5c0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1565, Address: 0x102d5f4 */

    base = 1; /* Line 1567, Address: 0x102d604 */
  } /* Line 1568, Address: 0x102d608 */
  else if (VramBase == 16384) { /* Line 1569, Address: 0x102d610 */

    base = 0; /* Line 1571, Address: 0x102d620 */
  }
  x = pTilePoint->x; /* Line 1573, Address: 0x102d624 */
  y = pTilePoint->y; /* Line 1574, Address: 0x102d62c */


  frip = BlkIndex & 6144; /* Line 1577, Address: 0x102d634 */
  BlkIndex &= 1023; /* Line 1578, Address: 0x102d63c */
  if (frip == 6144) { /* Line 1579, Address: 0x102d648 */

    p0 = 3, p1 = 2; /* Line 1581, Address: 0x102d654 */
    p2 = 1, p3 = 0; /* Line 1582, Address: 0x102d65c */
  } /* Line 1583, Address: 0x102d664 */
  else if (frip & 4096) { /* Line 1584, Address: 0x102d66c */

    p0 = 2, p1 = 3; /* Line 1586, Address: 0x102d678 */
    p2 = 0, p3 = 1; /* Line 1587, Address: 0x102d680 */
  } /* Line 1588, Address: 0x102d688 */
  else if (frip & 2048) { /* Line 1589, Address: 0x102d690 */

    p0 = 1, p1 = 0; /* Line 1591, Address: 0x102d69c */
    p2 = 3, p3 = 2; /* Line 1592, Address: 0x102d6a4 */
  } /* Line 1593, Address: 0x102d6ac */
  else {

    p0 = 0, p1 = 1; /* Line 1596, Address: 0x102d6b4 */
    p2 = 2, p3 = 3; /* Line 1597, Address: 0x102d6bc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1600, Address: 0x102d6c4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1601, Address: 0x102d708 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1602, Address: 0x102d74c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1603, Address: 0x102d790 */

} /* Line 1605, Address: 0x102d7d4 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1622, Address: 0x102d810 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1623, Address: 0x102d830 */
} /* Line 1624, Address: 0x102d850 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1626, Address: 0x102d860 */
  wH_posiw = 0; /* Line 1627, Address: 0x102d880 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1628, Address: 0x102d884 */
} /* Line 1629, Address: 0x102d8a4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1636, Address: 0x102d8c0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1642, Address: 0x102d8f0 */
  yOffs += wV_posiw; /* Line 1643, Address: 0x102d900 */





  if ((short)xOffs < 0) /* Line 1649, Address: 0x102d910 */
    xOffs = 0; /* Line 1650, Address: 0x102d92c */
  if ((short)yOffs < 0) /* Line 1651, Address: 0x102d930 */
    yOffs = 0; /* Line 1652, Address: 0x102d94c */
  if ((short)xOffs >= 16384) /* Line 1653, Address: 0x102d950 */
    xOffs = 16383; /* Line 1654, Address: 0x102d970 */
  if ((short)yOffs >= 2048) /* Line 1655, Address: 0x102d978 */
    yOffs = 2047; /* Line 1656, Address: 0x102d998 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1657, Address: 0x102d9a0 */
  if (i < 0) i = 0; /* Line 1658, Address: 0x102d9e8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1660, Address: 0x102d9f4 */

  if (ScreenNo) { /* Line 1662, Address: 0x102da10 */




    xOffs &= 32767; /* Line 1667, Address: 0x102da18 */
    yOffs &= 32767; /* Line 1668, Address: 0x102da24 */


    xBlk = xOffs; /* Line 1671, Address: 0x102da30 */
    xBlk %= 256; /* Line 1672, Address: 0x102da38 */
    xBlk /= 16; /* Line 1673, Address: 0x102da58 */
    yBlk = yOffs; /* Line 1674, Address: 0x102da74 */
    yBlk %= 256; /* Line 1675, Address: 0x102da7c */
    yBlk /= 16; /* Line 1676, Address: 0x102da9c */

    lpw = pmapwk; /* Line 1678, Address: 0x102dab8 */
    lpw += xBlk; /* Line 1679, Address: 0x102dac0 */
    lpw += yBlk * 16; /* Line 1680, Address: 0x102dac8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1681, Address: 0x102dad4 */
    *pIndex = *lpw; /* Line 1682, Address: 0x102daec */

    return 1; /* Line 1684, Address: 0x102dafc */
  }

  *pIndex = 0; /* Line 1687, Address: 0x102db08 */
  return 0; /* Line 1688, Address: 0x102db10 */
} /* Line 1689, Address: 0x102db14 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1709, Address: 0x102db40 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1717, Address: 0x102db68 */
  if (ScreenNo) { /* Line 1718, Address: 0x102dbcc */





    xBlk = xOffs; /* Line 1724, Address: 0x102dbd4 */
    xBlk %= 256; /* Line 1725, Address: 0x102dbdc */
    xBlk /= 16; /* Line 1726, Address: 0x102dbfc */
    yBlk = yOffs; /* Line 1727, Address: 0x102dc18 */
    yBlk %= 256; /* Line 1728, Address: 0x102dc20 */
    yBlk /= 16; /* Line 1729, Address: 0x102dc40 */


    lpw = pmapwk; /* Line 1732, Address: 0x102dc5c */
    lpw += xBlk; /* Line 1733, Address: 0x102dc64 */
    lpw += yBlk * 16; /* Line 1734, Address: 0x102dc6c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1735, Address: 0x102dc78 */
    *ppBlockNo = lpw; /* Line 1736, Address: 0x102dc90 */
    *pIndex = *lpw; /* Line 1737, Address: 0x102dc98 */




    return 1; /* Line 1742, Address: 0x102dca8 */
  }

  *pIndex = 0; /* Line 1745, Address: 0x102dcb4 */
  return 0; /* Line 1746, Address: 0x102dcbc */
} /* Line 1747, Address: 0x102dcc0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1761, Address: 0x102dce0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1768, Address: 0x102dcfc */
  pMapWk = (unsigned char*)mapwka; /* Line 1769, Address: 0x102dd00 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1770, Address: 0x102dd08 */
    *pBlockIndex = BlockNo; /* Line 1771, Address: 0x102dd2c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1772, Address: 0x102dd38 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1773, Address: 0x102dd50 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1774, Address: 0x102dd64 */
    }
  }


} /* Line 1779, Address: 0x102dd7c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1793, Address: 0x102dda0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1794, Address: 0x102ddac */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1795, Address: 0x102ddd8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1796, Address: 0x102de24 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1797, Address: 0x102de50 */

          return 0; /* Line 1799, Address: 0x102de9c */
        }
      }
    }
  }

  return 1; /* Line 1805, Address: 0x102dea8 */
} /* Line 1806, Address: 0x102deac */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1823, Address: 0x102dec0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1824, Address: 0x102dedc */

} /* Line 1826, Address: 0x102def8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1828, Address: 0x102df10 */
  wH_posiw = 0; /* Line 1829, Address: 0x102df2c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1830, Address: 0x102df30 */

} /* Line 1832, Address: 0x102df4c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1834, Address: 0x102df60 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1835, Address: 0x102df74 */

} /* Line 1837, Address: 0x102df90 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1839, Address: 0x102dfa0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1840, Address: 0x102dfbc */

} /* Line 1842, Address: 0x102dfd8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1844, Address: 0x102dff0 */
  xOffs += wH_posiw; /* Line 1845, Address: 0x102e008 */
  yOffs += wV_posiw; /* Line 1846, Address: 0x102e018 */
  yOffs &= 240; /* Line 1847, Address: 0x102e028 */
  xOffs &= 496; /* Line 1848, Address: 0x102e034 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1850, Address: 0x102e040 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1851, Address: 0x102e06c */


} /* Line 1854, Address: 0x102e098 */















void mapwrt() { /* Line 1870, Address: 0x102e0b0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1877, Address: 0x102e0c8 */
  wV_posiw = scra_v_posit.w.h; /* Line 1878, Address: 0x102e0d4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1879, Address: 0x102e0e0 */
  VramBase = 16384; /* Line 1880, Address: 0x102e0e8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1881, Address: 0x102e0ec */



  pMapWk = (unsigned char*)mapwkb; /* Line 1885, Address: 0x102e104 */
  VramBase = 24576; /* Line 1886, Address: 0x102e10c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1887, Address: 0x102e110 */

} /* Line 1889, Address: 0x102e120 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1892, Address: 0x102e140 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1893, Address: 0x102e158 */
} /* Line 1894, Address: 0x102e178 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1899, Address: 0x102e190 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1903, Address: 0x102e1b0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1906, Address: 0x102e1cc */



    wD4 += 16; /* Line 1910, Address: 0x102e1f4 */
  } while ((short)--wD6 >= 0); /* Line 1911, Address: 0x102e200 */

} /* Line 1913, Address: 0x102e228 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1919, Address: 0x102e240 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1922, Address: 0x102e25c */
  wD6 = 15; /* Line 1923, Address: 0x102e264 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1926, Address: 0x102e26c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1928, Address: 0x102e290 */
    wD4 += 16; /* Line 1929, Address: 0x102e2b0 */
  } while ((short)--wD6 >= 0); /* Line 1930, Address: 0x102e2b8 */
} /* Line 1931, Address: 0x102e2dc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1957, Address: 0x102e300 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1962, Address: 0x102e328 */
  wD0 = pWrttbl[wD0]; /* Line 1963, Address: 0x102e338 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1965, Address: 0x102e354 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1966, Address: 0x102e378 */
  if (wD0) { /* Line 1967, Address: 0x102e3a0 */
    wD5 = 65520; /* Line 1968, Address: 0x102e3ac */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1969, Address: 0x102e3b4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1972, Address: 0x102e3d0 */



  } /* Line 1976, Address: 0x102e3f8 */
  else {

    wD5 = 0; /* Line 1979, Address: 0x102e400 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1980, Address: 0x102e404 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1984, Address: 0x102e420 */
  }





} /* Line 1991, Address: 0x102e448 */










void mapinit() { /* Line 2002, Address: 0x102e470 */

  colorset2(mapinittbl.colorno2); /* Line 2004, Address: 0x102e478 */
  colorset(mapinittbl.colorno2); /* Line 2005, Address: 0x102e48c */


  if (play_start & 2) divdevset(); /* Line 2008, Address: 0x102e4a0 */
} /* Line 2009, Address: 0x102e4c0 */




void mapset() {} /* Line 2014, Address: 0x102e4d0 */



void divdevset() {} /* Line 2018, Address: 0x102e4e0 */



void enecginit() {} /* Line 2022, Address: 0x102e4f0 */
