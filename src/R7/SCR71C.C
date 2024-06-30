#include "..\EQU.H"
#include "SCR71A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL7A.H"

static int z71aline(int hsCount);
static int z71aline0(int hsCount);
static void zonescrsetsub0(short VPosi, unsigned short offs);

static unsigned char z81awrttbl[65];
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
unsigned short scr_dir_tbl[6] = { 4, 0, 11927, 0, 1296, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;






















































































void enecginit() {} /* Line 123, Address: 0x1024a50 */



void divdevset() {} /* Line 127, Address: 0x1024a60 */
















































void scr_set() { /* Line 176, Address: 0x1024a70 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 179, Address: 0x1024a7c */

  i = 0; /* Line 181, Address: 0x1024ac4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 182, Address: 0x1024ac8 */
  scralim_left = scr_dir_tbl[i]; /* Line 183, Address: 0x1024aec */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 184, Address: 0x1024b08 */
  scralim_right = scr_dir_tbl[i]; /* Line 185, Address: 0x1024b2c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 186, Address: 0x1024b48 */
  scralim_up = scr_dir_tbl[i]; /* Line 187, Address: 0x1024b6c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 188, Address: 0x1024b88 */
  scralim_down = scr_dir_tbl[i]; /* Line 189, Address: 0x1024bac */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 190, Address: 0x1024bc8 */

  scra_h_keep = scralim_left + 576; /* Line 192, Address: 0x1024bec */
  scra_h_count = 16; /* Line 193, Address: 0x1024c10 */
  scra_v_count = 16; /* Line 194, Address: 0x1024c1c */

  scra_vline = scr_dir_tbl[i++]; /* Line 196, Address: 0x1024c28 */
  scra_hline = 160; /* Line 197, Address: 0x1024c4c */

  playposiset(); /* Line 199, Address: 0x1024c58 */
} /* Line 200, Address: 0x1024c60 */



void playposiset() { /* Line 204, Address: 0x1024c80 */
  unsigned short playpositbl[2] = { /* Line 205, Address: 0x1024c94 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 209, Address: 0x1024cb0 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 217, Address: 0x1024cdc */

    playload(); /* Line 219, Address: 0x1024cf0 */
    xWk = actwk[0].xposi.w.h; /* Line 220, Address: 0x1024cf8 */
    yWk = actwk[0].yposi.w.h; /* Line 221, Address: 0x1024d08 */
    if (yWk < 0) yWk = 0; /* Line 222, Address: 0x1024d18 */
  } /* Line 223, Address: 0x1024d2c */
  else {


    i = 0; /* Line 227, Address: 0x1024d34 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 228, Address: 0x1024d38 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x1024d5c */
  }

  if ((unsigned short)xWk > 160) { /* Line 232, Address: 0x1024d80 */
    xWk -= 160; /* Line 233, Address: 0x1024d94 */
  } /* Line 234, Address: 0x1024da0 */
  else {
    xWk = 0; /* Line 236, Address: 0x1024da8 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 240, Address: 0x1024dac */
    xWk = scralim_right; /* Line 241, Address: 0x1024dd0 */
  }
  scra_h_posit.w.h = xWk; /* Line 243, Address: 0x1024de0 */

  if ((unsigned short)yWk > 96) { /* Line 245, Address: 0x1024de8 */
    yWk -= 96; /* Line 246, Address: 0x1024dfc */
  } /* Line 247, Address: 0x1024e08 */
  else {
    yWk = 0; /* Line 249, Address: 0x1024e10 */
  }

  if (scralim_down < yWk) { /* Line 252, Address: 0x1024e14 */
    yWk = scralim_down; /* Line 253, Address: 0x1024e38 */
  }

  scra_v_posit.w.h = yWk; /* Line 256, Address: 0x1024e48 */

  scrbinit(yWk, xWk); /* Line 258, Address: 0x1024e50 */

  i = 0; /* Line 260, Address: 0x1024e60 */
  loopmapno = playmapnotbl[i++]; /* Line 261, Address: 0x1024e64 */
  loopmapno2 = playmapnotbl[i++]; /* Line 262, Address: 0x1024e7c */
  ballmapno = playmapnotbl[i++]; /* Line 263, Address: 0x1024e94 */
  ballmapno2 = playmapnotbl[i++]; /* Line 264, Address: 0x1024eac */


} /* Line 267, Address: 0x1024ec4 */



void scrbinit(short yWk, short xWk) { /* Line 271, Address: 0x1024ee0 */
  uint_union data;


  data.l = 0; /* Line 275, Address: 0x1024eec */
  data.w.h = yWk; /* Line 276, Address: 0x1024ef0 */
  data.l = (data.l >> 2) + (data.l >> 3); /* Line 277, Address: 0x1024ef8 */
  scrb_v_posit.l = data.w.l; /* Line 278, Address: 0x1024f10 */
  scrc_v_posit.w.h = data.w.h; /* Line 279, Address: 0x1024f20 */
  scrz_v_posit.w.h = data.w.h; /* Line 280, Address: 0x1024f2c */

  scrc_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 282, Address: 0x1024f38 */
  scrz_h_posit.w.h = (unsigned short)((xWk >> 2) + (xWk >> 3)); /* Line 283, Address: 0x1024f5c */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 284, Address: 0x1024f94 */
} /* Line 285, Address: 0x1024fc0 */



void scroll() { /* Line 289, Address: 0x1024fd0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 294, Address: 0x1024fe0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 297, Address: 0x1024ff0 */
  scrchk(); /* Line 298, Address: 0x102501c */
  scroll_h(); /* Line 299, Address: 0x1025024 */
  scroll_v(); /* Line 300, Address: 0x102502c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 302, Address: 0x1025034 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 303, Address: 0x1025044 */



  scrollz_h((scra_hz << 6) + (scra_hz << 5), 64); /* Line 307, Address: 0x1025054 */
  scrollc_h(scra_hz << 7, 16); /* Line 308, Address: 0x102508c */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 309, Address: 0x10250ac */

  data.l = 0; /* Line 311, Address: 0x10250e4 */
  data.w.l = scra_v_posit.w.h; /* Line 312, Address: 0x10250e8 */
  data.w.l = (data.w.l >> 2) + (data.w.l >> 3); /* Line 313, Address: 0x10250f4 */
  scrollb_v(data.w.l); /* Line 314, Address: 0x1025118 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 316, Address: 0x1025124 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 317, Address: 0x1025134 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x1025144 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 319, Address: 0x1025154 */
  scrflagz.b.h = 0; /* Line 320, Address: 0x1025188 */
  scrflagc.b.h = 0; /* Line 321, Address: 0x1025190 */

  hsCount = 0; /* Line 323, Address: 0x1025198 */


  hsCount = z71aline(hsCount); /* Line 326, Address: 0x102519c */

  for (i = 0; i < 4; ++i) { /* Line 328, Address: 0x10251ac */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 330, Address: 0x10251b8 */
    ++hsCount; /* Line 331, Address: 0x10251e8 */
  } /* Line 332, Address: 0x10251ec */

  hsCount = z71aline0(hsCount); /* Line 334, Address: 0x10251fc */

  for (i = 0; i < 12; ++i) { /* Line 336, Address: 0x102520c */

    hscrollwork[hsCount] = -scrc_h_posit.w.h; /* Line 338, Address: 0x1025218 */
    ++hsCount; /* Line 339, Address: 0x1025248 */
  } /* Line 340, Address: 0x102524c */





  data.w.l = scrb_v_posit.w.h; /* Line 346, Address: 0x102525c */
  data.w.l &= 1016; /* Line 347, Address: 0x1025268 */
  data.w.l >>= 2; /* Line 348, Address: 0x1025274 */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 349, Address: 0x1025280 */
} /* Line 350, Address: 0x10252b4 */



int z71aline(int hsCount) { /* Line 354, Address: 0x10252d0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[39] = { /* Line 358, Address: 0x10252e4 */
    1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
  };

  temp = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 366, Address: 0x1025310 */
  temp <<= 6; /* Line 367, Address: 0x1025334 */
  temp /= 39; /* Line 368, Address: 0x1025338 */
  temp <<= 10; /* Line 369, Address: 0x1025350 */
  data.l = 0; /* Line 370, Address: 0x1025354 */
  data.w.l = scrb_h_posit.w.h; /* Line 371, Address: 0x1025358 */
  hsCount += 46; /* Line 372, Address: 0x1025364 */
  for (i = 0; i < 39; ++i) { /* Line 373, Address: 0x1025370 */


    for (j = -1; j < z71ascrtbl[38 - i]; ++j) { /* Line 376, Address: 0x102537c */


      --hsCount; /* Line 379, Address: 0x1025388 */
      hscrollwork[hsCount] = -data.w.l; /* Line 380, Address: 0x1025394 */
    } /* Line 381, Address: 0x10253c4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 382, Address: 0x10253e8 */
    data.l += temp; /* Line 383, Address: 0x102540c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 384, Address: 0x1025418 */
  } /* Line 385, Address: 0x102543c */
  hsCount += 46; /* Line 386, Address: 0x102544c */
  return hsCount; /* Line 387, Address: 0x1025458 */
} /* Line 388, Address: 0x102545c */


