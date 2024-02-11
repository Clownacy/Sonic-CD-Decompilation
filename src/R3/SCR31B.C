#include "..\EQU.H"
#include "SCR31A.H"

static unsigned char z31bwrttbl[49] = {
  0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 2, 2, 2, 2, 6, 6,
  4, 4, 4, 4, 2, 2, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0
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
extern unsigned char awasintbl[];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;












































































void enecginit() {} /* Line 112, Address: 0x1026c40 */



void divdevset() {} /* Line 116, Address: 0x1026c50 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 170, Address: 0x1026c60 */
    return &actwk[0]; /* Line 171, Address: 0x1026c74 */
  }
  return &actwk[1]; /* Line 173, Address: 0x1026c84 */
} /* Line 174, Address: 0x1026c8c */












void scr_set() { /* Line 187, Address: 0x1026ca0 */





  unsigned short scr_dir_tbl[6] = { /* Line 193, Address: 0x1026cac */
    4, 0, 11927, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1026ce0 */

  i = 0; /* Line 200, Address: 0x1026d28 */
  scrar_no = scr_dir_tbl[i++]; /* Line 201, Address: 0x1026d2c */
  scralim_left = scr_dir_tbl[i]; /* Line 202, Address: 0x1026d48 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 203, Address: 0x1026d5c */
  scralim_right = scr_dir_tbl[i]; /* Line 204, Address: 0x1026d78 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 205, Address: 0x1026d8c */
  scralim_up = scr_dir_tbl[i]; /* Line 206, Address: 0x1026da8 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 207, Address: 0x1026dbc */
  scralim_down = scr_dir_tbl[i]; /* Line 208, Address: 0x1026dd8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 209, Address: 0x1026dec */

  scra_h_keep = scralim_left + 576; /* Line 211, Address: 0x1026e08 */
  scra_h_count = 16; /* Line 212, Address: 0x1026e2c */
  scra_v_count = 16; /* Line 213, Address: 0x1026e38 */

  scra_vline = scr_dir_tbl[i++]; /* Line 215, Address: 0x1026e44 */
  scra_hline = 160; /* Line 216, Address: 0x1026e60 */

  playposiset(); /* Line 218, Address: 0x1026e6c */
} /* Line 219, Address: 0x1026e74 */











void playposiset() { /* Line 231, Address: 0x1026e90 */
  unsigned short playpositbl[2] = { /* Line 232, Address: 0x1026ea8 */
    96,
    1004
  };
  unsigned short endplpositbl[16] = { /* Line 236, Address: 0x1026ec4 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 246, Address: 0x1026ef8 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 256, Address: 0x1026f24 */
    playload(); /* Line 257, Address: 0x1026f38 */
    xWk = actwk[0].xposi.w.h; /* Line 258, Address: 0x1026f40 */
    yWk = actwk[0].yposi.w.h; /* Line 259, Address: 0x1026f50 */

    if (yWk < 0) yWk = 0; /* Line 261, Address: 0x1026f60 */

  } /* Line 263, Address: 0x1026f74 */
  else {

    if (demoflag.w < 0) { /* Line 266, Address: 0x1026f7c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 267, Address: 0x1026f94 */
    } /* Line 268, Address: 0x1026fbc */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 271, Address: 0x1026fc4 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 274, Address: 0x1026fe4 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 275, Address: 0x1027000 */
  }


  if ((unsigned short)xWk >= 161) { /* Line 279, Address: 0x1027014 */
    xWk -= 160; /* Line 280, Address: 0x1027028 */
  } /* Line 281, Address: 0x1027034 */
  else {
    xWk = 0; /* Line 283, Address: 0x102703c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 287, Address: 0x1027040 */
    xWk = scralim_right; /* Line 288, Address: 0x1027064 */
  }
  scra_h_posit.w.h = xWk; /* Line 290, Address: 0x1027074 */

  if ((unsigned short)yWk >= 97) { /* Line 292, Address: 0x102707c */
    yWk -= 96; /* Line 293, Address: 0x1027090 */
  } /* Line 294, Address: 0x102709c */
  else {
    yWk = 0; /* Line 296, Address: 0x10270a4 */
  }

  if (scralim_down < yWk) { /* Line 299, Address: 0x10270a8 */
    yWk = scralim_down; /* Line 300, Address: 0x10270cc */
  }

  scra_v_posit.w.h = yWk; /* Line 303, Address: 0x10270dc */

  scrbinit(xWk, yWk); /* Line 305, Address: 0x10270e4 */

  i = 0; /* Line 307, Address: 0x10270f4 */
  loopmapno = playmapnotbl[i++]; /* Line 308, Address: 0x10270f8 */
  loopmapno2 = playmapnotbl[i++]; /* Line 309, Address: 0x1027110 */
  ballmapno = playmapnotbl[i++]; /* Line 310, Address: 0x1027128 */
  ballmapno2 = playmapnotbl[i++]; /* Line 311, Address: 0x1027140 */


} /* Line 314, Address: 0x1027158 */











void scrbinit(short xWk, short yWk) { /* Line 326, Address: 0x1027180 */
  int i;
  short wD2;


  yWk = 536; /* Line 331, Address: 0x1027194 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 332, Address: 0x102719c */
  if ((unsigned short)scra_v_posit.w.h < 1313) { /* Line 333, Address: 0x10271c4 */
    yWk -= wD2 / 2; /* Line 334, Address: 0x10271e0 */
    if (yWk < 0) { /* Line 335, Address: 0x1027214 */
      yWk = 0; /* Line 336, Address: 0x1027228 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 340, Address: 0x102722c */
  scrb_v_posit.w.l = 0; /* Line 341, Address: 0x1027238 */
  scrc_v_posit.w.h = yWk; /* Line 342, Address: 0x1027240 */
  scrz_v_posit.w.h = yWk; /* Line 343, Address: 0x102724c */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 345, Address: 0x1027258 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 346, Address: 0x1027290 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 347, Address: 0x10272d0 */


  for (i = 0; i < 13; ++i) { /* Line 350, Address: 0x1027310 */
    ((int*)hscrollwork)[i] = 0; /* Line 351, Address: 0x102731c */
  } /* Line 352, Address: 0x1027330 */

} /* Line 354, Address: 0x1027340 */












void scroll() { /* Line 367, Address: 0x1027360 */
  int LineSpdTbl[13] = { /* Line 368, Address: 0x1027380 */
    32768, 24576, 16384,
    12288,  8192,  4096,
     2048,  4096,  8192,
    12288, 16384, 24576,
    32768
  };
  unsigned char z31b_cnttbl[13] = { /* Line 375, Address: 0x10273ac */
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1
  };
  unsigned char z31b_cnttbl0[3] = { /* Line 378, Address: 0x10273d8 */
    3, 1, 1
  };
  unsigned char z31b_cnttbl1[6] = { /* Line 381, Address: 0x10273fc */
    5, 1, 1,
    3, 1, 1
  };
  unsigned short z31b_kawatbl[3] = { /* Line 385, Address: 0x1027430 */
    64, 528, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 395, Address: 0x1027454 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 398, Address: 0x1027464 */
  scrchk(); /* Line 399, Address: 0x1027490 */
  scroll_h(); /* Line 400, Address: 0x102749c */
  scroll_v(); /* Line 401, Address: 0x10274a8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 403, Address: 0x10274b4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 404, Address: 0x10274c4 */


  scrollz_h(scra_hz * 16, 64); /* Line 407, Address: 0x10274d4 */
  scrollc_h(scra_hz * 8 * 3, 16); /* Line 408, Address: 0x10274f8 */
  scrollb_h(scra_hz * 4 * 3, 4); /* Line 409, Address: 0x1027534 */

  lD0.w.l = 536; /* Line 411, Address: 0x1027570 */
  wD1 = 1312; /* Line 412, Address: 0x1027578 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 413, Address: 0x1027580 */

    wD1 -= scra_v_posit.w.h; /* Line 415, Address: 0x10275a0 */
    wD1 >>= 1; /* Line 416, Address: 0x10275b4 */
    lD0.w.l -= wD1; /* Line 417, Address: 0x10275bc */
    if (lD0.w.l < 0) { /* Line 418, Address: 0x10275d0 */
      lD0.w.l = 0; /* Line 419, Address: 0x10275e4 */
    }
  } /* Line 421, Address: 0x10275e8 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 423, Address: 0x10275f0 */
  }

  scrollb_v(lD0.w.l); /* Line 426, Address: 0x1027604 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 427, Address: 0x1027618 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 428, Address: 0x1027628 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 429, Address: 0x1027638 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 431, Address: 0x1027648 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 432, Address: 0x1027664 */
  scrflagz.b.h = 0; /* Line 433, Address: 0x1027680 */
  scrflagc.b.h = 0; /* Line 434, Address: 0x1027688 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 457, Address: 0x1027690 */
  for (i = 0; i < 13; ++i) { /* Line 458, Address: 0x1027698 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 459, Address: 0x10276a4 */
    ++pHscrWk; /* Line 460, Address: 0x10276bc */
  } /* Line 461, Address: 0x10276c0 */
  wD1 = 0; /* Line 462, Address: 0x10276d0 */
  for ( ; i < 77; ++i) { /* Line 463, Address: 0x10276d4 */
    lD2.l = (wD1 << 8) + 32767 + 1; /* Line 464, Address: 0x10276dc */
    pHscrWk->l += lD2.l; /* Line 465, Address: 0x1027700 */
    ++pHscrWk; /* Line 466, Address: 0x1027710 */
    ++wD1; /* Line 467, Address: 0x1027714 */
  } /* Line 468, Address: 0x1027720 */






  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 475, Address: 0x1027730 */
  lD2.l <<= 5; /* Line 476, Address: 0x1027758 */
  lD2.l /= 12; /* Line 477, Address: 0x1027764 */
  lD2.l <<= 11; /* Line 478, Address: 0x1027784 */

  lD3.l = 0; /* Line 480, Address: 0x1027790 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 481, Address: 0x1027794 */

  pHScrollWork = &hscrollwork[161]; /* Line 483, Address: 0x10277a0 */
  for (i = 2; i >= 0; --i) { /* Line 484, Address: 0x10277ac */
    lD0.w.l = -lD3.w.l; /* Line 485, Address: 0x10277b8 */

    for (j = z31b_cnttbl0[i]; j >= 0; --j) { /* Line 487, Address: 0x10277d4 */
      *pHScrollWork++ = lD0.w.l; /* Line 488, Address: 0x10277e8 */
    } /* Line 489, Address: 0x10277fc */

    lD3.l = ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 491, Address: 0x1027808 */
    lD3.l += lD2.l; /* Line 492, Address: 0x102782c */
    lD3.l = ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 493, Address: 0x102783c */
  } /* Line 494, Address: 0x1027860 */

  pHScrollWork = &hscrollwork[162]; /* Line 496, Address: 0x102786c */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 497, Address: 0x1027878 */

  for (i = 0; i < 4; ++i) { /* Line 499, Address: 0x102789c */
    *pHScrollWork++ = lD0.w.l; /* Line 500, Address: 0x10278a8 */
  } /* Line 501, Address: 0x10278bc */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 503, Address: 0x10278cc */

  for (i = 0; i < 6; ++i) { /* Line 505, Address: 0x10278f0 */
    *pHScrollWork++ = lD0.w.l; /* Line 506, Address: 0x10278fc */
  } /* Line 507, Address: 0x1027910 */














  pHscrWk = (int_union*)hscrollwork; /* Line 522, Address: 0x1027920 */
  for (i = 12; i >= 0; --i) { /* Line 523, Address: 0x1027928 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 524, Address: 0x1027934 */
    ++pHscrWk; /* Line 525, Address: 0x1027960 */
    for (j = z31b_cnttbl[i]; j >= 0; --j) { /* Line 526, Address: 0x1027964 */
      *pHScrollWork++ = wD1; /* Line 527, Address: 0x1027978 */
    } /* Line 528, Address: 0x1027988 */
  } /* Line 529, Address: 0x1027994 */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 532, Address: 0x10279a0 */

  for (i = 0; i < 8; ++i) { /* Line 534, Address: 0x10279c4 */
    *pHScrollWork++ = lD0.w.l; /* Line 535, Address: 0x10279d0 */
  } /* Line 536, Address: 0x10279e4 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 538, Address: 0x10279f4 */

  for (i = 0; i < 4; ++i) { /* Line 540, Address: 0x1027a18 */
    *pHScrollWork++ = lD0.w.l; /* Line 541, Address: 0x1027a24 */
  } /* Line 542, Address: 0x1027a38 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 544, Address: 0x1027a48 */

  for (i = 0; i < 8; ++i) { /* Line 546, Address: 0x1027a6c */
    *pHScrollWork++ = lD0.w.l; /* Line 547, Address: 0x1027a78 */
  } /* Line 548, Address: 0x1027a8c */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 550, Address: 0x1027a9c */

  for (i = 0; i < 4; ++i) { /* Line 552, Address: 0x1027ac0 */
    *pHScrollWork++ = lD0.w.l; /* Line 553, Address: 0x1027acc */
  } /* Line 554, Address: 0x1027ae0 */


  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 557, Address: 0x1027af0 */
  lD2.l <<= 6; /* Line 558, Address: 0x1027b28 */
  lD2.l /= 24; /* Line 559, Address: 0x1027b34 */
  lD2.l <<= 10; /* Line 560, Address: 0x1027b54 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 561, Address: 0x1027b60 */

  for (i = 5; i >= 0; --i) { /* Line 563, Address: 0x1027b6c */
    lD0.w.l = -lD3.w.l; /* Line 564, Address: 0x1027b78 */
    for (j = z31b_cnttbl1[i]; j >= 0; --i) { /* Line 565, Address: 0x1027b94 */
      *pHScrollWork++ = lD0.w.l; /* Line 566, Address: 0x1027bac */
    } /* Line 567, Address: 0x1027bc0 */
    ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 568, Address: 0x1027bcc */
    lD3.l += lD2.l; /* Line 569, Address: 0x1027bf0 */
    ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 570, Address: 0x1027c00 */
  } /* Line 571, Address: 0x1027c24 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 573, Address: 0x1027c30 */

  for (i = 0; i < 8; ++i) { /* Line 575, Address: 0x1027c54 */
    *pHScrollWork++ = lD0.w.l; /* Line 576, Address: 0x1027c60 */
  } /* Line 577, Address: 0x1027c74 */

  pHScrollBuff = lphscrollbuff; /* Line 579, Address: 0x1027c88 */
  pHScrollWork = &hscrollwork[154]; /* Line 580, Address: 0x1027c94 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 581, Address: 0x1027ca0 */
  lD2.w.l = lD0.w.l; /* Line 582, Address: 0x1027cac */
  wD4 = lD0.w.l; /* Line 583, Address: 0x1027cb4 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 584, Address: 0x1027cbc */
  wD3 = lD0.w.l >> 1; /* Line 585, Address: 0x1027ce0 */
  wD1 = 87; /* Line 586, Address: 0x1027cf8 */
  wD5 = 28; /* Line 587, Address: 0x1027d00 */
  if (wD3 <= wD1) { /* Line 588, Address: 0x1027d08 */

    wD1 -= wD3; /* Line 590, Address: 0x1027d1c */
    if (wD1 >= 27) { /* Line 591, Address: 0x1027d24 */
      wD1 = 28; /* Line 592, Address: 0x1027d34 */
    }

    wD5 -= wD1; /* Line 595, Address: 0x1027d40 */
    pHScrollWork += lD0.w.l / 2U; /* Line 596, Address: 0x1027d48 */
    waterdirec.w += 64; /* Line 597, Address: 0x1027d6c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z31b_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 599, Address: 0x1027d80 */


  } /* Line 602, Address: 0x1027db0 */
  else {
    wD1 -= wD3; /* Line 604, Address: 0x1027db8 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 609, Address: 0x1027dc0 */
  pHScrollWork = &hscrollwork[17]; /* Line 610, Address: 0x1027dd4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 611, Address: 0x1027de0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 612, Address: 0x1027df8 */

  for ( ; (short)wD1 >= 0; --wD1) { /* Line 614, Address: 0x1027e10 */
    lD2.w.h = *pHScrollWork++; /* Line 615, Address: 0x1027e18 */
    lD2.w.l = *pHScrollWork++; /* Line 616, Address: 0x1027e2c */
    lD2.w.l += scrb_h_posit.w.h; /* Line 617, Address: 0x1027e40 */
    lD2.w.l = -lD2.w.l; /* Line 618, Address: 0x1027e54 */
    lD0.w.l = lD2.w.l; /* Line 619, Address: 0x1027e60 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 620, Address: 0x1027e68 */
    if (wD3 <= wD4) { /* Line 621, Address: 0x1027e88 */
      wD5 &= 255; /* Line 622, Address: 0x1027ea0 */
      wD3 = (char)awasintbl[wD5] * 2; /* Line 623, Address: 0x1027ea8 */
      wD3 += scra_h_posit.w.h; /* Line 624, Address: 0x1027ee0 */
      wD3 = -wD3; /* Line 625, Address: 0x1027ef8 */
      lD0.w.h = wD3; /* Line 626, Address: 0x1027f14 */
    }

    pHScrollBuff->l = lD0.l; /* Line 629, Address: 0x1027f18 */
    ++pHScrollBuff; /* Line 630, Address: 0x1027f24 */
    ++wD4; /* Line 631, Address: 0x1027f30 */
    ++wD5; /* Line 632, Address: 0x1027f3c */
  } /* Line 633, Address: 0x1027f48 */

} /* Line 635, Address: 0x1027f68 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 640, Address: 0x1027f90 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 647, Address: 0x1027fc4 */
  pA1 = *ppA1; /* Line 648, Address: 0x1027fe4 */
  pA2 = *ppA2; /* Line 649, Address: 0x1027fec */

  if (*pA3 <= *pwD4) goto label6; /* Line 651, Address: 0x1027ff4 */



label1:
  *pwD2 &= 7; /* Line 656, Address: 0x1028018 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 657, Address: 0x102802c */

  lD0.w.l = *pA2++; /* Line 659, Address: 0x1028058 */
  i = 8 - *pwD2; /* Line 660, Address: 0x1028068 */
  goto label4; /* Line 661, Address: 0x102807c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 664, Address: 0x1028084 */


  if (*pA3 <= *pwD4) goto label7; /* Line 667, Address: 0x10280a0 */



label3:
  lD0.w.l = *pA2++; /* Line 672, Address: 0x10280c4 */
  *pwD4 += 8; /* Line 673, Address: 0x10280d4 */


  i = 8; /* Line 676, Address: 0x10280e8 */
label4:
  for ( ; i > 0; --i) { /* Line 678, Address: 0x10280ec */


    pA1->l = lD0.l; /* Line 681, Address: 0x10280f4 */
    ++pA1; /* Line 682, Address: 0x10280fc */
  } /* Line 683, Address: 0x1028100 */
  if ((short)--wD1 >= 0) goto label2; /* Line 684, Address: 0x1028110 */



label5:
  *ppA1 = pA1; /* Line 689, Address: 0x1028138 */
  *ppA2 = pA2; /* Line 690, Address: 0x1028140 */
  return; /* Line 691, Address: 0x1028148 */


label6:
  wD3 = *pA3++ + 32 - *pwD4; /* Line 695, Address: 0x1028150 */
  if ((short)wD3 > 0) goto label8; /* Line 696, Address: 0x1028180 */


  if (*pA3 > *pwD4) goto label1; /* Line 699, Address: 0x1028198 */


  wD3 = *pA3++ + 32 - *pwD4; /* Line 702, Address: 0x10281bc */
  if ((short)wD3 > 0) goto label8; /* Line 703, Address: 0x10281ec */
  goto label1; /* Line 704, Address: 0x1028204 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 712, Address: 0x102820c */
  if ((short)wD3 <= 0) goto label3; /* Line 713, Address: 0x102823c */



label8:
  --wD3; /* Line 718, Address: 0x1028254 */
  wD6 = wD3; /* Line 719, Address: 0x102825c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 720, Address: 0x1028260 */

  do {
    *pwD2 &= 255; /* Line 723, Address: 0x1028278 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 724, Address: 0x102828c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 725, Address: 0x10282b8 */
    lD0.w.l = -lD0.w.l; /* Line 726, Address: 0x10282cc */
    pA1->w.h = lD0.w.h; /* Line 727, Address: 0x10282e8 */
    pA1->w.l = lD0.w.l; /* Line 728, Address: 0x10282f0 */
    ++pA1; /* Line 729, Address: 0x10282f8 */
    ++*pwD4; /* Line 730, Address: 0x10282fc */
    ++*pwD2; /* Line 731, Address: 0x1028310 */
  } while ((short)--wD3 >= 0); /* Line 732, Address: 0x1028324 */

  wD6 >>= 3; /* Line 734, Address: 0x1028348 */

  do {
    lD0.w.l = *pA2++; /* Line 737, Address: 0x1028350 */
    --wD1; /* Line 738, Address: 0x1028360 */
  } while ((short)--wD6 >= 0); /* Line 739, Address: 0x102836c */
  goto label2; /* Line 740, Address: 0x1028390 */
} /* Line 741, Address: 0x1028398 */















void scroll_h() { /* Line 757, Address: 0x10283c0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 760, Address: 0x10283cc */
  scrh_move(); /* Line 761, Address: 0x10283d8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 762, Address: 0x10283e0 */
    scra_h_count ^= 16; /* Line 763, Address: 0x1028414 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 764, Address: 0x1028428 */
      scrflaga.b.h |= 4; /* Line 765, Address: 0x1028454 */
    } /* Line 766, Address: 0x1028468 */
    else {

      scrflaga.b.h |= 8; /* Line 769, Address: 0x1028470 */
    }
  }


} /* Line 774, Address: 0x1028484 */

