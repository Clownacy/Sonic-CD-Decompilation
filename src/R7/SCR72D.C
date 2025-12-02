#include "..\EQU.H"
#include "SCR71A.H"
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
unsigned short scr_dir_tbl[6] = { 4, 0, 11927, 0, 1296, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 123, Address: 0x1025070 */



void divdevset() {} /* Line 127, Address: 0x1025080 */
















































void scr_set() { /* Line 176, Address: 0x1025090 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 179, Address: 0x102509c */

  i = 0; /* Line 181, Address: 0x10250e4 */
  scrar_no = scr_dir_tbl[i++]; /* Line 182, Address: 0x10250e8 */
  scralim_left = scr_dir_tbl[i]; /* Line 183, Address: 0x102510c */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 184, Address: 0x1025128 */
  scralim_right = scr_dir_tbl[i]; /* Line 185, Address: 0x102514c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 186, Address: 0x1025168 */
  scralim_up = scr_dir_tbl[i]; /* Line 187, Address: 0x102518c */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 188, Address: 0x10251a8 */
  scralim_down = scr_dir_tbl[i]; /* Line 189, Address: 0x10251cc */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 190, Address: 0x10251e8 */

  scra_h_keep = scralim_left + 576; /* Line 192, Address: 0x102520c */
  scra_h_count = 16; /* Line 193, Address: 0x1025230 */
  scra_v_count = 16; /* Line 194, Address: 0x102523c */

  scra_vline = scr_dir_tbl[i++]; /* Line 196, Address: 0x1025248 */
  scra_hline = 160; /* Line 197, Address: 0x102526c */

  playposiset(); /* Line 199, Address: 0x1025278 */
} /* Line 200, Address: 0x1025280 */



void playposiset() { /* Line 204, Address: 0x10252a0 */
  unsigned short playpositbl[2] = { /* Line 205, Address: 0x10252b4 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 209, Address: 0x10252d0 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 217, Address: 0x10252fc */

    playload(); /* Line 219, Address: 0x1025310 */
    xWk = actwk[0].xposi.w.h; /* Line 220, Address: 0x1025318 */
    yWk = actwk[0].yposi.w.h; /* Line 221, Address: 0x1025328 */
    if (yWk < 0) yWk = 0; /* Line 222, Address: 0x1025338 */
  } /* Line 223, Address: 0x102534c */
  else {


    i = 0; /* Line 227, Address: 0x1025354 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 228, Address: 0x1025358 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x102537c */
  }

  if ((unsigned short)xWk > 160) { /* Line 232, Address: 0x10253a0 */
    xWk -= 160; /* Line 233, Address: 0x10253b4 */
  } /* Line 234, Address: 0x10253c0 */
  else {
    xWk = 0; /* Line 236, Address: 0x10253c8 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 240, Address: 0x10253cc */
    xWk = scralim_right; /* Line 241, Address: 0x10253f0 */
  }
  scra_h_posit.w.h = xWk; /* Line 243, Address: 0x1025400 */

  if ((unsigned short)yWk > 96) { /* Line 245, Address: 0x1025408 */
    yWk -= 96; /* Line 246, Address: 0x102541c */
  } /* Line 247, Address: 0x1025428 */
  else {
    yWk = 0; /* Line 249, Address: 0x1025430 */
  }

  if (scralim_down < yWk) { /* Line 252, Address: 0x1025434 */
    yWk = scralim_down; /* Line 253, Address: 0x1025458 */
  }

  scra_v_posit.w.h = yWk; /* Line 256, Address: 0x1025468 */

  scrbinit(yWk, xWk); /* Line 258, Address: 0x1025470 */

  i = 0; /* Line 260, Address: 0x1025480 */
  loopmapno = playmapnotbl[i++]; /* Line 261, Address: 0x1025484 */
  loopmapno2 = playmapnotbl[i++]; /* Line 262, Address: 0x102549c */
  ballmapno = playmapnotbl[i++]; /* Line 263, Address: 0x10254b4 */
  ballmapno2 = playmapnotbl[i++]; /* Line 264, Address: 0x10254cc */


} /* Line 267, Address: 0x10254e4 */



void scrbinit(short yWk, short xWk) { /* Line 271, Address: 0x1025500 */
  uint_union data;


  data.l = 0; /* Line 275, Address: 0x102550c */
  data.w.h = yWk; /* Line 276, Address: 0x1025510 */
  data.l = (data.l >> 2) + (data.l >> 5); /* Line 277, Address: 0x1025518 */
  scrb_v_posit.l = data.w.l; /* Line 278, Address: 0x1025530 */
  scrc_v_posit.w.h = data.w.h; /* Line 279, Address: 0x1025540 */
  scrz_v_posit.w.h = data.w.h; /* Line 280, Address: 0x102554c */

  scrc_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 282, Address: 0x1025558 */
  scrz_h_posit.w.h = (unsigned short)((xWk >> 2) + (xWk >> 3)); /* Line 283, Address: 0x102557c */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 284, Address: 0x10255b4 */
} /* Line 285, Address: 0x10255e0 */



void scroll() { /* Line 289, Address: 0x10255f0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 294, Address: 0x1025600 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 297, Address: 0x1025610 */
  scrchk(); /* Line 298, Address: 0x102563c */
  scroll_h(); /* Line 299, Address: 0x1025644 */
  scroll_v(); /* Line 300, Address: 0x102564c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 302, Address: 0x1025654 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 303, Address: 0x1025664 */



  scrollz_h((scra_hz << 6) + (scra_hz << 5), 64); /* Line 307, Address: 0x1025674 */
  scrollc_h(scra_hz << 7, 16); /* Line 308, Address: 0x10256ac */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 309, Address: 0x10256cc */

  data.l = 0; /* Line 311, Address: 0x1025704 */
  data.w.l = scra_v_posit.w.h; /* Line 312, Address: 0x1025708 */
  data.w.l = (data.w.l >> 2) + (data.w.l >> 5); /* Line 313, Address: 0x1025714 */
  scrollb_v(data.w.l); /* Line 314, Address: 0x1025738 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 316, Address: 0x1025744 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 317, Address: 0x1025754 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x1025764 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 319, Address: 0x1025774 */
  scrflagz.b.h = 0; /* Line 320, Address: 0x10257a8 */
  scrflagc.b.h = 0; /* Line 321, Address: 0x10257b0 */

  hsCount = 0; /* Line 323, Address: 0x10257b8 */


  hsCount = z71aline(hsCount); /* Line 326, Address: 0x10257bc */

  for (i = 0; i < 8; ++i) { /* Line 328, Address: 0x10257cc */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 330, Address: 0x10257d8 */
    ++hsCount; /* Line 331, Address: 0x1025808 */
  } /* Line 332, Address: 0x102580c */

  hsCount = z71aline0(hsCount); /* Line 334, Address: 0x102581c */

  for (i = 0; i < 16; ++i) { /* Line 336, Address: 0x102582c */

    hscrollwork[hsCount] = -scrz_h_posit.w.h; /* Line 338, Address: 0x1025838 */
    ++hsCount; /* Line 339, Address: 0x1025868 */
  } /* Line 340, Address: 0x102586c */

  for (i = 0; i < 18; ++i) { /* Line 342, Address: 0x102587c */

    hscrollwork[hsCount] = -scrc_h_posit.w.h; /* Line 344, Address: 0x1025888 */
    ++hsCount; /* Line 345, Address: 0x10258b8 */
  } /* Line 346, Address: 0x10258bc */





  data.w.l = scrb_v_posit.w.h; /* Line 352, Address: 0x10258cc */
  data.w.l &= 1016; /* Line 353, Address: 0x10258d8 */
  data.w.l >>= 2; /* Line 354, Address: 0x10258e4 */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 355, Address: 0x10258f0 */
} /* Line 356, Address: 0x1025924 */



int z71aline(int hsCount) { /* Line 360, Address: 0x1025940 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[16] = { /* Line 364, Address: 0x1025954 */
    3, 3, 1, 1, 0, 0,
    3, 3, 1, 3, 1, 1,
    1, 1, 0, 0
  };

  temp = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 370, Address: 0x1025988 */
  temp <<= 6; /* Line 371, Address: 0x10259ac */
  temp /= 16; /* Line 372, Address: 0x10259b0 */
  temp <<= 10; /* Line 373, Address: 0x10259cc */
  data.l = 0; /* Line 374, Address: 0x10259d0 */
  data.w.l = scrb_h_posit.w.h; /* Line 375, Address: 0x10259d4 */
  hsCount += 38; /* Line 376, Address: 0x10259e0 */
  for (i = 0; i < 16; ++i) { /* Line 377, Address: 0x10259ec */


    for (j = -1; j < z71ascrtbl[15 - i]; ++j) { /* Line 380, Address: 0x10259f8 */


      --hsCount; /* Line 383, Address: 0x1025a04 */
      hscrollwork[hsCount] = -data.w.l; /* Line 384, Address: 0x1025a10 */
    } /* Line 385, Address: 0x1025a40 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 386, Address: 0x1025a64 */
    data.l += temp; /* Line 387, Address: 0x1025a88 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 388, Address: 0x1025a94 */
  } /* Line 389, Address: 0x1025ab8 */
  hsCount += 38; /* Line 390, Address: 0x1025ac8 */
  return hsCount; /* Line 391, Address: 0x1025ad4 */
} /* Line 392, Address: 0x1025ad8 */


