#include "..\EQU.H"
#include "SCR51A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset(void);
static void scrbinit(short sXpos, short sYpos);
static void z51cline(short** ppHscw);
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
static void mapset2(unsigned char* pMapDst, int idx);

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
extern unsigned char mapwkb[8][64];
short scr_dir_tbl[6] = { 4, 0, 10903, 0, 784, 96 };
short playpositbl[1][2] = { { 64, 620 } };
unsigned char playmapnotbl[4] = { 127, 127, 98, 24 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg(void) { /* Line 151, Address: 0x1023b10 */
  short tbl[9] = { /* Line 152, Address: 0x1023b30 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 157, Address: 0x1023b5c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 163, Address: 0x1023b80 */



  EnkeiNo = 0; /* Line 167, Address: 0x1023b90 */
  pTbl = tbl; /* Line 168, Address: 0x1023b94 */

  while ((poswk = *pTbl++) >= 0) { /* Line 170, Address: 0x1023b98 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 171, Address: 0x1023ba0 */


    ++EnkeiNo; /* Line 174, Address: 0x1023bc4 */
  } /* Line 175, Address: 0x1023bc8 */


  if (enkeino == EnkeiNo) return; /* Line 178, Address: 0x1023bec */




  enkeino = EnkeiNo; /* Line 183, Address: 0x1023c00 */


  TileNo = 592; /* Line 186, Address: 0x1023c0c */
  if (EnkeiNo == 1) { /* Line 187, Address: 0x1023c10 */
    i = 99; /* Line 188, Address: 0x1023c1c */
    BmpNo = 95; /* Line 189, Address: 0x1023c20 */
  } else { /* Line 190, Address: 0x1023c24 */
    i = 95; /* Line 191, Address: 0x1023c2c */
    BmpNo = 0; /* Line 192, Address: 0x1023c30 */
  }
  for ( ; i > 0; --i) { /* Line 194, Address: 0x1023c34 */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 195, Address: 0x1023c3c */
  } /* Line 196, Address: 0x1023c5c */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 198, Address: 0x1023c68 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 199, Address: 0x1023c88 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 201, Address: 0x1023ca8 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 202, Address: 0x1023ce0 */
  mapwrt_cnt = 1; /* Line 203, Address: 0x1023cf8 */
} /* Line 204, Address: 0x1023d04 */












sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 218, Address: 0x1023d30 */
    return &actwk[0]; /* Line 219, Address: 0x1023d44 */
  else
    return &actwk[1]; /* Line 221, Address: 0x1023d54 */

} /* Line 223, Address: 0x1023d5c */





































void scr_set(void) { /* Line 261, Address: 0x1023d70 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 264, Address: 0x1023d7c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 265, Address: 0x1023d90 */
  scr_timer.b.h = 0; /* Line 266, Address: 0x1023da4 */

  pScrTbl = scr_dir_tbl; /* Line 268, Address: 0x1023dac */
  scrar_no = *pScrTbl; /* Line 269, Address: 0x1023db4 */
  ++pScrTbl; /* Line 270, Address: 0x1023dc0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 271, Address: 0x1023dc4 */
  ++pScrTbl; /* Line 272, Address: 0x1023dd8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 273, Address: 0x1023ddc */
  ++pScrTbl; /* Line 274, Address: 0x1023df0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 275, Address: 0x1023df4 */
  ++pScrTbl; /* Line 276, Address: 0x1023e08 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 277, Address: 0x1023e0c */
  scra_h_keep = *pScrTbl + 576; /* Line 278, Address: 0x1023e20 */
  ++pScrTbl; /* Line 279, Address: 0x1023e40 */
  scra_h_count = 16; /* Line 280, Address: 0x1023e44 */
  scra_v_count = 16; /* Line 281, Address: 0x1023e50 */

  scra_vline = *pScrTbl; /* Line 283, Address: 0x1023e5c */
  scra_hline = 160; /* Line 284, Address: 0x1023e68 */

  playposiset(); /* Line 286, Address: 0x1023e74 */
} /* Line 287, Address: 0x1023e7c */






































static void playposiset(void) { /* Line 326, Address: 0x1023e90 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 329, Address: 0x1023ea4 */
    playload(); /* Line 330, Address: 0x1023eb4 */
    xwk = actwk[0].xposi.w.h; /* Line 331, Address: 0x1023ebc */

    if (actwk[0].yposi.w.h > 0) { /* Line 333, Address: 0x1023ecc */
      ywk = actwk[0].yposi.w.h; /* Line 334, Address: 0x1023ee4 */
    } else { /* Line 335, Address: 0x1023ef4 */
      ywk = 0; /* Line 336, Address: 0x1023efc */
    }
  } /* Line 338, Address: 0x1023f00 */
  else {
    pPositbl = playpositbl[0]; /* Line 340, Address: 0x1023f08 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 343, Address: 0x1023f10 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 344, Address: 0x1023f24 */
  }


  if (xwk > 160) { /* Line 348, Address: 0x1023f38 */
    xwk -= 160; /* Line 349, Address: 0x1023f4c */
  } else { /* Line 350, Address: 0x1023f58 */
    xwk = 0; /* Line 351, Address: 0x1023f60 */
  }


  if (xwk > scralim_right) { /* Line 355, Address: 0x1023f64 */
    xwk = scralim_right; /* Line 356, Address: 0x1023f88 */
  }


  scra_h_posit.w.h = xwk; /* Line 360, Address: 0x1023f98 */

  if (ywk > 96) { /* Line 362, Address: 0x1023fa0 */
    ywk -= 96; /* Line 363, Address: 0x1023fb4 */
  } else { /* Line 364, Address: 0x1023fc0 */
    ywk = 0; /* Line 365, Address: 0x1023fc8 */
  }


  if (ywk > scralim_down) { /* Line 369, Address: 0x1023fcc */
    ywk = scralim_down; /* Line 370, Address: 0x1023ff0 */
  }


  scra_v_posit.w.h = ywk; /* Line 374, Address: 0x1024000 */

  scrbinit(xwk, ywk); /* Line 376, Address: 0x1024008 */


  loopmapno = playmapnotbl[0]; /* Line 379, Address: 0x1024018 */
  loopmapno2 = playmapnotbl[1]; /* Line 380, Address: 0x1024028 */
  ballmapno = playmapnotbl[2]; /* Line 381, Address: 0x1024038 */
  ballmapno2 = playmapnotbl[3]; /* Line 382, Address: 0x1024048 */
} /* Line 383, Address: 0x1024058 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 404, Address: 0x1024080 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 407, Address: 0x102408c */
  lYwk.w.l = 0; /* Line 408, Address: 0x1024094 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 410, Address: 0x1024098 */

  scrb_v_posit.l = lYwk.l; /* Line 412, Address: 0x10240a4 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 413, Address: 0x10240b0 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 414, Address: 0x10240bc */

  sXpos = (unsigned short)sXpos >> 1; /* Line 416, Address: 0x10240c8 */
  scrb_h_posit.w.h = sXpos; /* Line 417, Address: 0x10240e4 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 419, Address: 0x10240f0 */
  scrc_h_posit.w.h = sXpos; /* Line 420, Address: 0x102410c */

  sXpos >>= 2; /* Line 422, Address: 0x1024118 */
  scrz_h_posit.w.h = sXpos * 3; /* Line 423, Address: 0x1024124 */
} /* Line 424, Address: 0x1024148 */















