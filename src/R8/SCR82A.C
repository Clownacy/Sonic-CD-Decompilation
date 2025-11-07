#include "..\EQU.H"
#include "SCR81A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL8A.H"
#include "SCRCHK8.H"

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
short playpositbl[2][2] = {
  { 46, 1164 },
  { 6942, 1484 }
};
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;











































































sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 151, Address: 0x1029ed0 */
    return &actwk[0]; /* Line 152, Address: 0x1029ee4 */
  else
    return &actwk[1]; /* Line 154, Address: 0x1029ef4 */

} /* Line 156, Address: 0x1029efc */





































void scr_set(void) { /* Line 194, Address: 0x1029f10 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 197, Address: 0x1029f1c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1029f30 */
  scr_timer.b.h = 0; /* Line 199, Address: 0x1029f44 */

  pScrTbl = scr_dir_tbl; /* Line 201, Address: 0x1029f4c */
  scrar_no = *pScrTbl; /* Line 202, Address: 0x1029f54 */
  ++pScrTbl; /* Line 203, Address: 0x1029f60 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 204, Address: 0x1029f64 */
  ++pScrTbl; /* Line 205, Address: 0x1029f78 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 206, Address: 0x1029f7c */
  ++pScrTbl; /* Line 207, Address: 0x1029f90 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 208, Address: 0x1029f94 */
  ++pScrTbl; /* Line 209, Address: 0x1029fa8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 210, Address: 0x1029fac */
  scra_h_keep = *pScrTbl + 576; /* Line 211, Address: 0x1029fc0 */
  ++pScrTbl; /* Line 212, Address: 0x1029fe0 */
  scra_h_count = 16; /* Line 213, Address: 0x1029fe4 */
  scra_v_count = 16; /* Line 214, Address: 0x1029ff0 */

  scra_vline = *pScrTbl; /* Line 216, Address: 0x1029ffc */
  scra_hline = 160; /* Line 217, Address: 0x102a008 */

  playposiset(); /* Line 219, Address: 0x102a014 */
} /* Line 220, Address: 0x102a01c */


















































static void playposiset(void) { /* Line 271, Address: 0x102a030 */
  short xwk, ywk, *pPositbl;


  if (lpKeepWork->demoflag.w) { /* Line 275, Address: 0x102a044 */
    pPositbl = &playpositbl[1][0]; /* Line 276, Address: 0x102a058 */
    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 277, Address: 0x102a060 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 278, Address: 0x102a074 */
  } else { /* Line 279, Address: 0x102a088 */
    if (plflag) { /* Line 280, Address: 0x102a090 */
      playload(); /* Line 281, Address: 0x102a0a0 */
      xwk = actwk[0].xposi.w.h; /* Line 282, Address: 0x102a0a8 */

      if (actwk[0].yposi.w.h > 0) { /* Line 284, Address: 0x102a0b8 */
        ywk = actwk[0].yposi.w.h; /* Line 285, Address: 0x102a0d0 */
      } else { /* Line 286, Address: 0x102a0e0 */
        ywk = 0; /* Line 287, Address: 0x102a0e8 */
      }
    } /* Line 289, Address: 0x102a0ec */
    else {
      pPositbl = &playpositbl[0][0]; /* Line 291, Address: 0x102a0f4 */

      actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 293, Address: 0x102a0fc */
      actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 294, Address: 0x102a110 */
    }
  }

  if (xwk > 160) { /* Line 298, Address: 0x102a124 */
    xwk -= 160; /* Line 299, Address: 0x102a138 */
  } else { /* Line 300, Address: 0x102a144 */
    xwk = 0; /* Line 301, Address: 0x102a14c */
  }


  if (xwk > scralim_right) { /* Line 305, Address: 0x102a150 */
    xwk = scralim_right; /* Line 306, Address: 0x102a174 */
  }


  scra_h_posit.w.h = xwk; /* Line 310, Address: 0x102a184 */

  if (ywk > 96) { /* Line 312, Address: 0x102a18c */
    ywk -= 96; /* Line 313, Address: 0x102a1a0 */
  } else { /* Line 314, Address: 0x102a1ac */
    ywk = 0; /* Line 315, Address: 0x102a1b4 */
  }


  if (ywk > scralim_down) { /* Line 319, Address: 0x102a1b8 */
    ywk = scralim_down; /* Line 320, Address: 0x102a1dc */
  }


  scra_v_posit.w.h = ywk; /* Line 324, Address: 0x102a1ec */

  scrbinit(xwk, ywk); /* Line 326, Address: 0x102a1f4 */


  loopmapno = playmapnotbl[0]; /* Line 329, Address: 0x102a204 */
  loopmapno2 = playmapnotbl[1]; /* Line 330, Address: 0x102a214 */
  ballmapno = playmapnotbl[2]; /* Line 331, Address: 0x102a224 */
  ballmapno2 = playmapnotbl[3]; /* Line 332, Address: 0x102a234 */
} /* Line 333, Address: 0x102a244 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 354, Address: 0x102a260 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 357, Address: 0x102a26c */
  lYwk.w.l = 0; /* Line 358, Address: 0x102a274 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 360, Address: 0x102a278 */
  scrb_v_posit.l = lYwk.l; /* Line 361, Address: 0x102a284 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 362, Address: 0x102a290 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 363, Address: 0x102a29c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 365, Address: 0x102a2a8 */
  scrc_h_posit.w.h = sXpos; /* Line 366, Address: 0x102a2c4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 368, Address: 0x102a2d0 */
  scrz_h_posit.w.h = sXpos; /* Line 369, Address: 0x102a2ec */

  sXpos = (unsigned short)sXpos >> 2; /* Line 371, Address: 0x102a2f8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 372, Address: 0x102a314 */
} /* Line 373, Address: 0x102a338 */















