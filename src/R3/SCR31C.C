#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3C.H"

static unsigned char z31cwrttbl[49] = {
  0, 0, 0, 0, 0, 0, 6, 6, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  2, 2, 6, 6, 4, 4, 4, 4, 2, 0,
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









































































void enecginit(void) {} /* Line 112, Address: 0x1027670 */



void divdevset() {} /* Line 116, Address: 0x1027680 */




















































sprite_status* main_chk(void) {
  if (main_play == 0) { /* Line 170, Address: 0x1027690 */
    return &actwk[0]; /* Line 171, Address: 0x10276a4 */
  }
  return &actwk[1]; /* Line 173, Address: 0x10276b4 */
} /* Line 174, Address: 0x10276bc */












void scr_set(void) { /* Line 187, Address: 0x10276d0 */





  unsigned short scr_dir_tbl[6] = { /* Line 193, Address: 0x10276dc */
    4, 0, 11927, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1027710 */

  i = 0; /* Line 200, Address: 0x1027758 */
  scrar_no = scr_dir_tbl[i++]; /* Line 201, Address: 0x102775c */
  scralim_left = scr_dir_tbl[i]; /* Line 202, Address: 0x1027778 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 203, Address: 0x102778c */
  scralim_right = scr_dir_tbl[i]; /* Line 204, Address: 0x10277a8 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 205, Address: 0x10277bc */
  scralim_up = scr_dir_tbl[i]; /* Line 206, Address: 0x10277d8 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 207, Address: 0x10277ec */
  scralim_down = scr_dir_tbl[i]; /* Line 208, Address: 0x1027808 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 209, Address: 0x102781c */

  scra_h_keep = scralim_left + 576; /* Line 211, Address: 0x1027838 */
  scra_h_count = 16; /* Line 212, Address: 0x102785c */
  scra_v_count = 16; /* Line 213, Address: 0x1027868 */

  scra_vline = scr_dir_tbl[i++]; /* Line 215, Address: 0x1027874 */
  scra_hline = 160; /* Line 216, Address: 0x1027890 */

  playposiset(); /* Line 218, Address: 0x102789c */
} /* Line 219, Address: 0x10278a4 */











void playposiset(void) { /* Line 231, Address: 0x10278c0 */
  unsigned short playpositbl[2] = { /* Line 232, Address: 0x10278d8 */
    96,
    1004
  };
  unsigned short endplpositbl[16] = { /* Line 236, Address: 0x10278f4 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 246, Address: 0x1027928 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 256, Address: 0x1027954 */
    playload(); /* Line 257, Address: 0x1027968 */
    xWk = actwk[0].xposi.w.h; /* Line 258, Address: 0x1027970 */
    yWk = actwk[0].yposi.w.h; /* Line 259, Address: 0x1027980 */

    if (yWk < 0) yWk = 0; /* Line 261, Address: 0x1027990 */

  } /* Line 263, Address: 0x10279a4 */
  else {

    if (demoflag.w < 0) { /* Line 266, Address: 0x10279ac */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 267, Address: 0x10279c4 */
    } /* Line 268, Address: 0x10279ec */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 271, Address: 0x10279f4 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 274, Address: 0x1027a14 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 275, Address: 0x1027a30 */
  }


  if ((unsigned short)xWk > 160) { /* Line 279, Address: 0x1027a44 */
    xWk -= 160; /* Line 280, Address: 0x1027a58 */
  } /* Line 281, Address: 0x1027a64 */
  else {
    xWk = 0; /* Line 283, Address: 0x1027a6c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 287, Address: 0x1027a70 */
    xWk = scralim_right; /* Line 288, Address: 0x1027a94 */
  }
  scra_h_posit.w.h = xWk; /* Line 290, Address: 0x1027aa4 */

  if ((unsigned short)yWk > 96) { /* Line 292, Address: 0x1027aac */
    yWk -= 96; /* Line 293, Address: 0x1027ac0 */
  } /* Line 294, Address: 0x1027acc */
  else {
    yWk = 0; /* Line 296, Address: 0x1027ad4 */
  }

  if (scralim_down < yWk) { /* Line 299, Address: 0x1027ad8 */
    yWk = scralim_down; /* Line 300, Address: 0x1027afc */
  }

  scra_v_posit.w.h = yWk; /* Line 303, Address: 0x1027b0c */

  scrbinit(xWk, yWk); /* Line 305, Address: 0x1027b14 */

  i = 0; /* Line 307, Address: 0x1027b24 */
  loopmapno = playmapnotbl[i++]; /* Line 308, Address: 0x1027b28 */
  loopmapno2 = playmapnotbl[i++]; /* Line 309, Address: 0x1027b40 */
  ballmapno = playmapnotbl[i++]; /* Line 310, Address: 0x1027b58 */
  ballmapno2 = playmapnotbl[i++]; /* Line 311, Address: 0x1027b70 */


} /* Line 314, Address: 0x1027b88 */











void scrbinit(short xWk, short yWk) { /* Line 326, Address: 0x1027bb0 */
  int i;
  short wD2;


  yWk = 536; /* Line 331, Address: 0x1027bc4 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 332, Address: 0x1027bcc */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 333, Address: 0x1027bf4 */
    yWk -= wD2 / 2; /* Line 334, Address: 0x1027c10 */
    if (yWk < 0) { /* Line 335, Address: 0x1027c44 */
      yWk = 0; /* Line 336, Address: 0x1027c58 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 340, Address: 0x1027c5c */
  scrb_v_posit.w.l = 0; /* Line 341, Address: 0x1027c68 */
  scrc_v_posit.w.h = yWk; /* Line 342, Address: 0x1027c70 */
  scrz_v_posit.w.h = yWk; /* Line 343, Address: 0x1027c7c */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 345, Address: 0x1027c88 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 346, Address: 0x1027cc0 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 347, Address: 0x1027d00 */


  for (i = 0; i < 14; ++i) { /* Line 350, Address: 0x1027d40 */
    ((int*)hscrollwork)[i] = 0; /* Line 351, Address: 0x1027d4c */
  } /* Line 352, Address: 0x1027d60 */

} /* Line 354, Address: 0x1027d70 */












void scroll(void) { /* Line 367, Address: 0x1027d90 */
  int LineSpdTbl[14] = { /* Line 368, Address: 0x1027db0 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  4096,  8192,
    12288, 16384, 24576,
    32768, 49152
  };
  unsigned char z31c_cnttbl[14] = { /* Line 375, Address: 0x1027de4 */
    1, 3, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 3, 3
  };
  unsigned short z31c_kawatbl[3] = { /* Line 378, Address: 0x1027e18 */
    56, 592, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 388, Address: 0x1027e3c */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 391, Address: 0x1027e4c */
  scrchk(); /* Line 392, Address: 0x1027e78 */
  scroll_h(); /* Line 393, Address: 0x1027e84 */
  scroll_v(); /* Line 394, Address: 0x1027e90 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 396, Address: 0x1027e9c */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 397, Address: 0x1027eac */


  scrollz_h(scra_hz << 4, 64); /* Line 400, Address: 0x1027ebc */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 401, Address: 0x1027ee0 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 402, Address: 0x1027f1c */

  lD0.w.l = 536; /* Line 404, Address: 0x1027f58 */
  wD1 = 1312; /* Line 405, Address: 0x1027f60 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 406, Address: 0x1027f68 */

    wD1 -= scra_v_posit.w.h; /* Line 408, Address: 0x1027f88 */
    wD1 >>= 1; /* Line 409, Address: 0x1027f9c */
    lD0.w.l -= wD1; /* Line 410, Address: 0x1027fa4 */
    if (lD0.w.l < 0) { /* Line 411, Address: 0x1027fb8 */
      lD0.w.l = 0; /* Line 412, Address: 0x1027fcc */
    }
  } /* Line 414, Address: 0x1027fd0 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 416, Address: 0x1027fd8 */
  }

  scrollb_v(lD0.w.l); /* Line 419, Address: 0x1027fec */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 420, Address: 0x1028000 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 421, Address: 0x1028010 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 422, Address: 0x1028020 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 424, Address: 0x1028030 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 425, Address: 0x102804c */
  scrflagz.b.h = 0; /* Line 426, Address: 0x1028068 */
  scrflagc.b.h = 0; /* Line 427, Address: 0x1028070 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 450, Address: 0x1028078 */
  for (i = 0; i < 14; ++i) { /* Line 451, Address: 0x1028080 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 452, Address: 0x102808c */
    ++pHscrWk; /* Line 453, Address: 0x10280a4 */
  } /* Line 454, Address: 0x10280a8 */
  wD1 = 0; /* Line 455, Address: 0x10280b8 */
  for ( ; i < 78; ++i) { /* Line 456, Address: 0x10280bc */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 457, Address: 0x10280c4 */
    pHscrWk->l += lD2.l; /* Line 458, Address: 0x10280e8 */
    ++pHscrWk; /* Line 459, Address: 0x10280f8 */
    ++wD1; /* Line 460, Address: 0x10280fc */
  } /* Line 461, Address: 0x1028104 */






  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 468, Address: 0x1028114 */
  lD2.l <<= 6; /* Line 469, Address: 0x102813c */
  lD2.l /= 28; /* Line 470, Address: 0x1028148 */
  lD2.l <<= 10; /* Line 471, Address: 0x1028168 */

  lD3.l = 0; /* Line 473, Address: 0x1028174 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 474, Address: 0x1028178 */

  pHScrollWork = &hscrollwork[162]; /* Line 476, Address: 0x1028184 */
  for (i = 0; i < 7; ++i) { /* Line 477, Address: 0x1028190 */
    lD0.w.l = -lD3.w.l; /* Line 478, Address: 0x102819c */
    *pHScrollWork-- = lD0.w.l; /* Line 479, Address: 0x10281b8 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 480, Address: 0x10281cc */
    lD3.l += lD2.l; /* Line 481, Address: 0x10281f0 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 482, Address: 0x1028200 */
  } /* Line 483, Address: 0x1028224 */

  pHScrollWork = &hscrollwork[163]; /* Line 485, Address: 0x1028234 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 486, Address: 0x1028240 */

  for (i = 0; i < 3; ++i) { /* Line 488, Address: 0x1028264 */
    *pHScrollWork++ = lD0.w.l; /* Line 489, Address: 0x1028270 */
  } /* Line 490, Address: 0x1028284 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 492, Address: 0x1028294 */

  for (i = 0; i < 4; ++i) { /* Line 494, Address: 0x10282b8 */
    *pHScrollWork++ = lD0.w.l; /* Line 495, Address: 0x10282c4 */
  } /* Line 496, Address: 0x10282d8 */














  pHscrWk = (int_union*)hscrollwork; /* Line 511, Address: 0x10282e8 */
  for (i = 13; i >= 0; --i) { /* Line 512, Address: 0x10282f0 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 513, Address: 0x10282fc */
    ++pHscrWk; /* Line 514, Address: 0x1028328 */
    for (j = z31c_cnttbl[i]; j >= 0; --j) { /* Line 515, Address: 0x102832c */
      *pHScrollWork++ = wD1; /* Line 516, Address: 0x1028340 */
    } /* Line 517, Address: 0x1028350 */
  } /* Line 518, Address: 0x102835c */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 521, Address: 0x1028368 */

  for (i = 0; i < 6; ++i) { /* Line 523, Address: 0x102838c */
    *pHScrollWork++ = lD0.w.l; /* Line 524, Address: 0x1028398 */
  } /* Line 525, Address: 0x10283ac */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 527, Address: 0x10283bc */

  for (i = 0; i < 4; ++i) { /* Line 529, Address: 0x10283e0 */
    *pHScrollWork++ = lD0.w.l; /* Line 530, Address: 0x10283ec */
  } /* Line 531, Address: 0x1028400 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 533, Address: 0x1028410 */

  for (i = 0; i < 8; ++i) { /* Line 535, Address: 0x1028434 */
    *pHScrollWork++ = lD0.w.l; /* Line 536, Address: 0x1028440 */
  } /* Line 537, Address: 0x1028454 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 539, Address: 0x1028464 */

  for (i = 0; i < 4; ++i) { /* Line 541, Address: 0x1028488 */
    *pHScrollWork++ = lD0.w.l; /* Line 542, Address: 0x1028494 */
  } /* Line 543, Address: 0x10284a8 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 546, Address: 0x10284b8 */
  lD2.l <<= 6; /* Line 547, Address: 0x10284f0 */
  lD2.l /= 44; /* Line 548, Address: 0x10284fc */
  lD2.l <<= 11; /* Line 549, Address: 0x102851c */
  lD3.w.l = scrb_h_posit.w.h; /* Line 550, Address: 0x1028528 */

  for (i = 0; i < 10; ++i) { /* Line 552, Address: 0x1028534 */
    *pHScrollWork++ = (unsigned short)-lD3.w.l; /* Line 553, Address: 0x1028540 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 554, Address: 0x102856c */
    lD3.l += lD2.l; /* Line 555, Address: 0x1028590 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 556, Address: 0x10285a0 */
  } /* Line 557, Address: 0x10285c4 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 559, Address: 0x10285d4 */

  for (i = 0; i < 8; ++i) { /* Line 561, Address: 0x10285f8 */
    *pHScrollWork++ = lD0.w.l; /* Line 562, Address: 0x1028604 */
  } /* Line 563, Address: 0x1028618 */

  pHScrollBuff = lphscrollbuff; /* Line 565, Address: 0x1028628 */
  pHScrollWork = &hscrollwork[156]; /* Line 566, Address: 0x1028634 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 567, Address: 0x1028640 */
  lD2.w.l = lD0.w.l; /* Line 568, Address: 0x102864c */
  wD4 = lD0.w.l; /* Line 569, Address: 0x1028654 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 570, Address: 0x102865c */
  wD3 = lD0.w.l >> 1; /* Line 571, Address: 0x1028680 */
  wD1 = 87; /* Line 572, Address: 0x1028698 */
  wD5 = 29; /* Line 573, Address: 0x10286a0 */
  if (wD3 <= wD1) { /* Line 574, Address: 0x10286a8 */

    wD1 -= wD3; /* Line 576, Address: 0x10286bc */
    if (wD1 >= 27) { /* Line 577, Address: 0x10286c4 */
      wD1 = 28; /* Line 578, Address: 0x10286d4 */
    }

    wD5 -= wD1; /* Line 581, Address: 0x10286dc */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 582, Address: 0x10286e8 */
    waterdirec.w += 64; /* Line 583, Address: 0x102870c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z31c_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 585, Address: 0x1028720 */


  } /* Line 588, Address: 0x102874c */
  else {
    wD1 -= wD3; /* Line 590, Address: 0x1028754 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 595, Address: 0x1028760 */
  pHScrollWork = &hscrollwork[28]; /* Line 596, Address: 0x1028774 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 597, Address: 0x1028780 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 598, Address: 0x1028794 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 601, Address: 0x10287ac */
    lD2.w.l = *pHScrollWork++; /* Line 602, Address: 0x10287c0 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 603, Address: 0x10287d4 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 604, Address: 0x10287e8 */
    lD0.w.l = lD2.w.l; /* Line 605, Address: 0x1028808 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 606, Address: 0x1028810 */
    if (wD3 <= wD4) { /* Line 607, Address: 0x1028830 */
      wD5 &= 255; /* Line 608, Address: 0x1028848 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 609, Address: 0x1028850 */
      wD3 += scra_h_posit.w.h; /* Line 610, Address: 0x102887c */
      wD3 = -(short)wD3; /* Line 611, Address: 0x1028890 */
      lD0.w.h = wD3; /* Line 612, Address: 0x10288ac */
    }

    pHScrollBuff->l = lD0.l; /* Line 615, Address: 0x10288b0 */
    ++pHScrollBuff; /* Line 616, Address: 0x10288bc */
    ++wD4; /* Line 617, Address: 0x10288c8 */
    ++wD5; /* Line 618, Address: 0x10288d4 */
  } while ((short)--wD1 >= 0); /* Line 619, Address: 0x10288dc */

} /* Line 621, Address: 0x1028900 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 626, Address: 0x1028930 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 633, Address: 0x1028964 */
  pA1 = *ppA1; /* Line 634, Address: 0x1028984 */
  pA2 = *ppA2; /* Line 635, Address: 0x102898c */

  if (*pA3 <= *pwD4) goto label6; /* Line 637, Address: 0x1028994 */



label1:
  *pwD2 &= 7; /* Line 642, Address: 0x10289b8 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 643, Address: 0x10289cc */

  lD0.w.l = *pA2++; /* Line 645, Address: 0x10289f8 */
  i = 8 - *pwD2; /* Line 646, Address: 0x1028a08 */
  goto label4; /* Line 647, Address: 0x1028a1c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 650, Address: 0x1028a24 */


  if (*pA3 <= *pwD4) goto label7; /* Line 653, Address: 0x1028a40 */



label3:
  lD0.w.l = *pA2++; /* Line 658, Address: 0x1028a64 */
  *pwD4 += 8; /* Line 659, Address: 0x1028a74 */


  i = 8; /* Line 662, Address: 0x1028a88 */
label4:
  for ( ; i > 0; --i) { /* Line 664, Address: 0x1028a8c */


    pA1->l = lD0.l; /* Line 667, Address: 0x1028a94 */
    ++pA1; /* Line 668, Address: 0x1028a9c */
  } /* Line 669, Address: 0x1028aa0 */
  if ((short)--wD1 >= 0) goto label2; /* Line 670, Address: 0x1028ab0 */



label5:
  *ppA1 = pA1; /* Line 675, Address: 0x1028ad8 */
  *ppA2 = pA2; /* Line 676, Address: 0x1028ae0 */
  return; /* Line 677, Address: 0x1028ae8 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 681, Address: 0x1028af0 */
  if ((short)wD3 > 0) goto label8; /* Line 682, Address: 0x1028b20 */


  if (*pA3 > *pwD4) goto label1; /* Line 685, Address: 0x1028b38 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 688, Address: 0x1028b5c */
  if ((short)wD3 > 0) goto label8; /* Line 689, Address: 0x1028b8c */
  goto label1; /* Line 690, Address: 0x1028ba4 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 698, Address: 0x1028bac */
  if ((short)wD3 <= 0) goto label3; /* Line 699, Address: 0x1028bdc */



label8:
  --wD3; /* Line 704, Address: 0x1028bf4 */
  wD6 = wD3; /* Line 705, Address: 0x1028bfc */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 706, Address: 0x1028c00 */

  do {
    *pwD2 &= 255; /* Line 709, Address: 0x1028c18 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 710, Address: 0x1028c2c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 711, Address: 0x1028c58 */
    lD0.w.l = -lD0.w.l; /* Line 712, Address: 0x1028c6c */
    pA1->w.h = lD0.w.h; /* Line 713, Address: 0x1028c88 */
    pA1->w.l = lD0.w.l; /* Line 714, Address: 0x1028c90 */
    ++pA1; /* Line 715, Address: 0x1028c98 */
    ++*pwD4; /* Line 716, Address: 0x1028c9c */
    ++*pwD2; /* Line 717, Address: 0x1028cb0 */
  } while ((short)--wD3 >= 0); /* Line 718, Address: 0x1028cc4 */

  wD6 >>= 3; /* Line 720, Address: 0x1028ce8 */

  do {
    lD0.w.l = *pA2++; /* Line 723, Address: 0x1028cf0 */
    --wD1; /* Line 724, Address: 0x1028d00 */
  } while ((short)--wD6 >= 0); /* Line 725, Address: 0x1028d0c */
  goto label2; /* Line 726, Address: 0x1028d30 */
} /* Line 727, Address: 0x1028d38 */















void scroll_h(void) { /* Line 743, Address: 0x1028d60 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 746, Address: 0x1028d6c */
  scrh_move(); /* Line 747, Address: 0x1028d78 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 748, Address: 0x1028d80 */
    scra_h_count ^= 16; /* Line 749, Address: 0x1028db4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 750, Address: 0x1028dc8 */
      scrflaga.b.h |= 4; /* Line 751, Address: 0x1028df4 */
    } /* Line 752, Address: 0x1028e08 */
    else {

      scrflaga.b.h |= 8; /* Line 755, Address: 0x1028e10 */
    }
  }


} /* Line 760, Address: 0x1028e24 */

