#include "..\EQU.H"
#include "SCR51A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51bline0(short** ppHscw);
static void z51bline1(short** ppHscw);
static void z51bline2(short** ppHscw);
static void z51bline3(short** ppHscw);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_v(short yPos);
static void scrollb_h(int xoffs, int flgbit);
static void scrollc_h(int xoffs, int flgbit);
static void scrollz_h(int xoffs, int flgbit);
static void scroll_h();
static void scrh_move();
static void scroll_v();
static void sv_move_main(short yPos);
static void sv_move_main2(short yPos);
static void sv_move_sub(short yPos);
static void sv_move_sub2();
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
unsigned char playmapnotbl[4] = { 127, 127, 9, 127 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg() { /* Line 154, Address: 0x1023b60 */
  short tbl[9] = { /* Line 155, Address: 0x1023b80 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 160, Address: 0x1023bac */
    2, 4, 2
  };
  int EnkeiNo, i, BmpNo, TileNo;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 166, Address: 0x1023bd0 */



  EnkeiNo = 0; /* Line 170, Address: 0x1023be0 */
  pTbl = tbl; /* Line 171, Address: 0x1023be4 */

  while ((poswk = *pTbl++) >= 0) { /* Line 173, Address: 0x1023be8 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 174, Address: 0x1023bf0 */


    ++EnkeiNo; /* Line 177, Address: 0x1023c14 */
  } /* Line 178, Address: 0x1023c18 */


  if (enkeino == EnkeiNo) return; /* Line 181, Address: 0x1023c3c */




  enkeino = EnkeiNo; /* Line 186, Address: 0x1023c50 */


  TileNo = 523; /* Line 189, Address: 0x1023c5c */
  if (EnkeiNo == 1) { /* Line 190, Address: 0x1023c60 */
    i = 175; /* Line 191, Address: 0x1023c6c */
    BmpNo = 168; /* Line 192, Address: 0x1023c70 */
  } else { /* Line 193, Address: 0x1023c74 */
    i = 168; /* Line 194, Address: 0x1023c7c */
    BmpNo = 0; /* Line 195, Address: 0x1023c80 */
  }
  for ( ; i > 0; --i) { /* Line 197, Address: 0x1023c84 */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 198, Address: 0x1023c8c */
  } /* Line 199, Address: 0x1023cac */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 201, Address: 0x1023cb8 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 202, Address: 0x1023cd8 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 204, Address: 0x1023cf8 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 205, Address: 0x1023d30 */
  mapwrt_cnt = 1; /* Line 206, Address: 0x1023d48 */
} /* Line 207, Address: 0x1023d54 */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 221, Address: 0x1023d80 */
    return &actwk[0]; /* Line 222, Address: 0x1023d94 */
  else
    return &actwk[1]; /* Line 224, Address: 0x1023da4 */

} /* Line 226, Address: 0x1023dac */





































void scr_set() { /* Line 264, Address: 0x1023dc0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 267, Address: 0x1023dcc */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 268, Address: 0x1023de0 */
  scr_timer.b.h = 0; /* Line 269, Address: 0x1023df4 */

  pScrTbl = scr_dir_tbl; /* Line 271, Address: 0x1023dfc */
  scrar_no = *pScrTbl; /* Line 272, Address: 0x1023e04 */
  ++pScrTbl; /* Line 273, Address: 0x1023e10 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 274, Address: 0x1023e14 */
  ++pScrTbl; /* Line 275, Address: 0x1023e28 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 276, Address: 0x1023e2c */
  ++pScrTbl; /* Line 277, Address: 0x1023e40 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 278, Address: 0x1023e44 */
  ++pScrTbl; /* Line 279, Address: 0x1023e58 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 280, Address: 0x1023e5c */
  scra_h_keep = *pScrTbl + 576; /* Line 281, Address: 0x1023e70 */
  ++pScrTbl; /* Line 282, Address: 0x1023e90 */
  scra_h_count = 16; /* Line 283, Address: 0x1023e94 */
  scra_v_count = 16; /* Line 284, Address: 0x1023ea0 */

  scra_vline = *pScrTbl; /* Line 286, Address: 0x1023eac */
  scra_hline = 160; /* Line 287, Address: 0x1023eb8 */

  playposiset(); /* Line 289, Address: 0x1023ec4 */
} /* Line 290, Address: 0x1023ecc */






































static void playposiset() { /* Line 329, Address: 0x1023ee0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 332, Address: 0x1023ef4 */
    playload(); /* Line 333, Address: 0x1023f04 */
    xwk = actwk[0].xposi.w.h; /* Line 334, Address: 0x1023f0c */

    if (actwk[0].yposi.w.h > 0) { /* Line 336, Address: 0x1023f1c */
      ywk = actwk[0].yposi.w.h; /* Line 337, Address: 0x1023f34 */
    } else { /* Line 338, Address: 0x1023f44 */
      ywk = 0; /* Line 339, Address: 0x1023f4c */
    }
  } /* Line 341, Address: 0x1023f50 */
  else {
    pPositbl = playpositbl[0]; /* Line 343, Address: 0x1023f58 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 346, Address: 0x1023f60 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 347, Address: 0x1023f74 */
  }


  if (xwk > 160) { /* Line 351, Address: 0x1023f88 */
    xwk -= 160; /* Line 352, Address: 0x1023f9c */
  } else { /* Line 353, Address: 0x1023fa8 */
    xwk = 0; /* Line 354, Address: 0x1023fb0 */
  }


  if (xwk > scralim_right) { /* Line 358, Address: 0x1023fb4 */
    xwk = scralim_right; /* Line 359, Address: 0x1023fd8 */
  }


  scra_h_posit.w.h = xwk; /* Line 363, Address: 0x1023fe8 */

  if (ywk > 96) { /* Line 365, Address: 0x1023ff0 */
    ywk -= 96; /* Line 366, Address: 0x1024004 */
  } else { /* Line 367, Address: 0x1024010 */
    ywk = 0; /* Line 368, Address: 0x1024018 */
  }


  if (ywk > scralim_down) { /* Line 372, Address: 0x102401c */
    ywk = scralim_down; /* Line 373, Address: 0x1024040 */
  }


  scra_v_posit.w.h = ywk; /* Line 377, Address: 0x1024050 */

  scrbinit(xwk, ywk); /* Line 379, Address: 0x1024058 */


  loopmapno = playmapnotbl[0]; /* Line 382, Address: 0x1024068 */
  loopmapno2 = playmapnotbl[1]; /* Line 383, Address: 0x1024078 */
  ballmapno = playmapnotbl[2]; /* Line 384, Address: 0x1024088 */
  ballmapno2 = playmapnotbl[3]; /* Line 385, Address: 0x1024098 */
} /* Line 386, Address: 0x10240a8 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 407, Address: 0x10240d0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 410, Address: 0x10240dc */
  lYwk.w.l = 0; /* Line 411, Address: 0x10240e4 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 413, Address: 0x10240e8 */
  lYwk.l += lYwk.l >> 1; /* Line 414, Address: 0x10240f4 */

  scrb_v_posit.l = lYwk.l; /* Line 416, Address: 0x1024108 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 417, Address: 0x1024114 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 418, Address: 0x1024120 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 420, Address: 0x102412c */
  scrb_h_posit.w.h = sXpos + (sXpos >> 1); /* Line 421, Address: 0x1024148 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 423, Address: 0x1024178 */
  scrc_h_posit.w.h = sXpos; /* Line 424, Address: 0x1024194 */

  sXpos >>= 2; /* Line 426, Address: 0x10241a0 */
  scrz_h_posit.w.h = sXpos * 3; /* Line 427, Address: 0x10241ac */
} /* Line 428, Address: 0x10241d0 */















