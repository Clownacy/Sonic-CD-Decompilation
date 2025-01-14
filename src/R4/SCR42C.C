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
















































































void enecginit() {} /* Line 129, Address: 0x1026a30 */



void divdevset() {} /* Line 133, Address: 0x1026a40 */














































sprite_status* main_chk() {
  if (!main_play) return &actwk[0];  /* Line 181, Address: 0x1026a50 */
  else return &actwk[1]; /* Line 182, Address: 0x1026a70 */
} /* Line 183, Address: 0x1026a78 */


void scr_set() { /* Line 186, Address: 0x1026a80 */






  unsigned short scr_dir_tbl[6] = { /* Line 193, Address: 0x1026a8c */
    4, 0, 7319, 0, 2048, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 198, Address: 0x1026ac0 */

  i = 0; /* Line 200, Address: 0x1026b08 */
  scrar_no = scr_dir_tbl[i++]; /* Line 201, Address: 0x1026b0c */
  scralim_left = scr_dir_tbl[i]; /* Line 202, Address: 0x1026b28 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 203, Address: 0x1026b3c */
  scralim_right = scr_dir_tbl[i]; /* Line 204, Address: 0x1026b58 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 205, Address: 0x1026b6c */
  scralim_up = scr_dir_tbl[i]; /* Line 206, Address: 0x1026b88 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 207, Address: 0x1026b9c */
  scralim_down = scr_dir_tbl[i]; /* Line 208, Address: 0x1026bb8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 209, Address: 0x1026bcc */

  scra_h_keep = scralim_left + 576; /* Line 211, Address: 0x1026be8 */
  scra_h_count = 16; /* Line 212, Address: 0x1026c0c */
  scra_v_count = 16; /* Line 213, Address: 0x1026c18 */

  scra_vline = scr_dir_tbl[i++]; /* Line 215, Address: 0x1026c24 */
  scra_hline = 160; /* Line 216, Address: 0x1026c40 */

  playposiset(); /* Line 218, Address: 0x1026c4c */
} /* Line 219, Address: 0x1026c54 */



void playposiset() { /* Line 223, Address: 0x1026c70 */
  unsigned short endplpositbl[16] = { /* Line 224, Address: 0x1026c84 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[2] = { /* Line 234, Address: 0x1026cb8 */
    80,
    1260
  };
  unsigned char playmapnotbl[4] = { /* Line 238, Address: 0x1026cd4 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 246, Address: 0x1026d00 */

    playload(); /* Line 248, Address: 0x1026d14 */
    xWk = actwk[0].xposi.w.h; /* Line 249, Address: 0x1026d1c */
    yWk = actwk[0].yposi.w.h; /* Line 250, Address: 0x1026d2c */
    if (yWk < 0) yWk = 0; /* Line 251, Address: 0x1026d3c */
  } /* Line 252, Address: 0x1026d50 */
  else {


    if (demoflag.w < 0) { /* Line 256, Address: 0x1026d58 */

      i = (enddemono - 1) * 4; /* Line 258, Address: 0x1026d70 */
      xWk = actwk[0].xposi.w.h = endplpositbl[i++]; /* Line 259, Address: 0x1026d88 */
      yWk = actwk[0].yposi.w.h = endplpositbl[i++]; /* Line 260, Address: 0x1026dac */
    } /* Line 261, Address: 0x1026dd0 */
    else {


      i = demoflag.w * 4; /* Line 265, Address: 0x1026dd8 */
      xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 266, Address: 0x1026dec */
      yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 267, Address: 0x1026e10 */
    }
  }

  if ((unsigned short)xWk > 160) { /* Line 271, Address: 0x1026e34 */
    xWk -= 160; /* Line 272, Address: 0x1026e48 */
  } /* Line 273, Address: 0x1026e54 */
  else {
    xWk = 0; /* Line 275, Address: 0x1026e5c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 279, Address: 0x1026e60 */
    xWk = scralim_right; /* Line 280, Address: 0x1026e84 */
  }
  scra_h_posit.w.h = xWk; /* Line 282, Address: 0x1026e94 */

  if ((unsigned short)yWk > 96) { /* Line 284, Address: 0x1026e9c */
    yWk -= 96; /* Line 285, Address: 0x1026eb0 */
  } /* Line 286, Address: 0x1026ebc */
  else {
    yWk = 0; /* Line 288, Address: 0x1026ec4 */
  }

  if (scralim_down < yWk) { /* Line 291, Address: 0x1026ec8 */
    yWk = scralim_down; /* Line 292, Address: 0x1026eec */
  }

  scra_v_posit.w.h = yWk; /* Line 295, Address: 0x1026efc */


  scrbinit(xWk); /* Line 298, Address: 0x1026f04 */

  i = 0; /* Line 300, Address: 0x1026f10 */
  loopmapno = playmapnotbl[i++]; /* Line 301, Address: 0x1026f14 */
  loopmapno2 = playmapnotbl[i++]; /* Line 302, Address: 0x1026f2c */
  ballmapno = playmapnotbl[i++]; /* Line 303, Address: 0x1026f44 */
  ballmapno2 = playmapnotbl[i++]; /* Line 304, Address: 0x1026f5c */


} /* Line 307, Address: 0x1026f74 */



void scrbinit(short yWk) { /* Line 311, Address: 0x1026f90 */
  uint_union data;


  data.l = 0; /* Line 315, Address: 0x1026f98 */
  data.w.l = scra_v_posit.w.h; /* Line 316, Address: 0x1026f9c */
  data.w.l >>= 1; /* Line 317, Address: 0x1026fa8 */

  scrb_v_posit.w.h = data.w.l; /* Line 319, Address: 0x1026fb4 */
  scrb_v_posit.w.l = 0; /* Line 320, Address: 0x1026fc0 */
  scrc_v_posit.w.h = data.w.l; /* Line 321, Address: 0x1026fc8 */
  scrz_v_posit.w.h = data.w.l; /* Line 322, Address: 0x1026fd4 */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 324, Address: 0x1026fe0 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 325, Address: 0x1027004 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 326, Address: 0x1027030 */




} /* Line 331, Address: 0x102705c */



void scroll() { /* Line 335, Address: 0x1027070 */
  uint_union data;
  int_union temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 341, Address: 0x1027080 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 344, Address: 0x1027090 */
  scrchk(); /* Line 345, Address: 0x10270bc */
  scroll_h(); /* Line 346, Address: 0x10270c4 */
  scroll_v(); /* Line 347, Address: 0x10270cc */

  vscroll.w.h = scra_v_posit.w.h; /* Line 349, Address: 0x10270d4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 350, Address: 0x10270e4 */



  temp1.l = (long int)(scra_hz << 2) * 3; /* Line 354, Address: 0x10270f4 */
  temp2.l = scra_vz * 128; /* Line 355, Address: 0x1027124 */
  scrollb_hv(&temp1, &temp2); /* Line 356, Address: 0x102713c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 358, Address: 0x102714c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 359, Address: 0x102715c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 360, Address: 0x102716c */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 362, Address: 0x102717c */
  scrflagz.b.h = 0; /* Line 363, Address: 0x10271b0 */
  scrflagc.b.h = 0; /* Line 364, Address: 0x10271b8 */

  hsCount = 0; /* Line 366, Address: 0x10271c0 */
  for (i = 0; i < 192; ++i) { /* Line 367, Address: 0x10271c4 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 370, Address: 0x10271d0 */
    ++hsCount; /* Line 371, Address: 0x1027200 */
  } /* Line 372, Address: 0x1027204 */

  data.w.l = -scra_h_posit.w.h; /* Line 374, Address: 0x1027214 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 375, Address: 0x1027230 */
  data.w.l = scrb_v_posit.w.h; /* Line 376, Address: 0x1027254 */
  data.w.l &= 1016; /* Line 377, Address: 0x1027260 */
  data.w.l >>= 2; /* Line 378, Address: 0x102726c */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 379, Address: 0x1027278 */

} /* Line 381, Address: 0x10272c8 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 419, Address: 0x10272e0 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 426, Address: 0x10272fc */
  data1.b.l = waterdirec.b.h; /* Line 427, Address: 0x1027304 */
  data2.b.l = waterdirec.b.h; /* Line 428, Address: 0x1027310 */
  waterdirec.w += 128; /* Line 429, Address: 0x102731c */
  data1.w += scrb_v_posit.w.h; /* Line 430, Address: 0x1027330 */
  data1.b.h = 0; /* Line 431, Address: 0x1027344 */
  data2.w += scra_v_posit.w.h; /* Line 432, Address: 0x1027348 */
  data2.b.h = 0; /* Line 433, Address: 0x102735c */

  VPosi &= 7; /* Line 435, Address: 0x1027360 */
  hsw.w.l = hscrollwork[offs++]; /* Line 436, Address: 0x102736c */
  avp = scra_v_posit.w.h; /* Line 437, Address: 0x1027394 */
  i = 232; /* Line 438, Address: 0x10273a4 */


  do {
    if (avp > waterposi) { /* Line 442, Address: 0x10273a8 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 447, Address: 0x10273cc */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 448, Address: 0x10273d4 */
        ++pHScrollBuff; /* Line 449, Address: 0x1027424 */
        ++data1.b.l; /* Line 450, Address: 0x1027428 */
        ++data2.b.l; /* Line 451, Address: 0x1027434 */
        ++VPosi; /* Line 452, Address: 0x1027440 */
        if (VPosi == 8) { /* Line 453, Address: 0x102744c */

          VPosi = 0; /* Line 455, Address: 0x1027464 */
          hsw.w.l = hscrollwork[offs++]; /* Line 456, Address: 0x1027468 */
        }
      } while (--i > 0); /* Line 458, Address: 0x1027490 */

      return; /* Line 460, Address: 0x102749c */
    }
    pHScrollBuff->l = hsw.l; /* Line 462, Address: 0x10274a4 */
    ++pHScrollBuff; /* Line 463, Address: 0x10274ac */
    ++avp; /* Line 464, Address: 0x10274b0 */
    ++data1.b.l; /* Line 465, Address: 0x10274bc */
    ++data2.b.l; /* Line 466, Address: 0x10274c8 */
    ++VPosi; /* Line 467, Address: 0x10274d4 */
    if (VPosi == 8) { /* Line 468, Address: 0x10274e0 */

      VPosi = 0; /* Line 470, Address: 0x10274f8 */
      hsw.w.l = hscrollwork[offs++]; /* Line 471, Address: 0x10274fc */
    }
  } while (--i > 0); /* Line 473, Address: 0x1027524 */

} /* Line 475, Address: 0x1027530 */











