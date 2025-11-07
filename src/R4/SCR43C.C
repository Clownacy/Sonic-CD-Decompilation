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
unsigned short scr_dir_tbl[6] = {
  4, 0, 3479, 0, 2048, 96
};
extern unsigned char awasintbl[256];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;













































































void enecginit(void) {} /* Line 129, Address: 0x1020800 */



void divdevset() {} /* Line 133, Address: 0x1020810 */














































sprite_status* main_chk(void) {
  if (!main_play) return &actwk[0]; /* Line 181, Address: 0x1020820 */
  else return &actwk[1]; /* Line 182, Address: 0x1020840 */
} /* Line 183, Address: 0x1020848 */






void scr_set(void) { /* Line 190, Address: 0x1020850 */
  int i;







  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 199, Address: 0x102085c */

  i = 0; /* Line 201, Address: 0x10208a4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 202, Address: 0x10208a8 */
  scralim_left = scr_dir_tbl[i]; /* Line 203, Address: 0x10208cc */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 204, Address: 0x10208e8 */
  scralim_right = scr_dir_tbl[i]; /* Line 205, Address: 0x102090c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 206, Address: 0x1020928 */
  scralim_up = scr_dir_tbl[i]; /* Line 207, Address: 0x102094c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 208, Address: 0x1020968 */
  scralim_down = scr_dir_tbl[i]; /* Line 209, Address: 0x102098c */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 210, Address: 0x10209a8 */

  scra_h_keep = scralim_left + 576; /* Line 212, Address: 0x10209cc */
  scra_h_count = 16; /* Line 213, Address: 0x10209f0 */
  scra_v_count = 16; /* Line 214, Address: 0x10209fc */

  scra_vline = scr_dir_tbl[i++]; /* Line 216, Address: 0x1020a08 */
  scra_hline = 160; /* Line 217, Address: 0x1020a2c */

  playposiset(); /* Line 219, Address: 0x1020a38 */
} /* Line 220, Address: 0x1020a40 */



void playposiset(void) { /* Line 224, Address: 0x1020a60 */
  unsigned short endplpositbl[16] = { /* Line 225, Address: 0x1020a74 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned short playpositbl[4] = { /* Line 235, Address: 0x1020aa8 */
     80, 364,
    976, 940
  };

  unsigned char playmapnotbl[4] = { /* Line 240, Address: 0x1020ad4 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (lpKeepWork->demoflag.w) { /* Line 248, Address: 0x1020b00 */
    xWk = actwk[0].xposi.w.h = playpositbl[2]; /* Line 249, Address: 0x1020b14 */
    yWk = actwk[0].yposi.w.h = playpositbl[3]; /* Line 250, Address: 0x1020b28 */
  } else { /* Line 251, Address: 0x1020b3c */
    if (plflag != 0) { /* Line 252, Address: 0x1020b44 */

      playload(); /* Line 254, Address: 0x1020b58 */
      xWk = actwk[0].xposi.w.h; /* Line 255, Address: 0x1020b60 */
      yWk = actwk[0].yposi.w.h; /* Line 256, Address: 0x1020b70 */
      if (yWk < 0) yWk = 0; /* Line 257, Address: 0x1020b80 */
    } /* Line 258, Address: 0x1020b94 */
    else {

      xWk = actwk[0].xposi.w.h = playpositbl[0]; /* Line 261, Address: 0x1020b9c */
      yWk = actwk[0].yposi.w.h = playpositbl[1]; /* Line 262, Address: 0x1020bb0 */
    }
  }
  if ((unsigned short)xWk > 160) { /* Line 265, Address: 0x1020bc4 */
    xWk -= 160; /* Line 266, Address: 0x1020bd8 */
  } /* Line 267, Address: 0x1020be4 */
  else {
    xWk = 0; /* Line 269, Address: 0x1020bec */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 273, Address: 0x1020bf0 */
    xWk = scralim_right; /* Line 274, Address: 0x1020c14 */
  }
  scra_h_posit.w.h = xWk; /* Line 276, Address: 0x1020c24 */

  if ((unsigned short)yWk > 96) { /* Line 278, Address: 0x1020c2c */
    yWk -= 96; /* Line 279, Address: 0x1020c40 */
  } /* Line 280, Address: 0x1020c4c */
  else {
    yWk = 0; /* Line 282, Address: 0x1020c54 */
  }

  if (scralim_down < yWk) { /* Line 285, Address: 0x1020c58 */
    yWk = scralim_down; /* Line 286, Address: 0x1020c7c */
  }

  scra_v_posit.w.h = yWk; /* Line 289, Address: 0x1020c8c */


  scrbinit(xWk); /* Line 292, Address: 0x1020c94 */

  i = 0; /* Line 294, Address: 0x1020ca0 */
  loopmapno = playmapnotbl[i++]; /* Line 295, Address: 0x1020ca4 */
  loopmapno2 = playmapnotbl[i++]; /* Line 296, Address: 0x1020cbc */
  ballmapno = playmapnotbl[i++]; /* Line 297, Address: 0x1020cd4 */
  ballmapno2 = playmapnotbl[i++]; /* Line 298, Address: 0x1020cec */


} /* Line 301, Address: 0x1020d04 */



void scrbinit(short yWk) { /* Line 305, Address: 0x1020d20 */
  uint_union data;


  data.l = 0; /* Line 309, Address: 0x1020d28 */
  data.w.l = scra_v_posit.w.h; /* Line 310, Address: 0x1020d2c */
  data.w.l >>= 1; /* Line 311, Address: 0x1020d38 */

  scrb_v_posit.w.h = data.w.l; /* Line 313, Address: 0x1020d44 */
  scrb_v_posit.w.l = 0; /* Line 314, Address: 0x1020d50 */
  scrc_v_posit.w.h = data.w.l; /* Line 315, Address: 0x1020d58 */
  scrz_v_posit.w.h = data.w.l; /* Line 316, Address: 0x1020d64 */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 318, Address: 0x1020d70 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 319, Address: 0x1020d94 */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 320, Address: 0x1020dc0 */




} /* Line 325, Address: 0x1020dec */