void scroll(void) { /* Line 440, Address: 0x1024160 */
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

  if (scroll_start.b.h) return; /* Line 452, Address: 0x102417c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 457, Address: 0x102418c */

  scrchk(); /* Line 459, Address: 0x10241b8 */

  scroll_h(); /* Line 461, Address: 0x10241c0 */
  scroll_v(); /* Line 462, Address: 0x10241c8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 464, Address: 0x10241d0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 465, Address: 0x10241e0 */


  lXwk = scra_hz * 16 * 3; /* Line 468, Address: 0x10241f0 */
  scrollz_h(lXwk, 6); /* Line 469, Address: 0x102420c */

  lXwk = scra_hz * 64; /* Line 471, Address: 0x102421c */
  scrollc_h(lXwk, 4); /* Line 472, Address: 0x1024230 */

  lXwk = scra_hz * 128; /* Line 474, Address: 0x1024240 */
  scrollb_h(lXwk, 2); /* Line 475, Address: 0x1024254 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 477, Address: 0x1024264 */


  scrollb_v(lYwk); /* Line 480, Address: 0x1024278 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 482, Address: 0x1024288 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 483, Address: 0x10242b0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 484, Address: 0x10242e8 */

  psHscw = hscrollwork; /* Line 486, Address: 0x10242fc */

  if (enkeino & 1) { /* Line 488, Address: 0x1024308 */

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 490, Address: 0x1024320 */
    for (i = 0; i < 14; ++i) { /* Line 491, Address: 0x1024340 */

      *psHscw++ = ldwk.w.l; /* Line 493, Address: 0x102434c */
    } /* Line 494, Address: 0x1024360 */
    z51cline(&psHscw); /* Line 495, Address: 0x1024370 */
  } /* Line 496, Address: 0x102437c */
  else {
    ldwk.w.l = -scrb_h_posit.w.h; /* Line 498, Address: 0x1024384 */
    for (i = 0; i < 10; ++i) { /* Line 499, Address: 0x10243a4 */

      *psHscw++ = ldwk.w.l; /* Line 501, Address: 0x10243b0 */
    } /* Line 502, Address: 0x10243c4 */

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 504, Address: 0x10243d4 */
    for (i = 0; i < 22; ++i) { /* Line 505, Address: 0x10243f4 */

      *psHscw++ = ldwk.w.l; /* Line 507, Address: 0x1024400 */
    } /* Line 508, Address: 0x1024414 */

    ldwk.w.l = -scrc_h_posit.w.h; /* Line 510, Address: 0x1024424 */
    for (i = 0; i < 4; ++i) { /* Line 511, Address: 0x1024444 */

      *psHscw++ = ldwk.w.l; /* Line 513, Address: 0x1024450 */
    } /* Line 514, Address: 0x1024464 */

    ldwk.w.l = -scrb_h_posit.w.h; /* Line 516, Address: 0x1024474 */
    for (i = 0; i < 12; ++i) { /* Line 517, Address: 0x1024494 */

      *psHscw++ = ldwk.w.l; /* Line 519, Address: 0x10244a0 */
    } /* Line 520, Address: 0x10244b4 */
  }


  pHscrbuf = lphscrollbuff; /* Line 524, Address: 0x10244c4 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 525, Address: 0x10244d0 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 526, Address: 0x1024500 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 527, Address: 0x1024530 */
} /* Line 528, Address: 0x102454c */













static void z51cline(short** ppHscw) { /* Line 542, Address: 0x1024570 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51cscrtbl[3] = { /* Line 547, Address: 0x1024588 */
    39, 3, 9
  };

  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 551, Address: 0x10245ac */
  lHwk = (unsigned int)lHwk * 128 / 12; /* Line 552, Address: 0x10245d0 */
  lHwk *= 512; /* Line 553, Address: 0x10245ec */

  ldHposwk.l = 0; /* Line 555, Address: 0x10245f0 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 556, Address: 0x10245f4 */

  for (i = 2; i >= 0; --i) { /* Line 558, Address: 0x1024600 */

    wk = -ldHposwk.w.l; /* Line 560, Address: 0x102460c */

    for (j = z51cscrtbl[i]; j >= 0; --j) { /* Line 562, Address: 0x102462c */

      **ppHscw = wk; /* Line 564, Address: 0x1024644 */
      ++*ppHscw; /* Line 565, Address: 0x1024650 */
    } /* Line 566, Address: 0x1024664 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 568, Address: 0x1024670 */
    ldHposwk.l += lHwk; /* Line 569, Address: 0x1024694 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 570, Address: 0x10246a0 */
  } /* Line 571, Address: 0x10246c4 */
} /* Line 572, Address: 0x10246d0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 593, Address: 0x10246f0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 597, Address: 0x102470c */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 599, Address: 0x1024710 */
    ldwk.w.l = *pHscrwk; /* Line 600, Address: 0x102472c */
    ++pHscrwk; /* Line 601, Address: 0x1024738 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 603, Address: 0x1024744 */
      (*pHscrbuf)->l = ldwk.l; /* Line 604, Address: 0x102474c */
    } /* Line 605, Address: 0x102475c */
  } /* Line 606, Address: 0x1024780 */
} /* Line 607, Address: 0x10247a0 */









































































































