#include "..\EQU.H"
#include "SCR71A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL7A.H"

static int z71aline(int hsCount);
static int z71aline0(int hsCount);
static void zonescrsetsub0(short VPosi, unsigned short offs);

static unsigned char z81awrttbl[65] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  2, 2, 2, 2, 0, 0, 0, 0, 0, 0,
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
unsigned short scr_dir_tbl[6] = { 4, 0, 16023, 0, 1296, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 123, Address: 0x1025220 */



void divdevset() {} /* Line 127, Address: 0x1025230 */
















































void scr_set() { /* Line 176, Address: 0x1025240 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 179, Address: 0x102524c */

  i = 0; /* Line 181, Address: 0x1025294 */
  scrar_no = scr_dir_tbl[i++]; /* Line 182, Address: 0x1025298 */
  scralim_left = scr_dir_tbl[i]; /* Line 183, Address: 0x10252bc */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 184, Address: 0x10252d8 */
  scralim_right = scr_dir_tbl[i]; /* Line 185, Address: 0x10252fc */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 186, Address: 0x1025318 */
  scralim_up = scr_dir_tbl[i]; /* Line 187, Address: 0x102533c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 188, Address: 0x1025358 */
  scralim_down = scr_dir_tbl[i]; /* Line 189, Address: 0x102537c */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 190, Address: 0x1025398 */

  scra_h_keep = scralim_left + 576; /* Line 192, Address: 0x10253bc */
  scra_h_count = 16; /* Line 193, Address: 0x10253e0 */
  scra_v_count = 16; /* Line 194, Address: 0x10253ec */

  scra_vline = scr_dir_tbl[i++]; /* Line 196, Address: 0x10253f8 */
  scra_hline = 160; /* Line 197, Address: 0x102541c */

  playposiset(); /* Line 199, Address: 0x1025428 */
} /* Line 200, Address: 0x1025430 */



void playposiset() { /* Line 204, Address: 0x1025450 */
  unsigned short playpositbl[2] = { /* Line 205, Address: 0x1025464 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 209, Address: 0x1025480 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 217, Address: 0x10254ac */

    playload(); /* Line 219, Address: 0x10254c0 */
    xWk = actwk[0].xposi.w.h; /* Line 220, Address: 0x10254c8 */
    yWk = actwk[0].yposi.w.h; /* Line 221, Address: 0x10254d8 */
    if (yWk < 0) yWk = 0; /* Line 222, Address: 0x10254e8 */
  } /* Line 223, Address: 0x10254fc */
  else {


    i = 0; /* Line 227, Address: 0x1025504 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 228, Address: 0x1025508 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x102552c */
  }

  if ((unsigned short)xWk > 160) { /* Line 232, Address: 0x1025550 */
    xWk -= 160; /* Line 233, Address: 0x1025564 */
  } /* Line 234, Address: 0x1025570 */
  else {
    xWk = 0; /* Line 236, Address: 0x1025578 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 240, Address: 0x102557c */
    xWk = scralim_right; /* Line 241, Address: 0x10255a0 */
  }
  scra_h_posit.w.h = xWk; /* Line 243, Address: 0x10255b0 */

  if ((unsigned short)yWk > 96) { /* Line 245, Address: 0x10255b8 */
    yWk -= 96; /* Line 246, Address: 0x10255cc */
  } /* Line 247, Address: 0x10255d8 */
  else {
    yWk = 0; /* Line 249, Address: 0x10255e0 */
  }

  if (scralim_down < yWk) { /* Line 252, Address: 0x10255e4 */
    yWk = scralim_down; /* Line 253, Address: 0x1025608 */
  }

  scra_v_posit.w.h = yWk; /* Line 256, Address: 0x1025618 */

  scrbinit(yWk, xWk); /* Line 258, Address: 0x1025620 */

  i = 0; /* Line 260, Address: 0x1025630 */
  loopmapno = playmapnotbl[i++]; /* Line 261, Address: 0x1025634 */
  loopmapno2 = playmapnotbl[i++]; /* Line 262, Address: 0x102564c */
  ballmapno = playmapnotbl[i++]; /* Line 263, Address: 0x1025664 */
  ballmapno2 = playmapnotbl[i++]; /* Line 264, Address: 0x102567c */


} /* Line 267, Address: 0x1025694 */



void scrbinit(short yWk, short xWk) { /* Line 271, Address: 0x10256b0 */
  uint_union data;


  data.l = 0; /* Line 275, Address: 0x10256bc */
  data.w.h = yWk; /* Line 276, Address: 0x10256c0 */
  scrb_v_posit.l = data.w.l; /* Line 277, Address: 0x10256c8 */
  scrc_v_posit.w.h = data.w.l; /* Line 278, Address: 0x10256d8 */
  scrz_v_posit.w.h = data.w.l; /* Line 279, Address: 0x10256e4 */

  scrc_h_posit.w.h = (unsigned short)((xWk >> 2) + (xWk >> 4)); /* Line 281, Address: 0x10256f0 */
  scrz_h_posit.w.h = (unsigned short)((xWk >> 3) + (xWk >> 4) + (xWk >> 5)); /* Line 282, Address: 0x1025728 */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 283, Address: 0x1025774 */
} /* Line 284, Address: 0x10257a0 */



void scroll() { /* Line 288, Address: 0x10257b0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 293, Address: 0x10257c0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 296, Address: 0x10257d0 */
  scrchk(); /* Line 297, Address: 0x10257fc */
  scroll_h(); /* Line 298, Address: 0x1025804 */
  scroll_v(); /* Line 299, Address: 0x102580c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 301, Address: 0x1025814 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 302, Address: 0x1025824 */



  scrollz_h((long int)(scra_hz << 5) * 7, 64); /* Line 306, Address: 0x1025834 */
  scrollc_h((long int)(scra_hz << 6) * 5, 16); /* Line 307, Address: 0x102586c */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 308, Address: 0x10258a4 */

  data.l = 0; /* Line 310, Address: 0x10258dc */
  data.w.l = scra_v_posit.w.h; /* Line 311, Address: 0x10258e0 */

  scrollb_v(data.w.l); /* Line 313, Address: 0x10258ec */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 315, Address: 0x10258f8 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 316, Address: 0x1025908 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 317, Address: 0x1025918 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 318, Address: 0x1025928 */
  scrflagz.b.h = 0; /* Line 319, Address: 0x102595c */
  scrflagc.b.h = 0; /* Line 320, Address: 0x1025964 */

  hsCount = 0; /* Line 322, Address: 0x102596c */


  hsCount = z71aline(hsCount); /* Line 325, Address: 0x1025970 */

  for (i = 0; i < 8; ++i) { /* Line 327, Address: 0x1025980 */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 329, Address: 0x102598c */
    ++hsCount; /* Line 330, Address: 0x10259bc */
  } /* Line 331, Address: 0x10259c0 */

  hsCount = z71aline0(hsCount); /* Line 333, Address: 0x10259d0 */

  for (i = 0; i < 16; ++i) { /* Line 335, Address: 0x10259e0 */

    hscrollwork[hsCount] = -scrz_h_posit.w.h; /* Line 337, Address: 0x10259ec */
    ++hsCount; /* Line 338, Address: 0x1025a1c */
  } /* Line 339, Address: 0x1025a20 */

  for (i = 0; i < 18; ++i) { /* Line 341, Address: 0x1025a30 */

    hscrollwork[hsCount] = -scrc_h_posit.w.h; /* Line 343, Address: 0x1025a3c */
    ++hsCount; /* Line 344, Address: 0x1025a6c */
  } /* Line 345, Address: 0x1025a70 */





  data.w.l = scrb_v_posit.w.h; /* Line 351, Address: 0x1025a80 */
  data.w.l &= 1016; /* Line 352, Address: 0x1025a8c */
  data.w.l >>= 2; /* Line 353, Address: 0x1025a98 */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 354, Address: 0x1025aa4 */
} /* Line 355, Address: 0x1025ad8 */



int z71aline(int hsCount) { /* Line 359, Address: 0x1025af0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[16] = { /* Line 363, Address: 0x1025b04 */
    3, 3, 1, 1, 0, 0,
    3, 3, 1, 3, 1, 1,
    1, 1, 0, 0
  };

  temp = scra_h_posit.w.h * 2 - scrb_h_posit.w.h; /* Line 369, Address: 0x1025b38 */
  temp <<= 5; /* Line 370, Address: 0x1025b60 */
  temp /= 16; /* Line 371, Address: 0x1025b64 */
  temp <<= 11; /* Line 372, Address: 0x1025b80 */
  data.l = 0; /* Line 373, Address: 0x1025b84 */
  data.w.l = scrb_h_posit.w.h; /* Line 374, Address: 0x1025b88 */
  hsCount += 38; /* Line 375, Address: 0x1025b94 */
  for (i = 0; i < 16; ++i) { /* Line 376, Address: 0x1025ba0 */


    for (j = -1; j < z71ascrtbl[15 - i]; ++j) { /* Line 379, Address: 0x1025bac */


      --hsCount; /* Line 382, Address: 0x1025bb8 */
      hscrollwork[hsCount] = -data.w.l; /* Line 383, Address: 0x1025bc4 */
    } /* Line 384, Address: 0x1025bf4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 385, Address: 0x1025c18 */
    data.l += temp; /* Line 386, Address: 0x1025c3c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 387, Address: 0x1025c48 */
  } /* Line 388, Address: 0x1025c6c */
  hsCount += 38; /* Line 389, Address: 0x1025c7c */
  return hsCount; /* Line 390, Address: 0x1025c88 */
} /* Line 391, Address: 0x1025c8c */


