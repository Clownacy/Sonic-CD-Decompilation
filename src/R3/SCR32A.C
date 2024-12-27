#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3A.H"

static unsigned char z32awrttbl[49] = {
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








































































void enecginit() {} /* Line 111, Address: 0x1029aa0 */



void divdevset() {} /* Line 115, Address: 0x1029ab0 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 169, Address: 0x1029ac0 */
    return &actwk[0]; /* Line 170, Address: 0x1029ad4 */
  }
  return &actwk[1]; /* Line 172, Address: 0x1029ae4 */
} /* Line 173, Address: 0x1029aec */












void scr_set() { /* Line 186, Address: 0x1029b00 */





  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x1029b0c */
    4, 0, 9879, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1029b40 */

  i = 0; /* Line 199, Address: 0x1029b88 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x1029b8c */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x1029ba8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x1029bbc */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x1029bd8 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x1029bec */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1029c08 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x1029c1c */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1029c38 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x1029c4c */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x1029c68 */
  scra_h_count = 16; /* Line 211, Address: 0x1029c8c */
  scra_v_count = 16; /* Line 212, Address: 0x1029c98 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x1029ca4 */
  scra_hline = 160; /* Line 215, Address: 0x1029cc0 */

  playposiset(); /* Line 217, Address: 0x1029ccc */
} /* Line 218, Address: 0x1029cd4 */











void playposiset() { /* Line 230, Address: 0x1029cf0 */
  unsigned short playpositbl[2] = { /* Line 231, Address: 0x1029d08 */
    32,
    428
  };
  unsigned short endplpositbl[16] = { /* Line 235, Address: 0x1029d24 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 245, Address: 0x1029d58 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 255, Address: 0x1029d84 */
    playload(); /* Line 256, Address: 0x1029d98 */
    xWk = actwk[0].xposi.w.h; /* Line 257, Address: 0x1029da0 */
    yWk = actwk[0].yposi.w.h; /* Line 258, Address: 0x1029db0 */

    if (yWk < 0) yWk = 0; /* Line 260, Address: 0x1029dc0 */

  } /* Line 262, Address: 0x1029dd4 */
  else {

    if (demoflag.w < 0) { /* Line 265, Address: 0x1029ddc */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 266, Address: 0x1029df4 */
    } /* Line 267, Address: 0x1029e1c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 270, Address: 0x1029e24 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 273, Address: 0x1029e44 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 274, Address: 0x1029e60 */
  }


  if ((unsigned short)xWk > 160) { /* Line 278, Address: 0x1029e74 */
    xWk -= 160; /* Line 279, Address: 0x1029e88 */
  } /* Line 280, Address: 0x1029e94 */
  else {
    xWk = 0; /* Line 282, Address: 0x1029e9c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 286, Address: 0x1029ea0 */
    xWk = scralim_right; /* Line 287, Address: 0x1029ec4 */
  }
  scra_h_posit.w.h = xWk; /* Line 289, Address: 0x1029ed4 */

  if ((unsigned short)yWk > 96) { /* Line 291, Address: 0x1029edc */
    yWk -= 96; /* Line 292, Address: 0x1029ef0 */
  } /* Line 293, Address: 0x1029efc */
  else {
    yWk = 0; /* Line 295, Address: 0x1029f04 */
  }

  if (scralim_down < yWk) { /* Line 298, Address: 0x1029f08 */
    yWk = scralim_down; /* Line 299, Address: 0x1029f2c */
  }

  scra_v_posit.w.h = yWk; /* Line 302, Address: 0x1029f3c */

  scrbinit(xWk, yWk); /* Line 304, Address: 0x1029f44 */

  i = 0; /* Line 306, Address: 0x1029f54 */
  loopmapno = playmapnotbl[i++]; /* Line 307, Address: 0x1029f58 */
  loopmapno2 = playmapnotbl[i++]; /* Line 308, Address: 0x1029f70 */
  ballmapno = playmapnotbl[i++]; /* Line 309, Address: 0x1029f88 */
  ballmapno2 = playmapnotbl[i++]; /* Line 310, Address: 0x1029fa0 */


} /* Line 313, Address: 0x1029fb8 */











