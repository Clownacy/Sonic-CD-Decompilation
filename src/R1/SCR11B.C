#include "..\EQU.H"
#include "SCR11B.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1B.H"

static unsigned char z11bwrttbl[33] = {
  0, 0, 0, 0, 0, 6, 6, 6, 6, 6,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4
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































































































void enecginit() {} /* Line 132, Address: 0x1025f00 */




void divdevset() {} /* Line 137, Address: 0x1025f10 */












sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 151, Address: 0x1025f20 */
  return &actwk[1]; /* Line 152, Address: 0x1025f40 */
} /* Line 153, Address: 0x1025f48 */










void scr_set() { /* Line 164, Address: 0x1025f50 */
  unsigned short scr_dir_tbl[6] = { /* Line 165, Address: 0x1025f5c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = 0; /* Line 170, Address: 0x1025f90 */
  scrv_flag = 0; /* Line 171, Address: 0x1025f98 */
  scr_die.b.h = 0; /* Line 172, Address: 0x1025fa0 */
  scr_timer.b.h = 0; /* Line 173, Address: 0x1025fa8 */
  zone_flag.b.h = 0; /* Line 174, Address: 0x1025fb0 */

  i = 0; /* Line 176, Address: 0x1025fb8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 177, Address: 0x1025fbc */
  scralim_left = scr_dir_tbl[i]; /* Line 178, Address: 0x1025fd8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 179, Address: 0x1025fec */
  scralim_right = scr_dir_tbl[i]; /* Line 180, Address: 0x1026008 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 181, Address: 0x102601c */
  scralim_up = scr_dir_tbl[i]; /* Line 182, Address: 0x1026038 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 183, Address: 0x102604c */
  scralim_down = scr_dir_tbl[i]; /* Line 184, Address: 0x1026068 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 185, Address: 0x102607c */

  scra_h_keep = scralim_left + 576; /* Line 187, Address: 0x1026098 */
  scra_h_count = 16; /* Line 188, Address: 0x10260bc */
  scra_v_count = 16; /* Line 189, Address: 0x10260c8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 191, Address: 0x10260d4 */
  scra_hline = 160; /* Line 192, Address: 0x10260f0 */

  playposiset(); /* Line 194, Address: 0x10260fc */
} /* Line 195, Address: 0x1026104 */










void playposiset() { /* Line 206, Address: 0x1026120 */
  unsigned short playpositbl[2] = { 80, 488 }; /* Line 207, Address: 0x1026134 */
  unsigned short endplpositbl[16] = { /* Line 208, Address: 0x1026150 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { 140, 127, 30, 30 }; /* Line 218, Address: 0x1026184 */
  short xWk;
  short yWk;
  int i;

  if (plflag) { /* Line 223, Address: 0x10261b0 */
    playload(); /* Line 224, Address: 0x10261c0 */
    xWk = actwk[0].xposi.w.h; /* Line 225, Address: 0x10261c8 */
    yWk = actwk[0].yposi.w.h; /* Line 226, Address: 0x10261d8 */
    if (yWk < 0) yWk = 0; /* Line 227, Address: 0x10261e8 */
  } /* Line 228, Address: 0x10261fc */
  else {
    if (demoflag.w < 0) { /* Line 230, Address: 0x1026204 */
      xWk = actwk[0].xposi.w.h = endplpositbl[(enddemono - 1) * 2]; /* Line 231, Address: 0x102621c */
      yWk = actwk[0].yposi.w.h = endplpositbl[(enddemono - 1) * 2 + 1]; /* Line 232, Address: 0x1026250 */
    } /* Line 233, Address: 0x1026288 */
    else {
      xWk = actwk[0].xposi.w.h = playpositbl[demoflag.w * 2]; /* Line 235, Address: 0x1026290 */
      yWk = actwk[0].yposi.w.h = playpositbl[demoflag.w * 2 + 1]; /* Line 236, Address: 0x10262c0 */
    }
  }

  if ((unsigned short)xWk > 160) xWk -= 160; /* Line 240, Address: 0x10262f4 */
  else xWk = 0; /* Line 241, Address: 0x102631c */
  if ((unsigned short)scralim_right < (unsigned short)xWk) xWk = scralim_right; /* Line 242, Address: 0x1026320 */
  scra_h_posit.w.h = xWk; /* Line 243, Address: 0x1026354 */

  if ((unsigned short)yWk > 96) yWk -= 96; /* Line 245, Address: 0x102635c */
  else yWk = 0; /* Line 246, Address: 0x1026384 */
  if ((unsigned short)scralim_down < (unsigned short)yWk) yWk = scralim_down; /* Line 247, Address: 0x1026388 */
  scra_v_posit.w.h = yWk; /* Line 248, Address: 0x10263bc */

  scrbinit(xWk, yWk); /* Line 250, Address: 0x10263c4 */

  i = 0; /* Line 252, Address: 0x10263d4 */
  loopmapno = playmapnotbl[i++]; /* Line 253, Address: 0x10263d8 */
  loopmapno2 = playmapnotbl[i++]; /* Line 254, Address: 0x10263f0 */
  ballmapno = playmapnotbl[i++]; /* Line 255, Address: 0x1026408 */
  ballmapno2 = playmapnotbl[i++]; /* Line 256, Address: 0x1026420 */
} /* Line 257, Address: 0x1026438 */











void scrbinit(short xWk, short yWk) { /* Line 269, Address: 0x1026460 */
  int_union lYwk;

  lYwk.w.h = yWk; /* Line 272, Address: 0x1026470 */
  lYwk.w.l = 0; /* Line 273, Address: 0x1026478 */

  lYwk.l = (lYwk.l >> 4) * 2; /* Line 275, Address: 0x102647c */
  scrb_v_posit.l = lYwk.l; /* Line 276, Address: 0x102648c */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 277, Address: 0x1026498 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 278, Address: 0x10264a4 */

  scrb_h_posit.w.h = (unsigned short)(xWk / 2); /* Line 280, Address: 0x10264b0 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 8); /* Line 281, Address: 0x10264e8 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 282, Address: 0x1026520 */

  sMemSet(hscrollwork, 0, 16); /* Line 284, Address: 0x1026560 */
} /* Line 285, Address: 0x1026580 */










void scroll() { /* Line 296, Address: 0x1026590 */
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

  if (scroll_start.b.h) return; /* Line 308, Address: 0x10265b8 */

  scrflaga.w = 0; /* Line 310, Address: 0x10265c8 */
  scrflagb.w = 0; /* Line 311, Address: 0x10265d0 */
  scrflagc.w = 0; /* Line 312, Address: 0x10265d8 */
  scrflagz.w = 0; /* Line 313, Address: 0x10265e0 */

  scrchk(); /* Line 315, Address: 0x10265e8 */

  scroll_h(); /* Line 317, Address: 0x10265f0 */
  scroll_v(); /* Line 318, Address: 0x10265f8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 320, Address: 0x1026600 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 321, Address: 0x1026610 */

  scrollz_h(scra_hz << 5, 64); /* Line 323, Address: 0x1026620 */
  scrollc_h((scra_hz << 4) * 3, 16); /* Line 324, Address: 0x1026640 */

  lD4 = scra_hz << 7; /* Line 326, Address: 0x1026668 */
  lD5 = (scra_vz << 4) * 2; /* Line 327, Address: 0x102667c */
  scrollb_hv(lD4, lD5); /* Line 328, Address: 0x1026694 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 330, Address: 0x10266a4 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 331, Address: 0x10266b4 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 332, Address: 0x10266c4 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 334, Address: 0x10266d4 */
  scrflagz.b.h = 0; /* Line 335, Address: 0x102670c */
  scrflagc.b.h = 0; /* Line 336, Address: 0x1026714 */

  for (i = 0, psHscr = hscrollwork; i < 4; ++i) { /* Line 338, Address: 0x102671c */
    lD2.w.l = psHscr[0]; /* Line 339, Address: 0x1026730 */
    lD2.w.h = psHscr[1]; /* Line 340, Address: 0x1026738 */
    lD2.l += scaddtbl[i]; /* Line 341, Address: 0x1026740 */
    psHscr[0] = lD2.w.l; /* Line 342, Address: 0x1026760 */
    psHscr[1] = lD2.w.h; /* Line 343, Address: 0x1026768 */
    psHscr += 2; /* Line 344, Address: 0x1026770 */
  } /* Line 345, Address: 0x1026774 */

  pHScrollWork = &hscrollwork[8]; /* Line 347, Address: 0x1026784 */

  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[1] + scrz_h_posit.w.h); /* Line 349, Address: 0x102678c */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[3] + scrz_h_posit.w.h); /* Line 350, Address: 0x10267e4 */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[5] + scrz_h_posit.w.h); /* Line 351, Address: 0x102683c */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[7] + scrz_h_posit.w.h); /* Line 352, Address: 0x1026894 */

  for (i = 0; i < 10; ++i) *pHScrollWork++ = -scrz_h_posit.w.h; /* Line 354, Address: 0x10268ec */
  for (i = 0; i < 24; ++i) *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 355, Address: 0x1026930 */

  pHScrollBuff = lphscrollbuff; /* Line 357, Address: 0x1026974 */

  wD0 = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 359, Address: 0x102697c */
  wD1 = 29; /* Line 360, Address: 0x10269a4 */
  pHScrollWork = &hscrollwork[wD0 / 2] + 8; /* Line 361, Address: 0x10269ac */

  i = 8 - ((unsigned short)scrb_v_posit.w.h & 7); /* Line 363, Address: 0x10269dc */
  goto label2; /* Line 364, Address: 0x10269f8 */

  do {
    i = 8; /* Line 367, Address: 0x1026a00 */
label2:
    wD0 = *pHScrollWork++; /* Line 369, Address: 0x1026a04 */

    for ( ; i > 0; --i) { /* Line 371, Address: 0x1026a14 */
      pHScrollBuff->w.h = 0; /* Line 372, Address: 0x1026a1c */
      pHScrollBuff->w.l = wD0; /* Line 373, Address: 0x1026a20 */
      ++pHScrollBuff; /* Line 374, Address: 0x1026a24 */
    } /* Line 375, Address: 0x1026a28 */
  } while ((short)--wD1 != -1); /* Line 376, Address: 0x1026a38 */
} /* Line 377, Address: 0x1026a60 */










