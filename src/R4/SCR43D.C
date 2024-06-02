#include "..\EQU.H"
#include "SCR41C.H"
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
unsigned short scr_dir_tbl[6] = {
  4, 0, 3479, 0, 2048, 96
};
extern unsigned char awasintbl[256];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;













































































void enecginit() {} /* Line 129, Address: 0x1027410 */



void divdevset() {} /* Line 133, Address: 0x1027420 */














































sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 181, Address: 0x1027430 */
  else return &actwk[1]; /* Line 182, Address: 0x1027450 */
} /* Line 183, Address: 0x1027458 */






void scr_set() { /* Line 190, Address: 0x1027460 */
  int i;







  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 199, Address: 0x102746c */

  i = 0; /* Line 201, Address: 0x10274b4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 202, Address: 0x10274b8 */
  scralim_left = scr_dir_tbl[i]; /* Line 203, Address: 0x10274dc */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 204, Address: 0x10274f8 */
  scralim_right = scr_dir_tbl[i]; /* Line 205, Address: 0x102751c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 206, Address: 0x1027538 */
  scralim_up = scr_dir_tbl[i]; /* Line 207, Address: 0x102755c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 208, Address: 0x1027578 */
  scralim_down = scr_dir_tbl[i]; /* Line 209, Address: 0x102759c */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 210, Address: 0x10275b8 */

  scra_h_keep = scralim_left + 576; /* Line 212, Address: 0x10275dc */
  scra_h_count = 16; /* Line 213, Address: 0x1027600 */
  scra_v_count = 16; /* Line 214, Address: 0x102760c */

  scra_vline = scr_dir_tbl[i++]; /* Line 216, Address: 0x1027618 */
  scra_hline = 160; /* Line 217, Address: 0x102763c */

  playposiset(); /* Line 219, Address: 0x1027648 */
} /* Line 220, Address: 0x1027650 */



void playposiset() { /* Line 224, Address: 0x1027670 */
  unsigned short endplpositbl[16] = { /* Line 225, Address: 0x1027684 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[2] = { /* Line 235, Address: 0x10276b8 */
    80,
    364
  };
  unsigned char playmapnotbl[4] = { /* Line 239, Address: 0x10276d4 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 247, Address: 0x1027700 */

    playload(); /* Line 249, Address: 0x1027714 */
    xWk = actwk[0].xposi.w.h; /* Line 250, Address: 0x102771c */
    yWk = actwk[0].yposi.w.h; /* Line 251, Address: 0x102772c */
    if (yWk < 0) yWk = 0; /* Line 252, Address: 0x102773c */
  } /* Line 253, Address: 0x1027750 */
  else {


    if (demoflag.w < 0) { /* Line 257, Address: 0x1027758 */

      i = (enddemono - 1) * 4; /* Line 259, Address: 0x1027770 */
      xWk = actwk[0].xposi.w.h = endplpositbl[i++]; /* Line 260, Address: 0x1027788 */
      yWk = actwk[0].yposi.w.h = endplpositbl[i++]; /* Line 261, Address: 0x10277ac */
    } /* Line 262, Address: 0x10277d0 */
    else {


      i = demoflag.w * 4; /* Line 266, Address: 0x10277d8 */
      xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 267, Address: 0x10277ec */
      yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 268, Address: 0x1027810 */
    }
  }

  if ((unsigned short)xWk > 160) { /* Line 272, Address: 0x1027834 */
    xWk -= 160; /* Line 273, Address: 0x1027848 */
  } /* Line 274, Address: 0x1027854 */
  else {
    xWk = 0; /* Line 276, Address: 0x102785c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 280, Address: 0x1027860 */
    xWk = scralim_right; /* Line 281, Address: 0x1027884 */
  }
  scra_h_posit.w.h = xWk; /* Line 283, Address: 0x1027894 */

  if ((unsigned short)yWk > 96) { /* Line 285, Address: 0x102789c */
    yWk -= 96; /* Line 286, Address: 0x10278b0 */
  } /* Line 287, Address: 0x10278bc */
  else {
    yWk = 0; /* Line 289, Address: 0x10278c4 */
  }

  if (scralim_down < yWk) { /* Line 292, Address: 0x10278c8 */
    yWk = scralim_down; /* Line 293, Address: 0x10278ec */
  }

  scra_v_posit.w.h = yWk; /* Line 296, Address: 0x10278fc */


  scrbinit(xWk); /* Line 299, Address: 0x1027904 */

  i = 0; /* Line 301, Address: 0x1027910 */
  loopmapno = playmapnotbl[i++]; /* Line 302, Address: 0x1027914 */
  loopmapno2 = playmapnotbl[i++]; /* Line 303, Address: 0x102792c */
  ballmapno = playmapnotbl[i++]; /* Line 304, Address: 0x1027944 */
  ballmapno2 = playmapnotbl[i++]; /* Line 305, Address: 0x102795c */


} /* Line 308, Address: 0x1027974 */



void scrbinit(short yWk) { /* Line 312, Address: 0x1027990 */
  uint_union data;


  data.l = 0; /* Line 316, Address: 0x1027998 */
  data.w.l = scra_v_posit.w.h; /* Line 317, Address: 0x102799c */
  data.w.l >>= 1; /* Line 318, Address: 0x10279a8 */

  scrb_v_posit.w.h = data.w.l; /* Line 320, Address: 0x10279b4 */
  scrb_v_posit.w.l = 0; /* Line 321, Address: 0x10279c0 */
  scrc_v_posit.w.h = data.w.l; /* Line 322, Address: 0x10279c8 */
  scrz_v_posit.w.h = data.w.l; /* Line 323, Address: 0x10279d4 */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 325, Address: 0x10279e0 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 326, Address: 0x1027a04 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 327, Address: 0x1027a30 */




} /* Line 332, Address: 0x1027a5c */



