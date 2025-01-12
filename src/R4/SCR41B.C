#include "..\EQU.H"
#include "SCR41B.H"
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














































































void enecginit() {} /* Line 128, Address: 0x10257f0 */



void divdevset() {} /* Line 132, Address: 0x1025800 */














































sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 180, Address: 0x1025810 */
  else return &actwk[1]; /* Line 181, Address: 0x1025830 */
} /* Line 182, Address: 0x1025838 */


void scr_set() { /* Line 185, Address: 0x1025840 */






  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x102584c */
    4, 0, 7319, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1025880 */

  i = 0; /* Line 199, Address: 0x10258c8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x10258cc */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x10258e8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x10258fc */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x1025918 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x102592c */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1025948 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x102595c */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1025978 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x102598c */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x10259a8 */
  scra_h_count = 16; /* Line 211, Address: 0x10259cc */
  scra_v_count = 16; /* Line 212, Address: 0x10259d8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x10259e4 */
  scra_hline = 160; /* Line 215, Address: 0x1025a00 */

  playposiset(); /* Line 217, Address: 0x1025a0c */
} /* Line 218, Address: 0x1025a14 */



void playposiset() { /* Line 222, Address: 0x1025a30 */
  unsigned short endplpositbl[16] = { /* Line 223, Address: 0x1025a44 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[2] = { /* Line 233, Address: 0x1025a78 */
    80,
    64
  };
  unsigned char playmapnotbl[4] = { /* Line 237, Address: 0x1025a94 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 245, Address: 0x1025ac0 */

    playload(); /* Line 247, Address: 0x1025ad4 */
    xWk = actwk[0].xposi.w.h; /* Line 248, Address: 0x1025adc */
    yWk = actwk[0].yposi.w.h; /* Line 249, Address: 0x1025aec */
    if (yWk < 0) yWk = 0; /* Line 250, Address: 0x1025afc */
  } /* Line 251, Address: 0x1025b10 */
  else {


    if (demoflag.w < 0) { /* Line 255, Address: 0x1025b18 */

      i = (enddemono - 1) * 4; /* Line 257, Address: 0x1025b30 */
      xWk = actwk[0].xposi.w.h = endplpositbl[i++]; /* Line 258, Address: 0x1025b48 */
      yWk = actwk[0].yposi.w.h = endplpositbl[i++]; /* Line 259, Address: 0x1025b6c */
    } /* Line 260, Address: 0x1025b90 */
    else {


      i = demoflag.w * 4; /* Line 264, Address: 0x1025b98 */
      xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 265, Address: 0x1025bac */
      yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 266, Address: 0x1025bd0 */
    }
  }

  if ((unsigned short)xWk > 160) { /* Line 270, Address: 0x1025bf4 */
    xWk -= 160; /* Line 271, Address: 0x1025c08 */
  } /* Line 272, Address: 0x1025c14 */
  else {
    xWk = 0; /* Line 274, Address: 0x1025c1c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 278, Address: 0x1025c20 */
    xWk = scralim_right; /* Line 279, Address: 0x1025c44 */
  }
  scra_h_posit.w.h = xWk; /* Line 281, Address: 0x1025c54 */

  if ((unsigned short)yWk > 96) { /* Line 283, Address: 0x1025c5c */
    yWk -= 96; /* Line 284, Address: 0x1025c70 */
  } /* Line 285, Address: 0x1025c7c */
  else {
    yWk = 0; /* Line 287, Address: 0x1025c84 */
  }

  if (scralim_down < yWk) { /* Line 290, Address: 0x1025c88 */
    yWk = scralim_down; /* Line 291, Address: 0x1025cac */
  }

  scra_v_posit.w.h = yWk; /* Line 294, Address: 0x1025cbc */


  scrbinit(xWk); /* Line 297, Address: 0x1025cc4 */

  i = 0; /* Line 299, Address: 0x1025cd0 */
  loopmapno = playmapnotbl[i++]; /* Line 300, Address: 0x1025cd4 */
  loopmapno2 = playmapnotbl[i++]; /* Line 301, Address: 0x1025cec */
  ballmapno = playmapnotbl[i++]; /* Line 302, Address: 0x1025d04 */
  ballmapno2 = playmapnotbl[i++]; /* Line 303, Address: 0x1025d1c */


} /* Line 306, Address: 0x1025d34 */



void scrbinit(short yWk) { /* Line 310, Address: 0x1025d50 */
  unsigned short data;
  int i;

  data = scra_v_posit.w.h; /* Line 314, Address: 0x1025d60 */
  data >>= 1; /* Line 315, Address: 0x1025d6c */

  scrb_v_posit.w.h = data; /* Line 317, Address: 0x1025d74 */
  scrb_v_posit.w.l = 0; /* Line 318, Address: 0x1025d7c */
  scrc_v_posit.w.h = data; /* Line 319, Address: 0x1025d84 */
  scrz_v_posit.w.h = data; /* Line 320, Address: 0x1025d8c */




  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 325, Address: 0x1025d94 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 326, Address: 0x1025db8 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 327, Address: 0x1025de4 */
  for (i = 0; i < 30; ++i) { /* Line 328, Address: 0x1025e10 */

    hscrollwork[i] = 0; /* Line 330, Address: 0x1025e1c */
  } /* Line 331, Address: 0x1025e30 */
} /* Line 332, Address: 0x1025e40 */