int z71aline0(int hsCount) { /* Line 391, Address: 0x1025480 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[10] = { /* Line 395, Address: 0x1025494 */
    7, 3, 3, 5,
    3, 3, 0, 0,
    0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 401, Address: 0x10254c8 */
  temp <<= 6; /* Line 402, Address: 0x10254ec */
  temp /= 10; /* Line 403, Address: 0x10254f0 */
  temp <<= 10; /* Line 404, Address: 0x1025508 */
  data.l = 0; /* Line 405, Address: 0x102550c */
  data.w.l = scrb_h_posit.w.h; /* Line 406, Address: 0x1025510 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 407, Address: 0x102551c */
  data.l += temp; /* Line 408, Address: 0x1025540 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 409, Address: 0x102554c */
  for (i = 0; i < 10; ++i) { /* Line 410, Address: 0x1025570 */


    for (j = -1; j < z71ascrtbl0[9 - i]; ++j) { /* Line 413, Address: 0x102557c */


      hscrollwork[hsCount] = -data.w.l; /* Line 416, Address: 0x1025588 */
      ++hsCount; /* Line 417, Address: 0x10255b8 */
    } /* Line 418, Address: 0x10255c4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 419, Address: 0x10255e8 */
    data.l += temp; /* Line 420, Address: 0x102560c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 421, Address: 0x1025618 */
  } /* Line 422, Address: 0x102563c */
  return hsCount; /* Line 423, Address: 0x102564c */
} /* Line 424, Address: 0x1025650 */




void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 429, Address: 0x1025670 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 437, Address: 0x1025688 */








  VPosi &= 7; /* Line 446, Address: 0x1025690 */
  hsw.l = 0; /* Line 447, Address: 0x102569c */
  hsw.w.l = hscrollwork[offs++]; /* Line 448, Address: 0x10256a0 */

  j = VPosi; /* Line 450, Address: 0x10256c8 */
  while (j < 8) { /* Line 451, Address: 0x10256d4 */

    pHScrollBuff->l = hsw.l; /* Line 453, Address: 0x10256dc */
    ++pHScrollBuff; /* Line 454, Address: 0x10256e4 */
    ++j; /* Line 455, Address: 0x10256e8 */
  } /* Line 456, Address: 0x10256ec */
  for (i = 0; i < 29; ++i) { /* Line 457, Address: 0x10256f8 */

    hsw.w.l = hscrollwork[offs++]; /* Line 459, Address: 0x1025704 */
    for (j = 0; j < 8; ++j) { /* Line 460, Address: 0x102572c */

      pHScrollBuff->l = hsw.l; /* Line 462, Address: 0x1025738 */
      ++pHScrollBuff; /* Line 463, Address: 0x1025740 */
    } /* Line 464, Address: 0x1025744 */
  } /* Line 465, Address: 0x1025754 */
} /* Line 466, Address: 0x1025764 */











void scroll_h() { /* Line 478, Address: 0x1025780 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 481, Address: 0x102578c */
  scrh_move(); /* Line 482, Address: 0x1025798 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 483, Address: 0x10257a0 */
    scra_h_count ^= 16; /* Line 484, Address: 0x10257d4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 485, Address: 0x10257e8 */
      scrflaga.b.h |= 4; /* Line 486, Address: 0x1025814 */
    } /* Line 487, Address: 0x1025828 */
    else {

      scrflaga.b.h |= 8; /* Line 490, Address: 0x1025830 */
    }
  }


} /* Line 495, Address: 0x1025844 */

