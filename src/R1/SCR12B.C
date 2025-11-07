#include "..\EQU.H"
#include "SCR12B.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1B.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_hv(int xOffs, int yOffs);
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

static unsigned char z12bwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 6,
  6, 6, 6, 4, 4, 4, 4, 0, 0, 0,
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
short scr_dir_tbl[6] = { 4, 0, 10391, 0, 784, 96 };
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
  { 80, 389 }
};
unsigned char playmapnotbl[4] = { 145, 182, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;















































































sprite_status* main_chk(void) {
  if (main_play == 0) { /* Line 151, Address: 0x1025f00 */
    return &actwk[0]; /* Line 152, Address: 0x1025f14 */
  }
  return &actwk[1]; /* Line 154, Address: 0x1025f24 */

} /* Line 156, Address: 0x1025f2c */





































void scr_set(void) { /* Line 194, Address: 0x1025f40 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 197, Address: 0x1025f4c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1025f60 */
  scr_timer.b.h = 0; /* Line 199, Address: 0x1025f74 */

  pScrTbl = scr_dir_tbl; /* Line 201, Address: 0x1025f7c */
  scrar_no = *pScrTbl; /* Line 202, Address: 0x1025f84 */
  ++pScrTbl; /* Line 203, Address: 0x1025f90 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 204, Address: 0x1025f94 */
  ++pScrTbl; /* Line 205, Address: 0x1025fa8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 206, Address: 0x1025fac */
  ++pScrTbl; /* Line 207, Address: 0x1025fc0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 208, Address: 0x1025fc4 */
  ++pScrTbl; /* Line 209, Address: 0x1025fd8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 210, Address: 0x1025fdc */
  scra_h_keep = *pScrTbl + 576; /* Line 211, Address: 0x1025ff0 */
  ++pScrTbl; /* Line 212, Address: 0x1026010 */
  scra_h_count = 16; /* Line 213, Address: 0x1026014 */
  scra_v_count = 16; /* Line 214, Address: 0x1026020 */

  scra_vline = *pScrTbl; /* Line 216, Address: 0x102602c */
  scra_hline = 160; /* Line 217, Address: 0x1026038 */

  playposiset(); /* Line 219, Address: 0x1026044 */
} /* Line 220, Address: 0x102604c */
















































static void playposiset(void) { /* Line 269, Address: 0x1026060 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 272, Address: 0x1026074 */
    playload(); /* Line 273, Address: 0x1026084 */
    xwk = actwk[0].xposi.w.h; /* Line 274, Address: 0x102608c */

    if (actwk[0].yposi.w.h > 0) { /* Line 276, Address: 0x102609c */
      ywk = actwk[0].yposi.w.h; /* Line 277, Address: 0x10260b4 */
    } /* Line 278, Address: 0x10260c4 */
    else ywk = 0; /* Line 279, Address: 0x10260cc */

  } /* Line 281, Address: 0x10260d0 */
  else {
    if (demoflag.w & -32768) { /* Line 283, Address: 0x10260d8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 284, Address: 0x10260f8 */
    } /* Line 285, Address: 0x102611c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 287, Address: 0x1026124 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 291, Address: 0x1026144 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 292, Address: 0x1026158 */
  }


  if (xwk > 160) { /* Line 296, Address: 0x102616c */
    xwk -= 160; /* Line 297, Address: 0x1026180 */
  } /* Line 298, Address: 0x102618c */
  else xwk = 0; /* Line 299, Address: 0x1026194 */



  if (xwk > scralim_right) { /* Line 303, Address: 0x1026198 */
    xwk = scralim_right; /* Line 304, Address: 0x10261bc */
  }


  scra_h_posit.w.h = xwk; /* Line 308, Address: 0x10261cc */

  if (ywk > 96) { /* Line 310, Address: 0x10261d4 */
    ywk -= 96; /* Line 311, Address: 0x10261e8 */
  } /* Line 312, Address: 0x10261f4 */
  else ywk = 0; /* Line 313, Address: 0x10261fc */



  if (ywk > scralim_down) { /* Line 317, Address: 0x1026200 */
    ywk = scralim_down; /* Line 318, Address: 0x1026224 */
  }


  scra_v_posit.w.h = ywk; /* Line 322, Address: 0x1026234 */

  scrbinit(xwk, ywk); /* Line 324, Address: 0x102623c */


  loopmapno = playmapnotbl[0]; /* Line 327, Address: 0x102624c */
  loopmapno2 = playmapnotbl[1]; /* Line 328, Address: 0x102625c */
  ballmapno = playmapnotbl[2]; /* Line 329, Address: 0x102626c */
  ballmapno2 = playmapnotbl[3]; /* Line 330, Address: 0x102627c */
} /* Line 331, Address: 0x102628c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 352, Address: 0x10262b0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 355, Address: 0x10262c0 */
  lYwk.w.l = 0; /* Line 356, Address: 0x10262c8 */

  lYwk.l = (lYwk.l >> 4) * 3; /* Line 358, Address: 0x10262cc */
  scrb_v_posit.l = lYwk.l; /* Line 359, Address: 0x10262e0 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 360, Address: 0x10262ec */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 361, Address: 0x10262f8 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 363, Address: 0x1026304 */
  scrb_h_posit.w.h = sXpos; /* Line 364, Address: 0x1026320 */

  sXpos = (unsigned short)sXpos >> 2; /* Line 366, Address: 0x102632c */
  scrz_h_posit.w.h = sXpos; /* Line 367, Address: 0x1026348 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 369, Address: 0x1026354 */
  scrc_h_posit.w.h = sXpos * 3; /* Line 370, Address: 0x1026370 */

  sMemSet(hscrollwork, 0, 32); /* Line 372, Address: 0x1026394 */
} /* Line 373, Address: 0x10263b4 */















