#include "..\EQU.H"
#include "SCR31A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3D.H"

static unsigned char z32dwrttbl[49] = {
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
extern unsigned char mapwkb[64][8];
extern unsigned char mapwka[64][8];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;








































































void enecginit() {} /* Line 111, Address: 0x1026fe0 */



void divdevset() {} /* Line 115, Address: 0x1026ff0 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 169, Address: 0x1027000 */
    return &actwk[0]; /* Line 170, Address: 0x1027014 */
  }
  return &actwk[1]; /* Line 172, Address: 0x1027024 */
} /* Line 173, Address: 0x102702c */












void scr_set() { /* Line 186, Address: 0x1027040 */





  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x102704c */
    4, 0, 9879, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1027080 */

  i = 0; /* Line 199, Address: 0x10270c8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x10270cc */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x10270e8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x10270fc */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x1027118 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x102712c */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1027148 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x102715c */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1027178 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x102718c */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x10271a8 */
  scra_h_count = 16; /* Line 211, Address: 0x10271cc */
  scra_v_count = 16; /* Line 212, Address: 0x10271d8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x10271e4 */
  scra_hline = 160; /* Line 215, Address: 0x1027200 */

  playposiset(); /* Line 217, Address: 0x102720c */
} /* Line 218, Address: 0x1027214 */











void playposiset() { /* Line 230, Address: 0x1027230 */
  unsigned short playpositbl[2] = { /* Line 231, Address: 0x1027248 */
    32,
    428
  };
  unsigned short endplpositbl[16] = { /* Line 235, Address: 0x1027264 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
     5120, 684
  };
  unsigned char playmapnotbl[4] = { /* Line 245, Address: 0x1027298 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 255, Address: 0x10272c4 */
    playload(); /* Line 256, Address: 0x10272d8 */
    xWk = actwk[0].xposi.w.h; /* Line 257, Address: 0x10272e0 */
    yWk = actwk[0].yposi.w.h; /* Line 258, Address: 0x10272f0 */

    if (yWk < 0) yWk = 0; /* Line 260, Address: 0x1027300 */

  } /* Line 262, Address: 0x1027314 */
  else {

    if (demoflag.w < 0) { /* Line 265, Address: 0x102731c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 266, Address: 0x1027334 */
    } /* Line 267, Address: 0x102735c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 270, Address: 0x1027364 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 273, Address: 0x1027384 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 274, Address: 0x10273a0 */
  }


  if ((unsigned short)xWk > 160) { /* Line 278, Address: 0x10273b4 */
    xWk -= 160; /* Line 279, Address: 0x10273c8 */
  } /* Line 280, Address: 0x10273d4 */
  else {
    xWk = 0; /* Line 282, Address: 0x10273dc */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 286, Address: 0x10273e0 */
    xWk = scralim_right; /* Line 287, Address: 0x1027404 */
  }
  scra_h_posit.w.h = xWk; /* Line 289, Address: 0x1027414 */

  if ((unsigned short)yWk > 96) { /* Line 291, Address: 0x102741c */
    yWk -= 96; /* Line 292, Address: 0x1027430 */
  } /* Line 293, Address: 0x102743c */
  else {
    yWk = 0; /* Line 295, Address: 0x1027444 */
  }

  if (scralim_down < yWk) { /* Line 298, Address: 0x1027448 */
    yWk = scralim_down; /* Line 299, Address: 0x102746c */
  }

  scra_v_posit.w.h = yWk; /* Line 302, Address: 0x102747c */

  scrbinit(xWk, yWk); /* Line 304, Address: 0x1027484 */

  i = 0; /* Line 306, Address: 0x1027494 */
  loopmapno = playmapnotbl[i++]; /* Line 307, Address: 0x1027498 */
  loopmapno2 = playmapnotbl[i++]; /* Line 308, Address: 0x10274b0 */
  ballmapno = playmapnotbl[i++]; /* Line 309, Address: 0x10274c8 */
  ballmapno2 = playmapnotbl[i++]; /* Line 310, Address: 0x10274e0 */


} /* Line 313, Address: 0x10274f8 */











