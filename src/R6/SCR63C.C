#include "..\EQU.H"
#include "SCR61A.H"
#include "..\ETC.H"
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

static unsigned char z81awrttbl[49] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4
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
short scr_dir_tbl[6] = { 4, 0, 3479, 0, 1808, 96 };
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
short playpositbl[1][2] = { { 48, 1580 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[64][8];
extern unsigned char mapwkb[64][8];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;









































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 147, Address: 0x1029a70 */
    return &actwk[0]; /* Line 148, Address: 0x1029a84 */
  else
    return &actwk[1]; /* Line 150, Address: 0x1029a94 */

} /* Line 152, Address: 0x1029a9c */





































void scr_set() { /* Line 190, Address: 0x1029ab0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x1029abc */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x1029ad0 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x1029ae4 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x1029aec */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x1029af4 */
  ++pScrTbl; /* Line 199, Address: 0x1029b00 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x1029b04 */
  ++pScrTbl; /* Line 201, Address: 0x1029b18 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x1029b1c */
  ++pScrTbl; /* Line 203, Address: 0x1029b30 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x1029b34 */
  ++pScrTbl; /* Line 205, Address: 0x1029b48 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x1029b4c */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x1029b60 */
  ++pScrTbl; /* Line 208, Address: 0x1029b80 */
  scra_h_count = 16; /* Line 209, Address: 0x1029b84 */
  scra_v_count = 16; /* Line 210, Address: 0x1029b90 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x1029b9c */
  scra_hline = 160; /* Line 213, Address: 0x1029ba8 */

  playposiset(); /* Line 215, Address: 0x1029bb4 */
} /* Line 216, Address: 0x1029bbc */
















































static void playposiset() { /* Line 265, Address: 0x1029bd0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 268, Address: 0x1029be4 */
    playload(); /* Line 269, Address: 0x1029bf4 */
    xwk = actwk[0].xposi.w.h; /* Line 270, Address: 0x1029bfc */

    if (actwk[0].yposi.w.h > 0) { /* Line 272, Address: 0x1029c0c */
      ywk = actwk[0].yposi.w.h; /* Line 273, Address: 0x1029c24 */
    } else { /* Line 274, Address: 0x1029c34 */
      ywk = 0; /* Line 275, Address: 0x1029c3c */
    }
  } /* Line 277, Address: 0x1029c40 */
  else {
    if (demoflag.w & -32768) { /* Line 279, Address: 0x1029c48 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 280, Address: 0x1029c68 */
    } /* Line 281, Address: 0x1029c8c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 283, Address: 0x1029c94 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 287, Address: 0x1029cb4 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 288, Address: 0x1029cc8 */
  }


  if (xwk > 160) { /* Line 292, Address: 0x1029cdc */
    xwk -= 160; /* Line 293, Address: 0x1029cf0 */
  } else { /* Line 294, Address: 0x1029cfc */
    xwk = 0; /* Line 295, Address: 0x1029d04 */
  }


  if (xwk > scralim_right) { /* Line 299, Address: 0x1029d08 */
    xwk = scralim_right; /* Line 300, Address: 0x1029d2c */
  }


  scra_h_posit.w.h = xwk; /* Line 304, Address: 0x1029d3c */

  if (ywk > 96) { /* Line 306, Address: 0x1029d44 */
    ywk -= 96; /* Line 307, Address: 0x1029d58 */
  } else { /* Line 308, Address: 0x1029d64 */
    ywk = 0; /* Line 309, Address: 0x1029d6c */
  }


  if (ywk > scralim_down) { /* Line 313, Address: 0x1029d70 */
    ywk = scralim_down; /* Line 314, Address: 0x1029d94 */
  }


  scra_v_posit.w.h = ywk; /* Line 318, Address: 0x1029da4 */

  scrbinit(xwk, ywk); /* Line 320, Address: 0x1029dac */


  loopmapno = playmapnotbl[0]; /* Line 323, Address: 0x1029dbc */
  loopmapno2 = playmapnotbl[1]; /* Line 324, Address: 0x1029dcc */
  ballmapno = playmapnotbl[2]; /* Line 325, Address: 0x1029ddc */
  ballmapno2 = playmapnotbl[3]; /* Line 326, Address: 0x1029dec */
} /* Line 327, Address: 0x1029dfc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 348, Address: 0x1029e20 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 351, Address: 0x1029e2c */
  lYwk.w.l = 0; /* Line 352, Address: 0x1029e34 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 354, Address: 0x1029e38 */
  scrb_v_posit.l = lYwk.l; /* Line 355, Address: 0x1029e44 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x1029e50 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 357, Address: 0x1029e5c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 359, Address: 0x1029e68 */
  scrc_h_posit.w.h = sXpos; /* Line 360, Address: 0x1029e84 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 362, Address: 0x1029e90 */
  scrz_h_posit.w.h = sXpos; /* Line 363, Address: 0x1029eac */

  sXpos = (unsigned short)sXpos >> 2; /* Line 365, Address: 0x1029eb8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 366, Address: 0x1029ed4 */
} /* Line 367, Address: 0x1029ef8 */