static void scrollb_v(short yPos) { /* Line 713, Address: 0x10247c0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 716, Address: 0x10247d0 */
  scrb_v_posit.w.h = yPos; /* Line 717, Address: 0x10247e0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 718, Address: 0x10247ec */

  if (!ywk) { /* Line 720, Address: 0x1024824 */
    scrb_v_count ^= 16; /* Line 721, Address: 0x102482c */
    if (yPos - ysv < 0) { /* Line 722, Address: 0x1024840 */
      scrflagb.b.h |= 1; /* Line 723, Address: 0x1024860 */
    } /* Line 724, Address: 0x1024874 */
    else {
      scrflagb.b.h |= 2; /* Line 726, Address: 0x102487c */
    }
  }


} /* Line 731, Address: 0x1024890 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 749, Address: 0x10248b0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 753, Address: 0x10248c4 */
  lXwk = lXsv + xoffs; /* Line 754, Address: 0x10248cc */
  scrb_h_posit.l = lXwk; /* Line 755, Address: 0x10248d4 */
  ldXwk.l = lXwk; /* Line 756, Address: 0x10248dc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 757, Address: 0x10248e0 */
  ldXwk.w.l &= 16; /* Line 758, Address: 0x1024904 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 759, Address: 0x1024910 */

  if (!ldXwk.b.b4) { /* Line 761, Address: 0x102492c */
    scrb_h_count ^= 16; /* Line 762, Address: 0x1024938 */
    if (lXwk - lXsv < 0) { /* Line 763, Address: 0x102494c */
      scrflagb.b.h |= 1 << flgbit; /* Line 764, Address: 0x1024958 */
    } /* Line 765, Address: 0x102497c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 767, Address: 0x1024984 */
    }
  }


} /* Line 772, Address: 0x10249ac */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 790, Address: 0x10249c0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 794, Address: 0x10249d4 */
  lXwk = lXsv + xoffs; /* Line 795, Address: 0x10249dc */
  scrc_h_posit.l = lXwk; /* Line 796, Address: 0x10249e4 */
  ldXwk.l = lXwk; /* Line 797, Address: 0x10249ec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 798, Address: 0x10249f0 */
  ldXwk.w.l &= 16; /* Line 799, Address: 0x1024a14 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 800, Address: 0x1024a20 */

  if (!ldXwk.b.b4) { /* Line 802, Address: 0x1024a3c */
    scrc_h_count ^= 16; /* Line 803, Address: 0x1024a48 */
    if (lXwk - lXsv < 0) { /* Line 804, Address: 0x1024a5c */
      scrflagc.b.h |= 1 << flgbit; /* Line 805, Address: 0x1024a68 */
    } /* Line 806, Address: 0x1024a8c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 808, Address: 0x1024a94 */
    }
  }


} /* Line 813, Address: 0x1024abc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 831, Address: 0x1024ad0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 835, Address: 0x1024ae4 */
  lXwk = lXsv + xoffs; /* Line 836, Address: 0x1024aec */
  scrz_h_posit.l = lXwk; /* Line 837, Address: 0x1024af4 */
  ldXwk.l = lXwk; /* Line 838, Address: 0x1024afc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 839, Address: 0x1024b00 */
  ldXwk.w.l &= 16; /* Line 840, Address: 0x1024b24 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 841, Address: 0x1024b30 */

  if (!ldXwk.b.b4) { /* Line 843, Address: 0x1024b4c */
    scrz_h_count ^= 16; /* Line 844, Address: 0x1024b58 */
    if (lXwk - lXsv < 0) { /* Line 845, Address: 0x1024b6c */
      scrflagz.b.h |= 1 << flgbit; /* Line 846, Address: 0x1024b78 */
    } /* Line 847, Address: 0x1024b9c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 849, Address: 0x1024ba4 */
    }
  }


} /* Line 854, Address: 0x1024bcc */














static void scroll_h(void) { /* Line 869, Address: 0x1024be0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 873, Address: 0x1024bf0 */

  scrh_move(); /* Line 875, Address: 0x1024c00 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 876, Address: 0x1024c08 */
  if (!bXwk) { /* Line 877, Address: 0x1024c3c */
    scra_h_count ^= 16; /* Line 878, Address: 0x1024c44 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 879, Address: 0x1024c58 */
      scrflaga.b.h |= 4; /* Line 880, Address: 0x1024c7c */
    } else { /* Line 881, Address: 0x1024c90 */
      scrflaga.b.h |= 8; /* Line 882, Address: 0x1024c98 */
    }
  }


} /* Line 887, Address: 0x1024cac */
