void scroll_h() { /* Line 487, Address: 0x1027550 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 490, Address: 0x102755c */
  scrh_move(); /* Line 491, Address: 0x1027568 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 492, Address: 0x1027570 */
    scra_h_count ^= 16; /* Line 493, Address: 0x10275a4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 494, Address: 0x10275b8 */
      scrflaga.b.h |= 4; /* Line 495, Address: 0x10275e4 */
    } /* Line 496, Address: 0x10275f8 */
    else {

      scrflaga.b.h |= 8; /* Line 499, Address: 0x1027600 */
    }
  }


} /* Line 504, Address: 0x1027614 */

void scrh_move() { /* Line 506, Address: 0x1027630 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 509, Address: 0x102763c */
  wD0 -= scra_h_posit.w.h; /* Line 510, Address: 0x1027648 */
  wD0 -= scra_hline; /* Line 511, Address: 0x102765c */
  if (wD0 == 0) { /* Line 512, Address: 0x1027670 */

    scra_hz = 0; /* Line 514, Address: 0x102767c */
  } /* Line 515, Address: 0x1027684 */
  else if ((short)wD0 < 0) { /* Line 516, Address: 0x102768c */
    left_check(wD0); /* Line 517, Address: 0x10276a4 */
  } /* Line 518, Address: 0x10276b0 */
  else {
    right_check(wD0); /* Line 520, Address: 0x10276b8 */
  }

} /* Line 523, Address: 0x10276c4 */


