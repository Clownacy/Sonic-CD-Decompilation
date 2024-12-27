#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3D.H"

static unsigned char z31dwrttbl[49] = {
  0, 0, 0, 6, 6, 6, 6, 6, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  2, 2, 6, 6, 4, 4, 4, 4, 4, 4,
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
extern map_init_data mapinittbl;









































































void enecginit() {} /* Line 112, Address: 0x1026ce0 */



void divdevset() {} /* Line 116, Address: 0x1026cf0 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 170, Address: 0x1026d00 */
    return &actwk[0]; /* Line 171, Address: 0x1026d14 */
  }
  return &actwk[1]; /* Line 173, Address: 0x1026d24 */
} /* Line 174, Address: 0x1026d2c */












void scr_set() { /* Line 187, Address: 0x1026d40 */





  unsigned short scr_dir_tbl[6] = { /* Line 193, Address: 0x1026d4c */
    4, 0, 11927, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1026d80 */

  i = 0; /* Line 200, Address: 0x1026dc8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 201, Address: 0x1026dcc */
  scralim_left = scr_dir_tbl[i]; /* Line 202, Address: 0x1026de8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 203, Address: 0x1026dfc */
  scralim_right = scr_dir_tbl[i]; /* Line 204, Address: 0x1026e18 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 205, Address: 0x1026e2c */
  scralim_up = scr_dir_tbl[i]; /* Line 206, Address: 0x1026e48 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 207, Address: 0x1026e5c */
  scralim_down = scr_dir_tbl[i]; /* Line 208, Address: 0x1026e78 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 209, Address: 0x1026e8c */

  scra_h_keep = scralim_left + 576; /* Line 211, Address: 0x1026ea8 */
  scra_h_count = 16; /* Line 212, Address: 0x1026ecc */
  scra_v_count = 16; /* Line 213, Address: 0x1026ed8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 215, Address: 0x1026ee4 */
  scra_hline = 160; /* Line 216, Address: 0x1026f00 */

  playposiset(); /* Line 218, Address: 0x1026f0c */
} /* Line 219, Address: 0x1026f14 */











void playposiset() { /* Line 231, Address: 0x1026f30 */
  unsigned short playpositbl[2] = { /* Line 232, Address: 0x1026f48 */
    96,
    1004
  };
  unsigned short endplpositbl[16] = { /* Line 236, Address: 0x1026f64 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 246, Address: 0x1026f98 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 256, Address: 0x1026fc4 */
    playload(); /* Line 257, Address: 0x1026fd8 */
    xWk = actwk[0].xposi.w.h; /* Line 258, Address: 0x1026fe0 */
    yWk = actwk[0].yposi.w.h; /* Line 259, Address: 0x1026ff0 */

    if (yWk < 0) yWk = 0; /* Line 261, Address: 0x1027000 */

  } /* Line 263, Address: 0x1027014 */
  else {

    if (demoflag.w < 0) { /* Line 266, Address: 0x102701c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 267, Address: 0x1027034 */
    } /* Line 268, Address: 0x102705c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 271, Address: 0x1027064 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 274, Address: 0x1027084 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 275, Address: 0x10270a0 */
  }


  if ((unsigned short)xWk > 160) { /* Line 279, Address: 0x10270b4 */
    xWk -= 160; /* Line 280, Address: 0x10270c8 */
  } /* Line 281, Address: 0x10270d4 */
  else {
    xWk = 0; /* Line 283, Address: 0x10270dc */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 287, Address: 0x10270e0 */
    xWk = scralim_right; /* Line 288, Address: 0x1027104 */
  }
  scra_h_posit.w.h = xWk; /* Line 290, Address: 0x1027114 */

  if ((unsigned short)yWk > 96) { /* Line 292, Address: 0x102711c */
    yWk -= 96; /* Line 293, Address: 0x1027130 */
  } /* Line 294, Address: 0x102713c */
  else {
    yWk = 0; /* Line 296, Address: 0x1027144 */
  }

  if (scralim_down < yWk) { /* Line 299, Address: 0x1027148 */
    yWk = scralim_down; /* Line 300, Address: 0x102716c */
  }

  scra_v_posit.w.h = yWk; /* Line 303, Address: 0x102717c */

  scrbinit(xWk, yWk); /* Line 305, Address: 0x1027184 */

  i = 0; /* Line 307, Address: 0x1027194 */
  loopmapno = playmapnotbl[i++]; /* Line 308, Address: 0x1027198 */
  loopmapno2 = playmapnotbl[i++]; /* Line 309, Address: 0x10271b0 */
  ballmapno = playmapnotbl[i++]; /* Line 310, Address: 0x10271c8 */
  ballmapno2 = playmapnotbl[i++]; /* Line 311, Address: 0x10271e0 */


} /* Line 314, Address: 0x10271f8 */











void scrbinit(short xWk, short yWk) { /* Line 326, Address: 0x1027220 */
  int i;
  short wD2;


  yWk = 536; /* Line 331, Address: 0x1027234 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 332, Address: 0x102723c */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 333, Address: 0x1027264 */
    yWk -= wD2 / 2; /* Line 334, Address: 0x1027280 */
    if (yWk < 0) { /* Line 335, Address: 0x10272b4 */
      yWk = 0; /* Line 336, Address: 0x10272c8 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 340, Address: 0x10272cc */
  scrb_v_posit.w.l = 0; /* Line 341, Address: 0x10272d8 */
  scrc_v_posit.w.h = yWk; /* Line 342, Address: 0x10272e0 */
  scrz_v_posit.w.h = yWk; /* Line 343, Address: 0x10272ec */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 345, Address: 0x10272f8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 346, Address: 0x1027330 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 347, Address: 0x1027370 */


  for (i = 0; i < 15; ++i) { /* Line 350, Address: 0x10273b0 */
    ((int*)hscrollwork)[i] = 0; /* Line 351, Address: 0x10273bc */
  } /* Line 352, Address: 0x10273d0 */

} /* Line 354, Address: 0x10273e0 */












void scroll() { /* Line 367, Address: 0x1027400 */
  int LineSpdTbl[15] = { /* Line 368, Address: 0x1027420 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  2048,  4096,
     8192, 12288, 16384,
    24576, 32768, 49152
  };
  unsigned char z31d_cnttbl[15] = { /* Line 375, Address: 0x1027450 */
    1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 3, 3, 1
  };
  unsigned char z31d_cnttbl1[3] = { /* Line 378, Address: 0x102747c */
    6, 1, 0
  };
  unsigned short z31d_kawatbl[3] = { /* Line 381, Address: 0x10274a0 */
    8, 32767, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 391, Address: 0x10274c4 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 394, Address: 0x10274d4 */
  scrchk(); /* Line 395, Address: 0x1027500 */
  scroll_h(); /* Line 396, Address: 0x102750c */
  scroll_v(); /* Line 397, Address: 0x1027518 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 399, Address: 0x1027524 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 400, Address: 0x1027534 */


  scrollz_h(scra_hz << 4, 64); /* Line 403, Address: 0x1027544 */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 404, Address: 0x1027568 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 405, Address: 0x10275a0 */

  lD0.w.l = 536; /* Line 407, Address: 0x10275d8 */
  wD1 = 1312; /* Line 408, Address: 0x10275e0 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 409, Address: 0x10275ec */

    wD1 -= scra_v_posit.w.h; /* Line 411, Address: 0x102760c */
    wD1 >>= 1; /* Line 412, Address: 0x1027620 */
    lD0.w.l -= wD1; /* Line 413, Address: 0x1027628 */
    if (lD0.w.l < 0) { /* Line 414, Address: 0x102763c */
      lD0.w.l = 0; /* Line 415, Address: 0x1027650 */
    }
  } /* Line 417, Address: 0x1027654 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 419, Address: 0x102765c */
  }

  scrollb_v(lD0.w.l); /* Line 422, Address: 0x1027674 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 423, Address: 0x1027688 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 424, Address: 0x1027698 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 425, Address: 0x10276a8 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 427, Address: 0x10276b8 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 428, Address: 0x10276d4 */
  scrflagz.b.h = 0; /* Line 429, Address: 0x10276f0 */
  scrflagc.b.h = 0; /* Line 430, Address: 0x10276f8 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 453, Address: 0x1027700 */
  for (i = 0; i < 15; ++i) { /* Line 454, Address: 0x1027708 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 455, Address: 0x1027714 */
    ++pHscrWk; /* Line 456, Address: 0x102772c */
  } /* Line 457, Address: 0x1027730 */
  wD1 = 0; /* Line 458, Address: 0x1027740 */
  for ( ; i < 79; ++i) { /* Line 459, Address: 0x1027744 */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 460, Address: 0x102774c */
    pHscrWk->l += lD2.l; /* Line 461, Address: 0x1027770 */
    ++pHscrWk; /* Line 462, Address: 0x1027780 */
    ++wD1; /* Line 463, Address: 0x1027784 */
  } /* Line 464, Address: 0x1027790 */






  pHScrollWork = &hscrollwork[158]; /* Line 471, Address: 0x10277a0 */
  lD0.w.h = -scra_h_posit.w.h; /* Line 472, Address: 0x10277ac */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 473, Address: 0x10277cc */
  *pHScrollWork++ = lD0.w.l; /* Line 474, Address: 0x10277f0 */


  for (i = 0; i < 3; ++i) { /* Line 477, Address: 0x1027804 */
    *pHScrollWork++ = lD0.w.l; /* Line 478, Address: 0x1027810 */
  } /* Line 479, Address: 0x1027824 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 481, Address: 0x1027834 */

  for (i = 0; i < 10; ++i) { /* Line 483, Address: 0x1027858 */
    *pHScrollWork++ = lD0.w.l; /* Line 484, Address: 0x1027864 */
  } /* Line 485, Address: 0x1027878 */














  pHscrWk = (int_union*)hscrollwork; /* Line 500, Address: 0x1027888 */
  for (i = 14; i >= 0; --i) { /* Line 501, Address: 0x1027890 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 502, Address: 0x102789c */
    ++pHscrWk; /* Line 503, Address: 0x10278c8 */
    for (j = z31d_cnttbl[i]; j >= 0; --j) { /* Line 504, Address: 0x10278cc */
      *pHScrollWork++ = wD1; /* Line 505, Address: 0x10278e0 */
    } /* Line 506, Address: 0x10278f0 */
  } /* Line 507, Address: 0x10278fc */



  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 511, Address: 0x1027908 */

  for (i = 0; i < 6; ++i) { /* Line 513, Address: 0x102792c */
    *pHScrollWork++ = lD0.w.l; /* Line 514, Address: 0x1027938 */
  } /* Line 515, Address: 0x102794c */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 517, Address: 0x102795c */

  for (i = 0; i < 4; ++i) { /* Line 519, Address: 0x1027980 */
    *pHScrollWork++ = lD0.w.l; /* Line 520, Address: 0x102798c */
  } /* Line 521, Address: 0x10279a0 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 523, Address: 0x10279b0 */

  for (i = 0; i < 12; ++i) { /* Line 525, Address: 0x10279d4 */
    *pHScrollWork++ = lD0.w.l; /* Line 526, Address: 0x10279e0 */
  } /* Line 527, Address: 0x10279f4 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 530, Address: 0x1027a04 */
  lD2.l <<= 6; /* Line 531, Address: 0x1027a3c */
  lD2.l /= 24; /* Line 532, Address: 0x1027a48 */
  lD2.l <<= 10; /* Line 533, Address: 0x1027a68 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 534, Address: 0x1027a74 */

  for (i = 2; i >= 0; --i) { /* Line 536, Address: 0x1027a80 */
    lD0.w.l = -lD3.w.l; /* Line 537, Address: 0x1027a8c */
    for (j = z31d_cnttbl1[i]; j >= 0; --j) { /* Line 538, Address: 0x1027aa8 */
      *pHScrollWork++ = lD0.w.l; /* Line 539, Address: 0x1027abc */
    } /* Line 540, Address: 0x1027ad0 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 541, Address: 0x1027adc */
    lD3.l += lD2.l; /* Line 542, Address: 0x1027b00 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 543, Address: 0x1027b10 */
  } /* Line 544, Address: 0x1027b34 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 546, Address: 0x1027b40 */

  for (i = 0; i < 8; ++i) { /* Line 548, Address: 0x1027b64 */
    *pHScrollWork++ = lD0.w.l; /* Line 549, Address: 0x1027b70 */
  } /* Line 550, Address: 0x1027b84 */

  pHScrollBuff = lphscrollbuff; /* Line 552, Address: 0x1027b94 */
  pHScrollWork = &hscrollwork[158]; /* Line 553, Address: 0x1027ba0 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 554, Address: 0x1027bac */
  lD2.w.l = lD0.w.l; /* Line 555, Address: 0x1027bb8 */
  wD4 = lD0.w.l; /* Line 556, Address: 0x1027bc0 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 557, Address: 0x1027bc8 */
  wD3 = lD0.w.l >> 1; /* Line 558, Address: 0x1027bec */
  wD1 = 87; /* Line 559, Address: 0x1027c04 */
  wD5 = 29; /* Line 560, Address: 0x1027c10 */
  if (wD3 <= wD1) { /* Line 561, Address: 0x1027c18 */

    wD1 -= wD3; /* Line 563, Address: 0x1027c2c */
    if (wD1 >= 27) { /* Line 564, Address: 0x1027c34 */
      wD1 = 28; /* Line 565, Address: 0x1027c44 */
    }

    wD5 -= wD1; /* Line 568, Address: 0x1027c50 */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 569, Address: 0x1027c58 */
    waterdirec.w += 64; /* Line 570, Address: 0x1027c7c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z31d_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 572, Address: 0x1027c90 */


  } /* Line 575, Address: 0x1027cb8 */
  else {
    wD1 -= wD3; /* Line 577, Address: 0x1027cc0 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 582, Address: 0x1027cc8 */
  pHScrollWork = &hscrollwork[30]; /* Line 583, Address: 0x1027cdc */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 584, Address: 0x1027ce8 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 585, Address: 0x1027cfc */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 588, Address: 0x1027d14 */
    lD2.w.l = *pHScrollWork++; /* Line 589, Address: 0x1027d28 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 590, Address: 0x1027d3c */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 591, Address: 0x1027d50 */
    lD0.w.l = lD2.w.l; /* Line 592, Address: 0x1027d70 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 593, Address: 0x1027d78 */
    if (wD3 <= wD4) { /* Line 594, Address: 0x1027d98 */
      wD5 &= 255; /* Line 595, Address: 0x1027db0 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 596, Address: 0x1027db8 */
      wD3 += scra_h_posit.w.h; /* Line 597, Address: 0x1027de4 */
      wD3 = -(short)wD3; /* Line 598, Address: 0x1027df8 */
      lD0.w.h = wD3; /* Line 599, Address: 0x1027e14 */
    }

    pHScrollBuff->l = lD0.l; /* Line 602, Address: 0x1027e18 */
    ++pHScrollBuff; /* Line 603, Address: 0x1027e24 */
    ++wD4; /* Line 604, Address: 0x1027e30 */
    ++wD5; /* Line 605, Address: 0x1027e3c */
  } while ((short)--wD1 >= 0); /* Line 606, Address: 0x1027e44 */

} /* Line 608, Address: 0x1027e68 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 613, Address: 0x1027e90 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 620, Address: 0x1027ec4 */
  pA1 = *ppA1; /* Line 621, Address: 0x1027ee4 */
  pA2 = *ppA2; /* Line 622, Address: 0x1027eec */

  if (*pA3 <= *pwD4) goto label6; /* Line 624, Address: 0x1027ef4 */



label1:
  *pwD2 &= 7; /* Line 629, Address: 0x1027f18 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 630, Address: 0x1027f2c */

  lD0.w.l = *pA2++; /* Line 632, Address: 0x1027f58 */
  i = 8 - *pwD2; /* Line 633, Address: 0x1027f68 */
  goto label4; /* Line 634, Address: 0x1027f7c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 637, Address: 0x1027f84 */


  if (*pA3 <= *pwD4) goto label7; /* Line 640, Address: 0x1027fa0 */



label3:
  lD0.w.l = *pA2++; /* Line 645, Address: 0x1027fc4 */
  *pwD4 += 8; /* Line 646, Address: 0x1027fd4 */


  i = 8; /* Line 649, Address: 0x1027fe8 */
label4:
  for ( ; i > 0; --i) { /* Line 651, Address: 0x1027fec */


    pA1->l = lD0.l; /* Line 654, Address: 0x1027ff4 */
    ++pA1; /* Line 655, Address: 0x1027ffc */
  } /* Line 656, Address: 0x1028000 */
  if ((short)--wD1 >= 0) goto label2; /* Line 657, Address: 0x1028010 */



label5:
  *ppA1 = pA1; /* Line 662, Address: 0x1028038 */
  *ppA2 = pA2; /* Line 663, Address: 0x1028040 */
  return; /* Line 664, Address: 0x1028048 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 668, Address: 0x1028050 */
  if ((short)wD3 > 0) goto label8; /* Line 669, Address: 0x1028080 */


  if (*pA3 > *pwD4) goto label1; /* Line 672, Address: 0x1028098 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 675, Address: 0x10280bc */
  if ((short)wD3 > 0) goto label8; /* Line 676, Address: 0x10280ec */
  goto label1; /* Line 677, Address: 0x1028104 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 685, Address: 0x102810c */
  if ((short)wD3 <= 0) goto label3; /* Line 686, Address: 0x102813c */



label8:
  --wD3; /* Line 691, Address: 0x1028154 */
  wD6 = wD3; /* Line 692, Address: 0x102815c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 693, Address: 0x1028160 */

  do {
    *pwD2 &= 255; /* Line 696, Address: 0x1028178 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 697, Address: 0x102818c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 698, Address: 0x10281b8 */
    lD0.w.l = -lD0.w.l; /* Line 699, Address: 0x10281cc */
    pA1->w.h = lD0.w.h; /* Line 700, Address: 0x10281e8 */
    pA1->w.l = lD0.w.l; /* Line 701, Address: 0x10281f0 */
    ++pA1; /* Line 702, Address: 0x10281f8 */
    ++*pwD4; /* Line 703, Address: 0x10281fc */
    ++*pwD2; /* Line 704, Address: 0x1028210 */
  } while ((short)--wD3 >= 0); /* Line 705, Address: 0x1028224 */

  wD6 >>= 3; /* Line 707, Address: 0x1028248 */

  do {
    lD0.w.l = *pA2++; /* Line 710, Address: 0x1028250 */
    --wD1; /* Line 711, Address: 0x1028260 */
  } while ((short)--wD6 >= 0); /* Line 712, Address: 0x102826c */
  goto label2; /* Line 713, Address: 0x1028290 */
} /* Line 714, Address: 0x1028298 */















