#include "..\EQU.H"
#include "SCR12C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1C.H"

static void playposiset(void);
static void scrbinit(short xWk, short yWk);
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

static unsigned char z12cwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 6,
  6, 6, 2, 4, 4, 4, 4, 0, 0, 0,
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















































































void enecginit(void) {} /* Line 135, Address: 0x1025200 */




void divdevset() {} /* Line 140, Address: 0x1025210 */












sprite_status* main_chk(void) {
  if (!main_play) return &actwk[0]; /* Line 154, Address: 0x1025220 */
  return &actwk[1]; /* Line 155, Address: 0x1025240 */
} /* Line 156, Address: 0x1025248 */










void scr_set(void) { /* Line 167, Address: 0x1025250 */
  unsigned short scr_dir_tbl[6] = { /* Line 168, Address: 0x102525c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 173, Address: 0x1025290 */

  i = 0; /* Line 175, Address: 0x10252d8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 176, Address: 0x10252dc */
  scralim_left = scralim_n_left = scr_dir_tbl[i++]; /* Line 177, Address: 0x10252f8 */
  scralim_right = scralim_n_right = scr_dir_tbl[i++]; /* Line 178, Address: 0x102531c */
  scralim_up = scralim_n_up = scr_dir_tbl[i++]; /* Line 179, Address: 0x1025340 */
  scralim_down = scralim_n_down = scr_dir_tbl[i++]; /* Line 180, Address: 0x1025364 */

  scra_h_keep = scralim_left + 576; /* Line 182, Address: 0x1025388 */
  scra_h_count = 16; /* Line 183, Address: 0x10253ac */
  scra_v_count = 16; /* Line 184, Address: 0x10253b8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 186, Address: 0x10253c4 */
  scra_hline = 160; /* Line 187, Address: 0x10253e0 */

  playposiset(); /* Line 189, Address: 0x10253ec */
} /* Line 190, Address: 0x10253f4 */










static void playposiset(void) { /* Line 201, Address: 0x1025410 */
  unsigned short playpositbl[2] = { /* Line 202, Address: 0x1025420 */
    80, 389
  };
  unsigned short endplpositbl[16] = { /* Line 205, Address: 0x102543c */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 215, Address: 0x1025470 */
    145, 182,
    127, 127
  };
  short xWk, yWk;

  if (plflag) { /* Line 221, Address: 0x102549c */
    playload(); /* Line 222, Address: 0x10254ac */
    xWk = actwk[0].xposi.w.h; /* Line 223, Address: 0x10254b4 */
    yWk = actwk[0].yposi.w.h; /* Line 224, Address: 0x10254c4 */
    if (yWk < 0) yWk = 0; /* Line 225, Address: 0x10254d4 */
  } /* Line 226, Address: 0x10254e8 */
  else {
    if (demoflag.w & -32768) { /* Line 228, Address: 0x10254f0 */
      xWk = actwk[0].xposi.w.h = endplpositbl[(enddemono - 1) * 2]; /* Line 229, Address: 0x1025510 */
      yWk = actwk[0].yposi.w.h = endplpositbl[(enddemono - 1) * 2 + 1]; /* Line 230, Address: 0x1025544 */
    } /* Line 231, Address: 0x102557c */
    else {
      xWk = actwk[0].xposi.w.h = playpositbl[demoflag.w * 2]; /* Line 233, Address: 0x1025584 */
      yWk = actwk[0].yposi.w.h = playpositbl[demoflag.w * 2 + 1]; /* Line 234, Address: 0x10255b4 */
    }
  }

  if (xWk > 160) xWk -= 160; /* Line 238, Address: 0x10255e8 */
  else xWk = 0; /* Line 239, Address: 0x1025610 */
  if (scralim_right < xWk) xWk = scralim_right; /* Line 240, Address: 0x1025614 */
  scra_h_posit.w.h = xWk; /* Line 241, Address: 0x1025648 */

  if (yWk > 96) yWk -= 96; /* Line 243, Address: 0x1025650 */
  else yWk = 0; /* Line 244, Address: 0x1025678 */
  if (scralim_down < yWk) yWk = scralim_down; /* Line 245, Address: 0x102567c */
  scra_v_posit.w.h = yWk; /* Line 246, Address: 0x10256b0 */

  scrbinit(xWk, yWk); /* Line 248, Address: 0x10256b8 */

  loopmapno = playmapnotbl[0]; /* Line 250, Address: 0x10256c8 */
  loopmapno2 = playmapnotbl[1]; /* Line 251, Address: 0x10256d4 */
  ballmapno = playmapnotbl[2]; /* Line 252, Address: 0x10256e0 */
  ballmapno2 = playmapnotbl[3]; /* Line 253, Address: 0x10256ec */
} /* Line 254, Address: 0x10256f8 */











static void scrbinit(short xWk, short yWk) { /* Line 266, Address: 0x1025710 */
  int_union lYwk;

  lYwk.w.h = yWk; /* Line 269, Address: 0x1025720 */
  lYwk.w.l = 0; /* Line 270, Address: 0x1025728 */

  lYwk.l = (lYwk.l >> 4) * 3; /* Line 272, Address: 0x102572c */
  scrb_v_posit.l = lYwk.l; /* Line 273, Address: 0x1025740 */
  scrc_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 274, Address: 0x102574c */
  scrz_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 275, Address: 0x102578c */

  scrb_h_posit.w.h = (unsigned short)(xWk / 8); /* Line 277, Address: 0x10257cc */
  scrc_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 278, Address: 0x1025804 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 279, Address: 0x1025844 */

  sMemSet(hscrollwork, 0, 20); /* Line 281, Address: 0x1025884 */
} /* Line 282, Address: 0x10258a4 */










void scroll(void) { /* Line 293, Address: 0x10258c0 */
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* psHscr;
  int i;
  int j;
  unsigned short wD1;
  unsigned short temp;
  int_union lD0, lD2, lD3;
  int lD4, lD5;
  unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 }; /* Line 303, Address: 0x10258e8 */
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };


  if (scroll_start.b.h) return; /* Line 307, Address: 0x1025914 */

  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 309, Address: 0x1025924 */

  scrchk(); /* Line 311, Address: 0x1025950 */

  scroll_h(); /* Line 313, Address: 0x1025958 */
  scroll_v(); /* Line 314, Address: 0x1025960 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 316, Address: 0x1025968 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 317, Address: 0x1025978 */

  scrollz_h((scra_hz << 3) * 3, 6); /* Line 319, Address: 0x1025988 */
  scrollc_h((scra_hz << 4) * 3, 4); /* Line 320, Address: 0x10259b0 */

  lD4 = scra_hz << 5; /* Line 322, Address: 0x10259d8 */
  lD5 = (scra_vz << 4) * 3; /* Line 323, Address: 0x10259ec */
  scrollb_hv(lD4, lD5); /* Line 324, Address: 0x1025a08 */

  vscroll.w.l = scrc_v_posit.w.h = scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 326, Address: 0x1025a18 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 328, Address: 0x1025a40 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 329, Address: 0x1025a78 */

  psHscr = (int_union*)hscrollwork; /* Line 331, Address: 0x1025a8c */
  for (i = 0; i < 5; ++i) { /* Line 332, Address: 0x1025a94 */
    psHscr->l += scaddtbl[i]; /* Line 333, Address: 0x1025aa0 */
    ++psHscr; /* Line 334, Address: 0x1025ac0 */
  } /* Line 335, Address: 0x1025ac4 */

  lD0.w.h = -scra_h_posit.w.h; /* Line 337, Address: 0x1025ad4 */
  psHscr = (int_union*)hscrollwork; /* Line 338, Address: 0x1025af4 */
  pHScrollWork = &hscrollwork[10]; /* Line 339, Address: 0x1025afc */
  for (i = 4; i >= 0; --i) { /* Line 340, Address: 0x1025b04 */

    wD1 = -(psHscr->w.h + scrz_h_posit.w.h); /* Line 342, Address: 0x1025b10 */
    ++psHscr; /* Line 343, Address: 0x1025b3c */
    for (j = z12c_cnttbl[i]; j >= 0; --j) { /* Line 344, Address: 0x1025b40 */

      *pHScrollWork++ = wD1; /* Line 346, Address: 0x1025b54 */
    } /* Line 347, Address: 0x1025b60 */
  } /* Line 348, Address: 0x1025b70 */

  lD0.w.l = -scrz_h_posit.w.h; /* Line 350, Address: 0x1025b7c */
  for (i = 0; i < 6; ++i) { /* Line 351, Address: 0x1025b9c */

    *pHScrollWork++ = lD0.w.l; /* Line 353, Address: 0x1025ba8 */
  } /* Line 354, Address: 0x1025bb8 */

  lD0.w.l = -scrb_h_posit.w.h; /* Line 356, Address: 0x1025bc8 */
  for (i = 0; i < 2; ++i) { /* Line 357, Address: 0x1025be8 */

    *pHScrollWork++ = lD0.w.l; /* Line 359, Address: 0x1025bf4 */
  } /* Line 360, Address: 0x1025c04 */

  lD0.w.l = -scrc_h_posit.w.h; /* Line 362, Address: 0x1025c14 */
  for (i = 0; i < 8; ++i) { /* Line 363, Address: 0x1025c34 */

    *pHScrollWork++ = lD0.w.l; /* Line 365, Address: 0x1025c40 */
  } /* Line 366, Address: 0x1025c50 */

  pHScrollBuff = lphscrollbuff; /* Line 368, Address: 0x1025c60 */
  pHScrollWork = &hscrollwork[10]; /* Line 369, Address: 0x1025c6c */
  lD2.w.l = lD0.w.l = scrb_v_posit.w.h; /* Line 370, Address: 0x1025c74 */
  lD0.w.l = (unsigned short)(lD0.w.l & 504) >> 2; /* Line 371, Address: 0x1025c84 */
  lD3.w.l = lD0.w.l >> 1; /* Line 372, Address: 0x1025cac */
  wD1 = 31; /* Line 373, Address: 0x1025cc8 */
  lD5 = 28; /* Line 374, Address: 0x1025cd0 */
  if (wD1 >= (unsigned short)lD3.w.l) { /* Line 375, Address: 0x1025cd4 */
    wD1 -= lD3.w.l; /* Line 376, Address: 0x1025cf0 */

    if (wD1 >= 27) { /* Line 378, Address: 0x1025d00 */
      wD1 = 27; /* Line 379, Address: 0x1025d10 */
    }


    lD5 -= wD1; /* Line 383, Address: 0x1025d18 */
    pHScrollWork += lD0.w.l / 2; /* Line 384, Address: 0x1025d20 */

    temp = wD1; /* Line 386, Address: 0x1025d4c */
    if (temp == 27) /* Line 387, Address: 0x1025d50 */
      ++temp; /* Line 388, Address: 0x1025d60 */
    zonescrsetsub0(lD2.w.l, temp, &pHScrollBuff, pHScrollWork); /* Line 389, Address: 0x1025d68 */
  } else { /* Line 390, Address: 0x1025d84 */
    wD1 -= lD3.w.l; /* Line 391, Address: 0x1025d8c */
  }



  lD0.w.l = scrc_h_posit.w.h; /* Line 396, Address: 0x1025d9c */
  lD2.l = scra_h_posit.w.h - lD0.w.l; /* Line 397, Address: 0x1025da8 */
  lD2.l *= 256; /* Line 398, Address: 0x1025dcc */
  lD2.l /= 256; /* Line 399, Address: 0x1025dd8 */
  lD2.l *= 256; /* Line 400, Address: 0x1025df8 */
  lD3.l = (unsigned short)lD0.w.l; /* Line 401, Address: 0x1025e04 */
  wD1 = ((unsigned short)lD5 * 8 - 1); /* Line 402, Address: 0x1025e14 */

  do {
    lD0.w.l = -lD3.w.l; /* Line 405, Address: 0x1025e2c */
    pHScrollBuff->l = lD0.l; /* Line 406, Address: 0x1025e48 */
    ++pHScrollBuff; /* Line 407, Address: 0x1025e54 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 408, Address: 0x1025e60 */
    lD3.l += lD2.l; /* Line 409, Address: 0x1025e84 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 410, Address: 0x1025e94 */
  } while ((short)--wD1 >= 0); /* Line 411, Address: 0x1025eb8 */
} /* Line 412, Address: 0x1025edc */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 433, Address: 0x1025f10 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 437, Address: 0x1025f2c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 438, Address: 0x1025f30 */

  for (i = 0, j = yoffs & 7; yline >= i; ++i, j = 0) { /* Line 440, Address: 0x1025f50 */
    ldwk.w.l = *pHscrwk; /* Line 441, Address: 0x1025f6c */
    ++pHscrwk; /* Line 442, Address: 0x1025f78 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 444, Address: 0x1025f84 */
      (*pHscrbuf)->l = ldwk.l; /* Line 445, Address: 0x1025f8c */
    } /* Line 446, Address: 0x1025f9c */
  } /* Line 447, Address: 0x1025fc0 */
} /* Line 448, Address: 0x1025fe0 */





