void scroll() { /* Line 336, Address: 0x1025e60 */
  uint_union data;
  int temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 342, Address: 0x1025e78 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 345, Address: 0x1025e88 */
  scrchk(); /* Line 346, Address: 0x1025eb4 */
  scroll_h(); /* Line 347, Address: 0x1025ebc */
  scroll_v(); /* Line 348, Address: 0x1025ec4 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 350, Address: 0x1025ecc */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 351, Address: 0x1025edc */



  temp1 = (long int)(scra_hz << 2) * 3; /* Line 355, Address: 0x1025eec */
  temp2 = scra_vz << 7; /* Line 356, Address: 0x1025f18 */
  scrollb_hv(temp1, temp2); /* Line 357, Address: 0x1025f2c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 359, Address: 0x1025f3c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 360, Address: 0x1025f4c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 361, Address: 0x1025f5c */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 363, Address: 0x1025f6c */
  scrflagz.b.h = 0; /* Line 364, Address: 0x1025fa0 */
  scrflagc.b.h = 0; /* Line 365, Address: 0x1025fa8 */

  hsCount = 0; /* Line 367, Address: 0x1025fb0 */

  for (i = 0; i < 192; ++i) { /* Line 369, Address: 0x1025fb4 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 372, Address: 0x1025fc0 */
    ++hsCount; /* Line 373, Address: 0x1025ff0 */
  } /* Line 374, Address: 0x1025ff4 */

  data.w.l = -scra_h_posit.w.h; /* Line 376, Address: 0x1026004 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 377, Address: 0x1026020 */
  data.w.l = scrb_v_posit.w.h; /* Line 378, Address: 0x1026044 */
  data.w.l &= 2040; /* Line 379, Address: 0x1026050 */
  data.w.l >>= 2; /* Line 380, Address: 0x102605c */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 381, Address: 0x1026068 */

} /* Line 383, Address: 0x10260b8 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 421, Address: 0x10260e0 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 428, Address: 0x10260fc */
  data1.b.l = waterdirec.b.h; /* Line 429, Address: 0x1026104 */
  data2.b.l = waterdirec.b.h; /* Line 430, Address: 0x1026110 */
  waterdirec.w += 128; /* Line 431, Address: 0x102611c */
  data1.w += scrb_v_posit.w.h; /* Line 432, Address: 0x1026130 */
  data1.b.h = 0; /* Line 433, Address: 0x1026144 */
  data2.w += scra_v_posit.w.h; /* Line 434, Address: 0x1026148 */
  data2.b.h = 0; /* Line 435, Address: 0x102615c */

  VPosi &= 7; /* Line 437, Address: 0x1026160 */
  hsw.w.l = hscrollwork[offs++]; /* Line 438, Address: 0x102616c */
  avp = scra_v_posit.w.h; /* Line 439, Address: 0x1026194 */
  i = 232; /* Line 440, Address: 0x10261a4 */


  do {
    if (avp > waterposi) { /* Line 444, Address: 0x10261a8 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 449, Address: 0x10261cc */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 450, Address: 0x10261d4 */
        ++pHScrollBuff; /* Line 451, Address: 0x1026224 */
        ++data1.b.l; /* Line 452, Address: 0x1026228 */
        ++data2.b.l; /* Line 453, Address: 0x1026234 */
        ++VPosi; /* Line 454, Address: 0x1026240 */
        if (VPosi == 8) { /* Line 455, Address: 0x102624c */

          VPosi = 0; /* Line 457, Address: 0x1026264 */
          hsw.w.l = hscrollwork[offs++]; /* Line 458, Address: 0x1026268 */
        }
      } while (--i > 0); /* Line 460, Address: 0x1026290 */

      return; /* Line 462, Address: 0x102629c */
    }
    pHScrollBuff->l = hsw.l; /* Line 464, Address: 0x10262a4 */
    ++pHScrollBuff; /* Line 465, Address: 0x10262ac */
    ++avp; /* Line 466, Address: 0x10262b0 */
    ++data1.b.l; /* Line 467, Address: 0x10262bc */
    ++data2.b.l; /* Line 468, Address: 0x10262c8 */
    ++VPosi; /* Line 469, Address: 0x10262d4 */
    if (VPosi == 8) { /* Line 470, Address: 0x10262e0 */

      VPosi = 0; /* Line 472, Address: 0x10262f8 */
      hsw.w.l = hscrollwork[offs++]; /* Line 473, Address: 0x10262fc */
    }
  } while (--i > 0); /* Line 475, Address: 0x1026324 */

} /* Line 477, Address: 0x1026330 */











void scroll_h() { /* Line 489, Address: 0x1026350 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 492, Address: 0x102635c */
  scrh_move(); /* Line 493, Address: 0x1026368 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 494, Address: 0x1026370 */
    scra_h_count ^= 16; /* Line 495, Address: 0x10263a4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 496, Address: 0x10263b8 */
      scrflaga.b.h |= 4; /* Line 497, Address: 0x10263e4 */
    } /* Line 498, Address: 0x10263f8 */
    else {

      scrflaga.b.h |= 8; /* Line 501, Address: 0x1026400 */
    }
  }


} /* Line 506, Address: 0x1026414 */

void scrh_move() { /* Line 508, Address: 0x1026430 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 511, Address: 0x102643c */
  wD0 -= scra_h_posit.w.h; /* Line 512, Address: 0x1026448 */
  wD0 -= scra_hline; /* Line 513, Address: 0x102645c */
  if (wD0 == 0) { /* Line 514, Address: 0x1026470 */

    scra_hz = 0; /* Line 516, Address: 0x102647c */
  } /* Line 517, Address: 0x1026484 */
  else if ((short)wD0 < 0) { /* Line 518, Address: 0x102648c */
    left_check(wD0); /* Line 519, Address: 0x10264a4 */
  } /* Line 520, Address: 0x10264b0 */
  else {
    right_check(wD0); /* Line 522, Address: 0x10264b8 */
  }

} /* Line 525, Address: 0x10264c4 */


