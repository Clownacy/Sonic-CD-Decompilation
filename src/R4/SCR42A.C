#include "..\EQU.H"
#include "SCR41C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL4A.H"
#include "SCRCHK4.H"

static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs);

static unsigned char z81awrttbl[129] = {
  0, 2, 2, 2, 2, 2, 2, 2, 2, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4
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
extern unsigned char awasintbl[256];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
















































































void enecginit() {} /* Line 129, Address: 0x1027400 */



void divdevset() {} /* Line 133, Address: 0x1027410 */














































sprite_status* main_chk() {
  if (!main_play) return &actwk[0];  /* Line 181, Address: 0x1027420 */
  else return &actwk[1]; /* Line 182, Address: 0x1027440 */
} /* Line 183, Address: 0x1027448 */


void scr_set() { /* Line 186, Address: 0x1027450 */






  unsigned short scr_dir_tbl[6] = { /* Line 193, Address: 0x102745c */
    4, 0, 7319, 0, 2048, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1027490 */

  i = 0; /* Line 200, Address: 0x10274d8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 201, Address: 0x10274dc */
  scralim_left = scr_dir_tbl[i]; /* Line 202, Address: 0x10274f8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 203, Address: 0x102750c */
  scralim_right = scr_dir_tbl[i]; /* Line 204, Address: 0x1027528 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 205, Address: 0x102753c */
  scralim_up = scr_dir_tbl[i]; /* Line 206, Address: 0x1027558 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 207, Address: 0x102756c */
  scralim_down = scr_dir_tbl[i]; /* Line 208, Address: 0x1027588 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 209, Address: 0x102759c */

  scra_h_keep = scralim_left + 576; /* Line 211, Address: 0x10275b8 */
  scra_h_count = 16; /* Line 212, Address: 0x10275dc */
  scra_v_count = 16; /* Line 213, Address: 0x10275e8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 215, Address: 0x10275f4 */
  scra_hline = 160; /* Line 216, Address: 0x1027610 */

  playposiset(); /* Line 218, Address: 0x102761c */
} /* Line 219, Address: 0x1027624 */



void playposiset() { /* Line 223, Address: 0x1027640 */
  unsigned short endplpositbl[16] = { /* Line 224, Address: 0x1027654 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[2] = { /* Line 234, Address: 0x1027688 */
    80,
    1260
  };
  unsigned char playmapnotbl[4] = { /* Line 238, Address: 0x10276a4 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 246, Address: 0x10276d0 */

    playload(); /* Line 248, Address: 0x10276e4 */
    xWk = actwk[0].xposi.w.h; /* Line 249, Address: 0x10276ec */
    yWk = actwk[0].yposi.w.h; /* Line 250, Address: 0x10276fc */
    if (yWk < 0) yWk = 0; /* Line 251, Address: 0x102770c */
  } /* Line 252, Address: 0x1027720 */
  else {


    if (demoflag.w < 0) { /* Line 256, Address: 0x1027728 */

      i = (enddemono - 1) * 4; /* Line 258, Address: 0x1027740 */
      xWk = actwk[0].xposi.w.h = endplpositbl[i++]; /* Line 259, Address: 0x1027758 */
      yWk = actwk[0].yposi.w.h = endplpositbl[i++]; /* Line 260, Address: 0x102777c */
    } /* Line 261, Address: 0x10277a0 */
    else {


      i = demoflag.w * 4; /* Line 265, Address: 0x10277a8 */
      xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 266, Address: 0x10277bc */
      yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 267, Address: 0x10277e0 */
    }
  }

  if ((unsigned short)xWk > 160) { /* Line 271, Address: 0x1027804 */
    xWk -= 160; /* Line 272, Address: 0x1027818 */
  } /* Line 273, Address: 0x1027824 */
  else {
    xWk = 0; /* Line 275, Address: 0x102782c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 279, Address: 0x1027830 */
    xWk = scralim_right; /* Line 280, Address: 0x1027854 */
  }
  scra_h_posit.w.h = xWk; /* Line 282, Address: 0x1027864 */

  if ((unsigned short)yWk > 96) { /* Line 284, Address: 0x102786c */
    yWk -= 96; /* Line 285, Address: 0x1027880 */
  } /* Line 286, Address: 0x102788c */
  else {
    yWk = 0; /* Line 288, Address: 0x1027894 */
  }

  if (scralim_down < yWk) { /* Line 291, Address: 0x1027898 */
    yWk = scralim_down; /* Line 292, Address: 0x10278bc */
  }

  scra_v_posit.w.h = yWk; /* Line 295, Address: 0x10278cc */


  scrbinit(xWk); /* Line 298, Address: 0x10278d4 */

  i = 0; /* Line 300, Address: 0x10278e0 */
  loopmapno = playmapnotbl[i++]; /* Line 301, Address: 0x10278e4 */
  loopmapno2 = playmapnotbl[i++]; /* Line 302, Address: 0x10278fc */
  ballmapno = playmapnotbl[i++]; /* Line 303, Address: 0x1027914 */
  ballmapno2 = playmapnotbl[i++]; /* Line 304, Address: 0x102792c */


} /* Line 307, Address: 0x1027944 */



void scrbinit(short yWk) { /* Line 311, Address: 0x1027960 */
  uint_union data;


  data.l = 0; /* Line 315, Address: 0x1027968 */
  data.w.l = scra_v_posit.w.h; /* Line 316, Address: 0x102796c */
  data.w.l >>= 1; /* Line 317, Address: 0x1027978 */

  scrb_v_posit.w.h = data.w.l; /* Line 319, Address: 0x1027984 */
  scrb_v_posit.w.l = 0; /* Line 320, Address: 0x1027990 */
  scrc_v_posit.w.h = data.w.l; /* Line 321, Address: 0x1027998 */
  scrz_v_posit.w.h = data.w.l; /* Line 322, Address: 0x10279a4 */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 324, Address: 0x10279b0 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 325, Address: 0x10279d4 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 326, Address: 0x1027a00 */




} /* Line 331, Address: 0x1027a2c */



void scroll() { /* Line 335, Address: 0x1027a40 */
  uint_union data;
  int_union temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 341, Address: 0x1027a50 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 344, Address: 0x1027a60 */
  scrchk(); /* Line 345, Address: 0x1027a8c */
  scroll_h(); /* Line 346, Address: 0x1027a94 */
  scroll_v(); /* Line 347, Address: 0x1027a9c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 349, Address: 0x1027aa4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 350, Address: 0x1027ab4 */



  temp1.l = (long int)(scra_hz << 2) * 3; /* Line 354, Address: 0x1027ac4 */
  temp2.l = scra_vz << 7; /* Line 355, Address: 0x1027af4 */
  scrollb_hv(&temp1, &temp2); /* Line 356, Address: 0x1027b0c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 358, Address: 0x1027b1c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 359, Address: 0x1027b2c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 360, Address: 0x1027b3c */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 362, Address: 0x1027b4c */
  scrflagz.b.h = 0; /* Line 363, Address: 0x1027b80 */
  scrflagc.b.h = 0; /* Line 364, Address: 0x1027b88 */

  hsCount = 0; /* Line 366, Address: 0x1027b90 */
  for (i = 0; i < 192; ++i) { /* Line 367, Address: 0x1027b94 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 370, Address: 0x1027ba0 */
    ++hsCount; /* Line 371, Address: 0x1027bd0 */
  } /* Line 372, Address: 0x1027bd4 */

  data.w.l = -scra_h_posit.w.h; /* Line 374, Address: 0x1027be4 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 375, Address: 0x1027c00 */
  data.w.l = scrb_v_posit.w.h; /* Line 376, Address: 0x1027c24 */
  data.w.l &= 1016; /* Line 377, Address: 0x1027c30 */
  data.w.l >>= 2; /* Line 378, Address: 0x1027c3c */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 379, Address: 0x1027c48 */

} /* Line 381, Address: 0x1027c98 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 419, Address: 0x1027cb0 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 426, Address: 0x1027ccc */
  data1.b.l = waterdirec.b.h; /* Line 427, Address: 0x1027cd4 */
  data2.b.l = waterdirec.b.h; /* Line 428, Address: 0x1027ce0 */
  waterdirec.w += 128; /* Line 429, Address: 0x1027cec */
  data1.w += scrb_v_posit.w.h; /* Line 430, Address: 0x1027d00 */
  data1.b.h = 0; /* Line 431, Address: 0x1027d14 */
  data2.w += scra_v_posit.w.h; /* Line 432, Address: 0x1027d18 */
  data2.b.h = 0; /* Line 433, Address: 0x1027d2c */

  VPosi &= 7; /* Line 435, Address: 0x1027d30 */
  hsw.w.l = hscrollwork[offs++]; /* Line 436, Address: 0x1027d3c */
  avp = scra_v_posit.w.h; /* Line 437, Address: 0x1027d64 */
  i = 232; /* Line 438, Address: 0x1027d74 */


  do {
    if (avp > waterposi) { /* Line 442, Address: 0x1027d78 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 447, Address: 0x1027d9c */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 448, Address: 0x1027da4 */
        ++pHScrollBuff; /* Line 449, Address: 0x1027df4 */
        ++data1.b.l; /* Line 450, Address: 0x1027df8 */
        ++data2.b.l; /* Line 451, Address: 0x1027e04 */
        ++VPosi; /* Line 452, Address: 0x1027e10 */
        if (VPosi == 8) { /* Line 453, Address: 0x1027e1c */

          VPosi = 0; /* Line 455, Address: 0x1027e34 */
          hsw.w.l = hscrollwork[offs++]; /* Line 456, Address: 0x1027e38 */
        }
      } while (--i > 0); /* Line 458, Address: 0x1027e60 */

      return; /* Line 460, Address: 0x1027e6c */
    }
    pHScrollBuff->l = hsw.l; /* Line 462, Address: 0x1027e74 */
    ++pHScrollBuff; /* Line 463, Address: 0x1027e7c */
    ++avp; /* Line 464, Address: 0x1027e80 */
    ++data1.b.l; /* Line 465, Address: 0x1027e8c */
    ++data2.b.l; /* Line 466, Address: 0x1027e98 */
    ++VPosi; /* Line 467, Address: 0x1027ea4 */
    if (VPosi == 8) { /* Line 468, Address: 0x1027eb0 */

      VPosi = 0; /* Line 470, Address: 0x1027ec8 */
      hsw.w.l = hscrollwork[offs++]; /* Line 471, Address: 0x1027ecc */
    }
  } while (--i > 0); /* Line 473, Address: 0x1027ef4 */

} /* Line 475, Address: 0x1027f00 */