void scroll() { /* Line 383, Address: 0x1029f10 */
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

  if (scroll_start.b.h) return; /* Line 395, Address: 0x1029f2c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 400, Address: 0x1029f3c */

  scrchk(); /* Line 402, Address: 0x1029f68 */

  scroll_h(); /* Line 404, Address: 0x1029f70 */
  scroll_v(); /* Line 405, Address: 0x1029f78 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 407, Address: 0x1029f80 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 408, Address: 0x1029f90 */


  lXwk = scra_hz << 6; /* Line 411, Address: 0x1029fa0 */
  scrollz_h(lXwk, 6); /* Line 412, Address: 0x1029fb4 */

  lXwk = scra_hz << 7; /* Line 414, Address: 0x1029fc4 */
  scrollc_h(lXwk, 4); /* Line 415, Address: 0x1029fd8 */

  lXwk = (scra_hz << 4) * 3; /* Line 417, Address: 0x1029fe8 */
  scrollb_h(lXwk, 2); /* Line 418, Address: 0x102a004 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 420, Address: 0x102a014 */


  scrollb_v(lYwk); /* Line 423, Address: 0x102a028 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 425, Address: 0x102a038 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 427, Address: 0x102a060 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 428, Address: 0x102a098 */

  psHscw = hscrollwork; /* Line 430, Address: 0x102a0ac */

  z61aline(&psHscw); /* Line 432, Address: 0x102a0b8 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 434, Address: 0x102a0c4 */
  for (i = 0; i < 24; ++i) { /* Line 435, Address: 0x102a0e4 */

    *psHscw++ = ldwk.w.l; /* Line 437, Address: 0x102a0f0 */
  } /* Line 438, Address: 0x102a104 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 440, Address: 0x102a114 */
  for (i = 0; i < 46; ++i) { /* Line 441, Address: 0x102a134 */

    *psHscw++ = ldwk.w.l; /* Line 443, Address: 0x102a140 */
  } /* Line 444, Address: 0x102a154 */

  pHscrbuf = lphscrollbuff; /* Line 446, Address: 0x102a164 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 447, Address: 0x102a170 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 448, Address: 0x102a1a0 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 449, Address: 0x102a1d0 */
} /* Line 450, Address: 0x102a1ec */













static void z61aline(short** ppHscw) { /* Line 464, Address: 0x102a210 */
  char z81ascrtbl[9] = { /* Line 465, Address: 0x102a238 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk, lHwk;

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 472, Address: 0x102a264 */
  radwk = 0; /* Line 473, Address: 0x102a288 */
  sXwk = scrb_h_posit.w.h; /* Line 474, Address: 0x102a28c */

  *ppHscw += 26; /* Line 476, Address: 0x102a29c */

  for (i = 8; i >= 0; --i) { /* Line 478, Address: 0x102a2b0 */

    sinset(radwk, &sinwk, &coswk); /* Line 480, Address: 0x102a2bc */
    lHwk = (256 - coswk) * lXwk; /* Line 481, Address: 0x102a2d0 */
    lHwk = (unsigned int)lHwk >> 8; /* Line 482, Address: 0x102a2e8 */
    hwk = -(lHwk + sXwk); /* Line 483, Address: 0x102a2ec */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 484, Address: 0x102a30c */

      --*ppHscw; /* Line 486, Address: 0x102a324 */
      **ppHscw = hwk; /* Line 487, Address: 0x102a338 */
    } /* Line 488, Address: 0x102a344 */

    radwk += 6; /* Line 490, Address: 0x102a350 */
  } /* Line 491, Address: 0x102a35c */

  *ppHscw += 26; /* Line 493, Address: 0x102a368 */
} /* Line 494, Address: 0x102a37c */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 515, Address: 0x102a3b0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 519, Address: 0x102a3cc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 520, Address: 0x102a3d0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 522, Address: 0x102a3f0 */
    ldwk.w.l = *pHscrwk; /* Line 523, Address: 0x102a40c */
    ++pHscrwk; /* Line 524, Address: 0x102a418 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 526, Address: 0x102a424 */
      (*pHscrbuf)->l = ldwk.l; /* Line 527, Address: 0x102a42c */
    } /* Line 528, Address: 0x102a43c */
  } /* Line 529, Address: 0x102a460 */
} /* Line 530, Address: 0x102a480 */









































































