void scroll() { /* Line 336, Address: 0x1027a70 */
  uint_union data;
  int_union temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 335, Address: 0x1020e10 */ /* Line 342, Address: 0x1027a80 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 345, Address: 0x1027a90 */
  scrchk(); /* Line 346, Address: 0x1027abc */
  scroll_h(); /* Line 347, Address: 0x1027ac4 */
  scroll_v(); /* Line 348, Address: 0x1027acc */

  vscroll.w.h = scra_v_posit.w.h; /* Line 350, Address: 0x1027ad4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 351, Address: 0x1027ae4 */



  temp1.l = (long int)(scra_hz << 2) * 3; /* Line 355, Address: 0x1027af4 */
  temp2.l = scra_vz << 7; /* Line 356, Address: 0x1027b24 */
  scrollb_hv(&temp1, &temp2); /* Line 357, Address: 0x1027b3c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 359, Address: 0x1027b4c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 360, Address: 0x1027b5c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 361, Address: 0x1027b6c */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 363, Address: 0x1027b7c */
  scrflagz.b.h = 0; /* Line 364, Address: 0x1027bb0 */
  scrflagc.b.h = 0; /* Line 365, Address: 0x1027bb8 */

  hsCount = 0; /* Line 367, Address: 0x1027bc0 */
  for (i = 0; i < 192; ++i) { /* Line 368, Address: 0x1027bc4 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 371, Address: 0x1027bd0 */
    ++hsCount; /* Line 372, Address: 0x1027c00 */
  } /* Line 373, Address: 0x1027c04 */

  data.w.l = -scra_h_posit.w.h; /* Line 375, Address: 0x1027c14 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 376, Address: 0x1027c30 */
  data.w.l = scrb_v_posit.w.h; /* Line 377, Address: 0x1027c54 */
  data.w.l &= 1016; /* Line 378, Address: 0x1027c60 */
  data.w.l >>= 2; /* Line 379, Address: 0x1027c6c */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 380, Address: 0x1027c78 */

} /* Line 382, Address: 0x1027cc8 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 420, Address: 0x1027ce0 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 427, Address: 0x1027cfc */
  data1.b.l = waterdirec.b.h; /* Line 428, Address: 0x1027d04 */
  data2.b.l = waterdirec.b.h; /* Line 429, Address: 0x1027d10 */
  waterdirec.w += 128; /* Line 430, Address: 0x1027d1c */
  data1.w += scrb_v_posit.w.h; /* Line 431, Address: 0x1027d30 */
  data1.b.h = 0; /* Line 432, Address: 0x1027d44 */
  data2.w += scra_v_posit.w.h; /* Line 433, Address: 0x1027d48 */
  data2.b.h = 0; /* Line 434, Address: 0x1027d5c */

  VPosi &= 7; /* Line 436, Address: 0x1027d60 */
  hsw.w.l = hscrollwork[offs++]; /* Line 437, Address: 0x1027d6c */
  avp = scra_v_posit.w.h; /* Line 438, Address: 0x1027d94 */
  i = 232; /* Line 439, Address: 0x1027da4 */


  do {
    if (avp > waterposi) { /* Line 443, Address: 0x1027da8 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 448, Address: 0x1027dcc */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 449, Address: 0x1027dd4 */
        ++pHScrollBuff; /* Line 450, Address: 0x1027e24 */
        ++data1.b.l; /* Line 451, Address: 0x1027e28 */
        ++data2.b.l; /* Line 452, Address: 0x1027e34 */
        ++VPosi; /* Line 453, Address: 0x1027e40 */
        if (VPosi == 8) { /* Line 454, Address: 0x1027e4c */

          VPosi = 0; /* Line 456, Address: 0x1027e64 */
          hsw.w.l = hscrollwork[offs++]; /* Line 457, Address: 0x1027e68 */
        }
      } while (--i > 0); /* Line 459, Address: 0x1027e90 */

      return; /* Line 461, Address: 0x1027e9c */
    }
    pHScrollBuff->l = hsw.l; /* Line 463, Address: 0x1027ea4 */
    ++pHScrollBuff; /* Line 464, Address: 0x1027eac */
    ++avp; /* Line 465, Address: 0x1027eb0 */
    ++data1.b.l; /* Line 466, Address: 0x1027ebc */
    ++data2.b.l; /* Line 467, Address: 0x1027ec8 */
    ++VPosi; /* Line 468, Address: 0x1027ed4 */
    if (VPosi == 8) { /* Line 469, Address: 0x1027ee0 */

      VPosi = 0; /* Line 471, Address: 0x1027ef8 */
      hsw.w.l = hscrollwork[offs++]; /* Line 472, Address: 0x1027efc */
    }
  } while (--i > 0); /* Line 474, Address: 0x1027f24 */

} /* Line 476, Address: 0x1027f30 */











void scroll_h() { /* Line 488, Address: 0x1027f50 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 491, Address: 0x1027f5c */
  scrh_move(); /* Line 492, Address: 0x1027f68 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 493, Address: 0x1027f70 */
    scra_h_count ^= 16; /* Line 494, Address: 0x1027fa4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 495, Address: 0x1027fb8 */
      scrflaga.b.h |= 4; /* Line 496, Address: 0x1027fe4 */
    } /* Line 497, Address: 0x1027ff8 */
    else {

      scrflaga.b.h |= 8; /* Line 500, Address: 0x1028000 */
    }
  }


} /* Line 505, Address: 0x1028014 */

void scrh_move() { /* Line 507, Address: 0x1028030 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 510, Address: 0x102803c */
  wD0 -= scra_h_posit.w.h; /* Line 511, Address: 0x1028048 */
  wD0 -= scra_hline; /* Line 512, Address: 0x102805c */
  if (wD0 == 0) { /* Line 513, Address: 0x1028070 */

    scra_hz = 0; /* Line 515, Address: 0x102807c */
  } /* Line 516, Address: 0x1028084 */
  else if ((short)wD0 < 0) { /* Line 517, Address: 0x102808c */
    left_check(wD0); /* Line 518, Address: 0x10280a4 */
  } /* Line 519, Address: 0x10280b0 */
  else {
    right_check(wD0); /* Line 521, Address: 0x10280b8 */
  }

} /* Line 524, Address: 0x10280c4 */