void scroll(void) { /* Line 329, Address: 0x1020e00 */
  uint_union data;
  int_union temp1, temp2;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 335, Address: 0x1020e10 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 338, Address: 0x1020e20 */
  scrchk(); /* Line 339, Address: 0x1020e4c */
  scroll_h(); /* Line 340, Address: 0x1020e54 */
  scroll_v(); /* Line 341, Address: 0x1020e5c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 343, Address: 0x1020e64 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 344, Address: 0x1020e74 */



  temp1.l = (long int)(scra_hz << 2) * 3; /* Line 348, Address: 0x1020e84 */
  temp2.l = scra_vz << 7; /* Line 349, Address: 0x1020eb4 */
  scrollb_hv(&temp1, &temp2); /* Line 350, Address: 0x1020ecc */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 352, Address: 0x1020edc */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 353, Address: 0x1020eec */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 354, Address: 0x1020efc */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 356, Address: 0x1020f0c */
  scrflagz.b.h = 0; /* Line 357, Address: 0x1020f40 */
  scrflagc.b.h = 0; /* Line 358, Address: 0x1020f48 */

  hsCount = 0; /* Line 360, Address: 0x1020f50 */
  for (i = 0; i < 192; ++i) { /* Line 361, Address: 0x1020f54 */


    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 364, Address: 0x1020f60 */
    ++hsCount; /* Line 365, Address: 0x1020f90 */
  } /* Line 366, Address: 0x1020f94 */

  data.w.l = -scra_h_posit.w.h; /* Line 368, Address: 0x1020fa4 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 369, Address: 0x1020fc0 */
  data.w.l = scrb_v_posit.w.h; /* Line 370, Address: 0x1020fe4 */
  data.w.l &= 1016; /* Line 371, Address: 0x1020ff0 */
  data.w.l >>= 2; /* Line 372, Address: 0x1020ffc */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 373, Address: 0x1021008 */

} /* Line 375, Address: 0x1021058 */





































static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 413, Address: 0x1021070 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 420, Address: 0x102108c */
  data1.b.l = waterdirec.b.h; /* Line 421, Address: 0x1021094 */
  data2.b.l = waterdirec.b.h; /* Line 422, Address: 0x10210a0 */
  waterdirec.w += 128; /* Line 423, Address: 0x10210ac */
  data1.w += scrb_v_posit.w.h; /* Line 424, Address: 0x10210c0 */
  data1.b.h = 0; /* Line 425, Address: 0x10210d4 */
  data2.w += scra_v_posit.w.h; /* Line 426, Address: 0x10210d8 */
  data2.b.h = 0; /* Line 427, Address: 0x10210ec */

  VPosi &= 7; /* Line 429, Address: 0x10210f0 */
  hsw.w.l = hscrollwork[offs++]; /* Line 430, Address: 0x10210fc */
  avp = scra_v_posit.w.h; /* Line 431, Address: 0x1021124 */
  i = 232; /* Line 432, Address: 0x1021134 */


  do {
    if (avp > waterposi) { /* Line 436, Address: 0x1021138 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 441, Address: 0x102115c */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 442, Address: 0x1021164 */
        ++pHScrollBuff; /* Line 443, Address: 0x10211b4 */
        ++data1.b.l; /* Line 444, Address: 0x10211b8 */
        ++data2.b.l; /* Line 445, Address: 0x10211c4 */
        ++VPosi; /* Line 446, Address: 0x10211d0 */
        if (VPosi == 8) { /* Line 447, Address: 0x10211dc */

          VPosi = 0; /* Line 449, Address: 0x10211f4 */
          hsw.w.l = hscrollwork[offs++]; /* Line 450, Address: 0x10211f8 */
        }
      } while (--i > 0); /* Line 452, Address: 0x1021220 */

      return; /* Line 454, Address: 0x102122c */
    }
    pHScrollBuff->l = hsw.l; /* Line 456, Address: 0x1021234 */
    ++pHScrollBuff; /* Line 457, Address: 0x102123c */
    ++avp; /* Line 458, Address: 0x1021240 */
    ++data1.b.l; /* Line 459, Address: 0x102124c */
    ++data2.b.l; /* Line 460, Address: 0x1021258 */
    ++VPosi; /* Line 461, Address: 0x1021264 */
    if (VPosi == 8) { /* Line 462, Address: 0x1021270 */

      VPosi = 0; /* Line 464, Address: 0x1021288 */
      hsw.w.l = hscrollwork[offs++]; /* Line 465, Address: 0x102128c */
    }
  } while (--i > 0); /* Line 467, Address: 0x10212b4 */

} /* Line 469, Address: 0x10212c0 */











void scroll_h(void) { /* Line 481, Address: 0x10212e0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 484, Address: 0x10212ec */
  scrh_move(); /* Line 485, Address: 0x10212f8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 486, Address: 0x1021300 */
    scra_h_count ^= 16; /* Line 487, Address: 0x1021334 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 488, Address: 0x1021348 */
      scrflaga.b.h |= 4; /* Line 489, Address: 0x1021374 */
    } /* Line 490, Address: 0x1021388 */
    else {

      scrflaga.b.h |= 8; /* Line 493, Address: 0x1021390 */
    }
  }


} /* Line 498, Address: 0x10213a4 */

void scrh_move(void) { /* Line 500, Address: 0x10213c0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 503, Address: 0x10213cc */
  wD0 -= scra_h_posit.w.h; /* Line 504, Address: 0x10213d8 */
  wD0 -= scra_hline; /* Line 505, Address: 0x10213ec */
  if (wD0 == 0) { /* Line 506, Address: 0x1021400 */

    scra_hz = 0; /* Line 508, Address: 0x102140c */
  } /* Line 509, Address: 0x1021414 */
  else if ((short)wD0 < 0) { /* Line 510, Address: 0x102141c */
    left_check(wD0); /* Line 511, Address: 0x1021434 */
  } /* Line 512, Address: 0x1021440 */
  else {
    right_check(wD0); /* Line 514, Address: 0x1021448 */
  }

} /* Line 517, Address: 0x1021454 */


