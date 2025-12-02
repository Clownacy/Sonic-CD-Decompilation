#include "..\EQU.H"
#include "SCR71A.H"
#include "..\IMPFUNCS.H"
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
unsigned short scr_dir_tbl[6] = { 4, 0, 11927, 0, 1808, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 124, Address: 0x1024e20 */



void divdevset() {} /* Line 128, Address: 0x1024e30 */
















































void scr_set() { /* Line 177, Address: 0x1024e40 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 180, Address: 0x1024e4c */

  i = 0; /* Line 182, Address: 0x1024e94 */
  scrar_no = scr_dir_tbl[i++]; /* Line 183, Address: 0x1024e98 */
  scralim_left = scr_dir_tbl[i]; /* Line 184, Address: 0x1024ebc */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 185, Address: 0x1024ed8 */
  scralim_right = scr_dir_tbl[i]; /* Line 186, Address: 0x1024efc */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 187, Address: 0x1024f18 */
  scralim_up = scr_dir_tbl[i]; /* Line 188, Address: 0x1024f3c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 189, Address: 0x1024f58 */
  scralim_down = scr_dir_tbl[i]; /* Line 190, Address: 0x1024f7c */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 191, Address: 0x1024f98 */

  scra_h_keep = scralim_left + 576; /* Line 193, Address: 0x1024fbc */
  scra_h_count = 16; /* Line 194, Address: 0x1024fe0 */
  scra_v_count = 16; /* Line 195, Address: 0x1024fec */

  scra_vline = scr_dir_tbl[i++]; /* Line 197, Address: 0x1024ff8 */
  scra_hline = 160; /* Line 198, Address: 0x102501c */

  playposiset(); /* Line 200, Address: 0x1025028 */
} /* Line 201, Address: 0x1025030 */



void playposiset() { /* Line 205, Address: 0x1025050 */
  unsigned short playpositbl[2] = { /* Line 206, Address: 0x1025064 */
    64,
    652
  };
  unsigned char playmapnotbl[4] = { /* Line 210, Address: 0x1025080 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 218, Address: 0x10250ac */

    playload(); /* Line 220, Address: 0x10250c0 */
    xWk = actwk[0].xposi.w.h; /* Line 221, Address: 0x10250c8 */
    yWk = actwk[0].yposi.w.h; /* Line 222, Address: 0x10250d8 */
    if (yWk < 0) yWk = 0; /* Line 223, Address: 0x10250e8 */
  } /* Line 224, Address: 0x10250fc */
  else {


    i = 0; /* Line 228, Address: 0x1025104 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x1025108 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 230, Address: 0x102512c */
  }

  if ((unsigned short)xWk > 160) { /* Line 233, Address: 0x1025150 */
    xWk -= 160; /* Line 234, Address: 0x1025164 */
  } /* Line 235, Address: 0x1025170 */
  else {
    xWk = 0; /* Line 237, Address: 0x1025178 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 241, Address: 0x102517c */
    xWk = scralim_right; /* Line 242, Address: 0x10251a0 */
  }
  scra_h_posit.w.h = xWk; /* Line 244, Address: 0x10251b0 */

  if ((unsigned short)yWk > 96) { /* Line 246, Address: 0x10251b8 */
    yWk -= 96; /* Line 247, Address: 0x10251cc */
  } /* Line 248, Address: 0x10251d8 */
  else {
    yWk = 0; /* Line 250, Address: 0x10251e0 */
  }

  if (scralim_down < yWk) { /* Line 253, Address: 0x10251e4 */
    yWk = scralim_down; /* Line 254, Address: 0x1025208 */
  }

  scra_v_posit.w.h = yWk; /* Line 257, Address: 0x1025218 */

  scrbinit(yWk, xWk); /* Line 259, Address: 0x1025220 */

  i = 0; /* Line 261, Address: 0x1025230 */
  loopmapno = playmapnotbl[i++]; /* Line 262, Address: 0x1025234 */
  loopmapno2 = playmapnotbl[i++]; /* Line 263, Address: 0x102524c */
  ballmapno = playmapnotbl[i++]; /* Line 264, Address: 0x1025264 */
  ballmapno2 = playmapnotbl[i++]; /* Line 265, Address: 0x102527c */


} /* Line 268, Address: 0x1025294 */



void scrbinit(short yWk, short xWk) { /* Line 272, Address: 0x10252b0 */
  uint_union data;


  data.l = 0; /* Line 276, Address: 0x10252bc */
  data.w.h = yWk; /* Line 277, Address: 0x10252c0 */
  data.l = (data.l >> 2) + (data.l >> 5); /* Line 278, Address: 0x10252c8 */
  scrb_v_posit.l = data.w.l; /* Line 279, Address: 0x10252e0 */
  scrc_v_posit.w.h = data.w.h; /* Line 280, Address: 0x10252f0 */
  scrz_v_posit.w.h = data.w.h; /* Line 281, Address: 0x10252fc */

  scrc_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 283, Address: 0x1025308 */
  scrz_h_posit.w.h = (unsigned short)(xWk >> 2); /* Line 284, Address: 0x102532c */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 285, Address: 0x1025350 */
} /* Line 286, Address: 0x102537c */



void scroll() { /* Line 290, Address: 0x1025390 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 295, Address: 0x10253a0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 298, Address: 0x10253b0 */
  scrchk(); /* Line 299, Address: 0x10253dc */
  scroll_h(); /* Line 300, Address: 0x10253e4 */
  scroll_v(); /* Line 301, Address: 0x10253ec */

  vscroll.w.h = scra_v_posit.w.h; /* Line 303, Address: 0x10253f4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 304, Address: 0x1025404 */



  scrollz_h(scra_hz << 6, 64); /* Line 308, Address: 0x1025414 */
  scrollc_h(scra_hz << 7, 16); /* Line 309, Address: 0x1025434 */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 310, Address: 0x1025454 */

  data.l = 0; /* Line 312, Address: 0x102548c */
  data.w.l = scra_v_posit.w.h; /* Line 313, Address: 0x1025490 */
  data.w.l = (data.w.l >> 2) + (data.w.l >> 5); /* Line 314, Address: 0x102549c */
  scrollb_v(data.w.l); /* Line 315, Address: 0x10254c0 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 317, Address: 0x10254cc */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x10254dc */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 319, Address: 0x10254ec */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 320, Address: 0x10254fc */
  scrflagz.b.h = 0; /* Line 321, Address: 0x1025530 */
  scrflagc.b.h = 0; /* Line 322, Address: 0x1025538 */

  hsCount = 0; /* Line 324, Address: 0x1025540 */


  hsCount = z71aline(hsCount); /* Line 327, Address: 0x1025544 */

  for (i = 0; i < 4; ++i) { /* Line 329, Address: 0x1025554 */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 331, Address: 0x1025560 */
    ++hsCount; /* Line 332, Address: 0x1025590 */
  } /* Line 333, Address: 0x1025594 */

  hsCount = z71aline0(hsCount); /* Line 335, Address: 0x10255a4 */

  for (i = 0; i < 16; ++i) { /* Line 337, Address: 0x10255b4 */

    hscrollwork[hsCount] = -scrz_h_posit.w.h; /* Line 339, Address: 0x10255c0 */
    ++hsCount; /* Line 340, Address: 0x10255f0 */
  } /* Line 341, Address: 0x10255f4 */

  hsCount = z71aline1(hsCount); /* Line 343, Address: 0x1025604 */



  data.w.l = scrb_v_posit.w.h; /* Line 347, Address: 0x1025614 */
  data.w.l &= 1016; /* Line 348, Address: 0x1025620 */
  data.w.l >>= 2; /* Line 349, Address: 0x102562c */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 350, Address: 0x1025638 */
} /* Line 351, Address: 0x102566c */



static int z71aline(int hsCount) { /* Line 355, Address: 0x1025690 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[37] = { /* Line 359, Address: 0x10256a4 */
    1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
  };

  temp = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 367, Address: 0x10256d0 */
  temp <<= 7; /* Line 368, Address: 0x10256f4 */
  temp /= 37; /* Line 369, Address: 0x10256f8 */
  temp <<= 9; /* Line 370, Address: 0x1025710 */
  data.l = 0; /* Line 371, Address: 0x1025714 */
  data.w.l = scrb_h_posit.w.h; /* Line 372, Address: 0x1025718 */
  hsCount += 44; /* Line 373, Address: 0x1025724 */
  for (i = 0; i < 37; ++i) { /* Line 374, Address: 0x1025730 */


    for (j = -1; j < z71ascrtbl[36 - i]; ++j) { /* Line 377, Address: 0x102573c */


      --hsCount; /* Line 380, Address: 0x1025748 */
      hscrollwork[hsCount] = -data.w.l; /* Line 381, Address: 0x1025754 */
    } /* Line 382, Address: 0x1025784 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 383, Address: 0x10257a8 */
    data.l += temp; /* Line 384, Address: 0x10257cc */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 385, Address: 0x10257d8 */
  } /* Line 386, Address: 0x10257fc */
  hsCount += 44; /* Line 387, Address: 0x102580c */
  return hsCount; /* Line 388, Address: 0x1025818 */
} /* Line 389, Address: 0x102581c */