void right_check(unsigned short wD0) { /* Line 528, Address: 0x10264e0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 531, Address: 0x10264ec */
    wD0 = 16; /* Line 532, Address: 0x102650c */
  }

  wD0 += scra_h_posit.w.h; /* Line 535, Address: 0x1026514 */
  if (scralim_right < (short)wD0) { /* Line 536, Address: 0x102652c */
    wD0 = scralim_right; /* Line 537, Address: 0x102655c */
  }

  wD1 = wD0; /* Line 540, Address: 0x1026568 */
  wD1 -= scra_h_posit.w.h; /* Line 541, Address: 0x1026570 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 542, Address: 0x1026584 */
  scra_h_posit.w.h = wD0; /* Line 543, Address: 0x10265b4 */
  scra_hz = wD1; /* Line 544, Address: 0x10265c0 */

} /* Line 546, Address: 0x10265c8 */


void left_check(unsigned short wD0) { /* Line 549, Address: 0x10265e0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 552, Address: 0x10265ec */
    wD0 = -16; /* Line 553, Address: 0x102660c */
  }

  wD0 += scra_h_posit.w.h; /* Line 556, Address: 0x1026614 */
  if (scralim_left > (short)wD0) { /* Line 557, Address: 0x102662c */
    wD0 = scralim_left; /* Line 558, Address: 0x102665c */
  }

  wD1 = wD0; /* Line 561, Address: 0x1026668 */
  wD1 -= scra_h_posit.w.h; /* Line 562, Address: 0x1026670 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 563, Address: 0x1026684 */
  scra_h_posit.w.h = wD0; /* Line 564, Address: 0x10266b4 */
  scra_hz = wD1; /* Line 565, Address: 0x10266c0 */

} /* Line 567, Address: 0x10266c8 */


















void scroll_v() { /* Line 586, Address: 0x10266e0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 589, Address: 0x10266ec */
  if (actwk[0].cddat & 4) { /* Line 590, Address: 0x1026718 */
    wD0 -= 5; /* Line 591, Address: 0x1026730 */
  }

  if (actwk[0].cddat & 2) { /* Line 594, Address: 0x1026738 */
    wD0 += 32; /* Line 595, Address: 0x1026750 */
    if ((unsigned short)scra_vline > wD0) { /* Line 596, Address: 0x1026758 */
      wD0 -= scra_vline; /* Line 597, Address: 0x1026778 */
      sv_move_main2(wD0); /* Line 598, Address: 0x102678c */
      return; /* Line 599, Address: 0x1026798 */
    }
    wD0 -= scra_vline; /* Line 601, Address: 0x10267a0 */
    if (wD0 >= 64) { /* Line 602, Address: 0x10267b4 */
      wD0 -= 64; /* Line 603, Address: 0x10267c4 */
      sv_move_main2(wD0); /* Line 604, Address: 0x10267cc */
      return; /* Line 605, Address: 0x10267d8 */
    }
    wD0 -= 64; /* Line 607, Address: 0x10267e0 */
    if (limmoveflag == 0) goto label1; /* Line 608, Address: 0x10267e8 */
    sv_move_sub2(); /* Line 609, Address: 0x10267fc */
    return; /* Line 610, Address: 0x1026804 */
  }




  wD0 -= scra_vline; /* Line 616, Address: 0x102680c */
  if (wD0) { /* Line 617, Address: 0x1026820 */
    sv_move_main(wD0); /* Line 618, Address: 0x1026828 */
    return; /* Line 619, Address: 0x1026834 */
  }
  if (limmoveflag == 0) { /* Line 621, Address: 0x102683c */
    sv_move_sub2(); /* Line 622, Address: 0x1026850 */
    return; /* Line 623, Address: 0x1026858 */
  }


label1:
  scra_vz = 0; /* Line 628, Address: 0x1026860 */

} /* Line 630, Address: 0x1026868 */





void sv_move_main(unsigned short wD0) { /* Line 636, Address: 0x1026880 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 639, Address: 0x1026890 */
    sv_move_main1(wD0); /* Line 640, Address: 0x10268ac */
  } /* Line 641, Address: 0x10268b8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 644, Address: 0x10268c0 */
    if ((short)wD1 < 0) { /* Line 645, Address: 0x10268cc */
      wD1 = -(short)wD1; /* Line 646, Address: 0x10268e4 */
    }

    if (wD1 >= 2048) { /* Line 649, Address: 0x1026900 */
      sv_move_main2(wD0); /* Line 650, Address: 0x1026910 */
    } /* Line 651, Address: 0x102691c */
    else {
      if ((short)wD0 > 6) { /* Line 653, Address: 0x1026924 */
        sv_move_plus(1536); /* Line 654, Address: 0x1026944 */
      } /* Line 655, Address: 0x1026950 */
      else if ((short)wD0 < -6) { /* Line 656, Address: 0x1026958 */
        sv_move_minus(1536); /* Line 657, Address: 0x1026978 */
      } /* Line 658, Address: 0x1026984 */
      else {
        sv_move_sub(wD0); /* Line 660, Address: 0x102698c */
      }
    }
  }
} /* Line 664, Address: 0x1026998 */



void sv_move_main1(unsigned short wD0) { /* Line 668, Address: 0x10269b0 */

  if ((short)wD0 > 2) { /* Line 670, Address: 0x10269bc */
    sv_move_plus(512); /* Line 671, Address: 0x10269dc */
  } /* Line 672, Address: 0x10269e8 */
  else if ((short)wD0 < -2) { /* Line 673, Address: 0x10269f0 */
    sv_move_minus(512); /* Line 674, Address: 0x1026a10 */
  } /* Line 675, Address: 0x1026a1c */
  else {
    sv_move_sub(wD0); /* Line 677, Address: 0x1026a24 */
  }

} /* Line 680, Address: 0x1026a30 */