static void scrollb_hv(int xOffs, int yOffs) { /* Line 470, Address: 0x1026000 */
  int lwk, lsv;
  int_union ldwk;

  lsv = scrb_h_posit.l; /* Line 474, Address: 0x1026014 */
  ldwk.l = scrb_h_posit.l = lwk = lsv + xOffs; /* Line 475, Address: 0x102601c */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_h_count) == 0) { /* Line 476, Address: 0x1026030 */
    scrb_h_count ^= 16; /* Line 477, Address: 0x1026060 */
    if (lwk - lsv < 0) { /* Line 478, Address: 0x1026074 */
      scrflagb.b.h |= 4; /* Line 479, Address: 0x1026080 */
    } /* Line 480, Address: 0x1026094 */
    else {
      scrflagb.b.h |= 8; /* Line 482, Address: 0x102609c */
    }
  }


  lsv = scrb_v_posit.l; /* Line 487, Address: 0x10260b0 */
  ldwk.l = scrb_v_posit.l = lwk = lsv + yOffs; /* Line 488, Address: 0x10260b8 */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_v_count) == 0) { /* Line 489, Address: 0x10260cc */
    scrb_v_count ^= 16; /* Line 490, Address: 0x10260fc */
    if (lwk - lsv < 0) { /* Line 491, Address: 0x1026110 */
      scrflagb.b.h |= 1; /* Line 492, Address: 0x102611c */
    } /* Line 493, Address: 0x1026130 */
    else {
      scrflagb.b.h |= 2; /* Line 495, Address: 0x1026138 */
    }
  }


} /* Line 500, Address: 0x102614c */


































































































































