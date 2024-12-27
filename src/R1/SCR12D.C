#include "..\EQU.H"
#include "SCR12C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1C.H"

static void playposiset();
static void scrbinit(short xWk, short yWk);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_hv(int xOffs, int yOffs);
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
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 134, Address: 0x1025230 */




void divdevset() {} /* Line 139, Address: 0x1025240 */












sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 153, Address: 0x1025250 */
  return &actwk[1]; /* Line 154, Address: 0x1025270 */
} /* Line 155, Address: 0x1025278 */










void scr_set() { /* Line 166, Address: 0x1025280 */
  unsigned short scr_dir_tbl[6] = { /* Line 167, Address: 0x102528c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 172, Address: 0x10252c0 */

  i = 0; /* Line 174, Address: 0x1025308 */
  scrar_no = scr_dir_tbl[i++]; /* Line 175, Address: 0x102530c */
  scralim_left = scralim_n_left = scr_dir_tbl[i++]; /* Line 176, Address: 0x1025328 */
  scralim_right = scralim_n_right = scr_dir_tbl[i++]; /* Line 177, Address: 0x102534c */
  scralim_up = scralim_n_up = scr_dir_tbl[i++]; /* Line 178, Address: 0x1025370 */
  scralim_down = scralim_n_down = scr_dir_tbl[i++]; /* Line 179, Address: 0x1025394 */

  scra_h_keep = scralim_left + 576; /* Line 181, Address: 0x10253b8 */
  scra_h_count = 16; /* Line 182, Address: 0x10253dc */
  scra_v_count = 16; /* Line 183, Address: 0x10253e8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 185, Address: 0x10253f4 */
  scra_hline = 160; /* Line 186, Address: 0x1025410 */

  playposiset(); /* Line 188, Address: 0x102541c */
} /* Line 189, Address: 0x1025424 */










static void playposiset() { /* Line 200, Address: 0x1025440 */
  unsigned short playpositbl[2] = { /* Line 201, Address: 0x1025450 */
    80, 389
  };
  unsigned short endplpositbl[16] = { /* Line 204, Address: 0x102546c */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 214, Address: 0x10254a0 */
    145, 182,
    127, 127
  };
  short xWk, yWk;

  if (plflag) { /* Line 220, Address: 0x10254cc */
    playload(); /* Line 221, Address: 0x10254dc */
    xWk = actwk[0].xposi.w.h; /* Line 222, Address: 0x10254e4 */
    yWk = actwk[0].yposi.w.h; /* Line 223, Address: 0x10254f4 */
    if (yWk < 0) yWk = 0; /* Line 224, Address: 0x1025504 */
  } /* Line 225, Address: 0x1025518 */
  else {
    if (demoflag.w & -32768) { /* Line 227, Address: 0x1025520 */
      xWk = actwk[0].xposi.w.h = endplpositbl[(enddemono - 1) * 2]; /* Line 228, Address: 0x1025540 */
      yWk = actwk[0].yposi.w.h = endplpositbl[(enddemono - 1) * 2 + 1]; /* Line 229, Address: 0x1025574 */
    } /* Line 230, Address: 0x10255ac */
    else {
      xWk = actwk[0].xposi.w.h = playpositbl[demoflag.w * 2]; /* Line 232, Address: 0x10255b4 */
      yWk = actwk[0].yposi.w.h = playpositbl[demoflag.w * 2 + 1]; /* Line 233, Address: 0x10255e4 */
    }
  }

  if (xWk > 160) xWk -= 160; /* Line 237, Address: 0x1025618 */
  else xWk = 0; /* Line 238, Address: 0x1025640 */
  if (scralim_right < xWk) xWk = scralim_right; /* Line 239, Address: 0x1025644 */
  scra_h_posit.w.h = xWk; /* Line 240, Address: 0x1025678 */

  if (yWk > 96) yWk -= 96; /* Line 242, Address: 0x1025680 */
  else yWk = 0; /* Line 243, Address: 0x10256a8 */
  if (scralim_down < yWk) yWk = scralim_down; /* Line 244, Address: 0x10256ac */
  scra_v_posit.w.h = yWk; /* Line 245, Address: 0x10256e0 */

  scrbinit(xWk, yWk); /* Line 247, Address: 0x10256e8 */

  loopmapno = playmapnotbl[0]; /* Line 249, Address: 0x10256f8 */
  loopmapno2 = playmapnotbl[1]; /* Line 250, Address: 0x1025704 */
  ballmapno = playmapnotbl[2]; /* Line 251, Address: 0x1025710 */
  ballmapno2 = playmapnotbl[3]; /* Line 252, Address: 0x102571c */
} /* Line 253, Address: 0x1025728 */











static void scrbinit(short xWk, short yWk) { /* Line 265, Address: 0x1025740 */
  int_union lYwk;

  lYwk.w.h = yWk; /* Line 268, Address: 0x1025750 */
  lYwk.w.l = 0; /* Line 269, Address: 0x1025758 */

  lYwk.l = (lYwk.l >> 4) * 2; /* Line 271, Address: 0x102575c */
  scrb_v_posit.l = lYwk.l; /* Line 272, Address: 0x102576c */
  scrc_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 273, Address: 0x1025778 */
  scrz_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 274, Address: 0x10257b8 */

  scrb_h_posit.w.h = (unsigned short)(xWk / 8); /* Line 276, Address: 0x10257f8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 277, Address: 0x1025830 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 278, Address: 0x1025870 */

  sMemSet(hscrollwork, 0, 16); /* Line 280, Address: 0x10258b0 */
} /* Line 281, Address: 0x10258d0 */










void scroll() { /* Line 292, Address: 0x10258e0 */
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* psHscr;
  int i;
  int j;
  unsigned short wD1;

  int_union lD0, lD2;
  int lD4, lD5;
  unsigned char z12d_cnttbl[4] = { 0, 4, 3, 3 }; /* Line 302, Address: 0x1025904 */
  static int scaddtbl[4] = { 65536, 49152, 32768, 16384 };


  if (scroll_start.b.h) return; /* Line 306, Address: 0x1025930 */

  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 308, Address: 0x1025940 */

  scrchk(); /* Line 310, Address: 0x102596c */

  scroll_h(); /* Line 312, Address: 0x1025974 */
  scroll_v(); /* Line 313, Address: 0x102597c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 315, Address: 0x1025984 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 316, Address: 0x1025994 */

  scrollz_h((scra_hz << 3) * 3, 6); /* Line 318, Address: 0x10259a4 */
  scrollc_h((scra_hz << 4) * 3, 4); /* Line 319, Address: 0x10259cc */

  lD4 = scra_hz << 5; /* Line 321, Address: 0x10259f4 */
  lD5 = (scra_vz << 4) * 2; /* Line 322, Address: 0x1025a08 */
  scrollb_hv(lD4, lD5); /* Line 323, Address: 0x1025a20 */

  vscroll.w.l = scrc_v_posit.w.h = scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 325, Address: 0x1025a30 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 327, Address: 0x1025a58 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 328, Address: 0x1025a90 */

  psHscr = (int_union*)hscrollwork; /* Line 330, Address: 0x1025aa4 */
  for (i = 0; i < 4; ++i) { /* Line 331, Address: 0x1025aac */
    psHscr->l += scaddtbl[i]; /* Line 332, Address: 0x1025ab8 */
    ++psHscr; /* Line 333, Address: 0x1025ad8 */
  } /* Line 334, Address: 0x1025adc */

  lD0.w.h = -scra_h_posit.w.h; /* Line 336, Address: 0x1025aec */
  psHscr = (int_union*)hscrollwork; /* Line 337, Address: 0x1025b0c */
  pHScrollWork = &hscrollwork[10]; /* Line 338, Address: 0x1025b14 */
  for (i = 3; i >= 0; --i) { /* Line 339, Address: 0x1025b1c */

    wD1 = -(psHscr->w.h + scrz_h_posit.w.h); /* Line 341, Address: 0x1025b28 */
    ++psHscr; /* Line 342, Address: 0x1025b54 */
    for (j = z12d_cnttbl[i]; j >= 0; --j) { /* Line 343, Address: 0x1025b58 */

      *pHScrollWork++ = wD1; /* Line 345, Address: 0x1025b6c */
    } /* Line 346, Address: 0x1025b78 */
  } /* Line 347, Address: 0x1025b88 */

  lD0.w.l = -scrz_h_posit.w.h; /* Line 349, Address: 0x1025b94 */
  for (i = 0; i < 8; ++i) { /* Line 350, Address: 0x1025bb4 */

    *pHScrollWork++ = lD0.w.l; /* Line 352, Address: 0x1025bc0 */
  } /* Line 353, Address: 0x1025bd0 */

  lD0.w.l = -scrb_h_posit.w.h; /* Line 355, Address: 0x1025be0 */
  for (i = 0; i < 2; ++i) { /* Line 356, Address: 0x1025c00 */

    *pHScrollWork++ = lD0.w.l; /* Line 358, Address: 0x1025c0c */
  } /* Line 359, Address: 0x1025c1c */

  lD0.w.l = -scrc_h_posit.w.h; /* Line 361, Address: 0x1025c2c */
  for (i = 0; i < 6; ++i) { /* Line 362, Address: 0x1025c4c */

    *pHScrollWork++ = lD0.w.l; /* Line 364, Address: 0x1025c58 */
  } /* Line 365, Address: 0x1025c68 */

  pHScrollBuff = lphscrollbuff; /* Line 367, Address: 0x1025c78 */
  pHScrollWork = hscrollwork; /* Line 368, Address: 0x1025c84 */
  lD2.w.l = lD0.w.l = scrb_v_posit.w.h; /* Line 369, Address: 0x1025c8c */
  lD0.w.l = (unsigned short)(lD0.w.l & 504) >> 2; /* Line 370, Address: 0x1025c9c */
  wD1 = 28; /* Line 371, Address: 0x1025cc4 */
  pHScrollWork += lD0.w.l / 2; /* Line 372, Address: 0x1025ccc */
  zonescrsetsub0(lD2.w.l, wD1, &pHScrollBuff, pHScrollWork); /* Line 373, Address: 0x1025cf8 */
} /* Line 374, Address: 0x1025d14 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 395, Address: 0x1025d40 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 399, Address: 0x1025d5c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 400, Address: 0x1025d60 */

  for (i = 0, j = yoffs & 7; yline >= i; ++i, j = 0) { /* Line 402, Address: 0x1025d80 */
    ldwk.w.l = *pHscrwk; /* Line 403, Address: 0x1025d9c */
    ++pHscrwk; /* Line 404, Address: 0x1025da8 */

    for ( ;j < 8; ++j, ++*pHscrbuf) { /* Line 406, Address: 0x1025db4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 407, Address: 0x1025dbc */
    } /* Line 408, Address: 0x1025dcc */
  } /* Line 409, Address: 0x1025df0 */
} /* Line 410, Address: 0x1025e10 */





