void scrbinit(short xWk, short yWk) { /* Line 325, Address: 0x1027520 */
  int i;
  short wD2;


  yWk = 536; /* Line 330, Address: 0x1027534 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 331, Address: 0x102753c */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 332, Address: 0x1027564 */
    yWk -= wD2 / 2; /* Line 333, Address: 0x1027580 */
    if (yWk < 0) { /* Line 334, Address: 0x10275b4 */
      yWk = 0; /* Line 335, Address: 0x10275c8 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 339, Address: 0x10275cc */
  scrb_v_posit.w.l = 0; /* Line 340, Address: 0x10275d8 */
  scrc_v_posit.w.h = yWk; /* Line 341, Address: 0x10275e0 */
  scrz_v_posit.w.h = yWk; /* Line 342, Address: 0x10275ec */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 344, Address: 0x10275f8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 345, Address: 0x1027630 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 346, Address: 0x1027670 */


  for (i = 0; i < 16; ++i) { /* Line 349, Address: 0x10276b0 */
    ((int*)hscrollwork)[i] = 0; /* Line 350, Address: 0x10276bc */
  } /* Line 351, Address: 0x10276d0 */

} /* Line 353, Address: 0x10276e0 */












void scroll() { /* Line 366, Address: 0x1027700 */
  int LineSpdTbl[16] = { /* Line 367, Address: 0x1027720 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  3072,  3072,  4096,
     8192, 12288, 16384,
    24576, 32768, 49152
  };
  unsigned char z32d_cnttbl[16] = { /* Line 374, Address: 0x1027754 */
    1, 3, 1, 1, 1, 3, 1, 3, 1, 1, 1, 3, 3, 1, 1, 1
  };
  unsigned char z32d_cnttbl1[3] = { /* Line 377, Address: 0x1027788 */
    6, 1, 0
  };
  unsigned short z32d_kawatbl[3] = { /* Line 380, Address: 0x10277ac */
    8, 32767, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 390, Address: 0x10277d0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 393, Address: 0x10277e0 */
  scrchk(); /* Line 394, Address: 0x102780c */
  scroll_h(); /* Line 395, Address: 0x1027818 */
  scroll_v(); /* Line 396, Address: 0x1027824 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 398, Address: 0x1027830 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 399, Address: 0x1027840 */


  scrollz_h(scra_hz << 4, 64); /* Line 402, Address: 0x1027850 */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 403, Address: 0x1027874 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 404, Address: 0x10278ac */

  lD0.w.l = 536; /* Line 406, Address: 0x10278e4 */
  wD1 = 1312; /* Line 407, Address: 0x10278ec */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 408, Address: 0x10278f8 */

    wD1 -= scra_v_posit.w.h; /* Line 410, Address: 0x1027918 */
    wD1 >>= 1; /* Line 411, Address: 0x102792c */
    lD0.w.l -= wD1; /* Line 412, Address: 0x1027934 */
    if (lD0.w.l < 0) { /* Line 413, Address: 0x1027948 */
      lD0.w.l = 0; /* Line 414, Address: 0x102795c */
    }
  } /* Line 416, Address: 0x1027960 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 418, Address: 0x1027968 */
  }

  scrollb_v(lD0.w.l); /* Line 421, Address: 0x1027980 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 422, Address: 0x1027994 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 423, Address: 0x10279a4 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 424, Address: 0x10279b4 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 426, Address: 0x10279c4 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 427, Address: 0x10279e0 */
  scrflagz.b.h = 0; /* Line 428, Address: 0x10279fc */
  scrflagc.b.h = 0; /* Line 429, Address: 0x1027a04 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 452, Address: 0x1027a0c */
  for (i = 0; i < 16; ++i) { /* Line 453, Address: 0x1027a14 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 454, Address: 0x1027a20 */
    ++pHscrWk; /* Line 455, Address: 0x1027a38 */
  } /* Line 456, Address: 0x1027a3c */
  wD1 = 0; /* Line 457, Address: 0x1027a4c */
  for ( ; i < 80; ++i) { /* Line 458, Address: 0x1027a50 */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 459, Address: 0x1027a58 */
    pHscrWk->l += lD2.l; /* Line 460, Address: 0x1027a7c */
    ++pHscrWk; /* Line 461, Address: 0x1027a8c */
    ++wD1; /* Line 462, Address: 0x1027a90 */
  } /* Line 463, Address: 0x1027a9c */







  pHScrollWork = &hscrollwork[160]; /* Line 471, Address: 0x1027aac */
  lD0.w.h = -scra_h_posit.w.h; /* Line 472, Address: 0x1027ab8 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 473, Address: 0x1027ad8 */
  *pHScrollWork++ = lD0.w.l; /* Line 474, Address: 0x1027afc */


  for (i = 0; i < 3; ++i) { /* Line 477, Address: 0x1027b10 */
    *pHScrollWork++ = lD0.w.l; /* Line 478, Address: 0x1027b1c */
  } /* Line 479, Address: 0x1027b30 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 481, Address: 0x1027b40 */

  for (i = 0; i < 10; ++i) { /* Line 483, Address: 0x1027b64 */
    *pHScrollWork++ = lD0.w.l; /* Line 484, Address: 0x1027b70 */
  } /* Line 485, Address: 0x1027b84 */














  pHscrWk = (int_union*)hscrollwork; /* Line 500, Address: 0x1027b94 */
  for (i = 15; i >= 0; --i) { /* Line 501, Address: 0x1027b9c */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 502, Address: 0x1027ba8 */
    ++pHscrWk; /* Line 503, Address: 0x1027bd4 */
    for (j = z32d_cnttbl[i]; j >= 0; --j) { /* Line 504, Address: 0x1027bd8 */
      *pHScrollWork++ = wD1; /* Line 505, Address: 0x1027bec */
    } /* Line 506, Address: 0x1027bfc */
  } /* Line 507, Address: 0x1027c08 */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 510, Address: 0x1027c14 */

  for (i = 0; i < 6; ++i) { /* Line 512, Address: 0x1027c38 */
    *pHScrollWork++ = lD0.w.l; /* Line 513, Address: 0x1027c44 */
  } /* Line 514, Address: 0x1027c58 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 516, Address: 0x1027c68 */

  for (i = 0; i < 4; ++i) { /* Line 518, Address: 0x1027c8c */
    *pHScrollWork++ = lD0.w.l; /* Line 519, Address: 0x1027c98 */
  } /* Line 520, Address: 0x1027cac */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 522, Address: 0x1027cbc */

  for (i = 0; i < 12; ++i) { /* Line 524, Address: 0x1027ce0 */
    *pHScrollWork++ = lD0.w.l; /* Line 525, Address: 0x1027cec */
  } /* Line 526, Address: 0x1027d00 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 529, Address: 0x1027d10 */
  lD2.l <<= 6; /* Line 530, Address: 0x1027d48 */
  lD2.l /= 24; /* Line 531, Address: 0x1027d54 */
  lD2.l <<= 10; /* Line 532, Address: 0x1027d74 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 533, Address: 0x1027d80 */

  for (i = 2; i >= 0; --i) {   /* Line 535, Address: 0x1027d8c */
    lD0.w.l = -lD3.w.l;   /* Line 536, Address: 0x1027d98 */
    for (j = z32d_cnttbl1[i]; j >= 0; --j) { /* Line 537, Address: 0x1027db4 */
      *pHScrollWork++ = lD0.w.l; /* Line 538, Address: 0x1027dc8 */
    } /* Line 539, Address: 0x1027ddc */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 540, Address: 0x1027de8 */
    lD3.l += lD2.l; /* Line 541, Address: 0x1027e0c */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 542, Address: 0x1027e1c */
  } /* Line 543, Address: 0x1027e40 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 545, Address: 0x1027e4c */

  for (i = 0; i < 8; ++i) { /* Line 547, Address: 0x1027e70 */
    *pHScrollWork++ = lD0.w.l; /* Line 548, Address: 0x1027e7c */
  } /* Line 549, Address: 0x1027e90 */

  pHScrollBuff = lphscrollbuff; /* Line 551, Address: 0x1027ea0 */
  pHScrollWork = &hscrollwork[160]; /* Line 552, Address: 0x1027eac */
  lD0.w.l = scrb_v_posit.w.h; /* Line 553, Address: 0x1027eb8 */
  lD2.w.l = lD0.w.l; /* Line 554, Address: 0x1027ec4 */
  wD4 = lD0.w.l; /* Line 555, Address: 0x1027ecc */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 556, Address: 0x1027ed4 */
  wD3 = lD0.w.l >> 1; /* Line 557, Address: 0x1027ef8 */
  wD1 = 87; /* Line 558, Address: 0x1027f14 */
  wD5 = 29; /* Line 559, Address: 0x1027f1c */
  if (wD3 <= wD1) { /* Line 560, Address: 0x1027f24 */

    wD1 -= wD3; /* Line 562, Address: 0x1027f38 */
    if (wD1 >= 27) { /* Line 563, Address: 0x1027f40 */
      wD1 = 28; /* Line 564, Address: 0x1027f50 */
    }

    wD5 -= wD1; /* Line 567, Address: 0x1027f58 */
    pHScrollWork += lD0.w.l / 2U; /* Line 568, Address: 0x1027f60 */
    waterdirec.w += 64; /* Line 569, Address: 0x1027f84 */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z32d_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 571, Address: 0x1027f98 */


  } /* Line 574, Address: 0x1027fc0 */
  else {
    wD1 -= wD3; /* Line 576, Address: 0x1027fc8 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 581, Address: 0x1027fd0 */
  pHScrollWork = &hscrollwork[28]; /* Line 582, Address: 0x1027fe4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 583, Address: 0x1027ff0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 584, Address: 0x1028004 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 587, Address: 0x102801c */
    lD2.w.l = *pHScrollWork++; /* Line 588, Address: 0x1028030 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 589, Address: 0x1028044 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 590, Address: 0x1028058 */
    lD0.w.l = lD2.w.l; /* Line 591, Address: 0x1028078 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 592, Address: 0x1028080 */
    if (wD3 <= wD4) { /* Line 593, Address: 0x10280a0 */
      wD5 &= 255; /* Line 594, Address: 0x10280b8 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 595, Address: 0x10280c0 */
      wD3 += scra_h_posit.w.h; /* Line 596, Address: 0x10280ec */
      wD3 = -(short)wD3; /* Line 597, Address: 0x1028100 */
      lD0.w.h = wD3; /* Line 598, Address: 0x102811c */
    }

    pHScrollBuff->l = lD0.l; /* Line 601, Address: 0x1028120 */
    ++pHScrollBuff; /* Line 602, Address: 0x102812c */
    ++wD4; /* Line 603, Address: 0x1028138 */
    ++wD5; /* Line 604, Address: 0x1028144 */
  } while ((short)--wD1 >= 0); /* Line 605, Address: 0x102814c */

} /* Line 607, Address: 0x1028170 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 612, Address: 0x10281a0 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 619, Address: 0x10281d4 */
  pA1 = *ppA1; /* Line 620, Address: 0x10281f4 */
  pA2 = *ppA2; /* Line 621, Address: 0x10281fc */

  if (*pA3 <= *pwD4) goto label6; /* Line 623, Address: 0x1028204 */



