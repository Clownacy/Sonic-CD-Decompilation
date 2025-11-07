#include "..\EQU.H"
#include "SCR61A.H"
#include "..\ETC.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL6C.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void z61aline(short** ppHscw);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_v(short yPos);
static void scrollb_h(int xoffs, int flgbit);
static void scrollc_h(int xoffs, int flgbit);
static void scrollz_h(int xoffs, int flgbit);
static void scroll_h(void);
static void scrh_move(void);
static void scroll_v(void);
static void sv_move_main(short yPos);
static void sv_move_main2(short yPos);
static void sv_move_sub(short yPos);
static void sv_move_sub2(void);
static void sv_move_minus(short speed);
static void scrv_up_ch(int_union lSpd);
static void sv_move_plus(short sSpd);
static void scrv_down_ch(int_union lSpd);
static void scrv_move(int_union lSpd);

static unsigned char z81awrttbl[49] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4
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
short scr_dir_tbl[6] = { 4, 0, 8855, 0, 1808, 96 };
short endplpositbl[8][2] = {
  {   80,  944 },
  { 3744, 1132 },
  { 5968,  189 },
  { 2560, 1580 },
  { 2992,   76 },
  { 5488,  364 },
  {  432, 1836 },
  { 5120,  684 }
};
short playpositbl[1][2] = { { 48, 1196 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;








































































sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 146, Address: 0x102ba50 */
    return &actwk[0]; /* Line 147, Address: 0x102ba64 */
  else
    return &actwk[1]; /* Line 149, Address: 0x102ba74 */

} /* Line 151, Address: 0x102ba7c */





































void scr_set(void) { /* Line 189, Address: 0x102ba90 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 192, Address: 0x102ba9c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 193, Address: 0x102bab0 */
  scr_timer.b.h = 0; /* Line 194, Address: 0x102bac4 */

  pScrTbl = scr_dir_tbl; /* Line 196, Address: 0x102bacc */
  scrar_no = *pScrTbl; /* Line 197, Address: 0x102bad4 */
  ++pScrTbl; /* Line 198, Address: 0x102bae0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 199, Address: 0x102bae4 */
  ++pScrTbl; /* Line 200, Address: 0x102baf8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 201, Address: 0x102bafc */
  ++pScrTbl; /* Line 202, Address: 0x102bb10 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 203, Address: 0x102bb14 */
  ++pScrTbl; /* Line 204, Address: 0x102bb28 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 205, Address: 0x102bb2c */
  scra_h_keep = *pScrTbl + 576; /* Line 206, Address: 0x102bb40 */
  ++pScrTbl; /* Line 207, Address: 0x102bb60 */
  scra_h_count = 16; /* Line 208, Address: 0x102bb64 */
  scra_v_count = 16; /* Line 209, Address: 0x102bb70 */

  scra_vline = *pScrTbl; /* Line 211, Address: 0x102bb7c */
  scra_hline = 160; /* Line 212, Address: 0x102bb88 */

  playposiset(); /* Line 214, Address: 0x102bb94 */
} /* Line 215, Address: 0x102bb9c */
















































static void playposiset(void) { /* Line 264, Address: 0x102bbb0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 267, Address: 0x102bbc4 */
    playload(); /* Line 268, Address: 0x102bbd4 */
    xwk = actwk[0].xposi.w.h; /* Line 269, Address: 0x102bbdc */

    if (actwk[0].yposi.w.h > 0) { /* Line 271, Address: 0x102bbec */
      ywk = actwk[0].yposi.w.h; /* Line 272, Address: 0x102bc04 */
    } else { /* Line 273, Address: 0x102bc14 */
      ywk = 0; /* Line 274, Address: 0x102bc1c */
    }
  } /* Line 276, Address: 0x102bc20 */
  else {
    if (demoflag.w & -32768) { /* Line 278, Address: 0x102bc28 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 279, Address: 0x102bc48 */
    } /* Line 280, Address: 0x102bc6c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 282, Address: 0x102bc74 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 286, Address: 0x102bc94 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 287, Address: 0x102bca8 */
  }


  if (xwk > 160) { /* Line 291, Address: 0x102bcbc */
    xwk -= 160; /* Line 292, Address: 0x102bcd0 */
  } else { /* Line 293, Address: 0x102bcdc */
    xwk = 0; /* Line 294, Address: 0x102bce4 */
  }


  if (xwk > scralim_right) { /* Line 298, Address: 0x102bce8 */
    xwk = scralim_right; /* Line 299, Address: 0x102bd0c */
  }


  scra_h_posit.w.h = xwk; /* Line 303, Address: 0x102bd1c */

  if (ywk > 96) { /* Line 305, Address: 0x102bd24 */
    ywk -= 96; /* Line 306, Address: 0x102bd38 */
  } else { /* Line 307, Address: 0x102bd44 */
    ywk = 0; /* Line 308, Address: 0x102bd4c */
  }


  if (ywk > scralim_down) { /* Line 312, Address: 0x102bd50 */
    ywk = scralim_down; /* Line 313, Address: 0x102bd74 */
  }


  scra_v_posit.w.h = ywk; /* Line 317, Address: 0x102bd84 */

  scrbinit(xwk, ywk); /* Line 319, Address: 0x102bd8c */


  loopmapno = playmapnotbl[0]; /* Line 322, Address: 0x102bd9c */
  loopmapno2 = playmapnotbl[1]; /* Line 323, Address: 0x102bdac */
  ballmapno = playmapnotbl[2]; /* Line 324, Address: 0x102bdbc */
  ballmapno2 = playmapnotbl[3]; /* Line 325, Address: 0x102bdcc */
} /* Line 326, Address: 0x102bddc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 347, Address: 0x102be00 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 350, Address: 0x102be0c */
  lYwk.w.l = 0; /* Line 351, Address: 0x102be14 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 353, Address: 0x102be18 */
  scrb_v_posit.l = lYwk.l; /* Line 354, Address: 0x102be24 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 355, Address: 0x102be30 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 356, Address: 0x102be3c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 358, Address: 0x102be48 */
  scrc_h_posit.w.h = sXpos; /* Line 359, Address: 0x102be64 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 361, Address: 0x102be70 */
  scrz_h_posit.w.h = sXpos; /* Line 362, Address: 0x102be8c */

  sXpos = (unsigned short)sXpos >> 2; /* Line 364, Address: 0x102be98 */
  scrb_h_posit.w.h = sXpos * 3; /* Line 365, Address: 0x102beb4 */
} /* Line 366, Address: 0x102bed8 */















