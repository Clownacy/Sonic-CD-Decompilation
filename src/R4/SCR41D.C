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















































































void enecginit() {} /* Line 128, Address: 0x1025430 */



void divdevset() {} /* Line 132, Address: 0x1025440 */














































sprite_status* main_chk() {
  if (!main_play) return &actwk[0];  /* Line 180, Address: 0x1025450 */
  else return &actwk[1]; /* Line 181, Address: 0x1025470 */
} /* Line 182, Address: 0x1025478 */


void scr_set() { /* Line 185, Address: 0x1025480 */






  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x102548c */
    4, 0, 7319, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x10254c0 */

  i = 0; /* Line 199, Address: 0x1025508 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x102550c */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x1025528 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x102553c */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x1025558 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x102556c */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x1025588 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x102559c */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x10255b8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x10255cc */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x10255e8 */
  scra_h_count = 16; /* Line 211, Address: 0x102560c */
  scra_v_count = 16; /* Line 212, Address: 0x1025618 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x1025624 */
  scra_hline = 160; /* Line 215, Address: 0x1025640 */

  playposiset(); /* Line 217, Address: 0x102564c */
} /* Line 218, Address: 0x1025654 */



void playposiset() { /* Line 222, Address: 0x1025670 */
  unsigned short endplpositbl[16] = { /* Line 223, Address: 0x1025684 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[2] = { /* Line 233, Address: 0x10256b8 */
    80,
    64
  };
  unsigned char playmapnotbl[4] = { /* Line 237, Address: 0x10256d4 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 245, Address: 0x1025700 */

    playload(); /* Line 247, Address: 0x1025714 */
    xWk = actwk[0].xposi.w.h; /* Line 248, Address: 0x102571c */
    yWk = actwk[0].yposi.w.h; /* Line 249, Address: 0x102572c */
    if (yWk < 0) yWk = 0; /* Line 250, Address: 0x102573c */
  } /* Line 251, Address: 0x1025750 */
  else {


    if (demoflag.w < 0) { /* Line 255, Address: 0x1025758 */

      i = (enddemono - 1) * 4; /* Line 257, Address: 0x1025770 */
      xWk = actwk[0].xposi.w.h = endplpositbl[i++]; /* Line 258, Address: 0x1025788 */
      yWk = actwk[0].yposi.w.h = endplpositbl[i++]; /* Line 259, Address: 0x10257ac */
    } /* Line 260, Address: 0x10257d0 */
    else {


      i = demoflag.w * 4; /* Line 264, Address: 0x10257d8 */
      xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 265, Address: 0x10257ec */
      yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 266, Address: 0x1025810 */
    }
  }

  if ((unsigned short)xWk > 160) { /* Line 270, Address: 0x1025834 */
    xWk -= 160; /* Line 271, Address: 0x1025848 */
  } /* Line 272, Address: 0x1025854 */
  else {
    xWk = 0; /* Line 274, Address: 0x102585c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 278, Address: 0x1025860 */
    xWk = scralim_right; /* Line 279, Address: 0x1025884 */
  }
  scra_h_posit.w.h = xWk; /* Line 281, Address: 0x1025894 */

  if ((unsigned short)yWk > 96) { /* Line 283, Address: 0x102589c */
    yWk -= 96; /* Line 284, Address: 0x10258b0 */
  } /* Line 285, Address: 0x10258bc */
  else {
    yWk = 0; /* Line 287, Address: 0x10258c4 */
  }

  if (scralim_down < yWk) { /* Line 290, Address: 0x10258c8 */
    yWk = scralim_down; /* Line 291, Address: 0x10258ec */
  }

  scra_v_posit.w.h = yWk; /* Line 294, Address: 0x10258fc */


  scrbinit(xWk); /* Line 297, Address: 0x1025904 */

  i = 0; /* Line 299, Address: 0x1025910 */
  loopmapno = playmapnotbl[i++]; /* Line 300, Address: 0x1025914 */
  loopmapno2 = playmapnotbl[i++]; /* Line 301, Address: 0x102592c */
  ballmapno = playmapnotbl[i++]; /* Line 302, Address: 0x1025944 */
  ballmapno2 = playmapnotbl[i++]; /* Line 303, Address: 0x102595c */


} /* Line 306, Address: 0x1025974 */



void scrbinit(short yWk) { /* Line 310, Address: 0x1025990 */
  uint_union data;
  int i;

  data.l = 0; /* Line 314, Address: 0x102599c */
  data.w.l = scra_v_posit.w.h; /* Line 315, Address: 0x10259a0 */
  data.w.l >>= 1; /* Line 316, Address: 0x10259ac */

  scrb_v_posit.w.h = data.w.l; /* Line 318, Address: 0x10259b8 */
  scrb_v_posit.w.l = 0; /* Line 319, Address: 0x10259c4 */
  scrc_v_posit.w.h = data.w.l; /* Line 320, Address: 0x10259cc */
  scrz_v_posit.w.h = data.w.l; /* Line 321, Address: 0x10259d8 */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 323, Address: 0x10259e4 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 324, Address: 0x1025a08 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 325, Address: 0x1025a34 */
  for (i = 0; i < 30; ++i) { /* Line 326, Address: 0x1025a60 */

    hscrollwork[i] = 0; /* Line 328, Address: 0x1025a6c */
  } /* Line 329, Address: 0x1025a80 */
} /* Line 330, Address: 0x1025a90 */



