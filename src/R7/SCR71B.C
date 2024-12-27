#include "..\EQU.H"
#include "SCR71A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL7A.H"

static int z71aline(int hsCount);
static int z71aline0(int hsCount);
static void zonescrsetsub0(short VPosi, unsigned short offs);

static unsigned char z81awrttbl[65] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0
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
unsigned short scr_dir_tbl[6] = { 4, 0, 11927, 0, 1296, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 124, Address: 0x1024a50 */



void divdevset() {} /* Line 128, Address: 0x1024a60 */
















































void scr_set() { /* Line 177, Address: 0x1024a70 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 180, Address: 0x1024a7c */

  i = 0; /* Line 182, Address: 0x1024ac4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 183, Address: 0x1024ac8 */
  scralim_left = scr_dir_tbl[i]; /* Line 184, Address: 0x1024aec */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 185, Address: 0x1024b08 */
  scralim_right = scr_dir_tbl[i]; /* Line 186, Address: 0x1024b2c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 187, Address: 0x1024b48 */
  scralim_up = scr_dir_tbl[i]; /* Line 188, Address: 0x1024b6c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 189, Address: 0x1024b88 */
  scralim_down = scr_dir_tbl[i]; /* Line 190, Address: 0x1024bac */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 191, Address: 0x1024bc8 */

  scra_h_keep = scralim_left + 576; /* Line 193, Address: 0x1024bec */
  scra_h_count = 16; /* Line 194, Address: 0x1024c10 */
  scra_v_count = 16; /* Line 195, Address: 0x1024c1c */

  scra_vline = scr_dir_tbl[i++]; /* Line 197, Address: 0x1024c28 */
  scra_hline = 160; /* Line 198, Address: 0x1024c4c */

  playposiset(); /* Line 200, Address: 0x1024c58 */
} /* Line 201, Address: 0x1024c60 */



void playposiset() { /* Line 205, Address: 0x1024c80 */
  unsigned short playpositbl[2] = { /* Line 206, Address: 0x1024c94 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 210, Address: 0x1024cb0 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 218, Address: 0x1024cdc */

    playload(); /* Line 220, Address: 0x1024cf0 */
    xWk = actwk[0].xposi.w.h; /* Line 221, Address: 0x1024cf8 */
    yWk = actwk[0].yposi.w.h; /* Line 222, Address: 0x1024d08 */
    if (yWk < 0) yWk = 0; /* Line 223, Address: 0x1024d18 */
  } /* Line 224, Address: 0x1024d2c */
  else {


    i = 0; /* Line 228, Address: 0x1024d34 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x1024d38 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 230, Address: 0x1024d5c */
  }

  if ((unsigned short)xWk > 160) { /* Line 233, Address: 0x1024d80 */
    xWk -= 160; /* Line 234, Address: 0x1024d94 */
  } /* Line 235, Address: 0x1024da0 */
  else {
    xWk = 0; /* Line 237, Address: 0x1024da8 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 241, Address: 0x1024dac */
    xWk = scralim_right; /* Line 242, Address: 0x1024dd0 */
  }
  scra_h_posit.w.h = xWk; /* Line 244, Address: 0x1024de0 */

  if ((unsigned short)yWk > 96) { /* Line 246, Address: 0x1024de8 */
    yWk -= 96; /* Line 247, Address: 0x1024dfc */
  } /* Line 248, Address: 0x1024e08 */
  else {
    yWk = 0; /* Line 250, Address: 0x1024e10 */
  }

  if (scralim_down < yWk) { /* Line 253, Address: 0x1024e14 */
    yWk = scralim_down; /* Line 254, Address: 0x1024e38 */
  }

  scra_v_posit.w.h = yWk; /* Line 257, Address: 0x1024e48 */

  scrbinit(yWk, xWk); /* Line 259, Address: 0x1024e50 */

  i = 0; /* Line 261, Address: 0x1024e60 */
  loopmapno = playmapnotbl[i++]; /* Line 262, Address: 0x1024e64 */
  loopmapno2 = playmapnotbl[i++]; /* Line 263, Address: 0x1024e7c */
  ballmapno = playmapnotbl[i++]; /* Line 264, Address: 0x1024e94 */
  ballmapno2 = playmapnotbl[i++]; /* Line 265, Address: 0x1024eac */


} /* Line 268, Address: 0x1024ec4 */



void scrbinit(short yWk, short xWk) { /* Line 272, Address: 0x1024ee0 */
  uint_union data;


  data.l = 0; /* Line 276, Address: 0x1024eec */
  data.w.h = yWk; /* Line 277, Address: 0x1024ef0 */
  data.l = (data.l >> 2) + (data.l >> 3); /* Line 278, Address: 0x1024ef8 */
  scrb_v_posit.l = data.w.l; /* Line 279, Address: 0x1024f10 */
  scrc_v_posit.w.h = data.w.h; /* Line 280, Address: 0x1024f20 */
  scrz_v_posit.w.h = data.w.h; /* Line 281, Address: 0x1024f2c */

  scrc_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 283, Address: 0x1024f38 */
  scrz_h_posit.w.h = (unsigned short)((xWk >> 2) + (xWk >> 3)); /* Line 284, Address: 0x1024f5c */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 285, Address: 0x1024f94 */
} /* Line 286, Address: 0x1024fc0 */



void scroll() { /* Line 290, Address: 0x1024fd0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 295, Address: 0x1024fe0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 298, Address: 0x1024ff0 */
  scrchk(); /* Line 299, Address: 0x102501c */
  scroll_h(); /* Line 300, Address: 0x1025024 */
  scroll_v(); /* Line 301, Address: 0x102502c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 303, Address: 0x1025034 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 304, Address: 0x1025044 */



  scrollz_h((scra_hz << 6) + (scra_hz << 5), 64); /* Line 308, Address: 0x1025054 */
  scrollc_h(scra_hz << 7, 16); /* Line 309, Address: 0x102508c */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 310, Address: 0x10250ac */

  data.l = 0; /* Line 312, Address: 0x10250e4 */
  data.w.l = scra_v_posit.w.h; /* Line 313, Address: 0x10250e8 */
  data.w.l = (data.w.l >> 2) + (data.w.l >> 3); /* Line 314, Address: 0x10250f4 */
  scrollb_v(data.w.l); /* Line 315, Address: 0x1025118 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 317, Address: 0x1025124 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x1025134 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 319, Address: 0x1025144 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 320, Address: 0x1025154 */
  scrflagz.b.h = 0; /* Line 321, Address: 0x1025188 */
  scrflagc.b.h = 0; /* Line 322, Address: 0x1025190 */

  hsCount = 0; /* Line 324, Address: 0x1025198 */


  hsCount = z71aline(hsCount); /* Line 327, Address: 0x102519c */

  for (i = 0; i < 4; ++i) { /* Line 329, Address: 0x10251ac */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 331, Address: 0x10251b8 */
    ++hsCount; /* Line 332, Address: 0x10251e8 */
  } /* Line 333, Address: 0x10251ec */

  hsCount = z71aline0(hsCount); /* Line 335, Address: 0x10251fc */

  for (i = 0; i < 20; ++i) { /* Line 337, Address: 0x102520c */

    hscrollwork[hsCount] = -scrz_h_posit.w.h; /* Line 339, Address: 0x1025218 */
    ++hsCount; /* Line 340, Address: 0x1025248 */
  } /* Line 341, Address: 0x102524c */





  data.w.l = scrb_v_posit.w.h; /* Line 347, Address: 0x102525c */
  data.w.l &= 1016; /* Line 348, Address: 0x1025268 */
  data.w.l >>= 2; /* Line 349, Address: 0x1025274 */
  waterdirec.w += 128; /* Line 350, Address: 0x1025280 */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 351, Address: 0x1025294 */
} /* Line 352, Address: 0x10252c8 */



int z71aline(int hsCount) { /* Line 356, Address: 0x10252e0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[37] = { /* Line 360, Address: 0x10252f4 */
    1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
  };

  temp = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 368, Address: 0x1025320 */
  temp <<= 7; /* Line 369, Address: 0x1025344 */
  temp /= 37; /* Line 370, Address: 0x1025348 */
  temp <<= 9; /* Line 371, Address: 0x1025360 */
  data.l = 0; /* Line 372, Address: 0x1025364 */
  data.w.l = scrb_h_posit.w.h; /* Line 373, Address: 0x1025368 */
  hsCount += 44; /* Line 374, Address: 0x1025374 */
  for (i = 0; i < 37; ++i) { /* Line 375, Address: 0x1025380 */


    for (j = -1; j < z71ascrtbl[36 - i]; ++j) { /* Line 378, Address: 0x102538c */


      --hsCount; /* Line 381, Address: 0x1025398 */
      hscrollwork[hsCount] = -data.w.l; /* Line 382, Address: 0x10253a4 */
    } /* Line 383, Address: 0x10253d4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 384, Address: 0x10253f8 */
    data.l += temp; /* Line 385, Address: 0x102541c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 386, Address: 0x1025428 */
  } /* Line 387, Address: 0x102544c */
  hsCount += 44; /* Line 388, Address: 0x102545c */
  return hsCount; /* Line 389, Address: 0x1025468 */
} /* Line 390, Address: 0x102546c */