void right_check(unsigned short wD0) { /* Line 526, Address: 0x10276e0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 529, Address: 0x10276ec */
    wD0 = 16; /* Line 530, Address: 0x102770c */
  }

  wD0 += scra_h_posit.w.h; /* Line 533, Address: 0x1027714 */
  if (scralim_right < (short)wD0) { /* Line 534, Address: 0x102772c */
    wD0 = scralim_right; /* Line 535, Address: 0x102775c */
  }

  wD1 = wD0; /* Line 538, Address: 0x1027768 */
  wD1 -= scra_h_posit.w.h; /* Line 539, Address: 0x1027770 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 540, Address: 0x1027784 */
  scra_h_posit.w.h = wD0; /* Line 541, Address: 0x10277b4 */
  scra_hz = wD1; /* Line 542, Address: 0x10277c0 */

} /* Line 544, Address: 0x10277c8 */


void left_check(unsigned short wD0) { /* Line 547, Address: 0x10277e0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 550, Address: 0x10277ec */
    wD0 = -16; /* Line 551, Address: 0x102780c */
  }

  wD0 += scra_h_posit.w.h; /* Line 554, Address: 0x1027814 */
  if (scralim_left > (short)wD0) { /* Line 555, Address: 0x102782c */
    wD0 = scralim_left; /* Line 556, Address: 0x102785c */
  }

  wD1 = wD0; /* Line 559, Address: 0x1027868 */
  wD1 -= scra_h_posit.w.h; /* Line 560, Address: 0x1027870 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 561, Address: 0x1027884 */
  scra_h_posit.w.h = wD0; /* Line 562, Address: 0x10278b4 */
  scra_hz = wD1; /* Line 563, Address: 0x10278c0 */

} /* Line 565, Address: 0x10278c8 */


















void scroll_v() { /* Line 584, Address: 0x10278e0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 587, Address: 0x10278ec */
  if (actwk[0].cddat & 4) { /* Line 588, Address: 0x1027918 */
    wD0 -= 5; /* Line 589, Address: 0x1027930 */
  }

  if (actwk[0].cddat & 2) { /* Line 592, Address: 0x1027938 */
    wD0 += 32; /* Line 593, Address: 0x1027950 */
    if ((unsigned short)scra_vline > wD0) { /* Line 594, Address: 0x1027958 */
      wD0 -= scra_vline; /* Line 595, Address: 0x1027978 */
      sv_move_main2(wD0); /* Line 596, Address: 0x102798c */
      return; /* Line 597, Address: 0x1027998 */
    }
    wD0 -= scra_vline; /* Line 599, Address: 0x10279a0 */
    if (wD0 >= 64) { /* Line 600, Address: 0x10279b4 */
      wD0 -= 64; /* Line 601, Address: 0x10279c4 */
      sv_move_main2(wD0); /* Line 602, Address: 0x10279cc */
      return; /* Line 603, Address: 0x10279d8 */
    }
    wD0 -= 64; /* Line 605, Address: 0x10279e0 */
    if (limmoveflag == 0) goto label1; /* Line 606, Address: 0x10279e8 */
    sv_move_sub2(); /* Line 607, Address: 0x10279fc */
    return; /* Line 608, Address: 0x1027a04 */
  }




  wD0 -= scra_vline; /* Line 614, Address: 0x1027a0c */
  if (wD0) { /* Line 615, Address: 0x1027a20 */
    sv_move_main(wD0); /* Line 616, Address: 0x1027a28 */
    return; /* Line 617, Address: 0x1027a34 */
  }
  if (limmoveflag == 0) { /* Line 619, Address: 0x1027a3c */
    sv_move_sub2(); /* Line 620, Address: 0x1027a50 */
    return; /* Line 621, Address: 0x1027a58 */
  }


label1:
  scra_vz = 0; /* Line 626, Address: 0x1027a60 */

} /* Line 628, Address: 0x1027a68 */





void sv_move_main(unsigned short wD0) { /* Line 634, Address: 0x1027a80 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 637, Address: 0x1027a90 */
    sv_move_main1(wD0); /* Line 638, Address: 0x1027aac */
  } /* Line 639, Address: 0x1027ab8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 642, Address: 0x1027ac0 */
    if ((short)wD1 < 0) { /* Line 643, Address: 0x1027acc */
      wD1 = -(short)wD1; /* Line 644, Address: 0x1027ae4 */
    }

    if (wD1 >= 2048) { /* Line 647, Address: 0x1027b00 */
      sv_move_main2(wD0); /* Line 648, Address: 0x1027b10 */
    } /* Line 649, Address: 0x1027b1c */
    else {
      if ((short)wD0 > 6) { /* Line 651, Address: 0x1027b24 */
        sv_move_plus(1536); /* Line 652, Address: 0x1027b44 */
      } /* Line 653, Address: 0x1027b50 */
      else if ((short)wD0 < -6) { /* Line 654, Address: 0x1027b58 */
        sv_move_minus(1536); /* Line 655, Address: 0x1027b78 */
      } /* Line 656, Address: 0x1027b84 */
      else {
        sv_move_sub(wD0); /* Line 658, Address: 0x1027b8c */
      }
    }
  }
} /* Line 662, Address: 0x1027b98 */



