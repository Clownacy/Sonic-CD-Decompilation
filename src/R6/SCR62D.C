#include "..\EQU.H"
#include "SCR62A.H"
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
short scr_dir_tbl[6] = { 4, 0, 9111, 0, 1808, 96 };
short playpositbl[1][2] = { { 48, 412 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;































































































































void scr_set() { /* Line 190, Address: 0x102ba20 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 193, Address: 0x102ba2c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 194, Address: 0x102ba40 */
  scr_timer.b.h = 0; /* Line 195, Address: 0x102ba54 */

  pScrTbl = scr_dir_tbl; /* Line 197, Address: 0x102ba5c */
  scrar_no = *pScrTbl; /* Line 198, Address: 0x102ba64 */
  ++pScrTbl; /* Line 199, Address: 0x102ba70 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 200, Address: 0x102ba74 */
  ++pScrTbl; /* Line 201, Address: 0x102ba88 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 202, Address: 0x102ba8c */
  ++pScrTbl; /* Line 203, Address: 0x102baa0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 204, Address: 0x102baa4 */
  ++pScrTbl; /* Line 205, Address: 0x102bab8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 206, Address: 0x102babc */
  scra_h_keep = *pScrTbl + 576; /* Line 207, Address: 0x102bad0 */
  ++pScrTbl; /* Line 208, Address: 0x102baf0 */
  scra_h_count = 16; /* Line 209, Address: 0x102baf4 */
  scra_v_count = 16; /* Line 210, Address: 0x102bb00 */

  scra_vline = *pScrTbl; /* Line 212, Address: 0x102bb0c */
  scra_hline = 160; /* Line 213, Address: 0x102bb18 */

  playposiset(); /* Line 215, Address: 0x102bb24 */
} /* Line 216, Address: 0x102bb2c */

















































void playposiset() { /* Line 266, Address: 0x102bb40 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 269, Address: 0x102bb54 */
    playload(); /* Line 270, Address: 0x102bb64 */
    xwk = actwk[0].xposi.w.h; /* Line 271, Address: 0x102bb6c */

    if (actwk[0].yposi.w.h > 0) { /* Line 273, Address: 0x102bb7c */
      ywk = actwk[0].yposi.w.h; /* Line 274, Address: 0x102bb94 */
    } else { /* Line 275, Address: 0x102bba4 */
      ywk = 0; /* Line 276, Address: 0x102bbac */
    }
  } /* Line 278, Address: 0x102bbb0 */
  else {












    pPositbl = playpositbl[0]; /* Line 292, Address: 0x102bbb8 */
    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 293, Address: 0x102bbc0 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 294, Address: 0x102bbd4 */
  }


  if (xwk > 160) { /* Line 298, Address: 0x102bbe8 */
    xwk -= 160; /* Line 299, Address: 0x102bbfc */
  } else { /* Line 300, Address: 0x102bc08 */
    xwk = 0; /* Line 301, Address: 0x102bc10 */
  }


  if (xwk > scralim_right) { /* Line 305, Address: 0x102bc14 */
    xwk = scralim_right; /* Line 306, Address: 0x102bc38 */
  }


  scra_h_posit.w.h = xwk; /* Line 310, Address: 0x102bc48 */

  if (ywk > 96) { /* Line 312, Address: 0x102bc50 */
    ywk -= 96; /* Line 313, Address: 0x102bc64 */
  } else { /* Line 314, Address: 0x102bc70 */
    ywk = 0; /* Line 315, Address: 0x102bc78 */
  }


  if (ywk > scralim_down) { /* Line 319, Address: 0x102bc7c */
    ywk = scralim_down; /* Line 320, Address: 0x102bca0 */
  }


  scra_v_posit.w.h = ywk; /* Line 324, Address: 0x102bcb0 */

  scrbinit(xwk, ywk); /* Line 326, Address: 0x102bcb8 */


  loopmapno = playmapnotbl[0]; /* Line 329, Address: 0x102bcc8 */
  loopmapno2 = playmapnotbl[1]; /* Line 330, Address: 0x102bcd8 */
  ballmapno = playmapnotbl[2]; /* Line 331, Address: 0x102bce8 */
  ballmapno2 = playmapnotbl[3]; /* Line 332, Address: 0x102bcf8 */
} /* Line 333, Address: 0x102bd08 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 354, Address: 0x102bd30 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 357, Address: 0x102bd3c */
  lYwk.w.l = 0; /* Line 358, Address: 0x102bd44 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 360, Address: 0x102bd48 */
  scrb_v_posit.l = lYwk.l; /* Line 361, Address: 0x102bd54 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 362, Address: 0x102bd60 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 363, Address: 0x102bd6c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 365, Address: 0x102bd78 */
  scrc_h_posit.w.h = sXpos; /* Line 366, Address: 0x102bd94 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 368, Address: 0x102bda0 */
  scrz_h_posit.w.h = sXpos; /* Line 369, Address: 0x102bdbc */

  sXpos = (unsigned short)sXpos >> 2; /* Line 371, Address: 0x102bdc8 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 372, Address: 0x102bde4 */
} /* Line 373, Address: 0x102be08 */