void right_check(unsigned short wD0) { /* Line 520, Address: 0x1021470 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 523, Address: 0x102147c */
    wD0 = 16; /* Line 524, Address: 0x102149c */
  }

  wD0 += scra_h_posit.w.h; /* Line 527, Address: 0x10214a4 */
  if (scralim_right < (short)wD0) { /* Line 528, Address: 0x10214bc */
    wD0 = scralim_right; /* Line 529, Address: 0x10214ec */
  }

  wD1 = wD0; /* Line 532, Address: 0x10214f8 */
  wD1 -= scra_h_posit.w.h; /* Line 533, Address: 0x1021500 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 534, Address: 0x1021514 */
  scra_h_posit.w.h = wD0; /* Line 535, Address: 0x1021544 */
  scra_hz = wD1; /* Line 536, Address: 0x1021550 */

} /* Line 538, Address: 0x1021558 */


void left_check(unsigned short wD0) { /* Line 541, Address: 0x1021570 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 544, Address: 0x102157c */
    wD0 = -16; /* Line 545, Address: 0x102159c */
  }

  wD0 += scra_h_posit.w.h; /* Line 548, Address: 0x10215a4 */
  if (scralim_left > (short)wD0) { /* Line 549, Address: 0x10215bc */
    wD0 = scralim_left; /* Line 550, Address: 0x10215ec */
  }

  wD1 = wD0; /* Line 553, Address: 0x10215f8 */
  wD1 -= scra_h_posit.w.h; /* Line 554, Address: 0x1021600 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 555, Address: 0x1021614 */
  scra_h_posit.w.h = wD0; /* Line 556, Address: 0x1021644 */
  scra_hz = wD1; /* Line 557, Address: 0x1021650 */

} /* Line 559, Address: 0x1021658 */


















void scroll_v(void) { /* Line 578, Address: 0x1021670 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 581, Address: 0x102167c */
  if (actwk[0].cddat & 4) { /* Line 582, Address: 0x10216a8 */
    wD0 -= 5; /* Line 583, Address: 0x10216c0 */
  }

  if (actwk[0].cddat & 2) { /* Line 586, Address: 0x10216c8 */
    wD0 += 32; /* Line 587, Address: 0x10216e0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 588, Address: 0x10216e8 */
      wD0 -= scra_vline; /* Line 589, Address: 0x1021708 */
      sv_move_main2(wD0); /* Line 590, Address: 0x102171c */
      return; /* Line 591, Address: 0x1021728 */
    }
    wD0 -= scra_vline; /* Line 593, Address: 0x1021730 */
    if (wD0 >= 64) { /* Line 594, Address: 0x1021744 */
      wD0 -= 64; /* Line 595, Address: 0x1021754 */
      sv_move_main2(wD0); /* Line 596, Address: 0x102175c */
      return; /* Line 597, Address: 0x1021768 */
    }
    wD0 -= 64; /* Line 599, Address: 0x1021770 */
    if (limmoveflag == 0) goto label1; /* Line 600, Address: 0x1021778 */
    sv_move_sub2(); /* Line 601, Address: 0x102178c */
    return; /* Line 602, Address: 0x1021794 */
  }




  wD0 -= scra_vline; /* Line 608, Address: 0x102179c */
  if (wD0) { /* Line 609, Address: 0x10217b0 */
    sv_move_main(wD0); /* Line 610, Address: 0x10217b8 */
    return; /* Line 611, Address: 0x10217c4 */
  }
  if (limmoveflag == 0) { /* Line 613, Address: 0x10217cc */
    sv_move_sub2(); /* Line 614, Address: 0x10217e0 */
    return; /* Line 615, Address: 0x10217e8 */
  }


label1:
  scra_vz = 0; /* Line 620, Address: 0x10217f0 */

} /* Line 622, Address: 0x10217f8 */





void sv_move_main(unsigned short wD0) { /* Line 628, Address: 0x1021810 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 631, Address: 0x1021820 */
    sv_move_main1(wD0); /* Line 632, Address: 0x102183c */
  } /* Line 633, Address: 0x1021848 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 636, Address: 0x1021850 */
    if ((short)wD1 < 0) { /* Line 637, Address: 0x102185c */
      wD1 = -(short)wD1; /* Line 638, Address: 0x1021874 */
    }

    if (wD1 >= 2048) { /* Line 641, Address: 0x1021890 */
      sv_move_main2(wD0); /* Line 642, Address: 0x10218a0 */
    } /* Line 643, Address: 0x10218ac */
    else {
      if ((short)wD0 > 6) { /* Line 645, Address: 0x10218b4 */
        sv_move_plus(1536); /* Line 646, Address: 0x10218d4 */
      } /* Line 647, Address: 0x10218e0 */
      else if ((short)wD0 < -6) { /* Line 648, Address: 0x10218e8 */
        sv_move_minus(1536); /* Line 649, Address: 0x1021908 */
      } /* Line 650, Address: 0x1021914 */
      else {
        sv_move_sub(wD0); /* Line 652, Address: 0x102191c */
      }
    }
  }
} /* Line 656, Address: 0x1021928 */



void sv_move_main1(unsigned short wD0) { /* Line 660, Address: 0x1021940 */

  if ((short)wD0 > 2) { /* Line 662, Address: 0x102194c */
    sv_move_plus(512); /* Line 663, Address: 0x102196c */
  } /* Line 664, Address: 0x1021978 */
  else if ((short)wD0 < -2) { /* Line 665, Address: 0x1021980 */
    sv_move_minus(512); /* Line 666, Address: 0x10219a0 */
  } /* Line 667, Address: 0x10219ac */
  else {
    sv_move_sub(wD0); /* Line 669, Address: 0x10219b4 */
  }

} /* Line 672, Address: 0x10219c0 */