int z71aline0(int hsCount) { /* Line 394, Address: 0x1025cb0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[11] = { /* Line 398, Address: 0x1025cc4 */
    1, 1, 1, 1,
    1, 0, 0, 0,
    0, 0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 404, Address: 0x1025cf0 */
  temp <<= 5; /* Line 405, Address: 0x1025d14 */
  temp /= 11; /* Line 406, Address: 0x1025d18 */
  temp <<= 11; /* Line 407, Address: 0x1025d30 */
  data.l = 0; /* Line 408, Address: 0x1025d34 */
  data.w.l = scrb_h_posit.w.h; /* Line 409, Address: 0x1025d38 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 410, Address: 0x1025d44 */
  data.l += temp; /* Line 411, Address: 0x1025d68 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 412, Address: 0x1025d74 */
  for (i = 0; i < 11; ++i) { /* Line 413, Address: 0x1025d98 */


    for (j = -1; j < z71ascrtbl0[10 - i]; ++j) { /* Line 416, Address: 0x1025da4 */


      hscrollwork[hsCount] = -data.w.l; /* Line 419, Address: 0x1025db0 */
      ++hsCount; /* Line 420, Address: 0x1025de0 */
    } /* Line 421, Address: 0x1025dec */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 422, Address: 0x1025e10 */
    data.l += temp; /* Line 423, Address: 0x1025e34 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 424, Address: 0x1025e40 */
  } /* Line 425, Address: 0x1025e64 */
  return hsCount; /* Line 426, Address: 0x1025e74 */
} /* Line 427, Address: 0x1025e78 */




void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 432, Address: 0x1025e90 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 440, Address: 0x1025ea8 */








  VPosi &= 7; /* Line 449, Address: 0x1025eb0 */
  hsw.l = 0; /* Line 450, Address: 0x1025ebc */
  hsw.w.l = hscrollwork[offs++]; /* Line 451, Address: 0x1025ec0 */

  j = VPosi; /* Line 453, Address: 0x1025ee8 */
  while (j < 8) { /* Line 454, Address: 0x1025ef4 */

    pHScrollBuff->l = hsw.l; /* Line 456, Address: 0x1025efc */
    ++pHScrollBuff; /* Line 457, Address: 0x1025f04 */
    ++j; /* Line 458, Address: 0x1025f08 */
  } /* Line 459, Address: 0x1025f0c */
  for (i = 0; i < 29; ++i) { /* Line 460, Address: 0x1025f18 */

    hsw.w.l = hscrollwork[offs++]; /* Line 462, Address: 0x1025f24 */
    for (j = 0; j < 8; ++j) { /* Line 463, Address: 0x1025f4c */

      pHScrollBuff->l = hsw.l; /* Line 465, Address: 0x1025f58 */
      ++pHScrollBuff; /* Line 466, Address: 0x1025f60 */
    } /* Line 467, Address: 0x1025f64 */
  } /* Line 468, Address: 0x1025f74 */
} /* Line 469, Address: 0x1025f84 */











