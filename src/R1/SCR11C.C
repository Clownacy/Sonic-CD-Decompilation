#include "..\EQU.H"
#include "SCR11C.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1C.H"

static unsigned char z11cwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
  2, 4, 4, 4, 4, 0, 0, 0, 0, 0,
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
extern void(*sMemSet)(void*, unsigned char, int);
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;





























































































void enecginit() {} /* Line 131, Address: 0x1023ed0 */




void divdevset() {} /* Line 136, Address: 0x1023ee0 */












sprite_status* main_chk() {
  if (!main_play) return &actwk[0]; /* Line 150, Address: 0x1023ef0 */
  return &actwk[1]; /* Line 151, Address: 0x1023f10 */
} /* Line 152, Address: 0x1023f18 */










void scr_set() { /* Line 163, Address: 0x1023f20 */
  unsigned short scr_dir_tbl[6] = { /* Line 164, Address: 0x1023f2c */
    4, 0, 10391, 0, 784, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 169, Address: 0x1023f60 */

  i = 0; /* Line 171, Address: 0x1023fa8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 172, Address: 0x1023fac */
  scralim_left = scr_dir_tbl[i]; /* Line 173, Address: 0x1023fc8 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 174, Address: 0x1023fdc */
  scralim_right = scr_dir_tbl[i]; /* Line 175, Address: 0x1023ff8 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 176, Address: 0x102400c */
  scralim_up = scr_dir_tbl[i]; /* Line 177, Address: 0x1024028 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 178, Address: 0x102403c */
  scralim_down = scr_dir_tbl[i]; /* Line 179, Address: 0x1024058 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 180, Address: 0x102406c */

  scra_h_keep = scralim_left + 576; /* Line 182, Address: 0x1024088 */
  scra_h_count = 16; /* Line 183, Address: 0x10240ac */
  scra_v_count = 16; /* Line 184, Address: 0x10240b8 */

  scra_vline = scr_dir_tbl[i++]; /* Line 186, Address: 0x10240c4 */
  scra_hline = 160; /* Line 187, Address: 0x10240e0 */

  playposiset(); /* Line 189, Address: 0x10240ec */
} /* Line 190, Address: 0x10240f4 */










void playposiset() { /* Line 201, Address: 0x1024110 */
  unsigned short playpositbl[2] = { 80, 488 }; /* Line 202, Address: 0x1024124 */
  unsigned short endplpositbl[16] = { /* Line 203, Address: 0x1024140 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { 140, 127, 30, 30 }; /* Line 213, Address: 0x1024174 */
  short xWk;
  short yWk;
  int i;

  if (plflag) { /* Line 218, Address: 0x10241a0 */
    playload(); /* Line 219, Address: 0x10241b0 */
    xWk = actwk[0].xposi.w.h; /* Line 220, Address: 0x10241b8 */
    yWk = actwk[0].yposi.w.h; /* Line 221, Address: 0x10241c8 */
    if (yWk < 0) yWk = 0; /* Line 222, Address: 0x10241d8 */
  } /* Line 223, Address: 0x10241ec */
  else {
    if (demoflag.w & -32768) { /* Line 225, Address: 0x10241f4 */
      xWk = actwk[0].xposi.w.h = endplpositbl[(enddemono - 1) * 2]; /* Line 226, Address: 0x1024214 */
      yWk = actwk[0].yposi.w.h = endplpositbl[(enddemono - 1) * 2 + 1]; /* Line 227, Address: 0x1024248 */
    } /* Line 228, Address: 0x1024280 */
    else {
      xWk = actwk[0].xposi.w.h = playpositbl[demoflag.w * 2]; /* Line 230, Address: 0x1024288 */
      yWk = actwk[0].yposi.w.h = playpositbl[demoflag.w * 2 + 1]; /* Line 231, Address: 0x10242b8 */
    }
  }

  if ((unsigned short)xWk > 160) xWk -= 160; /* Line 235, Address: 0x10242ec */
  else xWk = 0; /* Line 236, Address: 0x1024314 */
  if ((unsigned short)scralim_right < (unsigned short)xWk) xWk = scralim_right; /* Line 237, Address: 0x1024318 */
  scra_h_posit.w.h = xWk; /* Line 238, Address: 0x102434c */

  if ((unsigned short)yWk > 96) yWk -= 96; /* Line 240, Address: 0x1024354 */
  else yWk = 0; /* Line 241, Address: 0x102437c */
  if ((unsigned short)scralim_down < (unsigned short)yWk) yWk = scralim_down; /* Line 242, Address: 0x1024380 */
  scra_v_posit.w.h = yWk; /* Line 243, Address: 0x10243b4 */

  scrbinit(xWk, yWk); /* Line 245, Address: 0x10243bc */

  i = 0; /* Line 247, Address: 0x10243cc */
  loopmapno = playmapnotbl[i++]; /* Line 248, Address: 0x10243d0 */
  loopmapno2 = playmapnotbl[i++]; /* Line 249, Address: 0x10243e8 */
  ballmapno = playmapnotbl[i++]; /* Line 250, Address: 0x1024400 */
  ballmapno2 = playmapnotbl[i++]; /* Line 251, Address: 0x1024418 */
} /* Line 252, Address: 0x1024430 */











void scrbinit(short xWk, short yWk) { /* Line 264, Address: 0x1024450 */
  int_union lYwk;

  lYwk.w.h = yWk; /* Line 267, Address: 0x1024460 */
  lYwk.w.l = 0; /* Line 268, Address: 0x1024468 */

  lYwk.l = (lYwk.l >> 4) * 2; /* Line 270, Address: 0x102446c */
  scrb_v_posit.l = lYwk.l; /* Line 271, Address: 0x102447c */
  scrc_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 272, Address: 0x1024488 */
  scrz_v_posit.w.h = (unsigned short)(yWk / 16) * 2; /* Line 273, Address: 0x10244c8 */

  scrc_h_posit.w.h = (unsigned short)(xWk / 4); /* Line 275, Address: 0x1024508 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 8); /* Line 276, Address: 0x1024540 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 277, Address: 0x1024578 */

  sMemSet(hscrollwork, 0, 16); /* Line 279, Address: 0x10245b8 */
} /* Line 280, Address: 0x10245d8 */










void scroll() { /* Line 291, Address: 0x10245f0 */
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int i;
  unsigned short wD0, wD1, wD3;
  int_union lD2, lD3;
  int lD4, lD5;
  short* psHscr;
  static int scaddtbl[4] = {
    65536, 49152, 32768, 16384
  };

  if (scroll_start.b.h) return; /* Line 303, Address: 0x102461c */

  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 305, Address: 0x102462c */

  scrchk(); /* Line 307, Address: 0x1024658 */

  scroll_h(); /* Line 309, Address: 0x1024660 */
  scroll_v(); /* Line 310, Address: 0x1024668 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 312, Address: 0x1024670 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 313, Address: 0x1024680 */

  scrollz_h(scra_hz << 5, 64); /* Line 315, Address: 0x1024690 */
  scrollc_h(scra_hz << 6, 16); /* Line 316, Address: 0x10246b0 */

  lD4 = (scra_hz << 4) * 3; /* Line 318, Address: 0x10246d0 */
  lD5 = (scra_vz << 4) * 2; /* Line 319, Address: 0x10246ec */
  scrollb_hv(lD4, lD5); /* Line 320, Address: 0x1024704 */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 322, Address: 0x1024714 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 323, Address: 0x1024724 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 324, Address: 0x1024734 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 326, Address: 0x1024744 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 327, Address: 0x102477c */

  for (i = 0, psHscr = hscrollwork; i < 4; ++i) { /* Line 329, Address: 0x1024790 */
    lD2.w.l = psHscr[0]; /* Line 330, Address: 0x10247a4 */
    lD2.w.h = psHscr[1]; /* Line 331, Address: 0x10247ac */
    lD2.l += scaddtbl[i]; /* Line 332, Address: 0x10247b4 */
    psHscr[0] = lD2.w.l; /* Line 333, Address: 0x10247d4 */
    psHscr[1] = lD2.w.h; /* Line 334, Address: 0x10247dc */
    psHscr += 2; /* Line 335, Address: 0x10247e4 */
  } /* Line 336, Address: 0x10247e8 */

  pHScrollWork = &hscrollwork[8]; /* Line 338, Address: 0x10247f8 */

  for (i = 0; i < 4; ++i) *pHScrollWork++ = -(hscrollwork[1] + scrz_h_posit.w.h); /* Line 340, Address: 0x1024800 */
  for (i = 0; i < 4; ++i) *pHScrollWork++ = -(hscrollwork[3] + scrz_h_posit.w.h); /* Line 341, Address: 0x1024858 */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[5] + scrz_h_posit.w.h); /* Line 342, Address: 0x10248b0 */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -(hscrollwork[7] + scrz_h_posit.w.h); /* Line 343, Address: 0x1024908 */

  for (i = 0; i < 6; ++i) *pHScrollWork++ = -scrz_h_posit.w.h; /* Line 345, Address: 0x1024960 */
  for (i = 0; i < 2; ++i) *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 346, Address: 0x10249a4 */
  for (i = 0; i < 8; ++i) *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 347, Address: 0x10249e8 */

  pHScrollBuff = lphscrollbuff; /* Line 349, Address: 0x1024a2c */

  lD5 = 28; /* Line 351, Address: 0x1024a34 */
  wD0 = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 352, Address: 0x1024a38 */
  wD3 = (wD0 < 2) ^ 1; /* Line 353, Address: 0x1024a60 */
  wD1 = 27 - wD3; /* Line 354, Address: 0x1024a74 */
  if (wD1 >= 0) { /* Line 355, Address: 0x1024a88 */
    lD5 -= wD1; /* Line 356, Address: 0x1024a94 */
    pHScrollWork = &hscrollwork[wD0 / 2] + 8; /* Line 357, Address: 0x1024a9c */

    lD2.w.l = scrb_v_posit.w.h & 7; /* Line 359, Address: 0x1024acc */
    wD0 = *pHScrollWork++; /* Line 360, Address: 0x1024aec */

    i = 8 - lD2.w.l; /* Line 362, Address: 0x1024afc */
    goto label1; /* Line 363, Address: 0x1024b10 */

    do {
      wD0 = *pHScrollWork++; /* Line 366, Address: 0x1024b18 */
      i = 8; /* Line 367, Address: 0x1024b28 */
label1:
      for ( ; i > 0; --i) { /* Line 369, Address: 0x1024b2c */
        pHScrollBuff->w.h = 0; /* Line 370, Address: 0x1024b34 */
        pHScrollBuff->w.l = wD0; /* Line 371, Address: 0x1024b38 */
        ++pHScrollBuff; /* Line 372, Address: 0x1024b3c */
      }; /* Line 373, Address: 0x1024b40 */
    } while ((short)--wD1 != -1); /* Line 374, Address: 0x1024b4c */
  }

  lD2.l = (scra_h_posit.w.h - scrc_h_posit.w.h) * 256 / 256 * 256; /* Line 377, Address: 0x1024b74 */
  lD3.w.l = 0; /* Line 378, Address: 0x1024bbc */
  lD3.w.h = wD0; /* Line 379, Address: 0x1024bc0 */
  wD1 = lD5 * 8 - 1; /* Line 380, Address: 0x1024bc4 */
  do {
    pHScrollBuff->w.h = 0; /* Line 382, Address: 0x1024bd4 */
    pHScrollBuff->w.l = -(unsigned short)lD3.w.h; /* Line 383, Address: 0x1024bd8 */
    ++pHScrollBuff; /* Line 384, Address: 0x1024bf4 */
    lD3.l += lD2.l; /* Line 385, Address: 0x1024bf8 */
  } while ((short)--wD1 != -1); /* Line 386, Address: 0x1024c08 */
} /* Line 387, Address: 0x1024c30 */










void scroll_h() { /* Line 398, Address: 0x1024c70 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 401, Address: 0x1024c7c */
  scrh_move(); /* Line 402, Address: 0x1024c88 */
  if ((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) { /* Line 403, Address: 0x1024c90 */
    scra_h_count ^= 16; /* Line 404, Address: 0x1024cc4 */
    if ((short)wD4 > scra_h_posit.w.h) scrflaga.b.h |= 4; /* Line 405, Address: 0x1024cd8 */
    else scrflaga.b.h |= 8; /* Line 406, Address: 0x1024d20 */
  }
} /* Line 408, Address: 0x1024d34 */


void scrh_move() { /* Line 411, Address: 0x1024d50 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 414, Address: 0x1024d5c */
  if (!wD0) scra_hz = 0; /* Line 415, Address: 0x1024d9c */
  else if ((short)wD0 < 0) left_check(wD0); /* Line 416, Address: 0x1024db4 */
  else right_check(wD0); /* Line 417, Address: 0x1024de0 */
} /* Line 418, Address: 0x1024dec */


void right_check(unsigned short wD0) { /* Line 421, Address: 0x1024e00 */
  unsigned short wD1;

  if ((short)wD0 > 16) wD0 = 16; /* Line 424, Address: 0x1024e0c */
  wD0 += scra_h_posit.w.h; /* Line 425, Address: 0x1024e34 */
  if (scralim_right < (short)wD0) wD0 = scralim_right; /* Line 426, Address: 0x1024e4c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 427, Address: 0x1024e88 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 428, Address: 0x1024eac */
  scra_h_posit.w.h = wD0; /* Line 429, Address: 0x1024edc */
  scra_hz = wD1; /* Line 430, Address: 0x1024ee8 */
} /* Line 431, Address: 0x1024ef0 */


void left_check(unsigned short wD0) { /* Line 434, Address: 0x1024f00 */
  unsigned short wD1;

  if ((short)wD0 < -16) wD0 = 65520; /* Line 437, Address: 0x1024f0c */
  wD0 += scra_h_posit.w.h; /* Line 438, Address: 0x1024f34 */
  if (scralim_left > (short)wD0) wD0 = scralim_left; /* Line 439, Address: 0x1024f4c */
  wD1 = wD0 - scra_h_posit.w.h; /* Line 440, Address: 0x1024f88 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 441, Address: 0x1024fac */
  scra_h_posit.w.h = wD0; /* Line 442, Address: 0x1024fdc */
  scra_hz = wD1; /* Line 443, Address: 0x1024fe8 */
} /* Line 444, Address: 0x1024ff0 */










void scroll_v() { /* Line 455, Address: 0x1025000 */
  short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 458, Address: 0x102500c */
  if (actwk[0].cddat & 4) wD0 -= 5; /* Line 459, Address: 0x1025040 */
  if (actwk[0].cddat & 2) { /* Line 460, Address: 0x1025064 */
    wD0 += 32; /* Line 461, Address: 0x102507c */
    if (wD0 < scra_vline) { /* Line 462, Address: 0x1025088 */
      wD0 -= scra_vline; /* Line 463, Address: 0x10250ac */
      sv_move_main2(wD0); /* Line 464, Address: 0x10250c0 */
      return; /* Line 465, Address: 0x10250cc */
    }
    if (wD0 >= scra_vline + 64) { /* Line 467, Address: 0x10250d4 */
      wD0 -= scra_vline + 64; /* Line 468, Address: 0x10250fc */
      sv_move_main2(wD0); /* Line 469, Address: 0x1025124 */
      return; /* Line 470, Address: 0x1025130 */
    }

    wD0 -= scra_vline + 64; /* Line 473, Address: 0x1025138 */
    if (!limmoveflag) goto label1; /* Line 474, Address: 0x1025160 */
    sv_move_sub2(); /* Line 475, Address: 0x1025170 */
    return; /* Line 476, Address: 0x1025178 */
  }



  if ((wD0 -= scra_vline) != 0) { /* Line 481, Address: 0x1025180 */
    sv_move_main(wD0); /* Line 482, Address: 0x10251ac */
    return; /* Line 483, Address: 0x10251b8 */
  }
  if (limmoveflag) { /* Line 485, Address: 0x10251c0 */
    sv_move_sub2(); /* Line 486, Address: 0x10251d0 */
    return; /* Line 487, Address: 0x10251d8 */
  }
label1:
  scra_vz = 0; /* Line 490, Address: 0x10251e0 */
} /* Line 491, Address: 0x10251e8 */


void sv_move_main(short wD0) { /* Line 494, Address: 0x1025200 */
  short wD1;

  if (scra_vline != 96) sv_move_main1(wD0); /* Line 497, Address: 0x1025210 */
  else {
    wD1 = actwk[0].mspeed.w; /* Line 499, Address: 0x1025240 */
    if (wD1 < 0) wD1 *= -1; /* Line 500, Address: 0x1025250 */
    if (wD1 >= 2048) { /* Line 501, Address: 0x102526c */
      sv_move_main2(wD0); /* Line 502, Address: 0x1025280 */
      return; /* Line 503, Address: 0x102528c */
    }
    if (wD0 > 6) sv_move_plus(1536); /* Line 505, Address: 0x1025294 */
    else if (wD0 < -6) sv_move_minus(1536); /* Line 506, Address: 0x10252c0 */
    else sv_move_sub(wD0); /* Line 507, Address: 0x10252ec */
  }
} /* Line 509, Address: 0x10252f8 */


void sv_move_main1(short wD0) { /* Line 512, Address: 0x1025310 */
  if (wD0 > 2) sv_move_plus(512); /* Line 513, Address: 0x102531c */
  else if (wD0 < -2) sv_move_minus(512); /* Line 514, Address: 0x1025348 */
  else sv_move_sub(wD0); /* Line 515, Address: 0x1025374 */
} /* Line 516, Address: 0x1025380 */


void sv_move_main2(short wD0) { /* Line 519, Address: 0x1025390 */
  if ((short)wD0 > 16) sv_move_plus(4096); /* Line 520, Address: 0x102539c */
  else if ((short)wD0 < -16) sv_move_minus(4096); /* Line 521, Address: 0x10253c8 */
  else sv_move_sub(wD0); /* Line 522, Address: 0x10253f4 */
} /* Line 523, Address: 0x1025400 */


void sv_move_sub2() { /* Line 526, Address: 0x1025410 */
  limmoveflag = 0; /* Line 527, Address: 0x1025418 */
  sv_move_sub(0); /* Line 528, Address: 0x1025420 */
} /* Line 529, Address: 0x102542c */


void sv_move_sub(short wD0) { /* Line 532, Address: 0x1025440 */
  int_union lD1;

  lD1.w.h = 0; /* Line 535, Address: 0x102544c */
  lD1.w.l = wD0 + scra_v_posit.w.h; /* Line 536, Address: 0x1025450 */
  if (wD0 < 0) scrv_up_ch(lD1); /* Line 537, Address: 0x102547c */
  else scrv_down_ch(lD1); /* Line 538, Address: 0x10254a4 */
} /* Line 539, Address: 0x10254b0 */


void sv_move_minus(short wD1) { /* Line 542, Address: 0x10254c0 */
  int_union lD1;
  short wk;

  lD1.l = (-wD1 << 8) + scra_v_posit.l; /* Line 546, Address: 0x10254d0 */

  wk = lD1.w.h; /* Line 548, Address: 0x10254f4 */
  lD1.w.h = lD1.w.l; /* Line 549, Address: 0x1025500 */
  lD1.w.l = wk; /* Line 550, Address: 0x1025508 */
  scrv_up_ch(lD1); /* Line 551, Address: 0x102550c */
} /* Line 552, Address: 0x1025518 */


void scrv_up_ch(int_union lD1) { /* Line 555, Address: 0x1025530 */
  if (lD1.w.l <= scralim_up) { /* Line 556, Address: 0x102553c */
    if (lD1.w.l > -256) { /* Line 557, Address: 0x1025564 */
      lD1.w.l = scralim_up; /* Line 558, Address: 0x102557c */
    } /* Line 559, Address: 0x1025588 */
    else {
      lD1.w.l &= 2047; /* Line 561, Address: 0x1025590 */
      actwk[0].yposi.w.h &= 2047; /* Line 562, Address: 0x102559c */
      scra_v_posit.w.h &= 2047; /* Line 563, Address: 0x10255b0 */
      scrb_v_posit.w.h &= 1023; /* Line 564, Address: 0x10255c4 */
    }
  }
  scrv_move(lD1); /* Line 567, Address: 0x10255d8 */
} /* Line 568, Address: 0x10255e4 */


void sv_move_plus(short wD1) { /* Line 571, Address: 0x1025600 */
  int_union lD1;
  short wk;

  lD1.l = (wD1 << 8) + scra_v_posit.l; /* Line 575, Address: 0x1025610 */

  wk = lD1.w.h; /* Line 577, Address: 0x1025630 */
  lD1.w.h = lD1.w.l; /* Line 578, Address: 0x102563c */
  lD1.w.l = wk; /* Line 579, Address: 0x1025644 */
  scrv_down_ch(lD1); /* Line 580, Address: 0x1025648 */
} /* Line 581, Address: 0x1025654 */


void scrv_down_ch(int_union lD1) { /* Line 584, Address: 0x1025670 */
  if (lD1.w.l >= scralim_down) { /* Line 585, Address: 0x102567c */
    if ((lD1.w.l += -2048) < 0) { /* Line 586, Address: 0x10256a4 */
      lD1.w.l = scralim_down; /* Line 587, Address: 0x10256c8 */
    } /* Line 588, Address: 0x10256d4 */
    else {
      actwk[0].yposi.w.h &= 2047; /* Line 590, Address: 0x10256dc */
      scra_v_posit.w.h -= 2048; /* Line 591, Address: 0x10256f0 */
      scrb_v_posit.w.h &= 1023; /* Line 592, Address: 0x1025704 */
    }
  }
  scrv_move(lD1); /* Line 595, Address: 0x1025718 */
} /* Line 596, Address: 0x1025724 */


void scrv_move(int_union lD1) { /* Line 599, Address: 0x1025740 */
  short wD4, wk;
  uint_union dwk;

  wD4 = scra_v_posit.w.h; /* Line 603, Address: 0x1025750 */

  wk = lD1.w.h; /* Line 605, Address: 0x1025760 */
  lD1.w.h = lD1.w.l; /* Line 606, Address: 0x102576c */
  lD1.w.l = wk; /* Line 607, Address: 0x1025774 */

  dwk.l = lD1.l - scra_v_posit.l; /* Line 609, Address: 0x1025778 */
  dwk.l = (dwk.l >> 8) | (dwk.l << 24); /* Line 610, Address: 0x102578c */
  scra_vz = dwk.w.l; /* Line 611, Address: 0x10257a4 */

  scra_v_posit.l = lD1.l; /* Line 613, Address: 0x10257b0 */

  wk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 615, Address: 0x10257bc */
  if (!wk) { /* Line 616, Address: 0x10257f8 */
    scra_v_count ^= 16; /* Line 617, Address: 0x1025800 */
    wk = scra_v_posit.w.h - wD4; /* Line 618, Address: 0x1025814 */
    if (wk < 0) scrflaga.b.h |= 1; /* Line 619, Address: 0x1025840 */
    else scrflaga.b.h |= 2; /* Line 620, Address: 0x102586c */
  }
} /* Line 622, Address: 0x1025880 */











void scrollb_hv(int lD4, int lD5) { /* Line 634, Address: 0x10258a0 */
  int lD0, lD1;
  int_union lD2;

  lD0 = scrb_h_posit.l; /* Line 638, Address: 0x10258b4 */
  lD2.l = scrb_h_posit.l = lD1 = lD0 + lD4; /* Line 639, Address: 0x10258bc */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_h_count) == 0) { /* Line 640, Address: 0x10258d0 */
    scrb_h_count ^= 16; /* Line 641, Address: 0x1025900 */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 4; /* Line 642, Address: 0x1025914 */
    else scrflagb.b.h |= 8; /* Line 643, Address: 0x102593c */
  }
  lD0 = scrb_v_posit.l; /* Line 645, Address: 0x1025950 */
  lD2.l = scrb_v_posit.l = lD1 = lD0 + lD5; /* Line 646, Address: 0x1025958 */
  if (((unsigned char)(lD2.w.h & 16) ^ scrb_v_count) == 0) { /* Line 647, Address: 0x102596c */
    scrb_v_count ^= 16; /* Line 648, Address: 0x102599c */
    if (lD1 - lD0 < 0) scrflagb.b.h |= 1; /* Line 649, Address: 0x10259b0 */
    else scrflagb.b.h |= 2; /* Line 650, Address: 0x10259d8 */
  }
} /* Line 652, Address: 0x10259ec */









































































