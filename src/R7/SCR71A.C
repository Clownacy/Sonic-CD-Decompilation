#include "..\EQU.H"
#include "SCR71A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL7A.H"

static int z71aline(int hsCount);
static int z71aline0(int hsCount);
static int z71aline1(int hsCount);
static void zonescrsetsub0(short VPosi, unsigned short offs);

static unsigned char z81awrttbl[65] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
  0, 0, 6, 6, 6, 6, 6, 6, 6, 6,
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
extern unsigned char mapwkb[64][8];
extern unsigned char mapwka[64][8];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 124, Address: 0x101f660 */



void divdevset() {} /* Line 128, Address: 0x101f670 */
















































void scr_set() { /* Line 177, Address: 0x101f680 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 180, Address: 0x101f68c */

  i = 0; /* Line 182, Address: 0x101f6d4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 183, Address: 0x101f6d8 */
  scralim_left = scr_dir_tbl[i]; /* Line 184, Address: 0x101f6fc */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 185, Address: 0x101f718 */
  scralim_right = scr_dir_tbl[i]; /* Line 186, Address: 0x101f73c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 187, Address: 0x101f758 */
  scralim_up = scr_dir_tbl[i]; /* Line 188, Address: 0x101f77c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 189, Address: 0x101f798 */
  scralim_down = scr_dir_tbl[i]; /* Line 190, Address: 0x101f7bc */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 191, Address: 0x101f7d8 */

  scra_h_keep = scralim_left + 576; /* Line 193, Address: 0x101f7fc */
  scra_h_count = 16; /* Line 194, Address: 0x101f820 */
  scra_v_count = 16; /* Line 195, Address: 0x101f82c */

  scra_vline = scr_dir_tbl[i++]; /* Line 197, Address: 0x101f838 */
  scra_hline = 160; /* Line 198, Address: 0x101f85c */

  playposiset(); /* Line 200, Address: 0x101f868 */
} /* Line 201, Address: 0x101f870 */



void playposiset() { /* Line 205, Address: 0x101f890 */
  unsigned short playpositbl[2] = { /* Line 206, Address: 0x101f8a4 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 210, Address: 0x101f8c0 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 218, Address: 0x101f8ec */

    playload(); /* Line 220, Address: 0x101f900 */
    xWk = actwk[0].xposi.w.h; /* Line 221, Address: 0x101f908 */
    yWk = actwk[0].yposi.w.h; /* Line 222, Address: 0x101f918 */
    if (yWk < 0) yWk = 0; /* Line 223, Address: 0x101f928 */
  } /* Line 224, Address: 0x101f93c */
  else {


    i = 0; /* Line 228, Address: 0x101f944 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x101f948 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 230, Address: 0x101f96c */
  }

  if ((unsigned short)xWk > 160) { /* Line 233, Address: 0x101f990 */
    xWk -= 160; /* Line 234, Address: 0x101f9a4 */
  } /* Line 235, Address: 0x101f9b0 */
  else {
    xWk = 0; /* Line 237, Address: 0x101f9b8 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 241, Address: 0x101f9bc */
    xWk = scralim_right; /* Line 242, Address: 0x101f9e0 */
  }
  scra_h_posit.w.h = xWk; /* Line 244, Address: 0x101f9f0 */

  if ((unsigned short)yWk > 96) { /* Line 246, Address: 0x101f9f8 */
    yWk -= 96; /* Line 247, Address: 0x101fa0c */
  } /* Line 248, Address: 0x101fa18 */
  else {
    yWk = 0; /* Line 250, Address: 0x101fa20 */
  }

  if (scralim_down < yWk) { /* Line 253, Address: 0x101fa24 */
    yWk = scralim_down; /* Line 254, Address: 0x101fa48 */
  }

  scra_v_posit.w.h = yWk; /* Line 257, Address: 0x101fa58 */

  scrbinit(yWk, xWk); /* Line 259, Address: 0x101fa60 */

  i = 0; /* Line 261, Address: 0x101fa70 */
  loopmapno = playmapnotbl[i++]; /* Line 262, Address: 0x101fa74 */
  loopmapno2 = playmapnotbl[i++]; /* Line 263, Address: 0x101fa8c */
  ballmapno = playmapnotbl[i++]; /* Line 264, Address: 0x101faa4 */
  ballmapno2 = playmapnotbl[i++]; /* Line 265, Address: 0x101fabc */


} /* Line 268, Address: 0x101fad4 */



void scrbinit(short yWk, short xWk) { /* Line 272, Address: 0x101faf0 */
  uint_union data;


  data.l = 0; /* Line 276, Address: 0x101fafc */
  data.w.h = yWk; /* Line 277, Address: 0x101fb00 */
  data.l = (data.l >> 2) + (data.l >> 3); /* Line 278, Address: 0x101fb08 */
  scrb_v_posit.l = data.w.l; /* Line 279, Address: 0x101fb20 */
  scrc_v_posit.w.h = data.w.h; /* Line 280, Address: 0x101fb30 */
  scrz_v_posit.w.h = data.w.h; /* Line 281, Address: 0x101fb3c */

  scrc_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 283, Address: 0x101fb48 */
  scrz_h_posit.w.h = (unsigned short)(xWk >> 2); /* Line 284, Address: 0x101fb6c */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 285, Address: 0x101fb90 */
} /* Line 286, Address: 0x101fbbc */