void scroll() { /* Line 334, Address: 0x1025aa0 */
  uint_union data;
  int_union temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 340, Address: 0x1025ab0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 343, Address: 0x1025ac0 */
  scrchk(); /* Line 344, Address: 0x1025aec */
  scroll_h(); /* Line 345, Address: 0x1025af4 */
  scroll_v(); /* Line 346, Address: 0x1025afc */

  vscroll.w.h = scra_v_posit.w.h; /* Line 348, Address: 0x1025b04 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 349, Address: 0x1025b14 */



  temp1.l = (long int)(scra_hz << 2) * 3; /* Line 353, Address: 0x1025b24 */
  temp2.l = scra_vz << 7; /* Line 354, Address: 0x1025b54 */
  scrollb_hv(&temp1, &temp2); /* Line 355, Address: 0x1025b6c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 357, Address: 0x1025b7c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 358, Address: 0x1025b8c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 359, Address: 0x1025b9c */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 361, Address: 0x1025bac */
  scrflagz.b.h = 0; /* Line 362, Address: 0x1025be0 */
  scrflagc.b.h = 0; /* Line 363, Address: 0x1025be8 */

  hsCount = 0; /* Line 365, Address: 0x1025bf0 */

  for (i = 0; i < 192; ++i) { /* Line 367, Address: 0x1025bf4 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 370, Address: 0x1025c00 */
    ++hsCount; /* Line 371, Address: 0x1025c30 */
  } /* Line 372, Address: 0x1025c34 */

  data.w.l = -scra_h_posit.w.h; /* Line 374, Address: 0x1025c44 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 375, Address: 0x1025c60 */
  data.w.l = scrb_v_posit.w.h; /* Line 376, Address: 0x1025c84 */
  data.w.l &= 2040; /* Line 377, Address: 0x1025c90 */
  data.w.l >>= 2; /* Line 378, Address: 0x1025c9c */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 379, Address: 0x1025ca8 */

} /* Line 381, Address: 0x1025cf8 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 419, Address: 0x1025d10 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 426, Address: 0x1025d2c */
  data1.b.l = waterdirec.b.h; /* Line 427, Address: 0x1025d34 */
  data2.b.l = waterdirec.b.h; /* Line 428, Address: 0x1025d40 */
  waterdirec.w += 128; /* Line 429, Address: 0x1025d4c */
  data1.w += scrb_v_posit.w.h; /* Line 430, Address: 0x1025d60 */
  data1.b.h = 0; /* Line 431, Address: 0x1025d74 */
  data2.w += scra_v_posit.w.h; /* Line 432, Address: 0x1025d78 */
  data2.b.h = 0; /* Line 433, Address: 0x1025d8c */

  VPosi &= 7; /* Line 435, Address: 0x1025d90 */
  hsw.w.l = hscrollwork[offs++]; /* Line 436, Address: 0x1025d9c */
  avp = scra_v_posit.w.h; /* Line 437, Address: 0x1025dc4 */
  i = 232; /* Line 438, Address: 0x1025dd4 */


  do {
    if (avp > waterposi) { /* Line 442, Address: 0x1025dd8 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 447, Address: 0x1025dfc */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 448, Address: 0x1025e04 */
        ++pHScrollBuff; /* Line 449, Address: 0x1025e54 */
        ++data1.b.l; /* Line 450, Address: 0x1025e58 */
        ++data2.b.l; /* Line 451, Address: 0x1025e64 */
        ++VPosi; /* Line 452, Address: 0x1025e70 */
        if (VPosi == 8) { /* Line 453, Address: 0x1025e7c */

          VPosi = 0; /* Line 455, Address: 0x1025e94 */
          hsw.w.l = hscrollwork[offs++]; /* Line 456, Address: 0x1025e98 */
        }
      } while (--i > 0); /* Line 458, Address: 0x1025ec0 */

      return; /* Line 460, Address: 0x1025ecc */
    }
    pHScrollBuff->l = hsw.l; /* Line 462, Address: 0x1025ed4 */
    ++pHScrollBuff; /* Line 463, Address: 0x1025edc */
    ++avp; /* Line 464, Address: 0x1025ee0 */
    ++data1.b.l; /* Line 465, Address: 0x1025eec */
    ++data2.b.l; /* Line 466, Address: 0x1025ef8 */
    ++VPosi; /* Line 467, Address: 0x1025f04 */
    if (VPosi == 8) { /* Line 468, Address: 0x1025f10 */

      VPosi = 0; /* Line 470, Address: 0x1025f28 */
      hsw.w.l = hscrollwork[offs++]; /* Line 471, Address: 0x1025f2c */
    }
  } while (--i > 0); /* Line 473, Address: 0x1025f54 */

} /* Line 475, Address: 0x1025f60 */











void scroll_h() { /* Line 487, Address: 0x1025f80 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 490, Address: 0x1025f8c */
  scrh_move(); /* Line 491, Address: 0x1025f98 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 492, Address: 0x1025fa0 */
    scra_h_count ^= 16; /* Line 493, Address: 0x1025fd4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 494, Address: 0x1025fe8 */
      scrflaga.b.h |= 4; /* Line 495, Address: 0x1026014 */
    } /* Line 496, Address: 0x1026028 */
    else {

      scrflaga.b.h |= 8; /* Line 499, Address: 0x1026030 */
    }
  }


} /* Line 504, Address: 0x1026044 */

void scrh_move() { /* Line 506, Address: 0x1026060 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 509, Address: 0x102606c */
  wD0 -= scra_h_posit.w.h; /* Line 510, Address: 0x1026078 */
  wD0 -= scra_hline; /* Line 511, Address: 0x102608c */
  if (wD0 == 0) { /* Line 512, Address: 0x10260a0 */

    scra_hz = 0; /* Line 514, Address: 0x10260ac */
  } /* Line 515, Address: 0x10260b4 */
  else if ((short)wD0 < 0) { /* Line 516, Address: 0x10260bc */
    left_check(wD0); /* Line 517, Address: 0x10260d4 */
  } /* Line 518, Address: 0x10260e0 */
  else {
    right_check(wD0); /* Line 520, Address: 0x10260e8 */
  }

} /* Line 523, Address: 0x10260f4 */