void scroll(void) { /* Line 389, Address: 0x10263d0 */
  int_union ldwk;
  int_union ldwk2;
  int_union* pHscrbuf;
  int i, j;
  int lXwk, lYwk;
  short sYline;
  short sYnum;
  short *psHscr, *psHscw;
  static unsigned char z12b_cnttbl[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
  static int scaddtbl[8] = { 65536, 57344, 49152, 40960, 32768, 24576, 20480, 16384 };

  if (scroll_start.b.h) return; /* Line 401, Address: 0x10263fc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 406, Address: 0x102640c */

  scrchk(); /* Line 408, Address: 0x1026438 */

  scroll_h(); /* Line 410, Address: 0x1026440 */
  scroll_v(); /* Line 411, Address: 0x1026448 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 413, Address: 0x1026450 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 414, Address: 0x1026460 */


  lXwk = scra_hz << 5; /* Line 417, Address: 0x1026470 */
  scrollz_h(lXwk, 6); /* Line 418, Address: 0x1026484 */

  lXwk = (scra_hz << 4) * 3; /* Line 420, Address: 0x1026494 */
  scrollc_h(lXwk, 4); /* Line 421, Address: 0x10264b0 */

  lXwk = scra_hz << 7; /* Line 423, Address: 0x10264c0 */
  lYwk = (scra_vz << 4) * 3; /* Line 424, Address: 0x10264d4 */
  scrollb_hv(lXwk, lYwk); /* Line 425, Address: 0x10264f4 */
  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 426, Address: 0x1026504 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 428, Address: 0x102652c */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 429, Address: 0x1026564 */

  for (i = 0, psHscr = hscrollwork; i < 8; ++i) { /* Line 431, Address: 0x1026578 */
    ldwk.w.l = psHscr[0]; /* Line 432, Address: 0x102658c */
    ldwk.w.h = psHscr[1]; /* Line 433, Address: 0x1026594 */
    ldwk.l += scaddtbl[i]; /* Line 434, Address: 0x102659c */
    psHscr[0] = ldwk.w.l; /* Line 435, Address: 0x10265bc */
    psHscr[1] = ldwk.w.h; /* Line 436, Address: 0x10265c4 */
    psHscr += 2; /* Line 437, Address: 0x10265cc */
  } /* Line 438, Address: 0x10265d0 */

  ldwk.w.l = -scra_h_posit.w.h; /* Line 440, Address: 0x10265e0 */
  { short wk = ldwk.w.l; ldwk.w.l = ldwk.w.h; ldwk.w.h = wk; } /* Line 441, Address: 0x1026600 */
  psHscr = &hscrollwork[0]; /* Line 442, Address: 0x1026618 */
  psHscw = &hscrollwork[16]; /* Line 443, Address: 0x1026620 */

  for (i = 7; i >= 0; --i) { /* Line 445, Address: 0x1026628 */

    ldwk2.w.l = *psHscr; /* Line 447, Address: 0x1026634 */
    ++psHscr; /* Line 448, Address: 0x102663c */
    ldwk2.w.h = *psHscr; /* Line 449, Address: 0x1026640 */
    ++psHscr; /* Line 450, Address: 0x1026648 */
    { short wk = ldwk2.w.l; ldwk2.w.l = ldwk2.w.h; ldwk2.w.h = wk; } /* Line 451, Address: 0x102664c */
    ldwk2.w.l = -(ldwk2.w.l + scrz_h_posit.w.h); /* Line 452, Address: 0x1026664 */

    for (j = z12b_cnttbl[i]; j >= 0; --j) { /* Line 454, Address: 0x1026694 */

      *psHscw = ldwk2.w.l; /* Line 456, Address: 0x10266b0 */
      ++psHscw; /* Line 457, Address: 0x10266b8 */
    } /* Line 458, Address: 0x10266bc */
  } /* Line 459, Address: 0x10266cc */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 461, Address: 0x10266d8 */

  for (i = 0; i < 8; ++i) { /* Line 463, Address: 0x10266f8 */

    *psHscw = ldwk.w.l; /* Line 465, Address: 0x1026704 */
    ++psHscw; /* Line 466, Address: 0x102670c */
  } /* Line 467, Address: 0x1026710 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 469, Address: 0x1026720 */
  for (i = 0; i < 8; ++i) { /* Line 470, Address: 0x1026740 */

    *psHscw = ldwk.w.l; /* Line 472, Address: 0x102674c */
    ++psHscw; /* Line 473, Address: 0x1026754 */
  } /* Line 474, Address: 0x1026758 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 476, Address: 0x1026768 */
  for (i = 0; i < 32; ++i) { /* Line 477, Address: 0x1026788 */

    *psHscw = ldwk.w.l; /* Line 479, Address: 0x1026794 */
    ++psHscw; /* Line 480, Address: 0x102679c */
  } /* Line 481, Address: 0x10267a0 */

  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 483, Address: 0x10267b0 */
  psHscr = &hscrollwork[sYnum / 2] + 16; /* Line 484, Address: 0x10267e0 */

  sYline = 29; /* Line 486, Address: 0x1026814 */
  pHscrbuf = lphscrollbuff; /* Line 487, Address: 0x1026820 */
  zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 488, Address: 0x102682c */
} /* Line 489, Address: 0x1026848 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 510, Address: 0x1026880 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 514, Address: 0x102689c */
  for (i = 0, j = yoffs & 7; yline >= i; ++i, j = 0) { /* Line 515, Address: 0x10268a0 */
    ldwk.w.l = *pHscrwk; /* Line 516, Address: 0x10268bc */
    ++pHscrwk; /* Line 517, Address: 0x10268c8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 519, Address: 0x10268d4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 520, Address: 0x10268dc */
    } /* Line 521, Address: 0x10268ec */
  } /* Line 522, Address: 0x1026910 */
} /* Line 523, Address: 0x1026930 */





















