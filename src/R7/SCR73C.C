#include "..\EQU.H"
#include "SCR71A.H"
#include "..\IMPFUNCS.H"
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
unsigned short scr_dir_tbl[6] = { 4, 0, 16023, 0, 1296, 96 };
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;























































































void enecginit(void) {} /* Line 124, Address: 0x1021eb0 */



void divdevset() {} /* Line 128, Address: 0x1021ec0 */
















































void scr_set(void) { /* Line 177, Address: 0x1021ed0 */
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 180, Address: 0x1021edc */

  i = 0; /* Line 182, Address: 0x1021f24 */
  scrar_no = scr_dir_tbl[i++]; /* Line 183, Address: 0x1021f28 */
  scralim_left = scr_dir_tbl[i]; /* Line 184, Address: 0x1021f4c */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 185, Address: 0x1021f68 */
  scralim_right = scr_dir_tbl[i]; /* Line 186, Address: 0x1021f8c */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 187, Address: 0x1021fa8 */
  scralim_up = scr_dir_tbl[i]; /* Line 188, Address: 0x1021fcc */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 189, Address: 0x1021fe8 */
  scralim_down = scr_dir_tbl[i]; /* Line 190, Address: 0x102200c */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 191, Address: 0x1022028 */

  scra_h_keep = scralim_left + 576; /* Line 193, Address: 0x102204c */
  scra_h_count = 16; /* Line 194, Address: 0x1022070 */
  scra_v_count = 16; /* Line 195, Address: 0x102207c */

  scra_vline = scr_dir_tbl[i++]; /* Line 197, Address: 0x1022088 */
  scra_hline = 160; /* Line 198, Address: 0x10220ac */

  playposiset(); /* Line 200, Address: 0x10220b8 */
} /* Line 201, Address: 0x10220c0 */



void playposiset(void) { /* Line 205, Address: 0x10220e0 */
  unsigned short playpositbl[2] = { /* Line 206, Address: 0x10220f4 */
    64,
    396
  };
  unsigned char playmapnotbl[4] = { /* Line 210, Address: 0x1022110 */
    132,
    134,
    127,
    127
  };
  short xWk, yWk;
  int i;
  if (plflag != 0) { /* Line 218, Address: 0x102213c */

    playload(); /* Line 220, Address: 0x1022150 */
    xWk = actwk[0].xposi.w.h; /* Line 221, Address: 0x1022158 */
    yWk = actwk[0].yposi.w.h; /* Line 222, Address: 0x1022168 */
    if (yWk < 0) yWk = 0; /* Line 223, Address: 0x1022178 */
  } /* Line 224, Address: 0x102218c */
  else {


    i = 0; /* Line 228, Address: 0x1022194 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 229, Address: 0x1022198 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 230, Address: 0x10221bc */
  }

  if ((unsigned short)xWk > 160) { /* Line 233, Address: 0x10221e0 */
    xWk -= 160; /* Line 234, Address: 0x10221f4 */
  } /* Line 235, Address: 0x1022200 */
  else {
    xWk = 0; /* Line 237, Address: 0x1022208 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 241, Address: 0x102220c */
    xWk = scralim_right; /* Line 242, Address: 0x1022230 */
  }
  scra_h_posit.w.h = xWk; /* Line 244, Address: 0x1022240 */

  if ((unsigned short)yWk > 96) { /* Line 246, Address: 0x1022248 */
    yWk -= 96; /* Line 247, Address: 0x102225c */
  } /* Line 248, Address: 0x1022268 */
  else {
    yWk = 0; /* Line 250, Address: 0x1022270 */
  }

  if (scralim_down < yWk) { /* Line 253, Address: 0x1022274 */
    yWk = scralim_down; /* Line 254, Address: 0x1022298 */
  }

  scra_v_posit.w.h = yWk; /* Line 257, Address: 0x10222a8 */

  scrbinit(yWk, xWk); /* Line 259, Address: 0x10222b0 */

  i = 0; /* Line 261, Address: 0x10222c0 */
  loopmapno = playmapnotbl[i++]; /* Line 262, Address: 0x10222c4 */
  loopmapno2 = playmapnotbl[i++]; /* Line 263, Address: 0x10222dc */
  ballmapno = playmapnotbl[i++]; /* Line 264, Address: 0x10222f4 */
  ballmapno2 = playmapnotbl[i++]; /* Line 265, Address: 0x102230c */


} /* Line 268, Address: 0x1022324 */



void scrbinit(short yWk, short xWk) { /* Line 272, Address: 0x1022340 */
  uint_union data;


  data.l = 0; /* Line 276, Address: 0x102234c */
  data.w.h = yWk; /* Line 277, Address: 0x1022350 */
  scrb_v_posit.l = data.w.l; /* Line 278, Address: 0x1022358 */
  scrc_v_posit.w.h = data.w.l; /* Line 279, Address: 0x1022368 */
  scrz_v_posit.w.h = data.w.l; /* Line 280, Address: 0x1022374 */

  scrc_h_posit.w.h = (unsigned short)((xWk >> 1) + (xWk >> 2)); /* Line 282, Address: 0x1022380 */
  scrz_h_posit.w.h = (unsigned short)(xWk >> 1); /* Line 283, Address: 0x10223b8 */
  scrb_h_posit.w.h = (unsigned short)((xWk >> 4) * 3); /* Line 284, Address: 0x10223dc */
} /* Line 285, Address: 0x1022408 */