static int z71aline0(int hsCount) { /* Line 392, Address: 0x1025840 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[12] = { /* Line 396, Address: 0x1025854 */
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 402, Address: 0x1025888 */
  temp <<= 7; /* Line 403, Address: 0x10258ac */
  temp /= 12; /* Line 404, Address: 0x10258b0 */
  temp <<= 9; /* Line 405, Address: 0x10258c8 */
  data.l = 0; /* Line 406, Address: 0x10258cc */
  data.w.l = scrb_h_posit.w.h; /* Line 407, Address: 0x10258d0 */
  for (i = 0; i < 12; ++i) { /* Line 408, Address: 0x10258dc */


    for (j = -1; j < z71ascrtbl0[11 - i]; ++j) { /* Line 411, Address: 0x10258e8 */


      hscrollwork[hsCount] = -data.w.l; /* Line 414, Address: 0x10258f4 */
      ++hsCount; /* Line 415, Address: 0x1025924 */
    } /* Line 416, Address: 0x1025930 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 417, Address: 0x1025954 */
    data.l += temp; /* Line 418, Address: 0x1025978 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 419, Address: 0x1025984 */
  } /* Line 420, Address: 0x10259a8 */
  return hsCount; /* Line 421, Address: 0x10259b8 */
} /* Line 422, Address: 0x10259bc */


static int z71aline1(int hsCount) { /* Line 425, Address: 0x10259e0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl1[2] = { /* Line 429, Address: 0x10259f4 */
    9,
    7
  };

  temp = scrc_h_posit.w.h - scra_h_posit.w.h; /* Line 434, Address: 0x1025a10 */
  temp <<= 7; /* Line 435, Address: 0x1025a34 */
  temp /= 8; /* Line 436, Address: 0x1025a38 */
  temp <<= 9; /* Line 437, Address: 0x1025a54 */
  data.l = 0; /* Line 438, Address: 0x1025a58 */
  data.w.l = scrc_h_posit.w.h; /* Line 439, Address: 0x1025a5c */
  for (i = 0; i < 2; ++i) { /* Line 440, Address: 0x1025a68 */


    for (j = -1; j < z71ascrtbl1[1 - i]; ++j) { /* Line 443, Address: 0x1025a74 */


      hscrollwork[hsCount] = -data.w.l; /* Line 446, Address: 0x1025a80 */
      ++hsCount; /* Line 447, Address: 0x1025ab0 */
    } /* Line 448, Address: 0x1025abc */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 449, Address: 0x1025ae0 */
    data.l += temp; /* Line 450, Address: 0x1025b04 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 451, Address: 0x1025b10 */
  } /* Line 452, Address: 0x1025b34 */
  return hsCount; /* Line 453, Address: 0x1025b44 */
} /* Line 454, Address: 0x1025b48 */



static void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 458, Address: 0x1025b60 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 466, Address: 0x1025b78 */








  VPosi &= 7; /* Line 475, Address: 0x1025b80 */
  hsw.l = 0; /* Line 476, Address: 0x1025b8c */
  hsw.w.l = hscrollwork[offs++]; /* Line 477, Address: 0x1025b90 */

  j = VPosi; /* Line 479, Address: 0x1025bb8 */
  while (j < 8) { /* Line 480, Address: 0x1025bc4 */

    pHScrollBuff->l = hsw.l; /* Line 482, Address: 0x1025bcc */
    ++pHScrollBuff; /* Line 483, Address: 0x1025bd4 */
    ++j; /* Line 484, Address: 0x1025bd8 */
  } /* Line 485, Address: 0x1025bdc */
  for (i = 0; i < 29; ++i) { /* Line 486, Address: 0x1025be8 */

    hsw.w.l = hscrollwork[offs++]; /* Line 488, Address: 0x1025bf4 */
    for (j = 0; j < 8; ++j) { /* Line 489, Address: 0x1025c1c */

      pHScrollBuff->l = hsw.l; /* Line 491, Address: 0x1025c28 */
      ++pHScrollBuff; /* Line 492, Address: 0x1025c30 */
    } /* Line 493, Address: 0x1025c34 */
  } /* Line 494, Address: 0x1025c44 */
} /* Line 495, Address: 0x1025c54 */