void scrh_move() { /* Line 497, Address: 0x1025860 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 500, Address: 0x102586c */
  wD0 -= scra_h_posit.w.h; /* Line 501, Address: 0x1025878 */
  wD0 -= scra_hline; /* Line 502, Address: 0x102588c */
  if (wD0 == 0) { /* Line 503, Address: 0x10258a0 */

    scra_hz = 0; /* Line 505, Address: 0x10258ac */
  } /* Line 506, Address: 0x10258b4 */
  else if ((short)wD0 < 0) { /* Line 507, Address: 0x10258bc */
    left_check(wD0); /* Line 508, Address: 0x10258d4 */
  } /* Line 509, Address: 0x10258e0 */
  else {
    right_check(wD0); /* Line 511, Address: 0x10258e8 */
  }

} /* Line 514, Address: 0x10258f4 */


void right_check(unsigned short wD0) { /* Line 517, Address: 0x1025910 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 520, Address: 0x102591c */
    wD0 = 16; /* Line 521, Address: 0x102593c */
  }

  wD0 += scra_h_posit.w.h; /* Line 524, Address: 0x1025944 */
  if (scralim_right < (short)wD0) { /* Line 525, Address: 0x102595c */
    wD0 = scralim_right; /* Line 526, Address: 0x102598c */
  }

  wD1 = wD0; /* Line 529, Address: 0x1025998 */
  wD1 -= scra_h_posit.w.h; /* Line 530, Address: 0x10259a0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 531, Address: 0x10259b4 */
  scra_h_posit.w.h = wD0; /* Line 532, Address: 0x10259e4 */
  scra_hz = wD1; /* Line 533, Address: 0x10259f0 */

} /* Line 535, Address: 0x10259f8 */


void left_check(unsigned short wD0) { /* Line 538, Address: 0x1025a10 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 541, Address: 0x1025a1c */
    wD0 = -16; /* Line 542, Address: 0x1025a3c */
  }

  wD0 += scra_h_posit.w.h; /* Line 545, Address: 0x1025a44 */
  if (scralim_left > (short)wD0) { /* Line 546, Address: 0x1025a5c */
    wD0 = scralim_left; /* Line 547, Address: 0x1025a8c */
  }

  wD1 = wD0; /* Line 550, Address: 0x1025a98 */
  wD1 -= scra_h_posit.w.h; /* Line 551, Address: 0x1025aa0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 552, Address: 0x1025ab4 */
  scra_h_posit.w.h = wD0; /* Line 553, Address: 0x1025ae4 */
  scra_hz = wD1; /* Line 554, Address: 0x1025af0 */

} /* Line 556, Address: 0x1025af8 */


















void scroll_v() { /* Line 575, Address: 0x1025b10 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 578, Address: 0x1025b1c */
  if (actwk[0].cddat & 4) { /* Line 579, Address: 0x1025b48 */
    wD0 -= 5; /* Line 580, Address: 0x1025b60 */
  }

  if (actwk[0].cddat & 2) { /* Line 583, Address: 0x1025b68 */
    wD0 += 32; /* Line 584, Address: 0x1025b80 */
    if ((unsigned short)scra_vline > wD0) { /* Line 585, Address: 0x1025b88 */
      wD0 -= scra_vline; /* Line 586, Address: 0x1025ba8 */
      sv_move_main2(wD0); /* Line 587, Address: 0x1025bbc */
      return; /* Line 588, Address: 0x1025bc8 */
    }
    wD0 -= scra_vline; /* Line 590, Address: 0x1025bd0 */
    if (wD0 >= 64) { /* Line 591, Address: 0x1025be4 */
      wD0 -= 64; /* Line 592, Address: 0x1025bf4 */
      sv_move_main2(wD0); /* Line 593, Address: 0x1025bfc */
      return; /* Line 594, Address: 0x1025c08 */
    }
    wD0 -= 64; /* Line 596, Address: 0x1025c10 */
    if (limmoveflag == 0) goto label1; /* Line 597, Address: 0x1025c18 */
    sv_move_sub2(); /* Line 598, Address: 0x1025c2c */
    return; /* Line 599, Address: 0x1025c34 */
  }




  wD0 -= scra_vline; /* Line 605, Address: 0x1025c3c */
  if (wD0) { /* Line 606, Address: 0x1025c50 */
    sv_move_main(wD0); /* Line 607, Address: 0x1025c58 */
    return; /* Line 608, Address: 0x1025c64 */
  }
  if (limmoveflag == 0) { /* Line 610, Address: 0x1025c6c */
    sv_move_sub2(); /* Line 611, Address: 0x1025c80 */
    return; /* Line 612, Address: 0x1025c88 */
  }


label1:
  scra_vz = 0; /* Line 617, Address: 0x1025c90 */

} /* Line 619, Address: 0x1025c98 */





void sv_move_main(unsigned short wD0) { /* Line 625, Address: 0x1025cb0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 628, Address: 0x1025cc0 */
    sv_move_main1(wD0); /* Line 629, Address: 0x1025cdc */
  } /* Line 630, Address: 0x1025ce8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 633, Address: 0x1025cf0 */
    if ((short)wD1 < 0) { /* Line 634, Address: 0x1025cfc */
      wD1 = -(short)wD1; /* Line 635, Address: 0x1025d14 */
    }

    if (wD1 >= 2048) { /* Line 638, Address: 0x1025d30 */
      sv_move_main2(wD0); /* Line 639, Address: 0x1025d40 */
    } /* Line 640, Address: 0x1025d4c */
    else {
      if ((short)wD0 > 6) { /* Line 642, Address: 0x1025d54 */
        sv_move_plus(1536); /* Line 643, Address: 0x1025d74 */
      } /* Line 644, Address: 0x1025d80 */
      else if ((short)wD0 < -6) { /* Line 645, Address: 0x1025d88 */
        sv_move_minus(1536); /* Line 646, Address: 0x1025da8 */
      } /* Line 647, Address: 0x1025db4 */
      else {
        sv_move_sub(wD0); /* Line 649, Address: 0x1025dbc */
      }
    }
  }
} /* Line 653, Address: 0x1025dc8 */