void scroll_h() { /* Line 487, Address: 0x1027f20 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 490, Address: 0x1027f2c */
  scrh_move(); /* Line 491, Address: 0x1027f38 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 492, Address: 0x1027f40 */
    scra_h_count ^= 16; /* Line 493, Address: 0x1027f74 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 494, Address: 0x1027f88 */
      scrflaga.b.h |= 4; /* Line 495, Address: 0x1027fb4 */
    } /* Line 496, Address: 0x1027fc8 */
    else {

      scrflaga.b.h |= 8; /* Line 499, Address: 0x1027fd0 */
    }
  }


} /* Line 504, Address: 0x1027fe4 */

void scrh_move() { /* Line 506, Address: 0x1028000 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 509, Address: 0x102800c */
  wD0 -= scra_h_posit.w.h; /* Line 510, Address: 0x1028018 */
  wD0 -= scra_hline; /* Line 511, Address: 0x102802c */
  if (wD0 == 0) { /* Line 512, Address: 0x1028040 */

    scra_hz = 0; /* Line 514, Address: 0x102804c */
  } /* Line 515, Address: 0x1028054 */
  else if ((short)wD0 < 0) { /* Line 516, Address: 0x102805c */
    left_check(wD0); /* Line 517, Address: 0x1028074 */
  } /* Line 518, Address: 0x1028080 */
  else {
    right_check(wD0); /* Line 520, Address: 0x1028088 */
  }

} /* Line 523, Address: 0x1028094 */