void scroll() { /* Line 444, Address: 0x10241e0 */
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

  if (scroll_start.b.h) return; /* Line 456, Address: 0x10241fc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 461, Address: 0x102420c */

  scrchk(); /* Line 463, Address: 0x1024238 */

  scroll_h(); /* Line 465, Address: 0x1024240 */
  scroll_v(); /* Line 466, Address: 0x1024248 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 468, Address: 0x1024250 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 469, Address: 0x1024260 */


  lXwk = scra_hz * 16 * 3; /* Line 472, Address: 0x1024270 */
  scrollz_h(lXwk, 6); /* Line 473, Address: 0x102428c */

  lXwk = scra_hz * 64; /* Line 475, Address: 0x102429c */
  scrollc_h(lXwk, 4); /* Line 476, Address: 0x10242b0 */

  lXwk = scra_hz * 64; /* Line 478, Address: 0x10242c0 */
  lXwk += lXwk * 2; /* Line 479, Address: 0x10242d4 */
  scrollb_h(lXwk, 2); /* Line 480, Address: 0x10242dc */

  lYwk = (unsigned int)scra_v_posit.l >> 3; /* Line 482, Address: 0x10242ec */
  lYwk += lYwk >> 1; /* Line 483, Address: 0x10242f8 */
  lYwk = (unsigned int)lYwk >> 16 & 65535 | lYwk << 16 & -65536; /* Line 484, Address: 0x1024300 */


  scrollb_v(lYwk); /* Line 487, Address: 0x1024318 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 489, Address: 0x1024328 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 490, Address: 0x1024350 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 491, Address: 0x1024388 */

  psHscw = hscrollwork; /* Line 493, Address: 0x102439c */

  if (enkeino & 1) { /* Line 495, Address: 0x10243a8 */

    z51bline2(&psHscw); /* Line 497, Address: 0x10243c0 */
    z51bline3(&psHscw); /* Line 498, Address: 0x10243cc */
    ldwk.w.l = -scrb_h_posit.w.h; /* Line 499, Address: 0x10243d8 */
    for (i = 0; i < 18; ++i) { /* Line 500, Address: 0x10243f8 */

      *psHscw++ = ldwk.w.l; /* Line 502, Address: 0x1024404 */
    } /* Line 503, Address: 0x1024418 */
  } /* Line 504, Address: 0x1024428 */
  else {
    z51bline0(&psHscw); /* Line 506, Address: 0x1024430 */
    z51bline1(&psHscw); /* Line 507, Address: 0x102443c */
  }


  pHscrbuf = lphscrollbuff; /* Line 511, Address: 0x1024448 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 512, Address: 0x1024454 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 513, Address: 0x1024484 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 514, Address: 0x10244b4 */
} /* Line 515, Address: 0x10244d0 */













static void z51bline0(short** ppHscw) { /* Line 529, Address: 0x1024500 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl0[4] = { /* Line 534, Address: 0x1024518 */
    7, 3, 1, 5
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 538, Address: 0x1024544 */
  lHwk = (unsigned int)lHwk * 64 / 8; /* Line 539, Address: 0x1024568 */
  lHwk *= 1024; /* Line 540, Address: 0x1024574 */

  ldHposwk.l = 0; /* Line 542, Address: 0x1024578 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 543, Address: 0x102457c */
  *ppHscw += 20; /* Line 544, Address: 0x1024588 */

  for (i = 3; i >= 0; --i) { /* Line 546, Address: 0x102459c */

    wk = -ldHposwk.w.l; /* Line 548, Address: 0x10245a8 */

    for (j = z51bscrtbl0[i]; j >= 0; --j) { /* Line 550, Address: 0x10245c8 */

      --*ppHscw; /* Line 552, Address: 0x10245e0 */
      **ppHscw = wk; /* Line 553, Address: 0x10245f4 */
    } /* Line 554, Address: 0x1024600 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 556, Address: 0x102460c */
    ldHposwk.l += lHwk; /* Line 557, Address: 0x1024630 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 558, Address: 0x102463c */
  } /* Line 559, Address: 0x1024660 */
  *ppHscw += 20; /* Line 560, Address: 0x102466c */
} /* Line 561, Address: 0x1024680 */













static void z51bline1(short** ppHscw) { /* Line 575, Address: 0x10246a0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl1[12] = { /* Line 580, Address: 0x10246b8 */
    1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 0, 6
  };


  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 585, Address: 0x10246ec */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 586, Address: 0x1024710 */
  lHwk *= 1024; /* Line 587, Address: 0x102472c */

  ldHposwk.l = 0; /* Line 589, Address: 0x1024730 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 590, Address: 0x1024734 */

  for (i = 11; i >= 0; --i) { /* Line 592, Address: 0x1024740 */

    wk = -ldHposwk.w.l; /* Line 594, Address: 0x102474c */

    for (j = z51bscrtbl1[i]; j >= 0; --j) { /* Line 596, Address: 0x102476c */

      **ppHscw = wk; /* Line 598, Address: 0x1024784 */
      ++*ppHscw; /* Line 599, Address: 0x1024790 */
    } /* Line 600, Address: 0x10247a4 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 602, Address: 0x10247b0 */
    ldHposwk.l += lHwk; /* Line 603, Address: 0x10247d4 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 604, Address: 0x10247e0 */
  } /* Line 605, Address: 0x1024804 */
} /* Line 606, Address: 0x1024810 */