static void scrollb_hv(int xOffs, int yOffs) { /* Line 545, Address: 0x1026950 */
  int lwk, lsv;
  int_union ldwk;

  lsv = scrb_h_posit.l; /* Line 549, Address: 0x1026964 */
  ldwk.l = scrb_h_posit.l = lwk = lsv + xOffs; /* Line 550, Address: 0x102696c */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_h_count) == 0) { /* Line 551, Address: 0x1026980 */
    scrb_h_count ^= 16; /* Line 552, Address: 0x10269b0 */
    if (lwk - lsv < 0) { /* Line 553, Address: 0x10269c4 */
      scrflagb.b.h |= 4; /* Line 554, Address: 0x10269d0 */
    } /* Line 555, Address: 0x10269e4 */
    else {
      scrflagb.b.h |= 8; /* Line 557, Address: 0x10269ec */
    }
  }


  lsv = scrb_v_posit.l; /* Line 562, Address: 0x1026a00 */
  ldwk.l = scrb_v_posit.l = lwk = lsv + yOffs; /* Line 563, Address: 0x1026a08 */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_v_count) == 0) { /* Line 564, Address: 0x1026a1c */
    scrb_v_count ^= 16; /* Line 565, Address: 0x1026a4c */
    if (lwk - lsv < 0) { /* Line 566, Address: 0x1026a60 */
      scrflagb.b.h |= 1; /* Line 567, Address: 0x1026a6c */
    } /* Line 568, Address: 0x1026a80 */
    else {
      scrflagb.b.h |= 2; /* Line 570, Address: 0x1026a88 */
    }
  }


} /* Line 575, Address: 0x1026a9c */






























































































































static void scrollc_h(int xoffs, int flgbit) { /* Line 702, Address: 0x1026ab0 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  ldXwk.l = scrc_h_posit.l = lXwk = lXsv = scrc_h_posit.l + xoffs; /* Line 706, Address: 0x1026ac8 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 707, Address: 0x1026ae8 */
  ldXwk.w.l = (unsigned char)(ldXwk.w.l & 16) ^ scrc_h_count; /* Line 708, Address: 0x1026b00 */

  if (!ldXwk.w.l) { /* Line 710, Address: 0x1026b34 */
    scrc_h_count ^= 16; /* Line 711, Address: 0x1026b40 */
    if (lXwk - lXsv < 0) { /* Line 712, Address: 0x1026b54 */
      scrflagc.b.h |= 1 << flgbit; /* Line 713, Address: 0x1026b60 */
    } /* Line 714, Address: 0x1026b84 */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 716, Address: 0x1026b8c */
    }
  }


} /* Line 721, Address: 0x1026bb4 */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 739, Address: 0x1026bd0 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  ldXwk.l = scrz_h_posit.l = lXwk = lXsv = scrz_h_posit.l + xoffs; /* Line 743, Address: 0x1026be8 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 744, Address: 0x1026c08 */
  ldXwk.w.l = (unsigned char)(ldXwk.w.l & 16) ^ scrz_h_count; /* Line 745, Address: 0x1026c20 */

  if (!ldXwk.w.l) { /* Line 747, Address: 0x1026c54 */
    scrz_h_count ^= 16; /* Line 748, Address: 0x1026c60 */
    if (lXwk - lXsv < 0) { /* Line 749, Address: 0x1026c74 */
      scrflagz.b.h |= 1 << flgbit; /* Line 750, Address: 0x1026c80 */
    } /* Line 751, Address: 0x1026ca4 */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 753, Address: 0x1026cac */
    }
  }


} /* Line 758, Address: 0x1026cd4 */














static void scroll_h(void) { /* Line 773, Address: 0x1026cf0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 777, Address: 0x1026d00 */

  scrh_move(); /* Line 779, Address: 0x1026d10 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 780, Address: 0x1026d18 */
  if (!bXwk) { /* Line 781, Address: 0x1026d4c */
    scra_h_count ^= 16; /* Line 782, Address: 0x1026d54 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 783, Address: 0x1026d68 */
      scrflaga.b.h |= 4; /* Line 784, Address: 0x1026d8c */
    } /* Line 785, Address: 0x1026da0 */
    else scrflaga.b.h |= 8; /* Line 786, Address: 0x1026da8 */
  }



} /* Line 791, Address: 0x1026dbc */
















static void scrh_move(void) { /* Line 808, Address: 0x1026de0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 811, Address: 0x1026de8 */
  if (xwk == 0) { /* Line 812, Address: 0x1026e30 */

    scra_hz = 0; /* Line 814, Address: 0x1026e40 */
    return; /* Line 815, Address: 0x1026e48 */
  } else if (xwk < 0) { /* Line 816, Address: 0x1026e50 */

    if (xwk < -16) { /* Line 818, Address: 0x1026e60 */
      xwk = -16; /* Line 819, Address: 0x1026e74 */
    }


    xwk += scra_h_posit.w.h; /* Line 823, Address: 0x1026e80 */
    if (xwk < scralim_left) { /* Line 824, Address: 0x1026e94 */
      xwk = scralim_left; /* Line 825, Address: 0x1026eb8 */
    }
  } /* Line 827, Address: 0x1026ec8 */
  else {
    if (xwk > 16) { /* Line 829, Address: 0x1026ed0 */
      xwk = 16; /* Line 830, Address: 0x1026ee4 */
    }


    xwk += scra_h_posit.w.h; /* Line 834, Address: 0x1026ef0 */
    if (xwk > scralim_right) { /* Line 835, Address: 0x1026f04 */
      xwk = scralim_right; /* Line 836, Address: 0x1026f28 */
    }
  }


  scra_hz = xwk - scra_h_posit.w.h << 8; /* Line 841, Address: 0x1026f38 */
  scra_h_posit.w.h = xwk; /* Line 842, Address: 0x1026f68 */
} /* Line 843, Address: 0x1026f70 */