void scrh_move() { /* Line 776, Address: 0x10284a0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 779, Address: 0x10284ac */
  wD0 -= scra_h_posit.w.h; /* Line 780, Address: 0x10284b8 */
  wD0 -= scra_hline; /* Line 781, Address: 0x10284cc */
  if (wD0 == 0) { /* Line 782, Address: 0x10284e0 */

    scra_hz = 0; /* Line 784, Address: 0x10284ec */
  } /* Line 785, Address: 0x10284f4 */
  else if ((short)wD0 < 0) { /* Line 786, Address: 0x10284fc */
    left_check(wD0); /* Line 787, Address: 0x1028514 */
  } /* Line 788, Address: 0x1028520 */
  else {
    right_check(wD0); /* Line 790, Address: 0x1028528 */
  }

} /* Line 793, Address: 0x1028534 */


void right_check(unsigned short wD0) { /* Line 796, Address: 0x1028550 */
  unsigned short wD1;

  if ((short)wD0 >= 17) { /* Line 799, Address: 0x102855c */
    wD0 = 16; /* Line 800, Address: 0x102857c */
  }

  wD0 += scra_h_posit.w.h; /* Line 803, Address: 0x1028584 */
  if (scralim_right < (short)wD0) { /* Line 804, Address: 0x102859c */
    wD0 = scralim_right; /* Line 805, Address: 0x10285cc */
  }

  wD1 = wD0; /* Line 808, Address: 0x10285d8 */
  wD1 -= scra_h_posit.w.h; /* Line 809, Address: 0x10285e0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 810, Address: 0x10285f4 */
  scra_h_posit.w.h = wD0; /* Line 811, Address: 0x1028624 */
  scra_hz = wD1; /* Line 812, Address: 0x1028630 */

} /* Line 814, Address: 0x1028638 */


