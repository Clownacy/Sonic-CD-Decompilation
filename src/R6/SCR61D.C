#include "..\EQU.H"
#include "SCR61A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL6C.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z61aline(short** ppHscw);
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

static unsigned char z81awrttbl[49];
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
short playpositbl[1][2] = { { 48, 1196 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;















































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 147, Address: 0x102ba20 */
    return &actwk[0]; /* Line 148, Address: 0x102ba34 */
  else
    return &actwk[1]; /* Line 150, Address: 0x102ba44 */

} /* Line 152, Address: 0x102ba4c */





































void scr_set() { /* Line 190, Address: 0x102ba60 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x102ba6c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x102ba80 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x102ba94 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x102ba9c */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x102baa4 */
  ++pScrTbl; /* Line 199, Address: 0x102bab0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x102bab4 */
  ++pScrTbl; /* Line 201, Address: 0x102bac8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x102bacc */
  ++pScrTbl; /* Line 203, Address: 0x102bae0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x102bae4 */
  ++pScrTbl; /* Line 205, Address: 0x102baf8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x102bafc */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x102bb10 */
  ++pScrTbl; /* Line 208, Address: 0x102bb30 */
  scra_h_count = 16; /* Line 209, Address: 0x102bb34 */
  scra_v_count = 16; /* Line 210, Address: 0x102bb40 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x102bb4c */
  scra_hline = 160; /* Line 213, Address: 0x102bb58 */

  playposiset(); /* Line 215, Address: 0x102bb64 */
} /* Line 216, Address: 0x102bb6c */
















































static void playposiset() { /* Line 265, Address: 0x102bb80 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 268, Address: 0x102bb94 */
    playload(); /* Line 269, Address: 0x102bba4 */
    xwk = actwk[0].xposi.w.h; /* Line 270, Address: 0x102bbac */

    if (actwk[0].yposi.w.h > 0) { /* Line 272, Address: 0x102bbbc */
      ywk = actwk[0].yposi.w.h; /* Line 273, Address: 0x102bbd4 */
    } else { /* Line 274, Address: 0x102bbe4 */
      ywk = 0; /* Line 275, Address: 0x102bbec */
    }
  } /* Line 277, Address: 0x102bbf0 */
  else {
    if (demoflag.w & -32768) { /* Line 279, Address: 0x102bbf8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 280, Address: 0x102bc18 */
    } /* Line 281, Address: 0x102bc3c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 283, Address: 0x102bc44 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 287, Address: 0x102bc64 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 288, Address: 0x102bc78 */
  }


  if (xwk > 160) { /* Line 292, Address: 0x102bc8c */
    xwk -= 160; /* Line 293, Address: 0x102bca0 */
  } else { /* Line 294, Address: 0x102bcac */
    xwk = 0; /* Line 295, Address: 0x102bcb4 */
  }


  if (xwk > scralim_right) { /* Line 299, Address: 0x102bcb8 */
    xwk = scralim_right; /* Line 300, Address: 0x102bcdc */
  }


  scra_h_posit.w.h = xwk; /* Line 304, Address: 0x102bcec */

  if (ywk > 96) { /* Line 306, Address: 0x102bcf4 */
    ywk -= 96; /* Line 307, Address: 0x102bd08 */
  } else { /* Line 308, Address: 0x102bd14 */
    ywk = 0; /* Line 309, Address: 0x102bd1c */
  }


  if (ywk > scralim_down) { /* Line 313, Address: 0x102bd20 */
    ywk = scralim_down; /* Line 314, Address: 0x102bd44 */
  }


  scra_v_posit.w.h = ywk; /* Line 318, Address: 0x102bd54 */

  scrbinit(xwk, ywk); /* Line 320, Address: 0x102bd5c */


  loopmapno = playmapnotbl[0]; /* Line 323, Address: 0x102bd6c */
  loopmapno2 = playmapnotbl[1]; /* Line 324, Address: 0x102bd7c */
  ballmapno = playmapnotbl[2]; /* Line 325, Address: 0x102bd8c */
  ballmapno2 = playmapnotbl[3]; /* Line 326, Address: 0x102bd9c */
} /* Line 327, Address: 0x102bdac */




















static void scrbinit(short sXpos, short sYpos) { /* Line 348, Address: 0x102bdd0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 351, Address: 0x102bddc */
  lYwk.w.l = 0; /* Line 352, Address: 0x102bde4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 354, Address: 0x102bde8 */
  scrb_v_posit.l = lYwk.l; /* Line 355, Address: 0x102bdf4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102be00 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 357, Address: 0x102be0c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 359, Address: 0x102be18 */
  scrc_h_posit.w.h = sXpos; /* Line 360, Address: 0x102be34 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 362, Address: 0x102be40 */
  scrz_h_posit.w.h = sXpos; /* Line 363, Address: 0x102be5c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 365, Address: 0x102be68 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 366, Address: 0x102be84 */
} /* Line 367, Address: 0x102bea8 */