void sv_move_main2(unsigned short wD0) { /* Line 683, Address: 0x1026a40 */

  if ((short)wD0 > 16) { /* Line 685, Address: 0x1026a4c */
    sv_move_plus(4096); /* Line 686, Address: 0x1026a6c */
  } /* Line 687, Address: 0x1026a78 */
  else if ((short)wD0 < -16) { /* Line 688, Address: 0x1026a80 */
    sv_move_minus(4096); /* Line 689, Address: 0x1026aa0 */
  } /* Line 690, Address: 0x1026aac */
  else {
    sv_move_sub(wD0); /* Line 692, Address: 0x1026ab4 */
  }

} /* Line 695, Address: 0x1026ac0 */


void sv_move_sub2() { /* Line 698, Address: 0x1026ad0 */
  limmoveflag = 0; /* Line 699, Address: 0x1026ad8 */
  sv_move_sub(0); /* Line 700, Address: 0x1026ae0 */
} /* Line 701, Address: 0x1026aec */


void sv_move_sub(unsigned short wD0) { /* Line 704, Address: 0x1026b00 */
  int_union lD1;

  lD1.w.h = 0; /* Line 707, Address: 0x1026b0c */
  lD1.w.l = wD0; /* Line 708, Address: 0x1026b10 */
  lD1.l += scra_v_posit.w.h; /* Line 709, Address: 0x1026b18 */
  if ((short)wD0 > 0) { /* Line 710, Address: 0x1026b34 */
    scrv_down_ch(lD1); /* Line 711, Address: 0x1026b50 */
  } /* Line 712, Address: 0x1026b5c */
  else {
    scrv_up_ch(lD1); /* Line 714, Address: 0x1026b64 */
  }

} /* Line 717, Address: 0x1026b70 */




void sv_move_minus(unsigned short wD1) { /* Line 722, Address: 0x1026b80 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 726, Address: 0x1026b90 */
  lD1.l <<= 8; /* Line 727, Address: 0x1026bac */
  lD1.l += scra_v_posit.l; /* Line 728, Address: 0x1026bb8 */

  wk = lD1.w.h; /* Line 730, Address: 0x1026bcc */
  lD1.w.h = lD1.w.l; /* Line 731, Address: 0x1026bd4 */
  lD1.w.l = wk; /* Line 732, Address: 0x1026bdc */
  scrv_up_ch(lD1); /* Line 733, Address: 0x1026be0 */
} /* Line 734, Address: 0x1026bec */



void scrv_up_ch(int_union lD1) { /* Line 738, Address: 0x1026c00 */
  if (scralim_up >= lD1.w.l) { /* Line 739, Address: 0x1026c0c */
    if (lD1.w.l < -255) { /* Line 740, Address: 0x1026c34 */
      lD1.w.l &= 2047; /* Line 741, Address: 0x1026c4c */
      actwk[0].yposi.w.h &= 2047; /* Line 742, Address: 0x1026c58 */
      scra_v_posit.w.h &= 2047; /* Line 743, Address: 0x1026c6c */
      scrb_v_posit.w.h &= 1023; /* Line 744, Address: 0x1026c80 */
    } /* Line 745, Address: 0x1026c94 */
    else {

      lD1.w.l = scralim_up; /* Line 748, Address: 0x1026c9c */
    }
  }
  scrv_move(lD1); /* Line 751, Address: 0x1026ca8 */

} /* Line 753, Address: 0x1026cb4 */





void sv_move_plus(unsigned short wD1) { /* Line 759, Address: 0x1026cd0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 763, Address: 0x1026ce0 */
  lD1.w.l = wD1; /* Line 764, Address: 0x1026ce4 */
  lD1.l <<= 8; /* Line 765, Address: 0x1026cec */
  lD1.l += scra_v_posit.l; /* Line 766, Address: 0x1026cf8 */

  wk = lD1.w.h; /* Line 768, Address: 0x1026d0c */
  lD1.w.h = lD1.w.l; /* Line 769, Address: 0x1026d14 */
  lD1.w.l = wk; /* Line 770, Address: 0x1026d1c */

  scrv_down_ch(lD1); /* Line 772, Address: 0x1026d20 */

} /* Line 774, Address: 0x1026d2c */



void scrv_down_ch(int_union lD1) { /* Line 778, Address: 0x1026d40 */
  if (scralim_down <= lD1.w.l) { /* Line 779, Address: 0x1026d4c */
    lD1.w.l -= 2048; /* Line 780, Address: 0x1026d74 */
    if (lD1.w.l > 0) { /* Line 781, Address: 0x1026d80 */
      actwk[0].yposi.w.h &= 2047; /* Line 782, Address: 0x1026d94 */
      scra_v_posit.w.h -= 2048; /* Line 783, Address: 0x1026da8 */
      scrb_v_posit.w.h &= 1023; /* Line 784, Address: 0x1026dbc */
    } /* Line 785, Address: 0x1026dd0 */
    else {
      lD1.w.l = scralim_down; /* Line 787, Address: 0x1026dd8 */
    }
  }
  scrv_move(lD1); /* Line 790, Address: 0x1026de4 */

} /* Line 792, Address: 0x1026df0 */


void scrv_move(int_union lD1) { /* Line 795, Address: 0x1026e00 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 798, Address: 0x1026e10 */

  wk = lD1.w.h; /* Line 800, Address: 0x1026e1c */
  lD1.w.h = lD1.w.l; /* Line 801, Address: 0x1026e24 */
  lD1.w.l = wk; /* Line 802, Address: 0x1026e2c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 804, Address: 0x1026e30 */
  scra_v_posit.l = lD1.l; /* Line 805, Address: 0x1026e58 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 808, Address: 0x1026e64 */
    scra_v_count ^= 16; /* Line 809, Address: 0x1026e98 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 810, Address: 0x1026eac */

      scrflaga.b.h |= 2; /* Line 812, Address: 0x1026ed8 */
    } /* Line 813, Address: 0x1026eec */
    else {
      scrflaga.b.h |= 1; /* Line 815, Address: 0x1026ef4 */
    }
  }


} /* Line 820, Address: 0x1026f08 */



