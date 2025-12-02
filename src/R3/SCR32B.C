#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3B.H"

static unsigned char z32bwrttbl[49] = {
  0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2, 2, 2, 2, 2, 6, 6,
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
extern unsigned char mapwkb[64][8];
extern unsigned char mapwka[64][8];
extern map_init_data mapinittbl;








































































void enecginit(void) {} /* Line 111, Address: 0x1026c40 */



void divdevset() {} /* Line 115, Address: 0x1026c50 */




















































sprite_status* main_chk(void) {
  if (main_play == 0) { /* Line 169, Address: 0x1026c60 */
    return &actwk[0]; /* Line 170, Address: 0x1026c74 */
  }
  return &actwk[1]; /* Line 172, Address: 0x1026c84 */
} /* Line 173, Address: 0x1026c8c */












void scr_set(void) { /* Line 186, Address: 0x1026ca0 */





  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x1026cac */
    4, 0, 9879, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1026ce0 */

  i = 0; /* Line 199, Address: 0x1026d28 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x1026d2c */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x1026d48 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x1026d5c */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x1026d78 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x1026d8c */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1026da8 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x1026dbc */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1026dd8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x1026dec */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x1026e08 */
  scra_h_count = 16; /* Line 211, Address: 0x1026e2c */
  scra_v_count = 16; /* Line 212, Address: 0x1026e38 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x1026e44 */
  scra_hline = 160; /* Line 215, Address: 0x1026e60 */

  playposiset(); /* Line 217, Address: 0x1026e6c */
} /* Line 218, Address: 0x1026e74 */











void playposiset(void) { /* Line 230, Address: 0x1026e90 */
  unsigned short playpositbl[2] = { /* Line 231, Address: 0x1026ea8 */
    32,
    428
  };
  unsigned short endplpositbl[16] = { /* Line 235, Address: 0x1026ec4 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 245, Address: 0x1026ef8 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 255, Address: 0x1026f24 */
    playload(); /* Line 256, Address: 0x1026f38 */
    xWk = actwk[0].xposi.w.h; /* Line 257, Address: 0x1026f40 */
    yWk = actwk[0].yposi.w.h; /* Line 258, Address: 0x1026f50 */

    if (yWk < 0) yWk = 0; /* Line 260, Address: 0x1026f60 */

  } /* Line 262, Address: 0x1026f74 */
  else {

    if (demoflag.w < 0) { /* Line 265, Address: 0x1026f7c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 266, Address: 0x1026f94 */
    } /* Line 267, Address: 0x1026fbc */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 270, Address: 0x1026fc4 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 273, Address: 0x1026fe4 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 274, Address: 0x1027000 */
  }


  if ((unsigned short)xWk > 160) { /* Line 278, Address: 0x1027014 */
    xWk -= 160; /* Line 279, Address: 0x1027028 */
  } /* Line 280, Address: 0x1027034 */
  else {
    xWk = 0; /* Line 282, Address: 0x102703c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 286, Address: 0x1027040 */
    xWk = scralim_right; /* Line 287, Address: 0x1027064 */
  }
  scra_h_posit.w.h = xWk; /* Line 289, Address: 0x1027074 */

  if ((unsigned short)yWk > 96) { /* Line 291, Address: 0x102707c */
    yWk -= 96; /* Line 292, Address: 0x1027090 */
  } /* Line 293, Address: 0x102709c */
  else {
    yWk = 0; /* Line 295, Address: 0x10270a4 */
  }

  if (scralim_down < yWk) { /* Line 298, Address: 0x10270a8 */
    yWk = scralim_down; /* Line 299, Address: 0x10270cc */
  }

  scra_v_posit.w.h = yWk; /* Line 302, Address: 0x10270dc */

  scrbinit(xWk, yWk); /* Line 304, Address: 0x10270e4 */

  i = 0; /* Line 306, Address: 0x10270f4 */
  loopmapno = playmapnotbl[i++]; /* Line 307, Address: 0x10270f8 */
  loopmapno2 = playmapnotbl[i++]; /* Line 308, Address: 0x1027110 */
  ballmapno = playmapnotbl[i++]; /* Line 309, Address: 0x1027128 */
  ballmapno2 = playmapnotbl[i++]; /* Line 310, Address: 0x1027140 */


} /* Line 313, Address: 0x1027158 */











void scrbinit(short xWk, short yWk) { /* Line 325, Address: 0x1027180 */
  int i;
  short wD2;


  yWk = 536; /* Line 330, Address: 0x1027194 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 331, Address: 0x102719c */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 332, Address: 0x10271c4 */
    yWk -= wD2 / 2; /* Line 333, Address: 0x10271e0 */
    if (yWk < 0) { /* Line 334, Address: 0x1027214 */
      yWk = 0; /* Line 335, Address: 0x1027228 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 339, Address: 0x102722c */
  scrb_v_posit.w.l = 0; /* Line 340, Address: 0x1027238 */
  scrc_v_posit.w.h = yWk; /* Line 341, Address: 0x1027240 */
  scrz_v_posit.w.h = yWk; /* Line 342, Address: 0x102724c */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 344, Address: 0x1027258 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 345, Address: 0x1027290 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 346, Address: 0x10272d0 */


  for (i = 0; i < 10; ++i) { /* Line 349, Address: 0x1027310 */
    ((int*)hscrollwork)[i] = 0; /* Line 350, Address: 0x102731c */
  } /* Line 351, Address: 0x1027330 */

} /* Line 353, Address: 0x1027340 */












void scroll(void) { /* Line 366, Address: 0x1027360 */
  int LineSpdTbl[10] = { /* Line 367, Address: 0x1027380 */
    32768, 24576, 16384,
    12288,  8192,  8192,
    12288, 16384, 24576,
    32768
  };
  unsigned char z32b_cnttbl[10] = { /* Line 373, Address: 0x10273b4 */
    1, 1, 1, 1, 1, 5, 1, 1, 3, 1
  };
  unsigned char z32b_cnttbl0[3] = { /* Line 376, Address: 0x10273e8 */
    3, 1, 1
  };
  unsigned char z32b_cnttbl1[6] = { /* Line 379, Address: 0x102740c */
    5, 1, 1, 3, 1, 1
  };
  unsigned short z32b_kawatbl[3] = { /* Line 382, Address: 0x1027440 */
    64, 528, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 392, Address: 0x1027464 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 395, Address: 0x1027474 */
  scrchk(); /* Line 396, Address: 0x10274a0 */
  scroll_h(); /* Line 397, Address: 0x10274ac */
  scroll_v(); /* Line 398, Address: 0x10274b8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 400, Address: 0x10274c4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 401, Address: 0x10274d4 */


  scrollz_h(scra_hz << 4, 64); /* Line 404, Address: 0x10274e4 */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 405, Address: 0x1027508 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 406, Address: 0x1027544 */

  lD0.w.l = 536; /* Line 408, Address: 0x1027580 */
  wD1 = 1312; /* Line 409, Address: 0x1027588 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 410, Address: 0x1027590 */

    wD1 -= scra_v_posit.w.h; /* Line 412, Address: 0x10275b0 */
    wD1 >>= 1; /* Line 413, Address: 0x10275c4 */
    lD0.w.l -= wD1; /* Line 414, Address: 0x10275cc */
    if (lD0.w.l < 0) { /* Line 415, Address: 0x10275e0 */
      lD0.w.l = 0; /* Line 416, Address: 0x10275f4 */
    }
  } /* Line 418, Address: 0x10275f8 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 420, Address: 0x1027600 */
  }

  scrollb_v(lD0.w.l); /* Line 423, Address: 0x1027614 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x1027628 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 425, Address: 0x1027638 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 426, Address: 0x1027648 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 428, Address: 0x1027658 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 429, Address: 0x1027674 */
  scrflagz.b.h = 0; /* Line 430, Address: 0x1027690 */
  scrflagc.b.h = 0; /* Line 431, Address: 0x1027698 */























  pHscrWk = (int_union*)hscrollwork; /* Line 455, Address: 0x10276a0 */
  for (i = 0; i < 10; ++i) { /* Line 456, Address: 0x10276a8 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 457, Address: 0x10276b4 */
    ++pHscrWk; /* Line 458, Address: 0x10276cc */
  } /* Line 459, Address: 0x10276d0 */
  wD1 = 0; /* Line 460, Address: 0x10276e0 */
  for ( ; i < 74; ++i) { /* Line 461, Address: 0x10276e4 */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 462, Address: 0x10276ec */
    pHscrWk->l += lD2.l; /* Line 463, Address: 0x1027710 */
    ++pHscrWk; /* Line 464, Address: 0x1027720 */
    ++wD1; /* Line 465, Address: 0x1027724 */
  } /* Line 466, Address: 0x1027730 */







  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 474, Address: 0x1027740 */
  lD2.l <<= 5; /* Line 475, Address: 0x1027768 */
  lD2.l /= 12; /* Line 476, Address: 0x1027774 */
  lD2.l <<= 11; /* Line 477, Address: 0x1027794 */

  lD3.l = 0; /* Line 479, Address: 0x10277a0 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 480, Address: 0x10277a4 */

  pHScrollWork = &hscrollwork[155]; /* Line 482, Address: 0x10277b0 */
  for (i = 2; i >= 0; --i) { /* Line 483, Address: 0x10277bc */
    lD0.w.l = -lD3.w.l; /* Line 484, Address: 0x10277c8 */

    for (j = z32b_cnttbl0[i]; j >= 0; --j) { /* Line 486, Address: 0x10277e4 */
      *pHScrollWork-- = lD0.w.l; /* Line 487, Address: 0x10277f8 */
    } /* Line 488, Address: 0x102780c */

    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 490, Address: 0x1027818 */
    lD3.l += lD2.l; /* Line 491, Address: 0x102783c */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 492, Address: 0x102784c */
  } /* Line 493, Address: 0x1027870 */

  pHScrollWork = &hscrollwork[156]; /* Line 495, Address: 0x102787c */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 496, Address: 0x1027888 */

  for (i = 0; i < 4; ++i) { /* Line 498, Address: 0x10278ac */
    *pHScrollWork++ = lD0.w.l; /* Line 499, Address: 0x10278b8 */
  } /* Line 500, Address: 0x10278cc */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 502, Address: 0x10278dc */

  for (i = 0; i < 6; ++i) { /* Line 504, Address: 0x1027900 */
    *pHScrollWork++ = lD0.w.l; /* Line 505, Address: 0x102790c */
  } /* Line 506, Address: 0x1027920 */














  pHscrWk = (int_union*)hscrollwork; /* Line 521, Address: 0x1027930 */
  for (i = 9; i >= 0; --i) { /* Line 522, Address: 0x1027938 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 523, Address: 0x1027944 */
    ++pHscrWk; /* Line 524, Address: 0x1027970 */
    for (j = z32b_cnttbl[i]; j >= 0; --j) { /* Line 525, Address: 0x1027974 */
      *pHScrollWork++ = wD1; /* Line 526, Address: 0x1027988 */
    } /* Line 527, Address: 0x1027998 */
  } /* Line 528, Address: 0x10279a4 */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 531, Address: 0x10279b0 */

  for (i = 0; i < 10; ++i) { /* Line 533, Address: 0x10279d4 */
    *pHScrollWork++ = lD0.w.l; /* Line 534, Address: 0x10279e0 */
  } /* Line 535, Address: 0x10279f4 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 537, Address: 0x1027a04 */

  for (i = 0; i < 4; ++i) { /* Line 539, Address: 0x1027a28 */
    *pHScrollWork++ = lD0.w.l; /* Line 540, Address: 0x1027a34 */
  } /* Line 541, Address: 0x1027a48 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 543, Address: 0x1027a58 */

  for (i = 0; i < 8; ++i) { /* Line 545, Address: 0x1027a7c */
    *pHScrollWork++ = lD0.w.l; /* Line 546, Address: 0x1027a88 */
  } /* Line 547, Address: 0x1027a9c */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 549, Address: 0x1027aac */

  for (i = 0; i < 4; ++i) { /* Line 551, Address: 0x1027ad0 */
    *pHScrollWork++ = lD0.w.l; /* Line 552, Address: 0x1027adc */
  } /* Line 553, Address: 0x1027af0 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 556, Address: 0x1027b00 */
  lD2.l <<= 6; /* Line 557, Address: 0x1027b38 */
  lD2.l /= 24; /* Line 558, Address: 0x1027b44 */
  lD2.l <<= 10; /* Line 559, Address: 0x1027b64 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 560, Address: 0x1027b70 */

  for (i = 5; i >= 0; --i) { /* Line 562, Address: 0x1027b7c */
    lD0.w.l = -lD3.w.l; /* Line 563, Address: 0x1027b88 */
    for (j = z32b_cnttbl1[i]; j >= 0; --j) { /* Line 564, Address: 0x1027ba4 */
      *pHScrollWork++ = lD0.w.l; /* Line 565, Address: 0x1027bb8 */
    } /* Line 566, Address: 0x1027bcc */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 567, Address: 0x1027bd8 */
    lD3.l += lD2.l; /* Line 568, Address: 0x1027bfc */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 569, Address: 0x1027c0c */
  } /* Line 570, Address: 0x1027c30 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 572, Address: 0x1027c40 */

  for (i = 0; i < 8; ++i) { /* Line 574, Address: 0x1027c64 */
    *pHScrollWork++ = lD0.w.l; /* Line 575, Address: 0x1027c70 */
  } /* Line 576, Address: 0x1027c84 */

  pHScrollBuff = lphscrollbuff; /* Line 578, Address: 0x1027c94 */
  pHScrollWork = &hscrollwork[148]; /* Line 579, Address: 0x1027ca0 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 580, Address: 0x1027cac */
  lD2.w.l = lD0.w.l; /* Line 581, Address: 0x1027cb8 */
  wD4 = lD0.w.l; /* Line 582, Address: 0x1027cc0 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 583, Address: 0x1027cc8 */
  wD3 = lD0.w.l >> 1; /* Line 584, Address: 0x1027cec */
  wD1 = 87; /* Line 585, Address: 0x1027d04 */
  wD5 = 28; /* Line 586, Address: 0x1027d0c */
  if (wD3 <= wD1) { /* Line 587, Address: 0x1027d14 */

    wD1 -= wD3; /* Line 589, Address: 0x1027d28 */
    if (wD1 >= 27) { /* Line 590, Address: 0x1027d30 */
      wD1 = 28; /* Line 591, Address: 0x1027d40 */
    }

    wD5 -= wD1; /* Line 594, Address: 0x1027d4c */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 595, Address: 0x1027d54 */
    waterdirec.w += 64; /* Line 596, Address: 0x1027d78 */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z32b_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 598, Address: 0x1027d8c */


  } /* Line 601, Address: 0x1027dc0 */
  else {
    wD1 -= wD3; /* Line 603, Address: 0x1027dc8 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 608, Address: 0x1027dd0 */
  pHScrollWork = &hscrollwork[20]; /* Line 609, Address: 0x1027de4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 610, Address: 0x1027df0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 611, Address: 0x1027e04 */

  for ( ; (short)wD1 >= 0; --wD1) { /* Line 613, Address: 0x1027e1c */
    lD2.w.h = *pHScrollWork++; /* Line 614, Address: 0x1027e24 */
    lD2.w.l = *pHScrollWork++; /* Line 615, Address: 0x1027e38 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 616, Address: 0x1027e4c */
    lD2.w.l *= -1; /* Line 617, Address: 0x1027e60 */
    lD0.w.l = lD2.w.l; /* Line 618, Address: 0x1027e6c */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 619, Address: 0x1027e74 */
    if (wD3 <= wD4) { /* Line 620, Address: 0x1027e94 */
      wD5 &= 255; /* Line 621, Address: 0x1027eac */
      wD3 = (short)(char)awasintbl[wD5] * 2; /* Line 622, Address: 0x1027eb4 */
      wD3 += scra_h_posit.w.h; /* Line 623, Address: 0x1027eec */
      wD3 = -(short)wD3; /* Line 624, Address: 0x1027f00 */
      lD0.w.h = wD3; /* Line 625, Address: 0x1027f1c */
    }

    pHScrollBuff->l = lD0.l; /* Line 628, Address: 0x1027f20 */
    ++pHScrollBuff; /* Line 629, Address: 0x1027f2c */
    ++wD4; /* Line 630, Address: 0x1027f38 */
    ++wD5; /* Line 631, Address: 0x1027f44 */
  } /* Line 632, Address: 0x1027f50 */

} /* Line 634, Address: 0x1027f70 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 639, Address: 0x1027fa0 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 646, Address: 0x1027fd4 */
  pA1 = *ppA1; /* Line 647, Address: 0x1027ff4 */
  pA2 = *ppA2; /* Line 648, Address: 0x1027ffc */

  if (*pA3 <= *pwD4) goto label6; /* Line 650, Address: 0x1028004 */



label1:
  *pwD2 &= 7; /* Line 655, Address: 0x1028028 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 656, Address: 0x102803c */

  lD0.w.l = *pA2++; /* Line 658, Address: 0x1028068 */
  i = 8 - *pwD2; /* Line 659, Address: 0x1028078 */
  goto label4; /* Line 660, Address: 0x102808c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 663, Address: 0x1028094 */


  if (*pA3 <= *pwD4) goto label7; /* Line 666, Address: 0x10280b0 */



label3:
  lD0.w.l = *pA2++; /* Line 671, Address: 0x10280d4 */
  *pwD4 += 8; /* Line 672, Address: 0x10280e4 */


  i = 8; /* Line 675, Address: 0x10280f8 */
label4:
  for ( ; i > 0; --i) { /* Line 677, Address: 0x10280fc */


    pA1->l = lD0.l; /* Line 680, Address: 0x1028104 */
    ++pA1; /* Line 681, Address: 0x102810c */
  } /* Line 682, Address: 0x1028110 */
  if ((short)--wD1 >= 0) goto label2; /* Line 683, Address: 0x1028120 */



label5:
  *ppA1 = pA1; /* Line 688, Address: 0x1028148 */
  *ppA2 = pA2; /* Line 689, Address: 0x1028150 */
  return; /* Line 690, Address: 0x1028158 */


label6:
  wD3 = *pA3++ + 32 - *pwD4; /* Line 694, Address: 0x1028160 */
  if ((short)wD3 > 0) goto label8; /* Line 695, Address: 0x1028190 */


  if (*pA3 > *pwD4) goto label1; /* Line 698, Address: 0x10281a8 */


  wD3 = *pA3++ + 32 - *pwD4; /* Line 701, Address: 0x10281cc */
  if ((short)wD3 > 0) goto label8; /* Line 702, Address: 0x10281fc */
  goto label1; /* Line 703, Address: 0x1028214 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 711, Address: 0x102821c */
  if ((short)wD3 <= 0) goto label3; /* Line 712, Address: 0x102824c */



label8:
  --wD3; /* Line 717, Address: 0x1028264 */
  wD6 = wD3; /* Line 718, Address: 0x102826c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 719, Address: 0x1028270 */

  do {
    *pwD2 &= 255; /* Line 722, Address: 0x1028288 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 723, Address: 0x102829c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 724, Address: 0x10282c8 */
    lD0.w.l = -lD0.w.l; /* Line 725, Address: 0x10282dc */
    pA1->w.h = lD0.w.h; /* Line 726, Address: 0x10282f8 */
    pA1->w.l = lD0.w.l; /* Line 727, Address: 0x1028300 */
    ++pA1; /* Line 728, Address: 0x1028308 */
    ++*pwD4; /* Line 729, Address: 0x102830c */
    ++*pwD2; /* Line 730, Address: 0x1028320 */
  } while ((short)--wD3 >= 0); /* Line 731, Address: 0x1028334 */

  wD6 >>= 3; /* Line 733, Address: 0x1028358 */

  do {
    lD0.w.l = *pA2++; /* Line 736, Address: 0x1028360 */
    --wD1; /* Line 737, Address: 0x1028370 */
  } while ((short)--wD6 >= 0); /* Line 738, Address: 0x102837c */
  goto label2; /* Line 739, Address: 0x10283a0 */
} /* Line 740, Address: 0x10283a8 */















void scroll_h(void) { /* Line 756, Address: 0x10283d0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 759, Address: 0x10283dc */
  scrh_move(); /* Line 760, Address: 0x10283e8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 761, Address: 0x10283f0 */
    scra_h_count ^= 16; /* Line 762, Address: 0x1028424 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 763, Address: 0x1028438 */
      scrflaga.b.h |= 4; /* Line 764, Address: 0x1028464 */
    } /* Line 765, Address: 0x1028478 */
    else {

      scrflaga.b.h |= 8; /* Line 768, Address: 0x1028480 */
    }
  }


} /* Line 773, Address: 0x1028494 */

