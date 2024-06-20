#include "..\EQU.H"
#include "SCR31A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3C.H"

static unsigned char z33cwrttbl[49] = {
  0, 0, 0, 0, 0, 0, 6, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
  6, 6, 4, 4, 4, 4, 4, 4, 2, 0,
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







































































void enecginit() {} /* Line 110, Address: 0x102aef0 */



void divdevset() {} /* Line 114, Address: 0x102af00 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 168, Address: 0x102af10 */
    return &actwk[0]; /* Line 169, Address: 0x102af24 */
  }
  return &actwk[1]; /* Line 171, Address: 0x102af34 */
} /* Line 172, Address: 0x102af3c */












void scr_set() { /* Line 185, Address: 0x102af50 */





  unsigned short scr_dir_tbl[6] = { /* Line 191, Address: 0x102af5c */
    4, 0, 1175, 48, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 196, Address: 0x102af90 */

  i = 0; /* Line 198, Address: 0x102afd8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 199, Address: 0x102afdc */
  scralim_left = scr_dir_tbl[i]; /* Line 200, Address: 0x102aff8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 201, Address: 0x102b00c */
  scralim_right = scr_dir_tbl[i]; /* Line 202, Address: 0x102b028 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 203, Address: 0x102b03c */
  scralim_up = scr_dir_tbl[i]; /* Line 204, Address: 0x102b058 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 205, Address: 0x102b06c */
  scralim_down = scr_dir_tbl[i]; /* Line 206, Address: 0x102b088 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 207, Address: 0x102b09c */

  scra_h_keep = scralim_left + 576; /* Line 209, Address: 0x102b0b8 */
  scra_h_count = 16; /* Line 210, Address: 0x102b0dc */
  scra_v_count = 16; /* Line 211, Address: 0x102b0e8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 213, Address: 0x102b0f4 */
  scra_hline = 160; /* Line 214, Address: 0x102b110 */

  playposiset(); /* Line 216, Address: 0x102b11c */
} /* Line 217, Address: 0x102b124 */











void playposiset() { /* Line 229, Address: 0x102b140 */
  unsigned short playpositbl[2] = { /* Line 230, Address: 0x102b158 */
    80,
    268
  };
  unsigned short endplpositbl[16] = { /* Line 234, Address: 0x102b174 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 244, Address: 0x102b1a8 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 254, Address: 0x102b1d4 */
    playload(); /* Line 255, Address: 0x102b1e8 */
    xWk = actwk[0].xposi.w.h; /* Line 256, Address: 0x102b1f0 */
    yWk = actwk[0].yposi.w.h; /* Line 257, Address: 0x102b200 */

    if (yWk < 0) yWk = 0; /* Line 259, Address: 0x102b210 */

  } /* Line 261, Address: 0x102b224 */
  else {

    if (demoflag.w < 0) { /* Line 264, Address: 0x102b22c */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 265, Address: 0x102b244 */
    } /* Line 266, Address: 0x102b26c */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 269, Address: 0x102b274 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 272, Address: 0x102b294 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 273, Address: 0x102b2b0 */
  }


  if ((unsigned short)xWk > 160) { /* Line 277, Address: 0x102b2c4 */
    xWk -= 160; /* Line 278, Address: 0x102b2d8 */
  } /* Line 279, Address: 0x102b2e4 */
  else {
    xWk = 0; /* Line 281, Address: 0x102b2ec */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 285, Address: 0x102b2f0 */
    xWk = scralim_right; /* Line 286, Address: 0x102b314 */
  }
  scra_h_posit.w.h = xWk; /* Line 288, Address: 0x102b324 */

  if ((unsigned short)yWk > 96) { /* Line 290, Address: 0x102b32c */
    yWk -= 96; /* Line 291, Address: 0x102b340 */
  } /* Line 292, Address: 0x102b34c */
  else {
    yWk = 0; /* Line 294, Address: 0x102b354 */
  }

  if (scralim_down < yWk) { /* Line 297, Address: 0x102b358 */
    yWk = scralim_down; /* Line 298, Address: 0x102b37c */
  }

  scra_v_posit.w.h = yWk; /* Line 301, Address: 0x102b38c */

  scrbinit(xWk, yWk); /* Line 303, Address: 0x102b394 */

  i = 0; /* Line 305, Address: 0x102b3a4 */
  loopmapno = playmapnotbl[i++]; /* Line 306, Address: 0x102b3a8 */
  loopmapno2 = playmapnotbl[i++]; /* Line 307, Address: 0x102b3c0 */
  ballmapno = playmapnotbl[i++]; /* Line 308, Address: 0x102b3d8 */
  ballmapno2 = playmapnotbl[i++]; /* Line 309, Address: 0x102b3f0 */


} /* Line 312, Address: 0x102b408 */











void scrbinit(short xWk, short yWk) { /* Line 324, Address: 0x102b430 */
  int i;
  short wD2;


  yWk = 536; /* Line 329, Address: 0x102b444 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 330, Address: 0x102b44c */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 331, Address: 0x102b474 */
    yWk -= wD2 / 2; /* Line 332, Address: 0x102b490 */
    if (yWk < 0) { /* Line 333, Address: 0x102b4c4 */
      yWk = 0; /* Line 334, Address: 0x102b4d8 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 338, Address: 0x102b4dc */
  scrb_v_posit.w.l = 0; /* Line 339, Address: 0x102b4e8 */
  scrc_v_posit.w.h = yWk; /* Line 340, Address: 0x102b4f0 */
  scrz_v_posit.w.h = yWk; /* Line 341, Address: 0x102b4fc */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 343, Address: 0x102b508 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 344, Address: 0x102b540 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 345, Address: 0x102b580 */


  for (i = 0; i < 12; ++i) { /* Line 348, Address: 0x102b5c0 */
    ((int*)hscrollwork)[i] = 0; /* Line 349, Address: 0x102b5cc */
  } /* Line 350, Address: 0x102b5e0 */

} /* Line 352, Address: 0x102b5f0 */












void scroll() { /* Line 365, Address: 0x102b610 */
  int LineSpdTbl[12] = { /* Line 366, Address: 0x102b630 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     8192, 12288, 16384,
    24576, 32768, 49152
  };
  unsigned char z33c_cnttbl[12] = { /* Line 372, Address: 0x102b664 */
    1, 3, 1, 3, 1, 3, 1, 3, 3, 3, 3, 3
  };
  unsigned short z33c_kawatbl[3] = { /* Line 375, Address: 0x102b698 */
    56, 592, 32767
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 385, Address: 0x102b6bc */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 388, Address: 0x102b6cc */
  scrchk(); /* Line 389, Address: 0x102b6f8 */
  scroll_h(); /* Line 390, Address: 0x102b704 */
  scroll_v(); /* Line 391, Address: 0x102b710 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 393, Address: 0x102b71c */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 394, Address: 0x102b72c */


  scrollz_h(scra_hz << 4, 64); /* Line 397, Address: 0x102b73c */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 398, Address: 0x102b760 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 399, Address: 0x102b79c */

  lD0.w.l = 536; /* Line 401, Address: 0x102b7d8 */
  wD1 = 1312; /* Line 402, Address: 0x102b7e0 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 403, Address: 0x102b7e8 */

    wD1 -= scra_v_posit.w.h; /* Line 405, Address: 0x102b808 */
    wD1 >>= 1; /* Line 406, Address: 0x102b81c */
    lD0.w.l -= wD1; /* Line 407, Address: 0x102b824 */
    if (lD0.w.l < 0) { /* Line 408, Address: 0x102b838 */
      lD0.w.l = 0; /* Line 409, Address: 0x102b84c */
    }
  } /* Line 411, Address: 0x102b850 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 413, Address: 0x102b858 */
  }

  scrollb_v(lD0.w.l); /* Line 416, Address: 0x102b86c */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 417, Address: 0x102b880 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 418, Address: 0x102b890 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 419, Address: 0x102b8a0 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 421, Address: 0x102b8b0 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 422, Address: 0x102b8cc */
  scrflagz.b.h = 0; /* Line 423, Address: 0x102b8e8 */
  scrflagc.b.h = 0; /* Line 424, Address: 0x102b8f0 */






















  pHscrWk = (int_union*)hscrollwork; /* Line 447, Address: 0x102b8f8 */
  for (i = 0; i < 12; ++i) { /* Line 448, Address: 0x102b900 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 449, Address: 0x102b90c */
    ++pHscrWk; /* Line 450, Address: 0x102b924 */
  } /* Line 451, Address: 0x102b928 */
  wD1 = 0; /* Line 452, Address: 0x102b938 */
  for ( ; i < 76; ++i) { /* Line 453, Address: 0x102b93c */
    lD2.l = ((long int)(int)wD1 << 8) + 32768; /* Line 454, Address: 0x102b944 */
    pHscrWk->l += lD2.l; /* Line 455, Address: 0x102b968 */
    ++pHscrWk; /* Line 456, Address: 0x102b978 */
    ++wD1; /* Line 457, Address: 0x102b97c */
  } /* Line 458, Address: 0x102b984 */







  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 466, Address: 0x102b994 */
  lD2.l <<= 6; /* Line 467, Address: 0x102b9bc */
  lD2.l /= 28; /* Line 468, Address: 0x102b9c8 */
  lD2.l <<= 10; /* Line 469, Address: 0x102b9e8 */

  lD3.l = 0; /* Line 471, Address: 0x102b9f4 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 472, Address: 0x102b9f8 */

  pHScrollWork = &hscrollwork[158]; /* Line 474, Address: 0x102ba04 */
  for (i = 0; i < 7; ++i) { /* Line 475, Address: 0x102ba10 */
    lD0.w.l = -lD3.w.l; /* Line 476, Address: 0x102ba1c */
    *pHScrollWork-- = lD0.w.l; /* Line 477, Address: 0x102ba38 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 478, Address: 0x102ba4c */
    lD3.l += lD2.l; /* Line 479, Address: 0x102ba70 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 480, Address: 0x102ba80 */
  } /* Line 481, Address: 0x102baa4 */

  pHScrollWork = &hscrollwork[159]; /* Line 483, Address: 0x102bab4 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 484, Address: 0x102bac0 */

  for (i = 0; i < 3; ++i) { /* Line 486, Address: 0x102bae4 */
    *pHScrollWork++ = lD0.w.l; /* Line 487, Address: 0x102baf0 */
  } /* Line 488, Address: 0x102bb04 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 490, Address: 0x102bb14 */

  for (i = 0; i < 2; ++i) { /* Line 492, Address: 0x102bb38 */
    *pHScrollWork++ = lD0.w.l; /* Line 493, Address: 0x102bb44 */
  } /* Line 494, Address: 0x102bb58 */ /* Line 494, Address: 0x102bb58 */














  pHscrWk = (int_union*)hscrollwork; /* Line 509, Address: 0x102bb68 */
  for (i = 11; i >= 0; --i) { /* Line 510, Address: 0x102bb70 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 511, Address: 0x102bb7c */
    ++pHscrWk; /* Line 512, Address: 0x102bba8 */
    for (j = z33c_cnttbl[i]; j >= 0; --j) { /* Line 513, Address: 0x102bbac */
      *pHScrollWork++ = wD1; /* Line 514, Address: 0x102bbc0 */
    } /* Line 515, Address: 0x102bbd0 */
  } /* Line 516, Address: 0x102bbdc */


  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 519, Address: 0x102bbe8 */

  for (i = 0; i < 6; ++i) { /* Line 521, Address: 0x102bc0c */
    *pHScrollWork++ = lD0.w.l; /* Line 522, Address: 0x102bc18 */
  } /* Line 523, Address: 0x102bc2c */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 525, Address: 0x102bc3c */

  for (i = 0; i < 4; ++i) { /* Line 527, Address: 0x102bc60 */
    *pHScrollWork++ = lD0.w.l; /* Line 528, Address: 0x102bc6c */
  } /* Line 529, Address: 0x102bc80 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 531, Address: 0x102bc90 */

  for (i = 0; i < 12; ++i) { /* Line 533, Address: 0x102bcb4 */
    *pHScrollWork++ = lD0.w.l; /* Line 534, Address: 0x102bcc0 */
  } /* Line 535, Address: 0x102bcd4 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 537, Address: 0x102bce4 */

  for (i = 0; i < 4; ++i) { /* Line 539, Address: 0x102bd08 */
    *pHScrollWork++ = lD0.w.l; /* Line 540, Address: 0x102bd14 */
  } /* Line 541, Address: 0x102bd28 */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 544, Address: 0x102bd38 */
  lD2.l <<= 6; /* Line 545, Address: 0x102bd70 */
  lD2.l /= 44; /* Line 546, Address: 0x102bd7c */
  lD2.l <<= 11; /* Line 547, Address: 0x102bd9c */
  lD3.w.l = scrb_h_posit.w.h; /* Line 548, Address: 0x102bda8 */

  for (i = 0; i < 10; ++i) { /* Line 550, Address: 0x102bdb4 */
    *pHScrollWork++ = (unsigned short)-lD3.w.l; /* Line 551, Address: 0x102bdc0 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 552, Address: 0x102bdec */
    lD3.l += lD2.l; /* Line 553, Address: 0x102be10 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 554, Address: 0x102be20 */
  } /* Line 555, Address: 0x102be44 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 557, Address: 0x102be54 */

  for (i = 0; i < 8; ++i) { /* Line 559, Address: 0x102be78 */
    *pHScrollWork++ = lD0.w.l; /* Line 560, Address: 0x102be84 */
  } /* Line 561, Address: 0x102be98 */

  pHScrollBuff = lphscrollbuff; /* Line 563, Address: 0x102bea8 */
  pHScrollWork = &hscrollwork[160]; /* Line 564, Address: 0x102beb4 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 565, Address: 0x102bec0 */
  lD2.w.l = lD0.w.l; /* Line 566, Address: 0x102becc */
  wD4 = lD0.w.l; /* Line 567, Address: 0x102bed4 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 568, Address: 0x102bedc */
  wD3 = lD0.w.l >> 1; /* Line 569, Address: 0x102bf00 */
  wD1 = 87; /* Line 570, Address: 0x102bf18 */
  wD5 = 29; /* Line 571, Address: 0x102bf20 */
  if (wD3 <= wD1) { /* Line 572, Address: 0x102bf28 */

    wD1 -= wD3; /* Line 574, Address: 0x102bf3c */
    if (wD1 >= 27) { /* Line 575, Address: 0x102bf44 */
      wD1 = 28; /* Line 576, Address: 0x102bf54 */
    }

    wD5 -= wD1; /* Line 579, Address: 0x102bf5c */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 580, Address: 0x102bf68 */
    waterdirec.w += 64; /* Line 581, Address: 0x102bf8c */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z33c_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 583, Address: 0x102bfa0 */


  } /* Line 586, Address: 0x102bfcc */
  else {
    wD1 -= wD3; /* Line 588, Address: 0x102bfd4 */
  }



  wD1 = (wD5 << 3) - 1; /* Line 593, Address: 0x102bfe0 */
  pHScrollWork = &hscrollwork[24]; /* Line 594, Address: 0x102bff4 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 595, Address: 0x102c000 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 596, Address: 0x102c014 */

  do {
    lD2.w.h = *pHScrollWork++; /* Line 599, Address: 0x102c02c */
    lD2.w.l = *pHScrollWork++; /* Line 600, Address: 0x102c040 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 601, Address: 0x102c054 */
    lD2.w.l = (unsigned short)-lD2.w.l; /* Line 602, Address: 0x102c068 */
    lD0.w.l = lD2.w.l; /* Line 603, Address: 0x102c088 */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 604, Address: 0x102c090 */
    if (wD3 <= wD4) { /* Line 605, Address: 0x102c0b0 */
      wD5 &= 255; /* Line 606, Address: 0x102c0c8 */
      wD3 = (short)(char)awasintbl[wD5]; /* Line 607, Address: 0x102c0d0 */
      wD3 += scra_h_posit.w.h; /* Line 608, Address: 0x102c0fc */
      wD3 = -(short)wD3; /* Line 609, Address: 0x102c110 */
      lD0.w.h = wD3; /* Line 610, Address: 0x102c12c */
    }

    pHScrollBuff->l = lD0.l; /* Line 613, Address: 0x102c130 */
    ++pHScrollBuff; /* Line 614, Address: 0x102c13c */
    ++wD4; /* Line 615, Address: 0x102c148 */
    ++wD5; /* Line 616, Address: 0x102c154 */
  } while ((short)--wD1 >= 0); /* Line 617, Address: 0x102c15c */

} /* Line 619, Address: 0x102c180 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 624, Address: 0x102c1b0 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  lD0.w.h = -scra_h_posit.w.h; /* Line 631, Address: 0x102c1e4 */
  pA1 = *ppA1; /* Line 632, Address: 0x102c204 */
  pA2 = *ppA2; /* Line 633, Address: 0x102c20c */

  if (*pA3 <= *pwD4) goto label6; /* Line 635, Address: 0x102c214 */



label1:
  *pwD2 &= 7; /* Line 640, Address: 0x102c238 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 641, Address: 0x102c24c */

  lD0.w.l = *pA2++; /* Line 643, Address: 0x102c278 */
  i = 8 - *pwD2; /* Line 644, Address: 0x102c288 */
  goto label4; /* Line 645, Address: 0x102c29c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 648, Address: 0x102c2a4 */


  if (*pA3 <= *pwD4) goto label7; /* Line 651, Address: 0x102c2c0 */



label3:
  lD0.w.l = *pA2++; /* Line 656, Address: 0x102c2e4 */
  *pwD4 += 8; /* Line 657, Address: 0x102c2f4 */


  i = 8; /* Line 660, Address: 0x102c308 */
label4:
  for ( ; i > 0; --i) { /* Line 662, Address: 0x102c30c */


    pA1->l = lD0.l; /* Line 665, Address: 0x102c314 */
    ++pA1; /* Line 666, Address: 0x102c31c */
  } /* Line 667, Address: 0x102c320 */
  if ((short)--wD1 >= 0) goto label2; /* Line 668, Address: 0x102c330 */



label5:
  *ppA1 = pA1; /* Line 673, Address: 0x102c358 */
  *ppA2 = pA2; /* Line 674, Address: 0x102c360 */
  return; /* Line 675, Address: 0x102c368 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 679, Address: 0x102c370 */
  if ((short)wD3 > 0) goto label8; /* Line 680, Address: 0x102c3a0 */


  if (*pA3 > *pwD4) goto label1; /* Line 683, Address: 0x102c3b8 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 686, Address: 0x102c3dc */
  if ((short)wD3 > 0) goto label8; /* Line 687, Address: 0x102c40c */
  goto label1; /* Line 688, Address: 0x102c424 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 696, Address: 0x102c42c */
  if ((short)wD3 <= 0) goto label3; /* Line 697, Address: 0x102c45c */



label8:
  --wD3; /* Line 702, Address: 0x102c474 */
  wD6 = wD3; /* Line 703, Address: 0x102c47c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 704, Address: 0x102c480 */

  do {
    *pwD2 &= 255; /* Line 707, Address: 0x102c498 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 708, Address: 0x102c4ac */
    lD0.w.l += scrb_h_posit.w.h; /* Line 709, Address: 0x102c4d8 */
    lD0.w.l = -lD0.w.l; /* Line 710, Address: 0x102c4ec */
    pA1->w.h = lD0.w.h; /* Line 711, Address: 0x102c508 */
    pA1->w.l = lD0.w.l; /* Line 712, Address: 0x102c510 */
    ++pA1; /* Line 713, Address: 0x102c518 */
    ++*pwD4; /* Line 714, Address: 0x102c51c */
    ++*pwD2; /* Line 715, Address: 0x102c530 */
  } while ((short)--wD3 >= 0); /* Line 716, Address: 0x102c544 */

  wD6 >>= 3; /* Line 718, Address: 0x102c568 */

  do {
    lD0.w.l = *pA2++; /* Line 721, Address: 0x102c570 */
    --wD1; /* Line 722, Address: 0x102c580 */
  } while ((short)--wD6 >= 0); /* Line 723, Address: 0x102c58c */
  goto label2; /* Line 724, Address: 0x102c5b0 */
} /* Line 725, Address: 0x102c5b8 */