void left_check(unsigned short wD0) { /* Line 817, Address: 0x1028650 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 820, Address: 0x102865c */
    wD0 = -16; /* Line 821, Address: 0x102867c */
  }

  wD0 += scra_h_posit.w.h; /* Line 824, Address: 0x1028684 */
  if (scralim_left > (short)wD0) { /* Line 825, Address: 0x102869c */
    wD0 = scralim_left; /* Line 826, Address: 0x10286cc */
  }

  wD1 = wD0; /* Line 829, Address: 0x10286d8 */
  wD1 -= scra_h_posit.w.h; /* Line 830, Address: 0x10286e0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 831, Address: 0x10286f4 */
  scra_h_posit.w.h = wD0; /* Line 832, Address: 0x1028724 */
  scra_hz = wD1; /* Line 833, Address: 0x1028730 */

} /* Line 835, Address: 0x1028738 */


















void scroll_v() { /* Line 854, Address: 0x1028750 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 857, Address: 0x102875c */
  if (actwk[0].cddat & 4) { /* Line 858, Address: 0x1028788 */
    wD0 -= 5; /* Line 859, Address: 0x10287a0 */
  }

  if (actwk[0].cddat & 2) { /* Line 862, Address: 0x10287a8 */
    wD0 += 32; /* Line 863, Address: 0x10287c0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 864, Address: 0x10287c8 */
      wD0 -= scra_vline; /* Line 865, Address: 0x10287e8 */
      sv_move_main2(wD0); /* Line 866, Address: 0x10287fc */
      return; /* Line 867, Address: 0x1028808 */
    }
    wD0 -= scra_vline; /* Line 869, Address: 0x1028810 */
    if (wD0 >= 64) { /* Line 870, Address: 0x1028824 */
      wD0 -= 64; /* Line 871, Address: 0x1028834 */
      sv_move_main2(wD0); /* Line 872, Address: 0x102883c */
      return; /* Line 873, Address: 0x1028848 */
    }
    wD0 -= 64; /* Line 875, Address: 0x1028850 */
    if (limmoveflag == 0) goto label1; /* Line 876, Address: 0x1028858 */
    sv_move_sub2(); /* Line 877, Address: 0x102886c */
    return; /* Line 878, Address: 0x1028874 */
  }




  wD0 -= scra_vline; /* Line 884, Address: 0x102887c */
  if (wD0 != 0) { /* Line 885, Address: 0x1028890 */
    sv_move_main(wD0); /* Line 886, Address: 0x1028898 */
    return; /* Line 887, Address: 0x10288a4 */
  }
  if (limmoveflag == 0) { /* Line 889, Address: 0x10288ac */
    sv_move_sub2(); /* Line 890, Address: 0x10288c0 */
    return; /* Line 891, Address: 0x10288c8 */
  }