void scroll() { /* Line 389, Address: 0x102be20 */
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

  if (scroll_start.b.h) return; /* Line 401, Address: 0x102be3c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 406, Address: 0x102be4c */

  scrchk(); /* Line 408, Address: 0x102be78 */

  scroll_h(); /* Line 410, Address: 0x102be80 */
  scroll_v(); /* Line 411, Address: 0x102be88 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 413, Address: 0x102be90 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 414, Address: 0x102bea0 */


  lXwk = scra_hz << 6; /* Line 417, Address: 0x102beb0 */
  scrollz_h(lXwk, 6); /* Line 418, Address: 0x102bec4 */

  lXwk = scra_hz << 7; /* Line 420, Address: 0x102bed4 */
  scrollc_h(lXwk, 4); /* Line 421, Address: 0x102bee8 */

  lXwk = (scra_hz << 4) * 3; /* Line 423, Address: 0x102bef8 */
  scrollb_h(lXwk, 2); /* Line 424, Address: 0x102bf14 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 426, Address: 0x102bf24 */


  scrollb_v(lYwk); /* Line 429, Address: 0x102bf38 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 431, Address: 0x102bf48 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 433, Address: 0x102bf70 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 434, Address: 0x102bfa8 */

  psHscw = hscrollwork; /* Line 436, Address: 0x102bfbc */

  z61aline(&psHscw); /* Line 438, Address: 0x102bfc8 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 440, Address: 0x102bfd4 */
  for (i = 0; i < 24; ++i) { /* Line 441, Address: 0x102bff4 */

    *psHscw++ = ldwk.w.l; /* Line 443, Address: 0x102c000 */
  } /* Line 444, Address: 0x102c014 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 446, Address: 0x102c024 */
  for (i = 0; i < 46; ++i) { /* Line 447, Address: 0x102c044 */

    *psHscw++ = ldwk.w.l; /* Line 449, Address: 0x102c050 */
  } /* Line 450, Address: 0x102c064 */

  pHscrbuf = lphscrollbuff; /* Line 452, Address: 0x102c074 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 453, Address: 0x102c080 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 454, Address: 0x102c0b0 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 455, Address: 0x102c0e0 */
} /* Line 456, Address: 0x102c0fc */













void z61aline(short** ppHscw) { /* Line 470, Address: 0x102c120 */
  char z81ascrtbl[9] = { /* Line 471, Address: 0x102c144 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk;


  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 479, Address: 0x102c170 */
  radwk = 0; /* Line 480, Address: 0x102c194 */
  sXwk = scrb_h_posit.w.h; /* Line 481, Address: 0x102c198 */

  *ppHscw += 26; /* Line 483, Address: 0x102c1a8 */

  for (i = 8; i >= 0; --i) { /* Line 485, Address: 0x102c1bc */

    sinset(radwk, &sinwk, &coswk); /* Line 487, Address: 0x102c1c8 */
    hwk = -(sXwk + (short)((unsigned short)((256 - coswk) * lXwk) >> 8)); /* Line 488, Address: 0x102c1dc */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 489, Address: 0x102c230 */

      --*ppHscw; /* Line 491, Address: 0x102c248 */
      **ppHscw = hwk; /* Line 492, Address: 0x102c25c */
    } /* Line 493, Address: 0x102c268 */

    radwk += 6; /* Line 495, Address: 0x102c274 */
  } /* Line 496, Address: 0x102c280 */

  *ppHscw += 26; /* Line 498, Address: 0x102c28c */
} /* Line 499, Address: 0x102c2a0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 520, Address: 0x102c2d0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 524, Address: 0x102c2ec */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 525, Address: 0x102c2f0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 527, Address: 0x102c310 */
    ldwk.w.l = *pHscrwk; /* Line 528, Address: 0x102c32c */
    ++pHscrwk; /* Line 529, Address: 0x102c338 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 531, Address: 0x102c344 */
      (*pHscrbuf)->l = ldwk.l; /* Line 532, Address: 0x102c34c */
    } /* Line 533, Address: 0x102c35c */
  } /* Line 534, Address: 0x102c380 */
} /* Line 535, Address: 0x102c3a0 */









































































