void scroll(void) { /* Line 382, Address: 0x102bef0 */
  int_union ldwk;
  int_union* pHscrbuf;
  int i;
  int lXwk;
  int lYwk;
  short sYnum;
  short* psHscr;
  short* psHscw;
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };
  static unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 };

  if (scroll_start.b.h) return; /* Line 394, Address: 0x102bf0c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 399, Address: 0x102bf1c */

  scrchk(); /* Line 401, Address: 0x102bf48 */

  scroll_h(); /* Line 403, Address: 0x102bf50 */
  scroll_v(); /* Line 404, Address: 0x102bf58 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 406, Address: 0x102bf60 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 407, Address: 0x102bf70 */


  lXwk = scra_hz << 6; /* Line 410, Address: 0x102bf80 */
  scrollz_h(lXwk, 6); /* Line 411, Address: 0x102bf94 */

  lXwk = scra_hz << 7; /* Line 413, Address: 0x102bfa4 */
  scrollc_h(lXwk, 4); /* Line 414, Address: 0x102bfb8 */

  lXwk = (scra_hz << 4) * 3; /* Line 416, Address: 0x102bfc8 */
  scrollb_h(lXwk, 2); /* Line 417, Address: 0x102bfe4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 419, Address: 0x102bff4 */


  scrollb_v(lYwk); /* Line 422, Address: 0x102c008 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 424, Address: 0x102c018 */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 426, Address: 0x102c040 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 427, Address: 0x102c078 */

  psHscw = hscrollwork; /* Line 429, Address: 0x102c08c */

  z61aline(&psHscw); /* Line 431, Address: 0x102c098 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 433, Address: 0x102c0a4 */
  for (i = 0; i < 24; ++i) { /* Line 434, Address: 0x102c0c4 */

    *psHscw++ = ldwk.w.l; /* Line 436, Address: 0x102c0d0 */
  } /* Line 437, Address: 0x102c0e4 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 439, Address: 0x102c0f4 */
  for (i = 0; i < 46; ++i) { /* Line 440, Address: 0x102c114 */

    *psHscw++ = ldwk.w.l; /* Line 442, Address: 0x102c120 */
  } /* Line 443, Address: 0x102c134 */

  pHscrbuf = lphscrollbuff; /* Line 445, Address: 0x102c144 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 446, Address: 0x102c150 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 447, Address: 0x102c180 */
  zonescrsetsub0(scrb_v_posit.w.h, 29, &pHscrbuf, psHscr); /* Line 448, Address: 0x102c1b0 */
} /* Line 449, Address: 0x102c1cc */













static void z61aline(short** ppHscw) { /* Line 463, Address: 0x102c1f0 */
  char z81ascrtbl[9] = { /* Line 464, Address: 0x102c214 */
    5, 3, 2, 2, 1, 1, 1, 1, 1
  };
  int i, j;
  short sXwk, radwk, sinwk, coswk, hwk;
  int lXwk;


  lXwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 472, Address: 0x102c240 */
  radwk = 0; /* Line 473, Address: 0x102c264 */
  sXwk = scrb_h_posit.w.h; /* Line 474, Address: 0x102c268 */

  *ppHscw += 26; /* Line 476, Address: 0x102c278 */

  for (i = 8; i >= 0; --i) { /* Line 478, Address: 0x102c28c */

    sinset(radwk, &sinwk, &coswk); /* Line 480, Address: 0x102c298 */
    hwk = -(sXwk + (short)((unsigned short)((256 - coswk) * lXwk) >> 8)); /* Line 481, Address: 0x102c2ac */
    for (j = z81ascrtbl[i]; j >= 0; --j) { /* Line 482, Address: 0x102c300 */

      --*ppHscw; /* Line 484, Address: 0x102c318 */
      **ppHscw = hwk; /* Line 485, Address: 0x102c32c */
    } /* Line 486, Address: 0x102c338 */

    radwk += 6; /* Line 488, Address: 0x102c344 */
  } /* Line 489, Address: 0x102c350 */

  *ppHscw += 26; /* Line 491, Address: 0x102c35c */
} /* Line 492, Address: 0x102c370 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 513, Address: 0x102c3a0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 517, Address: 0x102c3bc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 518, Address: 0x102c3c0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 520, Address: 0x102c3e0 */
    ldwk.w.l = *pHscrwk; /* Line 521, Address: 0x102c3fc */
    ++pHscrwk; /* Line 522, Address: 0x102c408 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 524, Address: 0x102c414 */
      (*pHscrbuf)->l = ldwk.l; /* Line 525, Address: 0x102c41c */
    } /* Line 526, Address: 0x102c42c */
  } /* Line 527, Address: 0x102c450 */
} /* Line 528, Address: 0x102c470 */









































































































