#include "..\EQU.H"
#include "SCR81A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL8C.H"
#include "SCRCHK8.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void z81aline(short** ppHscw);
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
extern map_init_data mapinittbl;









































































sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 146, Address: 0x1027f40 */
    return &actwk[0]; /* Line 147, Address: 0x1027f54 */
  else
    return &actwk[1]; /* Line 149, Address: 0x1027f64 */

} /* Line 151, Address: 0x1027f6c */





































void scr_set(void) { /* Line 189, Address: 0x1027f80 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x1027f8c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x1027fa0 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x1027fb4 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x1027fbc */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x1027fc4 */
  ++pScrTbl; /* Line 198, Address: 0x1027fd0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x1027fd4 */
  ++pScrTbl; /* Line 200, Address: 0x1027fe8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x1027fec */
  ++pScrTbl; /* Line 202, Address: 0x1028000 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x1028004 */
  ++pScrTbl; /* Line 204, Address: 0x1028018 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x102801c */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x1028030 */
  ++pScrTbl; /* Line 207, Address: 0x1028050 */
  scra_h_count = 16; /* Line 208, Address: 0x1028054 */
  scra_v_count = 16; /* Line 209, Address: 0x1028060 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102806c */
  scra_hline = 160; /* Line 212, Address: 0x1028078 */

  playposiset(); /* Line 214, Address: 0x1028084 */
} /* Line 215, Address: 0x102808c */
















































static void playposiset(void) { /* Line 264, Address: 0x10280a0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x10280b4 */
    playload(); /* Line 268, Address: 0x10280c4 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x10280cc */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x10280dc */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x10280f4 */
    } else { /* Line 273, Address: 0x1028104 */
      ywk = 0; /* Line 274, Address: 0x102810c */
    }
  } /* Line 276, Address: 0x1028110 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x1028118 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x1028138 */
    } /* Line 280, Address: 0x102815c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x1028164 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x1028184 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x1028198 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x10281ac */
    xwk -= 160; /* Line 292, Address: 0x10281c0 */
  } else { /* Line 293, Address: 0x10281cc */
    xwk = 0; /* Line 294, Address: 0x10281d4 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x10281d8 */
    xwk = scralim_right; /* Line 299, Address: 0x10281fc */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x102820c */

  if (ywk > 96) { /* Line 305, Address: 0x1028214 */
    ywk -= 96; /* Line 306, Address: 0x1028228 */
  } else { /* Line 307, Address: 0x1028234 */
    ywk = 0; /* Line 308, Address: 0x102823c */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x1028240 */
    ywk = scralim_down; /* Line 313, Address: 0x1028264 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x1028274 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102827c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102828c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102829c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x10282ac */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x10282bc */
} /* Line 326, Address: 0x10282cc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x10282f0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x10282fc */
  lYwk.w.l = 0; /* Line 351, Address: 0x1028304 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x1028308 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x1028314 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x1028320 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102832c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x1028338 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x1028354 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x1028360 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102837c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x1028388 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x10283a4 */
} /* Line 366, Address: 0x10283c8 */















void scroll(void) { /* Line 382, Address: 0x10283e0 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x10283fc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x102840c */

  scrchk(); /* Line 401, Address: 0x1028438 */

  scroll_h(); /* Line 403, Address: 0x1028440 */
  scroll_v(); /* Line 404, Address: 0x1028448 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x1028450 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x1028460 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x1028470 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x1028484 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x1028494 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x10284a8 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x10284b8 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x10284d4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x10284e4 */


  scrollb_v(lYwk); /* Line 422, Address: 0x10284f8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x1028508 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x1028530 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x1028568 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102857c */

  z81aline(&psHscw); /* Line 431, Address: 0x1028588 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 433, Address: 0x1028594 */
  for (i = 0; i < 16; ++i) { /* Line 434, Address: 0x10285b4 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x10285c0 */
  } /* Line 437, Address: 0x10285d4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x10285e4 */
  for (i = 0; i < 28; ++i) { /* Line 440, Address: 0x1028604 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x1028610 */
  } /* Line 443, Address: 0x1028624 */

  z81aline(&psHscw); /* Line 445, Address: 0x1028634 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 447, Address: 0x1028640 */
  for (i = 0; i < 12; ++i) { /* Line 448, Address: 0x1028660 */

    *psHscw++ = ldwk.w.l; /* Line 450, Address: 0x102866c */
  } /* Line 451, Address: 0x1028680 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 453, Address: 0x1028690 */
  for (i = 0; i < 12; ++i) { /* Line 454, Address: 0x10286b0 */

    *psHscw++ = ldwk.w.l; /* Line 456, Address: 0x10286bc */
  } /* Line 457, Address: 0x10286d0 */

  pHscrbuf = lphscrollbuff; /* Line 459, Address: 0x10286e0 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 460, Address: 0x10286ec */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 461, Address: 0x102871c */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 462, Address: 0x102874c */
} /* Line 463, Address: 0x1028768 */