void scroll_h() { /* Line 730, Address: 0x10282c0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 733, Address: 0x10282cc */
  scrh_move(); /* Line 734, Address: 0x10282d8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 735, Address: 0x10282e0 */
    scra_h_count ^= 16; /* Line 736, Address: 0x1028314 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 737, Address: 0x1028328 */
      scrflaga.b.h |= 4; /* Line 738, Address: 0x1028354 */
    } /* Line 739, Address: 0x1028368 */
    else {

      scrflaga.b.h |= 8; /* Line 742, Address: 0x1028370 */
    }
  }


} /* Line 747, Address: 0x1028384 */

void scrh_move() { /* Line 749, Address: 0x10283a0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 752, Address: 0x10283ac */
  wD0 -= scra_h_posit.w.h; /* Line 753, Address: 0x10283b8 */
  wD0 -= scra_hline; /* Line 754, Address: 0x10283cc */
  if (wD0 == 0) { /* Line 755, Address: 0x10283e0 */

    scra_hz = 0; /* Line 757, Address: 0x10283ec */
  } /* Line 758, Address: 0x10283f4 */
  else if ((short)wD0 < 0) { /* Line 759, Address: 0x10283fc */
    left_check(wD0); /* Line 760, Address: 0x1028414 */
  } /* Line 761, Address: 0x1028420 */
  else {
    right_check(wD0); /* Line 763, Address: 0x1028428 */
  }

} /* Line 766, Address: 0x1028434 */