void scrh_move(void) { /* Line 775, Address: 0x10284b0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 778, Address: 0x10284bc */
  wD0 -= scra_h_posit.w.h; /* Line 779, Address: 0x10284c8 */
  wD0 -= scra_hline; /* Line 780, Address: 0x10284dc */
  if (wD0 == 0) { /* Line 781, Address: 0x10284f0 */

    scra_hz = 0; /* Line 783, Address: 0x10284fc */
  } /* Line 784, Address: 0x1028504 */
  else if ((short)wD0 < 0) { /* Line 785, Address: 0x102850c */
    left_check(wD0); /* Line 786, Address: 0x1028524 */
  } /* Line 787, Address: 0x1028530 */
  else {
    right_check(wD0); /* Line 789, Address: 0x1028538 */
  }

} /* Line 792, Address: 0x1028544 */


void right_check(unsigned short wD0) { /* Line 795, Address: 0x1028560 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 798, Address: 0x102856c */
    wD0 = 16; /* Line 799, Address: 0x102858c */
  }

  wD0 += scra_h_posit.w.h; /* Line 802, Address: 0x1028594 */
  if (scralim_right < (short)wD0) { /* Line 803, Address: 0x10285ac */
    wD0 = scralim_right; /* Line 804, Address: 0x10285dc */
  }

  wD1 = wD0; /* Line 807, Address: 0x10285e8 */
  wD1 -= scra_h_posit.w.h; /* Line 808, Address: 0x10285f0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 809, Address: 0x1028604 */
  scra_h_posit.w.h = wD0; /* Line 810, Address: 0x1028634 */
  scra_hz = wD1; /* Line 811, Address: 0x1028640 */

} /* Line 813, Address: 0x1028648 */