void right_check(unsigned short wD0) { /* Line 527, Address: 0x10280e0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 530, Address: 0x10280ec */
    wD0 = 16; /* Line 531, Address: 0x102810c */
  }

  wD0 += scra_h_posit.w.h; /* Line 534, Address: 0x1028114 */
  if (scralim_right < (short)wD0) { /* Line 535, Address: 0x102812c */
    wD0 = scralim_right; /* Line 536, Address: 0x102815c */
  }

  wD1 = wD0; /* Line 539, Address: 0x1028168 */
  wD1 -= scra_h_posit.w.h; /* Line 540, Address: 0x1028170 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 541, Address: 0x1028184 */
  scra_h_posit.w.h = wD0; /* Line 542, Address: 0x10281b4 */
  scra_hz = wD1; /* Line 543, Address: 0x10281c0 */

} /* Line 545, Address: 0x10281c8 */


void left_check(unsigned short wD0) { /* Line 548, Address: 0x10281e0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 551, Address: 0x10281ec */
    wD0 = -16; /* Line 552, Address: 0x102820c */
  }

  wD0 += scra_h_posit.w.h; /* Line 555, Address: 0x1028214 */
  if (scralim_left > (short)wD0) { /* Line 556, Address: 0x102822c */
    wD0 = scralim_left; /* Line 557, Address: 0x102825c */
  }

  wD1 = wD0; /* Line 560, Address: 0x1028268 */
  wD1 -= scra_h_posit.w.h; /* Line 561, Address: 0x1028270 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 562, Address: 0x1028284 */
  scra_h_posit.w.h = wD0; /* Line 563, Address: 0x10282b4 */
  scra_hz = wD1; /* Line 564, Address: 0x10282c0 */

} /* Line 566, Address: 0x10282c8 */


















void scroll_v() { /* Line 585, Address: 0x10282e0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 588, Address: 0x10282ec */
  if (actwk[0].cddat & 4) { /* Line 589, Address: 0x1028318 */
    wD0 -= 5; /* Line 590, Address: 0x1028330 */
  }

  if (actwk[0].cddat & 2) { /* Line 593, Address: 0x1028338 */
    wD0 += 32; /* Line 594, Address: 0x1028350 */
    if ((unsigned short)scra_vline > wD0) { /* Line 595, Address: 0x1028358 */
      wD0 -= scra_vline; /* Line 596, Address: 0x1028378 */
      sv_move_main2(wD0); /* Line 597, Address: 0x102838c */
      return; /* Line 598, Address: 0x1028398 */
    }
    wD0 -= scra_vline; /* Line 600, Address: 0x10283a0 */
    if (wD0 >= 64) { /* Line 601, Address: 0x10283b4 */
      wD0 -= 64; /* Line 602, Address: 0x10283c4 */
      sv_move_main2(wD0); /* Line 603, Address: 0x10283cc */
      return; /* Line 604, Address: 0x10283d8 */
    }
    wD0 -= 64; /* Line 606, Address: 0x10283e0 */
    if (limmoveflag == 0) goto label1; /* Line 607, Address: 0x10283e8 */
    sv_move_sub2(); /* Line 608, Address: 0x10283fc */
    return; /* Line 609, Address: 0x1028404 */
  }




  wD0 -= scra_vline; /* Line 615, Address: 0x102840c */
  if (wD0) { /* Line 616, Address: 0x1028420 */
    sv_move_main(wD0); /* Line 617, Address: 0x1028428 */
    return; /* Line 618, Address: 0x1028434 */
  }
  if (limmoveflag == 0) { /* Line 620, Address: 0x102843c */
    sv_move_sub2(); /* Line 621, Address: 0x1028450 */
    return; /* Line 622, Address: 0x1028458 */
  }


label1:
  scra_vz = 0; /* Line 627, Address: 0x1028460 */

} /* Line 629, Address: 0x1028468 */





void sv_move_main(unsigned short wD0) { /* Line 635, Address: 0x1028480 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 638, Address: 0x1028490 */
    sv_move_main1(wD0); /* Line 639, Address: 0x10284ac */
  } /* Line 640, Address: 0x10284b8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 643, Address: 0x10284c0 */
    if ((short)wD1 < 0) { /* Line 644, Address: 0x10284cc */
      wD1 = -(short)wD1; /* Line 645, Address: 0x10284e4 */
    }

    if (wD1 >= 2048) { /* Line 648, Address: 0x1028500 */
      sv_move_main2(wD0); /* Line 649, Address: 0x1028510 */
    } /* Line 650, Address: 0x102851c */
    else {
      if ((short)wD0 > 6) { /* Line 652, Address: 0x1028524 */
        sv_move_plus(1536); /* Line 653, Address: 0x1028544 */
      } /* Line 654, Address: 0x1028550 */
      else if ((short)wD0 < -6) { /* Line 655, Address: 0x1028558 */
        sv_move_minus(1536); /* Line 656, Address: 0x1028578 */
      } /* Line 657, Address: 0x1028584 */
      else {
        sv_move_sub(wD0); /* Line 659, Address: 0x102858c */
      }
    }
  }
} /* Line 663, Address: 0x1028598 */



void sv_move_main1(unsigned short wD0) { /* Line 667, Address: 0x10285b0 */

  if ((short)wD0 > 2) { /* Line 669, Address: 0x10285bc */
    sv_move_plus(512); /* Line 670, Address: 0x10285dc */
  } /* Line 671, Address: 0x10285e8 */
  else if ((short)wD0 < -2) { /* Line 672, Address: 0x10285f0 */
    sv_move_minus(512); /* Line 673, Address: 0x1028610 */
  } /* Line 674, Address: 0x102861c */
  else {
    sv_move_sub(wD0); /* Line 676, Address: 0x1028624 */
  }

} /* Line 679, Address: 0x1028630 */


