#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3C.H"

static unsigned char z32cwrttbl[49] = {
  0, 0, 0, 0, 0, 0, 6, 6, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  2, 2, 2, 6, 6, 4, 4, 4, 2, 0,
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
extern map_init_data mapinittbl;








































































void enecginit(void) {} /* Line 111, Address: 0x1026fc0 */



void divdevset() {} /* Line 115, Address: 0x1026fd0 */




















































sprite_status* main_chk(void) {
  if (main_play == 0) { /* Line 169, Address: 0x1026fe0 */
    return &actwk[0]; /* Line 170, Address: 0x1026ff4 */
  }
  return &actwk[1]; /* Line 172, Address: 0x1027004 */
} /* Line 173, Address: 0x102700c */












void scr_set(void) { /* Line 186, Address: 0x1027020 */





  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x102702c */
    4, 0, 9879, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1027060 */

  i = 0; /* Line 199, Address: 0x10270a8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x10270ac */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x10270c8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x10270dc */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x10270f8 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x102710c */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1027128 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x102713c */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1027158 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x102716c */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x1027188 */
  scra_h_count = 16; /* Line 211, Address: 0x10271ac */
  scra_v_count = 16; /* Line 212, Address: 0x10271b8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x10271c4 */
  scra_hline = 160; /* Line 215, Address: 0x10271e0 */

  playposiset(); /* Line 217, Address: 0x10271ec */
} /* Line 218, Address: 0x10271f4 */











void playposiset(void) { /* Line 230, Address: 0x1027210 */
  unsigned short playpositbl[2] = { /* Line 231, Address: 0x1027228 */
    32,
    428
  };
  unsigned short endplpositbl[16] = { /* Line 235, Address: 0x1027244 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 245, Address: 0x1027278 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 255, Address: 0x10272a4 */
    playload(); /* Line 256, Address: 0x10272b8 */
    xWk = actwk[0].xposi.w.h; /* Line 257, Address: 0x10272c0 */
    yWk = actwk[0].yposi.w.h; /* Line 258, Address: 0x10272d0 */

    if (yWk < 0) yWk = 0; /* Line 260, Address: 0x10272e0 */

  } /* Line 262, Address: 0x10272f4 */
  else {

    if (demoflag.w < 0) { /* Line 265, Address: 0x10272fc */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 266, Address: 0x1027314 */
    } /* Line 267, Address: 0x102733c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 270, Address: 0x1027344 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 273, Address: 0x1027364 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 274, Address: 0x1027380 */
  }


  if ((unsigned short)xWk > 160) { /* Line 278, Address: 0x1027394 */
    xWk -= 160; /* Line 279, Address: 0x10273a8 */
  } /* Line 280, Address: 0x10273b4 */
  else {
    xWk = 0; /* Line 282, Address: 0x10273bc */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 286, Address: 0x10273c0 */
    xWk = scralim_right; /* Line 287, Address: 0x10273e4 */
  }
  scra_h_posit.w.h = xWk; /* Line 289, Address: 0x10273f4 */

  if ((unsigned short)yWk > 96) { /* Line 291, Address: 0x10273fc */
    yWk -= 96; /* Line 292, Address: 0x1027410 */
  } /* Line 293, Address: 0x102741c */
  else {
    yWk = 0; /* Line 295, Address: 0x1027424 */
  }

  if (scralim_down < yWk) { /* Line 298, Address: 0x1027428 */
    yWk = scralim_down; /* Line 299, Address: 0x102744c */
  }

  scra_v_posit.w.h = yWk; /* Line 302, Address: 0x102745c */

  scrbinit(xWk, yWk); /* Line 304, Address: 0x1027464 */

  i = 0; /* Line 306, Address: 0x1027474 */
  loopmapno = playmapnotbl[i++]; /* Line 307, Address: 0x1027478 */
  loopmapno2 = playmapnotbl[i++]; /* Line 308, Address: 0x1027490 */
  ballmapno = playmapnotbl[i++]; /* Line 309, Address: 0x10274a8 */
  ballmapno2 = playmapnotbl[i++]; /* Line 310, Address: 0x10274c0 */


} /* Line 313, Address: 0x10274d8 */











void scrbinit(short xWk, short yWk) { /* Line 325, Address: 0x1027500 */
  int i;
  short wD2;


  yWk = 536; /* Line 330, Address: 0x1027514 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 331, Address: 0x102751c */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 332, Address: 0x1027544 */
    yWk -= wD2 / 2; /* Line 333, Address: 0x1027560 */
    if (yWk < 0) { /* Line 334, Address: 0x1027594 */
      yWk = 0; /* Line 335, Address: 0x10275a8 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 339, Address: 0x10275ac */
  scrb_v_posit.w.l = 0; /* Line 340, Address: 0x10275b8 */
  scrc_v_posit.w.h = yWk; /* Line 341, Address: 0x10275c0 */
  scrz_v_posit.w.h = yWk; /* Line 342, Address: 0x10275cc */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 344, Address: 0x10275d8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 345, Address: 0x1027610 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 346, Address: 0x1027650 */


  for (i = 0; i < 14; ++i) { /* Line 349, Address: 0x1027690 */
    ((int*)hscrollwork)[i] = 0; /* Line 350, Address: 0x102769c */
  } /* Line 351, Address: 0x10276b0 */

} /* Line 353, Address: 0x10276c0 */












void scroll(void) { /* Line 366, Address: 0x10276e0 */
  int LineSpdTbl[14] = { /* Line 367, Address: 0x1027700 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  4096,  8192,
    12288, 16384, 24576,
    32768, 49152
  };
  unsigned char z32c_cnttbl[14] = { /* Line 374, Address: 0x1027734 */
    1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 3, 3, 3, 5
  };
  unsigned short z32c_kawatbl[3] = { /* Line 377, Address: 0x1027768 */
    56, 592, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 387, Address: 0x102778c */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 390, Address: 0x102779c */
  scrchk(); /* Line 391, Address: 0x10277c8 */
  scroll_h(); /* Line 392, Address: 0x10277d4 */
  scroll_v(); /* Line 393, Address: 0x10277e0 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 395, Address: 0x10277ec */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 396, Address: 0x10277fc */


  scrollz_h(scra_hz << 4, 64); /* Line 399, Address: 0x102780c */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 400, Address: 0x1027830 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 401, Address: 0x102786c */

  lD0.w.l = 536; /* Line 403, Address: 0x10278a8 */
  wD1 = 1312; /* Line 404, Address: 0x10278b0 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 405, Address: 0x10278b8 */

    wD1 -= scra_v_posit.w.h; /* Line 407, Address: 0x10278d8 */
    wD1 >>= 1; /* Line 408, Address: 0x10278ec */
    lD0.w.l -= wD1; /* Line 409, Address: 0x10278f4 */
    if (lD0.w.l < 0) { /* Line 410, Address: 0x1027908 */
      lD0.w.l = 0; /* Line 411, Address: 0x102791c */
    }
  } /* Line 413, Address: 0x1027920 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 415, Address: 0x1027928 */
  }

  scrollb_v(lD0.w.l); /* Line 418, Address: 0x102793c */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 419, Address: 0x1027950 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 420, Address: 0x1027960 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 421, Address: 0x1027970 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 423, Address: 0x1027980 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 424, Address: 0x102799c */
  scrflagz.b.h = 0; /* Line 425, Address: 0x10279b8 */
  scrflagc.b.h = 0; /* Line 426, Address: 0x10279c0 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 449, Address: 0x10279c8 */
  for (i = 0; i < 14; ++i) { /* Line 450, Address: 0x10279d0 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 451, Address: 0x10279dc */
    ++pHscrWk; /* Line 452, Address: 0x10279f4 */
  } /* Line 453, Address: 0x10279f8 */
  wD1 = 0; /* Line 454, Address: 0x1027a08 */
  for ( ; i < 78; ++i) { /* Line 455, Address: 0x1027a0c */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 456, Address: 0x1027a14 */
    pHscrWk->l += lD2.l; /* Line 457, Address: 0x1027a38 */
    ++pHscrWk; /* Line 458, Address: 0x1027a48 */
    ++wD1; /* Line 459, Address: 0x1027a4c */
  } /* Line 460, Address: 0x1027a54 */







  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 468, Address: 0x1027a64 */
  lD2.l <<= 6; /* Line 469, Address: 0x1027a8c */
  lD2.l /= 28; /* Line 470, Address: 0x1027a98 */
  lD2.l <<= 10; /* Line 471, Address: 0x1027ab8 */

  lD3.l = 0; /* Line 473, Address: 0x1027ac4 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 474, Address: 0x1027ac8 */

  pHScrollWork = &hscrollwork[162]; /* Line 476, Address: 0x1027ad4 */
  for (i = 0; i < 7; ++i) { /* Line 477, Address: 0x1027ae0 */
    lD0.w.l = -lD3.w.l; /* Line 478, Address: 0x1027aec */
    *pHScrollWork-- = lD0.w.l; /* Line 479, Address: 0x1027b08 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 480, Address: 0x1027b1c */
    lD3.l += lD2.l; /* Line 481, Address: 0x1027b40 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 482, Address: 0x1027b50 */
  } /* Line 483, Address: 0x1027b74 */

  pHScrollWork = &hscrollwork[163]; /* Line 485, Address: 0x1027b84 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 486, Address: 0x1027b90 */

  for (i = 0; i < 3; ++i) { /* Line 488, Address: 0x1027bb4 */
    *pHScrollWork++ = lD0.w.l; /* Line 489, Address: 0x1027bc0 */
  } /* Line 490, Address: 0x1027bd4 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 492, Address: 0x1027be4 */

  for (i = 0; i < 4; ++i) { /* Line 494, Address: 0x1027c08 */
    *pHScrollWork++ = lD0.w.l; /* Line 495, Address: 0x1027c14 */
  } /* Line 496, Address: 0x1027c28 */














  pHscrWk = (int_union*)hscrollwork; /* Line 511, Address: 0x1027c38 */
  for (i = 13; i >= 0; --i) { /* Line 512, Address: 0x1027c40 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 513, Address: 0x1027c4c */
    ++pHscrWk; /* Line 514, Address: 0x1027c78 */
    for (j = z32c_cnttbl[i]; j >= 0; --j) { /* Line 515, Address: 0x1027c7c */
      *pHScrollWork++ = wD1; /* Line 516, Address: 0x1027c90 */
    } /* Line 517, Address: 0x1027ca0 */
  } /* Line 518, Address: 0x1027cac */



  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 522, Address: 0x1027cb8 */

  for (i = 0; i < 8; ++i) { /* Line 524, Address: 0x1027cdc */
    *pHScrollWork++ = lD0.w.l; /* Line 525, Address: 0x1027ce8 */
  } /* Line 526, Address: 0x1027cfc */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 528, Address: 0x1027d0c */

  for (i = 0; i < 4; ++i) { /* Line 530, Address: 0x1027d30 */
    *pHScrollWork++ = lD0.w.l; /* Line 531, Address: 0x1027d3c */
  } /* Line 532, Address: 0x1027d50 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 534, Address: 0x1027d60 */

  for (i = 0; i < 6; ++i) { /* Line 536, Address: 0x1027d84 */
    *pHScrollWork++ = lD0.w.l; /* Line 537, Address: 0x1027d90 */
  } /* Line 538, Address: 0x1027da4 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 540, Address: 0x1027db4 */

  for (i = 0; i < 4; ++i) { /* Line 542, Address: 0x1027dd8 */
    *pHScrollWork++ = lD0.w.l; /* Line 543, Address: 0x1027de4 */
  } /* Line 544, Address: 0x1027df8 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 547, Address: 0x1027e08 */
  lD2.l <<= 6; /* Line 548, Address: 0x1027e40 */
  lD2.l /= 44; /* Line 549, Address: 0x1027e4c */
  lD2.l <<= 11; /* Line 550, Address: 0x1027e6c */
  lD3.w.l = scrb_h_posit.w.h; /* Line 551, Address: 0x1027e78 */

  for (i = 0; i < 10; ++i) { /* Line 553, Address: 0x1027e84 */
    *pHScrollWork++ = (unsigned short)-lD3.w.l; /* Line 554, Address: 0x1027e90 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 555, Address: 0x1027ebc */
    lD3.l += lD2.l; /* Line 556, Address: 0x1027ee0 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 557, Address: 0x1027ef0 */
  } /* Line 558, Address: 0x1027f14 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 560, Address: 0x1027f24 */

  for (i = 0; i < 8; ++i) { /* Line 562, Address: 0x1027f48 */
    *pHScrollWork++ = lD0.w.l; /* Line 563, Address: 0x1027f54 */
  } /* Line 564, Address: 0x1027f68 */

  pHScrollBuff = lphscrollbuff; /* Line 566, Address: 0x1027f78 */
  pHScrollWork = &hscrollwork[156]; /* Line 567, Address: 0x1027f84 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 568, Address: 0x1027f90 */
  lD2.w.l = lD0.w.l; /* Line 569, Address: 0x1027f9c */
  wD4 = lD0.w.l; /* Line 570, Address: 0x1027fa4 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 571, Address: 0x1027fac */
  wD3 = lD0.w.l >> 1; /* Line 572, Address: 0x1027fd0 */
  wD1 = 87; /* Line 573, Address: 0x1027fe8 */
  wD5 = 29; /* Line 574, Address: 0x1027ff0 */
  if (wD3 <= wD1) { /* Line 575, Address: 0x1027ff8 */

    wD1 -= wD3; /* Line 577, Address: 0x102800c */
    if (wD1 >= 27) { /* Line 578, Address: 0x1028014 */
      wD1 = 28; /* Line 579, Address: 0x1028024 */
    }

    wD5 -= wD1; /* Line 582, Address: 0x102802c */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 583, Address: 0x1028038 */
    waterdirec.w += 64; /* Line 584, Address: 0x102805c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z32c_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 586, Address: 0x1028070 */


  } /* Line 589, Address: 0x102809c */
  else {
    wD1 -= wD3; /* Line 591, Address: 0x10280a4 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 596, Address: 0x10280b0 */
  pHScrollWork = &hscrollwork[28]; /* Line 597, Address: 0x10280c4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 598, Address: 0x10280d0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 599, Address: 0x10280e4 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 602, Address: 0x10280fc */
    lD2.w.l = *pHScrollWork++; /* Line 603, Address: 0x1028110 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 604, Address: 0x1028124 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 605, Address: 0x1028138 */
    lD0.w.l = lD2.w.l; /* Line 606, Address: 0x1028158 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 607, Address: 0x1028160 */
    if (wD3 <= wD4) { /* Line 608, Address: 0x1028180 */
      wD5 &= 255; /* Line 609, Address: 0x1028198 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 610, Address: 0x10281a0 */
      wD3 += scra_h_posit.w.h; /* Line 611, Address: 0x10281cc */
      wD3 = -(short)wD3; /* Line 612, Address: 0x10281e0 */
      lD0.w.h = wD3; /* Line 613, Address: 0x10281fc */
    }

    pHScrollBuff->l = lD0.l; /* Line 616, Address: 0x1028200 */
    ++pHScrollBuff; /* Line 617, Address: 0x102820c */
    ++wD4; /* Line 618, Address: 0x1028218 */
    ++wD5; /* Line 619, Address: 0x1028224 */
  } while ((short)--wD1 >= 0); /* Line 620, Address: 0x102822c */

} /* Line 622, Address: 0x1028250 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 627, Address: 0x1028280 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 634, Address: 0x10282b4 */
  pA1 = *ppA1; /* Line 635, Address: 0x10282d4 */
  pA2 = *ppA2; /* Line 636, Address: 0x10282dc */

  if (*pA3 <= *pwD4) goto label6; /* Line 638, Address: 0x10282e4 */



label1:
  *pwD2 &= 7; /* Line 643, Address: 0x1028308 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 644, Address: 0x102831c */

  lD0.w.l = *pA2++; /* Line 646, Address: 0x1028348 */
  i = 8 - *pwD2; /* Line 647, Address: 0x1028358 */
  goto label4; /* Line 648, Address: 0x102836c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 651, Address: 0x1028374 */


  if (*pA3 <= *pwD4) goto label7; /* Line 654, Address: 0x1028390 */



label3:
  lD0.w.l = *pA2++; /* Line 659, Address: 0x10283b4 */
  *pwD4 += 8; /* Line 660, Address: 0x10283c4 */


  i = 8; /* Line 663, Address: 0x10283d8 */
label4:
  for ( ; i > 0; --i) { /* Line 665, Address: 0x10283dc */


    pA1->l = lD0.l; /* Line 668, Address: 0x10283e4 */
    ++pA1; /* Line 669, Address: 0x10283ec */
  } /* Line 670, Address: 0x10283f0 */
  if ((short)--wD1 >= 0) goto label2; /* Line 671, Address: 0x1028400 */



label5:
  *ppA1 = pA1; /* Line 676, Address: 0x1028428 */
  *ppA2 = pA2; /* Line 677, Address: 0x1028430 */
  return; /* Line 678, Address: 0x1028438 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 682, Address: 0x1028440 */
  if ((short)wD3 > 0) goto label8; /* Line 683, Address: 0x1028470 */


  if (*pA3 > *pwD4) goto label1; /* Line 686, Address: 0x1028488 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 689, Address: 0x10284ac */
  if ((short)wD3 > 0) goto label8; /* Line 690, Address: 0x10284dc */
  goto label1; /* Line 691, Address: 0x10284f4 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 699, Address: 0x10284fc */
  if ((short)wD3 <= 0) goto label3; /* Line 700, Address: 0x102852c */



label8:
  --wD3; /* Line 705, Address: 0x1028544 */
  wD6 = wD3; /* Line 706, Address: 0x102854c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 707, Address: 0x1028550 */

  do {
    *pwD2 &= 255; /* Line 710, Address: 0x1028568 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 711, Address: 0x102857c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 712, Address: 0x10285a8 */
    lD0.w.l = -lD0.w.l; /* Line 713, Address: 0x10285bc */
    pA1->w.h = lD0.w.h; /* Line 714, Address: 0x10285d8 */
    pA1->w.l = lD0.w.l; /* Line 715, Address: 0x10285e0 */
    ++pA1; /* Line 716, Address: 0x10285e8 */
    ++*pwD4; /* Line 717, Address: 0x10285ec */
    ++*pwD2; /* Line 718, Address: 0x1028600 */
  } while ((short)--wD3 >= 0); /* Line 719, Address: 0x1028614 */

  wD6 >>= 3; /* Line 721, Address: 0x1028638 */

  do {
    lD0.w.l = *pA2++; /* Line 724, Address: 0x1028640 */
    --wD1; /* Line 725, Address: 0x1028650 */
  } while ((short)--wD6 >= 0); /* Line 726, Address: 0x102865c */
  goto label2; /* Line 727, Address: 0x1028680 */
} /* Line 728, Address: 0x1028688 */