void scroll() { /* Line 290, Address: 0x101fbd0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 295, Address: 0x101fbe0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 298, Address: 0x101fbf0 */
  scrchk(); /* Line 299, Address: 0x101fc1c */
  scroll_h(); /* Line 300, Address: 0x101fc24 */
  scroll_v(); /* Line 301, Address: 0x101fc2c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 303, Address: 0x101fc34 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 304, Address: 0x101fc44 */



  scrollz_h(scra_hz << 6, 64); /* Line 308, Address: 0x101fc54 */
  scrollc_h(scra_hz << 7, 16); /* Line 309, Address: 0x101fc74 */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 310, Address: 0x101fc94 */

  data.l = 0; /* Line 312, Address: 0x101fccc */
  data.w.l = scra_v_posit.w.h; /* Line 313, Address: 0x101fcd0 */
  data.w.l = (data.w.l >> 2) + (data.w.l >> 3); /* Line 314, Address: 0x101fcdc */
  scrollb_v(data.w.l); /* Line 315, Address: 0x101fd00 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 317, Address: 0x101fd0c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x101fd1c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 319, Address: 0x101fd2c */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 320, Address: 0x101fd3c */
  scrflagz.b.h = 0; /* Line 321, Address: 0x101fd70 */
  scrflagc.b.h = 0; /* Line 322, Address: 0x101fd78 */

  hsCount = 0; /* Line 324, Address: 0x101fd80 */


  hsCount = z71aline(hsCount); /* Line 327, Address: 0x101fd84 */

  for (i = 0; i < 4; ++i) { /* Line 329, Address: 0x101fd94 */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 331, Address: 0x101fda0 */
    ++hsCount; /* Line 332, Address: 0x101fdd0 */
  } /* Line 333, Address: 0x101fdd4 */

  hsCount = z71aline0(hsCount); /* Line 335, Address: 0x101fde4 */

  for (i = 0; i < 16; ++i) { /* Line 337, Address: 0x101fdf4 */

    hscrollwork[hsCount] = -scrz_h_posit.w.h; /* Line 339, Address: 0x101fe00 */
    ++hsCount; /* Line 340, Address: 0x101fe30 */
  } /* Line 341, Address: 0x101fe34 */

  hsCount = z71aline1(hsCount); /* Line 343, Address: 0x101fe44 */



  data.w.l = scrb_v_posit.w.h; /* Line 347, Address: 0x101fe54 */
  data.w.l &= 1016; /* Line 348, Address: 0x101fe60 */
  data.w.l >>= 2; /* Line 349, Address: 0x101fe6c */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 350, Address: 0x101fe78 */
} /* Line 351, Address: 0x101feac */



static int z71aline(int hsCount) { /* Line 355, Address: 0x101fed0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[37] = { /* Line 359, Address: 0x101fee4 */
    1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
  };

  temp = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 367, Address: 0x101ff10 */
  temp <<= 7; /* Line 368, Address: 0x101ff34 */
  temp /= 37; /* Line 369, Address: 0x101ff38 */
  temp <<= 9; /* Line 370, Address: 0x101ff50 */
  data.l = 0; /* Line 371, Address: 0x101ff54 */
  data.w.l = scrb_h_posit.w.h; /* Line 372, Address: 0x101ff58 */
  hsCount += 44; /* Line 373, Address: 0x101ff64 */
  for (i = 0; i < 37; ++i) { /* Line 374, Address: 0x101ff70 */


    for (j = -1; j < z71ascrtbl[36 - i]; ++j) { /* Line 377, Address: 0x101ff7c */


      --hsCount; /* Line 380, Address: 0x101ff88 */
      hscrollwork[hsCount] = -data.w.l; /* Line 381, Address: 0x101ff94 */
    } /* Line 382, Address: 0x101ffc4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 383, Address: 0x101ffe8 */
    data.l += temp; /* Line 384, Address: 0x102000c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 385, Address: 0x1020018 */
  } /* Line 386, Address: 0x102003c */
  hsCount += 44; /* Line 387, Address: 0x102004c */
  return hsCount; /* Line 388, Address: 0x1020058 */
} /* Line 389, Address: 0x102005c */


static int z71aline0(int hsCount) { /* Line 392, Address: 0x1020080 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[12] = { /* Line 396, Address: 0x1020094 */
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 402, Address: 0x10200c8 */
  temp <<= 7; /* Line 403, Address: 0x10200ec */
  temp /= 12; /* Line 404, Address: 0x10200f0 */
  temp <<= 9; /* Line 405, Address: 0x1020108 */
  data.l = 0; /* Line 406, Address: 0x102010c */
  data.w.l = scrb_h_posit.w.h; /* Line 407, Address: 0x1020110 */
  for (i = 0; i < 12; ++i) { /* Line 408, Address: 0x102011c */


    for (j = -1; j < z71ascrtbl0[11 - i]; ++j) { /* Line 411, Address: 0x1020128 */


      hscrollwork[hsCount] = -data.w.l; /* Line 414, Address: 0x1020134 */
      ++hsCount; /* Line 415, Address: 0x1020164 */
    } /* Line 416, Address: 0x1020170 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 417, Address: 0x1020194 */
    data.l += temp; /* Line 418, Address: 0x10201b8 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 419, Address: 0x10201c4 */
  } /* Line 420, Address: 0x10201e8 */
  return hsCount; /* Line 421, Address: 0x10201f8 */
} /* Line 422, Address: 0x10201fc */


static int z71aline1(int hsCount) { /* Line 425, Address: 0x1020220 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl1[2] = { /* Line 429, Address: 0x1020234 */
    9,
    7
  };

  temp = scrc_h_posit.w.h - scra_h_posit.w.h; /* Line 434, Address: 0x1020250 */
  temp <<= 7; /* Line 435, Address: 0x1020274 */
  temp /= 8; /* Line 436, Address: 0x1020278 */
  temp <<= 9; /* Line 437, Address: 0x1020294 */
  data.l = 0; /* Line 438, Address: 0x1020298 */
  data.w.l = scrc_h_posit.w.h; /* Line 439, Address: 0x102029c */
  for (i = 0; i < 2; ++i) { /* Line 440, Address: 0x10202a8 */


    for (j = -1; j < z71ascrtbl1[1 - i]; ++j) { /* Line 443, Address: 0x10202b4 */


      hscrollwork[hsCount] = -data.w.l; /* Line 446, Address: 0x10202c0 */
      ++hsCount; /* Line 447, Address: 0x10202f0 */
    } /* Line 448, Address: 0x10202fc */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 449, Address: 0x1020320 */
    data.l += temp; /* Line 450, Address: 0x1020344 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 451, Address: 0x1020350 */
  } /* Line 452, Address: 0x1020374 */
  return hsCount; /* Line 453, Address: 0x1020384 */
} /* Line 454, Address: 0x1020388 */



static void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 458, Address: 0x10203a0 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 466, Address: 0x10203b8 */








  VPosi &= 7; /* Line 475, Address: 0x10203c0 */
  hsw.l = 0; /* Line 476, Address: 0x10203cc */
  hsw.w.l = hscrollwork[offs++]; /* Line 477, Address: 0x10203d0 */

  j = VPosi; /* Line 479, Address: 0x10203f8 */
  while (j < 8) { /* Line 480, Address: 0x1020404 */

    pHScrollBuff->l = hsw.l; /* Line 482, Address: 0x102040c */
    ++pHScrollBuff; /* Line 483, Address: 0x1020414 */
    ++j; /* Line 484, Address: 0x1020418 */
  } /* Line 485, Address: 0x102041c */
  for (i = 0; i < 29; ++i) { /* Line 486, Address: 0x1020428 */

    hsw.w.l = hscrollwork[offs++]; /* Line 488, Address: 0x1020434 */
    for (j = 0; j < 8; ++j) { /* Line 489, Address: 0x102045c */

      pHScrollBuff->l = hsw.l; /* Line 491, Address: 0x1020468 */
      ++pHScrollBuff; /* Line 492, Address: 0x1020470 */
    } /* Line 493, Address: 0x1020474 */
  } /* Line 494, Address: 0x1020484 */
} /* Line 495, Address: 0x1020494 */