void scrollc_h(int lD4, int flagc) { /* Line 726, Address: 0x1025a00 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 730, Address: 0x1025a10 */
  lD0.l = lD2.l + lD4; /* Line 731, Address: 0x1025a1c */
  scrc_h_posit.l = lD0.l; /* Line 732, Address: 0x1025a2c */

  lD1.w.h = lD0.w.l; /* Line 734, Address: 0x1025a38 */
  lD1.w.l = lD0.w.h; /* Line 735, Address: 0x1025a40 */
  lD1.w.l &= 16; /* Line 736, Address: 0x1025a48 */

  bD3 = scrc_h_count; /* Line 738, Address: 0x1025a54 */
  lD1.b.b4 ^= bD3; /* Line 739, Address: 0x1025a60 */
  if (!lD1.b.b4) { /* Line 740, Address: 0x1025a74 */




    scrc_h_count ^= 16; /* Line 745, Address: 0x1025a80 */
    lD0.l -= lD2.l; /* Line 746, Address: 0x1025a94 */
    if ((long int)lD0.l < 0) scrflagc.b.h |= flagc; /* Line 747, Address: 0x1025aa4 */
    else scrflagc.b.h |= flagc * 2; /* Line 748, Address: 0x1025adc */
  }
} /* Line 750, Address: 0x1025afc */