static void scrollb_v(short yPos) { /* Line 636, Address: 0x102a4a0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 639, Address: 0x102a4b0 */
  scrb_v_posit.w.h = yPos; /* Line 640, Address: 0x102a4c0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 641, Address: 0x102a4cc */

  if (!ywk) { /* Line 643, Address: 0x102a504 */
    scrb_v_count ^= 16; /* Line 644, Address: 0x102a50c */
    if (yPos - ysv < 0) { /* Line 645, Address: 0x102a520 */
      scrflagb.b.h |= 1; /* Line 646, Address: 0x102a540 */
    } /* Line 647, Address: 0x102a554 */
    else {
      scrflagb.b.h |= 2; /* Line 649, Address: 0x102a55c */
    }
  }


} /* Line 654, Address: 0x102a570 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 672, Address: 0x102a590 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 676, Address: 0x102a5a4 */
  lXwk = lXsv + xoffs; /* Line 677, Address: 0x102a5ac */
  scrb_h_posit.l = lXwk; /* Line 678, Address: 0x102a5b4 */
  ldXwk.l = lXwk; /* Line 679, Address: 0x102a5bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 680, Address: 0x102a5c0 */
  ldXwk.w.l &= 16; /* Line 681, Address: 0x102a5e4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 682, Address: 0x102a5f0 */

  if (!ldXwk.b.b4) { /* Line 684, Address: 0x102a60c */
    scrb_h_count ^= 16; /* Line 685, Address: 0x102a618 */
    if (lXwk - lXsv < 0) { /* Line 686, Address: 0x102a62c */
      scrflagb.b.h |= 1 << flgbit; /* Line 687, Address: 0x102a638 */
    } /* Line 688, Address: 0x102a65c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 690, Address: 0x102a664 */
    }
  }


} /* Line 695, Address: 0x102a68c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 713, Address: 0x102a6a0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 717, Address: 0x102a6b4 */
  lXwk = lXsv + xoffs; /* Line 718, Address: 0x102a6bc */
  scrc_h_posit.l = lXwk; /* Line 719, Address: 0x102a6c4 */
  ldXwk.l = lXwk; /* Line 720, Address: 0x102a6cc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 721, Address: 0x102a6d0 */
  ldXwk.w.l &= 16; /* Line 722, Address: 0x102a6f4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 723, Address: 0x102a700 */

  if (!ldXwk.b.b4) { /* Line 725, Address: 0x102a71c */
    scrc_h_count ^= 16; /* Line 726, Address: 0x102a728 */
    if (lXwk - lXsv < 0) { /* Line 727, Address: 0x102a73c */
      scrflagc.b.h |= 1 << flgbit; /* Line 728, Address: 0x102a748 */
    } /* Line 729, Address: 0x102a76c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 731, Address: 0x102a774 */
    }
  }


} /* Line 736, Address: 0x102a79c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 754, Address: 0x102a7b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 758, Address: 0x102a7c4 */
  lXwk = lXsv + xoffs; /* Line 759, Address: 0x102a7cc */
  scrz_h_posit.l = lXwk; /* Line 760, Address: 0x102a7d4 */
  ldXwk.l = lXwk; /* Line 761, Address: 0x102a7dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 762, Address: 0x102a7e0 */
  ldXwk.w.l &= 16; /* Line 763, Address: 0x102a804 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 764, Address: 0x102a810 */

  if (!ldXwk.b.b4) { /* Line 766, Address: 0x102a82c */
    scrz_h_count ^= 16; /* Line 767, Address: 0x102a838 */
    if (lXwk - lXsv < 0) { /* Line 768, Address: 0x102a84c */
      scrflagz.b.h |= 1 << flgbit; /* Line 769, Address: 0x102a858 */
    } /* Line 770, Address: 0x102a87c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 772, Address: 0x102a884 */
    }
  }


} /* Line 777, Address: 0x102a8ac */














static void scroll_h() { /* Line 792, Address: 0x102a8c0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 796, Address: 0x102a8d0 */

  scrh_move(); /* Line 798, Address: 0x102a8e0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 799, Address: 0x102a8e8 */
  if (!bXwk) { /* Line 800, Address: 0x102a91c */
    scra_h_count ^= 16; /* Line 801, Address: 0x102a924 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 802, Address: 0x102a938 */
      scrflaga.b.h |= 4; /* Line 803, Address: 0x102a95c */
    } else { /* Line 804, Address: 0x102a970 */
      scrflaga.b.h |= 8; /* Line 805, Address: 0x102a978 */
    }
  }


} /* Line 810, Address: 0x102a98c */
