static void z51bline2(short** ppHscw) { /* Line 620, Address: 0x1024830 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl2[4] = { /* Line 625, Address: 0x1024848 */
    3, 1, 1, 4
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 629, Address: 0x1024874 */
  lHwk = (unsigned int)lHwk * 64 / 8; /* Line 630, Address: 0x1024898 */
  lHwk *= 1024; /* Line 631, Address: 0x10248a4 */

  ldHposwk.l = 0; /* Line 633, Address: 0x10248a8 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 634, Address: 0x10248ac */
  *ppHscw += 13; /* Line 635, Address: 0x10248b8 */

  for (i = 3; i >= 0; --i) { /* Line 637, Address: 0x10248cc */

    wk = -ldHposwk.w.l; /* Line 639, Address: 0x10248d8 */

    for (j = z51bscrtbl2[i]; j >= 0; --j) { /* Line 641, Address: 0x10248f8 */

      --*ppHscw; /* Line 643, Address: 0x1024910 */
      **ppHscw = wk; /* Line 644, Address: 0x1024924 */
    } /* Line 645, Address: 0x1024930 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 647, Address: 0x102493c */
    ldHposwk.l += lHwk; /* Line 648, Address: 0x1024960 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 649, Address: 0x102496c */
  } /* Line 650, Address: 0x1024990 */
  *ppHscw += 13; /* Line 651, Address: 0x102499c */
} /* Line 652, Address: 0x10249b0 */













static void z51bline3(short** ppHscw) { /* Line 666, Address: 0x10249d0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl3[10] = { /* Line 671, Address: 0x10249e8 */
    0, 2, 0, 2, 0, 2, 1, 1, 1, 2
  };


  lHwk = scrb_h_posit.w.h - scrc_h_posit.w.h; /* Line 676, Address: 0x1024a1c */
  lHwk = (unsigned int)lHwk * 64 / 14; /* Line 677, Address: 0x1024a40 */
  lHwk *= 1024; /* Line 678, Address: 0x1024a5c */

  ldHposwk.l = 0; /* Line 680, Address: 0x1024a60 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 681, Address: 0x1024a64 */

  for (i = 9; i >= 0; --i) { /* Line 683, Address: 0x1024a70 */

    wk = -ldHposwk.w.l; /* Line 685, Address: 0x1024a7c */

    for (j = z51bscrtbl3[i]; j >= 0; --j) { /* Line 687, Address: 0x1024a9c */

      **ppHscw = wk; /* Line 689, Address: 0x1024ab4 */
      ++*ppHscw; /* Line 690, Address: 0x1024ac0 */
    } /* Line 691, Address: 0x1024ad4 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 693, Address: 0x1024ae0 */
    ldHposwk.l += lHwk; /* Line 694, Address: 0x1024b04 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 695, Address: 0x1024b10 */
  } /* Line 696, Address: 0x1024b34 */
} /* Line 697, Address: 0x1024b40 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 718, Address: 0x1024b60 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 722, Address: 0x1024b7c */
  ldwk.w.h = -scrb_h_posit.w.h; /* Line 723, Address: 0x1024b80 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 725, Address: 0x1024ba0 */
    ldwk.w.l = *pHscrwk; /* Line 726, Address: 0x1024bbc */
    ++pHscrwk; /* Line 727, Address: 0x1024bc8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 729, Address: 0x1024bd4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 730, Address: 0x1024bdc */
    } /* Line 731, Address: 0x1024bec */
  } /* Line 732, Address: 0x1024c10 */
} /* Line 733, Address: 0x1024c30 */









































































































static void scrollb_v(short yPos) { /* Line 839, Address: 0x1024c50 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 842, Address: 0x1024c60 */
  scrb_v_posit.w.h = yPos; /* Line 843, Address: 0x1024c70 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 844, Address: 0x1024c7c */

  if (!ywk) { /* Line 846, Address: 0x1024cb4 */
    scrb_v_count ^= 16; /* Line 847, Address: 0x1024cbc */
    if (yPos - ysv < 0) { /* Line 848, Address: 0x1024cd0 */
      scrflagb.b.h |= 1; /* Line 849, Address: 0x1024cf0 */
    } /* Line 850, Address: 0x1024d04 */
    else {
      scrflagb.b.h |= 2; /* Line 852, Address: 0x1024d0c */
    }
  }


} /* Line 857, Address: 0x1024d20 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 875, Address: 0x1024d40 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 879, Address: 0x1024d54 */
  lXwk = lXsv + xoffs; /* Line 880, Address: 0x1024d5c */
  scrb_h_posit.l = lXwk; /* Line 881, Address: 0x1024d64 */
  ldXwk.l = lXwk; /* Line 882, Address: 0x1024d6c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 883, Address: 0x1024d70 */
  ldXwk.w.l &= 16; /* Line 884, Address: 0x1024d94 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 885, Address: 0x1024da0 */

  if (!ldXwk.b.b4) { /* Line 887, Address: 0x1024dbc */
    scrb_h_count ^= 16; /* Line 888, Address: 0x1024dc8 */
    if (lXwk - lXsv < 0) { /* Line 889, Address: 0x1024ddc */
      scrflagb.b.h |= 1 << flgbit; /* Line 890, Address: 0x1024de8 */
    } /* Line 891, Address: 0x1024e0c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 893, Address: 0x1024e14 */
    }
  }


} /* Line 898, Address: 0x1024e3c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 916, Address: 0x1024e50 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 920, Address: 0x1024e64 */
  lXwk = lXsv + xoffs; /* Line 921, Address: 0x1024e6c */
  scrc_h_posit.l = lXwk; /* Line 922, Address: 0x1024e74 */
  ldXwk.l = lXwk; /* Line 923, Address: 0x1024e7c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 924, Address: 0x1024e80 */
  ldXwk.w.l &= 16; /* Line 925, Address: 0x1024ea4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 926, Address: 0x1024eb0 */

  if (!ldXwk.b.b4) { /* Line 928, Address: 0x1024ecc */
    scrc_h_count ^= 16; /* Line 929, Address: 0x1024ed8 */
    if (lXwk - lXsv < 0) { /* Line 930, Address: 0x1024eec */
      scrflagc.b.h |= 1 << flgbit; /* Line 931, Address: 0x1024ef8 */
    } /* Line 932, Address: 0x1024f1c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 934, Address: 0x1024f24 */
    }
  }


} /* Line 939, Address: 0x1024f4c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 957, Address: 0x1024f60 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 961, Address: 0x1024f74 */
  lXwk = lXsv + xoffs; /* Line 962, Address: 0x1024f7c */
  scrz_h_posit.l = lXwk; /* Line 963, Address: 0x1024f84 */
  ldXwk.l = lXwk; /* Line 964, Address: 0x1024f8c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 965, Address: 0x1024f90 */
  ldXwk.w.l &= 16; /* Line 966, Address: 0x1024fb4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 967, Address: 0x1024fc0 */

  if (!ldXwk.b.b4) { /* Line 969, Address: 0x1024fdc */
    scrz_h_count ^= 16; /* Line 970, Address: 0x1024fe8 */
    if (lXwk - lXsv < 0) { /* Line 971, Address: 0x1024ffc */
      scrflagz.b.h |= 1 << flgbit; /* Line 972, Address: 0x1025008 */
    } /* Line 973, Address: 0x102502c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 975, Address: 0x1025034 */
    }
  }


} /* Line 980, Address: 0x102505c */