void right_check(unsigned short wD0) { /* Line 769, Address: 0x1028450 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 772, Address: 0x102845c */
    wD0 = 16; /* Line 773, Address: 0x102847c */
  }

  wD0 += scra_h_posit.w.h; /* Line 776, Address: 0x1028484 */
  if (scralim_right < (short)wD0) { /* Line 777, Address: 0x102849c */
    wD0 = scralim_right; /* Line 778, Address: 0x10284cc */
  }

  wD1 = wD0; /* Line 781, Address: 0x10284d8 */
  wD1 -= scra_h_posit.w.h; /* Line 782, Address: 0x10284e0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 783, Address: 0x10284f4 */
  scra_h_posit.w.h = wD0; /* Line 784, Address: 0x1028524 */
  scra_hz = wD1; /* Line 785, Address: 0x1028530 */

} /* Line 787, Address: 0x1028538 */


void left_check(unsigned short wD0) { /* Line 790, Address: 0x1028550 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 793, Address: 0x102855c */
    wD0 = -16; /* Line 794, Address: 0x102857c */
  }

  wD0 += scra_h_posit.w.h; /* Line 797, Address: 0x1028584 */
  if (scralim_left > (short)wD0) { /* Line 798, Address: 0x102859c */
    wD0 = scralim_left; /* Line 799, Address: 0x10285cc */
  }

  wD1 = wD0; /* Line 802, Address: 0x10285d8 */
  wD1 -= scra_h_posit.w.h; /* Line 803, Address: 0x10285e0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 804, Address: 0x10285f4 */
  scra_h_posit.w.h = wD0; /* Line 805, Address: 0x1028624 */
  scra_hz = wD1; /* Line 806, Address: 0x1028630 */

} /* Line 808, Address: 0x1028638 */


