static void scroll_v(void) { /* Line 858, Address: 0x1026f80 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 861, Address: 0x1026f8c */
  if (actwk[0].cddat & 4) { /* Line 862, Address: 0x1026fc0 */
    ywk -= 5; /* Line 863, Address: 0x1026fd8 */
  }


  if (actwk[0].cddat & 2) { /* Line 867, Address: 0x1026fe4 */
    ywk += 32; /* Line 868, Address: 0x1026ffc */
    if (ywk < scra_vline) { /* Line 869, Address: 0x1027008 */
      ywk -= scra_vline; /* Line 870, Address: 0x102702c */
      sv_move_main2(ywk); /* Line 871, Address: 0x1027040 */
      return; /* Line 872, Address: 0x102704c */
    } else if (ywk >= scra_vline + 64) { /* Line 873, Address: 0x1027054 */
      ywk -= scra_vline + 64; /* Line 874, Address: 0x102707c */
      sv_move_main2(ywk); /* Line 875, Address: 0x10270a4 */
      return; /* Line 876, Address: 0x10270b0 */
    }
    ywk -= scra_vline + 64; /* Line 878, Address: 0x10270b8 */
    if (!limmoveflag) goto label1; /* Line 879, Address: 0x10270e0 */
    sv_move_sub2(); /* Line 880, Address: 0x10270f0 */
    return; /* Line 881, Address: 0x10270f8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 886, Address: 0x1027100 */
    sv_move_main(ywk); /* Line 887, Address: 0x102712c */
    return; /* Line 888, Address: 0x1027138 */
  } else if (limmoveflag) { /* Line 889, Address: 0x1027140 */
    sv_move_sub2(); /* Line 890, Address: 0x1027150 */
    return; /* Line 891, Address: 0x1027158 */
  }


label1:
  scra_vz = 0; /* Line 896, Address: 0x1027160 */
} /* Line 897, Address: 0x1027168 */













static void sv_move_main(short yPos) { /* Line 911, Address: 0x1027180 */
  short spdwk;

  if (scra_vline == 96) { /* Line 914, Address: 0x1027190 */
    if (actwk[0].mspeed.w < 0) { /* Line 915, Address: 0x10271ac */
      spdwk = -actwk[0].mspeed.w; /* Line 916, Address: 0x10271c4 */
    } else { /* Line 917, Address: 0x10271e8 */
      spdwk = actwk[0].mspeed.w; /* Line 918, Address: 0x10271f0 */
    }


    if (spdwk >= 2048) { /* Line 922, Address: 0x1027200 */
      sv_move_main2(yPos); /* Line 923, Address: 0x1027214 */
    } /* Line 924, Address: 0x1027220 */
    else {

      if (yPos > 6) { /* Line 927, Address: 0x1027228 */
        sv_move_plus(1536); /* Line 928, Address: 0x1027240 */
      } else if (yPos < -6) { /* Line 929, Address: 0x102724c */
        sv_move_minus(1536); /* Line 930, Address: 0x102726c */
      } else /* Line 931, Address: 0x1027278 */
        sv_move_sub(yPos); /* Line 932, Address: 0x1027280 */
    }
  } /* Line 934, Address: 0x102728c */
  else {
    if (yPos > 2) { /* Line 936, Address: 0x1027294 */
      sv_move_plus(512); /* Line 937, Address: 0x10272ac */
    } else if (yPos < -2) { /* Line 938, Address: 0x10272b8 */
      sv_move_minus(512); /* Line 939, Address: 0x10272d8 */
    } else { /* Line 940, Address: 0x10272e4 */
      sv_move_sub(yPos); /* Line 941, Address: 0x10272ec */
    }
  }
} /* Line 944, Address: 0x10272f8 */













static void sv_move_main2(short yPos) { /* Line 958, Address: 0x1027310 */
  short spdwk;

  spdwk = 4096; /* Line 961, Address: 0x1027320 */

  if (yPos > 16) { /* Line 963, Address: 0x102732c */
    sv_move_plus(spdwk); /* Line 964, Address: 0x1027344 */
  } else if (yPos < -16) { /* Line 965, Address: 0x1027350 */
    sv_move_minus(spdwk); /* Line 966, Address: 0x1027370 */
  } else { /* Line 967, Address: 0x102737c */
    sv_move_sub(yPos); /* Line 968, Address: 0x1027384 */
  }
} /* Line 970, Address: 0x1027390 */














static void sv_move_sub(short yPos) { /* Line 985, Address: 0x10273b0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 988, Address: 0x10273bc */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 989, Address: 0x10273c0 */
  if (yPos < 0) { /* Line 990, Address: 0x10273ec */
    scrv_up_ch(lSpd); /* Line 991, Address: 0x1027400 */
  } else { /* Line 992, Address: 0x102740c */
    scrv_down_ch(lSpd); /* Line 993, Address: 0x1027414 */
  }
} /* Line 995, Address: 0x1027420 */