static void scrollb_hv(int xOffs, int yOffs) { /* Line 432, Address: 0x1025e30 */
  int lwk, lsv;
  int_union ldwk;

  lsv = scrb_h_posit.l; /* Line 436, Address: 0x1025e44 */
  ldwk.l = scrb_h_posit.l = lwk = lsv + xOffs; /* Line 437, Address: 0x1025e4c */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_h_count) == 0) { /* Line 438, Address: 0x1025e60 */
    scrb_h_count ^= 16; /* Line 439, Address: 0x1025e90 */
    if (lwk - lsv < 0) { /* Line 440, Address: 0x1025ea4 */
      scrflagb.b.h |= 4; /* Line 441, Address: 0x1025eb0 */
    } /* Line 442, Address: 0x1025ec4 */
    else {
      scrflagb.b.h |= 8; /* Line 444, Address: 0x1025ecc */
    }
  }


  lsv = scrb_v_posit.l; /* Line 449, Address: 0x1025ee0 */
  ldwk.l = scrb_v_posit.l = lwk = lsv + yOffs; /* Line 450, Address: 0x1025ee8 */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_v_count) == 0) { /* Line 451, Address: 0x1025efc */
    scrb_v_count ^= 16; /* Line 452, Address: 0x1025f2c */
    if (lwk - lsv < 0) { /* Line 453, Address: 0x1025f40 */
      scrflagb.b.h |= 1; /* Line 454, Address: 0x1025f4c */
    } /* Line 455, Address: 0x1025f60 */
    else {
      scrflagb.b.h |= 2; /* Line 457, Address: 0x1025f68 */
    }
  }


} /* Line 462, Address: 0x1025f7c */


































































































