label1:
  *pwD2 &= 7; /* Line 628, Address: 0x1028228 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 629, Address: 0x102823c */

  lD0.w.l = *pA2++; /* Line 631, Address: 0x1028268 */
  i = 8 - *pwD2; /* Line 632, Address: 0x1028278 */
  goto label4; /* Line 633, Address: 0x102828c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 636, Address: 0x1028294 */


  if (*pA3 <= *pwD4) goto label7; /* Line 639, Address: 0x10282b0 */



label3:
  lD0.w.l = *pA2++; /* Line 644, Address: 0x10282d4 */
  *pwD4 += 8; /* Line 645, Address: 0x10282e4 */


  i = 8; /* Line 648, Address: 0x10282f8 */
label4:
  for ( ; i > 0; --i) { /* Line 650, Address: 0x10282fc */


    pA1->l = lD0.l; /* Line 653, Address: 0x1028304 */
    ++pA1; /* Line 654, Address: 0x102830c */
  } /* Line 655, Address: 0x1028310 */
  if ((short)--wD1 >= 0) goto label2; /* Line 656, Address: 0x1028320 */



label5:
  *ppA1 = pA1; /* Line 661, Address: 0x1028348 */
  *ppA2 = pA2; /* Line 662, Address: 0x1028350 */
  return; /* Line 663, Address: 0x1028358 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 667, Address: 0x1028360 */
  if ((short)wD3 > 0) goto label8; /* Line 668, Address: 0x1028390 */


  if (*pA3 > *pwD4) goto label1; /* Line 671, Address: 0x10283a8 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 674, Address: 0x10283cc */
  if ((short)wD3 > 0) goto label8; /* Line 675, Address: 0x10283fc */
  goto label1; /* Line 676, Address: 0x1028414 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 684, Address: 0x102841c */
  if ((short)wD3 <= 0) goto label3; /* Line 685, Address: 0x102844c */



label8:
  --wD3; /* Line 690, Address: 0x1028464 */
  wD6 = wD3; /* Line 691, Address: 0x102846c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 692, Address: 0x1028470 */

  do {
    *pwD2 &= 255; /* Line 695, Address: 0x1028488 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 696, Address: 0x102849c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 697, Address: 0x10284c8 */
    lD0.w.l = -lD0.w.l; /* Line 698, Address: 0x10284dc */
    pA1->w.h = lD0.w.h; /* Line 699, Address: 0x10284f8 */
    pA1->w.l = lD0.w.l; /* Line 700, Address: 0x1028500 */
    ++pA1; /* Line 701, Address: 0x1028508 */
    ++*pwD4; /* Line 702, Address: 0x102850c */
    ++*pwD2; /* Line 703, Address: 0x1028520 */
  } while ((short)--wD3 >= 0); /* Line 704, Address: 0x1028534 */

  wD6 >>= 3; /* Line 706, Address: 0x1028558 */

  do {
    lD0.w.l = *pA2++; /* Line 709, Address: 0x1028560 */
    --wD1; /* Line 710, Address: 0x1028570 */
  } while ((short)--wD6 >= 0); /* Line 711, Address: 0x102857c */
  goto label2; /* Line 712, Address: 0x10285a0 */
} /* Line 713, Address: 0x10285a8 */















void scroll_h() { /* Line 729, Address: 0x10285d0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 732, Address: 0x10285dc */
  scrh_move(); /* Line 733, Address: 0x10285e8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 734, Address: 0x10285f0 */
    scra_h_count ^= 16; /* Line 735, Address: 0x1028624 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 736, Address: 0x1028638 */
      scrflaga.b.h |= 4; /* Line 737, Address: 0x1028664 */
    } /* Line 738, Address: 0x1028678 */
    else {

      scrflaga.b.h |= 8; /* Line 741, Address: 0x1028680 */
    }
  }


} /* Line 746, Address: 0x1028694 */

void scrh_move() { /* Line 748, Address: 0x10286b0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 751, Address: 0x10286bc */
  wD0 -= scra_h_posit.w.h; /* Line 752, Address: 0x10286c8 */
  wD0 -= scra_hline; /* Line 753, Address: 0x10286dc */
  if (wD0 == 0) { /* Line 754, Address: 0x10286f0 */

    scra_hz = 0; /* Line 756, Address: 0x10286fc */
  } /* Line 757, Address: 0x1028704 */
  else if ((short)wD0 < 0) { /* Line 758, Address: 0x102870c */
    left_check(wD0); /* Line 759, Address: 0x1028724 */
  } /* Line 760, Address: 0x1028730 */
  else {
    right_check(wD0); /* Line 762, Address: 0x1028738 */
  }

} /* Line 765, Address: 0x1028744 */


void right_check(unsigned short wD0) { /* Line 768, Address: 0x1028760 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 771, Address: 0x102876c */
    wD0 = 16; /* Line 772, Address: 0x102878c */
  }

  wD0 += scra_h_posit.w.h; /* Line 775, Address: 0x1028794 */
  if (scralim_right < (short)wD0) { /* Line 776, Address: 0x10287ac */
    wD0 = scralim_right; /* Line 777, Address: 0x10287dc */
  }

  wD1 = wD0; /* Line 780, Address: 0x10287e8 */
  wD1 -= scra_h_posit.w.h; /* Line 781, Address: 0x10287f0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 782, Address: 0x1028804 */
  scra_h_posit.w.h = wD0; /* Line 783, Address: 0x1028834 */
  scra_hz = wD1; /* Line 784, Address: 0x1028840 */

} /* Line 786, Address: 0x1028848 */


void left_check(unsigned short wD0) { /* Line 789, Address: 0x1028860 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 792, Address: 0x102886c */
    wD0 = -16; /* Line 793, Address: 0x102888c */
  }

  wD0 += scra_h_posit.w.h; /* Line 796, Address: 0x1028894 */
  if (scralim_left > (short)wD0) { /* Line 797, Address: 0x10288ac */
    wD0 = scralim_left; /* Line 798, Address: 0x10288dc */
  }

  wD1 = wD0; /* Line 801, Address: 0x10288e8 */
  wD1 -= scra_h_posit.w.h; /* Line 802, Address: 0x10288f0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 803, Address: 0x1028904 */
  scra_h_posit.w.h = wD0; /* Line 804, Address: 0x1028934 */
  scra_hz = wD1; /* Line 805, Address: 0x1028940 */

} /* Line 807, Address: 0x1028948 */


















