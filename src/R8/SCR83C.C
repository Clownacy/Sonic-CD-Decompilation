#include "..\EQU.H"
#include "SCR81A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL8C.H"
#include "SCRCHK8.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void z82bline0(short** ppHscw);
static void z82bline1(short** ppHscw);
static void line_div(int hWk1, int* hWk2, short sD6);
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

static unsigned char z81awrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0
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
short playpositbl[1][2] = { { 48, 588 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;









































































sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 147, Address: 0x101d850 */
    return &actwk[0]; /* Line 148, Address: 0x101d864 */
  else
    return &actwk[1]; /* Line 150, Address: 0x101d874 */

} /* Line 152, Address: 0x101d87c */





































void scr_set(void) { /* Line 190, Address: 0x101d890 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x101d89c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x101d8b0 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x101d8c4 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x101d8cc */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x101d8d4 */
  ++pScrTbl; /* Line 199, Address: 0x101d8e0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x101d8e4 */
  ++pScrTbl; /* Line 201, Address: 0x101d8f8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x101d8fc */
  ++pScrTbl; /* Line 203, Address: 0x101d910 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x101d914 */
  ++pScrTbl; /* Line 205, Address: 0x101d928 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x101d92c */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x101d940 */
  ++pScrTbl; /* Line 208, Address: 0x101d960 */
  scra_h_count = 16; /* Line 209, Address: 0x101d964 */
  scra_v_count = 16; /* Line 210, Address: 0x101d970 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x101d97c */
  scra_hline = 160; /* Line 213, Address: 0x101d988 */

  playposiset(); /* Line 215, Address: 0x101d994 */
} /* Line 216, Address: 0x101d99c */
















































static void playposiset(void) { /* Line 265, Address: 0x101d9b0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 268, Address: 0x101d9c4 */
    playload(); /* Line 269, Address: 0x101d9d4 */
    xwk = actwk[0].xposi.w.h; /* Line 270, Address: 0x101d9dc */

    if (actwk[0].yposi.w.h > 0) { /* Line 272, Address: 0x101d9ec */
      ywk = actwk[0].yposi.w.h; /* Line 273, Address: 0x101da04 */
    } else { /* Line 274, Address: 0x101da14 */
      ywk = 0; /* Line 275, Address: 0x101da1c */
    }
  } /* Line 277, Address: 0x101da20 */
  else {
    if (demoflag.w & -32768) { /* Line 279, Address: 0x101da28 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 280, Address: 0x101da48 */
    } /* Line 281, Address: 0x101da6c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 283, Address: 0x101da74 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 287, Address: 0x101da94 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 288, Address: 0x101daa8 */
  }


  if (xwk > 160) { /* Line 292, Address: 0x101dabc */
    xwk -= 160; /* Line 293, Address: 0x101dad0 */
  } else { /* Line 294, Address: 0x101dadc */
    xwk = 0; /* Line 295, Address: 0x101dae4 */
  }


  if (xwk > scralim_right) { /* Line 299, Address: 0x101dae8 */
    xwk = scralim_right; /* Line 300, Address: 0x101db0c */
  }


  scra_h_posit.w.h = xwk; /* Line 304, Address: 0x101db1c */

  if (ywk > 96) { /* Line 306, Address: 0x101db24 */
    ywk -= 96; /* Line 307, Address: 0x101db38 */
  } else { /* Line 308, Address: 0x101db44 */
    ywk = 0; /* Line 309, Address: 0x101db4c */
  }


  if (ywk > scralim_down) { /* Line 313, Address: 0x101db50 */
    ywk = scralim_down; /* Line 314, Address: 0x101db74 */
  }


  scra_v_posit.w.h = ywk; /* Line 318, Address: 0x101db84 */

  scrbinit(xwk, ywk); /* Line 320, Address: 0x101db8c */


  loopmapno = playmapnotbl[0]; /* Line 323, Address: 0x101db9c */
  loopmapno2 = playmapnotbl[1]; /* Line 324, Address: 0x101dbac */
  ballmapno = playmapnotbl[2]; /* Line 325, Address: 0x101dbbc */
  ballmapno2 = playmapnotbl[3]; /* Line 326, Address: 0x101dbcc */
} /* Line 327, Address: 0x101dbdc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 348, Address: 0x101dc00 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 351, Address: 0x101dc0c */
  lYwk.w.l = 0; /* Line 352, Address: 0x101dc14 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 354, Address: 0x101dc18 */
  scrb_v_posit.l = lYwk.l; /* Line 355, Address: 0x101dc24 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x101dc30 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 357, Address: 0x101dc3c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 359, Address: 0x101dc48 */
  scrc_h_posit.w.h = sXpos; /* Line 360, Address: 0x101dc64 */

  scrz_h_posit.w.h = sXpos + 112; /* Line 362, Address: 0x101dc70 */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x101dc90 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x101dcac */
} /* Line 366, Address: 0x101dcd0 */