static void scrollb_v(short yPos) { /* Line 641, Address: 0x102c3c0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 644, Address: 0x102c3d0 */
  scrb_v_posit.w.h = yPos; /* Line 645, Address: 0x102c3e0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 646, Address: 0x102c3ec */

  if (!ywk) { /* Line 648, Address: 0x102c424 */
    scrb_v_count ^= 16; /* Line 649, Address: 0x102c42c */
    if (yPos - ysv < 0) { /* Line 650, Address: 0x102c440 */
      scrflagb.b.h |= 1; /* Line 651, Address: 0x102c460 */
    } /* Line 652, Address: 0x102c474 */
    else {
      scrflagb.b.h |= 2; /* Line 654, Address: 0x102c47c */
    }
  }


} /* Line 659, Address: 0x102c490 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 677, Address: 0x102c4b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 681, Address: 0x102c4c4 */
  lXwk = lXsv + xoffs; /* Line 682, Address: 0x102c4cc */
  scrb_h_posit.l = lXwk; /* Line 683, Address: 0x102c4d4 */
  ldXwk.l = lXwk; /* Line 684, Address: 0x102c4dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 685, Address: 0x102c4e0 */
  ldXwk.w.l &= 16; /* Line 686, Address: 0x102c504 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 687, Address: 0x102c510 */

  if (!ldXwk.b.b4) { /* Line 689, Address: 0x102c52c */
    scrb_h_count ^= 16; /* Line 690, Address: 0x102c538 */
    if (lXwk - lXsv < 0) { /* Line 691, Address: 0x102c54c */
      scrflagb.b.h |= 1 << flgbit; /* Line 692, Address: 0x102c558 */
    } /* Line 693, Address: 0x102c57c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 695, Address: 0x102c584 */
    }
  }


} /* Line 700, Address: 0x102c5ac */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 718, Address: 0x102c5c0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 722, Address: 0x102c5d4 */
  lXwk = lXsv + xoffs; /* Line 723, Address: 0x102c5dc */
  scrc_h_posit.l = lXwk; /* Line 724, Address: 0x102c5e4 */
  ldXwk.l = lXwk; /* Line 725, Address: 0x102c5ec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 726, Address: 0x102c5f0 */
  ldXwk.w.l &= 16; /* Line 727, Address: 0x102c614 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 728, Address: 0x102c620 */

  if (!ldXwk.b.b4) { /* Line 730, Address: 0x102c63c */
    scrc_h_count ^= 16; /* Line 731, Address: 0x102c648 */
    if (lXwk - lXsv < 0) { /* Line 732, Address: 0x102c65c */
      scrflagc.b.h |= 1 << flgbit; /* Line 733, Address: 0x102c668 */
    } /* Line 734, Address: 0x102c68c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 736, Address: 0x102c694 */
    }
  }


} /* Line 741, Address: 0x102c6bc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 759, Address: 0x102c6d0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 763, Address: 0x102c6e4 */
  lXwk = lXsv + xoffs; /* Line 764, Address: 0x102c6ec */
  scrz_h_posit.l = lXwk; /* Line 765, Address: 0x102c6f4 */
  ldXwk.l = lXwk; /* Line 766, Address: 0x102c6fc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 767, Address: 0x102c700 */
  ldXwk.w.l &= 16; /* Line 768, Address: 0x102c724 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 769, Address: 0x102c730 */

  if (!ldXwk.b.b4) { /* Line 771, Address: 0x102c74c */
    scrz_h_count ^= 16; /* Line 772, Address: 0x102c758 */
    if (lXwk - lXsv < 0) { /* Line 773, Address: 0x102c76c */
      scrflagz.b.h |= 1 << flgbit; /* Line 774, Address: 0x102c778 */
    } /* Line 775, Address: 0x102c79c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 777, Address: 0x102c7a4 */
    }
  }


} /* Line 782, Address: 0x102c7cc */














static void scroll_h() { /* Line 797, Address: 0x102c7e0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 801, Address: 0x102c7f0 */

  scrh_move(); /* Line 803, Address: 0x102c800 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 804, Address: 0x102c808 */
  if (!bXwk) { /* Line 805, Address: 0x102c83c */
    scra_h_count ^= 16; /* Line 806, Address: 0x102c844 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 807, Address: 0x102c858 */
      scrflaga.b.h |= 4; /* Line 808, Address: 0x102c87c */
    } else { /* Line 809, Address: 0x102c890 */
      scrflaga.b.h |= 8; /* Line 810, Address: 0x102c898 */
    }
  }


} /* Line 815, Address: 0x102c8ac */
