void scroll(void) { /* Line 289, Address: 0x1022420 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 294, Address: 0x1022430 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 297, Address: 0x1022440 */
  scrchk(); /* Line 298, Address: 0x102246c */
  scroll_h(); /* Line 299, Address: 0x1022474 */
  scroll_v(); /* Line 300, Address: 0x102247c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 302, Address: 0x1022484 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 303, Address: 0x1022494 */



  scrollz_h(scra_hz << 7, 64); /* Line 307, Address: 0x10224a4 */
  scrollc_h((long int)(scra_hz << 7) * 3, 16); /* Line 308, Address: 0x10224c4 */
  scrollb_h((long int)(scra_hz << 4) * 3, 4); /* Line 309, Address: 0x10224fc */

  data.l = 0; /* Line 311, Address: 0x1022534 */
  data.w.l = scra_v_posit.w.h; /* Line 312, Address: 0x1022538 */

  scrollb_v(data.w.l); /* Line 314, Address: 0x1022544 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 316, Address: 0x1022550 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 317, Address: 0x1022560 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 318, Address: 0x1022570 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 319, Address: 0x1022580 */
  scrflagz.b.h = 0; /* Line 320, Address: 0x10225b4 */
  scrflagc.b.h = 0; /* Line 321, Address: 0x10225bc */

  hsCount = 0; /* Line 323, Address: 0x10225c4 */


  hsCount = z71aline(hsCount); /* Line 326, Address: 0x10225c8 */

  for (i = 0; i < 4; ++i) { /* Line 328, Address: 0x10225d8 */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 330, Address: 0x10225e4 */
    ++hsCount; /* Line 331, Address: 0x1022614 */
  } /* Line 332, Address: 0x1022618 */

  hsCount = z71aline0(hsCount); /* Line 334, Address: 0x1022628 */

  for (i = 0; i < 12; ++i) { /* Line 336, Address: 0x1022638 */

    hscrollwork[hsCount] = -scrc_h_posit.w.h; /* Line 338, Address: 0x1022644 */
    ++hsCount; /* Line 339, Address: 0x1022674 */
  } /* Line 340, Address: 0x1022678 */





  data.w.l = scrb_v_posit.w.h; /* Line 346, Address: 0x1022688 */
  data.w.l &= 1016; /* Line 347, Address: 0x1022694 */
  data.w.l >>= 2; /* Line 348, Address: 0x10226a0 */
  zonescrsetsub0(scrb_v_posit.w.h, data.w.l / 2); /* Line 349, Address: 0x10226ac */
} /* Line 350, Address: 0x10226e0 */



int z71aline(int hsCount) { /* Line 354, Address: 0x1022700 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl[39] = { /* Line 358, Address: 0x1022714 */
    1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
  };

  temp = scra_h_posit.w.h * 2 - scrb_h_posit.w.h; /* Line 366, Address: 0x1022740 */
  temp <<= 6; /* Line 367, Address: 0x1022768 */
  temp /= 39; /* Line 368, Address: 0x102276c */
  temp <<= 10; /* Line 369, Address: 0x1022784 */
  data.l = 0; /* Line 370, Address: 0x1022788 */
  data.w.l = scrb_h_posit.w.h; /* Line 371, Address: 0x102278c */
  hsCount += 46; /* Line 372, Address: 0x1022798 */
  for (i = 0; i < 39; ++i) { /* Line 373, Address: 0x10227a4 */


    for (j = -1; j < z71ascrtbl[38 - i]; ++j) { /* Line 376, Address: 0x10227b0 */


      --hsCount; /* Line 379, Address: 0x10227bc */
      hscrollwork[hsCount] = -data.w.l; /* Line 380, Address: 0x10227c8 */
    } /* Line 381, Address: 0x10227f8 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 382, Address: 0x102281c */
    data.l += temp; /* Line 383, Address: 0x1022840 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 384, Address: 0x102284c */
  } /* Line 385, Address: 0x1022870 */
  hsCount += 46; /* Line 386, Address: 0x1022880 */
  return hsCount; /* Line 387, Address: 0x102288c */
} /* Line 388, Address: 0x1022890 */


int z71aline0(int hsCount) { /* Line 391, Address: 0x10228b0 */
  int temp;
  int_union data;
  int i, j;
  int z71ascrtbl0[10] = { /* Line 395, Address: 0x10228c4 */
    7, 3, 3, 5,
    3, 3, 0, 0,
    0, 0
  };

  temp = scrc_h_posit.w.h - scrb_h_posit.w.h; /* Line 401, Address: 0x10228f8 */
  temp <<= 4; /* Line 402, Address: 0x102291c */
  temp /= 10; /* Line 403, Address: 0x1022920 */
  temp <<= 12; /* Line 404, Address: 0x1022938 */
  data.l = 0; /* Line 405, Address: 0x102293c */
  data.w.l = scrb_h_posit.w.h; /* Line 406, Address: 0x1022940 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 407, Address: 0x102294c */
  data.l += temp; /* Line 408, Address: 0x1022970 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 409, Address: 0x102297c */
  for (i = 0; i < 10; ++i) { /* Line 410, Address: 0x10229a0 */


    for (j = -1; j < z71ascrtbl0[9 - i]; ++j) { /* Line 413, Address: 0x10229ac */


      hscrollwork[hsCount] = -data.w.l; /* Line 416, Address: 0x10229b8 */
      ++hsCount; /* Line 417, Address: 0x10229e8 */
    } /* Line 418, Address: 0x10229f4 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 419, Address: 0x1022a18 */
    data.l += temp; /* Line 420, Address: 0x1022a3c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 421, Address: 0x1022a48 */
  } /* Line 422, Address: 0x1022a6c */
  return hsCount; /* Line 423, Address: 0x1022a7c */
} /* Line 424, Address: 0x1022a80 */




void zonescrsetsub0(short VPosi, unsigned short offs) { /* Line 429, Address: 0x1022aa0 */
  int_union* pHScrollBuff;
  int_union hsw;
  int i, j;




  pHScrollBuff = lphscrollbuff; /* Line 437, Address: 0x1022ab8 */








  VPosi &= 7; /* Line 446, Address: 0x1022ac0 */
  hsw.l = 0; /* Line 447, Address: 0x1022acc */
  hsw.w.l = hscrollwork[offs++]; /* Line 448, Address: 0x1022ad0 */

  j = VPosi; /* Line 450, Address: 0x1022af8 */
  while (j < 8) { /* Line 451, Address: 0x1022b04 */

    pHScrollBuff->l = hsw.l; /* Line 453, Address: 0x1022b0c */
    ++pHScrollBuff; /* Line 454, Address: 0x1022b14 */
    ++j; /* Line 455, Address: 0x1022b18 */
  } /* Line 456, Address: 0x1022b1c */
  for (i = 0; i < 29; ++i) { /* Line 457, Address: 0x1022b28 */

    hsw.w.l = hscrollwork[offs++]; /* Line 459, Address: 0x1022b34 */
    for (j = 0; j < 8; ++j) { /* Line 460, Address: 0x1022b5c */

      pHScrollBuff->l = hsw.l; /* Line 462, Address: 0x1022b68 */
      ++pHScrollBuff; /* Line 463, Address: 0x1022b70 */
    } /* Line 464, Address: 0x1022b74 */
  } /* Line 465, Address: 0x1022b84 */
} /* Line 466, Address: 0x1022b94 */