static void scrollc_h(int xoffs, int flgbit) { /* Line 593, Address: 0x1025f90 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 597, Address: 0x1025fa4 */
  lXwk = lXsv + xoffs; /* Line 598, Address: 0x1025fac */
  scrc_h_posit.l = lXwk; /* Line 599, Address: 0x1025fb4 */
  ldXwk.l = lXwk; /* Line 600, Address: 0x1025fbc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 601, Address: 0x1025fc0 */
  ldXwk.w.l &= 16; /* Line 602, Address: 0x1025fe4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 603, Address: 0x1025ff0 */

  if (!ldXwk.b.b4) { /* Line 605, Address: 0x102600c */
    scrc_h_count ^= 16; /* Line 606, Address: 0x1026018 */
    if (lXwk - lXsv < 0) { /* Line 607, Address: 0x102602c */
      scrflagc.b.h |= 1 << flgbit; /* Line 608, Address: 0x1026038 */
    } /* Line 609, Address: 0x102605c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 611, Address: 0x1026064 */
    }
  }


} /* Line 616, Address: 0x102608c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 634, Address: 0x10260a0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 638, Address: 0x10260b4 */
  lXwk = lXsv + xoffs; /* Line 639, Address: 0x10260bc */
  scrz_h_posit.l = lXwk; /* Line 640, Address: 0x10260c4 */
  ldXwk.l = lXwk; /* Line 641, Address: 0x10260cc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 642, Address: 0x10260d0 */
  ldXwk.w.l &= 16; /* Line 643, Address: 0x10260f4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 644, Address: 0x1026100 */

  if (!ldXwk.b.b4) { /* Line 646, Address: 0x102611c */
    scrz_h_count ^= 16; /* Line 647, Address: 0x1026128 */
    if (lXwk - lXsv < 0) { /* Line 648, Address: 0x102613c */
      scrflagz.b.h |= 1 << flgbit; /* Line 649, Address: 0x1026148 */
    } /* Line 650, Address: 0x102616c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 652, Address: 0x1026174 */
    }
  }


} /* Line 657, Address: 0x102619c */














static void scroll_h() { /* Line 672, Address: 0x10261b0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 676, Address: 0x10261c0 */

  scrh_move(); /* Line 678, Address: 0x10261d0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 679, Address: 0x10261d8 */
  if (!bXwk) { /* Line 680, Address: 0x102620c */
    scra_h_count ^= 16; /* Line 681, Address: 0x1026214 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 682, Address: 0x1026228 */
      scrflaga.b.h |= 4; /* Line 683, Address: 0x102624c */
    } /* Line 684, Address: 0x1026260 */
    else scrflaga.b.h |= 8; /* Line 685, Address: 0x1026268 */
  }



} /* Line 690, Address: 0x102627c */
















static void scrh_move() { /* Line 707, Address: 0x10262a0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 710, Address: 0x10262a8 */
  if (xwk == 0) { /* Line 711, Address: 0x10262f0 */

    scra_hz = 0; /* Line 713, Address: 0x1026300 */
    return; /* Line 714, Address: 0x1026308 */
  } else if (xwk < 0) { /* Line 715, Address: 0x1026310 */

    if (xwk < -16) { /* Line 717, Address: 0x1026320 */
      xwk = -16; /* Line 718, Address: 0x1026334 */
    }


    xwk += scra_h_posit.w.h; /* Line 722, Address: 0x1026340 */
    if (xwk < scralim_left) { /* Line 723, Address: 0x1026354 */
      xwk = scralim_left; /* Line 724, Address: 0x1026378 */
    }
  } /* Line 726, Address: 0x1026388 */
  else {
    if (xwk > 16) { /* Line 728, Address: 0x1026390 */
      xwk = 16; /* Line 729, Address: 0x10263a4 */
    }


    xwk += scra_h_posit.w.h; /* Line 733, Address: 0x10263b0 */
    if (xwk > scralim_right) { /* Line 734, Address: 0x10263c4 */
      xwk = scralim_right; /* Line 735, Address: 0x10263e8 */
    }
  }


  scra_hz = xwk - scra_h_posit.w.h << 8; /* Line 740, Address: 0x10263f8 */
  scra_h_posit.w.h = xwk; /* Line 741, Address: 0x1026428 */
} /* Line 742, Address: 0x1026430 */