void scrollb_hv(int lD4, int lD5) { /* Line 824, Address: 0x1026f20 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 827, Address: 0x1026f2c */
  lD0.l += lD4; /* Line 828, Address: 0x1026f3c */
  scrb_h_posit.l = lD0.l; /* Line 829, Address: 0x1026f4c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 831, Address: 0x1026f58 */

    scrb_h_count ^= 16; /* Line 833, Address: 0x1026f8c */
    lD0.l -= lD2.l; /* Line 834, Address: 0x1026fa0 */
    if ((long int)lD0.l < 0) { /* Line 835, Address: 0x1026fb0 */
      scrflagb.b.h |= 4; /* Line 836, Address: 0x1026fc4 */
    } /* Line 837, Address: 0x1026fd8 */
    else {

      scrflagb.b.h |= 8; /* Line 840, Address: 0x1026fe0 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 845, Address: 0x1026ff4 */
  lD0.l += lD5; /* Line 846, Address: 0x1027004 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 847, Address: 0x1027014 */
  scrb_v_posit.l = lD0.l; /* Line 848, Address: 0x102702c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 850, Address: 0x1027038 */

    scrb_v_count ^= 16; /* Line 852, Address: 0x102706c */
    lD0.l -= lD3.l; /* Line 853, Address: 0x1027080 */
    if ((long int)lD0.l < 0) { /* Line 854, Address: 0x1027090 */
      scrflagb.b.h |= 1; /* Line 855, Address: 0x10270a4 */
    } /* Line 856, Address: 0x10270b8 */
    else {

      scrflagb.b.h |= 2; /* Line 859, Address: 0x10270c0 */
    }
  }


} /* Line 864, Address: 0x10270d4 */






void scrollb_v(unsigned short wD0) { /* Line 871, Address: 0x10270e0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 874, Address: 0x10270ec */
  scrb_v_posit.w.h = wD0; /* Line 875, Address: 0x10270f8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 877, Address: 0x1027104 */
    scrb_v_count ^= 16; /* Line 878, Address: 0x1027130 */
    if ((short)wD3 > (short)wD0) { /* Line 879, Address: 0x1027144 */
      scrflagb.b.h |= 1; /* Line 880, Address: 0x1027174 */
    } /* Line 881, Address: 0x1027188 */
    else {

      scrflagb.b.h |= 2; /* Line 884, Address: 0x1027190 */
    }
  }


} /* Line 889, Address: 0x10271a4 */



void scrollb_h(int lD4, int flagb) { /* Line 893, Address: 0x10271c0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 897, Address: 0x10271d0 */
  lD0.l = lD2.l + lD4; /* Line 898, Address: 0x10271dc */
  scrb_h_posit.l = lD0.l; /* Line 899, Address: 0x10271ec */

  lD1.w.h = lD0.w.l; /* Line 901, Address: 0x10271f8 */
  lD1.w.l = lD0.w.h; /* Line 902, Address: 0x1027200 */
  lD1.w.l &= 16; /* Line 903, Address: 0x1027208 */

  bD3 = scrb_h_count; /* Line 905, Address: 0x1027214 */
  lD1.b.b4 ^= bD3; /* Line 906, Address: 0x1027220 */
  if (!lD1.b.b4) { /* Line 907, Address: 0x1027234 */
    scrb_h_count ^= 16; /* Line 908, Address: 0x1027240 */
    lD0.l -= lD2.l; /* Line 909, Address: 0x1027254 */
    if ((long int)lD0.l < 0) { /* Line 910, Address: 0x1027264 */
      scrflagb.b.h |= flagb; /* Line 911, Address: 0x1027278 */
    } /* Line 912, Address: 0x1027294 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 915, Address: 0x102729c */
    }
  }


} /* Line 920, Address: 0x10272bc */


void scrollc_h(int lD4, int flagc) { /* Line 923, Address: 0x10272d0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 927, Address: 0x10272e0 */
  lD0.l = lD2.l + lD4; /* Line 928, Address: 0x10272ec */
  scrc_h_posit.l = lD0.l; /* Line 929, Address: 0x10272fc */

  lD1.w.h = lD0.w.l; /* Line 931, Address: 0x1027308 */
  lD1.w.l = lD0.w.h; /* Line 932, Address: 0x1027310 */
  lD1.w.l &= 16; /* Line 933, Address: 0x1027318 */

  bD3 = scrc_h_count; /* Line 935, Address: 0x1027324 */
  lD1.b.b4 ^= bD3; /* Line 936, Address: 0x1027330 */
  if (!lD1.b.b4) { /* Line 937, Address: 0x1027344 */
    scrc_h_count ^= 16; /* Line 938, Address: 0x1027350 */
    lD0.l -= lD2.l; /* Line 939, Address: 0x1027364 */
    if ((long int)lD0.l < 0) { /* Line 940, Address: 0x1027374 */
      scrflagc.b.h |= flagc; /* Line 941, Address: 0x1027388 */
    } /* Line 942, Address: 0x10273a4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 945, Address: 0x10273ac */
    }
  }


} /* Line 950, Address: 0x10273cc */