void scroll_h() { /* Line 507, Address: 0x1025c70 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 510, Address: 0x1025c7c */
  scrh_move(); /* Line 511, Address: 0x1025c88 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 512, Address: 0x1025c90 */
    scra_h_count ^= 16; /* Line 513, Address: 0x1025cc4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 514, Address: 0x1025cd8 */
      scrflaga.b.h |= 4; /* Line 515, Address: 0x1025d04 */
    } /* Line 516, Address: 0x1025d18 */
    else {

      scrflaga.b.h |= 8; /* Line 519, Address: 0x1025d20 */
    }
  }


} /* Line 524, Address: 0x1025d34 */

void scrh_move() { /* Line 526, Address: 0x1025d50 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 529, Address: 0x1025d5c */
  wD0 -= scra_h_posit.w.h; /* Line 530, Address: 0x1025d68 */
  wD0 -= scra_hline; /* Line 531, Address: 0x1025d7c */
  if (wD0 == 0) { /* Line 532, Address: 0x1025d90 */

    scra_hz = 0; /* Line 534, Address: 0x1025d9c */
  } /* Line 535, Address: 0x1025da4 */
  else if ((short)wD0 < 0) { /* Line 536, Address: 0x1025dac */
    left_check(wD0); /* Line 537, Address: 0x1025dc4 */
  } /* Line 538, Address: 0x1025dd0 */
  else {
    right_check(wD0); /* Line 540, Address: 0x1025dd8 */
  }

} /* Line 543, Address: 0x1025de4 */


void right_check(unsigned short wD0) { /* Line 546, Address: 0x1025e00 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 549, Address: 0x1025e0c */
    wD0 = 16; /* Line 550, Address: 0x1025e2c */
  }

  wD0 += scra_h_posit.w.h; /* Line 553, Address: 0x1025e34 */
  if (scralim_right < (short)wD0) { /* Line 554, Address: 0x1025e4c */
    wD0 = scralim_right; /* Line 555, Address: 0x1025e7c */
  }

  wD1 = wD0; /* Line 558, Address: 0x1025e88 */
  wD1 -= scra_h_posit.w.h; /* Line 559, Address: 0x1025e90 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 560, Address: 0x1025ea4 */
  scra_h_posit.w.h = wD0; /* Line 561, Address: 0x1025ed4 */
  scra_hz = wD1; /* Line 562, Address: 0x1025ee0 */

} /* Line 564, Address: 0x1025ee8 */


void left_check(unsigned short wD0) { /* Line 567, Address: 0x1025f00 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 570, Address: 0x1025f0c */
    wD0 = -16; /* Line 571, Address: 0x1025f2c */
  }

  wD0 += scra_h_posit.w.h; /* Line 574, Address: 0x1025f34 */
  if (scralim_left > (short)wD0) { /* Line 575, Address: 0x1025f4c */
    wD0 = scralim_left; /* Line 576, Address: 0x1025f7c */
  }

  wD1 = wD0; /* Line 579, Address: 0x1025f88 */
  wD1 -= scra_h_posit.w.h; /* Line 580, Address: 0x1025f90 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 581, Address: 0x1025fa4 */
  scra_h_posit.w.h = wD0; /* Line 582, Address: 0x1025fd4 */
  scra_hz = wD1; /* Line 583, Address: 0x1025fe0 */

} /* Line 585, Address: 0x1025fe8 */


















void scroll_v() { /* Line 604, Address: 0x1026000 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 607, Address: 0x102600c */
  if (actwk[0].cddat & 4) { /* Line 608, Address: 0x1026038 */
    wD0 -= 5; /* Line 609, Address: 0x1026050 */
  }

  if (actwk[0].cddat & 2) { /* Line 612, Address: 0x1026058 */
    wD0 += 32; /* Line 613, Address: 0x1026070 */
    if ((unsigned short)scra_vline > wD0) { /* Line 614, Address: 0x1026078 */
      wD0 -= scra_vline; /* Line 615, Address: 0x1026098 */
      sv_move_main2(wD0); /* Line 616, Address: 0x10260ac */
      return; /* Line 617, Address: 0x10260b8 */
    }
    wD0 -= scra_vline; /* Line 619, Address: 0x10260c0 */
    if (wD0 >= 64) { /* Line 620, Address: 0x10260d4 */
      wD0 -= 64; /* Line 621, Address: 0x10260e4 */
      sv_move_main2(wD0); /* Line 622, Address: 0x10260ec */
      return; /* Line 623, Address: 0x10260f8 */
    }
    wD0 -= 64; /* Line 625, Address: 0x1026100 */
    if (limmoveflag == 0) goto label1; /* Line 626, Address: 0x1026108 */
    sv_move_sub2(); /* Line 627, Address: 0x102611c */
    return; /* Line 628, Address: 0x1026124 */
  }




  wD0 -= scra_vline; /* Line 634, Address: 0x102612c */
  if (wD0) { /* Line 635, Address: 0x1026140 */
    sv_move_main(wD0); /* Line 636, Address: 0x1026148 */
    return; /* Line 637, Address: 0x1026154 */
  }
  if (limmoveflag == 0) { /* Line 639, Address: 0x102615c */
    sv_move_sub2(); /* Line 640, Address: 0x1026170 */
    return; /* Line 641, Address: 0x1026178 */
  }


label1:
  scra_vz = 0; /* Line 646, Address: 0x1026180 */

} /* Line 648, Address: 0x1026188 */





void sv_move_main(unsigned short wD0) { /* Line 654, Address: 0x10261a0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 657, Address: 0x10261b0 */
    sv_move_main1(wD0); /* Line 658, Address: 0x10261cc */
  } /* Line 659, Address: 0x10261d8 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 662, Address: 0x10261e0 */
    if ((short)wD1 < 0) { /* Line 663, Address: 0x10261ec */
      wD1 = -(short)wD1; /* Line 664, Address: 0x1026204 */
    }

    if (wD1 >= 2048) { /* Line 667, Address: 0x1026220 */
      sv_move_main2(wD0); /* Line 668, Address: 0x1026230 */
    } /* Line 669, Address: 0x102623c */
    else {
      if ((short)wD0 > 6) { /* Line 671, Address: 0x1026244 */
        sv_move_plus(1536); /* Line 672, Address: 0x1026264 */
      } /* Line 673, Address: 0x1026270 */
      else if ((short)wD0 < -6) { /* Line 674, Address: 0x1026278 */
        sv_move_minus(1536); /* Line 675, Address: 0x1026298 */
      } /* Line 676, Address: 0x10262a4 */
      else {
        sv_move_sub(wD0); /* Line 678, Address: 0x10262ac */
      }
    }
  }
} /* Line 682, Address: 0x10262b8 */