void scroll_h() { /* Line 481, Address: 0x1025fa0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 484, Address: 0x1025fac */
  scrh_move(); /* Line 485, Address: 0x1025fb8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 486, Address: 0x1025fc0 */
    scra_h_count ^= 16; /* Line 487, Address: 0x1025ff4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 488, Address: 0x1026008 */
      scrflaga.b.h |= 4; /* Line 489, Address: 0x1026034 */
    } /* Line 490, Address: 0x1026048 */
    else {

      scrflaga.b.h |= 8; /* Line 493, Address: 0x1026050 */
    }
  }


} /* Line 498, Address: 0x1026064 */

void scrh_move() { /* Line 500, Address: 0x1026080 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 503, Address: 0x102608c */
  wD0 -= scra_h_posit.w.h; /* Line 504, Address: 0x1026098 */
  wD0 -= scra_hline; /* Line 505, Address: 0x10260ac */
  if (wD0 == 0) { /* Line 506, Address: 0x10260c0 */

    scra_hz = 0; /* Line 508, Address: 0x10260cc */
  } /* Line 509, Address: 0x10260d4 */
  else if ((short)wD0 < 0) { /* Line 510, Address: 0x10260dc */
    left_check(wD0); /* Line 511, Address: 0x10260f4 */
  } /* Line 512, Address: 0x1026100 */
  else {
    right_check(wD0); /* Line 514, Address: 0x1026108 */
  }

} /* Line 517, Address: 0x1026114 */


void right_check(unsigned short wD0) { /* Line 520, Address: 0x1026130 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 523, Address: 0x102613c */
    wD0 = 16; /* Line 524, Address: 0x102615c */
  }

  wD0 += scra_h_posit.w.h; /* Line 527, Address: 0x1026164 */
  if (scralim_right < (short)wD0) { /* Line 528, Address: 0x102617c */
    wD0 = scralim_right; /* Line 529, Address: 0x10261ac */
  }

  wD1 = wD0; /* Line 532, Address: 0x10261b8 */
  wD1 -= scra_h_posit.w.h; /* Line 533, Address: 0x10261c0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 534, Address: 0x10261d4 */
  scra_h_posit.w.h = wD0; /* Line 535, Address: 0x1026204 */
  scra_hz = wD1; /* Line 536, Address: 0x1026210 */

} /* Line 538, Address: 0x1026218 */


void left_check(unsigned short wD0) { /* Line 541, Address: 0x1026230 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 544, Address: 0x102623c */
    wD0 = -16; /* Line 545, Address: 0x102625c */
  }

  wD0 += scra_h_posit.w.h; /* Line 548, Address: 0x1026264 */
  if (scralim_left > (short)wD0) { /* Line 549, Address: 0x102627c */
    wD0 = scralim_left; /* Line 550, Address: 0x10262ac */
  }

  wD1 = wD0; /* Line 553, Address: 0x10262b8 */
  wD1 -= scra_h_posit.w.h; /* Line 554, Address: 0x10262c0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 555, Address: 0x10262d4 */
  scra_h_posit.w.h = wD0; /* Line 556, Address: 0x1026304 */
  scra_hz = wD1; /* Line 557, Address: 0x1026310 */

} /* Line 559, Address: 0x1026318 */


















void scroll_v() { /* Line 578, Address: 0x1026330 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 581, Address: 0x102633c */
  if (actwk[0].cddat & 4) { /* Line 582, Address: 0x1026368 */
    wD0 -= 5; /* Line 583, Address: 0x1026380 */
  }

  if (actwk[0].cddat & 2) { /* Line 586, Address: 0x1026388 */
    wD0 += 32; /* Line 587, Address: 0x10263a0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 588, Address: 0x10263a8 */
      wD0 -= scra_vline; /* Line 589, Address: 0x10263c8 */
      sv_move_main2(wD0); /* Line 590, Address: 0x10263dc */
      return; /* Line 591, Address: 0x10263e8 */
    }
    wD0 -= scra_vline; /* Line 593, Address: 0x10263f0 */
    if (wD0 >= 64) { /* Line 594, Address: 0x1026404 */
      wD0 -= 64; /* Line 595, Address: 0x1026414 */
      sv_move_main2(wD0); /* Line 596, Address: 0x102641c */
      return; /* Line 597, Address: 0x1026428 */
    }
    wD0 -= 64; /* Line 599, Address: 0x1026430 */
    if (limmoveflag == 0) goto label1; /* Line 600, Address: 0x1026438 */
    sv_move_sub2(); /* Line 601, Address: 0x102644c */
    return; /* Line 602, Address: 0x1026454 */
  }




  wD0 -= scra_vline; /* Line 608, Address: 0x102645c */
  if (wD0) { /* Line 609, Address: 0x1026470 */
    sv_move_main(wD0); /* Line 610, Address: 0x1026478 */
    return; /* Line 611, Address: 0x1026484 */
  }
  if (limmoveflag == 0) { /* Line 613, Address: 0x102648c */
    sv_move_sub2(); /* Line 614, Address: 0x10264a0 */
    return; /* Line 615, Address: 0x10264a8 */
  }


label1:
  scra_vz = 0; /* Line 620, Address: 0x10264b0 */

} /* Line 622, Address: 0x10264b8 */





void sv_move_main(unsigned short wD0) { /* Line 628, Address: 0x10264d0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 631, Address: 0x10264e0 */
    sv_move_main1(wD0); /* Line 632, Address: 0x10264fc */
  } /* Line 633, Address: 0x1026508 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 636, Address: 0x1026510 */
    if ((short)wD1 < 0) { /* Line 637, Address: 0x102651c */
      wD1 = -(short)wD1; /* Line 638, Address: 0x1026534 */
    }

    if (wD1 >= 2048) { /* Line 641, Address: 0x1026550 */
      sv_move_main2(wD0); /* Line 642, Address: 0x1026560 */
    } /* Line 643, Address: 0x102656c */
    else {
      if ((short)wD0 > 6) { /* Line 645, Address: 0x1026574 */
        sv_move_plus(1536); /* Line 646, Address: 0x1026594 */
      } /* Line 647, Address: 0x10265a0 */
      else if ((short)wD0 < -6) { /* Line 648, Address: 0x10265a8 */
        sv_move_minus(1536); /* Line 649, Address: 0x10265c8 */
      } /* Line 650, Address: 0x10265d4 */
      else {
        sv_move_sub(wD0); /* Line 652, Address: 0x10265dc */
      }
    }
  }
} /* Line 656, Address: 0x10265e8 */