static void scrollc_h(int xoffs, int flgbit) { /* Line 631, Address: 0x1026160 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 635, Address: 0x1026174 */
  lXwk = lXsv + xoffs; /* Line 636, Address: 0x102617c */
  scrc_h_posit.l = lXwk; /* Line 637, Address: 0x1026184 */
  ldXwk.l = lXwk; /* Line 638, Address: 0x102618c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 639, Address: 0x1026190 */
  ldXwk.w.l &= 16; /* Line 640, Address: 0x10261b4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 641, Address: 0x10261c0 */

  if (!ldXwk.b.b4) { /* Line 643, Address: 0x10261dc */
    scrc_h_count ^= 16; /* Line 644, Address: 0x10261e8 */
    if (lXwk - lXsv < 0) { /* Line 645, Address: 0x10261fc */
      scrflagc.b.h |= 1 << flgbit; /* Line 646, Address: 0x1026208 */
    } /* Line 647, Address: 0x102622c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 649, Address: 0x1026234 */
    }
  }


} /* Line 654, Address: 0x102625c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 672, Address: 0x1026270 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 676, Address: 0x1026284 */
  lXwk = lXsv + xoffs; /* Line 677, Address: 0x102628c */
  scrz_h_posit.l = lXwk; /* Line 678, Address: 0x1026294 */
  ldXwk.l = lXwk; /* Line 679, Address: 0x102629c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 680, Address: 0x10262a0 */
  ldXwk.w.l &= 16; /* Line 681, Address: 0x10262c4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 682, Address: 0x10262d0 */

  if (!ldXwk.b.b4) { /* Line 684, Address: 0x10262ec */
    scrz_h_count ^= 16; /* Line 685, Address: 0x10262f8 */
    if (lXwk - lXsv < 0) { /* Line 686, Address: 0x102630c */
      scrflagz.b.h |= 1 << flgbit; /* Line 687, Address: 0x1026318 */
    } /* Line 688, Address: 0x102633c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 690, Address: 0x1026344 */
    }
  }


} /* Line 695, Address: 0x102636c */