void scroll() { /* Line 383, Address: 0x102bec0 */
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

  if (scroll_start.b.h) return; /* Line 395, Address: 0x102bedc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 400, Address: 0x102beec */

  scrchk(); /* Line 402, Address: 0x102bf18 */

  scroll_h(); /* Line 404, Address: 0x102bf20 */
  scroll_v(); /* Line 405, Address: 0x102bf28 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 407, Address: 0x102bf30 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 408, Address: 0x102bf40 */


  lXwk = scra_hz << 6; /* Line 411, Address: 0x102bf50 */
  scrollz_h(lXwk, 6); /* Line 412, Address: 0x102bf64 */

  lXwk = scra_hz << 7; /* Line 414, Address: 0x102bf74 */
  scrollc_h(lXwk, 4); /* Line 415, Address: 0x102bf88 */

  lXwk = (scra_hz << 4) * 3; /* Line 417, Address: 0x102bf98 */
  scrollb_h(lXwk, 2); /* Line 418, Address: 0x102bfb4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 420, Address: 0x102bfc4 */


  scrollb_v(lYwk); /* Line 423, Address: 0x102bfd8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 425, Address: 0x102bfe8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 427, Address: 0x102c010 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 428, Address: 0x102c048 */

  psHscw = hscrollwork; /* Line 430, Address: 0x102c05c */

  z61aline(&psHscw); /* Line 432, Address: 0x102c068 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 434, Address: 0x102c074 */
  for (i = 0; i < 24; ++i) { /* Line 435, Address: 0x102c094 */

    *psHscw++ = ldwk.w.l; /* Line 437, Address: 0x102c0a0 */
  } /* Line 438, Address: 0x102c0b4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 440, Address: 0x102c0c4 */
  for (i = 0; i < 46; ++i) { /* Line 441, Address: 0x102c0e4 */

    *psHscw++ = ldwk.w.l; /* Line 443, Address: 0x102c0f0 */
  } /* Line 444, Address: 0x102c104 */

  pHscrbuf = lphscrollbuff; /* Line 446, Address: 0x102c114 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 447, Address: 0x102c120 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 448, Address: 0x102c150 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 449, Address: 0x102c180 */
} /* Line 450, Address: 0x102c19c */













static void z61aline(short** ppHscw) { /* Line 464, Address: 0x102c1c0 */
  char z81ascrtbl[9] = { /* Line 465, Address: 0x102c1e8 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk, lHwk;

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 472, Address: 0x102c214 */
  radwk = 0; /* Line 473, Address: 0x102c238 */
  sXwk = scrb_h_posit.w.h; /* Line 474, Address: 0x102c23c */

  *ppHscw += 26; /* Line 476, Address: 0x102c24c */

  for (i = 8; i >= 0; --i) { /* Line 478, Address: 0x102c260 */

    sinset(radwk, &sinwk, &coswk); /* Line 480, Address: 0x102c26c */
    lHwk = (256 - coswk) * lXwk; /* Line 481, Address: 0x102c280 */
    lHwk = (unsigned int)lHwk >> 8; /* Line 482, Address: 0x102c298 */
    hwk = -(lHwk + sXwk); /* Line 483, Address: 0x102c29c */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 484, Address: 0x102c2bc */

      --*ppHscw; /* Line 486, Address: 0x102c2d4 */
      **ppHscw = hwk; /* Line 487, Address: 0x102c2e8 */
    } /* Line 488, Address: 0x102c2f4 */

    radwk += 6; /* Line 490, Address: 0x102c300 */
  } /* Line 491, Address: 0x102c30c */

  *ppHscw += 26; /* Line 493, Address: 0x102c318 */
} /* Line 494, Address: 0x102c32c */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 515, Address: 0x102c360 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 519, Address: 0x102c37c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 520, Address: 0x102c380 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 522, Address: 0x102c3a0 */
    ldwk.w.l = *pHscrwk; /* Line 523, Address: 0x102c3bc */
    ++pHscrwk; /* Line 524, Address: 0x102c3c8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 526, Address: 0x102c3d4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 527, Address: 0x102c3dc */
    } /* Line 528, Address: 0x102c3ec */
  } /* Line 529, Address: 0x102c410 */
} /* Line 530, Address: 0x102c430 */









































































