void sv_move_main1(unsigned short wD0) { /* Line 666, Address: 0x1027bb0 */

  if ((short)wD0 > 2) { /* Line 668, Address: 0x1027bbc */
    sv_move_plus(512); /* Line 669, Address: 0x1027bdc */
  } /* Line 670, Address: 0x1027be8 */
  else if ((short)wD0 < -2) { /* Line 671, Address: 0x1027bf0 */
    sv_move_minus(512); /* Line 672, Address: 0x1027c10 */
  } /* Line 673, Address: 0x1027c1c */
  else {
    sv_move_sub(wD0); /* Line 675, Address: 0x1027c24 */
  }

} /* Line 678, Address: 0x1027c30 */


void sv_move_main2(unsigned short wD0) { /* Line 681, Address: 0x1027c40 */

  if ((short)wD0 > 16) { /* Line 683, Address: 0x1027c4c */
    sv_move_plus(4096); /* Line 684, Address: 0x1027c6c */
  } /* Line 685, Address: 0x1027c78 */
  else if ((short)wD0 < -16) { /* Line 686, Address: 0x1027c80 */
    sv_move_minus(4096); /* Line 687, Address: 0x1027ca0 */
  } /* Line 688, Address: 0x1027cac */
  else {
    sv_move_sub(wD0); /* Line 690, Address: 0x1027cb4 */
  }

} /* Line 693, Address: 0x1027cc0 */


void sv_move_sub2() { /* Line 696, Address: 0x1027cd0 */
  limmoveflag = 0; /* Line 697, Address: 0x1027cd8 */
  sv_move_sub(0); /* Line 698, Address: 0x1027ce0 */
} /* Line 699, Address: 0x1027cec */


void sv_move_sub(unsigned short wD0) { /* Line 702, Address: 0x1027d00 */
  int_union lD1;

  lD1.w.h = 0; /* Line 705, Address: 0x1027d0c */
  lD1.w.l = wD0; /* Line 706, Address: 0x1027d10 */
  lD1.l += scra_v_posit.w.h; /* Line 707, Address: 0x1027d18 */
  if ((short)wD0 > 0) { /* Line 708, Address: 0x1027d34 */
    scrv_down_ch(lD1); /* Line 709, Address: 0x1027d50 */
  } /* Line 710, Address: 0x1027d5c */
  else {
    scrv_up_ch(lD1); /* Line 712, Address: 0x1027d64 */
  }

} /* Line 715, Address: 0x1027d70 */




void sv_move_minus(unsigned short wD1) { /* Line 720, Address: 0x1027d80 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 724, Address: 0x1027d90 */
  lD1.l <<= 8; /* Line 725, Address: 0x1027dac */
  lD1.l += scra_v_posit.l; /* Line 726, Address: 0x1027db8 */

  wk = lD1.w.h; /* Line 728, Address: 0x1027dcc */
  lD1.w.h = lD1.w.l; /* Line 729, Address: 0x1027dd4 */
  lD1.w.l = wk; /* Line 730, Address: 0x1027ddc */
  scrv_up_ch(lD1); /* Line 731, Address: 0x1027de0 */
} /* Line 732, Address: 0x1027dec */



void scrv_up_ch(int_union lD1) { /* Line 736, Address: 0x1027e00 */
  if (scralim_up >= lD1.w.l) { /* Line 737, Address: 0x1027e0c */
    if (lD1.w.l <= 0) { /* Line 738, Address: 0x1027e34 */
      lD1.w.l += 2048; /* Line 739, Address: 0x1027e48 */
      actwk[0].yposi.w.h += 2048; /* Line 740, Address: 0x1027e54 */
      scra_v_posit.w.h += 2048; /* Line 741, Address: 0x1027e68 */
      scrb_v_posit.w.h &= 1023; /* Line 742, Address: 0x1027e7c */
    } /* Line 743, Address: 0x1027e90 */
    else {

      lD1.w.l = scralim_up; /* Line 746, Address: 0x1027e98 */
    }
  }
  scrv_move(lD1); /* Line 749, Address: 0x1027ea4 */

} /* Line 751, Address: 0x1027eb0 */





void sv_move_plus(unsigned short wD1) { /* Line 757, Address: 0x1027ec0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 761, Address: 0x1027ed0 */
  lD1.w.l = wD1; /* Line 762, Address: 0x1027ed4 */
  lD1.l <<= 8; /* Line 763, Address: 0x1027edc */
  lD1.l += scra_v_posit.l; /* Line 764, Address: 0x1027ee8 */

  wk = lD1.w.h; /* Line 766, Address: 0x1027efc */
  lD1.w.h = lD1.w.l; /* Line 767, Address: 0x1027f04 */
  lD1.w.l = wk; /* Line 768, Address: 0x1027f0c */

  scrv_down_ch(lD1); /* Line 770, Address: 0x1027f10 */

} /* Line 772, Address: 0x1027f1c */



void scrv_down_ch(int_union lD1) { /* Line 776, Address: 0x1027f30 */
  if (scralim_down <= lD1.w.l) { /* Line 777, Address: 0x1027f3c */
    lD1.w.l -= 2048; /* Line 778, Address: 0x1027f64 */
    if (lD1.w.l > 0) { /* Line 779, Address: 0x1027f70 */
      actwk[0].yposi.w.h &= 2047; /* Line 780, Address: 0x1027f84 */
      scra_v_posit.w.h -= 2048; /* Line 781, Address: 0x1027f98 */
      scrb_v_posit.w.h &= 1023; /* Line 782, Address: 0x1027fac */
    } /* Line 783, Address: 0x1027fc0 */
    else {
      lD1.w.l = scralim_down; /* Line 785, Address: 0x1027fc8 */
    }
  }
  scrv_move(lD1); /* Line 788, Address: 0x1027fd4 */

} /* Line 790, Address: 0x1027fe0 */


