#include "..\EQU.H"
#include "SCR13C.H"

static unsigned char z12dwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
  6, 6, 2, 4, 4, 4, 0, 0, 0, 0,
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
short scr_dir_tbl[6] = { 4, 0, 3479, 0, 784, 96 };
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
short playpositbl[1][2] = {
  { 64, 674 }
};
unsigned char playmapnotbl[4] = { 145, 127, 30, 30 };
extern void(*sMemSet)(void*, unsigned char, int);
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_info mapinittbl;



































































































act_info* main_chk() {
  if (main_play == 0) { /* Line 150, Address: 0x1024550 */
    return &actwk[0]; /* Line 151, Address: 0x1024564 */
  }
  return &actwk[1]; /* Line 153, Address: 0x1024574 */

} /* Line 155, Address: 0x102457c */





































void scr_set() { /* Line 193, Address: 0x1024590 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 196, Address: 0x102459c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x10245b0 */
  scr_timer.b.h = 0; /* Line 198, Address: 0x10245c4 */

  pScrTbl = scr_dir_tbl; /* Line 200, Address: 0x10245cc */
  scrar_no = *pScrTbl; /* Line 201, Address: 0x10245d4 */
  ++pScrTbl; /* Line 202, Address: 0x10245e0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 203, Address: 0x10245e4 */
  ++pScrTbl; /* Line 204, Address: 0x10245f8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 205, Address: 0x10245fc */
  ++pScrTbl; /* Line 206, Address: 0x1024610 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 207, Address: 0x1024614 */
  ++pScrTbl; /* Line 208, Address: 0x1024628 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 209, Address: 0x102462c */
  scra_h_keep = *pScrTbl + 576; /* Line 210, Address: 0x1024640 */
  ++pScrTbl; /* Line 211, Address: 0x1024660 */
  scra_h_count = 16; /* Line 212, Address: 0x1024664 */
  scra_v_count = 16; /* Line 213, Address: 0x1024670 */

  scra_vline = *pScrTbl; /* Line 215, Address: 0x102467c */
  scra_hline = 160; /* Line 216, Address: 0x1024688 */

  playposiset(); /* Line 218, Address: 0x1024694 */
} /* Line 219, Address: 0x102469c */
















































static void playposiset() { /* Line 268, Address: 0x10246b0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 271, Address: 0x10246c4 */
    playload(); /* Line 272, Address: 0x10246d4 */
    xwk = actwk[0].xposi.w.h; /* Line 273, Address: 0x10246dc */

    if (actwk[0].yposi.w.h > 0) { /* Line 275, Address: 0x10246ec */
      ywk = actwk[0].yposi.w.h; /* Line 276, Address: 0x1024704 */
    } /* Line 277, Address: 0x1024714 */
    else xwk = 0; /* Line 278, Address: 0x102471c */

  } /* Line 280, Address: 0x1024720 */
  else {
    if (demoflag.w & -32768) { /* Line 282, Address: 0x1024728 */
      pPositbl = &endplpositbl[enddemono - 1][0]; /* Line 283, Address: 0x1024748 */
    } /* Line 284, Address: 0x102476c */
    else {
      pPositbl = &playpositbl[demoflag.w][0]; /* Line 286, Address: 0x1024774 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 290, Address: 0x1024794 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 291, Address: 0x10247a8 */
  }


  if (xwk >= 161) { /* Line 295, Address: 0x10247bc */
    xwk -= 160; /* Line 296, Address: 0x10247d0 */
  } /* Line 297, Address: 0x10247dc */
  else xwk = 0; /* Line 298, Address: 0x10247e4 */



  if (xwk > scralim_right) { /* Line 302, Address: 0x10247e8 */
    xwk = scralim_right; /* Line 303, Address: 0x102480c */
  }


  scra_h_posit.w.h = xwk; /* Line 307, Address: 0x102481c */

  if (ywk >= 97) { /* Line 309, Address: 0x1024824 */
    ywk -= 96; /* Line 310, Address: 0x1024838 */
  } /* Line 311, Address: 0x1024844 */
  else ywk = 0; /* Line 312, Address: 0x102484c */



  if (ywk > scralim_down) { /* Line 316, Address: 0x1024850 */
    ywk = scralim_down; /* Line 317, Address: 0x1024874 */
  }


  ywk = scra_v_posit.w.h; /* Line 321, Address: 0x1024884 */

  scrbinit(xwk, ywk); /* Line 323, Address: 0x102488c */


  loopmapno = playmapnotbl[0]; /* Line 326, Address: 0x102489c */
  loopmapno2 = playmapnotbl[1]; /* Line 327, Address: 0x10248ac */
  ballmapno = playmapnotbl[2]; /* Line 328, Address: 0x10248bc */
  ballmapno2 = playmapnotbl[3]; /* Line 329, Address: 0x10248cc */
} /* Line 330, Address: 0x10248dc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 351, Address: 0x1024900 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 354, Address: 0x1024910 */
  lYwk.w.l = 0; /* Line 355, Address: 0x1024918 */

  lYwk.l = (lYwk.l >> 4) * 3; /* Line 357, Address: 0x102491c */
  scrb_v_posit.l = lYwk.l; /* Line 358, Address: 0x1024930 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 359, Address: 0x102493c */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 360, Address: 0x1024948 */

  sXpos >>= 3; /* Line 362, Address: 0x1024954 */
  scrb_h_posit.w.h = sXpos; /* Line 363, Address: 0x1024960 */

  sXpos >>= 1; /* Line 365, Address: 0x102496c */
  scrc_h_posit.w.h = sXpos * 3; /* Line 366, Address: 0x1024978 */

  sXpos >>= 1; /* Line 368, Address: 0x102499c */
  scrz_h_posit.w.h = sXpos * 3; /* Line 369, Address: 0x10249a8 */
  sMemSet(hscrollwork, 0, 16); /* Line 370, Address: 0x10249cc */
} /* Line 371, Address: 0x10249ec */