void scrbinit(short xWk, short yWk) { /* Line 325, Address: 0x1029fe0 */
  int i;
  short wD2;


  yWk = 536; /* Line 330, Address: 0x1029ff4 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 331, Address: 0x1029ffc */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 332, Address: 0x102a024 */
    yWk -= wD2 / 2; /* Line 333, Address: 0x102a040 */
    if (yWk < 0) { /* Line 334, Address: 0x102a074 */
      yWk = 0; /* Line 335, Address: 0x102a088 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 339, Address: 0x102a08c */
  scrb_v_posit.w.l = 0; /* Line 340, Address: 0x102a098 */
  scrc_v_posit.w.h = yWk; /* Line 341, Address: 0x102a0a0 */
  scrz_v_posit.w.h = yWk; /* Line 342, Address: 0x102a0ac */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 344, Address: 0x102a0b8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 345, Address: 0x102a0f0 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 346, Address: 0x102a130 */


  for (i = 0; i < 14; ++i) { /* Line 349, Address: 0x102a170 */
    ((int*)hscrollwork)[i] = 0; /* Line 350, Address: 0x102a17c */
  } /* Line 351, Address: 0x102a190 */

} /* Line 353, Address: 0x102a1a0 */












void scroll() { /* Line 366, Address: 0x102a1c0 */
  int LineSpdTbl[14] = { /* Line 367, Address: 0x102a1e0 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  4096,  8192,
    12288, 16384, 24576,
    32768, 49152
  };
  unsigned char z32a_cnttbl[14] = { /* Line 374, Address: 0x102a214 */
    1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 3, 5
  };
  unsigned short z32a_kawatbl[3] = { /* Line 377, Address: 0x102a248 */
    56, 592, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 387, Address: 0x102a26c */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 390, Address: 0x102a27c */
  scrchk(); /* Line 391, Address: 0x102a2a8 */
  scroll_h(); /* Line 392, Address: 0x102a2b4 */
  scroll_v(); /* Line 393, Address: 0x102a2c0 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 395, Address: 0x102a2cc */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 396, Address: 0x102a2dc */


  scrollz_h(scra_hz << 4, 64); /* Line 399, Address: 0x102a2ec */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 400, Address: 0x102a310 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 401, Address: 0x102a34c */

  lD0.w.l = 536; /* Line 403, Address: 0x102a388 */
  wD1 = 1312; /* Line 404, Address: 0x102a390 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 405, Address: 0x102a398 */

    wD1 -= scra_v_posit.w.h; /* Line 407, Address: 0x102a3b8 */
    wD1 >>= 1; /* Line 408, Address: 0x102a3cc */
    lD0.w.l -= wD1; /* Line 409, Address: 0x102a3d4 */
    if (lD0.w.l < 0) { /* Line 410, Address: 0x102a3e8 */
      lD0.w.l = 0; /* Line 411, Address: 0x102a3fc */
    }
  } /* Line 413, Address: 0x102a400 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 415, Address: 0x102a408 */
  }

  scrollb_v(lD0.w.l); /* Line 418, Address: 0x102a41c */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 419, Address: 0x102a430 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 420, Address: 0x102a440 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 421, Address: 0x102a450 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 423, Address: 0x102a460 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 424, Address: 0x102a47c */
  scrflagz.b.h = 0; /* Line 425, Address: 0x102a498 */
  scrflagc.b.h = 0; /* Line 426, Address: 0x102a4a0 */





















  pHscrWk = (int_union*)hscrollwork; /* Line 448, Address: 0x102a4a8 */
  for (i = 0; i < 14; ++i) { /* Line 449, Address: 0x102a4b0 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 450, Address: 0x102a4bc */
    ++pHscrWk; /* Line 451, Address: 0x102a4d4 */
  } /* Line 452, Address: 0x102a4d8 */
  wD1 = 0; /* Line 453, Address: 0x102a4e8 */
  for ( ; i < 78; ++i) { /* Line 454, Address: 0x102a4ec */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 455, Address: 0x102a4f4 */
    pHscrWk->l += lD2.l; /* Line 456, Address: 0x102a518 */
    ++pHscrWk; /* Line 457, Address: 0x102a528 */
    ++wD1; /* Line 458, Address: 0x102a52c */
  } /* Line 459, Address: 0x102a534 */






  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 466, Address: 0x102a544 */
  lD2.l <<= 6; /* Line 467, Address: 0x102a56c */
  lD2.l /= 28; /* Line 468, Address: 0x102a578 */
  lD2.l <<= 10; /* Line 469, Address: 0x102a598 */

  lD3.l = 0; /* Line 471, Address: 0x102a5a4 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 472, Address: 0x102a5a8 */

  pHScrollWork = &hscrollwork[162]; /* Line 474, Address: 0x102a5b4 */
  for (i = 0; i < 7; ++i) { /* Line 475, Address: 0x102a5c0 */
    lD0.w.l = -lD3.w.l; /* Line 476, Address: 0x102a5cc */
    *pHScrollWork-- = lD0.w.l; /* Line 477, Address: 0x102a5e8 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 478, Address: 0x102a5fc */
    lD3.l += lD2.l; /* Line 479, Address: 0x102a620 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 480, Address: 0x102a630 */
  } /* Line 481, Address: 0x102a654 */

  pHScrollWork = &hscrollwork[163]; /* Line 483, Address: 0x102a664 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 484, Address: 0x102a670 */

  for (i = 0; i < 3; ++i) { /* Line 486, Address: 0x102a694 */
    *pHScrollWork++ = lD0.w.l; /* Line 487, Address: 0x102a6a0 */
  } /* Line 488, Address: 0x102a6b4 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 490, Address: 0x102a6c4 */

  for (i = 0; i < 4; ++i) { /* Line 492, Address: 0x102a6e8 */
    *pHScrollWork++ = lD0.w.l; /* Line 493, Address: 0x102a6f4 */
  } /* Line 494, Address: 0x102a708 */














  pHscrWk = (int_union*)hscrollwork; /* Line 509, Address: 0x102a718 */
  for (i = 13; i >= 0; --i) { /* Line 510, Address: 0x102a720 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 511, Address: 0x102a72c */
    ++pHscrWk; /* Line 512, Address: 0x102a758 */
    for (j = z32a_cnttbl[i]; j >= 0; --j) { /* Line 513, Address: 0x102a75c */
      *pHScrollWork++ = wD1; /* Line 514, Address: 0x102a770 */
    } /* Line 515, Address: 0x102a780 */
  } /* Line 516, Address: 0x102a78c */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 519, Address: 0x102a798 */

  for (i = 0; i < 8; ++i) { /* Line 521, Address: 0x102a7bc */
    *pHScrollWork++ = lD0.w.l; /* Line 522, Address: 0x102a7c8 */
  } /* Line 523, Address: 0x102a7dc */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 525, Address: 0x102a7ec */

  for (i = 0; i < 4; ++i) { /* Line 527, Address: 0x102a810 */
    *pHScrollWork++ = lD0.w.l; /* Line 528, Address: 0x102a81c */
  } /* Line 529, Address: 0x102a830 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 531, Address: 0x102a840 */

  for (i = 0; i < 6; ++i) { /* Line 533, Address: 0x102a864 */
    *pHScrollWork++ = lD0.w.l; /* Line 534, Address: 0x102a870 */
  } /* Line 535, Address: 0x102a884 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 537, Address: 0x102a894 */

  for (i = 0; i < 4; ++i) { /* Line 539, Address: 0x102a8b8 */
    *pHScrollWork++ = lD0.w.l; /* Line 540, Address: 0x102a8c4 */
  } /* Line 541, Address: 0x102a8d8 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 544, Address: 0x102a8e8 */
  lD2.l <<= 6; /* Line 545, Address: 0x102a920 */
  lD2.l /= 44; /* Line 546, Address: 0x102a92c */
  lD2.l <<= 11; /* Line 547, Address: 0x102a94c */
  lD3.w.l = scrb_h_posit.w.h; /* Line 548, Address: 0x102a958 */

  for (i = 0; i < 10; ++i) { /* Line 550, Address: 0x102a964 */
    *pHScrollWork++ = (unsigned short)-lD3.w.l; /* Line 551, Address: 0x102a970 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 552, Address: 0x102a99c */
    lD3.l += lD2.l; /* Line 553, Address: 0x102a9c0 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 554, Address: 0x102a9d0 */
  } /* Line 555, Address: 0x102a9f4 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 557, Address: 0x102aa04 */

  for (i = 0; i < 8; ++i) { /* Line 559, Address: 0x102aa28 */
    *pHScrollWork++ = lD0.w.l; /* Line 560, Address: 0x102aa34 */
  } /* Line 561, Address: 0x102aa48 */

  pHScrollBuff = lphscrollbuff; /* Line 563, Address: 0x102aa58 */
  pHScrollWork = &hscrollwork[156]; /* Line 564, Address: 0x102aa64 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 565, Address: 0x102aa70 */
  lD2.w.l = lD0.w.l; /* Line 566, Address: 0x102aa7c */
  wD4 = lD0.w.l; /* Line 567, Address: 0x102aa84 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 568, Address: 0x102aa8c */
  wD3 = lD0.w.l >> 1; /* Line 569, Address: 0x102aab0 */
  wD1 = 87; /* Line 570, Address: 0x102aac8 */
  wD5 = 29; /* Line 571, Address: 0x102aad0 */
  if (wD3 <= wD1) { /* Line 572, Address: 0x102aad8 */

    wD1 -= wD3; /* Line 574, Address: 0x102aaec */
    if (wD1 >= 27) { /* Line 575, Address: 0x102aaf4 */
      wD1 = 28; /* Line 576, Address: 0x102ab04 */
    }

    wD5 -= wD1; /* Line 579, Address: 0x102ab0c */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 580, Address: 0x102ab18 */
    waterdirec.w += 64; /* Line 581, Address: 0x102ab3c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z32a_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 583, Address: 0x102ab50 */


  } /* Line 586, Address: 0x102ab7c */
  else {
    wD1 -= wD3; /* Line 588, Address: 0x102ab84 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 593, Address: 0x102ab90 */
  pHScrollWork = &hscrollwork[28]; /* Line 594, Address: 0x102aba4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 595, Address: 0x102abb0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 596, Address: 0x102abc4 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 599, Address: 0x102abdc */
    lD2.w.l = *pHScrollWork++; /* Line 600, Address: 0x102abf0 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 601, Address: 0x102ac04 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 602, Address: 0x102ac18 */
    lD0.w.l = lD2.w.l; /* Line 603, Address: 0x102ac38 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 604, Address: 0x102ac40 */
    if (wD3 <= wD4) { /* Line 605, Address: 0x102ac60 */
      wD5 &= 255; /* Line 606, Address: 0x102ac78 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 607, Address: 0x102ac80 */
      wD3 += scra_h_posit.w.h; /* Line 608, Address: 0x102acac */
      wD3 = -(short)wD3; /* Line 609, Address: 0x102acc0 */
      lD0.w.h = wD3; /* Line 610, Address: 0x102acdc */
    }

    pHScrollBuff->l = lD0.l; /* Line 613, Address: 0x102ace0 */
    ++pHScrollBuff; /* Line 614, Address: 0x102acec */
    ++wD4; /* Line 615, Address: 0x102acf8 */
    ++wD5; /* Line 616, Address: 0x102ad04 */
  } while ((short)--wD1 >= 0); /* Line 617, Address: 0x102ad0c */

} /* Line 619, Address: 0x102ad30 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 624, Address: 0x102ad60 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 631, Address: 0x102ad94 */
  pA1 = *ppA1; /* Line 632, Address: 0x102adb4 */
  pA2 = *ppA2; /* Line 633, Address: 0x102adbc */

  if (*pA3 <= *pwD4) goto label6; /* Line 635, Address: 0x102adc4 */