void scrv_move(int_union lD1) { /* Line 793, Address: 0x1027ff0 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 796, Address: 0x1028000 */

  wk = lD1.w.h; /* Line 798, Address: 0x102800c */
  lD1.w.h = lD1.w.l; /* Line 799, Address: 0x1028014 */
  lD1.w.l = wk; /* Line 800, Address: 0x102801c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 802, Address: 0x1028020 */
  scra_v_posit.l = lD1.l; /* Line 803, Address: 0x1028048 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 806, Address: 0x1028054 */
    scra_v_count ^= 16; /* Line 807, Address: 0x1028088 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 808, Address: 0x102809c */

      scrflaga.b.h |= 2; /* Line 810, Address: 0x10280c8 */
    } /* Line 811, Address: 0x10280dc */
    else {
      scrflaga.b.h |= 1; /* Line 813, Address: 0x10280e4 */
    }
  }


} /* Line 818, Address: 0x10280f8 */



void scrollb_hv(int_union* lD4, int_union* lD5) { /* Line 822, Address: 0x1028110 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 825, Address: 0x102811c */
  lD0.l += lD4->l; /* Line 826, Address: 0x102812c */
  scrb_h_posit.l = lD0.l; /* Line 827, Address: 0x1028140 */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 829, Address: 0x102814c */

    scrb_h_count ^= 16; /* Line 831, Address: 0x1028180 */
    lD0.l -= lD2.l; /* Line 832, Address: 0x1028194 */
    if ((long int)lD0.l < 0) { /* Line 833, Address: 0x10281a4 */
      scrflagb.b.h |= 4; /* Line 834, Address: 0x10281b8 */
    } /* Line 835, Address: 0x10281cc */
    else {

      scrflagb.b.h |= 8; /* Line 838, Address: 0x10281d4 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 843, Address: 0x10281e8 */
  lD0.l += lD5->l; /* Line 844, Address: 0x10281f8 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 845, Address: 0x102820c */
  scrb_v_posit.l = lD0.l; /* Line 846, Address: 0x1028224 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 848, Address: 0x1028230 */

    scrb_v_count ^= 16; /* Line 850, Address: 0x1028264 */
    lD0.l -= lD3.l; /* Line 851, Address: 0x1028278 */
    if ((long int)lD0.l < 0) { /* Line 852, Address: 0x1028288 */
      scrflagb.b.h |= 1; /* Line 853, Address: 0x102829c */
    } /* Line 854, Address: 0x10282b0 */
    else {

      scrflagb.b.h |= 2; /* Line 857, Address: 0x10282b8 */
    }
  }


} /* Line 862, Address: 0x10282cc */






void scrollb_v(unsigned short wD0) { /* Line 869, Address: 0x10282e0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 872, Address: 0x10282ec */
  scrb_v_posit.w.h = wD0; /* Line 873, Address: 0x10282f8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 875, Address: 0x1028304 */
    scrb_v_count ^= 16; /* Line 876, Address: 0x1028330 */
    if ((short)wD3 > (short)wD0) { /* Line 877, Address: 0x1028344 */
      scrflagb.b.h |= 1; /* Line 878, Address: 0x1028374 */
    } /* Line 879, Address: 0x1028388 */
    else {

      scrflagb.b.h |= 2; /* Line 882, Address: 0x1028390 */
    }
  }


} /* Line 887, Address: 0x10283a4 */



void scrollb_h(int lD4, int flagb) { /* Line 891, Address: 0x10283c0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 895, Address: 0x10283d0 */
  lD0.l = lD2.l + lD4; /* Line 896, Address: 0x10283dc */
  scrb_h_posit.l = lD0.l; /* Line 897, Address: 0x10283ec */

  lD1.w.h = lD0.w.l; /* Line 899, Address: 0x10283f8 */
  lD1.w.l = lD0.w.h; /* Line 900, Address: 0x1028400 */
  lD1.w.l &= 16; /* Line 901, Address: 0x1028408 */

  bD3 = scrb_h_count; /* Line 903, Address: 0x1028414 */
  lD1.b.b4 ^= bD3; /* Line 904, Address: 0x1028420 */
  if (!lD1.b.b4) { /* Line 905, Address: 0x1028434 */
    scrb_h_count ^= 16; /* Line 906, Address: 0x1028440 */
    lD0.l -= lD2.l; /* Line 907, Address: 0x1028454 */
    if ((long int)lD0.l < 0) { /* Line 908, Address: 0x1028464 */
      scrflagb.b.h |= flagb; /* Line 909, Address: 0x1028478 */
    } /* Line 910, Address: 0x1028494 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 913, Address: 0x102849c */
    }
  }


} /* Line 918, Address: 0x10284bc */


void scrollc_h(int lD4, int flagc) { /* Line 921, Address: 0x10284d0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 925, Address: 0x10284e0 */
  lD0.l = lD2.l + lD4; /* Line 926, Address: 0x10284ec */
  scrc_h_posit.l = lD0.l; /* Line 927, Address: 0x10284fc */

  lD1.w.h = lD0.w.l; /* Line 929, Address: 0x1028508 */
  lD1.w.l = lD0.w.h; /* Line 930, Address: 0x1028510 */
  lD1.w.l &= 16; /* Line 931, Address: 0x1028518 */

  bD3 = scrc_h_count; /* Line 933, Address: 0x1028524 */
  lD1.b.b4 ^= bD3; /* Line 934, Address: 0x1028530 */
  if (!lD1.b.b4) { /* Line 935, Address: 0x1028544 */
    scrc_h_count ^= 16; /* Line 936, Address: 0x1028550 */
    lD0.l -= lD2.l; /* Line 937, Address: 0x1028564 */
    if ((long int)lD0.l < 0) { /* Line 938, Address: 0x1028574 */
      scrflagc.b.h |= flagc; /* Line 939, Address: 0x1028588 */
    } /* Line 940, Address: 0x10285a4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 943, Address: 0x10285ac */
    }
  }


} /* Line 948, Address: 0x10285cc */