void scroll_v() { /* Line 827, Address: 0x1028650 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 830, Address: 0x102865c */
  if (actwk[0].cddat & 4) { /* Line 831, Address: 0x1028688 */
    wD0 -= 5; /* Line 832, Address: 0x10286a0 */
  }

  if (actwk[0].cddat & 2) { /* Line 835, Address: 0x10286a8 */
    wD0 += 32; /* Line 836, Address: 0x10286c0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 837, Address: 0x10286c8 */
      wD0 -= scra_vline; /* Line 838, Address: 0x10286e8 */
      sv_move_main2(wD0); /* Line 839, Address: 0x10286fc */
      return; /* Line 840, Address: 0x1028708 */
    }
    wD0 -= scra_vline; /* Line 842, Address: 0x1028710 */
    if (wD0 >= 64) { /* Line 843, Address: 0x1028724 */
      wD0 -= 64; /* Line 844, Address: 0x1028734 */
      sv_move_main2(wD0); /* Line 845, Address: 0x102873c */
      return; /* Line 846, Address: 0x1028748 */
    }
    wD0 -= 64; /* Line 848, Address: 0x1028750 */
    if (limmoveflag == 0) goto label1; /* Line 849, Address: 0x1028758 */
    sv_move_sub2(); /* Line 850, Address: 0x102876c */
    return; /* Line 851, Address: 0x1028774 */
  }




  wD0 -= scra_vline; /* Line 857, Address: 0x102877c */
  if (wD0) { /* Line 858, Address: 0x1028790 */
    sv_move_main(wD0); /* Line 859, Address: 0x1028798 */
    return; /* Line 860, Address: 0x10287a4 */
  }
  if (limmoveflag == 0) { /* Line 862, Address: 0x10287ac */
    sv_move_sub2(); /* Line 863, Address: 0x10287c0 */
    return; /* Line 864, Address: 0x10287c8 */
  }


label1:
  scra_vz = 0; /* Line 869, Address: 0x10287d0 */

} /* Line 871, Address: 0x10287d8 */





void sv_move_main(unsigned short wD0) { /* Line 877, Address: 0x10287f0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 880, Address: 0x1028800 */
    sv_move_main1(wD0); /* Line 881, Address: 0x102881c */
  } /* Line 882, Address: 0x1028828 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 885, Address: 0x1028830 */
    if ((short)wD1 < 0) { /* Line 886, Address: 0x102883c */
      wD1 = -(short)wD1; /* Line 887, Address: 0x1028854 */
    }

    if (wD1 >= 2048) { /* Line 890, Address: 0x1028870 */
      sv_move_main2(wD0); /* Line 891, Address: 0x1028880 */
    } /* Line 892, Address: 0x102888c */
    else {
      if ((short)wD0 > 6) { /* Line 894, Address: 0x1028894 */
        sv_move_plus(1536); /* Line 895, Address: 0x10288b4 */
      } /* Line 896, Address: 0x10288c0 */
      else if ((short)wD0 < -6) { /* Line 897, Address: 0x10288c8 */
        sv_move_minus(1536); /* Line 898, Address: 0x10288e8 */
      } /* Line 899, Address: 0x10288f4 */
      else {
        sv_move_sub(wD0); /* Line 901, Address: 0x10288fc */
      }
    }
  }
} /* Line 905, Address: 0x1028908 */



void sv_move_main1(unsigned short wD0) { /* Line 909, Address: 0x1028920 */

  if ((short)wD0 > 2) { /* Line 911, Address: 0x102892c */
    sv_move_plus(512); /* Line 912, Address: 0x102894c */
  } /* Line 913, Address: 0x1028958 */
  else if ((short)wD0 < -2) { /* Line 914, Address: 0x1028960 */
    sv_move_minus(512); /* Line 915, Address: 0x1028980 */
  } /* Line 916, Address: 0x102898c */
  else {
    sv_move_sub(wD0); /* Line 918, Address: 0x1028994 */
  }

} /* Line 921, Address: 0x10289a0 */


void sv_move_main2(unsigned short wD0) { /* Line 924, Address: 0x10289b0 */

  if ((short)wD0 > 16) { /* Line 926, Address: 0x10289bc */
    sv_move_plus(4096); /* Line 927, Address: 0x10289dc */
  } /* Line 928, Address: 0x10289e8 */
  else if ((short)wD0 < -16) { /* Line 929, Address: 0x10289f0 */
    sv_move_minus(4096); /* Line 930, Address: 0x1028a10 */
  } /* Line 931, Address: 0x1028a1c */
  else {
    sv_move_sub(wD0); /* Line 933, Address: 0x1028a24 */
  }

} /* Line 936, Address: 0x1028a30 */


void sv_move_sub2() { /* Line 939, Address: 0x1028a40 */
  limmoveflag = 0; /* Line 940, Address: 0x1028a48 */
  sv_move_sub(0); /* Line 941, Address: 0x1028a50 */
} /* Line 942, Address: 0x1028a5c */


void sv_move_sub(unsigned short wD0) { /* Line 945, Address: 0x1028a70 */
  int_union lD1;

  lD1.w.h = 0; /* Line 948, Address: 0x1028a7c */
  lD1.w.l = wD0; /* Line 949, Address: 0x1028a80 */
  lD1.l += scra_v_posit.w.h; /* Line 950, Address: 0x1028a88 */
  if ((short)wD0 > 0) { /* Line 951, Address: 0x1028aa4 */
    scrv_down_ch(lD1); /* Line 952, Address: 0x1028ac0 */
  } /* Line 953, Address: 0x1028acc */
  else {
    scrv_up_ch(lD1); /* Line 955, Address: 0x1028ad4 */
  }

} /* Line 958, Address: 0x1028ae0 */




void sv_move_minus(unsigned short wD1) { /* Line 963, Address: 0x1028af0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 967, Address: 0x1028b00 */
  lD1.l <<= 8; /* Line 968, Address: 0x1028b1c */
  lD1.l += scra_v_posit.l; /* Line 969, Address: 0x1028b28 */

  wk = lD1.w.h; /* Line 971, Address: 0x1028b3c */
  lD1.w.h = lD1.w.l; /* Line 972, Address: 0x1028b44 */
  lD1.w.l = wk; /* Line 973, Address: 0x1028b4c */
  scrv_up_ch(lD1); /* Line 974, Address: 0x1028b50 */
} /* Line 975, Address: 0x1028b5c */