void scroll_h(void) { /* Line 744, Address: 0x10286b0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 747, Address: 0x10286bc */
  scrh_move(); /* Line 748, Address: 0x10286c8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 749, Address: 0x10286d0 */
    scra_h_count ^= 16; /* Line 750, Address: 0x1028704 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 751, Address: 0x1028718 */
      scrflaga.b.h |= 4; /* Line 752, Address: 0x1028744 */
    } /* Line 753, Address: 0x1028758 */
    else {

      scrflaga.b.h |= 8; /* Line 756, Address: 0x1028760 */
    }
  }


} /* Line 761, Address: 0x1028774 */

void scrh_move(void) { /* Line 763, Address: 0x1028790 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 766, Address: 0x102879c */
  wD0 -= scra_h_posit.w.h; /* Line 767, Address: 0x10287a8 */
  wD0 -= scra_hline; /* Line 768, Address: 0x10287bc */
  if (wD0 == 0) { /* Line 769, Address: 0x10287d0 */

    scra_hz = 0; /* Line 771, Address: 0x10287dc */
  } /* Line 772, Address: 0x10287e4 */
  else if ((short)wD0 < 0) { /* Line 773, Address: 0x10287ec */
    left_check(wD0); /* Line 774, Address: 0x1028804 */
  } /* Line 775, Address: 0x1028810 */
  else {
    right_check(wD0); /* Line 777, Address: 0x1028818 */
  }

} /* Line 780, Address: 0x1028824 */