void scroll() { /* Line 387, Address: 0x1024a00 */
  int_union ldwk, ldwk2;
  int_union* pHscrbuf;
  int i, j;
  int lXwk, lYwk;
  short sYline;
  short sYnum;
  short *psHscr, *psHscw;
  short wk;
  static unsigned char z12d_cnttbl[4] = { 0, 4, 3, 3 };
  static int scaddtbl[4] = { 65536, 49152, 32768, 16384 };

  if (scroll_start.b.h) return; /* Line 399, Address: 0x1024a2c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 404, Address: 0x1024a3c */

  scrchk(); /* Line 406, Address: 0x1024a68 */

  scroll_h(); /* Line 408, Address: 0x1024a70 */
  scroll_v(); /* Line 409, Address: 0x1024a78 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 411, Address: 0x1024a80 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 412, Address: 0x1024a90 */


  lXwk = scra_hz * 8 * 3; /* Line 415, Address: 0x1024aa0 */
  scrollz_h(lXwk, 6); /* Line 416, Address: 0x1024abc */

  lXwk = scra_hz * 16 * 3; /* Line 418, Address: 0x1024acc */
  scrollc_h(lXwk, 4); /* Line 419, Address: 0x1024ae8 */

  lXwk = scra_hz * 32; /* Line 421, Address: 0x1024af8 */
  lYwk = scra_vz * 16 * 3; /* Line 422, Address: 0x1024b0c */
  scrollb_hv(lXwk, lYwk); /* Line 423, Address: 0x1024b2c */
  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x1024b3c */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x1024b64 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x1024b9c */

  for (i = 0, psHscr = hscrollwork; i < 4; ++i) { /* Line 429, Address: 0x1024bb0 */
    ldwk.w.l = psHscr[0]; /* Line 430, Address: 0x1024bc4 */
    ldwk.w.h = psHscr[1]; /* Line 431, Address: 0x1024bcc */
    ldwk.l += scaddtbl[i]; /* Line 432, Address: 0x1024bd4 */
    psHscr[0] = ldwk.w.l; /* Line 433, Address: 0x1024bf4 */
    psHscr[1] = ldwk.w.h; /* Line 434, Address: 0x1024bfc */
    psHscr += 2; /* Line 435, Address: 0x1024c04 */
  } /* Line 436, Address: 0x1024c08 */

  ldwk.w.l = -scra_h_posit.w.h; /* Line 438, Address: 0x1024c18 */
  wk = ldwk.w.l, ldwk.w.l = ldwk.w.h, ldwk.w.h = wk; /* Line 439, Address: 0x1024c38 */
  psHscr = &hscrollwork[0]; /* Line 440, Address: 0x1024c50 */
  psHscw = &hscrollwork[8]; /* Line 441, Address: 0x1024c58 */

  for (i = 3; i >= 0; --i) { /* Line 443, Address: 0x1024c60 */

    ldwk2.w.l = *psHscr; /* Line 445, Address: 0x1024c6c */
    ++psHscr; /* Line 446, Address: 0x1024c74 */
    ldwk2.w.h = *psHscr; /* Line 447, Address: 0x1024c78 */
    ++psHscr; /* Line 448, Address: 0x1024c80 */
    wk = ldwk2.w.l, ldwk2.w.l = ldwk2.w.h, ldwk2.w.h = wk; /* Line 449, Address: 0x1024c84 */
    ldwk2.w.l = ldwk2.w.l + -scrz_h_posit.w.h; /* Line 450, Address: 0x1024c9c */

    for (j = z12d_cnttbl[i]; j >= 0; --j) { /* Line 452, Address: 0x1024ccc */

      *psHscw = ldwk2.w.l; /* Line 454, Address: 0x1024ce8 */
      ++psHscw; /* Line 455, Address: 0x1024cf0 */
    } /* Line 456, Address: 0x1024cf4 */
  } /* Line 457, Address: 0x1024d04 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 459, Address: 0x1024d10 */

  for (i = 0; i < 8; ++i) { /* Line 461, Address: 0x1024d30 */

    *psHscw = ldwk.w.l; /* Line 463, Address: 0x1024d3c */
    ++psHscw; /* Line 464, Address: 0x1024d44 */
  } /* Line 465, Address: 0x1024d48 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 467, Address: 0x1024d58 */
  for (i = 0; i < 2; ++i) { /* Line 468, Address: 0x1024d78 */

    *psHscw = ldwk.w.l; /* Line 470, Address: 0x1024d84 */
    ++psHscw; /* Line 471, Address: 0x1024d8c */
  } /* Line 472, Address: 0x1024d90 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 474, Address: 0x1024da0 */
  for (i = 0; i < 6; ++i) { /* Line 475, Address: 0x1024dc0 */

    *psHscw = ldwk.w.l; /* Line 477, Address: 0x1024dcc */
    ++psHscw; /* Line 478, Address: 0x1024dd4 */
  } /* Line 479, Address: 0x1024dd8 */

  pHscrbuf = lphscrollbuff; /* Line 481, Address: 0x1024de8 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 482, Address: 0x1024df4 */
  psHscr = &hscrollwork[sYnum / 2] + 8; /* Line 483, Address: 0x1024e24 */
  sYline = 28; /* Line 484, Address: 0x1024e58 */
  zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 485, Address: 0x1024e64 */
} /* Line 486, Address: 0x1024e80 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 507, Address: 0x1024ec0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 511, Address: 0x1024edc */
  for (i = 0, j = yoffs & 7; yline >= i; ++i, j = 0) { /* Line 512, Address: 0x1024ee0 */
    ldwk.w.l = *pHscrwk; /* Line 513, Address: 0x1024efc */
    ++pHscrwk; /* Line 514, Address: 0x1024f08 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 516, Address: 0x1024f14 */
      (*pHscrbuf)->l = ldwk.l; /* Line 517, Address: 0x1024f1c */
    } /* Line 518, Address: 0x1024f2c */
  } /* Line 519, Address: 0x1024f50 */
} /* Line 520, Address: 0x1024f70 */





