int z71aline0(int hsCount) { /* Line 393, Address: 0x1025490 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[8] = { /* Line 397, Address: 0x10254a4 */
    0, 0, 0, 0,
    0, 0, 0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 402, Address: 0x10254d4 */
  temp <<= 7; /* Line 403, Address: 0x10254f8 */
  temp /= 8; /* Line 404, Address: 0x10254fc */
  temp <<= 9; /* Line 405, Address: 0x1025518 */
  data.l = 0; /* Line 406, Address: 0x102551c */
  data.w.l = scrb_h_posit.w.h; /* Line 407, Address: 0x1025520 */
  for (i = 0; i < 8; ++i) { /* Line 408, Address: 0x102552c */


    for (j = -1; j < z71ascrtbl0[7 - i]; ++j) { /* Line 411, Address: 0x1025538 */


      hscrollwork[hsCount] = -data.w.l; /* Line 414, Address: 0x1025544 */
      ++hsCount; /* Line 415, Address: 0x1025574 */
    } /* Line 416, Address: 0x1025580 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 417, Address: 0x10255a4 */
    data.l += temp; /* Line 418, Address: 0x10255c8 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 419, Address: 0x10255d4 */
  } /* Line 420, Address: 0x10255f8 */
  return hsCount; /* Line 421, Address: 0x1025608 */
} /* Line 422, Address: 0x102560c */




void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 427, Address: 0x1025630 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;
  short VPosi2;
  short wD2;
  short sin;
  short cos;

  pHScrollBuff = lphscrollbuff; /* Line 436, Address: 0x1025654 */








  VPosi2 = VPosi + 8; /* Line 445, Address: 0x102565c */
  VPosi &= 7; /* Line 446, Address: 0x102567c */
  VPosi2 -= VPosi; /* Line 447, Address: 0x1025688 */
  hsw.l = 0; /* Line 448, Address: 0x1025698 */
  hsw.w.l = hscrollwork[offs++]; /* Line 449, Address: 0x102569c */

  j = VPosi; /* Line 451, Address: 0x10256c4 */
  while (j < 8) { /* Line 452, Address: 0x10256d0 */

    pHScrollBuff->l = hsw.l; /* Line 454, Address: 0x10256d8 */
    ++pHScrollBuff; /* Line 455, Address: 0x10256e0 */
    ++j; /* Line 456, Address: 0x10256e4 */
  } /* Line 457, Address: 0x10256e8 */
  for (i = 29; i > 0; --i) { /* Line 458, Address: 0x10256f4 */

    if ((unsigned short)VPosi2 >= 616) { /* Line 460, Address: 0x1025700 */


      ++i; /* Line 463, Address: 0x1025714 */
      i *= 8; /* Line 464, Address: 0x1025718 */
      --i; /* Line 465, Address: 0x102571c */
      wD2 = (unsigned short)waterdirec.b.h; /* Line 466, Address: 0x1025720 */

      do {
        sinset(wD2 & 255, &sin, &cos); /* Line 469, Address: 0x1025740 */
        sin = (unsigned short)sin >> 5; /* Line 470, Address: 0x1025760 */
        sin += scrz_h_posit.w.h; /* Line 471, Address: 0x102577c */
        sin *= -1; /* Line 472, Address: 0x1025790 */
        pHScrollBuff->l = (unsigned short)sin; /* Line 473, Address: 0x102579c */
        ++pHScrollBuff; /* Line 474, Address: 0x10257ac */
        wD2 += 2; /* Line 475, Address: 0x10257b0 */
        --i; /* Line 476, Address: 0x10257bc */
      } while (i >= 0); /* Line 477, Address: 0x10257c0 */
      break; /* Line 478, Address: 0x10257c8 */
    }
    hsw.w.l = hscrollwork[offs++]; /* Line 480, Address: 0x10257d0 */
    for (j = 0; j < 8; ++j) { /* Line 481, Address: 0x10257f8 */

      pHScrollBuff->l = hsw.l; /* Line 483, Address: 0x1025804 */
      ++pHScrollBuff; /* Line 484, Address: 0x102580c */
    } /* Line 485, Address: 0x1025810 */
    VPosi2 += 8; /* Line 486, Address: 0x1025820 */
  } /* Line 487, Address: 0x102582c */
} /* Line 488, Address: 0x1025838 */











