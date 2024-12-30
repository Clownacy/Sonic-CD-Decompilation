#include "..\EQU.H"
#include "SCR12A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1A.H"

static unsigned char z12awrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 4, 4, 0,
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
































































































void enecginit() {} /* Line 133, Address: 0x1026630 */



void divdevset() {} /* Line 137, Address: 0x1026640 */













sprite_status* main_chk() {
  if (main_play == 0) { /* Line 152, Address: 0x1026650 */
    return &actwk[0]; /* Line 153, Address: 0x1026664 */
  }
  return &actwk[1]; /* Line 155, Address: 0x1026674 */
} /* Line 156, Address: 0x102667c */










void scr_set() { /* Line 167, Address: 0x1026690 */
  unsigned short scr_dir_tbl[6] = { /* Line 168, Address: 0x102669c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 173, Address: 0x10266d0 */

  i = 0; /* Line 175, Address: 0x1026718 */
  scrar_no = scr_dir_tbl[i++]; /* Line 176, Address: 0x102671c */
  scralim_left = scr_dir_tbl[i]; /* Line 177, Address: 0x1026738 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 178, Address: 0x102674c */
  scralim_right = scr_dir_tbl[i]; /* Line 179, Address: 0x1026768 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 180, Address: 0x102677c */
  scralim_up = scr_dir_tbl[i]; /* Line 181, Address: 0x1026798 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 182, Address: 0x10267ac */
  scralim_down = scr_dir_tbl[i]; /* Line 183, Address: 0x10267c8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 184, Address: 0x10267dc */

  scra_h_keep = scralim_left + 576; /* Line 186, Address: 0x10267f8 */
  scra_h_count = 16; /* Line 187, Address: 0x102681c */
  scra_v_count = 16; /* Line 188, Address: 0x1026828 */

  scra_vline = scr_dir_tbl[i++]; /* Line 190, Address: 0x1026834 */
  scra_hline = 160; /* Line 191, Address: 0x1026850 */

  playposiset(); /* Line 193, Address: 0x102685c */
} /* Line 194, Address: 0x1026864 */










void playposiset() { /* Line 205, Address: 0x1026880 */
  unsigned short playpositbl[2] = { 80, 389 }; /* Line 206, Address: 0x1026894 */
  unsigned short endplpositbl[16] = { /* Line 207, Address: 0x10268b0 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };

  unsigned char playmapnotbl[4] = { 145, 182, 127, 127 }; /* Line 218, Address: 0x10268e4 */
  short d0, d1;
  unsigned short* a1;

  if (plflag) { /* Line 222, Address: 0x1026910 */

    playload(); /* Line 224, Address: 0x1026920 */
    d1 = actwk[0].xposi.w.h; /* Line 225, Address: 0x1026928 */
    d0 = actwk[0].yposi.w.h; /* Line 226, Address: 0x1026938 */
    if (d0 < 0) d0 = 0; /* Line 227, Address: 0x1026948 */
  } /* Line 228, Address: 0x102695c */
  else {

    if (demoflag.w < 0) { /* Line 231, Address: 0x1026964 */

      d0 = enddemono; /* Line 233, Address: 0x102697c */
      --d0; /* Line 234, Address: 0x102698c */
      d0 = (unsigned short)d0 * 4; /* Line 235, Address: 0x1026998 */
      a1 = &endplpositbl[d0 / 2]; /* Line 236, Address: 0x10269b4 */
    } /* Line 237, Address: 0x10269e0 */
    else {

      d0 = demoflag.w; /* Line 240, Address: 0x10269e8 */
      d0 = (unsigned short)d0 * 4; /* Line 241, Address: 0x10269f8 */
      a1 = &playpositbl[d0 / 2]; /* Line 242, Address: 0x1026a14 */
    }

    d1 = *a1++; /* Line 245, Address: 0x1026a40 */
    actwk[0].xposi.w.h = d1; /* Line 246, Address: 0x1026a54 */
    d0 = *a1; /* Line 247, Address: 0x1026a5c */
    actwk[0].yposi.w.h = d0; /* Line 248, Address: 0x1026a68 */
  }

  if ((unsigned short)d1 >= 160) d1 -= 160; /* Line 251, Address: 0x1026a70 */
  else d1 = 0; /* Line 252, Address: 0x1026a98 */
  if ((unsigned short)d1 >= (unsigned short)scralim_right) d1 = scralim_right; /* Line 253, Address: 0x1026a9c */
  scra_h_posit.w.h = d1; /* Line 254, Address: 0x1026ad0 */

  if ((unsigned short)d0 >= 96) d0 -= 96; /* Line 256, Address: 0x1026ad8 */
  else d0 = 0; /* Line 257, Address: 0x1026b00 */
  if (d0 >= scralim_down) d0 = scralim_down; /* Line 258, Address: 0x1026b04 */
  scra_v_posit.w.h = d0; /* Line 259, Address: 0x1026b38 */

  scrbinit(d1, d0); /* Line 261, Address: 0x1026b40 */

  loopmapno = playmapnotbl[0]; /* Line 263, Address: 0x1026b50 */
  loopmapno2 = playmapnotbl[1]; /* Line 264, Address: 0x1026b5c */
  ballmapno = playmapnotbl[2]; /* Line 265, Address: 0x1026b68 */
  ballmapno2 = playmapnotbl[3]; /* Line 266, Address: 0x1026b74 */
} /* Line 267, Address: 0x1026b80 */











void scrbinit(short d1, short d0) { /* Line 279, Address: 0x1026ba0 */
  int_union ld0;




















  ld0.w.h = d0; /* Line 301, Address: 0x1026bac */
  ld0.w.l = 0; /* Line 302, Address: 0x1026bb4 */

  ld0.l = (long int)(ld0.l >> 4) * 3; /* Line 304, Address: 0x1026bb8 */
  scrb_v_posit.l = ld0.l; /* Line 305, Address: 0x1026bdc */
  scrc_v_posit.w.h = (unsigned short)(d0 / 16) * 2; /* Line 306, Address: 0x1026be8 */
  scrz_v_posit.w.h = (unsigned short)(d0 / 16) * 2; /* Line 307, Address: 0x1026c28 */

  scrc_h_posit.w.h = (unsigned short)(d1 / 4); /* Line 309, Address: 0x1026c68 */
  scrz_h_posit.w.h = (unsigned short)(d1 / 8); /* Line 310, Address: 0x1026ca0 */
  scrb_h_posit.w.h = (unsigned short)(d1 / 16 * 3); /* Line 311, Address: 0x1026cd8 */


  hscrollwork[0] = 0; /* Line 314, Address: 0x1026d18 */
  hscrollwork[1] = 0; /* Line 315, Address: 0x1026d20 */
  hscrollwork[2] = 0; /* Line 316, Address: 0x1026d28 */
  hscrollwork[3] = 0; /* Line 317, Address: 0x1026d30 */
  hscrollwork[4] = 0; /* Line 318, Address: 0x1026d38 */
  hscrollwork[5] = 0; /* Line 319, Address: 0x1026d40 */


} /* Line 322, Address: 0x1026d48 */










void scroll() { /* Line 333, Address: 0x1026d60 */
  int_union d0, d1, d2, d3, d4, d5, tmp;
  int l4, l5;
  int_union* pHscrollbuff;
  short *p, *pHscrollwork;
  short s;
  int i, j;
  int cnt, temp;
  static int hs[3] = { 65536, 49152, 32768 };

  d0.l = d1.l = d2.l = d3.l = d4.l = d5.l = 0; /* Line 343, Address: 0x1026d8c */

  if (scroll_start.b.h) return; /* Line 345, Address: 0x1026da4 */
  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 346, Address: 0x1026db4 */

  scrchk(); /* Line 348, Address: 0x1026de0 */
  scroll_h(); /* Line 349, Address: 0x1026dec */
  scroll_v(); /* Line 350, Address: 0x1026df8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 352, Address: 0x1026e04 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 353, Address: 0x1026e14 */

  scrollz_h(scra_hz << 5, 64); /* Line 355, Address: 0x1026e24 */
  scrollc_h((long int)(scra_hz << 4) * 3, 16); /* Line 356, Address: 0x1026e48 */

  l4 = scra_hz << 7; /* Line 358, Address: 0x1026e84 */
  l5 = (long int)(scra_vz << 4) * 3; /* Line 359, Address: 0x1026e9c */
  scrollb_hv(l4, l5); /* Line 360, Address: 0x1026ec8 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 362, Address: 0x1026ed8 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 363, Address: 0x1026ee8 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 364, Address: 0x1026ef8 */

  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 366, Address: 0x1026f08 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 367, Address: 0x1026f3c */

  for (i = 0, p = hscrollwork; i < 3; ++i) { /* Line 369, Address: 0x1026f50 */

    tmp.w.l = p[0]; /* Line 371, Address: 0x1026f64 */
    tmp.w.h = p[1]; /* Line 372, Address: 0x1026f6c */
    tmp.l += hs[i]; /* Line 373, Address: 0x1026f74 */
    p[0] = tmp.w.l; /* Line 374, Address: 0x1026f94 */
    p[1] = tmp.w.h; /* Line 375, Address: 0x1026f9c */
    p += 2; /* Line 376, Address: 0x1026fa4 */
  } /* Line 377, Address: 0x1026fa8 */




  pHscrollwork = &hscrollwork[6]; /* Line 382, Address: 0x1026fb8 */

  d0.w.h = -scra_h_posit.w.h; /* Line 384, Address: 0x1026fc0 */
  d0.w.l = -(hscrollwork[1] + scrz_h_posit.w.h); /* Line 385, Address: 0x1026fe0 */
  for (i = 0; i < 4; ++i) *pHscrollwork++ = d0.w.l; /* Line 386, Address: 0x1027014 */

  d0.w.l = -(hscrollwork[3] + scrz_h_posit.w.h); /* Line 388, Address: 0x1027040 */
  for (i = 0; i < 4; ++i) *pHscrollwork++ = d0.w.l; /* Line 389, Address: 0x1027074 */

  d0.w.l = -(hscrollwork[5] + scrz_h_posit.w.h); /* Line 391, Address: 0x10270a0 */
  for (i = 0; i < 4; ++i) *pHscrollwork++ = d0.w.l; /* Line 392, Address: 0x10270d4 */


  d0.w.l = -scrz_h_posit.w.h; /* Line 395, Address: 0x1027100 */
  for (i = 0; i < 20; ++i) *pHscrollwork++ = d0.w.l; /* Line 396, Address: 0x1027120 */

  d0.w.l = -scrc_h_posit.w.h; /* Line 398, Address: 0x102714c */
  for (i = 0; i < 4; ++i) *pHscrollwork++ = d0.w.l; /* Line 399, Address: 0x102716c */

  pHscrollbuff = lphscrollbuff; /* Line 401, Address: 0x1027198 */
  pHscrollwork = &hscrollwork[6]; /* Line 402, Address: 0x10271a0 */
  d0.w.l = scrb_v_posit.w.h; /* Line 403, Address: 0x10271a8 */
  d2.w.l = d0.w.l; /* Line 404, Address: 0x10271b4 */
  d0.w.l &= 504; /* Line 405, Address: 0x10271bc */
  d0.w.l >>= 2; /* Line 406, Address: 0x10271c8 */
  d3.w.l = d0.w.l; /* Line 407, Address: 0x10271d4 */
  d3.w.l = (unsigned short)d3.w.l >> 1; /* Line 408, Address: 0x10271dc */
  d1.w.l = 35; /* Line 409, Address: 0x10271f8 */
  d5.w.l = 28; /* Line 410, Address: 0x1027200 */
  if (d1.w.l >= d3.w.l) { /* Line 411, Address: 0x1027208 */

    d1.w.l -= d3.w.l; /* Line 413, Address: 0x102722c */
    if (d1.w.l >= 27) { /* Line 414, Address: 0x102723c */

      d1.w.l = 27; /* Line 416, Address: 0x1027254 */
    }
    d5.w.l -= d1.w.l; /* Line 418, Address: 0x102725c */
    pHscrollwork = &hscrollwork[d0.w.l / 2 + 6]; /* Line 419, Address: 0x102726c */


    d2.w.l &= 7; /* Line 422, Address: 0x10272a4 */
    d2.w.l += d2.w.l; /* Line 423, Address: 0x10272b0 */
    d0.w.h = 0; /* Line 424, Address: 0x10272c0 */
    d0.w.h = -scra_h_posit.w.h; /* Line 425, Address: 0x10272c4 */
    d0.w.l = *pHscrollwork++; /* Line 426, Address: 0x10272e4 */
    cnt = 8 - d2.w.l / 2; /* Line 427, Address: 0x10272f4 */
    temp = d1.w.l; /* Line 428, Address: 0x1027320 */
    if (d1.w.l == 27) ++temp; /* Line 429, Address: 0x102732c */

    for (i = 0; temp >= i; ++i) { /* Line 431, Address: 0x1027348 */

      if (i != 0) { /* Line 433, Address: 0x1027354 */

        cnt = 8; /* Line 435, Address: 0x102735c */
      }
      for (j = 0; j < cnt; ++j) { /* Line 437, Address: 0x1027360 */

        *pHscrollbuff++ = d0; /* Line 439, Address: 0x102736c */
      } /* Line 440, Address: 0x1027380 */
      d0.w.l = *pHscrollwork++; /* Line 441, Address: 0x1027390 */
    } /* Line 442, Address: 0x10273a0 */
  }

  d0.w.l = scrc_h_posit.w.h; /* Line 445, Address: 0x10273b0 */
  d2.w.l = scra_h_posit.w.h; /* Line 446, Address: 0x10273bc */
  d2.w.l -= d0.w.l; /* Line 447, Address: 0x10273c8 */
  d2.l = d2.w.l; /* Line 448, Address: 0x10273d8 */
  d2.l *= 256; /* Line 449, Address: 0x10273e8 */
  d2.w.l = (long int)d2.l / 256; /* Line 450, Address: 0x10273f4 */
  d2.l = d2.w.l; /* Line 451, Address: 0x1027424 */
  d2.l *= 256; /* Line 452, Address: 0x1027434 */
  d3.l = 0; /* Line 453, Address: 0x1027440 */
  d3.w.l = d0.w.l; /* Line 454, Address: 0x1027444 */
  d1.w.l = d5.w.l; /* Line 455, Address: 0x102744c */
  d1.w.l = (unsigned short)d1.w.l * 8; /* Line 456, Address: 0x1027454 */
  --d1.w.l; /* Line 457, Address: 0x1027470 */


  do {
    d0.w.l = d3.w.l; /* Line 461, Address: 0x102747c */
    d0.w.l *= -1; /* Line 462, Address: 0x1027484 */
    *pHscrollbuff++ = d0; /* Line 463, Address: 0x1027490 */
    s = d3.w.h; /* Line 464, Address: 0x10274a8 */
    d3.w.h = d3.w.l; /* Line 465, Address: 0x10274b4 */
    d3.w.l = s; /* Line 466, Address: 0x10274bc */
    d3.l += d2.l; /* Line 467, Address: 0x10274c0 */
    s = d3.w.h; /* Line 468, Address: 0x10274d0 */
    d3.w.h = d3.w.l; /* Line 469, Address: 0x10274e0 */
    d3.w.l = s; /* Line 470, Address: 0x10274e8 */
  } while (d1.w.l--); /* Line 471, Address: 0x10274ec */

} /* Line 473, Address: 0x1027500 */









void scroll_h() { /* Line 483, Address: 0x1027540 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 486, Address: 0x102754c */
  scrh_move(); /* Line 487, Address: 0x1027558 */
  if ((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) { /* Line 488, Address: 0x1027560 */
    scra_h_count ^= 16; /* Line 489, Address: 0x1027594 */
    if ((short)wD4 > scra_h_posit.w.h) scrflaga.b.h |= 4; /* Line 490, Address: 0x10275a8 */
    else scrflaga.b.h |= 8; /* Line 491, Address: 0x10275f0 */
  }
} /* Line 493, Address: 0x1027604 */


void scrh_move() { /* Line 496, Address: 0x1027620 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 499, Address: 0x102762c */
  wD0 -= scra_h_posit.w.h; /* Line 500, Address: 0x1027638 */
  wD0 -= scra_hline; /* Line 501, Address: 0x102764c */
  if (wD0 == 0) scra_hz = 0; /* Line 502, Address: 0x1027660 */
  else if ((short)wD0 < 0) left_check(wD0); /* Line 503, Address: 0x102767c */
  else right_check(wD0); /* Line 504, Address: 0x10276a8 */
} /* Line 505, Address: 0x10276b4 */


void right_check(unsigned short wD0) { /* Line 508, Address: 0x10276d0 */
  unsigned short wD1;

  if ((short)wD0 > 16) wD0 = 16; /* Line 511, Address: 0x10276dc */
  wD0 += scra_h_posit.w.h; /* Line 512, Address: 0x1027704 */
  if (scralim_right < (short)wD0) wD0 = scralim_right; /* Line 513, Address: 0x102771c */
  wD1 = wD0; /* Line 514, Address: 0x1027758 */
  wD1 -= scra_h_posit.w.h; /* Line 515, Address: 0x1027760 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 516, Address: 0x1027774 */
  scra_h_posit.w.h = wD0; /* Line 517, Address: 0x10277a4 */
  scra_hz = wD1; /* Line 518, Address: 0x10277b0 */
} /* Line 519, Address: 0x10277b8 */


void left_check(unsigned short wD0) { /* Line 522, Address: 0x10277d0 */
  unsigned short wD1;

  if ((short)wD0 < -16) wD0 = 65520; /* Line 525, Address: 0x10277dc */
  wD0 += scra_h_posit.w.h; /* Line 526, Address: 0x1027804 */
  if (scralim_left > (short)wD0) wD0 = scralim_left; /* Line 527, Address: 0x102781c */
  wD1 = wD0; /* Line 528, Address: 0x1027858 */
  wD1 -= scra_h_posit.w.h; /* Line 529, Address: 0x1027860 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 530, Address: 0x1027874 */
  scra_h_posit.w.h = wD0; /* Line 531, Address: 0x10278a4 */
  scra_hz = wD1; /* Line 532, Address: 0x10278b0 */
} /* Line 533, Address: 0x10278b8 */










void scroll_v() { /* Line 544, Address: 0x10278d0 */
  short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 547, Address: 0x10278dc */
  if (actwk[0].cddat & 4) wD0 -= 5; /* Line 548, Address: 0x1027910 */
  if (actwk[0].cddat & 2) { /* Line 549, Address: 0x1027934 */
    wD0 += 32; /* Line 550, Address: 0x102794c */
    if (wD0 < scra_vline) { /* Line 551, Address: 0x1027958 */
      wD0 -= scra_vline; /* Line 552, Address: 0x102797c */
      sv_move_main2(wD0); /* Line 553, Address: 0x1027990 */
      return; /* Line 554, Address: 0x102799c */
    }
    if (wD0 >= scra_vline + 64) { /* Line 556, Address: 0x10279a4 */
      wD0 -= scra_vline + 64; /* Line 557, Address: 0x10279cc */
      sv_move_main2(wD0); /* Line 558, Address: 0x10279f4 */
      return; /* Line 559, Address: 0x1027a00 */
    }

    wD0 -= scra_vline + 64; /* Line 562, Address: 0x1027a08 */
    if (!limmoveflag) goto label1; /* Line 563, Address: 0x1027a30 */
    sv_move_sub2(); /* Line 564, Address: 0x1027a40 */
    return; /* Line 565, Address: 0x1027a48 */
  }



  if ((wD0 -= scra_vline) != 0) { /* Line 570, Address: 0x1027a50 */
    sv_move_main(wD0); /* Line 571, Address: 0x1027a7c */
    return; /* Line 572, Address: 0x1027a88 */
  }
  if (limmoveflag) { /* Line 574, Address: 0x1027a90 */
    sv_move_sub2(); /* Line 575, Address: 0x1027aa0 */
    return; /* Line 576, Address: 0x1027aa8 */
  }
label1:
  scra_vz = 0; /* Line 579, Address: 0x1027ab0 */
} /* Line 580, Address: 0x1027ab8 */





void sv_move_main(short wD0) { /* Line 586, Address: 0x1027ad0 */
  short wD1;

  if (scra_vline != 96) sv_move_main1(wD0); /* Line 589, Address: 0x1027ae0 */
  else {
    wD1 = actwk[0].mspeed.w; /* Line 591, Address: 0x1027b10 */
    if (wD1 < 0) wD1 *= -1; /* Line 592, Address: 0x1027b20 */
    if (wD1 >= 2048) { /* Line 593, Address: 0x1027b3c */
      sv_move_main2(wD0); /* Line 594, Address: 0x1027b50 */
      return; /* Line 595, Address: 0x1027b5c */
    }
    if (wD0 > 6) sv_move_plus(1536); /* Line 597, Address: 0x1027b64 */
    else if (wD0 < -6) sv_move_minus(1536); /* Line 598, Address: 0x1027b90 */
    else sv_move_sub(wD0); /* Line 599, Address: 0x1027bbc */
  }
} /* Line 601, Address: 0x1027bc8 */


void sv_move_main1(short wD0) { /* Line 604, Address: 0x1027be0 */
  if (wD0 > 2) sv_move_plus(512); /* Line 605, Address: 0x1027bec */
  else if (wD0 < -2) sv_move_minus(512); /* Line 606, Address: 0x1027c18 */
  else sv_move_sub(wD0); /* Line 607, Address: 0x1027c44 */
} /* Line 608, Address: 0x1027c50 */


void sv_move_main2(short wD0) { /* Line 611, Address: 0x1027c60 */
  if ((short)wD0 > 16) sv_move_plus(4096); /* Line 612, Address: 0x1027c6c */
  else if ((short)wD0 < -16) sv_move_minus(4096); /* Line 613, Address: 0x1027c98 */
  else sv_move_sub(wD0); /* Line 614, Address: 0x1027cc4 */
} /* Line 615, Address: 0x1027cd0 */


void sv_move_sub2() { /* Line 618, Address: 0x1027ce0 */
  limmoveflag = 0; /* Line 619, Address: 0x1027ce8 */
  sv_move_sub(0); /* Line 620, Address: 0x1027cf0 */
} /* Line 621, Address: 0x1027cfc */


void sv_move_sub(short wD0) { /* Line 624, Address: 0x1027d10 */
  int_union lD1;

  lD1.w.h = 0; /* Line 627, Address: 0x1027d1c */
  lD1.w.l = wD0 + scra_v_posit.w.h; /* Line 628, Address: 0x1027d20 */
  if (wD0 < 0) scrv_up_ch(lD1); /* Line 629, Address: 0x1027d4c */
  else scrv_down_ch(lD1); /* Line 630, Address: 0x1027d74 */
} /* Line 631, Address: 0x1027d80 */




void sv_move_minus(short wD1) { /* Line 636, Address: 0x1027d90 */
  int_union lD1;
  short wk;

  lD1.l = (-wD1 << 8) + scra_v_posit.l; /* Line 640, Address: 0x1027da0 */

  wk = lD1.w.h; /* Line 642, Address: 0x1027dc4 */
  lD1.w.h = lD1.w.l; /* Line 643, Address: 0x1027dd0 */
  lD1.w.l = wk; /* Line 644, Address: 0x1027dd8 */
  scrv_up_ch(lD1); /* Line 645, Address: 0x1027ddc */
} /* Line 646, Address: 0x1027de8 */


void scrv_up_ch(int_union lD1) { /* Line 649, Address: 0x1027e00 */
  if (lD1.w.l <= scralim_up) { /* Line 650, Address: 0x1027e0c */
    if (lD1.w.l > -256) { /* Line 651, Address: 0x1027e34 */
      lD1.w.l = scralim_up; /* Line 652, Address: 0x1027e4c */
    } /* Line 653, Address: 0x1027e58 */
    else {
      lD1.w.l &= 2047; /* Line 655, Address: 0x1027e60 */
      actwk[0].yposi.w.h &= 2047; /* Line 656, Address: 0x1027e6c */
      scra_v_posit.w.h &= 2047; /* Line 657, Address: 0x1027e80 */
      scrb_v_posit.w.h &= 1023; /* Line 658, Address: 0x1027e94 */
    }
  }
  scrv_move(lD1); /* Line 661, Address: 0x1027ea8 */
} /* Line 662, Address: 0x1027eb4 */


void sv_move_plus(short wD1) { /* Line 665, Address: 0x1027ed0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = (wD1 << 8) + scra_v_posit.l; /* Line 669, Address: 0x1027ee0 */

  wk = lD1.w.h; /* Line 671, Address: 0x1027f00 */
  lD1.w.h = lD1.w.l; /* Line 672, Address: 0x1027f08 */
  lD1.w.l = wk; /* Line 673, Address: 0x1027f10 */
  scrv_down_ch(lD1); /* Line 674, Address: 0x1027f14 */
} /* Line 675, Address: 0x1027f20 */



void scrv_down_ch(int_union lD1) { /* Line 679, Address: 0x1027f40 */
  if (lD1.w.l >= scralim_down) { /* Line 680, Address: 0x1027f4c */
    if ((lD1.w.l -= +2048) < 0) { /* Line 681, Address: 0x1027f74 */
      lD1.w.l = scralim_down; /* Line 682, Address: 0x1027f98 */
    } /* Line 683, Address: 0x1027fa4 */
    else {
      actwk[0].yposi.w.h &= 2047; /* Line 685, Address: 0x1027fac */
      scra_v_posit.w.h -= 2048; /* Line 686, Address: 0x1027fc0 */
      scrb_v_posit.w.h &= 1023; /* Line 687, Address: 0x1027fd4 */
    }
  }
  scrv_move(lD1); /* Line 690, Address: 0x1027fe8 */
} /* Line 691, Address: 0x1027ff4 */


void scrv_move(int_union lD1) { /* Line 694, Address: 0x1028010 */
  short wD4, wk;
  uint_union dwk;

  wD4 = scra_v_posit.w.h; /* Line 698, Address: 0x1028020 */

  wk = lD1.w.h; /* Line 700, Address: 0x1028030 */
  lD1.w.h = lD1.w.l; /* Line 701, Address: 0x102803c */
  lD1.w.l = wk; /* Line 702, Address: 0x1028044 */

  dwk.l = lD1.l - scra_v_posit.l; /* Line 704, Address: 0x1028048 */
  dwk.l = (dwk.l >> 8) | (dwk.l << 24); /* Line 705, Address: 0x102805c */
  scra_vz = dwk.w.l; /* Line 706, Address: 0x1028074 */

  scra_v_posit.l = lD1.l; /* Line 708, Address: 0x1028080 */

  wk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 710, Address: 0x102808c */
  if (!wk) { /* Line 711, Address: 0x10280c8 */
    scra_v_count ^= 16; /* Line 712, Address: 0x10280d0 */
    wk = scra_v_posit.w.h - wD4; /* Line 713, Address: 0x10280e4 */
    if (wk < 0) scrflaga.b.h |= 1; /* Line 714, Address: 0x1028110 */
    else scrflaga.b.h |= 2; /* Line 715, Address: 0x102813c */
  }
} /* Line 717, Address: 0x1028150 */











void scrollb_hv(int lD4, int lD5) { /* Line 729, Address: 0x1028170 */
  int lD0, lD1;
  int_union lD2;

  lD0 = scrb_h_posit.l; /* Line 733, Address: 0x1028184 */
  lD2.l = scrb_h_posit.l = lD1 = lD0 + lD4; /* Line 734, Address: 0x102818c */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_h_count) == 0) { /* Line 735, Address: 0x10281a0 */
    scrb_h_count ^= 16; /* Line 736, Address: 0x10281d0 */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 4; /* Line 737, Address: 0x10281e4 */
    else scrflagb.b.h |= 8; /* Line 738, Address: 0x102820c */
  }
  lD0 = scrb_v_posit.l; /* Line 740, Address: 0x1028220 */
  lD2.l = scrb_v_posit.l = lD1 = lD0 + lD5; /* Line 741, Address: 0x1028228 */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_v_count) == 0) { /* Line 742, Address: 0x102823c */
    scrb_v_count ^= 16; /* Line 743, Address: 0x102826c */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 1; /* Line 744, Address: 0x1028280 */
    else scrflagb.b.h |= 2; /* Line 745, Address: 0x10282a8 */
  }
} /* Line 747, Address: 0x10282bc */