void scroll_h(void) { /* Line 478, Address: 0x1022bb0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 481, Address: 0x1022bbc */
  scrh_move(); /* Line 482, Address: 0x1022bc8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 483, Address: 0x1022bd0 */
    scra_h_count ^= 16; /* Line 484, Address: 0x1022c04 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 485, Address: 0x1022c18 */
      scrflaga.b.h |= 4; /* Line 486, Address: 0x1022c44 */
    } /* Line 487, Address: 0x1022c58 */
    else {

      scrflaga.b.h |= 8; /* Line 490, Address: 0x1022c60 */
    }
  }


} /* Line 495, Address: 0x1022c74 */

void scrh_move(void) { /* Line 497, Address: 0x1022c90 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 500, Address: 0x1022c9c */
  wD0 -= scra_h_posit.w.h; /* Line 501, Address: 0x1022ca8 */
  wD0 -= scra_hline; /* Line 502, Address: 0x1022cbc */
  if (wD0 == 0) { /* Line 503, Address: 0x1022cd0 */

    scra_hz = 0; /* Line 505, Address: 0x1022cdc */
  } /* Line 506, Address: 0x1022ce4 */
  else if ((short)wD0 < 0) { /* Line 507, Address: 0x1022cec */
    left_check(wD0); /* Line 508, Address: 0x1022d04 */
  } /* Line 509, Address: 0x1022d10 */
  else {
    right_check(wD0); /* Line 511, Address: 0x1022d18 */
  }

} /* Line 514, Address: 0x1022d24 */


void right_check(unsigned short wD0) { /* Line 517, Address: 0x1022d40 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 520, Address: 0x1022d4c */
    wD0 = 16; /* Line 521, Address: 0x1022d6c */
  }

  wD0 += scra_h_posit.w.h; /* Line 524, Address: 0x1022d74 */
  if (scralim_right < (short)wD0) { /* Line 525, Address: 0x1022d8c */
    wD0 = scralim_right; /* Line 526, Address: 0x1022dbc */
  }

  wD1 = wD0; /* Line 529, Address: 0x1022dc8 */
  wD1 -= scra_h_posit.w.h; /* Line 530, Address: 0x1022dd0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 531, Address: 0x1022de4 */
  scra_h_posit.w.h = wD0; /* Line 532, Address: 0x1022e14 */
  scra_hz = wD1; /* Line 533, Address: 0x1022e20 */

} /* Line 535, Address: 0x1022e28 */


void left_check(unsigned short wD0) { /* Line 538, Address: 0x1022e40 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 541, Address: 0x1022e4c */
    wD0 = -16; /* Line 542, Address: 0x1022e6c */
  }

  wD0 += scra_h_posit.w.h; /* Line 545, Address: 0x1022e74 */
  if (scralim_left > (short)wD0) { /* Line 546, Address: 0x1022e8c */
    wD0 = scralim_left; /* Line 547, Address: 0x1022ebc */
  }

  wD1 = wD0; /* Line 550, Address: 0x1022ec8 */
  wD1 -= scra_h_posit.w.h; /* Line 551, Address: 0x1022ed0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 552, Address: 0x1022ee4 */
  scra_h_posit.w.h = wD0; /* Line 553, Address: 0x1022f14 */
  scra_hz = wD1; /* Line 554, Address: 0x1022f20 */

} /* Line 556, Address: 0x1022f28 */


















void scroll_v(void) { /* Line 575, Address: 0x1022f40 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 578, Address: 0x1022f4c */
  if (actwk[0].cddat & 4) { /* Line 579, Address: 0x1022f78 */
    wD0 -= 5; /* Line 580, Address: 0x1022f90 */
  }

  if (actwk[0].cddat & 2) { /* Line 583, Address: 0x1022f98 */
    wD0 += 32; /* Line 584, Address: 0x1022fb0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 585, Address: 0x1022fb8 */
      wD0 -= scra_vline; /* Line 586, Address: 0x1022fd8 */
      sv_move_main2(wD0); /* Line 587, Address: 0x1022fec */
      return; /* Line 588, Address: 0x1022ff8 */
    }
    wD0 -= scra_vline; /* Line 590, Address: 0x1023000 */
    if (wD0 >= 64) { /* Line 591, Address: 0x1023014 */
      wD0 -= 64; /* Line 592, Address: 0x1023024 */
      sv_move_main2(wD0); /* Line 593, Address: 0x102302c */
      return; /* Line 594, Address: 0x1023038 */
    }
    wD0 -= 64; /* Line 596, Address: 0x1023040 */
    if (limmoveflag == 0) goto label1; /* Line 597, Address: 0x1023048 */
    sv_move_sub2(); /* Line 598, Address: 0x102305c */
    return; /* Line 599, Address: 0x1023064 */
  }




  wD0 -= scra_vline; /* Line 605, Address: 0x102306c */
  if (wD0) { /* Line 606, Address: 0x1023080 */
    sv_move_main(wD0); /* Line 607, Address: 0x1023088 */
    return; /* Line 608, Address: 0x1023094 */
  }
  if (limmoveflag == 0) { /* Line 610, Address: 0x102309c */
    sv_move_sub2(); /* Line 611, Address: 0x10230b0 */
    return; /* Line 612, Address: 0x10230b8 */
  }


label1:
  scra_vz = 0; /* Line 617, Address: 0x10230c0 */

} /* Line 619, Address: 0x10230c8 */





void sv_move_main(unsigned short wD0) { /* Line 625, Address: 0x10230e0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 628, Address: 0x10230f0 */
    sv_move_main1(wD0); /* Line 629, Address: 0x102310c */
  } /* Line 630, Address: 0x1023118 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 633, Address: 0x1023120 */
    if ((short)wD1 < 0) { /* Line 634, Address: 0x102312c */
      wD1 = -(short)wD1; /* Line 635, Address: 0x1023144 */
    }

    if (wD1 >= 2048) { /* Line 638, Address: 0x1023160 */
      sv_move_main2(wD0); /* Line 639, Address: 0x1023170 */
    } /* Line 640, Address: 0x102317c */
    else {
      if ((short)wD0 > 6) { /* Line 642, Address: 0x1023184 */
        sv_move_plus(1536); /* Line 643, Address: 0x10231a4 */
      } /* Line 644, Address: 0x10231b0 */
      else if ((short)wD0 < -6) { /* Line 645, Address: 0x10231b8 */
        sv_move_minus(1536); /* Line 646, Address: 0x10231d8 */
      } /* Line 647, Address: 0x10231e4 */
      else {
        sv_move_sub(wD0); /* Line 649, Address: 0x10231ec */
      }
    }
  }
} /* Line 653, Address: 0x10231f8 */