void scrh_move(void) { /* Line 762, Address: 0x1028e40 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 765, Address: 0x1028e4c */
  wD0 -= scra_h_posit.w.h; /* Line 766, Address: 0x1028e58 */
  wD0 -= scra_hline; /* Line 767, Address: 0x1028e6c */
  if (wD0 == 0) { /* Line 768, Address: 0x1028e80 */

    scra_hz = 0; /* Line 770, Address: 0x1028e8c */
  } /* Line 771, Address: 0x1028e94 */
  else if ((short)wD0 < 0) { /* Line 772, Address: 0x1028e9c */
    left_check(wD0); /* Line 773, Address: 0x1028eb4 */
  } /* Line 774, Address: 0x1028ec0 */
  else {
    right_check(wD0); /* Line 776, Address: 0x1028ec8 */
  }

} /* Line 779, Address: 0x1028ed4 */


void right_check(unsigned short wD0) { /* Line 782, Address: 0x1028ef0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 785, Address: 0x1028efc */
    wD0 = 16; /* Line 786, Address: 0x1028f1c */
  }

  wD0 += scra_h_posit.w.h; /* Line 789, Address: 0x1028f24 */
  if (scralim_right < (short)wD0) { /* Line 790, Address: 0x1028f3c */
    wD0 = scralim_right; /* Line 791, Address: 0x1028f6c */
  }

  wD1 = wD0; /* Line 794, Address: 0x1028f78 */
  wD1 -= scra_h_posit.w.h; /* Line 795, Address: 0x1028f80 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 796, Address: 0x1028f94 */
  scra_h_posit.w.h = wD0; /* Line 797, Address: 0x1028fc4 */
  scra_hz = wD1; /* Line 798, Address: 0x1028fd0 */

} /* Line 800, Address: 0x1028fd8 */