void right_check(unsigned short wD0) { /* Line 783, Address: 0x1028840 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 786, Address: 0x102884c */
    wD0 = 16; /* Line 787, Address: 0x102886c */
  }

  wD0 += scra_h_posit.w.h; /* Line 790, Address: 0x1028874 */
  if (scralim_right < (short)wD0) { /* Line 791, Address: 0x102888c */
    wD0 = scralim_right; /* Line 792, Address: 0x10288bc */
  }

  wD1 = wD0; /* Line 795, Address: 0x10288c8 */
  wD1 -= scra_h_posit.w.h; /* Line 796, Address: 0x10288d0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 797, Address: 0x10288e4 */
  scra_h_posit.w.h = wD0; /* Line 798, Address: 0x1028914 */
  scra_hz = wD1; /* Line 799, Address: 0x1028920 */

} /* Line 801, Address: 0x1028928 */


void left_check(unsigned short wD0) { /* Line 804, Address: 0x1028940 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 807, Address: 0x102894c */
    wD0 = -16; /* Line 808, Address: 0x102896c */
  }

  wD0 += scra_h_posit.w.h; /* Line 811, Address: 0x1028974 */
  if (scralim_left > (short)wD0) { /* Line 812, Address: 0x102898c */
    wD0 = scralim_left; /* Line 813, Address: 0x10289bc */
  }

  wD1 = wD0; /* Line 816, Address: 0x10289c8 */
  wD1 -= scra_h_posit.w.h; /* Line 817, Address: 0x10289d0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 818, Address: 0x10289e4 */
  scra_h_posit.w.h = wD0; /* Line 819, Address: 0x1028a14 */
  scra_hz = wD1; /* Line 820, Address: 0x1028a20 */

} /* Line 822, Address: 0x1028a28 */


















