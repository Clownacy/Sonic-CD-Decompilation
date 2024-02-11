#include "..\EQU.H"
#include "SCR31A.H"

static unsigned char z33dwrttbl[49] = {
  0, 0, 0, 0, 6, 6, 6, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
  6, 6, 6, 4, 4, 4, 4, 4, 4, 4,
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
extern unsigned char mapwkb[64][8];
extern unsigned char mapwka[64][8];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;










































































void enecginit() {} /* Line 110, Address: 0x1026ce0 */



void divdevset() {} /* Line 114, Address: 0x1026cf0 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 168, Address: 0x1026d00 */
    return &actwk[0]; /* Line 169, Address: 0x1026d14 */
  }
  return &actwk[1]; /* Line 171, Address: 0x1026d24 */
} /* Line 172, Address: 0x1026d2c */












void scr_set() { /* Line 185, Address: 0x1026d40 */





  unsigned short scr_dir_tbl[6] = { /* Line 191, Address: 0x1026d4c */
    4, 0, 1175, 48, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 196, Address: 0x1026d80 */

  i = 0; /* Line 198, Address: 0x1026dc8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 199, Address: 0x1026dcc */
  scralim_left = scr_dir_tbl[i]; /* Line 200, Address: 0x1026de8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 201, Address: 0x1026dfc */
  scralim_right = scr_dir_tbl[i]; /* Line 202, Address: 0x1026e18 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 203, Address: 0x1026e2c */
  scralim_up = scr_dir_tbl[i]; /* Line 204, Address: 0x1026e48 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 205, Address: 0x1026e5c */
  scralim_down = scr_dir_tbl[i]; /* Line 206, Address: 0x1026e78 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 207, Address: 0x1026e8c */

  scra_h_keep = scralim_left + 576; /* Line 209, Address: 0x1026ea8 */
  scra_h_count = 16; /* Line 210, Address: 0x1026ecc */
  scra_v_count = 16; /* Line 211, Address: 0x1026ed8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 213, Address: 0x1026ee4 */
  scra_hline = 160; /* Line 214, Address: 0x1026f00 */

  playposiset(); /* Line 216, Address: 0x1026f0c */
} /* Line 217, Address: 0x1026f14 */











void playposiset() { /* Line 229, Address: 0x1026f30 */
  unsigned short playpositbl[2] = { /* Line 230, Address: 0x1026f48 */
    80,
    268
  };
  unsigned short endplpositbl[16] = { /* Line 234, Address: 0x1026f64 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 244, Address: 0x1026f98 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 254, Address: 0x1026fc4 */
    playload(); /* Line 255, Address: 0x1026fd8 */
    xWk = actwk[0].xposi.w.h; /* Line 256, Address: 0x1026fe0 */
    yWk = actwk[0].yposi.w.h; /* Line 257, Address: 0x1026ff0 */

    if (yWk < 0) yWk = 0; /* Line 259, Address: 0x1027000 */

  } /* Line 261, Address: 0x1027014 */
  else {

    if (demoflag.w < 0) { /* Line 264, Address: 0x102701c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 265, Address: 0x1027034 */
    } /* Line 266, Address: 0x102705c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 269, Address: 0x1027064 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 272, Address: 0x1027084 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 273, Address: 0x10270a0 */
  }


  if ((unsigned short)xWk >= 161) { /* Line 277, Address: 0x10270b4 */
    xWk -= 160; /* Line 278, Address: 0x10270c8 */
  } /* Line 279, Address: 0x10270d4 */
  else {
    xWk = 0; /* Line 281, Address: 0x10270dc */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 285, Address: 0x10270e0 */
    xWk = scralim_right; /* Line 286, Address: 0x1027104 */
  }
  scra_h_posit.w.h = xWk; /* Line 288, Address: 0x1027114 */

  if ((unsigned short)yWk >= 97) { /* Line 290, Address: 0x102711c */
    yWk -= 96; /* Line 291, Address: 0x1027130 */
  } /* Line 292, Address: 0x102713c */
  else {
    yWk = 0; /* Line 294, Address: 0x1027144 */
  }

  if (scralim_down < yWk) { /* Line 297, Address: 0x1027148 */
    yWk = scralim_down; /* Line 298, Address: 0x102716c */
  }

  scra_v_posit.w.h = yWk; /* Line 301, Address: 0x102717c */

  scrbinit(xWk, yWk); /* Line 303, Address: 0x1027184 */

  i = 0; /* Line 305, Address: 0x1027194 */
  loopmapno = playmapnotbl[i++]; /* Line 306, Address: 0x1027198 */
  loopmapno2 = playmapnotbl[i++]; /* Line 307, Address: 0x10271b0 */
  ballmapno = playmapnotbl[i++]; /* Line 308, Address: 0x10271c8 */
  ballmapno2 = playmapnotbl[i++]; /* Line 309, Address: 0x10271e0 */


} /* Line 312, Address: 0x10271f8 */











void scrbinit(short xWk, short yWk) { /* Line 324, Address: 0x1027220 */
  int i;
  short wD2;


  yWk = 536; /* Line 329, Address: 0x1027234 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 330, Address: 0x102723c */
  if ((unsigned short)scra_v_posit.w.h < 1313) { /* Line 331, Address: 0x1027264 */
    yWk -= wD2 / 2; /* Line 332, Address: 0x1027280 */
    if (yWk < 0) { /* Line 333, Address: 0x10272b4 */
      yWk = 0; /* Line 334, Address: 0x10272c8 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 338, Address: 0x10272cc */
  scrb_v_posit.w.l = 0; /* Line 339, Address: 0x10272d8 */
  scrc_v_posit.w.h = yWk; /* Line 340, Address: 0x10272e0 */
  scrz_v_posit.w.h = yWk; /* Line 341, Address: 0x10272ec */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 343, Address: 0x10272f8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 344, Address: 0x1027330 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 345, Address: 0x1027370 */


  for (i = 0; i < 12; ++i) { /* Line 348, Address: 0x10273b0 */
    ((int*)hscrollwork)[i] = 0; /* Line 349, Address: 0x10273bc */
  } /* Line 350, Address: 0x10273d0 */

} /* Line 352, Address: 0x10273e0 */












void scroll() { /* Line 365, Address: 0x1027400 */
  int LineSpdTbl[12] = { /* Line 366, Address: 0x1027420 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     8192, 12288, 16384,
    24576, 32768, 49152
  };
  unsigned char z33d_cnttbl[12] = { /* Line 372, Address: 0x1027454 */
    1, 3, 3, 1, 1, 3, 1, 3, 3, 3, 3, 3
  };
  unsigned char z33d_cnttbl1[3] = { /* Line 375, Address: 0x1027488 */
    5, 1, 0
  };
  unsigned short z33d_kawatbl[3] = { /* Line 378, Address: 0x10274ac */
    24, 32767, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;


  if (scroll_start.b.h) return; /* Line 389, Address: 0x10274d0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 392, Address: 0x10274e0 */
  scrchk(); /* Line 393, Address: 0x102750c */
  scroll_h(); /* Line 394, Address: 0x1027518 */
  scroll_v(); /* Line 395, Address: 0x1027524 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 397, Address: 0x1027530 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 398, Address: 0x1027540 */


  scrollz_h(scra_hz * 16, 64); /* Line 401, Address: 0x1027550 */
  scrollc_h(scra_hz * 8 * 3, 16); /* Line 402, Address: 0x1027574 */
  scrollb_h(scra_hz * 4 * 3, 4); /* Line 403, Address: 0x10275ac */

  lD0.w.l = 536; /* Line 405, Address: 0x10275e4 */
  wD1 = 1312; /* Line 406, Address: 0x10275ec */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 407, Address: 0x10275f8 */

    wD1 -= scra_v_posit.w.h; /* Line 409, Address: 0x1027618 */
    wD1 >>= 1; /* Line 410, Address: 0x102762c */
    lD0.w.l -= wD1; /* Line 411, Address: 0x1027634 */
    if (lD0.w.l < 0) { /* Line 412, Address: 0x1027648 */
      lD0.w.l = 0; /* Line 413, Address: 0x102765c */
    }
  } /* Line 415, Address: 0x1027660 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 417, Address: 0x1027668 */
  }

  scrollb_v(lD0.w.l); /* Line 420, Address: 0x1027680 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 421, Address: 0x1027694 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 422, Address: 0x10276a4 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 423, Address: 0x10276b4 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 425, Address: 0x10276c4 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 426, Address: 0x10276e0 */
  scrflagz.b.h = 0; /* Line 427, Address: 0x10276fc */
  scrflagc.b.h = 0; /* Line 428, Address: 0x1027704 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 451, Address: 0x102770c */
  for (i = 0; i < 12; ++i) { /* Line 452, Address: 0x1027714 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 453, Address: 0x1027720 */
    ++pHscrWk; /* Line 454, Address: 0x1027738 */
  } /* Line 455, Address: 0x102773c */
  wD1 = 0; /* Line 456, Address: 0x102774c */
  for ( ; i < 76; ++i) { /* Line 457, Address: 0x1027750 */
    lD2.l = (wD1 << 8) + 32767 + 1; /* Line 458, Address: 0x1027758 */
    pHscrWk->l += lD2.l; /* Line 459, Address: 0x102777c */
    ++pHscrWk; /* Line 460, Address: 0x102778c */
    ++wD1; /* Line 461, Address: 0x1027790 */
  } /* Line 462, Address: 0x102779c */







  pHScrollWork = &hscrollwork[152]; /* Line 470, Address: 0x10277ac */
  lD0.w.h = -scra_h_posit.w.h; /* Line 471, Address: 0x10277b8 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 472, Address: 0x10277d8 */

  for (i = 0; i < 3; ++i) { /* Line 474, Address: 0x10277fc */
    *pHScrollWork++ = lD0.w.l; /* Line 475, Address: 0x1027808 */
  } /* Line 476, Address: 0x102781c */


  for (i = 0; i < 3; ++i) { /* Line 479, Address: 0x102782c */
    *pHScrollWork++ = lD0.w.l; /* Line 480, Address: 0x1027838 */
  } /* Line 481, Address: 0x102784c */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 483, Address: 0x102785c */

  for (i = 0; i < 6; ++i) { /* Line 485, Address: 0x1027880 */
    *pHScrollWork++ = lD0.w.l; /* Line 486, Address: 0x102788c */
  } /* Line 487, Address: 0x10278a0 */














  pHscrWk = (int_union*)hscrollwork; /* Line 502, Address: 0x10278b0 */
  for (i = 11; i >= 0; --i) { /* Line 503, Address: 0x10278b8 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 504, Address: 0x10278c4 */
    ++pHscrWk; /* Line 505, Address: 0x10278f0 */
    for (j = z33d_cnttbl[i]; j >= 0; --j) { /* Line 506, Address: 0x10278f4 */
      *pHScrollWork++ = wD1; /* Line 507, Address: 0x1027908 */
    } /* Line 508, Address: 0x1027918 */
  } /* Line 509, Address: 0x1027924 */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 512, Address: 0x1027930 */

  for (i = 0; i < 6; ++i) { /* Line 514, Address: 0x1027954 */
    *pHScrollWork++ = lD0.w.l; /* Line 515, Address: 0x1027960 */
  } /* Line 516, Address: 0x1027974 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 518, Address: 0x1027984 */

  for (i = 0; i < 6; ++i) { /* Line 520, Address: 0x10279a8 */
    *pHScrollWork++ = lD0.w.l; /* Line 521, Address: 0x10279b4 */
  } /* Line 522, Address: 0x10279c8 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 524, Address: 0x10279d8 */

  for (i = 0; i < 14; ++i) { /* Line 526, Address: 0x10279fc */
    *pHScrollWork++ = lD0.w.l; /* Line 527, Address: 0x1027a08 */
  } /* Line 528, Address: 0x1027a1c */


  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 531, Address: 0x1027a2c */
  lD2.l <<= 6; /* Line 532, Address: 0x1027a64 */
  lD2.l /= 24; /* Line 533, Address: 0x1027a70 */
  lD2.l <<= 10; /* Line 534, Address: 0x1027a90 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 535, Address: 0x1027a9c */

  for (i = 2; i >= 0; --i) { /* Line 537, Address: 0x1027aa8 */
    lD0.w.l = -lD3.w.h; /* Line 538, Address: 0x1027ab4 */
    for (j = z33d_cnttbl1[i]; j >= 0; --j) { /* Line 539, Address: 0x1027ad0 */
      *pHScrollWork++ = lD0.w.l; /* Line 540, Address: 0x1027ae4 */
    } /* Line 541, Address: 0x1027af8 */
    lD3.l = ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 542, Address: 0x1027b04 */
    lD3.l += lD2.l; /* Line 543, Address: 0x1027b28 */
    lD3.l = ((unsigned int)lD3.l >> 16) | (lD3.l << 16 & -65536); /* Line 544, Address: 0x1027b38 */
  } /* Line 545, Address: 0x1027b5c */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 547, Address: 0x1027b68 */

  for (i = 0; i < 8; ++i) { /* Line 549, Address: 0x1027b8c */
    *pHScrollWork++ = lD0.w.l; /* Line 550, Address: 0x1027b98 */
  } /* Line 551, Address: 0x1027bac */

  pHScrollBuff = lphscrollbuff; /* Line 553, Address: 0x1027bbc */
  pHScrollWork = &hscrollwork[152]; /* Line 554, Address: 0x1027bc8 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 555, Address: 0x1027bd4 */
  lD2.w.l = lD0.w.l; /* Line 556, Address: 0x1027be0 */
  wD4 = lD0.w.l; /* Line 557, Address: 0x1027be8 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 558, Address: 0x1027bf0 */
  wD3 = lD0.w.l >> 1; /* Line 559, Address: 0x1027c14 */
  wD1 = 87; /* Line 560, Address: 0x1027c30 */
  wD5 = 29; /* Line 561, Address: 0x1027c38 */
  if (wD1 <= wD3) { /* Line 562, Address: 0x1027c40 */

    wD1 -= wD3; /* Line 564, Address: 0x1027c54 */
    if (wD1 >= 27) { /* Line 565, Address: 0x1027c5c */
      wD1 = 28; /* Line 566, Address: 0x1027c6c */
    }

    wD5 -= wD1; /* Line 569, Address: 0x1027c74 */
    pHScrollWork += lD0.w.l / 2U; /* Line 570, Address: 0x1027c7c */
    waterdirec.w += 64; /* Line 571, Address: 0x1027ca0 */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z33d_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 573, Address: 0x1027cb4 */


  } /* Line 576, Address: 0x1027cdc */
  else {
    wD1 -= wD3; /* Line 578, Address: 0x1027ce4 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 583, Address: 0x1027cec */
  pHScrollWork = &hscrollwork[24]; /* Line 584, Address: 0x1027d00 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 585, Address: 0x1027d0c */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 586, Address: 0x1027d20 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 589, Address: 0x1027d38 */
    lD2.w.l = *pHScrollWork++; /* Line 590, Address: 0x1027d4c */
    lD2.w.l += scrb_h_posit.w.h; /* Line 591, Address: 0x1027d60 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 592, Address: 0x1027d74 */
    lD0.w.l = lD2.w.l; /* Line 593, Address: 0x1027d94 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 594, Address: 0x1027d9c */
    if (wD3 <= wD4) { /* Line 595, Address: 0x1027dbc */
      wD5 &= 255; /* Line 596, Address: 0x1027dd4 */
      wD3 = (char)awasintbl[wD5]; /* Line 597, Address: 0x1027ddc */
      wD3 += scra_h_posit.w.h; /* Line 598, Address: 0x1027e08 */
      wD3 = -wD3; /* Line 599, Address: 0x1027e1c */
      lD0.w.h = wD3; /* Line 600, Address: 0x1027e38 */
    }

    pHScrollBuff->l = lD0.l; /* Line 603, Address: 0x1027e3c */
    ++pHScrollBuff; /* Line 604, Address: 0x1027e48 */
    ++wD4; /* Line 605, Address: 0x1027e54 */
    ++wD5; /* Line 606, Address: 0x1027e60 */
  } while ((short)--wD1 >= 0); /* Line 607, Address: 0x1027e68 */

} /* Line 609, Address: 0x1027e8c */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 614, Address: 0x1027ec0 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 621, Address: 0x1027ef4 */
  pA1 = *ppA1; /* Line 622, Address: 0x1027f14 */
  pA2 = *ppA2; /* Line 623, Address: 0x1027f1c */

  if (*pA3 <= *pwD4) goto label6; /* Line 625, Address: 0x1027f24 */



label1:
  *pwD2 &= 7; /* Line 630, Address: 0x1027f48 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 631, Address: 0x1027f5c */

  lD0.w.l = *pA2++; /* Line 633, Address: 0x1027f88 */
  i = 8 - *pwD2; /* Line 634, Address: 0x1027f98 */
  goto label4; /* Line 635, Address: 0x1027fac */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 638, Address: 0x1027fb4 */


  if (*pA3 <= *pwD4) goto label7; /* Line 641, Address: 0x1027fd0 */



label3:
  lD0.w.l = *pA2++; /* Line 646, Address: 0x1027ff4 */
  *pwD4 += 8; /* Line 647, Address: 0x1028004 */


  i = 8; /* Line 650, Address: 0x1028018 */
label4:
  for ( ; i > 0; --i) { /* Line 652, Address: 0x102801c */


    pA1->l = lD0.l; /* Line 655, Address: 0x1028024 */
    ++pA1; /* Line 656, Address: 0x102802c */
  } /* Line 657, Address: 0x1028030 */
  if ((short)--wD1 >= 0) goto label2; /* Line 658, Address: 0x1028040 */



label5:
  *ppA1 = pA1; /* Line 663, Address: 0x1028068 */
  *ppA2 = pA2; /* Line 664, Address: 0x1028070 */
  return; /* Line 665, Address: 0x1028078 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 669, Address: 0x1028080 */
  if ((short)wD3 > 0) goto label8; /* Line 670, Address: 0x10280b0 */


  if (*pA3 > *pwD4) goto label1; /* Line 673, Address: 0x10280c8 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 676, Address: 0x10280ec */
  if ((short)wD3 > 0) goto label8; /* Line 677, Address: 0x102811c */
  goto label1; /* Line 678, Address: 0x1028134 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 686, Address: 0x102813c */
  if ((short)wD3 <= 0) goto label3; /* Line 687, Address: 0x102816c */



label8:
  --wD3; /* Line 692, Address: 0x1028184 */
  wD6 = wD3; /* Line 693, Address: 0x102818c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 694, Address: 0x1028190 */

  do {
    *pwD2 &= 255; /* Line 697, Address: 0x10281a8 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 698, Address: 0x10281bc */
    lD0.w.l += scrb_h_posit.w.h; /* Line 699, Address: 0x10281e8 */
    lD0.w.l = -lD0.w.l; /* Line 700, Address: 0x10281fc */
    pA1->w.h = lD0.w.h; /* Line 701, Address: 0x1028218 */
    pA1->w.l = lD0.w.l; /* Line 702, Address: 0x1028220 */
    ++pA1; /* Line 703, Address: 0x1028228 */
    ++*pwD4; /* Line 704, Address: 0x102822c */
    ++*pwD2; /* Line 705, Address: 0x1028240 */
  } while ((short)--wD3 >= 0); /* Line 706, Address: 0x1028254 */

  wD6 >>= 3; /* Line 708, Address: 0x1028278 */

  do {
    lD0.w.l = *pA2++; /* Line 711, Address: 0x1028280 */
    --wD1; /* Line 712, Address: 0x1028290 */
  } while ((short)--wD6 >= 0); /* Line 713, Address: 0x102829c */
  goto label2; /* Line 714, Address: 0x10282c0 */
} /* Line 715, Address: 0x10282c8 */















void scroll_h() { /* Line 731, Address: 0x10282f0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 734, Address: 0x10282fc */
  scrh_move(); /* Line 735, Address: 0x1028308 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 736, Address: 0x1028310 */
    scra_h_count ^= 16; /* Line 737, Address: 0x1028344 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 738, Address: 0x1028358 */
      scrflaga.b.h |= 4; /* Line 739, Address: 0x1028384 */
    } /* Line 740, Address: 0x1028398 */
    else {

      scrflaga.b.h |= 8; /* Line 743, Address: 0x10283a0 */
    }
  }


} /* Line 748, Address: 0x10283b4 */