void left_check(unsigned short wD0) { /* Line 816, Address: 0x1028660 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 819, Address: 0x102866c */
    wD0 = -16; /* Line 820, Address: 0x102868c */
  }

  wD0 += scra_h_posit.w.h; /* Line 823, Address: 0x1028694 */
  if (scralim_left > (short)wD0) { /* Line 824, Address: 0x10286ac */
    wD0 = scralim_left; /* Line 825, Address: 0x10286dc */
  }

  wD1 = wD0; /* Line 828, Address: 0x10286e8 */
  wD1 -= scra_h_posit.w.h; /* Line 829, Address: 0x10286f0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 830, Address: 0x1028704 */
  scra_h_posit.w.h = wD0; /* Line 831, Address: 0x1028734 */
  scra_hz = wD1; /* Line 832, Address: 0x1028740 */

} /* Line 834, Address: 0x1028748 */


















void scroll_v(void) { /* Line 853, Address: 0x1028760 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 856, Address: 0x102876c */
  if (actwk[0].cddat & 4) { /* Line 857, Address: 0x1028798 */
    wD0 -= 5; /* Line 858, Address: 0x10287b0 */
  }

  if (actwk[0].cddat & 2) { /* Line 861, Address: 0x10287b8 */
    wD0 += 32; /* Line 862, Address: 0x10287d0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 863, Address: 0x10287d8 */
      wD0 -= scra_vline; /* Line 864, Address: 0x10287f8 */
      sv_move_main2(wD0); /* Line 865, Address: 0x102880c */
      return; /* Line 866, Address: 0x1028818 */
    }
    wD0 -= scra_vline; /* Line 868, Address: 0x1028820 */
    if (wD0 >= 64) { /* Line 869, Address: 0x1028834 */
      wD0 -= 64; /* Line 870, Address: 0x1028844 */
      sv_move_main2(wD0); /* Line 871, Address: 0x102884c */
      return; /* Line 872, Address: 0x1028858 */
    }
    wD0 -= 64; /* Line 874, Address: 0x1028860 */
    if (limmoveflag == 0) goto label1; /* Line 875, Address: 0x1028868 */
    sv_move_sub2(); /* Line 876, Address: 0x102887c */
    return; /* Line 877, Address: 0x1028884 */
  }




  wD0 -= scra_vline; /* Line 883, Address: 0x102888c */
  if (wD0) { /* Line 884, Address: 0x10288a0 */
    sv_move_main(wD0); /* Line 885, Address: 0x10288a8 */
    return; /* Line 886, Address: 0x10288b4 */
  }
  if (limmoveflag == 0) { /* Line 888, Address: 0x10288bc */
    sv_move_sub2(); /* Line 889, Address: 0x10288d0 */
    return; /* Line 890, Address: 0x10288d8 */
  }


