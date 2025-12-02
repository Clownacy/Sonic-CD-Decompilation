#include "..\EQU.H"
#include "SCR11C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1C.H"

static unsigned char z11dwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
  6, 6, 2, 4, 4, 4, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0
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
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;






























































































void enecginit() {} /* Line 131, Address: 0x1025230 */




void divdevset() {} /* Line 136, Address: 0x1025240 */












sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 150, Address: 0x1025250 */
  return &actwk[1]; /* Line 151, Address: 0x1025270 */
} /* Line 152, Address: 0x1025278 */










void scr_set() { /* Line 163, Address: 0x1025280 */
  unsigned short scr_dir_tbl[6] = { /* Line 164, Address: 0x102528c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 169, Address: 0x10252c0 */

  i = 0; /* Line 171, Address: 0x1025308 */
  scrar_no = scr_dir_tbl[i++]; /* Line 172, Address: 0x102530c */
  scralim_left = scr_dir_tbl[i]; /* Line 173, Address: 0x1025328 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 174, Address: 0x102533c */
  scralim_right = scr_dir_tbl[i]; /* Line 175, Address: 0x1025358 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 176, Address: 0x102536c */
  scralim_up = scr_dir_tbl[i]; /* Line 177, Address: 0x1025388 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 178, Address: 0x102539c */
  scralim_down = scr_dir_tbl[i]; /* Line 179, Address: 0x10253b8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 180, Address: 0x10253cc */

  scra_h_keep = scralim_left + 576; /* Line 182, Address: 0x10253e8 */
  scra_h_count = 16; /* Line 183, Address: 0x102540c */
  scra_v_count = 16; /* Line 184, Address: 0x1025418 */

  scra_vline = scr_dir_tbl[i++]; /* Line 186, Address: 0x1025424 */
  scra_hline = 160; /* Line 187, Address: 0x1025440 */

  playposiset(); /* Line 189, Address: 0x102544c */
} /* Line 190, Address: 0x1025454 */










void playposiset() { /* Line 201, Address: 0x1025470 */
  unsigned short playpositbl[2] = { 80, 488 }; /* Line 202, Address: 0x1025484 */
  unsigned short endplpositbl[16] = { /* Line 203, Address: 0x10254a0 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { 140, 127, 30, 30 }; /* Line 213, Address: 0x10254d4 */
  short xWk;
  short yWk;
  int i;

  if (plflag) { /* Line 218, Address: 0x1025500 */
    playload(); /* Line 219, Address: 0x1025510 */
    xWk = actwk[0].xposi.w.h; /* Line 220, Address: 0x1025518 */
    yWk = actwk[0].yposi.w.h; /* Line 221, Address: 0x1025528 */
    if (yWk < 0) yWk = 0; /* Line 222, Address: 0x1025538 */
  } /* Line 223, Address: 0x102554c */
  else {
    if (demoflag.w & -32768) { /* Line 225, Address: 0x1025554 */
      xWk = actwk[0].xposi.w.h = endplpositbl[(enddemono - 1) * 2]; /* Line 226, Address: 0x1025574 */
      yWk = actwk[0].yposi.w.h = endplpositbl[(enddemono - 1) * 2 + 1]; /* Line 227, Address: 0x10255a8 */
    } /* Line 228, Address: 0x10255e0 */
    else {
      xWk = actwk[0].xposi.w.h = playpositbl[demoflag.w * 2]; /* Line 230, Address: 0x10255e8 */
      yWk = actwk[0].yposi.w.h = playpositbl[demoflag.w * 2 + 1]; /* Line 231, Address: 0x1025618 */
    }
  }

  if ((unsigned short)xWk > 160) xWk -= 160; /* Line 235, Address: 0x102564c */
  else xWk = 0; /* Line 236, Address: 0x1025674 */
  if ((unsigned short)scralim_right < (unsigned short)xWk) xWk = scralim_right; /* Line 237, Address: 0x1025678 */
  scra_h_posit.w.h = xWk; /* Line 238, Address: 0x10256ac */

  if ((unsigned short)yWk > 96) yWk -= 96; /* Line 240, Address: 0x10256b4 */
  else yWk = 0; /* Line 241, Address: 0x10256dc */
  if (scralim_down < yWk) yWk = scralim_down; /* Line 242, Address: 0x10256e0 */
  scra_v_posit.w.h = yWk; /* Line 243, Address: 0x1025714 */

  scrbinit(xWk, yWk); /* Line 245, Address: 0x102571c */

  i = 0; /* Line 247, Address: 0x102572c */
  loopmapno = playmapnotbl[i++]; /* Line 248, Address: 0x1025730 */
  loopmapno2 = playmapnotbl[i++]; /* Line 249, Address: 0x1025748 */
  ballmapno = playmapnotbl[i++]; /* Line 250, Address: 0x1025760 */
  ballmapno2 = playmapnotbl[i++]; /* Line 251, Address: 0x1025778 */
} /* Line 252, Address: 0x1025790 */











void scrbinit(short xWk, short yWk) { /* Line 264, Address: 0x10257b0 */
  int_union lYwk;

  lYwk.w.h = yWk; /* Line 267, Address: 0x10257c0 */
  lYwk.w.l = 0; /* Line 268, Address: 0x10257c8 */

  lYwk.l = (lYwk.l >> 4) * 2; /* Line 270, Address: 0x10257cc */
  scrb_v_posit.l = lYwk.l; /* Line 271, Address: 0x10257dc */
  scrc_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 272, Address: 0x10257e8 */
  scrz_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 273, Address: 0x1025828 */

  scrc_h_posit.w.h = (unsigned short)(xWk / 4); /* Line 275, Address: 0x1025868 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 8); /* Line 276, Address: 0x10258a0 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 277, Address: 0x10258d8 */

  sMemSet(hscrollwork, 0, 16); /* Line 279, Address: 0x1025918 */
} /* Line 280, Address: 0x1025938 */










void scroll() { /* Line 291, Address: 0x1025950 */
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int i;
  unsigned short wD0, wD1;
  int_union lD2;
  int lD4, lD5;
  short* psHscr;
  static int scaddtbl[4] = {
    65536, 49152, 32768, 16384
  };

  if (scroll_start.b.h) return; /* Line 303, Address: 0x1025978 */

  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 305, Address: 0x1025988 */

  scrchk(); /* Line 307, Address: 0x10259b4 */

  scroll_h(); /* Line 309, Address: 0x10259bc */
  scroll_v(); /* Line 310, Address: 0x10259c4 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 312, Address: 0x10259cc */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 313, Address: 0x10259dc */

  scrollz_h(scra_hz << 5, 64); /* Line 315, Address: 0x10259ec */
  scrollc_h(scra_hz << 6, 16); /* Line 316, Address: 0x1025a0c */

  lD4 = (scra_hz << 4) * 3; /* Line 318, Address: 0x1025a2c */
  lD5 = (scra_vz << 4) * 2; /* Line 319, Address: 0x1025a48 */
  scrollb_hv(lD4, lD5); /* Line 320, Address: 0x1025a60 */

  vscroll.w.l = scrc_v_posit.w.h = scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 322, Address: 0x1025a70 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 324, Address: 0x1025a98 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 325, Address: 0x1025ad0 */

  for (i = 0, psHscr = hscrollwork; i < 4; ++i) { /* Line 327, Address: 0x1025ae4 */
    lD2.w.l = psHscr[0]; /* Line 328, Address: 0x1025af8 */
    lD2.w.h = psHscr[1]; /* Line 329, Address: 0x1025b00 */
    lD2.l += scaddtbl[i]; /* Line 330, Address: 0x1025b08 */
    psHscr[0] = lD2.w.l; /* Line 331, Address: 0x1025b28 */
    psHscr[1] = lD2.w.h; /* Line 332, Address: 0x1025b30 */
    psHscr += 2; /* Line 333, Address: 0x1025b38 */
  } /* Line 334, Address: 0x1025b3c */

  pHScrollWork = &hscrollwork[8]; /* Line 336, Address: 0x1025b4c */

  for (i = 0; i < 4; ++i) *pHScrollWork++ = -(hscrollwork[1] + scrz_h_posit.w.h); /* Line 338, Address: 0x1025b54 */
  for (i = 0; i < 6; ++i) *pHScrollWork++ = -(hscrollwork[3] + scrz_h_posit.w.h); /* Line 339, Address: 0x1025bac */
  for (i = 0; i < 4; ++i) *pHScrollWork++ = -(hscrollwork[5] + scrz_h_posit.w.h); /* Line 340, Address: 0x1025c04 */

  for (i = 0; i < 8; ++i) *pHScrollWork++ = -scrz_h_posit.w.h; /* Line 342, Address: 0x1025c5c */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 343, Address: 0x1025ca0 */
  for (i = 0; i < 6; ++i) *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 344, Address: 0x1025ce4 */

  pHScrollBuff = lphscrollbuff; /* Line 346, Address: 0x1025d28 */

  wD0 = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 348, Address: 0x1025d30 */
  pHScrollWork = &hscrollwork[wD0 / 2] + 8; /* Line 349, Address: 0x1025d58 */
  wD1 = 28; /* Line 350, Address: 0x1025d88 */

  lD2.w.l = scrb_v_posit.w.h & 7; /* Line 352, Address: 0x1025d90 */
  wD0 = *pHScrollWork++; /* Line 353, Address: 0x1025db0 */

  i = 8 - lD2.w.l; /* Line 355, Address: 0x1025dc0 */
  goto label1; /* Line 356, Address: 0x1025dd4 */

  do {
    wD0 = *pHScrollWork++; /* Line 359, Address: 0x1025ddc */
    i = 8; /* Line 360, Address: 0x1025dec */
label1:
    for ( ; i > 0; --i) { /* Line 362, Address: 0x1025df0 */
      pHScrollBuff->w.h = 0; /* Line 363, Address: 0x1025df8 */
      pHScrollBuff->w.l = wD0; /* Line 364, Address: 0x1025dfc */
      ++pHScrollBuff; /* Line 365, Address: 0x1025e00 */
    }; /* Line 366, Address: 0x1025e04 */
  } while ((short)--wD1 != -1); /* Line 367, Address: 0x1025e10 */
} /* Line 368, Address: 0x1025e38 */










void scroll_h() { /* Line 379, Address: 0x1025e70 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 382, Address: 0x1025e7c */
  scrh_move(); /* Line 383, Address: 0x1025e88 */
  if ((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) { /* Line 384, Address: 0x1025e90 */
    scra_h_count ^= 16; /* Line 385, Address: 0x1025ec4 */
    if ((short)wD4 > scra_h_posit.w.h) scrflaga.b.h |= 4; /* Line 386, Address: 0x1025ed8 */
    else scrflaga.b.h |= 8; /* Line 387, Address: 0x1025f20 */
  }
} /* Line 389, Address: 0x1025f34 */


void scrh_move() { /* Line 392, Address: 0x1025f50 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 395, Address: 0x1025f5c */
  if (!wD0) scra_hz = 0; /* Line 396, Address: 0x1025f9c */
  else if ((short)wD0 < 0) left_check(wD0); /* Line 397, Address: 0x1025fb4 */
  else right_check(wD0); /* Line 398, Address: 0x1025fe0 */
} /* Line 399, Address: 0x1025fec */


void right_check(unsigned short wD0) { /* Line 402, Address: 0x1026000 */
  unsigned short wD1;

  if ((short)wD0 > 16) wD0 = 16; /* Line 405, Address: 0x102600c */
  wD0 += scra_h_posit.w.h; /* Line 406, Address: 0x1026034 */
  if (scralim_right < (short)wD0) wD0 = scralim_right; /* Line 407, Address: 0x102604c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 408, Address: 0x1026088 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 409, Address: 0x10260ac */
  scra_h_posit.w.h = wD0; /* Line 410, Address: 0x10260dc */
  scra_hz = wD1; /* Line 411, Address: 0x10260e8 */
} /* Line 412, Address: 0x10260f0 */


void left_check(unsigned short wD0) { /* Line 415, Address: 0x1026100 */
  unsigned short wD1;

  if ((short)wD0 < -16) wD0 = 65520; /* Line 418, Address: 0x102610c */
  wD0 += scra_h_posit.w.h; /* Line 419, Address: 0x1026134 */
  if (scralim_left > (short)wD0) wD0 = scralim_left; /* Line 420, Address: 0x102614c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 421, Address: 0x1026188 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 422, Address: 0x10261ac */
  scra_h_posit.w.h = wD0; /* Line 423, Address: 0x10261dc */
  scra_hz = wD1; /* Line 424, Address: 0x10261e8 */
} /* Line 425, Address: 0x10261f0 */










void scroll_v() { /* Line 436, Address: 0x1026200 */
  short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 439, Address: 0x102620c */
  if (actwk[0].cddat & 4) wD0 -= 5; /* Line 440, Address: 0x1026240 */
  if (actwk[0].cddat & 2) { /* Line 441, Address: 0x1026264 */
    wD0 += 32; /* Line 442, Address: 0x102627c */
    if (wD0 < scra_vline) { /* Line 443, Address: 0x1026288 */
      wD0 -= scra_vline; /* Line 444, Address: 0x10262ac */
      sv_move_main2(wD0); /* Line 445, Address: 0x10262c0 */
      return; /* Line 446, Address: 0x10262cc */
    }
    if (wD0 >= scra_vline + 64) { /* Line 448, Address: 0x10262d4 */
      wD0 -= scra_vline + 64; /* Line 449, Address: 0x10262fc */
      sv_move_main2(wD0); /* Line 450, Address: 0x1026324 */
      return; /* Line 451, Address: 0x1026330 */
    }

    wD0 -= scra_vline + 64; /* Line 454, Address: 0x1026338 */
    if (!limmoveflag) goto label1; /* Line 455, Address: 0x1026360 */
    sv_move_sub2(); /* Line 456, Address: 0x1026370 */
    return; /* Line 457, Address: 0x1026378 */
  }



  if ((wD0 -= scra_vline) != 0) { /* Line 462, Address: 0x1026380 */
    sv_move_main(wD0); /* Line 463, Address: 0x10263ac */
    return; /* Line 464, Address: 0x10263b8 */
  }
  if (limmoveflag) { /* Line 466, Address: 0x10263c0 */
    sv_move_sub2(); /* Line 467, Address: 0x10263d0 */
    return; /* Line 468, Address: 0x10263d8 */
  }
label1:
  scra_vz = 0; /* Line 471, Address: 0x10263e0 */
} /* Line 472, Address: 0x10263e8 */


void sv_move_main(short wD0) { /* Line 475, Address: 0x1026400 */
  short wD1;

  if (scra_vline != 96) sv_move_main1(wD0); /* Line 478, Address: 0x1026410 */
  else {
    wD1 = actwk[0].mspeed.w; /* Line 480, Address: 0x1026440 */
    if (wD1 < 0) wD1 *= -1; /* Line 481, Address: 0x1026450 */
    if (wD1 >= 2048) { /* Line 482, Address: 0x102646c */
      sv_move_main2(wD0); /* Line 483, Address: 0x1026480 */
      return; /* Line 484, Address: 0x102648c */
    }
    if (wD0 > 6) sv_move_plus(1536); /* Line 486, Address: 0x1026494 */
    else if (wD0 < -6) sv_move_minus(1536); /* Line 487, Address: 0x10264c0 */
    else sv_move_sub(wD0); /* Line 488, Address: 0x10264ec */
  }
} /* Line 490, Address: 0x10264f8 */


void sv_move_main1(short wD0) { /* Line 493, Address: 0x1026510 */
  if (wD0 > 2) sv_move_plus(512); /* Line 494, Address: 0x102651c */
  else if (wD0 < -2) sv_move_minus(512); /* Line 495, Address: 0x1026548 */
  else sv_move_sub(wD0); /* Line 496, Address: 0x1026574 */
} /* Line 497, Address: 0x1026580 */


void sv_move_main2(short wD0) { /* Line 500, Address: 0x1026590 */
  if ((short)wD0 > 16) sv_move_plus(4096); /* Line 501, Address: 0x102659c */
  else if ((short)wD0 < -16) sv_move_minus(4096); /* Line 502, Address: 0x10265c8 */
  else sv_move_sub(wD0); /* Line 503, Address: 0x10265f4 */
} /* Line 504, Address: 0x1026600 */


void sv_move_sub2() { /* Line 507, Address: 0x1026610 */
  limmoveflag = 0; /* Line 508, Address: 0x1026618 */
  sv_move_sub(0); /* Line 509, Address: 0x1026620 */
} /* Line 510, Address: 0x102662c */


void sv_move_sub(short wD0) { /* Line 513, Address: 0x1026640 */
  int_union lD1;

  lD1.w.h = 0; /* Line 516, Address: 0x102664c */
  lD1.w.l = wD0 + scra_v_posit.w.h; /* Line 517, Address: 0x1026650 */
  if (wD0 < 0) scrv_up_ch(lD1); /* Line 518, Address: 0x102667c */
  else scrv_down_ch(lD1); /* Line 519, Address: 0x10266a4 */
} /* Line 520, Address: 0x10266b0 */


void sv_move_minus(short wD1) { /* Line 523, Address: 0x10266c0 */
  int_union lD1;
  short wk;

  lD1.l = (-wD1 << 8) + scra_v_posit.l; /* Line 527, Address: 0x10266d0 */

  wk = lD1.w.h; /* Line 529, Address: 0x10266f4 */
  lD1.w.h = lD1.w.l; /* Line 530, Address: 0x1026700 */
  lD1.w.l = wk; /* Line 531, Address: 0x1026708 */
  scrv_up_ch(lD1); /* Line 532, Address: 0x102670c */
} /* Line 533, Address: 0x1026718 */


void scrv_up_ch(int_union lD1) { /* Line 536, Address: 0x1026730 */
  if (lD1.w.l <= scralim_up) { /* Line 537, Address: 0x102673c */
    if (lD1.w.l > -256) { /* Line 538, Address: 0x1026764 */
      lD1.w.l = scralim_up; /* Line 539, Address: 0x102677c */
    } /* Line 540, Address: 0x1026788 */
    else {
      lD1.w.l &= 2047; /* Line 542, Address: 0x1026790 */
      actwk[0].yposi.w.h &= 2047; /* Line 543, Address: 0x102679c */
      scra_v_posit.w.h &= 2047; /* Line 544, Address: 0x10267b0 */
      scrb_v_posit.w.h &= 1023; /* Line 545, Address: 0x10267c4 */
    }
  }
  scrv_move(lD1); /* Line 548, Address: 0x10267d8 */
} /* Line 549, Address: 0x10267e4 */


void sv_move_plus(short wD1) { /* Line 552, Address: 0x1026800 */
  int_union lD1;
  short wk;

  lD1.l = (wD1 << 8) + scra_v_posit.l; /* Line 556, Address: 0x1026810 */

  wk = lD1.w.h; /* Line 558, Address: 0x1026830 */
  lD1.w.h = lD1.w.l; /* Line 559, Address: 0x102683c */
  lD1.w.l = wk; /* Line 560, Address: 0x1026844 */
  scrv_down_ch(lD1); /* Line 561, Address: 0x1026848 */
} /* Line 562, Address: 0x1026854 */


void scrv_down_ch(int_union lD1) { /* Line 565, Address: 0x1026870 */
  if (lD1.w.l >= scralim_down) { /* Line 566, Address: 0x102687c */
    if ((lD1.w.l -= 2048) < 0) { /* Line 567, Address: 0x10268a4 */
      lD1.w.l = scralim_down; /* Line 568, Address: 0x10268c8 */
    } /* Line 569, Address: 0x10268d4 */
    else {
      actwk[0].yposi.w.h &= 2047; /* Line 571, Address: 0x10268dc */
      scra_v_posit.w.h -= 2048; /* Line 572, Address: 0x10268f0 */
      scrb_v_posit.w.h &= 1023; /* Line 573, Address: 0x1026904 */
    }
  }
  scrv_move(lD1); /* Line 576, Address: 0x1026918 */
} /* Line 577, Address: 0x1026924 */


void scrv_move(int_union lD1) { /* Line 580, Address: 0x1026940 */
  short wD4, wk;
  uint_union dwk;

  wD4 = scra_v_posit.w.h; /* Line 584, Address: 0x1026950 */

  wk = lD1.w.h; /* Line 586, Address: 0x1026960 */
  lD1.w.h = lD1.w.l; /* Line 587, Address: 0x102696c */
  lD1.w.l = wk; /* Line 588, Address: 0x1026974 */

  dwk.l = lD1.l - scra_v_posit.l; /* Line 590, Address: 0x1026978 */
  dwk.l = (dwk.l >> 8) | (dwk.l << 24); /* Line 591, Address: 0x102698c */
  scra_vz = dwk.w.l; /* Line 592, Address: 0x10269a4 */

  scra_v_posit.l = lD1.l; /* Line 594, Address: 0x10269b0 */

  wk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 596, Address: 0x10269bc */
  if (!wk) { /* Line 597, Address: 0x10269f8 */
    scra_v_count ^= 16; /* Line 598, Address: 0x1026a00 */
    wk = scra_v_posit.w.h - wD4; /* Line 599, Address: 0x1026a14 */
    if (wk < 0) scrflaga.b.h |= 1; /* Line 600, Address: 0x1026a40 */
    else scrflaga.b.h |= 2; /* Line 601, Address: 0x1026a6c */
  }
} /* Line 603, Address: 0x1026a80 */











void scrollb_hv(int lD4, int lD5) { /* Line 615, Address: 0x1026aa0 */
  int lD0, lD1;
  int_union lD2;

  lD0 = scrb_h_posit.l; /* Line 619, Address: 0x1026ab4 */
  lD2.l = scrb_h_posit.l = lD1 = lD0 + lD4; /* Line 620, Address: 0x1026abc */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_h_count) == 0) { /* Line 621, Address: 0x1026ad0 */
    scrb_h_count ^= 16; /* Line 622, Address: 0x1026b00 */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 4; /* Line 623, Address: 0x1026b14 */
    else scrflagb.b.h |= 8; /* Line 624, Address: 0x1026b3c */
  }
  lD0 = scrb_v_posit.l; /* Line 626, Address: 0x1026b50 */
  lD2.l = scrb_v_posit.l = lD1 = lD0 + lD5; /* Line 627, Address: 0x1026b58 */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_v_count) == 0) { /* Line 628, Address: 0x1026b6c */
    scrb_v_count ^= 16; /* Line 629, Address: 0x1026b9c */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 1; /* Line 630, Address: 0x1026bb0 */
    else scrflagb.b.h |= 2; /* Line 631, Address: 0x1026bd8 */
  }
} /* Line 633, Address: 0x1026bec */






























