void scrh_move() { /* Line 750, Address: 0x10283d0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 753, Address: 0x10283dc */
  wD0 -= scra_h_posit.w.h; /* Line 754, Address: 0x10283e8 */
  wD0 -= scra_hline; /* Line 755, Address: 0x10283fc */
  if (wD0 == 0) { /* Line 756, Address: 0x1028410 */

    scra_hz = 0; /* Line 758, Address: 0x102841c */
  } /* Line 759, Address: 0x1028424 */
  else if ((short)wD0 < 0) { /* Line 760, Address: 0x102842c */
    left_check(wD0); /* Line 761, Address: 0x1028444 */
  } /* Line 762, Address: 0x1028450 */
  else {
    right_check(wD0); /* Line 764, Address: 0x1028458 */
  }

} /* Line 767, Address: 0x1028464 */


void right_check(unsigned short wD0) { /* Line 770, Address: 0x1028480 */
  unsigned short wD1;

  if ((short)wD0 >= 17) { /* Line 773, Address: 0x102848c */
    wD0 = 16; /* Line 774, Address: 0x10284ac */
  }

  wD0 += scra_h_posit.w.h; /* Line 777, Address: 0x10284b4 */
  if (scralim_right < (short)wD0) { /* Line 778, Address: 0x10284cc */
    wD0 = scralim_right; /* Line 779, Address: 0x10284fc */
  }

  wD1 = wD0; /* Line 782, Address: 0x1028508 */
  wD1 -= scra_h_posit.w.h; /* Line 783, Address: 0x1028510 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 784, Address: 0x1028524 */
  scra_h_posit.w.h = wD0; /* Line 785, Address: 0x1028554 */
  scra_hz = wD1; /* Line 786, Address: 0x1028560 */

} /* Line 788, Address: 0x1028568 */