static void scrh_move() { /* Line 832, Address: 0x102c8d0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 835, Address: 0x102c8d8 */
  if (xwk == 0) { /* Line 836, Address: 0x102c920 */

    scra_hz = 0; /* Line 838, Address: 0x102c930 */
    return; /* Line 839, Address: 0x102c938 */
  } else if (xwk < 0) { /* Line 840, Address: 0x102c940 */

    if (xwk < -16) { /* Line 842, Address: 0x102c950 */
      xwk = -16; /* Line 843, Address: 0x102c964 */
    }


    xwk += scra_h_posit.w.h; /* Line 847, Address: 0x102c970 */
    if (xwk < scralim_left) { /* Line 848, Address: 0x102c984 */
      xwk = scralim_left; /* Line 849, Address: 0x102c9a8 */
    }
  } /* Line 851, Address: 0x102c9b8 */
  else {
    if (xwk > 16) { /* Line 853, Address: 0x102c9c0 */
      xwk = 16; /* Line 854, Address: 0x102c9d4 */
    }


    xwk += scra_h_posit.w.h; /* Line 858, Address: 0x102c9e0 */
    if (xwk > scralim_right) { /* Line 859, Address: 0x102c9f4 */
      xwk = scralim_right; /* Line 860, Address: 0x102ca18 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 865, Address: 0x102ca28 */
  scra_h_posit.w.h = xwk; /* Line 866, Address: 0x102ca58 */
} /* Line 867, Address: 0x102ca60 */














static void scroll_v() { /* Line 882, Address: 0x102ca70 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 885, Address: 0x102ca7c */
  if (actwk[0].cddat & 4) { /* Line 886, Address: 0x102cab0 */
    ywk -= 5; /* Line 887, Address: 0x102cac8 */
  }


  if (actwk[0].cddat & 2) { /* Line 891, Address: 0x102cad4 */
    ywk += 32; /* Line 892, Address: 0x102caec */
    if (ywk < scra_vline) { /* Line 893, Address: 0x102caf8 */
      ywk -= scra_vline; /* Line 894, Address: 0x102cb1c */
      sv_move_main2(ywk); /* Line 895, Address: 0x102cb30 */
      return; /* Line 896, Address: 0x102cb3c */
    } else if (ywk >= scra_vline + 64) { /* Line 897, Address: 0x102cb44 */
      ywk -= scra_vline + 64; /* Line 898, Address: 0x102cb6c */
      sv_move_main2(ywk); /* Line 899, Address: 0x102cb94 */
      return; /* Line 900, Address: 0x102cba0 */
    }
    ywk -= scra_vline + 64; /* Line 902, Address: 0x102cba8 */
    if (!limmoveflag) goto label1; /* Line 903, Address: 0x102cbd0 */
    sv_move_sub2(); /* Line 904, Address: 0x102cbe0 */
    return; /* Line 905, Address: 0x102cbe8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 910, Address: 0x102cbf0 */
    sv_move_main(ywk); /* Line 911, Address: 0x102cc1c */
    return; /* Line 912, Address: 0x102cc28 */
  } else if (!limmoveflag) goto label1; /* Line 913, Address: 0x102cc30 */
  sv_move_sub2(); /* Line 914, Address: 0x102cc40 */
  return; /* Line 915, Address: 0x102cc48 */



label1:
  scra_vz = 0; /* Line 920, Address: 0x102cc50 */
} /* Line 921, Address: 0x102cc58 */













static void sv_move_main(short yPos) { /* Line 935, Address: 0x102cc70 */
  short spdwk;

  if (scra_vline == 96) { /* Line 938, Address: 0x102cc80 */
    if (actwk[0].mspeed.w < 0) { /* Line 939, Address: 0x102cc9c */
      spdwk = -actwk[0].mspeed.w; /* Line 940, Address: 0x102ccb4 */
    } else { /* Line 941, Address: 0x102ccd8 */
      spdwk = actwk[0].mspeed.w; /* Line 942, Address: 0x102cce0 */
    }


    if (spdwk >= 2048) { /* Line 946, Address: 0x102ccf0 */
      sv_move_main2(yPos); /* Line 947, Address: 0x102cd04 */
    } /* Line 948, Address: 0x102cd10 */
    else {

      if (yPos > 6) { /* Line 951, Address: 0x102cd18 */
        sv_move_plus(1536); /* Line 952, Address: 0x102cd30 */
      } else if (yPos < -6) { /* Line 953, Address: 0x102cd3c */
        sv_move_minus(1536); /* Line 954, Address: 0x102cd5c */
      } /* Line 955, Address: 0x102cd68 */
      else sv_move_sub(yPos); /* Line 956, Address: 0x102cd70 */
    }
  } /* Line 958, Address: 0x102cd7c */
  else {
    if (yPos > 2) { /* Line 960, Address: 0x102cd84 */
      sv_move_plus(512); /* Line 961, Address: 0x102cd9c */
    } else if (yPos < -2) { /* Line 962, Address: 0x102cda8 */
      sv_move_minus(512); /* Line 963, Address: 0x102cdc8 */
    } /* Line 964, Address: 0x102cdd4 */
    else sv_move_sub(yPos); /* Line 965, Address: 0x102cddc */
  }

} /* Line 968, Address: 0x102cde8 */













static void sv_move_main2(short yPos) { /* Line 982, Address: 0x102ce00 */
  short spdwk;

  spdwk = 4096; /* Line 985, Address: 0x102ce10 */

  if (yPos > 16) { /* Line 987, Address: 0x102ce1c */
    sv_move_plus(spdwk); /* Line 988, Address: 0x102ce34 */
  } else if (yPos < -16) { /* Line 989, Address: 0x102ce40 */
    sv_move_minus(spdwk); /* Line 990, Address: 0x102ce60 */
  } else { /* Line 991, Address: 0x102ce6c */
    sv_move_sub(yPos); /* Line 992, Address: 0x102ce74 */
  }
} /* Line 994, Address: 0x102ce80 */














static void sv_move_sub(short yPos) { /* Line 1009, Address: 0x102cea0 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1012, Address: 0x102ceac */
  if (yPos < 0) { /* Line 1013, Address: 0x102ced8 */
    scrv_up_ch(lSpd); /* Line 1014, Address: 0x102ceec */
  } else { /* Line 1015, Address: 0x102cef8 */
    scrv_down_ch(lSpd); /* Line 1016, Address: 0x102cf00 */
  }
} /* Line 1018, Address: 0x102cf0c */



static void sv_move_sub2() { /* Line 1022, Address: 0x102cf20 */
  limmoveflag = 0; /* Line 1023, Address: 0x102cf28 */

  sv_move_sub(0); /* Line 1025, Address: 0x102cf30 */
} /* Line 1026, Address: 0x102cf3c */













static void sv_move_minus(short speed) { /* Line 1040, Address: 0x102cf50 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1043, Address: 0x102cf5c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1044, Address: 0x102cf80 */
  scrv_up_ch(lSpd); /* Line 1045, Address: 0x102cfa4 */
} /* Line 1046, Address: 0x102cfb0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1061, Address: 0x102cfc0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1062, Address: 0x102cfcc */
    if (lSpd.w.l > -256) { /* Line 1063, Address: 0x102cff4 */

      lSpd.w.l = scralim_up; /* Line 1065, Address: 0x102d00c */
    } else { /* Line 1066, Address: 0x102d018 */
      lSpd.w.l &= 2047; /* Line 1067, Address: 0x102d020 */
      actwk[0].yposi.w.h &= 2047; /* Line 1068, Address: 0x102d02c */
      scra_v_posit.w.h &= 2047; /* Line 1069, Address: 0x102d040 */
      scrb_v_posit.w.h &= 1023; /* Line 1070, Address: 0x102d054 */
    }
  }

  scrv_move(lSpd); /* Line 1074, Address: 0x102d068 */
} /* Line 1075, Address: 0x102d074 */