void sv_move_main1(unsigned short wD0) { /* Line 686, Address: 0x10262d0 */

  if ((short)wD0 > 2) { /* Line 688, Address: 0x10262dc */
    sv_move_plus(512); /* Line 689, Address: 0x10262fc */
  } /* Line 690, Address: 0x1026308 */
  else if ((short)wD0 < -2) { /* Line 691, Address: 0x1026310 */
    sv_move_minus(512); /* Line 692, Address: 0x1026330 */
  } /* Line 693, Address: 0x102633c */
  else {
    sv_move_sub(wD0); /* Line 695, Address: 0x1026344 */
  }

} /* Line 698, Address: 0x1026350 */


void sv_move_main2(unsigned short wD0) { /* Line 701, Address: 0x1026360 */

  if ((short)wD0 > 16) { /* Line 703, Address: 0x102636c */
    sv_move_plus(4096); /* Line 704, Address: 0x102638c */
  } /* Line 705, Address: 0x1026398 */
  else if ((short)wD0 < -16) { /* Line 706, Address: 0x10263a0 */
    sv_move_minus(4096); /* Line 707, Address: 0x10263c0 */
  } /* Line 708, Address: 0x10263cc */
  else {
    sv_move_sub(wD0); /* Line 710, Address: 0x10263d4 */
  }

} /* Line 713, Address: 0x10263e0 */


void sv_move_sub2() { /* Line 716, Address: 0x10263f0 */
  limmoveflag = 0; /* Line 717, Address: 0x10263f8 */
  sv_move_sub(0); /* Line 718, Address: 0x1026400 */
} /* Line 719, Address: 0x102640c */


void sv_move_sub(unsigned short wD0) { /* Line 722, Address: 0x1026420 */
  int_union lD1;

  lD1.w.h = 0; /* Line 725, Address: 0x102642c */
  lD1.w.l = wD0; /* Line 726, Address: 0x1026430 */
  lD1.l += scra_v_posit.w.h; /* Line 727, Address: 0x1026438 */
  if ((short)wD0 > 0) { /* Line 728, Address: 0x1026454 */
    scrv_down_ch(lD1); /* Line 729, Address: 0x1026470 */
  } /* Line 730, Address: 0x102647c */
  else {
    scrv_up_ch(lD1); /* Line 732, Address: 0x1026484 */
  }

} /* Line 735, Address: 0x1026490 */




void sv_move_minus(unsigned short wD1) { /* Line 740, Address: 0x10264a0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 744, Address: 0x10264b0 */
  lD1.l <<= 8; /* Line 745, Address: 0x10264cc */
  lD1.l += scra_v_posit.l; /* Line 746, Address: 0x10264d8 */

  wk = lD1.w.h; /* Line 748, Address: 0x10264ec */
  lD1.w.h = lD1.w.l; /* Line 749, Address: 0x10264f4 */
  lD1.w.l = wk; /* Line 750, Address: 0x10264fc */
  scrv_up_ch(lD1); /* Line 751, Address: 0x1026500 */
} /* Line 752, Address: 0x102650c */



void scrv_up_ch(int_union lD1) { /* Line 756, Address: 0x1026520 */
  if (scralim_up >= lD1.w.l) { /* Line 757, Address: 0x102652c */
    if (lD1.w.l < -255) { /* Line 758, Address: 0x1026554 */
      lD1.w.l &= 2047; /* Line 759, Address: 0x102656c */
      actwk[0].yposi.w.h &= 2047; /* Line 760, Address: 0x1026578 */
      scra_v_posit.w.h &= 2047; /* Line 761, Address: 0x102658c */
      scrb_v_posit.w.h &= 1023; /* Line 762, Address: 0x10265a0 */
    } /* Line 763, Address: 0x10265b4 */
    else {

      lD1.w.l = scralim_up; /* Line 766, Address: 0x10265bc */
    }
  }
  scrv_move(lD1); /* Line 769, Address: 0x10265c8 */

} /* Line 771, Address: 0x10265d4 */





void sv_move_plus(unsigned short wD1) { /* Line 777, Address: 0x10265f0 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 781, Address: 0x1026600 */
  lD1.w.l = wD1; /* Line 782, Address: 0x1026604 */
  lD1.l <<= 8; /* Line 783, Address: 0x102660c */
  lD1.l += scra_v_posit.l; /* Line 784, Address: 0x1026618 */

  wk = lD1.w.h; /* Line 786, Address: 0x102662c */
  lD1.w.h = lD1.w.l; /* Line 787, Address: 0x1026634 */
  lD1.w.l = wk; /* Line 788, Address: 0x102663c */

  scrv_down_ch(lD1); /* Line 790, Address: 0x1026640 */

} /* Line 792, Address: 0x102664c */



void scrv_down_ch(int_union lD1) { /* Line 796, Address: 0x1026660 */
  if (scralim_down <= lD1.w.l) { /* Line 797, Address: 0x102666c */
    lD1.w.l -= 2048; /* Line 798, Address: 0x1026694 */
    if (lD1.w.l > 0) { /* Line 799, Address: 0x10266a0 */
      actwk[0].yposi.w.h &= 2047; /* Line 800, Address: 0x10266b4 */
      scra_v_posit.w.h -= 2048; /* Line 801, Address: 0x10266c8 */
      scrb_v_posit.w.h &= 1023; /* Line 802, Address: 0x10266dc */
    } /* Line 803, Address: 0x10266f0 */
    else {
      lD1.w.l = scralim_down; /* Line 805, Address: 0x10266f8 */
    }
  }
  scrv_move(lD1); /* Line 808, Address: 0x1026704 */

} /* Line 810, Address: 0x1026710 */