void left_check(unsigned short wD0) { /* Line 803, Address: 0x1028ff0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 806, Address: 0x1028ffc */
    wD0 = -16; /* Line 807, Address: 0x102901c */
  }

  wD0 += scra_h_posit.w.h; /* Line 810, Address: 0x1029024 */
  if (scralim_left > (short)wD0) { /* Line 811, Address: 0x102903c */
    wD0 = scralim_left; /* Line 812, Address: 0x102906c */
  }

  wD1 = wD0; /* Line 815, Address: 0x1029078 */
  wD1 -= scra_h_posit.w.h; /* Line 816, Address: 0x1029080 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 817, Address: 0x1029094 */
  scra_h_posit.w.h = wD0; /* Line 818, Address: 0x10290c4 */
  scra_hz = wD1; /* Line 819, Address: 0x10290d0 */

} /* Line 821, Address: 0x10290d8 */


















void scroll_v(void) { /* Line 840, Address: 0x10290f0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 843, Address: 0x10290fc */
  if (actwk[0].cddat & 4) { /* Line 844, Address: 0x1029128 */
    wD0 -= 5; /* Line 845, Address: 0x1029140 */
  }

  if (actwk[0].cddat & 2) { /* Line 848, Address: 0x1029148 */
    wD0 += 32; /* Line 849, Address: 0x1029160 */
    if ((unsigned short)scra_vline > wD0) { /* Line 850, Address: 0x1029168 */
      wD0 -= scra_vline; /* Line 851, Address: 0x1029188 */
      sv_move_main2(wD0); /* Line 852, Address: 0x102919c */
      return; /* Line 853, Address: 0x10291a8 */
    }
    wD0 -= scra_vline; /* Line 855, Address: 0x10291b0 */
    if (wD0 >= 64) { /* Line 856, Address: 0x10291c4 */
      wD0 -= 64; /* Line 857, Address: 0x10291d4 */
      sv_move_main2(wD0); /* Line 858, Address: 0x10291dc */
      return; /* Line 859, Address: 0x10291e8 */
    }
    wD0 -= 64; /* Line 861, Address: 0x10291f0 */
    if (limmoveflag == 0) goto label1; /* Line 862, Address: 0x10291f8 */
    sv_move_sub2(); /* Line 863, Address: 0x102920c */
    return; /* Line 864, Address: 0x1029214 */
  }




  wD0 -= scra_vline; /* Line 870, Address: 0x102921c */
  if (wD0) { /* Line 871, Address: 0x1029230 */
    sv_move_main(wD0); /* Line 872, Address: 0x1029238 */
    return; /* Line 873, Address: 0x1029244 */
  }
  if (limmoveflag == 0) { /* Line 875, Address: 0x102924c */
    sv_move_sub2(); /* Line 876, Address: 0x1029260 */
    return; /* Line 877, Address: 0x1029268 */
  }


label1:
  scra_vz = 0; /* Line 882, Address: 0x1029270 */

} /* Line 884, Address: 0x1029278 */