void left_check(unsigned short wD0) { /* Line 791, Address: 0x1028580 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 794, Address: 0x102858c */
    wD0 = -16; /* Line 795, Address: 0x10285ac */
  }

  wD0 += scra_h_posit.w.h; /* Line 798, Address: 0x10285b4 */
  if (scralim_left > (short)wD0) { /* Line 799, Address: 0x10285cc */
    wD0 = scralim_left; /* Line 800, Address: 0x10285fc */
  }

  wD1 = wD0; /* Line 803, Address: 0x1028608 */
  wD1 -= scra_h_posit.w.h; /* Line 804, Address: 0x1028610 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 805, Address: 0x1028624 */
  scra_h_posit.w.h = wD0; /* Line 806, Address: 0x1028654 */
  scra_hz = wD1; /* Line 807, Address: 0x1028660 */

} /* Line 809, Address: 0x1028668 */


















void scroll_v() { /* Line 828, Address: 0x1028680 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 831, Address: 0x102868c */
  if (actwk[0].cddat & 4) { /* Line 832, Address: 0x10286b8 */
    wD0 -= 5; /* Line 833, Address: 0x10286d0 */
  }

  if (actwk[0].cddat & 2) { /* Line 836, Address: 0x10286d8 */
    wD0 += 32; /* Line 837, Address: 0x10286f0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 838, Address: 0x10286f8 */
      wD0 -= scra_vline; /* Line 839, Address: 0x1028718 */
      sv_move_main2(wD0); /* Line 840, Address: 0x102872c */
      return; /* Line 841, Address: 0x1028738 */
    }
    wD0 -= scra_vline; /* Line 843, Address: 0x1028740 */
    if (wD0 >= 64) { /* Line 844, Address: 0x1028754 */
      wD0 -= 64; /* Line 845, Address: 0x1028764 */
      sv_move_main2(wD0); /* Line 846, Address: 0x102876c */
      return; /* Line 847, Address: 0x1028778 */
    }
    wD0 -= 64; /* Line 849, Address: 0x1028780 */
    if (limmoveflag == 0) goto label1; /* Line 850, Address: 0x1028788 */
    sv_move_sub2(); /* Line 851, Address: 0x102879c */
    return; /* Line 852, Address: 0x10287a4 */
  }




  wD0 -= scra_vline; /* Line 858, Address: 0x10287ac */
  if (wD0 != 0) { /* Line 859, Address: 0x10287c0 */
    sv_move_main(wD0); /* Line 860, Address: 0x10287c8 */
    return; /* Line 861, Address: 0x10287d4 */
  }
  if (limmoveflag == 0) { /* Line 863, Address: 0x10287dc */
    sv_move_sub2(); /* Line 864, Address: 0x10287f0 */
    return; /* Line 865, Address: 0x10287f8 */
  }