static void scrollb_v(short yPos) { /* Line 636, Address: 0x102c450 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 639, Address: 0x102c460 */
  scrb_v_posit.w.h = yPos; /* Line 640, Address: 0x102c470 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 641, Address: 0x102c47c */

  if (!ywk) { /* Line 643, Address: 0x102c4b4 */
    scrb_v_count ^= 16; /* Line 644, Address: 0x102c4bc */
    if (yPos - ysv < 0) { /* Line 645, Address: 0x102c4d0 */
      scrflagb.b.h |= 1; /* Line 646, Address: 0x102c4f0 */
    } /* Line 647, Address: 0x102c504 */
    else {
      scrflagb.b.h |= 2; /* Line 649, Address: 0x102c50c */
    }
  }


} /* Line 654, Address: 0x102c520 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 672, Address: 0x102c540 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 676, Address: 0x102c554 */
  lXwk = lXsv + xoffs; /* Line 677, Address: 0x102c55c */
  scrb_h_posit.l = lXwk; /* Line 678, Address: 0x102c564 */
  ldXwk.l = lXwk; /* Line 679, Address: 0x102c56c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 680, Address: 0x102c570 */
  ldXwk.w.l &= 16; /* Line 681, Address: 0x102c594 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 682, Address: 0x102c5a0 */

  if (!ldXwk.b.b4) { /* Line 684, Address: 0x102c5bc */
    scrb_h_count ^= 16; /* Line 685, Address: 0x102c5c8 */
    if (lXwk - lXsv < 0) { /* Line 686, Address: 0x102c5dc */
      scrflagb.b.h |= 1 << flgbit; /* Line 687, Address: 0x102c5e8 */
    } /* Line 688, Address: 0x102c60c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 690, Address: 0x102c614 */
    }
  }


} /* Line 695, Address: 0x102c63c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 713, Address: 0x102c650 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 717, Address: 0x102c664 */
  lXwk = lXsv + xoffs; /* Line 718, Address: 0x102c66c */
  scrc_h_posit.l = lXwk; /* Line 719, Address: 0x102c674 */
  ldXwk.l = lXwk; /* Line 720, Address: 0x102c67c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 721, Address: 0x102c680 */
  ldXwk.w.l &= 16; /* Line 722, Address: 0x102c6a4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 723, Address: 0x102c6b0 */

  if (!ldXwk.b.b4) { /* Line 725, Address: 0x102c6cc */
    scrc_h_count ^= 16; /* Line 726, Address: 0x102c6d8 */
    if (lXwk - lXsv < 0) { /* Line 727, Address: 0x102c6ec */
      scrflagc.b.h |= 1 << flgbit; /* Line 728, Address: 0x102c6f8 */
    } /* Line 729, Address: 0x102c71c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 731, Address: 0x102c724 */
    }
  }


} /* Line 736, Address: 0x102c74c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 754, Address: 0x102c760 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 758, Address: 0x102c774 */
  lXwk = lXsv + xoffs; /* Line 759, Address: 0x102c77c */
  scrz_h_posit.l = lXwk; /* Line 760, Address: 0x102c784 */
  ldXwk.l = lXwk; /* Line 761, Address: 0x102c78c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 762, Address: 0x102c790 */
  ldXwk.w.l &= 16; /* Line 763, Address: 0x102c7b4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 764, Address: 0x102c7c0 */

  if (!ldXwk.b.b4) { /* Line 766, Address: 0x102c7dc */
    scrz_h_count ^= 16; /* Line 767, Address: 0x102c7e8 */
    if (lXwk - lXsv < 0) { /* Line 768, Address: 0x102c7fc */
      scrflagz.b.h |= 1 << flgbit; /* Line 769, Address: 0x102c808 */
    } /* Line 770, Address: 0x102c82c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 772, Address: 0x102c834 */
    }
  }


} /* Line 777, Address: 0x102c85c */














static void scroll_h() { /* Line 792, Address: 0x102c870 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 796, Address: 0x102c880 */

  scrh_move(); /* Line 798, Address: 0x102c890 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 799, Address: 0x102c898 */
  if (!bXwk) { /* Line 800, Address: 0x102c8cc */
    scra_h_count ^= 16; /* Line 801, Address: 0x102c8d4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 802, Address: 0x102c8e8 */
      scrflaga.b.h |= 4; /* Line 803, Address: 0x102c90c */
    } else { /* Line 804, Address: 0x102c920 */
      scrflaga.b.h |= 8; /* Line 805, Address: 0x102c928 */
    }
  }


} /* Line 810, Address: 0x102c93c */
