void sv_move_main1(unsigned short wD0) { /* Line 657, Address: 0x1023210 */

  if ((short)wD0 > 2) { /* Line 659, Address: 0x102321c */
    sv_move_plus(512); /* Line 660, Address: 0x102323c */
  } /* Line 661, Address: 0x1023248 */
  else if ((short)wD0 < -2) { /* Line 662, Address: 0x1023250 */
    sv_move_minus(512); /* Line 663, Address: 0x1023270 */
  } /* Line 664, Address: 0x102327c */
  else {
    sv_move_sub(wD0); /* Line 666, Address: 0x1023284 */
  }

} /* Line 669, Address: 0x1023290 */


void sv_move_main2(unsigned short wD0) { /* Line 672, Address: 0x10232a0 */

  if ((short)wD0 > 16) { /* Line 674, Address: 0x10232ac */
    sv_move_plus(4096); /* Line 675, Address: 0x10232cc */
  } /* Line 676, Address: 0x10232d8 */
  else if ((short)wD0 < -16) { /* Line 677, Address: 0x10232e0 */
    sv_move_minus(4096); /* Line 678, Address: 0x1023300 */
  } /* Line 679, Address: 0x102330c */
  else {
    sv_move_sub(wD0); /* Line 681, Address: 0x1023314 */
  }

} /* Line 684, Address: 0x1023320 */


void sv_move_sub2(void) { /* Line 687, Address: 0x1023330 */
  limmoveflag = 0; /* Line 688, Address: 0x1023338 */
  sv_move_sub(0); /* Line 689, Address: 0x1023340 */
} /* Line 690, Address: 0x102334c */


void sv_move_sub(unsigned short wD0) { /* Line 693, Address: 0x1023360 */
  int_union lD1;

  lD1.w.h = 0; /* Line 696, Address: 0x102336c */
  lD1.w.l = wD0; /* Line 697, Address: 0x1023370 */
  lD1.l += scra_v_posit.w.h; /* Line 698, Address: 0x1023378 */
  if ((short)wD0 > 0) { /* Line 699, Address: 0x1023394 */
    scrv_down_ch(lD1); /* Line 700, Address: 0x10233b0 */
  } /* Line 701, Address: 0x10233bc */
  else {
    scrv_up_ch(lD1); /* Line 703, Address: 0x10233c4 */
  }

} /* Line 706, Address: 0x10233d0 */




void sv_move_minus(unsigned short wD1) { /* Line 711, Address: 0x10233e0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 715, Address: 0x10233f0 */
  lD1.l <<= 8; /* Line 716, Address: 0x102340c */
  lD1.l += scra_v_posit.l; /* Line 717, Address: 0x1023418 */

  wk = lD1.w.h; /* Line 719, Address: 0x102342c */
  lD1.w.h = lD1.w.l; /* Line 720, Address: 0x1023434 */
  lD1.w.l = wk; /* Line 721, Address: 0x102343c */
  scrv_up_ch(lD1); /* Line 722, Address: 0x1023440 */
} /* Line 723, Address: 0x102344c */



void scrv_up_ch(int_union lD1) { /* Line 727, Address: 0x1023460 */
  if (scralim_up >= lD1.w.l) { /* Line 728, Address: 0x102346c */
    if (lD1.w.l < -255) { /* Line 729, Address: 0x1023494 */
      lD1.w.l &= 2047; /* Line 730, Address: 0x10234ac */
      actwk[0].yposi.w.h &= 2047; /* Line 731, Address: 0x10234b8 */
      scra_v_posit.w.h &= 2047; /* Line 732, Address: 0x10234cc */
      scrb_v_posit.w.h &= 1023; /* Line 733, Address: 0x10234e0 */
    } /* Line 734, Address: 0x10234f4 */
    else {

      lD1.w.l = scralim_up; /* Line 737, Address: 0x10234fc */
    }
  }
  scrv_move(lD1); /* Line 740, Address: 0x1023508 */

} /* Line 742, Address: 0x1023514 */





void sv_move_plus(unsigned short wD1) { /* Line 748, Address: 0x1023530 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 752, Address: 0x1023540 */
  lD1.w.l = wD1; /* Line 753, Address: 0x1023544 */
  lD1.l <<= 8; /* Line 754, Address: 0x102354c */
  lD1.l += scra_v_posit.l; /* Line 755, Address: 0x1023558 */

  wk = lD1.w.h; /* Line 757, Address: 0x102356c */
  lD1.w.h = lD1.w.l; /* Line 758, Address: 0x1023574 */
  lD1.w.l = wk; /* Line 759, Address: 0x102357c */

  scrv_down_ch(lD1); /* Line 761, Address: 0x1023580 */

} /* Line 763, Address: 0x102358c */



void scrv_down_ch(int_union lD1) { /* Line 767, Address: 0x10235a0 */
  if (scralim_down <= lD1.w.l) { /* Line 768, Address: 0x10235ac */
    lD1.w.l -= 2048; /* Line 769, Address: 0x10235d4 */
    if (lD1.w.l > 0) { /* Line 770, Address: 0x10235e0 */
      actwk[0].yposi.w.h &= 2047; /* Line 771, Address: 0x10235f4 */
      scra_v_posit.w.h -= 2048; /* Line 772, Address: 0x1023608 */
      scrb_v_posit.w.h &= 1023; /* Line 773, Address: 0x102361c */
    } /* Line 774, Address: 0x1023630 */
    else {
      lD1.w.l = scralim_down; /* Line 776, Address: 0x1023638 */
    }
  }
  scrv_move(lD1); /* Line 779, Address: 0x1023644 */

} /* Line 781, Address: 0x1023650 */