static void sv_move_plus(short sSpd) { /* Line 1089, Address: 0x102d090 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1092, Address: 0x102d09c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1093, Address: 0x102d0bc */
  scrv_down_ch(lSpd); /* Line 1094, Address: 0x102d0e0 */
} /* Line 1095, Address: 0x102d0ec */














static void scrv_down_ch(int_union lSpd) { /* Line 1110, Address: 0x102d100 */
  if (lSpd.w.l >= scralim_down) { /* Line 1111, Address: 0x102d10c */
    if (lSpd.w.l < 2048) { /* Line 1112, Address: 0x102d134 */

      lSpd.w.l = scralim_down; /* Line 1114, Address: 0x102d14c */
    } else { /* Line 1115, Address: 0x102d158 */
      lSpd.w.l -= 2048; /* Line 1116, Address: 0x102d160 */
      actwk[0].yposi.w.h &= 2047; /* Line 1117, Address: 0x102d16c */
      scra_v_posit.w.h -= 2048; /* Line 1118, Address: 0x102d180 */
      scrb_v_posit.w.h &= 1023; /* Line 1119, Address: 0x102d194 */
    }
  }

  scrv_move(lSpd); /* Line 1123, Address: 0x102d1a8 */
} /* Line 1124, Address: 0x102d1b4 */
















static void scrv_move(int_union lSpd) { /* Line 1141, Address: 0x102d1d0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1145, Address: 0x102d1e0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1146, Address: 0x102d1f0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1147, Address: 0x102d214 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1148, Address: 0x102d228 */
  scra_vz = spdwk.w.l; /* Line 1149, Address: 0x102d240 */

  scra_v_posit.l = lSpd.l; /* Line 1151, Address: 0x102d24c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1153, Address: 0x102d258 */
  if (!ywk) { /* Line 1154, Address: 0x102d294 */
    scra_v_count ^= 16; /* Line 1155, Address: 0x102d29c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1156, Address: 0x102d2b0 */
    if (ywk < 0) { /* Line 1157, Address: 0x102d2dc */
      scrflaga.b.h |= 1; /* Line 1158, Address: 0x102d2ec */
    } else { /* Line 1159, Address: 0x102d300 */
      scrflaga.b.h |= 2; /* Line 1160, Address: 0x102d308 */
    }
  }


} /* Line 1165, Address: 0x102d31c */

