label1:
  scra_vz = 0; /* Line 896, Address: 0x10288d0 */

} /* Line 898, Address: 0x10288d8 */





void sv_move_main(unsigned short wD0) { /* Line 904, Address: 0x10288f0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 907, Address: 0x1028900 */
    sv_move_main1(wD0); /* Line 908, Address: 0x102891c */
  } /* Line 909, Address: 0x1028928 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 912, Address: 0x1028930 */
    if ((short)wD1 < 0) { /* Line 913, Address: 0x102893c */
      wD1 = -wD1; /* Line 914, Address: 0x1028954 */
    }

    if (wD1 >= 2048) { /* Line 917, Address: 0x1028970 */
      sv_move_main2(wD0); /* Line 918, Address: 0x1028980 */
    } /* Line 919, Address: 0x102898c */
    else {
      if ((short)wD0 >= 7) { /* Line 921, Address: 0x1028994 */
        sv_move_plus(1536); /* Line 922, Address: 0x10289b4 */
      } /* Line 923, Address: 0x10289c0 */
      else if ((short)wD0 < -6) { /* Line 924, Address: 0x10289c8 */
        sv_move_minus(1536); /* Line 925, Address: 0x10289e8 */
      } /* Line 926, Address: 0x10289f4 */
      else {
        sv_move_sub(wD0); /* Line 928, Address: 0x10289fc */
      }
    }
  }
} /* Line 932, Address: 0x1028a08 */



void sv_move_main1(unsigned short wD0) { /* Line 936, Address: 0x1028a20 */

  if ((short)wD0 >= 3) { /* Line 938, Address: 0x1028a2c */
    sv_move_plus(512); /* Line 939, Address: 0x1028a4c */
  } /* Line 940, Address: 0x1028a58 */
  else if ((short)wD0 < -2) { /* Line 941, Address: 0x1028a60 */
    sv_move_minus(512); /* Line 942, Address: 0x1028a80 */
  } /* Line 943, Address: 0x1028a8c */
  else {
    sv_move_sub(wD0); /* Line 945, Address: 0x1028a94 */
  }

} /* Line 948, Address: 0x1028aa0 */


void sv_move_main2(unsigned short wD0) { /* Line 951, Address: 0x1028ab0 */

  if ((short)wD0 >= 17) { /* Line 953, Address: 0x1028abc */
    sv_move_plus(4096); /* Line 954, Address: 0x1028adc */
  } /* Line 955, Address: 0x1028ae8 */
  else if ((short)wD0 < -16) { /* Line 956, Address: 0x1028af0 */
    sv_move_minus(4096); /* Line 957, Address: 0x1028b10 */
  } /* Line 958, Address: 0x1028b1c */
  else {
    sv_move_sub(wD0); /* Line 960, Address: 0x1028b24 */
  }

} /* Line 963, Address: 0x1028b30 */


void sv_move_sub2() { /* Line 966, Address: 0x1028b40 */
  limmoveflag = 0; /* Line 967, Address: 0x1028b48 */
  sv_move_sub(0); /* Line 968, Address: 0x1028b50 */
} /* Line 969, Address: 0x1028b5c */