void sv_move_main2(unsigned short wD0) { /* Line 675, Address: 0x10219d0 */

  if ((short)wD0 > 16) { /* Line 677, Address: 0x10219dc */
    sv_move_plus(4096); /* Line 678, Address: 0x10219fc */
  } /* Line 679, Address: 0x1021a08 */
  else if ((short)wD0 < -16) { /* Line 680, Address: 0x1021a10 */
    sv_move_minus(4096); /* Line 681, Address: 0x1021a30 */
  } /* Line 682, Address: 0x1021a3c */
  else {
    sv_move_sub(wD0); /* Line 684, Address: 0x1021a44 */
  }

} /* Line 687, Address: 0x1021a50 */


void sv_move_sub2(void) { /* Line 690, Address: 0x1021a60 */
  limmoveflag = 0; /* Line 691, Address: 0x1021a68 */
  sv_move_sub(0); /* Line 692, Address: 0x1021a70 */
} /* Line 693, Address: 0x1021a7c */


void sv_move_sub(unsigned short wD0) { /* Line 696, Address: 0x1021a90 */
  int_union lD1;

  lD1.w.h = 0; /* Line 699, Address: 0x1021a9c */
  lD1.w.l = wD0; /* Line 700, Address: 0x1021aa0 */
  lD1.l += scra_v_posit.w.h; /* Line 701, Address: 0x1021aa8 */
  if ((short)wD0 > 0) { /* Line 702, Address: 0x1021ac4 */
    scrv_down_ch(lD1); /* Line 703, Address: 0x1021ae0 */
  } /* Line 704, Address: 0x1021aec */
  else {
    scrv_up_ch(lD1); /* Line 706, Address: 0x1021af4 */
  }

} /* Line 709, Address: 0x1021b00 */




void sv_move_minus(unsigned short wD1) { /* Line 714, Address: 0x1021b10 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 718, Address: 0x1021b20 */
  lD1.l <<= 8; /* Line 719, Address: 0x1021b3c */
  lD1.l += scra_v_posit.l; /* Line 720, Address: 0x1021b48 */

  wk = lD1.w.h; /* Line 722, Address: 0x1021b5c */
  lD1.w.h = lD1.w.l; /* Line 723, Address: 0x1021b64 */
  lD1.w.l = wk; /* Line 724, Address: 0x1021b6c */
  scrv_up_ch(lD1); /* Line 725, Address: 0x1021b70 */
} /* Line 726, Address: 0x1021b7c */



void scrv_up_ch(int_union lD1) { /* Line 730, Address: 0x1021b90 */
  if (scralim_up >= lD1.w.l) { /* Line 731, Address: 0x1021b9c */
    if (lD1.w.l <= 0) { /* Line 732, Address: 0x1021bc4 */
      lD1.w.l &= 2047; /* Line 733, Address: 0x1021bd8 */
      actwk[0].yposi.w.h &= 2048; /* Line 734, Address: 0x1021be4 */
      scra_v_posit.w.h &= 2048; /* Line 735, Address: 0x1021bf8 */
      scrb_v_posit.w.h &= 2048; /* Line 736, Address: 0x1021c0c */
    } /* Line 737, Address: 0x1021c20 */
    else {

      lD1.w.l = scralim_up; /* Line 740, Address: 0x1021c28 */
    }
  }
  scrv_move(lD1); /* Line 743, Address: 0x1021c34 */

} /* Line 745, Address: 0x1021c40 */





void sv_move_plus(unsigned short wD1) { /* Line 751, Address: 0x1021c50 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 755, Address: 0x1021c60 */
  lD1.w.l = wD1; /* Line 756, Address: 0x1021c64 */
  lD1.l <<= 8; /* Line 757, Address: 0x1021c6c */
  lD1.l += scra_v_posit.l; /* Line 758, Address: 0x1021c78 */

  wk = lD1.w.h; /* Line 760, Address: 0x1021c8c */
  lD1.w.h = lD1.w.l; /* Line 761, Address: 0x1021c94 */
  lD1.w.l = wk; /* Line 762, Address: 0x1021c9c */

  scrv_down_ch(lD1); /* Line 764, Address: 0x1021ca0 */

} /* Line 766, Address: 0x1021cac */



void scrv_down_ch(int_union lD1) { /* Line 770, Address: 0x1021cc0 */
  if (scralim_down <= lD1.w.l) { /* Line 771, Address: 0x1021ccc */
    lD1.w.l -= 2048; /* Line 772, Address: 0x1021cf4 */
    if (lD1.w.l > 0) { /* Line 773, Address: 0x1021d00 */
      actwk[0].yposi.w.h &= 2047; /* Line 774, Address: 0x1021d14 */
      scra_v_posit.w.h -= 2048; /* Line 775, Address: 0x1021d28 */
      scrb_v_posit.w.h &= 1023; /* Line 776, Address: 0x1021d3c */
    } /* Line 777, Address: 0x1021d50 */
    else {
      lD1.w.l = scralim_down; /* Line 779, Address: 0x1021d58 */
    }
  }
  scrv_move(lD1); /* Line 782, Address: 0x1021d64 */

} /* Line 784, Address: 0x1021d70 */


void scrv_move(int_union lD1) { /* Line 787, Address: 0x1021d80 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 790, Address: 0x1021d90 */

  wk = lD1.w.h; /* Line 792, Address: 0x1021d9c */
  lD1.w.h = lD1.w.l; /* Line 793, Address: 0x1021da4 */
  lD1.w.l = wk; /* Line 794, Address: 0x1021dac */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 796, Address: 0x1021db0 */
  scra_v_posit.l = lD1.l; /* Line 797, Address: 0x1021dd8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 800, Address: 0x1021de4 */
    scra_v_count ^= 16; /* Line 801, Address: 0x1021e18 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 802, Address: 0x1021e2c */

      scrflaga.b.h |= 2; /* Line 804, Address: 0x1021e58 */
    } /* Line 805, Address: 0x1021e6c */
    else {
      scrflaga.b.h |= 1; /* Line 807, Address: 0x1021e74 */
    }
  }


} /* Line 812, Address: 0x1021e88 */