label1:
  scra_vz = 0; /* Line 895, Address: 0x10288e0 */

} /* Line 897, Address: 0x10288e8 */





void sv_move_main(unsigned short wD0) { /* Line 903, Address: 0x1028900 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 906, Address: 0x1028910 */
    sv_move_main1(wD0); /* Line 907, Address: 0x102892c */
  } /* Line 908, Address: 0x1028938 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 911, Address: 0x1028940 */
    if ((short)wD1 < 0) { /* Line 912, Address: 0x102894c */
      wD1 = -(short)wD1; /* Line 913, Address: 0x1028964 */
    }

    if (wD1 >= 2048) { /* Line 916, Address: 0x1028980 */
      sv_move_main2(wD0); /* Line 917, Address: 0x1028990 */
    } /* Line 918, Address: 0x102899c */
    else {
      if ((short)wD0 > 6) { /* Line 920, Address: 0x10289a4 */
        sv_move_plus(1536); /* Line 921, Address: 0x10289c4 */
      } /* Line 922, Address: 0x10289d0 */
      else if ((short)wD0 < -6) { /* Line 923, Address: 0x10289d8 */
        sv_move_minus(1536); /* Line 924, Address: 0x10289f8 */
      } /* Line 925, Address: 0x1028a04 */
      else {
        sv_move_sub(wD0); /* Line 927, Address: 0x1028a0c */
      }
    }
  }
} /* Line 931, Address: 0x1028a18 */



void sv_move_main1(unsigned short wD0) { /* Line 935, Address: 0x1028a30 */

  if ((short)wD0 > 2) { /* Line 937, Address: 0x1028a3c */
    sv_move_plus(512); /* Line 938, Address: 0x1028a5c */
  } /* Line 939, Address: 0x1028a68 */
  else if ((short)wD0 < -2) { /* Line 940, Address: 0x1028a70 */
    sv_move_minus(512); /* Line 941, Address: 0x1028a90 */
  } /* Line 942, Address: 0x1028a9c */
  else {
    sv_move_sub(wD0); /* Line 944, Address: 0x1028aa4 */
  }

} /* Line 947, Address: 0x1028ab0 */


void sv_move_main2(unsigned short wD0) { /* Line 950, Address: 0x1028ac0 */

  if ((short)wD0 > 16) { /* Line 952, Address: 0x1028acc */
    sv_move_plus(4096); /* Line 953, Address: 0x1028aec */
  } /* Line 954, Address: 0x1028af8 */
  else if ((short)wD0 < -16) { /* Line 955, Address: 0x1028b00 */
    sv_move_minus(4096); /* Line 956, Address: 0x1028b20 */
  } /* Line 957, Address: 0x1028b2c */
  else {
    sv_move_sub(wD0); /* Line 959, Address: 0x1028b34 */
  }

} /* Line 962, Address: 0x1028b40 */


void sv_move_sub2(void) { /* Line 965, Address: 0x1028b50 */
  limmoveflag = 0; /* Line 966, Address: 0x1028b58 */
  sv_move_sub(0); /* Line 967, Address: 0x1028b60 */
} /* Line 968, Address: 0x1028b6c */


void sv_move_sub(unsigned short wD0) { /* Line 971, Address: 0x1028b80 */
  int_union lD1;

  lD1.w.h = 0; /* Line 974, Address: 0x1028b8c */
  lD1.w.l = wD0; /* Line 975, Address: 0x1028b90 */
  lD1.l += scra_v_posit.w.h; /* Line 976, Address: 0x1028b98 */
  if ((short)wD0 > 0) { /* Line 977, Address: 0x1028bb4 */
    scrv_down_ch(lD1); /* Line 978, Address: 0x1028bd0 */
  } /* Line 979, Address: 0x1028bdc */
  else {
    scrv_up_ch(lD1); /* Line 981, Address: 0x1028be4 */
  }

} /* Line 984, Address: 0x1028bf0 */