void scrv_up_ch(int_union lD1) { /* Line 979, Address: 0x1028b70 */
  if (scralim_up >= lD1.w.l) { /* Line 980, Address: 0x1028b7c */
    if (lD1.w.l < -255) { /* Line 981, Address: 0x1028ba4 */
      lD1.w.l &= 2047; /* Line 982, Address: 0x1028bbc */
      actwk[0].yposi.w.h &= 32767; /* Line 983, Address: 0x1028bc8 */
      scra_v_posit.w.h &= 2047; /* Line 984, Address: 0x1028bdc */
      scrb_v_posit.w.h &= 1023; /* Line 985, Address: 0x1028bf0 */
    } /* Line 986, Address: 0x1028c04 */
    else {

      lD1.w.l = scralim_up; /* Line 989, Address: 0x1028c0c */
    }
  }
  scrv_move(lD1); /* Line 992, Address: 0x1028c18 */

} /* Line 994, Address: 0x1028c24 */





void sv_move_plus(unsigned short wD1) { /* Line 1000, Address: 0x1028c40 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1004, Address: 0x1028c50 */
  lD1.w.l = wD1; /* Line 1005, Address: 0x1028c54 */
  lD1.l <<= 8; /* Line 1006, Address: 0x1028c5c */
  lD1.l += scra_v_posit.l; /* Line 1007, Address: 0x1028c68 */

  wk = lD1.w.h; /* Line 1009, Address: 0x1028c7c */
  lD1.w.h = lD1.w.l; /* Line 1010, Address: 0x1028c84 */
  lD1.w.l = wk; /* Line 1011, Address: 0x1028c8c */

  scrv_down_ch(lD1); /* Line 1013, Address: 0x1028c90 */

} /* Line 1015, Address: 0x1028c9c */



void scrv_down_ch(int_union lD1) { /* Line 1019, Address: 0x1028cb0 */
  if (scralim_down <= lD1.w.l) { /* Line 1020, Address: 0x1028cbc */
    lD1.w.l -= 2048; /* Line 1021, Address: 0x1028ce4 */
    if (lD1.w.l > 0) { /* Line 1022, Address: 0x1028cf0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1023, Address: 0x1028d04 */
      scra_v_posit.w.h -= 2048; /* Line 1024, Address: 0x1028d18 */
      scrb_v_posit.w.h &= 1023; /* Line 1025, Address: 0x1028d2c */
    } /* Line 1026, Address: 0x1028d40 */
    else {
      lD1.w.l = scralim_down; /* Line 1028, Address: 0x1028d48 */
    }
  }
  scrv_move(lD1); /* Line 1031, Address: 0x1028d54 */

} /* Line 1033, Address: 0x1028d60 */


void scrv_move(int_union lD1) { /* Line 1036, Address: 0x1028d70 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1039, Address: 0x1028d80 */

  wk = lD1.w.h; /* Line 1041, Address: 0x1028d8c */
  lD1.w.h = lD1.w.l; /* Line 1042, Address: 0x1028d94 */
  lD1.w.l = wk; /* Line 1043, Address: 0x1028d9c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1045, Address: 0x1028da0 */
  scra_v_posit.l = lD1.l; /* Line 1046, Address: 0x1028dc8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1049, Address: 0x1028dd4 */
    scra_v_count ^= 16; /* Line 1050, Address: 0x1028e08 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1051, Address: 0x1028e1c */

      scrflaga.b.h |= 2; /* Line 1053, Address: 0x1028e48 */
    } /* Line 1054, Address: 0x1028e5c */
    else {
      scrflaga.b.h |= 1; /* Line 1056, Address: 0x1028e64 */
    }
  }


} /* Line 1061, Address: 0x1028e78 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1065, Address: 0x1028e90 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1068, Address: 0x1028e9c */
  lD0.l += lD4.l; /* Line 1069, Address: 0x1028eac */
  scrb_h_posit.l = lD0.l; /* Line 1070, Address: 0x1028ebc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1072, Address: 0x1028ec8 */

    scrb_h_count ^= 16; /* Line 1074, Address: 0x1028efc */
    lD0.l -= lD2.l; /* Line 1075, Address: 0x1028f10 */
    if ((long int)lD0.l < 0) { /* Line 1076, Address: 0x1028f20 */
      scrflagb.b.h |= 4; /* Line 1077, Address: 0x1028f34 */
    } /* Line 1078, Address: 0x1028f48 */
    else {

      scrflagb.b.h |= 8; /* Line 1081, Address: 0x1028f50 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1086, Address: 0x1028f64 */
  lD0.l += lD5.l; /* Line 1087, Address: 0x1028f74 */
  scrb_h_posit.l = lD0.l; /* Line 1088, Address: 0x1028f84 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1090, Address: 0x1028f90 */

    scrb_v_count ^= 16; /* Line 1092, Address: 0x1028fc4 */
    lD0.l -= lD3.l; /* Line 1093, Address: 0x1028fd8 */
    if ((long int)lD0.l < 0) { /* Line 1094, Address: 0x1028fe8 */
      scrflagb.b.h |= 1; /* Line 1095, Address: 0x1028ffc */
    } /* Line 1096, Address: 0x1029010 */
    else {

      scrflagb.b.h |= 2; /* Line 1099, Address: 0x1029018 */
    }
  }


} /* Line 1104, Address: 0x102902c */






void scrollb_v(unsigned short wD0) { /* Line 1111, Address: 0x1029040 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1114, Address: 0x102904c */
  scrb_v_posit.w.h = wD0; /* Line 1115, Address: 0x1029058 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1117, Address: 0x1029064 */
    scrb_v_count ^= 16; /* Line 1118, Address: 0x1029090 */
    if ((short)wD3 > (short)wD0) { /* Line 1119, Address: 0x10290a4 */
      scrflagb.b.h |= 1; /* Line 1120, Address: 0x10290d4 */
    } /* Line 1121, Address: 0x10290e8 */
    else {

      scrflagb.b.h |= 2; /* Line 1124, Address: 0x10290f0 */
    }
  }


} /* Line 1129, Address: 0x1029104 */



void scrollb_h(int lD4, int flagb) { /* Line 1133, Address: 0x1029120 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1137, Address: 0x1029130 */
  lD0.l = lD2.l + lD4; /* Line 1138, Address: 0x102913c */
  scrb_h_posit.l = lD0.l; /* Line 1139, Address: 0x102914c */

  lD1.w.h = lD0.w.l; /* Line 1141, Address: 0x1029158 */
  lD1.w.l = lD0.w.h; /* Line 1142, Address: 0x1029160 */
  lD1.w.l &= 16; /* Line 1143, Address: 0x1029168 */

  bD3 = scrb_h_count; /* Line 1145, Address: 0x1029174 */
  lD1.b.b4 ^= bD3; /* Line 1146, Address: 0x1029180 */
  if (!lD1.b.b4) { /* Line 1147, Address: 0x1029194 */
    scrb_h_count ^= 16; /* Line 1148, Address: 0x10291a0 */
    lD0.l -= lD2.l; /* Line 1149, Address: 0x10291b4 */
    if ((long int)lD0.l < 0) { /* Line 1150, Address: 0x10291c4 */
      scrflagb.b.h |= flagb; /* Line 1151, Address: 0x10291d8 */
    } /* Line 1152, Address: 0x10291f4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1155, Address: 0x10291fc */
    }
  }


} /* Line 1160, Address: 0x102921c */