static void scrollb_hv(int xOffs, int yOffs) { /* Line 542, Address: 0x1024f90 */
  int lwk, lsv;
  int_union ldwk;

  lsv = scrb_h_posit.l; /* Line 546, Address: 0x1024fa4 */
  ldwk.l = scrb_h_posit.l = lwk = lsv + xOffs; /* Line 547, Address: 0x1024fac */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_h_count) == 0) { /* Line 548, Address: 0x1024fc0 */
    scrb_h_count ^= 16; /* Line 549, Address: 0x1024ff0 */
    if (lwk - lsv < 0) { /* Line 550, Address: 0x1025004 */
      scrflagb.b.h |= 4; /* Line 551, Address: 0x1025010 */
    } /* Line 552, Address: 0x1025024 */
    else {
      scrflagb.b.h |= 8; /* Line 554, Address: 0x102502c */
    }
  }


  lsv = scrb_v_posit.l; /* Line 559, Address: 0x1025040 */
  ldwk.l = scrb_v_posit.l = lwk = lsv + yOffs; /* Line 560, Address: 0x1025048 */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_v_count) == 0) { /* Line 561, Address: 0x102505c */
    scrb_v_count ^= 16; /* Line 562, Address: 0x102508c */
    if (lwk - lsv < 0) { /* Line 563, Address: 0x10250a0 */
      scrflagb.b.h |= 1; /* Line 564, Address: 0x10250ac */
    } /* Line 565, Address: 0x10250c0 */
    else {
      scrflagb.b.h |= 2; /* Line 567, Address: 0x10250c8 */
    }
  }


} /* Line 572, Address: 0x10250dc */


































































































































static void scrollc_h(int xoffs, int flgbit) { /* Line 703, Address: 0x10250f0 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  lXsv = scrc_h_posit.l; /* Line 707, Address: 0x1025108 */
  lXwk = lXsv + xoffs; /* Line 708, Address: 0x1025110 */
  scrc_h_posit.l = lXwk; /* Line 709, Address: 0x1025118 */
  ldXwk.l = lXwk; /* Line 710, Address: 0x1025120 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 711, Address: 0x1025124 */
  ldXwk.w.l &= 16; /* Line 712, Address: 0x102513c */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 713, Address: 0x1025148 */

  if (!ldXwk.b.b4) { /* Line 715, Address: 0x1025164 */
    scrc_h_count ^= 16; /* Line 716, Address: 0x1025170 */
    if (lXwk - lXsv < 0) { /* Line 717, Address: 0x1025184 */
      scrflagc.b.h |= 1 << flgbit; /* Line 718, Address: 0x1025190 */
    } /* Line 719, Address: 0x10251b4 */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 721, Address: 0x10251bc */
    }
  }


} /* Line 726, Address: 0x10251e4 */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 744, Address: 0x1025200 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  lXsv = scrz_h_posit.l; /* Line 748, Address: 0x1025218 */
  lXwk = lXsv + xoffs; /* Line 749, Address: 0x1025220 */
  scrz_h_posit.l = lXwk; /* Line 750, Address: 0x1025228 */
  ldXwk.l = lXwk; /* Line 751, Address: 0x1025230 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 752, Address: 0x1025234 */
  ldXwk.w.l &= 16; /* Line 753, Address: 0x102524c */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 754, Address: 0x1025258 */

  if (!ldXwk.b.b4) { /* Line 756, Address: 0x1025274 */
    scrz_h_count ^= 16; /* Line 757, Address: 0x1025280 */
    if (lXwk - lXsv < 0) { /* Line 758, Address: 0x1025294 */
      scrflagz.b.h |= 1 << flgbit; /* Line 759, Address: 0x10252a0 */
    } /* Line 760, Address: 0x10252c4 */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 762, Address: 0x10252cc */
    }
  }


} /* Line 767, Address: 0x10252f4 */














static void scroll_h() { /* Line 782, Address: 0x1025310 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 786, Address: 0x1025320 */

  scrh_move(); /* Line 788, Address: 0x1025330 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 789, Address: 0x1025338 */
  if (!bXwk) { /* Line 790, Address: 0x102536c */
    scra_h_count ^= 16; /* Line 791, Address: 0x1025374 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 792, Address: 0x1025388 */
      scrflaga.b.h |= 4; /* Line 793, Address: 0x10253ac */
    } /* Line 794, Address: 0x10253c0 */
    else scrflaga.b.h |= 8; /* Line 795, Address: 0x10253c8 */
  }



} /* Line 800, Address: 0x10253dc */
