void right_check(unsigned short wD0) { /* Line 526, Address: 0x1026110 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 529, Address: 0x102611c */
    wD0 = 16; /* Line 530, Address: 0x102613c */
  }

  wD0 += scra_h_posit.w.h; /* Line 533, Address: 0x1026144 */
  if (scralim_right < (short)wD0) { /* Line 534, Address: 0x102615c */
    wD0 = scralim_right; /* Line 535, Address: 0x102618c */
  }

  wD1 = wD0; /* Line 538, Address: 0x1026198 */
  wD1 -= scra_h_posit.w.h; /* Line 539, Address: 0x10261a0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 540, Address: 0x10261b4 */
  scra_h_posit.w.h = wD0; /* Line 541, Address: 0x10261e4 */
  scra_hz = wD1; /* Line 542, Address: 0x10261f0 */

} /* Line 544, Address: 0x10261f8 */


void left_check(unsigned short wD0) { /* Line 547, Address: 0x1026210 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 550, Address: 0x102621c */
    wD0 = -16; /* Line 551, Address: 0x102623c */
  }

  wD0 += scra_h_posit.w.h; /* Line 554, Address: 0x1026244 */
  if (scralim_left > (short)wD0) { /* Line 555, Address: 0x102625c */
    wD0 = scralim_left; /* Line 556, Address: 0x102628c */
  }

  wD1 = wD0; /* Line 559, Address: 0x1026298 */
  wD1 -= scra_h_posit.w.h; /* Line 560, Address: 0x10262a0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 561, Address: 0x10262b4 */
  scra_h_posit.w.h = wD0; /* Line 562, Address: 0x10262e4 */
  scra_hz = wD1; /* Line 563, Address: 0x10262f0 */

} /* Line 565, Address: 0x10262f8 */


















void scroll_v() { /* Line 584, Address: 0x1026310 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 587, Address: 0x102631c */
  if (actwk[0].cddat & 4) { /* Line 588, Address: 0x1026348 */
    wD0 -= 5; /* Line 589, Address: 0x1026360 */
  }

  if (actwk[0].cddat & 2) { /* Line 592, Address: 0x1026368 */
    wD0 += 32; /* Line 593, Address: 0x1026380 */
    if ((unsigned short)scra_vline > wD0) { /* Line 594, Address: 0x1026388 */
      wD0 -= scra_vline; /* Line 595, Address: 0x10263a8 */
      sv_move_main2(wD0); /* Line 596, Address: 0x10263bc */
      return; /* Line 597, Address: 0x10263c8 */
    }
    wD0 -= scra_vline; /* Line 599, Address: 0x10263d0 */
    if (wD0 >= 64) { /* Line 600, Address: 0x10263e4 */
      wD0 -= 64; /* Line 601, Address: 0x10263f4 */
      sv_move_main2(wD0); /* Line 602, Address: 0x10263fc */
      return; /* Line 603, Address: 0x1026408 */
    }
    wD0 -= 64; /* Line 605, Address: 0x1026410 */
    if (limmoveflag == 0) goto label1; /* Line 606, Address: 0x1026418 */
    sv_move_sub2(); /* Line 607, Address: 0x102642c */
    return; /* Line 608, Address: 0x1026434 */
  }




  wD0 -= scra_vline; /* Line 614, Address: 0x102643c */
  if (wD0) { /* Line 615, Address: 0x1026450 */
    sv_move_main(wD0); /* Line 616, Address: 0x1026458 */
    return; /* Line 617, Address: 0x1026464 */
  }
  if (limmoveflag == 0) { /* Line 619, Address: 0x102646c */
    sv_move_sub2(); /* Line 620, Address: 0x1026480 */
    return; /* Line 621, Address: 0x1026488 */
  }


label1:
  scra_vz = 0; /* Line 626, Address: 0x1026490 */

} /* Line 628, Address: 0x1026498 */





void sv_move_main(unsigned short wD0) { /* Line 634, Address: 0x10264b0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 637, Address: 0x10264c0 */
    sv_move_main1(wD0); /* Line 638, Address: 0x10264dc */
  } /* Line 639, Address: 0x10264e8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 642, Address: 0x10264f0 */
    if ((short)wD1 < 0) { /* Line 643, Address: 0x10264fc */
      wD1 = -(short)wD1; /* Line 644, Address: 0x1026514 */
    }

    if (wD1 >= 2048) { /* Line 647, Address: 0x1026530 */
      sv_move_main2(wD0); /* Line 648, Address: 0x1026540 */
    } /* Line 649, Address: 0x102654c */
    else {
      if ((short)wD0 > 6) { /* Line 651, Address: 0x1026554 */
        sv_move_plus(1536); /* Line 652, Address: 0x1026574 */
      } /* Line 653, Address: 0x1026580 */
      else if ((short)wD0 < -6) { /* Line 654, Address: 0x1026588 */
        sv_move_minus(1536); /* Line 655, Address: 0x10265a8 */
      } /* Line 656, Address: 0x10265b4 */
      else {
        sv_move_sub(wD0); /* Line 658, Address: 0x10265bc */
      }
    }
  }
} /* Line 662, Address: 0x10265c8 */



void sv_move_main1(unsigned short wD0) { /* Line 666, Address: 0x10265e0 */

  if ((short)wD0 > 2) { /* Line 668, Address: 0x10265ec */
    sv_move_plus(512); /* Line 669, Address: 0x102660c */
  } /* Line 670, Address: 0x1026618 */
  else if ((short)wD0 < -2) { /* Line 671, Address: 0x1026620 */
    sv_move_minus(512); /* Line 672, Address: 0x1026640 */
  } /* Line 673, Address: 0x102664c */
  else {
    sv_move_sub(wD0); /* Line 675, Address: 0x1026654 */
  }

} /* Line 678, Address: 0x1026660 */