void sv_move_main1(unsigned short wD0) { /* Line 657, Address: 0x1025de0 */

  if ((short)wD0 > 2) { /* Line 659, Address: 0x1025dec */
    sv_move_plus(512); /* Line 660, Address: 0x1025e0c */
  } /* Line 661, Address: 0x1025e18 */
  else if ((short)wD0 < -2) { /* Line 662, Address: 0x1025e20 */
    sv_move_minus(512); /* Line 663, Address: 0x1025e40 */
  } /* Line 664, Address: 0x1025e4c */
  else {
    sv_move_sub(wD0); /* Line 666, Address: 0x1025e54 */
  }

} /* Line 669, Address: 0x1025e60 */


void sv_move_main2(unsigned short wD0) { /* Line 672, Address: 0x1025e70 */

  if ((short)wD0 > 16) { /* Line 674, Address: 0x1025e7c */
    sv_move_plus(4096); /* Line 675, Address: 0x1025e9c */
  } /* Line 676, Address: 0x1025ea8 */
  else if ((short)wD0 < -16) { /* Line 677, Address: 0x1025eb0 */
    sv_move_minus(4096); /* Line 678, Address: 0x1025ed0 */
  } /* Line 679, Address: 0x1025edc */
  else {
    sv_move_sub(wD0); /* Line 681, Address: 0x1025ee4 */
  }

} /* Line 684, Address: 0x1025ef0 */


void sv_move_sub2() { /* Line 687, Address: 0x1025f00 */
  limmoveflag = 0; /* Line 688, Address: 0x1025f08 */
  sv_move_sub(0); /* Line 689, Address: 0x1025f10 */
} /* Line 690, Address: 0x1025f1c */


void sv_move_sub(unsigned short wD0) { /* Line 693, Address: 0x1025f30 */
  int_union lD1;

  lD1.w.h = 0; /* Line 696, Address: 0x1025f3c */
  lD1.w.l = wD0; /* Line 697, Address: 0x1025f40 */
  lD1.l += scra_v_posit.w.h; /* Line 698, Address: 0x1025f48 */
  if ((short)wD0 > 0) { /* Line 699, Address: 0x1025f64 */
    scrv_down_ch(lD1); /* Line 700, Address: 0x1025f80 */
  } /* Line 701, Address: 0x1025f8c */
  else {
    scrv_up_ch(lD1); /* Line 703, Address: 0x1025f94 */
  }

} /* Line 706, Address: 0x1025fa0 */




void sv_move_minus(unsigned short wD1) { /* Line 711, Address: 0x1025fb0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 715, Address: 0x1025fc0 */
  lD1.l <<= 8; /* Line 716, Address: 0x1025fdc */
  lD1.l += scra_v_posit.l; /* Line 717, Address: 0x1025fe8 */

  wk = lD1.w.h; /* Line 719, Address: 0x1025ffc */
  lD1.w.h = lD1.w.l; /* Line 720, Address: 0x1026004 */
  lD1.w.l = wk; /* Line 721, Address: 0x102600c */
  scrv_up_ch(lD1); /* Line 722, Address: 0x1026010 */
} /* Line 723, Address: 0x102601c */



void scrv_up_ch(int_union lD1) { /* Line 727, Address: 0x1026030 */
  if (scralim_up >= lD1.w.l) { /* Line 728, Address: 0x102603c */
    if (lD1.w.l < -255) { /* Line 729, Address: 0x1026064 */
      lD1.w.l &= 2047; /* Line 730, Address: 0x102607c */
      actwk[0].yposi.w.h &= 2047; /* Line 731, Address: 0x1026088 */
      scra_v_posit.w.h &= 2047; /* Line 732, Address: 0x102609c */
      scrb_v_posit.w.h &= 1023; /* Line 733, Address: 0x10260b0 */
    } /* Line 734, Address: 0x10260c4 */
    else {

      lD1.w.l = scralim_up; /* Line 737, Address: 0x10260cc */
    }
  }
  scrv_move(lD1); /* Line 740, Address: 0x10260d8 */

} /* Line 742, Address: 0x10260e4 */





void sv_move_plus(unsigned short wD1) { /* Line 748, Address: 0x1026100 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 752, Address: 0x1026110 */
  lD1.w.l = wD1; /* Line 753, Address: 0x1026114 */
  lD1.l <<= 8; /* Line 754, Address: 0x102611c */
  lD1.l += scra_v_posit.l; /* Line 755, Address: 0x1026128 */

  wk = lD1.w.h; /* Line 757, Address: 0x102613c */
  lD1.w.h = lD1.w.l; /* Line 758, Address: 0x1026144 */
  lD1.w.l = wk; /* Line 759, Address: 0x102614c */

  scrv_down_ch(lD1); /* Line 761, Address: 0x1026150 */

} /* Line 763, Address: 0x102615c */



void scrv_down_ch(int_union lD1) { /* Line 767, Address: 0x1026170 */
  if (scralim_down <= lD1.w.l) { /* Line 768, Address: 0x102617c */
    lD1.w.l -= 2048; /* Line 769, Address: 0x10261a4 */
    if (lD1.w.l > 0) { /* Line 770, Address: 0x10261b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 771, Address: 0x10261c4 */
      scra_v_posit.w.h -= 2048; /* Line 772, Address: 0x10261d8 */
      scrb_v_posit.w.h &= 1023; /* Line 773, Address: 0x10261ec */
    } /* Line 774, Address: 0x1026200 */
    else {
      lD1.w.l = scralim_down; /* Line 776, Address: 0x1026208 */
    }
  }
  scrv_move(lD1); /* Line 779, Address: 0x1026214 */

} /* Line 781, Address: 0x1026220 */