void right_check(unsigned short wD0) { /* Line 526, Address: 0x10280b0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 529, Address: 0x10280bc */
    wD0 = 16; /* Line 530, Address: 0x10280dc */
  }

  wD0 += scra_h_posit.w.h; /* Line 533, Address: 0x10280e4 */
  if (scralim_right < (short)wD0) { /* Line 534, Address: 0x10280fc */
    wD0 = scralim_right; /* Line 535, Address: 0x102812c */
  }

  wD1 = wD0; /* Line 538, Address: 0x1028138 */
  wD1 -= scra_h_posit.w.h; /* Line 539, Address: 0x1028140 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 540, Address: 0x1028154 */
  scra_h_posit.w.h = wD0; /* Line 541, Address: 0x1028184 */
  scra_hz = wD1; /* Line 542, Address: 0x1028190 */

} /* Line 544, Address: 0x1028198 */


void left_check(unsigned short wD0) { /* Line 547, Address: 0x10281b0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 550, Address: 0x10281bc */
    wD0 = -16; /* Line 551, Address: 0x10281dc */
  }

  wD0 += scra_h_posit.w.h; /* Line 554, Address: 0x10281e4 */
  if (scralim_left > (short)wD0) { /* Line 555, Address: 0x10281fc */
    wD0 = scralim_left; /* Line 556, Address: 0x102822c */
  }

  wD1 = wD0; /* Line 559, Address: 0x1028238 */
  wD1 -= scra_h_posit.w.h; /* Line 560, Address: 0x1028240 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 561, Address: 0x1028254 */
  scra_h_posit.w.h = wD0; /* Line 562, Address: 0x1028284 */
  scra_hz = wD1; /* Line 563, Address: 0x1028290 */

} /* Line 565, Address: 0x1028298 */


















void scroll_v() { /* Line 584, Address: 0x10282b0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 587, Address: 0x10282bc */
  if (actwk[0].cddat & 4) { /* Line 588, Address: 0x10282e8 */
    wD0 -= 5; /* Line 589, Address: 0x1028300 */
  }

  if (actwk[0].cddat & 2) { /* Line 592, Address: 0x1028308 */
    wD0 += 32; /* Line 593, Address: 0x1028320 */
    if ((unsigned short)scra_vline > wD0) { /* Line 594, Address: 0x1028328 */
      wD0 -= scra_vline; /* Line 595, Address: 0x1028348 */
      sv_move_main2(wD0); /* Line 596, Address: 0x102835c */
      return; /* Line 597, Address: 0x1028368 */
    }
    wD0 -= scra_vline; /* Line 599, Address: 0x1028370 */
    if (wD0 >= 64) { /* Line 600, Address: 0x1028384 */
      wD0 -= 64; /* Line 601, Address: 0x1028394 */
      sv_move_main2(wD0); /* Line 602, Address: 0x102839c */
      return; /* Line 603, Address: 0x10283a8 */
    }
    wD0 -= 64; /* Line 605, Address: 0x10283b0 */
    if (limmoveflag == 0) goto label1; /* Line 606, Address: 0x10283b8 */
    sv_move_sub2(); /* Line 607, Address: 0x10283cc */
    return; /* Line 608, Address: 0x10283d4 */
  }




  wD0 -= scra_vline; /* Line 614, Address: 0x10283dc */
  if (wD0) { /* Line 615, Address: 0x10283f0 */
    sv_move_main(wD0); /* Line 616, Address: 0x10283f8 */
    return; /* Line 617, Address: 0x1028404 */
  }
  if (limmoveflag == 0) { /* Line 619, Address: 0x102840c */
    sv_move_sub2(); /* Line 620, Address: 0x1028420 */
    return; /* Line 621, Address: 0x1028428 */
  }


label1:
  scra_vz = 0; /* Line 626, Address: 0x1028430 */

} /* Line 628, Address: 0x1028438 */





void sv_move_main(unsigned short wD0) { /* Line 634, Address: 0x1028450 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 637, Address: 0x1028460 */
    sv_move_main1(wD0); /* Line 638, Address: 0x102847c */
  } /* Line 639, Address: 0x1028488 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 642, Address: 0x1028490 */
    if ((short)wD1 < 0) { /* Line 643, Address: 0x102849c */
      wD1 = -(short)wD1; /* Line 644, Address: 0x10284b4 */
    }

    if (wD1 >= 2048) { /* Line 647, Address: 0x10284d0 */
      sv_move_main2(wD0); /* Line 648, Address: 0x10284e0 */
    } /* Line 649, Address: 0x10284ec */
    else {
      if ((short)wD0 > 6) { /* Line 651, Address: 0x10284f4 */
        sv_move_plus(1536); /* Line 652, Address: 0x1028514 */
      } /* Line 653, Address: 0x1028520 */
      else if ((short)wD0 < -6) { /* Line 654, Address: 0x1028528 */
        sv_move_minus(1536); /* Line 655, Address: 0x1028548 */
      } /* Line 656, Address: 0x1028554 */
      else {
        sv_move_sub(wD0); /* Line 658, Address: 0x102855c */
      }
    }
  }
} /* Line 662, Address: 0x1028568 */



void sv_move_main1(unsigned short wD0) { /* Line 666, Address: 0x1028580 */

  if ((short)wD0 > 2) { /* Line 668, Address: 0x102858c */
    sv_move_plus(512); /* Line 669, Address: 0x10285ac */
  } /* Line 670, Address: 0x10285b8 */
  else if ((short)wD0 < -2) { /* Line 671, Address: 0x10285c0 */
    sv_move_minus(512); /* Line 672, Address: 0x10285e0 */
  } /* Line 673, Address: 0x10285ec */
  else {
    sv_move_sub(wD0); /* Line 675, Address: 0x10285f4 */
  }

} /* Line 678, Address: 0x1028600 */