label1:
  *pwD2 &= 7; /* Line 640, Address: 0x102ade8 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 641, Address: 0x102adfc */

  lD0.w.l = *pA2++; /* Line 643, Address: 0x102ae28 */
  i = 8 - *pwD2; /* Line 644, Address: 0x102ae38 */
  goto label4; /* Line 645, Address: 0x102ae4c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 648, Address: 0x102ae54 */


  if (*pA3 <= *pwD4) goto label7; /* Line 651, Address: 0x102ae70 */



label3:
  lD0.w.l = *pA2++; /* Line 656, Address: 0x102ae94 */
  *pwD4 += 8; /* Line 657, Address: 0x102aea4 */


  i = 8; /* Line 660, Address: 0x102aeb8 */
label4:
  for ( ; i > 0; --i) { /* Line 662, Address: 0x102aebc */


    pA1->l = lD0.l; /* Line 665, Address: 0x102aec4 */
    ++pA1; /* Line 666, Address: 0x102aecc */
  } /* Line 667, Address: 0x102aed0 */
  if ((short)--wD1 >= 0) goto label2; /* Line 668, Address: 0x102aee0 */



label5:
  *ppA1 = pA1; /* Line 673, Address: 0x102af08 */
  *ppA2 = pA2; /* Line 674, Address: 0x102af10 */
  return; /* Line 675, Address: 0x102af18 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 679, Address: 0x102af20 */
  if ((short)wD3 > 0) goto label8; /* Line 680, Address: 0x102af50 */


  if (*pA3 > *pwD4) goto label1; /* Line 683, Address: 0x102af68 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 686, Address: 0x102af8c */
  if ((short)wD3 > 0) goto label8; /* Line 687, Address: 0x102afbc */
  goto label1; /* Line 688, Address: 0x102afd4 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 696, Address: 0x102afdc */
  if ((short)wD3 <= 0) goto label3; /* Line 697, Address: 0x102b00c */



label8:
  --wD3; /* Line 702, Address: 0x102b024 */
  wD6 = wD3; /* Line 703, Address: 0x102b02c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 704, Address: 0x102b030 */

  do {
    *pwD2 &= 255; /* Line 707, Address: 0x102b048 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 708, Address: 0x102b05c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 709, Address: 0x102b088 */
    lD0.w.l = -lD0.w.l; /* Line 710, Address: 0x102b09c */
    pA1->w.h = lD0.w.h; /* Line 711, Address: 0x102b0b8 */
    pA1->w.l = lD0.w.l; /* Line 712, Address: 0x102b0c0 */
    ++pA1; /* Line 713, Address: 0x102b0c8 */
    ++*pwD4; /* Line 714, Address: 0x102b0cc */
    ++*pwD2; /* Line 715, Address: 0x102b0e0 */
  } while ((short)--wD3 >= 0); /* Line 716, Address: 0x102b0f4 */

  wD6 >>= 3; /* Line 718, Address: 0x102b118 */

  do {
    lD0.w.l = *pA2++; /* Line 721, Address: 0x102b120 */
    --wD1; /* Line 722, Address: 0x102b130 */
  } while ((short)--wD6 >= 0); /* Line 723, Address: 0x102b13c */
  goto label2; /* Line 724, Address: 0x102b160 */
} /* Line 725, Address: 0x102b168 */















void scroll_h() { /* Line 741, Address: 0x102b190 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 744, Address: 0x102b19c */
  scrh_move(); /* Line 745, Address: 0x102b1a8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 746, Address: 0x102b1b0 */
    scra_h_count ^= 16; /* Line 747, Address: 0x102b1e4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 748, Address: 0x102b1f8 */
      scrflaga.b.h |= 4; /* Line 749, Address: 0x102b224 */
    } /* Line 750, Address: 0x102b238 */
    else {

      scrflaga.b.h |= 8; /* Line 753, Address: 0x102b240 */
    }
  }


} /* Line 758, Address: 0x102b254 */

void scrh_move() { /* Line 760, Address: 0x102b270 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 763, Address: 0x102b27c */
  wD0 -= scra_h_posit.w.h; /* Line 764, Address: 0x102b288 */
  wD0 -= scra_hline; /* Line 765, Address: 0x102b29c */
  if (wD0 == 0) { /* Line 766, Address: 0x102b2b0 */

    scra_hz = 0; /* Line 768, Address: 0x102b2bc */
  } /* Line 769, Address: 0x102b2c4 */
  else if ((short)wD0 < 0) { /* Line 770, Address: 0x102b2cc */
    left_check(wD0); /* Line 771, Address: 0x102b2e4 */
  } /* Line 772, Address: 0x102b2f0 */
  else {
    right_check(wD0); /* Line 774, Address: 0x102b2f8 */
  }

} /* Line 777, Address: 0x102b304 */


void right_check(unsigned short wD0) { /* Line 780, Address: 0x102b320 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 783, Address: 0x102b32c */
    wD0 = 16; /* Line 784, Address: 0x102b34c */
  }

  wD0 += scra_h_posit.w.h; /* Line 787, Address: 0x102b354 */
  if (scralim_right < (short)wD0) { /* Line 788, Address: 0x102b36c */
    wD0 = scralim_right; /* Line 789, Address: 0x102b39c */
  }

  wD1 = wD0; /* Line 792, Address: 0x102b3a8 */
  wD1 -= scra_h_posit.w.h; /* Line 793, Address: 0x102b3b0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 794, Address: 0x102b3c4 */
  scra_h_posit.w.h = wD0; /* Line 795, Address: 0x102b3f4 */
  scra_hz = wD1; /* Line 796, Address: 0x102b400 */

} /* Line 798, Address: 0x102b408 */