void sv_move_main(unsigned short wD0) { /* Line 890, Address: 0x1029290 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 893, Address: 0x10292a0 */
    sv_move_main1(wD0); /* Line 894, Address: 0x10292bc */
  } /* Line 895, Address: 0x10292c8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 898, Address: 0x10292d0 */
    if ((short)wD1 < 0) { /* Line 899, Address: 0x10292dc */
      wD1 = -(short)wD1; /* Line 900, Address: 0x10292f4 */
    }

    if (wD1 >= 2048) { /* Line 903, Address: 0x1029310 */
      sv_move_main2(wD0); /* Line 904, Address: 0x1029320 */
    } /* Line 905, Address: 0x102932c */
    else {
      if ((short)wD0 > 6) { /* Line 907, Address: 0x1029334 */
        sv_move_plus(1536); /* Line 908, Address: 0x1029354 */
      } /* Line 909, Address: 0x1029360 */
      else if ((short)wD0 < -6) { /* Line 910, Address: 0x1029368 */
        sv_move_minus(1536); /* Line 911, Address: 0x1029388 */
      } /* Line 912, Address: 0x1029394 */
      else {
        sv_move_sub(wD0); /* Line 914, Address: 0x102939c */
      }
    }
  }
} /* Line 918, Address: 0x10293a8 */



void sv_move_main1(unsigned short wD0) { /* Line 922, Address: 0x10293c0 */

  if ((short)wD0 > 2) { /* Line 924, Address: 0x10293cc */
    sv_move_plus(512); /* Line 925, Address: 0x10293ec */
  } /* Line 926, Address: 0x10293f8 */
  else if ((short)wD0 < -2) { /* Line 927, Address: 0x1029400 */
    sv_move_minus(512); /* Line 928, Address: 0x1029420 */
  } /* Line 929, Address: 0x102942c */
  else {
    sv_move_sub(wD0); /* Line 931, Address: 0x1029434 */
  }

} /* Line 934, Address: 0x1029440 */


void sv_move_main2(unsigned short wD0) { /* Line 937, Address: 0x1029450 */

  if ((short)wD0 > 16) { /* Line 939, Address: 0x102945c */
    sv_move_plus(4096); /* Line 940, Address: 0x102947c */
  } /* Line 941, Address: 0x1029488 */
  else if ((short)wD0 < -16) { /* Line 942, Address: 0x1029490 */
    sv_move_minus(4096); /* Line 943, Address: 0x10294b0 */
  } /* Line 944, Address: 0x10294bc */
  else {
    sv_move_sub(wD0); /* Line 946, Address: 0x10294c4 */
  }

} /* Line 949, Address: 0x10294d0 */


void sv_move_sub2(void) { /* Line 952, Address: 0x10294e0 */
  limmoveflag = 0; /* Line 953, Address: 0x10294e8 */
  sv_move_sub(0); /* Line 954, Address: 0x10294f0 */
} /* Line 955, Address: 0x10294fc */


void sv_move_sub(unsigned short wD0) { /* Line 958, Address: 0x1029510 */
  int_union lD1;

  lD1.w.h = 0; /* Line 961, Address: 0x102951c */
  lD1.w.l = wD0; /* Line 962, Address: 0x1029520 */
  lD1.l += scra_v_posit.w.h; /* Line 963, Address: 0x1029528 */
  if ((short)wD0 > 0) { /* Line 964, Address: 0x1029544 */
    scrv_down_ch(lD1); /* Line 965, Address: 0x1029560 */
  } /* Line 966, Address: 0x102956c */
  else {
    scrv_up_ch(lD1); /* Line 968, Address: 0x1029574 */
  }

} /* Line 971, Address: 0x1029580 */