static void scrh_move() { /* Line 817, Address: 0x1025400 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 820, Address: 0x1025408 */
  if (xwk == 0) { /* Line 821, Address: 0x1025450 */

    scra_hz = 0; /* Line 823, Address: 0x1025460 */
  } /* Line 824, Address: 0x1025468 */
  else if (xwk < 0) { /* Line 825, Address: 0x1025470 */

    if (xwk < -16) { /* Line 827, Address: 0x1025480 */
      xwk = -16; /* Line 828, Address: 0x1025494 */
    }


    xwk += scra_h_posit.w.h; /* Line 832, Address: 0x10254a0 */
    if (xwk < scralim_left) { /* Line 833, Address: 0x10254b4 */
      xwk = scralim_left; /* Line 834, Address: 0x10254d8 */
    }
  } /* Line 836, Address: 0x10254e8 */
  else {
    if (xwk >= 17) { /* Line 838, Address: 0x10254f0 */
      xwk = 16; /* Line 839, Address: 0x1025504 */
    }


    xwk += scra_h_posit.w.h; /* Line 843, Address: 0x1025510 */
    if (xwk > scralim_right) { /* Line 844, Address: 0x1025524 */
      xwk = scralim_right; /* Line 845, Address: 0x1025548 */
    }
  }


  scra_hz = xwk - scra_h_posit.w.h << 8; /* Line 850, Address: 0x1025558 */
  scra_h_posit.w.h = xwk; /* Line 851, Address: 0x1025588 */
} /* Line 852, Address: 0x1025590 */














static void scroll_v() { /* Line 867, Address: 0x10255a0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 870, Address: 0x10255ac */
  if (actwk[0].cddat & 4) { /* Line 871, Address: 0x10255e0 */
    ywk -= 5; /* Line 872, Address: 0x10255f8 */
  }


  if (actwk[0].cddat & 2) { /* Line 876, Address: 0x1025604 */
    ywk += 32; /* Line 877, Address: 0x102561c */
    if (ywk < scra_vline) { /* Line 878, Address: 0x1025628 */
      ywk -= scra_vline; /* Line 879, Address: 0x102564c */
      sv_move_main2(ywk); /* Line 880, Address: 0x1025660 */
      return; /* Line 881, Address: 0x102566c */
    } else if (ywk >= scra_vline + 64) { /* Line 882, Address: 0x1025674 */
      ywk -= scra_vline + 64; /* Line 883, Address: 0x102569c */
      sv_move_main2(ywk); /* Line 884, Address: 0x10256c4 */
      return; /* Line 885, Address: 0x10256d0 */
    }
    ywk -= scra_vline + 64; /* Line 887, Address: 0x10256d8 */
    if (limmoveflag) { /* Line 888, Address: 0x1025700 */
      sv_move_sub2(); /* Line 889, Address: 0x1025710 */
      return; /* Line 890, Address: 0x1025718 */
    }
  }


  if ((ywk -= scra_vline) != 0) { /* Line 895, Address: 0x1025720 */
    sv_move_main(ywk); /* Line 896, Address: 0x102574c */
    return; /* Line 897, Address: 0x1025758 */
  } else if (limmoveflag) { /* Line 898, Address: 0x1025760 */
    sv_move_sub2(); /* Line 899, Address: 0x1025770 */
    return; /* Line 900, Address: 0x1025778 */
  }



  scra_vz = 0; /* Line 905, Address: 0x1025780 */
} /* Line 906, Address: 0x1025788 */













static void sv_move_main(short yPos) { /* Line 920, Address: 0x10257a0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 923, Address: 0x10257b0 */
    if (actwk[0].mspeed.w < 0) { /* Line 924, Address: 0x10257cc */
      spdwk = -actwk[0].mspeed.w; /* Line 925, Address: 0x10257e4 */
    } else { /* Line 926, Address: 0x1025808 */
      spdwk = actwk[0].mspeed.w; /* Line 927, Address: 0x1025810 */
    }


    if (spdwk >= 2048) { /* Line 931, Address: 0x1025820 */
      sv_move_main2(yPos); /* Line 932, Address: 0x1025834 */
    } /* Line 933, Address: 0x1025840 */
    else {

      if (yPos >= 7) { /* Line 936, Address: 0x1025848 */
        sv_move_plus(1536); /* Line 937, Address: 0x1025860 */
      } else if (yPos < -6) { /* Line 938, Address: 0x102586c */
        sv_move_minus(1536); /* Line 939, Address: 0x102588c */
      } else /* Line 940, Address: 0x1025898 */
        sv_move_sub(yPos); /* Line 941, Address: 0x10258a0 */
    }
  } /* Line 943, Address: 0x10258ac */
  else {
    if (yPos >= 3) { /* Line 945, Address: 0x10258b4 */
      sv_move_plus(512); /* Line 946, Address: 0x10258cc */
    } else if (yPos < -2) { /* Line 947, Address: 0x10258d8 */
      sv_move_minus(512); /* Line 948, Address: 0x10258f8 */
    } else { /* Line 949, Address: 0x1025904 */
      sv_move_sub(yPos); /* Line 950, Address: 0x102590c */
    }
  }
} /* Line 953, Address: 0x1025918 */













static void sv_move_main2(short yPos) { /* Line 967, Address: 0x1025930 */
  short spdwk;

  spdwk = 4096; /* Line 970, Address: 0x1025940 */

  if (yPos >= 17) { /* Line 972, Address: 0x102594c */
    sv_move_plus(spdwk); /* Line 973, Address: 0x1025964 */
  } else if (yPos < -16) { /* Line 974, Address: 0x1025970 */
    sv_move_minus(spdwk); /* Line 975, Address: 0x1025990 */
  } else { /* Line 976, Address: 0x102599c */
    sv_move_sub(yPos); /* Line 977, Address: 0x10259a4 */
  }
} /* Line 979, Address: 0x10259b0 */














static void sv_move_sub(short yPos) { /* Line 994, Address: 0x10259d0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 997, Address: 0x10259dc */
  lSpd.w.h = yPos + scra_v_posit.w.h; /* Line 998, Address: 0x10259e0 */
  if (yPos < 0) { /* Line 999, Address: 0x1025a0c */
    scrv_up_ch(lSpd); /* Line 1000, Address: 0x1025a20 */
  } else { /* Line 1001, Address: 0x1025a2c */
    scrv_down_ch(lSpd); /* Line 1002, Address: 0x1025a34 */
  }
} /* Line 1004, Address: 0x1025a40 */