void scroll_h() { /* Line 388, Address: 0x1026a90 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 391, Address: 0x1026a9c */
  scrh_move(); /* Line 392, Address: 0x1026aa8 */
  if ((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) { /* Line 393, Address: 0x1026ab0 */
    scra_h_count ^= 16; /* Line 394, Address: 0x1026ae4 */
    if ((short)wD4 > scra_h_posit.w.h) scrflaga.b.h |= 4; /* Line 395, Address: 0x1026af8 */
    else scrflaga.b.h |= 8; /* Line 396, Address: 0x1026b40 */
  }
} /* Line 398, Address: 0x1026b54 */


void scrh_move() { /* Line 401, Address: 0x1026b70 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 404, Address: 0x1026b7c */
  if (!wD0) scra_hz = 0; /* Line 405, Address: 0x1026bbc */
  else if ((short)wD0 < 0) left_check(wD0); /* Line 406, Address: 0x1026bd4 */
  else right_check(wD0); /* Line 407, Address: 0x1026c00 */
} /* Line 408, Address: 0x1026c0c */


void right_check(unsigned short wD0) { /* Line 411, Address: 0x1026c20 */
  unsigned short wD1;

  if ((short)wD0 > 16) wD0 = 16; /* Line 414, Address: 0x1026c2c */
  wD0 += scra_h_posit.w.h; /* Line 415, Address: 0x1026c54 */
  if (scralim_right < (short)wD0) wD0 = scralim_right; /* Line 416, Address: 0x1026c6c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 417, Address: 0x1026ca8 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 418, Address: 0x1026ccc */
  scra_h_posit.w.h = wD0; /* Line 419, Address: 0x1026cfc */
  scra_hz = wD1; /* Line 420, Address: 0x1026d08 */
} /* Line 421, Address: 0x1026d10 */


void left_check(unsigned short wD0) { /* Line 424, Address: 0x1026d20 */
  unsigned short wD1;

  if ((short)wD0 < -16) wD0 = 65520; /* Line 427, Address: 0x1026d2c */
  wD0 += scra_h_posit.w.h; /* Line 428, Address: 0x1026d54 */
  if (scralim_left > (short)wD0) wD0 = scralim_left; /* Line 429, Address: 0x1026d6c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 430, Address: 0x1026da8 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 431, Address: 0x1026dcc */
  scra_h_posit.w.h = wD0; /* Line 432, Address: 0x1026dfc */
  scra_hz = wD1; /* Line 433, Address: 0x1026e08 */
} /* Line 434, Address: 0x1026e10 */










void scroll_v() { /* Line 445, Address: 0x1026e20 */
  short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 448, Address: 0x1026e2c */
  if (actwk[0].cddat & 4) wD0 -= 5; /* Line 449, Address: 0x1026e60 */
  if (actwk[0].cddat & 2) { /* Line 450, Address: 0x1026e84 */
    wD0 += 32; /* Line 451, Address: 0x1026e9c */
    if (wD0 < scra_vline) { /* Line 452, Address: 0x1026ea8 */
      wD0 -= scra_vline; /* Line 453, Address: 0x1026ecc */
      sv_move_main2(wD0); /* Line 454, Address: 0x1026ee0 */
      return; /* Line 455, Address: 0x1026eec */
    }
    if (wD0 >= scra_vline + 64) { /* Line 457, Address: 0x1026ef4 */
      wD0 -= scra_vline + 64; /* Line 458, Address: 0x1026f1c */
      sv_move_main2(wD0); /* Line 459, Address: 0x1026f44 */
      return; /* Line 460, Address: 0x1026f50 */
    }

    wD0 -= scra_vline + 64; /* Line 463, Address: 0x1026f58 */
    if (!limmoveflag) goto label1; /* Line 464, Address: 0x1026f80 */
    sv_move_sub2(); /* Line 465, Address: 0x1026f90 */
    return; /* Line 466, Address: 0x1026f98 */
  }



  if ((wD0 -= scra_vline) != 0) { /* Line 471, Address: 0x1026fa0 */
    sv_move_main(wD0); /* Line 472, Address: 0x1026fcc */
    return; /* Line 473, Address: 0x1026fd8 */
  }
  if (limmoveflag) { /* Line 475, Address: 0x1026fe0 */
    sv_move_sub2(); /* Line 476, Address: 0x1026ff0 */
    return; /* Line 477, Address: 0x1026ff8 */
  }
label1:
  scra_vz = 0; /* Line 480, Address: 0x1027000 */
} /* Line 481, Address: 0x1027008 */


void sv_move_main(short wD0) { /* Line 484, Address: 0x1027020 */
  short wD1;

  if (scra_vline != 96) sv_move_main1(wD0); /* Line 487, Address: 0x1027030 */
  else {
    wD1 = actwk[0].mspeed.w; /* Line 489, Address: 0x1027060 */
    if (wD1 < 0) wD1 *= -1; /* Line 490, Address: 0x1027070 */
    if (wD1 >= 2048) { /* Line 491, Address: 0x102708c */
      sv_move_main2(wD0); /* Line 492, Address: 0x10270a0 */
      return; /* Line 493, Address: 0x10270ac */
    }
    if (wD0 > 6) sv_move_plus(1536); /* Line 495, Address: 0x10270b4 */
    else if (wD0 < -6) sv_move_minus(1536); /* Line 496, Address: 0x10270e0 */
    else sv_move_sub(wD0); /* Line 497, Address: 0x102710c */
  }
} /* Line 499, Address: 0x1027118 */


void sv_move_main1(short wD0) { /* Line 502, Address: 0x1027130 */
  if (wD0 > 2) sv_move_plus(512); /* Line 503, Address: 0x102713c */
  else if (wD0 < -2) sv_move_minus(512); /* Line 504, Address: 0x1027168 */
  else sv_move_sub(wD0); /* Line 505, Address: 0x1027194 */
} /* Line 506, Address: 0x10271a0 */


void sv_move_main2(short wD0) { /* Line 509, Address: 0x10271b0 */
  if ((short)wD0 > 16) sv_move_plus(4096); /* Line 510, Address: 0x10271bc */
  else if ((short)wD0 < -16) sv_move_minus(4096); /* Line 511, Address: 0x10271e8 */
  else sv_move_sub(wD0); /* Line 512, Address: 0x1027214 */
} /* Line 513, Address: 0x1027220 */


void sv_move_sub2() { /* Line 516, Address: 0x1027230 */
  limmoveflag = 0; /* Line 517, Address: 0x1027238 */
  sv_move_sub(0); /* Line 518, Address: 0x1027240 */
} /* Line 519, Address: 0x102724c */


void sv_move_sub(short wD0) { /* Line 522, Address: 0x1027260 */
  int_union lD1;

  lD1.w.h = 0; /* Line 525, Address: 0x102726c */
  lD1.w.l = wD0 + scra_v_posit.w.h; /* Line 526, Address: 0x1027270 */
  if (wD0 < 0) scrv_up_ch(lD1); /* Line 527, Address: 0x102729c */
  else scrv_down_ch(lD1); /* Line 528, Address: 0x10272c4 */
} /* Line 529, Address: 0x10272d0 */


void sv_move_minus(short wD1) { /* Line 532, Address: 0x10272e0 */
  int_union lD1;
  short wk;

  lD1.l = (-wD1 << 8) + scra_v_posit.l; /* Line 536, Address: 0x10272f0 */

  wk = lD1.w.h; /* Line 538, Address: 0x1027314 */
  lD1.w.h = lD1.w.l; /* Line 539, Address: 0x1027320 */
  lD1.w.l = wk; /* Line 540, Address: 0x1027328 */
  scrv_up_ch(lD1); /* Line 541, Address: 0x102732c */
} /* Line 542, Address: 0x1027338 */


void scrv_up_ch(int_union lD1) { /* Line 545, Address: 0x1027350 */
  if (lD1.w.l <= scralim_up) { /* Line 546, Address: 0x102735c */
    if (lD1.w.l > -256) { /* Line 547, Address: 0x1027384 */
      lD1.w.l = scralim_up; /* Line 548, Address: 0x102739c */
    } /* Line 549, Address: 0x10273a8 */
    else {
      lD1.w.l &= 2047; /* Line 551, Address: 0x10273b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 552, Address: 0x10273bc */
      scra_v_posit.w.h &= 2047; /* Line 553, Address: 0x10273d0 */
      scrb_v_posit.w.h &= 1023; /* Line 554, Address: 0x10273e4 */
    }
  }
  scrv_move(lD1); /* Line 557, Address: 0x10273f8 */
} /* Line 558, Address: 0x1027404 */


void sv_move_plus(short wD1) { /* Line 561, Address: 0x1027420 */
  int_union lD1;
  unsigned short wk;

  lD1.l = (wD1 << 8) + scra_v_posit.l; /* Line 565, Address: 0x1027430 */

  wk = lD1.w.h; /* Line 567, Address: 0x1027450 */
  lD1.w.h = lD1.w.l; /* Line 568, Address: 0x1027458 */
  lD1.w.l = wk; /* Line 569, Address: 0x1027460 */
  scrv_down_ch(lD1); /* Line 570, Address: 0x1027464 */
} /* Line 571, Address: 0x1027470 */


void scrv_down_ch(int_union lD1) { /* Line 574, Address: 0x1027490 */
  if (lD1.w.l >= scralim_down) { /* Line 575, Address: 0x102749c */
    if ((lD1.w.l -= 2048) < 0) { /* Line 576, Address: 0x10274c4 */
      lD1.w.l = scralim_down; /* Line 577, Address: 0x10274e8 */
    } /* Line 578, Address: 0x10274f4 */
    else {
      actwk[0].yposi.w.h &= 2047; /* Line 580, Address: 0x10274fc */
      scra_v_posit.w.h -= 2048; /* Line 581, Address: 0x1027510 */
      scrb_v_posit.w.h &= 1023; /* Line 582, Address: 0x1027524 */
    }
  }
  scrv_move(lD1); /* Line 585, Address: 0x1027538 */
} /* Line 586, Address: 0x1027544 */


void scrv_move(int_union lD1) { /* Line 589, Address: 0x1027560 */
  short wD4, wk;
  uint_union dwk;

  wD4 = scra_v_posit.w.h; /* Line 593, Address: 0x1027570 */

  wk = lD1.w.h; /* Line 595, Address: 0x1027580 */
  lD1.w.h = lD1.w.l; /* Line 596, Address: 0x102758c */
  lD1.w.l = wk; /* Line 597, Address: 0x1027594 */

  dwk.l = lD1.l - scra_v_posit.l; /* Line 599, Address: 0x1027598 */
  dwk.l = (dwk.l >> 8) | (dwk.l << 24); /* Line 600, Address: 0x10275ac */
  scra_vz = dwk.w.l; /* Line 601, Address: 0x10275c4 */

  scra_v_posit.l = lD1.l; /* Line 603, Address: 0x10275d0 */

  wk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 605, Address: 0x10275dc */
  if (!wk) { /* Line 606, Address: 0x1027618 */
    scra_v_count ^= 16; /* Line 607, Address: 0x1027620 */
    wk = scra_v_posit.w.h - wD4; /* Line 608, Address: 0x1027634 */
    if (wk < 0) scrflaga.b.h |= 1; /* Line 609, Address: 0x1027660 */
    else scrflaga.b.h |= 2; /* Line 610, Address: 0x102768c */
  }
} /* Line 612, Address: 0x10276a0 */











void scrollb_hv(int lD4, int lD5) { /* Line 624, Address: 0x10276c0 */
  int lD0, lD1;
  int_union lD2;

  lD0 = scrb_h_posit.l; /* Line 628, Address: 0x10276d4 */
  lD2.l = scrb_h_posit.l = lD1 = lD0 + lD4; /* Line 629, Address: 0x10276dc */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_h_count) == 0) { /* Line 630, Address: 0x10276f0 */
    scrb_h_count ^= 16; /* Line 631, Address: 0x1027720 */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 4; /* Line 632, Address: 0x1027734 */
    else scrflagb.b.h |= 8; /* Line 633, Address: 0x102775c */
  }
  lD0 = scrb_v_posit.l; /* Line 635, Address: 0x1027770 */
  lD2.l = scrb_v_posit.l = lD1 = lD0 + lD5; /* Line 636, Address: 0x1027778 */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_v_count) == 0) { /* Line 637, Address: 0x102778c */
    scrb_v_count ^= 16; /* Line 638, Address: 0x10277bc */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 1; /* Line 639, Address: 0x10277d0 */
    else scrflagb.b.h |= 2; /* Line 640, Address: 0x10277f8 */
  }
} /* Line 642, Address: 0x102780c */









































