void scrollb_v(unsigned short wD0) { /* Line 758, Address: 0x10282d0 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 761, Address: 0x10282dc */
  scrb_v_posit.w.h = wD0; /* Line 762, Address: 0x10282e8 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 764, Address: 0x10282f4 */
    scrb_v_count ^= 16; /* Line 765, Address: 0x1028320 */
    if ((short)wD3 > (short)wD0) { /* Line 766, Address: 0x1028334 */
      scrflagb.b.h |= 1; /* Line 767, Address: 0x1028364 */
    } /* Line 768, Address: 0x1028378 */
    else {

      scrflagb.b.h |= 2; /* Line 771, Address: 0x1028380 */
    }
  }


} /* Line 776, Address: 0x1028394 */











void scrollb_h(int lD4, int flagb) { /* Line 788, Address: 0x10283b0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 792, Address: 0x10283c0 */
  lD0.l = lD2.l + lD4; /* Line 793, Address: 0x10283cc */
  scrb_h_posit.l = lD0.l; /* Line 794, Address: 0x10283dc */

  lD1.w.h = lD0.w.l; /* Line 796, Address: 0x10283e8 */
  lD1.w.l = lD0.w.h; /* Line 797, Address: 0x10283f0 */
  lD1.w.l &= 16; /* Line 798, Address: 0x10283f8 */

  bD3 = scrb_h_count; /* Line 800, Address: 0x1028404 */
  lD1.b.b4 ^= bD3; /* Line 801, Address: 0x1028410 */
  if (!lD1.b.b4) { /* Line 802, Address: 0x1028424 */




    scrb_h_count ^= 16; /* Line 807, Address: 0x1028430 */
    lD0.l -= lD2.l; /* Line 808, Address: 0x1028444 */
    if ((long int)lD0.l < 0) scrflagb.b.h |= flagb; /* Line 809, Address: 0x1028454 */
    else scrflagb.b.h |= flagb * 2; /* Line 810, Address: 0x102848c */
  }
} /* Line 812, Address: 0x10284ac */