static void scrh_move(void) { /* Line 904, Address: 0x1024cd0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 907, Address: 0x1024cd8 */
  if (xwk == 0) { /* Line 908, Address: 0x1024d20 */

    scra_hz = 0; /* Line 910, Address: 0x1024d30 */
    return; /* Line 911, Address: 0x1024d38 */
  } else if (xwk < 0) { /* Line 912, Address: 0x1024d40 */

    if (xwk < -16) { /* Line 914, Address: 0x1024d50 */
      xwk = -16; /* Line 915, Address: 0x1024d64 */
    }


    xwk += scra_h_posit.w.h; /* Line 919, Address: 0x1024d70 */
    if (xwk < scralim_left) { /* Line 920, Address: 0x1024d84 */
      xwk = scralim_left; /* Line 921, Address: 0x1024da8 */
    }
  } /* Line 923, Address: 0x1024db8 */
  else {
    if (xwk > 16) { /* Line 925, Address: 0x1024dc0 */
      xwk = 16; /* Line 926, Address: 0x1024dd4 */
    }


    xwk += scra_h_posit.w.h; /* Line 930, Address: 0x1024de0 */
    if (xwk > scralim_right) { /* Line 931, Address: 0x1024df4 */
      xwk = scralim_right; /* Line 932, Address: 0x1024e18 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 937, Address: 0x1024e28 */
  scra_h_posit.w.h = xwk; /* Line 938, Address: 0x1024e58 */
} /* Line 939, Address: 0x1024e60 */














static void scroll_v(void) { /* Line 954, Address: 0x1024e70 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 957, Address: 0x1024e7c */
  if (actwk[0].cddat & 4) { /* Line 958, Address: 0x1024eb0 */
    ywk -= 5; /* Line 959, Address: 0x1024ec8 */
  }


  if (actwk[0].cddat & 2) { /* Line 963, Address: 0x1024ed4 */
    ywk += 32; /* Line 964, Address: 0x1024eec */
    if (ywk < scra_vline) { /* Line 965, Address: 0x1024ef8 */
      ywk -= scra_vline; /* Line 966, Address: 0x1024f1c */
      sv_move_main2(ywk); /* Line 967, Address: 0x1024f30 */
      return; /* Line 968, Address: 0x1024f3c */
    } else if (ywk >= scra_vline + 64) { /* Line 969, Address: 0x1024f44 */
      ywk -= scra_vline + 64; /* Line 970, Address: 0x1024f6c */
      sv_move_main2(ywk); /* Line 971, Address: 0x1024f94 */
      return; /* Line 972, Address: 0x1024fa0 */
    }
    ywk -= scra_vline + 64; /* Line 974, Address: 0x1024fa8 */
    if (!limmoveflag) goto label1; /* Line 975, Address: 0x1024fd0 */
    sv_move_sub2(); /* Line 976, Address: 0x1024fe0 */
    return; /* Line 977, Address: 0x1024fe8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 982, Address: 0x1024ff0 */
    sv_move_main(ywk); /* Line 983, Address: 0x102501c */
    return; /* Line 984, Address: 0x1025028 */
  } else if (!limmoveflag) goto label1; /* Line 985, Address: 0x1025030 */
  sv_move_sub2(); /* Line 986, Address: 0x1025040 */
  return; /* Line 987, Address: 0x1025048 */



label1:
  scra_vz = 0; /* Line 992, Address: 0x1025050 */
} /* Line 993, Address: 0x1025058 */













static void sv_move_main(short yPos) { /* Line 1007, Address: 0x1025070 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1010, Address: 0x1025080 */
    if (actwk[0].mspeed.w < 0) { /* Line 1011, Address: 0x102509c */
      spdwk = -actwk[0].mspeed.w; /* Line 1012, Address: 0x10250b4 */
    } else { /* Line 1013, Address: 0x10250d8 */
      spdwk = actwk[0].mspeed.w; /* Line 1014, Address: 0x10250e0 */
    }


    if (spdwk >= 2048) { /* Line 1018, Address: 0x10250f0 */
      sv_move_main2(yPos); /* Line 1019, Address: 0x1025104 */
    } /* Line 1020, Address: 0x1025110 */
    else {

      if (yPos > 6) { /* Line 1023, Address: 0x1025118 */
        sv_move_plus(1536); /* Line 1024, Address: 0x1025130 */
      } else if (yPos < -6) { /* Line 1025, Address: 0x102513c */
        sv_move_minus(1536); /* Line 1026, Address: 0x102515c */
      } /* Line 1027, Address: 0x1025168 */
      else sv_move_sub(yPos); /* Line 1028, Address: 0x1025170 */
    }
  } /* Line 1030, Address: 0x102517c */
  else {
    if (yPos > 2) { /* Line 1032, Address: 0x1025184 */
      sv_move_plus(512); /* Line 1033, Address: 0x102519c */
    } else if (yPos < -2) { /* Line 1034, Address: 0x10251a8 */
      sv_move_minus(512); /* Line 1035, Address: 0x10251c8 */
    } /* Line 1036, Address: 0x10251d4 */
    else sv_move_sub(yPos); /* Line 1037, Address: 0x10251dc */
  }

} /* Line 1040, Address: 0x10251e8 */













static void sv_move_main2(short yPos) { /* Line 1054, Address: 0x1025200 */
  short spdwk;

  spdwk = 4096; /* Line 1057, Address: 0x1025210 */

  if (yPos > 16) { /* Line 1059, Address: 0x102521c */
    sv_move_plus(spdwk); /* Line 1060, Address: 0x1025234 */
  } else if (yPos < -16) { /* Line 1061, Address: 0x1025240 */
    sv_move_minus(spdwk); /* Line 1062, Address: 0x1025260 */
  } else { /* Line 1063, Address: 0x102526c */
    sv_move_sub(yPos); /* Line 1064, Address: 0x1025274 */
  }
} /* Line 1066, Address: 0x1025280 */














static void sv_move_sub(short yPos) { /* Line 1081, Address: 0x10252a0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1084, Address: 0x10252ac */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1085, Address: 0x10252b0 */
  if (yPos < 0) { /* Line 1086, Address: 0x10252dc */
    scrv_up_ch(lSpd); /* Line 1087, Address: 0x10252f0 */
  } else { /* Line 1088, Address: 0x10252fc */
    scrv_down_ch(lSpd); /* Line 1089, Address: 0x1025304 */
  }
} /* Line 1091, Address: 0x1025310 */



static void sv_move_sub2(void) { /* Line 1095, Address: 0x1025320 */
  limmoveflag = 0; /* Line 1096, Address: 0x1025328 */

  sv_move_sub(0); /* Line 1098, Address: 0x1025330 */
} /* Line 1099, Address: 0x102533c */













static void sv_move_minus(short speed) { /* Line 1113, Address: 0x1025350 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1116, Address: 0x102535c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1117, Address: 0x1025380 */
  scrv_up_ch(lSpd); /* Line 1118, Address: 0x10253a4 */
} /* Line 1119, Address: 0x10253b0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1134, Address: 0x10253c0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1135, Address: 0x10253cc */
    if (lSpd.w.l > -256) { /* Line 1136, Address: 0x10253f4 */

      lSpd.w.l = scralim_up; /* Line 1138, Address: 0x102540c */
    } else { /* Line 1139, Address: 0x1025418 */
      lSpd.w.l &= 2047; /* Line 1140, Address: 0x1025420 */
      actwk[0].yposi.w.h &= 2047; /* Line 1141, Address: 0x102542c */
      scra_v_posit.w.h &= 2047; /* Line 1142, Address: 0x1025440 */
      scrb_v_posit.w.h &= 1023; /* Line 1143, Address: 0x1025454 */
    }
  }

  scrv_move(lSpd); /* Line 1147, Address: 0x1025468 */
} /* Line 1148, Address: 0x1025474 */