static void scrollb_v(short yPos) { /* Line 634, Address: 0x102c490 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 637, Address: 0x102c4a0 */
  scrb_v_posit.w.h = yPos; /* Line 638, Address: 0x102c4b0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 639, Address: 0x102c4bc */

  if (!ywk) { /* Line 641, Address: 0x102c4f4 */
    scrb_v_count ^= 16; /* Line 642, Address: 0x102c4fc */
    if (yPos - ysv < 0) { /* Line 643, Address: 0x102c510 */
      scrflagb.b.h |= 1; /* Line 644, Address: 0x102c530 */
    } /* Line 645, Address: 0x102c544 */
    else {
      scrflagb.b.h |= 2; /* Line 647, Address: 0x102c54c */
    }
  }


} /* Line 652, Address: 0x102c560 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 670, Address: 0x102c580 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 674, Address: 0x102c594 */
  lXwk = lXsv + xoffs; /* Line 675, Address: 0x102c59c */
  scrb_h_posit.l = lXwk; /* Line 676, Address: 0x102c5a4 */
  ldXwk.l = lXwk; /* Line 677, Address: 0x102c5ac */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 678, Address: 0x102c5b0 */
  ldXwk.w.l &= 16; /* Line 679, Address: 0x102c5d4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 680, Address: 0x102c5e0 */

  if (!ldXwk.b.b4) { /* Line 682, Address: 0x102c5fc */
    scrb_h_count ^= 16; /* Line 683, Address: 0x102c608 */
    if (lXwk - lXsv < 0) { /* Line 684, Address: 0x102c61c */
      scrflagb.b.h |= 1 << flgbit; /* Line 685, Address: 0x102c628 */
    } /* Line 686, Address: 0x102c64c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 688, Address: 0x102c654 */
    }
  }


} /* Line 693, Address: 0x102c67c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 711, Address: 0x102c690 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 715, Address: 0x102c6a4 */
  lXwk = lXsv + xoffs; /* Line 716, Address: 0x102c6ac */
  scrc_h_posit.l = lXwk; /* Line 717, Address: 0x102c6b4 */
  ldXwk.l = lXwk; /* Line 718, Address: 0x102c6bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 719, Address: 0x102c6c0 */
  ldXwk.w.l &= 16; /* Line 720, Address: 0x102c6e4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 721, Address: 0x102c6f0 */

  if (!ldXwk.b.b4) { /* Line 723, Address: 0x102c70c */
    scrc_h_count ^= 16; /* Line 724, Address: 0x102c718 */
    if (lXwk - lXsv < 0) { /* Line 725, Address: 0x102c72c */
      scrflagc.b.h |= 1 << flgbit; /* Line 726, Address: 0x102c738 */
    } /* Line 727, Address: 0x102c75c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 729, Address: 0x102c764 */
    }
  }


} /* Line 734, Address: 0x102c78c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 752, Address: 0x102c7a0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 756, Address: 0x102c7b4 */
  lXwk = lXsv + xoffs; /* Line 757, Address: 0x102c7bc */
  scrz_h_posit.l = lXwk; /* Line 758, Address: 0x102c7c4 */
  ldXwk.l = lXwk; /* Line 759, Address: 0x102c7cc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 760, Address: 0x102c7d0 */
  ldXwk.w.l &= 16; /* Line 761, Address: 0x102c7f4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 762, Address: 0x102c800 */

  if (!ldXwk.b.b4) { /* Line 764, Address: 0x102c81c */
    scrz_h_count ^= 16; /* Line 765, Address: 0x102c828 */
    if (lXwk - lXsv < 0) { /* Line 766, Address: 0x102c83c */
      scrflagz.b.h |= 1 << flgbit; /* Line 767, Address: 0x102c848 */
    } /* Line 768, Address: 0x102c86c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 770, Address: 0x102c874 */
    }
  }


} /* Line 775, Address: 0x102c89c */














static void scroll_h(void) { /* Line 790, Address: 0x102c8b0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 794, Address: 0x102c8c0 */

  scrh_move(); /* Line 796, Address: 0x102c8d0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 797, Address: 0x102c8d8 */
  if (!bXwk) { /* Line 798, Address: 0x102c90c */
    scra_h_count ^= 16; /* Line 799, Address: 0x102c914 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 800, Address: 0x102c928 */
      scrflaga.b.h |= 4; /* Line 801, Address: 0x102c94c */
    } else { /* Line 802, Address: 0x102c960 */
      scrflaga.b.h |= 8; /* Line 803, Address: 0x102c968 */
    }
  }


} /* Line 808, Address: 0x102c97c */
