void scrv_move(int_union lD1) { /* Line 813, Address: 0x1026720 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 816, Address: 0x1026730 */

  wk = lD1.w.h; /* Line 818, Address: 0x102673c */
  lD1.w.h = lD1.w.l; /* Line 819, Address: 0x1026744 */
  lD1.w.l = wk; /* Line 820, Address: 0x102674c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 822, Address: 0x1026750 */
  scra_v_posit.l = lD1.l; /* Line 823, Address: 0x1026778 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 826, Address: 0x1026784 */
    scra_v_count ^= 16; /* Line 827, Address: 0x10267b8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 828, Address: 0x10267cc */

      scrflaga.b.h |= 2; /* Line 830, Address: 0x10267f8 */
    } /* Line 831, Address: 0x102680c */
    else {
      scrflaga.b.h |= 1; /* Line 833, Address: 0x1026814 */
    }
  }


} /* Line 838, Address: 0x1026828 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 842, Address: 0x1026840 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 845, Address: 0x102684c */
  lD0.l += lD4.l; /* Line 846, Address: 0x102685c */
  scrb_h_posit.l = lD0.l; /* Line 847, Address: 0x102686c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 849, Address: 0x1026878 */

    scrb_h_count ^= 16; /* Line 851, Address: 0x10268ac */
    lD0.l -= lD2.l; /* Line 852, Address: 0x10268c0 */
    if ((long int)lD0.l < 0) { /* Line 853, Address: 0x10268d0 */
      scrflagb.b.h |= 4; /* Line 854, Address: 0x10268e4 */
    } /* Line 855, Address: 0x10268f8 */
    else {

      scrflagb.b.h |= 8; /* Line 858, Address: 0x1026900 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 863, Address: 0x1026914 */
  lD0.l += lD5.l; /* Line 864, Address: 0x1026924 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 865, Address: 0x1026934 */
  scrb_v_posit.l = lD0.l; /* Line 866, Address: 0x102694c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 868, Address: 0x1026958 */

    scrb_v_count ^= 16; /* Line 870, Address: 0x102698c */
    lD0.l -= lD3.l; /* Line 871, Address: 0x10269a0 */
    if ((long int)lD0.l < 0) { /* Line 872, Address: 0x10269b0 */
      scrflagb.b.h |= 1; /* Line 873, Address: 0x10269c4 */
    } /* Line 874, Address: 0x10269d8 */
    else {

      scrflagb.b.h |= 2; /* Line 877, Address: 0x10269e0 */
    }
  }


} /* Line 882, Address: 0x10269f4 */






void scrollb_v(unsigned short wD0) { /* Line 889, Address: 0x1026a00 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 892, Address: 0x1026a0c */
  scrb_v_posit.w.h = wD0; /* Line 893, Address: 0x1026a18 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 895, Address: 0x1026a24 */
    scrb_v_count ^= 16; /* Line 896, Address: 0x1026a50 */
    if ((short)wD3 > (short)wD0) { /* Line 897, Address: 0x1026a64 */
      scrflagb.b.h |= 1; /* Line 898, Address: 0x1026a94 */
    } /* Line 899, Address: 0x1026aa8 */
    else {

      scrflagb.b.h |= 2; /* Line 902, Address: 0x1026ab0 */
    }
  }


} /* Line 907, Address: 0x1026ac4 */



void scrollb_h(int lD4, int flagb) { /* Line 911, Address: 0x1026ae0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 915, Address: 0x1026af0 */
  lD0.l = lD2.l + lD4; /* Line 916, Address: 0x1026afc */
  scrb_h_posit.l = lD0.l; /* Line 917, Address: 0x1026b0c */

  lD1.w.h = lD0.w.l; /* Line 919, Address: 0x1026b18 */
  lD1.w.l = lD0.w.h; /* Line 920, Address: 0x1026b20 */
  lD1.w.l &= 16; /* Line 921, Address: 0x1026b28 */

  bD3 = scrb_h_count; /* Line 923, Address: 0x1026b34 */
  lD1.b.b4 ^= bD3; /* Line 924, Address: 0x1026b40 */
  if (!lD1.b.b4) { /* Line 925, Address: 0x1026b54 */
    scrb_h_count ^= 16; /* Line 926, Address: 0x1026b60 */
    lD0.l -= lD2.l; /* Line 927, Address: 0x1026b74 */
    if ((long int)lD0.l < 0) { /* Line 928, Address: 0x1026b84 */
      scrflagb.b.h |= flagb; /* Line 929, Address: 0x1026b98 */
    } /* Line 930, Address: 0x1026bb4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 933, Address: 0x1026bbc */
    }
  }


} /* Line 938, Address: 0x1026bdc */


void scrollc_h(int lD4, int flagc) { /* Line 941, Address: 0x1026bf0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 945, Address: 0x1026c00 */
  lD0.l = lD2.l + lD4; /* Line 946, Address: 0x1026c0c */
  scrc_h_posit.l = lD0.l; /* Line 947, Address: 0x1026c1c */

  lD1.w.h = lD0.w.l; /* Line 949, Address: 0x1026c28 */
  lD1.w.l = lD0.w.h; /* Line 950, Address: 0x1026c30 */
  lD1.w.l &= 16; /* Line 951, Address: 0x1026c38 */

  bD3 = scrc_h_count; /* Line 953, Address: 0x1026c44 */
  lD1.b.b4 ^= bD3; /* Line 954, Address: 0x1026c50 */
  if (!lD1.b.b4) { /* Line 955, Address: 0x1026c64 */
    scrc_h_count ^= 16; /* Line 956, Address: 0x1026c70 */
    lD0.l -= lD2.l; /* Line 957, Address: 0x1026c84 */
    if ((long int)lD0.l < 0) { /* Line 958, Address: 0x1026c94 */
      scrflagc.b.h |= flagc; /* Line 959, Address: 0x1026ca8 */
    } /* Line 960, Address: 0x1026cc4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 963, Address: 0x1026ccc */
    }
  }


} /* Line 968, Address: 0x1026cec */











void scrollz_h(int lD4, int flagz) { /* Line 980, Address: 0x1026d00 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 984, Address: 0x1026d10 */
  lD0.l = lD2.l + lD4; /* Line 985, Address: 0x1026d1c */
  scrz_h_posit.l = lD0.l; /* Line 986, Address: 0x1026d2c */

  lD1.w.h = lD0.w.l; /* Line 988, Address: 0x1026d38 */
  lD1.w.l = lD0.w.h; /* Line 989, Address: 0x1026d40 */
  lD1.w.l &= 16; /* Line 990, Address: 0x1026d48 */

  bD3 = scrz_h_count; /* Line 992, Address: 0x1026d54 */
  lD1.b.b4 ^= bD3; /* Line 993, Address: 0x1026d60 */
  if (!lD1.b.b4) { /* Line 994, Address: 0x1026d74 */
    scrz_h_count ^= 16; /* Line 995, Address: 0x1026d80 */
    lD0.l -= lD2.l; /* Line 996, Address: 0x1026d94 */
    if ((long int)lD0.l < 0) { /* Line 997, Address: 0x1026da4 */
      scrflagz.b.h |= flagz; /* Line 998, Address: 0x1026db8 */
    } /* Line 999, Address: 0x1026dd4 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1002, Address: 0x1026ddc */
    }
  }


} /* Line 1007, Address: 0x1026dfc */