void scroll_v(void) { /* Line 841, Address: 0x1028a40 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 844, Address: 0x1028a4c */
  if (actwk[0].cddat & 4) { /* Line 845, Address: 0x1028a78 */
    wD0 -= 5; /* Line 846, Address: 0x1028a90 */
  }

  if (actwk[0].cddat & 2) { /* Line 849, Address: 0x1028a98 */
    wD0 += 32; /* Line 850, Address: 0x1028ab0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 851, Address: 0x1028ab8 */
      wD0 -= scra_vline; /* Line 852, Address: 0x1028ad8 */
      sv_move_main2(wD0); /* Line 853, Address: 0x1028aec */
      return; /* Line 854, Address: 0x1028af8 */
    }
    wD0 -= scra_vline; /* Line 856, Address: 0x1028b00 */
    if (wD0 >= 64) { /* Line 857, Address: 0x1028b14 */
      wD0 -= 64; /* Line 858, Address: 0x1028b24 */
      sv_move_main2(wD0); /* Line 859, Address: 0x1028b2c */
      return; /* Line 860, Address: 0x1028b38 */
    }
    wD0 -= 64; /* Line 862, Address: 0x1028b40 */
    if (limmoveflag == 0) goto label1; /* Line 863, Address: 0x1028b48 */
    sv_move_sub2(); /* Line 864, Address: 0x1028b5c */
    return; /* Line 865, Address: 0x1028b64 */
  }




  wD0 -= scra_vline; /* Line 871, Address: 0x1028b6c */
  if (wD0) { /* Line 872, Address: 0x1028b80 */
    sv_move_main(wD0); /* Line 873, Address: 0x1028b88 */
    return; /* Line 874, Address: 0x1028b94 */
  }
  if (limmoveflag == 0) { /* Line 876, Address: 0x1028b9c */
    sv_move_sub2(); /* Line 877, Address: 0x1028bb0 */
    return; /* Line 878, Address: 0x1028bb8 */
  }


label1:
  scra_vz = 0; /* Line 883, Address: 0x1028bc0 */

} /* Line 885, Address: 0x1028bc8 */





void sv_move_main(unsigned short wD0) { /* Line 891, Address: 0x1028be0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 894, Address: 0x1028bf0 */
    sv_move_main1(wD0); /* Line 895, Address: 0x1028c0c */
  } /* Line 896, Address: 0x1028c18 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 899, Address: 0x1028c20 */
    if ((short)wD1 < 0) { /* Line 900, Address: 0x1028c2c */
      wD1 = -(short)wD1; /* Line 901, Address: 0x1028c44 */
    }

    if (wD1 >= 2048) { /* Line 904, Address: 0x1028c60 */
      sv_move_main2(wD0); /* Line 905, Address: 0x1028c70 */
    } /* Line 906, Address: 0x1028c7c */
    else {
      if ((short)wD0 > 6) { /* Line 908, Address: 0x1028c84 */
        sv_move_plus(1536); /* Line 909, Address: 0x1028ca4 */
      } /* Line 910, Address: 0x1028cb0 */
      else if ((short)wD0 < -6) { /* Line 911, Address: 0x1028cb8 */
        sv_move_minus(1536); /* Line 912, Address: 0x1028cd8 */
      } /* Line 913, Address: 0x1028ce4 */
      else {
        sv_move_sub(wD0); /* Line 915, Address: 0x1028cec */
      }
    }
  }
} /* Line 919, Address: 0x1028cf8 */



void sv_move_main1(unsigned short wD0) { /* Line 923, Address: 0x1028d10 */

  if ((short)wD0 > 2) { /* Line 925, Address: 0x1028d1c */
    sv_move_plus(512); /* Line 926, Address: 0x1028d3c */
  } /* Line 927, Address: 0x1028d48 */
  else if ((short)wD0 < -2) { /* Line 928, Address: 0x1028d50 */
    sv_move_minus(512); /* Line 929, Address: 0x1028d70 */
  } /* Line 930, Address: 0x1028d7c */
  else {
    sv_move_sub(wD0); /* Line 932, Address: 0x1028d84 */
  }

} /* Line 935, Address: 0x1028d90 */


void sv_move_main2(unsigned short wD0) { /* Line 938, Address: 0x1028da0 */

  if ((short)wD0 > 16) { /* Line 940, Address: 0x1028dac */
    sv_move_plus(4096); /* Line 941, Address: 0x1028dcc */
  } /* Line 942, Address: 0x1028dd8 */
  else if ((short)wD0 < -16) { /* Line 943, Address: 0x1028de0 */
    sv_move_minus(4096); /* Line 944, Address: 0x1028e00 */
  } /* Line 945, Address: 0x1028e0c */
  else {
    sv_move_sub(wD0); /* Line 947, Address: 0x1028e14 */
  }

} /* Line 950, Address: 0x1028e20 */


void sv_move_sub2(void) { /* Line 953, Address: 0x1028e30 */
  limmoveflag = 0; /* Line 954, Address: 0x1028e38 */
  sv_move_sub(0); /* Line 955, Address: 0x1028e40 */
} /* Line 956, Address: 0x1028e4c */


void sv_move_sub(unsigned short wD0) { /* Line 959, Address: 0x1028e60 */
  int_union lD1;

  lD1.w.h = 0; /* Line 962, Address: 0x1028e6c */
  lD1.w.l = wD0; /* Line 963, Address: 0x1028e70 */
  lD1.l += scra_v_posit.w.h; /* Line 964, Address: 0x1028e78 */
  if ((short)wD0 > 0) { /* Line 965, Address: 0x1028e94 */
    scrv_down_ch(lD1); /* Line 966, Address: 0x1028eb0 */
  } /* Line 967, Address: 0x1028ebc */
  else {
    scrv_up_ch(lD1); /* Line 969, Address: 0x1028ec4 */
  }

} /* Line 972, Address: 0x1028ed0 */




void sv_move_minus(unsigned short wD1) { /* Line 977, Address: 0x1028ee0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 981, Address: 0x1028ef0 */
  lD1.l <<= 8; /* Line 982, Address: 0x1028f0c */
  lD1.l += scra_v_posit.l; /* Line 983, Address: 0x1028f18 */

  wk = lD1.w.h; /* Line 985, Address: 0x1028f2c */
  lD1.w.h = lD1.w.l; /* Line 986, Address: 0x1028f34 */
  lD1.w.l = wk; /* Line 987, Address: 0x1028f3c */
  scrv_up_ch(lD1); /* Line 988, Address: 0x1028f40 */
} /* Line 989, Address: 0x1028f4c */