void sv_move_main1(unsigned short wD0) { /* Line 660, Address: 0x1026600 */

  if ((short)wD0 > 2) { /* Line 662, Address: 0x102660c */
    sv_move_plus(512); /* Line 663, Address: 0x102662c */
  } /* Line 664, Address: 0x1026638 */
  else if ((short)wD0 < -2) { /* Line 665, Address: 0x1026640 */
    sv_move_minus(512); /* Line 666, Address: 0x1026660 */
  } /* Line 667, Address: 0x102666c */
  else {
    sv_move_sub(wD0); /* Line 669, Address: 0x1026674 */
  }

} /* Line 672, Address: 0x1026680 */


void sv_move_main2(unsigned short wD0) { /* Line 675, Address: 0x1026690 */

  if ((short)wD0 > 16) { /* Line 677, Address: 0x102669c */
    sv_move_plus(4096); /* Line 678, Address: 0x10266bc */
  } /* Line 679, Address: 0x10266c8 */
  else if ((short)wD0 < -16) { /* Line 680, Address: 0x10266d0 */
    sv_move_minus(4096); /* Line 681, Address: 0x10266f0 */
  } /* Line 682, Address: 0x10266fc */
  else {
    sv_move_sub(wD0); /* Line 684, Address: 0x1026704 */
  }

} /* Line 687, Address: 0x1026710 */


void sv_move_sub2() { /* Line 690, Address: 0x1026720 */
  limmoveflag = 0; /* Line 691, Address: 0x1026728 */
  sv_move_sub(0); /* Line 692, Address: 0x1026730 */
} /* Line 693, Address: 0x102673c */


void sv_move_sub(unsigned short wD0) { /* Line 696, Address: 0x1026750 */
  int_union lD1;

  lD1.w.h = 0; /* Line 699, Address: 0x102675c */
  lD1.w.l = wD0; /* Line 700, Address: 0x1026760 */
  lD1.l += scra_v_posit.w.h; /* Line 701, Address: 0x1026768 */
  if ((short)wD0 > 0) { /* Line 702, Address: 0x1026784 */
    scrv_down_ch(lD1); /* Line 703, Address: 0x10267a0 */
  } /* Line 704, Address: 0x10267ac */
  else {
    scrv_up_ch(lD1); /* Line 706, Address: 0x10267b4 */
  }

} /* Line 709, Address: 0x10267c0 */




void sv_move_minus(unsigned short wD1) { /* Line 714, Address: 0x10267d0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 718, Address: 0x10267e0 */
  lD1.l <<= 8; /* Line 719, Address: 0x10267fc */
  lD1.l += scra_v_posit.l; /* Line 720, Address: 0x1026808 */

  wk = lD1.w.h; /* Line 722, Address: 0x102681c */
  lD1.w.h = lD1.w.l; /* Line 723, Address: 0x1026824 */
  lD1.w.l = wk; /* Line 724, Address: 0x102682c */
  scrv_up_ch(lD1); /* Line 725, Address: 0x1026830 */
} /* Line 726, Address: 0x102683c */



void scrv_up_ch(int_union lD1) { /* Line 730, Address: 0x1026850 */
  if (scralim_up >= lD1.w.l) { /* Line 731, Address: 0x102685c */
    if (lD1.w.l < -255) { /* Line 732, Address: 0x1026884 */
      lD1.w.l &= 2047; /* Line 733, Address: 0x102689c */
      actwk[0].yposi.w.h &= 2047; /* Line 734, Address: 0x10268a8 */
      scra_v_posit.w.h &= 2047; /* Line 735, Address: 0x10268bc */
      scrb_v_posit.w.h &= 1023; /* Line 736, Address: 0x10268d0 */
    } /* Line 737, Address: 0x10268e4 */
    else {

      lD1.w.l = scralim_up; /* Line 740, Address: 0x10268ec */
    }
  }
  scrv_move(lD1); /* Line 743, Address: 0x10268f8 */

} /* Line 745, Address: 0x1026904 */





void sv_move_plus(unsigned short wD1) { /* Line 751, Address: 0x1026920 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 755, Address: 0x1026930 */
  lD1.w.l = wD1; /* Line 756, Address: 0x1026934 */
  lD1.l <<= 8; /* Line 757, Address: 0x102693c */
  lD1.l += scra_v_posit.l; /* Line 758, Address: 0x1026948 */

  wk = lD1.w.h; /* Line 760, Address: 0x102695c */
  lD1.w.h = lD1.w.l; /* Line 761, Address: 0x1026964 */
  lD1.w.l = wk; /* Line 762, Address: 0x102696c */

  scrv_down_ch(lD1); /* Line 764, Address: 0x1026970 */

} /* Line 766, Address: 0x102697c */



void scrv_down_ch(int_union lD1) { /* Line 770, Address: 0x1026990 */
  if (scralim_down <= lD1.w.l) { /* Line 771, Address: 0x102699c */
    lD1.w.l -= 2048; /* Line 772, Address: 0x10269c4 */
    if (lD1.w.l > 0) { /* Line 773, Address: 0x10269d0 */
      actwk[0].yposi.w.h &= 2047; /* Line 774, Address: 0x10269e4 */
      scra_v_posit.w.h -= 2048; /* Line 775, Address: 0x10269f8 */
      scrb_v_posit.w.h &= 1023; /* Line 776, Address: 0x1026a0c */
    } /* Line 777, Address: 0x1026a20 */
    else {
      lD1.w.l = scralim_down; /* Line 779, Address: 0x1026a28 */
    }
  }
  scrv_move(lD1); /* Line 782, Address: 0x1026a34 */

} /* Line 784, Address: 0x1026a40 */