void scroll_h() { /* Line 741, Address: 0x102c5e0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 744, Address: 0x102c5ec */
  scrh_move(); /* Line 745, Address: 0x102c5f8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 746, Address: 0x102c600 */
    scra_h_count ^= 16; /* Line 747, Address: 0x102c634 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 748, Address: 0x102c648 */
      scrflaga.b.h |= 4; /* Line 749, Address: 0x102c674 */
    } /* Line 750, Address: 0x102c688 */
    else {

      scrflaga.b.h |= 8; /* Line 753, Address: 0x102c690 */
    }
  }


} /* Line 758, Address: 0x102c6a4 */

void scrh_move() { /* Line 760, Address: 0x102c6c0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 763, Address: 0x102c6cc */
  wD0 -= scra_h_posit.w.h; /* Line 764, Address: 0x102c6d8 */
  wD0 -= scra_hline; /* Line 765, Address: 0x102c6ec */
  if (wD0 == 0) { /* Line 766, Address: 0x102c700 */

    scra_hz = 0; /* Line 768, Address: 0x102c70c */
  } /* Line 769, Address: 0x102c714 */
  else if ((short)wD0 < 0) { /* Line 770, Address: 0x102c71c */
    left_check(wD0); /* Line 771, Address: 0x102c734 */
  } /* Line 772, Address: 0x102c740 */
  else {
    right_check(wD0); /* Line 774, Address: 0x102c748 */
  }

} /* Line 777, Address: 0x102c754 */