static void scrh_move() { /* Line 827, Address: 0x102a9b0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 830, Address: 0x102a9b8 */
  if (xwk == 0) { /* Line 831, Address: 0x102aa00 */

    scra_hz = 0; /* Line 833, Address: 0x102aa10 */
    return; /* Line 834, Address: 0x102aa18 */
  } else if (xwk < 0) { /* Line 835, Address: 0x102aa20 */

    if (xwk < -16) { /* Line 837, Address: 0x102aa30 */
      xwk = -16; /* Line 838, Address: 0x102aa44 */
    }


    xwk += scra_h_posit.w.h; /* Line 842, Address: 0x102aa50 */
    if (xwk < scralim_left) { /* Line 843, Address: 0x102aa64 */
      xwk = scralim_left; /* Line 844, Address: 0x102aa88 */
    }
  } /* Line 846, Address: 0x102aa98 */
  else {
    if (xwk > 16) { /* Line 848, Address: 0x102aaa0 */
      xwk = 16; /* Line 849, Address: 0x102aab4 */
    }


    xwk += scra_h_posit.w.h; /* Line 853, Address: 0x102aac0 */
    if (xwk > scralim_right) { /* Line 854, Address: 0x102aad4 */
      xwk = scralim_right; /* Line 855, Address: 0x102aaf8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 860, Address: 0x102ab08 */
  scra_h_posit.w.h = xwk; /* Line 861, Address: 0x102ab38 */
} /* Line 862, Address: 0x102ab40 */














static void scroll_v() { /* Line 877, Address: 0x102ab50 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 880, Address: 0x102ab5c */
  if (actwk[0].cddat & 4) { /* Line 881, Address: 0x102ab90 */
    ywk -= 5; /* Line 882, Address: 0x102aba8 */
  }


  if (actwk[0].cddat & 2) { /* Line 886, Address: 0x102abb4 */
    ywk += 32; /* Line 887, Address: 0x102abcc */
    if (ywk < scra_vline) { /* Line 888, Address: 0x102abd8 */
      ywk -= scra_vline; /* Line 889, Address: 0x102abfc */
      sv_move_main2(ywk); /* Line 890, Address: 0x102ac10 */
      return; /* Line 891, Address: 0x102ac1c */
    } else if (ywk >= scra_vline + 64) { /* Line 892, Address: 0x102ac24 */
      ywk -= scra_vline + 64; /* Line 893, Address: 0x102ac4c */
      sv_move_main2(ywk); /* Line 894, Address: 0x102ac74 */
      return; /* Line 895, Address: 0x102ac80 */
    }
    ywk -= scra_vline + 64; /* Line 897, Address: 0x102ac88 */
    if (!limmoveflag) goto label1; /* Line 898, Address: 0x102acb0 */
    sv_move_sub2(); /* Line 899, Address: 0x102acc0 */
    return; /* Line 900, Address: 0x102acc8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 905, Address: 0x102acd0 */
    sv_move_main(ywk); /* Line 906, Address: 0x102acfc */
    return; /* Line 907, Address: 0x102ad08 */
  } else if (!limmoveflag) goto label1; /* Line 908, Address: 0x102ad10 */
  sv_move_sub2(); /* Line 909, Address: 0x102ad20 */
  return; /* Line 910, Address: 0x102ad28 */



label1:
  scra_vz = 0; /* Line 915, Address: 0x102ad30 */
} /* Line 916, Address: 0x102ad38 */













static void sv_move_main(short yPos) { /* Line 930, Address: 0x102ad50 */
  short spdwk;

  if (scra_vline == 96) { /* Line 933, Address: 0x102ad60 */
    if (actwk[0].mspeed.w < 0) { /* Line 934, Address: 0x102ad7c */
      spdwk = -actwk[0].mspeed.w; /* Line 935, Address: 0x102ad94 */
    } else { /* Line 936, Address: 0x102adb8 */
      spdwk = actwk[0].mspeed.w; /* Line 937, Address: 0x102adc0 */
    }


    if (spdwk >= 2048) { /* Line 941, Address: 0x102add0 */
      sv_move_main2(yPos); /* Line 942, Address: 0x102ade4 */
    } /* Line 943, Address: 0x102adf0 */
    else {

      if (yPos > 6) { /* Line 946, Address: 0x102adf8 */
        sv_move_plus(1536); /* Line 947, Address: 0x102ae10 */
      } else if (yPos < -6) { /* Line 948, Address: 0x102ae1c */
        sv_move_minus(1536); /* Line 949, Address: 0x102ae3c */
      } /* Line 950, Address: 0x102ae48 */
      else sv_move_sub(yPos); /* Line 951, Address: 0x102ae50 */
    }
  } /* Line 953, Address: 0x102ae5c */
  else {
    if (yPos > 2) { /* Line 955, Address: 0x102ae64 */
      sv_move_plus(512); /* Line 956, Address: 0x102ae7c */
    } else if (yPos < -2) { /* Line 957, Address: 0x102ae88 */
      sv_move_minus(512); /* Line 958, Address: 0x102aea8 */
    } /* Line 959, Address: 0x102aeb4 */
    else sv_move_sub(yPos); /* Line 960, Address: 0x102aebc */
  }

} /* Line 963, Address: 0x102aec8 */













static void sv_move_main2(short yPos) { /* Line 977, Address: 0x102aee0 */
  short spdwk;

  spdwk = 4096; /* Line 980, Address: 0x102aef0 */

  if (yPos > 16) { /* Line 982, Address: 0x102aefc */
    sv_move_plus(spdwk); /* Line 983, Address: 0x102af14 */
  } else if (yPos < -16) { /* Line 984, Address: 0x102af20 */
    sv_move_minus(spdwk); /* Line 985, Address: 0x102af40 */
  } else { /* Line 986, Address: 0x102af4c */
    sv_move_sub(yPos); /* Line 987, Address: 0x102af54 */
  }
} /* Line 989, Address: 0x102af60 */














static void sv_move_sub(short yPos) { /* Line 1004, Address: 0x102af80 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1007, Address: 0x102af8c */
  if (yPos < 0) { /* Line 1008, Address: 0x102afb8 */
    scrv_up_ch(lSpd); /* Line 1009, Address: 0x102afcc */
  } else { /* Line 1010, Address: 0x102afd8 */
    scrv_down_ch(lSpd); /* Line 1011, Address: 0x102afe0 */
  }
} /* Line 1013, Address: 0x102afec */



static void sv_move_sub2() { /* Line 1017, Address: 0x102b000 */
  limmoveflag = 0; /* Line 1018, Address: 0x102b008 */

  sv_move_sub(0); /* Line 1020, Address: 0x102b010 */
} /* Line 1021, Address: 0x102b01c */













static void sv_move_minus(short speed) { /* Line 1035, Address: 0x102b030 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1038, Address: 0x102b03c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1039, Address: 0x102b060 */
  scrv_up_ch(lSpd); /* Line 1040, Address: 0x102b084 */
} /* Line 1041, Address: 0x102b090 */














static void scrv_up_ch(int_union lSpd) { /* Line 1056, Address: 0x102b0a0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1057, Address: 0x102b0ac */
    if (lSpd.w.l > -256) { /* Line 1058, Address: 0x102b0d4 */

      lSpd.w.l = scralim_up; /* Line 1060, Address: 0x102b0ec */
    } else { /* Line 1061, Address: 0x102b0f8 */
      lSpd.w.l &= 2047; /* Line 1062, Address: 0x102b100 */
      actwk[0].yposi.w.l &= 2047; /* Line 1063, Address: 0x102b10c */
      scra_v_posit.w.h &= 2047; /* Line 1064, Address: 0x102b120 */
      scrb_v_posit.w.h &= 1023; /* Line 1065, Address: 0x102b134 */
    }
  }

  scrv_move(lSpd); /* Line 1069, Address: 0x102b148 */
} /* Line 1070, Address: 0x102b154 */













static void sv_move_plus(short sSpd) { /* Line 1084, Address: 0x102b170 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1087, Address: 0x102b17c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1088, Address: 0x102b19c */
  scrv_down_ch(lSpd); /* Line 1089, Address: 0x102b1c0 */
} /* Line 1090, Address: 0x102b1cc */














static void scrv_down_ch(int_union lSpd) { /* Line 1105, Address: 0x102b1e0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1106, Address: 0x102b1ec */
    if (lSpd.w.l < 2048) { /* Line 1107, Address: 0x102b214 */

      lSpd.w.l = scralim_down; /* Line 1109, Address: 0x102b22c */
    } else { /* Line 1110, Address: 0x102b238 */
      lSpd.w.l -= 2048; /* Line 1111, Address: 0x102b240 */
      actwk[0].yposi.w.l &= 2047; /* Line 1112, Address: 0x102b24c */
      scra_v_posit.w.h -= 2048; /* Line 1113, Address: 0x102b260 */
      scrb_v_posit.w.h &= 1023; /* Line 1114, Address: 0x102b274 */
    }
  }

  scrv_move(lSpd); /* Line 1118, Address: 0x102b288 */
} /* Line 1119, Address: 0x102b294 */
