void scrollc_h(int lD4, int flagc) { /* Line 716, Address: 0x1027820 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 720, Address: 0x1027830 */
  lD0.l = lD2.l + lD4; /* Line 721, Address: 0x102783c */
  scrc_h_posit.l = lD0.l; /* Line 722, Address: 0x102784c */

  lD1.w.h = lD0.w.l; /* Line 724, Address: 0x1027858 */
  lD1.w.l = lD0.w.h; /* Line 725, Address: 0x1027860 */
  lD1.w.l &= 16; /* Line 726, Address: 0x1027868 */

  bD3 = scrc_h_count; /* Line 728, Address: 0x1027874 */
  lD1.b.b4 ^= bD3; /* Line 729, Address: 0x1027880 */
  if (!lD1.b.b4) { /* Line 730, Address: 0x1027894 */




    scrc_h_count ^= 16; /* Line 735, Address: 0x10278a0 */
    lD0.l -= lD2.l; /* Line 736, Address: 0x10278b4 */
    if ((long int)lD0.l < 0) scrflagc.b.h |= flagc; /* Line 737, Address: 0x10278c4 */
    else scrflagc.b.h |= flagc * 2; /* Line 738, Address: 0x10278fc */
  }
} /* Line 740, Address: 0x102791c */











void scrollz_h(int lD4, int flagz) { /* Line 752, Address: 0x1027930 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 756, Address: 0x1027940 */
  lD0.l = lD2.l + lD4; /* Line 757, Address: 0x102794c */
  scrz_h_posit.l = lD0.l; /* Line 758, Address: 0x102795c */

  lD1.w.h = lD0.w.l; /* Line 760, Address: 0x1027968 */
  lD1.w.l = lD0.w.h; /* Line 761, Address: 0x1027970 */
  lD1.w.l &= 16; /* Line 762, Address: 0x1027978 */

  bD3 = scrz_h_count; /* Line 764, Address: 0x1027984 */
  lD1.b.b4 ^= bD3; /* Line 765, Address: 0x1027990 */
  if (!lD1.b.b4) { /* Line 766, Address: 0x10279a4 */




    scrz_h_count ^= 16; /* Line 771, Address: 0x10279b0 */
    lD0.l -= lD2.l; /* Line 772, Address: 0x10279c4 */
    if ((long int)lD0.l < 0) scrflagz.b.h |= flagz; /* Line 773, Address: 0x10279d4 */
    else scrflagz.b.h |= flagz * 2; /* Line 774, Address: 0x1027a0c */
  }
} /* Line 776, Address: 0x1027a2c */










