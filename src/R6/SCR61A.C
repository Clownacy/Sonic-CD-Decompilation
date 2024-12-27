#include "..\EQU.H"
#include "SCR61A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL6A.H"

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
  0, 0, 0, 0, 0, 0, 6, 6, 6, 6,
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
extern unsigned char mapwka[64][8];
extern unsigned char mapwkb[64][8];
extern map_init_data mapinittbl;








































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 146, Address: 0x101f7e0 */
    return &actwk[0]; /* Line 147, Address: 0x101f7f4 */
  else
    return &actwk[1]; /* Line 149, Address: 0x101f804 */

} /* Line 151, Address: 0x101f80c */





































void scr_set() { /* Line 189, Address: 0x101f820 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x101f82c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x101f840 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x101f854 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x101f85c */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x101f864 */
  ++pScrTbl; /* Line 198, Address: 0x101f870 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x101f874 */
  ++pScrTbl; /* Line 200, Address: 0x101f888 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x101f88c */
  ++pScrTbl; /* Line 202, Address: 0x101f8a0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x101f8a4 */
  ++pScrTbl; /* Line 204, Address: 0x101f8b8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x101f8bc */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x101f8d0 */
  ++pScrTbl; /* Line 207, Address: 0x101f8f0 */
  scra_h_count = 16; /* Line 208, Address: 0x101f8f4 */
  scra_v_count = 16; /* Line 209, Address: 0x101f900 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x101f90c */
  scra_hline = 160; /* Line 212, Address: 0x101f918 */

  playposiset(); /* Line 214, Address: 0x101f924 */
} /* Line 215, Address: 0x101f92c */
















































static void playposiset() { /* Line 264, Address: 0x101f940 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x101f954 */
    playload(); /* Line 268, Address: 0x101f964 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x101f96c */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x101f97c */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x101f994 */
    } else { /* Line 273, Address: 0x101f9a4 */
      ywk = 0; /* Line 274, Address: 0x101f9ac */
    }
  } /* Line 276, Address: 0x101f9b0 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x101f9b8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x101f9d8 */
    } /* Line 280, Address: 0x101f9fc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x101fa04 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x101fa24 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x101fa38 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x101fa4c */
    xwk -= 160; /* Line 292, Address: 0x101fa60 */
  } else { /* Line 293, Address: 0x101fa6c */
    xwk = 0; /* Line 294, Address: 0x101fa74 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x101fa78 */
    xwk = scralim_right; /* Line 299, Address: 0x101fa9c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x101faac */

  if (ywk > 96) { /* Line 305, Address: 0x101fab4 */
    ywk -= 96; /* Line 306, Address: 0x101fac8 */
  } else { /* Line 307, Address: 0x101fad4 */
    ywk = 0; /* Line 308, Address: 0x101fadc */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x101fae0 */
    ywk = scralim_down; /* Line 313, Address: 0x101fb04 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x101fb14 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x101fb1c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x101fb2c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x101fb3c */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x101fb4c */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x101fb5c */
} /* Line 326, Address: 0x101fb6c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x101fb90 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x101fb9c */
  lYwk.w.l = 0; /* Line 351, Address: 0x101fba4 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x101fba8 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x101fbb4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x101fbc0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x101fbcc */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x101fbd8 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x101fbf4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x101fc00 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x101fc1c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x101fc28 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x101fc44 */
} /* Line 366, Address: 0x101fc68 */















void scroll() { /* Line 382, Address: 0x101fc80 */
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

  if (scroll_start.b.h) return; /* Line 394, Address: 0x101fc9c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x101fcac */

  scrchk(); /* Line 401, Address: 0x101fcd8 */

  scroll_h(); /* Line 403, Address: 0x101fce0 */
  scroll_v(); /* Line 404, Address: 0x101fce8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x101fcf0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x101fd00 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x101fd10 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x101fd24 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x101fd34 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x101fd48 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x101fd58 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x101fd74 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x101fd84 */


  scrollb_v(lYwk); /* Line 422, Address: 0x101fd98 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x101fda8 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x101fdd0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x101fe08 */

  psHscw = hscrollwork; /* Line 429, Address: 0x101fe1c */

  z61aline(&psHscw); /* Line 431, Address: 0x101fe28 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 433, Address: 0x101fe34 */
  for (i = 0; i < 20; ++i) { /* Line 434, Address: 0x101fe54 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x101fe60 */
  } /* Line 437, Address: 0x101fe74 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x101fe84 */
  for (i = 0; i < 46; ++i) { /* Line 440, Address: 0x101fea4 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x101feb0 */
  } /* Line 443, Address: 0x101fec4 */

  pHscrbuf = lphscrollbuff; /* Line 445, Address: 0x101fed4 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 446, Address: 0x101fee0 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 447, Address: 0x101ff10 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 448, Address: 0x101ff40 */
} /* Line 449, Address: 0x101ff5c */