static void scroll_h() { /* Line 995, Address: 0x1025070 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 999, Address: 0x1025080 */

  scrh_move(); /* Line 1001, Address: 0x1025090 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 1002, Address: 0x1025098 */
  if (!bXwk) { /* Line 1003, Address: 0x10250cc */
    scra_h_count ^= 16; /* Line 1004, Address: 0x10250d4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 1005, Address: 0x10250e8 */
      scrflaga.b.h |= 4; /* Line 1006, Address: 0x102510c */
    } else { /* Line 1007, Address: 0x1025120 */
      scrflaga.b.h |= 8; /* Line 1008, Address: 0x1025128 */
    }
  }


} /* Line 1013, Address: 0x102513c */
















static void scrh_move() { /* Line 1030, Address: 0x1025160 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 1033, Address: 0x1025168 */
  if (xwk == 0) { /* Line 1034, Address: 0x10251b0 */

    scra_hz = 0; /* Line 1036, Address: 0x10251c0 */
    return; /* Line 1037, Address: 0x10251c8 */
  } else if (xwk < 0) { /* Line 1038, Address: 0x10251d0 */

    if (xwk < -16) { /* Line 1040, Address: 0x10251e0 */
      xwk = -16; /* Line 1041, Address: 0x10251f4 */
    }


    xwk += scra_h_posit.w.h; /* Line 1045, Address: 0x1025200 */
    if (xwk < scralim_left) { /* Line 1046, Address: 0x1025214 */
      xwk = scralim_left; /* Line 1047, Address: 0x1025238 */
    }
  } /* Line 1049, Address: 0x1025248 */
  else {
    if (xwk > 16) { /* Line 1051, Address: 0x1025250 */
      xwk = 16; /* Line 1052, Address: 0x1025264 */
    }


    xwk += scra_h_posit.w.h; /* Line 1056, Address: 0x1025270 */
    if (xwk > scralim_right) { /* Line 1057, Address: 0x1025284 */
      xwk = scralim_right; /* Line 1058, Address: 0x10252a8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1063, Address: 0x10252b8 */
  scra_h_posit.w.h = xwk; /* Line 1064, Address: 0x10252e8 */
} /* Line 1065, Address: 0x10252f0 */














static void scroll_v() { /* Line 1080, Address: 0x1025300 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1083, Address: 0x102530c */
  if (actwk[0].cddat & 4) { /* Line 1084, Address: 0x1025340 */
    ywk -= 5; /* Line 1085, Address: 0x1025358 */
  }


  if (actwk[0].cddat & 2) { /* Line 1089, Address: 0x1025364 */
    ywk += 32; /* Line 1090, Address: 0x102537c */
    if (ywk < scra_vline) { /* Line 1091, Address: 0x1025388 */
      ywk -= scra_vline; /* Line 1092, Address: 0x10253ac */
      sv_move_main2(ywk); /* Line 1093, Address: 0x10253c0 */
      return; /* Line 1094, Address: 0x10253cc */
    } else if (ywk >= scra_vline + 64) { /* Line 1095, Address: 0x10253d4 */
      ywk -= scra_vline + 64; /* Line 1096, Address: 0x10253fc */
      sv_move_main2(ywk); /* Line 1097, Address: 0x1025424 */
      return; /* Line 1098, Address: 0x1025430 */
    }
    ywk -= scra_vline + 64; /* Line 1100, Address: 0x1025438 */
    if (!limmoveflag) goto label1; /* Line 1101, Address: 0x1025460 */
    sv_move_sub2(); /* Line 1102, Address: 0x1025470 */
    return; /* Line 1103, Address: 0x1025478 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1108, Address: 0x1025480 */
    sv_move_main(ywk); /* Line 1109, Address: 0x10254ac */
    return; /* Line 1110, Address: 0x10254b8 */
  } else if (!limmoveflag) goto label1; /* Line 1111, Address: 0x10254c0 */
  sv_move_sub2(); /* Line 1112, Address: 0x10254d0 */
  return; /* Line 1113, Address: 0x10254d8 */



label1:
  scra_vz = 0; /* Line 1118, Address: 0x10254e0 */
} /* Line 1119, Address: 0x10254e8 */













static void sv_move_main(short yPos) { /* Line 1133, Address: 0x1025500 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1136, Address: 0x1025510 */
    if (actwk[0].mspeed.w < 0) { /* Line 1137, Address: 0x102552c */
      spdwk = -actwk[0].mspeed.w; /* Line 1138, Address: 0x1025544 */
    } else { /* Line 1139, Address: 0x1025568 */
      spdwk = actwk[0].mspeed.w; /* Line 1140, Address: 0x1025570 */
    }


    if (spdwk >= 2048) { /* Line 1144, Address: 0x1025580 */
      sv_move_main2(yPos); /* Line 1145, Address: 0x1025594 */
    } /* Line 1146, Address: 0x10255a0 */
    else {

      if (yPos > 6) { /* Line 1149, Address: 0x10255a8 */
        sv_move_plus(1536); /* Line 1150, Address: 0x10255c0 */
      } else if (yPos < -6) { /* Line 1151, Address: 0x10255cc */
        sv_move_minus(1536); /* Line 1152, Address: 0x10255ec */
      } /* Line 1153, Address: 0x10255f8 */
      else sv_move_sub(yPos); /* Line 1154, Address: 0x1025600 */
    }
  } /* Line 1156, Address: 0x102560c */
  else {
    if (yPos > 2) { /* Line 1158, Address: 0x1025614 */
      sv_move_plus(512); /* Line 1159, Address: 0x102562c */
    } else if (yPos < -2) { /* Line 1160, Address: 0x1025638 */
      sv_move_minus(512); /* Line 1161, Address: 0x1025658 */
    } /* Line 1162, Address: 0x1025664 */
    else sv_move_sub(yPos); /* Line 1163, Address: 0x102566c */
  }

} /* Line 1166, Address: 0x1025678 */













static void sv_move_main2(short yPos) { /* Line 1180, Address: 0x1025690 */
  short spdwk;

  spdwk = 4096; /* Line 1183, Address: 0x10256a0 */

  if (yPos > 16) { /* Line 1185, Address: 0x10256ac */
    sv_move_plus(spdwk); /* Line 1186, Address: 0x10256c4 */
  } else if (yPos < -16) { /* Line 1187, Address: 0x10256d0 */
    sv_move_minus(spdwk); /* Line 1188, Address: 0x10256f0 */
  } else { /* Line 1189, Address: 0x10256fc */
    sv_move_sub(yPos); /* Line 1190, Address: 0x1025704 */
  }
} /* Line 1192, Address: 0x1025710 */














static void sv_move_sub(short yPos) { /* Line 1207, Address: 0x1025730 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1210, Address: 0x102573c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1211, Address: 0x1025740 */
  if (yPos < 0) { /* Line 1212, Address: 0x102576c */
    scrv_up_ch(lSpd); /* Line 1213, Address: 0x1025780 */
  } else { /* Line 1214, Address: 0x102578c */
    scrv_down_ch(lSpd); /* Line 1215, Address: 0x1025794 */
  }
} /* Line 1217, Address: 0x10257a0 */



static void sv_move_sub2() { /* Line 1221, Address: 0x10257b0 */
  limmoveflag = 0; /* Line 1222, Address: 0x10257b8 */

  sv_move_sub(0); /* Line 1224, Address: 0x10257c0 */
} /* Line 1225, Address: 0x10257cc */













static void sv_move_minus(short speed) { /* Line 1239, Address: 0x10257e0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1242, Address: 0x10257ec */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1243, Address: 0x1025810 */
  scrv_up_ch(lSpd); /* Line 1244, Address: 0x1025834 */
} /* Line 1245, Address: 0x1025840 */














static void scrv_up_ch(int_union lSpd) { /* Line 1260, Address: 0x1025850 */
  if (lSpd.w.l <= scralim_up) { /* Line 1261, Address: 0x102585c */
    if (lSpd.w.l > -256) { /* Line 1262, Address: 0x1025884 */

      lSpd.w.l = scralim_up; /* Line 1264, Address: 0x102589c */
    } else { /* Line 1265, Address: 0x10258a8 */
      lSpd.w.l &= 2047; /* Line 1266, Address: 0x10258b0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1267, Address: 0x10258bc */
      scra_v_posit.w.h &= 2047; /* Line 1268, Address: 0x10258d0 */
      scrb_v_posit.w.h &= 1023; /* Line 1269, Address: 0x10258e4 */
    }
  }

  scrv_move(lSpd); /* Line 1273, Address: 0x10258f8 */
} /* Line 1274, Address: 0x1025904 */













static void sv_move_plus(short sSpd) { /* Line 1288, Address: 0x1025920 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1291, Address: 0x102592c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1292, Address: 0x102594c */
  scrv_down_ch(lSpd); /* Line 1293, Address: 0x1025970 */
} /* Line 1294, Address: 0x102597c */














static void scrv_down_ch(int_union lSpd) { /* Line 1309, Address: 0x1025990 */
  if (lSpd.w.l >= scralim_down) { /* Line 1310, Address: 0x102599c */
    if (lSpd.w.l < 2048) { /* Line 1311, Address: 0x10259c4 */

      lSpd.w.l = scralim_down; /* Line 1313, Address: 0x10259dc */
    } else { /* Line 1314, Address: 0x10259e8 */
      lSpd.w.l -= 2048; /* Line 1315, Address: 0x10259f0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1316, Address: 0x10259fc */
      scra_v_posit.w.h -= 2048; /* Line 1317, Address: 0x1025a10 */
      scrb_v_posit.w.h &= 1023; /* Line 1318, Address: 0x1025a24 */
    }
  }

  scrv_move(lSpd); /* Line 1322, Address: 0x1025a38 */
} /* Line 1323, Address: 0x1025a44 */
















static void scrv_move(int_union lSpd) { /* Line 1340, Address: 0x1025a60 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1344, Address: 0x1025a70 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1345, Address: 0x1025a80 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1346, Address: 0x1025aa4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1347, Address: 0x1025ab8 */
  scra_vz = spdwk.w.l; /* Line 1348, Address: 0x1025ad0 */

  scra_v_posit.l = lSpd.l; /* Line 1350, Address: 0x1025adc */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1352, Address: 0x1025ae8 */
  if (!ywk) { /* Line 1353, Address: 0x1025b24 */
    scra_v_count ^= 16; /* Line 1354, Address: 0x1025b2c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1355, Address: 0x1025b40 */
    if (ywk < 0) { /* Line 1356, Address: 0x1025b6c */
      scrflaga.b.h |= 1; /* Line 1357, Address: 0x1025b7c */
    } else { /* Line 1358, Address: 0x1025b90 */
      scrflaga.b.h |= 2; /* Line 1359, Address: 0x1025b98 */
    }
  }


} /* Line 1364, Address: 0x1025bac */

















void scrollwrt() { /* Line 1382, Address: 0x1025bc0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1391, Address: 0x1025be0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1392, Address: 0x1025be4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1393, Address: 0x1025bf0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1394, Address: 0x1025bfc */
  pScrFlag = &scrflagbw.b.h; /* Line 1395, Address: 0x1025c04 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1396, Address: 0x1025c0c */

  VramBase = 16384; /* Line 1398, Address: 0x1025c20 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1399, Address: 0x1025c24 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1400, Address: 0x1025c30 */
  pMapWk = (unsigned char*)mapwka; /* Line 1401, Address: 0x1025c3c */
  pScrFlag = &scrflagaw.b.h; /* Line 1402, Address: 0x1025c44 */

  if (*pScrFlag) { /* Line 1404, Address: 0x1025c4c */
    if (*pScrFlag & 1) { /* Line 1405, Address: 0x1025c58 */
      *pScrFlag &= 254; /* Line 1406, Address: 0x1025c6c */

      lD4.l = -16; /* Line 1408, Address: 0x1025c78 */
      wD5 = 65520; /* Line 1409, Address: 0x1025c80 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1411, Address: 0x1025c88 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1413, Address: 0x1025ca8 */
    }




    if (*pScrFlag & 2) { /* Line 1419, Address: 0x1025cd4 */
      *pScrFlag &= 253; /* Line 1420, Address: 0x1025ce8 */

      lD4.l = 224; /* Line 1422, Address: 0x1025cf4 */
      wD5 = 65520; /* Line 1423, Address: 0x1025cfc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1424, Address: 0x1025d04 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1426, Address: 0x1025d24 */
    }




    if (*pScrFlag & 4) { /* Line 1432, Address: 0x1025d50 */
      *pScrFlag &= 251; /* Line 1433, Address: 0x1025d64 */

      lD4.l = -16; /* Line 1435, Address: 0x1025d70 */
      wD5 = 65520; /* Line 1436, Address: 0x1025d78 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1437, Address: 0x1025d80 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1439, Address: 0x1025da0 */
    }




    if (*pScrFlag & 8) { /* Line 1445, Address: 0x1025dcc */
      *pScrFlag &= 247; /* Line 1446, Address: 0x1025de0 */

      lD4.l = -16; /* Line 1448, Address: 0x1025dec */
      wD5 = 320; /* Line 1449, Address: 0x1025df4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1450, Address: 0x1025dfc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1452, Address: 0x1025e1c */
    }
  }






} /* Line 1461, Address: 0x1025e48 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1478, Address: 0x1025e70 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1489, Address: 0x1025e9c */

  if (*pScrFlag & 1) { /* Line 1491, Address: 0x1025ea4 */
    *pScrFlag &= 254; /* Line 1492, Address: 0x1025ebc */
  } /* Line 1493, Address: 0x1025ed0 */
  else {
    *pScrFlag &= 254; /* Line 1495, Address: 0x1025ed8 */

    if (*pScrFlag & 2) { /* Line 1497, Address: 0x1025eec */
      *pScrFlag &= 253; /* Line 1498, Address: 0x1025f04 */
      lD4.w.l = 224; /* Line 1499, Address: 0x1025f18 */
    } /* Line 1500, Address: 0x1025f20 */
    else {
      *pScrFlag &= 253; /* Line 1502, Address: 0x1025f28 */
      goto label1; /* Line 1503, Address: 0x1025f3c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1508, Address: 0x1025f44 */
  wD0 &= 127; /* Line 1509, Address: 0x1025f94 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1510, Address: 0x1025f9c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1516, Address: 0x1025fbc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1517, Address: 0x1025fdc */
  if (wD0 != 0) { /* Line 1518, Address: 0x1026000 */
    wD5 = 65520; /* Line 1519, Address: 0x102600c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1520, Address: 0x1026014 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1522, Address: 0x1026034 */



  } /* Line 1526, Address: 0x1026060 */
  else {

    wD5 = 0; /* Line 1529, Address: 0x1026068 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1530, Address: 0x102606c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1534, Address: 0x102608c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1541, Address: 0x10260b8 */






    lD4.l = -16; /* Line 1548, Address: 0x10260cc */
    wD5 = 65520; /* Line 1549, Address: 0x10260d4 */
    if (*pScrFlag & 168) { /* Line 1550, Address: 0x10260dc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1551, Address: 0x10260f4 */
      wD5 = 320; /* Line 1552, Address: 0x1026114 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1556, Address: 0x102611c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1558, Address: 0x102614c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1559, Address: 0x1026158 */



    for (i = 0; i < 16; ++i) { /* Line 1563, Address: 0x1026168 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1564, Address: 0x1026174 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1566, Address: 0x1026194 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1567, Address: 0x10261cc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1568, Address: 0x10261ec */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1570, Address: 0x1026210 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1573, Address: 0x1026234 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1575, Address: 0x1026254 */
      }
      lD4.w.l += 16; /* Line 1577, Address: 0x1026268 */
    } /* Line 1578, Address: 0x1026274 */
    *pScrFlag = 0; /* Line 1579, Address: 0x1026284 */
  }
} /* Line 1581, Address: 0x102628c */





void scrollwrtc() {} /* Line 1587, Address: 0x10262c0 */




void scrollwrtz() {} /* Line 1592, Address: 0x10262d0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1610, Address: 0x10262e0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1623, Address: 0x1026308 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1626, Address: 0x1026328 */
    pTilePoint->x += 2; /* Line 1627, Address: 0x102633c */
    if (pTilePoint->x >= 64) { /* Line 1628, Address: 0x1026350 */
      pTilePoint->x -= 64; /* Line 1629, Address: 0x1026364 */
    }
    xOffs += 16; /* Line 1631, Address: 0x1026378 */
  } while (--lpcnt >= 0); /* Line 1632, Address: 0x1026384 */
} /* Line 1633, Address: 0x1026398 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1637, Address: 0x10263b0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1641, Address: 0x10263d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1644, Address: 0x10263f8 */
    pTilePoint->x += 2; /* Line 1645, Address: 0x102640c */
    if (pTilePoint->x >= 64) { /* Line 1646, Address: 0x1026420 */
      pTilePoint->x -= 64; /* Line 1647, Address: 0x1026434 */
    }
    xOffs += 16; /* Line 1649, Address: 0x1026448 */
  } while (--lpcnt >= 0); /* Line 1650, Address: 0x1026454 */
} /* Line 1651, Address: 0x1026468 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1671, Address: 0x1026480 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1675, Address: 0x10264a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1678, Address: 0x10264c8 */
    pTilePoint->y += 2; /* Line 1679, Address: 0x10264dc */
    if (pTilePoint->y >= 32) { /* Line 1680, Address: 0x10264ec */
      pTilePoint->y -= 32; /* Line 1681, Address: 0x1026500 */
    }
    yOffs += 16; /* Line 1683, Address: 0x1026510 */
  } while (--lpcnt >= 0); /* Line 1684, Address: 0x102651c */
} /* Line 1685, Address: 0x1026530 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1704, Address: 0x1026540 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1710, Address: 0x1026574 */

    base = 1; /* Line 1712, Address: 0x1026584 */
  } /* Line 1713, Address: 0x1026588 */
  else if (VramBase == 16384) { /* Line 1714, Address: 0x1026590 */

    base = 0; /* Line 1716, Address: 0x10265a0 */
  }
  x = pTilePoint->x; /* Line 1718, Address: 0x10265a4 */
  y = pTilePoint->y; /* Line 1719, Address: 0x10265ac */


  frip = BlkIndex & 6144; /* Line 1722, Address: 0x10265b4 */
  BlkIndex &= 1023; /* Line 1723, Address: 0x10265bc */
  if (frip == 6144) { /* Line 1724, Address: 0x10265c8 */

    p0 = 3, p1 = 2; /* Line 1726, Address: 0x10265d4 */
    p2 = 1, p3 = 0; /* Line 1727, Address: 0x10265dc */
  } /* Line 1728, Address: 0x10265e4 */
  else if (frip & 4096) { /* Line 1729, Address: 0x10265ec */

    p0 = 2, p1 = 3; /* Line 1731, Address: 0x10265f8 */
    p2 = 0, p3 = 1; /* Line 1732, Address: 0x1026600 */
  } /* Line 1733, Address: 0x1026608 */
  else if (frip & 2048) { /* Line 1734, Address: 0x1026610 */

    p0 = 1, p1 = 0; /* Line 1736, Address: 0x102661c */
    p2 = 3, p3 = 2; /* Line 1737, Address: 0x1026624 */
  } /* Line 1738, Address: 0x102662c */
  else {

    p0 = 0, p1 = 1; /* Line 1741, Address: 0x1026634 */
    p2 = 2, p3 = 3; /* Line 1742, Address: 0x102663c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1745, Address: 0x1026644 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1746, Address: 0x1026688 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1747, Address: 0x10266cc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1748, Address: 0x1026710 */

} /* Line 1750, Address: 0x1026754 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1768, Address: 0x1026790 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1769, Address: 0x10267b0 */
} /* Line 1770, Address: 0x10267d0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1772, Address: 0x10267e0 */
  wH_posiw = 0; /* Line 1773, Address: 0x1026800 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1774, Address: 0x1026804 */
} /* Line 1775, Address: 0x1026824 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1782, Address: 0x1026840 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1788, Address: 0x1026870 */
  yOffs += wV_posiw; /* Line 1789, Address: 0x1026880 */





  if ((short)xOffs < 0) /* Line 1795, Address: 0x1026890 */
    xOffs = 0; /* Line 1796, Address: 0x10268ac */
  if ((short)yOffs < 0) /* Line 1797, Address: 0x10268b0 */
    yOffs = 0; /* Line 1798, Address: 0x10268cc */
  if ((short)xOffs >= 16384) /* Line 1799, Address: 0x10268d0 */
    xOffs = 16383; /* Line 1800, Address: 0x10268f0 */
  if ((short)yOffs >= 2048) /* Line 1801, Address: 0x10268f8 */
    yOffs = 2047; /* Line 1802, Address: 0x1026918 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1803, Address: 0x1026920 */
  if (i < 0) i = 0; /* Line 1804, Address: 0x1026968 */

  ScreenNo = pMapWk[i] & 127; /* Line 1806, Address: 0x1026974 */

  if (ScreenNo) { /* Line 1808, Address: 0x1026990 */




    xOffs &= 32767; /* Line 1813, Address: 0x1026998 */
    yOffs &= 32767; /* Line 1814, Address: 0x10269a4 */


    xBlk = xOffs; /* Line 1817, Address: 0x10269b0 */
    xBlk %= 256; /* Line 1818, Address: 0x10269b8 */
    xBlk /= 16; /* Line 1819, Address: 0x10269d8 */
    yBlk = yOffs; /* Line 1820, Address: 0x10269f4 */
    yBlk %= 256; /* Line 1821, Address: 0x10269fc */
    yBlk /= 16; /* Line 1822, Address: 0x1026a1c */

    lpw = pmapwk; /* Line 1824, Address: 0x1026a38 */
    lpw += xBlk; /* Line 1825, Address: 0x1026a40 */
    lpw += yBlk * 16; /* Line 1826, Address: 0x1026a48 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1827, Address: 0x1026a54 */
    *pIndex = *lpw; /* Line 1828, Address: 0x1026a6c */

    return 1; /* Line 1830, Address: 0x1026a7c */
  }

  *pIndex = 0; /* Line 1833, Address: 0x1026a88 */
  return 0; /* Line 1834, Address: 0x1026a90 */
} /* Line 1835, Address: 0x1026a94 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1855, Address: 0x1026ac0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1863, Address: 0x1026ae8 */
  if (ScreenNo) { /* Line 1864, Address: 0x1026b4c */





    xBlk = xOffs; /* Line 1870, Address: 0x1026b54 */
    xBlk %= 256; /* Line 1871, Address: 0x1026b5c */
    xBlk /= 16; /* Line 1872, Address: 0x1026b7c */
    yBlk = yOffs; /* Line 1873, Address: 0x1026b98 */
    yBlk %= 256; /* Line 1874, Address: 0x1026ba0 */
    yBlk /= 16; /* Line 1875, Address: 0x1026bc0 */


    lpw = pmapwk; /* Line 1878, Address: 0x1026bdc */
    lpw += xBlk; /* Line 1879, Address: 0x1026be4 */
    lpw += yBlk * 16; /* Line 1880, Address: 0x1026bec */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1881, Address: 0x1026bf8 */
    *ppBlockNo = lpw; /* Line 1882, Address: 0x1026c10 */
    *pIndex = *lpw; /* Line 1883, Address: 0x1026c18 */




    return 1; /* Line 1888, Address: 0x1026c28 */
  }

  *pIndex = 0; /* Line 1891, Address: 0x1026c34 */
  return 0; /* Line 1892, Address: 0x1026c3c */
} /* Line 1893, Address: 0x1026c40 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1907, Address: 0x1026c60 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1914, Address: 0x1026c7c */
  pMapWk = (unsigned char*)mapwka; /* Line 1915, Address: 0x1026c80 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1916, Address: 0x1026c88 */
    *pBlockIndex = BlockNo; /* Line 1917, Address: 0x1026cac */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1918, Address: 0x1026cb8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1919, Address: 0x1026cd0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1920, Address: 0x1026ce4 */
    }
  }


} /* Line 1925, Address: 0x1026cfc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1939, Address: 0x1026d20 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1940, Address: 0x1026d2c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1941, Address: 0x1026d58 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1942, Address: 0x1026da4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1943, Address: 0x1026dd0 */

          return 0; /* Line 1945, Address: 0x1026e1c */
        }
      }
    }
  }

  return 1; /* Line 1951, Address: 0x1026e28 */
} /* Line 1952, Address: 0x1026e2c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1969, Address: 0x1026e40 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1970, Address: 0x1026e5c */

} /* Line 1972, Address: 0x1026e78 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1974, Address: 0x1026e90 */
  wH_posiw = 0; /* Line 1975, Address: 0x1026eac */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1976, Address: 0x1026eb0 */

} /* Line 1978, Address: 0x1026ecc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1980, Address: 0x1026ee0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1981, Address: 0x1026ef4 */

} /* Line 1983, Address: 0x1026f10 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1985, Address: 0x1026f20 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1986, Address: 0x1026f3c */

} /* Line 1988, Address: 0x1026f58 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1990, Address: 0x1026f70 */
  xOffs += wH_posiw; /* Line 1991, Address: 0x1026f88 */
  yOffs += wV_posiw; /* Line 1992, Address: 0x1026f98 */
  yOffs &= 240; /* Line 1993, Address: 0x1026fa8 */
  xOffs &= 496; /* Line 1994, Address: 0x1026fb4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1996, Address: 0x1026fc0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1997, Address: 0x1026fec */


} /* Line 2000, Address: 0x1027018 */