int z71aline0(int hsCount) { /* Line 395, Address: 0x1025af0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[11] = { /* Line 399, Address: 0x1025b04 */
    1, 1, 1, 1,
    1, 0, 0, 0,
    0, 0, 0
  };

  temp = scrz_h_posit.w.h - scrb_h_posit.w.h; /* Line 405, Address: 0x1025b30 */
  temp <<= 6; /* Line 406, Address: 0x1025b54 */
  temp /= 11; /* Line 407, Address: 0x1025b58 */
  temp <<= 10; /* Line 408, Address: 0x1025b70 */
  data.l = 0; /* Line 409, Address: 0x1025b74 */
  data.w.l = scrb_h_posit.w.h; /* Line 410, Address: 0x1025b78 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 411, Address: 0x1025b84 */
  data.l += temp; /* Line 412, Address: 0x1025ba8 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 413, Address: 0x1025bb4 */
  for (i = 0; i < 11; ++i) { /* Line 414, Address: 0x1025bd8 */


    for (j = -1; j < z71ascrtbl0[10 - i]; ++j) { /* Line 417, Address: 0x1025be4 */


      hscrollwork[hsCount] = -data.w.l; /* Line 420, Address: 0x1025bf0 */
      ++hsCount; /* Line 421, Address: 0x1025c20 */
    } /* Line 422, Address: 0x1025c2c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 423, Address: 0x1025c50 */
    data.l += temp; /* Line 424, Address: 0x1025c74 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 425, Address: 0x1025c80 */
  } /* Line 426, Address: 0x1025ca4 */
  return hsCount; /* Line 427, Address: 0x1025cb4 */
} /* Line 428, Address: 0x1025cb8 */




void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 433, Address: 0x1025cd0 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 441, Address: 0x1025ce8 */








  VPosi &= 7; /* Line 450, Address: 0x1025cf0 */
  hsw.l = 0; /* Line 451, Address: 0x1025cfc */
  hsw.w.l = hscrollwork[offs++]; /* Line 452, Address: 0x1025d00 */

  j = VPosi; /* Line 454, Address: 0x1025d28 */
  while (j < 8) { /* Line 455, Address: 0x1025d34 */

    pHScrollBuff->l = hsw.l; /* Line 457, Address: 0x1025d3c */
    ++pHScrollBuff; /* Line 458, Address: 0x1025d44 */
    ++j; /* Line 459, Address: 0x1025d48 */
  } /* Line 460, Address: 0x1025d4c */
  for (i = 0; i < 29; ++i) { /* Line 461, Address: 0x1025d58 */

    hsw.w.l = hscrollwork[offs++]; /* Line 463, Address: 0x1025d64 */
    for (j = 0; j < 8; ++j) { /* Line 464, Address: 0x1025d8c */

      pHScrollBuff->l = hsw.l; /* Line 466, Address: 0x1025d98 */
      ++pHScrollBuff; /* Line 467, Address: 0x1025da0 */
    } /* Line 468, Address: 0x1025da4 */
  } /* Line 469, Address: 0x1025db4 */
} /* Line 470, Address: 0x1025dc4 */