void scrollz_h(int lD4, int flagz) { /* Line 762, Address: 0x1025b10 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 766, Address: 0x1025b20 */
  lD0.l = lD2.l + lD4; /* Line 767, Address: 0x1025b2c */
  scrz_h_posit.l = lD0.l; /* Line 768, Address: 0x1025b3c */

  lD1.w.h = lD0.w.l; /* Line 770, Address: 0x1025b48 */
  lD1.w.l = lD0.w.h; /* Line 771, Address: 0x1025b50 */
  lD1.w.l &= 16; /* Line 772, Address: 0x1025b58 */

  bD3 = scrz_h_count; /* Line 774, Address: 0x1025b64 */
  lD1.b.b4 ^= bD3; /* Line 775, Address: 0x1025b70 */
  if (!lD1.b.b4) { /* Line 776, Address: 0x1025b84 */




    scrz_h_count ^= 16; /* Line 781, Address: 0x1025b90 */
    lD0.l -= lD2.l; /* Line 782, Address: 0x1025ba4 */
    if (lD0.l < 0) scrflagz.b.h |= flagz; /* Line 783, Address: 0x1025bb4 */
    else scrflagz.b.h |= flagz * 2; /* Line 784, Address: 0x1025be4 */
  }
} /* Line 786, Address: 0x1025c04 */