static void scroll_h(void) { /* Line 710, Address: 0x1026380 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 714, Address: 0x1026390 */

  scrh_move(); /* Line 716, Address: 0x10263a0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 717, Address: 0x10263a8 */
  if (!bXwk) { /* Line 718, Address: 0x10263dc */
    scra_h_count ^= 16; /* Line 719, Address: 0x10263e4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 720, Address: 0x10263f8 */
      scrflaga.b.h |= 4; /* Line 721, Address: 0x102641c */
    } /* Line 722, Address: 0x1026430 */
    else scrflaga.b.h |= 8; /* Line 723, Address: 0x1026438 */
  }



} /* Line 728, Address: 0x102644c */
















static void scrh_move(void) { /* Line 745, Address: 0x1026470 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 748, Address: 0x1026478 */
  if (xwk == 0) { /* Line 749, Address: 0x10264c0 */

    scra_hz = 0; /* Line 751, Address: 0x10264d0 */
    return; /* Line 752, Address: 0x10264d8 */
  } else if (xwk < 0) { /* Line 753, Address: 0x10264e0 */

    if (xwk < -16) { /* Line 755, Address: 0x10264f0 */
      xwk = -16; /* Line 756, Address: 0x1026504 */
    }


    xwk += scra_h_posit.w.h; /* Line 760, Address: 0x1026510 */
    if (xwk < scralim_left) { /* Line 761, Address: 0x1026524 */
      xwk = scralim_left; /* Line 762, Address: 0x1026548 */
    }
  } /* Line 764, Address: 0x1026558 */
  else {
    if (xwk > 16) { /* Line 766, Address: 0x1026560 */
      xwk = 16; /* Line 767, Address: 0x1026574 */
    }


    xwk += scra_h_posit.w.h; /* Line 771, Address: 0x1026580 */
    if (xwk > scralim_right) { /* Line 772, Address: 0x1026594 */
      xwk = scralim_right; /* Line 773, Address: 0x10265b8 */
    }
  }


  scra_hz = xwk - scra_h_posit.w.h << 8; /* Line 778, Address: 0x10265c8 */
  scra_h_posit.w.h = xwk; /* Line 779, Address: 0x10265f8 */
} /* Line 780, Address: 0x1026600 */














static void scroll_v(void) { /* Line 795, Address: 0x1026610 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 798, Address: 0x102661c */
  if (actwk[0].cddat & 4) { /* Line 799, Address: 0x1026650 */
    ywk -= 5; /* Line 800, Address: 0x1026668 */
  }


  if (actwk[0].cddat & 2) { /* Line 804, Address: 0x1026674 */
    ywk += 32; /* Line 805, Address: 0x102668c */
    if (ywk < scra_vline) { /* Line 806, Address: 0x1026698 */
      ywk -= scra_vline; /* Line 807, Address: 0x10266bc */
      sv_move_main2(ywk); /* Line 808, Address: 0x10266d0 */
      return; /* Line 809, Address: 0x10266dc */
    } else if (ywk >= scra_vline + 64) { /* Line 810, Address: 0x10266e4 */
      ywk -= scra_vline + 64; /* Line 811, Address: 0x102670c */
      sv_move_main2(ywk); /* Line 812, Address: 0x1026734 */
      return; /* Line 813, Address: 0x1026740 */
    }
    ywk -= scra_vline + 64; /* Line 815, Address: 0x1026748 */
    if (!limmoveflag) goto label1; /* Line 816, Address: 0x1026770 */
    sv_move_sub2(); /* Line 817, Address: 0x1026780 */
    return; /* Line 818, Address: 0x1026788 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 823, Address: 0x1026790 */
    sv_move_main(ywk); /* Line 824, Address: 0x10267bc */
    return; /* Line 825, Address: 0x10267c8 */
  } else if (limmoveflag) { /* Line 826, Address: 0x10267d0 */
    sv_move_sub2(); /* Line 827, Address: 0x10267e0 */
    return; /* Line 828, Address: 0x10267e8 */
  }


label1:
  scra_vz = 0; /* Line 833, Address: 0x10267f0 */
} /* Line 834, Address: 0x10267f8 */













static void sv_move_main(short yPos) { /* Line 848, Address: 0x1026810 */
  short spdwk;

  if (scra_vline == 96) { /* Line 851, Address: 0x1026820 */
    if (actwk[0].mspeed.w < 0) { /* Line 852, Address: 0x102683c */
      spdwk = -actwk[0].mspeed.w; /* Line 853, Address: 0x1026854 */
    } else { /* Line 854, Address: 0x1026878 */
      spdwk = actwk[0].mspeed.w; /* Line 855, Address: 0x1026880 */
    }


    if (spdwk >= 2048) { /* Line 859, Address: 0x1026890 */
      sv_move_main2(yPos); /* Line 860, Address: 0x10268a4 */
    } /* Line 861, Address: 0x10268b0 */
    else {

      if (yPos > 6) { /* Line 864, Address: 0x10268b8 */
        sv_move_plus(1536); /* Line 865, Address: 0x10268d0 */
      } else if (yPos < -6) { /* Line 866, Address: 0x10268dc */
        sv_move_minus(1536); /* Line 867, Address: 0x10268fc */
      } else /* Line 868, Address: 0x1026908 */
        sv_move_sub(yPos); /* Line 869, Address: 0x1026910 */
    }
  } /* Line 871, Address: 0x102691c */
  else {
    if (yPos > 2) { /* Line 873, Address: 0x1026924 */
      sv_move_plus(512); /* Line 874, Address: 0x102693c */
    } else if (yPos < -2) { /* Line 875, Address: 0x1026948 */
      sv_move_minus(512); /* Line 876, Address: 0x1026968 */
    } else { /* Line 877, Address: 0x1026974 */
      sv_move_sub(yPos); /* Line 878, Address: 0x102697c */
    }
  }
} /* Line 881, Address: 0x1026988 */