void sv_move_minus(unsigned short wD1) { /* Line 976, Address: 0x1029590 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 980, Address: 0x10295a0 */
  lD1.l <<= 8; /* Line 981, Address: 0x10295bc */
  lD1.l += scra_v_posit.l; /* Line 982, Address: 0x10295c8 */

  wk = lD1.w.h; /* Line 984, Address: 0x10295dc */
  lD1.w.h = lD1.w.l; /* Line 985, Address: 0x10295e4 */
  lD1.w.l = wk; /* Line 986, Address: 0x10295ec */
  scrv_up_ch(lD1); /* Line 987, Address: 0x10295f0 */
} /* Line 988, Address: 0x10295fc */



void scrv_up_ch(int_union lD1) { /* Line 992, Address: 0x1029610 */
  if (scralim_up >= lD1.w.l) { /* Line 993, Address: 0x102961c */
    if (lD1.w.l < -255) { /* Line 994, Address: 0x1029644 */
      lD1.w.l &= 2047; /* Line 995, Address: 0x102965c */
      actwk[0].yposi.w.h &= 32767; /* Line 996, Address: 0x1029668 */
      scra_v_posit.w.h &= 2047; /* Line 997, Address: 0x102967c */
      scrb_v_posit.w.h &= 1023; /* Line 998, Address: 0x1029690 */
    } /* Line 999, Address: 0x10296a4 */
    else {

      lD1.w.l = scralim_up; /* Line 1002, Address: 0x10296ac */
    }
  }
  scrv_move(lD1); /* Line 1005, Address: 0x10296b8 */

} /* Line 1007, Address: 0x10296c4 */





void sv_move_plus(unsigned short wD1) { /* Line 1013, Address: 0x10296e0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1017, Address: 0x10296f0 */
  lD1.w.l = wD1; /* Line 1018, Address: 0x10296f4 */
  lD1.l <<= 8; /* Line 1019, Address: 0x10296fc */
  lD1.l += scra_v_posit.l; /* Line 1020, Address: 0x1029708 */

  wk = lD1.w.h; /* Line 1022, Address: 0x102971c */
  lD1.w.h = lD1.w.l; /* Line 1023, Address: 0x1029724 */
  lD1.w.l = wk; /* Line 1024, Address: 0x102972c */

  scrv_down_ch(lD1); /* Line 1026, Address: 0x1029730 */

} /* Line 1028, Address: 0x102973c */



void scrv_down_ch(int_union lD1) { /* Line 1032, Address: 0x1029750 */
  if (scralim_down <= lD1.w.l) { /* Line 1033, Address: 0x102975c */
    lD1.w.l -= 2048; /* Line 1034, Address: 0x1029784 */
    if (lD1.w.l > 0) { /* Line 1035, Address: 0x1029790 */
      actwk[0].yposi.w.h &= 2047; /* Line 1036, Address: 0x10297a4 */
      scra_v_posit.w.h -= 2048; /* Line 1037, Address: 0x10297b8 */
      scrb_v_posit.w.h &= 1023; /* Line 1038, Address: 0x10297cc */
    } /* Line 1039, Address: 0x10297e0 */
    else {
      lD1.w.l = scralim_down; /* Line 1041, Address: 0x10297e8 */
    }
  }
  scrv_move(lD1); /* Line 1044, Address: 0x10297f4 */

} /* Line 1046, Address: 0x1029800 */


void scrv_move(int_union lD1) { /* Line 1049, Address: 0x1029810 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1052, Address: 0x1029820 */

  wk = lD1.w.h; /* Line 1054, Address: 0x102982c */
  lD1.w.h = lD1.w.l; /* Line 1055, Address: 0x1029834 */
  lD1.w.l = wk; /* Line 1056, Address: 0x102983c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1058, Address: 0x1029840 */
  scra_v_posit.l = lD1.l; /* Line 1059, Address: 0x1029868 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1062, Address: 0x1029874 */
    scra_v_count ^= 16; /* Line 1063, Address: 0x10298a8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1064, Address: 0x10298bc */

      scrflaga.b.h |= 2; /* Line 1066, Address: 0x10298e8 */
    } /* Line 1067, Address: 0x10298fc */
    else {
      scrflaga.b.h |= 1; /* Line 1069, Address: 0x1029904 */
    }
  }


} /* Line 1074, Address: 0x1029918 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1078, Address: 0x1029930 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1081, Address: 0x102993c */
  lD0.l += lD4.l; /* Line 1082, Address: 0x102994c */
  scrb_h_posit.l = lD0.l; /* Line 1083, Address: 0x102995c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1085, Address: 0x1029968 */

    scrb_h_count ^= 16; /* Line 1087, Address: 0x102999c */
    lD0.l -= lD2.l; /* Line 1088, Address: 0x10299b0 */
    if ((long int)lD0.l < 0) { /* Line 1089, Address: 0x10299c0 */
      scrflagb.b.h |= 4; /* Line 1090, Address: 0x10299d4 */
    } /* Line 1091, Address: 0x10299e8 */
    else {

      scrflagb.b.h |= 8; /* Line 1094, Address: 0x10299f0 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1099, Address: 0x1029a04 */
  lD0.l += lD5.l; /* Line 1100, Address: 0x1029a14 */
  scrb_h_posit.l = lD0.l; /* Line 1101, Address: 0x1029a24 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1103, Address: 0x1029a30 */

    scrb_v_count ^= 16; /* Line 1105, Address: 0x1029a64 */
    lD0.l -= lD3.l; /* Line 1106, Address: 0x1029a78 */
    if ((long int)lD0.l < 0) { /* Line 1107, Address: 0x1029a88 */
      scrflagb.b.h |= 1; /* Line 1108, Address: 0x1029a9c */
    } /* Line 1109, Address: 0x1029ab0 */
    else {

      scrflagb.b.h |= 2; /* Line 1112, Address: 0x1029ab8 */
    }
  }


} /* Line 1117, Address: 0x1029acc */






void scrollb_v(unsigned short wD0) { /* Line 1124, Address: 0x1029ae0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1127, Address: 0x1029aec */
  scrb_v_posit.w.h = wD0; /* Line 1128, Address: 0x1029af8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1130, Address: 0x1029b04 */
    scrb_v_count ^= 16; /* Line 1131, Address: 0x1029b30 */
    if ((short)wD3 > (short)wD0) { /* Line 1132, Address: 0x1029b44 */
      scrflagb.b.h |= 1; /* Line 1133, Address: 0x1029b74 */
    } /* Line 1134, Address: 0x1029b88 */
    else {

      scrflagb.b.h |= 2; /* Line 1137, Address: 0x1029b90 */
    }
  }


} /* Line 1142, Address: 0x1029ba4 */



void scrollb_h(int lD4, int flagb) { /* Line 1146, Address: 0x1029bc0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1150, Address: 0x1029bd0 */
  lD0.l = lD2.l + lD4; /* Line 1151, Address: 0x1029bdc */
  scrb_h_posit.l = lD0.l; /* Line 1152, Address: 0x1029bec */

  lD1.w.h = lD0.w.l; /* Line 1154, Address: 0x1029bf8 */
  lD1.w.l = lD0.w.h; /* Line 1155, Address: 0x1029c00 */
  lD1.w.l &= 16; /* Line 1156, Address: 0x1029c08 */

  bD3 = scrb_h_count; /* Line 1158, Address: 0x1029c14 */
  lD1.b.b4 ^= bD3; /* Line 1159, Address: 0x1029c20 */
  if (!lD1.b.b4) { /* Line 1160, Address: 0x1029c34 */
    scrb_h_count ^= 16; /* Line 1161, Address: 0x1029c40 */
    lD0.l -= lD2.l; /* Line 1162, Address: 0x1029c54 */
    if ((long int)lD0.l < 0) { /* Line 1163, Address: 0x1029c64 */
      scrflagb.b.h |= flagb; /* Line 1164, Address: 0x1029c78 */
    } /* Line 1165, Address: 0x1029c94 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1168, Address: 0x1029c9c */
    }
  }


} /* Line 1173, Address: 0x1029cbc */