void scrollb_hv(int_union* lD4, int_union* lD5) { /* Line 816, Address: 0x1021ea0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 819, Address: 0x1021eac */
  lD0.l += lD4->l; /* Line 820, Address: 0x1021ebc */
  scrb_h_posit.l = lD0.l; /* Line 821, Address: 0x1021ed0 */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 823, Address: 0x1021edc */

    scrb_h_count ^= 16; /* Line 825, Address: 0x1021f10 */
    lD0.l -= lD2.l; /* Line 826, Address: 0x1021f24 */
    if ((long int)lD0.l < 0) { /* Line 827, Address: 0x1021f34 */
      scrflagb.b.h |= 4; /* Line 828, Address: 0x1021f48 */
    } /* Line 829, Address: 0x1021f5c */
    else {

      scrflagb.b.h |= 8; /* Line 832, Address: 0x1021f64 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 837, Address: 0x1021f78 */
  lD0.l += lD5->l; /* Line 838, Address: 0x1021f88 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 839, Address: 0x1021f9c */
  scrb_v_posit.l = lD0.l; /* Line 840, Address: 0x1021fb4 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 842, Address: 0x1021fc0 */

    scrb_v_count ^= 16; /* Line 844, Address: 0x1021ff4 */
    lD0.l -= lD3.l; /* Line 845, Address: 0x1022008 */
    if ((long int)lD0.l < 0) { /* Line 846, Address: 0x1022018 */
      scrflagb.b.h |= 1; /* Line 847, Address: 0x102202c */
    } /* Line 848, Address: 0x1022040 */
    else {

      scrflagb.b.h |= 2; /* Line 851, Address: 0x1022048 */
    }
  }


} /* Line 856, Address: 0x102205c */






void scrollb_v(unsigned short wD0) { /* Line 863, Address: 0x1022070 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 866, Address: 0x102207c */
  scrb_v_posit.w.h = wD0; /* Line 867, Address: 0x1022088 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 869, Address: 0x1022094 */
    scrb_v_count ^= 16; /* Line 870, Address: 0x10220c0 */
    if ((short)wD3 > (short)wD0) { /* Line 871, Address: 0x10220d4 */
      scrflagb.b.h |= 1; /* Line 872, Address: 0x1022104 */
    } /* Line 873, Address: 0x1022118 */
    else {

      scrflagb.b.h |= 2; /* Line 876, Address: 0x1022120 */
    }
  }


} /* Line 881, Address: 0x1022134 */



void scrollb_h(int lD4, int flagb) { /* Line 885, Address: 0x1022150 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 889, Address: 0x1022160 */
  lD0.l = lD2.l + lD4; /* Line 890, Address: 0x102216c */
  scrb_h_posit.l = lD0.l; /* Line 891, Address: 0x102217c */

  lD1.w.h = lD0.w.l; /* Line 893, Address: 0x1022188 */
  lD1.w.l = lD0.w.h; /* Line 894, Address: 0x1022190 */
  lD1.w.l &= 16; /* Line 895, Address: 0x1022198 */

  bD3 = scrb_h_count; /* Line 897, Address: 0x10221a4 */
  lD1.b.b4 ^= bD3; /* Line 898, Address: 0x10221b0 */
  if (!lD1.b.b4) { /* Line 899, Address: 0x10221c4 */
    scrb_h_count ^= 16; /* Line 900, Address: 0x10221d0 */
    lD0.l -= lD2.l; /* Line 901, Address: 0x10221e4 */
    if ((long int)lD0.l < 0) { /* Line 902, Address: 0x10221f4 */
      scrflagb.b.h |= flagb; /* Line 903, Address: 0x1022208 */
    } /* Line 904, Address: 0x1022224 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 907, Address: 0x102222c */
    }
  }


} /* Line 912, Address: 0x102224c */


void scrollc_h(int lD4, int flagc) { /* Line 915, Address: 0x1022260 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 919, Address: 0x1022270 */
  lD0.l = lD2.l + lD4; /* Line 920, Address: 0x102227c */
  scrc_h_posit.l = lD0.l; /* Line 921, Address: 0x102228c */

  lD1.w.h = lD0.w.l; /* Line 923, Address: 0x1022298 */
  lD1.w.l = lD0.w.h; /* Line 924, Address: 0x10222a0 */
  lD1.w.l &= 16; /* Line 925, Address: 0x10222a8 */

  bD3 = scrc_h_count; /* Line 927, Address: 0x10222b4 */
  lD1.b.b4 ^= bD3; /* Line 928, Address: 0x10222c0 */
  if (!lD1.b.b4) { /* Line 929, Address: 0x10222d4 */
    scrc_h_count ^= 16; /* Line 930, Address: 0x10222e0 */
    lD0.l -= lD2.l; /* Line 931, Address: 0x10222f4 */
    if ((long int)lD0.l < 0) { /* Line 932, Address: 0x1022304 */
      scrflagc.b.h |= flagc; /* Line 933, Address: 0x1022318 */
    } /* Line 934, Address: 0x1022334 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 937, Address: 0x102233c */
    }
  }


} /* Line 942, Address: 0x102235c */