void scrv_move(int_union lD1) { /* Line 784, Address: 0x1026230 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 787, Address: 0x1026240 */

  wk = lD1.w.h; /* Line 789, Address: 0x102624c */
  lD1.w.h = lD1.w.l; /* Line 790, Address: 0x1026254 */
  lD1.w.l = wk; /* Line 791, Address: 0x102625c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 793, Address: 0x1026260 */
  scra_v_posit.l = lD1.l; /* Line 794, Address: 0x1026288 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 797, Address: 0x1026294 */
    scra_v_count ^= 16; /* Line 798, Address: 0x10262c8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 799, Address: 0x10262dc */

      scrflaga.b.h |= 2; /* Line 801, Address: 0x1026308 */
    } /* Line 802, Address: 0x102631c */
    else {
      scrflaga.b.h |= 1; /* Line 804, Address: 0x1026324 */
    }
  }


} /* Line 809, Address: 0x1026338 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 813, Address: 0x1026350 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 816, Address: 0x102635c */
  lD0.l += lD4.l; /* Line 817, Address: 0x102636c */
  scrb_h_posit.l = lD0.l; /* Line 818, Address: 0x102637c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 820, Address: 0x1026388 */

    scrb_h_count ^= 16; /* Line 822, Address: 0x10263bc */
    lD0.l -= lD2.l; /* Line 823, Address: 0x10263d0 */
    if ((long int)lD0.l < 0) { /* Line 824, Address: 0x10263e0 */
      scrflagb.b.h |= 4; /* Line 825, Address: 0x10263f4 */
    } /* Line 826, Address: 0x1026408 */
    else {

      scrflagb.b.h |= 8; /* Line 829, Address: 0x1026410 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 834, Address: 0x1026424 */
  lD0.l += lD5.l; /* Line 835, Address: 0x1026434 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 836, Address: 0x1026444 */
  scrb_v_posit.l = lD0.l; /* Line 837, Address: 0x102645c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 839, Address: 0x1026468 */

    scrb_v_count ^= 16; /* Line 841, Address: 0x102649c */
    lD0.l -= lD3.l; /* Line 842, Address: 0x10264b0 */
    if ((long int)lD0.l < 0) { /* Line 843, Address: 0x10264c0 */
      scrflagb.b.h |= 1; /* Line 844, Address: 0x10264d4 */
    } /* Line 845, Address: 0x10264e8 */
    else {

      scrflagb.b.h |= 2; /* Line 848, Address: 0x10264f0 */
    }
  }


} /* Line 853, Address: 0x1026504 */






void scrollb_v(unsigned short wD0) { /* Line 860, Address: 0x1026510 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 863, Address: 0x102651c */
  scrb_v_posit.w.h = wD0; /* Line 864, Address: 0x1026528 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 866, Address: 0x1026534 */
    scrb_v_count ^= 16; /* Line 867, Address: 0x1026560 */
    if ((short)wD3 > (short)wD0) { /* Line 868, Address: 0x1026574 */
      scrflagb.b.h |= 1; /* Line 869, Address: 0x10265a4 */
    } /* Line 870, Address: 0x10265b8 */
    else {

      scrflagb.b.h |= 2; /* Line 873, Address: 0x10265c0 */
    }
  }


} /* Line 878, Address: 0x10265d4 */



void scrollb_h(int lD4, int flagb) { /* Line 882, Address: 0x10265f0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 886, Address: 0x1026600 */
  lD0.l = lD2.l + lD4; /* Line 887, Address: 0x102660c */
  scrb_h_posit.l = lD0.l; /* Line 888, Address: 0x102661c */

  lD1.w.h = lD0.w.l; /* Line 890, Address: 0x1026628 */
  lD1.w.l = lD0.w.h; /* Line 891, Address: 0x1026630 */
  lD1.w.l &= 16; /* Line 892, Address: 0x1026638 */

  bD3 = scrb_h_count; /* Line 894, Address: 0x1026644 */
  lD1.b.b4 ^= bD3; /* Line 895, Address: 0x1026650 */
  if (!lD1.b.b4) { /* Line 896, Address: 0x1026664 */
    scrb_h_count ^= 16; /* Line 897, Address: 0x1026670 */
    lD0.l -= lD2.l; /* Line 898, Address: 0x1026684 */
    if ((long int)lD0.l < 0) { /* Line 899, Address: 0x1026694 */
      scrflagb.b.h |= flagb; /* Line 900, Address: 0x10266a8 */
    } /* Line 901, Address: 0x10266c4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 904, Address: 0x10266cc */
    }
  }


} /* Line 909, Address: 0x10266ec */


void scrollc_h(int lD4, int flagc) { /* Line 912, Address: 0x1026700 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 916, Address: 0x1026710 */
  lD0.l = lD2.l + lD4; /* Line 917, Address: 0x102671c */
  scrc_h_posit.l = lD0.l; /* Line 918, Address: 0x102672c */

  lD1.w.h = lD0.w.l; /* Line 920, Address: 0x1026738 */
  lD1.w.l = lD0.w.h; /* Line 921, Address: 0x1026740 */
  lD1.w.l &= 16; /* Line 922, Address: 0x1026748 */

  bD3 = scrc_h_count; /* Line 924, Address: 0x1026754 */
  lD1.b.b4 ^= bD3; /* Line 925, Address: 0x1026760 */
  if (!lD1.b.b4) { /* Line 926, Address: 0x1026774 */
    scrc_h_count ^= 16; /* Line 927, Address: 0x1026780 */
    lD0.l -= lD2.l; /* Line 928, Address: 0x1026794 */
    if ((long int)lD0.l < 0) { /* Line 929, Address: 0x10267a4 */
      scrflagc.b.h |= flagc; /* Line 930, Address: 0x10267b8 */
    } /* Line 931, Address: 0x10267d4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 934, Address: 0x10267dc */
    }
  }


} /* Line 939, Address: 0x10267fc */











void scrollz_h(int lD4, int flagz) { /* Line 951, Address: 0x1026810 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 955, Address: 0x1026820 */
  lD0.l = lD2.l + lD4; /* Line 956, Address: 0x102682c */
  scrz_h_posit.l = lD0.l; /* Line 957, Address: 0x102683c */

  lD1.w.h = lD0.w.l; /* Line 959, Address: 0x1026848 */
  lD1.w.l = lD0.w.h; /* Line 960, Address: 0x1026850 */
  lD1.w.l &= 16; /* Line 961, Address: 0x1026858 */

  bD3 = scrz_h_count; /* Line 963, Address: 0x1026864 */
  lD1.b.b4 ^= bD3; /* Line 964, Address: 0x1026870 */
  if (!lD1.b.b4) { /* Line 965, Address: 0x1026884 */
    scrz_h_count ^= 16; /* Line 966, Address: 0x1026890 */
    lD0.l -= lD2.l; /* Line 967, Address: 0x10268a4 */
    if ((long int)lD0.l < 0) { /* Line 968, Address: 0x10268b4 */
      scrflagz.b.h |= flagz; /* Line 969, Address: 0x10268c8 */
    } /* Line 970, Address: 0x10268e4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 973, Address: 0x10268ec */
    }
  }


} /* Line 978, Address: 0x102690c */