void scrollc_h(int lD4, int flagc) { /* Line 824, Address: 0x10284c0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 828, Address: 0x10284d0 */
  lD0.l = lD2.l + lD4; /* Line 829, Address: 0x10284dc */
  scrc_h_posit.l = lD0.l; /* Line 830, Address: 0x10284ec */

  lD1.w.h = lD0.w.l; /* Line 832, Address: 0x10284f8 */
  lD1.w.l = lD0.w.h; /* Line 833, Address: 0x1028500 */
  lD1.w.l &= 16; /* Line 834, Address: 0x1028508 */

  bD3 = scrc_h_count; /* Line 836, Address: 0x1028514 */
  lD1.b.b4 ^= bD3; /* Line 837, Address: 0x1028520 */
  if (!lD1.b.b4) { /* Line 838, Address: 0x1028534 */




    scrc_h_count ^= 16; /* Line 843, Address: 0x1028540 */
    lD0.l -= lD2.l; /* Line 844, Address: 0x1028554 */
    if ((long int)lD0.l < 0) scrflagc.b.h |= flagc; /* Line 845, Address: 0x1028564 */
    else scrflagc.b.h |= flagc * 2; /* Line 846, Address: 0x102859c */
  }
} /* Line 848, Address: 0x10285bc */











void scrollz_h(int lD4, int flagz) { /* Line 860, Address: 0x10285d0 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 864, Address: 0x10285e0 */
  lD0.l = lD2.l + lD4; /* Line 865, Address: 0x10285ec */
  scrz_h_posit.l = lD0.l; /* Line 866, Address: 0x10285fc */

  lD1.w.h = lD0.w.l; /* Line 868, Address: 0x1028608 */
  lD1.w.l = lD0.w.h; /* Line 869, Address: 0x1028610 */
  lD1.w.l &= 16; /* Line 870, Address: 0x1028618 */

  bD3 = scrz_h_count; /* Line 872, Address: 0x1028624 */
  lD1.b.b4 ^= bD3; /* Line 873, Address: 0x1028630 */
  if (!lD1.b.b4) { /* Line 874, Address: 0x1028644 */




    scrz_h_count ^= 16; /* Line 879, Address: 0x1028650 */
    lD0.l -= lD2.l; /* Line 880, Address: 0x1028664 */
    if ((long int)lD0.l < 0) scrflagz.b.h |= flagz; /* Line 881, Address: 0x1028674 */
    else scrflagz.b.h |= flagz * 2; /* Line 882, Address: 0x10286ac */
  }
} /* Line 884, Address: 0x10286cc */