static void sv_move_sub2() { /* Line 1008, Address: 0x1025a50 */
  limmoveflag = 0; /* Line 1009, Address: 0x1025a58 */

  sv_move_sub(0); /* Line 1011, Address: 0x1025a60 */
} /* Line 1012, Address: 0x1025a6c */













static void sv_move_minus(short speed) { /* Line 1026, Address: 0x1025a80 */
  int_union lSpd;
  short wk;
  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1029, Address: 0x1025a90 */
  wk = lSpd.w.h, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1030, Address: 0x1025ab4 */
  scrv_up_ch(lSpd); /* Line 1031, Address: 0x1025acc */
} /* Line 1032, Address: 0x1025ad8 */














static void scrv_up_ch(int_union lSpd) { /* Line 1047, Address: 0x1025af0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1048, Address: 0x1025afc */
    if (lSpd.w.l >= -255) { /* Line 1049, Address: 0x1025b24 */

      lSpd.w.l = scralim_up; /* Line 1051, Address: 0x1025b3c */
    } else { /* Line 1052, Address: 0x1025b48 */
      lSpd.w.l &= 2047; /* Line 1053, Address: 0x1025b50 */
      actwk[0].yposi.w.h &= 2047; /* Line 1054, Address: 0x1025b5c */
      scra_v_posit.w.h &= 2047; /* Line 1055, Address: 0x1025b70 */
      scrb_v_posit.w.h &= 1023; /* Line 1056, Address: 0x1025b84 */
    }
  }

  scrv_move(lSpd); /* Line 1060, Address: 0x1025b98 */
} /* Line 1061, Address: 0x1025ba4 */













static void sv_move_plus(short sSpd) { /* Line 1075, Address: 0x1025bc0 */
  int_union lSpd;
  short wk;
  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1078, Address: 0x1025bd0 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1079, Address: 0x1025bf0 */
  scrv_down_ch(lSpd); /* Line 1080, Address: 0x1025c08 */
} /* Line 1081, Address: 0x1025c14 */














static void scrv_down_ch(int_union lSpd) { /* Line 1096, Address: 0x1025c30 */
  if (lSpd.w.l >= scralim_down) { /* Line 1097, Address: 0x1025c3c */
    if (lSpd.w.l < 2048) { /* Line 1098, Address: 0x1025c64 */

      lSpd.w.l = scralim_down; /* Line 1100, Address: 0x1025c7c */
    } else { /* Line 1101, Address: 0x1025c88 */
      lSpd.w.l -= 2048; /* Line 1102, Address: 0x1025c90 */
      actwk[0].yposi.w.h &= 2047; /* Line 1103, Address: 0x1025c9c */
      scra_v_posit.w.h -= 2048; /* Line 1104, Address: 0x1025cb0 */
      scrb_v_posit.w.h &= 1023; /* Line 1105, Address: 0x1025cc4 */
    }
  }

  scrv_move(lSpd); /* Line 1109, Address: 0x1025cd8 */
} /* Line 1110, Address: 0x1025ce4 */
















static void scrv_move(int_union lSpd) { /* Line 1127, Address: 0x1025d00 */
  short ywk, ysv;
  uint_union spdwk;
  short wk;
  ysv = scra_v_posit.w.h; /* Line 1131, Address: 0x1025d14 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1132, Address: 0x1025d24 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1133, Address: 0x1025d3c */
  spdwk.l = (spdwk.l >> 8) | (spdwk.l << 24); /* Line 1134, Address: 0x1025d50 */
  scra_vz = spdwk.w.l; /* Line 1135, Address: 0x1025d68 */

  scra_v_posit.l = spdwk.l; /* Line 1137, Address: 0x1025d74 */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1139, Address: 0x1025d80 */
  if (!ywk) { /* Line 1140, Address: 0x1025dbc */
    scra_v_count ^= 16; /* Line 1141, Address: 0x1025dc4 */
    ywk = scra_v_posit.w.h - ysv; /* Line 1142, Address: 0x1025dd8 */
    if (ywk < 0) { /* Line 1143, Address: 0x1025e04 */
      scrflaga.b.h |= 1; /* Line 1144, Address: 0x1025e14 */
    } else { /* Line 1145, Address: 0x1025e28 */
      scrflaga.b.h |= 2; /* Line 1146, Address: 0x1025e30 */
    }
  }


} /* Line 1151, Address: 0x1025e44 */

