void scrollz_h(int lD4, int flagz) { /* Line 954, Address: 0x1022370 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 958, Address: 0x1022380 */
  lD0.l = lD2.l + lD4; /* Line 959, Address: 0x102238c */
  scrz_h_posit.l = lD0.l; /* Line 960, Address: 0x102239c */

  lD1.w.h = lD0.w.l; /* Line 962, Address: 0x10223a8 */
  lD1.w.l = lD0.w.h; /* Line 963, Address: 0x10223b0 */
  lD1.w.l &= 16; /* Line 964, Address: 0x10223b8 */

  bD3 = scrz_h_count; /* Line 966, Address: 0x10223c4 */
  lD1.b.b4 ^= bD3; /* Line 967, Address: 0x10223d0 */
  if (!lD1.b.b4) { /* Line 968, Address: 0x10223e4 */
    scrz_h_count ^= 16; /* Line 969, Address: 0x10223f0 */
    lD0.l -= lD2.l; /* Line 970, Address: 0x1022404 */
    if ((long int)lD0.l < 0) { /* Line 971, Address: 0x1022414 */
      scrflagz.b.h |= flagz; /* Line 972, Address: 0x1022428 */
    } /* Line 973, Address: 0x1022444 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 976, Address: 0x102244c */
    }
  }


} /* Line 981, Address: 0x102246c */













void scrollwrtadva(void) { /* Line 995, Address: 0x1022480 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1001, Address: 0x102249c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1002, Address: 0x10224a0 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1003, Address: 0x10224ac */
  pMapWk = (unsigned char*)mapwkb; /* Line 1004, Address: 0x10224b8 */
  pScrFlag = &scrflagb.b.h; /* Line 1005, Address: 0x10224c0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1006, Address: 0x10224c8 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1008, Address: 0x10224e4 */
  wV_posiw = scrc_v_posit.w.h; /* Line 1009, Address: 0x10224f0 */
  pScrFlag = &scrflagc.b.h; /* Line 1010, Address: 0x10224fc */
  scrollwrtc(); /* Line 1011, Address: 0x1022504 */

} /* Line 1013, Address: 0x102250c */












void scrollwrt(void) { /* Line 1026, Address: 0x1022530 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1035, Address: 0x1022550 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1036, Address: 0x1022554 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1037, Address: 0x1022560 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1038, Address: 0x102256c */
  pScrFlag = &scrflagbw.b.h; /* Line 1039, Address: 0x1022574 */
  scrollwrtb(pScrFlag, pMapWk, VramBase, wH_posiw, wV_posiw); /* Line 1040, Address: 0x102257c */

  VramBase = 16384; /* Line 1042, Address: 0x1022598 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1043, Address: 0x102259c */
  wV_posiw = scra_v_posiw.w.h; /* Line 1044, Address: 0x10225a8 */
  pMapWk = (unsigned char*)mapwka; /* Line 1045, Address: 0x10225b4 */
  pScrFlag = &scrflagaw.b.h; /* Line 1046, Address: 0x10225bc */

  if (*pScrFlag) { /* Line 1048, Address: 0x10225c4 */
    if (*pScrFlag & 1) { /* Line 1049, Address: 0x10225d0 */
      *pScrFlag &= 254; /* Line 1050, Address: 0x10225e4 */

      lD4.l = -16; /* Line 1052, Address: 0x10225f0 */
      wD5 = 65520; /* Line 1053, Address: 0x10225f8 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1055, Address: 0x1022600 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1057, Address: 0x1022620 */
    }




    if (*pScrFlag & 2) { /* Line 1063, Address: 0x102264c */
      *pScrFlag &= 253; /* Line 1064, Address: 0x1022660 */

      lD4.l = 224; /* Line 1066, Address: 0x102266c */
      wD5 = 65520; /* Line 1067, Address: 0x1022674 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1068, Address: 0x102267c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1070, Address: 0x102269c */
    }




    if (*pScrFlag & 4) { /* Line 1076, Address: 0x10226c8 */
      *pScrFlag &= 251; /* Line 1077, Address: 0x10226dc */

      lD4.l = -16; /* Line 1079, Address: 0x10226e8 */
      wD5 = 65520; /* Line 1080, Address: 0x10226f0 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1081, Address: 0x10226f8 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1083, Address: 0x1022718 */
    }




    if (*pScrFlag & 8) { /* Line 1089, Address: 0x1022744 */
      *pScrFlag &= 247; /* Line 1090, Address: 0x1022758 */

      lD4.l = -16; /* Line 1092, Address: 0x1022764 */
      wD5 = 320; /* Line 1093, Address: 0x102276c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1094, Address: 0x1022774 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1096, Address: 0x1022794 */
    }
  }






} /* Line 1105, Address: 0x10227c0 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw) { /* Line 1122, Address: 0x10227f0 */
  POINT TilePoint;
  int_union lD4;
  unsigned short wD5;

  if (*pScrFlag) { /* Line 1127, Address: 0x1022810 */
    if (*pScrFlag & 1) { /* Line 1128, Address: 0x1022820 */
      *pScrFlag &= 254; /* Line 1129, Address: 0x1022838 */

      lD4.l = -16; /* Line 1131, Address: 0x102284c */
      wD5 = 65520; /* Line 1132, Address: 0x1022854 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1134, Address: 0x102285c */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1136, Address: 0x102287c */
    }




    if (*pScrFlag & 2) { /* Line 1142, Address: 0x10228a8 */
      *pScrFlag &= 253; /* Line 1143, Address: 0x10228c0 */

      lD4.l = 224; /* Line 1145, Address: 0x10228d4 */
      wD5 = 65520; /* Line 1146, Address: 0x10228dc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1147, Address: 0x10228e4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1149, Address: 0x1022904 */
    }




    if (*pScrFlag & 4) { /* Line 1155, Address: 0x1022930 */
      *pScrFlag &= 251; /* Line 1156, Address: 0x1022948 */

      lD4.l = -16; /* Line 1158, Address: 0x102295c */
      wD5 = 65520; /* Line 1159, Address: 0x1022964 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1160, Address: 0x102296c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1162, Address: 0x102298c */
    }




    if (*pScrFlag & 8) { /* Line 1168, Address: 0x10229b8 */
      *pScrFlag &= 247; /* Line 1169, Address: 0x10229d0 */

      lD4.l = -16; /* Line 1171, Address: 0x10229e4 */
      wD5 = 320; /* Line 1172, Address: 0x10229ec */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1173, Address: 0x10229f4 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1175, Address: 0x1022a14 */
    }
  }






} /* Line 1184, Address: 0x1022a40 */