label1:
  scra_vz = 0; /* Line 870, Address: 0x1028800 */

} /* Line 872, Address: 0x1028808 */





void sv_move_main(unsigned short wD0) { /* Line 878, Address: 0x1028820 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 881, Address: 0x1028830 */
    sv_move_main1(wD0); /* Line 882, Address: 0x102884c */
  } /* Line 883, Address: 0x1028858 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 886, Address: 0x1028860 */
    if ((short)wD1 < 0) { /* Line 887, Address: 0x102886c */
      wD1 = -wD1; /* Line 888, Address: 0x1028884 */
    }

    if (wD1 >= 2048) { /* Line 891, Address: 0x10288a0 */
      sv_move_main2(wD0); /* Line 892, Address: 0x10288b0 */
    } /* Line 893, Address: 0x10288bc */
    else {
      if ((short)wD0 >= 7) { /* Line 895, Address: 0x10288c4 */
        sv_move_plus(1536); /* Line 896, Address: 0x10288e4 */
      } /* Line 897, Address: 0x10288f0 */
      else if ((short)wD0 < -6) { /* Line 898, Address: 0x10288f8 */
        sv_move_minus(1536); /* Line 899, Address: 0x1028918 */
      } /* Line 900, Address: 0x1028924 */
      else {
        sv_move_sub(wD0); /* Line 902, Address: 0x102892c */
      }
    }
  }
} /* Line 906, Address: 0x1028938 */



void sv_move_main1(unsigned short wD0) { /* Line 910, Address: 0x1028950 */

  if ((short)wD0 >= 3) { /* Line 912, Address: 0x102895c */
    sv_move_plus(512); /* Line 913, Address: 0x102897c */
  } /* Line 914, Address: 0x1028988 */
  else if ((short)wD0 < -2) { /* Line 915, Address: 0x1028990 */
    sv_move_minus(512); /* Line 916, Address: 0x10289b0 */
  } /* Line 917, Address: 0x10289bc */
  else {
    sv_move_sub(wD0); /* Line 919, Address: 0x10289c4 */
  }

} /* Line 922, Address: 0x10289d0 */


void sv_move_main2(unsigned short wD0) { /* Line 925, Address: 0x10289e0 */

  if ((short)wD0 >= 17) { /* Line 927, Address: 0x10289ec */
    sv_move_plus(4096); /* Line 928, Address: 0x1028a0c */
  } /* Line 929, Address: 0x1028a18 */
  else if ((short)wD0 < -16) { /* Line 930, Address: 0x1028a20 */
    sv_move_minus(4096); /* Line 931, Address: 0x1028a40 */
  } /* Line 932, Address: 0x1028a4c */
  else {
    sv_move_sub(wD0); /* Line 934, Address: 0x1028a54 */
  }

} /* Line 937, Address: 0x1028a60 */


void sv_move_sub2() { /* Line 940, Address: 0x1028a70 */
  limmoveflag = 0; /* Line 941, Address: 0x1028a78 */
  sv_move_sub(0); /* Line 942, Address: 0x1028a80 */
} /* Line 943, Address: 0x1028a8c */


void sv_move_sub(unsigned short wD0) { /* Line 946, Address: 0x1028aa0 */
  int_union lD1;

  lD1.w.h = 0; /* Line 949, Address: 0x1028aac */
  lD1.w.l = wD0; /* Line 950, Address: 0x1028ab0 */
  lD1.l += scra_v_posit.w.h; /* Line 951, Address: 0x1028ab8 */
  if ((short)wD0 > 0) { /* Line 952, Address: 0x1028ad4 */
    scrv_down_ch(lD1); /* Line 953, Address: 0x1028af0 */
  } /* Line 954, Address: 0x1028afc */
  else {
    scrv_up_ch(lD1); /* Line 956, Address: 0x1028b04 */
  }

} /* Line 959, Address: 0x1028b10 */