static void z61aline(short** ppHscw) { /* Line 463, Address: 0x101ff80 */
  char z81ascrtbl[10] = { /* Line 464, Address: 0x101ffa8 */
    5, 3, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk, lHwk;

  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 471, Address: 0x101ffdc */
  radwk = 0; /* Line 472, Address: 0x1020000 */
  sXwk = scrb_h_posit.w.h; /* Line 473, Address: 0x1020004 */

  *ppHscw += 30; /* Line 475, Address: 0x1020014 */

  for (i = 9; i >= 0; --i) { /* Line 477, Address: 0x1020028 */

    sinset(radwk, &sinwk, &coswk); /* Line 479, Address: 0x1020034 */
    lHwk = (256 - coswk) * lXwk; /* Line 480, Address: 0x1020048 */
    lHwk = (unsigned int)lHwk >> 8; /* Line 481, Address: 0x1020060 */
    hwk = -(lHwk + sXwk); /* Line 482, Address: 0x1020064 */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 483, Address: 0x1020084 */

      --*ppHscw; /* Line 485, Address: 0x102009c */
      **ppHscw = hwk; /* Line 486, Address: 0x10200b0 */
    } /* Line 487, Address: 0x10200bc */

    radwk += 6; /* Line 489, Address: 0x10200c8 */
  } /* Line 490, Address: 0x10200d4 */

  *ppHscw += 30; /* Line 492, Address: 0x10200e0 */
} /* Line 493, Address: 0x10200f4 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 514, Address: 0x1020120 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 518, Address: 0x102013c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 519, Address: 0x1020140 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 521, Address: 0x1020160 */
    ldwk.w.l = *pHscrwk; /* Line 522, Address: 0x102017c */
    ++pHscrwk; /* Line 523, Address: 0x1020188 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 525, Address: 0x1020194 */
      (*pHscrbuf)->l = ldwk.l; /* Line 526, Address: 0x102019c */
    } /* Line 527, Address: 0x10201ac */
  } /* Line 528, Address: 0x10201d0 */
} /* Line 529, Address: 0x10201f0 */









































































































static void scrollb_v(short yPos) { /* Line 635, Address: 0x1020210 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 638, Address: 0x1020220 */
  scrb_v_posit.w.h = yPos; /* Line 639, Address: 0x1020230 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 640, Address: 0x102023c */

  if (!ywk) { /* Line 642, Address: 0x1020274 */
    scrb_v_count ^= 16; /* Line 643, Address: 0x102027c */
    if (yPos - ysv < 0) { /* Line 644, Address: 0x1020290 */
      scrflagb.b.h |= 1; /* Line 645, Address: 0x10202b0 */
    } /* Line 646, Address: 0x10202c4 */
    else {
      scrflagb.b.h |= 2; /* Line 648, Address: 0x10202cc */
    }
  }


} /* Line 653, Address: 0x10202e0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 671, Address: 0x1020300 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 675, Address: 0x1020314 */
  lXwk = lXsv + xoffs; /* Line 676, Address: 0x102031c */
  scrb_h_posit.l = lXwk; /* Line 677, Address: 0x1020324 */
  ldXwk.l = lXwk; /* Line 678, Address: 0x102032c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 679, Address: 0x1020330 */
  ldXwk.w.l &= 16; /* Line 680, Address: 0x1020354 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 681, Address: 0x1020360 */

  if (!ldXwk.b.b4) { /* Line 683, Address: 0x102037c */
    scrb_h_count ^= 16; /* Line 684, Address: 0x1020388 */
    if (lXwk - lXsv < 0) { /* Line 685, Address: 0x102039c */
      scrflagb.b.h |= 1 << flgbit; /* Line 686, Address: 0x10203a8 */
    } /* Line 687, Address: 0x10203cc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 689, Address: 0x10203d4 */
    }
  }


} /* Line 694, Address: 0x10203fc */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 712, Address: 0x1020410 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 716, Address: 0x1020424 */
  lXwk = lXsv + xoffs; /* Line 717, Address: 0x102042c */
  scrc_h_posit.l = lXwk; /* Line 718, Address: 0x1020434 */
  ldXwk.l = lXwk; /* Line 719, Address: 0x102043c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 720, Address: 0x1020440 */
  ldXwk.w.l &= 16; /* Line 721, Address: 0x1020464 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 722, Address: 0x1020470 */

  if (!ldXwk.b.b4) { /* Line 724, Address: 0x102048c */
    scrc_h_count ^= 16; /* Line 725, Address: 0x1020498 */
    if (lXwk - lXsv < 0) { /* Line 726, Address: 0x10204ac */
      scrflagc.b.h |= 1 << flgbit; /* Line 727, Address: 0x10204b8 */
    } /* Line 728, Address: 0x10204dc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 730, Address: 0x10204e4 */
    }
  }


} /* Line 735, Address: 0x102050c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 753, Address: 0x1020520 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 757, Address: 0x1020534 */
  lXwk = lXsv + xoffs; /* Line 758, Address: 0x102053c */
  scrz_h_posit.l = lXwk; /* Line 759, Address: 0x1020544 */
  ldXwk.l = lXwk; /* Line 760, Address: 0x102054c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 761, Address: 0x1020550 */
  ldXwk.w.l &= 16; /* Line 762, Address: 0x1020574 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 763, Address: 0x1020580 */

  if (!ldXwk.b.b4) { /* Line 765, Address: 0x102059c */
    scrz_h_count ^= 16; /* Line 766, Address: 0x10205a8 */
    if (lXwk - lXsv < 0) { /* Line 767, Address: 0x10205bc */
      scrflagz.b.h |= 1 << flgbit; /* Line 768, Address: 0x10205c8 */
    } /* Line 769, Address: 0x10205ec */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 771, Address: 0x10205f4 */
    }
  }


} /* Line 776, Address: 0x102061c */