void scrollc_h(int lD4, int flagc) { /* Line 1177, Address: 0x1029cd0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1181, Address: 0x1029ce0 */
  lD0.l = lD2.l + lD4; /* Line 1182, Address: 0x1029cec */
  scrc_h_posit.l = lD0.l; /* Line 1183, Address: 0x1029cfc */

  lD1.w.h = lD0.w.l; /* Line 1185, Address: 0x1029d08 */
  lD1.w.l = lD0.w.h; /* Line 1186, Address: 0x1029d10 */
  lD1.w.l &= 16; /* Line 1187, Address: 0x1029d18 */

  bD3 = scrc_h_count; /* Line 1189, Address: 0x1029d24 */
  lD1.b.b4 ^= bD3; /* Line 1190, Address: 0x1029d30 */
  if (!lD1.b.b4) { /* Line 1191, Address: 0x1029d44 */
    scrc_h_count ^= 16; /* Line 1192, Address: 0x1029d50 */
    lD0.l -= lD2.l; /* Line 1193, Address: 0x1029d64 */
    if ((long int)lD0.l < 0) { /* Line 1194, Address: 0x1029d74 */
      scrflagc.b.h |= flagc; /* Line 1195, Address: 0x1029d88 */
    } /* Line 1196, Address: 0x1029da4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1199, Address: 0x1029dac */
    }
  }


} /* Line 1204, Address: 0x1029dcc */











void scrollz_h(int lD4, int flagz) { /* Line 1216, Address: 0x1029de0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1220, Address: 0x1029df0 */
  lD0.l = lD2.l + lD4; /* Line 1221, Address: 0x1029dfc */
  scrz_h_posit.l = lD0.l; /* Line 1222, Address: 0x1029e0c */

  lD1.w.h = lD0.w.l; /* Line 1224, Address: 0x1029e18 */
  lD1.w.l = lD0.w.h; /* Line 1225, Address: 0x1029e20 */
  lD1.w.l &= 16; /* Line 1226, Address: 0x1029e28 */

  bD3 = scrz_h_count; /* Line 1228, Address: 0x1029e34 */
  lD1.b.b4 ^= bD3; /* Line 1229, Address: 0x1029e40 */
  if (!lD1.b.b4) { /* Line 1230, Address: 0x1029e54 */
    scrz_h_count ^= 16; /* Line 1231, Address: 0x1029e60 */
    lD0.l -= lD2.l; /* Line 1232, Address: 0x1029e74 */
    if ((long int)lD0.l < 0) { /* Line 1233, Address: 0x1029e84 */
      scrflagz.b.h |= flagz; /* Line 1234, Address: 0x1029e98 */
    } /* Line 1235, Address: 0x1029eb4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1238, Address: 0x1029ebc */
    }
  }


} /* Line 1243, Address: 0x1029edc */














void scrollwrtadva(void) { /* Line 1258, Address: 0x1029ef0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1264, Address: 0x1029f0c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1265, Address: 0x1029f10 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1266, Address: 0x1029f1c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1267, Address: 0x1029f28 */
  pScrFlag = &scrflagb.b.h; /* Line 1268, Address: 0x1029f30 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1269, Address: 0x1029f38 */







} /* Line 1277, Address: 0x1029f4c */