void scrollwrtadva() { /* Line 896, Address: 0x10286e0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 902, Address: 0x10286fc */
  wH_posiw = scrb_h_posit.w.h; /* Line 903, Address: 0x1028700 */
  wV_posiw = scrb_v_posit.w.h; /* Line 904, Address: 0x102870c */
  pMapWk = (unsigned char*)mapwkb; /* Line 905, Address: 0x1028718 */
  pScrFlag = &scrflagb.b.h; /* Line 906, Address: 0x1028720 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 907, Address: 0x1028728 */





} /* Line 913, Address: 0x102873c */













void scrollwrt() { /* Line 927, Address: 0x1028760 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 936, Address: 0x1028780 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 937, Address: 0x1028784 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 938, Address: 0x1028790 */
  pMapWk = (unsigned char*)mapwkb; /* Line 939, Address: 0x102879c */
  pScrFlag = &scrflagbw.b.h; /* Line 940, Address: 0x10287a4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 941, Address: 0x10287ac */

  VramBase = 16384; /* Line 943, Address: 0x10287c0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 944, Address: 0x10287c4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 945, Address: 0x10287d0 */
  pMapWk = (unsigned char*)mapwka; /* Line 946, Address: 0x10287dc */
  pScrFlag = &scrflagaw.b.h; /* Line 947, Address: 0x10287e4 */

  if (*pScrFlag) { /* Line 949, Address: 0x10287ec */
    if (*pScrFlag & 1) { /* Line 950, Address: 0x10287f8 */
      *pScrFlag &= 254; /* Line 951, Address: 0x102880c */

      lD4.l = -16; /* Line 953, Address: 0x1028818 */
      wD5 = 65520; /* Line 954, Address: 0x1028820 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 956, Address: 0x1028828 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 958, Address: 0x1028848 */
    }




    if (*pScrFlag & 2) { /* Line 964, Address: 0x1028874 */
      *pScrFlag &= 253; /* Line 965, Address: 0x1028888 */

      lD4.l = 224; /* Line 967, Address: 0x1028894 */
      wD5 = 65520; /* Line 968, Address: 0x102889c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 969, Address: 0x10288a4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 971, Address: 0x10288c4 */
    }




    if (*pScrFlag & 4) { /* Line 977, Address: 0x10288f0 */
      *pScrFlag &= 251; /* Line 978, Address: 0x1028904 */

      lD4.l = -16; /* Line 980, Address: 0x1028910 */
      wD5 = 65520; /* Line 981, Address: 0x1028918 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 982, Address: 0x1028920 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 984, Address: 0x1028940 */
    }




    if (*pScrFlag & 8) { /* Line 990, Address: 0x102896c */
      *pScrFlag &= 247; /* Line 991, Address: 0x1028980 */

      lD4.l = -16; /* Line 993, Address: 0x102898c */
      wD5 = 320; /* Line 994, Address: 0x1028994 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 995, Address: 0x102899c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 997, Address: 0x10289bc */
    }
  }






} /* Line 1006, Address: 0x10289e8 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1020, Address: 0x1028a10 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1031, Address: 0x1028a3c */

  if (*pScrFlag & 1) { /* Line 1033, Address: 0x1028a44 */
    *pScrFlag &= 254; /* Line 1034, Address: 0x1028a5c */
  } /* Line 1035, Address: 0x1028a70 */
  else {
    *pScrFlag &= 254; /* Line 1037, Address: 0x1028a78 */

    if (*pScrFlag & 2) { /* Line 1039, Address: 0x1028a8c */
      *pScrFlag &= 253; /* Line 1040, Address: 0x1028aa4 */
      lD4.w.l = 224; /* Line 1041, Address: 0x1028ab8 */
    } /* Line 1042, Address: 0x1028ac0 */
    else {
      *pScrFlag &= 253; /* Line 1044, Address: 0x1028ac8 */
      goto label1; /* Line 1045, Address: 0x1028adc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1050, Address: 0x1028ae4 */
  wD0 &= 127; /* Line 1051, Address: 0x1028b34 */
  wD0 &= 31; /* Line 1052, Address: 0x1028b3c */
  wD0 = z12awrttbl[wD0 + 1]; /* Line 1053, Address: 0x1028b44 */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1054, Address: 0x1028b64 */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1055, Address: 0x1028b84 */
  if (wD0 != 0) { /* Line 1056, Address: 0x1028ba8 */
    wD5 = 65520; /* Line 1057, Address: 0x1028bb4 */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1058, Address: 0x1028bbc */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1060, Address: 0x1028bdc */



  } /* Line 1064, Address: 0x1028c08 */
  else {

    wD5 = 0; /* Line 1067, Address: 0x1028c10 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1068, Address: 0x1028c14 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1072, Address: 0x1028c34 */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1079, Address: 0x1028c60 */






    lD4.l = -16; /* Line 1086, Address: 0x1028c74 */
    wD5 = 65520; /* Line 1087, Address: 0x1028c7c */
    if (*pScrFlag & 168) { /* Line 1088, Address: 0x1028c84 */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1089, Address: 0x1028c9c */
      wD5 = 320; /* Line 1090, Address: 0x1028cbc */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1094, Address: 0x1028cc4 */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1096, Address: 0x1028cf4 */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1097, Address: 0x1028d00 */



    for (i = 0; i < 16; ++i) { /* Line 1101, Address: 0x1028d10 */
      wD0 = z12awrttbl[WrtTblCnt++]; /* Line 1102, Address: 0x1028d1c */
      if (wD0 != 0) { /* Line 1103, Address: 0x1028d3c */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1104, Address: 0x1028d48 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1105, Address: 0x1028d74 */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1106, Address: 0x1028d94 */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1108, Address: 0x1028db8 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1111, Address: 0x1028ddc */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1113, Address: 0x1028dfc */
        }
      }
      lD4.w.l += 16; /* Line 1116, Address: 0x1028e10 */
    } /* Line 1117, Address: 0x1028e1c */
    *pScrFlag = 0; /* Line 1118, Address: 0x1028e2c */
  }
} /* Line 1120, Address: 0x1028e34 */




void scrollwrtc() {} /* Line 1125, Address: 0x1028e60 */




void scrollwrtz() {} /* Line 1130, Address: 0x1028e70 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1148, Address: 0x1028e80 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1152, Address: 0x1028ea8 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1153, Address: 0x1028ec8 */
    pTilePoint->x += 2; /* Line 1154, Address: 0x1028edc */
    if (pTilePoint->x >= 64) pTilePoint->x -= 64; /* Line 1155, Address: 0x1028ef0 */
    xOffs += 16; /* Line 1156, Address: 0x1028f18 */
  } while (--lpcnt >= 0); /* Line 1157, Address: 0x1028f24 */
} /* Line 1158, Address: 0x1028f38 */