void scroll(void) { /* Line 382, Address: 0x101dce0 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x101dcfc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x101dd0c */

  scrchk(); /* Line 401, Address: 0x101dd38 */

  scroll_h(); /* Line 403, Address: 0x101dd40 */
  scroll_v(); /* Line 404, Address: 0x101dd48 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x101dd50 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x101dd60 */


  lXwk = scra_hz << 7; /* Line 410, Address: 0x101dd70 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x101dd84 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x101dd94 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x101dda8 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x101ddb8 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x101ddd4 */

  lYwk = (unsigned int)scra_v_posit.l >> 3; /* Line 419, Address: 0x101dde4 */
  lYwk = (unsigned int)lYwk >> 16 & 65535 | lYwk << 16 & -65536; /* Line 420, Address: 0x101ddf0 */


  scrollb_v(lYwk); /* Line 423, Address: 0x101de08 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 425, Address: 0x101de18 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 427, Address: 0x101de40 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 428, Address: 0x101de78 */

  psHscw = hscrollwork; /* Line 430, Address: 0x101de8c */

  z82bline1(&psHscw); /* Line 432, Address: 0x101de98 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 434, Address: 0x101dea4 */
  for (i = 0; i < 18; ++i) { /* Line 435, Address: 0x101dec4 */

    *psHscw++ = ldwk.w.l; /* Line 437, Address: 0x101ded0 */
  } /* Line 438, Address: 0x101dee4 */

  z82bline0(&psHscw); /* Line 440, Address: 0x101def4 */

  pHscrbuf = lphscrollbuff; /* Line 442, Address: 0x101df00 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 443, Address: 0x101df0c */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 444, Address: 0x101df3c */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 445, Address: 0x101df6c */
} /* Line 446, Address: 0x101df88 */













static void z82bline0(short** ppHscw) { /* Line 460, Address: 0x101dfb0 */
  int lWk1, lWk2;
  int_union ldWk1, ldWk2;
  int i, j;
  static char z82bscrtbl0[5] = {
    3, 3, 3, 1, 1
  };

  lWk1 = scrz_h_posit.w.h; /* Line 468, Address: 0x101dfc8 */
  lWk2 = scra_h_posit.w.h; /* Line 469, Address: 0x101dfd8 */
  line_div(lWk1, &lWk2, 5); /* Line 470, Address: 0x101dfec */

  ldWk1.w.h = -scra_h_posit.w.h; /* Line 472, Address: 0x101e000 */
  ldWk2.l = scrz_h_posit.w.h; /* Line 473, Address: 0x101e020 */

  for (i = 4; i >= 0; --i) { /* Line 475, Address: 0x101e034 */

    ldWk1.w.l = -ldWk2.w.l; /* Line 477, Address: 0x101e040 */

    for (j = z82bscrtbl0[i]; j >= 0; --j) { /* Line 479, Address: 0x101e05c */

      **ppHscw = ldWk1.w.l; /* Line 481, Address: 0x101e07c */
      ++*ppHscw; /* Line 482, Address: 0x101e08c */
    } /* Line 483, Address: 0x101e0a0 */

    ldWk2.l = (unsigned int)ldWk2.l >> 16 & 65535 | ldWk2.l << 16 & -65536; /* Line 485, Address: 0x101e0ac */
    ldWk2.l += lWk2; /* Line 486, Address: 0x101e0d0 */
    ldWk2.l = (unsigned int)ldWk2.l >> 16 & 65535 | ldWk2.l << 16 & -65536; /* Line 487, Address: 0x101e0e0 */
  } /* Line 488, Address: 0x101e104 */
} /* Line 489, Address: 0x101e110 */












static void z82bline1(short** ppHscw) { /* Line 502, Address: 0x101e130 */
  int lWk1, lWk2;
  int_union ldWk1, ldWk2;
  int i, j;
  static char z82bscrtbl1[5] = {
    1, 3, 1, 3, 1
  };

  lWk1 = scrb_h_posit.w.h; /* Line 510, Address: 0x101e148 */
  lWk2 = scra_h_posit.w.h; /* Line 511, Address: 0x101e158 */
  line_div(lWk1, &lWk2, 5); /* Line 512, Address: 0x101e16c */

  ldWk1.w.h = -scra_h_posit.w.h; /* Line 514, Address: 0x101e180 */
  ldWk2.l = scrb_h_posit.w.h; /* Line 515, Address: 0x101e1a0 */
  *ppHscw += 14; /* Line 516, Address: 0x101e1b4 */

  for (i = 4; i >= 0; --i) { /* Line 518, Address: 0x101e1c8 */

    ldWk1.w.l = -ldWk2.w.l; /* Line 520, Address: 0x101e1d4 */

    for (j = z82bscrtbl1[i]; j >= 0; --j) { /* Line 522, Address: 0x101e1f0 */

      --*ppHscw; /* Line 524, Address: 0x101e210 */
      **ppHscw = ldWk1.w.l; /* Line 525, Address: 0x101e224 */
    } /* Line 526, Address: 0x101e234 */

    ldWk2.l = (unsigned int)ldWk2.l >> 16 & 65535 | ldWk2.l << 16 & -65536; /* Line 528, Address: 0x101e240 */
    ldWk2.l += lWk2; /* Line 529, Address: 0x101e264 */
    ldWk2.l = (unsigned int)ldWk2.l >> 16 & 65535 | ldWk2.l << 16 & -65536; /* Line 530, Address: 0x101e274 */
  } /* Line 531, Address: 0x101e298 */

  *ppHscw += 14; /* Line 533, Address: 0x101e2a4 */
} /* Line 534, Address: 0x101e2b8 */





static void line_div(int hWk1, int* hWk2, short sD6) { /* Line 540, Address: 0x101e2e0 */
  *hWk2 = (unsigned int)(*hWk2 - hWk1 << 6) / sD6 << 10; /* Line 541, Address: 0x101e2f0 */
} /* Line 542, Address: 0x101e330 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 563, Address: 0x101e340 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 567, Address: 0x101e35c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 568, Address: 0x101e360 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 570, Address: 0x101e380 */
    ldwk.w.l = *pHscrwk; /* Line 571, Address: 0x101e39c */
    ++pHscrwk; /* Line 572, Address: 0x101e3a8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 574, Address: 0x101e3b4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 575, Address: 0x101e3bc */
    } /* Line 576, Address: 0x101e3cc */
  } /* Line 577, Address: 0x101e3f0 */
} /* Line 578, Address: 0x101e410 */









































































