void scrollwrt() { /* Line 1169, Address: 0x1025e60 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  point TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1178, Address: 0x1025e80 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1179, Address: 0x1025e84 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1180, Address: 0x1025e90 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1181, Address: 0x1025e9c */
  pScrFlag = &scrflagbw.b.h; /* Line 1182, Address: 0x1025ea4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1183, Address: 0x1025eac */

  VramBase = 16384; /* Line 1185, Address: 0x1025ec0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1186, Address: 0x1025ec4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1187, Address: 0x1025ed0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1188, Address: 0x1025edc */
  pScrFlag = &scrflagaw.b.h; /* Line 1189, Address: 0x1025ee4 */

  if (*pScrFlag) { /* Line 1191, Address: 0x1025eec */
    if (*pScrFlag & 1) { /* Line 1192, Address: 0x1025ef8 */
      *pScrFlag &= 254; /* Line 1193, Address: 0x1025f0c */

      lD4.l = -16; /* Line 1195, Address: 0x1025f18 */
      wD5 = 65520; /* Line 1196, Address: 0x1025f20 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1198, Address: 0x1025f28 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1200, Address: 0x1025f48 */
    }




    if (*pScrFlag & 2) { /* Line 1206, Address: 0x1025f74 */
      *pScrFlag &= 253; /* Line 1207, Address: 0x1025f88 */

      lD4.l = 224; /* Line 1209, Address: 0x1025f94 */
      wD5 = 65520; /* Line 1210, Address: 0x1025f9c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1211, Address: 0x1025fa4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1213, Address: 0x1025fc4 */
    }




    if (*pScrFlag & 4) { /* Line 1219, Address: 0x1025ff0 */
      *pScrFlag &= 251; /* Line 1220, Address: 0x1026004 */

      lD4.l = -16; /* Line 1222, Address: 0x1026010 */
      wD5 = 65520; /* Line 1223, Address: 0x1026018 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1224, Address: 0x1026020 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1226, Address: 0x1026040 */
    }




    if (*pScrFlag & 8) { /* Line 1232, Address: 0x102606c */
      *pScrFlag &= 247; /* Line 1233, Address: 0x1026080 */

      lD4.l = -16; /* Line 1235, Address: 0x102608c */
      wD5 = 320; /* Line 1236, Address: 0x1026094 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1237, Address: 0x102609c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1239, Address: 0x10260bc */
    }
  }






} /* Line 1248, Address: 0x10260e8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1265, Address: 0x1026110 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD5;
  short wD0;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  point TilePoint;
  int BlkIndex;
  int i;


  lD4.l = -16; /* Line 1277, Address: 0x102613c */

  if (*pScrFlag & 1) { /* Line 1279, Address: 0x1026144 */
    *pScrFlag &= 254; /* Line 1280, Address: 0x102615c */
  } /* Line 1281, Address: 0x1026170 */
  else {
    *pScrFlag &= 254; /* Line 1283, Address: 0x1026178 */

    if (*pScrFlag & 2) { /* Line 1285, Address: 0x102618c */
      *pScrFlag &= 253; /* Line 1286, Address: 0x10261a4 */
      lD4.w.l = 224; /* Line 1287, Address: 0x10261b8 */
    } /* Line 1288, Address: 0x10261c0 */
    else {
      *pScrFlag &= 253; /* Line 1290, Address: 0x10261c8 */
      goto label1; /* Line 1291, Address: 0x10261dc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1296, Address: 0x10261e4 */
  wD0 = z12dwrttbl[wD0 + 1]; /* Line 1297, Address: 0x102623c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1303, Address: 0x1026264 */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1304, Address: 0x1026288 */
  if (wD0 != 0) { /* Line 1305, Address: 0x10262b0 */
    wD5 = 65520; /* Line 1306, Address: 0x10262c0 */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1307, Address: 0x10262c8 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1309, Address: 0x10262e8 */



  } /* Line 1313, Address: 0x1026314 */
  else {

    wD5 = 0; /* Line 1316, Address: 0x102631c */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1317, Address: 0x1026320 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1321, Address: 0x1026340 */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1328, Address: 0x102636c */






    lD4.l = -16; /* Line 1335, Address: 0x1026380 */
    wD5 = 65520; /* Line 1336, Address: 0x1026388 */
    if (*pScrFlag & 168) { /* Line 1337, Address: 0x1026390 */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1338, Address: 0x10263a8 */
      wD5 = 320; /* Line 1339, Address: 0x10263c8 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1343, Address: 0x10263d0 */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1345, Address: 0x1026400 */
    if (WrtTblCnt >= 114) WrtTblCnt = 113; /* Line 1346, Address: 0x102640c */



    for (i = 0; i < 16; ++i) { /* Line 1350, Address: 0x102641c */
      wD0 = z12dwrttbl[WrtTblCnt++]; /* Line 1351, Address: 0x1026428 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1352, Address: 0x102644c */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1353, Address: 0x102647c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1354, Address: 0x10264a0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1356, Address: 0x10264c8 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1359, Address: 0x10264ec */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1361, Address: 0x102650c */
      }
      lD4.w.l += 16; /* Line 1363, Address: 0x1026520 */
    } /* Line 1364, Address: 0x102652c */
    *pScrFlag = 0; /* Line 1365, Address: 0x102653c */
  }
} /* Line 1367, Address: 0x1026544 */





void scrollwrtc() {} /* Line 1373, Address: 0x1026570 */




void scrollwrtz() {} /* Line 1378, Address: 0x1026580 */

















void hblockwrt(point* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1396, Address: 0x1026590 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1409, Address: 0x10265b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1412, Address: 0x10265d8 */
    pTilePoint->x += 2; /* Line 1413, Address: 0x10265ec */
    if (pTilePoint->x >= 64) { /* Line 1414, Address: 0x1026600 */
      pTilePoint->x -= 64; /* Line 1415, Address: 0x1026614 */
    }
    xOffs += 16; /* Line 1417, Address: 0x1026628 */
  } while (--lpcnt >= 0); /* Line 1418, Address: 0x1026634 */
} /* Line 1419, Address: 0x1026648 */



void hblockwrt1(point* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1423, Address: 0x1026660 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1427, Address: 0x1026688 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1430, Address: 0x10266a8 */
    pTilePoint->x += 2; /* Line 1431, Address: 0x10266bc */
    if (pTilePoint->x >= 64) { /* Line 1432, Address: 0x10266d0 */
      pTilePoint->x -= 64; /* Line 1433, Address: 0x10266e4 */
    }
    xOffs += 16; /* Line 1435, Address: 0x10266f8 */
  } while (--lpcnt >= 0); /* Line 1436, Address: 0x1026704 */
} /* Line 1437, Address: 0x1026718 */



















void vblockwrt(point* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1457, Address: 0x1026730 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1461, Address: 0x1026758 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1464, Address: 0x1026778 */
    pTilePoint->y += 2; /* Line 1465, Address: 0x102678c */
    if (pTilePoint->y >= 32) { /* Line 1466, Address: 0x102679c */
      pTilePoint->y -= 32; /* Line 1467, Address: 0x10267b0 */
    }
    yOffs += 16; /* Line 1469, Address: 0x10267c0 */
  } while (--lpcnt >= 0); /* Line 1470, Address: 0x10267cc */
} /* Line 1471, Address: 0x10267e0 */


