static void sv_move_plus(short sSpd) { /* Line 1162, Address: 0x1025490 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1165, Address: 0x102549c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1166, Address: 0x10254bc */
  scrv_down_ch(lSpd); /* Line 1167, Address: 0x10254e0 */
} /* Line 1168, Address: 0x10254ec */














static void scrv_down_ch(int_union lSpd) { /* Line 1183, Address: 0x1025500 */
  if (lSpd.w.l >= scralim_down) { /* Line 1184, Address: 0x102550c */
    if (lSpd.w.l < 2048) { /* Line 1185, Address: 0x1025534 */

      lSpd.w.l = scralim_down; /* Line 1187, Address: 0x102554c */
    } else { /* Line 1188, Address: 0x1025558 */
      lSpd.w.l -= 2048; /* Line 1189, Address: 0x1025560 */
      actwk[0].yposi.w.h &= 2047; /* Line 1190, Address: 0x102556c */
      scra_v_posit.w.h -= 2048; /* Line 1191, Address: 0x1025580 */
      scrb_v_posit.w.h &= 1023; /* Line 1192, Address: 0x1025594 */
    }
  }

  scrv_move(lSpd); /* Line 1196, Address: 0x10255a8 */
} /* Line 1197, Address: 0x10255b4 */
















static void scrv_move(int_union lSpd) { /* Line 1214, Address: 0x10255d0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1218, Address: 0x10255e0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1219, Address: 0x10255f0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1220, Address: 0x1025614 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1221, Address: 0x1025628 */
  scra_vz = spdwk.w.l; /* Line 1222, Address: 0x1025640 */

  scra_v_posit.l = lSpd.l; /* Line 1224, Address: 0x102564c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1226, Address: 0x1025658 */
  if (!ywk) { /* Line 1227, Address: 0x1025694 */
    scra_v_count ^= 16; /* Line 1228, Address: 0x102569c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1229, Address: 0x10256b0 */
    if (ywk < 0) { /* Line 1230, Address: 0x10256dc */
      scrflaga.b.h |= 1; /* Line 1231, Address: 0x10256ec */
    } else { /* Line 1232, Address: 0x1025700 */
      scrflaga.b.h |= 2; /* Line 1233, Address: 0x1025708 */
    }
  }


} /* Line 1238, Address: 0x102571c */

