void scroll_h() { /* Line 482, Address: 0x1025de0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 485, Address: 0x1025dec */
  scrh_move(); /* Line 486, Address: 0x1025df8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 487, Address: 0x1025e00 */
    scra_h_count ^= 16; /* Line 488, Address: 0x1025e34 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 489, Address: 0x1025e48 */
      scrflaga.b.h |= 4; /* Line 490, Address: 0x1025e74 */
    } /* Line 491, Address: 0x1025e88 */
    else {

      scrflaga.b.h |= 8; /* Line 494, Address: 0x1025e90 */
    }
  }


} /* Line 499, Address: 0x1025ea4 */

void scrh_move() { /* Line 501, Address: 0x1025ec0 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 504, Address: 0x1025ecc */
  wD0 -= scra_h_posit.w.h; /* Line 505, Address: 0x1025ed8 */
  wD0 -= scra_hline; /* Line 506, Address: 0x1025eec */
  if (wD0 == 0) { /* Line 507, Address: 0x1025f00 */

    scra_hz = 0; /* Line 509, Address: 0x1025f0c */
  } /* Line 510, Address: 0x1025f14 */
  else if ((short)wD0 < 0) { /* Line 511, Address: 0x1025f1c */
    left_check(wD0); /* Line 512, Address: 0x1025f34 */
  } /* Line 513, Address: 0x1025f40 */
  else {
    right_check(wD0); /* Line 515, Address: 0x1025f48 */
  }

} /* Line 518, Address: 0x1025f54 */


void right_check(unsigned short wD0) { /* Line 521, Address: 0x1025f70 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 524, Address: 0x1025f7c */
    wD0 = 16; /* Line 525, Address: 0x1025f9c */
  }

  wD0 += scra_h_posit.w.h; /* Line 528, Address: 0x1025fa4 */
  if (scralim_right < (short)wD0) { /* Line 529, Address: 0x1025fbc */
    wD0 = scralim_right; /* Line 530, Address: 0x1025fec */
  }

  wD1 = wD0; /* Line 533, Address: 0x1025ff8 */
  wD1 -= scra_h_posit.w.h; /* Line 534, Address: 0x1026000 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 535, Address: 0x1026014 */
  scra_h_posit.w.h = wD0; /* Line 536, Address: 0x1026044 */
  scra_hz = wD1; /* Line 537, Address: 0x1026050 */

} /* Line 539, Address: 0x1026058 */


void left_check(unsigned short wD0) { /* Line 542, Address: 0x1026070 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 545, Address: 0x102607c */
    wD0 = -16; /* Line 546, Address: 0x102609c */
  }

  wD0 += scra_h_posit.w.h; /* Line 549, Address: 0x10260a4 */
  if (scralim_left > (short)wD0) { /* Line 550, Address: 0x10260bc */
    wD0 = scralim_left; /* Line 551, Address: 0x10260ec */
  }

  wD1 = wD0; /* Line 554, Address: 0x10260f8 */
  wD1 -= scra_h_posit.w.h; /* Line 555, Address: 0x1026100 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 556, Address: 0x1026114 */
  scra_h_posit.w.h = wD0; /* Line 557, Address: 0x1026144 */
  scra_hz = wD1; /* Line 558, Address: 0x1026150 */

} /* Line 560, Address: 0x1026158 */


















void scroll_v() { /* Line 579, Address: 0x1026170 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 582, Address: 0x102617c */
  if (actwk[0].cddat & 4) { /* Line 583, Address: 0x10261a8 */
    wD0 -= 5; /* Line 584, Address: 0x10261c0 */
  }

  if (actwk[0].cddat & 2) { /* Line 587, Address: 0x10261c8 */
    wD0 += 32; /* Line 588, Address: 0x10261e0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 589, Address: 0x10261e8 */
      wD0 -= scra_vline; /* Line 590, Address: 0x1026208 */
      sv_move_main2(wD0); /* Line 591, Address: 0x102621c */
      return; /* Line 592, Address: 0x1026228 */
    }
    wD0 -= scra_vline; /* Line 594, Address: 0x1026230 */
    if (wD0 >= 64) { /* Line 595, Address: 0x1026244 */
      wD0 -= 64; /* Line 596, Address: 0x1026254 */
      sv_move_main2(wD0); /* Line 597, Address: 0x102625c */
      return; /* Line 598, Address: 0x1026268 */
    }
    wD0 -= 64; /* Line 600, Address: 0x1026270 */
    if (limmoveflag == 0) goto label1; /* Line 601, Address: 0x1026278 */
    sv_move_sub2(); /* Line 602, Address: 0x102628c */
    return; /* Line 603, Address: 0x1026294 */
  }




  wD0 -= scra_vline; /* Line 609, Address: 0x102629c */
  if (wD0) { /* Line 610, Address: 0x10262b0 */
    sv_move_main(wD0); /* Line 611, Address: 0x10262b8 */
    return; /* Line 612, Address: 0x10262c4 */
  }
  if (limmoveflag == 0) { /* Line 614, Address: 0x10262cc */
    sv_move_sub2(); /* Line 615, Address: 0x10262e0 */
    return; /* Line 616, Address: 0x10262e8 */
  }


label1:
  scra_vz = 0; /* Line 621, Address: 0x10262f0 */

} /* Line 623, Address: 0x10262f8 */





void sv_move_main(unsigned short wD0) { /* Line 629, Address: 0x1026310 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 632, Address: 0x1026320 */
    sv_move_main1(wD0); /* Line 633, Address: 0x102633c */
  } /* Line 634, Address: 0x1026348 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 637, Address: 0x1026350 */
    if ((short)wD1 < 0) { /* Line 638, Address: 0x102635c */
      wD1 = -(short)wD1; /* Line 639, Address: 0x1026374 */
    }

    if (wD1 >= 2048) { /* Line 642, Address: 0x1026390 */
      sv_move_main2(wD0); /* Line 643, Address: 0x10263a0 */
    } /* Line 644, Address: 0x10263ac */
    else {
      if ((short)wD0 > 6) { /* Line 646, Address: 0x10263b4 */
        sv_move_plus(1536); /* Line 647, Address: 0x10263d4 */
      } /* Line 648, Address: 0x10263e0 */
      else if ((short)wD0 < -6) { /* Line 649, Address: 0x10263e8 */
        sv_move_minus(1536); /* Line 650, Address: 0x1026408 */
      } /* Line 651, Address: 0x1026414 */
      else {
        sv_move_sub(wD0); /* Line 653, Address: 0x102641c */
      }
    }
  }
} /* Line 657, Address: 0x1026428 */