void scrollc_h(int lD4, int flagc) { /* Line 696, Address: 0x1026c00 */
  int_union lD0, lD2;

  lD2.l = scrc_h_posit.l; /* Line 699, Address: 0x1026c0c */
  lD0.l = lD2.l + lD4; /* Line 700, Address: 0x1026c18 */
  scrc_h_posit.l = lD0.l; /* Line 701, Address: 0x1026c28 */
  lD0.b.b2 &= 16; /* Line 702, Address: 0x1026c34 */
  if ((scrc_h_count ^ lD0.b.b2) == 0) { /* Line 703, Address: 0x1026c40 */
    scrc_h_count ^= 16; /* Line 704, Address: 0x1026c64 */
    lD0.l -= lD2.l; /* Line 705, Address: 0x1026c78 */
    if ((long int)lD0.l < 0) scrflagc.b.h |= flagc; /* Line 706, Address: 0x1026c88 */
    else scrflagc.b.h |= flagc * 2; /* Line 707, Address: 0x1026cc0 */
  }
} /* Line 709, Address: 0x1026ce0 */











void scrollz_h(int lD4, int flagz) { /* Line 721, Address: 0x1026cf0 */
  int_union lD0, lD2;

  lD2.l = scrz_h_posit.l; /* Line 724, Address: 0x1026cfc */
  lD0.l = lD2.l + lD4; /* Line 725, Address: 0x1026d08 */
  scrz_h_posit.l = lD0.l; /* Line 726, Address: 0x1026d18 */
  lD0.b.b2 &= 16; /* Line 727, Address: 0x1026d24 */
  if ((scrz_h_count ^ lD0.b.b2) == 0) { /* Line 728, Address: 0x1026d30 */
    scrz_h_count ^= 16; /* Line 729, Address: 0x1026d54 */
    lD0.l -= lD2.l; /* Line 730, Address: 0x1026d68 */
    if ((long int)lD0.l < 0) scrflagz.b.h |= flagz; /* Line 731, Address: 0x1026d78 */
    else scrflagz.b.h |= flagz * 2; /* Line 732, Address: 0x1026db0 */
  }
} /* Line 734, Address: 0x1026dd0 */