static void scroll_v() { /* Line 757, Address: 0x1026440 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 760, Address: 0x102644c */
  if (actwk[0].cddat & 4) { /* Line 761, Address: 0x1026480 */
    ywk -= 5; /* Line 762, Address: 0x1026498 */
  }


  if (actwk[0].cddat & 2) { /* Line 766, Address: 0x10264a4 */
    ywk += 32; /* Line 767, Address: 0x10264bc */
    if (ywk < scra_vline) { /* Line 768, Address: 0x10264c8 */
      ywk -= scra_vline; /* Line 769, Address: 0x10264ec */
      sv_move_main2(ywk); /* Line 770, Address: 0x1026500 */
      return; /* Line 771, Address: 0x102650c */
    } else if (ywk >= scra_vline + 64) { /* Line 772, Address: 0x1026514 */
      ywk -= scra_vline + 64; /* Line 773, Address: 0x102653c */
      sv_move_main2(ywk); /* Line 774, Address: 0x1026564 */
      return; /* Line 775, Address: 0x1026570 */
    }
    ywk -= scra_vline + 64; /* Line 777, Address: 0x1026578 */
    if (!limmoveflag) goto label1; /* Line 778, Address: 0x10265a0 */
    sv_move_sub2(); /* Line 779, Address: 0x10265b0 */
    return; /* Line 780, Address: 0x10265b8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 785, Address: 0x10265c0 */
    sv_move_main(ywk); /* Line 786, Address: 0x10265ec */
    return; /* Line 787, Address: 0x10265f8 */
  } else if (limmoveflag) { /* Line 788, Address: 0x1026600 */
    sv_move_sub2(); /* Line 789, Address: 0x1026610 */
    return; /* Line 790, Address: 0x1026618 */
  }


label1:
  scra_vz = 0; /* Line 795, Address: 0x1026620 */
} /* Line 796, Address: 0x1026628 */













static void sv_move_main(short yPos) { /* Line 810, Address: 0x1026640 */
  short spdwk;

  if (scra_vline == 96) { /* Line 813, Address: 0x1026650 */
    if (actwk[0].mspeed.w < 0) { /* Line 814, Address: 0x102666c */
      spdwk = -actwk[0].mspeed.w; /* Line 815, Address: 0x1026684 */
    } else { /* Line 816, Address: 0x10266a8 */
      spdwk = actwk[0].mspeed.w; /* Line 817, Address: 0x10266b0 */
    }


    if (spdwk >= 2048) { /* Line 821, Address: 0x10266c0 */
      sv_move_main2(yPos); /* Line 822, Address: 0x10266d4 */
    } /* Line 823, Address: 0x10266e0 */
    else {

      if (yPos > 6) { /* Line 826, Address: 0x10266e8 */
        sv_move_plus(1536); /* Line 827, Address: 0x1026700 */
      } else if (yPos < -6) { /* Line 828, Address: 0x102670c */
        sv_move_minus(1536); /* Line 829, Address: 0x102672c */
      } else /* Line 830, Address: 0x1026738 */
        sv_move_sub(yPos); /* Line 831, Address: 0x1026740 */
    }
  } /* Line 833, Address: 0x102674c */
  else {
    if (yPos > 2) { /* Line 835, Address: 0x1026754 */
      sv_move_plus(512); /* Line 836, Address: 0x102676c */
    } else if (yPos < -2) { /* Line 837, Address: 0x1026778 */
      sv_move_minus(512); /* Line 838, Address: 0x1026798 */
    } else { /* Line 839, Address: 0x10267a4 */
      sv_move_sub(yPos); /* Line 840, Address: 0x10267ac */
    }
  }
} /* Line 843, Address: 0x10267b8 */













static void sv_move_main2(short yPos) { /* Line 857, Address: 0x10267d0 */
  short spdwk;

  spdwk = 4096; /* Line 860, Address: 0x10267e0 */

  if (yPos > 16) { /* Line 862, Address: 0x10267ec */
    sv_move_plus(spdwk); /* Line 863, Address: 0x1026804 */
  } else if (yPos < -16) { /* Line 864, Address: 0x1026810 */
    sv_move_minus(spdwk); /* Line 865, Address: 0x1026830 */
  } else { /* Line 866, Address: 0x102683c */
    sv_move_sub(yPos); /* Line 867, Address: 0x1026844 */
  }
} /* Line 869, Address: 0x1026850 */














static void sv_move_sub(short yPos) { /* Line 884, Address: 0x1026870 */
  int_union lSpd;

  lSpd.l = 0; /* Line 887, Address: 0x102687c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 888, Address: 0x1026880 */
  if (yPos < 0) { /* Line 889, Address: 0x10268ac */
    scrv_up_ch(lSpd); /* Line 890, Address: 0x10268c0 */
  } else { /* Line 891, Address: 0x10268cc */
    scrv_down_ch(lSpd); /* Line 892, Address: 0x10268d4 */
  }
} /* Line 894, Address: 0x10268e0 */