void left_check(unsigned short wD0) { /* Line 801, Address: 0x102b420 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 804, Address: 0x102b42c */
    wD0 = -16; /* Line 805, Address: 0x102b44c */
  }

  wD0 += scra_h_posit.w.h; /* Line 808, Address: 0x102b454 */
  if (scralim_left > (short)wD0) { /* Line 809, Address: 0x102b46c */
    wD0 = scralim_left; /* Line 810, Address: 0x102b49c */
  }

  wD1 = wD0; /* Line 813, Address: 0x102b4a8 */
  wD1 -= scra_h_posit.w.h; /* Line 814, Address: 0x102b4b0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 815, Address: 0x102b4c4 */
  scra_h_posit.w.h = wD0; /* Line 816, Address: 0x102b4f4 */
  scra_hz = wD1; /* Line 817, Address: 0x102b500 */

} /* Line 819, Address: 0x102b508 */


















void scroll_v() { /* Line 838, Address: 0x102b520 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 841, Address: 0x102b52c */
  if (actwk[0].cddat & 4) { /* Line 842, Address: 0x102b558 */
    wD0 -= 5; /* Line 843, Address: 0x102b570 */
  }

  if (actwk[0].cddat & 2) { /* Line 846, Address: 0x102b578 */
    wD0 += 32; /* Line 847, Address: 0x102b590 */
    if ((unsigned short)scra_vline > wD0) { /* Line 848, Address: 0x102b598 */
      wD0 -= scra_vline; /* Line 849, Address: 0x102b5b8 */
      sv_move_main2(wD0); /* Line 850, Address: 0x102b5cc */
      return; /* Line 851, Address: 0x102b5d8 */
    }
    wD0 -= scra_vline; /* Line 853, Address: 0x102b5e0 */
    if (wD0 >= 64) { /* Line 854, Address: 0x102b5f4 */
      wD0 -= 64; /* Line 855, Address: 0x102b604 */
      sv_move_main2(wD0); /* Line 856, Address: 0x102b60c */
      return; /* Line 857, Address: 0x102b618 */
    }
    wD0 -= 64; /* Line 859, Address: 0x102b620 */
    if (limmoveflag == 0) goto label1; /* Line 860, Address: 0x102b628 */
    sv_move_sub2(); /* Line 861, Address: 0x102b63c */
    return; /* Line 862, Address: 0x102b644 */
  }




  wD0 -= scra_vline; /* Line 868, Address: 0x102b64c */
  if (wD0) { /* Line 869, Address: 0x102b660 */
    sv_move_main(wD0); /* Line 870, Address: 0x102b668 */
    return; /* Line 871, Address: 0x102b674 */
  }
  if (limmoveflag == 0) { /* Line 873, Address: 0x102b67c */
    sv_move_sub2(); /* Line 874, Address: 0x102b690 */
    return; /* Line 875, Address: 0x102b698 */
  }


label1:
  scra_vz = 0; /* Line 880, Address: 0x102b6a0 */

} /* Line 882, Address: 0x102b6a8 */





void sv_move_main(unsigned short wD0) { /* Line 888, Address: 0x102b6c0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 891, Address: 0x102b6d0 */
    sv_move_main1(wD0); /* Line 892, Address: 0x102b6ec */
  } /* Line 893, Address: 0x102b6f8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 896, Address: 0x102b700 */
    if ((short)wD1 < 0) { /* Line 897, Address: 0x102b70c */
      wD1 = -(short)wD1; /* Line 898, Address: 0x102b724 */
    }

    if (wD1 >= 2048) { /* Line 901, Address: 0x102b740 */
      sv_move_main2(wD0); /* Line 902, Address: 0x102b750 */
    } /* Line 903, Address: 0x102b75c */
    else {
      if ((short)wD0 > 6) { /* Line 905, Address: 0x102b764 */
        sv_move_plus(1536); /* Line 906, Address: 0x102b784 */
      } /* Line 907, Address: 0x102b790 */
      else if ((short)wD0 < -6) { /* Line 908, Address: 0x102b798 */
        sv_move_minus(1536); /* Line 909, Address: 0x102b7b8 */
      } /* Line 910, Address: 0x102b7c4 */
      else {
        sv_move_sub(wD0); /* Line 912, Address: 0x102b7cc */
      }
    }
  }
} /* Line 916, Address: 0x102b7d8 */



void sv_move_main1(unsigned short wD0) { /* Line 920, Address: 0x102b7f0 */

  if ((short)wD0 > 2) { /* Line 922, Address: 0x102b7fc */
    sv_move_plus(512); /* Line 923, Address: 0x102b81c */
  } /* Line 924, Address: 0x102b828 */
  else if ((short)wD0 < -2) { /* Line 925, Address: 0x102b830 */
    sv_move_minus(512); /* Line 926, Address: 0x102b850 */
  } /* Line 927, Address: 0x102b85c */
  else {
    sv_move_sub(wD0); /* Line 929, Address: 0x102b864 */
  }

} /* Line 932, Address: 0x102b870 */


void sv_move_main2(unsigned short wD0) { /* Line 935, Address: 0x102b880 */

  if ((short)wD0 > 16) { /* Line 937, Address: 0x102b88c */
    sv_move_plus(4096); /* Line 938, Address: 0x102b8ac */
  } /* Line 939, Address: 0x102b8b8 */
  else if ((short)wD0 < -16) { /* Line 940, Address: 0x102b8c0 */
    sv_move_minus(4096); /* Line 941, Address: 0x102b8e0 */
  } /* Line 942, Address: 0x102b8ec */
  else {
    sv_move_sub(wD0); /* Line 944, Address: 0x102b8f4 */
  }

} /* Line 947, Address: 0x102b900 */


void sv_move_sub2() { /* Line 950, Address: 0x102b910 */
  limmoveflag = 0; /* Line 951, Address: 0x102b918 */
  sv_move_sub(0); /* Line 952, Address: 0x102b920 */
} /* Line 953, Address: 0x102b92c */


void sv_move_sub(unsigned short wD0) { /* Line 956, Address: 0x102b940 */
  int_union lD1;

  lD1.w.h = 0; /* Line 959, Address: 0x102b94c */
  lD1.w.l = wD0; /* Line 960, Address: 0x102b950 */
  lD1.l += scra_v_posit.w.h; /* Line 961, Address: 0x102b958 */
  if ((short)wD0 > 0) { /* Line 962, Address: 0x102b974 */
    scrv_down_ch(lD1); /* Line 963, Address: 0x102b990 */
  } /* Line 964, Address: 0x102b99c */
  else {
    scrv_up_ch(lD1); /* Line 966, Address: 0x102b9a4 */
  }

} /* Line 969, Address: 0x102b9b0 */




void sv_move_minus(unsigned short wD1) { /* Line 974, Address: 0x102b9c0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 978, Address: 0x102b9d0 */
  lD1.l <<= 8; /* Line 979, Address: 0x102b9ec */
  lD1.l += scra_v_posit.l; /* Line 980, Address: 0x102b9f8 */

  wk = lD1.w.h; /* Line 982, Address: 0x102ba0c */
  lD1.w.h = lD1.w.l; /* Line 983, Address: 0x102ba14 */
  lD1.w.l = wk; /* Line 984, Address: 0x102ba1c */
  scrv_up_ch(lD1); /* Line 985, Address: 0x102ba20 */
} /* Line 986, Address: 0x102ba2c */