void scrollwrt() { /* Line 1183, Address: 0x102d330 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1192, Address: 0x102d350 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1193, Address: 0x102d354 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1194, Address: 0x102d360 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1195, Address: 0x102d36c */
  pScrFlag = &scrflagbw.b.h; /* Line 1196, Address: 0x102d374 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1197, Address: 0x102d37c */

  VramBase = 16384; /* Line 1199, Address: 0x102d390 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1200, Address: 0x102d394 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1201, Address: 0x102d3a0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1202, Address: 0x102d3ac */
  pScrFlag = &scrflagaw.b.h; /* Line 1203, Address: 0x102d3b4 */

  if (*pScrFlag) { /* Line 1205, Address: 0x102d3bc */
    if (*pScrFlag & 1) { /* Line 1206, Address: 0x102d3c8 */
      *pScrFlag &= 254; /* Line 1207, Address: 0x102d3dc */

      lD4.l = -16; /* Line 1209, Address: 0x102d3e8 */
      wD5 = 65520; /* Line 1210, Address: 0x102d3f0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1212, Address: 0x102d3f8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1214, Address: 0x102d418 */
    }




    if (*pScrFlag & 2) { /* Line 1220, Address: 0x102d444 */
      *pScrFlag &= 253; /* Line 1221, Address: 0x102d458 */

      lD4.l = 224; /* Line 1223, Address: 0x102d464 */
      wD5 = 65520; /* Line 1224, Address: 0x102d46c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1225, Address: 0x102d474 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1227, Address: 0x102d494 */
    }




    if (*pScrFlag & 4) { /* Line 1233, Address: 0x102d4c0 */
      *pScrFlag &= 251; /* Line 1234, Address: 0x102d4d4 */

      lD4.l = -16; /* Line 1236, Address: 0x102d4e0 */
      wD5 = 65520; /* Line 1237, Address: 0x102d4e8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1238, Address: 0x102d4f0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1240, Address: 0x102d510 */
    }




    if (*pScrFlag & 8) { /* Line 1246, Address: 0x102d53c */
      *pScrFlag &= 247; /* Line 1247, Address: 0x102d550 */

      lD4.l = -16; /* Line 1249, Address: 0x102d55c */
      wD5 = 320; /* Line 1250, Address: 0x102d564 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1251, Address: 0x102d56c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1253, Address: 0x102d58c */
    }
  }






} /* Line 1262, Address: 0x102d5b8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1279, Address: 0x102d5e0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1290, Address: 0x102d60c */

  if (*pScrFlag & 1) { /* Line 1292, Address: 0x102d614 */
    *pScrFlag &= 254; /* Line 1293, Address: 0x102d62c */
  } /* Line 1294, Address: 0x102d640 */
  else {
    *pScrFlag &= 254; /* Line 1296, Address: 0x102d648 */

    if (*pScrFlag & 2) { /* Line 1298, Address: 0x102d65c */
      *pScrFlag &= 253; /* Line 1299, Address: 0x102d674 */
      lD4.w.l = 224; /* Line 1300, Address: 0x102d688 */
    } /* Line 1301, Address: 0x102d690 */
    else {
      *pScrFlag &= 253; /* Line 1303, Address: 0x102d698 */
      goto label1; /* Line 1304, Address: 0x102d6ac */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1309, Address: 0x102d6b4 */
  wD0 &= 127; /* Line 1310, Address: 0x102d704 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1311, Address: 0x102d70c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1317, Address: 0x102d72c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1318, Address: 0x102d74c */
  if (wD0 != 0) { /* Line 1319, Address: 0x102d770 */
    wD5 = 65520; /* Line 1320, Address: 0x102d77c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1321, Address: 0x102d784 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1323, Address: 0x102d7a4 */



  } /* Line 1327, Address: 0x102d7d0 */
  else {

    wD5 = 0; /* Line 1330, Address: 0x102d7d8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x102d7dc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1335, Address: 0x102d7fc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1342, Address: 0x102d828 */






    lD4.l = -16; /* Line 1349, Address: 0x102d83c */
    wD5 = 65520; /* Line 1350, Address: 0x102d844 */
    if (*pScrFlag & 168) { /* Line 1351, Address: 0x102d84c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1352, Address: 0x102d864 */
      wD5 = 320; /* Line 1353, Address: 0x102d884 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1357, Address: 0x102d88c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1359, Address: 0x102d8bc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1360, Address: 0x102d8c8 */



    for (i = 0; i < 16; ++i) { /* Line 1364, Address: 0x102d8d8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1365, Address: 0x102d8e4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1366, Address: 0x102d904 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1367, Address: 0x102d93c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1368, Address: 0x102d95c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1370, Address: 0x102d980 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1373, Address: 0x102d9a4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1375, Address: 0x102d9c4 */
      }
      lD4.w.l += 16; /* Line 1377, Address: 0x102d9d8 */
    } /* Line 1378, Address: 0x102d9e4 */
    *pScrFlag = 0; /* Line 1379, Address: 0x102d9f4 */
  }
} /* Line 1381, Address: 0x102d9fc */





void scrollwrtc() {} /* Line 1387, Address: 0x102da30 */




void scrollwrtz() {} /* Line 1392, Address: 0x102da40 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1410, Address: 0x102da50 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1423, Address: 0x102da78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1426, Address: 0x102da98 */
    pTilePoint->x += 2; /* Line 1427, Address: 0x102daac */
    if (pTilePoint->x >= 64) { /* Line 1428, Address: 0x102dac0 */
      pTilePoint->x -= 64; /* Line 1429, Address: 0x102dad4 */
    }
    xOffs += 16; /* Line 1431, Address: 0x102dae8 */
  } while (--lpcnt >= 0); /* Line 1432, Address: 0x102daf4 */
} /* Line 1433, Address: 0x102db08 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1437, Address: 0x102db20 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1441, Address: 0x102db48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1444, Address: 0x102db68 */
    pTilePoint->x += 2; /* Line 1445, Address: 0x102db7c */
    if (pTilePoint->x >= 64) { /* Line 1446, Address: 0x102db90 */
      pTilePoint->x -= 64; /* Line 1447, Address: 0x102dba4 */
    }
    xOffs += 16; /* Line 1449, Address: 0x102dbb8 */
  } while (--lpcnt >= 0); /* Line 1450, Address: 0x102dbc4 */
} /* Line 1451, Address: 0x102dbd8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1471, Address: 0x102dbf0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1475, Address: 0x102dc18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1478, Address: 0x102dc38 */
    pTilePoint->y += 2; /* Line 1479, Address: 0x102dc4c */
    if (pTilePoint->y >= 32) { /* Line 1480, Address: 0x102dc5c */
      pTilePoint->y -= 32; /* Line 1481, Address: 0x102dc70 */
    }
    yOffs += 16; /* Line 1483, Address: 0x102dc80 */
  } while (--lpcnt >= 0); /* Line 1484, Address: 0x102dc8c */
} /* Line 1485, Address: 0x102dca0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1504, Address: 0x102dcb0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1510, Address: 0x102dce4 */

    base = 1; /* Line 1512, Address: 0x102dcf4 */
  } /* Line 1513, Address: 0x102dcf8 */
  else if (VramBase == 16384) { /* Line 1514, Address: 0x102dd00 */

    base = 0; /* Line 1516, Address: 0x102dd10 */
  }
  x = pTilePoint->x; /* Line 1518, Address: 0x102dd14 */
  y = pTilePoint->y; /* Line 1519, Address: 0x102dd1c */


  frip = BlkIndex & 6144; /* Line 1522, Address: 0x102dd24 */
  BlkIndex &= 1023; /* Line 1523, Address: 0x102dd2c */
  if (frip == 6144) { /* Line 1524, Address: 0x102dd38 */

    p0 = 3, p1 = 2; /* Line 1526, Address: 0x102dd44 */
    p2 = 1, p3 = 0; /* Line 1527, Address: 0x102dd4c */
  } /* Line 1528, Address: 0x102dd54 */
  else if (frip & 4096) { /* Line 1529, Address: 0x102dd5c */

    p0 = 2, p1 = 3; /* Line 1531, Address: 0x102dd68 */
    p2 = 0, p3 = 1; /* Line 1532, Address: 0x102dd70 */
  } /* Line 1533, Address: 0x102dd78 */
  else if (frip & 2048) { /* Line 1534, Address: 0x102dd80 */

    p0 = 1, p1 = 0; /* Line 1536, Address: 0x102dd8c */
    p2 = 3, p3 = 2; /* Line 1537, Address: 0x102dd94 */
  } /* Line 1538, Address: 0x102dd9c */
  else {

    p0 = 0, p1 = 1; /* Line 1541, Address: 0x102dda4 */
    p2 = 2, p3 = 3; /* Line 1542, Address: 0x102ddac */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1545, Address: 0x102ddb4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1546, Address: 0x102ddf8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1547, Address: 0x102de3c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1548, Address: 0x102de80 */

} /* Line 1550, Address: 0x102dec4 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1567, Address: 0x102df00 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1568, Address: 0x102df20 */
} /* Line 1569, Address: 0x102df40 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1571, Address: 0x102df50 */
  wH_posiw = 0; /* Line 1572, Address: 0x102df70 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1573, Address: 0x102df74 */
} /* Line 1574, Address: 0x102df94 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1581, Address: 0x102dfb0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1587, Address: 0x102dfe0 */
  yOffs += wV_posiw; /* Line 1588, Address: 0x102dff0 */





  if ((short)xOffs < 0) /* Line 1594, Address: 0x102e000 */
    xOffs = 0; /* Line 1595, Address: 0x102e01c */
  if ((short)yOffs < 0) /* Line 1596, Address: 0x102e020 */
    yOffs = 0; /* Line 1597, Address: 0x102e03c */
  if ((short)xOffs >= 16384) /* Line 1598, Address: 0x102e040 */
    xOffs = 16383; /* Line 1599, Address: 0x102e060 */
  if ((short)yOffs >= 2048) /* Line 1600, Address: 0x102e068 */
    yOffs = 2047; /* Line 1601, Address: 0x102e088 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1602, Address: 0x102e090 */
  if (i < 0) i = 0; /* Line 1603, Address: 0x102e0d8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1605, Address: 0x102e0e4 */

  if (ScreenNo) { /* Line 1607, Address: 0x102e100 */




    xOffs &= 32767; /* Line 1612, Address: 0x102e108 */
    yOffs &= 32767; /* Line 1613, Address: 0x102e114 */


    xBlk = xOffs; /* Line 1616, Address: 0x102e120 */
    xBlk %= 256; /* Line 1617, Address: 0x102e128 */
    xBlk /= 16; /* Line 1618, Address: 0x102e148 */
    yBlk = yOffs; /* Line 1619, Address: 0x102e164 */
    yBlk %= 256; /* Line 1620, Address: 0x102e16c */
    yBlk /= 16; /* Line 1621, Address: 0x102e18c */

    lpw = pmapwk; /* Line 1623, Address: 0x102e1a8 */
    lpw += xBlk; /* Line 1624, Address: 0x102e1b0 */
    lpw += yBlk * 16; /* Line 1625, Address: 0x102e1b8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1626, Address: 0x102e1c4 */
    *pIndex = *lpw; /* Line 1627, Address: 0x102e1dc */

    return 1; /* Line 1629, Address: 0x102e1ec */
  }

  *pIndex = 0; /* Line 1632, Address: 0x102e1f8 */
  return 0; /* Line 1633, Address: 0x102e200 */
} /* Line 1634, Address: 0x102e204 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1654, Address: 0x102e230 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1662, Address: 0x102e258 */
  if (ScreenNo) { /* Line 1663, Address: 0x102e2bc */





    xBlk = xOffs; /* Line 1669, Address: 0x102e2c4 */
    xBlk %= 256; /* Line 1670, Address: 0x102e2cc */
    xBlk /= 16; /* Line 1671, Address: 0x102e2ec */
    yBlk = yOffs; /* Line 1672, Address: 0x102e308 */
    yBlk %= 256; /* Line 1673, Address: 0x102e310 */
    yBlk /= 16; /* Line 1674, Address: 0x102e330 */


    lpw = pmapwk; /* Line 1677, Address: 0x102e34c */
    lpw += xBlk; /* Line 1678, Address: 0x102e354 */
    lpw += yBlk * 16; /* Line 1679, Address: 0x102e35c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1680, Address: 0x102e368 */
    *ppBlockNo = lpw; /* Line 1681, Address: 0x102e380 */
    *pIndex = *lpw; /* Line 1682, Address: 0x102e388 */




    return 1; /* Line 1687, Address: 0x102e398 */
  }

  *pIndex = 0; /* Line 1690, Address: 0x102e3a4 */
  return 0; /* Line 1691, Address: 0x102e3ac */
} /* Line 1692, Address: 0x102e3b0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1706, Address: 0x102e3d0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1713, Address: 0x102e3ec */
  pMapWk = (unsigned char*)mapwka; /* Line 1714, Address: 0x102e3f0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1715, Address: 0x102e3f8 */
    *pBlockIndex = BlockNo; /* Line 1716, Address: 0x102e41c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1717, Address: 0x102e428 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1718, Address: 0x102e440 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1719, Address: 0x102e454 */
    }
  }


} /* Line 1724, Address: 0x102e46c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1738, Address: 0x102e490 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1739, Address: 0x102e49c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1740, Address: 0x102e4c8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1741, Address: 0x102e514 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1742, Address: 0x102e540 */

          return 0; /* Line 1744, Address: 0x102e58c */
        }
      }
    }
  }

  return 1; /* Line 1750, Address: 0x102e598 */
} /* Line 1751, Address: 0x102e59c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1768, Address: 0x102e5b0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1769, Address: 0x102e5cc */

} /* Line 1771, Address: 0x102e5e8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1773, Address: 0x102e600 */
  wH_posiw = 0; /* Line 1774, Address: 0x102e61c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1775, Address: 0x102e620 */

} /* Line 1777, Address: 0x102e63c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1779, Address: 0x102e650 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1780, Address: 0x102e664 */

} /* Line 1782, Address: 0x102e680 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1784, Address: 0x102e690 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1785, Address: 0x102e6ac */

} /* Line 1787, Address: 0x102e6c8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1789, Address: 0x102e6e0 */
  xOffs += wH_posiw; /* Line 1790, Address: 0x102e6f8 */
  yOffs += wV_posiw; /* Line 1791, Address: 0x102e708 */
  yOffs &= 240; /* Line 1792, Address: 0x102e718 */
  xOffs &= 496; /* Line 1793, Address: 0x102e724 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1795, Address: 0x102e730 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1796, Address: 0x102e75c */


} /* Line 1799, Address: 0x102e788 */