static void sv_move_sub2() { /* Line 898, Address: 0x10268f0 */
  limmoveflag = 0; /* Line 899, Address: 0x10268f8 */

  sv_move_sub(0); /* Line 901, Address: 0x1026900 */
} /* Line 902, Address: 0x102690c */













static void sv_move_minus(short speed) { /* Line 916, Address: 0x1026920 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 919, Address: 0x102692c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 920, Address: 0x1026950 */
  scrv_up_ch(lSpd); /* Line 921, Address: 0x1026974 */
} /* Line 922, Address: 0x1026980 */














static void scrv_up_ch(int_union lSpd) { /* Line 937, Address: 0x1026990 */
  if (lSpd.w.l <= scralim_up) { /* Line 938, Address: 0x102699c */
    if (lSpd.w.l > -256) { /* Line 939, Address: 0x10269c4 */

      lSpd.w.l = scralim_up; /* Line 941, Address: 0x10269dc */
    } else { /* Line 942, Address: 0x10269e8 */
      lSpd.w.l &= 2047; /* Line 943, Address: 0x10269f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 944, Address: 0x10269fc */
      scra_v_posit.w.h &= 2047; /* Line 945, Address: 0x1026a10 */
      scrb_v_posit.w.h &= 1023; /* Line 946, Address: 0x1026a24 */
    }
  }

  scrv_move(lSpd); /* Line 950, Address: 0x1026a38 */
} /* Line 951, Address: 0x1026a44 */













static void sv_move_plus(short sSpd) { /* Line 965, Address: 0x1026a60 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 968, Address: 0x1026a6c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 969, Address: 0x1026a8c */
  scrv_down_ch(lSpd); /* Line 970, Address: 0x1026ab0 */
} /* Line 971, Address: 0x1026abc */














static void scrv_down_ch(int_union lSpd) { /* Line 986, Address: 0x1026ad0 */
  if (lSpd.w.l >= scralim_down) { /* Line 987, Address: 0x1026adc */
    if (lSpd.w.l < 2048) { /* Line 988, Address: 0x1026b04 */

      lSpd.w.l = scralim_down; /* Line 990, Address: 0x1026b1c */
    } else { /* Line 991, Address: 0x1026b28 */
      lSpd.w.l -= 2048; /* Line 992, Address: 0x1026b30 */
      actwk[0].yposi.w.h &= 2047; /* Line 993, Address: 0x1026b3c */
      scra_v_posit.w.h -= 2048; /* Line 994, Address: 0x1026b50 */
      scrb_v_posit.w.h &= 1023; /* Line 995, Address: 0x1026b64 */
    }
  }

  scrv_move(lSpd); /* Line 999, Address: 0x1026b78 */
} /* Line 1000, Address: 0x1026b84 */
















static void scrv_move(int_union lSpd) { /* Line 1017, Address: 0x1026ba0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1021, Address: 0x1026bb0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1022, Address: 0x1026bc0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1023, Address: 0x1026be4 */
  spdwk.l = (spdwk.l >> 8) | (spdwk.l << 24); /* Line 1024, Address: 0x1026bf8 */
  scra_vz = spdwk.w.l; /* Line 1025, Address: 0x1026c10 */

  scra_v_posit.l = lSpd.l; /* Line 1027, Address: 0x1026c1c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1029, Address: 0x1026c28 */
  if (!ywk) { /* Line 1030, Address: 0x1026c64 */
    scra_v_count ^= 16; /* Line 1031, Address: 0x1026c6c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1032, Address: 0x1026c80 */
    if (ywk < 0) { /* Line 1033, Address: 0x1026cac */
      scrflaga.b.h |= 1; /* Line 1034, Address: 0x1026cbc */
    } else { /* Line 1035, Address: 0x1026cd0 */
      scrflaga.b.h |= 2; /* Line 1036, Address: 0x1026cd8 */
    }
  }


} /* Line 1041, Address: 0x1026cec */







