void sv_move_main1(unsigned short wD0) { /* Line 661, Address: 0x1026440 */

  if ((short)wD0 > 2) { /* Line 663, Address: 0x102644c */
    sv_move_plus(512); /* Line 664, Address: 0x102646c */
  } /* Line 665, Address: 0x1026478 */
  else if ((short)wD0 < -2) { /* Line 666, Address: 0x1026480 */
    sv_move_minus(512); /* Line 667, Address: 0x10264a0 */
  } /* Line 668, Address: 0x10264ac */
  else {
    sv_move_sub(wD0); /* Line 670, Address: 0x10264b4 */
  }

} /* Line 673, Address: 0x10264c0 */


void sv_move_main2(unsigned short wD0) { /* Line 676, Address: 0x10264d0 */

  if ((short)wD0 > 16) { /* Line 678, Address: 0x10264dc */
    sv_move_plus(4096); /* Line 679, Address: 0x10264fc */
  } /* Line 680, Address: 0x1026508 */
  else if ((short)wD0 < -16) { /* Line 681, Address: 0x1026510 */
    sv_move_minus(4096); /* Line 682, Address: 0x1026530 */
  } /* Line 683, Address: 0x102653c */
  else {
    sv_move_sub(wD0); /* Line 685, Address: 0x1026544 */
  }

} /* Line 688, Address: 0x1026550 */


void sv_move_sub2() { /* Line 691, Address: 0x1026560 */
  limmoveflag = 0; /* Line 692, Address: 0x1026568 */
  sv_move_sub(0); /* Line 693, Address: 0x1026570 */
} /* Line 694, Address: 0x102657c */


void sv_move_sub(unsigned short wD0) { /* Line 697, Address: 0x1026590 */
  int_union lD1;

  lD1.w.h = 0; /* Line 700, Address: 0x102659c */
  lD1.w.l = wD0; /* Line 701, Address: 0x10265a0 */
  lD1.l += scra_v_posit.w.h; /* Line 702, Address: 0x10265a8 */
  if ((short)wD0 > 0) { /* Line 703, Address: 0x10265c4 */
    scrv_down_ch(lD1); /* Line 704, Address: 0x10265e0 */
  } /* Line 705, Address: 0x10265ec */
  else {
    scrv_up_ch(lD1); /* Line 707, Address: 0x10265f4 */
  }

} /* Line 710, Address: 0x1026600 */




void sv_move_minus(unsigned short wD1) { /* Line 715, Address: 0x1026610 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 719, Address: 0x1026620 */
  lD1.l <<= 8; /* Line 720, Address: 0x102663c */
  lD1.l += scra_v_posit.l; /* Line 721, Address: 0x1026648 */

  wk = lD1.w.h; /* Line 723, Address: 0x102665c */
  lD1.w.h = lD1.w.l; /* Line 724, Address: 0x1026664 */
  lD1.w.l = wk; /* Line 725, Address: 0x102666c */
  scrv_up_ch(lD1); /* Line 726, Address: 0x1026670 */
} /* Line 727, Address: 0x102667c */



void scrv_up_ch(int_union lD1) { /* Line 731, Address: 0x1026690 */
  if (scralim_up >= lD1.w.l) { /* Line 732, Address: 0x102669c */
    if (lD1.w.l < -255) { /* Line 733, Address: 0x10266c4 */
      lD1.w.l &= 2047; /* Line 734, Address: 0x10266dc */
      actwk[0].yposi.w.h &= 2047; /* Line 735, Address: 0x10266e8 */
      scra_v_posit.w.h &= 2047; /* Line 736, Address: 0x10266fc */
      scrb_v_posit.w.h &= 1023; /* Line 737, Address: 0x1026710 */
    } /* Line 738, Address: 0x1026724 */
    else {

      lD1.w.l = scralim_up; /* Line 741, Address: 0x102672c */
    }
  }
  scrv_move(lD1); /* Line 744, Address: 0x1026738 */

} /* Line 746, Address: 0x1026744 */





void sv_move_plus(unsigned short wD1) { /* Line 752, Address: 0x1026760 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 756, Address: 0x1026770 */
  lD1.w.l = wD1; /* Line 757, Address: 0x1026774 */
  lD1.l <<= 8; /* Line 758, Address: 0x102677c */
  lD1.l += scra_v_posit.l; /* Line 759, Address: 0x1026788 */

  wk = lD1.w.h; /* Line 761, Address: 0x102679c */
  lD1.w.h = lD1.w.l; /* Line 762, Address: 0x10267a4 */
  lD1.w.l = wk; /* Line 763, Address: 0x10267ac */

  scrv_down_ch(lD1); /* Line 765, Address: 0x10267b0 */

} /* Line 767, Address: 0x10267bc */



void scrv_down_ch(int_union lD1) { /* Line 771, Address: 0x10267d0 */
  if (scralim_down <= lD1.w.l) { /* Line 772, Address: 0x10267dc */
    lD1.w.l -= 2048; /* Line 773, Address: 0x1026804 */
    if (lD1.w.l > 0) { /* Line 774, Address: 0x1026810 */
      actwk[0].yposi.w.h &= 2047; /* Line 775, Address: 0x1026824 */
      scra_v_posit.w.h -= 2048; /* Line 776, Address: 0x1026838 */
      scrb_v_posit.w.h &= 1023; /* Line 777, Address: 0x102684c */
    } /* Line 778, Address: 0x1026860 */
    else {
      lD1.w.l = scralim_down; /* Line 780, Address: 0x1026868 */
    }
  }
  scrv_move(lD1); /* Line 783, Address: 0x1026874 */

} /* Line 785, Address: 0x1026880 */