void right_check(unsigned short wD0) { /* Line 780, Address: 0x102c770 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 783, Address: 0x102c77c */
    wD0 = 16; /* Line 784, Address: 0x102c79c */
  }

  wD0 += scra_h_posit.w.h; /* Line 787, Address: 0x102c7a4 */
  if (scralim_right < (short)wD0) { /* Line 788, Address: 0x102c7bc */
    wD0 = scralim_right; /* Line 789, Address: 0x102c7ec */
  }

  wD1 = wD0; /* Line 792, Address: 0x102c7f8 */
  wD1 -= scra_h_posit.w.h; /* Line 793, Address: 0x102c800 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 794, Address: 0x102c814 */
  scra_h_posit.w.h = wD0; /* Line 795, Address: 0x102c844 */
  scra_hz = wD1; /* Line 796, Address: 0x102c850 */

} /* Line 798, Address: 0x102c858 */


void left_check(unsigned short wD0) { /* Line 801, Address: 0x102c870 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 804, Address: 0x102c87c */
    wD0 = -16; /* Line 805, Address: 0x102c89c */
  }

  wD0 += scra_h_posit.w.h; /* Line 808, Address: 0x102c8a4 */
  if (scralim_left > (short)wD0) { /* Line 809, Address: 0x102c8bc */
    wD0 = scralim_left; /* Line 810, Address: 0x102c8ec */
  }

  wD1 = wD0; /* Line 813, Address: 0x102c8f8 */
  wD1 -= scra_h_posit.w.h; /* Line 814, Address: 0x102c900 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 815, Address: 0x102c914 */
  scra_h_posit.w.h = wD0; /* Line 816, Address: 0x102c944 */
  scra_hz = wD1; /* Line 817, Address: 0x102c950 */

} /* Line 819, Address: 0x102c958 */


