void scroll_v() { /* Line 826, Address: 0x1028960 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 829, Address: 0x102896c */
  if (actwk[0].cddat & 4) { /* Line 830, Address: 0x1028998 */
    wD0 -= 5; /* Line 831, Address: 0x10289b0 */
  }

  if (actwk[0].cddat & 2) { /* Line 834, Address: 0x10289b8 */
    wD0 += 32; /* Line 835, Address: 0x10289d0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 836, Address: 0x10289d8 */
      wD0 -= scra_vline; /* Line 837, Address: 0x10289f8 */
      sv_move_main2(wD0); /* Line 838, Address: 0x1028a0c */
      return; /* Line 839, Address: 0x1028a18 */
    }
    wD0 -= scra_vline; /* Line 841, Address: 0x1028a20 */
    if (wD0 >= 64) { /* Line 842, Address: 0x1028a34 */
      wD0 -= 64; /* Line 843, Address: 0x1028a44 */
      sv_move_main2(wD0); /* Line 844, Address: 0x1028a4c */
      return; /* Line 845, Address: 0x1028a58 */
    }
    wD0 -= 64; /* Line 847, Address: 0x1028a60 */
    if (limmoveflag == 0) goto label1; /* Line 848, Address: 0x1028a68 */
    sv_move_sub2(); /* Line 849, Address: 0x1028a7c */
    return; /* Line 850, Address: 0x1028a84 */
  }




  wD0 -= scra_vline; /* Line 856, Address: 0x1028a8c */
  if (wD0) { /* Line 857, Address: 0x1028aa0 */
    sv_move_main(wD0); /* Line 858, Address: 0x1028aa8 */
    return; /* Line 859, Address: 0x1028ab4 */
  }
  if (limmoveflag == 0) { /* Line 861, Address: 0x1028abc */
    sv_move_sub2(); /* Line 862, Address: 0x1028ad0 */
    return; /* Line 863, Address: 0x1028ad8 */
  }


label1:
  scra_vz = 0; /* Line 868, Address: 0x1028ae0 */

} /* Line 870, Address: 0x1028ae8 */





void sv_move_main(unsigned short wD0) { /* Line 876, Address: 0x1028b00 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 879, Address: 0x1028b10 */
    sv_move_main1(wD0); /* Line 880, Address: 0x1028b2c */
  } /* Line 881, Address: 0x1028b38 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 884, Address: 0x1028b40 */
    if ((short)wD1 < 0) { /* Line 885, Address: 0x1028b4c */
      wD1 = -(short)wD1; /* Line 886, Address: 0x1028b64 */
    }

    if (wD1 >= 2048) { /* Line 889, Address: 0x1028b80 */
      sv_move_main2(wD0); /* Line 890, Address: 0x1028b90 */
    } /* Line 891, Address: 0x1028b9c */
    else {
      if ((short)wD0 > 6) { /* Line 893, Address: 0x1028ba4 */
        sv_move_plus(1536); /* Line 894, Address: 0x1028bc4 */
      } /* Line 895, Address: 0x1028bd0 */
      else if ((short)wD0 < -6) { /* Line 896, Address: 0x1028bd8 */
        sv_move_minus(1536); /* Line 897, Address: 0x1028bf8 */
      } /* Line 898, Address: 0x1028c04 */
      else {
        sv_move_sub(wD0); /* Line 900, Address: 0x1028c0c */
      }
    }
  }
} /* Line 904, Address: 0x1028c18 */



void sv_move_main1(unsigned short wD0) { /* Line 908, Address: 0x1028c30 */

  if ((short)wD0 > 2) { /* Line 910, Address: 0x1028c3c */
    sv_move_plus(512); /* Line 911, Address: 0x1028c5c */
  } /* Line 912, Address: 0x1028c68 */
  else if ((short)wD0 < -2) { /* Line 913, Address: 0x1028c70 */
    sv_move_minus(512); /* Line 914, Address: 0x1028c90 */
  } /* Line 915, Address: 0x1028c9c */
  else {
    sv_move_sub(wD0); /* Line 917, Address: 0x1028ca4 */
  }

} /* Line 920, Address: 0x1028cb0 */


void sv_move_main2(unsigned short wD0) { /* Line 923, Address: 0x1028cc0 */

  if ((short)wD0 > 16) { /* Line 925, Address: 0x1028ccc */
    sv_move_plus(4096); /* Line 926, Address: 0x1028cec */
  } /* Line 927, Address: 0x1028cf8 */
  else if ((short)wD0 < -16) { /* Line 928, Address: 0x1028d00 */
    sv_move_minus(4096); /* Line 929, Address: 0x1028d20 */
  } /* Line 930, Address: 0x1028d2c */
  else {
    sv_move_sub(wD0); /* Line 932, Address: 0x1028d34 */
  }

} /* Line 935, Address: 0x1028d40 */


void sv_move_sub2() { /* Line 938, Address: 0x1028d50 */
  limmoveflag = 0; /* Line 939, Address: 0x1028d58 */
  sv_move_sub(0); /* Line 940, Address: 0x1028d60 */
} /* Line 941, Address: 0x1028d6c */


void sv_move_sub(unsigned short wD0) { /* Line 944, Address: 0x1028d80 */
  int_union lD1;

  lD1.w.h = 0; /* Line 947, Address: 0x1028d8c */
  lD1.w.l = wD0; /* Line 948, Address: 0x1028d90 */
  lD1.l += scra_v_posit.w.h; /* Line 949, Address: 0x1028d98 */
  if ((short)wD0 > 0) { /* Line 950, Address: 0x1028db4 */
    scrv_down_ch(lD1); /* Line 951, Address: 0x1028dd0 */
  } /* Line 952, Address: 0x1028ddc */
  else {
    scrv_up_ch(lD1); /* Line 954, Address: 0x1028de4 */
  }

} /* Line 957, Address: 0x1028df0 */




void sv_move_minus(unsigned short wD1) { /* Line 962, Address: 0x1028e00 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 966, Address: 0x1028e10 */
  lD1.l <<= 8; /* Line 967, Address: 0x1028e2c */
  lD1.l += scra_v_posit.l; /* Line 968, Address: 0x1028e38 */

  wk = lD1.w.h; /* Line 970, Address: 0x1028e4c */
  lD1.w.h = lD1.w.l; /* Line 971, Address: 0x1028e54 */
  lD1.w.l = wk; /* Line 972, Address: 0x1028e5c */
  scrv_up_ch(lD1); /* Line 973, Address: 0x1028e60 */
} /* Line 974, Address: 0x1028e6c */