void scrv_up_ch(int_union lD1) { /* Line 990, Address: 0x102ba40 */
  if (scralim_up >= lD1.w.l) { /* Line 991, Address: 0x102ba4c */
    if (lD1.w.l < -255) { /* Line 992, Address: 0x102ba74 */
      lD1.w.l &= 2047; /* Line 993, Address: 0x102ba8c */
      actwk[0].yposi.w.h &= 32767; /* Line 994, Address: 0x102ba98 */
      scra_v_posit.w.h &= 2047; /* Line 995, Address: 0x102baac */
      scrb_v_posit.w.h &= 1023; /* Line 996, Address: 0x102bac0 */
    } /* Line 997, Address: 0x102bad4 */
    else {

      lD1.w.l = scralim_up; /* Line 1000, Address: 0x102badc */
    }
  }
  scrv_move(lD1); /* Line 1003, Address: 0x102bae8 */

} /* Line 1005, Address: 0x102baf4 */





void sv_move_plus(unsigned short wD1) { /* Line 1011, Address: 0x102bb10 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1015, Address: 0x102bb20 */
  lD1.w.l = wD1; /* Line 1016, Address: 0x102bb24 */
  lD1.l <<= 8; /* Line 1017, Address: 0x102bb2c */
  lD1.l += scra_v_posit.l; /* Line 1018, Address: 0x102bb38 */

  wk = lD1.w.h; /* Line 1020, Address: 0x102bb4c */
  lD1.w.h = lD1.w.l; /* Line 1021, Address: 0x102bb54 */
  lD1.w.l = wk; /* Line 1022, Address: 0x102bb5c */

  scrv_down_ch(lD1); /* Line 1024, Address: 0x102bb60 */

} /* Line 1026, Address: 0x102bb6c */



void scrv_down_ch(int_union lD1) { /* Line 1030, Address: 0x102bb80 */
  if (scralim_down <= lD1.w.l) { /* Line 1031, Address: 0x102bb8c */
    lD1.w.l -= 2048; /* Line 1032, Address: 0x102bbb4 */
    if (lD1.w.l > 0) { /* Line 1033, Address: 0x102bbc0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1034, Address: 0x102bbd4 */
      scra_v_posit.w.h -= 2048; /* Line 1035, Address: 0x102bbe8 */
      scrb_v_posit.w.h &= 1023; /* Line 1036, Address: 0x102bbfc */
    } /* Line 1037, Address: 0x102bc10 */
    else {
      lD1.w.l = scralim_down; /* Line 1039, Address: 0x102bc18 */
    }
  }
  scrv_move(lD1); /* Line 1042, Address: 0x102bc24 */

} /* Line 1044, Address: 0x102bc30 */


void scrv_move(int_union lD1) { /* Line 1047, Address: 0x102bc40 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1050, Address: 0x102bc50 */

  wk = lD1.w.h; /* Line 1052, Address: 0x102bc5c */
  lD1.w.h = lD1.w.l; /* Line 1053, Address: 0x102bc64 */
  lD1.w.l = wk; /* Line 1054, Address: 0x102bc6c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1056, Address: 0x102bc70 */
  scra_v_posit.l = lD1.l; /* Line 1057, Address: 0x102bc98 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1060, Address: 0x102bca4 */
    scra_v_count ^= 16; /* Line 1061, Address: 0x102bcd8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1062, Address: 0x102bcec */

      scrflaga.b.h |= 2; /* Line 1064, Address: 0x102bd18 */
    } /* Line 1065, Address: 0x102bd2c */
    else {
      scrflaga.b.h |= 1; /* Line 1067, Address: 0x102bd34 */
    }
  }


} /* Line 1072, Address: 0x102bd48 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1076, Address: 0x102bd60 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1079, Address: 0x102bd6c */
  lD0.l += lD4.l; /* Line 1080, Address: 0x102bd7c */
  scrb_h_posit.l = lD0.l; /* Line 1081, Address: 0x102bd8c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1083, Address: 0x102bd98 */

    scrb_h_count ^= 16; /* Line 1085, Address: 0x102bdcc */
    lD0.l -= lD2.l; /* Line 1086, Address: 0x102bde0 */
    if ((long int)lD0.l < 0) { /* Line 1087, Address: 0x102bdf0 */
      scrflagb.b.h |= 4; /* Line 1088, Address: 0x102be04 */
    } /* Line 1089, Address: 0x102be18 */
    else {

      scrflagb.b.h |= 8; /* Line 1092, Address: 0x102be20 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1097, Address: 0x102be34 */
  lD0.l += lD5.l; /* Line 1098, Address: 0x102be44 */
  scrb_h_posit.l = lD0.l; /* Line 1099, Address: 0x102be54 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1101, Address: 0x102be60 */

    scrb_v_count ^= 16; /* Line 1103, Address: 0x102be94 */
    lD0.l -= lD3.l; /* Line 1104, Address: 0x102bea8 */
    if ((long int)lD0.l < 0) { /* Line 1105, Address: 0x102beb8 */
      scrflagb.b.h |= 1; /* Line 1106, Address: 0x102becc */
    } /* Line 1107, Address: 0x102bee0 */
    else {

      scrflagb.b.h |= 2; /* Line 1110, Address: 0x102bee8 */
    }
  }


} /* Line 1115, Address: 0x102befc */






void scrollb_v(unsigned short wD0) { /* Line 1122, Address: 0x102bf10 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1125, Address: 0x102bf1c */
  scrb_v_posit.w.h = wD0; /* Line 1126, Address: 0x102bf28 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1128, Address: 0x102bf34 */
    scrb_v_count ^= 16; /* Line 1129, Address: 0x102bf60 */
    if ((short)wD3 > (short)wD0) { /* Line 1130, Address: 0x102bf74 */
      scrflagb.b.h |= 1; /* Line 1131, Address: 0x102bfa4 */
    } /* Line 1132, Address: 0x102bfb8 */
    else {

      scrflagb.b.h |= 2; /* Line 1135, Address: 0x102bfc0 */
    }
  }


} /* Line 1140, Address: 0x102bfd4 */



void scrollb_h(int lD4, int flagb) { /* Line 1144, Address: 0x102bff0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1148, Address: 0x102c000 */
  lD0.l = lD2.l + lD4; /* Line 1149, Address: 0x102c00c */
  scrb_h_posit.l = lD0.l; /* Line 1150, Address: 0x102c01c */

  lD1.w.h = lD0.w.l; /* Line 1152, Address: 0x102c028 */
  lD1.w.l = lD0.w.h; /* Line 1153, Address: 0x102c030 */
  lD1.w.l &= 16; /* Line 1154, Address: 0x102c038 */

  bD3 = scrb_h_count; /* Line 1156, Address: 0x102c044 */
  lD1.b.b4 ^= bD3; /* Line 1157, Address: 0x102c050 */
  if (!lD1.b.b4) { /* Line 1158, Address: 0x102c064 */
    scrb_h_count ^= 16; /* Line 1159, Address: 0x102c070 */
    lD0.l -= lD2.l; /* Line 1160, Address: 0x102c084 */
    if ((long int)lD0.l < 0) { /* Line 1161, Address: 0x102c094 */
      scrflagb.b.h |= flagb; /* Line 1162, Address: 0x102c0a8 */
    } /* Line 1163, Address: 0x102c0c4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1166, Address: 0x102c0cc */
    }
  }


} /* Line 1171, Address: 0x102c0ec */