void scroll(void) { /* Line 389, Address: 0x102a350 */
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

  if (scroll_start.b.h) return; /* Line 401, Address: 0x102a36c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 406, Address: 0x102a37c */

  scrchk(); /* Line 408, Address: 0x102a3a8 */

  scroll_h(); /* Line 410, Address: 0x102a3b0 */
  scroll_v(); /* Line 411, Address: 0x102a3b8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 413, Address: 0x102a3c0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 414, Address: 0x102a3d0 */


  lXwk = scra_hz << 6; /* Line 417, Address: 0x102a3e0 */
  scrollz_h(lXwk, 6); /* Line 418, Address: 0x102a3f4 */

  lXwk = scra_hz << 7; /* Line 420, Address: 0x102a404 */
  scrollc_h(lXwk, 4); /* Line 421, Address: 0x102a418 */

  lXwk = (scra_hz << 4) * 3; /* Line 423, Address: 0x102a428 */
  scrollb_h(lXwk, 2); /* Line 424, Address: 0x102a444 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 426, Address: 0x102a454 */


  scrollb_v(lYwk); /* Line 429, Address: 0x102a468 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 431, Address: 0x102a478 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 433, Address: 0x102a4a0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 434, Address: 0x102a4d8 */

  psHscw = hscrollwork; /* Line 436, Address: 0x102a4ec */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 438, Address: 0x102a4f8 */
  for (i = 0; i < 6; ++i) { /* Line 439, Address: 0x102a518 */

    *psHscw++ = ldwk.w.l; /* Line 441, Address: 0x102a524 */
  } /* Line 442, Address: 0x102a538 */

  z82bline0(&psHscw); /* Line 444, Address: 0x102a548 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 446, Address: 0x102a554 */
  for (i = 0; i < 18; ++i) { /* Line 447, Address: 0x102a574 */

    *psHscw++ = ldwk.w.l; /* Line 449, Address: 0x102a580 */
  } /* Line 450, Address: 0x102a594 */

  z82bline1(&psHscw); /* Line 452, Address: 0x102a5a4 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 454, Address: 0x102a5b0 */
  for (i = 0; i < 10; ++i) { /* Line 455, Address: 0x102a5d0 */

    *psHscw++ = ldwk.w.l; /* Line 457, Address: 0x102a5dc */
  } /* Line 458, Address: 0x102a5f0 */

  pHscrbuf = lphscrollbuff; /* Line 460, Address: 0x102a600 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 461, Address: 0x102a60c */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 462, Address: 0x102a63c */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 463, Address: 0x102a66c */
} /* Line 464, Address: 0x102a688 */




static void z82bline0(short** ppHscw) { /* Line 469, Address: 0x102a6b0 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl0[7] = {
    0, 0, 0, 0, 1, 1, 1
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 478, Address: 0x102a6c8 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 479, Address: 0x102a6ec */

  ldwk.w.l = scrz_h_posit.w.h; /* Line 481, Address: 0x102a70c */

  for (i = 6; i >= 0; --i) { /* Line 483, Address: 0x102a718 */

    wk = -ldwk.w.l; /* Line 485, Address: 0x102a724 */

    for (j = z82bscrtbl0[i]; j >= 0; --j) { /* Line 487, Address: 0x102a744 */

      **ppHscw = wk; /* Line 489, Address: 0x102a764 */
      ++*ppHscw; /* Line 490, Address: 0x102a770 */
    } /* Line 491, Address: 0x102a784 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 493, Address: 0x102a790 */
    ldwk.l += lXwk; /* Line 494, Address: 0x102a7b4 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 495, Address: 0x102a7c0 */
  } /* Line 496, Address: 0x102a7e4 */
} /* Line 497, Address: 0x102a7f0 */




static void z82bline1(short** ppHscw) { /* Line 502, Address: 0x102a810 */
  int i, j;
  int lXwk;
  int_union ldwk;
  short wk;
  static char z82bscrtbl1[7] = {
    0, 0, 0, 0, 1, 9, 1
  };

  lXwk = scrc_h_posit.w.h - scrz_h_posit.w.h; /* Line 511, Address: 0x102a828 */
  lXwk = (unsigned int)(lXwk << 7) / 5 << 9; /* Line 512, Address: 0x102a84c */

  ldwk.w.l = scrz_h_posit.w.h; /* Line 514, Address: 0x102a86c */
  *ppHscw += 18; /* Line 515, Address: 0x102a878 */

  for (i = 6; i >= 0; --i) { /* Line 517, Address: 0x102a88c */

    wk = -ldwk.w.l; /* Line 519, Address: 0x102a898 */

    for (j = z82bscrtbl1[i]; j >= 0; --j) { /* Line 521, Address: 0x102a8b8 */

      --*ppHscw; /* Line 523, Address: 0x102a8d8 */
      **ppHscw = wk; /* Line 524, Address: 0x102a8ec */
    } /* Line 525, Address: 0x102a8f8 */

    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 527, Address: 0x102a904 */
    ldwk.l += lXwk; /* Line 528, Address: 0x102a928 */
    ldwk.l = (unsigned int)ldwk.l >> 16 & 65535 | ldwk.l << 16 & -65536; /* Line 529, Address: 0x102a934 */
  } /* Line 530, Address: 0x102a958 */
  *ppHscw += 18; /* Line 531, Address: 0x102a964 */
} /* Line 532, Address: 0x102a978 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 553, Address: 0x102a9a0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 557, Address: 0x102a9bc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 558, Address: 0x102a9c0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 560, Address: 0x102a9e0 */
    ldwk.w.l = *pHscrwk; /* Line 561, Address: 0x102a9fc */
    ++pHscrwk; /* Line 562, Address: 0x102aa08 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 564, Address: 0x102aa14 */
      (*pHscrbuf)->l = ldwk.l; /* Line 565, Address: 0x102aa1c */
    } /* Line 566, Address: 0x102aa2c */
  } /* Line 567, Address: 0x102aa50 */
} /* Line 568, Address: 0x102aa70 */









































































