void scroll_h() { /* Line 500, Address: 0x1025860 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 503, Address: 0x102586c */
  scrh_move(); /* Line 504, Address: 0x1025878 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 505, Address: 0x1025880 */
    scra_h_count ^= 16; /* Line 506, Address: 0x10258b4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 507, Address: 0x10258c8 */
      scrflaga.b.h |= 4; /* Line 508, Address: 0x10258f4 */
    } /* Line 509, Address: 0x1025908 */
    else {

      scrflaga.b.h |= 8; /* Line 512, Address: 0x1025910 */
    }
  }


} /* Line 517, Address: 0x1025924 */

void scrh_move() { /* Line 519, Address: 0x1025940 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 522, Address: 0x102594c */
  wD0 -= scra_h_posit.w.h; /* Line 523, Address: 0x1025958 */
  wD0 -= scra_hline; /* Line 524, Address: 0x102596c */
  if (wD0 == 0) { /* Line 525, Address: 0x1025980 */

    scra_hz = 0; /* Line 527, Address: 0x102598c */
  } /* Line 528, Address: 0x1025994 */
  else if ((short)wD0 < 0) { /* Line 529, Address: 0x102599c */
    left_check(wD0); /* Line 530, Address: 0x10259b4 */
  } /* Line 531, Address: 0x10259c0 */
  else {
    right_check(wD0); /* Line 533, Address: 0x10259c8 */
  }

} /* Line 536, Address: 0x10259d4 */


void right_check(unsigned short wD0) { /* Line 539, Address: 0x10259f0 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 542, Address: 0x10259fc */
    wD0 = 16; /* Line 543, Address: 0x1025a1c */
  }

  wD0 += scra_h_posit.w.h; /* Line 546, Address: 0x1025a24 */
  if (scralim_right < (short)wD0) { /* Line 547, Address: 0x1025a3c */
    wD0 = scralim_right; /* Line 548, Address: 0x1025a6c */
  }

  wD1 = wD0; /* Line 551, Address: 0x1025a78 */
  wD1 -= scra_h_posit.w.h; /* Line 552, Address: 0x1025a80 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 553, Address: 0x1025a94 */
  scra_h_posit.w.h = wD0; /* Line 554, Address: 0x1025ac4 */
  scra_hz = wD1; /* Line 555, Address: 0x1025ad0 */

} /* Line 557, Address: 0x1025ad8 */


void left_check(unsigned short wD0) { /* Line 560, Address: 0x1025af0 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 563, Address: 0x1025afc */
    wD0 = -16; /* Line 564, Address: 0x1025b1c */
  }

  wD0 += scra_h_posit.w.h; /* Line 567, Address: 0x1025b24 */
  if (scralim_left > (short)wD0) { /* Line 568, Address: 0x1025b3c */
    wD0 = scralim_left; /* Line 569, Address: 0x1025b6c */
  }

  wD1 = wD0; /* Line 572, Address: 0x1025b78 */
  wD1 -= scra_h_posit.w.h; /* Line 573, Address: 0x1025b80 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 574, Address: 0x1025b94 */
  scra_h_posit.w.h = wD0; /* Line 575, Address: 0x1025bc4 */
  scra_hz = wD1; /* Line 576, Address: 0x1025bd0 */

} /* Line 578, Address: 0x1025bd8 */


















void scroll_v() { /* Line 597, Address: 0x1025bf0 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 600, Address: 0x1025bfc */
  if (actwk[0].cddat & 4) { /* Line 601, Address: 0x1025c28 */
    wD0 -= 5; /* Line 602, Address: 0x1025c40 */
  }

  if (actwk[0].cddat & 2) { /* Line 605, Address: 0x1025c48 */
    wD0 += 32; /* Line 606, Address: 0x1025c60 */
    if ((unsigned short)scra_vline > wD0) { /* Line 607, Address: 0x1025c68 */
      wD0 -= scra_vline; /* Line 608, Address: 0x1025c88 */
      sv_move_main2(wD0); /* Line 609, Address: 0x1025c9c */
      return; /* Line 610, Address: 0x1025ca8 */
    }
    wD0 -= scra_vline; /* Line 612, Address: 0x1025cb0 */
    if (wD0 >= 64) { /* Line 613, Address: 0x1025cc4 */
      wD0 -= 64; /* Line 614, Address: 0x1025cd4 */
      sv_move_main2(wD0); /* Line 615, Address: 0x1025cdc */
      return; /* Line 616, Address: 0x1025ce8 */
    }
    wD0 -= 64; /* Line 618, Address: 0x1025cf0 */
    if (limmoveflag == 0) goto label1; /* Line 619, Address: 0x1025cf8 */
    sv_move_sub2(); /* Line 620, Address: 0x1025d0c */
    return; /* Line 621, Address: 0x1025d14 */
  }




  wD0 -= scra_vline; /* Line 627, Address: 0x1025d1c */
  if (wD0) { /* Line 628, Address: 0x1025d30 */
    sv_move_main(wD0); /* Line 629, Address: 0x1025d38 */
    return; /* Line 630, Address: 0x1025d44 */
  }
  if (limmoveflag == 0) { /* Line 632, Address: 0x1025d4c */
    sv_move_sub2(); /* Line 633, Address: 0x1025d60 */
    return; /* Line 634, Address: 0x1025d68 */
  }


label1:
  scra_vz = 0; /* Line 639, Address: 0x1025d70 */

} /* Line 641, Address: 0x1025d78 */