void scrv_move(int_union lD1) { /* Line 787, Address: 0x1026a50 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 790, Address: 0x1026a60 */

  wk = lD1.w.h; /* Line 792, Address: 0x1026a6c */
  lD1.w.h = lD1.w.l; /* Line 793, Address: 0x1026a74 */
  lD1.w.l = wk; /* Line 794, Address: 0x1026a7c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 796, Address: 0x1026a80 */
  scra_v_posit.l = lD1.l; /* Line 797, Address: 0x1026aa8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 800, Address: 0x1026ab4 */
    scra_v_count ^= 16; /* Line 801, Address: 0x1026ae8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 802, Address: 0x1026afc */

      scrflaga.b.h |= 2; /* Line 804, Address: 0x1026b28 */
    } /* Line 805, Address: 0x1026b3c */
    else {
      scrflaga.b.h |= 1; /* Line 807, Address: 0x1026b44 */
    }
  }


} /* Line 812, Address: 0x1026b58 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 816, Address: 0x1026b70 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 819, Address: 0x1026b7c */
  lD0.l += lD4.l; /* Line 820, Address: 0x1026b8c */
  scrb_h_posit.l = lD0.l; /* Line 821, Address: 0x1026b9c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 823, Address: 0x1026ba8 */

    scrb_h_count ^= 16; /* Line 825, Address: 0x1026bdc */
    lD0.l -= lD2.l; /* Line 826, Address: 0x1026bf0 */
    if ((long int)lD0.l < 0) { /* Line 827, Address: 0x1026c00 */
      scrflagb.b.h |= 4; /* Line 828, Address: 0x1026c14 */
    } /* Line 829, Address: 0x1026c28 */
    else {

      scrflagb.b.h |= 8; /* Line 832, Address: 0x1026c30 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 837, Address: 0x1026c44 */
  lD0.l += lD5.l; /* Line 838, Address: 0x1026c54 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 839, Address: 0x1026c64 */
  scrb_v_posit.l = lD0.l; /* Line 840, Address: 0x1026c7c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 842, Address: 0x1026c88 */

    scrb_v_count ^= 16; /* Line 844, Address: 0x1026cbc */
    lD0.l -= lD3.l; /* Line 845, Address: 0x1026cd0 */
    if ((long int)lD0.l < 0) { /* Line 846, Address: 0x1026ce0 */
      scrflagb.b.h |= 1; /* Line 847, Address: 0x1026cf4 */
    } /* Line 848, Address: 0x1026d08 */
    else {

      scrflagb.b.h |= 2; /* Line 851, Address: 0x1026d10 */
    }
  }


} /* Line 856, Address: 0x1026d24 */






void scrollb_v(unsigned short wD0) { /* Line 863, Address: 0x1026d30 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 866, Address: 0x1026d3c */
  scrb_v_posit.w.h = wD0; /* Line 867, Address: 0x1026d48 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 869, Address: 0x1026d54 */
    scrb_v_count ^= 16; /* Line 870, Address: 0x1026d80 */
    if ((short)wD3 > (short)wD0) { /* Line 871, Address: 0x1026d94 */
      scrflagb.b.h |= 1; /* Line 872, Address: 0x1026dc4 */
    } /* Line 873, Address: 0x1026dd8 */
    else {

      scrflagb.b.h |= 2; /* Line 876, Address: 0x1026de0 */
    }
  }


} /* Line 881, Address: 0x1026df4 */



void scrollb_h(int lD4, int flagb) { /* Line 885, Address: 0x1026e10 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 889, Address: 0x1026e20 */
  lD0.l = lD2.l + lD4; /* Line 890, Address: 0x1026e2c */
  scrb_h_posit.l = lD0.l; /* Line 891, Address: 0x1026e3c */

  lD1.w.h = lD0.w.l; /* Line 893, Address: 0x1026e48 */
  lD1.w.l = lD0.w.h; /* Line 894, Address: 0x1026e50 */
  lD1.w.l &= 16; /* Line 895, Address: 0x1026e58 */

  bD3 = scrb_h_count; /* Line 897, Address: 0x1026e64 */
  lD1.b.b4 ^= bD3; /* Line 898, Address: 0x1026e70 */
  if (!lD1.b.b4) { /* Line 899, Address: 0x1026e84 */
    scrb_h_count ^= 16; /* Line 900, Address: 0x1026e90 */
    lD0.l -= lD2.l; /* Line 901, Address: 0x1026ea4 */
    if ((long int)lD0.l < 0) { /* Line 902, Address: 0x1026eb4 */
      scrflagb.b.h |= flagb; /* Line 903, Address: 0x1026ec8 */
    } /* Line 904, Address: 0x1026ee4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 907, Address: 0x1026eec */
    }
  }


} /* Line 912, Address: 0x1026f0c */


void scrollc_h(int lD4, int flagc) { /* Line 915, Address: 0x1026f20 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 919, Address: 0x1026f30 */
  lD0.l = lD2.l + lD4; /* Line 920, Address: 0x1026f3c */
  scrc_h_posit.l = lD0.l; /* Line 921, Address: 0x1026f4c */

  lD1.w.h = lD0.w.l; /* Line 923, Address: 0x1026f58 */
  lD1.w.l = lD0.w.h; /* Line 924, Address: 0x1026f60 */
  lD1.w.l &= 16; /* Line 925, Address: 0x1026f68 */

  bD3 = scrc_h_count; /* Line 927, Address: 0x1026f74 */
  lD1.b.b4 ^= bD3; /* Line 928, Address: 0x1026f80 */
  if (!lD1.b.b4) { /* Line 929, Address: 0x1026f94 */
    scrc_h_count ^= 16; /* Line 930, Address: 0x1026fa0 */
    lD0.l -= lD2.l; /* Line 931, Address: 0x1026fb4 */
    if ((long int)lD0.l < 0) { /* Line 932, Address: 0x1026fc4 */
      scrflagc.b.h |= flagc; /* Line 933, Address: 0x1026fd8 */
    } /* Line 934, Address: 0x1026ff4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 937, Address: 0x1026ffc */
    }
  }


} /* Line 942, Address: 0x102701c */











void scrollz_h(int lD4, int flagz) { /* Line 954, Address: 0x1027030 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 958, Address: 0x1027040 */
  lD0.l = lD2.l + lD4; /* Line 959, Address: 0x102704c */
  scrz_h_posit.l = lD0.l; /* Line 960, Address: 0x102705c */

  lD1.w.h = lD0.w.l; /* Line 962, Address: 0x1027068 */
  lD1.w.l = lD0.w.h; /* Line 963, Address: 0x1027070 */
  lD1.w.l &= 16; /* Line 964, Address: 0x1027078 */

  bD3 = scrz_h_count; /* Line 966, Address: 0x1027084 */
  lD1.b.b4 ^= bD3; /* Line 967, Address: 0x1027090 */
  if (!lD1.b.b4) { /* Line 968, Address: 0x10270a4 */
    scrz_h_count ^= 16; /* Line 969, Address: 0x10270b0 */
    lD0.l -= lD2.l; /* Line 970, Address: 0x10270c4 */
    if ((long int)lD0.l < 0) { /* Line 971, Address: 0x10270d4 */
      scrflagz.b.h |= flagz; /* Line 972, Address: 0x10270e8 */
    } /* Line 973, Address: 0x1027104 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 976, Address: 0x102710c */
    }
  }


} /* Line 981, Address: 0x102712c */