void sv_move_main2(unsigned short wD0) { /* Line 681, Address: 0x1028610 */

  if ((short)wD0 > 16) { /* Line 683, Address: 0x102861c */
    sv_move_plus(4096); /* Line 684, Address: 0x102863c */
  } /* Line 685, Address: 0x1028648 */
  else if ((short)wD0 < -16) { /* Line 686, Address: 0x1028650 */
    sv_move_minus(4096); /* Line 687, Address: 0x1028670 */
  } /* Line 688, Address: 0x102867c */
  else {
    sv_move_sub(wD0); /* Line 690, Address: 0x1028684 */
  }

} /* Line 693, Address: 0x1028690 */


void sv_move_sub2() { /* Line 696, Address: 0x10286a0 */
  limmoveflag = 0; /* Line 697, Address: 0x10286a8 */
  sv_move_sub(0); /* Line 698, Address: 0x10286b0 */
} /* Line 699, Address: 0x10286bc */


void sv_move_sub(unsigned short wD0) { /* Line 702, Address: 0x10286d0 */
  int_union lD1;

  lD1.w.h = 0; /* Line 705, Address: 0x10286dc */
  lD1.w.l = wD0; /* Line 706, Address: 0x10286e0 */
  lD1.l += scra_v_posit.w.h; /* Line 707, Address: 0x10286e8 */
  if ((short)wD0 > 0) { /* Line 708, Address: 0x1028704 */
    scrv_down_ch(lD1); /* Line 709, Address: 0x1028720 */
  } /* Line 710, Address: 0x102872c */
  else {
    scrv_up_ch(lD1); /* Line 712, Address: 0x1028734 */
  }

} /* Line 715, Address: 0x1028740 */




void sv_move_minus(unsigned short wD1) { /* Line 720, Address: 0x1028750 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 724, Address: 0x1028760 */
  lD1.l <<= 8; /* Line 725, Address: 0x102877c */
  lD1.l += scra_v_posit.l; /* Line 726, Address: 0x1028788 */

  wk = lD1.w.h; /* Line 728, Address: 0x102879c */
  lD1.w.h = lD1.w.l; /* Line 729, Address: 0x10287a4 */
  lD1.w.l = wk; /* Line 730, Address: 0x10287ac */
  scrv_up_ch(lD1); /* Line 731, Address: 0x10287b0 */
} /* Line 732, Address: 0x10287bc */



void scrv_up_ch(int_union lD1) { /* Line 736, Address: 0x10287d0 */
  if (scralim_up >= lD1.w.l) { /* Line 737, Address: 0x10287dc */
    if (lD1.w.l <= 0) { /* Line 738, Address: 0x1028804 */
      lD1.w.l += 2048; /* Line 739, Address: 0x1028818 */
      actwk[0].yposi.w.h += 2048; /* Line 740, Address: 0x1028824 */
      scra_v_posit.w.h += 2048; /* Line 741, Address: 0x1028838 */
      scrb_v_posit.w.h &= 1023; /* Line 742, Address: 0x102884c */
    } /* Line 743, Address: 0x1028860 */
    else {

      lD1.w.l = scralim_up; /* Line 746, Address: 0x1028868 */
    }
  }
  scrv_move(lD1); /* Line 749, Address: 0x1028874 */

} /* Line 751, Address: 0x1028880 */





void sv_move_plus(unsigned short wD1) { /* Line 757, Address: 0x1028890 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 761, Address: 0x10288a0 */
  lD1.w.l = wD1; /* Line 762, Address: 0x10288a4 */
  lD1.l <<= 8; /* Line 763, Address: 0x10288ac */
  lD1.l += scra_v_posit.l; /* Line 764, Address: 0x10288b8 */

  wk = lD1.w.h; /* Line 766, Address: 0x10288cc */
  lD1.w.h = lD1.w.l; /* Line 767, Address: 0x10288d4 */
  lD1.w.l = wk; /* Line 768, Address: 0x10288dc */

  scrv_down_ch(lD1); /* Line 770, Address: 0x10288e0 */

} /* Line 772, Address: 0x10288ec */



void scrv_down_ch(int_union lD1) { /* Line 776, Address: 0x1028900 */
  if (scralim_down <= lD1.w.l) { /* Line 777, Address: 0x102890c */
    lD1.w.l -= 2048; /* Line 778, Address: 0x1028934 */
    if (lD1.w.l > 0) { /* Line 779, Address: 0x1028940 */
      actwk[0].yposi.w.h &= 2047; /* Line 780, Address: 0x1028954 */
      scra_v_posit.w.h -= 2048; /* Line 781, Address: 0x1028968 */
      scrb_v_posit.w.h &= 1023; /* Line 782, Address: 0x102897c */
    } /* Line 783, Address: 0x1028990 */
    else {
      lD1.w.l = scralim_down; /* Line 785, Address: 0x1028998 */
    }
  }
  scrv_move(lD1); /* Line 788, Address: 0x10289a4 */

} /* Line 790, Address: 0x10289b0 */


void scrv_move(int_union lD1) { /* Line 793, Address: 0x10289c0 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 796, Address: 0x10289d0 */

  wk = lD1.w.h; /* Line 798, Address: 0x10289dc */
  lD1.w.h = lD1.w.l; /* Line 799, Address: 0x10289e4 */
  lD1.w.l = wk; /* Line 800, Address: 0x10289ec */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 802, Address: 0x10289f0 */
  scra_v_posit.l = lD1.l; /* Line 803, Address: 0x1028a18 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 806, Address: 0x1028a24 */
    scra_v_count ^= 16; /* Line 807, Address: 0x1028a58 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 808, Address: 0x1028a6c */

      scrflaga.b.h |= 2; /* Line 810, Address: 0x1028a98 */
    } /* Line 811, Address: 0x1028aac */
    else {
      scrflaga.b.h |= 1; /* Line 813, Address: 0x1028ab4 */
    }
  }


} /* Line 818, Address: 0x1028ac8 */