void sv_move_main(unsigned short wD0) { /* Line 647, Address: 0x1025d90 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 650, Address: 0x1025da0 */
    sv_move_main1(wD0); /* Line 651, Address: 0x1025dbc */
  } /* Line 652, Address: 0x1025dc8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 655, Address: 0x1025dd0 */
    if ((short)wD1 < 0) { /* Line 656, Address: 0x1025ddc */
      wD1 = -(short)wD1; /* Line 657, Address: 0x1025df4 */
    }

    if (wD1 >= 2048) { /* Line 660, Address: 0x1025e10 */
      sv_move_main2(wD0); /* Line 661, Address: 0x1025e20 */
    } /* Line 662, Address: 0x1025e2c */
    else {
      if ((short)wD0 > 6) { /* Line 664, Address: 0x1025e34 */
        sv_move_plus(1536); /* Line 665, Address: 0x1025e54 */
      } /* Line 666, Address: 0x1025e60 */
      else if ((short)wD0 < -6) { /* Line 667, Address: 0x1025e68 */
        sv_move_minus(1536); /* Line 668, Address: 0x1025e88 */
      } /* Line 669, Address: 0x1025e94 */
      else {
        sv_move_sub(wD0); /* Line 671, Address: 0x1025e9c */
      }
    }
  }
} /* Line 675, Address: 0x1025ea8 */



void sv_move_main1(unsigned short wD0) { /* Line 679, Address: 0x1025ec0 */

  if ((short)wD0 > 2) { /* Line 681, Address: 0x1025ecc */
    sv_move_plus(512); /* Line 682, Address: 0x1025eec */
  } /* Line 683, Address: 0x1025ef8 */
  else if ((short)wD0 < -2) { /* Line 684, Address: 0x1025f00 */
    sv_move_minus(512); /* Line 685, Address: 0x1025f20 */
  } /* Line 686, Address: 0x1025f2c */
  else {
    sv_move_sub(wD0); /* Line 688, Address: 0x1025f34 */
  }

} /* Line 691, Address: 0x1025f40 */


void sv_move_main2(unsigned short wD0) { /* Line 694, Address: 0x1025f50 */

  if ((short)wD0 > 16) { /* Line 696, Address: 0x1025f5c */
    sv_move_plus(4096); /* Line 697, Address: 0x1025f7c */
  } /* Line 698, Address: 0x1025f88 */
  else if ((short)wD0 < -16) { /* Line 699, Address: 0x1025f90 */
    sv_move_minus(4096); /* Line 700, Address: 0x1025fb0 */
  } /* Line 701, Address: 0x1025fbc */
  else {
    sv_move_sub(wD0); /* Line 703, Address: 0x1025fc4 */
  }

} /* Line 706, Address: 0x1025fd0 */


void sv_move_sub2() { /* Line 709, Address: 0x1025fe0 */
  limmoveflag = 0; /* Line 710, Address: 0x1025fe8 */
  sv_move_sub(0); /* Line 711, Address: 0x1025ff0 */
} /* Line 712, Address: 0x1025ffc */


void sv_move_sub(unsigned short wD0) { /* Line 715, Address: 0x1026010 */
  int_union lD1;

  lD1.w.h = 0; /* Line 718, Address: 0x102601c */
  lD1.w.l = wD0; /* Line 719, Address: 0x1026020 */
  lD1.l += scra_v_posit.w.h; /* Line 720, Address: 0x1026028 */
  if ((short)wD0 > 0) { /* Line 721, Address: 0x1026044 */
    scrv_down_ch(lD1); /* Line 722, Address: 0x1026060 */
  } /* Line 723, Address: 0x102606c */
  else {
    scrv_up_ch(lD1); /* Line 725, Address: 0x1026074 */
  }

} /* Line 728, Address: 0x1026080 */




void sv_move_minus(unsigned short wD1) { /* Line 733, Address: 0x1026090 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 737, Address: 0x10260a0 */
  lD1.l <<= 8; /* Line 738, Address: 0x10260bc */
  lD1.l += scra_v_posit.l; /* Line 739, Address: 0x10260c8 */

  wk = lD1.w.h; /* Line 741, Address: 0x10260dc */
  lD1.w.h = lD1.w.l; /* Line 742, Address: 0x10260e4 */
  lD1.w.l = wk; /* Line 743, Address: 0x10260ec */
  scrv_up_ch(lD1); /* Line 744, Address: 0x10260f0 */
} /* Line 745, Address: 0x10260fc */



void scrv_up_ch(int_union lD1) { /* Line 749, Address: 0x1026110 */
  if (scralim_up >= lD1.w.l) { /* Line 750, Address: 0x102611c */
    if (lD1.w.l < -255) { /* Line 751, Address: 0x1026144 */
      lD1.w.l &= 2047; /* Line 752, Address: 0x102615c */
      actwk[0].yposi.w.h &= 2047; /* Line 753, Address: 0x1026168 */
      scra_v_posit.w.h &= 2047; /* Line 754, Address: 0x102617c */
      scrb_v_posit.w.h &= 1023; /* Line 755, Address: 0x1026190 */
    } /* Line 756, Address: 0x10261a4 */
    else {

      lD1.w.l = scralim_up; /* Line 759, Address: 0x10261ac */
    }
  }
  scrv_move(lD1); /* Line 762, Address: 0x10261b8 */

} /* Line 764, Address: 0x10261c4 */





void sv_move_plus(unsigned short wD1) { /* Line 770, Address: 0x10261e0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 774, Address: 0x10261f0 */
  lD1.w.l = wD1; /* Line 775, Address: 0x10261f4 */
  lD1.l <<= 8; /* Line 776, Address: 0x10261fc */
  lD1.l += scra_v_posit.l; /* Line 777, Address: 0x1026208 */

  wk = lD1.w.h; /* Line 779, Address: 0x102621c */
  lD1.w.h = lD1.w.l; /* Line 780, Address: 0x1026224 */
  lD1.w.l = wk; /* Line 781, Address: 0x102622c */

  scrv_down_ch(lD1); /* Line 783, Address: 0x1026230 */

} /* Line 785, Address: 0x102623c */



void scrv_down_ch(int_union lD1) { /* Line 789, Address: 0x1026250 */
  if (scralim_down <= lD1.w.l) { /* Line 790, Address: 0x102625c */
    lD1.w.l -= 2048; /* Line 791, Address: 0x1026284 */
    if (lD1.w.l > 0) { /* Line 792, Address: 0x1026290 */
      actwk[0].yposi.w.h &= 2047; /* Line 793, Address: 0x10262a4 */
      scra_v_posit.w.h -= 2048; /* Line 794, Address: 0x10262b8 */
      scrb_v_posit.w.h &= 1023; /* Line 795, Address: 0x10262cc */
    } /* Line 796, Address: 0x10262e0 */
    else {
      lD1.w.l = scralim_down; /* Line 798, Address: 0x10262e8 */
    }
  }
  scrv_move(lD1); /* Line 801, Address: 0x10262f4 */

} /* Line 803, Address: 0x1026300 */