static void scrollb_v(short yPos) { /* Line 684, Address: 0x101e430 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 687, Address: 0x101e440 */
  scrb_v_posit.w.h = yPos; /* Line 688, Address: 0x101e450 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 689, Address: 0x101e45c */

  if (!ywk) { /* Line 691, Address: 0x101e494 */
    scrb_v_count ^= 16; /* Line 692, Address: 0x101e49c */
    if (yPos - ysv < 0) { /* Line 693, Address: 0x101e4b0 */
      scrflagb.b.h |= 1; /* Line 694, Address: 0x101e4d0 */
    } /* Line 695, Address: 0x101e4e4 */
    else {
      scrflagb.b.h |= 2; /* Line 697, Address: 0x101e4ec */
    }
  }


} /* Line 702, Address: 0x101e500 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 720, Address: 0x101e520 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 724, Address: 0x101e534 */
  lXwk = lXsv + xoffs; /* Line 725, Address: 0x101e53c */
  scrb_h_posit.l = lXwk; /* Line 726, Address: 0x101e544 */
  ldXwk.l = lXwk; /* Line 727, Address: 0x101e54c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 728, Address: 0x101e550 */
  ldXwk.w.l &= 16; /* Line 729, Address: 0x101e574 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 730, Address: 0x101e580 */

  if (!ldXwk.b.b4) { /* Line 732, Address: 0x101e59c */
    scrb_h_count ^= 16; /* Line 733, Address: 0x101e5a8 */
    if (lXwk - lXsv < 0) { /* Line 734, Address: 0x101e5bc */
      scrflagb.b.h |= 1 << flgbit; /* Line 735, Address: 0x101e5c8 */
    } /* Line 736, Address: 0x101e5ec */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 738, Address: 0x101e5f4 */
    }
  }


} /* Line 743, Address: 0x101e61c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 761, Address: 0x101e630 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 765, Address: 0x101e644 */
  lXwk = lXsv + xoffs; /* Line 766, Address: 0x101e64c */
  scrc_h_posit.l = lXwk; /* Line 767, Address: 0x101e654 */
  ldXwk.l = lXwk; /* Line 768, Address: 0x101e65c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 769, Address: 0x101e660 */
  ldXwk.w.l &= 16; /* Line 770, Address: 0x101e684 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 771, Address: 0x101e690 */

  if (!ldXwk.b.b4) { /* Line 773, Address: 0x101e6ac */
    scrc_h_count ^= 16; /* Line 774, Address: 0x101e6b8 */
    if (lXwk - lXsv < 0) { /* Line 775, Address: 0x101e6cc */
      scrflagc.b.h |= 1 << flgbit; /* Line 776, Address: 0x101e6d8 */
    } /* Line 777, Address: 0x101e6fc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 779, Address: 0x101e704 */
    }
  }


} /* Line 784, Address: 0x101e72c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 802, Address: 0x101e740 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 806, Address: 0x101e754 */
  lXwk = lXsv + xoffs; /* Line 807, Address: 0x101e75c */
  scrz_h_posit.l = lXwk; /* Line 808, Address: 0x101e764 */
  ldXwk.l = lXwk; /* Line 809, Address: 0x101e76c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 810, Address: 0x101e770 */
  ldXwk.w.l &= 16; /* Line 811, Address: 0x101e794 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 812, Address: 0x101e7a0 */

  if (!ldXwk.b.b4) { /* Line 814, Address: 0x101e7bc */
    scrz_h_count ^= 16; /* Line 815, Address: 0x101e7c8 */
    if (lXwk - lXsv < 0) { /* Line 816, Address: 0x101e7dc */
      scrflagz.b.h |= 1 << flgbit; /* Line 817, Address: 0x101e7e8 */
    } /* Line 818, Address: 0x101e80c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 820, Address: 0x101e814 */
    }
  }


} /* Line 825, Address: 0x101e83c */














static void scroll_h(void) { /* Line 840, Address: 0x101e850 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 844, Address: 0x101e860 */

  scrh_move(); /* Line 846, Address: 0x101e870 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 847, Address: 0x101e878 */
  if (!bXwk) { /* Line 848, Address: 0x101e8ac */
    scra_h_count ^= 16; /* Line 849, Address: 0x101e8b4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 850, Address: 0x101e8c8 */
      scrflaga.b.h |= 4; /* Line 851, Address: 0x101e8ec */
    } else { /* Line 852, Address: 0x101e900 */
      scrflaga.b.h |= 8; /* Line 853, Address: 0x101e908 */
    }
  }


} /* Line 858, Address: 0x101e91c */
