void scrollb_hv(int_union* lD4, int_union* lD5) { /* Line 822, Address: 0x1028ae0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 825, Address: 0x1028aec */
  lD0.l += lD4->l; /* Line 826, Address: 0x1028afc */
  scrb_h_posit.l = lD0.l; /* Line 827, Address: 0x1028b10 */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 829, Address: 0x1028b1c */

    scrb_h_count ^= 16; /* Line 831, Address: 0x1028b50 */
    lD0.l -= lD2.l; /* Line 832, Address: 0x1028b64 */
    if ((long int)lD0.l < 0) { /* Line 833, Address: 0x1028b74 */
      scrflagb.b.h |= 4; /* Line 834, Address: 0x1028b88 */
    } /* Line 835, Address: 0x1028b9c */
    else {

      scrflagb.b.h |= 8; /* Line 838, Address: 0x1028ba4 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 843, Address: 0x1028bb8 */
  lD0.l += lD5->l; /* Line 844, Address: 0x1028bc8 */

  scrb_v_posit.l = lD0.l; /* Line 846, Address: 0x1028bdc */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 848, Address: 0x1028be8 */

    scrb_v_count ^= 16; /* Line 850, Address: 0x1028c1c */
    lD0.l -= lD3.l; /* Line 851, Address: 0x1028c30 */
    if ((long int)lD0.l < 0) { /* Line 852, Address: 0x1028c40 */
      scrflagb.b.h |= 1; /* Line 853, Address: 0x1028c54 */
    } /* Line 854, Address: 0x1028c68 */
    else {

      scrflagb.b.h |= 2; /* Line 857, Address: 0x1028c70 */
    }
  }


} /* Line 862, Address: 0x1028c84 */






void scrollb_v(unsigned short wD0) { /* Line 869, Address: 0x1028c90 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 872, Address: 0x1028c9c */
  scrb_v_posit.w.h = wD0; /* Line 873, Address: 0x1028ca8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 875, Address: 0x1028cb4 */
    scrb_v_count ^= 16; /* Line 876, Address: 0x1028ce0 */
    if ((short)wD3 > (short)wD0) { /* Line 877, Address: 0x1028cf4 */
      scrflagb.b.h |= 1; /* Line 878, Address: 0x1028d24 */
    } /* Line 879, Address: 0x1028d38 */
    else {

      scrflagb.b.h |= 2; /* Line 882, Address: 0x1028d40 */
    }
  }


} /* Line 887, Address: 0x1028d54 */



void scrollb_h(int lD4, int flagb) { /* Line 891, Address: 0x1028d70 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 895, Address: 0x1028d80 */
  lD0.l = lD2.l + lD4; /* Line 896, Address: 0x1028d8c */
  scrb_h_posit.l = lD0.l; /* Line 897, Address: 0x1028d9c */

  lD1.w.h = lD0.w.l; /* Line 899, Address: 0x1028da8 */
  lD1.w.l = lD0.w.h; /* Line 900, Address: 0x1028db0 */
  lD1.w.l &= 16; /* Line 901, Address: 0x1028db8 */

  bD3 = scrb_h_count; /* Line 903, Address: 0x1028dc4 */
  lD1.b.b4 ^= bD3; /* Line 904, Address: 0x1028dd0 */
  if (!lD1.b.b4) { /* Line 905, Address: 0x1028de4 */
    scrb_h_count ^= 16; /* Line 906, Address: 0x1028df0 */
    lD0.l -= lD2.l; /* Line 907, Address: 0x1028e04 */
    if ((long int)lD0.l < 0) { /* Line 908, Address: 0x1028e14 */
      scrflagb.b.h |= flagb; /* Line 909, Address: 0x1028e28 */
    } /* Line 910, Address: 0x1028e44 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 913, Address: 0x1028e4c */
    }
  }


} /* Line 918, Address: 0x1028e6c */


void scrollc_h(int lD4, int flagc) { /* Line 921, Address: 0x1028e80 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 925, Address: 0x1028e90 */
  lD0.l = lD2.l + lD4; /* Line 926, Address: 0x1028e9c */
  scrc_h_posit.l = lD0.l; /* Line 927, Address: 0x1028eac */

  lD1.w.h = lD0.w.l; /* Line 929, Address: 0x1028eb8 */
  lD1.w.l = lD0.w.h; /* Line 930, Address: 0x1028ec0 */
  lD1.w.l &= 16; /* Line 931, Address: 0x1028ec8 */

  bD3 = scrc_h_count; /* Line 933, Address: 0x1028ed4 */
  lD1.b.b4 ^= bD3; /* Line 934, Address: 0x1028ee0 */
  if (!lD1.b.b4) { /* Line 935, Address: 0x1028ef4 */
    scrc_h_count ^= 16; /* Line 936, Address: 0x1028f00 */
    lD0.l -= lD2.l; /* Line 937, Address: 0x1028f14 */
    if ((long int)lD0.l < 0) { /* Line 938, Address: 0x1028f24 */
      scrflagc.b.h |= flagc; /* Line 939, Address: 0x1028f38 */
    } /* Line 940, Address: 0x1028f54 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 943, Address: 0x1028f5c */
    }
  }


} /* Line 948, Address: 0x1028f7c */