void sv_move_main2(unsigned short wD0) { /* Line 681, Address: 0x1026670 */

  if ((short)wD0 > 16) { /* Line 683, Address: 0x102667c */
    sv_move_plus(4096); /* Line 684, Address: 0x102669c */
  } /* Line 685, Address: 0x10266a8 */
  else if ((short)wD0 < -16) { /* Line 686, Address: 0x10266b0 */
    sv_move_minus(4096); /* Line 687, Address: 0x10266d0 */
  } /* Line 688, Address: 0x10266dc */
  else {
    sv_move_sub(wD0); /* Line 690, Address: 0x10266e4 */
  }

} /* Line 693, Address: 0x10266f0 */


void sv_move_sub2() { /* Line 696, Address: 0x1026700 */
  limmoveflag = 0; /* Line 697, Address: 0x1026708 */
  sv_move_sub(0); /* Line 698, Address: 0x1026710 */
} /* Line 699, Address: 0x102671c */


void sv_move_sub(unsigned short wD0) { /* Line 702, Address: 0x1026730 */
  int_union lD1;

  lD1.w.h = 0; /* Line 705, Address: 0x102673c */
  lD1.w.l = wD0; /* Line 706, Address: 0x1026740 */
  lD1.l += scra_v_posit.w.h; /* Line 707, Address: 0x1026748 */
  if ((short)wD0 > 0) { /* Line 708, Address: 0x1026764 */
    scrv_down_ch(lD1); /* Line 709, Address: 0x1026780 */
  } /* Line 710, Address: 0x102678c */
  else {
    scrv_up_ch(lD1); /* Line 712, Address: 0x1026794 */
  }

} /* Line 715, Address: 0x10267a0 */




void sv_move_minus(unsigned short wD1) { /* Line 720, Address: 0x10267b0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 724, Address: 0x10267c0 */
  lD1.l <<= 8; /* Line 725, Address: 0x10267dc */
  lD1.l += scra_v_posit.l; /* Line 726, Address: 0x10267e8 */

  wk = lD1.w.h; /* Line 728, Address: 0x10267fc */
  lD1.w.h = lD1.w.l; /* Line 729, Address: 0x1026804 */
  lD1.w.l = wk; /* Line 730, Address: 0x102680c */
  scrv_up_ch(lD1); /* Line 731, Address: 0x1026810 */
} /* Line 732, Address: 0x102681c */



void scrv_up_ch(int_union lD1) { /* Line 736, Address: 0x1026830 */
  if (scralim_up >= lD1.w.l) { /* Line 737, Address: 0x102683c */
    if (lD1.w.l < -255) { /* Line 738, Address: 0x1026864 */
      lD1.w.l &= 2047; /* Line 739, Address: 0x102687c */
      actwk[0].yposi.w.h &= 2047; /* Line 740, Address: 0x1026888 */
      scra_v_posit.w.h &= 2047; /* Line 741, Address: 0x102689c */
      scrb_v_posit.w.h &= 1023; /* Line 742, Address: 0x10268b0 */
    } /* Line 743, Address: 0x10268c4 */
    else {

      lD1.w.l = scralim_up; /* Line 746, Address: 0x10268cc */
    }
  }
  scrv_move(lD1); /* Line 749, Address: 0x10268d8 */

} /* Line 751, Address: 0x10268e4 */





void sv_move_plus(unsigned short wD1) { /* Line 757, Address: 0x1026900 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 761, Address: 0x1026910 */
  lD1.w.l = wD1; /* Line 762, Address: 0x1026914 */
  lD1.l <<= 8; /* Line 763, Address: 0x102691c */
  lD1.l += scra_v_posit.l; /* Line 764, Address: 0x1026928 */

  wk = lD1.w.h; /* Line 766, Address: 0x102693c */
  lD1.w.h = lD1.w.l; /* Line 767, Address: 0x1026944 */
  lD1.w.l = wk; /* Line 768, Address: 0x102694c */

  scrv_down_ch(lD1); /* Line 770, Address: 0x1026950 */

} /* Line 772, Address: 0x102695c */



void scrv_down_ch(int_union lD1) { /* Line 776, Address: 0x1026970 */
  if (scralim_down <= lD1.w.l) { /* Line 777, Address: 0x102697c */
    lD1.w.l -= 2048; /* Line 778, Address: 0x10269a4 */
    if (lD1.w.l > 0) { /* Line 779, Address: 0x10269b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 780, Address: 0x10269c4 */
      scra_v_posit.w.h -= 2048; /* Line 781, Address: 0x10269d8 */
      scrb_v_posit.w.h &= 1023; /* Line 782, Address: 0x10269ec */
    } /* Line 783, Address: 0x1026a00 */
    else {
      lD1.w.l = scralim_down; /* Line 785, Address: 0x1026a08 */
    }
  }
  scrv_move(lD1); /* Line 788, Address: 0x1026a14 */

} /* Line 790, Address: 0x1026a20 */


void scrv_move(int_union lD1) { /* Line 793, Address: 0x1026a30 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 796, Address: 0x1026a40 */

  wk = lD1.w.h; /* Line 798, Address: 0x1026a4c */
  lD1.w.h = lD1.w.l; /* Line 799, Address: 0x1026a54 */
  lD1.w.l = wk; /* Line 800, Address: 0x1026a5c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 802, Address: 0x1026a60 */
  scra_v_posit.l = lD1.l; /* Line 803, Address: 0x1026a88 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 806, Address: 0x1026a94 */
    scra_v_count ^= 16; /* Line 807, Address: 0x1026ac8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 808, Address: 0x1026adc */

      scrflaga.b.h |= 2; /* Line 810, Address: 0x1026b08 */
    } /* Line 811, Address: 0x1026b1c */
    else {
      scrflaga.b.h |= 1; /* Line 813, Address: 0x1026b24 */
    }
  }


} /* Line 818, Address: 0x1026b38 */