void scrollwrtadva() { /* Line 745, Address: 0x1026de0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  pScrFlag = &scrflagb.b.h; /* Line 751, Address: 0x1026dfc */
  wH_posiw = scrb_h_posit.w.h; /* Line 752, Address: 0x1026e04 */
  wV_posiw = scrb_v_posit.w.h; /* Line 753, Address: 0x1026e10 */
  pMapWk = (unsigned char*)mapwkb; /* Line 754, Address: 0x1026e1c */
  VramBase = 24576; /* Line 755, Address: 0x1026e24 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 756, Address: 0x1026e28 */





} /* Line 762, Address: 0x1026e3c */










void scrollwrt() { /* Line 773, Address: 0x1026e60 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  pScrFlag = &scrflagbw.b.h; /* Line 782, Address: 0x1026e80 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 783, Address: 0x1026e88 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 784, Address: 0x1026e94 */
  pMapWk = (unsigned char*)mapwkb; /* Line 785, Address: 0x1026ea0 */
  VramBase = 24576; /* Line 786, Address: 0x1026ea8 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 787, Address: 0x1026eac */











  pScrFlag = &scrflagaw.b.h; /* Line 799, Address: 0x1026ec0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 800, Address: 0x1026ec8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 801, Address: 0x1026ed4 */
  pMapWk = (unsigned char*)mapwka; /* Line 802, Address: 0x1026ee0 */
  VramBase = 16384; /* Line 803, Address: 0x1026ee8 */

  if (*pScrFlag) { /* Line 805, Address: 0x1026eec */
    if (*pScrFlag & 1) { /* Line 806, Address: 0x1026ef8 */
      *pScrFlag &= 254; /* Line 807, Address: 0x1026f0c */

      lD4.l = -16; /* Line 809, Address: 0x1026f18 */
      wD5 = 65520; /* Line 810, Address: 0x1026f20 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 811, Address: 0x1026f28 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 812, Address: 0x1026f48 */
    }
    if (*pScrFlag & 2) { /* Line 814, Address: 0x1026f74 */
      *pScrFlag &= 253; /* Line 815, Address: 0x1026f88 */

      lD4.l = 224; /* Line 817, Address: 0x1026f94 */
      wD5 = 65520; /* Line 818, Address: 0x1026f9c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 819, Address: 0x1026fa4 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 820, Address: 0x1026fc4 */
    }
    if (*pScrFlag & 4) { /* Line 822, Address: 0x1026ff0 */
      *pScrFlag &= 251; /* Line 823, Address: 0x1027004 */

      lD4.l = -16; /* Line 825, Address: 0x1027010 */
      wD5 = 65520; /* Line 826, Address: 0x1027018 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 827, Address: 0x1027020 */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 828, Address: 0x1027040 */
    }
    if (*pScrFlag & 8) { /* Line 830, Address: 0x102706c */
      *pScrFlag &= 247; /* Line 831, Address: 0x1027080 */

      lD4.l = -16; /* Line 833, Address: 0x102708c */
      wD5 = 320; /* Line 834, Address: 0x1027094 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 835, Address: 0x102709c */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 836, Address: 0x10270bc */
    }
  }
} /* Line 839, Address: 0x10270e8 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 853, Address: 0x1027110 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 864, Address: 0x102713c */

  if (*pScrFlag & 1) { /* Line 866, Address: 0x1027144 */
    *pScrFlag &= 254; /* Line 867, Address: 0x102715c */
  } /* Line 868, Address: 0x1027170 */
  else {
    *pScrFlag &= 254; /* Line 870, Address: 0x1027178 */

    if (*pScrFlag & 2) { /* Line 872, Address: 0x102718c */
      *pScrFlag &= 253; /* Line 873, Address: 0x10271a4 */
      lD4.w.l = 224; /* Line 874, Address: 0x10271b8 */
    } /* Line 875, Address: 0x10271c0 */
    else {
      *pScrFlag &= 253; /* Line 877, Address: 0x10271c8 */
      goto label1; /* Line 878, Address: 0x10271dc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 883, Address: 0x10271e4 */
  wD0 &= 127; /* Line 884, Address: 0x1027234 */
  wD0 = z11dwrttbl[wD0 + 1]; /* Line 885, Address: 0x102723c */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 886, Address: 0x102725c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 887, Address: 0x102727c */
  if (wD0 != 0) { /* Line 888, Address: 0x10272a0 */
    wD5 = 65520; /* Line 889, Address: 0x10272ac */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 890, Address: 0x10272b4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 892, Address: 0x10272d4 */



  } /* Line 896, Address: 0x1027300 */
  else {

    wD5 = 0; /* Line 899, Address: 0x1027308 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 900, Address: 0x102730c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 904, Address: 0x102732c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 911, Address: 0x1027358 */






    lD4.l = -16; /* Line 918, Address: 0x102736c */
    wD5 = 65520; /* Line 919, Address: 0x1027374 */
    if (*pScrFlag & 168) { /* Line 920, Address: 0x102737c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 921, Address: 0x1027394 */
      wD5 = 320; /* Line 922, Address: 0x10273b4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 926, Address: 0x10273bc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 928, Address: 0x10273ec */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 929, Address: 0x10273f8 */



    for (i = 0; i < 16; ++i) { /* Line 933, Address: 0x1027408 */
      wD0 = z11dwrttbl[WrtTblCnt++]; /* Line 934, Address: 0x1027414 */
      if (wD0 != 0) { /* Line 935, Address: 0x1027434 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 936, Address: 0x1027440 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 937, Address: 0x102746c */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 938, Address: 0x102748c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 940, Address: 0x10274b0 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 943, Address: 0x10274d4 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 945, Address: 0x10274f4 */
        }
      }
      lD4.w.l += 16; /* Line 948, Address: 0x1027508 */
    } /* Line 949, Address: 0x1027514 */
    *pScrFlag = 0; /* Line 950, Address: 0x1027524 */
  }
} /* Line 952, Address: 0x102752c */


























void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 979, Address: 0x1027560 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 992, Address: 0x1027588 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 995, Address: 0x10275a8 */
    pTilePoint->x += 2; /* Line 996, Address: 0x10275bc */
    if (pTilePoint->x >= 64) { /* Line 997, Address: 0x10275d0 */
      pTilePoint->x -= 64; /* Line 998, Address: 0x10275e4 */
    }
    xOffs += 16; /* Line 1000, Address: 0x10275f8 */
  } while (--lpcnt >= 0); /* Line 1001, Address: 0x1027604 */
} /* Line 1002, Address: 0x1027618 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1006, Address: 0x1027630 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1010, Address: 0x1027658 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1013, Address: 0x1027678 */
    pTilePoint->x += 2; /* Line 1014, Address: 0x102768c */
    if (pTilePoint->x >= 64) { /* Line 1015, Address: 0x10276a0 */
      pTilePoint->x -= 64; /* Line 1016, Address: 0x10276b4 */
    }
    xOffs += 16; /* Line 1018, Address: 0x10276c8 */
  } while (--lpcnt >= 0); /* Line 1019, Address: 0x10276d4 */
} /* Line 1020, Address: 0x10276e8 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1036, Address: 0x1027700 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1040, Address: 0x1027728 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1041, Address: 0x1027748 */
    pTilePoint->y += 2; /* Line 1042, Address: 0x102775c */
    if (pTilePoint->y >= 32) pTilePoint->y -= 32; /* Line 1043, Address: 0x102776c */
    yOffs += 16; /* Line 1044, Address: 0x1027790 */
  } while (--lpcnt >= 0); /* Line 1045, Address: 0x102779c */
} /* Line 1046, Address: 0x10277b0 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1064, Address: 0x10277c0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) base = 1; /* Line 1070, Address: 0x10277f4 */
  else if (VramBase == 16384) base = 0; /* Line 1071, Address: 0x1027810 */
  x = pTilePoint->x; /* Line 1072, Address: 0x1027824 */
  y = pTilePoint->y; /* Line 1073, Address: 0x102782c */

  frip = BlkIndex & 6144; /* Line 1075, Address: 0x1027834 */
  BlkIndex &= 1023; /* Line 1076, Address: 0x102783c */
  if (frip == 6144) { /* Line 1077, Address: 0x1027848 */
    p0 = 3; /* Line 1078, Address: 0x1027854 */
    p1 = 2; /* Line 1079, Address: 0x1027858 */
    p2 = 1; /* Line 1080, Address: 0x102785c */
    p3 = 0; /* Line 1081, Address: 0x1027860 */
  } /* Line 1082, Address: 0x1027864 */
  else if (frip & 4096) { /* Line 1083, Address: 0x102786c */
    p0 = 2; /* Line 1084, Address: 0x1027878 */
    p1 = 3; /* Line 1085, Address: 0x102787c */
    p2 = 0; /* Line 1086, Address: 0x1027880 */
    p3 = 1; /* Line 1087, Address: 0x1027884 */
  } /* Line 1088, Address: 0x1027888 */
  else if (frip & 2048) { /* Line 1089, Address: 0x1027890 */
    p0 = 1; /* Line 1090, Address: 0x102789c */
    p1 = 0; /* Line 1091, Address: 0x10278a0 */
    p2 = 3; /* Line 1092, Address: 0x10278a4 */
    p3 = 2; /* Line 1093, Address: 0x10278a8 */
  } /* Line 1094, Address: 0x10278ac */
  else {
    p0 = 0; /* Line 1096, Address: 0x10278b4 */
    p1 = 1; /* Line 1097, Address: 0x10278b8 */
    p2 = 2; /* Line 1098, Address: 0x10278bc */
    p3 = 3; /* Line 1099, Address: 0x10278c0 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1102, Address: 0x10278c4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1103, Address: 0x1027908 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1104, Address: 0x102794c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1105, Address: 0x1027990 */
} /* Line 1106, Address: 0x10279d4 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1125, Address: 0x1027a10 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1126, Address: 0x1027a30 */
} /* Line 1127, Address: 0x1027a50 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1130, Address: 0x1027a60 */
  wH_posiw = 0; /* Line 1131, Address: 0x1027a80 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1132, Address: 0x1027a84 */
} /* Line 1133, Address: 0x1027aa4 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1136, Address: 0x1027ac0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1142, Address: 0x1027af0 */
  yOffs += wV_posiw; /* Line 1143, Address: 0x1027b00 */


  if ((short)xOffs < 0) xOffs = 0; /* Line 1146, Address: 0x1027b10 */
  if ((short)yOffs < 0) yOffs = 0; /* Line 1147, Address: 0x1027b30 */
  if ((short)xOffs >= 16384) xOffs = 16383; /* Line 1148, Address: 0x1027b50 */
  if ((short)yOffs >= 2048) yOffs = 2047; /* Line 1149, Address: 0x1027b78 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1150, Address: 0x1027ba0 */
  if (i < 0) i = 0; /* Line 1151, Address: 0x1027be8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1153, Address: 0x1027bf4 */

  if (ScreenNo) { /* Line 1155, Address: 0x1027c10 */
    xOffs &= 32767; /* Line 1156, Address: 0x1027c18 */
    yOffs &= 32767; /* Line 1157, Address: 0x1027c24 */

    xBlk = xOffs; /* Line 1159, Address: 0x1027c30 */
    xBlk %= 256; /* Line 1160, Address: 0x1027c38 */
    xBlk /= 16; /* Line 1161, Address: 0x1027c58 */
    yBlk = yOffs; /* Line 1162, Address: 0x1027c74 */
    yBlk %= 256; /* Line 1163, Address: 0x1027c7c */
    yBlk /= 16; /* Line 1164, Address: 0x1027c9c */

    lpw = pmapwk; /* Line 1166, Address: 0x1027cb8 */
    lpw += xBlk; /* Line 1167, Address: 0x1027cc0 */
    lpw += yBlk * 16; /* Line 1168, Address: 0x1027cc8 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1169, Address: 0x1027cd4 */
    *pIndex = *lpw; /* Line 1170, Address: 0x1027cec */

    return 1; /* Line 1172, Address: 0x1027cfc */
  }
  *pIndex = 0; /* Line 1174, Address: 0x1027d08 */
  return 0; /* Line 1175, Address: 0x1027d10 */
} /* Line 1176, Address: 0x1027d14 */















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1192, Address: 0x1027d40 */
  int xBlk, yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;

  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1197, Address: 0x1027d68 */
  if (ScreenNo) { /* Line 1198, Address: 0x1027dcc */
    xBlk = xOffs; /* Line 1199, Address: 0x1027dd4 */
    xBlk %= 256; /* Line 1200, Address: 0x1027ddc */
    xBlk /= 16; /* Line 1201, Address: 0x1027dfc */
    yBlk = yOffs; /* Line 1202, Address: 0x1027e18 */
    yBlk %= 256; /* Line 1203, Address: 0x1027e20 */
    yBlk /= 16; /* Line 1204, Address: 0x1027e40 */

    lpw = pmapwk; /* Line 1206, Address: 0x1027e5c */
    lpw += xBlk; /* Line 1207, Address: 0x1027e64 */
    lpw += yBlk * 16; /* Line 1208, Address: 0x1027e6c */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1209, Address: 0x1027e78 */
    *ppBlockNo = lpw; /* Line 1210, Address: 0x1027e90 */
    *pIndex = *lpw; /* Line 1211, Address: 0x1027e98 */

    return 1; /* Line 1213, Address: 0x1027ea8 */
  }
  *pIndex = 0; /* Line 1215, Address: 0x1027eb4 */
  return 0; /* Line 1216, Address: 0x1027ebc */
} /* Line 1217, Address: 0x1027ec0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1231, Address: 0x1027ee0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1238, Address: 0x1027efc */
  pMapWk = (unsigned char*)mapwka; /* Line 1239, Address: 0x1027f00 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1240, Address: 0x1027f08 */
    *pBlockIndex = BlockNo; /* Line 1241, Address: 0x1027f2c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1242, Address: 0x1027f38 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1243, Address: 0x1027f50 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1244, Address: 0x1027f64 */
    }
  }
} /* Line 1247, Address: 0x1027f7c */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1259, Address: 0x1027fa0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1260, Address: 0x1027fac */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1261, Address: 0x1027fd8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1262, Address: 0x1028024 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) return 0; /* Line 1263, Address: 0x1028050 */
      }
    }
  }
  return 1; /* Line 1267, Address: 0x10280a8 */
} /* Line 1268, Address: 0x10280ac */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1283, Address: 0x10280c0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1284, Address: 0x10280dc */
} /* Line 1285, Address: 0x10280f8 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1288, Address: 0x1028110 */
  wH_posiw = 0; /* Line 1289, Address: 0x102812c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1290, Address: 0x1028130 */
} /* Line 1291, Address: 0x102814c */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1294, Address: 0x1028160 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1295, Address: 0x1028174 */
} /* Line 1296, Address: 0x1028190 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1299, Address: 0x10281a0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1300, Address: 0x10281bc */
} /* Line 1301, Address: 0x10281d8 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1304, Address: 0x10281f0 */
  xOffs += wH_posiw; /* Line 1305, Address: 0x1028208 */
  yOffs += wV_posiw; /* Line 1306, Address: 0x1028218 */
  yOffs &= 240; /* Line 1307, Address: 0x1028228 */
  xOffs &= 496; /* Line 1308, Address: 0x1028234 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1310, Address: 0x1028240 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1311, Address: 0x102826c */

} /* Line 1313, Address: 0x1028298 */