void scrv_move(int_union lD1) { /* Line 788, Address: 0x1026890 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 791, Address: 0x10268a0 */

  wk = lD1.w.h; /* Line 793, Address: 0x10268ac */
  lD1.w.h = lD1.w.l; /* Line 794, Address: 0x10268b4 */
  lD1.w.l = wk; /* Line 795, Address: 0x10268bc */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 797, Address: 0x10268c0 */
  scra_v_posit.l = lD1.l; /* Line 798, Address: 0x10268e8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 801, Address: 0x10268f4 */
    scra_v_count ^= 16; /* Line 802, Address: 0x1026928 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 803, Address: 0x102693c */

      scrflaga.b.h |= 2; /* Line 805, Address: 0x1026968 */
    } /* Line 806, Address: 0x102697c */
    else {
      scrflaga.b.h |= 1; /* Line 808, Address: 0x1026984 */
    }
  }


} /* Line 813, Address: 0x1026998 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 817, Address: 0x10269b0 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 820, Address: 0x10269bc */
  lD0.l += lD4.l; /* Line 821, Address: 0x10269cc */
  scrb_h_posit.l = lD0.l; /* Line 822, Address: 0x10269dc */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 824, Address: 0x10269e8 */

    scrb_h_count ^= 16; /* Line 826, Address: 0x1026a1c */
    lD0.l -= lD2.l; /* Line 827, Address: 0x1026a30 */
    if ((long int)lD0.l < 0) { /* Line 828, Address: 0x1026a40 */
      scrflagb.b.h |= 4; /* Line 829, Address: 0x1026a54 */
    } /* Line 830, Address: 0x1026a68 */
    else {

      scrflagb.b.h |= 8; /* Line 833, Address: 0x1026a70 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 838, Address: 0x1026a84 */
  lD0.l += lD5.l; /* Line 839, Address: 0x1026a94 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 840, Address: 0x1026aa4 */
  scrb_v_posit.l = lD0.l; /* Line 841, Address: 0x1026abc */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 843, Address: 0x1026ac8 */

    scrb_v_count ^= 16; /* Line 845, Address: 0x1026afc */
    lD0.l -= lD3.l; /* Line 846, Address: 0x1026b10 */
    if ((long int)lD0.l < 0) { /* Line 847, Address: 0x1026b20 */
      scrflagb.b.h |= 1; /* Line 848, Address: 0x1026b34 */
    } /* Line 849, Address: 0x1026b48 */
    else {

      scrflagb.b.h |= 2; /* Line 852, Address: 0x1026b50 */
    }
  }


} /* Line 857, Address: 0x1026b64 */






void scrollb_v(unsigned short wD0) { /* Line 864, Address: 0x1026b70 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 867, Address: 0x1026b7c */
  scrb_v_posit.w.h = wD0; /* Line 868, Address: 0x1026b88 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 870, Address: 0x1026b94 */
    scrb_v_count ^= 16; /* Line 871, Address: 0x1026bc0 */
    if ((short)wD3 > (short)wD0) { /* Line 872, Address: 0x1026bd4 */
      scrflagb.b.h |= 1; /* Line 873, Address: 0x1026c04 */
    } /* Line 874, Address: 0x1026c18 */
    else {

      scrflagb.b.h |= 2; /* Line 877, Address: 0x1026c20 */
    }
  }


} /* Line 882, Address: 0x1026c34 */



void scrollb_h(int lD4, int flagb) { /* Line 886, Address: 0x1026c50 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 890, Address: 0x1026c60 */
  lD0.l = lD2.l + lD4; /* Line 891, Address: 0x1026c6c */
  scrb_h_posit.l = lD0.l; /* Line 892, Address: 0x1026c7c */

  lD1.w.h = lD0.w.l; /* Line 894, Address: 0x1026c88 */
  lD1.w.l = lD0.w.h; /* Line 895, Address: 0x1026c90 */
  lD1.w.l &= 16; /* Line 896, Address: 0x1026c98 */

  bD3 = scrb_h_count; /* Line 898, Address: 0x1026ca4 */
  lD1.b.b4 ^= bD3; /* Line 899, Address: 0x1026cb0 */
  if (!lD1.b.b4) { /* Line 900, Address: 0x1026cc4 */
    scrb_h_count ^= 16; /* Line 901, Address: 0x1026cd0 */
    lD0.l -= lD2.l; /* Line 902, Address: 0x1026ce4 */
    if ((long int)lD0.l < 0) { /* Line 903, Address: 0x1026cf4 */
      scrflagb.b.h |= flagb; /* Line 904, Address: 0x1026d08 */
    } /* Line 905, Address: 0x1026d24 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 908, Address: 0x1026d2c */
    }
  }


} /* Line 913, Address: 0x1026d4c */


void scrollc_h(int lD4, int flagc) { /* Line 916, Address: 0x1026d60 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 920, Address: 0x1026d70 */
  lD0.l = lD2.l + lD4; /* Line 921, Address: 0x1026d7c */
  scrc_h_posit.l = lD0.l; /* Line 922, Address: 0x1026d8c */

  lD1.w.h = lD0.w.l; /* Line 924, Address: 0x1026d98 */
  lD1.w.l = lD0.w.h; /* Line 925, Address: 0x1026da0 */
  lD1.w.l &= 16; /* Line 926, Address: 0x1026da8 */

  bD3 = scrc_h_count; /* Line 928, Address: 0x1026db4 */
  lD1.b.b4 ^= bD3; /* Line 929, Address: 0x1026dc0 */
  if (!lD1.b.b4) { /* Line 930, Address: 0x1026dd4 */
    scrc_h_count ^= 16; /* Line 931, Address: 0x1026de0 */
    lD0.l -= lD2.l; /* Line 932, Address: 0x1026df4 */
    if ((long int)lD0.l < 0) { /* Line 933, Address: 0x1026e04 */
      scrflagc.b.h |= flagc; /* Line 934, Address: 0x1026e18 */
    } /* Line 935, Address: 0x1026e34 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 938, Address: 0x1026e3c */
    }
  }


} /* Line 943, Address: 0x1026e5c */











void scrollz_h(int lD4, int flagz) { /* Line 955, Address: 0x1026e70 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 959, Address: 0x1026e80 */
  lD0.l = lD2.l + lD4; /* Line 960, Address: 0x1026e8c */
  scrz_h_posit.l = lD0.l; /* Line 961, Address: 0x1026e9c */

  lD1.w.h = lD0.w.l; /* Line 963, Address: 0x1026ea8 */
  lD1.w.l = lD0.w.h; /* Line 964, Address: 0x1026eb0 */
  lD1.w.l &= 16; /* Line 965, Address: 0x1026eb8 */

  bD3 = scrz_h_count; /* Line 967, Address: 0x1026ec4 */
  lD1.b.b4 ^= bD3; /* Line 968, Address: 0x1026ed0 */
  if (!lD1.b.b4) { /* Line 969, Address: 0x1026ee4 */
    scrz_h_count ^= 16; /* Line 970, Address: 0x1026ef0 */
    lD0.l -= lD2.l; /* Line 971, Address: 0x1026f04 */
    if ((long int)lD0.l < 0) { /* Line 972, Address: 0x1026f14 */
      scrflagz.b.h |= flagz; /* Line 973, Address: 0x1026f28 */
    } /* Line 974, Address: 0x1026f44 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 977, Address: 0x1026f4c */
    }
  }


} /* Line 982, Address: 0x1026f6c */