void scrollwrtadva() { /* Line 992, Address: 0x1026920 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 998, Address: 0x102693c */
  wH_posiw = scrb_h_posit.w.h; /* Line 999, Address: 0x1026940 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1000, Address: 0x102694c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1001, Address: 0x1026958 */
  pScrFlag = &scrflagb.b.h; /* Line 1002, Address: 0x1026960 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1003, Address: 0x1026968 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1005, Address: 0x102697c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1006, Address: 0x1026988 */
  pScrFlag = &scrflagc.b.h; /* Line 1007, Address: 0x1026994 */
  scrollwrtc(); /* Line 1008, Address: 0x102699c */

} /* Line 1010, Address: 0x10269a4 */












void scrollwrt() { /* Line 1023, Address: 0x10269d0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1032, Address: 0x10269f0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1033, Address: 0x10269f4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1034, Address: 0x1026a00 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1035, Address: 0x1026a0c */
  pScrFlag = &scrflagbw.b.h; /* Line 1036, Address: 0x1026a14 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1037, Address: 0x1026a1c */

  VramBase = 16384; /* Line 1039, Address: 0x1026a30 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1040, Address: 0x1026a34 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1041, Address: 0x1026a40 */
  pMapWk = (unsigned char*)mapwka; /* Line 1042, Address: 0x1026a4c */
  pScrFlag = &scrflagaw.b.h; /* Line 1043, Address: 0x1026a54 */

  if (*pScrFlag) { /* Line 1045, Address: 0x1026a5c */
    if (*pScrFlag & 1) { /* Line 1046, Address: 0x1026a68 */
      *pScrFlag &= 254; /* Line 1047, Address: 0x1026a7c */

      lD4.l = -16; /* Line 1049, Address: 0x1026a88 */
      wD5 = 65520; /* Line 1050, Address: 0x1026a90 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1052, Address: 0x1026a98 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1054, Address: 0x1026ab8 */
    }




    if (*pScrFlag & 2) { /* Line 1060, Address: 0x1026ae4 */
      *pScrFlag &= 253; /* Line 1061, Address: 0x1026af8 */

      lD4.l = 224; /* Line 1063, Address: 0x1026b04 */
      wD5 = 65520; /* Line 1064, Address: 0x1026b0c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1065, Address: 0x1026b14 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1067, Address: 0x1026b34 */
    }




    if (*pScrFlag & 4) { /* Line 1073, Address: 0x1026b60 */
      *pScrFlag &= 251; /* Line 1074, Address: 0x1026b74 */

      lD4.l = -16; /* Line 1076, Address: 0x1026b80 */
      wD5 = 65520; /* Line 1077, Address: 0x1026b88 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1078, Address: 0x1026b90 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1080, Address: 0x1026bb0 */
    }




    if (*pScrFlag & 8) { /* Line 1086, Address: 0x1026bdc */
      *pScrFlag &= 247; /* Line 1087, Address: 0x1026bf0 */

      lD4.l = -16; /* Line 1089, Address: 0x1026bfc */
      wD5 = 320; /* Line 1090, Address: 0x1026c04 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1091, Address: 0x1026c0c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1093, Address: 0x1026c2c */
    }
  }






} /* Line 1102, Address: 0x1026c58 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1119, Address: 0x1026c80 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1130, Address: 0x1026cac */

  if (*pScrFlag & 1) { /* Line 1132, Address: 0x1026cb4 */
    *pScrFlag &= 254; /* Line 1133, Address: 0x1026ccc */
  } /* Line 1134, Address: 0x1026ce0 */
  else {
    *pScrFlag &= 254; /* Line 1136, Address: 0x1026ce8 */

    if (*pScrFlag & 2) { /* Line 1138, Address: 0x1026cfc */
      *pScrFlag &= 253; /* Line 1139, Address: 0x1026d14 */
      lD4.w.l = 224; /* Line 1140, Address: 0x1026d28 */
    } /* Line 1141, Address: 0x1026d30 */
    else {
      *pScrFlag &= 253; /* Line 1143, Address: 0x1026d38 */
      goto label1; /* Line 1144, Address: 0x1026d4c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1149, Address: 0x1026d54 */
  wD0 &= 127; /* Line 1150, Address: 0x1026da4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1151, Address: 0x1026dac */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1157, Address: 0x1026dcc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1158, Address: 0x1026dec */
  if (wD0 != 0) { /* Line 1159, Address: 0x1026e10 */
    wD5 = 65520; /* Line 1160, Address: 0x1026e1c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1161, Address: 0x1026e24 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1163, Address: 0x1026e44 */



  } /* Line 1167, Address: 0x1026e70 */
  else {

    wD5 = 0; /* Line 1170, Address: 0x1026e78 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1171, Address: 0x1026e7c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1175, Address: 0x1026e9c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1182, Address: 0x1026ec8 */






    lD4.l = -16; /* Line 1189, Address: 0x1026edc */
    wD5 = 65520; /* Line 1190, Address: 0x1026ee4 */
    if (*pScrFlag & 168) { /* Line 1191, Address: 0x1026eec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1192, Address: 0x1026f04 */
      wD5 = 320; /* Line 1193, Address: 0x1026f24 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1197, Address: 0x1026f2c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1199, Address: 0x1026f5c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1200, Address: 0x1026f68 */



    for (i = 0; i < 16; ++i) { /* Line 1204, Address: 0x1026f78 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1205, Address: 0x1026f84 */
      if (wD0 != 0) { /* Line 1206, Address: 0x1026fa4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1207, Address: 0x1026fb0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1208, Address: 0x1026fdc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1209, Address: 0x1026ffc */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1211, Address: 0x1027020 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1214, Address: 0x1027044 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1216, Address: 0x1027064 */
        }
      }
      lD4.w.l += 16; /* Line 1219, Address: 0x1027078 */
    } /* Line 1220, Address: 0x1027084 */
    *pScrFlag = 0; /* Line 1221, Address: 0x1027094 */
  }
} /* Line 1223, Address: 0x102709c */





void scrollwrtc() {} /* Line 1229, Address: 0x10270d0 */




void scrollwrtz() {} /* Line 1234, Address: 0x10270e0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1252, Address: 0x10270f0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1265, Address: 0x1027118 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1268, Address: 0x1027138 */
    pTilePoint->x += 2; /* Line 1269, Address: 0x102714c */
    if (pTilePoint->x >= 64) { /* Line 1270, Address: 0x1027160 */
      pTilePoint->x -= 64; /* Line 1271, Address: 0x1027174 */
    }
    xOffs += 16; /* Line 1273, Address: 0x1027188 */
  } while (--lpcnt >= 0); /* Line 1274, Address: 0x1027194 */
} /* Line 1275, Address: 0x10271a8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1279, Address: 0x10271c0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1283, Address: 0x10271e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1286, Address: 0x1027208 */
    pTilePoint->x += 2; /* Line 1287, Address: 0x102721c */
    if (pTilePoint->x >= 64) { /* Line 1288, Address: 0x1027230 */
      pTilePoint->x -= 64; /* Line 1289, Address: 0x1027244 */
    }
    xOffs += 16; /* Line 1291, Address: 0x1027258 */
  } while (--lpcnt >= 0); /* Line 1292, Address: 0x1027264 */
} /* Line 1293, Address: 0x1027278 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1313, Address: 0x1027290 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1317, Address: 0x10272b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1320, Address: 0x10272d8 */
    pTilePoint->y += 2; /* Line 1321, Address: 0x10272ec */
    if (pTilePoint->y >= 32) { /* Line 1322, Address: 0x10272fc */
      pTilePoint->y -= 32; /* Line 1323, Address: 0x1027310 */
    }
    yOffs += 16; /* Line 1325, Address: 0x1027320 */
  } while (--lpcnt >= 0); /* Line 1326, Address: 0x102732c */
} /* Line 1327, Address: 0x1027340 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1346, Address: 0x1027350 */
  int base = 0; /* Line 1347, Address: 0x1027384 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1352, Address: 0x1027388 */

    base = 1; /* Line 1354, Address: 0x1027398 */
  } /* Line 1355, Address: 0x102739c */
  else if (VramBase == 16384) { /* Line 1356, Address: 0x10273a4 */

    base = 0; /* Line 1358, Address: 0x10273b4 */
  }
  x = pTilePoint->x; /* Line 1360, Address: 0x10273b8 */
  y = pTilePoint->y; /* Line 1361, Address: 0x10273c0 */


  frip = BlkIndex & 6144; /* Line 1364, Address: 0x10273c8 */
  BlkIndex &= 1023; /* Line 1365, Address: 0x10273d0 */
  if (frip == 6144) { /* Line 1366, Address: 0x10273dc */

    p0 = 3, p1 = 2; /* Line 1368, Address: 0x10273e8 */
    p2 = 1, p3 = 0; /* Line 1369, Address: 0x10273f0 */
  } /* Line 1370, Address: 0x10273f8 */
  else if (frip & 4096) { /* Line 1371, Address: 0x1027400 */

    p0 = 2, p1 = 3; /* Line 1373, Address: 0x102740c */
    p2 = 0, p3 = 1; /* Line 1374, Address: 0x1027414 */
  } /* Line 1375, Address: 0x102741c */
  else if (frip & 2048) { /* Line 1376, Address: 0x1027424 */

    p0 = 1, p1 = 0; /* Line 1378, Address: 0x1027430 */
    p2 = 3, p3 = 2; /* Line 1379, Address: 0x1027438 */
  } /* Line 1380, Address: 0x1027440 */
  else {

    p0 = 0, p1 = 1; /* Line 1383, Address: 0x1027448 */
    p2 = 2, p3 = 3; /* Line 1384, Address: 0x1027450 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1387, Address: 0x1027458 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1388, Address: 0x102749c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1389, Address: 0x10274e0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1390, Address: 0x1027524 */

} /* Line 1392, Address: 0x1027568 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1410, Address: 0x10275a0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1411, Address: 0x10275c0 */
} /* Line 1412, Address: 0x10275e0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1414, Address: 0x10275f0 */
  wH_posiw = 0; /* Line 1415, Address: 0x1027610 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1416, Address: 0x1027614 */
} /* Line 1417, Address: 0x1027634 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1424, Address: 0x1027650 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1430, Address: 0x1027680 */
  yOffs += wV_posiw; /* Line 1431, Address: 0x1027690 */





  if ((short)xOffs < 0) /* Line 1437, Address: 0x10276a0 */
    xOffs = 0; /* Line 1438, Address: 0x10276bc */
  if ((short)yOffs < 0) /* Line 1439, Address: 0x10276c0 */
    yOffs = 0; /* Line 1440, Address: 0x10276dc */
  if ((short)xOffs >= 16384) /* Line 1441, Address: 0x10276e0 */
    xOffs = 16383; /* Line 1442, Address: 0x1027700 */
  if ((short)yOffs >= 2048) /* Line 1443, Address: 0x1027708 */
    yOffs = 2047; /* Line 1444, Address: 0x1027728 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1445, Address: 0x1027730 */
  if (i < 0) i = 0; /* Line 1446, Address: 0x1027778 */

  ScreenNo = pMapWk[i] & 127; /* Line 1448, Address: 0x1027784 */

  if (ScreenNo) { /* Line 1450, Address: 0x10277a0 */




    xOffs &= 32767; /* Line 1455, Address: 0x10277a8 */
    yOffs &= 32767; /* Line 1456, Address: 0x10277b4 */


    xBlk = xOffs; /* Line 1459, Address: 0x10277c0 */
    xBlk %= 256; /* Line 1460, Address: 0x10277c8 */
    xBlk /= 16; /* Line 1461, Address: 0x10277e8 */
    yBlk = yOffs; /* Line 1462, Address: 0x1027804 */
    yBlk %= 256; /* Line 1463, Address: 0x102780c */
    yBlk /= 16; /* Line 1464, Address: 0x102782c */

    lpw = pmapwk; /* Line 1466, Address: 0x1027848 */
    lpw += xBlk; /* Line 1467, Address: 0x1027850 */
    lpw += yBlk * 16; /* Line 1468, Address: 0x1027858 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1469, Address: 0x1027864 */
    *pIndex = *lpw; /* Line 1470, Address: 0x102787c */

    return 1; /* Line 1472, Address: 0x102788c */
  }

  *pIndex = 0; /* Line 1475, Address: 0x1027898 */
  return 0; /* Line 1476, Address: 0x10278a0 */
} /* Line 1477, Address: 0x10278a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1497, Address: 0x10278d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1505, Address: 0x10278f8 */
  if (ScreenNo) { /* Line 1506, Address: 0x102795c */





    xBlk = xOffs; /* Line 1512, Address: 0x1027964 */
    xBlk %= 256; /* Line 1513, Address: 0x102796c */
    xBlk /= 16; /* Line 1514, Address: 0x102798c */
    yBlk = yOffs; /* Line 1515, Address: 0x10279a8 */
    yBlk %= 256; /* Line 1516, Address: 0x10279b0 */
    yBlk /= 16; /* Line 1517, Address: 0x10279d0 */


    lpw = pmapwk; /* Line 1520, Address: 0x10279ec */
    lpw += xBlk; /* Line 1521, Address: 0x10279f4 */
    lpw += yBlk * 16; /* Line 1522, Address: 0x10279fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1523, Address: 0x1027a08 */
    *ppBlockNo = lpw; /* Line 1524, Address: 0x1027a20 */
    *pIndex = *lpw; /* Line 1525, Address: 0x1027a28 */




    return 1; /* Line 1530, Address: 0x1027a38 */
  }

  *pIndex = 0; /* Line 1533, Address: 0x1027a44 */
  return 0; /* Line 1534, Address: 0x1027a4c */
} /* Line 1535, Address: 0x1027a50 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1549, Address: 0x1027a70 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1556, Address: 0x1027a8c */
  pMapWk = (unsigned char*)mapwka; /* Line 1557, Address: 0x1027a90 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1558, Address: 0x1027a98 */
    *pBlockIndex = BlockNo; /* Line 1559, Address: 0x1027abc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1560, Address: 0x1027ac8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1561, Address: 0x1027ae0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1562, Address: 0x1027af4 */
    }
  }


} /* Line 1567, Address: 0x1027b0c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1581, Address: 0x1027b30 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1582, Address: 0x1027b3c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1583, Address: 0x1027b68 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1584, Address: 0x1027bb4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1585, Address: 0x1027be0 */

          return 0; /* Line 1587, Address: 0x1027c2c */
        }
      }
    }
  }

  return 1; /* Line 1593, Address: 0x1027c38 */
} /* Line 1594, Address: 0x1027c3c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1611, Address: 0x1027c50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1612, Address: 0x1027c6c */

} /* Line 1614, Address: 0x1027c88 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1616, Address: 0x1027ca0 */
  wH_posiw = 0; /* Line 1617, Address: 0x1027cbc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1618, Address: 0x1027cc0 */

} /* Line 1620, Address: 0x1027cdc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1622, Address: 0x1027cf0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1623, Address: 0x1027d04 */

} /* Line 1625, Address: 0x1027d20 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1627, Address: 0x1027d30 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1628, Address: 0x1027d4c */

} /* Line 1630, Address: 0x1027d68 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1632, Address: 0x1027d80 */
  xOffs += wH_posiw; /* Line 1633, Address: 0x1027d98 */
  yOffs += wV_posiw; /* Line 1634, Address: 0x1027da8 */
  yOffs &= 240; /* Line 1635, Address: 0x1027db8 */
  xOffs &= 496; /* Line 1636, Address: 0x1027dc4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1638, Address: 0x1027dd0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1639, Address: 0x1027dfc */


} /* Line 1642, Address: 0x1027e28 */