void scrv_move(int_union lD1) { /* Line 806, Address: 0x1026310 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 809, Address: 0x1026320 */

  wk = lD1.w.h; /* Line 811, Address: 0x102632c */
  lD1.w.h = lD1.w.l; /* Line 812, Address: 0x1026334 */
  lD1.w.l = wk; /* Line 813, Address: 0x102633c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 815, Address: 0x1026340 */
  scra_v_posit.l = lD1.l; /* Line 816, Address: 0x1026368 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 819, Address: 0x1026374 */
    scra_v_count ^= 16; /* Line 820, Address: 0x10263a8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 821, Address: 0x10263bc */

      scrflaga.b.h |= 2; /* Line 823, Address: 0x10263e8 */
    } /* Line 824, Address: 0x10263fc */
    else {
      scrflaga.b.h |= 1; /* Line 826, Address: 0x1026404 */
    }
  }


} /* Line 831, Address: 0x1026418 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 835, Address: 0x1026430 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 838, Address: 0x102643c */
  lD0.l += lD4.l; /* Line 839, Address: 0x102644c */
  scrb_h_posit.l = lD0.l; /* Line 840, Address: 0x102645c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 842, Address: 0x1026468 */

    scrb_h_count ^= 16; /* Line 844, Address: 0x102649c */
    lD0.l -= lD2.l; /* Line 845, Address: 0x10264b0 */
    if ((long int)lD0.l < 0) { /* Line 846, Address: 0x10264c0 */
      scrflagb.b.h |= 4; /* Line 847, Address: 0x10264d4 */
    } /* Line 848, Address: 0x10264e8 */
    else {

      scrflagb.b.h |= 8; /* Line 851, Address: 0x10264f0 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 856, Address: 0x1026504 */
  lD0.l += lD5.l; /* Line 857, Address: 0x1026514 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 858, Address: 0x1026524 */
  scrb_v_posit.l = lD0.l; /* Line 859, Address: 0x102653c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 861, Address: 0x1026548 */

    scrb_v_count ^= 16; /* Line 863, Address: 0x102657c */
    lD0.l -= lD3.l; /* Line 864, Address: 0x1026590 */
    if ((long int)lD0.l < 0) { /* Line 865, Address: 0x10265a0 */
      scrflagb.b.h |= 1; /* Line 866, Address: 0x10265b4 */
    } /* Line 867, Address: 0x10265c8 */
    else {

      scrflagb.b.h |= 2; /* Line 870, Address: 0x10265d0 */
    }
  }


} /* Line 875, Address: 0x10265e4 */






void scrollb_v(unsigned short wD0) { /* Line 882, Address: 0x10265f0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 885, Address: 0x10265fc */
  scrb_v_posit.w.h = wD0; /* Line 886, Address: 0x1026608 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 888, Address: 0x1026614 */
    scrb_v_count ^= 16; /* Line 889, Address: 0x1026640 */
    if ((short)wD3 > (short)wD0) { /* Line 890, Address: 0x1026654 */
      scrflagb.b.h |= 1; /* Line 891, Address: 0x1026684 */
    } /* Line 892, Address: 0x1026698 */
    else {

      scrflagb.b.h |= 2; /* Line 895, Address: 0x10266a0 */
    }
  }


} /* Line 900, Address: 0x10266b4 */



void scrollb_h(int lD4, int flagb) { /* Line 904, Address: 0x10266d0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 908, Address: 0x10266e0 */
  lD0.l = lD2.l + lD4; /* Line 909, Address: 0x10266ec */
  scrb_h_posit.l = lD0.l; /* Line 910, Address: 0x10266fc */

  lD1.w.h = lD0.w.l; /* Line 912, Address: 0x1026708 */
  lD1.w.l = lD0.w.h; /* Line 913, Address: 0x1026710 */
  lD1.w.l &= 16; /* Line 914, Address: 0x1026718 */

  bD3 = scrb_h_count; /* Line 916, Address: 0x1026724 */
  lD1.b.b4 ^= bD3; /* Line 917, Address: 0x1026730 */
  if (!lD1.b.b4) { /* Line 918, Address: 0x1026744 */
    scrb_h_count ^= 16; /* Line 919, Address: 0x1026750 */
    lD0.l -= lD2.l; /* Line 920, Address: 0x1026764 */
    if ((long int)lD0.l < 0) { /* Line 921, Address: 0x1026774 */
      scrflagb.b.h |= flagb; /* Line 922, Address: 0x1026788 */
    } /* Line 923, Address: 0x10267a4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 926, Address: 0x10267ac */
    }
  }


} /* Line 931, Address: 0x10267cc */


void scrollc_h(int lD4, int flagc) { /* Line 934, Address: 0x10267e0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 938, Address: 0x10267f0 */
  lD0.l = lD2.l + lD4; /* Line 939, Address: 0x10267fc */
  scrc_h_posit.l = lD0.l; /* Line 940, Address: 0x102680c */

  lD1.w.h = lD0.w.l; /* Line 942, Address: 0x1026818 */
  lD1.w.l = lD0.w.h; /* Line 943, Address: 0x1026820 */
  lD1.w.l &= 16; /* Line 944, Address: 0x1026828 */

  bD3 = scrc_h_count; /* Line 946, Address: 0x1026834 */
  lD1.b.b4 ^= bD3; /* Line 947, Address: 0x1026840 */
  if (!lD1.b.b4) { /* Line 948, Address: 0x1026854 */
    scrc_h_count ^= 16; /* Line 949, Address: 0x1026860 */
    lD0.l -= lD2.l; /* Line 950, Address: 0x1026874 */
    if ((long int)lD0.l < 0) { /* Line 951, Address: 0x1026884 */
      scrflagc.b.h |= flagc; /* Line 952, Address: 0x1026898 */
    } /* Line 953, Address: 0x10268b4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 956, Address: 0x10268bc */
    }
  }


} /* Line 961, Address: 0x10268dc */











void scrollz_h(int lD4, int flagz) { /* Line 973, Address: 0x10268f0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 977, Address: 0x1026900 */
  lD0.l = lD2.l + lD4; /* Line 978, Address: 0x102690c */
  scrz_h_posit.l = lD0.l; /* Line 979, Address: 0x102691c */

  lD1.w.h = lD0.w.l; /* Line 981, Address: 0x1026928 */
  lD1.w.l = lD0.w.h; /* Line 982, Address: 0x1026930 */
  lD1.w.l &= 16; /* Line 983, Address: 0x1026938 */

  bD3 = scrz_h_count; /* Line 985, Address: 0x1026944 */
  lD1.b.b4 ^= bD3; /* Line 986, Address: 0x1026950 */
  if (!lD1.b.b4) { /* Line 987, Address: 0x1026964 */
    scrz_h_count ^= 16; /* Line 988, Address: 0x1026970 */
    lD0.l -= lD2.l; /* Line 989, Address: 0x1026984 */
    if ((long int)lD0.l < 0) { /* Line 990, Address: 0x1026994 */
      scrflagz.b.h |= flagz; /* Line 991, Address: 0x10269a8 */
    } /* Line 992, Address: 0x10269c4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 995, Address: 0x10269cc */
    }
  }


} /* Line 1000, Address: 0x10269ec */