void scrollwrtadva() { /* Line 995, Address: 0x1027140 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1001, Address: 0x102715c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1002, Address: 0x1027160 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1003, Address: 0x102716c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1004, Address: 0x1027178 */
  pScrFlag = &scrflagb.b.h; /* Line 1005, Address: 0x1027180 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1006, Address: 0x1027188 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1008, Address: 0x102719c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1009, Address: 0x10271a8 */
  pScrFlag = &scrflagc.b.h; /* Line 1010, Address: 0x10271b4 */
  scrollwrtc(); /* Line 1011, Address: 0x10271bc */

} /* Line 1013, Address: 0x10271c4 */












void scrollwrt() { /* Line 1026, Address: 0x10271f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1035, Address: 0x1027210 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1036, Address: 0x1027214 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1037, Address: 0x1027220 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1038, Address: 0x102722c */
  pScrFlag = &scrflagbw.b.h; /* Line 1039, Address: 0x1027234 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1040, Address: 0x102723c */

  VramBase = 16384; /* Line 1042, Address: 0x1027250 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1043, Address: 0x1027254 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1044, Address: 0x1027260 */
  pMapWk = (unsigned char*)mapwka; /* Line 1045, Address: 0x102726c */
  pScrFlag = &scrflagaw.b.h; /* Line 1046, Address: 0x1027274 */

  if (*pScrFlag) { /* Line 1048, Address: 0x102727c */
    if (*pScrFlag & 1) { /* Line 1049, Address: 0x1027288 */
      *pScrFlag &= 254; /* Line 1050, Address: 0x102729c */

      lD4.l = -16; /* Line 1052, Address: 0x10272a8 */
      wD5 = 65520; /* Line 1053, Address: 0x10272b0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1055, Address: 0x10272b8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1057, Address: 0x10272d8 */
    }




    if (*pScrFlag & 2) { /* Line 1063, Address: 0x1027304 */
      *pScrFlag &= 253; /* Line 1064, Address: 0x1027318 */

      lD4.l = 224; /* Line 1066, Address: 0x1027324 */
      wD5 = 65520; /* Line 1067, Address: 0x102732c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1068, Address: 0x1027334 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1070, Address: 0x1027354 */
    }




    if (*pScrFlag & 4) { /* Line 1076, Address: 0x1027380 */
      *pScrFlag &= 251; /* Line 1077, Address: 0x1027394 */

      lD4.l = -16; /* Line 1079, Address: 0x10273a0 */
      wD5 = 65520; /* Line 1080, Address: 0x10273a8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1081, Address: 0x10273b0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1083, Address: 0x10273d0 */
    }




    if (*pScrFlag & 8) { /* Line 1089, Address: 0x10273fc */
      *pScrFlag &= 247; /* Line 1090, Address: 0x1027410 */

      lD4.l = -16; /* Line 1092, Address: 0x102741c */
      wD5 = 320; /* Line 1093, Address: 0x1027424 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1094, Address: 0x102742c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1096, Address: 0x102744c */
    }
  }






} /* Line 1105, Address: 0x1027478 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1122, Address: 0x10274a0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1133, Address: 0x10274cc */

  if (*pScrFlag & 1) { /* Line 1135, Address: 0x10274d4 */
    *pScrFlag &= 254; /* Line 1136, Address: 0x10274ec */
  } /* Line 1137, Address: 0x1027500 */
  else {
    *pScrFlag &= 254; /* Line 1139, Address: 0x1027508 */

    if (*pScrFlag & 2) { /* Line 1141, Address: 0x102751c */
      *pScrFlag &= 253; /* Line 1142, Address: 0x1027534 */
      lD4.w.l = 224; /* Line 1143, Address: 0x1027548 */
    } /* Line 1144, Address: 0x1027550 */
    else {
      *pScrFlag &= 253; /* Line 1146, Address: 0x1027558 */
      goto label1; /* Line 1147, Address: 0x102756c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1152, Address: 0x1027574 */
  wD0 &= 127; /* Line 1153, Address: 0x10275c4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1154, Address: 0x10275cc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1160, Address: 0x10275ec */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1161, Address: 0x102760c */
  if (wD0 != 0) { /* Line 1162, Address: 0x1027630 */
    wD5 = 65520; /* Line 1163, Address: 0x102763c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1164, Address: 0x1027644 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1166, Address: 0x1027664 */



  } /* Line 1170, Address: 0x1027690 */
  else {

    wD5 = 0; /* Line 1173, Address: 0x1027698 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1174, Address: 0x102769c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1178, Address: 0x10276bc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1185, Address: 0x10276e8 */






    lD4.l = -16; /* Line 1192, Address: 0x10276fc */
    wD5 = 65520; /* Line 1193, Address: 0x1027704 */
    if (*pScrFlag & 168) { /* Line 1194, Address: 0x102770c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1195, Address: 0x1027724 */
      wD5 = 320; /* Line 1196, Address: 0x1027744 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1200, Address: 0x102774c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1202, Address: 0x102777c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1203, Address: 0x1027788 */



    for (i = 0; i < 16; ++i) { /* Line 1207, Address: 0x1027798 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1208, Address: 0x10277a4 */
      if (wD0 != 0) { /* Line 1209, Address: 0x10277c4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1210, Address: 0x10277d0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1211, Address: 0x10277fc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1212, Address: 0x102781c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1214, Address: 0x1027840 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1217, Address: 0x1027864 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1219, Address: 0x1027884 */
        }
      }
      lD4.w.l += 16; /* Line 1222, Address: 0x1027898 */
    } /* Line 1223, Address: 0x10278a4 */
    *pScrFlag = 0; /* Line 1224, Address: 0x10278b4 */
  }
} /* Line 1226, Address: 0x10278bc */





void scrollwrtc() {} /* Line 1232, Address: 0x10278f0 */




void scrollwrtz() {} /* Line 1237, Address: 0x1027900 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1255, Address: 0x1027910 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1268, Address: 0x1027938 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1271, Address: 0x1027958 */
    pTilePoint->x += 2; /* Line 1272, Address: 0x102796c */
    if (pTilePoint->x >= 64) { /* Line 1273, Address: 0x1027980 */
      pTilePoint->x -= 64; /* Line 1274, Address: 0x1027994 */
    }
    xOffs += 16; /* Line 1276, Address: 0x10279a8 */
  } while (--lpcnt >= 0); /* Line 1277, Address: 0x10279b4 */
} /* Line 1278, Address: 0x10279c8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1282, Address: 0x10279e0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1286, Address: 0x1027a08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1289, Address: 0x1027a28 */
    pTilePoint->x += 2; /* Line 1290, Address: 0x1027a3c */
    if (pTilePoint->x >= 64) { /* Line 1291, Address: 0x1027a50 */
      pTilePoint->x -= 64; /* Line 1292, Address: 0x1027a64 */
    }
    xOffs += 16; /* Line 1294, Address: 0x1027a78 */
  } while (--lpcnt >= 0); /* Line 1295, Address: 0x1027a84 */
} /* Line 1296, Address: 0x1027a98 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1316, Address: 0x1027ab0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1320, Address: 0x1027ad8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1323, Address: 0x1027af8 */
    pTilePoint->y += 2; /* Line 1324, Address: 0x1027b0c */
    if (pTilePoint->y >= 32) { /* Line 1325, Address: 0x1027b1c */
      pTilePoint->y -= 32; /* Line 1326, Address: 0x1027b30 */
    }
    yOffs += 16; /* Line 1328, Address: 0x1027b40 */
  } while (--lpcnt >= 0); /* Line 1329, Address: 0x1027b4c */
} /* Line 1330, Address: 0x1027b60 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1349, Address: 0x1027b70 */
  int base = 0; /* Line 1350, Address: 0x1027ba4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1355, Address: 0x1027ba8 */

    base = 1; /* Line 1357, Address: 0x1027bb8 */
  } /* Line 1358, Address: 0x1027bbc */
  else if (VramBase == 16384) { /* Line 1359, Address: 0x1027bc4 */

    base = 0; /* Line 1361, Address: 0x1027bd4 */
  }
  x = pTilePoint->x; /* Line 1363, Address: 0x1027bd8 */
  y = pTilePoint->y; /* Line 1364, Address: 0x1027be0 */


  frip = BlkIndex & 6144; /* Line 1367, Address: 0x1027be8 */
  BlkIndex &= 1023; /* Line 1368, Address: 0x1027bf0 */
  if (frip == 6144) { /* Line 1369, Address: 0x1027bfc */

    p0 = 3, p1 = 2; /* Line 1371, Address: 0x1027c08 */
    p2 = 1, p3 = 0; /* Line 1372, Address: 0x1027c10 */
  } /* Line 1373, Address: 0x1027c18 */
  else if (frip & 4096) { /* Line 1374, Address: 0x1027c20 */

    p0 = 2, p1 = 3; /* Line 1376, Address: 0x1027c2c */
    p2 = 0, p3 = 1; /* Line 1377, Address: 0x1027c34 */
  } /* Line 1378, Address: 0x1027c3c */
  else if (frip & 2048) { /* Line 1379, Address: 0x1027c44 */

    p0 = 1, p1 = 0; /* Line 1381, Address: 0x1027c50 */
    p2 = 3, p3 = 2; /* Line 1382, Address: 0x1027c58 */
  } /* Line 1383, Address: 0x1027c60 */
  else {

    p0 = 0, p1 = 1; /* Line 1386, Address: 0x1027c68 */
    p2 = 2, p3 = 3; /* Line 1387, Address: 0x1027c70 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1390, Address: 0x1027c78 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1391, Address: 0x1027cbc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1392, Address: 0x1027d00 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1393, Address: 0x1027d44 */

} /* Line 1395, Address: 0x1027d88 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1413, Address: 0x1027dc0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1414, Address: 0x1027de0 */
} /* Line 1415, Address: 0x1027e00 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1417, Address: 0x1027e10 */
  wH_posiw = 0; /* Line 1418, Address: 0x1027e30 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1419, Address: 0x1027e34 */
} /* Line 1420, Address: 0x1027e54 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1427, Address: 0x1027e70 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1433, Address: 0x1027ea0 */
  yOffs += wV_posiw; /* Line 1434, Address: 0x1027eb0 */





  if ((short)xOffs < 0) /* Line 1440, Address: 0x1027ec0 */
    xOffs = 0; /* Line 1441, Address: 0x1027edc */
  if ((short)yOffs < 0) /* Line 1442, Address: 0x1027ee0 */
    yOffs = 0; /* Line 1443, Address: 0x1027efc */
  if ((short)xOffs >= 16384) /* Line 1444, Address: 0x1027f00 */
    xOffs = 16383; /* Line 1445, Address: 0x1027f20 */
  if ((short)yOffs >= 2048) /* Line 1446, Address: 0x1027f28 */
    yOffs = 2047; /* Line 1447, Address: 0x1027f48 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1448, Address: 0x1027f50 */
  if (i < 0) i = 0; /* Line 1449, Address: 0x1027f98 */

  ScreenNo = pMapWk[i] & 127; /* Line 1451, Address: 0x1027fa4 */

  if (ScreenNo) { /* Line 1453, Address: 0x1027fc0 */




    xOffs &= 32767; /* Line 1458, Address: 0x1027fc8 */
    yOffs &= 32767; /* Line 1459, Address: 0x1027fd4 */


    xBlk = xOffs; /* Line 1462, Address: 0x1027fe0 */
    xBlk %= 256; /* Line 1463, Address: 0x1027fe8 */
    xBlk /= 16; /* Line 1464, Address: 0x1028008 */
    yBlk = yOffs; /* Line 1465, Address: 0x1028024 */
    yBlk %= 256; /* Line 1466, Address: 0x102802c */
    yBlk /= 16; /* Line 1467, Address: 0x102804c */

    lpw = pmapwk; /* Line 1469, Address: 0x1028068 */
    lpw += xBlk; /* Line 1470, Address: 0x1028070 */
    lpw += yBlk * 16; /* Line 1471, Address: 0x1028078 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1472, Address: 0x1028084 */
    *pIndex = *lpw; /* Line 1473, Address: 0x102809c */

    return 1; /* Line 1475, Address: 0x10280ac */
  }

  *pIndex = 0; /* Line 1478, Address: 0x10280b8 */
  return 0; /* Line 1479, Address: 0x10280c0 */
} /* Line 1480, Address: 0x10280c4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1500, Address: 0x10280f0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1508, Address: 0x1028118 */
  if (ScreenNo) { /* Line 1509, Address: 0x102817c */





    xBlk = xOffs; /* Line 1515, Address: 0x1028184 */
    xBlk %= 256; /* Line 1516, Address: 0x102818c */
    xBlk /= 16; /* Line 1517, Address: 0x10281ac */
    yBlk = yOffs; /* Line 1518, Address: 0x10281c8 */
    yBlk %= 256; /* Line 1519, Address: 0x10281d0 */
    yBlk /= 16; /* Line 1520, Address: 0x10281f0 */


    lpw = pmapwk; /* Line 1523, Address: 0x102820c */
    lpw += xBlk; /* Line 1524, Address: 0x1028214 */
    lpw += yBlk * 16; /* Line 1525, Address: 0x102821c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1526, Address: 0x1028228 */
    *ppBlockNo = lpw; /* Line 1527, Address: 0x1028240 */
    *pIndex = *lpw; /* Line 1528, Address: 0x1028248 */




    return 1; /* Line 1533, Address: 0x1028258 */
  }

  *pIndex = 0; /* Line 1536, Address: 0x1028264 */
  return 0; /* Line 1537, Address: 0x102826c */
} /* Line 1538, Address: 0x1028270 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1552, Address: 0x1028290 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1559, Address: 0x10282ac */
  pMapWk = (unsigned char*)mapwka; /* Line 1560, Address: 0x10282b0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1561, Address: 0x10282b8 */
    *pBlockIndex = BlockNo; /* Line 1562, Address: 0x10282dc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1563, Address: 0x10282e8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1564, Address: 0x1028300 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1565, Address: 0x1028314 */
    }
  }


} /* Line 1570, Address: 0x102832c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1584, Address: 0x1028350 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1585, Address: 0x102835c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1586, Address: 0x1028388 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1587, Address: 0x10283d4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1588, Address: 0x1028400 */

          return 0; /* Line 1590, Address: 0x102844c */
        }
      }
    }
  }

  return 1; /* Line 1596, Address: 0x1028458 */
} /* Line 1597, Address: 0x102845c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1614, Address: 0x1028470 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1615, Address: 0x102848c */

} /* Line 1617, Address: 0x10284a8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1619, Address: 0x10284c0 */
  wH_posiw = 0; /* Line 1620, Address: 0x10284dc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1621, Address: 0x10284e0 */

} /* Line 1623, Address: 0x10284fc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1625, Address: 0x1028510 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1626, Address: 0x1028524 */

} /* Line 1628, Address: 0x1028540 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1630, Address: 0x1028550 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1631, Address: 0x102856c */

} /* Line 1633, Address: 0x1028588 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1635, Address: 0x10285a0 */
  xOffs += wH_posiw; /* Line 1636, Address: 0x10285b8 */
  yOffs += wV_posiw; /* Line 1637, Address: 0x10285c8 */
  yOffs &= 240; /* Line 1638, Address: 0x10285d8 */
  xOffs &= 496; /* Line 1639, Address: 0x10285e4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1641, Address: 0x10285f0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1642, Address: 0x102861c */


} /* Line 1645, Address: 0x1028648 */