void scrollwrtc(void) {} /* Line 1191, Address: 0x1022a60 */




void scrollwrtz(void) {} /* Line 1196, Address: 0x1022a70 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1214, Address: 0x1022a80 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1227, Address: 0x1022aa8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1230, Address: 0x1022ac8 */
    pTilePoint->x += 2; /* Line 1231, Address: 0x1022adc */
    if (pTilePoint->x >= 64) { /* Line 1232, Address: 0x1022af0 */
      pTilePoint->x -= 64; /* Line 1233, Address: 0x1022b04 */
    }
    xOffs += 16; /* Line 1235, Address: 0x1022b18 */
  } while (--lpcnt >= 0); /* Line 1236, Address: 0x1022b24 */
} /* Line 1237, Address: 0x1022b38 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1241, Address: 0x1022b50 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1245, Address: 0x1022b78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1248, Address: 0x1022b98 */
    pTilePoint->x += 2; /* Line 1249, Address: 0x1022bac */
    if (pTilePoint->x >= 64) { /* Line 1250, Address: 0x1022bc0 */
      pTilePoint->x -= 64; /* Line 1251, Address: 0x1022bd4 */
    }
    xOffs += 16; /* Line 1253, Address: 0x1022be8 */
  } while (--lpcnt >= 0); /* Line 1254, Address: 0x1022bf4 */
} /* Line 1255, Address: 0x1022c08 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1275, Address: 0x1022c20 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1279, Address: 0x1022c48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1282, Address: 0x1022c68 */
    pTilePoint->y += 2; /* Line 1283, Address: 0x1022c7c */
    if (pTilePoint->y >= 32) { /* Line 1284, Address: 0x1022c8c */
      pTilePoint->y -= 32; /* Line 1285, Address: 0x1022ca0 */
    }
    yOffs += 16; /* Line 1287, Address: 0x1022cb0 */
  } while (--lpcnt >= 0); /* Line 1288, Address: 0x1022cbc */
} /* Line 1289, Address: 0x1022cd0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1308, Address: 0x1022ce0 */
  int base = 0; /* Line 1309, Address: 0x1022d14 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1314, Address: 0x1022d18 */

    base = 1; /* Line 1316, Address: 0x1022d28 */
  } /* Line 1317, Address: 0x1022d2c */
  else if (VramBase == 16384) { /* Line 1318, Address: 0x1022d34 */

    base = 0; /* Line 1320, Address: 0x1022d44 */
  }
  x = pTilePoint->x; /* Line 1322, Address: 0x1022d48 */
  y = pTilePoint->y; /* Line 1323, Address: 0x1022d50 */


  frip = BlkIndex & 6144; /* Line 1326, Address: 0x1022d58 */
  BlkIndex &= 1023; /* Line 1327, Address: 0x1022d60 */
  if (frip == 6144) { /* Line 1328, Address: 0x1022d6c */

    p0 = 3, p1 = 2; /* Line 1330, Address: 0x1022d78 */
    p2 = 1, p3 = 0; /* Line 1331, Address: 0x1022d80 */
  } /* Line 1332, Address: 0x1022d88 */
  else if (frip & 4096) { /* Line 1333, Address: 0x1022d90 */

    p0 = 2, p1 = 3; /* Line 1335, Address: 0x1022d9c */
    p2 = 0, p3 = 1; /* Line 1336, Address: 0x1022da4 */
  } /* Line 1337, Address: 0x1022dac */
  else if (frip & 2048) { /* Line 1338, Address: 0x1022db4 */

    p0 = 1, p1 = 0; /* Line 1340, Address: 0x1022dc0 */
    p2 = 3, p3 = 2; /* Line 1341, Address: 0x1022dc8 */
  } /* Line 1342, Address: 0x1022dd0 */
  else {

    p0 = 0, p1 = 1; /* Line 1345, Address: 0x1022dd8 */
    p2 = 2, p3 = 3; /* Line 1346, Address: 0x1022de0 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1349, Address: 0x1022de8 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1350, Address: 0x1022e2c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1351, Address: 0x1022e70 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1352, Address: 0x1022eb4 */

} /* Line 1354, Address: 0x1022ef8 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1372, Address: 0x1022f30 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1373, Address: 0x1022f50 */
} /* Line 1374, Address: 0x1022f70 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1376, Address: 0x1022f80 */
  wH_posiw = 0; /* Line 1377, Address: 0x1022fa0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1378, Address: 0x1022fa4 */
} /* Line 1379, Address: 0x1022fc4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1386, Address: 0x1022fe0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1392, Address: 0x1023010 */
  yOffs += wV_posiw; /* Line 1393, Address: 0x1023020 */





  if ((short)xOffs < 0) /* Line 1399, Address: 0x1023030 */
    xOffs = 0; /* Line 1400, Address: 0x102304c */
  if ((short)yOffs < 0) /* Line 1401, Address: 0x1023050 */

    yOffs = (short)yOffs + 2048; /* Line 1403, Address: 0x102306c */
  if ((short)xOffs >= 16384) /* Line 1404, Address: 0x102308c */
    xOffs = 16383; /* Line 1405, Address: 0x10230ac */
  if ((short)yOffs >= 2048) /* Line 1406, Address: 0x10230b4 */

    yOffs = (short)yOffs - 2048; /* Line 1408, Address: 0x10230d4 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1409, Address: 0x10230f4 */
  if (i < 0) i = 0; /* Line 1410, Address: 0x102313c */

  ScreenNo = pMapWk[i] & 127; /* Line 1412, Address: 0x1023148 */

  if (ScreenNo) { /* Line 1414, Address: 0x1023164 */




    xOffs &= 32767; /* Line 1419, Address: 0x102316c */
    yOffs &= 32767; /* Line 1420, Address: 0x1023178 */


    xBlk = xOffs; /* Line 1423, Address: 0x1023184 */
    xBlk %= 256; /* Line 1424, Address: 0x102318c */
    xBlk /= 16; /* Line 1425, Address: 0x10231ac */
    yBlk = yOffs; /* Line 1426, Address: 0x10231c8 */
    yBlk %= 256; /* Line 1427, Address: 0x10231d0 */
    yBlk /= 16; /* Line 1428, Address: 0x10231f0 */

    lpw = pmapwk; /* Line 1430, Address: 0x102320c */
    lpw += xBlk; /* Line 1431, Address: 0x1023214 */
    lpw += yBlk * 16; /* Line 1432, Address: 0x102321c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1433, Address: 0x1023228 */
    *pIndex = *lpw; /* Line 1434, Address: 0x1023240 */

    return 1; /* Line 1436, Address: 0x1023250 */
  }

  *pIndex = 0; /* Line 1439, Address: 0x102325c */
  return 0; /* Line 1440, Address: 0x1023264 */
} /* Line 1441, Address: 0x1023268 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1461, Address: 0x1023290 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1469, Address: 0x10232b8 */
  if (ScreenNo) { /* Line 1470, Address: 0x102331c */





    xBlk = xOffs; /* Line 1476, Address: 0x1023324 */
    xBlk %= 256; /* Line 1477, Address: 0x102332c */
    xBlk /= 16; /* Line 1478, Address: 0x102334c */
    yBlk = yOffs; /* Line 1479, Address: 0x1023368 */
    yBlk %= 256; /* Line 1480, Address: 0x1023370 */
    yBlk /= 16; /* Line 1481, Address: 0x1023390 */


    lpw = pmapwk; /* Line 1484, Address: 0x10233ac */
    lpw += xBlk; /* Line 1485, Address: 0x10233b4 */
    lpw += yBlk * 16; /* Line 1486, Address: 0x10233bc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1487, Address: 0x10233c8 */
    *ppBlockNo = lpw; /* Line 1488, Address: 0x10233e0 */
    *pIndex = *lpw; /* Line 1489, Address: 0x10233e8 */




    return 1; /* Line 1494, Address: 0x10233f8 */
  }

  *pIndex = 0; /* Line 1497, Address: 0x1023404 */
  return 0; /* Line 1498, Address: 0x102340c */
} /* Line 1499, Address: 0x1023410 */