void scrollwrt(void) { /* Line 1256, Address: 0x1025730 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1265, Address: 0x1025750 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1266, Address: 0x1025754 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1267, Address: 0x1025760 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1268, Address: 0x102576c */
  pScrFlag = &scrflagbw.b.h; /* Line 1269, Address: 0x1025774 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1270, Address: 0x102577c */

  VramBase = 16384; /* Line 1272, Address: 0x1025790 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1273, Address: 0x1025794 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1274, Address: 0x10257a0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1275, Address: 0x10257ac */
  pScrFlag = &scrflagaw.b.h; /* Line 1276, Address: 0x10257b4 */

  if (*pScrFlag) { /* Line 1278, Address: 0x10257bc */
    if (*pScrFlag & 1) { /* Line 1279, Address: 0x10257c8 */
      *pScrFlag &= 254; /* Line 1280, Address: 0x10257dc */

      lD4.l = -16; /* Line 1282, Address: 0x10257e8 */
      wD5 = 65520; /* Line 1283, Address: 0x10257f0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1285, Address: 0x10257f8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1287, Address: 0x1025818 */
    }




    if (*pScrFlag & 2) { /* Line 1293, Address: 0x1025844 */
      *pScrFlag &= 253; /* Line 1294, Address: 0x1025858 */

      lD4.l = 224; /* Line 1296, Address: 0x1025864 */
      wD5 = 65520; /* Line 1297, Address: 0x102586c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1298, Address: 0x1025874 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1300, Address: 0x1025894 */
    }




    if (*pScrFlag & 4) { /* Line 1306, Address: 0x10258c0 */
      *pScrFlag &= 251; /* Line 1307, Address: 0x10258d4 */

      lD4.l = -16; /* Line 1309, Address: 0x10258e0 */
      wD5 = 65520; /* Line 1310, Address: 0x10258e8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1311, Address: 0x10258f0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1313, Address: 0x1025910 */
    }




    if (*pScrFlag & 8) { /* Line 1319, Address: 0x102593c */
      *pScrFlag &= 247; /* Line 1320, Address: 0x1025950 */

      lD4.l = -16; /* Line 1322, Address: 0x102595c */
      wD5 = 320; /* Line 1323, Address: 0x1025964 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1324, Address: 0x102596c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1326, Address: 0x102598c */
    }
  }






} /* Line 1335, Address: 0x10259b8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1352, Address: 0x10259e0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1363, Address: 0x1025a0c */

  if (*pScrFlag & 1) { /* Line 1365, Address: 0x1025a14 */
    *pScrFlag &= 254; /* Line 1366, Address: 0x1025a2c */
  } /* Line 1367, Address: 0x1025a40 */
  else {
    *pScrFlag &= 254; /* Line 1369, Address: 0x1025a48 */

    if (*pScrFlag & 2) { /* Line 1371, Address: 0x1025a5c */
      *pScrFlag &= 253; /* Line 1372, Address: 0x1025a74 */
      lD4.w.l = 224; /* Line 1373, Address: 0x1025a88 */
    } /* Line 1374, Address: 0x1025a90 */
    else {
      *pScrFlag &= 253; /* Line 1376, Address: 0x1025a98 */
      goto label1; /* Line 1377, Address: 0x1025aac */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1382, Address: 0x1025ab4 */
  wD0 &= 127; /* Line 1383, Address: 0x1025b04 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1384, Address: 0x1025b0c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1390, Address: 0x1025b2c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1391, Address: 0x1025b4c */
  if (wD0 != 0) { /* Line 1392, Address: 0x1025b70 */
    wD5 = 65520; /* Line 1393, Address: 0x1025b7c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1394, Address: 0x1025b84 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1396, Address: 0x1025ba4 */



  } /* Line 1400, Address: 0x1025bd0 */
  else {

    wD5 = 0; /* Line 1403, Address: 0x1025bd8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1404, Address: 0x1025bdc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1408, Address: 0x1025bfc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1415, Address: 0x1025c28 */






    lD4.l = -16; /* Line 1422, Address: 0x1025c3c */
    wD5 = 65520; /* Line 1423, Address: 0x1025c44 */
    if (*pScrFlag & 168) { /* Line 1424, Address: 0x1025c4c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1425, Address: 0x1025c64 */
      wD5 = 320; /* Line 1426, Address: 0x1025c84 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1430, Address: 0x1025c8c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1432, Address: 0x1025cbc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1433, Address: 0x1025cc8 */



    for (i = 0; i < 16; ++i) { /* Line 1437, Address: 0x1025cd8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1438, Address: 0x1025ce4 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1440, Address: 0x1025d04 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1441, Address: 0x1025d3c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1442, Address: 0x1025d5c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1444, Address: 0x1025d80 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1447, Address: 0x1025da4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1449, Address: 0x1025dc4 */
      }
      lD4.w.l += 16; /* Line 1451, Address: 0x1025dd8 */
    } /* Line 1452, Address: 0x1025de4 */
    *pScrFlag = 0; /* Line 1453, Address: 0x1025df4 */
  }
} /* Line 1455, Address: 0x1025dfc */





void scrollwrtc(void) {} /* Line 1461, Address: 0x1025e30 */




void scrollwrtz(void) {} /* Line 1466, Address: 0x1025e40 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1484, Address: 0x1025e50 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1497, Address: 0x1025e78 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1500, Address: 0x1025e98 */
    pTilePoint->x += 2; /* Line 1501, Address: 0x1025eac */
    if (pTilePoint->x >= 64) { /* Line 1502, Address: 0x1025ec0 */
      pTilePoint->x -= 64; /* Line 1503, Address: 0x1025ed4 */
    }
    xOffs += 16; /* Line 1505, Address: 0x1025ee8 */
  } while (--lpcnt >= 0); /* Line 1506, Address: 0x1025ef4 */
} /* Line 1507, Address: 0x1025f08 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1511, Address: 0x1025f20 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1515, Address: 0x1025f48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1518, Address: 0x1025f68 */
    pTilePoint->x += 2; /* Line 1519, Address: 0x1025f7c */
    if (pTilePoint->x >= 64) { /* Line 1520, Address: 0x1025f90 */
      pTilePoint->x -= 64; /* Line 1521, Address: 0x1025fa4 */
    }
    xOffs += 16; /* Line 1523, Address: 0x1025fb8 */
  } while (--lpcnt >= 0); /* Line 1524, Address: 0x1025fc4 */
} /* Line 1525, Address: 0x1025fd8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1545, Address: 0x1025ff0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1549, Address: 0x1026018 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1552, Address: 0x1026038 */
    pTilePoint->y += 2; /* Line 1553, Address: 0x102604c */
    if (pTilePoint->y >= 32) { /* Line 1554, Address: 0x102605c */
      pTilePoint->y -= 32; /* Line 1555, Address: 0x1026070 */
    }
    yOffs += 16; /* Line 1557, Address: 0x1026080 */
  } while (--lpcnt >= 0); /* Line 1558, Address: 0x102608c */
} /* Line 1559, Address: 0x10260a0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1578, Address: 0x10260b0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1584, Address: 0x10260e4 */

    base = 1; /* Line 1586, Address: 0x10260f4 */
  } /* Line 1587, Address: 0x10260f8 */
  else if (VramBase == 16384) { /* Line 1588, Address: 0x1026100 */

    base = 0; /* Line 1590, Address: 0x1026110 */
  }
  x = pTilePoint->x; /* Line 1592, Address: 0x1026114 */
  y = pTilePoint->y; /* Line 1593, Address: 0x102611c */


  frip = BlkIndex & 6144; /* Line 1596, Address: 0x1026124 */
  BlkIndex &= 1023; /* Line 1597, Address: 0x102612c */
  if (frip == 6144) { /* Line 1598, Address: 0x1026138 */

    p0 = 3, p1 = 2; /* Line 1600, Address: 0x1026144 */
    p2 = 1, p3 = 0; /* Line 1601, Address: 0x102614c */
  } /* Line 1602, Address: 0x1026154 */
  else if (frip & 4096) { /* Line 1603, Address: 0x102615c */

    p0 = 2, p1 = 3; /* Line 1605, Address: 0x1026168 */
    p2 = 0, p3 = 1; /* Line 1606, Address: 0x1026170 */
  } /* Line 1607, Address: 0x1026178 */
  else if (frip & 2048) { /* Line 1608, Address: 0x1026180 */

    p0 = 1, p1 = 0; /* Line 1610, Address: 0x102618c */
    p2 = 3, p3 = 2; /* Line 1611, Address: 0x1026194 */
  } /* Line 1612, Address: 0x102619c */
  else {

    p0 = 0, p1 = 1; /* Line 1615, Address: 0x10261a4 */
    p2 = 2, p3 = 3; /* Line 1616, Address: 0x10261ac */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1619, Address: 0x10261b4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1620, Address: 0x10261f8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1621, Address: 0x102623c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1622, Address: 0x1026280 */

} /* Line 1624, Address: 0x10262c4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1642, Address: 0x1026300 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1643, Address: 0x1026320 */
} /* Line 1644, Address: 0x1026340 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1646, Address: 0x1026350 */
  wH_posiw = 0; /* Line 1647, Address: 0x1026370 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1648, Address: 0x1026374 */
} /* Line 1649, Address: 0x1026394 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1656, Address: 0x10263b0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1662, Address: 0x10263e0 */
  yOffs += wV_posiw; /* Line 1663, Address: 0x10263f0 */





  if ((short)xOffs < 0) /* Line 1669, Address: 0x1026400 */
    xOffs = 0; /* Line 1670, Address: 0x102641c */
  if ((short)yOffs < 0) /* Line 1671, Address: 0x1026420 */
    yOffs = 0; /* Line 1672, Address: 0x102643c */
  if ((short)xOffs >= 16384) /* Line 1673, Address: 0x1026440 */
    xOffs = 16383; /* Line 1674, Address: 0x1026460 */
  if ((short)yOffs >= 2048) /* Line 1675, Address: 0x1026468 */
    yOffs = 2047; /* Line 1676, Address: 0x1026488 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1677, Address: 0x1026490 */
  if (i < 0) i = 0; /* Line 1678, Address: 0x10264d8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1680, Address: 0x10264e4 */

  if (ScreenNo) { /* Line 1682, Address: 0x1026500 */




    xOffs &= 32767; /* Line 1687, Address: 0x1026508 */
    yOffs &= 32767; /* Line 1688, Address: 0x1026514 */


    xBlk = xOffs; /* Line 1691, Address: 0x1026520 */
    xBlk %= 256; /* Line 1692, Address: 0x1026528 */
    xBlk /= 16; /* Line 1693, Address: 0x1026548 */
    yBlk = yOffs; /* Line 1694, Address: 0x1026564 */
    yBlk %= 256; /* Line 1695, Address: 0x102656c */
    yBlk /= 16; /* Line 1696, Address: 0x102658c */

    lpw = pmapwk; /* Line 1698, Address: 0x10265a8 */
    lpw += xBlk; /* Line 1699, Address: 0x10265b0 */
    lpw += yBlk * 16; /* Line 1700, Address: 0x10265b8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1701, Address: 0x10265c4 */
    *pIndex = *lpw; /* Line 1702, Address: 0x10265dc */

    return 1; /* Line 1704, Address: 0x10265ec */
  }

  *pIndex = 0; /* Line 1707, Address: 0x10265f8 */
  return 0; /* Line 1708, Address: 0x1026600 */
} /* Line 1709, Address: 0x1026604 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1729, Address: 0x1026630 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1737, Address: 0x1026658 */
  if (ScreenNo) { /* Line 1738, Address: 0x10266bc */





    xBlk = xOffs; /* Line 1744, Address: 0x10266c4 */
    xBlk %= 256; /* Line 1745, Address: 0x10266cc */
    xBlk /= 16; /* Line 1746, Address: 0x10266ec */
    yBlk = yOffs; /* Line 1747, Address: 0x1026708 */
    yBlk %= 256; /* Line 1748, Address: 0x1026710 */
    yBlk /= 16; /* Line 1749, Address: 0x1026730 */


    lpw = pmapwk; /* Line 1752, Address: 0x102674c */
    lpw += xBlk; /* Line 1753, Address: 0x1026754 */
    lpw += yBlk * 16; /* Line 1754, Address: 0x102675c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1755, Address: 0x1026768 */
    *ppBlockNo = lpw; /* Line 1756, Address: 0x1026780 */
    *pIndex = *lpw; /* Line 1757, Address: 0x1026788 */




    return 1; /* Line 1762, Address: 0x1026798 */
  }

  *pIndex = 0; /* Line 1765, Address: 0x10267a4 */
  return 0; /* Line 1766, Address: 0x10267ac */
} /* Line 1767, Address: 0x10267b0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1781, Address: 0x10267d0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1788, Address: 0x10267ec */
  pMapWk = (unsigned char*)mapwka; /* Line 1789, Address: 0x10267f0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1790, Address: 0x10267f8 */
    *pBlockIndex = BlockNo; /* Line 1791, Address: 0x102681c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1792, Address: 0x1026828 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1793, Address: 0x1026840 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1794, Address: 0x1026854 */
    }
  }


} /* Line 1799, Address: 0x102686c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1813, Address: 0x1026890 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1814, Address: 0x102689c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1815, Address: 0x10268c8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1816, Address: 0x1026914 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1817, Address: 0x1026940 */

          return 0; /* Line 1819, Address: 0x102698c */
        }
      }
    }
  }

  return 1; /* Line 1825, Address: 0x1026998 */
} /* Line 1826, Address: 0x102699c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1843, Address: 0x10269b0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1844, Address: 0x10269cc */

} /* Line 1846, Address: 0x10269e8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1848, Address: 0x1026a00 */
  wH_posiw = 0; /* Line 1849, Address: 0x1026a1c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1850, Address: 0x1026a20 */

} /* Line 1852, Address: 0x1026a3c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1854, Address: 0x1026a50 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1855, Address: 0x1026a64 */

} /* Line 1857, Address: 0x1026a80 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1859, Address: 0x1026a90 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1860, Address: 0x1026aac */

} /* Line 1862, Address: 0x1026ac8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1864, Address: 0x1026ae0 */
  xOffs += wH_posiw; /* Line 1865, Address: 0x1026af8 */
  yOffs += wV_posiw; /* Line 1866, Address: 0x1026b08 */
  yOffs &= 240; /* Line 1867, Address: 0x1026b18 */
  xOffs &= 496; /* Line 1868, Address: 0x1026b24 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1870, Address: 0x1026b30 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1871, Address: 0x1026b5c */


} /* Line 1874, Address: 0x1026b88 */