void scrollz_h(int lD4, int flagz) { /* Line 960, Address: 0x10285e0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 964, Address: 0x10285f0 */
  lD0.l = lD2.l + lD4; /* Line 965, Address: 0x10285fc */
  scrz_h_posit.l = lD0.l; /* Line 966, Address: 0x102860c */

  lD1.w.h = lD0.w.l; /* Line 968, Address: 0x1028618 */
  lD1.w.l = lD0.w.h; /* Line 969, Address: 0x1028620 */
  lD1.w.l &= 16; /* Line 970, Address: 0x1028628 */

  bD3 = scrz_h_count; /* Line 972, Address: 0x1028634 */
  lD1.b.b4 ^= bD3; /* Line 973, Address: 0x1028640 */
  if (!lD1.b.b4) { /* Line 974, Address: 0x1028654 */
    scrz_h_count ^= 16; /* Line 975, Address: 0x1028660 */
    lD0.l -= lD2.l; /* Line 976, Address: 0x1028674 */
    if ((long int)lD0.l < 0) { /* Line 977, Address: 0x1028684 */
      scrflagz.b.h |= flagz; /* Line 978, Address: 0x1028698 */
    } /* Line 979, Address: 0x10286b4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 982, Address: 0x10286bc */
    }
  }


} /* Line 987, Address: 0x10286dc */













void scrollwrtadva() { /* Line 1001, Address: 0x10286f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1007, Address: 0x102870c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1008, Address: 0x1028710 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1009, Address: 0x102871c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1010, Address: 0x1028728 */
  pScrFlag = &scrflagb.b.h; /* Line 1011, Address: 0x1028730 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1012, Address: 0x1028738 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1014, Address: 0x1028754 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1015, Address: 0x1028760 */
  pScrFlag = &scrflagc.b.h; /* Line 1016, Address: 0x102876c */
  scrollwrtc(); /* Line 1017, Address: 0x1028774 */

} /* Line 1019, Address: 0x102877c */












void scrollwrt() { /* Line 1032, Address: 0x10287a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1041, Address: 0x10287c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1042, Address: 0x10287c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1043, Address: 0x10287d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1044, Address: 0x10287dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1045, Address: 0x10287e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1046, Address: 0x10287ec */

  VramBase = 16384; /* Line 1048, Address: 0x1028808 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1049, Address: 0x102880c */
  wV_posiw = scra_v_posiw.w.h; /* Line 1050, Address: 0x1028818 */
  pMapWk = (unsigned char*)mapwka; /* Line 1051, Address: 0x1028824 */
  pScrFlag = &scrflagaw.b.h; /* Line 1052, Address: 0x102882c */

  if (*pScrFlag) { /* Line 1054, Address: 0x1028834 */
    if (*pScrFlag & 1) { /* Line 1055, Address: 0x1028840 */
      *pScrFlag &= 254; /* Line 1056, Address: 0x1028854 */

      lD4.l = -16; /* Line 1058, Address: 0x1028860 */
      wD5 = 65520; /* Line 1059, Address: 0x1028868 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1061, Address: 0x1028870 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1063, Address: 0x1028890 */
    }




    if (*pScrFlag & 2) { /* Line 1069, Address: 0x10288bc */
      *pScrFlag &= 253; /* Line 1070, Address: 0x10288d0 */

      lD4.l = 224; /* Line 1072, Address: 0x10288dc */
      wD5 = 65520; /* Line 1073, Address: 0x10288e4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1074, Address: 0x10288ec */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1076, Address: 0x102890c */
    }




    if (*pScrFlag & 4) { /* Line 1082, Address: 0x1028938 */
      *pScrFlag &= 251; /* Line 1083, Address: 0x102894c */

      lD4.l = -16; /* Line 1085, Address: 0x1028958 */
      wD5 = 65520; /* Line 1086, Address: 0x1028960 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1087, Address: 0x1028968 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1089, Address: 0x1028988 */
    }




    if (*pScrFlag & 8) { /* Line 1095, Address: 0x10289b4 */
      *pScrFlag &= 247; /* Line 1096, Address: 0x10289c8 */

      lD4.l = -16; /* Line 1098, Address: 0x10289d4 */
      wD5 = 320; /* Line 1099, Address: 0x10289dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1100, Address: 0x10289e4 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1102, Address: 0x1028a04 */
    }
  }






} /* Line 1111, Address: 0x1028a30 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1128, Address: 0x1028a60 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1133, Address: 0x1028a80 */
    if (*pScrFlag & 1) { /* Line 1134, Address: 0x1028a90 */
      *pScrFlag &= 254; /* Line 1135, Address: 0x1028aa8 */

      lD4.l = -16; /* Line 1137, Address: 0x1028abc */
      wD5 = 65520; /* Line 1138, Address: 0x1028ac4 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1140, Address: 0x1028acc */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1142, Address: 0x1028aec */
    }




    if (*pScrFlag & 2) { /* Line 1148, Address: 0x1028b18 */
      *pScrFlag &= 253; /* Line 1149, Address: 0x1028b30 */

      lD4.l = 224; /* Line 1151, Address: 0x1028b44 */
      wD5 = 65520; /* Line 1152, Address: 0x1028b4c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1153, Address: 0x1028b54 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1155, Address: 0x1028b74 */
    }




    if (*pScrFlag & 4) { /* Line 1161, Address: 0x1028ba0 */
      *pScrFlag &= 251; /* Line 1162, Address: 0x1028bb8 */

      lD4.l = -16; /* Line 1164, Address: 0x1028bcc */
      wD5 = 65520; /* Line 1165, Address: 0x1028bd4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1166, Address: 0x1028bdc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1168, Address: 0x1028bfc */
    }




    if (*pScrFlag & 8) { /* Line 1174, Address: 0x1028c28 */
      *pScrFlag &= 247; /* Line 1175, Address: 0x1028c40 */

      lD4.l = -16; /* Line 1177, Address: 0x1028c54 */
      wD5 = 320; /* Line 1178, Address: 0x1028c5c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1179, Address: 0x1028c64 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1181, Address: 0x1028c84 */
    }
  }






} /* Line 1190, Address: 0x1028cb0 */