void mapwrt() { /* Line 2016, Address: 0x1027030 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 2021, Address: 0x1027048 */
  wV_posiw = scra_v_posiw.w.h; /* Line 2022, Address: 0x1027054 */
  pMapWk = (unsigned char*)mapwka; /* Line 2023, Address: 0x1027060 */
  VramBase = 16384; /* Line 2024, Address: 0x1027068 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 2025, Address: 0x102706c */
  mapwrtb(); /* Line 2026, Address: 0x1027084 */
} /* Line 2027, Address: 0x102708c */


void mapwrtb() { /* Line 2030, Address: 0x10270b0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 2035, Address: 0x10270c8 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 2036, Address: 0x10270d4 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2037, Address: 0x10270e0 */
  VramBase = 24576; /* Line 2038, Address: 0x10270e8 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2039, Address: 0x10270ec */

} /* Line 2041, Address: 0x10270fc */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2044, Address: 0x1027120 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2045, Address: 0x1027138 */
} /* Line 2046, Address: 0x1027158 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2051, Address: 0x1027170 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2055, Address: 0x1027190 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2058, Address: 0x10271ac */



    wD4 += 16; /* Line 2062, Address: 0x10271d4 */
  } while ((short)--wD6 >= 0); /* Line 2063, Address: 0x10271e0 */

} /* Line 2065, Address: 0x1027208 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2071, Address: 0x1027220 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2074, Address: 0x102723c */
  wD6 = 15; /* Line 2075, Address: 0x1027244 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 2078, Address: 0x102724c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2080, Address: 0x1027270 */
    wD4 += 16; /* Line 2081, Address: 0x1027290 */
  } while ((short)--wD6 >= 0); /* Line 2082, Address: 0x1027298 */
} /* Line 2083, Address: 0x10272bc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2109, Address: 0x10272e0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2114, Address: 0x1027308 */
  wD0 = pWrttbl[wD0]; /* Line 2115, Address: 0x1027318 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2117, Address: 0x1027334 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2118, Address: 0x1027358 */
  if (wD0) { /* Line 2119, Address: 0x1027380 */
    wD5 = 65520; /* Line 2120, Address: 0x102738c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2121, Address: 0x1027394 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2124, Address: 0x10273b0 */



  } /* Line 2128, Address: 0x10273d8 */
  else {

    wD5 = 0; /* Line 2131, Address: 0x10273e0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2132, Address: 0x10273e4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2136, Address: 0x1027400 */
  }





} /* Line 2143, Address: 0x1027428 */