void scrollwrtadva() { /* Line 1014, Address: 0x1026a00 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1020, Address: 0x1026a1c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1021, Address: 0x1026a20 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1022, Address: 0x1026a2c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1023, Address: 0x1026a38 */
  pScrFlag = &scrflagb.b.h; /* Line 1024, Address: 0x1026a40 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1025, Address: 0x1026a48 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1027, Address: 0x1026a5c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1028, Address: 0x1026a68 */
  pScrFlag = &scrflagc.b.h; /* Line 1029, Address: 0x1026a74 */
  scrollwrtc(); /* Line 1030, Address: 0x1026a7c */

} /* Line 1032, Address: 0x1026a84 */












void scrollwrt() { /* Line 1045, Address: 0x1026ab0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1054, Address: 0x1026ad0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1055, Address: 0x1026ad4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1056, Address: 0x1026ae0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1057, Address: 0x1026aec */
  pScrFlag = &scrflagbw.b.h; /* Line 1058, Address: 0x1026af4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1059, Address: 0x1026afc */

  VramBase = 16384; /* Line 1061, Address: 0x1026b10 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1062, Address: 0x1026b14 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1063, Address: 0x1026b20 */
  pMapWk = (unsigned char*)mapwka; /* Line 1064, Address: 0x1026b2c */
  pScrFlag = &scrflagaw.b.h; /* Line 1065, Address: 0x1026b34 */

  if (*pScrFlag) { /* Line 1067, Address: 0x1026b3c */
    if (*pScrFlag & 1) { /* Line 1068, Address: 0x1026b48 */
      *pScrFlag &= 254; /* Line 1069, Address: 0x1026b5c */

      lD4.l = -16; /* Line 1071, Address: 0x1026b68 */
      wD5 = 65520; /* Line 1072, Address: 0x1026b70 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1074, Address: 0x1026b78 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1076, Address: 0x1026b98 */
    }




    if (*pScrFlag & 2) { /* Line 1082, Address: 0x1026bc4 */
      *pScrFlag &= 253; /* Line 1083, Address: 0x1026bd8 */

      lD4.l = 224; /* Line 1085, Address: 0x1026be4 */
      wD5 = 65520; /* Line 1086, Address: 0x1026bec */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1087, Address: 0x1026bf4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1089, Address: 0x1026c14 */
    }




    if (*pScrFlag & 4) { /* Line 1095, Address: 0x1026c40 */
      *pScrFlag &= 251; /* Line 1096, Address: 0x1026c54 */

      lD4.l = -16; /* Line 1098, Address: 0x1026c60 */
      wD5 = 65520; /* Line 1099, Address: 0x1026c68 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1100, Address: 0x1026c70 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1102, Address: 0x1026c90 */
    }




    if (*pScrFlag & 8) { /* Line 1108, Address: 0x1026cbc */
      *pScrFlag &= 247; /* Line 1109, Address: 0x1026cd0 */

      lD4.l = -16; /* Line 1111, Address: 0x1026cdc */
      wD5 = 320; /* Line 1112, Address: 0x1026ce4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1113, Address: 0x1026cec */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1115, Address: 0x1026d0c */
    }
  }






} /* Line 1124, Address: 0x1026d38 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1141, Address: 0x1026d60 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1152, Address: 0x1026d8c */

  if (*pScrFlag & 1) { /* Line 1154, Address: 0x1026d94 */
    *pScrFlag &= 254; /* Line 1155, Address: 0x1026dac */
  } /* Line 1156, Address: 0x1026dc0 */
  else {
    *pScrFlag &= 254; /* Line 1158, Address: 0x1026dc8 */

    if (*pScrFlag & 2) { /* Line 1160, Address: 0x1026ddc */
      *pScrFlag &= 253; /* Line 1161, Address: 0x1026df4 */
      lD4.w.l = 224; /* Line 1162, Address: 0x1026e08 */
    } /* Line 1163, Address: 0x1026e10 */
    else {
      *pScrFlag &= 253; /* Line 1165, Address: 0x1026e18 */
      goto label1; /* Line 1166, Address: 0x1026e2c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1171, Address: 0x1026e34 */
  wD0 &= 127; /* Line 1172, Address: 0x1026e84 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1173, Address: 0x1026e8c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1179, Address: 0x1026eac */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1180, Address: 0x1026ecc */
  if (wD0 != 0) { /* Line 1181, Address: 0x1026ef0 */
    wD5 = 65520; /* Line 1182, Address: 0x1026efc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1183, Address: 0x1026f04 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1185, Address: 0x1026f24 */



  } /* Line 1189, Address: 0x1026f50 */
  else {

    wD5 = 0; /* Line 1192, Address: 0x1026f58 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1193, Address: 0x1026f5c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1197, Address: 0x1026f7c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1204, Address: 0x1026fa8 */






    lD4.l = -16; /* Line 1211, Address: 0x1026fbc */
    wD5 = 65520; /* Line 1212, Address: 0x1026fc4 */
    if (*pScrFlag & 168) { /* Line 1213, Address: 0x1026fcc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1214, Address: 0x1026fe4 */
      wD5 = 320; /* Line 1215, Address: 0x1027004 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1219, Address: 0x102700c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1221, Address: 0x102703c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1222, Address: 0x1027048 */



    for (i = 0; i < 16; ++i) { /* Line 1226, Address: 0x1027058 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1227, Address: 0x1027064 */
      if (wD0 != 0) { /* Line 1228, Address: 0x1027084 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1229, Address: 0x1027090 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1230, Address: 0x10270bc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1231, Address: 0x10270dc */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1233, Address: 0x1027100 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1236, Address: 0x1027124 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1238, Address: 0x1027144 */
        }
      }
      lD4.w.l += 16; /* Line 1241, Address: 0x1027158 */
    } /* Line 1242, Address: 0x1027164 */
    *pScrFlag = 0; /* Line 1243, Address: 0x1027174 */
  }
} /* Line 1245, Address: 0x102717c */





void scrollwrtc() {} /* Line 1251, Address: 0x10271b0 */




void scrollwrtz() {} /* Line 1256, Address: 0x10271c0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1274, Address: 0x10271d0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1287, Address: 0x10271f8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1290, Address: 0x1027218 */
    pTilePoint->x += 2; /* Line 1291, Address: 0x102722c */
    if (pTilePoint->x >= 64) { /* Line 1292, Address: 0x1027240 */
      pTilePoint->x -= 64; /* Line 1293, Address: 0x1027254 */
    }
    xOffs += 16; /* Line 1295, Address: 0x1027268 */
  } while (--lpcnt >= 0); /* Line 1296, Address: 0x1027274 */
} /* Line 1297, Address: 0x1027288 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1301, Address: 0x10272a0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1305, Address: 0x10272c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1308, Address: 0x10272e8 */
    pTilePoint->x += 2; /* Line 1309, Address: 0x10272fc */
    if (pTilePoint->x >= 64) { /* Line 1310, Address: 0x1027310 */
      pTilePoint->x -= 64; /* Line 1311, Address: 0x1027324 */
    }
    xOffs += 16; /* Line 1313, Address: 0x1027338 */
  } while (--lpcnt >= 0); /* Line 1314, Address: 0x1027344 */
} /* Line 1315, Address: 0x1027358 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1335, Address: 0x1027370 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1339, Address: 0x1027398 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1342, Address: 0x10273b8 */
    pTilePoint->y += 2; /* Line 1343, Address: 0x10273cc */
    if (pTilePoint->y >= 32) { /* Line 1344, Address: 0x10273dc */
      pTilePoint->y -= 32; /* Line 1345, Address: 0x10273f0 */
    }
    yOffs += 16; /* Line 1347, Address: 0x1027400 */
  } while (--lpcnt >= 0); /* Line 1348, Address: 0x102740c */
} /* Line 1349, Address: 0x1027420 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1368, Address: 0x1027430 */
  int base = 0; /* Line 1369, Address: 0x1027464 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1374, Address: 0x1027468 */

    base = 1; /* Line 1376, Address: 0x1027478 */
  } /* Line 1377, Address: 0x102747c */
  else if (VramBase == 16384) { /* Line 1378, Address: 0x1027484 */

    base = 0; /* Line 1380, Address: 0x1027494 */
  }
  x = pTilePoint->x; /* Line 1382, Address: 0x1027498 */
  y = pTilePoint->y; /* Line 1383, Address: 0x10274a0 */


  frip = BlkIndex & 6144; /* Line 1386, Address: 0x10274a8 */
  BlkIndex &= 1023; /* Line 1387, Address: 0x10274b0 */
  if (frip == 6144) { /* Line 1388, Address: 0x10274bc */

    p0 = 3, p1 = 2; /* Line 1390, Address: 0x10274c8 */
    p2 = 1, p3 = 0; /* Line 1391, Address: 0x10274d0 */
  } /* Line 1392, Address: 0x10274d8 */
  else if (frip & 4096) { /* Line 1393, Address: 0x10274e0 */

    p0 = 2, p1 = 3; /* Line 1395, Address: 0x10274ec */
    p2 = 0, p3 = 1; /* Line 1396, Address: 0x10274f4 */
  } /* Line 1397, Address: 0x10274fc */
  else if (frip & 2048) { /* Line 1398, Address: 0x1027504 */

    p0 = 1, p1 = 0; /* Line 1400, Address: 0x1027510 */
    p2 = 3, p3 = 2; /* Line 1401, Address: 0x1027518 */
  } /* Line 1402, Address: 0x1027520 */
  else {

    p0 = 0, p1 = 1; /* Line 1405, Address: 0x1027528 */
    p2 = 2, p3 = 3; /* Line 1406, Address: 0x1027530 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1409, Address: 0x1027538 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1410, Address: 0x102757c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1411, Address: 0x10275c0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1412, Address: 0x1027604 */

} /* Line 1414, Address: 0x1027648 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1432, Address: 0x1027680 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1433, Address: 0x10276a0 */
} /* Line 1434, Address: 0x10276c0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1436, Address: 0x10276d0 */
  wH_posiw = 0; /* Line 1437, Address: 0x10276f0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1438, Address: 0x10276f4 */
} /* Line 1439, Address: 0x1027714 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1446, Address: 0x1027730 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1452, Address: 0x1027760 */
  yOffs += wV_posiw; /* Line 1453, Address: 0x1027770 */





  if ((short)xOffs < 0) /* Line 1459, Address: 0x1027780 */
    xOffs = 0; /* Line 1460, Address: 0x102779c */
  if ((short)yOffs < 0) /* Line 1461, Address: 0x10277a0 */
    yOffs = 0; /* Line 1462, Address: 0x10277bc */
  if ((short)xOffs >= 16384) /* Line 1463, Address: 0x10277c0 */
    xOffs = 16383; /* Line 1464, Address: 0x10277e0 */
  if ((short)yOffs >= 2048) /* Line 1465, Address: 0x10277e8 */
    yOffs = 2047; /* Line 1466, Address: 0x1027808 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1467, Address: 0x1027810 */
  if (i < 0) i = 0; /* Line 1468, Address: 0x1027858 */

  ScreenNo = pMapWk[i] & 127; /* Line 1470, Address: 0x1027864 */

  if (ScreenNo) { /* Line 1472, Address: 0x1027880 */




    xOffs &= 32767; /* Line 1477, Address: 0x1027888 */
    yOffs &= 32767; /* Line 1478, Address: 0x1027894 */


    xBlk = xOffs; /* Line 1481, Address: 0x10278a0 */
    xBlk %= 256; /* Line 1482, Address: 0x10278a8 */
    xBlk /= 16; /* Line 1483, Address: 0x10278c8 */
    yBlk = yOffs; /* Line 1484, Address: 0x10278e4 */
    yBlk %= 256; /* Line 1485, Address: 0x10278ec */
    yBlk /= 16; /* Line 1486, Address: 0x102790c */

    lpw = pmapwk; /* Line 1488, Address: 0x1027928 */
    lpw += xBlk; /* Line 1489, Address: 0x1027930 */
    lpw += yBlk * 16; /* Line 1490, Address: 0x1027938 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1491, Address: 0x1027944 */
    *pIndex = *lpw; /* Line 1492, Address: 0x102795c */

    return 1; /* Line 1494, Address: 0x102796c */
  }

  *pIndex = 0; /* Line 1497, Address: 0x1027978 */
  return 0; /* Line 1498, Address: 0x1027980 */
} /* Line 1499, Address: 0x1027984 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1519, Address: 0x10279b0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1527, Address: 0x10279d8 */
  if (ScreenNo) { /* Line 1528, Address: 0x1027a3c */





    xBlk = xOffs; /* Line 1534, Address: 0x1027a44 */
    xBlk %= 256; /* Line 1535, Address: 0x1027a4c */
    xBlk /= 16; /* Line 1536, Address: 0x1027a6c */
    yBlk = yOffs; /* Line 1537, Address: 0x1027a88 */
    yBlk %= 256; /* Line 1538, Address: 0x1027a90 */
    yBlk /= 16; /* Line 1539, Address: 0x1027ab0 */


    lpw = pmapwk; /* Line 1542, Address: 0x1027acc */
    lpw += xBlk; /* Line 1543, Address: 0x1027ad4 */
    lpw += yBlk * 16; /* Line 1544, Address: 0x1027adc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1545, Address: 0x1027ae8 */
    *ppBlockNo = lpw; /* Line 1546, Address: 0x1027b00 */
    *pIndex = *lpw; /* Line 1547, Address: 0x1027b08 */




    return 1; /* Line 1552, Address: 0x1027b18 */
  }

  *pIndex = 0; /* Line 1555, Address: 0x1027b24 */
  return 0; /* Line 1556, Address: 0x1027b2c */
} /* Line 1557, Address: 0x1027b30 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1571, Address: 0x1027b50 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1578, Address: 0x1027b6c */
  pMapWk = (unsigned char*)mapwka; /* Line 1579, Address: 0x1027b70 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1580, Address: 0x1027b78 */
    *pBlockIndex = BlockNo; /* Line 1581, Address: 0x1027b9c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1582, Address: 0x1027ba8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1583, Address: 0x1027bc0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1584, Address: 0x1027bd4 */
    }
  }


} /* Line 1589, Address: 0x1027bec */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1603, Address: 0x1027c10 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1604, Address: 0x1027c1c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1605, Address: 0x1027c48 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1606, Address: 0x1027c94 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1607, Address: 0x1027cc0 */

          return 0; /* Line 1609, Address: 0x1027d0c */
        }
      }
    }
  }

  return 1; /* Line 1615, Address: 0x1027d18 */
} /* Line 1616, Address: 0x1027d1c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1633, Address: 0x1027d30 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1634, Address: 0x1027d4c */

} /* Line 1636, Address: 0x1027d68 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1638, Address: 0x1027d80 */
  wH_posiw = 0; /* Line 1639, Address: 0x1027d9c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1640, Address: 0x1027da0 */

} /* Line 1642, Address: 0x1027dbc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1644, Address: 0x1027dd0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1645, Address: 0x1027de4 */

} /* Line 1647, Address: 0x1027e00 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1649, Address: 0x1027e10 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1650, Address: 0x1027e2c */

} /* Line 1652, Address: 0x1027e48 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1654, Address: 0x1027e60 */
  xOffs += wH_posiw; /* Line 1655, Address: 0x1027e78 */
  yOffs += wV_posiw; /* Line 1656, Address: 0x1027e88 */
  yOffs &= 240; /* Line 1657, Address: 0x1027e98 */
  xOffs &= 496; /* Line 1658, Address: 0x1027ea4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1660, Address: 0x1027eb0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1661, Address: 0x1027edc */


} /* Line 1664, Address: 0x1027f08 */