void sv_move_minus(unsigned short wD1) { /* Line 964, Address: 0x1028b20 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 968, Address: 0x1028b30 */
  lD1.l <<= 8; /* Line 969, Address: 0x1028b4c */
  lD1.l += scra_v_posit.l; /* Line 970, Address: 0x1028b58 */

  wk = lD1.w.h; /* Line 972, Address: 0x1028b6c */
  lD1.w.h = lD1.w.l; /* Line 973, Address: 0x1028b74 */
  lD1.w.l = wk; /* Line 974, Address: 0x1028b7c */
  scrv_up_ch(lD1); /* Line 975, Address: 0x1028b80 */
} /* Line 976, Address: 0x1028b8c */



void scrv_up_ch(int_union lD1) { /* Line 980, Address: 0x1028ba0 */
  if (scralim_up >= lD1.w.l) { /* Line 981, Address: 0x1028bac */
    if (lD1.w.l < -255) { /* Line 982, Address: 0x1028bd4 */
      lD1.w.l &= 2047; /* Line 983, Address: 0x1028bec */
      actwk[0].yposi.w.h &= 32767; /* Line 984, Address: 0x1028bf8 */
      scra_v_posit.w.h &= 2047; /* Line 985, Address: 0x1028c0c */
      scrb_v_posit.w.h &= 1023; /* Line 986, Address: 0x1028c20 */
    } /* Line 987, Address: 0x1028c34 */
    else {

      lD1.w.l = scralim_up; /* Line 990, Address: 0x1028c3c */
    }
  }
  scrv_move(lD1); /* Line 993, Address: 0x1028c48 */

} /* Line 995, Address: 0x1028c54 */





void sv_move_plus(unsigned short wD1) { /* Line 1001, Address: 0x1028c70 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1005, Address: 0x1028c80 */
  lD1.w.l = wD1; /* Line 1006, Address: 0x1028c84 */
  lD1.l <<= 8; /* Line 1007, Address: 0x1028c8c */
  lD1.l += scra_v_posit.l; /* Line 1008, Address: 0x1028c98 */

  wk = lD1.w.h; /* Line 1010, Address: 0x1028cac */
  lD1.w.h = lD1.w.l; /* Line 1011, Address: 0x1028cb4 */
  lD1.w.l = wk; /* Line 1012, Address: 0x1028cbc */

  scrv_down_ch(lD1); /* Line 1014, Address: 0x1028cc0 */

} /* Line 1016, Address: 0x1028ccc */



void scrv_down_ch(int_union lD1) { /* Line 1020, Address: 0x1028ce0 */
  if (scralim_down <= lD1.w.l) { /* Line 1021, Address: 0x1028cec */
    lD1.w.l -= 2048; /* Line 1022, Address: 0x1028d14 */
    if (lD1.w.l > 0) { /* Line 1023, Address: 0x1028d20 */
      actwk[0].yposi.w.h &= 2047; /* Line 1024, Address: 0x1028d34 */
      scra_v_posit.w.h -= 2048; /* Line 1025, Address: 0x1028d48 */
      scrb_v_posit.w.h &= 1023; /* Line 1026, Address: 0x1028d5c */
    } /* Line 1027, Address: 0x1028d70 */
    else {
      lD1.w.l = scralim_down; /* Line 1029, Address: 0x1028d78 */
    }
  }
  scrv_move(lD1); /* Line 1032, Address: 0x1028d84 */

} /* Line 1034, Address: 0x1028d90 */


void scrv_move(int_union lD1) { /* Line 1037, Address: 0x1028da0 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1040, Address: 0x1028db0 */

  wk = lD1.w.h; /* Line 1042, Address: 0x1028dbc */
  lD1.w.h = lD1.w.l; /* Line 1043, Address: 0x1028dc4 */
  lD1.w.l = wk; /* Line 1044, Address: 0x1028dcc */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1046, Address: 0x1028dd0 */
  scra_v_posit.l = lD1.l; /* Line 1047, Address: 0x1028df8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1050, Address: 0x1028e04 */
    scra_v_count ^= 16; /* Line 1051, Address: 0x1028e38 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1052, Address: 0x1028e4c */

      scrflaga.b.h |= 2; /* Line 1054, Address: 0x1028e78 */
    } /* Line 1055, Address: 0x1028e8c */
    else {
      scrflaga.b.h |= 1; /* Line 1057, Address: 0x1028e94 */
    }
  }


} /* Line 1062, Address: 0x1028ea8 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1066, Address: 0x1028ec0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1069, Address: 0x1028ecc */
  lD0.l += lD4.l; /* Line 1070, Address: 0x1028edc */
  scrb_h_posit.l = lD0.l; /* Line 1071, Address: 0x1028eec */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1073, Address: 0x1028ef8 */

    scrb_h_count ^= 16; /* Line 1075, Address: 0x1028f2c */
    lD0.l -= lD2.l; /* Line 1076, Address: 0x1028f40 */
    if ((long int)lD0.l < 0) { /* Line 1077, Address: 0x1028f50 */
      scrflagb.b.h |= 4; /* Line 1078, Address: 0x1028f64 */
    } /* Line 1079, Address: 0x1028f78 */
    else {

      scrflagb.b.h |= 8; /* Line 1082, Address: 0x1028f80 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1087, Address: 0x1028f94 */
  lD0.l += lD5.l; /* Line 1088, Address: 0x1028fa4 */
  scrb_h_posit.l = lD0.l; /* Line 1089, Address: 0x1028fb4 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1091, Address: 0x1028fc0 */

    scrb_v_count ^= 16; /* Line 1093, Address: 0x1028ff4 */
    lD0.l -= lD3.l; /* Line 1094, Address: 0x1029008 */
    if ((long int)lD0.l < 0) { /* Line 1095, Address: 0x1029018 */
      scrflagb.b.h |= 1; /* Line 1096, Address: 0x102902c */
    } /* Line 1097, Address: 0x1029040 */
    else {

      scrflagb.b.h |= 2; /* Line 1100, Address: 0x1029048 */
    }
  }


} /* Line 1105, Address: 0x102905c */






void scrollb_v(unsigned short wD0) { /* Line 1112, Address: 0x1029070 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1115, Address: 0x102907c */
  scrb_v_posit.w.h = wD0; /* Line 1116, Address: 0x1029088 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1118, Address: 0x1029094 */
    scrb_v_count ^= 16; /* Line 1119, Address: 0x10290c0 */
    if ((short)wD3 > (short)wD0) { /* Line 1120, Address: 0x10290d4 */
      scrflagb.b.h |= 1; /* Line 1121, Address: 0x1029104 */
    } /* Line 1122, Address: 0x1029118 */
    else {

      scrflagb.b.h |= 2; /* Line 1125, Address: 0x1029120 */
    }
  }


} /* Line 1130, Address: 0x1029134 */



void scrollb_h(int lD4, int flagb) { /* Line 1134, Address: 0x1029150 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1138, Address: 0x1029160 */
  lD0.l = lD2.l + lD4; /* Line 1139, Address: 0x102916c */
  scrb_h_posit.l = lD0.l; /* Line 1140, Address: 0x102917c */

  lD1.w.h = lD0.w.l; /* Line 1142, Address: 0x1029188 */
  lD1.w.l = lD0.w.h; /* Line 1143, Address: 0x1029190 */
  lD1.w.l &= 16; /* Line 1144, Address: 0x1029198 */

  bD3 = scrb_h_count; /* Line 1146, Address: 0x10291a4 */
  lD1.b.b4 ^= bD3; /* Line 1147, Address: 0x10291b0 */
  if (!lD1.b.b4) { /* Line 1148, Address: 0x10291c4 */
    scrb_h_count ^= 16; /* Line 1149, Address: 0x10291d0 */
    lD0.l -= lD2.l; /* Line 1150, Address: 0x10291e4 */
    if ((long int)lD0.l < 0) { /* Line 1151, Address: 0x10291f4 */
      scrflagb.b.h |= flagb; /* Line 1152, Address: 0x1029208 */
    } /* Line 1153, Address: 0x1029224 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1156, Address: 0x102922c */
    }
  }


} /* Line 1161, Address: 0x102924c */