void scrollwrtadva() { /* Line 787, Address: 0x1027a40 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  pScrFlag = &scrflagb.b.h; /* Line 793, Address: 0x1027a5c */
  wH_posiw = scrb_h_posit.w.h; /* Line 794, Address: 0x1027a64 */
  wV_posiw = scrb_v_posit.w.h; /* Line 795, Address: 0x1027a70 */
  pMapWk = (unsigned char*)mapwkb; /* Line 796, Address: 0x1027a7c */
  VramBase = 24576; /* Line 797, Address: 0x1027a84 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 798, Address: 0x1027a88 */





} /* Line 804, Address: 0x1027a9c */










void scrollwrt() { /* Line 815, Address: 0x1027ac0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  pScrFlag = &scrflagbw.b.h; /* Line 824, Address: 0x1027ae0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 825, Address: 0x1027ae8 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 826, Address: 0x1027af4 */
  pMapWk = (unsigned char*)mapwkb; /* Line 827, Address: 0x1027b00 */
  VramBase = 24576; /* Line 828, Address: 0x1027b08 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 829, Address: 0x1027b0c */

  pScrFlag = &scrflagaw.b.h; /* Line 831, Address: 0x1027b20 */
  wH_posiw = scra_h_posiw.w.h; /* Line 832, Address: 0x1027b28 */
  wV_posiw = scra_v_posiw.w.h; /* Line 833, Address: 0x1027b34 */
  pMapWk = (unsigned char*)mapwka; /* Line 834, Address: 0x1027b40 */
  VramBase = 16384; /* Line 835, Address: 0x1027b48 */

  if (*pScrFlag) { /* Line 837, Address: 0x1027b4c */
    if (*pScrFlag & 1) { /* Line 838, Address: 0x1027b58 */
      *pScrFlag &= 254; /* Line 839, Address: 0x1027b6c */

      lD4.l = -16; /* Line 841, Address: 0x1027b78 */
      wD5 = 65520; /* Line 842, Address: 0x1027b80 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 843, Address: 0x1027b88 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 844, Address: 0x1027ba8 */
    }
    if (*pScrFlag & 2) { /* Line 846, Address: 0x1027bd4 */
      *pScrFlag &= 253; /* Line 847, Address: 0x1027be8 */

      lD4.l = 224; /* Line 849, Address: 0x1027bf4 */
      wD5 = 65520; /* Line 850, Address: 0x1027bfc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 851, Address: 0x1027c04 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 852, Address: 0x1027c24 */
    }
    if (*pScrFlag & 4) { /* Line 854, Address: 0x1027c50 */
      *pScrFlag &= 251; /* Line 855, Address: 0x1027c64 */

      lD4.l = -16; /* Line 857, Address: 0x1027c70 */
      wD5 = 65520; /* Line 858, Address: 0x1027c78 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 859, Address: 0x1027c80 */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 860, Address: 0x1027ca0 */
    }
    if (*pScrFlag & 8) { /* Line 862, Address: 0x1027ccc */
      *pScrFlag &= 247; /* Line 863, Address: 0x1027ce0 */

      lD4.l = -16; /* Line 865, Address: 0x1027cec */
      wD5 = 320; /* Line 866, Address: 0x1027cf4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 867, Address: 0x1027cfc */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 868, Address: 0x1027d1c */
    }
  }
} /* Line 871, Address: 0x1027d48 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 885, Address: 0x1027d70 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 896, Address: 0x1027d9c */

  if (*pScrFlag & 1) { /* Line 898, Address: 0x1027da4 */
    *pScrFlag &= 254; /* Line 899, Address: 0x1027dbc */
  } /* Line 900, Address: 0x1027dd0 */
  else {
    *pScrFlag &= 254; /* Line 902, Address: 0x1027dd8 */

    if (*pScrFlag & 2) { /* Line 904, Address: 0x1027dec */
      *pScrFlag &= 253; /* Line 905, Address: 0x1027e04 */
      lD4.w.l = 224; /* Line 906, Address: 0x1027e18 */
    } /* Line 907, Address: 0x1027e20 */
    else {
      *pScrFlag &= 253; /* Line 909, Address: 0x1027e28 */
      goto label1; /* Line 910, Address: 0x1027e3c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 915, Address: 0x1027e44 */
  wD0 &= 127; /* Line 916, Address: 0x1027e94 */
  wD0 = z11bwrttbl[wD0 + 1]; /* Line 917, Address: 0x1027e9c */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 918, Address: 0x1027ebc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 919, Address: 0x1027edc */
  if (wD0 != 0) { /* Line 920, Address: 0x1027f00 */
    wD5 = 65520; /* Line 921, Address: 0x1027f0c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 922, Address: 0x1027f14 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 924, Address: 0x1027f34 */



  } /* Line 928, Address: 0x1027f60 */
  else {

    wD5 = 0; /* Line 931, Address: 0x1027f68 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 932, Address: 0x1027f6c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 936, Address: 0x1027f8c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 943, Address: 0x1027fb8 */






    lD4.l = -16; /* Line 950, Address: 0x1027fcc */
    wD5 = 65520; /* Line 951, Address: 0x1027fd4 */
    if (*pScrFlag & 168) { /* Line 952, Address: 0x1027fdc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 953, Address: 0x1027ff4 */
      wD5 = 320; /* Line 954, Address: 0x1028014 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 958, Address: 0x102801c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 960, Address: 0x102804c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 961, Address: 0x1028058 */



    for (i = 0; i < 16; ++i) { /* Line 965, Address: 0x1028068 */
      wD0 = z11bwrttbl[WrtTblCnt++]; /* Line 966, Address: 0x1028074 */
      if (wD0 != 0) { /* Line 967, Address: 0x1028094 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 968, Address: 0x10280a0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 969, Address: 0x10280cc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 970, Address: 0x10280ec */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 972, Address: 0x1028110 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 975, Address: 0x1028134 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 977, Address: 0x1028154 */
        }
      }
      lD4.w.l += 16; /* Line 980, Address: 0x1028168 */
    } /* Line 981, Address: 0x1028174 */
    *pScrFlag = 0; /* Line 982, Address: 0x1028184 */
  }
} /* Line 984, Address: 0x102818c */


























void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1011, Address: 0x10281c0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1024, Address: 0x10281e8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1027, Address: 0x1028208 */
    pTilePoint->x += 2; /* Line 1028, Address: 0x102821c */
    if (pTilePoint->x >= 64) { /* Line 1029, Address: 0x1028230 */
      pTilePoint->x -= 64; /* Line 1030, Address: 0x1028244 */
    }
    xOffs += 16; /* Line 1032, Address: 0x1028258 */
  } while (--lpcnt >= 0); /* Line 1033, Address: 0x1028264 */
} /* Line 1034, Address: 0x1028278 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1038, Address: 0x1028290 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1042, Address: 0x10282b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1045, Address: 0x10282d8 */
    pTilePoint->x += 2; /* Line 1046, Address: 0x10282ec */
    if (pTilePoint->x >= 64) { /* Line 1047, Address: 0x1028300 */
      pTilePoint->x -= 64; /* Line 1048, Address: 0x1028314 */
    }
    xOffs += 16; /* Line 1050, Address: 0x1028328 */
  } while (--lpcnt >= 0); /* Line 1051, Address: 0x1028334 */
} /* Line 1052, Address: 0x1028348 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1068, Address: 0x1028360 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1072, Address: 0x1028388 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1073, Address: 0x10283a8 */
    pTilePoint->y += 2; /* Line 1074, Address: 0x10283bc */
    if (pTilePoint->y >= 32) pTilePoint->y -= 32; /* Line 1075, Address: 0x10283cc */
    yOffs += 16; /* Line 1076, Address: 0x10283f0 */
  } while (--lpcnt >= 0); /* Line 1077, Address: 0x10283fc */
} /* Line 1078, Address: 0x1028410 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1096, Address: 0x1028420 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) base = 1; /* Line 1102, Address: 0x1028454 */
  else if (VramBase == 16384) base = 0; /* Line 1103, Address: 0x1028470 */
  x = pTilePoint->x; /* Line 1104, Address: 0x1028484 */
  y = pTilePoint->y; /* Line 1105, Address: 0x102848c */

  frip = BlkIndex & 6144; /* Line 1107, Address: 0x1028494 */
  BlkIndex &= 1023; /* Line 1108, Address: 0x102849c */
  if (frip == 6144) { /* Line 1109, Address: 0x10284a8 */
    p0 = 3; /* Line 1110, Address: 0x10284b4 */
    p1 = 2; /* Line 1111, Address: 0x10284b8 */
    p2 = 1; /* Line 1112, Address: 0x10284bc */
    p3 = 0; /* Line 1113, Address: 0x10284c0 */
  } /* Line 1114, Address: 0x10284c4 */
  else if (frip & 4096) { /* Line 1115, Address: 0x10284cc */
    p0 = 2; /* Line 1116, Address: 0x10284d8 */
    p1 = 3; /* Line 1117, Address: 0x10284dc */
    p2 = 0; /* Line 1118, Address: 0x10284e0 */
    p3 = 1; /* Line 1119, Address: 0x10284e4 */
  } /* Line 1120, Address: 0x10284e8 */
  else if (frip & 2048) { /* Line 1121, Address: 0x10284f0 */
    p0 = 1; /* Line 1122, Address: 0x10284fc */
    p1 = 0; /* Line 1123, Address: 0x1028500 */
    p2 = 3; /* Line 1124, Address: 0x1028504 */
    p3 = 2; /* Line 1125, Address: 0x1028508 */
  } /* Line 1126, Address: 0x102850c */
  else {
    p0 = 0; /* Line 1128, Address: 0x1028514 */
    p1 = 1; /* Line 1129, Address: 0x1028518 */
    p2 = 2; /* Line 1130, Address: 0x102851c */
    p3 = 3; /* Line 1131, Address: 0x1028520 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1134, Address: 0x1028524 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1135, Address: 0x1028568 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1136, Address: 0x10285ac */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1137, Address: 0x10285f0 */
} /* Line 1138, Address: 0x1028634 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1157, Address: 0x1028670 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1158, Address: 0x1028690 */
} /* Line 1159, Address: 0x10286b0 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1162, Address: 0x10286c0 */
  wH_posiw = 0; /* Line 1163, Address: 0x10286e0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1164, Address: 0x10286e4 */
} /* Line 1165, Address: 0x1028704 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1168, Address: 0x1028720 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1174, Address: 0x1028750 */
  yOffs += wV_posiw; /* Line 1175, Address: 0x1028760 */


  if ((short)xOffs < 0) xOffs = 0; /* Line 1178, Address: 0x1028770 */
  if ((short)yOffs < 0) yOffs = 0; /* Line 1179, Address: 0x1028790 */
  if ((short)xOffs >= 16384) xOffs = 16383; /* Line 1180, Address: 0x10287b0 */
  if ((short)yOffs >= 2048) yOffs = 2047; /* Line 1181, Address: 0x10287d8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1182, Address: 0x1028800 */
  if (i < 0) i = 0; /* Line 1183, Address: 0x1028848 */

  ScreenNo = pMapWk[i] & 127; /* Line 1185, Address: 0x1028854 */

  if (ScreenNo) { /* Line 1187, Address: 0x1028870 */
    xOffs &= 32767; /* Line 1188, Address: 0x1028878 */
    yOffs &= 32767; /* Line 1189, Address: 0x1028884 */

    xBlk = xOffs; /* Line 1191, Address: 0x1028890 */
    xBlk %= 256; /* Line 1192, Address: 0x1028898 */
    xBlk /= 16; /* Line 1193, Address: 0x10288b8 */
    yBlk = yOffs; /* Line 1194, Address: 0x10288d4 */
    yBlk %= 256; /* Line 1195, Address: 0x10288dc */
    yBlk /= 16; /* Line 1196, Address: 0x10288fc */

    lpw = pmapwk; /* Line 1198, Address: 0x1028918 */
    lpw += xBlk; /* Line 1199, Address: 0x1028920 */
    lpw += yBlk * 16; /* Line 1200, Address: 0x1028928 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1201, Address: 0x1028934 */
    *pIndex = *lpw; /* Line 1202, Address: 0x102894c */

    return 1; /* Line 1204, Address: 0x102895c */
  }
  *pIndex = 0; /* Line 1206, Address: 0x1028968 */
  return 0; /* Line 1207, Address: 0x1028970 */
} /* Line 1208, Address: 0x1028974 */















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1224, Address: 0x10289a0 */
  int xBlk, yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;

  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1229, Address: 0x10289c8 */
  if (ScreenNo) { /* Line 1230, Address: 0x1028a2c */
    xBlk = xOffs; /* Line 1231, Address: 0x1028a34 */
    xBlk %= 256; /* Line 1232, Address: 0x1028a3c */
    xBlk /= 16; /* Line 1233, Address: 0x1028a5c */
    yBlk = yOffs; /* Line 1234, Address: 0x1028a78 */
    yBlk %= 256; /* Line 1235, Address: 0x1028a80 */
    yBlk /= 16; /* Line 1236, Address: 0x1028aa0 */

    lpw = pmapwk; /* Line 1238, Address: 0x1028abc */
    lpw += xBlk; /* Line 1239, Address: 0x1028ac4 */
    lpw += yBlk * 16; /* Line 1240, Address: 0x1028acc */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1241, Address: 0x1028ad8 */
    *ppBlockNo = lpw; /* Line 1242, Address: 0x1028af0 */
    *pIndex = *lpw; /* Line 1243, Address: 0x1028af8 */

    return 1; /* Line 1245, Address: 0x1028b08 */
  }
  *pIndex = 0; /* Line 1247, Address: 0x1028b14 */
  return 0; /* Line 1248, Address: 0x1028b1c */
} /* Line 1249, Address: 0x1028b20 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1263, Address: 0x1028b40 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1270, Address: 0x1028b5c */
  pMapWk = (unsigned char*)mapwka; /* Line 1271, Address: 0x1028b60 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1272, Address: 0x1028b68 */
    *pBlockIndex = BlockNo; /* Line 1273, Address: 0x1028b8c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1274, Address: 0x1028b98 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1275, Address: 0x1028bb0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1276, Address: 0x1028bc4 */
    }
  }
} /* Line 1279, Address: 0x1028bdc */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1291, Address: 0x1028c00 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1292, Address: 0x1028c0c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1293, Address: 0x1028c38 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1294, Address: 0x1028c84 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) return 0; /* Line 1295, Address: 0x1028cb0 */
      }
    }
  }
  return 1; /* Line 1299, Address: 0x1028d08 */
} /* Line 1300, Address: 0x1028d0c */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1315, Address: 0x1028d20 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1316, Address: 0x1028d3c */
} /* Line 1317, Address: 0x1028d58 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1320, Address: 0x1028d70 */
  wH_posiw = 0; /* Line 1321, Address: 0x1028d8c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1322, Address: 0x1028d90 */
} /* Line 1323, Address: 0x1028dac */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1326, Address: 0x1028dc0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1327, Address: 0x1028dd4 */
} /* Line 1328, Address: 0x1028df0 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1331, Address: 0x1028e00 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1332, Address: 0x1028e1c */
} /* Line 1333, Address: 0x1028e38 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1336, Address: 0x1028e50 */
  xOffs += wH_posiw; /* Line 1337, Address: 0x1028e68 */
  yOffs += wV_posiw; /* Line 1338, Address: 0x1028e78 */
  yOffs &= 240; /* Line 1339, Address: 0x1028e88 */
  xOffs &= 496; /* Line 1340, Address: 0x1028e94 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1342, Address: 0x1028ea0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1343, Address: 0x1028ecc */

} /* Line 1345, Address: 0x1028ef8 */