void scroll_h() { /* Line 507, Address: 0x10204b0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 510, Address: 0x10204bc */
  scrh_move(); /* Line 511, Address: 0x10204c8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 512, Address: 0x10204d0 */
    scra_h_count ^= 16; /* Line 513, Address: 0x1020504 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 514, Address: 0x1020518 */
      scrflaga.b.h |= 4; /* Line 515, Address: 0x1020544 */
    } /* Line 516, Address: 0x1020558 */
    else {

      scrflaga.b.h |= 8; /* Line 519, Address: 0x1020560 */
    }
  }


}

void scrh_move() { /* Line 526, Address: 0x1020590 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 529, Address: 0x102059c */
  wD0 -= scra_h_posit.w.h; /* Line 530, Address: 0x10205a8 */
  wD0 -= scra_hline; /* Line 531, Address: 0x10205bc */
  if (wD0 == 0) { /* Line 532, Address: 0x10205d0 */

    scra_hz = 0; /* Line 534, Address: 0x10205dc */
  } /* Line 535, Address: 0x10205e4 */
  else if ((short)wD0 < 0) { /* Line 536, Address: 0x10205ec */
    left_check(wD0); /* Line 537, Address: 0x1020604 */
  } /* Line 538, Address: 0x1020610 */
  else {
    right_check(wD0); /* Line 540, Address: 0x1020618 */
  }

} /* Line 543, Address: 0x1020624 */


void right_check(unsigned short wD0) { /* Line 546, Address: 0x1020640 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 549, Address: 0x102064c */
    wD0 = 16; /* Line 550, Address: 0x102066c */
  }

  wD0 += scra_h_posit.w.h; /* Line 553, Address: 0x1020674 */
  if (scralim_right < (short)wD0) { /* Line 554, Address: 0x102068c */
    wD0 = scralim_right; /* Line 555, Address: 0x10206bc */
  }

  wD1 = wD0; /* Line 558, Address: 0x10206c8 */
  wD1 -= scra_h_posit.w.h; /* Line 559, Address: 0x10206d0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 560, Address: 0x10206e4 */
  scra_h_posit.w.h = wD0; /* Line 561, Address: 0x1020714 */
  scra_hz = wD1; /* Line 562, Address: 0x1020720 */

} /* Line 564, Address: 0x1020728 */


void left_check(unsigned short wD0) { /* Line 567, Address: 0x1020740 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 570, Address: 0x102074c */
    wD0 = -16; /* Line 571, Address: 0x102076c */
  }

  wD0 += scra_h_posit.w.h; /* Line 574, Address: 0x1020774 */
  if (scralim_left > (short)wD0) { /* Line 575, Address: 0x102078c */
    wD0 = scralim_left; /* Line 576, Address: 0x10207bc */
  }

  wD1 = wD0; /* Line 579, Address: 0x10207c8 */
  wD1 -= scra_h_posit.w.h; /* Line 580, Address: 0x10207d0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 581, Address: 0x10207e4 */
  scra_h_posit.w.h = wD0; /* Line 582, Address: 0x1020814 */
  scra_hz = wD1; /* Line 583, Address: 0x1020820 */

} /* Line 585, Address: 0x1020828 */


















void scroll_v() { /* Line 604, Address: 0x1020840 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 607, Address: 0x102084c */
  if (actwk[0].cddat & 4) { /* Line 608, Address: 0x1020878 */
    wD0 -= 5; /* Line 609, Address: 0x1020890 */
  }

  if (actwk[0].cddat & 2) { /* Line 612, Address: 0x1020898 */
    wD0 += 32; /* Line 613, Address: 0x10208b0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 614, Address: 0x10208b8 */
      wD0 -= scra_vline; /* Line 615, Address: 0x10208d8 */
      sv_move_main2(wD0); /* Line 616, Address: 0x10208ec */
      return; /* Line 617, Address: 0x10208f8 */
    }
    wD0 -= scra_vline; /* Line 619, Address: 0x1020900 */
    if (wD0 >= 64) { /* Line 620, Address: 0x1020914 */
      wD0 -= 64; /* Line 621, Address: 0x1020924 */
      sv_move_main2(wD0); /* Line 622, Address: 0x102092c */
      return; /* Line 623, Address: 0x1020938 */
    }
    wD0 -= 64; /* Line 625, Address: 0x1020940 */
    if (limmoveflag == 0) goto label1; /* Line 626, Address: 0x1020948 */
    sv_move_sub2(); /* Line 627, Address: 0x102095c */
    return; /* Line 628, Address: 0x1020964 */
  }




  wD0 -= scra_vline; /* Line 634, Address: 0x102096c */
  if (wD0) { /* Line 635, Address: 0x1020980 */
    sv_move_main(wD0); /* Line 636, Address: 0x1020988 */
    return; /* Line 637, Address: 0x1020994 */
  }
  if (limmoveflag == 0) { /* Line 639, Address: 0x102099c */
    sv_move_sub2(); /* Line 640, Address: 0x10209b0 */
    return; /* Line 641, Address: 0x10209b8 */
  }


label1:
  scra_vz = 0; /* Line 646, Address: 0x10209c0 */

} /* Line 648, Address: 0x10209c8 */





void sv_move_main(unsigned short wD0) { /* Line 654, Address: 0x10209e0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 657, Address: 0x10209f0 */
    sv_move_main1(wD0); /* Line 658, Address: 0x1020a0c */
  } /* Line 659, Address: 0x1020a18 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 662, Address: 0x1020a20 */
    if ((short)wD1 < 0) { /* Line 663, Address: 0x1020a2c */
      wD1 = -(short)wD1; /* Line 664, Address: 0x1020a44 */
    }

    if (wD1 >= 2048) { /* Line 667, Address: 0x1020a60 */
      sv_move_main2(wD0); /* Line 668, Address: 0x1020a70 */
    } /* Line 669, Address: 0x1020a7c */
    else {
      if ((short)wD0 > 6) { /* Line 671, Address: 0x1020a84 */
        sv_move_plus(1536); /* Line 672, Address: 0x1020aa4 */
      } /* Line 673, Address: 0x1020ab0 */
      else if ((short)wD0 < -6) { /* Line 674, Address: 0x1020ab8 */
        sv_move_minus(1536); /* Line 675, Address: 0x1020ad8 */
      } /* Line 676, Address: 0x1020ae4 */
      else {
        sv_move_sub(wD0); /* Line 678, Address: 0x1020aec */
      }
    }
  }
} /* Line 682, Address: 0x1020af8 */