void mapwrt() { /* Line 1661, Address: 0x1028660 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1666, Address: 0x1028678 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1667, Address: 0x1028684 */
  pMapWk = (unsigned char*)mapwka; /* Line 1668, Address: 0x1028690 */
  VramBase = 16384; /* Line 1669, Address: 0x1028698 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1670, Address: 0x102869c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1674, Address: 0x10286b4 */
  VramBase = 24576; /* Line 1675, Address: 0x10286bc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1676, Address: 0x10286c0 */

} /* Line 1678, Address: 0x10286d0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1681, Address: 0x10286f0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1682, Address: 0x1028708 */
} /* Line 1683, Address: 0x1028728 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1688, Address: 0x1028740 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1692, Address: 0x1028760 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1695, Address: 0x102877c */



    wD4 += 16; /* Line 1699, Address: 0x10287a4 */
  } while ((short)--wD6 >= 0); /* Line 1700, Address: 0x10287b0 */

} /* Line 1702, Address: 0x10287d8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1708, Address: 0x10287f0 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1713, Address: 0x102880c */
  wD6 = 15; /* Line 1714, Address: 0x1028814 */

  do {
    temp.l = 0; /* Line 1717, Address: 0x102881c */
    temp.w.l = scrb_v_posit.w.h; /* Line 1718, Address: 0x1028820 */
    wD0 = scrb_v_posit.w.h; /* Line 1719, Address: 0x102882c */
    wD0 += wD4 & 496; /* Line 1720, Address: 0x1028838 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1721, Address: 0x102884c */
    wD4 += 16; /* Line 1722, Address: 0x102886c */
  } while ((short)--wD6 >= 0); /* Line 1723, Address: 0x1028874 */
} /* Line 1724, Address: 0x1028898 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1746, Address: 0x10288c0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1751, Address: 0x10288e8 */
  wD0 = pWrttbl[wD0]; /* Line 1752, Address: 0x10288f8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1754, Address: 0x1028914 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1755, Address: 0x1028938 */
  if (wD0) { /* Line 1756, Address: 0x1028960 */
    wD5 = 65520; /* Line 1757, Address: 0x102896c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1758, Address: 0x1028974 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1761, Address: 0x1028990 */



  } /* Line 1765, Address: 0x10289b8 */
  else {

    wD5 = 0; /* Line 1768, Address: 0x10289c0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1769, Address: 0x10289c4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1773, Address: 0x10289e0 */
  }





} /* Line 1780, Address: 0x1028a08 */



void mapinit() { /* Line 1784, Address: 0x1028a30 */

  colorset2(mapinittbl.colorno2); /* Line 1786, Address: 0x1028a38 */
  colorset(mapinittbl.colorno2); /* Line 1787, Address: 0x1028a4c */


  if (play_start & 2) divdevset(); /* Line 1790, Address: 0x1028a60 */
} /* Line 1791, Address: 0x1028a80 */










void mapset() {} /* Line 1802, Address: 0x1028a90 */