static void scrv_move(int_union lSpd) { /* Line 1136, Address: 0x102b2b0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1140, Address: 0x102b2c0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1141, Address: 0x102b2d0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1142, Address: 0x102b2f4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1143, Address: 0x102b308 */
  scra_vz = spdwk.w.l; /* Line 1144, Address: 0x102b320 */

  scra_v_posit.l = lSpd.l; /* Line 1146, Address: 0x102b32c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1148, Address: 0x102b338 */
  if (!ywk) { /* Line 1149, Address: 0x102b374 */
    scra_v_count ^= 16; /* Line 1150, Address: 0x102b37c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1151, Address: 0x102b390 */
    if (ywk < 0) { /* Line 1152, Address: 0x102b3bc */
      scrflaga.b.h |= 1; /* Line 1153, Address: 0x102b3cc */
    } else { /* Line 1154, Address: 0x102b3e0 */
      scrflaga.b.h |= 2; /* Line 1155, Address: 0x102b3e8 */
    }
  }


} /* Line 1160, Address: 0x102b3fc */

















void scrollwrt() { /* Line 1178, Address: 0x102b410 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1187, Address: 0x102b430 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1188, Address: 0x102b434 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1189, Address: 0x102b440 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1190, Address: 0x102b44c */
  pScrFlag = &scrflagbw.b.h; /* Line 1191, Address: 0x102b454 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1192, Address: 0x102b45c */

  VramBase = 16384; /* Line 1194, Address: 0x102b470 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1195, Address: 0x102b474 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1196, Address: 0x102b480 */
  pMapWk = (unsigned char*)mapwka; /* Line 1197, Address: 0x102b48c */
  pScrFlag = &scrflagaw.b.h; /* Line 1198, Address: 0x102b494 */

  if (*pScrFlag) { /* Line 1200, Address: 0x102b49c */
    if (*pScrFlag & 1) { /* Line 1201, Address: 0x102b4a8 */
      *pScrFlag &= 254; /* Line 1202, Address: 0x102b4bc */

      lD4.l = -16; /* Line 1204, Address: 0x102b4c8 */
      wD5 = 65520; /* Line 1205, Address: 0x102b4d0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1207, Address: 0x102b4d8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1209, Address: 0x102b4f8 */
    }




    if (*pScrFlag & 2) { /* Line 1215, Address: 0x102b524 */
      *pScrFlag &= 253; /* Line 1216, Address: 0x102b538 */

      lD4.l = 224; /* Line 1218, Address: 0x102b544 */
      wD5 = 65520; /* Line 1219, Address: 0x102b54c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1220, Address: 0x102b554 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1222, Address: 0x102b574 */
    }




    if (*pScrFlag & 4) { /* Line 1228, Address: 0x102b5a0 */
      *pScrFlag &= 251; /* Line 1229, Address: 0x102b5b4 */

      lD4.l = -16; /* Line 1231, Address: 0x102b5c0 */
      wD5 = 65520; /* Line 1232, Address: 0x102b5c8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1233, Address: 0x102b5d0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1235, Address: 0x102b5f0 */
    }




    if (*pScrFlag & 8) { /* Line 1241, Address: 0x102b61c */
      *pScrFlag &= 247; /* Line 1242, Address: 0x102b630 */

      lD4.l = -16; /* Line 1244, Address: 0x102b63c */
      wD5 = 320; /* Line 1245, Address: 0x102b644 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1246, Address: 0x102b64c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1248, Address: 0x102b66c */
    }
  }






} /* Line 1257, Address: 0x102b698 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1274, Address: 0x102b6c0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1285, Address: 0x102b6ec */

  if (*pScrFlag & 1) { /* Line 1287, Address: 0x102b6f4 */
    *pScrFlag &= 254; /* Line 1288, Address: 0x102b70c */
  } /* Line 1289, Address: 0x102b720 */
  else {
    *pScrFlag &= 254; /* Line 1291, Address: 0x102b728 */

    if (*pScrFlag & 2) { /* Line 1293, Address: 0x102b73c */
      *pScrFlag &= 253; /* Line 1294, Address: 0x102b754 */
      lD4.w.l = 224; /* Line 1295, Address: 0x102b768 */
    } /* Line 1296, Address: 0x102b770 */
    else {
      *pScrFlag &= 253; /* Line 1298, Address: 0x102b778 */
      goto label1; /* Line 1299, Address: 0x102b78c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1304, Address: 0x102b794 */
  wD0 &= 127; /* Line 1305, Address: 0x102b7e4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1306, Address: 0x102b7ec */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1312, Address: 0x102b80c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1313, Address: 0x102b82c */
  if (wD0 != 0) { /* Line 1314, Address: 0x102b850 */
    wD5 = 65520; /* Line 1315, Address: 0x102b85c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1316, Address: 0x102b864 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1318, Address: 0x102b884 */



  } /* Line 1322, Address: 0x102b8b0 */
  else {

    wD5 = 0; /* Line 1325, Address: 0x102b8b8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1326, Address: 0x102b8bc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1330, Address: 0x102b8dc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1337, Address: 0x102b908 */






    lD4.l = -16; /* Line 1344, Address: 0x102b91c */
    wD5 = 65520; /* Line 1345, Address: 0x102b924 */
    if (*pScrFlag & 168) { /* Line 1346, Address: 0x102b92c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1347, Address: 0x102b944 */
      wD5 = 320; /* Line 1348, Address: 0x102b964 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1352, Address: 0x102b96c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1354, Address: 0x102b99c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1355, Address: 0x102b9a8 */



    for (i = 0; i < 16; ++i) { /* Line 1359, Address: 0x102b9b8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1360, Address: 0x102b9c4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1361, Address: 0x102b9e4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1362, Address: 0x102ba1c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1363, Address: 0x102ba3c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1365, Address: 0x102ba60 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1368, Address: 0x102ba84 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1370, Address: 0x102baa4 */
      }
      lD4.w.l += 16; /* Line 1372, Address: 0x102bab8 */
    } /* Line 1373, Address: 0x102bac4 */
    *pScrFlag = 0; /* Line 1374, Address: 0x102bad4 */
  }
} /* Line 1376, Address: 0x102badc */





void scrollwrtc() {} /* Line 1382, Address: 0x102bb10 */




void scrollwrtz() {} /* Line 1387, Address: 0x102bb20 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1405, Address: 0x102bb30 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1418, Address: 0x102bb58 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1421, Address: 0x102bb78 */
    pTilePoint->x += 2; /* Line 1422, Address: 0x102bb8c */
    if (pTilePoint->x >= 64) { /* Line 1423, Address: 0x102bba0 */
      pTilePoint->x -= 64; /* Line 1424, Address: 0x102bbb4 */
    }
    xOffs += 16; /* Line 1426, Address: 0x102bbc8 */
  } while (--lpcnt >= 0); /* Line 1427, Address: 0x102bbd4 */
} /* Line 1428, Address: 0x102bbe8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1432, Address: 0x102bc00 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1436, Address: 0x102bc28 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1439, Address: 0x102bc48 */
    pTilePoint->x += 2; /* Line 1440, Address: 0x102bc5c */
    if (pTilePoint->x >= 64) { /* Line 1441, Address: 0x102bc70 */
      pTilePoint->x -= 64; /* Line 1442, Address: 0x102bc84 */
    }
    xOffs += 16; /* Line 1444, Address: 0x102bc98 */
  } while (--lpcnt >= 0); /* Line 1445, Address: 0x102bca4 */
} /* Line 1446, Address: 0x102bcb8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1466, Address: 0x102bcd0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1470, Address: 0x102bcf8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1473, Address: 0x102bd18 */
    pTilePoint->y += 2; /* Line 1474, Address: 0x102bd2c */
    if (pTilePoint->y >= 32) { /* Line 1475, Address: 0x102bd3c */
      pTilePoint->y -= 32; /* Line 1476, Address: 0x102bd50 */
    }
    yOffs += 16; /* Line 1478, Address: 0x102bd60 */
  } while (--lpcnt >= 0); /* Line 1479, Address: 0x102bd6c */
} /* Line 1480, Address: 0x102bd80 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1499, Address: 0x102bd90 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1505, Address: 0x102bdc4 */

    base = 1; /* Line 1507, Address: 0x102bdd4 */
  } /* Line 1508, Address: 0x102bdd8 */
  else if (VramBase == 16384) { /* Line 1509, Address: 0x102bde0 */

    base = 0; /* Line 1511, Address: 0x102bdf0 */
  }
  x = pTilePoint->x; /* Line 1513, Address: 0x102bdf4 */
  y = pTilePoint->y; /* Line 1514, Address: 0x102bdfc */


  frip = BlkIndex & 6144; /* Line 1517, Address: 0x102be04 */
  BlkIndex &= 1023; /* Line 1518, Address: 0x102be0c */
  if (frip == 6144) { /* Line 1519, Address: 0x102be18 */

    p0 = 3, p1 = 2; /* Line 1521, Address: 0x102be24 */
    p2 = 1, p3 = 0; /* Line 1522, Address: 0x102be2c */
  } /* Line 1523, Address: 0x102be34 */
  else if (frip & 4096) { /* Line 1524, Address: 0x102be3c */

    p0 = 2, p1 = 3; /* Line 1526, Address: 0x102be48 */
    p2 = 0, p3 = 1; /* Line 1527, Address: 0x102be50 */
  } /* Line 1528, Address: 0x102be58 */
  else if (frip & 2048) { /* Line 1529, Address: 0x102be60 */

    p0 = 1, p1 = 0; /* Line 1531, Address: 0x102be6c */
    p2 = 3, p3 = 2; /* Line 1532, Address: 0x102be74 */
  } /* Line 1533, Address: 0x102be7c */
  else {

    p0 = 0, p1 = 1; /* Line 1536, Address: 0x102be84 */
    p2 = 2, p3 = 3; /* Line 1537, Address: 0x102be8c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1540, Address: 0x102be94 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1541, Address: 0x102bed8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1542, Address: 0x102bf1c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1543, Address: 0x102bf60 */

} /* Line 1545, Address: 0x102bfa4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1563, Address: 0x102bfe0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1564, Address: 0x102c000 */
} /* Line 1565, Address: 0x102c020 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1567, Address: 0x102c030 */
  wH_posiw = 0; /* Line 1568, Address: 0x102c050 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1569, Address: 0x102c054 */
} /* Line 1570, Address: 0x102c074 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1577, Address: 0x102c090 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1583, Address: 0x102c0c0 */
  yOffs += wV_posiw; /* Line 1584, Address: 0x102c0d0 */





  if ((short)xOffs < 0) /* Line 1590, Address: 0x102c0e0 */
    xOffs = 0; /* Line 1591, Address: 0x102c0fc */
  if ((short)yOffs < 0) /* Line 1592, Address: 0x102c100 */
    yOffs = 0; /* Line 1593, Address: 0x102c11c */
  if ((short)xOffs >= 16384) /* Line 1594, Address: 0x102c120 */
    xOffs = 16383; /* Line 1595, Address: 0x102c140 */
  if ((short)yOffs >= 2048) /* Line 1596, Address: 0x102c148 */
    yOffs = 2047; /* Line 1597, Address: 0x102c168 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1598, Address: 0x102c170 */
  if (i < 0) i = 0; /* Line 1599, Address: 0x102c1b8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1601, Address: 0x102c1c4 */

  if (ScreenNo) { /* Line 1603, Address: 0x102c1e0 */




    xOffs &= 32767; /* Line 1608, Address: 0x102c1e8 */
    yOffs &= 32767; /* Line 1609, Address: 0x102c1f4 */


    xBlk = xOffs; /* Line 1612, Address: 0x102c200 */
    xBlk %= 256; /* Line 1613, Address: 0x102c208 */
    xBlk /= 16; /* Line 1614, Address: 0x102c228 */
    yBlk = yOffs; /* Line 1615, Address: 0x102c244 */
    yBlk %= 256; /* Line 1616, Address: 0x102c24c */
    yBlk /= 16; /* Line 1617, Address: 0x102c26c */

    lpw = pmapwk; /* Line 1619, Address: 0x102c288 */
    lpw += xBlk; /* Line 1620, Address: 0x102c290 */
    lpw += yBlk * 16; /* Line 1621, Address: 0x102c298 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1622, Address: 0x102c2a4 */
    *pIndex = *lpw; /* Line 1623, Address: 0x102c2bc */

    return 1; /* Line 1625, Address: 0x102c2cc */
  }

  *pIndex = 0; /* Line 1628, Address: 0x102c2d8 */
  return 0; /* Line 1629, Address: 0x102c2e0 */
} /* Line 1630, Address: 0x102c2e4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1650, Address: 0x102c310 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1658, Address: 0x102c338 */
  if (ScreenNo) { /* Line 1659, Address: 0x102c39c */





    xBlk = xOffs; /* Line 1665, Address: 0x102c3a4 */
    xBlk %= 256; /* Line 1666, Address: 0x102c3ac */
    xBlk /= 16; /* Line 1667, Address: 0x102c3cc */
    yBlk = yOffs; /* Line 1668, Address: 0x102c3e8 */
    yBlk %= 256; /* Line 1669, Address: 0x102c3f0 */
    yBlk /= 16; /* Line 1670, Address: 0x102c410 */


    lpw = pmapwk; /* Line 1673, Address: 0x102c42c */
    lpw += xBlk; /* Line 1674, Address: 0x102c434 */
    lpw += yBlk * 16; /* Line 1675, Address: 0x102c43c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1676, Address: 0x102c448 */
    *ppBlockNo = lpw; /* Line 1677, Address: 0x102c460 */
    *pIndex = *lpw; /* Line 1678, Address: 0x102c468 */




    return 1; /* Line 1683, Address: 0x102c478 */
  }

  *pIndex = 0; /* Line 1686, Address: 0x102c484 */
  return 0; /* Line 1687, Address: 0x102c48c */
} /* Line 1688, Address: 0x102c490 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1702, Address: 0x102c4b0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1709, Address: 0x102c4cc */
  pMapWk = (unsigned char*)mapwka; /* Line 1710, Address: 0x102c4d0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1711, Address: 0x102c4d8 */
    *pBlockIndex = BlockNo; /* Line 1712, Address: 0x102c4fc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1713, Address: 0x102c508 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1714, Address: 0x102c520 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1715, Address: 0x102c534 */
    }
  }


} /* Line 1720, Address: 0x102c54c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1734, Address: 0x102c570 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1735, Address: 0x102c57c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1736, Address: 0x102c5a8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1737, Address: 0x102c5f4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1738, Address: 0x102c620 */

          return 0; /* Line 1740, Address: 0x102c66c */
        }
      }
    }
  }

  return 1; /* Line 1746, Address: 0x102c678 */
} /* Line 1747, Address: 0x102c67c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1764, Address: 0x102c690 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1765, Address: 0x102c6ac */

} /* Line 1767, Address: 0x102c6c8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1769, Address: 0x102c6e0 */
  wH_posiw = 0; /* Line 1770, Address: 0x102c6fc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1771, Address: 0x102c700 */

} /* Line 1773, Address: 0x102c71c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1775, Address: 0x102c730 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1776, Address: 0x102c744 */

} /* Line 1778, Address: 0x102c760 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1780, Address: 0x102c770 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1781, Address: 0x102c78c */

} /* Line 1783, Address: 0x102c7a8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1785, Address: 0x102c7c0 */
  xOffs += wH_posiw; /* Line 1786, Address: 0x102c7d8 */
  yOffs += wV_posiw; /* Line 1787, Address: 0x102c7e8 */
  yOffs &= 240; /* Line 1788, Address: 0x102c7f8 */
  xOffs &= 496; /* Line 1789, Address: 0x102c804 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1791, Address: 0x102c810 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1792, Address: 0x102c83c */


} /* Line 1795, Address: 0x102c868 */