void sv_move_minus(unsigned short wD1) { /* Line 989, Address: 0x1028c00 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 993, Address: 0x1028c10 */
  lD1.l <<= 8; /* Line 994, Address: 0x1028c2c */
  lD1.l += scra_v_posit.l; /* Line 995, Address: 0x1028c38 */

  wk = lD1.w.h; /* Line 997, Address: 0x1028c4c */
  lD1.w.h = lD1.w.l; /* Line 998, Address: 0x1028c54 */
  lD1.w.l = wk; /* Line 999, Address: 0x1028c5c */
  scrv_up_ch(lD1); /* Line 1000, Address: 0x1028c60 */
} /* Line 1001, Address: 0x1028c6c */



void scrv_up_ch(int_union lD1) { /* Line 1005, Address: 0x1028c80 */
  if (scralim_up >= lD1.w.l) { /* Line 1006, Address: 0x1028c8c */
    if (lD1.w.l < -255) { /* Line 1007, Address: 0x1028cb4 */
      lD1.w.l &= 2047; /* Line 1008, Address: 0x1028ccc */
      actwk[0].yposi.w.h &= 32767; /* Line 1009, Address: 0x1028cd8 */
      scra_v_posit.w.h &= 2047; /* Line 1010, Address: 0x1028cec */
      scrb_v_posit.w.h &= 1023; /* Line 1011, Address: 0x1028d00 */
    } /* Line 1012, Address: 0x1028d14 */
    else {

      lD1.w.l = scralim_up; /* Line 1015, Address: 0x1028d1c */
    }
  }
  scrv_move(lD1); /* Line 1018, Address: 0x1028d28 */

} /* Line 1020, Address: 0x1028d34 */





void sv_move_plus(unsigned short wD1) { /* Line 1026, Address: 0x1028d50 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1030, Address: 0x1028d60 */
  lD1.w.l = wD1; /* Line 1031, Address: 0x1028d64 */
  lD1.l <<= 8; /* Line 1032, Address: 0x1028d6c */
  lD1.l += scra_v_posit.l; /* Line 1033, Address: 0x1028d78 */

  wk = lD1.w.h; /* Line 1035, Address: 0x1028d8c */
  lD1.w.h = lD1.w.l; /* Line 1036, Address: 0x1028d94 */
  lD1.w.l = wk; /* Line 1037, Address: 0x1028d9c */

  scrv_down_ch(lD1); /* Line 1039, Address: 0x1028da0 */

} /* Line 1041, Address: 0x1028dac */



void scrv_down_ch(int_union lD1) { /* Line 1045, Address: 0x1028dc0 */
  if (scralim_down <= lD1.w.l) { /* Line 1046, Address: 0x1028dcc */
    lD1.w.l -= 2048; /* Line 1047, Address: 0x1028df4 */
    if (lD1.w.l > 0) { /* Line 1048, Address: 0x1028e00 */
      actwk[0].yposi.w.h &= 2047; /* Line 1049, Address: 0x1028e14 */
      scra_v_posit.w.h -= 2048; /* Line 1050, Address: 0x1028e28 */
      scrb_v_posit.w.h &= 1023; /* Line 1051, Address: 0x1028e3c */
    } /* Line 1052, Address: 0x1028e50 */
    else {
      lD1.w.l = scralim_down; /* Line 1054, Address: 0x1028e58 */
    }
  }
  scrv_move(lD1); /* Line 1057, Address: 0x1028e64 */

} /* Line 1059, Address: 0x1028e70 */


void scrv_move(int_union lD1) { /* Line 1062, Address: 0x1028e80 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1065, Address: 0x1028e90 */

  wk = lD1.w.h; /* Line 1067, Address: 0x1028e9c */
  lD1.w.h = lD1.w.l; /* Line 1068, Address: 0x1028ea4 */
  lD1.w.l = wk; /* Line 1069, Address: 0x1028eac */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1071, Address: 0x1028eb0 */
  scra_v_posit.l = lD1.l; /* Line 1072, Address: 0x1028ed8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1075, Address: 0x1028ee4 */
    scra_v_count ^= 16; /* Line 1076, Address: 0x1028f18 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1077, Address: 0x1028f2c */

      scrflaga.b.h |= 2; /* Line 1079, Address: 0x1028f58 */
    } /* Line 1080, Address: 0x1028f6c */
    else {
      scrflaga.b.h |= 1; /* Line 1082, Address: 0x1028f74 */
    }
  }


} /* Line 1087, Address: 0x1028f88 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1091, Address: 0x1028fa0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1094, Address: 0x1028fac */
  lD0.l += lD4.l; /* Line 1095, Address: 0x1028fbc */
  scrb_h_posit.l = lD0.l; /* Line 1096, Address: 0x1028fcc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1098, Address: 0x1028fd8 */

    scrb_h_count ^= 16; /* Line 1100, Address: 0x102900c */
    lD0.l -= lD2.l; /* Line 1101, Address: 0x1029020 */
    if ((long int)lD0.l < 0) { /* Line 1102, Address: 0x1029030 */
      scrflagb.b.h |= 4; /* Line 1103, Address: 0x1029044 */
    } /* Line 1104, Address: 0x1029058 */
    else {

      scrflagb.b.h |= 8; /* Line 1107, Address: 0x1029060 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1112, Address: 0x1029074 */
  lD0.l += lD5.l; /* Line 1113, Address: 0x1029084 */
  scrb_h_posit.l = lD0.l; /* Line 1114, Address: 0x1029094 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1116, Address: 0x10290a0 */

    scrb_v_count ^= 16; /* Line 1118, Address: 0x10290d4 */
    lD0.l -= lD3.l; /* Line 1119, Address: 0x10290e8 */
    if ((long int)lD0.l < 0) { /* Line 1120, Address: 0x10290f8 */
      scrflagb.b.h |= 1; /* Line 1121, Address: 0x102910c */
    } /* Line 1122, Address: 0x1029120 */
    else {

      scrflagb.b.h |= 2; /* Line 1125, Address: 0x1029128 */
    }
  }


} /* Line 1130, Address: 0x102913c */






void scrollb_v(unsigned short wD0) { /* Line 1137, Address: 0x1029150 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1140, Address: 0x102915c */
  scrb_v_posit.w.h = wD0; /* Line 1141, Address: 0x1029168 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1143, Address: 0x1029174 */
    scrb_v_count ^= 16; /* Line 1144, Address: 0x10291a0 */
    if ((short)wD3 > (short)wD0) { /* Line 1145, Address: 0x10291b4 */
      scrflagb.b.h |= 1; /* Line 1146, Address: 0x10291e4 */
    } /* Line 1147, Address: 0x10291f8 */
    else {

      scrflagb.b.h |= 2; /* Line 1150, Address: 0x1029200 */
    }
  }


} /* Line 1155, Address: 0x1029214 */