void scrollwrtadva() { /* Line 797, Address: 0x1025c20 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  pScrFlag = &scrflagb.b.h; /* Line 803, Address: 0x1025c3c */
  wH_posiw = scrb_h_posit.w.h; /* Line 804, Address: 0x1025c44 */
  wV_posiw = scrb_v_posit.w.h; /* Line 805, Address: 0x1025c50 */
  pMapWk = (unsigned char*)mapwkb; /* Line 806, Address: 0x1025c5c */
  VramBase = 24576; /* Line 807, Address: 0x1025c64 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 808, Address: 0x1025c68 */





} /* Line 814, Address: 0x1025c7c */










void scrollwrt() { /* Line 825, Address: 0x1025ca0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  pScrFlag = &scrflagbw.b.h; /* Line 834, Address: 0x1025cc0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 835, Address: 0x1025cc8 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 836, Address: 0x1025cd4 */
  pMapWk = (unsigned char*)mapwkb; /* Line 837, Address: 0x1025ce0 */
  VramBase = 24576; /* Line 838, Address: 0x1025ce8 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 839, Address: 0x1025cec */











  pScrFlag = &scrflagaw.b.h; /* Line 851, Address: 0x1025d00 */
  wH_posiw = scra_h_posiw.w.h; /* Line 852, Address: 0x1025d08 */
  wV_posiw = scra_v_posiw.w.h; /* Line 853, Address: 0x1025d14 */
  pMapWk = (unsigned char*)mapwka; /* Line 854, Address: 0x1025d20 */
  VramBase = 16384; /* Line 855, Address: 0x1025d28 */

  if (*pScrFlag) { /* Line 857, Address: 0x1025d2c */
    if (*pScrFlag & 1) { /* Line 858, Address: 0x1025d38 */
      *pScrFlag &= 254; /* Line 859, Address: 0x1025d4c */

      lD4.l = -16; /* Line 861, Address: 0x1025d58 */
      wD5 = 65520; /* Line 862, Address: 0x1025d60 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 863, Address: 0x1025d68 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 864, Address: 0x1025d88 */
    }
    if (*pScrFlag & 2) { /* Line 866, Address: 0x1025db4 */
      *pScrFlag &= 253; /* Line 867, Address: 0x1025dc8 */

      lD4.l = 224; /* Line 869, Address: 0x1025dd4 */
      wD5 = 65520; /* Line 870, Address: 0x1025ddc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 871, Address: 0x1025de4 */
      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 872, Address: 0x1025e04 */
    }
    if (*pScrFlag & 4) { /* Line 874, Address: 0x1025e30 */
      *pScrFlag &= 251; /* Line 875, Address: 0x1025e44 */

      lD4.l = -16; /* Line 877, Address: 0x1025e50 */
      wD5 = 65520; /* Line 878, Address: 0x1025e58 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 879, Address: 0x1025e60 */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 880, Address: 0x1025e80 */
    }
    if (*pScrFlag & 8) { /* Line 882, Address: 0x1025eac */
      *pScrFlag &= 247; /* Line 883, Address: 0x1025ec0 */

      lD4.l = -16; /* Line 885, Address: 0x1025ecc */
      wD5 = 320; /* Line 886, Address: 0x1025ed4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 887, Address: 0x1025edc */
      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 888, Address: 0x1025efc */
    }
  }
} /* Line 891, Address: 0x1025f28 */