void mapwrt(void) { /* Line 1890, Address: 0x1026ba0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1895, Address: 0x1026bb8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1896, Address: 0x1026bc4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1897, Address: 0x1026bd0 */
  VramBase = 16384; /* Line 1898, Address: 0x1026bd8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1899, Address: 0x1026bdc */
  mapwrtb(); /* Line 1900, Address: 0x1026bf4 */
} /* Line 1901, Address: 0x1026bfc */


void mapwrtb(void) { /* Line 1904, Address: 0x1026c20 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1909, Address: 0x1026c38 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1910, Address: 0x1026c44 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1911, Address: 0x1026c50 */
  VramBase = 24576; /* Line 1912, Address: 0x1026c58 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1913, Address: 0x1026c5c */

} /* Line 1915, Address: 0x1026c6c */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1918, Address: 0x1026c90 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1919, Address: 0x1026ca8 */
} /* Line 1920, Address: 0x1026cc8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1925, Address: 0x1026ce0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1929, Address: 0x1026d00 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1932, Address: 0x1026d1c */



    wD4 += 16; /* Line 1936, Address: 0x1026d44 */
  } while ((short)--wD6 >= 0); /* Line 1937, Address: 0x1026d50 */

} /* Line 1939, Address: 0x1026d78 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1945, Address: 0x1026d90 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1948, Address: 0x1026dac */
  wD6 = 15; /* Line 1949, Address: 0x1026db4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1952, Address: 0x1026dbc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1954, Address: 0x1026de0 */
    wD4 += 16; /* Line 1955, Address: 0x1026e00 */
  } while ((short)--wD6 >= 0); /* Line 1956, Address: 0x1026e08 */
} /* Line 1957, Address: 0x1026e2c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1983, Address: 0x1026e50 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1988, Address: 0x1026e78 */
  wD0 = pWrttbl[wD0]; /* Line 1989, Address: 0x1026e88 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1991, Address: 0x1026ea4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1992, Address: 0x1026ec8 */
  if (wD0) { /* Line 1993, Address: 0x1026ef0 */
    wD5 = 65520; /* Line 1994, Address: 0x1026efc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1995, Address: 0x1026f04 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1998, Address: 0x1026f20 */



  } /* Line 2002, Address: 0x1026f48 */
  else {

    wD5 = 0; /* Line 2005, Address: 0x1026f50 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2006, Address: 0x1026f54 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2010, Address: 0x1026f70 */
  }





} /* Line 2017, Address: 0x1026f98 */