void sv_move_sub(unsigned short wD0) { /* Line 972, Address: 0x1028b70 */
  int_union lD1;

  lD1.w.h = 0; /* Line 975, Address: 0x1028b7c */
  lD1.w.l = wD0; /* Line 976, Address: 0x1028b80 */
  lD1.l += scra_v_posit.w.h; /* Line 977, Address: 0x1028b88 */
  if ((short)wD0 > 0) { /* Line 978, Address: 0x1028ba4 */
    scrv_down_ch(lD1); /* Line 979, Address: 0x1028bc0 */
  } /* Line 980, Address: 0x1028bcc */
  else {
    scrv_up_ch(lD1); /* Line 982, Address: 0x1028bd4 */
  }

} /* Line 985, Address: 0x1028be0 */




void sv_move_minus(unsigned short wD1) { /* Line 990, Address: 0x1028bf0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 994, Address: 0x1028c00 */
  lD1.l <<= 8; /* Line 995, Address: 0x1028c1c */
  lD1.l += scra_v_posit.l; /* Line 996, Address: 0x1028c28 */

  wk = lD1.w.h; /* Line 998, Address: 0x1028c3c */
  lD1.w.h = lD1.w.l; /* Line 999, Address: 0x1028c44 */
  lD1.w.l = wk; /* Line 1000, Address: 0x1028c4c */
  scrv_up_ch(lD1); /* Line 1001, Address: 0x1028c50 */
} /* Line 1002, Address: 0x1028c5c */



void scrv_up_ch(int_union lD1) { /* Line 1006, Address: 0x1028c70 */
  if (scralim_up >= lD1.w.l) { /* Line 1007, Address: 0x1028c7c */
    if (lD1.w.l < -255) { /* Line 1008, Address: 0x1028ca4 */
      lD1.w.l &= 2047; /* Line 1009, Address: 0x1028cbc */
      actwk[0].yposi.w.h &= 32767; /* Line 1010, Address: 0x1028cc8 */
      scra_v_posit.w.h &= 2047; /* Line 1011, Address: 0x1028cdc */
      scrb_v_posit.w.h &= 1023; /* Line 1012, Address: 0x1028cf0 */
    } /* Line 1013, Address: 0x1028d04 */
    else {

      lD1.w.l = scralim_up; /* Line 1016, Address: 0x1028d0c */
    }
  }
  scrv_move(lD1); /* Line 1019, Address: 0x1028d18 */

} /* Line 1021, Address: 0x1028d24 */





void sv_move_plus(unsigned short wD1) { /* Line 1027, Address: 0x1028d40 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1031, Address: 0x1028d50 */
  lD1.w.l = wD1; /* Line 1032, Address: 0x1028d54 */
  lD1.l <<= 8; /* Line 1033, Address: 0x1028d5c */
  lD1.l += scra_v_posit.l; /* Line 1034, Address: 0x1028d68 */

  wk = lD1.w.h; /* Line 1036, Address: 0x1028d7c */
  lD1.w.h = lD1.w.l; /* Line 1037, Address: 0x1028d84 */
  lD1.w.l = wk; /* Line 1038, Address: 0x1028d8c */

  scrv_down_ch(lD1); /* Line 1040, Address: 0x1028d90 */

} /* Line 1042, Address: 0x1028d9c */



void scrv_down_ch(int_union lD1) { /* Line 1046, Address: 0x1028db0 */
  if (scralim_down <= lD1.w.l) { /* Line 1047, Address: 0x1028dbc */
    lD1.w.l -= 2048; /* Line 1048, Address: 0x1028de4 */
    if (lD1.w.l > 0) { /* Line 1049, Address: 0x1028df0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1050, Address: 0x1028e04 */
      scra_v_posit.w.h -= 2048; /* Line 1051, Address: 0x1028e18 */
      scrb_v_posit.w.h &= 1023; /* Line 1052, Address: 0x1028e2c */
    } /* Line 1053, Address: 0x1028e40 */
    else {
      lD1.w.l = scralim_down; /* Line 1055, Address: 0x1028e48 */
    }
  }
  scrv_move(lD1); /* Line 1058, Address: 0x1028e54 */

} /* Line 1060, Address: 0x1028e60 */


void scrv_move(int_union lD1) { /* Line 1063, Address: 0x1028e70 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1066, Address: 0x1028e80 */

  wk = lD1.w.h; /* Line 1068, Address: 0x1028e8c */
  lD1.w.h = lD1.w.l; /* Line 1069, Address: 0x1028e94 */
  lD1.w.l = wk; /* Line 1070, Address: 0x1028e9c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1072, Address: 0x1028ea0 */
  scra_v_posit.l = lD1.l; /* Line 1073, Address: 0x1028ec8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1076, Address: 0x1028ed4 */
    scra_v_count ^= 16; /* Line 1077, Address: 0x1028f08 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1078, Address: 0x1028f1c */

      scrflaga.b.h |= 2; /* Line 1080, Address: 0x1028f48 */
    } /* Line 1081, Address: 0x1028f5c */
    else {
      scrflaga.b.h |= 1; /* Line 1083, Address: 0x1028f64 */
    }
  }


} /* Line 1088, Address: 0x1028f78 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1092, Address: 0x1028f90 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1095, Address: 0x1028f9c */
  lD0.l += lD4.l; /* Line 1096, Address: 0x1028fac */
  scrb_h_posit.l = lD0.l; /* Line 1097, Address: 0x1028fbc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1099, Address: 0x1028fc8 */

    scrb_h_count ^= 16; /* Line 1101, Address: 0x1028ffc */
    lD0.l -= lD2.l; /* Line 1102, Address: 0x1029010 */
    if ((long int)lD0.l < 0) { /* Line 1103, Address: 0x1029020 */
      scrflagb.b.h |= 4; /* Line 1104, Address: 0x1029034 */
    } /* Line 1105, Address: 0x1029048 */
    else {

      scrflagb.b.h |= 8; /* Line 1108, Address: 0x1029050 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1113, Address: 0x1029064 */
  lD0.l += lD5.l; /* Line 1114, Address: 0x1029074 */
  scrb_h_posit.l = lD0.l; /* Line 1115, Address: 0x1029084 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1117, Address: 0x1029090 */

    scrb_v_count ^= 16; /* Line 1119, Address: 0x10290c4 */
    lD0.l -= lD3.l; /* Line 1120, Address: 0x10290d8 */
    if ((long int)lD0.l < 0) { /* Line 1121, Address: 0x10290e8 */
      scrflagb.b.h |= 1; /* Line 1122, Address: 0x10290fc */
    } /* Line 1123, Address: 0x1029110 */
    else {

      scrflagb.b.h |= 2; /* Line 1126, Address: 0x1029118 */
    }
  }


} /* Line 1131, Address: 0x102912c */






void scrollb_v(unsigned short wD0) { /* Line 1138, Address: 0x1029140 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1141, Address: 0x102914c */
  scrb_v_posit.w.h = wD0; /* Line 1142, Address: 0x1029158 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1144, Address: 0x1029164 */
    scrb_v_count ^= 16; /* Line 1145, Address: 0x1029190 */
    if ((short)wD3 > (short)wD0) { /* Line 1146, Address: 0x10291a4 */
      scrflagb.b.h |= 1; /* Line 1147, Address: 0x10291d4 */
    } /* Line 1148, Address: 0x10291e8 */
    else {

      scrflagb.b.h |= 2; /* Line 1151, Address: 0x10291f0 */
    }
  }


} /* Line 1156, Address: 0x1029204 */