static void sv_move_sub2(void) { /* Line 999, Address: 0x1027430 */
  limmoveflag = 0; /* Line 1000, Address: 0x1027438 */

  sv_move_sub(0); /* Line 1002, Address: 0x1027440 */
 } /* Line 1003, Address: 0x102744c */













static void sv_move_minus(short speed) { /* Line 1017, Address: 0x1027460 */
  int_union lSpd;
  short wk;
  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1020, Address: 0x1027470 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1021, Address: 0x1027494 */
  scrv_up_ch(lSpd); /* Line 1022, Address: 0x10274ac */
} /* Line 1023, Address: 0x10274b8 */














static void scrv_up_ch(int_union lSpd) { /* Line 1038, Address: 0x10274d0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1039, Address: 0x10274dc */
    if (lSpd.w.l > -256) { /* Line 1040, Address: 0x1027504 */

      lSpd.w.l = scralim_up; /* Line 1042, Address: 0x102751c */
    } else { /* Line 1043, Address: 0x1027528 */
      lSpd.w.l &= 2047; /* Line 1044, Address: 0x1027530 */
      actwk[0].yposi.w.h &= 2047; /* Line 1045, Address: 0x102753c */
      scra_v_posit.w.h &= 2047; /* Line 1046, Address: 0x1027550 */
      scrb_v_posit.w.h &= 1023; /* Line 1047, Address: 0x1027564 */
    }
  }

  scrv_move(lSpd); /* Line 1051, Address: 0x1027578 */
} /* Line 1052, Address: 0x1027584 */













static void sv_move_plus(short sSpd) { /* Line 1066, Address: 0x10275a0 */
  int_union lSpd;
  short wk;
  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1069, Address: 0x10275b0 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1070, Address: 0x10275d0 */
  scrv_down_ch(lSpd); /* Line 1071, Address: 0x10275e8 */
} /* Line 1072, Address: 0x10275f4 */














static void scrv_down_ch(int_union lSpd) { /* Line 1087, Address: 0x1027610 */
  if (lSpd.w.l >= scralim_down) { /* Line 1088, Address: 0x102761c */
    if (lSpd.w.l < 2048) { /* Line 1089, Address: 0x1027644 */

      lSpd.w.l = scralim_down; /* Line 1091, Address: 0x102765c */
    } else { /* Line 1092, Address: 0x1027668 */
      lSpd.w.l -= 2048; /* Line 1093, Address: 0x1027670 */
      actwk[0].yposi.w.h &= 2047; /* Line 1094, Address: 0x102767c */
      scra_v_posit.w.h -= 2048; /* Line 1095, Address: 0x1027690 */
      scrb_v_posit.w.h &= 1023; /* Line 1096, Address: 0x10276a4 */
    }
  }

  scrv_move(lSpd); /* Line 1100, Address: 0x10276b8 */
} /* Line 1101, Address: 0x10276c4 */
















static void scrv_move(int_union lSpd) { /* Line 1118, Address: 0x10276e0 */
  short ywk, ysv;
  uint_union spdwk;
  short wk;
  ysv = scra_v_posit.w.h; /* Line 1122, Address: 0x10276f4 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1123, Address: 0x1027704 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1124, Address: 0x102771c */
  spdwk.l = (spdwk.l >> 8) | (spdwk.l << 24); /* Line 1125, Address: 0x1027730 */
  scra_vz = spdwk.w.l; /* Line 1126, Address: 0x1027748 */

  scra_v_posit.l = lSpd.l; /* Line 1128, Address: 0x1027754 */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1130, Address: 0x1027760 */
  if (!ywk) { /* Line 1131, Address: 0x102779c */
    scra_v_count ^= 16; /* Line 1132, Address: 0x10277a4 */
    ywk = scra_v_posit.w.h - ysv; /* Line 1133, Address: 0x10277b8 */
    if (ywk < 0) { /* Line 1134, Address: 0x10277e4 */
      scrflaga.b.h |= 1; /* Line 1135, Address: 0x10277f4 */
    } else { /* Line 1136, Address: 0x1027808 */
      scrflaga.b.h |= 2; /* Line 1137, Address: 0x1027810 */
    }
  }


} /* Line 1142, Address: 0x1027824 */

