void mapinit(void) { /* Line 2028, Address: 0x1026fc0 */
  short tbl[9] = { /* Line 2029, Address: 0x1026fe0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2034, Address: 0x102700c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2040, Address: 0x1027030 */
  pTbl = tbl; /* Line 2041, Address: 0x1027034 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2043, Address: 0x1027038 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2044, Address: 0x1027040 */


    ++EnkeiNo; /* Line 2047, Address: 0x1027064 */
  } /* Line 2048, Address: 0x1027068 */


  TileNo = 592; /* Line 2051, Address: 0x102708c */
  if (EnkeiNo == 0) { /* Line 2052, Address: 0x1027090 */
    i = 95; /* Line 2053, Address: 0x1027098 */
    BmpNo = 0; /* Line 2054, Address: 0x102709c */

    for ( ; i > 0; --i) { /* Line 2056, Address: 0x10270a0 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2057, Address: 0x10270a8 */
    } /* Line 2058, Address: 0x10270c8 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2062, Address: 0x10270d4 */
  colorset(mapinittbl.colorno2); /* Line 2063, Address: 0x10270e8 */


  if (play_start & 2) divdevset(); /* Line 2066, Address: 0x10270fc */
} /* Line 2067, Address: 0x102711c */




void mapset(void) {} /* Line 2072, Address: 0x1027150 */



void divdevset() {} /* Line 2076, Address: 0x1027160 */



void enecginit(void) {} /* Line 2080, Address: 0x1027170 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2096, Address: 0x1027180 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2100, Address: 0x10271a0 */
  h = *pZonetbl++; /* Line 2101, Address: 0x10271b8 */
  v = *pZonetbl++; /* Line 2102, Address: 0x10271c8 */
  for ( ;v >= 0; --v) { /* Line 2103, Address: 0x10271d8 */
    pMapwk = pMapDst; /* Line 2104, Address: 0x10271e0 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2106, Address: 0x10271e4 */
      *pMapwk++ = *pZonetbl++; /* Line 2107, Address: 0x10271f0 */
    } /* Line 2108, Address: 0x1027208 */

    pMapDst += 64; /* Line 2110, Address: 0x1027214 */
  } /* Line 2111, Address: 0x1027220 */
} /* Line 2112, Address: 0x102722c */