void scrollwrtadva() { /* Line 1021, Address: 0x1026e10 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1027, Address: 0x1026e2c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1028, Address: 0x1026e30 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1029, Address: 0x1026e3c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1030, Address: 0x1026e48 */
  pScrFlag = &scrflagb.b.h; /* Line 1031, Address: 0x1026e50 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1032, Address: 0x1026e58 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1034, Address: 0x1026e6c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1035, Address: 0x1026e78 */
  pScrFlag = &scrflagc.b.h; /* Line 1036, Address: 0x1026e84 */
  scrollwrtc(); /* Line 1037, Address: 0x1026e8c */

} /* Line 1039, Address: 0x1026e94 */












void scrollwrt() { /* Line 1052, Address: 0x1026ec0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1061, Address: 0x1026ee0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1062, Address: 0x1026ee4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1063, Address: 0x1026ef0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1064, Address: 0x1026efc */
  pScrFlag = &scrflagbw.b.h; /* Line 1065, Address: 0x1026f04 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1066, Address: 0x1026f0c */

  VramBase = 16384; /* Line 1068, Address: 0x1026f20 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1069, Address: 0x1026f24 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1070, Address: 0x1026f30 */
  pMapWk = (unsigned char*)mapwka; /* Line 1071, Address: 0x1026f3c */
  pScrFlag = &scrflagaw.b.h; /* Line 1072, Address: 0x1026f44 */

  if (*pScrFlag) { /* Line 1074, Address: 0x1026f4c */
    if (*pScrFlag & 1) { /* Line 1075, Address: 0x1026f58 */
      *pScrFlag &= 254; /* Line 1076, Address: 0x1026f6c */

      lD4.l = -16; /* Line 1078, Address: 0x1026f78 */
      wD5 = 65520; /* Line 1079, Address: 0x1026f80 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1081, Address: 0x1026f88 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1083, Address: 0x1026fa8 */
    }




    if (*pScrFlag & 2) { /* Line 1089, Address: 0x1026fd4 */
      *pScrFlag &= 253; /* Line 1090, Address: 0x1026fe8 */

      lD4.l = 224; /* Line 1092, Address: 0x1026ff4 */
      wD5 = 65520; /* Line 1093, Address: 0x1026ffc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1094, Address: 0x1027004 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1096, Address: 0x1027024 */
    }




    if (*pScrFlag & 4) { /* Line 1102, Address: 0x1027050 */
      *pScrFlag &= 251; /* Line 1103, Address: 0x1027064 */

      lD4.l = -16; /* Line 1105, Address: 0x1027070 */
      wD5 = 65520; /* Line 1106, Address: 0x1027078 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1107, Address: 0x1027080 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1109, Address: 0x10270a0 */
    }




    if (*pScrFlag & 8) { /* Line 1115, Address: 0x10270cc */
      *pScrFlag &= 247; /* Line 1116, Address: 0x10270e0 */

      lD4.l = -16; /* Line 1118, Address: 0x10270ec */
      wD5 = 320; /* Line 1119, Address: 0x10270f4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1120, Address: 0x10270fc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1122, Address: 0x102711c */
    }
  }






} /* Line 1131, Address: 0x1027148 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1148, Address: 0x1027170 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1159, Address: 0x102719c */

  if (*pScrFlag & 1) { /* Line 1161, Address: 0x10271a4 */
    *pScrFlag &= 254; /* Line 1162, Address: 0x10271bc */
  } /* Line 1163, Address: 0x10271d0 */
  else {
    *pScrFlag &= 254; /* Line 1165, Address: 0x10271d8 */

    if (*pScrFlag & 2) { /* Line 1167, Address: 0x10271ec */
      *pScrFlag &= 253; /* Line 1168, Address: 0x1027204 */
      lD4.w.l = 224; /* Line 1169, Address: 0x1027218 */
    } /* Line 1170, Address: 0x1027220 */
    else {
      *pScrFlag &= 253; /* Line 1172, Address: 0x1027228 */
      goto label1; /* Line 1173, Address: 0x102723c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1178, Address: 0x1027244 */
  wD0 &= 127; /* Line 1179, Address: 0x1027294 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1180, Address: 0x102729c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1186, Address: 0x10272bc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1187, Address: 0x10272dc */
  if (wD0 != 0) { /* Line 1188, Address: 0x1027300 */
    wD5 = 65520; /* Line 1189, Address: 0x102730c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1190, Address: 0x1027314 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1192, Address: 0x1027334 */



  } /* Line 1196, Address: 0x1027360 */
  else {

    wD5 = 0; /* Line 1199, Address: 0x1027368 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1200, Address: 0x102736c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1204, Address: 0x102738c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1211, Address: 0x10273b8 */






    lD4.l = -16; /* Line 1218, Address: 0x10273cc */
    wD5 = 65520; /* Line 1219, Address: 0x10273d4 */
    if (*pScrFlag & 168) { /* Line 1220, Address: 0x10273dc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1221, Address: 0x10273f4 */
      wD5 = 320; /* Line 1222, Address: 0x1027414 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1226, Address: 0x102741c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1228, Address: 0x102744c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1229, Address: 0x1027458 */



    for (i = 0; i < 16; ++i) { /* Line 1233, Address: 0x1027468 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1234, Address: 0x1027474 */
      if (wD0 != 0) { /* Line 1235, Address: 0x1027494 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1236, Address: 0x10274a0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1237, Address: 0x10274cc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1238, Address: 0x10274ec */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1240, Address: 0x1027510 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1243, Address: 0x1027534 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1245, Address: 0x1027554 */
        }
      }
      lD4.w.l += 16; /* Line 1248, Address: 0x1027568 */
    } /* Line 1249, Address: 0x1027574 */
    *pScrFlag = 0; /* Line 1250, Address: 0x1027584 */
  }
} /* Line 1252, Address: 0x102758c */





void scrollwrtc() {} /* Line 1258, Address: 0x10275c0 */




void scrollwrtz() {} /* Line 1263, Address: 0x10275d0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1281, Address: 0x10275e0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1294, Address: 0x1027608 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1297, Address: 0x1027628 */
    pTilePoint->x += 2; /* Line 1298, Address: 0x102763c */
    if (pTilePoint->x >= 64) { /* Line 1299, Address: 0x1027650 */
      pTilePoint->x -= 64; /* Line 1300, Address: 0x1027664 */
    }
    xOffs += 16; /* Line 1302, Address: 0x1027678 */
  } while (--lpcnt >= 0); /* Line 1303, Address: 0x1027684 */
} /* Line 1304, Address: 0x1027698 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1308, Address: 0x10276b0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1312, Address: 0x10276d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1315, Address: 0x10276f8 */
    pTilePoint->x += 2; /* Line 1316, Address: 0x102770c */
    if (pTilePoint->x >= 64) { /* Line 1317, Address: 0x1027720 */
      pTilePoint->x -= 64; /* Line 1318, Address: 0x1027734 */
    }
    xOffs += 16; /* Line 1320, Address: 0x1027748 */
  } while (--lpcnt >= 0); /* Line 1321, Address: 0x1027754 */
} /* Line 1322, Address: 0x1027768 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1342, Address: 0x1027780 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1346, Address: 0x10277a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1349, Address: 0x10277c8 */
    pTilePoint->y += 2; /* Line 1350, Address: 0x10277dc */
    if (pTilePoint->y >= 32) { /* Line 1351, Address: 0x10277ec */
      pTilePoint->y -= 32; /* Line 1352, Address: 0x1027800 */
    }
    yOffs += 16; /* Line 1354, Address: 0x1027810 */
  } while (--lpcnt >= 0); /* Line 1355, Address: 0x102781c */
} /* Line 1356, Address: 0x1027830 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1375, Address: 0x1027840 */
  int base = 0; /* Line 1376, Address: 0x1027874 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1381, Address: 0x1027878 */

    base = 1; /* Line 1383, Address: 0x1027888 */
  } /* Line 1384, Address: 0x102788c */
  else if (VramBase == 16384) { /* Line 1385, Address: 0x1027894 */

    base = 0; /* Line 1387, Address: 0x10278a4 */
  }
  x = pTilePoint->x; /* Line 1389, Address: 0x10278a8 */
  y = pTilePoint->y; /* Line 1390, Address: 0x10278b0 */


  frip = BlkIndex & 6144; /* Line 1393, Address: 0x10278b8 */
  BlkIndex &= 1023; /* Line 1394, Address: 0x10278c0 */
  if (frip == 6144) { /* Line 1395, Address: 0x10278cc */

    p0 = 3, p1 = 2; /* Line 1397, Address: 0x10278d8 */
    p2 = 1, p3 = 0; /* Line 1398, Address: 0x10278e0 */
  } /* Line 1399, Address: 0x10278e8 */
  else if (frip & 4096) { /* Line 1400, Address: 0x10278f0 */

    p0 = 2, p1 = 3; /* Line 1402, Address: 0x10278fc */
    p2 = 0, p3 = 1; /* Line 1403, Address: 0x1027904 */
  } /* Line 1404, Address: 0x102790c */
  else if (frip & 2048) { /* Line 1405, Address: 0x1027914 */

    p0 = 1, p1 = 0; /* Line 1407, Address: 0x1027920 */
    p2 = 3, p3 = 2; /* Line 1408, Address: 0x1027928 */
  } /* Line 1409, Address: 0x1027930 */
  else {

    p0 = 0, p1 = 1; /* Line 1412, Address: 0x1027938 */
    p2 = 2, p3 = 3; /* Line 1413, Address: 0x1027940 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1416, Address: 0x1027948 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1417, Address: 0x102798c */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1418, Address: 0x10279d0 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1419, Address: 0x1027a14 */

} /* Line 1421, Address: 0x1027a58 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1439, Address: 0x1027a90 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1440, Address: 0x1027ab0 */
} /* Line 1441, Address: 0x1027ad0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1443, Address: 0x1027ae0 */
  wH_posiw = 0; /* Line 1444, Address: 0x1027b00 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1445, Address: 0x1027b04 */
} /* Line 1446, Address: 0x1027b24 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1453, Address: 0x1027b40 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1459, Address: 0x1027b70 */
  yOffs += wV_posiw; /* Line 1460, Address: 0x1027b80 */





  if ((short)xOffs < 0) /* Line 1466, Address: 0x1027b90 */
    xOffs = 0; /* Line 1467, Address: 0x1027bac */
  if ((short)yOffs < 0) /* Line 1468, Address: 0x1027bb0 */
    yOffs = 0; /* Line 1469, Address: 0x1027bcc */
  if ((short)xOffs >= 16384) /* Line 1470, Address: 0x1027bd0 */
    xOffs = 16383; /* Line 1471, Address: 0x1027bf0 */
  if ((short)yOffs >= 2048) /* Line 1472, Address: 0x1027bf8 */
    yOffs = 2047; /* Line 1473, Address: 0x1027c18 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1474, Address: 0x1027c20 */
  if (i < 0) i = 0; /* Line 1475, Address: 0x1027c68 */

  ScreenNo = pMapWk[i] & 127; /* Line 1477, Address: 0x1027c74 */

  if (ScreenNo) { /* Line 1479, Address: 0x1027c90 */




    xOffs &= 32767; /* Line 1484, Address: 0x1027c98 */
    yOffs &= 32767; /* Line 1485, Address: 0x1027ca4 */


    xBlk = xOffs; /* Line 1488, Address: 0x1027cb0 */
    xBlk %= 256; /* Line 1489, Address: 0x1027cb8 */
    xBlk /= 16; /* Line 1490, Address: 0x1027cd8 */
    yBlk = yOffs; /* Line 1491, Address: 0x1027cf4 */
    yBlk %= 256; /* Line 1492, Address: 0x1027cfc */
    yBlk /= 16; /* Line 1493, Address: 0x1027d1c */

    lpw = pmapwk; /* Line 1495, Address: 0x1027d38 */
    lpw += xBlk; /* Line 1496, Address: 0x1027d40 */
    lpw += yBlk * 16; /* Line 1497, Address: 0x1027d48 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1498, Address: 0x1027d54 */
    *pIndex = *lpw; /* Line 1499, Address: 0x1027d6c */

    return 1; /* Line 1501, Address: 0x1027d7c */
  }

  *pIndex = 0; /* Line 1504, Address: 0x1027d88 */
  return 0; /* Line 1505, Address: 0x1027d90 */
} /* Line 1506, Address: 0x1027d94 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1526, Address: 0x1027dc0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1534, Address: 0x1027de8 */
  if (ScreenNo) { /* Line 1535, Address: 0x1027e4c */





    xBlk = xOffs; /* Line 1541, Address: 0x1027e54 */
    xBlk %= 256; /* Line 1542, Address: 0x1027e5c */
    xBlk /= 16; /* Line 1543, Address: 0x1027e7c */
    yBlk = yOffs; /* Line 1544, Address: 0x1027e98 */
    yBlk %= 256; /* Line 1545, Address: 0x1027ea0 */
    yBlk /= 16; /* Line 1546, Address: 0x1027ec0 */


    lpw = pmapwk; /* Line 1549, Address: 0x1027edc */
    lpw += xBlk; /* Line 1550, Address: 0x1027ee4 */
    lpw += yBlk * 16; /* Line 1551, Address: 0x1027eec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1552, Address: 0x1027ef8 */
    *ppBlockNo = lpw; /* Line 1553, Address: 0x1027f10 */
    *pIndex = *lpw; /* Line 1554, Address: 0x1027f18 */




    return 1; /* Line 1559, Address: 0x1027f28 */
  }

  *pIndex = 0; /* Line 1562, Address: 0x1027f34 */
  return 0; /* Line 1563, Address: 0x1027f3c */
} /* Line 1564, Address: 0x1027f40 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1578, Address: 0x1027f60 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1585, Address: 0x1027f7c */
  pMapWk = (unsigned char*)mapwka; /* Line 1586, Address: 0x1027f80 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1587, Address: 0x1027f88 */
    *pBlockIndex = BlockNo; /* Line 1588, Address: 0x1027fac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1589, Address: 0x1027fb8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1590, Address: 0x1027fd0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1591, Address: 0x1027fe4 */
    }
  }


} /* Line 1596, Address: 0x1027ffc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1610, Address: 0x1028020 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1611, Address: 0x102802c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1612, Address: 0x1028058 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1613, Address: 0x10280a4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1614, Address: 0x10280d0 */

          return 0; /* Line 1616, Address: 0x102811c */
        }
      }
    }
  }

  return 1; /* Line 1622, Address: 0x1028128 */
} /* Line 1623, Address: 0x102812c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1640, Address: 0x1028140 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1641, Address: 0x102815c */

} /* Line 1643, Address: 0x1028178 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1645, Address: 0x1028190 */
  wH_posiw = 0; /* Line 1646, Address: 0x10281ac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1647, Address: 0x10281b0 */

} /* Line 1649, Address: 0x10281cc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1651, Address: 0x10281e0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1652, Address: 0x10281f4 */

} /* Line 1654, Address: 0x1028210 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1656, Address: 0x1028220 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1657, Address: 0x102823c */

} /* Line 1659, Address: 0x1028258 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1661, Address: 0x1028270 */
  xOffs += wH_posiw; /* Line 1662, Address: 0x1028288 */
  yOffs += wV_posiw; /* Line 1663, Address: 0x1028298 */
  yOffs &= 240; /* Line 1664, Address: 0x10282a8 */
  xOffs &= 496; /* Line 1665, Address: 0x10282b4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1667, Address: 0x10282c0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1668, Address: 0x10282ec */


} /* Line 1671, Address: 0x1028318 */