void scrollb_h(int lD4, int flagb) { /* Line 1159, Address: 0x1029230 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1163, Address: 0x1029240 */
  lD0.l = lD2.l + lD4; /* Line 1164, Address: 0x102924c */
  scrb_h_posit.l = lD0.l; /* Line 1165, Address: 0x102925c */

  lD1.w.h = lD0.w.l; /* Line 1167, Address: 0x1029268 */
  lD1.w.l = lD0.w.h; /* Line 1168, Address: 0x1029270 */
  lD1.w.l &= 16; /* Line 1169, Address: 0x1029278 */

  bD3 = scrb_h_count; /* Line 1171, Address: 0x1029284 */
  lD1.b.b4 ^= bD3; /* Line 1172, Address: 0x1029290 */
  if (!lD1.b.b4) { /* Line 1173, Address: 0x10292a4 */
    scrb_h_count ^= 16; /* Line 1174, Address: 0x10292b0 */
    lD0.l -= lD2.l; /* Line 1175, Address: 0x10292c4 */
    if ((long int)lD0.l < 0) { /* Line 1176, Address: 0x10292d4 */
      scrflagb.b.h |= flagb; /* Line 1177, Address: 0x10292e8 */
    } /* Line 1178, Address: 0x1029304 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1181, Address: 0x102930c */
    }
  }


} /* Line 1186, Address: 0x102932c */



void scrollc_h(int lD4, int flagc) { /* Line 1190, Address: 0x1029340 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1194, Address: 0x1029350 */
  lD0.l = lD2.l + lD4; /* Line 1195, Address: 0x102935c */
  scrc_h_posit.l = lD0.l; /* Line 1196, Address: 0x102936c */

  lD1.w.h = lD0.w.l; /* Line 1198, Address: 0x1029378 */
  lD1.w.l = lD0.w.h; /* Line 1199, Address: 0x1029380 */
  lD1.w.l &= 16; /* Line 1200, Address: 0x1029388 */

  bD3 = scrc_h_count; /* Line 1202, Address: 0x1029394 */
  lD1.b.b4 ^= bD3; /* Line 1203, Address: 0x10293a0 */
  if (!lD1.b.b4) { /* Line 1204, Address: 0x10293b4 */
    scrc_h_count ^= 16; /* Line 1205, Address: 0x10293c0 */
    lD0.l -= lD2.l; /* Line 1206, Address: 0x10293d4 */
    if ((long int)lD0.l < 0) { /* Line 1207, Address: 0x10293e4 */
      scrflagc.b.h |= flagc; /* Line 1208, Address: 0x10293f8 */
    } /* Line 1209, Address: 0x1029414 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1212, Address: 0x102941c */
    }
  }


} /* Line 1217, Address: 0x102943c */











void scrollz_h(int lD4, int flagz) { /* Line 1229, Address: 0x1029450 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1233, Address: 0x1029460 */
  lD0.l = lD2.l + lD4; /* Line 1234, Address: 0x102946c */
  scrz_h_posit.l = lD0.l; /* Line 1235, Address: 0x102947c */

  lD1.w.h = lD0.w.l; /* Line 1237, Address: 0x1029488 */
  lD1.w.l = lD0.w.h; /* Line 1238, Address: 0x1029490 */
  lD1.w.l &= 16; /* Line 1239, Address: 0x1029498 */

  bD3 = scrz_h_count; /* Line 1241, Address: 0x10294a4 */
  lD1.b.b4 ^= bD3; /* Line 1242, Address: 0x10294b0 */
  if (!lD1.b.b4) { /* Line 1243, Address: 0x10294c4 */
    scrz_h_count ^= 16; /* Line 1244, Address: 0x10294d0 */
    lD0.l -= lD2.l; /* Line 1245, Address: 0x10294e4 */
    if ((long int)lD0.l < 0) { /* Line 1246, Address: 0x10294f4 */
      scrflagz.b.h |= flagz; /* Line 1247, Address: 0x1029508 */
    } /* Line 1248, Address: 0x1029524 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1251, Address: 0x102952c */
    }
  }


} /* Line 1256, Address: 0x102954c */














void scrollwrtadva(void) { /* Line 1271, Address: 0x1029560 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1277, Address: 0x102957c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1278, Address: 0x1029580 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1279, Address: 0x102958c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1280, Address: 0x1029598 */
  pScrFlag = &scrflagb.b.h; /* Line 1281, Address: 0x10295a0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1282, Address: 0x10295a8 */







} /* Line 1290, Address: 0x10295bc */