void mapwrt() { /* Line 1327, Address: 0x10282b0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1332, Address: 0x10282c8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1333, Address: 0x10282d4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1334, Address: 0x10282e0 */
  VramBase = 16384; /* Line 1335, Address: 0x10282e8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1336, Address: 0x10282ec */



  pMapWk = (unsigned char*)mapwkb; /* Line 1340, Address: 0x1028304 */
  VramBase = 24576; /* Line 1341, Address: 0x102830c */
  mapwrt_z11c(pMapWk, VramBase); /* Line 1342, Address: 0x1028310 */
} /* Line 1343, Address: 0x1028320 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1346, Address: 0x1028340 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1347, Address: 0x1028358 */
} /* Line 1348, Address: 0x1028378 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1351, Address: 0x1028390 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1355, Address: 0x10283b0 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1356, Address: 0x10283cc */
    wD4 += 16; /* Line 1357, Address: 0x10283f4 */
  } while ((short)--wD6 >= 0); /* Line 1358, Address: 0x1028400 */
} /* Line 1359, Address: 0x1028428 */


void mapwrt_z11c(unsigned char* pMapWk, int VramBase) { /* Line 1362, Address: 0x1028440 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1365, Address: 0x102845c */
  wD6 = 15; /* Line 1366, Address: 0x1028464 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1369, Address: 0x102846c */
    mapwrt_sub(&z11dwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1370, Address: 0x1028490 */
    wD4 += 16; /* Line 1371, Address: 0x10284b0 */
  } while ((short)--wD6 >= 0); /* Line 1372, Address: 0x10284b8 */
} /* Line 1373, Address: 0x10284dc */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1389, Address: 0x1028500 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1394, Address: 0x1028528 */
  wD0 = pWrttbl[wD0]; /* Line 1395, Address: 0x1028538 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1396, Address: 0x1028554 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1397, Address: 0x1028578 */
  if (wD0) { /* Line 1398, Address: 0x10285a0 */
    wD5 = 65520; /* Line 1399, Address: 0x10285ac */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1400, Address: 0x10285b4 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1401, Address: 0x10285d0 */
  } /* Line 1402, Address: 0x10285f8 */
  else {
    wD5 = 0; /* Line 1404, Address: 0x1028600 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1405, Address: 0x1028604 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1406, Address: 0x1028620 */
  }
} /* Line 1408, Address: 0x1028648 */










void mapinit() { /* Line 1419, Address: 0x1028670 */

  colorset2(mapinittbl.colorno2); /* Line 1421, Address: 0x1028678 */
  colorset(mapinittbl.colorno2); /* Line 1422, Address: 0x102868c */

  if (plflag) enecginit(); /* Line 1424, Address: 0x10286a0 */
  if (play_start & 2) divdevset(); /* Line 1425, Address: 0x10286b8 */
} /* Line 1426, Address: 0x10286d8 */