void mapwrt() { /* Line 1687, Address: 0x1028330 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1692, Address: 0x1028348 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1693, Address: 0x1028354 */
  pMapWk = (unsigned char*)mapwka; /* Line 1694, Address: 0x1028360 */
  VramBase = 16384; /* Line 1695, Address: 0x1028368 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1696, Address: 0x102836c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1700, Address: 0x1028384 */
  VramBase = 24576; /* Line 1701, Address: 0x102838c */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1702, Address: 0x1028390 */

} /* Line 1704, Address: 0x10283a0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1707, Address: 0x10283c0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1708, Address: 0x10283d8 */
} /* Line 1709, Address: 0x10283f8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1714, Address: 0x1028410 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1718, Address: 0x1028430 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1721, Address: 0x102844c */



    wD4 += 16; /* Line 1725, Address: 0x1028474 */
  } while ((short)--wD6 >= 0); /* Line 1726, Address: 0x1028480 */

} /* Line 1728, Address: 0x10284a8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1734, Address: 0x10284c0 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1739, Address: 0x10284dc */
  wD6 = 15; /* Line 1740, Address: 0x10284e4 */

  do {
    temp.l = 0; /* Line 1743, Address: 0x10284ec */
    temp.w.l = scrb_v_posit.w.h; /* Line 1744, Address: 0x10284f0 */
    wD0 = scrb_v_posit.w.h; /* Line 1745, Address: 0x10284fc */
    wD0 += wD4 & 496; /* Line 1746, Address: 0x1028508 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1747, Address: 0x102851c */
    wD4 += 16; /* Line 1748, Address: 0x102853c */
  } while ((short)--wD6 >= 0); /* Line 1749, Address: 0x1028544 */
} /* Line 1750, Address: 0x1028568 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1772, Address: 0x1028590 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1777, Address: 0x10285b8 */
  wD0 = pWrttbl[wD0]; /* Line 1778, Address: 0x10285c8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1780, Address: 0x10285e4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1781, Address: 0x1028608 */
  if (wD0) { /* Line 1782, Address: 0x1028630 */
    wD5 = 65520; /* Line 1783, Address: 0x102863c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1784, Address: 0x1028644 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1787, Address: 0x1028660 */



  } /* Line 1791, Address: 0x1028688 */
  else {

    wD5 = 0; /* Line 1794, Address: 0x1028690 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1795, Address: 0x1028694 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1799, Address: 0x10286b0 */
  }





} /* Line 1806, Address: 0x10286d8 */



void mapinit() { /* Line 1810, Address: 0x1028700 */

  colorset2(mapinittbl.colorno2); /* Line 1812, Address: 0x1028708 */
  colorset(mapinittbl.colorno2); /* Line 1813, Address: 0x102871c */

  if (plflag) enecginit(); /* Line 1815, Address: 0x1028730 */
  if (play_start & 2) divdevset(); /* Line 1816, Address: 0x1028748 */
} /* Line 1817, Address: 0x1028768 */










void mapset() {} /* Line 1828, Address: 0x1028780 */