void scrv_up_ch(int_union lD1) { /* Line 978, Address: 0x1028e80 */
  if (scralim_up >= lD1.w.l) { /* Line 979, Address: 0x1028e8c */
    if (lD1.w.l < -255) { /* Line 980, Address: 0x1028eb4 */
      lD1.w.l &= 2047; /* Line 981, Address: 0x1028ecc */
      actwk[0].yposi.w.h &= 32767; /* Line 982, Address: 0x1028ed8 */
      scra_v_posit.w.h &= 2047; /* Line 983, Address: 0x1028eec */
      scrb_v_posit.w.h &= 1023; /* Line 984, Address: 0x1028f00 */
    } /* Line 985, Address: 0x1028f14 */
    else {

      lD1.w.l = scralim_up; /* Line 988, Address: 0x1028f1c */
    }
  }
  scrv_move(lD1); /* Line 991, Address: 0x1028f28 */

} /* Line 993, Address: 0x1028f34 */





void sv_move_plus(unsigned short wD1) { /* Line 999, Address: 0x1028f50 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1003, Address: 0x1028f60 */
  lD1.w.l = wD1; /* Line 1004, Address: 0x1028f64 */
  lD1.l <<= 8; /* Line 1005, Address: 0x1028f6c */
  lD1.l += scra_v_posit.l; /* Line 1006, Address: 0x1028f78 */

  wk = lD1.w.h; /* Line 1008, Address: 0x1028f8c */
  lD1.w.h = lD1.w.l; /* Line 1009, Address: 0x1028f94 */
  lD1.w.l = wk; /* Line 1010, Address: 0x1028f9c */

  scrv_down_ch(lD1); /* Line 1012, Address: 0x1028fa0 */

} /* Line 1014, Address: 0x1028fac */



void scrv_down_ch(int_union lD1) { /* Line 1018, Address: 0x1028fc0 */
  if (scralim_down <= lD1.w.l) { /* Line 1019, Address: 0x1028fcc */
    lD1.w.l -= 2048; /* Line 1020, Address: 0x1028ff4 */
    if (lD1.w.l > 0) { /* Line 1021, Address: 0x1029000 */
      actwk[0].yposi.w.h &= 2047; /* Line 1022, Address: 0x1029014 */
      scra_v_posit.w.h -= 2048; /* Line 1023, Address: 0x1029028 */
      scrb_v_posit.w.h &= 1023; /* Line 1024, Address: 0x102903c */
    } /* Line 1025, Address: 0x1029050 */
    else {
      lD1.w.l = scralim_down; /* Line 1027, Address: 0x1029058 */
    }
  }
  scrv_move(lD1); /* Line 1030, Address: 0x1029064 */

} /* Line 1032, Address: 0x1029070 */


void scrv_move(int_union lD1) { /* Line 1035, Address: 0x1029080 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1038, Address: 0x1029090 */

  wk = lD1.w.h; /* Line 1040, Address: 0x102909c */
  lD1.w.h = lD1.w.l; /* Line 1041, Address: 0x10290a4 */
  lD1.w.l = wk; /* Line 1042, Address: 0x10290ac */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1044, Address: 0x10290b0 */
  scra_v_posit.l = lD1.l; /* Line 1045, Address: 0x10290d8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1048, Address: 0x10290e4 */
    scra_v_count ^= 16; /* Line 1049, Address: 0x1029118 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1050, Address: 0x102912c */

      scrflaga.b.h |= 2; /* Line 1052, Address: 0x1029158 */
    } /* Line 1053, Address: 0x102916c */
    else {
      scrflaga.b.h |= 1; /* Line 1055, Address: 0x1029174 */
    }
  }


} /* Line 1060, Address: 0x1029188 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1064, Address: 0x10291a0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1067, Address: 0x10291ac */
  lD0.l += lD4.l; /* Line 1068, Address: 0x10291bc */
  scrb_h_posit.l = lD0.l; /* Line 1069, Address: 0x10291cc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1071, Address: 0x10291d8 */

    scrb_h_count ^= 16; /* Line 1073, Address: 0x102920c */
    lD0.l -= lD2.l; /* Line 1074, Address: 0x1029220 */
    if ((long int)lD0.l < 0) { /* Line 1075, Address: 0x1029230 */
      scrflagb.b.h |= 4; /* Line 1076, Address: 0x1029244 */
    } /* Line 1077, Address: 0x1029258 */
    else {

      scrflagb.b.h |= 8; /* Line 1080, Address: 0x1029260 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1085, Address: 0x1029274 */
  lD0.l += lD5.l; /* Line 1086, Address: 0x1029284 */
  scrb_h_posit.l = lD0.l; /* Line 1087, Address: 0x1029294 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1089, Address: 0x10292a0 */

    scrb_v_count ^= 16; /* Line 1091, Address: 0x10292d4 */
    lD0.l -= lD3.l; /* Line 1092, Address: 0x10292e8 */
    if ((long int)lD0.l < 0) { /* Line 1093, Address: 0x10292f8 */
      scrflagb.b.h |= 1; /* Line 1094, Address: 0x102930c */
    } /* Line 1095, Address: 0x1029320 */
    else {

      scrflagb.b.h |= 2; /* Line 1098, Address: 0x1029328 */
    }
  }


} /* Line 1103, Address: 0x102933c */






void scrollb_v(unsigned short wD0) { /* Line 1110, Address: 0x1029350 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1113, Address: 0x102935c */
  scrb_v_posit.w.h = wD0; /* Line 1114, Address: 0x1029368 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1116, Address: 0x1029374 */
    scrb_v_count ^= 16; /* Line 1117, Address: 0x10293a0 */
    if ((short)wD3 > (short)wD0) { /* Line 1118, Address: 0x10293b4 */
      scrflagb.b.h |= 1; /* Line 1119, Address: 0x10293e4 */
    } /* Line 1120, Address: 0x10293f8 */
    else {

      scrflagb.b.h |= 2; /* Line 1123, Address: 0x1029400 */
    }
  }


} /* Line 1128, Address: 0x1029414 */



void scrollb_h(int lD4, int flagb) { /* Line 1132, Address: 0x1029430 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1136, Address: 0x1029440 */
  lD0.l = lD2.l + lD4; /* Line 1137, Address: 0x102944c */
  scrb_h_posit.l = lD0.l; /* Line 1138, Address: 0x102945c */

  lD1.w.h = lD0.w.l; /* Line 1140, Address: 0x1029468 */
  lD1.w.l = lD0.w.h; /* Line 1141, Address: 0x1029470 */
  lD1.w.l &= 16; /* Line 1142, Address: 0x1029478 */

  bD3 = scrb_h_count; /* Line 1144, Address: 0x1029484 */
  lD1.b.b4 ^= bD3; /* Line 1145, Address: 0x1029490 */
  if (!lD1.b.b4) { /* Line 1146, Address: 0x10294a4 */
    scrb_h_count ^= 16; /* Line 1147, Address: 0x10294b0 */
    lD0.l -= lD2.l; /* Line 1148, Address: 0x10294c4 */
    if ((long int)lD0.l < 0) { /* Line 1149, Address: 0x10294d4 */
      scrflagb.b.h |= flagb; /* Line 1150, Address: 0x10294e8 */
    } /* Line 1151, Address: 0x1029504 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1154, Address: 0x102950c */
    }
  }


} /* Line 1159, Address: 0x102952c */