void scrollb_hv(int_union* lD4, int_union* lD5) { /* Line 822, Address: 0x1026b50 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 825, Address: 0x1026b5c */
  lD0.l += lD4->l; /* Line 826, Address: 0x1026b6c */
  scrb_h_posit.l = lD0.l; /* Line 827, Address: 0x1026b80 */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 829, Address: 0x1026b8c */

    scrb_h_count ^= 16; /* Line 831, Address: 0x1026bc0 */
    lD0.l -= lD2.l; /* Line 832, Address: 0x1026bd4 */
    if ((long int)lD0.l < 0) { /* Line 833, Address: 0x1026be4 */
      scrflagb.b.h |= 4; /* Line 834, Address: 0x1026bf8 */
    } /* Line 835, Address: 0x1026c0c */
    else {

      scrflagb.b.h |= 8; /* Line 838, Address: 0x1026c14 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 843, Address: 0x1026c28 */
  lD0.l += lD5->l; /* Line 844, Address: 0x1026c38 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 845, Address: 0x1026c4c */
  scrb_v_posit.l = lD0.l; /* Line 846, Address: 0x1026c64 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 848, Address: 0x1026c70 */

    scrb_v_count ^= 16; /* Line 850, Address: 0x1026ca4 */
    lD0.l -= lD3.l; /* Line 851, Address: 0x1026cb8 */
    if ((long int)lD0.l < 0) { /* Line 852, Address: 0x1026cc8 */
      scrflagb.b.h |= 1; /* Line 853, Address: 0x1026cdc */
    } /* Line 854, Address: 0x1026cf0 */
    else {

      scrflagb.b.h |= 2; /* Line 857, Address: 0x1026cf8 */
    }
  }


} /* Line 862, Address: 0x1026d0c */






void scrollb_v(unsigned short wD0) { /* Line 869, Address: 0x1026d20 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 872, Address: 0x1026d2c */
  scrb_v_posit.w.h = wD0; /* Line 873, Address: 0x1026d38 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 875, Address: 0x1026d44 */
    scrb_v_count ^= 16; /* Line 876, Address: 0x1026d70 */
    if ((short)wD3 > (short)wD0) { /* Line 877, Address: 0x1026d84 */
      scrflagb.b.h |= 1; /* Line 878, Address: 0x1026db4 */
    } /* Line 879, Address: 0x1026dc8 */
    else {

      scrflagb.b.h |= 2; /* Line 882, Address: 0x1026dd0 */
    }
  }


} /* Line 887, Address: 0x1026de4 */



void scrollb_h(int lD4, int flagb) { /* Line 891, Address: 0x1026e00 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 895, Address: 0x1026e10 */
  lD0.l = lD2.l + lD4; /* Line 896, Address: 0x1026e1c */
  scrb_h_posit.l = lD0.l; /* Line 897, Address: 0x1026e2c */

  lD1.w.h = lD0.w.l; /* Line 899, Address: 0x1026e38 */
  lD1.w.l = lD0.w.h; /* Line 900, Address: 0x1026e40 */
  lD1.w.l &= 16; /* Line 901, Address: 0x1026e48 */

  bD3 = scrb_h_count; /* Line 903, Address: 0x1026e54 */
  lD1.b.b4 ^= bD3; /* Line 904, Address: 0x1026e60 */
  if (!lD1.b.b4) { /* Line 905, Address: 0x1026e74 */
    scrb_h_count ^= 16; /* Line 906, Address: 0x1026e80 */
    lD0.l -= lD2.l; /* Line 907, Address: 0x1026e94 */
    if ((long int)lD0.l < 0) { /* Line 908, Address: 0x1026ea4 */
      scrflagb.b.h |= flagb; /* Line 909, Address: 0x1026eb8 */
    } /* Line 910, Address: 0x1026ed4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 913, Address: 0x1026edc */
    }
  }


} /* Line 918, Address: 0x1026efc */


void scrollc_h(int lD4, int flagc) { /* Line 921, Address: 0x1026f10 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 925, Address: 0x1026f20 */
  lD0.l = lD2.l + lD4; /* Line 926, Address: 0x1026f2c */
  scrc_h_posit.l = lD0.l; /* Line 927, Address: 0x1026f3c */

  lD1.w.h = lD0.w.l; /* Line 929, Address: 0x1026f48 */
  lD1.w.l = lD0.w.h; /* Line 930, Address: 0x1026f50 */
  lD1.w.l &= 16; /* Line 931, Address: 0x1026f58 */

  bD3 = scrc_h_count; /* Line 933, Address: 0x1026f64 */
  lD1.b.b4 ^= bD3; /* Line 934, Address: 0x1026f70 */
  if (!lD1.b.b4) { /* Line 935, Address: 0x1026f84 */
    scrc_h_count ^= 16; /* Line 936, Address: 0x1026f90 */
    lD0.l -= lD2.l; /* Line 937, Address: 0x1026fa4 */
    if ((long int)lD0.l < 0) { /* Line 938, Address: 0x1026fb4 */
      scrflagc.b.h |= flagc; /* Line 939, Address: 0x1026fc8 */
    } /* Line 940, Address: 0x1026fe4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 943, Address: 0x1026fec */
    }
  }


} /* Line 948, Address: 0x102700c */