void scrollwrtadva() { /* Line 996, Address: 0x1026f80 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1002, Address: 0x1026f9c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1003, Address: 0x1026fa0 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1004, Address: 0x1026fac */
  pMapWk = (unsigned char*)mapwkb; /* Line 1005, Address: 0x1026fb8 */
  pScrFlag = &scrflagb.b.h; /* Line 1006, Address: 0x1026fc0 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1007, Address: 0x1026fc8 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1009, Address: 0x1026fdc */
  wV_posiw = scrc_v_posit.w.h; /* Line 1010, Address: 0x1026fe8 */
  pScrFlag = &scrflagc.b.h; /* Line 1011, Address: 0x1026ff4 */
  scrollwrtc(); /* Line 1012, Address: 0x1026ffc */

} /* Line 1014, Address: 0x1027004 */












void scrollwrt() { /* Line 1027, Address: 0x1027030 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1036, Address: 0x1027050 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1037, Address: 0x1027054 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1038, Address: 0x1027060 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1039, Address: 0x102706c */
  pScrFlag = &scrflagbw.b.h; /* Line 1040, Address: 0x1027074 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1041, Address: 0x102707c */

  VramBase = 16384; /* Line 1043, Address: 0x1027090 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1044, Address: 0x1027094 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1045, Address: 0x10270a0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1046, Address: 0x10270ac */
  pScrFlag = &scrflagaw.b.h; /* Line 1047, Address: 0x10270b4 */

  if (*pScrFlag) { /* Line 1049, Address: 0x10270bc */
    if (*pScrFlag & 1) { /* Line 1050, Address: 0x10270c8 */
      *pScrFlag &= 254; /* Line 1051, Address: 0x10270dc */

      lD4.l = -16; /* Line 1053, Address: 0x10270e8 */
      wD5 = 65520; /* Line 1054, Address: 0x10270f0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1056, Address: 0x10270f8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1058, Address: 0x1027118 */
    }




    if (*pScrFlag & 2) { /* Line 1064, Address: 0x1027144 */
      *pScrFlag &= 253; /* Line 1065, Address: 0x1027158 */

      lD4.l = 224; /* Line 1067, Address: 0x1027164 */
      wD5 = 65520; /* Line 1068, Address: 0x102716c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1069, Address: 0x1027174 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1071, Address: 0x1027194 */
    }




    if (*pScrFlag & 4) { /* Line 1077, Address: 0x10271c0 */
      *pScrFlag &= 251; /* Line 1078, Address: 0x10271d4 */

      lD4.l = -16; /* Line 1080, Address: 0x10271e0 */
      wD5 = 65520; /* Line 1081, Address: 0x10271e8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1082, Address: 0x10271f0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1084, Address: 0x1027210 */
    }




    if (*pScrFlag & 8) { /* Line 1090, Address: 0x102723c */
      *pScrFlag &= 247; /* Line 1091, Address: 0x1027250 */

      lD4.l = -16; /* Line 1093, Address: 0x102725c */
      wD5 = 320; /* Line 1094, Address: 0x1027264 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1095, Address: 0x102726c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1097, Address: 0x102728c */
    }
  }






} /* Line 1106, Address: 0x10272b8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1123, Address: 0x10272e0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1134, Address: 0x102730c */

  if (*pScrFlag & 1) { /* Line 1136, Address: 0x1027314 */
    *pScrFlag &= 254; /* Line 1137, Address: 0x102732c */
  } /* Line 1138, Address: 0x1027340 */
  else {
    *pScrFlag &= 254; /* Line 1140, Address: 0x1027348 */

    if (*pScrFlag & 2) { /* Line 1142, Address: 0x102735c */
      *pScrFlag &= 253; /* Line 1143, Address: 0x1027374 */
      lD4.w.l = 224; /* Line 1144, Address: 0x1027388 */
    } /* Line 1145, Address: 0x1027390 */
    else {
      *pScrFlag &= 253; /* Line 1147, Address: 0x1027398 */
      goto label1; /* Line 1148, Address: 0x10273ac */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1153, Address: 0x10273b4 */
  wD0 &= 127; /* Line 1154, Address: 0x1027404 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1155, Address: 0x102740c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1161, Address: 0x102742c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1162, Address: 0x102744c */
  if (wD0 != 0) { /* Line 1163, Address: 0x1027470 */
    wD5 = 65520; /* Line 1164, Address: 0x102747c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1165, Address: 0x1027484 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1167, Address: 0x10274a4 */



  } /* Line 1171, Address: 0x10274d0 */
  else {

    wD5 = 0; /* Line 1174, Address: 0x10274d8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1175, Address: 0x10274dc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1179, Address: 0x10274fc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1186, Address: 0x1027528 */






    lD4.l = -16; /* Line 1193, Address: 0x102753c */
    wD5 = 65520; /* Line 1194, Address: 0x1027544 */
    if (*pScrFlag & 168) { /* Line 1195, Address: 0x102754c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1196, Address: 0x1027564 */
      wD5 = 320; /* Line 1197, Address: 0x1027584 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1201, Address: 0x102758c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1203, Address: 0x10275bc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1204, Address: 0x10275c8 */



    for (i = 0; i < 16; ++i) { /* Line 1208, Address: 0x10275d8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1209, Address: 0x10275e4 */
      if (wD0 != 0) { /* Line 1210, Address: 0x1027604 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1211, Address: 0x1027610 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1212, Address: 0x102763c */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1213, Address: 0x102765c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1215, Address: 0x1027680 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1218, Address: 0x10276a4 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1220, Address: 0x10276c4 */
        }
      }
      lD4.w.l += 16; /* Line 1223, Address: 0x10276d8 */
    } /* Line 1224, Address: 0x10276e4 */
    *pScrFlag = 0; /* Line 1225, Address: 0x10276f4 */
  }
} /* Line 1227, Address: 0x10276fc */





void scrollwrtc() {} /* Line 1233, Address: 0x1027730 */




void scrollwrtz() {} /* Line 1238, Address: 0x1027740 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1256, Address: 0x1027750 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1269, Address: 0x1027778 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1272, Address: 0x1027798 */
    pTilePoint->x += 2; /* Line 1273, Address: 0x10277ac */
    if (pTilePoint->x >= 64) { /* Line 1274, Address: 0x10277c0 */
      pTilePoint->x -= 64; /* Line 1275, Address: 0x10277d4 */
    }
    xOffs += 16; /* Line 1277, Address: 0x10277e8 */
  } while (--lpcnt >= 0); /* Line 1278, Address: 0x10277f4 */
} /* Line 1279, Address: 0x1027808 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1283, Address: 0x1027820 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1287, Address: 0x1027848 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1290, Address: 0x1027868 */
    pTilePoint->x += 2; /* Line 1291, Address: 0x102787c */
    if (pTilePoint->x >= 64) { /* Line 1292, Address: 0x1027890 */
      pTilePoint->x -= 64; /* Line 1293, Address: 0x10278a4 */
    }
    xOffs += 16; /* Line 1295, Address: 0x10278b8 */
  } while (--lpcnt >= 0); /* Line 1296, Address: 0x10278c4 */
} /* Line 1297, Address: 0x10278d8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1317, Address: 0x10278f0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1321, Address: 0x1027918 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1324, Address: 0x1027938 */
    pTilePoint->y += 2; /* Line 1325, Address: 0x102794c */
    if (pTilePoint->y >= 32) { /* Line 1326, Address: 0x102795c */
      pTilePoint->y -= 32; /* Line 1327, Address: 0x1027970 */
    }
    yOffs += 16; /* Line 1329, Address: 0x1027980 */
  } while (--lpcnt >= 0); /* Line 1330, Address: 0x102798c */
} /* Line 1331, Address: 0x10279a0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1350, Address: 0x10279b0 */
  int base = 0; /* Line 1351, Address: 0x10279e4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1356, Address: 0x10279e8 */

    base = 1; /* Line 1358, Address: 0x10279f8 */
  } /* Line 1359, Address: 0x10279fc */
  else if (VramBase == 16384) { /* Line 1360, Address: 0x1027a04 */

    base = 0; /* Line 1362, Address: 0x1027a14 */
  }
  x = pTilePoint->x; /* Line 1364, Address: 0x1027a18 */
  y = pTilePoint->y; /* Line 1365, Address: 0x1027a20 */


  frip = BlkIndex & 6144; /* Line 1368, Address: 0x1027a28 */
  BlkIndex &= 1023; /* Line 1369, Address: 0x1027a30 */
  if (frip == 6144) { /* Line 1370, Address: 0x1027a3c */

    p0 = 3, p1 = 2; /* Line 1372, Address: 0x1027a48 */
    p2 = 1, p3 = 0; /* Line 1373, Address: 0x1027a50 */
  } /* Line 1374, Address: 0x1027a58 */
  else if (frip & 4096) { /* Line 1375, Address: 0x1027a60 */

    p0 = 2, p1 = 3; /* Line 1377, Address: 0x1027a6c */
    p2 = 0, p3 = 1; /* Line 1378, Address: 0x1027a74 */
  } /* Line 1379, Address: 0x1027a7c */
  else if (frip & 2048) { /* Line 1380, Address: 0x1027a84 */

    p0 = 1, p1 = 0; /* Line 1382, Address: 0x1027a90 */
    p2 = 3, p3 = 2; /* Line 1383, Address: 0x1027a98 */
  } /* Line 1384, Address: 0x1027aa0 */
  else {

    p0 = 0, p1 = 1; /* Line 1387, Address: 0x1027aa8 */
    p2 = 2, p3 = 3; /* Line 1388, Address: 0x1027ab0 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1391, Address: 0x1027ab8 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1392, Address: 0x1027afc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1393, Address: 0x1027b40 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1394, Address: 0x1027b84 */

} /* Line 1396, Address: 0x1027bc8 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1414, Address: 0x1027c00 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1415, Address: 0x1027c20 */
} /* Line 1416, Address: 0x1027c40 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1418, Address: 0x1027c50 */
  wH_posiw = 0; /* Line 1419, Address: 0x1027c70 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1420, Address: 0x1027c74 */
} /* Line 1421, Address: 0x1027c94 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1428, Address: 0x1027cb0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1434, Address: 0x1027ce0 */
  yOffs += wV_posiw; /* Line 1435, Address: 0x1027cf0 */





  if ((short)xOffs < 0) /* Line 1441, Address: 0x1027d00 */
    xOffs = 0; /* Line 1442, Address: 0x1027d1c */
  if ((short)yOffs < 0) /* Line 1443, Address: 0x1027d20 */
    yOffs = 0; /* Line 1444, Address: 0x1027d3c */
  if ((short)xOffs >= 16384) /* Line 1445, Address: 0x1027d40 */
    xOffs = 16383; /* Line 1446, Address: 0x1027d60 */
  if ((short)yOffs >= 2048) /* Line 1447, Address: 0x1027d68 */
    yOffs = 2047; /* Line 1448, Address: 0x1027d88 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1449, Address: 0x1027d90 */
  if (i < 0) i = 0; /* Line 1450, Address: 0x1027dd8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1452, Address: 0x1027de4 */

  if (ScreenNo) { /* Line 1454, Address: 0x1027e00 */




    xOffs &= 32767; /* Line 1459, Address: 0x1027e08 */
    yOffs &= 32767; /* Line 1460, Address: 0x1027e14 */


    xBlk = xOffs; /* Line 1463, Address: 0x1027e20 */
    xBlk %= 256; /* Line 1464, Address: 0x1027e28 */
    xBlk /= 16; /* Line 1465, Address: 0x1027e48 */
    yBlk = yOffs; /* Line 1466, Address: 0x1027e64 */
    yBlk %= 256; /* Line 1467, Address: 0x1027e6c */
    yBlk /= 16; /* Line 1468, Address: 0x1027e8c */

    lpw = pmapwk; /* Line 1470, Address: 0x1027ea8 */
    lpw += xBlk; /* Line 1471, Address: 0x1027eb0 */
    lpw += yBlk * 16; /* Line 1472, Address: 0x1027eb8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1473, Address: 0x1027ec4 */
    *pIndex = *lpw; /* Line 1474, Address: 0x1027edc */

    return 1; /* Line 1476, Address: 0x1027eec */
  }

  *pIndex = 0; /* Line 1479, Address: 0x1027ef8 */
  return 0; /* Line 1480, Address: 0x1027f00 */
} /* Line 1481, Address: 0x1027f04 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1501, Address: 0x1027f30 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1509, Address: 0x1027f58 */
  if (ScreenNo) { /* Line 1510, Address: 0x1027fbc */





    xBlk = xOffs; /* Line 1516, Address: 0x1027fc4 */
    xBlk %= 256; /* Line 1517, Address: 0x1027fcc */
    xBlk /= 16; /* Line 1518, Address: 0x1027fec */
    yBlk = yOffs; /* Line 1519, Address: 0x1028008 */
    yBlk %= 256; /* Line 1520, Address: 0x1028010 */
    yBlk /= 16; /* Line 1521, Address: 0x1028030 */


    lpw = pmapwk; /* Line 1524, Address: 0x102804c */
    lpw += xBlk; /* Line 1525, Address: 0x1028054 */
    lpw += yBlk * 16; /* Line 1526, Address: 0x102805c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1527, Address: 0x1028068 */
    *ppBlockNo = lpw; /* Line 1528, Address: 0x1028080 */
    *pIndex = *lpw; /* Line 1529, Address: 0x1028088 */




    return 1; /* Line 1534, Address: 0x1028098 */
  }

  *pIndex = 0; /* Line 1537, Address: 0x10280a4 */
  return 0; /* Line 1538, Address: 0x10280ac */
} /* Line 1539, Address: 0x10280b0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1553, Address: 0x10280d0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1560, Address: 0x10280ec */
  pMapWk = (unsigned char*)mapwka; /* Line 1561, Address: 0x10280f0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1562, Address: 0x10280f8 */
    *pBlockIndex = BlockNo; /* Line 1563, Address: 0x102811c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1564, Address: 0x1028128 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1565, Address: 0x1028140 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1566, Address: 0x1028154 */
    }
  }


} /* Line 1571, Address: 0x102816c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1585, Address: 0x1028190 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1586, Address: 0x102819c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1587, Address: 0x10281c8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1588, Address: 0x1028214 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1589, Address: 0x1028240 */

          return 0; /* Line 1591, Address: 0x102828c */
        }
      }
    }
  }

  return 1; /* Line 1597, Address: 0x1028298 */
} /* Line 1598, Address: 0x102829c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1615, Address: 0x10282b0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1616, Address: 0x10282cc */

} /* Line 1618, Address: 0x10282e8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1620, Address: 0x1028300 */
  wH_posiw = 0; /* Line 1621, Address: 0x102831c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1622, Address: 0x1028320 */

} /* Line 1624, Address: 0x102833c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1626, Address: 0x1028350 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1627, Address: 0x1028364 */

} /* Line 1629, Address: 0x1028380 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1631, Address: 0x1028390 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1632, Address: 0x10283ac */

} /* Line 1634, Address: 0x10283c8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1636, Address: 0x10283e0 */
  xOffs += wH_posiw; /* Line 1637, Address: 0x10283f8 */
  yOffs += wV_posiw; /* Line 1638, Address: 0x1028408 */
  yOffs &= 240; /* Line 1639, Address: 0x1028418 */
  xOffs &= 496; /* Line 1640, Address: 0x1028424 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1642, Address: 0x1028430 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1643, Address: 0x102845c */


} /* Line 1646, Address: 0x1028488 */