void scrollwrtc() {} /* Line 1197, Address: 0x1028cd0 */




void scrollwrtz() {} /* Line 1202, Address: 0x1028ce0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1220, Address: 0x1028cf0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1233, Address: 0x1028d18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1236, Address: 0x1028d38 */
    pTilePoint->x += 2; /* Line 1237, Address: 0x1028d4c */
    if (pTilePoint->x >= 64) { /* Line 1238, Address: 0x1028d60 */
      pTilePoint->x -= 64; /* Line 1239, Address: 0x1028d74 */
    }
    xOffs += 16; /* Line 1241, Address: 0x1028d88 */
  } while (--lpcnt >= 0); /* Line 1242, Address: 0x1028d94 */
} /* Line 1243, Address: 0x1028da8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1247, Address: 0x1028dc0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1251, Address: 0x1028de8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1254, Address: 0x1028e08 */
    pTilePoint->x += 2; /* Line 1255, Address: 0x1028e1c */
    if (pTilePoint->x >= 64) { /* Line 1256, Address: 0x1028e30 */
      pTilePoint->x -= 64; /* Line 1257, Address: 0x1028e44 */
    }
    xOffs += 16; /* Line 1259, Address: 0x1028e58 */
  } while (--lpcnt >= 0); /* Line 1260, Address: 0x1028e64 */
} /* Line 1261, Address: 0x1028e78 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1281, Address: 0x1028e90 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1285, Address: 0x1028eb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1288, Address: 0x1028ed8 */
    pTilePoint->y += 2; /* Line 1289, Address: 0x1028eec */
    if (pTilePoint->y >= 32) { /* Line 1290, Address: 0x1028efc */
      pTilePoint->y -= 32; /* Line 1291, Address: 0x1028f10 */
    }
    yOffs += 16; /* Line 1293, Address: 0x1028f20 */
  } while (--lpcnt >= 0); /* Line 1294, Address: 0x1028f2c */
} /* Line 1295, Address: 0x1028f40 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1314, Address: 0x1028f50 */
  int base = 0; /* Line 1315, Address: 0x1028f84 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1320, Address: 0x1028f88 */

    base = 1; /* Line 1322, Address: 0x1028f98 */
  } /* Line 1323, Address: 0x1028f9c */
  else if (VramBase == 16384) { /* Line 1324, Address: 0x1028fa4 */

    base = 0; /* Line 1326, Address: 0x1028fb4 */
  }
  x = pTilePoint->x; /* Line 1328, Address: 0x1028fb8 */
  y = pTilePoint->y; /* Line 1329, Address: 0x1028fc0 */


  frip = BlkIndex & 6144; /* Line 1332, Address: 0x1028fc8 */
  BlkIndex &= 1023; /* Line 1333, Address: 0x1028fd0 */
  if (frip == 6144) { /* Line 1334, Address: 0x1028fdc */

    p0 = 3, p1 = 2; /* Line 1336, Address: 0x1028fe8 */
    p2 = 1, p3 = 0; /* Line 1337, Address: 0x1028ff0 */
  } /* Line 1338, Address: 0x1028ff8 */
  else if (frip & 4096) { /* Line 1339, Address: 0x1029000 */

    p0 = 2, p1 = 3; /* Line 1341, Address: 0x102900c */
    p2 = 0, p3 = 1; /* Line 1342, Address: 0x1029014 */
  } /* Line 1343, Address: 0x102901c */
  else if (frip & 2048) { /* Line 1344, Address: 0x1029024 */

    p0 = 1, p1 = 0; /* Line 1346, Address: 0x1029030 */
    p2 = 3, p3 = 2; /* Line 1347, Address: 0x1029038 */
  } /* Line 1348, Address: 0x1029040 */
  else {

    p0 = 0, p1 = 1; /* Line 1351, Address: 0x1029048 */
    p2 = 2, p3 = 3; /* Line 1352, Address: 0x1029050 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1355, Address: 0x1029058 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1356, Address: 0x102909c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1357, Address: 0x10290e0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1358, Address: 0x1029124 */

} /* Line 1360, Address: 0x1029168 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1378, Address: 0x10291a0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1379, Address: 0x10291c0 */
} /* Line 1380, Address: 0x10291e0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1382, Address: 0x10291f0 */
  wH_posiw = 0; /* Line 1383, Address: 0x1029210 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1384, Address: 0x1029214 */
} /* Line 1385, Address: 0x1029234 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1392, Address: 0x1029250 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1398, Address: 0x1029280 */
  yOffs += wV_posiw; /* Line 1399, Address: 0x1029290 */





  if ((short)xOffs < 0) /* Line 1405, Address: 0x10292a0 */
    xOffs = 0; /* Line 1406, Address: 0x10292bc */
  if ((short)yOffs < 0) /* Line 1407, Address: 0x10292c0 */

    yOffs = (short)yOffs + 2048; /* Line 1409, Address: 0x10292dc */
  if ((short)xOffs >= 16384) /* Line 1410, Address: 0x10292fc */
    xOffs = 16383; /* Line 1411, Address: 0x102931c */
  if ((short)yOffs >= 2048) /* Line 1412, Address: 0x1029324 */

    yOffs = (short)yOffs - 2048; /* Line 1414, Address: 0x1029344 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1415, Address: 0x1029364 */
  if (i < 0) i = 0; /* Line 1416, Address: 0x10293ac */

  ScreenNo = pMapWk[i] & 127; /* Line 1418, Address: 0x10293b8 */

  if (ScreenNo) { /* Line 1420, Address: 0x10293d4 */




    xOffs &= 32767; /* Line 1425, Address: 0x10293dc */
    yOffs &= 32767; /* Line 1426, Address: 0x10293e8 */


    xBlk = xOffs; /* Line 1429, Address: 0x10293f4 */
    xBlk %= 256; /* Line 1430, Address: 0x10293fc */
    xBlk /= 16; /* Line 1431, Address: 0x102941c */
    yBlk = yOffs; /* Line 1432, Address: 0x1029438 */
    yBlk %= 256; /* Line 1433, Address: 0x1029440 */
    yBlk /= 16; /* Line 1434, Address: 0x1029460 */

    lpw = pmapwk; /* Line 1436, Address: 0x102947c */
    lpw += xBlk; /* Line 1437, Address: 0x1029484 */
    lpw += yBlk * 16; /* Line 1438, Address: 0x102948c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1439, Address: 0x1029498 */
    *pIndex = *lpw; /* Line 1440, Address: 0x10294b0 */

    return 1; /* Line 1442, Address: 0x10294c0 */
  }

  *pIndex = 0; /* Line 1445, Address: 0x10294cc */
  return 0; /* Line 1446, Address: 0x10294d4 */
} /* Line 1447, Address: 0x10294d8 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1467, Address: 0x1029500 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1475, Address: 0x1029528 */
  if (ScreenNo) { /* Line 1476, Address: 0x102958c */





    xBlk = xOffs; /* Line 1482, Address: 0x1029594 */
    xBlk %= 256; /* Line 1483, Address: 0x102959c */
    xBlk /= 16; /* Line 1484, Address: 0x10295bc */
    yBlk = yOffs; /* Line 1485, Address: 0x10295d8 */
    yBlk %= 256; /* Line 1486, Address: 0x10295e0 */
    yBlk /= 16; /* Line 1487, Address: 0x1029600 */


    lpw = pmapwk; /* Line 1490, Address: 0x102961c */
    lpw += xBlk; /* Line 1491, Address: 0x1029624 */
    lpw += yBlk * 16; /* Line 1492, Address: 0x102962c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1493, Address: 0x1029638 */
    *ppBlockNo = lpw; /* Line 1494, Address: 0x1029650 */
    *pIndex = *lpw; /* Line 1495, Address: 0x1029658 */




    return 1; /* Line 1500, Address: 0x1029668 */
  }

  *pIndex = 0; /* Line 1503, Address: 0x1029674 */
  return 0; /* Line 1504, Address: 0x102967c */
} /* Line 1505, Address: 0x1029680 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1519, Address: 0x10296a0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1526, Address: 0x10296bc */
  pMapWk = (unsigned char*)mapwka; /* Line 1527, Address: 0x10296c0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1528, Address: 0x10296c8 */
    *pBlockIndex = BlockNo; /* Line 1529, Address: 0x10296ec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1530, Address: 0x10296f8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1531, Address: 0x1029710 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1532, Address: 0x1029724 */
    }
  }


} /* Line 1537, Address: 0x102973c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1551, Address: 0x1029760 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1552, Address: 0x102976c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1553, Address: 0x1029798 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1554, Address: 0x10297e4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1555, Address: 0x1029810 */

          return 0; /* Line 1557, Address: 0x102985c */
        }
      }
    }
  }

  return 1; /* Line 1563, Address: 0x1029868 */
} /* Line 1564, Address: 0x102986c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1581, Address: 0x1029880 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1582, Address: 0x102989c */

} /* Line 1584, Address: 0x10298b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1586, Address: 0x10298d0 */
  wH_posiw = 0; /* Line 1587, Address: 0x10298ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1588, Address: 0x10298f0 */

} /* Line 1590, Address: 0x102990c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1592, Address: 0x1029920 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1593, Address: 0x1029934 */

} /* Line 1595, Address: 0x1029950 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1597, Address: 0x1029960 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1598, Address: 0x102997c */

} /* Line 1600, Address: 0x1029998 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1602, Address: 0x10299b0 */
  xOffs += wH_posiw; /* Line 1603, Address: 0x10299c8 */
  yOffs += wV_posiw; /* Line 1604, Address: 0x10299d8 */
  yOffs &= 240; /* Line 1605, Address: 0x10299e8 */
  xOffs &= 496; /* Line 1606, Address: 0x10299f4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1608, Address: 0x1029a00 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1609, Address: 0x1029a2c */


} /* Line 1612, Address: 0x1029a58 */