void sv_move_main1(unsigned short wD0) { /* Line 686, Address: 0x1020b10 */

  if ((short)wD0 > 2) { /* Line 688, Address: 0x1020b1c */
    sv_move_plus(512); /* Line 689, Address: 0x1020b3c */
  } /* Line 690, Address: 0x1020b48 */
  else if ((short)wD0 < -2) { /* Line 691, Address: 0x1020b50 */
    sv_move_minus(512); /* Line 692, Address: 0x1020b70 */
  } /* Line 693, Address: 0x1020b7c */
  else {
    sv_move_sub(wD0); /* Line 695, Address: 0x1020b84 */
  }

} /* Line 698, Address: 0x1020b90 */


void sv_move_main2(unsigned short wD0) { /* Line 701, Address: 0x1020ba0 */

  if ((short)wD0 > 16) { /* Line 703, Address: 0x1020bac */
    sv_move_plus(4096); /* Line 704, Address: 0x1020bcc */
  } /* Line 705, Address: 0x1020bd8 */
  else if ((short)wD0 < -16) { /* Line 706, Address: 0x1020be0 */
    sv_move_minus(4096); /* Line 707, Address: 0x1020c00 */
  } /* Line 708, Address: 0x1020c0c */
  else {
    sv_move_sub(wD0); /* Line 710, Address: 0x1020c14 */
  }

} /* Line 713, Address: 0x1020c20 */


void sv_move_sub2() { /* Line 716, Address: 0x1020c30 */
  limmoveflag = 0; /* Line 717, Address: 0x1020c38 */
  sv_move_sub(0); /* Line 718, Address: 0x1020c40 */
} /* Line 719, Address: 0x1020c4c */


void sv_move_sub(unsigned short wD0) { /* Line 722, Address: 0x1020c60 */
  int_union lD1;

  lD1.w.h = 0; /* Line 725, Address: 0x1020c6c */
  lD1.w.l = wD0; /* Line 726, Address: 0x1020c70 */
  lD1.l += scra_v_posit.w.h; /* Line 727, Address: 0x1020c78 */
  if ((short)wD0 > 0) { /* Line 728, Address: 0x1020c94 */
    scrv_down_ch(lD1); /* Line 729, Address: 0x1020cb0 */
  } /* Line 730, Address: 0x1020cbc */
  else {
    scrv_up_ch(lD1); /* Line 732, Address: 0x1020cc4 */
  }

} /* Line 735, Address: 0x1020cd0 */




void sv_move_minus(unsigned short wD1) { /* Line 740, Address: 0x1020ce0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 744, Address: 0x1020cf0 */
  lD1.l <<= 8; /* Line 745, Address: 0x1020d0c */
  lD1.l += scra_v_posit.l; /* Line 746, Address: 0x1020d18 */

  wk = lD1.w.h; /* Line 748, Address: 0x1020d2c */
  lD1.w.h = lD1.w.l; /* Line 749, Address: 0x1020d34 */
  lD1.w.l = wk; /* Line 750, Address: 0x1020d3c */
  scrv_up_ch(lD1); /* Line 751, Address: 0x1020d40 */
} /* Line 752, Address: 0x1020d4c */



void scrv_up_ch(int_union lD1) { /* Line 756, Address: 0x1020d60 */
  if (scralim_up >= lD1.w.l) { /* Line 757, Address: 0x1020d6c */
    if (lD1.w.l < -255) { /* Line 758, Address: 0x1020d94 */
      lD1.w.l &= 2047; /* Line 759, Address: 0x1020dac */
      actwk[0].yposi.w.h &= 2047; /* Line 760, Address: 0x1020db8 */
      scra_v_posit.w.h &= 2047; /* Line 761, Address: 0x1020dcc */
      scrb_v_posit.w.h &= 1023; /* Line 762, Address: 0x1020de0 */
    } /* Line 763, Address: 0x1020df4 */
    else {

      lD1.w.l = scralim_up; /* Line 766, Address: 0x1020dfc */
    }
  }
  scrv_move(lD1); /* Line 769, Address: 0x1020e08 */

} /* Line 771, Address: 0x1020e14 */





void sv_move_plus(unsigned short wD1) { /* Line 777, Address: 0x1020e30 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 781, Address: 0x1020e40 */
  lD1.w.l = wD1; /* Line 782, Address: 0x1020e44 */
  lD1.l <<= 8; /* Line 783, Address: 0x1020e4c */
  lD1.l += scra_v_posit.l; /* Line 784, Address: 0x1020e58 */

  wk = lD1.w.h; /* Line 786, Address: 0x1020e6c */
  lD1.w.h = lD1.w.l; /* Line 787, Address: 0x1020e74 */
  lD1.w.l = wk; /* Line 788, Address: 0x1020e7c */

  scrv_down_ch(lD1); /* Line 790, Address: 0x1020e80 */

} /* Line 792, Address: 0x1020e8c */



void scrv_down_ch(int_union lD1) { /* Line 796, Address: 0x1020ea0 */
  if (scralim_down <= lD1.w.l) { /* Line 797, Address: 0x1020eac */
    lD1.w.l -= 2048; /* Line 798, Address: 0x1020ed4 */
    if (lD1.w.l > 0) { /* Line 799, Address: 0x1020ee0 */
      actwk[0].yposi.w.h &= 2047; /* Line 800, Address: 0x1020ef4 */
      scra_v_posit.w.h -= 2048; /* Line 801, Address: 0x1020f08 */
      scrb_v_posit.w.h &= 1023; /* Line 802, Address: 0x1020f1c */
    } /* Line 803, Address: 0x1020f30 */
    else {
      lD1.w.l = scralim_down; /* Line 805, Address: 0x1020f38 */
    }
  }
  scrv_move(lD1); /* Line 808, Address: 0x1020f44 */

} /* Line 810, Address: 0x1020f50 */