void mapwrt() { /* Line 1680, Address: 0x1027f20 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1685, Address: 0x1027f38 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1686, Address: 0x1027f44 */
  pMapWk = (unsigned char*)mapwka; /* Line 1687, Address: 0x1027f50 */
  VramBase = 16384; /* Line 1688, Address: 0x1027f58 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1689, Address: 0x1027f5c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1693, Address: 0x1027f74 */
  VramBase = 24576; /* Line 1694, Address: 0x1027f7c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1695, Address: 0x1027f80 */

} /* Line 1697, Address: 0x1027f90 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1700, Address: 0x1027fb0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1701, Address: 0x1027fc8 */
} /* Line 1702, Address: 0x1027fe8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1707, Address: 0x1028000 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1711, Address: 0x1028020 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1714, Address: 0x102803c */



    wD4 += 16; /* Line 1718, Address: 0x1028064 */
  } while ((short)--wD6 >= 0); /* Line 1719, Address: 0x1028070 */

} /* Line 1721, Address: 0x1028098 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1727, Address: 0x10280b0 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1732, Address: 0x10280cc */
  wD6 = 15; /* Line 1733, Address: 0x10280d4 */

  do {
    temp.l = 0; /* Line 1736, Address: 0x10280dc */
    temp.w.l = scrb_v_posit.w.h; /* Line 1737, Address: 0x10280e0 */
    wD0 = scrb_v_posit.w.h; /* Line 1738, Address: 0x10280ec */
    wD0 += wD4 & 496; /* Line 1739, Address: 0x10280f8 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1740, Address: 0x102810c */
    wD4 += 16; /* Line 1741, Address: 0x102812c */
  } while ((short)--wD6 >= 0); /* Line 1742, Address: 0x1028134 */
} /* Line 1743, Address: 0x1028158 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1765, Address: 0x1028180 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1770, Address: 0x10281a8 */
  wD0 = pWrttbl[wD0]; /* Line 1771, Address: 0x10281b8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1773, Address: 0x10281d4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1774, Address: 0x10281f8 */
  if (wD0) { /* Line 1775, Address: 0x1028220 */
    wD5 = 65520; /* Line 1776, Address: 0x102822c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1777, Address: 0x1028234 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1780, Address: 0x1028250 */



  } /* Line 1784, Address: 0x1028278 */
  else {

    wD5 = 0; /* Line 1787, Address: 0x1028280 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1788, Address: 0x1028284 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1792, Address: 0x10282a0 */
  }





} /* Line 1799, Address: 0x10282c8 */



void mapinit() { /* Line 1803, Address: 0x10282f0 */

  colorset2(mapinittbl.colorno2); /* Line 1805, Address: 0x10282f8 */
  colorset(mapinittbl.colorno2); /* Line 1806, Address: 0x102830c */

  if (plflag) enecginit(); /* Line 1808, Address: 0x1028320 */
  if (play_start & 2) divdevset(); /* Line 1809, Address: 0x1028338 */
} /* Line 1810, Address: 0x1028358 */










void mapset() {} /* Line 1821, Address: 0x1028370 */