void scrollc_h(int lD4, int flagc) { /* Line 1165, Address: 0x1029260 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1169, Address: 0x1029270 */
  lD0.l = lD2.l + lD4; /* Line 1170, Address: 0x102927c */
  scrc_h_posit.l = lD0.l; /* Line 1171, Address: 0x102928c */

  lD1.w.h = lD0.w.l; /* Line 1173, Address: 0x1029298 */
  lD1.w.l = lD0.w.h; /* Line 1174, Address: 0x10292a0 */
  lD1.w.l &= 16; /* Line 1175, Address: 0x10292a8 */

  bD3 = scrc_h_count; /* Line 1177, Address: 0x10292b4 */
  lD1.b.b4 ^= bD3; /* Line 1178, Address: 0x10292c0 */
  if (!lD1.b.b4) { /* Line 1179, Address: 0x10292d4 */
    scrc_h_count ^= 16; /* Line 1180, Address: 0x10292e0 */
    lD0.l -= lD2.l; /* Line 1181, Address: 0x10292f4 */
    if ((long int)lD0.l < 0) { /* Line 1182, Address: 0x1029304 */
      scrflagc.b.h |= flagc; /* Line 1183, Address: 0x1029318 */
    } /* Line 1184, Address: 0x1029334 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1187, Address: 0x102933c */
    }
  }


} /* Line 1192, Address: 0x102935c */











void scrollz_h(int lD4, int flagz) { /* Line 1204, Address: 0x1029370 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1208, Address: 0x1029380 */
  lD0.l = lD2.l + lD4; /* Line 1209, Address: 0x102938c */
  scrz_h_posit.l = lD0.l; /* Line 1210, Address: 0x102939c */

  lD1.w.h = lD0.w.l; /* Line 1212, Address: 0x10293a8 */
  lD1.w.l = lD0.w.h; /* Line 1213, Address: 0x10293b0 */
  lD1.w.l &= 16; /* Line 1214, Address: 0x10293b8 */

  bD3 = scrz_h_count; /* Line 1216, Address: 0x10293c4 */
  lD1.b.b4 ^= bD3; /* Line 1217, Address: 0x10293d0 */
  if (!lD1.b.b4) { /* Line 1218, Address: 0x10293e4 */
    scrz_h_count ^= 16; /* Line 1219, Address: 0x10293f0 */
    lD0.l -= lD2.l; /* Line 1220, Address: 0x1029404 */
    if ((long int)lD0.l < 0) { /* Line 1221, Address: 0x1029414 */
      scrflagz.b.h |= flagz; /* Line 1222, Address: 0x1029428 */
    } /* Line 1223, Address: 0x1029444 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1226, Address: 0x102944c */
    }
  }


} /* Line 1231, Address: 0x102946c */














void scrollwrtadva() { /* Line 1246, Address: 0x1029480 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1252, Address: 0x102949c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1253, Address: 0x10294a0 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1254, Address: 0x10294ac */
  pMapWk = (unsigned char*)mapwkb; /* Line 1255, Address: 0x10294b8 */
  pScrFlag = &scrflagb.b.h; /* Line 1256, Address: 0x10294c0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1257, Address: 0x10294c8 */







} /* Line 1265, Address: 0x10294dc */