void scrollz_h(int lD4, int flagz) { /* Line 960, Address: 0x1028f90 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 964, Address: 0x1028fa0 */
  lD0.l = lD2.l + lD4; /* Line 965, Address: 0x1028fac */
  scrz_h_posit.l = lD0.l; /* Line 966, Address: 0x1028fbc */

  lD1.w.h = lD0.w.l; /* Line 968, Address: 0x1028fc8 */
  lD1.w.l = lD0.w.h; /* Line 969, Address: 0x1028fd0 */
  lD1.w.l &= 16; /* Line 970, Address: 0x1028fd8 */

  bD3 = scrz_h_count; /* Line 972, Address: 0x1028fe4 */
  lD1.b.b4 ^= bD3; /* Line 973, Address: 0x1028ff0 */
  if (!lD1.b.b4) { /* Line 974, Address: 0x1029004 */
    scrz_h_count ^= 16; /* Line 975, Address: 0x1029010 */
    lD0.l -= lD2.l; /* Line 976, Address: 0x1029024 */
    if ((long int)lD0.l < 0) { /* Line 977, Address: 0x1029034 */
      scrflagz.b.h |= flagz; /* Line 978, Address: 0x1029048 */
    } /* Line 979, Address: 0x1029064 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 982, Address: 0x102906c */
    }
  }


} /* Line 987, Address: 0x102908c */













void scrollwrtadva() { /* Line 1001, Address: 0x10290a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1007, Address: 0x10290bc */
  wH_posiw = scrb_h_posit.w.h; /* Line 1008, Address: 0x10290c0 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1009, Address: 0x10290cc */
  pMapWk = (unsigned char*)mapwkb; /* Line 1010, Address: 0x10290d8 */
  pScrFlag = &scrflagb.b.h; /* Line 1011, Address: 0x10290e0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1012, Address: 0x10290e8 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1014, Address: 0x1029104 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1015, Address: 0x1029110 */
  pScrFlag = &scrflagc.b.h; /* Line 1016, Address: 0x102911c */
  scrollwrtc(); /* Line 1017, Address: 0x1029124 */

} /* Line 1019, Address: 0x102912c */












void scrollwrt() { /* Line 1032, Address: 0x1029150 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1041, Address: 0x1029170 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1042, Address: 0x1029174 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1043, Address: 0x1029180 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1044, Address: 0x102918c */
  pScrFlag = &scrflagbw.b.h; /* Line 1045, Address: 0x1029194 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1046, Address: 0x102919c */

  VramBase = 16384; /* Line 1048, Address: 0x10291b8 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1049, Address: 0x10291bc */
  wV_posiw = scra_v_posiw.w.h; /* Line 1050, Address: 0x10291c8 */
  pMapWk = (unsigned char*)mapwka; /* Line 1051, Address: 0x10291d4 */
  pScrFlag = &scrflagaw.b.h; /* Line 1052, Address: 0x10291dc */

  if (*pScrFlag) { /* Line 1054, Address: 0x10291e4 */
    if (*pScrFlag & 1) { /* Line 1055, Address: 0x10291f0 */
      *pScrFlag &= 254; /* Line 1056, Address: 0x1029204 */

      lD4.l = -16; /* Line 1058, Address: 0x1029210 */
      wD5 = 65520; /* Line 1059, Address: 0x1029218 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1061, Address: 0x1029220 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1063, Address: 0x1029240 */
    }




    if (*pScrFlag & 2) { /* Line 1069, Address: 0x102926c */
      *pScrFlag &= 253; /* Line 1070, Address: 0x1029280 */

      lD4.l = 224; /* Line 1072, Address: 0x102928c */
      wD5 = 65520; /* Line 1073, Address: 0x1029294 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1074, Address: 0x102929c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1076, Address: 0x10292bc */
    }




    if (*pScrFlag & 4) { /* Line 1082, Address: 0x10292e8 */
      *pScrFlag &= 251; /* Line 1083, Address: 0x10292fc */

      lD4.l = -16; /* Line 1085, Address: 0x1029308 */
      wD5 = 65520; /* Line 1086, Address: 0x1029310 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1087, Address: 0x1029318 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1089, Address: 0x1029338 */
    }




    if (*pScrFlag & 8) { /* Line 1095, Address: 0x1029364 */
      *pScrFlag &= 247; /* Line 1096, Address: 0x1029378 */

      lD4.l = -16; /* Line 1098, Address: 0x1029384 */
      wD5 = 320; /* Line 1099, Address: 0x102938c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1100, Address: 0x1029394 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1102, Address: 0x10293b4 */
    }
  }






} /* Line 1111, Address: 0x10293e0 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1128, Address: 0x1029410 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1133, Address: 0x1029430 */
    if (*pScrFlag & 1) { /* Line 1134, Address: 0x1029440 */
      *pScrFlag &= 254; /* Line 1135, Address: 0x1029458 */

      lD4.l = -16; /* Line 1137, Address: 0x102946c */
      wD5 = 65520; /* Line 1138, Address: 0x1029474 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1140, Address: 0x102947c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1142, Address: 0x102949c */
    }




    if (*pScrFlag & 2) { /* Line 1148, Address: 0x10294c8 */
      *pScrFlag &= 253; /* Line 1149, Address: 0x10294e0 */

      lD4.l = 224; /* Line 1151, Address: 0x10294f4 */
      wD5 = 65520; /* Line 1152, Address: 0x10294fc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1153, Address: 0x1029504 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1155, Address: 0x1029524 */
    }




    if (*pScrFlag & 4) { /* Line 1161, Address: 0x1029550 */
      *pScrFlag &= 251; /* Line 1162, Address: 0x1029568 */

      lD4.l = -16; /* Line 1164, Address: 0x102957c */
      wD5 = 65520; /* Line 1165, Address: 0x1029584 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1166, Address: 0x102958c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1168, Address: 0x10295ac */
    }




    if (*pScrFlag & 8) { /* Line 1174, Address: 0x10295d8 */
      *pScrFlag &= 247; /* Line 1175, Address: 0x10295f0 */

      lD4.l = -16; /* Line 1177, Address: 0x1029604 */
      wD5 = 320; /* Line 1178, Address: 0x102960c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1179, Address: 0x1029614 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1181, Address: 0x1029634 */
    }
  }






} /* Line 1190, Address: 0x1029660 */