static void scrh_move() { /* Line 827, Address: 0x102c960 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 830, Address: 0x102c968 */
  if (xwk == 0) { /* Line 831, Address: 0x102c9b0 */

    scra_hz = 0; /* Line 833, Address: 0x102c9c0 */
    return; /* Line 834, Address: 0x102c9c8 */
  } else if (xwk < 0) { /* Line 835, Address: 0x102c9d0 */

    if (xwk < -16) { /* Line 837, Address: 0x102c9e0 */
      xwk = -16; /* Line 838, Address: 0x102c9f4 */
    }


    xwk += scra_h_posit.w.h; /* Line 842, Address: 0x102ca00 */
    if (xwk < scralim_left) { /* Line 843, Address: 0x102ca14 */
      xwk = scralim_left; /* Line 844, Address: 0x102ca38 */
    }
  } /* Line 846, Address: 0x102ca48 */
  else {
    if (xwk > 16) { /* Line 848, Address: 0x102ca50 */
      xwk = 16; /* Line 849, Address: 0x102ca64 */
    }


    xwk += scra_h_posit.w.h; /* Line 853, Address: 0x102ca70 */
    if (xwk > scralim_right) { /* Line 854, Address: 0x102ca84 */
      xwk = scralim_right; /* Line 855, Address: 0x102caa8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 860, Address: 0x102cab8 */
  scra_h_posit.w.h = xwk; /* Line 861, Address: 0x102cae8 */
} /* Line 862, Address: 0x102caf0 */














static void scroll_v() { /* Line 877, Address: 0x102cb00 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 880, Address: 0x102cb0c */
  if (actwk[0].cddat & 4) { /* Line 881, Address: 0x102cb40 */
    ywk -= 5; /* Line 882, Address: 0x102cb58 */
  }


  if (actwk[0].cddat & 2) { /* Line 886, Address: 0x102cb64 */
    ywk += 32; /* Line 887, Address: 0x102cb7c */
    if (ywk < scra_vline) { /* Line 888, Address: 0x102cb88 */
      ywk -= scra_vline; /* Line 889, Address: 0x102cbac */
      sv_move_main2(ywk); /* Line 890, Address: 0x102cbc0 */
      return; /* Line 891, Address: 0x102cbcc */
    } else if (ywk >= scra_vline + 64) { /* Line 892, Address: 0x102cbd4 */
      ywk -= scra_vline + 64; /* Line 893, Address: 0x102cbfc */
      sv_move_main2(ywk); /* Line 894, Address: 0x102cc24 */
      return; /* Line 895, Address: 0x102cc30 */
    }
    ywk -= scra_vline + 64; /* Line 897, Address: 0x102cc38 */
    if (!limmoveflag) goto label1; /* Line 898, Address: 0x102cc60 */
    sv_move_sub2(); /* Line 899, Address: 0x102cc70 */
    return; /* Line 900, Address: 0x102cc78 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 905, Address: 0x102cc80 */
    sv_move_main(ywk); /* Line 906, Address: 0x102ccac */
    return; /* Line 907, Address: 0x102ccb8 */
  } else if (!limmoveflag) goto label1; /* Line 908, Address: 0x102ccc0 */
  sv_move_sub2(); /* Line 909, Address: 0x102ccd0 */
  return; /* Line 910, Address: 0x102ccd8 */



label1:
  scra_vz = 0; /* Line 915, Address: 0x102cce0 */
} /* Line 916, Address: 0x102cce8 */













static void sv_move_main(short yPos) { /* Line 930, Address: 0x102cd00 */
  short spdwk;

  if (scra_vline == 96) { /* Line 933, Address: 0x102cd10 */
    if (actwk[0].mspeed.w < 0) { /* Line 934, Address: 0x102cd2c */
      spdwk = -actwk[0].mspeed.w; /* Line 935, Address: 0x102cd44 */
    } else { /* Line 936, Address: 0x102cd68 */
      spdwk = actwk[0].mspeed.w; /* Line 937, Address: 0x102cd70 */
    }


    if (spdwk >= 2048) { /* Line 941, Address: 0x102cd80 */
      sv_move_main2(yPos); /* Line 942, Address: 0x102cd94 */
    } /* Line 943, Address: 0x102cda0 */
    else {

      if (yPos > 6) { /* Line 946, Address: 0x102cda8 */
        sv_move_plus(1536); /* Line 947, Address: 0x102cdc0 */
      } else if (yPos < -6) { /* Line 948, Address: 0x102cdcc */
        sv_move_minus(1536); /* Line 949, Address: 0x102cdec */
      } /* Line 950, Address: 0x102cdf8 */
      else sv_move_sub(yPos); /* Line 951, Address: 0x102ce00 */
    }
  } /* Line 953, Address: 0x102ce0c */
  else {
    if (yPos > 2) { /* Line 955, Address: 0x102ce14 */
      sv_move_plus(512); /* Line 956, Address: 0x102ce2c */
    } else if (yPos < -2) { /* Line 957, Address: 0x102ce38 */
      sv_move_minus(512); /* Line 958, Address: 0x102ce58 */
    } /* Line 959, Address: 0x102ce64 */
    else sv_move_sub(yPos); /* Line 960, Address: 0x102ce6c */
  }

} /* Line 963, Address: 0x102ce78 */













static void sv_move_main2(short yPos) { /* Line 977, Address: 0x102ce90 */
  short spdwk;

  spdwk = 4096; /* Line 980, Address: 0x102cea0 */

  if (yPos > 16) { /* Line 982, Address: 0x102ceac */
    sv_move_plus(spdwk); /* Line 983, Address: 0x102cec4 */
  } else if (yPos < -16) { /* Line 984, Address: 0x102ced0 */
    sv_move_minus(spdwk); /* Line 985, Address: 0x102cef0 */
  } else { /* Line 986, Address: 0x102cefc */
    sv_move_sub(yPos); /* Line 987, Address: 0x102cf04 */
  }
} /* Line 989, Address: 0x102cf10 */














static void sv_move_sub(short yPos) { /* Line 1004, Address: 0x102cf30 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1007, Address: 0x102cf3c */
  if (yPos < 0) { /* Line 1008, Address: 0x102cf68 */
    scrv_up_ch(lSpd); /* Line 1009, Address: 0x102cf7c */
  } else { /* Line 1010, Address: 0x102cf88 */
    scrv_down_ch(lSpd); /* Line 1011, Address: 0x102cf90 */
  }
} /* Line 1013, Address: 0x102cf9c */



static void sv_move_sub2() { /* Line 1017, Address: 0x102cfb0 */
  limmoveflag = 0; /* Line 1018, Address: 0x102cfb8 */

  sv_move_sub(0); /* Line 1020, Address: 0x102cfc0 */
} /* Line 1021, Address: 0x102cfcc */













static void sv_move_minus(short speed) { /* Line 1035, Address: 0x102cfe0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1038, Address: 0x102cfec */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1039, Address: 0x102d010 */
  scrv_up_ch(lSpd); /* Line 1040, Address: 0x102d034 */
} /* Line 1041, Address: 0x102d040 */














static void scrv_up_ch(int_union lSpd) { /* Line 1056, Address: 0x102d050 */
  if (lSpd.w.l <= scralim_up) { /* Line 1057, Address: 0x102d05c */
    if (lSpd.w.l > -256) { /* Line 1058, Address: 0x102d084 */

      lSpd.w.l = scralim_up; /* Line 1060, Address: 0x102d09c */
    } else { /* Line 1061, Address: 0x102d0a8 */
      lSpd.w.l &= 2047; /* Line 1062, Address: 0x102d0b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1063, Address: 0x102d0bc */
      scra_v_posit.w.h &= 2047; /* Line 1064, Address: 0x102d0d0 */
      scrb_v_posit.w.h &= 1023; /* Line 1065, Address: 0x102d0e4 */
    }
  }

  scrv_move(lSpd); /* Line 1069, Address: 0x102d0f8 */
} /* Line 1070, Address: 0x102d104 */













static void sv_move_plus(short sSpd) { /* Line 1084, Address: 0x102d120 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1087, Address: 0x102d12c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1088, Address: 0x102d14c */
  scrv_down_ch(lSpd); /* Line 1089, Address: 0x102d170 */
} /* Line 1090, Address: 0x102d17c */














static void scrv_down_ch(int_union lSpd) { /* Line 1105, Address: 0x102d190 */
  if (lSpd.w.l >= scralim_down) { /* Line 1106, Address: 0x102d19c */
    if (lSpd.w.l < 2048) { /* Line 1107, Address: 0x102d1c4 */

      lSpd.w.l = scralim_down; /* Line 1109, Address: 0x102d1dc */
    } else { /* Line 1110, Address: 0x102d1e8 */
      lSpd.w.l -= 2048; /* Line 1111, Address: 0x102d1f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1112, Address: 0x102d1fc */
      scra_v_posit.w.h -= 2048; /* Line 1113, Address: 0x102d210 */
      scrb_v_posit.w.h &= 1023; /* Line 1114, Address: 0x102d224 */
    }
  }

  scrv_move(lSpd); /* Line 1118, Address: 0x102d238 */
} /* Line 1119, Address: 0x102d244 */
















static void scrv_move(int_union lSpd) { /* Line 1136, Address: 0x102d260 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1140, Address: 0x102d270 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1141, Address: 0x102d280 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1142, Address: 0x102d2a4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1143, Address: 0x102d2b8 */
  scra_vz = spdwk.w.l; /* Line 1144, Address: 0x102d2d0 */

  scra_v_posit.l = lSpd.l; /* Line 1146, Address: 0x102d2dc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1148, Address: 0x102d2e8 */
  if (!ywk) { /* Line 1149, Address: 0x102d324 */
    scra_v_count ^= 16; /* Line 1150, Address: 0x102d32c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1151, Address: 0x102d340 */
    if (ywk < 0) { /* Line 1152, Address: 0x102d36c */
      scrflaga.b.h |= 1; /* Line 1153, Address: 0x102d37c */
    } else { /* Line 1154, Address: 0x102d390 */
      scrflaga.b.h |= 2; /* Line 1155, Address: 0x102d398 */
    }
  }


} /* Line 1160, Address: 0x102d3ac */

















void scrollwrt() { /* Line 1178, Address: 0x102d3c0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1187, Address: 0x102d3e0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1188, Address: 0x102d3e4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1189, Address: 0x102d3f0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1190, Address: 0x102d3fc */
  pScrFlag = &scrflagbw.b.h; /* Line 1191, Address: 0x102d404 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1192, Address: 0x102d40c */

  VramBase = 16384; /* Line 1194, Address: 0x102d420 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1195, Address: 0x102d424 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1196, Address: 0x102d430 */
  pMapWk = (unsigned char*)mapwka; /* Line 1197, Address: 0x102d43c */
  pScrFlag = &scrflagaw.b.h; /* Line 1198, Address: 0x102d444 */

  if (*pScrFlag) { /* Line 1200, Address: 0x102d44c */
    if (*pScrFlag & 1) { /* Line 1201, Address: 0x102d458 */
      *pScrFlag &= 254; /* Line 1202, Address: 0x102d46c */

      lD4.l = -16; /* Line 1204, Address: 0x102d478 */
      wD5 = 65520; /* Line 1205, Address: 0x102d480 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1207, Address: 0x102d488 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1209, Address: 0x102d4a8 */
    }




    if (*pScrFlag & 2) { /* Line 1215, Address: 0x102d4d4 */
      *pScrFlag &= 253; /* Line 1216, Address: 0x102d4e8 */

      lD4.l = 224; /* Line 1218, Address: 0x102d4f4 */
      wD5 = 65520; /* Line 1219, Address: 0x102d4fc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1220, Address: 0x102d504 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1222, Address: 0x102d524 */
    }




    if (*pScrFlag & 4) { /* Line 1228, Address: 0x102d550 */
      *pScrFlag &= 251; /* Line 1229, Address: 0x102d564 */

      lD4.l = -16; /* Line 1231, Address: 0x102d570 */
      wD5 = 65520; /* Line 1232, Address: 0x102d578 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1233, Address: 0x102d580 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1235, Address: 0x102d5a0 */
    }




    if (*pScrFlag & 8) { /* Line 1241, Address: 0x102d5cc */
      *pScrFlag &= 247; /* Line 1242, Address: 0x102d5e0 */

      lD4.l = -16; /* Line 1244, Address: 0x102d5ec */
      wD5 = 320; /* Line 1245, Address: 0x102d5f4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1246, Address: 0x102d5fc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1248, Address: 0x102d61c */
    }
  }






} /* Line 1257, Address: 0x102d648 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1274, Address: 0x102d670 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1285, Address: 0x102d69c */

  if (*pScrFlag & 1) { /* Line 1287, Address: 0x102d6a4 */
    *pScrFlag &= 254; /* Line 1288, Address: 0x102d6bc */
  } /* Line 1289, Address: 0x102d6d0 */
  else {
    *pScrFlag &= 254; /* Line 1291, Address: 0x102d6d8 */

    if (*pScrFlag & 2) { /* Line 1293, Address: 0x102d6ec */
      *pScrFlag &= 253; /* Line 1294, Address: 0x102d704 */
      lD4.w.l = 224; /* Line 1295, Address: 0x102d718 */
    } /* Line 1296, Address: 0x102d720 */
    else {
      *pScrFlag &= 253; /* Line 1298, Address: 0x102d728 */
      goto label1; /* Line 1299, Address: 0x102d73c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1304, Address: 0x102d744 */
  wD0 &= 127; /* Line 1305, Address: 0x102d794 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1306, Address: 0x102d79c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1312, Address: 0x102d7bc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1313, Address: 0x102d7dc */
  if (wD0 != 0) { /* Line 1314, Address: 0x102d800 */
    wD5 = 65520; /* Line 1315, Address: 0x102d80c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1316, Address: 0x102d814 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1318, Address: 0x102d834 */



  } /* Line 1322, Address: 0x102d860 */
  else {

    wD5 = 0; /* Line 1325, Address: 0x102d868 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1326, Address: 0x102d86c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1330, Address: 0x102d88c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1337, Address: 0x102d8b8 */






    lD4.l = -16; /* Line 1344, Address: 0x102d8cc */
    wD5 = 65520; /* Line 1345, Address: 0x102d8d4 */
    if (*pScrFlag & 168) { /* Line 1346, Address: 0x102d8dc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1347, Address: 0x102d8f4 */
      wD5 = 320; /* Line 1348, Address: 0x102d914 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1352, Address: 0x102d91c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1354, Address: 0x102d94c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1355, Address: 0x102d958 */



    for (i = 0; i < 16; ++i) { /* Line 1359, Address: 0x102d968 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1360, Address: 0x102d974 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1361, Address: 0x102d994 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1362, Address: 0x102d9cc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1363, Address: 0x102d9ec */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1365, Address: 0x102da10 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1368, Address: 0x102da34 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1370, Address: 0x102da54 */
      }
      lD4.w.l += 16; /* Line 1372, Address: 0x102da68 */
    } /* Line 1373, Address: 0x102da74 */
    *pScrFlag = 0; /* Line 1374, Address: 0x102da84 */
  }
} /* Line 1376, Address: 0x102da8c */





void scrollwrtc() {} /* Line 1382, Address: 0x102dac0 */




void scrollwrtz() {} /* Line 1387, Address: 0x102dad0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1405, Address: 0x102dae0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1418, Address: 0x102db08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1421, Address: 0x102db28 */
    pTilePoint->x += 2; /* Line 1422, Address: 0x102db3c */
    if (pTilePoint->x >= 64) { /* Line 1423, Address: 0x102db50 */
      pTilePoint->x -= 64; /* Line 1424, Address: 0x102db64 */
    }
    xOffs += 16; /* Line 1426, Address: 0x102db78 */
  } while (--lpcnt >= 0); /* Line 1427, Address: 0x102db84 */
} /* Line 1428, Address: 0x102db98 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1432, Address: 0x102dbb0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1436, Address: 0x102dbd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1439, Address: 0x102dbf8 */
    pTilePoint->x += 2; /* Line 1440, Address: 0x102dc0c */
    if (pTilePoint->x >= 64) { /* Line 1441, Address: 0x102dc20 */
      pTilePoint->x -= 64; /* Line 1442, Address: 0x102dc34 */
    }
    xOffs += 16; /* Line 1444, Address: 0x102dc48 */
  } while (--lpcnt >= 0); /* Line 1445, Address: 0x102dc54 */
} /* Line 1446, Address: 0x102dc68 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1466, Address: 0x102dc80 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1470, Address: 0x102dca8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1473, Address: 0x102dcc8 */
    pTilePoint->y += 2; /* Line 1474, Address: 0x102dcdc */
    if (pTilePoint->y >= 32) { /* Line 1475, Address: 0x102dcec */
      pTilePoint->y -= 32; /* Line 1476, Address: 0x102dd00 */
    }
    yOffs += 16; /* Line 1478, Address: 0x102dd10 */
  } while (--lpcnt >= 0); /* Line 1479, Address: 0x102dd1c */
} /* Line 1480, Address: 0x102dd30 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1499, Address: 0x102dd40 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1505, Address: 0x102dd74 */

    base = 1; /* Line 1507, Address: 0x102dd84 */
  } /* Line 1508, Address: 0x102dd88 */
  else if (VramBase == 16384) { /* Line 1509, Address: 0x102dd90 */

    base = 0; /* Line 1511, Address: 0x102dda0 */
  }
  x = pTilePoint->x; /* Line 1513, Address: 0x102dda4 */
  y = pTilePoint->y; /* Line 1514, Address: 0x102ddac */


  frip = BlkIndex & 6144; /* Line 1517, Address: 0x102ddb4 */
  BlkIndex &= 1023; /* Line 1518, Address: 0x102ddbc */
  if (frip == 6144) { /* Line 1519, Address: 0x102ddc8 */

    p0 = 3, p1 = 2; /* Line 1521, Address: 0x102ddd4 */
    p2 = 1, p3 = 0; /* Line 1522, Address: 0x102dddc */
  } /* Line 1523, Address: 0x102dde4 */
  else if (frip & 4096) { /* Line 1524, Address: 0x102ddec */

    p0 = 2, p1 = 3; /* Line 1526, Address: 0x102ddf8 */
    p2 = 0, p3 = 1; /* Line 1527, Address: 0x102de00 */
  } /* Line 1528, Address: 0x102de08 */
  else if (frip & 2048) { /* Line 1529, Address: 0x102de10 */

    p0 = 1, p1 = 0; /* Line 1531, Address: 0x102de1c */
    p2 = 3, p3 = 2; /* Line 1532, Address: 0x102de24 */
  } /* Line 1533, Address: 0x102de2c */
  else {

    p0 = 0, p1 = 1; /* Line 1536, Address: 0x102de34 */
    p2 = 2, p3 = 3; /* Line 1537, Address: 0x102de3c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1540, Address: 0x102de44 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1541, Address: 0x102de88 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1542, Address: 0x102decc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1543, Address: 0x102df10 */

} /* Line 1545, Address: 0x102df54 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1562, Address: 0x102df90 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1563, Address: 0x102dfb0 */
} /* Line 1564, Address: 0x102dfd0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1566, Address: 0x102dfe0 */
  wH_posiw = 0; /* Line 1567, Address: 0x102e000 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1568, Address: 0x102e004 */
} /* Line 1569, Address: 0x102e024 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1576, Address: 0x102e040 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1582, Address: 0x102e070 */
  yOffs += wV_posiw; /* Line 1583, Address: 0x102e080 */





  if ((short)xOffs < 0) /* Line 1589, Address: 0x102e090 */
    xOffs = 0; /* Line 1590, Address: 0x102e0ac */
  if ((short)yOffs < 0) /* Line 1591, Address: 0x102e0b0 */
    yOffs = 0; /* Line 1592, Address: 0x102e0cc */
  if ((short)xOffs >= 16384) /* Line 1593, Address: 0x102e0d0 */
    xOffs = 16383; /* Line 1594, Address: 0x102e0f0 */
  if ((short)yOffs >= 2048) /* Line 1595, Address: 0x102e0f8 */
    yOffs = 2047; /* Line 1596, Address: 0x102e118 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1597, Address: 0x102e120 */
  if (i < 0) i = 0; /* Line 1598, Address: 0x102e168 */

  ScreenNo = pMapWk[i] & 127; /* Line 1600, Address: 0x102e174 */

  if (ScreenNo) { /* Line 1602, Address: 0x102e190 */




    xOffs &= 32767; /* Line 1607, Address: 0x102e198 */
    yOffs &= 32767; /* Line 1608, Address: 0x102e1a4 */


    xBlk = xOffs; /* Line 1611, Address: 0x102e1b0 */
    xBlk %= 256; /* Line 1612, Address: 0x102e1b8 */
    xBlk /= 16; /* Line 1613, Address: 0x102e1d8 */
    yBlk = yOffs; /* Line 1614, Address: 0x102e1f4 */
    yBlk %= 256; /* Line 1615, Address: 0x102e1fc */
    yBlk /= 16; /* Line 1616, Address: 0x102e21c */

    lpw = pmapwk; /* Line 1618, Address: 0x102e238 */
    lpw += xBlk; /* Line 1619, Address: 0x102e240 */
    lpw += yBlk * 16; /* Line 1620, Address: 0x102e248 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1621, Address: 0x102e254 */
    *pIndex = *lpw; /* Line 1622, Address: 0x102e26c */

    return 1; /* Line 1624, Address: 0x102e27c */
  }

  *pIndex = 0; /* Line 1627, Address: 0x102e288 */
  return 0; /* Line 1628, Address: 0x102e290 */
} /* Line 1629, Address: 0x102e294 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1649, Address: 0x102e2c0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1657, Address: 0x102e2e8 */
  if (ScreenNo) { /* Line 1658, Address: 0x102e34c */





    xBlk = xOffs; /* Line 1664, Address: 0x102e354 */
    xBlk %= 256; /* Line 1665, Address: 0x102e35c */
    xBlk /= 16; /* Line 1666, Address: 0x102e37c */
    yBlk = yOffs; /* Line 1667, Address: 0x102e398 */
    yBlk %= 256; /* Line 1668, Address: 0x102e3a0 */
    yBlk /= 16; /* Line 1669, Address: 0x102e3c0 */


    lpw = pmapwk; /* Line 1672, Address: 0x102e3dc */
    lpw += xBlk; /* Line 1673, Address: 0x102e3e4 */
    lpw += yBlk * 16; /* Line 1674, Address: 0x102e3ec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1675, Address: 0x102e3f8 */
    *ppBlockNo = lpw; /* Line 1676, Address: 0x102e410 */
    *pIndex = *lpw; /* Line 1677, Address: 0x102e418 */




    return 1; /* Line 1682, Address: 0x102e428 */
  }

  *pIndex = 0; /* Line 1685, Address: 0x102e434 */
  return 0; /* Line 1686, Address: 0x102e43c */
} /* Line 1687, Address: 0x102e440 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1701, Address: 0x102e460 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1708, Address: 0x102e47c */
  pMapWk = (unsigned char*)mapwka; /* Line 1709, Address: 0x102e480 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1710, Address: 0x102e488 */
    *pBlockIndex = BlockNo; /* Line 1711, Address: 0x102e4ac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1712, Address: 0x102e4b8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1713, Address: 0x102e4d0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1714, Address: 0x102e4e4 */
    }
  }


} /* Line 1719, Address: 0x102e4fc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1733, Address: 0x102e520 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1734, Address: 0x102e52c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1735, Address: 0x102e558 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1736, Address: 0x102e5a4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1737, Address: 0x102e5d0 */

          return 0; /* Line 1739, Address: 0x102e61c */
        }
      }
    }
  }

  return 1; /* Line 1745, Address: 0x102e628 */
} /* Line 1746, Address: 0x102e62c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1763, Address: 0x102e640 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1764, Address: 0x102e65c */

} /* Line 1766, Address: 0x102e678 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1768, Address: 0x102e690 */
  wH_posiw = 0; /* Line 1769, Address: 0x102e6ac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1770, Address: 0x102e6b0 */

} /* Line 1772, Address: 0x102e6cc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1774, Address: 0x102e6e0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x102e6f4 */

} /* Line 1777, Address: 0x102e710 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102e720 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x102e73c */

} /* Line 1782, Address: 0x102e758 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x102e770 */
  xOffs += wH_posiw; /* Line 1785, Address: 0x102e788 */
  yOffs += wV_posiw; /* Line 1786, Address: 0x102e798 */
  yOffs &= 240; /* Line 1787, Address: 0x102e7a8 */
  xOffs &= 496; /* Line 1788, Address: 0x102e7b4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1790, Address: 0x102e7c0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1791, Address: 0x102e7ec */


} /* Line 1794, Address: 0x102e818 */