static void sv_move_main2(short yPos) { /* Line 895, Address: 0x10269a0 */
  short spdwk;

  spdwk = 4096; /* Line 898, Address: 0x10269b0 */

  if (yPos > 16) { /* Line 900, Address: 0x10269bc */
    sv_move_plus(spdwk); /* Line 901, Address: 0x10269d4 */
  } else if (yPos < -16) { /* Line 902, Address: 0x10269e0 */
    sv_move_minus(spdwk); /* Line 903, Address: 0x1026a00 */
  } else { /* Line 904, Address: 0x1026a0c */
    sv_move_sub(yPos); /* Line 905, Address: 0x1026a14 */
  }
} /* Line 907, Address: 0x1026a20 */














static void sv_move_sub(short yPos) { /* Line 922, Address: 0x1026a40 */
  int_union lSpd;

  lSpd.l = 0; /* Line 925, Address: 0x1026a4c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 926, Address: 0x1026a50 */
  if (yPos < 0) { /* Line 927, Address: 0x1026a7c */
    scrv_up_ch(lSpd); /* Line 928, Address: 0x1026a90 */
  } else { /* Line 929, Address: 0x1026a9c */
    scrv_down_ch(lSpd); /* Line 930, Address: 0x1026aa4 */
  }
} /* Line 932, Address: 0x1026ab0 */



static void sv_move_sub2(void) { /* Line 936, Address: 0x1026ac0 */
  limmoveflag = 0; /* Line 937, Address: 0x1026ac8 */

  sv_move_sub(0); /* Line 939, Address: 0x1026ad0 */
} /* Line 940, Address: 0x1026adc */













static void sv_move_minus(short speed) { /* Line 954, Address: 0x1026af0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 957, Address: 0x1026afc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 958, Address: 0x1026b20 */
  scrv_up_ch(lSpd); /* Line 959, Address: 0x1026b44 */
} /* Line 960, Address: 0x1026b50 */














static void scrv_up_ch(int_union lSpd) { /* Line 975, Address: 0x1026b60 */
  if (lSpd.w.l <= scralim_up) { /* Line 976, Address: 0x1026b6c */
    if (lSpd.w.l > -256) { /* Line 977, Address: 0x1026b94 */

      lSpd.w.l = scralim_up; /* Line 979, Address: 0x1026bac */
    } else { /* Line 980, Address: 0x1026bb8 */
      lSpd.w.l &= 2047; /* Line 981, Address: 0x1026bc0 */
      actwk[0].yposi.w.h &= 2047; /* Line 982, Address: 0x1026bcc */
      scra_v_posit.w.h &= 2047; /* Line 983, Address: 0x1026be0 */
      scrb_v_posit.w.h &= 1023; /* Line 984, Address: 0x1026bf4 */
    }
  }

  scrv_move(lSpd); /* Line 988, Address: 0x1026c08 */
} /* Line 989, Address: 0x1026c14 */













static void sv_move_plus(short sSpd) { /* Line 1003, Address: 0x1026c30 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1006, Address: 0x1026c3c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1007, Address: 0x1026c5c */
  scrv_down_ch(lSpd); /* Line 1008, Address: 0x1026c80 */
} /* Line 1009, Address: 0x1026c8c */














static void scrv_down_ch(int_union lSpd) { /* Line 1024, Address: 0x1026ca0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1025, Address: 0x1026cac */
    if (lSpd.w.l < 2048) { /* Line 1026, Address: 0x1026cd4 */

      lSpd.w.l = scralim_down; /* Line 1028, Address: 0x1026cec */
    } else { /* Line 1029, Address: 0x1026cf8 */
      lSpd.w.l -= 2048; /* Line 1030, Address: 0x1026d00 */
      actwk[0].yposi.w.h &= 2047; /* Line 1031, Address: 0x1026d0c */
      scra_v_posit.w.h -= 2048; /* Line 1032, Address: 0x1026d20 */
      scrb_v_posit.w.h &= 1023; /* Line 1033, Address: 0x1026d34 */
    }
  }

  scrv_move(lSpd); /* Line 1037, Address: 0x1026d48 */
} /* Line 1038, Address: 0x1026d54 */
















static void scrv_move(int_union lSpd) { /* Line 1055, Address: 0x1026d70 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1059, Address: 0x1026d80 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1060, Address: 0x1026d90 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1061, Address: 0x1026db4 */
  spdwk.l = (spdwk.l >> 8) | (spdwk.l << 24); /* Line 1062, Address: 0x1026dc8 */
  scra_vz = spdwk.w.l; /* Line 1063, Address: 0x1026de0 */

  scra_v_posit.l = lSpd.l; /* Line 1065, Address: 0x1026dec */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1067, Address: 0x1026df8 */
  if (!ywk) { /* Line 1068, Address: 0x1026e34 */
    scra_v_count ^= 16; /* Line 1069, Address: 0x1026e3c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1070, Address: 0x1026e50 */
    if (ywk < 0) { /* Line 1071, Address: 0x1026e7c */
      scrflaga.b.h |= 1; /* Line 1072, Address: 0x1026e8c */
    } else { /* Line 1073, Address: 0x1026ea0 */
      scrflaga.b.h |= 2; /* Line 1074, Address: 0x1026ea8 */
    }
  }


} /* Line 1079, Address: 0x1026ebc */







