void scrollwrt(void) { /* Line 1303, Address: 0x10295e0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1312, Address: 0x1029600 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1313, Address: 0x1029604 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1314, Address: 0x1029610 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1315, Address: 0x102961c */
  pScrFlag = &scrflagbw.b.h; /* Line 1316, Address: 0x1029624 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1317, Address: 0x102962c */

  VramBase = 16384; /* Line 1319, Address: 0x1029640 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1320, Address: 0x1029644 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1321, Address: 0x1029650 */
  pMapWk = (unsigned char*)mapwka; /* Line 1322, Address: 0x102965c */
  pScrFlag = &scrflagaw.b.h; /* Line 1323, Address: 0x1029664 */

  if (*pScrFlag) { /* Line 1325, Address: 0x102966c */
    if (*pScrFlag & 1) { /* Line 1326, Address: 0x1029678 */
      *pScrFlag &= 254; /* Line 1327, Address: 0x102968c */

      lD4.l = -16; /* Line 1329, Address: 0x1029698 */
      wD5 = 65520; /* Line 1330, Address: 0x10296a0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1332, Address: 0x10296a8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1334, Address: 0x10296c8 */
    }




    if (*pScrFlag & 2) { /* Line 1340, Address: 0x10296f4 */
      *pScrFlag &= 253; /* Line 1341, Address: 0x1029708 */

      lD4.l = 224; /* Line 1343, Address: 0x1029714 */
      wD5 = 65520; /* Line 1344, Address: 0x102971c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1345, Address: 0x1029724 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1347, Address: 0x1029744 */
    }




    if (*pScrFlag & 4) { /* Line 1353, Address: 0x1029770 */
      *pScrFlag &= 251; /* Line 1354, Address: 0x1029784 */

      lD4.l = -16; /* Line 1356, Address: 0x1029790 */
      wD5 = 65520; /* Line 1357, Address: 0x1029798 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1358, Address: 0x10297a0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1360, Address: 0x10297c0 */
    }




    if (*pScrFlag & 8) { /* Line 1366, Address: 0x10297ec */
      *pScrFlag &= 247; /* Line 1367, Address: 0x1029800 */

      lD4.l = -16; /* Line 1369, Address: 0x102980c */
      wD5 = 320; /* Line 1370, Address: 0x1029814 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1371, Address: 0x102981c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1373, Address: 0x102983c */
    }
  }






} /* Line 1382, Address: 0x1029868 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1399, Address: 0x1029890 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1410, Address: 0x10298bc */

  if (*pScrFlag & 1) { /* Line 1412, Address: 0x10298c4 */
    *pScrFlag &= 254; /* Line 1413, Address: 0x10298dc */
  } /* Line 1414, Address: 0x10298f0 */
  else {
    *pScrFlag &= 254; /* Line 1416, Address: 0x10298f8 */

    if (*pScrFlag & 2) { /* Line 1418, Address: 0x102990c */
      *pScrFlag &= 253; /* Line 1419, Address: 0x1029924 */
      lD4.w.l = 224; /* Line 1420, Address: 0x1029938 */
    } /* Line 1421, Address: 0x1029940 */
    else {
      *pScrFlag &= 253; /* Line 1423, Address: 0x1029948 */
      goto label1; /* Line 1424, Address: 0x102995c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1429, Address: 0x1029964 */
  wD0 &= 127; /* Line 1430, Address: 0x10299b4 */
  wD0 = z32bwrttbl[wD0 + 1]; /* Line 1431, Address: 0x10299bc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1437, Address: 0x10299dc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1438, Address: 0x10299fc */
  if (wD0 != 0) { /* Line 1439, Address: 0x1029a20 */
    wD5 = 65520; /* Line 1440, Address: 0x1029a2c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1441, Address: 0x1029a34 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1443, Address: 0x1029a54 */



  } /* Line 1447, Address: 0x1029a80 */
  else {

    wD5 = 0; /* Line 1450, Address: 0x1029a88 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1451, Address: 0x1029a8c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1455, Address: 0x1029aac */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1462, Address: 0x1029ad8 */






    lD4.l = -16; /* Line 1469, Address: 0x1029aec */
    wD5 = 65520; /* Line 1470, Address: 0x1029af4 */
    if (*pScrFlag & 168) { /* Line 1471, Address: 0x1029afc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1472, Address: 0x1029b14 */
      wD5 = 320; /* Line 1473, Address: 0x1029b34 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1477, Address: 0x1029b3c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1479, Address: 0x1029b6c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1480, Address: 0x1029b78 */



    for (i = 0; i < 16; ++i) { /* Line 1484, Address: 0x1029b88 */
      wD0 = z32bwrttbl[WrtTblCnt++]; /* Line 1485, Address: 0x1029b94 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1486, Address: 0x1029bb4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1487, Address: 0x1029be0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1488, Address: 0x1029c00 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1490, Address: 0x1029c24 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1493, Address: 0x1029c48 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1495, Address: 0x1029c68 */
      }
      lD4.w.l += 16; /* Line 1497, Address: 0x1029c7c */
    } /* Line 1498, Address: 0x1029c88 */
    *pScrFlag = 0; /* Line 1499, Address: 0x1029c98 */
  }
} /* Line 1501, Address: 0x1029ca0 */







void scrollwrtc(void) {} /* Line 1509, Address: 0x1029cd0 */




void scrollwrtz(void) {} /* Line 1514, Address: 0x1029ce0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1535, Address: 0x1029cf0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1548, Address: 0x1029d18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1551, Address: 0x1029d38 */
    pTilePoint->x += 2; /* Line 1552, Address: 0x1029d4c */
    if (pTilePoint->x >= 64) { /* Line 1553, Address: 0x1029d60 */
      pTilePoint->x -= 64; /* Line 1554, Address: 0x1029d74 */
    }
    xOffs += 16; /* Line 1556, Address: 0x1029d88 */
  } while (--lpcnt >= 0); /* Line 1557, Address: 0x1029d94 */
} /* Line 1558, Address: 0x1029da8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1562, Address: 0x1029dc0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1566, Address: 0x1029de8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1569, Address: 0x1029e08 */
    pTilePoint->x += 2; /* Line 1570, Address: 0x1029e1c */
    if (pTilePoint->x >= 64) { /* Line 1571, Address: 0x1029e30 */
      pTilePoint->x -= 64; /* Line 1572, Address: 0x1029e44 */
    }
    xOffs += 16; /* Line 1574, Address: 0x1029e58 */
  } while (--lpcnt >= 0); /* Line 1575, Address: 0x1029e64 */
} /* Line 1576, Address: 0x1029e78 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1595, Address: 0x1029e90 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1599, Address: 0x1029eb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1602, Address: 0x1029ed8 */
    pTilePoint->y += 2; /* Line 1603, Address: 0x1029eec */
    if (pTilePoint->y >= 32) { /* Line 1604, Address: 0x1029efc */
      pTilePoint->y -= 32; /* Line 1605, Address: 0x1029f10 */
    }
    yOffs += 16; /* Line 1607, Address: 0x1029f20 */
  } while (--lpcnt >= 0); /* Line 1608, Address: 0x1029f2c */
} /* Line 1609, Address: 0x1029f40 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1628, Address: 0x1029f50 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1634, Address: 0x1029f84 */

    base = 1; /* Line 1636, Address: 0x1029f94 */
  } /* Line 1637, Address: 0x1029f98 */
  else if (VramBase == 16384) { /* Line 1638, Address: 0x1029fa0 */

    base = 0; /* Line 1640, Address: 0x1029fb0 */
  }
  x = pTilePoint->x; /* Line 1642, Address: 0x1029fb4 */
  y = pTilePoint->y; /* Line 1643, Address: 0x1029fbc */


  frip = BlkIndex & 6144; /* Line 1646, Address: 0x1029fc4 */
  BlkIndex &= 1023; /* Line 1647, Address: 0x1029fcc */
  if (frip == 6144) { /* Line 1648, Address: 0x1029fd8 */

    p0 = 3, p1 = 2; /* Line 1650, Address: 0x1029fe4 */
    p2 = 1, p3 = 0; /* Line 1651, Address: 0x1029fec */
  } /* Line 1652, Address: 0x1029ff4 */
  else if (frip & 4096) { /* Line 1653, Address: 0x1029ffc */

    p0 = 2, p1 = 3; /* Line 1655, Address: 0x102a008 */
    p2 = 0, p3 = 1; /* Line 1656, Address: 0x102a010 */
  } /* Line 1657, Address: 0x102a018 */
  else if (frip & 2048) { /* Line 1658, Address: 0x102a020 */

    p0 = 1, p1 = 0; /* Line 1660, Address: 0x102a02c */
    p2 = 3, p3 = 2; /* Line 1661, Address: 0x102a034 */
  } /* Line 1662, Address: 0x102a03c */
  else {

    p0 = 0, p1 = 1; /* Line 1665, Address: 0x102a044 */
    p2 = 2, p3 = 3; /* Line 1666, Address: 0x102a04c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1669, Address: 0x102a054 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1670, Address: 0x102a098 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1671, Address: 0x102a0dc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1672, Address: 0x102a120 */

} /* Line 1674, Address: 0x102a164 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1692, Address: 0x102a1a0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1693, Address: 0x102a1c0 */
} /* Line 1694, Address: 0x102a1e0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1696, Address: 0x102a1f0 */
  wH_posiw = 0; /* Line 1697, Address: 0x102a210 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1698, Address: 0x102a214 */
} /* Line 1699, Address: 0x102a234 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1706, Address: 0x102a250 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1712, Address: 0x102a280 */
  yOffs += wV_posiw; /* Line 1713, Address: 0x102a290 */





  if ((short)xOffs < 0) /* Line 1719, Address: 0x102a2a0 */
    xOffs = 0; /* Line 1720, Address: 0x102a2bc */
  if ((short)yOffs < 0) /* Line 1721, Address: 0x102a2c0 */
    yOffs = 0; /* Line 1722, Address: 0x102a2dc */
  if ((short)xOffs >= 16384) /* Line 1723, Address: 0x102a2e0 */
    xOffs = 16383; /* Line 1724, Address: 0x102a300 */
  if ((short)yOffs >= 2048) /* Line 1725, Address: 0x102a308 */
    yOffs = 2047; /* Line 1726, Address: 0x102a328 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1727, Address: 0x102a330 */
  if (i < 0) i = 0; /* Line 1728, Address: 0x102a378 */

  ScreenNo = pMapWk[i] & 127; /* Line 1730, Address: 0x102a384 */

  if (ScreenNo) { /* Line 1732, Address: 0x102a3a0 */




    xOffs &= 32767; /* Line 1737, Address: 0x102a3a8 */
    yOffs &= 32767; /* Line 1738, Address: 0x102a3b4 */


    xBlk = xOffs; /* Line 1741, Address: 0x102a3c0 */
    xBlk %= 256; /* Line 1742, Address: 0x102a3c8 */
    xBlk /= 16; /* Line 1743, Address: 0x102a3e8 */
    yBlk = yOffs; /* Line 1744, Address: 0x102a404 */
    yBlk %= 256; /* Line 1745, Address: 0x102a40c */
    yBlk /= 16; /* Line 1746, Address: 0x102a42c */

    lpw = pmapwk; /* Line 1748, Address: 0x102a448 */
    lpw += xBlk; /* Line 1749, Address: 0x102a450 */
    lpw += yBlk * 16; /* Line 1750, Address: 0x102a458 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1751, Address: 0x102a464 */
    *pIndex = *lpw; /* Line 1752, Address: 0x102a47c */

    return 1; /* Line 1754, Address: 0x102a48c */
  }

  *pIndex = 0; /* Line 1757, Address: 0x102a498 */
  return 0; /* Line 1758, Address: 0x102a4a0 */
} /* Line 1759, Address: 0x102a4a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1779, Address: 0x102a4d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1787, Address: 0x102a4f8 */
  if (ScreenNo) { /* Line 1788, Address: 0x102a55c */





    xBlk = xOffs; /* Line 1794, Address: 0x102a564 */
    xBlk %= 256; /* Line 1795, Address: 0x102a56c */
    xBlk /= 16; /* Line 1796, Address: 0x102a58c */
    yBlk = yOffs; /* Line 1797, Address: 0x102a5a8 */
    yBlk %= 256; /* Line 1798, Address: 0x102a5b0 */
    yBlk /= 16; /* Line 1799, Address: 0x102a5d0 */


    lpw = pmapwk; /* Line 1802, Address: 0x102a5ec */
    lpw += xBlk; /* Line 1803, Address: 0x102a5f4 */
    lpw += yBlk * 16; /* Line 1804, Address: 0x102a5fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1805, Address: 0x102a608 */
    *ppBlockNo = lpw; /* Line 1806, Address: 0x102a620 */
    *pIndex = *lpw; /* Line 1807, Address: 0x102a628 */




    return 1; /* Line 1812, Address: 0x102a638 */
  }

  *pIndex = 0; /* Line 1815, Address: 0x102a644 */
  return 0; /* Line 1816, Address: 0x102a64c */
} /* Line 1817, Address: 0x102a650 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1831, Address: 0x102a670 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1838, Address: 0x102a68c */
  pMapWk = (unsigned char*)mapwka; /* Line 1839, Address: 0x102a690 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1840, Address: 0x102a698 */
    *pBlockIndex = BlockNo; /* Line 1841, Address: 0x102a6bc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1842, Address: 0x102a6c8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1843, Address: 0x102a6e0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1844, Address: 0x102a6f4 */
    }
  }


} /* Line 1849, Address: 0x102a70c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1863, Address: 0x102a730 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1864, Address: 0x102a73c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1865, Address: 0x102a768 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1866, Address: 0x102a7b4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1867, Address: 0x102a7e0 */

          return 0; /* Line 1869, Address: 0x102a82c */
        }
      }
    }
  }

  return 1; /* Line 1875, Address: 0x102a838 */
} /* Line 1876, Address: 0x102a83c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1893, Address: 0x102a850 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1894, Address: 0x102a86c */

} /* Line 1896, Address: 0x102a888 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1898, Address: 0x102a8a0 */
  wH_posiw = 0; /* Line 1899, Address: 0x102a8bc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1900, Address: 0x102a8c0 */

} /* Line 1902, Address: 0x102a8dc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1904, Address: 0x102a8f0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1905, Address: 0x102a904 */

} /* Line 1907, Address: 0x102a920 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1909, Address: 0x102a930 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1910, Address: 0x102a94c */

} /* Line 1912, Address: 0x102a968 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1914, Address: 0x102a980 */
  xOffs += wH_posiw; /* Line 1915, Address: 0x102a998 */
  yOffs += wV_posiw; /* Line 1916, Address: 0x102a9a8 */
  yOffs &= 240; /* Line 1917, Address: 0x102a9b8 */
  xOffs &= 496; /* Line 1918, Address: 0x102a9c4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1920, Address: 0x102a9d0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1921, Address: 0x102a9fc */


} /* Line 1924, Address: 0x102aa28 */