static void scroll_h() { /* Line 791, Address: 0x1020630 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 795, Address: 0x1020640 */

  scrh_move(); /* Line 797, Address: 0x1020650 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 798, Address: 0x1020658 */
  if (!bXwk) { /* Line 799, Address: 0x102068c */
    scra_h_count ^= 16; /* Line 800, Address: 0x1020694 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 801, Address: 0x10206a8 */
      scrflaga.b.h |= 4; /* Line 802, Address: 0x10206cc */
    } else { /* Line 803, Address: 0x10206e0 */
      scrflaga.b.h |= 8; /* Line 804, Address: 0x10206e8 */
    }
  }


} /* Line 809, Address: 0x10206fc */
















static void scrh_move() { /* Line 826, Address: 0x1020720 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 829, Address: 0x1020728 */
  if (xwk == 0) { /* Line 830, Address: 0x1020770 */

    scra_hz = 0; /* Line 832, Address: 0x1020780 */
    return; /* Line 833, Address: 0x1020788 */
  } else if (xwk < 0) { /* Line 834, Address: 0x1020790 */

    if (xwk < -16) { /* Line 836, Address: 0x10207a0 */
      xwk = -16; /* Line 837, Address: 0x10207b4 */
    }


    xwk += scra_h_posit.w.h; /* Line 841, Address: 0x10207c0 */
    if (xwk < scralim_left) { /* Line 842, Address: 0x10207d4 */
      xwk = scralim_left; /* Line 843, Address: 0x10207f8 */
    }
  } /* Line 845, Address: 0x1020808 */
  else {
    if (xwk > 16) { /* Line 847, Address: 0x1020810 */
      xwk = 16; /* Line 848, Address: 0x1020824 */
    }


    xwk += scra_h_posit.w.h; /* Line 852, Address: 0x1020830 */
    if (xwk > scralim_right) { /* Line 853, Address: 0x1020844 */
      xwk = scralim_right; /* Line 854, Address: 0x1020868 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 859, Address: 0x1020878 */
  scra_h_posit.w.h = xwk; /* Line 860, Address: 0x10208a8 */
} /* Line 861, Address: 0x10208b0 */














static void scroll_v() { /* Line 876, Address: 0x10208c0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 879, Address: 0x10208cc */
  if (actwk[0].cddat & 4) { /* Line 880, Address: 0x1020900 */
    ywk -= 5; /* Line 881, Address: 0x1020918 */
  }


  if (actwk[0].cddat & 2) { /* Line 885, Address: 0x1020924 */
    ywk += 32; /* Line 886, Address: 0x102093c */
    if (ywk < scra_vline) { /* Line 887, Address: 0x1020948 */
      ywk -= scra_vline; /* Line 888, Address: 0x102096c */
      sv_move_main2(ywk); /* Line 889, Address: 0x1020980 */
      return; /* Line 890, Address: 0x102098c */
    } else if (ywk >= scra_vline + 64) { /* Line 891, Address: 0x1020994 */
      ywk -= scra_vline + 64; /* Line 892, Address: 0x10209bc */
      sv_move_main2(ywk); /* Line 893, Address: 0x10209e4 */
      return; /* Line 894, Address: 0x10209f0 */
    }
    ywk -= scra_vline + 64; /* Line 896, Address: 0x10209f8 */
    if (!limmoveflag) goto label1; /* Line 897, Address: 0x1020a20 */
    sv_move_sub2(); /* Line 898, Address: 0x1020a30 */
    return; /* Line 899, Address: 0x1020a38 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 904, Address: 0x1020a40 */
    sv_move_main(ywk); /* Line 905, Address: 0x1020a6c */
    return; /* Line 906, Address: 0x1020a78 */
  } else if (!limmoveflag) goto label1; /* Line 907, Address: 0x1020a80 */
  sv_move_sub2(); /* Line 908, Address: 0x1020a90 */
  return; /* Line 909, Address: 0x1020a98 */



label1:
  scra_vz = 0; /* Line 914, Address: 0x1020aa0 */
} /* Line 915, Address: 0x1020aa8 */













static void sv_move_main(short yPos) { /* Line 929, Address: 0x1020ac0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 932, Address: 0x1020ad0 */
    if (actwk[0].mspeed.w < 0) { /* Line 933, Address: 0x1020aec */
      spdwk = -actwk[0].mspeed.w; /* Line 934, Address: 0x1020b04 */
    } else { /* Line 935, Address: 0x1020b28 */
      spdwk = actwk[0].mspeed.w; /* Line 936, Address: 0x1020b30 */
    }


    if (spdwk >= 2048) { /* Line 940, Address: 0x1020b40 */
      sv_move_main2(yPos); /* Line 941, Address: 0x1020b54 */
    } /* Line 942, Address: 0x1020b60 */
    else {

      if (yPos > 6) { /* Line 945, Address: 0x1020b68 */
        sv_move_plus(1536); /* Line 946, Address: 0x1020b80 */
      } else if (yPos < -6) { /* Line 947, Address: 0x1020b8c */
        sv_move_minus(1536); /* Line 948, Address: 0x1020bac */
      } /* Line 949, Address: 0x1020bb8 */
      else sv_move_sub(yPos); /* Line 950, Address: 0x1020bc0 */
    }
  } /* Line 952, Address: 0x1020bcc */
  else {
    if (yPos > 2) { /* Line 954, Address: 0x1020bd4 */
      sv_move_plus(512); /* Line 955, Address: 0x1020bec */
    } else if (yPos < -2) { /* Line 956, Address: 0x1020bf8 */
      sv_move_minus(512); /* Line 957, Address: 0x1020c18 */
    } /* Line 958, Address: 0x1020c24 */
    else sv_move_sub(yPos); /* Line 959, Address: 0x1020c2c */
  }

} /* Line 962, Address: 0x1020c38 */













static void sv_move_main2(short yPos) { /* Line 976, Address: 0x1020c50 */
  short spdwk;

  spdwk = 4096; /* Line 979, Address: 0x1020c60 */

  if (yPos > 16) { /* Line 981, Address: 0x1020c6c */
    sv_move_plus(spdwk); /* Line 982, Address: 0x1020c84 */
  } else if (yPos < -16) { /* Line 983, Address: 0x1020c90 */
    sv_move_minus(spdwk); /* Line 984, Address: 0x1020cb0 */
  } else { /* Line 985, Address: 0x1020cbc */
    sv_move_sub(yPos); /* Line 986, Address: 0x1020cc4 */
  }
} /* Line 988, Address: 0x1020cd0 */














static void sv_move_sub(short yPos) { /* Line 1003, Address: 0x1020cf0 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1006, Address: 0x1020cfc */
  if (yPos < 0) { /* Line 1007, Address: 0x1020d28 */
    scrv_up_ch(lSpd); /* Line 1008, Address: 0x1020d3c */
  } else { /* Line 1009, Address: 0x1020d48 */
    scrv_down_ch(lSpd); /* Line 1010, Address: 0x1020d50 */
  }
} /* Line 1012, Address: 0x1020d5c */



static void sv_move_sub2() { /* Line 1016, Address: 0x1020d70 */
  limmoveflag = 0; /* Line 1017, Address: 0x1020d78 */

  sv_move_sub(0); /* Line 1019, Address: 0x1020d80 */
} /* Line 1020, Address: 0x1020d8c */













static void sv_move_minus(short speed) { /* Line 1034, Address: 0x1020da0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1037, Address: 0x1020dac */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1038, Address: 0x1020dd0 */
  scrv_up_ch(lSpd); /* Line 1039, Address: 0x1020df4 */
} /* Line 1040, Address: 0x1020e00 */














static void scrv_up_ch(int_union lSpd) { /* Line 1055, Address: 0x1020e10 */
  if (lSpd.w.l <= scralim_up) { /* Line 1056, Address: 0x1020e1c */
    if (lSpd.w.l > -256) { /* Line 1057, Address: 0x1020e44 */

      lSpd.w.l = scralim_up; /* Line 1059, Address: 0x1020e5c */
    } else { /* Line 1060, Address: 0x1020e68 */
      lSpd.w.l &= 2047; /* Line 1061, Address: 0x1020e70 */
      actwk[0].yposi.w.l &= 2047; /* Line 1062, Address: 0x1020e7c */
      scra_v_posit.w.h &= 2047; /* Line 1063, Address: 0x1020e90 */
      scrb_v_posit.w.h &= 1023; /* Line 1064, Address: 0x1020ea4 */
    }
  }

  scrv_move(lSpd); /* Line 1068, Address: 0x1020eb8 */
} /* Line 1069, Address: 0x1020ec4 */













static void sv_move_plus(short sSpd) { /* Line 1083, Address: 0x1020ee0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1086, Address: 0x1020eec */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1087, Address: 0x1020f0c */
  scrv_down_ch(lSpd); /* Line 1088, Address: 0x1020f30 */
} /* Line 1089, Address: 0x1020f3c */














static void scrv_down_ch(int_union lSpd) { /* Line 1104, Address: 0x1020f50 */
  if (lSpd.w.l >= scralim_down) { /* Line 1105, Address: 0x1020f5c */
    if (lSpd.w.l < 2048) { /* Line 1106, Address: 0x1020f84 */

      lSpd.w.l = scralim_down; /* Line 1108, Address: 0x1020f9c */
    } else { /* Line 1109, Address: 0x1020fa8 */
      lSpd.w.l -= 2048; /* Line 1110, Address: 0x1020fb0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1111, Address: 0x1020fbc */
      scra_v_posit.w.h -= 2048; /* Line 1112, Address: 0x1020fd0 */
      scrb_v_posit.w.h &= 1023; /* Line 1113, Address: 0x1020fe4 */
    }
  }

  scrv_move(lSpd); /* Line 1117, Address: 0x1020ff8 */
} /* Line 1118, Address: 0x1021004 */
















static void scrv_move(int_union lSpd) { /* Line 1135, Address: 0x1021020 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1139, Address: 0x1021030 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1140, Address: 0x1021040 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1141, Address: 0x1021064 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1142, Address: 0x1021078 */
  scra_vz = spdwk.w.l; /* Line 1143, Address: 0x1021090 */

  scra_v_posit.l = lSpd.l; /* Line 1145, Address: 0x102109c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1147, Address: 0x10210a8 */
  if (!ywk) { /* Line 1148, Address: 0x10210e4 */
    scra_v_count ^= 16; /* Line 1149, Address: 0x10210ec */
    ywk = scra_v_posit.w.h - ysv; /* Line 1150, Address: 0x1021100 */
    if (ywk < 0) { /* Line 1151, Address: 0x102112c */
      scrflaga.b.h |= 1; /* Line 1152, Address: 0x102113c */
    } else { /* Line 1153, Address: 0x1021150 */
      scrflaga.b.h |= 2; /* Line 1154, Address: 0x1021158 */
    }
  }


} /* Line 1159, Address: 0x102116c */

















void scrollwrt() { /* Line 1177, Address: 0x1021180 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1186, Address: 0x10211a0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1187, Address: 0x10211a4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1188, Address: 0x10211b0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1189, Address: 0x10211bc */
  pScrFlag = &scrflagbw.b.h; /* Line 1190, Address: 0x10211c4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1191, Address: 0x10211cc */

  VramBase = 16384; /* Line 1193, Address: 0x10211e0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1194, Address: 0x10211e4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1195, Address: 0x10211f0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1196, Address: 0x10211fc */
  pScrFlag = &scrflagaw.b.h; /* Line 1197, Address: 0x1021204 */

  if (*pScrFlag) { /* Line 1199, Address: 0x102120c */
    if (*pScrFlag & 1) { /* Line 1200, Address: 0x1021218 */
      *pScrFlag &= 254; /* Line 1201, Address: 0x102122c */

      lD4.l = -16; /* Line 1203, Address: 0x1021238 */
      wD5 = 65520; /* Line 1204, Address: 0x1021240 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1206, Address: 0x1021248 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1208, Address: 0x1021268 */
    }




    if (*pScrFlag & 2) { /* Line 1214, Address: 0x1021294 */
      *pScrFlag &= 253; /* Line 1215, Address: 0x10212a8 */

      lD4.l = 224; /* Line 1217, Address: 0x10212b4 */
      wD5 = 65520; /* Line 1218, Address: 0x10212bc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1219, Address: 0x10212c4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1221, Address: 0x10212e4 */
    }




    if (*pScrFlag & 4) { /* Line 1227, Address: 0x1021310 */
      *pScrFlag &= 251; /* Line 1228, Address: 0x1021324 */

      lD4.l = -16; /* Line 1230, Address: 0x1021330 */
      wD5 = 65520; /* Line 1231, Address: 0x1021338 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1232, Address: 0x1021340 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1234, Address: 0x1021360 */
    }




    if (*pScrFlag & 8) { /* Line 1240, Address: 0x102138c */
      *pScrFlag &= 247; /* Line 1241, Address: 0x10213a0 */

      lD4.l = -16; /* Line 1243, Address: 0x10213ac */
      wD5 = 320; /* Line 1244, Address: 0x10213b4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1245, Address: 0x10213bc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1247, Address: 0x10213dc */
    }
  }






} /* Line 1256, Address: 0x1021408 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1273, Address: 0x1021430 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1284, Address: 0x102145c */

  if (*pScrFlag & 1) { /* Line 1286, Address: 0x1021464 */
    *pScrFlag &= 254; /* Line 1287, Address: 0x102147c */
  } /* Line 1288, Address: 0x1021490 */
  else {
    *pScrFlag &= 254; /* Line 1290, Address: 0x1021498 */

    if (*pScrFlag & 2) { /* Line 1292, Address: 0x10214ac */
      *pScrFlag &= 253; /* Line 1293, Address: 0x10214c4 */
      lD4.w.l = 224; /* Line 1294, Address: 0x10214d8 */
    } /* Line 1295, Address: 0x10214e0 */
    else {
      *pScrFlag &= 253; /* Line 1297, Address: 0x10214e8 */
      goto label1; /* Line 1298, Address: 0x10214fc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1303, Address: 0x1021504 */
  wD0 &= 127; /* Line 1304, Address: 0x1021554 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1305, Address: 0x102155c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1311, Address: 0x102157c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1312, Address: 0x102159c */
  if (wD0 != 0) { /* Line 1313, Address: 0x10215c0 */
    wD5 = 65520; /* Line 1314, Address: 0x10215cc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1315, Address: 0x10215d4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1317, Address: 0x10215f4 */



  } /* Line 1321, Address: 0x1021620 */
  else {

    wD5 = 0; /* Line 1324, Address: 0x1021628 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1325, Address: 0x102162c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1329, Address: 0x102164c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1336, Address: 0x1021678 */






    lD4.l = -16; /* Line 1343, Address: 0x102168c */
    wD5 = 65520; /* Line 1344, Address: 0x1021694 */
    if (*pScrFlag & 168) { /* Line 1345, Address: 0x102169c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1346, Address: 0x10216b4 */
      wD5 = 320; /* Line 1347, Address: 0x10216d4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1351, Address: 0x10216dc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1353, Address: 0x102170c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1354, Address: 0x1021718 */



    for (i = 0; i < 16; ++i) { /* Line 1358, Address: 0x1021728 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1359, Address: 0x1021734 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1360, Address: 0x1021754 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1361, Address: 0x102178c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1362, Address: 0x10217ac */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1364, Address: 0x10217d0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1367, Address: 0x10217f4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1369, Address: 0x1021814 */
      }
      lD4.w.l += 16; /* Line 1371, Address: 0x1021828 */
    } /* Line 1372, Address: 0x1021834 */
    *pScrFlag = 0; /* Line 1373, Address: 0x1021844 */
  }
} /* Line 1375, Address: 0x102184c */





void scrollwrtc() {} /* Line 1381, Address: 0x1021880 */




void scrollwrtz() {} /* Line 1386, Address: 0x1021890 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1404, Address: 0x10218a0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1417, Address: 0x10218c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1420, Address: 0x10218e8 */
    pTilePoint->x += 2; /* Line 1421, Address: 0x10218fc */
    if (pTilePoint->x >= 64) { /* Line 1422, Address: 0x1021910 */
      pTilePoint->x -= 64; /* Line 1423, Address: 0x1021924 */
    }
    xOffs += 16; /* Line 1425, Address: 0x1021938 */
  } while (--lpcnt >= 0); /* Line 1426, Address: 0x1021944 */
} /* Line 1427, Address: 0x1021958 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1431, Address: 0x1021970 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1435, Address: 0x1021998 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1438, Address: 0x10219b8 */
    pTilePoint->x += 2; /* Line 1439, Address: 0x10219cc */
    if (pTilePoint->x >= 64) { /* Line 1440, Address: 0x10219e0 */
      pTilePoint->x -= 64; /* Line 1441, Address: 0x10219f4 */
    }
    xOffs += 16; /* Line 1443, Address: 0x1021a08 */
  } while (--lpcnt >= 0); /* Line 1444, Address: 0x1021a14 */
} /* Line 1445, Address: 0x1021a28 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1465, Address: 0x1021a40 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1469, Address: 0x1021a68 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1472, Address: 0x1021a88 */
    pTilePoint->y += 2; /* Line 1473, Address: 0x1021a9c */
    if (pTilePoint->y >= 32) { /* Line 1474, Address: 0x1021aac */
      pTilePoint->y -= 32; /* Line 1475, Address: 0x1021ac0 */
    }
    yOffs += 16; /* Line 1477, Address: 0x1021ad0 */
  } while (--lpcnt >= 0); /* Line 1478, Address: 0x1021adc */
} /* Line 1479, Address: 0x1021af0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1498, Address: 0x1021b00 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1504, Address: 0x1021b34 */

    base = 1; /* Line 1506, Address: 0x1021b44 */
  } /* Line 1507, Address: 0x1021b48 */
  else if (VramBase == 16384) { /* Line 1508, Address: 0x1021b50 */

    base = 0; /* Line 1510, Address: 0x1021b60 */
  }
  x = pTilePoint->x; /* Line 1512, Address: 0x1021b64 */
  y = pTilePoint->y; /* Line 1513, Address: 0x1021b6c */


  frip = BlkIndex & 6144; /* Line 1516, Address: 0x1021b74 */
  BlkIndex &= 1023; /* Line 1517, Address: 0x1021b7c */
  if (frip == 6144) { /* Line 1518, Address: 0x1021b88 */

    p0 = 3, p1 = 2; /* Line 1520, Address: 0x1021b94 */
    p2 = 1, p3 = 0; /* Line 1521, Address: 0x1021b9c */
  } /* Line 1522, Address: 0x1021ba4 */
  else if (frip & 4096) { /* Line 1523, Address: 0x1021bac */

    p0 = 2, p1 = 3; /* Line 1525, Address: 0x1021bb8 */
    p2 = 0, p3 = 1; /* Line 1526, Address: 0x1021bc0 */
  } /* Line 1527, Address: 0x1021bc8 */
  else if (frip & 2048) { /* Line 1528, Address: 0x1021bd0 */

    p0 = 1, p1 = 0; /* Line 1530, Address: 0x1021bdc */
    p2 = 3, p3 = 2; /* Line 1531, Address: 0x1021be4 */
  } /* Line 1532, Address: 0x1021bec */
  else {

    p0 = 0, p1 = 1; /* Line 1535, Address: 0x1021bf4 */
    p2 = 2, p3 = 3; /* Line 1536, Address: 0x1021bfc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1539, Address: 0x1021c04 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1540, Address: 0x1021c48 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1541, Address: 0x1021c8c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1542, Address: 0x1021cd0 */

} /* Line 1544, Address: 0x1021d14 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1562, Address: 0x1021d50 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1563, Address: 0x1021d70 */
} /* Line 1564, Address: 0x1021d90 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1566, Address: 0x1021da0 */
  wH_posiw = 0; /* Line 1567, Address: 0x1021dc0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1568, Address: 0x1021dc4 */
} /* Line 1569, Address: 0x1021de4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1576, Address: 0x1021e00 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1582, Address: 0x1021e30 */
  yOffs += wV_posiw; /* Line 1583, Address: 0x1021e40 */





  if ((short)xOffs < 0) /* Line 1589, Address: 0x1021e50 */
    xOffs = 0; /* Line 1590, Address: 0x1021e6c */
  if ((short)yOffs < 0) /* Line 1591, Address: 0x1021e70 */
    yOffs = 0; /* Line 1592, Address: 0x1021e8c */
  if ((short)xOffs >= 16384) /* Line 1593, Address: 0x1021e90 */
    xOffs = 16383; /* Line 1594, Address: 0x1021eb0 */
  if ((short)yOffs >= 2048) /* Line 1595, Address: 0x1021eb8 */
    yOffs = 2047; /* Line 1596, Address: 0x1021ed8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1597, Address: 0x1021ee0 */
  if (i < 0) i = 0; /* Line 1598, Address: 0x1021f28 */

  ScreenNo = pMapWk[i] & 127; /* Line 1600, Address: 0x1021f34 */

  if (ScreenNo) { /* Line 1602, Address: 0x1021f50 */




    xOffs &= 32767; /* Line 1607, Address: 0x1021f58 */
    yOffs &= 32767; /* Line 1608, Address: 0x1021f64 */


    xBlk = xOffs; /* Line 1611, Address: 0x1021f70 */
    xBlk %= 256; /* Line 1612, Address: 0x1021f78 */
    xBlk /= 16; /* Line 1613, Address: 0x1021f98 */
    yBlk = yOffs; /* Line 1614, Address: 0x1021fb4 */
    yBlk %= 256; /* Line 1615, Address: 0x1021fbc */
    yBlk /= 16; /* Line 1616, Address: 0x1021fdc */

    lpw = pmapwk; /* Line 1618, Address: 0x1021ff8 */
    lpw += xBlk; /* Line 1619, Address: 0x1022000 */
    lpw += yBlk * 16; /* Line 1620, Address: 0x1022008 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1621, Address: 0x1022014 */
    *pIndex = *lpw; /* Line 1622, Address: 0x102202c */

    return 1; /* Line 1624, Address: 0x102203c */
  }

  *pIndex = 0; /* Line 1627, Address: 0x1022048 */
  return 0; /* Line 1628, Address: 0x1022050 */
} /* Line 1629, Address: 0x1022054 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1649, Address: 0x1022080 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1657, Address: 0x10220a8 */
  if (ScreenNo) { /* Line 1658, Address: 0x102210c */





    xBlk = xOffs; /* Line 1664, Address: 0x1022114 */
    xBlk %= 256; /* Line 1665, Address: 0x102211c */
    xBlk /= 16; /* Line 1666, Address: 0x102213c */
    yBlk = yOffs; /* Line 1667, Address: 0x1022158 */
    yBlk %= 256; /* Line 1668, Address: 0x1022160 */
    yBlk /= 16; /* Line 1669, Address: 0x1022180 */


    lpw = pmapwk; /* Line 1672, Address: 0x102219c */
    lpw += xBlk; /* Line 1673, Address: 0x10221a4 */
    lpw += yBlk * 16; /* Line 1674, Address: 0x10221ac */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1675, Address: 0x10221b8 */
    *ppBlockNo = lpw; /* Line 1676, Address: 0x10221d0 */
    *pIndex = *lpw; /* Line 1677, Address: 0x10221d8 */




    return 1; /* Line 1682, Address: 0x10221e8 */
  }

  *pIndex = 0; /* Line 1685, Address: 0x10221f4 */
  return 0; /* Line 1686, Address: 0x10221fc */
} /* Line 1687, Address: 0x1022200 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1701, Address: 0x1022220 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1708, Address: 0x102223c */
  pMapWk = (unsigned char*)mapwka; /* Line 1709, Address: 0x1022240 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1710, Address: 0x1022248 */
    *pBlockIndex = BlockNo; /* Line 1711, Address: 0x102226c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1712, Address: 0x1022278 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1713, Address: 0x1022290 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1714, Address: 0x10222a4 */
    }
  }


} /* Line 1719, Address: 0x10222bc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1733, Address: 0x10222e0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1734, Address: 0x10222ec */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1735, Address: 0x1022318 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1736, Address: 0x1022364 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1737, Address: 0x1022390 */

          return 0; /* Line 1739, Address: 0x10223dc */
        }
      }
    }
  }

  return 1; /* Line 1745, Address: 0x10223e8 */
} /* Line 1746, Address: 0x10223ec */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1763, Address: 0x1022400 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1764, Address: 0x102241c */

} /* Line 1766, Address: 0x1022438 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1768, Address: 0x1022450 */
  wH_posiw = 0; /* Line 1769, Address: 0x102246c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1770, Address: 0x1022470 */

} /* Line 1772, Address: 0x102248c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1774, Address: 0x10224a0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x10224b4 */

} /* Line 1777, Address: 0x10224d0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x10224e0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x10224fc */

} /* Line 1782, Address: 0x1022518 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x1022530 */
  xOffs += wH_posiw; /* Line 1785, Address: 0x1022548 */
  yOffs += wV_posiw; /* Line 1786, Address: 0x1022558 */
  yOffs &= 240; /* Line 1787, Address: 0x1022568 */
  xOffs &= 496; /* Line 1788, Address: 0x1022574 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1790, Address: 0x1022580 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1791, Address: 0x10225ac */


} /* Line 1794, Address: 0x10225d8 */