void scrv_up_ch(int_union lD1) { /* Line 993, Address: 0x1028f60 */
  if (scralim_up >= lD1.w.l) { /* Line 994, Address: 0x1028f6c */
    if (lD1.w.l < -255) { /* Line 995, Address: 0x1028f94 */
      lD1.w.l &= 2047; /* Line 996, Address: 0x1028fac */
      actwk[0].yposi.w.h &= 32767; /* Line 997, Address: 0x1028fb8 */
      scra_v_posit.w.h &= 2047; /* Line 998, Address: 0x1028fcc */
      scrb_v_posit.w.h &= 1023; /* Line 999, Address: 0x1028fe0 */
    } /* Line 1000, Address: 0x1028ff4 */
    else {

      lD1.w.l = scralim_up; /* Line 1003, Address: 0x1028ffc */
    }
  }
  scrv_move(lD1); /* Line 1006, Address: 0x1029008 */

} /* Line 1008, Address: 0x1029014 */





void sv_move_plus(unsigned short wD1) { /* Line 1014, Address: 0x1029030 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1018, Address: 0x1029040 */
  lD1.w.l = wD1; /* Line 1019, Address: 0x1029044 */
  lD1.l <<= 8; /* Line 1020, Address: 0x102904c */
  lD1.l += scra_v_posit.l; /* Line 1021, Address: 0x1029058 */

  wk = lD1.w.h; /* Line 1023, Address: 0x102906c */
  lD1.w.h = lD1.w.l; /* Line 1024, Address: 0x1029074 */
  lD1.w.l = wk; /* Line 1025, Address: 0x102907c */

  scrv_down_ch(lD1); /* Line 1027, Address: 0x1029080 */

} /* Line 1029, Address: 0x102908c */



void scrv_down_ch(int_union lD1) { /* Line 1033, Address: 0x10290a0 */
  if (scralim_down <= lD1.w.l) { /* Line 1034, Address: 0x10290ac */
    lD1.w.l -= 2048; /* Line 1035, Address: 0x10290d4 */
    if (lD1.w.l > 0) { /* Line 1036, Address: 0x10290e0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1037, Address: 0x10290f4 */
      scra_v_posit.w.h -= 2048; /* Line 1038, Address: 0x1029108 */
      scrb_v_posit.w.h &= 1023; /* Line 1039, Address: 0x102911c */
    } /* Line 1040, Address: 0x1029130 */
    else {
      lD1.w.l = scralim_down; /* Line 1042, Address: 0x1029138 */
    }
  }
  scrv_move(lD1); /* Line 1045, Address: 0x1029144 */

} /* Line 1047, Address: 0x1029150 */


void scrv_move(int_union lD1) { /* Line 1050, Address: 0x1029160 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1053, Address: 0x1029170 */

  wk = lD1.w.h; /* Line 1055, Address: 0x102917c */
  lD1.w.h = lD1.w.l; /* Line 1056, Address: 0x1029184 */
  lD1.w.l = wk; /* Line 1057, Address: 0x102918c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1059, Address: 0x1029190 */
  scra_v_posit.l = lD1.l; /* Line 1060, Address: 0x10291b8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1063, Address: 0x10291c4 */
    scra_v_count ^= 16; /* Line 1064, Address: 0x10291f8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1065, Address: 0x102920c */

      scrflaga.b.h |= 2; /* Line 1067, Address: 0x1029238 */
    } /* Line 1068, Address: 0x102924c */
    else {
      scrflaga.b.h |= 1; /* Line 1070, Address: 0x1029254 */
    }
  }


} /* Line 1075, Address: 0x1029268 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1079, Address: 0x1029280 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1082, Address: 0x102928c */
  lD0.l += lD4.l; /* Line 1083, Address: 0x102929c */
  scrb_h_posit.l = lD0.l; /* Line 1084, Address: 0x10292ac */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1086, Address: 0x10292b8 */

    scrb_h_count ^= 16; /* Line 1088, Address: 0x10292ec */
    lD0.l -= lD2.l; /* Line 1089, Address: 0x1029300 */
    if ((long int)lD0.l < 0) { /* Line 1090, Address: 0x1029310 */
      scrflagb.b.h |= 4; /* Line 1091, Address: 0x1029324 */
    } /* Line 1092, Address: 0x1029338 */
    else {

      scrflagb.b.h |= 8; /* Line 1095, Address: 0x1029340 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1100, Address: 0x1029354 */
  lD0.l += lD5.l; /* Line 1101, Address: 0x1029364 */
  scrb_h_posit.l = lD0.l; /* Line 1102, Address: 0x1029374 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1104, Address: 0x1029380 */

    scrb_v_count ^= 16; /* Line 1106, Address: 0x10293b4 */
    lD0.l -= lD3.l; /* Line 1107, Address: 0x10293c8 */
    if ((long int)lD0.l < 0) { /* Line 1108, Address: 0x10293d8 */
      scrflagb.b.h |= 1; /* Line 1109, Address: 0x10293ec */
    } /* Line 1110, Address: 0x1029400 */
    else {

      scrflagb.b.h |= 2; /* Line 1113, Address: 0x1029408 */
    }
  }


} /* Line 1118, Address: 0x102941c */






void scrollb_v(unsigned short wD0) { /* Line 1125, Address: 0x1029430 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1128, Address: 0x102943c */
  scrb_v_posit.w.h = wD0; /* Line 1129, Address: 0x1029448 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1131, Address: 0x1029454 */
    scrb_v_count ^= 16; /* Line 1132, Address: 0x1029480 */
    if ((short)wD3 > (short)wD0) { /* Line 1133, Address: 0x1029494 */
      scrflagb.b.h |= 1; /* Line 1134, Address: 0x10294c4 */
    } /* Line 1135, Address: 0x10294d8 */
    else {

      scrflagb.b.h |= 2; /* Line 1138, Address: 0x10294e0 */
    }
  }


} /* Line 1143, Address: 0x10294f4 */



void scrollb_h(int lD4, int flagb) { /* Line 1147, Address: 0x1029510 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1151, Address: 0x1029520 */
  lD0.l = lD2.l + lD4; /* Line 1152, Address: 0x102952c */
  scrb_h_posit.l = lD0.l; /* Line 1153, Address: 0x102953c */

  lD1.w.h = lD0.w.l; /* Line 1155, Address: 0x1029548 */
  lD1.w.l = lD0.w.h; /* Line 1156, Address: 0x1029550 */
  lD1.w.l &= 16; /* Line 1157, Address: 0x1029558 */

  bD3 = scrb_h_count; /* Line 1159, Address: 0x1029564 */
  lD1.b.b4 ^= bD3; /* Line 1160, Address: 0x1029570 */
  if (!lD1.b.b4) { /* Line 1161, Address: 0x1029584 */
    scrb_h_count ^= 16; /* Line 1162, Address: 0x1029590 */
    lD0.l -= lD2.l; /* Line 1163, Address: 0x10295a4 */
    if ((long int)lD0.l < 0) { /* Line 1164, Address: 0x10295b4 */
      scrflagb.b.h |= flagb; /* Line 1165, Address: 0x10295c8 */
    } /* Line 1166, Address: 0x10295e4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1169, Address: 0x10295ec */
    }
  }


} /* Line 1174, Address: 0x102960c */