void mapwrt() { /* Line 1815, Address: 0x102e7a0 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1822, Address: 0x102e7b8 */
  wV_posiw = scra_v_posit.w.h; /* Line 1823, Address: 0x102e7c4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1824, Address: 0x102e7d0 */
  VramBase = 16384; /* Line 1825, Address: 0x102e7d8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1826, Address: 0x102e7dc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1830, Address: 0x102e7f4 */
  VramBase = 24576; /* Line 1831, Address: 0x102e7fc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1832, Address: 0x102e800 */

} /* Line 1834, Address: 0x102e810 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1837, Address: 0x102e830 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1838, Address: 0x102e848 */
} /* Line 1839, Address: 0x102e868 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1844, Address: 0x102e880 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1848, Address: 0x102e8a0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1851, Address: 0x102e8bc */



    wD4 += 16; /* Line 1855, Address: 0x102e8e4 */
  } while ((short)--wD6 >= 0); /* Line 1856, Address: 0x102e8f0 */

} /* Line 1858, Address: 0x102e918 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1864, Address: 0x102e930 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1867, Address: 0x102e94c */
  wD6 = 15; /* Line 1868, Address: 0x102e954 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1871, Address: 0x102e95c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1873, Address: 0x102e980 */
    wD4 += 16; /* Line 1874, Address: 0x102e9a0 */
  } while ((short)--wD6 >= 0); /* Line 1875, Address: 0x102e9a8 */
} /* Line 1876, Address: 0x102e9cc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1902, Address: 0x102e9f0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1907, Address: 0x102ea18 */
  wD0 = pWrttbl[wD0]; /* Line 1908, Address: 0x102ea28 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1910, Address: 0x102ea44 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1911, Address: 0x102ea68 */
  if (wD0) { /* Line 1912, Address: 0x102ea90 */
    wD5 = 65520; /* Line 1913, Address: 0x102ea9c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1914, Address: 0x102eaa4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1917, Address: 0x102eac0 */



  } /* Line 1921, Address: 0x102eae8 */
  else {

    wD5 = 0; /* Line 1924, Address: 0x102eaf0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1925, Address: 0x102eaf4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1929, Address: 0x102eb10 */
  }





} /* Line 1936, Address: 0x102eb38 */










void mapinit() { /* Line 1947, Address: 0x102eb60 */

  colorset2(mapinittbl.colorno2); /* Line 1949, Address: 0x102eb68 */
  colorset(mapinittbl.colorno2); /* Line 1950, Address: 0x102eb7c */


  if (play_start & 2) divdevset(); /* Line 1953, Address: 0x102eb90 */
} /* Line 1954, Address: 0x102ebb0 */




void mapset() {} /* Line 1959, Address: 0x102ebc0 */



void divdevset() {} /* Line 1963, Address: 0x102ebd0 */



void enecginit() {} /* Line 1967, Address: 0x102ebe0 */