void scrollwrt(void) { /* Line 1290, Address: 0x1029f70 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1299, Address: 0x1029f90 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1300, Address: 0x1029f94 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1301, Address: 0x1029fa0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1302, Address: 0x1029fac */
  pScrFlag = &scrflagbw.b.h; /* Line 1303, Address: 0x1029fb4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1304, Address: 0x1029fbc */

  VramBase = 16384; /* Line 1306, Address: 0x1029fd0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1307, Address: 0x1029fd4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1308, Address: 0x1029fe0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1309, Address: 0x1029fec */
  pScrFlag = &scrflagaw.b.h; /* Line 1310, Address: 0x1029ff4 */

  if (*pScrFlag) { /* Line 1312, Address: 0x1029ffc */
    if (*pScrFlag & 1) { /* Line 1313, Address: 0x102a008 */
      *pScrFlag &= 254; /* Line 1314, Address: 0x102a01c */

      lD4.l = -16; /* Line 1316, Address: 0x102a028 */
      wD5 = 65520; /* Line 1317, Address: 0x102a030 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1319, Address: 0x102a038 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1321, Address: 0x102a058 */
    }




    if (*pScrFlag & 2) { /* Line 1327, Address: 0x102a084 */
      *pScrFlag &= 253; /* Line 1328, Address: 0x102a098 */

      lD4.l = 224; /* Line 1330, Address: 0x102a0a4 */
      wD5 = 65520; /* Line 1331, Address: 0x102a0ac */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1332, Address: 0x102a0b4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1334, Address: 0x102a0d4 */
    }




    if (*pScrFlag & 4) { /* Line 1340, Address: 0x102a100 */
      *pScrFlag &= 251; /* Line 1341, Address: 0x102a114 */

      lD4.l = -16; /* Line 1343, Address: 0x102a120 */
      wD5 = 65520; /* Line 1344, Address: 0x102a128 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1345, Address: 0x102a130 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1347, Address: 0x102a150 */
    }




    if (*pScrFlag & 8) { /* Line 1353, Address: 0x102a17c */
      *pScrFlag &= 247; /* Line 1354, Address: 0x102a190 */

      lD4.l = -16; /* Line 1356, Address: 0x102a19c */
      wD5 = 320; /* Line 1357, Address: 0x102a1a4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1358, Address: 0x102a1ac */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1360, Address: 0x102a1cc */
    }
  }






} /* Line 1369, Address: 0x102a1f8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1386, Address: 0x102a220 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1397, Address: 0x102a24c */

  if (*pScrFlag & 1) { /* Line 1399, Address: 0x102a254 */
    *pScrFlag &= 254; /* Line 1400, Address: 0x102a26c */
  } /* Line 1401, Address: 0x102a280 */
  else {
    *pScrFlag &= 254; /* Line 1403, Address: 0x102a288 */

    if (*pScrFlag & 2) { /* Line 1405, Address: 0x102a29c */
      *pScrFlag &= 253; /* Line 1406, Address: 0x102a2b4 */
      lD4.w.l = 224; /* Line 1407, Address: 0x102a2c8 */
    } /* Line 1408, Address: 0x102a2d0 */
    else {
      *pScrFlag &= 253; /* Line 1410, Address: 0x102a2d8 */
      goto label1; /* Line 1411, Address: 0x102a2ec */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1416, Address: 0x102a2f4 */
  wD0 &= 127; /* Line 1417, Address: 0x102a344 */
  wD0 = z31cwrttbl[wD0 + 1]; /* Line 1418, Address: 0x102a34c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1424, Address: 0x102a36c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1425, Address: 0x102a38c */
  if (wD0 != 0) { /* Line 1426, Address: 0x102a3b0 */
    wD5 = 65520; /* Line 1427, Address: 0x102a3bc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1428, Address: 0x102a3c4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1430, Address: 0x102a3e4 */



  } /* Line 1434, Address: 0x102a410 */
  else {

    wD5 = 0; /* Line 1437, Address: 0x102a418 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1438, Address: 0x102a41c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1442, Address: 0x102a43c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1449, Address: 0x102a468 */






    lD4.l = -16; /* Line 1456, Address: 0x102a47c */
    wD5 = 65520; /* Line 1457, Address: 0x102a484 */
    if (*pScrFlag & 168) { /* Line 1458, Address: 0x102a48c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1459, Address: 0x102a4a4 */
      wD5 = 320; /* Line 1460, Address: 0x102a4c4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1464, Address: 0x102a4cc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1466, Address: 0x102a4fc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1467, Address: 0x102a508 */



    for (i = 0; i < 16; ++i) { /* Line 1471, Address: 0x102a518 */
      wD0 = z31cwrttbl[WrtTblCnt++]; /* Line 1472, Address: 0x102a524 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1473, Address: 0x102a544 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1474, Address: 0x102a570 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1475, Address: 0x102a590 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1477, Address: 0x102a5b4 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1480, Address: 0x102a5d8 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1482, Address: 0x102a5f8 */
      }
      lD4.w.l += 16; /* Line 1484, Address: 0x102a60c */
    } /* Line 1485, Address: 0x102a618 */
    *pScrFlag = 0; /* Line 1486, Address: 0x102a628 */
  }
} /* Line 1488, Address: 0x102a630 */







void scrollwrtc(void) {} /* Line 1496, Address: 0x102a660 */




void scrollwrtz(void) {} /* Line 1501, Address: 0x102a670 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1522, Address: 0x102a680 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1535, Address: 0x102a6a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1538, Address: 0x102a6c8 */
    pTilePoint->x += 2; /* Line 1539, Address: 0x102a6dc */
    if (pTilePoint->x >= 64) { /* Line 1540, Address: 0x102a6f0 */
      pTilePoint->x -= 64; /* Line 1541, Address: 0x102a704 */
    }
    xOffs += 16; /* Line 1543, Address: 0x102a718 */
  } while (--lpcnt >= 0); /* Line 1544, Address: 0x102a724 */
} /* Line 1545, Address: 0x102a738 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1549, Address: 0x102a750 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1553, Address: 0x102a778 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1556, Address: 0x102a798 */
    pTilePoint->x += 2; /* Line 1557, Address: 0x102a7ac */
    if (pTilePoint->x >= 64) { /* Line 1558, Address: 0x102a7c0 */
      pTilePoint->x -= 64; /* Line 1559, Address: 0x102a7d4 */
    }
    xOffs += 16; /* Line 1561, Address: 0x102a7e8 */
  } while (--lpcnt >= 0); /* Line 1562, Address: 0x102a7f4 */
} /* Line 1563, Address: 0x102a808 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1582, Address: 0x102a820 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1586, Address: 0x102a848 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1589, Address: 0x102a868 */
    pTilePoint->y += 2; /* Line 1590, Address: 0x102a87c */
    if (pTilePoint->y >= 32) { /* Line 1591, Address: 0x102a88c */
      pTilePoint->y -= 32; /* Line 1592, Address: 0x102a8a0 */
    }
    yOffs += 16; /* Line 1594, Address: 0x102a8b0 */
  } while (--lpcnt >= 0); /* Line 1595, Address: 0x102a8bc */
} /* Line 1596, Address: 0x102a8d0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1615, Address: 0x102a8e0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1621, Address: 0x102a914 */

    base = 1; /* Line 1623, Address: 0x102a924 */
  } /* Line 1624, Address: 0x102a928 */
  else if (VramBase == 16384) { /* Line 1625, Address: 0x102a930 */

    base = 0; /* Line 1627, Address: 0x102a940 */
  }
  x = pTilePoint->x; /* Line 1629, Address: 0x102a944 */
  y = pTilePoint->y; /* Line 1630, Address: 0x102a94c */


  frip = BlkIndex & 6144; /* Line 1633, Address: 0x102a954 */
  BlkIndex &= 1023; /* Line 1634, Address: 0x102a95c */
  if (frip == 6144) { /* Line 1635, Address: 0x102a968 */

    p0 = 3, p1 = 2; /* Line 1637, Address: 0x102a974 */
    p2 = 1, p3 = 0; /* Line 1638, Address: 0x102a97c */
  } /* Line 1639, Address: 0x102a984 */
  else if (frip & 4096) { /* Line 1640, Address: 0x102a98c */

    p0 = 2, p1 = 3; /* Line 1642, Address: 0x102a998 */
    p2 = 0, p3 = 1; /* Line 1643, Address: 0x102a9a0 */
  } /* Line 1644, Address: 0x102a9a8 */
  else if (frip & 2048) { /* Line 1645, Address: 0x102a9b0 */

    p0 = 1, p1 = 0; /* Line 1647, Address: 0x102a9bc */
    p2 = 3, p3 = 2; /* Line 1648, Address: 0x102a9c4 */
  } /* Line 1649, Address: 0x102a9cc */
  else {

    p0 = 0, p1 = 1; /* Line 1652, Address: 0x102a9d4 */
    p2 = 2, p3 = 3; /* Line 1653, Address: 0x102a9dc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1656, Address: 0x102a9e4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1657, Address: 0x102aa28 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1658, Address: 0x102aa6c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1659, Address: 0x102aab0 */

} /* Line 1661, Address: 0x102aaf4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1679, Address: 0x102ab30 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1680, Address: 0x102ab50 */
} /* Line 1681, Address: 0x102ab70 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1683, Address: 0x102ab80 */
  wH_posiw = 0; /* Line 1684, Address: 0x102aba0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1685, Address: 0x102aba4 */
} /* Line 1686, Address: 0x102abc4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1693, Address: 0x102abe0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1699, Address: 0x102ac10 */
  yOffs += wV_posiw; /* Line 1700, Address: 0x102ac20 */





  if ((short)xOffs < 0) /* Line 1706, Address: 0x102ac30 */
    xOffs = 0; /* Line 1707, Address: 0x102ac4c */
  if ((short)yOffs < 0) /* Line 1708, Address: 0x102ac50 */
    yOffs = 0; /* Line 1709, Address: 0x102ac6c */
  if ((short)xOffs >= 16384) /* Line 1710, Address: 0x102ac70 */
    xOffs = 16383; /* Line 1711, Address: 0x102ac90 */
  if ((short)yOffs >= 2048) /* Line 1712, Address: 0x102ac98 */
    yOffs = 2047; /* Line 1713, Address: 0x102acb8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1714, Address: 0x102acc0 */
  if (i < 0) i = 0; /* Line 1715, Address: 0x102ad08 */

  ScreenNo = pMapWk[i] & 127; /* Line 1717, Address: 0x102ad14 */

  if (ScreenNo) { /* Line 1719, Address: 0x102ad30 */




    xOffs &= 32767; /* Line 1724, Address: 0x102ad38 */
    yOffs &= 32767; /* Line 1725, Address: 0x102ad44 */


    xBlk = xOffs; /* Line 1728, Address: 0x102ad50 */
    xBlk %= 256; /* Line 1729, Address: 0x102ad58 */
    xBlk /= 16; /* Line 1730, Address: 0x102ad78 */
    yBlk = yOffs; /* Line 1731, Address: 0x102ad94 */
    yBlk %= 256; /* Line 1732, Address: 0x102ad9c */
    yBlk /= 16; /* Line 1733, Address: 0x102adbc */

    lpw = pmapwk; /* Line 1735, Address: 0x102add8 */
    lpw += xBlk; /* Line 1736, Address: 0x102ade0 */
    lpw += yBlk * 16; /* Line 1737, Address: 0x102ade8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1738, Address: 0x102adf4 */
    *pIndex = *lpw; /* Line 1739, Address: 0x102ae0c */

    return 1; /* Line 1741, Address: 0x102ae1c */
  }

  *pIndex = 0; /* Line 1744, Address: 0x102ae28 */
  return 0; /* Line 1745, Address: 0x102ae30 */
} /* Line 1746, Address: 0x102ae34 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1766, Address: 0x102ae60 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1774, Address: 0x102ae88 */
  if (ScreenNo) { /* Line 1775, Address: 0x102aeec */





    xBlk = xOffs; /* Line 1781, Address: 0x102aef4 */
    xBlk %= 256; /* Line 1782, Address: 0x102aefc */
    xBlk /= 16; /* Line 1783, Address: 0x102af1c */
    yBlk = yOffs; /* Line 1784, Address: 0x102af38 */
    yBlk %= 256; /* Line 1785, Address: 0x102af40 */
    yBlk /= 16; /* Line 1786, Address: 0x102af60 */


    lpw = pmapwk; /* Line 1789, Address: 0x102af7c */
    lpw += xBlk; /* Line 1790, Address: 0x102af84 */
    lpw += yBlk * 16; /* Line 1791, Address: 0x102af8c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1792, Address: 0x102af98 */
    *ppBlockNo = lpw; /* Line 1793, Address: 0x102afb0 */
    *pIndex = *lpw; /* Line 1794, Address: 0x102afb8 */




    return 1; /* Line 1799, Address: 0x102afc8 */
  }

  *pIndex = 0; /* Line 1802, Address: 0x102afd4 */
  return 0; /* Line 1803, Address: 0x102afdc */
} /* Line 1804, Address: 0x102afe0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1818, Address: 0x102b000 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1825, Address: 0x102b01c */
  pMapWk = (unsigned char*)mapwka; /* Line 1826, Address: 0x102b020 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1827, Address: 0x102b028 */
    *pBlockIndex = BlockNo; /* Line 1828, Address: 0x102b04c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1829, Address: 0x102b058 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1830, Address: 0x102b070 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1831, Address: 0x102b084 */
    }
  }


} /* Line 1836, Address: 0x102b09c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1850, Address: 0x102b0c0 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1851, Address: 0x102b0cc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1852, Address: 0x102b0f8 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1853, Address: 0x102b144 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1854, Address: 0x102b170 */

          return 0; /* Line 1856, Address: 0x102b1bc */
        }
      }
    }
  }

  return 1; /* Line 1862, Address: 0x102b1c8 */
} /* Line 1863, Address: 0x102b1cc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1880, Address: 0x102b1e0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1881, Address: 0x102b1fc */

} /* Line 1883, Address: 0x102b218 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1885, Address: 0x102b230 */
  wH_posiw = 0; /* Line 1886, Address: 0x102b24c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1887, Address: 0x102b250 */

} /* Line 1889, Address: 0x102b26c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1891, Address: 0x102b280 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1892, Address: 0x102b294 */

} /* Line 1894, Address: 0x102b2b0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1896, Address: 0x102b2c0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1897, Address: 0x102b2dc */

} /* Line 1899, Address: 0x102b2f8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1901, Address: 0x102b310 */
  xOffs += wH_posiw; /* Line 1902, Address: 0x102b328 */
  yOffs += wV_posiw; /* Line 1903, Address: 0x102b338 */
  yOffs &= 240; /* Line 1904, Address: 0x102b348 */
  xOffs &= 496; /* Line 1905, Address: 0x102b354 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1907, Address: 0x102b360 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1908, Address: 0x102b38c */


} /* Line 1911, Address: 0x102b3b8 */