static void scrollb_v(short yPos) { /* Line 674, Address: 0x102aa90 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 677, Address: 0x102aaa0 */
  scrb_v_posit.w.h = yPos; /* Line 678, Address: 0x102aab0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 679, Address: 0x102aabc */

  if (!ywk) { /* Line 681, Address: 0x102aaf4 */
    scrb_v_count ^= 16; /* Line 682, Address: 0x102aafc */
    if (yPos - ysv < 0) { /* Line 683, Address: 0x102ab10 */
      scrflagb.b.h |= 1; /* Line 684, Address: 0x102ab30 */
    } /* Line 685, Address: 0x102ab44 */
    else {
      scrflagb.b.h |= 2; /* Line 687, Address: 0x102ab4c */
    }
  }


} /* Line 692, Address: 0x102ab60 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 710, Address: 0x102ab80 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 714, Address: 0x102ab94 */
  lXwk = lXsv + xoffs; /* Line 715, Address: 0x102ab9c */
  scrb_h_posit.l = lXwk; /* Line 716, Address: 0x102aba4 */
  ldXwk.l = lXwk; /* Line 717, Address: 0x102abac */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 718, Address: 0x102abb0 */
  ldXwk.w.l &= 16; /* Line 719, Address: 0x102abd4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 720, Address: 0x102abe0 */

  if (!ldXwk.b.b4) { /* Line 722, Address: 0x102abfc */
    scrb_h_count ^= 16; /* Line 723, Address: 0x102ac08 */
    if (lXwk - lXsv < 0) { /* Line 724, Address: 0x102ac1c */
      scrflagb.b.h |= 1 << flgbit; /* Line 725, Address: 0x102ac28 */
    } /* Line 726, Address: 0x102ac4c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 728, Address: 0x102ac54 */
    }
  }


} /* Line 733, Address: 0x102ac7c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 751, Address: 0x102ac90 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 755, Address: 0x102aca4 */
  lXwk = lXsv + xoffs; /* Line 756, Address: 0x102acac */
  scrc_h_posit.l = lXwk; /* Line 757, Address: 0x102acb4 */
  ldXwk.l = lXwk; /* Line 758, Address: 0x102acbc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 759, Address: 0x102acc0 */
  ldXwk.w.l &= 16; /* Line 760, Address: 0x102ace4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 761, Address: 0x102acf0 */

  if (!ldXwk.b.b4) { /* Line 763, Address: 0x102ad0c */
    scrc_h_count ^= 16; /* Line 764, Address: 0x102ad18 */
    if (lXwk - lXsv < 0) { /* Line 765, Address: 0x102ad2c */
      scrflagc.b.h |= 1 << flgbit; /* Line 766, Address: 0x102ad38 */
    } /* Line 767, Address: 0x102ad5c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 769, Address: 0x102ad64 */
    }
  }


} /* Line 774, Address: 0x102ad8c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 792, Address: 0x102ada0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 796, Address: 0x102adb4 */
  lXwk = lXsv + xoffs; /* Line 797, Address: 0x102adbc */
  scrz_h_posit.l = lXwk; /* Line 798, Address: 0x102adc4 */
  ldXwk.l = lXwk; /* Line 799, Address: 0x102adcc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 800, Address: 0x102add0 */
  ldXwk.w.l &= 16; /* Line 801, Address: 0x102adf4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 802, Address: 0x102ae00 */

  if (!ldXwk.b.b4) { /* Line 804, Address: 0x102ae1c */
    scrz_h_count ^= 16; /* Line 805, Address: 0x102ae28 */
    if (lXwk - lXsv < 0) { /* Line 806, Address: 0x102ae3c */
      scrflagz.b.h |= 1 << flgbit; /* Line 807, Address: 0x102ae48 */
    } /* Line 808, Address: 0x102ae6c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 810, Address: 0x102ae74 */
    }
  }


} /* Line 815, Address: 0x102ae9c */














static void scroll_h(void) { /* Line 830, Address: 0x102aeb0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 834, Address: 0x102aec0 */

  scrh_move(); /* Line 836, Address: 0x102aed0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 837, Address: 0x102aed8 */
  if (!bXwk) { /* Line 838, Address: 0x102af0c */
    scra_h_count ^= 16; /* Line 839, Address: 0x102af14 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 840, Address: 0x102af28 */
      scrflaga.b.h |= 4; /* Line 841, Address: 0x102af4c */
    } else { /* Line 842, Address: 0x102af60 */
      scrflaga.b.h |= 8; /* Line 843, Address: 0x102af68 */
    }
  }


} /* Line 848, Address: 0x102af7c */
