void sv_move_main2(unsigned short wD0) { /* Line 682, Address: 0x1028640 */

  if ((short)wD0 > 16) { /* Line 684, Address: 0x102864c */
    sv_move_plus(4096); /* Line 685, Address: 0x102866c */
  } /* Line 686, Address: 0x1028678 */
  else if ((short)wD0 < -16) { /* Line 687, Address: 0x1028680 */
    sv_move_minus(4096); /* Line 688, Address: 0x10286a0 */
  } /* Line 689, Address: 0x10286ac */
  else {
    sv_move_sub(wD0); /* Line 691, Address: 0x10286b4 */
  }

} /* Line 694, Address: 0x10286c0 */


void sv_move_sub2() { /* Line 697, Address: 0x10286d0 */
  limmoveflag = 0; /* Line 698, Address: 0x10286d8 */
  sv_move_sub(0); /* Line 699, Address: 0x10286e0 */
} /* Line 700, Address: 0x10286ec */


void sv_move_sub(unsigned short wD0) { /* Line 703, Address: 0x1028700 */
  int_union lD1;

  lD1.w.h = 0; /* Line 706, Address: 0x102870c */
  lD1.w.l = wD0; /* Line 707, Address: 0x1028710 */
  lD1.l += scra_v_posit.w.h; /* Line 708, Address: 0x1028718 */
  if ((short)wD0 > 0) { /* Line 709, Address: 0x1028734 */
    scrv_down_ch(lD1); /* Line 710, Address: 0x1028750 */
  } /* Line 711, Address: 0x102875c */
  else {
    scrv_up_ch(lD1); /* Line 713, Address: 0x1028764 */
  }

} /* Line 716, Address: 0x1028770 */




void sv_move_minus(unsigned short wD1) { /* Line 721, Address: 0x1028780 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 725, Address: 0x1028790 */
  lD1.l <<= 8; /* Line 726, Address: 0x10287ac */
  lD1.l += scra_v_posit.l; /* Line 727, Address: 0x10287b8 */

  wk = lD1.w.h; /* Line 729, Address: 0x10287cc */
  lD1.w.h = lD1.w.l; /* Line 730, Address: 0x10287d4 */
  lD1.w.l = wk; /* Line 731, Address: 0x10287dc */
  scrv_up_ch(lD1); /* Line 732, Address: 0x10287e0 */
} /* Line 733, Address: 0x10287ec */



void scrv_up_ch(int_union lD1) { /* Line 737, Address: 0x1028800 */
  if (scralim_up >= lD1.w.l) { /* Line 738, Address: 0x102880c */
    if (lD1.w.l <= 0) { /* Line 739, Address: 0x1028834 */
      lD1.w.l &= 2047; /* Line 740, Address: 0x1028848 */
      actwk[0].yposi.w.h &= 2048; /* Line 741, Address: 0x1028854 */
      scra_v_posit.w.h &= 2048; /* Line 742, Address: 0x1028868 */
      scrb_v_posit.w.h &= 2048; /* Line 743, Address: 0x102887c */
    } /* Line 744, Address: 0x1028890 */
    else {

      lD1.w.l = scralim_up; /* Line 747, Address: 0x1028898 */
    }
  }
  scrv_move(lD1); /* Line 750, Address: 0x10288a4 */

} /* Line 752, Address: 0x10288b0 */





void sv_move_plus(unsigned short wD1) { /* Line 758, Address: 0x10288c0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 762, Address: 0x10288d0 */
  lD1.w.l = wD1; /* Line 763, Address: 0x10288d4 */
  lD1.l <<= 8; /* Line 764, Address: 0x10288dc */
  lD1.l += scra_v_posit.l; /* Line 765, Address: 0x10288e8 */

  wk = lD1.w.h; /* Line 767, Address: 0x10288fc */
  lD1.w.h = lD1.w.l; /* Line 768, Address: 0x1028904 */
  lD1.w.l = wk; /* Line 769, Address: 0x102890c */

  scrv_down_ch(lD1); /* Line 771, Address: 0x1028910 */

} /* Line 773, Address: 0x102891c */



void scrv_down_ch(int_union lD1) { /* Line 777, Address: 0x1028930 */
  if (scralim_down <= lD1.w.l) { /* Line 778, Address: 0x102893c */
    lD1.w.l -= 2048; /* Line 779, Address: 0x1028964 */
    if (lD1.w.l > 0) { /* Line 780, Address: 0x1028970 */
      actwk[0].yposi.w.h &= 2047; /* Line 781, Address: 0x1028984 */
      scra_v_posit.w.h -= 2048; /* Line 782, Address: 0x1028998 */
      scrb_v_posit.w.h &= 1023; /* Line 783, Address: 0x10289ac */
    } /* Line 784, Address: 0x10289c0 */
    else {
      lD1.w.l = scralim_down; /* Line 786, Address: 0x10289c8 */
    }
  }
  scrv_move(lD1); /* Line 789, Address: 0x10289d4 */

} /* Line 791, Address: 0x10289e0 */


void scrv_move(int_union lD1) { /* Line 794, Address: 0x10289f0 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 797, Address: 0x1028a00 */

  wk = lD1.w.h; /* Line 799, Address: 0x1028a0c */
  lD1.w.h = lD1.w.l; /* Line 800, Address: 0x1028a14 */
  lD1.w.l = wk; /* Line 801, Address: 0x1028a1c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 803, Address: 0x1028a20 */
  scra_v_posit.l = lD1.l; /* Line 804, Address: 0x1028a48 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 807, Address: 0x1028a54 */
    scra_v_count ^= 16; /* Line 808, Address: 0x1028a88 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 809, Address: 0x1028a9c */

      scrflaga.b.h |= 2; /* Line 811, Address: 0x1028ac8 */
    } /* Line 812, Address: 0x1028adc */
    else {
      scrflaga.b.h |= 1; /* Line 814, Address: 0x1028ae4 */
    }
  }


} /* Line 819, Address: 0x1028af8 */