void scrollc_h(int lD4, int flagc) { /* Line 1163, Address: 0x1029540 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1167, Address: 0x1029550 */
  lD0.l = lD2.l + lD4; /* Line 1168, Address: 0x102955c */
  scrc_h_posit.l = lD0.l; /* Line 1169, Address: 0x102956c */

  lD1.w.h = lD0.w.l; /* Line 1171, Address: 0x1029578 */
  lD1.w.l = lD0.w.h; /* Line 1172, Address: 0x1029580 */
  lD1.w.l &= 16; /* Line 1173, Address: 0x1029588 */

  bD3 = scrc_h_count; /* Line 1175, Address: 0x1029594 */
  lD1.b.b4 ^= bD3; /* Line 1176, Address: 0x10295a0 */
  if (!lD1.b.b4) { /* Line 1177, Address: 0x10295b4 */
    scrc_h_count ^= 16; /* Line 1178, Address: 0x10295c0 */
    lD0.l -= lD2.l; /* Line 1179, Address: 0x10295d4 */
    if ((long int)lD0.l < 0) { /* Line 1180, Address: 0x10295e4 */
      scrflagc.b.h |= flagc; /* Line 1181, Address: 0x10295f8 */
    } /* Line 1182, Address: 0x1029614 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1185, Address: 0x102961c */
    }
  }


} /* Line 1190, Address: 0x102963c */











void scrollz_h(int lD4, int flagz) { /* Line 1202, Address: 0x1029650 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1206, Address: 0x1029660 */
  lD0.l = lD2.l + lD4; /* Line 1207, Address: 0x102966c */
  scrz_h_posit.l = lD0.l; /* Line 1208, Address: 0x102967c */

  lD1.w.h = lD0.w.l; /* Line 1210, Address: 0x1029688 */
  lD1.w.l = lD0.w.h; /* Line 1211, Address: 0x1029690 */
  lD1.w.l &= 16; /* Line 1212, Address: 0x1029698 */

  bD3 = scrz_h_count; /* Line 1214, Address: 0x10296a4 */
  lD1.b.b4 ^= bD3; /* Line 1215, Address: 0x10296b0 */
  if (!lD1.b.b4) { /* Line 1216, Address: 0x10296c4 */
    scrz_h_count ^= 16; /* Line 1217, Address: 0x10296d0 */
    lD0.l -= lD2.l; /* Line 1218, Address: 0x10296e4 */
    if ((long int)lD0.l < 0) { /* Line 1219, Address: 0x10296f4 */
      scrflagz.b.h |= flagz; /* Line 1220, Address: 0x1029708 */
    } /* Line 1221, Address: 0x1029724 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1224, Address: 0x102972c */
    }
  }


} /* Line 1229, Address: 0x102974c */














void scrollwrtadva() { /* Line 1244, Address: 0x1029760 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1250, Address: 0x102977c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1251, Address: 0x1029780 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1252, Address: 0x102978c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1253, Address: 0x1029798 */
  pScrFlag = &scrflagb.b.h; /* Line 1254, Address: 0x10297a0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1255, Address: 0x10297a8 */







} /* Line 1263, Address: 0x10297bc */