void mapwrt() { /* Line 1810, Address: 0x102e830 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1817, Address: 0x102e848 */
  wV_posiw = scra_v_posit.w.h; /* Line 1818, Address: 0x102e854 */
  pMapWk = (unsigned char*)mapwka; /* Line 1819, Address: 0x102e860 */
  VramBase = 16384; /* Line 1820, Address: 0x102e868 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1821, Address: 0x102e86c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1825, Address: 0x102e884 */
  VramBase = 24576; /* Line 1826, Address: 0x102e88c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1827, Address: 0x102e890 */

} /* Line 1829, Address: 0x102e8a0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1832, Address: 0x102e8c0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1833, Address: 0x102e8d8 */
} /* Line 1834, Address: 0x102e8f8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1839, Address: 0x102e910 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1843, Address: 0x102e930 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1846, Address: 0x102e94c */



    wD4 += 16; /* Line 1850, Address: 0x102e974 */
  } while ((short)--wD6 >= 0); /* Line 1851, Address: 0x102e980 */

} /* Line 1853, Address: 0x102e9a8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1859, Address: 0x102e9c0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1862, Address: 0x102e9dc */
  wD6 = 15; /* Line 1863, Address: 0x102e9e4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1866, Address: 0x102e9ec */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1868, Address: 0x102ea10 */
    wD4 += 16; /* Line 1869, Address: 0x102ea30 */
  } while ((short)--wD6 >= 0); /* Line 1870, Address: 0x102ea38 */
} /* Line 1871, Address: 0x102ea5c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1897, Address: 0x102ea80 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1902, Address: 0x102eaa8 */
  wD0 = pWrttbl[wD0]; /* Line 1903, Address: 0x102eab8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1905, Address: 0x102ead4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1906, Address: 0x102eaf8 */
  if (wD0) { /* Line 1907, Address: 0x102eb20 */
    wD5 = 65520; /* Line 1908, Address: 0x102eb2c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1909, Address: 0x102eb34 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1912, Address: 0x102eb50 */



  } /* Line 1916, Address: 0x102eb78 */
  else {

    wD5 = 0; /* Line 1919, Address: 0x102eb80 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1920, Address: 0x102eb84 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1924, Address: 0x102eba0 */
  }





} /* Line 1931, Address: 0x102ebc8 */










void mapinit() { /* Line 1942, Address: 0x102ebf0 */

  colorset2(mapinittbl.colorno2); /* Line 1944, Address: 0x102ebf8 */
  colorset(mapinittbl.colorno2); /* Line 1945, Address: 0x102ec0c */


  if (play_start & 2) divdevset(); /* Line 1948, Address: 0x102ec20 */
} /* Line 1949, Address: 0x102ec40 */




void mapset() {} /* Line 1954, Address: 0x102ec50 */



void divdevset() {} /* Line 1958, Address: 0x102ec60 */



void enecginit() {} /* Line 1962, Address: 0x102ec70 */