void scroll_v() { /* Line 838, Address: 0x102c970 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 841, Address: 0x102c97c */
  if (actwk[0].cddat & 4) { /* Line 842, Address: 0x102c9a8 */
    wD0 -= 5; /* Line 843, Address: 0x102c9c0 */
  }

  if (actwk[0].cddat & 2) { /* Line 846, Address: 0x102c9c8 */
    wD0 += 32; /* Line 847, Address: 0x102c9e0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 848, Address: 0x102c9e8 */
      wD0 -= scra_vline; /* Line 849, Address: 0x102ca08 */
      sv_move_main2(wD0); /* Line 850, Address: 0x102ca1c */
      return; /* Line 851, Address: 0x102ca28 */
    }
    wD0 -= scra_vline; /* Line 853, Address: 0x102ca30 */
    if (wD0 >= 64) { /* Line 854, Address: 0x102ca44 */
      wD0 -= 64; /* Line 855, Address: 0x102ca54 */
      sv_move_main2(wD0); /* Line 856, Address: 0x102ca5c */
      return; /* Line 857, Address: 0x102ca68 */
    }
    wD0 -= 64; /* Line 859, Address: 0x102ca70 */
    if (limmoveflag == 0) goto label1; /* Line 860, Address: 0x102ca78 */
    sv_move_sub2(); /* Line 861, Address: 0x102ca8c */
    return; /* Line 862, Address: 0x102ca94 */
  }




  wD0 -= scra_vline; /* Line 868, Address: 0x102ca9c */
  if (wD0) { /* Line 869, Address: 0x102cab0 */
    sv_move_main(wD0); /* Line 870, Address: 0x102cab8 */
    return; /* Line 871, Address: 0x102cac4 */
  }
  if (limmoveflag == 0) { /* Line 873, Address: 0x102cacc */
    sv_move_sub2(); /* Line 874, Address: 0x102cae0 */
    return; /* Line 875, Address: 0x102cae8 */
  }


label1:
  scra_vz = 0; /* Line 880, Address: 0x102caf0 */

} /* Line 882, Address: 0x102caf8 */





void sv_move_main(unsigned short wD0) { /* Line 888, Address: 0x102cb10 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 891, Address: 0x102cb20 */
    sv_move_main1(wD0); /* Line 892, Address: 0x102cb3c */
  } /* Line 893, Address: 0x102cb48 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 896, Address: 0x102cb50 */
    if ((short)wD1 < 0) { /* Line 897, Address: 0x102cb5c */
      wD1 = -(short)wD1; /* Line 898, Address: 0x102cb74 */
    }

    if (wD1 >= 2048) { /* Line 901, Address: 0x102cb90 */
      sv_move_main2(wD0); /* Line 902, Address: 0x102cba0 */
    } /* Line 903, Address: 0x102cbac */
    else {
      if ((short)wD0 > 6) { /* Line 905, Address: 0x102cbb4 */
        sv_move_plus(1536); /* Line 906, Address: 0x102cbd4 */
      } /* Line 907, Address: 0x102cbe0 */
      else if ((short)wD0 < -6) { /* Line 908, Address: 0x102cbe8 */
        sv_move_minus(1536); /* Line 909, Address: 0x102cc08 */
      } /* Line 910, Address: 0x102cc14 */
      else {
        sv_move_sub(wD0); /* Line 912, Address: 0x102cc1c */
      }
    }
  }
} /* Line 916, Address: 0x102cc28 */



void sv_move_main1(unsigned short wD0) { /* Line 920, Address: 0x102cc40 */

  if ((short)wD0 > 2) { /* Line 922, Address: 0x102cc4c */
    sv_move_plus(512); /* Line 923, Address: 0x102cc6c */
  } /* Line 924, Address: 0x102cc78 */
  else if ((short)wD0 < -2) { /* Line 925, Address: 0x102cc80 */
    sv_move_minus(512); /* Line 926, Address: 0x102cca0 */
  } /* Line 927, Address: 0x102ccac */
  else {
    sv_move_sub(wD0); /* Line 929, Address: 0x102ccb4 */
  }

} /* Line 932, Address: 0x102ccc0 */


void sv_move_main2(unsigned short wD0) { /* Line 935, Address: 0x102ccd0 */

  if ((short)wD0 > 16) { /* Line 937, Address: 0x102ccdc */
    sv_move_plus(4096); /* Line 938, Address: 0x102ccfc */
  } /* Line 939, Address: 0x102cd08 */
  else if ((short)wD0 < -16) { /* Line 940, Address: 0x102cd10 */
    sv_move_minus(4096); /* Line 941, Address: 0x102cd30 */
  } /* Line 942, Address: 0x102cd3c */
  else {
    sv_move_sub(wD0); /* Line 944, Address: 0x102cd44 */
  }

} /* Line 947, Address: 0x102cd50 */


void sv_move_sub2() { /* Line 950, Address: 0x102cd60 */
  limmoveflag = 0; /* Line 951, Address: 0x102cd68 */
  sv_move_sub(0); /* Line 952, Address: 0x102cd70 */
} /* Line 953, Address: 0x102cd7c */


void sv_move_sub(unsigned short wD0) { /* Line 956, Address: 0x102cd90 */
  int_union lD1;

  lD1.w.h = 0; /* Line 959, Address: 0x102cd9c */
  lD1.w.l = wD0; /* Line 960, Address: 0x102cda0 */
  lD1.l += scra_v_posit.w.h; /* Line 961, Address: 0x102cda8 */
  if ((short)wD0 > 0) { /* Line 962, Address: 0x102cdc4 */
    scrv_down_ch(lD1); /* Line 963, Address: 0x102cde0 */
  } /* Line 964, Address: 0x102cdec */
  else {
    scrv_up_ch(lD1); /* Line 966, Address: 0x102cdf4 */
  }

} /* Line 969, Address: 0x102ce00 */