void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1160, Address: 0x1028f50 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1164, Address: 0x1028f78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1167, Address: 0x1028f98 */
    pTilePoint->x += 2; /* Line 1168, Address: 0x1028fac */
    if (pTilePoint->x >= 64) { /* Line 1169, Address: 0x1028fc0 */
      pTilePoint->x -= 64; /* Line 1170, Address: 0x1028fd4 */
    }
    xOffs += 16; /* Line 1172, Address: 0x1028fe8 */
  } while (--lpcnt >= 0); /* Line 1173, Address: 0x1028ff4 */
} /* Line 1174, Address: 0x1029008 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1190, Address: 0x1029020 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1194, Address: 0x1029048 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1197, Address: 0x1029068 */
    pTilePoint->y += 2; /* Line 1198, Address: 0x102907c */
    if (pTilePoint->y >= 32) { /* Line 1199, Address: 0x102908c */
      pTilePoint->y -= 32; /* Line 1200, Address: 0x10290a0 */
    }
    yOffs += 16; /* Line 1202, Address: 0x10290b0 */
  } while (--lpcnt >= 0); /* Line 1203, Address: 0x10290bc */
} /* Line 1204, Address: 0x10290d0 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1222, Address: 0x10290e0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1228, Address: 0x1029114 */

    base = 1; /* Line 1230, Address: 0x1029124 */
  } /* Line 1231, Address: 0x1029128 */
  else if (VramBase == 16384) { /* Line 1232, Address: 0x1029130 */

    base = 0; /* Line 1234, Address: 0x1029140 */
  }
  x = pTilePoint->x; /* Line 1236, Address: 0x1029144 */
  y = pTilePoint->y; /* Line 1237, Address: 0x102914c */


  frip = BlkIndex & 6144; /* Line 1240, Address: 0x1029154 */
  BlkIndex &= 1023; /* Line 1241, Address: 0x102915c */
  if (frip == 6144) { /* Line 1242, Address: 0x1029168 */

    p0 = 3, p1 = 2; /* Line 1244, Address: 0x1029174 */
    p2 = 1, p3 = 0; /* Line 1245, Address: 0x102917c */
  } /* Line 1246, Address: 0x1029184 */
  else if (frip & 4096) { /* Line 1247, Address: 0x102918c */

    p0 = 2, p1 = 3; /* Line 1249, Address: 0x1029198 */
    p2 = 0, p3 = 1; /* Line 1250, Address: 0x10291a0 */
  } /* Line 1251, Address: 0x10291a8 */
  else if (frip & 2048) { /* Line 1252, Address: 0x10291b0 */

    p0 = 1, p1 = 0; /* Line 1254, Address: 0x10291bc */
    p2 = 3, p3 = 2; /* Line 1255, Address: 0x10291c4 */
  } /* Line 1256, Address: 0x10291cc */
  else {

    p0 = 0, p1 = 1; /* Line 1259, Address: 0x10291d4 */
    p2 = 2, p3 = 3; /* Line 1260, Address: 0x10291dc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1263, Address: 0x10291e4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1264, Address: 0x1029228 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1265, Address: 0x102926c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1266, Address: 0x10292b0 */

} /* Line 1268, Address: 0x10292f4 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1287, Address: 0x1029330 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1288, Address: 0x1029350 */
} /* Line 1289, Address: 0x1029370 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1292, Address: 0x1029380 */
  wH_posiw = 0; /* Line 1293, Address: 0x10293a0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1294, Address: 0x10293a4 */
} /* Line 1295, Address: 0x10293c4 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1298, Address: 0x10293e0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1304, Address: 0x1029410 */
  yOffs += wV_posiw; /* Line 1305, Address: 0x1029420 */





  if ((short)xOffs < 0) /* Line 1311, Address: 0x1029430 */
    xOffs = 0; /* Line 1312, Address: 0x102944c */
  if ((short)yOffs < 0) /* Line 1313, Address: 0x1029450 */
    yOffs = 0; /* Line 1314, Address: 0x102946c */
  if ((short)xOffs >= 16384) /* Line 1315, Address: 0x1029470 */
    xOffs = 16383; /* Line 1316, Address: 0x1029490 */
  if ((short)yOffs >= 2048) /* Line 1317, Address: 0x1029498 */
    yOffs = 2047; /* Line 1318, Address: 0x10294b8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1319, Address: 0x10294c0 */
  if (i < 0) i = 0; /* Line 1320, Address: 0x1029508 */

  ScreenNo = pMapWk[i] & 127; /* Line 1322, Address: 0x1029514 */

  if (ScreenNo) { /* Line 1324, Address: 0x1029530 */




    xOffs &= 32767; /* Line 1329, Address: 0x1029538 */
    yOffs &= 32767; /* Line 1330, Address: 0x1029544 */


    xBlk = xOffs; /* Line 1333, Address: 0x1029550 */
    xBlk %= 256; /* Line 1334, Address: 0x1029558 */
    xBlk /= 16; /* Line 1335, Address: 0x1029578 */
    yBlk = yOffs; /* Line 1336, Address: 0x1029594 */
    yBlk %= 256; /* Line 1337, Address: 0x102959c */
    yBlk /= 16; /* Line 1338, Address: 0x10295bc */

    lpw = pmapwk; /* Line 1340, Address: 0x10295d8 */
    lpw += xBlk; /* Line 1341, Address: 0x10295e0 */
    lpw += yBlk * 16; /* Line 1342, Address: 0x10295e8 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1343, Address: 0x10295f4 */
    *pIndex = *lpw; /* Line 1344, Address: 0x102960c */

    return 1; /* Line 1346, Address: 0x102961c */
  }

  *pIndex = 0; /* Line 1349, Address: 0x1029628 */
  return 0; /* Line 1350, Address: 0x1029630 */
} /* Line 1351, Address: 0x1029634 */

















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1369, Address: 0x1029660 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1377, Address: 0x1029688 */
  if (ScreenNo) { /* Line 1378, Address: 0x10296ec */





    xBlk = xOffs; /* Line 1384, Address: 0x10296f4 */
    xBlk %= 256; /* Line 1385, Address: 0x10296fc */
    xBlk /= 16; /* Line 1386, Address: 0x102971c */
    yBlk = yOffs; /* Line 1387, Address: 0x1029738 */
    yBlk %= 256; /* Line 1388, Address: 0x1029740 */
    yBlk /= 16; /* Line 1389, Address: 0x1029760 */


    lpw = pmapwk; /* Line 1392, Address: 0x102977c */
    lpw += xBlk; /* Line 1393, Address: 0x1029784 */
    lpw += yBlk * 16; /* Line 1394, Address: 0x102978c */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1395, Address: 0x1029798 */
    *ppBlockNo = lpw; /* Line 1396, Address: 0x10297b0 */
    *pIndex = *lpw; /* Line 1397, Address: 0x10297b8 */




    return 1; /* Line 1402, Address: 0x10297c8 */
  }

  *pIndex = 0; /* Line 1405, Address: 0x10297d4 */
  return 0; /* Line 1406, Address: 0x10297dc */
} /* Line 1407, Address: 0x10297e0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1421, Address: 0x1029800 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1428, Address: 0x102981c */
  pMapWk = (unsigned char*)mapwka; /* Line 1429, Address: 0x1029820 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1430, Address: 0x1029828 */
    *pBlockIndex = BlockNo; /* Line 1431, Address: 0x102984c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1432, Address: 0x1029858 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1433, Address: 0x1029870 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1434, Address: 0x1029884 */
    }
  }


} /* Line 1439, Address: 0x102989c */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1451, Address: 0x10298c0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1452, Address: 0x10298cc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1453, Address: 0x10298f8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1454, Address: 0x1029944 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1455, Address: 0x1029970 */

          return 0; /* Line 1457, Address: 0x10299bc */
        }
      }
    }
  }

  return 1; /* Line 1463, Address: 0x10299c8 */
} /* Line 1464, Address: 0x10299cc */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1479, Address: 0x10299e0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1480, Address: 0x10299fc */
} /* Line 1481, Address: 0x1029a18 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1484, Address: 0x1029a30 */
  wH_posiw = 0; /* Line 1485, Address: 0x1029a4c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1486, Address: 0x1029a50 */
} /* Line 1487, Address: 0x1029a6c */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1490, Address: 0x1029a80 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1491, Address: 0x1029a94 */
} /* Line 1492, Address: 0x1029ab0 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1495, Address: 0x1029ac0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1496, Address: 0x1029adc */
} /* Line 1497, Address: 0x1029af8 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1500, Address: 0x1029b10 */
  xOffs += wH_posiw; /* Line 1501, Address: 0x1029b28 */
  yOffs += wV_posiw; /* Line 1502, Address: 0x1029b38 */
  yOffs &= 240; /* Line 1503, Address: 0x1029b48 */
  xOffs &= 496; /* Line 1504, Address: 0x1029b54 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1506, Address: 0x1029b60 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1507, Address: 0x1029b8c */

} /* Line 1509, Address: 0x1029bb8 */