void scrollc_h(int lD4, int flagc) { /* Line 1164, Address: 0x1029230 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1168, Address: 0x1029240 */
  lD0.l = lD2.l + lD4; /* Line 1169, Address: 0x102924c */
  scrc_h_posit.l = lD0.l; /* Line 1170, Address: 0x102925c */

  lD1.w.h = lD0.w.l; /* Line 1172, Address: 0x1029268 */
  lD1.w.l = lD0.w.h; /* Line 1173, Address: 0x1029270 */
  lD1.w.l &= 16; /* Line 1174, Address: 0x1029278 */

  bD3 = scrc_h_count; /* Line 1176, Address: 0x1029284 */
  lD1.b.b4 ^= bD3; /* Line 1177, Address: 0x1029290 */
  if (!lD1.b.b4) { /* Line 1178, Address: 0x10292a4 */
    scrc_h_count ^= 16; /* Line 1179, Address: 0x10292b0 */
    lD0.l -= lD2.l; /* Line 1180, Address: 0x10292c4 */
    if ((long int)lD0.l < 0) { /* Line 1181, Address: 0x10292d4 */
      scrflagc.b.h |= flagc; /* Line 1182, Address: 0x10292e8 */
    } /* Line 1183, Address: 0x1029304 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1186, Address: 0x102930c */
    }
  }


} /* Line 1191, Address: 0x102932c */











void scrollz_h(int lD4, int flagz) { /* Line 1203, Address: 0x1029340 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1207, Address: 0x1029350 */
  lD0.l = lD2.l + lD4; /* Line 1208, Address: 0x102935c */
  scrz_h_posit.l = lD0.l; /* Line 1209, Address: 0x102936c */

  lD1.w.h = lD0.w.l; /* Line 1211, Address: 0x1029378 */
  lD1.w.l = lD0.w.h; /* Line 1212, Address: 0x1029380 */
  lD1.w.l &= 16; /* Line 1213, Address: 0x1029388 */

  bD3 = scrz_h_count; /* Line 1215, Address: 0x1029394 */
  lD1.b.b4 ^= bD3; /* Line 1216, Address: 0x10293a0 */
  if (!lD1.b.b4) { /* Line 1217, Address: 0x10293b4 */
    scrz_h_count ^= 16; /* Line 1218, Address: 0x10293c0 */
    lD0.l -= lD2.l; /* Line 1219, Address: 0x10293d4 */
    if ((long int)lD0.l < 0) { /* Line 1220, Address: 0x10293e4 */
      scrflagz.b.h |= flagz; /* Line 1221, Address: 0x10293f8 */
    } /* Line 1222, Address: 0x1029414 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1225, Address: 0x102941c */
    }
  }


} /* Line 1230, Address: 0x102943c */














void scrollwrtadva() { /* Line 1245, Address: 0x1029450 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1251, Address: 0x102946c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1252, Address: 0x1029470 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1253, Address: 0x102947c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1254, Address: 0x1029488 */
  pScrFlag = &scrflagb.b.h; /* Line 1255, Address: 0x1029490 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1256, Address: 0x1029498 */







} /* Line 1264, Address: 0x10294ac */