void scrollwrt() { /* Line 1276, Address: 0x10297e0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1285, Address: 0x1029800 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1286, Address: 0x1029804 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1287, Address: 0x1029810 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1288, Address: 0x102981c */
  pScrFlag = &scrflagbw.b.h; /* Line 1289, Address: 0x1029824 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1290, Address: 0x102982c */

  VramBase = 16384; /* Line 1292, Address: 0x1029840 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1293, Address: 0x1029844 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1294, Address: 0x1029850 */
  pMapWk = (unsigned char*)mapwka; /* Line 1295, Address: 0x102985c */
  pScrFlag = &scrflagaw.b.h; /* Line 1296, Address: 0x1029864 */

  if (*pScrFlag) { /* Line 1298, Address: 0x102986c */
    if (*pScrFlag & 1) { /* Line 1299, Address: 0x1029878 */
      *pScrFlag &= 254; /* Line 1300, Address: 0x102988c */

      lD4.l = -16; /* Line 1302, Address: 0x1029898 */
      wD5 = 65520; /* Line 1303, Address: 0x10298a0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1305, Address: 0x10298a8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1307, Address: 0x10298c8 */
    }




    if (*pScrFlag & 2) { /* Line 1313, Address: 0x10298f4 */
      *pScrFlag &= 253; /* Line 1314, Address: 0x1029908 */

      lD4.l = 224; /* Line 1316, Address: 0x1029914 */
      wD5 = 65520; /* Line 1317, Address: 0x102991c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1318, Address: 0x1029924 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1320, Address: 0x1029944 */
    }




    if (*pScrFlag & 4) { /* Line 1326, Address: 0x1029970 */
      *pScrFlag &= 251; /* Line 1327, Address: 0x1029984 */

      lD4.l = -16; /* Line 1329, Address: 0x1029990 */
      wD5 = 65520; /* Line 1330, Address: 0x1029998 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x10299a0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1333, Address: 0x10299c0 */
    }




    if (*pScrFlag & 8) { /* Line 1339, Address: 0x10299ec */
      *pScrFlag &= 247; /* Line 1340, Address: 0x1029a00 */

      lD4.l = -16; /* Line 1342, Address: 0x1029a0c */
      wD5 = 320; /* Line 1343, Address: 0x1029a14 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1344, Address: 0x1029a1c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1346, Address: 0x1029a3c */
    }
  }






} /* Line 1355, Address: 0x1029a68 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1372, Address: 0x1029a90 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1383, Address: 0x1029abc */

  if (*pScrFlag & 1) { /* Line 1385, Address: 0x1029ac4 */
    *pScrFlag &= 254; /* Line 1386, Address: 0x1029adc */
  } /* Line 1387, Address: 0x1029af0 */
  else {
    *pScrFlag &= 254; /* Line 1389, Address: 0x1029af8 */

    if (*pScrFlag & 2) { /* Line 1391, Address: 0x1029b0c */
      *pScrFlag &= 253; /* Line 1392, Address: 0x1029b24 */
      lD4.w.l = 224; /* Line 1393, Address: 0x1029b38 */
    } /* Line 1394, Address: 0x1029b40 */
    else {
      *pScrFlag &= 253; /* Line 1396, Address: 0x1029b48 */
      goto label1; /* Line 1397, Address: 0x1029b5c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1402, Address: 0x1029b64 */
  wD0 &= 127; /* Line 1403, Address: 0x1029bb4 */
  wD0 = z32dwrttbl[wD0 + 1]; /* Line 1404, Address: 0x1029bbc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1410, Address: 0x1029bdc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1411, Address: 0x1029bfc */
  if (wD0 != 0) { /* Line 1412, Address: 0x1029c20 */
    wD5 = 65520; /* Line 1413, Address: 0x1029c2c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1414, Address: 0x1029c34 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1416, Address: 0x1029c54 */



  } /* Line 1420, Address: 0x1029c80 */
  else {

    wD5 = 0; /* Line 1423, Address: 0x1029c88 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1424, Address: 0x1029c8c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1428, Address: 0x1029cac */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1435, Address: 0x1029cd8 */






    lD4.l = -16; /* Line 1442, Address: 0x1029cec */
    wD5 = 65520; /* Line 1443, Address: 0x1029cf4 */
    if (*pScrFlag & 168) { /* Line 1444, Address: 0x1029cfc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1445, Address: 0x1029d14 */
      wD5 = 320; /* Line 1446, Address: 0x1029d34 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1450, Address: 0x1029d3c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1452, Address: 0x1029d6c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1453, Address: 0x1029d78 */



    for (i = 0; i < 16; ++i) { /* Line 1457, Address: 0x1029d88 */
      wD0 = z32dwrttbl[WrtTblCnt++]; /* Line 1458, Address: 0x1029d94 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1459, Address: 0x1029db4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1460, Address: 0x1029de0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1461, Address: 0x1029e00 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1463, Address: 0x1029e24 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1466, Address: 0x1029e48 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1468, Address: 0x1029e68 */
      }
      lD4.w.l += 16; /* Line 1470, Address: 0x1029e7c */
    } /* Line 1471, Address: 0x1029e88 */
    *pScrFlag = 0; /* Line 1472, Address: 0x1029e98 */
  }
} /* Line 1474, Address: 0x1029ea0 */







void scrollwrtc() {} /* Line 1482, Address: 0x1029ed0 */




void scrollwrtz() {} /* Line 1487, Address: 0x1029ee0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1508, Address: 0x1029ef0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1521, Address: 0x1029f18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1524, Address: 0x1029f38 */
    pTilePoint->x += 2; /* Line 1525, Address: 0x1029f4c */
    if (pTilePoint->x >= 64) { /* Line 1526, Address: 0x1029f60 */
      pTilePoint->x -= 64; /* Line 1527, Address: 0x1029f74 */
    }
    xOffs += 16; /* Line 1529, Address: 0x1029f88 */
  } while (--lpcnt >= 0); /* Line 1530, Address: 0x1029f94 */
} /* Line 1531, Address: 0x1029fa8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1535, Address: 0x1029fc0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1539, Address: 0x1029fe8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1542, Address: 0x102a008 */
    pTilePoint->x += 2; /* Line 1543, Address: 0x102a01c */
    if (pTilePoint->x >= 64) { /* Line 1544, Address: 0x102a030 */
      pTilePoint->x -= 64; /* Line 1545, Address: 0x102a044 */
    }
    xOffs += 16; /* Line 1547, Address: 0x102a058 */
  } while (--lpcnt >= 0); /* Line 1548, Address: 0x102a064 */
} /* Line 1549, Address: 0x102a078 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1568, Address: 0x102a090 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1572, Address: 0x102a0b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1575, Address: 0x102a0d8 */
    pTilePoint->y += 2; /* Line 1576, Address: 0x102a0ec */
    if (pTilePoint->y >= 32) { /* Line 1577, Address: 0x102a0fc */
      pTilePoint->y -= 32; /* Line 1578, Address: 0x102a110 */
    }
    yOffs += 16; /* Line 1580, Address: 0x102a120 */
  } while (--lpcnt >= 0); /* Line 1581, Address: 0x102a12c */
} /* Line 1582, Address: 0x102a140 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1601, Address: 0x102a150 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1607, Address: 0x102a184 */

    base = 1; /* Line 1609, Address: 0x102a194 */
  } /* Line 1610, Address: 0x102a198 */
  else if (VramBase == 16384) { /* Line 1611, Address: 0x102a1a0 */

    base = 0; /* Line 1613, Address: 0x102a1b0 */
  }
  x = pTilePoint->x; /* Line 1615, Address: 0x102a1b4 */
  y = pTilePoint->y; /* Line 1616, Address: 0x102a1bc */


  frip = BlkIndex & 6144; /* Line 1619, Address: 0x102a1c4 */
  BlkIndex &= 1023; /* Line 1620, Address: 0x102a1cc */
  if (frip == 6144) { /* Line 1621, Address: 0x102a1d8 */

    p0 = 3, p1 = 2; /* Line 1623, Address: 0x102a1e4 */
    p2 = 1, p3 = 0; /* Line 1624, Address: 0x102a1ec */
  } /* Line 1625, Address: 0x102a1f4 */
  else if (frip & 4096) { /* Line 1626, Address: 0x102a1fc */

    p0 = 2, p1 = 3; /* Line 1628, Address: 0x102a208 */
    p2 = 0, p3 = 1; /* Line 1629, Address: 0x102a210 */
  } /* Line 1630, Address: 0x102a218 */
  else if (frip & 2048) { /* Line 1631, Address: 0x102a220 */

    p0 = 1, p1 = 0; /* Line 1633, Address: 0x102a22c */
    p2 = 3, p3 = 2; /* Line 1634, Address: 0x102a234 */
  } /* Line 1635, Address: 0x102a23c */
  else {

    p0 = 0, p1 = 1; /* Line 1638, Address: 0x102a244 */
    p2 = 2, p3 = 3; /* Line 1639, Address: 0x102a24c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1642, Address: 0x102a254 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1643, Address: 0x102a298 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1644, Address: 0x102a2dc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1645, Address: 0x102a320 */

} /* Line 1647, Address: 0x102a364 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1665, Address: 0x102a3a0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1666, Address: 0x102a3c0 */
} /* Line 1667, Address: 0x102a3e0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1669, Address: 0x102a3f0 */
  wH_posiw = 0; /* Line 1670, Address: 0x102a410 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1671, Address: 0x102a414 */
} /* Line 1672, Address: 0x102a434 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1679, Address: 0x102a450 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1685, Address: 0x102a480 */
  yOffs += wV_posiw; /* Line 1686, Address: 0x102a490 */





  if ((short)xOffs < 0) /* Line 1692, Address: 0x102a4a0 */
    xOffs = 0; /* Line 1693, Address: 0x102a4bc */
  if ((short)yOffs < 0) /* Line 1694, Address: 0x102a4c0 */
    yOffs = 0; /* Line 1695, Address: 0x102a4dc */
  if ((short)xOffs >= 16384) /* Line 1696, Address: 0x102a4e0 */
    xOffs = 16383; /* Line 1697, Address: 0x102a500 */
  if ((short)yOffs >= 2048) /* Line 1698, Address: 0x102a508 */
    yOffs = 2047; /* Line 1699, Address: 0x102a528 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1700, Address: 0x102a530 */
  if (i < 0) i = 0; /* Line 1701, Address: 0x102a578 */

  ScreenNo = pMapWk[i] & 127; /* Line 1703, Address: 0x102a584 */

  if (ScreenNo) { /* Line 1705, Address: 0x102a5a0 */




    xOffs &= 32767; /* Line 1710, Address: 0x102a5a8 */
    yOffs &= 32767; /* Line 1711, Address: 0x102a5b4 */


    xBlk = xOffs; /* Line 1714, Address: 0x102a5c0 */
    xBlk %= 256; /* Line 1715, Address: 0x102a5c8 */
    xBlk /= 16; /* Line 1716, Address: 0x102a5e8 */
    yBlk = yOffs; /* Line 1717, Address: 0x102a604 */
    yBlk %= 256; /* Line 1718, Address: 0x102a60c */
    yBlk /= 16; /* Line 1719, Address: 0x102a62c */

    lpw = pmapwk; /* Line 1721, Address: 0x102a648 */
    lpw += xBlk; /* Line 1722, Address: 0x102a650 */
    lpw += yBlk * 16; /* Line 1723, Address: 0x102a658 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1724, Address: 0x102a664 */
    *pIndex = *lpw; /* Line 1725, Address: 0x102a67c */

    return 1; /* Line 1727, Address: 0x102a68c */
  }

  *pIndex = 0; /* Line 1730, Address: 0x102a698 */
  return 0; /* Line 1731, Address: 0x102a6a0 */
} /* Line 1732, Address: 0x102a6a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1752, Address: 0x102a6d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1760, Address: 0x102a6f8 */
  if (ScreenNo) { /* Line 1761, Address: 0x102a75c */





    xBlk = xOffs; /* Line 1767, Address: 0x102a764 */
    xBlk %= 256; /* Line 1768, Address: 0x102a76c */
    xBlk /= 16; /* Line 1769, Address: 0x102a78c */
    yBlk = yOffs; /* Line 1770, Address: 0x102a7a8 */
    yBlk %= 256; /* Line 1771, Address: 0x102a7b0 */
    yBlk /= 16; /* Line 1772, Address: 0x102a7d0 */


    lpw = pmapwk; /* Line 1775, Address: 0x102a7ec */
    lpw += xBlk; /* Line 1776, Address: 0x102a7f4 */
    lpw += yBlk * 16; /* Line 1777, Address: 0x102a7fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1778, Address: 0x102a808 */
    *ppBlockNo = lpw; /* Line 1779, Address: 0x102a820 */
    *pIndex = *lpw; /* Line 1780, Address: 0x102a828 */




    return 1; /* Line 1785, Address: 0x102a838 */
  }

  *pIndex = 0; /* Line 1788, Address: 0x102a844 */
  return 0; /* Line 1789, Address: 0x102a84c */
} /* Line 1790, Address: 0x102a850 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1804, Address: 0x102a870 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1811, Address: 0x102a88c */
  pMapWk = (unsigned char*)mapwka; /* Line 1812, Address: 0x102a890 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1813, Address: 0x102a898 */
    *pBlockIndex = BlockNo; /* Line 1814, Address: 0x102a8bc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1815, Address: 0x102a8c8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1816, Address: 0x102a8e0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1817, Address: 0x102a8f4 */
    }
  }


} /* Line 1822, Address: 0x102a90c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1836, Address: 0x102a930 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1837, Address: 0x102a93c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1838, Address: 0x102a968 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1839, Address: 0x102a9b4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1840, Address: 0x102a9e0 */

          return 0; /* Line 1842, Address: 0x102aa2c */
        }
      }
    }
  }

  return 1; /* Line 1848, Address: 0x102aa38 */
} /* Line 1849, Address: 0x102aa3c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1866, Address: 0x102aa50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1867, Address: 0x102aa6c */

} /* Line 1869, Address: 0x102aa88 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1871, Address: 0x102aaa0 */
  wH_posiw = 0; /* Line 1872, Address: 0x102aabc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1873, Address: 0x102aac0 */

} /* Line 1875, Address: 0x102aadc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1877, Address: 0x102aaf0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1878, Address: 0x102ab04 */

} /* Line 1880, Address: 0x102ab20 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1882, Address: 0x102ab30 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1883, Address: 0x102ab4c */

} /* Line 1885, Address: 0x102ab68 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1887, Address: 0x102ab80 */
  xOffs += wH_posiw; /* Line 1888, Address: 0x102ab98 */
  yOffs += wV_posiw; /* Line 1889, Address: 0x102aba8 */
  yOffs &= 240; /* Line 1890, Address: 0x102abb8 */
  xOffs &= 496; /* Line 1891, Address: 0x102abc4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1893, Address: 0x102abd0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1894, Address: 0x102abfc */


} /* Line 1897, Address: 0x102ac28 */