void scrv_move(int_union lD1) { /* Line 784, Address: 0x1023660 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 787, Address: 0x1023670 */

  wk = lD1.w.h; /* Line 789, Address: 0x102367c */
  lD1.w.h = lD1.w.l; /* Line 790, Address: 0x1023684 */
  lD1.w.l = wk; /* Line 791, Address: 0x102368c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 793, Address: 0x1023690 */
  scra_v_posit.l = lD1.l; /* Line 794, Address: 0x10236b8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 797, Address: 0x10236c4 */
    scra_v_count ^= 16; /* Line 798, Address: 0x10236f8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 799, Address: 0x102370c */

      scrflaga.b.h |= 2; /* Line 801, Address: 0x1023738 */
    } /* Line 802, Address: 0x102374c */
    else {
      scrflaga.b.h |= 1; /* Line 804, Address: 0x1023754 */
    }
  }


} /* Line 809, Address: 0x1023768 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 813, Address: 0x1023780 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 816, Address: 0x102378c */
  lD0.l += lD4.l; /* Line 817, Address: 0x102379c */
  scrb_h_posit.l = lD0.l; /* Line 818, Address: 0x10237ac */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 820, Address: 0x10237b8 */

    scrb_h_count ^= 16; /* Line 822, Address: 0x10237ec */
    lD0.l -= lD2.l; /* Line 823, Address: 0x1023800 */
    if ((long int)lD0.l < 0) { /* Line 824, Address: 0x1023810 */
      scrflagb.b.h |= 4; /* Line 825, Address: 0x1023824 */
    } /* Line 826, Address: 0x1023838 */
    else {

      scrflagb.b.h |= 8; /* Line 829, Address: 0x1023840 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 834, Address: 0x1023854 */
  lD0.l += lD5.l; /* Line 835, Address: 0x1023864 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 836, Address: 0x1023874 */
  scrb_v_posit.l = lD0.l; /* Line 837, Address: 0x102388c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 839, Address: 0x1023898 */

    scrb_v_count ^= 16; /* Line 841, Address: 0x10238cc */
    lD0.l -= lD3.l; /* Line 842, Address: 0x10238e0 */
    if ((long int)lD0.l < 0) { /* Line 843, Address: 0x10238f0 */
      scrflagb.b.h |= 1; /* Line 844, Address: 0x1023904 */
    } /* Line 845, Address: 0x1023918 */
    else {

      scrflagb.b.h |= 2; /* Line 848, Address: 0x1023920 */
    }
  }


} /* Line 853, Address: 0x1023934 */






void scrollb_v(unsigned short wD0) { /* Line 860, Address: 0x1023940 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 863, Address: 0x102394c */
  scrb_v_posit.w.h = wD0; /* Line 864, Address: 0x1023958 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 866, Address: 0x1023964 */
    scrb_v_count ^= 16; /* Line 867, Address: 0x1023990 */
    if ((short)wD3 > (short)wD0) { /* Line 868, Address: 0x10239a4 */
      scrflagb.b.h |= 1; /* Line 869, Address: 0x10239d4 */
    } /* Line 870, Address: 0x10239e8 */
    else {

      scrflagb.b.h |= 2; /* Line 873, Address: 0x10239f0 */
    }
  }


} /* Line 878, Address: 0x1023a04 */



void scrollb_h(int lD4, int flagb) { /* Line 882, Address: 0x1023a20 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 886, Address: 0x1023a30 */
  lD0.l = lD2.l + lD4; /* Line 887, Address: 0x1023a3c */
  scrb_h_posit.l = lD0.l; /* Line 888, Address: 0x1023a4c */

  lD1.w.h = lD0.w.l; /* Line 890, Address: 0x1023a58 */
  lD1.w.l = lD0.w.h; /* Line 891, Address: 0x1023a60 */
  lD1.w.l &= 16; /* Line 892, Address: 0x1023a68 */

  bD3 = scrb_h_count; /* Line 894, Address: 0x1023a74 */
  lD1.b.b4 ^= bD3; /* Line 895, Address: 0x1023a80 */
  if (!lD1.b.b4) { /* Line 896, Address: 0x1023a94 */
    scrb_h_count ^= 16; /* Line 897, Address: 0x1023aa0 */
    lD0.l -= lD2.l; /* Line 898, Address: 0x1023ab4 */
    if ((long int)lD0.l < 0) { /* Line 899, Address: 0x1023ac4 */
      scrflagb.b.h |= flagb; /* Line 900, Address: 0x1023ad8 */
    } /* Line 901, Address: 0x1023af4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 904, Address: 0x1023afc */
    }
  }


} /* Line 909, Address: 0x1023b1c */


void scrollc_h(int lD4, int flagc) { /* Line 912, Address: 0x1023b30 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 916, Address: 0x1023b40 */
  lD0.l = lD2.l + lD4; /* Line 917, Address: 0x1023b4c */
  scrc_h_posit.l = lD0.l; /* Line 918, Address: 0x1023b5c */

  lD1.w.h = lD0.w.l; /* Line 920, Address: 0x1023b68 */
  lD1.w.l = lD0.w.h; /* Line 921, Address: 0x1023b70 */
  lD1.w.l &= 16; /* Line 922, Address: 0x1023b78 */

  bD3 = scrc_h_count; /* Line 924, Address: 0x1023b84 */
  lD1.b.b4 ^= bD3; /* Line 925, Address: 0x1023b90 */
  if (!lD1.b.b4) { /* Line 926, Address: 0x1023ba4 */
    scrc_h_count ^= 16; /* Line 927, Address: 0x1023bb0 */
    lD0.l -= lD2.l; /* Line 928, Address: 0x1023bc4 */
    if ((long int)lD0.l < 0) { /* Line 929, Address: 0x1023bd4 */
      scrflagc.b.h |= flagc; /* Line 930, Address: 0x1023be8 */
    } /* Line 931, Address: 0x1023c04 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 934, Address: 0x1023c0c */
    }
  }


} /* Line 939, Address: 0x1023c2c */











void scrollz_h(int lD4, int flagz) { /* Line 951, Address: 0x1023c40 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 955, Address: 0x1023c50 */
  lD0.l = lD2.l + lD4; /* Line 956, Address: 0x1023c5c */
  scrz_h_posit.l = lD0.l; /* Line 957, Address: 0x1023c6c */

  lD1.w.h = lD0.w.l; /* Line 959, Address: 0x1023c78 */
  lD1.w.l = lD0.w.h; /* Line 960, Address: 0x1023c80 */
  lD1.w.l &= 16; /* Line 961, Address: 0x1023c88 */

  bD3 = scrz_h_count; /* Line 963, Address: 0x1023c94 */
  lD1.b.b4 ^= bD3; /* Line 964, Address: 0x1023ca0 */
  if (!lD1.b.b4) { /* Line 965, Address: 0x1023cb4 */
    scrz_h_count ^= 16; /* Line 966, Address: 0x1023cc0 */
    lD0.l -= lD2.l; /* Line 967, Address: 0x1023cd4 */
    if ((long int)lD0.l < 0) { /* Line 968, Address: 0x1023ce4 */
      scrflagz.b.h |= flagz; /* Line 969, Address: 0x1023cf8 */
    } /* Line 970, Address: 0x1023d14 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 973, Address: 0x1023d1c */
    }
  }


} /* Line 978, Address: 0x1023d3c */