void scrv_move(int_union lD1) { /* Line 813, Address: 0x1020f60 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 816, Address: 0x1020f70 */

  wk = lD1.w.h; /* Line 818, Address: 0x1020f7c */
  lD1.w.h = lD1.w.l; /* Line 819, Address: 0x1020f84 */
  lD1.w.l = wk; /* Line 820, Address: 0x1020f8c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 822, Address: 0x1020f90 */
  scra_v_posit.l = lD1.l; /* Line 823, Address: 0x1020fb8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 826, Address: 0x1020fc4 */
    scra_v_count ^= 16; /* Line 827, Address: 0x1020ff8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 828, Address: 0x102100c */

      scrflaga.b.h |= 2; /* Line 830, Address: 0x1021038 */
    } /* Line 831, Address: 0x102104c */
    else {
      scrflaga.b.h |= 1; /* Line 833, Address: 0x1021054 */
    }
  }


} /* Line 838, Address: 0x1021068 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 842, Address: 0x1021080 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 845, Address: 0x102108c */
  lD0.l += lD4.l; /* Line 846, Address: 0x102109c */
  scrb_h_posit.l = lD0.l; /* Line 847, Address: 0x10210ac */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 849, Address: 0x10210b8 */

    scrb_h_count ^= 16; /* Line 851, Address: 0x10210ec */
    lD0.l -= lD2.l; /* Line 852, Address: 0x1021100 */
    if ((long int)lD0.l < 0) { /* Line 853, Address: 0x1021110 */
      scrflagb.b.h |= 4; /* Line 854, Address: 0x1021124 */
    } /* Line 855, Address: 0x1021138 */
    else {

      scrflagb.b.h |= 8; /* Line 858, Address: 0x1021140 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 863, Address: 0x1021154 */
  lD0.l += lD5.l; /* Line 864, Address: 0x1021164 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 865, Address: 0x1021174 */
  scrb_v_posit.l = lD0.l; /* Line 866, Address: 0x102118c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 868, Address: 0x1021198 */

    scrb_v_count ^= 16; /* Line 870, Address: 0x10211cc */
    lD0.l -= lD3.l; /* Line 871, Address: 0x10211e0 */
    if ((long int)lD0.l < 0) { /* Line 872, Address: 0x10211f0 */
      scrflagb.b.h |= 1; /* Line 873, Address: 0x1021204 */
    } /* Line 874, Address: 0x1021218 */
    else {

      scrflagb.b.h |= 2; /* Line 877, Address: 0x1021220 */
    }
  }


} /* Line 882, Address: 0x1021234 */






void scrollb_v(unsigned short wD0) { /* Line 889, Address: 0x1021240 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 892, Address: 0x102124c */
  scrb_v_posit.w.h = wD0; /* Line 893, Address: 0x1021258 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 895, Address: 0x1021264 */
    scrb_v_count ^= 16; /* Line 896, Address: 0x1021290 */
    if ((short)wD3 > (short)wD0) { /* Line 897, Address: 0x10212a4 */
      scrflagb.b.h |= 1; /* Line 898, Address: 0x10212d4 */
    } /* Line 899, Address: 0x10212e8 */
    else {

      scrflagb.b.h |= 2; /* Line 902, Address: 0x10212f0 */
    }
  }


} /* Line 907, Address: 0x1021304 */



void scrollb_h(int lD4, int flagb) { /* Line 911, Address: 0x1021320 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 915, Address: 0x1021330 */
  lD0.l = lD2.l + lD4; /* Line 916, Address: 0x102133c */
  scrb_h_posit.l = lD0.l; /* Line 917, Address: 0x102134c */

  lD1.w.h = lD0.w.l; /* Line 919, Address: 0x1021358 */
  lD1.w.l = lD0.w.h; /* Line 920, Address: 0x1021360 */
  lD1.w.l &= 16; /* Line 921, Address: 0x1021368 */

  bD3 = scrb_h_count; /* Line 923, Address: 0x1021374 */
  lD1.b.b4 ^= bD3; /* Line 924, Address: 0x1021380 */
  if (!lD1.b.b4) { /* Line 925, Address: 0x1021394 */
    scrb_h_count ^= 16; /* Line 926, Address: 0x10213a0 */
    lD0.l -= lD2.l; /* Line 927, Address: 0x10213b4 */
    if ((long int)lD0.l < 0) { /* Line 928, Address: 0x10213c4 */
      scrflagb.b.h |= flagb; /* Line 929, Address: 0x10213d8 */
    } /* Line 930, Address: 0x10213f4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 933, Address: 0x10213fc */
    }
  }


} /* Line 938, Address: 0x102141c */


void scrollc_h(int lD4, int flagc) { /* Line 941, Address: 0x1021430 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 945, Address: 0x1021440 */
  lD0.l = lD2.l + lD4; /* Line 946, Address: 0x102144c */
  scrc_h_posit.l = lD0.l; /* Line 947, Address: 0x102145c */

  lD1.w.h = lD0.w.l; /* Line 949, Address: 0x1021468 */
  lD1.w.l = lD0.w.h; /* Line 950, Address: 0x1021470 */
  lD1.w.l &= 16; /* Line 951, Address: 0x1021478 */

  bD3 = scrc_h_count; /* Line 953, Address: 0x1021484 */
  lD1.b.b4 ^= bD3; /* Line 954, Address: 0x1021490 */
  if (!lD1.b.b4) { /* Line 955, Address: 0x10214a4 */
    scrc_h_count ^= 16; /* Line 956, Address: 0x10214b0 */
    lD0.l -= lD2.l; /* Line 957, Address: 0x10214c4 */
    if ((long int)lD0.l < 0) { /* Line 958, Address: 0x10214d4 */
      scrflagc.b.h |= flagc; /* Line 959, Address: 0x10214e8 */
    } /* Line 960, Address: 0x1021504 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 963, Address: 0x102150c */
    }
  }


} /* Line 968, Address: 0x102152c */











void scrollz_h(int lD4, int flagz) { /* Line 980, Address: 0x1021540 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 984, Address: 0x1021550 */
  lD0.l = lD2.l + lD4; /* Line 985, Address: 0x102155c */
  scrz_h_posit.l = lD0.l; /* Line 986, Address: 0x102156c */

  lD1.w.h = lD0.w.l; /* Line 988, Address: 0x1021578 */
  lD1.w.l = lD0.w.h; /* Line 989, Address: 0x1021580 */
  lD1.w.l &= 16; /* Line 990, Address: 0x1021588 */

  bD3 = scrz_h_count; /* Line 992, Address: 0x1021594 */
  lD1.b.b4 ^= bD3; /* Line 993, Address: 0x10215a0 */
  if (!lD1.b.b4) { /* Line 994, Address: 0x10215b4 */
    scrz_h_count ^= 16; /* Line 995, Address: 0x10215c0 */
    lD0.l -= lD2.l; /* Line 996, Address: 0x10215d4 */
    if ((long int)lD0.l < 0) { /* Line 997, Address: 0x10215e4 */
      scrflagz.b.h |= flagz; /* Line 998, Address: 0x10215f8 */
    } /* Line 999, Address: 0x1021614 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1002, Address: 0x102161c */
    }
  }


} /* Line 1007, Address: 0x102163c */