void mapwrt() { /* Line 1913, Address: 0x102ac40 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1918, Address: 0x102ac58 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1919, Address: 0x102ac64 */
  pMapWk = (unsigned char*)mapwka; /* Line 1920, Address: 0x102ac70 */
  VramBase = 16384; /* Line 1921, Address: 0x102ac78 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1922, Address: 0x102ac7c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1926, Address: 0x102ac94 */
  VramBase = 24576; /* Line 1927, Address: 0x102ac9c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1928, Address: 0x102aca0 */

} /* Line 1930, Address: 0x102acb0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1933, Address: 0x102acd0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1934, Address: 0x102ace8 */
} /* Line 1935, Address: 0x102ad08 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1940, Address: 0x102ad20 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1944, Address: 0x102ad40 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1947, Address: 0x102ad5c */



    wD4 += 16; /* Line 1951, Address: 0x102ad84 */
  } while ((short)--wD6 >= 0); /* Line 1952, Address: 0x102ad90 */

} /* Line 1954, Address: 0x102adb8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1959, Address: 0x102add0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1962, Address: 0x102adec */
  wD6 = 15; /* Line 1963, Address: 0x102adf4 */



  do {
    wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1968, Address: 0x102adfc */

    mapwrt_sub(z32dwrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1970, Address: 0x102ae20 */
    wD4 += 16; /* Line 1971, Address: 0x102ae40 */
  } while ((short)--wD6 >= 0); /* Line 1972, Address: 0x102ae48 */
} /* Line 1973, Address: 0x102ae6c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1999, Address: 0x102ae90 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2004, Address: 0x102aeb8 */
  wD0 = pWrttbl[wD0]; /* Line 2005, Address: 0x102aec8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2007, Address: 0x102aee4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2008, Address: 0x102af08 */
  if (wD0) { /* Line 2009, Address: 0x102af30 */
    wD5 = 65520; /* Line 2010, Address: 0x102af3c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2011, Address: 0x102af44 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2014, Address: 0x102af60 */



  } /* Line 2018, Address: 0x102af88 */
  else {

    wD5 = 0; /* Line 2021, Address: 0x102af90 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2022, Address: 0x102af94 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2026, Address: 0x102afb0 */
  }





} /* Line 2033, Address: 0x102afd8 */




void mapinit() { /* Line 2038, Address: 0x102b000 */





  mapset(); /* Line 2044, Address: 0x102b008 */


  colorset2(mapinittbl.colorno2); /* Line 2047, Address: 0x102b010 */
  colorset(mapinittbl.colorno2); /* Line 2048, Address: 0x102b024 */






  if (plflag != 0) { /* Line 2055, Address: 0x102b038 */
    enecginit(); /* Line 2056, Address: 0x102b04c */
  }

  if (play_start & 2) { /* Line 2059, Address: 0x102b054 */

    divdevset(); /* Line 2061, Address: 0x102b06c */
  }


} /* Line 2065, Address: 0x102b074 */









void mapset() {} /* Line 2075, Address: 0x102b090 */