void mapwrt() { /* Line 1628, Address: 0x1029a70 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1633, Address: 0x1029a88 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1634, Address: 0x1029a94 */
  pMapWk = (unsigned char*)mapwka; /* Line 1635, Address: 0x1029aa0 */
  VramBase = 16384; /* Line 1636, Address: 0x1029aa8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1637, Address: 0x1029aac */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1639, Address: 0x1029ac4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1640, Address: 0x1029ad0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1641, Address: 0x1029adc */
  VramBase = 24576; /* Line 1642, Address: 0x1029ae4 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1644, Address: 0x1029ae8 */

} /* Line 1646, Address: 0x1029b00 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1650, Address: 0x1029b20 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1651, Address: 0x1029b38 */
} /* Line 1652, Address: 0x1029b58 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1657, Address: 0x1029b70 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1661, Address: 0x1029b90 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1664, Address: 0x1029bac */



    wD4 += 16; /* Line 1668, Address: 0x1029bd4 */
  } while ((short)--wD6 >= 0); /* Line 1669, Address: 0x1029be0 */

} /* Line 1671, Address: 0x1029c08 */













































































































void mapinit() { /* Line 1781, Address: 0x1029c20 */

  colorset2(mapinittbl.colorno2); /* Line 1783, Address: 0x1029c28 */
  colorset(mapinittbl.colorno2); /* Line 1784, Address: 0x1029c3c */


  if (play_start & 2) divdevset(); /* Line 1787, Address: 0x1029c50 */
} /* Line 1788, Address: 0x1029c70 */










void mapset() {} /* Line 1799, Address: 0x1029c80 */