void scrollz_h(int lD4, int flagz) { /* Line 960, Address: 0x1027020 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 964, Address: 0x1027030 */
  lD0.l = lD2.l + lD4; /* Line 965, Address: 0x102703c */
  scrz_h_posit.l = lD0.l; /* Line 966, Address: 0x102704c */

  lD1.w.h = lD0.w.l; /* Line 968, Address: 0x1027058 */
  lD1.w.l = lD0.w.h; /* Line 969, Address: 0x1027060 */
  lD1.w.l &= 16; /* Line 970, Address: 0x1027068 */

  bD3 = scrz_h_count; /* Line 972, Address: 0x1027074 */
  lD1.b.b4 ^= bD3; /* Line 973, Address: 0x1027080 */
  if (!lD1.b.b4) { /* Line 974, Address: 0x1027094 */
    scrz_h_count ^= 16; /* Line 975, Address: 0x10270a0 */
    lD0.l -= lD2.l; /* Line 976, Address: 0x10270b4 */
    if ((long int)lD0.l < 0) { /* Line 977, Address: 0x10270c4 */
      scrflagz.b.h |= flagz; /* Line 978, Address: 0x10270d8 */
    } /* Line 979, Address: 0x10270f4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 982, Address: 0x10270fc */
    }
  }


} /* Line 987, Address: 0x102711c */













void scrollwrtadva() { /* Line 1001, Address: 0x1027130 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1007, Address: 0x102714c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1008, Address: 0x1027150 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1009, Address: 0x102715c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1010, Address: 0x1027168 */
  pScrFlag = &scrflagb.b.h; /* Line 1011, Address: 0x1027170 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1012, Address: 0x1027178 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1014, Address: 0x1027194 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1015, Address: 0x10271a0 */
  pScrFlag = &scrflagc.b.h; /* Line 1016, Address: 0x10271ac */
  scrollwrtc(); /* Line 1017, Address: 0x10271b4 */

} /* Line 1019, Address: 0x10271bc */












void scrollwrt() { /* Line 1032, Address: 0x10271e0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1041, Address: 0x1027200 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1042, Address: 0x1027204 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1043, Address: 0x1027210 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1044, Address: 0x102721c */
  pScrFlag = &scrflagbw.b.h; /* Line 1045, Address: 0x1027224 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1046, Address: 0x102722c */

  VramBase = 16384; /* Line 1048, Address: 0x1027248 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1049, Address: 0x102724c */
  wV_posiw = scra_v_posiw.w.h; /* Line 1050, Address: 0x1027258 */
  pMapWk = (unsigned char*)mapwka; /* Line 1051, Address: 0x1027264 */
  pScrFlag = &scrflagaw.b.h; /* Line 1052, Address: 0x102726c */

  if (*pScrFlag) { /* Line 1054, Address: 0x1027274 */
    if (*pScrFlag & 1) { /* Line 1055, Address: 0x1027280 */
      *pScrFlag &= 254; /* Line 1056, Address: 0x1027294 */

      lD4.l = -16; /* Line 1058, Address: 0x10272a0 */
      wD5 = 65520; /* Line 1059, Address: 0x10272a8 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1061, Address: 0x10272b0 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1063, Address: 0x10272d0 */
    }




    if (*pScrFlag & 2) { /* Line 1069, Address: 0x10272fc */
      *pScrFlag &= 253; /* Line 1070, Address: 0x1027310 */

      lD4.l = 224; /* Line 1072, Address: 0x102731c */
      wD5 = 65520; /* Line 1073, Address: 0x1027324 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1074, Address: 0x102732c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1076, Address: 0x102734c */
    }




    if (*pScrFlag & 4) { /* Line 1082, Address: 0x1027378 */
      *pScrFlag &= 251; /* Line 1083, Address: 0x102738c */

      lD4.l = -16; /* Line 1085, Address: 0x1027398 */
      wD5 = 65520; /* Line 1086, Address: 0x10273a0 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1087, Address: 0x10273a8 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1089, Address: 0x10273c8 */
    }




    if (*pScrFlag & 8) { /* Line 1095, Address: 0x10273f4 */
      *pScrFlag &= 247; /* Line 1096, Address: 0x1027408 */

      lD4.l = -16; /* Line 1098, Address: 0x1027414 */
      wD5 = 320; /* Line 1099, Address: 0x102741c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1100, Address: 0x1027424 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1102, Address: 0x1027444 */
    }
  }






} /* Line 1111, Address: 0x1027470 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1128, Address: 0x10274a0 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1133, Address: 0x10274c0 */
    if (*pScrFlag & 1) { /* Line 1134, Address: 0x10274d0 */
      *pScrFlag &= 254; /* Line 1135, Address: 0x10274e8 */

      lD4.l = -16; /* Line 1137, Address: 0x10274fc */
      wD5 = 65520; /* Line 1138, Address: 0x1027504 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1140, Address: 0x102750c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1142, Address: 0x102752c */
    }




    if (*pScrFlag & 2) { /* Line 1148, Address: 0x1027558 */
      *pScrFlag &= 253; /* Line 1149, Address: 0x1027570 */

      lD4.l = 224; /* Line 1151, Address: 0x1027584 */
      wD5 = 65520; /* Line 1152, Address: 0x102758c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1153, Address: 0x1027594 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1155, Address: 0x10275b4 */
    }




    if (*pScrFlag & 4) { /* Line 1161, Address: 0x10275e0 */
      *pScrFlag &= 251; /* Line 1162, Address: 0x10275f8 */

      lD4.l = -16; /* Line 1164, Address: 0x102760c */
      wD5 = 65520; /* Line 1165, Address: 0x1027614 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1166, Address: 0x102761c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1168, Address: 0x102763c */
    }




    if (*pScrFlag & 8) { /* Line 1174, Address: 0x1027668 */
      *pScrFlag &= 247; /* Line 1175, Address: 0x1027680 */

      lD4.l = -16; /* Line 1177, Address: 0x1027694 */
      wD5 = 320; /* Line 1178, Address: 0x102769c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1179, Address: 0x10276a4 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1181, Address: 0x10276c4 */
    }
  }






} /* Line 1190, Address: 0x10276f0 */