void scrollb_hv(int_union* lD4, int_union* lD5) { /* Line 823, Address: 0x1028b10 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 826, Address: 0x1028b1c */
  lD0.l += lD4->l; /* Line 827, Address: 0x1028b2c */
  scrb_h_posit.l = lD0.l; /* Line 828, Address: 0x1028b40 */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 830, Address: 0x1028b4c */

    scrb_h_count ^= 16; /* Line 832, Address: 0x1028b80 */
    lD0.l -= lD2.l; /* Line 833, Address: 0x1028b94 */
    if ((long int)lD0.l < 0) { /* Line 834, Address: 0x1028ba4 */
      scrflagb.b.h |= 4; /* Line 835, Address: 0x1028bb8 */
    } /* Line 836, Address: 0x1028bcc */
    else {

      scrflagb.b.h |= 8; /* Line 839, Address: 0x1028bd4 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 844, Address: 0x1028be8 */
  lD0.l += lD5->l; /* Line 845, Address: 0x1028bf8 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 846, Address: 0x1028c0c */
  scrb_v_posit.l = lD0.l; /* Line 847, Address: 0x1028c24 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 849, Address: 0x1028c30 */

    scrb_v_count ^= 16; /* Line 851, Address: 0x1028c64 */
    lD0.l -= lD3.l; /* Line 852, Address: 0x1028c78 */
    if ((long int)lD0.l < 0) { /* Line 853, Address: 0x1028c88 */
      scrflagb.b.h |= 1; /* Line 854, Address: 0x1028c9c */
    } /* Line 855, Address: 0x1028cb0 */
    else {

      scrflagb.b.h |= 2; /* Line 858, Address: 0x1028cb8 */
    }
  }


} /* Line 863, Address: 0x1028ccc */






void scrollb_v(unsigned short wD0) { /* Line 870, Address: 0x1028ce0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 873, Address: 0x1028cec */
  scrb_v_posit.w.h = wD0; /* Line 874, Address: 0x1028cf8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 876, Address: 0x1028d04 */
    scrb_v_count ^= 16; /* Line 877, Address: 0x1028d30 */
    if ((short)wD3 > (short)wD0) { /* Line 878, Address: 0x1028d44 */
      scrflagb.b.h |= 1; /* Line 879, Address: 0x1028d74 */
    } /* Line 880, Address: 0x1028d88 */
    else {

      scrflagb.b.h |= 2; /* Line 883, Address: 0x1028d90 */
    }
  }


} /* Line 888, Address: 0x1028da4 */



void scrollb_h(int lD4, int flagb) { /* Line 892, Address: 0x1028dc0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 896, Address: 0x1028dd0 */
  lD0.l = lD2.l + lD4; /* Line 897, Address: 0x1028ddc */
  scrb_h_posit.l = lD0.l; /* Line 898, Address: 0x1028dec */

  lD1.w.h = lD0.w.l; /* Line 900, Address: 0x1028df8 */
  lD1.w.l = lD0.w.h; /* Line 901, Address: 0x1028e00 */
  lD1.w.l &= 16; /* Line 902, Address: 0x1028e08 */

  bD3 = scrb_h_count; /* Line 904, Address: 0x1028e14 */
  lD1.b.b4 ^= bD3; /* Line 905, Address: 0x1028e20 */
  if (!lD1.b.b4) { /* Line 906, Address: 0x1028e34 */
    scrb_h_count ^= 16; /* Line 907, Address: 0x1028e40 */
    lD0.l -= lD2.l; /* Line 908, Address: 0x1028e54 */
    if ((long int)lD0.l < 0) { /* Line 909, Address: 0x1028e64 */
      scrflagb.b.h |= flagb; /* Line 910, Address: 0x1028e78 */
    } /* Line 911, Address: 0x1028e94 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 914, Address: 0x1028e9c */
    }
  }


} /* Line 919, Address: 0x1028ebc */


void scrollc_h(int lD4, int flagc) { /* Line 922, Address: 0x1028ed0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 926, Address: 0x1028ee0 */
  lD0.l = lD2.l + lD4; /* Line 927, Address: 0x1028eec */
  scrc_h_posit.l = lD0.l; /* Line 928, Address: 0x1028efc */

  lD1.w.h = lD0.w.l; /* Line 930, Address: 0x1028f08 */
  lD1.w.l = lD0.w.h; /* Line 931, Address: 0x1028f10 */
  lD1.w.l &= 16; /* Line 932, Address: 0x1028f18 */

  bD3 = scrc_h_count; /* Line 934, Address: 0x1028f24 */
  lD1.b.b4 ^= bD3; /* Line 935, Address: 0x1028f30 */
  if (!lD1.b.b4) { /* Line 936, Address: 0x1028f44 */
    scrc_h_count ^= 16; /* Line 937, Address: 0x1028f50 */
    lD0.l -= lD2.l; /* Line 938, Address: 0x1028f64 */
    if ((long int)lD0.l < 0) { /* Line 939, Address: 0x1028f74 */
      scrflagc.b.h |= flagc; /* Line 940, Address: 0x1028f88 */
    } /* Line 941, Address: 0x1028fa4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 944, Address: 0x1028fac */
    }
  }


} /* Line 949, Address: 0x1028fcc */