void sv_move_minus(unsigned short wD1) { /* Line 974, Address: 0x102ce10 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 978, Address: 0x102ce20 */
  lD1.l <<= 8; /* Line 979, Address: 0x102ce3c */
  lD1.l += scra_v_posit.l; /* Line 980, Address: 0x102ce48 */

  wk = lD1.w.h; /* Line 982, Address: 0x102ce5c */
  lD1.w.h = lD1.w.l; /* Line 983, Address: 0x102ce64 */
  lD1.w.l = wk; /* Line 984, Address: 0x102ce6c */
  scrv_up_ch(lD1); /* Line 985, Address: 0x102ce70 */
} /* Line 986, Address: 0x102ce7c */



void scrv_up_ch(int_union lD1) { /* Line 990, Address: 0x102ce90 */
  if (scralim_up >= lD1.w.l) { /* Line 991, Address: 0x102ce9c */
    if (lD1.w.l < -255) { /* Line 992, Address: 0x102cec4 */
      lD1.w.l &= 2047; /* Line 993, Address: 0x102cedc */
      actwk[0].yposi.w.h &= 32767; /* Line 994, Address: 0x102cee8 */
      scra_v_posit.w.h &= 2047; /* Line 995, Address: 0x102cefc */
      scrb_v_posit.w.h &= 1023; /* Line 996, Address: 0x102cf10 */
    } /* Line 997, Address: 0x102cf24 */
    else {

      lD1.w.l = scralim_up; /* Line 1000, Address: 0x102cf2c */
    }
  }
  scrv_move(lD1); /* Line 1003, Address: 0x102cf38 */

} /* Line 1005, Address: 0x102cf44 */





void sv_move_plus(unsigned short wD1) { /* Line 1011, Address: 0x102cf60 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 1015, Address: 0x102cf70 */
  lD1.w.l = wD1; /* Line 1016, Address: 0x102cf74 */
  lD1.l <<= 8; /* Line 1017, Address: 0x102cf7c */
  lD1.l += scra_v_posit.l; /* Line 1018, Address: 0x102cf88 */

  wk = lD1.w.h; /* Line 1020, Address: 0x102cf9c */
  lD1.w.h = lD1.w.l; /* Line 1021, Address: 0x102cfa4 */
  lD1.w.l = wk; /* Line 1022, Address: 0x102cfac */

  scrv_down_ch(lD1); /* Line 1024, Address: 0x102cfb0 */

} /* Line 1026, Address: 0x102cfbc */



void scrv_down_ch(int_union lD1) { /* Line 1030, Address: 0x102cfd0 */
  if (scralim_down <= lD1.w.l) { /* Line 1031, Address: 0x102cfdc */
    lD1.w.l -= 2048; /* Line 1032, Address: 0x102d004 */
    if (lD1.w.l > 0) { /* Line 1033, Address: 0x102d010 */
      actwk[0].yposi.w.h &= 2047; /* Line 1034, Address: 0x102d024 */
      scra_v_posit.w.h -= 2048; /* Line 1035, Address: 0x102d038 */
      scrb_v_posit.w.h &= 1023; /* Line 1036, Address: 0x102d04c */
    } /* Line 1037, Address: 0x102d060 */
    else {
      lD1.w.l = scralim_down; /* Line 1039, Address: 0x102d068 */
    }
  }
  scrv_move(lD1); /* Line 1042, Address: 0x102d074 */

} /* Line 1044, Address: 0x102d080 */


void scrv_move(int_union lD1) { /* Line 1047, Address: 0x102d090 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1050, Address: 0x102d0a0 */

  wk = lD1.w.h; /* Line 1052, Address: 0x102d0ac */
  lD1.w.h = lD1.w.l; /* Line 1053, Address: 0x102d0b4 */
  lD1.w.l = wk; /* Line 1054, Address: 0x102d0bc */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1056, Address: 0x102d0c0 */
  scra_v_posit.l = lD1.l; /* Line 1057, Address: 0x102d0e8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1060, Address: 0x102d0f4 */
    scra_v_count ^= 16; /* Line 1061, Address: 0x102d128 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1062, Address: 0x102d13c */

      scrflaga.b.h |= 2; /* Line 1064, Address: 0x102d168 */
    } /* Line 1065, Address: 0x102d17c */
    else {
      scrflaga.b.h |= 1; /* Line 1067, Address: 0x102d184 */
    }
  }


} /* Line 1072, Address: 0x102d198 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1076, Address: 0x102d1b0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1079, Address: 0x102d1bc */
  lD0.l += lD4.l; /* Line 1080, Address: 0x102d1cc */
  scrb_h_posit.l = lD0.l; /* Line 1081, Address: 0x102d1dc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1083, Address: 0x102d1e8 */

    scrb_h_count ^= 16; /* Line 1085, Address: 0x102d21c */
    lD0.l -= lD2.l; /* Line 1086, Address: 0x102d230 */
    if ((long int)lD0.l < 0) { /* Line 1087, Address: 0x102d240 */
      scrflagb.b.h |= 4; /* Line 1088, Address: 0x102d254 */
    } /* Line 1089, Address: 0x102d268 */
    else {

      scrflagb.b.h |= 8; /* Line 1092, Address: 0x102d270 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1097, Address: 0x102d284 */
  lD0.l += lD5.l; /* Line 1098, Address: 0x102d294 */
  scrb_h_posit.l = lD0.l; /* Line 1099, Address: 0x102d2a4 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1101, Address: 0x102d2b0 */

    scrb_v_count ^= 16; /* Line 1103, Address: 0x102d2e4 */
    lD0.l -= lD3.l; /* Line 1104, Address: 0x102d2f8 */
    if ((long int)lD0.l < 0) { /* Line 1105, Address: 0x102d308 */
      scrflagb.b.h |= 1; /* Line 1106, Address: 0x102d31c */
    } /* Line 1107, Address: 0x102d330 */
    else {

      scrflagb.b.h |= 2; /* Line 1110, Address: 0x102d338 */
    }
  }


} /* Line 1115, Address: 0x102d34c */






void scrollb_v(unsigned short wD0) { /* Line 1122, Address: 0x102d360 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1125, Address: 0x102d36c */
  scrb_v_posit.w.h = wD0; /* Line 1126, Address: 0x102d378 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1128, Address: 0x102d384 */
    scrb_v_count ^= 16; /* Line 1129, Address: 0x102d3b0 */
    if ((short)wD3 > (short)wD0) { /* Line 1130, Address: 0x102d3c4 */
      scrflagb.b.h |= 1; /* Line 1131, Address: 0x102d3f4 */
    } /* Line 1132, Address: 0x102d408 */
    else {

      scrflagb.b.h |= 2; /* Line 1135, Address: 0x102d410 */
    }
  }


} /* Line 1140, Address: 0x102d424 */