void scrollwrt(void) { /* Line 1119, Address: 0x1026ed0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  pScrFlag = &scrflagbw.b.h; /* Line 1128, Address: 0x1026ef0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1129, Address: 0x1026ef8 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1130, Address: 0x1026f04 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1131, Address: 0x1026f10 */
  VramBase = 24576; /* Line 1132, Address: 0x1026f18 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1133, Address: 0x1026f1c */











  pScrFlag = &scrflagaw.b.h; /* Line 1145, Address: 0x1026f30 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1146, Address: 0x1026f38 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1147, Address: 0x1026f44 */
  pMapWk = (unsigned char*)mapwka; /* Line 1148, Address: 0x1026f50 */
  VramBase = 16384; /* Line 1149, Address: 0x1026f58 */

  if (*pScrFlag) { /* Line 1151, Address: 0x1026f5c */
    if (*pScrFlag & 1) { /* Line 1152, Address: 0x1026f68 */
      *pScrFlag &= 254; /* Line 1153, Address: 0x1026f7c */

      lD4.l = -16; /* Line 1155, Address: 0x1026f88 */
      wD5 = 65520; /* Line 1156, Address: 0x1026f90 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1157, Address: 0x1026f98 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1158, Address: 0x1026fb8 */
    }
    if (*pScrFlag & 2) { /* Line 1160, Address: 0x1026fe4 */
      *pScrFlag &= 253; /* Line 1161, Address: 0x1026ff8 */

      lD4.l = 224; /* Line 1163, Address: 0x1027004 */
      wD5 = 65520; /* Line 1164, Address: 0x102700c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1165, Address: 0x1027014 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1166, Address: 0x1027034 */
    }
    if (*pScrFlag & 4) { /* Line 1168, Address: 0x1027060 */
      *pScrFlag &= 251; /* Line 1169, Address: 0x1027074 */

      lD4.l = -16; /* Line 1171, Address: 0x1027080 */
      wD5 = 65520; /* Line 1172, Address: 0x1027088 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1173, Address: 0x1027090 */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1174, Address: 0x10270b0 */
    }
    if (*pScrFlag & 8) { /* Line 1176, Address: 0x10270dc */
      *pScrFlag &= 247; /* Line 1177, Address: 0x10270f0 */

      lD4.l = -16; /* Line 1179, Address: 0x10270fc */
      wD5 = 320; /* Line 1180, Address: 0x1027104 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1181, Address: 0x102710c */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1182, Address: 0x102712c */
    }
  }
} /* Line 1185, Address: 0x1027158 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1199, Address: 0x1027180 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1210, Address: 0x10271ac */

  if (*pScrFlag & 1) { /* Line 1212, Address: 0x10271b4 */
    *pScrFlag &= 254; /* Line 1213, Address: 0x10271cc */
  } /* Line 1214, Address: 0x10271e0 */
  else {
    *pScrFlag &= 254; /* Line 1216, Address: 0x10271e8 */

    if (*pScrFlag & 2) { /* Line 1218, Address: 0x10271fc */
      *pScrFlag &= 253; /* Line 1219, Address: 0x1027214 */
      lD4.w.l = 224; /* Line 1220, Address: 0x1027228 */
    } /* Line 1221, Address: 0x1027230 */
    else {
      *pScrFlag &= 253; /* Line 1223, Address: 0x1027238 */
      goto label1; /* Line 1224, Address: 0x102724c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1229, Address: 0x1027254 */
  wD0 &= 127; /* Line 1230, Address: 0x10272a4 */
  wD0 = z12cwrttbl[wD0 + 1]; /* Line 1231, Address: 0x10272ac */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1232, Address: 0x10272cc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1233, Address: 0x10272ec */
  if (wD0 != 0) { /* Line 1234, Address: 0x1027310 */
    wD5 = 65520; /* Line 1235, Address: 0x102731c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1236, Address: 0x1027324 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1238, Address: 0x1027344 */



  } /* Line 1242, Address: 0x1027370 */
  else {

    wD5 = 0; /* Line 1245, Address: 0x1027378 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1246, Address: 0x102737c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1250, Address: 0x102739c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1257, Address: 0x10273c8 */






    lD4.l = -16; /* Line 1264, Address: 0x10273dc */
    wD5 = 65520; /* Line 1265, Address: 0x10273e4 */
    if (*pScrFlag & 168) { /* Line 1266, Address: 0x10273ec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1267, Address: 0x1027404 */
      wD5 = 320; /* Line 1268, Address: 0x1027424 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1272, Address: 0x102742c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1274, Address: 0x102745c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1275, Address: 0x1027468 */



    for (i = 0; i < 16; ++i) { /* Line 1279, Address: 0x1027478 */
      wD0 = z12cwrttbl[WrtTblCnt++]; /* Line 1280, Address: 0x1027484 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1281, Address: 0x10274a4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1282, Address: 0x10274d0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1283, Address: 0x10274f0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1285, Address: 0x1027514 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1288, Address: 0x1027538 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1290, Address: 0x1027558 */
      }
      lD4.w.l += 16; /* Line 1292, Address: 0x102756c */
    } /* Line 1293, Address: 0x1027578 */
    *pScrFlag = 0; /* Line 1294, Address: 0x1027588 */
  }
} /* Line 1296, Address: 0x1027590 */


























void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1323, Address: 0x10275c0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1336, Address: 0x10275e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1339, Address: 0x1027608 */
    pTilePoint->x += 2; /* Line 1340, Address: 0x102761c */
    if (pTilePoint->x >= 64) { /* Line 1341, Address: 0x1027630 */
      pTilePoint->x -= 64; /* Line 1342, Address: 0x1027644 */
    }
    xOffs += 16; /* Line 1344, Address: 0x1027658 */
  } while (--lpcnt >= 0); /* Line 1345, Address: 0x1027664 */
} /* Line 1346, Address: 0x1027678 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1350, Address: 0x1027690 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1354, Address: 0x10276b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1357, Address: 0x10276d8 */
    pTilePoint->x += 2; /* Line 1358, Address: 0x10276ec */
    if (pTilePoint->x >= 64) { /* Line 1359, Address: 0x1027700 */
      pTilePoint->x -= 64; /* Line 1360, Address: 0x1027714 */
    }
    xOffs += 16; /* Line 1362, Address: 0x1027728 */
  } while (--lpcnt >= 0); /* Line 1363, Address: 0x1027734 */
} /* Line 1364, Address: 0x1027748 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1380, Address: 0x1027760 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1384, Address: 0x1027788 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1385, Address: 0x10277a8 */
    pTilePoint->y += 2; /* Line 1386, Address: 0x10277bc */
    if (pTilePoint->y >= 32) pTilePoint->y -= 32; /* Line 1387, Address: 0x10277cc */
    yOffs += 16; /* Line 1388, Address: 0x10277f0 */
  } while (--lpcnt >= 0); /* Line 1389, Address: 0x10277fc */
} /* Line 1390, Address: 0x1027810 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1408, Address: 0x1027820 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) base = 1; /* Line 1414, Address: 0x1027854 */
  else if (VramBase == 16384) base = 0; /* Line 1415, Address: 0x1027870 */
  x = pTilePoint->x; /* Line 1416, Address: 0x1027884 */
  y = pTilePoint->y; /* Line 1417, Address: 0x102788c */

  frip = BlkIndex & 6144; /* Line 1419, Address: 0x1027894 */
  BlkIndex &= 1023; /* Line 1420, Address: 0x102789c */
  if (frip == 6144) { /* Line 1421, Address: 0x10278a8 */
    p0 = 3; /* Line 1422, Address: 0x10278b4 */
    p1 = 2; /* Line 1423, Address: 0x10278b8 */
    p2 = 1; /* Line 1424, Address: 0x10278bc */
    p3 = 0; /* Line 1425, Address: 0x10278c0 */
  } /* Line 1426, Address: 0x10278c4 */
  else if (frip & 4096) { /* Line 1427, Address: 0x10278cc */
    p0 = 2; /* Line 1428, Address: 0x10278d8 */
    p1 = 3; /* Line 1429, Address: 0x10278dc */
    p2 = 0; /* Line 1430, Address: 0x10278e0 */
    p3 = 1; /* Line 1431, Address: 0x10278e4 */
  } /* Line 1432, Address: 0x10278e8 */
  else if (frip & 2048) { /* Line 1433, Address: 0x10278f0 */
    p0 = 1; /* Line 1434, Address: 0x10278fc */
    p1 = 0; /* Line 1435, Address: 0x1027900 */
    p2 = 3; /* Line 1436, Address: 0x1027904 */
    p3 = 2; /* Line 1437, Address: 0x1027908 */
  } /* Line 1438, Address: 0x102790c */
  else {
    p0 = 0; /* Line 1440, Address: 0x1027914 */
    p1 = 1; /* Line 1441, Address: 0x1027918 */
    p2 = 2; /* Line 1442, Address: 0x102791c */
    p3 = 3; /* Line 1443, Address: 0x1027920 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1446, Address: 0x1027924 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1447, Address: 0x1027968 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1448, Address: 0x10279ac */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1449, Address: 0x10279f0 */
} /* Line 1450, Address: 0x1027a34 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1469, Address: 0x1027a70 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1470, Address: 0x1027a90 */
} /* Line 1471, Address: 0x1027ab0 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1474, Address: 0x1027ac0 */
  wH_posiw = 0; /* Line 1475, Address: 0x1027ae0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1476, Address: 0x1027ae4 */
} /* Line 1477, Address: 0x1027b04 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1480, Address: 0x1027b20 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1486, Address: 0x1027b50 */
  yOffs += wV_posiw; /* Line 1487, Address: 0x1027b60 */


  if ((short)xOffs < 0) xOffs = 0; /* Line 1490, Address: 0x1027b70 */
  if ((short)yOffs < 0) yOffs = 0; /* Line 1491, Address: 0x1027b90 */
  if ((short)xOffs >= 16384) xOffs = 16383; /* Line 1492, Address: 0x1027bb0 */
  if ((short)yOffs >= 2048) yOffs = 2047; /* Line 1493, Address: 0x1027bd8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1494, Address: 0x1027c00 */
  if (i < 0) i = 0; /* Line 1495, Address: 0x1027c48 */

  ScreenNo = pMapWk[i] & 127; /* Line 1497, Address: 0x1027c54 */

  if (ScreenNo) { /* Line 1499, Address: 0x1027c70 */
    xOffs &= 32767; /* Line 1500, Address: 0x1027c78 */
    yOffs &= 32767; /* Line 1501, Address: 0x1027c84 */

    xBlk = xOffs; /* Line 1503, Address: 0x1027c90 */
    xBlk %= 256; /* Line 1504, Address: 0x1027c98 */
    xBlk /= 16; /* Line 1505, Address: 0x1027cb8 */
    yBlk = yOffs; /* Line 1506, Address: 0x1027cd4 */
    yBlk %= 256; /* Line 1507, Address: 0x1027cdc */
    yBlk /= 16; /* Line 1508, Address: 0x1027cfc */

    lpw = pmapwk; /* Line 1510, Address: 0x1027d18 */
    lpw += xBlk; /* Line 1511, Address: 0x1027d20 */
    lpw += yBlk * 16; /* Line 1512, Address: 0x1027d28 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1513, Address: 0x1027d34 */
    *pIndex = *lpw; /* Line 1514, Address: 0x1027d4c */

    return 1; /* Line 1516, Address: 0x1027d5c */
  }
  *pIndex = 0; /* Line 1518, Address: 0x1027d68 */
  return 0; /* Line 1519, Address: 0x1027d70 */
} /* Line 1520, Address: 0x1027d74 */















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1536, Address: 0x1027da0 */
  int xBlk, yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;

  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1541, Address: 0x1027dc8 */
  if (ScreenNo) { /* Line 1542, Address: 0x1027e2c */
    xBlk = xOffs; /* Line 1543, Address: 0x1027e34 */
    xBlk %= 256; /* Line 1544, Address: 0x1027e3c */
    xBlk /= 16; /* Line 1545, Address: 0x1027e5c */
    yBlk = yOffs; /* Line 1546, Address: 0x1027e78 */
    yBlk %= 256; /* Line 1547, Address: 0x1027e80 */
    yBlk /= 16; /* Line 1548, Address: 0x1027ea0 */

    lpw = pmapwk; /* Line 1550, Address: 0x1027ebc */
    lpw += xBlk; /* Line 1551, Address: 0x1027ec4 */
    lpw += yBlk * 16; /* Line 1552, Address: 0x1027ecc */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1553, Address: 0x1027ed8 */
    *ppBlockNo = lpw; /* Line 1554, Address: 0x1027ef0 */
    *pIndex = *lpw; /* Line 1555, Address: 0x1027ef8 */

    return 1; /* Line 1557, Address: 0x1027f08 */
  }
  *pIndex = 0; /* Line 1559, Address: 0x1027f14 */
  return 0; /* Line 1560, Address: 0x1027f1c */
} /* Line 1561, Address: 0x1027f20 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1575, Address: 0x1027f40 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1582, Address: 0x1027f5c */
  pMapWk = (unsigned char*)mapwka; /* Line 1583, Address: 0x1027f60 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1584, Address: 0x1027f68 */
    *pBlockIndex = BlockNo; /* Line 1585, Address: 0x1027f8c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1586, Address: 0x1027f98 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1587, Address: 0x1027fb0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1588, Address: 0x1027fc4 */
    }
  }
} /* Line 1591, Address: 0x1027fdc */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1603, Address: 0x1028000 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1604, Address: 0x102800c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1605, Address: 0x1028038 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1606, Address: 0x1028084 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) return 0; /* Line 1607, Address: 0x10280b0 */
      }
    }
  }
  return 1; /* Line 1611, Address: 0x1028108 */
} /* Line 1612, Address: 0x102810c */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1627, Address: 0x1028120 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1628, Address: 0x102813c */
} /* Line 1629, Address: 0x1028158 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1632, Address: 0x1028170 */
  wH_posiw = 0; /* Line 1633, Address: 0x102818c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1634, Address: 0x1028190 */
} /* Line 1635, Address: 0x10281ac */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1638, Address: 0x10281c0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1639, Address: 0x10281d4 */
} /* Line 1640, Address: 0x10281f0 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1643, Address: 0x1028200 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1644, Address: 0x102821c */
} /* Line 1645, Address: 0x1028238 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1648, Address: 0x1028250 */
  xOffs += wH_posiw; /* Line 1649, Address: 0x1028268 */
  yOffs += wV_posiw; /* Line 1650, Address: 0x1028278 */
  yOffs &= 240; /* Line 1651, Address: 0x1028288 */
  xOffs &= 496; /* Line 1652, Address: 0x1028294 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1654, Address: 0x10282a0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1655, Address: 0x10282cc */

} /* Line 1657, Address: 0x10282f8 */