void scrollz_h(int lD4, int flagz) { /* Line 961, Address: 0x1028fe0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 965, Address: 0x1028ff0 */
  lD0.l = lD2.l + lD4; /* Line 966, Address: 0x1028ffc */
  scrz_h_posit.l = lD0.l; /* Line 967, Address: 0x102900c */

  lD1.w.h = lD0.w.l; /* Line 969, Address: 0x1029018 */
  lD1.w.l = lD0.w.h; /* Line 970, Address: 0x1029020 */
  lD1.w.l &= 16; /* Line 971, Address: 0x1029028 */

  bD3 = scrz_h_count; /* Line 973, Address: 0x1029034 */
  lD1.b.b4 ^= bD3; /* Line 974, Address: 0x1029040 */
  if (!lD1.b.b4) { /* Line 975, Address: 0x1029054 */
    scrz_h_count ^= 16; /* Line 976, Address: 0x1029060 */
    lD0.l -= lD2.l; /* Line 977, Address: 0x1029074 */
    if ((long int)lD0.l < 0) { /* Line 978, Address: 0x1029084 */
      scrflagz.b.h |= flagz; /* Line 979, Address: 0x1029098 */
    } /* Line 980, Address: 0x10290b4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 983, Address: 0x10290bc */
    }
  }


} /* Line 988, Address: 0x10290dc */













void scrollwrtadva() { /* Line 1002, Address: 0x10290f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1008, Address: 0x102910c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1009, Address: 0x1029110 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1010, Address: 0x102911c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1011, Address: 0x1029128 */
  pScrFlag = &scrflagb.b.h; /* Line 1012, Address: 0x1029130 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1013, Address: 0x1029138 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1015, Address: 0x1029154 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1016, Address: 0x1029160 */
  pScrFlag = &scrflagc.b.h; /* Line 1017, Address: 0x102916c */
  scrollwrtc(); /* Line 1018, Address: 0x1029174 */

} /* Line 1020, Address: 0x102917c */












void scrollwrt() { /* Line 1033, Address: 0x10291a0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1042, Address: 0x10291c0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1043, Address: 0x10291c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1044, Address: 0x10291d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1045, Address: 0x10291dc */
  pScrFlag = &scrflagbw.b.h; /* Line 1046, Address: 0x10291e4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1047, Address: 0x10291ec */

  VramBase = 16384; /* Line 1049, Address: 0x1029208 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1050, Address: 0x102920c */
  wV_posiw = scra_v_posiw.w.h; /* Line 1051, Address: 0x1029218 */
  pMapWk = (unsigned char*)mapwka; /* Line 1052, Address: 0x1029224 */
  pScrFlag = &scrflagaw.b.h; /* Line 1053, Address: 0x102922c */

  if (*pScrFlag) { /* Line 1055, Address: 0x1029234 */
    if (*pScrFlag & 1) { /* Line 1056, Address: 0x1029240 */
      *pScrFlag &= 254; /* Line 1057, Address: 0x1029254 */

      lD4.l = -16; /* Line 1059, Address: 0x1029260 */
      wD5 = 65520; /* Line 1060, Address: 0x1029268 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1062, Address: 0x1029270 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1064, Address: 0x1029290 */
    }




    if (*pScrFlag & 2) { /* Line 1070, Address: 0x10292bc */
      *pScrFlag &= 253; /* Line 1071, Address: 0x10292d0 */

      lD4.l = 224; /* Line 1073, Address: 0x10292dc */
      wD5 = 65520; /* Line 1074, Address: 0x10292e4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1075, Address: 0x10292ec */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1077, Address: 0x102930c */
    }




    if (*pScrFlag & 4) { /* Line 1083, Address: 0x1029338 */
      *pScrFlag &= 251; /* Line 1084, Address: 0x102934c */

      lD4.l = -16; /* Line 1086, Address: 0x1029358 */
      wD5 = 65520; /* Line 1087, Address: 0x1029360 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1088, Address: 0x1029368 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1090, Address: 0x1029388 */
    }




    if (*pScrFlag & 8) { /* Line 1096, Address: 0x10293b4 */
      *pScrFlag &= 247; /* Line 1097, Address: 0x10293c8 */

      lD4.l = -16; /* Line 1099, Address: 0x10293d4 */
      wD5 = 320; /* Line 1100, Address: 0x10293dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1101, Address: 0x10293e4 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1103, Address: 0x1029404 */
    }
  }






} /* Line 1112, Address: 0x1029430 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1129, Address: 0x1029460 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1134, Address: 0x1029480 */
    if (*pScrFlag & 1) { /* Line 1135, Address: 0x1029490 */
      *pScrFlag &= 254;; /* Line 1136, Address: 0x10294a8 */

      lD4.l = -16; /* Line 1138, Address: 0x10294bc */
      wD5 = 65520; /* Line 1139, Address: 0x10294c4 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1141, Address: 0x10294cc */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1143, Address: 0x10294ec */
    }




    if (*pScrFlag & 2) { /* Line 1149, Address: 0x1029518 */
      *pScrFlag &= 253; /* Line 1150, Address: 0x1029530 */

      lD4.l = 224; /* Line 1152, Address: 0x1029544 */
      wD5 = 65520; /* Line 1153, Address: 0x102954c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1154, Address: 0x1029554 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1156, Address: 0x1029574 */
    }




    if (*pScrFlag & 4) { /* Line 1162, Address: 0x10295a0 */
      *pScrFlag &= 251; /* Line 1163, Address: 0x10295b8 */

      lD4.l = -16; /* Line 1165, Address: 0x10295cc */
      wD5 = 65520; /* Line 1166, Address: 0x10295d4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1167, Address: 0x10295dc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1169, Address: 0x10295fc */
    }




    if (*pScrFlag & 8) { /* Line 1175, Address: 0x1029628 */
      *pScrFlag &= 247; /* Line 1176, Address: 0x1029640 */

      lD4.l = -16; /* Line 1178, Address: 0x1029654 */
      wD5 = 320; /* Line 1179, Address: 0x102965c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1180, Address: 0x1029664 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1182, Address: 0x1029684 */
    }
  }






} /* Line 1191, Address: 0x10296b0 */