void scrollz_h(int lD4, int flagz) { /* Line 962, Address: 0x10273e0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 966, Address: 0x10273f0 */
  lD0.l = lD2.l + lD4; /* Line 967, Address: 0x10273fc */
  scrz_h_posit.l = lD0.l; /* Line 968, Address: 0x102740c */

  lD1.w.h = lD0.w.l; /* Line 970, Address: 0x1027418 */
  lD1.w.l = lD0.w.h; /* Line 971, Address: 0x1027420 */
  lD1.w.l &= 16; /* Line 972, Address: 0x1027428 */

  bD3 = scrz_h_count; /* Line 974, Address: 0x1027434 */
  lD1.b.b4 ^= bD3; /* Line 975, Address: 0x1027440 */
  if (!lD1.b.b4) { /* Line 976, Address: 0x1027454 */
    scrz_h_count ^= 16; /* Line 977, Address: 0x1027460 */
    lD0.l -= lD2.l; /* Line 978, Address: 0x1027474 */
    if ((long int)lD0.l < 0) { /* Line 979, Address: 0x1027484 */
      scrflagz.b.h |= flagz; /* Line 980, Address: 0x1027498 */
    } /* Line 981, Address: 0x10274b4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 984, Address: 0x10274bc */
    }
  }


} /* Line 989, Address: 0x10274dc */













void scrollwrtadva() { /* Line 1003, Address: 0x10274f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1009, Address: 0x102750c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1010, Address: 0x1027510 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1011, Address: 0x102751c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1012, Address: 0x1027528 */
  pScrFlag = &scrflagb.b.h; /* Line 1013, Address: 0x1027530 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1014, Address: 0x1027538 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1016, Address: 0x1027554 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1017, Address: 0x1027560 */
  pScrFlag = &scrflagc.b.h; /* Line 1018, Address: 0x102756c */
  scrollwrtc(); /* Line 1019, Address: 0x1027574 */

} /* Line 1021, Address: 0x102757c */












void scrollwrt() { /* Line 1034, Address: 0x10275a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1043, Address: 0x10275c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1044, Address: 0x10275c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1045, Address: 0x10275d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1046, Address: 0x10275dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1047, Address: 0x10275e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1048, Address: 0x10275ec */

  VramBase = 16384; /* Line 1050, Address: 0x1027608 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1051, Address: 0x102760c */
  wV_posiw = scra_v_posiw.w.h; /* Line 1052, Address: 0x1027618 */
  pMapWk = (unsigned char*)mapwka; /* Line 1053, Address: 0x1027624 */
  pScrFlag = &scrflagaw.b.h; /* Line 1054, Address: 0x102762c */

  if (*pScrFlag) { /* Line 1056, Address: 0x1027634 */
    if (*pScrFlag & 1) { /* Line 1057, Address: 0x1027640 */
      *pScrFlag &= 254; /* Line 1058, Address: 0x1027654 */

      lD4.l = -16; /* Line 1060, Address: 0x1027660 */
      wD5 = 65520; /* Line 1061, Address: 0x1027668 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1063, Address: 0x1027670 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1065, Address: 0x1027690 */
    }




    if (*pScrFlag & 2) { /* Line 1071, Address: 0x10276bc */
      *pScrFlag &= 253; /* Line 1072, Address: 0x10276d0 */

      lD4.l = 224; /* Line 1074, Address: 0x10276dc */
      wD5 = 65520; /* Line 1075, Address: 0x10276e4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1076, Address: 0x10276ec */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1078, Address: 0x102770c */
    }




    if (*pScrFlag & 4) { /* Line 1084, Address: 0x1027738 */
      *pScrFlag &= 251; /* Line 1085, Address: 0x102774c */

      lD4.l = -16; /* Line 1087, Address: 0x1027758 */
      wD5 = 65520; /* Line 1088, Address: 0x1027760 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1089, Address: 0x1027768 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1091, Address: 0x1027788 */
    }




    if (*pScrFlag & 8) { /* Line 1097, Address: 0x10277b4 */
      *pScrFlag &= 247; /* Line 1098, Address: 0x10277c8 */

      lD4.l = -16; /* Line 1100, Address: 0x10277d4 */
      wD5 = 320; /* Line 1101, Address: 0x10277dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1102, Address: 0x10277e4 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1104, Address: 0x1027804 */
    }
  }






} /* Line 1113, Address: 0x1027830 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1130, Address: 0x1027860 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1135, Address: 0x1027880 */
    if (*pScrFlag & 1) { /* Line 1136, Address: 0x1027890 */
      *pScrFlag &= 254; /* Line 1137, Address: 0x10278a8 */

      lD4.l = -16; /* Line 1139, Address: 0x10278bc */
      wD5 = 65520; /* Line 1140, Address: 0x10278c4 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1142, Address: 0x10278cc */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1144, Address: 0x10278ec */
    }




    if (*pScrFlag & 2) { /* Line 1150, Address: 0x1027918 */
      *pScrFlag &= 253; /* Line 1151, Address: 0x1027930 */

      lD4.l = 224; /* Line 1153, Address: 0x1027944 */
      wD5 = 65520; /* Line 1154, Address: 0x102794c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1155, Address: 0x1027954 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1157, Address: 0x1027974 */
    }




    if (*pScrFlag & 4) { /* Line 1163, Address: 0x10279a0 */
      *pScrFlag &= 251; /* Line 1164, Address: 0x10279b8 */

      lD4.l = -16; /* Line 1166, Address: 0x10279cc */
      wD5 = 65520; /* Line 1167, Address: 0x10279d4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1168, Address: 0x10279dc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1170, Address: 0x10279fc */
    }




    if (*pScrFlag & 8) { /* Line 1176, Address: 0x1027a28 */
      *pScrFlag &= 247; /* Line 1177, Address: 0x1027a40 */

      lD4.l = -16; /* Line 1179, Address: 0x1027a54 */
      wD5 = 320; /* Line 1180, Address: 0x1027a5c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1181, Address: 0x1027a64 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1183, Address: 0x1027a84 */
    }
  }






} /* Line 1192, Address: 0x1027ab0 */






void scrollwrtc() {} /* Line 1199, Address: 0x1027ad0 */