void mapwrt(void) { /* Line 1927, Address: 0x102b3d0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1932, Address: 0x102b3e8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1933, Address: 0x102b3f4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1934, Address: 0x102b400 */
  VramBase = 16384; /* Line 1935, Address: 0x102b408 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1936, Address: 0x102b40c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1940, Address: 0x102b424 */
  VramBase = 24576; /* Line 1941, Address: 0x102b42c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1942, Address: 0x102b430 */

} /* Line 1944, Address: 0x102b440 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1947, Address: 0x102b460 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1948, Address: 0x102b478 */
} /* Line 1949, Address: 0x102b498 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1954, Address: 0x102b4b0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1958, Address: 0x102b4d0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1961, Address: 0x102b4ec */



    wD4 += 16; /* Line 1965, Address: 0x102b514 */
  } while ((short)--wD6 >= 0); /* Line 1966, Address: 0x102b520 */

} /* Line 1968, Address: 0x102b548 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1973, Address: 0x102b560 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1976, Address: 0x102b57c */
  wD6 = 15; /* Line 1977, Address: 0x102b584 */






  do {
    if (actwk[0].xposi.w.h == 96) /* Line 1985, Address: 0x102b58c */
      wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1986, Address: 0x102b5a8 */
    else
      wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1988, Address: 0x102b5d4 */

    mapwrt_sub(&z31cwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1990, Address: 0x102b5f8 */
    wD4 += 16; /* Line 1991, Address: 0x102b618 */
  } while ((short)--wD6 >= 0); /* Line 1992, Address: 0x102b620 */
} /* Line 1993, Address: 0x102b644 */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2019, Address: 0x102b660 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2024, Address: 0x102b688 */
  wD0 = pWrttbl[wD0]; /* Line 2025, Address: 0x102b698 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2027, Address: 0x102b6b4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2028, Address: 0x102b6d8 */
  if (wD0) { /* Line 2029, Address: 0x102b700 */
    wD5 = 65520; /* Line 2030, Address: 0x102b70c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2031, Address: 0x102b714 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2034, Address: 0x102b730 */



  } /* Line 2038, Address: 0x102b758 */
  else {

    wD5 = 0; /* Line 2041, Address: 0x102b760 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2042, Address: 0x102b764 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2046, Address: 0x102b780 */
  }





} /* Line 2053, Address: 0x102b7a8 */




void mapinit(void) { /* Line 2058, Address: 0x102b7d0 */





  mapset(); /* Line 2064, Address: 0x102b7d8 */


  colorset2(mapinittbl.colorno2); /* Line 2067, Address: 0x102b7e0 */
  colorset(mapinittbl.colorno2); /* Line 2068, Address: 0x102b7f4 */






  if (plflag != 0) { /* Line 2075, Address: 0x102b808 */
    enecginit(); /* Line 2076, Address: 0x102b81c */
  }

  if (play_start & 2) { /* Line 2079, Address: 0x102b824 */

    divdevset(); /* Line 2081, Address: 0x102b83c */
  }


} /* Line 2085, Address: 0x102b844 */









void mapset(void) {} /* Line 2095, Address: 0x102b860 */