void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 905, Address: 0x1025f50 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 916, Address: 0x1025f7c */

  if (*pScrFlag & 1) { /* Line 918, Address: 0x1025f84 */
    *pScrFlag &= 254; /* Line 919, Address: 0x1025f9c */
  } /* Line 920, Address: 0x1025fb0 */
  else {
    *pScrFlag &= 254; /* Line 922, Address: 0x1025fb8 */

    if (*pScrFlag & 2) { /* Line 924, Address: 0x1025fcc */
      *pScrFlag &= 253; /* Line 925, Address: 0x1025fe4 */
      lD4.w.l = 224; /* Line 926, Address: 0x1025ff8 */
    } /* Line 927, Address: 0x1026000 */
    else {
      *pScrFlag &= 253; /* Line 929, Address: 0x1026008 */
      goto label1; /* Line 930, Address: 0x102601c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 935, Address: 0x1026024 */
  wD0 &= 127; /* Line 936, Address: 0x1026074 */
  wD0 = z11cwrttbl[wD0 + 1]; /* Line 937, Address: 0x102607c */
  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 938, Address: 0x102609c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 939, Address: 0x10260bc */
  if (wD0 != 0) { /* Line 940, Address: 0x10260e0 */
    wD5 = 65520; /* Line 941, Address: 0x10260ec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 942, Address: 0x10260f4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 944, Address: 0x1026114 */



  } /* Line 948, Address: 0x1026140 */
  else {

    wD5 = 0; /* Line 951, Address: 0x1026148 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 952, Address: 0x102614c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 956, Address: 0x102616c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 963, Address: 0x1026198 */






    lD4.l = -16; /* Line 970, Address: 0x10261ac */
    wD5 = 65520; /* Line 971, Address: 0x10261b4 */
    if (*pScrFlag & 168) { /* Line 972, Address: 0x10261bc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 973, Address: 0x10261d4 */
      wD5 = 320; /* Line 974, Address: 0x10261f4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 978, Address: 0x10261fc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 980, Address: 0x102622c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 981, Address: 0x1026238 */



    for (i = 0; i < 16; ++i) { /* Line 985, Address: 0x1026248 */
      wD0 = z11cwrttbl[WrtTblCnt++]; /* Line 986, Address: 0x1026254 */
      if (wD0 != 0) { /* Line 987, Address: 0x1026274 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 988, Address: 0x1026280 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 989, Address: 0x10262ac */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 990, Address: 0x10262cc */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 992, Address: 0x10262f0 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 995, Address: 0x1026314 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 997, Address: 0x1026334 */
        }
      }
      lD4.w.l += 16; /* Line 1000, Address: 0x1026348 */
    } /* Line 1001, Address: 0x1026354 */
    *pScrFlag = 0; /* Line 1002, Address: 0x1026364 */
  }
} /* Line 1004, Address: 0x102636c */


























void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1031, Address: 0x10263a0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1044, Address: 0x10263c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1047, Address: 0x10263e8 */
    pTilePoint->x += 2; /* Line 1048, Address: 0x10263fc */
    if (pTilePoint->x >= 64) { /* Line 1049, Address: 0x1026410 */
      pTilePoint->x -= 64; /* Line 1050, Address: 0x1026424 */
    }
    xOffs += 16; /* Line 1052, Address: 0x1026438 */
  } while (--lpcnt >= 0); /* Line 1053, Address: 0x1026444 */
} /* Line 1054, Address: 0x1026458 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1058, Address: 0x1026470 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1062, Address: 0x1026498 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1065, Address: 0x10264b8 */
    pTilePoint->x += 2; /* Line 1066, Address: 0x10264cc */
    if (pTilePoint->x >= 64) { /* Line 1067, Address: 0x10264e0 */
      pTilePoint->x -= 64; /* Line 1068, Address: 0x10264f4 */
    }
    xOffs += 16; /* Line 1070, Address: 0x1026508 */
  } while (--lpcnt >= 0); /* Line 1071, Address: 0x1026514 */
} /* Line 1072, Address: 0x1026528 */















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1088, Address: 0x1026540 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1092, Address: 0x1026568 */
    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1093, Address: 0x1026588 */
    pTilePoint->y += 2; /* Line 1094, Address: 0x102659c */
    if (pTilePoint->y >= 32) pTilePoint->y -= 32; /* Line 1095, Address: 0x10265ac */
    yOffs += 16; /* Line 1096, Address: 0x10265d0 */
  } while (--lpcnt >= 0); /* Line 1097, Address: 0x10265dc */
} /* Line 1098, Address: 0x10265f0 */

















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1116, Address: 0x1026600 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) base = 1; /* Line 1122, Address: 0x1026634 */
  else if (VramBase == 16384) base = 0; /* Line 1123, Address: 0x1026650 */
  x = pTilePoint->x; /* Line 1124, Address: 0x1026664 */
  y = pTilePoint->y; /* Line 1125, Address: 0x102666c */

  frip = BlkIndex & 6144; /* Line 1127, Address: 0x1026674 */
  BlkIndex &= 1023; /* Line 1128, Address: 0x102667c */
  if (frip == 6144) { /* Line 1129, Address: 0x1026688 */
    p0 = 3; /* Line 1130, Address: 0x1026694 */
    p1 = 2; /* Line 1131, Address: 0x1026698 */
    p2 = 1; /* Line 1132, Address: 0x102669c */
    p3 = 0; /* Line 1133, Address: 0x10266a0 */
  } /* Line 1134, Address: 0x10266a4 */
  else if (frip & 4096) { /* Line 1135, Address: 0x10266ac */
    p0 = 2; /* Line 1136, Address: 0x10266b8 */
    p1 = 3; /* Line 1137, Address: 0x10266bc */
    p2 = 0; /* Line 1138, Address: 0x10266c0 */
    p3 = 1; /* Line 1139, Address: 0x10266c4 */
  } /* Line 1140, Address: 0x10266c8 */
  else if (frip & 2048) { /* Line 1141, Address: 0x10266d0 */
    p0 = 1; /* Line 1142, Address: 0x10266dc */
    p1 = 0; /* Line 1143, Address: 0x10266e0 */
    p2 = 3; /* Line 1144, Address: 0x10266e4 */
    p3 = 2; /* Line 1145, Address: 0x10266e8 */
  } /* Line 1146, Address: 0x10266ec */
  else {
    p0 = 0; /* Line 1148, Address: 0x10266f4 */
    p1 = 1; /* Line 1149, Address: 0x10266f8 */
    p2 = 2; /* Line 1150, Address: 0x10266fc */
    p3 = 3; /* Line 1151, Address: 0x1026700 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1154, Address: 0x1026704 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1155, Address: 0x1026748 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1156, Address: 0x102678c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1157, Address: 0x10267d0 */
} /* Line 1158, Address: 0x1026814 */


















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1177, Address: 0x1026850 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1178, Address: 0x1026870 */
} /* Line 1179, Address: 0x1026890 */