void mapinit() { /* Line 2154, Address: 0x1027450 */
  short tbl[9] = { /* Line 2155, Address: 0x1027470 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2160, Address: 0x102749c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2166, Address: 0x10274c0 */
  pTbl = tbl; /* Line 2167, Address: 0x10274c4 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2169, Address: 0x10274c8 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2170, Address: 0x10274d0 */


    ++EnkeiNo; /* Line 2173, Address: 0x10274f4 */
  } /* Line 2174, Address: 0x10274f8 */


  TileNo = 523; /* Line 2177, Address: 0x102751c */
  if (EnkeiNo == 0) { /* Line 2178, Address: 0x1027520 */
    i = 168; /* Line 2179, Address: 0x1027528 */
    BmpNo = 0; /* Line 2180, Address: 0x102752c */

    for ( ; i > 0; --i) { /* Line 2182, Address: 0x1027530 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2183, Address: 0x1027538 */
    } /* Line 2184, Address: 0x1027558 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2188, Address: 0x1027564 */
  colorset(mapinittbl.colorno2); /* Line 2189, Address: 0x1027578 */

  if (plflag) enecginit(); /* Line 2191, Address: 0x102758c */
  if (play_start & 2) divdevset(); /* Line 2192, Address: 0x10275a4 */
} /* Line 2193, Address: 0x10275c4 */




void mapset() {} /* Line 2198, Address: 0x10275f0 */



void divdevset() {} /* Line 2202, Address: 0x1027600 */



void enecginit() {} /* Line 2206, Address: 0x1027610 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2222, Address: 0x1027620 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2226, Address: 0x1027640 */
  h = *pZonetbl++; /* Line 2227, Address: 0x1027658 */
  v = *pZonetbl++; /* Line 2228, Address: 0x1027668 */
  for ( ;v >= 0; --v) { /* Line 2229, Address: 0x1027678 */
    pMapwk = pMapDst; /* Line 2230, Address: 0x1027680 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2232, Address: 0x1027684 */
      *pMapwk++ = *pZonetbl++; /* Line 2233, Address: 0x1027690 */
    } /* Line 2234, Address: 0x10276a8 */

    pMapDst += 64; /* Line 2236, Address: 0x10276b4 */
  } /* Line 2237, Address: 0x10276c0 */
} /* Line 2238, Address: 0x10276cc */