static void scrh_move(void) { /* Line 875, Address: 0x101e940 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 878, Address: 0x101e948 */
  if (xwk == 0) { /* Line 879, Address: 0x101e990 */

    scra_hz = 0; /* Line 881, Address: 0x101e9a0 */
    return; /* Line 882, Address: 0x101e9a8 */
  } else if (xwk < 0) { /* Line 883, Address: 0x101e9b0 */

    if (xwk < -16) { /* Line 885, Address: 0x101e9c0 */
      xwk = -16; /* Line 886, Address: 0x101e9d4 */
    }


    xwk += scra_h_posit.w.h; /* Line 890, Address: 0x101e9e0 */
    if (xwk < scralim_left) { /* Line 891, Address: 0x101e9f4 */
      xwk = scralim_left; /* Line 892, Address: 0x101ea18 */
    }
  } /* Line 894, Address: 0x101ea28 */
  else {
    if (xwk > 16) { /* Line 896, Address: 0x101ea30 */
      xwk = 16; /* Line 897, Address: 0x101ea44 */
    }


    xwk += scra_h_posit.w.h; /* Line 901, Address: 0x101ea50 */
    if (xwk > scralim_right) { /* Line 902, Address: 0x101ea64 */
      xwk = scralim_right; /* Line 903, Address: 0x101ea88 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 908, Address: 0x101ea98 */
  scra_h_posit.w.h = xwk; /* Line 909, Address: 0x101eac8 */
} /* Line 910, Address: 0x101ead0 */














static void scroll_v(void) { /* Line 925, Address: 0x101eae0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 928, Address: 0x101eaec */
  if (actwk[0].cddat & 4) { /* Line 929, Address: 0x101eb20 */
    ywk -= 5; /* Line 930, Address: 0x101eb38 */
  }


  if (actwk[0].cddat & 2) { /* Line 934, Address: 0x101eb44 */
    ywk += 32; /* Line 935, Address: 0x101eb5c */
    if (ywk < scra_vline) { /* Line 936, Address: 0x101eb68 */
      ywk -= scra_vline; /* Line 937, Address: 0x101eb8c */
      sv_move_main2(ywk); /* Line 938, Address: 0x101eba0 */
      return; /* Line 939, Address: 0x101ebac */
    } else if (ywk >= scra_vline + 64) { /* Line 940, Address: 0x101ebb4 */
      ywk -= scra_vline + 64; /* Line 941, Address: 0x101ebdc */
      sv_move_main2(ywk); /* Line 942, Address: 0x101ec04 */
      return; /* Line 943, Address: 0x101ec10 */
    }
    ywk -= scra_vline + 64; /* Line 945, Address: 0x101ec18 */
    if (!limmoveflag) goto label1; /* Line 946, Address: 0x101ec40 */
    sv_move_sub2(); /* Line 947, Address: 0x101ec50 */
    return; /* Line 948, Address: 0x101ec58 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 953, Address: 0x101ec60 */
    sv_move_main(ywk); /* Line 954, Address: 0x101ec8c */
    return; /* Line 955, Address: 0x101ec98 */
  } else if (!limmoveflag) goto label1; /* Line 956, Address: 0x101eca0 */
  sv_move_sub2(); /* Line 957, Address: 0x101ecb0 */
  return; /* Line 958, Address: 0x101ecb8 */



label1:
  scra_vz = 0; /* Line 963, Address: 0x101ecc0 */
} /* Line 964, Address: 0x101ecc8 */













static void sv_move_main(short yPos) { /* Line 978, Address: 0x101ece0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 981, Address: 0x101ecf0 */
    if (actwk[0].mspeed.w < 0) { /* Line 982, Address: 0x101ed0c */
      spdwk = -actwk[0].mspeed.w; /* Line 983, Address: 0x101ed24 */
    } else { /* Line 984, Address: 0x101ed48 */
      spdwk = actwk[0].mspeed.w; /* Line 985, Address: 0x101ed50 */
    }


    if (spdwk >= 2048) { /* Line 989, Address: 0x101ed60 */
      sv_move_main2(yPos); /* Line 990, Address: 0x101ed74 */
    } /* Line 991, Address: 0x101ed80 */
    else {

      if (yPos > 6) { /* Line 994, Address: 0x101ed88 */
        sv_move_plus(1536); /* Line 995, Address: 0x101eda0 */
      } else if (yPos < -6) { /* Line 996, Address: 0x101edac */
        sv_move_minus(1536); /* Line 997, Address: 0x101edcc */
      } /* Line 998, Address: 0x101edd8 */
      else sv_move_sub(yPos); /* Line 999, Address: 0x101ede0 */
    }
  } /* Line 1001, Address: 0x101edec */
  else {
    if (yPos > 2) { /* Line 1003, Address: 0x101edf4 */
      sv_move_plus(512); /* Line 1004, Address: 0x101ee0c */
    } else if (yPos < -2) { /* Line 1005, Address: 0x101ee18 */
      sv_move_minus(512); /* Line 1006, Address: 0x101ee38 */
    } /* Line 1007, Address: 0x101ee44 */
    else sv_move_sub(yPos); /* Line 1008, Address: 0x101ee4c */
  }

} /* Line 1011, Address: 0x101ee58 */













static void sv_move_main2(short yPos) { /* Line 1025, Address: 0x101ee70 */
  short spdwk;

  spdwk = 4096; /* Line 1028, Address: 0x101ee80 */

  if (yPos > 16) { /* Line 1030, Address: 0x101ee8c */
    sv_move_plus(spdwk); /* Line 1031, Address: 0x101eea4 */
  } else if (yPos < -16) { /* Line 1032, Address: 0x101eeb0 */
    sv_move_minus(spdwk); /* Line 1033, Address: 0x101eed0 */
  } else { /* Line 1034, Address: 0x101eedc */
    sv_move_sub(yPos); /* Line 1035, Address: 0x101eee4 */
  }
} /* Line 1037, Address: 0x101eef0 */














static void sv_move_sub(short yPos) { /* Line 1052, Address: 0x101ef10 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1055, Address: 0x101ef1c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1056, Address: 0x101ef20 */
  if (yPos < 0) { /* Line 1057, Address: 0x101ef4c */
    scrv_up_ch(lSpd); /* Line 1058, Address: 0x101ef60 */
  } else { /* Line 1059, Address: 0x101ef6c */
    scrv_down_ch(lSpd); /* Line 1060, Address: 0x101ef74 */
  }
} /* Line 1062, Address: 0x101ef80 */



static void sv_move_sub2(void) { /* Line 1066, Address: 0x101ef90 */
  limmoveflag = 0; /* Line 1067, Address: 0x101ef98 */

  sv_move_sub(0); /* Line 1069, Address: 0x101efa0 */
} /* Line 1070, Address: 0x101efac */













static void sv_move_minus(short speed) { /* Line 1084, Address: 0x101efc0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1087, Address: 0x101efcc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1088, Address: 0x101eff0 */
  scrv_up_ch(lSpd); /* Line 1089, Address: 0x101f014 */
} /* Line 1090, Address: 0x101f020 */














static void scrv_up_ch(int_union lSpd) { /* Line 1105, Address: 0x101f030 */
  if (lSpd.w.l <= scralim_up) { /* Line 1106, Address: 0x101f03c */
    if (lSpd.w.l > -256) { /* Line 1107, Address: 0x101f064 */

      lSpd.w.l = scralim_up; /* Line 1109, Address: 0x101f07c */
    } else { /* Line 1110, Address: 0x101f088 */
      lSpd.w.l &= 2047; /* Line 1111, Address: 0x101f090 */
      actwk[0].yposi.w.h &= 2047; /* Line 1112, Address: 0x101f09c */
      scra_v_posit.w.h &= 2047; /* Line 1113, Address: 0x101f0b0 */
      scrb_v_posit.w.h &= 1023; /* Line 1114, Address: 0x101f0c4 */
    }
  }

  scrv_move(lSpd); /* Line 1118, Address: 0x101f0d8 */
} /* Line 1119, Address: 0x101f0e4 */













static void sv_move_plus(short sSpd) { /* Line 1133, Address: 0x101f100 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1136, Address: 0x101f10c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1137, Address: 0x101f12c */
  scrv_down_ch(lSpd); /* Line 1138, Address: 0x101f150 */
} /* Line 1139, Address: 0x101f15c */














static void scrv_down_ch(int_union lSpd) { /* Line 1154, Address: 0x101f170 */
  if (lSpd.w.l >= scralim_down) { /* Line 1155, Address: 0x101f17c */
    if (lSpd.w.l < 2048) { /* Line 1156, Address: 0x101f1a4 */

      lSpd.w.l = scralim_down; /* Line 1158, Address: 0x101f1bc */
    } else { /* Line 1159, Address: 0x101f1c8 */
      lSpd.w.l -= 2048; /* Line 1160, Address: 0x101f1d0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1161, Address: 0x101f1dc */
      scra_v_posit.w.h -= 2048; /* Line 1162, Address: 0x101f1f0 */
      scrb_v_posit.w.h &= 1023; /* Line 1163, Address: 0x101f204 */
    }
  }

  scrv_move(lSpd); /* Line 1167, Address: 0x101f218 */
} /* Line 1168, Address: 0x101f224 */
















static void scrv_move(int_union lSpd) { /* Line 1185, Address: 0x101f240 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1189, Address: 0x101f250 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1190, Address: 0x101f260 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1191, Address: 0x101f284 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1192, Address: 0x101f298 */
  scra_vz = spdwk.w.l; /* Line 1193, Address: 0x101f2b0 */

  scra_v_posit.l = lSpd.l; /* Line 1195, Address: 0x101f2bc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1197, Address: 0x101f2c8 */
  if (!ywk) { /* Line 1198, Address: 0x101f304 */
    scra_v_count ^= 16; /* Line 1199, Address: 0x101f30c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1200, Address: 0x101f320 */
    if (ywk < 0) { /* Line 1201, Address: 0x101f34c */
      scrflaga.b.h |= 1; /* Line 1202, Address: 0x101f35c */
    } else { /* Line 1203, Address: 0x101f370 */
      scrflaga.b.h |= 2; /* Line 1204, Address: 0x101f378 */
    }
  }


} /* Line 1209, Address: 0x101f38c */

















void scrollwrt(void) { /* Line 1227, Address: 0x101f3a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1236, Address: 0x101f3c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1237, Address: 0x101f3c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1238, Address: 0x101f3d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1239, Address: 0x101f3dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1240, Address: 0x101f3e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1241, Address: 0x101f3ec */

  VramBase = 16384; /* Line 1243, Address: 0x101f400 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1244, Address: 0x101f404 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1245, Address: 0x101f410 */
  pMapWk = (unsigned char*)mapwka; /* Line 1246, Address: 0x101f41c */
  pScrFlag = &scrflagaw.b.h; /* Line 1247, Address: 0x101f424 */

  if (*pScrFlag) { /* Line 1249, Address: 0x101f42c */
    if (*pScrFlag & 1) { /* Line 1250, Address: 0x101f438 */
      *pScrFlag &= 254; /* Line 1251, Address: 0x101f44c */

      lD4.l = -16; /* Line 1253, Address: 0x101f458 */
      wD5 = 65520; /* Line 1254, Address: 0x101f460 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1256, Address: 0x101f468 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1258, Address: 0x101f488 */
    }




    if (*pScrFlag & 2) { /* Line 1264, Address: 0x101f4b4 */
      *pScrFlag &= 253; /* Line 1265, Address: 0x101f4c8 */

      lD4.l = 224; /* Line 1267, Address: 0x101f4d4 */
      wD5 = 65520; /* Line 1268, Address: 0x101f4dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1269, Address: 0x101f4e4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1271, Address: 0x101f504 */
    }




    if (*pScrFlag & 4) { /* Line 1277, Address: 0x101f530 */
      *pScrFlag &= 251; /* Line 1278, Address: 0x101f544 */

      lD4.l = -16; /* Line 1280, Address: 0x101f550 */
      wD5 = 65520; /* Line 1281, Address: 0x101f558 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1282, Address: 0x101f560 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1284, Address: 0x101f580 */
    }




    if (*pScrFlag & 8) { /* Line 1290, Address: 0x101f5ac */
      *pScrFlag &= 247; /* Line 1291, Address: 0x101f5c0 */

      lD4.l = -16; /* Line 1293, Address: 0x101f5cc */
      wD5 = 320; /* Line 1294, Address: 0x101f5d4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1295, Address: 0x101f5dc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1297, Address: 0x101f5fc */
    }
  }






} /* Line 1306, Address: 0x101f628 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1323, Address: 0x101f650 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1334, Address: 0x101f67c */

  if (*pScrFlag & 1) { /* Line 1336, Address: 0x101f684 */
    *pScrFlag &= 254; /* Line 1337, Address: 0x101f69c */
  } /* Line 1338, Address: 0x101f6b0 */
  else {
    *pScrFlag &= 254; /* Line 1340, Address: 0x101f6b8 */

    if (*pScrFlag & 2) { /* Line 1342, Address: 0x101f6cc */
      *pScrFlag &= 253; /* Line 1343, Address: 0x101f6e4 */
      lD4.w.l = 224; /* Line 1344, Address: 0x101f6f8 */
    } /* Line 1345, Address: 0x101f700 */
    else {
      *pScrFlag &= 253; /* Line 1347, Address: 0x101f708 */
      goto label1; /* Line 1348, Address: 0x101f71c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1353, Address: 0x101f724 */
  wD0 &= 127; /* Line 1354, Address: 0x101f774 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1355, Address: 0x101f77c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1361, Address: 0x101f79c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1362, Address: 0x101f7bc */
  if (wD0 != 0) { /* Line 1363, Address: 0x101f7e0 */
    wD5 = 65520; /* Line 1364, Address: 0x101f7ec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1365, Address: 0x101f7f4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1367, Address: 0x101f814 */



  } /* Line 1371, Address: 0x101f840 */
  else {

    wD5 = 0; /* Line 1374, Address: 0x101f848 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1375, Address: 0x101f84c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1379, Address: 0x101f86c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1386, Address: 0x101f898 */






    lD4.l = -16; /* Line 1393, Address: 0x101f8ac */
    wD5 = 65520; /* Line 1394, Address: 0x101f8b4 */
    if (*pScrFlag & 168) { /* Line 1395, Address: 0x101f8bc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1396, Address: 0x101f8d4 */
      wD5 = 320; /* Line 1397, Address: 0x101f8f4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1401, Address: 0x101f8fc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1403, Address: 0x101f92c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1404, Address: 0x101f938 */



    for (i = 0; i < 16; ++i) { /* Line 1408, Address: 0x101f948 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1409, Address: 0x101f954 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1410, Address: 0x101f974 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1411, Address: 0x101f9ac */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1412, Address: 0x101f9cc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1414, Address: 0x101f9f0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1417, Address: 0x101fa14 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1419, Address: 0x101fa34 */
      }
      lD4.w.l += 16; /* Line 1421, Address: 0x101fa48 */
    } /* Line 1422, Address: 0x101fa54 */
    *pScrFlag = 0; /* Line 1423, Address: 0x101fa64 */
  }
} /* Line 1425, Address: 0x101fa6c */





void scrollwrtc(void) {} /* Line 1431, Address: 0x101faa0 */




void scrollwrtz(void) {} /* Line 1436, Address: 0x101fab0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1454, Address: 0x101fac0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1467, Address: 0x101fae8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1470, Address: 0x101fb08 */
    pTilePoint->x += 2; /* Line 1471, Address: 0x101fb1c */
    if (pTilePoint->x >= 64) { /* Line 1472, Address: 0x101fb30 */
      pTilePoint->x -= 64; /* Line 1473, Address: 0x101fb44 */
    }
    xOffs += 16; /* Line 1475, Address: 0x101fb58 */
  } while (--lpcnt >= 0); /* Line 1476, Address: 0x101fb64 */
} /* Line 1477, Address: 0x101fb78 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1481, Address: 0x101fb90 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1485, Address: 0x101fbb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1488, Address: 0x101fbd8 */
    pTilePoint->x += 2; /* Line 1489, Address: 0x101fbec */
    if (pTilePoint->x >= 64) { /* Line 1490, Address: 0x101fc00 */
      pTilePoint->x -= 64; /* Line 1491, Address: 0x101fc14 */
    }
    xOffs += 16; /* Line 1493, Address: 0x101fc28 */
  } while (--lpcnt >= 0); /* Line 1494, Address: 0x101fc34 */
} /* Line 1495, Address: 0x101fc48 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1515, Address: 0x101fc60 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1519, Address: 0x101fc88 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1522, Address: 0x101fca8 */
    pTilePoint->y += 2; /* Line 1523, Address: 0x101fcbc */
    if (pTilePoint->y >= 32) { /* Line 1524, Address: 0x101fccc */
      pTilePoint->y -= 32; /* Line 1525, Address: 0x101fce0 */
    }
    yOffs += 16; /* Line 1527, Address: 0x101fcf0 */
  } while (--lpcnt >= 0); /* Line 1528, Address: 0x101fcfc */
} /* Line 1529, Address: 0x101fd10 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1548, Address: 0x101fd20 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1554, Address: 0x101fd54 */

    base = 1; /* Line 1556, Address: 0x101fd64 */
  } /* Line 1557, Address: 0x101fd68 */
  else if (VramBase == 16384) { /* Line 1558, Address: 0x101fd70 */

    base = 0; /* Line 1560, Address: 0x101fd80 */
  }
  x = pTilePoint->x; /* Line 1562, Address: 0x101fd84 */
  y = pTilePoint->y; /* Line 1563, Address: 0x101fd8c */


  frip = BlkIndex & 6144; /* Line 1566, Address: 0x101fd94 */
  BlkIndex &= 1023; /* Line 1567, Address: 0x101fd9c */
  if (frip == 6144) { /* Line 1568, Address: 0x101fda8 */

    p0 = 3, p1 = 2; /* Line 1570, Address: 0x101fdb4 */
    p2 = 1, p3 = 0; /* Line 1571, Address: 0x101fdbc */
  } /* Line 1572, Address: 0x101fdc4 */
  else if (frip & 4096) { /* Line 1573, Address: 0x101fdcc */

    p0 = 2, p1 = 3; /* Line 1575, Address: 0x101fdd8 */
    p2 = 0, p3 = 1; /* Line 1576, Address: 0x101fde0 */
  } /* Line 1577, Address: 0x101fde8 */
  else if (frip & 2048) { /* Line 1578, Address: 0x101fdf0 */

    p0 = 1, p1 = 0; /* Line 1580, Address: 0x101fdfc */
    p2 = 3, p3 = 2; /* Line 1581, Address: 0x101fe04 */
  } /* Line 1582, Address: 0x101fe0c */
  else {

    p0 = 0, p1 = 1; /* Line 1585, Address: 0x101fe14 */
    p2 = 2, p3 = 3; /* Line 1586, Address: 0x101fe1c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1589, Address: 0x101fe24 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1590, Address: 0x101fe68 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1591, Address: 0x101feac */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1592, Address: 0x101fef0 */

} /* Line 1594, Address: 0x101ff34 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1612, Address: 0x101ff70 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1613, Address: 0x101ff90 */
} /* Line 1614, Address: 0x101ffb0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1616, Address: 0x101ffc0 */
  wH_posiw = 0; /* Line 1617, Address: 0x101ffe0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1618, Address: 0x101ffe4 */
} /* Line 1619, Address: 0x1020004 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1626, Address: 0x1020020 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1632, Address: 0x1020050 */
  yOffs += wV_posiw; /* Line 1633, Address: 0x1020060 */





  if ((short)xOffs < 0) /* Line 1639, Address: 0x1020070 */
    xOffs = 0; /* Line 1640, Address: 0x102008c */
  if ((short)yOffs < 0) /* Line 1641, Address: 0x1020090 */
    yOffs = 0; /* Line 1642, Address: 0x10200ac */
  if ((short)xOffs >= 16384) /* Line 1643, Address: 0x10200b0 */
    xOffs = 16383; /* Line 1644, Address: 0x10200d0 */
  if ((short)yOffs >= 2048) /* Line 1645, Address: 0x10200d8 */
    yOffs = 2047; /* Line 1646, Address: 0x10200f8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1647, Address: 0x1020100 */
  if (i < 0) i = 0; /* Line 1648, Address: 0x1020148 */

  ScreenNo = pMapWk[i] & 127; /* Line 1650, Address: 0x1020154 */

  if (ScreenNo) { /* Line 1652, Address: 0x1020170 */




    xOffs &= 32767; /* Line 1657, Address: 0x1020178 */
    yOffs &= 32767; /* Line 1658, Address: 0x1020184 */


    xBlk = xOffs; /* Line 1661, Address: 0x1020190 */
    xBlk %= 256; /* Line 1662, Address: 0x1020198 */
    xBlk /= 16; /* Line 1663, Address: 0x10201b8 */
    yBlk = yOffs; /* Line 1664, Address: 0x10201d4 */
    yBlk %= 256; /* Line 1665, Address: 0x10201dc */
    yBlk /= 16; /* Line 1666, Address: 0x10201fc */

    lpw = pmapwk; /* Line 1668, Address: 0x1020218 */
    lpw += xBlk; /* Line 1669, Address: 0x1020220 */
    lpw += yBlk * 16; /* Line 1670, Address: 0x1020228 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1671, Address: 0x1020234 */
    *pIndex = *lpw; /* Line 1672, Address: 0x102024c */

    return 1; /* Line 1674, Address: 0x102025c */
  }

  *pIndex = 0; /* Line 1677, Address: 0x1020268 */
  return 0; /* Line 1678, Address: 0x1020270 */
} /* Line 1679, Address: 0x1020274 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1699, Address: 0x10202a0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1707, Address: 0x10202c8 */
  if (ScreenNo) { /* Line 1708, Address: 0x102032c */





    xBlk = xOffs; /* Line 1714, Address: 0x1020334 */
    xBlk %= 256; /* Line 1715, Address: 0x102033c */
    xBlk /= 16; /* Line 1716, Address: 0x102035c */
    yBlk = yOffs; /* Line 1717, Address: 0x1020378 */
    yBlk %= 256; /* Line 1718, Address: 0x1020380 */
    yBlk /= 16; /* Line 1719, Address: 0x10203a0 */


    lpw = pmapwk; /* Line 1722, Address: 0x10203bc */
    lpw += xBlk; /* Line 1723, Address: 0x10203c4 */
    lpw += yBlk * 16; /* Line 1724, Address: 0x10203cc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1725, Address: 0x10203d8 */
    *ppBlockNo = lpw; /* Line 1726, Address: 0x10203f0 */
    *pIndex = *lpw; /* Line 1727, Address: 0x10203f8 */




    return 1; /* Line 1732, Address: 0x1020408 */
  }

  *pIndex = 0; /* Line 1735, Address: 0x1020414 */
  return 0; /* Line 1736, Address: 0x102041c */
} /* Line 1737, Address: 0x1020420 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1751, Address: 0x1020440 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1758, Address: 0x102045c */
  pMapWk = (unsigned char*)mapwka; /* Line 1759, Address: 0x1020460 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1760, Address: 0x1020468 */

    if (block_chk(xOffs, yOffs) == 0) { /* Line 1762, Address: 0x102048c */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1763, Address: 0x10204a4 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1764, Address: 0x10204b8 */
    }
  }


} /* Line 1769, Address: 0x10204d0 */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1783, Address: 0x10204f0 */
  if ((unsigned short)((scra_v_posit.w.h & 65520) - 16) <= yOffs) { /* Line 1784, Address: 0x10204fc */
    if ((short)((scra_v_posit.w.h + 240 & 65520) - 16) > (short)yOffs) { /* Line 1785, Address: 0x1020530 */
      if ((unsigned short)((scra_h_posit.w.h & 65520) - 16) < xOffs) { /* Line 1786, Address: 0x102057c */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1787, Address: 0x10205b0 */

          return 0; /* Line 1789, Address: 0x10205fc */
        }
      }
    }
  }

  return 1; /* Line 1795, Address: 0x1020608 */
} /* Line 1796, Address: 0x102060c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1813, Address: 0x1020620 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1814, Address: 0x102063c */

} /* Line 1816, Address: 0x1020658 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1818, Address: 0x1020670 */
  wH_posiw = 0; /* Line 1819, Address: 0x102068c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1820, Address: 0x1020690 */

} /* Line 1822, Address: 0x10206ac */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1824, Address: 0x10206c0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1825, Address: 0x10206d4 */

} /* Line 1827, Address: 0x10206f0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1829, Address: 0x1020700 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1830, Address: 0x102071c */

} /* Line 1832, Address: 0x1020738 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1834, Address: 0x1020750 */
  xOffs += wH_posiw; /* Line 1835, Address: 0x1020768 */
  yOffs += wV_posiw; /* Line 1836, Address: 0x1020778 */
  yOffs &= 240; /* Line 1837, Address: 0x1020788 */
  xOffs &= 496; /* Line 1838, Address: 0x1020794 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1840, Address: 0x10207a0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1841, Address: 0x10207cc */


} /* Line 1844, Address: 0x10207f8 */