void mapwrt() { /* Line 1359, Address: 0x1028f10 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1364, Address: 0x1028f28 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1365, Address: 0x1028f34 */
  pMapWk = (unsigned char*)mapwka; /* Line 1366, Address: 0x1028f40 */
  VramBase = 16384; /* Line 1367, Address: 0x1028f48 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1368, Address: 0x1028f4c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1372, Address: 0x1028f64 */
  VramBase = 24576; /* Line 1373, Address: 0x1028f6c */
  mapwrt_z11b(pMapWk, VramBase); /* Line 1374, Address: 0x1028f70 */
} /* Line 1375, Address: 0x1028f80 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1378, Address: 0x1028fa0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1379, Address: 0x1028fb8 */
} /* Line 1380, Address: 0x1028fd8 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1383, Address: 0x1028ff0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1387, Address: 0x1029010 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1388, Address: 0x102902c */
    wD4 += 16; /* Line 1389, Address: 0x1029054 */
  } while ((short)--wD6 >= 0); /* Line 1390, Address: 0x1029060 */
} /* Line 1391, Address: 0x1029088 */


void mapwrt_z11b(unsigned char* pMapWk, int VramBase) { /* Line 1394, Address: 0x10290a0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1397, Address: 0x10290bc */
  wD6 = 15; /* Line 1398, Address: 0x10290c4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1401, Address: 0x10290cc */
    mapwrt_sub(&z11bwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1402, Address: 0x10290f0 */
    wD4 += 16; /* Line 1403, Address: 0x1029110 */
  } while ((short)--wD6 >= 0); /* Line 1404, Address: 0x1029118 */
} /* Line 1405, Address: 0x102913c */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1421, Address: 0x1029160 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1426, Address: 0x1029188 */
  wD0 = pWrttbl[wD0]; /* Line 1427, Address: 0x1029198 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1428, Address: 0x10291b4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1429, Address: 0x10291d8 */
  if (wD0) { /* Line 1430, Address: 0x1029200 */
    wD5 = 65520; /* Line 1431, Address: 0x102920c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1432, Address: 0x1029214 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1433, Address: 0x1029230 */
  } /* Line 1434, Address: 0x1029258 */
  else {
    wD5 = 0; /* Line 1436, Address: 0x1029260 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1437, Address: 0x1029264 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1438, Address: 0x1029280 */
  }
} /* Line 1440, Address: 0x10292a8 */










void mapinit() { /* Line 1451, Address: 0x10292d0 */

  colorset2(mapinittbl.colorno2); /* Line 1453, Address: 0x10292d8 */
  colorset(mapinittbl.colorno2); /* Line 1454, Address: 0x10292ec */

  if (plflag) enecginit(); /* Line 1456, Address: 0x1029300 */
  if (play_start & 2) divdevset(); /* Line 1457, Address: 0x1029318 */
} /* Line 1458, Address: 0x1029338 */