void scrollwrt(void) { /* Line 1160, Address: 0x1027840 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1169, Address: 0x1027860 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1170, Address: 0x1027864 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1171, Address: 0x1027870 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1172, Address: 0x102787c */
  pScrFlag = &scrflagbw.b.h; /* Line 1173, Address: 0x1027884 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1174, Address: 0x102788c */

  VramBase = 16384; /* Line 1176, Address: 0x10278a0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1177, Address: 0x10278a4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1178, Address: 0x10278b0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1179, Address: 0x10278bc */
  pScrFlag = &scrflagaw.b.h; /* Line 1180, Address: 0x10278c4 */

  if (*pScrFlag) { /* Line 1182, Address: 0x10278cc */
    if (*pScrFlag & 1) { /* Line 1183, Address: 0x10278d8 */
      *pScrFlag &= 254; /* Line 1184, Address: 0x10278ec */

      lD4.l = -16; /* Line 1186, Address: 0x10278f8 */
      wD5 = 65520; /* Line 1187, Address: 0x1027900 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1189, Address: 0x1027908 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1191, Address: 0x1027928 */
    }




    if (*pScrFlag & 2) { /* Line 1197, Address: 0x1027954 */
      *pScrFlag &= 253; /* Line 1198, Address: 0x1027968 */

      lD4.l = 224; /* Line 1200, Address: 0x1027974 */
      wD5 = 65520; /* Line 1201, Address: 0x102797c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1202, Address: 0x1027984 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1204, Address: 0x10279a4 */
    }




    if (*pScrFlag & 4) { /* Line 1210, Address: 0x10279d0 */
      *pScrFlag &= 251; /* Line 1211, Address: 0x10279e4 */

      lD4.l = -16; /* Line 1213, Address: 0x10279f0 */
      wD5 = 65520; /* Line 1214, Address: 0x10279f8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1215, Address: 0x1027a00 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1217, Address: 0x1027a20 */
    }




    if (*pScrFlag & 8) { /* Line 1223, Address: 0x1027a4c */
      *pScrFlag &= 247; /* Line 1224, Address: 0x1027a60 */

      lD4.l = -16; /* Line 1226, Address: 0x1027a6c */
      wD5 = 320; /* Line 1227, Address: 0x1027a74 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1228, Address: 0x1027a7c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1230, Address: 0x1027a9c */
    }
  }






} /* Line 1239, Address: 0x1027ac8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1256, Address: 0x1027af0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  short wD0;
  POINT TilePoint;
  int BlkIndex;
  int i;


  lD4.l = -16; /* Line 1268, Address: 0x1027b1c */

  if (*pScrFlag & 1) { /* Line 1270, Address: 0x1027b24 */
    *pScrFlag &= 254; /* Line 1271, Address: 0x1027b3c */
  } /* Line 1272, Address: 0x1027b50 */
  else {
    *pScrFlag &= 254; /* Line 1274, Address: 0x1027b58 */

    if (*pScrFlag & 2) { /* Line 1276, Address: 0x1027b6c */
      *pScrFlag &= 253; /* Line 1277, Address: 0x1027b84 */
      lD4.w.l = 224; /* Line 1278, Address: 0x1027b98 */
    } /* Line 1279, Address: 0x1027ba0 */
    else {
      *pScrFlag &= 253; /* Line 1281, Address: 0x1027ba8 */
      goto label1; /* Line 1282, Address: 0x1027bbc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1287, Address: 0x1027bc4 */
  wD0 = z12bwrttbl[wD0 + 1]; /* Line 1288, Address: 0x1027c1c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1294, Address: 0x1027c44 */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1295, Address: 0x1027c68 */
  if (wD0 != 0) { /* Line 1296, Address: 0x1027c90 */
    wD5 = 65520; /* Line 1297, Address: 0x1027ca0 */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1298, Address: 0x1027ca8 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1300, Address: 0x1027cc8 */



  } /* Line 1304, Address: 0x1027cf4 */
  else {

    wD5 = 0; /* Line 1307, Address: 0x1027cfc */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1308, Address: 0x1027d00 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1312, Address: 0x1027d20 */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1319, Address: 0x1027d4c */






    lD4.l = -16; /* Line 1326, Address: 0x1027d60 */
    wD5 = 65520; /* Line 1327, Address: 0x1027d68 */
    if (*pScrFlag & 168) { /* Line 1328, Address: 0x1027d70 */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1329, Address: 0x1027d88 */
      wD5 = 320; /* Line 1330, Address: 0x1027da8 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1334, Address: 0x1027db0 */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1336, Address: 0x1027de0 */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1337, Address: 0x1027dec */



    for (i = 0; i < 16; ++i) { /* Line 1341, Address: 0x1027dfc */
      wD0 = z12bwrttbl[WrtTblCnt++]; /* Line 1342, Address: 0x1027e08 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1343, Address: 0x1027e2c */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1344, Address: 0x1027e5c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1345, Address: 0x1027e80 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1347, Address: 0x1027ea8 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1350, Address: 0x1027ecc */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1352, Address: 0x1027eec */
      }
      lD4.w.l += 16; /* Line 1354, Address: 0x1027f00 */
    } /* Line 1355, Address: 0x1027f0c */
    *pScrFlag = 0; /* Line 1356, Address: 0x1027f1c */
  }
} /* Line 1358, Address: 0x1027f24 */





void scrollwrtc(void) {} /* Line 1364, Address: 0x1027f50 */




void scrollwrtz(void) {} /* Line 1369, Address: 0x1027f60 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1387, Address: 0x1027f70 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1400, Address: 0x1027f98 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1403, Address: 0x1027fb8 */
    pTilePoint->x += 2; /* Line 1404, Address: 0x1027fcc */
    if (pTilePoint->x >= 64) { /* Line 1405, Address: 0x1027fe0 */
      pTilePoint->x -= 64; /* Line 1406, Address: 0x1027ff4 */
    }
    xOffs += 16; /* Line 1408, Address: 0x1028008 */
  } while (--lpcnt >= 0); /* Line 1409, Address: 0x1028014 */
} /* Line 1410, Address: 0x1028028 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1414, Address: 0x1028040 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1418, Address: 0x1028068 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1421, Address: 0x1028088 */
    pTilePoint->x += 2; /* Line 1422, Address: 0x102809c */
    if (pTilePoint->x >= 64) { /* Line 1423, Address: 0x10280b0 */
      pTilePoint->x -= 64; /* Line 1424, Address: 0x10280c4 */
    }
    xOffs += 16; /* Line 1426, Address: 0x10280d8 */
  } while (--lpcnt >= 0); /* Line 1427, Address: 0x10280e4 */
} /* Line 1428, Address: 0x10280f8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1448, Address: 0x1028110 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1452, Address: 0x1028138 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1455, Address: 0x1028158 */
    pTilePoint->y += 2; /* Line 1456, Address: 0x102816c */
    if (pTilePoint->y >= 32) { /* Line 1457, Address: 0x102817c */
      pTilePoint->y -= 32; /* Line 1458, Address: 0x1028190 */
    }
    yOffs += 16; /* Line 1460, Address: 0x10281a0 */
  } while (--lpcnt >= 0); /* Line 1461, Address: 0x10281ac */
} /* Line 1462, Address: 0x10281c0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1481, Address: 0x10281d0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) /* Line 1487, Address: 0x1028204 */
  {
    base = 1; /* Line 1489, Address: 0x1028214 */
  } /* Line 1490, Address: 0x1028218 */
  else if (VramBase == 16384) /* Line 1491, Address: 0x1028220 */
  {
    base = 0; /* Line 1493, Address: 0x1028230 */
  }
  x = pTilePoint->x; /* Line 1495, Address: 0x1028234 */
  y = pTilePoint->y; /* Line 1496, Address: 0x102823c */


  frip = BlkIndex & 6144; /* Line 1499, Address: 0x1028244 */
  BlkIndex &= 1023; /* Line 1500, Address: 0x102824c */
  if (frip == 6144) /* Line 1501, Address: 0x1028258 */
  {
    p0 = 3, p1 = 2; /* Line 1503, Address: 0x1028264 */
    p2 = 1, p3 = 0; /* Line 1504, Address: 0x102826c */
  } /* Line 1505, Address: 0x1028274 */
  else if (frip & 4096) /* Line 1506, Address: 0x102827c */
  {
    p0 = 2, p1 = 3; /* Line 1508, Address: 0x1028288 */
    p2 = 0, p3 = 1; /* Line 1509, Address: 0x1028290 */
  } /* Line 1510, Address: 0x1028298 */
  else if (frip & 2048) /* Line 1511, Address: 0x10282a0 */
  {
    p0 = 1, p1 = 0; /* Line 1513, Address: 0x10282ac */
    p2 = 3, p3 = 2; /* Line 1514, Address: 0x10282b4 */
  } /* Line 1515, Address: 0x10282bc */
  else
  {
    p0 = 0, p1 = 1; /* Line 1518, Address: 0x10282c4 */
    p2 = 2, p3 = 3; /* Line 1519, Address: 0x10282cc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1522, Address: 0x10282d4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1523, Address: 0x1028318 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1524, Address: 0x102835c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1525, Address: 0x10283a0 */

} /* Line 1527, Address: 0x10283e4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1545, Address: 0x1028420 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1546, Address: 0x1028440 */
} /* Line 1547, Address: 0x1028460 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1549, Address: 0x1028470 */
  wH_posiw = 0; /* Line 1550, Address: 0x1028490 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1551, Address: 0x1028494 */
} /* Line 1552, Address: 0x10284b4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1559, Address: 0x10284d0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1565, Address: 0x1028500 */
  yOffs += wV_posiw; /* Line 1566, Address: 0x1028510 */





  if ((short)xOffs < 0) /* Line 1572, Address: 0x1028520 */
    xOffs = 0; /* Line 1573, Address: 0x102853c */
  if ((short)yOffs < 0) /* Line 1574, Address: 0x1028540 */
    yOffs = 0; /* Line 1575, Address: 0x102855c */
  if ((short)xOffs >= 16384) /* Line 1576, Address: 0x1028560 */
    xOffs = 16383; /* Line 1577, Address: 0x1028580 */
  if ((short)yOffs >= 2048) /* Line 1578, Address: 0x1028588 */
    yOffs = 2047; /* Line 1579, Address: 0x10285a8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1580, Address: 0x10285b0 */
  if (i < 0) i = 0; /* Line 1581, Address: 0x10285f8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1583, Address: 0x1028604 */

  if (ScreenNo) { /* Line 1585, Address: 0x1028620 */




    xOffs &= 32767; /* Line 1590, Address: 0x1028628 */
    yOffs &= 32767; /* Line 1591, Address: 0x1028634 */


    xBlk = xOffs; /* Line 1594, Address: 0x1028640 */
    xBlk %= 256; /* Line 1595, Address: 0x1028648 */
    xBlk /= 16; /* Line 1596, Address: 0x1028668 */
    yBlk = yOffs; /* Line 1597, Address: 0x1028684 */
    yBlk %= 256; /* Line 1598, Address: 0x102868c */
    yBlk /= 16; /* Line 1599, Address: 0x10286ac */

    lpw = pmapwk; /* Line 1601, Address: 0x10286c8 */
    lpw += xBlk; /* Line 1602, Address: 0x10286d0 */
    lpw += yBlk * 16; /* Line 1603, Address: 0x10286d8 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1604, Address: 0x10286e4 */
    *pIndex = *lpw; /* Line 1605, Address: 0x10286fc */

    return 1; /* Line 1607, Address: 0x102870c */
  }

  *pIndex = 0; /* Line 1610, Address: 0x1028718 */
  return 0; /* Line 1611, Address: 0x1028720 */
} /* Line 1612, Address: 0x1028724 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1632, Address: 0x1028750 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1640, Address: 0x1028778 */
  if (ScreenNo) { /* Line 1641, Address: 0x10287dc */





    xBlk = xOffs; /* Line 1647, Address: 0x10287e4 */
    xBlk %= 256; /* Line 1648, Address: 0x10287ec */
    xBlk /= 16; /* Line 1649, Address: 0x102880c */
    yBlk = yOffs; /* Line 1650, Address: 0x1028828 */
    yBlk %= 256; /* Line 1651, Address: 0x1028830 */
    yBlk /= 16; /* Line 1652, Address: 0x1028850 */


    lpw = pmapwk; /* Line 1655, Address: 0x102886c */
    lpw += xBlk; /* Line 1656, Address: 0x1028874 */
    lpw += yBlk * 16; /* Line 1657, Address: 0x102887c */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1658, Address: 0x1028888 */
    *ppBlockNo = lpw; /* Line 1659, Address: 0x10288a0 */
    *pIndex = *lpw; /* Line 1660, Address: 0x10288a8 */




    return 1; /* Line 1665, Address: 0x10288b8 */
  }

  *pIndex = 0; /* Line 1668, Address: 0x10288c4 */
  return 0; /* Line 1669, Address: 0x10288cc */
} /* Line 1670, Address: 0x10288d0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1684, Address: 0x10288f0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1691, Address: 0x102890c */
  pMapWk = (unsigned char*)mapwka; /* Line 1692, Address: 0x1028910 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1693, Address: 0x1028918 */
    *pBlockIndex = BlockNo; /* Line 1694, Address: 0x102893c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1695, Address: 0x1028948 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1696, Address: 0x1028960 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1697, Address: 0x1028974 */
    }
  }


} /* Line 1702, Address: 0x102898c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1716, Address: 0x10289b0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1717, Address: 0x10289bc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1718, Address: 0x10289e8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1719, Address: 0x1028a34 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1720, Address: 0x1028a60 */

          return 0; /* Line 1722, Address: 0x1028aac */
        }
      }
    }
  }

  return 1; /* Line 1728, Address: 0x1028ab8 */
} /* Line 1729, Address: 0x1028abc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1746, Address: 0x1028ad0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1747, Address: 0x1028aec */

} /* Line 1749, Address: 0x1028b08 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1751, Address: 0x1028b20 */
  wH_posiw = 0; /* Line 1752, Address: 0x1028b3c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1753, Address: 0x1028b40 */

} /* Line 1755, Address: 0x1028b5c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1757, Address: 0x1028b70 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1758, Address: 0x1028b84 */

} /* Line 1760, Address: 0x1028ba0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1762, Address: 0x1028bb0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1763, Address: 0x1028bcc */

} /* Line 1765, Address: 0x1028be8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1767, Address: 0x1028c00 */
  xOffs += wH_posiw; /* Line 1768, Address: 0x1028c18 */
  yOffs += wV_posiw; /* Line 1769, Address: 0x1028c28 */
  yOffs &= 240; /* Line 1770, Address: 0x1028c38 */
  xOffs &= 496; /* Line 1771, Address: 0x1028c44 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1773, Address: 0x1028c50 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1774, Address: 0x1028c7c */


} /* Line 1777, Address: 0x1028ca8 */