void mapwrt(void) { /* Line 1671, Address: 0x1028310 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1676, Address: 0x1028328 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1677, Address: 0x1028334 */
  pMapWk = (unsigned char*)mapwka; /* Line 1678, Address: 0x1028340 */
  VramBase = 16384; /* Line 1679, Address: 0x1028348 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1680, Address: 0x102834c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1684, Address: 0x1028364 */
  VramBase = 24576; /* Line 1685, Address: 0x102836c */
  mapwrt_z11c(pMapWk, VramBase); /* Line 1686, Address: 0x1028370 */
} /* Line 1687, Address: 0x1028380 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1690, Address: 0x10283a0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1691, Address: 0x10283b8 */
} /* Line 1692, Address: 0x10283d8 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1695, Address: 0x10283f0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1699, Address: 0x1028410 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1700, Address: 0x102842c */
    wD4 += 16; /* Line 1701, Address: 0x1028454 */
  } while ((short)--wD6 >= 0); /* Line 1702, Address: 0x1028460 */
} /* Line 1703, Address: 0x1028488 */


void mapwrt_z11c(unsigned char* pMapWk, int VramBase) { /* Line 1706, Address: 0x10284a0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1709, Address: 0x10284bc */
  wD6 = 15; /* Line 1710, Address: 0x10284c4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1713, Address: 0x10284cc */
    mapwrt_sub(&z12cwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1714, Address: 0x10284f0 */
    wD4 += 16; /* Line 1715, Address: 0x1028510 */
  } while ((short)--wD6 >= 0); /* Line 1716, Address: 0x1028518 */
} /* Line 1717, Address: 0x102853c */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1733, Address: 0x1028560 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1738, Address: 0x1028588 */
  wD0 = pWrttbl[wD0]; /* Line 1739, Address: 0x1028598 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1740, Address: 0x10285b4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1741, Address: 0x10285d8 */
  if (wD0) { /* Line 1742, Address: 0x1028600 */
    wD5 = 65520; /* Line 1743, Address: 0x102860c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1744, Address: 0x1028614 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1745, Address: 0x1028630 */
  } /* Line 1746, Address: 0x1028658 */
  else {
    wD5 = 0; /* Line 1748, Address: 0x1028660 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1749, Address: 0x1028664 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1750, Address: 0x1028680 */
  }
} /* Line 1752, Address: 0x10286a8 */










void mapinit(void) { /* Line 1763, Address: 0x10286d0 */

  colorset2(mapinittbl.colorno2); /* Line 1765, Address: 0x10286d8 */
  colorset(mapinittbl.colorno2); /* Line 1766, Address: 0x10286ec */

  if (plflag) enecginit(); /* Line 1768, Address: 0x1028700 */
  if (play_start & 2) divdevset(); /* Line 1769, Address: 0x1028718 */
} /* Line 1770, Address: 0x1028738 */