static void scrh_move(void) { /* Line 825, Address: 0x102c9a0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 828, Address: 0x102c9a8 */
  if (xwk == 0) { /* Line 829, Address: 0x102c9f0 */

    scra_hz = 0; /* Line 831, Address: 0x102ca00 */
    return; /* Line 832, Address: 0x102ca08 */
  } else if (xwk < 0) { /* Line 833, Address: 0x102ca10 */

    if (xwk < -16) { /* Line 835, Address: 0x102ca20 */
      xwk = -16; /* Line 836, Address: 0x102ca34 */
    }


    xwk += scra_h_posit.w.h; /* Line 840, Address: 0x102ca40 */
    if (xwk < scralim_left) { /* Line 841, Address: 0x102ca54 */
      xwk = scralim_left; /* Line 842, Address: 0x102ca78 */
    }
  } /* Line 844, Address: 0x102ca88 */
  else {
    if (xwk > 16) { /* Line 846, Address: 0x102ca90 */
      xwk = 16; /* Line 847, Address: 0x102caa4 */
    }


    xwk += scra_h_posit.w.h; /* Line 851, Address: 0x102cab0 */
    if (xwk > scralim_right) { /* Line 852, Address: 0x102cac4 */
      xwk = scralim_right; /* Line 853, Address: 0x102cae8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 858, Address: 0x102caf8 */
  scra_h_posit.w.h = xwk; /* Line 859, Address: 0x102cb28 */
} /* Line 860, Address: 0x102cb30 */














static void scroll_v(void) { /* Line 875, Address: 0x102cb40 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 878, Address: 0x102cb4c */
  if (actwk[0].cddat & 4) { /* Line 879, Address: 0x102cb80 */
    ywk -= 5; /* Line 880, Address: 0x102cb98 */
  }


  if (actwk[0].cddat & 2) { /* Line 884, Address: 0x102cba4 */
    ywk += 32; /* Line 885, Address: 0x102cbbc */
    if (ywk < scra_vline) { /* Line 886, Address: 0x102cbc8 */
      ywk -= scra_vline; /* Line 887, Address: 0x102cbec */
      sv_move_main2(ywk); /* Line 888, Address: 0x102cc00 */
      return; /* Line 889, Address: 0x102cc0c */
    } else if (ywk >= scra_vline + 64) { /* Line 890, Address: 0x102cc14 */
      ywk -= scra_vline + 64; /* Line 891, Address: 0x102cc3c */
      sv_move_main2(ywk); /* Line 892, Address: 0x102cc64 */
      return; /* Line 893, Address: 0x102cc70 */
    }
    ywk -= scra_vline + 64; /* Line 895, Address: 0x102cc78 */
    if (!limmoveflag) goto label1; /* Line 896, Address: 0x102cca0 */
    sv_move_sub2(); /* Line 897, Address: 0x102ccb0 */
    return; /* Line 898, Address: 0x102ccb8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 903, Address: 0x102ccc0 */
    sv_move_main(ywk); /* Line 904, Address: 0x102ccec */
    return; /* Line 905, Address: 0x102ccf8 */
  } else if (!limmoveflag) goto label1; /* Line 906, Address: 0x102cd00 */
  sv_move_sub2(); /* Line 907, Address: 0x102cd10 */
  return; /* Line 908, Address: 0x102cd18 */



label1:
  scra_vz = 0; /* Line 913, Address: 0x102cd20 */
} /* Line 914, Address: 0x102cd28 */













static void sv_move_main(short yPos) { /* Line 928, Address: 0x102cd40 */
  short spdwk;

  if (scra_vline == 96) { /* Line 931, Address: 0x102cd50 */
    if (actwk[0].mspeed.w < 0) { /* Line 932, Address: 0x102cd6c */
      spdwk = -actwk[0].mspeed.w; /* Line 933, Address: 0x102cd84 */
    } else { /* Line 934, Address: 0x102cda8 */
      spdwk = actwk[0].mspeed.w; /* Line 935, Address: 0x102cdb0 */
    }


    if (spdwk >= 2048) { /* Line 939, Address: 0x102cdc0 */
      sv_move_main2(yPos); /* Line 940, Address: 0x102cdd4 */
    } /* Line 941, Address: 0x102cde0 */
    else {

      if (yPos > 6) { /* Line 944, Address: 0x102cde8 */
        sv_move_plus(1536); /* Line 945, Address: 0x102ce00 */
      } else if (yPos < -6) { /* Line 946, Address: 0x102ce0c */
        sv_move_minus(1536); /* Line 947, Address: 0x102ce2c */
      } /* Line 948, Address: 0x102ce38 */
      else sv_move_sub(yPos); /* Line 949, Address: 0x102ce40 */
    }
  } /* Line 951, Address: 0x102ce4c */
  else {
    if (yPos > 2) { /* Line 953, Address: 0x102ce54 */
      sv_move_plus(512); /* Line 954, Address: 0x102ce6c */
    } else if (yPos < -2) { /* Line 955, Address: 0x102ce78 */
      sv_move_minus(512); /* Line 956, Address: 0x102ce98 */
    } /* Line 957, Address: 0x102cea4 */
    else sv_move_sub(yPos); /* Line 958, Address: 0x102ceac */
  }

} /* Line 961, Address: 0x102ceb8 */













static void sv_move_main2(short yPos) { /* Line 975, Address: 0x102ced0 */
  short spdwk;

  spdwk = 4096; /* Line 978, Address: 0x102cee0 */

  if (yPos > 16) { /* Line 980, Address: 0x102ceec */
    sv_move_plus(spdwk); /* Line 981, Address: 0x102cf04 */
  } else if (yPos < -16) { /* Line 982, Address: 0x102cf10 */
    sv_move_minus(spdwk); /* Line 983, Address: 0x102cf30 */
  } else { /* Line 984, Address: 0x102cf3c */
    sv_move_sub(yPos); /* Line 985, Address: 0x102cf44 */
  }
} /* Line 987, Address: 0x102cf50 */














static void sv_move_sub(short yPos) { /* Line 1002, Address: 0x102cf70 */
  int_union lSpd;

  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1005, Address: 0x102cf7c */
  if (yPos < 0) { /* Line 1006, Address: 0x102cfa8 */
    scrv_up_ch(lSpd); /* Line 1007, Address: 0x102cfbc */
  } else { /* Line 1008, Address: 0x102cfc8 */
    scrv_down_ch(lSpd); /* Line 1009, Address: 0x102cfd0 */
  }
} /* Line 1011, Address: 0x102cfdc */



static void sv_move_sub2(void) { /* Line 1015, Address: 0x102cff0 */
  limmoveflag = 0; /* Line 1016, Address: 0x102cff8 */

  sv_move_sub(0); /* Line 1018, Address: 0x102d000 */
} /* Line 1019, Address: 0x102d00c */













static void sv_move_minus(short speed) { /* Line 1033, Address: 0x102d020 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1036, Address: 0x102d02c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1037, Address: 0x102d050 */
  scrv_up_ch(lSpd); /* Line 1038, Address: 0x102d074 */
} /* Line 1039, Address: 0x102d080 */














static void scrv_up_ch(int_union lSpd) { /* Line 1054, Address: 0x102d090 */
  if (lSpd.w.l <= scralim_up) { /* Line 1055, Address: 0x102d09c */
    if (lSpd.w.l > -256) { /* Line 1056, Address: 0x102d0c4 */

      lSpd.w.l = scralim_up; /* Line 1058, Address: 0x102d0dc */
    } else { /* Line 1059, Address: 0x102d0e8 */
      lSpd.w.l &= 2047; /* Line 1060, Address: 0x102d0f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1061, Address: 0x102d0fc */
      scra_v_posit.w.h &= 2047; /* Line 1062, Address: 0x102d110 */
      scrb_v_posit.w.h &= 1023; /* Line 1063, Address: 0x102d124 */
    }
  }

  scrv_move(lSpd); /* Line 1067, Address: 0x102d138 */
} /* Line 1068, Address: 0x102d144 */













static void sv_move_plus(short sSpd) { /* Line 1082, Address: 0x102d160 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1085, Address: 0x102d16c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1086, Address: 0x102d18c */
  scrv_down_ch(lSpd); /* Line 1087, Address: 0x102d1b0 */
} /* Line 1088, Address: 0x102d1bc */














static void scrv_down_ch(int_union lSpd) { /* Line 1103, Address: 0x102d1d0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1104, Address: 0x102d1dc */
    if (lSpd.w.l < 2048) { /* Line 1105, Address: 0x102d204 */

      lSpd.w.l = scralim_down; /* Line 1107, Address: 0x102d21c */
    } else { /* Line 1108, Address: 0x102d228 */
      lSpd.w.l -= 2048; /* Line 1109, Address: 0x102d230 */
      actwk[0].yposi.w.h &= 2047; /* Line 1110, Address: 0x102d23c */
      scra_v_posit.w.h -= 2048; /* Line 1111, Address: 0x102d250 */
      scrb_v_posit.w.h &= 1023; /* Line 1112, Address: 0x102d264 */
    }
  }

  scrv_move(lSpd); /* Line 1116, Address: 0x102d278 */
} /* Line 1117, Address: 0x102d284 */
















static void scrv_move(int_union lSpd) { /* Line 1134, Address: 0x102d2a0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1138, Address: 0x102d2b0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1139, Address: 0x102d2c0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1140, Address: 0x102d2e4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1141, Address: 0x102d2f8 */
  scra_vz = spdwk.w.l; /* Line 1142, Address: 0x102d310 */

  scra_v_posit.l = lSpd.l; /* Line 1144, Address: 0x102d31c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1146, Address: 0x102d328 */
  if (!ywk) { /* Line 1147, Address: 0x102d364 */
    scra_v_count ^= 16; /* Line 1148, Address: 0x102d36c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1149, Address: 0x102d380 */
    if (ywk < 0) { /* Line 1150, Address: 0x102d3ac */
      scrflaga.b.h |= 1; /* Line 1151, Address: 0x102d3bc */
    } else { /* Line 1152, Address: 0x102d3d0 */
      scrflaga.b.h |= 2; /* Line 1153, Address: 0x102d3d8 */
    }
  }


} /* Line 1158, Address: 0x102d3ec */

















void scrollwrt(void) { /* Line 1176, Address: 0x102d400 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1185, Address: 0x102d420 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1186, Address: 0x102d424 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1187, Address: 0x102d430 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1188, Address: 0x102d43c */
  pScrFlag = &scrflagbw.b.h; /* Line 1189, Address: 0x102d444 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1190, Address: 0x102d44c */

  VramBase = 16384; /* Line 1192, Address: 0x102d460 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1193, Address: 0x102d464 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1194, Address: 0x102d470 */
  pMapWk = (unsigned char*)mapwka; /* Line 1195, Address: 0x102d47c */
  pScrFlag = &scrflagaw.b.h; /* Line 1196, Address: 0x102d484 */

  if (*pScrFlag) { /* Line 1198, Address: 0x102d48c */
    if (*pScrFlag & 1) { /* Line 1199, Address: 0x102d498 */
      *pScrFlag &= 254; /* Line 1200, Address: 0x102d4ac */

      lD4.l = -16; /* Line 1202, Address: 0x102d4b8 */
      wD5 = 65520; /* Line 1203, Address: 0x102d4c0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1205, Address: 0x102d4c8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1207, Address: 0x102d4e8 */
    }




    if (*pScrFlag & 2) { /* Line 1213, Address: 0x102d514 */
      *pScrFlag &= 253; /* Line 1214, Address: 0x102d528 */

      lD4.l = 224; /* Line 1216, Address: 0x102d534 */
      wD5 = 65520; /* Line 1217, Address: 0x102d53c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1218, Address: 0x102d544 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1220, Address: 0x102d564 */
    }




    if (*pScrFlag & 4) { /* Line 1226, Address: 0x102d590 */
      *pScrFlag &= 251; /* Line 1227, Address: 0x102d5a4 */

      lD4.l = -16; /* Line 1229, Address: 0x102d5b0 */
      wD5 = 65520; /* Line 1230, Address: 0x102d5b8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1231, Address: 0x102d5c0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1233, Address: 0x102d5e0 */
    }




    if (*pScrFlag & 8) { /* Line 1239, Address: 0x102d60c */
      *pScrFlag &= 247; /* Line 1240, Address: 0x102d620 */

      lD4.l = -16; /* Line 1242, Address: 0x102d62c */
      wD5 = 320; /* Line 1243, Address: 0x102d634 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1244, Address: 0x102d63c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1246, Address: 0x102d65c */
    }
  }






} /* Line 1255, Address: 0x102d688 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1272, Address: 0x102d6b0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1283, Address: 0x102d6dc */

  if (*pScrFlag & 1) { /* Line 1285, Address: 0x102d6e4 */
    *pScrFlag &= 254; /* Line 1286, Address: 0x102d6fc */
  } /* Line 1287, Address: 0x102d710 */
  else {
    *pScrFlag &= 254; /* Line 1289, Address: 0x102d718 */

    if (*pScrFlag & 2) { /* Line 1291, Address: 0x102d72c */
      *pScrFlag &= 253; /* Line 1292, Address: 0x102d744 */
      lD4.w.l = 224; /* Line 1293, Address: 0x102d758 */
    } /* Line 1294, Address: 0x102d760 */
    else {
      *pScrFlag &= 253; /* Line 1296, Address: 0x102d768 */
      goto label1; /* Line 1297, Address: 0x102d77c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1302, Address: 0x102d784 */
  wD0 &= 127; /* Line 1303, Address: 0x102d7d4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1304, Address: 0x102d7dc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1310, Address: 0x102d7fc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1311, Address: 0x102d81c */
  if (wD0 != 0) { /* Line 1312, Address: 0x102d840 */
    wD5 = 65520; /* Line 1313, Address: 0x102d84c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1314, Address: 0x102d854 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1316, Address: 0x102d874 */



  } /* Line 1320, Address: 0x102d8a0 */
  else {

    wD5 = 0; /* Line 1323, Address: 0x102d8a8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1324, Address: 0x102d8ac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1328, Address: 0x102d8cc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1335, Address: 0x102d8f8 */






    lD4.l = -16; /* Line 1342, Address: 0x102d90c */
    wD5 = 65520; /* Line 1343, Address: 0x102d914 */
    if (*pScrFlag & 168) { /* Line 1344, Address: 0x102d91c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1345, Address: 0x102d934 */
      wD5 = 320; /* Line 1346, Address: 0x102d954 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1350, Address: 0x102d95c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1352, Address: 0x102d98c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1353, Address: 0x102d998 */



    for (i = 0; i < 16; ++i) { /* Line 1357, Address: 0x102d9a8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1358, Address: 0x102d9b4 */
      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1359, Address: 0x102d9d4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1360, Address: 0x102da0c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1361, Address: 0x102da2c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1363, Address: 0x102da50 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1366, Address: 0x102da74 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1368, Address: 0x102da94 */
      }
      lD4.w.l += 16; /* Line 1370, Address: 0x102daa8 */
    } /* Line 1371, Address: 0x102dab4 */
    *pScrFlag = 0; /* Line 1372, Address: 0x102dac4 */
  }
} /* Line 1374, Address: 0x102dacc */





void scrollwrtc(void) {} /* Line 1380, Address: 0x102db00 */




void scrollwrtz(void) {} /* Line 1385, Address: 0x102db10 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1403, Address: 0x102db20 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1416, Address: 0x102db48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1419, Address: 0x102db68 */
    pTilePoint->x += 2; /* Line 1420, Address: 0x102db7c */
    if (pTilePoint->x >= 64) { /* Line 1421, Address: 0x102db90 */
      pTilePoint->x -= 64; /* Line 1422, Address: 0x102dba4 */
    }
    xOffs += 16; /* Line 1424, Address: 0x102dbb8 */
  } while (--lpcnt >= 0); /* Line 1425, Address: 0x102dbc4 */
} /* Line 1426, Address: 0x102dbd8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1430, Address: 0x102dbf0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1434, Address: 0x102dc18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1437, Address: 0x102dc38 */
    pTilePoint->x += 2; /* Line 1438, Address: 0x102dc4c */
    if (pTilePoint->x >= 64) { /* Line 1439, Address: 0x102dc60 */
      pTilePoint->x -= 64; /* Line 1440, Address: 0x102dc74 */
    }
    xOffs += 16; /* Line 1442, Address: 0x102dc88 */
  } while (--lpcnt >= 0); /* Line 1443, Address: 0x102dc94 */
} /* Line 1444, Address: 0x102dca8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1464, Address: 0x102dcc0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1468, Address: 0x102dce8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1471, Address: 0x102dd08 */
    pTilePoint->y += 2; /* Line 1472, Address: 0x102dd1c */
    if (pTilePoint->y >= 32) { /* Line 1473, Address: 0x102dd2c */
      pTilePoint->y -= 32; /* Line 1474, Address: 0x102dd40 */
    }
    yOffs += 16; /* Line 1476, Address: 0x102dd50 */
  } while (--lpcnt >= 0); /* Line 1477, Address: 0x102dd5c */
} /* Line 1478, Address: 0x102dd70 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1497, Address: 0x102dd80 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1503, Address: 0x102ddb4 */

    base = 1; /* Line 1505, Address: 0x102ddc4 */
  } /* Line 1506, Address: 0x102ddc8 */
  else if (VramBase == 16384) { /* Line 1507, Address: 0x102ddd0 */

    base = 0; /* Line 1509, Address: 0x102dde0 */
  }
  x = pTilePoint->x; /* Line 1511, Address: 0x102dde4 */
  y = pTilePoint->y; /* Line 1512, Address: 0x102ddec */


  frip = BlkIndex & 6144; /* Line 1515, Address: 0x102ddf4 */
  BlkIndex &= 1023; /* Line 1516, Address: 0x102ddfc */
  if (frip == 6144) { /* Line 1517, Address: 0x102de08 */

    p0 = 3, p1 = 2; /* Line 1519, Address: 0x102de14 */
    p2 = 1, p3 = 0; /* Line 1520, Address: 0x102de1c */
  } /* Line 1521, Address: 0x102de24 */
  else if (frip & 4096) { /* Line 1522, Address: 0x102de2c */

    p0 = 2, p1 = 3; /* Line 1524, Address: 0x102de38 */
    p2 = 0, p3 = 1; /* Line 1525, Address: 0x102de40 */
  } /* Line 1526, Address: 0x102de48 */
  else if (frip & 2048) { /* Line 1527, Address: 0x102de50 */

    p0 = 1, p1 = 0; /* Line 1529, Address: 0x102de5c */
    p2 = 3, p3 = 2; /* Line 1530, Address: 0x102de64 */
  } /* Line 1531, Address: 0x102de6c */
  else {

    p0 = 0, p1 = 1; /* Line 1534, Address: 0x102de74 */
    p2 = 2, p3 = 3; /* Line 1535, Address: 0x102de7c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1538, Address: 0x102de84 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1539, Address: 0x102dec8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1540, Address: 0x102df0c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1541, Address: 0x102df50 */

} /* Line 1543, Address: 0x102df94 */
















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1560, Address: 0x102dfd0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1561, Address: 0x102dff0 */
} /* Line 1562, Address: 0x102e010 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1564, Address: 0x102e020 */
  wH_posiw = 0; /* Line 1565, Address: 0x102e040 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1566, Address: 0x102e044 */
} /* Line 1567, Address: 0x102e064 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1574, Address: 0x102e080 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1580, Address: 0x102e0b0 */
  yOffs += wV_posiw; /* Line 1581, Address: 0x102e0c0 */





  if ((short)xOffs < 0) /* Line 1587, Address: 0x102e0d0 */
    xOffs = 0; /* Line 1588, Address: 0x102e0ec */
  if ((short)yOffs < 0) /* Line 1589, Address: 0x102e0f0 */
    yOffs = 0; /* Line 1590, Address: 0x102e10c */
  if ((short)xOffs >= 16384) /* Line 1591, Address: 0x102e110 */
    xOffs = 16383; /* Line 1592, Address: 0x102e130 */
  if ((short)yOffs >= 2048) /* Line 1593, Address: 0x102e138 */
    yOffs = 2047; /* Line 1594, Address: 0x102e158 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1595, Address: 0x102e160 */
  if (i < 0) i = 0; /* Line 1596, Address: 0x102e1a8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1598, Address: 0x102e1b4 */

  if (ScreenNo) { /* Line 1600, Address: 0x102e1d0 */




    xOffs &= 32767; /* Line 1605, Address: 0x102e1d8 */
    yOffs &= 32767; /* Line 1606, Address: 0x102e1e4 */


    xBlk = xOffs; /* Line 1609, Address: 0x102e1f0 */
    xBlk %= 256; /* Line 1610, Address: 0x102e1f8 */
    xBlk /= 16; /* Line 1611, Address: 0x102e218 */
    yBlk = yOffs; /* Line 1612, Address: 0x102e234 */
    yBlk %= 256; /* Line 1613, Address: 0x102e23c */
    yBlk /= 16; /* Line 1614, Address: 0x102e25c */

    lpw = pmapwk; /* Line 1616, Address: 0x102e278 */
    lpw += xBlk; /* Line 1617, Address: 0x102e280 */
    lpw += yBlk * 16; /* Line 1618, Address: 0x102e288 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1619, Address: 0x102e294 */
    *pIndex = *lpw; /* Line 1620, Address: 0x102e2ac */

    return 1; /* Line 1622, Address: 0x102e2bc */
  }

  *pIndex = 0; /* Line 1625, Address: 0x102e2c8 */
  return 0; /* Line 1626, Address: 0x102e2d0 */
} /* Line 1627, Address: 0x102e2d4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1647, Address: 0x102e300 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1655, Address: 0x102e328 */
  if (ScreenNo) { /* Line 1656, Address: 0x102e38c */





    xBlk = xOffs; /* Line 1662, Address: 0x102e394 */
    xBlk %= 256; /* Line 1663, Address: 0x102e39c */
    xBlk /= 16; /* Line 1664, Address: 0x102e3bc */
    yBlk = yOffs; /* Line 1665, Address: 0x102e3d8 */
    yBlk %= 256; /* Line 1666, Address: 0x102e3e0 */
    yBlk /= 16; /* Line 1667, Address: 0x102e400 */


    lpw = pmapwk; /* Line 1670, Address: 0x102e41c */
    lpw += xBlk; /* Line 1671, Address: 0x102e424 */
    lpw += yBlk * 16; /* Line 1672, Address: 0x102e42c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1673, Address: 0x102e438 */
    *ppBlockNo = lpw; /* Line 1674, Address: 0x102e450 */
    *pIndex = *lpw; /* Line 1675, Address: 0x102e458 */




    return 1; /* Line 1680, Address: 0x102e468 */
  }

  *pIndex = 0; /* Line 1683, Address: 0x102e474 */
  return 0; /* Line 1684, Address: 0x102e47c */
} /* Line 1685, Address: 0x102e480 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1699, Address: 0x102e4a0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1706, Address: 0x102e4bc */
  pMapWk = (unsigned char*)mapwka; /* Line 1707, Address: 0x102e4c0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1708, Address: 0x102e4c8 */
    *pBlockIndex = BlockNo; /* Line 1709, Address: 0x102e4ec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1710, Address: 0x102e4f8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1711, Address: 0x102e510 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1712, Address: 0x102e524 */
    }
  }


} /* Line 1717, Address: 0x102e53c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1731, Address: 0x102e560 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1732, Address: 0x102e56c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1733, Address: 0x102e598 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1734, Address: 0x102e5e4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1735, Address: 0x102e610 */

          return 0; /* Line 1737, Address: 0x102e65c */
        }
      }
    }
  }

  return 1; /* Line 1743, Address: 0x102e668 */
} /* Line 1744, Address: 0x102e66c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1761, Address: 0x102e680 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1762, Address: 0x102e69c */

} /* Line 1764, Address: 0x102e6b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1766, Address: 0x102e6d0 */
  wH_posiw = 0; /* Line 1767, Address: 0x102e6ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1768, Address: 0x102e6f0 */

} /* Line 1770, Address: 0x102e70c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1772, Address: 0x102e720 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1773, Address: 0x102e734 */

} /* Line 1775, Address: 0x102e750 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1777, Address: 0x102e760 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1778, Address: 0x102e77c */

} /* Line 1780, Address: 0x102e798 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1782, Address: 0x102e7b0 */
  xOffs += wH_posiw; /* Line 1783, Address: 0x102e7c8 */
  yOffs += wV_posiw; /* Line 1784, Address: 0x102e7d8 */
  yOffs &= 240; /* Line 1785, Address: 0x102e7e8 */
  xOffs &= 496; /* Line 1786, Address: 0x102e7f4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1788, Address: 0x102e800 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1789, Address: 0x102e82c */


} /* Line 1792, Address: 0x102e858 */