void scrollb_h(int lD4, int flagb) { /* Line 1160, Address: 0x1029220 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1164, Address: 0x1029230 */
  lD0.l = lD2.l + lD4; /* Line 1165, Address: 0x102923c */
  scrb_h_posit.l = lD0.l; /* Line 1166, Address: 0x102924c */

  lD1.w.h = lD0.w.l; /* Line 1168, Address: 0x1029258 */
  lD1.w.l = lD0.w.h; /* Line 1169, Address: 0x1029260 */
  lD1.w.l &= 16; /* Line 1170, Address: 0x1029268 */

  bD3 = scrb_h_count; /* Line 1172, Address: 0x1029274 */
  lD1.b.b4 ^= bD3; /* Line 1173, Address: 0x1029280 */
  if (!lD1.b.b4) { /* Line 1174, Address: 0x1029294 */
    scrb_h_count ^= 16; /* Line 1175, Address: 0x10292a0 */
    lD0.l -= lD2.l; /* Line 1176, Address: 0x10292b4 */
    if ((long int)lD0.l < 0) { /* Line 1177, Address: 0x10292c4 */
      scrflagb.b.h |= flagb; /* Line 1178, Address: 0x10292d8 */
    } /* Line 1179, Address: 0x10292f4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1182, Address: 0x10292fc */
    }
  }


} /* Line 1187, Address: 0x102931c */



void scrollc_h(int lD4, int flagc) { /* Line 1191, Address: 0x1029330 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1195, Address: 0x1029340 */
  lD0.l = lD2.l + lD4; /* Line 1196, Address: 0x102934c */
  scrc_h_posit.l = lD0.l; /* Line 1197, Address: 0x102935c */

  lD1.w.h = lD0.w.l; /* Line 1199, Address: 0x1029368 */
  lD1.w.l = lD0.w.h; /* Line 1200, Address: 0x1029370 */
  lD1.w.l &= 16; /* Line 1201, Address: 0x1029378 */

  bD3 = scrc_h_count; /* Line 1203, Address: 0x1029384 */
  lD1.b.b4 ^= bD3; /* Line 1204, Address: 0x1029390 */
  if (!lD1.b.b4) { /* Line 1205, Address: 0x10293a4 */
    scrc_h_count ^= 16; /* Line 1206, Address: 0x10293b0 */
    lD0.l -= lD2.l; /* Line 1207, Address: 0x10293c4 */
    if ((long int)lD0.l < 0) { /* Line 1208, Address: 0x10293d4 */
      scrflagc.b.h |= flagc; /* Line 1209, Address: 0x10293e8 */
    } /* Line 1210, Address: 0x1029404 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1213, Address: 0x102940c */
    }
  }


} /* Line 1218, Address: 0x102942c */











void scrollz_h(int lD4, int flagz) { /* Line 1230, Address: 0x1029440 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1234, Address: 0x1029450 */
  lD0.l = lD2.l + lD4; /* Line 1235, Address: 0x102945c */
  scrz_h_posit.l = lD0.l; /* Line 1236, Address: 0x102946c */

  lD1.w.h = lD0.w.l; /* Line 1238, Address: 0x1029478 */
  lD1.w.l = lD0.w.h; /* Line 1239, Address: 0x1029480 */
  lD1.w.l &= 16; /* Line 1240, Address: 0x1029488 */

  bD3 = scrz_h_count; /* Line 1242, Address: 0x1029494 */
  lD1.b.b4 ^= bD3; /* Line 1243, Address: 0x10294a0 */
  if (!lD1.b.b4) { /* Line 1244, Address: 0x10294b4 */
    scrz_h_count ^= 16; /* Line 1245, Address: 0x10294c0 */
    lD0.l -= lD2.l; /* Line 1246, Address: 0x10294d4 */
    if ((long int)lD0.l < 0) { /* Line 1247, Address: 0x10294e4 */
      scrflagz.b.h |= flagz; /* Line 1248, Address: 0x10294f8 */
    } /* Line 1249, Address: 0x1029514 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1252, Address: 0x102951c */
    }
  }


} /* Line 1257, Address: 0x102953c */














void scrollwrtadva() { /* Line 1272, Address: 0x1029550 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1278, Address: 0x102956c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1279, Address: 0x1029570 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1280, Address: 0x102957c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1281, Address: 0x1029588 */
  pScrFlag = &scrflagb.b.h; /* Line 1282, Address: 0x1029590 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1283, Address: 0x1029598 */







} /* Line 1291, Address: 0x10295ac */