void scrollb_h(int lD4, int flagb) { /* Line 1144, Address: 0x102d440 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1148, Address: 0x102d450 */
  lD0.l = lD2.l + lD4; /* Line 1149, Address: 0x102d45c */
  scrb_h_posit.l = lD0.l; /* Line 1150, Address: 0x102d46c */

  lD1.w.h = lD0.w.l; /* Line 1152, Address: 0x102d478 */
  lD1.w.l = lD0.w.h; /* Line 1153, Address: 0x102d480 */
  lD1.w.l &= 16; /* Line 1154, Address: 0x102d488 */

  bD3 = scrb_h_count; /* Line 1156, Address: 0x102d494 */
  lD1.b.b4 ^= bD3; /* Line 1157, Address: 0x102d4a0 */
  if (!lD1.b.b4) { /* Line 1158, Address: 0x102d4b4 */
    scrb_h_count ^= 16; /* Line 1159, Address: 0x102d4c0 */
    lD0.l -= lD2.l; /* Line 1160, Address: 0x102d4d4 */
    if ((long int)lD0.l < 0) { /* Line 1161, Address: 0x102d4e4 */
      scrflagb.b.h |= flagb; /* Line 1162, Address: 0x102d4f8 */
    } /* Line 1163, Address: 0x102d514 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1166, Address: 0x102d51c */
    }
  }


} /* Line 1171, Address: 0x102d53c */



void scrollc_h(int lD4, int flagc) { /* Line 1175, Address: 0x102d550 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1179, Address: 0x102d560 */
  lD0.l = lD2.l + lD4; /* Line 1180, Address: 0x102d56c */
  scrc_h_posit.l = lD0.l; /* Line 1181, Address: 0x102d57c */

  lD1.w.h = lD0.w.l; /* Line 1183, Address: 0x102d588 */
  lD1.w.l = lD0.w.h; /* Line 1184, Address: 0x102d590 */
  lD1.w.l &= 16; /* Line 1185, Address: 0x102d598 */

  bD3 = scrc_h_count; /* Line 1187, Address: 0x102d5a4 */
  lD1.b.b4 ^= bD3; /* Line 1188, Address: 0x102d5b0 */
  if (!lD1.b.b4) { /* Line 1189, Address: 0x102d5c4 */
    scrc_h_count ^= 16; /* Line 1190, Address: 0x102d5d0 */
    lD0.l -= lD2.l; /* Line 1191, Address: 0x102d5e4 */
    if ((long int)lD0.l < 0) { /* Line 1192, Address: 0x102d5f4 */
      scrflagc.b.h |= flagc; /* Line 1193, Address: 0x102d608 */
    } /* Line 1194, Address: 0x102d624 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1197, Address: 0x102d62c */
    }
  }


} /* Line 1202, Address: 0x102d64c */











void scrollz_h(int lD4, int flagz) { /* Line 1214, Address: 0x102d660 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1218, Address: 0x102d670 */
  lD0.l = lD2.l + lD4; /* Line 1219, Address: 0x102d67c */
  scrz_h_posit.l = lD0.l; /* Line 1220, Address: 0x102d68c */

  lD1.w.h = lD0.w.l; /* Line 1222, Address: 0x102d698 */
  lD1.w.l = lD0.w.h; /* Line 1223, Address: 0x102d6a0 */
  lD1.w.l &= 16; /* Line 1224, Address: 0x102d6a8 */

  bD3 = scrz_h_count; /* Line 1226, Address: 0x102d6b4 */
  lD1.b.b4 ^= bD3; /* Line 1227, Address: 0x102d6c0 */
  if (!lD1.b.b4) { /* Line 1228, Address: 0x102d6d4 */
    scrz_h_count ^= 16; /* Line 1229, Address: 0x102d6e0 */
    lD0.l -= lD2.l; /* Line 1230, Address: 0x102d6f4 */
    if ((long int)lD0.l < 0) { /* Line 1231, Address: 0x102d704 */
      scrflagz.b.h |= flagz; /* Line 1232, Address: 0x102d718 */
    } /* Line 1233, Address: 0x102d734 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1236, Address: 0x102d73c */
    }
  }


} /* Line 1241, Address: 0x102d75c */














void scrollwrtadva() { /* Line 1256, Address: 0x102d770 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1262, Address: 0x102d78c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1263, Address: 0x102d790 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1264, Address: 0x102d79c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1265, Address: 0x102d7a8 */
  pScrFlag = &scrflagb.b.h; /* Line 1266, Address: 0x102d7b0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1267, Address: 0x102d7b8 */







} /* Line 1275, Address: 0x102d7cc */