static void z81aline(short** ppHscw) { /* Line 477, Address: 0x1028790 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z81ascrtbl[5] = {
    3, 4, 2, 0, 0
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 486, Address: 0x10287a8 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 487, Address: 0x10287cc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 488, Address: 0x10287ec */
  ldwk.w.l = scrz_h_posit.w.h; /* Line 489, Address: 0x102880c */
  *ppHscw += 14; /* Line 490, Address: 0x1028818 */

  for (i = 4; i >= 0; --i) { /* Line 492, Address: 0x102882c */

    wk = -ldwk.w.l; /* Line 494, Address: 0x1028838 */

    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 496, Address: 0x1028858 */

      --*ppHscw; /* Line 498, Address: 0x1028878 */
      **ppHscw = wk; /* Line 499, Address: 0x102888c */
    } /* Line 500, Address: 0x1028898 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 502, Address: 0x10288a4 */
    ldwk.l += lXwk; /* Line 503, Address: 0x10288c8 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 504, Address: 0x10288d4 */
  } /* Line 505, Address: 0x10288f8 */

  *ppHscw += 14; /* Line 507, Address: 0x1028904 */
} /* Line 508, Address: 0x1028918 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 529, Address: 0x1028940 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 533, Address: 0x102895c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 534, Address: 0x1028960 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 536, Address: 0x1028980 */
    ldwk.w.l = *pHscrwk; /* Line 537, Address: 0x102899c */
    ++pHscrwk; /* Line 538, Address: 0x10289a8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 540, Address: 0x10289b4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 541, Address: 0x10289bc */
    } /* Line 542, Address: 0x10289cc */
  } /* Line 543, Address: 0x10289f0 */
} /* Line 544, Address: 0x1028a10 */









































































































static void scrollb_v(short yPos) { /* Line 650, Address: 0x1028a30 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 653, Address: 0x1028a40 */
  scrb_v_posit.w.h = yPos; /* Line 654, Address: 0x1028a50 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 655, Address: 0x1028a5c */

  if (!ywk) { /* Line 657, Address: 0x1028a94 */
    scrb_v_count ^= 16; /* Line 658, Address: 0x1028a9c */
    if (yPos - ysv < 0) { /* Line 659, Address: 0x1028ab0 */
      scrflagb.b.h |= 1; /* Line 660, Address: 0x1028ad0 */
    } /* Line 661, Address: 0x1028ae4 */
    else {
      scrflagb.b.h |= 2; /* Line 663, Address: 0x1028aec */
    }
  }


} /* Line 668, Address: 0x1028b00 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 686, Address: 0x1028b20 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 690, Address: 0x1028b34 */
  lXwk = lXsv + xoffs; /* Line 691, Address: 0x1028b3c */
  scrb_h_posit.l = lXwk; /* Line 692, Address: 0x1028b44 */
  ldXwk.l = lXwk; /* Line 693, Address: 0x1028b4c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 694, Address: 0x1028b50 */
  ldXwk.w.l &= 16; /* Line 695, Address: 0x1028b74 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 696, Address: 0x1028b80 */

  if (!ldXwk.b.b4) { /* Line 698, Address: 0x1028b9c */
    scrb_h_count ^= 16; /* Line 699, Address: 0x1028ba8 */
    if (lXwk - lXsv < 0) { /* Line 700, Address: 0x1028bbc */
      scrflagb.b.h |= 1 << flgbit; /* Line 701, Address: 0x1028bc8 */
    } /* Line 702, Address: 0x1028bec */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 704, Address: 0x1028bf4 */
    }
  }


} /* Line 709, Address: 0x1028c1c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 727, Address: 0x1028c30 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 731, Address: 0x1028c44 */
  lXwk = lXsv + xoffs; /* Line 732, Address: 0x1028c4c */
  scrc_h_posit.l = lXwk; /* Line 733, Address: 0x1028c54 */
  ldXwk.l = lXwk; /* Line 734, Address: 0x1028c5c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 735, Address: 0x1028c60 */
  ldXwk.w.l &= 16; /* Line 736, Address: 0x1028c84 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 737, Address: 0x1028c90 */

  if (!ldXwk.b.b4) { /* Line 739, Address: 0x1028cac */
    scrc_h_count ^= 16; /* Line 740, Address: 0x1028cb8 */
    if (lXwk - lXsv < 0) { /* Line 741, Address: 0x1028ccc */
      scrflagc.b.h |= 1 << flgbit; /* Line 742, Address: 0x1028cd8 */
    } /* Line 743, Address: 0x1028cfc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 745, Address: 0x1028d04 */
    }
  }


} /* Line 750, Address: 0x1028d2c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 768, Address: 0x1028d40 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 772, Address: 0x1028d54 */
  lXwk = lXsv + xoffs; /* Line 773, Address: 0x1028d5c */
  scrz_h_posit.l = lXwk; /* Line 774, Address: 0x1028d64 */
  ldXwk.l = lXwk; /* Line 775, Address: 0x1028d6c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 776, Address: 0x1028d70 */
  ldXwk.w.l &= 16; /* Line 777, Address: 0x1028d94 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 778, Address: 0x1028da0 */

  if (!ldXwk.b.b4) { /* Line 780, Address: 0x1028dbc */
    scrz_h_count ^= 16; /* Line 781, Address: 0x1028dc8 */
    if (lXwk - lXsv < 0) { /* Line 782, Address: 0x1028ddc */
      scrflagz.b.h |= 1 << flgbit; /* Line 783, Address: 0x1028de8 */
    } /* Line 784, Address: 0x1028e0c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 786, Address: 0x1028e14 */
    }
  }


} /* Line 791, Address: 0x1028e3c */