void mapwrt() { /* Line 1662, Address: 0x10284a0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1667, Address: 0x10284b8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1668, Address: 0x10284c4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1669, Address: 0x10284d0 */
  VramBase = 16384; /* Line 1670, Address: 0x10284d8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1671, Address: 0x10284dc */



  pMapWk = (unsigned char*)mapwkb; /* Line 1675, Address: 0x10284f4 */
  VramBase = 24576; /* Line 1676, Address: 0x10284fc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1677, Address: 0x1028500 */

} /* Line 1679, Address: 0x1028510 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1682, Address: 0x1028530 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1683, Address: 0x1028548 */
} /* Line 1684, Address: 0x1028568 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1689, Address: 0x1028580 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1693, Address: 0x10285a0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1696, Address: 0x10285bc */



    wD4 += 16; /* Line 1700, Address: 0x10285e4 */
  } while ((short)--wD6 >= 0); /* Line 1701, Address: 0x10285f0 */

} /* Line 1703, Address: 0x1028618 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1709, Address: 0x1028630 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1714, Address: 0x102864c */
  wD6 = 15; /* Line 1715, Address: 0x1028654 */

  do {
    temp.l = 0; /* Line 1718, Address: 0x102865c */
    temp.w.l = scrb_v_posit.w.h; /* Line 1719, Address: 0x1028660 */
    wD0 = scrb_v_posit.w.h; /* Line 1720, Address: 0x102866c */
    wD0 += wD4 & 496; /* Line 1721, Address: 0x1028678 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1722, Address: 0x102868c */
    wD4 += 16; /* Line 1723, Address: 0x10286ac */
  } while ((short)--wD6 >= 0); /* Line 1724, Address: 0x10286b4 */
} /* Line 1725, Address: 0x10286d8 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1747, Address: 0x1028700 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1752, Address: 0x1028728 */
  wD0 = pWrttbl[wD0]; /* Line 1753, Address: 0x1028738 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1755, Address: 0x1028754 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1756, Address: 0x1028778 */
  if (wD0) { /* Line 1757, Address: 0x10287a0 */
    wD5 = 65520; /* Line 1758, Address: 0x10287ac */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1759, Address: 0x10287b4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1762, Address: 0x10287d0 */



  } /* Line 1766, Address: 0x10287f8 */
  else {

    wD5 = 0; /* Line 1769, Address: 0x1028800 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1770, Address: 0x1028804 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1774, Address: 0x1028820 */
  }





} /* Line 1781, Address: 0x1028848 */



void mapinit() { /* Line 1785, Address: 0x1028870 */

  colorset2(mapinittbl.colorno2); /* Line 1787, Address: 0x1028878 */
  colorset(mapinittbl.colorno2); /* Line 1788, Address: 0x102888c */


  if (play_start & 2) divdevset(); /* Line 1791, Address: 0x10288a0 */
} /* Line 1792, Address: 0x10288c0 */










void mapset() {} /* Line 1803, Address: 0x10288d0 */