void scrollwrt() { /* Line 1288, Address: 0x102d7f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1297, Address: 0x102d810 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1298, Address: 0x102d814 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1299, Address: 0x102d820 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1300, Address: 0x102d82c */
  pScrFlag = &scrflagbw.b.h; /* Line 1301, Address: 0x102d834 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1302, Address: 0x102d83c */

  VramBase = 16384; /* Line 1304, Address: 0x102d850 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1305, Address: 0x102d854 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1306, Address: 0x102d860 */
  pMapWk = (unsigned char*)mapwka; /* Line 1307, Address: 0x102d86c */
  pScrFlag = &scrflagaw.b.h; /* Line 1308, Address: 0x102d874 */

  if (*pScrFlag) { /* Line 1310, Address: 0x102d87c */
    if (*pScrFlag & 1) { /* Line 1311, Address: 0x102d888 */
      *pScrFlag &= 254; /* Line 1312, Address: 0x102d89c */

      lD4.l = -16; /* Line 1314, Address: 0x102d8a8 */
      wD5 = 65520; /* Line 1315, Address: 0x102d8b0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1317, Address: 0x102d8b8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1319, Address: 0x102d8d8 */
    }




    if (*pScrFlag & 2) { /* Line 1325, Address: 0x102d904 */
      *pScrFlag &= 253; /* Line 1326, Address: 0x102d918 */

      lD4.l = 224; /* Line 1328, Address: 0x102d924 */
      wD5 = 65520; /* Line 1329, Address: 0x102d92c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1330, Address: 0x102d934 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1332, Address: 0x102d954 */
    }




    if (*pScrFlag & 4) { /* Line 1338, Address: 0x102d980 */
      *pScrFlag &= 251; /* Line 1339, Address: 0x102d994 */

      lD4.l = -16; /* Line 1341, Address: 0x102d9a0 */
      wD5 = 65520; /* Line 1342, Address: 0x102d9a8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1343, Address: 0x102d9b0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1345, Address: 0x102d9d0 */
    }




    if (*pScrFlag & 8) { /* Line 1351, Address: 0x102d9fc */
      *pScrFlag &= 247; /* Line 1352, Address: 0x102da10 */

      lD4.l = -16; /* Line 1354, Address: 0x102da1c */
      wD5 = 320; /* Line 1355, Address: 0x102da24 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1356, Address: 0x102da2c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1358, Address: 0x102da4c */
    }
  }






} /* Line 1367, Address: 0x102da78 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1384, Address: 0x102daa0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1395, Address: 0x102dacc */

  if (*pScrFlag & 1) { /* Line 1397, Address: 0x102dad4 */
    *pScrFlag &= 254; /* Line 1398, Address: 0x102daec */
  } /* Line 1399, Address: 0x102db00 */
  else {
    *pScrFlag &= 254; /* Line 1401, Address: 0x102db08 */

    if (*pScrFlag & 2) { /* Line 1403, Address: 0x102db1c */
      *pScrFlag &= 253; /* Line 1404, Address: 0x102db34 */
      lD4.w.l = 224; /* Line 1405, Address: 0x102db48 */
    } /* Line 1406, Address: 0x102db50 */
    else {
      *pScrFlag &= 253; /* Line 1408, Address: 0x102db58 */
      goto label1; /* Line 1409, Address: 0x102db6c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1414, Address: 0x102db74 */
  wD0 &= 127; /* Line 1415, Address: 0x102dbc4 */
  wD0 = z33cwrttbl[wD0 + 1]; /* Line 1416, Address: 0x102dbcc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1422, Address: 0x102dbec */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1423, Address: 0x102dc0c */
  if (wD0 != 0) { /* Line 1424, Address: 0x102dc30 */
    wD5 = 65520; /* Line 1425, Address: 0x102dc3c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1426, Address: 0x102dc44 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1428, Address: 0x102dc64 */



  } /* Line 1432, Address: 0x102dc90 */
  else {

    wD5 = 0; /* Line 1435, Address: 0x102dc98 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1436, Address: 0x102dc9c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1440, Address: 0x102dcbc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1447, Address: 0x102dce8 */






    lD4.l = -16; /* Line 1454, Address: 0x102dcfc */
    wD5 = 65520; /* Line 1455, Address: 0x102dd04 */
    if (*pScrFlag & 168) { /* Line 1456, Address: 0x102dd0c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1457, Address: 0x102dd24 */
      wD5 = 320; /* Line 1458, Address: 0x102dd44 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1462, Address: 0x102dd4c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1464, Address: 0x102dd7c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1465, Address: 0x102dd88 */



    for (i = 0; i < 16; ++i) { /* Line 1469, Address: 0x102dd98 */
      wD0 = z33cwrttbl[WrtTblCnt++]; /* Line 1470, Address: 0x102dda4 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1471, Address: 0x102ddc4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1472, Address: 0x102ddf0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1473, Address: 0x102de10 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1475, Address: 0x102de34 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1478, Address: 0x102de58 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1480, Address: 0x102de78 */
      }
      lD4.w.l += 16; /* Line 1482, Address: 0x102de8c */
    } /* Line 1483, Address: 0x102de98 */
    *pScrFlag = 0; /* Line 1484, Address: 0x102dea8 */
  }
} /* Line 1486, Address: 0x102deb0 */







void scrollwrtc() {} /* Line 1494, Address: 0x102dee0 */




void scrollwrtz() {} /* Line 1499, Address: 0x102def0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1520, Address: 0x102df00 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1533, Address: 0x102df28 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1536, Address: 0x102df48 */
    pTilePoint->x += 2; /* Line 1537, Address: 0x102df5c */
    if (pTilePoint->x >= 64) { /* Line 1538, Address: 0x102df70 */
      pTilePoint->x -= 64; /* Line 1539, Address: 0x102df84 */
    }
    xOffs += 16; /* Line 1541, Address: 0x102df98 */
  } while (--lpcnt >= 0); /* Line 1542, Address: 0x102dfa4 */
} /* Line 1543, Address: 0x102dfb8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1547, Address: 0x102dfd0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1551, Address: 0x102dff8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1554, Address: 0x102e018 */
    pTilePoint->x += 2; /* Line 1555, Address: 0x102e02c */
    if (pTilePoint->x >= 64) { /* Line 1556, Address: 0x102e040 */
      pTilePoint->x -= 64; /* Line 1557, Address: 0x102e054 */
    }
    xOffs += 16; /* Line 1559, Address: 0x102e068 */
  } while (--lpcnt >= 0); /* Line 1560, Address: 0x102e074 */
} /* Line 1561, Address: 0x102e088 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1580, Address: 0x102e0a0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1584, Address: 0x102e0c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1587, Address: 0x102e0e8 */
    pTilePoint->y += 2; /* Line 1588, Address: 0x102e0fc */
    if (pTilePoint->y >= 32) { /* Line 1589, Address: 0x102e10c */
      pTilePoint->y -= 32; /* Line 1590, Address: 0x102e120 */
    }
    yOffs += 16; /* Line 1592, Address: 0x102e130 */
  } while (--lpcnt >= 0); /* Line 1593, Address: 0x102e13c */
} /* Line 1594, Address: 0x102e150 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1613, Address: 0x102e160 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1619, Address: 0x102e194 */

    base = 1; /* Line 1621, Address: 0x102e1a4 */
  } /* Line 1622, Address: 0x102e1a8 */
  else if (VramBase == 16384) { /* Line 1623, Address: 0x102e1b0 */

    base = 0; /* Line 1625, Address: 0x102e1c0 */
  }
  x = pTilePoint->x; /* Line 1627, Address: 0x102e1c4 */
  y = pTilePoint->y; /* Line 1628, Address: 0x102e1cc */


  frip = BlkIndex & 6144; /* Line 1631, Address: 0x102e1d4 */
  BlkIndex &= 1023; /* Line 1632, Address: 0x102e1dc */
  if (frip == 6144) { /* Line 1633, Address: 0x102e1e8 */

    p0 = 3, p1 = 2; /* Line 1635, Address: 0x102e1f4 */
    p2 = 1, p3 = 0; /* Line 1636, Address: 0x102e1fc */
  } /* Line 1637, Address: 0x102e204 */
  else if (frip & 4096) { /* Line 1638, Address: 0x102e20c */

    p0 = 2, p1 = 3; /* Line 1640, Address: 0x102e218 */
    p2 = 0, p3 = 1; /* Line 1641, Address: 0x102e220 */
  } /* Line 1642, Address: 0x102e228 */
  else if (frip & 2048) { /* Line 1643, Address: 0x102e230 */

    p0 = 1, p1 = 0; /* Line 1645, Address: 0x102e23c */
    p2 = 3, p3 = 2; /* Line 1646, Address: 0x102e244 */
  } /* Line 1647, Address: 0x102e24c */
  else {

    p0 = 0, p1 = 1; /* Line 1650, Address: 0x102e254 */
    p2 = 2, p3 = 3; /* Line 1651, Address: 0x102e25c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1654, Address: 0x102e264 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1655, Address: 0x102e2a8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1656, Address: 0x102e2ec */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1657, Address: 0x102e330 */

} /* Line 1659, Address: 0x102e374 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1677, Address: 0x102e3b0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1678, Address: 0x102e3d0 */
} /* Line 1679, Address: 0x102e3f0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1681, Address: 0x102e400 */
  wH_posiw = 0; /* Line 1682, Address: 0x102e420 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1683, Address: 0x102e424 */
} /* Line 1684, Address: 0x102e444 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1691, Address: 0x102e460 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1697, Address: 0x102e490 */
  yOffs += wV_posiw; /* Line 1698, Address: 0x102e4a0 */





  if ((short)xOffs < 0) /* Line 1704, Address: 0x102e4b0 */
    xOffs = 0; /* Line 1705, Address: 0x102e4cc */
  if ((short)yOffs < 0) /* Line 1706, Address: 0x102e4d0 */
    yOffs = 0; /* Line 1707, Address: 0x102e4ec */
  if ((short)xOffs >= 16384) /* Line 1708, Address: 0x102e4f0 */
    xOffs = 16383; /* Line 1709, Address: 0x102e510 */
  if ((short)yOffs >= 2048) /* Line 1710, Address: 0x102e518 */
    yOffs = 2047; /* Line 1711, Address: 0x102e538 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1712, Address: 0x102e540 */
  if (i < 0) i = 0; /* Line 1713, Address: 0x102e588 */

  ScreenNo = pMapWk[i] & 127; /* Line 1715, Address: 0x102e594 */

  if (ScreenNo) { /* Line 1717, Address: 0x102e5b0 */




    xOffs &= 32767; /* Line 1722, Address: 0x102e5b8 */
    yOffs &= 32767; /* Line 1723, Address: 0x102e5c4 */


    xBlk = xOffs; /* Line 1726, Address: 0x102e5d0 */
    xBlk %= 256; /* Line 1727, Address: 0x102e5d8 */
    xBlk /= 16; /* Line 1728, Address: 0x102e5f8 */
    yBlk = yOffs; /* Line 1729, Address: 0x102e614 */
    yBlk %= 256; /* Line 1730, Address: 0x102e61c */
    yBlk /= 16; /* Line 1731, Address: 0x102e63c */

    lpw = pmapwk; /* Line 1733, Address: 0x102e658 */
    lpw += xBlk; /* Line 1734, Address: 0x102e660 */
    lpw += yBlk * 16; /* Line 1735, Address: 0x102e668 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1736, Address: 0x102e674 */
    *pIndex = *lpw; /* Line 1737, Address: 0x102e68c */

    return 1; /* Line 1739, Address: 0x102e69c */
  }

  *pIndex = 0; /* Line 1742, Address: 0x102e6a8 */
  return 0; /* Line 1743, Address: 0x102e6b0 */
} /* Line 1744, Address: 0x102e6b4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1764, Address: 0x102e6e0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1772, Address: 0x102e708 */
  if (ScreenNo) { /* Line 1773, Address: 0x102e76c */





    xBlk = xOffs; /* Line 1779, Address: 0x102e774 */
    xBlk %= 256; /* Line 1780, Address: 0x102e77c */
    xBlk /= 16; /* Line 1781, Address: 0x102e79c */
    yBlk = yOffs; /* Line 1782, Address: 0x102e7b8 */
    yBlk %= 256; /* Line 1783, Address: 0x102e7c0 */
    yBlk /= 16; /* Line 1784, Address: 0x102e7e0 */


    lpw = pmapwk; /* Line 1787, Address: 0x102e7fc */
    lpw += xBlk; /* Line 1788, Address: 0x102e804 */
    lpw += yBlk * 16; /* Line 1789, Address: 0x102e80c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1790, Address: 0x102e818 */
    *ppBlockNo = lpw; /* Line 1791, Address: 0x102e830 */
    *pIndex = *lpw; /* Line 1792, Address: 0x102e838 */




    return 1; /* Line 1797, Address: 0x102e848 */
  }

  *pIndex = 0; /* Line 1800, Address: 0x102e854 */
  return 0; /* Line 1801, Address: 0x102e85c */
} /* Line 1802, Address: 0x102e860 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1816, Address: 0x102e880 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1823, Address: 0x102e89c */
  pMapWk = (unsigned char*)mapwka; /* Line 1824, Address: 0x102e8a0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1825, Address: 0x102e8a8 */
    *pBlockIndex = BlockNo; /* Line 1826, Address: 0x102e8cc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1827, Address: 0x102e8d8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1828, Address: 0x102e8f0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1829, Address: 0x102e904 */
    }
  }


} /* Line 1834, Address: 0x102e91c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1848, Address: 0x102e940 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1849, Address: 0x102e94c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1850, Address: 0x102e978 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1851, Address: 0x102e9c4 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1852, Address: 0x102e9f0 */

          return 0; /* Line 1854, Address: 0x102ea3c */
        }
      }
    }
  }

  return 1; /* Line 1860, Address: 0x102ea48 */
} /* Line 1861, Address: 0x102ea4c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1878, Address: 0x102ea60 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1879, Address: 0x102ea7c */

} /* Line 1881, Address: 0x102ea98 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1883, Address: 0x102eab0 */
  wH_posiw = 0; /* Line 1884, Address: 0x102eacc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1885, Address: 0x102ead0 */

} /* Line 1887, Address: 0x102eaec */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1889, Address: 0x102eb00 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1890, Address: 0x102eb14 */

} /* Line 1892, Address: 0x102eb30 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1894, Address: 0x102eb40 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1895, Address: 0x102eb5c */

} /* Line 1897, Address: 0x102eb78 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1899, Address: 0x102eb90 */
  xOffs += wH_posiw; /* Line 1900, Address: 0x102eba8 */
  yOffs += wV_posiw; /* Line 1901, Address: 0x102ebb8 */
  yOffs &= 240; /* Line 1902, Address: 0x102ebc8 */
  xOffs &= 496; /* Line 1903, Address: 0x102ebd4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1905, Address: 0x102ebe0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1906, Address: 0x102ec0c */


} /* Line 1909, Address: 0x102ec38 */