void mapwrt(void) { /* Line 1808, Address: 0x102e870 */
  int VramBase;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  unsigned char* pMapWk;


  wH_posiw = scra_h_posit.w.h; /* Line 1815, Address: 0x102e888 */
  wV_posiw = scra_v_posit.w.h; /* Line 1816, Address: 0x102e894 */
  pMapWk = (unsigned char*)mapwka; /* Line 1817, Address: 0x102e8a0 */
  VramBase = 16384; /* Line 1818, Address: 0x102e8a8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1819, Address: 0x102e8ac */



  pMapWk = (unsigned char*)mapwkb; /* Line 1823, Address: 0x102e8c4 */
  VramBase = 24576; /* Line 1824, Address: 0x102e8cc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1825, Address: 0x102e8d0 */

} /* Line 1827, Address: 0x102e8e0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1830, Address: 0x102e900 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1831, Address: 0x102e918 */
} /* Line 1832, Address: 0x102e938 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1837, Address: 0x102e950 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1841, Address: 0x102e970 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1844, Address: 0x102e98c */



    wD4 += 16; /* Line 1848, Address: 0x102e9b4 */
  } while ((short)--wD6 >= 0); /* Line 1849, Address: 0x102e9c0 */

} /* Line 1851, Address: 0x102e9e8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1857, Address: 0x102ea00 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1860, Address: 0x102ea1c */
  wD6 = 15; /* Line 1861, Address: 0x102ea24 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1864, Address: 0x102ea2c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1866, Address: 0x102ea50 */
    wD4 += 16; /* Line 1867, Address: 0x102ea70 */
  } while ((short)--wD6 >= 0); /* Line 1868, Address: 0x102ea78 */
} /* Line 1869, Address: 0x102ea9c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1895, Address: 0x102eac0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1900, Address: 0x102eae8 */
  wD0 = pWrttbl[wD0]; /* Line 1901, Address: 0x102eaf8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1903, Address: 0x102eb14 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1904, Address: 0x102eb38 */
  if (wD0) { /* Line 1905, Address: 0x102eb60 */
    wD5 = 65520; /* Line 1906, Address: 0x102eb6c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1907, Address: 0x102eb74 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1910, Address: 0x102eb90 */



  } /* Line 1914, Address: 0x102ebb8 */
  else {

    wD5 = 0; /* Line 1917, Address: 0x102ebc0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1918, Address: 0x102ebc4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1922, Address: 0x102ebe0 */
  }





} /* Line 1929, Address: 0x102ec08 */










void mapinit(void) { /* Line 1940, Address: 0x102ec30 */

  colorset2(mapinittbl.colorno2); /* Line 1942, Address: 0x102ec38 */
  colorset(mapinittbl.colorno2); /* Line 1943, Address: 0x102ec4c */


  if (play_start & 2) divdevset(); /* Line 1946, Address: 0x102ec60 */
} /* Line 1947, Address: 0x102ec80 */




void mapset(void) {} /* Line 1952, Address: 0x102ec90 */



void divdevset() {} /* Line 1956, Address: 0x102eca0 */



void enecginit(void) {} /* Line 1960, Address: 0x102ecb0 */