void scrollc_h(int lD4, int flagc) { /* Line 1178, Address: 0x1029620 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1182, Address: 0x1029630 */
  lD0.l = lD2.l + lD4; /* Line 1183, Address: 0x102963c */
  scrc_h_posit.l = lD0.l; /* Line 1184, Address: 0x102964c */

  lD1.w.h = lD0.w.l; /* Line 1186, Address: 0x1029658 */
  lD1.w.l = lD0.w.h; /* Line 1187, Address: 0x1029660 */
  lD1.w.l &= 16; /* Line 1188, Address: 0x1029668 */

  bD3 = scrc_h_count; /* Line 1190, Address: 0x1029674 */
  lD1.b.b4 ^= bD3; /* Line 1191, Address: 0x1029680 */
  if (!lD1.b.b4) { /* Line 1192, Address: 0x1029694 */
    scrc_h_count ^= 16; /* Line 1193, Address: 0x10296a0 */
    lD0.l -= lD2.l; /* Line 1194, Address: 0x10296b4 */
    if ((long int)lD0.l < 0) { /* Line 1195, Address: 0x10296c4 */
      scrflagc.b.h |= flagc; /* Line 1196, Address: 0x10296d8 */
    } /* Line 1197, Address: 0x10296f4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1200, Address: 0x10296fc */
    }
  }


} /* Line 1205, Address: 0x102971c */











void scrollz_h(int lD4, int flagz) { /* Line 1217, Address: 0x1029730 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1221, Address: 0x1029740 */
  lD0.l = lD2.l + lD4; /* Line 1222, Address: 0x102974c */
  scrz_h_posit.l = lD0.l; /* Line 1223, Address: 0x102975c */

  lD1.w.h = lD0.w.l; /* Line 1225, Address: 0x1029768 */
  lD1.w.l = lD0.w.h; /* Line 1226, Address: 0x1029770 */
  lD1.w.l &= 16; /* Line 1227, Address: 0x1029778 */

  bD3 = scrz_h_count; /* Line 1229, Address: 0x1029784 */
  lD1.b.b4 ^= bD3; /* Line 1230, Address: 0x1029790 */
  if (!lD1.b.b4) { /* Line 1231, Address: 0x10297a4 */
    scrz_h_count ^= 16; /* Line 1232, Address: 0x10297b0 */
    lD0.l -= lD2.l; /* Line 1233, Address: 0x10297c4 */
    if ((long int)lD0.l < 0) { /* Line 1234, Address: 0x10297d4 */
      scrflagz.b.h |= flagz; /* Line 1235, Address: 0x10297e8 */
    } /* Line 1236, Address: 0x1029804 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1239, Address: 0x102980c */
    }
  }


} /* Line 1244, Address: 0x102982c */














void scrollwrtadva(void) { /* Line 1259, Address: 0x1029840 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1265, Address: 0x102985c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1266, Address: 0x1029860 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1267, Address: 0x102986c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1268, Address: 0x1029878 */
  pScrFlag = &scrflagb.b.h; /* Line 1269, Address: 0x1029880 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1270, Address: 0x1029888 */







} /* Line 1278, Address: 0x102989c */