void blockwrt(int VramBase, point* pTilePoint, int BlkIndex) { /* Line 1490, Address: 0x10267f0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) /* Line 1496, Address: 0x1026824 */
  {
    base = 1; /* Line 1498, Address: 0x1026834 */
  } /* Line 1499, Address: 0x1026838 */
  else if (VramBase == 16384) /* Line 1500, Address: 0x1026840 */
  {
    base = 0; /* Line 1502, Address: 0x1026850 */
  }
  x = pTilePoint->x; /* Line 1504, Address: 0x1026854 */
  y = pTilePoint->y; /* Line 1505, Address: 0x102685c */


  frip = BlkIndex & 6144; /* Line 1508, Address: 0x1026864 */
  BlkIndex &= 1023; /* Line 1509, Address: 0x102686c */
  if (frip == 6144) /* Line 1510, Address: 0x1026878 */
  {
    p0 = 3, p1 = 2; /* Line 1512, Address: 0x1026884 */
    p2 = 1, p3 = 0; /* Line 1513, Address: 0x102688c */
  } /* Line 1514, Address: 0x1026894 */
  else if (frip & 4096) /* Line 1515, Address: 0x102689c */
  {
    p0 = 2, p1 = 3; /* Line 1517, Address: 0x10268a8 */
    p2 = 0, p3 = 1; /* Line 1518, Address: 0x10268b0 */
  } /* Line 1519, Address: 0x10268b8 */
  else if (frip & 2048) /* Line 1520, Address: 0x10268c0 */
  {
    p0 = 1, p1 = 0; /* Line 1522, Address: 0x10268cc */
    p2 = 3, p3 = 2; /* Line 1523, Address: 0x10268d4 */
  } /* Line 1524, Address: 0x10268dc */
  else
  {
    p0 = 0, p1 = 1; /* Line 1527, Address: 0x10268e4 */
    p2 = 2, p3 = 3; /* Line 1528, Address: 0x10268ec */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1531, Address: 0x10268f4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1532, Address: 0x1026938 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1533, Address: 0x102697c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1534, Address: 0x10269c0 */

} /* Line 1536, Address: 0x1026a04 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1554, Address: 0x1026a40 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1555, Address: 0x1026a60 */
} /* Line 1556, Address: 0x1026a80 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1558, Address: 0x1026a90 */
  wH_posiw = 0; /* Line 1559, Address: 0x1026ab0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1560, Address: 0x1026ab4 */
} /* Line 1561, Address: 0x1026ad4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1568, Address: 0x1026af0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1574, Address: 0x1026b20 */
  yOffs += wV_posiw; /* Line 1575, Address: 0x1026b30 */





  if ((short)xOffs < 0) /* Line 1581, Address: 0x1026b40 */
    xOffs = 0; /* Line 1582, Address: 0x1026b5c */
  if ((short)yOffs < 0) /* Line 1583, Address: 0x1026b60 */
    yOffs = 0; /* Line 1584, Address: 0x1026b7c */
  if ((short)xOffs >= 16384) /* Line 1585, Address: 0x1026b80 */
    xOffs = 16383; /* Line 1586, Address: 0x1026ba0 */
  if ((short)yOffs >= 2048) /* Line 1587, Address: 0x1026ba8 */
    yOffs = 2047; /* Line 1588, Address: 0x1026bc8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1589, Address: 0x1026bd0 */
  if (i < 0) i = 0; /* Line 1590, Address: 0x1026c18 */

  ScreenNo = pMapWk[i] & 127; /* Line 1592, Address: 0x1026c24 */

  if (ScreenNo) { /* Line 1594, Address: 0x1026c40 */




    xOffs &= 32767; /* Line 1599, Address: 0x1026c48 */
    yOffs &= 32767; /* Line 1600, Address: 0x1026c54 */


    xBlk = xOffs; /* Line 1603, Address: 0x1026c60 */
    xBlk %= 256; /* Line 1604, Address: 0x1026c68 */
    xBlk /= 16; /* Line 1605, Address: 0x1026c88 */
    yBlk = yOffs; /* Line 1606, Address: 0x1026ca4 */
    yBlk %= 256; /* Line 1607, Address: 0x1026cac */
    yBlk /= 16; /* Line 1608, Address: 0x1026ccc */

    lpw = pmapwk; /* Line 1610, Address: 0x1026ce8 */
    lpw += xBlk; /* Line 1611, Address: 0x1026cf0 */
    lpw += yBlk * 16; /* Line 1612, Address: 0x1026cf8 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1613, Address: 0x1026d04 */
    *pIndex = *lpw; /* Line 1614, Address: 0x1026d1c */

    return 1; /* Line 1616, Address: 0x1026d2c */
  }

  *pIndex = 0; /* Line 1619, Address: 0x1026d38 */
  return 0; /* Line 1620, Address: 0x1026d40 */
} /* Line 1621, Address: 0x1026d44 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1641, Address: 0x1026d70 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1649, Address: 0x1026d98 */
  if (ScreenNo) { /* Line 1650, Address: 0x1026dfc */





    xBlk = xOffs; /* Line 1656, Address: 0x1026e04 */
    xBlk %= 256; /* Line 1657, Address: 0x1026e0c */
    xBlk /= 16; /* Line 1658, Address: 0x1026e2c */
    yBlk = yOffs; /* Line 1659, Address: 0x1026e48 */
    yBlk %= 256; /* Line 1660, Address: 0x1026e50 */
    yBlk /= 16; /* Line 1661, Address: 0x1026e70 */


    lpw = pmapwk; /* Line 1664, Address: 0x1026e8c */
    lpw += xBlk; /* Line 1665, Address: 0x1026e94 */
    lpw += yBlk * 16; /* Line 1666, Address: 0x1026e9c */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1667, Address: 0x1026ea8 */
    *ppBlockNo = lpw; /* Line 1668, Address: 0x1026ec0 */
    *pIndex = *lpw; /* Line 1669, Address: 0x1026ec8 */




    return 1; /* Line 1674, Address: 0x1026ed8 */
  }

  *pIndex = 0; /* Line 1677, Address: 0x1026ee4 */
  return 0; /* Line 1678, Address: 0x1026eec */
} /* Line 1679, Address: 0x1026ef0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1693, Address: 0x1026f10 */
  int VramBase;
  point TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1700, Address: 0x1026f2c */
  pMapWk = (unsigned char*)mapwka; /* Line 1701, Address: 0x1026f30 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1702, Address: 0x1026f38 */
    *pBlockIndex = BlockNo; /* Line 1703, Address: 0x1026f5c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1704, Address: 0x1026f68 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1705, Address: 0x1026f80 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1706, Address: 0x1026f94 */
    }
  }


} /* Line 1711, Address: 0x1026fac */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1725, Address: 0x1026fd0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1726, Address: 0x1026fdc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1727, Address: 0x1027008 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1728, Address: 0x1027054 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1729, Address: 0x1027080 */

          return 0; /* Line 1731, Address: 0x10270cc */
        }
      }
    }
  }

  return 1; /* Line 1737, Address: 0x10270d8 */
} /* Line 1738, Address: 0x10270dc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, point* lpTilePoint) { /* Line 1755, Address: 0x10270f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1756, Address: 0x102710c */

} /* Line 1758, Address: 0x1027128 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, point* lpTilePoint) { /* Line 1760, Address: 0x1027140 */
  wH_posiw = 0; /* Line 1761, Address: 0x102715c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1762, Address: 0x1027160 */

} /* Line 1764, Address: 0x102717c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, point* lpTilePoint) { /* Line 1766, Address: 0x1027190 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1767, Address: 0x10271a4 */

} /* Line 1769, Address: 0x10271c0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, point* lpTilePoint) { /* Line 1771, Address: 0x10271d0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1772, Address: 0x10271ec */

} /* Line 1774, Address: 0x1027208 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, point* lpTilePoint) { /* Line 1776, Address: 0x1027220 */
  xOffs += wH_posiw; /* Line 1777, Address: 0x1027238 */
  yOffs += wV_posiw; /* Line 1778, Address: 0x1027248 */
  yOffs &= 240; /* Line 1779, Address: 0x1027258 */
  xOffs &= 496; /* Line 1780, Address: 0x1027264 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1782, Address: 0x1027270 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1783, Address: 0x102729c */


} /* Line 1786, Address: 0x10272c8 */