void scrollwrt() { /* Line 1081, Address: 0x1026d00 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  pScrFlag = &scrflagbw.b.h; /* Line 1090, Address: 0x1026d20 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1091, Address: 0x1026d28 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1092, Address: 0x1026d34 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1093, Address: 0x1026d40 */
  VramBase = 24576; /* Line 1094, Address: 0x1026d48 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1095, Address: 0x1026d4c */











  pScrFlag = &scrflagaw.b.h; /* Line 1107, Address: 0x1026d60 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1108, Address: 0x1026d68 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1109, Address: 0x1026d74 */
  pMapWk = (unsigned char*)mapwka; /* Line 1110, Address: 0x1026d80 */
  VramBase = 16384; /* Line 1111, Address: 0x1026d88 */

  if (*pScrFlag) { /* Line 1113, Address: 0x1026d8c */
    if (*pScrFlag & 1) { /* Line 1114, Address: 0x1026d98 */
      *pScrFlag &= 254; /* Line 1115, Address: 0x1026dac */

      lD4.l = -16; /* Line 1117, Address: 0x1026db8 */
      wD5 = 65520; /* Line 1118, Address: 0x1026dc0 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1119, Address: 0x1026dc8 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1120, Address: 0x1026de8 */
    }
    if (*pScrFlag & 2) { /* Line 1122, Address: 0x1026e14 */
      *pScrFlag &= 253; /* Line 1123, Address: 0x1026e28 */

      lD4.l = 224; /* Line 1125, Address: 0x1026e34 */
      wD5 = 65520; /* Line 1126, Address: 0x1026e3c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1127, Address: 0x1026e44 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1128, Address: 0x1026e64 */
    }
    if (*pScrFlag & 4) { /* Line 1130, Address: 0x1026e90 */
      *pScrFlag &= 251; /* Line 1131, Address: 0x1026ea4 */

      lD4.l = -16; /* Line 1133, Address: 0x1026eb0 */
      wD5 = 65520; /* Line 1134, Address: 0x1026eb8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1135, Address: 0x1026ec0 */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1136, Address: 0x1026ee0 */
    }
    if (*pScrFlag & 8) { /* Line 1138, Address: 0x1026f0c */
      *pScrFlag &= 247; /* Line 1139, Address: 0x1026f20 */

      lD4.l = -16; /* Line 1141, Address: 0x1026f2c */
      wD5 = 320; /* Line 1142, Address: 0x1026f34 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1143, Address: 0x1026f3c */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1144, Address: 0x1026f5c */
    }
  }
} /* Line 1147, Address: 0x1026f88 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1161, Address: 0x1026fb0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1172, Address: 0x1026fdc */

  if (*pScrFlag & 1) { /* Line 1174, Address: 0x1026fe4 */
    *pScrFlag &= 254; /* Line 1175, Address: 0x1026ffc */
  } /* Line 1176, Address: 0x1027010 */
  else {
    *pScrFlag &= 254; /* Line 1178, Address: 0x1027018 */

    if (*pScrFlag & 2) { /* Line 1180, Address: 0x102702c */
      *pScrFlag &= 253; /* Line 1181, Address: 0x1027044 */
      lD4.w.l = 224; /* Line 1182, Address: 0x1027058 */
    } /* Line 1183, Address: 0x1027060 */
    else {
      *pScrFlag &= 253; /* Line 1185, Address: 0x1027068 */
      goto label1; /* Line 1186, Address: 0x102707c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1191, Address: 0x1027084 */
  wD0 &= 127; /* Line 1192, Address: 0x10270d4 */
  wD0 = z12dwrttbl[wD0 + 1]; /* Line 1193, Address: 0x10270dc */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1194, Address: 0x10270fc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1195, Address: 0x102711c */
  if (wD0 != 0) { /* Line 1196, Address: 0x1027140 */
    wD5 = 65520; /* Line 1197, Address: 0x102714c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1198, Address: 0x1027154 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1200, Address: 0x1027174 */



  } /* Line 1204, Address: 0x10271a0 */
  else {

    wD5 = 0; /* Line 1207, Address: 0x10271a8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1208, Address: 0x10271ac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1212, Address: 0x10271cc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1219, Address: 0x10271f8 */






    lD4.l = -16; /* Line 1226, Address: 0x102720c */
    wD5 = 65520; /* Line 1227, Address: 0x1027214 */
    if (*pScrFlag & 168) { /* Line 1228, Address: 0x102721c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1229, Address: 0x1027234 */
      wD5 = 320; /* Line 1230, Address: 0x1027254 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1234, Address: 0x102725c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1236, Address: 0x102728c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1237, Address: 0x1027298 */



    for (i = 0; i < 16; ++i) { /* Line 1241, Address: 0x10272a8 */
      wD0 = z12dwrttbl[WrtTblCnt++]; /* Line 1242, Address: 0x10272b4 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1243, Address: 0x10272d4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1244, Address: 0x1027300 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1245, Address: 0x1027320 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1247, Address: 0x1027344 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1250, Address: 0x1027368 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1252, Address: 0x1027388 */
      }
      lD4.w.l += 16; /* Line 1254, Address: 0x102739c */
    } /* Line 1255, Address: 0x10273a8 */
    *pScrFlag = 0; /* Line 1256, Address: 0x10273b8 */
  }
} /* Line 1258, Address: 0x10273c0 */


























void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1285, Address: 0x10273f0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1298, Address: 0x1027418 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1301, Address: 0x1027438 */
    pTilePoint->x += 2; /* Line 1302, Address: 0x102744c */
    if (pTilePoint->x >= 64) { /* Line 1303, Address: 0x1027460 */
      pTilePoint->x -= 64; /* Line 1304, Address: 0x1027474 */
    }
    xOffs += 16; /* Line 1306, Address: 0x1027488 */
  } while (--lpcnt >= 0); /* Line 1307, Address: 0x1027494 */
} /* Line 1308, Address: 0x10274a8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1312, Address: 0x10274c0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1316, Address: 0x10274e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1319, Address: 0x1027508 */
    pTilePoint->x += 2; /* Line 1320, Address: 0x102751c */
    if (pTilePoint->x >= 64) { /* Line 1321, Address: 0x1027530 */
      pTilePoint->x -= 64; /* Line 1322, Address: 0x1027544 */
    }
    xOffs += 16; /* Line 1324, Address: 0x1027558 */
  } while (--lpcnt >= 0); /* Line 1325, Address: 0x1027564 */
} /* Line 1326, Address: 0x1027578 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1342, Address: 0x1027590 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1346, Address: 0x10275b8 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1347, Address: 0x10275d8 */
    pTilePoint->y += 2; /* Line 1348, Address: 0x10275ec */
    if (pTilePoint->y >= 32) pTilePoint->y -= 32; /* Line 1349, Address: 0x10275fc */
    yOffs += 16; /* Line 1350, Address: 0x1027620 */
  } while (--lpcnt >= 0); /* Line 1351, Address: 0x102762c */
} /* Line 1352, Address: 0x1027640 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1370, Address: 0x1027650 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) base = 1; /* Line 1376, Address: 0x1027684 */
  else if (VramBase == 16384) base = 0; /* Line 1377, Address: 0x10276a0 */
  x = pTilePoint->x; /* Line 1378, Address: 0x10276b4 */
  y = pTilePoint->y; /* Line 1379, Address: 0x10276bc */

  frip = BlkIndex & 6144; /* Line 1381, Address: 0x10276c4 */
  BlkIndex &= 1023; /* Line 1382, Address: 0x10276cc */
  if (frip == 6144) { /* Line 1383, Address: 0x10276d8 */
    p0 = 3; /* Line 1384, Address: 0x10276e4 */
    p1 = 2; /* Line 1385, Address: 0x10276e8 */
    p2 = 1; /* Line 1386, Address: 0x10276ec */
    p3 = 0; /* Line 1387, Address: 0x10276f0 */
  } /* Line 1388, Address: 0x10276f4 */
  else if (frip & 4096) { /* Line 1389, Address: 0x10276fc */
    p0 = 2; /* Line 1390, Address: 0x1027708 */
    p1 = 3; /* Line 1391, Address: 0x102770c */
    p2 = 0; /* Line 1392, Address: 0x1027710 */
    p3 = 1; /* Line 1393, Address: 0x1027714 */
  } /* Line 1394, Address: 0x1027718 */
  else if (frip & 2048) { /* Line 1395, Address: 0x1027720 */
    p0 = 1; /* Line 1396, Address: 0x102772c */
    p1 = 0; /* Line 1397, Address: 0x1027730 */
    p2 = 3; /* Line 1398, Address: 0x1027734 */
    p3 = 2; /* Line 1399, Address: 0x1027738 */
  } /* Line 1400, Address: 0x102773c */
  else {
    p0 = 0; /* Line 1402, Address: 0x1027744 */
    p1 = 1; /* Line 1403, Address: 0x1027748 */
    p2 = 2; /* Line 1404, Address: 0x102774c */
    p3 = 3; /* Line 1405, Address: 0x1027750 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1408, Address: 0x1027754 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1409, Address: 0x1027798 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1410, Address: 0x10277dc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1411, Address: 0x1027820 */
} /* Line 1412, Address: 0x1027864 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1431, Address: 0x10278a0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1432, Address: 0x10278c0 */
} /* Line 1433, Address: 0x10278e0 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1436, Address: 0x10278f0 */
  wH_posiw = 0; /* Line 1437, Address: 0x1027910 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1438, Address: 0x1027914 */
} /* Line 1439, Address: 0x1027934 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1442, Address: 0x1027950 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1448, Address: 0x1027980 */
  yOffs += wV_posiw; /* Line 1449, Address: 0x1027990 */


  if ((short)xOffs < 0) xOffs = 0; /* Line 1452, Address: 0x10279a0 */
  if ((short)yOffs < 0) yOffs = 0; /* Line 1453, Address: 0x10279c0 */
  if ((short)xOffs >= 16384) xOffs = 16383; /* Line 1454, Address: 0x10279e0 */
  if ((short)yOffs >= 2048) yOffs = 2047; /* Line 1455, Address: 0x1027a08 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1456, Address: 0x1027a30 */
  if (i < 0) i = 0; /* Line 1457, Address: 0x1027a78 */

  ScreenNo = pMapWk[i] & 127; /* Line 1459, Address: 0x1027a84 */

  if (ScreenNo) { /* Line 1461, Address: 0x1027aa0 */
    xOffs &= 32767; /* Line 1462, Address: 0x1027aa8 */
    yOffs &= 32767; /* Line 1463, Address: 0x1027ab4 */

    xBlk = xOffs; /* Line 1465, Address: 0x1027ac0 */
    xBlk %= 256; /* Line 1466, Address: 0x1027ac8 */
    xBlk /= 16; /* Line 1467, Address: 0x1027ae8 */
    yBlk = yOffs; /* Line 1468, Address: 0x1027b04 */
    yBlk %= 256; /* Line 1469, Address: 0x1027b0c */
    yBlk /= 16; /* Line 1470, Address: 0x1027b2c */

    lpw = pmapwk; /* Line 1472, Address: 0x1027b48 */
    lpw += xBlk; /* Line 1473, Address: 0x1027b50 */
    lpw += yBlk * 16; /* Line 1474, Address: 0x1027b58 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1475, Address: 0x1027b64 */
    *pIndex = *lpw; /* Line 1476, Address: 0x1027b7c */

    return 1; /* Line 1478, Address: 0x1027b8c */
  }
  *pIndex = 0; /* Line 1480, Address: 0x1027b98 */
  return 0; /* Line 1481, Address: 0x1027ba0 */
} /* Line 1482, Address: 0x1027ba4 */















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1498, Address: 0x1027bd0 */
  int xBlk, yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;

  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1503, Address: 0x1027bf8 */
  if (ScreenNo) { /* Line 1504, Address: 0x1027c5c */
    xBlk = xOffs; /* Line 1505, Address: 0x1027c64 */
    xBlk %= 256; /* Line 1506, Address: 0x1027c6c */
    xBlk /= 16; /* Line 1507, Address: 0x1027c8c */
    yBlk = yOffs; /* Line 1508, Address: 0x1027ca8 */
    yBlk %= 256; /* Line 1509, Address: 0x1027cb0 */
    yBlk /= 16; /* Line 1510, Address: 0x1027cd0 */

    lpw = pmapwk; /* Line 1512, Address: 0x1027cec */
    lpw += xBlk; /* Line 1513, Address: 0x1027cf4 */
    lpw += yBlk * 16; /* Line 1514, Address: 0x1027cfc */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1515, Address: 0x1027d08 */
    *ppBlockNo = lpw; /* Line 1516, Address: 0x1027d20 */
    *pIndex = *lpw; /* Line 1517, Address: 0x1027d28 */

    return 1; /* Line 1519, Address: 0x1027d38 */
  }
  *pIndex = 0; /* Line 1521, Address: 0x1027d44 */
  return 0; /* Line 1522, Address: 0x1027d4c */
} /* Line 1523, Address: 0x1027d50 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1537, Address: 0x1027d70 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1544, Address: 0x1027d8c */
  pMapWk = (unsigned char*)mapwka; /* Line 1545, Address: 0x1027d90 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1546, Address: 0x1027d98 */
    *pBlockIndex = BlockNo; /* Line 1547, Address: 0x1027dbc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1548, Address: 0x1027dc8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1549, Address: 0x1027de0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1550, Address: 0x1027df4 */
    }
  }
} /* Line 1553, Address: 0x1027e0c */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1565, Address: 0x1027e30 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1566, Address: 0x1027e3c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1567, Address: 0x1027e68 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1568, Address: 0x1027eb4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) return 0; /* Line 1569, Address: 0x1027ee0 */
      }
    }
  }
  return 1; /* Line 1573, Address: 0x1027f38 */
} /* Line 1574, Address: 0x1027f3c */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1589, Address: 0x1027f50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1590, Address: 0x1027f6c */
} /* Line 1591, Address: 0x1027f88 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1594, Address: 0x1027fa0 */
  wH_posiw = 0; /* Line 1595, Address: 0x1027fbc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1596, Address: 0x1027fc0 */
} /* Line 1597, Address: 0x1027fdc */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1600, Address: 0x1027ff0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1601, Address: 0x1028004 */
} /* Line 1602, Address: 0x1028020 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1605, Address: 0x1028030 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1606, Address: 0x102804c */
} /* Line 1607, Address: 0x1028068 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1610, Address: 0x1028080 */
  xOffs += wH_posiw; /* Line 1611, Address: 0x1028098 */
  yOffs += wV_posiw; /* Line 1612, Address: 0x10280a8 */
  yOffs &= 240; /* Line 1613, Address: 0x10280b8 */
  xOffs &= 496; /* Line 1614, Address: 0x10280c4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1616, Address: 0x10280d0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1617, Address: 0x10280fc */

} /* Line 1619, Address: 0x1028128 */