void scrollwrt(void) { /* Line 1291, Address: 0x10298c0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1300, Address: 0x10298e0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1301, Address: 0x10298e4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1302, Address: 0x10298f0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1303, Address: 0x10298fc */
  pScrFlag = &scrflagbw.b.h; /* Line 1304, Address: 0x1029904 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1305, Address: 0x102990c */

  VramBase = 16384; /* Line 1307, Address: 0x1029920 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1308, Address: 0x1029924 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1309, Address: 0x1029930 */
  pMapWk = (unsigned char*)mapwka; /* Line 1310, Address: 0x102993c */
  pScrFlag = &scrflagaw.b.h; /* Line 1311, Address: 0x1029944 */

  if (*pScrFlag) { /* Line 1313, Address: 0x102994c */
    if (*pScrFlag & 1) { /* Line 1314, Address: 0x1029958 */
      *pScrFlag &= 254; /* Line 1315, Address: 0x102996c */

      lD4.l = -16; /* Line 1317, Address: 0x1029978 */
      wD5 = 65520; /* Line 1318, Address: 0x1029980 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1320, Address: 0x1029988 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1322, Address: 0x10299a8 */
    }




    if (*pScrFlag & 2) { /* Line 1328, Address: 0x10299d4 */
      *pScrFlag &= 253; /* Line 1329, Address: 0x10299e8 */

      lD4.l = 224; /* Line 1331, Address: 0x10299f4 */
      wD5 = 65520; /* Line 1332, Address: 0x10299fc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1333, Address: 0x1029a04 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1335, Address: 0x1029a24 */
    }




    if (*pScrFlag & 4) { /* Line 1341, Address: 0x1029a50 */
      *pScrFlag &= 251; /* Line 1342, Address: 0x1029a64 */

      lD4.l = -16; /* Line 1344, Address: 0x1029a70 */
      wD5 = 65520; /* Line 1345, Address: 0x1029a78 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1346, Address: 0x1029a80 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1348, Address: 0x1029aa0 */
    }




    if (*pScrFlag & 8) { /* Line 1354, Address: 0x1029acc */
      *pScrFlag &= 247; /* Line 1355, Address: 0x1029ae0 */

      lD4.l = -16; /* Line 1357, Address: 0x1029aec */
      wD5 = 320; /* Line 1358, Address: 0x1029af4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1359, Address: 0x1029afc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1361, Address: 0x1029b1c */
    }
  }






} /* Line 1370, Address: 0x1029b48 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1387, Address: 0x1029b70 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1398, Address: 0x1029b9c */

  if (*pScrFlag & 1) { /* Line 1400, Address: 0x1029ba4 */
    *pScrFlag &= 254; /* Line 1401, Address: 0x1029bbc */
  } /* Line 1402, Address: 0x1029bd0 */
  else {
    *pScrFlag &= 254; /* Line 1404, Address: 0x1029bd8 */

    if (*pScrFlag & 2) { /* Line 1406, Address: 0x1029bec */
      *pScrFlag &= 253; /* Line 1407, Address: 0x1029c04 */
      lD4.w.l = 224; /* Line 1408, Address: 0x1029c18 */
    } /* Line 1409, Address: 0x1029c20 */
    else {
      *pScrFlag &= 253; /* Line 1411, Address: 0x1029c28 */
      goto label1; /* Line 1412, Address: 0x1029c3c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1417, Address: 0x1029c44 */
  wD0 &= 127; /* Line 1418, Address: 0x1029c94 */
  wD0 = z32cwrttbl[wD0 + 1]; /* Line 1419, Address: 0x1029c9c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1425, Address: 0x1029cbc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1426, Address: 0x1029cdc */
  if (wD0 != 0) { /* Line 1427, Address: 0x1029d00 */
    wD5 = 65520; /* Line 1428, Address: 0x1029d0c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1429, Address: 0x1029d14 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1431, Address: 0x1029d34 */



  } /* Line 1435, Address: 0x1029d60 */
  else {

    wD5 = 0; /* Line 1438, Address: 0x1029d68 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1439, Address: 0x1029d6c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1443, Address: 0x1029d8c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1450, Address: 0x1029db8 */






    lD4.l = -16; /* Line 1457, Address: 0x1029dcc */
    wD5 = 65520; /* Line 1458, Address: 0x1029dd4 */
    if (*pScrFlag & 168) { /* Line 1459, Address: 0x1029ddc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1460, Address: 0x1029df4 */
      wD5 = 320; /* Line 1461, Address: 0x1029e14 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1465, Address: 0x1029e1c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1467, Address: 0x1029e4c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1468, Address: 0x1029e58 */



    for (i = 0; i < 16; ++i) { /* Line 1472, Address: 0x1029e68 */
      wD0 = z32cwrttbl[WrtTblCnt++]; /* Line 1473, Address: 0x1029e74 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1474, Address: 0x1029e94 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1475, Address: 0x1029ec0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1476, Address: 0x1029ee0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1478, Address: 0x1029f04 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1481, Address: 0x1029f28 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1483, Address: 0x1029f48 */
      }
      lD4.w.l += 16; /* Line 1485, Address: 0x1029f5c */
    } /* Line 1486, Address: 0x1029f68 */
    *pScrFlag = 0; /* Line 1487, Address: 0x1029f78 */
  }
} /* Line 1489, Address: 0x1029f80 */







void scrollwrtc(void) {} /* Line 1497, Address: 0x1029fb0 */




void scrollwrtz(void) {} /* Line 1502, Address: 0x1029fc0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1523, Address: 0x1029fd0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1536, Address: 0x1029ff8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1539, Address: 0x102a018 */
    pTilePoint->x += 2; /* Line 1540, Address: 0x102a02c */
    if (pTilePoint->x >= 64) { /* Line 1541, Address: 0x102a040 */
      pTilePoint->x -= 64; /* Line 1542, Address: 0x102a054 */
    }
    xOffs += 16; /* Line 1544, Address: 0x102a068 */
  } while (--lpcnt >= 0); /* Line 1545, Address: 0x102a074 */
} /* Line 1546, Address: 0x102a088 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1550, Address: 0x102a0a0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1554, Address: 0x102a0c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1557, Address: 0x102a0e8 */
    pTilePoint->x += 2; /* Line 1558, Address: 0x102a0fc */
    if (pTilePoint->x >= 64) { /* Line 1559, Address: 0x102a110 */
      pTilePoint->x -= 64; /* Line 1560, Address: 0x102a124 */
    }
    xOffs += 16; /* Line 1562, Address: 0x102a138 */
  } while (--lpcnt >= 0); /* Line 1563, Address: 0x102a144 */
} /* Line 1564, Address: 0x102a158 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1583, Address: 0x102a170 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1587, Address: 0x102a198 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1590, Address: 0x102a1b8 */
    pTilePoint->y += 2; /* Line 1591, Address: 0x102a1cc */
    if (pTilePoint->y >= 32) { /* Line 1592, Address: 0x102a1dc */
      pTilePoint->y -= 32; /* Line 1593, Address: 0x102a1f0 */
    }
    yOffs += 16; /* Line 1595, Address: 0x102a200 */
  } while (--lpcnt >= 0); /* Line 1596, Address: 0x102a20c */
} /* Line 1597, Address: 0x102a220 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1616, Address: 0x102a230 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1622, Address: 0x102a264 */

    base = 1; /* Line 1624, Address: 0x102a274 */
  } /* Line 1625, Address: 0x102a278 */
  else if (VramBase == 16384) { /* Line 1626, Address: 0x102a280 */

    base = 0; /* Line 1628, Address: 0x102a290 */
  }
  x = pTilePoint->x; /* Line 1630, Address: 0x102a294 */
  y = pTilePoint->y; /* Line 1631, Address: 0x102a29c */


  frip = BlkIndex & 6144; /* Line 1634, Address: 0x102a2a4 */
  BlkIndex &= 1023; /* Line 1635, Address: 0x102a2ac */
  if (frip == 6144) { /* Line 1636, Address: 0x102a2b8 */

    p0 = 3, p1 = 2; /* Line 1638, Address: 0x102a2c4 */
    p2 = 1, p3 = 0; /* Line 1639, Address: 0x102a2cc */
  } /* Line 1640, Address: 0x102a2d4 */
  else if (frip & 4096) { /* Line 1641, Address: 0x102a2dc */

    p0 = 2, p1 = 3; /* Line 1643, Address: 0x102a2e8 */
    p2 = 0, p3 = 1; /* Line 1644, Address: 0x102a2f0 */
  } /* Line 1645, Address: 0x102a2f8 */
  else if (frip & 2048) { /* Line 1646, Address: 0x102a300 */

    p0 = 1, p1 = 0; /* Line 1648, Address: 0x102a30c */
    p2 = 3, p3 = 2; /* Line 1649, Address: 0x102a314 */
  } /* Line 1650, Address: 0x102a31c */
  else {

    p0 = 0, p1 = 1; /* Line 1653, Address: 0x102a324 */
    p2 = 2, p3 = 3; /* Line 1654, Address: 0x102a32c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1657, Address: 0x102a334 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1658, Address: 0x102a378 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1659, Address: 0x102a3bc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1660, Address: 0x102a400 */

} /* Line 1662, Address: 0x102a444 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1680, Address: 0x102a480 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1681, Address: 0x102a4a0 */
} /* Line 1682, Address: 0x102a4c0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1684, Address: 0x102a4d0 */
  wH_posiw = 0; /* Line 1685, Address: 0x102a4f0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1686, Address: 0x102a4f4 */
} /* Line 1687, Address: 0x102a514 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1694, Address: 0x102a530 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1700, Address: 0x102a560 */
  yOffs += wV_posiw; /* Line 1701, Address: 0x102a570 */





  if ((short)xOffs < 0) /* Line 1707, Address: 0x102a580 */
    xOffs = 0; /* Line 1708, Address: 0x102a59c */
  if ((short)yOffs < 0) /* Line 1709, Address: 0x102a5a0 */
    yOffs = 0; /* Line 1710, Address: 0x102a5bc */
  if ((short)xOffs >= 16384) /* Line 1711, Address: 0x102a5c0 */
    xOffs = 16383; /* Line 1712, Address: 0x102a5e0 */
  if ((short)yOffs >= 2048) /* Line 1713, Address: 0x102a5e8 */
    yOffs = 2047; /* Line 1714, Address: 0x102a608 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1715, Address: 0x102a610 */
  if (i < 0) i = 0; /* Line 1716, Address: 0x102a658 */

  ScreenNo = pMapWk[i] & 127; /* Line 1718, Address: 0x102a664 */

  if (ScreenNo) { /* Line 1720, Address: 0x102a680 */




    xOffs &= 32767; /* Line 1725, Address: 0x102a688 */
    yOffs &= 32767; /* Line 1726, Address: 0x102a694 */


    xBlk = xOffs; /* Line 1729, Address: 0x102a6a0 */
    xBlk %= 256; /* Line 1730, Address: 0x102a6a8 */
    xBlk /= 16; /* Line 1731, Address: 0x102a6c8 */
    yBlk = yOffs; /* Line 1732, Address: 0x102a6e4 */
    yBlk %= 256; /* Line 1733, Address: 0x102a6ec */
    yBlk /= 16; /* Line 1734, Address: 0x102a70c */

    lpw = pmapwk; /* Line 1736, Address: 0x102a728 */
    lpw += xBlk; /* Line 1737, Address: 0x102a730 */
    lpw += yBlk * 16; /* Line 1738, Address: 0x102a738 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1739, Address: 0x102a744 */
    *pIndex = *lpw; /* Line 1740, Address: 0x102a75c */

    return 1; /* Line 1742, Address: 0x102a76c */
  }

  *pIndex = 0; /* Line 1745, Address: 0x102a778 */
  return 0; /* Line 1746, Address: 0x102a780 */
} /* Line 1747, Address: 0x102a784 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1767, Address: 0x102a7b0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1775, Address: 0x102a7d8 */
  if (ScreenNo) { /* Line 1776, Address: 0x102a83c */





    xBlk = xOffs; /* Line 1782, Address: 0x102a844 */
    xBlk %= 256; /* Line 1783, Address: 0x102a84c */
    xBlk /= 16; /* Line 1784, Address: 0x102a86c */
    yBlk = yOffs; /* Line 1785, Address: 0x102a888 */
    yBlk %= 256; /* Line 1786, Address: 0x102a890 */
    yBlk /= 16; /* Line 1787, Address: 0x102a8b0 */


    lpw = pmapwk; /* Line 1790, Address: 0x102a8cc */
    lpw += xBlk; /* Line 1791, Address: 0x102a8d4 */
    lpw += yBlk * 16; /* Line 1792, Address: 0x102a8dc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1793, Address: 0x102a8e8 */
    *ppBlockNo = lpw; /* Line 1794, Address: 0x102a900 */
    *pIndex = *lpw; /* Line 1795, Address: 0x102a908 */




    return 1; /* Line 1800, Address: 0x102a918 */
  }

  *pIndex = 0; /* Line 1803, Address: 0x102a924 */
  return 0; /* Line 1804, Address: 0x102a92c */
} /* Line 1805, Address: 0x102a930 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1819, Address: 0x102a950 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1826, Address: 0x102a96c */
  pMapWk = (unsigned char*)mapwka; /* Line 1827, Address: 0x102a970 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1828, Address: 0x102a978 */
    *pBlockIndex = BlockNo; /* Line 1829, Address: 0x102a99c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1830, Address: 0x102a9a8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1831, Address: 0x102a9c0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1832, Address: 0x102a9d4 */
    }
  }


} /* Line 1837, Address: 0x102a9ec */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1851, Address: 0x102aa10 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1852, Address: 0x102aa1c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1853, Address: 0x102aa48 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1854, Address: 0x102aa94 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1855, Address: 0x102aac0 */

          return 0; /* Line 1857, Address: 0x102ab0c */
        }
      }
    }
  }

  return 1; /* Line 1863, Address: 0x102ab18 */
} /* Line 1864, Address: 0x102ab1c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1881, Address: 0x102ab30 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1882, Address: 0x102ab4c */

} /* Line 1884, Address: 0x102ab68 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1886, Address: 0x102ab80 */
  wH_posiw = 0; /* Line 1887, Address: 0x102ab9c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1888, Address: 0x102aba0 */

} /* Line 1890, Address: 0x102abbc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1892, Address: 0x102abd0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1893, Address: 0x102abe4 */

} /* Line 1895, Address: 0x102ac00 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1897, Address: 0x102ac10 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1898, Address: 0x102ac2c */

} /* Line 1900, Address: 0x102ac48 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1902, Address: 0x102ac60 */
  xOffs += wH_posiw; /* Line 1903, Address: 0x102ac78 */
  yOffs += wV_posiw; /* Line 1904, Address: 0x102ac88 */
  yOffs &= 240; /* Line 1905, Address: 0x102ac98 */
  xOffs &= 496; /* Line 1906, Address: 0x102aca4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1908, Address: 0x102acb0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1909, Address: 0x102acdc */


} /* Line 1912, Address: 0x102ad08 */