void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1514, Address: 0x1023430 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1521, Address: 0x102344c */
  pMapWk = (unsigned char*)mapwka; /* Line 1522, Address: 0x1023450 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1523, Address: 0x1023458 */
    *pBlockIndex = BlockNo; /* Line 1524, Address: 0x102347c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1525, Address: 0x1023488 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1526, Address: 0x10234a0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1527, Address: 0x10234b4 */
    }
  }


} /* Line 1532, Address: 0x10234cc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1546, Address: 0x10234f0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1547, Address: 0x10234fc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1548, Address: 0x1023528 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1549, Address: 0x1023574 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1550, Address: 0x10235a0 */

          return 0; /* Line 1552, Address: 0x10235ec */
        }
      }
    }
  }

  return 1; /* Line 1558, Address: 0x10235f8 */
} /* Line 1559, Address: 0x10235fc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1576, Address: 0x1023610 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1577, Address: 0x102362c */

} /* Line 1579, Address: 0x1023648 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1581, Address: 0x1023660 */
  wH_posiw = 0; /* Line 1582, Address: 0x102367c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1583, Address: 0x1023680 */

} /* Line 1585, Address: 0x102369c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1587, Address: 0x10236b0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1588, Address: 0x10236c4 */

} /* Line 1590, Address: 0x10236e0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1592, Address: 0x10236f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1593, Address: 0x102370c */

} /* Line 1595, Address: 0x1023728 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1598, Address: 0x1023740 */
  xOffs += wH_posiw; /* Line 1599, Address: 0x1023758 */
  yOffs += wV_posiw; /* Line 1600, Address: 0x1023768 */
  yOffs &= 240; /* Line 1601, Address: 0x1023778 */
  xOffs &= 496; /* Line 1602, Address: 0x1023784 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1604, Address: 0x1023790 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1605, Address: 0x10237bc */


} /* Line 1608, Address: 0x10237e8 */















void mapwrt(void) { /* Line 1624, Address: 0x1023800 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1629, Address: 0x1023818 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1630, Address: 0x1023824 */
  pMapWk = (unsigned char*)mapwka; /* Line 1631, Address: 0x1023830 */
  VramBase = 16384; /* Line 1632, Address: 0x1023838 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1633, Address: 0x102383c */

  wH_posiw = scrb_h_posiw.w.h; /* Line 1635, Address: 0x1023854 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1636, Address: 0x1023860 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1637, Address: 0x102386c */
  VramBase = 24576; /* Line 1638, Address: 0x1023874 */

  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1640, Address: 0x1023878 */

} /* Line 1642, Address: 0x1023890 */



void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1646, Address: 0x10238b0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1647, Address: 0x10238c8 */
} /* Line 1648, Address: 0x10238e8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1653, Address: 0x1023900 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1657, Address: 0x1023920 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1660, Address: 0x102393c */



    wD4 += 16; /* Line 1664, Address: 0x1023964 */
  } while ((short)--wD6 >= 0); /* Line 1665, Address: 0x1023970 */

} /* Line 1667, Address: 0x1023998 */













































































































void mapinit(void) { /* Line 1777, Address: 0x10239b0 */

  colorset2(mapinittbl.colorno2); /* Line 1779, Address: 0x10239b8 */
  colorset(mapinittbl.colorno2); /* Line 1780, Address: 0x10239cc */


  if (play_start & 2) divdevset(); /* Line 1783, Address: 0x10239e0 */
} /* Line 1784, Address: 0x1023a00 */










void mapset(void) {}/* Line 1795, Address: 0x1023a10 */