void scrollwrtadva() { /* Line 1021, Address: 0x1021650 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1027, Address: 0x102166c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1028, Address: 0x1021670 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1029, Address: 0x102167c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1030, Address: 0x1021688 */
  pScrFlag = &scrflagb.b.h; /* Line 1031, Address: 0x1021690 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1032, Address: 0x1021698 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1034, Address: 0x10216ac */
  wV_posiw = scrc_v_posit.w.h; /* Line 1035, Address: 0x10216b8 */
  pScrFlag = &scrflagc.b.h; /* Line 1036, Address: 0x10216c4 */
  scrollwrtc(); /* Line 1037, Address: 0x10216cc */

} /* Line 1039, Address: 0x10216d4 */












void scrollwrt() { /* Line 1052, Address: 0x1021700 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1061, Address: 0x1021720 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1062, Address: 0x1021724 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1063, Address: 0x1021730 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1064, Address: 0x102173c */
  pScrFlag = &scrflagbw.b.h; /* Line 1065, Address: 0x1021744 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1066, Address: 0x102174c */

  VramBase = 16384; /* Line 1068, Address: 0x1021760 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1069, Address: 0x1021764 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1070, Address: 0x1021770 */
  pMapWk = (unsigned char*)mapwka; /* Line 1071, Address: 0x102177c */
  pScrFlag = &scrflagaw.b.h; /* Line 1072, Address: 0x1021784 */

  if (*pScrFlag) { /* Line 1074, Address: 0x102178c */
    if (*pScrFlag & 1) { /* Line 1075, Address: 0x1021798 */
      *pScrFlag &= 254; /* Line 1076, Address: 0x10217ac */

      lD4.l = -16; /* Line 1078, Address: 0x10217b8 */
      wD5 = 65520; /* Line 1079, Address: 0x10217c0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1081, Address: 0x10217c8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1083, Address: 0x10217e8 */
    }




    if (*pScrFlag & 2) { /* Line 1089, Address: 0x1021814 */
      *pScrFlag &= 253; /* Line 1090, Address: 0x1021828 */

      lD4.l = 224; /* Line 1092, Address: 0x1021834 */
      wD5 = 65520; /* Line 1093, Address: 0x102183c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1094, Address: 0x1021844 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1096, Address: 0x1021864 */
    }




    if (*pScrFlag & 4) { /* Line 1102, Address: 0x1021890 */
      *pScrFlag &= 251; /* Line 1103, Address: 0x10218a4 */

      lD4.l = -16; /* Line 1105, Address: 0x10218b0 */
      wD5 = 65520; /* Line 1106, Address: 0x10218b8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1107, Address: 0x10218c0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1109, Address: 0x10218e0 */
    }




    if (*pScrFlag & 8) { /* Line 1115, Address: 0x102190c */
      *pScrFlag &= 247; /* Line 1116, Address: 0x1021920 */

      lD4.l = -16; /* Line 1118, Address: 0x102192c */
      wD5 = 320; /* Line 1119, Address: 0x1021934 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1120, Address: 0x102193c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1122, Address: 0x102195c */
    }
  }






} /* Line 1131, Address: 0x1021988 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1148, Address: 0x10219b0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1159, Address: 0x10219dc */

  if (*pScrFlag & 1) { /* Line 1161, Address: 0x10219e4 */
    *pScrFlag &= 254; /* Line 1162, Address: 0x10219fc */
  } /* Line 1163, Address: 0x1021a10 */
  else {
    *pScrFlag &= 254; /* Line 1165, Address: 0x1021a18 */

    if (*pScrFlag & 2) { /* Line 1167, Address: 0x1021a2c */
      *pScrFlag &= 253; /* Line 1168, Address: 0x1021a44 */
      lD4.w.l = 224; /* Line 1169, Address: 0x1021a58 */
    } /* Line 1170, Address: 0x1021a60 */
    else {
      *pScrFlag &= 253; /* Line 1172, Address: 0x1021a68 */
      goto label1; /* Line 1173, Address: 0x1021a7c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1178, Address: 0x1021a84 */
  wD0 &= 127; /* Line 1179, Address: 0x1021ad4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1180, Address: 0x1021adc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1186, Address: 0x1021afc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1187, Address: 0x1021b1c */
  if (wD0 != 0) { /* Line 1188, Address: 0x1021b40 */
    wD5 = 65520; /* Line 1189, Address: 0x1021b4c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1190, Address: 0x1021b54 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1192, Address: 0x1021b74 */



  } /* Line 1196, Address: 0x1021ba0 */
  else {

    wD5 = 0; /* Line 1199, Address: 0x1021ba8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1200, Address: 0x1021bac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1204, Address: 0x1021bcc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1211, Address: 0x1021bf8 */






    lD4.l = -16; /* Line 1218, Address: 0x1021c0c */
    wD5 = 65520; /* Line 1219, Address: 0x1021c14 */
    if (*pScrFlag & 168) { /* Line 1220, Address: 0x1021c1c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1221, Address: 0x1021c34 */
      wD5 = 320; /* Line 1222, Address: 0x1021c54 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1226, Address: 0x1021c5c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1228, Address: 0x1021c8c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1229, Address: 0x1021c98 */



    for (i = 0; i < 16; ++i) { /* Line 1233, Address: 0x1021ca8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1234, Address: 0x1021cb4 */
      if (wD0 != 0) { /* Line 1235, Address: 0x1021cd4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1236, Address: 0x1021ce0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1237, Address: 0x1021d0c */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1238, Address: 0x1021d2c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1240, Address: 0x1021d50 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1243, Address: 0x1021d74 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1245, Address: 0x1021d94 */
        }
      }
      lD4.w.l += 16; /* Line 1248, Address: 0x1021da8 */
    } /* Line 1249, Address: 0x1021db4 */
    *pScrFlag = 0; /* Line 1250, Address: 0x1021dc4 */
  }
} /* Line 1252, Address: 0x1021dcc */





void scrollwrtc() {} /* Line 1258, Address: 0x1021e00 */




void scrollwrtz() {} /* Line 1263, Address: 0x1021e10 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1281, Address: 0x1021e20 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1294, Address: 0x1021e48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1297, Address: 0x1021e68 */
    pTilePoint->x += 2; /* Line 1298, Address: 0x1021e7c */
    if (pTilePoint->x >= 64) { /* Line 1299, Address: 0x1021e90 */
      pTilePoint->x -= 64; /* Line 1300, Address: 0x1021ea4 */
    }
    xOffs += 16; /* Line 1302, Address: 0x1021eb8 */
  } while (--lpcnt >= 0); /* Line 1303, Address: 0x1021ec4 */
} /* Line 1304, Address: 0x1021ed8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1308, Address: 0x1021ef0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1312, Address: 0x1021f18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1315, Address: 0x1021f38 */
    pTilePoint->x += 2; /* Line 1316, Address: 0x1021f4c */
    if (pTilePoint->x >= 64) { /* Line 1317, Address: 0x1021f60 */
      pTilePoint->x -= 64; /* Line 1318, Address: 0x1021f74 */
    }
    xOffs += 16; /* Line 1320, Address: 0x1021f88 */
  } while (--lpcnt >= 0); /* Line 1321, Address: 0x1021f94 */
} /* Line 1322, Address: 0x1021fa8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1342, Address: 0x1021fc0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1346, Address: 0x1021fe8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1349, Address: 0x1022008 */
    pTilePoint->y += 2; /* Line 1350, Address: 0x102201c */
    if (pTilePoint->y >= 32) { /* Line 1351, Address: 0x102202c */
      pTilePoint->y -= 32; /* Line 1352, Address: 0x1022040 */
    }
    yOffs += 16; /* Line 1354, Address: 0x1022050 */
  } while (--lpcnt >= 0); /* Line 1355, Address: 0x102205c */
} /* Line 1356, Address: 0x1022070 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1375, Address: 0x1022080 */
  int base = 0; /* Line 1376, Address: 0x10220b4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1381, Address: 0x10220b8 */

    base = 1; /* Line 1383, Address: 0x10220c8 */
  } /* Line 1384, Address: 0x10220cc */
  else if (VramBase == 16384) { /* Line 1385, Address: 0x10220d4 */

    base = 0; /* Line 1387, Address: 0x10220e4 */
  }
  x = pTilePoint->x; /* Line 1389, Address: 0x10220e8 */
  y = pTilePoint->y; /* Line 1390, Address: 0x10220f0 */


  frip = BlkIndex & 6144; /* Line 1393, Address: 0x10220f8 */
  BlkIndex &= 1023; /* Line 1394, Address: 0x1022100 */
  if (frip == 6144) { /* Line 1395, Address: 0x102210c */

    p0 = 3, p1 = 2; /* Line 1397, Address: 0x1022118 */
    p2 = 1, p3 = 0; /* Line 1398, Address: 0x1022120 */
  } /* Line 1399, Address: 0x1022128 */
  else if (frip & 4096) { /* Line 1400, Address: 0x1022130 */

    p0 = 2, p1 = 3; /* Line 1402, Address: 0x102213c */
    p2 = 0, p3 = 1; /* Line 1403, Address: 0x1022144 */
  } /* Line 1404, Address: 0x102214c */
  else if (frip & 2048) { /* Line 1405, Address: 0x1022154 */

    p0 = 1, p1 = 0; /* Line 1407, Address: 0x1022160 */
    p2 = 3, p3 = 2; /* Line 1408, Address: 0x1022168 */
  } /* Line 1409, Address: 0x1022170 */
  else {

    p0 = 0, p1 = 1; /* Line 1412, Address: 0x1022178 */
    p2 = 2, p3 = 3; /* Line 1413, Address: 0x1022180 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1416, Address: 0x1022188 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1417, Address: 0x10221cc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1418, Address: 0x1022210 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1419, Address: 0x1022254 */

} /* Line 1421, Address: 0x1022298 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1439, Address: 0x10222d0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1440, Address: 0x10222f0 */
} /* Line 1441, Address: 0x1022310 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1443, Address: 0x1022320 */
  wH_posiw = 0; /* Line 1444, Address: 0x1022340 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1445, Address: 0x1022344 */
} /* Line 1446, Address: 0x1022364 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1453, Address: 0x1022380 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1459, Address: 0x10223b0 */
  yOffs += wV_posiw; /* Line 1460, Address: 0x10223c0 */





  if ((short)xOffs < 0) /* Line 1466, Address: 0x10223d0 */
    xOffs = 0; /* Line 1467, Address: 0x10223ec */
  if ((short)yOffs < 0) /* Line 1468, Address: 0x10223f0 */
    yOffs = 0; /* Line 1469, Address: 0x102240c */
  if ((short)xOffs >= 16384) /* Line 1470, Address: 0x1022410 */
    xOffs = 16383; /* Line 1471, Address: 0x1022430 */
  if ((short)yOffs >= 2048) /* Line 1472, Address: 0x1022438 */
    yOffs = 2047; /* Line 1473, Address: 0x1022458 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1474, Address: 0x1022460 */
  if (i < 0) i = 0; /* Line 1475, Address: 0x10224a8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1477, Address: 0x10224b4 */

  if (ScreenNo) { /* Line 1479, Address: 0x10224d0 */




    xOffs &= 32767; /* Line 1484, Address: 0x10224d8 */
    yOffs &= 32767; /* Line 1485, Address: 0x10224e4 */


    xBlk = xOffs; /* Line 1488, Address: 0x10224f0 */
    xBlk %= 256; /* Line 1489, Address: 0x10224f8 */
    xBlk /= 16; /* Line 1490, Address: 0x1022518 */
    yBlk = yOffs; /* Line 1491, Address: 0x1022534 */
    yBlk %= 256; /* Line 1492, Address: 0x102253c */
    yBlk /= 16; /* Line 1493, Address: 0x102255c */

    lpw = pmapwk; /* Line 1495, Address: 0x1022578 */
    lpw += xBlk; /* Line 1496, Address: 0x1022580 */
    lpw += yBlk * 16; /* Line 1497, Address: 0x1022588 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1498, Address: 0x1022594 */
    *pIndex = *lpw; /* Line 1499, Address: 0x10225ac */

    return 1; /* Line 1501, Address: 0x10225bc */
  }

  *pIndex = 0; /* Line 1504, Address: 0x10225c8 */
  return 0; /* Line 1505, Address: 0x10225d0 */
} /* Line 1506, Address: 0x10225d4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1526, Address: 0x1022600 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1534, Address: 0x1022628 */
  if (ScreenNo) { /* Line 1535, Address: 0x102268c */





    xBlk = xOffs; /* Line 1541, Address: 0x1022694 */
    xBlk %= 256; /* Line 1542, Address: 0x102269c */
    xBlk /= 16; /* Line 1543, Address: 0x10226bc */
    yBlk = yOffs; /* Line 1544, Address: 0x10226d8 */
    yBlk %= 256; /* Line 1545, Address: 0x10226e0 */
    yBlk /= 16; /* Line 1546, Address: 0x1022700 */


    lpw = pmapwk; /* Line 1549, Address: 0x102271c */
    lpw += xBlk; /* Line 1550, Address: 0x1022724 */
    lpw += yBlk * 16; /* Line 1551, Address: 0x102272c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1552, Address: 0x1022738 */
    *ppBlockNo = lpw; /* Line 1553, Address: 0x1022750 */
    *pIndex = *lpw; /* Line 1554, Address: 0x1022758 */




    return 1; /* Line 1559, Address: 0x1022768 */
  }

  *pIndex = 0; /* Line 1562, Address: 0x1022774 */
  return 0; /* Line 1563, Address: 0x102277c */
} /* Line 1564, Address: 0x1022780 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1578, Address: 0x10227a0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1585, Address: 0x10227bc */
  pMapWk = (unsigned char*)mapwka; /* Line 1586, Address: 0x10227c0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1587, Address: 0x10227c8 */
    *pBlockIndex = BlockNo; /* Line 1588, Address: 0x10227ec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1589, Address: 0x10227f8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1590, Address: 0x1022810 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1591, Address: 0x1022824 */
    }
  }


} /* Line 1596, Address: 0x102283c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1610, Address: 0x1022860 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1611, Address: 0x102286c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1612, Address: 0x1022898 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1613, Address: 0x10228e4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1614, Address: 0x1022910 */

          return 0; /* Line 1616, Address: 0x102295c */
        }
      }
    }
  }

  return 1; /* Line 1622, Address: 0x1022968 */
} /* Line 1623, Address: 0x102296c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1640, Address: 0x1022980 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1641, Address: 0x102299c */

} /* Line 1643, Address: 0x10229b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1645, Address: 0x10229d0 */
  wH_posiw = 0; /* Line 1646, Address: 0x10229ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1647, Address: 0x10229f0 */

} /* Line 1649, Address: 0x1022a0c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1651, Address: 0x1022a20 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1652, Address: 0x1022a34 */

} /* Line 1654, Address: 0x1022a50 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1656, Address: 0x1022a60 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1657, Address: 0x1022a7c */

} /* Line 1659, Address: 0x1022a98 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1661, Address: 0x1022ab0 */
  xOffs += wH_posiw; /* Line 1662, Address: 0x1022ac8 */
  yOffs += wV_posiw; /* Line 1663, Address: 0x1022ad8 */
  yOffs &= 240; /* Line 1664, Address: 0x1022ae8 */
  xOffs &= 496; /* Line 1665, Address: 0x1022af4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1667, Address: 0x1022b00 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1668, Address: 0x1022b2c */


} /* Line 1671, Address: 0x1022b58 */