void scrollwrt() { /* Line 1304, Address: 0x10295d0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1313, Address: 0x10295f0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1314, Address: 0x10295f4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1315, Address: 0x1029600 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1316, Address: 0x102960c */
  pScrFlag = &scrflagbw.b.h; /* Line 1317, Address: 0x1029614 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1318, Address: 0x102961c */

  VramBase = 16384; /* Line 1320, Address: 0x1029630 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1321, Address: 0x1029634 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1322, Address: 0x1029640 */
  pMapWk = (unsigned char*)mapwka; /* Line 1323, Address: 0x102964c */
  pScrFlag = &scrflagaw.b.h; /* Line 1324, Address: 0x1029654 */

  if (*pScrFlag) { /* Line 1326, Address: 0x102965c */
    if (*pScrFlag & 1) { /* Line 1327, Address: 0x1029668 */
      *pScrFlag &= 254; /* Line 1328, Address: 0x102967c */

      lD4.l = -16; /* Line 1330, Address: 0x1029688 */
      wD5 = 65520; /* Line 1331, Address: 0x1029690 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1333, Address: 0x1029698 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1335, Address: 0x10296b8 */
    }




    if (*pScrFlag & 2) { /* Line 1341, Address: 0x10296e4 */
      *pScrFlag &= 253; /* Line 1342, Address: 0x10296f8 */

      lD4.l = 224; /* Line 1344, Address: 0x1029704 */
      wD5 = 65520; /* Line 1345, Address: 0x102970c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1346, Address: 0x1029714 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1348, Address: 0x1029734 */
    }




    if (*pScrFlag & 4) { /* Line 1354, Address: 0x1029760 */
      *pScrFlag &= 251; /* Line 1355, Address: 0x1029774 */

      lD4.l = -16; /* Line 1357, Address: 0x1029780 */
      wD5 = 65520; /* Line 1358, Address: 0x1029788 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1359, Address: 0x1029790 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1361, Address: 0x10297b0 */
    }




    if (*pScrFlag & 8) { /* Line 1367, Address: 0x10297dc */
      *pScrFlag &= 247; /* Line 1368, Address: 0x10297f0 */

      lD4.l = -16; /* Line 1370, Address: 0x10297fc */
      wD5 = 320; /* Line 1371, Address: 0x1029804 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1372, Address: 0x102980c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1374, Address: 0x102982c */
    }
  }






} /* Line 1383, Address: 0x1029858 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1400, Address: 0x1029880 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1411, Address: 0x10298ac */

  if (*pScrFlag & 1) { /* Line 1413, Address: 0x10298b4 */
    *pScrFlag &= 254; /* Line 1414, Address: 0x10298cc */
  } /* Line 1415, Address: 0x10298e0 */
  else {
    *pScrFlag &= 254; /* Line 1417, Address: 0x10298e8 */

    if (*pScrFlag & 2) { /* Line 1419, Address: 0x10298fc */
      *pScrFlag &= 253; /* Line 1420, Address: 0x1029914 */
      lD4.w.l = 224; /* Line 1421, Address: 0x1029928 */
    } /* Line 1422, Address: 0x1029930 */
    else {
      *pScrFlag &= 253; /* Line 1424, Address: 0x1029938 */
      goto label1; /* Line 1425, Address: 0x102994c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1430, Address: 0x1029954 */
  wD0 &= 127; /* Line 1431, Address: 0x10299a4 */
  wD0 = z31bwrttbl[wD0 + 1]; /* Line 1432, Address: 0x10299ac */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1438, Address: 0x10299cc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1439, Address: 0x10299ec */
  if (wD0 != 0) { /* Line 1440, Address: 0x1029a10 */
    wD5 = 65520; /* Line 1441, Address: 0x1029a1c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1442, Address: 0x1029a24 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1444, Address: 0x1029a44 */



  } /* Line 1448, Address: 0x1029a70 */
  else {

    wD5 = 0; /* Line 1451, Address: 0x1029a78 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1452, Address: 0x1029a7c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1456, Address: 0x1029a9c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1463, Address: 0x1029ac8 */






    lD4.l = -16; /* Line 1470, Address: 0x1029adc */
    wD5 = 65520; /* Line 1471, Address: 0x1029ae4 */
    if (*pScrFlag & 168) { /* Line 1472, Address: 0x1029aec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1473, Address: 0x1029b04 */
      wD5 = 320; /* Line 1474, Address: 0x1029b24 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1478, Address: 0x1029b2c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1480, Address: 0x1029b5c */
    if (WrtTblCnt >= 114) WrtTblCnt = 113; /* Line 1481, Address: 0x1029b68 */



    for (i = 0; i < 16; ++i) { /* Line 1485, Address: 0x1029b78 */
      wD0 = z31bwrttbl[WrtTblCnt++]; /* Line 1486, Address: 0x1029b84 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1487, Address: 0x1029ba4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1488, Address: 0x1029bd0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1489, Address: 0x1029bf0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1491, Address: 0x1029c14 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1494, Address: 0x1029c38 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1496, Address: 0x1029c58 */
      }
      lD4.w.l += 16; /* Line 1498, Address: 0x1029c6c */
    } /* Line 1499, Address: 0x1029c78 */
    *pScrFlag = 0; /* Line 1500, Address: 0x1029c88 */
  }
} /* Line 1502, Address: 0x1029c90 */







void scrollwrtc() {} /* Line 1510, Address: 0x1029cc0 */




void scrollwrtz() {} /* Line 1515, Address: 0x1029cd0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1536, Address: 0x1029ce0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1549, Address: 0x1029d08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1552, Address: 0x1029d28 */
    pTilePoint->x += 2; /* Line 1553, Address: 0x1029d3c */
    if (pTilePoint->x >= 64) { /* Line 1554, Address: 0x1029d50 */
      pTilePoint->x -= 64; /* Line 1555, Address: 0x1029d64 */
    }
    xOffs += 16; /* Line 1557, Address: 0x1029d78 */
  } while (--lpcnt >= 0); /* Line 1558, Address: 0x1029d84 */
} /* Line 1559, Address: 0x1029d98 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1563, Address: 0x1029db0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1567, Address: 0x1029dd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1570, Address: 0x1029df8 */
    pTilePoint->x += 2; /* Line 1571, Address: 0x1029e0c */
    if (pTilePoint->x >= 64) { /* Line 1572, Address: 0x1029e20 */
      pTilePoint->x -= 64; /* Line 1573, Address: 0x1029e34 */
    }
    xOffs += 16; /* Line 1575, Address: 0x1029e48 */
  } while (--lpcnt >= 0); /* Line 1576, Address: 0x1029e54 */
} /* Line 1577, Address: 0x1029e68 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1596, Address: 0x1029e80 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1600, Address: 0x1029ea8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1603, Address: 0x1029ec8 */
    pTilePoint->y += 2; /* Line 1604, Address: 0x1029edc */
    if (pTilePoint->y >= 32) { /* Line 1605, Address: 0x1029eec */
      pTilePoint->y -= 32; /* Line 1606, Address: 0x1029f00 */
    }
    yOffs += 16; /* Line 1608, Address: 0x1029f10 */
  } while (--lpcnt >= 0); /* Line 1609, Address: 0x1029f1c */
} /* Line 1610, Address: 0x1029f30 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1629, Address: 0x1029f40 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1635, Address: 0x1029f74 */

    base = 1; /* Line 1637, Address: 0x1029f84 */
  } /* Line 1638, Address: 0x1029f88 */
  else if (VramBase == 16384) { /* Line 1639, Address: 0x1029f90 */

    base = 0; /* Line 1641, Address: 0x1029fa0 */
  }
  x = pTilePoint->x; /* Line 1643, Address: 0x1029fa4 */
  y = pTilePoint->y; /* Line 1644, Address: 0x1029fac */


  frip = BlkIndex & 6144; /* Line 1647, Address: 0x1029fb4 */
  BlkIndex &= 1023; /* Line 1648, Address: 0x1029fbc */
  if (frip == 6144) { /* Line 1649, Address: 0x1029fc8 */

    p0 = 3, p1 = 2; /* Line 1651, Address: 0x1029fd4 */
    p2 = 1, p3 = 0; /* Line 1652, Address: 0x1029fdc */
  } /* Line 1653, Address: 0x1029fe4 */
  else if (frip & 4096) { /* Line 1654, Address: 0x1029fec */

    p0 = 2, p1 = 3; /* Line 1656, Address: 0x1029ff8 */
    p2 = 0, p3 = 1; /* Line 1657, Address: 0x102a000 */
  } /* Line 1658, Address: 0x102a008 */
  else if (frip & 2048) { /* Line 1659, Address: 0x102a010 */

    p0 = 1, p1 = 0; /* Line 1661, Address: 0x102a01c */
    p2 = 3, p3 = 2; /* Line 1662, Address: 0x102a024 */
  } /* Line 1663, Address: 0x102a02c */
  else {

    p0 = 0, p1 = 1; /* Line 1666, Address: 0x102a034 */
    p2 = 2, p3 = 3; /* Line 1667, Address: 0x102a03c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1670, Address: 0x102a044 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1671, Address: 0x102a088 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1672, Address: 0x102a0cc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1673, Address: 0x102a110 */

} /* Line 1675, Address: 0x102a154 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1693, Address: 0x102a190 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1694, Address: 0x102a1b0 */
} /* Line 1695, Address: 0x102a1d0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1697, Address: 0x102a1e0 */
  wH_posiw = 0; /* Line 1698, Address: 0x102a200 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1699, Address: 0x102a204 */
} /* Line 1700, Address: 0x102a224 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1707, Address: 0x102a240 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1713, Address: 0x102a270 */
  yOffs += wV_posiw; /* Line 1714, Address: 0x102a280 */





  if ((short)xOffs < 0) /* Line 1720, Address: 0x102a290 */
    xOffs = 0; /* Line 1721, Address: 0x102a2ac */
  if ((short)yOffs < 0) /* Line 1722, Address: 0x102a2b0 */
    yOffs = 0; /* Line 1723, Address: 0x102a2cc */
  if ((short)xOffs >= 16384) /* Line 1724, Address: 0x102a2d0 */
    xOffs = 16383; /* Line 1725, Address: 0x102a2f0 */
  if ((short)yOffs >= 2048) /* Line 1726, Address: 0x102a2f8 */
    yOffs = 2047; /* Line 1727, Address: 0x102a318 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1728, Address: 0x102a320 */
  if (i < 0) i = 0; /* Line 1729, Address: 0x102a368 */

  ScreenNo = pMapWk[i] & 127; /* Line 1731, Address: 0x102a374 */

  if (ScreenNo) { /* Line 1733, Address: 0x102a390 */




    xOffs &= 32767; /* Line 1738, Address: 0x102a398 */
    yOffs &= 32767; /* Line 1739, Address: 0x102a3a4 */


    xBlk = xOffs; /* Line 1742, Address: 0x102a3b0 */
    xBlk %= 256; /* Line 1743, Address: 0x102a3b8 */
    xBlk /= 16; /* Line 1744, Address: 0x102a3d8 */
    yBlk = yOffs; /* Line 1745, Address: 0x102a3f4 */
    yBlk %= 256; /* Line 1746, Address: 0x102a3fc */
    yBlk /= 16; /* Line 1747, Address: 0x102a41c */

    lpw = pmapwk; /* Line 1749, Address: 0x102a438 */
    lpw += xBlk; /* Line 1750, Address: 0x102a440 */
    lpw += yBlk * 16; /* Line 1751, Address: 0x102a448 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1752, Address: 0x102a454 */
    *pIndex = *lpw; /* Line 1753, Address: 0x102a46c */

    return 1; /* Line 1755, Address: 0x102a47c */
  }

  *pIndex = 0; /* Line 1758, Address: 0x102a488 */
  return 0; /* Line 1759, Address: 0x102a490 */
} /* Line 1760, Address: 0x102a494 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1780, Address: 0x102a4c0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1788, Address: 0x102a4e8 */
  if (ScreenNo) { /* Line 1789, Address: 0x102a54c */





    xBlk = xOffs; /* Line 1795, Address: 0x102a554 */
    xBlk %= 256; /* Line 1796, Address: 0x102a55c */
    xBlk /= 16; /* Line 1797, Address: 0x102a57c */
    yBlk = yOffs; /* Line 1798, Address: 0x102a598 */
    yBlk %= 256; /* Line 1799, Address: 0x102a5a0 */
    yBlk /= 16; /* Line 1800, Address: 0x102a5c0 */


    lpw = pmapwk; /* Line 1803, Address: 0x102a5dc */
    lpw += xBlk; /* Line 1804, Address: 0x102a5e4 */
    lpw += yBlk * 16; /* Line 1805, Address: 0x102a5ec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1806, Address: 0x102a5f8 */
    *ppBlockNo = lpw; /* Line 1807, Address: 0x102a610 */
    *pIndex = *lpw; /* Line 1808, Address: 0x102a618 */




    return 1; /* Line 1813, Address: 0x102a628 */
  }

  *pIndex = 0; /* Line 1816, Address: 0x102a634 */
  return 0; /* Line 1817, Address: 0x102a63c */
} /* Line 1818, Address: 0x102a640 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1832, Address: 0x102a660 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1839, Address: 0x102a67c */
  pMapWk = (unsigned char*)mapwka; /* Line 1840, Address: 0x102a680 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1841, Address: 0x102a688 */
    *pBlockIndex = BlockNo; /* Line 1842, Address: 0x102a6ac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1843, Address: 0x102a6b8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1844, Address: 0x102a6d0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1845, Address: 0x102a6e4 */
    }
  }


} /* Line 1850, Address: 0x102a6fc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1864, Address: 0x102a720 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1865, Address: 0x102a72c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1866, Address: 0x102a758 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1867, Address: 0x102a7a4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1868, Address: 0x102a7d0 */

          return 0; /* Line 1870, Address: 0x102a81c */
        }
      }
    }
  }

  return 1; /* Line 1876, Address: 0x102a828 */
} /* Line 1877, Address: 0x102a82c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1894, Address: 0x102a840 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1895, Address: 0x102a85c */

} /* Line 1897, Address: 0x102a878 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1899, Address: 0x102a890 */
  wH_posiw = 0; /* Line 1900, Address: 0x102a8ac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1901, Address: 0x102a8b0 */

} /* Line 1903, Address: 0x102a8cc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1905, Address: 0x102a8e0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1906, Address: 0x102a8f4 */

} /* Line 1908, Address: 0x102a910 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1910, Address: 0x102a920 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1911, Address: 0x102a93c */

} /* Line 1913, Address: 0x102a958 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1915, Address: 0x102a970 */
  xOffs += wH_posiw; /* Line 1916, Address: 0x102a988 */
  yOffs += wV_posiw; /* Line 1917, Address: 0x102a998 */
  yOffs &= 240; /* Line 1918, Address: 0x102a9a8 */
  xOffs &= 496; /* Line 1919, Address: 0x102a9b4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1921, Address: 0x102a9c0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1922, Address: 0x102a9ec */


} /* Line 1925, Address: 0x102aa18 */