void mapwrt() { /* Line 1811, Address: 0x102c880 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1818, Address: 0x102c898 */
  wV_posiw = scra_v_posit.w.h; /* Line 1819, Address: 0x102c8a4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1820, Address: 0x102c8b0 */
  VramBase = 16384; /* Line 1821, Address: 0x102c8b8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1822, Address: 0x102c8bc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1826, Address: 0x102c8d4 */
  VramBase = 24576; /* Line 1827, Address: 0x102c8dc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1828, Address: 0x102c8e0 */

} /* Line 1830, Address: 0x102c8f0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1833, Address: 0x102c910 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1834, Address: 0x102c928 */
} /* Line 1835, Address: 0x102c948 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1840, Address: 0x102c960 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1844, Address: 0x102c980 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1847, Address: 0x102c99c */



    wD4 += 16; /* Line 1851, Address: 0x102c9c4 */
  } while ((short)--wD6 >= 0); /* Line 1852, Address: 0x102c9d0 */

} /* Line 1854, Address: 0x102c9f8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1860, Address: 0x102ca10 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1863, Address: 0x102ca2c */
  wD6 = 15; /* Line 1864, Address: 0x102ca34 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1867, Address: 0x102ca3c */

    mapwrt_sub(z81awrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1869, Address: 0x102ca60 */
    wD4 += 16; /* Line 1870, Address: 0x102ca80 */
  } while ((short)--wD6 >= 0); /* Line 1871, Address: 0x102ca88 */
} /* Line 1872, Address: 0x102caac */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1898, Address: 0x102cad0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1903, Address: 0x102caf8 */
  wD0 = pWrttbl[wD0]; /* Line 1904, Address: 0x102cb08 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1906, Address: 0x102cb24 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1907, Address: 0x102cb48 */
  if (wD0) { /* Line 1908, Address: 0x102cb70 */
    wD5 = 65520; /* Line 1909, Address: 0x102cb7c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1910, Address: 0x102cb84 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1913, Address: 0x102cba0 */



  } /* Line 1917, Address: 0x102cbc8 */
  else {

    wD5 = 0; /* Line 1920, Address: 0x102cbd0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1921, Address: 0x102cbd4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1925, Address: 0x102cbf0 */
  }





} /* Line 1932, Address: 0x102cc18 */










void mapinit() { /* Line 1943, Address: 0x102cc40 */

  colorset2(mapinittbl.colorno2); /* Line 1945, Address: 0x102cc48 */
  colorset(mapinittbl.colorno2); /* Line 1946, Address: 0x102cc5c */


  if (play_start & 2) divdevset(); /* Line 1949, Address: 0x102cc70 */
} /* Line 1950, Address: 0x102cc90 */




void mapset() {} /* Line 1955, Address: 0x102cca0 */



void divdevset() {} /* Line 1959, Address: 0x102ccb0 */



void enecginit() {} /* Line 1963, Address: 0x102ccc0 */