void scrollwrtz() {} /* Line 1204, Address: 0x1027ae0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1222, Address: 0x1027af0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1235, Address: 0x1027b18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1238, Address: 0x1027b38 */
    pTilePoint->x += 2; /* Line 1239, Address: 0x1027b4c */
    if (pTilePoint->x >= 64) { /* Line 1240, Address: 0x1027b60 */
      pTilePoint->x -= 64; /* Line 1241, Address: 0x1027b74 */
    }
    xOffs += 16; /* Line 1243, Address: 0x1027b88 */
  } while (--lpcnt >= 0); /* Line 1244, Address: 0x1027b94 */
} /* Line 1245, Address: 0x1027ba8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1249, Address: 0x1027bc0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1253, Address: 0x1027be8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1256, Address: 0x1027c08 */
    pTilePoint->x += 2; /* Line 1257, Address: 0x1027c1c */
    if (pTilePoint->x >= 64) { /* Line 1258, Address: 0x1027c30 */
      pTilePoint->x -= 64; /* Line 1259, Address: 0x1027c44 */
    }
    xOffs += 16; /* Line 1261, Address: 0x1027c58 */
  } while (--lpcnt >= 0); /* Line 1262, Address: 0x1027c64 */
} /* Line 1263, Address: 0x1027c78 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1283, Address: 0x1027c90 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1287, Address: 0x1027cb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1290, Address: 0x1027cd8 */
    pTilePoint->y += 2; /* Line 1291, Address: 0x1027cec */
    if (pTilePoint->y >= 32) { /* Line 1292, Address: 0x1027cfc */
      pTilePoint->y -= 32; /* Line 1293, Address: 0x1027d10 */
    }
    yOffs += 16; /* Line 1295, Address: 0x1027d20 */
  } while (--lpcnt >= 0); /* Line 1296, Address: 0x1027d2c */
} /* Line 1297, Address: 0x1027d40 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1316, Address: 0x1027d50 */
  int base = 0; /* Line 1317, Address: 0x1027d84 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1322, Address: 0x1027d88 */

    base = 1; /* Line 1324, Address: 0x1027d98 */
  } /* Line 1325, Address: 0x1027d9c */
  else if (VramBase == 16384) { /* Line 1326, Address: 0x1027da4 */

    base = 0; /* Line 1328, Address: 0x1027db4 */
  }
  x = pTilePoint->x; /* Line 1330, Address: 0x1027db8 */
  y = pTilePoint->y; /* Line 1331, Address: 0x1027dc0 */


  frip = BlkIndex & 6144; /* Line 1334, Address: 0x1027dc8 */
  BlkIndex &= 1023; /* Line 1335, Address: 0x1027dd0 */
  if (frip == 6144) { /* Line 1336, Address: 0x1027ddc */

    p0 = 3, p1 = 2; /* Line 1338, Address: 0x1027de8 */
    p2 = 1, p3 = 0; /* Line 1339, Address: 0x1027df0 */
  } /* Line 1340, Address: 0x1027df8 */
  else if (frip & 4096) { /* Line 1341, Address: 0x1027e00 */

    p0 = 2, p1 = 3; /* Line 1343, Address: 0x1027e0c */
    p2 = 0, p3 = 1; /* Line 1344, Address: 0x1027e14 */
  } /* Line 1345, Address: 0x1027e1c */
  else if (frip & 2048) { /* Line 1346, Address: 0x1027e24 */

    p0 = 1, p1 = 0; /* Line 1348, Address: 0x1027e30 */
    p2 = 3, p3 = 2; /* Line 1349, Address: 0x1027e38 */
  } /* Line 1350, Address: 0x1027e40 */
  else {

    p0 = 0, p1 = 1; /* Line 1353, Address: 0x1027e48 */
    p2 = 2, p3 = 3; /* Line 1354, Address: 0x1027e50 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1357, Address: 0x1027e58 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1358, Address: 0x1027e9c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1359, Address: 0x1027ee0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1360, Address: 0x1027f24 */

} /* Line 1362, Address: 0x1027f68 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1380, Address: 0x1027fa0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1381, Address: 0x1027fc0 */
} /* Line 1382, Address: 0x1027fe0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1384, Address: 0x1027ff0 */
  wH_posiw = 0; /* Line 1385, Address: 0x1028010 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1386, Address: 0x1028014 */
} /* Line 1387, Address: 0x1028034 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1394, Address: 0x1028050 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1400, Address: 0x1028080 */
  yOffs += wV_posiw; /* Line 1401, Address: 0x1028090 */





  if ((short)xOffs < 0) /* Line 1407, Address: 0x10280a0 */
    xOffs = 0; /* Line 1408, Address: 0x10280bc */
  if ((short)yOffs < 0) /* Line 1409, Address: 0x10280c0 */
    yOffs = 0; /* Line 1410, Address: 0x10280dc */
  if ((short)xOffs >= 16384) /* Line 1411, Address: 0x10280e0 */
    xOffs = 16383; /* Line 1412, Address: 0x1028100 */
  if ((short)yOffs >= 2048) /* Line 1413, Address: 0x1028108 */
    yOffs = 2047; /* Line 1414, Address: 0x1028128 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1415, Address: 0x1028130 */
  if (i < 0) i = 0; /* Line 1416, Address: 0x1028178 */

  ScreenNo = pMapWk[i] & 127; /* Line 1418, Address: 0x1028184 */

  if (ScreenNo) { /* Line 1420, Address: 0x10281a0 */




    xOffs &= 32767; /* Line 1425, Address: 0x10281a8 */
    yOffs &= 32767; /* Line 1426, Address: 0x10281b4 */


    xBlk = xOffs; /* Line 1429, Address: 0x10281c0 */
    xBlk %= 256; /* Line 1430, Address: 0x10281c8 */
    xBlk /= 16; /* Line 1431, Address: 0x10281e8 */
    yBlk = yOffs; /* Line 1432, Address: 0x1028204 */
    yBlk %= 256; /* Line 1433, Address: 0x102820c */
    yBlk /= 16; /* Line 1434, Address: 0x102822c */

    lpw = pmapwk; /* Line 1436, Address: 0x1028248 */
    lpw += xBlk; /* Line 1437, Address: 0x1028250 */
    lpw += yBlk * 16; /* Line 1438, Address: 0x1028258 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1439, Address: 0x1028264 */
    *pIndex = *lpw; /* Line 1440, Address: 0x102827c */

    return 1; /* Line 1442, Address: 0x102828c */
  }

  *pIndex = 0; /* Line 1445, Address: 0x1028298 */
  return 0; /* Line 1446, Address: 0x10282a0 */
} /* Line 1447, Address: 0x10282a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1467, Address: 0x10282d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1475, Address: 0x10282f8 */
  if (ScreenNo) { /* Line 1476, Address: 0x102835c */





    xBlk = xOffs; /* Line 1482, Address: 0x1028364 */
    xBlk %= 256; /* Line 1483, Address: 0x102836c */
    xBlk /= 16; /* Line 1484, Address: 0x102838c */
    yBlk = yOffs; /* Line 1485, Address: 0x10283a8 */
    yBlk %= 256; /* Line 1486, Address: 0x10283b0 */
    yBlk /= 16; /* Line 1487, Address: 0x10283d0 */


    lpw = pmapwk; /* Line 1490, Address: 0x10283ec */
    lpw += xBlk; /* Line 1491, Address: 0x10283f4 */
    lpw += yBlk * 16; /* Line 1492, Address: 0x10283fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1493, Address: 0x1028408 */
    *ppBlockNo = lpw; /* Line 1494, Address: 0x1028420 */
    *pIndex = *lpw; /* Line 1495, Address: 0x1028428 */




    return 1; /* Line 1500, Address: 0x1028438 */
  }

  *pIndex = 0; /* Line 1503, Address: 0x1028444 */
  return 0; /* Line 1504, Address: 0x102844c */
} /* Line 1505, Address: 0x1028450 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1519, Address: 0x1028470 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1526, Address: 0x102848c */
  pMapWk = (unsigned char*)mapwka; /* Line 1527, Address: 0x1028490 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1528, Address: 0x1028498 */
    *pBlockIndex = BlockNo; /* Line 1529, Address: 0x10284bc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1530, Address: 0x10284c8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1531, Address: 0x10284e0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1532, Address: 0x10284f4 */
    }
  }


} /* Line 1537, Address: 0x102850c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1551, Address: 0x1028530 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1552, Address: 0x102853c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1553, Address: 0x1028568 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1554, Address: 0x10285b4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1555, Address: 0x10285e0 */

          return 0; /* Line 1557, Address: 0x102862c */
        }
      }
    }
  }

  return 1; /* Line 1563, Address: 0x1028638 */
} /* Line 1564, Address: 0x102863c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1581, Address: 0x1028650 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1582, Address: 0x102866c */

} /* Line 1584, Address: 0x1028688 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1586, Address: 0x10286a0 */
  wH_posiw = 0; /* Line 1587, Address: 0x10286bc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1588, Address: 0x10286c0 */

} /* Line 1590, Address: 0x10286dc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1592, Address: 0x10286f0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1593, Address: 0x1028704 */

} /* Line 1595, Address: 0x1028720 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1597, Address: 0x1028730 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1598, Address: 0x102874c */

} /* Line 1600, Address: 0x1028768 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1602, Address: 0x1028780 */
  xOffs += wH_posiw; /* Line 1603, Address: 0x1028798 */
  yOffs += wV_posiw; /* Line 1604, Address: 0x10287a8 */
  yOffs &= 240; /* Line 1605, Address: 0x10287b8 */
  xOffs &= 496; /* Line 1606, Address: 0x10287c4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1608, Address: 0x10287d0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1609, Address: 0x10287fc */


} /* Line 1612, Address: 0x1028828 */