void mapwrt(void) { /* Line 1928, Address: 0x102ad20 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1933, Address: 0x102ad38 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1934, Address: 0x102ad44 */
  pMapWk = (unsigned char*)mapwka; /* Line 1935, Address: 0x102ad50 */
  VramBase = 16384; /* Line 1936, Address: 0x102ad58 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1937, Address: 0x102ad5c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1941, Address: 0x102ad74 */
  VramBase = 24576; /* Line 1942, Address: 0x102ad7c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1943, Address: 0x102ad80 */

} /* Line 1945, Address: 0x102ad90 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1948, Address: 0x102adb0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1949, Address: 0x102adc8 */
} /* Line 1950, Address: 0x102ade8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1955, Address: 0x102ae00 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1959, Address: 0x102ae20 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1962, Address: 0x102ae3c */



    wD4 += 16; /* Line 1966, Address: 0x102ae64 */
  } while ((short)--wD6 >= 0); /* Line 1967, Address: 0x102ae70 */

} /* Line 1969, Address: 0x102ae98 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1974, Address: 0x102aeb0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1977, Address: 0x102aecc */
  wD6 = 15; /* Line 1978, Address: 0x102aed4 */



  do {
    wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1983, Address: 0x102aedc */

    mapwrt_sub(&z32cwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1985, Address: 0x102af00 */
    wD4 += 16; /* Line 1986, Address: 0x102af20 */
  } while ((short)--wD6 >= 0); /* Line 1987, Address: 0x102af28 */
} /* Line 1988, Address: 0x102af4c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2014, Address: 0x102af70 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2019, Address: 0x102af98 */
  wD0 = pWrttbl[wD0]; /* Line 2020, Address: 0x102afa8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2022, Address: 0x102afc4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2023, Address: 0x102afe8 */
  if (wD0) { /* Line 2024, Address: 0x102b010 */
    wD5 = 65520; /* Line 2025, Address: 0x102b01c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2026, Address: 0x102b024 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2029, Address: 0x102b040 */



  } /* Line 2033, Address: 0x102b068 */
  else {

    wD5 = 0; /* Line 2036, Address: 0x102b070 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2037, Address: 0x102b074 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2041, Address: 0x102b090 */
  }





} /* Line 2048, Address: 0x102b0b8 */




void mapinit(void) { /* Line 2053, Address: 0x102b0e0 */





  mapset(); /* Line 2059, Address: 0x102b0e8 */


  colorset2(mapinittbl.colorno2); /* Line 2062, Address: 0x102b0f0 */
  colorset(mapinittbl.colorno2); /* Line 2063, Address: 0x102b104 */






  if (plflag != 0) { /* Line 2070, Address: 0x102b118 */
    enecginit(); /* Line 2071, Address: 0x102b12c */
  }

  if (play_start & 2) { /* Line 2074, Address: 0x102b134 */

    divdevset(); /* Line 2076, Address: 0x102b14c */
  }


} /* Line 2080, Address: 0x102b154 */









void mapset(void) {} /* Line 2090, Address: 0x102b170 */