void scrollwrtc() {} /* Line 1197, Address: 0x1027710 */




void scrollwrtz() {} /* Line 1202, Address: 0x1027720 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1220, Address: 0x1027730 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1233, Address: 0x1027758 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1236, Address: 0x1027778 */
    pTilePoint->x += 2; /* Line 1237, Address: 0x102778c */
    if (pTilePoint->x >= 64) { /* Line 1238, Address: 0x10277a0 */
      pTilePoint->x -= 64; /* Line 1239, Address: 0x10277b4 */
    }
    xOffs += 16; /* Line 1241, Address: 0x10277c8 */
  } while (--lpcnt >= 0); /* Line 1242, Address: 0x10277d4 */
} /* Line 1243, Address: 0x10277e8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1247, Address: 0x1027800 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1251, Address: 0x1027828 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1254, Address: 0x1027848 */
    pTilePoint->x += 2; /* Line 1255, Address: 0x102785c */
    if (pTilePoint->x >= 64) { /* Line 1256, Address: 0x1027870 */
      pTilePoint->x -= 64; /* Line 1257, Address: 0x1027884 */
    }
    xOffs += 16; /* Line 1259, Address: 0x1027898 */
  } while (--lpcnt >= 0); /* Line 1260, Address: 0x10278a4 */
} /* Line 1261, Address: 0x10278b8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1281, Address: 0x10278d0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1285, Address: 0x10278f8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1288, Address: 0x1027918 */
    pTilePoint->y += 2; /* Line 1289, Address: 0x102792c */
    if (pTilePoint->y >= 32) { /* Line 1290, Address: 0x102793c */
      pTilePoint->y -= 32; /* Line 1291, Address: 0x1027950 */
    }
    yOffs += 16; /* Line 1293, Address: 0x1027960 */
  } while (--lpcnt >= 0); /* Line 1294, Address: 0x102796c */
} /* Line 1295, Address: 0x1027980 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1314, Address: 0x1027990 */
  int base = 0; /* Line 1315, Address: 0x10279c4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1320, Address: 0x10279c8 */

    base = 1; /* Line 1322, Address: 0x10279d8 */
  } /* Line 1323, Address: 0x10279dc */
  else if (VramBase == 16384) { /* Line 1324, Address: 0x10279e4 */

    base = 0; /* Line 1326, Address: 0x10279f4 */
  }
  x = pTilePoint->x; /* Line 1328, Address: 0x10279f8 */
  y = pTilePoint->y; /* Line 1329, Address: 0x1027a00 */


  frip = BlkIndex & 6144; /* Line 1332, Address: 0x1027a08 */
  BlkIndex &= 1023; /* Line 1333, Address: 0x1027a10 */
  if (frip == 6144) { /* Line 1334, Address: 0x1027a1c */

    p0 = 3, p1 = 2; /* Line 1336, Address: 0x1027a28 */
    p2 = 1, p3 = 0; /* Line 1337, Address: 0x1027a30 */
  } /* Line 1338, Address: 0x1027a38 */
  else if (frip & 4096) { /* Line 1339, Address: 0x1027a40 */

    p0 = 2, p1 = 3; /* Line 1341, Address: 0x1027a4c */
    p2 = 0, p3 = 1; /* Line 1342, Address: 0x1027a54 */
  } /* Line 1343, Address: 0x1027a5c */
  else if (frip & 2048) { /* Line 1344, Address: 0x1027a64 */

    p0 = 1, p1 = 0; /* Line 1346, Address: 0x1027a70 */
    p2 = 3, p3 = 2; /* Line 1347, Address: 0x1027a78 */
  } /* Line 1348, Address: 0x1027a80 */
  else {

    p0 = 0, p1 = 1; /* Line 1351, Address: 0x1027a88 */
    p2 = 2, p3 = 3; /* Line 1352, Address: 0x1027a90 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1355, Address: 0x1027a98 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1356, Address: 0x1027adc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1357, Address: 0x1027b20 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1358, Address: 0x1027b64 */

} /* Line 1360, Address: 0x1027ba8 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1378, Address: 0x1027be0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1379, Address: 0x1027c00 */
} /* Line 1380, Address: 0x1027c20 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1382, Address: 0x1027c30 */
  wH_posiw = 0; /* Line 1383, Address: 0x1027c50 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1384, Address: 0x1027c54 */
} /* Line 1385, Address: 0x1027c74 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1392, Address: 0x1027c90 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1398, Address: 0x1027cc0 */
  yOffs += wV_posiw; /* Line 1399, Address: 0x1027cd0 */





  if ((short)xOffs < 0) /* Line 1405, Address: 0x1027ce0 */
    xOffs = 0; /* Line 1406, Address: 0x1027cfc */
  if ((short)yOffs < 0) /* Line 1407, Address: 0x1027d00 */
    yOffs = 0; /* Line 1408, Address: 0x1027d1c */
  if ((short)xOffs >= 16384) /* Line 1409, Address: 0x1027d20 */
    xOffs = 16383; /* Line 1410, Address: 0x1027d40 */
  if ((short)yOffs >= 2048) /* Line 1411, Address: 0x1027d48 */
    yOffs = 2047; /* Line 1412, Address: 0x1027d68 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1413, Address: 0x1027d70 */
  if (i < 0) i = 0; /* Line 1414, Address: 0x1027db8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1416, Address: 0x1027dc4 */

  if (ScreenNo) { /* Line 1418, Address: 0x1027de0 */




    xOffs &= 32767; /* Line 1423, Address: 0x1027de8 */
    yOffs &= 32767; /* Line 1424, Address: 0x1027df4 */


    xBlk = xOffs; /* Line 1427, Address: 0x1027e00 */
    xBlk %= 256; /* Line 1428, Address: 0x1027e08 */
    xBlk /= 16; /* Line 1429, Address: 0x1027e28 */
    yBlk = yOffs; /* Line 1430, Address: 0x1027e44 */
    yBlk %= 256; /* Line 1431, Address: 0x1027e4c */
    yBlk /= 16; /* Line 1432, Address: 0x1027e6c */

    lpw = pmapwk; /* Line 1434, Address: 0x1027e88 */
    lpw += xBlk; /* Line 1435, Address: 0x1027e90 */
    lpw += yBlk * 16; /* Line 1436, Address: 0x1027e98 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1437, Address: 0x1027ea4 */
    *pIndex = *lpw; /* Line 1438, Address: 0x1027ebc */

    return 1; /* Line 1440, Address: 0x1027ecc */
  }

  *pIndex = 0; /* Line 1443, Address: 0x1027ed8 */
  return 0; /* Line 1444, Address: 0x1027ee0 */
} /* Line 1445, Address: 0x1027ee4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1465, Address: 0x1027f10 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1473, Address: 0x1027f38 */
  if (ScreenNo) { /* Line 1474, Address: 0x1027f9c */





    xBlk = xOffs; /* Line 1480, Address: 0x1027fa4 */
    xBlk %= 256; /* Line 1481, Address: 0x1027fac */
    xBlk /= 16; /* Line 1482, Address: 0x1027fcc */
    yBlk = yOffs; /* Line 1483, Address: 0x1027fe8 */
    yBlk %= 256; /* Line 1484, Address: 0x1027ff0 */
    yBlk /= 16; /* Line 1485, Address: 0x1028010 */


    lpw = pmapwk; /* Line 1488, Address: 0x102802c */
    lpw += xBlk; /* Line 1489, Address: 0x1028034 */
    lpw += yBlk * 16; /* Line 1490, Address: 0x102803c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1491, Address: 0x1028048 */
    *ppBlockNo = lpw; /* Line 1492, Address: 0x1028060 */
    *pIndex = *lpw; /* Line 1493, Address: 0x1028068 */




    return 1; /* Line 1498, Address: 0x1028078 */
  }

  *pIndex = 0; /* Line 1501, Address: 0x1028084 */
  return 0; /* Line 1502, Address: 0x102808c */
} /* Line 1503, Address: 0x1028090 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1517, Address: 0x10280b0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1524, Address: 0x10280cc */
  pMapWk = (unsigned char*)mapwka; /* Line 1525, Address: 0x10280d0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1526, Address: 0x10280d8 */
    *pBlockIndex = BlockNo; /* Line 1527, Address: 0x10280fc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1528, Address: 0x1028108 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1529, Address: 0x1028120 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1530, Address: 0x1028134 */
    }
  }


} /* Line 1535, Address: 0x102814c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1549, Address: 0x1028170 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1550, Address: 0x102817c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1551, Address: 0x10281a8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1552, Address: 0x10281f4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1553, Address: 0x1028220 */

          return 0; /* Line 1555, Address: 0x102826c */
        }
      }
    }
  }

  return 1; /* Line 1561, Address: 0x1028278 */
} /* Line 1562, Address: 0x102827c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1579, Address: 0x1028290 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1580, Address: 0x10282ac */

} /* Line 1582, Address: 0x10282c8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1584, Address: 0x10282e0 */
  wH_posiw = 0; /* Line 1585, Address: 0x10282fc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1586, Address: 0x1028300 */

} /* Line 1588, Address: 0x102831c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1590, Address: 0x1028330 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1591, Address: 0x1028344 */

} /* Line 1593, Address: 0x1028360 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1595, Address: 0x1028370 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1596, Address: 0x102838c */

} /* Line 1598, Address: 0x10283a8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1600, Address: 0x10283c0 */
  xOffs += wH_posiw; /* Line 1601, Address: 0x10283d8 */
  yOffs += wV_posiw; /* Line 1602, Address: 0x10283e8 */
  yOffs &= 240; /* Line 1603, Address: 0x10283f8 */
  xOffs &= 496; /* Line 1604, Address: 0x1028404 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1606, Address: 0x1028410 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1607, Address: 0x102843c */


} /* Line 1610, Address: 0x1028468 */