void mapwrt() { /* Line 1941, Address: 0x102aa30 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1946, Address: 0x102aa48 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1947, Address: 0x102aa54 */
  pMapWk = (unsigned char*)mapwka; /* Line 1948, Address: 0x102aa60 */
  VramBase = 16384; /* Line 1949, Address: 0x102aa68 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1950, Address: 0x102aa6c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1954, Address: 0x102aa84 */
  VramBase = 24576; /* Line 1955, Address: 0x102aa8c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1956, Address: 0x102aa90 */

} /* Line 1958, Address: 0x102aaa0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1961, Address: 0x102aac0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1962, Address: 0x102aad8 */
} /* Line 1963, Address: 0x102aaf8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1968, Address: 0x102ab10 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1972, Address: 0x102ab30 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1975, Address: 0x102ab4c */



    wD4 += 16; /* Line 1979, Address: 0x102ab74 */
  } while ((short)--wD6 >= 0); /* Line 1980, Address: 0x102ab80 */

} /* Line 1982, Address: 0x102aba8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1987, Address: 0x102abc0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1990, Address: 0x102abdc */
  wD6 = 15; /* Line 1991, Address: 0x102abe4 */






  do {
    if (actwk[0].xposi.w.h == 96) /* Line 1999, Address: 0x102abec */
      wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 2000, Address: 0x102ac08 */
    else
      wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 2002, Address: 0x102ac34 */

    mapwrt_sub(z31bwrttbl, wD0, wD4, pMapWk, VramBase); /* Line 2004, Address: 0x102ac58 */
    wD4 += 16; /* Line 2005, Address: 0x102ac78 */
  } while ((short)--wD6 >= 0); /* Line 2006, Address: 0x102ac80 */
} /* Line 2007, Address: 0x102aca4 */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2033, Address: 0x102acc0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2038, Address: 0x102ace8 */
  wD0 = pWrttbl[wD0]; /* Line 2039, Address: 0x102acf8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2041, Address: 0x102ad14 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2042, Address: 0x102ad38 */
  if (wD0) { /* Line 2043, Address: 0x102ad60 */
    wD5 = 65520; /* Line 2044, Address: 0x102ad6c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2045, Address: 0x102ad74 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2048, Address: 0x102ad90 */



  } /* Line 2052, Address: 0x102adb8 */
  else {

    wD5 = 0; /* Line 2055, Address: 0x102adc0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2056, Address: 0x102adc4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2060, Address: 0x102ade0 */
  }





} /* Line 2067, Address: 0x102ae08 */




void mapinit() { /* Line 2072, Address: 0x102ae30 */





  mapset(); /* Line 2078, Address: 0x102ae38 */


  colorset2(mapinittbl.colorno2); /* Line 2081, Address: 0x102ae40 */
  colorset(mapinittbl.colorno2); /* Line 2082, Address: 0x102ae54 */






  if (plflag != 0) { /* Line 2089, Address: 0x102ae68 */
    enecginit(); /* Line 2090, Address: 0x102ae7c */
  }

  if (play_start & 2) { /* Line 2093, Address: 0x102ae84 */

    divdevset(); /* Line 2095, Address: 0x102ae9c */
  }


} /* Line 2099, Address: 0x102aea4 */









void mapset() {} /* Line 2109, Address: 0x102aec0 */