void mapwrt(void) { /* Line 1940, Address: 0x102aa40 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1945, Address: 0x102aa58 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1946, Address: 0x102aa64 */
  pMapWk = (unsigned char*)mapwka; /* Line 1947, Address: 0x102aa70 */
  VramBase = 16384; /* Line 1948, Address: 0x102aa78 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1949, Address: 0x102aa7c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1953, Address: 0x102aa94 */
  VramBase = 24576; /* Line 1954, Address: 0x102aa9c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1955, Address: 0x102aaa0 */

} /* Line 1957, Address: 0x102aab0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1960, Address: 0x102aad0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1961, Address: 0x102aae8 */
} /* Line 1962, Address: 0x102ab08 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1967, Address: 0x102ab20 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1971, Address: 0x102ab40 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1974, Address: 0x102ab5c */



    wD4 += 16; /* Line 1978, Address: 0x102ab84 */
  } while ((short)--wD6 >= 0); /* Line 1979, Address: 0x102ab90 */

} /* Line 1981, Address: 0x102abb8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1986, Address: 0x102abd0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1989, Address: 0x102abec */
  wD6 = 15; /* Line 1990, Address: 0x102abf4 */



  do {
    wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1995, Address: 0x102abfc */

    mapwrt_sub(&z32bwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1997, Address: 0x102ac20 */
    wD4 += 16; /* Line 1998, Address: 0x102ac40 */
  } while ((short)--wD6 >= 0); /* Line 1999, Address: 0x102ac48 */
} /* Line 2000, Address: 0x102ac6c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2026, Address: 0x102ac90 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2031, Address: 0x102acb8 */
  wD0 = pWrttbl[wD0]; /* Line 2032, Address: 0x102acc8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2034, Address: 0x102ace4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2035, Address: 0x102ad08 */
  if (wD0) { /* Line 2036, Address: 0x102ad30 */
    wD5 = 65520; /* Line 2037, Address: 0x102ad3c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2038, Address: 0x102ad44 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2041, Address: 0x102ad60 */



  } /* Line 2045, Address: 0x102ad88 */
  else {

    wD5 = 0; /* Line 2048, Address: 0x102ad90 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2049, Address: 0x102ad94 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2053, Address: 0x102adb0 */
  }





} /* Line 2060, Address: 0x102add8 */




void mapinit(void) { /* Line 2065, Address: 0x102ae00 */





  mapset(); /* Line 2071, Address: 0x102ae08 */


  colorset2(mapinittbl.colorno2); /* Line 2074, Address: 0x102ae10 */
  colorset(mapinittbl.colorno2); /* Line 2075, Address: 0x102ae24 */






  if (plflag != 0) { /* Line 2082, Address: 0x102ae38 */
    enecginit(); /* Line 2083, Address: 0x102ae4c */
  }

  if (play_start & 2) { /* Line 2086, Address: 0x102ae54 */

    divdevset(); /* Line 2088, Address: 0x102ae6c */
  }


} /* Line 2092, Address: 0x102ae74 */









void mapset(void) {} /* Line 2102, Address: 0x102ae90 */