void scrollwrt() { /* Line 1277, Address: 0x10294d0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1286, Address: 0x10294f0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1287, Address: 0x10294f4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1288, Address: 0x1029500 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1289, Address: 0x102950c */
  pScrFlag = &scrflagbw.b.h; /* Line 1290, Address: 0x1029514 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1291, Address: 0x102951c */

  VramBase = 16384; /* Line 1293, Address: 0x1029530 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1294, Address: 0x1029534 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1295, Address: 0x1029540 */
  pMapWk = (unsigned char*)mapwka; /* Line 1296, Address: 0x102954c */
  pScrFlag = &scrflagaw.b.h; /* Line 1297, Address: 0x1029554 */

  if (*pScrFlag) { /* Line 1299, Address: 0x102955c */
    if (*pScrFlag & 1) { /* Line 1300, Address: 0x1029568 */
      *pScrFlag &= 254; /* Line 1301, Address: 0x102957c */

      lD4.l = -16; /* Line 1303, Address: 0x1029588 */
      wD5 = 65520; /* Line 1304, Address: 0x1029590 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1306, Address: 0x1029598 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1308, Address: 0x10295b8 */
    }




    if (*pScrFlag & 2) { /* Line 1314, Address: 0x10295e4 */
      *pScrFlag &= 253; /* Line 1315, Address: 0x10295f8 */

      lD4.l = 224; /* Line 1317, Address: 0x1029604 */
      wD5 = 65520; /* Line 1318, Address: 0x102960c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1319, Address: 0x1029614 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1321, Address: 0x1029634 */
    }




    if (*pScrFlag & 4) { /* Line 1327, Address: 0x1029660 */
      *pScrFlag &= 251; /* Line 1328, Address: 0x1029674 */

      lD4.l = -16; /* Line 1330, Address: 0x1029680 */
      wD5 = 65520; /* Line 1331, Address: 0x1029688 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1332, Address: 0x1029690 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1334, Address: 0x10296b0 */
    }




    if (*pScrFlag & 8) { /* Line 1340, Address: 0x10296dc */
      *pScrFlag &= 247; /* Line 1341, Address: 0x10296f0 */

      lD4.l = -16; /* Line 1343, Address: 0x10296fc */
      wD5 = 320; /* Line 1344, Address: 0x1029704 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1345, Address: 0x102970c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1347, Address: 0x102972c */
    }
  }






} /* Line 1356, Address: 0x1029758 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1373, Address: 0x1029780 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1384, Address: 0x10297ac */

  if (*pScrFlag & 1) { /* Line 1386, Address: 0x10297b4 */
    *pScrFlag &= 254; /* Line 1387, Address: 0x10297cc */
  } /* Line 1388, Address: 0x10297e0 */
  else {
    *pScrFlag &= 254; /* Line 1390, Address: 0x10297e8 */

    if (*pScrFlag & 2) { /* Line 1392, Address: 0x10297fc */
      *pScrFlag &= 253; /* Line 1393, Address: 0x1029814 */
      lD4.w.l = 224; /* Line 1394, Address: 0x1029828 */
    } /* Line 1395, Address: 0x1029830 */
    else {
      *pScrFlag &= 253; /* Line 1397, Address: 0x1029838 */
      goto label1; /* Line 1398, Address: 0x102984c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1403, Address: 0x1029854 */
  wD0 &= 127; /* Line 1404, Address: 0x10298a4 */
  wD0 = z31dwrttbl[wD0 + 1]; /* Line 1405, Address: 0x10298ac */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1411, Address: 0x10298cc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1412, Address: 0x10298ec */
  if (wD0 != 0) { /* Line 1413, Address: 0x1029910 */
    wD5 = 65520; /* Line 1414, Address: 0x102991c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1415, Address: 0x1029924 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1417, Address: 0x1029944 */



  } /* Line 1421, Address: 0x1029970 */
  else {

    wD5 = 0; /* Line 1424, Address: 0x1029978 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1425, Address: 0x102997c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1429, Address: 0x102999c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1436, Address: 0x10299c8 */






    lD4.l = -16; /* Line 1443, Address: 0x10299dc */
    wD5 = 65520; /* Line 1444, Address: 0x10299e4 */
    if (*pScrFlag & 168) { /* Line 1445, Address: 0x10299ec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1446, Address: 0x1029a04 */
      wD5 = 320; /* Line 1447, Address: 0x1029a24 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1451, Address: 0x1029a2c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1453, Address: 0x1029a5c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1454, Address: 0x1029a68 */



    for (i = 0; i < 16; ++i) { /* Line 1458, Address: 0x1029a78 */
      wD0 = z31dwrttbl[WrtTblCnt++]; /* Line 1459, Address: 0x1029a84 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1460, Address: 0x1029aa4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1461, Address: 0x1029ad0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1462, Address: 0x1029af0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1464, Address: 0x1029b14 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1467, Address: 0x1029b38 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1469, Address: 0x1029b58 */
      }
      lD4.w.l += 16; /* Line 1471, Address: 0x1029b6c */
    } /* Line 1472, Address: 0x1029b78 */
    *pScrFlag = 0; /* Line 1473, Address: 0x1029b88 */
  }
} /* Line 1475, Address: 0x1029b90 */







void scrollwrtc() {} /* Line 1483, Address: 0x1029bc0 */




void scrollwrtz() {} /* Line 1488, Address: 0x1029bd0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1509, Address: 0x1029be0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1522, Address: 0x1029c08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1525, Address: 0x1029c28 */
    pTilePoint->x += 2; /* Line 1526, Address: 0x1029c3c */
    if (pTilePoint->x >= 64) { /* Line 1527, Address: 0x1029c50 */
      pTilePoint->x -= 64; /* Line 1528, Address: 0x1029c64 */
    }
    xOffs += 16; /* Line 1530, Address: 0x1029c78 */
  } while (--lpcnt >= 0); /* Line 1531, Address: 0x1029c84 */
} /* Line 1532, Address: 0x1029c98 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1536, Address: 0x1029cb0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1540, Address: 0x1029cd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1543, Address: 0x1029cf8 */
    pTilePoint->x += 2; /* Line 1544, Address: 0x1029d0c */
    if (pTilePoint->x >= 64) { /* Line 1545, Address: 0x1029d20 */
      pTilePoint->x -= 64; /* Line 1546, Address: 0x1029d34 */
    }
    xOffs += 16; /* Line 1548, Address: 0x1029d48 */
  } while (--lpcnt >= 0); /* Line 1549, Address: 0x1029d54 */
} /* Line 1550, Address: 0x1029d68 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1569, Address: 0x1029d80 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1573, Address: 0x1029da8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1576, Address: 0x1029dc8 */
    pTilePoint->y += 2; /* Line 1577, Address: 0x1029ddc */
    if (pTilePoint->y >= 32) { /* Line 1578, Address: 0x1029dec */
      pTilePoint->y -= 32; /* Line 1579, Address: 0x1029e00 */
    }
    yOffs += 16; /* Line 1581, Address: 0x1029e10 */
  } while (--lpcnt >= 0); /* Line 1582, Address: 0x1029e1c */
} /* Line 1583, Address: 0x1029e30 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1602, Address: 0x1029e40 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1608, Address: 0x1029e74 */

    base = 1; /* Line 1610, Address: 0x1029e84 */
  } /* Line 1611, Address: 0x1029e88 */
  else if (VramBase == 16384) { /* Line 1612, Address: 0x1029e90 */

    base = 0; /* Line 1614, Address: 0x1029ea0 */
  }
  x = pTilePoint->x; /* Line 1616, Address: 0x1029ea4 */
  y = pTilePoint->y; /* Line 1617, Address: 0x1029eac */


  frip = BlkIndex & 6144; /* Line 1620, Address: 0x1029eb4 */
  BlkIndex &= 1023; /* Line 1621, Address: 0x1029ebc */
  if (frip == 6144) { /* Line 1622, Address: 0x1029ec8 */

    p0 = 3, p1 = 2; /* Line 1624, Address: 0x1029ed4 */
    p2 = 1, p3 = 0; /* Line 1625, Address: 0x1029edc */
  } /* Line 1626, Address: 0x1029ee4 */
  else if (frip & 4096) { /* Line 1627, Address: 0x1029eec */

    p0 = 2, p1 = 3; /* Line 1629, Address: 0x1029ef8 */
    p2 = 0, p3 = 1; /* Line 1630, Address: 0x1029f00 */
  } /* Line 1631, Address: 0x1029f08 */
  else if (frip & 2048) { /* Line 1632, Address: 0x1029f10 */

    p0 = 1, p1 = 0; /* Line 1634, Address: 0x1029f1c */
    p2 = 3, p3 = 2; /* Line 1635, Address: 0x1029f24 */
  } /* Line 1636, Address: 0x1029f2c */
  else {

    p0 = 0, p1 = 1; /* Line 1639, Address: 0x1029f34 */
    p2 = 2, p3 = 3; /* Line 1640, Address: 0x1029f3c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1643, Address: 0x1029f44 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1644, Address: 0x1029f88 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1645, Address: 0x1029fcc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1646, Address: 0x102a010 */

} /* Line 1648, Address: 0x102a054 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1666, Address: 0x102a090 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1667, Address: 0x102a0b0 */
} /* Line 1668, Address: 0x102a0d0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1670, Address: 0x102a0e0 */
  wH_posiw = 0; /* Line 1671, Address: 0x102a100 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1672, Address: 0x102a104 */
} /* Line 1673, Address: 0x102a124 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1680, Address: 0x102a140 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1686, Address: 0x102a170 */
  yOffs += wV_posiw; /* Line 1687, Address: 0x102a180 */





  if ((short)xOffs < 0) /* Line 1693, Address: 0x102a190 */
    xOffs = 0; /* Line 1694, Address: 0x102a1ac */
  if ((short)yOffs < 0) /* Line 1695, Address: 0x102a1b0 */
    yOffs = 0; /* Line 1696, Address: 0x102a1cc */
  if ((short)xOffs >= 16384) /* Line 1697, Address: 0x102a1d0 */
    xOffs = 16383; /* Line 1698, Address: 0x102a1f0 */
  if ((short)yOffs >= 2048) /* Line 1699, Address: 0x102a1f8 */
    yOffs = 2047; /* Line 1700, Address: 0x102a218 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1701, Address: 0x102a220 */
  if (i < 0) i = 0; /* Line 1702, Address: 0x102a268 */

  ScreenNo = pMapWk[i] & 127; /* Line 1704, Address: 0x102a274 */

  if (ScreenNo) { /* Line 1706, Address: 0x102a290 */




    xOffs &= 32767; /* Line 1711, Address: 0x102a298 */
    yOffs &= 32767; /* Line 1712, Address: 0x102a2a4 */


    xBlk = xOffs; /* Line 1715, Address: 0x102a2b0 */
    xBlk %= 256; /* Line 1716, Address: 0x102a2b8 */
    xBlk /= 16; /* Line 1717, Address: 0x102a2d8 */
    yBlk = yOffs; /* Line 1718, Address: 0x102a2f4 */
    yBlk %= 256; /* Line 1719, Address: 0x102a2fc */
    yBlk /= 16; /* Line 1720, Address: 0x102a31c */

    lpw = pmapwk; /* Line 1722, Address: 0x102a338 */
    lpw += xBlk; /* Line 1723, Address: 0x102a340 */
    lpw += yBlk * 16; /* Line 1724, Address: 0x102a348 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1725, Address: 0x102a354 */
    *pIndex = *lpw; /* Line 1726, Address: 0x102a36c */

    return 1; /* Line 1728, Address: 0x102a37c */
  }

  *pIndex = 0; /* Line 1731, Address: 0x102a388 */
  return 0; /* Line 1732, Address: 0x102a390 */
} /* Line 1733, Address: 0x102a394 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1753, Address: 0x102a3c0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1761, Address: 0x102a3e8 */
  if (ScreenNo) { /* Line 1762, Address: 0x102a44c */





    xBlk = xOffs; /* Line 1768, Address: 0x102a454 */
    xBlk %= 256; /* Line 1769, Address: 0x102a45c */
    xBlk /= 16; /* Line 1770, Address: 0x102a47c */
    yBlk = yOffs; /* Line 1771, Address: 0x102a498 */
    yBlk %= 256; /* Line 1772, Address: 0x102a4a0 */
    yBlk /= 16; /* Line 1773, Address: 0x102a4c0 */


    lpw = pmapwk; /* Line 1776, Address: 0x102a4dc */
    lpw += xBlk; /* Line 1777, Address: 0x102a4e4 */
    lpw += yBlk * 16; /* Line 1778, Address: 0x102a4ec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1779, Address: 0x102a4f8 */
    *ppBlockNo = lpw; /* Line 1780, Address: 0x102a510 */
    *pIndex = *lpw; /* Line 1781, Address: 0x102a518 */




    return 1; /* Line 1786, Address: 0x102a528 */
  }

  *pIndex = 0; /* Line 1789, Address: 0x102a534 */
  return 0; /* Line 1790, Address: 0x102a53c */
} /* Line 1791, Address: 0x102a540 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1805, Address: 0x102a560 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1812, Address: 0x102a57c */
  pMapWk = (unsigned char*)mapwka; /* Line 1813, Address: 0x102a580 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1814, Address: 0x102a588 */
    *pBlockIndex = BlockNo; /* Line 1815, Address: 0x102a5ac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1816, Address: 0x102a5b8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1817, Address: 0x102a5d0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1818, Address: 0x102a5e4 */
    }
  }


} /* Line 1823, Address: 0x102a5fc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1837, Address: 0x102a620 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1838, Address: 0x102a62c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1839, Address: 0x102a658 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1840, Address: 0x102a6a4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1841, Address: 0x102a6d0 */

          return 0; /* Line 1843, Address: 0x102a71c */
        }
      }
    }
  }

  return 1; /* Line 1849, Address: 0x102a728 */
} /* Line 1850, Address: 0x102a72c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1867, Address: 0x102a740 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1868, Address: 0x102a75c */

} /* Line 1870, Address: 0x102a778 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1872, Address: 0x102a790 */
  wH_posiw = 0; /* Line 1873, Address: 0x102a7ac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1874, Address: 0x102a7b0 */

} /* Line 1876, Address: 0x102a7cc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1878, Address: 0x102a7e0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1879, Address: 0x102a7f4 */

} /* Line 1881, Address: 0x102a810 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1883, Address: 0x102a820 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1884, Address: 0x102a83c */

} /* Line 1886, Address: 0x102a858 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1888, Address: 0x102a870 */
  xOffs += wH_posiw; /* Line 1889, Address: 0x102a888 */
  yOffs += wV_posiw; /* Line 1890, Address: 0x102a898 */
  yOffs &= 240; /* Line 1891, Address: 0x102a8a8 */
  xOffs &= 496; /* Line 1892, Address: 0x102a8b4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1894, Address: 0x102a8c0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1895, Address: 0x102a8ec */


} /* Line 1898, Address: 0x102a918 */