void mapwrt() { /* Line 1658, Address: 0x1027e40 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1663, Address: 0x1027e58 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1664, Address: 0x1027e64 */
  pMapWk = (unsigned char*)mapwka; /* Line 1665, Address: 0x1027e70 */
  VramBase = 16384; /* Line 1666, Address: 0x1027e78 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1667, Address: 0x1027e7c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1671, Address: 0x1027e94 */
  VramBase = 24576; /* Line 1672, Address: 0x1027e9c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1673, Address: 0x1027ea0 */

} /* Line 1675, Address: 0x1027eb0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1678, Address: 0x1027ed0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1679, Address: 0x1027ee8 */
} /* Line 1680, Address: 0x1027f08 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1685, Address: 0x1027f20 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1689, Address: 0x1027f40 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1692, Address: 0x1027f5c */



    wD4 += 16; /* Line 1696, Address: 0x1027f84 */
  } while ((short)--wD6 >= 0); /* Line 1697, Address: 0x1027f90 */

} /* Line 1699, Address: 0x1027fb8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1705, Address: 0x1027fd0 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1710, Address: 0x1027fec */
  wD6 = 15; /* Line 1711, Address: 0x1027ff4 */

  do {
    temp.l = 0; /* Line 1714, Address: 0x1027ffc */
    temp.w.l = scrb_v_posit.w.h; /* Line 1715, Address: 0x1028000 */
    wD0 = scrb_v_posit.w.h; /* Line 1716, Address: 0x102800c */
    wD0 += wD4 & 496; /* Line 1717, Address: 0x1028018 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1718, Address: 0x102802c */
    wD4 += 16; /* Line 1719, Address: 0x102804c */
  } while ((short)--wD6 >= 0); /* Line 1720, Address: 0x1028054 */
} /* Line 1721, Address: 0x1028078 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1743, Address: 0x10280a0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1748, Address: 0x10280c8 */
  wD0 = pWrttbl[wD0]; /* Line 1749, Address: 0x10280d8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1751, Address: 0x10280f4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1752, Address: 0x1028118 */
  if (wD0) { /* Line 1753, Address: 0x1028140 */
    wD5 = 65520; /* Line 1754, Address: 0x102814c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1755, Address: 0x1028154 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1758, Address: 0x1028170 */



  } /* Line 1762, Address: 0x1028198 */
  else {

    wD5 = 0; /* Line 1765, Address: 0x10281a0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1766, Address: 0x10281a4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1770, Address: 0x10281c0 */
  }





} /* Line 1777, Address: 0x10281e8 */



void mapinit() { /* Line 1781, Address: 0x1028210 */

  colorset2(mapinittbl.colorno2); /* Line 1783, Address: 0x1028218 */
  colorset(mapinittbl.colorno2); /* Line 1784, Address: 0x102822c */


  if (play_start & 2) divdevset(); /* Line 1787, Address: 0x1028240 */
} /* Line 1788, Address: 0x1028260 */










void mapset() {} /* Line 1799, Address: 0x1028270 */