void scrollwrtc() {} /* Line 1197, Address: 0x1029680 */




void scrollwrtz() {} /* Line 1202, Address: 0x1029690 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1220, Address: 0x10296a0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1233, Address: 0x10296c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1236, Address: 0x10296e8 */
    pTilePoint->x += 2; /* Line 1237, Address: 0x10296fc */
    if (pTilePoint->x >= 64) { /* Line 1238, Address: 0x1029710 */
      pTilePoint->x -= 64; /* Line 1239, Address: 0x1029724 */
    }
    xOffs += 16; /* Line 1241, Address: 0x1029738 */
  } while (--lpcnt >= 0); /* Line 1242, Address: 0x1029744 */
} /* Line 1243, Address: 0x1029758 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1247, Address: 0x1029770 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1251, Address: 0x1029798 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1254, Address: 0x10297b8 */
    pTilePoint->x += 2; /* Line 1255, Address: 0x10297cc */
    if (pTilePoint->x >= 64) { /* Line 1256, Address: 0x10297e0 */
      pTilePoint->x -= 64; /* Line 1257, Address: 0x10297f4 */
    }
    xOffs += 16; /* Line 1259, Address: 0x1029808 */
  } while (--lpcnt >= 0); /* Line 1260, Address: 0x1029814 */
} /* Line 1261, Address: 0x1029828 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1281, Address: 0x1029840 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1285, Address: 0x1029868 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1288, Address: 0x1029888 */
    pTilePoint->y += 2; /* Line 1289, Address: 0x102989c */
    if (pTilePoint->y >= 32) { /* Line 1290, Address: 0x10298ac */
      pTilePoint->y -= 32; /* Line 1291, Address: 0x10298c0 */
    }
    yOffs += 16; /* Line 1293, Address: 0x10298d0 */
  } while (--lpcnt >= 0); /* Line 1294, Address: 0x10298dc */
} /* Line 1295, Address: 0x10298f0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1314, Address: 0x1029900 */
  int base = 0; /* Line 1315, Address: 0x1029934 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1320, Address: 0x1029938 */

    base = 1; /* Line 1322, Address: 0x1029948 */
  } /* Line 1323, Address: 0x102994c */
  else if (VramBase == 16384) { /* Line 1324, Address: 0x1029954 */

    base = 0; /* Line 1326, Address: 0x1029964 */
  }
  x = pTilePoint->x; /* Line 1328, Address: 0x1029968 */
  y = pTilePoint->y; /* Line 1329, Address: 0x1029970 */


  frip = BlkIndex & 6144; /* Line 1332, Address: 0x1029978 */
  BlkIndex &= 1023; /* Line 1333, Address: 0x1029980 */
  if (frip == 6144) { /* Line 1334, Address: 0x102998c */

    p0 = 3, p1 = 2; /* Line 1336, Address: 0x1029998 */
    p2 = 1, p3 = 0; /* Line 1337, Address: 0x10299a0 */
  } /* Line 1338, Address: 0x10299a8 */
  else if (frip & 4096) { /* Line 1339, Address: 0x10299b0 */

    p0 = 2, p1 = 3; /* Line 1341, Address: 0x10299bc */
    p2 = 0, p3 = 1; /* Line 1342, Address: 0x10299c4 */
  } /* Line 1343, Address: 0x10299cc */
  else if (frip & 2048) { /* Line 1344, Address: 0x10299d4 */

    p0 = 1, p1 = 0; /* Line 1346, Address: 0x10299e0 */
    p2 = 3, p3 = 2; /* Line 1347, Address: 0x10299e8 */
  } /* Line 1348, Address: 0x10299f0 */
  else {

    p0 = 0, p1 = 1; /* Line 1351, Address: 0x10299f8 */
    p2 = 2, p3 = 3; /* Line 1352, Address: 0x1029a00 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1355, Address: 0x1029a08 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1356, Address: 0x1029a4c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1357, Address: 0x1029a90 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1358, Address: 0x1029ad4 */

} /* Line 1360, Address: 0x1029b18 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1378, Address: 0x1029b50 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1379, Address: 0x1029b70 */
} /* Line 1380, Address: 0x1029b90 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1382, Address: 0x1029ba0 */
  wH_posiw = 0; /* Line 1383, Address: 0x1029bc0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1384, Address: 0x1029bc4 */
} /* Line 1385, Address: 0x1029be4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1392, Address: 0x1029c00 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1398, Address: 0x1029c30 */
  yOffs += wV_posiw; /* Line 1399, Address: 0x1029c40 */





  if ((short)xOffs < 0) /* Line 1405, Address: 0x1029c50 */
    xOffs = 0; /* Line 1406, Address: 0x1029c6c */
  if ((short)yOffs < 0) /* Line 1407, Address: 0x1029c70 */

    yOffs = (short)yOffs + 2048; /* Line 1409, Address: 0x1029c8c */
  if ((short)xOffs >= 16384) /* Line 1410, Address: 0x1029cac */
    xOffs = 16383; /* Line 1411, Address: 0x1029ccc */
  if ((short)yOffs >= 2048) /* Line 1412, Address: 0x1029cd4 */

    yOffs = (short)yOffs - 2048; /* Line 1414, Address: 0x1029cf4 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1415, Address: 0x1029d14 */
  if (i < 0) i = 0; /* Line 1416, Address: 0x1029d5c */

  ScreenNo = pMapWk[i] & 127; /* Line 1418, Address: 0x1029d68 */

  if (ScreenNo) { /* Line 1420, Address: 0x1029d84 */




    xOffs &= 32767; /* Line 1425, Address: 0x1029d8c */
    yOffs &= 32767; /* Line 1426, Address: 0x1029d98 */


    xBlk = xOffs; /* Line 1429, Address: 0x1029da4 */
    xBlk %= 256; /* Line 1430, Address: 0x1029dac */
    xBlk /= 16; /* Line 1431, Address: 0x1029dcc */
    yBlk = yOffs; /* Line 1432, Address: 0x1029de8 */
    yBlk %= 256; /* Line 1433, Address: 0x1029df0 */
    yBlk /= 16; /* Line 1434, Address: 0x1029e10 */

    lpw = pmapwk; /* Line 1436, Address: 0x1029e2c */
    lpw += xBlk; /* Line 1437, Address: 0x1029e34 */
    lpw += yBlk * 16; /* Line 1438, Address: 0x1029e3c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1439, Address: 0x1029e48 */
    *pIndex = *lpw; /* Line 1440, Address: 0x1029e60 */

    return 1; /* Line 1442, Address: 0x1029e70 */
  }

  *pIndex = 0; /* Line 1445, Address: 0x1029e7c */
  return 0; /* Line 1446, Address: 0x1029e84 */
} /* Line 1447, Address: 0x1029e88 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1467, Address: 0x1029eb0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1475, Address: 0x1029ed8 */
  if (ScreenNo) { /* Line 1476, Address: 0x1029f3c */





    xBlk = xOffs; /* Line 1482, Address: 0x1029f44 */
    xBlk %= 256; /* Line 1483, Address: 0x1029f4c */
    xBlk /= 16; /* Line 1484, Address: 0x1029f6c */
    yBlk = yOffs; /* Line 1485, Address: 0x1029f88 */
    yBlk %= 256; /* Line 1486, Address: 0x1029f90 */
    yBlk /= 16; /* Line 1487, Address: 0x1029fb0 */


    lpw = pmapwk; /* Line 1490, Address: 0x1029fcc */
    lpw += xBlk; /* Line 1491, Address: 0x1029fd4 */
    lpw += yBlk * 16; /* Line 1492, Address: 0x1029fdc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1493, Address: 0x1029fe8 */
    *ppBlockNo = lpw; /* Line 1494, Address: 0x102a000 */
    *pIndex = *lpw; /* Line 1495, Address: 0x102a008 */




    return 1; /* Line 1500, Address: 0x102a018 */
  }

  *pIndex = 0; /* Line 1503, Address: 0x102a024 */
  return 0; /* Line 1504, Address: 0x102a02c */
} /* Line 1505, Address: 0x102a030 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1519, Address: 0x102a050 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1526, Address: 0x102a06c */
  pMapWk = (unsigned char*)mapwka; /* Line 1527, Address: 0x102a070 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1528, Address: 0x102a078 */
    *pBlockIndex = BlockNo; /* Line 1529, Address: 0x102a09c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1530, Address: 0x102a0a8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1531, Address: 0x102a0c0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1532, Address: 0x102a0d4 */
    }
  }


} /* Line 1537, Address: 0x102a0ec */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1551, Address: 0x102a110 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1552, Address: 0x102a11c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1553, Address: 0x102a148 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1554, Address: 0x102a194 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1555, Address: 0x102a1c0 */

          return 0; /* Line 1557, Address: 0x102a20c */
        }
      }
    }
  }

  return 1; /* Line 1563, Address: 0x102a218 */
} /* Line 1564, Address: 0x102a21c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1581, Address: 0x102a230 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1582, Address: 0x102a24c */

} /* Line 1584, Address: 0x102a268 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1586, Address: 0x102a280 */
  wH_posiw = 0; /* Line 1587, Address: 0x102a29c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1588, Address: 0x102a2a0 */

} /* Line 1590, Address: 0x102a2bc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1592, Address: 0x102a2d0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1593, Address: 0x102a2e4 */

} /* Line 1595, Address: 0x102a300 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1597, Address: 0x102a310 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1598, Address: 0x102a32c */

} /* Line 1600, Address: 0x102a348 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1602, Address: 0x102a360 */
  xOffs += wH_posiw; /* Line 1603, Address: 0x102a378 */
  yOffs += wV_posiw; /* Line 1604, Address: 0x102a388 */
  yOffs &= 240; /* Line 1605, Address: 0x102a398 */
  xOffs &= 496; /* Line 1606, Address: 0x102a3a4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1608, Address: 0x102a3b0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1609, Address: 0x102a3dc */


} /* Line 1612, Address: 0x102a408 */