void scrollwrtadva(void) { /* Line 992, Address: 0x1023d50 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 998, Address: 0x1023d6c */
  wH_posiw = scrb_h_posit.w.h; /* Line 999, Address: 0x1023d70 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1000, Address: 0x1023d7c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1001, Address: 0x1023d88 */
  pScrFlag = &scrflagb.b.h; /* Line 1002, Address: 0x1023d90 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1003, Address: 0x1023d98 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1005, Address: 0x1023dac */
  wV_posiw = scrc_v_posit.w.h; /* Line 1006, Address: 0x1023db8 */
  pScrFlag = &scrflagc.b.h; /* Line 1007, Address: 0x1023dc4 */
  scrollwrtc(); /* Line 1008, Address: 0x1023dcc */

} /* Line 1010, Address: 0x1023dd4 */












void scrollwrt(void) { /* Line 1023, Address: 0x1023e00 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1032, Address: 0x1023e20 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1033, Address: 0x1023e24 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1034, Address: 0x1023e30 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1035, Address: 0x1023e3c */
  pScrFlag = &scrflagbw.b.h; /* Line 1036, Address: 0x1023e44 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1037, Address: 0x1023e4c */

  VramBase = 16384; /* Line 1039, Address: 0x1023e60 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1040, Address: 0x1023e64 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1041, Address: 0x1023e70 */
  pMapWk = (unsigned char*)mapwka; /* Line 1042, Address: 0x1023e7c */
  pScrFlag = &scrflagaw.b.h; /* Line 1043, Address: 0x1023e84 */

  if (*pScrFlag) { /* Line 1045, Address: 0x1023e8c */
    if (*pScrFlag & 1) { /* Line 1046, Address: 0x1023e98 */
      *pScrFlag &= 254; /* Line 1047, Address: 0x1023eac */

      lD4.l = -16; /* Line 1049, Address: 0x1023eb8 */
      wD5 = 65520; /* Line 1050, Address: 0x1023ec0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1052, Address: 0x1023ec8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1054, Address: 0x1023ee8 */
    }




    if (*pScrFlag & 2) { /* Line 1060, Address: 0x1023f14 */
      *pScrFlag &= 253; /* Line 1061, Address: 0x1023f28 */

      lD4.l = 224; /* Line 1063, Address: 0x1023f34 */
      wD5 = 65520; /* Line 1064, Address: 0x1023f3c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1065, Address: 0x1023f44 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1067, Address: 0x1023f64 */
    }




    if (*pScrFlag & 4) { /* Line 1073, Address: 0x1023f90 */
      *pScrFlag &= 251; /* Line 1074, Address: 0x1023fa4 */

      lD4.l = -16; /* Line 1076, Address: 0x1023fb0 */
      wD5 = 65520; /* Line 1077, Address: 0x1023fb8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1078, Address: 0x1023fc0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1080, Address: 0x1023fe0 */
    }




    if (*pScrFlag & 8) { /* Line 1086, Address: 0x102400c */
      *pScrFlag &= 247; /* Line 1087, Address: 0x1024020 */

      lD4.l = -16; /* Line 1089, Address: 0x102402c */
      wD5 = 320; /* Line 1090, Address: 0x1024034 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1091, Address: 0x102403c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1093, Address: 0x102405c */
    }
  }






} /* Line 1102, Address: 0x1024088 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1119, Address: 0x10240b0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1130, Address: 0x10240dc */

  if (*pScrFlag & 1) { /* Line 1132, Address: 0x10240e4 */
    *pScrFlag &= 254; /* Line 1133, Address: 0x10240fc */
  } /* Line 1134, Address: 0x1024110 */
  else {
    *pScrFlag &= 254; /* Line 1136, Address: 0x1024118 */

    if (*pScrFlag & 2) { /* Line 1138, Address: 0x102412c */
      *pScrFlag &= 253; /* Line 1139, Address: 0x1024144 */
      lD4.w.l = 224; /* Line 1140, Address: 0x1024158 */
    } /* Line 1141, Address: 0x1024160 */
    else {
      *pScrFlag &= 253; /* Line 1143, Address: 0x1024168 */
      goto label1; /* Line 1144, Address: 0x102417c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1149, Address: 0x1024184 */
  wD0 &= 127; /* Line 1150, Address: 0x10241d4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1151, Address: 0x10241dc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1157, Address: 0x10241fc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1158, Address: 0x102421c */
  if (wD0 != 0) { /* Line 1159, Address: 0x1024240 */
    wD5 = 65520; /* Line 1160, Address: 0x102424c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1161, Address: 0x1024254 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1163, Address: 0x1024274 */



  } /* Line 1167, Address: 0x10242a0 */
  else {

    wD5 = 0; /* Line 1170, Address: 0x10242a8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1171, Address: 0x10242ac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1175, Address: 0x10242cc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1182, Address: 0x10242f8 */






    lD4.l = -16; /* Line 1189, Address: 0x102430c */
    wD5 = 65520; /* Line 1190, Address: 0x1024314 */
    if (*pScrFlag & 168) { /* Line 1191, Address: 0x102431c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1192, Address: 0x1024334 */
      wD5 = 320; /* Line 1193, Address: 0x1024354 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1197, Address: 0x102435c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1199, Address: 0x102438c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1200, Address: 0x1024398 */



    for (i = 0; i < 16; ++i) { /* Line 1204, Address: 0x10243a8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1205, Address: 0x10243b4 */
      if (wD0 != 0) { /* Line 1206, Address: 0x10243d4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1207, Address: 0x10243e0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1208, Address: 0x102440c */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1209, Address: 0x102442c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1211, Address: 0x1024450 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1214, Address: 0x1024474 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1216, Address: 0x1024494 */
        }
      }
      lD4.w.l += 16; /* Line 1219, Address: 0x10244a8 */
    } /* Line 1220, Address: 0x10244b4 */
    *pScrFlag = 0; /* Line 1221, Address: 0x10244c4 */
  }
} /* Line 1223, Address: 0x10244cc */





void scrollwrtc(void) {} /* Line 1229, Address: 0x1024500 */




void scrollwrtz(void) {} /* Line 1234, Address: 0x1024510 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1252, Address: 0x1024520 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1265, Address: 0x1024548 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1268, Address: 0x1024568 */
    pTilePoint->x += 2; /* Line 1269, Address: 0x102457c */
    if (pTilePoint->x >= 64) { /* Line 1270, Address: 0x1024590 */
      pTilePoint->x -= 64; /* Line 1271, Address: 0x10245a4 */
    }
    xOffs += 16; /* Line 1273, Address: 0x10245b8 */
  } while (--lpcnt >= 0); /* Line 1274, Address: 0x10245c4 */
} /* Line 1275, Address: 0x10245d8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1279, Address: 0x10245f0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1283, Address: 0x1024618 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1286, Address: 0x1024638 */
    pTilePoint->x += 2; /* Line 1287, Address: 0x102464c */
    if (pTilePoint->x >= 64) { /* Line 1288, Address: 0x1024660 */
      pTilePoint->x -= 64; /* Line 1289, Address: 0x1024674 */
    }
    xOffs += 16; /* Line 1291, Address: 0x1024688 */
  } while (--lpcnt >= 0); /* Line 1292, Address: 0x1024694 */
} /* Line 1293, Address: 0x10246a8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1313, Address: 0x10246c0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1317, Address: 0x10246e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1320, Address: 0x1024708 */
    pTilePoint->y += 2; /* Line 1321, Address: 0x102471c */
    if (pTilePoint->y >= 32) { /* Line 1322, Address: 0x102472c */
      pTilePoint->y -= 32; /* Line 1323, Address: 0x1024740 */
    }
    yOffs += 16; /* Line 1325, Address: 0x1024750 */
  } while (--lpcnt >= 0); /* Line 1326, Address: 0x102475c */
} /* Line 1327, Address: 0x1024770 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1346, Address: 0x1024780 */
  int base = 0; /* Line 1347, Address: 0x10247b4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1352, Address: 0x10247b8 */

    base = 1; /* Line 1354, Address: 0x10247c8 */
  } /* Line 1355, Address: 0x10247cc */
  else if (VramBase == 16384) { /* Line 1356, Address: 0x10247d4 */

    base = 0; /* Line 1358, Address: 0x10247e4 */
  }
  x = pTilePoint->x; /* Line 1360, Address: 0x10247e8 */
  y = pTilePoint->y; /* Line 1361, Address: 0x10247f0 */


  frip = BlkIndex & 6144; /* Line 1364, Address: 0x10247f8 */
  BlkIndex &= 1023; /* Line 1365, Address: 0x1024800 */
  if (frip == 6144) { /* Line 1366, Address: 0x102480c */

    p0 = 3, p1 = 2; /* Line 1368, Address: 0x1024818 */
    p2 = 1, p3 = 0; /* Line 1369, Address: 0x1024820 */
  } /* Line 1370, Address: 0x1024828 */
  else if (frip & 4096) { /* Line 1371, Address: 0x1024830 */

    p0 = 2, p1 = 3; /* Line 1373, Address: 0x102483c */
    p2 = 0, p3 = 1; /* Line 1374, Address: 0x1024844 */
  } /* Line 1375, Address: 0x102484c */
  else if (frip & 2048) { /* Line 1376, Address: 0x1024854 */

    p0 = 1, p1 = 0; /* Line 1378, Address: 0x1024860 */
    p2 = 3, p3 = 2; /* Line 1379, Address: 0x1024868 */
  } /* Line 1380, Address: 0x1024870 */
  else {

    p0 = 0, p1 = 1; /* Line 1383, Address: 0x1024878 */
    p2 = 2, p3 = 3; /* Line 1384, Address: 0x1024880 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1387, Address: 0x1024888 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1388, Address: 0x10248cc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1389, Address: 0x1024910 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1390, Address: 0x1024954 */

} /* Line 1392, Address: 0x1024998 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1410, Address: 0x10249d0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1411, Address: 0x10249f0 */
} /* Line 1412, Address: 0x1024a10 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1414, Address: 0x1024a20 */
  wH_posiw = 0; /* Line 1415, Address: 0x1024a40 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1416, Address: 0x1024a44 */
} /* Line 1417, Address: 0x1024a64 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1424, Address: 0x1024a80 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1430, Address: 0x1024ab0 */
  yOffs += wV_posiw; /* Line 1431, Address: 0x1024ac0 */





  if ((short)xOffs < 0) /* Line 1437, Address: 0x1024ad0 */
    xOffs = 0; /* Line 1438, Address: 0x1024aec */
  if ((short)yOffs < 0) /* Line 1439, Address: 0x1024af0 */
    yOffs = 0; /* Line 1440, Address: 0x1024b0c */
  if ((short)xOffs >= 16384) /* Line 1441, Address: 0x1024b10 */
    xOffs = 16383; /* Line 1442, Address: 0x1024b30 */
  if ((short)yOffs >= 2048) /* Line 1443, Address: 0x1024b38 */
    yOffs = 2047; /* Line 1444, Address: 0x1024b58 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1445, Address: 0x1024b60 */
  if (i < 0) i = 0; /* Line 1446, Address: 0x1024ba8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1448, Address: 0x1024bb4 */

  if (ScreenNo) { /* Line 1450, Address: 0x1024bd0 */




    xOffs &= 32767; /* Line 1455, Address: 0x1024bd8 */
    yOffs &= 32767; /* Line 1456, Address: 0x1024be4 */


    xBlk = xOffs; /* Line 1459, Address: 0x1024bf0 */
    xBlk %= 256; /* Line 1460, Address: 0x1024bf8 */
    xBlk /= 16; /* Line 1461, Address: 0x1024c18 */
    yBlk = yOffs; /* Line 1462, Address: 0x1024c34 */
    yBlk %= 256; /* Line 1463, Address: 0x1024c3c */
    yBlk /= 16; /* Line 1464, Address: 0x1024c5c */

    lpw = pmapwk; /* Line 1466, Address: 0x1024c78 */
    lpw += xBlk; /* Line 1467, Address: 0x1024c80 */
    lpw += yBlk * 16; /* Line 1468, Address: 0x1024c88 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1469, Address: 0x1024c94 */
    *pIndex = *lpw; /* Line 1470, Address: 0x1024cac */

    return 1; /* Line 1472, Address: 0x1024cbc */
  }

  *pIndex = 0; /* Line 1475, Address: 0x1024cc8 */
  return 0; /* Line 1476, Address: 0x1024cd0 */
} /* Line 1477, Address: 0x1024cd4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1497, Address: 0x1024d00 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1505, Address: 0x1024d28 */
  if (ScreenNo) { /* Line 1506, Address: 0x1024d8c */





    xBlk = xOffs; /* Line 1512, Address: 0x1024d94 */
    xBlk %= 256; /* Line 1513, Address: 0x1024d9c */
    xBlk /= 16; /* Line 1514, Address: 0x1024dbc */
    yBlk = yOffs; /* Line 1515, Address: 0x1024dd8 */
    yBlk %= 256; /* Line 1516, Address: 0x1024de0 */
    yBlk /= 16; /* Line 1517, Address: 0x1024e00 */


    lpw = pmapwk; /* Line 1520, Address: 0x1024e1c */
    lpw += xBlk; /* Line 1521, Address: 0x1024e24 */
    lpw += yBlk * 16; /* Line 1522, Address: 0x1024e2c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1523, Address: 0x1024e38 */
    *ppBlockNo = lpw; /* Line 1524, Address: 0x1024e50 */
    *pIndex = *lpw; /* Line 1525, Address: 0x1024e58 */




    return 1; /* Line 1530, Address: 0x1024e68 */
  }

  *pIndex = 0; /* Line 1533, Address: 0x1024e74 */
  return 0; /* Line 1534, Address: 0x1024e7c */
} /* Line 1535, Address: 0x1024e80 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1549, Address: 0x1024ea0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1556, Address: 0x1024ebc */
  pMapWk = (unsigned char*)mapwka; /* Line 1557, Address: 0x1024ec0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1558, Address: 0x1024ec8 */
    *pBlockIndex = BlockNo; /* Line 1559, Address: 0x1024eec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1560, Address: 0x1024ef8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1561, Address: 0x1024f10 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1562, Address: 0x1024f24 */
    }
  }


} /* Line 1567, Address: 0x1024f3c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1581, Address: 0x1024f60 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1582, Address: 0x1024f6c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1583, Address: 0x1024f98 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1584, Address: 0x1024fe4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1585, Address: 0x1025010 */

          return 0; /* Line 1587, Address: 0x102505c */
        }
      }
    }
  }

  return 1; /* Line 1593, Address: 0x1025068 */
} /* Line 1594, Address: 0x102506c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1611, Address: 0x1025080 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1612, Address: 0x102509c */

} /* Line 1614, Address: 0x10250b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1616, Address: 0x10250d0 */
  wH_posiw = 0; /* Line 1617, Address: 0x10250ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1618, Address: 0x10250f0 */

} /* Line 1620, Address: 0x102510c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1622, Address: 0x1025120 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1623, Address: 0x1025134 */

} /* Line 1625, Address: 0x1025150 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1627, Address: 0x1025160 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1628, Address: 0x102517c */

} /* Line 1630, Address: 0x1025198 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1632, Address: 0x10251b0 */
  xOffs += wH_posiw; /* Line 1633, Address: 0x10251c8 */
  yOffs += wV_posiw; /* Line 1634, Address: 0x10251d8 */
  yOffs &= 240; /* Line 1635, Address: 0x10251e8 */
  xOffs &= 496; /* Line 1636, Address: 0x10251f4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1638, Address: 0x1025200 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1639, Address: 0x102522c */


} /* Line 1642, Address: 0x1025258 */