static void scroll_h(void) { /* Line 806, Address: 0x1028e50 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 810, Address: 0x1028e60 */

  scrh_move(); /* Line 812, Address: 0x1028e70 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 813, Address: 0x1028e78 */
  if (!bXwk) { /* Line 814, Address: 0x1028eac */
    scra_h_count ^= 16; /* Line 815, Address: 0x1028eb4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 816, Address: 0x1028ec8 */
      scrflaga.b.h |= 4; /* Line 817, Address: 0x1028eec */
    } else { /* Line 818, Address: 0x1028f00 */
      scrflaga.b.h |= 8; /* Line 819, Address: 0x1028f08 */
    }
  }


} /* Line 824, Address: 0x1028f1c */
















static void scrh_move(void) { /* Line 841, Address: 0x1028f40 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 844, Address: 0x1028f48 */
  if (xwk == 0) { /* Line 845, Address: 0x1028f90 */

    scra_hz = 0; /* Line 847, Address: 0x1028fa0 */
    return; /* Line 848, Address: 0x1028fa8 */
  } else if (xwk < 0) { /* Line 849, Address: 0x1028fb0 */

    if (xwk < -16) { /* Line 851, Address: 0x1028fc0 */
      xwk = -16; /* Line 852, Address: 0x1028fd4 */
    }


    xwk += scra_h_posit.w.h; /* Line 856, Address: 0x1028fe0 */
    if (xwk < scralim_left) { /* Line 857, Address: 0x1028ff4 */
      xwk = scralim_left; /* Line 858, Address: 0x1029018 */
    }
  } /* Line 860, Address: 0x1029028 */
  else {
    if (xwk > 16) { /* Line 862, Address: 0x1029030 */
      xwk = 16; /* Line 863, Address: 0x1029044 */
    }


    xwk += scra_h_posit.w.h; /* Line 867, Address: 0x1029050 */
    if (xwk > scralim_right) { /* Line 868, Address: 0x1029064 */
      xwk = scralim_right; /* Line 869, Address: 0x1029088 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 874, Address: 0x1029098 */
  scra_h_posit.w.h = xwk; /* Line 875, Address: 0x10290c8 */
} /* Line 876, Address: 0x10290d0 */














static void scroll_v(void) { /* Line 891, Address: 0x10290e0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 894, Address: 0x10290ec */
  if (actwk[0].cddat & 4) { /* Line 895, Address: 0x1029120 */
    ywk -= 5; /* Line 896, Address: 0x1029138 */
  }


  if (actwk[0].cddat & 2) { /* Line 900, Address: 0x1029144 */
    ywk += 32; /* Line 901, Address: 0x102915c */
    if (ywk < scra_vline) { /* Line 902, Address: 0x1029168 */
      ywk -= scra_vline; /* Line 903, Address: 0x102918c */
      sv_move_main2(ywk); /* Line 904, Address: 0x10291a0 */
      return; /* Line 905, Address: 0x10291ac */
    } else if (ywk >= scra_vline + 64) { /* Line 906, Address: 0x10291b4 */
      ywk -= scra_vline + 64; /* Line 907, Address: 0x10291dc */
      sv_move_main2(ywk); /* Line 908, Address: 0x1029204 */
      return; /* Line 909, Address: 0x1029210 */
    }
    ywk -= scra_vline + 64; /* Line 911, Address: 0x1029218 */
    if (!limmoveflag) goto label1; /* Line 912, Address: 0x1029240 */
    sv_move_sub2(); /* Line 913, Address: 0x1029250 */
    return; /* Line 914, Address: 0x1029258 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 919, Address: 0x1029260 */
    sv_move_main(ywk); /* Line 920, Address: 0x102928c */
    return; /* Line 921, Address: 0x1029298 */
  } else if (!limmoveflag) goto label1; /* Line 922, Address: 0x10292a0 */
  sv_move_sub2(); /* Line 923, Address: 0x10292b0 */
  return; /* Line 924, Address: 0x10292b8 */



label1:
  scra_vz = 0; /* Line 929, Address: 0x10292c0 */
} /* Line 930, Address: 0x10292c8 */













static void sv_move_main(short yPos) { /* Line 944, Address: 0x10292e0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 947, Address: 0x10292f0 */
    if (actwk[0].mspeed.w < 0) { /* Line 948, Address: 0x102930c */
      spdwk = -actwk[0].mspeed.w; /* Line 949, Address: 0x1029324 */
    } else { /* Line 950, Address: 0x1029348 */
      spdwk = actwk[0].mspeed.w; /* Line 951, Address: 0x1029350 */
    }


    if (spdwk >= 2048) { /* Line 955, Address: 0x1029360 */
      sv_move_main2(yPos); /* Line 956, Address: 0x1029374 */
    } /* Line 957, Address: 0x1029380 */
    else {

      if (yPos > 6) { /* Line 960, Address: 0x1029388 */
        sv_move_plus(1536); /* Line 961, Address: 0x10293a0 */
      } else if (yPos < -6) { /* Line 962, Address: 0x10293ac */
        sv_move_minus(1536); /* Line 963, Address: 0x10293cc */
      } /* Line 964, Address: 0x10293d8 */
      else sv_move_sub(yPos); /* Line 965, Address: 0x10293e0 */
    }
  } /* Line 967, Address: 0x10293ec */
  else {
    if (yPos > 2) { /* Line 969, Address: 0x10293f4 */
      sv_move_plus(512); /* Line 970, Address: 0x102940c */
    } else if (yPos < -2) { /* Line 971, Address: 0x1029418 */
      sv_move_minus(512); /* Line 972, Address: 0x1029438 */
    } /* Line 973, Address: 0x1029444 */
    else sv_move_sub(yPos); /* Line 974, Address: 0x102944c */
  }

} /* Line 977, Address: 0x1029458 */













static void sv_move_main2(short yPos) { /* Line 991, Address: 0x1029470 */
  short spdwk;

  spdwk = 4096; /* Line 994, Address: 0x1029480 */

  if (yPos > 16) { /* Line 996, Address: 0x102948c */
    sv_move_plus(spdwk); /* Line 997, Address: 0x10294a4 */
  } else if (yPos < -16) { /* Line 998, Address: 0x10294b0 */
    sv_move_minus(spdwk); /* Line 999, Address: 0x10294d0 */
  } else { /* Line 1000, Address: 0x10294dc */
    sv_move_sub(yPos); /* Line 1001, Address: 0x10294e4 */
  }
} /* Line 1003, Address: 0x10294f0 */














static void sv_move_sub(short yPos) { /* Line 1018, Address: 0x1029510 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1021, Address: 0x102951c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1022, Address: 0x1029520 */
  if (yPos < 0) { /* Line 1023, Address: 0x102954c */
    scrv_up_ch(lSpd); /* Line 1024, Address: 0x1029560 */
  } else { /* Line 1025, Address: 0x102956c */
    scrv_down_ch(lSpd); /* Line 1026, Address: 0x1029574 */
  }
} /* Line 1028, Address: 0x1029580 */



static void sv_move_sub2(void) { /* Line 1032, Address: 0x1029590 */
  limmoveflag = 0; /* Line 1033, Address: 0x1029598 */

  sv_move_sub(0); /* Line 1035, Address: 0x10295a0 */
} /* Line 1036, Address: 0x10295ac */













static void sv_move_minus(short speed) { /* Line 1050, Address: 0x10295c0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1053, Address: 0x10295cc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1054, Address: 0x10295f0 */
  scrv_up_ch(lSpd); /* Line 1055, Address: 0x1029614 */
} /* Line 1056, Address: 0x1029620 */














static void scrv_up_ch(int_union lSpd) { /* Line 1071, Address: 0x1029630 */
  if (lSpd.w.l <= scralim_up) { /* Line 1072, Address: 0x102963c */
    if (lSpd.w.l > -256) { /* Line 1073, Address: 0x1029664 */

      lSpd.w.l = scralim_up; /* Line 1075, Address: 0x102967c */
    } else { /* Line 1076, Address: 0x1029688 */
      lSpd.w.l &= 2047; /* Line 1077, Address: 0x1029690 */
      actwk[0].yposi.w.h &= 2047; /* Line 1078, Address: 0x102969c */
      scra_v_posit.w.h &= 2047; /* Line 1079, Address: 0x10296b0 */
      scrb_v_posit.w.h &= 1023; /* Line 1080, Address: 0x10296c4 */
    }
  }

  scrv_move(lSpd); /* Line 1084, Address: 0x10296d8 */
} /* Line 1085, Address: 0x10296e4 */













static void sv_move_plus(short sSpd) { /* Line 1099, Address: 0x1029700 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1102, Address: 0x102970c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1103, Address: 0x102972c */
  scrv_down_ch(lSpd); /* Line 1104, Address: 0x1029750 */
} /* Line 1105, Address: 0x102975c */














static void scrv_down_ch(int_union lSpd) { /* Line 1120, Address: 0x1029770 */
  if (lSpd.w.l >= scralim_down) { /* Line 1121, Address: 0x102977c */
    if (lSpd.w.l < 2048) { /* Line 1122, Address: 0x10297a4 */

      lSpd.w.l = scralim_down; /* Line 1124, Address: 0x10297bc */
    } else { /* Line 1125, Address: 0x10297c8 */
      lSpd.w.l -= 2048; /* Line 1126, Address: 0x10297d0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1127, Address: 0x10297dc */
      scra_v_posit.w.h -= 2048; /* Line 1128, Address: 0x10297f0 */
      scrb_v_posit.w.h &= 1023; /* Line 1129, Address: 0x1029804 */
    }
  }

  scrv_move(lSpd); /* Line 1133, Address: 0x1029818 */
} /* Line 1134, Address: 0x1029824 */
















static void scrv_move(int_union lSpd) { /* Line 1151, Address: 0x1029840 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1155, Address: 0x1029850 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1156, Address: 0x1029860 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1157, Address: 0x1029884 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1158, Address: 0x1029898 */
  scra_vz = spdwk.w.l; /* Line 1159, Address: 0x10298b0 */

  scra_v_posit.l = lSpd.l; /* Line 1161, Address: 0x10298bc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1163, Address: 0x10298c8 */
  if (!ywk) { /* Line 1164, Address: 0x1029904 */
    scra_v_count ^= 16; /* Line 1165, Address: 0x102990c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1166, Address: 0x1029920 */
    if (ywk < 0) { /* Line 1167, Address: 0x102994c */
      scrflaga.b.h |= 1; /* Line 1168, Address: 0x102995c */
    } else { /* Line 1169, Address: 0x1029970 */
      scrflaga.b.h |= 2; /* Line 1170, Address: 0x1029978 */
    }
  }


} /* Line 1175, Address: 0x102998c */

















void scrollwrt(void) { /* Line 1193, Address: 0x10299a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1202, Address: 0x10299c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1203, Address: 0x10299c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1204, Address: 0x10299d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1205, Address: 0x10299dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1206, Address: 0x10299e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1207, Address: 0x10299ec */

  VramBase = 16384; /* Line 1209, Address: 0x1029a00 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1210, Address: 0x1029a04 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1211, Address: 0x1029a10 */
  pMapWk = (unsigned char*)mapwka; /* Line 1212, Address: 0x1029a1c */
  pScrFlag = &scrflagaw.b.h; /* Line 1213, Address: 0x1029a24 */

  if (*pScrFlag) { /* Line 1215, Address: 0x1029a2c */
    if (*pScrFlag & 1) { /* Line 1216, Address: 0x1029a38 */
      *pScrFlag &= 254; /* Line 1217, Address: 0x1029a4c */

      lD4.l = -16; /* Line 1219, Address: 0x1029a58 */
      wD5 = 65520; /* Line 1220, Address: 0x1029a60 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1222, Address: 0x1029a68 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1224, Address: 0x1029a88 */
    }




    if (*pScrFlag & 2) { /* Line 1230, Address: 0x1029ab4 */
      *pScrFlag &= 253; /* Line 1231, Address: 0x1029ac8 */

      lD4.l = 224; /* Line 1233, Address: 0x1029ad4 */
      wD5 = 65520; /* Line 1234, Address: 0x1029adc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1235, Address: 0x1029ae4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1237, Address: 0x1029b04 */
    }




    if (*pScrFlag & 4) { /* Line 1243, Address: 0x1029b30 */
      *pScrFlag &= 251; /* Line 1244, Address: 0x1029b44 */

      lD4.l = -16; /* Line 1246, Address: 0x1029b50 */
      wD5 = 65520; /* Line 1247, Address: 0x1029b58 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1248, Address: 0x1029b60 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1250, Address: 0x1029b80 */
    }




    if (*pScrFlag & 8) { /* Line 1256, Address: 0x1029bac */
      *pScrFlag &= 247; /* Line 1257, Address: 0x1029bc0 */

      lD4.l = -16; /* Line 1259, Address: 0x1029bcc */
      wD5 = 320; /* Line 1260, Address: 0x1029bd4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1261, Address: 0x1029bdc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1263, Address: 0x1029bfc */
    }
  }






} /* Line 1272, Address: 0x1029c28 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1289, Address: 0x1029c50 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1300, Address: 0x1029c7c */

  if (*pScrFlag & 1) { /* Line 1302, Address: 0x1029c84 */
    *pScrFlag &= 254; /* Line 1303, Address: 0x1029c9c */
  } /* Line 1304, Address: 0x1029cb0 */
  else {
    *pScrFlag &= 254; /* Line 1306, Address: 0x1029cb8 */

    if (*pScrFlag & 2) { /* Line 1308, Address: 0x1029ccc */
      *pScrFlag &= 253; /* Line 1309, Address: 0x1029ce4 */
      lD4.w.l = 224; /* Line 1310, Address: 0x1029cf8 */
    } /* Line 1311, Address: 0x1029d00 */
    else {
      *pScrFlag &= 253; /* Line 1313, Address: 0x1029d08 */
      goto label1; /* Line 1314, Address: 0x1029d1c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1319, Address: 0x1029d24 */
  wD0 &= 127; /* Line 1320, Address: 0x1029d74 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1321, Address: 0x1029d7c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1327, Address: 0x1029d9c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1328, Address: 0x1029dbc */
  if (wD0 != 0) { /* Line 1329, Address: 0x1029de0 */
    wD5 = 65520; /* Line 1330, Address: 0x1029dec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x1029df4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1333, Address: 0x1029e14 */



  } /* Line 1337, Address: 0x1029e40 */
  else {

    wD5 = 0; /* Line 1340, Address: 0x1029e48 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1341, Address: 0x1029e4c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1345, Address: 0x1029e6c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1352, Address: 0x1029e98 */






    lD4.l = -16; /* Line 1359, Address: 0x1029eac */
    wD5 = 65520; /* Line 1360, Address: 0x1029eb4 */
    if (*pScrFlag & 168) { /* Line 1361, Address: 0x1029ebc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1362, Address: 0x1029ed4 */
      wD5 = 320; /* Line 1363, Address: 0x1029ef4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1367, Address: 0x1029efc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1369, Address: 0x1029f2c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1370, Address: 0x1029f38 */



    for (i = 0; i < 16; ++i) { /* Line 1374, Address: 0x1029f48 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1375, Address: 0x1029f54 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1376, Address: 0x1029f74 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1377, Address: 0x1029fac */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1378, Address: 0x1029fcc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1380, Address: 0x1029ff0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1383, Address: 0x102a014 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1385, Address: 0x102a034 */
      }
      lD4.w.l += 16; /* Line 1387, Address: 0x102a048 */
    } /* Line 1388, Address: 0x102a054 */
    *pScrFlag = 0; /* Line 1389, Address: 0x102a064 */
  }
} /* Line 1391, Address: 0x102a06c */





void scrollwrtc(void) {} /* Line 1397, Address: 0x102a0a0 */




void scrollwrtz(void) {} /* Line 1402, Address: 0x102a0b0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1420, Address: 0x102a0c0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1433, Address: 0x102a0e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1436, Address: 0x102a108 */
    pTilePoint->x += 2; /* Line 1437, Address: 0x102a11c */
    if (pTilePoint->x >= 64) { /* Line 1438, Address: 0x102a130 */
      pTilePoint->x -= 64; /* Line 1439, Address: 0x102a144 */
    }
    xOffs += 16; /* Line 1441, Address: 0x102a158 */
  } while (--lpcnt >= 0); /* Line 1442, Address: 0x102a164 */
} /* Line 1443, Address: 0x102a178 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1447, Address: 0x102a190 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1451, Address: 0x102a1b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1454, Address: 0x102a1d8 */
    pTilePoint->x += 2; /* Line 1455, Address: 0x102a1ec */
    if (pTilePoint->x >= 64) { /* Line 1456, Address: 0x102a200 */
      pTilePoint->x -= 64; /* Line 1457, Address: 0x102a214 */
    }
    xOffs += 16; /* Line 1459, Address: 0x102a228 */
  } while (--lpcnt >= 0); /* Line 1460, Address: 0x102a234 */
} /* Line 1461, Address: 0x102a248 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1481, Address: 0x102a260 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1485, Address: 0x102a288 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1488, Address: 0x102a2a8 */
    pTilePoint->y += 2; /* Line 1489, Address: 0x102a2bc */
    if (pTilePoint->y >= 32) { /* Line 1490, Address: 0x102a2cc */
      pTilePoint->y -= 32; /* Line 1491, Address: 0x102a2e0 */
    }
    yOffs += 16; /* Line 1493, Address: 0x102a2f0 */
  } while (--lpcnt >= 0); /* Line 1494, Address: 0x102a2fc */
} /* Line 1495, Address: 0x102a310 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1514, Address: 0x102a320 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1520, Address: 0x102a354 */

    base = 1; /* Line 1522, Address: 0x102a364 */
  } /* Line 1523, Address: 0x102a368 */
  else if (VramBase == 16384) { /* Line 1524, Address: 0x102a370 */

    base = 0; /* Line 1526, Address: 0x102a380 */
  }
  x = pTilePoint->x; /* Line 1528, Address: 0x102a384 */
  y = pTilePoint->y; /* Line 1529, Address: 0x102a38c */


  frip = BlkIndex & 6144; /* Line 1532, Address: 0x102a394 */
  BlkIndex &= 1023; /* Line 1533, Address: 0x102a39c */
  if (frip == 6144) { /* Line 1534, Address: 0x102a3a8 */

    p0 = 3, p1 = 2; /* Line 1536, Address: 0x102a3b4 */
    p2 = 1, p3 = 0; /* Line 1537, Address: 0x102a3bc */
  } /* Line 1538, Address: 0x102a3c4 */
  else if (frip & 4096) { /* Line 1539, Address: 0x102a3cc */

    p0 = 2, p1 = 3; /* Line 1541, Address: 0x102a3d8 */
    p2 = 0, p3 = 1; /* Line 1542, Address: 0x102a3e0 */
  } /* Line 1543, Address: 0x102a3e8 */
  else if (frip & 2048) { /* Line 1544, Address: 0x102a3f0 */

    p0 = 1, p1 = 0; /* Line 1546, Address: 0x102a3fc */
    p2 = 3, p3 = 2; /* Line 1547, Address: 0x102a404 */
  } /* Line 1548, Address: 0x102a40c */
  else {

    p0 = 0, p1 = 1; /* Line 1551, Address: 0x102a414 */
    p2 = 2, p3 = 3; /* Line 1552, Address: 0x102a41c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1555, Address: 0x102a424 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1556, Address: 0x102a468 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1557, Address: 0x102a4ac */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1558, Address: 0x102a4f0 */

} /* Line 1560, Address: 0x102a534 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1578, Address: 0x102a570 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1579, Address: 0x102a590 */
} /* Line 1580, Address: 0x102a5b0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1582, Address: 0x102a5c0 */
  wH_posiw = 0; /* Line 1583, Address: 0x102a5e0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1584, Address: 0x102a5e4 */
} /* Line 1585, Address: 0x102a604 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1592, Address: 0x102a620 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1598, Address: 0x102a650 */
  yOffs += wV_posiw; /* Line 1599, Address: 0x102a660 */





  if ((short)xOffs < 0) /* Line 1605, Address: 0x102a670 */
    xOffs = 0; /* Line 1606, Address: 0x102a68c */
  if ((short)yOffs < 0) /* Line 1607, Address: 0x102a690 */
    yOffs = 0; /* Line 1608, Address: 0x102a6ac */
  if ((short)xOffs >= 16384) /* Line 1609, Address: 0x102a6b0 */
    xOffs = 16383; /* Line 1610, Address: 0x102a6d0 */
  if ((short)yOffs >= 2048) /* Line 1611, Address: 0x102a6d8 */
    yOffs = 2047; /* Line 1612, Address: 0x102a6f8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1613, Address: 0x102a700 */
  if (i < 0) i = 0; /* Line 1614, Address: 0x102a748 */

  ScreenNo = pMapWk[i] & 127; /* Line 1616, Address: 0x102a754 */

  if (ScreenNo) { /* Line 1618, Address: 0x102a770 */




    xOffs &= 32767; /* Line 1623, Address: 0x102a778 */
    yOffs &= 32767; /* Line 1624, Address: 0x102a784 */


    xBlk = xOffs; /* Line 1627, Address: 0x102a790 */
    xBlk %= 256; /* Line 1628, Address: 0x102a798 */
    xBlk /= 16; /* Line 1629, Address: 0x102a7b8 */
    yBlk = yOffs; /* Line 1630, Address: 0x102a7d4 */
    yBlk %= 256; /* Line 1631, Address: 0x102a7dc */
    yBlk /= 16; /* Line 1632, Address: 0x102a7fc */

    lpw = pmapwk; /* Line 1634, Address: 0x102a818 */
    lpw += xBlk; /* Line 1635, Address: 0x102a820 */
    lpw += yBlk * 16; /* Line 1636, Address: 0x102a828 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1637, Address: 0x102a834 */
    *pIndex = *lpw; /* Line 1638, Address: 0x102a84c */

    return 1; /* Line 1640, Address: 0x102a85c */
  }

  *pIndex = 0; /* Line 1643, Address: 0x102a868 */
  return 0; /* Line 1644, Address: 0x102a870 */
} /* Line 1645, Address: 0x102a874 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1665, Address: 0x102a8a0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1673, Address: 0x102a8c8 */
  if (ScreenNo) { /* Line 1674, Address: 0x102a92c */





    xBlk = xOffs; /* Line 1680, Address: 0x102a934 */
    xBlk %= 256; /* Line 1681, Address: 0x102a93c */
    xBlk /= 16; /* Line 1682, Address: 0x102a95c */
    yBlk = yOffs; /* Line 1683, Address: 0x102a978 */
    yBlk %= 256; /* Line 1684, Address: 0x102a980 */
    yBlk /= 16; /* Line 1685, Address: 0x102a9a0 */


    lpw = pmapwk; /* Line 1688, Address: 0x102a9bc */
    lpw += xBlk; /* Line 1689, Address: 0x102a9c4 */
    lpw += yBlk * 16; /* Line 1690, Address: 0x102a9cc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1691, Address: 0x102a9d8 */
    *ppBlockNo = lpw; /* Line 1692, Address: 0x102a9f0 */
    *pIndex = *lpw; /* Line 1693, Address: 0x102a9f8 */




    return 1; /* Line 1698, Address: 0x102aa08 */
  }

  *pIndex = 0; /* Line 1701, Address: 0x102aa14 */
  return 0; /* Line 1702, Address: 0x102aa1c */
} /* Line 1703, Address: 0x102aa20 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1717, Address: 0x102aa40 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1724, Address: 0x102aa5c */
  pMapWk = (unsigned char*)mapwka; /* Line 1725, Address: 0x102aa60 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1726, Address: 0x102aa68 */
    *pBlockIndex = BlockNo; /* Line 1727, Address: 0x102aa8c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1728, Address: 0x102aa98 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1729, Address: 0x102aab0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1730, Address: 0x102aac4 */
    }
  }


} /* Line 1735, Address: 0x102aadc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1749, Address: 0x102ab00 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1750, Address: 0x102ab0c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1751, Address: 0x102ab38 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1752, Address: 0x102ab84 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1753, Address: 0x102abb0 */

          return 0; /* Line 1755, Address: 0x102abfc */
        }
      }
    }
  }

  return 1; /* Line 1761, Address: 0x102ac08 */
} /* Line 1762, Address: 0x102ac0c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102ac20 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x102ac3c */

} /* Line 1782, Address: 0x102ac58 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x102ac70 */
  wH_posiw = 0; /* Line 1785, Address: 0x102ac8c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1786, Address: 0x102ac90 */

} /* Line 1788, Address: 0x102acac */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1790, Address: 0x102acc0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1791, Address: 0x102acd4 */

} /* Line 1793, Address: 0x102acf0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1795, Address: 0x102ad00 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1796, Address: 0x102ad1c */

} /* Line 1798, Address: 0x102ad38 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1800, Address: 0x102ad50 */
  xOffs += wH_posiw; /* Line 1801, Address: 0x102ad68 */
  yOffs += wV_posiw; /* Line 1802, Address: 0x102ad78 */
  yOffs &= 240; /* Line 1803, Address: 0x102ad88 */
  xOffs &= 496; /* Line 1804, Address: 0x102ad94 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1806, Address: 0x102ada0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1807, Address: 0x102adcc */


} /* Line 1810, Address: 0x102adf8 */