int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1182, Address: 0x10268a0 */
  wH_posiw = 0; /* Line 1183, Address: 0x10268c0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1184, Address: 0x10268c4 */
} /* Line 1185, Address: 0x10268e4 */


int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1188, Address: 0x1026900 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1194, Address: 0x1026930 */
  yOffs += wV_posiw; /* Line 1195, Address: 0x1026940 */


  if ((short)xOffs < 0) xOffs = 0; /* Line 1198, Address: 0x1026950 */
  if ((short)yOffs < 0) yOffs = 0; /* Line 1199, Address: 0x1026970 */
  if ((short)xOffs >= 16384) xOffs = 16383; /* Line 1200, Address: 0x1026990 */
  if ((short)yOffs >= 2048) yOffs = 2047; /* Line 1201, Address: 0x10269b8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1202, Address: 0x10269e0 */
  if (i < 0) i = 0; /* Line 1203, Address: 0x1026a28 */

  ScreenNo = pMapWk[i] & 127; /* Line 1205, Address: 0x1026a34 */

  if (ScreenNo) { /* Line 1207, Address: 0x1026a50 */
    xOffs &= 32767; /* Line 1208, Address: 0x1026a58 */
    yOffs &= 32767; /* Line 1209, Address: 0x1026a64 */

    xBlk = xOffs; /* Line 1211, Address: 0x1026a70 */
    xBlk %= 256; /* Line 1212, Address: 0x1026a78 */
    xBlk /= 16; /* Line 1213, Address: 0x1026a98 */
    yBlk = yOffs; /* Line 1214, Address: 0x1026ab4 */
    yBlk %= 256; /* Line 1215, Address: 0x1026abc */
    yBlk /= 16; /* Line 1216, Address: 0x1026adc */

    lpw = pmapwk; /* Line 1218, Address: 0x1026af8 */
    lpw += xBlk; /* Line 1219, Address: 0x1026b00 */
    lpw += yBlk * 16; /* Line 1220, Address: 0x1026b08 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1221, Address: 0x1026b14 */
    *pIndex = *lpw; /* Line 1222, Address: 0x1026b2c */

    return 1; /* Line 1224, Address: 0x1026b3c */
  }
  *pIndex = 0; /* Line 1226, Address: 0x1026b48 */
  return 0; /* Line 1227, Address: 0x1026b50 */
} /* Line 1228, Address: 0x1026b54 */















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1244, Address: 0x1026b80 */
  int xBlk, yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;

  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1249, Address: 0x1026ba8 */
  if (ScreenNo) { /* Line 1250, Address: 0x1026c0c */
    xBlk = xOffs; /* Line 1251, Address: 0x1026c14 */
    xBlk %= 256; /* Line 1252, Address: 0x1026c1c */
    xBlk /= 16; /* Line 1253, Address: 0x1026c3c */
    yBlk = yOffs; /* Line 1254, Address: 0x1026c58 */
    yBlk %= 256; /* Line 1255, Address: 0x1026c60 */
    yBlk /= 16; /* Line 1256, Address: 0x1026c80 */

    lpw = pmapwk; /* Line 1258, Address: 0x1026c9c */
    lpw += xBlk; /* Line 1259, Address: 0x1026ca4 */
    lpw += yBlk * 16; /* Line 1260, Address: 0x1026cac */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1261, Address: 0x1026cb8 */
    *ppBlockNo = lpw; /* Line 1262, Address: 0x1026cd0 */
    *pIndex = *lpw; /* Line 1263, Address: 0x1026cd8 */

    return 1; /* Line 1265, Address: 0x1026ce8 */
  }
  *pIndex = 0; /* Line 1267, Address: 0x1026cf4 */
  return 0; /* Line 1268, Address: 0x1026cfc */
} /* Line 1269, Address: 0x1026d00 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1283, Address: 0x1026d20 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1290, Address: 0x1026d3c */
  pMapWk = (unsigned char*)mapwka; /* Line 1291, Address: 0x1026d40 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1292, Address: 0x1026d48 */
    *pBlockIndex = BlockNo; /* Line 1293, Address: 0x1026d6c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1294, Address: 0x1026d78 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1295, Address: 0x1026d90 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1296, Address: 0x1026da4 */
    }
  }
} /* Line 1299, Address: 0x1026dbc */