void mapwrt(void) { /* Line 1658, Address: 0x1025270 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1663, Address: 0x1025288 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1664, Address: 0x1025294 */
  pMapWk = (unsigned char*)mapwka; /* Line 1665, Address: 0x10252a0 */
  VramBase = 16384; /* Line 1666, Address: 0x10252a8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1667, Address: 0x10252ac */



  pMapWk = (unsigned char*)mapwkb; /* Line 1671, Address: 0x10252c4 */
  VramBase = 24576; /* Line 1672, Address: 0x10252cc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1673, Address: 0x10252d0 */

} /* Line 1675, Address: 0x10252e0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1678, Address: 0x1025300 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1679, Address: 0x1025318 */
} /* Line 1680, Address: 0x1025338 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1685, Address: 0x1025350 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1689, Address: 0x1025370 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1692, Address: 0x102538c */



    wD4 += 16; /* Line 1696, Address: 0x10253b4 */
  } while ((short)--wD6 >= 0); /* Line 1697, Address: 0x10253c0 */

} /* Line 1699, Address: 0x10253e8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1705, Address: 0x1025400 */
  unsigned short wD0, wD4, wD6;
  int_union temp;


  wD4 = 65520; /* Line 1710, Address: 0x102541c */
  wD6 = 15; /* Line 1711, Address: 0x1025424 */

  do {
    temp.l = 0; /* Line 1714, Address: 0x102542c */
    temp.w.l = scrb_v_posit.w.h; /* Line 1715, Address: 0x1025430 */
    wD0 = scrb_v_posit.w.h; /* Line 1716, Address: 0x102543c */
    wD0 += wD4 & 496; /* Line 1717, Address: 0x1025448 */
    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1718, Address: 0x102545c */
    wD4 += 16; /* Line 1719, Address: 0x102547c */
  } while ((short)--wD6 >= 0); /* Line 1720, Address: 0x1025484 */
} /* Line 1721, Address: 0x10254a8 */





















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1743, Address: 0x10254d0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1748, Address: 0x10254f8 */
  wD0 = pWrttbl[wD0]; /* Line 1749, Address: 0x1025508 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1751, Address: 0x1025524 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1752, Address: 0x1025548 */
  if (wD0) { /* Line 1753, Address: 0x1025570 */
    wD5 = 65520; /* Line 1754, Address: 0x102557c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1755, Address: 0x1025584 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1758, Address: 0x10255a0 */



  } /* Line 1762, Address: 0x10255c8 */
  else {

    wD5 = 0; /* Line 1765, Address: 0x10255d0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1766, Address: 0x10255d4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1770, Address: 0x10255f0 */
  }





} /* Line 1777, Address: 0x1025618 */



void mapinit(void) { /* Line 1781, Address: 0x1025640 */

  colorset2(mapinittbl.colorno2); /* Line 1783, Address: 0x1025648 */
  colorset(mapinittbl.colorno2); /* Line 1784, Address: 0x102565c */


  if (play_start & 2) divdevset(); /* Line 1787, Address: 0x1025670 */
} /* Line 1788, Address: 0x1025690 */










void mapset(void) {} /* Line 1799, Address: 0x10256a0 */