void scrollc_h(int lD4, int flagc) { /* Line 1175, Address: 0x102c100 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1179, Address: 0x102c110 */
  lD0.l = lD2.l + lD4; /* Line 1180, Address: 0x102c11c */
  scrc_h_posit.l = lD0.l; /* Line 1181, Address: 0x102c12c */

  lD1.w.h = lD0.w.l; /* Line 1183, Address: 0x102c138 */
  lD1.w.l = lD0.w.h; /* Line 1184, Address: 0x102c140 */
  lD1.w.l &= 16; /* Line 1185, Address: 0x102c148 */

  bD3 = scrc_h_count; /* Line 1187, Address: 0x102c154 */
  lD1.b.b4 ^= bD3; /* Line 1188, Address: 0x102c160 */
  if (!lD1.b.b4) { /* Line 1189, Address: 0x102c174 */
    scrc_h_count ^= 16; /* Line 1190, Address: 0x102c180 */
    lD0.l -= lD2.l; /* Line 1191, Address: 0x102c194 */
    if ((long int)lD0.l < 0) { /* Line 1192, Address: 0x102c1a4 */
      scrflagc.b.h |= flagc; /* Line 1193, Address: 0x102c1b8 */
    } /* Line 1194, Address: 0x102c1d4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1197, Address: 0x102c1dc */
    }
  }


} /* Line 1202, Address: 0x102c1fc */











void scrollz_h(int lD4, int flagz) { /* Line 1214, Address: 0x102c210 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1218, Address: 0x102c220 */
  lD0.l = lD2.l + lD4; /* Line 1219, Address: 0x102c22c */
  scrz_h_posit.l = lD0.l; /* Line 1220, Address: 0x102c23c */

  lD1.w.h = lD0.w.l; /* Line 1222, Address: 0x102c248 */
  lD1.w.l = lD0.w.h; /* Line 1223, Address: 0x102c250 */
  lD1.w.l &= 16; /* Line 1224, Address: 0x102c258 */

  bD3 = scrz_h_count; /* Line 1226, Address: 0x102c264 */
  lD1.b.b4 ^= bD3; /* Line 1227, Address: 0x102c270 */
  if (!lD1.b.b4) { /* Line 1228, Address: 0x102c284 */
    scrz_h_count ^= 16; /* Line 1229, Address: 0x102c290 */
    lD0.l -= lD2.l; /* Line 1230, Address: 0x102c2a4 */
    if ((long int)lD0.l < 0) { /* Line 1231, Address: 0x102c2b4 */
      scrflagz.b.h |= flagz; /* Line 1232, Address: 0x102c2c8 */
    } /* Line 1233, Address: 0x102c2e4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1236, Address: 0x102c2ec */
    }
  }


} /* Line 1241, Address: 0x102c30c */














void scrollwrtadva() { /* Line 1256, Address: 0x102c320 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1262, Address: 0x102c33c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1263, Address: 0x102c340 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1264, Address: 0x102c34c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1265, Address: 0x102c358 */
  pScrFlag = &scrflagb.b.h; /* Line 1266, Address: 0x102c360 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1267, Address: 0x102c368 */







} /* Line 1275, Address: 0x102c37c */