void mapwrt(void) { /* Line 1826, Address: 0x102ae10 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1833, Address: 0x102ae28 */
  wV_posiw = scra_v_posit.w.h; /* Line 1834, Address: 0x102ae34 */
  pMapWk = (unsigned char*)mapwka; /* Line 1835, Address: 0x102ae40 */
  VramBase = 16384; /* Line 1836, Address: 0x102ae48 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1837, Address: 0x102ae4c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1841, Address: 0x102ae64 */
  VramBase = 24576; /* Line 1842, Address: 0x102ae6c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1843, Address: 0x102ae70 */

} /* Line 1845, Address: 0x102ae80 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1848, Address: 0x102aea0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1849, Address: 0x102aeb8 */
} /* Line 1850, Address: 0x102aed8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1855, Address: 0x102aef0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1859, Address: 0x102af10 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1862, Address: 0x102af2c */



    wD4 += 16; /* Line 1866, Address: 0x102af54 */
  } while ((short)--wD6 >= 0); /* Line 1867, Address: 0x102af60 */

} /* Line 1869, Address: 0x102af88 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1875, Address: 0x102afa0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1878, Address: 0x102afbc */
  wD6 = 15; /* Line 1879, Address: 0x102afc4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1882, Address: 0x102afcc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1884, Address: 0x102aff0 */
    wD4 += 16; /* Line 1885, Address: 0x102b010 */
  } while ((short)--wD6 >= 0); /* Line 1886, Address: 0x102b018 */
} /* Line 1887, Address: 0x102b03c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1913, Address: 0x102b060 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1918, Address: 0x102b088 */
  wD0 = pWrttbl[wD0]; /* Line 1919, Address: 0x102b098 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1921, Address: 0x102b0b4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1922, Address: 0x102b0d8 */
  if (wD0) { /* Line 1923, Address: 0x102b100 */
    wD5 = 65520; /* Line 1924, Address: 0x102b10c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1925, Address: 0x102b114 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1928, Address: 0x102b130 */



  } /* Line 1932, Address: 0x102b158 */
  else {

    wD5 = 0; /* Line 1935, Address: 0x102b160 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1936, Address: 0x102b164 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1940, Address: 0x102b180 */
  }





} /* Line 1947, Address: 0x102b1a8 */










void mapinit(void) { /* Line 1958, Address: 0x102b1d0 */

  colorset2(mapinittbl.colorno2); /* Line 1960, Address: 0x102b1d8 */
  colorset(mapinittbl.colorno2); /* Line 1961, Address: 0x102b1ec */

  if (plflag) enecginit(); /* Line 1963, Address: 0x102b200 */
  if (play_start & 2) divdevset(); /* Line 1964, Address: 0x102b218 */
} /* Line 1965, Address: 0x102b238 */




void mapset(void) {} /* Line 1970, Address: 0x102b250 */



void divdevset() {} /* Line 1974, Address: 0x102b260 */



void enecginit(void) {} /* Line 1978, Address: 0x102b270 */