int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1311, Address: 0x1026de0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1312, Address: 0x1026dec */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1313, Address: 0x1026e18 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1314, Address: 0x1026e64 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) return 0; /* Line 1315, Address: 0x1026e90 */
      }
    }
  }
  return 1; /* Line 1319, Address: 0x1026ee8 */
} /* Line 1320, Address: 0x1026eec */














void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1335, Address: 0x1026f00 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1336, Address: 0x1026f1c */
} /* Line 1337, Address: 0x1026f38 */


void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1340, Address: 0x1026f50 */
  wH_posiw = 0; /* Line 1341, Address: 0x1026f6c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1342, Address: 0x1026f70 */
} /* Line 1343, Address: 0x1026f8c */


void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1346, Address: 0x1026fa0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1347, Address: 0x1026fb4 */
} /* Line 1348, Address: 0x1026fd0 */


void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1351, Address: 0x1026fe0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1352, Address: 0x1026ffc */
} /* Line 1353, Address: 0x1027018 */


void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1356, Address: 0x1027030 */
  xOffs += wH_posiw; /* Line 1357, Address: 0x1027048 */
  yOffs += wV_posiw; /* Line 1358, Address: 0x1027058 */
  yOffs &= 240; /* Line 1359, Address: 0x1027068 */
  xOffs &= 496; /* Line 1360, Address: 0x1027074 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1362, Address: 0x1027080 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1363, Address: 0x10270ac */

} /* Line 1365, Address: 0x10270d8 */