static void scrh_move(void) { /* Line 865, Address: 0x102afa0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 868, Address: 0x102afa8 */
  if (xwk == 0) { /* Line 869, Address: 0x102aff0 */

    scra_hz = 0; /* Line 871, Address: 0x102b000 */
    return; /* Line 872, Address: 0x102b008 */
  } else if (xwk < 0) { /* Line 873, Address: 0x102b010 */

    if (xwk < -16) { /* Line 875, Address: 0x102b020 */
      xwk = -16; /* Line 876, Address: 0x102b034 */
    }


    xwk += scra_h_posit.w.h; /* Line 880, Address: 0x102b040 */
    if (xwk < scralim_left) { /* Line 881, Address: 0x102b054 */
      xwk = scralim_left; /* Line 882, Address: 0x102b078 */
    }
  } /* Line 884, Address: 0x102b088 */
  else {
    if (xwk > 16) { /* Line 886, Address: 0x102b090 */
      xwk = 16; /* Line 887, Address: 0x102b0a4 */
    }


    xwk += scra_h_posit.w.h; /* Line 891, Address: 0x102b0b0 */
    if (xwk > scralim_right) { /* Line 892, Address: 0x102b0c4 */
      xwk = scralim_right; /* Line 893, Address: 0x102b0e8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 898, Address: 0x102b0f8 */
  scra_h_posit.w.h = xwk; /* Line 899, Address: 0x102b128 */
} /* Line 900, Address: 0x102b130 */














static void scroll_v(void) { /* Line 915, Address: 0x102b140 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 918, Address: 0x102b14c */
  if (actwk[0].cddat & 4) { /* Line 919, Address: 0x102b180 */
    ywk -= 5; /* Line 920, Address: 0x102b198 */
  }


  if (actwk[0].cddat & 2) { /* Line 924, Address: 0x102b1a4 */
    ywk += 32; /* Line 925, Address: 0x102b1bc */
    if (ywk < scra_vline) { /* Line 926, Address: 0x102b1c8 */
      ywk -= scra_vline; /* Line 927, Address: 0x102b1ec */
      sv_move_main2(ywk); /* Line 928, Address: 0x102b200 */
      return; /* Line 929, Address: 0x102b20c */
    } else if (ywk >= scra_vline + 64) { /* Line 930, Address: 0x102b214 */
      ywk -= scra_vline + 64; /* Line 931, Address: 0x102b23c */
      sv_move_main2(ywk); /* Line 932, Address: 0x102b264 */
      return; /* Line 933, Address: 0x102b270 */
    }
    ywk -= scra_vline + 64; /* Line 935, Address: 0x102b278 */
    if (!limmoveflag) goto label1; /* Line 936, Address: 0x102b2a0 */
    sv_move_sub2(); /* Line 937, Address: 0x102b2b0 */
    return; /* Line 938, Address: 0x102b2b8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 943, Address: 0x102b2c0 */
    sv_move_main(ywk); /* Line 944, Address: 0x102b2ec */
    return; /* Line 945, Address: 0x102b2f8 */
  } else if (!limmoveflag) goto label1; /* Line 946, Address: 0x102b300 */
  sv_move_sub2(); /* Line 947, Address: 0x102b310 */
  return; /* Line 948, Address: 0x102b318 */



label1:
  scra_vz = 0; /* Line 953, Address: 0x102b320 */
} /* Line 954, Address: 0x102b328 */













static void sv_move_main(short yPos) { /* Line 968, Address: 0x102b340 */
  short spdwk;

  if (scra_vline == 96) { /* Line 971, Address: 0x102b350 */
    if (actwk[0].mspeed.w < 0) { /* Line 972, Address: 0x102b36c */
      spdwk = -actwk[0].mspeed.w; /* Line 973, Address: 0x102b384 */
    } else { /* Line 974, Address: 0x102b3a8 */
      spdwk = actwk[0].mspeed.w; /* Line 975, Address: 0x102b3b0 */
    }


    if (spdwk >= 2048) { /* Line 979, Address: 0x102b3c0 */
      sv_move_main2(yPos); /* Line 980, Address: 0x102b3d4 */
    } /* Line 981, Address: 0x102b3e0 */
    else {

      if (yPos > 6) { /* Line 984, Address: 0x102b3e8 */
        sv_move_plus(1536); /* Line 985, Address: 0x102b400 */
      } else if (yPos < -6) { /* Line 986, Address: 0x102b40c */
        sv_move_minus(1536); /* Line 987, Address: 0x102b42c */
      } /* Line 988, Address: 0x102b438 */
      else sv_move_sub(yPos); /* Line 989, Address: 0x102b440 */
    }
  } /* Line 991, Address: 0x102b44c */
  else {
    if (yPos > 2) { /* Line 993, Address: 0x102b454 */
      sv_move_plus(512); /* Line 994, Address: 0x102b46c */
    } else if (yPos < -2) { /* Line 995, Address: 0x102b478 */
      sv_move_minus(512); /* Line 996, Address: 0x102b498 */
    } /* Line 997, Address: 0x102b4a4 */
    else sv_move_sub(yPos); /* Line 998, Address: 0x102b4ac */
  }

} /* Line 1001, Address: 0x102b4b8 */













static void sv_move_main2(short yPos) { /* Line 1015, Address: 0x102b4d0 */
  short spdwk;

  spdwk = 4096; /* Line 1018, Address: 0x102b4e0 */

  if (yPos > 16) { /* Line 1020, Address: 0x102b4ec */
    sv_move_plus(spdwk); /* Line 1021, Address: 0x102b504 */
  } else if (yPos < -16) { /* Line 1022, Address: 0x102b510 */
    sv_move_minus(spdwk); /* Line 1023, Address: 0x102b530 */
  } else { /* Line 1024, Address: 0x102b53c */
    sv_move_sub(yPos); /* Line 1025, Address: 0x102b544 */
  }
} /* Line 1027, Address: 0x102b550 */














static void sv_move_sub(short yPos) { /* Line 1042, Address: 0x102b570 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1045, Address: 0x102b57c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1046, Address: 0x102b580 */
  if (yPos < 0) { /* Line 1047, Address: 0x102b5ac */
    scrv_up_ch(lSpd); /* Line 1048, Address: 0x102b5c0 */
  } else { /* Line 1049, Address: 0x102b5cc */
    scrv_down_ch(lSpd); /* Line 1050, Address: 0x102b5d4 */
  }
} /* Line 1052, Address: 0x102b5e0 */



static void sv_move_sub2(void) { /* Line 1056, Address: 0x102b5f0 */
  limmoveflag = 0; /* Line 1057, Address: 0x102b5f8 */

  sv_move_sub(0); /* Line 1059, Address: 0x102b600 */
} /* Line 1060, Address: 0x102b60c */













static void sv_move_minus(short speed) { /* Line 1074, Address: 0x102b620 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1077, Address: 0x102b62c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1078, Address: 0x102b650 */
  scrv_up_ch(lSpd); /* Line 1079, Address: 0x102b674 */
} /* Line 1080, Address: 0x102b680 */














static void scrv_up_ch(int_union lSpd) { /* Line 1095, Address: 0x102b690 */
  if (lSpd.w.l <= scralim_up) { /* Line 1096, Address: 0x102b69c */
    if (lSpd.w.l > -256) { /* Line 1097, Address: 0x102b6c4 */

      lSpd.w.l = scralim_up; /* Line 1099, Address: 0x102b6dc */
    } else { /* Line 1100, Address: 0x102b6e8 */
      lSpd.w.l &= 2047; /* Line 1101, Address: 0x102b6f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1102, Address: 0x102b6fc */
      scra_v_posit.w.h &= 2047; /* Line 1103, Address: 0x102b710 */
      scrb_v_posit.w.h &= 1023; /* Line 1104, Address: 0x102b724 */
    }
  }

  scrv_move(lSpd); /* Line 1108, Address: 0x102b738 */
} /* Line 1109, Address: 0x102b744 */













static void sv_move_plus(short sSpd) { /* Line 1123, Address: 0x102b760 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1126, Address: 0x102b76c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1127, Address: 0x102b78c */
  scrv_down_ch(lSpd); /* Line 1128, Address: 0x102b7b0 */
} /* Line 1129, Address: 0x102b7bc */














static void scrv_down_ch(int_union lSpd) { /* Line 1144, Address: 0x102b7d0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1145, Address: 0x102b7dc */
    if (lSpd.w.l < 2048) { /* Line 1146, Address: 0x102b804 */

      lSpd.w.l = scralim_down; /* Line 1148, Address: 0x102b81c */
    } else { /* Line 1149, Address: 0x102b828 */
      lSpd.w.l -= 2048; /* Line 1150, Address: 0x102b830 */
      actwk[0].yposi.w.h &= 2047; /* Line 1151, Address: 0x102b83c */
      scra_v_posit.w.h -= 2048; /* Line 1152, Address: 0x102b850 */
      scrb_v_posit.w.h &= 1023; /* Line 1153, Address: 0x102b864 */
    }
  }

  scrv_move(lSpd); /* Line 1157, Address: 0x102b878 */
} /* Line 1158, Address: 0x102b884 */
















static void scrv_move(int_union lSpd) { /* Line 1175, Address: 0x102b8a0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1179, Address: 0x102b8b0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1180, Address: 0x102b8c0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1181, Address: 0x102b8e4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1182, Address: 0x102b8f8 */
  scra_vz = spdwk.w.l; /* Line 1183, Address: 0x102b910 */

  scra_v_posit.l = lSpd.l; /* Line 1185, Address: 0x102b91c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1187, Address: 0x102b928 */
  if (!ywk) { /* Line 1188, Address: 0x102b964 */
    scra_v_count ^= 16; /* Line 1189, Address: 0x102b96c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1190, Address: 0x102b980 */
    if (ywk < 0) { /* Line 1191, Address: 0x102b9ac */
      scrflaga.b.h |= 1; /* Line 1192, Address: 0x102b9bc */
    } else { /* Line 1193, Address: 0x102b9d0 */
      scrflaga.b.h |= 2; /* Line 1194, Address: 0x102b9d8 */
    }
  }


} /* Line 1199, Address: 0x102b9ec */

















void scrollwrt(void) { /* Line 1217, Address: 0x102ba00 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1226, Address: 0x102ba20 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1227, Address: 0x102ba24 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1228, Address: 0x102ba30 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1229, Address: 0x102ba3c */
  pScrFlag = &scrflagbw.b.h; /* Line 1230, Address: 0x102ba44 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1231, Address: 0x102ba4c */

  VramBase = 16384; /* Line 1233, Address: 0x102ba60 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1234, Address: 0x102ba64 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1235, Address: 0x102ba70 */
  pMapWk = (unsigned char*)mapwka; /* Line 1236, Address: 0x102ba7c */
  pScrFlag = &scrflagaw.b.h; /* Line 1237, Address: 0x102ba84 */

  if (*pScrFlag) { /* Line 1239, Address: 0x102ba8c */
    if (*pScrFlag & 1) { /* Line 1240, Address: 0x102ba98 */
      *pScrFlag &= 254; /* Line 1241, Address: 0x102baac */

      lD4.l = -16; /* Line 1243, Address: 0x102bab8 */
      wD5 = 65520; /* Line 1244, Address: 0x102bac0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1246, Address: 0x102bac8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1248, Address: 0x102bae8 */
    }




    if (*pScrFlag & 2) { /* Line 1254, Address: 0x102bb14 */
      *pScrFlag &= 253; /* Line 1255, Address: 0x102bb28 */

      lD4.l = 224; /* Line 1257, Address: 0x102bb34 */
      wD5 = 65520; /* Line 1258, Address: 0x102bb3c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1259, Address: 0x102bb44 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1261, Address: 0x102bb64 */
    }




    if (*pScrFlag & 4) { /* Line 1267, Address: 0x102bb90 */
      *pScrFlag &= 251; /* Line 1268, Address: 0x102bba4 */

      lD4.l = -16; /* Line 1270, Address: 0x102bbb0 */
      wD5 = 65520; /* Line 1271, Address: 0x102bbb8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1272, Address: 0x102bbc0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1274, Address: 0x102bbe0 */
    }




    if (*pScrFlag & 8) { /* Line 1280, Address: 0x102bc0c */
      *pScrFlag &= 247; /* Line 1281, Address: 0x102bc20 */

      lD4.l = -16; /* Line 1283, Address: 0x102bc2c */
      wD5 = 320; /* Line 1284, Address: 0x102bc34 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1285, Address: 0x102bc3c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1287, Address: 0x102bc5c */
    }
  }






} /* Line 1296, Address: 0x102bc88 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1313, Address: 0x102bcb0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1324, Address: 0x102bcdc */

  if (*pScrFlag & 1) { /* Line 1326, Address: 0x102bce4 */
    *pScrFlag &= 254; /* Line 1327, Address: 0x102bcfc */
  } /* Line 1328, Address: 0x102bd10 */
  else {
    *pScrFlag &= 254; /* Line 1330, Address: 0x102bd18 */

    if (*pScrFlag & 2) { /* Line 1332, Address: 0x102bd2c */
      *pScrFlag &= 253; /* Line 1333, Address: 0x102bd44 */
      lD4.w.l = 224; /* Line 1334, Address: 0x102bd58 */
    } /* Line 1335, Address: 0x102bd60 */
    else {
      *pScrFlag &= 253; /* Line 1337, Address: 0x102bd68 */
      goto label1; /* Line 1338, Address: 0x102bd7c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1343, Address: 0x102bd84 */
  wD0 &= 127; /* Line 1344, Address: 0x102bdd4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1345, Address: 0x102bddc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1351, Address: 0x102bdfc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1352, Address: 0x102be1c */
  if (wD0 != 0) { /* Line 1353, Address: 0x102be40 */
    wD5 = 65520; /* Line 1354, Address: 0x102be4c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1355, Address: 0x102be54 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1357, Address: 0x102be74 */



  } /* Line 1361, Address: 0x102bea0 */
  else {

    wD5 = 0; /* Line 1364, Address: 0x102bea8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1365, Address: 0x102beac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1369, Address: 0x102becc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1376, Address: 0x102bef8 */






    lD4.l = -16; /* Line 1383, Address: 0x102bf0c */
    wD5 = 65520; /* Line 1384, Address: 0x102bf14 */
    if (*pScrFlag & 168) { /* Line 1385, Address: 0x102bf1c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1386, Address: 0x102bf34 */
      wD5 = 320; /* Line 1387, Address: 0x102bf54 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1391, Address: 0x102bf5c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1393, Address: 0x102bf8c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1394, Address: 0x102bf98 */



    for (i = 0; i < 16; ++i) { /* Line 1398, Address: 0x102bfa8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1399, Address: 0x102bfb4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1400, Address: 0x102bfd4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1401, Address: 0x102c00c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1402, Address: 0x102c02c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1404, Address: 0x102c050 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1407, Address: 0x102c074 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1409, Address: 0x102c094 */
      }
      lD4.w.l += 16; /* Line 1411, Address: 0x102c0a8 */
    } /* Line 1412, Address: 0x102c0b4 */
    *pScrFlag = 0; /* Line 1413, Address: 0x102c0c4 */
  }
} /* Line 1415, Address: 0x102c0cc */





void scrollwrtc(void) {} /* Line 1421, Address: 0x102c100 */




void scrollwrtz(void) {} /* Line 1426, Address: 0x102c110 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1444, Address: 0x102c120 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1457, Address: 0x102c148 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1460, Address: 0x102c168 */
    pTilePoint->x += 2; /* Line 1461, Address: 0x102c17c */
    if (pTilePoint->x >= 64) { /* Line 1462, Address: 0x102c190 */
      pTilePoint->x -= 64; /* Line 1463, Address: 0x102c1a4 */
    }
    xOffs += 16; /* Line 1465, Address: 0x102c1b8 */
  } while (--lpcnt >= 0); /* Line 1466, Address: 0x102c1c4 */
} /* Line 1467, Address: 0x102c1d8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1471, Address: 0x102c1f0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1475, Address: 0x102c218 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1478, Address: 0x102c238 */
    pTilePoint->x += 2; /* Line 1479, Address: 0x102c24c */
    if (pTilePoint->x >= 64) { /* Line 1480, Address: 0x102c260 */
      pTilePoint->x -= 64; /* Line 1481, Address: 0x102c274 */
    }
    xOffs += 16; /* Line 1483, Address: 0x102c288 */
  } while (--lpcnt >= 0); /* Line 1484, Address: 0x102c294 */
} /* Line 1485, Address: 0x102c2a8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1505, Address: 0x102c2c0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1509, Address: 0x102c2e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1512, Address: 0x102c308 */
    pTilePoint->y += 2; /* Line 1513, Address: 0x102c31c */
    if (pTilePoint->y >= 32) { /* Line 1514, Address: 0x102c32c */
      pTilePoint->y -= 32; /* Line 1515, Address: 0x102c340 */
    }
    yOffs += 16; /* Line 1517, Address: 0x102c350 */
  } while (--lpcnt >= 0); /* Line 1518, Address: 0x102c35c */
} /* Line 1519, Address: 0x102c370 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1538, Address: 0x102c380 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1544, Address: 0x102c3b4 */

    base = 1; /* Line 1546, Address: 0x102c3c4 */
  } /* Line 1547, Address: 0x102c3c8 */
  else if (VramBase == 16384) { /* Line 1548, Address: 0x102c3d0 */

    base = 0; /* Line 1550, Address: 0x102c3e0 */
  }
  x = pTilePoint->x; /* Line 1552, Address: 0x102c3e4 */
  y = pTilePoint->y; /* Line 1553, Address: 0x102c3ec */


  frip = BlkIndex & 6144; /* Line 1556, Address: 0x102c3f4 */
  BlkIndex &= 1023; /* Line 1557, Address: 0x102c3fc */
  if (frip == 6144) { /* Line 1558, Address: 0x102c408 */

    p0 = 3, p1 = 2; /* Line 1560, Address: 0x102c414 */
    p2 = 1, p3 = 0; /* Line 1561, Address: 0x102c41c */
  } /* Line 1562, Address: 0x102c424 */
  else if (frip & 4096) { /* Line 1563, Address: 0x102c42c */

    p0 = 2, p1 = 3; /* Line 1565, Address: 0x102c438 */
    p2 = 0, p3 = 1; /* Line 1566, Address: 0x102c440 */
  } /* Line 1567, Address: 0x102c448 */
  else if (frip & 2048) { /* Line 1568, Address: 0x102c450 */

    p0 = 1, p1 = 0; /* Line 1570, Address: 0x102c45c */
    p2 = 3, p3 = 2; /* Line 1571, Address: 0x102c464 */
  } /* Line 1572, Address: 0x102c46c */
  else {

    p0 = 0, p1 = 1; /* Line 1575, Address: 0x102c474 */
    p2 = 2, p3 = 3; /* Line 1576, Address: 0x102c47c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1579, Address: 0x102c484 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1580, Address: 0x102c4c8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1581, Address: 0x102c50c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1582, Address: 0x102c550 */

} /* Line 1584, Address: 0x102c594 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1602, Address: 0x102c5d0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1603, Address: 0x102c5f0 */
} /* Line 1604, Address: 0x102c610 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1606, Address: 0x102c620 */
  wH_posiw = 0; /* Line 1607, Address: 0x102c640 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1608, Address: 0x102c644 */
} /* Line 1609, Address: 0x102c664 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1616, Address: 0x102c680 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1622, Address: 0x102c6b0 */
  yOffs += wV_posiw; /* Line 1623, Address: 0x102c6c0 */





  if ((short)xOffs < 0) /* Line 1629, Address: 0x102c6d0 */
    xOffs = 0; /* Line 1630, Address: 0x102c6ec */
  if ((short)yOffs < 0) /* Line 1631, Address: 0x102c6f0 */
    yOffs = 0; /* Line 1632, Address: 0x102c70c */
  if ((short)xOffs >= 16384) /* Line 1633, Address: 0x102c710 */
    xOffs = 16383; /* Line 1634, Address: 0x102c730 */
  if ((short)yOffs >= 2048) /* Line 1635, Address: 0x102c738 */
    yOffs = 2047; /* Line 1636, Address: 0x102c758 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1637, Address: 0x102c760 */
  if (i < 0) i = 0; /* Line 1638, Address: 0x102c7a8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1640, Address: 0x102c7b4 */

  if (ScreenNo) { /* Line 1642, Address: 0x102c7d0 */




    xOffs &= 32767; /* Line 1647, Address: 0x102c7d8 */
    yOffs &= 32767; /* Line 1648, Address: 0x102c7e4 */


    xBlk = xOffs; /* Line 1651, Address: 0x102c7f0 */
    xBlk %= 256; /* Line 1652, Address: 0x102c7f8 */
    xBlk /= 16; /* Line 1653, Address: 0x102c818 */
    yBlk = yOffs; /* Line 1654, Address: 0x102c834 */
    yBlk %= 256; /* Line 1655, Address: 0x102c83c */
    yBlk /= 16; /* Line 1656, Address: 0x102c85c */

    lpw = pmapwk; /* Line 1658, Address: 0x102c878 */
    lpw += xBlk; /* Line 1659, Address: 0x102c880 */
    lpw += yBlk * 16; /* Line 1660, Address: 0x102c888 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1661, Address: 0x102c894 */
    *pIndex = *lpw; /* Line 1662, Address: 0x102c8ac */

    return 1; /* Line 1664, Address: 0x102c8bc */
  }

  *pIndex = 0; /* Line 1667, Address: 0x102c8c8 */
  return 0; /* Line 1668, Address: 0x102c8d0 */
} /* Line 1669, Address: 0x102c8d4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1689, Address: 0x102c900 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1697, Address: 0x102c928 */
  if (ScreenNo) { /* Line 1698, Address: 0x102c98c */





    xBlk = xOffs; /* Line 1704, Address: 0x102c994 */
    xBlk %= 256; /* Line 1705, Address: 0x102c99c */
    xBlk /= 16; /* Line 1706, Address: 0x102c9bc */
    yBlk = yOffs; /* Line 1707, Address: 0x102c9d8 */
    yBlk %= 256; /* Line 1708, Address: 0x102c9e0 */
    yBlk /= 16; /* Line 1709, Address: 0x102ca00 */


    lpw = pmapwk; /* Line 1712, Address: 0x102ca1c */
    lpw += xBlk; /* Line 1713, Address: 0x102ca24 */
    lpw += yBlk * 16; /* Line 1714, Address: 0x102ca2c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1715, Address: 0x102ca38 */
    *ppBlockNo = lpw; /* Line 1716, Address: 0x102ca50 */
    *pIndex = *lpw; /* Line 1717, Address: 0x102ca58 */




    return 1; /* Line 1722, Address: 0x102ca68 */
  }

  *pIndex = 0; /* Line 1725, Address: 0x102ca74 */
  return 0; /* Line 1726, Address: 0x102ca7c */
} /* Line 1727, Address: 0x102ca80 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1741, Address: 0x102caa0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1748, Address: 0x102cabc */
  pMapWk = (unsigned char*)mapwka; /* Line 1749, Address: 0x102cac0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1750, Address: 0x102cac8 */
    *pBlockIndex = BlockNo; /* Line 1751, Address: 0x102caec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1752, Address: 0x102caf8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1753, Address: 0x102cb10 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1754, Address: 0x102cb24 */
    }
  }


} /* Line 1759, Address: 0x102cb3c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1773, Address: 0x102cb60 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1774, Address: 0x102cb6c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1775, Address: 0x102cb98 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1776, Address: 0x102cbe4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1777, Address: 0x102cc10 */

          return 0; /* Line 1779, Address: 0x102cc5c */
        }
      }
    }
  }

  return 1; /* Line 1785, Address: 0x102cc68 */
} /* Line 1786, Address: 0x102cc6c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1803, Address: 0x102cc80 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1804, Address: 0x102cc9c */

} /* Line 1806, Address: 0x102ccb8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1808, Address: 0x102ccd0 */
  wH_posiw = 0; /* Line 1809, Address: 0x102ccec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1810, Address: 0x102ccf0 */

} /* Line 1812, Address: 0x102cd0c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1814, Address: 0x102cd20 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1815, Address: 0x102cd34 */

} /* Line 1817, Address: 0x102cd50 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1819, Address: 0x102cd60 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1820, Address: 0x102cd7c */

} /* Line 1822, Address: 0x102cd98 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1824, Address: 0x102cdb0 */
  xOffs += wH_posiw; /* Line 1825, Address: 0x102cdc8 */
  yOffs += wV_posiw; /* Line 1826, Address: 0x102cdd8 */
  yOffs &= 240; /* Line 1827, Address: 0x102cde8 */
  xOffs &= 496; /* Line 1828, Address: 0x102cdf4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1830, Address: 0x102ce00 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1831, Address: 0x102ce2c */


} /* Line 1834, Address: 0x102ce58 */