void mapwrt() { /* Line 1626, Address: 0x1028480 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1631, Address: 0x1028498 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1632, Address: 0x10284a4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1633, Address: 0x10284b0 */
  VramBase = 16384; /* Line 1634, Address: 0x10284b8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1635, Address: 0x10284bc */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1637, Address: 0x10284d4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1638, Address: 0x10284e0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1639, Address: 0x10284ec */
  VramBase = 24576; /* Line 1640, Address: 0x10284f4 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1642, Address: 0x10284f8 */

} /* Line 1644, Address: 0x1028510 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1648, Address: 0x1028530 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1649, Address: 0x1028548 */
} /* Line 1650, Address: 0x1028568 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1655, Address: 0x1028580 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1659, Address: 0x10285a0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1662, Address: 0x10285bc */



    wD4 += 16; /* Line 1666, Address: 0x10285e4 */
  } while ((short)--wD6 >= 0); /* Line 1667, Address: 0x10285f0 */

} /* Line 1669, Address: 0x1028618 */













































































































void mapinit() { /* Line 1779, Address: 0x1028630 */

  colorset2(mapinittbl.colorno2); /* Line 1781, Address: 0x1028638 */
  colorset(mapinittbl.colorno2); /* Line 1782, Address: 0x102864c */


  if (play_start & 2) divdevset(); /* Line 1785, Address: 0x1028660 */
} /* Line 1786, Address: 0x1028680 */










void mapset() {} /* Line 1797, Address: 0x1028690 */