void mapwrt() { /* Line 1523, Address: 0x1029bd0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1528, Address: 0x1029be8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1529, Address: 0x1029bf4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1530, Address: 0x1029c00 */
  VramBase = 16384; /* Line 1531, Address: 0x1029c08 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1532, Address: 0x1029c0c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1536, Address: 0x1029c24 */
  VramBase = 24576; /* Line 1537, Address: 0x1029c2c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1538, Address: 0x1029c30 */
} /* Line 1539, Address: 0x1029c40 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1542, Address: 0x1029c60 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1543, Address: 0x1029c78 */
} /* Line 1544, Address: 0x1029c98 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1547, Address: 0x1029cb0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1551, Address: 0x1029cd0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1554, Address: 0x1029cec */



    wD4 += 16; /* Line 1558, Address: 0x1029d14 */
  } while ((short)--wD6 >= 0); /* Line 1559, Address: 0x1029d20 */
} /* Line 1560, Address: 0x1029d48 */


void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1563, Address: 0x1029d60 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1566, Address: 0x1029d7c */
  wD6 = 15; /* Line 1567, Address: 0x1029d84 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1570, Address: 0x1029d8c */
    mapwrt_sub(&z12awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1571, Address: 0x1029db0 */
    wD4 += 16; /* Line 1572, Address: 0x1029dd0 */
  } while ((short)--wD6 >= 0); /* Line 1573, Address: 0x1029dd8 */
} /* Line 1574, Address: 0x1029dfc */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1590, Address: 0x1029e20 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1595, Address: 0x1029e48 */
  wD0 = pWrttbl[wD0]; /* Line 1596, Address: 0x1029e58 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1597, Address: 0x1029e74 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1598, Address: 0x1029e98 */
  if (wD0) { /* Line 1599, Address: 0x1029ec0 */
    wD5 = 65520; /* Line 1600, Address: 0x1029ecc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1601, Address: 0x1029ed4 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1602, Address: 0x1029ef0 */
  } /* Line 1603, Address: 0x1029f18 */
  else {
    wD5 = 0; /* Line 1605, Address: 0x1029f20 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1606, Address: 0x1029f24 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1607, Address: 0x1029f40 */
  }
} /* Line 1609, Address: 0x1029f68 */










void mapinit() { /* Line 1620, Address: 0x1029f90 */

  colorset2(mapinittbl.colorno2); /* Line 1622, Address: 0x1029f98 */
  colorset(mapinittbl.colorno2); /* Line 1623, Address: 0x1029fac */

  if (plflag) enecginit(); /* Line 1625, Address: 0x1029fc0 */
  if (play_start & 2) divdevset(); /* Line 1626, Address: 0x1029fd8 */
} /* Line 1627, Address: 0x1029ff8 */