void mapwrt(void) { /* Line 1850, Address: 0x102ce70 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1857, Address: 0x102ce88 */
  wV_posiw = scra_v_posit.w.h; /* Line 1858, Address: 0x102ce94 */
  pMapWk = (unsigned char*)mapwka; /* Line 1859, Address: 0x102cea0 */
  VramBase = 16384; /* Line 1860, Address: 0x102cea8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1861, Address: 0x102ceac */



  pMapWk = (unsigned char*)mapwkb; /* Line 1865, Address: 0x102cec4 */
  VramBase = 24576; /* Line 1866, Address: 0x102cecc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1867, Address: 0x102ced0 */

} /* Line 1869, Address: 0x102cee0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1872, Address: 0x102cf00 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1873, Address: 0x102cf18 */
} /* Line 1874, Address: 0x102cf38 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1879, Address: 0x102cf50 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1883, Address: 0x102cf70 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1886, Address: 0x102cf8c */



    wD4 += 16; /* Line 1890, Address: 0x102cfb4 */
  } while ((short)--wD6 >= 0); /* Line 1891, Address: 0x102cfc0 */

} /* Line 1893, Address: 0x102cfe8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1899, Address: 0x102d000 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1902, Address: 0x102d01c */
  wD6 = 15; /* Line 1903, Address: 0x102d024 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1906, Address: 0x102d02c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1908, Address: 0x102d050 */
    wD4 += 16; /* Line 1909, Address: 0x102d070 */
  } while ((short)--wD6 >= 0); /* Line 1910, Address: 0x102d078 */
} /* Line 1911, Address: 0x102d09c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1937, Address: 0x102d0c0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1942, Address: 0x102d0e8 */
  wD0 = pWrttbl[wD0]; /* Line 1943, Address: 0x102d0f8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1945, Address: 0x102d114 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1946, Address: 0x102d138 */
  if (wD0) { /* Line 1947, Address: 0x102d160 */
    wD5 = 65520; /* Line 1948, Address: 0x102d16c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1949, Address: 0x102d174 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1952, Address: 0x102d190 */



  } /* Line 1956, Address: 0x102d1b8 */
  else {

    wD5 = 0; /* Line 1959, Address: 0x102d1c0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1960, Address: 0x102d1c4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1964, Address: 0x102d1e0 */
  }





} /* Line 1971, Address: 0x102d208 */










void mapinit(void) { /* Line 1982, Address: 0x102d230 */

  colorset2(mapinittbl.colorno2); /* Line 1984, Address: 0x102d238 */
  colorset(mapinittbl.colorno2); /* Line 1985, Address: 0x102d24c */

  if (plflag) enecginit(); /* Line 1987, Address: 0x102d260 */
  if (play_start & 2) divdevset(); /* Line 1988, Address: 0x102d278 */
} /* Line 1989, Address: 0x102d298 */




void mapset(void) {} /* Line 1994, Address: 0x102d2b0 */



void divdevset() {} /* Line 1998, Address: 0x102d2c0 */



void enecginit(void) {} /* Line 2002, Address: 0x102d2d0 */