void mapwrt() { /* Line 1628, Address: 0x102a420 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1633, Address: 0x102a438 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1634, Address: 0x102a444 */
  pMapWk = (unsigned char*)mapwka; /* Line 1635, Address: 0x102a450 */
  VramBase = 16384; /* Line 1636, Address: 0x102a458 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1637, Address: 0x102a45c */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1639, Address: 0x102a474 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1640, Address: 0x102a480 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1641, Address: 0x102a48c */
  VramBase = 24576; /* Line 1642, Address: 0x102a494 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1644, Address: 0x102a498 */

} /* Line 1646, Address: 0x102a4b0 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1650, Address: 0x102a4d0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1651, Address: 0x102a4e8 */
} /* Line 1652, Address: 0x102a508 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1657, Address: 0x102a520 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1661, Address: 0x102a540 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1664, Address: 0x102a55c */



    wD4 += 16; /* Line 1668, Address: 0x102a584 */
  } while ((short)--wD6 >= 0); /* Line 1669, Address: 0x102a590 */

} /* Line 1671, Address: 0x102a5b8 */













































































































void mapinit() { /* Line 1781, Address: 0x102a5d0 */

  colorset2(mapinittbl.colorno2); /* Line 1783, Address: 0x102a5d8 */
  colorset(mapinittbl.colorno2); /* Line 1784, Address: 0x102a5ec */

  if (plflag) enecginit(); /* Line 1786, Address: 0x102a600 */
  if (play_start & 2) divdevset(); /* Line 1787, Address: 0x102a618 */
} /* Line 1788, Address: 0x102a638 */










void mapset() {} /* Line 1799, Address: 0x102a650 */