void mapwrt() { /* Line 1379, Address: 0x10270f0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1384, Address: 0x1027108 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1385, Address: 0x1027114 */
  pMapWk = (unsigned char*)mapwka; /* Line 1386, Address: 0x1027120 */
  VramBase = 16384; /* Line 1387, Address: 0x1027128 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1388, Address: 0x102712c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1392, Address: 0x1027144 */
  VramBase = 24576; /* Line 1393, Address: 0x102714c */
  mapwrt_z11c(pMapWk, VramBase); /* Line 1394, Address: 0x1027150 */
} /* Line 1395, Address: 0x1027160 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1398, Address: 0x1027180 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1399, Address: 0x1027198 */
} /* Line 1400, Address: 0x10271b8 */


void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1403, Address: 0x10271d0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1407, Address: 0x10271f0 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1408, Address: 0x102720c */
    wD4 += 16; /* Line 1409, Address: 0x1027234 */
  } while ((short)--wD6 >= 0); /* Line 1410, Address: 0x1027240 */
} /* Line 1411, Address: 0x1027268 */


void mapwrt_z11c(unsigned char* pMapWk, int VramBase) { /* Line 1414, Address: 0x1027280 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1417, Address: 0x102729c */
  wD6 = 15; /* Line 1418, Address: 0x10272a4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1421, Address: 0x10272ac */
    mapwrt_sub(z11cwrttbl, wD0, wD4, pMapWk, VramBase); /* Line 1422, Address: 0x10272d0 */
    wD4 += 16; /* Line 1423, Address: 0x10272f0 */
  } while ((short)--wD6 >= 0); /* Line 1424, Address: 0x10272f8 */
} /* Line 1425, Address: 0x102731c */















void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1441, Address: 0x1027340 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1446, Address: 0x1027368 */
  wD0 = pWrttbl[wD0]; /* Line 1447, Address: 0x1027378 */
  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1448, Address: 0x1027394 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1449, Address: 0x10273b8 */
  if (wD0) { /* Line 1450, Address: 0x10273e0 */
    wD5 = 65520; /* Line 1451, Address: 0x10273ec */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1452, Address: 0x10273f4 */
    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1453, Address: 0x1027410 */
  } /* Line 1454, Address: 0x1027438 */
  else {
    wD5 = 0; /* Line 1456, Address: 0x1027440 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1457, Address: 0x1027444 */
    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1458, Address: 0x1027460 */
  }
} /* Line 1460, Address: 0x1027488 */










void mapinit() { /* Line 1471, Address: 0x10274b0 */

  colorset2(mapinittbl.colorno2); /* Line 1473, Address: 0x10274b8 */
  colorset(mapinittbl.colorno2); /* Line 1474, Address: 0x10274cc */

  if (plflag) enecginit(); /* Line 1476, Address: 0x10274e0 */
  if (play_start & 2) divdevset(); /* Line 1477, Address: 0x10274f8 */
} /* Line 1478, Address: 0x1027518 */