void scrollwrt() { /* Line 1288, Address: 0x102c3a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1297, Address: 0x102c3c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1298, Address: 0x102c3c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1299, Address: 0x102c3d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1300, Address: 0x102c3dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1301, Address: 0x102c3e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1302, Address: 0x102c3ec */

  VramBase = 16384; /* Line 1304, Address: 0x102c400 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1305, Address: 0x102c404 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1306, Address: 0x102c410 */
  pMapWk = (unsigned char*)mapwka; /* Line 1307, Address: 0x102c41c */
  pScrFlag = &scrflagaw.b.h; /* Line 1308, Address: 0x102c424 */

  if (*pScrFlag) { /* Line 1310, Address: 0x102c42c */
    if (*pScrFlag & 1) { /* Line 1311, Address: 0x102c438 */
      *pScrFlag &= 254; /* Line 1312, Address: 0x102c44c */

      lD4.l = -16; /* Line 1314, Address: 0x102c458 */
      wD5 = 65520; /* Line 1315, Address: 0x102c460 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1317, Address: 0x102c468 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1319, Address: 0x102c488 */
    }




    if (*pScrFlag & 2) { /* Line 1325, Address: 0x102c4b4 */
      *pScrFlag &= 253; /* Line 1326, Address: 0x102c4c8 */

      lD4.l = 224; /* Line 1328, Address: 0x102c4d4 */
      wD5 = 65520; /* Line 1329, Address: 0x102c4dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1330, Address: 0x102c4e4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1332, Address: 0x102c504 */
    }




    if (*pScrFlag & 4) { /* Line 1338, Address: 0x102c530 */
      *pScrFlag &= 251; /* Line 1339, Address: 0x102c544 */

      lD4.l = -16; /* Line 1341, Address: 0x102c550 */
      wD5 = 65520; /* Line 1342, Address: 0x102c558 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1343, Address: 0x102c560 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1345, Address: 0x102c580 */
    }




    if (*pScrFlag & 8) { /* Line 1351, Address: 0x102c5ac */
      *pScrFlag &= 247; /* Line 1352, Address: 0x102c5c0 */

      lD4.l = -16; /* Line 1354, Address: 0x102c5cc */
      wD5 = 320; /* Line 1355, Address: 0x102c5d4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1356, Address: 0x102c5dc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1358, Address: 0x102c5fc */
    }
  }






} /* Line 1367, Address: 0x102c628 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1384, Address: 0x102c650 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1395, Address: 0x102c67c */

  if (*pScrFlag & 1) { /* Line 1397, Address: 0x102c684 */
    *pScrFlag &= 254; /* Line 1398, Address: 0x102c69c */
  } /* Line 1399, Address: 0x102c6b0 */
  else {
    *pScrFlag &= 254; /* Line 1401, Address: 0x102c6b8 */

    if (*pScrFlag & 2) { /* Line 1403, Address: 0x102c6cc */
      *pScrFlag &= 253; /* Line 1404, Address: 0x102c6e4 */
      lD4.w.l = 224; /* Line 1405, Address: 0x102c6f8 */
    } /* Line 1406, Address: 0x102c700 */
    else {
      *pScrFlag &= 253; /* Line 1408, Address: 0x102c708 */
      goto label1; /* Line 1409, Address: 0x102c71c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1414, Address: 0x102c724 */
  wD0 &= 127; /* Line 1415, Address: 0x102c774 */
  wD0 = z32awrttbl[wD0 + 1]; /* Line 1416, Address: 0x102c77c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1422, Address: 0x102c79c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1423, Address: 0x102c7bc */
  if (wD0 != 0) { /* Line 1424, Address: 0x102c7e0 */
    wD5 = 65520; /* Line 1425, Address: 0x102c7ec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1426, Address: 0x102c7f4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1428, Address: 0x102c814 */



  } /* Line 1432, Address: 0x102c840 */
  else {

    wD5 = 0; /* Line 1435, Address: 0x102c848 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1436, Address: 0x102c84c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1440, Address: 0x102c86c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1447, Address: 0x102c898 */






    lD4.l = -16; /* Line 1454, Address: 0x102c8ac */
    wD5 = 65520; /* Line 1455, Address: 0x102c8b4 */
    if (*pScrFlag & 168) { /* Line 1456, Address: 0x102c8bc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1457, Address: 0x102c8d4 */
      wD5 = 320; /* Line 1458, Address: 0x102c8f4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1462, Address: 0x102c8fc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1464, Address: 0x102c92c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1465, Address: 0x102c938 */



    for (i = 0; i < 16; ++i) { /* Line 1469, Address: 0x102c948 */
      wD0 = z32awrttbl[WrtTblCnt++]; /* Line 1470, Address: 0x102c954 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1471, Address: 0x102c974 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1472, Address: 0x102c9a0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1473, Address: 0x102c9c0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1475, Address: 0x102c9e4 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1478, Address: 0x102ca08 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1480, Address: 0x102ca28 */
      }
      lD4.w.l += 16; /* Line 1482, Address: 0x102ca3c */
    } /* Line 1483, Address: 0x102ca48 */
    *pScrFlag = 0; /* Line 1484, Address: 0x102ca58 */
  }
} /* Line 1486, Address: 0x102ca60 */







void scrollwrtc() {} /* Line 1494, Address: 0x102ca90 */




void scrollwrtz() {} /* Line 1499, Address: 0x102caa0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1520, Address: 0x102cab0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1533, Address: 0x102cad8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1536, Address: 0x102caf8 */
    pTilePoint->x += 2; /* Line 1537, Address: 0x102cb0c */
    if (pTilePoint->x >= 64) { /* Line 1538, Address: 0x102cb20 */
      pTilePoint->x -= 64; /* Line 1539, Address: 0x102cb34 */
    }
    xOffs += 16; /* Line 1541, Address: 0x102cb48 */
  } while (--lpcnt >= 0); /* Line 1542, Address: 0x102cb54 */
} /* Line 1543, Address: 0x102cb68 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1547, Address: 0x102cb80 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1551, Address: 0x102cba8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1554, Address: 0x102cbc8 */
    pTilePoint->x += 2; /* Line 1555, Address: 0x102cbdc */
    if (pTilePoint->x >= 64) { /* Line 1556, Address: 0x102cbf0 */
      pTilePoint->x -= 64; /* Line 1557, Address: 0x102cc04 */
    }
    xOffs += 16; /* Line 1559, Address: 0x102cc18 */
  } while (--lpcnt >= 0); /* Line 1560, Address: 0x102cc24 */
} /* Line 1561, Address: 0x102cc38 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1580, Address: 0x102cc50 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1584, Address: 0x102cc78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1587, Address: 0x102cc98 */
    pTilePoint->y += 2; /* Line 1588, Address: 0x102ccac */
    if (pTilePoint->y >= 32) { /* Line 1589, Address: 0x102ccbc */
      pTilePoint->y -= 32; /* Line 1590, Address: 0x102ccd0 */
    }
    yOffs += 16; /* Line 1592, Address: 0x102cce0 */
  } while (--lpcnt >= 0); /* Line 1593, Address: 0x102ccec */
} /* Line 1594, Address: 0x102cd00 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1613, Address: 0x102cd10 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1619, Address: 0x102cd44 */

    base = 1; /* Line 1621, Address: 0x102cd54 */
  } /* Line 1622, Address: 0x102cd58 */
  else if (VramBase == 16384) { /* Line 1623, Address: 0x102cd60 */

    base = 0; /* Line 1625, Address: 0x102cd70 */
  }
  x = pTilePoint->x; /* Line 1627, Address: 0x102cd74 */
  y = pTilePoint->y; /* Line 1628, Address: 0x102cd7c */


  frip = BlkIndex & 6144; /* Line 1631, Address: 0x102cd84 */
  BlkIndex &= 1023; /* Line 1632, Address: 0x102cd8c */
  if (frip == 6144) { /* Line 1633, Address: 0x102cd98 */

    p0 = 3, p1 = 2; /* Line 1635, Address: 0x102cda4 */
    p2 = 1, p3 = 0; /* Line 1636, Address: 0x102cdac */
  } /* Line 1637, Address: 0x102cdb4 */
  else if (frip & 4096) { /* Line 1638, Address: 0x102cdbc */

    p0 = 2, p1 = 3; /* Line 1640, Address: 0x102cdc8 */
    p2 = 0, p3 = 1; /* Line 1641, Address: 0x102cdd0 */
  } /* Line 1642, Address: 0x102cdd8 */
  else if (frip & 2048) { /* Line 1643, Address: 0x102cde0 */

    p0 = 1, p1 = 0; /* Line 1645, Address: 0x102cdec */
    p2 = 3, p3 = 2; /* Line 1646, Address: 0x102cdf4 */
  } /* Line 1647, Address: 0x102cdfc */
  else {

    p0 = 0, p1 = 1; /* Line 1650, Address: 0x102ce04 */
    p2 = 2, p3 = 3; /* Line 1651, Address: 0x102ce0c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1654, Address: 0x102ce14 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1655, Address: 0x102ce58 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1656, Address: 0x102ce9c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1657, Address: 0x102cee0 */

} /* Line 1659, Address: 0x102cf24 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1677, Address: 0x102cf60 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1678, Address: 0x102cf80 */
} /* Line 1679, Address: 0x102cfa0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1681, Address: 0x102cfb0 */
  wH_posiw = 0; /* Line 1682, Address: 0x102cfd0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1683, Address: 0x102cfd4 */
} /* Line 1684, Address: 0x102cff4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1691, Address: 0x102d010 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1697, Address: 0x102d040 */
  yOffs += wV_posiw; /* Line 1698, Address: 0x102d050 */





  if ((short)xOffs < 0) /* Line 1704, Address: 0x102d060 */
    xOffs = 0; /* Line 1705, Address: 0x102d07c */
  if ((short)yOffs < 0) /* Line 1706, Address: 0x102d080 */
    yOffs = 0; /* Line 1707, Address: 0x102d09c */
  if ((short)xOffs >= 16384) /* Line 1708, Address: 0x102d0a0 */
    xOffs = 16383; /* Line 1709, Address: 0x102d0c0 */
  if ((short)yOffs >= 2048) /* Line 1710, Address: 0x102d0c8 */
    yOffs = 2047; /* Line 1711, Address: 0x102d0e8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1712, Address: 0x102d0f0 */
  if (i < 0) i = 0; /* Line 1713, Address: 0x102d138 */

  ScreenNo = pMapWk[i] & 127; /* Line 1715, Address: 0x102d144 */

  if (ScreenNo) { /* Line 1717, Address: 0x102d160 */




    xOffs &= 32767; /* Line 1722, Address: 0x102d168 */
    yOffs &= 32767; /* Line 1723, Address: 0x102d174 */


    xBlk = xOffs; /* Line 1726, Address: 0x102d180 */
    xBlk %= 256; /* Line 1727, Address: 0x102d188 */
    xBlk /= 16; /* Line 1728, Address: 0x102d1a8 */
    yBlk = yOffs; /* Line 1729, Address: 0x102d1c4 */
    yBlk %= 256; /* Line 1730, Address: 0x102d1cc */
    yBlk /= 16; /* Line 1731, Address: 0x102d1ec */

    lpw = pmapwk; /* Line 1733, Address: 0x102d208 */
    lpw += xBlk; /* Line 1734, Address: 0x102d210 */
    lpw += yBlk * 16; /* Line 1735, Address: 0x102d218 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1736, Address: 0x102d224 */
    *pIndex = *lpw; /* Line 1737, Address: 0x102d23c */

    return 1; /* Line 1739, Address: 0x102d24c */
  }

  *pIndex = 0; /* Line 1742, Address: 0x102d258 */
  return 0; /* Line 1743, Address: 0x102d260 */
} /* Line 1744, Address: 0x102d264 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1764, Address: 0x102d290 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1772, Address: 0x102d2b8 */
  if (ScreenNo) { /* Line 1773, Address: 0x102d31c */





    xBlk = xOffs; /* Line 1779, Address: 0x102d324 */
    xBlk %= 256; /* Line 1780, Address: 0x102d32c */
    xBlk /= 16; /* Line 1781, Address: 0x102d34c */
    yBlk = yOffs; /* Line 1782, Address: 0x102d368 */
    yBlk %= 256; /* Line 1783, Address: 0x102d370 */
    yBlk /= 16; /* Line 1784, Address: 0x102d390 */


    lpw = pmapwk; /* Line 1787, Address: 0x102d3ac */
    lpw += xBlk; /* Line 1788, Address: 0x102d3b4 */
    lpw += yBlk * 16; /* Line 1789, Address: 0x102d3bc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1790, Address: 0x102d3c8 */
    *ppBlockNo = lpw; /* Line 1791, Address: 0x102d3e0 */
    *pIndex = *lpw; /* Line 1792, Address: 0x102d3e8 */




    return 1; /* Line 1797, Address: 0x102d3f8 */
  }

  *pIndex = 0; /* Line 1800, Address: 0x102d404 */
  return 0; /* Line 1801, Address: 0x102d40c */
} /* Line 1802, Address: 0x102d410 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1816, Address: 0x102d430 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1823, Address: 0x102d44c */
  pMapWk = (unsigned char*)mapwka; /* Line 1824, Address: 0x102d450 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1825, Address: 0x102d458 */
    *pBlockIndex = BlockNo; /* Line 1826, Address: 0x102d47c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1827, Address: 0x102d488 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1828, Address: 0x102d4a0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1829, Address: 0x102d4b4 */
    }
  }


} /* Line 1834, Address: 0x102d4cc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1848, Address: 0x102d4f0 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1849, Address: 0x102d4fc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1850, Address: 0x102d528 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1851, Address: 0x102d574 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1852, Address: 0x102d5a0 */

          return 0; /* Line 1854, Address: 0x102d5ec */
        }
      }
    }
  }

  return 1; /* Line 1860, Address: 0x102d5f8 */
} /* Line 1861, Address: 0x102d5fc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1878, Address: 0x102d610 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1879, Address: 0x102d62c */

} /* Line 1881, Address: 0x102d648 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1883, Address: 0x102d660 */
  wH_posiw = 0; /* Line 1884, Address: 0x102d67c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1885, Address: 0x102d680 */

} /* Line 1887, Address: 0x102d69c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1889, Address: 0x102d6b0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1890, Address: 0x102d6c4 */

} /* Line 1892, Address: 0x102d6e0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1894, Address: 0x102d6f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1895, Address: 0x102d70c */

} /* Line 1897, Address: 0x102d728 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1899, Address: 0x102d740 */
  xOffs += wH_posiw; /* Line 1900, Address: 0x102d758 */
  yOffs += wV_posiw; /* Line 1901, Address: 0x102d768 */
  yOffs &= 240; /* Line 1902, Address: 0x102d778 */
  xOffs &= 496; /* Line 1903, Address: 0x102d784 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1905, Address: 0x102d790 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1906, Address: 0x102d7bc */


} /* Line 1909, Address: 0x102d7e8 */