void mapwrt() { /* Line 1802, Address: 0x10272e0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1807, Address: 0x10272f8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1808, Address: 0x1027304 */
  pMapWk = (unsigned char*)mapwka; /* Line 1809, Address: 0x1027310 */
  VramBase = 16384; /* Line 1810, Address: 0x1027318 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1811, Address: 0x102731c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1815, Address: 0x1027334 */
  VramBase = 24576; /* Line 1816, Address: 0x102733c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1817, Address: 0x1027340 */

} /* Line 1819, Address: 0x1027350 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1822, Address: 0x1027370 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1823, Address: 0x1027388 */
} /* Line 1824, Address: 0x10273a8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1829, Address: 0x10273c0 */
  point TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1833, Address: 0x10273e0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1836, Address: 0x10273fc */



    wD4 += 16; /* Line 1840, Address: 0x1027424 */
  } while ((short)--wD6 >= 0); /* Line 1841, Address: 0x1027430 */

} /* Line 1843, Address: 0x1027458 */





void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1849, Address: 0x1027470 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1852, Address: 0x102748c */
  wD6 = 15; /* Line 1853, Address: 0x1027494 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1856, Address: 0x102749c */

    mapwrt_sub(z12dwrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1858, Address: 0x10274c0 */
    wD4 += 16; /* Line 1859, Address: 0x10274e0 */
  } while ((short)--wD6 >= 0); /* Line 1860, Address: 0x10274e8 */
} /* Line 1861, Address: 0x102750c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1887, Address: 0x1027530 */
  point TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1892, Address: 0x1027558 */
  wD0 = pWrttbl[wD0]; /* Line 1893, Address: 0x1027568 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1895, Address: 0x1027584 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1896, Address: 0x10275a8 */
  if (wD0) { /* Line 1897, Address: 0x10275d0 */
    wD5 = 65520; /* Line 1898, Address: 0x10275dc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1899, Address: 0x10275e4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1902, Address: 0x1027600 */



  } /* Line 1906, Address: 0x1027628 */
  else {

    wD5 = 0; /* Line 1909, Address: 0x1027630 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1910, Address: 0x1027634 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1914, Address: 0x1027650 */
  }





} /* Line 1921, Address: 0x1027678 */










void mapinit() { /* Line 1932, Address: 0x10276a0 */

  colorset2(mapinittbl.colorno2); /* Line 1934, Address: 0x10276a8 */
  colorset(mapinittbl.colorno2); /* Line 1935, Address: 0x10276bc */


  if (play_start & 2) divdevset(); /* Line 1938, Address: 0x10276d0 */
} /* Line 1939, Address: 0x10276f0 */




void mapset() {} /* Line 1944, Address: 0x1027700 */



void divdevset() {} /* Line 1948, Address: 0x1027710 */



void enecginit() {} /* Line 1952, Address: 0x1027720 */