void mapwrt() { /* Line 1628, Address: 0x1028840 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1633, Address: 0x1028858 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1634, Address: 0x1028864 */
  pMapWk = (unsigned char*)mapwka; /* Line 1635, Address: 0x1028870 */
  VramBase = 16384; /* Line 1636, Address: 0x1028878 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1637, Address: 0x102887c */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1639, Address: 0x1028894 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1640, Address: 0x10288a0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1641, Address: 0x10288ac */
  VramBase = 24576; /* Line 1642, Address: 0x10288b4 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1644, Address: 0x10288b8 */

} /* Line 1646, Address: 0x10288d0 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1650, Address: 0x10288f0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1651, Address: 0x1028908 */
} /* Line 1652, Address: 0x1028928 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1657, Address: 0x1028940 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1661, Address: 0x1028960 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1664, Address: 0x102897c */



    wD4 += 16; /* Line 1668, Address: 0x10289a4 */
  } while ((short)--wD6 >= 0); /* Line 1669, Address: 0x10289b0 */

} /* Line 1671, Address: 0x10289d8 */













































































































void mapinit() { /* Line 1781, Address: 0x10289f0 */

  colorset2(mapinittbl.colorno2); /* Line 1783, Address: 0x10289f8 */
  colorset(mapinittbl.colorno2); /* Line 1784, Address: 0x1028a0c */

  if (plflag) enecginit(); /* Line 1786, Address: 0x1028a20 */
  if (play_start & 2) divdevset(); /* Line 1787, Address: 0x1028a38 */
} /* Line 1788, Address: 0x1028a58 */










void mapset() {} /* Line 1799, Address: 0x1028a70 */