void mapwrt() { /* Line 1633, Address: 0x1028140 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1638, Address: 0x1028158 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1639, Address: 0x1028164 */
  pMapWk = (unsigned char*)mapwka; /* Line 1640, Address: 0x1028170 */
  VramBase = 16384; /* Line 1641, Address: 0x1028178 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1642, Address: 0x102817c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1646, Address: 0x1028194 */
  VramBase = 24576; /* Line 1647, Address: 0x102819c */
  mapwrt_z11c(pMapWk, VramBase); /* Line 1648, Address: 0x10281a0 */
} /* Line 1649, Address: 0x10281b0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1652, Address: 0x10281d0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1653, Address: 0x10281e8 */
} /* Line 1654, Address: 0x1028208 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1657, Address: 0x1028220 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1661, Address: 0x1028240 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1662, Address: 0x102825c */
    wD4 += 16; /* Line 1663, Address: 0x1028284 */
  } while ((short)--wD6 >= 0); /* Line 1664, Address: 0x1028290 */
} /* Line 1665, Address: 0x10282b8 */


void mapwrt_z11c(unsigned char* pMapWk, int VramBase) { /* Line 1668, Address: 0x10282d0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1671, Address: 0x10282ec */
  wD6 = 15; /* Line 1672, Address: 0x10282f4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1675, Address: 0x10282fc */
    mapwrt_sub(&z12dwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1676, Address: 0x1028320 */
    wD4 += 16; /* Line 1677, Address: 0x1028340 */
  } while ((short)--wD6 >= 0); /* Line 1678, Address: 0x1028348 */
} /* Line 1679, Address: 0x102836c */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1695, Address: 0x1028390 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1700, Address: 0x10283b8 */
  wD0 = pWrttbl[wD0]; /* Line 1701, Address: 0x10283c8 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1702, Address: 0x10283e4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1703, Address: 0x1028408 */
  if (wD0) { /* Line 1704, Address: 0x1028430 */
    wD5 = 65520; /* Line 1705, Address: 0x102843c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1706, Address: 0x1028444 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1707, Address: 0x1028460 */
  } /* Line 1708, Address: 0x1028488 */
  else {
    wD5 = 0; /* Line 1710, Address: 0x1028490 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1711, Address: 0x1028494 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1712, Address: 0x10284b0 */
  }
} /* Line 1714, Address: 0x10284d8 */










void mapinit() { /* Line 1725, Address: 0x1028500 */

  colorset2(mapinittbl.colorno2); /* Line 1727, Address: 0x1028508 */
  colorset(mapinittbl.colorno2); /* Line 1728, Address: 0x102851c */

  if (plflag) enecginit(); /* Line 1730, Address: 0x1028530 */
  if (play_start & 2) divdevset(); /* Line 1731, Address: 0x1028548 */
} /* Line 1732, Address: 0x1028568 */