void mapwrt() { /* Line 1914, Address: 0x102a930 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1919, Address: 0x102a948 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1920, Address: 0x102a954 */
  pMapWk = (unsigned char*)mapwka; /* Line 1921, Address: 0x102a960 */
  VramBase = 16384; /* Line 1922, Address: 0x102a968 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1923, Address: 0x102a96c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1927, Address: 0x102a984 */
  VramBase = 24576; /* Line 1928, Address: 0x102a98c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1929, Address: 0x102a990 */

} /* Line 1931, Address: 0x102a9a0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1934, Address: 0x102a9c0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1935, Address: 0x102a9d8 */
} /* Line 1936, Address: 0x102a9f8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1941, Address: 0x102aa10 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1945, Address: 0x102aa30 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1948, Address: 0x102aa4c */



    wD4 += 16; /* Line 1952, Address: 0x102aa74 */
  } while ((short)--wD6 >= 0); /* Line 1953, Address: 0x102aa80 */

} /* Line 1955, Address: 0x102aaa8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1960, Address: 0x102aac0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1963, Address: 0x102aadc */
  wD6 = 15; /* Line 1964, Address: 0x102aae4 */






  do {
    if (actwk[0].xposi.w.h == 96) /* Line 1972, Address: 0x102aaec */
      wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1973, Address: 0x102ab08 */
    else
      wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1975, Address: 0x102ab34 */

    mapwrt_sub(&z31dwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1977, Address: 0x102ab58 */
    wD4 += 16; /* Line 1978, Address: 0x102ab78 */
  } while ((short)--wD6 >= 0); /* Line 1979, Address: 0x102ab80 */
} /* Line 1980, Address: 0x102aba4 */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2006, Address: 0x102abc0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2011, Address: 0x102abe8 */
  wD0 = pWrttbl[wD0]; /* Line 2012, Address: 0x102abf8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2014, Address: 0x102ac14 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2015, Address: 0x102ac38 */
  if (wD0) { /* Line 2016, Address: 0x102ac60 */
    wD5 = 65520; /* Line 2017, Address: 0x102ac6c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2018, Address: 0x102ac74 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2021, Address: 0x102ac90 */



  } /* Line 2025, Address: 0x102acb8 */
  else {

    wD5 = 0; /* Line 2028, Address: 0x102acc0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2029, Address: 0x102acc4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2033, Address: 0x102ace0 */
  }





} /* Line 2040, Address: 0x102ad08 */




void mapinit() { /* Line 2045, Address: 0x102ad30 */





  mapset(); /* Line 2051, Address: 0x102ad38 */


  colorset2(mapinittbl.colorno2); /* Line 2054, Address: 0x102ad40 */
  colorset(mapinittbl.colorno2); /* Line 2055, Address: 0x102ad54 */






  if (plflag != 0) { /* Line 2062, Address: 0x102ad68 */
    enecginit(); /* Line 2063, Address: 0x102ad7c */
  }

  if (play_start & 2) { /* Line 2066, Address: 0x102ad84 */

    divdevset(); /* Line 2068, Address: 0x102ad9c */
  }


} /* Line 2072, Address: 0x102ada4 */









void mapset() {} /* Line 2082, Address: 0x102adc0 */