void scrollwrtc() {} /* Line 1198, Address: 0x10296d0 */




void scrollwrtz() {} /* Line 1203, Address: 0x10296e0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1221, Address: 0x10296f0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1234, Address: 0x1029718 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1237, Address: 0x1029738 */
    pTilePoint->x += 2; /* Line 1238, Address: 0x102974c */
    if (pTilePoint->x >= 64) { /* Line 1239, Address: 0x1029760 */
      pTilePoint->x -= 64; /* Line 1240, Address: 0x1029774 */
    }
    xOffs += 16; /* Line 1242, Address: 0x1029788 */
  } while (--lpcnt >= 0); /* Line 1243, Address: 0x1029794 */
} /* Line 1244, Address: 0x10297a8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1248, Address: 0x10297c0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1252, Address: 0x10297e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1255, Address: 0x1029808 */
    pTilePoint->x += 2; /* Line 1256, Address: 0x102981c */
    if (pTilePoint->x >= 64) { /* Line 1257, Address: 0x1029830 */
      pTilePoint->x -= 64; /* Line 1258, Address: 0x1029844 */
    }
    xOffs += 16; /* Line 1260, Address: 0x1029858 */
  } while (--lpcnt >= 0); /* Line 1261, Address: 0x1029864 */
} /* Line 1262, Address: 0x1029878 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1282, Address: 0x1029890 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1286, Address: 0x10298b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1289, Address: 0x10298d8 */
    pTilePoint->y += 2; /* Line 1290, Address: 0x10298ec */
    if (pTilePoint->y >= 32) { /* Line 1291, Address: 0x10298fc */
      pTilePoint->y -= 32; /* Line 1292, Address: 0x1029910 */
    }
    yOffs += 16; /* Line 1294, Address: 0x1029920 */
  } while (--lpcnt >= 0); /* Line 1295, Address: 0x102992c */
} /* Line 1296, Address: 0x1029940 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1315, Address: 0x1029950 */
  int base = 0; /* Line 1316, Address: 0x1029984 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1321, Address: 0x1029988 */

    base = 1; /* Line 1323, Address: 0x1029998 */
  } /* Line 1324, Address: 0x102999c */
  else if (VramBase == 16384) { /* Line 1325, Address: 0x10299a4 */

    base = 0; /* Line 1327, Address: 0x10299b4 */
  }
  x = pTilePoint->x; /* Line 1329, Address: 0x10299b8 */
  y = pTilePoint->y; /* Line 1330, Address: 0x10299c0 */


  frip = BlkIndex & 6144; /* Line 1333, Address: 0x10299c8 */
  BlkIndex &= 1023; /* Line 1334, Address: 0x10299d0 */
  if (frip == 6144) { /* Line 1335, Address: 0x10299dc */

    p0 = 3, p1 = 2; /* Line 1337, Address: 0x10299e8 */
    p2 = 1, p3 = 0; /* Line 1338, Address: 0x10299f0 */
  } /* Line 1339, Address: 0x10299f8 */
  else if (frip & 4096) { /* Line 1340, Address: 0x1029a00 */

    p0 = 2, p1 = 3; /* Line 1342, Address: 0x1029a0c */
    p2 = 0, p3 = 1; /* Line 1343, Address: 0x1029a14 */
  } /* Line 1344, Address: 0x1029a1c */
  else if (frip & 2048) { /* Line 1345, Address: 0x1029a24 */

    p0 = 1, p1 = 0; /* Line 1347, Address: 0x1029a30 */
    p2 = 3, p3 = 2; /* Line 1348, Address: 0x1029a38 */
  } /* Line 1349, Address: 0x1029a40 */
  else {

    p0 = 0, p1 = 1; /* Line 1352, Address: 0x1029a48 */
    p2 = 2, p3 = 3; /* Line 1353, Address: 0x1029a50 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1356, Address: 0x1029a58 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1357, Address: 0x1029a9c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1358, Address: 0x1029ae0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1359, Address: 0x1029b24 */

} /* Line 1361, Address: 0x1029b68 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1379, Address: 0x1029ba0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1380, Address: 0x1029bc0 */
} /* Line 1381, Address: 0x1029be0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1383, Address: 0x1029bf0 */
  wH_posiw = 0; /* Line 1384, Address: 0x1029c10 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1385, Address: 0x1029c14 */
} /* Line 1386, Address: 0x1029c34 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1393, Address: 0x1029c50 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1399, Address: 0x1029c80 */
  yOffs += wV_posiw; /* Line 1400, Address: 0x1029c90 */





  if ((short)xOffs < 0) /* Line 1406, Address: 0x1029ca0 */
    xOffs = 0; /* Line 1407, Address: 0x1029cbc */
  if ((short)yOffs < 0) /* Line 1408, Address: 0x1029cc0 */

    yOffs = (short)yOffs + 2048; /* Line 1410, Address: 0x1029cdc */
  if ((short)xOffs >= 16384) /* Line 1411, Address: 0x1029cfc */
    xOffs = 16383; /* Line 1412, Address: 0x1029d1c */
  if ((short)yOffs >= 2048) /* Line 1413, Address: 0x1029d24 */

    yOffs = (short)yOffs - 2048; /* Line 1415, Address: 0x1029d44 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1416, Address: 0x1029d64 */
  if (i < 0) i = 0; /* Line 1417, Address: 0x1029dac */

  ScreenNo = pMapWk[i] & 127; /* Line 1419, Address: 0x1029db8 */

  if (ScreenNo) { /* Line 1421, Address: 0x1029dd4 */




    xOffs &= 32767; /* Line 1426, Address: 0x1029ddc */
    yOffs &= 32767; /* Line 1427, Address: 0x1029de8 */


    xBlk = xOffs; /* Line 1430, Address: 0x1029df4 */
    xBlk %= 256; /* Line 1431, Address: 0x1029dfc */
    xBlk /= 16; /* Line 1432, Address: 0x1029e1c */
    yBlk = yOffs; /* Line 1433, Address: 0x1029e38 */
    yBlk %= 256; /* Line 1434, Address: 0x1029e40 */
    yBlk /= 16; /* Line 1435, Address: 0x1029e60 */

    lpw = pmapwk; /* Line 1437, Address: 0x1029e7c */
    lpw += xBlk; /* Line 1438, Address: 0x1029e84 */
    lpw += yBlk * 16; /* Line 1439, Address: 0x1029e8c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1440, Address: 0x1029e98 */
    *pIndex = *lpw; /* Line 1441, Address: 0x1029eb0 */

    return 1; /* Line 1443, Address: 0x1029ec0 */
  }

  *pIndex = 0; /* Line 1446, Address: 0x1029ecc */
  return 0; /* Line 1447, Address: 0x1029ed4 */
} /* Line 1448, Address: 0x1029ed8 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1468, Address: 0x1029f00 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1476, Address: 0x1029f28 */
  if (ScreenNo) { /* Line 1477, Address: 0x1029f8c */





    xBlk = xOffs; /* Line 1483, Address: 0x1029f94 */
    xBlk %= 256; /* Line 1484, Address: 0x1029f9c */
    xBlk /= 16; /* Line 1485, Address: 0x1029fbc */
    yBlk = yOffs; /* Line 1486, Address: 0x1029fd8 */
    yBlk %= 256; /* Line 1487, Address: 0x1029fe0 */
    yBlk /= 16; /* Line 1488, Address: 0x102a000 */


    lpw = pmapwk; /* Line 1491, Address: 0x102a01c */
    lpw += xBlk; /* Line 1492, Address: 0x102a024 */
    lpw += yBlk * 16; /* Line 1493, Address: 0x102a02c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1494, Address: 0x102a038 */
    *ppBlockNo = lpw; /* Line 1495, Address: 0x102a050 */
    *pIndex = *lpw; /* Line 1496, Address: 0x102a058 */




    return 1; /* Line 1501, Address: 0x102a068 */
  }

  *pIndex = 0; /* Line 1504, Address: 0x102a074 */
  return 0; /* Line 1505, Address: 0x102a07c */
} /* Line 1506, Address: 0x102a080 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1520, Address: 0x102a0a0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1527, Address: 0x102a0bc */
  pMapWk = (unsigned char*)mapwka; /* Line 1528, Address: 0x102a0c0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1529, Address: 0x102a0c8 */
    *pBlockIndex = BlockNo; /* Line 1530, Address: 0x102a0ec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1531, Address: 0x102a0f8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1532, Address: 0x102a110 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1533, Address: 0x102a124 */
    }
  }


} /* Line 1538, Address: 0x102a13c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1552, Address: 0x102a160 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1553, Address: 0x102a16c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1554, Address: 0x102a198 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1555, Address: 0x102a1e4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1556, Address: 0x102a210 */

          return 0; /* Line 1558, Address: 0x102a25c */
        }
      }
    }
  }

  return 1; /* Line 1564, Address: 0x102a268 */
} /* Line 1565, Address: 0x102a26c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1582, Address: 0x102a280 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1583, Address: 0x102a29c */

} /* Line 1585, Address: 0x102a2b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1587, Address: 0x102a2d0 */
  wH_posiw = 0; /* Line 1588, Address: 0x102a2ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1589, Address: 0x102a2f0 */

} /* Line 1591, Address: 0x102a30c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1593, Address: 0x102a320 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1594, Address: 0x102a334 */

} /* Line 1596, Address: 0x102a350 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1598, Address: 0x102a360 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1599, Address: 0x102a37c */

} /* Line 1601, Address: 0x102a398 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1603, Address: 0x102a3b0 */
  xOffs += wH_posiw; /* Line 1604, Address: 0x102a3c8 */
  yOffs += wV_posiw; /* Line 1605, Address: 0x102a3d8 */
  yOffs &= 240; /* Line 1606, Address: 0x102a3e8 */
  xOffs &= 496; /* Line 1607, Address: 0x102a3f4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1609, Address: 0x102a400 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1610, Address: 0x102a42c */


} /* Line 1613, Address: 0x102a458 */