void mapwrt() { /* Line 1925, Address: 0x102d800 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1930, Address: 0x102d818 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1931, Address: 0x102d824 */
  pMapWk = (unsigned char*)mapwka; /* Line 1932, Address: 0x102d830 */
  VramBase = 16384; /* Line 1933, Address: 0x102d838 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1934, Address: 0x102d83c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1938, Address: 0x102d854 */
  VramBase = 24576; /* Line 1939, Address: 0x102d85c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1940, Address: 0x102d860 */

} /* Line 1942, Address: 0x102d870 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1945, Address: 0x102d890 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1946, Address: 0x102d8a8 */
} /* Line 1947, Address: 0x102d8c8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1952, Address: 0x102d8e0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1956, Address: 0x102d900 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1959, Address: 0x102d91c */



    wD4 += 16; /* Line 1963, Address: 0x102d944 */
  } while ((short)--wD6 >= 0); /* Line 1964, Address: 0x102d950 */

} /* Line 1966, Address: 0x102d978 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1971, Address: 0x102d990 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1974, Address: 0x102d9ac */
  wD6 = 15; /* Line 1975, Address: 0x102d9b4 */



  do {
    wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1980, Address: 0x102d9bc */

    mapwrt_sub(&z32awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1982, Address: 0x102d9e0 */
    wD4 += 16; /* Line 1983, Address: 0x102da00 */
  } while ((short)--wD6 >= 0); /* Line 1984, Address: 0x102da08 */
} /* Line 1985, Address: 0x102da2c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2011, Address: 0x102da50 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2016, Address: 0x102da78 */
  wD0 = pWrttbl[wD0]; /* Line 2017, Address: 0x102da88 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2019, Address: 0x102daa4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2020, Address: 0x102dac8 */
  if (wD0) { /* Line 2021, Address: 0x102daf0 */
    wD5 = 65520; /* Line 2022, Address: 0x102dafc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2023, Address: 0x102db04 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2026, Address: 0x102db20 */



  } /* Line 2030, Address: 0x102db48 */
  else {

    wD5 = 0; /* Line 2033, Address: 0x102db50 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2034, Address: 0x102db54 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2038, Address: 0x102db70 */
  }





} /* Line 2045, Address: 0x102db98 */




void mapinit() { /* Line 2050, Address: 0x102dbc0 */





  mapset(); /* Line 2056, Address: 0x102dbc8 */


  colorset2(mapinittbl.colorno2); /* Line 2059, Address: 0x102dbd0 */
  colorset(mapinittbl.colorno2); /* Line 2060, Address: 0x102dbe4 */






  if (plflag != 0) { /* Line 2067, Address: 0x102dbf8 */
    enecginit(); /* Line 2068, Address: 0x102dc0c */
  }

  if (play_start & 2) { /* Line 2071, Address: 0x102dc14 */

    divdevset(); /* Line 2073, Address: 0x102dc2c */
  }


} /* Line 2077, Address: 0x102dc34 */









void mapset() {} /* Line 2087, Address: 0x102dc50 */