void mapwrt() { /* Line 1925, Address: 0x102ec50 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1930, Address: 0x102ec68 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1931, Address: 0x102ec74 */
  pMapWk = (unsigned char*)mapwka; /* Line 1932, Address: 0x102ec80 */
  VramBase = 16384; /* Line 1933, Address: 0x102ec88 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1934, Address: 0x102ec8c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1938, Address: 0x102eca4 */
  VramBase = 24576; /* Line 1939, Address: 0x102ecac */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1940, Address: 0x102ecb0 */

} /* Line 1942, Address: 0x102ecc0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1945, Address: 0x102ece0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1946, Address: 0x102ecf8 */
} /* Line 1947, Address: 0x102ed18 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1952, Address: 0x102ed30 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1956, Address: 0x102ed50 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1959, Address: 0x102ed6c */



    wD4 += 16; /* Line 1963, Address: 0x102ed94 */
  } while ((short)--wD6 >= 0); /* Line 1964, Address: 0x102eda0 */

} /* Line 1966, Address: 0x102edc8 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1971, Address: 0x102ede0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1974, Address: 0x102edfc */
  wD6 = 15; /* Line 1975, Address: 0x102ee04 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1978, Address: 0x102ee0c */

    mapwrt_sub(&z33cwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1980, Address: 0x102ee30 */
    wD4 += 16; /* Line 1981, Address: 0x102ee50 */
  } while ((short)--wD6 >= 0); /* Line 1982, Address: 0x102ee58 */
} /* Line 1983, Address: 0x102ee7c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2009, Address: 0x102eea0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2014, Address: 0x102eec8 */
  wD0 = pWrttbl[wD0]; /* Line 2015, Address: 0x102eed8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2017, Address: 0x102eef4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2018, Address: 0x102ef18 */
  if (wD0) { /* Line 2019, Address: 0x102ef40 */
    wD5 = 65520; /* Line 2020, Address: 0x102ef4c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2021, Address: 0x102ef54 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2024, Address: 0x102ef70 */



  } /* Line 2028, Address: 0x102ef98 */
  else {

    wD5 = 0; /* Line 2031, Address: 0x102efa0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2032, Address: 0x102efa4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2036, Address: 0x102efc0 */
  }





} /* Line 2043, Address: 0x102efe8 */




void mapinit() { /* Line 2048, Address: 0x102f010 */





  mapset(); /* Line 2054, Address: 0x102f018 */


  colorset2(mapinittbl.colorno2); /* Line 2057, Address: 0x102f020 */
  colorset(mapinittbl.colorno2); /* Line 2058, Address: 0x102f034 */






  if (plflag != 0) { /* Line 2065, Address: 0x102f048 */
    enecginit(); /* Line 2066, Address: 0x102f05c */
  }

  if (play_start & 2) { /* Line 2069, Address: 0x102f064 */

    divdevset(); /* Line 2071, Address: 0x102f07c */
  }


} /* Line 2075, Address: 0x102f084 */









void mapset() {} /* Line 2085, Address: 0x102f0a0 */