void mapwrt(void) { /* Line 1793, Address: 0x1028cc0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1798, Address: 0x1028cd8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1799, Address: 0x1028ce4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1800, Address: 0x1028cf0 */
  VramBase = 16384; /* Line 1801, Address: 0x1028cf8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1802, Address: 0x1028cfc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1806, Address: 0x1028d14 */
  VramBase = 24576; /* Line 1807, Address: 0x1028d1c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1808, Address: 0x1028d20 */

} /* Line 1810, Address: 0x1028d30 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1813, Address: 0x1028d50 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1814, Address: 0x1028d68 */
} /* Line 1815, Address: 0x1028d88 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1820, Address: 0x1028da0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1824, Address: 0x1028dc0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1827, Address: 0x1028ddc */



    wD4 += 16; /* Line 1831, Address: 0x1028e04 */
  } while ((short)--wD6 >= 0); /* Line 1832, Address: 0x1028e10 */

} /* Line 1834, Address: 0x1028e38 */





void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1840, Address: 0x1028e50 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1843, Address: 0x1028e6c */
  wD6 = 15; /* Line 1844, Address: 0x1028e74 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1847, Address: 0x1028e7c */

    mapwrt_sub(&z12bwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1849, Address: 0x1028ea0 */
    wD4 += 16; /* Line 1850, Address: 0x1028ec0 */
  } while ((short)--wD6 >= 0); /* Line 1851, Address: 0x1028ec8 */
} /* Line 1852, Address: 0x1028eec */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1878, Address: 0x1028f10 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1883, Address: 0x1028f38 */
  wD0 = pWrttbl[wD0]; /* Line 1884, Address: 0x1028f48 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1886, Address: 0x1028f64 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1887, Address: 0x1028f88 */
  if (wD0) { /* Line 1888, Address: 0x1028fb0 */
    wD5 = 65520; /* Line 1889, Address: 0x1028fbc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1890, Address: 0x1028fc4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1893, Address: 0x1028fe0 */



  } /* Line 1897, Address: 0x1029008 */
  else {

    wD5 = 0; /* Line 1900, Address: 0x1029010 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1901, Address: 0x1029014 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1905, Address: 0x1029030 */
  }





} /* Line 1912, Address: 0x1029058 */










void mapinit(void) { /* Line 1923, Address: 0x1029080 */

  colorset2(mapinittbl.colorno2); /* Line 1925, Address: 0x1029088 */
  colorset(mapinittbl.colorno2); /* Line 1926, Address: 0x102909c */

  if (plflag) enecginit(); /* Line 1928, Address: 0x10290b0 */
  if (play_start & 2) divdevset(); /* Line 1929, Address: 0x10290c8 */
} /* Line 1930, Address: 0x10290e8 */







void divdevset() {} /* Line 1938, Address: 0x1029100 */




void enecginit(void) {} /* Line 1943, Address: 0x1029110 */