void mapwrt() { /* Line 1687, Address: 0x1022b70 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1692, Address: 0x1022b88 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1693, Address: 0x1022b94 */
  pMapWk = (unsigned char*)mapwka; /* Line 1694, Address: 0x1022ba0 */
  VramBase = 16384; /* Line 1695, Address: 0x1022ba8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1696, Address: 0x1022bac */



  pMapWk = (unsigned char*)mapwkb; /* Line 1700, Address: 0x1022bc4 */
  VramBase = 24576; /* Line 1701, Address: 0x1022bcc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1702, Address: 0x1022bd0 */

} /* Line 1704, Address: 0x1022be0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1707, Address: 0x1022c00 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1708, Address: 0x1022c18 */
} /* Line 1709, Address: 0x1022c38 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1714, Address: 0x1022c50 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1718, Address: 0x1022c70 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1721, Address: 0x1022c8c */



    wD4 += 16; /* Line 1725, Address: 0x1022cb4 */
  } while ((short)--wD6 >= 0); /* Line 1726, Address: 0x1022cc0 */

} /* Line 1728, Address: 0x1022ce8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1734, Address: 0x1022d00 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1739, Address: 0x1022d1c */
  wD6 = 15; /* Line 1740, Address: 0x1022d24 */

  do {
    temp.l = 0; /* Line 1743, Address: 0x1022d2c */
    temp.w.l = scrb_v_posit.w.h; /* Line 1744, Address: 0x1022d30 */
    wD0 = scrb_v_posit.w.h; /* Line 1745, Address: 0x1022d3c */
    wD0 += wD4 & 496; /* Line 1746, Address: 0x1022d48 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1747, Address: 0x1022d5c */
    wD4 += 16; /* Line 1748, Address: 0x1022d7c */
  } while ((short)--wD6 >= 0); /* Line 1749, Address: 0x1022d84 */
} /* Line 1750, Address: 0x1022da8 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1772, Address: 0x1022dd0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1777, Address: 0x1022df8 */
  wD0 = pWrttbl[wD0]; /* Line 1778, Address: 0x1022e08 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1780, Address: 0x1022e24 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1781, Address: 0x1022e48 */
  if (wD0) { /* Line 1782, Address: 0x1022e70 */
    wD5 = 65520; /* Line 1783, Address: 0x1022e7c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1784, Address: 0x1022e84 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1787, Address: 0x1022ea0 */



  } /* Line 1791, Address: 0x1022ec8 */
  else {

    wD5 = 0; /* Line 1794, Address: 0x1022ed0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1795, Address: 0x1022ed4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1799, Address: 0x1022ef0 */
  }





} /* Line 1806, Address: 0x1022f18 */



void mapinit() { /* Line 1810, Address: 0x1022f40 */

  colorset2(mapinittbl.colorno2); /* Line 1812, Address: 0x1022f48 */
  colorset(mapinittbl.colorno2); /* Line 1813, Address: 0x1022f5c */

  if (plflag) enecginit(); /* Line 1815, Address: 0x1022f70 */
  if (play_start & 2) divdevset(); /* Line 1816, Address: 0x1022f88 */
} /* Line 1817, Address: 0x1022fa8 */










void mapset() {} /* Line 1828, Address: 0x1022fc0 */