void mapwrt(void) { /* Line 1860, Address: 0x1020810 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1867, Address: 0x1020828 */
  wV_posiw = scra_v_posit.w.h; /* Line 1868, Address: 0x1020834 */
  pMapWk = (unsigned char*)mapwka; /* Line 1869, Address: 0x1020840 */
  VramBase = 16384; /* Line 1870, Address: 0x1020848 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1871, Address: 0x102084c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1875, Address: 0x1020864 */
  VramBase = 24576; /* Line 1876, Address: 0x102086c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1877, Address: 0x1020870 */

} /* Line 1879, Address: 0x1020880 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1882, Address: 0x10208a0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1883, Address: 0x10208b8 */
} /* Line 1884, Address: 0x10208d8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1889, Address: 0x10208f0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1893, Address: 0x1020910 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1896, Address: 0x102092c */



    wD4 += 16; /* Line 1900, Address: 0x1020954 */
  } while ((short)--wD6 >= 0); /* Line 1901, Address: 0x1020960 */

} /* Line 1903, Address: 0x1020988 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1909, Address: 0x10209a0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1912, Address: 0x10209bc */
  wD6 = 15; /* Line 1913, Address: 0x10209c4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1916, Address: 0x10209cc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1918, Address: 0x10209f0 */
    wD4 += 16; /* Line 1919, Address: 0x1020a10 */
  } while ((short)--wD6 >= 0); /* Line 1920, Address: 0x1020a18 */
} /* Line 1921, Address: 0x1020a3c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1947, Address: 0x1020a60 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1952, Address: 0x1020a88 */
  wD0 = pWrttbl[wD0]; /* Line 1953, Address: 0x1020a98 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1955, Address: 0x1020ab4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1956, Address: 0x1020ad8 */
  if (wD0) { /* Line 1957, Address: 0x1020b00 */
    wD5 = 65520; /* Line 1958, Address: 0x1020b0c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1959, Address: 0x1020b14 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1962, Address: 0x1020b30 */



  } /* Line 1966, Address: 0x1020b58 */
  else {

    wD5 = 0; /* Line 1969, Address: 0x1020b60 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1970, Address: 0x1020b64 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1974, Address: 0x1020b80 */
  }





} /* Line 1981, Address: 0x1020ba8 */










void mapinit(void) { /* Line 1992, Address: 0x1020bd0 */

  colorset2(mapinittbl.colorno2); /* Line 1994, Address: 0x1020bd8 */
  colorset(mapinittbl.colorno2); /* Line 1995, Address: 0x1020bec */

  if (plflag) enecginit(); /* Line 1997, Address: 0x1020c00 */
  if (play_start & 2) divdevset(); /* Line 1998, Address: 0x1020c18 */
} /* Line 1999, Address: 0x1020c38 */




void mapset(void) {} /* Line 2004, Address: 0x1020c50 */



void divdevset() {} /* Line 2008, Address: 0x1020c60 */



void enecginit(void) {} /* Line 2012, Address: 0x1020c70 */