void scrollwrt() { /* Line 1278, Address: 0x1029500 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1287, Address: 0x1029520 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1288, Address: 0x1029524 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1289, Address: 0x1029530 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1290, Address: 0x102953c */
  pScrFlag = &scrflagbw.b.h; /* Line 1291, Address: 0x1029544 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1292, Address: 0x102954c */

  VramBase = 16384; /* Line 1294, Address: 0x1029560 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1295, Address: 0x1029564 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1296, Address: 0x1029570 */
  pMapWk = (unsigned char*)mapwka; /* Line 1297, Address: 0x102957c */
  pScrFlag = &scrflagaw.b.h; /* Line 1298, Address: 0x1029584 */

  if (*pScrFlag) { /* Line 1300, Address: 0x102958c */
    if (*pScrFlag & 1) { /* Line 1301, Address: 0x1029598 */
      *pScrFlag &= 254; /* Line 1302, Address: 0x10295ac */

      lD4.l = -16; /* Line 1304, Address: 0x10295b8 */
      wD5 = 65520; /* Line 1305, Address: 0x10295c0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1307, Address: 0x10295c8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1309, Address: 0x10295e8 */
    }




    if (*pScrFlag & 2) { /* Line 1315, Address: 0x1029614 */
      *pScrFlag &= 253; /* Line 1316, Address: 0x1029628 */

      lD4.l = 224; /* Line 1318, Address: 0x1029634 */
      wD5 = 65520; /* Line 1319, Address: 0x102963c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1320, Address: 0x1029644 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1322, Address: 0x1029664 */
    }




    if (*pScrFlag & 4) { /* Line 1328, Address: 0x1029690 */
      *pScrFlag &= 251; /* Line 1329, Address: 0x10296a4 */

      lD4.l = -16; /* Line 1331, Address: 0x10296b0 */
      wD5 = 65520; /* Line 1332, Address: 0x10296b8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1333, Address: 0x10296c0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1335, Address: 0x10296e0 */
    }




    if (*pScrFlag & 8) { /* Line 1341, Address: 0x102970c */
      *pScrFlag &= 247; /* Line 1342, Address: 0x1029720 */

      lD4.l = -16; /* Line 1344, Address: 0x102972c */
      wD5 = 320; /* Line 1345, Address: 0x1029734 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1346, Address: 0x102973c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1348, Address: 0x102975c */
    }
  }






} /* Line 1357, Address: 0x1029788 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1374, Address: 0x10297b0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1385, Address: 0x10297dc */

  if (*pScrFlag & 1) { /* Line 1387, Address: 0x10297e4 */
    *pScrFlag &= 254; /* Line 1388, Address: 0x10297fc */
  } /* Line 1389, Address: 0x1029810 */
  else {
    *pScrFlag &= 254; /* Line 1391, Address: 0x1029818 */

    if (*pScrFlag & 2) { /* Line 1393, Address: 0x102982c */
      *pScrFlag &= 253; /* Line 1394, Address: 0x1029844 */
      lD4.w.l = 224; /* Line 1395, Address: 0x1029858 */
    } /* Line 1396, Address: 0x1029860 */
    else {
      *pScrFlag &= 253; /* Line 1398, Address: 0x1029868 */
      goto label1; /* Line 1399, Address: 0x102987c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1404, Address: 0x1029884 */
  wD0 &= 127; /* Line 1405, Address: 0x10298d4 */
  wD0 = z33dwrttbl[wD0 + 1]; /* Line 1406, Address: 0x10298dc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1412, Address: 0x10298fc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1413, Address: 0x102991c */
  if (wD0 != 0) { /* Line 1414, Address: 0x1029940 */
    wD5 = 65520; /* Line 1415, Address: 0x102994c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1416, Address: 0x1029954 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1418, Address: 0x1029974 */



  } /* Line 1422, Address: 0x10299a0 */
  else {

    wD5 = 0; /* Line 1425, Address: 0x10299a8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1426, Address: 0x10299ac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1430, Address: 0x10299cc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1437, Address: 0x10299f8 */






    lD4.l = -16; /* Line 1444, Address: 0x1029a0c */
    wD5 = 65520; /* Line 1445, Address: 0x1029a14 */
    if (*pScrFlag & 168) { /* Line 1446, Address: 0x1029a1c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1447, Address: 0x1029a34 */
      wD5 = 320; /* Line 1448, Address: 0x1029a54 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1452, Address: 0x1029a5c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1454, Address: 0x1029a8c */
    if (WrtTblCnt >= 114) WrtTblCnt = 113; /* Line 1455, Address: 0x1029a98 */



    for (i = 0; i < 16; ++i) { /* Line 1459, Address: 0x1029aa8 */
      wD0 = z33dwrttbl[WrtTblCnt++]; /* Line 1460, Address: 0x1029ab4 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1461, Address: 0x1029ad4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1462, Address: 0x1029b00 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1463, Address: 0x1029b20 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1465, Address: 0x1029b44 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1468, Address: 0x1029b68 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1470, Address: 0x1029b88 */
      }
      lD4.w.l += 16; /* Line 1472, Address: 0x1029b9c */
    } /* Line 1473, Address: 0x1029ba8 */
    *pScrFlag = 0; /* Line 1474, Address: 0x1029bb8 */
  }
} /* Line 1476, Address: 0x1029bc0 */







void scrollwrtc() {} /* Line 1484, Address: 0x1029bf0 */




void scrollwrtz() {} /* Line 1489, Address: 0x1029c00 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1510, Address: 0x1029c10 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1523, Address: 0x1029c38 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1526, Address: 0x1029c58 */
    pTilePoint->x += 2; /* Line 1527, Address: 0x1029c6c */
    if (pTilePoint->x >= 64) { /* Line 1528, Address: 0x1029c80 */
      pTilePoint->x -= 64; /* Line 1529, Address: 0x1029c94 */
    }
    xOffs += 16; /* Line 1531, Address: 0x1029ca8 */
  } while (--lpcnt >= 0); /* Line 1532, Address: 0x1029cb4 */
} /* Line 1533, Address: 0x1029cc8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1537, Address: 0x1029ce0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1541, Address: 0x1029d08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1544, Address: 0x1029d28 */
    pTilePoint->x += 2; /* Line 1545, Address: 0x1029d3c */
    if (pTilePoint->x >= 64) { /* Line 1546, Address: 0x1029d50 */
      pTilePoint->x -= 64; /* Line 1547, Address: 0x1029d64 */
    }
    xOffs += 16; /* Line 1549, Address: 0x1029d78 */
  } while (--lpcnt >= 0); /* Line 1550, Address: 0x1029d84 */
} /* Line 1551, Address: 0x1029d98 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1570, Address: 0x1029db0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1574, Address: 0x1029dd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1577, Address: 0x1029df8 */
    pTilePoint->y += 2; /* Line 1578, Address: 0x1029e0c */
    if (pTilePoint->y >= 32) { /* Line 1579, Address: 0x1029e1c */
      pTilePoint->y -= 32; /* Line 1580, Address: 0x1029e30 */
    }
    yOffs += 16; /* Line 1582, Address: 0x1029e40 */
  } while (--lpcnt >= 0); /* Line 1583, Address: 0x1029e4c */
} /* Line 1584, Address: 0x1029e60 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1603, Address: 0x1029e70 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1609, Address: 0x1029ea4 */

    base = 1; /* Line 1611, Address: 0x1029eb4 */
  } /* Line 1612, Address: 0x1029eb8 */
  else if (VramBase == 16384) { /* Line 1613, Address: 0x1029ec0 */

    base = 0; /* Line 1615, Address: 0x1029ed0 */
  }
  x = pTilePoint->x; /* Line 1617, Address: 0x1029ed4 */
  y = pTilePoint->y; /* Line 1618, Address: 0x1029edc */


  frip = BlkIndex & 6144; /* Line 1621, Address: 0x1029ee4 */
  BlkIndex &= 1023; /* Line 1622, Address: 0x1029eec */
  if (frip == 6144) { /* Line 1623, Address: 0x1029ef8 */

    p0 = 3, p1 = 2; /* Line 1625, Address: 0x1029f04 */
    p2 = 1, p3 = 0; /* Line 1626, Address: 0x1029f0c */
  } /* Line 1627, Address: 0x1029f14 */
  else if (frip & 4096) { /* Line 1628, Address: 0x1029f1c */

    p0 = 2, p1 = 3; /* Line 1630, Address: 0x1029f28 */
    p2 = 0, p3 = 1; /* Line 1631, Address: 0x1029f30 */
  } /* Line 1632, Address: 0x1029f38 */
  else if (frip & 2048) { /* Line 1633, Address: 0x1029f40 */

    p0 = 1, p1 = 0; /* Line 1635, Address: 0x1029f4c */
    p2 = 3, p3 = 2; /* Line 1636, Address: 0x1029f54 */
  } /* Line 1637, Address: 0x1029f5c */
  else {

    p0 = 0, p1 = 1; /* Line 1640, Address: 0x1029f64 */
    p2 = 2, p3 = 3; /* Line 1641, Address: 0x1029f6c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1644, Address: 0x1029f74 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1645, Address: 0x1029fb8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1646, Address: 0x1029ffc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1647, Address: 0x102a040 */

} /* Line 1649, Address: 0x102a084 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1667, Address: 0x102a0c0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1668, Address: 0x102a0e0 */
} /* Line 1669, Address: 0x102a100 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1671, Address: 0x102a110 */
  wH_posiw = 0; /* Line 1672, Address: 0x102a130 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1673, Address: 0x102a134 */
} /* Line 1674, Address: 0x102a154 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1681, Address: 0x102a170 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1687, Address: 0x102a1a0 */
  yOffs += wV_posiw; /* Line 1688, Address: 0x102a1b0 */





  if ((short)xOffs < 0) /* Line 1694, Address: 0x102a1c0 */
    xOffs = 0; /* Line 1695, Address: 0x102a1dc */
  if ((short)yOffs < 0) /* Line 1696, Address: 0x102a1e0 */
    yOffs = 0; /* Line 1697, Address: 0x102a1fc */
  if ((short)xOffs >= 16384) /* Line 1698, Address: 0x102a200 */
    xOffs = 16383; /* Line 1699, Address: 0x102a220 */
  if ((short)yOffs >= 2048) /* Line 1700, Address: 0x102a228 */
    yOffs = 2047; /* Line 1701, Address: 0x102a248 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1702, Address: 0x102a250 */
  if (i < 0) i = 0; /* Line 1703, Address: 0x102a298 */

  ScreenNo = pMapWk[i] & 127; /* Line 1705, Address: 0x102a2a4 */

  if (ScreenNo) { /* Line 1707, Address: 0x102a2c0 */




    xOffs &= 32767; /* Line 1712, Address: 0x102a2c8 */
    yOffs &= 32767; /* Line 1713, Address: 0x102a2d4 */


    xBlk = xOffs; /* Line 1716, Address: 0x102a2e0 */
    xBlk %= 256; /* Line 1717, Address: 0x102a2e8 */
    xBlk /= 16; /* Line 1718, Address: 0x102a308 */
    yBlk = yOffs; /* Line 1719, Address: 0x102a324 */
    yBlk %= 256; /* Line 1720, Address: 0x102a32c */
    yBlk /= 16; /* Line 1721, Address: 0x102a34c */

    lpw = pmapwk; /* Line 1723, Address: 0x102a368 */
    lpw += xBlk; /* Line 1724, Address: 0x102a370 */
    lpw += yBlk * 16; /* Line 1725, Address: 0x102a378 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1726, Address: 0x102a384 */
    *pIndex = *lpw; /* Line 1727, Address: 0x102a39c */

    return 1; /* Line 1729, Address: 0x102a3ac */
  }

  *pIndex = 0; /* Line 1732, Address: 0x102a3b8 */
  return 0; /* Line 1733, Address: 0x102a3c0 */
} /* Line 1734, Address: 0x102a3c4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1754, Address: 0x102a3f0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1762, Address: 0x102a418 */
  if (ScreenNo) { /* Line 1763, Address: 0x102a47c */





    xBlk = xOffs; /* Line 1769, Address: 0x102a484 */
    xBlk %= 256; /* Line 1770, Address: 0x102a48c */
    xBlk /= 16; /* Line 1771, Address: 0x102a4ac */
    yBlk = yOffs; /* Line 1772, Address: 0x102a4c8 */
    yBlk %= 256; /* Line 1773, Address: 0x102a4d0 */
    yBlk /= 16; /* Line 1774, Address: 0x102a4f0 */


    lpw = pmapwk; /* Line 1777, Address: 0x102a50c */
    lpw += xBlk; /* Line 1778, Address: 0x102a514 */
    lpw += yBlk * 16; /* Line 1779, Address: 0x102a51c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1780, Address: 0x102a528 */
    *ppBlockNo = lpw; /* Line 1781, Address: 0x102a540 */
    *pIndex = *lpw; /* Line 1782, Address: 0x102a548 */




    return 1; /* Line 1787, Address: 0x102a558 */
  }

  *pIndex = 0; /* Line 1790, Address: 0x102a564 */
  return 0; /* Line 1791, Address: 0x102a56c */
} /* Line 1792, Address: 0x102a570 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1806, Address: 0x102a590 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1813, Address: 0x102a5ac */
  pMapWk = (unsigned char*)mapwka; /* Line 1814, Address: 0x102a5b0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1815, Address: 0x102a5b8 */
    *pBlockIndex = BlockNo; /* Line 1816, Address: 0x102a5dc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1817, Address: 0x102a5e8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1818, Address: 0x102a600 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1819, Address: 0x102a614 */
    }
  }


} /* Line 1824, Address: 0x102a62c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1838, Address: 0x102a650 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1839, Address: 0x102a65c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1840, Address: 0x102a688 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1841, Address: 0x102a6d4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1842, Address: 0x102a700 */

          return 0; /* Line 1844, Address: 0x102a74c */
        }
      }
    }
  }

  return 1; /* Line 1850, Address: 0x102a758 */
} /* Line 1851, Address: 0x102a75c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1868, Address: 0x102a770 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1869, Address: 0x102a78c */

} /* Line 1871, Address: 0x102a7a8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1873, Address: 0x102a7c0 */
  wH_posiw = 0; /* Line 1874, Address: 0x102a7dc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1875, Address: 0x102a7e0 */

} /* Line 1877, Address: 0x102a7fc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1879, Address: 0x102a810 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1880, Address: 0x102a824 */

} /* Line 1882, Address: 0x102a840 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1884, Address: 0x102a850 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1885, Address: 0x102a86c */

} /* Line 1887, Address: 0x102a888 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1889, Address: 0x102a8a0 */
  xOffs += wH_posiw; /* Line 1890, Address: 0x102a8b8 */
  yOffs += wV_posiw; /* Line 1891, Address: 0x102a8c8 */
  yOffs &= 240; /* Line 1892, Address: 0x102a8d8 */
  xOffs &= 496; /* Line 1893, Address: 0x102a8e4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1895, Address: 0x102a8f0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1896, Address: 0x102a91c */


} /* Line 1899, Address: 0x102a948 */