void mapwrt() { /* Line 1810, Address: 0x10225f0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1817, Address: 0x1022608 */
  wV_posiw = scra_v_posit.w.h; /* Line 1818, Address: 0x1022614 */
  pMapWk = (unsigned char*)mapwka; /* Line 1819, Address: 0x1022620 */
  VramBase = 16384; /* Line 1820, Address: 0x1022628 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1821, Address: 0x102262c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1825, Address: 0x1022644 */
  VramBase = 24576; /* Line 1826, Address: 0x102264c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1827, Address: 0x1022650 */

} /* Line 1829, Address: 0x1022660 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1832, Address: 0x1022680 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1833, Address: 0x1022698 */
} /* Line 1834, Address: 0x10226b8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1839, Address: 0x10226d0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1843, Address: 0x10226f0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1846, Address: 0x102270c */



    wD4 += 16; /* Line 1850, Address: 0x1022734 */
  } while ((short)--wD6 >= 0); /* Line 1851, Address: 0x1022740 */

} /* Line 1853, Address: 0x1022768 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1859, Address: 0x1022780 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1862, Address: 0x102279c */
  wD6 = 15; /* Line 1863, Address: 0x10227a4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1866, Address: 0x10227ac */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1868, Address: 0x10227d0 */
    wD4 += 16; /* Line 1869, Address: 0x10227f0 */
  } while ((short)--wD6 >= 0); /* Line 1870, Address: 0x10227f8 */
} /* Line 1871, Address: 0x102281c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1897, Address: 0x1022840 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1902, Address: 0x1022868 */
  wD0 = pWrttbl[wD0]; /* Line 1903, Address: 0x1022878 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1905, Address: 0x1022894 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1906, Address: 0x10228b8 */
  if (wD0) { /* Line 1907, Address: 0x10228e0 */
    wD5 = 65520; /* Line 1908, Address: 0x10228ec */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1909, Address: 0x10228f4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1912, Address: 0x1022910 */



  } /* Line 1916, Address: 0x1022938 */
  else {

    wD5 = 0; /* Line 1919, Address: 0x1022940 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1920, Address: 0x1022944 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1924, Address: 0x1022960 */
  }





} /* Line 1931, Address: 0x1022988 */










void mapinit() { /* Line 1942, Address: 0x10229b0 */

  colorset2(mapinittbl.colorno2); /* Line 1944, Address: 0x10229b8 */
  colorset(mapinittbl.colorno2); /* Line 1945, Address: 0x10229cc */


  if (play_start & 2) divdevset(); /* Line 1948, Address: 0x10229e0 */
} /* Line 1949, Address: 0x1022a00 */




void mapset() {} /* Line 1954, Address: 0x1022a10 */



void divdevset() {} /* Line 1958, Address: 0x1022a20 */



void enecginit() {} /* Line 1962, Address: 0x1022a30 */