void mapwrt() { /* Line 1629, Address: 0x102a470 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1634, Address: 0x102a488 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1635, Address: 0x102a494 */
  pMapWk = (unsigned char*)mapwka; /* Line 1636, Address: 0x102a4a0 */
  VramBase = 16384; /* Line 1637, Address: 0x102a4a8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1638, Address: 0x102a4ac */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1640, Address: 0x102a4c4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1641, Address: 0x102a4d0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1642, Address: 0x102a4dc */
  VramBase = 24576; /* Line 1643, Address: 0x102a4e4 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1645, Address: 0x102a4e8 */

} /* Line 1647, Address: 0x102a500 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1651, Address: 0x102a520 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1652, Address: 0x102a538 */
} /* Line 1653, Address: 0x102a558 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1658, Address: 0x102a570 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1662, Address: 0x102a590 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1665, Address: 0x102a5ac */



    wD4 += 16; /* Line 1669, Address: 0x102a5d4 */
  } while ((short)--wD6 >= 0); /* Line 1670, Address: 0x102a5e0 */

} /* Line 1672, Address: 0x102a608 */













































































































void mapinit() { /* Line 1782, Address: 0x102a620 */

  colorset2(mapinittbl.colorno2); /* Line 1784, Address: 0x102a628 */
  colorset(mapinittbl.colorno2); /* Line 1785, Address: 0x102a63c */


  if (play_start & 2) divdevset(); /* Line 1788, Address: 0x102a650 */
} /* Line 1789, Address: 0x102a670 */










void mapset() {} /* Line 1800, Address: 0x102a680 */