void mapwrt() { /* Line 1915, Address: 0x102a960 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1920, Address: 0x102a978 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1921, Address: 0x102a984 */
  pMapWk = (unsigned char*)mapwka; /* Line 1922, Address: 0x102a990 */
  VramBase = 16384; /* Line 1923, Address: 0x102a998 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1924, Address: 0x102a99c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1928, Address: 0x102a9b4 */
  VramBase = 24576; /* Line 1929, Address: 0x102a9bc */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1930, Address: 0x102a9c0 */

} /* Line 1932, Address: 0x102a9d0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1935, Address: 0x102a9f0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1936, Address: 0x102aa08 */
} /* Line 1937, Address: 0x102aa28 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1942, Address: 0x102aa40 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1946, Address: 0x102aa60 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1949, Address: 0x102aa7c */



    wD4 += 16; /* Line 1953, Address: 0x102aaa4 */
  } while ((short)--wD6 >= 0); /* Line 1954, Address: 0x102aab0 */

} /* Line 1956, Address: 0x102aad8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1961, Address: 0x102aaf0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1964, Address: 0x102ab0c */
  wD6 = 15; /* Line 1965, Address: 0x102ab14 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1968, Address: 0x102ab1c */

    mapwrt_sub(z33dwrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1970, Address: 0x102ab40 */
    wD4 += 16; /* Line 1971, Address: 0x102ab60 */
  } while ((short)--wD6 >= 0); /* Line 1972, Address: 0x102ab68 */
} /* Line 1973, Address: 0x102ab8c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1999, Address: 0x102abb0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2004, Address: 0x102abd8 */
  wD0 = pWrttbl[wD0]; /* Line 2005, Address: 0x102abe8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2007, Address: 0x102ac04 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2008, Address: 0x102ac28 */
  if (wD0) { /* Line 2009, Address: 0x102ac50 */
    wD5 = 65520; /* Line 2010, Address: 0x102ac5c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2011, Address: 0x102ac64 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2014, Address: 0x102ac80 */



  } /* Line 2018, Address: 0x102aca8 */
  else {

    wD5 = 0; /* Line 2021, Address: 0x102acb0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2022, Address: 0x102acb4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2026, Address: 0x102acd0 */
  }





} /* Line 2033, Address: 0x102acf8 */




void mapinit() { /* Line 2038, Address: 0x102ad20 */





  mapset(); /* Line 2044, Address: 0x102ad28 */


  colorset2(mapinittbl.colorno2); /* Line 2047, Address: 0x102ad30 */
  colorset(mapinittbl.colorno2); /* Line 2048, Address: 0x102ad44 */






  if (plflag != 0) { /* Line 2055, Address: 0x102ad58 */
    enecginit(); /* Line 2056, Address: 0x102ad6c */
  }

  if (play_start & 2) { /* Line 2059, Address: 0x102ad74 */

    divdevset(); /* Line 2061, Address: 0x102ad8c */
  }


} /* Line 2065, Address: 0x102ad94 */









void mapset() {} /* Line 2075, Address: 0x102adb0 */
